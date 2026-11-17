/***************************************************************
 * Name:      mtg_t_svrFrame.cpp
 * Purpose:   Code for Application Frame
 * Author:    dengdeyan (dengdeyan@medosurvey.com)
 * Created:   2011-03-21
 * Copyright: dengdeyan (http://www.medosurvey.com)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "mtg_t_svrMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(mtg_t_svrFrame)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include <wx/dcclient.h>
#include "DtaDlg.h"
#include "mtg_t_svrApp.h"
#include "LibPlc.h"
#include <wx/stdpaths.h>
#include "ConfigDlg.h"
#include "SegmentDlg.h"
#include "MyCheckDlg.h"
#include "JackDlg.h"
#include "MapViewDlg.h"
#include "MyQueryDlg.h"
#include "MySetupDlg.h"
#include "ConfirmDlg.h"
#include "ModifySegDialog.h"
#include "dmsrad.h"
#include <wx/imaglist.h>
#include "LogDialog.h"
#include <wx/dcbuffer.h>
#include "libele.h"
#include "PasswordDialog.h"
#include <wx/config.h>
#include "gtime.h"
#include "MydoctorDlg.h"
//#include "MyHistoryDlg.h"

#define PI  3.1415926535897932384626433832795

//(*IdInit(mtg_t_svrFrame)
const long mtg_t_svrFrame::ID_PANEL1 = wxNewId();
//*)

enum
{
    // id for sockets
    SERVER_ID = 100,
    SOCKET_ID
};

enum
{
    PU_RESTORE = 10001,
    PU_EXIT
};

BEGIN_EVENT_TABLE(mtg_t_svrFrame,wxFrame)
    //(*EventTable(mtg_t_svrFrame)
    //*)
    EVT_SOCKET(SERVER_ID,  mtg_t_svrFrame::OnServerEvent)
    EVT_SOCKET(SOCKET_ID,  mtg_t_svrFrame::OnSocketEvent)
    EVT_TIMER(-1,mtg_t_svrFrame::OnTimer)
    EVT_CLOSE(mtg_t_svrFrame::OnClose)
END_EVENT_TABLE()

static time_t tlog=0;
static time_t starttime=0;

mtg_t_svrFrame::mtg_t_svrFrame(wxWindow* parent,wxWindowID id)
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
    bmpPartner.LoadFile(path+_("/plugins/partner.png"),wxBITMAP_TYPE_PNG);

    path1=path;
    int t1=path1.Find('\\',false);
    path1=path1.SubString(0,t1-1);
    path1=path1+_("\\image\\");
    //wxMessageBox(path1);

    if(!wxFileExists(path1))
    {
        wxMkDir(path1);
    }

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
    else if(iver==2) bmpLogo.LoadFile(path+_("/plugins/Partner2.jpg"),wxBITMAP_TYPE_JPEG);
    else bmpLogo.LoadFile(path+_("/plugins/logo.png"),wxBITMAP_TYPE_PNG);

    int w,h;
    //imgTrace.Create(1280,960);
    //(*Initialize(mtg_t_svrFrame)
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
    panelTool = new wxPanel(panelMetric, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelHistory = new wxPanel(panelUI, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPointer = new wxPanel(panelUI, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));

    listlog = new wxListView(panelUI, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    metroFig1->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    metroFig2->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    metroFig3->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMode->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelLogo->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelGraph->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelStatus->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMetric->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBar->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTool->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelHistory->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPointer->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMode->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_svrFrame::OnPaintMode,0,this);
    panelLogo->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_svrFrame::OnPaintLogo,0,this);
    panelGraph->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_svrFrame::OnPaintGraph,0,this);
    panelStatus->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_svrFrame::OnPaintStatus,0,this);

    panelMetric->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_svrFrame::OnPaintMetric,0,this);
    metroFig1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_svrFrame::OnPaintMetroFig1,0,this);
    metroFig2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_svrFrame::OnPaintMetroFig2,0,this);
    metroFig2->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_svrFrame::ViewJack,0,this);
    metroFig3->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_svrFrame::OnPaintMetroFig3,0,this);
    metroFig3->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_t_svrFrame::OnMotionSegment,0,this);
    metroFig3->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_t_svrFrame::OnLeaveSegment,0,this);
    metroFig3->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_svrFrame::SetSegment,0,this);
    panelBar->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_svrFrame::OnPaintBar,0,this);

    panelButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_svrFrame::OnPaintButton,0,this);
    panelButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_t_svrFrame::OnMotionButton,0,this);
    panelButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_t_svrFrame::OnLeaveButton,0,this);
    panelButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_svrFrame::OnClickButton,0,this);

    panelTool->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_t_svrFrame::OnPaintTool,0,this);
    panelTool->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_t_svrFrame::OnMotionTool,0,this);
    panelTool->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_t_svrFrame::OnLeaveTool,0,this);
    panelTool->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_svrFrame::OnClickTool,0,this);

    listlog->Connect(wxEVT_COMMAND_LEFT_DCLICK,(wxObjectEventFunction)&mtg_t_svrFrame::OnLogDoubleClicked,0,this);

    //panelButtonList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_svrFrame::OnBtnClick,0,this);
    this->Connect(wxEVT_SIZE,(wxObjectEventFunction)&mtg_t_svrFrame::OnSize,0,this);
    //*)
    //Center();
    mtg_connect(mtg);

    if(mtg->iset.vibration==1&&!mtg->ajthread)
    {
        mtg_start_aj(mtg);
    }
    //trace(0,"test:%s\n",mtg->comset[3].ip);
    listlog->InsertColumn(0,_("类型"),wxLIST_FORMAT_LEFT,45);
    listlog->InsertColumn(1,_("时间"),wxLIST_FORMAT_LEFT,150);
    listlog->InsertColumn(2,_("信息"),wxLIST_FORMAT_LEFT,150);
    //listlog->SetBackgroundColour(wxColor(237,237,237));
    //wxMessageBox(wxString::Format(_("%.4f"),mtg->m1.faj[0]));
    wxImageList* imglist=new wxImageList(16,16);
    imglist->Add(wxIcon(path+_("/plugins/Info.ico"),wxBITMAP_TYPE_ICO));
    imglist->Add(wxBitmap(path+_("/plugins/Error.png"),wxBITMAP_TYPE_PNG));
    listlog->SetImageList(imglist,wxIMAGE_LIST_SMALL);

    Connect(wxEVT_TIMER,(wxObjectEventFunction)&mtg_t_svrFrame::OnTimer);

    int i=0;
    btn_label[i++]=_("开始测量");
    btn_label[i++]=_("停止测量");
    /*btn_label[i++]=_("打开激光");
    btn_label[i++]=_("停止激光");*/
    btn_label[i++]=_("管片选型");
    btn_label[i++]=_("向前移站");
    btn_label[i++]=_("系统检查");
    btn_label[i++]=_("数据查询");
    btn_label[i++]=_("隧道中线");
    btn_label[i++]=_("地质地物");
    //btn_label[i++]=_("管环监测");
    //btn_label[i++]=_("盾尾间隙");
    btn_label[i++]=_("参数设置");
    //btn_label[i++]=_("打开激光");
    //btn_label[i++]=_("关闭激光");
    //btn_label[i++]=_("导出照片");
    btn_label[i++]=_("退出系统");
    clicked=-1;
    for(i=0; i<ncli; i++)
    {
        //strcpy(m_clients[i].uid,mtg->usr[i].name);
        m_clients[i].sock=0;
    }

    wxIPV4address addr;
    addr.Service(3000); ///端口号

    /// Create the socket
    m_server = new wxSocketServer(addr);
    /// Setup the event handler and subscribe to connection events
    m_server->SetEventHandler(*this, SERVER_ID);
    m_server->SetNotify(wxSOCKET_CONNECTION_FLAG);
    m_server->Notify(true);

    nr[0]=nr[1]=nr[2]=nr[3]=nr[4]=0;

    memset(m_clients,0,MAX_CLI*sizeof(mtg_usr));
    ncli=0;
    admin=0;
    map_ready=0;
    ///开始时间刷新
    timerStat.SetOwner(this);
    timerStat.Start(100,false);

    ///关键区域提示
    Err=0;
    GetTips();

    tpsDirection=2;
    drawAnimation=false;
    tpsStatus=0;       //0电子补偿器1电池电量

    //ipubble=0;
    //wxMessageBox(wxString::Format(_("%d,%d"),mtg->m1.iseg,mtg->snum.iseg));
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
    //存储照片
    //20180208whq增加下面的判断，否则可能会导致死机
    if(mtg->camsvr.cams[0].width==0||mtg->camsvr.cams[0].height==0)
    {
        mtg->camsvr.cams[0].width=1628;
        mtg->camsvr.cams[0].height=1236;
    }
    image.Create(mtg->camsvr.cams[0].width,mtg->camsvr.cams[0].height);
    bufsize=mtg->camsvr.cams[0].width*mtg->camsvr.cams[0].height*3;
    logDlg=new LogDialog(this);
    ///20190315 whq add
    if(mtg->tarset.stopped)
    {
        mtg->ierr[10]=1;
    }

    time_tip=0;
    ReadPlcStartVal=0;

    ///20200925ws add
    time(&starttime);
    starttime=starttime+86400;    //第二天的同一时间
    tlog=starttime+8*3600-(starttime+8*3600)%(24*3600);    //第二天的8点

    ///下面是在主倾斜仪坏掉情况下需要更换倾斜仪测试使用
//    mtg->m=mtg->m0;
//    mtg_laser_incline(mtg);
//    mtg->m0=mtg->m;
//    if(mtg_store_origin(mtg))
//    {
//        wxMessageBox(_("零位保存成功!"));
//        ///mtg_log(mtg,MTG_LOG_FINISH_STORE_ORIGIN);
//    }
//    else
//    {
//        ///mtg_log(mtg,MTG_LOG_FAIL_STORE_ORIGIN);
//    }
//    mtg->m=mtg->m1;
////    mtg_tbm_incline(mtg);
//    mtg_laser_incline(mtg);
//    mtg_laser_gesture(mtg);
//    if(mtg_store_meas(mtg))
//    {
//        mtg_log(mtg,MTG_LOG_FINISH_STORE_MEASURE);
//        //mtg_store_alw(mtg);
//    }
//    else
//    {
//        mtg_log(mtg,MTG_LOG_FAIL_STORE_MEASURE);
//    }
}

void mtg_t_svrFrame::GetError()
{
    if(mtg->ierr[0]==1)
    {
        Err=ID_ERR_NO_CAMSET;
        return;
    }
    else if(mtg->ierr[1]==1)
    {
        Err=ID_ERR_NO_TAR;
        return;
    }
    else if(mtg->ierr[2]==1)
    {
        Err=ID_ERR_NO_STN;
        return;
    }
    else if(mtg->ierr[3]==1)
    {
        Err=ID_ERR_NO_ORI;
        return;
    }
    else if(mtg->ierr[4]==1)
    {
        Err=ID_ERR_NO_HE;
        return;
    }
    else if(mtg->ierr[5]==1)
    {
        Err=ID_ERR_NO_VE;
        return;
    }
    else if(mtg->ierr[6]==1)
    {
        Err=ID_ERR_NO_TPS;
        return;
    }
    else if(mtg->ierr[7]==1)
    {
        Err=ID_ERR_NO_PSM;
        return;
    }
    else if(mtg->ierr[8]==1)
    {
        Err=ID_ERR_NO_INC;
        return;
    }
    else if(mtg->ierr[9]==1)
    {
        Err=ID_ERR_STN;
        return;
    }
    else if(mtg->ierr[10]==1)
    {
        Err=ID_ERR_INC_OUT;
    }
    Err=0;
}

void mtg_t_svrFrame::GetTips()
{
    double len1,len2;
    nks=0;

    for(int i=0;i<mtg->nks;i++)
    {
        len1=mtg->m1.headc-mtg->keys[i].mile1;
        len2=mtg->m1.headc-mtg->keys[i].mile2;

        if(fabs(len1)<=mtg->prj.tip || fabs(len2)<=mtg->prj.tip)
        {
            keys[nks]=mtg->keys[i];
            nks++;
        }
        if(nks>=200) break;
    }
    tip=nks;
}

mtg_t_svrFrame::~mtg_t_svrFrame()
{
    //(*Destroy(mtg_t_svrFrame)
    //*)
    //if(mapDlg) mapDlg->Destroy();
    //mapDlg=0;
    image.Destroy();
    //if(ms) free(ms);
    //timerStat.Stop();
    //panelButtonList->Disconnect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_t_svrFrame::OnBtnClick,0,this);
    if(logDlg)
        logDlg->Destroy();
}

void mtg_t_svrFrame::OnServerEvent(wxSocketEvent& event)
{
    wxSocketBase *sock;
    // Accept new connection if there is one in the pending
    // connections queue, else exit. We use Accept(false) for
    // non-blocking accept (although if we got here, there
    // should ALWAYS be a pending connection).
    sock = m_server->Accept(false);

    if (!sock)
    {
        return;
    }

    sock->SetEventHandler(*this, SOCKET_ID);
    sock->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
    sock->Notify(true);
}

void mtg_t_svrFrame::RadioMsg(const char* msg)
{
    //trace(0,"RadioMsg:msg=%s,ncli=%d\n",msg,ncli);
    for(int i=0; i<ncli; i++)
    {
        if(!m_clients[i].sock) continue;
        m_clients[i].sock->Write(msg,strlen(msg));
    }
}

void mtg_t_svrFrame::RadioData(int type)
{
    char msg[4096];
    int i;
    switch(type)
    {
        case 15:   ///广播测量数据
        {
            sprintf(msg,"%%R1D,52:0:%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%d,%ld,%ld,%ld,%d\n",
             mtg->m.inc[0],mtg->m.inc[1],mtg->m.inc[2],mtg->m.inc[3],mtg->m.cam[0],mtg->m.cam[1],mtg->m.cam[2],mtg->m.cam[3],mtg->m.prism[0],mtg->m.prism[1],mtg->m.prism[2],
             mtg->m.angle[0],mtg->m.angle[1],mtg->m.comp[0],mtg->m.comp[1],mtg->m.head[0],mtg->m.head[1],mtg->m.head[2],mtg->m.hdes[0],mtg->m.hdes[1],mtg->m.hdes[2],
             mtg->m.headc,mtg->m.headh,mtg->m.headv,mtg->m.tail[0],mtg->m.tail[1],mtg->m.tail[2],mtg->m.tdes[0],mtg->m.tdes[1],mtg->m.tdes[2],
             mtg->m.tailc,mtg->m.tailh,mtg->m.tailv,mtg->m.mile1,mtg->m.hdev1,mtg->m.vdev1,mtg->m.mile2,mtg->m.hdev2,mtg->m.vdev2,mtg->m.mile3,mtg->m.hdev3,mtg->m.vdev3,
             mtg->m.faj[0],mtg->m.faj[1],mtg->m.faj[2],mtg->m.faj[3],mtg->m.baj[0],mtg->m.baj[1],mtg->m.baj[2],mtg->m.baj[3],mtg->m.aj[0],mtg->m.aj[1],mtg->m.aj[2],mtg->m.aj[3],
             mtg->m.inc1[0],mtg->m.inc1[1],mtg->m.inc1[2],mtg->m1.iseg,(long)mtg->m.t1,(long)mtg->m.t2,(long)mtg->m.t3,mtg->m.iset
            );
            RadioMsg(msg);
            break;
        }
        case 0:
        {
            sprintf(msg,"%%R1D,3:'%s',%lf,%lf,%d,%d,%d,%d,%lf\n",
                 mtg->prj.name,mtg->prj.mile1,mtg->prj.mile2,mtg->prj.a2z,mtg->ndty,
                 mtg->prj.htip,mtg->prj.vtip,mtg->prj.tip);
            sprintf(msg,"%%R1D,3:0:'%s',%.12f,%.12f,%d,%d,'%s','%s','%s','%s',%d,%d,%.12f\n",
                mtg->prj.name,mtg->prj.mile1,mtg->prj.mile2,mtg->prj.a2z,mtg->ndty,mtg->duty[0].name,mtg->duty[1].name,
                mtg->duty[2].name,mtg->duty[3].name,mtg->prj.htip,mtg->prj.vtip,mtg->prj.tip);
            RadioMsg(msg);
            break;
        }
        case 1:
        {
            sprintf(msg,"%%R1D,15:0:%d\n",mtg->nks);
            RadioMsg(msg);
            //sock->Write(msg,strlen(msg));
            for(i=0; i<mtg->nks; i++)
            {
                sprintf(msg,"%%R1D,15:1:%d,'%s',%lf,%lf\n",i,mtg->keys[i].name,mtg->keys[i].mile1,mtg->keys[i].mile2);
                RadioMsg(msg);
                //sock->Write(msg,strlen(msg));
            }
            break;
        }
        case 2:
        {
            sprintf(msg,"%%R1D,18:0:'%s',%d,%d,\
                %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,\
                %d,%.12f,%.12f,%.12f,%.12f,%d,\
                %d,%.12f,%.12f,%.12f,%.12f,%d\n",
                mtg->tbm.name,mtg->tbm.type,mtg->tbm.mode,
                mtg->tbm.D[0],mtg->tbm.D[1],mtg->tbm.D[2],mtg->tbm.D[3],mtg->tbm.D[4],mtg->tbm.D[5],mtg->tbm.L[0],mtg->tbm.L[1],mtg->tbm.L[2],mtg->tbm.L[3],mtg->tbm.L[4],mtg->tbm.L[5],
                mtg->tbm.L[6],mtg->tbm.L[7],mtg->tbm.L[8],mtg->tbm.naj,mtg->tbm.aj[0],mtg->tbm.aj[1],mtg->tbm.aj[2],mtg->tbm.aj[3],mtg->tbm.aj[4],mtg->tbm.aj[5],mtg->tbm.aunit,
                mtg->tbm.nbj,mtg->tbm.bj[0],mtg->tbm.bj[1],mtg->tbm.bj[2],mtg->tbm.bj[3],mtg->tbm.bunit,
                mtg->tbm.nfj,mtg->tbm.fj[0],mtg->tbm.fj[1],mtg->tbm.fj[2],mtg->tbm.fj[3],mtg->tbm.funit
            );
            RadioMsg(msg);
            break;
        }
        case 3:
        {
            sprintf(msg,"%%R1D,21:0:%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%d,%d,%d,%d\n",
                mtg->tarset.ver,mtg->tarset.prism[0],mtg->tarset.prism[1],mtg->tarset.prism[2],mtg->tarset.prism[3],mtg->tarset.prism[4],mtg->tarset.prism[5],
                mtg->tarset.prism[6],mtg->tarset.prism[7],mtg->tarset.prism[8],mtg->tarset.prc,mtg->tarset.length,mtg->tarset.cam,mtg->tarset.inc,mtg->tarset.ipos,mtg->tarset.pos
             );
            RadioMsg(msg);
            break;
        }
        case 4:
        {
            sprintf(msg,"%%R1D,27:0:%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%d\n",
                mtg->tps.type,mtg->tps.lasertype,mtg->tps.laserheight,mtg->tps.laserdist[0],mtg->tps.laserdist[1],
                mtg->tps.laserx[0],mtg->tps.lasery[0],mtg->tps.laserx[1],mtg->tps.lasery[1],mtg->tps.edm,mtg->tps.comp);

            RadioMsg(msg);
            break;
        }
        case 5:
        {
            sprintf(msg,"%%R1D,30:0:%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%d,%.12f,%.12f,%d\n",
                mtg->segset.type,mtg->segset.in,mtg->segset.f2b,mtg->segset.l2s,
                mtg->segset.L,mtg->segset.De,mtg->segset.D,mtg->segset.Ks,mtg->segset.G0,mtg->segset.G1,mtg->segset.s2s
            );
            RadioMsg(msg);
            break;
        }
        case 6:
        {
            sprintf(msg,"%%R1D,33:0:%d\n",mtg->nblk);
            RadioMsg(msg);
            for(i=0;i<mtg->nblk;i++)
            {
                sprintf(msg,"%%R1D,33:1:%d,'%s',%lf\n",i,mtg->blocks[i].name,mtg->blocks[i].angle);
                RadioMsg(msg);
            }
            break;
        }
        case 7:
        {
            sprintf(msg,"%%R1D,9:0:%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                %lf,%lf,%lf,%lf,%lf,%d,%ld,%ld,%ld,%d,%lf,%lf,%lf,%lf,%lf,%lf\n",
             mtg->m0.inc[0],mtg->m0.inc[1],mtg->m0.inc[2],mtg->m0.inc[3],
             mtg->m0.cam[0],mtg->m0.cam[1],mtg->m0.cam[2],mtg->m0.cam[3],
             mtg->m0.prism[0],mtg->m0.prism[1],mtg->m0.prism[2],
             mtg->m0.angle[0],mtg->m0.angle[1],
             mtg->m0.comp[0],mtg->m0.comp[1],
             mtg->m0.head[0],mtg->m0.head[1],mtg->m0.head[2],
             mtg->m0.hdes[0],mtg->m0.hdes[1],mtg->m0.hdes[2],
             mtg->m0.headc,mtg->m0.headh,mtg->m0.headv,
             mtg->m0.tail[0],mtg->m0.tail[1],mtg->m0.tail[2],
             mtg->m0.tdes[0],mtg->m0.tdes[1],mtg->m0.tdes[2],
             mtg->m0.tailc,mtg->m0.tailh,mtg->m0.tailv,
             mtg->m0.faj[0],mtg->m0.faj[1],mtg->m0.faj[2],mtg->m0.faj[3],
             mtg->m0.baj[0],mtg->m0.baj[1],mtg->m0.baj[2],mtg->m0.baj[3],
             mtg->m0.aj[0],mtg->m0.aj[1],mtg->m0.aj[2],mtg->m0.aj[3],
             mtg->m0.inc1[0],mtg->m0.inc1[1],mtg->m0.inc1[2],
             mtg->m0.iseg,(long)mtg->m0.t1,(long)mtg->m0.t2,(long)mtg->m0.t3,mtg->m0.iset,
             mtg->mp.prism[0],mtg->mp.prism[1],mtg->mp.prism[2],mtg->mp.prism[3],mtg->mp.prism[4],mtg->mp.prism[5]
             );

            RadioMsg(msg);
            break;
        }
        case 8:
        {
            sprintf(msg,"%%R1D,12:0:%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\
                %d,%d,%lf,%lf,%d\n",
                mtg->iset.cyc,mtg->iset.bcyc,mtg->iset.palw,mtg->iset.jalw,mtg->iset.balw,mtg->iset.talw,
                mtg->iset.vibration,mtg->iset.rstn,mtg->iset.tsyn,mtg->iset.rget,mtg->iset.idrv,mtg->iset.prun,mtg->iset.pend,
                mtg->iset.psas,mtg->iset.pchk,mtg->iset.pqry,mtg->iset.pmap,mtg->iset.psmr,mtg->iset.pquit,mtg->iset.unit,
                mtg->iset.vmileage,mtg->iset.head,mtg->iset.tbm3d,mtg->iset.trend,mtg->iset.povr,mtg->iset.jovr,mtg->iset.tovr,
                mtg->iset.bovr,mtg->iset.toEr,mtg->iset.flen,mtg->iset.fdev,mtg->iset.lang);
            RadioMsg(msg);
            break;
        }
        case 9:
        {
            sprintf(msg,"%%R1D,36:0:%d,%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%ld,%.12f,%.12f\n",
            mtg->smonitor.number,mtg->smonitor.monitor,mtg->smonitor.cycle,mtg->smonitor.last,mtg->smonitor.iseg,mtg->smonitor.headc,mtg->smonitor.x0,mtg->smonitor.y0,mtg->smonitor.z0,
            mtg->smonitor.x,mtg->smonitor.y,mtg->smonitor.z,(long)mtg->smonitor.t,mtg->smonitor.dv,mtg->smonitor.dv1);

            RadioMsg(msg);
            break;
        }
        case 10:
        {
            sprintf(msg,"%%R1D,42:0:%d\n",mtg->nuser);
            RadioMsg(msg);
            for(i=0; i<mtg->nuser; i++)
            {
                sprintf(msg,"%%R1D,42:1:%d,'%s','%s',%d\n",i,mtg->user[i].name,mtg->user[i].password,mtg->user[i].level);
                RadioMsg(msg);
            }
            break;
        }
        case 11:
        {
            ///要素个数
            int nh,nv,nho,nvo,nmo;
            h_element *he;
            v_element *ve;
            h_offset  *ho;
            v_offset  *vo;
            m_offset  *mo;
            nh = road_number_horizon(&mtg->r);
            nv = road_number_vertical(&mtg->r);
            nho = road_number_horizon_off(&mtg->r);
            nvo = road_number_vertical_off(&mtg->r);
            nmo = road_number_mile_off(&mtg->r);
            sprintf(msg,"%%R1D,6:0:%d,%d,%d,%d,%d\n",nh,nv,nho,nvo,nmo);
            RadioMsg(msg);
            ///平曲线要素
            for(i=0; i<nh; i++)
            {
                he = road_horizon(&mtg->r,i);
                sprintf(msg,"%%R1D,6:1:%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d,%f\n",
                i,he->type,he->radius,he->rou1,he->rou2,he->x1,he->y1,he->x2,he->y2,he->angle1,he->angle2,he->l1,
                he->length,he->pz,he->deta);
                RadioMsg(msg);
            }
            ///竖曲线
            for(i=0; i<nv; i++)
            {
                ve = road_vertical(&mtg->r,i);
                sprintf(msg,"%%R1D,6:2:%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%d,%f\n",
                        i,ve->type,ve->radius,ve->l1,ve->h1,ve->l2,ve->h2,ve->angle1,ve->angle2,ve->length,ve->pz,ve->deta);
                RadioMsg(msg);
            }
            ///横偏
            for(i=0; i<nho; i++)
            {
                ho = road_horizon_off(&mtg->r,i);
                sprintf(msg,"%%R1D,6:3:%d,%f,%f\n",i,ho->mile,ho->off);
                RadioMsg(msg);
            }
            ///纵偏
            for(i=0; i<nvo; i++)
            {
                vo = road_vertical_off(&mtg->r,i);
                sprintf(msg,"%%R1D,6:4:%d,%f,%f\n",i,vo->mile,vo->off);
                RadioMsg(msg);
            }
            ///短链
            for(i=0; i<nmo; i++)
            {
                mo = road_mile_off(&mtg->r,i);
                sprintf(msg,"%%R1D,6:5:%d,%f,%f\n",i,mo->mile,mo->off);
                RadioMsg(msg);
            }
            break;
        }
        case 12:
        {
            sprintf(msg,"%%R1D,48:0:%d,'%s','%s',%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%ld\n",
             mtg->istn.id+1,mtg->istn.stat,mtg->istn.back,
             mtg->istn.statx,mtg->istn.staty,mtg->istn.statz,mtg->istn.stath,
             mtg->istn.backx,mtg->istn.backy,mtg->istn.backz,mtg->istn.backh,
             mtg->istn.backx1,mtg->istn.backy1,mtg->istn.backz1,
             mtg->istn.headh[0],mtg->istn.headh[1],mtg->istn.tailh[0],mtg->istn.tailh[1],
             mtg->istn.headv[0],mtg->istn.headv[1],mtg->istn.tailv[0],mtg->istn.tailv[1],
             mtg->istn.azi[0],mtg->istn.azi[1],mtg->istn.pitch[0],mtg->istn.pitch[1],
             mtg->istn.roll[0],mtg->istn.roll[0],(long)mtg->istn.t
            );
            RadioMsg(msg);
            break;
        }
        case 13:
        {
            sprintf(msg,"%%R1D,45:0:%d\n",mtg->nbsk);
            RadioMsg(msg);
            for(i=0;i<mtg->nbsk;i++)
            {
                sprintf(msg,"%%R1D,45:1:%d,'%s',%lf,%lf,%lf,%ld\n",
                    i,mtg->bask[i].name,mtg->bask[i].x,mtg->bask[i].y,mtg->bask[i].z,(long)mtg->bask[i].t);
                RadioMsg(msg);
            }
            break;
        }
        case 14:
        {
            for(i=0;i<2;i++)
            {
                sprintf(msg,"%%R1D,24:0:%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                    %d,%d,%d,%d,'%s'\n",
                    i,mtg->camset[i].w,mtg->camset[i].h,mtg->camset[i].affine[0],mtg->camset[i].affine[1],mtg->camset[i].affine[2],
                    mtg->camset[i].affine[3],mtg->camset[i].affine[4],mtg->camset[i].affine[5],
                    mtg->camset[i].affine[6],mtg->camset[i].affine[7],mtg->camset[i].affine[8],
                    mtg->camset[i].x1,mtg->camset[i].y1,mtg->camset[i].x2,mtg->camset[i].y2,mtg->camset[i].name);
                RadioMsg(msg);
            }
            break;
        }
        case 16:
        {
            sprintf(msg,"%%R1D,201:0:%d\n",0);
            RadioMsg(msg);
            break;
        }
        case 17:
        {
            sprintf(msg,"%%R1D,57:0:%d,%lf,%lf\n",
                    mtg->snum.iseg,mtg->snum.mile,mtg->snum.tm);
            RadioMsg(msg);
            break;
        }
        default:
            break;
    }
}

void mtg_t_svrFrame::OnSocketEvent(wxSocketEvent& event)
{
    wxSocketBase *sock = event.GetSocket();
    static char buffer[1024];
    static char word[1024];
    int index=0;
    //FILE* fp = fopen("E:\\sock.txt","a");
    for(index=0; index<ncli; index++)
    {
        if(m_clients[index].sock==sock)
        {
            break;
        }
    }
    // Now we process the event

    switch(event.GetSocketEvent())
    {
    case wxSOCKET_INPUT:
    {
        // We disable input events, so that the test doesn't trigger
        // wxSocketEvent again.
        sock->SetNotify(wxSOCKET_LOST_FLAG);
        if(index==ncli)    ///用户登录
        {
            //ncli++;
            sock->Read(buffer, 1024);
            int num=sock->LastCount();
            buffer[num]=0;
            //fprintf(fp,"buffer=%s\n",buffer);
            //fflush(fp);

            ///解译
            for(int i=0; i<num; i++)
            {
                if(buffer[i]=='%')
                {
                    char* ptr=strchr((char*)buffer+i,'\n');
                    int j=ptr-buffer+1;
                    if(ptr)
                    {
                        memcpy(word,buffer+i,j-i);
                        word[j-i]=0;
                        DecodeCommand(sock,word);
                    }
                    break;
                }
            }
        }
        else
        {
            sock->Read(m_clients[index].buffer+m_clients[index].nbuf, 1024-m_clients[index].nbuf);
            m_clients[index].nbuf+=sock->LastCount();
            ///注意，这里需要将buffer加上结束符
            m_clients[index].buffer[m_clients[index].nbuf]=0;

            while(m_clients[index].nbuf>0)
            {
                bool brk=true;
                for(int i=0; i<m_clients[index].nbuf; i++)
                {
                    if(m_clients[index].buffer[i]=='%')
                    {
                        char* ptr=strchr((char*)m_clients[index].buffer+i,'\n');
                        if(ptr)
                        {
                            int j=(ptr-m_clients[index].buffer)+1;
                            memcpy(word,m_clients[index].buffer+i,j-i);
                            word[j-i]=0;
                            DecodeCommand(sock,word);
                            memmove(m_clients[index].buffer,m_clients[index].buffer+j,m_clients[index].nbuf-j);
                            m_clients[index].nbuf-=j;
                            ///注意，这里需要将buffer加上结束符
                            m_clients[index].buffer[m_clients[index].nbuf]=0;
                            brk=false;
                        }
                        break;
                    }
                }
                if(brk) break;
            }
        }

        sock->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);
        break;
    }
    case wxSOCKET_LOST:
    {
        if(index<ncli)
        {
            char log[64];
            sprintf(log,"用户<%s>退出",m_clients[index].addr);
            if(index>0)
            {
                for(int i=index;i<ncli-1;i++)
                {
                    m_clients[i]=m_clients[i+1];
                }
            }
            else
            {
                m_clients[index].sock=0;
                m_clients[index].nbuf=0;
                strcpy(m_clients[index].buffer,"\0");
                strcpy(m_clients[index].addr,"\0");
            }
            ncli--;
            add_msg_log(mtg,log,1);
            panelMode->Refresh();
        }
        sock->Destroy();

        break;
    }
    default:
        break;
    }
    //fclose(fp);
//  UpdateStatusBar();
}

void mtg_t_svrFrame::OnClose(wxCloseEvent& event)
{
    ConfirmDlg dlg(this);
    dlg.Center();
    if(dlg.ShowModal()==wxID_OK)
    {
        timerStat.Stop();
        sleepms(50);
        event.Skip();
    }
    else
    {
        event.Veto();
    }
}

void mtg_t_svrFrame::OnLogDoubleClicked(wxCommandEvent& event)
{
    /*LogDialog dlg(this);
    dlg.Center();
    dlg.ShowModal();*/
    //logDlg=new LogDialog(this);
    if(logDlg)
    {
        logDlg->Center();
        logDlg->Show();
    }
}

static int times=0;
void mtg_t_svrFrame::RunMeasurement()
{
//    if(times==0)
//    {
//        mtg->m=mtg->m1;
//        mtg->m.hdev1=0;
//        mtg_dc_meas(mtg,0);
//        if(mtg_store_meas(mtg))
//            mtg_log(mtg,MTG_LOG_FINISH_CYCLE);
//        times++;
//    }
//    else
//    {
//        mtg->m=mtg->m1;
//        if(times<5)
//           mtg->m.hdev1-=0.005*times;
//        else if(times<10)
//            mtg->m.hdev1=0.005*(times-5);
//        else if(times<15)
//            mtg->m.hdev1=0.001*(times-10);
//        else
//            mtg->m.hdev1=0.002*(times-15);
//        mtg->hdev1=mtg->m.hdev1;
//        mtg->vdev1=mtg->m.vdev1;
//        mtg->hdev2=mtg->m.hdev2;
//        mtg->vdev2=mtg->m.vdev2;
//        mtg->hdev3=mtg->m.hdev3;
//        mtg->vdev3=mtg->m.vdev3;
//        ///wxMessageBox(wxString::Format(_("%.4f"),mtg->m.hdev1*1000.0));
//        mtg_dc_meas(mtg,0);
//        char dbpath[1024];
//        sprintf(dbpath,"D:\\midu\\dc_meas.db");
//        sqlite_export_dc_meas(mtg,dbpath);
//        if(mtg_store_meas(mtg))
//            mtg_log(mtg,MTG_LOG_FINISH_CYCLE);
//        times++;
//    }

    if(mtg->tarset.stopped)
    {
        wxMessageBox(_("激光靶角度异常，请立刻联系上海米度测量技术有限公司！"),_("警告"),wxOK|wxICON_ERROR);
        return;
    }
    mtg_start_cycle(mtg);
    FILE* fp=fopen(mtg->popi,"a");
    if(fp)
    {
        time_t now;
        time(&now);
        fprintf(fp,"%%R1P,%d,%ld\n",2,now);     ///启动周期测量
        fclose(fp);
    }
}

void mtg_t_svrFrame::EndMeasurement()
{
    mtg_stop(mtg);
    panelMode->Refresh();
    panelGraph->Refresh();
    FILE* fp=fopen(mtg->popi,"a");
    if(fp)
    {
        time_t now;
        time(&now);
        fprintf(fp,"%%R1P,%d,%ld\n",3,now);     ///终止周期测
        fclose(fp);
    }
}

void mtg_t_svrFrame::OriginSegMeasurement()
{
    if(mtg->maj.amoding)
    {
        wxMessageBox(_("拼装状态下不可标定,待拼装完成机器停止时再标定!"));
        return ;
    }
    wxMessageBox(_("注意:未初始标定成功前,不得开始掘进,否则导向系统无法指导掘进!"));
    int num=0;
    for(int i=0;i<mtg->tbm.naj;i++)
    {
        if(mtg->maj.iaj[i]==1)
        {
            num++;
        }
    }
    if(num==0)
    {
        wxMessageBox(wxString::Format(_("至少需要3组推进油缸行程数据,目前无推进油缸行程数据,因此无法进行初始标定!"),num));
    }
    else if(num<3)
    {
        wxMessageBox(wxString::Format(_("至少需要3组推进油缸行程数据,目前只获取到%d个推进油缸行程,无法进行初始标定"),num));
    }
    else
    {
        mtg->maj.deth=mtg->maj0.deth;
        mtg->maj.detv=mtg->maj0.detv;
        mtg->maj.status=0;
        if(sqlite_export_origin_aj(mtg,mtg->sqlitepath)==0)
        {
            mtg_start_origin_segmeas(mtg);

//            mtg_laser_to_aj(mtg);
//
//            time(&mtg->maj.t4);
//            mtg->maj.status=1;
//            if(sqlite_export_origin_aj(mtg,mtg->sqlitepath)==0)
//            {
//                ///成功
//                mtg_log(mtg,MTG_LOG_FINISH_STORE_ORIGIN_SEG);
//            }
//            else
//            {
//                ///失败
//                mtg_log(mtg,MTG_LOG_FAIL_STORE_ORIGIN_SEG);
//            }
        }
        else
        {
            wxMessageBox(_("数据复位失败,已停止初始标定!"));
        }
    }
}

void mtg_t_svrFrame::CalRings()
{
    SegmentDlg *dlg = new SegmentDlg(this);
    dlg->Center();
    dlg->ShowModal();
    FILE* fp=fopen(mtg->popi,"a");
    if(fp)
    {
        time_t now;
        time(&now);
        fprintf(fp,"%%R1P,%d,%ld\n",4,now);     ///管环选型
        fclose(fp);
    }
}

void mtg_t_svrFrame::MoveStation()
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
            MySetupDlg dlg(this);
            dlg.Center();
            dlg.ShowModal();
            panelStatus->Refresh();
            panelMetric->Refresh();
            panelBar->Refresh();
            FILE* fp=fopen(mtg->popi,"a");
            if(fp)
            {
                time_t now;
                time(&now);
                fprintf(fp,"%%R1P,%d,%ld,%d\n",5,now,mtg->onLine);     ///移站
                fclose(fp);
            }
            //setupDlg=0;
        }
    }
}

void mtg_t_svrFrame::Check()
{
    //checkDlg = new CheckUpDlg(this);
    MyCheckDlg dlg(this);
    dlg.Center();
    dlg.ShowModal();
    FILE* fp=fopen(mtg->popi,"a");
    if(fp)
    {
        time_t now;
        time(&now);
        fprintf(fp,"%%R1P,%d,%ld\n",6,now);     ///检查
        fclose(fp);
    }
    //ReviewDlg = new ReviewDlg(this);
    //ReviewDlg->Center();
    //ReviewDlg->ShowModal();
    //checkDlg->Destroy();
    //checkDlg=0;
}

void mtg_t_svrFrame::Query()
{
    if(mtg->iset.pqry==1)
    {
        PasswordDialog dlg(this);

        dlg.TextPassword->SetFocus();
        dlg.Center();

        if(dlg.ShowModal()==wxID_OK)
        {
            if(dlg.iuser>=0)
            {
                mtg->onLine = dlg.iuser;
                MyQueryDlg dlg(this);
                dlg.Center();
                dlg.ShowModal();
                FILE* fp=fopen(mtg->popi,"a");
                if(fp)
                {
                    time_t now;
                    time(&now);
                    fprintf(fp,"%%R1P,%d,%ld,%d\n",7,now,mtg->onLine);     ///查询
                    fclose(fp);
                }
            }
        }
    }
    else
    {
        MyQueryDlg dlg(this);
        dlg.Center();
        dlg.ShowModal();
        FILE* fp=fopen(mtg->popi,"a");
        if(fp)
        {
            time_t now;
            time(&now);
            fprintf(fp,"%%R1P,%d,%ld,\n",7,now);     ///查询
            fclose(fp);
        }
    }
}

void mtg_t_svrFrame::EditDTA()
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
            FILE* fp=fopen(mtg->popi,"a");
            if(fp)
            {
                time_t now;
                time(&now);
                fprintf(fp,"%%R1P,%d,%ld,%d\n",8,now,mtg->onLine);     ///中线
                fclose(fp);
            }
        }
    }
}

void mtg_t_svrFrame::ViewMap()
{
    ///非模式对话框
   /* MapViewDlg *dlg = new MapViewDlg(this);
    dlg->Center();
    dlg->Show(true);*/
    if(map_ready==0)
    {
        mapDlg=new MapViewDlg(this);
        mapDlg->Center();
        mapDlg->Show(true);
        map_ready=1;
        mapDlg->OnUse=1;
        FILE* fp=fopen(mtg->popi,"a");
        if(fp)
        {
            time_t now;
            time(&now);
            fprintf(fp,"%%R1P,%d,%ld,\n",9,now);     ///地图
            fclose(fp);
        }
    }
    else
    {
        mapDlg->Show(true);
        mapDlg->OnUse=1;
        FILE* fp=fopen(mtg->popi,"a");
        if(fp)
        {
            time_t now;
            time(&now);
            fprintf(fp,"%%R1P,%d,%ld,\n",9,now);     ///地图
            fclose(fp);
        }
    }
    //mapDlg=0;
}

void mtg_t_svrFrame::Settings()
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
            //confDlg=new ConfigDlg(this);
            //confDlg->opLevel=i;
            //confDlg->Center();
            //confDlg->ShowModal();
            ConfigDlg dlg(this);
            dlg.Center();
            dlg.opLevel=i;
            mtg->onLine=i;
            //wxMessageBox(wxString::Format(_("%d"),mtg->onLine));
            dlg.ShowModal();
            panelStatus->Refresh();
            panelMetric->Refresh();
            panelBar->Refresh();
            FILE* fp=fopen(mtg->popi,"a");
            if(fp)
            {
                time_t now;
                time(&now);
                fprintf(fp,"%%R1P,%d,%ld,%d\n",12,(long)now,mtg->onLine);     ///设置
                fclose(fp);
            }
        }
    }
}

#include "wx/dir.h"
#include <wx/filename.h>
#include "direct.h"
void mtg_t_svrFrame::SaveImage()
{
    int psize=0;
    int nbuff=0;
    if(bufsize!=mtg->camsvr.cams[0].bufsize)
    {
        image.Destroy();
        image.Create(mtg->camsvr.cams[0].width,mtg->camsvr.cams[0].height);
        bufsize=mtg->camsvr.cams[0].bufsize;
        //mtg_log(mtg,MTG_LOG_ERROR_SIZE);
        //mtg->ierr[1]=1;
    }
    psize=mtg->camsvr.cams[0].bufsize;
    if(psize>0)
    {
        int l=0;
        char tmp=0;
        for(int j=0;j<mtg->camsvr.cams[0].height;j++)
        {
            for(int k=0;k<mtg->camsvr.cams[0].width;k++)
            {
                l=(j*mtg->camsvr.cams[0].width+k);
                if(l*3+2>=psize)
                    break;
                tmp=mtg->camsvr.cams[0].buffer[l*3+2];
                mtg->camsvr.cams[0].buffer[l*3+2]=mtg->camsvr.cams[0].buffer[l*3];
                mtg->camsvr.cams[0].buffer[l*3]=tmp;
            }
            if(l*3+2>=psize)
                break;
        }
        //image.Create(mtg->camsvr.cams[0].width,mtg->camsvr.cams[0].height);
        memcpy(image.GetData(),mtg->camsvr.cams[0].buffer,psize);

        wxString name=path1;
        name+=wxDateTime(mtg->camsvr.cams[0].t).Format(_("%Y%m%d%H%M%S.bmp"));
        image.SaveFile(name,wxBITMAP_TYPE_BMP);
        //image.Destroy();

        wxDir dir(path1);
        if(dir.IsOpened())
        {
            int n=0;
            wxArrayString files;
            wxString token=wxT("*.bmp");
            n=dir.GetAllFiles(path1,&files,token,wxDIR_DEFAULT);
            if(n>5)//超过五张照片需要删除多余的部分
            {
                files.Sort(true);
                //files.RemoveAt(5,n-5);
                for(int i=5;i<n;i++)
                {
                    wxRemoveFile(files[i]);
                }
            }
        }
    }
}

void mtg_t_svrFrame::OnSize(wxSizeEvent& event)
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

    ///status
    panelStatus->SetSize(w1,h1-h5,w2,h2+h5);


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
    ///graph
    //panelGraph->SetSize(0,h1,w1-fw2,h2);
    panelGraph->SetSize(0,h1,w1,h2);
    ///history
    //panelHistory->SetSize(w1-fw2,h1,fw2,h2);
    if(iver==1)
    {
        ///log
        //listlog->SetSize(0,h1+h2,w1-230,h3);
        //listlog->SetColumnWidth(2,w1-fw2-460);
        listlog->SetSize(0,h1+h2,w1-fw2,h3);
        listlog->SetColumnWidth(2,w1-fw2-230);
        panelPointer->Show(false);
        ///logo
        panelLogo->SetSize(w1-230,h1+h2,w2+230,h3);
    }
    else
    {
        ///log
        //listlog->SetSize(0,h1+h2,w1-fw2,h3);
        //listlog->SetColumnWidth(2,w1-fw2-230);
        listlog->SetSize(0,h1+h2,w1,h3);
        listlog->SetColumnWidth(2,w1-230);
        //panelPointer->SetSize(w1-fw2,h1+h2,fw2,h3);
        ///logo
        panelLogo->SetSize(w1,h1+h2,w2,h3);
    }
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
    listlog->Refresh();
    //panelTitle->Refresh();
    //panelButtonList->Refresh();
}

void mtg_t_svrFrame::PaintBattery(wxMemoryDC* memDC, wxRect rect)
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

void mtg_t_svrFrame::OnPaintMode(wxPaintEvent& event)
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

    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);

        int c1 = 255;
        int c2 = 255;
        int c3 = 30;

        int x1,x2,w1;
        metroFig2->GetSize(&w1,0);
        x1=w-w1;
        w1=w1/3;
        x2=x1+w1;

        wxString valstr=wxEmptyString;
        memDC.SetTextForeground(wxColor(71,71,71));
        if(mtg->m1.t1>0)
        {
            time_t now;
            time(&now);
            time_t timing;
            timing=now-mtg->m1.t1;
            if(timing>mtg->iset.talw)
            {
                c1=255;
                c2=255;
                c3=30;
                for(int i=0;i<h;i++)
                {
                    memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                    memDC.DrawLine(x1,i,x2,i);
                    if(i%2==0)
                    {
                        c1-=3;
                        c2-=5;
                        c3+=4;
                    }
                }
                memDC.SetPen(wxPen(wxColor(236,236,236)));
                memDC.DrawLine(x1,h-2,x2,h-2);
                memDC.SetPen(wxPen(wxColor(104,104,104)));
                memDC.DrawLine(x1,h-1,x2,h-1);
                memDC.DrawLine(x1,0,x2,0);
                memDC.DrawLine(x1-1,0,x1-1,h);
            }
            else
            {
                c1=236;
                c2=236;
                c3=236;
                for(int i=0;i<h;i++)
                {
                    memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                    memDC.DrawLine(x1,i,x2,i);
                    c1--;
                    c2--;
                    c3--;
                }
                memDC.SetPen(wxPen(wxColor(236,236,236)));
                memDC.DrawLine(x1,h-2,x2,h-2);
                memDC.SetPen(wxPen(wxColor(104,104,104)));
                memDC.DrawLine(x1,h-1,x2,h-1);
                memDC.DrawLine(x1,0,x2,0);
                memDC.DrawLine(x1-1,0,x1-1,h);
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
            memDC.DrawLabel(valstr,wxRect(x1,0,w1,h),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            c1=255;
            c2=255;
            c3=30;
            for(int i=0;i<h;i++)
            {
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
                if(i%2==0)
                {
                    c1-=3;
                    c2-=5;
                    c3+=4;
                }
            }
            memDC.SetPen(wxPen(wxColor(236,236,236)));
            memDC.DrawLine(x1,h-2,x2,h-2);
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.DrawLine(x1,h-1,x2,h-1);
            memDC.DrawLine(x1,0,x2,0);
            memDC.DrawLine(x1-1,0,x1-1,h);

            valstr = _("---");
            memDC.DrawLabel(valstr,wxRect(x1,0,w1,h),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetTextForeground(wxColor(71,71,71));
        x1=x2;
        x2=x1+w1;
        if(mtg->itbm<=1)
        {
            c1=255;
            c2=255;
            c3=30;
            for(int i=0;i<h;i++)
            {
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
                if(i%2==0)
                {
                    c1-=3;
                    c2-=5;
                    c3+=4;
                }
            }
            memDC.SetPen(wxPen(wxColor(236,236,236)));
            memDC.DrawLine(x1,h-2,x2,h-2);
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.DrawLine(x1,h-1,x2,h-1);
            memDC.DrawLine(x1,0,x2,0);
            memDC.DrawLine(x1-1,0,x1-1,h);
        }
        else
        {
            c1=236;
            c2=236;
            c3=236;
            for(int i=0;i<h;i++)
            {
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
                c1--;
                c2--;
                c3--;
            }
            memDC.SetPen(wxPen(wxColor(236,236,236)));
            memDC.DrawLine(x1,h-2,x2,h-2);
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.DrawLine(x1,h-1,x2,h-1);
            memDC.DrawLine(x1,0,x2,0);
            memDC.DrawLine(x1-1,0,x1-1,h);
        }
        memDC.DrawLabel(_("PLC"),wxRect(x1,0,w1,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x2;
        x2=w;
        if(ncli<=0)
        {
            c1=255;
            c2=255;
            c3=30;
            for(int i=0;i<h;i++)
            {
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
                if(i%2==0)
                {
                    c1-=3;
                    c2-=5;
                    c3+=4;
                }
            }
            memDC.SetPen(wxPen(wxColor(236,236,236)));
            memDC.DrawLine(x1,h-2,x2,h-2);
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.DrawLine(x1,h-1,x2,h-1);
            memDC.DrawLine(x1,0,x2,0);
            memDC.DrawLine(x1-1,0,x1-1,h);
        }
        else
        {
            c1=236;
            c2=236;
            c3=236;
            for(int i=0;i<h;i++)
            {
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
                c1--;
                c2--;
                c3--;
            }
            memDC.SetPen(wxPen(wxColor(236,236,236)));
            memDC.DrawLine(x1,h-2,x2,h-2);
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.DrawLine(x1,h-1,x2,h-1);
            memDC.DrawLine(x1,0,x2,0);
            memDC.DrawLine(x1-1,0,x1-1,h);
        }
        memDC.SetFont(chs);
        memDC.DrawLabel(_("远程"),wxRect(x1,0,w1,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=0;
        metroFig2->GetSize(&w1,0);
        x2=w-w1-1;
        double l1,l2,len;
        double vi;
        h_element* he;
        v_element* ve;

        if(mtg->m1.t1>0) l1=mtg->m1.mile1;
        else l1=mtg->prj.mile1;
        if(Err > 0)
        {
            memDC.SetTextForeground(wxColor(239,249,255));
            c1 = 255;
            c2 = 0;
            c3 = 0;
            for(int i=0;i<h;i++)
            {
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
                if(i%2==0)
                {
                    c1-=3;
                    c2+=6;
                    c3+=4;
                }
                memDC.SetPen(wxPen(wxColor(236,236,236)));
                memDC.DrawLine(x1,h-2,x2,h-2);
                memDC.SetPen(wxPen(wxColor(104,104,104)));
                memDC.DrawLine(x1,h-1,x2,h-1);
                memDC.DrawLine(x1,0,x2,0);
            }

            switch(Err)
            {
                case ID_ERR_NO_CAMSET:
                {
                    valstr=_("缺少激光靶文件，请检查！");
                    break;
                }
                case ID_ERR_NO_TAR:
                {
                    valstr=_("激光靶参数错误，请检查！");
                    break;
                }
                case ID_ERR_NO_STN:
                {
                    valstr=_("系统未进行设站定向，请检查！");
                    break;
                }
                case ID_ERR_NO_ORI:
                {
                    valstr=_("TBM位置未初始化，请检查！");
                    break;
                }
                case ID_ERR_NO_HE:
                {
                    valstr=_("系统缺少平曲线数据，请检查！");
                    break;
                }
                case ID_ERR_NO_VE:
                {
                    valstr=_("系统缺少竖曲线数据，请检查！");
                    break;
                }
                case ID_ERR_NO_TPS:
                {
                    valstr=_("全站仪未连接，请检查！");
                    break;
                }
                case ID_ERR_NO_PSM:
                {
                    valstr=_("激光屏初始化失败，请检查！");
                    break;
                }
                case ID_ERR_NO_INC:
                {
                    valstr=_("姿态仪初始化失败，请检查！");
                    break;
                }
                case ID_ERR_STN:
                {
                    valstr=_("测站异常，请检查！");
                    break;
                }
                case ID_ERR_INC_OUT:
                {
                    valstr=_("激光靶角度异常，请检查！");
                }
                default:
                    break;
            }
            memDC.DrawLabel(valstr,wxRect(x1+15,0,0,h),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            c1=236;
            c2=236;
            c3=236;
            for(int i=0;i<h;i++)
            {
                memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                memDC.DrawLine(x1,i,x2,i);
                c1--;
                c2--;
                c3--;
            }
            memDC.SetPen(wxPen(wxColor(236,236,236)));
            memDC.DrawLine(x1,h-2,x2,h-2);
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.DrawLine(x1,h-1,x2,h-1);
            memDC.DrawLine(x1,0,x2,0);

            if(tip==nks)
            {
                //wxMessageBox(_("ok"));
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
                    memDC.DrawLabel(tipstr[0],wxRect(x1+15,0,0,h),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }
            }
            else if(tip==nks+1)
            {
                memDC.DrawLabel(tipstr[1],wxRect(x1+15,0,0,h),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
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
                    memDC.DrawLabel(tipstr[2],wxRect(x1+15,0,0,h),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }
            }
            else if(tip==nks+3)
            {
                memDC.DrawLabel(tipstr[3],wxRect(x1+15,0,0,h),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else if(nks>0)
            {
                if(tip<nks)
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
                    memDC.DrawLabel(valstr,wxRect(x1+15,0,0,h),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }
            }
        }
        /*


        x1 = 1;
        y1 = 1;
        metroFig2->GetSize(&x2,0);
        x2=w-x2;
        y2 = h-2;
        double l1,l2,len;
        double vi;

        h_element* he;
        v_element* ve;

        if(mtg->m1.t1>0) l1=mtg->m1.headc;
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
                case ID_ERR_NO_CAMSET:
                {
                    valstr=_("缺少激光靶文件，请检查！");
                    break;
                }
                case ID_ERR_NO_TAR:
                {
                    valstr=_("激光靶参数错误，请检查！");
                    break;
                }
                case ID_ERR_NO_STN:
                {
                    valstr=_("系统未进行设站定向，请检查！");
                    break;
                }
                case ID_ERR_NO_ORI:
                {
                    valstr=_("TBM位置未初始化，请检查！");
                    break;
                }
                case ID_ERR_NO_HE:
                {
                    valstr=_("系统缺少平曲线数据，请检查！");
                    break;
                }
                case ID_ERR_NO_VE:
                {
                    valstr=_("系统缺少竖曲线数据，请检查！");
                    break;
                }
                case ID_ERR_NO_TPS:
                {
                    valstr=_("全站仪未连接，请检查！");
                    break;
                }
                case ID_ERR_NO_PSM:
                {
                    valstr=_("激光屏初始化失败，请检查！");
                    break;
                }
                case ID_ERR_NO_INC:
                {
                    valstr=_("姿态仪初始化失败，请检查！");
                    break;
                }
                case ID_ERR_STN:
                {
                    valstr=_("测站异常，请检查！");
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
                            vi=ve->angle1;
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
                                vi=ve->angle1;
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
*/
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_svrFrame::OnPaintLogo(wxPaintEvent& event)
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
        if(iver==1 || iver==2)
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

void mtg_t_svrFrame::PaintHorizon(wxMemoryDC* memDC, wxRect rect,double ds)
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
//    FILE* fp = fopen("D:\\midu\\painthorizon.log","w");
    FILE* fp = NULL;
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
//    if(mtg->m1.t1>0)    ///有测量数据
//    {
//        d1 = fabs(midc-tailc);     ///后筒体长度
//        d2 = fabs(headc-midc);      ///前筒体长度
//        pds = d1/(d1+d2);
//    }
    if(mtg->m1.t1>0)
    {
        d1 = fabs(mtg->m1.mile2-mtg->m1.mile3);
        d2 = fabs(mtg->m1.mile1-mtg->m1.mile2);
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
    if(mtg->tbm.type==1 && mtg->iset.tailapply==1)
        w3=w1;
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

    double ori=0.0;
    if(mtg->m1.t1>0)
    {
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
        arrow[0].x=w4-dw2*sin(-ori);
        arrow[0].y=h4-dh2*cos(ori);
        arrow[1].x=x+w2;
        arrow[1].y=h2;
        arrow[2].x=w4+dw2*sin(-ori);
        arrow[2].y=h4+dh2*cos(ori);
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
        if(mtg->tbm.type==1 && mtg->iset.tailapply==1)
        {
            memDC->SetPen(wxPen(wxColor(0,75,255)));
            memDC->DrawLine(x+w3,h3,x+w2,h2);
        }
        else
        {
            memDC->SetPen(wxPen(wxColor(0,75,255)));
            memDC->DrawLine(x+w1,h1,x+w3,h3);
            memDC->DrawLine(x+w3,h3,x+w2,h2);
            memDC->SetPen(wxPen(wxColor(255,0,0)));
            memDC->DrawLine(x+w3-dw2*3/2,h3-dh2*3/2-1,x+w3+dw2*3/2,h3+dh2*3/2);
        }
    }
    else
    {
        memDC->SetPen(wxPen(wxColor(255,255,255)));
        memDC->SetPen(wxPen(wxColor(0,75,255)));
        memDC->DrawLine(x+w1,h1,x+w2,h2);
    }

    wxFont chs(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxString str;
    if(mtg->iset.vibration==1)
    {
        if(mtg->maj0.status==0)
        {
            memDC->SetTextForeground(wxColor(255,0,0));
            str=_("震动环境下,未初始标定,不可掘进!");
            memDC->DrawLabel(str,wxRect(0,0,w,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
    }
    if(fp)
    {
        fclose(fp);
    }
}

void mtg_t_svrFrame::PaintVertical(wxMemoryDC* memDC, wxRect rect,double ds)
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
//    FILE* fp=fopen("D:\\midu\\PaintVertical.log","w");
    FILE* fp=NULL;
    memDC->SetPen(wxPen(wxColor(112,112,112)));
    memDC->SetBrush(wxBrush(wxColor(248,248,248)));
    memDC->DrawRectangle(x,y+1,w,h-2);

    double d1,d2,pds;
    double  length;
//    if(mtg->m1.t1>0 && mtg->iset.vmileage==1)
//    {
//        d1 = fabs(midc-tailc);
//        d2 = fabs(headc-midc);
//        pds = d1/(d1+d2);
//    }
    if(mtg->m1.t1>0)
    {
        d1 = fabs(mtg->m1.mile2-mtg->m1.mile3);
        d2 = fabs(mtg->m1.mile1-mtg->m1.mile2);
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
    if(mtg->tbm.type==1 && mtg->iset.tailapply==1)
        w3=w1;
//    double len=2*length;
//    len=50.0;
//    double scale=len/length;
    double scale=1.0;               ///20200729ws 参考whq修改
//    double len=length*2*scale;
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
                        ///20210319ws 注释以下部分
                        lines[nlines].x = x+w;
                        lines[nlines].y = y+h/2;
                        nlines++;   ///20210319

                        ///20210319 ws add以下部分
                        x2 = l2;
                        road_l2h(&mtg->r,l2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        x2 = x-len*cos(alf2);
                        y2 = y+h/2-len*sin(alf2)*scale;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;

                        nlines++;   ///20210319

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

    double phi=0.0;
    if(mtg->m1.t1>0)
    {
//        h1 = h1-tailv*ds;
//        h2 = h2-headv*ds;
//        double phi=0.0;
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
        arrow[0].x=w4-dw2*sin(-phi);
        arrow[0].y=h4-dh2*cos(phi);
        arrow[1].x=x+w2;
        arrow[1].y=h2;
        arrow[2].x=w4+dw2*sin(-phi);
        arrow[2].y=h4+dh2*cos(phi);
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
        if(mtg->tbm.type==1 && mtg->iset.tailapply==1)
        {
            memDC->SetPen(wxPen(wxColor(0,75,255)));
            memDC->DrawLine(x+w3,h3,x+w2,h2);
        }
        else
        {
            memDC->SetPen(wxPen(wxColor(0,75,255)));
            memDC->DrawLine(x+w1,h1,x+w3,h3);
            memDC->DrawLine(x+w3,h3,x+w2,h2);
            memDC->SetPen(wxPen(wxColor(255,0,0)));
            memDC->SetBrush(*wxTRANSPARENT_BRUSH);
            memDC->DrawLine(x+w3-dw2*3/2,h3-dh2*3/2-1,x+w3+dw2*3/2,h3+dh2*3/2);
        }
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

void mtg_t_svrFrame::OnPaintGraph(wxPaintEvent& event)
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

        memDC.SetPen(wxPen(wxColor(220,220,220)));
        memDC.SetBrush(wxBrush(wxColor(220,220,220)));
        //memDC.SetPen(wxPen(wxColor(150,163,172)));
        //memDC.SetBrush(wxBrush(wxColor(150,163,172)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
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
        w1=90;
        h1=h*13/20-4;
        //mtg->deth=0.02;
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(w-1,0,w-1,h);
        if(fabs(mtg->deth)>=mtg->iset.balw/1000.0) memDC.SetBrush(wxBrush(wxColor(254,254,0)));
        else memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1/2+1);
        if(fabs(mtg->detv)>=mtg->iset.balw/1000.0) memDC.SetBrush(wxBrush(wxColor(254,254,0)));
        else memDC.SetBrush(wxBrush(wxColor(255,255,255)));//memDC.SetBrush(wxBrush(wxColor(204,251,200)));
        memDC.DrawRectangle(x1,y1+h1/2,w1,h1/2);
        //memDC.DrawLine(x1,y1+h1/2,x1+w1,y1+h1/2);

        wxString istr;
        istr=_("H: ")+wxString::Format(_("%.1f mm"),mtg->deth*1000.0);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(0,0,0));
        memDC.DrawLabel(istr,wxRect(x1+10,y1+h1/4,w1,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        istr=_("V: ")+wxString::Format(_("%.1f mm"),mtg->detv*1000.0);
        memDC.DrawLabel(istr,wxRect(x1+10,y1+h1*3/4,w1,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_svrFrame::OnPaintButton(wxPaintEvent& event)
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
        int index=0;
        for(int i=0;i<btns;i++)
        {
            y=11+index*btn_h;
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
            index++;
            //memDC.DrawLabel(btn_label[i],wxRect(x+w/10,y-btn_height+2,w*9/10,btn_height-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_svrFrame::OnMotionButton(wxMouseEvent& event)
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

void mtg_t_svrFrame::OnLeaveButton(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    panelButton->Refresh();
}

void mtg_t_svrFrame::OnClickButton(wxMouseEvent& event)
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

void mtg_t_svrFrame::OnPaintTool(wxPaintEvent& event)
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
            memDC.DrawRectangle(x1,y1,w1-2,h1);
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
        x1=x1-w1-2;
        button[ID_BTN_DOC].x=x1;
        button[ID_BTN_DOC].y=y1;
        button[ID_BTN_DOC].width=w1;
        button[ID_BTN_DOC].height=h1;

        if(mtg->fbi)
        {
            h2=h-6;
            w2=h2*4/3;
            x2=x1+w1/2-w2/2;
            y2=y1+3;
            memDC.SetPen(wxPen(wxColor(168,181,178)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.DrawRectangle(x2,y2,w2,h2);

            memDC.SetPen(wxPen(wxColor(168,181,178)));
            memDC.DrawLine(x2+7,y2+h2/2-1,x2+w2-7,y2+h2/2-1);
            memDC.DrawLine(x2+7,y2+h2/2,x2+w2-7,y2+h2/2);
            memDC.DrawLine(x2+w2/2,y2+5,x2+w2/2,y2+h2-5);
            memDC.DrawLine(x2+w2/2+1,y2+5,x2+w2/2+1,y2+h2-5);
        }
        else
        {
            if(motion==ID_BTN_DOC)
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
            memDC.DrawRectangle(x2,y2,w2,h2);

            memDC.SetPen(wxPen(wxColor(47,139,205)));
            memDC.DrawLine(x2+7,y2+h2/2-1,x2+w2-7,y2+h2/2-1);
            memDC.DrawLine(x2+7,y2+h2/2,x2+w2-7,y2+h2/2);
            memDC.DrawLine(x2+w2/2,y2+5,x2+w2/2,y2+h2-5);
            memDC.DrawLine(x2+w2/2+1,y2+5,x2+w2/2+1,y2+h2-5);
        }
        /*memDC.SetPen(wxPen(wxColor(0,255,0)));
        memDC.DrawLine(x2+2,y2+h2/2,x2+w2-4,y2+h2/2);
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        //memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        memDC.DrawLine(x2+2,y2+h2/4,x2+w2/4,y2+h2/4);
        memDC.DrawLine(x2+w2/4,y2+h2/4,x2+w2/2,y2+h2/4+h2/8);
        memDC.DrawLine(x2+w2/2,y2+h2/4+h2/8,x2+w2*3/4,y2+h2/4+h2/8);
        memDC.DrawLine(x2+w2*3/4,y2+h2/4+h2/8,x2+w2-4,y2+h2/2);*/
        //memDC.DrawArc(x2+2,y2+h2/4,x2+w2-4,y2+h2/2,x2+w2-4,-40);


        if(mtg->iset.vibration==1)
        {
            int w3;
            metroFig2->GetSize(&w3,0);
            w1=(x1-(w-w3))/2;
            x1=w-w3;
            y1=0;
            //x2=w-w3;
            x2=x1+w1-2;
            int r,g,b;

            button[ID_BTN_ORIGIN_SEG].x=x1;
            button[ID_BTN_ORIGIN_SEG].y=y1;
            button[ID_BTN_ORIGIN_SEG].width=w1;
            button[ID_BTN_ORIGIN_SEG].height=h1;
            if(motion==ID_BTN_ORIGIN_SEG)
            {
                memDC.SetTextForeground(wxColor(0,0,0));
                memDC.SetPen(wxPen(wxColor(173,175,176)));
                //memDC.SetBrush(wxBrush(wxColor(237,240,245)));
                r=200;
                g=225;
                b=250;
                int y=0;
                for(int j=0;j<h;j++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*j/(h-2),g+20*j/(h-2),b)));
                    memDC.DrawLine(x1,y,x2,y);
                    y++;
                }
            }
            else
            {
                memDC.SetTextForeground(wxColor(0,0,0));
                memDC.SetPen(wxPen(wxColor(173,175,176)));
                //memDC.SetBrush(wxBrush(wxColor(237,240,245)));
                r=220;
                g=236;
                b=236;
                int y=0;
                for(int j=0;j<h;j++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x1,y,x2,y);
                    y++;
                }
            }
            memDC.DrawLabel(_("初始标定"),wxRect(x1,0,w1,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.SetPen(wxPen(wxColor(168,181,178)));
            memDC.DrawLine(x1+w1,0,x1+w1,h);
            memDC.DrawLine(x1,0,x1,h);
            memDC.DrawLine(x1,0,x1+w1,0);
            memDC.DrawLine(x1,h,x1+w1,h);

            //w1=(x1-(w-w3))/2;
            x1=w-w3+w1;
            y1=0;
            x2=x1+w1-2;

//            button[ID_BTN_STOP_ORIGIN_SEG].x=x1;
//            button[ID_BTN_STOP_ORIGIN_SEG].y=y1;
//            button[ID_BTN_STOP_ORIGIN_SEG].width=w1;
//            button[ID_BTN_STOP_ORIGIN_SEG].height=h1;
//            memDC.SetTextForeground(wxColor(0,0,0));
//            if(motion==ID_BTN_STOP_ORIGIN_SEG)
//            {
//                memDC.SetPen(wxPen(wxColor(173,175,176)));
//                //memDC.SetBrush(wxBrush(wxColor(237,240,245)));
//                r=200;
//                g=225;
//                b=250;
//                int y=0;
//                for(int j=0;j<h;j++)
//                {
//                    memDC.SetPen(wxPen(wxColor(r+40*j/(h-2),g+20*j/(h-2),b)));
//                    memDC.DrawLine(x1,y,x2,y);
//                    y++;
//                }
//            }
//            else
//            {
//                memDC.SetPen(wxPen(wxColor(173,175,176)));
//                //memDC.SetBrush(wxBrush(wxColor(237,240,245)));
//                r=220;
//                g=236;
//                b=236;
//                int y=0;
//                for(int j=0;j<h;j++)
//                {
//                    memDC.SetPen(wxPen(wxColor(r,g,b)));
//                    memDC.DrawLine(x1,y,x2,y);
//                    y++;
//                }
//            }
//            if(mtg->autoflag==1)
//            {
//                memDC.SetTextForeground(wxColor(0,0,0));
//                memDC.DrawLabel(_("暂停自动标定"),wxRect(x1,0,w1,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
//            }
//            else
//            {
//                memDC.SetTextForeground(wxColor(255,0,0));
//                memDC.DrawLabel(_("恢复自动标定"),wxRect(x1,0,w1,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
//            }
//            memDC.SetPen(wxPen(wxColor(168,181,178)));
//            memDC.DrawLine(x1+w1,0,x1+w1,h);
//            memDC.DrawLine(x1,0,x1,h);
//            memDC.DrawLine(x1,0,x1+w1,0);
//            memDC.DrawLine(x1,h,x1+w1,h);

            int c1,c2,c3;
            if(mtg->maj0.status == 0)
            {
                x1=0;
                x2=w-w3-2;
                memDC.SetTextForeground(wxColor(239,249,255));
                c1 = 255;
                c2 = 0;
                c3 = 0;
                for(int i=0;i<h;i++)
                {
                    memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                    memDC.DrawLine(x1,i,x2,i);
                    if(i%2==0)
                    {
                        c1-=3;
                        c2+=6;
                        c3+=4;
                    }
                    memDC.SetPen(wxPen(wxColor(236,236,236)));
                    memDC.DrawLine(x1,h-2,x2,h-2);
                    memDC.SetPen(wxPen(wxColor(104,104,104)));
                    memDC.DrawLine(x1,h-1,x2,h-1);
                    memDC.DrawLine(x1,0,x2,0);
                }
                wxString valstr;
                valstr=_("震动环境下,未初始标定,不可掘进!");

                memDC.DrawLabel(valstr,wxRect(x1+15,0,x2,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
            else if(mtg->maj0.status == 1)
            {
                x1=0;
                x2=w-w3-2;
                memDC.SetTextForeground(wxColor(239,249,255));
                c1 = 0;
                c2 = 125;
                c3 = 0;
                for(int i=0;i<h;i++)
                {
                    memDC.SetPen(wxPen(wxColor(c1,c2,c3)));
                    memDC.DrawLine(x1,i,x2,i);
                    if(i%2==0)
                    {
                        c2-=3;
                        c1+=6;
                        c3+=4;
                    }
                    memDC.SetPen(wxPen(wxColor(236,236,236)));
                    memDC.DrawLine(x1,h-2,x2,h-2);
                    memDC.SetPen(wxPen(wxColor(104,104,104)));
                    memDC.DrawLine(x1,h-1,x2,h-1);
                    memDC.DrawLine(x1,0,x2,0);
                }
                wxString valstr;
                valstr=_("已初始标定,可开始掘进!");

                memDC.DrawLabel(valstr,wxRect(x1+15,0,x2,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
        }

//        if(time_tip>0)
//        {
////            x1=w*2/3;
////            y1=0;
////            w1=w/6;
////            h1=h;
//            int w3;
//            metroFig2->GetSize(&w3,0);
//            x1=0;
//            y1=0;
//            w1=(w-w3)/2;
//            h1=h;
//            wxFont chs1(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
//            memDC.SetFont(chs1);
//            memDC.SetTextForeground(wxColor(0,0,255));
//
//            if(time_tip==1)
//            {
////                if(remain_d/365>0)
////                {
////                    memDC.DrawLabel(wxString::Format(_("授权许可时间%d年%d天！"),remain_d/365,remain_d%365),wxRect(x1,y1,w1,h1),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
////                }
////                else
//                {
//                    memDC.DrawLabel(wxString::Format(_("授权许可时间剩余%d天！"),remain_d),wxRect(x1,y1,w1,h1),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
//                }
//            }
//            else if(time_tip==2)
//            {
//                memDC.DrawLabel(wxString::Format(_("授权许可已到期！"),remain_d),wxRect(x1,y1,w1,h1),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
//            }
//        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_svrFrame::OnMotionTool(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_PRT_SCN].y && y<button[ID_BTN_PRT_SCN].y+button[ID_BTN_PRT_SCN].height)
    {
        if(x>button[ID_BTN_PRT_SCN].x && x<button[ID_BTN_PRT_SCN].x+button[ID_BTN_PRT_SCN].width)
        {
            motion=ID_BTN_PRT_SCN;
        }
        else if(x>button[ID_BTN_DOC].x && x<button[ID_BTN_DOC].x+button[ID_BTN_DOC].width)
        {
            motion=ID_BTN_DOC;
        }
        else if(x>button[ID_BTN_ORIGIN_SEG].x && x<button[ID_BTN_ORIGIN_SEG].x+button[ID_BTN_ORIGIN_SEG].width)
        {
            motion=ID_BTN_ORIGIN_SEG;
        }
        else if(x>button[ID_BTN_STOP_ORIGIN_SEG].x && x<button[ID_BTN_STOP_ORIGIN_SEG].x+button[ID_BTN_STOP_ORIGIN_SEG].width)
        {
            motion=ID_BTN_STOP_ORIGIN_SEG;
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

void mtg_t_svrFrame::OnLeaveTool(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    panelTool->Refresh();
}

void mtg_t_svrFrame::OnClickTool(wxMouseEvent& event)
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
        mtg_stop_laser(mtg);
    }
    else if(motion==ID_BTN_DOC)
    {
        if(!mtg->fbi)
        {
            MydoctorDlg dlg(this);
            dlg.Center();
            dlg.ShowModal();
        }
        //mtg_start_laser(mtg);
    }
    else if(motion==ID_BTN_ORIGIN_SEG)
    {
        OriginSegMeasurement();
    }
    else if(motion==ID_BTN_STOP_ORIGIN_SEG)
    {
        if(mtg->autoflag==0)///当前已关闭，可恢复
        {
            mtg->autoflag=1;
        }
        else///当前已开启，可关闭
        {
            mtg->autoflag=0;
            if(mtg->originstat)
            {
                mtg_stop(mtg);
            }
        }
    }

    panelTool->Refresh();
}

void mtg_t_svrFrame::OnPaintBar(wxPaintEvent& event)
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
        metroFig2->GetSize(&w1,0);
        panelLogo->GetPosition(&x1,0);
        //panelMetric->GetSize(&x1,0);
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
        if(iver==0) memDC.DrawLabel(_("米度研制"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        else if(iver==1) memDC.DrawLabel(_("米度研制"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        else if(iver==2) memDC.DrawLabel(_("山河智能装备集团"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString(mtg->prj.name,wxConvUTF8),wxRect(x3,y3,w3,h3),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetFont(eni);
        if(mtg->m1.t1>0)
        {
            double p1=mtg->prj.mile1-mtg->prj.mile2;
            p1=fabs(p1);
            double p2=headc-mtg->prj.mile1;
            p2=p2*mtg->prj.a2z;
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
                if(p2<0.0) valstr=_("--%(")+wxString::Format(_("%.1f"),p2)+_("m)");
                else valstr=wxString::Format(_("%.1f"),p2*100/p1)+_("%(")+wxString::Format(_("%.1f"),p2)+_("m)");
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

void mtg_t_svrFrame::GetMetro()
{
    int maxw,maxh;
    double val;
    int a2z=mtg->prj.a2z;
    double x,y,z;
    //FILE* fp=fopen("D://GetMetro.log","w");

    maxw=0;
    maxh=0;

    headh=mtg->m1.hdev1*1000.0;
    headv=mtg->m1.vdev1*1000.0;
    midh=mtg->m1.hdev2*1000.0;
    midv=mtg->m1.vdev2*1000.0;
    tailh=mtg->m1.hdev3*1000.0;
    tailv=mtg->m1.vdev3*1000.0;

    headc=mtg->m1.mile1;
    midc=mtg->m1.mile2;
    tailc=mtg->m1.mile3;
//    if(fp)
//    {
//        fprintf(fp,"headh:%d,%d,%d\n",headh,midh,tailh);
//        fflush(fp);
//    }

    int j=0;
    int nmoff;
    nmoff=road_number_mile_off(&mtg->r);
    if(nmoff>0&&mtg->iset.vmileage==0)
    {
        m_offset *mo={0};
        val=0.0;
        ///20190306whq modify
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
        //trace(0,"metro:ori=%.4f,phi=%.4f,roll=%.4f\n",mtg->m1.inc[0],mtg->m1.inc[0],mtg->m1.inc[0]);


        tbmlen=(head[0]-tail[0])*(head[0]-tail[0])+(head[1]-tail[1])*(head[1]-tail[1]);
        tbmlen = sqrt(tbmlen);
        //trace(0,"metro:len=%.4f\n",tbmlen);
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
            ///20180903whq修改
            htrend=(headh-midh)/tbmlen;
            vtrend=(headv-midv)/tbmlen;
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
        maxw = abs(tailh)>maxw?abs(headh):maxw;
        maxh = abs(headv)>abs(midv)?abs(headv):abs(midv);
        maxh = abs(tailv)>maxw?abs(headv):maxh;

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
            ///20180903whq修改
//            htrend=(headh-midh)/tbmlen;
//            vtrend=(headv-midv)/tbmlen;
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
        if(mtg->tarset.pos==0)
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
        else if(mtg->tarset.pos==1)
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
        //if(fp)
        //{
            //fprintf(fp,"getmetric:fj1=%.4f,fj2=%.4f,fj3=%.4f,fj4=%.4f\n",mtg->m1.faj[0],mtg->m1.faj[1],mtg->m1.faj[2],mtg->m1.faj[3]);
            //fflush(fp);
        //}
        //trace(0,"ui:pit=%.12f,azi=%.12f\n",inc[1],inc[2]);
        maxw = abs(headh)>abs(midh)?abs(headh):abs(midh);
        maxw = abs(tailh)>maxw?abs(tailh):maxw;
        maxh = abs(headv)>abs(midv)?abs(headv):abs(midv);
        maxh = abs(tailv)>maxh?abs(headv):maxh;

        ///20200422ws同步whq
        double dist=0.0;
        dist=(tail[0]-mid[0])*(tail[0]-mid[0])+(tail[1]-mid[1])*(tail[1]-mid[1]);
        dist = sqrt(dist);

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
            //htrend=(headh-midh)/tbmlen;
            //vtrend=(headv-midv)/tbmlen;
//            if(fp)
//            {
//                fprintf(fp,"i1:%.4f,azi:%.4f,inc1:%.4f\n",i1,inc[2],mtg->m1.inc1[2]);
//                fflush(fp);
//            }
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
//    if(fp)
//    {
//        fclose(fp);
//    }
    //trace(0,"GetMetric:headh=%.1f,headv=%.1f,tailh=%.1f,tailv=%.1f\n",mtg->m1.headh*1000.0,mtg->m1.headv*1000.0,mtg->m1.tailh*1000.0,mtg->m1.tailv*1000.0);
    //trace(0,"GetMetric:headh1=%d,headv1=%d,tailh1=%d,tailv1=%d,midh=%d,midv=%d\n",headh,headv,tailh,tailv,midh,midv);
    //trace(0,"GetMetric:len=%.4f,headc=%.4f,tailc=%.4f,headx=%.4f,heady=%.4f,headz=%.4f,tailx=%.4f,taily=%.4f,tailz=%.4f\n",tbmlen,headc,tailc,head[0],head[1],head[2],tail[0],tail[1],tail[2]);
    //trace(0,"GetMetric:hdesx=%.4f,hdesy=%.4f,hdesz=%.4f,tdesx=%.4f,tdesy=%.4f,tdesz=%.4f\n",head[0],head[1],hdes[2],tail[0],tail[1],tail[2]);
    //trace(0,"GetMetric:htrend=%.4f,vtrend=%.4f,roll=%.4f,phi=%.4f,ori=%.4f\n",htrend,vtrend,inc[0],inc[1],inc[2]);
}

void mtg_t_svrFrame::OnPaintMetroFig1(wxPaintEvent& event)
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
        //FILE* fp=fopen("D:\\metricFig1.log","w");
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
        //r[0] = r[0]*9/10;
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
            //fprintf(fp,"x[0]=%.4f,y[0]=%.4f\n",x[0],y[0]);
            for(int i=1;i<6;i++)
            {
                x[i] = x[0]+(sw*i)*cos(alf1);
                y[i] = y[0]+(sw*i)*sin(alf1);
                //fprintf(fp,"x[%d]=%.4f,y[%d]=%.4f\n",i,x[i],i,y[i]);
                //fprintf(fp,"sr1=%.12f,alf1=%.12f\n",sr1,alf1);
                val=0;
                road_xy2l(cl,x[i],y[i],0,0,0,0,&val);
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

            x[0]=(double)gx1;
            y[0]=(double)gy1;
           // fprintf(fp,"2:x[0]=%.4f,y[0]=%.4f\n",x[0],y[0]);
        }
        else
        {
            for(int i=0;i<6;i++)
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
            //fprintf(fp,"x[%d]=%d,y[%d]=%d\n",i,x[i],i,y[i]);
            //fprintf(fp,"x2=%d,y2=%d,r[%d]=%d\n",x2,y2,i,r[i]);
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
        }
        else
        {
            x6=gx1+midh*s;
            y6=gy1-midv*s;
            x5=gx1+headh*s;
            y5=gy1-headv*s;
        }
        ps=0.32;

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
        //if(fp)
        //    fclose(fp);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

#define NANTONG 0   //0：用一个趋势    1：用两个趋势
void mtg_t_svrFrame::OnPaintMetroFig2(wxPaintEvent& event)
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
            if(mtg->tbm.type==1 && mtg->iset.tailapply==1)
            {
                memDC.DrawLabel(_("中"),wxRect(x1+30*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(_("中"),wxRect(x1+30*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(_("中"),wxRect(x1+w1/3+10*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(_("后"),wxRect(x1+10*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(_("中"),wxRect(x1+w1/3+10*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(_("后"),wxRect(x1+10*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            memDC.DrawLabel(_("前"),wxRect(x1+w1*2/3+10*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            memDC.DrawLabel(_("中"),wxRect(x1+w1/3+10*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            memDC.DrawLabel(_("后"),wxRect(x1+10*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("水平偏航"),wxRect(x1+10*sxy,y1+h1-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("前"),wxRect(x1+w1*2/3+10*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            memDC.DrawLabel(_("中"),wxRect(x1+w1/3+10*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            memDC.DrawLabel(_("后"),wxRect(x1+10*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("垂直偏航"),wxRect(x1+10*sxy,y1+h1*2-15*sxy,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetFont(eng2);
            if(mtg->tbm.type==1 && mtg->iset.tailapply==1)
            {
                memDC.DrawLabel(wxString::Format(_("%d"),midh),wxRect(x1+52*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%d"),midv),wxRect(x1+52*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(wxString::Format(_("%d"),midh),wxRect(x1+w1/3+32*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%d"),tailh),wxRect(x1+32*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%d"),midv),wxRect(x1+w1/3+32*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%d"),tailv),wxRect(x1+32*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            memDC.DrawLabel(wxString::Format(_("%d"),headh),wxRect(x1+w1*2/3+32*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            memDC.DrawLabel(wxString::Format(_("%d"),midh),wxRect(x1+w1/3+32*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            memDC.DrawLabel(wxString::Format(_("%d"),tailh),wxRect(x1+32*sxy,y1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),headv),wxRect(x1+w1*2/3+32*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            memDC.DrawLabel(wxString::Format(_("%d"),midv),wxRect(x1+w1/3+32*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            memDC.DrawLabel(wxString::Format(_("%d"),tailv),wxRect(x1+32*sxy,y1+h1+10*sxy,0,25*sxy),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
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

#define ZHONGJIAOTIANHE 0      ///中交天和三菱plc需要写入和读取的东西有区别于其他

void mtg_t_svrFrame::OnPaintMetroFig3(wxPaintEvent& event)
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
//        memDC.DrawLabel(wxString::Format(_("%d"),mtg->m1.iseg)+_(" 环"),wxRect(gx1,gy1,gw1,gh1),wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("米度测量"),wxRect(gx1,gy1,gw1,gh1),wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        int gx2,gy2,gw2,gh2;
        gx2=10*sx;
        gy2=60*sxy;
        gw2=w1-20*sx;
        gh2=h1-75*sxy;
        memDC.SetPen(wxPen(wxColor(140,144,147)));
        memDC.SetBrush(wxBrush(wxColor(212,218,224)));
        ///memDC.DrawRectangle(gx2,gy2,gw2,gh2);

        double per = mtg->snum.tm;
        int n=per/mtg->segset.L;
        if(ZHONGJIAOTIANHE==0)   ///20200602ws modify
            per=per-n*mtg->segset.L;
        if(per>mtg->segset.L*2.0) per=0.0;
        wxFont eng5(15*sxy,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(eng5);
        valstr=wxString::Format(_("%d"),(int)(per*1000.0));
        per = per/mtg->segset.L;
        if(per>1.0) per=1;
        memDC.SetPen(wxPen(wxColor(234,251,230)));
        memDC.SetBrush(wxBrush(wxColor(234,251,230)));
        gx2=gx2+1;
        gy2=gy2+1;
        gw2=gw2-2;
        gh2=gh2-2;
        ///memDC.DrawRectangle(gx2,gy2,gw2*per,gh2);
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

        if(mtg->incA_flag==1)
        {
            memDC.DrawLabel(_("后"),wxRect(x1-35*sxy,y1+35*sxy,w1,35*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("前"),wxRect(x1+35*sxy,y1+35*sxy,w1,35*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            memDC.SetFont(eng2);
            if(mtg->m1.inc1[0]>mtg->iset.aalw || mtg->m1.inc1[0]<-mtg->iset.aalw)
                memDC.SetTextForeground(wxColor(255,0,0));
            else
                memDC.SetTextForeground(wxColor(25,35,45));
            if(mtg->iset.vibration==0)
            {
                if(mtg->iset.unit==0)
                {
                    memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->m1.inc1[0]*PI/180.0)*1000.0),wxRect(x1+35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->m1.inc1[0]),wxRect(x1+35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
            else
            {
                if(mtg->iset.unit==0)
                {
                    memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->maj1.inc1[0]*PI/180.0)*1000.0),wxRect(x1+35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->maj1.inc1[0]),wxRect(x1+35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }

            ///撑紧盾滚动角
            if(mtg->iset.unit==0)
            {
                memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->m1.inc4[0]*PI/180.0)*1000.0),wxRect(x1-35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->m1.inc4[0]),wxRect(x1-35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
        }
        else{
            memDC.SetFont(eng2);
            if(mtg->m1.inc1[0]>mtg->iset.aalw || mtg->m1.inc1[0]<-mtg->iset.aalw)
                memDC.SetTextForeground(wxColor(255,0,0));
            else
                memDC.SetTextForeground(wxColor(25,35,45));
            if(mtg->iset.vibration==0)
            {
                if(mtg->iset.unit==0)
                {
                    memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->m1.inc1[0]*PI/180.0)*1000.0),wxRect(x1,y1+32*sxy,w1,h1-32*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->m1.inc1[0]),wxRect(x1,y1+32*sxy,w1,h1-32*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
            else
            {
                if(mtg->iset.unit==0)
                {
                    memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->maj1.inc1[0]*PI/180.0)*1000.0),wxRect(x1,y1+32*sxy,w1,h1-32*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->maj1.inc1[0]),wxRect(x1,y1+32*sxy,w1,h1-32*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
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

        if(mtg->incA_flag==1)
        {
            memDC.DrawLabel(_("后"),wxRect(x1-35*sxy,y1+35*sxy,w1,35*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("前"),wxRect(x1+35*sxy,y1+35*sxy,w1,35*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.SetFont(eng2);
            memDC.SetTextForeground(wxColor(25,35,45));
            if(mtg->iset.vibration==0)
            {
                if(mtg->iset.unit==0)
                {
                    memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->m1.inc1[1]*PI/180.0)*1000.0),wxRect(x1+35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->m1.inc1[1]),wxRect(x1+35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
            else
            {
                if(mtg->iset.unit==0)
                {
                    memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->maj1.inc1[1]*PI/180.0)*1000.0),wxRect(x1+35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->maj1.inc1[1]),wxRect(x1+35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }

             ///撑紧盾滚动角
            if(mtg->iset.unit==0)
            {
                memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->m1.inc4[1]*PI/180.0)*1000.0),wxRect(x1-35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->m1.inc4[1]),wxRect(x1-35*sxy,y1+45*sxy,w1,h1-45*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
        }
        else{
            memDC.SetFont(eng2);
            memDC.SetTextForeground(wxColor(25,35,45));
            if(mtg->iset.vibration==0)
            {
                if(mtg->iset.unit==0)
                {
                    memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->m1.inc1[1]*PI/180.0)*1000.0),wxRect(x1,y1+32*sxy,w1,h1-32*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->m1.inc1[1]),wxRect(x1,y1+32*sxy,w1,h1-32*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
            else
            {
                if(mtg->iset.unit==0)
                {
                    memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->maj1.inc1[1]*PI/180.0)*1000.0),wxRect(x1,y1+32*sxy,w1,h1-32*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->maj1.inc1[1]),wxRect(x1,y1+32*sxy,w1,h1-32*sxy),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
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

void mtg_t_svrFrame::OnPaintMetric(wxPaintEvent& event)
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

        if(time_tip>0)
        {
            int x1,y1,w1,h1;
            x1=w/3;
            y1=10;
            w1=w/2;
//            h1=h/2;
            wxFont chs1(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
            memDC.SetFont(chs1);
            memDC.SetTextForeground(wxColor(0,0,255));

            if(time_tip==1)
            {
                memDC.DrawLabel(wxString::Format(_("授权许可时间剩余%d天！"),remain_d),wxRect(x1,y1,w1,10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
            }
            else if(time_tip==2)
            {
                memDC.DrawLabel(wxString::Format(_("授权许可已到期！"),remain_d),wxRect(x1,y1,w1,10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_t_svrFrame::OnMotionSegment(wxMouseEvent& event)
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

void mtg_t_svrFrame::OnLeaveSegment(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    metroFig3->Refresh();
}

void mtg_t_svrFrame::SetSegment(wxMouseEvent& event)
{
    if(motion==ID_BTN_SEG)
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

void mtg_t_svrFrame::ViewJack(wxMouseEvent& event)
{
    //mtg_log(mtg,MTG_LOG_FINISH_CYCLE);

    //JackDlg dlg(this);
    //dlg.Center();
    //dlg.ShowModal();
}

///项目信息
void mtg_t_svrFrame::PaintBubble(wxMemoryDC* memDC, wxRect rect)
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
        dx=-mtg->m.comp[1]*scale;
        dy=-mtg->m.comp[0]*scale;
        inclix=-mtg->m.comp[1];
        incliy=-mtg->m.comp[0];
    }
    else//0.001100527对应角度3'47",徕卡全站仪倾角补偿范围待定
    {
        scale=1/0.001100527*rad*13/20;
        dx=mtg->m.comp[0]*scale;
        dy=mtg->m.comp[1]*scale;
        inclix=mtg->m.comp[0];
        incliy=mtg->m.comp[1];
    }

    //dx=mtg->m.comp[0]*scale;
    //dy=mtg->m.comp[1]*scale;

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

void mtg_t_svrFrame::OnPaintStatus(wxPaintEvent& event)
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
        //else
        //{
        //    PaintBattery(&memDC, wxRect(0,0,w,h));
        //}

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}


#ifdef WIN32
static DWORD WINAPI _listthread(void* arg)
#else
static void *_listthread(void *arg)
#endif
{
    if(logDlg)
    {
        logDlg->UpdateLogList();
    }
    mtg->logthread=0;

    return 0;
}

void mtg_t_svrFrame::UpdateLogList()
{
    if(mtg->logthread==0)
    {
    #ifdef WIN32
        if(!(mtg->logthread=CreateThread(NULL,0,_listthread,mtg,0,NULL)))
    #else
        if(pthread_create(&mtg->logthread,NULL,_listthread,mtg))
    #endif
        {
            return;
        }
    }
    return;
}

#include "trace.h"

#define IHI 0    ///20200713ws add 为了石川岛设备

//static time_t tlog=0;

void mtg_t_svrFrame::write_plc_roll()
{
    if((mtg->itbm>1 && mtg->iset.plctype==0) && (testP.type==0 || testP.type==6))
    {
        testP.units[write_plc_roll1_val].val_double = tan(mtg->m1.inc1[0]*PI/180.0)*1000.0;
        testP.units[write_plc_roll2_val].val_double = tan(mtg->m1.inc1[0]*PI/180.0)*1000.0;
        testP.units[write_plc_pitch1_val].val_double = tan(mtg->m1.inc4[1]*PI/180.0)*1000.0;
        testP.units[write_plc_pitch2_val].val_double = tan(mtg->m1.inc4[1]*PI/180.0)*1000.0;
        write_plc();
    }
    else if((mtg->itbm>1 && mtg->iset.plctype==0) &&testP.type==2)   ///施耐德
    {
        if(mtg->iset.unit==0)
        {
            testP.units[write_plc_roll1_val].val_long = (long)((tan(mtg->m1.inc1[0]/180*PI)*1000.0-testP.units[write_plc_roll1_val].val_add)/testP.units[write_plc_roll1_val].val_mul);
            testP.units[write_plc_roll1_val].val_double = (tan(mtg->m1.inc1[0]/180*PI)*1000.0-testP.units[write_plc_roll1_val].val_add)/testP.units[write_plc_roll1_val].val_mul;
            testP.units[write_plc_pitch1_val].val_long = (long)((tan(mtg->m1.inc1[1]/180*PI)*1000.0-testP.units[write_plc_pitch1_val].val_add)/testP.units[write_plc_pitch1_val].val_mul);
            testP.units[write_plc_pitch1_val].val_double = (tan(mtg->m1.inc1[1]/180*PI)*1000.0-testP.units[write_plc_pitch1_val].val_add)/testP.units[write_plc_pitch1_val].val_mul;

            testP.units[write_plc_roll2_val].val_long = (long)((tan(mtg->m1.inc4[0]/180*PI)*1000.0-testP.units[write_plc_roll2_val].val_add)/testP.units[write_plc_roll2_val].val_mul);
            testP.units[write_plc_roll2_val].val_double = (tan(mtg->m1.inc4[0]/180*PI)*1000.0-testP.units[write_plc_roll2_val].val_add)/testP.units[write_plc_roll2_val].val_mul;
            testP.units[write_plc_pitch2_val].val_long = (long)((tan(mtg->m1.inc4[1]/180*PI)*1000.0-testP.units[write_plc_pitch2_val].val_add)/testP.units[write_plc_pitch2_val].val_mul);
            testP.units[write_plc_pitch2_val].val_double = (tan(mtg->m1.inc4[1]/180*PI)*1000.0-testP.units[write_plc_pitch2_val].val_add)/testP.units[write_plc_pitch2_val].val_mul;
        }
        else{
            testP.units[write_plc_roll1_val].val_long = (long)((mtg->m1.inc1[0]-testP.units[write_plc_roll1_val].val_add)/testP.units[write_plc_roll1_val].val_mul);
            testP.units[write_plc_roll1_val].val_double = (mtg->m1.inc1[0]-testP.units[write_plc_roll1_val].val_add)/testP.units[write_plc_roll1_val].val_mul;
            testP.units[write_plc_pitch1_val].val_long = (long)((mtg->m1.inc1[1]-testP.units[write_plc_pitch1_val].val_add)/testP.units[write_plc_pitch1_val].val_mul);
            testP.units[write_plc_pitch1_val].val_double = (mtg->m1.inc1[1]-testP.units[write_plc_pitch1_val].val_add)/testP.units[write_plc_pitch1_val].val_mul;


            testP.units[write_plc_roll2_val].val_long = (long)((mtg->m1.inc4[0]-testP.units[write_plc_roll2_val].val_add)/testP.units[write_plc_roll2_val].val_mul);
            testP.units[write_plc_roll2_val].val_double = (mtg->m1.inc4[0]-testP.units[write_plc_roll2_val].val_add)/testP.units[write_plc_roll2_val].val_mul;
            testP.units[write_plc_pitch2_val].val_long = (long)((mtg->m1.inc4[1]-testP.units[write_plc_pitch2_val].val_add)/testP.units[write_plc_pitch2_val].val_mul);
            testP.units[write_plc_pitch2_val].val_double = (mtg->m1.inc4[1]-testP.units[write_plc_pitch2_val].val_add)/testP.units[write_plc_pitch2_val].val_mul;
        }
        write_plc();
    }

}


///timer
void mtg_t_svrFrame::OnTimer(wxTimerEvent& event)
{
    ///日志
    static int tick=0;
    int ico=0;
    int i=0;
    char msg[4096];
    static char s[1024];
    static int nlog=0;
    static MTG_LOG logs[20];
    char logmsg[4096];
    int drv=0;
    int asb=0;
    static int multiple=0;
    static double remain=0.0;
    static int left=0;
    static double right=0;
    static double per=0.0;
    static int num=0;
    static double avraj=0.0;
    static int value=0;

    int id1,id2;

    int nmoff;
    m_offset *mo={0};
    double val=0;
    int nn=0;
    //double headc=0,midc=0,tailc=0,mile1=0;
    double mile1=0;
    int indexlog=0;
    time_t t;
    time_t t1;
    char path[1024]={0};
	char strFull[1024]={0};
	static FILE* fpmeas=0;
	char filemeas[1024]={0};
	int n=0;
	double advance=0.0;
    wxArrayString files;
    wxString token=wxT("*.prj");
    wxString dirstr=_("D://database//");
    time_t tinc;
    time_t now_t;
    static int amode=0;
    static int drive=0;
    int write_roll_plc=0;

    if(IsChangeConnectPlcWay)
    {
        tick=0;
        return;
    }

    time(&t);

    nlog=mtg_peek_log(mtg,logs,20);
    if(nlog > 0)
    {
        wxString strLog;
        for(i=0;i<nlog;i++)
        {
            sprintf(logmsg,"%%R1D,51:%d\n",logs[i].nlog);
            if(logs[i].nlog>=0) RadioMsg(logmsg);
            else panelMode->Refresh();
            ico=logs[i].type;

            int size=listlog->GetItemCount();
            if(size>=200)
            {
                listlog->DeleteAllItems();
                size=0;
            }
            long index=listlog->InsertItem(size,ico);
            if(ico==1)
            {
                listlog->SetItemTextColour(index,wxColor(255,0,0));
            }
            else
            {
                listlog->SetItemTextColour(index,wxColor(0,0,0));
            }
            listlog->SetItem(index,1,wxDateTime(logs[i].t).Format(_("%Y-%m-%d %H:%M:%S")));
            strLog = wxString(logs[i].msg,wxConvLocal);
            listlog->SetItem(index,2,strLog);
            listlog->EnsureVisible(index);

            switch(logs[i].nlog)
            {
                case MTG_LOG_FINISH_START_LASER:
                {
                    tpsDirection=1;
                    tickAnimation=0;
                    drawAnimation=true;
                    if(testP.type==5)  //软plc
                        mtg_read_faj(mtg);
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
                    //mtg->istn.backx1=mtg->backmeas[0];
                    //mtg->istn.backy1=mtg->backmeas[1];
                    //mtg->istn.backz1=mtg->backmeas[2];
                    break;
                }
                case MTG_LOG_FINISH_SET_ORIENTATION:
                {
                    //20180115whq解除下面两句的注释,20180125whq再次注释，原因是在MySetupDlg.cpp中已执行下面的语句
                    //time(&mtg->istn.t);
                    //mtg_store_station(mtg);

                    if(mtg->istat.x!=mtg->istn.statx ||
                       mtg->istat.y!=mtg->istn.staty ||
                       mtg->istat.z!=mtg->istn.statz ||
                       mtg->iback.x!=mtg->istn.backx ||
                       mtg->iback.y!=mtg->istn.backy ||
                       mtg->iback.z!=mtg->istn.backz) mtg->ierr[9]=1;
                       else mtg->ierr[9]=0;

                    GetError();
                    panelMode->Refresh();

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
                    RadioData(15);
                    panelBar->Refresh();
                    panelMetric->Refresh();
                    GetMetro();
                    GetTips();
                    write_roll_plc=1;

                    ///20181207 whq add for segement software
                    //WriteSeg();

                    sqlite_export_meas(mtg,mtg->sqlitepath);
                    if(mtg->itbm>1)
                        sqlite_export_plc(mtg,mtg->sqlitepath);

                    if((mtg->itbm>1 && mtg->iset.plctype==0) && (testP.type==0 || testP.type==6))    ///西门子 或者ab 20210110 ws modify
                    {
                        testP.units[write_plc_roll1_val].val_double = tan(mtg->m1.inc1[0]*PI/180.0)*1000.0;
                        testP.units[write_plc_roll2_val].val_double = tan(mtg->m1.inc1[0]*PI/180.0)*1000.0;
                        testP.units[write_plc_pitch1_val].val_double = tan(mtg->m1.inc4[1]*PI/180.0)*1000.0;
                        testP.units[write_plc_pitch2_val].val_double = tan(mtg->m1.inc4[1]*PI/180.0)*1000.0;
                        if(mtg->tbm.type<2)
                        {
                            testP.units[write_plc_mile1_val].val_double = headc;
                            testP.units[write_plc_mile2_val].val_double = midc;
                            testP.units[write_plc_mile3_val].val_double = tailc;
                            testP.units[write_plc_headh_val].val_double = headh;
                            testP.units[write_plc_headv_val].val_double = headv;
                            testP.units[write_plc_midh_val].val_double = midh;
                            testP.units[write_plc_midv_val].val_double = midv;
                            testP.units[write_plc_tailh_val].val_double = tailh;
                            testP.units[write_plc_tailv_val].val_double = tailv;
                            if(mtg->tbm.type==0)
                            {
                                testP.units[write_plc_direct1_val].val_double = htrend;
                                testP.units[write_plc_direct2_val].val_double = vtrend;
                                testP.units[write_plc_direct3_val].val_double = 0.0;
                                testP.units[write_plc_direct4_val].val_double = 0.0;
                                testP.units[write_plc_headx_val].val_double = head[0];
                                testP.units[write_plc_heady_val].val_double = head[1];
                                testP.units[write_plc_headz_val].val_double = head[2];
                                testP.units[write_plc_tailx_val].val_double = tail[0];
                                testP.units[write_plc_taily_val].val_double = tail[1];
                                testP.units[write_plc_tailz_val].val_double = tail[2];
                                testP.units[write_plc_midx_val].val_double = 0.0;
                                testP.units[write_plc_midy_val].val_double = 0.0;
                                testP.units[write_plc_midz_val].val_double = 0.0;
                            }
                            else
                            {
                                testP.units[write_plc_direct1_val].val_double = htrend;
                                testP.units[write_plc_direct2_val].val_double = vtrend;
                                testP.units[write_plc_direct3_val].val_double = (mtg->m1.tailh-mtg->m1.tailh2)*1000.0/fabs(mtg->m1.tailc-mtg->m1.tailc2);
                                testP.units[write_plc_direct4_val].val_double = (mtg->m1.tailv-mtg->m1.tailv2)*1000.0/fabs(mtg->m1.tailc-mtg->m1.tailc2);
                                testP.units[write_plc_headx_val].val_double = head[0];
                                testP.units[write_plc_heady_val].val_double = head[1];
                                testP.units[write_plc_headz_val].val_double = head[2];
                                testP.units[write_plc_midx_val].val_double = mid[0];
                                testP.units[write_plc_midy_val].val_double = mid[1];
                                testP.units[write_plc_midz_val].val_double = mid[2];
                                testP.units[write_plc_tailx_val].val_double = tail[0];
                                testP.units[write_plc_taily_val].val_double = tail[1];
                                testP.units[write_plc_tailz_val].val_double = tail[2];

                            }
                        }
                        else if(mtg->tbm.type==2)
                        {
                            if(mtg->tarset.pos==0)
                            {
                                testP.units[write_plc_mile1_val].val_double = headc;
                                testP.units[write_plc_mile2_val].val_double = midc;
                                testP.units[write_plc_mile3_val].val_double = tailc;
                                testP.units[write_plc_headh_val].val_double = headh;
                                testP.units[write_plc_headv_val].val_double = headv;
                                testP.units[write_plc_midh_val].val_double = midh;
                                testP.units[write_plc_midv_val].val_double = midv;
                                testP.units[write_plc_tailh_val].val_double = tailh;
                                testP.units[write_plc_tailv_val].val_double = tailv;
                                testP.units[write_plc_direct1_val].val_double = htrend;
                                testP.units[write_plc_direct2_val].val_double = vtrend;
                                testP.units[write_plc_direct3_val].val_double = (mtg->m1.tailh-mtg->m1.tailh2)*1000.0/fabs(mtg->m1.tailc-mtg->m1.tailc2);
                                testP.units[write_plc_direct4_val].val_double = (mtg->m1.tailv-mtg->m1.tailv2)*1000.0/fabs(mtg->m1.tailc-mtg->m1.tailc2);
                                testP.units[write_plc_headx_val].val_double = head[0];
                                testP.units[write_plc_heady_val].val_double = head[1];
                                testP.units[write_plc_headz_val].val_double = head[2];
                                testP.units[write_plc_midx_val].val_double = mid[0];
                                testP.units[write_plc_midy_val].val_double = mid[1];
                                testP.units[write_plc_midz_val].val_double = mid[2];
                                testP.units[write_plc_tailx_val].val_double = tail[0];
                                testP.units[write_plc_taily_val].val_double = tail[1];
                                testP.units[write_plc_tailz_val].val_double = tail[2];
                            }
                            else
                            {
                                testP.units[write_plc_mile1_val].val_double = headc;
                                testP.units[write_plc_mile2_val].val_double = midc;
                                testP.units[write_plc_mile3_val].val_double = tailc;
                                testP.units[write_plc_headh_val].val_double = headh;
                                testP.units[write_plc_headv_val].val_double = headv;
                                testP.units[write_plc_midh_val].val_double = midh;
                                testP.units[write_plc_midv_val].val_double = midv;
                                testP.units[write_plc_tailh_val].val_double = tailh;
                                testP.units[write_plc_tailv_val].val_double = tailv;
                                testP.units[write_plc_direct1_val].val_double = htrend;
                                testP.units[write_plc_direct2_val].val_double = vtrend;
                                testP.units[write_plc_direct3_val].val_double = (mtg->m1.headh-mtg->m1.tailh)*1000.0/fabs(mtg->m1.headc-mtg->m1.tailc);
                                testP.units[write_plc_direct4_val].val_double = (mtg->m1.headv-mtg->m1.tailv)*1000.0/fabs(mtg->m1.headc-mtg->m1.tailc);
                                testP.units[write_plc_headx_val].val_double = head[0];
                                testP.units[write_plc_heady_val].val_double = head[1];
                                testP.units[write_plc_headz_val].val_double = head[2];
                                testP.units[write_plc_midx_val].val_double = mid[0];
                                testP.units[write_plc_midy_val].val_double = mid[1];
                                testP.units[write_plc_midz_val].val_double = mid[2];
                                testP.units[write_plc_tailx_val].val_double = tail[0];
                                testP.units[write_plc_taily_val].val_double = tail[1];
                                testP.units[write_plc_tailz_val].val_double = tail[2];
                            }
                        }

                        testP.units[write_plc_segmile1_val].val_double = 0.0;
                        testP.units[write_plc_segmile2_val].val_double = 0.0;
                        testP.units[write_plc_segmile3_val].val_double = 0.0;

                        testP.units[write_plc_segx_val].val_double = 0.0;
                        testP.units[write_plc_segy_val].val_double = 0.0;
                        testP.units[write_plc_segz_val].val_double = 0.0;
                        testP.units[write_plc_segk_val].val_double = 0.0;

                        testP.units[write_plc_ugap_val].val_double = 0.0;
                        testP.units[write_plc_dgap_val].val_double = 0.0;
                        testP.units[write_plc_lgap_val].val_double = 0.0;
                        testP.units[write_plc_rgap_val].val_double = 0.0;
                        testP.units[write_plc_numb1_val].val_double = mtg->m1.iseg;

                        for(int j=write_plc_pitch1_val;j<=write_plc_slum_val;j++)
                        {
                            testP.units[j].val_long=(long)testP.units[j].val_double;
                            testP.units[j].val_int=(int)testP.units[j].val_double;
                        }

                        write_plc();
                        //wxMessageBox(_("1"));
                    }
                    else if((mtg->itbm>1 && mtg->iset.plctype==0) &&testP.type==1)   ///三菱
                    {
                        ///20171130whq修改，原因是部分变量的定义已被更改，修改完用在西安六局的项目
                        testP.units[Mit_write_plc_direct1_val].val_int=(int)(htrend/testP.units[Mit_write_plc_direct1_val].val_mul-testP.units[Mit_write_plc_direct1_val].val_add);
                        testP.units[Mit_write_plc_direct2_val].val_int=(int)(vtrend/testP.units[Mit_write_plc_direct2_val].val_mul-testP.units[Mit_write_plc_direct2_val].val_add);
                        testP.units[Mit_write_plc_midh_val].val_int = (int)(midh/testP.units[Mit_write_plc_midh_val].val_mul-testP.units[Mit_write_plc_midh_val].val_add);
                        testP.units[Mit_write_plc_midv_val].val_int = (int)(midv/testP.units[Mit_write_plc_midv_val].val_mul-testP.units[Mit_write_plc_midv_val].val_add);

                        testP.units[Mit_write_plc_seg_val].val_int = mtg->m1.iseg;
                        testP.units[Mit_write_plc_seg_val].val_long = (long)mtg->m1.iseg;

                        mile1=headc;
                        testP.units[Mit_write_plc_mile1_val].val_int = (int)(mile1/4000.0);
                        testP.units[Mit_write_plc_mile2_val].val_int = (int)((int)mile1%4000);
                        testP.units[Mit_write_plc_mile3_val].val_int = (int)((mile1-(int)mile1)*1000.0);

                        testP.units[Mit_write_plc_headh_val].val_int = (int)(headh/testP.units[Mit_write_plc_headh_val].val_mul-testP.units[Mit_write_plc_headh_val].val_add);
                        testP.units[Mit_write_plc_headv_val].val_int = (int)(headv/testP.units[Mit_write_plc_headv_val].val_mul-testP.units[Mit_write_plc_headv_val].val_add);

                        testP.units[Mit_write_plc_tailh_val].val_int = (int)(tailh/testP.units[Mit_write_plc_tailh_val].val_mul-testP.units[Mit_write_plc_tailh_val].val_add);
                        testP.units[Mit_write_plc_tailv_val].val_int = (int)(tailv/testP.units[Mit_write_plc_tailh_val].val_mul-testP.units[Mit_write_plc_tailh_val].val_add);

                        //testP.units[Mit_write_plc_roll_val].val_int = (int)(tan(mtg->m1.inc1[0])*1000.0);
                        //testP.units[Mit_write_plc_pitch_val].val_int = (int)(tan(mtg->m1.inc1[1])*1000.0);
                        testP.units[Mit_write_plc_roll_val].val_int = (int)(tan(mtg->m1.inc1[0]/180*PI)*1000.0/testP.units[Mit_write_plc_roll_val].val_mul-testP.units[Mit_write_plc_roll_val].val_add);
                        testP.units[Mit_write_plc_pitch_val].val_int = (int)(tan(mtg->m1.inc1[1]/180*PI)*1000.0/testP.units[Mit_write_plc_pitch_val].val_mul-testP.units[Mit_write_plc_pitch_val].val_add);

                        double per = mtg->snum.tm;
                        int n=per/mtg->segset.L;
                        per=per-n*mtg->segset.L;
                        if(per>mtg->segset.L*2.0) per=0.0;
                        testP.units[Mit_write_plc_seg_part_val].val_int = (int)(per*1000.0);

                        if(ZHONGJIAOTIANHE && IHI==0)    ///20200331ws add 中交天和额外需要写的地址
                        {
                            testP.units[Mit_write_plc_roll_val].val_int = (int)(mtg->m1.inc1[0]/testP.units[Mit_write_plc_roll_val].val_mul-testP.units[Mit_write_plc_roll_val].val_add);
                            testP.units[Mit_write_plc_pitch_val].val_int = (int)(mtg->m1.inc1[1]/testP.units[Mit_write_plc_pitch_val].val_mul-testP.units[Mit_write_plc_pitch_val].val_add);

                            left=(int)mtg->m1.inc1[2];
                            testP.units[Mit_write_plc_azimuth1_val].val_int=(int)(left/testP.units[Mit_write_plc_azimuth1_val].val_mul-testP.units[Mit_write_plc_azimuth1_val].val_add);
                            right=mtg->m1.inc1[2]-(int)mtg->m1.inc1[2];
                            right*=1000.0;
                            testP.units[Mit_write_plc_azimuth2_val].val_int=(int)(right/testP.units[Mit_write_plc_azimuth2_val].val_mul-testP.units[Mit_write_plc_azimuth2_val].val_add);

                            mtg->azidesign=mtg->azidesign*180.0/PI;
                            left=(int)(mtg->azidesign);
                            testP.units[Mit_write_plc_azimuth3_val].val_int=(int)(left/testP.units[Mit_write_plc_azimuth3_val].val_mul-testP.units[Mit_write_plc_azimuth3_val].val_add);
                            right=mtg->azidesign-(int)mtg->azidesign;
                            right*=1000.0;
                            testP.units[Mit_write_plc_azimuth4_val].val_int=(int)(right/testP.units[Mit_write_plc_azimuth4_val].val_mul-testP.units[Mit_write_plc_azimuth4_val].val_add);

                            left=(int)(per*1000.0);
                            testP.units[Mit_write_plc_seg_part_val].val_int = left;
                            right=per-(int)per;
                            right*=1000.0;
                            testP.units[Mit_write_plc_seg_part2_val].val_int = (int)right;
                        }
                        write_plc();
                        //wxMessageBox(wxString::Format(_("write:%d"),testP.write_plc_complete));
                    }
                    else if((mtg->itbm>1 && mtg->iset.plctype==0) &&testP.type==2)   ///施耐德
                    {
                        if(mtg->iset.unit==0)
                        {
                            testP.units[write_plc_roll1_val].val_long = (long)((tan(mtg->m1.inc1[0]/180*PI)*1000.0-testP.units[write_plc_roll1_val].val_add)/testP.units[write_plc_roll1_val].val_mul);
                            testP.units[write_plc_roll1_val].val_double = (tan(mtg->m1.inc1[0]/180*PI)*1000.0-testP.units[write_plc_roll1_val].val_add)/testP.units[write_plc_roll1_val].val_mul;
                            testP.units[write_plc_pitch1_val].val_long = (long)((tan(mtg->m1.inc1[1]/180*PI)*1000.0-testP.units[write_plc_pitch1_val].val_add)/testP.units[write_plc_pitch1_val].val_mul);
                            testP.units[write_plc_pitch1_val].val_double = (tan(mtg->m1.inc1[1]/180*PI)*1000.0-testP.units[write_plc_pitch1_val].val_add)/testP.units[write_plc_pitch1_val].val_mul;

                            testP.units[write_plc_roll2_val].val_long = (long)((tan(mtg->m1.inc4[0]/180*PI)*1000.0-testP.units[write_plc_roll2_val].val_add)/testP.units[write_plc_roll2_val].val_mul);
                            testP.units[write_plc_roll2_val].val_double = (tan(mtg->m1.inc4[0]/180*PI)*1000.0-testP.units[write_plc_roll2_val].val_add)/testP.units[write_plc_roll2_val].val_mul;
                            testP.units[write_plc_pitch2_val].val_long = (long)((tan(mtg->m1.inc4[1]/180*PI)*1000.0-testP.units[write_plc_pitch2_val].val_add)/testP.units[write_plc_pitch2_val].val_mul);
                            testP.units[write_plc_pitch2_val].val_double = (tan(mtg->m1.inc4[1]/180*PI)*1000.0-testP.units[write_plc_pitch2_val].val_add)/testP.units[write_plc_pitch2_val].val_mul;
                        }
                        else{
                            testP.units[write_plc_roll1_val].val_long = (long)((mtg->m1.inc1[0]-testP.units[write_plc_roll1_val].val_add)/testP.units[write_plc_roll1_val].val_mul);
                            testP.units[write_plc_roll1_val].val_double = (mtg->m1.inc1[0]-testP.units[write_plc_roll1_val].val_add)/testP.units[write_plc_roll1_val].val_mul;
                            testP.units[write_plc_pitch1_val].val_long = (long)((mtg->m1.inc1[1]-testP.units[write_plc_pitch1_val].val_add)/testP.units[write_plc_pitch1_val].val_mul);
                            testP.units[write_plc_pitch1_val].val_double = (mtg->m1.inc1[1]-testP.units[write_plc_pitch1_val].val_add)/testP.units[write_plc_pitch1_val].val_mul;


                            testP.units[write_plc_roll2_val].val_long = (long)((mtg->m1.inc4[0]-testP.units[write_plc_roll2_val].val_add)/testP.units[write_plc_roll2_val].val_mul);
                            testP.units[write_plc_roll2_val].val_double = (mtg->m1.inc4[0]-testP.units[write_plc_roll2_val].val_add)/testP.units[write_plc_roll2_val].val_mul;
                            testP.units[write_plc_pitch2_val].val_long = (long)((mtg->m1.inc4[1]-testP.units[write_plc_pitch2_val].val_add)/testP.units[write_plc_pitch2_val].val_mul);
                            testP.units[write_plc_pitch2_val].val_double = (mtg->m1.inc4[1]-testP.units[write_plc_pitch2_val].val_add)/testP.units[write_plc_pitch2_val].val_mul;
                        }

                        testP.units[write_plc_mile1_val].val_long = (long)(headc-testP.units[write_plc_head_mile].val_add)/testP.units[write_plc_head_mile].val_mul;
                        testP.units[write_plc_mile1_val].val_double = (headc-testP.units[write_plc_head_mile].val_add)/testP.units[write_plc_head_mile].val_mul;
                        testP.units[write_plc_numb1_val].val_long = (long)(mtg->m1.iseg-testP.units[write_plc_seg_num].val_add)/testP.units[write_plc_seg_num].val_mul;
                        testP.units[write_plc_numb1_val].val_int = (mtg->m1.iseg-testP.units[write_plc_seg_num].val_add)/testP.units[write_plc_seg_num].val_mul;
                        testP.units[write_plc_numb1_val].val_double = (mtg->m1.iseg-testP.units[write_plc_seg_num].val_add)/testP.units[write_plc_seg_num].val_mul;
                        testP.units[write_plc_numb1_val].val_long=testP.units[write_plc_numb1_val].val_int;

                        testP.units[write_plc_headh_val].val_long = (long)(headh-testP.units[write_plc_head_hoff].val_add)/testP.units[write_plc_head_hoff].val_mul;
                        testP.units[write_plc_headh_val].val_double = (headh-testP.units[write_plc_head_hoff].val_add)/testP.units[write_plc_head_hoff].val_mul;
                        testP.units[write_plc_midh_val].val_long = (long)(midh-testP.units[write_plc_mid_hoff].val_add)/testP.units[write_plc_mid_hoff].val_mul;
                        testP.units[write_plc_midh_val].val_double = (midh-testP.units[write_plc_mid_hoff].val_add)/testP.units[write_plc_mid_hoff].val_mul;
                        testP.units[write_plc_tailh_val].val_long = (long)(tailh-testP.units[write_plc_tail_hoff].val_add)/testP.units[write_plc_tail_hoff].val_mul;
                        testP.units[write_plc_tailh_val].val_double = (tailh-testP.units[write_plc_tail_hoff].val_add)/testP.units[write_plc_tail_hoff].val_mul;
                        testP.units[write_plc_headv_val].val_long = (long)(headv-testP.units[write_plc_head_voff].val_add)/testP.units[write_plc_head_voff].val_mul;
                        testP.units[write_plc_headv_val].val_double = (headv-testP.units[write_plc_head_voff].val_add)/testP.units[write_plc_head_voff].val_mul;
                        testP.units[write_plc_midv_val].val_long = (long)(midv-testP.units[write_plc_mid_voff].val_add)/testP.units[write_plc_mid_voff].val_mul;
                        testP.units[write_plc_midv_val].val_double = (midv-testP.units[write_plc_mid_voff].val_add)/testP.units[write_plc_mid_voff].val_mul;
                        testP.units[write_plc_tailv_val].val_long = (long)(tailv-testP.units[write_plc_tail_voff].val_add)/testP.units[write_plc_tail_voff].val_mul;
                        testP.units[write_plc_tailv_val].val_double = (tailv-testP.units[write_plc_tail_voff].val_add)/testP.units[write_plc_tail_voff].val_mul;
                        testP.units[write_plc_direct1_val].val_long = (long)(htrend-testP.units[write_plc_fore_directh].val_add)/testP.units[write_plc_fore_directh].val_mul;
                        testP.units[write_plc_direct1_val].val_double = (htrend-testP.units[write_plc_fore_directh].val_add)/testP.units[write_plc_fore_directh].val_mul;
                        testP.units[write_plc_direct2_val].val_long = (long)(vtrend-testP.units[write_plc_fore_directv].val_add)/testP.units[write_plc_fore_directv].val_mul;
                        testP.units[write_plc_direct2_val].val_double = (vtrend-testP.units[write_plc_fore_directv].val_add)/testP.units[write_plc_fore_directv].val_mul;
                        testP.units[write_plc_direct3_val].val_long = (long)(htrend2-testP.units[write_plc_back_directh].val_add)/testP.units[write_plc_back_directh].val_mul;
                        testP.units[write_plc_direct3_val].val_double = (htrend2-testP.units[write_plc_back_directh].val_add)/testP.units[write_plc_back_directh].val_mul;
                        testP.units[write_plc_direct4_val].val_long = (long)(vtrend2-testP.units[write_plc_back_directv].val_add)/testP.units[write_plc_back_directv].val_mul;
                        testP.units[write_plc_direct4_val].val_double = (vtrend2-testP.units[write_plc_back_directv].val_add)/testP.units[write_plc_back_directv].val_mul;

                        testP.units[write_plc_roll_val].val_long = (long)((tan(mtg->m1.inc1[0]/180*PI)*1000.0-testP.units[write_plc_roll_val].val_add)/testP.units[write_plc_roll_val].val_mul);
                        testP.units[write_plc_roll_val].val_double = (tan(mtg->m1.inc1[0]/180*PI)*1000.0-testP.units[write_plc_roll_val].val_add)/testP.units[write_plc_roll_val].val_mul;
                        testP.units[write_plc_pitch_val].val_long = (long)((tan(mtg->m1.inc1[1]/180*PI)*1000.0-testP.units[write_plc_pitch_val].val_add)/testP.units[write_plc_pitch_val].val_mul);
                        testP.units[write_plc_pitch_val].val_double = (tan(mtg->m1.inc1[1]/180*PI)*1000.0-testP.units[write_plc_pitch_val].val_add)/testP.units[write_plc_pitch_val].val_mul;
                        testP.units[write_plc_head_mile].val_long = (long)(headc-testP.units[write_plc_head_mile].val_add)/testP.units[write_plc_head_mile].val_mul;
                        testP.units[write_plc_head_mile].val_double = (headc-testP.units[write_plc_head_mile].val_add)/testP.units[write_plc_head_mile].val_mul;
                        testP.units[write_plc_seg_num].val_long = (long)(mtg->m1.iseg-testP.units[write_plc_seg_num].val_add)/testP.units[write_plc_seg_num].val_mul;
                        testP.units[write_plc_seg_num].val_int = (mtg->m1.iseg-testP.units[write_plc_seg_num].val_add)/testP.units[write_plc_seg_num].val_mul;
                        testP.units[write_plc_head_hoff].val_long = (long)(headh-testP.units[write_plc_head_hoff].val_add)/testP.units[write_plc_head_hoff].val_mul;
                        testP.units[write_plc_head_hoff].val_double = (headh-testP.units[write_plc_head_hoff].val_add)/testP.units[write_plc_head_hoff].val_mul;
                        testP.units[write_plc_mid_hoff].val_long = (long)(midh-testP.units[write_plc_mid_hoff].val_add)/testP.units[write_plc_mid_hoff].val_mul;
                        testP.units[write_plc_mid_hoff].val_double = (midh-testP.units[write_plc_mid_hoff].val_add)/testP.units[write_plc_mid_hoff].val_mul;
                        testP.units[write_plc_tail_hoff].val_long = (long)(tailh-testP.units[write_plc_tail_hoff].val_add)/testP.units[write_plc_tail_hoff].val_mul;
                        testP.units[write_plc_tail_hoff].val_double = (tailh-testP.units[write_plc_tail_hoff].val_add)/testP.units[write_plc_tail_hoff].val_mul;
                        testP.units[write_plc_head_voff].val_long = (long)(headv-testP.units[write_plc_head_voff].val_add)/testP.units[write_plc_head_voff].val_mul;
                        testP.units[write_plc_head_voff].val_double = (headv-testP.units[write_plc_head_voff].val_add)/testP.units[write_plc_head_voff].val_mul;
                        testP.units[write_plc_mid_voff].val_long = (long)(midv-testP.units[write_plc_mid_voff].val_add)/testP.units[write_plc_mid_voff].val_mul;
                        testP.units[write_plc_mid_voff].val_double = (midv-testP.units[write_plc_mid_voff].val_add)/testP.units[write_plc_mid_voff].val_mul;
                        testP.units[write_plc_tail_voff].val_long = (long)(tailv-testP.units[write_plc_tail_voff].val_add)/testP.units[write_plc_tail_voff].val_mul;
                        testP.units[write_plc_tail_voff].val_double = (tailv-testP.units[write_plc_tail_voff].val_add)/testP.units[write_plc_tail_voff].val_mul;
                        testP.units[write_plc_fore_directh].val_long = (long)(htrend-testP.units[write_plc_fore_directh].val_add)/testP.units[write_plc_fore_directh].val_mul;
                        testP.units[write_plc_fore_directh].val_double = (htrend-testP.units[write_plc_fore_directh].val_add)/testP.units[write_plc_fore_directh].val_mul;
                        testP.units[write_plc_fore_directv].val_long = (long)(vtrend-testP.units[write_plc_fore_directv].val_add)/testP.units[write_plc_fore_directv].val_mul;
                        testP.units[write_plc_fore_directv].val_double = (vtrend-testP.units[write_plc_fore_directv].val_add)/testP.units[write_plc_fore_directv].val_mul;
                        testP.units[write_plc_back_directh].val_long = (long)(htrend2-testP.units[write_plc_back_directh].val_add)/testP.units[write_plc_back_directh].val_mul;
                        testP.units[write_plc_back_directh].val_double = (htrend2-testP.units[write_plc_back_directh].val_add)/testP.units[write_plc_back_directh].val_mul;
                        testP.units[write_plc_back_directv].val_long = (long)(vtrend2-testP.units[write_plc_back_directv].val_add)/testP.units[write_plc_back_directv].val_mul;
                        testP.units[write_plc_back_directv].val_double = (vtrend2-testP.units[write_plc_back_directv].val_add)/testP.units[write_plc_back_directv].val_mul;
                        write_plc();
                    }
                    else if(mtg->itbm>1 && mtg->iset.plctype==1)   ///web plc   20200825ws add
                    {
                        testW.units[write_plc_roll1_val].val_double=tan(mtg->m1.inc1[0]*PI/180.0)*1000.0;
                        testW.units[write_plc_pitch1_val].val_double = tan(mtg->m1.inc1[1]*PI/180.0)*1000.0;
                        testW.units[write_plc_mile1_val].val_double = headc;
                        testW.units[write_plc_headh_val].val_double = headh;
                        testW.units[write_plc_headv_val].val_double = headv;
                        testW.units[write_plc_midh_val].val_double = midh;
                        testW.units[write_plc_midv_val].val_double = midv;
                        testW.units[write_plc_tailh_val].val_double = tailh;
                        testW.units[write_plc_tailv_val].val_double = tailv;
                        testW.units[write_plc_direct1_val].val_double = htrend;
                        testW.units[write_plc_direct2_val].val_double = vtrend;
                        if(mtg->tbm.type==0)
                        {
                            testW.units[write_plc_headx_val].val_double = head[0];
                            testW.units[write_plc_heady_val].val_double = head[1];
                            testW.units[write_plc_headz_val].val_double = head[2];
                            testW.units[write_plc_tailx_val].val_double = tail[0];
                            testW.units[write_plc_taily_val].val_double = tail[1];
                            testW.units[write_plc_tailz_val].val_double = tail[2];
                            testW.units[write_plc_midx_val].val_double = 0.0;
                            testW.units[write_plc_midy_val].val_double = 0.0;
                            testW.units[write_plc_midz_val].val_double = 0.0;
                        }
                        else if(mtg->tbm.type==1)
                        {
                            testW.units[write_plc_headx_val].val_double = head[0];
                            testW.units[write_plc_heady_val].val_double = head[1];
                            testW.units[write_plc_headz_val].val_double = head[2];
                            testW.units[write_plc_midx_val].val_double = mid[0];
                            testW.units[write_plc_midy_val].val_double = mid[1];
                            testW.units[write_plc_midz_val].val_double = mid[2];
                            testW.units[write_plc_tailx_val].val_double = tail[0];
                            testW.units[write_plc_taily_val].val_double = tail[1];
                            testW.units[write_plc_tailz_val].val_double = tail[2];
                        }
                        else if(mtg->tbm.type==2)
                        {
                            testW.units[write_plc_headx_val].val_double = head[0];
                            testW.units[write_plc_heady_val].val_double = head[1];
                            testW.units[write_plc_headz_val].val_double = head[2];
                            testW.units[write_plc_midx_val].val_double = mid[0];
                            testW.units[write_plc_midy_val].val_double = mid[1];
                            testW.units[write_plc_midz_val].val_double = mid[2];
                            testW.units[write_plc_tailx_val].val_double = tail[0];
                            testW.units[write_plc_taily_val].val_double = tail[1];
                            testW.units[write_plc_tailz_val].val_double = tail[2];
                        }
                        testW.units[write_plc_numb1_val].val_int = mtg->m1.iseg;
                        ///write_tbm();
                    }
                    else
                    {
                        testP.units[write_plc_roll1_val].val_double = tan(mtg->m1.inc1[0]*PI/180.0)*1000.0;
                        testP.units[write_plc_roll2_val].val_double = tan(mtg->m1.inc1[0]*PI/180.0)*1000.0;
                        testP.units[write_plc_pitch1_val].val_double = tan(mtg->m1.inc1[1]*PI/180.0)*1000.0;
                        testP.units[write_plc_pitch2_val].val_double = tan(mtg->m1.inc1[1]*PI/180.0)*1000.0;
                        if(mtg->tbm.type<2)
                        {
                            testP.units[write_plc_mile1_val].val_double = headc;
                            testP.units[write_plc_mile2_val].val_double = midc;
                            testP.units[write_plc_mile3_val].val_double = tailc;
                            testP.units[write_plc_headh_val].val_double = headh;
                            testP.units[write_plc_headv_val].val_double = headv;
                            testP.units[write_plc_midh_val].val_double = midh;
                            testP.units[write_plc_midv_val].val_double = midv;
                            testP.units[write_plc_tailh_val].val_double = tailh;
                            testP.units[write_plc_tailv_val].val_double = tailv;
                            if(mtg->tbm.type==0)
                            {
                                testP.units[write_plc_direct1_val].val_double = htrend;
                                testP.units[write_plc_direct2_val].val_double = vtrend;
                                testP.units[write_plc_direct3_val].val_double = 0.0;
                                testP.units[write_plc_direct4_val].val_double = 0.0;
                                testP.units[write_plc_headx_val].val_double = head[0];
                                testP.units[write_plc_heady_val].val_double = head[1];
                                testP.units[write_plc_headz_val].val_double = head[2];
                                testP.units[write_plc_tailx_val].val_double = tail[0];
                                testP.units[write_plc_taily_val].val_double = tail[1];
                                testP.units[write_plc_tailz_val].val_double = tail[2];
                                testP.units[write_plc_midx_val].val_double = 0.0;
                                testP.units[write_plc_midy_val].val_double = 0.0;
                                testP.units[write_plc_midz_val].val_double = 0.0;
                            }
                            else
                            {
                                testP.units[write_plc_direct1_val].val_double = htrend;
                                testP.units[write_plc_direct2_val].val_double = vtrend;
                                testP.units[write_plc_direct3_val].val_double = (mtg->m1.tailh-mtg->m1.tailh2)*1000.0/fabs(mtg->m1.tailc-mtg->m1.tailc2);
                                testP.units[write_plc_direct4_val].val_double = (mtg->m1.tailv-mtg->m1.tailv2)*1000.0/fabs(mtg->m1.tailc-mtg->m1.tailc2);
                                testP.units[write_plc_headx_val].val_double = head[0];
                                testP.units[write_plc_heady_val].val_double = head[1];
                                testP.units[write_plc_headz_val].val_double = head[2];
                                testP.units[write_plc_midx_val].val_double = mid[0];
                                testP.units[write_plc_midy_val].val_double = mid[1];
                                testP.units[write_plc_midz_val].val_double = mid[2];
                                testP.units[write_plc_tailx_val].val_double = tail[0];
                                testP.units[write_plc_taily_val].val_double = tail[1];
                                testP.units[write_plc_tailz_val].val_double = tail[2];

                            }
                        }
                        else if(mtg->tbm.type==2)
                        {
                            if(mtg->tarset.pos==0)
                            {
                                testP.units[write_plc_mile1_val].val_double = headc;
                                testP.units[write_plc_mile2_val].val_double = midc;
                                testP.units[write_plc_mile3_val].val_double = tailc;
                                testP.units[write_plc_headh_val].val_double = headh;
                                testP.units[write_plc_headv_val].val_double = headv;
                                testP.units[write_plc_midh_val].val_double = midh;
                                testP.units[write_plc_midv_val].val_double = midv;
                                testP.units[write_plc_tailh_val].val_double = tailh;
                                testP.units[write_plc_tailv_val].val_double = tailv;
                                testP.units[write_plc_direct1_val].val_double = htrend;
                                testP.units[write_plc_direct2_val].val_double = vtrend;
                                testP.units[write_plc_direct3_val].val_double = (mtg->m1.tailh-mtg->m1.tailh2)*1000.0/fabs(mtg->m1.tailc-mtg->m1.tailc2);
                                testP.units[write_plc_direct4_val].val_double = (mtg->m1.tailv-mtg->m1.tailv2)*1000.0/fabs(mtg->m1.tailc-mtg->m1.tailc2);
                                testP.units[write_plc_headx_val].val_double = head[0];
                                testP.units[write_plc_heady_val].val_double = head[1];
                                testP.units[write_plc_headz_val].val_double = head[2];
                                testP.units[write_plc_midx_val].val_double = mid[0];
                                testP.units[write_plc_midy_val].val_double = mid[1];
                                testP.units[write_plc_midz_val].val_double = mid[2];
                                testP.units[write_plc_tailx_val].val_double = tail[0];
                                testP.units[write_plc_taily_val].val_double = tail[1];
                                testP.units[write_plc_tailz_val].val_double = tail[2];
                            }
                            else
                            {
                                testP.units[write_plc_mile1_val].val_double = headc;
                                testP.units[write_plc_mile2_val].val_double = midc;
                                testP.units[write_plc_mile3_val].val_double = tailc;
                                testP.units[write_plc_headh_val].val_double = headh;
                                testP.units[write_plc_headv_val].val_double = headv;
                                testP.units[write_plc_midh_val].val_double = midh;
                                testP.units[write_plc_midv_val].val_double = midv;
                                testP.units[write_plc_tailh_val].val_double = tailh;
                                testP.units[write_plc_tailv_val].val_double = tailv;
                                testP.units[write_plc_direct1_val].val_double = htrend;
                                testP.units[write_plc_direct2_val].val_double = vtrend;
                                testP.units[write_plc_direct3_val].val_double = (mtg->m1.headh-mtg->m1.tailh)*1000.0/fabs(mtg->m1.headc-mtg->m1.tailc);
                                testP.units[write_plc_direct4_val].val_double = (mtg->m1.headv-mtg->m1.tailv)*1000.0/fabs(mtg->m1.headc-mtg->m1.tailc);
                                testP.units[write_plc_headx_val].val_double = head[0];
                                testP.units[write_plc_heady_val].val_double = head[1];
                                testP.units[write_plc_headz_val].val_double = head[2];
                                testP.units[write_plc_midx_val].val_double = mid[0];
                                testP.units[write_plc_midy_val].val_double = mid[1];
                                testP.units[write_plc_midz_val].val_double = mid[2];
                                testP.units[write_plc_tailx_val].val_double = tail[0];
                                testP.units[write_plc_taily_val].val_double = tail[1];
                                testP.units[write_plc_tailz_val].val_double = tail[2];
                            }
                        }

                        testP.units[write_plc_segmile1_val].val_double = 0.0;
                        testP.units[write_plc_segmile2_val].val_double = 0.0;
                        testP.units[write_plc_segmile3_val].val_double = 0.0;

                        testP.units[write_plc_segx_val].val_double = 0.0;
                        testP.units[write_plc_segy_val].val_double = 0.0;
                        testP.units[write_plc_segz_val].val_double = 0.0;
                        testP.units[write_plc_segk_val].val_double = 0.0;

                        testP.units[write_plc_ugap_val].val_double = 0.0;
                        testP.units[write_plc_dgap_val].val_double = 0.0;
                        testP.units[write_plc_lgap_val].val_double = 0.0;
                        testP.units[write_plc_rgap_val].val_double = 0.0;

                        testP.units[write_plc_numb1_val].val_int = mtg->m1.iseg;
                        testP.units[write_plc_numb1_val].val_long = (long)mtg->m1.iseg;
                    }

                    fpmeas=fopen("D:\\midu\\mtg_meas.csv","w");
                    if(fpmeas)
                    {
                        if(testP.type==1 && mtg->iset.plctype==0)     ///ws20200822 add
                        {
                            fprintf(fpmeas,"水平趋势(mm/m),垂直趋势(mm/m),盾中水平偏差(mm),盾中垂直偏差(mm),环号,里程1,里程2,里程3,切口水平偏差(mm),切口垂直偏差(mm),盾尾水平偏差(mm),盾尾垂直偏差(mm),滚动角(mm/m),俯仰角(mm/m),当前环掘进距离(mm)\n");
                            fflush(fpmeas);
                            for(int k=0;k<=Mit_write_plc_pitch_val-Mit_write_plc_direct1_val;k++)
                            {
                                fprintf(fpmeas,"%d,",testP.units[k+Mit_write_plc_direct1_val].val_int);
                                fflush(fpmeas);
                            }
                            fprintf(fpmeas,"%d\n",testP.units[Mit_write_plc_seg_part_val].val_int);
                            fflush(fpmeas);
                        }
                        else if(testP.type==2 && mtg->iset.plctype==0)
                        {
                            fprintf(fpmeas,"滚动角,俯仰角,切口里程,环号,盾首水平偏差,盾中水平偏差,盾尾水平偏差,盾首垂直偏差,盾中垂直偏差,盾尾垂直偏差,前盾水平趋势,前盾垂直趋势,后盾水平趋势,后盾垂直趋势\n");
                            fflush(fpmeas);
                            for(int k=0;k<=write_plc_back_directv-write_plc_roll_val;k++)
                            {
                                if(k==3)
                                    fprintf(fpmeas,"%d,",testP.units[k+write_plc_roll_val].val_int);
                                else
                                    fprintf(fpmeas,"%d,",testP.units[k+write_plc_roll_val].val_double);
                                fflush(fpmeas);
                            }
                        }
                        else if(mtg->iset.plctype==1)     ///20200825ws add
                        {
                            fprintf(fpmeas,"前筒俯仰角(mm/m),前筒滚动角(mm/m),后筒俯仰角(mm/m),后筒滚动角(mm/m),切口里程,铰接里程,盾尾里程,切口平面偏差,切口垂直偏差,盾尾平面偏差,盾尾垂直偏差,铰接平面偏差,铰接垂直偏差,前筒水平趋势(mm/m),前筒垂直趋势(mm/m),后筒水平趋势(mm/m),后筒垂直趋势(mm/m),切口X坐标,切口Y坐标,切口Z坐标,铰接X坐标,铰接Y坐标,铰接Z坐标,盾尾X坐标,盾尾Y坐标,盾尾Z坐标,mile1,mile2,mile3,segh,segv,segy,segx,segz,segk,盾尾间隙上,盾尾间隙右,盾尾间隙下,盾尾间隙左,管片号\n");
                            for(int k=0;k<write_plc_numb1_val-write_plc_pitch1_val;k++)
                            {
                                fprintf(fpmeas,"%.4f,",testW.units[k+write_plc_pitch1_val].val_double);
                                fflush(fpmeas);
                            }
                            fprintf(fpmeas,"%d\n",testW.units[write_plc_numb1_val].val_int);
                            fflush(fpmeas);
                        }
                        else
                        {
                            fprintf(fpmeas,"前筒俯仰角(mm/m),前筒滚动角(mm/m),后筒俯仰角(mm/m),后筒滚动角(mm/m),切口里程,铰接里程,盾尾里程,切口平面偏差,切口垂直偏差,盾尾平面偏差,盾尾垂直偏差,铰接平面偏差,铰接垂直偏差,前筒水平趋势(mm/m),前筒垂直趋势(mm/m),后筒水平趋势(mm/m),后筒垂直趋势(mm/m),切口X坐标,切口Y坐标,切口Z坐标,铰接X坐标,铰接Y坐标,铰接Z坐标,盾尾X坐标,盾尾Y坐标,盾尾Z坐标,mile1,mile2,mile3,segh,segv,segy,segx,segz,segk,盾尾间隙上,盾尾间隙右,盾尾间隙下,盾尾间隙左,管片号\n");
                            for(int k=0;k<write_plc_numb1_val-write_plc_pitch1_val;k++)
                            {
                                fprintf(fpmeas,"%.4f,",testP.units[k+write_plc_pitch1_val].val_double);
                                fflush(fpmeas);
                            }
                            fprintf(fpmeas,"%d\n",testP.units[write_plc_numb1_val].val_int);
                            fflush(fpmeas);
                        }
                        fclose(fpmeas);
                        fpmeas=NULL;
                    }

                    if(mapDlg && mapDlg->OnUse==1) mapDlg->UpdateGraph();
                    //20180117whq增加，用于保存照片
                    SaveImage();
                    break;
                }
                case MTG_LOG_CANCEL_CYCLE:
                case MTG_LOG_FINISH_ORIGIN:
                case MTG_LOG_FAIL_ORIGIN:
                    //20180117whq增加用于保存照片
                    SaveImage();
                    break;
                case MTG_LOG_FINISH_GET_LOG:
                {
                    UpdateLogList();
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
        write_plc_roll();
        if(mtg->iset.plctype==0)
        {
            if(mtg->itbm>0 && testP.type!=5)
            {
                read_plc();
            }
        }
        else if(mtg->iset.plctype==1)   ///20200825ws add
        {
            if(mtg->itbm>0)
            {
                read_web();
            }
        }

        if(testP.type==1 && mtg->iset.plctype==0)///三菱PLC
        {
            if(testP.read_plc_complete==1)
            {
                if(mtg->itbm<2) mtg->itbm++;

                if(ZHONGJIAOTIANHE==0)
                {
                    if(testP.units[read_plc_mode_val].val_int&0x4000)
                    {
                        mtg->plc.amode=true;           ///拼装模式
                    }
                    else
                    {
                        mtg->plc.amode=false;           ///拼装模式
                    }
                    if(testP.units[read_plc_start_val].val_int&0x1000 )
                    {
                        mtg->plc.drive=true;           ///掘进开始
                        if(mtg->run==0 && mtg->iset.tsyn==0) mtg_start_cycle(mtg);
                    }
                    else
                    {
                        mtg->plc.drive=false;          ///掘进停止
                        if(mtg->iset.tsyn==0)
                        {
                            if(mtg->run==1 && !mtg->incycle) mtg_stop(mtg);
                        }
                        ///分析环号
                        if(mtg->plc.amode)
                        {
                            if(mtg->snum.tm>=mtg->segset.L-0.2 && mtg->iset.rget==0)///20180112whq增加了mtg->iset.rget==0的判断,表示根据PLC近似计算
                            {
                                ///20180112whq修改
                                multiple=(int)(mtg->snum.tm/mtg->segset.L);
                                mtg->snum.iseg+=multiple;
                                remain=mtg->snum.tm-mtg->segset.L*multiple;
                                if(remain>=mtg->segset.L-0.2)
                                    mtg->snum.iseg++;
                                ///20180112修改结束
                                mtg->snum.mile=mtg->m.headc;
                                mtg->snum.tm=0.0;
                                ///20180112whq取消下句的注释，以便界面立刻更新环号
                                mtg->m1.iseg=mtg->snum.iseg;
                                mtg_store_snum(mtg);
                                panelMetric->Refresh();
                                RadioData(17);
                            }
                        }
                    }
                }
                else if(ZHONGJIAOTIANHE==1)   ///20200602ws add 为了适应中交天和项目
                {
                    ///解析【掘进中】信号量值
                    fpmeas=fopen("D:\\midu\\mtg_special.log","w");
                    if(IHI==0)
                    {
                        if(fpmeas)
                        {
                            fprintf(fpmeas,"val_int=%d\n",testP.units[read_plc_start_val].val_int);
                            fflush(fpmeas);
                        }
                        value=testP.units[read_plc_start_val].val_int;
                        if(fpmeas)
                        {
                            fprintf(fpmeas,"value1=%d\n",value);
                            fflush(fpmeas);
                        }
                        value=value >> 4;
                        if(fpmeas)
                        {
                            fprintf(fpmeas,"value2=%d\n",value);
                            fflush(fpmeas);
                        }
                        if(value & 1 ==1)
                            ReadPlcStartVal=1;
                        else
                            ReadPlcStartVal=0;

                        if(fpmeas)
                        {
                            fprintf(fpmeas,"ReadPlcStartVal=%d\n",ReadPlcStartVal);
                            fflush(fpmeas);
                        }

                        if(testP.units[read_plc_mode_val].val_int==1)
                        {
                            mtg->plc.amode=true;           ///环片模式
                        }
                        else
                        {
                            mtg->plc.amode=false;           ///掘进模式
                        }
                    }
                    else if(IHI==1)
                    {
                        if(testP.units[read_plc_start_val].val_int==1)
                            ReadPlcStartVal=1;
                        else
                            ReadPlcStartVal=0;

                        if(fpmeas)
                        {
                            fprintf(fpmeas,"ReadPlcStartVal=%d\n",ReadPlcStartVal);
                            fflush(fpmeas);
                        }

                        if(testP.units[read_plc_mode_val].val_int==1)
                            mtg->plc.amode=true;
                        else
                            mtg->plc.amode=false;
                    }


                    if(ReadPlcStartVal==1)   ///[掘进中]信号打开才周期测量
                    {
                        mtg->plc.drive=true;
                        if(fpmeas)
                        {
                            fprintf(fpmeas,"drive=true\n");
                            fflush(fpmeas);
                        }

                        if(mtg->run==0 && mtg->iset.tsyn==0)
                            mtg_start_cycle(mtg);

                        if(avraj>MinAJLength && mtg->snum.tm<mtg->segset.L*LengthPercent)
                            SegDoing=1;
                    }
                    else
                    {
                        mtg->plc.drive=false;
                        if(fpmeas)
                        {
                            fprintf(fpmeas,"drive=false\n");
                            fflush(fpmeas);
                        }

                        if(mtg->iset.tsyn==0)
                        {
                            if(mtg->run==1 && !mtg->incycle)
                                mtg_stop(mtg);
                        }
                    }

                    avraj=(mtg->aj[0]+mtg->aj[1]+mtg->aj[2]+mtg->aj[3])/4.0;
                    if(fpmeas)
                    {
                        fprintf(fpmeas,"avraj=%.4f,MinAJLength=%.4f\n",avraj,MinAJLength);
                        fflush(fpmeas);
                        fprintf(fpmeas,"read_plc_mode_val_int=%d,SegStart=%d,SegEnd=%d\n",testP.units[read_plc_mode_val].val_int,SegStart,SegEnd);
                        fflush(fpmeas);
                        fprintf(fpmeas,"mtg->snum.tm=%.4f,mtg->segset.L=%.4f,LengthPercent=%.4f\n",mtg->snum.tm,mtg->segset.L,LengthPercent);
                        fflush(fpmeas);
                        fprintf(fpmeas,"SegDoing=%d\n",SegDoing);
                        fflush(fpmeas);
                    }
                    if(avraj<MinAJLength && ReadPlcStartVal==1 && testP.units[read_plc_mode_val].val_int==0 && SegStart==0)   ///一环开始
                    {
                        if(fpmeas)
                        {
                            fprintf(fpmeas,"一环开始\n");
                            fflush(fpmeas);
                        }
                        //if(SegEnd==1)   ///之前进入过结束的状态,
                        {
                            if(fpmeas)
                            {
                                fprintf(fpmeas,"mtg->iset.rget=%d\n",mtg->iset.rget);
                                fflush(fpmeas);
                            }
                            if(mtg->snum.tm>=mtg->segset.L*LengthPercent && mtg->iset.rget==0)   ///跳环
                            {
                                multiple=(int)(mtg->snum.tm/mtg->segset.L);
                                mtg->snum.iseg+=multiple;
                                remain=mtg->snum.tm-mtg->segset.L*multiple;
                                if(remain>=mtg->segset.L-0.2)
                                    mtg->snum.iseg++;
                                mtg->snum.mile=mtg->m.headc;
                                mtg->snum.tm=0.0;
                                mtg->m1.iseg=mtg->snum.iseg;
                                mtg_store_snum(mtg);
                                panelMetric->Refresh();
                                RadioData(17);
                                if(fpmeas)
                                {
                                    fprintf(fpmeas,"跳环\n");
                                    fflush(fpmeas);
                                }
                            }
                        }
                        //SegEnd=0;
                        SegStart=1;
                        SegDoing=1;
                    }
                    else if(mtg->snum.tm>=mtg->segset.L*LengthPercent && testP.units[read_plc_mode_val].val_int==1 && SegDoing==1)   ///一环结束
                    {
                        if(fpmeas)
                        {
                            fprintf(fpmeas,"一环结束\n");
                            fflush(fpmeas);
                        }
                        //SegEnd=1;
                        SegStart=0;
                        SegDoing=0;
                    }

                    if(fpmeas)
                    {
                        fprintf(fpmeas,"\n");
                        fflush(fpmeas);
                        fclose(fpmeas);
                        fpmeas=NULL;
                    }
                }



                if(testP.units[read_plc_aj_a].readorwrite==0)
                {
                    mtg->aj[0]=(testP.units[read_plc_aj_a].val_int*testP.units[read_plc_aj_a].val_mul+testP.units[read_plc_aj_a].val_add)/1000.0;
                }
                if(testP.units[read_plc_aj_b].readorwrite==0)
                {
                    mtg->aj[1]=(testP.units[read_plc_aj_b].val_int*testP.units[read_plc_aj_b].val_mul+testP.units[read_plc_aj_b].val_add)/1000.0;
                }
                if(testP.units[read_plc_aj_c].readorwrite==0)
                {
                    mtg->aj[2]=(testP.units[read_plc_aj_c].val_int*testP.units[read_plc_aj_c].val_mul+testP.units[read_plc_aj_c].val_add)/1000.0;
                }
                if(testP.units[read_plc_aj_d].readorwrite==0)
                {
                    mtg->aj[3]=(testP.units[read_plc_aj_d].val_int*testP.units[read_plc_aj_d].val_mul+testP.units[read_plc_aj_d].val_add)/1000.0;
                }
                if(testP.units[read_plc_aj_e].readorwrite==0)
                {
                    mtg->aj[4]=(testP.units[read_plc_aj_e].val_int*testP.units[read_plc_aj_e].val_mul+testP.units[read_plc_aj_e].val_add)/1000.0;
                }
                if(testP.units[read_plc_aj_f].readorwrite==0)
                {
                    mtg->aj[5]=(testP.units[read_plc_aj_f].val_int*testP.units[read_plc_aj_f].val_mul+testP.units[read_plc_aj_f].val_add)/1000.0;
                }
                if(testP.units[read_plc_fj_a].readorwrite==0)
                {
                    mtg->fj[0]=(testP.units[read_plc_fj_a].val_int*testP.units[read_plc_fj_a].val_mul+testP.units[read_plc_fj_a].val_add)/1000.0;
                }
                if(testP.units[read_plc_fj_b].readorwrite==0)
                {
                    mtg->fj[1]=(testP.units[read_plc_fj_b].val_int*testP.units[read_plc_fj_b].val_mul+testP.units[read_plc_fj_b].val_add)/1000.0;
                }
                if(testP.units[read_plc_fj_c].readorwrite==0)
                {
                    mtg->fj[2]=(testP.units[read_plc_fj_c].val_int*testP.units[read_plc_fj_c].val_mul+testP.units[read_plc_fj_c].val_add)/1000.0;
                }
                if(testP.units[read_plc_fj_d].readorwrite==0)
                {
                    mtg->fj[3]=(testP.units[read_plc_fj_d].val_int*testP.units[read_plc_fj_d].val_mul+testP.units[read_plc_fj_d].val_add)/1000.0;
                }
                if(testP.units[read_plc_bj_a].readorwrite==0)
                {
                    mtg->bj[0]=(testP.units[read_plc_bj_a].val_int*testP.units[read_plc_bj_a].val_mul+testP.units[read_plc_bj_a].val_add)/1000.0;
                }
                if(testP.units[read_plc_bj_b].readorwrite==0)
                {
                    mtg->bj[1]=(testP.units[read_plc_bj_b].val_int*testP.units[read_plc_bj_b].val_mul+testP.units[read_plc_bj_b].val_add)/1000.0;
                }
                if(testP.units[read_plc_bj_c].readorwrite==0)
                {
                    mtg->bj[2]=(testP.units[read_plc_bj_c].val_int*testP.units[read_plc_bj_c].val_mul+testP.units[read_plc_bj_c].val_add)/1000.0;
                }
                if(testP.units[read_plc_bj_d].readorwrite==0)
                {
                    mtg->bj[3]=(testP.units[read_plc_bj_d].val_int*testP.units[read_plc_bj_d].val_mul+testP.units[read_plc_bj_d].val_add)/1000.0;
                }
                testP.read_plc_complete=0;
                //sqlite_export_plc(mtg,mtg->sqlitepath);
            }
        }
//        else if(testP.type==0 && mtg->iset.plctype==0)  //西门子
        else if((testP.type==0 || testP.type==6) && mtg->iset.plctype==0)  /// 西门子或者ab 20210110ws modify
        {
            if(testP.read_plc_complete==1)
            {
                if(mtg->itbm<2) mtg->itbm++;

/*                 20171226whq增加掘进状态是int型判断，
 *                 因兰州项目的掘进状态和拼装状态存在一个PLC地址中，
 *                 且用0，1，2，3，4，5分别表示停止、准备、就绪、掘进、拼装、拼装完成等6中情况
 */
                fpmeas=fopen("D:\\midu\\changeseg.log","w");

                if((testP.units[read_plc_mode_val].val_int==1&&testP.units[read_plc_mode_val].type==11)||(testP.units[read_plc_mode_val].val_int==4&&testP.units[read_plc_mode_val].type==2))
                {
                    if(fpmeas)
                    {
                        fprintf(fpmeas,"拼装\n");fflush(fpmeas);
                        fprintf(fpmeas,"tm=%.4f,L=%.4f,iseg=%d\n",mtg->snum.tm,mtg->segset.L,mtg->m1.iseg);fflush(fpmeas);
                    }
                    mtg->plc.amode=true;           ///拼装模式
                    mtg->segok=0;
                    ///分析环号
/*                    20180112whq增加了mtg->iset.rget==0的判断,表示根据PLC近似计算*/
                    if(mtg->snum.tm>=mtg->segset.L-0.2&&mtg->iset.rget==0)
                    {
                        ///20180112whq修改
                        multiple=(int)(mtg->snum.tm/mtg->segset.L);
                        mtg->snum.iseg+=multiple;
                        remain=mtg->snum.tm-mtg->segset.L*multiple;
                        if(remain>=mtg->segset.L-0.2)
                            mtg->snum.iseg++;
                        ///20180112修改结束
                        mtg->snum.mile=mtg->m.headc;
                        mtg->snum.tm=0.0;
                        ///20180112whq取消下句的注释，以便界面立刻更新环号
                        mtg->m1.iseg=mtg->snum.iseg;
                        mtg_store_snum(mtg);
                        ///20190514 whq add the following
                        RadioData(17);
                        if(fpmeas)
                        {
                            fprintf(fpmeas,"跳环\n");fflush(fpmeas);
                            fprintf(fpmeas,"seg=%d,mile=%.4f\n",mtg->m1.iseg,mtg->snum.mile);fflush(fpmeas);
                        }
                    }
                }
                else
                {
                    mtg->plc.amode=false;           ///拼装模式
                }
                if((testP.units[read_plc_start_val].val_int==1&&testP.units[read_plc_start_val].type==11)||(testP.units[read_plc_start_val].val_int==3&&testP.units[read_plc_start_val].type==2))
                {
                    if(fpmeas)
                    {
                        fprintf(fpmeas,"掘进\n");fflush(fpmeas);
                    }
                    mtg->plc.drive=true;           ///掘进开始
                    if(mtg->run==0 && mtg->iset.tsyn==0) mtg_start_cycle(mtg);
                }
                else
                {
                    mtg->plc.drive=false;          ///掘进停止
                    if(mtg->iset.tsyn==0)
                    {
                        if(mtg->run==1 && !mtg->incycle) mtg_stop(mtg);
                    }
                }
                if(fpmeas)
                {
                    fclose(fpmeas);
                    fpmeas=NULL;
                }

//                if(testP.units[read_plc_start_val].status==0||testP.units[read_plc_mode_val].status==0)///掘进或拼装状态地址不可用
//                {
//                    if(mtg->iset.rget!=1)
//                    {
//                        mtg->iset.rget=1;
//                        mtg_store_sets(mtg);
//                    }
//                }
                if(testP.units[read_plc_aj_a].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->aj[0] = (testP.units[read_plc_aj_a].val_int*testP.units[read_plc_aj_a].val_mul+testP.units[read_plc_aj_a].val_add)/1000.0;           ///A组推进油缸行程
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->aj[0] = (testP.units[read_plc_aj_a].val_double*testP.units[read_plc_aj_a].val_mul+testP.units[read_plc_aj_a].val_add)/1000.0;
                }
                if(testP.units[read_plc_aj_b].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->aj[1] = (testP.units[read_plc_aj_b].val_int*testP.units[read_plc_aj_b].val_mul+testP.units[read_plc_aj_b].val_add)/1000.0;           ///B组推进油缸行程
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->aj[1] = (testP.units[read_plc_aj_b].val_double*testP.units[read_plc_aj_b].val_mul+testP.units[read_plc_aj_b].val_add)/1000.0;
                }
                if(testP.units[read_plc_aj_c].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->aj[2] = (testP.units[read_plc_aj_c].val_int*testP.units[read_plc_aj_c].val_mul+testP.units[read_plc_aj_c].val_add)/1000.0;           ///C组推进油缸行程
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->aj[2] = (testP.units[read_plc_aj_c].val_double*testP.units[read_plc_aj_c].val_mul+testP.units[read_plc_aj_c].val_add)/1000.0;
                }
                if(testP.units[read_plc_aj_d].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->aj[3] = (testP.units[read_plc_aj_d].val_int*testP.units[read_plc_aj_d].val_mul+testP.units[read_plc_aj_d].val_add)/1000.0;           ///D组推进油缸行程
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->aj[3] = (testP.units[read_plc_aj_d].val_double*testP.units[read_plc_aj_d].val_mul+testP.units[read_plc_aj_d].val_add)/1000.0;
                }
                if(testP.units[read_plc_aj_e].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->aj[4] = (testP.units[read_plc_aj_e].val_int*testP.units[read_plc_aj_e].val_mul+testP.units[read_plc_aj_e].val_add)/1000.0;           ///D组推进油缸行程
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->aj[4] = (testP.units[read_plc_aj_e].val_double*testP.units[read_plc_aj_e].val_mul+testP.units[read_plc_aj_e].val_add)/1000.0;
                }
                if(testP.units[read_plc_aj_f].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->aj[5] = (testP.units[read_plc_aj_f].val_int*testP.units[read_plc_aj_f].val_mul+testP.units[read_plc_aj_f].val_add)/1000.0;           ///D组推进油缸行程
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->aj[5] = (testP.units[read_plc_aj_f].val_double*testP.units[read_plc_aj_f].val_mul+testP.units[read_plc_aj_f].val_add)/1000.0;
                }
                if(testP.units[read_plc_fj_a].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->fj[0] = (testP.units[read_plc_fj_a].val_int*testP.units[read_plc_fj_a].val_mul+testP.units[read_plc_fj_a].val_add)/1000.0;         ///盾首铰接
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->fj[0] = (testP.units[read_plc_fj_a].val_double*testP.units[read_plc_fj_a].val_mul+testP.units[read_plc_fj_a].val_add)/1000.0;
                }
                if(testP.units[read_plc_fj_b].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->fj[1] = (testP.units[read_plc_fj_b].val_int*testP.units[read_plc_fj_b].val_mul+testP.units[read_plc_fj_b].val_add)/1000.0;         ///盾首铰接
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->fj[1] = (testP.units[read_plc_fj_b].val_double*testP.units[read_plc_fj_b].val_mul+testP.units[read_plc_fj_b].val_add)/1000.0;
                }
                if(testP.units[read_plc_fj_c].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->fj[2] = (testP.units[read_plc_fj_c].val_int*testP.units[read_plc_fj_c].val_mul+testP.units[read_plc_fj_c].val_add)/1000.0;         ///盾首铰接
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->fj[2] = (testP.units[read_plc_fj_c].val_double*testP.units[read_plc_fj_c].val_mul+testP.units[read_plc_fj_c].val_add)/1000.0;
                }
                if(testP.units[read_plc_fj_d].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->fj[3] = (testP.units[read_plc_fj_d].val_int*testP.units[read_plc_fj_d].val_mul+testP.units[read_plc_fj_d].val_add)/1000.0;         ///盾首铰接
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->fj[3] = (testP.units[read_plc_fj_d].val_double*testP.units[read_plc_fj_d].val_mul+testP.units[read_plc_fj_d].val_add)/1000.0;
                }
                if(testP.units[read_plc_bj_a].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->bj[0] = (testP.units[read_plc_bj_a].val_int*testP.units[read_plc_bj_a].val_mul+testP.units[read_plc_bj_a].val_add)/1000.0;         ///盾尾铰接油缸右上：上
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->bj[0] = (testP.units[read_plc_bj_a].val_double*testP.units[read_plc_bj_a].val_mul+testP.units[read_plc_bj_a].val_add)/1000.0;
                }
                if(testP.units[read_plc_bj_b].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->bj[1] = (testP.units[read_plc_bj_b].val_int*testP.units[read_plc_bj_b].val_mul+testP.units[read_plc_bj_b].val_add)/1000.0;         ///盾尾铰接油缸左上：左
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->bj[1] = (testP.units[read_plc_bj_b].val_double*testP.units[read_plc_bj_b].val_mul+testP.units[read_plc_bj_b].val_add)/1000.0;
                }
                if(testP.units[read_plc_bj_c].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->bj[2] = (testP.units[read_plc_bj_c].val_int*testP.units[read_plc_bj_c].val_mul+testP.units[read_plc_bj_c].val_add)/1000.0;         ///盾尾铰接油缸左上：左
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->bj[2] = (testP.units[read_plc_bj_c].val_double*testP.units[read_plc_bj_c].val_mul+testP.units[read_plc_bj_c].val_add)/1000.0;
                }
                if(testP.units[read_plc_bj_d].readorwrite==0)
                {
                    if(testP.units[read_plc_aj_a].type==2)
                        mtg->bj[3] = (testP.units[read_plc_bj_d].val_int*testP.units[read_plc_bj_d].val_mul+testP.units[read_plc_bj_d].val_add)/1000.0;         ///盾尾铰接油缸右下：右
                    else if(testP.units[read_plc_aj_a].type==5)
                        mtg->bj[3] = (testP.units[read_plc_bj_d].val_double*testP.units[read_plc_bj_d].val_mul+testP.units[read_plc_bj_d].val_add)/1000.0;
                }
                //if(mtg->plc.drive) mtg_jack_gesture(mtg);
                testP.read_plc_complete=0;
            }
        }
        else if(testP.type==2 && mtg->iset.plctype==0)   ///施耐德
        {
            if(testP.read_plc_complete==1)
            {
                if(mtg->itbm<2) mtg->itbm++;

                if(testP.nunit>=60)
                {
                    if(testP.units[read_plc_mode_val].type==2)
                        amode=(testP.units[read_plc_mode_val].val_int*testP.units[read_plc_mode_val].val_mul+testP.units[read_plc_mode_val].val_add);
                    else if(testP.units[read_plc_mode_val].type==11)
                        amode=testP.units[read_plc_mode_val].val_int;

                    if(testP.units[read_plc_start_val].type==2)
                        drive=(testP.units[read_plc_start_val].val_int*testP.units[read_plc_start_val].val_mul+testP.units[read_plc_start_val].val_add);
                    else
                        drive=(testP.units[read_plc_start_val].val_int);
                }
                else
                {
                    if(testP.units[read_plc_status_amode].type==2)
                        amode=(testP.units[read_plc_status_amode].val_int*testP.units[read_plc_status_amode].val_mul+testP.units[read_plc_status_amode].val_add);
                    else if(testP.units[read_plc_status_amode].type==11)
                        amode=testP.units[read_plc_status_amode].val_int;

                    if(testP.units[read_plc_status_drive].type==2)
                        drive=(testP.units[read_plc_status_drive].val_int*testP.units[read_plc_status_drive].val_mul+testP.units[read_plc_status_drive].val_add);
                    else
                        drive=(testP.units[read_plc_status_drive].val_int);
                }
                if(amode==1)
                {
                    mtg->plc.amode=true;           ///拼装模式
                    mtg->segok=0;
                    if(mtg->snum.tm>=mtg->segset.L-0.2&&mtg->iset.rget==0)
                    {
                        multiple=(int)(mtg->snum.tm/mtg->segset.L);
                        mtg->snum.iseg+=multiple;
                        remain=mtg->snum.tm-mtg->segset.L*multiple;
                        if(remain>=mtg->segset.L-0.2)
                            mtg->snum.iseg++;
                        mtg->snum.mile=mtg->m.headc;
                        mtg->snum.tm=0.0;
                        mtg->m1.iseg=mtg->snum.iseg;
                        mtg_store_snum(mtg);
                        RadioData(17);
                    }
                }
                else
                {
                    mtg->plc.amode=false;
                }
                if(drive==1)
                {
                    mtg->plc.drive=true;           ///掘进开始
                    if(mtg->run==0 && mtg->iset.tsyn==0) mtg_start_cycle(mtg);
                }
                else
                {
                    mtg->plc.drive=false;          ///掘进停止
                    if(mtg->iset.tsyn==0)
                    {
                        if(mtg->run==1 && !mtg->incycle) mtg_stop(mtg);
                    }
                }

                mtg->aj[0]=(testP.units[read_plc_aj_a].val_long*testP.units[read_plc_aj_a].val_mul+testP.units[read_plc_aj_a].val_add)/1000.0;
                mtg->aj[1]=(testP.units[read_plc_aj_b].val_long*testP.units[read_plc_aj_b].val_mul+testP.units[read_plc_aj_b].val_add)/1000.0;
                mtg->aj[2]=(testP.units[read_plc_aj_c].val_long*testP.units[read_plc_aj_c].val_mul+testP.units[read_plc_aj_c].val_add)/1000.0;
                mtg->aj[3]=(testP.units[read_plc_aj_d].val_long*testP.units[read_plc_aj_d].val_mul+testP.units[read_plc_aj_d].val_add)/1000.0;

                mtg->fj[0]=(testP.units[read_plc_fj_a].val_long*testP.units[read_plc_fj_a].val_mul+testP.units[read_plc_fj_a].val_add)/1000.0;
                mtg->fj[1]=(testP.units[read_plc_fj_b].val_long*testP.units[read_plc_fj_b].val_mul+testP.units[read_plc_fj_b].val_add)/1000.0;
                mtg->fj[2]=(testP.units[read_plc_fj_c].val_long*testP.units[read_plc_fj_c].val_mul+testP.units[read_plc_fj_c].val_add)/1000.0;
                mtg->fj[3]=(testP.units[read_plc_fj_d].val_long*testP.units[read_plc_fj_d].val_mul+testP.units[read_plc_fj_d].val_add)/1000.0;

                mtg->bj[0]=(testP.units[read_plc_bj_a].val_long*testP.units[read_plc_bj_a].val_mul+testP.units[read_plc_bj_a].val_add)/1000.0;
                mtg->bj[1]=(testP.units[read_plc_bj_b].val_long*testP.units[read_plc_bj_b].val_mul+testP.units[read_plc_bj_b].val_add)/1000.0;
                mtg->bj[2]=(testP.units[read_plc_bj_c].val_long*testP.units[read_plc_bj_c].val_mul+testP.units[read_plc_bj_c].val_add)/1000.0;
                mtg->bj[3]=(testP.units[read_plc_bj_d].val_long*testP.units[read_plc_bj_d].val_mul+testP.units[read_plc_bj_d].val_add)/1000.0;

//                fpmeas=fopen("D:\\test.log","w");
//                if(fpmeas)
//                {
//                    fprintf(fpmeas,"drive=%d\n",testP.units[read_plc_start_val].val_int);fflush(fpmeas);
//                    fprintf(fpmeas,"0:%ld,aj=%.4f\n",testP.units[read_plc_aj_a].val_long,mtg->aj[0]);fflush(fpmeas);
//                    fprintf(fpmeas,"1:%ld,aj=%.4f\n",testP.units[read_plc_aj_b].val_long,mtg->aj[1]);fflush(fpmeas);
//                    fprintf(fpmeas,"2:%ld,aj=%.4f\n",testP.units[read_plc_aj_c].val_long,mtg->aj[2]);fflush(fpmeas);
//                    fprintf(fpmeas,"3:%ld,aj=%.4f\n",testP.units[read_plc_aj_d].val_long,mtg->aj[3]);fflush(fpmeas);
//                    fprintf(fpmeas,"0:%ld,fj=%.4f\n",testP.units[read_plc_fj_a].val_long,mtg->fj[0]);fflush(fpmeas);
//                    fprintf(fpmeas,"1:%ld,fj=%.4f\n",testP.units[read_plc_fj_b].val_long,mtg->fj[1]);fflush(fpmeas);
//                    fprintf(fpmeas,"2:%ld,fj=%.4f\n",testP.units[read_plc_fj_c].val_long,mtg->fj[2]);fflush(fpmeas);
//                    fprintf(fpmeas,"3:%ld,fj=%.4f\n",testP.units[read_plc_fj_d].val_long,mtg->fj[3]);fflush(fpmeas);
//                    fprintf(fpmeas,"0:%ld,bj=%.4f\n",testP.units[read_plc_bj_a].val_long,mtg->bj[0]);fflush(fpmeas);
//                    fprintf(fpmeas,"1:%ld,bj=%.4f\n",testP.units[read_plc_bj_b].val_long,mtg->bj[1]);fflush(fpmeas);
//                    fprintf(fpmeas,"2:%ld,bj=%.4f\n",testP.units[read_plc_bj_c].val_long,mtg->bj[2]);fflush(fpmeas);
//                    fprintf(fpmeas,"3:%ld,bj=%.4f\n",testP.units[read_plc_bj_d].val_long,mtg->bj[3]);fflush(fpmeas);
//                    fclose(fpmeas);
//                    fpmeas=NULL;
//                }

                testP.read_plc_complete=0;
            }
        }
        else if(mtg->iset.plctype==1)   ///web
        {
            if(testW.read_web_complete==1)
            {
                if(mtg->itbm<2) mtg->itbm++;

               // if(testW.units[read_plc_mode_val].val_int==4)
                if((testW.units[read_plc_mode_val].bitnum<0 && testW.units[read_plc_mode_val].val_int==4) || (testW.units[read_plc_mode_val].bitnum>=0 && testW.units[read_plc_mode_val].val_bit==1))
                {
                    mtg->plc.amode=true;           ///拼装模式mtg_laser_incline
                    mtg->segok=0;

                    //跳环
                    if(mtg->snum.tm>=mtg->segset.L-0.2&&mtg->iset.rget==0)
                    {
                        ///20180112whq修改
                        multiple=(int)(mtg->snum.tm/mtg->segset.L);
                        mtg->snum.iseg+=multiple;
                        remain=mtg->snum.tm-mtg->segset.L*multiple;
                        if(remain>=mtg->segset.L-0.2)
                            mtg->snum.iseg++;
                        ///20180112修改结束
                        mtg->snum.mile=mtg->m.headc;
                        mtg->snum.tm=0.0;
                        ///20180112whq取消下句的注释，以便界面立刻更新环号
                        mtg->m1.iseg=mtg->snum.iseg;
                        mtg_store_snum(mtg);
                        ///20190514 whq add the following
                        RadioData(17);
                    }
                }
                else
                {
                    mtg->plc.amode=false;
                }

                //if(testW.units[read_plc_start_val].val_int==3)
				if((testW.units[read_plc_start_val].bitnum<0 && testW.units[read_plc_start_val].val_int==3) || (testW.units[read_plc_start_val].bitnum>=0 &&testW.units[read_plc_start_val].val_bit==1))
                {
                    mtg->plc.drive=true;           ///掘进开始
                    if(mtg->run==0 && mtg->iset.tsyn==0) mtg_start_cycle(mtg);
                }
                else
                {
                    mtg->plc.drive=false;          ///掘进停止
                    if(mtg->iset.tsyn==0)
                    {
                        if(mtg->run==1 && !mtg->incycle) mtg_stop(mtg);
                    }
                }

                if(testW.units[read_plc_aj_a].readorwrite==0)
                {
                    mtg->aj[0] = testW.units[read_plc_aj_a].val_double/1000.0;           ///A组推进油缸行程
                }
                if(testW.units[read_plc_aj_b].readorwrite==0)
                {
                    mtg->aj[1] = testW.units[read_plc_aj_b].val_double/1000.0;           ///B组推进油缸行程
                }
                if(testW.units[read_plc_aj_c].readorwrite==0)
                {
                    mtg->aj[2] = testW.units[read_plc_aj_c].val_double/1000.0;           ///C组推进油缸行程
                }
                if(testW.units[read_plc_aj_d].readorwrite==0)
                {
                    mtg->aj[3] = testW.units[read_plc_aj_d].val_double/1000.0;           ///D组推进油缸行程
                }
                if(testW.units[read_plc_aj_e].readorwrite==0)
                {
                    mtg->aj[4] = testW.units[read_plc_aj_e].val_double/1000.0;           ///D组推进油缸行程
                }
                if(testW.units[read_plc_aj_f].readorwrite==0)
                {
                    mtg->aj[5] = testW.units[read_plc_aj_f].val_double/1000.0;           ///D组推进油缸行程
                }
                if(testW.units[read_plc_fj_a].readorwrite==0)
                {
                    mtg->fj[0] = testW.units[read_plc_fj_a].val_double/1000.0;         ///盾首铰接
                }
                if(testW.units[read_plc_fj_b].readorwrite==0)
                {
                    mtg->fj[1] = testW.units[read_plc_fj_b].val_double/1000.0;         ///盾首铰接
                }
                if(testW.units[read_plc_fj_c].readorwrite==0)
                {
                    mtg->fj[2] = testW.units[read_plc_fj_c].val_double/1000.0;         ///盾首铰接
                }
                if(testW.units[read_plc_fj_d].readorwrite==0)
                {
                    mtg->fj[3] = testW.units[read_plc_fj_d].val_double/1000.0;         ///盾首铰接
                }
                if(testW.units[read_plc_bj_a].readorwrite==0)
                {
                    mtg->bj[0] = testW.units[read_plc_bj_a].val_double/1000.0;         ///盾尾铰接油缸右上：上
                }
                if(testW.units[read_plc_bj_b].readorwrite==0)
                {
                    mtg->bj[1] = testW.units[read_plc_bj_b].val_double/1000.0;         ///盾尾铰接油缸左上：左
                }
                if(testW.units[read_plc_bj_c].readorwrite==0)
                {
                    mtg->bj[2] = testW.units[read_plc_bj_c].val_double/1000.0;         ///盾尾铰接油缸左上：左
                }
                if(testW.units[read_plc_bj_d].readorwrite==0)
                {
                    mtg->bj[3] = testW.units[read_plc_bj_d].val_double/1000.0;         ///盾尾铰接油缸右下：右
                }
                testW.read_web_complete=0;
            }
        }
        ///测试使用
//        if(mtg->itbm>=2)
//        {
//            testP.units[write_plc_roll1_val].val_long = (long)((tan(mtg->m1.inc1[0]/180*PI)*1000.0-testP.units[write_plc_roll_val].val_add)/testP.units[write_plc_roll_val].val_mul);
//            testP.units[write_plc_roll1_val].val_double = (tan(mtg->m1.inc1[0]/180*PI)*1000.0-testP.units[write_plc_roll_val].val_add)/testP.units[write_plc_roll_val].val_mul;
//            testP.units[write_plc_mile1_val].val_long = (long)(headc-testP.units[write_plc_head_mile].val_add)/testP.units[write_plc_head_mile].val_mul;
//            testP.units[write_plc_mile1_val].val_double = (headc-testP.units[write_plc_head_mile].val_add)/testP.units[write_plc_head_mile].val_mul;
//            testP.units[write_plc_numb1_val].val_long = (long)(mtg->m1.iseg-testP.units[write_plc_seg_num].val_add)/testP.units[write_plc_seg_num].val_mul;
//            testP.units[write_plc_numb1_val].val_int = (mtg->m1.iseg-testP.units[write_plc_seg_num].val_add)/testP.units[write_plc_seg_num].val_mul;
//
//            testP.units[write_plc_roll1_val].val_double=10000;
//            testP.units[write_plc_roll1_val].val_long=10000;
//            testP.units[write_plc_mile1_val].val_long=20000;
//            testP.units[write_plc_mile1_val].val_double=20000;
//            testP.units[write_plc_numb1_val].val_long=30000;
//            testP.units[write_plc_numb1_val].val_int=30000;
//            testP.units[write_plc_numb1_val].val_double=30000;
//            write_plc();
//        }

        for(i=0;i<ncli;i++)
        {
            if(mtg->icli[i]==1)
            {
                RadioData(i);
                mtg->icli[i]=0;
            }
        }
        ///撑紧盾倾斜仪
        if(mtg->incA_flag==1 && mtg->iincA)
        {
            if(!mtg->incthreadA)
            {
                mtg_inc_startA(mtg);
            }
        }

        ///倾斜仪
        if(mtg->iinc)
        {
            if(!mtg->incthread)
            {
                mtg_inc_start(mtg);
            }
        }
        if(mtg->plc.drive) drv=1;
        else drv=0;
        if(mtg->plc.amode) asb=1;
        else asb=0;
        sprintf(msg,"%%R1D,55:0:%lf,%lf,%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,\
            %d,%lf,%lf,%lf,%lf,%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,%lf\n",mtg->m.inc1[1],mtg->m.inc1[0],mtg->itps,mtg->iinc,mtg->icam,mtg->itbm,
            mtg->tbm.naj,mtg->aj[0],mtg->aj[1],mtg->aj[2],mtg->aj[3],mtg->aj[4],mtg->aj[5],
            mtg->tbm.nfj,mtg->fj[0],mtg->fj[1],mtg->fj[2],mtg->fj[3],mtg->tbm.nbj,mtg->bj[0],mtg->bj[1],mtg->bj[2],mtg->bj[3],
            mtg->deth,mtg->detv,drv,asb,mtg->snum.mile);
        RadioMsg(msg);


        ///判断加密狗剩余时间    20191101ws add
        time(&now_t);
        if(deadline-now_t<0)    ///剩余时间为负
        {
            time_tip=2;
            if(mtg->run==1 && !mtg->incycle)
                mtg_stop(mtg);
        }
        else if(deadline-now_t<=14*24*3600)   ///剩余时间小于14天
        {
            time_tip=1;
            remain_d=(deadline-now_t)/(24*3600);
        }
        else
        {
            time_tip=0;
        }

        panelMetric->Refresh();
    }

    if(tick % 30==0)
    {
        ///20190315 whq add
        tinc=mtg->inc_check.t+8*3600-(mtg->inc_check.t+8*3600)%(24*3600);
        if(t+8*3600-tinc>24*3600)
        {
            if(!mtg->tarset.stopped)
            {
                mtg->inc_check.daytimes=0;
            }
        }
        ///20191211 暂时注释，不判断角度是否异常
//        if(mtg->tarset.stopped==0)
//        {
//            if(mtg->inc_check.daytimes>mtg->tarset.dtsalw || mtg->inc_check.contimes>mtg->tarset.ctsalw)
//            {
//                mtg->tarset.stopped=1;
//                mtg_store_tars(mtg);
//                mtg->ierr[10]=1;
//            }
//        }
        ///20190315 whq add
        //if(tpsStatus==0) tpsStatus=1;
        //else tpsStatus=0;
        panelStatus->Refresh();
        if(mtg->iset.vibration==1 && mtg->itbm==1)
        {
            if(mtg->plc.drive && mtg->segok==1) mtg_jack_gesture(mtg);
        }

        //30s判断一次容易在设站定向时出现“测站异常”的提示，改为60s判断一次  20200302ws修改
        if(mtg->istat.x!=mtg->istn.statx ||
               mtg->istat.y!=mtg->istn.staty ||
               mtg->istat.z!=mtg->istn.statz ||
               mtg->iback.x!=mtg->istn.backx ||
               mtg->iback.y!=mtg->istn.backy ||
               mtg->iback.z!=mtg->istn.backz) mtg->ierr[9]=1;
               else mtg->ierr[9]=0;

        GetError();
        panelMode->Refresh();
    }

    if(mtg->itps && !mtg->thread)
    {
        /*if(tick==300) ///每30秒查询一次电池电量
        {
            mtg_get_power(mtg);
        }
        else */if(tick==600)
        {
            mtg_get_comp(mtg);
        }
    }

    if(tick % 50==0)
    {
        if(tip<nks-1)
        {
            tip++;
        }
        else if(tip==nks-1)
        {
            if(mtg->prj.htip==0) tip=nks;
            else if(mtg->prj.vtip==0) tip=nks+2;
            else tip=0;
        }
        else if(tip<nks+4)
        {
            tip++;
            if(tip==nks+4)
                tip=0;
        }
//        else
//        {
//            tip=0;
//        }

        if(testP.type==5)   //软plc
        {
            mtg_read_faj(mtg);
            if(mtg->plc.drive)   ///掘进
            {
                if(mtg->run==0 && mtg->iset.tsyn==0) mtg_start_cycle(mtg);
            }
            else    ///掘进停止
            {
                if(mtg->iset.tsyn==0)
                {
                    if(mtg->run==1 && !mtg->incycle) mtg_stop(mtg);
                }

                ///分析环号
                if(mtg->plc.amode)
                {
                    if(mtg->snum.tm>=mtg->segset.L-0.2 && mtg->iset.rget==0)///20180112whq增加了mtg->iset.rget==0的判断,表示根据PLC近似计算
                    {
                        ///20180112whq修改
                        multiple=(int)(mtg->snum.tm/mtg->segset.L);
                        mtg->snum.iseg+=multiple;
                        remain=mtg->snum.tm-mtg->segset.L*multiple;
                        if(remain>=mtg->segset.L-0.2)
                            mtg->snum.iseg++;
                        ///20180112修改结束
                        mtg->snum.mile=mtg->m.headc;
                        mtg->snum.tm=0.0;
                        ///20180112whq取消下句的注释，以便界面立刻更新环号
                        mtg->m1.iseg=mtg->snum.iseg;
                        mtg_store_snum(mtg);
                        panelMetric->Refresh();
                        RadioData(17);
                    }
                }
            }
        }
    }

    if(tick == 120) ///reconnect hardware
    {
        tick=0;
        if(!mtg->itps || !mtg->icam || !mtg->iinc && !mtg->thread || !mtg->iincA)
        {
            mtg_connect(mtg);
        }

        if(mtg->itbm==0)
        {
            wxStandardPaths wsp;
            wxString str=wsp.GetDataDir()+wxString(_("\\plugins"))+wxString(_("\\plc_config.cfg"));
            char path[1024];
            strcpy(path,str.mb_str(wxConvLocal));
            ///20181101whq临时注释，排查问题,2019-2-22whq 恢复
//            if(init_plc(path)==1)
//                mtg->itbm=1;
//            else
//            {
//                free_plc();
//            }
        }
        time(&t);
        t=t+86400;

        if(t+8*3600-tlog>24*3600)   ///每天0点备份
        {
            time(&t1);   //20201026ws add
            strftime(path,64,"db_%Y%m%d%H%M%S.prj",localtime(&t1));
            strcpy(strFull,"D://database//");

            //wxDir dbdir(wxString::FromUTF8(strFull));
            if(!wxDir::Exists(wxString::FromUTF8(strFull)))
            {
                wxFileName::Mkdir(wxString::FromUTF8(strFull));
            }
            if(wxDir::Exists(wxString::FromUTF8(strFull)))
            {
                strcat(strFull,path);
                mtg_store_database(mtg,strFull);
                tlog=t+8*3600-(t+8*3600)%(24*3600);
                wxDir dir(dirstr);
                if(dir.IsOpened())
                {
                    n=dir.GetAllFiles(dirstr,&files,token,wxDIR_DEFAULT);
                    //wxMessageBox(wxString::Format(_("%d"),n));
                    if(n>3)//超过五张照片需要删除多余的部分
                    {
                        files.Sort(true);
                        //files.RemoveAt(5,n-5);
                        for(int i=3;i<n;i++)
                        {
                            wxRemoveFile(files[i]);
                        }
                    }
                }
            }
        }
    }
    tickAnimation++;
    if(tickAnimation>10) tickAnimation=1;
    if(drawAnimation) panelGraph->Refresh(false);
}

