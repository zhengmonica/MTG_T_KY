///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////
#include "wx_pch.h"
#include "ReviewDlg.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"
#include "confirmdlg.h"
#include "libmtg.h"
#include "geometry.h"
#include "DataDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>

#include <wx/stdpaths.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(ReviewDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(ReviewDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(ReviewDlg)
const long ReviewDlg::ID_PANEL1 = wxNewId();        //主panel
const long ReviewDlg::ID_PANEL2 = wxNewId();        //导航panel
const long ReviewDlg::ID_PANEL3 = wxNewId();        //分割panel1
const long ReviewDlg::ID_PANEL4 = wxNewId();        //分割panel2
const long ReviewDlg::ID_PANEL5 = wxNewId();        ///中线检查btn
const long ReviewDlg::ID_PANEL6 = wxNewId();        ///姿态检查
const long ReviewDlg::ID_PANEL7 = wxNewId();        ///姿态页面
const long ReviewDlg::ID_PANEL8 = wxNewId();        ///全站仪按钮
const long ReviewDlg::ID_PANEL9 = wxNewId();        ///全站仪页面
const long ReviewDlg::ID_PANEL10 = wxNewId();       //当前环管片按钮
const long ReviewDlg::ID_PANEL11 = wxNewId();        ///激光靶
const long ReviewDlg::ID_PANEL12 = wxNewId();        ///激光靶页面
const long ReviewDlg::ID_PANEL14 = wxNewId();       ///中线检查面板
const long ReviewDlg::ID_PANEL16 = wxNewId();       ///操作
const long ReviewDlg::ID_PANEL17 = wxNewId();       ///操作页面

const long ReviewDlg::ID_PANEL15 = wxNewId();       ///按钮区域
const long ReviewDlg::ID_PANEL20 = wxNewId();       ///设计中线页面
const long ReviewDlg::ID_PANEL21 = wxNewId();       ///稳定性按钮
const long ReviewDlg::ID_PANEL22 = wxNewId();       ///稳定性页面
const long ReviewDlg::ID_PANEL23 = wxNewId();       ///盾构机按钮
const long ReviewDlg::ID_PANEL24 = wxNewId();       ///盾构机页面

const long ReviewDlg::ID_BUTTON1 = wxNewId();                 //取消
const long ReviewDlg::ID_BUTTON2 = wxNewId();                 //应用
const long ReviewDlg::ID_BUTTON3 = wxNewId();                 //工程

//*)
ReviewDlg::ReviewDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);
    bmpTps.LoadFile(path+_("/plugins/tps1.png"),wxBITMAP_TYPE_PNG);
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelMain = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelNavi = new wxPanel(panelMain, ID_PANEL2, wxPoint(0,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelBorder1 = new wxPanel(panelMain, ID_PANEL3, wxPoint(0,0), wxSize(w,10), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    panelBorder2 = new wxPanel(panelMain, ID_PANEL4, wxPoint(w-8,10), wxSize(8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL4"));

    panelBtnArea = new wxPanel(panelMain, ID_PANEL15, wxPoint(0,h-80), wxSize(w,90), wxTAB_TRAVERSAL, _T("ID_PANEL15"));
    ///按钮
    //panelBtnSys = new wxPanel(panelNavi, ID_PANEL5, wxPoint(0,0), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    //panelBtnDta = new wxPanel(panelNavi, ID_PANEL10, wxPoint(0,36), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    //panelBtnPst = new wxPanel(panelNavi, ID_PANEL6, wxPoint(0,72), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    //panelBtnTps = new wxPanel(panelNavi, ID_PANEL8, wxPoint(0,108), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    //panelBtnTars = new wxPanel(panelNavi, ID_PANEL11, wxPoint(0,144), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL11"));
    //panelBtnOp = new wxPanel(panelNavi, ID_PANEL16, wxPoint(0,180), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL16"));
    panelBtnOp = new wxPanel(panelNavi, ID_PANEL16, wxPoint(0,0), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL16"));
    panelBtnTps = new wxPanel(panelNavi, ID_PANEL8, wxPoint(0,36), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    panelBtnTars = new wxPanel(panelNavi, ID_PANEL11, wxPoint(0,72), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL11"));
    panelBtnDta = new wxPanel(panelNavi, ID_PANEL10, wxPoint(0,108), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    panelBtnPst = new wxPanel(panelNavi, ID_PANEL6, wxPoint(0,144), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    panelBtnLevel = new wxPanel(panelNavi, ID_PANEL21, wxPoint(0,180), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL21"));
    panelBtnPlc = new wxPanel(panelNavi, ID_PANEL23, wxPoint(0,216), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL23"));
    ///中线检查
    //panelSys = new wxPanel(panelMain, ID_PANEL14, wxPoint(160,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL14"));
    //panelSys->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelSys->SetBackgroundColour(wxColor(255,255,255));
    //panelSys->SetFont(normalFont);

    panelDta = new wxPanel(panelMain, ID_PANEL20, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL20"));
    panelDta->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelDta->SetBackgroundColour(wxColor(255,255,255));
    panelDta->SetFont(normalFont);

    panelPst = new wxPanel(panelMain, ID_PANEL7, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    panelPst->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPst->SetBackgroundColour(wxColor(255,255,255));
    panelPst->SetFont(normalFont);

    panelTps = new wxPanel(panelMain, ID_PANEL9, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    panelTps->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTps->SetBackgroundColour(wxColor(255,255,255));
    panelTps->SetFont(normalFont);

    panelTars = new wxPanel(panelMain, ID_PANEL12, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL12"));
    panelTars->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTars->SetBackgroundColour(wxColor(255,255,255));
    panelTars->SetFont(normalFont);

    panelOp = new wxPanel(panelMain, ID_PANEL17, wxPoint(160,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL17"));
    panelOp->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelOp->SetBackgroundColour(wxColor(255,255,255));
    panelOp->SetFont(normalFont);

    panelLevel = new wxPanel(panelMain, ID_PANEL22, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL22"));
    panelLevel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelLevel->SetBackgroundColour(wxColor(255,255,255));
    panelLevel->SetFont(normalFont);

    panelPlc = new wxPanel(panelMain, ID_PANEL24, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL24"));
    panelPlc->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPlc->SetBackgroundColour(wxColor(255,255,255));
    panelPlc->SetFont(normalFont);

    btnCancel = new wxButton(panelBtnArea, ID_BUTTON1, _("退 出"), wxPoint(w-96-10,15), wxSize(96,36), 0, wxDefaultValidator, _T("ID_BUTTON1"));

	panelNavi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBorder1->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBorder1->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelBtnSys->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnDta->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnPst->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelSys->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    m_dtaGrid = new wxMyGrid( panelDta, wxID_ANY, wxPoint(36,121), wxSize( 538,290 ), 0 );

	panelNavi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintNavi,0,this);
	panelBorder1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintBorder1,0,this);
	panelBorder2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintBorder2,0,this);
    //panelBtnSys->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintBtnSys,0,this);
    panelBtnDta->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintBtnDta,0,this);
    panelBtnPst->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintBtnPst,0,this);
    panelBtnTps->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintBtnTps,0,this);
    panelBtnTars->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintBtnTars,0,this);
    panelBtnOp->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintBtnOp,0,this);
    panelBtnLevel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintBtnLevel,0,this);
    panelLevel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintLevel,0,this);
    panelBtnPlc->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintBtnPlc,0,this);
    panelPlc->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintPlc,0,this);


    panelDta->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ReviewDlg::OnCheckDta,0,this);
    panelDta->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ReviewDlg::OnEnterDta,0,this);
    //panelDta->Connect(wxEVT_MOUSEWHEEL,(wxObjectEventFunction)&ReviewDlg::OnMouseWheel,0,this);

    panelPst->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ReviewDlg::OnCheckPst,0,this);
    panelPst->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ReviewDlg::OnEnterPst,0,this);

    panelOp->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ReviewDlg::OnCheckOp,0,this);
    panelOp->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ReviewDlg::OnEnterOp,0,this);

    //panelSys->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintSys,0,this);
    panelBtnArea->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintBtnArea,0,this);
    panelDta->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintDta,0,this);
    panelPst->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintPst,0,this);
    panelTps->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintTps,0,this);
    panelTars->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintTars,0,this);
    panelOp->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReviewDlg::OnPaintOp,0,this);


    //panelBtnSys->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnEnterBtnSys,0,this);
    //panelBtnSys->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnLeaveBtnSys,0,this);
    //panelBtnSys->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&ReviewDlg::OnLeftDownBtnSys,0,this);
    //panelBtnSys->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ReviewDlg::OnBtnSysClick,0,this);

    panelBtnDta->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnEnterBtnDta,0,this);
    panelBtnDta->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnLeaveBtnDta,0,this);
    panelBtnDta->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&ReviewDlg::OnLeftDownBtnDta,0,this);
    panelBtnDta->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ReviewDlg::OnBtnDtaClick,0,this);



    panelBtnPst->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnEnterBtnPst,0,this);
    panelBtnPst->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnLeaveBtnPst,0,this);
    panelBtnPst->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&ReviewDlg::OnLeftDownBtnPst,0,this);
    panelBtnPst->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ReviewDlg::OnBtnPstClick,0,this);

    panelBtnTps->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnEnterBtnTps,0,this);
    panelBtnTps->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnLeaveBtnTps,0,this);
    panelBtnTps->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&ReviewDlg::OnLeftDownBtnTps,0,this);
    panelBtnTps->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ReviewDlg::OnBtnTpsClick,0,this);

    panelBtnTars->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnEnterBtnTars,0,this);
    panelBtnTars->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnLeaveBtnTars,0,this);
    panelBtnTars->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&ReviewDlg::OnLeftDownBtnTars,0,this);
    panelBtnTars->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ReviewDlg::OnBtnTarsClick,0,this);

    panelBtnOp->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnEnterBtnOp,0,this);
    panelBtnOp->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnLeaveBtnOp,0,this);
    panelBtnOp->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&ReviewDlg::OnLeftDownBtnOp,0,this);
    panelBtnOp->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ReviewDlg::OnBtnOpClick,0,this);

    panelBtnLevel->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnEnterBtnLevel,0,this);
    panelBtnLevel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnLeaveBtnLevel,0,this);
    panelBtnLevel->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&ReviewDlg::OnLeftDownBtnLevel,0,this);
    panelBtnLevel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ReviewDlg::OnBtnLevelClick,0,this);

    panelBtnPlc->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnEnterBtnPlc,0,this);
    panelBtnPlc->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ReviewDlg::OnLeaveBtnPlc,0,this);
    panelBtnPlc->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&ReviewDlg::OnLeftDownBtnPlc,0,this);
    panelBtnPlc->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ReviewDlg::OnBtnPlcClick,0,this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ReviewDlg::OnBtnQuit);

    //*)

    InitMyGrid();

    //btnSysState = 4;
    btnPstState = 0;
    btnDtaState = 0;
    btnTpsState = 0;
    btnTarsState = 0;
    btnLevelState = 0;
    btnPlcState = 0;
    btnOpState = 4;

    dta_btn = -1;
    dta_btn_clicked = -1;
    dta_type_clicked = 0;
    btnTbmCheck = 0;
    //m_gridData->InsertCols(0,9);
    ///设计线
    /*l1_val = 0.001;
    l2_val = 0.005;
    l3_val = 0.01;
    l4_val = 0.015;
    l5_val = 0.020;
    l1_str = wxString::Format(_("%.1f"),l1_val*1000)+_("-")+wxString::Format(_("%.1f"),l2_val*1000)+_("mm");
    l2_str = wxString::Format(_("%.1f"),l2_val*1000)+_("-")+wxString::Format(_("%.1f"),l3_val*1000)+_("mm");
    l3_str = wxString::Format(_("%.1f"),l3_val*1000)+_("-")+wxString::Format(_("%.1f"),l4_val*1000)+_("mm");
    l4_str = wxString::Format(_("%.1f"),l4_val*1000)+_("-")+wxString::Format(_("%.1f"),l5_val*1000)+_("mm");
    l5_str = _("> ")+wxString::Format(_("%.1f"),l5_val*1000);
    */
    npts = 0;
    /*for(int i=0;i<10;i++)
    {
        nl[i] = 0;
    }*/
    ///画图参数
    x1[0] = 65;
    y1[0] = 360;
    x1[1] = 570;
    y1[1] = 360;
    sxy = 0;
    ang = 0;
    ///提示信息
    msg_str = _("");
    msg_cor = wxColor(255,255,255);
    ///
    m_bCheckBack = false;
    //历史
    ///姿态数据
    headh = 0.0;
    headv = 0.0;
    tailh = 0.0;
    tailv = 0.0;
    ///状态
    checked[0] = -1;
    checked[1] = -1;
    checking = -1;
    isPstCheck = false;
    isop = -1;
    //LoadData();
    //LoadTBM();
    //CalTBM();
}

ReviewDlg::~ReviewDlg()
{
    checkDlg=0;
}

void ReviewDlg::InitMyGrid()
{
    // Grid
	m_dtaGrid->CreateGrid( 0, 0 );
	m_dtaGrid->EnableEditing( false );
	m_dtaGrid->EnableGridLines( true );
	m_dtaGrid->EnableDragGridSize( false );
	m_dtaGrid->SetMargins( 0, 0 );

	// Columns
	m_dtaGrid->EnableDragColMove( false );
	m_dtaGrid->EnableDragColSize( true );
	m_dtaGrid->SetColLabelSize( 0 );
	m_dtaGrid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Rows
	m_dtaGrid->EnableDragRowSize( true );
	m_dtaGrid->SetRowLabelSize( 0 );
	m_dtaGrid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Label Appearance

	// Cell Defaults
	m_dtaGrid->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
    m_dtaGrid->InsertCols(0,6);
    ///历史
    int i=0;
	/*m_dtaGrid->MergeColum(_("系统DTA"),i,i+2);
	m_dtaGrid->SetColLabelValue( i, _("X") );
	m_dtaGrid->SetColSize(i++,90);
	m_dtaGrid->SetColLabelValue( i, _("Y") );
	m_dtaGrid->SetColSize(i++,90);
	m_dtaGrid->SetColLabelValue( i, _("Z") );
	m_dtaGrid->SetColSize(i++,60);*/
	m_dtaGrid->SetColLabelValue( i, _("X") );
	m_dtaGrid->SetColSize(i++,85);
	m_dtaGrid->MergeColum(_("坐标"),i,i+2);
	m_dtaGrid->SetColLabelValue( i, _("X") );
	m_dtaGrid->SetColSize(i++,100);
	m_dtaGrid->SetColLabelValue( i, _("Y") );
	m_dtaGrid->SetColSize(i++,100);
	m_dtaGrid->SetColLabelValue( i, _("Z") );
	m_dtaGrid->SetColSize(i++,80);
	m_dtaGrid->MergeColum(_("偏差(mm)"),i,i+1);
	m_dtaGrid->SetColLabelValue( i, _("平面") );
	m_dtaGrid->SetColSize(i++,70);
	m_dtaGrid->SetColLabelValue( i, _("高程") );
	m_dtaGrid->SetColSize(i++,70);
}

void ReviewDlg::DrawTCA(wxMemoryDC* dc,wxRect rect,double ang)
{

    int x1 = rect.x;
    int y1 = rect.y;
    int w = rect.width;
    int h = rect.height;

    ///
    int cx = x1+w/2;
    int cy = y1+h/2;


    double x[4];
    double y[4];

    x[0] = x1+w*3/20.0;
    y[0] = y1+h/2.0-h/6.0;
    x[1] = x[0]+w*7.0/10.0;
    y[1] = y[0];
    x[2] = x[1];
    y[2] = y[0]+h/3.0;
    x[3] = x[0];
    y[3] = y[2];
    double d,a;
    wxPoint ps[4];
    for(int i=0;i<4;i++)
    {
        d = (x[i]-cx)*(x[i]-cx)+(y[i]-cy)*(y[i]-cy);
        d = sqrt(d);
        a = (double)(y[i]-cy)/(double)(x[i]-cx);
        a = atan(a);
        if(y[i]-cy<0 && x[i]-cx>0)
        {
            a = a+PI*2.0;
        }
        if(y[i]-cy<0 && x[i]-cx<0)
        {
            a = a+PI;
        }
        if(y[i]-cy>0 && x[i]-cx<0)
        {
            a = a+PI;
        }
        a = a+ang;
        x[i] = cx+d*cos(a);
        y[i] = cy+d*sin(a);
        ps[i].x = x[i];
        ps[i].y = y[i];
    }
    dc->SetBrush(wxBrush(wxColor(110,150,110)));
    dc->SetPen(wxPen(wxColor(182,186,187)));
    dc->DrawPolygon(4,ps);

    x[0] = x1+w/2.0-w/8.0;
    y[0] = y1+h/2.0-h/50.0;
    x[1] = x[0]+w/4.0;
    y[1] = y[0];
    x[2] = x[1];
    y[2] = y[0]+h/25.0;
    x[3] = x[0];
    y[3] = y[2];
    for(int i=0;i<4;i++)
    {
        d = (x[i]-cx)*(x[i]-cx)+(y[i]-cy)*(y[i]-cy);
        d = sqrt(d);
        a = (double)(y[i]-cy)/(double)(x[i]-cx);
        a = atan(a);
        if(y[i]-cy<0 && x[i]-cx>0)
        {
            a = a+PI*2.0;
        }
        if(y[i]-cy<0 && x[i]-cx<0)
        {
            a = a+PI;
        }
        if(y[i]-cy>0 && x[i]-cx<0)
        {
            a = a+PI;
        }
        a = a+ang;
        x[i] = cx+d*cos(a);
        y[i] = cy+d*sin(a);
        ps[i].x = x[i];
        ps[i].y = y[i];
    }
    dc->SetBrush(wxBrush(wxColor(20,20,20)));
    dc->SetPen(wxPen(wxColor(20,20,20)));
    dc->DrawPolygon(4,ps);

    x[0] = x1+w-w*3.0/20.0;
    y[0] = y1+h/2.0-h/8.0;
    x[1] = x[0]+w/12.0;
    y[1] = y[0];
    x[2] = x[1];
    y[2] = y[0]+h/4.0;
    x[3] = x[0];
    y[3] = y[2];
    for(int i=0;i<4;i++)
    {
        d = (x[i]-cx)*(x[i]-cx)+(y[i]-cy)*(y[i]-cy);
        d = sqrt(d);
        a = (double)(y[i]-cy)/(double)(x[i]-cx);
        a = atan(a);
        if(y[i]-cy<0 && x[i]-cx>0)
        {
            a = a+PI*2.0;
        }
        if(y[i]-cy<0 && x[i]-cx<0)
        {
            a = a+PI;
        }
        if(y[i]-cy>0 && x[i]-cx<0)
        {
            a = a+PI;
        }
        a = a+ang;
        x[i] = cx+d*cos(a);
        y[i] = cy+d*sin(a);
        ps[i].x = x[i];
        ps[i].y = y[i];
    }
    dc->DrawPolygon(4,ps);

    x[0] = x1+w*3.0/20.0-w/20.0;
    y[0] = y1+h/2.0-h/12.0;
    x[1] = x[0]+w/20.0;
    y[1] = y[0];
    x[2] = x[1];
    y[2] = y[0]+h/6.0;
    x[3] = x[0];
    y[3] = y[2];
    for(int i=0;i<4;i++)
    {
        d = (x[i]-cx)*(x[i]-cx)+(y[i]-cy)*(y[i]-cy);
        d = sqrt(d);
        a = (double)(y[i]-cy)/(double)(x[i]-cx);
        a = atan(a);
        if(y[i]-cy<0 && x[i]-cx>0)
        {
            a = a+PI*2.0;
        }
        if(y[i]-cy<0 && x[i]-cx<0)
        {
            a = a+PI;
        }
        if(y[i]-cy>0 && x[i]-cx<0)
        {
            a = a+PI;
        }
        a = a+ang;
        x[i] = cx+d*cos(a);
        y[i] = cy+d*sin(a);
        ps[i].x = x[i];
        ps[i].y = y[i];
    }
    dc->DrawPolygon(4,ps);

    x[0] = x1+w/2.0-w/24.0;
    y[0] = y1+h/5.0;
    x[1] = x[0]+w/12.0;
    y[1] = y[0];
    x[2] = x[1];
    y[2] = y[0]+h*3.0/5.0;
    x[3] = x[0];
    y[3] = y[2];
    for(int i=0;i<4;i++)
    {
        d = (x[i]-cx)*(x[i]-cx)+(y[i]-cy)*(y[i]-cy);
        d = sqrt(d);
        a = (double)(y[i]-cy)/(double)(x[i]-cx);
        a = atan(a);
        if(y[i]-cy<0 && x[i]-cx>0)
        {
            a = a+PI*2.0;
        }
        if(y[i]-cy<0 && x[i]-cx<0)
        {
            a = a+PI;
        }
        if(y[i]-cy>0 && x[i]-cx<0)
        {
            a = a+PI;
        }
        a = a+ang;
        x[i] = cx+d*cos(a);
        y[i] = cy+d*sin(a);
        ps[i].x = x[i];
        ps[i].y = y[i];
    }
    dc->SetBrush(wxBrush(wxColor(212,216,217)));
    dc->SetPen(wxPen(wxColor(182,186,187)));
    dc->DrawPolygon(4,ps);

    /*dc->SetBrush(wxBrush(wxColor(110,150,110)));


    dc->DrawRectangle(x1,y1,w1,h1);
    x1 = x+w/2-w/24;
    y1 = y+h/5;
    w1 = w/12;
    h1 = h*3/5;
    dc->SetBrush(wxBrush(wxColor(212,216,217)));
    dc->SetPen(wxPen(wxColor(182,186,187)));
    dc->DrawRectangle(x1,y1,w1,h1);*/
}
/*
int ReviewDlg::LoadData()
{
    wxStandardPaths stdp;
    wxString str=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=str.Find('\\',true);
    #else
    int t=str.Find('/',true);
    #endif
    str=str.SubString(0,t-1);
    str = str+_("/plugins/LineCheck.dta");
    if(wxFileExists(str))
    {
        char path[1024];
        strcpy(path,str.mb_str(wxConvLocal));
        double val;
        double val1=0.0,val2=0.0;
        FILE* fp=fopen(path,"rb");
        if(fp)
        {
            fread(&npts,sizeof(int),1,fp);
            npts = npts-1;
            dpts=(DPoint*)malloc(npts*sizeof(DPoint));
            for(int i=0;i<npts;i++)
            {
                fread(&val,sizeof(double),1,fp);
                dpts[i].l = val;
                fread(&val,sizeof(double),1,fp);
                dpts[i].x1 = val;
                fread(&val,sizeof(double),1,fp);
                dpts[i].y1 = val;
                fread(&val,sizeof(double),1,fp);
                dpts[i].z1 = val;
                fread(&val,sizeof(double),1,fp);
                dpts[i].x2 = val;
                fread(&val,sizeof(double),1,fp);
                dpts[i].y2 = val;
                fread(&val,sizeof(double),1,fp);
                dpts[i].z2 = val;
                fread(&val,sizeof(double),1,fp);
                dpts[i].hd = val;
                if(fabs(val)>=l1_val && fabs(val)<l2_val)
                {
                    nl[0]++;
                }
                else if(fabs(val)>=l2_val && fabs(val)<l3_val)
                {
                    nl[1]++;
                }
                else if(fabs(val)>=l3_val && fabs(val)<l4_val)
                {
                    nl[2]++;
                }
                else if(fabs(val)>=l4_val && fabs(val)<l5_val)
                {
                    nl[3]++;
                }
                else if(fabs(val)>=l5_val)
                {
                    nl[4]++;
                    if(fabs(val)>fabs(val1))
                    {
                        val1 = val;
                    }
                }
                fread(&val,sizeof(double),1,fp);
                dpts[i].vd = val;


                if(fabs(val)>=l1_val && fabs(val)<l2_val)
                {
                    nl[5]++;
                }
                else if(fabs(val)>=l2_val && fabs(val)<l3_val)
                {
                    nl[6]++;
                }
                else if(fabs(val)>=l3_val && fabs(val)<l4_val)
                {
                    nl[7]++;
                }
                else if(fabs(val)>=l4_val && fabs(val)<l5_val)
                {
                    nl[8]++;
                }
                else if(fabs(val)>=l5_val)
                {
                    nl[9]++;
                    if(fabs(val)>fabs(val2))
                    {
                        val2 = val;
                    }
                }
            }
            maxh = val1;
            maxv = val2;
            x2[0] = dpts[0].x2;
            y2[0] = dpts[0].y2;
            x2[1] = dpts[npts-1].x2;
            y2[1] = dpts[npts-1].y2;
            double d1 = sqrt((x1[0]-x1[1])*(x1[0]-x1[1])+(y1[0]-y1[1])*(y1[0]-y1[1]));
            double d2 = sqrt((x2[0]-x2[1])*(x2[0]-x2[1])+(y2[0]-y2[1])*(y2[0]-y2[1]));
            sxy = d1/d2;
            double ang1 = atan2(y1[1]-y1[0],x1[1]-x1[0]);
            double ang2 = atan2(y2[1]-y2[0],x2[1]-x2[0]);
            if(ang1<0.0) ang1 = ang1+2.0*PI;
            if(ang2<0.0) ang2 = ang2+2.0*PI;
            ang = ang2-ang1;
            if(ang<0.0) ang = ang+2.0*PI;
        }
        else
        {
            return 0;
        }
        checked[0] = 0;
        fclose(fp);
    }
    else
    {
        return 0;
    }
    return 1;
}
*/
void ReviewDlg::LoadTBM()
{
    wxStandardPaths stdp;
    wxString str=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=str.Find('\\',true);
    #else
    int t=str.Find('/',true);
    #endif
    str=str.SubString(0,t-1);
    str = str+_("/plugins/Position.tbm");

    if(wxFileExists(str))
    {
        char path[1024];
        strcpy(path,str.mb_str(wxConvLocal));
        double val;
        int nval = 0;
        FILE* fp=fopen(path,"rb");
        if(fp)
        {
            fread(&nval,sizeof(int),1,fp);
            ncp = nval-4;
            ncp = ncp/2;
            cpx1=(double*)malloc(ncp*sizeof(double));
            cpy1=(double*)malloc(ncp*sizeof(double));
            cpz1=(double*)malloc(ncp*sizeof(double));
            cpx2=(double*)malloc(ncp*sizeof(double));
            cpy2=(double*)malloc(ncp*sizeof(double));
            cpz2=(double*)malloc(ncp*sizeof(double));
            fread(&val,sizeof(double),1,fp);
            hd1[0] = val;
            fread(&val,sizeof(double),1,fp);
            hd1[1] = val;
            fread(&val,sizeof(double),1,fp);
            hd1[2] = val;
            fread(&val,sizeof(double),1,fp);
            tl1[0] = val;
            fread(&val,sizeof(double),1,fp);
            tl1[1] = val;
            fread(&val,sizeof(double),1,fp);
            tl1[2] = val;
            for(int i=0;i<ncp;i++)
            {
                fread(&val,sizeof(double),1,fp);
                cpx1[i] = val;
                fread(&val,sizeof(double),1,fp);
                cpy1[i] = val;
                fread(&val,sizeof(double),1,fp);
                cpz1[i] = val;

            }
            for(int i=0;i<ncp;i++)
            {
                fread(&val,sizeof(double),1,fp);
                cpx2[i] = val;
                fread(&val,sizeof(double),1,fp);
                cpy2[i] = val;
                fread(&val,sizeof(double),1,fp);
                cpz2[i] = val;

            }
        }
        checked[1] = 0;
    }

}

void ReviewDlg::CalTBM()
{
    if(checked[1]==-1)
    {
        return;
    }
    double* dist1;
    double* dist2;
    double off;
    int nh = road_number_horizon(&mtg->r);
    int nv = road_number_vertical(&mtg->r);
    //FILE* fp = fopen("E:\\caltbm.log","w");
    dist1 = (double*)malloc(ncp*sizeof(double));
    dist2 = (double*)malloc(ncp*sizeof(double));

    for(int i=0;i<ncp;i++)
    {
        if(i<ncp-1)
        {
            dist1[i] = (cpx1[i]-cpx1[i+1])*(cpx1[i]-cpx1[i+1])+(cpy1[i]-cpy1[i+1])*(cpy1[i]-cpy1[i+1])+(cpz1[i]-cpz1[i+1])*(cpz1[i]-cpz1[i+1]);
            dist1[i] = sqrt(dist1[i]);
            dist2[i] = (cpx2[i]-cpx2[i+1])*(cpx2[i]-cpx2[i+1])+(cpy2[i]-cpy2[i+1])*(cpy2[i]-cpy2[i+1])+(cpz2[i]-cpz2[i+1])*(cpz2[i]-cpz2[i+1]);
            dist2[i] = sqrt(dist2[i]);
        }
        else
        {
            dist1[i] = (cpx1[i]-cpx1[0])*(cpx1[i]-cpx1[0])+(cpy1[i]-cpy1[0])*(cpy1[i]-cpy1[0])+(cpz1[i]-cpz1[0])*(cpz1[i]-cpz1[0]);
            dist1[i] = sqrt(dist1[i]);
            dist2[i] = (cpx2[i]-cpx2[0])*(cpx2[i]-cpx2[0])+(cpy2[i]-cpy2[0])*(cpy2[i]-cpy2[0])+(cpz2[i]-cpz2[0])*(cpz2[i]-cpz2[0]);
            dist2[i] = sqrt(dist2[i]);
        }
        off = dist1[i] - dist2[i];

        /*if(off/dist1[i]>0.005)
        {
            WriteMsg(_("数据关系错误，请检查！"),1);
            return;
        }*/
    }
    double mile1=0.0;
    double mile2=0.0;
    transform3d_t trans;
    transform3d_init(&trans,0,0,0,0,0,0,1);
    point3d_t* pt1;
    point3d_t* pt2;
    point3d_t head;
    point3d_t tail;
    head.x = hd1[0];
    head.y = hd1[1];
    head.z = hd1[2];
    tail.x = tl1[0];
    tail.y = tl1[1];
    tail.z = tl1[2];
    pt1 = (point3d_t*)malloc(ncp*sizeof(point3d_t));
    pt2 = (point3d_t*)malloc(ncp*sizeof(point3d_t));
    int flags[7] = {1,1,1,1,1,1,0};
    for(int i =0;i<ncp;i++)
    {
        pt1[i].x = cpx1[i];
        pt1[i].y = cpy1[i];
        pt1[i].z = cpz1[i];
        pt2[i].x = cpx2[i];
        pt2[i].y = cpy2[i];
        pt2[i].z = cpz2[i];
        //fprintf(fp,"pt1:%.4f,%.4f,%.4f\n",pt1[i].x,pt1[i].y,pt1[i].z);
        //fprintf(fp,"pt2:%.4f,%.4f,%.4f\n",pt2[i].x,pt2[i].y,pt2[i].z);
    }
    transform3d_init_points(&trans,ncp,pt1,pt2,flags);
    transform3d_trans(&trans,&head,&head);
    transform3d_trans(&trans,&tail,&tail);
    hd2[0] = head.x;
    hd2[1] = head.y;
    hd2[2] = head.z;
    tl2[0] = tail.x;
    tl2[1] = tail.y;
    tl2[2] = tail.z;
    if(nh>2 && nv>2)
    {
        road_xy2l(&mtg->r,hd2[0],hd2[1],&mile1,0,0,0,&headh);
        road_l2h(&mtg->r,mile1,&headv,0);
        headv = hd2[2]-headv;
        road_xy2l(&mtg->r,tl2[0],tl2[1],&mile2,0,0,0,&tailh);
        road_l2h(&mtg->r,mile2,&tailv,0);
        tailv = hd2[2]-tailv;
        azi = atan2(hd2[1]-tl2[1],hd2[0]-tl2[0]);
        if(azi<0.0) azi = azi+2.0*PI;
        pitch = atan((hd2[2]-tl2[2])/fabs(mile1-mile2));
    }
    else
    {
        WriteMsg(_("缺少中线数据!"),1);
    }
    //fprintf(fp,"head:%.4f,%.4f,%.4f\n",hd2[0],hd2[1],hd2[2]);
    //fprintf(fp,"tail:%.4f,%.4f,%.4f\n",tl2[0],tl2[1],tl2[2]);
    panelPst->Refresh();
    checked[1] = 0;
    //fclose(fp);
    //mtg_start_cycle(mtg);

}

void ReviewDlg::ReadTBM()
{
    /*if(!mtg->m0.t1)
    {
        WriteMsg(_("盾构姿态未初始化，请检查！"),1);
        return;
    }*/
    wxFileDialog Dlg(this,_("请选择TBM姿态数据文件"),wxEmptyString,wxEmptyString,_("坐标表文件(*.csv)|*.csv"),wxFD_OPEN);
    //FILE* fp1 = fopen("E:\\readtbm.log","w");
    if(Dlg.ShowModal()==wxID_OK)
    {
        wxString str1 = Dlg.GetPath();
        char path[1024];
        char buf[1024];
        char mark[64];
        char coor1[64];
        char coor2[64];
        char coor3[64];
        int index = 0;
        int dcp=0,acp=0;
        strcpy(path,str1.mb_str(wxConvLocal));
        FILE* fp=fopen(path,"r");
        if(fp)
        {
            while(!feof(fp))
            {
                fgets(buf,1024,fp);
                if(sscanf(buf,"%[^,],%[^,],%[^,],%s",mark,coor1,coor2,coor3))
                {
                    index++;
                    if(index>18)
                    {
                        break;
                    }
                }
            }

        }
        fclose(fp);
        if(index<10)
        {
            WriteMsg(_("控制点数必须大于或等于3，请检查！"),1);
            return;
        }
        if((index-4)%2!=0)
        {
            WriteMsg(_("数据格式错误，请检查！"),1);
            return;
        }
        fp = fopen(path,"r");
        if(fp)
        {
            double val;
            ncp = index-4;
            ncp = ncp/2;
            //fprintf(fp1,"ncp:%d\n",ncp);
            //fprintf(fp1,"ncp+4:%d\n",ncp+4);
            //fprintf(fp1,"ncp+3:%d\n",ncp+3);
            cpx1=(double*)malloc(ncp*sizeof(double));
            cpy1=(double*)malloc(ncp*sizeof(double));
            cpz1=(double*)malloc(ncp*sizeof(double));
            cpx2=(double*)malloc(ncp*sizeof(double));
            cpy2=(double*)malloc(ncp*sizeof(double));
            cpz2=(double*)malloc(ncp*sizeof(double));
            index=0;
            wxString valstr;
            double dval;
            int i=0;
            while(!feof(fp))
            {
                fgets(buf,1024,fp);
                if(sscanf(buf,"%[^,],%[^,],%[^,],%s",mark,coor1,coor2,coor3))
                {
                    if(index>0)
                    {
                        if(index==1)
                        {
                            valstr = wxString(coor1,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            hd1[0] = dval;
                            valstr = wxString(coor2,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            hd1[1] = dval;
                            valstr = wxString(coor3,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            hd1[2] = dval;
                            //fprintf(fp1,"head:%.4f,%.4f,%.4f\n",hd1[0],hd1[1],hd1[2]);
                        }
                        else if(index==2)
                        {
                            valstr = wxString(coor1,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            tl1[0] = dval;
                            valstr = wxString(coor2,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            tl1[1] = dval;
                            valstr = wxString(coor3,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            tl1[2] = dval;
                            //fprintf(fp1,"tail:%.4f,%.4f,%.4f\n",tl1[0],tl1[1],tl1[2]);
                        }
                        else if(index<ncp+3)
                        {
                            //fprintf(fp1,"%d,%d\n",index,ncp+4);
                            valstr = wxString(coor1,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            cpx1[i] = dval;
                            valstr = wxString(coor2,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            cpy1[i] = dval;
                            valstr = wxString(coor3,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            cpz1[i] = dval;
                            //fprintf(fp1,"cp1:%.4f,%.4f,%.4f\n",cpx1[i],cpy1[i],cpz1[i]);
                            i++;
                            dcp++;
                            //wxMessageBox(_("ok"));
                            if(index == ncp+2)
                            {
                                i=0;
                            }
                        }
                        else if(index<ncp*2+3)
                        {
                            valstr = wxString(coor1,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            cpx2[i] = dval;
                            valstr = wxString(coor2,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            cpy2[i] = dval;
                            valstr = wxString(coor3,wxConvUTF8);
                            valstr.ToDouble(&dval);
                            cpz2[i] = dval;
                            //fprintf(fp1,"cp2:%.4f,%.4f,%.4f\n",cpx2[i],cpy2[i],cpz2[i]);
                            i++;
                            acp++;
                        }

                    }
                    index++;
                    if(index>18)
                    {
                        break;
                    }
                }
            }

        }
        fclose(fp);
        if(dcp>=3 && acp>=3)
        {
            if(acp==dcp)
            {
                checked[1]=0;
            }
            else
            {
                checked[1]=-1;
            }
        }
        else
        {
            checked[1]=-1;
        }
    }
    //fclose(fp1);
}

int ReviewDlg::ReadXYZ()
{
    wxFileDialog Dlg(this,_("请选择中线数据文件"),wxEmptyString,wxEmptyString,_("坐标表文件(*.csv)|*.csv"),wxFD_OPEN);
    int nh=road_number_horizon(&mtg->r);
    int nv = road_number_vertical(&mtg->r);
    if(nh<=2 || nv<=2)
    {
        WriteMsg(_("缺少中线数据,请检查！"),1);
        //wxMessageBox(_("缺少中线数据！"),_("错误"),wxOK|wxICON_ERROR);
        return 0;
    }
    if(Dlg.ShowModal()==wxID_OK)
    {
        wxString str1 = Dlg.GetPath();
        char path[1024];
        char buf[1024];
        char mark[64];
        char coor1[64];
        char coor2[64];
        char coor3[64];
        int index = 0;
        strcpy(path,str1.mb_str(wxConvLocal));
        FILE* fp=fopen(path,"r");
        if(fp)
        {
            while(!feof(fp))
            {
                fgets(buf,1024,fp);
                if(sscanf(buf,"%[^,],%[^,],%[^,],%s",mark,coor1,coor2,coor3))
                {
                    index++;
                }
            }
        }
        fclose(fp);
        dpts=(DPoint*)malloc(index*sizeof(DPoint));
        int row=m_dtaGrid->GetNumberRows();
        index = index-1;
        if(row<index)
        {
            m_dtaGrid->InsertRows(row,index-row);
        }
        else
        {
            m_dtaGrid->DeleteRows(index,row-index);
        }
        index=0;
        int i = 0;
        fp = fopen(path,"r");
        if(fp)
        {
            wxString valstr;
            double dval;
            while(!feof(fp))
            {
                fgets(buf,1024,fp);
                if(sscanf(buf,"%[^,],%[^,],%[^,],%s",mark,coor1,coor2,coor3))
                {
                    if(index>0)
                    {
                        int j=0;
                        m_dtaGrid->SetCellValue(i,j++,wxString::Format(_("%d"),i+1));
                        valstr = wxString(coor1,wxConvUTF8);
                        valstr.ToDouble(&dval);
                        dpts[index].x1=dval;
                        m_dtaGrid->SetCellValue(i,j++,wxString::Format(_("%.4f"),dval));

                        valstr = wxString(coor2,wxConvUTF8);
                        //m_dtaGrid->SetCellValue(i,j++,valstr);
                        valstr.ToDouble(&dval);
                        dpts[index].y1=dval;
                        m_dtaGrid->SetCellValue(i,j++,wxString::Format(_("%.4f"),dval));

                        valstr = wxString(coor3,wxConvUTF8);
                        //m_dtaGrid->SetCellValue(i,j++,valstr);
                        valstr.ToDouble(&dval);
                        dpts[index].z1=dval;
                        m_dtaGrid->SetCellValue(i,j++,wxString::Format(_("%.4f"),dval));

                        m_dtaGrid->SetCellAlignment(i,j,wxALIGN_RIGHT,wxALIGN_CENTER);
                        m_dtaGrid->SetCellTextColour(i,j,wxColor(0,0,255));
                        road_xy2l(&mtg->r,dpts[index].x1,dpts[index].y1,&dpts[index].l,&dpts[index].x2,&dpts[index].y2,0,&dpts[index].hd);
                        m_dtaGrid->SetCellValue(i,j++,wxString::Format(_("%.1f "),dpts[index].hd*1000.0));

                        m_dtaGrid->SetCellAlignment(i,j,wxALIGN_RIGHT,wxALIGN_CENTER);
                        m_dtaGrid->SetCellTextColour(i,j,wxColor(255,0,255));
                        road_l2h(&mtg->r,dpts[index].l,&dpts[index].z2,0);
                        dpts[index].vd = dpts[index].z1-dpts[index].z2;
                        m_dtaGrid->SetCellValue(i,j++,wxString::Format(_("%.1f "),dpts[index].vd*1000.0));
                        i++;
                    }
                    index++;
                }
            }
        }
        else
        {
            return 0;
        }
        fclose(fp);
        return 1;
    }
}

void ReviewDlg::WriteMsg(const wxString& str,int color)
{
    switch(color)
    {
        case 0:
            msg_cor = wxColor(0,0,255);
        break;
        case 1:
            msg_cor = wxColor(255,0,0);
        break;
        default:
        break;
    }
    msg_str = str;
    panelBtnArea->Refresh();
}

void ReviewDlg::OnBtnQuit(wxCommandEvent& event)
{
    /*if(checking==0)
    {
        WriteMsg(_("检查工作未完成，请稍后退出！"),1);
        return;
    }*/
    Destroy();
}

void ReviewDlg::UpdateView()
{
    if(m_bCheckBack)
    {
        panelOp->Refresh();
    }
}


void ReviewDlg::OnCheckOp(wxMouseEvent& event)
{
    checking = 0;
    if(isop==0 || isop==2)
    {
        ///测量后视
        if(mtg->stns[mtg->nstn-1].t<=0)
        {
            WriteMsg(_("设站尚未完成！"),1);
            checking = -1;
            return;
        }
        if(mtg_check_back(mtg))
        {
            checking = -1;
            WriteMsg(_("后视检核失败！"),1);
            return;
        }
    }
    else if(isop==1)
    {
         ///后视复位
        if(!m_bCheckBack)
        {
            WriteMsg(_("后视检核尚未进行！"),1);
            checking = -1;
            return;
        }
        if(mtg_setup(mtg))
        {
            WriteMsg(_("重定向失败！"),1);
            checking = -1;
            return;
        }
    }
    else if(isop==4)
    {
        ///测量激光靶
        if(mtg->m1.t3<=0)
        {
            WriteMsg(_("学习测量尚未完成！"),1);
            checking = -1;
            return;
        }
        prism[0]=mtg->m1.prism[0];
        prism[1]=mtg->m1.prism[1];
        prism[2]=mtg->m1.prism[2];
        if(mtg_check_prism(mtg,prism))
        {
            WriteMsg(_("棱镜检核失败！"),1);
            checking = -1;
            return;
        }
    }
}
void ReviewDlg::OnEnterOp(wxMouseEvent& event)
{
    int x,y;
    x = event.m_x;
    y = event.m_y;
    double r1 = (psm_x-x)*(psm_x-x)+(psm_y-y)*(psm_y-y);
    double r2 = (tps_x-x)*(tps_x-x)+(tps_y-y)*(tps_y-y);
    double r3 = (tar_x-x)*(tar_x-x)+(tar_y-y)*(tar_y-y);
    r1 = sqrt(r1);
    r2 = sqrt(r2);
    r3 = sqrt(r3);
    if(x>=480 && x<=550)
    {
        if(y>=85 && y<=115)
        {
            isop = 0;
        }
        else if(y>=130 && y<=160)
        {
            isop = 1;
        }
        else if(r3<=30.0)
        {
            isop = 4;
        }
        else
        {
            isop = -1;
        }
    }
    else if(r1<=15.0)
    {
        isop = 2;
    }
    else if(r2<=30.0)
    {
        isop = 3;
    }
    else
    {
        isop = -1;
    }
    panelOp->Refresh();
}

void ReviewDlg::OnCheckPst(wxMouseEvent& event)
{
    if(isPstCheck)
    {
        ReadTBM();
        //LoadTBM();
        CalTBM();
    }
}

void ReviewDlg::OnEnterPst(wxMouseEvent& event)
{
    int x,y;
    x = event.m_x;
    y = event.m_y;
    if(y>20 && y<50)
    {
        if(x>505 && x<575)
        {
            isPstCheck = true;
        }
        else
        {
            isPstCheck = false;
        }
    }
    else
    {
        isPstCheck = false;
    }
    panelPst->Refresh();
}

void ReviewDlg::OnCheckDta(wxMouseEvent& event)
{
    wxPaintDC dc(panelDta);
    int x = event.m_x;
    int y = event.m_y;
    //wxMessageBox(wxString::Format(_("%d"),y));
    if(dta_btn==0)
    {
        ReadXYZ();
    }
}

void ReviewDlg::OnEnterDta(wxMouseEvent& event)
{
    int x,y;
    x = event.m_x;
    y = event.m_y;
    if(y>20 && y<50)
    {
        if(x>505 && x<575)
        {
            dta_btn = 0;
        }
        else
        {
            dta_btn = -1;
        }
    }
    else
    {
        dta_btn = -1;
    }
    panelDta->RefreshRect(wxRect(500,20,80,30));
}

void ReviewDlg::OnPaintNavi(wxPaintEvent& event)
{
    wxPaintDC dc(panelNavi);
    int w,h;
    panelNavi->GetClientSize(&w,&h);

    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(0,-1,w,h+1);
}


void ReviewDlg::OnPaintBorder1(wxPaintEvent& event)
{
    wxPaintDC dc(panelBorder1);
    int w,h;
    panelBorder1->GetClientSize(&w,&h);

    ///background
    int *maxPixels,*minPixels;
    maxPixels=(int*)malloc(3*sizeof(int));
    memset(maxPixels,0,3);

    minPixels=(int*)malloc(3*sizeof(int));
    memset(minPixels,0,3);

    wxRect rect(0,0,w,h);

    maxPixels[0]=227;
    maxPixels[1]=227;
    maxPixels[2]=227;

    minPixels[0]=249;
    minPixels[1]=249;
    minPixels[2]=249;

    PaintGradual(panelBorder1, rect, maxPixels,minPixels,0);

    free(maxPixels);
    free(minPixels);
}

void ReviewDlg::OnPaintBorder2(wxPaintEvent& event)
{
    wxPaintDC dc(panelBorder2);
    int w,h;
    panelBorder2->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.DrawLine(0,h-1,w,h-1);
}
/*
void ReviewDlg::OnPaintBtnSys(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnSys);
    int w,h;
    panelBtnSys->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnSysState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("系统状态"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("系统状态"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("系统状态"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}
*/

void ReviewDlg::OnPaintBtnLevel(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnLevel);
    int w,h;
    panelBtnLevel->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnLevelState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("系统稳定性"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("系统稳定性"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("系统稳定性"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void ReviewDlg::OnEnterBtnLevel(wxMouseEvent& event)
{
    if(btnLevelState!=4)
    {
        btnLevelState=1;
        panelBtnLevel->Refresh();
    }
}

void ReviewDlg::OnLeaveBtnLevel(wxMouseEvent& event)
{
    if(btnLevelState!=4)
    {
        btnLevelState=2;
        panelBtnLevel->Refresh();
    }
}

void ReviewDlg::OnLeftDownBtnLevel(wxMouseEvent& event)
{
    if(btnLevelState!=4)
    {
        btnLevelState=3;
        panelBtnLevel->Refresh();
    }
}

void ReviewDlg::OnBtnLevelClick(wxMouseEvent& event)
{
    if(btnLevelState!=4)
    {
        btnLevelState=4;
        int w,h;
        panelLevel->GetClientSize(&w,&h);
        panelLevel->SetSize(160,10,w,h);
        panelLevel->Refresh();
        panelNavi->Refresh();
        panelBtnLevel->Refresh();
        if(btnOpState==4)
        {
            btnOpState=0;
            panelOp->SetPosition(wxPoint(w+w+160,10));
            panelBtnOp->Refresh();
        }
        if(btnDtaState==4)
        {
            btnDtaState=0;
            panelDta->SetPosition(wxPoint(w+w+160,10));
            panelBtnDta->Refresh();
        }
        if(btnPstState==4)
        {
            btnPstState=0;
            panelPst->SetPosition(wxPoint(w+w+160,10));
            panelBtnPst->Refresh();
        }
        if(btnTpsState==4)
        {
            btnTpsState=0;
            panelTps->SetPosition(wxPoint(w+w+160,10));
            panelBtnTps->Refresh();
        }
        if(btnTarsState==4)
        {
            btnTarsState=0;
            panelTars->SetPosition(wxPoint(w+w+160,10));
            panelBtnTars->Refresh();
        }
        if(btnPlcState==4)
        {
            btnPlcState=0;
            panelPlc->SetPosition(wxPoint(w+w+160,10));
            panelBtnPlc->Refresh();
        }
    }
}

void ReviewDlg::OnPaintBtnPlc(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnPlc);
    int w,h;
    panelBtnPlc->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnPlcState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("PLC数据"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("PLC数据"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("PLC数据"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void ReviewDlg::OnEnterBtnPlc(wxMouseEvent& event)
{
    if(btnPlcState!=4)
    {
        btnPlcState=1;
        panelBtnPlc->Refresh();
    }
}

void ReviewDlg::OnLeaveBtnPlc(wxMouseEvent& event)
{
    if(btnPlcState!=4)
    {
        btnPlcState=2;
        panelBtnPlc->Refresh();
    }
}

void ReviewDlg::OnLeftDownBtnPlc(wxMouseEvent& event)
{
    if(btnPlcState!=4)
    {
        btnPlcState=3;
        panelBtnPlc->Refresh();
    }
}

void ReviewDlg::OnBtnPlcClick(wxMouseEvent& event)
{
    if(btnPlcState!=4)
    {
        btnPlcState=4;
        int w,h;
        panelPlc->GetClientSize(&w,&h);
        panelPlc->SetSize(160,10,w,h);
        panelPlc->Refresh();
        panelNavi->Refresh();
        panelBtnPlc->Refresh();
        if(btnOpState==4)
        {
            btnOpState=0;
            panelOp->SetPosition(wxPoint(w+w+160,10));
            panelBtnOp->Refresh();
        }
        if(btnDtaState==4)
        {
            btnDtaState=0;
            panelDta->SetPosition(wxPoint(w+w+160,10));
            panelBtnDta->Refresh();
        }
        if(btnPstState==4)
        {
            btnPstState=0;
            panelPst->SetPosition(wxPoint(w+w+160,10));
            panelBtnPst->Refresh();
        }
        if(btnTpsState==4)
        {
            btnTpsState=0;
            panelTps->SetPosition(wxPoint(w+w+160,10));
            panelBtnTps->Refresh();
        }
        if(btnTarsState==4)
        {
            btnTarsState=0;
            panelTars->SetPosition(wxPoint(w+w+160,10));
            panelBtnTars->Refresh();
        }
        if(btnLevelState==4)
        {
            btnLevelState=0;
            panelLevel->SetPosition(wxPoint(w+w+160,10));
            panelBtnLevel->Refresh();
        }
    }
}


void ReviewDlg::OnPaintBtnDta(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnDta);
    int w,h;
    panelBtnDta->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnDtaState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("隧道中线"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("隧道中线"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        //dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("隧道中线"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void ReviewDlg::OnEnterBtnOp(wxMouseEvent& event)
{
    if(btnOpState!=4)
    {
        btnOpState=1;
        panelBtnOp->Refresh();
    }
}

void ReviewDlg::OnLeaveBtnOp(wxMouseEvent& event)
{
    if(btnOpState!=4)
    {
        btnOpState=2;
        panelBtnOp->Refresh();
    }
}

void ReviewDlg::OnLeftDownBtnOp(wxMouseEvent& event)
{
    if(btnOpState!=4)
    {
        btnOpState=3;
        panelBtnOp->Refresh();
    }
}

void ReviewDlg::OnBtnOpClick(wxMouseEvent& event)
{
    if(btnOpState!=4)
    {
        btnOpState=4;
        int w,h;
        panelOp->GetClientSize(&w,&h);
        panelOp->SetSize(160,10,w,h);
        panelOp->Refresh();
        panelNavi->Refresh();
        panelBtnOp->Refresh();
        /*if(btnSysState==4)
        {
            btnSysState=0;
            panelSys->SetPosition(wxPoint(w+w+160,10));
            panelBtnSys->Refresh();
        }*/
        if(btnDtaState==4)
        {
            btnDtaState=0;
            panelDta->SetPosition(wxPoint(w+w+160,10));
            panelBtnDta->Refresh();
        }
        if(btnPstState==4)
        {
            btnPstState=0;
            panelPst->SetPosition(wxPoint(w+w+160,10));
            panelBtnPst->Refresh();
        }
        if(btnTpsState==4)
        {
            btnTpsState=0;
            panelTps->SetPosition(wxPoint(w+w+160,10));
            panelBtnTps->Refresh();
        }
        if(btnTarsState==4)
        {
            btnTarsState=0;
            panelTars->SetPosition(wxPoint(w+w+160,10));
            panelBtnTars->Refresh();
        }
        if(btnPlcState==4)
        {
            btnPlcState=0;
            panelPlc->SetPosition(wxPoint(w+w+160,10));
            panelBtnPlc->Refresh();
        }
        if(btnLevelState==4)
        {
            btnLevelState=0;
            panelLevel->SetPosition(wxPoint(w+w+160,10));
            panelBtnLevel->Refresh();
        }
    }
}

void ReviewDlg::OnPaintBtnOp(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnOp);
    int w,h;
    panelBtnOp->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnOpState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("系统操作"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("系统操作"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("系统操作"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void ReviewDlg::OnEnterBtnTars(wxMouseEvent& event)
{
    if(btnTarsState!=4)
    {
        btnTarsState=1;
        panelBtnTars->Refresh();
    }
}

void ReviewDlg::OnLeaveBtnTars(wxMouseEvent& event)
{
    if(btnTarsState!=4)
    {
        btnTarsState=2;
        panelBtnTars->Refresh();
    }
}

void ReviewDlg::OnLeftDownBtnTars(wxMouseEvent& event)
{
    if(btnTarsState!=4)
    {
        btnTarsState=3;
        panelBtnTars->Refresh();
    }
}

void ReviewDlg::OnBtnTarsClick(wxMouseEvent& event)
{
    if(btnTarsState!=4)
    {
        btnTarsState=4;
        int w,h;
        panelTars->GetClientSize(&w,&h);
        panelTars->SetSize(160,10,w,h);
        panelTars->Refresh();
        panelNavi->Refresh();
        panelBtnTars->Refresh();
        /*if(btnSysState==4)
        {
            btnSysState=0;
            panelSys->SetPosition(wxPoint(w+w+160,10));
            panelBtnSys->Refresh();
        }*/
        if(btnDtaState==4)
        {
            btnDtaState=0;
            panelDta->SetPosition(wxPoint(w+w+160,10));
            panelBtnDta->Refresh();
        }
        if(btnPstState==4)
        {
            btnPstState=0;
            panelPst->SetPosition(wxPoint(w+w+160,10));
            panelBtnPst->Refresh();
        }
        if(btnTpsState==4)
        {
            btnTpsState=0;
            panelTps->SetPosition(wxPoint(w+w+160,10));
            panelBtnTps->Refresh();
        }
        if(btnOpState==4)
        {
            btnOpState=0;
            panelOp->SetPosition(wxPoint(w+w+160,10));
            panelBtnOp->Refresh();
        }
        if(btnPlcState==4)
        {
            btnPlcState=0;
            panelPlc->SetPosition(wxPoint(w+w+160,10));
            panelBtnPlc->Refresh();
        }
        if(btnLevelState==4)
        {
            btnLevelState=0;
            panelLevel->SetPosition(wxPoint(w+w+160,10));
            panelBtnLevel->Refresh();
        }
    }
}

void ReviewDlg::OnPaintBtnTars(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnTars);
    int w,h;
    panelBtnTars->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnTarsState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("激光靶"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("激光靶"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("激光靶"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void ReviewDlg::OnEnterBtnTps(wxMouseEvent& event)
{
    if(btnTpsState!=4)
    {
        btnTpsState=1;
        panelBtnTps->Refresh();
    }
}

void ReviewDlg::OnLeaveBtnTps(wxMouseEvent& event)
{
    if(btnTpsState!=4)
    {
        btnTpsState=2;
        panelBtnTps->Refresh();
    }
}

void ReviewDlg::OnLeftDownBtnTps(wxMouseEvent& event)
{
    if(btnTpsState!=4)
    {
        btnTpsState=3;
        panelBtnTps->Refresh();
    }
}

void ReviewDlg::OnBtnTpsClick(wxMouseEvent& event)
{
    if(btnTpsState!=4)
    {
        btnTpsState=4;
        int w,h;
        panelTps->GetClientSize(&w,&h);
        panelTps->SetSize(160,10,w,h);
        panelTps->Refresh();
        panelNavi->Refresh();
        panelBtnTps->Refresh();
        /*if(btnSysState==4)
        {
            btnSysState=0;
            panelSys->SetPosition(wxPoint(w+w+160,10));
            panelBtnSys->Refresh();
        }*/
        if(btnDtaState==4)
        {
            btnDtaState=0;
            panelDta->SetPosition(wxPoint(w+w+160,10));
            panelBtnDta->Refresh();
        }
        if(btnPstState==4)
        {
            btnPstState=0;
            panelPst->SetPosition(wxPoint(w+w+160,10));
            panelBtnPst->Refresh();
        }
        if(btnTarsState==4)
        {
            btnTarsState=0;
            panelTars->SetPosition(wxPoint(w+w+160,10));
            panelBtnTars->Refresh();
        }
        if(btnOpState==4)
        {
            btnOpState=0;
            panelOp->SetPosition(wxPoint(w+w+160,10));
            panelBtnOp->Refresh();
        }
        if(btnPlcState==4)
        {
            btnPlcState=0;
            panelPlc->SetPosition(wxPoint(w+w+160,10));
            panelBtnPlc->Refresh();
        }
        if(btnLevelState==4)
        {
            btnLevelState=0;
            panelLevel->SetPosition(wxPoint(w+w+160,10));
            panelBtnLevel->Refresh();
        }
    }
}

void ReviewDlg::OnPaintBtnTps(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnTps);
    int w,h;
    panelBtnTps->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnTpsState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("全站仪"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("全站仪"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("全站仪"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void ReviewDlg::OnPaintBtnPst(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnPst);
    int w,h;
    panelBtnPst->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnPstState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("盾构姿态"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("盾构姿态"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("盾构姿态"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void ReviewDlg::OnEnterBtnPst(wxMouseEvent& event)
{
    if(btnPstState!=4)
    {
        btnPstState=1;
        panelBtnPst->Refresh();
    }
}

void ReviewDlg::OnLeaveBtnPst(wxMouseEvent& event)
{
    if(btnPstState!=4)
    {
        btnPstState=2;
        panelBtnPst->Refresh();
    }
}

void ReviewDlg::OnLeftDownBtnPst(wxMouseEvent& event)
{
    if(btnPstState!=4)
    {
        btnPstState=3;
        panelBtnPst->Refresh();
    }
}

void ReviewDlg::OnBtnPstClick(wxMouseEvent& event)
{
    if(btnPstState!=4)
    {
        btnPstState=4;
        int w,h;
        panelPst->GetClientSize(&w,&h);
        panelPst->SetSize(160,10,w,h);
        panelPst->Refresh();
        panelNavi->Refresh();
        //panelBtnSys->Refresh();
        /*if(btnSysState==4)
        {
            btnSysState=0;
            panelSys->SetPosition(wxPoint(w+w+160,10));
            panelBtnSys->Refresh();
        }*/
        if(btnDtaState==4)
        {
            btnDtaState=0;
            panelDta->SetPosition(wxPoint(w+w+160,10));
            panelBtnDta->Refresh();
        }
        if(btnTpsState==4)
        {
            btnTpsState=0;
            panelTps->SetPosition(wxPoint(w+w+160,10));
            panelBtnTps->Refresh();
        }
        if(btnTarsState==4)
        {
            btnTarsState=0;
            panelTars->SetPosition(wxPoint(w+w+160,10));
            panelBtnTars->Refresh();
        }
        if(btnOpState==4)
        {
            btnOpState=0;
            panelOp->SetPosition(wxPoint(w+w+160,10));
            panelBtnOp->Refresh();
        }
        if(btnPlcState==4)
        {
            btnPlcState=0;
            panelPlc->SetPosition(wxPoint(w+w+160,10));
            panelBtnPlc->Refresh();
        }
        if(btnLevelState==4)
        {
            btnLevelState=0;
            panelLevel->SetPosition(wxPoint(w+w+160,10));
            panelBtnLevel->Refresh();
        }
    }
}
/*
void ReviewDlg::OnEnterBtnSys(wxPaintEvent& event)
{
    if(btnSysState!=4)
    {
        btnSysState=1;
        panelBtnSys->Refresh();
    }
}

void ReviewDlg::OnLeaveBtnSys(wxMouseEvent& event)
{
    if(btnSysState!=4)
    {
        btnSysState=2;
        panelBtnSys->Refresh();
    }
}

void ReviewDlg::OnLeftDownBtnSys(wxMouseEvent& event)
{
    if(btnSysState!=4)
    {
        btnSysState=3;
        panelBtnSys->Refresh();
    }
}

void ReviewDlg::OnBtnSysClick(wxMouseEvent& event)
{
    if(btnSysState!=4)
    {
        btnSysState=4;
        int w,h;
        panelSys->GetClientSize(&w,&h);
        panelSys->SetSize(160,10,w,h);
        panelSys->Refresh();
        panelNavi->Refresh();
        panelBtnSys->Refresh();
        if(btnPstState==4)
        {
            btnPstState=0;
            panelPst->SetPosition(wxPoint(w+w+160,10));
            panelBtnPst->Refresh();
        }
        if(btnDtaState==4)
        {
            btnDtaState=0;
            panelDta->SetPosition(wxPoint(w+w+160,10));
            panelBtnDta->Refresh();
        }
        if(btnTpsState==4)
        {
            btnTpsState=0;
            panelTps->SetPosition(wxPoint(w+w+160,10));
            panelBtnTps->Refresh();
        }
        if(btnTarsState==4)
        {
            btnTarsState=0;
            panelTars->SetPosition(wxPoint(w+w+160,10));
            panelBtnTars->Refresh();
        }
        if(btnOpState==4)
        {
            btnOpState=0;
            panelOp->SetPosition(wxPoint(w+w+160,10));
            panelBtnOp->Refresh();
        }
    }
}*/

void ReviewDlg::OnEnterBtnDta(wxMouseEvent& event)
{
    if(btnDtaState!=4)
    {
        btnDtaState=1;
        panelBtnDta->Refresh();
    }
}

void ReviewDlg::OnLeaveBtnDta(wxMouseEvent& event)
{
     if(btnDtaState!=4)
    {
        btnDtaState=2;
        panelBtnDta->Refresh();
    }
}

void ReviewDlg::OnLeftDownBtnDta(wxMouseEvent& event)
{
     if(btnDtaState!=4)
    {
        btnDtaState=3;
        panelBtnDta->Refresh();
    }
}

void ReviewDlg::OnBtnDtaClick(wxMouseEvent& event)
{
     if(btnDtaState!=4)
    {
        btnDtaState=4;
        int w,h;
        panelDta->GetClientSize(&w,&h);
        panelDta->SetSize(160,10,w,h);
        panelDta->Refresh();
        panelNavi->Refresh();
        panelBtnDta->Refresh();
        /*if(btnSysState==4)
        {
            btnSysState=0;
            panelSys->SetPosition(wxPoint(w+w+160,10));
            panelBtnSys->Refresh();
        }*/
        if(btnPstState==4)
        {
            btnPstState=0;
            panelPst->SetPosition(wxPoint(w+w+160,10));
            panelBtnPst->Refresh();
        }
        if(btnTpsState==4)
        {
            btnTpsState=0;
            panelTps->SetPosition(wxPoint(w+w+160,10));
            panelBtnTps->Refresh();
        }
        if(btnTarsState==4)
        {
            btnTarsState=0;
            panelTars->SetPosition(wxPoint(w+w+160,10));
            panelBtnTars->Refresh();
        }
        if(btnOpState==4)
        {
            btnOpState=0;
            panelOp->SetPosition(wxPoint(w+w+160,10));
            panelBtnOp->Refresh();
        }
        if(btnPlcState==4)
        {
            btnPlcState=0;
            panelPlc->SetPosition(wxPoint(w+w+160,10));
            panelBtnPlc->Refresh();
        }
        if(btnLevelState==4)
        {
            btnLevelState=0;
            panelLevel->SetPosition(wxPoint(w+w+160,10));
            panelBtnLevel->Refresh();
        }
    }
}
/*
void ReviewDlg::OnPaintSys(wxPaintEvent& event)
{
    wxPaintDC dc(panelSys);
    int w,h;
    panelSys->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

    dc.SetFont(normalFont);
    dc.SetTextForeground(wxColor(68,68,68));
    //dc.DrawLabel(wxString::Format(_("通讯连接")),wxRect(50,25,0,0),wxALIGN_LEFT|wxALIGN_TOP);
    dc.SetPen(wxPen(wxColor(189,189,189)));

    dc.DrawLabel(_("隧道中线"),wxRect(60,35,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
    dc.DrawLabel(_("盾构姿态"),wxRect(60,75,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
    dc.DrawLabel(_("全站仪"),wxRect(60,115,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
    dc.DrawLabel(_("激光靶"),wxRect(60,155,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
    dc.SetTextForeground(wxColor(20,20,248));
    dc.DrawLabel(wxString::Format(_("%.1f"),maxh*1000.0)+_("/")+wxString::Format(_("%.1f"),maxv*1000.0)+_(" mm"),wxRect(200,35,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

    if(checked[0]==0)
    {
        dc.SetTextForeground(wxColor(20,20,248));
    }
    else
    {
        dc.SetTextForeground(wxColor(248,20,20));
    }
    dc.DrawLabel(_("√"),wxRect(180,35,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    if(checked[1]==0)
    {
        dc.SetTextForeground(wxColor(20,20,248));
    }
    else
    {
        dc.SetTextForeground(wxColor(248,20,20));
    }
    dc.DrawLabel(_("√"),wxRect(180,75,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    if(mtg->itps)
    {
        dc.SetTextForeground(wxColor(20,20,248));
    }
    else
    {
        dc.SetTextForeground(wxColor(248,20,20));
    }
    dc.DrawLabel(_("√"),wxRect(180,115,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    if(mtg->iinc && mtg->icam)
    {
        dc.SetTextForeground(wxColor(20,20,248));
    }
    else
    {
        dc.SetTextForeground(wxColor(248,20,20));
    }
    dc.DrawLabel(_("√"),wxRect(180,155,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(50,50,560,50);
    //dc.DrawLine(50,230,560,230);
}*/


void ReviewDlg::OnPaintDta(wxPaintEvent& event)
{
    wxPaintDC dc(panelDta);
    int w,h;
    panelDta->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(-1,-1,w+2,h+2);
        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.DrawLine(0,0,w,0);
        memDC.DrawLine(w-1,0,w-1,h);
        memDC.DrawLine(0,h-1,w,h-1);

        wxFont chs(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont EngFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(68,68,68));
        //dc.DrawLabel(wxString::Format(_("通讯连接")),wxRect(50,25,0,0),wxALIGN_LEFT|wxALIGN_TOP);
        memDC.SetPen(wxPen(wxColor(189,189,189)));

        int x1 = 35;
        int y1 = 35;
        memDC.DrawLabel(_("平曲线"),wxRect(x1+10,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        //dc.DrawCircle(180,35,8);
        int nh = road_number_horizon(&mtg->r);
        if(nh>2)
        {
            memDC.SetTextForeground(wxColor(20,255,20));
            memDC.DrawLabel(_("√"),wxRect(x1+75,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,20,20));
            memDC.DrawLabel(_("×"),wxRect(x1+75,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetTextForeground(wxColor(68,68,68));

        memDC.DrawLabel(_("竖曲线"),wxRect(x1+155,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        int nv = road_number_vertical(&mtg->r);
        if(nv>2)
        {
            memDC.SetTextForeground(wxColor(20,255,20));
            memDC.DrawLabel(_("√"),wxRect(x1+215,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,20,20));
            memDC.DrawLabel(_("×"),wxRect(x1+215,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetTextForeground(wxColor(68,68,68));
        if(dta_btn==0)
        {

            memDC.SetPen(wxPen(wxColor(122,176,232)));
            memDC.DrawRectangle(x1+470,y1-15,70,30);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(189,189,189)));
            memDC.DrawRectangle(x1+470,y1-15,70,30);
        }
        memDC.DrawLabel(_("检查"),wxRect(505,35,70,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetTextForeground(wxColor(68,68,68));
        memDC.SetPen(wxPen(wxColor(168,168,168)));
        memDC.DrawLine(x1,y1+20,x1+540,y1+20);

        memDC.SetBrush(wxBrush(wxColor(238,236,234)));
        memDC.SetPen(wxPen(wxColor(168,168,168)));

        memDC.DrawRectangle(x1,y1+35,540,50);

        memDC.DrawLine(x1,y1+85,x1,y1+380);
        memDC.DrawLine(x1+539,y1+85,x1+539,y1+380);
        memDC.DrawLine(x1,y1+380,x1+539,y1+380);

        memDC.DrawLine(x1+85,y1+60,x1+540,y1+60);
        memDC.DrawLine(x1+85,y1+35,x1+85,y1+85);
        memDC.DrawLine(x1+185,y1+60,x1+185,y1+85);
        memDC.DrawLine(x1+285,y1+60,x1+285,y1+85);
        memDC.DrawLine(x1+365,y1+35,x1+365,y1+85);
        memDC.DrawLine(x1+435,y1+60,x1+435,y1+85);
        memDC.DrawLine(x1+505,y1+60,x1+505,y1+85);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1+1,y1+36,x1+539,y1+36);
        memDC.DrawLine(x1+1,y1+36,x1+1,y1+84);
        memDC.DrawLine(x1+86,y1+36,x1+86,y1+59);
        memDC.DrawLine(x1+86,y1+61,x1+86,y1+84);
        memDC.DrawLine(x1+186,y1+61,x1+186,y1+84);
        memDC.DrawLine(x1+286,y1+61,x1+286,y1+84);
        memDC.DrawLine(x1+366,y1+36,x1+366,y1+59);
        memDC.DrawLine(x1+366,y1+61,x1+366,y1+84);
        memDC.DrawLine(x1+436,y1+61,x1+436,y1+84);
        memDC.DrawLine(x1+506,y1+61,x1+506,y1+84);
        memDC.DrawLine(x1+86,y1+61,x1+539,y1+61);

        memDC.DrawLabel(_("位置"),wxRect(x1,y1+35,85,50),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("坐标"),wxRect(x1+85,y1+35,300,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("X"),wxRect(x1+85,y1+60,100,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("Y"),wxRect(x1+185,y1+60,100,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("Z"),wxRect(x1+285,y1+60,80,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("偏差(mm)"),wxRect(x1+365,y1+35,140,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("平面"),wxRect(x1+365,y1+60,70,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("高程"),wxRect(x1+435,y1+60,70,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ReviewDlg::OnPaintPst(wxPaintEvent& event)
{
    wxPaintDC dc(panelPst);
    int w,h;
    panelPst->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(-1,-1,w+2,h+2);
        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.DrawLine(0,0,w,0);
        memDC.DrawLine(w-1,0,w-1,h);
        memDC.DrawLine(0,h-1,w,h-1);

        wxFont chs(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont EngFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(68,68,68));
        //dc.DrawLabel(wxString::Format(_("通讯连接")),wxRect(50,25,0,0),wxALIGN_LEFT|wxALIGN_TOP);
        memDC.SetPen(wxPen(wxColor(189,189,189)));
        int x1 = 35;
        int y1 = 35;
        memDC.DrawLabel(_("姿态初始化"),wxRect(x1+10,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        //dc.DrawCircle(180,35,8);
        if(mtg->m0.t1)
        {
            memDC.SetTextForeground(wxColor(20,255,20));
            memDC.DrawLabel(_("√"),wxRect(x1+100,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,20,20));
            memDC.DrawLabel(_("×"),wxRect(x1+100,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetTextForeground(wxColor(68,68,68));
        if(isPstCheck)
        {
            memDC.SetPen(wxPen(wxColor(122,176,232)));
            memDC.DrawRectangle(x1+470,y1-15,70,30);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(189,189,189)));
            memDC.DrawRectangle(x1+470,y1-15,70,30);
        }
        memDC.DrawLabel(_("检查"),wxRect(x1+470,y1,70,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetTextForeground(wxColor(68,68,68));
        memDC.SetPen(wxPen(wxColor(168,168,168)));
        memDC.DrawLine(x1,y1+20,x1+540,y1+20);

        memDC.SetBrush(wxBrush(wxColor(238,236,234)));
        memDC.SetPen(wxPen(wxColor(168,168,168)));

        memDC.DrawRectangle(x1,y1+35,540,50);
        memDC.DrawLine(x1+100,y1+60,x1+540,y1+60);
        memDC.DrawLine(x1+100,y1+35,x1+100,y1+380);
        memDC.DrawLine(x1+210,y1+60,x1+210,y1+160);
        memDC.DrawLine(x1+320,y1+35,x1+320,y1+380);
        memDC.DrawLine(x1+430,y1+60,x1+430,y1+160);
        memDC.DrawLine(x1,y1+110,x1+540,y1+110);
        memDC.DrawLine(x1,y1+135,x1+540,y1+135);
        memDC.DrawLine(x1,y1+160,x1+540,y1+160);
        //memDC.DrawLine(60,220,575,220);
        memDC.DrawLine(x1,y1+35,x1,y1+380);
        memDC.DrawLine(x1+540,y1+35,x1+540,y1+380);
        memDC.DrawLine(x1,y1+380,x1+540,y1+380);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1+1,y1+36,x1+539,y1+36);
        memDC.DrawLine(x1+1,y1+36,x1+1,y1+84);
        memDC.DrawLine(x1+101,y1+36,x1+101,y1+59);
        memDC.DrawLine(x1+101,y1+61,x1+101,y1+84);
        memDC.DrawLine(x1+101,y1+61,x1+209,y1+61);
        memDC.DrawLine(x1+211,y1+61,x1+211,y1+84);
        memDC.DrawLine(x1+211,y1+61,x1+319,y1+61);
        memDC.DrawLine(x1+321,y1+36,x1+321,y1+59);
        memDC.DrawLine(x1+321,y1+61,x1+321,y1+84);
        memDC.DrawLine(x1+321,y1+61,x1+429,y1+61);
        memDC.DrawLine(x1+431,y1+61,x1+431,y1+84);
        memDC.DrawLine(x1+431,y1+61,x1+539,y1+61);
        //memDC.DrawLine(540,70,540,120);
        memDC.DrawLabel(_("位 置"),wxRect(x1,y1+35,100,50),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("水平[mm]"),wxRect(x1+100,y1+35,220,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("切口"),wxRect(x1+100,y1+60,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("盾尾"),wxRect(x1+210,y1+60,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("垂直[mm]"),wxRect(x1+320,y1+35,220,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("切口"),wxRect(x1+320,y1+60,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("盾尾"),wxRect(x1+430,y1+60,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("系统"),wxRect(x1,y1+85,100,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("用户"),wxRect(x1,y1+110,100,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("较差"),wxRect(x1,y1+135,100,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("图形"),wxRect(x1,y1+160,100,210),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(20,20,207)));
        memDC.SetBrush(wxBrush(wxColor(20,20,207)));
        memDC.DrawLine(x1+210,y1+180,x1+210,y1+350);
        memDC.DrawLine(x1+350,y1+265,x1+520,y1+265);
        //memDC.DrawLine(385,300,385,292);
        memDC.SetPen(wxPen(wxColor(207,20,20)));
        memDC.SetBrush(wxBrush(wxColor(207,20,20)));
        memDC.DrawLine(x1+210+(int)(mtg->m1.headh*1000.0-headh*1000.0),y1+180,x1+210+(int)(mtg->m1.tailh*1000.0-tailh*1000.0),y1+350);
        memDC.DrawLine(x1+350,y1+265-(int)(mtg->m1.tailv*1000.0-tailv*1000.0),x1+520,y1+265-(int)(mtg->m1.headv*1000.0-headv*1000.0));

        memDC.DrawLabel(wxString::Format(_("%d"),(int)(mtg->m1.headh*1000.0)),wxRect(x1+100,y1+85,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(mtg->m1.tailh*1000.0)),wxRect(x1+210,y1+85,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(mtg->m1.headv*1000.0)),wxRect(x1+320,y1+85,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(mtg->m1.tailv*1000.0)),wxRect(x1+430,y1+85,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(headh*1000.0)),wxRect(x1+100,y1+110,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(tailh*1000.0)),wxRect(x1+210,y1+110,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(headv*1000.0)),wxRect(x1+320,y1+110,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(tailv*1000.0)),wxRect(x1+430,y1+110,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetTextForeground(wxColor(255,20,255));
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(mtg->m1.headh*1000.0-headh*1000.0)),wxRect(x1+100,y1+135,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(mtg->m1.tailh*1000.0-tailh*1000.0)),wxRect(x1+210,y1+135,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(mtg->m1.headv*1000.0-headv*1000.0)),wxRect(x1+320,y1+135,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),(int)(mtg->m1.tailv*1000.0-tailv*1000.0)),wxRect(x1+430,y1+135,110,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLine(cx,cy-60,cx,cy+60);
        //memDC.DrawLine(cx+190,cy-60,cx+190,cy+60);
        //memDC.DrawLine(cx+380,cy-60,cx+380,cy+60);
        //memDC.SetBrush(*wxTRANSPARENT_BRUSH);

        memDC.SetPen(wxPen(wxColor(255,68,68)));



        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ReviewDlg::OnPaintTps(wxPaintEvent& event)
{
    wxPaintDC dc(panelTps);
    int w,h;
    panelTps->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    wxString str[4];
    wxBrush b[4];
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(-1,-1,w+2,h+2);
        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.DrawLine(0,0,w,0);
        memDC.DrawLine(w-1,0,w-1,h);
        memDC.DrawLine(0,h-1,w,h-1);

        wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont EngFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(normalFont);
        memDC.SetTextForeground(wxColor(68,68,68));
        //dc.DrawLabel(wxString::Format(_("通讯连接")),wxRect(50,25,0,0),wxALIGN_LEFT|wxALIGN_TOP);
        memDC.SetPen(wxPen(wxColor(189,189,189)));

        memDC.DrawLabel(_("全站仪"),wxRect(45,35,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(35,55,575,55);

        //memDC.DrawLabel(_("电子补偿"),wxRect(70,85,80,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(35,70,575,70);
        memDC.DrawLine(35,70,35,275);
        memDC.DrawLine(574,70,574,275);
        //memDC.DrawLine(575,85,575,270);
        memDC.DrawLine(35,275,575,275);

        /*memDC.DrawLabel(_("TCA参数"),wxRect(265,85,80,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(255,85,265,85);
        memDC.DrawLine(255,85,255,270);
        memDC.DrawLine(345,85,570,85);
        memDC.DrawLine(255,270,570,270);
        memDC.DrawLine(570,85,570,270);*/

        //memDC.DrawLabel(_("通讯连接"),wxRect(270,120,80,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("ATR"),wxRect(300,105,80,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("棱镜常数"),wxRect(300,135,80,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        //if(mtg->itps)
        //{
            tps_get_atr(&mtg->tps);
            if(mtg->tps.atr==0)
            {
                str[0] = _("关闭");
            }
            else
            {
                str[0] = _("打开");
            }
            tps_get_prism(&mtg->tps);
            str[1] = wxString::Format(_("%.1f"),mtg->tps.prism);
        //}
        /*else
        {
            str[0] = _("连接断开");
            b[0] = wxBrush(wxColor(255,45,48));
            b[1] = wxBrush(wxColor(255,45,48));
            str[1] = _("---");
            b[2] = wxBrush(wxColor(255,45,48));
            str[2] = _("---");
            b[3] = wxBrush(wxColor(255,45,48));
            str[3] = _("---");
        }*/
        memDC.SetTextForeground(wxColor(255,20,255));
        memDC.DrawLabel(str[0],wxRect(415,92,80,24),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(str[1],wxRect(415,122,80,24),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(415,112,495,112);
        memDC.DrawLine(415,142,495,142);
        //memDC.DrawLabel(str[2],wxRect(415,167,0,24),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        int a=150;
        int rad=a*5/12;
        int cx=70+a/2;
        int cy=90+a/2;

        memDC.SetBrush(wxBrush(wxColor(206,206,206)));
        memDC.SetPen(wxPen(wxColor(0,0,0)));
        memDC.DrawRectangle(cx-a/2,cy-a/2,a,a);

        ///大圆
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.SetPen(wxPen(wxColor(0,0,0)));
        memDC.DrawCircle(cx,cy,rad);
        ///小圆
        memDC.DrawCircle(cx,cy,rad/2);
        ///双轴
        memDC.DrawLine(cx-a/2+a/24,cy,cx+a/2-a/24,cy);
        memDC.DrawLine(cx,cy-a/2+a/24,cx,cy+a/2-a/24);
        static const  double r2s=206264.80624709635515647335733078;
        double dx,dy;
        dx=mtg->m.comp[0]*r2s/10;
        dy=mtg->m.comp[1]*r2s/10;
        ///如圆心超出大圆，则画在大圆上
        double dist=sqrt(dx*dx+dy*dy);
        if(dist>rad)
        {
            dx*=rad/dist;
            dy*=rad/dist;
        }
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        memDC.DrawCircle(cx-dx,cy+dy,rad/4+1);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ReviewDlg::OnPaintTars(wxPaintEvent& event)
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
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(-1,-1,w+2,h+2);
        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.DrawLine(0,0,w,0);
        memDC.DrawLine(w-1,0,w-1,h);
        memDC.DrawLine(0,h-1,w,h-1);

        wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont EngFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(normalFont);
        memDC.SetTextForeground(wxColor(68,68,68));
        //dc.DrawLabel(wxString::Format(_("通讯连接")),wxRect(50,25,0,0),wxALIGN_LEFT|wxALIGN_TOP);
        memDC.SetPen(wxPen(wxColor(189,189,189)));
        memDC.SetTextForeground(wxColor(68,68,68));
        memDC.DrawLine(35,55,575,55);

        memDC.DrawLabel(_("激光靶"),wxRect(45,35,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(35,55,575,55);

        //memDC.DrawLabel(_("激光靶姿态"),wxRect(70,85,80,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(35,70,570,70);
        memDC.DrawLine(35,70,35,325);
        //memDC.DrawLine(150,85,570,85);
        memDC.DrawLine(570,70,570,325);
        memDC.DrawLine(35,325,570,325);

        int w1=150;
        int h1=150;
        int x1=70;
        int y1=90;
        int x2=x1+w1/12;
        int y2=y1+w1/12;
        int w2=x1+w1-x2-w1/12;
        int h2=y1+h1-y2-w1/12;
        int rad=w1*5/12;
        int cx=250;
        int cy=260;

        memDC.SetBrush(wxBrush(wxColor(77,80,82)));
        memDC.SetPen(wxPen(wxColor(20,20,20)));
        memDC.DrawRectangle(x1-1,y1-1,w1+2,h1+2);
        memDC.SetPen(wxPen(wxColor(89,91,93)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        memDC.DrawLine(x1+w1+20+4,y2,x1+w1+20+20,y2);
        memDC.DrawLine(x1+w1+20+7,y2+h2/4,x1+w1+20+17,y2+h2/4);
        memDC.DrawLine(x1+w1+20+4,y2+h2/2,x1+w1+20+20,y2+h2/2);
        memDC.DrawLine(x1+w1+20+7,y2+h2*3/4,x1+w1+20+17,y2+h2*3/4);
        memDC.DrawLine(x1+w1+20,y2+h2,x1+w1+20+25,y2+h2);
        //memDC.SetTextForeground(wxColor(248,228,48));
        memDC.DrawLabel(_("俯仰"),wxRect(x1+w1+120,y1+15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("转动"),wxRect(x1+w1+120,y1+45,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        //memDC.DrawLabel(_("俯仰"),wxRect(x1+w1+120,y1+h1/4,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLabel(_("转动"),wxRect(x1+w1+120,y1+h1*3/4,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetFont(EngFont);
        memDC.SetTextForeground(wxColor(255,20,255));
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->m.inc[0])+_(" °"),wxRect(x1+w1+120+120,y1+15,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1+120+80,y1+25,x1+w1+120+160,y1+25);
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->m.inc[1])+_(" °"),wxRect(x1+w1+120+120,y1+45,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1+120+80,y1+55,x1+w1+120+160,y1+55);

        memDC.SetTextForeground(wxColor(68,68,68));
        memDC.DrawLine(x1+w1+20+12,y1,x1+w1+20+12,y1+h1);
        memDC.DrawLabel(_("0"),wxRect(x1+w1+20+12+20,y1+h1/2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("40"),wxRect(x1+w1+20+12+20,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("40"),wxRect(x1+w1+20+12+20,y2+h2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLine(x2,y1+h1+20+4,x2,y1+h1+20+20);
        memDC.DrawLine(x2+w2/4,y1+h1+20+7,x2+w2/4,y1+h1+20+17);
        memDC.DrawLine(x2+w2/2,y1+h1+20+4,x2+w2/2,y1+h1+20+20);
        memDC.DrawLine(x2+w2*3/4,y1+h1+20+7,x2+w2*3/4,y1+h1+20+17);
        memDC.DrawLine(x2+w2,y1+h1+20+4,x2+w2,y1+h1+20+20);
        memDC.DrawLine(x1,y1+h1+20+12,x1+w1,y1+h1+20+12);
        memDC.DrawLabel(_("0"),wxRect(x1,y1+h1+20+25,w1,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(_("50"),wxRect(x2,y1+h1+20+25,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(_("50"),wxRect(x2+w2,y1+h1+20+25,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

        //FILE* fp=fopen("E:\\info_tar.log","w");

        double sx=w1/(mtg->camset[0].right-mtg->camset[0].left);
        double sy=h1/(mtg->camset[0].down-mtg->camset[0].up);

        double lcx0=(mtg->camset[0].right+mtg->camset[0].left)/2.0;
        double lcy0=(mtg->camset[0].down+mtg->camset[0].up)/2.0;

        memDC.SetPen(wxPen(wxColor(20,20,20)));
        memDC.SetBrush(wxBrush(wxColor(206,206,206)));
        memDC.DrawRectangle(x2-1,y2-1,w2+2,h2+2);
        memDC.SetBrush(wxBrush(wxColor(255,0,0)));
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        double lcx1=0.0;
        double lcy1=0.0;
        wxPoint pts[3];
        if(mtg->m1.cam[0]==0)
        {
            lcx1=x1+w1/2.0;
            lcy1=y1+h1/2.0;
            memDC.DrawCircle(lcx1,lcy1,8);
        }
        else
        {
            lcx1=x1+w1/2.0+(mtg->m1.cam[0]-lcx0)*sx;
            lcy1=y1+h1/2.0+(mtg->m1.cam[1]-lcy0)*sy;
            memDC.DrawCircle(lcx1,lcy1,8);
        }
        pts[0].x = x1+w1+20+12;
        pts[0].y = lcy1;
        pts[1].x = x1+w1+20+12-8;
        pts[1].y = lcy1-4;
        pts[2].x = x1+w1+20+12-8;
        pts[2].y = lcy1+4;
        memDC.DrawPolygon(3,pts);

        pts[0].x = lcx1;
        pts[0].y = y1+h1+20+12;
        pts[1].x = lcx1-4;
        pts[1].y = y1+h1+20+12-8;
        pts[2].x = lcx1+4;
        pts[2].y = y1+h1+20+12-8;
        memDC.DrawPolygon(3,pts);

        int cx1=x1+w1/24;
        int cx2=x1+w1/2;
        int cx3=x1+w1*23/24;

        int cy1=y1+w1/24;
        int cy2=y1+w1/2;
        int cy3=y1+w1*23/24;

        int r=w1/36;

        memDC.SetPen(wxPen(wxColor(20,20,20)));
        memDC.DrawLine(x2,y2+h2/2,x2+w2,y2+h2/2);
        memDC.DrawLine(x2+w2/2,y2,x2+w2/2,y2+h2);
        //dc.SetPen(wxPen(wxColor(0,0,0)));
        memDC.SetBrush(wxBrush(wxColor(27,61,88)));
        memDC.DrawCircle(cx1,cy1,r);
        memDC.DrawCircle(cx1,cy2,r);
        memDC.DrawCircle(cx1,cy3,r);
        memDC.DrawCircle(cx2,cy1,r);
        memDC.DrawCircle(cx2,cy3,r);
        memDC.DrawCircle(cx3,cy1,r);
        memDC.DrawCircle(cx3,cy2,r);
        memDC.DrawCircle(cx3,cy3,r);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ReviewDlg::OnPaintOp(wxPaintEvent& event)
{
    wxPaintDC dc(panelOp);
    int w,h;
    panelOp->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(-1,-1,w+2,h+2);
        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.DrawLine(0,0,w,0);
        memDC.DrawLine(w-1,0,w-1,h);
        memDC.DrawLine(0,h-1,w,h-1);

        wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont EngFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(normalFont);
        memDC.SetTextForeground(wxColor(68,68,68));
        //dc.DrawLabel(wxString::Format(_("通讯连接")),wxRect(50,25,0,0),wxALIGN_LEFT|wxALIGN_TOP);
        memDC.SetPen(wxPen(wxColor(189,189,189)));

        memDC.DrawLabel(_("系统操作"),wxRect(45,35,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(35,55,575,55);

        int x1 = 35;
        int y1 = 55;
        int w1 = 540;
        int h1 = 320;

        //memDC.DrawLabel(_("测量后视"),wxRect(x1+10,y1+15,80,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLine(x1,y1+15,x1+10,y1+15);
        memDC.DrawLine(x1,y1+15,x1+w1,y1+15);
        memDC.DrawLine(x1,y1+15,x1,y1+180);
        memDC.DrawLine(x1+w1-1,y1+15,x1+w1-1,y1+180);
        memDC.DrawLine(x1,y1+180,x1+w1,y1+180);
        memDC.SetBrush(wxBrush(wxColor(208,208,208)));
        memDC.DrawRectangle(x1+20,y1+30,w1-140,30);
        memDC.DrawLabel(_("分项"),wxRect(x1+20,y1+45,80,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("X"),wxRect(x1+100,y1+45,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("Y"),wxRect(x1+200,y1+45,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("Z"),wxRect(x1+300,y1+45,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //wxString name(bask.name,wxConvUTF8);
        station[0] = mtg->stns[mtg->nstn-1].statx;
        station[1] = mtg->stns[mtg->nstn-1].staty;
        station[2] = mtg->stns[mtg->nstn-1].statz;
        memDC.DrawLabel(_("测站"),wxRect(x1+20,y1+75,80,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%.4f"),station[0]),wxRect(x1+100,y1+75,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%.4f"),station[1]),wxRect(x1+200,y1+75,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%.4f"),station[2]),wxRect(x1+300,y1+75,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("后视"),wxRect(x1+20,y1+105,80,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("较差"),wxRect(x1+20,y1+135,80,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        if(m_bCheckBack)
        {
            memDC.DrawLabel(wxString::Format(_("%.4f"),back[0]),wxRect(x1+100,y1+105,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%.4f"),back[1]),wxRect(x1+200,y1+105,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%.4f"),back[2]),wxRect(x1+300,y1+105,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


            memDC.SetTextForeground(wxColor(248,148,88));
            memDC.DrawLabel(wxString::Format(_("%.4f"),back[0]-mtg->stns[mtg->nstn-1].backx),wxRect(x1+100,y1+135,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%.4f"),back[1]-mtg->stns[mtg->nstn-1].backy),wxRect(x1+200,y1+135,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%.4f"),back[2]-mtg->stns[mtg->nstn-1].backz),wxRect(x1+300,y1+135,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(wxColor(68,68,68));
            memDC.DrawLabel(_("---"),wxRect(x1+100,y1+105,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("---"),wxRect(x1+200,y1+105,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("---"),wxRect(x1+300,y1+105,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


            memDC.SetTextForeground(wxColor(255,20,255));
            memDC.DrawLabel(_("---"),wxRect(x1+100,y1+135,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("---"),wxRect(x1+200,y1+135,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("---"),wxRect(x1+300,y1+135,100,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        memDC.SetPen(wxPen(wxColor(189,189,189)));
        memDC.DrawLine(x1+20,y1+90,x1+20+w1-140,y1+90);
        memDC.DrawLine(x1+20,y1+120,x1+20+w1-140,y1+120);
        memDC.DrawLine(x1+20,y1+150,x1+20+w1-140,y1+150);

        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        memDC.SetPen(wxPen(wxColor(189,189,189)));
        if(isop == 0)
        {
            memDC.SetPen(wxPen(wxColor(122,176,232)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(189,189,189)));
        }
        memDC.DrawRectangle(x1+445,y1+30,70,30);
        if(isop == 1)
        {
            memDC.SetPen(wxPen(wxColor(122,176,232)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(189,189,189)));
        }
        memDC.DrawRectangle(x1+445,y1+75,70,30);
        memDC.SetTextForeground(wxColor(68,68,68));
        memDC.DrawLabel(_("测量"),wxRect(x1+445,y1+30,70,30),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("复位"),wxRect(x1+445,y1+75,70,30),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(189,189,189)));
        x1 = 35;
        y1 = y1+200;
        w1 = 540;
        h1 = 180;

        //memDC.DrawLabel(_("全站仪动作"),wxRect(x1+10,y1+15,80,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLine(x1,y1+15,x1+w1,y1+15);
        //memDC.DrawLine(x1+15+80,y1+15,x1+w1,y1+15);
        //memDC.DrawLine(x1,y1+15,x1,y1+180);
        //memDC.DrawLine(x1+w1-1,y1+15,x1+w1-1,y1+180);
        //memDC.DrawLine(x1,y1+180,x1+w1,y1+180);
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.SetPen(wxPen(wxColor(168,168,168)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        //DrawTCA(&memDC,rect1,0.5239);

        /*memDC.SetBrush(wxBrush(wxColor(208,208,208)));
        memDC.DrawRectangle(x1+20,y1+20,120,30);
        memDC.SetBrush(wxBrush(wxColor(245,246,247)));
        memDC.DrawRectangle(x1+20,y1+49,120,95);
        memDC.DrawLabel(_("动作选择"),wxRect(x1+20,y1+35,120,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        if(isop==2)
        {
            memDC.SetBrush(wxBrush(wxColor(228,240,252)));
            memDC.SetPen(wxPen(wxColor(228,240,252)));
            memDC.DrawRectangle(x1+19,y1+53,118,24);
        }
        memDC.DrawLabel(_("转向后视"),wxRect(x1+40,y1+65,80,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        if(isop==3)
        {
            memDC.SetBrush(wxBrush(wxColor(228,240,252)));
            memDC.SetPen(wxPen(wxColor(228,240,252)));
            memDC.DrawRectangle(x1+19,y1+78,118,24);
        }
        memDC.DrawLabel(_("转向激光靶"),wxRect(x1+40,y1+90,80,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        if(isop==4)
        {
            memDC.SetBrush(wxBrush(wxColor(228,240,252)));
            memDC.SetPen(wxPen(wxColor(228,240,252)));
            memDC.DrawRectangle(x1+19,y1+103,118,24);
        }
        memDC.DrawLabel(_("打开激光"),wxRect(x1+40,y1+115,80,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);*/

        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        memDC.SetPen(wxPen(wxColor(255,68,255)));
        tps_x = x1+w1/2;
        tps_y = y1+h1/2;
        memDC.DrawCircle(tps_x,tps_y,40);
        memDC.DrawLabel(_("测站"),wxRect(tps_x,tps_y+55,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        double tx,ty;
        double bx,by;
        prism[0] = mtg->m1.prism[0];
        prism[1] = mtg->m1.prism[1];
        prism[2] = mtg->m1.prism[2];
        bx = mtg->stns[mtg->nstn-1].backx;
        by = mtg->stns[mtg->nstn-1].backy;

        double ang1 = atan2(station[1]-by,station[0]-bx);
        if(ang1<0.0) ang1 = ang1+2.0*PI;

        double ang2 = atan2(prism[1]-station[1],prism[0]-station[0]);
        if(ang2<0.0) ang2 = ang2+2.0*PI;
        ang2 = ang2-ang1;

        int lh,lw;
        lw = 200;
        psm_x = tps_x-lw;
        psm_y = tps_y;
        //lh = 0;
        if(isop == 2)
        {
            memDC.SetPen(wxPen(wxColor(20,255,116)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(20,68,116)));
        }
        memDC.DrawCircle(psm_x,psm_y,15);
        memDC.DrawLabel(_("后视"),wxRect(psm_x,psm_y+30,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(psm_x-10,psm_y-10,psm_x+10,psm_y+10);
        memDC.DrawLine(psm_x-10,psm_y+10,psm_x+10,psm_y-10);
        lh = lw*tan(ang2);
        tar_x = tps_x+lw;
        tar_y = tps_y;
        if(isop == 4)
        {
            memDC.SetPen(wxPen(wxColor(20,255,116)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(20,68,116)));
        }
        memDC.DrawRectangle(tar_x-15,tar_y-15,30,30);
        memDC.DrawLabel(_("激光靶"),wxRect(tar_x,tar_y+30,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(tar_x-10,tar_y-10,tar_x+10,tar_y+10);
        memDC.DrawLine(tar_x-10,tar_y-2,tar_x+2,tar_y+10);
        memDC.DrawLine(tar_x-2,tar_y-10,tar_x+10,tar_y+2);
        if(isop == 3)
        {
            memDC.SetPen(wxPen(wxColor(20,255,116)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(20,68,116)));
        }
        memDC.DrawRectangle(tps_x-15,tps_y-15,30,30);
        //if(bmpTps.IsOk()) memDC.DrawBitmap(bmpTps,x1+240,y1+10);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ReviewDlg::OnPaintLevel(wxPaintEvent& event)
{
    wxPaintDC dc(panelLevel);
    int w,h;
    panelLevel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(-1,-1,w+2,h+2);
        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.DrawLine(0,0,w,0);
        memDC.DrawLine(w-1,0,w-1,h);
        memDC.DrawLine(0,h-1,w,h-1);

        wxFont chs(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont EngFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(68,68,68));
        //dc.DrawLabel(wxString::Format(_("通讯连接")),wxRect(50,25,0,0),wxALIGN_LEFT|wxALIGN_TOP);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ReviewDlg::OnPaintPlc(wxPaintEvent& event)
{
    wxPaintDC dc(panelPlc);
    int w,h;
    panelPlc->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(-1,-1,w+2,h+2);
        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.DrawLine(0,0,w,0);
        memDC.DrawLine(w-1,0,w-1,h);
        memDC.DrawLine(0,h-1,w,h-1);

        wxFont chs(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont EngFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(68,68,68));
        //dc.DrawLabel(wxString::Format(_("通讯连接")),wxRect(50,25,0,0),wxALIGN_LEFT|wxALIGN_TOP);
        memDC.SetPen(wxPen(wxColor(189,189,189)));

        int x1 = 35;
        int y1 = 35;
        memDC.DrawLabel(_("PLC通讯"),wxRect(x1+10,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        //dc.DrawCircle(180,35,8);
        if(mtg->itbm==1)
        {
            memDC.SetTextForeground(wxColor(20,255,20));
            memDC.DrawLabel(_("√"),wxRect(x1+75,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,20,20));
            memDC.DrawLabel(_("×"),wxRect(x1+75,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        memDC.SetTextForeground(wxColor(68,68,68));
        memDC.SetPen(wxPen(wxColor(168,168,168)));
        memDC.DrawLine(x1,y1+20,x1+540,y1+20);

        memDC.DrawLabel(_("掘进状态:"),wxRect(x1+10,y1+50,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        if(read_plc_start_val==1)
        {
            memDC.DrawLabel(_("掘进"),wxRect(x1+100,y1+50,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("停止"),wxRect(x1+100,y1+50,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        memDC.DrawLabel(_("拼装状态:"),wxRect(x1+10,y1+80,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        if(read_plc_mode_val==1)
        {
            memDC.DrawLabel(_("拼装"),wxRect(x1+100,y1+80,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("---"),wxRect(x1+100,y1+80,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        memDC.DrawLabel(_("A组油缸行程:  ")+wxString::Format(_("%.1f"),mtg->plc.raj*1000.0),wxRect(x1+10,y1+110,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("B组油缸行程:  ")+wxString::Format(_("%.1f"),mtg->plc.daj*1000.0),wxRect(x1+10,y1+140,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("C组油缸行程:  ")+wxString::Format(_("%.1f"),mtg->plc.laj*1000.0),wxRect(x1+10,y1+170,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("D组油缸行程:  ")+wxString::Format(_("%.1f"),mtg->plc.uaj*1000.0),wxRect(x1+10,y1+200,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLabel(_("盾尾铰接油缸右:  ")+wxString::Format(_("%.1f"),mtg->plc.rbaj*1000.0),wxRect(x1+10,y1+230,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("盾尾铰接油缸下:  ")+wxString::Format(_("%.1f"),mtg->plc.dbaj*1000.0),wxRect(x1+10,y1+260,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("盾尾铰接油缸左:  ")+wxString::Format(_("%.1f"),mtg->plc.lbaj*1000.0),wxRect(x1+10,y1+290,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("盾尾铰接油缸上:  ")+wxString::Format(_("%.1f"),mtg->plc.ubaj*1000.0),wxRect(x1+10,y1+320,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ReviewDlg::OnPaintBtnArea(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnArea);
    int w,h;
    panelBtnArea->GetClientSize(&w,&h);
    ///background
    int *maxPixels,*minPixels;
    maxPixels=(int*)malloc(3*sizeof(int));
    memset(maxPixels,0,3);

    minPixels=(int*)malloc(3*sizeof(int));
    memset(minPixels,0,3);

    wxRect rect(0,0,w,h);

    maxPixels[0]=227;
    maxPixels[1]=227;
    maxPixels[2]=227;

    minPixels[0]=209;
    minPixels[1]=209;
    minPixels[2]=209;

    PaintGradual(panelBtnArea, rect, maxPixels,minPixels,0);

    free(maxPixels);
    free(minPixels);

    dc.SetPen(wxPen(wxColor(248,248,248)));
    dc.DrawLine(0,0,w,0);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetFont(normalFont);
    dc.SetTextForeground(msg_cor);
    dc.DrawLabel(msg_str,wxRect(230,30,0,15),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
}

void ReviewDlg::PaintGradual(wxPanel* panel, wxRect rect, int *maxColorValue,int *minColorValue,int paintStyle)
{
    if(rect.width==0||rect.height==0)
    {
        return;
    }
    else
    {
        wxPaintDC dc(panel);
        int w,h;
        panel->GetClientSize(&w,&h);

        int maxr,maxg,maxb;
        int minr,ming,minb;
        double stepr,stepg,stepb;
        //int signr,signg,signb;

        maxr=maxColorValue[0];
        maxg=maxColorValue[1];
        maxb=maxColorValue[2];

        minr=minColorValue[0];
        ming=minColorValue[1];
        minb=minColorValue[2];

        int x0=rect.x,y0=rect.y;
        int x1=x0+rect.width,y1=y0+rect.height;

        int wb=rect.width;
        int hb=rect.height;


        //btnStartState=3;
        switch(paintStyle)
        {
        case 0:
            if(maxr-minr==0)
            {
                stepr=0.0;

            }
            else
            {
                stepr=(double)(maxr-minr);
                stepr=stepr/hb;
                //wxMessageBox(wxString::Format(_("%f"),stepr));
                //stepr=(double)((maxr-minr)/hb);
            }
            if(maxg-ming==0)
            {
                stepg=0.0;
            }
            else
            {
                stepg=(double)(maxg-ming);
                stepg=stepg/hb;
            }
            if(maxb-minb==0)
            {
                stepb=0.0;
            }
            else
            {
                stepb=(double)(maxb-minb);
                stepb=stepb/hb;
            }
            for(int i=0;i<hb;i++)
            {
                dc.SetPen(wxPen(wxColor(maxr,maxg,maxb)));
                dc.DrawLine(x0,y0+i,x1,y0+i);

                if(abs(stepr)>1)
                {
                    if(maxr-stepr<255&&maxr-stepr>0)
                    {
                        maxr-=stepr;
                    }
                }
                else
                {
                    if(maxr-stepr*i<255&&maxr-stepr*i>0)
                    {
                        maxr=maxColorValue[0]-(int)(stepr*(i+1));
                    }
                }

                if(abs(stepg)>1)
                {
                    if(maxg-stepg<255&&maxg-stepg>0)
                    {
                        maxg-=stepg;
                    }
                }
                else
                {
                    if(maxg-stepg*i<255&&maxg-stepg*i>0)
                    {
                        maxg=maxColorValue[1]-(int)(stepg*(i+1));
                    }
                }

                if(abs(stepb)>1)
                {
                    if(maxb-stepb<255&&maxb-stepb>0)
                    {
                        maxb-=stepb;
                    }
                }
                else
                {
                    if(maxb-stepb*i<255&&maxb-stepb*i>0)
                    {
                        maxb=maxColorValue[2]-(int)(stepb*(i+1));
                    }
                }
            }
            //dc.DrawLabel(name,wxRect(x0,y0,wb,hb),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
            break;
        case 1:
            if(maxr-minr==0)
            {
                stepr=0;
            }
            else
            {
                stepr=(maxr-minr)*2/hb;
            }

            if(maxg-ming==0)
            {
                stepg=0;
            }
            else
            {
                stepg=(maxg-ming)*2/hb;
            }

            if(maxb-minb==0)
            {
                stepb=0;
            }
            else
            {
                stepb=(maxb-minb)*2/hb;
            }

            for(int i=0;i<hb/2;i++)
            {
                dc.SetPen(wxPen(wxColor(maxr,maxg,maxb)));
                dc.DrawLine(x0,y0+i,x1,y0+i);
                if(abs(stepr)>1)
                {
                    if(maxr-stepr<255&&maxr-stepr>0)
                    {
                        maxr-=stepr;
                    }
                }
                else
                {
                    if(maxr-stepr*i<255&&maxr-stepr*i>0)
                    {
                        maxr=maxColorValue[0]-(int)(stepr*(i+1));
                    }
                }

                if(abs(stepg)>1)
                {
                    if(maxg-stepg<255&&maxg-stepg>0)
                    {
                        maxg-=stepg;
                    }
                }
                else
                {
                    if(maxg-stepg*i<255&&maxg-stepg*i>0)
                    {
                        maxg=maxColorValue[1]-(int)(stepg*(i+1));
                    }
                }

                if(abs(stepb)>1)
                {
                    if(maxb-stepb<255&&maxb-stepb>0)
                    {
                        maxb-=stepb;
                    }
                }
                else
                {
                    if(maxb-stepb*i<255&&maxb-stepb*i>0)
                    {
                        maxb=maxColorValue[2]-(int)(stepb*(i+1));
                    }
                }
            }

            maxColorValue[0]=maxr;
            maxColorValue[1]=maxg;
            maxColorValue[2]=maxb;
            for(int i=hb/2;i<hb;i++)
            {
                dc.SetPen(wxPen(wxColor(maxr,maxg,maxb)));
                dc.DrawLine(x0,y0+i,x1,y0+i);
                if(abs(stepr)>1)
                {
                    if(maxr-stepr<255&&maxr-stepr>0)
                    {
                        maxr+=stepr;
                    }
                }
                else
                {
                    if(maxr-stepr*i<255&&maxr-stepr*i>0)
                    {
                        maxr=maxColorValue[0]+stepr*(i-hb/2);
                    }
                }

                if(abs(stepg)>1)
                {
                    if(maxg-stepg<255&&maxg-stepg>0)
                    {
                        maxg+=stepg;
                    }
                }
                else
                {
                    if(maxg-stepg*i<255&&maxg-stepg*i>0)
                    {
                        maxg=maxColorValue[1]+stepg*(i-hb/2);
                    }
                }

                if(abs(stepb)>1)
                {
                    if(maxb-stepb<255&&maxb-stepb>0)
                    {
                        maxb+=stepb;
                    }
                }
                else
                {
                    if(maxb-stepb*i<255&&maxb-stepb*i>0)
                    {
                        maxb=maxColorValue[2]+stepb*(i-hb/2);
                    }
                }
            }
            break;
        default:
            break;
        }
    }
}



