/***************************************************************
 * Name:      mtg_t_cliFrame.cpp
 * Purpose:   Code for Application Frame
 * Author:    dengdeyan (dengdeyan@medosurvey.com)
 * Created:   2011-03-21
 * Copyright: dengdeyan (http://www.medosurvey.com)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "mtg_t_cliMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(mtg_t_cliFrame)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include <wx/dcclient.h>
#include "DtaDlg.h"
#include "mtg_t_cliApp.h"
#include <wx/stdpaths.h>
#include "ConfigDlg.h"
#include "SegmentDlg.h"
#include "MyCheckDlg.h"
#include "MapViewDlg.h"
#include "MyQueryDlg.h"
#include "MySetupDlg.h"
#include "DutyDlg.h"
#include "ConfirmDlg.h"
#include "ModifySegDialog.h"
//#include "MySetupDialog.h"
#include "dmsrad.h"
#include <wx/imaglist.h>
#include "LogDialog.h"
#include <wx/dcbuffer.h>
#include "libele.h"
#include "PasswordDialog.h"
#include <wx/config.h>
#include "gtime.h"

#define PI  3.1415926535897932384626433832795

//(*IdInit(mtg_t_cliFrame)
const long mtg_t_cliFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(mtg_t_cliFrame,wxFrame)
    //(*EventTable(mtg_t_cliFrame)
   EVT_CLOSE(mtg_t_cliFrame::OnClose)
    //*)
    EVT_SOCKET(-1,mtg_t_cliFrame::OnSocketEvent)
END_EVENT_TABLE()

mtg_t_cliFrame::mtg_t_cliFrame(wxWindow* parent,wxWindowID id)
{
    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);
    bmpLogo.LoadFile(path+_("/plugins/logo.png"),wxBITMAP_TYPE_PNG);
    bmpTps1.LoadFile(path+_("/plugins/tps1.png"),wxBITMAP_TYPE_PNG);
    bmpTps2.LoadFile(path+_("/plugins/tps2.png"),wxBITMAP_TYPE_PNG);
    bmpPrism.LoadFile(path+_("/plugins/prism.png"),wxBITMAP_TYPE_PNG);
    //bmpLogo.LoadFile(path+_("/plugins/logo.png"),wxBITMAP_TYPE_PNG);
    bmpPartner.LoadFile(path+_("/plugins/partner.png"),wxBITMAP_TYPE_PNG);
    wxString str=path+_("/plugins/vertion.ini");
    char ipath[260];
    strcpy(ipath,str.mb_str(wxConvLocal));
    FILE* fp=fopen(ipath,"r");
    if(fp)
    {
        char ibuf[260];
        char vpth[260];
        fgets(ibuf,260,fp);
        if(sscanf(ibuf,"%s",vpth)==1)
        {
            str = wxString(vpth,wxConvUTF8);
            str.Trim();
            str.ToLong(&iver);
        }
        fclose(fp);
    }

    if(iver==1) bmpLogo.LoadFile(path+_("/plugins/Partner1.jpg"),wxBITMAP_TYPE_JPEG);
    else bmpLogo.LoadFile(path+_("/plugins/logo.png"),wxBITMAP_TYPE_PNG);
    int w,h;
    imgTrace.Create(1280,960);
    //(*Initialize(mtg_t_cliFrame)
    Create(parent, id, _("MTG-T-KY矿用掘进导向系统"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(1024,768));
    this->GetSize(&w,&h);
    //wxMessageBox(wxString::Format(_("%d,%d"),w,h));

    panelUI = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    //panelTitle = new MDTitle(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelButton = new wxPanel(panelUI, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //panelButtonList = new MDButtonList(panelUI, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //panelButtonList->Show(false);
    panelGraph = new wxPanel(panelUI, wxID_ANY, wxPoint(200,545), wxSize(634,100), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMetric = new wxPanel(panelUI, wxID_ANY, wxPoint(0,395), wxSize(200,150), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    metroFig1 = new wxPanel(panelMetric, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    metroFig2 = new wxPanel(panelMetric, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    metroFig3 = new wxPanel(panelMetric, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBar = new wxPanel(panelUI, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelLogo = new wxPanel(panelUI, wxID_ANY, wxPoint(834,0), wxSize(190,125), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMode = new wxPanel(panelMetric, wxID_ANY, wxPoint(200,0), wxSize(634,125), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStatus = new wxPanel(panelUI, wxID_ANY, wxPoint(0,395), wxSize(200,150), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelDuty = new wxPanel(panelGraph, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTool = new wxPanel(panelMetric, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));

    listlog = new wxListView(panelUI, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    metroFig1->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    metroFig2->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    metroFig3->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMode->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelLogo->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelGraph->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelDuty->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelStatus->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMetric->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBar->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTool->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMode->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintMode,0,this);
    panelLogo->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintLogo,0,this);
    panelGraph->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintGraph,0,this);
    panelStatus->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintStatus,0,this);

    panelMetric->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintMetric,0,this);
    metroFig1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintMetroFig1,0,this);
    metroFig2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintMetroFig2,0,this);
    metroFig3->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintMetroFig3,0,this);
    metroFig3->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_t_cliFrame::OnMotionSegment,0,this);
    metroFig3->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_t_cliFrame::OnLeaveSegment,0,this);
    metroFig3->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_cliFrame::SetSegment,0,this);
    panelBar->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintBar,0,this);

    panelButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintButton,0,this);
    panelButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_t_cliFrame::OnMotionButton,0,this);
    panelButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_t_cliFrame::OnLeaveButton,0,this);
    panelButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_cliFrame::OnClickButton,0,this);

    panelDuty->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintDuty,0,this);
    panelDuty->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_t_cliFrame::OnMotionDuty,0,this);
    panelDuty->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_t_cliFrame::OnLeaveDuty,0,this);
    panelDuty->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_cliFrame::OnClickDuty,0,this);

    panelTool->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_cliFrame::OnPaintTool,0,this);
    panelTool->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_t_cliFrame::OnMotionTool,0,this);
    panelTool->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_t_cliFrame::OnLeaveTool,0,this);
    panelTool->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_cliFrame::OnClickTool,0,this);

    listlog->Connect(wxEVT_COMMAND_LEFT_DCLICK,(wxObjectEventFunction)&mtg_t_cliFrame::OnLogDoubleClicked,0,this);

    //panelButtonList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_cliFrame::OnBtnClick,0,this);
    this->Connect(wxEVT_SIZE,(wxObjectEventFunction)&mtg_t_cliFrame::OnSize,0,this);
    //*)
    //Center();

    listlog->InsertColumn(0,_("类型"),wxLIST_FORMAT_RIGHT,45);
    listlog->InsertColumn(1,_("时间"),wxLIST_FORMAT_LEFT,150);
    listlog->InsertColumn(2,_("信息"),wxLIST_FORMAT_LEFT,480);

    wxImageList* imglist=new wxImageList(16,16);
    imglist->Add(wxIcon(path+_("/plugins/Info.ico"),wxBITMAP_TYPE_ICO));
    imglist->Add(wxBitmap(path+_("/plugins/Error.png"),wxBITMAP_TYPE_PNG));
    listlog->SetImageList(imglist,wxIMAGE_LIST_SMALL);

    //mtg_client_connect(mtg);
    Connect(wxEVT_TIMER,(wxObjectEventFunction)&mtg_t_cliFrame::OnTimer);
    timerStat.SetOwner(this);
    timerStat.Start(100,false);

    ///20180622whq注释下面的语句，因为服务器和客户端显示的切口姿态不一致
    /*if(mtg->tbm.type>0)
    {
        mtg_cal_tbm(mtg);
        mtg->m1=mtg->m;
    }*/
    //panelTitle->Name = _("MTG-T盾构导向系统");
    //panelTitle->m_maximize_box=1;
    //panelTitle->m_minimize_box=1;

    //panelButtonList->pos_left=1;
    //panelButtonList->btn_label_align=2;
    //panelButtonList->AddButton(_("开始测量"));
    //panelButtonList->AddButton(_("停止测量"));
    //panelButtonList->AddButton(_("管片选型"));
    //panelButtonList->AddButton(_("向前移站"));
    //panelButtonList->AddButton(_("系统检查"));
    //panelButtonList->AddButton(_("数据查询"));
    //panelButtonList->AddButton(_("隧道中线"));
    //panelButtonList->AddButton(_("地质地物"));
    //panelButtonList->AddButton(_("管环监测"));
    //panelButtonList->AddButton(_("参数设置"));
    //panelButtonList->AddButton(_("退出系统"));
    int i=0;
    btn_label[i++]=_("开始测量");
    btn_label[i++]=_("停止测量");
    btn_label[i++]=_("管片选型");
    btn_label[i++]=_("向前移站");
    btn_label[i++]=_("系统检查");
    btn_label[i++]=_("数据查询");
    btn_label[i++]=_("隧道中线");
    btn_label[i++]=_("地质地物");
    //btn_label[i++]=_("管环监测");
    //btn_label[i++]=_("盾尾间隙");
    btn_label[i++]=_("参数设置");
    btn_label[i++]=_("退出系统");
    clicked=-1;
    ///关键区域提示
    Err=0;
    GetTips();
    map_ready=0;

    tpsDirection=2;
    drawAnimation=false;
    tpsStatus=0;       //0电子补偿器1电池电量

    nbuf=0;
    second=0;
    peek=0;
    #ifdef WIN32
    Maximize(true);
    //SetSize(1024,768);
    Center();
    //ShowFullScreen(true,wxFULLSCREEN_NOBORDER);
    SetIcon(wxICON(aaaa));
    #endif
    htrend2=vtrend2=0;
}

void mtg_t_cliFrame::GetTips()
{
    double len1,len2;
    nks=0;

    for(int i=0;i<mtg->nks;i++)
    {
        len1=mtg->m1.headc-mtg->keys[i].mile1;
        len2=mtg->m1.headc-mtg->keys[i].mile2;

        if(fabs(len1)<=mtg->prj.tip || fabs(len2)<=mtg->prj.tip);
        {
            keys[nks]=mtg->keys[i];
            nks++;
        }
        if(nks>=200) break;
    }
    tip=nks-1;
}

mtg_t_cliFrame::~mtg_t_cliFrame()
{
    //(*Destroy(mtg_t_cliFrame)
    //*)
    //panelButtonList->Disconnect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_cliFrame::OnBtnClick,0,this);
    if(mapDlg) mapDlg->Destroy();
    mapDlg=0;
    timerStat.Stop();
}

void mtg_t_cliFrame::OnSocketEvent(wxSocketEvent& event)
{
    //wxSocketBase *sock = event.GetSocket();
    static char word[4096];

    // Now we process the event
    switch(event.GetSocketEvent())
    {
    case wxSOCKET_INPUT:
    {
        // We disable input events, so that the test doesn't trigger
        // wxSocketEvent again.
        sock->SetNotify(wxSOCKET_LOST_FLAG);
        // Which test are we going to run?
        if(nbuf>=4095) nbuf=0;
        sock->Read(buffer+nbuf, 4095-nbuf);
        nbuf+=sock->LastCount();
        ///注意，这里需要将buffer加上结束符
        buffer[nbuf]=0;

        //fprintf(fp,"nbuf=%d\n",nbuf);
        ///解译
        while(nbuf>0)
        {
            bool brk=true;
            for(int i=0; i<nbuf; i++)
            {
                if(buffer[i]=='%')
                {
                    char* ptr=strchr((char*)buffer+i,'\n');
                    if(ptr)
                    {
                        int index=ptr-buffer+1;
                        memcpy(word,buffer+i,index-i);
                        word[index-i]=0;
                        //fprintf(fp,"%s",word);
                        DecodeCommand(word);
                        memmove(buffer,buffer+index,nbuf-index);
                        nbuf-=index;
                        ///注意，这里需要将buffer加上结束符
                        buffer[nbuf]=0;

                        brk=false;
                        //fflush(fp);
                    }
                    break;
                }
            }
            if(brk) break;
        }


        // Enable input events again.
        sock->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);
        break;
    }
    case wxSOCKET_LOST:
    {
        //20180116whq增加下面的cli->login==1的判断
        if(cli->login==1)
            wxMessageBox(_("服务端已退出！"),_("错误"),wxOK|wxICON_ERROR);
        //20180116whq解注释下面的一条语句
        //sock->Destroy();
        //sock=0;
        cli->login=0;
        //Destroy();
        break;
    }
    default:
        ;
    }
    //strcpy(cli.inccom,"COM2");
}

void mtg_t_cliFrame::OnClose(wxCloseEvent& event)
{
    //timerStat.Stop();
    //sleepms(50);
    //event.Skip();

    ConfirmDlg dlg(this);
    dlg.Center();
    if(dlg.ShowModal()==wxID_OK)
    {
        timerStat.Stop();

        sock->Destroy();

        sleepms(50);
        event.Skip();
    }
    else
    {
        event.Veto();
    }
}

void mtg_t_cliFrame::OnLogDoubleClicked(wxCommandEvent& event)
{
    LogDialog *dlg = new LogDialog(this);
    dlg->Center();
    dlg->Show(true);
}

void mtg_t_cliFrame::RunMeasurement()
{

    //mtg_start_cycle(mtg);
}

void mtg_t_cliFrame::EndMeasurement()
{
    mtg_stop(mtg);
    panelMode->Refresh();
    panelGraph->Refresh();
}

void mtg_t_cliFrame::CalRings()
{
    SegmentDlg *dlg = new SegmentDlg(this);
    dlg->Center();
    dlg->ShowModal();

    /*SegmentDlg dlg(this);
    dlg.Center();
    //mtg->m1.headc=415.0418;
    //mtg->m1.headc=536.0418;
    //mtg->ref_seg.seg_set=0;
    //mtg_cal_seg(mtg,320,1.2);
    dlg.ShowModal();*/
}

void mtg_t_cliFrame::MoveStation()
{
    if(cli->login == 1)
    {
        char word[1024]="\0";
        strcpy(word,"%R1Q,43:0\n");
        strcat(word,"%R1Q,46:0\n");
        strcat(word,"%R1Q,48:0\n");
        sock->Write(word,strlen(word));
    }

    PasswordDialog dlg(this);
    dlg.TextPassword->SetFocus();
    dlg.Center();

    if(dlg.ShowModal()==wxID_OK)
    {
        int i;
        for(i=0;i<mtg->nuser;i++)
        {
            if(dlg.TextPassword->GetValue().Cmp(wxString((const char*)mtg->user[i].password,wxConvLocal))==0)
            {
                break;
            }
        }

        if(i<mtg->nuser)
        {
            mtg->onLine = i;
            MySetupDlg dlg(this);
            dlg.Center();
            dlg.ShowModal();
            panelStatus->Refresh();
            panelMetric->Refresh();
            panelBar->Refresh();
            //setupDlg=0;
        }
    }
}

void mtg_t_cliFrame::Check()
{
    //checkDlg = new CheckUpDlg(this);
    MyCheckDlg dlg(this);
    dlg.Center();
    dlg.ShowModal();
    //ReviewDlg = new ReviewDlg(this);
    //ReviewDlg->Center();
    //ReviewDlg->ShowModal();
    //checkDlg->Destroy();
    //checkDlg=0;
}

void mtg_t_cliFrame::Query()
{
    MyQueryDlg *dlg = new MyQueryDlg(this);
    dlg->Center();
    dlg->Show(true);
}

void mtg_t_cliFrame::EditDTA()
{
    PasswordDialog dlg(this);

    dlg.TextPassword->SetFocus();
    dlg.Center();

    if(dlg.ShowModal()==wxID_OK)
    {
        if(dlg.iuser>=0)
        {
            mtg->onLine = dlg.iuser;
            DtaDlg dlg(this);
            dlg.Center();
            dlg.ShowModal();
        }
    }
}

void mtg_t_cliFrame::ViewMap()
{
    ///非模式对话框
    if(map_ready==0)
    {
        mapDlg=new MapViewDlg(this);
        mapDlg->Center();
        mapDlg->Show(true);
        map_ready=1;
        mapDlg->OnUse=1;
    }
    else
    {
        mapDlg->Show(true);
        mapDlg->OnUse=1;
    }
    //MapViewDlg *dlg = new MapViewDlg(this);
    //dlg->Center();
    //dlg->Show(true);
}

void mtg_t_cliFrame::Settings()
{
    if(cli->login == 1)
    {
        char word[1024]="\0";
        strcpy(word,"%R1Q,7:0\n");
        strcat(word,"%R1Q,25:0\n");
        sock->Write(word,strlen(word));
    }
    PasswordDialog dlg(this);

    dlg.TextPassword->SetFocus();
    dlg.Center();

    if(dlg.ShowModal()==wxID_OK)
    {
        int i;
        for(i=0;i<mtg->nuser;i++)
        {
            if(dlg.TextPassword->GetValue().Cmp(wxString((const char*)mtg->user[i].password,wxConvLocal))==0)
            {
                break;
            }
        }
        if(i<mtg->nuser)
        {
            //confDlg=new ConfigDlg(this);
            //confDlg->opLevel=i;
            //confDlg->Center();
            //confDlg->ShowModal();
            ConfigDlg dlg(this);
            dlg.Center();
            dlg.opLevel=i;
            dlg.ShowModal();
            panelStatus->Refresh();
            panelMetric->Refresh();
            panelBar->Refresh();
        }
    }
}

void mtg_t_cliFrame::OnSize(wxSizeEvent& event)
{
    int w,h;
    GetSize(&w,&h);
    int w1 = 832, w2 = 130;
    int h1 = 524, h2 = 68, h3 = 72, h4 = 28 , h5 = 32;
    double sx,sy;
    sx = w/1024.0;
    sy = h/728.0;

    GetClientSize(&w,&h);
    w1 = w-w2;
    h1 = h-h2-h3-h4;
    panelUI->SetSize(0,0,w,h);
    //trace(0,"head:%f,%f,%f\n",mtg->m1.head[0],mtg->m1.head[1],mtg->m1.head[2]);
    //panelTitle->SetSize(0,0,w,31);
    panelButton->SetSize(w1,0,w2,h1-h5);
    //panelButtonList->SetSize(w1,0,w2,h1-h5);
    //panelButtonList->btn_height=36*sy;

    int x1=20*sx;
    int y1=10;

    ///姿态数据显示
    panelMetric->SetSize(0,0,w1,h1);
    ///graph
    panelGraph->SetSize(0,h1,w1,h2);
    panelDuty->SetSize(w1/2+75,h2-26,w1/2-150,25);
    ///status
    panelStatus->SetSize(w1,h1-h5,w2,h2+h5);

    if(iver==1)
    {
        ///log
        listlog->SetSize(0,h1+h2,w1-230,h3);
        listlog->SetColumnWidth(2,w1-460);
        ///logo
        panelLogo->SetSize(w1-230,h1+h2,w2+230,h3);
    }
    else
    {
        ///log
        listlog->SetSize(0,h1+h2,w1,h3);
        listlog->SetColumnWidth(2,w1-230);
        ///logo
        panelLogo->SetSize(w1,h1+h2,w2,h3);
    }
    ///statusbar
    panelBar->SetSize(0,h1+h2+h3,w1+w2,h4);

    ///模式提醒
    panelMode->SetSize(0,h1-h5,w1,h5);
    panelTool->SetSize(0,h1-h5-h4-1,w1,h4);

    int fx1,fy1,fw1,fh1;
    //double fsy=h/768.0;
    GetSize(&w,&h);
    sx = w/1024.0;
	sy = h/768.0;
    fw1 = (w1*3/5)>(h1-40*sy)?(h1-40*sy)*19/40:(w1*3/5)*19/40;
    fw1 = fw1*9/10;
    fh1=fw1;
    fx1 = w1*2/5-fw1;
    fy1 = h1/2-23-fh1;
    fw1=fw1*2;
    fh1=fw1;
    metroFig1->SetSize(fx1,fy1,fw1,fh1);

    int fx2,fy2,fw2,fh2;
    fx2 = fx1+fw1+35*sx;
    fy2 = fy1;
    fw2 = w1-fx2+1;
    fh2 = fh1;
    metroFig2->SetSize(fx2,fy2,fw2,fh2);

    fx2 = -1;
    fy2 = fy1;
    fw2 = fx1-35*sx;
    fh2 = fh1;
    metroFig3->SetSize(fx2,fy2,fw2,fh2);

    panelMetric->Refresh();
    //panelMode->Refresh();
    panelLogo->Refresh();
    panelGraph->Refresh();
    panelStatus->Refresh();
    panelBar->Refresh();
    panelButton->Refresh();
}

void mtg_t_cliFrame::PaintBattery(wxMemoryDC* memDC, wxRect rect)
{
    int w,h;
    GetSize(&w,&h);
    w = rect.width;
    h = rect.height;
    int x = rect.x;
    int y = rect.y;
    ///background

    ///画电池电量
    memDC->SetPen(wxPen(wxColor(58,68,88)));
    int y1=y+h/4;
    int w1=w*6/9;
    int h1=h*1/2;
    int x1=x+w/2-w1/2-2;


    int w2=w1/9;
    int h2=h1/2;
    int x2=x1+w1;
    int y2=y1+h1/2-h2/2;

    int x3=x+x2-w2/2;
    int y3=y2+h2/2;

    memDC->SetPen(wxPen(wxColor(58,68,88)));
    memDC->SetBrush(wxBrush(wxColor(145,158,167)));
    memDC->DrawRectangle(x1,y1,w1,h1);
    memDC->DrawLine(x1+1,y1+2,x1+1,y1+h1-2);
    //memDC->DrawRectangle(x2,y2,w2,h2+1);
    memDC->DrawLine(x2+1,y2,x2+1,y2+h2);
    memDC->DrawLine(x2+2,y2+1,x2+2,y2+h2-1);
    memDC->DrawLine(x2+3,y2+2,x2+3,y2+h2-2);
    memDC->DrawLine(x2+4,y2+3,x2+4,y2+h2-3);
    //memDC->DrawLine(x2+3,y2+1,x2+w2-3,y2+1);
    //memDC->DrawLine(x2+2,y2+2,x2+w2-2,y2+2);
    //memDC->DrawLine(x2+1,y2+3,x2+w2-1,y2+3);
    //memDC->DrawLine(x2,y2+4,x2+w2,y2+4);

    int capacity=mtg->tps.power;
    capacity=100;
    if(capacity>20)
    {
        memDC->SetPen(wxPen(wxColor(148,255,148)));
        //memDC->SetTextForeground(wxColor(209,209,209));
    }
    else
    {
        memDC->SetPen(wxPen(wxColor(255,0,0)));
        //memDC->SetTextForeground(wxColor(209,209,209));
    }

    for(int hi=x1+2;hi<x1+2+(w1-5)*capacity/100;hi++)
    {
        memDC->DrawLine(hi,y1+2,hi,y1+h1-2);
        //memDC->DrawLine(x1+2,hi,x1+w1-2,hi);
    }
    memDC->DrawLine(x1+2,y1+2,x1+2,y1+h1-2);
    //memDC->DrawLine(x1+2,y1+h1-3,x1+w1-2,y1+h1-3);
    //memDC->SetPen(*wxBLACK_PEN);
    //memDC->DrawRectangle(x1+3,y1+3+h1-6-(h1-6)*capacity/100,(w1-6),(h1-6)*capacity/100);
}

void mtg_t_cliFrame::OnPaintMode(wxPaintEvent& event)
{
    wxPaintDC dc(panelMode);
    int w,h;
    GetSize(&w,&h);

    double sx=w/1024.0;
    double sy=h/768.0;

    if(sx>sy)
    {
        sx = sy;
    }
    panelMode->GetClientSize(&w,&h);
    int x1;
    metroFig2->GetSize(&x1,0);
    x1=w-x1;
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);

        int c1 = 204;
        int c2 = 204;
        int c3 = 204;

        memDC.SetPen(wxPen(wxColor(168,168,168)));
        memDC.SetBrush(wxBrush(wxColor(208,208,208)));
        memDC.DrawRectangle(0,0,w,h);

        int w1 = (w-x1)/3;
        int h1 = h-2;
        int y1 = 1;
        int x2 = x1+w1;
        int y2 = h-2;
        //memDC.SetBrush(wxBrush(wxColor(204,233,177)));
        memDC.SetTextForeground(wxColor(71,71,71));
        wxString valstr = wxEmptyString;
        //mtg->m1.t1=1444987713;
        if(mtg->m1.t1>0)
        {
            time_t now;
            time(&now);
            time_t timing;
            timing=now-mtg->m1.t1;
            if(timing>mtg->iset.talw)
            {
                //memDC.SetTextForeground(wxColor(247,247,247));
                c1 = 255;
                c2 = 255;
                c3 = 30;
                for(int i=y1;i<=y2;i++)
                {
                    if((i-y1)%2==0)
                    {
                        c1-=3;
                        c2-=3;
                        c3+=4;
                    }
                    memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                    memDC.DrawLine(x1,i,x2,i);
                }
            }

            if(timing>3600)
            {
                valstr = _("---");
            }
            else
            {
                int om = timing/60;
                int os = timing-om*60;
                if(os<10)
                {
                    valstr=wxString::Format(wxString::Format(_("%d"),om))+_(":0")+wxString::Format(wxString::Format(_("%d"),os));
                }
                else
                {
                    valstr=wxString::Format(wxString::Format(_("%d"),om))+_(":")+wxString::Format(wxString::Format(_("%d"),os));
                }
            }
            memDC.SetFont(eng);
            memDC.DrawLabel(valstr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            c1 = 255;
            c2 = 255;
            c3 = 30;
            for(int i=y1;i<=y2;i++)
            {
                if((i-y1)%2==0)
                {
                    c1-=3;
                    c2-=3;
                    c3+=4;
                }
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
            }

            valstr = _("---");
            memDC.DrawLabel(valstr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
        }
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1 = x1+w1;
        y1 = 1;
        x2 = x1+w1;
        y2 = h-2;

        memDC.SetTextForeground(wxColor(71,71,71));
        if(mtg->itbm == 0)
        {
            c1 = 255;
            c2 = 255;
            c3 = 30;
            for(int i=y1;i<=y2;i++)
            {
                if((i-y1)%2==0)
                {
                    c1-=3;
                    c2-=3;
                    c3+=4;
                }
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
            }
        }
        memDC.DrawLabel(_("PLC"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1 = x1+w1;
        y1 = 1;
        x2 = x1+w1;
        y2 = h-2;
        memDC.SetFont(chs);
        if(cli->login == 0)
        {
            c1 = 255;
            c2 = 255;
            c3 = 30;
            for(int i=y1;i<=y2;i++)
            {
                if((i-y1)%2==0)
                {
                    c1-=3;
                    c2-=3;
                    c3+=4;
                }
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
            }

        }
        memDC.DrawLabel(_("远程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLabel(_("失败"),wxRect(x1,y1,w1/2,h1),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1 = 1;
        y1 = 1;
        metroFig2->GetSize(&x2,0);
        x2=w-x2;
        y2 = h-2;
        double l1,l2,len;
        double vi;

        h_element* he;
        v_element* ve;

        if(mtg->m1.t1>0) l1=l1=mtg->m1.mile1;
        else l1=mtg->prj.mile1;

        if(Err > 0)
        {
            memDC.SetTextForeground(wxColor(239,249,255));
            c1 = 255;
            c2 = 0;
            c3 = 0;
            for(int i=y1;i<=y2;i++)
            {
                if((i-y1)%2==0)
                {
                    c1-=2;
                    c2+=6;
                    c3+=4;
                }
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
            }
            memDC.SetPen(wxPen(wxColor(203,203,203)));
            memDC.DrawLine(x1,1,x2,1);
            memDC.DrawLine(x2-1,1,x2-1,y2+1);
            //memDC.SetPen(wxPen(wxColor(168,168,168)));
            //memDC.DrawLine(x1,y2,x2,y2);
            switch(Err)
            {
                case ID_ERR_NO_DTA:
                {
                    valstr=_("系统缺少中线数据，请检查！");
                    break;
                }
                case ID_ERR_NO_ORI:
                {
                    valstr=_("TBM位置未初始化，请检查！");
                    break;
                }
                case ID_ERR_NO_STN:
                {
                    valstr=_("系统未进行设站定向，请检查！");
                    break;
                }
                case ID_ERR_NO_PSM:
                {
                    valstr=_("激光靶位置未初始化，请检查！");
                    break;
                }
                case ID_ERR_NO_TARSET:
                {
                    valstr=_("激光靶配置文件缺失，请检查！");
                    break;
                }
                case ID_ERR_NO_TPS:
                {
                    valstr=_("全站仪未连接，请检查！");
                    break;
                }
                case ID_ERR_NO_TAR:
                {
                    valstr=_("激光靶未连接，请检查！");
                    break;
                }
                default:
                    break;
            }

            memDC.DrawLabel(valstr,wxRect(x1+15,y1,0,y2-y1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(tip==nks)
        {
            int nh = road_number_horizon(&mtg->r);
            if(nh>2)
            {
                tipstr[0]=wxEmptyString;
                tipstr[1]=wxEmptyString;
                valstr=wxEmptyString;
                for(int i=1;i<nh-1;i++)
                {
                    he=road_horizon(&mtg->r,i);

                    if(l1>=he->l1 && l1<=he->l1+he->length)
                    //if((l3-l1)/(l3-l2+0.000001)<0 || (l4-l1)/(l4-l2+0.000001)<0)
                    {
                        if(he->type==ROAD_TYPE_LINE)
                        {
                            valstr=_("当前平曲线:类型(直线),剩余(");
                        }
                        else if(he->type==ROAD_TYPE_ARC)
                        {
                            valstr=valstr+_("当前平曲线:类型(圆曲线),半径(");
                            valstr=valstr+wxString::Format(_("%.2f"),he->radius);
                            valstr=valstr+_("米),转向(");
                            if(he->pz==ROAD_LEFT)
                            {
                                if(mtg->prj.a2z==1) valstr=valstr+_("左转弯),剩余(");
                                else valstr=valstr+_("右转弯),剩余(");
                            }
                            else
                            {
                                if(mtg->prj.a2z==1) valstr=valstr+_("右转弯),剩余(");
                                else valstr=valstr+_("左转弯),剩余(");
                            }
                        }
                        else if(he->type==ROAD_TYPE_SPIRAL)
                        {
                            valstr=valstr+_("当前平曲线:类型(缓和曲线),长度(");
                            valstr=valstr+wxString::Format(_("%.2f"),he->length);
                            valstr=valstr+_("米),转向(");
                            if(he->pz==ROAD_LEFT)
                            {
                                if(mtg->prj.a2z==1) valstr=valstr+_("左转弯),剩余(");
                                else valstr=valstr+_("右转弯),剩余(");
                            }
                            else
                            {
                                if(mtg->prj.a2z==1) valstr=valstr+_("右转弯),剩余(");
                                else valstr=valstr+_("左转弯),剩余(");
                            }
                        }

                        if(mtg->prj.a2z==1) len=he->l1+he->length-l1;
                        else len=l1-he->l1;

                        valstr=valstr+wxString::Format(_("%.2f米)"),len);
                        tipstr[0]=valstr;

                        if(i<nh-1)
                        {
                            if(mtg->prj.a2z==-1)
                            {
                                if(i==1) break;
                                i=i-1;
                            }
                            else
                            {
                                i=i+1;
                            }

                            he=road_horizon(&mtg->r,i);
                            if(he->type==ROAD_TYPE_LINE)
                            {
                                valstr=_("下段平曲线:类型(直线),前方(");
                            }
                            else if(he->type==ROAD_TYPE_ARC)
                            {
                                valstr=+_("下段平曲线:类型(圆曲线),半径(");
                                valstr=valstr+wxString::Format(_("%.2f"),he->radius);
                                valstr=valstr+_("米),转向(");
                                if(he->pz==ROAD_LEFT)
                                {
                                    if(mtg->prj.a2z==1) valstr=valstr+_("左转弯),前方(");
                                    else valstr=valstr+_("右转弯),前方(");
                                }
                                else
                                {
                                    if(mtg->prj.a2z==1) valstr=valstr+_("右转弯),前方(");
                                    else valstr=valstr+_("左转弯),前方(");
                                }
                            }
                            else if(he->type==ROAD_TYPE_SPIRAL)
                            {
                                valstr=_("下段平曲线:类型(缓和曲线),长度(");
                                valstr=valstr+wxString::Format(_("%.2f"),he->length);
                                valstr=valstr+_("米),转向(");
                                if(he->pz==ROAD_LEFT)
                                {
                                    if(mtg->prj.a2z==1) valstr=valstr+_("左转弯),前方(");
                                    else valstr=valstr+_("右转弯),前方(");
                                }
                                else
                                {
                                    if(mtg->prj.a2z==1) valstr=valstr+_("右转弯),前方(");
                                    else valstr=valstr+_("左转弯),前方(");
                                }
                            }
                            if(mtg->prj.a2z==1) len=he->l1-l1;
                            else len=l1-(he->l1+he->length);

                            valstr=valstr+wxString::Format(_("%.2f米)"),len);
                            tipstr[1]=valstr;
                        }
                        break;
                    }
                }
                memDC.DrawLabel(tipstr[0],wxRect(x1+15,y1,0,y2-y1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else if(tip==nks+1)
        {
            memDC.DrawLabel(tipstr[1],wxRect(x1+15,y1,0,y2-y1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(tip==nks+2)
        {
            int nv = road_number_vertical(&mtg->r);
            if(nv>2)
            {
                tipstr[2]=wxEmptyString;
                tipstr[3]=wxEmptyString;
                for(int i=1;i<nv-1;i++)
                {
                    ve=road_vertical(&mtg->r,i);
                    if(l1>=ve->l1 && l1<=ve->l1+ve->length)
                    {
                        if(ve->type==ROAD_TYPE_LINE)
                        {
                            valstr=_("当前竖曲线:类型(直线),坡度(");
                            vi=ve->angle1+ve->deta;
                            vi=tan(vi)*1000.0*mtg->prj.a2z;
                            valstr=valstr+wxString::Format(_("%.3f‰),剩余("),vi);
                        }
                        else if(ve->type==ROAD_TYPE_ARC)
                        {
                            valstr=_("当前竖曲线:类型(圆曲线),半径(");
                            valstr=valstr+wxString::Format(_("%.2f"),ve->radius);
                            valstr=valstr+_("米),转向(");
                            if(ve->pz==ROAD_UP) valstr=valstr+_("向上),剩余(");
                            else valstr=valstr+_("向下),剩余(");

                        }
                        if(mtg->prj.a2z==1) len=ve->l1+ve->length-l1;
                        else len=l1-ve->l1;

                        valstr=valstr+wxString::Format(_("%.2f米)"),len);
                        tipstr[2]=valstr;

                        if(i<nv-1)
                        {
                            if(mtg->prj.a2z==-1)
                            {
                                if(i==1) break;
                                i=i-1;
                            }
                            else
                            {
                                i=i+1;
                            }
                            ve=road_vertical(&mtg->r,i);
                            if(ve->type==ROAD_TYPE_LINE)
                            {
                                valstr=_("下段竖曲线:类型(直线),坡度(");
                                vi=ve->angle1+ve->deta;
                                vi=tan(vi)*1000.0*mtg->prj.a2z;
                                valstr=valstr+wxString::Format(_("%.3f‰),剩余("),vi);
                            }
                            else if(ve->type==ROAD_TYPE_ARC)
                            {
                                valstr=_("下段竖曲线:类型(圆曲线),半径(");
                                valstr=valstr+wxString::Format(_("%.2f"),ve->radius);
                                valstr=valstr+_("米),转向(");
                                if(ve->pz==ROAD_UP) valstr=valstr+_("向上),前方(");
                                else valstr=valstr+_("向下),前方(");

                            }
                            if(mtg->prj.a2z==1) len=ve->l1-l1;
                            else len=l1-(ve->l1+ve->length);

                            valstr=valstr+wxString::Format(_("%.2f米)"),len);
                            tipstr[3]=valstr;
                        }
                        break;
                    }
                }
                memDC.DrawLabel(tipstr[2],wxRect(x1+15,y1,0,y2-y1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else if(tip==nks+3)
        {
            memDC.DrawLabel(tipstr[3],wxRect(x1+15,y1,0,y2-y1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(nks>0)
        {
            valstr=wxString(keys[tip].name,wxConvUTF8)+_(":");

            if(mtg->prj.a2z==1)
            {
                if(l1>=keys[tip].mile2)
                {
                    len=l1-keys[tip].mile2;
                    valstr=valstr+_("后方(")+wxString::Format(_("%.2f米)"),len);
                }
                else if(l1<=keys[tip].mile1)
                {
                    len=keys[tip].mile1-l1;
                    valstr=valstr+_("前方(")+wxString::Format(_("%.2f米)"),len);
                }
            }
            else
            {
                if(l1<=keys[tip].mile1)
                {
                    len=keys[tip].mile1-l1;
                    valstr=valstr+_("后方(")+wxString::Format(_("%.2f米)"),len);
                }
                else if(l1>=keys[tip].mile2)
                {
                    len=l1-keys[tip].mile2;
                    valstr=valstr+_("前方(")+wxString::Format(_("%.2f米)"),len);
                }
            }
            memDC.DrawLabel(valstr,wxRect(x1+15,y1,0,y2-y1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        //memDC.SetPen(wxPen(wxColor(104,104,104)));
        //memDC.DrawLine(x1,y1,x1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_cliFrame::OnPaintLogo(wxPaintEvent& event)
{
    wxPaintDC dc(panelLogo);
    int w,h;
    panelLogo->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        if(iver==1)
        {
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.DrawRectangle(0,-1,w+2,h+2);

            if(bmpLogo.IsOk())
            {
                int w1,h1;
                w1=bmpLogo.GetWidth();
                h1=bmpLogo.GetHeight();
                double s=w*0.96/w1;
                memDC.SetUserScale(s,s);
                memDC.DrawBitmap(bmpLogo,w/2/s-w1/2,h/2/s-h1/2);
                memDC.SetUserScale(1.0,1.0);
            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.SetBrush(wxBrush(wxColor(236,241,254)));
            memDC.DrawRectangle(0,-1,w+2,h+2);

            if(bmpLogo.IsOk())
            {
                int w1,h1;
                w1=bmpLogo.GetWidth();
                h1=bmpLogo.GetHeight();
                double s=w*0.8/w1;
                memDC.SetUserScale(s,s);
                memDC.DrawBitmap(bmpLogo,w*0.6/s-w1/2,h/2/s-h1/2);
                memDC.SetUserScale(1.0,1.0);
            }
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

static double castdiff(int diff)
{
    static int diff0[]={10,30,60,90};
    static double scale0[]={0.1,0.3,0.6,0.9};
    int sign=1;
    if(diff<0) sign=-1;
    diff=abs(diff);
    //wxMessageBox(wxString::Format(_("%d"),diff));
    int i=0;
    for(i=1;i<5;i++)
    {
        if(diff<=diff0[i])
        {
            return sign*(scale0[i-1]+(scale0[i]-scale0[i-1])*(diff-diff0[i-1])/(diff0[i]-diff0[i-1]));
        }
    }
    return sign*0.9;
}

void mtg_t_cliFrame::PaintHorizon(wxMemoryDC* memDC, wxRect rect,double ds)
{
    int x,y;
	x = rect.x;
	y = rect.y;
    int w,h;
    GetSize(&w,&h);
    double sx,sy;
    sx = w/1024.0;
    sy = h/768.0;
    w = rect.width;
	h = rect.height;
    FILE* fp = fopen("D:\\midu\\painthorizon.log","w");
    if(fp)
    {
        fprintf(fp,"maxdev:%.4f\n",ds);fflush(fp);
    }
	ds = h/6/ds;
	if(fp)
    {
        fprintf(fp,"ds:%.4f\n",ds);fflush(fp);
    }

	int nh = road_number_horizon(&mtg->r);

    memDC->SetPen(wxPen(wxColor(112,112,112)));
    memDC->SetBrush(wxBrush(wxColor(248,248,248)));
    memDC->DrawRectangle(x,y,w,h-1);
    double d1,d2,pds;
    double  length;
    if(mtg->m1.t1>0)    ///有测量数据
    {
        d1 = fabs(midc-tailc);     ///后筒体长度
        d2 = fabs(headc-midc);      ///前筒体长度
        pds = d1/(d1+d2);
    }
    else     //没有测量数据
    {
//        d1=mtg->tbm.L[3];     ///推进油缸至切口的距离
//        d2=mtg->tbm.L[0]-mtg->tbm.L[3];     ///前盾长-推进油缸至切口的距离
        ///20200729ws 参考whq的修改
        d1=mtg->tbm.L[2];
        d2=mtg->tbm.L[0];
        pds = d1/(d1+d2);
    }
    length=d1+d2;
    if(fp)
    {
        fprintf(fp,"d1:%.4f,%.4f,%.4f\n",d1,d2,pds);
        fflush(fp);
    }
    ///??????
    int w1=w*1/4;
    int h1=y+h/2;
    int w2=w*3/4;
    int h2=y+h/2;
    int w3=w1+w/2*pds;
    int h3=y+h/2;
//    double len=length*2;
//    len=50;
//    double scale=len/length;
    double scale=1.0;     ///20200729ws 参考whq的修改
    double len=length*2;
    ///double len=50.0;        ///20200729ws modify

    double l1,l2;    ///掘进方向反方向距离切口25米处的里程，掘进方向前进方向距离切口25米处的里程
    if(mtg->m1.t1<=0)   //没有测量数据
    {
        if(mtg->prj.a2z==1)
        {
            l1 = mtg->prj.mile1-len/2.0;
            l2 = l1+len;
        }
        else
        {
            l1 = mtg->prj.mile2+len/2.0;
            l2 = l1-len;
        }
    }
    else     ///有测量数据
    {
        if(mtg->prj.a2z==1)
        {
            l1 = mtg->m1.headc-len/2.0;
            l2 = l1+len;
        }
        else
        {
            l1 = mtg->m1.headc+len/2.0;
            l2 = l1-len;
        }
    }
    if(fp)
    {
        fprintf(fp,"l1:%.4f,l2:%.4f\n",l1,l2);
        fflush(fp);
    }

    double x1=0.0,y1=0.0,x2=0.0,y2=0.0,x3=0.0,y3=0.0;
    double alf=0.0,alf1=0.0,alf2=0.0;

    if(nh>2)
    {
        road_l2xy(&mtg->r,l1,&x1,&y1,0);
        road_l2xy(&mtg->r,l2,&x2,&y2,0);
        if(fp)
        {
            fprintf(fp,"l1:%.4f,x:%.4f,y:%.4f\n",l1,x1,y1);
            fprintf(fp,"l2:%.4f,x:%.4f,y:%.4f\n",l2,x2,y2);
            fflush(fp);
        }

        alf1 = atan2(y2-y1,x2-x1);
        if(alf1<0.0) alf1 = alf1+2.0*PI;
        double li=l1;
//        double s=w/len;
        double s=w/50.0;        ///20200729ws 参考whq的修改
        wxPoint lines[60];
        int nlines=0;
//        double len = 0.0;
        h_element* e;
        int hi;
        e = road_horizon_chain(&mtg->r,li,&hi);

        if(fabs(length)>0.05)           ///20200729ws 参考whq的修改
            s=w*1.0/len;

        if(fp)
        {
            fprintf(fp,"l1:%.4f,hi:%d\n",l1,hi);
            fflush(fp);
        }

        while(1)
        {
            if(nlines>59) break;
            if(hi>=nh||hi<0) break;
            e = road_horizon(&mtg->r,hi);

            if(e)
            {
                if(e->type==ROAD_TYPE_START_POINT)
                {
                    lines[nlines].x = x;
                    lines[nlines].y = y+h/2;
                    nlines++;
                    if(mtg->prj.a2z==1)
                    {
                        hi++;
                    }
                    else
                    {
                        if(nlines>59)
                            break;
                        road_l2xy(&mtg->r,l2,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        //if(alf<-PI/2.0) alf=alf+PI;
                        //if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*scale;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        nlines++;
                        break;
                    }
                    //fprintf(fp,"%d,%.4f,%.4f\n",nlines,lines[nlines-1].x,lines[nlines-1].y);
                }
                else if(e->type==ROAD_TYPE_LINE)
                {
                    if(mtg->prj.a2z==1)
                    {
                        road_l2xy(&mtg->r,li,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        //if(alf<-PI/2.0) alf=alf+PI;
                        //if(alf>PI/2.0) alf=alf-PI;

                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*scale;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        nlines++;
                        if(nlines>59)
                            break;
                        if(l2>e->l1+e->length)
                        {
                            if(fp)
                            {
                                fprintf(fp,"hi:%d\n",l1,hi);
                                fflush(fp);
                            }
                            //wxMessageBox(wxString::Format(_("l2>l1+length,%.4f,%.4f"),l2,e->l1+e->length));
                            //x2 = e->x2;
                            //y2 = e->y2;
                            if(mtg->prj.a2z==1)
                                road_l2xy(&mtg->r,e->l1+e->length,&x2,&y2,0);
                            else
                                road_l2xy(&mtg->r,e->l1+e->length,&x2,&y2,0);
                            //wxMessageBox(wxString::Format(_("%.4f"),e->l1+e->length));
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            //if(alf<-PI/2.0) alf=alf+PI;
                            //if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*scale;

                            //wxMessageBox(wxString::Format(_("%d"),nlines));
                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            hi++;
                            li = e->l1+e->length;
                            //wxMessageBox(wxString::Format(_("%d"),nlines));
                        }
                        else
                        {
                            road_l2xy(&mtg->r,l2,&x2,&y2,0);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            //if(alf<-PI/2.0) alf=alf+PI;
                            //if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*scale;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            //fprintf(fp,"%d,%d,%d\n",nlines,lines[nlines].x,lines[nlines].y);
                            break;
                        }
                    }
                    else
                    {
                        road_l2xy(&mtg->r,li,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        //if(alf<-PI/2.0) alf=alf+PI;
                        //if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*scale;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;

                        nlines++;
                        if(nlines>59)
                            break;

                        if(l2<e->l1)
                        {
                            //x2 = e->x1;
                            //y2 = e->y1;
                            road_l2xy(&mtg->r,e->l1,&x2,&y2,0);

                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            //if(alf<-PI/2.0) alf=alf+PI;
                            //if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*scale;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            hi--;
                            li = e->l1;
                        }
                        else
                        {
                            road_l2xy(&mtg->r,l2,&x2,&y2,0);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            //if(alf<-PI/2.0) alf=alf+PI;
                            //if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*scale;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            break;
                        }
                    }
                }
                else if(e->type==ROAD_TYPE_ARC || e->type==ROAD_TYPE_SPIRAL)
                {
                    if(road_l2xy(&mtg->r,li,&x2,&y2,0)>=0)
                    {
                        if(fp)
                        {
                            fprintf(fp,"x2:%.4f,y2:%.4f\n",x2,y2);fflush(fp);
                        }
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        //if(alf<-PI/2.0) alf=alf+PI;
                        //if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*scale;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;

                        if(lines[nlines].x == x+w)
                        {
                            nlines++;
                            break;
                        }
                        else if(lines[nlines].x > x+w)
                        {
                            lines[nlines].y = lines[nlines-1].y+(lines[nlines].y-lines[nlines-1].y)*(x+w-lines[nlines-1].x)/(lines[nlines].x-lines[nlines-1].x);   ///20200608ws modify
                            lines[nlines].x = x+w;
                            nlines++;
                            break;
                        }
                        if(nlines>59)
                            break;
                        nlines++;
                    }
                    if(mtg->prj.a2z==1)
                    {
                        li+=1;
                    }
                    else
                    {
                        li=li-1;
                    }
                    if(fp)
                    {
                        fprintf(fp,"nlines:%d,  li:%.4f,",nlines,li);
                        fflush(fp);
                    }
                }
                else if(e->type==ROAD_TYPE_END_POINT)
                {
                    if(mtg->prj.a2z==-1)
                    {
                        hi--;
                    }
                    else
                    {
                        //wxMessageBox(wxString::Format(_("%d"),nlines));
                        road_l2xy(&mtg->r,l2,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        //if(alf<-PI/2.0) alf=alf+PI;
                        //if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*scale;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        nlines++;
                        break;
                    }
                }
            }
        }

        if(nlines>1)   ///20200608ws modify   否则只有一个坐标数据时，不绘制中线
        {
            int i1=0;
            for(int i=0;i<nlines-1;i++)
            {
                memDC->SetPen(wxPen(wxColor(255,255,255),1));
                memDC->SetPen(wxPen(wxColor(58,58,58),1));
                memDC->DrawLine(lines[i].x,lines[i].y,lines[i+1].x,lines[i+1].y);

                if(lines[i].x<=x+w1 && lines[i+1].x>x+w1)   //盾尾的高度计算  ,相似三角形原理求x+w1处的高度h1
                {
                    h1 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w1-lines[i].x)/(lines[i+1].x-lines[i].x);
                }

                if(lines[i].x<=x+w3 && lines[i+1].x>x+w3)   //盾中的高度计算
                {
                    h3 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w3-lines[i].x)/(lines[i+1].x-lines[i].x);
                }

                if(lines[i].x<=x+w2 && lines[i+1].x>x+w2)   //盾首的高度计算
                {
                    h2 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w2-lines[i].x)/(lines[i+1].x-lines[i].x);
                }
            }
        }
        else
        {
            memDC->DrawLine(x,y+h/2,x+w,y+h/2);
            h1 = y+h/2;
            h2 = y+h/2;
            h3 = y+h/2;
        }

    }
    else
    {
        memDC->DrawLine(x,y+h/2,x+w,y+h/2);
        h1 = y+h/2;
        h2 = y+h/2;
        h3 = y+h/2;
    }

//    if(mtg->m1.t1>0)
//    {
//        h2 = h2+headh*ds;
//        h3 = h3+midh*ds;
//        //h2=h/2+headh*ds;
//        //h3=h/2+midh*ds;
//        //mtg->m1.faj[2]=0.068;
//        //mtg->m1.faj[3]=0.028;
//
//        ///20180601whq注释下面的代码并还原以前的,因为该代码在现场出现画图错误，因此现在还原至以前的
//        double ori=(h2-h3)*1.0/(w2-w3);
//        ori=atan(ori);
//        if(mtg->tbm.type==1) ori=ori-atan((mtg->m1.baj[2]-mtg->m1.baj[3])/mtg->tbm.D[3])*20.0*ds;
//        else if(mtg->tbm.type>1) ori=ori-atan((mtg->m1.faj[2]-mtg->m1.faj[3])/mtg->tbm.D[2])/**20.0*/*ds;
//        h1=h3-(w3-w1)*1.0*tan(ori);
//        //fprintf(fp,"l=%4f,r=%.4f,r=%.4f\n",mtg->m1.faj[2],mtg->m1.faj[3],mtg->tbm.D[2]);
//        ///20180920whq注释下面的代码，并还原成20180601之前的
////        h1 = h1+tailh*ds;
////        h2 = h2+headh*ds;
////        h3 = h3+midh*ds;
//    }
//    else
//    {
//        h1 = y+h/2;
//        h2 = y+h/2;
//        h3 = y+h/2;
//    }

//    if(mtg->m1.t1>0)
//    {
//        h1 = h1+tailh*ds;
//        h2 = h2+headh*ds;
//        //memDC->DrawCircle(wxPoint(w1,h1),2);
//        //h3 = h3+midh*ds;
//
//        ///20180601whq注释下面的代码并还原以前的,因为该代码在现场出现画图错误，因此现在还原至以前的
//        double ori=(h1-h2)*1.0/(w1-w2);
//        ori=atan(ori);
//        if(mtg->tbm.type==1) ori=ori-atan((mtg->m1.baj[2]-mtg->m1.baj[3])/mtg->tbm.D[3])*20.0*ds;
//        else if(mtg->tbm.type>1) ori=ori-atan((mtg->m1.faj[2]-mtg->m1.faj[3])/mtg->tbm.D[2])*20.0*ds;
//        if(mtg->tbm.type==1)
//        h3=h2-(w2-w3)*1.0*tan(ori);
//        else if(mtg->tbm.type>1)
//        h3=h1-(w1-w3)*1.0*tan(ori);
//        //fprintf(fp,"l=%4f,r=%.4f,r=%.4f\n",mtg->m1.faj[2],mtg->m1.faj[3],mtg->tbm.D[2]);
//        ///20180920whq注释下面的代码，并还原成20180601之前的
//        h1 = h1+tailh*ds;
//        h2 = h2+headh*ds;
//        h3 = h3+midh*ds;
//    }
//    else
//    {
//        h1 = y+h/2;
//        h2 = y+h/2;
//        h3 = y+h/2;
//    }


    if(mtg->m1.t1>0)
    {
        double ori=0.0;

        if(mtg->tbm.type>1)   //主动
        {
            h1 = h1+tailh*ds;   //左负右正，所以偏差值为负时，y值变小
            h3 = h3+midh*ds;
            ori=(h3-h1)*1.0/(w3-w1);
        }
        else if(mtg->tbm.type==1)    //被动
        {
            h2 = h2+headh*ds;
            h3 = h3+midh*ds;
            ori=(h3-h2)*1.0/(w2-w3);
        }
        else        //无铰接
        {
            h1 = h1+tailh*ds;
            h2 = h2+headh*ds;
            ori=(h1-h2)*1.0/(w1-w2);
        }


        ///20180601whq注释下面的代码,因为水平曲线画图时该代码在现场出现画图错误，因此现在还原至以前的
        ori=atan(ori);
        if(fp)
        {
            fprintf(fp,"ori=%.4f,h3=%d,h2=%d,w3=%d,w2=%d\n",ori,h3,h2,w3,w2);fflush(fp);
        }

//        scale=len/length*2.0;       ///20200729ws modify
        scale=length;       ///20200930ws modify

        if(mtg->tbm.type==1)
            ori=ori+atan((mtg->m1.baj[2]-mtg->m1.baj[3])/mtg->tbm.D[3]*scale)/**20.0*ds*/;    ///20200729ws 参考whq的修改
        else if(mtg->tbm.type>1)
            ori=ori+atan((mtg->m1.faj[2]-mtg->m1.faj[3])/mtg->tbm.D[2]*scale)/**20.0*ds*/;    ///20200729ws 参考whq的修改
        if(fp)
        {
            fprintf(fp,"w1=%d,w2=%d,w3=%d\n",w1,w2,w3);fflush(fp);
            fprintf(fp,"faj0=%.4f,faj1=%.4f\n",mtg->m1.faj[2],mtg->m1.faj[3]);fflush(fp);
            fprintf(fp,"ori=%.4f\n",ori);fflush(fp);
        }


        if(mtg->tbm.type==1)
        {
            h1=h3+(w3-w1)*1.0*tan(ori);   //要保证方向一致，ori是正的则△w/△h的值也要为正
            if(fp)
            {
                fprintf(fp,"len1:%.4f,len2:%.4f\n",mtg->tbm.L[0],mtg->tbm.L[2]);
            }
        }
        else if(mtg->tbm.type>1)
        {
            h2=h3+(w2-w3)*1.0*tan(ori);
        }
    }

    int w4,h4;
    int dw1=15*sx;
    int dh1;
    int dw2,dh2;
    double xd;
    wxPoint arrow[3];
    if(mtg->tbm.type>0)
    {
        xd = (w2-w3)*(w2-w3)+(h2-h3)*(h2-h3);
        xd = sqrt(xd);
        dh1 = (h3-h2)*dw1/xd;
        dw1 = (w3-w2)*dw1/xd;
        dw2 = dh1/3;
        dh2 = dw1/3;

        w4=x+w2+dw1;
        h4=h2+dh1;
        arrow[0].x=w4-dw2;
        arrow[0].y=h4-dh2;
        arrow[1].x=x+w2;
        arrow[1].y=h2;
        arrow[2].x=w4+dw2;
        arrow[2].y=h4+dh2;
    }
    else
    {
        xd = (w2-w1)*(w2-w1)+(h2-h1)*(h2-h1);
        xd = sqrt(xd);
        dh1 = (h1-h2)*dw1/xd;
        dw1 = (w1-w2)*dw1/xd;
        dw2 = dh1/3;
        dh2 = dw1/3;

        w4=x+w2+dw1;
        h4=h2+dh1;

        arrow[0].x=w4-dw2;
        arrow[0].y=h4-dh2;
        arrow[1].x=x+w2;
        arrow[1].y=h2;
        arrow[2].x=w4+dw2;
        arrow[2].y=h4+dh2;
    }

    memDC->SetPen(wxPen(wxColor(0,75,255)));
    memDC->SetBrush(wxBrush(wxColor(0,75,255)));
    memDC->DrawPolygon(3,arrow);

    if(mtg->tbm.type>0)
    {
        memDC->SetPen(wxPen(wxColor(0,75,255)));
        memDC->DrawLine(x+w1,h1,x+w3,h3);
        memDC->DrawLine(x+w3,h3,x+w2,h2);
        memDC->SetPen(wxPen(wxColor(255,0,0)));
        memDC->DrawLine(x+w3-dw2*3/2,h3-dh2*3/2-1,x+w3+dw2*3/2,h3+dh2*3/2);
    }
    else
    {
        memDC->SetPen(wxPen(wxColor(255,255,255)));
        memDC->SetPen(wxPen(wxColor(0,75,255)));
        memDC->DrawLine(x+w1,h1,x+w2,h2);
    }
    if(fp)
    {
        fclose(fp);
    }
}

void mtg_t_cliFrame::PaintVertical(wxMemoryDC* memDC, wxRect rect,double ds)
{
    int x,y;
	x = rect.x;
	y = rect.y;
    int w,h;
    GetSize(&w,&h);
    double sx,sy;
    sx = w/1024.0;
    sy = h/768.0;
    w = rect.width;
	h = rect.height;
    ds=h/6/ds;
    FILE* fp=fopen("D:\\midu\\PaintVertical.log","w");
    memDC->SetPen(wxPen(wxColor(112,112,112)));
    memDC->SetBrush(wxBrush(wxColor(248,248,248)));
    memDC->DrawRectangle(x,y+1,w,h-2);

    double d1,d2,pds;
    double  length;
    if(mtg->m1.t1>0)
    {
        d1 = fabs(midc-tailc);
        d2 = fabs(headc-midc);
        pds = d1/(d1+d2);
    }
    else
    {
//        d1=mtg->tbm.L[3];
//        d2=mtg->tbm.L[0]-mtg->tbm.L[3];
        d1=mtg->tbm.L[2];   ///20200729ws 参考whq修改
        d2=mtg->tbm.L[0];
        pds = d1/(d1+d2);
    }
    length=d1+d2;

    int nv = road_number_vertical(&mtg->r);

    int w1=w/4;
    int h1=y+h/2;
    int w2=w*3/4;
    int h2=y+h/2;
    int w3 = w1+w/2*pds;
    int h3=y+h/2;
//    double len=2*length;
//    len=50.0;
//    double scale=len/length;
    double scale=1.0;               ///20200729ws 参考whq修改
    double len=length*2;
    ///double len=50.0;        ///20200729ws modify

    double l1,l2;
    if(mtg->m1.t1<=0)
    {
        if(mtg->prj.a2z==1)
        {
            l1 = mtg->prj.mile1-len/2.0;
            l2 = l1+len;
        }
        else
        {
            l1 = mtg->prj.mile2+len/2.0;
            l2 = l1-len;
        }
    }
    else
    {
        if(mtg->prj.a2z==1)
        {
            l1 = mtg->m1.headc-len/2.0;
            l2 = l1+len;
        }
        else
        {
            l1 = mtg->m1.headc+len/2.0;
            l2 = l1-len;
        }
    }
    //fprintf(fp,"nv=%d,l1=%.4f,l2=%.4f\n",nv,l1,l2);
    double x1=0.0,y1=0.0,x2=0.0,y2=0.0,x3=0.0,y3=0.0;
    double alf=0.0,alf1=0.0,alf2=0.0;
    x1 = l1;

    if(nv>2)
    {
        double li=l1;
//        double s=w/len;
        double s=w/50.0;        ///20200729ws 参考whq修改
        wxPoint lines[60];
        int nlines=0;
        //double len = 0.0;
        int vi;
        v_element* e = road_vertical_chain(&mtg->r,li,&vi);
        road_l2h(&mtg->r,l1,&y1,&alf1);
        if(alf1<0.0) alf1 = alf1+2.0*PI;

        s=w/len;    ///20200729ws 参考whq修改

        while(1)
        {
            if(nlines>59) break;
            if(vi>=nv||vi<0) break;
            e = road_vertical(&mtg->r,vi);
            //fprintf(fp,"vi=%d,type=%d\n",vi,e->type);
            if(e)
            {
                if(e->type==ROAD_TYPE_START_POINT)
                {
                    lines[nlines].x = x;
                    lines[nlines].y = y+h/2;
                    nlines++;
                    if(mtg->prj.a2z==1)
                    {
                        vi++;
                        li=e->l1;
                    }
                    else
                    {
                        break;
                    }
                }
                else if(e->type==ROAD_TYPE_LINE)
                {
                    if(mtg->prj.a2z==1)
                    {
                        x2 = li;
                        road_l2h(&mtg->r,li,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        x2 = x+len*cos(alf2);
                        y2 = y+h/2-len*sin(alf2)*scale;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        //fprintf(fp,"%d,%d,%d,%d,%.4f\n",nlines,lines[nlines].x,lines[nlines].y,x,li);
                        nlines++;
                        if(nlines>59)
                            break;

                        if(l2>e->l1+e->length)
                        {
                            x2 = e->l1+e->length;
//                            y2 = e->h2;
                            road_l2h(&mtg->r,x2,&y2,0);    //20200807ws modify
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            x2 = x+len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*scale;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            vi++;
                            li = e->l1+e->length;
                        }
                        else
                        {
                            x2 = l2;
                            road_l2h(&mtg->r,l2,&y2,0);
                            //fprintf(fp,"l2:%.4f,y2:%.4f\n",l2,y2);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;
                            //fprintf(fp,"%.4f,%.4f,%.4f\n",x2,y2,len);

                            x2 = x+len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*scale;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            break;
                        }
                    }
                    else
                    {
                        x2 = li;
                        road_l2h(&mtg->r,li,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        x2 = x-len*cos(alf2);
                        y2 = y+h/2-len*sin(alf2)*scale;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;

                        nlines++;
                        if(nlines>59)
                            break;
                        //fprintf(fp,"%.4f,%.4f\n",l2,e->l1);
                        if(l2<e->l1)     ///20200608ws modify
                        {
                            //wxMessageBox(_("ok"));
                            x2 = e->l1;
//                            y2 = e->h1;
                            road_l2h(&mtg->r,x2,&y2,0);    //20200807ws modify
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            x2 = x-len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*scale;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            vi--;
                            li=e->l1;
                        }
                        else
                        {
                            x2 = l2;
                            road_l2h(&mtg->r,l2,&y2,0);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            x2 = x-len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*scale;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;

                            nlines++;
                            break;
                        }
                    }
                }
                else if(e->type==ROAD_TYPE_ARC)
                {
                    if(road_l2h(&mtg->r,li,&y2,0)>=0)
                    {
                        //fprintf(fp,"%.4f,%.4f\n",li,y2);
                        //fflush(fp);
                        x2 = li;
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        x2 = x+fabs(len*cos(alf2));
                        y2 = y+h/2-len*sin(alf2)*scale;
                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        //fprintf(fp,"%d,%d\n",lines[nlines].x,x+w);
                        //fflush(fp);
                        if(lines[nlines].x > x+w)
                        {
                            lines[nlines].y = lines[nlines-1].y+(lines[nlines].y-lines[nlines-1].y)*(x+w-lines[nlines-1].x)/(lines[nlines].x-lines[nlines-1].x);   ///20200608ws modify
                            lines[nlines].x = x+w;
                            nlines++;
                            break;
                        }
                        if(nlines>59) break;
                        nlines++;
                    }
                    if(mtg->prj.a2z==1)
                    {
                        li+=1;
                    }
                    else
                    {
                        li=li-1;
                    }
                }
                else if(e->type==ROAD_TYPE_END_POINT)
                {
                    if(mtg->prj.a2z==1)
                    {
                        lines[nlines].x = x+w;
                        lines[nlines].y = y+h/2;
                        nlines++;
                        break;
                        //vi--;
                    }
                    else
                    {
                        ///20200608ws 注释以下部分
//                        x2 = l2;
//                        road_l2h(&mtg->r,l2,&y2,0);
//                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
//                        len = sqrt(len)*s;
//                        alf2 = atan2(y2-y1,x2-x1);
//                        if(alf2<0.0) alf2 = alf2+2.0*PI;
//                        //fprintf(fp,"x2=%.4f,y2=%.4f,z2=%.4f\n",x2,y2,len);
//                        //alf = mtg_sub_angle(alf2,alf1);
//                        x2 = x+len*cos(alf2);
//                        y2 = y+h/2-len*sin(alf2)*scale;
//
//                        lines[nlines].x = x2;
//                        lines[nlines].y = y2;
//                        nlines++;
                        vi--;
                        //break;
                    }
                }
            }
        }

        //fprintf(fp,"nlines=%d\n",nlines);
        if(nlines>1)   ///20200608ws modify   否则只有一个坐标数据时，不绘制中线
        {
            for(int i=0;i<nlines-1;i++)
            {
                //if(lines[i].x>x && lines[i+1].x<x+w)
                {
                    //memDC->SetPen(wxPen(wxColor(255,255,255),1));
                    //memDC->DrawLine(lines[i].x,lines[i].y-1,lines[i+1].x,lines[i+1].y-1);
                    //memDC->DrawLine(lines[i].x,lines[i].y+1,lines[i+1].x,lines[i+1].y+1);
                    memDC->SetPen(wxPen(wxColor(58,58,58),1));
                    memDC->DrawLine(lines[i].x,lines[i].y,lines[i+1].x,lines[i+1].y);
                    //fprintf(fp,"i=%d,x=%d,y=%d\n",i,lines[i].x,lines[i].y);
                }

                //memDC->DrawLine(lines[i],lines[i+1]);

                if(lines[i].x<=x+w1 && lines[i+1].x>x+w1)
                {
                    h1 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w1-lines[i].x)/(lines[i+1].x-lines[i].x);
                }

                if(lines[i].x<=x+w2 && lines[i+1].x>x+w2)
                {
                    h2 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w2-lines[i].x)/(lines[i+1].x-lines[i].x);
                }

                if(lines[i].x<=x+w3 && lines[i+1].x>x+w3)
                {
                    h3 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w3-lines[i].x)/(lines[i+1].x-lines[i].x);
                }
            }
        }
        else
        {
            memDC->DrawLine(x,y+h/2,x+w,y+h/2);
            h1 = y+h/2;
            h2 = y+h/2;
            h3 = y+h/2;
        }
    }
    else
    {
        memDC->SetPen(wxPen(wxColor(58,58,58),1));
        memDC->DrawLine(x,y+h/2,x+w,y+h/2);
        h1 = y+h/2;
        h2 = y+h/2;
        h3 = y+h/2;
    }

    ///20181219 whq change tha following
//    if(mtg->m1.t1>0)
//    {
//        h1 = h1-tailv*ds;
//        h2 = h2-headv*ds;
//        h3 = h3-midv*ds;
//        /20180601whq注释下面的代码,因为水平曲线画图时该代码在现场出现画图错误，因此现在还原至以前的
//        double phi=(h1-h2)*1.0/(w1-w2);
//        phi=atan(phi);
//        fprintf(fp,"phi=%.4f,h1=%d,ds=%.4f\n",phi,h1,ds);
//
//        if(mtg->tbm.type==1) phi=phi-atan((mtg->m1.baj[0]-mtg->m1.baj[1])/mtg->tbm.D[3])*20.0*ds;
//        else if(mtg->tbm.type>1) phi=phi-atan((mtg->m1.faj[0]-mtg->m1.faj[1])/mtg->tbm.D[2])*20.0*ds;
//
//        fprintf(fp,"u=%4f,d=%.4f,r=%.4f\n",mtg->m1.faj[0],mtg->m1.faj[1],mtg->tbm.D[2]);
//        if(mtg->tbm.type==1)
//            h3=h2-(w2-w3)*1.0*tan(phi);
//        else if(mtg->tbm.type>1)
//            h3=h1-(w1-w3)*1.0*tan(phi);
//        /20180920whq注释下面的代码，并还原成20180601之前的
//        h1 = h1-tailv*ds;
//        h2 = h2-headv*ds;
//        h3 = h3-midv*ds;
//    }

    if(mtg->m1.t1>0)
    {
//        h1 = h1-tailv*ds;
//        h2 = h2-headv*ds;
        double phi=0.0;
        //=(h1-h2)*1.0/(w1-w2);

        if(mtg->tbm.type>1)
        {
            h1 = h1-tailv*ds;    //上正下负，所以偏差值为正时，y值应该变小
            h3 = h3-midv*ds;
            phi=(h3-h1)*1.0/(w3-w1);
        }
        else if(mtg->tbm.type==1)
        {
            h2 = h2-headv*ds;
            h3 = h3-midv*ds;
            phi=(h3-h2)*1.0/(w2-w3);
        }
        else
        {
            h1=h1-tailv*ds;
            h2=h2-headv*ds;
        }

        //h3 = h3-midv*ds;
        ///20180601whq注释下面的代码,因为水平曲线画图时该代码在现场出现画图错误，因此现在还原至以前的
        //double phi=(h1-h2)*1.0/(w1-w2);
        phi=atan(phi);
        if(fp)
        {
            fprintf(fp,"0 phi=%.4f,h1=%d,ds=%.4f\n",phi,h1,ds);fflush(fp);
        }

//        scale=len/length*2.0;       ///20200729ws modify
        scale=length;       ///20200930ws modify

        if(mtg->tbm.type==1)
            phi=phi+atan((mtg->m1.baj[0]-mtg->m1.baj[1])/mtg->tbm.D[3]*scale)/**20.0*ds*/;        ///20200729ws 参考whq修改
        else if(mtg->tbm.type>1)
            phi=phi+atan((mtg->m1.faj[0]-mtg->m1.faj[1])/mtg->tbm.D[2]*scale)/**20.0*ds*/;        ///20200729ws 参考whq修改
            //phi=phi+atan((headv*ds-midv*ds)/(w2-w3))*ds;    ///20200714ws test
//            phi=phi+atan((headv-midv)*1.0/(w2-w3))*ds;    ///20200714ws test

        if(fp)
        {
            fprintf(fp,"phi=%.4f,\n",phi);fflush(fp);
        }

        if(mtg->tbm.type==1)
        {
            h1=h3+(w3-w1)*1.0*tan(phi);
            if(h1<y)            ///20200729ws 参考whq修改
                h1=y;
            if(h1>y+h)
                h1=y+h;
        }
        else if(mtg->tbm.type>1)
        {
            h2=h3+(w2-w3)*1.0*tan(phi);
            if(h2<y)            ///20200729ws 参考whq修改
                h2=y;
            if(h2>y+h)
                h2=y+h;
        }
    }

    int w4,h4;
    int dw1=15*sx;
    int dh1;
    int dw2,dh2;
    double xd;
    wxPoint arrow[3];
    if(mtg->tbm.type>0)
    {
        xd = (w2-w3)*(w2-w3)+(h2-h3)*(h2-h3);
        xd = sqrt(xd);
        dh1 = (h3-h2)*dw1/xd;
        dw1 = (w3-w2)*dw1/xd;
        dw2 = dh1/3;
        dh2 = dw1/3;
        //alf=atan2((double)(h2-h3),(double)(w2-w3))+PI/2;
        //wxMessageBox(wxString::Format(_("%.4f"),alf));
        w4=x+w2+dw1;
        h4=h2+dh1;
        arrow[0].x=w4-dw2;
        arrow[0].y=h4-dh2;
        arrow[1].x=x+w2;
        arrow[1].y=h2;
        arrow[2].x=w4+dw2;
        arrow[2].y=h4+dh2;
    }
    else
    {
        xd = (w2-w1)*(w2-w1)+(h2-h1)*(h2-h1);
        xd = sqrt(xd);
        dh1 = (h1-h2)*dw1/xd;
        dw1 = (w1-w2)*dw1/xd;
        dw2 = dh1/3;
        dh2 = dw1/3;
        //alf=atan2((double)(h2-h3),(double)(w2-w3))+PI/2;
        //wxMessageBox(wxString::Format(_("%.4f"),alf));
        w4=x+w2+dw1;
        h4=h2+dh1;
        arrow[0].x=w4-dw2;
        arrow[0].y=h4-dh2;
        arrow[1].x=x+w2;
        arrow[1].y=h2;
        arrow[2].x=w4+dw2;
        arrow[2].y=h4+dh2;
    }

    memDC->SetPen(wxPen(wxColor(0,75,255)));
    memDC->SetBrush(wxBrush(wxColor(0,75,255)));
    memDC->DrawPolygon(3,arrow);

    if(mtg->tbm.type>0)
    {
        //memDC->SetPen(wxPen(wxColor(255,255,255)));
        //memDC->DrawLine(x+w1,h1-1,x+w3,h3-1);
        //memDC->DrawLine(x+w1,h1+1,x+w3,h3+1);
        //memDC->DrawLine(x+w3,h3-1,x+w2,h2-1);
        //memDC->DrawLine(x+w3,h3+1,x+w2,h2+1);
        memDC->SetPen(wxPen(wxColor(0,75,255)));
        memDC->DrawLine(x+w1,h1,x+w3,h3);
        memDC->DrawLine(x+w3,h3,x+w2,h2);
        memDC->SetPen(wxPen(wxColor(255,0,0)));
        memDC->SetBrush(*wxTRANSPARENT_BRUSH);
        memDC->DrawLine(x+w3-dw2*3/2,h3-dh2*3/2-1,x+w3+dw2*3/2,h3+dh2*3/2);
    }
    else
    {
        memDC->SetPen(wxPen(wxColor(0,75,255)));
        memDC->DrawLine(x+w1,h1,x+w2,h2);
    }
    if(fp)
    {
        fclose(fp);
    }
}


void mtg_t_cliFrame::OnPaintGraph(wxPaintEvent& event)
{
    wxBufferedPaintDC dc(panelGraph);
    int w,h;
    GetSize(&w,&h);
    double sx,sy;
    sx=w/1024.0;
    sy=h/768.0;
    if(sx > sy) sx = sy;

    panelGraph->GetClientSize(&w,&h);

    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background

        memDC.SetPen(wxPen(wxColor(150,163,172)));
        memDC.SetBrush(wxBrush(wxColor(150,163,172)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        ///1086*150
        double w1,h1;
        h1 = h*2/3;
        w1 = h1;
        double sx1=w1/75.0;

        memDC.SetTextForeground(wxColor(255,255,255));


        int tw1 = w1*2/3,th1=tw1;
        int x1 = w-tw1*3/2;
        int y1 = h/6;
        int x2 = x1+tw1/12;
        int y2 = y1+th1/12;
        int tw2 = tw1-tw1/12-tw1/12;
        int th2 = tw2;
        memDC.SetBrush(wxBrush(wxColor(180,190,200)));
        memDC.SetPen(wxPen(wxColor(100,110,125)));
        memDC.DrawRectangle(x1-3,y1-3,tw1+6,th1+6);
        memDC.DrawRectangle(x1,y1,tw1,th1);

        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.SetBrush(wxBrush(wxColor(248,248,248)));
        memDC.DrawRectangle(x2-1,y2-1,tw2+2,th2+2);
        memDC.DrawLine(x2,y2+th2/2,x2+tw2,y2+th2/2);
        memDC.DrawLine(x2+tw2/2,y2,x2+tw2/2,y2+th2);

        h1 = h*19/20;
        int pw1,ph1;
        double s=1.0;
        if(bmpTps2.IsOk())
        {
            ph1=bmpTps2.GetHeight();
            pw1=bmpTps2.GetWidth();
            s=h1/ph1;
        }
        else if(bmpTps1.IsOk())
        {
            ph1=bmpTps1.GetHeight();
            pw1=bmpTps2.GetWidth();
            s=h1/ph1;
        }
        memDC.SetUserScale(s,s);
        ///画全站仪
        if(tpsDirection==0)  ///backsight
        {
            if(bmpTps2.IsOk()) memDC.DrawBitmap(bmpTps2,w/2/s-pw1/2,0);
        }
        else if(tpsDirection==1)  ///prism
        {
            if(bmpTps1.IsOk()) memDC.DrawBitmap(bmpTps1,w/2/s-pw1/2,0);
        }
        else if(tpsDirection==2) ///rolling
        {
            if(tickAnimation>=5)
            {
                if(bmpTps2.IsOk()) memDC.DrawBitmap(bmpTps2,w/2/s-pw1/2,0);
            }
            else
            {
                if(bmpTps1.IsOk()) memDC.DrawBitmap(bmpTps1,w/2/s-pw1/2,0);
            }
        }
        int pw2,ph2;
        if(bmpPrism.IsOk())
        {
            ph2=bmpPrism.GetHeight();
            pw2=bmpPrism.GetWidth();
            memDC.DrawBitmap(bmpPrism,pw2/2,h*3/20/s);
        }

        ///动态测量
        memDC.SetUserScale(1.0,1.0);
        //memDC.SetPen(wxPen(wxColor(255,0,0),2));
        int xy[4];

        xy[0]=w/2-pw1/2*s;
        xy[1]=h*7/20;
        xy[2]=pw2*3/2*s;
        xy[3]=h*7/20;
        //memDC.DrawLine(xy[0],xy[1],xy[0]+(xy[2]-xy[0]),xy[1]+(xy[3]-xy[1]));
        xy[0]=w/2+pw1/2*s;
        xy[1]=h*7/20;
        xy[2]=w-33*sx;
        xy[3]=h*7/20;
        //memDC.SetPen(wxPen(wxColor(255,0,0),2));
        //memDC.DrawLine(xy[0],xy[1],xy[0]+xy[2]-xy[0],xy[1]+xy[3]-xy[1]);
        if(drawAnimation)
        {
            if(tpsDirection==0)
            {
                xy[0]=w/2-pw1/2*s;
                xy[1]=h*7/20;
                xy[2]=pw2*3/2*s;
                xy[3]=(h*7/20);
                memDC.SetPen(wxPen(wxColor(255,0,0),2));
                memDC.DrawLine(xy[0],xy[1],xy[0]+(xy[2]-xy[0])*tickAnimation/10,xy[1]+(xy[3]-xy[1])*tickAnimation/10);
            }
            else if(tpsDirection==1)
            {
                xy[0]=w/2+pw1/2*s;
                xy[1]=h*7/20;
                xy[2]=w-33*sx;
                xy[3]=h*7/20;
                memDC.SetPen(wxPen(wxColor(255,0,0),2));
                memDC.DrawLine(xy[0],xy[1],xy[0]+(xy[2]-xy[0])*tickAnimation/10,xy[1]+(xy[3]-xy[1])*tickAnimation/10);
            }
        }

        x1=pw2*3/2*s+5;
        y1=h*7/20+3;
        w1=110;
        h1=h*13/20-4;
        //mtg->deth=0.02;
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        if(fabs(mtg->deth)>=mtg->iset.balw/1000.0) memDC.SetBrush(wxBrush(wxColor(254,254,0)));
        else memDC.SetBrush(wxBrush(wxColor(204,251,200)));
        memDC.DrawRectangle(x1,y1,w1,h1/2+1);
        if(fabs(mtg->detv)>=mtg->iset.balw/1000.0) memDC.SetBrush(wxBrush(wxColor(254,254,0)));
        else memDC.SetBrush(wxBrush(wxColor(204,251,200)));
        memDC.DrawRectangle(x1,y1+h1/2,w1,h1/2);
        //memDC.DrawLine(x1,y1+h1/2,x1+w1,y1+h1/2);

        wxString istr;
        istr=_("水平: ")+wxString::Format(_("%.1f mm"),mtg->deth*1000.0);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(0,0,0));
        memDC.DrawLabel(istr,wxRect(x1+10,y1+h1/4,w1,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        istr=_("垂直: ")+wxString::Format(_("%.1f mm"),mtg->detv*1000.0);
        memDC.DrawLabel(istr,wxRect(x1+10,y1+h1*3/4,w1,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_cliFrame::OnPaintButton(wxPaintEvent& event)
{
    wxPaintDC dc(panelButton);
    int w,h;
    GetSize(&w,&h);
    double sx,sy,sxy;
	sx = w/1024.0;
	sy = h/768.0;
	if(sx>sy)
	{
		sxy = sy;
	}
	else
	{
		sxy = sx;
	}

    panelButton->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);

    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);

        memDC.SetBrush(wxBrush(wxColor(204,204,204)));
        memDC.DrawRectangle(0,10,w+1,h-10);
        memDC.SetBrush(wxBrush(wxColor(255,255,255),wxBDIAGONAL_HATCH));
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawRectangle(0,10,w+1,h-10);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetTextForeground(wxColor(71,71,71));
        memDC.SetFont(chs);
        int x,y,x2;
        int r,g,b;
        int btns=ID_BTN_QUIT-ID_BTN_RUN+1;
        int btn_h=36.0*sy;
        for(int i=0;i<btns;i++)
        {
            y=11+i*btn_h;
            x=1;
            x2=w;
            button[ID_BTN_RUN+i].x=x;
            button[ID_BTN_RUN+i].y=y;
            button[ID_BTN_RUN+i].width=w-2;
            button[ID_BTN_RUN+i].height=btn_h;

            if(motion==ID_BTN_RUN+i)
            {
                r=200;
                g=225;
                b=250;
                for(int j=0;j<btn_h-2;j++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*j/(btn_h-2),g+20*j/(btn_h-2),b)));
                    memDC.DrawLine(x,y,x2,y);
                    y++;
                }
            }
            else
            {
                r=236;
                g=236;
                b=236;
                for(int j=0;j<btn_h-2;j++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x,y,x2,y);
                    r--;
                    g--;
                    b--;
                    y++;
                }
            }
            memDC.SetPen(wxPen(wxColor(236,236,236)));
            memDC.DrawLine(x,y,x2,y);
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.DrawLine(x,y+1,x2,y+1);
            if(clicked==ID_BTN_RUN+i)
            {
                memDC.DrawLabel(_("◆ ")+btn_label[i],wxRect(10,y-btn_h+2,w-20,btn_h-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(_("◇ ")+btn_label[i],wxRect(10,y-btn_h+2,w-20,btn_h-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
            //memDC.DrawLabel(btn_label[i],wxRect(x+w/10,y-btn_height+2,w*9/10,btn_height-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_cliFrame::OnMotionButton(wxMouseEvent& event)
{
    int x,y;
    int w,h;
    x=event.GetX();
    y=event.GetY();
    panelButton->GetClientSize(&w,&h);
    int btns=ID_BTN_QUIT-ID_BTN_RUN+1;
    for(int i=0;i<btns;i++)
    {
        if(x>button[ID_BTN_RUN+i].x && x<button[ID_BTN_RUN+i].x+button[ID_BTN_RUN+i].width)
        {
            if(y>button[ID_BTN_RUN+i].y && y<button[ID_BTN_RUN+i].y+button[ID_BTN_RUN+i].height)
            {
                motion=ID_BTN_RUN+i;
                break;
            }
            else if(i==btns-1)
            {
                motion=ID_BTN_NONE;
                break;
            }
            else
            {
                continue;
            }
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    //btn_left_down=-1;
    panelButton->Refresh();
}

void mtg_t_cliFrame::OnLeaveButton(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    panelButton->Refresh();
}

void mtg_t_cliFrame::OnClickButton(wxMouseEvent& event)
{
    if(motion==ID_BTN_RUN)
    {
        clicked=ID_BTN_RUN;
        RunMeasurement();
    }
    else if(motion==ID_BTN_END)
    {
        clicked=ID_BTN_END;
        EndMeasurement();
    }
    else if(motion==ID_BTN_SEGSEL)
    {
        clicked=ID_BTN_SEGSEL;
        CalRings();
    }
    else if(motion==ID_BTN_STN)
    {
        clicked=ID_BTN_STN;
        MoveStation();
    }
    else if(motion==ID_BTN_CHK)
    {
        clicked=ID_BTN_CHK;
        Check();
    }
    else if(motion==ID_BTN_QRY)
    {
        clicked=ID_BTN_QRY;
        Query();
    }
    else if(motion==ID_BTN_DTA)
    {
        clicked=ID_BTN_DTA;
         EditDTA();
    }
    else if(motion==ID_BTN_MAP)
    {
        clicked=ID_BTN_MAP;
        ViewMap();
    }
    else if(motion==ID_BTN_SET)
    {
        clicked=ID_BTN_SET;
        Settings();
    }
    else if(motion==ID_BTN_QUIT)
    {
        clicked=ID_BTN_QUIT;
        Close();
    }
    panelButton->Refresh();
}

void mtg_t_cliFrame::OnPaintDuty(wxPaintEvent& event)
{
    wxBufferedPaintDC dc(panelDuty);
    int w,h;
    GetSize(&w,&h);
    double sx,sy;
    sx=w/1024.0;
    sy=h/768.0;
    if(sx > sy)
    {
        sx = sy;
    }
    panelDuty->GetClientSize(&w,&h);

    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background

        memDC.SetPen(wxPen(wxColor(150,163,172)));
        memDC.SetBrush(wxBrush(wxColor(150,163,172)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int op=mtg->ndty;
        int x1,y1,w1,h1;

        w1=60;
        h1=h;
        x1=w*1/2-w1*3/2;
        y1=0;
        button[ID_BTN_PREV_OP].x=x1;
        button[ID_BTN_PREV_OP].y=y1;
        button[ID_BTN_PREV_OP].width=w1/2;
        button[ID_BTN_PREV_OP].height=h1;
        if(motion==ID_BTN_PREV_OP)
        {
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.SetBrush(wxBrush(wxColor(254,254,0)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.SetBrush(wxBrush(wxColor(204,251,200)));
        }
        memDC.DrawRectangle(x1,y1,w1/2,h1);
        memDC.DrawLabel(_("<"),wxRect(x1,y1,w1/2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1/2-1;
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.SetBrush(wxBrush(wxColor(204,251,200)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        int duty=mtg->onduty;
        wxString str1=wxString(mtg->duty[duty].name,wxConvLocal);
        memDC.DrawLabel(str1,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        button[ID_BTN_NEXT_OP].x=x1;
        button[ID_BTN_NEXT_OP].y=y1;
        button[ID_BTN_NEXT_OP].width=w1/2;
        button[ID_BTN_NEXT_OP].height=h1;
        if(motion==ID_BTN_NEXT_OP)
        {
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.SetBrush(wxBrush(wxColor(254,254,0)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.SetBrush(wxBrush(wxColor(204,251,200)));
        }
        memDC.DrawRectangle(x1,y1,w1/2,h1);
        memDC.DrawLabel(_(">"),wxRect(x1,y1,w1/2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/2+3;
        button[ID_BTN_RP].x=x1;
        button[ID_BTN_RP].y=y1;
        button[ID_BTN_RP].width=w1;
        button[ID_BTN_RP].height=h1;
        if(motion==ID_BTN_RP)
        {
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.SetBrush(wxBrush(wxColor(254,254,0)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.SetBrush(wxBrush(wxColor(204,251,200)));
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        str1=_("报告");
        memDC.SetFont(chs);
        memDC.DrawLabel(str1,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_cliFrame::OnMotionDuty(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_PREV_OP].y && y<button[ID_BTN_PREV_OP].y+button[ID_BTN_PREV_OP].height)
    {
        if(x>button[ID_BTN_PREV_OP].x && x<button[ID_BTN_PREV_OP].x+button[ID_BTN_PREV_OP].width)
        {
            motion=ID_BTN_PREV_OP;
        }
        else if(x>button[ID_BTN_NEXT_OP].x && x<button[ID_BTN_NEXT_OP].x+button[ID_BTN_NEXT_OP].width)
        {
            motion=ID_BTN_NEXT_OP;
        }
        else if(x>button[ID_BTN_RP].x && x<button[ID_BTN_RP].x+button[ID_BTN_RP].width)
        {
            motion=ID_BTN_RP;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }
    panelDuty->Refresh();
}

void mtg_t_cliFrame::OnLeaveDuty(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    panelDuty->Refresh();
}

void mtg_t_cliFrame::OnClickDuty(wxMouseEvent& event)
{
    if(motion==ID_BTN_PREV_OP)
    {

    }
    else if(motion==ID_BTN_NEXT_OP)
    {

    }
    else if(motion==ID_BTN_RP)
    {
        DutyDlg dlg(this);
        dlg.Center();
        dlg.ShowModal();
    }
    panelDuty->Refresh();
}

void mtg_t_cliFrame::OnPaintTool(wxPaintEvent& event)
{
    wxBufferedPaintDC dc(panelTool);
    int w,h;
    GetSize(&w,&h);
    double sx,sy;
    sx=w/1024.0;
    sy=h/768.0;
    if(sx > sy)
    {
        sx = sy;
    }
    panelTool->GetClientSize(&w,&h);

    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        int x2,y2,w2,h2;
        h1=h;
        w1=h1*4/3;
        x1=w-w1-2;
        y1=0;
        button[ID_BTN_PRT_SCN].x=x1;
        button[ID_BTN_PRT_SCN].y=y1;
        button[ID_BTN_PRT_SCN].width=w1;
        button[ID_BTN_PRT_SCN].height=h1;
        if(motion==ID_BTN_PRT_SCN)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
        }

        h2=h-6;
        w2=h2*4/3;
        x2=x1+w1/2-w2/2;
        y2=y1+3;
        memDC.SetPen(wxPen(wxColor(168,181,178)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x2,y2,w2-2,h2-2);
        memDC.SetPen(wxPen(wxColor(47,139,205)));
        memDC.SetBrush(wxBrush(wxColor(47,139,205)));
        memDC.DrawRectangle(x2+3,y2+4,w2-8,h2-11);

        memDC.SetPen(wxPen(wxColor(168,181,178)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x2+w2/4-1,y2+h2-3,w2/2,4);

        //memDC.DrawLabel(_("<"),wxRect(x1,y1,w1/2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_cliFrame::OnMotionTool(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_PRT_SCN].y && y<button[ID_BTN_PRT_SCN].y+button[ID_BTN_PRT_SCN].height)
    {
        if(x>button[ID_BTN_PRT_SCN].x && x<button[ID_BTN_PRT_SCN].x+button[ID_BTN_PRT_SCN].width)
        {
            motion=ID_BTN_PRT_SCN;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }
    panelTool->Refresh();
}

void mtg_t_cliFrame::OnLeaveTool(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    panelTool->Refresh();
}

void mtg_t_cliFrame::OnClickTool(wxMouseEvent& event)
{
    if(motion==ID_BTN_PRT_SCN)
    {
        //wxScreenDC DC;
        wxSize screenSize = GetSize();
        wxBitmap bitmap(screenSize.x, screenSize.y);
        wxScreenDC dc;
        wxMemoryDC memDC;
        memDC.SelectObject(bitmap);

        memDC.Blit(0,0,screenSize.x,screenSize.y, &dc,GetPosition().x,GetPosition().y);
        memDC.SelectObject(wxNullBitmap);

        wxString str;
        time_t t;
        time(&t);
        str=_("主界面");
        str+=wxDateTime(t).Format(_("%Y%m%d%H%M.bmp"));
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
        }
    }
    panelTool->Refresh();
}

void mtg_t_cliFrame::OnPaintBar(wxPaintEvent& event)
{
    wxPaintDC dc(panelBar);
    int w,h;

    panelBar->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("黑体"),wxFONTENCODING_DEFAULT);
        wxFont eni(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        //background
        memDC.SetPen(wxPen(wxColor(245,248,250)));
        memDC.SetBrush(wxBrush(wxColor(245,248,250)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(178,178,178)));
        memDC.DrawLine(0,0,w,0);

        wxString valstr;
        int x1,y1,w1,h1;
        metroFig1->GetSize(&w1,0);
        panelMetric->GetSize(&x1,0);
        x1=x1-w1;
        //x1 = hrect.x;
        //w1 = hrect.width;
        y1=0;
        h1=h;
        int x2,y2,w2,h2;
        x2=x1+w1;
        y2=y1;
        h2=h1;
        w2=w-x2;
        int x3,y3,w3,h3;
        x3=0;
        y3=0;
        w3=w-w1-w2;
        h3=h;

        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.SetBrush(wxBrush(wxColor(242,242,242)));
        memDC.DrawRectangle(x1+1,y1+1,w1-2,h1-2);
        memDC.DrawRectangle(x2,y2+1,w2-1,h2-2);
        memDC.DrawRectangle(x3+1,y3+1,w3-2,h3-2);

        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(71,71,71));
        memDC.DrawLabel(_("米度研制"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString(mtg->prj.name,wxConvUTF8),wxRect(x3,y3,w3,h3),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetFont(eni);
        if(mtg->m1.t1>0)
        {
            double p1=mtg->prj.mile1-mtg->prj.mile2;
            p1=fabs(p1);
            double p2=headc-mtg->prj.mile1;
            p2=fabs(p2);
            if(p1==0)
            {
                p1=p2;
                p2=0;
                memDC.SetBrush(wxBrush(wxColor(204,251,200)));
                memDC.DrawRectangle(x1+1,y1+1,(w1-2)*p2/p1,h1-2);
                valstr=_("--%( 0.00 m)");
                memDC.DrawLabel(valstr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(204,251,200)));
                memDC.SetBrush(wxBrush(wxColor(204,251,200)));
                memDC.DrawRectangle(x1+2,y1+2,(w1-4)*p2/p1,h1-4);
                valstr=wxString::Format(_("%.1f"),p2*100/p1)+_("%(")+wxString::Format(_("%.1f"),p2)+_("m)");
                memDC.DrawLabel(valstr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            double p1=mtg->prj.mile1-mtg->prj.mile2;
            p1=fabs(p1);
            if(p1==0) p1=1;
            double p2=0.0;
            memDC.SetBrush(wxBrush(wxColor(204,251,200)));
            memDC.DrawRectangle(x1+1,y1+1,(w1-2)*p2/p1,h1-2);
            valstr=wxString::Format(_("%.1f"),p2*100/p1)+_("%(")+wxString::Format(_("%.1f"),p2)+_("m)");
            memDC.DrawLabel(valstr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_cliFrame::GetMetro()
{
    int maxw,maxh;
    double val;
    int a2z=mtg->prj.a2z;
    double x,y,z;
    //FILE* fp=fopen("D://getmetro.log","a");

    maxw=0;
    maxh=0;

    headh=mtg->m1.hdev1*1000.0;
    //wxMessageBox(wxString::Format(_("%d"),headh));
    //fprintf(fp,"hdev1:%.4f\n",mtg->m1.hdev1);
    //fflush(fp);
    headv=mtg->m1.vdev1*1000.0;
    midh=mtg->m1.hdev2*1000.0;
    midv=mtg->m1.vdev2*1000.0;
    tailc=mtg->m1.mile3;
    tailh=mtg->m1.hdev3*1000.0;
    tailv=mtg->m1.vdev3*1000.0;

    headc=mtg->m1.mile1;
    midc=mtg->m1.mile2;
    tailc=mtg->m1.mile3;

    int j=0;
    int nmoff;
    nmoff=road_number_mile_off(&mtg->r);
    if(nmoff>0&&mtg->iset.vmileage==0)
    {
        m_offset *mo={0};
        val=0.0;
        for(int nn=nmoff-1;nn>=0;nn--)
        {
            mo=road_mile_off(&mtg->r,nn);
            val=mo->off;
            if(headc>mo->mile)
            {
                headc=headc+val;
                break;
            }
        }

        for(int nn=nmoff-1;nn>=0;nn--)
        {
            mo=road_mile_off(&mtg->r,nn);
            val=mo->off;
            if(midc>mo->mile)
            {
                midc=midc+val;
                break;
            }
        }

        for(int nn=nmoff-1;nn>=0;nn--)
        {
            mo=road_mile_off(&mtg->r,nn);
            val=mo->off;
            if(tailc>mo->mile)
            {
                tailc=tailc+val;
                break;
            }
        }
    }

    if(mtg->tbm.type==0)
    {
        head[0]=mtg->m1.head[0];
        head[1]=mtg->m1.head[1];
        head[2]=mtg->m1.head[2];
        tail[0]=mtg->m1.tail[0];
        tail[1]=mtg->m1.tail[1];
        tail[2]=mtg->m1.tail[2];
        hdes[0]=mtg->m1.hdes[0];
        hdes[1]=mtg->m1.hdes[1];
        hdes[2]=mtg->m1.hdes[2];
        tdes[0]=mtg->m1.tdes[0];
        tdes[1]=mtg->m1.tdes[1];
        tdes[2]=mtg->m1.tdes[2];
        inc[0]=mtg->m1.inc1[0]*PI/180.0;
        inc[1]=mtg->m1.inc1[1]*PI/180.0;
        inc[2]=mtg->m1.inc1[2]*PI/180.0;

        tbmlen=(head[0]-tail[0])*(head[0]-tail[0])+(head[1]-tail[1])*(head[1]-tail[1]);
        tbmlen = sqrt(tbmlen);
        maxw = abs(headh)>abs(tailh)?abs(headh):abs(tailh);
        maxh = abs(headv)>abs(tailv)?abs(headv):abs(tailv);
        if(mtg->iset.trend==1)
        {
            double i1,i2;
            road_l2xy(&mtg->r,headc,0,0,&i1);
            road_l2h(&mtg->r,headc,0,&i2);
            //trace(0,"metro:i1=%.4f,i2=%.4f\n",i1,i2);
            //trace(0,"metro:ori=%.4f,phi=%.4f\n",inc[2],inc[1]);
            if(a2z==-1)
            {
                i1+=PI;
                i2=-i2;
                if(i1>2.0*PI) i1-=2.0*PI;
                if(i2>2.0*PI) i2-=2.0*PI;
                //trace(0,"metro:dori=%.4f,dphi=%.4f\n",i1,i2);
            }
            val=inc[2]-i1;
            htrend=tan(val)*1000.0;
            val=inc[1]-i2;
            vtrend=tan(val)*1000.0;
            //trace(0,"metro:htrend=%.4f,vtrend=%.4f\n",htrend,vtrend);
        }
        else
        {
            htrend=(headh-tailh)/tbmlen;
            vtrend=(headv-tailv)/tbmlen;
        }
    }
    else if(mtg->tbm.type==1)
    {
        head[0]=mtg->m1.head[0];
        head[1]=mtg->m1.head[1];
        head[2]=mtg->m1.head[2];
        mid[0]=mtg->m1.tail[0];
        mid[1]=mtg->m1.tail[1];
        mid[2]=mtg->m1.tail[2];

        ///20200422 ws同步whq
        if(mtg->prj.a2z==1)
            road_lo2xy(&mtg->r,mtg->m1.mile3,mtg->m1.hdev3,&tail[0],&tail[1],0);
        else
            road_lo2xy(&mtg->r,mtg->m1.mile3,-mtg->m1.hdev3,&tail[0],&tail[1],0);
        road_l2h(&mtg->r,mtg->m1.mile3,&tail[2],0);
        tail[2]+=mtg->m1.vdev3;

//        tail[0]=mtg->m1.tail2[0];
//        tail[1]=mtg->m1.tail2[1];
//        tail[2]=mtg->m1.tail2[2];
        hdes[0]=mtg->m1.hdes[0];
        hdes[1]=mtg->m1.hdes[1];
        hdes[2]=mtg->m1.hdes[2];
        mdes[0]=mtg->m1.tdes[0];
        mdes[1]=mtg->m1.tdes[1];
        mdes[2]=mtg->m1.tdes[2];
//        tdes[0]=mtg->m1.tdes2[0];
//        tdes[1]=mtg->m1.tdes2[1];
//        tdes[2]=mtg->m1.tdes2[2];
        inc[0]=mtg->m1.inc1[0]*PI/180.0;
        inc[1]=mtg->m1.inc1[1]*PI/180.0;
        inc[2]=mtg->m1.inc1[2]*PI/180.0;

        tbmlen=(head[0]-mid[0])*(head[0]-mid[0])+(head[1]-mid[1])*(head[1]-mid[1]);
        tbmlen = sqrt(tbmlen);
//        tbmlen=mtg->m1.mile1-mtg->m1.mile2;
        tbmlen=fabs(tbmlen);
        maxw = abs(headh)>abs(midh)?abs(headh):abs(midh);
        maxh = abs(headv)>abs(midv)?abs(headv):abs(midv);

        double dist;
        dist=sqrt((mid[1]-tail[1])*(mid[1]-tail[1])+(mid[0]-tail[0])*(mid[0]-tail[0]));


        if(mtg->iset.trend==1)
        {
            double i1,i2;
            road_l2xy(&mtg->r,headc,0,0,&i1);
            road_l2h(&mtg->r,headc,0,&i2);
            //trace(0,"metro:headc=%.4f,i1=%.4f,i2=%.4f\n",headc,i1,i2);
            //trace(0,"metro:ori=%.4f,phi=%.4f\n",inc[2],inc[1]);
            if(a2z==-1)
            {
                i1+=PI;
                i2=-i2;
                if(i1>2.0*PI) i1-=2.0*PI;
                if(i2>2.0*PI) i2-=2.0*PI;
            }
            val=inc[2]-i1;
            htrend=tan(val)*1000.0;
            val=inc[1]-i2;
            vtrend=tan(val)*1000.0;
            //trace(0,"metro:htrend=%.4f,vtrend=%.4f\n",htrend,vtrend);
        }
        else
        {
            htrend=(headh-midh)/tbmlen;
            vtrend=(headv-midv)/tbmlen;
        }
        if(dist>0)    ///20200422 ws同步whq
        {
            htrend2=(midh-tailh)/dist;
            vtrend2=(midv-tailv)/dist;
        }
        else
        {
            htrend2=0.0;
            vtrend2=0.0;
        }
//        htrend2=(midh-tailh)/fabs(mtg->m1.mile2-mtg->m1.mile3);
//        vtrend2=(midv-tailv)/fabs(mtg->m1.mile2-mtg->m1.mile3);
    }
    else if(mtg->tbm.type==2)
    {
        if(mtg->tarset.pos==0)  ///安装于前盾
        {
            head[0]=mtg->m1.head[0];
            head[1]=mtg->m1.head[1];
            head[2]=mtg->m1.head[2];
            mid[0]=mtg->m1.tail[0];
            mid[1]=mtg->m1.tail[1];
            mid[2]=mtg->m1.tail[2];
            ///20200422ws 同步whq
            if(mtg->prj.a2z==1)
                road_lo2xy(&mtg->r,mtg->m1.mile3,mtg->m1.hdev3,&tail[0],&tail[1],0);
            else
                road_lo2xy(&mtg->r,mtg->m1.mile3,-mtg->m1.hdev3,&tail[0],&tail[1],0);
            road_l2h(&mtg->r,mtg->m1.mile3,&tail[2],0);
            tail[2]+=mtg->m1.vdev3;
//            tail[0]=mtg->m1.tail2[0];
//            tail[1]=mtg->m1.tail2[1];
//            tail[2]=mtg->m1.tail2[2];
            hdes[0]=mtg->m1.hdes[0];
            hdes[1]=mtg->m1.hdes[1];
            hdes[2]=mtg->m1.hdes[2];
            mdes[0]=mtg->m1.tdes[0];
            mdes[1]=mtg->m1.tdes[1];
            mdes[2]=mtg->m1.tdes[2];
            tdes[0]=mtg->m1.tdes2[0];
            tdes[1]=mtg->m1.tdes2[1];
            tdes[2]=mtg->m1.tdes2[2];
            inc[0]=mtg->m1.inc1[0]*PI/180.0;
            inc[1]=mtg->m1.inc1[1]*PI/180.0;
            inc[2]=mtg->m1.inc1[2]*PI/180.0;
        }
        else if(mtg->tarset.pos==1)   ///安装于中盾
        {
            ///20200422ws 同步whq
            if(mtg->prj.a2z==1)
                road_lo2xy(&mtg->r,mtg->m1.mile1,mtg->m1.hdev1,&head[0],&head[1],0);
            else
                road_lo2xy(&mtg->r,mtg->m1.mile1,-mtg->m1.hdev1,&head[0],&head[1],0);
            road_l2h(&mtg->r,mtg->m1.mile1,&head[2],0);
            head[2]+=mtg->m1.vdev1;
//            head[0]=mtg->m1.head1[0];
//            head[1]=mtg->m1.head1[1];
//            head[2]=mtg->m1.head1[2];
//            mid[0]=mtg->m1.tail1[0];
//            mid[1]=mtg->m1.tail1[1];
//            mid[2]=mtg->m1.tail1[2];

            mid[0]=mtg->m1.head[0];
            mid[1]=mtg->m1.head[1];
            mid[2]=mtg->m1.head[2];

            tail[0]=mtg->m1.tail[0];
            tail[1]=mtg->m1.tail[1];
            tail[2]=mtg->m1.tail[2];

//            hdes[0]=mtg->m1.hdes1[0];
//            hdes[1]=mtg->m1.hdes1[1];
//            hdes[2]=mtg->m1.hdes1[2];
//            mdes[0]=mtg->m1.tdes1[0];
//            mdes[1]=mtg->m1.tdes1[1];
//            mdes[2]=mtg->m1.tdes1[2];
            tdes[0]=mtg->m1.tdes[0];
            tdes[1]=mtg->m1.tdes[1];
            tdes[2]=mtg->m1.tdes[2];
            inc[0]=mtg->m1.inc2[0]*PI/180.0;
            inc[1]=mtg->m1.inc2[1]*PI/180.0;
            inc[2]=mtg->m1.inc2[2]*PI/180.0;
        }

        tbmlen=(head[0]-mid[0])*(head[0]-mid[0])+(head[1]-mid[1])*(head[1]-mid[1]);
        tbmlen = sqrt(tbmlen);
//        tbmlen=mtg->m1.mile1-mtg->m1.mile2;
//        tbmlen=fabs(tbmlen);
        //trace(0,"ui:pit=%.12f,azi=%.12f\n",inc[1],inc[2]);
        maxw = abs(headh)>abs(midh)?abs(headh):abs(midh);
        maxh = abs(headv)>abs(midv)?abs(headv):abs(midv);

        ///20200422ws同步whq
        double dist=0.0;
        dist=(tail[0]-mid[0])*(tail[0]-mid[0])+(tail[1]-mid[1])*(tail[1]-mid[1]);

        if(mtg->iset.trend==1)
        {
            double i1,i2;
            road_l2xy(&mtg->r,headc,0,0,&i1);
            road_l2h(&mtg->r,headc,0,&i2);
            //trace(0,"metro:headc=%.4f,i1=%.4f,i2=%.4f\n",headc,i1,i2);
            //trace(0,"metro:ori=%.4f,phi=%.4f\n",inc[2],inc[1]);
            if(a2z==-1)
            {
                i1+=PI;
                i2=-i2;
                if(i1>2.0*PI) i1-=2.0*PI;
                if(i2>2.0*PI) i2-=2.0*PI;
            }
            val=inc[2]-i1;
            htrend=tan(val)*1000.0;
            val=inc[1]-i2;
            vtrend=tan(val)*1000.0;
            //trace(0,"metro:htrend=%.4f,vtrend=%.4f\n",htrend,vtrend);
        }
        else
        {
            htrend=(headh-midh)/tbmlen;
            vtrend=(headv-midv)/tbmlen;
        }
        ///20200422ws同步whq
        if(dist>0)
        {
            htrend2=(midh-tailh)/dist;
            vtrend2=(midv-tailv)/dist;
        }
        else
        {
            htrend2=0.0;
            vtrend2=0.0;
        }
    }

    //wxMessageBox(wxString::Format(_("%d"),mtg->tarset.pos));
    maxdev = (maxw>maxh)?maxw:maxh;

    int n=maxdev/50;
    if(maxdev%50>25)
        n+=1;
    maxdev=50*n+50;
    //wxMessageBox(wxString::Format(_("%d"),maxdev));

    if(tbmlen==0)
    {
        htrend=0.0;
        vtrend=0.0;
    }
    //trace(0,"GetMetric:headh=%.1f,headv=%.1f,tailh=%.1f,tailv=%.1f\n",mtg->m1.headh*1000.0,mtg->m1.headv*1000.0,mtg->m1.tailh*1000.0,mtg->m1.tailv*1000.0);
    //trace(0,"GetMetric:headh1=%d,headv1=%d,tailh1=%d,tailv1=%d,midh=%d,midv=%d\n",headh,headv,tailh,tailv,midh,midv);
    //trace(0,"GetMetric:len=%.4f,headc=%.4f,tailc=%.4f,headx=%.4f,heady=%.4f,headz=%.4f,tailx=%.4f,taily=%.4f,tailz=%.4f\n",tbmlen,headc,tailc,head[0],head[1],head[2],tail[0],tail[1],tail[2]);
    //trace(0,"GetMetric:hdesx=%.4f,hdesy=%.4f,hdesz=%.4f,tdesx=%.4f,tdesy=%.4f,tdesz=%.4f\n",head[0],head[1],hdes[2],tail[0],tail[1],tail[2]);
    //trace(0,"GetMetric:htrend=%.4f,vtrend=%.4f,roll=%.4f,phi=%.4f,ori=%.4f\n",htrend,vtrend,inc[0],inc[1],inc[2]);
//    if(fp)
//    {
//        fprintf(fp,"type:%d,mile2:%.4f,mile3%.4f,midh:%d,tailh:%d,trend:%.4f\n",
//                mtg->tbm.type,mtg->m1.mile2,mtg->m1.mile3,midh,tailh,htrend2);
//        fclose(fp);
//        fp=NULL;
//    }
}

void mtg_t_cliFrame::OnPaintMetroFig1(wxPaintEvent& event)
{
    wxPaintDC dc(metroFig1);
    int w,h;
    GetSize(&w,&h);
    double sx,sy,sxy;
	sx = w/1024.0;
	sy = h/768.0;
	if(sx>sy)
	{
		sxy = sy;
	}
	else
	{
		sxy = sx;
	}

    metroFig1->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        //FILE* fp=fopen("E:\\metricFig1.log","w");
        ///background
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);
        ///字体
        wxFont chs(10*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng1(12*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        wxFont eng2(15*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);

        ///姿态区域
        road* cl = &mtg->r;
        int nh = road_number_horizon(cl);
        int nv = road_number_vertical(cl);
        int a2z=mtg->prj.a2z;
        double x[6]={0.0};
        double y[6]={0.0};
        double z[6]={0.0};
        int r[6];
        r[0] = w/2-1;
        ///r[0] = r[0]*9/10;
        for(int i=1;i<6;i++)
        {
            r[i]=r[i-1]-20*sxy;
        }
        int cell = r[0]/6;
        double s = (5.0*cell)/maxdev;
        double val;

        ///盾构三维图
        double sw = mtg->segset.L;
        double mile =mtg->m1.headc;
        double alf1,alf2,ph;
        double sr1,sr2;
        int h1 = 20*sxy;

        int gx1=w/2;
        int gy1=h/2;

        if(mtg->m1.t1<=0)
        {
            if(a2z==1)
            {
                mile = mtg->prj.mile1;
                road_l2xy(cl,mile,&x[0],&y[0],&alf1);
                road_l2h(cl,mile,&z[0],&alf2);
            }
            else
            {
                mile = mtg->prj.mile2;
                road_l2xy(cl,mile,&x[0],&y[0],&alf1);
                alf1 = alf1+PI;
                if(alf1>2.0*PI) alf1 = alf1-2.0*PI;
                road_l2h(cl,mile,&z[0],&alf2);
                alf2 = alf2+PI;
                if(alf2>2.0*PI) alf2 = alf2-2.0*PI;
            }
        }
        else
        {
            if(a2z==1)
            {
                road_l2xy(cl,mile,&x[0],&y[0],&alf1);
                road_l2h(cl,mile,&z[0],&alf2);
            }
            else
            {
                road_l2xy(cl,mile,&x[0],&y[0],&alf1);
                alf1 = alf1+PI;
                if(alf1>2.0*PI) alf1 = alf1-2.0*PI;
                road_l2h(cl,mile,&z[0],&alf2);
                alf2 = alf2+PI;
                if(alf2>2.0*PI) alf2 = alf2-2.0*PI;
            }
        }
        h_element* he;
        v_element* ve;
        if(nh>2)
        {
            sr1 = 1.5;
            sr2 = 0.75;
            he = road_horizon_chain(cl,mile,0);
            if(he)
            {
                if(he->radius>300 && he->radius<=1500)
                {
                    sr1 = sr1+(he->radius-300)*0.5/1200;
                }
                else if(he->radius>1500 && he->radius<=3000)
                {
                    sr1 = sr1+0.5+(he->radius-1500)*1.0/1500;
                }
                else if(he->radius > 3000)
                {
                    sr1 = 3.0;
                }
                else
                {
                    sr1 = sr1+(he->radius-300)*1/300;
                }
            }
            ve=road_vertical_chain(cl,mile,0);
            if(ve)
            {
                double slope = 0.0;
                road_l2h(&mtg->r,mile,0,&slope);
                slope=slope*1000.0;
                if(slope<=5)
                {
                    sr2 = 1.25;
                }
                else if(slope>5 && slope<=15)
                {
                    sr2 = 1.25-0.5*(slope-5)/10;
                }
                else if(slope>15 && slope<=30)
                {
                    sr2 = 0.75-0.25*(slope-15)/15;
                }
                else
                {
                    sr2 = 0.5;
                }
            }
            for(int i=1;i<6;i++)
            {
                x[i] = x[0]+(sw*i)*cos(alf1);
                y[i] = y[0]+(sw*i)*sin(alf1);
                //fprintf(fp,"x[%d]=%.4f,y[%d]=%.4f\n",i,x[i],i,y[i]);
                //fprintf(fp,"sr1=%.12f\n",sr1);
                val=0;
                road_xy2l(cl,x[i],y[i],0,0,0,0,&val);
                //fprintf(fp,"val=%.12f\n",val);
                x[i]=val;

                if(a2z==1)
                {
                    x[i] = -x[i]*1000.0*sr1+(double)gx1;
                }
                else
                {
                    x[i] = x[i]*1000.0*sr1+(double)gx1;
                }
                if(nv>2)
                {
                    z[i] = z[0];
                    if(a2z==1)
                    {
                        road_l2h(cl,mile+sw*i,&ph,0);
                        //fprintf(fp,"ph:%.4f\n",ph);
                    }
                    else
                    {
                        road_l2h(cl,mile-sw*i,&ph,0);

                    }
                    y[i] = (z[i]-ph)*1000.0*sr2+gy1;

                }
                else
                {
                    y[i] = gy1;
                }
                //fprintf(fp,"2:x[%d]=%.4f,y[%d]=%.4f\n",i,x[i],i,y[i]);
            }
        }
        else
        {
            for(int i=1;i<6;i++)
            {
                x[i] = gx1;
                if(nv>2)
                {
                    ve=road_vertical_chain(cl,mtg->m1.headc,0);
                    if(ve)
                    {
                        if(ve->type == ROAD_TYPE_ARC)
                        {
                            z[i] = z[0]+(sw*i)*sin(alf2);
                        }
                        else
                        {
                            z[i] = z[0];
                        }
                        if(mtg->prj.a2z==1)
                        {
                            road_l2h(cl,mile+sw*i,&ph,0);
                        }
                        else
                        {
                            road_l2h(cl,mile-sw*i,&ph,0);
                        }
                        if(ve->type == ROAD_TYPE_ARC)
                        {
                            y[i] = (z[i]-ph)*1000.0+gy1;
                        }
                        else
                        {
                            y[i] = (z[i]-ph)*1000.0/2+gy1;
                        }
                    }
                }
                else
                {
                    y[i] = gy1;
                }
            }
        }

        wxPoint pts[6][1440];
        x[0] = gx1;
        y[0] = gy1;
        double d1;
        double alf3;
        double alf;
        int x2,y2;

        int k;
        for(int i=0;i<6;i++)
        {
            if(i==0)
            {
                memDC.SetPen(wxPen(wxColor(237,248,254),1));
                memDC.SetBrush(wxBrush(wxColor(237,248,254)));
            }
            else if(i==1)
            {
                memDC.SetPen(wxPen(wxColor(188,218,244),1));
                memDC.SetBrush(wxBrush(wxColor(188,218,244)));
            }
            else if(i==2)
            {
                memDC.SetPen(wxPen(wxColor(160,200,235),1));
                memDC.SetBrush(wxBrush(wxColor(160,200,235)));
            }
            else if(i==3)
            {
                memDC.SetPen(wxPen(wxColor(144,189,225),1));
                memDC.SetBrush(wxBrush(wxColor(144,189,225)));
            }
            else if(i==4)
            {
                memDC.SetPen(wxPen(wxColor(129,178,210),1));
                memDC.SetBrush(wxBrush(wxColor(129,178,210)));
            }
            else if(i==5)
            {
                memDC.SetPen(wxPen(wxColor(119,172,204),1));
                memDC.SetBrush(wxBrush(wxColor(119,172,204)));
            }

            int inter = 0;
            double A[5] = {0.0};
            double B[5] = {0.0};
            for(int m=0;m<i;m++)
            {
                d1 = sqrt((x[i]-x[m])*(x[i]-x[m])+(y[i]-y[m])*(y[i]-y[m]));
                //fprintf(fp,"d1:%d,%d,%.12f,%d,%d\n",m,i,d1,r[m],r[i]);
                if(d1>(double)(r[m]-r[i]))
                {
                    alf1 = atan2(y[m]-y[i],x[m]-x[i]);
                    //fprintf(fp,"t1:%.12f,%.12f,%.12f,%.12f,%.12f\n",x[m],y[m],x[i],y[i],alf1);
                    if(alf1<0.0) alf1 = alf1+2.0*PI;
                    alf2 = acos((d1*d1+r[i]*r[i]-r[m]*r[m])/(2*d1*r[i]));

                    A[inter] = alf1+alf2;
                    //fprintf(fp,"t1:%.12f,%.12f,%.12f\n",alf1,alf2,A[inter]);
                    if(A[inter] > 2.0*PI) A[inter] = A[inter]-2.0*PI;
                    B[inter] = alf1-alf2;
                    //fprintf(fp,"t1:%.12f,%.12f,%.12f\n",alf1,alf2,A[inter]);
                    if(B[inter] < 0) B[inter] = B[inter]+2.0*PI;

                    inter++;
                }
            }
            alf1 = A[0];
            alf2 = B[0];

            for(int n=0;n<inter;n++)
            {
                if(alf1>A[n] && alf1-A[n]<PI)
                {
                    alf1 = A[n];
                }

                if(alf1<A[n] && A[n]-alf1>PI)
                {
                    alf1 = A[n];
                }


                if(alf2<B[n] && B[n]-alf2<PI)
                {
                    alf2 = B[n];
                }
                if(alf2>B[n] && alf2-B[n]>PI)
                {
                    alf2 = B[n];
                }
            }

            for(int j=0;j<1440;j++)
            {
                alf = PI*j/720;
                x2 = x[i]+r[i]*cos(alf);
                y2 = y[i]+r[i]*sin(alf);
                //fprintf(fp,"x[%d]=%.4f,y[%d]=%.4f\n",i,x[i],i,y[i]);
                if(i==0)
                {
                    pts[i][j].x = x2;
                    pts[i][j].y = y2;
                }
                else
                {
                    alf3 = atan2(y2-y[i-1],x2-x[i-1]);
                    if(alf3<0.0) alf3 = alf3+2.0*PI;
                    k = alf3/(PI/720);
                    if(inter == 0)
                    {
                        pts[i][j].x = x2;
                        pts[i][j].y = y2;
                    }
                    else
                    {
                        if(alf1<=alf2)
                        {
                            if(alf>alf1 && alf<alf2)
                            {
                                pts[i][j].x = pts[i-1][k].x;
                                pts[i][j].y = pts[i-1][k].y;
                            }
                            else
                            {
                                pts[i][j].x = x2;
                                pts[i][j].y = y2;
                            }
                        }
                        else
                        {
                            if(alf>alf1 || alf<alf2)
                            {
                                pts[i][j].x = pts[i-1][k].x;
                                pts[i][j].y = pts[i-1][k].y;
                            }
                            else
                            {
                                pts[i][j].x = x2;
                                pts[i][j].y = y2;
                            }
                        }
                    }
                }
            }
            memDC.DrawPolygon(1440,pts[i]);
            memDC.SetPen(wxPen(wxColor(70,75,80),2));
            memDC.SetBrush(*wxTRANSPARENT_BRUSH);
            memDC.DrawCircle(x[0],y[0],r[0]+1);
        }

        memDC.SetPen(wxPen(wxColor(70,75,80),2));
        memDC.DrawLine(gx1-r[0],gy1,gx1+r[0],gy1);
        memDC.DrawLine(gx1,gy1-r[0],gx1,gy1+r[0]);
        memDC.SetPen(wxPen(wxColor(255,20,20),1,wxLONG_DASH));
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);

        memDC.DrawCircle(gx1,gy1,5.0*cell);
        //if(maxdev==50) memDC.DrawCircle(gx1,gy1,4.0*cell);
        //else if(maxdev==100) memDC.DrawCircle(gx1,gy1,2.0*cell);
        //else if(maxdev==150) memDC.DrawCircle(gx1,gy1,4.0*cell/3.0);
        //else memDC.DrawCircle(gx1,gy1,1.0*cell);

        memDC.SetPen(wxPen(wxColor(20,20,20)));
        memDC.DrawLine(gx1-cell,gy1-4,gx1-cell,gy1+4);
        memDC.DrawLine(gx1-2*cell,gy1-4,gx1-2*cell,gy1+4);
        memDC.DrawLine(gx1-3*cell,gy1-4,gx1-3*cell,gy1+4);
        memDC.DrawLine(gx1-4*cell,gy1-4,gx1-4*cell,gy1+4);
        memDC.DrawLine(gx1-5*cell,gy1-4,gx1-5*cell,gy1+4);
        memDC.DrawLine(gx1+cell,gy1-4,gx1+cell,gy1+4);
        memDC.DrawLine(gx1+2*cell,gy1-4,gx1+2*cell,gy1+4);
        memDC.DrawLine(gx1+3*cell,gy1-4,gx1+3*cell,gy1+4);
        memDC.DrawLine(gx1+4*cell,gy1-4,gx1+4*cell,gy1+4);
        memDC.DrawLine(gx1+5*cell,gy1-4,gx1+5*cell,gy1+4);
        memDC.DrawLine(gx1-4,gy1-cell,gx1+4,gy1-cell);
        memDC.DrawLine(gx1-4,gy1-2*cell,gx1+4,gy1-2*cell);
        memDC.DrawLine(gx1-4,gy1-3*cell,gx1+4,gy1-3*cell);
        memDC.DrawLine(gx1-4,gy1-4*cell,gx1+4,gy1-4*cell);
        memDC.DrawLine(gx1-4,gy1-5*cell,gx1+4,gy1-5*cell);
        memDC.DrawLine(gx1-4,gy1+cell,gx1+4,gy1+cell);
        memDC.DrawLine(gx1-4,gy1+2*cell,gx1+4,gy1+2*cell);
        memDC.DrawLine(gx1-4,gy1+3*cell,gx1+4,gy1+3*cell);
        memDC.DrawLine(gx1-4,gy1+4*cell,gx1+4,gy1+4*cell);
        memDC.DrawLine(gx1-4,gy1+5*cell,gx1+4,gy1+5*cell);

        memDC.SetFont(eng1);
        if(maxdev>100) memDC.SetTextForeground(wxColor(255,0,0));
        else memDC.SetTextForeground(wxColor(28,28,28));

        memDC.DrawLabel(wxString::Format(_("%d"),maxdev),wxRect(gx1-5*cell,gy1+4,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(wxString::Format(_("%d"),maxdev),wxRect(gx1+5*cell,gy1+4,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(wxString::Format(_("%d"),maxdev),wxRect(gx1+4,gy1+5*cell,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),maxdev),wxRect(gx1+4,gy1-5*cell,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        ///盾构机图形
        double x6;
        double y6;
        double x5;
        double y5;
        double ps=0.0;
        if(mtg->tbm.type==0)
        {
            x6=gx1+tailh*s;
            y6=gy1-tailv*s;
            x5=gx1+headh*s;
            y5=gy1-headv*s;
//            FILE* fp=fopen("D://onpaintmetrofig1.log","w");
//            if(fp)
//            {
//                fprintf(fp,"headh:%d,headv:%d,tailh:%d,tailv:%d\n",headh,headv,tailh,tailv);fflush(fp);
//            }
//            fclose(fp);
            /*if(abs(headh-tailh)>abs(headv-tailv))
            {
                ps=abs(headh-tailh)*1.0/maxdev;
            }
            else
            {
                ps=abs(headv-tailv)*1.0/maxdev;
            }*/
        }
        else
        {
            x6=gx1+midh*s;
            y6=gy1-midv*s;
            x5=gx1+headh*s;
            y5=gy1-headv*s;
            /*if(abs(headh-midh)>abs(headv-midv))
            {
                ps=abs(headh-midh)*1.0/maxdev;
            }
            else
            {
                ps=abs(headv-midv)*1.0/maxdev;
            }*/
        }
        ps=0.32;
        //if(ps>1.0) ps=1.0;

        double cor[4][2];
        double cor1[4][2];
        double cosa[3],sina[3];
        double ms[3];
        double rx[4]={0};
        double ry[4]={0};
        double rz[4]={0};
        double azi = atan(htrend/1000.0);
        double pitch = atan(vtrend/1000.0);
        double roll=mtg->m1.inc1[0]*PI/180.0;
        //trace(0,"metro:roll=%.4f,y=%.4f\n",mtg->m.inc1[0],vtrend);
        ms[0] = 6.0;
        ms[1] = 6.0;
        ms[2] = 6.0;
        if(fabs(pitch)>0.00872664625997165 && fabs(pitch)<=0.0174532925199433)
        {
            ms[1] = ms[1]-1.0*(fabs(pitch)-0.00872664625997165)/0.00872664625997165;
        }
        else if(fabs(pitch)>0.0174532925199433 && fabs(pitch)<=0.0261799387799149)
        {
            ms[1] = ms[1]-1.0-0.5*(fabs(pitch)-0.0174532925199433)/0.00872664625997165;
        }
        else if(fabs(pitch)>0.0261799387799149 && fabs(pitch)<=0.0349065850398866)
        {
            ms[1] = ms[1]-1.0-0.5-0.5*(fabs(pitch)-0.0261799387799149)/0.00872664625997165;
        }
        else if(fabs(pitch)>0.0349065850398866 && fabs(pitch)<=0.0436332312998582)
        {
            ms[1] = ms[1]-1.0-0.5-0.5-0.5*(fabs(pitch)-0.0349065850398866)/0.00872664625997165;
        }
        else if(fabs(pitch)>0.0436332312998582 && fabs(pitch)<=0.0523598775598299)
        {
            ms[1] = ms[1]-1.0-0.5-0.5-0.5-0.5*(fabs(pitch)-0.0436332312998582)/0.00872664625997165;
        }
        else if(fabs(pitch) > 0.0523598775598299)
        {
            ms[1] = 3.0;
        }
        cosa[1] = cos(pitch*ms[1]);
        sina[1] = sin(pitch*ms[1]);

        if(fabs(roll)>0.00872664625997165 && fabs(roll)<=0.0174532925199433)
        {
            ms[0] = ms[0]-1.0*(fabs(roll)-0.00872664625997165)/0.00872664625997165;
        }
        else if(fabs(roll)>0.0174532925199433 && fabs(roll)<=0.0261799387799149)
        {
            ms[0] = ms[0]-1.0-0.5*(fabs(roll)-0.0174532925199433)/0.00872664625997165;
        }
        else if(fabs(roll)>0.0261799387799149 && fabs(roll)<=0.0349065850398866)
        {
            ms[0] = ms[0]-1.0-0.5-0.5*(fabs(roll)-0.0261799387799149)/0.00872664625997165;
        }
        else if(fabs(roll)>0.0349065850398866 && fabs(roll)<=0.0436332312998582)
        {
            ms[0] = ms[0]-1.0-0.5-0.5-0.5*(fabs(roll)-0.0349065850398866)/0.00872664625997165;
        }
        else if(fabs(roll)>0.0436332312998582 && fabs(roll)<=0.0523598775598299)
        {
            ms[0] = ms[0]-1.0-0.5-0.5-0.5-0.5*(fabs(roll)-0.0436332312998582)/0.00872664625997165;
        }
        else if(fabs(roll) > 0.0523598775598299)
        {
            ms[0] = 3.0;
        }
        cosa[0] = cos(roll*ms[0]);
        sina[0] = sin(roll*ms[0]);
        //trace(0,"fig1:roll=%.4f,ms=%.4f\n",roll,ms[0]);

        if(fabs(azi)>0.00872664625997165 && fabs(azi)<=0.0174532925199433)
        {
            ms[2] = ms[2]-1.0*(fabs(azi)-0.00872664625997165)/0.00872664625997165;
        }
        else if(fabs(azi)>0.0174532925199433 && fabs(azi)<=0.0261799387799149)
        {
            ms[2] = ms[2]-1.0-0.5*(fabs(azi)-0.0174532925199433)/0.00872664625997165;
        }
        else if(fabs(azi)>0.0261799387799149 && fabs(azi)<=0.0349065850398866)
        {
            ms[2] = ms[2]-1.0-0.5-0.5*(fabs(azi)-0.0261799387799149)/0.00872664625997165;
        }
        else if(fabs(azi)>0.0349065850398866 && fabs(azi)<=0.0436332312998582)
        {
            ms[2] = ms[2]-1.0-0.5-0.5-0.5*(fabs(azi)-0.0349065850398866)/0.00872664625997165;
        }
        else if(fabs(azi)>0.0436332312998582 && fabs(azi)<=0.0523598775598299)
        {
            ms[2] = ms[2]-1.0-0.5-0.5-0.5-0.5*(fabs(azi)-0.0436332312998582)/0.00872664625997165;
        }
        else if(fabs(azi) > 0.0523598775598299)
        {
            ms[2] = 3.0;
        }
        cosa[2] = cos(azi*ms[2]);
        sina[2] = sin(azi*ms[2]);

        rx[0] = 0.0;
        ry[0] = -1.5*cell-3.0*ps*cell;
        rz[0] = 0.0;
        rx[1] = 0.0;
        ry[1] = -ry[0];
        rz[1] = 0.0;
        rx[2] = -1.5*cell-3.0*ps*cell;
        ry[2] = 0.0;
        rz[2] = 0.0;
        rx[3] = -rx[2];
        ry[3] = 0.0;
        rz[3] = 0.0;
        //trace(0,"fig1:rx1=%.4f,tx2=%.4f,rx3=%.4f\n",rx[0],rx[1],rx[2]);
        //trace(0,"fig1:rx1=%.4f,tx2=%.4f,rx3=%.4f\n",ry[0],ry[1],ry[2]);
        //trace(0,"fig1:rx1=%.4f,tx2=%.4f,rx3=%.4f\n",rz[0],rz[1],rz[2]);
        ///转动角修正
        rx[0] = (1.5+3*ps)*cell*sina[0];
        ry[0] = -(1.5+3*ps)*cell*cosa[0];
        rx[1] = -rx[0];
        ry[1] = -ry[0];
        rx[2] = -(1.5+3*ps)*cell*cosa[0];
        ry[2] = -(1.5+3*ps)*cell*sina[0];
        rx[3] = -rx[2];
        ry[3] = -ry[2];
        //trace(0,"fig1:rx1=%.4f,tx2=%.4f,rx3=%.4f\n",rx[0],rx[1],rx[2]);
        //trace(0,"fig1:rx1=%.4f,tx2=%.4f,rx3=%.4f\n",ry[0],ry[1],ry[2]);
        //trace(0,"fig1:sina=%.4f,cosa=%.4f\n",sina[0],cosa[0]);
        ///方位角修正
        rx[0] = rx[0]*cosa[2];
        rz[0] = -rx[0]*sina[2];
        rx[1] = -rx[0];
        rz[1] = -rx[1]*sina[2];
        rx[2] = rx[2]*cosa[2];
        rz[2] = -rx[2]*sina[2];
        rx[3] = -rx[2];
        rz[3] = -rx[3]*sina[2];
        ///俯仰角修正
        rx[0] = rx[0]+ry[0]*sina[1]*sina[2];
        rz[0] = rz[0]+ry[0]*sina[1]*cosa[2];
        ry[0] = ry[0]*cosa[1];
        rx[1] = rx[1]+ry[1]*sina[1]*sina[2];
        rz[1] = rz[1]+ry[1]*sina[1]*cosa[2];
        ry[1] = -ry[0];
        rx[2] = rx[2]+ry[2]*sina[1]*sina[2];
        rz[2] = rz[2]+ry[2]*sina[1]*cosa[2];
        ry[2] = ry[2]*cosa[1];
        rx[3] = rx[3]+ry[3]*sina[1]*sina[2];
        rz[3] = rz[3]+ry[3]*sina[1]*cosa[2];
        ry[3] = -ry[2];

        ///up
        cor[0][0]=x6+rx[0];
        cor[0][1]=y6+ry[0];
        ///down
        cor[1][0]=x6+rx[1];
        cor[1][1]=y6+ry[1];
        ///left
        cor[2][0]=x6+rx[2];
        cor[2][1]=y6+ry[2];
        ///right
        cor[3][0]=x6+rx[3];
        cor[3][1]=y6+ry[3];


        wxBrush posBrush[4];
        //posBrush[0]=wxBrush(wxColor(254,254,0));
        //posBrush[1]=wxBrush(wxColor(234,234,0));
        //posBrush[2]=wxBrush(wxColor(214,214,0));
        //posBrush[3]=wxBrush(wxColor(194,194,0));
        posBrush[0]=wxBrush(wxColor(110,140,155));
        posBrush[1]=wxBrush(wxColor(100,120,135));
        posBrush[2]=wxBrush(wxColor(80,100,110));
        posBrush[3]=wxBrush(wxColor(85,105,115));
        //wxPen posPen(wxColor(0,0,204));
        wxPen posPen(wxColor(58,68,88));
        //memDC.SetPen(posPen);
        int index[4]={0,1,2,3};
        double a,b;
        a = (y5-y6)*1.0/(x5-x6);
        b = y5-a*x5;
        h1 = a*cor[2][0]+b;
        if(x5<x6)
        {
            if(y5<y6)
            {
                if(h1>cor[2][1])
                {
                    index[0]=0;
                    index[1]=2;
                    index[2]=3;
                    index[3]=1;
                }
                else
                {
                    index[0]=1;
                    index[1]=3;
                    index[2]=0;
                    index[3]=2;
                }
            }
            else
            {
                if(h1>cor[2][1])
                {
                    index[0]=0;
                    index[1]=3;
                    index[2]=2;
                    index[3]=1;
                }
                else
                {
                    index[0]=3;
                    index[1]=1;
                    index[2]=2;
                    index[3]=0;
                }
            }
        }
        else
        {
            if(y5<y6)
            {
                if(h1>cor[2][1])
                {
                    index[0]=1;
                    index[1]=2;
                    index[2]=0;
                    index[3]=3;
                }
                else
                {
                    index[0]=2;
                    index[1]=0;
                    index[2]=1;
                    index[3]=3;
                }
            }
            else
            {
                if(h1>cor[2][1])
                {
                    index[0]=2;
                    index[1]=0;
                    index[2]=1;
                    index[3]=3;
                }
                else
                {
                    index[0]=0;
                    index[1]=2;
                    index[2]=1;
                    index[3]=3;
                }
            }
        }

        //up
        rx[0]=(cor[0][0]-x6)*1/5;
        ry[0]=(cor[0][1]-y6)*1/5;
        //down
        rx[1]=(cor[1][0]-x6)*1/5;
        ry[1]=(cor[1][1]-y6)*1/5;
        //left
        rx[2]=(cor[2][0]-x6)*1/5;
        ry[2]=(cor[2][1]-y6)*1/5;
        //right
        rx[3]=(cor[3][0]-x6)*1/5;
        ry[3]=(cor[3][1]-y6)*1/5;

        double px[4];
        double py[4];
        for(int i=0;i<4;i++)
        {
            int j=index[i];
            px[i]=cor[j][0];
            py[i]=cor[j][1];
        }

        memDC.SetPen(wxPen(wxColor(215,57,28),3));
        memDC.DrawLine(rx[0]+x5,ry[0]+y5,rx[1]+x5,ry[1]+y5);
        memDC.DrawLine(rx[2]+x5,ry[2]+y5,rx[3]+x5,ry[3]+y5);
        //trace(0,"fig1:%.1f,%.1f,%.1f,%.1f\n",rx[0],ry[0],rx[1],ry[1]);
        //trace(0,"fig1:%.1f,%.1f,%.1f,%.1f\n",rx[2],ry[2],rx[3],ry[3]);
        memDC.SetPen(posPen);
        wxPoint tbm_pts[3];
        tbm_pts[1].x=x6;
        tbm_pts[1].y=y6;
        tbm_pts[2].x=x5;
        tbm_pts[2].y=y5;
        for(int i=0;i<4;i++)
        {
            int j=index[i];
            //if(i==1) continue;
            memDC.SetBrush(posBrush[j]);
            tbm_pts[0].x=px[i];
            tbm_pts[0].y=py[i];
            if(mtg->iset.tbm3d==0) memDC.DrawPolygon(3,tbm_pts);
        }

        memDC.SetPen(wxPen(wxColor(0,1,219),3));
        memDC.DrawLine(rx[0]+x6,ry[0]+y6,rx[1]+x6,ry[1]+y6);
        memDC.DrawLine(rx[2]+x6,ry[2]+y6,rx[3]+x6,ry[3]+y6);
        //trace(0,"fig1:%.1f,%.1f,%.1f,%.1f\n",rx[0]+x6,ry[0]+y6,rx[1]+x6,ry[1]+y6);
        //trace(0,"fig1:%.1f,%.1f,%.1f,%.1f\n",rx[2]+x6,ry[2]+y6,rx[3]+x6,ry[3]+y6);
        /*if(mtg->iset.idrv==1)
        {
            memDC.SetPen(wxPen(wxColor(255,0,0)));
            memDC.SetBrush(*wxWHITE_BRUSH);
            x5=gx1-r[0]+15;
            y5=gy1;
            memDC.DrawCircle(x5,y5,15);

            x5=gx1+r[0]-15;
            y5=gy1;
            memDC.DrawCircle(x5,y5,15);

            x5=gx1;
            y5=gy1-r[0]+15;
            memDC.DrawCircle(x5,y5,15);

            x5=gx1;
            y5=gy1+r[0]-15;
            memDC.DrawCircle(x5,y5,15);
        }*/

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

#define NANTONG 0

void mtg_t_cliFrame::OnPaintMetroFig2(wxPaintEvent& event)
{
    wxPaintDC dc(metroFig2);
    int w,h;
    GetSize(&w,&h);
    double sx,sy,sxy;
	sx = w/1024.0;
	sy = h/768.0;
	if(sx>sy)
	{
		sxy = sy;
	}
	else
	{
		sxy = sx;
	}

    metroFig2->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        ///background
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);
        ///字体
        wxFont chs(10*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng1(12*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        wxFont eng2(15*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        wxFont chs1(11*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=h/2;
        PaintHorizon(&memDC, wxRect(x1,y1,w1,h1),maxdev);
        y1=h/2;
        PaintVertical(&memDC, wxRect(x1,y1,w1,h1),maxdev);

        ///偏差及趋势
        memDC.SetBrush(wxBrush(wxColor(204,233,177)));
        memDC.SetPen(wxPen(wxColor(204,233,177)));
        memDC.SetTextForeground(wxColor(28,28,28));
        memDC.SetFont(chs);
        y1=0;
        if(mtg->tbm.type==0)
        {
            memDC.DrawLabel(_("切口 "),wxRect(x1+w1*1/2+32*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("盾尾 "),wxRect(x1+32*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("水平偏航"),wxRect(x1+32*sxy,y1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("切口 "),wxRect(x1+w1*1/2+32*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("盾尾 "),wxRect(x1+32*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("垂直偏航"),wxRect(x1+32*sxy,y1+h1*2-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetTextForeground(wxColor(0,0,0));
            memDC.SetFont(eng2);
            memDC.DrawLabel(wxString::Format(_("%d"),headh),wxRect(x1+w1/2+80*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),tailh),wxRect(x1+80*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),headv),wxRect(x1+w1/2+80*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),tailv),wxRect(x1+80*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            memDC.SetFont(eng1);
            if(tbmlen==0.0)
            {
                memDC.DrawLabel(wxString::Format(_("%d"),0.0)+_(" mm/m"),wxRect(x1+w1/2+32*sxy,y1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%d"),0.0)+_(" mm/m"),wxRect(x1+w1/2+32*sxy,y1+h1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(wxString::Format(_("%.1f"),htrend)+_(" mm/m"),wxRect(x1+w1/2+32*sxy,y1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%.1f"),vtrend)+_(" mm/m"),wxRect(x1+w1/2+32*sxy,y1+h1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            memDC.DrawLabel(_("前"),wxRect(x1+w1*2/3+10*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("中"),wxRect(x1+w1/3+10*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("后"),wxRect(x1+10*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("水平偏航"),wxRect(x1+10*sxy,y1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("前"),wxRect(x1+w1*2/3+10*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("中"),wxRect(x1+w1/3+10*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("后"),wxRect(x1+10*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("垂直偏航"),wxRect(x1+10*sxy,y1+h1*2-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetFont(eng2);
            //wxMessageBox(wxString::Format(_("%d"),headh));
            memDC.DrawLabel(wxString::Format(_("%d"),headh),wxRect(x1+w1*2/3+32*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),midh),wxRect(x1+w1/3+32*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),tailh),wxRect(x1+32*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),headv),wxRect(x1+w1*2/3+32*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),midv),wxRect(x1+w1/3+32*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),tailv),wxRect(x1+32*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetFont(eng1);

            if(tbmlen==0.0)
            {
                memDC.DrawLabel(wxString::Format(_("%d"),0.0)+_(" mm/m"),wxRect(x1+w1/2+32*sxy,y1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%d"),0.0)+_(" mm/m"),wxRect(x1+w1/2+32*sxy,y1+h1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(NANTONG)
                {
                    memDC.SetFont(chs1);
                    memDC.DrawLabel(wxString::Format(_("后:%6.1f"),htrend2)+_(" mm/m"),wxRect(x1+w1/3,y1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    memDC.DrawLabel(wxString::Format(_("后:%6.1f"),vtrend2)+_(" mm/m"),wxRect(x1+w1/3,y1+h1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    memDC.DrawLabel(wxString::Format(_("前:%6.1f"),htrend)+_(" mm/m"),wxRect(x1+w1*2/3,y1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    memDC.DrawLabel(wxString::Format(_("前:%6.1f"),vtrend)+_(" mm/m"),wxRect(x1+w1*2/3,y1+h1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(wxString::Format(_("%.1f"),htrend)+_(" mm/m"),wxRect(x1+w1/2+32*sxy,y1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    memDC.DrawLabel(wxString::Format(_("%.1f"),vtrend)+_(" mm/m"),wxRect(x1+w1/2+32*sxy,y1+h1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_cliFrame::OnPaintMetroFig3(wxPaintEvent& event)
{
    wxPaintDC dc(metroFig3);
    int w,h;
    GetSize(&w,&h);
    double sx,sy,sxy;
	sx = w/1024.0;
	sy = h/768.0;
	if(sx>sy)
	{
		sxy = sy;
	}
	else
	{
		sxy = sx;
	}

    metroFig3->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        ///background
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);
        ///字体
        wxFont chs(10*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng1(12*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        wxFont eng2(15*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);

        wxString valstr;

        ///环号
        int x1,y1,w1,h1;
        x1=-1;
        y1=0;
        w1=w;
        h1=h/4;
        memDC.SetPen(wxPen(wxColor(105,105,105)));
        memDC.SetBrush(wxBrush(wxColor(248,248,248)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        int gx1,gy1,gw1,gh1;
        gx1=10*sx;
        gy1=15*sxy;
        gw1=w1-10*sx-10*sx;
        gh1=35*sxy;
//        button[ID_BTN_SEG].x=gx1;
//        button[ID_BTN_SEG].y=gy1;
//        button[ID_BTN_SEG].width=gw1;
//        button[ID_BTN_SEG].height=gh1;
//        if(motion==ID_BTN_SEG)
//        {
//            memDC.SetPen(wxPen(wxColor(104,104,104)));
//            memDC.SetBrush(wxBrush(wxColor(254,254,0)));
//        }
//        else
//        {
//            memDC.SetPen(wxPen(wxColor(104,104,104)));
//            memDC.SetBrush(wxBrush(wxColor(204,251,200)));
//        }
//        memDC.DrawRoundedRectangle(button[ID_BTN_SEG],3);

        //memDC.SetPen(wxPen(wxColor(140,144,147)));
        //memDC.DrawRoundedRectangle(gx1,gy1,gw1,gh1,3);
        memDC.SetFont(eng2);
        memDC.SetTextForeground(wxColor(25,35,45));
        ///memDC.DrawLabel(wxString::Format(_("%d"),mtg->m1.iseg)+_(" 环"),wxRect(gx1,gy1,gw1,gh1),wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("米度测量"),wxRect(gx1,gy1,gw1,gh1),wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        int gx2,gy2,gw2,gh2;
        gx2=10*sx;
        gy2=60*sxy;
        gw2=w1-20*sx;
        gh2=h1-75*sxy;
        memDC.SetPen(wxPen(wxColor(140,144,147)));
        memDC.SetBrush(wxBrush(wxColor(212,218,224)));
        ///memDC.DrawRectangle(gx2,gy2,gw2,gh2);

        double per = fabs(mtg->m1.headc-mtg->snum.mile);
        if(per>mtg->segset.L*2.0) per=0.0;
        wxFont eng5(15*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(eng5);
        ///memDC.SetFont(eng1);
        valstr=wxString::Format(_("%d"),(int)(per*1000));
        per = per/mtg->segset.L;
        if(per>1.0) per=1;
        memDC.SetPen(wxPen(wxColor(234,251,230)));
        memDC.SetBrush(wxBrush(wxColor(234,251,230)));
        gx2=gx2+1;
        gy2=gy2+1;
        gw2=gw2-2;
        gh2=gh2-2;
        memDC.DrawRectangle(gx2,gy2,gw2*per,gh2);
        ///memDC.DrawLabel(valstr,wxRect(gx2,gy2,gw2,gh2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::FromUTF8(mtg->tbm.name),wxRect(gx2,gy2,gw2,gh2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        ///转动角
        y1 = y1+h1;
        memDC.SetPen(wxPen(wxColor(105,105,105)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(28,28,28));
        memDC.DrawLabel(_("转动角"),wxRect(x1,y1,w1,30*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetFont(eng1);
        if(mtg->iset.unit==0)
        {
            memDC.DrawLabel(_("[ mm/m ]"),wxRect(x1,y1+15*sxy,w1,35*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("[  °  ]"),wxRect(x1,y1+15*sxy,w1,35*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetFont(eng2);
        memDC.SetTextForeground(wxColor(25,35,45));
        if(mtg->iset.unit==0)
        {
            memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->m1.inc1[0]*PI/180.0)*1000.0),wxRect(x1,y1+33*sxy,w1,h1-33*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->m1.inc1[0]),wxRect(x1,y1+33*sxy,w1,h1-33*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }


        ///俯仰角
        y1 = y1+h1;
        memDC.SetPen(wxPen(wxColor(105,105,105)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(28,28,28));
        memDC.DrawLabel(_("俯仰角"),wxRect(x1,y1,w1,30*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetFont(eng1);
        if(mtg->iset.unit==0)
        {
            memDC.DrawLabel(_("[ mm/m ]"),wxRect(x1,y1+15*sxy,w1,35*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("[  °  ]"),wxRect(x1,y1+15*sxy,w1,35*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetFont(eng2);
        memDC.SetTextForeground(wxColor(25,35,45));
        if(mtg->iset.unit==0)
        {
            memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->m1.inc1[1]*PI/180.0)*1000.0),wxRect(x1,y1+33*sxy,w1,h1-33*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->m1.inc1[1]),wxRect(x1,y1+33*sxy,w1,h1-33*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        y1 = y1+h1;
        memDC.SetPen(wxPen(wxColor(112,112,112)));
        memDC.SetBrush(wxBrush(wxColor(248,248,248)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(28,28,28));
        memDC.DrawLabel(_("切口里程"),wxRect(x1,y1,w1,30*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("盾尾里程"),wxRect(x1,y1+50*sxy,w1,30*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetFont(eng1);
        memDC.DrawLabel(wxString::Format(_("%.2f"),headc),wxRect(x1,y1+25*sxy,w1,25*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%.2f"),tailc),wxRect(x1,y1+75*sxy,w1,25*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_cliFrame::OnPaintMetric(wxPaintEvent& event)
{
    wxPaintDC dc(panelMetric);

    int w,h;
    GetSize(&w,&h);
    double sx,sy,sxy;
	sx = w/1024.0;
	sy = h/768.0;
	if(sx>sy)
	{
		sxy = sy;
	}
	else
	{
		sxy = sx;
	}
	///调试
    GetMetro();
    //trace(0,"metric:headh=%d,headv=%d\n",headh,headv);
    panelMetric->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        ///background
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_cliFrame::OnMotionSegment(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_SEG].y && y<button[ID_BTN_SEG].y+button[ID_BTN_SEG].height)
    {
        if(x>button[ID_BTN_SEG].x && x<button[ID_BTN_SEG].x+button[ID_BTN_SEG].width)
        {
            motion=ID_BTN_SEG;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }
    metroFig3->Refresh();
}

void mtg_t_cliFrame::OnLeaveSegment(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    metroFig3->Refresh();
}

void mtg_t_cliFrame::SetSegment(wxMouseEvent& event)
{
    wxPoint pt;
    pt = event.GetPosition();
    int w,h;
    metroFig3->GetSize(&w,&h);
    if(pt.x>0 && pt.x< w && pt.y> 0 && pt.y < h/4)
    {
        PasswordDialog dlg(this);
        dlg.TextPassword->SetFocus();
        dlg.Center();

        if(dlg.ShowModal()==wxID_OK)
        {
            int i;
            for(i=0;i<mtg->nuser;i++)
            {
                if(dlg.TextPassword->GetValue().Cmp(wxString((const char*)mtg->user[i].password,wxConvLocal))==0)
                {
                    break;
                }
            }
            if(i<mtg->nuser)
            {
                mtg->onLine = i;
                ModifySegDialog dlg(this);
                dlg.Center();
                dlg.ShowModal();
                metroFig3->Refresh();
                //panelMetric->RefreshRect(wxRect(idxrect.x,idxrect.y,idxrect.width,idxrect.height+20),true);
            }
        }
    }
}

void mtg_t_cliFrame::PaintBubble(wxMemoryDC* memDC, wxRect rect)
{
    int w,h;
    w = rect.width;
    h = rect.height-20;
    int x = rect.x;
    int y = rect.y;
    ///background
    int mina=(w<h)?w:h;
    int a=mina;
    int rad=mina*9/20;
    int cx=x+w/2;
    int cy=y+h/2;
    double scale=1;
    double inclix=0.0;
    double incliy=0.0;
    wxFont eng(7,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);


    ///大圆
    memDC->SetPen(wxPen(wxColor(58,68,88)));
    memDC->SetBrush(wxBrush(wxColor(255,255,255)));
    memDC->DrawCircle(cx,cy,rad);
    ///小圆
    memDC->DrawCircle(cx,cy,rad*13/20);
    ///双轴
    memDC->DrawLine(cx-a/2+a/24,cy,cx+a/2-a/24,cy);
    memDC->DrawLine(cx,cy-a/2+a/24,cx,cy+a/2-a/24);
    static const double r2s=206264.80624709635515647335733078;
    double dx,dy;

    /*dx=mtg->m.comp[0]*r2s/10;
    dy=mtg->m.comp[1]*r2s/10;*/

    //20180115whq修改
    if(mtg->tps.type==TPS_TRIMBLE)//0.001570796对应角度5.4'
    {
        scale=1/0.001570796*rad*13/20;//20180206whq修改成rad*13/20
        dx=-mtg->m1.comp[1]*scale;
        dy=-mtg->m1.comp[0]*scale;
        inclix=-mtg->m1.comp[1];
        incliy=-mtg->m1.comp[0];
    }
    else//0.001100527对应角度3'47",徕卡全站仪倾角补偿范围待定
    {
        scale=1/0.001100527*rad*13/20;
        dx=mtg->m1.comp[0]*scale;
        dy=mtg->m1.comp[1]*scale;
        inclix=mtg->m1.comp[0];
        incliy=mtg->m1.comp[1];
    }

    //dx=mtg->m1.comp[0]*scale;
    //dy=mtg->m1.comp[1]*scale;

    ///如圆心超出小圆，则画在小圆上，20180206whq修改，将大圆改成小圆
    double dist=sqrt(dx*dx+dy*dy);
    if(dist>rad*13/20)
    {
        dx*=rad*13/20/dist;
        dy*=rad*13/20/dist;
        memDC->SetBrush(*wxTRANSPARENT_BRUSH);
        memDC->SetPen(wxPen(wxColor(255,0,0),2));
        memDC->DrawCircle(cx,cy,rad);
    }

    memDC->SetPen(wxPen(wxColor(0,250,150),2));
    memDC->SetBrush(*wxTRANSPARENT_BRUSH);
    memDC->DrawCircle(cx-dx,cy+dy,rad*3/10);

    memDC->SetFont(eng);
    memDC->DrawLabel(_("L:")+Radian_to_Angle(inclix)+_(" T:")+Radian_to_Angle(incliy),NULL,wxRect(x,y+h,w,20),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);

}

void mtg_t_cliFrame::OnPaintStatus(wxPaintEvent& event)
{
    wxPaintDC dc(panelStatus);
    int w,h;
    panelStatus->GetClientSize(&w,&h);

    ///background
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(0,h-1,w,h-1);
        memDC.DrawLine(0,0,0,h);

        int r,g,b;
        r=215;
        g=234;
        b=251;
        for(int hi=0;hi<h-1;hi++)
        {
            memDC.SetPen(wxPen(wxColor(r,g,b)));
            memDC.DrawLine(1,hi,w,hi);
            if(hi%5==0)
            {
                r++;
            }

            if(hi%15==0)
            {
                g++;
            }

            if(hi%35==0)
            {
                b++;
            }
        }

        //PaintBattery(&memDC, wxRect(0,0,w,h));
        //if(tpsStatus==1)
        {
            PaintBubble(&memDC, wxRect(0,0,w,h));
        }
//        else
//        {
//            PaintBattery(&memDC, wxRect(0,0,w,h));
//        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_cliFrame::GetError()
{
    int nh=road_number_horizon(&mtg->r);
    int nv=road_number_vertical(&mtg->r);
    if(nh<=2 || nv<=2)
    {
        Err=ID_ERR_NO_DTA;
        return;
    }

    if(mtg->m0.t1<=0)
    {
        Err=ID_ERR_NO_ORI;
        return;
    }

    if(mtg->m1.t3<=0)
    {
        Err=ID_ERR_NO_PSM;
        return;
    }

    wxString istr=wxString(mtg->camset[0].name,wxConvUTF8);

    if(istr.length()==0)
    {
        Err=ID_ERR_NO_TARSET;
        return;
    }

    if(mtg->itps==0)
    {
        Err=ID_ERR_NO_TPS;
        return;
    }

    if(mtg->iinc==0 || mtg->icam==0)
    {
        Err=ID_ERR_NO_TAR;
        return;
    }

    Err=0;
}

#include "trace.h"
///tiemr
void mtg_t_cliFrame::OnTimer(wxTimerEvent& event)
{
    static int tick=0;
    int ico=0;
    int i=0;
    static char msg[4096];
    static char s[1024];
    static int nlog=0;
    static MTG_LOG logs[20];
    char logmsg[4096];
    int size=listlog->GetItemCount();
    char word[1024]="\0";
    int id1,id2;
    wxIPV4address addr;
    wxString HostIP;
 //   FILE* fp=fopen("C:\\tpsaction.txt","a");

    if(size>=200)
    {
        listlog->DeleteAllItems();
        size=0;
    }
    nlog=mtg_peek_log(mtg,logs,20);
    if(nlog > 0)
    {
        wxString strLog;
        for(i=0;i<nlog;i++)
        {
            ico=logs[i].type;

            listlog->InsertItem(size+i,ico);
            listlog->SetItem(size+i,1,wxDateTime(logs[i].t).Format(_("%Y-%m-%d %H:%M:%S")));
            strLog = wxString(logs[i].msg,wxConvLocal);
            listlog->SetItem(size+i,2,strLog);
            listlog->EnsureVisible(size+i);

            switch(logs[i].nlog)
            {
                case MTG_LOG_FINISH_START_LASER:
                {
                    tpsDirection=1;
                    tickAnimation=0;
                    drawAnimation=true;
                    break;
                }
                case MTG_LOG_FINISH_STOP_LASER:
                case MTG_LOG_FAIL_STOP_LASER:
                case MTG_LOG_END_CYCLE:
                {
                    drawAnimation=false;
                    panelGraph->Refresh(false);
                    break;
                }
                case MTG_LOG_FAIL_CONNECT_TPS:
                {
                    if(Err==0)
                    {
                        Err=MTG_LOG_FAIL_CONNECT_TPS;
                        panelMode->Refresh();
                    }
                    break;
                }
                case MTG_LOG_FAIL_CONNECT_INCLINE:
                {
                    if(Err==0)
                    {
                        Err=MTG_LOG_FAIL_CONNECT_INCLINE;
                        panelMode->Refresh();
                    }
                    break;
                }
                case MTG_LOG_FAIL_CONNECT_CAMERA:
                {
                    if(Err==0)
                    {
                        Err=MTG_LOG_FAIL_CONNECT_CAMERA;
                        panelMode->Refresh();
                    }
                    break;
                }
                case MTG_LOG_FINISH_CONNECT_TPS:
                {
                    if(Err==MTG_LOG_FAIL_CONNECT_TPS)
                    {
                        Err=0;
                        panelMode->Refresh();
                    }
                    break;
                }
                case MTG_LOG_FINISH_CONNECT_INCLINE:
                {
                    if(Err==MTG_LOG_FAIL_CONNECT_INCLINE)
                    {
                        Err=0;
                        panelMode->Refresh();
                    }
                    break;
                }
                case MTG_LOG_FINISH_CONNECT_CAMERA:
                {
                    if(Err==MTG_LOG_FAIL_CONNECT_CAMERA)
                    {
                        Err=0;
                        panelMode->Refresh();
                    }
                    break;
                }
                case MTG_LOG_BEGIN_MEASURE_BACKSIGHT:
                {
                    tpsDirection=0;
                    tickAnimation=0;
                    drawAnimation=true;
                    //panelGraph->Refresh(false);
                    break;
                }
                case MTG_LOG_FAIL_MEASURE_BACKSIGHT:
                {
                    drawAnimation=false;
                    panelGraph->Refresh(false);
                    break;
                }
                case MTG_LOG_BEGIN_TARGET_BACKSIGHT:
                {
                    tpsDirection=2;
                    tickAnimation=0;
                    drawAnimation=true;
                    panelGraph->Refresh();
                    break;
                }
                case MTG_LOG_FAIL_TARGET_BACKSIGHT:
                {
                    tpsDirection=0;
                    drawAnimation=false;
                    panelGraph->Refresh(false);
                    break;
                }
                case MTG_LOG_FINISH_MEASURE_BACKSIGHT:
                {
                    drawAnimation=false;
                    panelGraph->Refresh(false);
                    mtg->istn.backx1=mtg->backmeas[0];
                    mtg->istn.backy1=mtg->backmeas[1];
                    mtg->istn.backz1=mtg->backmeas[2];
                    break;
                }
                case MTG_LOG_FINISH_SET_ORIENTATION:
                {
                    time(&mtg->istn.t);
                    mtg_store_station(mtg);
                    break;
                }
                case MTG_LOG_FINISH_TARGET_BACKSIGHT:
                {
                    tpsDirection=0;
                    drawAnimation=false;
                    panelGraph->Refresh(false);
                    break;
                }
                case MTG_LOG_BEGIN_TARGET_PRISM:
                {
                    tpsDirection=2;
                    tickAnimation=0;
                    drawAnimation=true;
                    panelGraph->Refresh();
                    break;
                }
                case MTG_LOG_FAIL_TARGET_PRISM:
                {
                    tpsDirection=1;
                    drawAnimation=false;
                    panelGraph->Refresh(false);
                    break;
                }
                case MTG_LOG_FINISH_TARGET_PRISM:
                {
                    tpsDirection=1;
                    drawAnimation=false;
                    panelGraph->Refresh(false);
                    break;
                }
                case MTG_LOG_BEGIN_MEASURE_PRISM:
                {
                    tpsDirection=1;
                    tickAnimation=0;
                    drawAnimation=true;
                    break;
                }
                case MTG_LOG_FAIL_MEASURE_PRISM:
                {
                    drawAnimation=false;
                    panelGraph->Refresh(false);
                    break;
                }
                case MTG_LOG_FINISH_MEASURE_PRISM:
                {
                    drawAnimation=false;
                    panelGraph->Refresh(false);
                    break;
                }
                case MTG_LOG_FINISH_CYCLE:
                {
                    GetTips();
                    panelBar->Refresh();
                    if(mapDlg && mapDlg->OnUse==1) mapDlg->UpdateGraph();
                    break;
                }
                default:
                    break;
            }
        }
    }

    tick++;
    if(tick % 10==0)
    {
        panelMetric->Refresh();

        FILE* fp=fopen("D:\\midu\\Meas.csv","w");
        if(fp)
        {
            fprintf(fp,wxString(_("环号,前里程,中里程,后里程,前平偏,中平偏,后平偏,前高偏,中高偏,后高偏,转动角,\
              俯仰角,方位角,前x,前y,前z,中x,中y,中z,后x,后y,后z,水平趋势,垂直趋势,测站x,测站y,测站z,时间\n")).mb_str(wxConvLocal));
            fprintf(fp,"%d,",mtg->m1.iseg);
            fprintf(fp,"%.4f,",headc);
            fprintf(fp,"%.4f,",midc);
            fprintf(fp,"%.4f,",tailc);
            fprintf(fp,"%.4f,",headh/1000.0);
            fprintf(fp,"%.4f,",midh/1000.0);
            fprintf(fp,"%.4f,",tailh/1000.0);
            fprintf(fp,"%.4f,",headv/1000.0);
            fprintf(fp,"%.4f,",midv/1000.0);
            fprintf(fp,"%.4f,",tailv/1000.0);
            fprintf(fp,"%.4f,",inc[0]);
            fprintf(fp,"%.4f,",inc[1]);
            fprintf(fp,"%.4f,",inc[2]);
            fprintf(fp,"%.4f,",head[0]);
            fprintf(fp,"%.4f,",head[1]);
            fprintf(fp,"%.4f,",head[2]);
            fprintf(fp,"%.4f,",mid[0]);
            fprintf(fp,"%.4f,",mid[1]);
            fprintf(fp,"%.4f,",mid[2]);
            fprintf(fp,"%.4f,",tail[0]);
            fprintf(fp,"%.4f,",tail[1]);
            fprintf(fp,"%.4f,",tail[2]);
            fprintf(fp,"%.4f,",htrend/1000.0);
            fprintf(fp,"%.4f,",vtrend/1000.0);
            fprintf(fp,"%.4f,",mtg->istn.statx);
            fprintf(fp,"%.4f,",mtg->istn.staty);
            fprintf(fp,"%.4f,",mtg->istn.statz);
            wxString strt=wxDateTime(mtg->m1.t1).Format(_("%Y-%m-%d %H:%M:%S"));
            fprintf(fp,"%s\n",(const char*)strt.mb_str(wxConvLocal));
            fclose(fp);
        }
    }

    if(tick % 30==0)
    {
        //GetError();
        //if(tpsStatus==0) tpsStatus=1;
        //else tpsStatus=0;
        panelStatus->Refresh();
        panelMode->Refresh();
    }

    if(tick % 50==0)
    {
        if(tip<nks-1)
        {
            tip++;
        }
        else if(tip==nks-1)
        {
            if(mtg->prj.htip==1) tip=nks;
            else if(mtg->prj.vtip==1) tip=nks+2;
            else tip=0;
        }
        else if(tip<nks+4)
        {
            tip++;
        }
        else
        {
            tip=0;
        }
    }

    if(tick % 100==0)
    {
        //wxMessageBox(wxString::Format(_("%d,%d"),cli->login,cli->mode));
        if(cli->login==0 && cli->mode==0)
        {
            //sock = new wxSocketClient();
            if(cli->local==1)
            {
                addr.LocalHost();
                HostIP = addr.IPAddress();
            }
            else
            {
                HostIP=wxString(mtg->comset[4].ip,wxConvUTF8);
                addr.Hostname(HostIP);
            }

            addr.Hostname(HostIP);
            addr.Service(3000);
            sock->Connect(addr, false);
            sock->WaitOnConnect(10);

            if(sock->IsConnected())
            {
                sock->GetLocal(addr);
                if(cli->local==1)
                {
                    sprintf(word,"%%R1Q,0:%s\n",HostIP);
                    sock->Write(word,strlen(word));
                    cli->login=1;

                    sprintf(word,"登录服务器成功！");
                    add_msg_log(mtg,word,0);
                    //wxMessageBox(_("登录服务器成功！"));
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
                    sleepms(100);
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
                        sprintf(word,"登录服务器失败！");
                        add_msg_log(mtg,word,1);
                        //wxMessageBox(_("登录服务器失败！"));
                    }
                    else
                    {
                        sprintf(word,"登录服务器成功！");
                        add_msg_log(mtg,word,0);
                        //wxMessageBox(_("登录服务器成功！"));
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
                        sleepms(100);
                    }
                }
            }
        }
    }

    if(tick == 1200) ///reconnect hardware
    {
        tick=0;
    }
    tickAnimation++;
    if(tickAnimation>10) tickAnimation=1;
    if(drawAnimation) panelGraph->Refresh(false);
}

