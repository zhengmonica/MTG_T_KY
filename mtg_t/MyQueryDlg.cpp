///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyQueryDlg.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"
#include "confirmdlg.h"
#include "SegDialog.h"
#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MyQueryDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MyQueryDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MyQueryDlg)


const long MyQueryDlg::ID_PANEL1 = wxNewId();                  //标题
const long MyQueryDlg::ID_PANEL2 = wxNewId();                  //按钮
const long MyQueryDlg::ID_BUTTON1 = wxNewId();                 //取消
const long MyQueryDlg::ID_BUTTON2 = wxNewId();                 //应用
//*)

MyQueryDlg::MyQueryDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int dh=20;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelTitle = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelTitle->IsMaximinize=0;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("历史数据");
    panelButtonList = new MDButtonList(this, ID_PANEL2, wxPoint(0,31), wxSize(150,h-76), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(150,31), wxSize(w-150,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelNavi = new wxPanel(panelMain, wxID_ANY, wxPoint(600+w,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x1=0;
    y1=11;
    w1=w-150;
    h1=h-88;
    panelGridHead = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelGridHead->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //historyGid = new wxGrid(panelGridHead, wxID_ANY, wxPoint(1,41), wxSize(w1-2,h1-41), 0, _T("wxID_ANY"));
    qryList = new wxListView(panelGridHead, wxID_ANY, wxPoint(0,40), wxSize(w1+1,h1-39), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelGraph = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelGraph->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelZoom = new wxPanel(panelGraph, wxID_ANY, wxPoint(w1/2-72,h1-48), wxSize(144,32), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelZoom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelChart = new wxPanel(panelGraph, wxID_ANY, wxPoint(42,90), wxSize(w1-99,h1-240), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelChart->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    queryValue1 = new wxMyTextCtrl(panelBottom, wxID_ANY, wxEmptyString, wxPoint(303,11), wxSize(118,-1), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER,wxDefaultValidator);
    queryValue2 = new wxMyTextCtrl(panelBottom, wxID_ANY, wxEmptyString, wxPoint(421,11), wxSize(118,-1), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER,wxDefaultValidator);

    btnCancel = new wxButton(panelBottom, ID_BUTTON1, _("退 出"), wxPoint(w-90,7), wxSize(80,32), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btnApply = new wxButton(panelBottom, ID_BUTTON2, _("应 用"), wxPoint(w-175,7), wxSize(80,32), 0, wxDefaultValidator, _T("ID_BUTTON2"));

    btnCancel->Show(false);
    btnApply->Show(false);

    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelNavi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintBackground,0,this);
	panelNavi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintNavi,0,this);

    panelGridHead->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintGridHead,0,this);

    panelGraph->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintGraph,0,this);
    panelGraph->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyQueryDlg::OnMotionGraph,0,this);
    panelGraph->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyQueryDlg::OnLeaveGraph,0,this);
    panelGraph->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyQueryDlg::OnClickGraph,0,this);

    panelChart->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintChart,0,this);

    panelZoom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintZoom,0,this);
    panelZoom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyQueryDlg::OnMotionZoom,0,this);
    panelZoom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyQueryDlg::OnLeaveZoom,0,this);
    panelZoom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyQueryDlg::OnClickZoom,0,this);


    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyQueryDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyQueryDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyQueryDlg::OnClickBottom,0,this);

    panelButtonList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyQueryDlg::OnButtonClick,0,this);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyQueryDlg::OnQuit);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyQueryDlg::OnApply);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    panelButtonList->btn_height=27;
    panelButtonList->AddButton(_("姿态数据"));
    panelButtonList->AddButton(_("偏差曲线"));
    panelButtonList->btn_clicked=0;

    int i=0;
    /*historyGid->CreateGrid( 1, 10 );
    historyGid->EnableEditing( false );
	historyGid->EnableGridLines( true );
	historyGid->EnableDragGridSize( false );

	historyGid->EnableDragColMove( false );
	historyGid->EnableDragColSize( true );
	historyGid->SetColLabelSize( 0 );

	historyGid->EnableDragRowSize( true );
	historyGid->SetRowLabelSize( 0 );
	historyGid->SetDefaultRowSize(20);
    historyGid->SetSelectionMode(wxGrid::wxGridSelectRows);
    //historyGid->SetSelectionBackground(wxColor(186,186,186));
	historyGid->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
    //historyGid->InsertCols(1,7);

	historyGid->SetColSize(i++,55);       ///环号
	historyGid->SetColSize(i++,90);      ///里程
	historyGid->SetColSize(i++,55);      ///切口平偏
	historyGid->SetColSize(i++,55);      ///盾尾平偏
	historyGid->SetColSize(i++,55);      ///切口高偏
	historyGid->SetColSize(i++,55);      ///盾尾高偏
	historyGid->SetColSize(i++,65);      ///转动角
	historyGid->SetColSize(i++,65);      ///俯仰角
	historyGid->SetColSize(i++,75);      ///方位角
	historyGid->SetColSize(i++,150);     ///时间
    */
    i=0;
    qryList->InsertColumn(i++,_("环号"),wxLIST_FORMAT_CENTRE,55);
    qryList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_LEFT,90);
    qryList->InsertColumn(i++,_("切口平偏"),wxLIST_FORMAT_CENTRE,55);
    qryList->InsertColumn(i++,_("盾尾平偏"),wxLIST_FORMAT_CENTRE,55);
    qryList->InsertColumn(i++,_("切口高偏"),wxLIST_FORMAT_CENTRE,55);
    qryList->InsertColumn(i++,_("盾尾高偏"),wxLIST_FORMAT_CENTRE,55);
    qryList->InsertColumn(i++,_("转动角"),wxLIST_FORMAT_CENTRE,65);
    qryList->InsertColumn(i++,_("俯仰角"),wxLIST_FORMAT_CENTRE,65);
    qryList->InsertColumn(i++,_("方位角"),wxLIST_FORMAT_CENTRE,75);
    qryList->InsertColumn(i++,_("时间"),wxLIST_FORMAT_CENTRE,150);

    motion=QRY_POS_NONE;
    qryMethod=QRY_POS_QRY_METHOD_SEG;
    viewMethod=QRY_POS_QRY_VIEW_DITAIL;

    qres1=0;
    nq1=0;

    qres2=0;
    nq2=0;

    perL=20;
    zoom=0;

    viewHeadh=1;
    viewHeadv=1;
    viewTailh=1;
    viewTailv=1;
    LoadData();
}

MyQueryDlg::~MyQueryDlg()
{

}

void MyQueryDlg::OnApply(wxCommandEvent& event)
{

}

void MyQueryDlg::OnQuit(wxCommandEvent& event)
{
    Destroy();
}

void MyQueryDlg::OnButtonClick(wxMouseEvent& event)
{
    int btn = panelButtonList->btn_left_down;
    int w,h;
    panelGridHead->GetClientSize(&w,&h);
    switch(btn)
    {
    case 0:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelGraph->SetSize(1024,11,w,h);
        panelGridHead->SetSize(0,11,w,h);
        break;
    case 1:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelGridHead->SetSize(1024,11,w,h);
        panelGraph->SetSize(0,11,w,h);
        break;
    default:
        break;
    }
    panelBottom->Refresh();
}

void MyQueryDlg::OnPaintGridHead(wxPaintEvent& event)
{
    wxPaintDC dc(panelGridHead);
    int w,h;
    panelGridHead->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(239,239,239)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;
        int x2,w2;
        int i=0;
        x1=0;
        y1=0;
        h1=40;
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(0,y1+h1,w,y1+h1);
        w1=qryList->GetColumnWidth(i++);
        //w1=historyGid->GetColSize(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        //w1=historyGid->GetColSize(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        //w1=historyGid->GetColSize(i++);
        memDC.DrawLine(x1+w1,y1+h1/2,x1+w1,y1+h1);
        memDC.DrawLabel(_("切口"),wxRect(x1,y1+h1/2,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x2=x1;
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        //w1=historyGid->GetColSize(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("盾尾"),wxRect(x1,y1+h1/2,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("平面偏差(mm)"),wxRect(x2,y1,w1*2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x2,y1+h1/2,x1+w1,y1+h1/2);
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        //w1=historyGid->GetColSize(i++);
        memDC.DrawLine(x1+w1,y1+h1/2,x1+w1,y1+h1);
        memDC.DrawLabel(_("切口"),wxRect(x1,y1+h1/2,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x2=x1;
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        //w1=historyGid->GetColSize(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("盾尾"),wxRect(x1,y1+h1/2,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("垂直偏差(mm)"),wxRect(x2,y1,w1*2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x2,y1+h1/2,x1+w1,y1+h1/2);
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        //w1=historyGid->GetColSize(i++);
        memDC.DrawLine(x1+w1,y1+h1/2,x1+w1,y1+h1);
        memDC.DrawLabel(_("转动角"),wxRect(x1,y1+h1/2,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x2=x1;
        w2=w1;
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        //w1=historyGid->GetColSize(i++);
        memDC.DrawLine(x1+w1,y1+h1/2,x1+w1,y1+h1);
        memDC.DrawLabel(_("俯仰角"),wxRect(x1,y1+h1/2,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        w2+=w1;
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        //w1=historyGid->GetColSize(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("方位角"),wxRect(x1,y1+h1/2,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("盾构姿态(°)"),wxRect(x2,y1,w2+w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x2,y1+h1/2,x1+w1,y1+h1/2);
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        //w1=historyGid->GetColSize(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("日期"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyQueryDlg::OnPaintChart(wxPaintEvent& event)
{
    wxPaintDC dc(panelChart);
    int w,h;
    panelChart->GetSize(&w,&h);
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

        int x1=0;
        int y1=h/2;
        int w1=w;
        int h1=h/6;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1-3*h1,x1,y1+3*h1);
        memDC.SetPen(wxPen(wxColor(158,158,158),1,wxDOT));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        memDC.DrawLine(x1,y1+h1*2,x1+w1,y1+h1*2);
        memDC.DrawLine(x1,y1+h1*3,x1+w1,y1+h1*3);
        memDC.DrawLine(x1,y1-h1,x1+w1,y1-h1);
        memDC.DrawLine(x1,y1-h1*2,x1+w1,y1-h1*2);
        memDC.DrawLine(x1,y1-h1*3,x1+w1,y1-h1*3);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyQueryDlg::OnMotionGraph(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>qryButton[QRY_POS_GRAPH_HEADH].y && y<qryButton[QRY_POS_GRAPH_HEADH].y+qryButton[QRY_POS_GRAPH_HEADH].height)
    {
        if(x>qryButton[QRY_POS_GRAPH_HEADH].x && x<qryButton[QRY_POS_GRAPH_HEADH].x+qryButton[QRY_POS_GRAPH_HEADH].width)
        {
            motion=QRY_POS_GRAPH_HEADH;
        }
        else if(x>qryButton[QRY_POS_GRAPH_HEADV].x && x<qryButton[QRY_POS_GRAPH_HEADV].x+qryButton[QRY_POS_GRAPH_HEADV].width)
        {
            motion=QRY_POS_GRAPH_HEADV;
        }
        else if(x>qryButton[QRY_POS_GRAPH_TAILH].x && x<qryButton[QRY_POS_GRAPH_TAILH].x+qryButton[QRY_POS_GRAPH_TAILH].width)
        {
            motion=QRY_POS_GRAPH_TAILH;
        }
        else if(x>qryButton[QRY_POS_GRAPH_TAILV].x && x<qryButton[QRY_POS_GRAPH_TAILV].x+qryButton[QRY_POS_GRAPH_TAILV].width)
        {
            motion=QRY_POS_GRAPH_TAILV;
        }
        else
        {
            motion=QRY_POS_NONE;
        }
    }
    else
    {
        motion=QRY_POS_NONE;
    }
    panelGraph->Refresh();
}

void MyQueryDlg::OnLeaveGraph(wxMouseEvent& event)
{
    motion=QRY_POS_NONE;
    panelGraph->Refresh();
}

void MyQueryDlg::OnClickGraph(wxMouseEvent& event)
{
    if(motion==QRY_POS_GRAPH_HEADH)
    {
        if(viewHeadh==1) viewHeadh=0;
        else viewHeadh=1;
    }
    else if(motion==QRY_POS_GRAPH_HEADV)
    {
        if(viewHeadv==1) viewHeadv=0;
        else viewHeadv=1;
    }
    else if(motion==QRY_POS_GRAPH_TAILH)
    {
        if(viewTailh==1) viewTailh=0;
        else viewTailh=1;
    }
    else if(motion==QRY_POS_GRAPH_TAILV)
    {
        if(viewTailv==1) viewTailv=0;
        else viewTailv=1;
    }
    panelGraph->Refresh();
}

void MyQueryDlg::OnPaintGraph(wxPaintEvent& event)
{
    wxPaintDC dc(panelGraph);
    int w,h;
    int a2z=cli->prj.a2z;

    panelGraph->GetSize(&w,&h);
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
        wxFont eni(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));

        int x1,y1,w1,h1;
        panelChart->GetPosition(&x1,&y1);
        panelChart->GetSize(&w1,&h1);

        //memDC.DrawLabel(_("姿态偏差曲线"),wxRect(x1,y1/8,w1,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1*1/3,w1,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1*2/3,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("日期时间"),wxRect(x1+w1/2,y1*1/3,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        double mile[6]={0};
        memDC.SetFont(eni);
        if(viewMethod==QRY_POS_QRY_VIEW_DITAIL)
        {
            if(nq1>0)
            {
                memDC.DrawLabel(wxString::Format(_("%d"),qres1[0].iseg)+_(" ～ ")+wxString::Format(_("%d"),qres1[nq1-1].iseg),wxRect(x1+60,y1*1/3,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%.3f"),qres1[0].headc)+_(" ～ ")+wxString::Format(_("%.3f"),qres1[nq1-1].headc),wxRect(x1+60,y1*2/3,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxDateTime(qres1[0].t1).Format(_("%Y-%m-%d %H:%M:%S"))+_(" ～ ")+wxDateTime(qres1[nq1-1].t1).Format(_("%Y-%m-%d %H:%M:%S")),wxRect(x1+w1/2+60,y1*1/3,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                mile[0]=qres1[nq1-1].headc;
                for(int i=1;i<6;i++)
                {
                    mile[i]=mile[0]+4.0*i*a2z;
                }
            }
        }
        else
        {
            if(nq2>0)
            {
                memDC.DrawLabel(wxString::Format(_("%d"),qres2[0].iseg)+_(" ～ ")+wxString::Format(_("%d"),qres2[nq2-1].iseg),wxRect(x1+60,y1*1/3,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%.3f"),qres2[0].headc)+_(" ～ ")+wxString::Format(_("%.3f"),qres2[nq2-1].headc),wxRect(x1+60,y1*2/3,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxDateTime(qres2[0].t1).Format(_("%Y-%m-%d %H:%M:%S"))+_(" ～ ")+wxDateTime(qres2[nq2-1].t1).Format(_("%Y-%m-%d %H:%M:%S")),wxRect(x1+w1/2+60,y1*1/3,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                mile[0]=qres2[nq2-1].headc;
                for(int i=1;i<6;i++)
                {
                    mile[i]=mile[0]+4.0*i*a2z;
                }
            }
        }

        //y1=y1+h1/2;
        int dw,dh;
        dh=h1/6;
        memDC.DrawLabel(_("0"),wxRect(x1-5,y1+h1/2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(1*perL)),wxRect(x1-5,y1+h1/2-dh,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(2*perL)),wxRect(x1-5,y1+h1/2-dh*2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(3*perL)),wxRect(x1-5,y1+h1/2-dh*3,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(-1*perL)),wxRect(x1-5,y1+h1/2+dh,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(-2*perL)),wxRect(x1-5,y1+h1/2+dh*2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(-3*perL)),wxRect(x1-5,y1+h1/2+dh*3,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        dw=w1/6;
        for(int i=0;i<6;i++)
        {
            memDC.DrawLine(x1+dw*i,y1+h1+7,x1+dw*i,y1+h1+15);
            memDC.DrawLabel(wxString::Format(_("%.2f"),mile[i]),wxRect(x1+dw*i,y1+h1+22,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        }

        if(viewHeadh==1)
        {
            memDC.SetPen(wxPen(wxColor(255,0,0)));
            memDC.SetBrush(wxBrush(wxColor(255,0,0)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(255,0,0)));
            memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        }
        memDC.DrawRectangle(x1+29,y1+h1+56,12,12);
        memDC.DrawLabel(_("切口平面"),wxRect(x1+49,y1+h1+55,0,14),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        qryButton[QRY_POS_GRAPH_HEADH].x=x1+29;
        qryButton[QRY_POS_GRAPH_HEADH].y=y1+h1+55;
        qryButton[QRY_POS_GRAPH_HEADH].width=85;
        qryButton[QRY_POS_GRAPH_HEADH].height=14;

        if(viewHeadv==1)
        {
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.SetBrush(wxBrush(wxColor(0,0,255)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        }
        memDC.DrawRectangle(x1+w1/4+w1/40+29,y1+h1+56,12,12);
        memDC.DrawLabel(_("切口高程"),wxRect(x1+w1/4+w1/40+49,y1+h1+55,0,14),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        qryButton[QRY_POS_GRAPH_HEADV].x=x1+w1/4+w1/40+29;
        qryButton[QRY_POS_GRAPH_HEADV].y=y1+h1+55;
        qryButton[QRY_POS_GRAPH_HEADV].width=85;
        qryButton[QRY_POS_GRAPH_HEADV].height=14;

        if(viewTailh==1)
        {
            memDC.SetPen(wxPen(wxColor(0,255,0)));
            memDC.SetBrush(wxBrush(wxColor(0,255,0)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(0,255,0)));
            memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        }
        memDC.DrawRectangle(x1+w1/2+w1/20+29,y1+h1+56,12,12);
        memDC.DrawLabel(_("盾尾平面"),wxRect(x1+w1/2+w1/20+49,y1+h1+55,0,14),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        qryButton[QRY_POS_GRAPH_TAILH].x=x1+w1/2+w1/20+29;
        qryButton[QRY_POS_GRAPH_TAILH].y=y1+h1+55;
        qryButton[QRY_POS_GRAPH_TAILH].width=85;
        qryButton[QRY_POS_GRAPH_TAILH].height=14;

        if(viewTailv==1)
        {
            memDC.SetPen(wxPen(wxColor(0,255,255)));
            memDC.SetBrush(wxBrush(wxColor(0,255,255)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(0,255,255)));
            memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        }
        memDC.DrawRectangle(x1+w1*4/5+29,y1+h1+56,12,12);
        memDC.DrawLabel(_("盾尾高程"),wxRect(x1+w1*4/5+49,y1+h1+55,0,14),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        qryButton[QRY_POS_GRAPH_TAILV].x=x1+w1*4/5+29;
        qryButton[QRY_POS_GRAPH_TAILV].y=y1+h1+55;
        qryButton[QRY_POS_GRAPH_TAILV].width=85;
        qryButton[QRY_POS_GRAPH_TAILV].height=14;

        /*memDC.SetFont(eni);
        memDC.SetTextForeground(wxColor(0,255,0));
        memDC.DrawLabel(_("√"),wxRect(x1+29,y1+h1+55,14,14),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetTextForeground(wxColor(255,97,0));
        memDC.DrawLabel(_("√"),wxRect(x1+w1/4+w1/40+29,y1+h1+55,14,14),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetTextForeground(wxColor(255,255,255));
        memDC.DrawLabel(_("√"),wxRect(x1+w1/2+w1/20+29,y1+h1+55,14,14),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetTextForeground(wxColor(0,0,255));
        memDC.DrawLabel(_("√"),wxRect(x1+w1*4/5+29,y1+h1+55,14,14),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        */
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyQueryDlg::OnPaintZoom(wxPaintEvent& event)
{
    wxPaintDC dc(panelZoom);
    int w,h;
    panelZoom->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(107,107,107)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1=1;
        int y1=1;
        int w1=(w-4)/3;
        int h1=h-2;
        qryButton[QRY_POS_GRAPH_ZOOM_OUT].x=x1;
        qryButton[QRY_POS_GRAPH_ZOOM_OUT].y=y1;
        qryButton[QRY_POS_GRAPH_ZOOM_OUT].width=w1;
        qryButton[QRY_POS_GRAPH_ZOOM_OUT].height=h1;
        if(motion==QRY_POS_GRAPH_ZOOM_OUT)
        {
            memDC.SetPen(btnBrush[1].GetColour());
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnBrush[0].GetColour());
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }

        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),qryButton[QRY_POS_GRAPH_ZOOM_OUT],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(107,107,107)));
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        x1=x1+w1+1;
        qryButton[QRY_POS_GRAPH_ZOOM_PAM].x=x1;
        qryButton[QRY_POS_GRAPH_ZOOM_PAM].y=y1;
        qryButton[QRY_POS_GRAPH_ZOOM_PAM].width=w1;
        qryButton[QRY_POS_GRAPH_ZOOM_PAM].height=h1;
        if(motion==QRY_POS_GRAPH_ZOOM_PAM)
        {
            memDC.SetPen(btnBrush[1].GetColour());
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnBrush[0].GetColour());
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }

        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("口"),qryButton[QRY_POS_GRAPH_ZOOM_PAM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(107,107,107)));
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        x1=x1+w1+1;
        w1=w1+2;
        qryButton[QRY_POS_GRAPH_ZOOM_IN].x=x1;
        qryButton[QRY_POS_GRAPH_ZOOM_IN].y=y1;
        qryButton[QRY_POS_GRAPH_ZOOM_IN].width=w1;
        qryButton[QRY_POS_GRAPH_ZOOM_IN].height=h1;
        if(motion==QRY_POS_GRAPH_ZOOM_IN)
        {
            memDC.SetPen(btnBrush[1].GetColour());
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnBrush[0].GetColour());
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }

        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),qryButton[QRY_POS_GRAPH_ZOOM_IN],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.SetPen(wxPen(wxColor(107,107,107)));
        //memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyQueryDlg::OnMotionZoom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>qryButton[QRY_POS_GRAPH_ZOOM_OUT].y && y<qryButton[QRY_POS_GRAPH_ZOOM_OUT].y+qryButton[QRY_POS_GRAPH_ZOOM_OUT].height)
    {
        if(x>qryButton[QRY_POS_GRAPH_ZOOM_OUT].x && x<qryButton[QRY_POS_GRAPH_ZOOM_OUT].x+qryButton[QRY_POS_GRAPH_ZOOM_OUT].width)
        {
            motion=QRY_POS_GRAPH_ZOOM_OUT;
        }
        else if(x>qryButton[QRY_POS_GRAPH_ZOOM_PAM].x && x<qryButton[QRY_POS_GRAPH_ZOOM_PAM].x+qryButton[QRY_POS_GRAPH_ZOOM_PAM].width)
        {
            motion=QRY_POS_GRAPH_ZOOM_PAM;
        }
        else if(x>qryButton[QRY_POS_GRAPH_ZOOM_IN].x && x<qryButton[QRY_POS_GRAPH_ZOOM_IN].x+qryButton[QRY_POS_GRAPH_ZOOM_IN].width)
        {
            motion=QRY_POS_GRAPH_ZOOM_IN;
        }
        else
        {
            motion=QRY_POS_NONE;
        }
    }
    else
    {
        motion=QRY_POS_NONE;
    }
    panelZoom->Refresh();
}

void MyQueryDlg::OnLeaveZoom(wxMouseEvent& event)
{
    motion=QRY_POS_NONE;
    panelZoom->Refresh();
}

void MyQueryDlg::OnClickZoom(wxMouseEvent& event)
{
    if(motion==QRY_POS_GRAPH_ZOOM_IN)
    {
        if(perL<65)
        {
            perL=perL+5;
            panelGraph->Refresh();
        }
    }
    else if(motion==QRY_POS_GRAPH_ZOOM_PAM)
    {
        perL=20;
        panelGraph->Refresh();
    }
    else if(motion==QRY_POS_GRAPH_ZOOM_OUT)
    {
        if(perL>5)
        {
            perL=perL-5;
            panelGraph->Refresh();
        }
    }
    panelZoom->Refresh();
}

void MyQueryDlg::OnPaintBottom(wxPaintEvent& event)
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
        x1=9;
        y1=9;
        w1=65;
        h1=26;
        qryButton[QRY_POS_QRY_METHOD_SEG].x=x1;
        qryButton[QRY_POS_QRY_METHOD_SEG].y=y1;
        qryButton[QRY_POS_QRY_METHOD_SEG].width=w1;
        qryButton[QRY_POS_QRY_METHOD_SEG].height=h1;

        memDC.SetPen(wxPen(wxColor(107,107,107)));
        if(qryMethod==QRY_POS_QRY_METHOD_SEG)
        {
            memDC.SetBrush(btnBrush[2]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else if(motion==QRY_POS_QRY_METHOD_SEG)
        {
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(qryButton[QRY_POS_QRY_METHOD_SEG]);
        memDC.DrawLabel(_("按环号"),qryButton[QRY_POS_QRY_METHOD_SEG],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        qryButton[QRY_POS_QRY_METHOD_MILE].x=x1+w1;
        qryButton[QRY_POS_QRY_METHOD_MILE].y=y1;
        qryButton[QRY_POS_QRY_METHOD_MILE].width=w1;
        qryButton[QRY_POS_QRY_METHOD_MILE].height=h1;
        memDC.SetPen(wxPen(wxColor(107,107,107)));
        if(qryMethod==QRY_POS_QRY_METHOD_MILE)
        {
            memDC.SetBrush(btnBrush[2]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else if(motion==QRY_POS_QRY_METHOD_MILE)
        {
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(qryButton[QRY_POS_QRY_METHOD_MILE]);
        memDC.DrawLabel(_("按里程"),qryButton[QRY_POS_QRY_METHOD_MILE],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1*2+7;
        panelMain->GetPosition(&x1,0);
        w1=120;
        memDC.SetPen(btnPen[0]);
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        queryValue1->SetSize(x1+2,y1+5,w1-4,20);

        x1=x1+w1;
        w1=25;
        memDC.SetTextForeground(btnTextColor[0]);
        memDC.DrawLabel(_("～"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=120;
        memDC.SetPen(btnPen[0]);
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        queryValue2->SetSize(x1+2,y1+5,w1-4,20);

        x1=x1+w1+7;
        w1=65;
        h1=26;
        qryButton[QRY_POS_QRY_BTN].x=x1;
        qryButton[QRY_POS_QRY_BTN].y=y1;
        qryButton[QRY_POS_QRY_BTN].width=w1;
        qryButton[QRY_POS_QRY_BTN].height=h1;
        if(motion==QRY_POS_QRY_BTN)
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
        memDC.DrawLabel(_("查询"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+28;
        w1=180;
        qryButton[QRY_POS_QRY_VIEW_3P].x=x1;
        qryButton[QRY_POS_QRY_VIEW_3P].y=y1;
        qryButton[QRY_POS_QRY_VIEW_3P].width=w1;
        qryButton[QRY_POS_QRY_VIEW_3P].height=h1;
        if(viewMethod==QRY_POS_QRY_VIEW_3P)
        {
            if(motion==QRY_POS_QRY_VIEW_3P)
            {
                memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                memDC.SetBrush(btnBrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-7,14,14);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-7,14,14),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("每环显示管环前、中、后三点"),wxRect(x1+19,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                memDC.SetBrush(btnBrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-7,14,14);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-7,14,14),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("每环显示管环前、中、后三点"),wxRect(x1+19,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion==QRY_POS_QRY_VIEW_3P)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(btnBrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-7,14,14);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("每环显示管环前、中、后三点"),wxRect(x1+19,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(btnBrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-7,14,14);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("每环显示管环前、中、后三点"),wxRect(x1+19,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        w1=65;
        x1=w-w1*2-21;

        qryButton[QRY_POS_EMPORT_BTN].x=x1;
        qryButton[QRY_POS_EMPORT_BTN].y=y1;
        qryButton[QRY_POS_EMPORT_BTN].width=w1;
        qryButton[QRY_POS_EMPORT_BTN].height=h1;
        if(motion==QRY_POS_EMPORT_BTN)
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
        memDC.DrawLabel(_("导出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1+7;
        qryButton[QRY_POS_QUIT_BTN].x=x1;
        qryButton[QRY_POS_QUIT_BTN].y=y1;
        qryButton[QRY_POS_QUIT_BTN].width=w1;
        qryButton[QRY_POS_QUIT_BTN].height=h1;
        if(motion==QRY_POS_QUIT_BTN)
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

void MyQueryDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>qryButton[QRY_POS_QRY_METHOD_SEG].y && y<qryButton[QRY_POS_QRY_METHOD_SEG].y+qryButton[QRY_POS_QRY_METHOD_SEG].height)
    {
        if(x>qryButton[QRY_POS_QRY_METHOD_SEG].x && x<qryButton[QRY_POS_QRY_METHOD_SEG].x+qryButton[QRY_POS_QRY_METHOD_SEG].width)
        {
            motion=QRY_POS_QRY_METHOD_SEG;
        }
        else if(x>qryButton[QRY_POS_QRY_METHOD_MILE].x && x<qryButton[QRY_POS_QRY_METHOD_MILE].x+qryButton[QRY_POS_QRY_METHOD_MILE].width)
        {
            motion=QRY_POS_QRY_METHOD_MILE;
        }
        else if(x>qryButton[QRY_POS_QRY_BTN].x && x<qryButton[QRY_POS_QRY_BTN].x+qryButton[QRY_POS_QRY_BTN].width)
        {
            motion=QRY_POS_QRY_BTN;
        }
        else if(x>qryButton[QRY_POS_QRY_VIEW_3P].x && x<qryButton[QRY_POS_QRY_VIEW_3P].x+qryButton[QRY_POS_QRY_VIEW_3P].width)
        {
            motion=QRY_POS_QRY_VIEW_3P;
        }
        else if(x>qryButton[QRY_POS_EMPORT_BTN].x && x<qryButton[QRY_POS_EMPORT_BTN].x+qryButton[QRY_POS_EMPORT_BTN].width)
        {
            motion=QRY_POS_EMPORT_BTN;
        }
        else if(x>qryButton[QRY_POS_QUIT_BTN].x && x<qryButton[QRY_POS_QUIT_BTN].x+qryButton[QRY_POS_QUIT_BTN].width)
        {
            motion=QRY_POS_QUIT_BTN;
        }
        else
        {
            motion=QRY_POS_NONE;
        }
    }
    else
    {
        motion=QRY_POS_NONE;
    }
    panelBottom->Refresh();
}

void MyQueryDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=QRY_POS_NONE;
    panelBottom->Refresh();
}

void MyQueryDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==QRY_POS_QUIT_BTN)
    {
        Destroy();
    }
    else if(motion==QRY_POS_EMPORT_BTN)
    {
        Report();
    }
    else if(motion==QRY_POS_QRY_BTN)
    {
        if(viewMethod==QRY_POS_QRY_VIEW_DITAIL)
        {
            if(qryMethod==QRY_POS_QRY_METHOD_MILE)
            {
                double l1,l2;
                queryValue1->GetValue().ToDouble(&l1);
                if(cli->prj.a2z==1)
                {
                    l2=l1+20;
                }
                else
                {
                    l2=l1;
                    l1=l2-20;
                }
                if(qres1) free(qres1);
                qres1=0;
                nq1=0;
                //nq1=mtg_query_chain(cli,l1,l2,&qres1);
            }
            else
            {
                int n1,n2;
                long val;
                queryValue1->GetValue().ToLong(&val);
                n1=val;
                n2=n1+10;
                if(qres1) free(qres1);
                qres1=0;
                nq1=0;
                if(qres2) free(qres2);
                nq2=0;
                //nq1=mtg_query_meas(cli,n1,n2,&qres1);
            }
            SerialQurey();
        }
        else
        {
            if(qryMethod==QRY_POS_QRY_METHOD_MILE)
            {
                double l1,l2;
                queryValue1->GetValue().ToDouble(&l1);
                if(cli->prj.a2z==1)
                {
                    l2=l1+20;
                }
                else
                {
                    l2=l1;
                    l1=l2-20;
                }
                if(qres2) free(qres2);
                qres2=0;
                nq2=0;
                //nq2=mtg_query_segment_chain(cli,l1,l2,&qres2);
            }
            else
            {
                int n1,n2;
                long val;
                queryValue1->GetValue().ToLong(&val);
                n1=val;
                n2=n1+10;
                if(qres2) free(qres2);
                qres2=0;
                nq2=0;
                //nq2=mtg_query_segment_meas(cli,n1,n2,&qres2);
            }
        }
        ShowQurey();
        panelGraph->Refresh();
    }
    else if(motion==QRY_POS_QRY_VIEW_3P)
    {
        if(viewMethod==QRY_POS_QRY_VIEW_3P)
        {
            viewMethod=QRY_POS_QRY_VIEW_DITAIL;
        }
        else
        {
            viewMethod=QRY_POS_QRY_VIEW_3P;
        }
    }
    else if(motion==QRY_POS_QRY_METHOD_MILE)
    {
        if(qryMethod==QRY_POS_QRY_METHOD_SEG)
        {
            qryMethod=QRY_POS_QRY_METHOD_MILE;
            if(cli->prj.a2z==1)
            {
                queryValue1->SetValue(wxString::Format(_("%.3f"),cli->m1.headc-20));
            }
            else
            {
                queryValue1->SetValue(wxString::Format(_("%.3f"),cli->m1.headc+20));
            }
        }
    }
    else if(motion==QRY_POS_QRY_METHOD_SEG)
    {
        if(qryMethod==QRY_POS_QRY_METHOD_MILE)
        {
            qryMethod=QRY_POS_QRY_METHOD_SEG;
            queryValue1->SetValue(wxString::Format(_("%d"),cli->m1.iseg-10));
        }
    }

    panelBottom->Refresh();
}

void MyQueryDlg::SerialQurey()
{
    double val;
    double mile;

    if(cli->prj.a2z==1)
    {
        val=0.02;
    }
    else
    {
        val=-0.02;
    }

    int i,j;
    j=1;
    mile=qres1[0].headc-val;
    for(i=1;i<nq1;i++)
    {
        if(val<0.0 && qres1[i].headc>mile)
        {
            mile=qres1[i].headc-val;
            qres1[j]=qres1[i];
            j++;
        }
        else if(val>0.0 && qres1[i].headc<mile)
        {
            mile=qres1[i].headc-val;
            qres1[j]=qres1[i];
            j++;
        }
    }
    if(j<nq1)
    {
        qres1[j]=qres1[nq1-1];
        j++;
    }
    nq1=j;
}

void MyQueryDlg::ShowQurey()
{
    if(viewMethod==QRY_POS_QRY_VIEW_DITAIL)
    {
        if(nq1<=0)
        {
            return;
        }

        qryList->DeleteAllItems();

        for(int i=0;i<nq1;i++)
        {
            int j=1;
            qryList->InsertItem(i,wxString::Format(_("%d"),qres1[i].iseg));

            int nmoff;
            nmoff=road_number_mile_off(&cli->r);
            if(nmoff>0)
            {
                m_offset *mo={0};
                for(int nn=nmoff-1;nn>=0;nn--)
                {
                    mo=road_mile_off(&cli->r,nn);
                    if(qres1[i].headc>mo->mile)
                    {
                        qres1[i].headc=qres1[i].headc+mo->off;
                        qryList->SetItem(i,j++,wxString::Format(_("%.3f"),qres1[i].headc));
                        break;
                    }
                }
            }
            qryList->SetItem(i,j++,wxString::Format(_("%d"),(int)(qres1[i].headh*1000)));
            qryList->SetItem(i,j++,wxString::Format(_("%d"),(int)(qres1[i].tailh*1000)));
            qryList->SetItem(i,j++,wxString::Format(_("%d"),(int)(qres1[i].headv*1000)));
            qryList->SetItem(i,j++,wxString::Format(_("%d"),(int)(qres1[i].tailv*1000)));

            qryList->SetItem(i,j++,wxString::Format(_("%.3f"),qres1[i].roll*180/PI));
            qryList->SetItem(i,j++,wxString::Format(_("%.3f"),qres1[i].pitch*180/PI));
            qryList->SetItem(i,j++,wxString::Format(_("%.3f"),qres1[i].azimuth*180/PI));
            qryList->SetItem(i,j++,wxDateTime(qres1[i].t1).Format(_("%Y-%m-%d %H:%M:%S")));
        }
    }
    else
    {
        if(nq2<=0)
        {
            return;
        }


        qryList->DeleteAllItems();

        for(int i=0;i<nq2;i++)
        {
            int j=1;
            qryList->InsertItem(i,wxString::Format(_("%d"),qres1[i].iseg));

            int nmoff;
            nmoff=road_number_mile_off(&cli->r);
            if(nmoff>0)
            {
                m_offset *mo={0};
                for(int nn=nmoff-1;nn>=0;nn--)
                {
                    mo=road_mile_off(&cli->r,nn);
                    if(qres1[i].headc>mo->mile)
                    {
                        qres1[i].headc=qres1[i].headc+mo->off;
                        qryList->SetItem(i,j++,wxString::Format(_("%.3f"),qres1[i].headc));
                        break;
                    }
                }
            }
            qryList->SetItem(i,j++,wxString::Format(_("%d"),(int)(qres1[i].headh*1000)));
            qryList->SetItem(i,j++,wxString::Format(_("%d"),(int)(qres1[i].tailh*1000)));
            qryList->SetItem(i,j++,wxString::Format(_("%d"),(int)(qres1[i].headv*1000)));
            qryList->SetItem(i,j++,wxString::Format(_("%d"),(int)(qres1[i].tailv*1000)));

            qryList->SetItem(i,j++,wxString::Format(_("%.3f"),qres1[i].roll*180/PI));
            qryList->SetItem(i,j++,wxString::Format(_("%.3f"),qres1[i].pitch*180/PI));
            qryList->SetItem(i,j++,wxString::Format(_("%.3f"),qres1[i].azimuth*180/PI));
            qryList->SetItem(i,j++,wxDateTime(qres1[i].t1).Format(_("%Y-%m-%d %H:%M:%S")));
        }
    }
}

void MyQueryDlg::Report()
{
    if(viewMethod==QRY_POS_QRY_VIEW_DITAIL)
    {
        if(nq1<=0)
        {
            return;
        }

        wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
            if(fp)
            {
                fprintf(fp,wxString(_("管片号,刀盘里程,盾首平面,盾首高程,盾尾平面,盾尾高程,滚动,俯仰,方位,盾首（实测）x,盾首（实测）y,盾首（实测）z,盾首（设计）x,盾首（设计）y,盾首（设计）z,盾尾（实测）x,盾尾（实测）y,盾尾（实测）z,盾尾（设计）x,盾尾（设计）y,盾尾（设计）z,棱镜x,棱镜y,棱镜z,倾斜仪滚动,倾斜仪俯仰,时间\n")).mb_str(wxConvLocal));
                for(int i=0;i<nq1;i++)
                {
                    fprintf(fp,"%d,",qres1[i].iseg);
                    fprintf(fp,"%.3f,",qres1[i].headc);
                    fprintf(fp,"%d,",(int)(qres1[i].headh*1000.0));
                    fprintf(fp,"%d,",(int)(qres1[i].headv*1000.0));
                    fprintf(fp,"%d,",(int)(qres1[i].tailh*1000.0));
                    fprintf(fp,"%d,",(int)(qres1[i].tailv*1000.0));
                    fprintf(fp,"%.3f,",qres1[i].roll*180.0/PI);
                    fprintf(fp,"%.3f,",qres1[i].pitch*180.0/PI);
                    fprintf(fp,"%.3f,",qres1[i].azimuth*180.0/PI);
                    fprintf(fp,"%.3f,",qres1[i].head[0]);
                    fprintf(fp,"%.3f,",qres1[i].head[1]);
                    fprintf(fp,"%.3f,",qres1[i].head[2]);
                    fprintf(fp,"%.3f,",qres1[i].hdes[0]);
                    fprintf(fp,"%.3f,",qres1[i].hdes[1]);
                    fprintf(fp,"%.3f,",qres1[i].hdes[2]);
                    fprintf(fp,"%.3f,",qres1[i].tail[0]);
                    fprintf(fp,"%.3f,",qres1[i].tail[1]);
                    fprintf(fp,"%.3f,",qres1[i].tail[2]);
                    fprintf(fp,"%.3f,",qres1[i].tdes[0]);
                    fprintf(fp,"%.3f,",qres1[i].tdes[1]);
                    fprintf(fp,"%.3f,",qres1[i].tdes[2]);
                    fprintf(fp,"%.3f,",qres1[i].prism[0]);
                    fprintf(fp,"%.3f,",qres1[i].prism[1]);
                    fprintf(fp,"%.3f,",qres1[i].prism[2]);
                    fprintf(fp,"%.4f,",qres1[i].inc[0]);
                    fprintf(fp,"%.4f,",qres1[i].inc[1]);
                    wxString strt=wxDateTime(qres1[i].t1).Format(_("%Y-%m-%d %H:%M:%S"));
                    fprintf(fp,"%s\n",(const char*)strt.mb_str(wxConvLocal));
                }
                fclose(fp);
                wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
            }
        }
    }
    else
    {
        if(nq2<=0)
        {
            return;
        }

        wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
            if(fp)
            {
                fprintf(fp,wxString(_("管片号,刀盘里程,盾首平面,盾首高程,盾尾平面,盾尾高程,滚动,俯仰,方位,盾首（实测）x,盾首（实测）y,盾首（实测）z,盾首（设计）x,盾首（设计）y,盾首（设计）z,盾尾（实测）x,盾尾（实测）y,盾尾（实测）z,盾尾（设计）x,盾尾（设计）y,盾尾（设计）z,棱镜x,棱镜y,棱镜z,倾斜仪滚动,倾斜仪俯仰,时间\n")).mb_str(wxConvLocal));
                for(int i=0;i<nq2;i++)
                {
                    fprintf(fp,"%d,",qres2[i].iseg);
                    fprintf(fp,"%.3f,",qres2[i].headc);
                    fprintf(fp,"%d,",(int)(qres2[i].headh*1000.0));
                    fprintf(fp,"%d,",(int)(qres2[i].headv*1000.0));
                    fprintf(fp,"%d,",(int)(qres2[i].tailh*1000.0));
                    fprintf(fp,"%d,",(int)(qres2[i].tailv*1000.0));
                    fprintf(fp,"%.3f,",qres2[i].roll*180.0/PI);
                    fprintf(fp,"%.3f,",qres2[i].pitch*180.0/PI);
                    fprintf(fp,"%.3f,",qres2[i].azimuth*180.0/PI);
                    fprintf(fp,"%.3f,",qres2[i].head[0]);
                    fprintf(fp,"%.3f,",qres2[i].head[1]);
                    fprintf(fp,"%.3f,",qres2[i].head[2]);
                    fprintf(fp,"%.3f,",qres2[i].hdes[0]);
                    fprintf(fp,"%.3f,",qres2[i].hdes[1]);
                    fprintf(fp,"%.3f,",qres2[i].hdes[2]);
                    fprintf(fp,"%.3f,",qres2[i].tail[0]);
                    fprintf(fp,"%.3f,",qres2[i].tail[1]);
                    fprintf(fp,"%.3f,",qres2[i].tail[2]);
                    fprintf(fp,"%.3f,",qres2[i].tdes[0]);
                    fprintf(fp,"%.3f,",qres2[i].tdes[1]);
                    fprintf(fp,"%.3f,",qres2[i].tdes[2]);
                    fprintf(fp,"%.3f,",qres2[i].prism[0]);
                    fprintf(fp,"%.3f,",qres2[i].prism[1]);
                    fprintf(fp,"%.3f,",qres2[i].prism[2]);
                    fprintf(fp,"%.4f,",qres2[i].inc[0]);
                    fprintf(fp,"%.4f,",qres2[i].inc[1]);
                    wxString strt=wxDateTime(qres2[i].t1).Format(_("%Y-%m-%d %H:%M:%S"));
                    fprintf(fp,"%s\n",(const char*)strt.mb_str(wxConvLocal));
                }
                fclose(fp);
                wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
            }
        }
    }
}

void MyQueryDlg::LoadData()
{
    if(qryMethod==QRY_POS_QRY_METHOD_SEG)
    {
        queryValue1->SetValue(wxString::Format(_("%d"),cli->m1.iseg-10));
    }
    else
    {
        if(cli->prj.a2z==1)
        {
            queryValue1->SetValue(wxString::Format(_("%.3f"),cli->m1.headc-20));
        }
        else
        {
            queryValue1->SetValue(wxString::Format(_("%.3f"),cli->m1.headc+20));
        }
    }
}

void MyQueryDlg::OnPaintBackground(wxPaintEvent& event)
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


void MyQueryDlg::OnPaintNavi(wxPaintEvent& event)
{
    wxPaintDC dc(panelNavi);
    int w,h;
    panelNavi->GetClientSize(&w,&h);

    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(0,-1,w,h+1);
}

