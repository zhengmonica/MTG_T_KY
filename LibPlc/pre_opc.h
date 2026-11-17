//  pre_opc.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//	MFC, ATL and OPC header files
//

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC OLE automation classes
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>

#include "OPCDA.H"
#include "OPCcomn.H"
#include "OPCError.h"
