///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MapViewDlg.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"
#include "confirmdlg.h"
#include "SegDialog.h"
#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#include "dl_dxf.h"


#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MapViewDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MapViewDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MapViewDlg)


const long MapViewDlg::ID_PANEL1 = wxNewId();                  //标题
const long MapViewDlg::ID_PANEL2 = wxNewId();                  //按钮
const long MapViewDlg::ID_BUTTON1 = wxNewId();                 //取消
const long MapViewDlg::ID_BUTTON2 = wxNewId();                 //应用
//*)
const long MapViewDlg::ID_canvas=wxNewId();

MapViewDlg::MapViewDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);
    bmpPam1.LoadFile(path+_("/plugins/fitWindow.png"),wxBITMAP_TYPE_PNG);
    bmpPam2.LoadFile(path+_("/plugins/fitWindow2.png"),wxBITMAP_TYPE_PNG);
    bmpOpen.LoadFile(path+_("/plugins/DXFFile.png"),wxBITMAP_TYPE_PNG);
    bmpPoint1.LoadFile(path+_("/plugins/MapPoint1.png"),wxBITMAP_TYPE_PNG);
    bmpPoint2.LoadFile(path+_("/plugins/MapPoint2.png"),wxBITMAP_TYPE_PNG);
    bmpPoint3.LoadFile(path+_("/plugins/MapPoint3.png"),wxBITMAP_TYPE_PNG);
    bmpPoint4.LoadFile(path+_("/plugins/MapPoint4.png"),wxBITMAP_TYPE_PNG);
    bmpLayer1.LoadFile(path+_("/plugins/layer1.png"),wxBITMAP_TYPE_PNG);
    bmpLayer2.LoadFile(path+_("/plugins/layer2.png"),wxBITMAP_TYPE_PNG);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelTitle = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    //panelTitle->IsMaximinize=1;
    panelTitle->m_maximize_box=1;
    panelTitle->m_minimize_box=1;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("地质地物");
    panelButtonList = new MDButtonList(this, ID_PANEL2, wxPoint(0,31), wxSize(150,h-76), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(150,31), wxSize(w-150,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelNavi = new wxPanel(panelMain, wxID_ANY, wxPoint(600+w,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x1=0;
    y1=11;
    w1=w-150;
    h1=h-88;
    //hmapPanel = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    hmapPanel=new DxfCanvas(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    hmapPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    hmapSetPanel = new wxPanel(hmapPanel, wxID_ANY, wxPoint((w1-675)/2,h1-100), wxSize(675,100), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    hmapSetPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    hmapPointX1Text = new wxMyTextCtrl(hmapSetPanel, wxID_ANY, wxEmptyString, wxPoint(277,45), wxSize(96,19), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    hmapPointY1Text = new wxMyTextCtrl(hmapSetPanel, wxID_ANY, wxEmptyString, wxPoint(377,45), wxSize(96,19), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    hmapPointX2Text = new wxMyTextCtrl(hmapSetPanel, wxID_ANY, wxEmptyString, wxPoint(277,70), wxSize(96,19), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    hmapPointY2Text = new wxMyTextCtrl(hmapSetPanel, wxID_ANY, wxEmptyString, wxPoint(377,70), wxSize(96,19), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    //vmapPanel = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    vmapPanel=new DxfCanvas(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    vmapPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    vmapSetPanel = new wxPanel(vmapPanel, wxID_ANY, wxPoint((w1-675)/2,h1-100), wxSize(675,100), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    vmapSetPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    vmapPointX1Text = new wxMyTextCtrl(vmapSetPanel, wxID_ANY, wxEmptyString, wxPoint(277,45), wxSize(96,19), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    vmapPointY1Text = new wxMyTextCtrl(vmapSetPanel, wxID_ANY, wxEmptyString, wxPoint(377,45), wxSize(96,19), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    vmapPointX2Text = new wxMyTextCtrl(vmapSetPanel, wxID_ANY, wxEmptyString, wxPoint(277,70), wxSize(96,19), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    vmapPointY2Text = new wxMyTextCtrl(vmapSetPanel, wxID_ANY, wxEmptyString, wxPoint(377,70), wxSize(96,19), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);


    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelNavi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapViewDlg::OnPaintBackground,0,this);
	panelNavi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapViewDlg::OnPaintNavi,0,this);

   // hmapPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapViewDlg::OnPaintHmap,0,this);
    hmapPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MapViewDlg::OnMotionHmap,0,this);
    hmapPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapViewDlg::OnLeaveHmap,0,this);
    hmapPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapViewDlg::OnClickHmap,0,this);
    hmapSetPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapViewDlg::OnPaintHmapSets,0,this);
    hmapSetPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MapViewDlg::OnMotionHmapSets,0,this);
    hmapSetPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapViewDlg::OnLeaveHmapSets,0,this);
    hmapSetPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapViewDlg::OnClickHmapSets,0,this);

    vmapSetPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapViewDlg::OnPaintVmapSets,0,this);
    vmapSetPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MapViewDlg::OnMotionVmapSets,0,this);
    vmapSetPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapViewDlg::OnLeaveVmapSets,0,this);
    vmapSetPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapViewDlg::OnClickVmapSets,0,this);

  //  vmapPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapViewDlg::OnPaintVmap,0,this);
    vmapPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MapViewDlg::OnMotionVmap,0,this);
    vmapPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapViewDlg::OnLeaveVmap,0,this);
    vmapPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapViewDlg::OnClickVmap,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapViewDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MapViewDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapViewDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapViewDlg::OnClickBottom,0,this);

    panelButtonList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapViewDlg::OnButtonClick,0,this);

    this->Connect(wxEVT_SIZE,(wxObjectEventFunction)&MapViewDlg::OnSize,0,this);

    Connect(wxEVT_TIMER,(wxObjectEventFunction)&MapViewDlg::OnTimer);
    timerStat.SetOwner(this);
    timerStat.Start(100,false);
    //*)

    //DxfCanvas* canvas;
    //canvas=new DxfCanvas(hmapPanel, ID_canvas, wxPoint(0,0),wxSize(600,400), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //canvas->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //mycHorizon=new MyCreation(&HorizonMap);

    this->SetBackgroundColour(wxColor(245,248,250));

    panelButtonList->btn_height=27;
    panelButtonList->AddButton(_("平面视图"));
    panelButtonList->AddButton(_("地质视图"));
    panelButtonList->btn_clicked=0;

    cross_cursor=wxCursor(wxCURSOR_CROSS);
    stand_cursor=wxCursor(wxCURSOR_ARROW);

    motion=ID_MAP_NONE;
    pushed=ID_MAP_NONE;

    hx1=hy1=hx10=hy10=hx2=hy2=hx20=hy20=0;
    vx1=vy1=vx10=vy10=vx2=vy2=vx20=vy20=0;
    LoadData();
    if(panelButtonList->btn_clicked==0)
    {
        vmapPanel->SetSize(1024,11,w,h);
        hmapPanel->SetSize(0,11,w-150,h-88);
    }
    else if(panelButtonList->btn_clicked==1)
    {
        hmapPanel->SetSize(1024,11,w,h);
        vmapPanel->SetSize(0,11,w-150,h-88);
    }
    PointDlg1=new PointDialog(this);
    PointDlg2=new PointDialog(this);
    PointDlg1->ok=0;
    PointDlg2->ok=0;
}

MapViewDlg::~MapViewDlg()
{

}

void MapViewDlg::OnButtonClick(wxMouseEvent& event)
{
    int btn = panelButtonList->btn_left_down;
    int w,h;
    hmapPanel->GetClientSize(&w,&h);
    switch(btn)
    {
    case 0:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        vmapPanel->SetSize(w*2,11,w,h);
        hmapPanel->SetSize(0,11,w,h);
        hmapPanel->EventFlag=pushed;
        break;
    case 1:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        hmapPanel->SetSize(w*2,11,w,h);
        vmapPanel->SetSize(0,11,w,h);
        vmapPanel->EventFlag=pushed;
        break;
    default:
        break;
    }
}

void MapViewDlg::OnSize(wxSizeEvent& event)
{
    int w,h;
    GetSize(&w,&h);
    int x1,y1,w1,h1;
    x1=0;
    y1=11;
    w1=w-150;
    h1=h-88;
    panelBottom->SetSize(0,h-45,w,45);
    panelMain->SetSize(150,31,w-150,h-76);
    panelNavi->SetSize(600+w,10,160,h-90);
    panelButtonList->SetSize(0,31,150,h-76);

    if(panelButtonList->btn_clicked==0)
    {
        hmapPanel->SetSize(0,11,w1,h1);
        //hmapPanel->FitAll();
        vmapPanel->SetSize(w,11,w1,h1);
        //vmapPanel->FitAll();
        hmapPanel->Refresh();
    }
    else
    {
        vmapPanel->SetSize(0,11,w1,h1);
        //vmapPanel->FitAll();
        hmapPanel->SetSize(w,11,w1,h1);
        //hmapPanel->FitAll();
        vmapPanel->Refresh();
    }
    hmapSetPanel->SetSize((w1-675)/2,h1-100,675,100);
    vmapSetPanel->SetSize((w1-675)/2,h1-100,675,100);

    panelTitle->SetSize(0,0,w,31);
    panelTitle->Refresh();
    panelBottom->Refresh();
    panelMain->Refresh();
    panelNavi->Refresh();
    panelButtonList->Refresh();
}

void MapViewDlg::OnPaintHmap(wxPaintEvent& event)
{
    wxPaintDC dc(hmapPanel);
    int w,h;
    hmapPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        //memDC.SetPen(wxPen(wxColor(255,0,0)));

        //memDC.DrawCircle(w/2,h/2,50);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
    event.Skip();
}

void MapViewDlg::OnMotionHmap(wxMouseEvent& event)
{
    motion=ID_MAP_HMAP;
    //hmapPanel->Refresh();
   event.Skip();
}

void MapViewDlg::OnLeaveHmap(wxMouseEvent& event)
{
    motion=ID_MAP_NONE;
    //hmapPanel->Refresh();
    event.Skip();
}

void MapViewDlg::OnClickHmap(wxMouseEvent& event)
{
    if(pushed==ID_MAP_HPOINT1)
    {
        int x,y;
        x=event.GetX();
        y=event.GetY();
        hmapPanel->GetMapXY(x,y,&cli->mapset[0].dx[0],&cli->mapset[0].dy[0]);

        hmapPanel->DrawCross();
    }
    else if(pushed==ID_MAP_HPOINT2)
    {
        int x,y;
        x=event.GetX();
        y=event.GetY();
        hmapPanel->GetMapXY(x,y,&cli->mapset[0].dx[2],&cli->mapset[0].dy[2]);
        hmapPanel->DrawCross();
    }
    else
    {
        event.Skip();
    }
    hmapPanel->Refresh();
}

void MapViewDlg::OnPaintHmapSets(wxPaintEvent& event)
{
    wxPaintDC dc(hmapSetPanel);
    int w,h;
    hmapSetPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(169,169,169)));
        memDC.SetBrush(wxBrush(wxColor(240,240,240)));
        memDC.DrawRectangle(0,0,w,h+1);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(103,103,103));
        int x1,y1,w1,h1;
        x1=0;
        y1=40;
        w1=w/2;
        h1=25;

        memDC.DrawLabel(_("点位"),wxRect(x1,0,75,40),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("起点"),wxRect(x1,y1,75,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("终点"),wxRect(x1,y1+h1,75,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLine(x1+75,0,x1+75,40);
        memDC.DrawLabel(_("原始坐标"),wxRect(x1+75,0,200,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+275,0,x1+275,40);
        memDC.DrawLine(x1+75,20,x1+275,20);
        memDC.DrawLabel(_("北坐标(X)"),wxRect(x1+75,20,100,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("东坐标(Y)"),wxRect(x1+175,20,100,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+175,20,x1+175,40);

        memDC.DrawLabel(_("实际坐标"),wxRect(x1+275,0,200,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+475,0,x1+475,40);
        memDC.DrawLine(x1+275,20,x1+475,20);
        memDC.DrawLabel(_("北坐标(X)"),wxRect(x1+275,20,100,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("东坐标(Y)"),wxRect(x1+375,20,100,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+375,20,x1+375,40);
        memDC.DrawLabel(_("定位"),wxRect(x1+475,0,100,40),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+575,0,x1+575,40);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(75,y1,500,h1*2);

        memDC.SetPen(wxPen(wxColor(169,169,169)));
        memDC.DrawLine(0,y1,575,y1);
        memDC.DrawLine(0,y1+h1,575,y1+h1);
        memDC.DrawLine(0,y1+h1*2,575,y1+h1*2);

        memDC.DrawLine(75,y1,75,y1+h1*2);
        memDC.DrawLine(175,y1,175,y1+h1*2);
        memDC.DrawLine(275,y1,275,y1+h1*2);
        memDC.DrawLine(375,y1,375,y1+h1*2);
        memDC.DrawLine(475,y1,475,y1+h1*2);
        memDC.DrawLine(575,y1,575,y1+h1*2);

        x1=590;
        y1=7;
        w1=65;
        h1=25;
        mapButton[ID_MAP_HFILE].x=x1;
        mapButton[ID_MAP_HFILE].y=y1;
        mapButton[ID_MAP_HFILE].width=w1;
        mapButton[ID_MAP_HFILE].height=h1;
        if(motion==ID_MAP_HFILE)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(wxColor(103,103,103));
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("打开"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1+8;
        h1=25;
        mapButton[ID_MAP_HSET].x=x1;
        mapButton[ID_MAP_HSET].y=y1;
        mapButton[ID_MAP_HSET].width=w1;
        mapButton[ID_MAP_HSET].height=h1;
        if(motion==ID_MAP_HSET)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(wxColor(103,103,103));
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("设置"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=475;
        y1=40;
        w1=100;
        h1=25;
        mapButton[ID_MAP_HPOINT1].x=x1;
        mapButton[ID_MAP_HPOINT1].y=y1;
        mapButton[ID_MAP_HPOINT1].width=w1;
        mapButton[ID_MAP_HPOINT1].height=h1;
        memDC.SetBrush(btnBrush[0]);
        if(pushed==ID_MAP_HPOINT1)
        {
            memDC.SetPen(btnPen[2]);
            memDC.DrawCircle(x1+w1/2,y1+h1/2+1,h1*2/5);
        }
        else if(motion==ID_MAP_HPOINT1)
        {
            memDC.SetPen(btnPen[0]);
            memDC.DrawCircle(x1+w1/2,y1+h1/2+1,h1*2/5);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
        }

        memDC.DrawLine(x1+w1/2,y1+h1/2-4,x1+w1/2,y1+h1/2+6);
        memDC.DrawLine(x1+w1/2-5,y1+h1/2+1,x1+w1/2+5,y1+h1/2+1);

        y1=65;
        mapButton[ID_MAP_HPOINT2].x=x1+2;
        mapButton[ID_MAP_HPOINT2].y=y1+2;
        mapButton[ID_MAP_HPOINT2].width=w1-4;
        mapButton[ID_MAP_HPOINT2].height=h1-4;
        if(pushed==ID_MAP_HPOINT2)
        {
            memDC.SetPen(btnPen[2]);
            memDC.DrawCircle(x1+w1/2,y1+h1/2+1,h1*2/5);
        }
        else if(motion==ID_MAP_HPOINT2)
        {
            memDC.SetPen(btnPen[0]);
            memDC.DrawCircle(x1+w1/2,y1+h1/2+1,h1*2/5);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
        }

        memDC.DrawLine(x1+w1/2,y1+h1/2-4,x1+w1/2,y1+h1/2+6);
        memDC.DrawLine(x1+w1/2-5,y1+h1/2+1,x1+w1/2+5,y1+h1/2+1);

        x1=75;
        w1=100;
        y1=40;
        h1=25;
        memDC.SetTextForeground(wxColor(103,103,103));
        memDC.DrawLabel(wxString::Format(_("%.4f"),cli->mapset[0].dx[0]),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%.4f"),cli->mapset[0].dy[0]),wxRect(x1+w1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%.4f"),cli->mapset[0].dx[2]),wxRect(x1,y1+h1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%.4f"),cli->mapset[0].dy[2]),wxRect(x1+w1,y1+h1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        //y1+=h1;
        //h1=25;
       //

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MapViewDlg::OnMotionHmapSets(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>mapButton[ID_MAP_HPOINT1].x && x<mapButton[ID_MAP_HPOINT1].x+mapButton[ID_MAP_HPOINT1].width)
    {
        if(y>mapButton[ID_MAP_HPOINT1].y && y<mapButton[ID_MAP_HPOINT1].y+mapButton[ID_MAP_HPOINT1].height)
        {
            motion=ID_MAP_HPOINT1;
        }
        else if(y>mapButton[ID_MAP_HPOINT2].y && y<mapButton[ID_MAP_HPOINT2].y+mapButton[ID_MAP_HPOINT2].height)
        {
            motion=ID_MAP_HPOINT2;
        }
        else
        {
            motion=ID_MAP_NONE;
        }
    }
    else if(x>mapButton[ID_MAP_HFILE].x && x<mapButton[ID_MAP_HFILE].x+mapButton[ID_MAP_HFILE].width)
    {
        if(y>mapButton[ID_MAP_HFILE].y && y<mapButton[ID_MAP_HFILE].y+mapButton[ID_MAP_HFILE].height)
        {
            motion=ID_MAP_HFILE;
        }
        else if(y>mapButton[ID_MAP_HSET].y && y<mapButton[ID_MAP_HSET].y+mapButton[ID_MAP_HSET].height)
        {
            motion=ID_MAP_HSET;
        }
        else
        {
            motion=ID_MAP_NONE;
        }
    }
    else
    {
        motion=ID_MAP_NONE;
    }
    hmapSetPanel->Refresh();
}

void MapViewDlg::OnLeaveHmapSets(wxMouseEvent& event)
{
    motion=ID_MAP_NONE;
    hmapSetPanel->Refresh();
}

void MapViewDlg::OnClickHmapSets(wxMouseEvent& event)
{
    if(motion==ID_MAP_HFILE)
    {
        wxFileDialog dlg(this,_("选择平面图文件"),wxEmptyString,wxEmptyString,_("平面图文件(*.DXF)|*.DXF"),wxFD_OPEN);
        dlg.Center();
        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str=dlg.GetPath();
            string hstr=std::string(str.mb_str());

            wxStandardPaths wsp;
            wxString hstr2=wsp.GetDataDir()+wxString(_("\\data"));
            if(!wxFileName::FileExists(hstr2))
            {
                wxMkDir(hstr2);
            }
            wxString hstr1=wsp.GetDataDir()+wxString(_("\\data\\Horizon.dxf"));
            if(str.compare(hstr1))
            {

                if(wxFileName::FileExists(hstr1))
                {
                    int rs1;
                    rs1=wxMessageBox(_("是否用该文件替换已存的文件？"),_("提示"),wxYES|wxNO);
                    if(rs1==wxYES)
                    {
                        wxCopyFile(str,hstr1,true);
                        hx1=hy1=hx10=hy10=hx2=hy2=hx20=hy20=0;
                        cli->mapset[0].dx[0]=0;
                        cli->mapset[0].dy[0]=0;
                        cli->mapset[0].dx[1]=0;
                        cli->mapset[0].dy[1]=0;
                        cli->mapset[0].dx[2]=0;
                        cli->mapset[0].dy[2]=0;
                        cli->mapset[0].dx[3]=0;
                        cli->mapset[0].dy[3]=0;

                        int rs;
                        hmapPanel->Clear();
                        //HorizonMap.Clear();
                        PointDlg1->ok=0;
                        rs=hmapPanel->filein(hstr);
                        //mtg_store_mapset(cli,0);
                    }
                }
                else
                {
                    hx1=hy1=hx10=hy10=hx2=hy2=hx20=hy20=0;
                    wxCopyFile(str,hstr1,true);
                    int rs;
                    rs=hmapPanel->filein(hstr);
                    //mtg_store_mapset(cli,0);
                }
            }
        }
    }
    else if(motion==ID_MAP_HPOINT1)
    {
        if(pushed==ID_MAP_HPOINT1)
        {
            pushed=ID_MAP_NONE;
        }
        else
        {
            pushed=ID_MAP_HPOINT1;
        }
    }
    else if(motion==ID_MAP_HPOINT2)
    {
        if(pushed==ID_MAP_HPOINT2)
        {
            pushed=ID_MAP_NONE;
        }
        else
        {
            pushed=ID_MAP_HPOINT2;
        }
    }
    else if(motion==ID_MAP_HSET)
    {
        wxString valstr;
        double val;
        valstr=hmapPointX1Text->GetValue();
        if(!valstr.IsEmpty())
        {
            valstr.ToDouble(&val);
            cli->mapset[0].dx[1]=val;
        }
        else
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("起点坐标不能为空");
            dlg.type=1;

            if(dlg.ShowModal()==wxID_OK)
            {
                return;
            }

        }
        valstr=hmapPointY1Text->GetValue();
        if(!valstr.IsEmpty())
        {
            valstr.ToDouble(&val);
            cli->mapset[0].dy[1]=val;
        }
        else
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("起点坐标不能为空");
            dlg.type=1;

            if(dlg.ShowModal()==wxID_OK)
            {
                return;
            }
        }
        valstr=hmapPointX2Text->GetValue();
        if(!valstr.IsEmpty())
        {
            valstr.ToDouble(&val);
            cli->mapset[0].dx[3]=val;
        }
        else
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("终点坐标不能为空");
            dlg.type=1;

            if(dlg.ShowModal()==wxID_OK)
            {
                return;
            }
        }
        valstr=hmapPointY2Text->GetValue();
        if(!valstr.IsEmpty())
        {
            valstr.ToDouble(&val);
            cli->mapset[0].dy[3]=val;
        }
        else
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("终点坐标不能为空");
            dlg.type=1;

            if(dlg.ShowModal()==wxID_OK)
            {
                return;
            }
        }
        //mtg_store_mapset(cli,0);
    }
    hmapSetPanel->Refresh();
}

void MapViewDlg::OnPaintVmapSets(wxPaintEvent& event)
{
    wxPaintDC dc(vmapSetPanel);
    int w,h;
    vmapSetPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(169,169,169)));
        memDC.SetBrush(wxBrush(wxColor(240,240,240)));
        memDC.DrawRectangle(0,0,w,h+1);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(103,103,103));
        int x1,y1,w1,h1;
        x1=0;
        y1=40;
        w1=w/2;
        h1=25;

        memDC.DrawLabel(_("点位"),wxRect(x1,0,75,40),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("起点"),wxRect(x1,y1,75,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("终点"),wxRect(x1,y1+h1,75,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLine(x1+75,0,x1+75,40);
        memDC.DrawLabel(_("原始坐标"),wxRect(x1+75,0,200,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+275,0,x1+275,40);
        memDC.DrawLine(x1+75,20,x1+275,20);
        memDC.DrawLabel(_("里程(L)"),wxRect(x1+75,20,100,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("高程(H)"),wxRect(x1+175,20,100,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+175,20,x1+175,40);

        memDC.DrawLabel(_("实际坐标"),wxRect(x1+275,0,200,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+475,0,x1+475,40);
        memDC.DrawLine(x1+275,20,x1+475,20);
        memDC.DrawLabel(_("里程(L)"),wxRect(x1+275,20,100,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("高程(H)"),wxRect(x1+375,20,100,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+375,20,x1+375,40);
        memDC.DrawLabel(_("定位"),wxRect(x1+475,0,100,40),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+575,0,x1+575,40);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(75,y1,500,h1*2);

        memDC.SetPen(wxPen(wxColor(169,169,169)));
        memDC.DrawLine(0,y1,575,y1);
        memDC.DrawLine(0,y1+h1,575,y1+h1);
        memDC.DrawLine(0,y1+h1*2,575,y1+h1*2);

        memDC.DrawLine(75,y1,75,y1+h1*2);
        memDC.DrawLine(175,y1,175,y1+h1*2);
        memDC.DrawLine(275,y1,275,y1+h1*2);
        memDC.DrawLine(375,y1,375,y1+h1*2);
        memDC.DrawLine(475,y1,475,y1+h1*2);
        memDC.DrawLine(575,y1,575,y1+h1*2);

        x1=590;
        y1=7;
        w1=65;
        h1=25;
        mapButton[ID_MAP_VFILE].x=x1;
        mapButton[ID_MAP_VFILE].y=y1;
        mapButton[ID_MAP_VFILE].width=w1;
        mapButton[ID_MAP_VFILE].height=h1;
        if(motion==ID_MAP_VFILE)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(wxColor(103,103,103));
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("打开"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1+8;
        h1=25;
        mapButton[ID_MAP_VSET].x=x1;
        mapButton[ID_MAP_VSET].y=y1;
        mapButton[ID_MAP_VSET].width=w1;
        mapButton[ID_MAP_VSET].height=h1;
        if(motion==ID_MAP_VSET)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(wxColor(103,103,103));
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("设置"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=475;
        y1=40;
        w1=100;
        h1=25;
        mapButton[ID_MAP_VPOINT1].x=x1;
        mapButton[ID_MAP_VPOINT1].y=y1;
        mapButton[ID_MAP_VPOINT1].width=w1;
        mapButton[ID_MAP_VPOINT1].height=h1;
        memDC.SetBrush(btnBrush[0]);
        if(pushed==ID_MAP_VPOINT1)
        {
            memDC.SetPen(btnPen[2]);
            memDC.DrawCircle(x1+w1/2,y1+h1/2+1,h1*2/5);
        }
        else if(motion==ID_MAP_VPOINT1)
        {
            memDC.SetPen(btnPen[0]);
            memDC.DrawCircle(x1+w1/2,y1+h1/2+1,h1*2/5);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
        }

        memDC.DrawLine(x1+w1/2,y1+h1/2-4,x1+w1/2,y1+h1/2+6);
        memDC.DrawLine(x1+w1/2-5,y1+h1/2+1,x1+w1/2+5,y1+h1/2+1);

        y1=65;
        mapButton[ID_MAP_VPOINT2].x=x1+2;
        mapButton[ID_MAP_VPOINT2].y=y1+2;
        mapButton[ID_MAP_VPOINT2].width=w1-4;
        mapButton[ID_MAP_VPOINT2].height=h1-4;
        if(pushed==ID_MAP_VPOINT2)
        {
            memDC.SetPen(btnPen[2]);
            memDC.DrawCircle(x1+w1/2,y1+h1/2+1,h1*2/5);
        }
        else if(motion==ID_MAP_VPOINT2)
        {
            memDC.SetPen(btnPen[0]);
            memDC.DrawCircle(x1+w1/2,y1+h1/2+1,h1*2/5);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
        }

        memDC.DrawLine(x1+w1/2,y1+h1/2-4,x1+w1/2,y1+h1/2+6);
        memDC.DrawLine(x1+w1/2-5,y1+h1/2+1,x1+w1/2+5,y1+h1/2+1);

        x1=75;
        w1=100;
        y1=40;
        h1=25;
        memDC.SetTextForeground(wxColor(103,103,103));
        memDC.DrawLabel(wxString::Format(_("%.4f"),cli->mapset[1].dx[0]),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%.4f"),cli->mapset[1].dy[0]),wxRect(x1+w1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%.4f"),cli->mapset[1].dx[2]),wxRect(x1,y1+h1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%.4f"),cli->mapset[1].dy[2]),wxRect(x1+w1,y1+h1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MapViewDlg::OnMotionVmapSets(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>mapButton[ID_MAP_VPOINT1].x && x<mapButton[ID_MAP_VPOINT1].x+mapButton[ID_MAP_VPOINT1].width)
    {
        if(y>mapButton[ID_MAP_VPOINT1].y && y<mapButton[ID_MAP_VPOINT1].y+mapButton[ID_MAP_VPOINT1].height)
        {
            motion=ID_MAP_VPOINT1;
        }
        else if(y>mapButton[ID_MAP_VPOINT2].y && y<mapButton[ID_MAP_VPOINT2].y+mapButton[ID_MAP_VPOINT2].height)
        {
            motion=ID_MAP_VPOINT2;
        }
        else
        {
            motion=ID_MAP_NONE;
        }
    }
    else if(x>mapButton[ID_MAP_VFILE].x && x<mapButton[ID_MAP_VFILE].x+mapButton[ID_MAP_VFILE].width)
    {
        if(y>mapButton[ID_MAP_VFILE].y && y<mapButton[ID_MAP_VFILE].y+mapButton[ID_MAP_VFILE].height)
        {
            motion=ID_MAP_VFILE;
        }
        else if(y>mapButton[ID_MAP_VSET].y && y<mapButton[ID_MAP_VSET].y+mapButton[ID_MAP_VSET].height)
        {
            motion=ID_MAP_VSET;
        }
        else
        {
            motion=ID_MAP_NONE;
        }
    }
    else
    {
        motion=ID_MAP_NONE;
    }
    vmapSetPanel->Refresh();
}

void MapViewDlg::OnLeaveVmapSets(wxMouseEvent& event)
{
    motion=ID_MAP_NONE;
    vmapSetPanel->Refresh();
}

void MapViewDlg::OnClickVmapSets(wxMouseEvent& event)
{
    if(motion==ID_MAP_VFILE)
    {
        wxFileDialog dlg(this,_("选择地质图文件"),wxEmptyString,wxEmptyString,_("地质图文件(*.DXF)|*.DXF"),wxFD_OPEN);
        dlg.Center();
        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str=dlg.GetPath();
            string vstr=std::string(str.mb_str());

            wxStandardPaths wsp;
            wxString vstr2=wsp.GetDataDir()+wxString(_("\\data"));
            if(!wxFileName::FileExists(vstr2))
            {
                wxMkDir(vstr2);
            }
            wxString vstr1=wsp.GetDataDir()+wxString(_("\\data\\Horizon.dxf"));
            if(str.compare(vstr1))
            {

                if(wxFileName::FileExists(vstr1))
                {
                    int rs1;
                    rs1=wxMessageBox(_("是否用该文件替换已存的文件？"),_("提示"),wxYES|wxNO);
                    if(rs1==wxYES)
                    {
                        wxCopyFile(str,vstr1,true);
                        vx1=vy1=vx10=vy10=vx2=vy2=vx20=vy20=0;
                        cli->mapset[1].dx[0]=0;
                        cli->mapset[1].dy[0]=0;
                        cli->mapset[1].dx[1]=0;
                        cli->mapset[1].dy[1]=0;
                        cli->mapset[1].dx[2]=0;
                        cli->mapset[1].dy[2]=0;
                        cli->mapset[1].dx[3]=0;
                        cli->mapset[1].dy[3]=0;

                        int rs;
                        vmapPanel->Clear();
                        //HorizonMap.Clear();
                        PointDlg1->ok=0;
                        rs=vmapPanel->filein(vstr);
                        //mtg_store_mapset(cli,1);
                    }
                }
                else
                {
                    vx1=vy1=vx10=vy10=vx2=vy2=vx20=vy20=0;
                    wxCopyFile(str,vstr1,true);
                    int rs;
                    rs=vmapPanel->filein(vstr);
                    //mtg_store_mapset(cli,1);
                }
            }
        }
    }
    else if(motion==ID_MAP_VPOINT1)
    {
        if(pushed==ID_MAP_VPOINT1)
        {
            pushed=ID_MAP_NONE;
        }
        else
        {
            pushed=ID_MAP_VPOINT1;
        }
    }
    else if(motion==ID_MAP_VPOINT2)
    {
        if(pushed==ID_MAP_VPOINT2)
        {
            pushed=ID_MAP_NONE;
        }
        else
        {
            pushed=ID_MAP_VPOINT2;
        }
    }
    else if(motion==ID_MAP_VSET)
    {
        wxString valstr;
        double val;
        valstr=vmapPointX1Text->GetValue();
        if(!valstr.IsEmpty())
        {
            valstr.ToDouble(&val);
            cli->mapset[1].dx[1]=val;
        }
        else
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("起点坐标不能为空");
            dlg.type=1;

            if(dlg.ShowModal()==wxID_OK)
            {
                return;
            }

        }
        valstr=vmapPointY1Text->GetValue();
        if(!valstr.IsEmpty())
        {
            valstr.ToDouble(&val);
            cli->mapset[1].dy[1]=val;
        }
        else
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("起点坐标不能为空");
            dlg.type=1;

            if(dlg.ShowModal()==wxID_OK)
            {
                return;
            }
        }
        valstr=vmapPointX2Text->GetValue();
        if(!valstr.IsEmpty())
        {
            valstr.ToDouble(&val);
            cli->mapset[1].dx[3]=val;
        }
        else
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("终点坐标不能为空");
            dlg.type=1;

            if(dlg.ShowModal()==wxID_OK)
            {
                return;
            }
        }
        valstr=vmapPointY2Text->GetValue();
        if(!valstr.IsEmpty())
        {
            valstr.ToDouble(&val);
            cli->mapset[1].dy[3]=val;
        }
        else
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("终点坐标不能为空");
            dlg.type=1;

            if(dlg.ShowModal()==wxID_OK)
            {
                return;
            }
        }
        //mtg_store_mapset(cli,1);
    }
    vmapSetPanel->Refresh();
}

void MapViewDlg::OnPaintVmap(wxPaintEvent& event)
{
    wxPaintDC dc(vmapPanel);
    int w,h;
    vmapPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x1,y1,w1,h1;

        y1=9;
        w1=48;
        h1=26;
        x1=w/2-w1*3/2;

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
    event.Skip();
}

void MapViewDlg::OnMotionVmap(wxMouseEvent& event)
{
    motion=ID_MAP_VMAP;
    //vmapPanel->Refresh();
    event.Skip();
}

void MapViewDlg::OnLeaveVmap(wxMouseEvent& event)
{
    motion=ID_MAP_NONE;
    //vmapPanel->Refresh();
    event.Skip();
}

void MapViewDlg::OnClickVmap(wxMouseEvent& event)
{
    if(pushed==ID_MAP_VPOINT1)
    {
        int x,y;
        x=event.GetX();
        y=event.GetY();
        vmapPanel->GetMapXY(x,y,&cli->mapset[1].dx[0],&cli->mapset[1].dy[0]);

        vmapPanel->DrawCross();
    }
    else if(pushed==ID_MAP_VPOINT2)
    {
        int x,y;
        x=event.GetX();
        y=event.GetY();
        vmapPanel->GetMapXY(x,y,&cli->mapset[1].dx[2],&cli->mapset[1].dy[2]);
        vmapPanel->DrawCross();
    }
    else
    {
        event.Skip();
    }
    vmapPanel->Refresh();
}

void MapViewDlg::OnPaintBottom(wxPaintEvent& event)
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
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x1,y1,w1,h1;
        int w2,h2;
        memDC.SetPen(wxPen(wxColor(117,117,117)));

        y1=9;
        w1=48;
        h1=28;
        x1=w/2-w1*3/2;

        mapButton[ID_MAP_ZOOM_OUT].x=x1+1;
        mapButton[ID_MAP_ZOOM_OUT].y=y1+1;
        mapButton[ID_MAP_ZOOM_OUT].width=w1-1;
        mapButton[ID_MAP_ZOOM_OUT].height=h1-2;

        mapButton[ID_MAP_ZOOM_PAM].x=x1+w1+1;
        mapButton[ID_MAP_ZOOM_PAM].y=y1+1;
        mapButton[ID_MAP_ZOOM_PAM].width=w1-1;
        mapButton[ID_MAP_ZOOM_PAM].height=h1-2;

        mapButton[ID_MAP_ZOOM_IN].x=x1+w1*2+1;
        mapButton[ID_MAP_ZOOM_IN].y=y1+1;
        mapButton[ID_MAP_ZOOM_IN].width=w1-2;
        mapButton[ID_MAP_ZOOM_IN].height=h1-2;

        memDC.DrawRectangle(x1,y1,w1*3,h1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLine(x1+w1*2,y1,x1+w1*2,y1+h1);

        if(pushed==ID_MAP_ZOOM_OUT || motion==ID_MAP_ZOOM_OUT)
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(mapButton[ID_MAP_ZOOM_OUT]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }

        memDC.DrawLabel(_("+"),mapButton[ID_MAP_ZOOM_OUT],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        int x2,y2;
        x2=mapButton[ID_MAP_ZOOM_PAM].x;
        y2=mapButton[ID_MAP_ZOOM_PAM].y;
        w2=mapButton[ID_MAP_ZOOM_PAM].width;
        h2=mapButton[ID_MAP_ZOOM_PAM].height;
        if(motion==ID_MAP_ZOOM_PAM)
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(mapButton[ID_MAP_ZOOM_PAM]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawLabel(_("口"),mapButton[ID_MAP_ZOOM_PAM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        if(pushed==ID_MAP_ZOOM_IN || motion==ID_MAP_ZOOM_IN)
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(mapButton[ID_MAP_ZOOM_IN]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawLabel(_("-"),mapButton[ID_MAP_ZOOM_IN],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        w1=65;
        x1=w-w1-12;
        mapButton[ID_MAP_BTN_QUIT].x=x1;
        mapButton[ID_MAP_BTN_QUIT].y=y1;
        mapButton[ID_MAP_BTN_QUIT].width=w1;
        mapButton[ID_MAP_BTN_QUIT].height=h1;
        if(motion==ID_MAP_BTN_QUIT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("退出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MapViewDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>mapButton[ID_MAP_BTN_QUIT].y && y<mapButton[ID_MAP_BTN_QUIT].y+mapButton[ID_MAP_BTN_QUIT].height)
    {
        if(x>mapButton[ID_MAP_BTN_QUIT].x && x<mapButton[ID_MAP_BTN_QUIT].x+mapButton[ID_MAP_BTN_QUIT].width)
        {
            motion=ID_MAP_BTN_QUIT;
        }
        else if(x>mapButton[ID_MAP_ZOOM_IN].x && x<mapButton[ID_MAP_ZOOM_IN].x+mapButton[ID_MAP_ZOOM_IN].width)
        {
            motion=ID_MAP_ZOOM_IN;
        }
        else if(x>mapButton[ID_MAP_ZOOM_OUT].x && x<mapButton[ID_MAP_ZOOM_OUT].x+mapButton[ID_MAP_ZOOM_OUT].width)
        {
            motion=ID_MAP_ZOOM_OUT;
        }
        else if(x>mapButton[ID_MAP_ZOOM_PAM].x && x<mapButton[ID_MAP_ZOOM_PAM].x+mapButton[ID_MAP_ZOOM_PAM].width)
        {
            motion=ID_MAP_ZOOM_PAM;
        }
        else if(x>mapButton[ID_MAP_OPEN].x && x<mapButton[ID_MAP_OPEN].x+mapButton[ID_MAP_OPEN].width)
        {
            motion=ID_MAP_OPEN;
        }
        else if(x>mapButton[ID_MAP_POINT1].x && x<mapButton[ID_MAP_POINT1].x+mapButton[ID_MAP_POINT1].width)
        {
            motion=ID_MAP_POINT1;
        }
        else if(x>mapButton[ID_MAP_POINT2].x && x<mapButton[ID_MAP_POINT2].x+mapButton[ID_MAP_POINT2].width)
        {
            motion=ID_MAP_POINT2;
        }
        else if(x>mapButton[ID_MAP_LAYER].x && x<mapButton[ID_MAP_LAYER].x+mapButton[ID_MAP_LAYER].width)
        {
            motion=ID_MAP_LAYER;
        }
        else
        {
            motion=ID_MAP_NONE;
        }
    }
    else
    {
        motion=ID_MAP_NONE;
    }
    panelBottom->Refresh();
}

void MapViewDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_MAP_NONE;
    panelBottom->Refresh();
}

void MapViewDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_MAP_BTN_QUIT)
    {
        Destroy();
    }
    else
    {
        if(motion==ID_MAP_ZOOM_IN)
        {
            if(pushed==ID_MAP_ZOOM_IN)
            {
                pushed=ID_MAP_NONE;
            }
            else
            {
                pushed=ID_MAP_ZOOM_IN;

//                ///实现缩小
//                wxMouseEvent evt(wxEVT_MOUSEWHEEL);
//                int w,h;
//                if(panelButtonList->btn_clicked==0)
//                {
//                    hmapPanel->GetClientSize(&w,&h);
//                    hmapPanel->eventDet=-1;
//                    wxPostEvent(hmapPanel,evt);
//                }
//                else if(panelButtonList->btn_clicked==1)
//                {
//                    vmapPanel->GetClientSize(&w,&h);
//                    vmapPanel->eventDet=-1;
//                    wxPostEvent(vmapPanel,evt);
//                }
            }

        }
        else if(motion==ID_MAP_ZOOM_OUT)
        {
            if(pushed==ID_MAP_ZOOM_OUT)
            {
                pushed=ID_MAP_NONE;
            }
            else
            {
                pushed=ID_MAP_ZOOM_OUT;
//                ///实现缩小
//                wxMouseEvent evt(wxEVT_MOUSEWHEEL);
//                int w,h;
//                if(panelButtonList->btn_clicked==0)
//                {
//                    hmapPanel->GetClientSize(&w,&h);
//                    hmapPanel->eventDet=1;
//                    wxPostEvent(hmapPanel,evt);
//                }
//                else if(panelButtonList->btn_clicked==1)
//                {
//                    vmapPanel->GetClientSize(&w,&h);
//                    vmapPanel->eventDet=1;
//                    wxPostEvent(vmapPanel,evt);
//                }
            }
        }
        else if(motion==ID_MAP_ZOOM_PAM)
        {
            //if(pushed==ID_MAP_ZOOM_PAM)
            //{
            //    pushed=ID_MAP_NONE;
            //}
           // else
           // {
                pushed=ID_MAP_ZOOM_PAM;
                if(panelButtonList->btn_clicked==0)
                {
                    hmapPanel->Calculate(hx1,hy1,hx10,hy10,hx2,hy2,hx20,hy20);
                    //hmapPanel->FitAll();
                }
                else if(panelButtonList->btn_clicked==1)
                {
                    //vmapPanel->FitAll();
                    vmapPanel->Calculate(vx1,vy1,vx10,vy10,vx2,vy2,vx20,vy20);
                    //vmapPanel->Calculate(5200.7268,-2646.6759,5165.7268,-2646.6759,5700.074,-2513.37820,5595.074,-2513.37820);
                }
                pushed=ID_MAP_NONE;
           // }
        }
        else if(motion==ID_MAP_POINT1)
        {
            if(pushed==ID_MAP_POINT1)
            {
                /*pushed=ID_MAP_NONE;
                if(panelButtonList->btn_clicked==0)
                {
                    PointDlg1->Show(false);
                }
                else if(panelButtonList->btn_clicked==1)
                {
                    PointDlg2->Show(false);

                }*/
            }
            else
            {
                pushed=ID_MAP_POINT1;
                //wxCursor down_cursor = wxCursor(wxCROSS_CURSOR);

                //hmapPanel->cursor_type=1;
                //wxMessageBox(_("ok"));
                //hmapPanel->SetCursor(wxCURSOR_ARROW);
                //hmapPanel->Refresh();
                if(panelButtonList->btn_clicked==0)
                {
                    PointDlg1->flag=0;
                    PointDlg1->x0=cli->mapset[0].dx[0];
                    PointDlg1->y0=cli->mapset[0].dy[0];
                    PointDlg1->x=cli->mapset[0].dx[1];
                    PointDlg1->y=cli->mapset[0].dy[1];
                    PointDlg1->Init();
                    PointDlg1->Show();
                }
                else if(panelButtonList->btn_clicked==1)
                {
                    PointDlg2->flag=0;
                    PointDlg2->x0=cli->mapset[1].dx[0];
                    PointDlg2->y0=cli->mapset[1].dy[0];
                    PointDlg2->x=cli->mapset[1].dx[1];
                    PointDlg2->y=cli->mapset[1].dy[1];
                    PointDlg2->Init();
                    PointDlg2->Show();
                }
            }
        }
        else if(motion==ID_MAP_POINT2)
        {
            if(pushed==ID_MAP_POINT2)
            {
                pushed=ID_MAP_NONE;
                if(panelButtonList->btn_clicked==0)
                {
                    PointDlg1->Show(false);
                }
                else if(panelButtonList->btn_clicked==1)
                {
                    PointDlg2->Show(false);
                }
            }
            else
            {
                pushed=ID_MAP_POINT2;
                if(panelButtonList->btn_clicked==0)
                {
                    PointDlg1->flag=1;
                    PointDlg1->x0=cli->mapset[0].dx[2];
                    PointDlg1->y0=cli->mapset[0].dy[2];
                    PointDlg1->x=cli->mapset[0].dx[3];
                    PointDlg1->y=cli->mapset[0].dy[3];
                    PointDlg1->Init();
                    PointDlg1->Show();
                }
                else if(panelButtonList->btn_clicked==1)
                {
                    PointDlg2->flag=1;
                    PointDlg2->x0=cli->mapset[1].dx[2];
                    PointDlg2->y0=cli->mapset[1].dy[2];
                    PointDlg2->x=cli->mapset[1].dx[3];
                    PointDlg2->y=cli->mapset[1].dy[3];
                    PointDlg2->Init();
                    PointDlg2->Show();
                }
            }
        }
        else if(motion==ID_MAP_OPEN)
        {
            if(panelButtonList->btn_clicked==0)
            {
                wxFileDialog dlg(this,_("选择平面图文件"),wxEmptyString,wxEmptyString,_("平面图文件(*.DXF)|*.DXF"),wxFD_OPEN);
                dlg.Center();
                if(dlg.ShowModal()==wxID_OK)
                {
                    wxString str=dlg.GetPath();
                    string hstr=std::string(str.mb_str());

                    wxStandardPaths wsp;
                    wxString hstr2=wsp.GetDataDir()+wxString(_("\\data"));
                    if(!wxFileName::FileExists(hstr2))
                    {
                        wxMkDir(hstr2);
                    }
                    wxString hstr1=wsp.GetDataDir()+wxString(_("\\data\\Horizon.dxf"));
                    if(str.compare(hstr1))
                    {

                        if(wxFileName::FileExists(hstr1))
                        {
                            int rs1;
                            rs1=wxMessageBox(_("是否用该文件替换已存的文件？"),_("提示"),wxYES|wxNO);
                            if(rs1==wxYES)
                            {
                                wxCopyFile(str,hstr1,true);
                                hx1=hy1=hx10=hy10=hx2=hy2=hx20=hy20=0;
                                cli->mapset[0].dx[0]=0;
                                cli->mapset[0].dy[0]=0;
                                cli->mapset[0].dx[1]=0;
                                cli->mapset[0].dy[1]=0;
                                cli->mapset[0].dx[2]=0;
                                cli->mapset[0].dy[2]=0;
                                cli->mapset[0].dx[3]=0;
                                cli->mapset[0].dy[3]=0;

                                int rs;
                                hmapPanel->Clear();
                                //HorizonMap.Clear();
                                PointDlg1->ok=0;
                                rs=hmapPanel->filein(hstr);
                                //mtg_store_mapset(cli,0);
                            }
                        }
                        else
                        {
						    hx1=hy1=hx10=hy10=hx2=hy2=hx20=hy20=0;
                            wxCopyFile(str,hstr1,true);
                            int rs;
                            rs=hmapPanel->filein(hstr);
                            //mtg_store_mapset(cli,0);
                        }
                    }

                }
            }
            else if(panelButtonList->btn_clicked==1)
            {
                wxFileDialog dlg(this,_("选择地质图文件"),wxEmptyString,wxEmptyString,_("纵断面图文件(*.DXF)|*.DXF"),wxFD_OPEN);
                dlg.Center();
                if(dlg.ShowModal()==wxID_OK)
                {
                    wxString str=dlg.GetPath();
                    string vstr=std::string(str.mb_str());

                    wxStandardPaths wsp;
                    wxString vstr2=wsp.GetDataDir()+wxString(_("\\data"));
                    if(!wxFileName::FileExists(vstr2))
                    {
                        wxMkDir(vstr2);
                    }
                    wxString vstr1=wsp.GetDataDir()+wxString(_("\\data\\Vertical.dxf"));
                    if(str.compare(vstr1))
                    {

                        if(wxFileName::FileExists(vstr1))
                        {
                            int rs1;
                            rs1=wxMessageBox(_("是否用该文件替换已存的文件？"),_("提示"),wxYES|wxNO);
                            if(rs1==wxYES)
                            {
                                wxCopyFile(str,vstr1,true);
                                vx1=vy1=vx10=vy10=vx2=vy2=vx20=vy20=0;
                                cli->mapset[1].dx[0]=0;
                                cli->mapset[1].dy[0]=0;
                                cli->mapset[1].dx[1]=0;
                                cli->mapset[1].dy[1]=0;
                                cli->mapset[1].dx[2]=0;
                                cli->mapset[1].dy[2]=0;
                                cli->mapset[1].dx[3]=0;
                                cli->mapset[1].dy[3]=0;
                                int rs;
                                vmapPanel->Clear();
                                //VerticalMap.Clear();
                                PointDlg2->ok=0;
                                rs=vmapPanel->filein(vstr);
                                //mtg_store_mapset(cli,1);
                            }
                        }
                        else
                        {
						    vx1=vy1=vx10=vy10=vx2=vy2=vx20=vy20=0;
                            wxCopyFile(str,vstr1,true);
                            int rs;
                            rs=vmapPanel->filein(vstr);
                            //mtg_store_mapset(cli,1);
                        }
                    }
                }
            }
        }
        else if(motion==ID_MAP_LAYER)
        {
            if(pushed==ID_MAP_LAYER)
            {
                pushed=ID_MAP_NONE;
            }
        }

        if(panelButtonList->btn_clicked==0)
        {
            hmapPanel->EventFlag=pushed;
        }
        else if(panelButtonList->btn_clicked==1)
        {
            vmapPanel->EventFlag=pushed;
        }
        panelBottom->Refresh();
        hmapPanel->UpdateView();
    }
}

void MapViewDlg::LoadData()
{
    wxStandardPaths wsp;
    wxString hstr=wsp.GetDataDir()+wxString(_("\\data\\Horizon.dxf"));
    wxString vstr=wsp.GetDataDir()+wxString(_("\\data\\Vertical.dxf"));
    string hstr1=std::string(hstr.mb_str());
    string vstr1=std::string(vstr.mb_str());

    int rsh=hmapPanel->filein(hstr1);
    if(rsh)
    {
        hx10=cli->mapset[0].dx[0];
        hy10=cli->mapset[0].dy[0];
        hx1=cli->mapset[0].dx[1];
        hy1=cli->mapset[0].dy[1];
        hx20=cli->mapset[0].dx[2];
        hy20=cli->mapset[0].dy[2];
        hx2=cli->mapset[0].dx[3];
        hy2=cli->mapset[0].dy[3];

        ///hmapPanel->Calculate(530173.1271,379432.3348,530173.1271,379432.3348,530083.1694,379475.2692,530083.1694,379475.2692);
        hmapPanel->Calculate(hx1,hy1,hx10,hy10,hx2,hy2,hx20,hy20);
        //wxMessageBox(wxT("平曲线打开成功"));
    }

    int rsv=vmapPanel->filein(vstr1);
    if(rsv)
    {
        vx10=cli->mapset[1].dx[0];
        vy10=cli->mapset[1].dy[0];
        vx1=cli->mapset[1].dx[1];
        vy1=cli->mapset[1].dy[1];
        vx20=cli->mapset[1].dx[2];
        vy20=cli->mapset[1].dy[2];
        vx2=cli->mapset[1].dx[3];
        hy2=cli->mapset[1].dy[3];
        vmapPanel->Calculate(vx1,vy1,vx10,vy10,vx2,vy2,vx20,vy20);
        //vmapPanel->Calculate(5200.7268,-2646.6759,5165.7268,-2646.6759,5700.074,-2513.37820,5595.074,-2513.37820);
        //wxMessageBox(wxT("地质图打开成功"));
    }
}

void MapViewDlg::OnPaintBackground(wxPaintEvent& event)
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
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(0,10,w,10);
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MapViewDlg::OnPaintNavi(wxPaintEvent& event)
{
    wxPaintDC dc(panelNavi);
    int w,h;
    panelNavi->GetClientSize(&w,&h);

    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(0,-1,w,h+1);
}

void MapViewDlg::rotatemap()
{
    if(panelButtonList->btn_clicked==0)
    {
        if(PointDlg1->flag==0)
        {
            hx10=PointDlg1->x0;
            hy10=PointDlg1->y0;
            hx1=PointDlg1->x;
            hy1=PointDlg1->y;

            cli->mapset[0].dx[0]=PointDlg1->x0;
            cli->mapset[0].dy[0]=PointDlg1->y0;
            cli->mapset[0].dx[1]=PointDlg1->x;
            cli->mapset[0].dy[1]=PointDlg1->y;
        }
        else if(PointDlg1->flag==1)
        {
            hx20=PointDlg1->x0;
            hy20=PointDlg1->y0;
            hx2=PointDlg1->x;
            hy2=PointDlg1->y;
            cli->mapset[0].dx[2]=PointDlg1->x0;
            cli->mapset[0].dy[2]=PointDlg1->y0;
            cli->mapset[0].dx[3]=PointDlg1->x;
            cli->mapset[0].dy[3]=PointDlg1->y;
        }
        //mtg_store_mapset(cli,0);
        if(PointDlg1->ok==3)
        {
            hmapPanel->Calculate(hx1,hy1,hx10,hy10,hx2,hy2,hx20,hy20);
        }
        else if(PointDlg1->ok==2)
            wxMessageBox(_("起点坐标未输入"));
        else if(PointDlg1->ok==1)
            wxMessageBox(_("终点坐标未输入"));
        else if(PointDlg1->ok==0)
            wxMessageBox(_("起点和终点坐标未输入"));
    }
    else if(panelButtonList->btn_clicked==1)
    {
        if(PointDlg1->flag==0)
        {
            vx10=PointDlg2->x0;
            vy10=PointDlg2->y0;
            vx1=PointDlg2->x;
            vy1=PointDlg2->y;

            cli->mapset[1].dx[0]=PointDlg2->x0;
            cli->mapset[1].dy[0]=PointDlg2->y0;
            cli->mapset[1].dx[1]=PointDlg2->x;
            cli->mapset[1].dy[1]=PointDlg2->y;
        }
        else if(PointDlg1->flag==1)
        {
            vx20=PointDlg2->x0;
            vy20=PointDlg2->y0;
            vx2=PointDlg2->x;
            vy2=PointDlg2->y;
            cli->mapset[1].dx[2]=PointDlg2->x0;
            cli->mapset[1].dy[2]=PointDlg2->y0;
            cli->mapset[1].dx[3]=PointDlg2->x;
            cli->mapset[1].dy[3]=PointDlg2->y;
        }
        //mtg_store_mapset(cli,1);
        if(PointDlg2->ok==3)
            vmapPanel->Calculate(vx1,vy1,vx10,vy10,vx2,vy2,vx20,vy20);
        else if(PointDlg2->ok==2)
            wxMessageBox(_("起点坐标未输入"));
        else if(PointDlg2->ok==1)
            wxMessageBox(_("终点坐标未输入"));
        else if(PointDlg2->ok==0)
            wxMessageBox(_("起点和终点坐标未输入"));
    }
}

void MapViewDlg::cancel()
{
    pushed=ID_MAP_NONE;
    if(panelButtonList->btn_clicked==0)
    {
        hmapPanel->EventFlag=pushed;
    }
    else if(panelButtonList->btn_clicked==1)
    {
        vmapPanel->EventFlag=pushed;
    }
}


void MapViewDlg::OnTimer(wxTimerEvent& event)
{
    if(panelButtonList->btn_clicked==0)
    {
        if(hmapPanel->point_complete==1)
        {
            if(PointDlg1->flag==0)//起点
            {
                hx10=hmapPanel->LeftX;
                hy10=hmapPanel->LeftY;
            }
            else if(PointDlg1->flag==1)
            {
                hx20=hmapPanel->LeftX;
                hy20=hmapPanel->LeftY;
            }
            PointDlg1->x0=hmapPanel->LeftX;
            PointDlg1->y0=hmapPanel->LeftY;
            PointDlg1->Init();
            hmapPanel->point_complete=0;
        }
    }
    else if(panelButtonList->btn_clicked==1)
    {
        if(vmapPanel->point_complete==1)
        {
            if(PointDlg2->flag==0)//起点
            {
                vx10=vmapPanel->LeftX;
                vy10=vmapPanel->LeftY;
            }
            else if(PointDlg2->flag==1)
            {
                vx20=vmapPanel->LeftX;
                vy20=vmapPanel->LeftY;
            }
            PointDlg2->x0=vmapPanel->LeftX;
            PointDlg2->y0=vmapPanel->LeftY;
            PointDlg2->Init();
            vmapPanel->point_complete=0;
        }
    }
}
