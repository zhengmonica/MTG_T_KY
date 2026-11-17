/***************************************************************
 * Name:      mtg_t_cliApp.cpp
 * Purpose:   Code for Application Class
 * Author:    MIDU (lhr@midu.com)
 * Created:   2016-02-20
 * Copyright: MIDU (http://www.midu.com)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "mtg_t_cliApp.h"
#include <wx/stdpaths.h>
#include <wx/msgdlg.h>
#include  <wx/filename.h>
#include "libele.h"
//(*AppHeaders
#include "mtg_t_cliMain.h"
#include <wx/image.h>
//*)
#include "LoginDialog.h"
mtg_t *mtg=0;
mtg_cli *cli=0;
MapViewDlg *mapDlg=0;
wxSocketClient* sock=0;

wxBrush ibrush[10];
wxPen ipen[10];
wxColor icolor[10];
long iver=0;
wxLocale intl;

IMPLEMENT_APP(mtg_t_cliApp);

BEGIN_EVENT_TABLE(mtg_t_cliApp,wxApp)
    //(*EventTable(mtg_t_cliFrame)
    //EVT_SOCKET(mtg_t_cliApp::OnSocketEvent)
    //*)
END_EVENT_TABLE()

bool mtg_t_cliApp::OnInit()
{
    const wxString name = wxString::Format(wxT("mtg_t-%s"), wxGetUserId().c_str());
    m_checker = new wxSingleInstanceChecker(name);
    if ( m_checker->IsAnotherRunning() )
    {
        wxMessageBox(_("程序正在运行！"));
        return false;
    }

    bool blocal=false;
    char word[1024]="\0";
    bool login=false;
    bool link=false;

    const wxString name1 = wxString::Format(wxT("mtg_t_svr-%s"), wxGetUserId().c_str());
    wxSingleInstanceChecker checker;
    checker.Create(name1);
    if(checker.IsAnotherRunning())
    {
        blocal=true;
    }

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
    //ibrush[3]=wxBrush(wxColor(40,221,112));
    ipen[0]=wxPen(wxColor(178,178,178));
    ipen[1]=wxPen(wxColor(21,131,221));
    ipen[2]=wxPen(wxColor(80,196,23));
    ipen[3]=wxPen(wxColor(21,131,221));
    icolor[0]=wxColor(0,0,0);
    icolor[1]=wxColor(0,0,0);
    icolor[2]=wxColor(255,255,255);

    mtg=(mtg_t*)malloc(sizeof(mtg_t));
    mtg_init(mtg);
    cli=(mtg_cli*)malloc(sizeof(mtg_cli));
    memset(cli,0,sizeof(mtg_cli));

    ///导入数据
    if(!mtg_import_db(mtg))
    {
        mtg_init_db(mtg);
        mtg_import_db(mtg);
    }

    sock = new wxSocketClient();

    ///用户登录
    wxIPV4address addr;
    wxString HostIP ;
    if(blocal)
    {
        addr.LocalHost();
        HostIP = addr.IPAddress();
        cli->local=1;
    }
    else
    {
        wxStandardPaths wsp;
        wxString dirStr=wsp.GetDataDir()+wxString(_("\\client.ini"));
        char path[260];
        strcpy(path,dirStr.mb_str(wxConvLocal));
        wxString ip1=wxEmptyString;
        wxString ip2=wxEmptyString;
        wxString ip3=wxEmptyString;
        wxString ip4=wxEmptyString;
        if(wxFileName::FileExists(dirStr))
        {
            FILE* fp=fopen(path,"r");
            if(fp)
            {
                char buf[1024];
                fgets(buf,1023,fp);
                HostIP=wxString(buf,wxConvUTF8);
                int len = HostIP.length();
                int j = 0;
                wxString str1,str2;
                str1=HostIP;
                str2=wxEmptyString;
                for(int i=0;i<len;i++)
                {
                    str2 = str1.Left(1);
                    str1 = str1.Remove(0,1);
                    if(str2.Cmp(_("."))==0)
                    {
                        j++;
                        str2 = _("");
                    }
                    if(j==0)
                    {
                        ip1=ip1+str2;
                    }
                    if(j==1)
                    {
                        ip2=ip2+str2;
                    }
                    if(j==2)
                    {
                        ip3=ip3+str2;
                    }
                    if(j==3)
                    {
                        ip4=ip4+str2;
                    }
                }
            }
        }
        else
        {
            ip1=_("192");
            ip2=_("168");
            ip3=_("1");
            ip4=_("6");
            HostIP=_("192.178.1.6");
        }

        //strncpy(mtg->comset[4].ip,HostIP.mb_str(wxConvUTF8),16);

        LoginDialog dlg(NULL);
        dlg.Center();
        dlg.ip1->SetValue(ip1);
        dlg.ip2->SetValue(ip2);
        dlg.ip3->SetValue(ip3);
        dlg.ip4->SetValue(ip4);
        if(dlg.ShowModal()==wxID_OK)
        {
            ip1=dlg.ip1->GetValue();
            ip2=dlg.ip2->GetValue();
            ip3=dlg.ip3->GetValue();
            ip4=dlg.ip4->GetValue();
            HostIP=ip1+_(".")+ip2+_(".")+ip3+_(".")+ip4;
            addr.Hostname(HostIP);

            strcpy(mtg->comset[4].ip,HostIP.mb_str(wxConvUTF8));
            FILE* fp=fopen(path,"w");
            if(fp)
            {
                fprintf(fp,"%s\n",mtg->comset[4].ip);
                fclose(fp);
            }
        }
        else
        {
            cli->login=0;
            cli->mode=1;
        }
    }

    addr.Service(3000);
    sock->Connect(addr, false);
    sock->WaitOnConnect(10);

    if(sock->IsConnected())
    {
        sock->GetLocal(addr);
        if(blocal)
        {
            sprintf(word,"%%R1Q,0:%s\n",HostIP);
            sock->Write(word,strlen(word));
            cli->login=1;
        }
        else
        {
            addr.LocalHost();
            HostIP = addr.IPAddress();
            sprintf(word,"%%R1Q,0:%s\n",HostIP);
            sock->Write(word,strlen(word));
            for(int i=0; i<5; i++)
            {
                Sleep(1000);
                sock->Read(word,260);
                //wxMessageBox(wxString(word,wxConvUTF8));

                if(strcmp(word,"%R1P,0:1\n")==0)
                {
                    cli->login=1;
                    break;
                }
                else if(strcmp(word,"%R1P,0:0\n")==0)
                {
                    cli->login=0;
                    break;
                }
            }
            if(cli->login==0)
            {
                wxMessageBox(_("登录失败！"),_("错误"),wxOK|wxICON_ERROR);
                return 0;
            }
        }
        link=true;
    }
    else
    {
        //20180116whq增加
        wxMessageBox(_("连接服务器失败！"),_("错误"),wxOK|wxICON_ERROR);
    }

    ///
    mtg->segs[5].gap[0] = mtg->segset.G0;
    mtg->segs[5].gap[1] = mtg->segset.G0;
    mtg->segs[5].gap[2] = mtg->segset.G0;
    mtg->segs[5].gap[3] = mtg->segset.G0;

    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	mtg_t_cliFrame* Frame = new mtg_t_cliFrame(0);
    	Frame->SetMinSize(wxSize(800,600));
    	Frame->SetSize(1024,728);
    	Frame->CenterOnScreen();
    	sock->SetEventHandler(*Frame,-1);
        sock->SetNotify(wxSOCKET_CONNECTION_FLAG |
                          wxSOCKET_INPUT_FLAG |
                          wxSOCKET_LOST_FLAG);
        sock->Notify(true);
        if(cli->login==1)
        {
            strcpy(word,"%R1Q,1:0\n");
            strcat(word,"%R1Q,4:0\n");
            //strcat(word,"%R1Q,7:0\n");
            strcat(word,"%R1Q,10:0\n");
            strcat(word,"%R1Q,13:0\n");
            strcat(word,"%R1Q,16:0\n");
            strcat(word,"%R1Q,19:0\n");
            strcat(word,"%R1Q,22:0\n");
            //strcat(word,"%R1Q,25\n");
            strcat(word,"%R1Q,28:0\n");
            strcat(word,"%R1Q,31:0\n");
            //strcat(word,"%R1Q,34\n");
            strcat(word,"%R1Q,40:0\n");
            strcat(word,"%R1Q,50:0\n");
            //strcat(word,"%R1Q,43\n");
            //strcat(word,"%R1Q,46\n");
            sock->Write(word,strlen(word));
        }
        sleepms(100);
        Frame->Show();
    	SetTopWindow(Frame);
    }

    return wxsOK;
}

int mtg_t_cliApp::OnExit()
{
    mtg_final(mtg);
    delete m_checker;

    //traceclose();
    return 0;
}
