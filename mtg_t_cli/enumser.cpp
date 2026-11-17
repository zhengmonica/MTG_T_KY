#include "enumser.h"

#if defined(WIN32) &&!defined(_WIN32_WCE) 

#include <windows.h>
///////////////////////////// Implementation //////////////////////////////////
void EnumerateSerialPorts(wxArrayInt& ports)
{
  //Make sure we clear out any elements which may already be in the array
  ports.Clear();

  //Determine what OS we are running on
  OSVERSIONINFO osvi;
  osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
  BOOL bGetVer = GetVersionEx(&osvi);

  //On NT use the QueryDosDevice API
  if (bGetVer && (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT))
  {
    //Use QueryDosDevice to look for all devices of the form COMx. This is a better
    //solution as it means that no ports have to be opened at all.
    TCHAR szDevices[65535];
    DWORD dwChars = QueryDosDevice(NULL, szDevices, 65535);
    if (dwChars)
    {
      int i=0;

      for (;;)
      {
        //Get the current device name
        TCHAR* pszCurrentDevice = &szDevices[i];

        //If it looks like "COMX" then
        //add it to the array which will be returned
        int nLen = _tcslen(pszCurrentDevice);
        if (nLen > 3 && _tcsnicmp(pszCurrentDevice, _T("COM"), 3) == 0)
        {
          //Work out the port number
          int nPort = _ttoi(&pszCurrentDevice[3]);
          if(nPort>0)     ports.Add(nPort);
        }

        // Go to next NULL character
        while(szDevices[i] != _T('\0'))
          i++;

        // Bump pointer to the next string
        i++;

        // The list is double-NULL terminated, so if the character is
        // now NULL, we're at the end
        if (szDevices[i] == _T('\0'))
          break;
      }
    }
    //else
      //TRACE(_T("Failed in call to QueryDosDevice, GetLastError:%d\n"), GetLastError());
  }
  else
  {
    //On 95/98 open up each port to determine their existence

    //Up to 255 COM ports are supported so we iterate through all of them seeing
    //if we can open them or if we fail to open them, get an access denied or general error error.
    //Both of these cases indicate that there is a COM port at that number.
    for (UINT i=1; i<256; i++)
    {
      //Form the Raw device name
      wchar_t sPort[64];
      _snwprintf(sPort,64,_T("\\\\.\\COM%d"),i);
      //wxString sPort=wxString::Format(wxT("\\\\.\\COM%d"), i);

      //Try to open the port
      bool bSuccess = false;
      HANDLE hPort = ::CreateFile(sPort, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
      if (hPort == INVALID_HANDLE_VALUE)
      {
        DWORD dwError = GetLastError();

        //Check to see if the error was because some other app had the port open or a general failure
        if (dwError == ERROR_ACCESS_DENIED || dwError == ERROR_GEN_FAILURE)
          bSuccess = true;
      }
      else
      {
        //The port was opened successfully
        bSuccess = true;

        //Don't forget to close the port, since we are going to do nothing with it anyway
        CloseHandle(hPort);
      }

      //Add the port number to the array which will be returned
      if (bSuccess)
        ports.Add(i);
    }
  }
}


#elif defined(_WIN32_WCE)  ///wince

#include <winnt.h>
#include <winerror.h>
#include <winbase.h>
#include <winreg.h>

static LONG OpenSubKeyByIndex(
  HKEY hKey,DWORD dwIndex,REGSAM samDesired,PHKEY phkResult,LPTSTR* lppSubKeyName)
{
  DWORD              dwError=0;
  BOOL               bLocalSubkeyName=FALSE;
  LPTSTR             lpSubkeyName=NULL;
  DWORD              cbSubkeyName=128*sizeof(TCHAR); /* an initial guess */
  FILETIME           filetime;

  if(lppSubKeyName==NULL){
    bLocalSubkeyName=TRUE;
    lppSubKeyName=&lpSubkeyName;
  }
  /* loop asking for the subkey name til we allocated enough memory */

  for(;;){
    free(*lppSubKeyName);
    if(!(*lppSubKeyName=(LPTSTR)malloc(cbSubkeyName))){
       dwError=ERROR_NOT_ENOUGH_MEMORY;
       goto end;
    }
    if(!(dwError=RegEnumKeyEx(hKey,dwIndex,*lppSubKeyName,&cbSubkeyName,
                              0,NULL,NULL,&filetime))){
      break; /* we did it */
    }
    else if(dwError==ERROR_MORE_DATA){ /* not enough space */
      dwError=0;
      /* no indication of space required, we try doubling */
      cbSubkeyName=(cbSubkeyName+sizeof(TCHAR))*2;
    }
    else goto end;
  }

  dwError=RegOpenKeyEx(hKey,*lppSubKeyName,0,samDesired,phkResult);

end:
  if(bLocalSubkeyName)free(*lppSubKeyName);
  return dwError;
}

static LONG QueryStringValue(HKEY hKey,LPCTSTR lpValueName,LPTSTR* lppStringValue)
{
  DWORD cbStringValue=128*sizeof(TCHAR); /* an initial guess */

  for(;;){
    DWORD dwError;

    free(*lppStringValue);
    if(!(*lppStringValue=(LPTSTR)malloc(cbStringValue))){
      return ERROR_NOT_ENOUGH_MEMORY;
    }
    if(!(dwError=RegQueryValueEx(hKey,lpValueName,NULL,NULL,
                                 (LPBYTE)*lppStringValue,&cbStringValue))){
      return ERROR_SUCCESS;
    }
    else if(dwError==ERROR_MORE_DATA){
      /* not enough space, keep looping */
    }
    else return dwError;
  }
}


void EnumerateSerialPorts(wxArrayInt& ports)
/* Available COM ports on Pocket PC/Windows CE devices are stored in registry under
 * key: HKLM\Drivers\BuiltIn. Note, that also other stuff like native Bluetooth ports
 * are written in this part of registry, so we must skip them using condition
 * (_tcsncicmp(lpPortName,TEXT("COM"),3)!=0) below.
 */
{
  DWORD               dwError=0;
  HKEY                hKey=NULL;
  DWORD               dwIndex;
  LPTSTR              lpPortName=NULL;
  HKEY                hkLevel1=NULL;
  LPTSTR              lpFriendlyName=NULL;
  //LISTPORTS_PORTINFO  portinfo;
  DWORD               index;
  DWORD               wordSize = sizeof(DWORD);

  ports.Clear();

  //portinfo.lpPortName = (LPTSTR)malloc(64);

  if(dwError=RegOpenKeyEx(HKEY_LOCAL_MACHINE,TEXT("Drivers\\BuiltIn"),
                          0,KEY_READ,&hKey)){
    /* it is really strange that this key does not exist, but could happen in theory */
    if(dwError==ERROR_FILE_NOT_FOUND)dwError=0;
    goto end;
  }

  for(dwIndex=0;;++dwIndex) {
    dwError = 0;
    if (dwError=OpenSubKeyByIndex(hKey,dwIndex,KEY_ENUMERATE_SUB_KEYS,&hkLevel1,NULL)) {
      if (dwError==ERROR_NO_MORE_ITEMS) dwError=0;
      break;
    }

    if (dwError=QueryStringValue(hkLevel1,TEXT("PREFIX"),&lpPortName)) {
      if(dwError==ERROR_FILE_NOT_FOUND) continue; else break;
    }

    if (_tcsncmp(lpPortName,TEXT("COM"),3)!=0) continue; // We want only COM serial ports

    if (dwError=RegQueryValueEx(hkLevel1, TEXT("INDEX"), NULL, NULL, (LPBYTE)&index, &wordSize)) {
      if(dwError==ERROR_FILE_NOT_FOUND) continue; else break;
    }

    ports.Add(index);
  }

end:
  //free((LPTSTR)portinfo.lpPortName);
  free(lpFriendlyName);
  free(lpPortName);
  if(hKey!=NULL) RegCloseKey(hKey);
  if(hkLevel1!=NULL) RegCloseKey(hkLevel1);
  if(dwError!=0){
    SetLastError(dwError);
  }
}

#endif

