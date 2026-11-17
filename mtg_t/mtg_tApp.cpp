/***************************************************************
 * Name:      mtg_tApp.cpp
 * Purpose:   Code for Application Class
 * Author:    dengdeyan (dengdeyan@medosurvey.com)
 * Created:   2011-03-21
 * Copyright: dengdeyan (http://www.medosurvey.com)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "mtg_tApp.h"
#include "libele.h"
#include "wx/stdpaths.h"

//(*AppHeaders
#include "mtg_tMain.h"
#include <wx/image.h>
//*)
#include <wx/config.h>
#include "LoginDialog.h"
//#define PI  3.1415926535897932384626433832795

mtg_cli *cli=0;
wxSocketClient* sock=0;

LogDialog* logDlg=0;
wxBrush btnBrush[4];
wxPen btnPen[3];
wxColor btnTextColor[2];
wxLocale intl;

IMPLEMENT_APP(mtg_tApp);

BEGIN_EVENT_TABLE(mtg_tApp,wxApp)
    //(*EventTable(mtg_tFrame)
    //EVT_SOCKET(mtg_tApp::OnSocketEvent)
    //*)
END_EVENT_TABLE()

bool mtg_tApp::OnInit()
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

    const wxString name1 = wxString::Format(wxT("mtg_t_svr-%s"), wxGetUserId().c_str());
    wxSingleInstanceChecker checker;
    checker.Create(name1);
    if ( checker.IsAnotherRunning() )
    {
        blocal = true;
    }

    sock = new wxSocketClient();

    ///用户登录
    wxIPV4address addr;
    wxString HostIP ;
    if(blocal)
    {
        addr.LocalHost();
        HostIP = addr.IPAddress();
    }
    else
    {
        HostIP = _("192.168.0.110");
        addr.Hostname(HostIP);
    }

    addr.Service(3000);
    sock->Connect(addr, false);
    sock->WaitOnConnect(10);

    if(!sock->IsConnected())
    {
        wxMessageBox(_("连接服务端失败！"),_("错误"),wxOK|wxICON_ERROR);
        return 0;
    }

    sock->GetLocal(addr);

    if(addr.IPAddress().Cmp(HostIP))
    {
        LoginDialog dlg(NULL);
        if(dlg.ShowModal()==wxID_OK)
        {
            char uid[64],psw[64];
            strcpy(uid,dlg.TextUid->GetValue().mb_str(wxConvUTF8));
            strcpy(psw,dlg.TextPsw->GetValue().mb_str(wxConvUTF8));
            sprintf(word,"%%R1Q,0:%s,%s\n",uid,psw);
            sock->Write(word,strlen(word));
            for(int i=0; i<5; i++)
            {
                Sleep(1000);
                sock->Read(word,260);
                //wxMessageBox(wxString(word,wxConvUTF8));
                if(strcmp(word,"%R1P,0:1\n")==0)
                {
                    login=true;
                    break;
                }
                else if(strcmp(word,"%R1P,0:0\n")==0)
                {
                    login=false;
                    break;
                }
            }
            if(!login)
            {
                wxMessageBox(_("登录失败！"),_("错误"),wxOK|wxICON_ERROR);
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        strcpy(word,"%R1Q,0:localhost,123\n");
        sock->Write(word,strlen(word));
    }

    btnBrush[0]=wxBrush(wxColor(255,255,255));
    btnBrush[1]=wxBrush(wxColor(80,196,23));
    btnBrush[2]=wxBrush(wxColor(111,182,76));
    btnBrush[3]=wxBrush(wxColor(80,196,23));

    btnPen[0]=wxPen(wxColor(178,178,178));
    btnPen[1]=wxPen(wxColor(7,145,79));
    btnPen[2]=wxPen(wxColor(21,131,221));
    btnTextColor[0]=wxColor(0,0,0);
    btnTextColor[1]=wxColor(255,255,255);

    wxConfig *config = new wxConfig(_("MTG-T"));
    long lang=0;
    config->Read(_("Language"),&lang,0);
    delete config;

    switch(lang)
    {
    case 0:
        intl.Init(wxLANGUAGE_CHINESE_SIMPLIFIED);
        break;
    case 1:
        intl.Init(wxLANGUAGE_CHINESE_TRADITIONAL);
        break;
    case 2:
        intl.Init(wxLANGUAGE_ENGLISH);
        break;
    default:
        break;
    }

    wxLocale::AddCatalogLookupPathPrefix(wxT("il8n"));
    // Initialize the catalogs we'll be using
    intl.AddCatalog(wxT("internat"));

    cli=(mtg_cli*)malloc(sizeof(mtg_cli));
    memset(cli,0,sizeof(mtg_cli));        ///将与mtg_t相关的所有变量初始化为0
    cli_init(cli);
    if(blocal)
    {
        cli->imode=1;
        cli->ilocal=1;
    }


    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	mtg_tFrame* Frame = new mtg_tFrame(0);
    	Frame->SetMinSize(wxSize(800,600));
    	Frame->SetSize(1024,728);
    	Frame->CenterOnScreen();
        sock->SetEventHandler(*Frame,-1);
        sock->SetNotify(wxSOCKET_CONNECTION_FLAG |
                          wxSOCKET_INPUT_FLAG |
                          wxSOCKET_LOST_FLAG);
        sock->Notify(true);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)

    return wxsOK;
}

int mtg_tApp::OnExit()
{
    cli_final();
    delete m_checker;
    return 0;
}
