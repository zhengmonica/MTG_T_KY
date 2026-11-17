//---------------------------------------------------------
// OPC Custom 2.0 Sample
// Asynchronous IO with MFC and ATL
// (c) Siemens AG 2000
//---------------------------------------------------------

//
// OPCDA_AsyncDlg.cpp : implementation file of the dialog class
//						all OPC calls are located here
//

#include "stdafx.h"
#include "pre_opc.h"		// for OPC: include MFC, ATL and OPC header files
#include "OPCDA_Async.h"	// include class declaration for application class
#include "OPCDA_AsyncDlg.h" // include class declaration of dialog class

#include "Callback.h"		// for OPC: include class declaration fpr this callback class


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//// Used by GetErrorString; Language code ////
#define LOCALE_ID    0x409      // Code 0x409 = ENGLISH


const LPWSTR		szItemID0 = L"S7:[DEMO]DemoPower";    // this item must be readable and writeablein this sample
const LPWSTR		szItemID1 = L"S7:[DEMO]MW3";    // this item must be readable in this sample

const DWORD			vtDataTypeItem0 = VT_EMPTY;		// canonical datatype
const DWORD			vtDataTypeItem1 = VT_UI2;		// unsigned integer 2 Bytes

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COPCDA_AsyncDlg dialog
//
// class constructor: initialisation of dialog variables
//
COPCDA_AsyncDlg::COPCDA_AsyncDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COPCDA_AsyncDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COPCDA_AsyncDlg)
	m_ReadValue = 0;
	m_QualityRead = _T("");
	m_TimeStampRead = _T("");
	m_WriteResult = _T("");
	m_WriteVal = 0;
	m_bChkActivateGroup = FALSE;
	m_Quality0 = _T("");
	m_TimeStamp0 = _T("");
	m_Value0 = _T("");
	m_Quality1 = _T("");
	m_TimeStamp1 = _T("");
	m_Value1 = _T("");
	m_szItemID0 = szItemID0; //_T("");
	m_szItemID1 = szItemID1; // _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICONOPC);
}
//
// MFC Dialog Data Exchange handler: Maps control IDs to variables
//
void COPCDA_AsyncDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COPCDA_AsyncDlg)
	DDX_Control(pDX, IDC_CHECK_ACTIVATEGROUP, m_CtrlChkActive);
	DDX_Control(pDX, IDC_BUTTON_WRITE, m_CtrlWrite);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_CtrlStop);
	DDX_Control(pDX, IDC_BUTTON_START, m_CtrlStart);
	DDX_Control(pDX, IDC_BUTTON_READ, m_CtrlRead);
	DDX_Text(pDX, IDC_EDIT_READVAL, m_ReadValue);
	DDX_Text(pDX, IDC_EDIT_QUALITY, m_QualityRead);
	DDX_Text(pDX, IDC_EDIT_TIMESTAMP, m_TimeStampRead);
	DDX_Text(pDX, IDC_EDIT_WRITERESULT, m_WriteResult);
	DDX_Text(pDX, IDC_EDIT_WRITEVAL, m_WriteVal);
	DDX_Check(pDX, IDC_CHECK_ACTIVATEGROUP, m_bChkActivateGroup);
	DDX_Text(pDX, IDC_EDIT_ONDATA_QU1, m_Quality0);
	DDX_Text(pDX, IDC_EDIT_ONDATA_TIMEST1, m_TimeStamp0);
	DDX_Text(pDX, IDC_EDIT_ONDATA_VAL1, m_Value0);
	DDX_Text(pDX, IDC_EDIT_ONDATA_QU2, m_Quality1);
	DDX_Text(pDX, IDC_EDIT_ONDATA_TIMEST2, m_TimeStamp1);
	DDX_Text(pDX, IDC_EDIT_ONDATA_VAL2, m_Value1);
	DDX_Text(pDX, IDC_STATIC_ITEMID0, m_szItemID0);
	DDX_Text(pDX, IDC_STATIC_ITEMID1, m_szItemID1);
	//}}AFX_DATA_MAP
}

//
// MFC Message map: maps control ID to handler routines
//
BEGIN_MESSAGE_MAP(COPCDA_AsyncDlg, CDialog)
	//{{AFX_MSG_MAP(COPCDA_AsyncDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_READ, OnButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_WRITE, OnButtonWrite)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_CHECK_ACTIVATEGROUP, OnCheckActivategroup)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// COPCDA_AsyncDlg message handlers
//

//
// OnInitDialog: being called, when dialog is opened the first time
//
BOOL COPCDA_AsyncDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	

    // for OPC: remainder of this method

	// initialise interface pointer
	m_pIOPCServer = NULL;
	m_pIOPCItemMgt = NULL;
	m_pIOPCGroupStateMgt = NULL;
	
	m_dwAdvise = 0; 
	
	// Disable Buttons until Sample is started to avoid operation mistakes
	m_CtrlStop.EnableWindow(FALSE);
	m_CtrlRead.EnableWindow(FALSE);
	m_CtrlWrite.EnableWindow(FALSE);
	m_CtrlChkActive.EnableWindow(FALSE);
	
	return TRUE;
}


//
// OnSysCommand: being called, when system command "about" has been invoked
//
void COPCDA_AsyncDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}


//
// OnPaint: MFC handler, being called, when Windows or an application makes a 
//			request to repaint a portion of an application’s window
//
void COPCDA_AsyncDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}


HCURSOR COPCDA_AsyncDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
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

void COPCDA_AsyncDlg::OnButtonStart() 
{
	HRESULT		r1;
	CLSID		clsid;
	LONG		TimeBias = 0;
	FLOAT		PercentDeadband = 0.0;
	DWORD		RevisedUpdateRate;
	LPWSTR		ErrorStr1,ErrorStr2;
	CString		szErrorText;

	m_pItemResult = NULL;

	// Initialize the COM library
	r1 = CoInitialize(NULL);
	if (r1 != S_OK)
	{	if (r1 == S_FALSE)
		{	MessageBox("COM Library already initialized",
			           "Error CoInitialize()", MB_OK+MB_ICONEXCLAMATION);
		}
		else
		{	szErrorText.Format("Initialisation of COM Library failed. ErrorCode= %4x", r1);
			MessageBox(szErrorText,"Error CoInitialize()", MB_OK+MB_ICONERROR);
			SendMessage(WM_CLOSE);
			return;
		}
	}
	
	// Given a ProgID, this looks up the associated CLSID in the registry
	r1 = CLSIDFromProgID(L"OPC.SimaticNET", &clsid);
	if (r1 != S_OK)
	{	MessageBox("Retrival of CLSID failed",
				   "Error CLSIDFromProgID()", MB_OK+MB_ICONERROR);
		CoUninitialize();
		SendMessage(WM_CLOSE);
		return;
	}
	
	// Create the OPC server object and querry for the IOPCServer interface of the object
	r1 = CoCreateInstance (clsid, NULL, CLSCTX_LOCAL_SERVER ,IID_IOPCServer, (void**)&m_pIOPCServer);
	if (r1 != S_OK)
	{	MessageBox("Creation of IOPCServer-Object failed",
		           "Error CoCreateInstance()", MB_OK+MB_ICONERROR);
		m_pIOPCServer = NULL;
		CoUninitialize();
		SendMessage(WM_CLOSE);
		return;
	}

	// Add a group object "grp1" and querry for interface IOPCItemMgt
	r1=m_pIOPCServer->AddGroup(	L"grp1",		// [in] group name
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
		szErrorText.Format ("Revised Update Rate %d is different from Requested Update Rate 500",RevisedUpdateRate );
		AfxMessageBox (szErrorText);
	} 
	else
		if (FAILED(r1)) 
		{	MessageBox("Can't add Group to Server!",
					   "Error AddGroup()", MB_OK+MB_ICONERROR);
			m_pIOPCServer->Release();
			m_pIOPCServer = NULL;
			CoUninitialize();
			SendMessage(WM_CLOSE);
			return;
		}

	// define item tables with 2 items as in parameters for AddItem
		 
	m_Items[0].szAccessPath		  = L"";		// Accesspath not needed
	m_Items[0].szItemID			  = szItemID0;	// ItemID, see above
	m_Items[0].bActive			  = TRUE;		// AddItem Active, so OnDataChange will come in an active group for this item 
	m_Items[0].hClient			  = 0;			// Client handle , needed in this sample in callback OnDataChange
	m_Items[0].dwBlobSize		  = 0;			// "BinaryLargeOBject" not needed by SimaticNet OPC Server 
	m_Items[0].pBlob				  = NULL;		// no blob
	m_Items[0].vtRequestedDataType = vtDataTypeItem0;	// Return values in native (cannonical) datatype defined by the item itself

	m_Items[1].szAccessPath		  = L"";
	m_Items[1].szItemID			  = szItemID1;
	m_Items[1].bActive			  = TRUE;
	m_Items[1].hClient			  = 1;
	m_Items[1].dwBlobSize		  = 0;
	m_Items[1].pBlob			  = NULL;
	m_Items[1].vtRequestedDataType = vtDataTypeItem1;	// Return values - if possible - in data type 2 bytes integer else: see return value OPCITEMRESLUT: error for this item


	r1 = m_pIOPCItemMgt->AddItems(	2,				// [in] Add two Items
								m_Items,			// [in] defined in this structure (see above)
								&m_pItemResult,	// [out] array with additional information about the item (server assigned item handle and canonical datatype)
								&m_pErrors		// [out] tells which of the items was successfully added. For any item which failed it provides a reason.
							);

	if ( (r1 != S_OK) && (r1 != S_FALSE) )
	{	MessageBox("AddItems failed!",
		           "Error AddItems()", MB_OK+MB_ICONERROR);
		
        m_pIOPCItemMgt->Release();
		m_pIOPCItemMgt = NULL;
		m_GrpSrvHandle = 0;
		m_pIOPCServer->Release();
		m_pIOPCServer = NULL;
		CoUninitialize();
		SendMessage(WM_CLOSE);
		return; 

	}
	else
	{	// this is the normal part
        m_pIOPCServer->GetErrorString(m_pErrors[0], LOCALE_ID, &ErrorStr1);
		m_pIOPCServer->GetErrorString(m_pErrors[1], LOCALE_ID, &ErrorStr2);
		
		CString szOut;
        szOut.Format("Item %ls :\n %ls\n\nItem %ls :\n %ls\n", szItemID0, ErrorStr1, szItemID1, ErrorStr2);
		MessageBox(szOut, "Result AddItems()", MB_OK+MB_ICONEXCLAMATION);

		// release ErrorStr 
        CoTaskMemFree(ErrorStr1);	
        CoTaskMemFree(ErrorStr2);	
		// go on
	}

	// check if Item0 is readable and writeable
	if (m_pItemResult[0].dwAccessRights != (OPC_READABLE + OPC_WRITEABLE)) 
	{
		MessageBox("Item 0 ist not readable and writeable.\nThis is essential for correct operation of this sample.", "Result AddItems()", MB_OK+MB_ICONEXCLAMATION);
	}

	// Get interface for GroupStateMgt
	r1=m_pIOPCItemMgt->QueryInterface(IID_IOPCGroupStateMgt, (void**) &m_pIOPCGroupStateMgt);

	if (r1 != S_OK) 
	{	MessageBox("No IOPCGroupStateMgt found",
			           "Error QueryInterface()", MB_OK+MB_ICONERROR);
		CoTaskMemFree(m_pItemResult);
		m_pIOPCItemMgt->Release();
		m_pIOPCItemMgt = 0;
		m_GrpSrvHandle = 0;
		m_pIOPCServer->Release();
		m_pIOPCServer = NULL;
		CoUninitialize();
		SendMessage(WM_CLOSE);
		return;
	}

	// query interface for async calls on group object
	r1 = m_pIOPCItemMgt->QueryInterface(IID_IOPCAsyncIO2, (void**)&m_pIOPCAsyncIO2);
	if (r1 < 0)
	{	MessageBox("No IOPCAsyncIO found!",
	           "Error QueryInterface()", MB_OK+MB_ICONERROR);
		CoTaskMemFree(m_pItemResult);
		m_pIOPCItemMgt->Release();
		m_pIOPCItemMgt = 0;
		m_GrpSrvHandle = 0;
		m_pIOPCServer->Release();
		m_pIOPCServer = NULL;
		CoUninitialize();
		SendMessage(WM_CLOSE);
        return;
	}

	// Activate Group according to Checkbox
	OnCheckActivategroup();

	// Establish Callback for all async operations
	CComObject<COPCDataCallback>* pCOPCDataCallback;	// Pointer to Callback Object

	// Create Instance of Callback Object using an ATL template
    CComObject<COPCDataCallback>::CreateInstance(&pCOPCDataCallback);
    
	// pass pointer of this dialog class to callback object
	pCOPCDataCallback->InformAboutDialog(this);

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
	{	AfxMessageBox("Advise failed!");

		CoTaskMemFree(m_pItemResult);
		m_pIOPCItemMgt->Release();
		m_pIOPCItemMgt = 0;
		m_GrpSrvHandle = 0;
		m_pIOPCServer->Release();
		m_pIOPCServer = NULL;
		CoUninitialize();
		SendMessage(WM_CLOSE);
        return;
	}
		
	// Enable Buttons and Disable Start Button
	m_CtrlStop.EnableWindow(TRUE);
	m_CtrlRead.EnableWindow(TRUE);
	m_CtrlWrite.EnableWindow(TRUE);
	m_CtrlChkActive.EnableWindow(TRUE);
	m_CtrlStart.EnableWindow(FALSE);
}


//
// OnButtonRead: handler is being called, when button "Read Value" has been pressed
//
// This handler for OPC:
//	- initiates an async read request
//
void COPCDA_AsyncDlg::OnButtonRead() 
{
	OPCHANDLE		*phServer;
	DWORD			dwCancelID;
	HRESULT			*pErrors;
	HRESULT			r1;
	LPWSTR			ErrorStr;
	CString			szOut;
	
    if (m_pErrors[0] != S_OK) // Item not available

	{	MessageBox("OPC Item0 not available!",
			       "Error Read async", MB_OK+MB_ICONERROR);
		return;
	}
    
    // Memory allocation really needed, if more than 1 item to be read
	phServer = new OPCHANDLE[1];
	// Select item by server handle, received at AddItem
	phServer[0] = m_pItemResult[0].hServer;

	r1 = m_pIOPCAsyncIO2->Read(1,				// [in] Read 1 Item
							phServer,		// [in] Item defined in this array
							1,				// [out] Clients Transaction ID, not used in this sample
							&dwCancelID,	// [out] Servers Cancel ID, not used in this sample
							&pErrors		// [out] Errors for each item, returned by OPC Server
						);
	
	delete[] phServer;
		
	if (r1 == S_FALSE)
	{	m_pIOPCServer->GetErrorString(pErrors[0], LOCALE_ID, &ErrorStr);
		szOut.Format ("%s",ErrorStr);
		MessageBox(szOut, "Error Reading Item0", MB_OK+MB_ICONERROR);
		// release ErrorStr 
        CoTaskMemFree(ErrorStr);	
    } 
	szOut.Format("%d",r1);
	MessageBox(szOut,"info",MB_OK);
	if (FAILED(r1)) 
	{	szOut.Format ("Method call IOPCAsyncIO2::Read failed with error code %x", r1);
		MessageBox(szOut, "Error Reading Item0", MB_OK+MB_ICONERROR);
	}
	else
	{	// release [out] parameter in case of not failed
		CoTaskMemFree(pErrors);
	}
}	


//
// OnButtonWrite: handler is being called, when button "Write Value" has been pressed
//
// This handler for OPC:
//  - Retrieves Value of Item 0 from dialog
//	- initiates an async write request
//
void COPCDA_AsyncDlg::OnButtonWrite() 
{
	OPCHANDLE		*phServer;
	DWORD			dwCancelID;
	VARIANT			values[1];
	HRESULT			*pErrors;
	HRESULT			r1;
	LPWSTR			ErrorStr;
	CString			szOut;

	if (m_pErrors[0] != S_OK) // Item not available
	{	MessageBox("OPC Item not available!",
			       "Error Write async", MB_OK+MB_ICONERROR);
		return;
	}

	// Select item by server handle, received at AddItem
	phServer = new OPCHANDLE[1];
	phServer[0] = m_pItemResult[0].hServer;
	
	// Retrieve data from dialog
	UpdateData(TRUE);
	// Set Variant with datatype and received value
	values[0].vt = VT_I2;
	values[0].iVal = m_WriteVal;


	r1 = m_pIOPCAsyncIO2->Write(	1,			// [in] Write 1 Item
							phServer,	// [in] Item defined in this array
							values,		// [in] Values defined in an array of Variants
							2,			// [in] Clients transaction ID, not used in this sample
							&dwCancelID,// [out] Servers Cancel ID for this transaction, not used 
							&pErrors	// [out] Errors for each item, returned by OPC Server
						);
	delete[] phServer;
	
	if (r1 == S_FALSE)
	{	m_pIOPCServer->GetErrorString(pErrors[0], LOCALE_ID, &ErrorStr);
		m_WriteResult = ErrorStr;
		UpdateData(FALSE);
	
		// release parameter in case of S_FALSE
		CoTaskMemFree(ErrorStr);
    } 

	if (FAILED(r1)) 
	{	
		szOut.Format ("Method call IOPCAsyncIO2::Write failed with error code %x", r1);
		MessageBox(szOut, "Error Writing Item0", MB_OK+MB_ICONERROR);
	}
	else
	{	// release [out] parameter in case of not failed
		CoTaskMemFree(pErrors);
	}

}


//
// OnCheckActivategroup: handler is being called, when checkbox "Group Active" has been clicked
//
// This handler for OPC:
//  - Retrieves state of the checkboc from Dialog
//	- Sets the state of the group corresponding to the checkbox state
//
void COPCDA_AsyncDlg::OnCheckActivategroup() 
{
	UpdateData(TRUE);

	DWORD dwRevUpdateRate;
	HRESULT	r1=	m_pIOPCGroupStateMgt->SetState(NULL,	// [in] RequestedUpdateRate
						&dwRevUpdateRate,	// [out] RevisedUpdateRate
						&m_bChkActivateGroup,//[in] ActiveFlag for Group
						NULL,				// [in] TimeBias
						NULL,				// [in] PercentDeadband
						NULL,				// [in] LCID
						NULL);				// [in] Handle ClientGroup

	if (FAILED(r1))
	{	MessageBox("Set State failed",
	           "Error", MB_OK+MB_ICONERROR);
		return;
	}
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
void COPCDA_AsyncDlg::OnButtonStop() 
{
	HRESULT		r1;
	OPCHANDLE	*phServer;
	HRESULT		*pErrors;
	
	// Unadvise Callback
	HRESULT hRes = AtlUnadvise(m_pIOPCGroupStateMgt, IID_IOPCDataCallback, m_dwAdvise);
	m_pIOPCGroupStateMgt->Release();

	// Remove Items
	phServer = new OPCHANDLE[2];
	phServer[0] = m_pItemResult[0].hServer;
	phServer[1] = m_pItemResult[1].hServer;

	r1 = m_pIOPCItemMgt->RemoveItems(	2,		// [in] Remove two Items
								phServer,	// [in] Identified in by Server Handle
								&pErrors	// [out] Errors for each item, returned by OPC Server
							  );

	if ( (r1 != S_OK) && (r1 != S_FALSE) )
	{	MessageBox("RemoveItems failed!",
			       "Error RemoveItems()", MB_OK+MB_ICONERROR);
	}

	delete[] phServer; 
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
	{	MessageBox("RemoveGroup failed!",
			       "Error RemoveGroup()", MB_OK+MB_ICONERROR);
	}
	m_GrpSrvHandle = NULL;

	// Release OPC-Server
	m_pIOPCServer->Release();
	m_pIOPCServer = NULL;
	
	// Uninit COM
	CoUninitialize();

	// Disable Buttons until Sample is started
	m_CtrlStart.EnableWindow(TRUE);
	m_CtrlStop.EnableWindow(FALSE);
	m_CtrlRead.EnableWindow(FALSE);
	m_CtrlWrite.EnableWindow(FALSE);
	m_CtrlChkActive.EnableWindow(FALSE);
}
	

void COPCDA_AsyncDlg::OnDestroy() 
{
	// if OPC server initialized, shut down server
    if (m_pIOPCServer) 
		OnButtonStop();
	
	CDialog::OnDestroy();
}

//
// DisplayData0: being called from callback to display the data for Item 0
//


void COPCDA_AsyncDlg::DisplayData0(CString ReadVal, CString ReadQuality, CString ReadTS)
{

	m_Quality0=ReadQuality;
	m_TimeStamp0=ReadTS;
	m_Value0=ReadVal;
	
	UpdateData(FALSE);
}


void COPCDA_AsyncDlg::DisplayData1(CString ReadVal, CString ReadQuality, CString ReadTS)
{

	m_Quality1=ReadQuality;
	m_TimeStamp1=ReadTS;
	m_Value1=ReadVal;

	UpdateData(FALSE);
}

void COPCDA_AsyncDlg::DisplayData(long Value, CString Quality, CString TimeStamp)
{
	m_ReadValue = Value;
	m_QualityRead = Quality;
	m_TimeStampRead = TimeStamp;
	
	UpdateData(FALSE);

}


void COPCDA_AsyncDlg::DisplayData(HRESULT ErrorCode)
{
	LPWSTR			ErrorStr;

	m_pIOPCServer->GetErrorString(ErrorCode, LOCALE_ID, &ErrorStr);
	m_WriteResult = ErrorStr;
	m_WriteResult.Remove('\r');
	m_WriteResult.Remove('\n');
	UpdateData(FALSE);
    CoTaskMemFree(ErrorStr);	

}



BOOL COPCDA_AsyncDlg::UpdateData( BOOL bSaveAndValidate )
{
	BOOL bRes;

	// Enter Critical Section
    m_cCritSec.Lock();
	bRes = CDialog::UpdateData( bSaveAndValidate );
	
	// Exit Critical Section
	m_cCritSec.Unlock();

	return bRes;
}

//---------------------------------------------------------
// (c) Siemens AG 2000
//---------------------------------------------------------

