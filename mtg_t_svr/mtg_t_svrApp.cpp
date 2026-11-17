/***************************************************************
 * Name:      mtg_t_svrApp.cpp
 * Purpose:   Code for Application Class
 * Author:    MIDU (lhr@midu.com)
 * Created:   2016-02-20
 * Copyright: MIDU (http://www.midu.com)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "mtg_t_svrApp.h"
#include <wx/stdpaths.h>
#include <wx/msgdlg.h>
#include "libele.h"
#include <wx/dir.h>
#include <wx/filename.h>
#include "hasp_vcode.h"
#include "hasp_api.h"
#include "Ini.h"
#include "ping.h"

//(*AppHeaders
#include "mtg_t_svrMain.h"
#include <wx/image.h>
//*)
mtg_t *mtg=0;
MapViewDlg *mapDlg=0;
LogDialog* logDlg=0;
//wxString path = _("");
wxBrush ibrush[10];
wxPen ipen[10];
wxColor icolor[10];
long iver=0;
long deadline=0;
int hasptype=0;

double MinAJLength=0.8;
int SegStart=0;    ///0表示未进入状态
int SegDoing=0;
int SegEnd=0;
double LengthPercent=0.9;

int IsChangeConnectPlcWay=0;   //0表示未修改过plc连接方式   1表示修改过

IMPLEMENT_APP(mtg_t_svrApp);

bool mtg_t_svrApp::OnInit()
{
    time_t now;
    time(&now);
    wxStandardPaths wsp;
    wxString str=wsp.GetDataDir()+wxString(_("\\data\\"))+wxDateTime(now).Format(_("%Y-%m-%d.log"));

    char path[260];

    ibrush[0]=wxBrush(wxColor(255,255,255));
    ibrush[1]=wxBrush(wxColor(200,225,250));
    ibrush[2]=wxBrush(wxColor(80,196,23));
    ibrush[3]=wxBrush(wxColor(200,225,250));
    ibrush[4]=wxBrush(wxColor(200,225,250));
    ibrush[5]=wxBrush(wxColor(80,196,23));
    ibrush[6]=wxBrush(wxColor(200,225,250));
    ibrush[7]=wxBrush(wxColor(80,196,23));
    ibrush[8]=wxBrush(wxColor(80,196,23));
    ibrush[9]=wxBrush(wxColor(80,196,23));
    ipen[0]=wxPen(wxColor(178,178,178));
    ipen[1]=wxPen(wxColor(21,131,221));
    ipen[2]=wxPen(wxColor(80,196,23));
    ipen[3]=wxPen(wxColor(21,131,221));
    ipen[4]=wxPen(wxColor(21,131,221));
    ipen[5]=wxPen(wxColor(21,131,221));
    ipen[6]=wxPen(wxColor(21,131,221));
    ipen[7]=wxPen(wxColor(21,131,221));
    ipen[8]=wxPen(wxColor(21,131,221));
    ipen[9]=wxPen(wxColor(21,131,221));
    icolor[0]=wxColor(0,0,0);
    icolor[1]=wxColor(0,0,0);
    icolor[2]=wxColor(255,255,255);
    icolor[3]=wxColor(0,0,0);
    icolor[4]=wxColor(0,0,0);
    icolor[5]=wxColor(0,0,0);
    icolor[6]=wxColor(0,0,0);
    icolor[7]=wxColor(0,0,0);
    icolor[8]=wxColor(0,0,0);
    icolor[9]=wxColor(0,0,0);

    ///加密
    if(lock_sense(1,174)==0)
    {
        wxMessageBox(_("加密狗访问失败，\n请与上海米度测量技术有限公司联系！"),_("错误"),wxOK|wxICON_ERROR);
        trace(0,"License: sensor error\n");
        return 0;
    }
    else
    {
        ReadDogTime();     ///20191107ws add  获取加密够中到期时间
    }
    ///加密

    const wxString name = wxString::Format(wxT("mtg_t_svr-%s"), wxGetUserId().c_str());
    m_check = new wxSingleInstanceChecker(name);
    if(m_check->IsAnotherRunning())
    {
        wxMessageBox(_("程序正在运行!"),_("错误"),wxOK|wxICON_ERROR);
        return false;
    }

    mtg=(mtg_t*)malloc(sizeof(mtg_t));
    mtg_init(mtg);
    time(&now);
    str=wsp.GetDataDir()+wxString(_("\\data\\"))+wxString(_("base.log"));
    strcpy(mtg->pbi,str.mb_str(wxConvLocal));
    mtg->fbi=fopen(mtg->pbi,"w");
    str=wsp.GetDataDir()+wxString(_("\\data\\"))+wxString(_("main.log"));
    strcpy(mtg->pmain,str.mb_str(wxConvLocal));

    str=wsp.GetDataDir()+wxString(_("\\data\\"))+wxDateTime(now).Format(_("%Y-%m-%d.log"));
    strcpy(mtg->popi,str.mb_str(wxConvLocal));

    FILE* fp=fopen(mtg->popi,"a");
    if(fp)
    {
        fprintf(fp,"%%R1P,%d,%ld\n",0,(long)now);     ///软件启动
        fclose(fp);
    }

    ///导入数据
    if(!mtg_import_db(mtg))
    {
        mtg_init_db(mtg);
        mtg_import_db(mtg);
    }

    if(mtg->tarset.ver==0)
    {
        strcpy(mtg->comset[2].ip,"192.168.0.203");
        mtg->comset[2].port=5300;
        strcpy(mtg->comset[3].ip,"192.168.0.204");
        mtg->comset[3].port=5300;
    }

    CIni ini;
    wxString iniPath = wsp.GetDataDir() +wxString(_("\\set.ini"));
	ini.SetPathName(iniPath);
	mtg->tarset.baseinc=ini.GetInt(_T("para"),_T("BaseInclinometer"),0);


	mtg->incA_flag=ini.GetInt(_T("para"),_T("incA_flag"),0);
	mtg->init_rollA=ini.GetDouble(_T("para"),_T("init_roll"),0);
	mtg->init_pitchA=ini.GetDouble(_T("para"),_T("init_pitch"),0);

	mtg->ver=ini.GetInt(_T("para"),_T("ver"),0);
	TCHAR DACIP[60] = {0};
	ini.GetString(_T("para"), _T("incA_IP"), DACIP, sizeof(DACIP) / sizeof(DACIP[0]));
	wxString wxDACIP(DACIP);
	strncpy(mtg->comset[6].ip, (const char*)wxDACIP.mb_str(), sizeof(mtg->comset[6].ip));
    mtg->comset[6].port=ini.GetInt(_T("para"),_T("incA_Port"),0);


    if(mtg->iset.plctype==0)
    {
        str=wsp.GetDataDir()+wxString(_("\\plc_config.cfg"));
        strcpy(path,str.mb_str(wxConvLocal));
        if(!wxFileExists(str))
            wxMessageBox(_("缺少PLC配置文件！"));
        if(init_plc(path)==1)
        {
            mtg->itbm=1;
            //read_plc();
        }
        if(testP.type==5)  //软plc
            mtg_read_faj(mtg);  //软plc   ///20200819ws add
    }
    else if(mtg->iset.plctype==1)    ///20200825ws add
    {
        TCHAR sIpWeb[60] = {0};
        TCHAR sIpTbm[60] = {0};
        ini.GetString(_T("para"), _T("WebIP"), testW.m_sIPWeb, sizeof(testW.m_sIPWeb) / sizeof(testW.m_sIPWeb[0]));
        ini.GetString(_T("para"), _T("TbmIP"), testW.m_sIPTbm, sizeof(testW.m_sIPTbm) / sizeof(testW.m_sIPTbm[0]));
        ini.GetString(_T("para"), _T("WebReadUrl"), testW.m_sUrlReadWeb, sizeof(testW.m_sUrlReadWeb) / sizeof(testW.m_sUrlReadWeb[0]));
        ini.GetString(_T("para"), _T("TbmWriteUrl"), testW.m_sUrlWriteTbm, sizeof(testW.m_sUrlWriteTbm) / sizeof(testW.m_sUrlWriteTbm[0]));
//        ini.GetString(_T("para"), _T("account"), testW.m_sAccount, sizeof(testW.m_sAccount) / sizeof(testW.m_sAccount[0]));
//        ini.GetString(_T("para"), _T("password"), testW.m_sPassword, sizeof(testW.m_sPassword) / sizeof(testW.m_sPassword[0]));
        ///wxMessageBox(wxString(testW.m_sUrlReadWeb));
        wxString wxStrWeb(testW.m_sIPWeb);
        wxString wxStrTbm(testW.m_sIPTbm);
        char sIpWebA[60] = {0};
        char sIpTbmA[60] = {0};
        strncpy(sIpWebA, (const char*)wxStrWeb.mb_str(), sizeof(sIpWebA));
        strncpy(sIpTbmA, (const char*)wxStrTbm.mb_str(), sizeof(sIpTbmA));
        BOOL bServerConOk = TRUE;
        BOOL bRet = FALSE;
        bRet = IsIpValid(sIpWebA);
        if (!bRet)
        {
//            sDebug.Printf(_T("web ip:%s,网络不通!"), wxStrWeb);
            bServerConOk = FALSE;
            wxMessageBox(_T("web ip:")+wxStrWeb+_T(",网络不通!"));
        }
        bRet = IsIpValid(sIpTbmA);
        if (!bRet)
        {
//            sDebug.Printf(_T("tbm ip:%s,网络不通!"), wxStrTbm);
            bServerConOk = FALSE;
            wxMessageBox(_T("web ip:")+wxStrTbm+_T(",网络不通!"));
        }

        str=wsp.GetDataDir()+wxString(_("\\web_config.cfg"));
        strcpy(path,str.mb_str(wxConvLocal));
        if(!wxFileExists(str))
            wxMessageBox(_("缺少PLC配置文件！"));

        if(bServerConOk)
        {
            if(init_web(path)==1)
            {
                mtg->itbm=1;
            }
        }
    }

    str=wsp.GetDataDir()+wxString(_("\\plugins"))+wxString(_("\\Database.prj"));
    strcpy(mtg->dbpath,str.mb_str(wxConvLocal));

    str=wsp.GetDataDir()+wxString(_("\\log"));
    if(!wxDir::Exists(str))
    {
        wxFileName::Mkdir(str);
    }

    str=wxString(_("D:\\midu\\"));
    if(!wxDir::Exists(str))
    {
        wxFileName::Mkdir(str);
    }
    str+=wxString(_("msr_t.db"));
    strcpy(mtg->sqlitepath,str.mb_str(wxConvLocal));
    //if(!wxFileExists(str))
    {
        sqlite_export_db(mtg,mtg->sqlitepath);
//        wxMessageBox(wxString::Format(_("%d"),sqlite_export_db(mtg,mtg->sqlitepath)));
    }
    sqlite_import_aj(mtg,mtg->sqlitepath);
    ///震动环境下修改状态
    if(mtg->iset.vibration==1)
    {
        mtg->maj=mtg->maj0;
//        mtg->maj.status=0;
//        time(&mtg->maj.t4);
//        if(sqlite_export_origin_aj(mtg,mtg->sqlitepath))
//        {
//            wxMessageBox(_("更新标定状态失败!"));
//        }
    }

    //20200602ws add 设置文件读取
    char buf1[1024]={0};
    char buf2[1024]={0};
    str=wsp.GetDataDir()+wxString(_("\\plugins"))+wxString(_("\\set.prj"));
    strcpy(buf1,str.mb_str(wxConvLocal));
    FILE *setfile=fopen(buf1,"r");
    if(setfile)
    {
        fgets(buf2,1023,setfile);
        sscanf(buf2,"%lf",&MinAJLength);
        fgets(buf2,1023,setfile);
        sscanf(buf2,"%lf",&LengthPercent);
        fclose(setfile);
    }
    //wxMessageBox(wxString::Format(_("%.4f,%.4f\n"),MinAJLength,LengthPercent));

    //20200728ws add 读取倾斜仪滤波计算的时间设置
    str=wsp.GetDataDir()+wxString(_("\\plugins"))+wxString(_("\\smoothtime.cfg"));
    strcpy(buf1,str.mb_str(wxConvLocal));
    setfile=fopen(buf1,"r");
    if(setfile)
    {
        fgets(buf2,1023,setfile);
        sscanf(buf2,"%d",&mtg->SmoothTime);
        fclose(setfile);
    }

    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	mtg_t_svrFrame* Frame = new mtg_t_svrFrame(0);
    	Frame->SetMinSize(wxSize(800,600));
    	Frame->SetSize(1024,728);
    	Frame->CenterOnScreen();
    	Frame->Show();
    	SetTopWindow(Frame);
    }

    return wxsOK;
}

int mtg_t_svrApp::ReadDogTime()
{
    hasp_status_t status;
    hasp_handle_t handle;
    char *info = 0;
    char *start_time=0;
    char *total_time=0;
    char *exp_date=0;
    char *license_type=0;
    char *featureID=0;
    char *featureIDt=0;
    char *concurrency=0;
    int k=0;
    int index=0;
    time_t t;
    long deadline1=0;
    int hasptype;
    char license_type_value[64]={0};
    char start_time_value[64]={0};
    char total_time_value[64]={0};
    char exp_date_value[64]={0};

    const char* scope =
    "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
    "<haspscope/>";
    const char* view =
    "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
    "<haspformat root=\"hasp_info\">"
    "  <hasp>\n"
    "    <attribute name=\"id\" />\n"
    "    <attribute name=\"type\" />\n"
    "    <feature>\n"
    "      <attribute name=\"id\" />\n"
    "      <element name=\"concurrency\" />\n"
    "      <element name=\"license\" />\n"
    "      <session>\n"
    "        <element name=\"username\" />\n"
    "        <element name=\"hostname\" />\n"
    "        <element name=\"ip\" />\n"
    "        <element name=\"apiversion\" />\n"
    "      </session>\n"
    "    </feature>\n"
    "  </hasp>\n"
    "</haspformat>\n";
    status=hasp_login(174,(hasp_vendor_code_t *)vendor_code,&handle);
    if(status==HASP_STATUS_OK)
    {
        status = hasp_get_info(scope, view, vendor_code, &info);
        if (status == HASP_STATUS_OK)
        {
            concurrency=strstr(info,"<feature id=\"174\">");
            if(concurrency!=NULL)
                featureID=concurrency;

            while(featureID!=NULL)
            {
                ///解析加密狗中的时间授权信息
                concurrency=strstr(featureID,"<concurrency>");
                license_type=strstr(featureID,"<license_type>");
                start_time=strstr(featureID,"<time_start>");
                total_time=strstr(featureID,"<total_time>");
                exp_date=strstr(featureID,"<exp_date>");

                k=0;
                if(license_type)
                {
                    for(int i=14;i<50;i++)
                    {
                        if(license_type[i]=='<')
                        {
    //                        license_type[k]='\0';
                            break;
                        }
                        license_type_value[k]=license_type[i];
                        k++;
                    }
                    license_type_value[k]='\0';
                }

                if(strcmp(license_type_value,"trial")==0)
                {
                    k=0;
                    if(start_time)
                    {
                        for(int i=12;i<50;i++)
                        {
                            if(start_time[i]=='<')
                            {
        //                            start_time[k]='\0';
                                break;
                            }
                            start_time_value[k]=start_time[i];
                            k++;
                        }
                        start_time_value[k]='\0';
                    }

                    k=0;
                    if(total_time)
                    {
                        for(int i=12;i<50;i++)
                        {
                            if(total_time[i]=='<')
                            {
        //                            total_time[k]='\0';
                                break;
                            }
                            total_time_value[k]=total_time[i];
                            k++;
                        }
                        total_time_value[k]='\0';
                    }
                    if(start_time&&total_time)
                    {
                        if(strcmp(start_time_value,"uninitialized")!=0)
                            deadline1=atol(start_time_value)+atol(total_time_value);
                        else
                            deadline1+=atol(total_time_value);

                    }
                    if(deadline<deadline1)
                        deadline=deadline1;
                    hasptype=0;
                }
                else if(strcmp(license_type_value,"expiration")==0)
                {
                    k=0;
                    if(exp_date)
                    {
                        for(int i=10;i<50;i++)
                        {
                            if(exp_date[i]=='<')
                            {
        //                            exp_date[k]='\0';
                                break;
                            }
                            exp_date_value[k]=exp_date[i];
                            k++;
                        }
                        exp_date_value[k]='\0';
                    }
                    deadline1=atol(exp_date_value);
                    if(deadline<deadline1)
                        deadline=deadline1;
                    hasptype=0;
                }
                else if(strcmp(license_type_value,"perpetual")==0)
                {
                    hasptype=1;
                    break;
                }

                featureID=strstr(concurrency,"<feature id=\"174\">");
            }

            hasp_free(info);
        }
    }

    return 0;
}

int mtg_t_svrApp::OnExit()
{
    if((mtg->itbm && testP.type!=5) && mtg->iset.plctype==0)
    {
        uninit_plc();
    }
    if(mtg->flog)
        mtg_write_log(mtg,mtg->flogs);

    FILE* fp=fopen(mtg->popi,"a");
    if(fp)
    {
        time_t now;
        time(&now);
        fprintf(fp,"%%R1P,%d,%ld\n",1,(long)now);     ///软件启动
        fflush(fp);
        fclose(fp);
    }

    mtg_final(mtg);
    delete m_check;

    traceclose();
    return 0;
}
