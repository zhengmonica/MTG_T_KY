//---------------------------------------------------------
// OPC Custom 2.0 Sample
// Asynchronous IO with MFC and ATL
// (c) Siemens AG 2000
//---------------------------------------------------------

//
// callback.cpp : Defines the class behaviors for the callback
//				  This callback object receives the connection point
//				  callbacks from the OPC server
//
#include "stdafx.h"
#include "pre_opc.h"		// for OPC: include MFC, ATL and OPC header files - for OPC only
//#include "OPCDA_Async.h"	// include class declaration for application class
//#include "OPCDA_AsyncDlg.h" // include class declaration of dialog class

#include "Callback.h"		// for OPC: include class declaration fpr this callback class
#include "LibPlc.h"

CString GetQualityText(UINT qnr);
							// for OPC: prototype for a helper function to get OPC quality
							//          text description from quality code

/////////////////////////////////////////////////////////////////////////////
//
// IOPCDataCallback - implementation

// OnDataChange called by OPC server when the OPC server has detected modified data
// (being called only when group and item is set to active)

STDMETHODIMP COPCDataCallback:: OnDataChange(
            /* [in] */ DWORD dwTransid,
            /* [in] */ OPCHANDLE hGroup,
            /* [in] */ HRESULT hrMasterquality,
            /* [in] */ HRESULT hrMastererror,
            /* [in] */ DWORD dwCount,
            /* [size_is][in] */ OPCHANDLE __RPC_FAR *phClientItems,
            /* [size_is][in] */ VARIANT __RPC_FAR *pvValues,
            /* [size_is][in] */ WORD __RPC_FAR *pwQualities,
            /* [size_is][in] */ FILETIME __RPC_FAR *pftTimeStamps,
            /* [size_is][in] */ HRESULT __RPC_FAR *pErrors)
	{

	    // The input parameters dwTransid, hGroup, hrMasterquality, hrMastererror, pErrors are not checked within this sample...

		CString szReadVal;			//  CString array with values as text
		CString szReadQuality;		// CString array with quality texts
		CString szReadTS;			// CString array with timeStamps as text



		CComVariant * pvarOut;		// ATL wrapper for VARIANT data type
		DWORD i;
		for (i = 0;  i<dwCount; i++) {
			pvarOut = new CComVariant(pvValues[i]);	// create VARIANT and init with received value
			pvarOut->ChangeType(VT_BSTR);			// change Variant Type to String
			szReadVal.Format("%ls", pvarOut->bstrVal);
													// put BSTR in CString
			delete pvarOut;							// delete VARIANT
			szReadQuality=GetQualityText(pwQualities[i]);
													// Call helper function to get text description
			szReadTS=COleDateTime( pftTimeStamps[i] ).Format();
													// MFC OLE Date wrapper used to change to CString

            switch (phClientItems[i]) {
            case 0:
		        //m_pCDlgClass->DisplayData0(szReadVal, szReadQuality, szReadTS);
													// Call OPCDa_AsyncDlg::Display Data0 Method to
													// show Data for Item 0 in Dialog
                break;

                case 1:
		        //m_pCDlgClass->DisplayData1(szReadVal, szReadQuality, szReadTS);
													// Call OPCDa_AsyncDlg::Display Data1 Method to
													// show Data for Item 1 in Dialog
                break;
                default: ASSERT(0);                 // SHOULD NEVER HAPPEN
            }
        }


		return S_OK;
	};

//
// OnReadComplete is being called by OPC server when an async read request has been carried out
//

#include <direct.h>

//STDMETHODIMP  COPCDataCallback::OnReadComplete(
//		/* [in] */ DWORD dwTransid,
//		/* [in] */ OPCHANDLE hGroup,
//		/* [in] */ HRESULT hrMasterquality,
//		/* [in] */ HRESULT hrMastererror,
//		/* [in] */ DWORD dwCount,
//		/* [size_is][in] */ OPCHANDLE __RPC_FAR *phClientItems,
//		/* [size_is][in] */ VARIANT __RPC_FAR *pvValues,
//		/* [size_is][in] */ WORD __RPC_FAR *pwQualities,
//		/* [size_is][in] */ FILETIME __RPC_FAR *pftTimeStamps,
//		/* [size_is][in] */ HRESULT __RPC_FAR *pErrors)
//	{
//
//
// 	    // The input parameters dwTransid, hGroup, hrMasterquality, hrMastererror, pErrors are not checked within this sample...
//
//		/* if no error: Update Data */
//	//FILE* fp = fopen("E:\\callback.log","w");
//	CString			szOut;
//	LPWSTR			ErrorStr;
//	char buf[1024]={0};
//	char* filepath;
//	int i=0,j=0,k=0;
//	int index=0;
//	filepath=_getcwd(NULL,0);
//	sprintf(buf,"%s\\callback.log",filepath);
//	//sprintf(buf,"E:\\plc_read.log",filepath);
//	FILE* fp = fopen(buf,"w");
//	if(fp)
//	{
//	    fprintf(fp,"callback\n");fflush(fp);
//	}
//	for(i=0;i<testP.nunit;i++)
//    {
//        if(testP.units[i].readorwrite!=0)
//        {
//            continue;
//        }
//        else
//        {
//            k++;
//        }
//        if(testP.type==2)
//        {
//            index=phClientItems[k];
//            if(index>=testP.nunit)
//                continue;
//        }
//        else
//        {
//            index=k;
//        }
//
//        if(testP.units[i].readorwrite==0)
//        {
//            if (pErrors[i] == S_OK)
//            {
//                testP.units[index].status=1;
//                if(fp)
//                {
//                    fprintf(fp,"pErrors[%d]: S_OK  ",i);
//                    fflush(fp);
//                }
//            }
//            else {
//                /* error case: display error text */
//                CString readQuality = GetQualityText(pErrors[i]);
//                szOut= GetQualityText(pErrors[i]);
//                //m_pCDlgClass->DisplayData(0,readQuality,"");
//                //szOut.Format ("%s",ErrorStr);
//                if(fp)
//                {
//                    fprintf(fp,"i=%d,%s ",i,szOut);
//                    fflush(fp);
//                }
//                testP.units[index].status=0;
//            }
//            if(fp)
//            {
//                fprintf(fp,"type=%d ",testP.units[index].type);
//                fflush(fp);
//            }
//            if(testP.units[index].type==2)
//            {
//                testP.units[index].val_int=pvValues[j].iVal;
//                if(fp)
//                {
//                    fprintf(fp,"units: %d ",testP.units[index].val_int);
//                    fflush(fp);
//                }
//            }
//            else if(testP.units[index].type==5)
//            {
//                testP.units[index].val_double=pvValues[j].dblVal;
//                if(fp)
//                {
//                    fprintf(fp,"units: %.4f ",testP.units[index].val_double);
//                    fflush(fp);
//                }
//            }
//            else if(testP.units[index].type==11)
//            {
//                if(pvValues[j].boolVal)
//                {
//                    testP.units[index].val_int = 1;
//                }
//                else
//                {
//                    testP.units[index].val_int = 0;
//                }
//                if(fp)
//                {
//                    fprintf(fp,"units: %d ",testP.units[index].val_int);
//                    fflush(fp);
//                }
//            }
//            else if(testP.units[index].type==4)///20171129whq新增
//            {
//                testP.units[index].val_double=pvValues[j].fltVal;
//                if(fp)
//                {
//                    fprintf(fp,"units: %d ",testP.units[index].val_double);
//                    fflush(fp);
//                }
//            }
//            else if(testP.units[index].type==3)   ///20201125ws add
//            {
//                testP.units[index].val_long=pvValues[j].llVal;
//                if(fp)
//                {
//                    fprintf(fp,"units: %d ",testP.units[index].val_long);
//                    fflush(fp);
//                }
//            }
//            if(fp)
//            {
//                fprintf(fp,"val_int=%d,val_double=%.4f,val_long=%ld\n",testP.units[index].val_int,testP.units[index].val_double,testP.units[index].val_long);
//                fflush(fp);
//            }
//            j++;
//        }
//        else
//        {
//            if(fp)
//            {
//                fprintf(fp,"i:%d,type=%d is not read type\n",i,testP.units[index].readorwrite);
//                fflush(fp);
//            }
//        }
//    }
//    testP.read_plc_complete=1;
//
//    if(fp)
//    {
//        fclose(fp);
//        fp=NULL;
//    }
//    return S_OK;
//};

STDMETHODIMP  COPCDataCallback::OnReadComplete(
		/* [in] */ DWORD dwTransid,
		/* [in] */ OPCHANDLE hGroup,
		/* [in] */ HRESULT hrMasterquality,
		/* [in] */ HRESULT hrMastererror,
		/* [in] */ DWORD dwCount,
		/* [size_is][in] */ OPCHANDLE __RPC_FAR *phClientItems,
		/* [size_is][in] */ VARIANT __RPC_FAR *pvValues,
		/* [size_is][in] */ WORD __RPC_FAR *pwQualities,
		/* [size_is][in] */ FILETIME __RPC_FAR *pftTimeStamps,
		/* [size_is][in] */ HRESULT __RPC_FAR *pErrors)
	{


 	    // The input parameters dwTransid, hGroup, hrMasterquality, hrMastererror, pErrors are not checked within this sample...

		/* if no error: Update Data */
	//FILE* fp = fopen("E:\\callback.log","w");
	CString			szOut;
	LPWSTR			ErrorStr;
	char buf[1024]={0};
	char* filepath;
	int i=0,j=0,k=0;
	int index=0;
	filepath=_getcwd(NULL,0);
	sprintf(buf,"%s\\callback.log",filepath);
	//sprintf(buf,"E:\\plc_read.log",filepath);
	FILE* fp = fopen(buf,"w");
	if(fp)
	{
	    fprintf(fp,"callback\n");fflush(fp);
	}

	for(j=0;j<dwCount;j++)
    {
        index=phClientItems[j];
        if(fp)
        {
            fprintf(fp,"j:%d,index:%d\n",j,index);fflush(fp);
        }
        if (pErrors[j] == S_OK)
        {
            testP.units[index].status=1;
            if(fp)
            {
                fprintf(fp,"pErrors[%d]: S_OK  ",j);
                fflush(fp);
            }
        }
        else {
            /* error case: display error text */
            CString readQuality = GetQualityText(pErrors[j]);
            szOut= GetQualityText(pErrors[j]);
            //m_pCDlgClass->DisplayData(0,readQuality,"");
            //szOut.Format ("%s",ErrorStr);
            if(fp)
            {
                fprintf(fp,"j=%d,%s ",j,szOut);
                fflush(fp);
            }
            testP.units[index].status=0;
        }
        if(testP.units[index].type==2)
        {
            testP.units[index].val_int=pvValues[j].iVal;
            if(fp)
            {
                fprintf(fp,"units: %d ",testP.units[index].val_int);
                fflush(fp);
            }
        }
        else if(testP.units[index].type==5)
        {
            testP.units[index].val_double=pvValues[j].dblVal;
            if(fp)
            {
                fprintf(fp,"units: %.4f ",testP.units[index].val_double);
                fflush(fp);
            }
        }
        else if(testP.units[index].type==11)
        {
            if(pvValues[j].boolVal)
            {
                testP.units[index].val_int = 1;
            }
            else
            {
                testP.units[index].val_int = 0;
            }
            if(fp)
            {
                fprintf(fp,"units: %d ",testP.units[index].val_int);
                fflush(fp);
            }
        }
        else if(testP.units[index].type==4)///20171129whq新增
        {
            testP.units[index].val_double=pvValues[j].fltVal;
            if(fp)
            {
                fprintf(fp,"units: %d ",testP.units[index].val_double);
                fflush(fp);
            }
        }
        else if(testP.units[index].type==3)   ///20201125ws add
        {
            testP.units[index].val_long=pvValues[j].llVal;
            if(fp)
            {
                fprintf(fp,"units: %d ",testP.units[index].val_long);
                fflush(fp);
            }
        }
        if(fp)
        {
            fprintf(fp,"val_int=%d,val_double=%.4f,val_long=%ld\n",testP.units[index].val_int,testP.units[index].val_double,testP.units[index].val_long);
            fflush(fp);
        }
    }
//	for(i=0;i<testP.nunit;i++)
//    {
//        if(testP.units[i].readorwrite!=0)
//        {
//            continue;
//        }
//        else
//        {
//            k
//        }
//
//        if(testP.type==2)
//        {
//            index=phClientItems[k];
//            if(index>=testP.nunit)
//                continue;
//        }
//        else
//        {
//            index=k;
//        }
//
//        if(testP.units[i].readorwrite==0)
//        {
//            if (pErrors[i] == S_OK)
//            {
//                testP.units[index].status=1;
//                if(fp)
//                {
//                    fprintf(fp,"pErrors[%d]: S_OK  ",i);
//                    fflush(fp);
//                }
//            }
//            else {
//                /* error case: display error text */
//                CString readQuality = GetQualityText(pErrors[i]);
//                szOut= GetQualityText(pErrors[i]);
//                //m_pCDlgClass->DisplayData(0,readQuality,"");
//                //szOut.Format ("%s",ErrorStr);
//                if(fp)
//                {
//                    fprintf(fp,"i=%d,%s ",i,szOut);
//                    fflush(fp);
//                }
//                testP.units[index].status=0;
//            }
//            if(fp)
//            {
//                fprintf(fp,"type=%d ",testP.units[index].type);
//                fflush(fp);
//            }
//            if(testP.units[index].type==2)
//            {
//                testP.units[index].val_int=pvValues[j].iVal;
//                if(fp)
//                {
//                    fprintf(fp,"units: %d ",testP.units[index].val_int);
//                    fflush(fp);
//                }
//            }
//            else if(testP.units[index].type==5)
//            {
//                testP.units[index].val_double=pvValues[j].dblVal;
//                if(fp)
//                {
//                    fprintf(fp,"units: %.4f ",testP.units[index].val_double);
//                    fflush(fp);
//                }
//            }
//            else if(testP.units[index].type==11)
//            {
//                if(pvValues[j].boolVal)
//                {
//                    testP.units[index].val_int = 1;
//                }
//                else
//                {
//                    testP.units[index].val_int = 0;
//                }
//                if(fp)
//                {
//                    fprintf(fp,"units: %d ",testP.units[index].val_int);
//                    fflush(fp);
//                }
//            }
//            else if(testP.units[index].type==4)///20171129whq新增
//            {
//                testP.units[index].val_double=pvValues[j].fltVal;
//                if(fp)
//                {
//                    fprintf(fp,"units: %d ",testP.units[index].val_double);
//                    fflush(fp);
//                }
//            }
//            else if(testP.units[index].type==3)   ///20201125ws add
//            {
//                testP.units[index].val_long=pvValues[j].llVal;
//                if(fp)
//                {
//                    fprintf(fp,"units: %d ",testP.units[index].val_long);
//                    fflush(fp);
//                }
//            }
//            if(fp)
//            {
//                fprintf(fp,"val_int=%d,val_double=%.4f,val_long=%ld\n",testP.units[index].val_int,testP.units[index].val_double,testP.units[index].val_long);
//                fflush(fp);
//            }
//            j++;
//        }
//        else
//        {
//            if(fp)
//            {
//                fprintf(fp,"i:%d,type=%d is not read type\n",i,testP.units[index].readorwrite);
//                fflush(fp);
//            }
//        }
//    }
    testP.read_plc_complete=1;

    if(fp)
    {
        fclose(fp);
        fp=NULL;
    }
    return S_OK;
};



//
// OnWriteComplete called by OPC server when an async write request has been carried out
//
STDMETHODIMP  COPCDataCallback::OnWriteComplete(
        /* [in] */ DWORD dwTransid,
        /* [in] */ OPCHANDLE hGroup,
        /* [in] */ HRESULT hrMastererr,
        /* [in] */ DWORD dwCount,
        /* [size_is][in] */ OPCHANDLE __RPC_FAR *pClienthandles,
        /* [size_is][in] */ HRESULT __RPC_FAR *pErrors)
	{

		/* Display Error Text */

		//m_pCDlgClass->DisplayData(pErrors[0]);
        testP.write_plc_complete=1;
		return S_OK;
	};

//
// Converts opc quality codes into text strings
//

CString GetQualityText(UINT qnr)
{	CString qstr;

	switch(qnr)

    {	case OPC_QUALITY_BAD:			qstr = "BAD";
					break;
        case OPC_QUALITY_UNCERTAIN:		qstr = "UNCERTAIN";
					break;
        case OPC_QUALITY_GOOD:			qstr = "GOOD";
					break;
		case OPC_QUALITY_NOT_CONNECTED:	qstr = "NOT_CONNECTED";
					break;
        case OPC_QUALITY_DEVICE_FAILURE:qstr = "DEVICE_FAILURE";
					break;
        case OPC_QUALITY_SENSOR_FAILURE:qstr = "SENSOR_FAILURE";
					break;
        case OPC_QUALITY_LAST_KNOWN:    qstr = "LAST_KNOWN";
					break;
        case OPC_QUALITY_COMM_FAILURE:  qstr = "COMM_FAILURE";
					break;
        case OPC_QUALITY_OUT_OF_SERVICE:qstr = "OUT_OF_SERVICE";
					break;
        case OPC_QUALITY_LAST_USABLE:	qstr = "LAST_USABLE";
					break;
        case OPC_QUALITY_SENSOR_CAL:	qstr = "SENSOR_CAL";
					break;
        case OPC_QUALITY_EGU_EXCEEDED:  qstr = "EGU_EXCEEDED";
					break;
        case OPC_QUALITY_SUB_NORMAL:	qstr = "SUB_NORMAL";
					break;
        case OPC_QUALITY_LOCAL_OVERRIDE:qstr = "LOCAL_OVERRIDE";
					break;
        default:						qstr = "UNKNOWN ERROR";
	}
	return qstr;
}

//---------------------------------------------------------
// (c) Siemens AG 2000
//---------------------------------------------------------
