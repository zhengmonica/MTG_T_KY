#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "libele.h"
#include "elitee.h"


static void ResetAndCloseEle(PELE_DEVICE_CONTEXT pEleDevCtx);

int DoSense(const char* vendor,const char* model,IO_PACKAGE* pIn,IO_PACKAGE* pOut)
{
    BOOL bRet = FALSE;
    DWORD dwRet = 0;
    ELE_DEVICE_CONTEXT EleCtx = {0}, EleTempCtx = {0};
    unsigned long ulTempIndex = 0;
    unsigned char desc[8];
    unsigned long nDesc=0;
    ///打开第一把锁
    EleCtx.ulSize = sizeof(ELE_DEVICE_CONTEXT);

    bRet = EleOpenFirstDevice(NULL, NULL, NULL, ELE_SHARE_MODE, &EleCtx);

    //open the other device
    while (1)
    {
        if (!bRet)
        {
            dwRet = EleGetLastError();
            if (dwRet == ELE_NO_MORE_DEVICE)
            {
                printf("Total device(s): %d\n", ulTempIndex);
                printf("Valid index range: 0-%d\n", ulTempIndex-1);
                return 0;
            }
            else
            {
                printf("Open Elite-E device failed! <error code: 0x%08x>\n", dwRet);
                return 0;
            }
        }

        ulTempIndex++;

        ///判断锁的厂家描述是否与要求相符
        bRet=EleControl(&EleCtx,ELE_GET_VENDOR_DESC,0,0,desc,8,&nDesc);
        if(!bRet)
        {
            memcpy(&EleTempCtx, &EleCtx, sizeof(ELE_DEVICE_CONTEXT));
            ResetAndCloseEle(&EleTempCtx);
            return 0;
        }
        else
        {
            if(strcmp(vendor,(const char*)desc)==0)
            {
                printf("Execute Module in Elite-E...\n");
                bRet = EleExecute(
                           &EleCtx,
                           (char*) model,
                           (BYTE *)pIn,
                           sizeof(IO_PACKAGE),
                           (BYTE*)pOut,
                           sizeof(IO_PACKAGE),
                           NULL);
                if (!bRet)
                {
                    printf("Execute Module failed..\n");
                    return 0;
                }
                //for better security use "ResetAndCloseEle" instead of "EleClose"
                printf("Execute Module finished..\n");
                ResetAndCloseEle(&EleCtx);
                return 1;
            }
        }
        bRet = EleOpenNextDevice(&EleCtx);
    }
    //return 0;
}


/*
	Reset and close specified Elite-E device.
	Parameters:
		pEleDevCtx[in] : pointer to Elite-E context: ELE_DEVICE_CONTEXT

	Return:
		none.

	Remarks:
		Use this function instead of EleClose() may enhance security in certain
		circumstances.
*/
void ResetAndCloseEle(PELE_DEVICE_CONTEXT pEleDevCtx)
{
    BOOL bRet = FALSE;
    DWORD dwRet = 0;
    DWORD dwRealLen = 0;

    //reset
    bRet = EleControl(pEleDevCtx, ELE_RESET_DEVICE, NULL, 0, NULL, 0, &dwRealLen);
    if (!bRet)
    {
        dwRet = EleGetLastError();
        printf("Reset device failed! <error code: 0x%08x>\n", dwRet);

        getch();
        return;
    }

    //close
    bRet = EleClose(pEleDevCtx);
    if (!bRet)
    {
        dwRet = EleGetLastError();
        printf("Close device failed! <error code: 0x%08x>\n", dwRet);

        getch();
        return;
    }

    //set pointer "pEleDevCtx" to NULL
    //to avoid it being wild
    pEleDevCtx = NULL;
}


#ifdef WIN32
#include <windows.h>
#include <Iphlpapi.h>
#pragma comment(lib,"IPHlpApi.Lib")
int GetMacAddress(char addr[][13],int num)
{
    int nMac=0;
    PIP_ADAPTER_INFO pAdapterInfo;
    PIP_ADAPTER_INFO pAdapter = NULL;
    DWORD dwRetVal = 0;
    ULONG ulOutBufLen;
    pAdapterInfo=(PIP_ADAPTER_INFO)malloc(sizeof(IP_ADAPTER_INFO));
    ulOutBufLen = sizeof(IP_ADAPTER_INFO);

// 第一次调用GetAdapterInfo获取ulOutBufLen大小
    if (GetAdaptersInfo( pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW)
    {
        free(pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO *) malloc (ulOutBufLen);
    }

    if ((dwRetVal = GetAdaptersInfo( pAdapterInfo, &ulOutBufLen)) == NO_ERROR)
    {
        pAdapter = pAdapterInfo;
        while (pAdapter)
        {
            //printf("Adapter Name:     %s ", pAdapter->AdapterName);
            //printf("Adapter Desc:     %s ", pAdapter->Description);
            sprintf(addr[nMac],"%02x%02x%02x%02x%02x%02x",
                   pAdapter->Address[0],
                   pAdapter->Address[1],
                   pAdapter->Address[2],
                   pAdapter->Address[3],
                   pAdapter->Address[4],
                   pAdapter->Address[5]);
            addr[nMac][12]=0;
            //printf("IP Address:     %s ", pAdapter->IpAddressList.IpAddress.String);
            //printf("IP Mask:     %s ", pAdapter->IpAddressList.IpMask.String);
            //printf("Gateway:     %s ", pAdapter->GatewayList.IpAddress.String);
            pAdapter = pAdapter->Next;
            nMac++;
            if(nMac>=num) break;
        }
    }
    else
    {
        printf("Call to GetAdaptersInfo failed. ");
    }

    return nMac;
}
#endif
