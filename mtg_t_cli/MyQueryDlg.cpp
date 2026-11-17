///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyQueryDlg.h"
#include "mtg_t_cliMain.h"
#include "mtg_t_cliApp.h"
//#include "confirmdlg.h"
#include "wxMyGrid.h"
//#include "SegDialog.h"
//#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include "laserimg.h"

#define PI  3.1415926535897932384626433832795
#define MXQ  1000

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

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPage = new wxPanel(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x1=7;
    y1=59;
    w1=w-x1*2;
    h1=h-115;
    panelMeas = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    measButton = new wxPanel(panelMeas, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    queryValue1 = new wxMyTextCtrl(measButton, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER,wxDefaultValidator);
    queryValue2 = new wxMyTextCtrl(measButton, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER,wxDefaultValidator);

    m_gridHistory = new wxMyGrid(panelMeas, wxID_ANY, wxPoint(0,39), wxSize(w1,h1-39 ), 0 );
    m_gridSegment = new wxMyGrid(panelMeas, wxID_ANY, wxPoint(0,39), wxSize(w1,h1-39 ), 0 );
    m_gridSegment->Show(false);
    //measList = new wxPanel(panelMeas, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //measList->Show(false);
    //qryList = new wxListView(measList, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    panelGraph = new wxPanel(panelMeas, wxID_ANY, wxPoint(0,39), wxSize(w1,h1-39 ), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelGraph->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelGraph->Show(false);
    panelChart = new wxPanel(panelGraph, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelLaser = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //panelLaser = new wxPanel(panelMeas, wxID_ANY, wxPoint(0,39), wxSize(w1,h1-39 ), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelLaser->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelLaser->Show(false);

    x1=0;
    y1=100;
    w1=w-150;
    h1=h-88;
    //panelMeas = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    //historyGid = new wxGrid(panelMeas, wxID_ANY, wxPoint(1,41), wxSize(w1-2,h1-41), 0, _T("wxID_ANY"));

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMeas->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    measButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //measList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelChart->SetBackgroundStyle(wxBG_STYLE_CUSTOM);


    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintMain,0,this);
	panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyQueryDlg::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyQueryDlg::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyQueryDlg::OnClickPage,0,this);

    panelMeas->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintMeas,0,this);
    measButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintMeasButton,0,this);
    measButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyQueryDlg::OnMotionMeasButton,0,this);
    measButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyQueryDlg::OnLeaveMeasButton,0,this);
    measButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyQueryDlg::OnClickMeasButton,0,this);
    //measList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintMeasList,0,this);

    panelGraph->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintGraph,0,this);
    panelGraph->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyQueryDlg::OnMotionGraph,0,this);
    panelGraph->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyQueryDlg::OnLeaveGraph,0,this);
    panelGraph->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyQueryDlg::OnClickGraph,0,this);

    panelChart->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintChart,0,this);

    panelLaser->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintLaser,0,this);
    panelLaser->Connect(wxEVT_LEFT_DCLICK,(wxObjectEventFunction)&MyQueryDlg::OnDoubleClickLaser,0,this);
    //panelLaser->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyQueryDlg::OnMotionLaser,0,this);
    //panelLaser->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyQueryDlg::OnLeaveLaser,0,this);
    //panelLaser->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyQueryDlg::OnClickLaser,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyQueryDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyQueryDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyQueryDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyQueryDlg::OnClickBottom,0,this);

    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    int i=0;

    wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    // Grid
	m_gridHistory->CreateGrid( 0, 0 );
	m_gridHistory->EnableEditing( false );
	m_gridHistory->EnableGridLines( true );
	m_gridHistory->EnableDragGridSize( false );
	m_gridHistory->SetMargins( 0, 0 );

	// Columns
	m_gridHistory->EnableDragColMove( false );
	m_gridHistory->EnableDragColSize( false );
	m_gridHistory->SetColLabelSize( 40 );
	m_gridHistory->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Rows
	m_gridHistory->EnableDragRowSize( false );
	m_gridHistory->SetRowLabelSize( 65 );
	m_gridHistory->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
    m_gridHistory->SetLabelFont(chs);
	// Label Appearance

	// Cell Defaults
	m_gridHistory->SetDefaultCellAlignment( wxALIGN_RIGHT, wxALIGN_TOP );

    m_gridHistory->InsertCols(0,42);
    i=0;
    //m_gridHistory->SetColLabelValue( i, _("管片号") );
	//m_gridHistory->SetColSize(i++,65);  ///管片号
	m_gridHistory->SetColLabelValue( i, _("切口里程") );
	m_gridHistory->SetColSize(i++,100);  ///里程
	m_gridHistory->MergeColum(_("平面偏差(mm)"),i,i+2);
	m_gridHistory->SetColLabelValue( i, _("前") );
	m_gridHistory->SetColSize(i++,65); ///偏差
	m_gridHistory->SetColLabelValue( i, _("中") );
	m_gridHistory->SetColSize(i++,65);
	m_gridHistory->SetColLabelValue( i, _("后") );
	m_gridHistory->SetColSize(i++,65);
	m_gridHistory->MergeColum(_("高程偏差(mm)"),i,i+2);
	m_gridHistory->SetColLabelValue( i, _("前") );
	m_gridHistory->SetColSize(i++,65);
	m_gridHistory->SetColLabelValue( i, _("中") );
	m_gridHistory->SetColSize(i++,65);
	m_gridHistory->SetColLabelValue( i, _("后") );
	m_gridHistory->SetColSize(i++,65);
	m_gridHistory->MergeColum(_("姿态角(°)"),i,i+2);
	m_gridHistory->SetColLabelValue( i, _("滚动角") );
	m_gridHistory->SetColSize(i++,65);
	m_gridHistory->SetColLabelValue( i, _("俯仰角") );
	m_gridHistory->SetColSize(i++,65);
	m_gridHistory->SetColLabelValue( i, _("方位角") );
	m_gridHistory->SetColSize(i++,75);
	m_gridHistory->MergeColum(_("盾首(计算)"),i,i+2);
	m_gridHistory->SetColLabelValue( i, _("X") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Y") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Z") );
	m_gridHistory->SetColSize(i++,85);
	m_gridHistory->MergeColum(_("盾中(计算)"),i,i+2);
	m_gridHistory->SetColLabelValue( i, _("X") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Y") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Z") );
	m_gridHistory->SetColSize(i++,85);
	m_gridHistory->MergeColum(_("盾尾(计算)"),i,i+2);
	m_gridHistory->SetColLabelValue( i, _("X") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Y") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Z") );
	m_gridHistory->SetColSize(i++,85);
	m_gridHistory->MergeColum(_("盾首(设计)"),i,i+2);
	m_gridHistory->SetColLabelValue( i, _("X") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Y") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Z") );
	m_gridHistory->SetColSize(i++,85);
	m_gridHistory->MergeColum(_("盾中(设计)"),i,i+2);
	m_gridHistory->SetColLabelValue( i, _("X") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Y") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Z") );
	m_gridHistory->SetColSize(i++,85);
	m_gridHistory->MergeColum(_("盾尾(设计)"),i,i+2);
	m_gridHistory->SetColLabelValue( i, _("X") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Y") );
	m_gridHistory->SetColSize(i++,100);
	m_gridHistory->SetColLabelValue( i, _("Z") );
	m_gridHistory->SetColSize(i++,85);
	int j=0;
	//if(wxGetApp().m_Position._prism_used[0])
    {
        m_gridHistory->MergeColum(_("棱镜"),i,i+2);
        m_gridHistory->SetColLabelValue( i, _("X") );
        m_gridHistory->SetColSize(i++,100);
        m_gridHistory->SetColLabelValue( i, _("Y") );
        m_gridHistory->SetColSize(i++,100);
        m_gridHistory->SetColLabelValue( i, _("Z") );
        m_gridHistory->SetColSize(i++,85);
        j++;
    }
    m_gridHistory->MergeColum(_("全站仪"),i,i+1);
    m_gridHistory->SetColLabelValue( i, _("水平角(°)") );
    m_gridHistory->SetColSize(i++,75);
    m_gridHistory->SetColLabelValue( i, _("垂直角(°)") );
    m_gridHistory->SetColSize(i++,75);
    m_gridHistory->MergeColum(_("全站仪气泡"),i,i+1);
    m_gridHistory->SetColLabelValue( i, _("L(°)") );
    m_gridHistory->SetColSize(i++,75);
    m_gridHistory->SetColLabelValue( i, _("T(°)") );
    m_gridHistory->SetColSize(i++,75);
    ///耙1
    m_gridHistory->MergeColum(_("前屏"),i,i+1);
    m_gridHistory->SetColLabelValue( i, _("X1") );
    m_gridHistory->SetColSize(i++,75);
    m_gridHistory->SetColLabelValue( i, _("Y1") );
    m_gridHistory->SetColSize(i++,75);
    ///耙2
    m_gridHistory->MergeColum(_("后屏"),i,i+1);
    m_gridHistory->SetColLabelValue( i, _("X2") );
    m_gridHistory->SetColSize(i++,75);
    m_gridHistory->SetColLabelValue( i, _("Y2") );
    m_gridHistory->SetColSize(i++,75);
    //if(wxGetApp().m_Position._position_type==POSITION_TYPE_BINARY)
    {
        m_gridHistory->MergeColum(_("倾斜仪"),i,i+1);
        m_gridHistory->SetColLabelValue( i, _("滚动(°)") );
        m_gridHistory->SetColSize(i++,75);
        m_gridHistory->SetColLabelValue( i, _("俯仰(°)") );
        m_gridHistory->SetColSize(i++,75);
    }
    m_gridHistory->SetColLabelValue( i, _("日期") );
	m_gridHistory->SetColSize(i++,150);  ///日期

    ///m_gridSegment
    m_gridSegment->CreateGrid( 0, 0 );
	m_gridSegment->EnableEditing( false );
	m_gridSegment->EnableGridLines( true );
	m_gridSegment->EnableDragGridSize( false );
	m_gridSegment->SetMargins( 0, 0 );

	// Columns
	m_gridSegment->EnableDragColMove( false );
	m_gridSegment->EnableDragColSize( false );
	m_gridSegment->SetColLabelSize( 40 );
	m_gridSegment->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Rows
	m_gridSegment->EnableDragRowSize( false );
	m_gridSegment->SetRowLabelSize( 65 );
	m_gridSegment->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
    m_gridSegment->SetLabelFont(chs);
	m_gridSegment->SetDefaultCellAlignment( wxALIGN_RIGHT, wxALIGN_TOP );

    m_gridSegment->InsertCols(0,7);
    i=0;
    m_gridSegment->SetColLabelValue( i, _("里程") );
	m_gridSegment->SetColSize(i++,100);  ///里程
	m_gridSegment->MergeColum(_("管环坐标"),i,i+2);
	m_gridSegment->SetColLabelValue( i, _("X") );
	m_gridSegment->SetColSize(i++,100);
	m_gridSegment->SetColLabelValue( i, _("Y") );
	m_gridSegment->SetColSize(i++,100);
	m_gridSegment->SetColLabelValue( i, _("Z") );
	m_gridSegment->SetColSize(i++,85);
	m_gridSegment->MergeColum(_("管环偏差（mm）"),i,i+1);
	m_gridSegment->SetColLabelValue( i, _("水平") );
	m_gridSegment->SetColSize(i++,65);
	m_gridSegment->SetColLabelValue( i, _("垂直") );
	m_gridSegment->SetColSize(i++,65);
	m_gridSegment->SetColLabelValue( i, _("日期") );
	m_gridSegment->SetColSize(i++,150);  ///日期

    page=ID_QRY_PAGE_MEAS;
    motion=ID_QRY_NONE;
    qryMethod=ID_QRY_RING;

    res=0;
    nres=0;

    segs=0;
    nseg=0;
    ires=0;
    mxn=0;
    //ifrm=0;
    //qres2=0;
    //nq2=0;

    msg=wxEmptyString;

    dev=20;
    zoom=0;

    graphHeadh=1;
    graphHeadv=1;
    graphTailh=1;
    graphTailv=1;

    checkBoxWidth=14;
    checkBoxHeight=14;
    radioBoxR1=7;
    radioBoxR2=4;

    queryValue1->SetValue(wxString::Format(_("%d"),mtg->m1.iseg-1));
    queryValue2->SetValue(wxString::Format(_("%d"),mtg->m1.iseg));
}

MyQueryDlg::~MyQueryDlg()
{
    if(res) free(res);
    if(segs) free(segs);
}

void MyQueryDlg::OnPaintMeas(wxPaintEvent& event)
{
    wxPaintDC dc(panelMeas);
    int w,h;
    panelMeas->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=37;
        memDC.SetPen(wxPen(wxColor(130,135,144)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1,y1+1,x1+w1,y1+1);
        measButton->SetSize(x1,y1+2,w1,h1);

        y1=y1+h1+2;
        h1=h-y1;
        //m_gridHistory->SetSize(x1,y1,w1,h1);
        //measList->SetSize(x1,y1,w1,h1);
        //panelGraph->SetSize(x1,y1,w1,h1);
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
        memDC.SetPen(wxPen(wxColor(33,40,48)));
        memDC.SetBrush(wxBrush(wxColor(33,40,48)));
        memDC.DrawRectangle(0,0,w,h);

        int x1=0;
        int y1=h/2;
        int w1=w;
        int h1=h/6;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        //memDC.DrawLine(x1,y1-3*h1,x1,y1+3*h1);
        memDC.SetPen(wxPen(wxColor(158,158,158),1,wxDOT));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        memDC.DrawLine(x1,y1+h1*2,x1+w1,y1+h1*2);
        //memDC.DrawLine(x1,y1+h1*3,x1+w1,y1+h1*3);
        memDC.DrawLine(x1,y1-h1,x1+w1,y1-h1);
        memDC.DrawLine(x1,y1-h1*2,x1+w1,y1-h1*2);
        //memDC.DrawLine(x1,y1-h1*3,x1+w1,y1-h1*3);

        double hs,vs;
        double dx,dy;

        //int nline=mxdev/15;
        //dev=(nline+1)*5;
        vs=dev*1.0/h1;

        hs=fabs(el-ol)/w;

        int px1[4],py1[4],px2[4],py2[4];
        int i=ires+mxn-1;
        while(i>ires)
        {
            if(graphHeadh==1)
            {
                dx=fabs(res[i].headc-ol);
                px2[0]=x1+dx/hs;
                dy=res[i].hdev1*1000.0/vs;
                py2[0]=y1-dy;
                //if(i==0)
                //{
                    //trace(0,"chart:px1=%d,py1=%d,px2=%d,py2=%d\n",px1[0],py1[0],px2[0],py2[0]);
                //}
                memDC.SetPen(wxPen(wxColor(255,0,0)));
                if(i<ires+mxn-1) memDC.DrawLine(px1[0],py1[0],px2[0],py2[0]);
                px1[0]=px2[0];
                py1[0]=py2[0];
            }
            if(graphHeadv==1)
            {
                dx=fabs(res[i].headc-ol);
                px2[1]=x1+dx/hs;
                dy=res[i].vdev1*1000.0/vs;
                py2[1]=y1-dy;
                memDC.SetPen(wxPen(wxColor(0,0,255)));
                if(i<ires+mxn-1) memDC.DrawLine(px1[1],py1[1],px2[1],py2[1]);
                px1[1]=px2[1];
                py1[1]=py2[1];
            }
            if(graphTailh==1)
            {
                dx=fabs(res[i].tailc-ol);
                px2[2]=x1+dx/hs;
                dy=res[i].hdev2*1000.0/vs;
                py2[2]=y1-dy;
                memDC.SetPen(wxPen(wxColor(0,255,0)));
                if(i<ires+mxn-1) memDC.DrawLine(px1[2],py1[2],px2[2],py2[2]);
                px1[2]=px2[2];
                py1[2]=py2[2];
            }
            if(graphTailv==1)
            {
                dx=fabs(res[i].tailc-ol);
                px2[3]=x1+dx/hs;
                dy=res[i].vdev2*1000.0/vs;
                py2[3]=y1-dy;
                memDC.SetPen(wxPen(wxColor(0,255,255)));
                if(i<ires+mxn-1) memDC.DrawLine(px1[3],py1[3],px2[3],py2[3]);
                px1[3]=px2[3];
                py1[3]=py2[3];
            }
            i--;
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyQueryDlg::OnMotionGraph(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>qryButton[ID_QRY_GRAPH_HEADH].y && y<qryButton[ID_QRY_GRAPH_HEADH].y+qryButton[ID_QRY_GRAPH_HEADH].height)
    {
        if(x>qryButton[ID_QRY_GRAPH_HEADH].x && x<qryButton[ID_QRY_GRAPH_HEADH].x+qryButton[ID_QRY_GRAPH_HEADH].width)
        {
            motion=ID_QRY_GRAPH_HEADH;
        }
        else if(x>qryButton[ID_QRY_GRAPH_HEADV].x && x<qryButton[ID_QRY_GRAPH_HEADV].x+qryButton[ID_QRY_GRAPH_HEADV].width)
        {
            motion=ID_QRY_GRAPH_HEADV;
        }
        else if(x>qryButton[ID_QRY_GRAPH_TAILH].x && x<qryButton[ID_QRY_GRAPH_TAILH].x+qryButton[ID_QRY_GRAPH_TAILH].width)
        {
            motion=ID_QRY_GRAPH_TAILH;
        }
        else if(x>qryButton[ID_QRY_GRAPH_TAILV].x && x<qryButton[ID_QRY_GRAPH_TAILV].x+qryButton[ID_QRY_GRAPH_TAILV].width)
        {
            motion=ID_QRY_GRAPH_TAILV;
        }
        else
        {
            motion=ID_QRY_NONE;
        }
    }
    else
    {
        motion=ID_QRY_NONE;
    }
    panelGraph->Refresh();
}

void MyQueryDlg::OnLeaveGraph(wxMouseEvent& event)
{
    motion=ID_QRY_NONE;
    panelGraph->Refresh();
}

void MyQueryDlg::OnClickGraph(wxMouseEvent& event)
{
    if(motion==ID_QRY_GRAPH_HEADH)
    {
        if(graphHeadh==1) graphHeadh=0;
        else graphHeadh=1;
    }
    else if(motion==ID_QRY_GRAPH_HEADV)
    {
        if(graphHeadv==1) graphHeadv=0;
        else graphHeadv=1;
    }
    else if(motion==ID_QRY_GRAPH_TAILH)
    {
        if(graphTailh==1) graphTailh=0;
        else graphTailh=1;
    }
    else if(motion==ID_QRY_GRAPH_TAILV)
    {
        if(graphTailv==1) graphTailv=0;
        else graphTailv=1;
    }
    panelGraph->Refresh();
}

void MyQueryDlg::OnPaintGraph(wxPaintEvent& event)
{
    wxPaintDC dc(panelGraph);
    int w,h;
    int a2z=mtg->prj.a2z;

    panelGraph->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(130,135,144)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eni(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));

        int x1,y1,w1,h1;
        x1=42;
        y1=25;
        w1=w-x1*2;
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("里程"),wxRect(x1+w1/4-20,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("日期"),wxRect(x1+w1*1/2+30,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1=y1+25;
        h1=h-y1-90;
        panelChart->SetSize(x1,y1,w1,h1);

        double mile[7]={0};
        memDC.SetFont(eni);
        x1=42;
        y1=25;
        w1=w-x1*2;

        if(nres>0)
        {
            int ki=ires+mxn-1;
            memDC.DrawLabel(wxString::Format(_("%d"),res[ki].iseg)+_(" ～ ")+wxString::Format(_("%d"),res[ires].iseg),wxRect(x1+40,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%.3f"),res[ki].headc)+_(" ～ ")+wxString::Format(_("%.3f"),res[ires].headc),wxRect(x1+w1/4+20,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxDateTime(res[ki].t1).Format(_("%Y-%m-%d %H:%M:%S"))+_(" ～ ")+wxDateTime(res[ires].t1).Format(_("%Y-%m-%d %H:%M:%S")),wxRect(x1+w1/2+70,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            mile[0]=res[ki].headc;
            mile[6]=res[ires].headc;
            for(int i=1;i<6;i++)
            {
                mile[i]=mile[0]+(mile[6]-mile[0])*i/6.0;
            }
        }

        y1=y1+25;
        int dw,dh;
        dh=h1/6;
        memDC.DrawLabel(_("0"),wxRect(x1-5,y1+h1/2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(1*dev)),wxRect(x1-5,y1+h1/2-dh,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(2*dev)),wxRect(x1-5,y1+h1/2-dh*2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(3*dev)),wxRect(x1-5,y1+h1/2-dh*3,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(-1*dev)),wxRect(x1-5,y1+h1/2+dh,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(-2*dev)),wxRect(x1-5,y1+h1/2+dh*2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(-3*dev)),wxRect(x1-5,y1+h1/2+dh*3,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        dw=w1/6;
        for(int i=0;i<=6;i++)
        {
            memDC.DrawLine(x1+dw*i,y1+h1+5,x1+dw*i,y1+h1+12);
            memDC.DrawLabel(wxString::Format(_("%.2f"),mile[i]),wxRect(x1+dw*i,y1+h1+18,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        }

        int x2,y2,w2,h2;
        memDC.SetFont(chs);
        ///注记
        w2=w1-80;
        x2=x1+40;
        y2=y1+h1+65;
        w2=w2/3-20;
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        memDC.SetBrush(wxBrush(wxColor(255,0,0)));
        memDC.DrawLine(x2,y2,x2+20,y2);
        memDC.DrawRectangle(x2+8,y2-2,5,5);
        qryButton[ID_QRY_GRAPH_HEADH].x=x2+30;
        qryButton[ID_QRY_GRAPH_HEADH].y=y2-12;
        qryButton[ID_QRY_GRAPH_HEADH].width=75;
        qryButton[ID_QRY_GRAPH_HEADH].height=24;
        //memDC.DrawLabel(_("切口平面"),wxRect(x2+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        if(graphHeadh==1)
        {
            if(motion==ID_QRY_GRAPH_HEADH)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("前 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("√"),wxRect(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                //memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("前 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion==ID_QRY_GRAPH_HEADH)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("前 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("前 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        x2=x2+w2-15;
        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.SetBrush(wxBrush(wxColor(0,0,255)));
        memDC.DrawLine(x2,y2,x2+20,y2);
        memDC.DrawRectangle(x2+8,y2-2,5,5);
        //memDC.DrawLabel(_("切口高程"),wxRect(x2+30,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        qryButton[ID_QRY_GRAPH_HEADV].x=x2+30;
        qryButton[ID_QRY_GRAPH_HEADV].y=y2-12;
        qryButton[ID_QRY_GRAPH_HEADV].width=75;
        qryButton[ID_QRY_GRAPH_HEADV].height=24;
        if(graphHeadv==1)
        {
            if(motion==ID_QRY_GRAPH_HEADV)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("前 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("√"),wxRect(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                //memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("前 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion==ID_QRY_GRAPH_HEADV)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("前 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("前 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x2=x2+w2-15;
        memDC.SetPen(wxPen(wxColor(0,255,0)));
        memDC.SetBrush(wxBrush(wxColor(0,255,0)));
        memDC.DrawLine(x2,y2,x2+20,y2);
        memDC.DrawRectangle(x2+8,y2-2,5,5);
        //memDC.DrawLabel(_("盾尾平面"),wxRect(x2+30,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        qryButton[ID_QRY_GRAPH_TAILH].x=x2+30;
        qryButton[ID_QRY_GRAPH_TAILH].y=y2-12;
        qryButton[ID_QRY_GRAPH_TAILH].width=75;
        qryButton[ID_QRY_GRAPH_TAILH].height=24;
        if(graphTailh==1)
        {
            if(motion==ID_QRY_GRAPH_TAILH)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                if(mtg->tbm.type==0)
                memDC.DrawLabel(_("后 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                else
                memDC.DrawLabel(_("中 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("√"),wxRect(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                //memDC.SetTextForeground(icolor[0]);
                if(mtg->tbm.type==0)
                memDC.DrawLabel(_("后 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                else
                memDC.DrawLabel(_("中 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion==ID_QRY_GRAPH_TAILH)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                if(mtg->tbm.type==0)
                memDC.DrawLabel(_("后 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                else
                memDC.DrawLabel(_("中 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                if(mtg->tbm.type==0)
                memDC.DrawLabel(_("后 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                else
                memDC.DrawLabel(_("中 平偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x2=x2+w2-15;
        memDC.SetPen(wxPen(wxColor(0,255,255)));
        memDC.SetBrush(wxBrush(wxColor(0,255,255)));
        memDC.DrawLine(x2,y2,x2+20,y2);
        memDC.DrawRectangle(x2+8,y2-2,5,5);
        //memDC.DrawLabel(_("盾尾高程"),wxRect(x2+30,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        qryButton[ID_QRY_GRAPH_TAILV].x=x2+30;
        qryButton[ID_QRY_GRAPH_TAILV].y=y2-12;
        qryButton[ID_QRY_GRAPH_TAILV].width=75;
        qryButton[ID_QRY_GRAPH_TAILV].height=24;
        if(graphTailv==1)
        {
            if(motion==ID_QRY_GRAPH_TAILV)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                if(mtg->tbm.type==0)
                memDC.DrawLabel(_("后 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                else
                memDC.DrawLabel(_("中 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("√"),wxRect(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                //memDC.SetTextForeground(icolor[0]);
                if(mtg->tbm.type==0)
                memDC.DrawLabel(_("后 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                else
                memDC.DrawLabel(_("中 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion==ID_QRY_GRAPH_TAILV)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                if(mtg->tbm.type==0)
                memDC.DrawLabel(_("后 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                else
                memDC.DrawLabel(_("中 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x2+30,y2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                if(mtg->tbm.type==0)
                memDC.DrawLabel(_("后 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                else
                memDC.DrawLabel(_("中 高偏"),wxRect(x2+30+checkBoxWidth+5,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyQueryDlg::OnPaintLaser(wxPaintEvent& event)
{
    wxPaintDC dc(panelLaser);
    int w,h;
    int a2z=mtg->prj.a2z;

    panelLaser->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(130,135,144)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eni(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        if(bmpLaser.IsOk())
        {
            int w1;
            int h1;
            w1=bmpLaser.GetWidth();
            h1=bmpLaser.GetHeight();
            double s=(w-2)*1.0/w1;
            memDC.SetUserScale(s,s);
            memDC.DrawBitmap(bmpLaser,1,1);
            memDC.SetUserScale(1.0,1.0);
            memDC.SetTextForeground(wxColor(255,255,255));
            memDC.DrawLabel(wxString::Format(_("%.4f"),speckle[0]),wxRect(10,30,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%.4f"),speckle[1]),wxRect(10,60,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%.4f"),speckle[2]),wxRect(10,90,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyQueryDlg::OnDoubleClickLaser(wxMouseEvent& event)
{
    wxFileDialog dlg(this,_("请选择要打开的图片"),_(""),_(""),_("图像文件(*.*)|*.*"),wxFD_OPEN);
    if(dlg.ShowModal()==wxID_OK)
    {
        wxString path=dlg.GetPath();
        if(m_img.LoadFile(path))
        {
            bmpLaser=wxBitmap(m_img);

            unsigned char* uc=m_img.GetData();
            int w,h;
            w=m_img.GetWidth();
            h=m_img.GetHeight();
            int ret;
            ret=laser_image_speckle2(uc,w,h,speckle);
            panelLaser->Refresh();
            wxMessageBox(wxString::Format(_("%d"),ret));
        }
    }
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

        w1=65;
        x1=w-w1-14;
        y1=9;
        h1=26;

        qryButton[ID_QRY_QUIT].x=x1;
        qryButton[ID_QRY_QUIT].y=y1;
        qryButton[ID_QRY_QUIT].width=w1;
        qryButton[ID_QRY_QUIT].height=h1;
        if(motion==ID_QRY_QUIT)
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
        w1=h1*4/3;

        qryButton[ID_QRY_PRT_SCN].x=x1;
        qryButton[ID_QRY_PRT_SCN].y=y1;
        qryButton[ID_QRY_PRT_SCN].width=w1;
        qryButton[ID_QRY_PRT_SCN].height=h1;
        if(motion==ID_QRY_PRT_SCN)
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

        wxPoint pt[3];
        w1=65;
        double len=w1/7.0;
        x1=w/2-w1*2;
        qryButton[ID_QRY_FIRST_PAGE].x=x1;
        qryButton[ID_QRY_FIRST_PAGE].y=y1;
        qryButton[ID_QRY_FIRST_PAGE].width=w1;
        qryButton[ID_QRY_FIRST_PAGE].height=h1;
        if(ires>0)
        {
            if(motion==ID_QRY_FIRST_PAGE)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                memDC.SetPen(ipen[0]);
                pt[0].x=x1+w1/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x+len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
                pt[0].x=pt[0].x-len*0.866025404;
                pt[1].x=pt[1].x-len*0.866025404;
                pt[2].x=pt[2].x-len*0.866025404;
                memDC.DrawPolygon(3,pt);
                memDC.SetPen(wxPen(wxColor(0,0,0)));
                pt[0].y=pt[1].y+1;
                pt[1].x=pt[0].x;
                pt[1].y=pt[2].y;
                memDC.DrawLine(pt[0],pt[1]);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                pt[0].x=x1+w1/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x+len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
                pt[0].x=pt[0].x-len*0.866025404;
                pt[1].x=pt[1].x-len*0.866025404;
                pt[2].x=pt[2].x-len*0.866025404;
                memDC.DrawPolygon(3,pt);
                memDC.SetPen(wxPen(wxColor(0,0,0)));
                pt[0].y=pt[1].y+1;
                pt[1].x=pt[0].x;
                pt[1].y=pt[2].y;
                memDC.DrawLine(pt[0],pt[1]);
            }
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
            memDC.DrawRectangle(x1,y1,w1,h1);
            pt[0].x=x1+w1/2;
            pt[0].y=y1+h1/2;
            pt[1].x=pt[0].x+len*0.866025404;
            pt[1].y=pt[0].y-len/2.0;
            pt[2].x=pt[1].x;
            pt[2].y=pt[1].y+len;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(117,117,117)));
            memDC.DrawPolygon(3,pt);
            pt[0].x=pt[0].x-len*0.866025404;
            pt[1].x=pt[1].x-len*0.866025404;
            pt[2].x=pt[2].x-len*0.866025404;
            memDC.DrawPolygon(3,pt);
            //memDC.SetPen(wxPen(wxColor(0,0,0)));
            pt[0].y=pt[1].y+1;
            pt[1].x=pt[0].x;
            pt[1].y=pt[2].y;
            memDC.DrawLine(pt[0],pt[1]);
        }
        //memDC.DrawLabel(_("第一页"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1-1;
        qryButton[ID_QRY_PREV_PAGE].x=x1;
        qryButton[ID_QRY_PREV_PAGE].y=y1;
        qryButton[ID_QRY_PREV_PAGE].width=w1;
        qryButton[ID_QRY_PREV_PAGE].height=h1;
        if(ires>0)
        {
            if(motion==ID_QRY_PREV_PAGE)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                memDC.SetPen(ipen[0]);
                pt[0].x=x1+w1/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x+len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
                pt[0].x=pt[0].x-len*0.866025404;
                pt[1].x=pt[1].x-len*0.866025404;
                pt[2].x=pt[2].x-len*0.866025404;
                memDC.DrawPolygon(3,pt);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                if(motion==ID_QRY_FIRST_PAGE)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.DrawLine(x1,y1,x1,y1+h1);
                    memDC.SetPen(ipen[0]);
                }
                pt[0].x=x1+w1/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x+len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
                pt[0].x=pt[0].x-len*0.866025404;
                pt[1].x=pt[1].x-len*0.866025404;
                pt[2].x=pt[2].x-len*0.866025404;
                memDC.DrawPolygon(3,pt);
            }
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(motion==ID_QRY_FIRST_PAGE)
            {
                memDC.SetPen(ipen[1]);
                memDC.DrawLine(x1,y1,x1,y1+h1);
                memDC.SetPen(ipen[0]);
            }
            pt[0].x=x1+w1/2;
            pt[0].y=y1+h1/2;
            pt[1].x=pt[0].x+len*0.866025404;
            pt[1].y=pt[0].y-len/2.0;
            pt[2].x=pt[1].x;
            pt[2].y=pt[1].y+len;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(117,117,117)));
            memDC.DrawPolygon(3,pt);
            pt[0].x=pt[0].x-len*0.866025404;
            pt[1].x=pt[1].x-len*0.866025404;
            pt[2].x=pt[2].x-len*0.866025404;
            memDC.DrawPolygon(3,pt);
        }

        int ifrm,frms;
        if(nres==0)
        {
            ifrm=0;
            frms=0;
        }
        else
        {
            ifrm=ires/MXQ+1;
            frms=nres/MXQ+1;
        }


        x1=x1+w1-1;
        qryButton[ID_QRY_NEXT_PAGE].x=x1;
        qryButton[ID_QRY_NEXT_PAGE].y=y1;
        qryButton[ID_QRY_NEXT_PAGE].width=w1;
        qryButton[ID_QRY_NEXT_PAGE].height=h1;
        if(ifrm==frms)
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(motion==ID_QRY_PREV_PAGE)
            {
                memDC.SetPen(ipen[1]);
                memDC.DrawLine(x1,y1,x1,y1+h1);
                memDC.SetPen(ipen[0]);
            }
            pt[0].x=x1+w1/2;
            pt[0].y=y1+h1/2;
            pt[1].x=pt[0].x-len*0.866025404;
            pt[1].y=pt[0].y-len/2.0;
            pt[2].x=pt[1].x;
            pt[2].y=pt[1].y+len;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(117,117,117)));
            memDC.DrawPolygon(3,pt);
            pt[0].x=pt[0].x+len*0.866025404;
            pt[1].x=pt[1].x+len*0.866025404;
            pt[2].x=pt[2].x+len*0.866025404;
            memDC.DrawPolygon(3,pt);
        }
        else
        {
            if(motion==ID_QRY_NEXT_PAGE)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                memDC.SetPen(ipen[0]);
                pt[0].x=x1+w1/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x-len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
                pt[0].x=pt[0].x+len*0.866025404;
                pt[1].x=pt[1].x+len*0.866025404;
                pt[2].x=pt[2].x+len*0.866025404;
                memDC.DrawPolygon(3,pt);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                if(motion==ID_QRY_PREV_PAGE)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.DrawLine(x1,y1,x1,y1+h1);
                    memDC.SetPen(ipen[0]);
                }
                pt[0].x=x1+w1/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x-len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
                pt[0].x=pt[0].x+len*0.866025404;
                pt[1].x=pt[1].x+len*0.866025404;
                pt[2].x=pt[2].x+len*0.866025404;
                memDC.DrawPolygon(3,pt);
            }
        }

        x1=x1+w1-1;
        qryButton[ID_QRY_LAST_PAGE].x=x1;
        qryButton[ID_QRY_LAST_PAGE].y=y1;
        qryButton[ID_QRY_LAST_PAGE].width=w1;
        qryButton[ID_QRY_LAST_PAGE].height=h1;
        if(ifrm==frms)
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(motion==ID_QRY_NEXT_PAGE)
            {
                memDC.SetPen(ipen[1]);
                memDC.DrawLine(x1,y1,x1,y1+h1);
                memDC.SetPen(ipen[0]);
            }
            pt[0].x=x1+w1/2;
            pt[0].y=y1+h1/2;
            pt[1].x=pt[0].x-len*0.866025404;
            pt[1].y=pt[0].y-len/2.0;
            pt[2].x=pt[1].x;
            pt[2].y=pt[1].y+len;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(117,117,117)));
            memDC.DrawPolygon(3,pt);
            pt[0].x=pt[0].x+len*0.866025404;
            pt[1].x=pt[1].x+len*0.866025404;
            pt[2].x=pt[2].x+len*0.866025404;
            memDC.DrawPolygon(3,pt);
            //memDC.SetPen(wxPen(wxColor(0,0,0)));
            pt[0].y=pt[1].y+1;
            pt[1].x=pt[0].x;
            pt[1].y=pt[2].y;
            memDC.DrawLine(pt[0],pt[1]);
        }
        else
        {
            if(motion==ID_QRY_LAST_PAGE)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                memDC.SetPen(ipen[0]);
                pt[0].x=x1+w1/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x-len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
                pt[0].x=pt[0].x+len*0.866025404;
                pt[1].x=pt[1].x+len*0.866025404;
                pt[2].x=pt[2].x+len*0.866025404;
                memDC.DrawPolygon(3,pt);
                memDC.SetPen(wxPen(wxColor(0,0,0)));
                pt[0].y=pt[1].y+1;
                pt[1].x=pt[0].x;
                pt[1].y=pt[2].y;
                memDC.DrawLine(pt[0],pt[1]);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                if(motion==ID_QRY_NEXT_PAGE)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.DrawLine(x1,y1,x1,y1+h1);
                    memDC.SetPen(ipen[0]);
                }
                pt[0].x=x1+w1/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x-len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
                pt[0].x=pt[0].x+len*0.866025404;
                pt[1].x=pt[1].x+len*0.866025404;
                pt[2].x=pt[2].x+len*0.866025404;
                memDC.DrawPolygon(3,pt);
                memDC.SetPen(wxPen(wxColor(0,0,0)));
                pt[0].y=pt[1].y+1;
                pt[1].x=pt[0].x;
                pt[1].y=pt[2].y;
                memDC.DrawLine(pt[0],pt[1]);
            }
        }
        memDC.SetTextForeground(wxColor(0,0,255));
        if(msg!=wxEmptyString) memDC.DrawLabel(msg,wxRect(56,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyQueryDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>qryButton[ID_QRY_EXP].y && y<qryButton[ID_QRY_EXP].y+qryButton[ID_QRY_EXP].height)
    {
        if(x>qryButton[ID_QRY_QUIT].x && x<qryButton[ID_QRY_QUIT].x+qryButton[ID_QRY_QUIT].width)
        {
            motion=ID_QRY_QUIT;
        }
        else if(x>qryButton[ID_QRY_PRT_SCN].x && x<qryButton[ID_QRY_PRT_SCN].x+qryButton[ID_QRY_PRT_SCN].width)
        {
            motion=ID_QRY_PRT_SCN;
        }
        else if(x>qryButton[ID_QRY_FIRST_PAGE].x && x<qryButton[ID_QRY_FIRST_PAGE].x+qryButton[ID_QRY_FIRST_PAGE].width)
        {
            motion=ID_QRY_FIRST_PAGE;
        }
        else if(x>qryButton[ID_QRY_PREV_PAGE].x && x<qryButton[ID_QRY_PREV_PAGE].x+qryButton[ID_QRY_PREV_PAGE].width)
        {
            motion=ID_QRY_PREV_PAGE;
        }
        else if(x>qryButton[ID_QRY_NEXT_PAGE].x && x<qryButton[ID_QRY_NEXT_PAGE].x+qryButton[ID_QRY_NEXT_PAGE].width)
        {
            motion=ID_QRY_NEXT_PAGE;
        }
        else if(x>qryButton[ID_QRY_LAST_PAGE].x && x<qryButton[ID_QRY_LAST_PAGE].x+qryButton[ID_QRY_LAST_PAGE].width)
        {
            motion=ID_QRY_LAST_PAGE;
        }
        else
        {
            motion=ID_QRY_NONE;
        }
    }
    else
    {
        motion=ID_QRY_NONE;
    }
    panelBottom->Refresh();
}

void MyQueryDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_QRY_NONE;
    panelBottom->Refresh();
}

void MyQueryDlg::OnClickBottom(wxMouseEvent& event)
{
    int ifrm,frms;
    if(nres==0)
    {
        ifrm=0;
        frms=0;
    }
    else
    {
        ifrm=ires/MXQ+1;
        frms=nres/MXQ+1;
    }
    if(motion==ID_QRY_QUIT)
    {
        Destroy();
    }
    else if(motion==ID_QRY_PRT_SCN)
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
        str=_("查询界面");
        str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
        }
    }
    else if(motion==ID_QRY_FIRST_PAGE)
    {
        if(ires==0) return;
        ires=0;
        ifrm=1;
        msg=wxString::Format(_("%d"),nres)+_(" 条记录！");
        msg=msg+wxString::Format(_(" 第 %d 页 共 %d 页"),ifrm,frms);
        ShowResults();
    }
    else if(motion==ID_QRY_PREV_PAGE)
    {
        if(ires==0) return;
        if(ires-MXQ<0)
        {
            ires=0;
            ifrm=1;
        }
        else
        {
            ires=ires-MXQ;
            ifrm=ifrm-1;
        }
        msg=wxString::Format(_("%d"),nres)+_(" 条记录！");
        //int frms=nres/MXQ;
        msg=msg+wxString::Format(_(" 第 %d 页 共 %d 页"),ifrm,frms);
        ShowResults();
    }
    else if(motion==ID_QRY_NEXT_PAGE)
    {
        if(ires+MXQ<nres-1)
        {
            //wxMessageBox(wxString::Format(_("%d,%d"),ires,nres));
            ires=ires+MXQ;
            ifrm=ifrm+1;
        }
        else
        {
            return;
        }
        msg=wxString::Format(_("%d"),nres)+_(" 条记录！");
        //int frms=nres/MXQ;
        msg=msg+wxString::Format(_(" 第 %d 页 共 %d 页"),ifrm,frms);
        ShowResults();
    }
    else if(motion==ID_QRY_LAST_PAGE)
    {
        while(ires+MXQ>=nres-1) return;
        while(ires+MXQ<nres-1)
        {
            ires=ires+MXQ;
            //if(ires+MXQ>=nres) break;
        }
        msg=wxString::Format(_("%d"),nres)+_(" 条记录！");
        //int frms=nres/MXQ;
        ifrm=frms;
        msg=msg+wxString::Format(_(" 第 %d 页 共 %d 页"),ifrm,frms);
        ShowResults();
    }

    panelBottom->Refresh();
}

void MyQueryDlg::CalSegments()
{
    if(nres<=0) return;
    int row=m_gridSegment->GetNumberRows();
    m_gridSegment->DeleteRows(0,row);

    int i=1;
    int index=0;

    double ihead[3];
    double itail[3];
    double inc[3];
    double len1;
    double len[2];
    double li,xi,yi,zi,dh,dv;
    int n1,n2;

    while(i<nres-1)
    {
        n1=res[i].iseg;
        n2=res[i+1].iseg;
        //trace(0,"query:seg1=%d,seg2=%d\n",n1,n2);
        if(n1>n2)
        {
            if(mtg->tbm.type<2)    ///无铰接+盾尾铰接
            {
                itail[0]=res[i].tail[0];
                itail[1]=res[i].tail[1];
                itail[2]=res[i].tail[2];
                inc[1]=res[i].inc1[1]*PI/180;
                inc[2]=res[i].inc1[2]*PI/180;
                len1=mtg->ilen;
                if(res[i].aj[0]==0.0 && res[i].aj[1]==0.0 && res[i].aj[2]==0.0 && res[i].aj[3]==0.0)
                {
                    len[0]=mtg->tbm.L[3]+mtg->segset.L;
                }
                else
                {
                    len[0]=mtg->tbm.L[3]+(res[i].aj[0]+res[i].aj[1]+res[i].aj[2]+res[i].aj[3])/4.0;
                }
                len[1]=len1-len[0];
            }
            else
            {
                if(mtg->tarset.pos==0)
                {
                    itail[0]=res[i].tail1[0];
                    itail[1]=res[i].tail1[1];
                    itail[2]=res[i].tail1[2];
                    inc[1]=res[i].inc2[1]*PI/180;
                    inc[2]=res[i].inc2[2]*PI/180;
                    len1=mtg->ilen;
                    if(res[i].aj[0]==0.0 && res[i].aj[1]==0.0 && res[i].aj[2]==0.0 && res[i].aj[3]==0.0)
                    {
                        len[0]=mtg->tbm.L[3]-len1+mtg->segset.L;
                    }
                    else
                    {
                        len[0]=mtg->tbm.L[3]-len1+(res[i].aj[0]+res[i].aj[1]+res[i].aj[2]+res[i].aj[3])/4.0;
                    }

                    if(mtg->tbm.type==2) len[1]=mtg->tbm.L[2]-len[0];
                    else len[1]=mtg->tbm.L[1]-len[0];
                }
                else if(mtg->tarset.pos==1)
                {
                    itail[0]=res[i].tail[0];
                    itail[1]=res[i].tail[1];
                    itail[2]=res[i].tail[2];
                    inc[1]=res[i].inc1[1]*PI/180;
                    inc[2]=res[i].inc1[2]*PI/180;

                    len1=mtg->ilen;
                    if(res[i].aj[0]==0.0 && res[i].aj[1]==0.0 && res[i].aj[2]==0.0 && res[i].aj[3]==0.0)
                    {
                        len[0]=mtg->tbm.L[3]-mtg->tbm.L[0]+mtg->segset.L;
                    }
                    else
                    {
                        mtg->tbm.L[3]-mtg->tbm.L[0]+(res[i].aj[0]+res[i].aj[1]+res[i].aj[2]+res[i].aj[3])/4.0;
                    }
                    len[1]=len1-len[0];
                }
            }

            len1=len[1];
            xi=itail[0]+len1*cos(inc[1])*cos(inc[2]);
            yi=itail[1]+len1*cos(inc[1])*sin(inc[2]);
            zi=itail[2]+len1*sin(inc[1]);

            road_xy2l(&mtg->r,xi,yi,&li,0,0,0,&dh);
            road_l2h(&mtg->r,li,&dv,0);
            dv=zi-dv;
            dh=dh*mtg->prj.a2z;
            m_gridSegment->InsertRows(index,1);
            int j=0;
            m_gridSegment->SetRowLabelValue(index,wxString::Format(_("%d"),n1));
            m_gridSegment->SetCellValue(index,j++,wxString::Format(_("%.4f"),li)); ///里程
            m_gridSegment->SetCellValue(index,j++,wxString::Format(_("%.4f"),xi)); ///
            m_gridSegment->SetCellValue(index,j++,wxString::Format(_("%.4f"),yi)); ///
            m_gridSegment->SetCellValue(index,j++,wxString::Format(_("%.4f"),zi)); ///
            m_gridSegment->SetCellValue(index,j++,wxString::Format(_("%.1f"),dh*1000.0)); ///
            m_gridSegment->SetCellValue(index,j++,wxString::Format(_("%.1f"),dv*1000.0)); ///
            m_gridSegment->SetCellValue(index,j++,wxDateTime(res[i].t1).Format(_("%Y-%m-%d %H:%M:%S"))); ///日期
            index++;
        }
        i++;
    }
}

//void MyQueryDlg::UpdateSegs()
//{
//    int row=m_gridSegment->GetNumberRows();
//    if(row<nseg)
//    {
//        m_gridSegment->InsertRows(row,nseg-row);
//    }
//    else
//    {
//        m_gridSegment->DeleteRows(nseg,row-nseg);
//    }
//    for(int i=0;i<nseg;i++)
//    {
//        int j=0;
//        int nmoff;
//        nmoff=road_number_mile_off(&mtg->r);
//        if(nmoff>0&&mtg->iset.vileage==0)
//        {
//            m_offset *mo={0};
//            for(int nn=nmoff-1;nn>=0;nn--)
//            {
//                mo=road_mile_off(&mtg->r,nn);
//                if(segs[i].mile>mo->mile)
//                {
//                    segs[i].mile=segs[i].mile+mo->off;
//                    break;
//                }
//            }
//        }
//        m_gridSegment->SetRowLabelValue(i,wxString::Format(_("%d"),segs[i].numb));
//        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.4f"),segs[i].mile)); ///里程
//        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.4f"),segs[i].x)); ///
//        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.4f"),segs[i].y)); ///
//        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.4f"),segs[i].z)); ///
//        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.1f"),segs[i].dh*1000.0)); ///
//        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.1f"),segs[i].dv*1000.0)); ///
//        m_gridSegment->SetCellValue(i,j++,wxDateTime(segs[i].t).Format(_("%Y-%m-%d %H:%M:%S"))); ///日期
//    }
//}
//
//void MyQueryDlg::ShowResults()
//{
//    ///历史数据m_gridHistory
//    sleepms(50);
//    //wxMessageBox(_("ok"));
//    mxn=nres-ires;
//    if(mxn<=0) return;
//    if(mxn>MXQ) mxn=MXQ;
//
//    int row=m_gridHistory->GetNumberRows();
//    //trace(0,"qry:ires=%d,mxn=%d,row=%d\n",ires,mxn,row);
//    if(row<mxn)
//    {
//        m_gridHistory->InsertRows(row,mxn-row);
//    }
//    else
//    {
//        m_gridHistory->DeleteRows(mxn,row-mxn);
//    }
//    mxdev=0;
//
//    for(int i=0;i<mxn;i++)
//    {
//        int j=0;
//        int k=ires+i;
//        int nmoff;
//        nmoff=road_number_mile_off(&mtg->r);
//        if(nmoff>0&&mtg->iset.vileage==0)
//        {
//            m_offset *mo={0};
//            for(int nn=nmoff-1;nn>=0;nn--)
//            {
//                mo=road_mile_off(&mtg->r,nn);
//                if(res[k].headc>mo->mile)
//                {
//                    res[k].headc=res[k].headc+mo->off;
//                    break;
//                }
//            }
//        }
//        m_gridHistory->SetRowLabelValue(i,wxString::Format(_("%d"),res[k].iseg));
//        //m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),res[i].iseg)); ///管片号
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].headc)); ///盾首里程
//        //m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[i].tail_chainage)); ///盾尾里程
//        m_gridHistory->SetCellTextColour(i,j,wxColor(255,0,255));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].hdev1*1000))); ///前
//        m_gridHistory->SetCellTextColour(i,j,wxColor(255,156,0));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].hdev2*1000))); ///中
//        m_gridHistory->SetCellTextColour(i,j,wxColor(0,156,255));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].hdev3*1000))); ///后
//        m_gridHistory->SetCellTextColour(i,j,wxColor(0,255,0));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].vdev1*1000))); ///前
//        m_gridHistory->SetCellTextColour(i,j,wxColor(0,0,255));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].vdev2*1000))); ///中
//        m_gridHistory->SetCellTextColour(i,j,wxColor(0,255,255));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].vdev3*1000))); ///后
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].inc1[0])); ///侧转
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].inc1[1])); ///俯仰
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].inc1[2])); ///方位
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[0])); ///盾首计算坐标
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[1]));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[2]));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[0]));///盾尾计算坐标
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[1]));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[2]));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[0])); ///盾首设计坐标
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[1]));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[2]));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[0]));///盾尾设计坐标
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[1]));
//        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[2]));
//        //if(wxGetApp().m_Position._prism_used[0])
//        {
//            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].prism[0]));///棱镜1归一值
//            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].prism[1]));
//            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].prism[2]));
//        }
//
//        {
//            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].angle[0]*180.0/PI));///耙1
//            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].angle[1]*180.0/PI));
//        }
//
//        {
//            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].cam[2]));///耙1
//            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].cam[3]));
//        }
//
//        {
//            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].cam[0]));///耙2
//            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].cam[1]));
//        }
//
//        //if(wxGetApp().m_Position._position_type==POSITION_TYPE_BINARY)
//        {
//            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].inc[0])); ///侧转
//            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].inc[1])); ///俯仰
//        }
//        m_gridHistory->SetCellValue(i,j++,wxDateTime(res[k].t1).Format(_("%Y-%m-%d %H:%M:%S"))); ///日期
//        if(fabs(res[k].headh)>mxdev) mxdev=fabs(res[k].headh);
//        if(fabs(res[k].headv)>mxdev) mxdev=fabs(res[k].headv);
//        if(fabs(res[k].tailh)>mxdev) mxdev=fabs(res[k].tailh);
//        if(fabs(res[k].tailv)>mxdev) mxdev=fabs(res[k].tailv);
//        //trace(0,"qry:i=%d,cam=%.4f\n",i,res[k].cam[0]);
//        //m_gridHistory->SetRowLabelValue(i,wxDateTime(res[i].t1).Format(_("%Y-%m-%d %H:%M:%S")));
//    }
//    mxdev=mxdev*1000.0;
//    while(mxdev>dev*3)
//    {
//        if(dev>65) break;
//        dev=dev+5;
//    }
//    ol=res[ires+mxn-1].tailc;
//    el=res[ires].headc;
//    //msg=wxString::Format(_("%d"),ires);
//    panelGraph->Refresh();
//    panelBottom->Refresh();
//
//    int n1=res[ires].iseg;
//    int n2=res[ires+mxn-1].iseg;
//    nseg=0;
//    if(segs) free(segs);
//    segs=0;
//    nseg=mtg_query_seged(mtg,n1,n2,&segs);
//    if(mxn>0 && nseg==0) CalSegments();
//    else UpdateSegs();
//    ///偏差曲线
//    //CreateDiffHorizon();
//    //CreateDiffVertical();
//}
//
//void MyQueryDlg::Report()
//{
//    if(page==ID_QRY_PAGE_SEGS)
//    {
//        if(nres<=0 && nseg<=0) return;
//        wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
//        if(fileDlg.ShowModal()==wxID_OK)
//        {
//            wxString strFile=fileDlg.GetPath();
//            FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
//            if(fp)
//            {
//                fprintf(fp,wxString(_("管片号,管环里程,管环X,管环Y,管环Z,水平偏差（mm）,垂直偏差（mm）,时间\n")).mb_str(wxConvLocal));
//                int row=m_gridSegment->GetNumberRows();
//                wxString istr;
//                for(int i=0;i<row;i++)
//                {
//                    int j=0;
//                    istr=m_gridSegment->GetRowLabelValue(i)+_(",");
//                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
//                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
//                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
//                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
//                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
//                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
//                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
//                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
//                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
//                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
//                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
//                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
//                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
//                    istr=m_gridSegment->GetCellValue(i,j++);
//                    fprintf(fp,"%s\n",(const char*)istr.mb_str(wxConvLocal));
//                }
//                fclose(fp);
//                wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
//            }
//        }
//    }
//    else
//    {
//        if(nres<=0) return;
//
//        wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
//        if(fileDlg.ShowModal()==wxID_OK)
//        {
//            wxString strFile=fileDlg.GetPath();
//            FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
//            if(fp)
//            {
//                fprintf(fp,wxString(_("管片号,刀盘里程,盾首平面,盾首高程,盾尾平面,盾尾高程,滚动,俯仰,方位,盾首（实测）x,盾首（实测）y,盾首（实测）z,盾首（设计）x,盾首（设计）y,盾首（设计）z,盾尾（实测）x,盾尾（实测）y,盾尾（实测）z,盾尾（设计）x,盾尾（设计）y,盾尾（设计）z,棱镜x,棱镜y,棱镜z,水平角,竖直角,前屏X,前屏Y,后屏X,后屏Y,转动,俯仰,转动,俯仰,时间\n")).mb_str(wxConvLocal));
//                for(int i=0;i<nres;i++)
//                {
//                    fprintf(fp,"%d,",res[i].iseg);
//                    fprintf(fp,"%.3f,",res[i].headc);
//                    fprintf(fp,"%d,",(int)(res[i].headh*1000.0));
//                    fprintf(fp,"%d,",(int)(res[i].headv*1000.0));
//                    fprintf(fp,"%d,",(int)(res[i].tailh*1000.0));
//                    fprintf(fp,"%d,",(int)(res[i].tailv*1000.0));
//                    fprintf(fp,"%.3f,",res[i].inc1[0]);
//                    fprintf(fp,"%.3f,",res[i].inc1[1]);
//                    fprintf(fp,"%.3f,",res[i].inc1[2]);
//                    fprintf(fp,"%.3f,",res[i].head[0]);
//                    fprintf(fp,"%.3f,",res[i].head[1]);
//                    fprintf(fp,"%.3f,",res[i].head[2]);
//                    fprintf(fp,"%.3f,",res[i].hdes[0]);
//                    fprintf(fp,"%.3f,",res[i].hdes[1]);
//                    fprintf(fp,"%.3f,",res[i].hdes[2]);
//                    fprintf(fp,"%.3f,",res[i].tail[0]);
//                    fprintf(fp,"%.3f,",res[i].tail[1]);
//                    fprintf(fp,"%.3f,",res[i].tail[2]);
//                    fprintf(fp,"%.3f,",res[i].tdes[0]);
//                    fprintf(fp,"%.3f,",res[i].tdes[1]);
//                    fprintf(fp,"%.3f,",res[i].tdes[2]);
//                    fprintf(fp,"%.3f,",res[i].prism[0]);
//                    fprintf(fp,"%.3f,",res[i].prism[1]);
//                    fprintf(fp,"%.3f,",res[i].prism[2]);
//                    fprintf(fp,"%.3f,",res[i].angle[0]);
//                    fprintf(fp,"%.3f,",res[i].angle[1]);
//                    fprintf(fp,"%.3f,",res[i].cam[2]);
//                    fprintf(fp,"%.3f,",res[i].cam[3]);
//                    fprintf(fp,"%.3f,",res[i].cam[0]);
//                    fprintf(fp,"%.3f,",res[i].cam[1]);
//                    fprintf(fp,"%.4f,",res[i].inc[0]);
//                    fprintf(fp,"%.4f,",res[i].inc[1]);
//                    fprintf(fp,"%.4f,",res[i].inc[3]);
//                    fprintf(fp,"%.4f,",res[i].inc[4]);
//                    wxString strt=wxDateTime(res[i].t1).Format(_("%Y-%m-%d %H:%M:%S"));
//                    fprintf(fp,"%s\n",(const char*)strt.mb_str(wxConvLocal));
//                }
//                fclose(fp);
//                wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
//            }
//        }
//    }
//
//}

void MyQueryDlg::UpdateSegs()
{
    int row=m_gridSegment->GetNumberRows();
    if(row<nseg)
    {
        m_gridSegment->InsertRows(row,nseg-row);
    }
    else
    {
        m_gridSegment->DeleteRows(nseg,row-nseg);
    }
    for(int i=0;i<nseg;i++)
    {
        int j=0;
        if(mtg->iset.vmileage==0)
        {
            int nmoff;
            nmoff=road_number_mile_off(&mtg->r);
            if(nmoff>0)
            {
                m_offset *mo={0};
                for(int nn=nmoff-1;nn>=0;nn--)
                {
                    mo=road_mile_off(&mtg->r,nn);
                    if(segs[i].mile>mo->mile)
                    {
                        segs[i].mile=segs[i].mile+mo->off;
                        break;
                    }
                }
            }
        }
        m_gridSegment->SetRowLabelValue(i,wxString::Format(_("%d"),segs[i].numb));
        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.4f"),segs[i].mile)); ///里程
        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.4f"),segs[i].x)); ///
        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.4f"),segs[i].y)); ///
        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.4f"),segs[i].z)); ///
        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.1f"),segs[i].dh*1000.0)); ///
        m_gridSegment->SetCellValue(i,j++,wxString::Format(_("%.1f"),segs[i].dv*1000.0)); ///
        m_gridSegment->SetCellValue(i,j++,wxDateTime(segs[i].t).Format(_("%Y-%m-%d %H:%M:%S"))); ///日期
    }
}

void MyQueryDlg::ShowResults()
{
    ///历史数据m_gridHistory
    sleepms(50);
    //wxMessageBox(_("ok"));
    mxn=nres-ires;
    if(mxn<=0) return;
    if(mxn>MXQ) mxn=MXQ;

    int row=m_gridHistory->GetNumberRows();
    //trace(0,"qry:ires=%d,mxn=%d,row=%d\n",ires,mxn,row);
    if(row<mxn)
    {
        m_gridHistory->InsertRows(row,mxn-row);
    }
    else
    {
        m_gridHistory->DeleteRows(mxn,row-mxn);
    }
    mxdev=0;

    for(int i=0;i<mxn;i++)
    {
        int j=0;
        int k=ires+i;
        int nmoff;
        nmoff=road_number_mile_off(&mtg->r);
        if(nmoff>0&&mtg->iset.vmileage==0)
        {
            m_offset *mo={0};
            for(int nn=nmoff-1;nn>=0;nn--)
            {
                mo=road_mile_off(&mtg->r,nn);
                if(res[k].mile1>mo->mile)
                {
                    res[k].mile1=res[k].mile1+mo->off;
                    break;
                }
            }
        }
        m_gridHistory->SetRowLabelValue(i,wxString::Format(_("%d"),res[k].iseg));
        //m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),res[i].iseg)); ///管片号
        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].mile1)); ///盾首里程
        //m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[i].tail_chainage)); ///盾尾里程
        m_gridHistory->SetCellTextColour(i,j,wxColor(255,0,255));
        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].hdev1*1000))); ///前
        m_gridHistory->SetCellTextColour(i,j,wxColor(255,156,0));
        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].hdev2*1000))); ///中
        m_gridHistory->SetCellTextColour(i,j,wxColor(0,156,255));
        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].hdev3*1000))); ///后
        m_gridHistory->SetCellTextColour(i,j,wxColor(0,255,0));
        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].vdev1*1000))); ///前
        m_gridHistory->SetCellTextColour(i,j,wxColor(0,0,255));
        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].vdev2*1000))); ///中
        m_gridHistory->SetCellTextColour(i,j,wxColor(0,255,255));
        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%d"),(int)(res[k].vdev3*1000))); ///后
        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].inc1[0])); ///侧转
        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].inc1[1])); ///俯仰
        m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].inc1[2])); ///方位

        if(mtg->tbm.type==0)
        {
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[0])); ///盾首计算坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("--")));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("--")));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("--")));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[0]));///盾尾计算坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[0])); ///盾首设计坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("--")));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("--")));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("--")));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[0]));///盾尾设计坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[2]));
        }
        else if(mtg->tbm.type==1)
        {
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[0])); ///盾首计算坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[0]));///盾中计算坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].ht[0]));///盾尾计算坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].ht[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].ht[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[0])); ///盾首设计坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[0]));///盾中设计坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].htdes[0]));///盾尾计算坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].htdes[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].htdes[2]));
        }
        else if(mtg->tbm.type==2)
        {
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].ht[0]));///盾首计算坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].ht[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].ht[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[0])); ///盾中计算坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].head[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[0]));///盾尾计算坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tail[2]));

            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].htdes[0]));///盾首计算坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].htdes[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].htdes[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[0])); ///盾中设计坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].hdes[2]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[0]));///盾尾设计坐标
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].tdes[2]));
        }
        //if(wxGetApp().m_Position._prism_used[0])
        {
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].prism[0]));///棱镜1归一值
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].prism[1]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].prism[2]));
        }

        {
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].angle[0]*180.0/PI));///耙1
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].angle[1]*180.0/PI));
        }

        {
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].cam[2]));///耙1
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].cam[3]));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].comp[0]*180.0/PI));
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].comp[1]*180.0/PI));
        }

        {
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].cam[0]));///耙2
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].cam[1]));
        }

        //if(wxGetApp().m_Position._position_type==POSITION_TYPE_BINARY)
        {
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].inc[0])); ///侧转
            m_gridHistory->SetCellValue(i,j++,wxString::Format(_("%.4f"),res[k].inc[1])); ///俯仰
        }
        m_gridHistory->SetCellValue(i,j++,wxDateTime(res[k].t1).Format(_("%Y-%m-%d %H:%M:%S"))); ///日期
        if(fabs(res[k].headh)>mxdev) mxdev=fabs(res[k].headh);
        if(fabs(res[k].headv)>mxdev) mxdev=fabs(res[k].headv);
        if(fabs(res[k].tailh)>mxdev) mxdev=fabs(res[k].tailh);
        if(fabs(res[k].tailv)>mxdev) mxdev=fabs(res[k].tailv);
        //trace(0,"qry:i=%d,cam=%.4f\n",i,res[k].cam[0]);
        //m_gridHistory->SetRowLabelValue(i,wxDateTime(res[i].t1).Format(_("%Y-%m-%d %H:%M:%S")));
    }
    mxdev=mxdev*1000.0;
    while(mxdev>dev*3)
    {
        if(dev>65) break;
        dev=dev+5;
    }
    ol=res[ires+mxn-1].tailc;
    el=res[ires].headc;
    //msg=wxString::Format(_("%d"),ires);
    panelGraph->Refresh();
    panelBottom->Refresh();

    int n1=res[ires].iseg;
    int n2=res[ires+mxn-1].iseg;
    nseg=0;
    if(segs) free(segs);
    segs=0;
    nseg=mtg_query_seged(mtg,n1,n2,&segs);
    if(mxn>0 && nseg==0) CalSegments();
    else UpdateSegs();
    ///偏差曲线
    //CreateDiffHorizon();
    //CreateDiffVertical();
}

void MyQueryDlg::Report()
{
    if(page==ID_QRY_PAGE_SEGS)
    {
        if(nres<=0 && nseg<=0) return;
        wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
            if(fp)
            {
                fprintf(fp,wxString(_("管片号,管环里程,管环X,管环Y,管环Z,水平偏差（mm）,垂直偏差（mm）,时间\n")).mb_str(wxConvLocal));
                int row=m_gridSegment->GetNumberRows();
                wxString istr;
                for(int i=0;i<row;i++)
                {
                    int j=0;
                    istr=m_gridSegment->GetRowLabelValue(i)+_(",");
                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
                    istr=m_gridSegment->GetCellValue(i,j++)+_(",");
                    fprintf(fp,"%s",(const char*)istr.mb_str(wxConvLocal));
                    istr=m_gridSegment->GetCellValue(i,j++);
                    fprintf(fp,"%s\n",(const char*)istr.mb_str(wxConvLocal));
                }
                fclose(fp);
                wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
            }
        }
    }
    else
    {
        if(nres<=0) return;

        wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
            if(fp)
            {
                fprintf(fp,wxString(_("管片号,切口里程,盾首平面,盾首高程,盾中平面,盾中高程,盾尾平面,盾尾高程,滚动,俯仰,方位,盾首（实测）x,盾首（实测）y,盾首（实测）z,盾首（设计）x,盾首（设计）y,盾首（设计）z,盾中（实测）x,盾中（实测）y,盾中（实测）z,盾中（设计）x,盾中（设计）y,盾中（设计）z,盾尾（实测）x,盾尾（实测）y,盾尾（实测）z,盾尾（设计）x,盾尾（设计）y,盾尾（设计）z,棱镜x,棱镜y,棱镜z,水平角,竖直角,气泡L,气泡T,前屏X,前屏Y,后屏X,后屏Y,转动,俯仰,转动,俯仰,时间\n")).mb_str(wxConvLocal));
                for(int i=0;i<nres;i++)
                {
                    fprintf(fp,"%d,",res[i].iseg);
                    fprintf(fp,"%.3f,",res[i].mile1);///该里程在showresults中已经计算
                    fprintf(fp,"%d,",(int)(res[i].hdev1*1000.0));
                    fprintf(fp,"%d,",(int)(res[i].vdev1*1000.0));
                    fprintf(fp,"%d,",(int)(res[i].hdev2*1000.0));
                    fprintf(fp,"%d,",(int)(res[i].vdev2*1000.0));
                    fprintf(fp,"%d,",(int)(res[i].hdev3*1000.0));
                    fprintf(fp,"%d,",(int)(res[i].vdev3*1000.0));
                    fprintf(fp,"%.3f,",res[i].inc1[0]);
                    fprintf(fp,"%.3f,",res[i].inc1[1]);
                    fprintf(fp,"%.3f,",res[i].inc1[2]);
                    if(mtg->tbm.type==0)
                    {
                        fprintf(fp,"%.3f,",res[i].head[0]);
                        fprintf(fp,"%.3f,",res[i].head[1]);
                        fprintf(fp,"%.3f,",res[i].head[2]);
                        fprintf(fp,"%.3f,",res[i].hdes[0]);
                        fprintf(fp,"%.3f,",res[i].hdes[1]);
                        fprintf(fp,"%.3f,",res[i].hdes[2]);
                        fprintf(fp,"--,");
                        fprintf(fp,"--,");
                        fprintf(fp,"--,");
                        fprintf(fp,"--,");
                        fprintf(fp,"--,");
                        fprintf(fp,"--,");

                        fprintf(fp,"%.3f,",res[i].tail[0]);
                        fprintf(fp,"%.3f,",res[i].tail[1]);
                        fprintf(fp,"%.3f,",res[i].tail[2]);
                        fprintf(fp,"%.3f,",res[i].tdes[0]);
                        fprintf(fp,"%.3f,",res[i].tdes[1]);
                        fprintf(fp,"%.3f,",res[i].tdes[2]);
                    }
                    else if(mtg->tbm.type==1)
                    {
                        fprintf(fp,"%.3f,",res[i].head[0]);
                        fprintf(fp,"%.3f,",res[i].head[1]);
                        fprintf(fp,"%.3f,",res[i].head[2]);
                        fprintf(fp,"%.3f,",res[i].hdes[0]);
                        fprintf(fp,"%.3f,",res[i].hdes[1]);
                        fprintf(fp,"%.3f,",res[i].hdes[2]);

                        fprintf(fp,"%.3f,",res[i].tail[0]);
                        fprintf(fp,"%.3f,",res[i].tail[1]);
                        fprintf(fp,"%.3f,",res[i].tail[2]);
                        fprintf(fp,"%.3f,",res[i].tdes[0]);
                        fprintf(fp,"%.3f,",res[i].tdes[1]);
                        fprintf(fp,"%.3f,",res[i].tdes[2]);

                        fprintf(fp,"%.3f,",res[i].ht[0]);
                        fprintf(fp,"%.3f,",res[i].ht[1]);
                        fprintf(fp,"%.3f,",res[i].ht[2]);
                        fprintf(fp,"%.3f,",res[i].htdes[0]);
                        fprintf(fp,"%.3f,",res[i].htdes[1]);
                        fprintf(fp,"%.3f,",res[i].htdes[2]);
                    }
                    else if(mtg->tbm.type==2)
                    {
                        fprintf(fp,"%.3f,",res[i].ht[0]);
                        fprintf(fp,"%.3f,",res[i].ht[1]);
                        fprintf(fp,"%.3f,",res[i].ht[2]);
                        fprintf(fp,"%.3f,",res[i].htdes[0]);
                        fprintf(fp,"%.3f,",res[i].htdes[1]);
                        fprintf(fp,"%.3f,",res[i].htdes[2]);

                        fprintf(fp,"%.3f,",res[i].head[0]);
                        fprintf(fp,"%.3f,",res[i].head[1]);
                        fprintf(fp,"%.3f,",res[i].head[2]);
                        fprintf(fp,"%.3f,",res[i].hdes[0]);
                        fprintf(fp,"%.3f,",res[i].hdes[1]);
                        fprintf(fp,"%.3f,",res[i].hdes[2]);

                        fprintf(fp,"%.3f,",res[i].tail[0]);
                        fprintf(fp,"%.3f,",res[i].tail[1]);
                        fprintf(fp,"%.3f,",res[i].tail[2]);
                        fprintf(fp,"%.3f,",res[i].tdes[0]);
                        fprintf(fp,"%.3f,",res[i].tdes[1]);
                        fprintf(fp,"%.3f,",res[i].tdes[2]);
                    }
                    fprintf(fp,"%.3f,",res[i].prism[0]);
                    fprintf(fp,"%.3f,",res[i].prism[1]);
                    fprintf(fp,"%.3f,",res[i].prism[2]);
                    fprintf(fp,"%.3f,",res[i].angle[0]);
                    fprintf(fp,"%.3f,",res[i].angle[1]);
                    fprintf(fp,"%.4f,",res[i].comp[0]);
                    fprintf(fp,"%.4f,",res[i].comp[1]);
                    fprintf(fp,"%.3f,",res[i].cam[2]);
                    fprintf(fp,"%.3f,",res[i].cam[3]);
                    fprintf(fp,"%.3f,",res[i].cam[0]);
                    fprintf(fp,"%.3f,",res[i].cam[1]);
                    fprintf(fp,"%.4f,",res[i].inc[0]);
                    fprintf(fp,"%.4f,",res[i].inc[1]);
                    fprintf(fp,"%.4f,",res[i].inc[4]);
                    fprintf(fp,"%.4f,",res[i].inc[3]);
                    wxString strt=wxDateTime(res[i].t1).Format(_("%Y-%m-%d %H:%M:%S"));
                    fprintf(fp,"%s\n",(const char*)strt.mb_str(wxConvLocal));
                }
                fclose(fp);
                wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
            }
        }
    }
}

void MyQueryDlg::OnPaintMain(wxPaintEvent& event)
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

void MyQueryDlg::OnPaintPage(wxPaintEvent& event)
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
        qryButton[ID_QRY_PAGE_MEAS].x=x1;
        qryButton[ID_QRY_PAGE_MEAS].y=y1;
        qryButton[ID_QRY_PAGE_MEAS].width=w1;
        qryButton[ID_QRY_PAGE_MEAS].height=h1;

        if(page==ID_QRY_PAGE_MEAS || motion==ID_QRY_PAGE_MEAS)
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

            if(page!=ID_QRY_PAGE_MEAS)
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
        memDC.DrawLabel(_("历史数据"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1+w1-1,y1,x1+w1-1,y1+h1);

        x1=x1+w1;
        qryButton[ID_QRY_PAGE_CHART].x=x1;
        qryButton[ID_QRY_PAGE_CHART].y=y1;
        qryButton[ID_QRY_PAGE_CHART].width=w1;
        qryButton[ID_QRY_PAGE_CHART].height=h1;
        if(page==ID_QRY_PAGE_CHART || motion==ID_QRY_PAGE_CHART)
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

            if(page!=ID_QRY_PAGE_CHART)
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
        memDC.DrawLabel(_("偏差曲线"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1+w1-1,y1,x1+w1-1,y1+h1);

        x1=x1+w1;
        qryButton[ID_QRY_PAGE_SEGS].x=x1;
        qryButton[ID_QRY_PAGE_SEGS].y=y1;
        qryButton[ID_QRY_PAGE_SEGS].width=w1;
        qryButton[ID_QRY_PAGE_SEGS].height=h1;
        if(page==ID_QRY_PAGE_SEGS || motion==ID_QRY_PAGE_SEGS)
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

            if(page!=ID_QRY_PAGE_SEGS)
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
        memDC.DrawLabel(_("管环姿态"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,w,y1);
        //memDC.DrawLine(x1+w1-1,y1,x1+w1-1,y1+h1);

        if(iver==2)
        {
            x1=x1+w1;
            qryButton[ID_QRY_PAGE_LASER].x=x1;
            qryButton[ID_QRY_PAGE_LASER].y=y1;
            qryButton[ID_QRY_PAGE_LASER].width=w1;
            qryButton[ID_QRY_PAGE_LASER].height=h1;
            if(page==ID_QRY_PAGE_LASER || motion==ID_QRY_PAGE_LASER)
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

                if(page!=ID_QRY_PAGE_LASER)
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
            memDC.DrawLabel(_("光斑分析"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawLine(x1,y1,w,y1);
        }
        //memDC.DrawLine(x1,y1+h1-1,w,y1+h1-1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

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

void MyQueryDlg::OnMotionPage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();

    if(y>qryButton[ID_QRY_PAGE_MEAS].y && y<qryButton[ID_QRY_PAGE_MEAS].y+qryButton[ID_QRY_PAGE_MEAS].height)
    {
        if(x>qryButton[ID_QRY_PAGE_MEAS].x && x<qryButton[ID_QRY_PAGE_MEAS].x+qryButton[ID_QRY_PAGE_MEAS].width)
        {
            motion=ID_QRY_PAGE_MEAS;
        }
        else if(x>qryButton[ID_QRY_PAGE_CHART].x && x<qryButton[ID_QRY_PAGE_CHART].x+qryButton[ID_QRY_PAGE_CHART].width)
        {
            motion=ID_QRY_PAGE_CHART;
        }
        else if(x>qryButton[ID_QRY_PAGE_SEGS].x && x<qryButton[ID_QRY_PAGE_SEGS].x+qryButton[ID_QRY_PAGE_SEGS].width)
        {
            motion=ID_QRY_PAGE_SEGS;
        }
        else if(x>qryButton[ID_QRY_PAGE_LASER].x && x<qryButton[ID_QRY_PAGE_LASER].x+qryButton[ID_QRY_PAGE_LASER].width)
        {
            motion=ID_QRY_PAGE_LASER;
        }
        else
        {
            motion=ID_QRY_NONE;
        }
    }
    else
    {
        motion=ID_QRY_NONE;
    }
    panelPage->Refresh();
}

void MyQueryDlg::OnLeavePage(wxMouseEvent& event)
{
    motion=ID_QRY_NONE;
    panelPage->Refresh();
}

void MyQueryDlg::OnClickPage(wxMouseEvent& event)
{
    if(motion==ID_QRY_PAGE_MEAS)
    {
        page=ID_QRY_PAGE_MEAS;
        panelMeas->Show(true);
        m_gridHistory->Show(true);
        panelGraph->Show(false);
        m_gridSegment->Show(false);
        panelLaser->Show(false);
    }
    else if(motion==ID_QRY_PAGE_CHART)
    {
        page=ID_QRY_PAGE_CHART;
        panelMeas->Show(true);
        m_gridHistory->Show(false);
        panelGraph->Show(true);
        m_gridSegment->Show(false);
        panelLaser->Show(false);
    }
    else if(motion==ID_QRY_PAGE_SEGS)
    {
        page=ID_QRY_PAGE_SEGS;
        panelMeas->Show(true);
        m_gridHistory->Show(false);
        panelGraph->Show(false);
        m_gridSegment->Show(true);
        panelLaser->Show(false);
    }
    else if(motion==ID_QRY_PAGE_LASER)
    {
        page=ID_QRY_PAGE_LASER;
        panelMeas->Show(false);
        m_gridHistory->Show(false);
        panelGraph->Show(false);
        m_gridSegment->Show(false);
        panelLaser->Show(true);
    }
    panelPage->Refresh();
}

void MyQueryDlg::OnPaintMeasButton(wxPaintEvent& event)
{
    wxPaintDC dc(measButton);
    int w,h;
    measButton->GetClientSize(&w,&h);
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

        int x1,y1,w1,h1;
        x1=9;
        y1=5;
        w1=65;
        h1=23;
        qryButton[ID_QRY_RING].x=x1;
        qryButton[ID_QRY_RING].y=y1;
        qryButton[ID_QRY_RING].width=w1;
        qryButton[ID_QRY_RING].height=h1;

        if(qryMethod==ID_QRY_RING)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion==ID_QRY_RING)
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
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawLabel(_("按环号"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion==ID_QRY_RING)
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
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawLabel(_("按环号"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1+15;
        qryButton[ID_QRY_MILE].x=x1;
        qryButton[ID_QRY_MILE].y=y1;
        qryButton[ID_QRY_MILE].width=w1;
        qryButton[ID_QRY_MILE].height=h1;
        if(qryMethod==ID_QRY_MILE)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion==ID_QRY_MILE)
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
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawLabel(_("按里程"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion==ID_QRY_MILE)
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
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawLabel(_("按里程"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1+21;
        w1=85;
        memDC.SetPen(ipen[0]);
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1+1,w1,h1,3);
        queryValue1->SetSize(x1+2,y1+4,w1-4,h1-5);

        x1=x1+w1;
        w1=25;
        memDC.SetTextForeground(icolor[0]);
        memDC.DrawLabel(_("～"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=85;
        memDC.SetPen(ipen[0]);
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1+1,w1,h1,3);
        queryValue2->SetSize(x1+2,y1+4,w1-4,h1-5);

        x1=x1+w1+7;
        w1=65;
        qryButton[ID_QRY_QRY].x=x1;
        qryButton[ID_QRY_QRY].y=y1;
        qryButton[ID_QRY_QRY].width=w1;
        qryButton[ID_QRY_QRY].height=h1;
        if(motion==ID_QRY_QRY)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1+1,w1,h1,3);
        memDC.DrawLabel(_("查询"),wxRect(x1,y1+1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(130,135,144)));
        x1=x1+w1+10;
        memDC.DrawLine(x1,y1+3,x1,y1+h1);

        /*x1=x1+10;
        w1=65;
        qryButton[ID_QRY_OPTION].x=x1;
        qryButton[ID_QRY_OPTION].y=y1;
        qryButton[ID_QRY_OPTION].width=w1;
        qryButton[ID_QRY_OPTION].height=h1;
        if(motion==ID_QRY_OPTION)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1+1,w1,h1,3);
        memDC.DrawLabel(_("选项..."),wxRect(x1,y1+1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        */
        x1=x1+10;
        w1=35;
        qryButton[ID_QRY_ZOOM_OUT].x=x1;
        qryButton[ID_QRY_ZOOM_OUT].y=y1;
        qryButton[ID_QRY_ZOOM_OUT].width=w1;
        qryButton[ID_QRY_ZOOM_OUT].height=h1;
        if(motion==ID_QRY_ZOOM_OUT)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1+1,w1,h1,3);
        memDC.DrawLabel(_("+"),wxRect(x1,y1+1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+10;
        w1=35;
        qryButton[ID_QRY_ZOOM_PAM].x=x1;
        qryButton[ID_QRY_ZOOM_PAM].y=y1;
        qryButton[ID_QRY_ZOOM_PAM].width=w1;
        qryButton[ID_QRY_ZOOM_PAM].height=h1;
        if(motion==ID_QRY_ZOOM_PAM)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1+1,w1,h1,3);
        memDC.DrawLabel(_("口"),wxRect(x1,y1+1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+10;
        w1=35;
        qryButton[ID_QRY_ZOOM_IN].x=x1;
        qryButton[ID_QRY_ZOOM_IN].y=y1;
        qryButton[ID_QRY_ZOOM_IN].width=w1;
        qryButton[ID_QRY_ZOOM_IN].height=h1;
        if(motion==ID_QRY_ZOOM_IN)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1+1,w1,h1,3);
        memDC.DrawLabel(_("-"),wxRect(x1,y1+1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(130,135,144)));
        x1=x1+w1+10;
        memDC.DrawLine(x1,y1+3,x1,y1+h1);

        x1=x1+10;
        w1=65;
        qryButton[ID_QRY_EXP].x=x1;
        qryButton[ID_QRY_EXP].y=y1;
        qryButton[ID_QRY_EXP].width=w1;
        qryButton[ID_QRY_EXP].height=h1;
        if(motion==ID_QRY_EXP)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1+1,w1,h1,3);
        memDC.DrawLabel(_("导出"),wxRect(x1,y1+1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(130,135,144)));
        x1=x1+w1+10;
        memDC.DrawLine(x1,y1+3,x1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyQueryDlg::OnMotionMeasButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();

    if(y>qryButton[ID_QRY_RING].y && y<qryButton[ID_QRY_RING].y+qryButton[ID_QRY_RING].height)
    {
        if(x>qryButton[ID_QRY_RING].x && x<qryButton[ID_QRY_RING].x+qryButton[ID_QRY_RING].width)
        {
            motion=ID_QRY_RING;
        }
        else if(x>qryButton[ID_QRY_MILE].x && x<qryButton[ID_QRY_MILE].x+qryButton[ID_QRY_MILE].width)
        {
            motion=ID_QRY_MILE;
        }
        else if(x>qryButton[ID_QRY_QRY].x && x<qryButton[ID_QRY_QRY].x+qryButton[ID_QRY_QRY].width)
        {
            motion=ID_QRY_QRY;
        }
        else if(x>qryButton[ID_QRY_ZOOM_OUT].x && x<qryButton[ID_QRY_ZOOM_OUT].x+qryButton[ID_QRY_ZOOM_OUT].width)
        {
            motion=ID_QRY_ZOOM_OUT;
        }
        else if(x>qryButton[ID_QRY_ZOOM_IN].x && x<qryButton[ID_QRY_ZOOM_IN].x+qryButton[ID_QRY_ZOOM_IN].width)
        {
            motion=ID_QRY_ZOOM_IN;
        }
        else if(x>qryButton[ID_QRY_ZOOM_PAM].x && x<qryButton[ID_QRY_ZOOM_PAM].x+qryButton[ID_QRY_ZOOM_PAM].width)
        {
            motion=ID_QRY_ZOOM_PAM;
        }
        else if(x>qryButton[ID_QRY_EXP].x && x<qryButton[ID_QRY_EXP].x+qryButton[ID_QRY_EXP].width)
        {
            motion=ID_QRY_EXP;
        }
        else
        {
            motion=ID_QRY_NONE;
        }
    }
    else
    {
        motion=ID_QRY_NONE;
    }
    measButton->Refresh();
}

void MyQueryDlg::OnLeaveMeasButton(wxMouseEvent& event)
{
    motion=ID_QRY_NONE;
    measButton->Refresh();
}

void MyQueryDlg::OnClickMeasButton(wxMouseEvent& event)
{
    if(motion==ID_QRY_EXP)
    {
        Report();
    }
    else if(motion==ID_QRY_QRY)
    {
        int ifrm,frms;

        if(qryMethod==ID_QRY_MILE)
        {
            double l1,l2;
            queryValue1->GetValue().ToDouble(&l1);
            queryValue2->GetValue().ToDouble(&l2);
            nres=0;
            if(res) free(res);
            res=0;
            nres=mtg_query_chain(mtg,l1,l2,&res);
            ires=0;
            if(nres==0)
            {
                ifrm=0;
                frms=0;
            }
            else
            {
                ifrm=ires/MXQ+1;
                frms=nres/MXQ+1;
            }
            //ifrm=1;
            msg=wxString::Format(_("%d"),nres)+_(" 条记录！");
            //int frms=nres/MXQ;
            msg=msg+wxString::Format(_(" 第 %d 页 共 %d 页"),ifrm,frms);
        }
        else
        {
            int n1,n2;
            long val;
            queryValue1->GetValue().ToLong(&val);
            n1=val;
            queryValue2->GetValue().ToLong(&val);
            n2=val;
            nres=0;
            if(res) free(res);
            res=0;
            nres=mtg_query_seg(mtg,n1,n2,&res);
            ires=0;
            if(nres==0)
            {
                ifrm=0;
                frms=0;
            }
            else
            {
                ifrm=ires/MXQ+1;
                frms=nres/MXQ+1;
            }
            //ifrm=1;
            msg=wxString::Format(_("%d"),nres)+_(" 条记录！");
            //int frms=nres/MXQ;
            msg=msg+wxString::Format(_(" 第 %d 页 共 %d 页"),ifrm,frms);
        }
        if(nres<=0) return;
        //ShowQurey();
        ShowResults();
        panelGraph->Refresh();
    }
    else if(motion==ID_QRY_MILE)
    {
        if(qryMethod==ID_QRY_RING)
        {
            qryMethod=ID_QRY_MILE;
            if(mtg->prj.a2z==1)
            {
                queryValue1->SetValue(wxString::Format(_("%.3f"),mtg->m1.headc-mtg->segset.L));
            }
            else
            {
                queryValue1->SetValue(wxString::Format(_("%.3f"),mtg->m1.headc+mtg->segset.L));
            }
            queryValue2->SetValue(wxString::Format(_("%.3f"),mtg->m1.headc));
        }
    }
    else if(motion==ID_QRY_RING)
    {
        if(qryMethod==ID_QRY_MILE)
        {
            qryMethod=ID_QRY_RING;
            queryValue1->SetValue(wxString::Format(_("%d"),mtg->m1.iseg-1));
            queryValue2->SetValue(wxString::Format(_("%d"),mtg->m1.iseg));
        }
    }
    else if(motion==ID_QRY_ZOOM_IN)
    {
        if(dev<65)
        {
            dev=dev+5;
            panelGraph->Refresh();
        }
    }
    else if(motion==ID_QRY_ZOOM_PAM)
    {
        dev=20;
        panelGraph->Refresh();
    }
    else if(motion==ID_QRY_ZOOM_OUT)
    {
        if(dev>5)
        {
            dev=dev-5;
            panelGraph->Refresh();
        }
    }

    measButton->Refresh();
}
