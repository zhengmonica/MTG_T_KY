///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyCheckDlg.h"
#include "mtg_t_svrApp.h"
#include "MypointDlg.h"
#include "MyfileDlg.h"
//#include "confirmdlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include "time.h"
#include "laserimg.h"
#include "ConfirmDlg.h"

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MyCheckDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MyCheckDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MyCheckDlg)
const long MyCheckDlg::ID_PANEL2 = wxNewId();                  //按钮
//*)

MyCheckDlg::MyCheckDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int dh=20;
	int x2,y2,w2,h2;
	this->GetClientSize(&w,&h);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPage = new wxPanel(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x1=7;
    y1=59;
    w1=w-x1*2;
    //h1=h-129;
    h1=h-119;
    panelTps = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTars = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPLC = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelINC = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTars->Show(false);
    panelPLC->Show(false);
    panelINC->Show(false);

    tpsList = new wxListView(panelTps, wxID_ANY, wxPoint(0,24), wxSize(w1,h1-64), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    incList = new wxListView(panelTars, wxID_ANY, wxPoint(w1/2,32), wxSize(w1/2,h1-72), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    plcList = new wxListView(panelPLC, wxID_ANY, wxPoint(0,24), wxSize(w1,h1-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    incList2 = new wxListView(panelINC, wxID_ANY, wxPoint(0,24), wxSize(w1,h1-64), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    //incList->Show(false);
    tpsButton = new wxPanel(panelTps, wxID_ANY, wxPoint(0,h1-40), wxSize(w1,40), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //tarsButton = new wxPanel(panelTars, wxID_ANY, wxPoint(0,h1-30), wxSize(w1,30), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    plcButton = new wxPanel(panelPLC, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    incButton = new wxPanel(panelINC, wxID_ANY, wxPoint(0,h1-40), wxSize(w1,40), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    plcButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPLC->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTars->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    tpsButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    incButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyCheckDlg::OnPaintMain,0,this);
    panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyCheckDlg::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyCheckDlg::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyCheckDlg::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyCheckDlg::OnClickPage,0,this);

    panelTps->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyCheckDlg::OnPaintTpsList,0,this);
    panelINC->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyCheckDlg::OnPaintIncList,0,this);

    panelTars->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyCheckDlg::OnPaintTar,0,this);

    panelPLC->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyCheckDlg::OnPaintPLC,0,this);

    plcButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyCheckDlg::OnPaintPlcButton,0,this);
    plcButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyCheckDlg::OnMotionPlcButton,0,this);
    plcButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyCheckDlg::OnLeavePlcButton,0,this);
    plcButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyCheckDlg::OnClickPlcButton,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyCheckDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyCheckDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyCheckDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyCheckDlg::OnClickBottom,0,this);

    ///2019-2-19 whq add
    tpsButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyCheckDlg::OnPaintTpsButton,0,this);
    tpsButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyCheckDlg::OnMotionTpsButton,0,this);
    tpsButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyCheckDlg::OnLeaveTpsButton,0,this);
    tpsButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyCheckDlg::OnClickTpsButton,0,this);

    //tarsButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyCheckDlg::OnPaintTarsButton,0,this);
    panelTars->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyCheckDlg::OnMotionTarsButton,0,this);
    panelTars->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyCheckDlg::OnLeaveTarsButton,0,this);
    panelTars->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyCheckDlg::OnClickTarsButton,0,this);

    incButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyCheckDlg::OnPaintIncButton,0,this);
    incButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyCheckDlg::OnMotionIncButton,0,this);
    incButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyCheckDlg::OnLeaveIncButton,0,this);
    incButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyCheckDlg::OnClickIncButton,0,this);

    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&MyCheckDlg::OnClose);
    //*)

    Connect(wxEVT_TIMER,(wxObjectEventFunction)&MyCheckDlg::OnTimer);
    timerStat.SetOwner(this);
    timerStat.Start(100,false);

    this->SetBackgroundColour(wxColor(245,248,250));

    motion=ID_CHECK_NONE;
    page=ID_CHECK_PAGE_TPS;

    int i=0;
    int j=0;

    tpsList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    tpsList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,65);
    tpsList->InsertColumn(i++,_("操作"),wxLIST_FORMAT_LEFT,120);
    tpsList->InsertColumn(i++,_("返回信息"),wxLIST_FORMAT_LEFT,360);
    tpsList->InsertColumn(i++,_("时间"),wxLIST_FORMAT_LEFT,180);

    i=0;
    incList2->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,60);
    incList2->InsertColumn(i++,_("时间"),wxLIST_FORMAT_CENTRE,200);
    incList2->InsertColumn(i++,_("初始滚动角差值"),wxLIST_FORMAT_LEFT,130);
    incList2->InsertColumn(i++,_("掘进滚动角差值"),wxLIST_FORMAT_LEFT,130);
    incList2->InsertColumn(i++,_("初始俯仰角差值"),wxLIST_FORMAT_LEFT,130);
    incList2->InsertColumn(i++,_("掘进俯仰角差值"),wxLIST_FORMAT_LEFT,130);

    i=0;
    incList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,30);
    incList->InsertColumn(i++,_("滚动角1"),wxLIST_FORMAT_CENTRE,60);
    incList->InsertColumn(i++,_("俯仰角1"),wxLIST_FORMAT_CENTRE,60);
    incList->InsertColumn(i++,_("滚动角2"),wxLIST_FORMAT_CENTRE,60);
    incList->InsertColumn(i++,_("俯仰角2"),wxLIST_FORMAT_CENTRE,60);
    incList->InsertColumn(i++,_("滚动角差\n差值"),wxLIST_FORMAT_CENTRE,60);
    incList->InsertColumn(i++,_("俯仰角差\n差值"),wxLIST_FORMAT_CENTRE,60);

    i=0;
    plcList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    plcList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    plcList->InsertColumn(i++,_("数据项"),wxLIST_FORMAT_LEFT,150);
    plcList->InsertColumn(i++,_("值"),wxLIST_FORMAT_CENTRE,120);
    j=0;
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("01"));
    plcList->SetItem(j++,2,_("掘进状态"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("02"));
    plcList->SetItem(j++,2,_("拼装状态"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("03"));
    plcList->SetItem(j++,2,_("推进油缸（上）"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("04"));
    plcList->SetItem(j++,2,_("推进油缸（下）"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("05"));
    plcList->SetItem(j++,2,_("推进油缸（左）"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("06"));
    plcList->SetItem(j++,2,_("推进油缸（右）"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("07"));
    plcList->SetItem(j++,2,_("盾首铰接油缸（上）"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("08"));
    plcList->SetItem(j++,2,_("盾首铰接油缸（下）"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("09"));
    plcList->SetItem(j++,2,_("盾首铰接油缸（左）"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("10"));
    plcList->SetItem(j++,2,_("盾首铰接油缸（右）"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("11"));
    plcList->SetItem(j++,2,_("盾尾铰接油缸（上）"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("12"));
    plcList->SetItem(j++,2,_("盾尾铰接油缸（下）"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("13"));
    plcList->SetItem(j++,2,_("盾尾铰接油缸（左）"));
    plcList->InsertItem(j,_(""));
    plcList->SetItem(j,1,_("14"));
    plcList->SetItem(j++,2,_("盾尾铰接油缸（右）"));
    i=0;
    radioBoxR1=7;
    radioBoxR2=4;
    ajname[0]=_("A组油缸");
    ajname[1]=_("B组油缸");
    ajname[2]=_("C组油缸");
    ajname[3]=_("D组油缸");
    ajname[4]=_("E组油缸");
    ajname[5]=_("F组油缸");
    ajname[6]=_("G组油缸");
    ajname[7]=_("H组油缸");
    ajname[8]=_("I组油缸");
    ajname[9]=_("J组油缸");
    ajname[10]=_("K组油缸");
    ajname[11]=_("L组油缸");

    LoadData();

    ///2019-2-19 whq add
    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);
    path1=path;
    int t1=path1.Find('\\',false);
    path1=path1.SubString(0,t1-1);
    path1=path1+_("\\image\\");
    //wxMessageBox(path1);

    if(!wxFileExists(path1))
    {
        wxMkDir(path1);
    }

    if(mtg->camsvr.cams[0].width==0||mtg->camsvr.cams[0].height==0)
    {
        mtg->camsvr.cams[0].width=1628;
        mtg->camsvr.cams[0].height=1236;
    }
    image.Create(mtg->camsvr.cams[0].width,mtg->camsvr.cams[0].height);
    bufsize=mtg->camsvr.cams[0].width*mtg->camsvr.cams[0].height*3;
}

MyCheckDlg::~MyCheckDlg()
{
    if(mtg->incover)
    {
        free(mtg->incover);
        mtg->incover=0;
        mtg->nover=0;
    }
}

void MyCheckDlg::OnClose(wxCloseEvent& event)
{
    if(mtg->incstat) mtg->incstat=0;
    Destroy();
}
///
void MyCheckDlg::OnPaintTpsList(wxPaintEvent& event)
{
    wxPaintDC dc(panelTps);
    int w,h;
    panelTps->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;
        int i=1;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=tpsList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=tpsList->GetColumnWidth(i++);

        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("操作"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=tpsList->GetColumnWidth(i++);

        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("返回信息"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=tpsList->GetColumnWidth(i++);

        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=tpsList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyCheckDlg::OnPaintIncList(wxPaintEvent& event)
{
    wxPaintDC dc(panelINC);
    int w,h;
    panelINC->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;
        int i=0;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=incList2->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList2->GetColumnWidth(i++);

        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList2->GetColumnWidth(i++);

        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("初始滚动角差值"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList2->GetColumnWidth(i++);

        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("掘进滚动角差值"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList2->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("初始俯仰角差值"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList2->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("掘进俯仰角差值"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList2->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyCheckDlg::OnPaintTar(wxPaintEvent& event)
{
    wxPaintDC dc(panelTars);
    int w,h;
    panelTars->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h-40);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont chs1(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
        //wxFont ens(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x1,y1,w1,h1;

        int x2,y2,w2,h2;
        w2=180;
        h2=144;
        x2=50;
        y2=33;
        wxPoint lines[360];

        lines[0].x=x2;
        lines[0].y=y2+2;
        lines[1].x=x2+2;
        lines[1].y=y2;
        lines[2].x=x2+w2-2;
        lines[2].y=y2;
        lines[3].x=x2+w2;
        lines[3].y=y2+2;
        lines[4].x=x2+w2;
        lines[4].y=y2+h2-2;
        lines[5].x=x2+w2-2;
        lines[5].y=y2+h2;
        lines[6].x=x2+2;
        lines[6].y=y2+h2;
        lines[7].x=x2;
        lines[7].y=y2+h2-2;
        lines[8].x=x2;
        lines[8].y=y2+2;
        memDC.DrawLines(9,lines);

        x1=x2+20;
        y1=y2+20;
        w1=w2-40;
        h1=h2-40;
        memDC.SetPen(wxPen(wxColor(158,0,0),1,wxDOT_DASH));
        memDC.DrawLine(x1,y1+h1/2,x1+w1,y1+h1/2);
        memDC.DrawLine(x1+w1/2,y1,x1+w1/2,y1+h1);
        int ix,iy;
        ix=mtg->camset[0].x2-mtg->camset[0].x1;
        iy=mtg->camset[0].y2-mtg->camset[0].y1;
        if(ix<0)
        {
            ix=-ix/2;
            iy=iy/2;
            x2=(mtg->m1.cam[1]-iy)*w2/2/iy;
            y2=(mtg->m1.cam[0]-ix)*h2/2/ix;
        }
        else
        {
            ix=ix/2;
            iy=iy/2;
            x2=(mtg->m1.cam[0]-(mtg->camset[0].x1+ix))*w1/2/ix;
            y2=(mtg->m1.cam[1]-(mtg->camset[0].y1+iy))*h1/2/iy;
        }
        memDC.SetBrush(wxBrush(wxColor(255,0,0)));
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        memDC.DrawCircle(x1+w1/2+x2,y1+h1/2+y2,5);
        memDC.SetPen(wxPen(wxColor(0,0,0)));
        memDC.DrawLine(x1+w1/2+x2-10,y1+h1/2+y2,x1+w1/2+x2+10,y1+h1/2+y2);
        memDC.DrawLine(x1+w1/2+x2,y1+h1/2+y2-10,x1+w1/2+x2,y1+h1/2+y2+10);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        w2=180;
        h2=144;
        x2=50;
        y2=210;
        //y2=y2+h2+y2;
        lines[0].x=x2;
        lines[0].y=y2+2;
        lines[1].x=x2+2;
        lines[1].y=y2;
        lines[2].x=x2+w2-2;
        lines[2].y=y2;
        lines[3].x=x2+w2;
        lines[3].y=y2+2;
        lines[4].x=x2+w2;
        lines[4].y=y2+h2-2;
        lines[5].x=x2+w2-2;
        lines[5].y=y2+h2;
        lines[6].x=x2+2;
        lines[6].y=y2+h2;
        lines[7].x=x2;
        lines[7].y=y2+h2-2;
        lines[8].x=x2;
        lines[8].y=y2+2;
        memDC.DrawLines(9,lines);
        lines[0].x=x2+w2/2-32;
        lines[0].y=y2+h2;
        lines[1].x=lines[0].x;
        lines[1].y=y2+h2+2;
        lines[2].x=lines[0].x+64;
        lines[2].y=lines[1].y;
        lines[3].x=lines[2].x;
        lines[3].y=lines[0].y;
        memDC.DrawLines(4,lines);

        lines[0].x=x2+13;
        lines[0].y=y2+13;
        lines[1].x=x2+w2-13;
        lines[1].y=y2+13;
        lines[2].x=x2+w2-13;
        lines[2].y=y2+h2;
        lines[3].x=x2+13;
        lines[3].y=y2+h2;
        lines[4].x=x2+13;
        lines[4].y=y2+13;
        memDC.DrawLines(5,lines);

        lines[0].x=x2+70;
        lines[0].y=y2+45;
        lines[1].x=lines[0].x+40;
        lines[1].y=lines[0].y;
        lines[2].x=lines[1].x;
        lines[2].y=lines[0].y+30;
        lines[3].x=lines[0].x;
        lines[3].y=lines[2].y;
        lines[4].x=lines[0].x;
        lines[4].y=lines[0].y;
        memDC.DrawLines(5,lines);

        int xc=x2+16;
        int yc=y2+16;
        for(int i=180;i<=270;i++)
        {
            lines[i-180].x=xc+8*cos(i*3.1415926/180);
            lines[i-180].y=yc+8*sin(i*3.1415926/180);
        }
        xc=x2+w2-16;
        yc=y2+16;
        for(int i=270;i<=360;i++)
        {
            lines[i-179].x=xc+8*cos(i*3.1415926/180);
            lines[i-179].y=yc+8*sin(i*3.1415926/180);
        }
        lines[182].x=lines[181].x;
        lines[182].y=y2+h2;
        lines[183].x=x2+8;
        lines[183].y=lines[182].y;
        lines[184].x=lines[0].x;
        lines[184].y=lines[0].y;
        memDC.DrawLines(185,lines);

        w2=180;
        h2=144;
        x2=x2+w2+50;
        y2=33;
        memDC.SetFont(chs1);
        memDC.DrawLabel(_("光斑位置"),wxRect(x2,y2,120,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y2+=28;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("x = ")+wxString::Format(_("%.2f"),mtg->m1.cam[0]),wxRect(x2,y2,120,18),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y2+=18;
        memDC.DrawLabel(_("y = ")+wxString::Format(_("%.2f"),mtg->m1.cam[1]),wxRect(x2,y2,120,18),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y2+=30;
        memDC.SetFont(chs1);
        memDC.DrawLabel(_("姿态角"),wxRect(x2,y2,120,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y2+=28;
        memDC.SetFont(chs);
        if(mtg->tarset.baseinc==1)
            memDC.DrawLabel(_("转动 = ")+wxString::Format(_("%.2f°"),mtg->m1.inc[5]),wxRect(x2,y2,120,18),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        else
            memDC.DrawLabel(_("转动 = ")+wxString::Format(_("%.2f°"),mtg->m1.inc[0]),wxRect(x2,y2,120,18),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y2+=18;
        if(mtg->tarset.baseinc==1)
            memDC.DrawLabel(_("俯仰 = ")+wxString::Format(_("%.2f°"),mtg->m1.inc[6]),wxRect(x2,y2,120,18),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        else
            memDC.DrawLabel(_("俯仰 = ")+wxString::Format(_("%.2f°"),mtg->m1.inc[1]),wxRect(x2,y2,120,18),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y2+=18;
        memDC.DrawLabel(_("方位 = ")+wxString::Format(_("%.2f°"),mtg->m1.inc[2]),wxRect(x2,y2,120,18),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        int r1,g1,b1;
        r1=200;
        g1=200;
        b1=200;
        for(int i=0;i<40;i++)
        {
            memDC.SetPen(wxPen(wxColor(r1,g1,b1)));
            memDC.DrawLine(0,i+h-40,w,i+h-40);
            if(i%3==0)
            {
                if(i<h/2)
                {
                    r1--;
                    g1--;
                    b1--;
                }
                else
                {
                    r1++;
                    g1++;
                    b1++;
                }
            }
        }

        //int x1,y1,w1,h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawLine(w/2,0,w/2,h);

//        double incx1=0,incx2=0,incxd=0,incy1=0,incy2=0,incyd=0;
//        incx1=mtg->m0.inc[5]-mtg->m0.inc[0];
//        incx2=mtg->m.inc[5]-mtg->m.inc[0];
//        incy1=mtg->m0.inc[6]-mtg->m0.inc[1];
//        incy2=mtg->m.inc[6]-mtg->m.inc[1];
//        incxd=incx2-incx1;
//        incyd=incy2-incy1;
//
//        x1=w/2;
//        y1=33;
////        w1=w/2;
////        h1=144;
//        int x3,y3,w3,h3;
//
//        x3=x1+11;
//        y3=y1;
//        w3=120;
//        h3=h1=30;
//        memDC.DrawLabel(_("激光靶角度"),NULL,wxRect(x3,y3,w1,h1),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
//        x3+=w3;
//        w3=80;
//        memDC.DrawLabel(wxString::Format(_("滚动角")),NULL,wxRect(x3,y3,w3,h3),wxALIGN_CENTER);
//        x3+=w3;
//        w3=120;
//        memDC.DrawLabel(wxString::Format(_("俯仰角")),NULL,wxRect(x3,y3,w3,h3),wxALIGN_CENTER);
//
//        x3=x1+11;
//        y3=y3+h1;
//        w3=120;
//        h1=30;
//        memDC.DrawLabel(_("零位测量"),NULL,wxRect(x3,y3,w1,h1),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
//        x3+=w3;
//        w3=80;
//        memDC.DrawLabel(wxString::Format(_("%.5f°"),incx1),NULL,wxRect(x3,y3,w3,h3),wxALIGN_CENTER);
//        x3+=w3;
//        w3=120;
//        memDC.DrawLabel(wxString::Format(_("%.5f°"),incy1),NULL,wxRect(x3,y3,w3,h3),wxALIGN_CENTER);
//
//        x3=x1+11;
//        y3=y3+h1;
//        w3=120;
//        h1=30;
//        memDC.DrawLabel(_("周期测量"),NULL,wxRect(x3,y3,w1,h1),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
//        x3+=w3;
//        w3=80;
//        memDC.DrawLabel(wxString::Format(_("%.5f°"),incx2),NULL,wxRect(x3,y3,w3,h3),wxALIGN_CENTER);
//        x3+=w3;
//        w3=120;
//        memDC.DrawLabel(wxString::Format(_("%.5f°"),incy2),NULL,wxRect(x3,y3,w3,h3),wxALIGN_CENTER);
//
//        x3=x1+11;
//        y3=y3+h1;
//        w3=120;
//        h1=30;
//        memDC.DrawLabel(_("差值"),NULL,wxRect(x3,y3,w1,h1),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
//        x3+=w3;
//        w3=80;
//        if(fabs(incxd)>0.3)
//            memDC.SetTextForeground(wxColor(255,0,0));
//        else
//            memDC.SetTextBackground(wxColor(0,0,0));
//        memDC.DrawLabel(wxString::Format(_("%.5f°"),incxd),NULL,wxRect(x3,y3,w3,h3),wxALIGN_CENTER);
//        x3+=w3;
//        w3=120;
//        if(fabs(incxd)>0.3)
//            memDC.SetTextForeground(wxColor(255,0,0));
//        else
//            memDC.SetTextBackground(wxColor(0,0,0));
//        memDC.DrawLabel(wxString::Format(_("%.5f°"),incyd),NULL,wxRect(x3,y3,w3,h3),wxALIGN_CENTER);
//
//        x3=x1+11;
//        y3=y3+h1;
//        w3=240;
//        wxString str=wxEmptyString;
//        if(fabs(incxd)>0.3||fabs(incyd)>0.3)
//        {
//            str=_("超限");
//            memDC.SetTextForeground(wxColor(255,0,0));
//        }
//        else
//        {
//            str=_("");
//            memDC.SetTextBackground(wxColor(0,0,0));
//        }
//        memDC.DrawLabel(_("时间   ")+wxDateTime(mtg->m.t5).Format(_("%Y-%m-%d %H:%M:%S"))+_("超限"),NULL,wxRect(x3,y3,w1,h1),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        //incList->SetSize(w/2,0,w/2,h-40);

        //int x1,y1,w1,h1;
        x1=w/2;
        y1=0;
        h1=32;
        int i=0;
        //memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=incList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("滚动角1"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("俯仰角1"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("滚动角2"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("俯仰角2"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("滚动角差\n差值"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("俯仰角差\n差值"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        incList->SetSize(w/2,32,w/2,h-72);

        w1=65;
        h1=26;
        x1=w/2-w1-14;
        y1=h-h1-7;
        checkButton[ID_CHECK_EXPORT_IMAGE].x=x1;
        checkButton[ID_CHECK_EXPORT_IMAGE].y=y1;
        checkButton[ID_CHECK_EXPORT_IMAGE].width=w1;
        checkButton[ID_CHECK_EXPORT_IMAGE].height=h1;
        if(motion==ID_CHECK_EXPORT_IMAGE)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("导出照片"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1-=w1;
        x1=w-w1-14;
        checkButton[ID_CHECK_INC_START].x=x1;
        checkButton[ID_CHECK_INC_START].y=y1;
        checkButton[ID_CHECK_INC_START].width=w1;
        checkButton[ID_CHECK_INC_START].height=h1;
        if(motion==ID_CHECK_INC_START)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        if(mtg->incstat==0)
            memDC.DrawLabel(_("采集数据"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        else
            memDC.DrawLabel(_("停止采集"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        //memDC.DrawLine(0,h-40,w,h-40);
        memDC.DrawLine(0,h-1,w,h-1);
        memDC.DrawLine(0,h-40,0,h);
        memDC.DrawLine(w-1,h-40,w-1,h);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyCheckDlg::OnPaintPLC(wxPaintEvent& event)
{
    wxPaintDC dc(panelPLC);
    int w,h;
    panelPLC->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);

    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(-1,0,w+2,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=37;
        memDC.SetPen(wxPen(wxColor(130,135,144)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1,y1+1,x1+w1,y1+1);
        plcButton->SetSize(x1,y1+2,w1,h1);

        y1=y1+h1+2;
        h1=h-y1;
        memDC.SetPen(wxPen(wxColor(130,135,144)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        plcList->SetSize(x1,y1,w1,h1);
        plcList->Show(false);
        int x2,y2,w2,h2;
        x1=x1+15;
        y1=y1+10;
        w1=w1-30;
        h1=25;
        x2=x1;
        y2=y1;
        w2=w1/3;
        h2=h1;
        memDC.DrawLabel(_("正在掘进？"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(0,0,0)));
        memDC.SetBrush(*wxBLACK_BRUSH);
        memDC.DrawRectangle(x2+w2/3,y2+3,w2/3,h2-6);
        if(mtg->plc.drive)
        {
            memDC.SetTextForeground(wxColor(0,255,0));
            memDC.DrawLabel(_("是"),wxRect(x2+w2/3,y2,w2/3,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,0,0));
            memDC.DrawLabel(_("否"),wxRect(x2+w2/3,y2,w2/3,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        x2=x2+w2;
        memDC.SetTextForeground(wxColor(0,0,0));
//        memDC.DrawLabel(_("正在拼装？"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("环片模式？"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(0,0,0)));
        memDC.SetBrush(*wxBLACK_BRUSH);
        memDC.DrawRectangle(x2+w2/3,y2+3,w2/3,h2-6);
        if(mtg->plc.amode)
        {
            memDC.SetTextForeground(wxColor(0,255,0));
            memDC.DrawLabel(_("是"),wxRect(x2+w2/3,y2,w2/3,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,0,0));
            memDC.DrawLabel(_("否"),wxRect(x2+w2/3,y2,w2/3,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetTextForeground(wxColor(0,0,0));
        y2=y2+h2+10;
        x2=x1;
        if(mtg->tbm.aunit==1000)
        {
            memDC.DrawLabel(_("推进油缸（单位：毫米）"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
            memDC.DrawLabel(_("推进油缸（单位：米）"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x2=x2+w2;
        if(mtg->tbm.bunit==1000)
        {
            memDC.DrawLabel(_("盾尾铰接（单位：毫米）"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x2=x2+w2;
            memDC.DrawLabel(_("盾首铰接（单位：毫米）"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("盾尾铰接（单位：米）"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x2=x2+w2;
            memDC.DrawLabel(_("盾首铰接（单位：米）"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        x2=x1;
        y1=y2+h2;
        y2=y1;
        int naj=mtg->tbm.naj;
        int nbj=mtg->tbm.nbj;
        int nfj=mtg->tbm.nfj;


        for(int i=0;i<naj;i++)
        {
            memDC.SetTextForeground(wxColor(0,0,0));
            memDC.DrawLabel(ajname[i],wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetTextForeground(wxColor(0,0,255));
            if(mtg->tbm.aunit==1000)
                memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->aj[i]*1000.0),wxRect(x2+w2/3,y2,w2/3,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            else
                memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->aj[i]),wxRect(x2+w2/3,y2,w2/3,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            y2=y2+h2;
        }

        x2=x2+w2;
        y2=y1;
        for(int i=0;i<nbj;i++)
        {
            memDC.SetTextForeground(wxColor(0,0,0));
            memDC.DrawLabel(ajname[i],wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetTextForeground(wxColor(0,0,255));
            if(mtg->tbm.bunit==1000)
                memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->bj[i]*1000.0),wxRect(x2+w2/3,y2,w2/3,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            else
                memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->bj[i]),wxRect(x2+w2/3,y2,w2/3,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            y2=y2+h2;
        }


        x2=x2+w2;
        y2=y1;
        for(int i=0;i<nfj;i++)
        {
            memDC.SetTextForeground(wxColor(0,0,0));
            memDC.DrawLabel(ajname[i],wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetTextForeground(wxColor(0,0,255));
            if(mtg->tbm.funit==1000)
                memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->fj[i]*1000.0),wxRect(x2+w2/3,y2,w2/3,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            else
                memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->fj[i]),wxRect(x2+w2/3,y2,w2/3,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            y2=y2+h2;
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

///
void MyCheckDlg::OnPaintPlcButton(wxPaintEvent& event)
{
    wxPaintDC dc(plcButton);
    int w,h;
    plcButton->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(238,238,238)));
        memDC.SetBrush(wxBrush(wxColor(238,238,238)));
        memDC.DrawRectangle(0,0,w,h);

        int x1=0;
        int y1=0;
        int w1=60;
        int h1=h;

        memDC.DrawLabel(_("推进油缸"),wxRect(x1+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=80;
        w1=100;
        checkButton[ID_CHECK_AJ_UNIT_MM].x=x1;
        checkButton[ID_CHECK_AJ_UNIT_MM].y=y1;
        checkButton[ID_CHECK_AJ_UNIT_MM].width=w1;
        checkButton[ID_CHECK_AJ_UNIT_MM].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(mtg->tbm.aunit==1000)
        {
            if(motion==ID_CHECK_AJ_UNIT_MM)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("单位:毫米"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion==ID_CHECK_AJ_UNIT_MM)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.DrawLabel(_("单位:毫米"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        //w1=100;
        checkButton[ID_CHECK_AJ_UNIT_M].x=x1;
        checkButton[ID_CHECK_AJ_UNIT_M].y=y1;
        checkButton[ID_CHECK_AJ_UNIT_M].width=w1;
        checkButton[ID_CHECK_AJ_UNIT_M].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(mtg->tbm.aunit==1)
        {
            if(motion==ID_CHECK_AJ_UNIT_M)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("单位:米"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion==ID_CHECK_AJ_UNIT_M)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.DrawLabel(_("单位:米"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1+30;
        memDC.DrawLabel(_("铰接油缸"),wxRect(x1+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+80;
        w1=100;
        checkButton[ID_CHECK_BJ_UNIT_MM].x=x1;
        checkButton[ID_CHECK_BJ_UNIT_MM].y=y1;
        checkButton[ID_CHECK_BJ_UNIT_MM].width=w1;
        checkButton[ID_CHECK_BJ_UNIT_MM].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(mtg->tbm.bunit==1000)
        {
            if(motion==ID_CHECK_BJ_UNIT_MM)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("单位:毫米"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion==ID_CHECK_BJ_UNIT_MM)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.DrawLabel(_("单位:毫米"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        //w1=100;
        checkButton[ID_CHECK_BJ_UNIT_M].x=x1;
        checkButton[ID_CHECK_BJ_UNIT_M].y=y1;
        checkButton[ID_CHECK_BJ_UNIT_M].width=w1;
        checkButton[ID_CHECK_BJ_UNIT_M].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(mtg->tbm.bunit==1)
        {
            if(motion==ID_CHECK_BJ_UNIT_M)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("单位:米"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion==ID_CHECK_BJ_UNIT_M)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.DrawLabel(_("单位:米"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyCheckDlg::OnMotionPlcButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();

    if(y>checkButton[ID_CHECK_AJ_UNIT_MM].y && y<checkButton[ID_CHECK_AJ_UNIT_MM].y+checkButton[ID_CHECK_AJ_UNIT_MM].height)
    {
        if(x>checkButton[ID_CHECK_AJ_UNIT_MM].x && x<checkButton[ID_CHECK_AJ_UNIT_MM].x+checkButton[ID_CHECK_AJ_UNIT_MM].width)
        {
            motion=ID_CHECK_AJ_UNIT_MM;
        }
        else if(x>checkButton[ID_CHECK_AJ_UNIT_M].x && x<checkButton[ID_CHECK_AJ_UNIT_M].x+checkButton[ID_CHECK_AJ_UNIT_M].width)
        {
            motion=ID_CHECK_AJ_UNIT_M;
        }
        else if(x>checkButton[ID_CHECK_BJ_UNIT_MM].x && x<checkButton[ID_CHECK_BJ_UNIT_MM].x+checkButton[ID_CHECK_BJ_UNIT_MM].width)
        {
            motion=ID_CHECK_BJ_UNIT_MM;
        }
        else if(x>checkButton[ID_CHECK_BJ_UNIT_M].x && x<checkButton[ID_CHECK_BJ_UNIT_M].x+checkButton[ID_CHECK_BJ_UNIT_M].width)
        {
            motion=ID_CHECK_BJ_UNIT_M;
        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    else
    {
        motion=ID_CHECK_NONE;
    }

    plcButton->Refresh();
}

void MyCheckDlg::OnLeavePlcButton(wxMouseEvent& event)
{
    motion=ID_CHECK_NONE;
    plcButton->Refresh();
}

void MyCheckDlg::OnClickPlcButton(wxMouseEvent& event)
{
    if(motion==ID_CHECK_AJ_UNIT_MM)
    {
        mtg->tbm.aunit=1000;
        mtg_store_tbmset(mtg);
    }
    else if(motion==ID_CHECK_AJ_UNIT_M)
    {
        mtg->tbm.aunit=1;
        mtg_store_tbmset(mtg);
    }
    else if(motion==ID_CHECK_BJ_UNIT_MM)
    {
        mtg->tbm.bunit=1000;
        mtg->tbm.funit=1000;
        mtg_store_tbmset(mtg);
    }
    else if(motion==ID_CHECK_BJ_UNIT_M)
    {
        mtg->tbm.bunit=1;
        mtg->tbm.funit=1;
        mtg_store_tbmset(mtg);
    }
    plcButton->Refresh();
    panelPLC->Refresh();
}

///
void MyCheckDlg::OnPaintBottom(wxPaintEvent& event)
{
    wxPaintDC dc(panelBottom);
    int w,h;
    panelBottom->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        int r1,g1,b1;
        r1=236;
        g1=236;
        b1=236;
        for(int i=0;i<h;i++)
        {
            memDC.SetPen(wxPen(wxColor(r1,g1,b1)));
            memDC.DrawLine(0,i,w,i);
            if(i%3==0)
            {
                if(i<h/2)
                {
                    r1--;
                    g1--;
                    b1--;
                }
                else
                {
                    r1++;
                    g1++;
                    b1++;
                }
            }
        }
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        w1=65;
        h1=26;
        x1=w-w1-14;
        y1=9;
        checkButton[ID_CHECK_QUIT].x=x1;
        checkButton[ID_CHECK_QUIT].y=y1;
        checkButton[ID_CHECK_QUIT].width=w1;
        checkButton[ID_CHECK_QUIT].height=h1;
        if(motion==ID_CHECK_QUIT)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("退出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=9;
        y1=9;
        h1=26;
        w1=h1*4/3;

        checkButton[ID_CHECK_PRT_SCN].x=x1;
        checkButton[ID_CHECK_PRT_SCN].y=y1;
        checkButton[ID_CHECK_PRT_SCN].width=w1;
        checkButton[ID_CHECK_PRT_SCN].height=h1;
        if(motion==ID_CHECK_PRT_SCN)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
        }
        int x2,y2,w2,h2;
        h2=h1-6;
        w2=h1;
        x2=x1+w1/2-w2/2;
        y2=y1+3;
        memDC.SetPen(wxPen(wxColor(168,181,178)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x2,y2,w2,h2-2);
        memDC.SetPen(wxPen(wxColor(47,139,205)));
        memDC.SetBrush(wxBrush(wxColor(47,139,205)));
        memDC.DrawRectangle(x2+3,y2+4,w2-6,h2-11);

        memDC.SetPen(wxPen(wxColor(168,181,178)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x2+w2/4-1,y2+h2-3,w2/2,4);

        x1=w1+14;
        w1=w-x1*2;

        if(m_msgc==0)
        {
            memDC.SetTextForeground(wxColor(0,0,255));
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,0,0));
        }
        if(m_msg!=wxEmptyString) memDC.DrawLabel(m_msg,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyCheckDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>checkButton[ID_CHECK_QUIT].y && y<checkButton[ID_CHECK_QUIT].y+checkButton[ID_CHECK_QUIT].height)
    {
        if(x>checkButton[ID_CHECK_QUIT].x && x<checkButton[ID_CHECK_QUIT].x+checkButton[ID_CHECK_QUIT].width)
        {
            motion=ID_CHECK_QUIT;
        }
        else if(x>checkButton[ID_CHECK_PRT_SCN].x && x<checkButton[ID_CHECK_PRT_SCN].x+checkButton[ID_CHECK_PRT_SCN].width)
        {
            motion=ID_CHECK_PRT_SCN;
        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    else
    {
        motion=ID_CHECK_NONE;
    }
    panelBottom->Refresh();
}

void MyCheckDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_CHECK_NONE;
    panelBottom->Refresh();
}

void MyCheckDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_CHECK_QUIT)
    {
        //SaveTbm();
        //SavePortal();
        sleepms(50);
        mtg->incstat=0;
        Destroy();
    }
    else if(motion==ID_CHECK_PRT_SCN)
    {
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
        //str=wxString(mtg->duty[i].name,wxConvLocal);
        str=_("检查界面");
        str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
        }
    }
    ///panelBottom->Refresh();
}

///
void MyCheckDlg::OnPaintMain(wxPaintEvent& event)
{
    wxPaintDC dc(panelMain);
    int w,h;
    panelMain->GetSize(&w,&h);
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


        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(-1,38,w+2,10);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,48,w,48);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(-1,49,w+2,h-49);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

///
void MyCheckDlg::OnPaintPage(wxPaintEvent& event)
{
    wxPaintDC dc(panelPage);
    int w,h;
    panelPage->GetSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        int r,g,b;
        x1=0;
        y1=0;
        w1=95;
        h1=h;
        checkButton[ID_CHECK_PAGE_TPS].x=x1;
        checkButton[ID_CHECK_PAGE_TPS].y=y1;
        checkButton[ID_CHECK_PAGE_TPS].width=w1;
        checkButton[ID_CHECK_PAGE_TPS].height=h1;

        if(page==ID_CHECK_PAGE_TPS || motion==ID_CHECK_PAGE_TPS)
        {
            r=200;
            g=225;
            b=250;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                //y1++;
            }

            if(page!=ID_CHECK_PAGE_TPS)
            {
                memDC.SetPen(wxPen(wxColor(172,168,153)));
                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
            }
        }
        else
        {
            r=236;
            g=236;
            b=236;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                r--;
                g--;
                b--;
            }
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
        }
        memDC.DrawLabel(_("全站仪"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);

        x1=x1+w1;
        checkButton[ID_CHECK_PAGE_TAR].x=x1;
        checkButton[ID_CHECK_PAGE_TAR].y=y1;
        checkButton[ID_CHECK_PAGE_TAR].width=w1;
        checkButton[ID_CHECK_PAGE_TAR].height=h1;
        if(page==ID_CHECK_PAGE_TAR || motion==ID_CHECK_PAGE_TAR)
        {
            r=200;
            g=225;
            b=250;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                //y1++;
            }

            if(page!=ID_CHECK_PAGE_TAR)
            {
                memDC.SetPen(wxPen(wxColor(172,168,153)));
                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
            }
        }
        else
        {
            r=236;
            g=236;
            b=236;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                r--;
                g--;
                b--;
            }
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
        }
        memDC.DrawLabel(_("激光靶"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1+w1;
        checkButton[ID_CHECK_PAGE_PLC].x=x1;
        checkButton[ID_CHECK_PAGE_PLC].y=y1;
        checkButton[ID_CHECK_PAGE_PLC].width=w1;
        checkButton[ID_CHECK_PAGE_PLC].height=h1;
        if(page==ID_CHECK_PAGE_PLC || motion==ID_CHECK_PAGE_PLC)
        {
            r=200;
            g=225;
            b=250;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                //y1++;
            }

            if(page!=ID_CHECK_PAGE_PLC)
            {
                memDC.SetPen(wxPen(wxColor(172,168,153)));
                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
            }
        }
        else
        {
            r=236;
            g=236;
            b=236;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                r--;
                g--;
                b--;
            }
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
        }
        memDC.DrawLabel(_("PLC"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1+w1;
        checkButton[ID_CHECK_PAGE_INC].x=x1;
        checkButton[ID_CHECK_PAGE_INC].y=y1;
        checkButton[ID_CHECK_PAGE_INC].width=w1;
        checkButton[ID_CHECK_PAGE_INC].height=h1;
        if(page==ID_CHECK_PAGE_INC || motion==ID_CHECK_PAGE_INC)
        {
            r=200;
            g=225;
            b=250;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                //y1++;
            }

            if(page!=ID_CHECK_PAGE_PLC)
            {
                memDC.SetPen(wxPen(wxColor(172,168,153)));
                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
            }
        }
        else
        {
            r=236;
            g=236;
            b=236;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                r--;
                g--;
                b--;
            }
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
        }
        memDC.DrawLabel(_("倾角仪"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        ///2019-2-19 whq modify
//        x1=x1+w1;
//        checkButton[ID_CHECK_PAGE_DTA].x=x1;
//        checkButton[ID_CHECK_PAGE_DTA].y=y1;
//        checkButton[ID_CHECK_PAGE_DTA].width=w1;
//        checkButton[ID_CHECK_PAGE_DTA].height=h1;
//        if(page==ID_CHECK_PAGE_DTA || motion==ID_CHECK_PAGE_DTA)
//        {
//            r=200;
//            g=225;
//            b=250;
//            for(int j=0;j<h1;j++)
//            {
//                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
//                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
//                //y1++;
//            }
//
//            if(page!=ID_CHECK_PAGE_DTA)
//            {
//                memDC.SetPen(wxPen(wxColor(172,168,153)));
//                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
//            }
//        }
//        else
//        {
//            r=236;
//            g=236;
//            b=236;
//            for(int j=0;j<h1;j++)
//            {
//                memDC.SetPen(wxPen(wxColor(r,g,b)));
//                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
//                r--;
//                g--;
//                b--;
//            }
//            memDC.SetPen(wxPen(wxColor(172,168,153)));
//            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
//        }
//        memDC.DrawLabel(_("中线复核"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
//        memDC.SetPen(wxPen(wxColor(172,168,153)));
//        memDC.DrawLine(x1,y1,x1+w1,y1);
//        memDC.DrawLine(x1,y1,x1,y1+h1);
//
//        x1=x1+w1;
//        checkButton[ID_CHECK_PAGE_ORI].x=x1;
//        checkButton[ID_CHECK_PAGE_ORI].y=y1;
//        checkButton[ID_CHECK_PAGE_ORI].width=w1;
//        checkButton[ID_CHECK_PAGE_ORI].height=h1;
//        if(page==ID_CHECK_PAGE_ORI || motion==ID_CHECK_PAGE_ORI)
//        {
//            r=200;
//            g=225;
//            b=250;
//            for(int j=0;j<h1;j++)
//            {
//                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
//                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
//                //y1++;
//            }
//
//            if(page!=ID_CHECK_PAGE_ORI)
//            {
//                memDC.SetPen(wxPen(wxColor(172,168,153)));
//                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
//            }
//        }
//        else
//        {
//            r=236;
//            g=236;
//            b=236;
//            for(int j=0;j<h1;j++)
//            {
//                memDC.SetPen(wxPen(wxColor(r,g,b)));
//                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
//                r--;
//                g--;
//                b--;
//            }
//            memDC.SetPen(wxPen(wxColor(172,168,153)));
//            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
//        }
//        memDC.DrawLabel(_("初始姿态"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
//        memDC.SetPen(wxPen(wxColor(172,168,153)));
//        memDC.DrawLine(x1,y1,x1+w1,y1);
//        memDC.DrawLine(x1,y1,x1,y1+h1);
//
//        x1=x1+w1;
//        checkButton[ID_CHECK_PAGE_MAN].x=x1;
//        checkButton[ID_CHECK_PAGE_MAN].y=y1;
//        checkButton[ID_CHECK_PAGE_MAN].width=w1;
//        checkButton[ID_CHECK_PAGE_MAN].height=h1;
//        if(page==ID_CHECK_PAGE_MAN || motion==ID_CHECK_PAGE_MAN)
//        {
//            r=200;
//            g=225;
//            b=250;
//            for(int j=0;j<h1;j++)
//            {
//                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
//                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
//                //y1++;
//            }
//            if(page!=ID_CHECK_PAGE_MAN)
//            {
//                memDC.SetPen(wxPen(wxColor(172,168,153)));
//                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
//            }
//        }
//        else
//        {
//            r=236;
//            g=236;
//            b=236;
//            for(int j=0;j<h1;j++)
//            {
//                memDC.SetPen(wxPen(wxColor(r,g,b)));
//                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
//                r--;
//                g--;
//                b--;
//            }
//            memDC.SetPen(wxPen(wxColor(172,168,153)));
//            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
//        }
//        memDC.DrawLabel(_("姿态计算"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
//        memDC.SetPen(wxPen(wxColor(172,168,153)));
//        memDC.DrawLine(x1,y1,x1+w1,y1);
//        memDC.DrawLine(x1,y1,x1,y1+h1);
//
//        x1=x1+w1;
//        checkButton[ID_CHECK_PAGE_POR].x=x1;
//        checkButton[ID_CHECK_PAGE_POR].y=y1;
//        checkButton[ID_CHECK_PAGE_POR].width=w1;
//        checkButton[ID_CHECK_PAGE_POR].height=h1;
//        if(page==ID_CHECK_PAGE_POR || motion==ID_CHECK_PAGE_POR)
//        {
//            r=200;
//            g=225;
//            b=250;
//            for(int j=0;j<h1;j++)
//            {
//                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
//                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
//                //y1++;
//            }
//            if(page!=ID_CHECK_PAGE_POR)
//            {
//                memDC.SetPen(wxPen(wxColor(172,168,153)));
//                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
//            }
//        }
//        else
//        {
//            r=236;
//            g=236;
//            b=236;
//            for(int j=0;j<h1;j++)
//            {
//                memDC.SetPen(wxPen(wxColor(r,g,b)));
//                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
//                r--;
//                g--;
//                b--;
//            }
//            memDC.SetPen(wxPen(wxColor(172,168,153)));
//            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
//        }
//        memDC.DrawLabel(_("洞门计算"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
//        memDC.SetPen(wxPen(wxColor(172,168,153)));
//        memDC.DrawLine(x1,y1,x1+w1,y1);
//        memDC.DrawLine(x1,y1,x1,y1+h1);
//        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        r=236;
        g=236;
        b=236;
        x1=x1+w1;
        for(int j=0;j<h1;j++)
        {
            memDC.SetPen(wxPen(wxColor(r,g,b)));
            memDC.DrawLine(x1,y1+j,w,y1+j);
            r--;
            g--;
            b--;
        }
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,w,y1);
        memDC.DrawLine(x1,y1+h1-1,w,y1+h1-1);
        memDC.DrawLine(x1,y1,x1,y1+h1);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyCheckDlg::OnMotionPage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>checkButton[ID_CHECK_PAGE_TPS].y && y<checkButton[ID_CHECK_PAGE_TPS].y+checkButton[ID_CHECK_PAGE_TPS].height)
    {
        if(x>checkButton[ID_CHECK_PAGE_TPS].x && x<checkButton[ID_CHECK_PAGE_TPS].x+checkButton[ID_CHECK_PAGE_TPS].width)
        {
            motion=ID_CHECK_PAGE_TPS;
        }
        else if(x>checkButton[ID_CHECK_PAGE_TAR].x && x<checkButton[ID_CHECK_PAGE_TAR].x+checkButton[ID_CHECK_PAGE_TAR].width)
        {
            motion=ID_CHECK_PAGE_TAR;
        }
        else if(x>checkButton[ID_CHECK_PAGE_PLC].x && x<checkButton[ID_CHECK_PAGE_PLC].x+checkButton[ID_CHECK_PAGE_PLC].width)
        {
            motion=ID_CHECK_PAGE_PLC;
        }
        else if(x>checkButton[ID_CHECK_PAGE_INC].x && x<checkButton[ID_CHECK_PAGE_INC].x+checkButton[ID_CHECK_PAGE_INC].width)
        {
            motion=ID_CHECK_PAGE_INC;
        }
//        else if(x>checkButton[ID_CHECK_PAGE_DTA].x && x<checkButton[ID_CHECK_PAGE_DTA].x+checkButton[ID_CHECK_PAGE_DTA].width)
//        {
//            motion=ID_CHECK_PAGE_DTA;
//        }
//        else if(x>checkButton[ID_CHECK_PAGE_ORI].x && x<checkButton[ID_CHECK_PAGE_ORI].x+checkButton[ID_CHECK_PAGE_ORI].width)
//        {
//            motion=ID_CHECK_PAGE_ORI;
//        }
//        else if(x>checkButton[ID_CHECK_PAGE_MAN].x && x<checkButton[ID_CHECK_PAGE_MAN].x+checkButton[ID_CHECK_PAGE_MAN].width)
//        {
//            motion=ID_CHECK_PAGE_MAN;
//        }
//        else if(x>checkButton[ID_CHECK_PAGE_POR].x && x<checkButton[ID_CHECK_PAGE_POR].x+checkButton[ID_CHECK_PAGE_POR].width)
//        {
//            motion=ID_CHECK_PAGE_POR;
//        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    else
    {
        motion=ID_CHECK_NONE;
    }
    panelPage->Refresh();
}

void MyCheckDlg::OnLeavePage(wxMouseEvent& event)
{
    motion=ID_CHECK_NONE;
    panelPage->Refresh();
}

void MyCheckDlg::OnClickPage(wxMouseEvent& event)
{
    if(motion==ID_CHECK_PAGE_TPS)
    {
        page=ID_CHECK_PAGE_TPS;
        UpataeTps();
        panelTps->Show(true);
        panelTars->Show(false);
        panelPLC->Show(false);
        panelINC->Show(false);
    }
    else if(motion==ID_CHECK_PAGE_TAR)
    {
        page=ID_CHECK_PAGE_TAR;
        panelTps->Show(false);
        panelTars->Show(true);
        panelPLC->Show(false);
        panelINC->Show(false);
    }
    else if(motion==ID_CHECK_PAGE_PLC)
    {
        page=ID_CHECK_PAGE_PLC;
        panelTps->Show(false);
        panelTars->Show(false);
        panelPLC->Show(true);
        panelINC->Show(false);
    }
    else if(motion==ID_CHECK_PAGE_INC)
    {
        page=ID_CHECK_PAGE_INC;
        UpdateInc();
        panelTps->Show(false);
        panelTars->Show(false);
        panelPLC->Show(false);
        panelINC->Show(true);
    }
    panelPage->Refresh();
}

///
void MyCheckDlg::OnPaintTpsButton(wxPaintEvent& event)
{
    wxPaintDC dc(tpsButton);
    int w,h;
    tpsButton->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        int r1,g1,b1;
        r1=200;
        g1=200;
        b1=200;
        for(int i=0;i<h;i++)
        {
            memDC.SetPen(wxPen(wxColor(r1,g1,b1)));
            memDC.DrawLine(0,i,w,i);
            if(i%3==0)
            {
                if(i<h/2)
                {
                    r1--;
                    g1--;
                    b1--;
                }
                else
                {
                    r1++;
                    g1++;
                    b1++;
                }
            }
        }
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        w1=65;
        h1=26;
        x1=w-w1-14;
        y1=7;
        checkButton[ID_CHECK_CLOSE_LASER].x=x1;
        checkButton[ID_CHECK_CLOSE_LASER].y=y1;
        checkButton[ID_CHECK_CLOSE_LASER].width=w1;
        checkButton[ID_CHECK_CLOSE_LASER].height=h1;
        if(motion==ID_CHECK_CLOSE_LASER)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("关闭激光"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1-w1-7;
        checkButton[ID_CHECK_OPEN_LASER].x=x1;
        checkButton[ID_CHECK_OPEN_LASER].y=y1;
        checkButton[ID_CHECK_OPEN_LASER].width=w1;
        checkButton[ID_CHECK_OPEN_LASER].height=h1;
        if(motion==ID_CHECK_OPEN_LASER)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("打开激光"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawLine(0,h-1,w,h-1);
        memDC.DrawLine(0,0,0,h);
        memDC.DrawLine(w-1,0,w-1,h);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyCheckDlg::OnMotionTpsButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>checkButton[ID_CHECK_OPEN_LASER].y && y<checkButton[ID_CHECK_OPEN_LASER].y+checkButton[ID_CHECK_OPEN_LASER].height)
    {
        if(x>checkButton[ID_CHECK_OPEN_LASER].x && x<checkButton[ID_CHECK_OPEN_LASER].x+checkButton[ID_CHECK_OPEN_LASER].width)
        {
            motion=ID_CHECK_OPEN_LASER;
        }
        else if(x>checkButton[ID_CHECK_CLOSE_LASER].x && x<checkButton[ID_CHECK_CLOSE_LASER].x+checkButton[ID_CHECK_CLOSE_LASER].width)
        {
            motion=ID_CHECK_CLOSE_LASER;
        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    else
    {
        motion=ID_CHECK_NONE;
    }
    tpsButton->Refresh();
}

void MyCheckDlg::OnLeaveTpsButton(wxMouseEvent& event)
{
    motion=ID_CHECK_NONE;
    tpsButton->Refresh();
}

void MyCheckDlg::OnClickTpsButton(wxMouseEvent& event)
{
    if(motion==ID_CHECK_OPEN_LASER)
    {
        mtg_start_laser(mtg);
    }
    else if(motion==ID_CHECK_CLOSE_LASER)
    {
        mtg_stop_laser(mtg);
    }
    ///panelBottom->Refresh();
}

///
void MyCheckDlg::OnPaintIncButton(wxPaintEvent& event)
{
    wxPaintDC dc(incButton);
    int w,h;
    incButton->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        int r1,g1,b1;
        r1=200;
        g1=200;
        b1=200;
        for(int i=0;i<h;i++)
        {
            memDC.SetPen(wxPen(wxColor(r1,g1,b1)));
            memDC.DrawLine(0,i,w,i);
            if(i%3==0)
            {
                if(i<h/2)
                {
                    r1--;
                    g1--;
                    b1--;
                }
                else
                {
                    r1++;
                    g1++;
                    b1++;
                }
            }
        }
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        w1=65;
        h1=26;
        x1=w-w1-14;
        y1=7;
        checkButton[ID_CHECK_INC_OUTPUT].x=x1;
        checkButton[ID_CHECK_INC_OUTPUT].y=y1;
        checkButton[ID_CHECK_INC_OUTPUT].width=w1;
        checkButton[ID_CHECK_INC_OUTPUT].height=h1;
        if(motion==ID_CHECK_INC_OUTPUT)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("导出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1-w1-7;
        checkButton[ID_CHECK_INC_QUERY].x=x1;
        checkButton[ID_CHECK_INC_QUERY].y=y1;
        checkButton[ID_CHECK_INC_QUERY].width=w1;
        checkButton[ID_CHECK_INC_QUERY].height=h1;
        if(motion==ID_CHECK_INC_QUERY)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("查询"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawLine(0,h-1,w,h-1);
        memDC.DrawLine(0,0,0,h);
        memDC.DrawLine(w-1,0,w-1,h);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyCheckDlg::OnMotionIncButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>checkButton[ID_CHECK_INC_QUERY].y && y<checkButton[ID_CHECK_INC_QUERY].y+checkButton[ID_CHECK_INC_QUERY].height)
    {
        if(x>checkButton[ID_CHECK_INC_QUERY].x && x<checkButton[ID_CHECK_INC_QUERY].x+checkButton[ID_CHECK_INC_QUERY].width)
        {
            motion=ID_CHECK_INC_QUERY;
        }
        else if(x>checkButton[ID_CHECK_INC_OUTPUT].x && x<checkButton[ID_CHECK_INC_OUTPUT].x+checkButton[ID_CHECK_INC_OUTPUT].width)
        {
            motion=ID_CHECK_INC_OUTPUT;
        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    else
    {
        motion=ID_CHECK_NONE;
    }
    incButton->Refresh();
}

void MyCheckDlg::OnLeaveIncButton(wxMouseEvent& event)
{
    motion=ID_CHECK_NONE;
    incButton->Refresh();
}

void MyCheckDlg::OnClickIncButton(wxMouseEvent& event)
{
    if(motion==ID_CHECK_INC_QUERY)
    {
        mtg_query_overinfo(mtg);
        UpdateInc();
    }
    else if(motion==ID_CHECK_INC_OUTPUT)
    {
        OutputInc();
//        INC_OVERRUN overinfo;
//        time(&overinfo.t);
//        overinfo.inc0_1[0]=1.0;
//        overinfo.inc0_1[1]=2.0;
//        overinfo.inc0_2[0]=3.0;
//        overinfo.inc0_2[1]=4.0;
//        overinfo.inc_1[0]=5.0;
//        overinfo.inc_1[1]=6.0;
//        overinfo.inc_2[0]=7.0;
//        overinfo.inc_2[1]=8.0;
//        overinfo.diff0[0]=9.0;
//        overinfo.diff0[1]=10.0;
//        overinfo.diff[0]=11.0;
//        overinfo.diff[1]=12.0;
//        if(mtg_store_overinfo(mtg,&overinfo))
//            wxMessageBox(_("chenggong"));
//        else
//            wxMessageBox(_("fail"));
    }
}

///
void MyCheckDlg::OnMotionTarsButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>checkButton[ID_CHECK_EXPORT_IMAGE].y && y<checkButton[ID_CHECK_EXPORT_IMAGE].y+checkButton[ID_CHECK_EXPORT_IMAGE].height)
    {
        if(x>checkButton[ID_CHECK_EXPORT_IMAGE].x && x<checkButton[ID_CHECK_EXPORT_IMAGE].x+checkButton[ID_CHECK_EXPORT_IMAGE].width)
        {
            motion=ID_CHECK_EXPORT_IMAGE;
        }
        else if(x>checkButton[ID_CHECK_INC_START].x && x<checkButton[ID_CHECK_INC_START].x+checkButton[ID_CHECK_INC_START].width)
        {
            motion=ID_CHECK_INC_START;
        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    else
    {
        motion=ID_CHECK_NONE;
    }
    panelTars->Refresh();
}

void MyCheckDlg::OnLeaveTarsButton(wxMouseEvent& event)
{
    motion=ID_CHECK_NONE;
    panelTars->Refresh();
}

void MyCheckDlg::OnClickTarsButton(wxMouseEvent& event)
{
    if(motion==ID_CHECK_EXPORT_IMAGE)
    {
        SaveFile();
    }
    else if(motion==ID_CHECK_INC_START)
    {
        if(mtg->incstat==0)
        {
            if(mtg->thread)
            {
                if(mtg->ithread==MTG_THREAD_CYCLE)
                {
                    ConfirmDlg dlg(this);
                    dlg.confirmMsg=_("确定停止周期测量？");
                    dlg.Center();
                    if(dlg.ShowModal()==wxID_OK)
                    {
                        mtg_stop(mtg);
                    }
                    return;
                }
            }
            if(mtg->iinc)
            {
                mtg->incstat=1;
                panelTars->Refresh();
                WriteMsg(_("获取姿态仪角度中..."),0);
            }
            else
            {
                WriteMsg(_("姿态仪初始化失败无法获取!"),0);
            }
        }
        else
        {
            mtg->incstat=0;
            panelTars->Refresh();
        }
    }
}

#include "wx/dir.h"
#include <wx/filename.h>
#include "direct.h"
void MyCheckDlg::SaveFile()
{
    wxDir dir(path1);
    if(dir.IsOpened())
    {
        int n=0;
        wxArrayString files;
        wxString token=wxT("*.bmp");
        n=dir.GetAllFiles(path1,&files,token,wxDIR_DEFAULT);
        if(n<=0)
        {
            wxMessageBox(wxString::Format(_("无照片数据，不能保存！")));
            return;
        }
        else if(n>5)//超过五张照片需要删除多余的部分
        {
            files.Sort(true);
            //files.RemoveAt(5,n-5);
            for(int i=5;i<n;i++)
            {
                wxRemoveFile(files[i]);
            }
        }
        //wxMessageBox(path1+wxString::Format(_(":%d"),n));
        ///导出压缩包设置
        wxFileDialog fileDlg(this,_("导出文件路径"),wxEmptyString,wxEmptyString,_("工程文件(*.rar)|*.rar"),wxFD_SAVE);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            char cmd[1024];
            wxString dir2=path1+_("*.bmp");
            //wxMessageBox(dir2+wxString::Format(_(":%d"),n));
            sprintf(cmd,"WinRAR.exe a %s -m5 -s -r %s",strFile.mb_str(wxConvLocal),dir2.mb_str(wxConvLocal));
            system(cmd);
        }
    }
}

void MyCheckDlg::UpataeTps()
{
    tpsList->DeleteAllItems();
    int n=mtg->tps.irv;
    wxString istr;

    for(int i=0;i<n;i++)
    {
        if(mtg->tps.rv[i].t<=0) continue;
        tpsList->InsertItem(i,_(""));
        tpsList->SetItem(i,1,wxString::Format(_("%d"),i+1));
        istr=wxString(mtg->tps.rv[i].cmd,wxConvLocal);
        tpsList->SetItem(i,2,istr);
        istr=wxString(mtg->tps.rv[i].ret,wxConvLocal);
        tpsList->SetItem(i,3,istr);
        istr=wxDateTime(mtg->tps.rv[i].t).Format(_("%Y-%m-%d %H:%M:%S"));
        tpsList->SetItem(i,4,istr);
    }
}

void MyCheckDlg::UpdateInc()
{
    if(incList2->GetItemCount()>0)
        incList2->DeleteAllItems();
    for(int i=0;i<mtg->nover;i++)
    {
        incList2->InsertItem(i,wxString::Format(_("%d"),i+1));
        incList2->SetItem(i,1,wxDateTime(mtg->incover[i].t).Format(_("%Y-%m-%d %H:%M:%S")));
        incList2->SetItem(i,2,wxString::Format(_("%.3f"),mtg->incover[i].diff0[0]));
        incList2->SetItem(i,3,wxString::Format(_("%.3f"),mtg->incover[i].diff[0]));
        incList2->SetItem(i,4,wxString::Format(_("%.3f"),mtg->incover[i].diff0[1]));
        incList2->SetItem(i,5,wxString::Format(_("%.3f"),mtg->incover[i].diff[1]));
    }
}

void MyCheckDlg::OutputInc()
{
    int i=0;
    int n=incList2->GetItemCount();
    int selected[1000]={0};
    int nsel=0;
    wxString str;
    wxString strt;
    char path[1024]={0};
    char chtime[256]={0};
    int index=0;

    for(i=0;i<n;i++)
    {
        if(incList2->IsSelected(i))
        {
            selected[nsel]=i;
            nsel++;

            if(nsel>=1000)
                break;
        }
    }
    if(nsel>0)
    {
        wxMessageDialog dlg(this,_("是否导出列表中选中的数据？"),_("提示"), wxOK | wxCANCEL);
        if(dlg.ShowModal()==wxID_OK)
        {
            wxFileDialog dlg1(this,_("请选择保存路径"),_(""),_(""),_("倾角仪超限数据(*.csv)|*.csv"),wxFD_OPEN);
            if(dlg1.ShowModal()==wxID_OK)
            {
                str=dlg1.GetPath();
                strcpy(path,str.mb_str(wxConvLocal));
                FILE* fp=fopen(path,"w");
                if(fp)
                {
                    fprintf(fp,"序号,记录时间,初始滚动角差值,掘进滚动角差值,初始俯仰角差值,掘进俯仰角差值,初始滚动角1,初始滚动角2,初始俯仰角1,初始俯仰角2,掘进滚动角1,掘进滚动角2,掘进俯仰角1,掘进俯仰角2\n");
                    fflush(fp);
                    for(i=0;i<nsel;i++)
                    {
                        index=selected[i];
                        strt=wxDateTime(mtg->incover[index].t).Format(_("%Y-%m-%d %H:%M:%S"));
                        strcpy(chtime,strt.mb_str(wxConvLocal));
                        fprintf(fp,"%d,%s,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n",i+1,chtime,
                                mtg->incover[index].diff0[0],mtg->incover[index].diff[0],mtg->incover[index].diff0[1],mtg->incover[index].diff[1],
                                mtg->incover[index].inc0_1[0],mtg->incover[index].inc0_2[0],mtg->incover[index].inc0_1[1],mtg->incover[index].inc0_2[1],
                                mtg->incover[index].inc_1[0],mtg->incover[index].inc_2[0],mtg->incover[index].inc_1[1],mtg->incover[index].inc_2[1]);
                        fflush(fp);
                    }
                    fclose(fp);
                }
            }
        }
    }
    else
    {
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),_(""),_("倾角仪超限数据(*.csv)|*.csv"),wxFD_OPEN);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            strcpy(path,str.mb_str(wxConvLocal));
            FILE* fp=fopen(path,"w");
            if(fp)
            {
                fprintf(fp,"序号,记录时间,初始滚动角差值,掘进滚动角差值,初始俯仰角差值,掘进俯仰角差值,初始滚动角1,初始滚动角2,初始俯仰角1,初始俯仰角2,掘进滚动角1,掘进滚动角2,掘进俯仰角1,掘进俯仰角2\n");
                fflush(fp);
                for(i=0;i<mtg->nover;i++)
                {
                    strt=wxDateTime(mtg->incover[i].t).Format(_("%Y-%m-%d %H:%M:%S"));
                    strcpy(chtime,strt.mb_str(wxConvLocal));
                    fprintf(fp,"%d,%s,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n",i+1,chtime,
                            mtg->incover[i].diff0[0],mtg->incover[i].diff[0],mtg->incover[i].diff0[1],mtg->incover[i].diff[1],
                            mtg->incover[i].inc0_1[0],mtg->incover[i].inc0_2[0],mtg->incover[i].inc0_1[1],mtg->incover[i].inc0_2[1],
                            mtg->incover[i].inc_1[0],mtg->incover[i].inc_2[0],mtg->incover[i].inc_1[1],mtg->incover[i].inc_2[1]);
                    fflush(fp);
                }
                fclose(fp);
            }
        }
    }
}

void MyCheckDlg::UpataeTarget()
{
    int n=incList->GetItemCount();
    if(n==20)
    {
        incList->DeleteAllItems();
        n=0;
    }
    incList->InsertItem(n,wxString::Format(_("%d"),n+1));
    //incList->SetItem(n,1,wxString::Format(_("%d"),n));
//    incList->SetItem(n,2,wxString::Format(_("%.3f"),mtg->m1.inc1[0]));
//    incList->SetItem(n,3,wxString::Format(_("%.3f"),mtg->m1.inc1[1]));
//    incList->SetItem(n,4,wxString::Format(_("%.3f"),mtg->m1.inc1[2]));
    //double incx1=0.0,incy1=0.0,incx2=0.0,incy2=0.0,delta_incx=0.0,delta_incy=0.0;

    incList->SetItem(n,1,wxString::Format(_("%.3f"),mtg->m.inc[0]));
    incList->SetItem(n,2,wxString::Format(_("%.3f"),mtg->m.inc[1]));
    incList->SetItem(n,3,wxString::Format(_("%.3f"),mtg->m.inc[5]));
    incList->SetItem(n,4,wxString::Format(_("%.3f"),mtg->m.inc[6]));
    if(mtg->m1.t1>0)
    {
        incList->SetItem(n,5,wxString::Format(_("%.3f"),(mtg->m.inc[5]-mtg->m.inc[0])-(mtg->m0.inc[5]-mtg->m0.inc[0])));
        incList->SetItem(n,6,wxString::Format(_("%.3f"),(mtg->m.inc[6]-mtg->m.inc[1])-(mtg->m0.inc[6]-mtg->m0.inc[1])));
    }
    else
    {
        incList->SetItem(n,3,wxString::Format(_("--")));
        incList->SetItem(n,4,wxString::Format(_("--")));
    }
}

void MyCheckDlg::UpataePlc()
{
    if(mtg->plc.drive) plcList->SetItem(0,3,_("掘进中..."));
    else plcList->SetItem(0,3,_("停止"));
    if(mtg->plc.amode) plcList->SetItem(1,3,_("拼装中..."));
    else plcList->SetItem(1,3,_(""));

    plcList->SetItem(2,3,wxString::Format(_("%.1f mm"),mtg->m1.aj[0]));
    plcList->SetItem(3,3,wxString::Format(_("%.1f mm"),mtg->m1.aj[1]));
    plcList->SetItem(4,3,wxString::Format(_("%.1f mm"),mtg->m1.aj[2]));
    plcList->SetItem(5,3,wxString::Format(_("%.1f mm"),mtg->m1.aj[3]));

    plcList->SetItem(6,3,wxString::Format(_("%.1f mm"),mtg->m1.faj[0]));
    plcList->SetItem(7,3,wxString::Format(_("%.1f mm"),mtg->m1.faj[1]));
    plcList->SetItem(8,3,wxString::Format(_("%.1f mm"),mtg->m1.faj[2]));
    plcList->SetItem(9,3,wxString::Format(_("%.1f mm"),mtg->m1.faj[3]));

    plcList->SetItem(10,3,wxString::Format(_("%.1f mm"),mtg->m1.baj[0]));
    plcList->SetItem(11,3,wxString::Format(_("%.1f mm"),mtg->m1.baj[1]));
    plcList->SetItem(12,3,wxString::Format(_("%.1f mm"),mtg->m1.baj[2]));
    plcList->SetItem(13,3,wxString::Format(_("%.1f mm"),mtg->m1.baj[3]));
}

void MyCheckDlg::LoadData()
{
    UpataeTps();
    //UpataeTarget();
}

void MyCheckDlg::OnTimer(wxTimerEvent& event)
{
    static int tick=0;
    int i=0;


    if(mtg->ithread==MTG_THREAD_START_LASER||
       mtg->ithread==MTG_THREAD_CLOSE_LASER||
       mtg->incstat)
    {
        if(mtg->plog > 0)
        {
            wxString strLog;
            for(i=0;i<mtg->plog;i++)
            {
                strLog = wxString(mtg->plogs[i].msg,wxConvLocal);
                WriteMsg(strLog,mtg->plogs[i].type);
                if(mtg->plogs[i].nlog==MTG_LOG_FINISH_GET_INCLINE)
                {
                    UpataeTarget();
                }
            }
        }
    }
    tick++;
    if(tick % 10==0)
    {
        //UpataePlc();
        panelPLC->Refresh();
        panelTars->Refresh();
        //UpataeTarget();

    }
    if(tick==1200) tick=0;
}

void MyCheckDlg::WriteMsg(wxString msg,int col)
{
    m_msg=msg;
    m_msgc=col;
    panelBottom->Refresh();
}
