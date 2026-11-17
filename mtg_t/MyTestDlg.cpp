///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyTestDlg.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"
#include "confirmdlg.h"
#include "SegDialog.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>

#include <wx/stdpaths.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MyTestDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MyTestDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MyTestDlg)
const long MyTestDlg::ID_PANEL1 = wxNewId();        //主panel
const long MyTestDlg::ID_PANEL2 = wxNewId();        //历史数据
const long MyTestDlg::ID_PANEL3 = wxNewId();        //详细数据
const long MyTestDlg::ID_PANEL4 = wxNewId();        //设站定向
const long MyTestDlg::ID_PANEL5 = wxNewId();        //换站前
const long MyTestDlg::ID_PANEL6 = wxNewId();        //详细历史数据
const long MyTestDlg::ID_PANEL7 = wxNewId();        //环号测试

const long MyTestDlg::ID_BUTTON1 = wxNewId();                 //退出
const long MyTestDlg::ID_BUTTON2 = wxNewId();                 //查询
const long MyTestDlg::ID_BUTTON3 = wxNewId();                 //详细
const long MyTestDlg::ID_BUTTON4 = wxNewId();                 //报表

const long MyTestDlg::ID_BUTTON5 = wxNewId();                 //管环-顶
const long MyTestDlg::ID_BUTTON6 = wxNewId();                 //管环-上
const long MyTestDlg::ID_BUTTON7 = wxNewId();                 //管环-下
const long MyTestDlg::ID_BUTTON8 = wxNewId();                 //管环-底

const long MyTestDlg::ID_BUTTON9 = wxNewId();                 //详细-顶
const long MyTestDlg::ID_BUTTON10 = wxNewId();                 //详细-上
const long MyTestDlg::ID_BUTTON11 = wxNewId();                 //详细-下
const long MyTestDlg::ID_BUTTON12 = wxNewId();                 //详细-底

const long MyTestDlg::ID_BUTTON13 = wxNewId();                 //掘进
const long MyTestDlg::ID_BUTTON14 = wxNewId();                 //停止
const long MyTestDlg::ID_BUTTON15 = wxNewId();                 //速度1
const long MyTestDlg::ID_BUTTON16 = wxNewId();                 //速度2
const long MyTestDlg::ID_BUTTON17 = wxNewId();                 //速度3
const long MyTestDlg::ID_BUTTON18 = wxNewId();                 //速度4
const long MyTestDlg::ID_BUTTON19 = wxNewId();                 //零位测量
const long MyTestDlg::ID_LIST1 = wxNewId();                        //管环类型
//*)

MyTestDlg::MyTestDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelMain = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("ID_PANEL1"));

    m_notebook = new wxNotebook( panelMain, wxID_ANY, wxPoint(5,5), wxSize( w-10,480 ), 0 );
    m_panelHistory = new wxPanel( m_notebook, ID_PANEL2, wxPoint(5,5), wxSize( w-10,480 ), wxTAB_TRAVERSAL );
    //m_gridHistory = new wxMyGrid( m_panelHistory, wxID_ANY, wxPoint(5,5), wxSize( w-30,428 ), 0 );
	btnStart = new wxButton(m_panelHistory, ID_BUTTON13, _("掘进"), wxPoint(25,25), wxSize(72,-1), 0, wxDefaultValidator, _T("ID_BUTTON13"));
	btnStop = new wxButton(m_panelHistory, ID_BUTTON14, _("停止"), wxPoint(110,25), wxSize(72,-1), 0, wxDefaultValidator, _T("ID_BUTTON14"));
	btnV1 = new wxButton(m_panelHistory, ID_BUTTON15, _("速度1"), wxPoint(195,25), wxSize(72,-1), 0, wxDefaultValidator, _T("ID_BUTTON15"));
	btnV2 = new wxButton(m_panelHistory, ID_BUTTON16, _("速度2"), wxPoint(280,25), wxSize(72,-1), 0, wxDefaultValidator, _T("ID_BUTTON16"));
	btnV3 = new wxButton(m_panelHistory, ID_BUTTON17, _("速度3"), wxPoint(365,25), wxSize(72,-1), 0, wxDefaultValidator, _T("ID_BUTTON17"));
	btnInit = new wxButton(m_panelHistory, ID_BUTTON18, _("初始化"), wxPoint(450,25), wxSize(72,-1), 0, wxDefaultValidator, _T("ID_BUTTON18"));

    m_panelNums = new wxPanel( m_panelHistory, ID_PANEL7, wxPoint(25,75), wxSize( w-50,320 ), wxTAB_TRAVERSAL );

    m_panelNums->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    m_panelNums->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyTestDlg::OnPaintNums,0,this);
	m_panelHistory->Layout();

    m_notebook->AddPage( m_panelHistory, wxT("环号测试"), true );

    m_panelDetail = new wxPanel( m_notebook, ID_PANEL3, wxPoint(5,5), wxSize( w-10,480 ), wxTAB_TRAVERSAL );
    //m_gridSegData = new wxMyGrid( m_panelDetail, wxID_ANY, wxPoint(5,5), wxSize( w-30,388 ), 0 );
    //wxStaticBoxSizer* sbSizer3;
    //sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( m_panelDetail, wxID_ANY, wxT("选择环号"),wxPoint(5,385),wxSize(150,55) ), wxHORIZONTAL );

    //wxStaticBoxSizer* sbSizer4;
    //sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panelDetail, wxID_ANY, wxT("数据选项"),wxPoint(180,385),wxSize(w-210,55) ), wxHORIZONTAL );
    //m_staticSegResult = new wxStaticText( m_panelDetail, wxID_ANY, wxT("本环测量记录 0 条"), wxPoint(195,410), wxDefaultSize, 0 );

    //m_textSegView = new wxMyTextCtrl( m_panelDetail, wxID_ANY, wxEmptyString, wxPoint(435,405), wxSize(80,-1), 0 );
    //m_staticViewMethod = new wxStaticText( m_panelDetail, wxID_ANY, wxT("查看方式"), wxPoint(540,410), wxDefaultSize, 0 );
    //methodChoice = new wxChoice(m_panelDetail, wxID_ANY, wxPoint(600,405), wxSize(80,-1), 0, 0, 0, wxDefaultValidator);
    //methodChoice->SetSelection(methodChoice->Append(_("均分距离")) );
    //methodChoice->Append(_("均分记录"));
    btnSegTop = new wxButton(m_panelDetail, ID_BUTTON5, _("|<"), wxPoint(5,405), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    btnSegPre = new wxButton(m_panelDetail, ID_BUTTON6, _("<<"), wxPoint(79,405), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    btnSegNext = new wxButton(m_panelDetail, ID_BUTTON7, _(">>"), wxPoint(w-30-72-2-72,405), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    btnSegBottom = new wxButton(m_panelDetail, ID_BUTTON8, _(">|"), wxPoint(w-30-72,405), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON8"));
    btnOrigin = new wxButton(m_panelDetail, ID_BUTTON19, _("零位计算"), wxPoint(5,60), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON19"));
    m_textSegPage = new wxMyTextCtrl( m_panelDetail, wxID_ANY, wxEmptyString, wxPoint(153,406), wxSize(461,26), wxTE_CENTER  );
    m_textSegPage->Enable(false);
    m_panelDetail->Layout();
    m_notebook->AddPage( m_panelDetail, wxT("管环详细查看"), false );

    m_panelDetails = new wxPanel( m_notebook, ID_PANEL6, wxPoint(5,5), wxSize( w-10,480 ), wxTAB_TRAVERSAL );
    m_gridDetails = new wxMyGrid( m_panelDetails, wxID_ANY, wxPoint(5,5), wxSize( w-30,388 ), 0 );
    btnDtsTop = new wxButton(m_panelDetails, ID_BUTTON9, _("|<"), wxPoint(5,405), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON9"));
    btnDtsPre = new wxButton(m_panelDetails, ID_BUTTON10, _("<<"), wxPoint(79,405), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON10"));
    btnDtsNext = new wxButton(m_panelDetails, ID_BUTTON11, _(">>"), wxPoint(w-30-72-2-72,405), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON11"));
    btnDtsBottom = new wxButton(m_panelDetails, ID_BUTTON12, _(">|"), wxPoint(w-30-72,405), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON12"));


    m_textDtsPage = new wxMyTextCtrl( m_panelDetails, wxID_ANY, wxEmptyString, wxPoint(153,406), wxSize(461,26), wxTE_CENTER  );
    m_textDtsPage->Enable(false);
    m_panelDetails->Layout();
    m_notebook->AddPage( m_panelDetails, wxT("历史测量记录"), false );

    m_panelSetup = new wxPanel( m_notebook, ID_PANEL4, wxPoint(5,5), wxSize( w-10,480 ), wxTAB_TRAVERSAL );
    //listSets = new wxListView(m_panelSetup,wxID_ANY,wxPoint(5,5),wxSize(120,420),wxLC_REPORT, wxDefaultValidator);
    listSets = new wxListView(m_panelSetup,ID_LIST1,wxPoint(5,5),wxSize(120,420),wxLC_REPORT, wxDefaultValidator,_T("ID_LIST1"));
    listSets->InsertColumn(0,_("设站定向"),wxLIST_FORMAT_CENTER,90);
    m_panelSet = new wxPanel( m_panelSetup, ID_PANEL5, wxPoint(140,5), wxSize( w-180,420 ), wxTAB_TRAVERSAL );
    m_panelSet->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    m_panelSetup->Layout();
    m_notebook->AddPage( m_panelSetup, wxT("设站定向记录"), false );

    wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( panelMain, wxID_ANY, wxT("查询环号设置"),wxPoint(5,490),wxSize(260,60) ), wxHORIZONTAL );
    m_staticFrom = new wxStaticText( panelMain, wxID_ANY, wxT("环号："), wxPoint(15,520),wxDefaultSize, 0 );
	m_textFrom = new wxMyTextCtrl( panelMain, wxID_ANY, wxEmptyString, wxPoint(55,515), wxSize(80,-1), 0 );
	m_staticTo = new wxStaticText( panelMain, wxID_ANY, wxT("到"), wxPoint(145,520), wxDefaultSize, 0 );
	m_textTo = new wxMyTextCtrl( panelMain, wxID_ANY, wxEmptyString, wxPoint(170,515), wxSize(80,-1), 0 );

    m_staticSeg = new wxStaticText( panelMain, wxID_ANY, wxT("环号："), wxPoint(285,520), wxDefaultSize, 0 );
    segChoice = new wxChoice(panelMain, wxID_ANY, wxPoint(325,515), wxSize(80,-1), 0, 0, 0, wxDefaultValidator);

    wxStaticBoxSizer* sbSizer2;
    sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( panelMain, wxID_ANY, wxT("选择环号"),wxPoint(270,490),wxSize(150,60) ), wxHORIZONTAL );
    m_staticMessage = new wxStaticText( panelMain, wxID_ANY, wxT(""), wxPoint(440,520), wxDefaultSize, 0 );

    //listSets->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&MyTestDlg::OnListSetsItemSelect);
    Connect(ID_LIST1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&MyTestDlg::OnListSetsItemSelect);
    m_panelSet->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyTestDlg::OnPaintSet,0,this);
    //Connect(ID_CHOICE5,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MyTestDlg::OnLangSelect);
    btnQuit = new wxButton(panelMain, ID_BUTTON1, _("退 出"), wxPoint(715,512), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btnQuery = new wxButton(panelMain, ID_BUTTON2, _("查 询"), wxPoint(551,512), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    //btnDetail = new wxButton(panelMain, ID_BUTTON3, _("详 细"), wxPoint(520,512), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btnReport = new wxButton(panelMain, ID_BUTTON4, _("报 表"), wxPoint(633,512), wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    segChoice->Connect(wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MyTestDlg::OnSegSelect,NULL,this);
    //m_notebook->Connect(wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&MyTestDlg::OnPageChanged,NULL,this);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnBtnQuit);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnBtnQuery);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnReport);

    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnSegTop);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnSegPre);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnSegNext);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnSegBottom);

    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnDtsTop);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnDtsPre);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnDtsNext);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnDtsBottom);

    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnStart);
    Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnStop);
    Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnBtnV1);
    Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnBtnV2);
    Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnBtnV3);
    Connect(ID_BUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnInitial);
    Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyTestDlg::OnOrigin);

    //*)

    Connect(wxEVT_TIMER,(wxObjectEventFunction)&MyTestDlg::OnTestTimer);
    timerTestStat.SetOwner(this);
    timerTestStat.Start(100,false);
    //m_textFrom->SetValue(wxString::Format(_("%d"),cli->seg1.numb+1));
    //m_textTo->SetValue(wxString::Format(_("%d"),cli->seg1.numb-5));
    seg_page = 0;
    dts_page = 0;
    nres1 = 0;
    nres2 = 0;
    nres3 = 0;

    qres1 = 0;
    qres2 = 0;
    qres3 = 0;

    ///速度
    ds1=0.0;
    ds2=-1.0;
    ds3=0;

    is_save_set = -1;
    m_textFrom->SetValue(wxString::Format(_("%d"),cli->m1.iseg-6));
    m_textTo->SetValue(wxString::Format(_("%d"),cli->m1.iseg));
    InitMyGrid();
    InitSegGrid();
    InitDetailsGrid();
    UpdateSets();
    listSets->Select(cli->nstn-1);

    segChoice->SetSelection( segChoice->Append(wxString::Format(_("%d"),cli->m1.iseg)));
    segChoice->Append(wxString::Format(_("%d"),cli->m1.iseg-1));
    segChoice->Append(wxString::Format(_("%d"),cli->m1.iseg-2));
    segChoice->Append(wxString::Format(_("%d"),cli->m1.iseg-3));
    segChoice->Append(wxString::Format(_("%d"),cli->m1.iseg-4));
    segChoice->Append(wxString::Format(_("%d"),cli->m1.iseg-5));
    segChoice->Append(wxString::Format(_("%d"),cli->m1.iseg-6));
    cli->m1.headc = 24360.3649;
    //wxCommandEvent e;
    //OnSegSelect(e);
}

MyTestDlg::~MyTestDlg()
{

}

void MyTestDlg::OnOrigin(wxCommandEvent& event)
{
    cli->m = cli->m0;
    wxMessageBox(wxString::Format(_("%.12f"),cli->azi[0]));
}

void MyTestDlg::OnTestTimer(wxTimerEvent& event)
{
    ///log
    /*static int tick=0;
    int n;
    double v = 0.0;
    time_t now;

    FILE* fp = fopen("E:\\TestNum.log","a");
    tick++;
    ///关键区域，5秒更新
    if(tick % 50==0)
    {
        if(ds2>-1.0)
        {
            cli->m.headc = cli->m1.headc-ds2;
            time(&now);
            cli->m.t1=now;
            ds2 = -1.0;
        }
        else
        {
            cli->m.headc = cli->m1.headc-ds1;
            time(&now);
            cli->m.t1=now;
        }
        fprintf(fp,"headc:%.4f\n",cli->m.headc);
        mtg_cal_snum(cli);
        cli->m1.headc = cli->m.headc;
        cli->m1.t1 = cli->m.t1;
        m_panelNums->Refresh();
    }

    fclose(fp);*/
}

void MyTestDlg::OnStart(wxCommandEvent& event)
{
    ds1 = 0.01;
}

void MyTestDlg::OnStop(wxCommandEvent& event)
{
    ds1 = 0.0;
}

void MyTestDlg::OnBtnV1(wxCommandEvent& event)
{
    ds1 = 0.005;
}


void MyTestDlg::OnBtnV2(wxCommandEvent& event)
{
    ds1 = 0.003;
}

void MyTestDlg::OnBtnV3(wxCommandEvent& event)
{
    ds2 = ds1/2;
}

void MyTestDlg::OnInitial(wxCommandEvent& event)
{
    int val = 20;
    cli->segs[4].numb = val-1;
    cli->segs[5].numb = val;
    cli->m1.iseg = val;
    cli->segs[4].t=0;
    //mtg_store_seg(cli,&cli->segs[4]);
    cli->snum.state = 1;
    //mtg_store_snum(cli);
}


void MyTestDlg::OnBtnQuit(wxCommandEvent& event)
{
    Destroy();
}

void MyTestDlg::OnDtsTop(wxCommandEvent& event)
{

    if(nres2>0)
    {
        dts_page = 0;
        ShowResults();
    }
}

void MyTestDlg::OnDtsPre(wxCommandEvent& event)
{

    if(nres2>0)
    {
        if(dts_page>0)
        {
            dts_page--;
            ShowResults();
        }
    }
}

void MyTestDlg::OnDtsNext(wxCommandEvent& event)
{

    if(nres2>0)
    {
        if(dts_page<dts_pages-1)
        {
            dts_page++;
            ShowResults();
        }
    }
}

void MyTestDlg::OnDtsBottom(wxCommandEvent& event)
{

    if(nres2>0)
    {
        dts_page=dts_pages-1;
        ShowResults();
    }
}

void MyTestDlg::OnSegTop(wxCommandEvent& event)
{

    if(nres3>0)
    {
        seg_page = 0;
        ShowDetails();
    }
}

void MyTestDlg::OnSegPre(wxCommandEvent& event)
{

    if(nres3>0)
    {
        if(seg_page>0)
        {
            seg_page--;
            ShowDetails();
        }
    }
}

void MyTestDlg::OnSegNext(wxCommandEvent& event)
{

    if(nres3>0)
    {
        if(seg_page<seg_pages-1)
        {
            seg_page++;
            ShowDetails();
        }
    }
}

void MyTestDlg::OnSegBottom(wxCommandEvent& event)
{

    if(nres3>0)
    {
        seg_page=seg_pages-1;
        ShowDetails();
    }
}

void MyTestDlg::UpdateSets()
{
    listSets->DeleteAllItems();
    wxString valstr;
    //wxMessageBox(wxString::Format(_("%d"),cli->nblk));
    for(int i=0; i<cli->nstn; i++)
    {
        //wxMessageBox(wxString::Format(_("%d"),cli->nsetup));
        valstr = wxDateTime(cli->stns[i].t).Format(_("%Y-%m-%d"));
        listSets->InsertItem(i,valstr,i+1);
    }
}

void MyTestDlg::OnListSetsItemSelect(wxListEvent& event)
{
    //wxMessageBox(_("ok"));
    //selset = listSets->GetSelectedItemCount();
    m_panelSet->Refresh();
}

void MyTestDlg::OnSegSelect(wxCommandEvent& event)
{
    nres3 = 0;
    //nqres2 = 0;
    //if(qres1) free(qres1);
    if(qres3) free(qres3);
    qres3=0;
    long ln;
    int index = segChoice->GetSelection();
    segChoice->GetString(index).ToLong(&ln);
    n1=ln;
    n2=ln;
    //nres3=mtg_query_meas(cli,n1,n2,&qres3);
    m_staticMessage->SetForegroundColour(wxColor(0,255,0));
    m_staticMessage->SetLabel(wxString::Format(_("查询%d条！"),nres3));
    seg_pages = nres3/500;
    if(nres3>seg_pages*500)
    {
        seg_pages++;
    }
    ShowDetails();
    m_textSegPage->SetValue(wxString::Format(_("第%d页/共%d页"),seg_page+1,seg_pages));
}

void MyTestDlg::ShowDetails()
{

}

void MyTestDlg::InitSegGrid()
{
    // Grid
}

void MyTestDlg::InitDetailsGrid()
{
    // Grid
	m_gridDetails->CreateGrid( 0, 0 );
	m_gridDetails->EnableEditing( false );
	m_gridDetails->EnableGridLines( true );
	m_gridDetails->EnableDragGridSize( false );
	m_gridDetails->SetMargins( 0, 0 );

	// Columns
	m_gridDetails->EnableDragColMove( false );
	m_gridDetails->EnableDragColSize( true );
	m_gridDetails->SetColLabelSize( 40 );
	m_gridDetails->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Rows
	m_gridDetails->EnableDragRowSize( true );
	m_gridDetails->SetRowLabelSize( 40 );
	m_gridDetails->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Label Appearance

	// Cell Defaults
	m_gridDetails->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
    m_gridDetails->InsertCols(0,24);
    ///历史
    int i=0;
	m_gridDetails->SetColLabelValue( i, _("管片号") );
	m_gridDetails->SetColSize(i++,50);  ///管片号
	m_gridDetails->SetColLabelValue( i, _("切口里程") );
	m_gridDetails->SetColSize(i++,90);  ///里程
	m_gridDetails->MergeColum(_("平面偏差(mm)"),i,i+1);
	m_gridDetails->SetColLabelValue( i, _("盾首") );
	m_gridDetails->SetColSize(i++,50); ///偏差
	m_gridDetails->SetColLabelValue( i, _("盾尾") );
	m_gridDetails->SetColSize(i++,50);
	m_gridDetails->MergeColum(_("高程偏差(mm)"),i,i+1);
	m_gridDetails->SetColLabelValue( i, _("盾首") );
	m_gridDetails->SetColSize(i++,50);
	m_gridDetails->SetColLabelValue( i, _("盾尾") );
	m_gridDetails->SetColSize(i++,50);
	m_gridDetails->MergeColum(_("姿态角(°)"),i,i+2);
	m_gridDetails->SetColLabelValue( i, _("滚动角") );
	m_gridDetails->SetColSize(i++,50);
	m_gridDetails->SetColLabelValue( i, _("俯仰角") );
	m_gridDetails->SetColSize(i++,50);
	m_gridDetails->SetColLabelValue( i, _("方位角") );
	m_gridDetails->SetColSize(i++,50);
	m_gridDetails->MergeColum(_("盾首(计算)"),i,i+2);
	m_gridDetails->SetColLabelValue( i, _("X") );
	m_gridDetails->SetColSize(i++,90);
	m_gridDetails->SetColLabelValue( i, _("Y") );
	m_gridDetails->SetColSize(i++,90);
	m_gridDetails->SetColLabelValue( i, _("Z") );
	m_gridDetails->SetColSize(i++,60);
	m_gridDetails->MergeColum(_("盾尾(计算)"),i,i+2);
	m_gridDetails->SetColLabelValue( i, _("X") );
	m_gridDetails->SetColSize(i++,90);
	m_gridDetails->SetColLabelValue( i, _("Y") );
	m_gridDetails->SetColSize(i++,90);
	m_gridDetails->SetColLabelValue( i, _("Z") );
	m_gridDetails->SetColSize(i++,60);
	m_gridDetails->MergeColum(_("盾首(设计)"),i,i+2);
	m_gridDetails->SetColLabelValue( i, _("X") );
	m_gridDetails->SetColSize(i++,90);
	m_gridDetails->SetColLabelValue( i, _("Y") );
	m_gridDetails->SetColSize(i++,90);
	m_gridDetails->SetColLabelValue( i, _("Z") );
	m_gridDetails->SetColSize(i++,60);
	m_gridDetails->MergeColum(_("盾尾(设计)"),i,i+2);
	m_gridDetails->SetColLabelValue( i, _("X") );
	m_gridDetails->SetColSize(i++,90);
	m_gridDetails->SetColLabelValue( i, _("Y") );
	m_gridDetails->SetColSize(i++,90);
	m_gridDetails->SetColLabelValue( i, _("Z") );
	m_gridDetails->SetColSize(i++,60);
    m_gridDetails->MergeColum(_("倾斜仪(°)"),i,i+1);
    m_gridDetails->SetColLabelValue( i, _("滚动") );
    m_gridDetails->SetColSize(i++,50);
    m_gridDetails->SetColLabelValue( i, _("俯仰") );
    m_gridDetails->SetColSize(i++,50);
    m_gridDetails->SetColLabelValue( i, _("日期") );
	m_gridDetails->SetColSize(i++,130);  ///日期
}

void MyTestDlg::InitMyGrid()
{
    // Grid
}

void MyTestDlg::OnBtnQuery( wxCommandEvent& event )
{
// TODO: Implement OnQuery

    if(m_notebook->GetSelection()==0)
    {
       nres1=0;
       if(qres1) free(qres1);
       qres1=0;
    }
    else if(m_notebook->GetSelection()==1)
    {
        nres3=0;
        if(qres3) free(qres3);
        qres3=0;
    }
    else if(m_notebook->GetSelection()==2)
    {
        nres2=0;
        if(qres2) free(qres2);
        qres2=0;
    }

    long ln;
    m_textFrom->GetValue().ToLong(&ln);
    n1=ln;
    m_textTo->GetValue().ToLong(&ln);
    n2=ln;
    //nres1 = n2-n1+1;
    if(n2-n1+1<=0)
    {
        return;
    }
    segChoice->Clear();
    for(int i=n2;i>=n1;i--)
    {
        segChoice->Append(wxString::Format(_("%d"),i));
    }
    segChoice->SetSelection(0);
    //nres1=mtg_query_segment_meas(cli,n1,n2,&qres1);
    //nres2=mtg_query_meas(cli,n1,n2,&qres2);
    //wxMessageBox(_("ok"));
    m_staticMessage->SetForegroundColour(wxColor(0,255,0));
    if(m_notebook->GetSelection()==0)
    {

        //nres1=mtg_query_segment_meas(cli,n1,n2,&qres1);
        m_staticMessage->SetLabel(wxString::Format(_("查询%d条！"),nres1));
    }
    else if(m_notebook->GetSelection()==1)
    {
        int index = segChoice->GetSelection();
        segChoice->GetString(index).ToLong(&ln);
        //nres3=mtg_query_meas(cli,ln,ln,&qres3);
        seg_pages = nres3/1000;
        if(nres3>seg_pages*1000)
        {
            seg_pages++;
        }
        ShowDetails();
        m_staticMessage->SetLabel(wxString::Format(_("查询%d条！"),nres3));
        m_textSegPage->SetValue(wxString::Format(_("第%d页/共%d页"),seg_page+1,seg_pages));
    }
    else if(m_notebook->GetSelection()==2)
    {
        //nres2=mtg_query_meas(cli,n1,n2,&qres2);
        m_staticMessage->SetLabel(wxString::Format(_("查询%d条！"),nres2));
        dts_pages = nres2/500;
        if(nres2>dts_pages*500)
        {
            dts_pages++;
        }
        m_textDtsPage->SetValue(wxString::Format(_("第%d页/共%d页"),dts_page+1,dts_pages));
        //wxMessageBox(wxString::Format(_("%d"),dts_pages));
    }
    ///更新界面
    ShowResults();
}

void MyTestDlg::CalRes(int n1,int n2)
{
    /*int idx = n1;
    int i=nres-1;
    nres1 = 0;
    double d1=0.0;
    int i0=nres-1;
    int ifind=-1;
    //FILE* fp = fopen("D:\\query.log","w");
    while(idx<=n2)
    {

        for(i=i0;i>=0;i--)
        {

            if(res[i].seg==idx)
            {
                res1[nres1].nm3 = 1;
                res1[nres1].qm3 = res[i];
                d1 = res[i].headc;
                ifind=0;
                break;
            }
        }
        //fprintf(fp,"%d\n",i);
        //fflush(fp);
        if(ifind==0)
        {

            while(res[i].seg==idx && i>=0)
            {
                //fprintf(fp,"%d,%d\n",i,idx);
                //fflush(fp);
                if(fabs(res[i].headc-d1)>=cli->segset.width/2.0)
                {
                    res1[nres1].nm2 = 1;
                    res1[nres1].qm2 = res[i];
                    //fprintf(fp,"%d,%d\n",i,idx);
                    //fflush(fp);
                    break;
                }
                else if(i==0)
                {
                    break;
                }
                i--;
            }
            //fprintf(fp,"ok\n");
            //fflush(fp);
            //wxMessageBox(wxString::Format(_("%d"),ifind));
            while(i>=0)
            {

                if(res[i].seg==idx+1 && res[i+1].seg==idx)
                {

                    res1[nres1].nm1 = 1;
                    res1[nres1].qm1 = res[i+1];
                    break;
                }
                else if(i==0)
                {
                    if(res1[nres1].nm2 == 1)
                    {

                        res1[nres1].nm1 = 1;
                        res1[nres1].qm1 = res[0];
                    }
                }
                i--;
            }
            i0=i;
            nres1++;
        }
        ifind=-1;
        idx++;

    }
    //fclose(fp);
    //meas qm;
    segChoice->Clear();
    for(i=0;i<nres1;i++)
    {
        //qm = res1[i].qm1;
        segChoice->Append(wxString::Format(_("%d"),res1[i].qm1.seg));
        //wxMessageBox(wxString::Format(_("%d"),qm.seg));
    }
    segChoice->SetSelection(0);

    m_textSegView->SetValue(wxString::Format(_("%d"),3));
    ShowDetails();*/
}

void MyTestDlg::ShowResults()
{

}

void MyTestDlg::OnReport( wxCommandEvent& event )
{
// TODO: Implement OnReport
    if(m_notebook->GetSelection()==0)          ///数据报表
    {
        if(nres1<=0)
        {
            wxMessageBox(_("无查询数据！"),_("提示"),wxOK);
            return;
        }
        wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
        wxString valstr = wxString::Format(_("%d ~ "),qres1[nres1-1].iseg)+wxString::Format(_("%d"),qres1[0].iseg)+_("号管环测量记录");
        fileDlg.SetFilename(valstr);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            if(wxFileExists(strFile))
            {
                wxMessageDialog dlg(this,_("覆盖操作将不可恢复\n确定要进行覆盖吗？"),_("报表导出"),wxYES_NO|wxICON_INFORMATION);
                if(dlg.ShowModal() == wxID_NO)
                {
                    return;
                }
            }

            FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
            if(fp)
            {
                fprintf(fp,wxString(_("管片号,位置,刀盘里程,盾首平面,盾首高程,盾尾平面,盾尾高程,滚动,俯仰,方位,盾首x,盾首y,盾首z,盾尾x,盾尾y,盾尾z,棱镜x,棱镜y,棱镜z,倾斜仪滚动,倾斜仪俯仰,时间\n")).mb_str(wxConvLocal));
                for(int i=0;i<nres1;i++)
                {
                    fprintf(fp,"%d,",qres1[i].iseg);
                    if(qres1[i].iset==1)
                    {
                        fprintf(fp,"%s,",_("后"));
                    }
                    else if(qres1[i].iset==2)
                    {
                        fprintf(fp,"%s,",_("中"));
                    }
                    else if(qres1[i].iset==3)
                    {
                        fprintf(fp,"%s,",_("前"));
                    }
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
                    fprintf(fp,"%.3f,",qres1[i].tail[0]);
                    fprintf(fp,"%.3f,",qres1[i].tail[1]);
                    fprintf(fp,"%.3f,",qres1[i].tail[2]);
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
    else if(m_notebook->GetSelection()==1)          ///数据报表
    {
        if(nres3<=0)
        {
            wxMessageBox(_("无查询数据！"),_("提示"),wxOK);
            return;
        }
        wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
        int num = segChoice->GetSelection();
        wxString valstr = segChoice->GetString(num)+_("号管环测量记录");
        fileDlg.SetFilename(valstr);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            if(wxFileExists(strFile))
            {
                wxMessageDialog dlg(this,_("覆盖操作将不可恢复\n确定要进行覆盖吗？"),_("报表导出"),wxYES_NO|wxICON_INFORMATION);
                if(dlg.ShowModal() == wxID_NO)
                {
                    return;
                }
            }
            FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
            if(fp)
            {
                fprintf(fp,wxString(_("管片号,刀盘里程,盾首平面,盾首高程,盾尾平面,盾尾高程,滚动,俯仰,方位,盾首x,盾首y,盾首z,盾尾x,盾尾y,盾尾z,棱镜x,棱镜y,棱镜z,倾斜仪滚动,倾斜仪俯仰,时间\n")).mb_str(wxConvLocal));
                for(int i=0;i<nres3;i++)
                {
                    fprintf(fp,"%d,",qres3[i].iseg);
                    fprintf(fp,"%.3f,",qres3[i].headc);
                    fprintf(fp,"%d,",(int)(qres3[i].headh*1000.0));
                    fprintf(fp,"%d,",(int)(qres3[i].headv*1000.0));
                    fprintf(fp,"%d,",(int)(qres3[i].tailh*1000.0));
                    fprintf(fp,"%d,",(int)(qres3[i].tailv*1000.0));
                    fprintf(fp,"%.3f,",qres3[i].roll*180.0/PI);
                    fprintf(fp,"%.3f,",qres3[i].pitch*180.0/PI);
                    fprintf(fp,"%.3f,",qres3[i].azimuth*180.0/PI);
                    fprintf(fp,"%.3f,",qres3[i].head[0]);
                    fprintf(fp,"%.3f,",qres3[i].head[1]);
                    fprintf(fp,"%.3f,",qres3[i].head[2]);
                    fprintf(fp,"%.3f,",qres3[i].tail[0]);
                    fprintf(fp,"%.3f,",qres3[i].tail[1]);
                    fprintf(fp,"%.3f,",qres3[i].tail[2]);
                    fprintf(fp,"%.3f,",qres3[i].prism[0]);
                    fprintf(fp,"%.3f,",qres3[i].prism[1]);
                    fprintf(fp,"%.3f,",qres3[i].prism[2]);
                    fprintf(fp,"%.4f,",qres3[i].inc[0]);
                    fprintf(fp,"%.4f,",qres3[i].inc[1]);
                    wxString strt=wxDateTime(qres3[i].t1).Format(_("%Y-%m-%d %H:%M:%S"));
                    fprintf(fp,"%s\n",(const char*)strt.mb_str(wxConvLocal));
                }
                fclose(fp);
                wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
            }
        }
    }
    else if(m_notebook->GetSelection()==2)          ///导出详细历史数据
    {
        if(nres2<=0)
        {
            wxMessageBox(_("无查询数据！"),_("提示"),wxOK);
            return;
        }
        wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
        wxString valstr = wxString::Format(_("%d ~ "),qres2[nres2-1].iseg)+wxString::Format(_("%d"),qres2[0].iseg)+_("号管环详细测量记录");
        fileDlg.SetFilename(valstr);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            if(wxFileExists(strFile))
            {
                wxMessageDialog dlg(this,_("覆盖操作将不可恢复\n确定要进行覆盖吗？"),_("报表导出"),wxYES_NO|wxICON_INFORMATION);
                if(dlg.ShowModal() == wxID_NO)
                {
                    return;
                }
            }

            FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
            if(fp)
            {
                fprintf(fp,wxString(_("管片号,刀盘里程,盾首平面,盾首高程,盾尾平面,盾尾高程,滚动,俯仰,方位,盾首x,盾首y,盾首z,盾尾x,盾尾y,盾尾z,棱镜x,棱镜y,棱镜z,倾斜仪滚动,倾斜仪俯仰,时间\n")).mb_str(wxConvLocal));
                for(int i=0;i<nres2;i++)
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
                    fprintf(fp,"%.3f,",qres2[i].tail[0]);
                    fprintf(fp,"%.3f,",qres2[i].tail[1]);
                    fprintf(fp,"%.3f,",qres2[i].tail[2]);
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
    else if(m_notebook->GetSelection()==3)          ///数据报表
    {
        wxFileDialog fileDlg(this,_("保存"),wxEmptyString,wxEmptyString,_("JPEG 图像(*.jpg)|*.jpg"),wxFD_SAVE);
        int nsets = listSets->GetFirstSelected();
        wxString valstr = wxDateTime(cli->stns[nsets].t).Format(_("%Y-%m-%d"));
        valstr = valstr+_("  换站记录");
        fileDlg.SetFilename(valstr);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            m_setPath=fileDlg.GetPath();
            //m_setPath = m_setPath+valstr;
            is_save_set = 0;
            m_panelSet->Refresh();
        }
    }
}

void MyTestDlg::OnPaintNums(wxPaintEvent& event)
{
    wxPaintDC dc(m_panelNums);
    int w,h;
    m_panelNums->GetClientSize(&w,&h);

    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);

        memDC.SetPen(wxPen(wxColor(130,135,145)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.SetFont(chs);
        memDC.DrawRectangle(0,0,w,h);
        int x1 = 15;
        int y1 = 15;
        int w1 = 120;
        int h1 = 25;
        memDC.DrawLabel(_("模式:"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        if(cli->snum.mode==0)
        {
            memDC.DrawLabel(_("初始环号未设置!"),wxRect(x1+50,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(cli->snum.mode==1)
        {
            memDC.DrawLabel(_("刚开始掘进"),wxRect(x1+50,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(cli->snum.mode==2)
        {
            memDC.DrawLabel(_("正常掘进"),wxRect(x1+50,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(cli->snum.mode==3)
        {
            memDC.DrawLabel(_("慢速掘进"),wxRect(x1+50,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        int x2 = x1+w1+80;
        int y2 = y1;
        int w2 = w1;
        int h2 = h1;
        memDC.DrawLabel(_("状态:"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        if(cli->snum.state==0)
        {
            memDC.DrawLabel(_("初始环号未设置!"),wxRect(x2+50,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(cli->snum.state==1)
        {
            memDC.DrawLabel(_("初始环号已设置,参数已初始化!"),wxRect(x2+50,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(cli->snum.state==2)
        {
            memDC.DrawLabel(_("环号计算中..."),wxRect(x2+50,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        memDC.DrawLabel(_("环号:")+wxString::Format(_("%d"),cli->segs[5].numb),wxRect(x2+w2+w2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1+=30;
        y2+=30;
        memDC.DrawLabel(_("速度1:")+wxString::Format(_("%.7f"),cli->snum.v1),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("速度2:")+wxString::Format(_("%.7f"),cli->snum.v2),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("速度3:")+wxString::Format(_("%.7f"),cli->snum.v3),wxRect(x2+w2+w2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLabel(_("掘进：")+wxString::Format(_("%.4f"),cli->m.headc-cli->snum.tm),wxRect(x2+w2+w2+w2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1+=30;
        y2+=30;
        memDC.DrawLabel(_("计数1:")+wxString::Format(_("%d"),cli->snum.sum1),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("计数2:")+wxString::Format(_("%d"),cli->snum.sum2),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("计数3:")+wxString::Format(_("%d"),cli->snum.sum3),wxRect(x2+w2+w2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1+=30;
        y2+=30;
        memDC.DrawLabel(_("计数4:")+wxString::Format(_("%d"),cli->snum.sum4),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("起点里程:")+wxString::Format(_("%.4f"),cli->snum.tm),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("当前里程:")+wxString::Format(_("%.4f"),cli->m.headc),wxRect(x2+w2+w2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1+=30;
        for(int i=0;i<20;i++)
        {
            memDC.DrawLabel(wxString::Format(_("里程[%d]:"),i)+wxString::Format(_("%.4f"),cli->snum.mile[i]),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=160;
            if(x1>w-120)
            {
                x1 = 15;
                y1 += 30;
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyTestDlg::OnPaintSet(wxPaintEvent& event)
{
    wxPaintDC dc(m_panelSet);
    int w,h;
    m_panelSet->GetClientSize(&w,&h);

    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        wxString valstr;
        double dh1,dh2,dv;
        double x1,y1,z1,h1;
        double x2,y2,z2,h2;
        double x3,y3,z3;
        int nsets = listSets->GetFirstSelected();

        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);

        memDC.SetPen(wxPen(wxColor(130,135,145)));
        memDC.SetFont(chs);

        if(nsets==-1)
        {
            //memDC.SetPen(wxPen(wxColor(255,255,255)));
            memDC.DrawRectangle(0,0,w,h);

            memDC.SetTextForeground(wxColor(68,68,68));
            valstr = _("无设站记录");
            memDC.DrawLabel(valstr,wxRect(w/2,30,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            dc.Blit(0,0,w,h,&memDC,0,0);
            return;
        }

        int isPre = -1;
        if(nsets>0)
        {
            x1 = cli->stns[nsets-1].statx;
            y1 = cli->stns[nsets-1].staty;
            z1 = cli->stns[nsets-1].statz;
            h1 = cli->stns[nsets-1].stath;
            x2 = cli->stns[nsets-1].backx;
            y2 = cli->stns[nsets-1].backy;
            z2 = cli->stns[nsets-1].backz;
            h1 = cli->stns[nsets-1].backh;
            x3 = cli->stns[nsets-1].backx1;
            y3 = cli->stns[nsets-1].backy1;
            y3 = PI/2.0-y3;
            z3 = cli->stns[nsets-1].backz1;
            isPre = 0;
        }

        memDC.DrawRectangle(0,0,w,h);
        valstr = wxDateTime(cli->stns[nsets].t).Format(_("%Y-%m-%d %H:%M:%S"));
        valstr = valstr+_("  换站测量记录");

        memDC.SetTextForeground(wxColor(68,68,68));
        memDC.DrawLabel(valstr,wxRect(w/2,30,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        if(isPre==-1)
        {
            valstr = _("一、上次设站信息  无设站记录");
        }
        else
        {
            valstr = _("一、上次设站信息");
        }
        memDC.DrawLabel(valstr,wxRect(15,60,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("1.测站坐标");
        memDC.DrawLabel(valstr,wxRect(35,85,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        if(isPre==0)
        {
            valstr = _("X ")+wxString::Format(_("%.4f"),x1)+_("   ")+_("Y ")+wxString::Format(_("%.4f"),y1)+_("   ")+_("Z ")+wxString::Format(_("%.4f"),z1)+_("   ")+_("高 ")+wxString::Format(_("%.3f"),h1);
            memDC.DrawLabel(valstr,wxRect(155,85,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            valstr = _("X ")+wxString::Format(_("%.4f"),x2)+_("   ")+_("Y ")+wxString::Format(_("%.4f"),y2)+_("   ")+_("Z ")+wxString::Format(_("%.4f"),z2)+_("   ")+_("高 ")+wxString::Format(_("%.3f"),h2);
            memDC.DrawLabel(valstr,wxRect(155,110,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            dh1 = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
            dh1 = sqrt(dh1);
            dh2 = z3*cos(y3);
            dh1 = dh2-dh1;
            valstr = _("平距差 ")+wxString::Format(_("%.1f mm"),dh1*1000.0);
            memDC.DrawLabel(valstr,wxRect(155,135,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            dv = z1+z3*sin(y3)-z2;
            valstr = _("高差 ")+wxString::Format(_("%.1f mm"),dv*1000.0);
            memDC.DrawLabel(valstr,wxRect(380,135,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        valstr = _("2.后视坐标");
        memDC.DrawLabel(valstr,wxRect(35,110,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("3.设站质量");
        memDC.DrawLabel(valstr,wxRect(35,135,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        valstr = _("二、本次设站信息");
        memDC.DrawLabel(valstr,wxRect(15,165,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1 = cli->stns[nsets].statx;
        y1 = cli->stns[nsets].staty;
        z1 = cli->stns[nsets].statz;
        h1 = cli->stns[nsets].stath;
        x2 = cli->stns[nsets].backx;
        y2 = cli->stns[nsets].backy;
        z2 = cli->stns[nsets].backz;
        h1 = cli->stns[nsets].backh;
        x3 = cli->stns[nsets].backx1;
        y3 = cli->stns[nsets].backy1;
        y3 = PI/2.0-y3;
        z3 = cli->stns[nsets].backz1;
        valstr = _("1.测站坐标");
        memDC.DrawLabel(valstr,wxRect(35,190,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("X ")+wxString::Format(_("%.4f"),x1)+_("   ")+_("Y ")+wxString::Format(_("%.4f"),y1)+_("   ")+_("Z ")+wxString::Format(_("%.4f"),z1)+_("   ")+_("高 ")+wxString::Format(_("%.3f"),h1);
        memDC.DrawLabel(valstr,wxRect(155,190,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("2.后视坐标");
        memDC.DrawLabel(valstr,wxRect(35,215,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("X ")+wxString::Format(_("%.4f"),x2)+_("   ")+_("Y ")+wxString::Format(_("%.4f"),y2)+_("   ")+_("Z ")+wxString::Format(_("%.4f"),z2)+_("   ")+_("高 ")+wxString::Format(_("%.3f"),h2);
        memDC.DrawLabel(valstr,wxRect(155,215,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("3.设站质量");
        memDC.DrawLabel(valstr,wxRect(35,240,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dh1 = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        dh1 = sqrt(dh1);
        dh2 = z3*cos(y3);
        dh1 = dh2-dh1;

        valstr = _("平距差 ")+wxString::Format(_("%.1f mm"),dh1*1000.0);
        memDC.DrawLabel(valstr,wxRect(155,240,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        dv = z1+z3*sin(y3)-z2;
        valstr = _("高差 ")+wxString::Format(_("%.1f mm"),dv*1000.0);
        memDC.DrawLabel(valstr,wxRect(380,240,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        valstr = _("三、前/后盾构姿态");
        memDC.DrawLabel(valstr,wxRect(15,275,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("切口平面");
        memDC.DrawLabel(valstr,wxRect(155,315,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("盾尾平面");
        memDC.DrawLabel(valstr,wxRect(267,315,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("切口高程");
        memDC.DrawLabel(valstr,wxRect(380,315,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("盾尾高程");
        memDC.DrawLabel(valstr,wxRect(465,315,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("设站前");
        memDC.DrawLabel(valstr,wxRect(35,345,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = _("设站后");
        memDC.DrawLabel(valstr,wxRect(35,375,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        //valstr = _("前后差");
        //memDC.DrawLabel(valstr,wxRect(35,380,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        long t1 = cli->stns[nsets].t-600;
        long t2 = cli->stns[nsets].t;
        //wxMessageBox(wxString::Format(_("%d"),nsets));

        MTG_MEASURE* stres;
        int nstres;
        double hdh[2];
        double tlh[2];
        double hdv[2];
        double tlv[2];
        for(int i=0;i<2;i++)
        {
            hdh[i] = 0.0;
            tlh[i] = 0.0;
            hdv[i] = 0.0;
            tlv[i] = 0.0;
        }
        //nstres = mtg_query_time(cli,t1,t2,&stres);
        if(nstres>0)
        {
            hdh[0] = stres[0].headh*1000.0;
            tlh[0] = stres[0].tailh*1000.0;
            hdv[0] = stres[0].headv*1000.0;
            tlv[0] = stres[0].tailv*1000.0;
            valstr = wxString::Format(_("%.1f"),hdh[0]);
            memDC.DrawLabel(valstr,wxRect(155,345,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            valstr = wxString::Format(_("%.1f"),tlh[0]);
            memDC.DrawLabel(valstr,wxRect(267,345,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            valstr = wxString::Format(_("%.1f"),hdv[0]);
            memDC.DrawLabel(valstr,wxRect(380,345,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            valstr = wxString::Format(_("%.1f"),tlv[0]);
            memDC.DrawLabel(valstr,wxRect(465,345,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            valstr = _("换站前10分钟内无测量记录");
            memDC.DrawLabel(valstr,wxRect(155,345,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        t1 = t2;
        t2 = cli->stns[nsets].t+600;
        //nstres = mtg_query_time(cli,t1,t2,&stres);
        if(nstres>0)
        {
            hdh[1] = stres[nstres-1].headh*1000.0;
            tlh[1] = stres[nstres-1].tailh*1000.0;
            hdv[1] = stres[nstres-1].headv*1000.0;
            tlv[1] = stres[nstres-1].tailv*1000.0;
            valstr = wxString::Format(_("%.1f"),hdh[1]);
            memDC.DrawLabel(valstr,wxRect(155,375,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            valstr = wxString::Format(_("%.1f"),tlh[1]);
            memDC.DrawLabel(valstr,wxRect(267,375,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            valstr = wxString::Format(_("%.1f"),hdv[1]);
            memDC.DrawLabel(valstr,wxRect(380,375,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            valstr = wxString::Format(_("%.1f"),tlv[1]);
            memDC.DrawLabel(valstr,wxRect(465,375,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            valstr = _("换站后10分钟内无测量记录");
            memDC.DrawLabel(valstr,wxRect(155,375,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        }
        /*memDC.SetTextForeground(wxColor(255,0,255));
        valstr = wxString::Format(_("%.1f"),hdh[0]-hdh[1]);
        memDC.DrawLabel(valstr,wxRect(155,380,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = wxString::Format(_("%.1f"),tlh[0]-tlh[1]);
        memDC.DrawLabel(valstr,wxRect(267,380,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = wxString::Format(_("%.1f"),hdv[0]-hdv[1]);
        memDC.DrawLabel(valstr,wxRect(380,380,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr = wxString::Format(_("%.1f"),tlv[0]-tlv[1]);
        memDC.DrawLabel(valstr,wxRect(465,380,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);*/

        dc.Blit(0,0,w,h,&memDC,0,0);

        if(is_save_set==0)
        {
            if(wxFileExists(m_setPath))
            {
                //wxMessageBox(_("ok"));

                wxMessageDialog dlg(this,_("覆盖操作将不可恢复\n确定要进行覆盖吗？"),_("报表导出"),wxYES_NO|wxICON_INFORMATION);
                if(dlg.ShowModal() == wxID_YES)
                {
                    m_memBit.SaveFile(m_setPath,wxBITMAP_TYPE_JPEG);
                    is_save_set=-1;
                }
                else
                {
                    is_save_set=-1;
                    return;
                }
            }
            else
            {
                m_memBit.SaveFile(m_setPath,wxBITMAP_TYPE_JPEG);
                is_save_set=-1;
            }
        }
    }
}
