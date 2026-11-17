///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SegmentDlg.h"
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
	//(*InternalHeadersPCH(SegmentDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(SegmentDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(SegmentDlg)


const long SegmentDlg::ID_PANEL1 = wxNewId();                  //标题
const long SegmentDlg::ID_PANEL2 = wxNewId();                  //按钮
//const long SegmentDlg::ID_BUTTON1 = wxNewId();                 //取消
//const long SegmentDlg::ID_BUTTON2 = wxNewId();                 //应用
//*)

SegmentDlg::SegmentDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelTitle = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelTitle->IsMaximinize=0;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("管环选型");
    panelButtonList = new MDButtonList(this, ID_PANEL2, wxPoint(0,31), wxSize(150,h-76), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(150,31), wxSize(w-150,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelNavi = new wxPanel(panelMain, wxID_ANY, wxPoint(600+w,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    int x1,y1,w1,h1;
    x1=0;
    y1=11;
    w1=w-150;
    h1=h-88;
    panelSeg1 = new wxPanel(panelMain, wxID_ANY, wxPoint(x1+1024,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSeg1->SetBackgroundColour(wxColor(239,239,239));

    int x2,y2,w2,h2;
    x2=9;
    y2=17;
    w2=w1-18;
    h2=h1-17;
    panelFigSeg1 = new wxPanel(panelSeg1, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2-17), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelFigSeg1->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelSeging = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSeging->SetBackgroundColour(wxColor(239,239,239));
    x2=9;
    y2=17;
    w2=w1-18;
    h2=h1-17;
    panelFigSeging = new wxPanel(panelSeging, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2-17), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelFigSeging->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    seg_dh_Text = new wxMyTextCtrl(panelFigSeging, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    tbm_laj_Text = new wxMyTextCtrl(panelFigSeging, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    tbm_raj_Text = new wxMyTextCtrl(panelFigSeging, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    tbm_uaj_Text = new wxMyTextCtrl(panelFigSeging, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    tbm_daj_Text = new wxMyTextCtrl(panelFigSeging, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    tbm_lgap_Text = new wxMyTextCtrl(panelFigSeging, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    tbm_rgap_Text = new wxMyTextCtrl(panelFigSeging, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    tbm_ugap_Text = new wxMyTextCtrl(panelFigSeging, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    tbm_dgap_Text = new wxMyTextCtrl(panelFigSeging, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    x2=9;
    y2=17;
    w2=w1-18;
    h2=h1-17;
    panelSegings = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSegings->SetBackgroundColour(wxColor(239,239,239));
    panelSegingsList = new wxPanel(panelSegings, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2-y2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSegingsList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    gridSegings = new wxMyGrid( panelSegingsList, wxID_ANY, wxPoint(1,41), wxSize(w2-2,h2-y2-42), 0 );

    x2=9;
    y2=17;
    w2=w1-18;
    h2=h1-17;
    panelSeg = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSeg->SetBackgroundColour(wxColor(239,239,239));
    panelFigSeg = new wxPanel(panelSeg, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2-17), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelFigSeg->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    seg_mile_Text = new wxMyTextCtrl(panelFigSeg, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    x2=9;
    y2=17;
    w2=w1-18;
    h2=h1-17;
    panelSegs = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSegs->SetBackgroundColour(wxColor(239,239,239));
    panelSegsList = new wxPanel(panelSegs, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2-y2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSegsList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    gridSegs = new wxMyGrid( panelSegsList, wxID_ANY, wxPoint(1,41), wxSize(w2-2,h2-y2-42), 0 );

    x2=9;
    y2=17;
    w2=w1-18;
    h2=h1-17;
    panelSeged = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSeged->SetBackgroundColour(wxColor(239,239,239));
    panelSegedList = new wxPanel(panelSeged, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2-y2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSegedList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    gridSeged = new wxMyGrid( panelSegedList, wxID_ANY, wxPoint(1,41), wxSize(w2-2,h2-y2-42), 0 );

    panelDemo = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelDemo->SetBackgroundColour(wxColor(239,239,239));
    x2=9;
    y2=17;
    w2=w1-18;
    h2=h1-17;
    panelFigDemo = new wxPanel(panelDemo, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2-17), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelFigDemo->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    demo_dh_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    demo_laj_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    demo_raj_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    demo_uaj_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    demo_daj_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    demo_lgap_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    demo_rgap_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    demo_ugap_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    demo_dgap_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    demo_headh_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    demo_headv_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    demo_tailh_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    demo_tailv_Text = new wxMyTextCtrl(panelFigDemo, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    x2=9;
    y2=17;
    w2=w1-18;
    h2=h1-17;
    panelDemoSegs = new wxPanel(panelMain, wxID_ANY, wxPoint(x1+1024,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelDemoSegs->SetBackgroundColour(wxColor(239,239,239));
    panelDemoList = new wxPanel(panelDemoSegs, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2-y2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelDemoList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    gridDemo = new wxMyGrid( panelDemoList, wxID_ANY, wxPoint(1,41), wxSize(w2-2,h2-y2-42), 0 );

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelNavi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintBackground,0,this);
	panelNavi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintNavi,0,this);


    panelFigSeg1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintFigSeg1,0,this);
    panelFigSeg1->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentDlg::OnMotionSeg1,0,this);
    panelFigSeg1->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentDlg::OnLeaveSeg1,0,this);
    panelFigSeg1->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnClickSeg1,0,this);

    panelFigSeging->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintSeging,0,this);
    panelFigSeging->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentDlg::OnMotionSeging,0,this);
    panelFigSeging->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentDlg::OnLeaveSeging,0,this);
    panelFigSeging->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnClickSeging,0,this);

    tbm_laj_Text->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SegmentDlg::LeftajChanged,0,this);
    tbm_uaj_Text->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SegmentDlg::UpajChanged,0,this);
    tbm_raj_Text->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SegmentDlg::RightajChanged,0,this);
    tbm_daj_Text->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SegmentDlg::DownajChanged,0,this);

    tbm_lgap_Text->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SegmentDlg::LeftGapChanged,0,this);
    tbm_ugap_Text->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SegmentDlg::UpGapChanged,0,this);
    tbm_rgap_Text->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SegmentDlg::RightGapChanged,0,this);
    tbm_dgap_Text->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SegmentDlg::DownGapChanged,0,this);
    panelSegingsList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintSegingsListTitle,0,this);

    panelFigSeg->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintFigSeg,0,this);
    panelFigSeg->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentDlg::OnMotionSeg,0,this);
    panelFigSeg->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentDlg::OnLeaveSeg,0,this);
    panelFigSeg->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnClickSeg,0,this);
    panelSegsList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintSegsListTitle,0,this);

    panelSegedList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintFigSeged,0,this);

    panelFigDemo->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintDemo,0,this);
    panelFigDemo->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentDlg::OnMotionDemo,0,this);
    panelFigDemo->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentDlg::OnLeaveDemo,0,this);
    panelFigDemo->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnClickDemo,0,this);

    panelDemoList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintDemoList,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnClickBottom,0,this);

    panelButtonList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnButtonClick,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    panelButtonList->btn_height=27;
    panelButtonList->AddButton(_("历史拼装"));
    //panelButtonList->AddButton(_("上环设置"));
    panelButtonList->AddButton(_("管环预测"));
    panelButtonList->AddButton(_("预测列表"));
    panelButtonList->AddButton(_("设计排版"));
    panelButtonList->AddButton(_("排版列表"));
    panelButtonList->AddButton(_("排版演示"));
    panelButtonList->AddButton(_("演示列表"));
    panelButtonList->btn_clicked=0;

    checkBoxWidth=14;
    checkBoxHeight=14;
    radioBoxR1=7;
    radioBoxR2=4;

    Mtype=0;
    Msg=wxEmptyString;
    int nk = cli->segset.Ks;

    int i=0;
    gridSegings->CreateGrid( 1, 8 );
    gridSegings->EnableEditing( false );
	gridSegings->EnableGridLines( true );
	gridSegings->EnableDragGridSize( false );
	gridSegings->SetMargins( 0, 0 );

	// Columns
	gridSegings->EnableDragColMove( false );
	gridSegings->EnableDragColSize( true );
	gridSegings->SetColLabelSize( 0 );
	gridSegings->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Rows
	gridSegings->EnableDragRowSize( true );
	gridSegings->SetRowLabelSize( 0 );
	gridSegings->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	//Cell Defaults
	gridSegings->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

    i=0;
    gridSegings->SetColLabelValue( i, _("管片号") );
	gridSegings->SetColSize(i++,55);
	gridSegings->SetColLabelValue( i, _("类型") );
	gridSegings->SetColSize(i++,65);
	gridSegings->SetColLabelValue( i, _("里程") );
	gridSegings->SetColSize(i++,85);
	gridSegings->SetColLabelValue( i, _("拼装点位") );
	gridSegings->SetColSize(i++,65);
	gridSegings->MergeColum(_("偏差(mm)"),i,i+1);
	gridSegings->SetColLabelValue( i, _("水平") );
	gridSegings->SetColSize(i++,75);
	gridSegings->SetColLabelValue( i, _("垂直") );
	gridSegings->SetColSize(i++,75);
	gridSegings->MergeColum(_("超前量(mm)"),i,i+1);
	gridSegings->SetColLabelValue( i, _("水平") );
	gridSegings->SetColSize(i++,75);
	gridSegings->SetColLabelValue( i, _("垂直") );
	gridSegings->SetColSize(i++,75);

    gridSegs->CreateGrid( 1, 8 );
    gridSegs->EnableEditing( false );
	gridSegs->EnableGridLines( true );
	gridSegs->EnableDragGridSize( false );
	gridSegs->SetMargins( 0, 0 );

	// Columns
	gridSegs->EnableDragColMove( false );
	gridSegs->EnableDragColSize( true );
	gridSegs->SetColLabelSize( 0 );
	gridSegs->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Rows
	gridSegs->EnableDragRowSize( true );
	gridSegs->SetRowLabelSize( 0 );
	gridSegings->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	//Cell Defaults
	gridSegs->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
    i=0;
    gridSegs->SetColLabelValue( i, _("管片号") );
	gridSegs->SetColSize(i++,55);
	gridSegs->SetColLabelValue( i, _("类型") );
	gridSegs->SetColSize(i++,65);
	gridSegs->SetColLabelValue( i, _("里程") );
	gridSegs->SetColSize(i++,85);
	gridSegs->SetColLabelValue( i, _("拼装点位") );
	gridSegs->SetColSize(i++,65);
	gridSegs->MergeColum(_("偏差(mm)"),i,i+1);
	gridSegs->SetColLabelValue( i, _("水平") );
	gridSegs->SetColSize(i++,75);
	gridSegs->SetColLabelValue( i, _("垂直") );
	gridSegs->SetColSize(i++,75);
	gridSegs->MergeColum(_("超前量(mm)"),i,i+1);
	gridSegs->SetColLabelValue( i, _("水平") );
	gridSegs->SetColSize(i++,75);
	gridSegs->SetColLabelValue( i, _("垂直") );
	gridSegs->SetColSize(i++,75);

    gridSeged->CreateGrid( 1, 8 );
    gridSeged->EnableEditing( false );
	gridSeged->EnableGridLines( true );
	gridSeged->EnableDragGridSize( false );
	gridSeged->SetMargins( 0, 0 );

	// Columns
	gridSeged->EnableDragColMove( false );
	gridSeged->EnableDragColSize( true );
	gridSeged->SetColLabelSize( 0 );
	gridSeged->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Rows
	gridSeged->EnableDragRowSize( true );
	gridSeged->SetRowLabelSize( 0 );
	gridSeged->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	//Cell Defaults
	gridSeged->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

    i=0;
    gridSeged->SetColLabelValue( i, _("管片号") );
	gridSeged->SetColSize(i++,55);
	gridSeged->SetColLabelValue( i, _("类型") );
	gridSeged->SetColSize(i++,65);
	gridSeged->SetColLabelValue( i, _("里程") );
	gridSeged->SetColSize(i++,85);
	gridSeged->SetColLabelValue( i, _("拼装点位") );
	gridSeged->SetColSize(i++,65);
	gridSeged->MergeColum(_("偏差(mm)"),i,i+1);
	gridSeged->SetColLabelValue( i, _("水平") );
	gridSeged->SetColSize(i++,75);
	gridSeged->SetColLabelValue( i, _("垂直") );
	gridSeged->SetColSize(i++,75);
	gridSeged->MergeColum(_("超前量(mm)"),i,i+1);
	gridSeged->SetColLabelValue( i, _("水平") );
	gridSeged->SetColSize(i++,75);
	gridSeged->SetColLabelValue( i, _("垂直") );
	gridSeged->SetColSize(i++,75);

    gridDemo->CreateGrid( 1, 8 );
    gridDemo->EnableEditing( false );
	gridDemo->EnableGridLines( true );
	gridDemo->EnableDragGridSize( false );
	gridDemo->SetMargins( 0, 0 );

	// Columns
	gridDemo->EnableDragColMove( false );
	gridDemo->EnableDragColSize( true );
	gridDemo->SetColLabelSize( 0 );
	gridDemo->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Rows
	gridDemo->EnableDragRowSize( true );
	gridDemo->SetRowLabelSize( 0 );
	gridSegings->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	//Cell Defaults
	gridDemo->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
    i=0;
    gridDemo->SetColLabelValue( i, _("管片号") );
	gridDemo->SetColSize(i++,55);
	gridDemo->SetColLabelValue( i, _("类型") );
	gridDemo->SetColSize(i++,65);
	gridDemo->SetColLabelValue( i, _("里程") );
	gridDemo->SetColSize(i++,85);
	gridDemo->SetColLabelValue( i, _("拼装点位") );
	gridDemo->SetColSize(i++,65);
	gridDemo->MergeColum(_("偏差(mm)"),i,i+1);
	gridDemo->SetColLabelValue( i, _("水平") );
	gridDemo->SetColSize(i++,75);
	gridDemo->SetColLabelValue( i, _("垂直") );
	gridDemo->SetColSize(i++,75);
	gridDemo->MergeColum(_("超前量(mm)"),i,i+1);
	gridDemo->SetColLabelValue( i, _("水平") );
	gridDemo->SetColSize(i++,75);
	gridDemo->SetColLabelValue( i, _("垂直") );
	gridDemo->SetColSize(i++,75);

    cli->segs[4].uds=0.05;

    LoadData();
}

SegmentDlg::~SegmentDlg()
{

}

void SegmentDlg::LeftajChanged(wxCommandEvent& event)
{
    double laj;
    tbm_laj_Text->GetValue().ToDouble(&laj);
    segings[4].laj=laj/1000.0;
    if(fabs(segings[4].laj-segings[4].raj)<0.2)
    {
        //mtg_seg_gesture(cli,&segings[4],&segings[5]);
    }
    else
    {
        return;
    }
    panelFigSeging->Refresh();
}

void SegmentDlg::UpajChanged(wxCommandEvent& event)
{
    double uaj;
    tbm_uaj_Text->GetValue().ToDouble(&uaj);
    segings[4].uaj=uaj/1000.0;
    if(fabs(segings[4].daj-segings[4].uaj)<0.2)
    {
        //mtg_seg_gesture(cli,&segings[4],&segings[5]);
    }
    else
    {
        return;
    }
    panelFigSeging->Refresh();
}

void SegmentDlg::RightajChanged(wxCommandEvent& event)
{
    double raj;
    tbm_raj_Text->GetValue().ToDouble(&raj);
    segings[4].raj=raj/1000.0;
    if(fabs(segings[4].laj-segings[4].raj)<0.2)
    {
        //mtg_seg_gesture(cli,&segings[4],&segings[5]);
    }
    else
    {
        return;
    }
    panelFigSeging->Refresh();
}

void SegmentDlg::DownajChanged(wxCommandEvent& event)
{
    double daj;
    tbm_daj_Text->GetValue().ToDouble(&daj);
    segings[4].daj=daj/1000.0;
    if(fabs(segings[4].daj-segings[4].uaj)<0.2)
    {
        //mtg_seg_gesture(cli,&segings[4],&segings[5]);
    }
    else
    {
        return;
    }
    panelFigSeging->Refresh();
}

void SegmentDlg::LeftGapChanged(wxCommandEvent& event)
{
    double gap;
    tbm_lgap_Text->GetValue().ToDouble(&gap);
    gap=gap/1000.0;
    if(gap>cli->segset.G0*2.0)
    {
        WriteMsg(_("左侧盾尾间隙输入错误，请检查"),1);
        return;
    }

    segings[4].lgap=gap;
    Msg=wxEmptyString;
    WriteMsg(Msg,0);
    //mtg_seg_gesture(cli,&segings[4],&segings[5]);
    panelFigSeging->Refresh();
}

void SegmentDlg::UpGapChanged(wxCommandEvent& event)
{
    double gap;
    tbm_ugap_Text->GetValue().ToDouble(&gap);
    gap=gap/1000.0;
    if(gap>cli->segset.G0*2.0)
    {
        WriteMsg(_("上侧盾尾间隙输入错误，请检查"),1);
        return;
    }
    Msg=wxEmptyString;
    WriteMsg(Msg,0);
    segings[4].ugap=gap;
    //mtg_seg_gesture(cli,&segings[4],&segings[5]);
    panelFigSeging->Refresh();
}

void SegmentDlg::RightGapChanged(wxCommandEvent& event)
{
    double gap;
    tbm_rgap_Text->GetValue().ToDouble(&gap);
    gap=gap/1000.0;
    if(gap>cli->segset.G0*2.0)
    {
        WriteMsg(_("右侧盾尾间隙输入错误，请检查"),1);
        return;
    }
    Msg=wxEmptyString;
    WriteMsg(Msg,0);
    segings[4].rgap=gap;
    //mtg_seg_gesture(cli,&segings[4],&segings[5]);
    panelFigSeging->Refresh();
}

void SegmentDlg::DownGapChanged(wxCommandEvent& event)
{
    double gap;
    tbm_dgap_Text->GetValue().ToDouble(&gap);
    gap=gap/1000.0;
    if(gap>cli->segset.G0*2.0)
    {
        WriteMsg(_("下侧盾尾间隙输入错误，请检查"),1);
        return;
    }
    Msg=wxEmptyString;
    WriteMsg(Msg,0);
    segings[4].dgap=gap;
    //mtg_seg_gesture(cli,&segings[4],&segings[5]);
    panelFigSeging->Refresh();
}

void SegmentDlg::OnButtonClick(wxMouseEvent& event)
{
    int btn = panelButtonList->btn_left_down;
    int w,h;
    panelSeg1->GetClientSize(&w,&h);
    switch(btn)
    {
    case 0:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelSeging->SetSize(1024,11,w,h);
        panelSeg1->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelSegings->SetSize(1024,11,w,h);
        panelSegs->SetSize(1024,11,w,h);
        panelDemo->SetSize(1024,11,w,h);
        panelDemoSegs->SetSize(1024,11,w,h);
        panelSeged->SetSize(0,11,w,h);
        break;
    case 1:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelSeg->SetSize(1024,11,w,h);
        panelSeg1->SetSize(1024,11,w,h);
        panelSeged->SetSize(1024,11,w,h);
        panelSegings->SetSize(1024,11,w,h);
        panelSegs->SetSize(1024,11,w,h);
        panelDemo->SetSize(1024,11,w,h);
        panelDemoSegs->SetSize(1024,11,w,h);
        panelSeging->SetSize(0,11,w,h);
        break;
    case 2:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelSeging->SetSize(1024,11,w,h);
        panelSeg1->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelSeged->SetSize(1024,11,w,h);
        panelSegs->SetSize(1024,11,w,h);
        panelDemo->SetSize(1024,11,w,h);
        panelDemoSegs->SetSize(1024,11,w,h);
        panelSegings->SetSize(0,11,w,h);
        break;
    case 3:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelSeging->SetSize(1024,11,w,h);
        panelSeg1->SetSize(1024,11,w,h);
        panelSegings->SetSize(1024,11,w,h);
        panelSeged->SetSize(1024,11,w,h);
        panelSegs->SetSize(1024,11,w,h);
        panelDemo->SetSize(1024,11,w,h);
        panelDemoSegs->SetSize(1024,11,w,h);
        panelSeg->SetSize(0,11,w,h);
        break;
    case 4:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelSeging->SetSize(1024,11,w,h);
        panelSeg1->SetSize(1024,11,w,h);
        panelSegings->SetSize(1024,11,w,h);
        panelSeged->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelDemo->SetSize(1024,11,w,h);
        panelDemoSegs->SetSize(1024,11,w,h);
        panelSegs->SetSize(0,11,w,h);
        break;
    case 5:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelSeging->SetSize(1024,11,w,h);
        panelSeg1->SetSize(1024,11,w,h);
        panelSegings->SetSize(1024,11,w,h);
        panelSeged->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelSegs->SetSize(1024,11,w,h);
        panelDemoSegs->SetSize(1024,11,w,h);
        panelDemo->SetSize(0,11,w,h);
        break;
    case 6:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelSeging->SetSize(1024,11,w,h);
        panelSeg1->SetSize(1024,11,w,h);
        panelSegings->SetSize(1024,11,w,h);
        panelSeged->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelSegs->SetSize(1024,11,w,h);
        panelDemo->SetSize(1024,11,w,h);
        panelDemoSegs->SetSize(0,11,w,h);
        break;
    default:
        break;
    }
    /*case 1:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelSeging->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelSeged->SetSize(1024,11,w,h);
        panelSegings->SetSize(1024,11,w,h);
        panelSegs->SetSize(1024,11,w,h);
        panelDemo->SetSize(1024,11,w,h);
        panelDemoSegs->SetSize(1024,11,w,h);
        panelSeg1->SetSize(0,11,w,h);
        break;*/
}

void SegmentDlg::OnPaintFigSeg1(wxPaintEvent& event)
{
    wxPaintDC dc(panelFigSeg1);
    int w,h;
    panelFigSeg1->GetClientSize(&w,&h);
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

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont num(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont mar(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("黑体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        double radius =(h-120)/2.0;
        double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;

        wxPen pen1=wxPen(wxColor(255,30,30));
        wxPen pen2=wxPen(wxColor(30,30,30));

        x1=w/2.0;
        y1=h/2.0;
        //wxMessageBox(wxString::Format(_("%d"),cli->nblk));
        if(cli->nblk>0)
        {
            double angle1 = PI*3/2-cli->blocks[0].angle/2.0;
            double angle2=PI*3/2-cli->blocks[0].angle/2.0;
            int k1=motion-ID_SEGMENT_COUNT;
            if(k1>=0) angle2 = angle2+2.0*PI*k1/cli->segset.Ks;
            if(segings[4].kpos<cli->segset.Ks)
            {
                angle1 = angle1+2.0*PI*segings[4].kpos/cli->segset.Ks;
            }
            for(int i=0;i<cli->nblk;i++)
            {
                x2=x1+radius*cos(angle1+0.02);
                y2=y1+radius*sin(angle1+0.02);
                x4=x1+(radius-25)*cos(angle1+0.02);
                y4=y1+(radius-25)*sin(angle1+0.02);
                angle1+=cli->blocks[i].angle;
                x3=x1+radius*cos(angle1-0.02);
                y3=y1+radius*sin(angle1-0.02);
                x5=x1+(radius-25)*cos(angle1-0.02);
                y5=y1+(radius-25)*sin(angle1-0.02);
                if(i==0)
                {
                    memDC.SetPen(pen1);
                }
                else
                {
                    memDC.SetPen(pen2);
                }
                memDC.DrawArc(x3,y3,x2,y2,x1,y1);
                memDC.DrawArc(x5,y5,x4,y4,x1,y1);
            }
            memDC.SetPen(wxPen(wxColor(255,255,255)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.DrawCircle(x1,y1,radius-27);
            memDC.SetPen(wxPen(wxColor(20,20,20),1,wxDOT_DASH));
            memDC.DrawLine(1,y1,w-1,y1);
            memDC.DrawLine(x1,1,x1,h-1);

            if((k1>0 && k1!=segings[4].kpos) || (k1==0 && cli->segset.Ks!=segings[4].kpos))
            {
                for(int i=0;i<cli->nblk;i++)
                {
                    x2=x1+(radius+10)*cos(angle2+0.02);
                    y2=y1+(radius+10)*sin(angle2+0.02);
                    x4=x1+(radius-35)*cos(angle2+0.02);
                    y4=y1+(radius-35)*sin(angle2+0.02);
                    angle2+=cli->blocks[i].angle;
                    x3=x1+(radius+10)*cos(angle2-0.02);
                    y3=y1+(radius+10)*sin(angle2-0.02);
                    x5=x1+(radius-35)*cos(angle2-0.02);
                    y5=y1+(radius-35)*sin(angle2-0.02);
                    if(i==0 || i==1)
                    {
                        memDC.SetPen(wxPen(wxColor(255,0,0),2,wxDOT_DASH));
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(0,0,255),2,wxDOT_DASH));
                    }
                    memDC.DrawLine(x2,y2,x4,y4);
                }
            }

            angle1=PI*2.0/cli->segset.Ks;
            x4=-1;
            x5=-1;
            for(int i=0;i<cli->segset.Ks;i++)
            {
                x2=x1+(radius-13)*cos(PI*3.0/2.0+angle1*i);
                y2=y1+(radius-13)*sin(PI*3.0/2.0+angle1*i);
                segButton[ID_SEGMENT_COUNT+i].x=x2;
                segButton[ID_SEGMENT_COUNT+i].y=y2;
                segButton[ID_SEGMENT_COUNT+i].width=12;
                segButton[ID_SEGMENT_COUNT+i].height=12;
                if(i==segings[4].kpos || (i==0 && segings[4].kpos==cli->segset.Ks))
                {
                    if(motion==ID_SEGMENT_COUNT+i)
                    {
                        memDC.SetPen(btnPen[1]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    else
                    {
                        memDC.SetPen(btnPen[0]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                    memDC.SetBrush(btnBrush[1]);
                }
                else
                {
                    if(motion==ID_SEGMENT_COUNT+i)
                    {
                        memDC.SetPen(btnPen[1]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    memDC.SetPen(btnPen[0]);
                    memDC.SetBrush(wxBrush(wxColor(0,0,0)));
                }

                memDC.DrawCircle(x2,y2,5);

                if(i==0)
                {
                    x3=x1+(radius-43)*cos(PI*3.0/2.0+angle1*i);
                    y3=y1+(radius-43)*sin(PI*3.0/2.0+angle1*i);
                }
                else if(i==k1)
                {
                    x5=x1+(radius-43)*cos(PI*3.0/2.0+angle1*i);
                    y5=y1+(radius-43)*sin(PI*3.0/2.0+angle1*i);
                }

                if(i==segings[4].kpos)
                {
                    x4=x1+(radius-43)*cos(PI*3.0/2.0+angle1*i);
                    y4=y1+(radius-43)*sin(PI*3.0/2.0+angle1*i);
                }
            }
            memDC.SetTextForeground(wxColor(255,0,0));
            memDC.SetFont(num);
            memDC.DrawLabel(wxString::Format(_("%d"),cli->segset.Ks),wxRect(x3,y3,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            if(x4>0) memDC.DrawLabel(wxString::Format(_("%d"),segings[4].kpos),wxRect(x4,y4,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            if(x5>0) memDC.DrawLabel(wxString::Format(_("%d"),k1),wxRect(x5,y5,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        x2=15;
        y2=25;
        memDC.SetFont(chs);
        memDC.SetTextForeground(btnTextColor[0]);
        memDC.DrawLabel(_("管环编号"),wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y2+=25;
        memDC.DrawLabel(_("是否选型"),wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x2+=85;
        y2=25;
        memDC.DrawLabel(wxString::Format(_("%d"),segings[4].numb),wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y2+=25;
        if(segings[4].t==0)
        {
            memDC.DrawLabel(_("否"),wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("是"),wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        int w1,h1;
        double s1;
        double a1,a2;
        double hx[4],hy[4],vx[4],vy[4];

        w1=w/2-radius-30;
        h1=w1/2;
        s1=h1/2.0/cli->segset.l2s;
        a1=segings[4].l2r/4.0;
        a2=segings[4].d2u/4.0;
        a1=a1*s1;
        a2=a2*s1;

        hx[0]=x1-w1/2;
        hy[0]=y1-h1/2;
        hx[1]=hx[0]+w1;
        hy[1]=hy[0];
        hx[2]=hx[1];
        hy[2]=hy[1]+h1;
        hx[3]=hx[0];
        hy[3]=hy[2];

        vx[0]=15+w1-h1/2;
        vy[0]=y1-w1/2;
        vx[1]=vx[0];
        vy[1]=vy[0]+w1;
        vx[2]=vx[1]-h1;
        vy[2]=vy[1];
        vx[3]=vx[2];
        vy[3]=vy[0];

        memDC.SetPen(wxPen(wxColor(168,168,168)));
        memDC.DrawLine(hx[0],hy[0]-a1,hx[1],hy[1]+a1);
        memDC.DrawLine(hx[1],hy[1]+a1,hx[2],hy[2]-a1);
        memDC.DrawLine(hx[2],hy[2]-a1,hx[3],hy[3]+a1);
        memDC.DrawLine(hx[3],hy[3]+a1,hx[0],hy[0]-a1);
        if(a1>0)
        {
            memDC.DrawLine(hx[1],hy[1]+a1,hx[0],hy[1]+a1);
            memDC.DrawLine(hx[2],hy[2]-a1,hx[3],hy[2]-a1);
        }
        else
        {
            memDC.DrawLine(hx[0],hy[0]-a1,hx[1],hy[0]-a1);
            memDC.DrawLine(hx[3],hy[3]+a1,hx[2],hy[3]+a1);
        }

        memDC.DrawLine(vx[0]-a2,vy[0],vx[1]+a2,vy[1]);
        memDC.DrawLine(vx[1]+a2,vy[1],vx[2]-a2,vy[2]);
        memDC.DrawLine(vx[2]-a2,vy[2],vx[3]+a2,vy[3]);
        memDC.DrawLine(vx[3]+a2,vy[3],vx[0]-a2,vy[0]);
        if(a2>0)
        {
            memDC.DrawLine(vx[0]-a2,vy[0],vx[0]-a2,vy[1]);
            memDC.DrawLine(vx[3]+a2,vy[2],vx[3]+a2,vy[3]);
        }
        else
        {
            memDC.DrawLine(vx[1]+a2,vy[0],vx[1]+a2,vy[1]);
            memDC.DrawLine(vx[2]-a2,vy[2],vx[2]-a2,vy[3]);
        }

        memDC.DrawLabel(_("水平"),wxRect(hx[0],hy[0],w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("垂直"),wxRect(vx[3],vy[3],h1,w1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        if(cli->nblk>0)
        {
            w1=60;
            h1=25;
            x2=x1-w1*3/2;
            y2=y1-radius/2-h1/2;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(btnBrush[0]);
            memDC.DrawRectangle(x2,y2,w1*3+1,h1);

            segButton[ID_SEGMENT_TYPE_TL].x=x2+1;
            segButton[ID_SEGMENT_TYPE_TL].y=y2+1;
            segButton[ID_SEGMENT_TYPE_TL].width=w1-1;
            segButton[ID_SEGMENT_TYPE_TL].height=h1-2;
            if(cli->segset.type==0)
            {
                memDC.SetTextForeground(wxColor(198,198,198));
            }
            else
            {
                if(segings[4].type==2)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_TL)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_TL)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_TL]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawLine(x2+w1,y2,x2+w1,y2+h1);
            memDC.DrawLabel(_("左转弯"),segButton[ID_SEGMENT_TYPE_TL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            x2=x2+w1;
            segButton[ID_SEGMENT_TYPE_STD].x=x2+1;
            segButton[ID_SEGMENT_TYPE_STD].y=y2+1;
            segButton[ID_SEGMENT_TYPE_STD].width=w1-1;
            segButton[ID_SEGMENT_TYPE_STD].height=h1-2;
            //cli->segset.type=1;
            if(cli->segset.type==0)
            {
                memDC.SetTextForeground(wxColor(118,118,118));
            }
            else
            {
                if(segings[4].type==1)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_STD)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_STD)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_STD]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawLine(x2+w1,y2,x2+w1,y2+h1);
            memDC.DrawLabel(_("标准环"),segButton[ID_SEGMENT_TYPE_STD],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            x2=x2+w1;
            segButton[ID_SEGMENT_TYPE_TR].x=x2+1;
            segButton[ID_SEGMENT_TYPE_TR].y=y2+1;
            segButton[ID_SEGMENT_TYPE_TR].width=w1-1;
            segButton[ID_SEGMENT_TYPE_TR].height=h1-2;
            //cli->segset.type=1;
            if(cli->segset.type==0)
            {
                memDC.SetTextForeground(wxColor(118,118,118));
            }
            else
            {
                if(segings[4].type==3)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_TR)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_TR)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_TR]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            //memDC.DrawLine(x1+w1,y1+3,x1+w1,y1+h1-3);
            memDC.DrawLabel(_("右转弯"),segButton[ID_SEGMENT_TYPE_TR],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentDlg::OnMotionSeg1(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int n=cli->segset.Ks;
    double r;
    for(int i=0;i<n+3;i++)
    {
        r=(x-segButton[ID_SEGMENT_COUNT+i].x)*(x-segButton[ID_SEGMENT_COUNT+i].x)+(y-segButton[ID_SEGMENT_COUNT+i].y)*(y-segButton[ID_SEGMENT_COUNT+i].y);
        r=sqrt(r);
        if(r<segButton[ID_SEGMENT_COUNT+i].width)
        {
            motion=ID_SEGMENT_COUNT+i;
            break;
        }
        else
        {
            motion=ID_SEGMENT_NONE;
        }
    }
    if(motion==ID_SEGMENT_NONE)
    {
        if(y>segButton[ID_SEGMENT_TYPE_TL].y && y<segButton[ID_SEGMENT_TYPE_TL].y+segButton[ID_SEGMENT_TYPE_TL].height)
        {
            if(x>segButton[ID_SEGMENT_TYPE_TL].x && x<segButton[ID_SEGMENT_TYPE_TL].x+segButton[ID_SEGMENT_TYPE_TL].width)
            {
                motion=ID_SEGMENT_TYPE_TL;
            }
            else if(x>segButton[ID_SEGMENT_TYPE_TR].x && x<segButton[ID_SEGMENT_TYPE_TR].x+segButton[ID_SEGMENT_TYPE_TR].width)
            {
                motion=ID_SEGMENT_TYPE_TR;
            }
            else if(x>segButton[ID_SEGMENT_TYPE_STD].x && x<segButton[ID_SEGMENT_TYPE_STD].x+segButton[ID_SEGMENT_TYPE_STD].width)
            {
                motion=ID_SEGMENT_TYPE_STD;
            }
            else
            {
                motion=ID_SEGMENT_NONE;
            }
        }
        else
        {
            motion=ID_SEGMENT_NONE;
        }
    }

    panelFigSeg1->Refresh();
}

void SegmentDlg::OnLeaveSeg1(wxMouseEvent& event)
{
    motion=ID_SEGMENT_NONE;
    panelFigSeg1->Refresh();
}

void SegmentDlg::OnClickSeg1(wxMouseEvent& event)
{
    int n=cli->segset.Ks;
    for(int i=0;i<n;i++)
    {
        if(motion==ID_SEGMENT_COUNT+i)
        {
            if(i==0)
            {
                segings[4].kpos=n;
                //mtg_kpos_off(cli,&segings[4]);
            }
            else
            {
                segings[4].kpos=i;
                //mtg_kpos_off(cli,&segings[4]);
            }
        }
    }

    if(motion==ID_SEGMENT_TYPE_TL)
    {
        segings[4].type=2;
        //mtg_kpos_off(cli,&segings[4]);
    }
    else if(motion==ID_SEGMENT_TYPE_TR)
    {
        segings[4].type=3;
        //mtg_kpos_off(cli,&segings[4]);
    }
    else if(motion==ID_SEGMENT_TYPE_STD)
    {
        segings[4].type=1;
        //mtg_kpos_off(cli,&segings[4]);
    }

    panelFigSeg1->Refresh();
}

void SegmentDlg::OnPaintSeging(wxPaintEvent& event)
{
    wxPaintDC dc(panelFigSeging);
    int w,h;
    panelFigSeging->GetClientSize(&w,&h);
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

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont num(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        double radius =(h-150)/2.0;
        double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
        int w1,h1;

        wxPen pen1=wxPen(wxColor(255,30,30));
        wxPen pen2=wxPen(wxColor(30,30,30));

        x1=w/2.0-30;
        y1=h/2.0-45;
        if(cli->nblk>0)
        {
            double angle1 = PI*3/2-cli->blocks[0].angle/2.0;
            double angle2=PI*3/2-cli->blocks[0].angle/2.0;
            int k1=segings[4].kpos;
            if(k1==cli->segset.Ks) k1=0;
            if(k1>=0) angle2 = angle2+2.0*PI*k1/cli->segset.Ks;
            if(id==4) k1=-1;
            if(segings[id].kpos<cli->segset.Ks)
            {
                angle1 = angle1+2.0*PI*segings[id].kpos/cli->segset.Ks;
            }
            for(int i=0;i<cli->nblk;i++)
            {
                x2=x1+radius*cos(angle1+0.02);
                y2=y1+radius*sin(angle1+0.02);
                x4=x1+(radius-25)*cos(angle1+0.02);
                y4=y1+(radius-25)*sin(angle1+0.02);
                angle1+=cli->blocks[i].angle;
                x3=x1+radius*cos(angle1-0.02);
                y3=y1+radius*sin(angle1-0.02);
                x5=x1+(radius-25)*cos(angle1-0.02);
                y5=y1+(radius-25)*sin(angle1-0.02);
                if(i==0)
                {
                    memDC.SetPen(pen1);
                }
                else
                {
                    memDC.SetPen(pen2);
                }
                memDC.DrawArc(x3,y3,x2,y2,x1,y1);
                memDC.DrawArc(x5,y5,x4,y4,x1,y1);
            }
            memDC.SetPen(wxPen(wxColor(255,255,255)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.DrawCircle(x1,y1,radius-27);
            memDC.SetPen(wxPen(wxColor(20,20,20),1,wxDOT_DASH));
            memDC.DrawLine(1,y1,w-1,y1);
            memDC.DrawLine(x1,1,x1,h-1);

            if((k1>0 && k1!=segings[5].kpos) || (k1==0 && cli->segset.Ks!=segings[5].kpos))
            {
                for(int i=0;i<cli->nblk;i++)
                {
                    x2=x1+(radius+10)*cos(angle2+0.02);
                    y2=y1+(radius+10)*sin(angle2+0.02);
                    x4=x1+(radius-35)*cos(angle2+0.02);
                    y4=y1+(radius-35)*sin(angle2+0.02);
                    angle2+=cli->blocks[i].angle;
                    x3=x1+(radius+10)*cos(angle2-0.02);
                    y3=y1+(radius+10)*sin(angle2-0.02);
                    x5=x1+(radius-35)*cos(angle2-0.02);
                    y5=y1+(radius-35)*sin(angle2-0.02);
                    if(i==0 || i==1)
                    {
                        memDC.SetPen(wxPen(wxColor(255,0,0),2,wxDOT_DASH));
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(168,168,168),2,wxDOT_DASH));
                    }
                    memDC.DrawLine(x2,y2,x4,y4);
                }
            }

            angle1=PI*2.0/cli->segset.Ks;
            x4=-1;
            x5=-1;
            int k4=segings[4].kpos;
            int k5;
            if(k4==cli->segset.Ks) k4=0;
            for(int i=0;i<cli->segset.Ks;i++)
            {
                x2=x1+(radius-13)*cos(PI*3.0/2.0+angle1*i);
                y2=y1+(radius-13)*sin(PI*3.0/2.0+angle1*i);
                segButton[ID_SEGMENT_COUNT+i].x=x2;
                segButton[ID_SEGMENT_COUNT+i].y=y2;
                segButton[ID_SEGMENT_COUNT+i].width=12;
                segButton[ID_SEGMENT_COUNT+i].height=12;
                if(i==segings[id].kpos || (i==0 && segings[id].kpos==cli->segset.Ks))
                {
                    if(motion==ID_SEGMENT_COUNT+i)
                    {
                        memDC.SetPen(btnPen[1]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    else
                    {
                        memDC.SetPen(btnPen[0]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                    memDC.SetBrush(btnBrush[1]);
                }
                else
                {
                    if(motion==ID_SEGMENT_COUNT+i)
                    {
                        memDC.SetPen(btnPen[1]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    k5=i-k4;
                    if(k5<0) k5=k5+cli->segset.Ks;
                    if(id==5 && cli->kpos[k5]==0)
                    {
                        memDC.SetPen(btnPen[0]);
                        memDC.SetBrush(wxBrush(wxColor(255,255,0)));
                    }
                    else
                    {
                        memDC.SetPen(btnPen[0]);
                        memDC.SetBrush(wxBrush(wxColor(0,0,0)));
                    }
                }

                memDC.DrawCircle(x2,y2,5);

                if(i==0)
                {
                    x3=x1+(radius+15)*cos(PI*3.0/2.0+angle1*i);
                    y3=y1+(radius+15)*sin(PI*3.0/2.0+angle1*i);
                }
                else if(i==k1)
                {
                    x5=x1+(radius+15)*cos(PI*3.0/2.0+angle1*i);
                    y5=y1+(radius+15)*sin(PI*3.0/2.0+angle1*i);
                }

                if(i==segings[id].kpos)
                {
                    x4=x1+(radius+15)*cos(PI*3.0/2.0+angle1*i);
                    y4=y1+(radius+15)*sin(PI*3.0/2.0+angle1*i);
                }

            }
            memDC.SetTextForeground(wxColor(255,0,0));
            memDC.SetFont(num);
            memDC.DrawLabel(wxString::Format(_("%d"),cli->segset.Ks),wxRect(x3,y3,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            if(x4>0) memDC.DrawLabel(wxString::Format(_("%d"),segings[id].kpos),wxRect(x4,y4,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            if(x5>0) memDC.DrawLabel(wxString::Format(_("%d"),k1),wxRect(x5,y5,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        x1=15;
        y1=25;
        memDC.SetFont(chs);
        memDC.SetTextForeground(btnTextColor[0]);
        memDC.DrawLabel(_("管环编号"),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("是否选型 ？"),wxRect(x1,y1+25,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=85;
        memDC.DrawLabel(wxString::Format(_("%d"),segings[id].numb),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        if(segings[id].t==0)
        {
            memDC.DrawLabel(_("否"),wxRect(x1,y1+25,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("是"),wxRect(x1,y1+25,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        double hx[12],hy[12];
        double vx[12],vy[12];
        double s1,s2;
        double l2r,d2u,b;
        //FILE* fp=fopen("F:\\segtest.log","w");
        w1=w/2-radius-50;
        h1=w1/4;

        x1=w/2.0-30;
        y1=h/2.0-45;

        x2=x1-w1/2;
        x3=x2+w1;
        y2=h-h1/2;

        x4=0;
        y4=y1;
        x5=h1;

        hx[6]=x2;
        hy[6]=y2-h1/2;
        hx[7]=x3;
        hy[7]=hy[6];
        hx[8]=x3;
        hy[8]=hy[7]+h1;
        hx[9]=x2;
        hy[9]=hy[6]+h1;
        segButton[ID_SEGMENT_LASTH].x=hx[6];
        segButton[ID_SEGMENT_LASTH].y=hy[6];
        segButton[ID_SEGMENT_LASTH].width=w1;
        segButton[ID_SEGMENT_LASTH].height=h1;

        hx[0]=x2;
        hy[0]=hy[6]-2;
        hx[1]=x3;
        hy[1]=hy[0];
        hx[2]=x3;
        hy[2]=hy[1]-h1;
        hx[3]=x2;
        hy[3]=hy[0]-h1;
        hx[4]=(hx[0]+hx[1])/2.0;
        hy[4]=(hy[0]+hy[3])/2.0;
        segButton[ID_SEGMENT_SEGH].x=hx[3];
        segButton[ID_SEGMENT_SEGH].y=hy[3];
        segButton[ID_SEGMENT_SEGH].width=w1;
        segButton[ID_SEGMENT_SEGH].height=h1;

        vx[6]=x5;
        vy[6]=h/2-45-w1/2;
        vx[7]=x5;
        vy[7]=vy[6]+w1;
        vx[8]=x4;
        vy[8]=vy[7];
        vx[9]=vx[8];
        vy[9]=vy[6];
        segButton[ID_SEGMENT_LASTV].x=vx[9];
        segButton[ID_SEGMENT_LASTV].y=vy[9];
        segButton[ID_SEGMENT_LASTV].width=h1;
        segButton[ID_SEGMENT_LASTV].height=w1;

        vx[0]=vx[6]+2;
        vy[0]=vy[6];
        vx[1]=vx[0];
        vy[1]=vy[0]+w1;
        vx[2]=vx[1]+h1;
        vy[2]=vy[1];
        vx[3]=vx[2];
        vy[3]=vy[2]-w1;
        vx[4]=(vx[0]+vx[3])/2.0;
        vy[4]=(vy[0]+vy[1])/2.0;
        segButton[ID_SEGMENT_SEGV].x=vx[0];
        segButton[ID_SEGMENT_SEGV].y=vy[0];
        segButton[ID_SEGMENT_SEGV].width=h1;
        segButton[ID_SEGMENT_SEGV].height=w1;

        double dist,azi[3],pitch[3],roll;

        if(cli->segset.f2b==0)
        {
            l2r=fabs(segings[4].l2r/2.0);
            d2u=fabs(segings[4].d2u/2.0);
            s1=h1/2/cli->segset.l2s;
            s2=atan(h1/2.0/w1)/atan(cli->segset.l2s/cli->segset.De);
            //fprintf(fp,"%.12f,%.12f\n",l2r,d2u);
            l2r=l2r*s1;
            d2u=d2u*s1;
            if(segings[4].type==2)
            {
                hy[7]=hy[7]-l2r;
                hy[8]=hy[8]+l2r;
            }
            else if(segings[4].type==3)
            {
                hy[6]=hy[6]-l2r;
                hy[9]=hy[9]+l2r;
            }
            hx[11]=(hx[6]+hx[7])/2.0;
            hy[11]=(hy[6]+hy[9])/2.0;

            hy[0]=hy[0]-l2r/2.0;
            hy[1]=hy[1]-l2r/2.0;
            hy[2]=hy[2]-l2r/2.0;
            hy[3]=hy[3]-l2r/2.0;

            if(segings[4].d2u<0.0)
            {
                vx[6]=vx[6]+d2u;
                vx[9]=vx[9]-d2u;
            }
            else
            {
                vx[7]=vx[7]+d2u;
                vx[8]=vx[8]-d2u;
            }

            vx[11]=(vx[6]+vx[9])/2.0;
            vy[11]=(vy[6]+vy[7])/2.0;

            vx[0]=vx[0]+d2u/2.0;
            vx[1]=vx[1]+d2u/2.0;
            vx[2]=vx[2]+d2u/2.0;
            vx[3]=vx[3]+d2u/2.0;

            l2r=fabs(segings[5].l2r/2.0);
            d2u=fabs(segings[5].d2u/2.0);
            l2r=l2r*s1;
            d2u=d2u*s1;
            //fprintf(fp,"%.12f,%.12f\n",l2r,d2u);
            azi[2]=atan(segings[5].l2r/2.0*s1/w1);
            pitch[2]=atan(segings[5].d2u/2.0*s1/w1);

            if(segings[5].l2r<0.0)
            {
                hy[0]=hy[0]-l2r/2;
                hy[1]=hy[1]+l2r/2;
                hy[2]=hy[2]-l2r-l2r/2;
                hy[3]=hy[3]-l2r/2;
            }
            else
            {
                hy[0]=hy[0]+l2r/2;
                hy[1]=hy[1]-l2r/2;
                hy[2]=hy[2]-l2r/2;
                hy[3]=hy[3]-l2r-l2r/2;
            }
            hy[4]=(hy[0]+hy[3])/2.0;

            if(segings[5].d2u<0.0)
            {
                vx[0]=vx[0]-d2u/2;
                vx[1]=vx[1]+d2u/2;
                vx[2]=vx[2]+d2u/2;
                vx[3]=vx[3]+d2u+d2u/2;
            }
            else
            {
                vx[0]=vx[0]+d2u/2;
                vx[1]=vx[1]-d2u/2;
                vx[2]=vx[2]+d2u+d2u/2;
                vx[3]=vx[3]+d2u/2;
            }
            vx[4]=(vx[0]+vx[3])/2.0;

            azi[0]=segings[4].azi-segings[4].azi1;
            if(azi[0]<-PI/2.0) azi[0]=azi[0]+2.0*PI;
            if(azi[0]>PI/2.0) azi[0]=azi[0]-2.0*PI;

            pitch[0]=segings[4].tilt-segings[4].azi1;
            if(pitch[0]<-PI/2.0) pitch[0]=pitch[0]+2.0*PI;
            if(pitch[0]>PI/2.0) pitch[0]=pitch[0]-2.0*PI;

            azi[1]=atan2(hy[7]*1.0-hy[6]*1.0,hx[7]-hx[6]*1.0);
            if(azi[1]<0.0) azi[1]=azi[1]+2.0*PI;
            dist=h1/2.0+2;
            roll=atan2(hy[4]*1.0-hy[11]*1.0,hx[4]*1.0-hx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            roll=roll+azi[0]*s2;//+azi[1]+azi[2];
            hx[4]=hx[11]+dist*cos(roll);
            hy[4]=hy[11]+dist*sin(roll);

            pitch[1]=atan2(vy[7]*1.0-vy[6]*1.0,vx[7]-vx[6]*1.0);
            pitch[1]=pitch[1]-PI/2.0;
            if(pitch[1]<0.0) pitch[1]=pitch[1]+2.0*PI;
            dist=h1+2;
            roll=atan2(vy[4]*1.0-vy[11]*1.0,vx[4]*1.0-vx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            roll=roll-pitch[0]*s2;//+pitch[1]-pitch[2];
            vx[4]=vx[11]+dist*cos(roll);
            vy[4]=vy[11]+dist*sin(roll);
            memDC.SetBrush(*wxTRANSPARENT_BRUSH);

            roll=atan2(hy[0]*1.0-hy[4]*1.0,hx[0]*1.0-hx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[0]-hx[4])*(hx[0]-hx[4])+(hy[0]-hy[4])*(hy[0]-hy[4]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2+azi[1]+azi[2];
            hx[0]=hx[4]+dist*cos(roll)+segings[5].dh*s1;
            hy[0]=hy[4]+dist*sin(roll);

            roll=atan2(hy[1]*1.0-hy[4]*1.0,hx[1]*1.0-hx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[1]-hx[4])*(hx[1]-hx[4])+(hy[1]-hy[4])*(hy[1]-hy[4]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2+azi[1]+azi[2];
            hx[1]=hx[4]+dist*cos(roll)+segings[5].dh*s1;
            hy[1]=hy[4]+dist*sin(roll);

            roll=atan2(hy[2]*1.0-hy[4]*1.0,hx[2]*1.0-hx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[2]-hx[4])*(hx[2]-hx[4])+(hy[2]-hy[4])*(hy[2]-hy[4]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2+azi[1]+azi[2];
            hx[2]=hx[4]+dist*cos(roll)+segings[5].dh*s1;
            hy[2]=hy[4]+dist*sin(roll);

            roll=atan2(hy[3]*1.0-hy[4]*1.0,hx[3]*1.0-hx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[3]-hx[4])*(hx[3]-hx[4])+(hy[3]-hy[4])*(hy[3]-hy[4]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2+azi[1]+azi[2];
            hx[3]=hx[4]+dist*cos(roll)+segings[5].dh*s1;
            hy[3]=hy[4]+dist*sin(roll);

            //垂直
            roll=atan2(vy[0]*1.0-vy[4]*1.0,vx[0]*1.0-vx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[0]-vx[4])*(vx[0]-vx[4])+(vy[0]-vy[4])*(vy[0]-vy[4]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2+pitch[1]-pitch[2];
            vx[0]=vx[4]+dist*cos(roll);
            vy[0]=vy[4]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[1]*1.0-vy[4]*1.0,vx[1]*1.0-vx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[1]-vx[4])*(vx[1]-vx[4])+(vy[1]-vy[4])*(vy[1]-vy[4]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2+pitch[1]-pitch[2];
            vx[1]=vx[4]+dist*cos(roll);
            vy[1]=vy[4]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[2]*1.0-vy[4]*1.0,vx[2]*1.0-vx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[2]-vx[4])*(vx[2]-vx[4])+(vy[2]-vy[4])*(vy[2]-vy[4]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2+pitch[1]-pitch[2];
            vx[2]=vx[4]+dist*cos(roll);
            vy[2]=vy[4]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[3]*1.0-vy[4]*1.0,vx[3]*1.0-vx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[3]-vx[4])*(vx[3]-vx[4])+(vy[3]-vy[4])*(vy[3]-vy[4]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2+pitch[1]-pitch[2];
            vx[3]=vx[4]+dist*cos(roll);
            vy[3]=vy[4]+dist*sin(roll)-segings[5].dv*s1;

            //画上环
            roll=atan2(hy[6]*1.0-hy[11]*1.0,hx[6]*1.0-hx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[11]-hx[6])*(hx[11]-hx[6])+(hy[11]-hy[6])*(hy[11]-hy[6]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2;
            hx[6]=hx[11]+dist*cos(roll)+segings[5].dh*s1;
            hy[6]=hy[11]+dist*sin(roll);

            roll=atan2(hy[7]*1.0-hy[11]*1.0,hx[7]*1.0-hx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[11]-hx[7])*(hx[11]-hx[7])+(hy[11]-hy[7])*(hy[11]-hy[7]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2;
            hx[7]=hx[11]+dist*cos(roll)+segings[5].dh*s1;
            hy[7]=hy[11]+dist*sin(roll);

            roll=atan2(hy[8]*1.0-hy[11]*1.0,hx[8]*1.0-hx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[11]-hx[8])*(hx[11]-hx[8])+(hy[11]-hy[8])*(hy[11]-hy[8]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2;
            hx[8]=hx[11]+dist*cos(roll)+segings[5].dh*s1;
            hy[8]=hy[11]+dist*sin(roll);

            roll=atan2(hy[9]*1.0-hy[11]*1.0,hx[9]*1.0-hx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[11]-hx[9])*(hx[11]-hx[9])+(hy[11]-hy[9])*(hy[11]-hy[9]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2;
            hx[9]=hx[11]+dist*cos(roll)+segings[5].dh*s1;
            hy[9]=hy[11]+dist*sin(roll);

            //垂直
            roll=atan2(vy[6]*1.0-vy[11]*1.0,vx[6]*1.0-vx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[11]-vx[6])*(vx[11]-vx[6])+(vy[11]-vy[6])*(vy[11]-vy[6]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2;
            vx[6]=vx[11]+dist*cos(roll);
            vy[6]=vy[11]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[7]*1.0-vy[11]*1.0,vx[7]*1.0-vx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[11]-vx[7])*(vx[11]-vx[7])+(vy[11]-vy[7])*(vy[11]-vy[7]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2;
            vx[7]=vx[11]+dist*cos(roll);
            vy[7]=vy[11]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[8]*1.0-vy[11]*1.0,vx[8]*1.0-vx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[11]-vx[8])*(vx[11]-vx[8])+(vy[11]-vy[8])*(vy[11]-vy[8]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2;
            vx[8]=vx[11]+dist*cos(roll);
            vy[8]=vy[11]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[9]*1.0-vy[11]*1.0,vx[9]*1.0-vx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[11]-vx[9])*(vx[11]-vx[9])+(vy[11]-vy[9])*(vy[11]-vy[9]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2;
            vx[9]=vx[11]+dist*cos(roll);
            vy[9]=vy[11]+dist*sin(roll)-segings[5].dv*s1;

            if(id==4)
            {
                memDC.SetPen(wxPen(wxColor(0,50,200)));
                tbm_laj_Text->SetEditable(false);
                tbm_raj_Text->SetEditable(false);
                tbm_uaj_Text->SetEditable(false);
                tbm_daj_Text->SetEditable(false);
                tbm_lgap_Text->SetEditable(false);
                tbm_rgap_Text->SetEditable(false);
                tbm_ugap_Text->SetEditable(false);
                tbm_dgap_Text->SetEditable(false);
            }
            else
            {
                if(motion==ID_SEGMENT_LASTH || motion==ID_SEGMENT_LASTV)
                {
                    memDC.SetPen(wxPen(wxColor(0,50,200)));
                }
                else
                {
                    memDC.SetPen(wxPen(wxColor(168,168,168)));
                }
            }
            memDC.DrawLine(hx[6],hy[6],hx[7],hy[7]);
            memDC.DrawLine(hx[7],hy[7],hx[8],hy[8]);
            memDC.DrawLine(hx[8],hy[8],hx[9],hy[9]);
            memDC.DrawLine(hx[9],hy[9],hx[6],hy[6]);

            memDC.DrawLine(vx[6],vy[6],vx[7],vy[7]);
            memDC.DrawLine(vx[7],vy[7],vx[8],vy[8]);
            memDC.DrawLine(vx[8],vy[8],vx[9],vy[9]);
            memDC.DrawLine(vx[9],vy[9],vx[6],vy[6]);

            //if(id==5)
            if(id==5)
            {
                memDC.SetPen(wxPen(wxColor(0,50,200)));
                tbm_laj_Text->SetEditable(true);
                tbm_raj_Text->SetEditable(true);
                tbm_uaj_Text->SetEditable(true);
                tbm_daj_Text->SetEditable(true);
                tbm_lgap_Text->SetEditable(true);
                tbm_rgap_Text->SetEditable(true);
                tbm_ugap_Text->SetEditable(true);
                tbm_dgap_Text->SetEditable(true);
            }
            else
            {
                if(motion==ID_SEGMENT_SEGH || motion==ID_SEGMENT_SEGV)
                {
                    memDC.SetPen(wxPen(wxColor(0,50,200)));
                }
                else
                {
                    memDC.SetPen(wxPen(wxColor(168,168,168)));
                }
            }
            memDC.DrawLine(hx[0],hy[0],hx[1],hy[1]);
            memDC.DrawLine(hx[1],hy[1],hx[2],hy[2]);
            memDC.DrawLine(hx[2],hy[2],hx[3],hy[3]);
            memDC.DrawLine(hx[3],hy[3],hx[0],hy[0]);

            memDC.DrawLine(vx[0],vy[0],vx[1],vy[1]);
            memDC.DrawLine(vx[1],vy[1],vx[2],vy[2]);
            memDC.DrawLine(vx[2],vy[2],vx[3],vy[3]);
            memDC.DrawLine(vx[3],vy[3],vx[0],vy[0]);

            //fclose(fp);
        }

        memDC.SetPen(wxPen(wxColor(118,118,118)));
        x2=w/2+radius;
        x2=x2+(w-x2)/2-15;
        y2=y1-radius/2;
        memDC.DrawRoundedRectangle(x2-w1/5-3,y2-40,w1*2/5+6,25,3);
        tbm_uaj_Text->SetSize(x2-w1/5,y2-35,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2-w1/5-3,y2+35,w1*2/5+6,25,3);
        tbm_daj_Text->SetSize(x2-w1/5,y2+40,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2-w1*2/5-28,y2,w1*2/5+6,25,3);
        tbm_laj_Text->SetSize(x2-w1*2/5-25,y2+5,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2+22,y2,w1*2/5+6,25,3);
        tbm_raj_Text->SetSize(x2+25,y2+5,w1*2/5,18);
        memDC.DrawLabel(_("推进油缸行程[ mm ]"),wxRect(x2,y2-55,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("上"),wxRect(x2,y2-10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(_("下"),wxRect(x2,y2+30,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
        memDC.DrawLabel(_("左"),wxRect(x2-20,y2+9,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("右"),wxRect(x2+20,y2+9,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        y2=y1+radius/2;
        memDC.DrawRoundedRectangle(x2-w1/5-3,y2-35,w1*2/5+6,25,3);
        tbm_ugap_Text->SetSize(x2-w1/5,y2-30,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2-w1/5-3,y2+30,w1*2/5+6,25,3);
        tbm_dgap_Text->SetSize(x2-w1/5,y2+35,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2-w1*2/5-28,y2,w1*2/5+6,25,3);
        tbm_lgap_Text->SetSize(x2-w1*2/5-25,y2+5,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2+22,y2,w1*2/5+6,25,3);
        tbm_rgap_Text->SetSize(x2+25,y2+5,w1*2/5,18);
        memDC.DrawLabel(_("盾尾间隙[ mm ]"),wxRect(x2,y2-50,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("上"),wxRect(x2,y2-10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(_("下"),wxRect(x2,y2+30,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
        memDC.DrawLabel(_("左"),wxRect(x2-20,y2+9,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("右"),wxRect(x2+20,y2+9,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        x2=x2-w1/2;
        y2=y1+radius+15;
        memDC.DrawRoundedRectangle(x2,y2,w1,25,3);
        seg_dh_Text->SetSize(x2+3,y2+5,w1-6,18);
        memDC.DrawLabel(_("经验沉降值[ mm ]"),wxRect(x2,y2-15,w1,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        if(cli->nblk>0)
        {
            w1=60;
            h1=25;
            x2=x1-w1*3/2;
            y2=y1-radius/2-h1/2;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(btnBrush[0]);
            memDC.DrawRectangle(x2,y2,w1*3+1,h1);

            segButton[ID_SEGMENT_TYPE_TL].x=x2+1;
            segButton[ID_SEGMENT_TYPE_TL].y=y2+1;
            segButton[ID_SEGMENT_TYPE_TL].width=w1-1;
            segButton[ID_SEGMENT_TYPE_TL].height=h1-2;
            if(cli->segset.type==0)
            {
                memDC.SetTextForeground(wxColor(198,198,198));
                memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            }
            else
            {
                if(segings[id].type==2)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_TL)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_TL)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_TL]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawLine(x2+w1,y2,x2+w1,y2+h1);
            memDC.DrawLabel(_("左转弯"),segButton[ID_SEGMENT_TYPE_TL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            x2=x2+w1;
            segButton[ID_SEGMENT_TYPE_STD].x=x2+1;
            segButton[ID_SEGMENT_TYPE_STD].y=y2+1;
            segButton[ID_SEGMENT_TYPE_STD].width=w1-1;
            segButton[ID_SEGMENT_TYPE_STD].height=h1-2;
            //cli->segset.type=1;
            if(cli->segset.type==0)
            {
                memDC.SetTextForeground(wxColor(198,198,198));
                memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            }
            else
            {
                if(segings[id].type==1)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_STD)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_STD)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_STD]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawLine(x2+w1,y2,x2+w1,y2+h1);
            memDC.DrawLabel(_("标准环"),segButton[ID_SEGMENT_TYPE_STD],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            x2=x2+w1;
            segButton[ID_SEGMENT_TYPE_TR].x=x2+1;
            segButton[ID_SEGMENT_TYPE_TR].y=y2+1;
            segButton[ID_SEGMENT_TYPE_TR].width=w1-1;
            segButton[ID_SEGMENT_TYPE_TR].height=h1-2;
            //cli->segset.type=1;
            if(cli->segset.type==0)
            {
                memDC.SetTextForeground(wxColor(198,198,198));
                memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            }
            else
            {
                if(segings[id].type==3)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_TR)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_TR)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_TR]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            //memDC.DrawLine(x1+w1,y1+3,x1+w1,y1+h1-3);
            memDC.DrawLabel(_("右转弯"),segButton[ID_SEGMENT_TYPE_TR],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentDlg::OnMotionSeging(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int n=cli->segset.Ks;
    double r;
    for(int i=0;i<n+3;i++)
    {
        r=(x-segButton[ID_SEGMENT_COUNT+i].x)*(x-segButton[ID_SEGMENT_COUNT+i].x)+(y-segButton[ID_SEGMENT_COUNT+i].y)*(y-segButton[ID_SEGMENT_COUNT+i].y);
        r=sqrt(r);
        if(r<segButton[ID_SEGMENT_COUNT+i].width)
        {
            motion=ID_SEGMENT_COUNT+i;
            break;
        }
        else
        {
            motion=ID_SEGMENT_NONE;
        }
    }
    if(motion==ID_SEGMENT_NONE)
    {
        if(y>segButton[ID_SEGMENT_TYPE_TL].y && y<segButton[ID_SEGMENT_TYPE_TL].y+segButton[ID_SEGMENT_TYPE_TL].height)
        {
            if(x>segButton[ID_SEGMENT_TYPE_TL].x && x<segButton[ID_SEGMENT_TYPE_TL].x+segButton[ID_SEGMENT_TYPE_TL].width)
            {
                motion=ID_SEGMENT_TYPE_TL;
            }
            else if(x>segButton[ID_SEGMENT_TYPE_TR].x && x<segButton[ID_SEGMENT_TYPE_TR].x+segButton[ID_SEGMENT_TYPE_TR].width)
            {
                motion=ID_SEGMENT_TYPE_TR;
            }
            else if(x>segButton[ID_SEGMENT_TYPE_STD].x && x<segButton[ID_SEGMENT_TYPE_STD].x+segButton[ID_SEGMENT_TYPE_STD].width)
            {
                motion=ID_SEGMENT_TYPE_STD;
            }
            else
            {
                motion=ID_SEGMENT_NONE;
            }
        }
        else if(y>segButton[ID_SEGMENT_LASTV].y && y<segButton[ID_SEGMENT_LASTV].y+segButton[ID_SEGMENT_LASTV].height)
        {
            if(x>segButton[ID_SEGMENT_LASTV].x && x<segButton[ID_SEGMENT_LASTV].x+segButton[ID_SEGMENT_LASTV].width)
            {
                motion=ID_SEGMENT_LASTV;
            }
            else if(x>segButton[ID_SEGMENT_SEGV].x && x<segButton[ID_SEGMENT_SEGV].x+segButton[ID_SEGMENT_SEGV].width)
            {
                motion=ID_SEGMENT_SEGV;
            }
            else
            {
                motion=ID_SEGMENT_NONE;
            }
        }
        else if(x>segButton[ID_SEGMENT_SEGH].x && x<segButton[ID_SEGMENT_SEGH].x+segButton[ID_SEGMENT_SEGH].width)
        {
            if(y>segButton[ID_SEGMENT_SEGH].y && y<segButton[ID_SEGMENT_SEGH].y+segButton[ID_SEGMENT_SEGH].height)
            {
                motion=ID_SEGMENT_SEGH;
            }
            else if(y>segButton[ID_SEGMENT_LASTH].y && y<segButton[ID_SEGMENT_LASTH].y+segButton[ID_SEGMENT_LASTH].height)
            {
                motion=ID_SEGMENT_LASTH;
            }
            else
            {
                motion=ID_SEGMENT_NONE;
            }
        }
        else
        {
            motion=ID_SEGMENT_NONE;
        }
    }

    panelFigSeging->Refresh();
}

void SegmentDlg::OnLeaveSeging(wxMouseEvent& event)
{
    motion=ID_SEGMENT_NONE;
    panelFigSeging->Refresh();
}

void SegmentDlg::OnClickSeging(wxMouseEvent& event)
{
    int n=cli->segset.Ks;
    int i;
    for(i=0;i<n;i++)
    {
        if(motion==ID_SEGMENT_COUNT+i)
        {
            if(i==0)
            {
                segings[id].kpos=n;
                //mtg_kpos_off(cli,&segings[id]);
            }
            else
            {
                segings[id].kpos=i;
                //mtg_kpos_off(cli,&segings[id]);
            }
        }
    }

    if(i==n)
    {
        if(motion==ID_SEGMENT_TYPE_TL)
        {
            segings[id].type=2;
            //mtg_kpos_off(cli,&segings[id]);
        }
        else if(motion==ID_SEGMENT_TYPE_TR)
        {
            segings[id].type=3;
            //mtg_kpos_off(cli,&segings[id]);
        }
        else if(motion==ID_SEGMENT_TYPE_STD)
        {
            segings[id].type=1;
            //mtg_kpos_off(cli,&segings[id]);
        }
        else if(motion==ID_SEGMENT_SEGH || motion==ID_SEGMENT_SEGV)
        {
            id=5;
            tbm_laj_Text->SetEditable(true);
            tbm_raj_Text->SetEditable(true);
            tbm_uaj_Text->SetEditable(true);
            tbm_daj_Text->SetEditable(true);
            tbm_lgap_Text->SetEditable(true);
            tbm_rgap_Text->SetEditable(true);
            tbm_ugap_Text->SetEditable(true);
            tbm_dgap_Text->SetEditable(true);
            tbm_laj_Text->SetValue(wxString::Format(_("%.1f"),segings[5].laj*1000.0));
            tbm_raj_Text->SetValue(wxString::Format(_("%.1f"),segings[5].raj*1000.0));
            tbm_uaj_Text->SetValue(wxString::Format(_("%.1f"),segings[5].uaj*1000.0));
            tbm_daj_Text->SetValue(wxString::Format(_("%.1f"),segings[5].daj*1000.0));
            tbm_lgap_Text->SetValue(wxString::Format(_("%.1f"),segings[5].lgap*1000.0));
            tbm_rgap_Text->SetValue(wxString::Format(_("%.1f"),segings[5].rgap*1000.0));
            tbm_ugap_Text->SetValue(wxString::Format(_("%.1f"),segings[5].ugap*1000.0));
            tbm_dgap_Text->SetValue(wxString::Format(_("%.1f"),segings[5].dgap*1000.0));
        }
        else if(motion==ID_SEGMENT_LASTH || motion==ID_SEGMENT_LASTV)
        {
            id=4;
            tbm_laj_Text->SetEditable(false);
            tbm_raj_Text->SetEditable(false);
            tbm_uaj_Text->SetEditable(false);
            tbm_daj_Text->SetEditable(false);
            tbm_lgap_Text->SetEditable(false);
            tbm_rgap_Text->SetEditable(false);
            tbm_ugap_Text->SetEditable(false);
            tbm_dgap_Text->SetEditable(false);
            tbm_laj_Text->SetValue(wxString::Format(_("%.1f"),segings[4].laj*1000.0));
            tbm_raj_Text->SetValue(wxString::Format(_("%.1f"),segings[4].raj*1000.0));
            tbm_uaj_Text->SetValue(wxString::Format(_("%.1f"),segings[4].uaj*1000.0));
            tbm_daj_Text->SetValue(wxString::Format(_("%.1f"),segings[4].daj*1000.0));
            tbm_lgap_Text->SetValue(wxString::Format(_("%.1f"),segings[4].lgap*1000.0));
            tbm_rgap_Text->SetValue(wxString::Format(_("%.1f"),segings[4].rgap*1000.0));
            tbm_ugap_Text->SetValue(wxString::Format(_("%.1f"),segings[4].ugap*1000.0));
            tbm_dgap_Text->SetValue(wxString::Format(_("%.1f"),segings[4].dgap*1000.0));
        }
    }

    panelFigSeging->Refresh();
}

void SegmentDlg::OnPaintSegingsListTitle(wxPaintEvent& event)
{
    wxPaintDC dc(panelSegingsList);
    int w,h;
    panelSegingsList->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs1(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont chs2(15,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs1);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=40;
        memDC.SetTextForeground(wxColor(68,68,68));
        memDC.DrawLine(x1,h1,w1,h1);
        w1=gridSegings->GetColSize(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSegings->GetColSize(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSegings->GetColSize(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSegings->GetColSize(3);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("拼装点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSegings->GetColSize(4);
        w1=w1+gridSegings->GetColSize(5);
        memDC.DrawLine(x1,y1+h1/2,x1+w1,y1+h1/2);
        memDC.DrawLabel(_("偏差[ mm ]"),wxRect(x1,y1,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1/2,y1+h1/2,x1+w1/2,h1);
        memDC.DrawLabel(_("水平"),wxRect(x1,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("垂直"),wxRect(x1+w1/2,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSegings->GetColSize(6);
        w1=w1+gridSegings->GetColSize(7);
        memDC.DrawLine(x1,y1+h1/2,x1+w1,y1+h1/2);
        memDC.DrawLabel(_("超前量[ mm ]"),wxRect(x1,y1,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1/2,y1+h1/2,x1+w1/2,h1);
        memDC.DrawLabel(_("水平"),wxRect(x1,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("垂直"),wxRect(x1+w1/2,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentDlg::OnPaintFigSeg(wxPaintEvent& event)
{
    wxPaintDC dc(panelFigSeg);
    int w,h;
    panelFigSeg->GetClientSize(&w,&h);
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

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont num(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont mar(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("黑体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        double radius =(h-120)/2.0;
        double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;

        wxPen pen1=wxPen(wxColor(255,30,30));
        wxPen pen2=wxPen(wxColor(30,30,30));

        x1=w/2.0;
        y1=h/2.0;
        //wxMessageBox(wxString::Format(_("%d"),cli->nblk));
        if(cli->nblk>0)
        {
            double angle1 = PI*3/2-cli->blocks[0].angle/2.0;
            double angle2=PI*3/2-cli->blocks[0].angle/2.0;
            int k1=motion-ID_SEGMENT_COUNT;
            if(k1>=0) angle2 = angle2+2.0*PI*k1/cli->segset.Ks;
            if(segs[0].kpos<cli->segset.Ks)
            {
                angle1 = angle1+2.0*PI*segs[0].kpos/cli->segset.Ks;
            }
            for(int i=0;i<cli->nblk;i++)
            {
                x2=x1+radius*cos(angle1+0.02);
                y2=y1+radius*sin(angle1+0.02);
                x4=x1+(radius-25)*cos(angle1+0.02);
                y4=y1+(radius-25)*sin(angle1+0.02);
                angle1+=cli->blocks[i].angle;
                x3=x1+radius*cos(angle1-0.02);
                y3=y1+radius*sin(angle1-0.02);
                x5=x1+(radius-25)*cos(angle1-0.02);
                y5=y1+(radius-25)*sin(angle1-0.02);
                if(i==0)
                {
                    memDC.SetPen(pen1);
                }
                else
                {
                    memDC.SetPen(pen2);
                }
                memDC.DrawArc(x3,y3,x2,y2,x1,y1);
                memDC.DrawArc(x5,y5,x4,y4,x1,y1);
            }
            memDC.SetPen(wxPen(wxColor(255,255,255)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.DrawCircle(x1,y1,radius-27);
            memDC.SetPen(wxPen(wxColor(20,20,20),1,wxDOT_DASH));
            memDC.DrawLine(1,y1,w-1,y1);
            memDC.DrawLine(x1,1,x1,h-1);

            angle1=PI*2.0/cli->segset.Ks;
            x4=-1;
            x5=-1;
            for(int i=0;i<cli->segset.Ks;i++)
            {
                x2=x1+(radius-13)*cos(PI*3.0/2.0+angle1*i);
                y2=y1+(radius-13)*sin(PI*3.0/2.0+angle1*i);
                segButton[ID_SEGMENT_COUNT+i].x=x2;
                segButton[ID_SEGMENT_COUNT+i].y=y2;
                segButton[ID_SEGMENT_COUNT+i].width=12;
                segButton[ID_SEGMENT_COUNT+i].height=12;
                if(i==segs[0].kpos || (i==0 && segs[0].kpos==cli->segset.Ks))
                {
                    if(motion==ID_SEGMENT_COUNT+i)
                    {
                        memDC.SetPen(btnPen[1]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    else
                    {
                        memDC.SetPen(btnPen[0]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                    memDC.SetBrush(btnBrush[1]);
                }
                else
                {
                    if(motion==ID_SEGMENT_COUNT+i)
                    {
                        memDC.SetPen(btnPen[1]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    memDC.SetPen(btnPen[0]);
                    memDC.SetBrush(wxBrush(wxColor(0,0,0)));
                }

                memDC.DrawCircle(x2,y2,5);

                if(i==0)
                {
                    x3=x1+(radius-43)*cos(PI*3.0/2.0+angle1*i);
                    y3=y1+(radius-43)*sin(PI*3.0/2.0+angle1*i);
                }
                else if(i==k1)
                {
                    x5=x1+(radius-43)*cos(PI*3.0/2.0+angle1*i);
                    y5=y1+(radius-43)*sin(PI*3.0/2.0+angle1*i);
                }

                if(i==segs[0].kpos)
                {
                    x4=x1+(radius-43)*cos(PI*3.0/2.0+angle1*i);
                    y4=y1+(radius-43)*sin(PI*3.0/2.0+angle1*i);
                }
            }
            memDC.SetTextForeground(wxColor(255,0,0));
            memDC.SetFont(num);
            memDC.DrawLabel(wxString::Format(_("%d"),cli->segset.Ks),wxRect(x3,y3,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            if(x4>0) memDC.DrawLabel(wxString::Format(_("%d"),segs[0].kpos),wxRect(x4,y4,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            if(x5>0) memDC.DrawLabel(wxString::Format(_("%d"),k1),wxRect(x5,y5,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        x2=15;
        y2=35;
        memDC.SetFont(chs);
        memDC.SetTextForeground(btnTextColor[0]);
        memDC.DrawLabel(_("管环编号"),wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x2+=85;
        memDC.DrawLabel(wxString::Format(_("%d"),segs[0].numb),wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        int w1,h1;
        double s1;
        double a1,a2;
        double hx[4],hy[4],vx[4],vy[4];

        w1=w/2-radius-30;
        h1=w1/2;
        s1=h1/2.0/cli->segset.l2s;
        a1=segs[0].l2r/4.0;
        a2=segs[0].d2u/4.0;
        a1=a1*s1;
        a2=a2*s1;

        hx[0]=x1-w1/2;
        hy[0]=y1-h1/2;
        hx[1]=hx[0]+w1;
        hy[1]=hy[0];
        hx[2]=hx[1];
        hy[2]=hy[1]+h1;
        hx[3]=hx[0];
        hy[3]=hy[2];

        vx[0]=15+w1-h1/2;
        vy[0]=y1-w1/2;
        vx[1]=vx[0];
        vy[1]=vy[0]+w1;
        vx[2]=vx[1]-h1;
        vy[2]=vy[1];
        vx[3]=vx[2];
        vy[3]=vy[0];

        memDC.SetPen(wxPen(wxColor(168,168,168)));
        memDC.DrawLine(hx[0],hy[0]-a1,hx[1],hy[1]+a1);
        memDC.DrawLine(hx[1],hy[1]+a1,hx[2],hy[2]-a1);
        memDC.DrawLine(hx[2],hy[2]-a1,hx[3],hy[3]+a1);
        memDC.DrawLine(hx[3],hy[3]+a1,hx[0],hy[0]-a1);
        if(a1>0)
        {
            memDC.DrawLine(hx[1],hy[1]+a1,hx[0],hy[1]+a1);
            memDC.DrawLine(hx[2],hy[2]-a1,hx[3],hy[2]-a1);
        }
        else
        {
            memDC.DrawLine(hx[0],hy[0]-a1,hx[1],hy[0]-a1);
            memDC.DrawLine(hx[3],hy[3]+a1,hx[2],hy[3]+a1);
        }

        memDC.DrawLine(vx[0]-a2,vy[0],vx[1]+a2,vy[1]);
        memDC.DrawLine(vx[1]+a2,vy[1],vx[2]-a2,vy[2]);
        memDC.DrawLine(vx[2]-a2,vy[2],vx[3]+a2,vy[3]);
        memDC.DrawLine(vx[3]+a2,vy[3],vx[0]-a2,vy[0]);
        if(a2>0)
        {
            memDC.DrawLine(vx[0]-a2,vy[0],vx[0]-a2,vy[1]);
            memDC.DrawLine(vx[3]+a2,vy[2],vx[3]+a2,vy[3]);
        }
        else
        {
            memDC.DrawLine(vx[1]+a2,vy[0],vx[1]+a2,vy[1]);
            memDC.DrawLine(vx[2]-a2,vy[2],vx[2]-a2,vy[3]);
        }

        memDC.DrawLabel(_("水平"),wxRect(hx[0],hy[0],w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("垂直"),wxRect(vx[3],vy[3],h1,w1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x2=(vx[0]+vx[3])/2.0-w1/2;
        y2=y1+radius*2/3;
        h1=28;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x2,y2,w1,h1,3);
        seg_mile_Text->SetSize(x2+3,y2+5,w1-6,18);
        memDC.DrawLabel(_("起始环里程"),wxRect(x2,y2-25,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        if(cli->nblk>0)
        {
            w1=60;
            h1=25;
            x2=x1-w1*3/2;
            y2=y1-radius/2-h1/2;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(btnBrush[0]);
            memDC.DrawRectangle(x2,y2,w1*3+1,h1);

            segButton[ID_SEGMENT_TYPE_TL].x=x2+1;
            segButton[ID_SEGMENT_TYPE_TL].y=y2+1;
            segButton[ID_SEGMENT_TYPE_TL].width=w1-1;
            segButton[ID_SEGMENT_TYPE_TL].height=h1-2;
            if(cli->segset.type==0)
            {
                memDC.SetTextForeground(wxColor(198,198,198));
                memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            }
            else
            {
                if(segings[4].type==2)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_TL)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_TL)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_TL]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawLine(x2+w1,y2,x2+w1,y2+h1);
            memDC.DrawLabel(_("左转弯"),segButton[ID_SEGMENT_TYPE_TL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            x2=x2+w1;
            segButton[ID_SEGMENT_TYPE_STD].x=x2+1;
            segButton[ID_SEGMENT_TYPE_STD].y=y2+1;
            segButton[ID_SEGMENT_TYPE_STD].width=w1-1;
            segButton[ID_SEGMENT_TYPE_STD].height=h1-2;
            //cli->segset.type=1;
            if(cli->segset.type==0)
            {
                memDC.SetTextForeground(wxColor(198,198,198));
                memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            }
            else
            {
                if(segs[0].type==1)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_STD)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_STD)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_STD]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawLine(x2+w1,y2,x2+w1,y2+h1);
            memDC.DrawLabel(_("标准环"),segButton[ID_SEGMENT_TYPE_STD],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            x2=x2+w1;
            segButton[ID_SEGMENT_TYPE_TR].x=x2+1;
            segButton[ID_SEGMENT_TYPE_TR].y=y2+1;
            segButton[ID_SEGMENT_TYPE_TR].width=w1-1;
            segButton[ID_SEGMENT_TYPE_TR].height=h1-2;
            //cli->segset.type=1;
            if(cli->segset.type==0)
            {
                memDC.SetTextForeground(wxColor(198,198,198));
                memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            }
            else
            {
                if(segs[0].type==3)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_TR)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_TR)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_TR]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            //memDC.DrawLine(x1+w1,y1+3,x1+w1,y1+h1-3);
            memDC.DrawLabel(_("右转弯"),segButton[ID_SEGMENT_TYPE_TR],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentDlg::OnMotionSeg(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int n=cli->segset.Ks;
    double r;
    for(int i=0;i<n+3;i++)
    {
        r=(x-segButton[ID_SEGMENT_COUNT+i].x)*(x-segButton[ID_SEGMENT_COUNT+i].x)+(y-segButton[ID_SEGMENT_COUNT+i].y)*(y-segButton[ID_SEGMENT_COUNT+i].y);
        r=sqrt(r);
        if(r<segButton[ID_SEGMENT_COUNT+i].width)
        {
            motion=ID_SEGMENT_COUNT+i;
            break;
        }
        else
        {
            motion=ID_SEGMENT_NONE;
        }
    }
    if(motion==ID_SEGMENT_NONE)
    {
        if(y>segButton[ID_SEGMENT_TYPE_TL].y && y<segButton[ID_SEGMENT_TYPE_TL].y+segButton[ID_SEGMENT_TYPE_TL].height)
        {
            if(x>segButton[ID_SEGMENT_TYPE_TL].x && x<segButton[ID_SEGMENT_TYPE_TL].x+segButton[ID_SEGMENT_TYPE_TL].width)
            {
                motion=ID_SEGMENT_TYPE_TL;
            }
            else if(x>segButton[ID_SEGMENT_TYPE_TR].x && x<segButton[ID_SEGMENT_TYPE_TR].x+segButton[ID_SEGMENT_TYPE_TR].width)
            {
                motion=ID_SEGMENT_TYPE_TR;
            }
            else if(x>segButton[ID_SEGMENT_TYPE_STD].x && x<segButton[ID_SEGMENT_TYPE_STD].x+segButton[ID_SEGMENT_TYPE_STD].width)
            {
                motion=ID_SEGMENT_TYPE_STD;
            }
            else
            {
                motion=ID_SEGMENT_NONE;
            }
        }
        else
        {
            motion=ID_SEGMENT_NONE;
        }
    }

    panelFigSeg->Refresh();
}

void SegmentDlg::OnLeaveSeg(wxMouseEvent& event)
{
    motion=ID_SEGMENT_NONE;
    panelFigSeg->Refresh();
}

void SegmentDlg::OnClickSeg(wxMouseEvent& event)
{
    int n=cli->segset.Ks;
    for(int i=0;i<n;i++)
    {
        if(motion==ID_SEGMENT_COUNT+i)
        {
            if(i==0)
            {
                segs[0].kpos=n;
                //mtg_kpos_off(cli,&segs[0]);
            }
            else
            {
                segs[0].kpos=i;
                //mtg_kpos_off(cli,&segs[0]);
            }
        }
    }

    if(motion==ID_SEGMENT_TYPE_TL)
    {
        segs[0].type=2;
        //mtg_kpos_off(cli,&segs[0]);
    }
    else if(motion==ID_SEGMENT_TYPE_TR)
    {
        segs[0].type=3;
        //mtg_kpos_off(cli,&segs[0]);
    }
    else if(motion==ID_SEGMENT_TYPE_STD)
    {
        segs[0].type=1;
        //mtg_kpos_off(cli,&segs[0]);
    }

    panelFigSeg->Refresh();
}

void SegmentDlg::OnPaintSegsListTitle(wxPaintEvent& event)
{
    wxPaintDC dc(panelSegsList);
    int w,h;
    panelSegsList->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs1(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont chs2(15,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs1);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=40;
        memDC.SetTextForeground(wxColor(68,68,68));
        memDC.DrawLine(x1,h1,w1,h1);
        w1=gridSegs->GetColSize(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSegs->GetColSize(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSegs->GetColSize(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSegs->GetColSize(3);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("拼装点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSegs->GetColSize(4);
        w1=w1+gridSegs->GetColSize(5);
        memDC.DrawLine(x1,y1+h1/2,x1+w1,y1+h1/2);
        memDC.DrawLabel(_("偏差[ mm ]"),wxRect(x1,y1,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1/2,y1+h1/2,x1+w1/2,h1);
        memDC.DrawLabel(_("水平"),wxRect(x1,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("垂直"),wxRect(x1+w1/2,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSegs->GetColSize(6);
        w1=w1+gridSegs->GetColSize(7);
        memDC.DrawLine(x1,y1+h1/2,x1+w1,y1+h1/2);
        memDC.DrawLabel(_("超前量[ mm ]"),wxRect(x1,y1,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1/2,y1+h1/2,x1+w1/2,h1);
        memDC.DrawLabel(_("水平"),wxRect(x1,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("垂直"),wxRect(x1+w1/2,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentDlg::OnPaintFigSeged(wxPaintEvent& event)
{
    wxPaintDC dc(panelSegedList);
    int w,h;
    panelSegedList->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs1(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont chs2(15,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs1);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=40;
        memDC.SetTextForeground(wxColor(68,68,68));
        memDC.DrawLine(x1,h1,w1,h1);
        w1=gridSeged->GetColSize(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSeged->GetColSize(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSeged->GetColSize(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSeged->GetColSize(3);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("拼装点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSeged->GetColSize(4);
        w1=w1+gridSeged->GetColSize(5);
        memDC.DrawLine(x1,y1+h1/2,x1+w1,y1+h1/2);
        memDC.DrawLabel(_("偏差[ mm ]"),wxRect(x1,y1,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1/2,y1+h1/2,x1+w1/2,h1);
        memDC.DrawLabel(_("水平"),wxRect(x1,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("垂直"),wxRect(x1+w1/2,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridSeged->GetColSize(6);
        w1=w1+gridSeged->GetColSize(7);
        memDC.DrawLine(x1,y1+h1/2,x1+w1,y1+h1/2);
        memDC.DrawLabel(_("超前量[ mm ]"),wxRect(x1,y1,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1/2,y1+h1/2,x1+w1/2,h1);
        memDC.DrawLabel(_("水平"),wxRect(x1,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("垂直"),wxRect(x1+w1/2,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentDlg::OnPaintDemo(wxPaintEvent& event)
{
    wxPaintDC dc(panelFigDemo);
    int w,h;
    panelFigDemo->GetClientSize(&w,&h);
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

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont num(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        double radius =(h-150)/2.0;
        double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
        int w1,h1;

        wxPen pen1=wxPen(wxColor(255,30,30));
        wxPen pen2=wxPen(wxColor(30,30,30));

        x1=w/2.0-30;
        y1=h/2.0-45;
        if(cli->nblk>0)
        {
            double angle1 = PI*3/2-cli->blocks[0].angle/2.0;
            double angle2=PI*3/2-cli->blocks[0].angle/2.0;
            int k1=segings[4].kpos;
            if(k1==cli->segset.Ks) k1=0;
            if(k1>=0) angle2 = angle2+2.0*PI*k1/cli->segset.Ks;
            if(segings[5].kpos<cli->segset.Ks)
            {
                angle1 = angle1+2.0*PI*segings[5].kpos/cli->segset.Ks;
            }
            for(int i=0;i<cli->nblk;i++)
            {
                x2=x1+radius*cos(angle1+0.02);
                y2=y1+radius*sin(angle1+0.02);
                x4=x1+(radius-25)*cos(angle1+0.02);
                y4=y1+(radius-25)*sin(angle1+0.02);
                angle1+=cli->blocks[i].angle;
                x3=x1+radius*cos(angle1-0.02);
                y3=y1+radius*sin(angle1-0.02);
                x5=x1+(radius-25)*cos(angle1-0.02);
                y5=y1+(radius-25)*sin(angle1-0.02);
                if(i==0)
                {
                    memDC.SetPen(pen1);
                }
                else
                {
                    memDC.SetPen(pen2);
                }
                memDC.DrawArc(x3,y3,x2,y2,x1,y1);
                memDC.DrawArc(x5,y5,x4,y4,x1,y1);
            }
            memDC.SetPen(wxPen(wxColor(255,255,255)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.DrawCircle(x1,y1,radius-27);
            memDC.SetPen(wxPen(wxColor(20,20,20),1,wxDOT_DASH));
            memDC.DrawLine(1,y1,w-1,y1);
            memDC.DrawLine(x1,1,x1,h-1);

            if((k1>0 && k1!=segings[5].kpos) || (k1==0 && cli->segset.Ks!=segings[5].kpos))
            {
                for(int i=0;i<cli->nblk;i++)
                {
                    x2=x1+(radius+10)*cos(angle2+0.02);
                    y2=y1+(radius+10)*sin(angle2+0.02);
                    x4=x1+(radius-35)*cos(angle2+0.02);
                    y4=y1+(radius-35)*sin(angle2+0.02);
                    angle2+=cli->blocks[i].angle;
                    x3=x1+(radius+10)*cos(angle2-0.02);
                    y3=y1+(radius+10)*sin(angle2-0.02);
                    x5=x1+(radius-35)*cos(angle2-0.02);
                    y5=y1+(radius-35)*sin(angle2-0.02);
                    if(i==0 || i==1)
                    {
                        memDC.SetPen(wxPen(wxColor(255,0,0),2,wxDOT_DASH));
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(168,168,168),2,wxDOT_DASH));
                    }
                    memDC.DrawLine(x2,y2,x4,y4);
                }
            }

            angle1=PI*2.0/cli->segset.Ks;
            x4=-1;
            x5=-1;
            for(int i=0;i<cli->segset.Ks;i++)
            {
                x2=x1+(radius-13)*cos(PI*3.0/2.0+angle1*i);
                y2=y1+(radius-13)*sin(PI*3.0/2.0+angle1*i);
                segButton[ID_SEGMENT_COUNT+i].x=x2;
                segButton[ID_SEGMENT_COUNT+i].y=y2;
                segButton[ID_SEGMENT_COUNT+i].width=12;
                segButton[ID_SEGMENT_COUNT+i].height=12;
                if(i==segings[5].kpos || (i==0 && segings[5].kpos==cli->segset.Ks))
                {
                    if(motion==ID_SEGMENT_COUNT+i)
                    {
                        memDC.SetPen(btnPen[1]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    else
                    {
                        memDC.SetPen(btnPen[0]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                    memDC.SetBrush(btnBrush[1]);
                }
                else
                {
                    if(motion==ID_SEGMENT_COUNT+i)
                    {
                        memDC.SetPen(btnPen[1]);
                        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                        memDC.DrawCircle(x2,y2,12);
                    }
                    memDC.SetPen(btnPen[0]);
                    memDC.SetBrush(wxBrush(wxColor(0,0,0)));
                }

                memDC.DrawCircle(x2,y2,5);

                if(i==0)
                {
                    x3=x1+(radius-43)*cos(PI*3.0/2.0+angle1*i);
                    y3=y1+(radius-43)*sin(PI*3.0/2.0+angle1*i);
                }
                else if(i==k1)
                {
                    x5=x1+(radius-43)*cos(PI*3.0/2.0+angle1*i);
                    y5=y1+(radius-43)*sin(PI*3.0/2.0+angle1*i);
                }

                if(i==segings[5].kpos)
                {
                    x4=x1+(radius-43)*cos(PI*3.0/2.0+angle1*i);
                    y4=y1+(radius-43)*sin(PI*3.0/2.0+angle1*i);
                }

            }
            memDC.SetTextForeground(wxColor(255,0,0));
            memDC.SetFont(num);
            memDC.DrawLabel(wxString::Format(_("%d"),cli->segset.Ks),wxRect(x3,y3,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            if(x4>0) memDC.DrawLabel(wxString::Format(_("%d"),segings[5].kpos),wxRect(x4,y4,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            if(x5>0) memDC.DrawLabel(wxString::Format(_("%d"),k1),wxRect(x5,y5,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        x1=15;
        y1=25;
        memDC.SetFont(chs);
        memDC.SetTextForeground(btnTextColor[0]);
        memDC.DrawLabel(_("管环编号"),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=85;

        memDC.DrawLabel(wxString::Format(_("%d"),segings[5].numb),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        double hx[12],hy[12];
        double vx[12],vy[12];
        double s1,s2;
        double l2r,d2u,b;
        //FILE* fp=fopen("F:\\segtest.log","w");
        w1=w/2-radius-50;
        h1=w1/4;

        x1=w/2.0-30;
        y1=h/2.0-45;

        x2=x1-w1/2;
        x3=x2+w1;
        y2=h-h1/2.0;

        x4=0;
        y4=y1;
        x5=h1;

        hx[6]=x2;
        hy[6]=y2-h1/2;
        hx[7]=x3;
        hy[7]=hy[6];
        hx[8]=x3;
        hy[8]=hy[7]+h1;
        hx[9]=x2;
        hy[9]=hy[6]+h1;

        hx[0]=x2;
        hy[0]=hy[6]-2;
        hx[1]=x3;
        hy[1]=hy[0];
        hx[2]=x3;
        hy[2]=hy[1]-h1;
        hx[3]=x2;
        hy[3]=hy[0]-h1;
        hx[4]=(hx[0]+hx[1])/2.0;
        hy[4]=(hy[0]+hy[3])/2.0;

        vx[6]=x5;
        vy[6]=h/2-45-w1/2;
        vx[7]=x5;
        vy[7]=vy[6]+w1;
        vx[8]=x4;
        vy[8]=vy[7];
        vx[9]=vx[8];
        vy[9]=vy[6];

        vx[0]=vx[6]+2;
        vy[0]=vy[6];
        vx[1]=vx[0];
        vy[1]=vy[0]+w1;
        vx[2]=vx[1]+h1;
        vy[2]=vy[1];
        vx[3]=vx[2];
        vy[3]=vy[2]-w1;
        vx[4]=(vx[0]+vx[3])/2.0;
        vy[4]=(vy[0]+vy[1])/2.0;

        double dist,azi[3],pitch[3],roll;

        if(cli->segset.f2b==0)
        {
            l2r=fabs(segings[4].l2r/2.0);
            d2u=fabs(segings[4].d2u/2.0);
            s1=h1/2/cli->segset.l2s;
            s2=atan(h1/2.0/w1)/atan(cli->segset.l2s/cli->segset.De);
            //fprintf(fp,"%.12f,%.12f\n",l2r,d2u);
            l2r=l2r*s1;
            d2u=d2u*s1;
            if(segings[4].type==2)
            {
                hy[7]=hy[7]-l2r;
                hy[8]=hy[8]+l2r;
            }
            else if(segings[4].type==3)
            {
                hy[6]=hy[6]-l2r;
                hy[9]=hy[9]+l2r;
            }
            hx[11]=(hx[6]+hx[7])/2.0;
            hy[11]=(hy[6]+hy[9])/2.0;

            hy[0]=hy[0]-l2r/2.0;
            hy[1]=hy[1]-l2r/2.0;
            hy[2]=hy[2]-l2r/2.0;
            hy[3]=hy[3]-l2r/2.0;

            if(segings[4].d2u<0.0)
            {
                vx[6]=vx[6]+d2u;
                vx[9]=vx[9]-d2u;
            }
            else
            {
                vx[7]=vx[7]+d2u;
                vx[8]=vx[8]-d2u;
            }

            vx[11]=(vx[6]+vx[9])/2.0;
            vy[11]=(vy[6]+vy[7])/2.0;

            vx[0]=vx[0]+d2u/2.0;
            vx[1]=vx[1]+d2u/2.0;
            vx[2]=vx[2]+d2u/2.0;
            vx[3]=vx[3]+d2u/2.0;

            l2r=fabs(segings[5].l2r/2.0);
            d2u=fabs(segings[5].d2u/2.0);
            l2r=l2r*s1;
            d2u=d2u*s1;
            //fprintf(fp,"%.12f,%.12f\n",l2r,d2u);
            azi[2]=atan(segings[5].l2r/2.0*s1/w1);
            pitch[2]=atan(segings[5].d2u/2.0*s1/w1);

            if(segings[5].l2r<0.0)
            {
                hy[0]=hy[0]-l2r/2;
                hy[1]=hy[1]+l2r/2;
                hy[2]=hy[2]-l2r-l2r/2;
                hy[3]=hy[3]-l2r/2;
            }
            else
            {
                hy[0]=hy[0]+l2r/2;
                hy[1]=hy[1]-l2r/2;
                hy[2]=hy[2]-l2r/2;
                hy[3]=hy[3]-l2r-l2r/2;
            }
            hy[4]=(hy[0]+hy[3])/2.0;

            if(segings[5].d2u<0.0)
            {
                vx[0]=vx[0]-d2u/2;
                vx[1]=vx[1]+d2u/2;
                vx[2]=vx[2]+d2u/2;
                vx[3]=vx[3]+d2u+d2u/2;
            }
            else
            {
                vx[0]=vx[0]+d2u/2;
                vx[1]=vx[1]-d2u/2;
                vx[2]=vx[2]+d2u+d2u/2;
                vx[3]=vx[3]+d2u/2;
            }
            vx[4]=(vx[0]+vx[3])/2.0;

            azi[0]=segings[4].azi-segings[4].azi1;
            if(azi[0]<-PI/2.0) azi[0]=azi[0]+2.0*PI;
            if(azi[0]>PI/2.0) azi[0]=azi[0]-2.0*PI;

            pitch[0]=segings[4].tilt-segings[4].azi1;
            if(pitch[0]<-PI/2.0) pitch[0]=pitch[0]+2.0*PI;
            if(pitch[0]>PI/2.0) pitch[0]=pitch[0]-2.0*PI;

            azi[1]=atan2(hy[7]*1.0-hy[6]*1.0,hx[7]-hx[6]*1.0);
            if(azi[1]<0.0) azi[1]=azi[1]+2.0*PI;
            dist=h1/2.0+2;
            roll=atan2(hy[4]*1.0-hy[11]*1.0,hx[4]*1.0-hx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            roll=roll+azi[0]*s2;//+azi[1]+azi[2];
            hx[4]=hx[11]+dist*cos(roll);
            hy[4]=hy[11]+dist*sin(roll);

            pitch[1]=atan2(vy[7]*1.0-vy[6]*1.0,vx[7]-vx[6]*1.0);
            pitch[1]=pitch[1]-PI/2.0;
            if(pitch[1]<0.0) pitch[1]=pitch[1]+2.0*PI;
            dist=h1+2;
            roll=atan2(vy[4]*1.0-vy[11]*1.0,vx[4]*1.0-vx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            roll=roll-pitch[0]*s2;//+pitch[1]-pitch[2];
            vx[4]=vx[11]+dist*cos(roll);
            vy[4]=vy[11]+dist*sin(roll);
            memDC.SetBrush(*wxTRANSPARENT_BRUSH);

            roll=atan2(hy[0]*1.0-hy[4]*1.0,hx[0]*1.0-hx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[0]-hx[4])*(hx[0]-hx[4])+(hy[0]-hy[4])*(hy[0]-hy[4]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2+azi[1]+azi[2];
            hx[0]=hx[4]+dist*cos(roll)+segings[5].dh*s1;
            hy[0]=hy[4]+dist*sin(roll);

            roll=atan2(hy[1]*1.0-hy[4]*1.0,hx[1]*1.0-hx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[1]-hx[4])*(hx[1]-hx[4])+(hy[1]-hy[4])*(hy[1]-hy[4]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2+azi[1]+azi[2];
            hx[1]=hx[4]+dist*cos(roll)+segings[5].dh*s1;
            hy[1]=hy[4]+dist*sin(roll);

            roll=atan2(hy[2]*1.0-hy[4]*1.0,hx[2]*1.0-hx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[2]-hx[4])*(hx[2]-hx[4])+(hy[2]-hy[4])*(hy[2]-hy[4]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2+azi[1]+azi[2];
            hx[2]=hx[4]+dist*cos(roll)+segings[5].dh*s1;
            hy[2]=hy[4]+dist*sin(roll);

            roll=atan2(hy[3]*1.0-hy[4]*1.0,hx[3]*1.0-hx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[3]-hx[4])*(hx[3]-hx[4])+(hy[3]-hy[4])*(hy[3]-hy[4]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2+azi[1]+azi[2];
            hx[3]=hx[4]+dist*cos(roll)+segings[5].dh*s1;
            hy[3]=hy[4]+dist*sin(roll);

            //垂直
            roll=atan2(vy[0]*1.0-vy[4]*1.0,vx[0]*1.0-vx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[0]-vx[4])*(vx[0]-vx[4])+(vy[0]-vy[4])*(vy[0]-vy[4]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2+pitch[1]-pitch[2];
            vx[0]=vx[4]+dist*cos(roll);
            vy[0]=vy[4]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[1]*1.0-vy[4]*1.0,vx[1]*1.0-vx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[1]-vx[4])*(vx[1]-vx[4])+(vy[1]-vy[4])*(vy[1]-vy[4]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2+pitch[1]-pitch[2];
            vx[1]=vx[4]+dist*cos(roll);
            vy[1]=vy[4]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[2]*1.0-vy[4]*1.0,vx[2]*1.0-vx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[2]-vx[4])*(vx[2]-vx[4])+(vy[2]-vy[4])*(vy[2]-vy[4]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2+pitch[1]-pitch[2];
            vx[2]=vx[4]+dist*cos(roll);
            vy[2]=vy[4]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[3]*1.0-vy[4]*1.0,vx[3]*1.0-vx[4]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[3]-vx[4])*(vx[3]-vx[4])+(vy[3]-vy[4])*(vy[3]-vy[4]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2+pitch[1]-pitch[2];
            vx[3]=vx[4]+dist*cos(roll);
            vy[3]=vy[4]+dist*sin(roll)-segings[5].dv*s1;

            //画上环
            roll=atan2(hy[6]*1.0-hy[11]*1.0,hx[6]*1.0-hx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[11]-hx[6])*(hx[11]-hx[6])+(hy[11]-hy[6])*(hy[11]-hy[6]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2;
            hx[6]=hx[11]+dist*cos(roll)+segings[5].dh*s1;
            hy[6]=hy[11]+dist*sin(roll);

            roll=atan2(hy[7]*1.0-hy[11]*1.0,hx[7]*1.0-hx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[11]-hx[7])*(hx[11]-hx[7])+(hy[11]-hy[7])*(hy[11]-hy[7]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2;
            hx[7]=hx[11]+dist*cos(roll)+segings[5].dh*s1;
            hy[7]=hy[11]+dist*sin(roll);

            roll=atan2(hy[8]*1.0-hy[11]*1.0,hx[8]*1.0-hx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[11]-hx[8])*(hx[11]-hx[8])+(hy[11]-hy[8])*(hy[11]-hy[8]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2;
            hx[8]=hx[11]+dist*cos(roll)+segings[5].dh*s1;
            hy[8]=hy[11]+dist*sin(roll);

            roll=atan2(hy[9]*1.0-hy[11]*1.0,hx[9]*1.0-hx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(hx[11]-hx[9])*(hx[11]-hx[9])+(hy[11]-hy[9])*(hy[11]-hy[9]);
            dist=sqrt(dist);
            roll=roll+azi[0]*s2;
            hx[9]=hx[11]+dist*cos(roll)+segings[5].dh*s1;
            hy[9]=hy[11]+dist*sin(roll);

            //垂直
            roll=atan2(vy[6]*1.0-vy[11]*1.0,vx[6]*1.0-vx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[11]-vx[6])*(vx[11]-vx[6])+(vy[11]-vy[6])*(vy[11]-vy[6]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2;
            vx[6]=vx[11]+dist*cos(roll);
            vy[6]=vy[11]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[7]*1.0-vy[11]*1.0,vx[7]*1.0-vx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[11]-vx[7])*(vx[11]-vx[7])+(vy[11]-vy[7])*(vy[11]-vy[7]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2;
            vx[7]=vx[11]+dist*cos(roll);
            vy[7]=vy[11]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[8]*1.0-vy[11]*1.0,vx[8]*1.0-vx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[11]-vx[8])*(vx[11]-vx[8])+(vy[11]-vy[8])*(vy[11]-vy[8]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2;
            vx[8]=vx[11]+dist*cos(roll);
            vy[8]=vy[11]+dist*sin(roll)-segings[5].dv*s1;

            roll=atan2(vy[9]*1.0-vy[11]*1.0,vx[9]*1.0-vx[11]*1.0);
            if(roll<0.0) roll=roll+2.0*PI;
            dist=(vx[11]-vx[9])*(vx[11]-vx[9])+(vy[11]-vy[9])*(vy[11]-vy[9]);
            dist=sqrt(dist);
            roll=roll-pitch[0]*s2;
            vx[9]=vx[11]+dist*cos(roll);
            vy[9]=vy[11]+dist*sin(roll)-segings[5].dv*s1;


            memDC.SetPen(wxPen(wxColor(168,168,168)));
            memDC.DrawLine(hx[6],hy[6],hx[7],hy[7]);
            memDC.DrawLine(hx[7],hy[7],hx[8],hy[8]);
            memDC.DrawLine(hx[8],hy[8],hx[9],hy[9]);
            memDC.DrawLine(hx[9],hy[9],hx[6],hy[6]);

            memDC.DrawLine(vx[6],vy[6],vx[7],vy[7]);
            memDC.DrawLine(vx[7],vy[7],vx[8],vy[8]);
            memDC.DrawLine(vx[8],vy[8],vx[9],vy[9]);
            memDC.DrawLine(vx[9],vy[9],vx[6],vy[6]);

            memDC.SetPen(wxPen(wxColor(0,50,200)));
            memDC.DrawLine(hx[0],hy[0],hx[1],hy[1]);
            memDC.DrawLine(hx[1],hy[1],hx[2],hy[2]);
            memDC.DrawLine(hx[2],hy[2],hx[3],hy[3]);
            memDC.DrawLine(hx[3],hy[3],hx[0],hy[0]);

            memDC.DrawLine(vx[0],vy[0],vx[1],vy[1]);
            memDC.DrawLine(vx[1],vy[1],vx[2],vy[2]);
            memDC.DrawLine(vx[2],vy[2],vx[3],vy[3]);
            memDC.DrawLine(vx[3],vy[3],vx[0],vy[0]);

            //fclose(fp);
        }

        memDC.SetPen(wxPen(wxColor(118,118,118)));
        x2=w/2+radius;
        x2=x2+(w-x2)/2-15;
        y2=y1-radius/2;
        memDC.DrawRoundedRectangle(x2-w1/5-3,y2-40,w1*2/5+6,25,3);
        demo_uaj_Text->SetSize(x2-w1/5,y2-35,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2-w1/5-3,y2+35,w1*2/5+6,25,3);
        demo_daj_Text->SetSize(x2-w1/5,y2+40,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2-w1*2/5-28,y2,w1*2/5+6,25,3);
        demo_laj_Text->SetSize(x2-w1*2/5-25,y2+5,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2+22,y2,w1*2/5+6,25,3);
        demo_raj_Text->SetSize(x2+25,y2+5,w1*2/5,18);
        memDC.DrawLabel(_("推进油缸行程[ mm ]"),wxRect(x2,y2-55,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("上"),wxRect(x2,y2-10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(_("下"),wxRect(x2,y2+30,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
        memDC.DrawLabel(_("左"),wxRect(x2-20,y2+9,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("右"),wxRect(x2+20,y2+9,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        y2=y1+radius/2;
        memDC.DrawRoundedRectangle(x2-w1/5-3,y2-35,w1*2/5+6,25,3);
        demo_ugap_Text->SetSize(x2-w1/5,y2-30,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2-w1/5-3,y2+30,w1*2/5+6,25,3);
        demo_dgap_Text->SetSize(x2-w1/5,y2+35,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2-w1*2/5-28,y2,w1*2/5+6,25,3);
        demo_lgap_Text->SetSize(x2-w1*2/5-25,y2+5,w1*2/5,18);
        memDC.DrawRoundedRectangle(x2+22,y2,w1*2/5+6,25,3);
        demo_rgap_Text->SetSize(x2+25,y2+5,w1*2/5,18);
        memDC.DrawLabel(_("盾尾间隙[ mm ]"),wxRect(x2,y2-50,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("上"),wxRect(x2,y2-10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(_("下"),wxRect(x2,y2+30,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
        memDC.DrawLabel(_("左"),wxRect(x2-20,y2+9,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("右"),wxRect(x2+20,y2+9,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        x2=x2-w1/2;
        y2=y1+radius+15;
        memDC.DrawRoundedRectangle(x2,y2,w1,25,3);
        demo_dh_Text->SetSize(x2+3,y2+5,w1-6,18);
        memDC.DrawLabel(_("经验沉降值[ mm ]"),wxRect(x2,y2-15,w1,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x2=15;
        y2=y1+radius*2/3;
        memDC.DrawLabel(_("盾构平面姿态[ mm ]"),wxRect(x2,y2-15,w1,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawRoundedRectangle(x2+38,y2,w1*2/3,25,3);
        demo_headh_Text->SetSize(x2+41,y2+5,w1*2/3-6,18);
        memDC.DrawLabel(_("切口"),wxRect(x2,y2,w1,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y2+=32;
        memDC.DrawRoundedRectangle(x2+38,y2,w1*2/3,25,3);
        demo_tailh_Text->SetSize(x2+41,y2+5,w1*2/3-6,18);
        memDC.DrawLabel(_("盾尾"),wxRect(x2,y2,w1,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y2+=62;
        memDC.DrawLabel(_("盾构垂直姿态[ mm ]"),wxRect(x2,y2-15,w1,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawRoundedRectangle(x2+38,y2,w1*2/3,25,3);
        demo_headv_Text->SetSize(x2+41,y2+5,w1*2/3-6,18);
        memDC.DrawLabel(_("切口"),wxRect(x2,y2,w1,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y2+=32;
        memDC.DrawRoundedRectangle(x2+38,y2,w1*2/3,25,3);
        demo_tailv_Text->SetSize(x2+41,y2+5,w1*2/3-6,18);
        memDC.DrawLabel(_("盾尾"),wxRect(x2,y2,w1,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);


        if(cli->nblk>0)
        {
            w1=60;
            h1=25;
            x2=x1-w1*3/2;
            y2=y1-radius/2-h1/3;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            //memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            memDC.SetBrush(btnBrush[0]);
            memDC.DrawRectangle(x2,y2,w1*3+1,h1);

            segButton[ID_SEGMENT_TYPE_TL].x=x2+1;
            segButton[ID_SEGMENT_TYPE_TL].y=y2+1;
            segButton[ID_SEGMENT_TYPE_TL].width=w1-1;
            segButton[ID_SEGMENT_TYPE_TL].height=h1-2;
            if(cli->segset.type==0)
            {
                memDC.SetTextForeground(wxColor(198,198,198));
                memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            }
            else
            {
                if(segings[5].type==2)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_TL)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_TL)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_TL]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawLine(x2+w1,y2,x2+w1,y2+h1);
            memDC.DrawLabel(_("左转弯"),segButton[ID_SEGMENT_TYPE_TL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            x2=x2+w1;
            segButton[ID_SEGMENT_TYPE_STD].x=x2+1;
            segButton[ID_SEGMENT_TYPE_STD].y=y2+1;
            segButton[ID_SEGMENT_TYPE_STD].width=w1-1;
            segButton[ID_SEGMENT_TYPE_STD].height=h1-2;
            //cli->segset.type=1;
            if(cli->segset.type==0)
            {
                //memDC.SetTextForeground(wxColor(118,118,118));
                memDC.SetTextForeground(wxColor(198,198,198));
                memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            }
            else
            {
                if(segings[5].type==1)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_STD)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_STD)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_STD]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawLine(x2+w1,y2,x2+w1,y2+h1);
            memDC.DrawLabel(_("标准环"),segButton[ID_SEGMENT_TYPE_STD],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            x2=x2+w1;
            segButton[ID_SEGMENT_TYPE_TR].x=x2+1;
            segButton[ID_SEGMENT_TYPE_TR].y=y2+1;
            segButton[ID_SEGMENT_TYPE_TR].width=w1-1;
            segButton[ID_SEGMENT_TYPE_TR].height=h1-2;
            //cli->segset.type=1;
            if(cli->segset.type==0)
            {
                memDC.SetTextForeground(wxColor(198,198,198));
                memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            }
            else
            {
                if(segings[5].type==3)
                {
                    memDC.SetTextForeground(btnTextColor[1]);
                    if(motion==ID_SEGMENT_TYPE_TR)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
                        memDC.SetBrush(btnBrush[2]);
                    }
                }
                else
                {
                    if(motion==ID_SEGMENT_TYPE_TR)
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
                        memDC.SetBrush(btnBrush[1]);
                        memDC.SetTextForeground(btnTextColor[1]);
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
                        memDC.SetBrush(btnBrush[0]);
                        memDC.SetTextForeground(btnTextColor[0]);
                    }
                }
            }
            memDC.DrawRectangle(segButton[ID_SEGMENT_TYPE_TR]);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            //memDC.DrawLine(x1+w1,y1+3,x1+w1,y1+h1-3);
            memDC.DrawLabel(_("右转弯"),segButton[ID_SEGMENT_TYPE_TR],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            x2=x1-w1*3/2;
            y2=y1+radius/2-h1*2/3;
            segButton[ID_SEGMENT_LASTH].x=x2;
            segButton[ID_SEGMENT_LASTH].y=y2;
            segButton[ID_SEGMENT_LASTH].width=w1;
            segButton[ID_SEGMENT_LASTH].height=h1;
            if(motion==ID_SEGMENT_LASTH)
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
            memDC.DrawRoundedRectangle(segButton[ID_SEGMENT_LASTH],3);
            memDC.DrawLabel(_("上一环"),segButton[ID_SEGMENT_LASTH],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            x2=x2+w1*2;
            segButton[ID_SEGMENT_SEGH].x=x2;
            segButton[ID_SEGMENT_SEGH].y=y2;
            segButton[ID_SEGMENT_SEGH].width=w1;
            segButton[ID_SEGMENT_SEGH].height=h1;
            if(motion==ID_SEGMENT_SEGH)
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
            memDC.DrawRoundedRectangle(segButton[ID_SEGMENT_SEGH],3);
            memDC.DrawLabel(_("上一环"),segButton[ID_SEGMENT_SEGH],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentDlg::OnMotionDemo(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int n=cli->segset.Ks;
    double r;
    for(int i=0;i<n+3;i++)
    {
        r=(x-segButton[ID_SEGMENT_COUNT+i].x)*(x-segButton[ID_SEGMENT_COUNT+i].x)+(y-segButton[ID_SEGMENT_COUNT+i].y)*(y-segButton[ID_SEGMENT_COUNT+i].y);
        r=sqrt(r);
        if(r<segButton[ID_SEGMENT_COUNT+i].width)
        {
            motion=ID_SEGMENT_COUNT+i;
            break;
        }
        else
        {
            motion=ID_SEGMENT_NONE;
        }
    }
    if(motion==ID_SEGMENT_NONE)
    {
        if(y>segButton[ID_SEGMENT_TYPE_TL].y && y<segButton[ID_SEGMENT_TYPE_TL].y+segButton[ID_SEGMENT_TYPE_TL].height)
        {
            if(x>segButton[ID_SEGMENT_TYPE_TL].x && x<segButton[ID_SEGMENT_TYPE_TL].x+segButton[ID_SEGMENT_TYPE_TL].width)
            {
                motion=ID_SEGMENT_TYPE_TL;
            }
            else if(x>segButton[ID_SEGMENT_TYPE_TR].x && x<segButton[ID_SEGMENT_TYPE_TR].x+segButton[ID_SEGMENT_TYPE_TR].width)
            {
                motion=ID_SEGMENT_TYPE_TR;
            }
            else if(x>segButton[ID_SEGMENT_TYPE_STD].x && x<segButton[ID_SEGMENT_TYPE_STD].x+segButton[ID_SEGMENT_TYPE_STD].width)
            {
                motion=ID_SEGMENT_TYPE_STD;
            }
            else
            {
                motion=ID_SEGMENT_NONE;
            }
        }
        else if(y>segButton[ID_SEGMENT_LASTH].y && y<segButton[ID_SEGMENT_LASTH].y+segButton[ID_SEGMENT_LASTH].height)
        {
            if(x>segButton[ID_SEGMENT_LASTH].x && x<segButton[ID_SEGMENT_LASTH].x+segButton[ID_SEGMENT_LASTH].width)
            {
                motion=ID_SEGMENT_LASTH;
            }
            else if(x>segButton[ID_SEGMENT_SEGH].x && x<segButton[ID_SEGMENT_SEGH].x+segButton[ID_SEGMENT_SEGH].width)
            {
                motion=ID_SEGMENT_SEGH;
            }
            else
            {
                motion=ID_SEGMENT_NONE;
            }
        }
        else
        {
            motion=ID_SEGMENT_NONE;
        }
    }

    panelFigDemo->Refresh();
}

void SegmentDlg::OnLeaveDemo(wxMouseEvent& event)
{
    motion=ID_SEGMENT_NONE;
    panelFigDemo->Refresh();
}

void SegmentDlg::OnClickDemo(wxMouseEvent& event)
{
    int n=cli->segset.Ks;
    for(int i=0;i<n;i++)
    {
        if(motion==ID_SEGMENT_COUNT+i)
        {
            if(i==0)
            {
                segings[5].kpos=n;
                //mtg_kpos_off(cli,&segings[5]);
            }
            else
            {
                segings[5].kpos=i;
                //mtg_kpos_off(cli,&segings[5]);
            }
        }
    }

    if(motion==ID_SEGMENT_TYPE_TL)
    {
        segings[5].type=2;
        //mtg_kpos_off(cli,&segings[5]);
    }
    else if(motion==ID_SEGMENT_TYPE_TR)
    {
        segings[5].type=3;
        //mtg_kpos_off(cli,&segings[5]);
    }
    else if(motion==ID_SEGMENT_TYPE_STD)
    {
        segings[5].type=1;
        //mtg_kpos_off(cli,&segings[5]);
    }

    panelFigDemo->Refresh();
}

void SegmentDlg::OnPaintDemoList(wxPaintEvent& event)
{
    wxPaintDC dc(panelDemoList);
    int w,h;
    panelDemoList->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs1(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont chs2(15,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs1);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=40;
        memDC.SetTextForeground(wxColor(68,68,68));
        memDC.DrawLine(x1,h1,w1,h1);
        w1=gridDemo->GetColSize(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridDemo->GetColSize(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridDemo->GetColSize(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridDemo->GetColSize(3);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("拼装点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridDemo->GetColSize(4);
        w1=w1+gridDemo->GetColSize(5);
        memDC.DrawLine(x1,y1+h1/2,x1+w1,y1+h1/2);
        memDC.DrawLabel(_("偏差[ mm ]"),wxRect(x1,y1,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1/2,y1+h1/2,x1+w1/2,h1);
        memDC.DrawLabel(_("水平"),wxRect(x1,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("垂直"),wxRect(x1+w1/2,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=gridDemo->GetColSize(6);
        w1=w1+gridDemo->GetColSize(7);
        memDC.DrawLine(x1,y1+h1/2,x1+w1,y1+h1/2);
        memDC.DrawLabel(_("超前量[ mm ]"),wxRect(x1,y1,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1/2,y1+h1/2,x1+w1/2,h1);
        memDC.DrawLabel(_("水平"),wxRect(x1,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+w1,y1,x1+w1,h1);
        memDC.DrawLabel(_("垂直"),wxRect(x1+w1/2,y1+h1/2,w1/2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentDlg::OnPaintBottom(wxPaintEvent& event)
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

        w1=65;
        h1=26;
        x1=w-w1-12;
        y1=9;
        segButton[ID_SEGMENT_BTN_QUIT].x=x1;
        segButton[ID_SEGMENT_BTN_QUIT].y=y1;
        segButton[ID_SEGMENT_BTN_QUIT].width=w1;
        segButton[ID_SEGMENT_BTN_QUIT].height=h1;
        if(motion==ID_SEGMENT_BTN_QUIT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(btnTextColor[0]);
        }
        //memDC.SetPen(wxPen(wxColor(117,117,117)));

        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("退出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1-w1-7;
        segButton[ID_SEGMENT_BTN_APPLY].x=x1;
        segButton[ID_SEGMENT_BTN_APPLY].y=y1;
        segButton[ID_SEGMENT_BTN_APPLY].width=w1;
        segButton[ID_SEGMENT_BTN_APPLY].height=h1;
        if(motion==ID_SEGMENT_BTN_APPLY)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("应用"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        panelButtonList->GetSize(&w1,0);
        x1=w1+14;
        w1=w-x1*2;
        if(Mtype==0)
        {
            memDC.SetTextForeground(wxColor(0,0,255));
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,0,0));
        }
        if(Msg!=wxEmptyString) memDC.DrawLabel(_(" ！ ")+Msg,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>segButton[ID_SEGMENT_BTN_QUIT].y && y<segButton[ID_SEGMENT_BTN_QUIT].y+segButton[ID_SEGMENT_BTN_QUIT].height)
    {
        if(x>segButton[ID_SEGMENT_BTN_QUIT].x && x<segButton[ID_SEGMENT_BTN_QUIT].x+segButton[ID_SEGMENT_BTN_QUIT].width)
        {
            motion=ID_SEGMENT_BTN_QUIT;
        }
        else if(x>segButton[ID_SEGMENT_BTN_APPLY].x && x<segButton[ID_SEGMENT_BTN_APPLY].x+segButton[ID_SEGMENT_BTN_APPLY].width)
        {
            motion=ID_SEGMENT_BTN_APPLY;
        }
        else
        {
            motion=ID_SEGMENT_NONE;
        }
    }
    else
    {
        motion=ID_SEGMENT_NONE;
    }
    panelBottom->Refresh();
}

void SegmentDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_SEGMENT_NONE;
    panelBottom->Refresh();
}

void SegmentDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_SEGMENT_BTN_QUIT)
    {
        Destroy();
    }
    else if(motion==ID_SEGMENT_BTN_APPLY)
    {
        for(int i=0;i<40;i++)
        {
            cli->segs[i]=segings[i];
        }
    }
}

void SegmentDlg::WriteMsg(wxString msg,int col)
{
    Msg=msg;
    Mtype=col;
    panelBottom->Refresh();
}

void SegmentDlg::LoadData()
{
    int n=cli->segset.Ks;
    ///预测管环初始化
    segings[4].numb=cli->m1.iseg;
    for(int i=0;i<cli->ns;i++)
    {
        segings[i]=cli->segs[i];
        if(segings[i].kpos==0) segings[i].kpos=n;
        if(cli->segset.type==1)
        {
            segings[i].type=1;
        }
        else
        {
            segings[i].type=0;
        }
        if(i>4)
        {
            segings[i].numb=segings[i-1].numb+1;
        }
    }

    if(segings[4].t==0)
    {
        id=4;
    }
    else
    {
        id=5;
    }

    MTG_SEG seg0={0};
    for(int i=0;i<2500;i++)
    {
        segs[i]=seg0;
        if(cli->segset.type==1)
        {
            segs[i].type=1;
        }
        else
        {
            segs[i].type=0;
        }
        segs[i].kpos=n;
    }

    //mtg_seg_init(cli);
}

void SegmentDlg::OnPaintBackground(wxPaintEvent& event)
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


void SegmentDlg::OnPaintNavi(wxPaintEvent& event)
{
    wxPaintDC dc(panelNavi);
    int w,h;
    panelNavi->GetClientSize(&w,&h);

    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(0,-1,w,h+1);
}

