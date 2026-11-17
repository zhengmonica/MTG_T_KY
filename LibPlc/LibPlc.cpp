// LibPlc.cpp : Defines the initialization routines for the DLL.
//
#include "stdafx.h"
#include "LibPlc.h"
#include "pre_opc.h"		// for OPC: include MFC, ATL and OPC header files - for OPC only
#include "callback.h"
#include <direct.h>
#include <string.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CLibPlcApp

class CLibPlcApp : public CWinApp
{
public:
	CLibPlcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibPlcApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CLibPlcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CLibPlcApp, CWinApp)
	//{{AFX_MSG_MAP(CLibPlcApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLibPlcApp construction

CLibPlcApp::CLibPlcApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLibPlcApp object

CLibPlcApp theApp;


//// Used by GetErrorString; Language code ////
#define LOCALE_ID    0x409      // Code 0x409 = ENGLISH


//const LPWSTR		szItemID0 = L"S7:[DEMO]DemoPower";    // this item must be readable and writeablein this sample
//const LPWSTR		szItemID1 = L"S7:[DEMO]MW3";    // this item must be readable in this sample

//const DWORD			vtDataTypeItem0 = VT_EMPTY;		// canonical datatype
//const DWORD			vtDataTypeItem1 = VT_UI2;		// unsigned integer 2 Bytes

///从PLC读取的数据
// const LPWSTR		szItemID0 = L"S7:[HmiConn]DB46,X220.0";       // 掘进开始

// const LPWSTR		szItemID2 = L"S7:[HmiConn]DB46,REAL36";      // 推进油缸行程A组

// const DWORD			vtDataTypeItem0 = 11;		// VbBoolean

// const DWORD			vtDataTypeItem2 = 5;		// VbDouble

///写入PLC的测量数据
// const LPWSTR		szItemID20 = L"S7:[HmiConn]DB47,REAL0";     // 俯仰角1(盾体轴线与第一节盾体水平线之间的夹角)

// const LPWSTR		szItemID59 = L"S7:[HmiConn]DB47,INT256";     // 掘进编号（除管环编号外）

// const DWORD			vtDataTypeItem20 = 5;		// VbDouble
// const DWORD			vtDataTypeItem59 = 2;		// VbDouble


DWORD				m_dwAdvise;
OPCITEMDEF			*m_Items;


CComModule _Module;

IOPCServer			*m_pIOPCServer;
IOPCItemMgt			*m_pIOPCItemMgt;
IOPCGroupStateMgt	*m_pIOPCGroupStateMgt;
IOPCAsyncIO2		*m_pIOPCAsyncIO2;
OPCITEMRESULT		*m_pItemResult;
HRESULT				*m_pErrors;
OPCHANDLE			m_GrpSrvHandle;

BOOL	m_bChkActivateGroup;

 int plc_data = 0;
// int read_plc_complete = 0;
//
// int read_plc_start_val = 0;
// double read_plc_uaj_val = 0.0;            // 推进油缸行程A组
//
/////写入PLC内容
// double write_plc_roll1_val = 0.0;         // 俯仰角1(盾体轴线与第一节盾体水平线之间的夹角)
//
// int write_plc_numb1_val = 0;            // 掘进编号（除管环编号外）

 mtg_tp testP={0};

 wchar_t** unitsbuf;
 const LPWSTR		szItemID0 = L"NewDataItem";       // 掘进开始
 const DWORD			vtDataTypeItem59 = 2;		// VbDouble

//
// OnCheckActivategroup: handler is being called, when checkbox "Group Active" has been clicked
//
// This handler for OPC:
//  - Retrieves state of the checkboc from Dialog
//	- Sets the state of the group corresponding to the checkbox state
//
static void OnCheckActivategroup()
{
	//UpdateData(TRUE);

	DWORD dwRevUpdateRate;
	HRESULT	r1=	m_pIOPCGroupStateMgt->SetState(NULL,	// [in] RequestedUpdateRate
						&dwRevUpdateRate,	// [out] RevisedUpdateRate
						&m_bChkActivateGroup,//[in] ActiveFlag for Group
						NULL,				// [in] TimeBias
						NULL,				// [in] PercentDeadband
						NULL,				// [in] LCID
						NULL);				// [in] Handle ClientGroup

	if (FAILED(r1))
	{
		//MessageBox("Set State failed",
	           //"Error", MB_OK+MB_ICONERROR);
		return;
	}
}


//
// OnButtonStart: handler is being called, when button "Start Sample" has been pressed
//
// This handler is for OPC:
//	- initializes COM
//	- creates an OPC server object
//	- adds an OPC group
//	- adds 2 items to this group
//	- establishes the callback

char* filepath=0;
int init_plc(char* path)
{
	HRESULT		r1;
	CLSID		clsid;
	LONG		TimeBias = 0;
	FLOAT		PercentDeadband = 0.0;
	DWORD		RevisedUpdateRate;
	LPWSTR		ErrorStr1,ErrorStr2;
	CString		szErrorText;
	FILE* initFile=NULL;
	LPCSTR lpcstr;
	int i=0;
	char buf[1024]={0};
	char progidbuf[256]={0};
	char groupbuf[256]={0};
//	char* filepath;

	char* ret=NULL;

//    initlock(&testP.dblock);

	m_pItemResult = NULL;
	filepath=_getcwd(NULL,0);
	sprintf(buf,"%s\\init_plc.log",filepath);
	//sprintf(buf,"E:\\init_plc.log");
	FILE* fp = fopen(buf,"w");
	//fprintf(fp,filepath);
	fprintf(fp,"%s\n",path);fflush(fp);
	initFile = fopen(path,"r");
	if(initFile==NULL) return 0;
	fprintf(fp,"open ok\n");fflush(fp);
	ret = fgets(progidbuf,255,initFile);     ///progID
	if(!ret)
    {
        fclose(initFile);
        return 0;
    }
    fprintf(fp,progidbuf);fflush(fp);
	progidbuf[strlen(progidbuf)-1] ='\0';
	if(strcmp(progidbuf,"Mitsubishi.MXOPC.6")==0)
    {
        testP.type=1;
    }
    else if(strcmp(progidbuf,"OPC.SimaticNET")==0)
    {
        testP.type=0;
    }
    else if(strcmp(progidbuf,"SOFTPLC")==0)   ///软plc
    {
        testP.type=5;
        return 1;
    }
    else if (strcmp(progidbuf,"RSLinx OPC Server")==0)  ///ab
    {
        testP.type=6;
    }
    else if(strcmp(progidbuf,"Kepware.KEPServerEX.V6")==0)  ///施耐德
    {
        testP.type=2;
    }
    fprintf(fp,"testP.type = %d\n",testP.type);fflush(fp);

	//strcpy(testP.IDname,progidbuf);
	//char *CStr = "string to convert";
    size_t len = strlen(progidbuf) + 1;
    size_t converted = 0;
    wchar_t *WStr;
    WStr=(wchar_t*)malloc(len*sizeof(wchar_t));
    mbstowcs_s(&converted, WStr, len, progidbuf, len-1);
	//lpcstr = progidbuf;
	testP.ProgID = (LPWSTR)WStr;
	ret = fgets(groupbuf,255,initFile);     ///GroupName
	fprintf(fp,"%s\n",testP.ProgID);fflush(fp);
	fprintf(fp,"%d\n",converted);fflush(fp);
	if(!ret)
    {
        fclose(initFile);
        return 0;
    }
    fprintf(fp,groupbuf);fflush(fp);
	groupbuf[strlen(groupbuf)-1] ='\0';
	//fprintf(fp,"%s\n",groupbuf);fflush(fp);
	len = strlen(groupbuf) + 1;
    converted = 0;
    wchar_t *WStr1;
    WStr1=(wchar_t*)malloc(len*sizeof(wchar_t));
    mbstowcs_s(&converted, WStr1, len, groupbuf, len-1);
	//lpcstr = groupbuf;
	testP.GroupName = (LPWSTR)WStr1;
	//fprintf(fp,"%s\n",testP.GroupName);fflush(fp);
	ret = fgets(buf,1023,initFile);     ///nunit
	if(!ret)
    {
        fclose(initFile);
        return 0;
    }
	sscanf(buf,"%d",&i);
	fprintf(fp,"%d\n",i);fflush(fp);
	//if(i!=UNIT_COUNT) return 0;
	testP.nunit=i;
	unitsbuf=(wchar_t**)calloc(testP.nunit,sizeof(wchar_t*));
	for(i=0;i<testP.nunit&&!feof(initFile);i++)
	{
		ret = fgets(buf,1023,initFile);     ///type && read or write
		if(!ret) break;
		fprintf(fp,"%s\n",buf);
		fflush(fp);

		sscanf(buf,"%d,%d,%lf,%lf",&testP.units[i].type,&testP.units[i].readorwrite,&testP.units[i].val_add,&testP.units[i].val_mul);
		fprintf(fp,"i=%d,val_add=%lf,val_mul=%lf\n",i,testP.units[i].val_add,testP.units[i].val_mul);
		fprintf(fp,"%d,%d,%lf,%lf\n",testP.units[i].type,testP.units[i].readorwrite,testP.units[i].val_add,testP.units[i].val_mul);
		testP.units[i].vtDataTypeItem=testP.units[i].type;
		///testP.units[i].val_max=4000.0;
		//ret = fgets(buf,1023,initFile);     ///value min max
		//if(!ret) break;
		//sscanf(buf,"%f,%f",&testP.units[i].val_min,&testP.units[i].val_max);
		// if(testP.units[i].readorwrite)
		// {
			// ret = fgets(buf,1023,initFile);     ///value
			// if(!ret) break;
			// if(testP.units[i].type==0)
			// {
				// sscanf(buf,"%d",&testP.units[i].val_int);
			// }
			// else
			// {
				// sscanf(buf,"%f",&testP.units[i].val_double);
			// }
		// }
		//unitsbuf[i]=(char*)calloc(256,sizeof(char));
		ret = fgets(buf,255,initFile);     ///szItemID
		if(!ret) break;
		buf[strlen(buf)-1] ='\0';
        len = strlen(buf) + 1;
        converted = 0;
        //wchar_t *WStr1;
        unitsbuf[i]=(wchar_t*)malloc(len*sizeof(wchar_t));
        mbstowcs_s(&converted, unitsbuf[i], len, buf, _TRUNCATE);
		testP.units[i].szItemID = (LPWSTR)unitsbuf[i];
	}
	fclose(initFile);
	if(i==0)
	{
		if(testP.units) free(testP.units);
		//fclose(initFile);
		return 0;
	}
	testP.nunit=i;

//	if(i<testP.nunit)
//	{
//		testP.nunit=i;
//		testP.units=(plc_unit_t*)realloc(testP.units,testP.nunit*sizeof(plc_unit_t));
//		unitsbuf=(wchar_t**)realloc(unitsbuf,testP.nunit*sizeof(wchar_t*));
//	}
#ifdef RAS
    return 1;
#endif // RAS
	// Initialize the COM library
	r1 = CoInitialize(NULL);
	//szErrorText.Format("Initialisation of COM Library failed. ErrorCode= %4x", r1);
	//fprintf(fp,"%s\n",szErrorText);
	if (r1 != S_OK)
	{	if (r1 == S_FALSE)
		{
		//MessageBox("COM Library already initialized",
			           //"Error CoInitialize()", MB_OK+MB_ICONEXCLAMATION);
		}
		else
		{
			//szErrorText.Format("Initialisation of COM Library failed. ErrorCode= %4x", r1);
			//MessageBox(szErrorText,"Error CoInitialize()", MB_OK+MB_ICONERROR);
			//SendMessage(WM_CLOSE);
            for(i=0;i<testP.nunit;i++)
            {
                if(unitsbuf[i]) free(unitsbuf[i]);
            }
            free(unitsbuf);
            unitsbuf=NULL;
			if(testP.units) free(testP.units);
			return 0;
		}
	}
	//fprintf(fp,"%s\n",szErrorText);
	// Given a ProgID, this looks up the associated CLSID in the registry
	//fprintf(fp,"%s\n",testP.ProgID);fflush(fp);
	//mbstowcs_s(&converted, WStr, len, progidbuf, _TRUNCATE);
	//r1 = CLSIDFromProgID(L"OPC.SimaticNET", &clsid);
////	if(testP.type==1)
////        r1 = CLSIDFromProgID(L"Mitsubishi.MXOPC.6", &clsid);
////    else
////        r1 = CLSIDFromProgID(L"OPC.SimaticNET", &clsid);
	r1 = CLSIDFromProgID(testP.ProgID, &clsid);
	fprintf(fp,"%d",testP.type);fflush(fp);
	if (r1 != S_OK)
	{
		//MessageBox("Retrival of CLSID failed",
				   //"Error CLSIDFromProgID()", MB_OK+MB_ICONERROR);
		CoUninitialize();
//		for(i=0;i<testP.nunit;i++)
//        {
//            if(unitsbuf[i]) free(unitsbuf[i]);
//        }
//        free(unitsbuf);
//        unitsbuf=NULL;
//		if(testP.units) free(testP.units);
		//SendMessage(WM_CLOSE);
		fprintf(fp,"progID over");fflush(fp);
		fclose(fp);
		return 0;
	}
////20181101__1
//	if(fp)
//    {
//        fclose(fp);
//    }
//    return 1;
	//fprintf(fp,"%s\n",szErrorText);
	// Create the OPC server object and querry for the IOPCServer interface of the object
	r1 = CoCreateInstance (clsid, NULL, CLSCTX_LOCAL_SERVER ,IID_IOPCServer, (void**)&m_pIOPCServer);
	if (r1 != S_OK)
	{
		//MessageBox("Creation of IOPCServer-Object failed",
		           //"Error CoCreateInstance()", MB_OK+MB_ICONERROR);
		m_pIOPCServer = NULL;
		CoUninitialize();
		for(i=0;i<testP.nunit;i++)
        {
            if(unitsbuf[i]) free(unitsbuf[i]);
        }
        free(unitsbuf);
        unitsbuf=NULL;
		if(testP.units) free(testP.units);
		//SendMessage(WM_CLOSE);
		return 0;
	}
	//fprintf(fp,"1:%s\n",szErrorText);
	// Add a group object "grp1" and querry for interface IOPCItemMgt
////	if(testP.type==1)
////        testP.GroupName=L"Group One";
////    else
////        testP.GroupName=L"grp1";
////	r1=m_pIOPCServer->AddGroup(	L"Group One",		// [in] group name

    ////20181101__2
//	if(fp)
//    {
//        fclose(fp);
//    }
//    return 1;
    r1=m_pIOPCServer->AddGroup(	testP.GroupName,		// [in] group name
						FALSE,				// [in] not active, so no OnDataChange callback
						500,				// [in] Request this Update Rate from Server
						1,					// [in] Client Handle, not necessary in this sample
						&TimeBias,			// [in] No time interval to system UTC time
						&PercentDeadband,	// [in] No Deadband, so all data changes are reported
						LOCALE_ID,			// [in] Server uses english language to for text values
						&m_GrpSrvHandle,	// [out] Server handle to identify this group in later calls
						&RevisedUpdateRate,	// [out] The answer from Server to the requested Update Rate
						IID_IOPCItemMgt,	// [in] requested interface type of the group object
						(LPUNKNOWN*)&m_pIOPCItemMgt); // [out] pointer to the requested interface


	if (r1 == OPC_S_UNSUPPORTEDRATE)
	{
		//szErrorText.Format ("Revised Update Rate %d is different from Requested Update Rate 500",RevisedUpdateRate );
		//AfxMessageBox (szErrorText);
	}
	else
		if (FAILED(r1))
		{
			//MessageBox("Can't add Group to Server!",
					   //"Error AddGroup()", MB_OK+MB_ICONERROR);
			m_pIOPCServer->Release();
			m_pIOPCServer = NULL;
			CoUninitialize();
			for(i=0;i<testP.nunit;i++)
            {
                if(unitsbuf[i]) free(unitsbuf[i]);
            }
            free(unitsbuf);
            unitsbuf=NULL;
			if(testP.units) free(testP.units);
			fprintf(fp,"group over");fflush(fp);
			//SendMessage(WM_CLOSE);
			return 0;
		}
    ////20181101__3
//	if(fp)
//    {
//        fclose(fp);
//    }
//    return 1;
	//fprintf(fp,"2:%s\n",szErrorText);
	// define item tables with 2 items as in parameters for AddItem
	///初始化Items
	m_Items=(OPCITEMDEF*)calloc(testP.nunit,sizeof(OPCITEMDEF));
	for(i=0;i<testP.nunit;i++)
	{
		m_Items[i].szAccessPath		  = L"";	        	// Accesspath not needed
		m_Items[i].szItemID			  = testP.units[i].szItemID;	        // ItemID, see above
		m_Items[i].bActive			  = TRUE;		        // AddItem Active, so OnDataChange will come in an active group for this item
		m_Items[i].hClient			  = i;		        	// Client handle , needed in this sample in callback OnDataChange
		m_Items[i].dwBlobSize		  = 0;		         	// "BinaryLargeOBject" not needed by SimaticNet OPC Server
		m_Items[i].pBlob				  = NULL;	    	// no blob
		m_Items[i].vtRequestedDataType = (DWORD)testP.units[i].vtDataTypeItem;	// Return values in native (cannonical) datatype defined by the item itself
	}
	////20181101__34_2
//	if(fp)
//    {
//        fclose(fp);
//    }
//    return 1;

	r1 = m_pIOPCItemMgt->AddItems(	testP.nunit,				// [in] Add two Items
								m_Items,			// [in] defined in this structure (see above)
								&m_pItemResult,	// [out] array with additional information about the item (server assigned item handle and canonical datatype)
								&m_pErrors		// [out] tells which of the items was successfully added. For any item which failed it provides a reason.
							);

    ////20181101__34_1
//	if(fp)
//    {
//        fclose(fp);
//    }
//    return 1;

	if ( (r1 != S_OK) && (r1 != S_FALSE) )
	{
		//MessageBox("AddItems failed!",
		           //"Error AddItems()", MB_OK+MB_ICONERROR);

        m_pIOPCItemMgt->Release();
		m_pIOPCItemMgt = NULL;
		m_GrpSrvHandle = 0;
		m_pIOPCServer->Release();
		m_pIOPCServer = NULL;
		CoUninitialize();
		for(i=0;i<testP.nunit;i++)
        {
            if(unitsbuf[i]) free(unitsbuf[i]);
        }
        free(unitsbuf);
        unitsbuf=NULL;
		if(testP.units) free(testP.units);
		if(m_Items) free(m_Items);
		//SendMessage(WM_CLOSE);
		fprintf(fp,"additems over");fflush(fp);
		return 0;

	}
	else
	{	// this is the normal part
 		CString szOut;
        for(i=0;i<testP.nunit;i++)
        {
            m_pIOPCServer->GetErrorString(m_pErrors[i], LOCALE_ID, &ErrorStr1);
            fprintf(fp,"Item %ls : %ls\n",testP.units[i].szItemID,ErrorStr1);fflush(fp);
        }

		//fprintf(fp,"%s\n",szOut);


		//MessageBox(szOut, "Result AddItems()", MB_OK+MB_ICONEXCLAMATION);
		// release ErrorStr
        CoTaskMemFree(ErrorStr1);
        //CoTaskMemFree(ErrorStr2);
		// go on
	}
	fprintf(fp,"add items pass\n");fflush(fp);
	////20181101__4
//	if(fp)
//    {
//        fclose(fp);
//    }
//    return 1;
	//fprintf(fp,"3:%s\n",szErrorText);
	// check if Item0 is readable and writeable
	if (m_pItemResult[0].dwAccessRights != (OPC_READABLE + OPC_WRITEABLE))
	{
		//MessageBox("Item 0 ist not readable and writeable.\nThis is essential for correct operation of this sample.", "Result AddItems()", MB_OK+MB_ICONEXCLAMATION);
	}

	// Get interface for GroupStateMgt
	r1=m_pIOPCItemMgt->QueryInterface(IID_IOPCGroupStateMgt, (void**) &m_pIOPCGroupStateMgt);

	if (r1 != S_OK)
	{
		//MessageBox("No IOPCGroupStateMgt found",
			           //"Error QueryInterface()", MB_OK+MB_ICONERROR);
		CoTaskMemFree(m_pItemResult);
		m_pIOPCItemMgt->Release();
		m_pIOPCItemMgt = 0;
		m_GrpSrvHandle = 0;
		m_pIOPCServer->Release();
		m_pIOPCServer = NULL;
		CoUninitialize();
		fprintf(fp,"Query Interface 1 over\n");fflush(fp);
		for(i=0;i<testP.nunit;i++)
        {
            if(unitsbuf[i]) free(unitsbuf[i]);
        }
        free(unitsbuf);
        unitsbuf=NULL;
		if(testP.units) free(testP.units);
		if(m_Items) free(m_Items);
		//SendMessage(WM_CLOSE);
		return 0;
	}
	fprintf(fp,"Query Interface 1 pass\n");fflush(fp);
	//fprintf(fp,"4:%s\n",szErrorText);
	// query interface for async calls on group object
	r1 = m_pIOPCItemMgt->QueryInterface(IID_IOPCAsyncIO2, (void**)&m_pIOPCAsyncIO2);
	if (r1 < 0)
	{
		//MessageBox("No IOPCAsyncIO found!",
	           //"Error QueryInterface()", MB_OK+MB_ICONERROR);
		CoTaskMemFree(m_pItemResult);
		m_pIOPCItemMgt->Release();
		m_pIOPCItemMgt = 0;
		m_GrpSrvHandle = 0;
		m_pIOPCServer->Release();
		m_pIOPCServer = NULL;
		CoUninitialize();
		fprintf(fp,"Query Interface 2 over\n");fflush(fp);
		for(i=0;i<testP.nunit;i++)
        {
            if(unitsbuf[i]) free(unitsbuf[i]);
        }
        free(unitsbuf);
        unitsbuf=NULL;
		if(testP.units) free(testP.units);
		if(m_Items) free(m_Items);
		//SendMessage(WM_CLOSE);
        return 0;
	}
	fprintf(fp,"Query Interface  2 pass\n");fflush(fp);
	//fprintf(fp,"5:%s\n",szErrorText);
	// Activate Group according to Checkbox
	OnCheckActivategroup();

	// Establish Callback for all async operations
	CComObject<COPCDataCallback>* pCOPCDataCallback;	// Pointer to Callback Object

	// Create Instance of Callback Object using an ATL template
    CComObject<COPCDataCallback>::CreateInstance(&pCOPCDataCallback);

	// pass pointer of this dialog class to callback object
	//pCOPCDataCallback->InformAboutDialog(this);

    // query IUnknown interface of callback object, needed for the ATL Advise
	LPUNKNOWN pCbUnk;
    pCbUnk = pCOPCDataCallback->GetUnknown();

    // Creates a connection between the OPC servers's connection point and
	// this client's sink (the callback object).
	HRESULT hRes = AtlAdvise(	m_pIOPCGroupStateMgt,			 // [in] IUnknown Interface of the Connection Point
								pCbUnk,				 // [in] IUnknown Interface of the Callback object
								IID_IOPCDataCallback,// [in] Connection Point ID: The OPC Data Callback
								&m_dwAdvise			 // [out] Cookie that that uniquely identifies the connection
							);

	if (hRes != S_OK)
	{
		//AfxMessageBox("Advise failed!");

		CoTaskMemFree(m_pItemResult);
		m_pIOPCItemMgt->Release();
		m_pIOPCItemMgt = 0;
		m_GrpSrvHandle = 0;
		m_pIOPCServer->Release();
		m_pIOPCServer = NULL;
		CoUninitialize();
		fprintf(fp,"AtlAdvise over\n");fflush(fp);
		for(i=0;i<testP.nunit;i++)
        {
            if(unitsbuf[i]) free(unitsbuf[i]);
        }
        free(unitsbuf);
        unitsbuf=NULL;
		if(testP.units) free(testP.units);
		if(m_Items) free(m_Items);
		//SendMessage(WM_CLOSE);
        return 0;
	}
	fprintf(fp,"AtlAdvise pass\n");fflush(fp);
	//fprintf(fp,"6:%s\n",szErrorText);
	// Enable Buttons and Disable Start Button
	/*m_CtrlStop.EnableWindow(TRUE);
	m_CtrlRead.EnableWindow(TRUE);
	m_CtrlWrite.EnableWindow(TRUE);
	m_CtrlChkActive.EnableWindow(TRUE);
	m_CtrlStart.EnableWindow(FALSE);*/
	//fclose(fp);
	//fclose(initFile);
	fclose(fp);
	return 1;
}

void free_plc()
{
    int i=0;
    for(i=0;i<testP.nunit;i++)
    {
        if(unitsbuf[i]) free(unitsbuf[i]);
    }
    free(unitsbuf);
    unitsbuf=NULL;
    if(testP.units) free(testP.units);
    /*if(testP.query_results)
    {
        for(i=0;i<testP.query_nrow;i++)
        {
            if(testP.query_results[i].result_row)
                free(testP.query_results[i].result_row);
        }
        free(testP.query_results);
    }*/
    return;
}

//
// OnButtonRead: handler is being called, when button "Read Value" has been pressed
//
// This handler for OPC:
//	- initiates an async read request
//
void read_plc()
{
	OPCHANDLE		*phServer;
	DWORD			dwCancelID;
	HRESULT			*pErrors;
	HRESULT			r1;
	LPWSTR			ErrorStr;
	CString			szOut;
	int i=0,j=0;
	int read_count=0;
	char buf[1024]={0};
//	char* filepath;
//	filepath=_getcwd(NULL,0);
	sprintf(buf,"%s\\plc_read.log",filepath);
	//sprintf(buf,"E:\\plc_read1.log",filepath);
	FILE* fp = fopen(buf,"w");

	fprintf(fp,"\n\n");fflush(fp);
	fprintf(fp,"%s\n",buf);
	//fprintf(fp,"%d\n",1);
	for(i=0;i<testP.nunit;i++)
	{
		if(testP.units[i].readorwrite==0)
        {
            if (m_pErrors[i] != S_OK) // Item not available
            {
                //MessageBox("OPC Item0 not available!",
                           //"Error Read async", MB_OK+MB_ICONERROR);
                fprintf(fp,"%d,errors\n",i);fflush(fp);
                //fclose(fp);
                //return;
            }
        }
	}

    for(i=0;i<testP.nunit;i++)
	{
		if(testP.units[i].readorwrite==0) read_count++;
	}
	//read_count=10;
	fprintf(fp,"%d\n",read_count);fflush(fp);
    // Memory allocation really needed, if more than 1 item to be read
	phServer = (OPCHANDLE*)malloc(read_count*sizeof(OPCHANDLE));
	// Select item by server handle, received at AddItem
	for(i=0;i<testP.nunit;i++)
	//for(i=0;i<read_count;i++)
	{
		if(testP.units[i].readorwrite==0)
		{
		    //fprintf(fp,"i=%d,j=%d\n",i,j);fflush(fp);
			phServer[j]=m_pItemResult[i].hServer;
			j++;
		}
	}
	r1 = m_pIOPCAsyncIO2->Read(read_count,				// [in] Read 1 Item
							phServer,		// [in] Item defined in this array
							1,				// [out] Clients Transaction ID, not used in this sample
							&dwCancelID,	// [out] Servers Cancel ID, not used in this sample
							&pErrors		// [out] Errors for each item, returned by OPC Server
						);

	free(phServer);
	if (r1 == S_FALSE)
	{
	    for(i=0;i<testP.nunit;i++)
        {
            if(testP.units[i].readorwrite==0)
            {
                m_pIOPCServer->GetErrorString(pErrors[i], LOCALE_ID, &ErrorStr);
            }
        }
	    //m_pIOPCServer->GetErrorString(pErrors[0], LOCALE_ID, &ErrorStr);
		//szOut.Format ("%s",ErrorStr);
		//MessageBox(szOut, "Error Reading Item0", MB_OK+MB_ICONERROR);
		// release ErrorStr
		fprintf(fp,"failed\n");fflush(fp);
        CoTaskMemFree(ErrorStr);
    }
	szOut.Format("%d",r1);
	fprintf(fp,"%s\n",szOut);
	//MessageBox(szOut,"info",MB_OK);
	if (FAILED(r1))
	{	//szOut.Format ("Method call IOPCAsyncIO2::Read failed with error code %x", r1);
		//MessageBox(szOut, "Error Reading Item0", MB_OK+MB_ICONERROR);
		fprintf(fp,"failed\n");fflush(fp);
	}
	else
	{	// release [out] parameter in case of not failed
		CoTaskMemFree(pErrors);

		szOut.Format("%d",plc_data);
	//fprintf(fp,"%s\n",szOut);
		//strncpy(name,szReadVal.mb_str(wxConvUTF8),64);
	}
	fclose(fp);
}



//
// OnButtonWrite: handler is being called, when button "Write Value" has been pressed
//
// This handler for OPC:
//  - Retrieves Value of Item 0 from dialog
//	- initiates an async write request
//
void write_plc()
{
	OPCHANDLE		*phServer;
	DWORD			dwCancelID;
	VARIANT			*values;
	HRESULT			*pErrors;
	HRESULT			r1;
	LPWSTR			ErrorStr;
	CString			szOut;
	int i=0,j=0;
	int write_count=0;

	int value=12;
	char buf[1024]={0};
//	char* filepath;
//	filepath=_getcwd(NULL,0);
	sprintf(buf,"%s\\plc_write.log",filepath);
	FILE* fp = fopen(buf,"w");

    for(i=0;i<testP.nunit;i++)
	{
		if(testP.units[i].readorwrite==1)
        {
            if (m_pErrors[i] != S_OK) // Item not available
            {	//MessageBox("OPC Item not available!",
                           //"Error Write async", MB_OK+MB_ICONERROR);
                //return;
                fprintf(fp,"%d,errors\n",i);fflush(fp);
            }
        }
	}
	for(i=0;i<testP.nunit;i++)
	{
		if(testP.units[i].readorwrite==1) write_count++;
	}
	fprintf(fp,"write_count=%d\n",write_count);
    // Memory allocation really needed, if more than 1 item to be read
	phServer = (OPCHANDLE*)calloc(write_count,sizeof(OPCHANDLE));
	values = (VARIANT*)calloc(write_count,sizeof(VARIANT));
	memset(values,0,write_count*sizeof(VARIANT));           ///可以全都读一下，看看是否写的正确
	// Select item by server handle, received at AddItem
	for(i=0;i<testP.nunit;i++)
	{
		if(testP.units[i].readorwrite==1)
		{
            fprintf(fp,"i=%d,j=%d\n",i,j);fflush(fp);
			phServer[j]=m_pItemResult[i].hServer;
			values[j].vt = testP.units[i].type;
			if(values[j].vt==5)
            {
                values[j].dblVal = testP.units[i].val_double;
            }
            else if(values[j].vt==4)
            {
                values[j].fltVal = testP.units[i].val_double;
            }
            else if(values[j].vt==2)
            {
                values[j].iVal = testP.units[i].val_int;
            }
            else if(values[j].vt==3)
            {
                values[j].llVal = testP.units[i].val_long;
            }
            fprintf(fp,",type=%d,int_in=%d,db_in=%lf,long_in=%ld,ival=%d,dblval=%lf\n",values[j].vt,testP.units[i].val_int,testP.units[i].val_double,testP.units[i].val_long,values[j].iVal,values[j].dblVal);
			j++;
		}
	}
    testP.write_plc_complete=0;
	r1 = m_pIOPCAsyncIO2->Write(write_count,			// [in] Write 1 Item
							phServer,	// [in] Item defined in this array
							values,		// [in] Values defined in an array of Variants
							2,			// [in] Clients transaction ID, not used in this sample
							&dwCancelID,// [out] Servers Cancel ID for this transaction, not used
							&pErrors	// [out] Errors for each item, returned by OPC Server
						);
	free(phServer);
    free(values);
	if (r1 == S_FALSE)
	{
	    for(i=0;i<testP.nunit;i++)
        {
            if(testP.units[i].readorwrite==1)
            {
                m_pIOPCServer->GetErrorString(pErrors[i], LOCALE_ID, &ErrorStr);
            }
        }
	    //m_pIOPCServer->GetErrorString(pErrors[0], LOCALE_ID, &ErrorStr);
		//m_WriteResult = ErrorStr;
		//UpdateData(FALSE);

		// release parameter in case of S_FALSE
		CoTaskMemFree(ErrorStr);
    }

	if (FAILED(r1))
	{
		fprintf(fp,"Method call IOPCAsyncIO2::Write failed with error code %x", r1);
		//MessageBox(szOut, "Error Writing Item0", MB_OK+MB_ICONERROR);
		fprintf(fp,"failed\n");fflush(fp);
	}
	else
	{	// release [out] parameter in case of not failed
		CoTaskMemFree(pErrors);
	}
    fclose(fp);
}



//
// OnButtonStop: handler is being called, when button "Stop Sample" has been pressed
//
// This handler:
//	- Removes the Callback
//	- Removes the Items
//	- Removes the group object
//	- Terminates the OPC server
//	- Releases all interfaces
//
void uninit_plc()
{
	HRESULT		r1;
	OPCHANDLE	*phServer;
	HRESULT		*pErrors;
	int i;

	// Unadvise Callback
	HRESULT hRes = AtlUnadvise(m_pIOPCGroupStateMgt, IID_IOPCDataCallback, m_dwAdvise);
	m_pIOPCGroupStateMgt->Release();

	// Remove Items
	phServer = (OPCHANDLE*)calloc(testP.nunit,sizeof(OPCHANDLE));
	for(int i=0;i<testP.nunit;i++)
	{
		phServer[i] = m_pItemResult[i].hServer;
	}
	//phServer[0] = m_pItemResult[0].hServer;
	//phServer[1] = m_pItemResult[1].hServer;

	r1 = m_pIOPCItemMgt->RemoveItems(	testP.nunit,		// [in] Remove two Items
								phServer,	// [in] Identified in by Server Handle
								&pErrors	// [out] Errors for each item, returned by OPC Server
							  );

	if ( (r1 != S_OK) && (r1 != S_FALSE) )
	{
		//MessageBox("RemoveItems failed!",
			       //"Error RemoveItems()", MB_OK+MB_ICONERROR);
	}

	free(phServer);
	CoTaskMemFree(pErrors);


	CoTaskMemFree(m_pItemResult);
	m_pItemResult=NULL;
	CoTaskMemFree(m_pErrors);
	m_pErrors=NULL;

	//Release Interface for async calls
	m_pIOPCAsyncIO2->Release();
	m_pIOPCAsyncIO2 = NULL;

	// Release ItemManagement Interface
	m_pIOPCItemMgt->Release();
	m_pIOPCItemMgt = NULL;

	// Remove Group
	r1=m_pIOPCServer->RemoveGroup(m_GrpSrvHandle, TRUE);
	if (r1 != S_OK)
	{	//MessageBox("RemoveGroup failed!",
			       //"Error RemoveGroup()", MB_OK+MB_ICONERROR);
	}
	m_GrpSrvHandle = NULL;

	// Release OPC-Server
	m_pIOPCServer->Release();
	m_pIOPCServer = NULL;

	// Uninit COM
	CoUninitialize();
	if(unitsbuf)
    {
        for(i=0;i<testP.nunit;i++)
        {
            if(unitsbuf[i]) free(unitsbuf[i]);
        }
        free(unitsbuf);
    }

	if(testP.units) free(testP.units);

	// Disable Buttons until Sample is started
	/*m_CtrlStart.EnableWindow(TRUE);
	m_CtrlStop.EnableWindow(FALSE);
	m_CtrlRead.EnableWindow(FALSE);
	m_CtrlWrite.EnableWindow(FALSE);
	m_CtrlChkActive.EnableWindow(FALSE);*/
}

