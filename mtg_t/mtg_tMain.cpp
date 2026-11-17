/***************************************************************
 * Name:      mtg_tMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    dengdeyan (dengdeyan@medosurvey.com)
 * Created:   2011-03-21
 * Copyright: dengdeyan (http://www.medosurvey.com)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "mtg_tMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(mtg_tFrame)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include <wx/dcclient.h>
#include "DtaDlg.h"
#include "mtg_tApp.h"
#include "LibPlc.h"
#include <wx/stdpaths.h>
#include "ConfigDlg.h"
#include "SegmentDlg.h"
#include "CheckUpDlg.h"
#include "MapViewDlg.h"
#include "MyQueryDlg.h"
#include "MyTestDlg.h"
#include "MySetupDlg.h"
#include "MyErectDlg.h"
#include "confirmdlg.h"
#include "ModifySegDialog.h"
#include "MySetupDialog.h"
#include "SegmentMonitorDlg.h"
#include "dmsrad.h"
#include <wx/imaglist.h>
#include "LogDialog.h"
#include <wx/dcbuffer.h>
#include "libele.h"
#include "PasswordDialog.h"
#include <wx/config.h>
#include "gtime.h"

#define PI  3.1415926535897932384626433832795

//(*IdInit(mtg_tFrame)
const long mtg_tFrame::ID_PANEL4 = wxNewId();
const long mtg_tFrame::ID_PANEL5 = wxNewId();
const long mtg_tFrame::ID_PANEL11 = wxNewId();
const long mtg_tFrame::ID_PANEL12 = wxNewId();
const long mtg_tFrame::ID_PANEL13 = wxNewId();
const long mtg_tFrame::ID_PANEL1 = wxNewId();
const long mtg_tFrame::ID_PANEL17 = wxNewId();
const long mtg_tFrame::ID_PANEL19 = wxNewId();
const long mtg_tFrame::ID_PANEL33 = wxNewId();
const long mtg_tFrame::ID_PANEL34 = wxNewId();
const long mtg_tFrame::ID_PANEL36 = wxNewId();
const long mtg_tFrame::ID_PANEL37 = wxNewId();
//*)

BEGIN_EVENT_TABLE(mtg_tFrame,wxFrame)
    //(*EventTable(mtg_tFrame)
    EVT_CLOSE(mtg_tFrame::OnClose)
    //*)
    EVT_SOCKET(-1,mtg_tFrame::OnSocketEvent)
END_EVENT_TABLE()

mtg_tFrame::mtg_tFrame(wxWindow* parent,wxWindowID id)
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
    bmpTarget.LoadFile(path+_("/plugins/target.png"),wxBITMAP_TYPE_PNG);
    //bmpLogo.LoadFile(path+_("/plugins/logo.png"),wxBITMAP_TYPE_PNG);
    bmpPartner.LoadFile(path+_("/plugins/partner.png"),wxBITMAP_TYPE_PNG);
    bmpInfo.LoadFile(path+_("/plugins/info.png"),wxBITMAP_TYPE_PNG);
    bmpError.LoadFile(path+_("/plugins/error.png"),wxBITMAP_TYPE_PNG);
    int w,h;
    imgTrace.Create(1280,960);
    //(*Initialize(mtg_tFrame)
    Create(parent, id, _("cli-T盾构导向系统"), wxDefaultPosition, wxDefaultSize, wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER | wxSYSTEM_MENU | wxCLOSE_BOX | wxCLIP_CHILDREN, _T("id"));
    SetClientSize(wxSize(1024,768));
    this->GetSize(&w,&h);
    //wxMessageBox(wxString::Format(_("%d,%d"),w,h));

    panelUI = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelTitle = new MDTitle(this, ID_PANEL36, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL36"));
    panelButtonList = new MDButtonList(panelUI, ID_PANEL37, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL37"));
    panelGraph = new wxPanel(panelUI, ID_PANEL11, wxPoint(200,545), wxSize(634,100), wxTAB_TRAVERSAL, _T("ID_PANEL11"));
    panelMetric = new wxPanel(panelUI, ID_PANEL33, wxPoint(0,395), wxSize(200,150), wxTAB_TRAVERSAL, _T("ID_PANEL33"));
    panelBar = new wxPanel(panelUI, ID_PANEL34, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL34"));
    panelLogo = new wxPanel(panelUI, ID_PANEL5, wxPoint(834,0), wxSize(190,125), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    panelMode = new wxPanel(panelMetric, ID_PANEL4, wxPoint(200,0), wxSize(634,125), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    panelKeyarea = new wxPanel(panelMetric, ID_PANEL19, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL19"));
    panelTime = new wxPanel(panelMetric, ID_PANEL12, wxPoint(834,125), wxSize(190,420), wxTAB_TRAVERSAL, _T("ID_PANEL12"));
    panelStatus = new wxPanel(panelUI, ID_PANEL13, wxPoint(0,395), wxSize(200,150), wxTAB_TRAVERSAL, _T("ID_PANEL13"));
    panelLog = new wxPanel(panelUI, ID_PANEL17, wxPoint(834,645), wxSize(190,25), wxTAB_TRAVERSAL, _T("ID_PANEL17"));

    panelKeyarea->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMode->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelLogo->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelGraph->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelTime->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelStatus->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMetric->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBar->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelLog->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMode->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintMode,0,this);
    panelLogo->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintLogo,0,this);
    panelGraph->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintGraph,0,this);
    panelTime->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintTime,0,this);
    panelStatus->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintStatus,0,this);

    panelLog->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintLog,0,this);
    panelLog->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnEnterLog,0,this);
    panelLog->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveLog,0,this);
    panelLog->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&mtg_tFrame::OnLeftDownLog,0,this);
    panelLog->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnLogClick,0,this);
    panelMetric->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintMetric,0,this);
    panelMetric->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnMetricClick,0,this);
    panelBar->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintBar,0,this);

    panelKeyarea->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintKeyarea,0,this);
    panelButtonList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnBtnClick,0,this);
    this->Connect(wxEVT_SIZE,(wxObjectEventFunction)&mtg_tFrame::OnSize,0,this);
    //*)
    //Center();

    //mtg_client_connect(cli);
    Connect(wxEVT_TIMER,(wxObjectEventFunction)&mtg_tFrame::OnTimer);
    timerStat.SetOwner(this);
    timerStat.Start(100,false);

    panelTitle->Name = _("MTG-T盾构导向系统");
    panelTitle->m_maximize_box=1;
    panelTitle->m_minimize_box=1;

    panelButtonList->pos_left=1;
    panelButtonList->btn_label_align=2;
    panelButtonList->AddButton(_("开始测量"));
    panelButtonList->AddButton(_("停止测量"));
    panelButtonList->AddButton(_("管片选型"));
    panelButtonList->AddButton(_("向前移站"));
    panelButtonList->AddButton(_("系统检查"));
    panelButtonList->AddButton(_("数据查询"));
    panelButtonList->AddButton(_("隧道中线"));
    panelButtonList->AddButton(_("地质地物"));
    panelButtonList->AddButton(_("管环监测"));
    panelButtonList->AddButton(_("参数设置"));
    panelButtonList->AddButton(_("退出系统"));
    ///btnState init
    btnLogState=0;

    ///用户区域
    ui = 0;
    ///日志
    nlog=cli->nlog;
    strLog[0]=wxEmptyString;
    strLog[1]=wxEmptyString;
    strLog[2]=wxEmptyString;
    tpLog[0]=tpLog[1]=tpLog[2]=0;

    ///关键区域提示
    GetTips();

    tps_tip=0;       //0电子补偿器1电池电量

    tpsDirection=2;
    drawAnimation=false;

    ///地质图
    isvmap = -1;
    //ReadMap();
    clientRun=0;
    emsg=0;
    ///调试信息
    logDlg=new LogDialog(this);

    SetSize(1024,696);
    Center();
    nbuf=0;
    second=0;
    peek=0;

    SetIcon(wxICON(aaaa));
    //#endif
}

void mtg_tFrame::GetTips()
{
    double l1,l2,l3,l4;
    int sn=1;
    nks=0;

    sn=cli->prj.a2z;

    l1=cli->m1.headc-sn*100;
    l2=l1+sn*200;

    for(int i=0;i<cli->nks;i++)
    {
        l3=cli->keys[i].mile1;
        if((l3-l1)/(l3-l2+0.000001)<0)
        {
            keys[nks]=cli->keys[i];
            nks++;
        }
    }
}

mtg_tFrame::~mtg_tFrame()
{
    //(*Destroy(mtg_tFrame)
    //*)
    timerStat.Stop();
    logDlg->Destroy();
}

void mtg_tFrame::OnSocketEvent(wxSocketEvent& event)
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

//

//

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
        wxMessageBox(_("服务端已退出！"),_("错误"),wxOK|wxICON_ERROR);
        sock->Destroy();
        sock=0;
        //Destroy();
        break;
    }
    default:
        ;
    }
    //strcpy(cli.inccom,"COM2");
}

void mtg_tFrame::OnClose(wxCloseEvent& event)
{
    ConfirmDlg dlg(this);
    dlg.Center();
    if(dlg.ShowModal()==wxID_OK)
    {
        event.Skip();
    }
    else
    {
        event.Veto();
    }
}

void mtg_tFrame::OnBtnClick(wxMouseEvent& event)
{
    int btn = panelButtonList->btn_left_down;
    switch(btn)
    {
    case 0:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        Start();
        break;
    case 1:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        Stop();
        break;
    case 2:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        SegmentAnalysis();
        break;
    case 3:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        MoveStation();
        break;
    case 4:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        Check();
        break;
    case 5:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        Query();
        break;
    case 6:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        EditDTA();
        break;
    case 7:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        ViewMap();
        break;
    case 8:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        ViewSegmentMonitor();
        break;
    case 9:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        Settings();
        break;
    case 10:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        Close();
        break;
    default:
        break;
    }
}

void mtg_tFrame::Start()
{
    //mtg_start_cycle(cli);
}

void mtg_tFrame::Stop()
{
    //mtg_stop(cli);
    panelMode->Refresh();
    panelGraph->Refresh();
}

void mtg_tFrame::SegmentAnalysis()
{
    SegmentDlg *dlg = new SegmentDlg(this);
    dlg->Center();
    dlg->ShowModal();

    /*SegmentDlg dlg(this);
    dlg.Center();
    //cli->m1.headc=415.0418;
    //cli->m1.headc=536.0418;
    //cli->ref_seg.seg_set=0;
    //mtg_cal_seg(cli,320,1.2);
    dlg.ShowModal();*/
}

void mtg_tFrame::MoveStation()
{
    PasswordDialog dlg(this);
    dlg.TextPassword->SetFocus();
    dlg.Center();

    if(dlg.ShowModal()==wxID_OK)
    {
        int i;
        for(i=0;i<cli->nuser;i++)
        {
            if(dlg.TextPassword->GetValue().Cmp(wxString((const char*)cli->user[i].password,wxConvLocal))==0)
            {
                break;
            }
        }
        if(i<cli->nuser)
        {
            cli->onLine = i;
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

void mtg_tFrame::Check()
{
    //checkDlg = new CheckUpDlg(this);
    CheckUpDlg dlg(this);
    dlg.Center();
    dlg.ShowModal();
    //ReviewDlg = new ReviewDlg(this);
    //ReviewDlg->Center();
    //ReviewDlg->ShowModal();
    //checkDlg->Destroy();
    //checkDlg=0;
}

void mtg_tFrame::Query()
{
    MyQueryDlg *dlg = new MyQueryDlg(this);
    dlg->Center();
    dlg->Show(true);
}

void mtg_tFrame::EditDTA()
{
    PasswordDialog dlg(this);

    dlg.TextPassword->SetFocus();
    dlg.Center();

    if(dlg.ShowModal()==wxID_OK)
    {
        if(dlg.iuser>=0)
        {
            cli->onLine = dlg.iuser;
            DtaDlg dlg(this);
            dlg.Center();
            dlg.ShowModal();
        }
    }
}

void mtg_tFrame::ViewMap()
{
    ///非模式对话框
    MapViewDlg *dlg = new MapViewDlg(this);
    dlg->Center();
    dlg->Show(true);
}

void mtg_tFrame::ViewSegmentMonitor()
{
    ///非模式对话框
    SegmentMonitorDlg *dlg = new SegmentMonitorDlg(this);
    dlg->Center();
    dlg->Show(true);
}

void mtg_tFrame::Settings()
{
    PasswordDialog dlg(this);

    dlg.TextPassword->SetFocus();
    dlg.Center();

    if(dlg.ShowModal()==wxID_OK)
    {
        int i;
        for(i=0;i<cli->nuser;i++)
        {
            if(dlg.TextPassword->GetValue().Cmp(wxString((const char*)cli->user[i].password,wxConvLocal))==0)
            {
                break;
            }
        }
        if(i<cli->nuser)
        {
            //confDlg=new ConfigDlg(this);
            //confDlg->opLevel=i;
            //confDlg->Center();
            //confDlg->ShowModal();
            ConfigDlg dlg(this);
            dlg.Center();
            dlg.ShowModal();
            panelStatus->Refresh();
            panelMetric->Refresh();
            panelBar->Refresh();
            //confDlg=0;
        }
    }
}


void mtg_tFrame::OnSize(wxSizeEvent& event)
{
    int w,h;
    GetSize(&w,&h);
    int w1 = 832, w2 = 130;
    int h1 = 524, h2 = 76, h3 = 64, h4 = 28 , h5 = 32;
    double sx,sy;
    sx = w/1024.0;
    sy = h/728.0;

    GetClientSize(&w,&h);
    //w2 = w2*sx;
    w1 = w-w2;
    h1 = h-31-h2-h3-h4;
    panelUI->SetSize(0,31,w,h-31);

    panelTitle->SetSize(0,0,w,31);
    panelButtonList->SetSize(w1,0,w2,h1);
    panelButtonList->btn_height=36*sy;

    int x1=20*sx;
    int y1=10;
    int wb=w2-40*sx;
    int hb=(h1-20)/10;

    ///姿态数据显示
    panelMetric->SetSize(0,0,w1,h1);
    ///graph
    //panelGraph->SetSize(w1,h1+h2+h3+h4,w2,h5);
    panelGraph->SetSize(0,h1,w1,h2);
    wb = h2/2;
    hb = wb;
    x1 = w1-wb-15;
    y1 = hb/4;

    x1 = w1/2;
    y1 = hb*7/8;
    ///bubble
    //panelBubble->SetSize(x1,y1,wb,hb);
    x1 = x1+wb+wb*2/3;
    //y1 = h1*4/12;
    ///电池电量
    //panelBattery->SetSize(x1,y1,wb/2,hb);
    ///status
    panelStatus->SetSize(w1,h1,w2,h2);
    ///log
    panelLog->SetSize(0,h1+h2,w1,h3);
    //listLog->SetSize(11,1,w1-21,h3-4);
    ///statusbar
    panelBar->SetSize(0,h1+h2+h3,w1+w2,h4);
    ///logo
    panelLogo->SetSize(w1,h1+h2,w2,h3);
    ///关键区域
    panelKeyarea->SetSize(15*sx,h1-h5,w1-30*sx,h5);
    panelKeyarea->Show(false);
    ///地质
    int lw1,lh1,lx1,ly1;
    if(sx>sy)
    {
        lw1 = 310*sx-250*sy;
        lx1 = (310*sx-160*sy-lw1)/2-20*sy;
        ly1 = 20*sy;
        lh1 = 370*sy;
    }
    else
    {
        lw1 = 60*sx;
        lx1 = 25*sx;
        ly1 = 205*sy-185*sx;
        lh1 = 370*sx;
    }


    ///模式提醒
    panelMode->SetSize(0,h1-h5,w1,h5);
    ///时间
    panelTime->SetSize(w+15*sx+(w1-30*sx)*4/5,h1-h5,(w1-30*sx)/5,h5);


    panelMode->Refresh();
    panelLogo->Refresh();
    panelTime->Refresh();
    panelKeyarea->Refresh();

    panelGraph->Refresh();
    panelStatus->Refresh();
    panelLog->Refresh();
    panelMetric->Refresh();
    panelBar->Refresh();
    panelTitle->Refresh();
    panelButtonList->Refresh();
}

void mtg_tFrame::PaintBattery(wxMemoryDC* memDC, wxRect rect)
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
    int y1=y+h/5;
    int w1=w*6/9;
    int h1=h*3/5;
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

    int capacity=cli->tps.power;
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

void mtg_tFrame::OnPaintMode(wxPaintEvent& event)
{
    wxPaintDC dc(panelMode);
    int w,h;
    GetSize(&w,&h);

    double sx=w/1024.0;
    double sy=h/768.0;
    int x1 = hrect.x;

    if(sx>sy)
    {
        sx = sy;
    }
    panelMode->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("黑体"),wxFONTENCODING_DEFAULT);
        wxFont eng(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);

        int c1 = 204;
        int c2 = 204;
        int c3 = 204;

        memDC.SetPen(wxPen(wxColor(168,168,168)));
        memDC.SetBrush(wxBrush(wxColor(208,208,208)));
        memDC.DrawRectangle(0,0,w,h);

        //int x1 = w;
        int w1 = (w-x1)/3;
        int h1 = h-2;
        int y1 = 1;
        int x2 = x1+w1;
        int y2 = h-2;

        //memDC.SetBrush(wxBrush(wxColor(204,233,177)));
        memDC.SetTextForeground(wxColor(71,71,71));
        wxString valstr = wxEmptyString;
        //cli->m1.t1=1444987713;
        if(cli->m1.t1>0)
        {
            time_t now;
            time(&now);
            time_t timing;
            timing=now-cli->m1.t1;
            if(timing>cli->sets.talw)
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
        if(cli->itbm == 0)
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
        if(cli->iclient <= 0)
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
        x2 = hrect.x;
        y2 = h-2;
        double l1,l2,l3,l4,l5;
        double vi;
        int sn=1;
        sn=cli->prj.a2z;

        double headc;
        if(cli->m1.t1>0)
        {
            headc=cli->m1.headc;
            l1=headc-sn*100;
            l2=l1+sn*200;
        }
        else
        {
            headc=cli->prj.mile1;
            l1=headc-sn*100;
            l2=l1+sn*200;
        }

        if(cli->elog.t > 0)
        {

            memDC.SetTextForeground(wxColor(255,255,255));
            c1 = 180;
            c2 = 60;
            c3 = 30;
            for(int i=y1;i<=y2;i++)
            {
                if((i-y1)%2==0)
                {
                    c1+=1;
                    c2+=3;
                    c3+=4;
                }
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
            }
            //DecodeLogString(cli->elog.nlog,valstr);
            valstr=wxDateTime(cli->elog.t).Format(_("%Y-%m-%d %H:%M:%S"))+valstr;
            memDC.DrawLabel(valstr,wxRect(x1+15,y1,0,y2-y1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(tip==nks)
        {
            int nh = road_number_horizon(&cli->r);
            if(nh>2)
            {
                tipstr[0]=wxEmptyString;
                tipstr[1]=wxEmptyString;
                for(int i=1;i<nh-1;i++)
                {
                    l3=road_horizon(&cli->r,i)->l1;
                    l4=l3+road_horizon(&cli->r,i)->length;
                    if((l3-l1)/(l3-l2+0.000001)<0 || (l4-l1)/(l4-l2+0.000001)<0)
                    {
                        if(road_horizon(&cli->r,i)->type==ROAD_TYPE_LINE)
                        {
                            valstr=_("当前平曲线:类型(直线),剩余(");
                        }
                        else if(road_horizon(&cli->r,i)->type==ROAD_TYPE_ARC)
                        {
                            valstr=valstr+_("当前平曲线:类型(圆曲线),半径(");
                            valstr=valstr+wxString::Format(_("%.2f"),road_horizon(&cli->r,i)->radius);
                            valstr=valstr+_("米),转向(");
                            if(road_horizon(&cli->r,i)->pz==ROAD_LEFT)
                            {
                                if(sn==1) valstr=valstr+_("左转弯),剩余(");
                                else valstr=valstr+_("右转弯),剩余(");
                            }
                            else
                            {
                                if(sn==1) valstr=valstr+_("右转弯),剩余(");
                                else valstr=valstr+_("左转弯),剩余(");
                            }
                        }
                        else if(road_horizon(&cli->r,i)->type==ROAD_TYPE_SPIRAL)
                        {
                            valstr=valstr+_("当前平曲线:类型(缓和曲线),长度(");
                            valstr=valstr+wxString::Format(_("%.2f"),road_horizon(&cli->r,i)->length);
                            valstr=valstr+_("米),转向(");
                            if(road_horizon(&cli->r,i)->pz==ROAD_LEFT)
                            {
                                if(sn==1) valstr=valstr+_("左转弯),剩余(");
                                else valstr=valstr+_("右转弯),剩余(");
                            }
                            else
                            {
                                if(sn==1) valstr=valstr+_("右转弯),剩余(");
                                else valstr=valstr+_("左转弯),剩余(");
                            }
                        }
                        if(sn==1)
                        {
                            l5=l4-headc;
                        }
                        else
                        {
                            l5=headc-l3;
                        }
                        valstr=valstr+wxString::Format(_("%.2f米)"),l5);
                        tipstr[0]=valstr;

                        if(i<nh-1)
                        {
                            if(sn==-1)
                            {
                                if(i==1) break;
                                i=i-1;
                            }
                            else
                            {
                                i=i+1;
                            }
                            if(road_horizon(&cli->r,i)->type==ROAD_TYPE_LINE)
                            {
                                valstr=_("下段平曲线:类型(直线),前方(");
                            }
                            else if(road_horizon(&cli->r,i)->type==ROAD_TYPE_ARC)
                            {
                                valstr=+_("下段平曲线:类型(圆曲线),半径(");
                                valstr=valstr+wxString::Format(_("%.2f"),road_horizon(&cli->r,i)->radius);
                                valstr=valstr+_("米),转向(");
                                if(road_horizon(&cli->r,i)->pz==ROAD_LEFT)
                                {
                                    if(sn==1) valstr=valstr+_("左转弯),前方(");
                                    else valstr=valstr+_("右转弯),前方(");
                                }
                                else
                                {
                                    if(sn==1) valstr=valstr+_("右转弯),前方(");
                                    else valstr=valstr+_("左转弯),前方(");
                                }
                            }
                            else if(road_horizon(&cli->r,i)->type==ROAD_TYPE_SPIRAL)
                            {
                                valstr=_("下段平曲线:类型(缓和曲线),长度(");
                                valstr=valstr+wxString::Format(_("%.2f"),road_horizon(&cli->r,i)->length);
                                valstr=valstr+_("米),转向(");
                                if(road_horizon(&cli->r,i)->pz==ROAD_LEFT)
                                {
                                    if(sn==1) valstr=valstr+_("左转弯),前方(");
                                    else valstr=valstr+_("右转弯),前方(");
                                }
                                else
                                {
                                    if(sn==1) valstr=valstr+_("右转弯),前方(");
                                    else valstr=valstr+_("左转弯),前方(");
                                }
                            }
                            if(sn==1)
                            {
                                l5=l4-headc;
                            }
                            else
                            {
                                l5=headc-l3;
                            }
                            valstr=valstr+wxString::Format(_("%.2f米)"),l5);
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
            int nv = road_number_vertical(&cli->r);
            if(nv>2)
            {
                tipstr[2]=wxEmptyString;
                tipstr[3]=wxEmptyString;
                for(int i=1;i<nv-1;i++)
                {
                    l3=road_vertical(&cli->r,i)->l1;
                    l4=l3+road_vertical(&cli->r,i)->length;
                    if((l3-l1)/(l3-l2+0.000001)<0 || (l4-l1)/(l4-l2+0.000001)<0)
                    {
                        if(road_vertical(&cli->r,i)->type==ROAD_TYPE_LINE)
                        {
                            valstr=_("当前竖曲线:类型(直线),坡度(");
                            vi=road_vertical(&cli->r,i)->angle1;
                            vi=tan(vi)*1000.0*sn;
                            valstr=valstr+wxString::Format(_("%.3f‰),剩余("),vi);
                        }
                        else if(road_vertical(&cli->r,i)->type==ROAD_TYPE_ARC)
                        {
                            valstr=_("当前竖曲线:类型(圆曲线),半径(");
                            valstr=valstr+wxString::Format(_("%.2f"),road_vertical(&cli->r,i)->radius);
                            valstr=valstr+_("米),转向(");
                            if(road_vertical(&cli->r,i)->pz==ROAD_UP)
                            {
                                valstr=valstr+_("向上),剩余(");
                            }
                            else
                            {
                                valstr=valstr+_("向下),剩余(");
                            }
                        }
                        if(sn==1)
                        {
                            l5=l4-headc;
                        }
                        else
                        {
                            l5=headc-l3;
                        }
                        valstr=valstr+wxString::Format(_("%.2f米)"),l5);
                        tipstr[2]=valstr;

                        if(i<nv-1)
                        {
                            if(sn==-1)
                            {
                                if(i==1) break;
                                i=i-1;
                            }
                            else
                            {
                                i=i+1;
                            }

                            if(road_vertical(&cli->r,i)->type==ROAD_TYPE_LINE)
                            {
                                valstr=_("下段竖曲线:类型(直线),坡度(");
                                vi=road_vertical(&cli->r,i)->angle1;
                                vi=tan(vi)*1000.0*sn;
                                valstr=valstr+wxString::Format(_("%.3f‰),剩余("),vi);
                            }
                            else if(road_vertical(&cli->r,i)->type==ROAD_TYPE_ARC)
                            {
                                valstr=_("下段竖曲线:类型(圆曲线),半径(");
                                valstr=valstr+wxString::Format(_("%.2f"),road_vertical(&cli->r,i)->radius);
                                valstr=valstr+_("米),转向(");
                                if(road_vertical(&cli->r,i)->pz==ROAD_UP)
                                {
                                    valstr=valstr+_("向上),前方(");
                                }
                                else
                                {
                                    valstr=valstr+_("向下),前方(");
                                }
                            }
                            if(sn==1)
                            {
                                l5=l4-headc;
                            }
                            else
                            {
                                l5=headc-l3;
                            }
                            valstr=valstr+wxString::Format(_("%.2f米)"),l5);
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

            if(sn==1)
            {
                if(cli->m1.headc>=keys[tip].mile2)
                {
                    l5=cli->m1.headc-keys[tip].mile2;
                    valstr=valstr+_("后方(")+wxString::Format(_("%.2f米)"),l5);
                }
                else if(cli->m1.headc<=keys[tip].mile1)
                {
                    l5=keys[tip].mile2-cli->m1.headc;
                    valstr=valstr+_("前方(")+wxString::Format(_("%.2f米)"),l5);
                }
            }
            else
            {
                if(cli->m1.headc<=keys[tip].mile2)
                {
                    l5=keys[tip].mile2-cli->m1.headc;
                    valstr=valstr+_("后方(")+wxString::Format(_("%.2f米)"),l5);
                }
                else if(cli->m1.headc>=keys[tip].mile1)
                {
                    l5=cli->m1.headc-keys[tip].mile2;
                    valstr=valstr+_("前方(")+wxString::Format(_("%.2f米)"),l5);
                }
            }
            memDC.DrawLabel(valstr,wxRect(x1+15,y1,0,y2-y1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(x1,y1,x1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnPaintLogo(wxPaintEvent& event)
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
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.SetBrush(wxBrush(wxColor(236,241,254)));
        memDC.DrawRectangle(0,-1,w+2,h+2);

        if(bmpLogo.IsOk())
        {
            int w1,h1;
            w1=bmpLogo.GetWidth();
            h1=bmpLogo.GetHeight();
            double s=w1/3.0/w;
            memDC.SetUserScale(s,s);
            memDC.DrawBitmap(bmpLogo,w/2/s-w1/2,h/2/s-h1/2);
            memDC.SetUserScale(1.0,1.0);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnPaintKeyarea(wxPaintEvent& event)
{
    wxPaintDC dc(panelKeyarea);
    int w,h;
    GetSize(&w,&h);

    //FILE* fp = fopen("E:\\keyarea.log","w");

    double sx=w/1024.0;
    double sy=h/768.0;
    if(sx>sy)
    {
        sx = sy;
    }
    panelKeyarea->GetClientSize(&w,&h);
    ///background
    //dc.SetPen(wxPen(wxColor(displayColor3[0],displayColor3[1],displayColor3[2])));
    //dc.SetBrush(wxBrush(wxColor(127,117,103)));
    dc.SetBrush(wxBrush(wxColor(223,228,234)));
    dc.SetPen(wxPen(wxColor(243,248,254)));
    dc.DrawRectangle(0,0,w,h+1);

    ///关键区域
    wxString tipString[10];
    wxString areaname;
    //tips = 0;
    h_element* he;
    v_element* ve;
    double d1;
    double r1;
    double ver;
    double headc;

    if(cli->m1.t1)
    {
        headc = cli->m1.headc;
    }
    else
    {
        headc = cli->prj.mile1;
    }

    //fprintf(fp,"headc:%.4f\n",headc);
    int nh = road_number_horizon(&cli->r);
    int nv = road_number_vertical(&cli->r);

    int mh = 0;
    int mv = 0;

    if(nh>2)
    {
        if(cli->m1.t1)
        {
            if(headc<road_horizon(&cli->r,0)->l1)
            {
                he = road_horizon(&cli->r,1);
                mh=1;
            }
            else if(headc>road_horizon(&cli->r,nh-2)->l1+road_horizon(&cli->r,nh-2)->length)
            {
                he = road_horizon(&cli->r,nh-2);
                mh=nh-2;
            }
            else
            {
                he = road_horizon_chain(&cli->r,headc,&mh);
            }
        }
        else
        {
            if(headc<road_horizon(&cli->r,0)->l1)
            {
                he = road_horizon(&cli->r,1);
                mh=1;
            }
            else if(headc>road_horizon(&cli->r,nh-2)->l1+road_horizon(&cli->r,nh-2)->length)
            {
                he = road_horizon(&cli->r,nh-2);
                mh=nh-2;
            }
            else
            {
                he = road_horizon_chain(&cli->r,headc,&mh);
            }
        }
        if(he)
        {
            areaname = _("当前平曲线   ");
            switch(he->type)
            {
            case ROAD_TYPE_LINE:
                areaname = areaname+_("类型：直线   ");
                if(cli->prj.a2z==1)
                {
                    d1 = he->l1+he->length-headc;
                }
                else
                {
                    d1 = headc-he->l1;
                    //fprintf(fp,"headc:%.4f\n",he->l1);
                }
                areaname = areaname+wxString::Format(_("终点：前方%.3f米   "),d1);
                break;
            case ROAD_TYPE_SPIRAL:
                areaname = areaname+_("类型：缓和曲线   ");
                if(he->pz==0)
                {
                    if(cli->prj.a2z==1)
                    {
                        d1 = he->l1+he->length-headc;
                        areaname = areaname+wxString::Format(_("终点：前方%.3f米   "),d1);
                        areaname = areaname+_("转向：向左   ");

                    }
                    else
                    {
                        d1 = headc-he->l1;
                        areaname = areaname+wxString::Format(_("终点：前方%.3f米   "),d1);
                        areaname = areaname+_("转向：向右   ");

                    }

                }
                else
                {
                    if(cli->prj.a2z==1)
                    {
                        d1 = he->l1+he->length-headc;
                        areaname = areaname+wxString::Format(_("终点：前方%.3f米   "),d1);
                        areaname = areaname+_("转向：向右   ");
                    }
                    else
                    {
                        d1 = headc-he->l1;
                        areaname = areaname+wxString::Format(_("终点：前方%.3f米   "),d1);
                        areaname = areaname+_("转向：向左   ");
                    }

                }

                break;
            case ROAD_TYPE_ARC:
                areaname = areaname+_("类型：圆曲线   ");
                if(he->pz==0)
                {
                    if(cli->prj.a2z==1)
                    {
                        d1 = he->l1+he->length-headc;
                        r1 = he->radius;
                        areaname = areaname+wxString::Format(_("终点：前方%.3f米   "),d1);
                        areaname = areaname+wxString::Format(_("半径R：%.3f米   "),r1);
                        areaname = areaname+_("转向：向左   ");

                    }
                    else
                    {
                        d1 = headc-he->l1;
                        r1 = he->radius;
                        areaname = areaname+wxString::Format(_("终点：前方%.3f米   "),d1);
                        areaname = areaname+wxString::Format(_("半径R：%.3f米   "),r1);
                        areaname = areaname+_("转向：向右   ");
                        //fprintf(fp,"headc:%.4f\n",he->l1);

                    }
                }
                else
                {
                    if(cli->prj.a2z==1)
                    {
                        d1 = he->l1+he->length-headc;
                        r1 = he->radius;
                        areaname = areaname+wxString::Format(_("终点：前方%.3f米   "),d1);
                        areaname = areaname+wxString::Format(_("半径R：%.3f米   "),r1);
                        areaname = areaname+_("转向：向右   ");

                    }
                    else
                    {
                        d1 = headc-he->l1;
                        r1 = he->radius;
                        areaname = areaname+wxString::Format(_("终点：前方%.3f米   "),d1);
                        areaname = areaname+wxString::Format(_("半径R：%.3f米   "),r1);
                        areaname = areaname+_("转向：向左   ");

                    }
                }
                break;
            default:
                break;
            }
            //tipString[tips] =areaname;
            //tips++;
        }
    }
    if(nv>2)
    {
        if(cli->m1.t1)
        {
            if(headc<road_vertical(&cli->r,0)->l1)
            {
                ve = road_vertical(&cli->r,1);
                mv=1;
            }
            else if(headc>road_vertical(&cli->r,nv-2)->l1+road_vertical(&cli->r,nv-2)->length)
            {
                ve = road_vertical(&cli->r,nv-2);
                mv=nv-2;
            }
            else
            {
                ve = road_vertical_chain(&cli->r,headc,&mv);
            }
        }
        else
        {
            if(headc<road_vertical(&cli->r,0)->l1)
            {
                ve = road_vertical(&cli->r,1);
                mv=1;
            }
            else if(headc>road_vertical(&cli->r,nv-2)->l1+road_vertical(&cli->r,nv-2)->length)
            {
                ve = road_vertical(&cli->r,nv-2);
                mv=nv-2;
            }
            else
            {
                ve = road_vertical_chain(&cli->r,headc,&mv);
            }
        }

        areaname = _("当前竖曲线   ");
        switch(ve->type)
        {
        case ROAD_TYPE_LINE:
            areaname = areaname+_("类型：直线   ");
            if(cli->prj.a2z==1)
            {
                ver = tan(ve->angle1)*1000.0;
                d1 = ve->l1+ve->length-headc;
            }
            else
            {
                ver = -tan(ve->angle1)*1000.0;
                d1 = headc-he->l1;
            }
            areaname = areaname+wxString::Format(_("终点：前方%.3f米   "),d1);
            areaname = areaname+wxString::Format(_("坡度：%.3f ‰   "),ver);
            break;
        case ROAD_TYPE_ARC:
            areaname = areaname+_("类型：圆曲线   ");
            if(cli->prj.a2z==1)
            {
                d1 = ve->l1+ve->length-headc;
                r1 = ve->radius;
                areaname = areaname+wxString::Format(_("终点：前方%.3f米 "),d1);
                areaname = areaname+wxString::Format(_("半径R：%.1f米   "),r1);
                if(ve->pz==0)
                {
                    areaname = areaname+_("转向：向下   ");
                }
                else
                {
                    areaname = areaname+_("转向：向上   ");
                }
            }
            else
            {
                d1 = headc-he->l1;
                r1 = ve->radius;
                areaname = areaname+wxString::Format(_("终点：%.3f米   "),d1);
                areaname = areaname+wxString::Format(_("半径R：%.1f米   "),r1);
                if(ve->pz==0)
                {
                    areaname = areaname+_("转向：向下   ");
                }
                else
                {
                    areaname = areaname+_("转向：向上   ");
                }
            }
            break;
        default:
            break;
        }

        //tipString[tips] =areaname;
        //tips++;
    }

    if(cli->prj.a2z==1)
    {
        if(mh<nh-2)
        {
            he = road_horizon(&cli->r,mh+1);
            areaname = _("下段平曲线   ");

            switch(he->type)
            {
            case ROAD_TYPE_LINE:
                areaname = areaname+_("类型：直线   ");
                d1 = he->l1-headc;
                areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                break;
            case ROAD_TYPE_SPIRAL:
                areaname = areaname+_("类型：缓和曲线   ");
                d1 = he->l1-headc;
                if(he->pz==0)
                {
                    areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                    areaname = areaname+_("转向：向左   ");
                }
                else
                {
                    areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                    areaname = areaname+_("转向：向右   ");
                }

                break;
            case ROAD_TYPE_ARC:
                areaname = areaname+_("类型：圆曲线   ");
                if(he->pz==0)
                {
                    d1 = he->l1-headc;
                    r1 = he->radius;
                    areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                    areaname = areaname+wxString::Format(_("半径R:%.3f米   "),r1);
                    areaname = areaname+_("转向：向左   ");
                }
                else
                {
                    d1 = he->l1-headc;
                    r1 = he->radius;
                    areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                    areaname = areaname+wxString::Format(_("半径R:%.3f米   "),r1);
                    areaname = areaname+_("转向：向右   ");
                }
                break;
            default:
                break;
            }
            //tipString[tips] =areaname;
            //tips++;
        }

        if(mv<nv-2)
        {
            ve = road_vertical(&cli->r,mv+1);

            areaname = _("下段竖曲线   ");
            switch(ve->type)
            {
            case ROAD_TYPE_LINE:
                areaname = areaname+_("类型：直线   ");
                ver = tan(ve->angle1)*1000.0;
                d1 = ve->l1-headc;
                areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                areaname = areaname+wxString::Format(_("坡度：%.3f ‰   "),ver);
                break;
            case ROAD_TYPE_ARC:
                areaname = areaname+_("类型：圆曲线   ");
                d1 = ve->l1+ve->length-headc;
                r1 = ve->radius;
                areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                areaname = areaname+wxString::Format(_("半径R:%.1f米   "),r1);
                if(ve->pz==0)
                {
                    areaname = areaname+_("转向：向下   ");
                }
                else
                {
                    areaname = areaname+_("转向：向上   ");
                }
                break;
            default:
                break;
            }

            //tipString[tips] =areaname;
            //tips++;
        }
    }
    else
    {
        if(mh>1)
        {
            he = road_horizon(&cli->r,mh-1);

            areaname = _("下段平曲线   ");
            switch(he->type)
            {
            case ROAD_TYPE_LINE:
                areaname = areaname+_("类型：直线   ");
                d1 = headc-he->l1-he->length;
                areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                break;
            case ROAD_TYPE_SPIRAL:
                areaname = areaname+_("类型：缓和曲线   ");
                d1 = headc-he->l1-he->length;
                if(he->pz==0)
                {
                    areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                    areaname = areaname+_("转向：向右   ");
                }
                else
                {
                    areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                    areaname = areaname+_("转向：向左   ");
                }

                break;
            case ROAD_TYPE_ARC:
                areaname = areaname+_("类型：圆曲线   ");
                d1 = headc-he->l1-he->length;
                r1 = he->radius;
                if(he->pz==0)
                {
                    areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                    areaname = areaname+wxString::Format(_("半径R:%.3f米   "),r1);
                    areaname = areaname+_("转向：向左   ");
                }
                else
                {
                    areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                    areaname = areaname+wxString::Format(_("半径R:%.3f米   "),r1);
                    areaname = areaname+_("转向：向右   ");
                }
                break;
            default:
                break;
            }
            //tipString[tips] =areaname;
            //tips++;
        }

        if(mv>1)
        {
            ve = road_vertical(&cli->r,mv-1);
            areaname = _("下段竖曲线   ");

            switch(ve->type)
            {
            case ROAD_TYPE_LINE:
                areaname = areaname+_("类型：直线   ");
                ver = -tan(ve->angle1)*1000.0;
                d1 = headc-ve->l1-ve->length;
                areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                areaname = areaname+wxString::Format(_("坡度：%.3f ‰   "),ver);
                break;
            case ROAD_TYPE_ARC:
                areaname = areaname+_("类型：圆曲线   ");
                d1 = headc-ve->l1-ve->length;
                r1 = ve->radius;
                areaname = areaname+wxString::Format(_("前方:%.3f米   "),d1);
                areaname = areaname+wxString::Format(_("半径R:%.1f米   "),r1);

                if(ve->pz==0)
                {
                    areaname = areaname+_("转向：向下   ");
                }
                else
                {
                    areaname = areaname+_("转向：向上   ");
                }

                break;
            default:
                break;
            }

            //tipString[tips] =areaname;
            //tips++;
        }
    }


    if(cli->nks > 0)
    {
        for(int i=0;i<cli->nks;i++)
        {
            //if(tips == 10) break;
            if(cli->prj.a2z == 1)
            {
                if(cli->keys[i].mile1>=headc && cli->keys[i].mile1-headc<cli->prj.tip)
                {
                    areaname = wxString(cli->keys[i].name,wxConvUTF8);
                    areaname = areaname+_("     ");
                    areaname = areaname+_("前方：  ")+wxString::Format(_("%.2fm"),cli->keys[i].mile1-headc);
                    //tipString[tips] = areaname;
                    //tips++;
                }
                if(cli->keys[i].mile2<=headc && headc-cli->keys[i].mile2<cli->prj.tip)
                {
                    areaname = wxString(cli->keys[i].name,wxConvUTF8);
                    areaname = areaname+_("     ");
                    areaname = areaname+_("后方：  ")+wxString::Format(_("%.2fm"),headc-cli->keys[i].mile2);
                    //tipString[tips] = areaname;
                    //tips++;
                }
            }
            else
            {
                //if(cli->keys[tips].mile1<headc && headc-cli->keys[i].mile1<cli->prj.tip)
                {
                    areaname = wxString(cli->keys[i].name,wxConvUTF8);
                    areaname = areaname+_("     ");
                    areaname = areaname+_("前方：  ")+wxString::Format(_("%.2fm"),headc-cli->keys[i].mile1);
                    //tipString[tips] = areaname;
                    //tips++;
                }
                //if(cli->keys[tips].mile2>headc && cli->keys[i].mile2-headc<cli->prj.tip)
                {
                    areaname = wxString(cli->keys[i].name,wxConvUTF8);
                    areaname = areaname+_("     ");
                    areaname = areaname+_("后方：  ")+wxString::Format(_("%.2fm"),cli->keys[i].mile2-headc);
                    //tipString[tips] = areaname;
                    //tips++;
                }
            }
        }

    }

    wxFont chs(10*sx,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

    //dc.SetUserScale(sx,sx);
    dc.SetFont(chs);

    ///关键区域提醒
    dc.SetTextForeground(wxColor(71,71,71));

    //dc.DrawLabel(tipString[tip],wxRect(7*sx,0,w-5,h),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

    //fclose(fp);
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

void mtg_tFrame::PaintHorizon(wxMemoryDC* memDC, wxRect rect,double ds)
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
    //FILE* fp = fopen("E:\\painthorizon.log","w");
	ds = h/6/ds;

	int nh = road_number_horizon(&cli->r);

    memDC->SetPen(wxPen(wxColor(112,112,112)));
    memDC->SetBrush(wxBrush(wxColor(248,248,248)));
    memDC->DrawRectangle(x,y,w,h-1);
    double d1,d2,pds;
    if(cli->m1.t1>0)
    {
        d1 = (cli->m0.head[0]-cli->m0.mid[0])*(cli->m0.head[0]-cli->m0.mid[0])+(cli->m0.head[1]-cli->m0.mid[1])*(cli->m0.head[1]-cli->m0.mid[1])+(cli->m0.head[2]-cli->m0.mid[2])*(cli->m0.head[2]-cli->m0.mid[2]);
        d1 = sqrt(d1);
        d2 = (cli->m0.tail[0]-cli->m0.mid[0])*(cli->m0.tail[0]-cli->m0.mid[0])+(cli->m0.tail[1]-cli->m0.mid[1])*(cli->m0.tail[1]-cli->m0.mid[1])+(cli->m0.tail[2]-cli->m0.mid[2])*(cli->m0.tail[2]-cli->m0.mid[2]);
        d2 = sqrt(d2);
        pds = d2/(d1+d2);
    }
    else
    {
        d1=cli->tbm.L[3];
        d2=cli->tbm.L[0]-cli->tbm.L[3];
        pds = d2/(d1+d2);
    }
    //fprintf(fp,"%.4f,%.4f,%.4f\n",d1,d2,pds);
    //fflush(fp);
    ///??????
    int w1=w*1/4;
    int h1=y+h/2;
    int w2=w*3/4;
    int h2=y+h/2;
    int w3=w1+w/2*pds;
    int h3=y+h/2;

    //cli->m1.headc=22992.493;
    ///????200?
    double l1,l2;
    if(cli->m1.t1<=0)
    {
        if(cli->prj.a2z==1)
        {
            l1 = cli->prj.mile1-25.0;
            l2 = l1+50.0;
        }
        else
        {
            l1 = cli->prj.mile2+25;
            l2 = l1-50.0;
        }
    }
    else
    {
        if(cli->prj.a2z==1)
        {
            l1 = cli->m1.headc-25.0;
            l2 = l1+50.0;
        }
        else
        {
            l1 = cli->m1.headc+25.0;
            l2 = l1-50.0;
        }
    }

    double x1=0.0,y1=0.0,x2=0.0,y2=0.0,x3=0.0,y3=0.0;
    double alf=0.0,alf1=0.0,alf2=0.0;

    if(nh>2)
    {
        road_l2xy(&cli->r,l1,&x1,&y1,0);
        road_l2xy(&cli->r,l2,&x2,&y2,0);

        alf1 = atan2(y2-y1,x2-x1);
        if(alf1<0.0) alf1 = alf1+2.0*PI;
        double li=l1;
        double s=w/50.0;
        wxPoint lines[60];
        int nlines=0;
        double len = 0.0;
        h_element* e;
        int hi;
        e = road_horizon_chain(&cli->r,li,&hi);

        while(1)
        {
            if(nlines>59) break;
            e = road_horizon(&cli->r,hi);

            if(e)
            {
                //fprintf(fp,"%d,%d\n",nlines,hi);
                //if(nlines>0) fprintf(fp,"%d,%.4f,%d,%d\n",nlines,li,lines[nlines-1].x,lines[nlines-1].y);
                if(e->type==ROAD_TYPE_START_POINT)
                {
                    lines[nlines].x = x;
                    lines[nlines].y = y+h/2;
                    nlines++;
                    if(cli->prj.a2z==1)
                    {
                        hi++;
                    }
                    else
                    {
                        road_l2xy(&cli->r,l2,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        if(alf<-PI/2.0) alf=alf+PI;
                        if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        nlines++;
                        break;
                    }
                    //fprintf(fp,"%d,%.4f,%.4f\n",nlines,lines[nlines-1].x,lines[nlines-1].y);
                }
                else if(e->type==ROAD_TYPE_LINE)
                {
                    if(cli->prj.a2z==1)
                    {
                        road_l2xy(&cli->r,li,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        if(alf<-PI/2.0) alf=alf+PI;
                        if(alf>PI/2.0) alf=alf-PI;

                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        nlines++;
                        //fprintf(fp,"%d,%d,%d\n",nlines,lines[nlines].x,lines[nlines].y);
                        if(l2>e->l1+e->length)
                        {
                            x2 = e->x2;
                            y2 = e->y2;
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            if(alf<-PI/2.0) alf=alf+PI;
                            if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            hi++;
                            li = e->l1+e->length;
                        }
                        else
                        {
                            road_l2xy(&cli->r,l2,&x2,&y2,0);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            if(alf<-PI/2.0) alf=alf+PI;
                            if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            //fprintf(fp,"%d,%d,%d\n",nlines,lines[nlines].x,lines[nlines].y);
                            break;
                        }
                    }
                    else
                    {
                        road_l2xy(&cli->r,li,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        if(alf<-PI/2.0) alf=alf+PI;
                        if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;

                        nlines++;

                        if(l2<e->l1)
                        {
                            x2 = e->x1;
                            y2 = e->y1;
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            if(alf<-PI/2.0) alf=alf+PI;
                            if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            hi--;
                            li = e->l1;
                        }
                        else
                        {
                            road_l2xy(&cli->r,l2,&x2,&y2,0);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            if(alf<-PI/2.0) alf=alf+PI;
                            if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            break;
                        }
                    }
                }
                else if(e->type==ROAD_TYPE_ARC || e->type==ROAD_TYPE_SPIRAL)
                {
                    if(road_l2xy(&cli->r,li,&x2,&y2,0)>=0)
                    {
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        if(alf<-PI/2.0) alf=alf+PI;
                        if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;

                        if(lines[nlines].x == x+w)
                        {
                            nlines++;
                            break;
                        }
                        else if(lines[nlines].x > x+w)
                        {
                            lines[nlines].y = lines[nlines].y+(lines[nlines].y-lines[nlines-1].y)*(x+w-lines[nlines-1].x)/(lines[nlines].x-lines[nlines-1].x);
                            lines[nlines].x = x+w;
                            nlines++;
                            break;
                        }
                        nlines++;
                    }
                    if(cli->prj.a2z==1)
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
                    if(cli->prj.a2z==-1)
                    {
                        hi--;
                    }
                    else
                    {
                        road_l2xy(&cli->r,l2,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        if(alf<-PI/2.0) alf=alf+PI;
                        if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        nlines++;
                        break;
                    }
                }
            }
        }

        if(nlines>0)
        {
            int i1=0;
            for(int i=0;i<nlines-1;i++)
            {
                memDC->SetPen(wxPen(wxColor(255,255,255),1));
                memDC->SetPen(wxPen(wxColor(58,58,58),1));
                memDC->DrawLine(lines[i].x,lines[i].y,lines[i+1].x,lines[i+1].y);

                if(lines[i].x<=x+w1 && lines[i+1].x>x+w1)
                {
                    h1 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w1-lines[i].x)/(lines[i+1].x-lines[i].x);
                }

                if(lines[i].x<=x+w3 && lines[i+1].x>x+w3)
                {
                    h3 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w3-lines[i].x)/(lines[i+1].x-lines[i].x);
                }

                if(lines[i].x<=x+w2 && lines[i+1].x>x+w2)
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

    if(cli->m1.t1>0)
    {
        h1 = h1+cli->m1.tailh*1000*ds;
        h2 = h2+cli->m1.headh*1000*ds;
        if(fabs(cli->m1.midh)>0.5) cli->m1.midh = (cli->m1.headh+cli->m1.tailh)/2.0;
        h3 = h3+cli->m1.midh*1000*ds;
    }

    int w4,h4;
    int dw1=15*sx;
    int dh1;
    int dw2,dh2;
    double xd;
    wxPoint arrow[3];
    if(cli->tbm.type>0)
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

    if(cli->tbm.type>0)
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
    //fclose(fp);
}

void mtg_tFrame::PaintVertical(wxMemoryDC* memDC, wxRect rect,double ds)
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
    //FILE* fp=fopen("E:\\PaintVertical.log","w");
    memDC->SetPen(wxPen(wxColor(112,112,112)));
    memDC->SetBrush(wxBrush(wxColor(248,248,248)));
    memDC->DrawRectangle(x,y+1,w,h-2);

    double d1,d2,pds;
    if(cli->m1.t1>0)
    {
        d1 = (cli->m0.head[0]-cli->m0.mid[0])*(cli->m0.head[0]-cli->m0.mid[0])+(cli->m0.head[1]-cli->m0.mid[1])*(cli->m0.head[1]-cli->m0.mid[1])+(cli->m0.head[2]-cli->m0.mid[2])*(cli->m0.head[2]-cli->m0.mid[2]);
        d1 = sqrt(d1);
        d2 = (cli->m0.tail[0]-cli->m0.mid[0])*(cli->m0.tail[0]-cli->m0.mid[0])+(cli->m0.tail[1]-cli->m0.mid[1])*(cli->m0.tail[1]-cli->m0.mid[1])+(cli->m0.tail[2]-cli->m0.mid[2])*(cli->m0.tail[2]-cli->m0.mid[2]);
        d2 = sqrt(d2);
        pds = d2/(d1+d2);
    }
    else
    {
        d1=cli->tbm.L[3];
        d2=cli->tbm.L[0]-cli->tbm.L[3];
        pds = d2/(d1+d2);
    }

    int nv = road_number_vertical(&cli->r);

    int w1=w/4;
    int h1=y+h/2;
    int w2=w*3/4;
    int h2=y+h/2;
    int w3 = w1+w/2*d2/(d1+d2);
    int h3=y+h/2;
    ///????200?
    //cli->m1.headc=22992.493;
    double l1,l2;
    if(cli->m1.t1<=0)
    {
        if(cli->prj.a2z==1)
        {
            l1 = cli->prj.mile1-25.0;
            l2 = l1+50.0;
        }
        else
        {
            l1 = cli->prj.mile2+25;
            l2 = l1-50.0;
        }
    }
    else
    {
        if(cli->prj.a2z==1)
        {
            l1 = cli->m1.headc-25.0;
            l2 = l1+50.0;
        }
        else
        {
            l1 = cli->m1.headc+25.0;
            l2 = l1-50.0;
        }
    }

    double x1=0.0,y1=0.0,x2=0.0,y2=0.0,x3=0.0,y3=0.0;
    double alf=0.0,alf1=0.0,alf2=0.0;
    x1 = l1;

    if(nv>2)
    {
        double li=l1;
        double s=w/50.0;
        wxPoint lines[60];
        int nlines=0;
        double len = 0.0;
        int vi;
        v_element* e = road_vertical_chain(&cli->r,li,&vi);
        road_l2h(&cli->r,l1,&y1,&alf1);
        if(alf1<0.0) alf1 = alf1+2.0*PI;
        //fprintf(fp,"%d,%.4f,%.4f,%.12f\n",vi,li,y1,alf1);
        while(1)
        {
            if(nlines>59) break;
            e = road_vertical(&cli->r,vi);
            if(e)
            {
                if(e->type==ROAD_TYPE_START_POINT)
                {
                    lines[nlines].x = x;
                    lines[nlines].y = y+h/2;
                    nlines++;
                    if(cli->prj.a2z==1)
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
                    if(cli->prj.a2z==1)
                    {
                        x2 = li;
                        road_l2h(&cli->r,li,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        x2 = x+len*cos(alf2);
                        y2 = y+h/2-len*sin(alf2)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        //fprintf(fp,"%d,%d,%d,%d,%.4f\n",nlines,lines[nlines].x,lines[nlines].y,x,li);
                        nlines++;

                        if(l2>e->l1+e->length)
                        {
                            x2 = e->l1+e->length;
                            y2 = e->h2;
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            x2 = x+len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            vi++;
                            li = e->l1+e->length;
                        }
                        else
                        {
                            x2 = l2;
                            road_l2h(&cli->r,l2,&y2,0);
                            //fprintf(fp,"l2:%.4f,y2:%.4f\n",l2,y2);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;
                            //fprintf(fp,"%.4f,%.4f,%.4f\n",x2,y2,len);

                            x2 = x+len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            break;
                        }
                    }
                    else
                    {
                        x2 = li;
                        road_l2h(&cli->r,li,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        x2 = x-len*cos(alf2);
                        y2 = y+h/2-len*sin(alf2)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;

                        nlines++;
                        //fprintf(fp,"%.4f,%.4f\n",l2,e->l1);
                        if(l2<e->l1-e->length)
                        {
                            //wxMessageBox(_("ok"));
                            x2 = e->l1;
                            y2 = e->h1;
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            x2 = x-len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            vi++;
                            li=e->l1;
                        }
                        else
                        {
                            x2 = l2;
                            road_l2h(&cli->r,l2,&y2,0);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            x2 = x-len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;

                            nlines++;
                            break;
                        }
                    }
                }
                else if(e->type==ROAD_TYPE_ARC)
                {
                    if(road_l2h(&cli->r,li,&y2,0)>=0)
                    {
                        //fprintf(fp,"%.4f,%.4f\n",li,y2);
                        //fflush(fp);
                        x2 = li;
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        x2 = x+fabs(len*cos(alf2));
                        y2 = y+h/2-len*sin(alf2)*2.0;
                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        //fprintf(fp,"%d,%d\n",lines[nlines].x,x+w);
                        //fflush(fp);
                        if(lines[nlines].x > x+w)
                        {
                            lines[nlines].y = lines[nlines].y+(lines[nlines].y-lines[nlines-1].y)*(x+w-lines[nlines-1].x)/(lines[nlines].x-lines[nlines-1].x);
                            lines[nlines].x = x+w;
                            nlines++;
                            break;
                        }
                        nlines++;
                    }
                    if(cli->prj.a2z==1)
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
                    if(cli->prj.a2z==1)
                    {
                        lines[nlines].x = x+w;
                        lines[nlines].y = y+h/2;
                        nlines++;
                        vi--;
                    }
                    else
                    {
                        x2 = l2;
                        road_l2h(&cli->r,l2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;
                        //fprintf(fp,"%.4f,%.4f,%.4f\n",x2,y2,len);
                        //alf = mtg_sub_angle(alf2,alf1);
                        x2 = x+len*cos(alf2);
                        y2 = y+h/2-len*sin(alf2)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        nlines++;
                        break;
                    }
                }
            }
        }


        if(nlines>0)
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
        //memDC->SetPen(wxPen(wxColor(75,255,0)));
        memDC->DrawLine(x,y+h/2,x+w,y+h/2);
        h1 = y+h/2;
        h2 = y+h/2;
        h3 = y+h/2;
    }

    if(cli->m1.t1>0)
    {
        h1 = h1-cli->m1.tailv*1000*ds;
        h2 = h2-cli->m1.headv*1000*ds;
        if(fabs(cli->m1.midv)>0.5) cli->m1.midv = (cli->m1.headv+cli->m1.tailv)/2.0;
        h3 = h3 - cli->m1.midv*1000*ds;
    }
    int w4,h4;
    int dw1=15*sx;
    int dh1;
    int dw2,dh2;
    double xd;
    wxPoint arrow[3];
    if(cli->tbm.type>0)
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

    if(cli->tbm.type>0)
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
    //fclose(fp);
}

void mtg_tFrame::OnPaintGraph(wxPaintEvent& event)
{
    wxBufferedPaintDC dc(panelGraph);
    int w,h;
    GetSize(&w,&h);
    double sx,sy;
    sx=w/1024.0;
    sy=h/768.0;
    if(sx > sy)
    {
        sx = sy;
    }
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
        memDC.SetPen(wxPen(wxColor(255,0,0),2));
        int xy[4];
        xy[0]=w/2-pw1/2*s;
        xy[1]=h*7/20;
        xy[2]=pw2*3/2*s;
        xy[3]=(h*7/20);
        //memDC.DrawLine(xy[0],xy[1],xy[0]+(xy[2]-xy[0]),xy[1]+(xy[3]-xy[1]));
        xy[0]=w/2+pw1/2*s;
        xy[1]=h*7/20;
        xy[2]=w-33*sx;
        xy[3]=h*7/20;
        memDC.SetPen(wxPen(wxColor(255,0,0),2));
        //memDC.DrawLine(xy[0],xy[1],xy[0]+xy[2]-xy[0],xy[1]+xy[3]-xy[1]);
        if(drawAnimation)
        {
            if(tpsDirection==0)
            {
                xy[0]=w/2/sx1-w1/sx1;
                xy[1]=(h*7/20)/sx1;
                xy[2]=31*sx/sx1;
                xy[3]=(h*7/20)/sx1;
                memDC.SetPen(wxPen(wxColor(255,0,0),2));
                memDC.DrawLine(xy[0],xy[1],xy[0]+(xy[2]-xy[0])*tickAnimation/10,xy[1]+(xy[3]-xy[1])*tickAnimation/10);
            }
            else if(tpsDirection==1)
            {
                xy[0]=w/2/sx1;
                xy[1]=(h*7/20)/sx1;
                xy[2]=(w-33*sx)/sx1;
                xy[3]=(h*7/20)/sx1;
                memDC.SetPen(wxPen(wxColor(255,0,0),2));
                memDC.DrawLine(xy[0],xy[1],xy[0]+(xy[2]-xy[0])*tickAnimation/10,xy[1]+(xy[3]-xy[1])*tickAnimation/10);
            }
        }


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnPaintTime(wxPaintEvent& event)
{
    wxPaintDC dc(panelTime);
    int w,h;
    GetSize(&w,&h);

    double sx=w/1024.0;
    double sy=h/768.0;
    if(sx>sy)
    {
        sx = sy;
    }
    panelTime->GetClientSize(&w,&h);
    ///background
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        wxFont chs1(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont chs2(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetBrush(wxBrush(wxColor(98,98,98)));
        memDC.SetPen(wxPen(wxColor(0,0,0)));
        memDC.DrawRectangle(0,0,w,h);

        memDC.SetFont(chs1);
        int c1 = 132;
        int c2 = 132;
        int c3 = 132;

        for(int i=0;i<w/2;i++)
        {
            c1--;
            c2--;
            c3--;
            memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
            memDC.DrawLine(i,h/2,i,h);
        }
        for(int i=w/2;i<=w;i++)
        {
            c1++;
            c2++;
            c3++;
            memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
            memDC.DrawLine(i,h/2,i,h);
        }
        memDC.SetPen(wxPen(wxColor(28,48,98)));
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        memDC.DrawRectangle(0,h/2,w,h/2);
        wxString timeString;
        memDC.SetTextForeground(wxColor(251,188,23));
        memDC.DrawLabel(_("计时"),wxRect(0,0,w,h/2),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
        ///测量时间
        memDC.SetFont(chs2);
        if(cli->m1.t1)
        {
            //dc.SetFont(fontSmallValue);
            time_t now;
            time(&now);
            time_t overTime;
            overTime=now-cli->m1.t1;
            if(overTime>cli->sets.talw)
            {
                memDC.SetTextForeground(wxColor(250,30,60));
            }
            else
            {
                memDC.SetTextForeground(wxColor(0,255,0));
            }
            int oh=overTime/3600;
            int om=(overTime-oh*3600)/60;
            int os=(overTime-oh*3600-om*60);
            timeString=wxString::Format(wxString::Format(_("%d"),oh)+_(":")+wxString::Format(_("%d"),om)+_(":")+wxString::Format(_("%d"),os));
            memDC.DrawLabel(wxString::Format(_("%s"),timeString),wxRect(0,h/2,w,h*1/2),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(wxColor(250,30,60));
            memDC.DrawLabel(_("---"),wxRect(0,h/2,w,h*1/2),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
    //wxFont fontCaption(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
}

void mtg_tFrame::OnPaintBar(wxPaintEvent& event)
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
        x1 = hrect.x;
        w1 = hrect.width;
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
        memDC.DrawLabel(wxString(cli->prj.name,wxConvUTF8),wxRect(x3,y3,w3,h3),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetFont(eni);
        if(cli->m1.t1>0)
        {
            double p1=cli->prj.mile1-cli->prj.mile2;
            p1=fabs(p1);
            double p2=cli->m1.headc-cli->prj.mile1;
            p2=fabs(p2);
            memDC.SetBrush(wxBrush(wxColor(204,251,200)));
            memDC.DrawRectangle(x1+1,y1+1,(w1-2)*p2/p1,h1-2);
            valstr=wxString::Format(_("%.1f"),p2*100/p1)+_("%(")+wxString::Format(_("%.1f"),p2)+_("m)");
            memDC.DrawLabel(valstr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            double p1=cli->prj.mile1-cli->prj.mile2;
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

void mtg_tFrame::ReadMap()
{
    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);

    wxString vpath;
    vpath = path+_("/plugins/v_map.map");

    if(wxFileExists(vpath))
    {
        char vbuf[1024];
        char vname[64];
        int vmaps;
        int mapw,maph;
        int mapw0,maph0;
        strcpy(vbuf,vpath.mb_str(wxConvLocal));
        FILE* fp=fopen(vbuf,"rb");
        if(fp)
        {
            fread(vname,64,1,fp);
            fread(&vmaps,sizeof(int),1,fp);
            for(int i=0;i<vmaps;i++)
            {
                fread(&mapw,sizeof(int),1,fp);
                fread(&maph,sizeof(int),1,fp);
                unsigned char* vuc=new unsigned char[mapw*maph*3];
                fread(vuc,mapw*maph*3,1,fp);
                if(i==0)
                {
                    //v_map.Create(mapw,maph);
                    //v_map.SetData(vuc);
                    mapw0 = mapw;
                    maph0 = maph;
                }
                if(i==vmaps-1)
                {
                    v_map.Create(mapw,maph);
                    v_map.SetData(vuc);
                    vmapw = mapw;
                    vmaph = maph;
                }
            }
            for(int i=0;i<2;i++)
            {
                fread(&mapx1[i],sizeof(double),1,fp);
                fread(&mapy1[i],sizeof(double),1,fp);
                fread(&mapx2[i],sizeof(double),1,fp);
                fread(&mapy2[i],sizeof(double),1,fp);
                mapx1[i] = mapx1[i]*vmapw/mapw0;
                mapy1[i] = mapy1[i]*vmaph/maph0;
            }
        }
        double diff1=0.0,diff2=0.0;
        road_l2h(&cli->r,mapx2[0],&diff1,0);
        diff1 = mapy2[0]-diff1;
        road_l2h(&cli->r,mapx2[1],&diff2,0);
        diff2 = mapy2[1]-diff2;
        //road_xy2l(&cli->r,mapx2[0],mapy2[0],0,0,0,0,&diff1);
        //road_xy2l(&cli->r,mapx2[1],mapy2[1],0,0,0,0,&diff2);

        isvmap = 0;
        /*if(fabs(diff1)>0.01 || fabs(diff2)>0.01)
        {
            isvmap = -1;
        }
        else
        {
            isvmap = 0;
        }*/
        fclose(fp);
    }
}

void mtg_tFrame::Coor2Map(double* x,double* y)
{
    double d1 = sqrt((mapx2[0]-mapx2[1])*(mapx2[0]-mapx2[1])+(mapy2[0]-mapy2[1])*(mapy2[0]-mapy2[1]));
    double d2 = sqrt((mapx1[0]-mapx1[1])*(mapx1[0]-mapx1[1])+(mapy1[0]-mapy1[1])*(mapy1[0]-mapy1[1]));
    double s = d1/d2;
    double ang1 = atan2(mapy1[1]-mapy1[0],mapx1[1]-mapx1[0]);
    double ang2 = atan2(mapy2[1]-mapy2[0],mapx2[1]-mapx2[0]);
    if(ang1<0) ang1+=2.0*PI;
    if(ang2<0) ang2+=2.0*PI;
    double ang = 0.0;//mtg_sub_angle(ang2,ang1);

    if(cli->m1.t1<=0)
    {
        if(cli->prj.a2z==0)
        {
            *x = mapx1[0];
            *y = mapy1[0];
            return;
        }
        else
        {
            *x = mapx1[1];
            *y = mapy1[1];
            return;
        }
    }
    else
    {
        d1 = sqrt((mapx2[0]-cli->m1.headc)*(mapx2[0]-cli->m1.headc)+(mapy2[0]-cli->m1.head[2])*(mapy2[0]-cli->m1.head[2]));
    }
    d1 = d1*s;

    ang2 = atan2(cli->m1.head[2]-mapy2[0],cli->m1.headc-mapx2[0]);
    if(ang2<0) ang2+=2.0*PI;
    ang2 = ang2+ang;
    *x = mapx1[0]+d1*cos(ang2);
    *y = mapy1[0]+d1*sin(ang2);
}

void mtg_tFrame::OnPaintMetric(wxPaintEvent& event)
{
    wxPaintDC dc(panelMetric);
    //FILE* fp=fopen("E:\\metric.log","w");
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

        wxFont chs(10*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng1(12*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        wxFont eng2(15*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        if(cli->iOk==0)
        {
            memDC.SetTextForeground(wxColor(255,0,0));
            memDC.DrawLabel(_("正在初始化运行环境！"),wxRect(0,0,w,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            dc.Blit(0,0,w,h,&memDC,0,0);
            return;
        }

        int headh;
        int headv;
        int tailh;
        int tailv;
        int midh;
        int midv;
        double yawh,yawv,yaws;
        double t_len;
        double headc,tailc,midc;
        double head[3];
        double val;
        int a2z=cli->prj.a2z;
        ///平面偏差
        int maxw,maxh,maxl;
        maxw=0;
        maxh=0;
        if(cli->tbm.type==0)
        {
            t_len = (cli->m1.head[0]-cli->m1.tail[0])*(cli->m1.head[0]-cli->m1.tail[0])+(cli->m1.head[1]-cli->m1.tail[1])*(cli->m1.head[1]-cli->m1.tail[1]);
            t_len = sqrt(t_len);
            if(cli->sets.head==1)
            {
                head[0]=(cli->m1.head[0]-cli->m1.tail[0])/t_len;
                head[1]=(cli->m1.head[1]-cli->m1.tail[1])/t_len;
                head[2]=(cli->m1.head[2]-cli->m1.tail[2])/t_len;
                head[0]=cli->m1.head[0]+head[0]*cli->tbm.L[4];
                head[1]=cli->m1.head[1]+head[1]*cli->tbm.L[4];
                head[2]=cli->m1.head[2]+head[2]*cli->tbm.L[4];
                road_xy2l(&cli->r,head[0],head[1],&headc,0,0,0,&val);
                headh=val*1000.0*a2z;
                road_l2h(&cli->r,headc,&val,0);
                headv=(head[2]-val)*1000.0;
            }
            else
            {
                headh=cli->m1.headh*1000.0;
                headv=cli->m1.headv*1000.0;
                headc=cli->m1.headc;
            }
            tailh=cli->m1.tailh*1000.0;
            tailv=cli->m1.tailv*1000.0;
            maxw = abs(headh)>abs(tailh)?abs(headh):abs(tailh);
            maxh = abs(headv)>abs(tailv)?abs(headv):abs(tailv);
        }
        else if(cli->tbm.type==1)
        {
            t_len = (cli->m1.head[0]-cli->m1.mid[0])*(cli->m1.head[0]-cli->m1.mid[0])+(cli->m1.head[1]-cli->m1.mid[1])*(cli->m1.head[1]-cli->m1.mid[1]);
            t_len = sqrt(t_len);
            if(cli->sets.head==1)
            {
                head[0]=(cli->m1.head[0]-cli->m1.mid[0])/t_len;
                head[1]=(cli->m1.head[1]-cli->m1.mid[1])/t_len;
                head[2]=(cli->m1.head[2]-cli->m1.mid[2])/t_len;
                head[0]=cli->m1.head[0]+head[0]*cli->tbm.L[4];
                head[1]=cli->m1.head[1]+head[1]*cli->tbm.L[4];
                head[2]=cli->m1.head[2]+head[2]*cli->tbm.L[4];
                road_xy2l(&cli->r,head[0],head[1],&headc,0,0,0,&val);
                headh=val*1000.0*a2z;
                road_l2h(&cli->r,headc,&val,0);
                headv=(head[2]-val)*1000.0;
            }
            else
            {
                headh=cli->m1.headh*1000.0;
                headv=cli->m1.headv*1000.0;
                headc=cli->m1.headc;
            }
            tailh=cli->m1.tailh*1000.0;
            tailv=cli->m1.tailv*1000.0;
            midh=cli->m1.midh*1000.0;
            midv=cli->m1.midv*1000.0;
            maxw = abs(headh)>abs(midh)?abs(headh):abs(midh);
            maxh = abs(headv)>abs(midv)?abs(headv):abs(midv);
        }
        else if(cli->tbm.type==2)
        {
            t_len = (cli->m1.head[0]-cli->m1.mid[0])*(cli->m1.head[0]-cli->m1.mid[0])+(cli->m1.head[1]-cli->m1.mid[1])*(cli->m1.head[1]-cli->m1.mid[1]);
            t_len = sqrt(t_len);
            if(cli->sets.head==1)
            {
                head[0]=(cli->m1.head[0]-cli->m1.mid[0])/t_len;
                head[1]=(cli->m1.head[1]-cli->m1.mid[1])/t_len;
                head[2]=(cli->m1.head[2]-cli->m1.mid[2])/t_len;
                head[0]=cli->m1.head[0]+head[0]*cli->tbm.L[4];
                head[1]=cli->m1.head[1]+head[1]*cli->tbm.L[4];
                head[2]=cli->m1.head[2]+head[2]*cli->tbm.L[4];
                road_xy2l(&cli->r,head[0],head[1],&headc,0,0,0,&val);
                headh=val*1000.0*a2z;
                road_l2h(&cli->r,headc,&val,0);
                headv=(head[2]-val)*1000.0;
            }
            else
            {
                headh=cli->m1.headh*1000.0;
                headv=cli->m1.headv*1000.0;
                headc=cli->m1.headc;
            }
            tailh=cli->m1.tailh*1000.0;
            tailv=cli->m1.tailv*1000.0;
            midh=cli->m1.midh*1000.0;
            midv=cli->m1.midv*1000.0;
            maxw = abs(midh)>abs(tailh)?abs(midh):abs(tailh);
            maxh = abs(midv)>abs(tailv)?abs(midv):abs(tailv);
        }

        maxl = (maxw>maxh)?maxw:maxh;
        if(maxl <= 200)
        {
            maxl = 100;
        }
        else
        {
            maxl = 200;
        }

        tailh=cli->m1.tailh*1000.0;
        tailv=cli->m1.tailv*1000.0;
        midh=cli->m1.midh*1000.0;
        midv=cli->m1.midv*1000.0;

        if(abs(midh)>500) midh = (headh+tailh)/2.0;
        if(abs(midv)>500) midv = (headv+tailv)/2.0;

        tailc=cli->m1.tailc;
        midc=cli->m1.midc;
        if(cli->sets.vmileage==0)
        {
            int nmoff;
            nmoff=road_number_mile_off(&cli->r);
            if(nmoff>0)
            {
                m_offset *mo={0};
                for(int nn=nmoff-1;nn>=0;nn--)
                {
                    mo=road_mile_off(&cli->r,nn);
                    if(headc>mo->mile)
                    {
                        headc=headc+mo->off;
                        break;
                    }
                }
                for(int nn=nmoff-1;nn>=0;nn--)
                {
                    mo=road_mile_off(&cli->r,nn);
                    if(tailc>mo->mile)
                    {
                        tailc=tailc+mo->off;
                        break;
                    }
                }
                for(int nn=nmoff-1;nn>=0;nn--)
                {
                    mo=road_mile_off(&cli->r,nn);
                    if(midc>mo->mile)
                    {
                        midc=midc+mo->off;
                        break;
                    }
                }
            }
        }


        memDC.SetTextForeground(wxColor(28,28,28));
        ///姿态区域
        road* cl = &cli->r;
        int nh = road_number_horizon(cl);
        int nv = road_number_vertical(cl);
        double x[6]={0.0};
        double y[6]={0.0};
        double z[6]={0.0};
        wxString valstr;
        ///姿态圆半径
        int r[6];
        r[0] = (w*3/5)>(h-40*sy)?(h-40*sy)*19/40:(w*3/5)*19/40;
        r[0] = r[0]*9/10;
        for(int i=1;i<6;i++)
        {
            r[i]=r[i-1]-20*sxy;
        }
        int cell = r[0]/5;
        double s = (2.0*cell)/maxl;

        int gx1 = w*2/5;
        int gy1 = h/2-23;


        ///画平面图
        int gx2 = gx1+r[0]+35*sx;
        int gw2 = w-gx2+1;
        int gh2 = r[0];
        //int gx2 = w-15*sx-gw2;
        int gy2 = gy1-gh2;

        hrect.x=gx2;
        hrect.y=gy2;
        hrect.width=gw2;
        hrect.height=gh2;


        PaintHorizon(&memDC, wxRect(gx2,gy2,gw2,gh2),maxl);

        ///画垂直偏差图
        int gx3 = gx2;
        int gy3 = gy1;
        int gw3 = gw2;
        int gh3 = gh2;

        PaintVertical(&memDC, wxRect(gx3,gy3,gw3,gh3),maxl);

        ///环号及推进参数区域
        int gx5 = -1;
        int gy5 = gy2;
        int gw5 = gx1-r[0]-35*sx-gx5;
        int gh5 = r[0]*1/2;
        memDC.SetPen(wxPen(wxColor(105,105,105)));
        memDC.SetBrush(wxBrush(wxColor(248,248,248)));
        memDC.DrawRectangle(gx5,gy5,gw5,gh5);

        int ex1=gx5+10*sx;
        int ey1=gy5+10*sxy;
        int ew1=gw5-10*sx-10*sx;
        int eh1=35*sxy;
        memDC.SetPen(wxPen(wxColor(140,144,147)));
        //memDC.SetBrush(wxBrush(wxColor(190,194,197)));
        memDC.DrawRoundedRectangle(ex1,ey1,ew1,eh1,3);

        idxrect.x = gx5;
        idxrect.y = gy5;
        idxrect.width = gw5;
        idxrect.height = 85*sy;

        //memDC.DrawLine(gx5,gy5+idxrect.height,gx5+gw5,gy5+idxrect.height);
        memDC.SetFont(chs);

        mtcrect.x = gx5;
        mtcrect.y = gy5;
        mtcrect.width = gx1+r[0]-gx5;

        int ex2=gx5+10*sx;
        int ey2=gy5+55*sxy;
        int ew2=gw5-20*sx;
        int eh2=gh5-70*sxy;
        memDC.SetPen(wxPen(wxColor(140,144,147)));
        //memDC.SetBrush(wxBrush(wxColor(234,251,230)));
        memDC.SetBrush(wxBrush(wxColor(212,218,224)));
        memDC.DrawRectangle(ex2,ey2,ew2,eh2);

        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        ///转动角
        int gx6 = gx5;
        int gy6 = gy5+gh5;
        int gw6 = gw5;
        int gh6 = gh5;
        memDC.SetPen(wxPen(wxColor(105,105,105)));
        memDC.DrawRectangle(gx6,gy6,gw6,gh6);
        memDC.DrawLabel(_("转动角"),wxRect(gx6,gy6,gw6,30*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetFont(eng1);
        if(cli->sets.unit==0)
        {
            memDC.DrawLabel(_("[ mm/m ]"),wxRect(gx6,gy6+15*sxy,gw6,35*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("[ ° ]"),wxRect(gx6,gy6+15*sxy,gw6,35*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        ///俯仰角
        int gw7 = gw6;
        int gh7 = gh6;
        int gx7 = gx6;
        int gy7 = gy6+gh6;
        memDC.DrawRectangle(gx7,gy7,gw7,gh7);
        memDC.SetFont(chs);
        memDC.DrawLabel(_("俯仰角"),wxRect(gx7,gy7,gw7,30*sxy),wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetFont(eng1);
        if(cli->sets.unit==0)
        {
            memDC.DrawLabel(_("[ mm/m ]"),wxRect(gx7,gy7+15*sxy,gw7,35*sxy),wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("[ ° ]"),wxRect(gx7,gy7+15*sxy,gw7,35*sxy),wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        ///偏差及趋势
        memDC.SetBrush(wxBrush(wxColor(204,233,177)));
        memDC.SetPen(wxPen(wxColor(204,233,177)));
        memDC.SetTextForeground(wxColor(28,28,28));
        memDC.SetFont(chs);
        if(cli->tbm.type==0)
        {
            /*if(cli->alw[0]==0)
            {
                memDC.SetBrush(wxBrush(wxColor(75,255,0)));
            }
            else
            {
                memDC.SetBrush(wxBrush(wxColor(255,247,0)));
            }*/
            //memDC.DrawRoundedRectangle(gx2+gw2*3/4-20*sxy,gy2+10*sxy,50*sxy,25*sxy,3*sxy);
            memDC.DrawLabel(_("切口 "),wxRect(gx2+gw2*1/2+10*sxy,gy2+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            //memDC.DrawRoundedRectangle(gx2+gw2/2-25*sxy,gy2+10*sxy,50*sxy,30*sxy,3);
            //memDC.DrawLabel(_("中"),wxRect(gx2+gw2/2-25*sxy,gy2+10*sxy,0,30*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            /*if(cli->alw[2]==0)
            {
                memDC.SetBrush(wxBrush(wxColor(75,255,0)));
            }
            else
            {
                memDC.SetBrush(wxBrush(wxColor(255,247,0)));
            }*/
            //memDC.DrawRoundedRectangle(gx2+gw2/4-10*sxy,gy2+10*sxy,50*sxy,25*sxy,3*sxy);
            memDC.DrawLabel(_("盾尾 "),wxRect(gx2+10*sxy,gy2+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("水平偏航(mm/m)"),wxRect(gx2+10*sxy,gy2+gh2-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            /*if(cli->alw[1]==0)
            {
                memDC.SetBrush(wxBrush(wxColor(75,255,0)));
            }
            else
            {
                memDC.SetBrush(wxBrush(wxColor(255,247,0)));
            }*/
            //memDC.DrawRoundedRectangle(gx3+gw3*3/4-20*sxy,gy3+10*sxy,50*sxy,25*sxy,3*sxy);
            memDC.DrawLabel(_("切口 "),wxRect(gx3+gw3*1/2+10*sxy,gy3+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            //memDC.DrawRoundedRectangle(gx3+gw3/2-25*sxy,gy3+10*sxy,50*sxy,30*sxy,3);
            //memDC.DrawLabel(_("中"),wxRect(gx3+gw3/2-25*sxy,gy3+10*sxy,0,30*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            /*if(cli->alw[3]==0)
            {
                memDC.SetBrush(wxBrush(wxColor(75,255,0)));
            }
            else
            {
                memDC.SetBrush(wxBrush(wxColor(255,247,0)));
            }*/
            //memDC.DrawRoundedRectangle(gx3+gw3/4-10*sxy,gy3+10*sxy,50*sxy,25*sxy,3*sxy);
            memDC.DrawLabel(_("盾尾 "),wxRect(gx3+10*sxy,gy3+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("垂直偏航(mm/m)"),wxRect(gx3+10*sxy,gy3+gh3-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            /*if(cli->alw[0]==0)
            {
                memDC.SetBrush(wxBrush(wxColor(75,255,0)));
            }
            else
            {
                memDC.SetBrush(wxBrush(wxColor(255,247,0)));
            }*/
            //memDC.DrawRoundedRectangle(gx2+gw2*3/4-10*sxy,gy2+10*sxy,50*sxy,25*sxy,3*sxy);
            memDC.DrawLabel(_("前"),wxRect(gx2+gw2*2/3+10*sxy,gy2+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            /*if(cli->alw[5]==0)
            {
                memDC.SetBrush(wxBrush(wxColor(75,255,0)));
            }
            else
            {
                memDC.SetBrush(wxBrush(wxColor(255,247,0)));
            }*/
            //memDC.DrawRoundedRectangle(gx2+gw2/2-25*sxy,gy2+10*sxy,50*sxy,25*sxy,3*sxy);
            memDC.DrawLabel(_("中"),wxRect(gx2+gw2/3+10*sxy,gy2+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            /*if(cli->alw[2]==0)
            {
                memDC.SetBrush(wxBrush(wxColor(75,255,0)));
            }
            else
            {
                memDC.SetBrush(wxBrush(wxColor(255,247,0)));
            }*/
            //memDC.DrawRoundedRectangle(gx2+gw2/4-40*sxy,gy2+10*sxy,50*sxy,25*sxy,3*sxy);
            memDC.DrawLabel(_("后"),wxRect(gx2+10*sxy,gy2+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("水平偏航(mm/m)"),wxRect(gx2+10*sxy,gy2+gh2-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            /*if(cli->alw[1]==0)
            {
                memDC.SetBrush(wxBrush(wxColor(75,255,0)));
            }
            else
            {
                memDC.SetBrush(wxBrush(wxColor(255,247,0)));
            }*/
            //memDC.DrawRoundedRectangle(gx3+gw3*3/4-10*sxy,gy3+10*sxy,50*sxy,25*sxy,3*sxy);
            memDC.DrawLabel(_("前"),wxRect(gx3+gw3*2/3+10*sxy,gy3+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            /*if(cli->alw[5]==0)
            {
                memDC.SetBrush(wxBrush(wxColor(75,255,0)));
            }
            else
            {
                memDC.SetBrush(wxBrush(wxColor(255,247,0)));
            }*/
            //memDC.DrawRoundedRectangle(gx3+gw3/2-25*sxy,gy3+10*sxy,50*sxy,25*sxy,3*sxy);
            memDC.DrawLabel(_("中"),wxRect(gx3+gw3/3+10*sxy,gy3+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            /*if(cli->alw[3]==0)
            {
                memDC.SetBrush(wxBrush(wxColor(75,255,0)));
            }
            else
            {
                memDC.SetBrush(wxBrush(wxColor(255,247,0)));
            }*/
            //memDC.DrawRoundedRectangle(gx3+gw3/4-40*sxy,gy3+10*sxy,50*sxy,25*sxy,3*sxy);
            memDC.DrawLabel(_("后"),wxRect(gx3+10*sxy,gy3+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("垂直偏航(mm/m)"),wxRect(gx3+10*sxy,gy3+gh3-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        ///项目信息图

        int gx4 = gx7;
        int gy4 = gy7+gh7;
        int gw4 = gw7;
        int gh4 = gh7;

        memDC.SetPen(wxPen(wxColor(112,112,112)));
        memDC.SetBrush(wxBrush(wxColor(248,248,248)));
        memDC.DrawRectangle(gx4,gy4,gw4,gh4);
        memDC.DrawLabel(_("切口里程"),wxRect(gx4,gy4,gw4,30*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("盾尾里程"),wxRect(gx4,gy4+50*sxy,gw4,30*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetFont(eng1);
        memDC.DrawLabel(wxString::Format(_("%.2f"),headc),wxRect(gx4,gy4+25*sxy,gw4,25*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%.2f"),tailc),wxRect(gx4,gy4+75*sxy,gw4,25*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        if(cli->m1.t1>0)
        {
            valstr = wxDateTime(cli->m1.t1).Format(_("%Y-%m-%d %H:%M:%S"));
        }
        else
        {
            valstr = _("系统未开始测量!");
        }
        memDC.DrawLabel(valstr,wxRect(gx2,gy4+gh4+30*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        double pds=0.0;
        memDC.SetFont(chs);
        if(cli->m1.t1>0)
        {
            if(cli->prj.a2z==0)
            {
                pds = (cli->m1.headc-cli->prj.mile1)/fabs(cli->prj.mile2-cli->prj.mile1);
            }
            else
            {
                pds = (cli->prj.mile1-cli->m1.headc)/fabs(cli->prj.mile2-cli->prj.mile1);
            }
        }

        double advance = fabs(cli->m1.headc-cli->snum.tm);
        if(advance>cli->segset.L*2.0) advance=0.0;
        memDC.SetFont(eng1);
        valstr=wxString::Format(_("%d"),(int)(advance*1000));
        advance = advance/cli->segset.L;
        if(advance>1.0) advance=1;
        memDC.SetPen(wxPen(wxColor(234,251,230)));
        memDC.SetBrush(wxBrush(wxColor(234,251,230)));
        ex2=ex2+1;
        ey2=ey2+1;
        ew2=ew2-2;
        eh2=eh2-2;
        memDC.DrawRectangle(ex2,ey2,ew2*advance,eh2);
        memDC.DrawLabel(valstr,wxRect(ex2,ey2,ew2,eh2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetFont(eng2);
        memDC.SetTextForeground(wxColor(25,35,45));
        memDC.DrawLabel(wxString::Format(_("%d"),cli->m1.iseg)+_(" 环"),wxRect(ex1,ey1,ew1,eh1),wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(58,255,58)));

        memDC.SetFont(eng2);
        pitchrect.x = gx7+sxy;
        pitchrect.y = gy7+33*sxy;
        pitchrect.width = gw7;
        pitchrect.height = gh7-33*sxy;
        if(cli->sets.unit==0)
        {
            memDC.DrawLabel(wxString::Format(_("%.1f"),tan(cli->m.pitch)*1000.0),pitchrect,wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(wxString::Format(_("%.2f"),cli->m.pitch*180.0/PI),pitchrect,wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        rollrect.x = gx6+sxy;
        rollrect.y = gy6+33*sxy;
        rollrect.width= gw6;
        rollrect.height= gh6-33*sxy;
        mtcrect.height = rollrect.y+rollrect.height-mtcrect.y;
        if(cli->sets.unit==0)
        {
            memDC.DrawLabel(wxString::Format(_("%.1f"),tan(cli->m.roll)*1000.0),rollrect,wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(wxString::Format(_("%.2f"),cli->m.roll*180.0/PI),rollrect,wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        memDC.SetTextForeground(wxColor(0,0,0));

        if(cli->tbm.type>0)
        {
            if(cli->alw[0]==0)
            {
                memDC.SetTextForeground(wxColor(0,0,0));
            }
            else
            {
                memDC.SetTextForeground(wxColor(255,0,0));
            }
            memDC.DrawLabel(wxString::Format(_("%d"),headh),wxRect(gx2+gw2*2/3+40*sxy,gy2+10*sxy,50*sxy,25*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            if(cli->alw[4]==0)
            {
                memDC.SetTextForeground(wxColor(0,0,0));
            }
            else
            {
                memDC.SetTextForeground(wxColor(255,0,0));
            }
            memDC.DrawLabel(wxString::Format(_("%d"),midh),wxRect(gx2+gw2/3+40*sxy,gy2+10*sxy,50*sxy,25*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            if(cli->alw[2]==0)
            {
                memDC.SetTextForeground(wxColor(0,0,0));
            }
            else
            {
                memDC.SetTextForeground(wxColor(255,0,0));
            }
            memDC.DrawLabel(wxString::Format(_("%d"),tailh),wxRect(gx2+40*sxy,gy2+10*sxy,50*sxy,25*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            if(cli->alw[1]==0)
            {
                memDC.SetTextForeground(wxColor(0,0,0));
            }
            else
            {
                memDC.SetTextForeground(wxColor(255,0,0));
            }
            memDC.DrawLabel(wxString::Format(_("%d"),headv),wxRect(gx3+gw3*2/3+40*sxy,gy3+10*sxy,50*sxy,25*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            if(cli->alw[5]==0)
            {
                memDC.SetTextForeground(wxColor(0,0,0));
            }
            else
            {
                memDC.SetTextForeground(wxColor(216,12,24));
            }
            memDC.DrawLabel(wxString::Format(_("%d"),midv),wxRect(gx3+gw3/3+40*sxy,gy3+10*sxy,50*sxy,25*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            if(cli->alw[3]==0)
            {
                memDC.SetTextForeground(wxColor(0,0,0));
            }
            else
            {
                memDC.SetTextForeground(wxColor(216,12,24));
            }
            memDC.DrawLabel(wxString::Format(_("%d"),tailv),wxRect(gx3+40*sxy,gy3+10*sxy,50*sxy,25*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(cli->alw[0]==0)
            {
                memDC.SetTextForeground(wxColor(0,0,0));
            }
            else
            {
                memDC.SetTextForeground(wxColor(255,0,0));
            }
            memDC.DrawLabel(wxString::Format(_("%d"),headh),wxRect(gx2+gw2*1/2+65*sxy,gy2+10*sxy,50*sxy,25*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

            if(cli->alw[2]==0)
            {
                memDC.SetTextForeground(wxColor(0,0,0));
            }
            else
            {
                memDC.SetTextForeground(wxColor(255,0,0));
            }
            memDC.DrawLabel(wxString::Format(_("%d"),tailh),wxRect(gx2+65*sxy,gy2+10*sxy,50*sxy,25*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            if(cli->alw[1]==0)
            {
                memDC.SetTextForeground(wxColor(0,0,0));
            }
            else
            {
                memDC.SetTextForeground(wxColor(255,0,0));
            }
            memDC.DrawLabel(wxString::Format(_("%d"),headv),wxRect(gx3+gw3*1/2+65*sxy,gy3+10*sxy,50*sxy,25*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

            if(cli->alw[3]==0)
            {
                memDC.SetTextForeground(wxColor(0,0,0));
            }
            else
            {
                memDC.SetTextForeground(wxColor(255,0,0));
            }
            memDC.DrawLabel(wxString::Format(_("%d"),tailv),wxRect(gx3+65*sxy,gy3+10*sxy,50*sxy,25*sxy),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }

        if(t_len==0.0)
        {
            memDC.SetTextForeground(wxColor(71,71,71));
            if(cli->tbm.type>0)
            {
                memDC.DrawLabel(wxString::Format(_("%.1f"),0.0),wxRect(gx2+gw2*2/3+40*sxy,gy2+gh2-15*sxy,50*sxy,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%.1f"),0.0),wxRect(gx3+gw3*2/3+40*sxy,gy3+gh3-15*sxy,50*sxy,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(wxString::Format(_("%.1f"),0.0),wxRect(gx2+gw2*1/2+65*sxy,gy2+gh2-15*sxy,50*sxy,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%.1f"),0.0),wxRect(gx3+gw3*1/2+65*sxy,gy3+gh3-15*sxy,50*sxy,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(cli->tbm.type==0)
            {
                if(cli->alw[8]==0)
                {
                    memDC.SetTextForeground(wxColor(65,75,85));
                }
                else
                {
                    memDC.SetTextForeground(wxColor(216,12,24));
                }
                memDC.DrawLabel(wxString::Format(_("%.1f"),(headh-tailh)/t_len),wxRect(gx2+gw2*1/2+65*sxy,gy2+gh2-15*sxy,50*sxy,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                if(cli->alw[7]==0)
                {
                    memDC.SetTextForeground(wxColor(65,75,85));
                }
                else
                {
                    memDC.SetTextForeground(wxColor(216,12,24));
                }
                memDC.DrawLabel(wxString::Format(_("%.1f"),(headv-tailv)/t_len),wxRect(gx3+gw3*1/2+65*sxy,gy3+gh3-15*sxy,50*sxy,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            }
            else if(cli->tbm.type==1)
            {
                if(cli->alw[8]==0)
                {
                    memDC.SetTextForeground(wxColor(65,75,85));
                }
                else
                {
                    memDC.SetTextForeground(wxColor(216,12,24));
                }
                memDC.DrawLabel(wxString::Format(_("%.1f"),(headh-midh)/t_len),wxRect(gx2+gw2*2/3+40*sxy,gy2+gh2-15*sxy,50*sxy,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                if(cli->alw[7]==0)
                {
                    memDC.SetTextForeground(wxColor(65,75,85));
                }
                else
                {
                    memDC.SetTextForeground(wxColor(216,12,24));
                }
                memDC.DrawLabel(wxString::Format(_("%.1f"),(headv-midv)/t_len),wxRect(gx3+gw3*2/3+40*sxy,gy3+gh3-15*sxy,50*sxy,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            }
            else if(cli->tbm.type==2)
            {
                if(cli->alw[8]==0)
                {
                    memDC.SetTextForeground(wxColor(20,20,20));
                }
                else
                {
                    memDC.SetTextForeground(wxColor(216,12,24));
                }
                memDC.DrawLabel(wxString::Format(_("%.1f"),(midh-tailh)/t_len),wxRect(gx2+gw2*1/2+65*sxy,gy2+gh2-15*sxy,50*sxy,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                if(cli->alw[7]==0)
                {
                    memDC.SetTextForeground(wxColor(65,75,85));
                }
                else
                {
                    memDC.SetTextForeground(wxColor(216,12,24));
                }
                memDC.DrawLabel(wxString::Format(_("%.1f"),(midv-tailv)/t_len),wxRect(gx3+gw3*1/2+65*sxy,gy3+gh3-15*sxy,50*sxy,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            }
        }

        ///盾构三维图
        double sw = cli->segset.L;
        double mile =cli->m1.headc;
        double alf1,alf2,ph;
        double sr1,sr2;
        int h1 = 20*sxy;

        if(cli->m1.t1<=0)
        {
            if(a2z==1)
            {
                mile = cli->prj.mile1;
                road_l2xy(cl,mile,&x[0],&y[0],&alf1);
                road_l2h(cl,mile,&z[0],&alf2);
            }
            else
            {
                mile = cli->prj.mile2;
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
                road_l2h(&cli->r,mile,0,&slope);
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
                    ve=road_vertical_chain(cl,cli->m1.headc,0);
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
                        if(cli->prj.a2z==1)
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
                memDC.SetPen(wxPen(wxColor(127,178,225),1));
                memDC.SetBrush(wxBrush(wxColor(127,178,225)));
            }
            else if(i==4)
            {
                memDC.SetPen(wxPen(wxColor(96,156,210),1));
                memDC.SetBrush(wxBrush(wxColor(96,156,210)));
            }
            else if(i==5)
            {
                memDC.SetPen(wxPen(wxColor(74,144,204),1));
                memDC.SetBrush(wxBrush(wxColor(74,144,204)));
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
        memDC.DrawRectangle(gx1-2*cell,gy1-2*cell,4*cell,4*cell);
        memDC.SetPen(wxPen(wxColor(20,20,20)));
        memDC.DrawLine(gx1-cell,gy1-4,gx1-cell,gy1+4);
        memDC.DrawLine(gx1-2*cell,gy1-4,gx1-2*cell,gy1+4);
        memDC.DrawLine(gx1-3*cell,gy1-4,gx1-3*cell,gy1+4);
        memDC.DrawLine(gx1-4*cell,gy1-4,gx1-4*cell,gy1+4);
        memDC.DrawLine(gx1+cell,gy1-4,gx1+cell,gy1+4);
        memDC.DrawLine(gx1+2*cell,gy1-4,gx1+2*cell,gy1+4);
        memDC.DrawLine(gx1+3*cell,gy1-4,gx1+3*cell,gy1+4);
        memDC.DrawLine(gx1+4*cell,gy1-4,gx1+4*cell,gy1+4);
        memDC.DrawLine(gx1-4,gy1-cell,gx1+4,gy1-cell);
        memDC.DrawLine(gx1-4,gy1-2*cell,gx1+4,gy1-2*cell);
        memDC.DrawLine(gx1-4,gy1-3*cell,gx1+4,gy1-3*cell);
        memDC.DrawLine(gx1-4,gy1-4*cell,gx1+4,gy1-4*cell);
        memDC.DrawLine(gx1-4,gy1+cell,gx1+4,gy1+cell);
        memDC.DrawLine(gx1-4,gy1+2*cell,gx1+4,gy1+2*cell);
        memDC.DrawLine(gx1-4,gy1+3*cell,gx1+4,gy1+3*cell);
        memDC.DrawLine(gx1-4,gy1+4*cell,gx1+4,gy1+4*cell);

        int gx10=gx7;
        int gy10=gy5+gh5/2;
        memDC.SetFont(eng1);
        memDC.DrawLabel(wxString::Format(_("%d"),maxl*2),wxRect(gx1-4*cell,gy1+4,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(wxString::Format(_("%d"),maxl*2),wxRect(gx1+4*cell,gy1+4,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(wxString::Format(_("%d"),maxl*2),wxRect(gx1+4,gy1+4*cell,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),maxl*2),wxRect(gx1+4,gy1-4*cell,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        ///盾构机图形
        double x6;
        double y6;
        double x5;
        double y5;
        x6=gx1+tailh*s;
        y6=gy1-tailv*s;
        x5=gx1+headh*s;
        y5=gy1-headv*s;

        double cor[4][2];
        double cor1[4][2];
        double cosa[3],sina[3];
        double ms[3];
        double rx[4]={0};
        double ry[4]={0};
        double rz[4]={0};
        double azi = atan(yawh/1000.0);
        double ptich = atan(yawv/1000.0);

        ms[0] = 6.0;
        ms[1] = 6.0;
        ms[2] = 6.0;
        if(fabs(ptich)>0.00872664625997165 && fabs(ptich)<=0.0174532925199433)
        {
            ms[1] = ms[1]-1.0*(fabs(ptich)-0.00872664625997165)/0.00872664625997165;
        }
        else if(fabs(ptich)>0.0174532925199433 && fabs(ptich)<=0.0261799387799149)
        {
            ms[1] = ms[1]-1.0-0.5*(fabs(ptich)-0.0174532925199433)/0.00872664625997165;
        }
        else if(fabs(ptich)>0.0261799387799149 && fabs(ptich)<=0.0349065850398866)
        {
            ms[1] = ms[1]-1.0-0.5-0.5*(fabs(ptich)-0.0261799387799149)/0.00872664625997165;
        }
        else if(fabs(ptich)>0.0349065850398866 && fabs(ptich)<=0.0436332312998582)
        {
            ms[1] = ms[1]-1.0-0.5-0.5-0.5*(fabs(ptich)-0.0349065850398866)/0.00872664625997165;
        }
        else if(fabs(ptich)>0.0436332312998582 && fabs(ptich)<=0.0523598775598299)
        {
            ms[1] = ms[1]-1.0-0.5-0.5-0.5-0.5*(fabs(ptich)-0.0436332312998582)/0.00872664625997165;
        }
        else if(fabs(ptich) > 0.0523598775598299)
        {
            ms[1] = 3.0;
        }
        cosa[1] = cos(ptich*ms[1]);
        sina[1] = sin(ptich*ms[1]);

        if(fabs(cli->m.roll)>0.00872664625997165 && fabs(cli->m.roll)<=0.0174532925199433)
        {
            ms[0] = ms[0]-1.0*(fabs(cli->m.roll)-0.00872664625997165)/0.00872664625997165;
        }
        else if(fabs(cli->m.roll)>0.0174532925199433 && fabs(cli->m.roll)<=0.0261799387799149)
        {
            ms[0] = ms[0]-1.0-0.5*(fabs(cli->m.roll)-0.0174532925199433)/0.00872664625997165;
        }
        else if(fabs(cli->m.roll)>0.0261799387799149 && fabs(cli->m.roll)<=0.0349065850398866)
        {
            ms[0] = ms[0]-1.0-0.5-0.5*(fabs(cli->m.roll)-0.0261799387799149)/0.00872664625997165;
        }
        else if(fabs(cli->m.roll)>0.0349065850398866 && fabs(cli->m.roll)<=0.0436332312998582)
        {
            ms[0] = ms[0]-1.0-0.5-0.5-0.5*(fabs(cli->m.roll)-0.0349065850398866)/0.00872664625997165;
        }
        else if(fabs(cli->m.roll)>0.0436332312998582 && fabs(cli->m.roll)<=0.0523598775598299)
        {
            ms[0] = ms[0]-1.0-0.5-0.5-0.5-0.5*(fabs(cli->m.roll)-0.0436332312998582)/0.00872664625997165;
        }
        else if(fabs(cli->m.roll) > 0.0523598775598299)
        {
            ms[0] = 3.0;
        }
        cosa[0] = cos(cli->m.roll*ms[0]);
        sina[0] = sin(cli->m.roll*ms[0]);


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
        //wxMessageBox(wxString::Format(_("%.4f"),cosa[2]));
        rx[0] = 0.0;
        ry[0] = -1.5*cell;
        rz[0] = 0.0;
        rx[1] = 0.0;
        ry[1] = -ry[0];
        rz[1] = 0.0;
        rx[2] = -1.5*cell;
        ry[2] = 0.0;
        rz[2] = 0.0;
        rx[3] = -rx[2];
        ry[3] = 0.0;
        rz[3] = 0.0;
        ///转动角修正
        rx[0] = 1.5*cell*sina[0];
        ry[0] = -1.5*cell*cosa[0];
        rx[1] = -rx[0];
        ry[1] = -ry[0];
        rx[2] = -1.5*cell*cosa[0];
        ry[2] = -1.5*cell*sina[0];
        rx[3] = -rx[2];
        ry[3] = -ry[2];
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
        //cli->m1.roll=0.2;

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
        posBrush[0]=wxBrush(wxColor(254,254,0));
        posBrush[1]=wxBrush(wxColor(234,234,0));
        posBrush[2]=wxBrush(wxColor(214,214,0));
        posBrush[3]=wxBrush(wxColor(194,194,0));
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

        memDC.SetPen(wxPen(wxColor(115,57,28),3));
        memDC.DrawLine(rx[0]+x5,ry[0]+y5,rx[1]+x5,ry[1]+y5);
        memDC.DrawLine(rx[2]+x5,ry[2]+y5,rx[3]+x5,ry[3]+y5);

        memDC.SetPen(posPen);
        for(int i=0;i<4;i++)
        {
            int j=index[i];
            //if(i==1) continue;
            memDC.SetBrush(posBrush[j]);
            wxPoint tbm_pts[3];
            tbm_pts[0].x=cor[j][0];
            tbm_pts[0].y=cor[j][1];
            tbm_pts[1].x=x6;
            tbm_pts[1].y=y6;
            tbm_pts[2].x=x5;
            tbm_pts[2].y=y5;
            if(cli->sets.tbm3d==0) memDC.DrawPolygon(3,tbm_pts);
        }

        memDC.SetPen(wxPen(wxColor(0,1,219),3));
        memDC.DrawLine(rx[0]+x6,ry[0]+y6,rx[1]+x6,ry[1]+y6);
        memDC.DrawLine(rx[2]+x6,ry[2]+y6,rx[3]+x6,ry[3]+y6);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
    fclose(fp);
}

void mtg_tFrame::OnMetricClick(wxMouseEvent& event)
{
    wxPoint pt;
    pt = event.GetPosition();
    if(pt.x>idxrect.x && pt.x< idxrect.x+idxrect.width && pt.y> idxrect.y && pt.y < idxrect.y+idxrect.height)
    {
        PasswordDialog dlg(this);
        dlg.TextPassword->SetFocus();
        dlg.Center();

        if(dlg.ShowModal()==wxID_OK)
        {
            int i;
            for(i=0;i<cli->nuser;i++)
            {
                if(dlg.TextPassword->GetValue().Cmp(wxString((const char*)cli->user[i].password,wxConvLocal))==0)
                {
                    break;
                }
            }
            if(i<cli->nuser)
            {
                cli->onLine = i;
                ModifySegDialog dlg(this);
                dlg.Center();
                dlg.ShowModal();
                panelMetric->RefreshRect(wxRect(idxrect.x,idxrect.y,idxrect.width,idxrect.height+20),true);
            }
        }
    }
}

///项目信息
void mtg_tFrame::PaintBubble(wxMemoryDC* memDC, wxRect rect)
{
    int w,h;
    w = rect.width;
    h = rect.height;
    int x = rect.x;
    int y = rect.y;
    ///background
    int mina=(w<h)?w:h;
    int a=mina;
    int rad=mina*9/20;
    int cx=x+w/2;
    int cy=y+h/2;



    ///大圆
    memDC->SetPen(wxPen(wxColor(58,68,88)));
    memDC->SetBrush(wxBrush(wxColor(255,255,255)));
    memDC->DrawCircle(cx,cy,rad);
    ///小圆
    memDC->DrawCircle(cx,cy,rad*13/20);
    ///双轴
    memDC->DrawLine(cx-a/2+a/24,cy,cx+a/2-a/24,cy);
    memDC->DrawLine(cx,cy-a/2+a/24,cx,cy+a/2-a/24);
    static const  double r2s=206264.80624709635515647335733078;
    double dx,dy;
    dx=cli->m.comp[0]*r2s/10;
    dy=cli->m.comp[1]*r2s/10;
    ///如圆心超出大圆，则画在大圆上
    double dist=sqrt(dx*dx+dy*dy);
    if(dist>rad)
    {
        dx*=rad/dist;
        dy*=rad/dist;
    }
    memDC->SetBrush(*wxTRANSPARENT_BRUSH);
    memDC->SetPen(wxPen(wxColor(255,0,0)));
    memDC->DrawCircle(cx-dx,cy+dy,rad*3/10);
}

void mtg_tFrame::OnPaintLog(wxPaintEvent& event)
{
    wxPaintDC dc(panelLog);
    int w,h;
    GetSize(&w,&h);
    double sx=w/1024.0;
    double sy=h/768.0;
    if(sx>=sy)
    {
        sx=sy;
    }
    panelLog->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        ///background
        switch(btnLogState)
        {
        case 0:
        case 2:
        case 3:
            memDC.SetPen(wxPen(wxColor(237,240,245)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(0,0,w,h);
            break;

        case 1:
            memDC.SetPen(wxPen(wxColor(255,255,255)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.DrawRectangle(0,0,w,h);

            break;
        default:
            break;
        }

        wxFont chs(10*sx,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int infoType[3];
        wxString infoString=wxEmptyString;
        for(int i=0;i<3;i++)
        {
            if(tpLog[i]==0)
            {
                infoString=_("√  ")+strLog[i];
                memDC.SetTextForeground(wxColor(28,28,28));
            }
            else
            {
                infoString=_("×  ")+strLog[i];
                memDC.SetTextForeground(wxColor(255,0,0));
            }
            if(!strLog[i].IsEmpty()) memDC.DrawLabel(infoString,wxRect(20,(5+i*18)*sx,w-50,18*sx),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnEnterLog(wxMouseEvent& event)
{
    btnLogState=1;
    panelLog->Refresh();
}

void mtg_tFrame::OnLeaveLog(wxMouseEvent& event)
{
    btnLogState=2;
    panelLog->Refresh();
}

void mtg_tFrame::OnLeftDownLog(wxMouseEvent& event)
{
    btnLogState=3;
    panelLog->Refresh();
}

void mtg_tFrame::OnLogClick(wxMouseEvent& event)
{
    logDlg->Center();
    logDlg->Show();
    //logDlg=0;
    btnLogState=2;
    panelLog->Refresh();
}

void mtg_tFrame::OnPaintStatus(wxPaintEvent& event)
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
        if(tps_tip==0)
        {
            PaintBubble(&memDC, wxRect(0,0,w,h));
        }
        else
        {
            PaintBattery(&memDC, wxRect(0,0,w,h));
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

#include "trace.h"
///tiemr
void mtg_tFrame::OnTimer(wxTimerEvent& event)
{
    ///log
    static int tick=0;
    static char word[260]="\0";
    //char iword[4096]="\0";
    static int state=-1;
    static double headh=0.0;
    static double headv=0.0;
    static int segnum=0;
    static double roll=0.0;
    static double pitch=0.0;
    static double chain=0.0;
    static bool RoadState=true;
    static bool OriState=true;
    static int InvState=0;
    static int GState=-1;
    static int lightonoff=-1;
    static int j=0;

    if(peek==0)
    {
        peek=1;
        strcpy(word,"%R1Q,1\n");
        strcat(word,"%R1Q,4\n");
        strcat(word,"%R1Q,7\n");
        strcat(word,"%R1Q,10\n");
        strcat(word,"%R1Q,13\n");
        strcat(word,"%R1Q,16\n");
        strcat(word,"%R1Q,19\n");
        strcat(word,"%R1Q,22\n");
        strcat(word,"%R1Q,25\n");
        strcat(word,"%R1Q,28\n");
        strcat(word,"%R1Q,31\n");
        strcat(word,"%R1Q,34\n");
        strcat(word,"%R1Q,40\n");
        strcat(word,"%R1Q,43\n");
        strcat(word,"%R1Q,46\n");
        sock->Write(word,strlen(word));
    }

    if(cli->nlog<nlog)
    {
        nlog=0;
    }

    if(cli->nlog > nlog)
    {
        for(int i=nlog;i<cli->nlog;i++)
        {
            if(j<3)
            {
                tpLog[j]=cli->logs[i].type;
                strLog[j]=wxDateTime(cli->logs[i].t).Format(_("%Y-%m-%d %H:%M:%S"));
                strLog[j]=strLog[j]+_("   ")+wxString(cli->logs[i].msg,wxConvLocal);
                j++;
            }
            else
            {
                tpLog[0]=tpLog[1];
                tpLog[1]=tpLog[2];
                tpLog[1]=cli->logs[i].type;
                strLog[0]=strLog[1];
                strLog[1]=strLog[2];
                strLog[2]=wxDateTime(cli->logs[i].t).Format(_("%Y-%m-%d %H:%M:%S"));
                strLog[2]=strLog[2]+_("   ")+wxString(cli->logs[i].msg,wxConvLocal);

            }
            nlog++;
            panelLog->Refresh();
        }
    }

    tick++;
    if(tick % 10==0)
    {
        panelMetric->Refresh();
        panelBar->Refresh();
    }

    if(tick ==1200)
    {
        tick=0;
    }


    tickAnimation++;
    if(tickAnimation>10) tickAnimation=1;
    if(drawAnimation) panelGraph->Refresh(false);

    //fclose(fp);
}

