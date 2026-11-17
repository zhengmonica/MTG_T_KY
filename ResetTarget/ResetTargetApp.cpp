/***************************************************************
 * Name:      ResetTargetApp.cpp
 * Purpose:   Code for Application Class
 * Author:    whq ()
 * Created:   2019-05-14
 * Copyright: whq ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "ResetTargetApp.h"
#include "hasp_api.h"
#include "hasp_vcode.h"

//(*AppHeaders
#include "ResetTargetMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ResetTargetApp);

bool ResetTargetApp::OnInit()
{
    hasp_status_t status;
    hasp_handle_t handle;
    hasp_time_t time;
    hasp_size_t memSize;
    int bsense=0;

    hasp_size_t offset = 0;
    hasp_size_t len = 48;
    unsigned char data[48];
    int i=0;
    char mac[4][13];
    char mac16[16];
    int nMac=0;
    FILE* fp=fopen("D://hasp_get_size.log","w");
    status=hasp_login(176,(hasp_vendor_code_t *)vendor_code,&handle);
    if(status!=HASP_STATUS_OK)
    {
        if(fp)
        {
            fprintf(fp,"status:%d",status);
            fflush(fp);
            fclose(fp);
            fp=NULL;
        }
        wxMessageBox(_("加密狗访问失败，\n请与上海米度测量技术有限公司联系！"),_("错误"),wxOK|wxICON_ERROR);
        return 0;
    }
    else
    {
        hasp_logout(handle);
    }
    if(fp)
    {
        fclose(fp);
        fp=NULL;
    }
    //(*AppInitialize

    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ResetTargetDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
