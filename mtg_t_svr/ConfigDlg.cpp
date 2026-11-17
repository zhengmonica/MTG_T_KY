///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ConfigDlg.h"
#include "mtg_t_svrMain.h"
#include "mtg_t_svrApp.h"
#include "TpsDlg.h"
#include "KeyDlg.h"
#include "BlockDlg.h"
#include "ConfirmDlg.h"
#include "PasswordDialog.h"
#include "dmsrad.h"
#include "geometry.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/dir.h>
#include <wx/filename.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(ConfigDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(ConfigDlg)
#include <wx/font.h>
//*)
#include <wx/config.h>

///////////////////////////////////////////////////////////////////////////
//(*IdInit(ConfigDlg)
const long ConfigDlg::ID_PANEL2 = wxNewId();                  //按钮
//const long ConfigDlg::ID_BUTTON1 = wxNewId();                 //取消
//const long ConfigDlg::ID_BUTTON2 = wxNewId();                 //应用
//*)

ConfigDlg::ConfigDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
    bmpTPS.LoadFile(path+_("/plugins/tps3.png"),wxBITMAP_TYPE_PNG);
    bmpImportPrj.LoadFile(path+_("/plugins/prj_import.png"),wxBITMAP_TYPE_PNG);
    bmpExportPrj.LoadFile(path+_("/plugins/prj_export.png"),wxBITMAP_TYPE_PNG);
    bmpClearPrj.LoadFile(path+_("/plugins/prj_clear.png"),wxBITMAP_TYPE_PNG);
    bmpTPS1.LoadFile(path+_("/plugins/tps4.png"),wxBITMAP_TYPE_PNG);
	ipath=path;
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x,y;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	this->GetClientSize(&w,&h);
	panelButton = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(150,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
	panelButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    //panelButtonList = new MDButtonList(this, ID_PANEL2, wxPoint(0,0), wxSize(150,h-45), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	//panelButtonList->Show(false);
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(150,0), wxSize(w-150,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelNavi = new wxPanel(panelMain, wxID_ANY, wxPoint(600+w,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    w1=w-150;
    h1=h-57;
    panelPrj = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPrj->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    prjStaticText1 = new wxStaticText(panelPrj, wxID_ANY, _("工程设置"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prjLine1 = new wxStaticLine(panelPrj, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=30;
    prjStaticText2 = new wxStaticText(panelPrj, wxID_ANY, _("工程名称"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prjName = new wxMyTextCtrl(panelPrj, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1-3), wxSize(360,-1), 0);
    y1+=30;
    prjStaticText3 = new wxStaticText(panelPrj, wxID_ANY, _("起点里程"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prjMile1 = new wxMyTextCtrl(panelPrj, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1-3), wxSize(120,-1), 0);
    y1+=30;
    prjStaticText4 = new wxStaticText(panelPrj, wxID_ANY, _("终点里程"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prjMile2 = new wxMyTextCtrl(panelPrj, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1-3), wxSize(120,-1), 0);

    y1+=30;
    prjStaticText6 = new wxStaticText(panelPrj, wxID_ANY, _("作业设置"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prjLine2 = new wxStaticLine(panelPrj, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=30;
    prjStaticText7 = new wxStaticText(panelPrj, wxID_ANY, _("作业人数"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prjDutyPanel = new wxPanel(panelPrj, wxID_ANY, wxPoint(x1+65,y1-3), wxSize(120,23), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    prjDutyPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y1+=30;
    prjStaticText8 = new wxStaticText(panelPrj, wxID_ANY, _("作业员(1)"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    op1Name = new wxMyTextCtrl(panelPrj, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1-3), wxSize(120,-1),0);
    y1+=30;
    prjStaticText9 = new wxStaticText(panelPrj, wxID_ANY, _("作业员(2)"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    op2Name = new wxMyTextCtrl(panelPrj, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1-3), wxSize(120,-1), 0);
    y1+=30;
    prjStaticText10 = new wxStaticText(panelPrj, wxID_ANY, _("作业员(3)"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    op3Name = new wxMyTextCtrl(panelPrj, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1-3), wxSize(120,-1), 0);
    y1+=30;
    prjStaticText11 = new wxStaticText(panelPrj, wxID_ANY, _("作业员(4)"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    op4Name = new wxMyTextCtrl(panelPrj, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1-3), wxSize(120,-1), 0);

    panelKey = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelKey->SetBackgroundColour(wxColor(239,239,239));

    x1=14;
    y1=9;
    w2=w1-x1*2;
    keyStaticText1 = new wxStaticText(panelKey, wxID_ANY, _("提示范围"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    keyLine1 = new wxStaticLine(panelKey, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=30;
    keyStaticText2 = new wxStaticText(panelKey, wxID_ANY, _("切口附近"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    keyTip = new wxMyTextCtrl(panelKey, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1-3), wxSize(120,-1), 0);
    keyStaticText3 = new wxStaticText(panelKey, wxID_ANY, _("米范围内提示"), wxPoint(x1+190,y1), wxDefaultSize, 0, _("wxID_ANY"));
    y1+=30;
    keyStaticText4 = new wxStaticText(panelKey, wxID_ANY, _("中线提示"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    keyRoadPanel = new wxPanel(panelKey, wxID_ANY, wxPoint(x1+65,y1-3), wxSize(260,23), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    keyRoadPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=14;
    y1+=30;
    w2=w1-x1*2;
    keyStaticText5 = new wxStaticText(panelKey, wxID_ANY, _("区域设置"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    keyLine2 = new wxStaticLine(panelKey, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    h2=h1-y1-25;
    keyGridPanel = new wxPanel(panelKey, wxID_ANY, wxPoint(x1,y1), wxSize(w2-72,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    keyGridPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    keyList = new wxListView(keyGridPanel, wxID_ANY, wxPoint(0,24), wxSize(w2-72,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    x1=x1+w2-65;
    keyButton1Panel = new wxPanel(panelKey, wxID_ANY, wxPoint(x1,y1), wxSize(65,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    keyButton1Panel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelTbm = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTbm->SetBackgroundColour(wxColor(239,239,239));
    tbmPanelPage = new wxPanel(panelTbm, wxID_ANY, wxPoint(0,5), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tbmPanelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTbmgen = new wxPanel(panelTbm, wxID_ANY, wxPoint(0,33), wxSize(w1,h1-33), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTbmgen->SetBackgroundColour(wxColor(239,239,239));
    panelTbmJack = new wxPanel(panelTbm, wxID_ANY, wxPoint(0,33), wxSize(w1,h1-33), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTbmJack->SetBackgroundColour(wxColor(239,239,239));
    panelTbmJack->Show(false);
    x1=14;
    //y1=9;
    w2=w1-x1*2;
    y1=16;
    tbmStaticText2 = new wxStaticText(panelTbmgen, wxID_ANY, _("盾构编号"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tbmIndex = new wxMyTextCtrl(panelTbmgen, wxID_ANY, wxEmptyString, wxPoint(x1+60,y1-3), wxSize(180,-1), 0);
    tbmStaticText3 = new wxStaticText(panelTbmgen, wxID_ANY, _("铰接类型"), wxPoint(x1+305,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tbmKinkPanel = new wxPanel(panelTbmgen, wxID_ANY, wxPoint(x1+385,y1-4), wxSize(320,23), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tbmKinkPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelJackfig = new wxPanel(panelTbmJack, wxID_ANY, wxPoint(x1,y1+45), wxSize(w1/2,w1/2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelJackfig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    tbmStaticText6 = new wxStaticText(panelTbmJack, wxID_ANY, _("推进油缸组"), wxPoint(x1+w1/2+15,y1+48), wxDefaultSize, 0, _("wxID_ANY"));
    tbmStaticText7 = new wxStaticText(panelTbmJack, wxID_ANY, _("A组油缸"), wxPoint(x1+w1/2+15,y1+78), wxDefaultSize, 0, _("wxID_ANY"));
    panelTypJack = new wxPanel(panelTbmJack, wxID_ANY, wxPoint(x1,y1), wxSize(w1-x1*2-5,42), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTypJack->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelNumJack = new wxPanel(panelTbmJack, wxID_ANY, wxPoint(x1+w1/2+95,y1+45), wxSize(120,22), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelNumJack->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelAngJack = new wxPanel(panelTbmJack, wxID_ANY, wxPoint(x1+w1/2+95,y1+75), wxSize(192,22), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelAngJack->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    jackTxt = new wxMyTextCtrl(panelAngJack, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    panelJackList = new wxPanel(panelTbmJack, wxID_ANY, wxPoint(x1+w1/2+15,y1+105), wxSize(272,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelJackList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    jackList = new wxListView(panelTbmJack, wxID_ANY, wxPoint(x1+w1/2+15,y1+129), wxSize(272,w1/2-84), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    y1+=30;
    tbmStaticText4 = new wxStaticText(panelTbmgen, wxID_ANY, _("几何参数"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tbmLine2 = new wxStaticLine(panelTbmgen, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=30;
    tbmFigPanel = new wxPanel(panelTbmgen, wxID_ANY, wxPoint(x1,y1-5), wxSize(343,395), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tbmFigPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    tbmTxtPanel = new wxPanel(panelTbmgen, wxID_ANY, wxPoint(x1+353,y1-5), wxSize(w2-353,405), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tbmTxtPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1+=363;
    tbmL1 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(125,2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL2 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(125,2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL3 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(125,2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL4 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL5 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL6 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL7 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL8 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL9 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    y1+=30;
    tbmD1 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmD2 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmD3 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmD4 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmD5 = new wxMyTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelTars = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTars->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    y1+=7;
    tarsStaticText2 = new wxStaticText(panelTars, wxID_ANY, _("配置文件"), wxPoint(x1+1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tarsFile = new wxMyTextCtrl(panelTars, wxID_ANY, wxEmptyString, wxPoint(x1+60,y1-4), wxSize(210,25), 0);
    tarsFile->Enable(false);
    prismPanel = new wxPanel(panelTars, wxID_ANY, wxPoint(x1+352,y1-4), wxSize(120,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    prismPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    prismPanel->Show(false);
    tarsButton = new wxPanel(panelTars, wxID_ANY, wxPoint(x1+282,y1-4), wxSize(137,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tarsButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y1+=27;
    tarsLine1 = new wxStaticLine(panelTars, wxID_ANY, wxPoint(x1,y1+8), wxSize(w2,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    h2=h1-y1-25;
    tarsFig = new wxPanel(panelTars, wxID_ANY, wxPoint(x1,y1), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tarsFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    tarsPrism = new wxMyTextCtrl(tarsFig, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelTps = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTps->SetBackgroundColour(wxColor(239,239,239));

    x1=14;
    y1=9;
    w2=w1-x1*2;
    tpsSetPanel = new wxPanel(panelTps, wxID_ANY, wxPoint(x1,y1), wxSize(w2-3,80), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tpsSetPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y1+=80;
    //tpsStaticText2 = new wxStaticText(panelTps, wxID_ANY, _("激光矫正"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    //tpsLine2 = new wxStaticLine(panelTps, wxID_ANY, wxPoint(x1+35,y1+8), wxSize(w2-38,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    //y1+=25;
    tpsFigPanel = new wxPanel(panelTps, wxID_ANY, wxPoint(x1,y1), wxSize(w2-3,h1-y1-18), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tpsFigPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    tpsLaserDist = new wxMyTextCtrl(tpsFigPanel, wxID_ANY, wxEmptyString, wxPoint(x1+60,y1-2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    tpsLaserDevX = new wxMyTextCtrl(tpsFigPanel, wxID_ANY, _(" mm"), wxPoint(x1+250,y1-2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    tpsLaserDevY = new wxMyTextCtrl(tpsFigPanel, wxID_ANY, _(" mm"), wxPoint(x1+450,y1-2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelSeg = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSeg->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    segStaticText1 = new wxStaticText(panelSeg, wxID_ANY, _("管环参数"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    segLine1 = new wxStaticLine(panelSeg, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    h2=h1-y1-18;
    segFigPanel = new wxPanel(panelSeg, wxID_ANY, wxPoint(x1,y1), wxSize(w2/2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    segFigPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    segTxtPanel = new wxPanel(panelSeg, wxID_ANY, wxPoint(x1+w2/2,y1), wxSize(w2/2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    segTxtPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    segL = new wxMyTextCtrl(segTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+60,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segD1 = new wxMyTextCtrl(segTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+265,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segD2 = new wxMyTextCtrl(segTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+470,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segKs = new wxMyTextCtrl(segTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+60,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segG0 = new wxMyTextCtrl(segTxtPanel, wxID_ANY,wxEmptyString, wxPoint(x1+265,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segG1 = new wxMyTextCtrl(segTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+470,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segL2s = new wxMyTextCtrl(segTxtPanel, wxID_ANY, _(" mm"), wxPoint(x1+277,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelBlock = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBlock->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    blkListPanel = new wxPanel(panelBlock, wxID_ANY, wxPoint(x1,y1), wxSize(w2-72,h2/2-5), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    blkListPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    blockList = new wxListView(blkListPanel, wxID_ANY, wxPoint(0,24), wxSize(w2-72,h2/2-29), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    blkButton1Panel = new wxPanel(panelBlock, wxID_ANY, wxPoint(x1+w2-65,y1), wxSize(65,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    blkButton1Panel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);


    blkFigPanel = new wxPanel(panelBlock, wxID_ANY, wxPoint(x1,y1+h2/2+10), wxSize(w2-72,h2/2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    blkFigPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x2=x1+w2+10;
    panelM1 = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelM1->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    int w3=65;
    int w4=w2-w3-7;
    int w5=(w4-45)/3;
    int h5=25;
    w4=w4-7;
    m1StaticText1 = new wxStaticText(panelM1, wxID_ANY, _("盾构机"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    m1Line1 = new wxStaticLine(panelM1, wxID_ANY, wxPoint(x1+38,y1+8), wxSize(w4-38,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));

    int x5=x1;
    int y5=y1+25;

    m1StaticText2 = new wxStaticText(panelM1, wxID_ANY, _("前端"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=45;
    m1StaticText3 = new wxStaticText(panelM1, wxID_ANY, _("X"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    y1=y5+15;
    m1Head1 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1StaticText4 = new wxStaticText(panelM1, wxID_ANY, _("Y"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1Head2 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1StaticText5 = new wxStaticText(panelM1, wxID_ANY, _("Z"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1Head3 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);

    /*x5=x1;
    y5+=30;
    m1StaticText6 = new wxStaticText(panelM1, wxID_ANY, _("铰接"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=45;
    m1Mid1 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1Mid2 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1Mid3 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);*/

    x5=x1;
    y5+=30;
    m1StaticText10 = new wxStaticText(panelM1, wxID_ANY, _("后端"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=45;
    m1Tail1 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1Tail2 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1Tail3 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);

    x5=x1;
    y5+=55;
    m1StaticText7 = new wxStaticText(panelM1, wxID_ANY, _("姿态角"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=45;
    m1StaticText15 = new wxStaticText(panelM1, wxID_ANY, _("转动角（D.MMSS）"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1Roll = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1StaticText16 = new wxStaticText(panelM1, wxID_ANY, _("俯仰角（D.MMSS）"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1Pitch = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1StaticText17 = new wxStaticText(panelM1, wxID_ANY, _("方位角（D.MMSS）"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1Azi = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);

    x5=x1;
    y5+=55;
    m1StaticText18 = new wxStaticText(panelM1, wxID_ANY, _("激光靶"), wxPoint(x5,y5), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=38;
    m1Line3 = new wxStaticLine(panelM1, wxID_ANY, wxPoint(x5,y5+8), wxSize(w4-38,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    x5=x1;
    y5+=25;
    m1StaticText19 = new wxStaticText(panelM1, wxID_ANY, _("坐标"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=45;
    m1StaticText20 = new wxStaticText(panelM1, wxID_ANY, _("X"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1Prism1 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1StaticText21 = new wxStaticText(panelM1, wxID_ANY, _("Y"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1Prism2 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1StaticText22 = new wxStaticText(panelM1, wxID_ANY, _("Z"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1Prism3 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);

    x5=x1;
    y5+=55;
    m1StaticText8 = new wxStaticText(panelM1, wxID_ANY, _("姿态角"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=45;
    m1StaticText23 = new wxStaticText(panelM1, wxID_ANY, _("转动角（D.MMSS）"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1Inc1 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1StaticText24 = new wxStaticText(panelM1, wxID_ANY, _("俯仰角（D.MMSS）"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1Inc2 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1StaticText25 = new wxStaticText(panelM1, wxID_ANY, _("方位角（D.MMSS）"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1Inc3 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5=x1;
    y5+=50;
    m1StaticText26 = new wxStaticText(panelM1, wxID_ANY, _("检核棱镜"), wxPoint(x5,y5), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=50;
    m1Line4 = new wxStaticLine(panelM1, wxID_ANY, wxPoint(x5,y5+8), wxSize(w4-55,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    x5=x1;
    y5+=25;
    m1StaticText27 = new wxStaticText(panelM1, wxID_ANY, _("1#棱镜"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=45;
    m1StaticText28 = new wxStaticText(panelM1, wxID_ANY, _("X"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1CP11 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1StaticText29 = new wxStaticText(panelM1, wxID_ANY, _("Y"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1CP12 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1StaticText30 = new wxStaticText(panelM1, wxID_ANY, _("Z"), wxPoint(x5,y5-5), wxDefaultSize, 0, _("wxID_ANY"));
    m1CP13 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);

    x5=x1;
    y5+=30;
    m1StaticText31 = new wxStaticText(panelM1, wxID_ANY, _("2#棱镜"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=45;
    m1CP21 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1CP22 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1CP23 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);

    x5=x1;
    y5+=40;
    m1StaticText32 = new wxStaticText(panelM1, wxID_ANY, _("2#棱镜"), wxPoint(x5+45,y5+18-40-30-25), wxDefaultSize, 0, _("wxID_ANY"));
    //x5+=45;
    //m1CP31 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    //x5+=w5;
    //m1CP32 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    //x5+=w5;
    //m1CP33 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);

    m1CP11->Show(false);
    m1CP12->Show(false);
    m1CP13->Show(false);
    m1CP21->Show(false);
    m1CP22->Show(false);
    m1CP23->Show(false);
    m1StaticText26->Show(false);
    m1StaticText27->Show(false);
    m1StaticText31->Show(false);
    //m1StaticText32->Show(false);
    m1Line4->Show(false);
    m1StaticText28->Show(false);
    m1StaticText29->Show(false);
    m1StaticText30->Show(false);

    m1TimePanel = new wxPanel(panelM1, wxID_ANY, wxPoint(0,h1-26), wxSize(w1,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    m1TimePanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    m1ButtonPanel = new wxPanel(panelM1, wxID_ANY, wxPoint(x1+w2-w3,y1), wxSize(w3,h2-26), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    m1ButtonPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelSet = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSet->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    setStaticText1 = new wxStaticText(panelSet, wxID_ANY, _("时间设置"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    setLine1 = new wxStaticLine(panelSet, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    setTimePanel = new wxPanel(panelSet, wxID_ANY, wxPoint(x1,y1), wxSize(w2,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    setTimePanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    setMeasTime = new wxMyTextCtrl(setTimePanel, wxID_ANY, wxEmptyString, wxPoint(1,5), wxSize(98,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    setBackTime = new wxMyTextCtrl(setTimePanel, wxID_ANY, wxEmptyString, wxPoint(181,5), wxSize(98,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=35;
    setStaticText2 = new wxStaticText(panelSet, wxID_ANY, _("限差设置"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    setLine2 = new wxStaticLine(panelSet, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    setDevPanel = new wxPanel(panelSet, wxID_ANY, wxPoint(x1,y1), wxSize(w2,60), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    setDevPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    setDev1 = new wxMyTextCtrl(setDevPanel, wxID_ANY,wxEmptyString, wxPoint(61,1), wxSize(90,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    setDev2 = new wxMyTextCtrl(setDevPanel, wxID_ANY, wxEmptyString, wxPoint(151,1), wxSize(90,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    setDev3 = new wxMyTextCtrl(setDevPanel, wxID_ANY, wxEmptyString, wxPoint(301,1), wxSize(90,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    setDev4 = new wxMyTextCtrl(setDevPanel, wxID_ANY, wxEmptyString, wxPoint(451,1), wxSize(90,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    setDev5 = new wxMyTextCtrl(setDevPanel, wxID_ANY, wxEmptyString, wxPoint(451,1), wxSize(90,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=65;
    setStaticText3 = new wxStaticText(panelSet, wxID_ANY, _("功能设置"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    setLine3 = new wxStaticLine(panelSet, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    funPanel = new wxPanel(panelSet, wxID_ANY, wxPoint(x1,y1), wxSize(w2,335), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    funPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    setLine4 = new wxStaticLine(funPanel, wxID_ANY, wxPoint(50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));

    panelUI = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelUI->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    uiStaticText1 = new wxStaticText(panelUI, wxID_ANY, _("界面显示"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    uiLine1 = new wxStaticLine(panelUI, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    uiElementPanel = new wxPanel(panelUI, wxID_ANY, wxPoint(x1,y1), wxSize(w2,215), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    uiElementPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y1+=220;
    uiStaticText2 = new wxStaticText(panelUI, wxID_ANY, _("警示设置"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    uiLine2 = new wxStaticLine(panelUI, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    uiCautionPanel = new wxPanel(panelUI, wxID_ANY, wxPoint(x1,y1), wxSize(w2,185), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    uiCautionPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelUser = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelUser->SetBackgroundColour(wxColor(239,239,239));

    x1=14;
    y1=9;
    w2=w1-x1*2;
    h2=h1-y1-15;
    userGridPanel = new wxPanel(panelUser, wxID_ANY, wxPoint(x1,y1), wxSize(w2-75,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    userGridPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    userList = new wxListView(userGridPanel, wxID_ANY, wxPoint(0,24), wxSize(w2-75,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    userButtonPanel = new wxPanel(panelUser, wxID_ANY, wxPoint(x1+w2-65,y1), wxSize(65,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    userButtonPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelLanguage = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelLanguage->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    langButton = new wxPanel(panelLanguage, wxID_ANY, wxPoint(x1,y1), wxSize(w2,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    langButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelNavi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintButton,0,this);
    panelButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionButton,0,this);
    panelButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveButton,0,this);
    panelButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickButton,0,this);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintBackground,0,this);
	panelNavi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintNavi,0,this);

    prjDutyPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintDuty,0,this);
    prjDutyPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionDuty,0,this);
    prjDutyPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveDuty,0,this);
    prjDutyPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickDuty,0,this);

    panelTypJack->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTypeJack,0,this);
    panelTypJack->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionTypeJack,0,this);
    panelTypJack->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveTypeJack,0,this);
    panelTypJack->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickTypeJack,0,this);

    panelNumJack->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintNumTbmaj,0,this);
    panelNumJack->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionNumTbmaj,0,this);
    panelNumJack->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveNumTbmaj,0,this);
    panelNumJack->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickNumTbmaj,0,this);

    panelAngJack->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintAngTbmaj,0,this);
    panelAngJack->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionAngTbmaj,0,this);
    panelAngJack->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveAngTbmaj,0,this);
    panelAngJack->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickAngTbmaj,0,this);

    panelJackList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintAjlistHeader,0,this);

    keyRoadPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintRoad,0,this);
    keyRoadPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionRoad,0,this);
    keyRoadPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveRoad,0,this);
    keyRoadPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickRoad,0,this);

    keyGridPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintKeyGrid,0,this);

    keyButton1Panel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintKeyButton1,0,this);
    keyButton1Panel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionKeyButton1,0,this);
    keyButton1Panel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveKeyButton1,0,this);
    keyButton1Panel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickKeyButton1,0,this);

    keyList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&ConfigDlg::OnListKeyActivated,0,this);

    tbmPanelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTbmPage,0,this);
    tbmPanelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionTbmPage,0,this);
    tbmPanelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveTbmPage,0,this);
    tbmPanelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickTbmPage,0,this);

    tbmKinkPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintKink,0,this);
    tbmKinkPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionKink,0,this);
    tbmKinkPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveKink,0,this);
    tbmKinkPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickKink,0,this);

    tbmFigPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTbmFig,0,this);
    tbmTxtPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTbmTxt,0,this);
    panelJackfig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTbmajFig,0,this);

    prismPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintPrismPanel,0,this);
    tarsButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTarButton,0,this);
    tarsButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionTarButton,0,this);
    tarsButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveTarButton,0,this);
    tarsButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickTarButton,0,this);

    tarsFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTarFig,0,this);
    tarsFig->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionTarFig,0,this);
    tarsFig->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveTarFig,0,this);
    tarsFig->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickTarFig,0,this);

    tpsSetPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintLaserSet,0,this);
    tpsSetPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionLaserSet,0,this);
    tpsSetPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveLaserSet,0,this);
    tpsSetPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickLaserSet,0,this);

    tpsFigPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintLaser,0,this);
    tpsFigPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionLaser,0,this);
    tpsFigPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveLaser,0,this);
    tpsFigPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickLaser,0,this);

    segFigPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintSegFig,0,this);
    segTxtPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintSegTxt,0,this);
    segTxtPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionSegTxt,0,this);
    segTxtPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveSegTxt,0,this);
    segTxtPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickSegTxt,0,this);

    blkButton1Panel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintBlkButton1,0,this);
    blkButton1Panel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionBlkButton1,0,this);
    blkButton1Panel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveBlkButton1,0,this);
    blkButton1Panel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickBlkButton1,0,this);

    blockList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&ConfigDlg::OnListBlockSelect,0,this);
    blockList->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&ConfigDlg::OnListBlockDeselect,0,this);
    blockList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&ConfigDlg::OnListBlockActivated,0,this);

    jackList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&ConfigDlg::OnListJackSelect,0,this);
    //jackList->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&ConfigDlg::OnListAjDeselect,0,this);
    //jackList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&ConfigDlg::OnListAjActivated,0,this);

    blkListPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintBlockList,0,this);
    blkFigPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintBlkFig,0,this);

    m1ButtonPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintM1Button,0,this);
    m1ButtonPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionM1Button,0,this);
    m1ButtonPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveM1Button,0,this);
    m1ButtonPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickM1Button,0,this);

    setTimePanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintSetTime,0,this);
    setDevPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintSetDev,0,this);

    funPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintSetFun,0,this);
    funPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionSetFun,0,this);
    funPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveSetFun,0,this);
    funPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickSetFun,0,this);

    uiElementPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintElement,0,this);
    uiElementPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionElement,0,this);
    uiElementPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveElement,0,this);
    uiElementPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickElement,0,this);

    uiCautionPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintCaution,0,this);
    uiCautionPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionCaution,0,this);
    uiCautionPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveCaution,0,this);
    uiCautionPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickCaution,0,this);

    userButtonPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintUserButton,0,this);
    userButtonPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionUserButton,0,this);
    userButtonPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveUserButton,0,this);
    userButtonPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickUserButton,0,this);

    userGridPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintUserGrid,0,this);
    userList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&ConfigDlg::OnListUserActivated,0,this);

    langButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintLanguage,0,this);
    langButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionLanguage,0,this);
    langButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveLanguage,0,this);
    langButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickLanguage,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickBottom,0,this);

    //panelButtonList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnButtonClick,0,this);

    //tbmD1->Connect(wxEVT_LEFT_UP, (wxObjectEventFunction)&ConfigDlg::OnTbmD0Click,0,this);
    //tbmD2->Connect(wxEVT_LEFT_UP, (wxObjectEventFunction)&ConfigDlg::OnTbmD1Click,0,this);

    //tbmD4->Connect(wxEVT_LEFT_UP, (wxObjectEventFunction)&ConfigDlg::OnTbmD3Click,0,this);
    //tbmD6->Connect(wxEVT_LEFT_UP, (wxObjectEventFunction)&ConfigDlg::OnTbmD6Click,0,this);

    m1TimePanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTimeFig,0,this);

    //*)

    Connect(wxEVT_TIMER,(wxObjectEventFunction)&ConfigDlg::OnTimer);
    timerStat.SetOwner(this);
    timerStat.Start(100,false);

    this->SetBackgroundColour(wxColor(245,248,250));

    /*panelButtonList->btn_height=30;
    panelButtonList->AddButton(_("工程设置"));
    panelButtonList->AddButton(_("关键区域"));
    panelButtonList->AddButton(_("盾构设置"));
    panelButtonList->AddButton(_("激光靶"));
    panelButtonList->AddButton(_("全站仪"));
    panelButtonList->AddButton(_("管环参数"));
    panelButtonList->AddButton(_("管块参数"));
    panelButtonList->AddButton(_("零位数据"));
    panelButtonList->AddButton(_("测量设置"));
    panelButtonList->AddButton(_("界面设置"));
    panelButtonList->AddButton(_("管环监测"));
    panelButtonList->AddButton(_("模拟运行"));
    panelButtonList->AddButton(_("用户权限"));
    panelButtonList->AddButton(_("语言设置"));
    panelButtonList->btn_clicked=0;*/
    int i=ID_FIG_BTN_LANG-ID_FIG_BTN_PRJ+1;
    modified=(int*)malloc(i*sizeof(int));
    memset(modified,0,i*sizeof(int));
/*    wxString str1;
    for(int j=0;j<i;j++)
    {
        str1+=wxString::Format(_("%d:%d, "),j,modified[j]);
    }
    wxMessageBox(str1);*/
    i=0;
    figLabel[i++]=_("工程设置");
    figLabel[i++]=_("关键区域");
    figLabel[i++]=_("盾构设置");
    figLabel[i++]=_("激光靶");
    figLabel[i++]=_("全站仪");
    figLabel[i++]=_("管环参数");
    figLabel[i++]=_("管块参数");
    figLabel[i++]=_("零位数据");
    figLabel[i++]=_("测量设置");
    figLabel[i++]=_("界面设置");
    //figLabel[i++]=_("管环监测");
    //figLabel[i++]=_("模拟运行");
    figLabel[i++]=_("用户权限");
    figLabel[i++]=_("语言设置");
    page=0;
    i=0;
    jackList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    jackList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,65);
    jackList->InsertColumn(i++,_("油缸"),wxLIST_FORMAT_CENTRE,65);
    jackList->InsertColumn(i++,_("角度"),wxLIST_FORMAT_CENTRE,85);

    i=0;
    keyList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    keyList->InsertColumn(i++,_("名称"),wxLIST_FORMAT_LEFT,180);
    keyList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,110);
    keyList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,110);

    i=0;
    blockList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,85);
    blockList->InsertColumn(i++,_("名称"),wxLIST_FORMAT_CENTRE,120);
    blockList->InsertColumn(i++,_("圆心角"),wxLIST_FORMAT_CENTRE,120);

    i=0;
    userList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    userList->InsertColumn(i++,_("名称"),wxLIST_FORMAT_CENTRE,130);
    userList->InsertColumn(i++,_("密码"),wxLIST_FORMAT_CENTRE,130);
    userList->InsertColumn(i++,_("权限"),wxLIST_FORMAT_CENTRE,130);
    ajname[0]=_("A 组");
    ajname[1]=_("B 组");
    ajname[2]=_("C 组");
    ajname[3]=_("D 组");
    ajname[4]=_("E 组");
    ajname[5]=_("F 组");
    ajname[6]=_("G 组");
    ajname[7]=_("H 组");
    ajname[8]=_("I 组");
    ajname[9]=_("J 组");
    jackType=ID_FIG_TBM_MAIN_JACK;

    checkBoxWidth=14;
    checkBoxHeight=14;
    radioBoxR1=7;
    radioBoxR2=4;
    tbmPage=ID_FIG_TBM_PAGE_GEN;

    m_msg=wxEmptyString;
    m_msgc=0;
    for(int i=0;i<20;i++)
    {
        settingErr[i]=0;
    }

    prjModified=keyModified=tbmModified=tarsModified=tpsModified=segModified=blockModified=m1Modified=settingModified=userModified=0;
    LoadDataBase();
    panelKey->Show(false);
    panelTars->Show(false);
    panelTbm->Show(false);
    panelTps->Show(false);
    panelSeg->Show(false);
    panelBlock->Show(false);
    panelM1->Show(false);
    panelSet->Show(false);
    panelUI->Show(false);
    panelUser->Show(false);
    panelLanguage->Show(false);
    panelPrj->Show(true);
    m1StaticText32->SetForegroundColour(wxColor(192,0,0));
    m1StaticText32->SetLabel(_("注：\n\n前端 —— 激光靶安装位置对应的盾构桶体的前端\n\n后端 —— 激光靶安装位置对应的盾构桶体的后端"));
}

ConfigDlg::~ConfigDlg()
{
    //confDlg=0;
}

void ConfigDlg::OnPaintTbmPage(wxPaintEvent& event)
{
    wxPaintDC dc(tbmPanelPage);
    int w,h;
    tbmPanelPage->GetSize(&w,&h);
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
        figButton[ID_FIG_TBM_PAGE_GEN].x=x1;
        figButton[ID_FIG_TBM_PAGE_GEN].y=y1;
        figButton[ID_FIG_TBM_PAGE_GEN].width=w1;
        figButton[ID_FIG_TBM_PAGE_GEN].height=h1;

        if(tbmPage==ID_FIG_TBM_PAGE_GEN || motion1==ID_FIG_TBM_PAGE_GEN)
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

            if(tbmPage!=ID_FIG_TBM_PAGE_GEN)
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
        memDC.DrawLabel(_("TBM参数"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);

        x1=x1+w1;
        figButton[ID_FIG_TBM_PAGE_JACK].x=x1;
        figButton[ID_FIG_TBM_PAGE_JACK].y=y1;
        figButton[ID_FIG_TBM_PAGE_JACK].width=w1;
        figButton[ID_FIG_TBM_PAGE_JACK].height=h1;
        if(tbmPage==ID_FIG_TBM_PAGE_JACK || motion1==ID_FIG_TBM_PAGE_JACK)
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
            if(tbmPage!=ID_FIG_TBM_PAGE_JACK)
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
        memDC.DrawLabel(_("油缸位置"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

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

void ConfigDlg::OnMotionTbmPage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_TBM_PAGE_GEN].y && y<figButton[ID_FIG_TBM_PAGE_GEN].y+figButton[ID_FIG_TBM_PAGE_GEN].height)
    {
        if(x>figButton[ID_FIG_TBM_PAGE_GEN].x && x<figButton[ID_FIG_TBM_PAGE_GEN].x+figButton[ID_FIG_TBM_PAGE_GEN].width)
        {
            motion1=ID_FIG_TBM_PAGE_GEN;
        }
        else if(x>figButton[ID_FIG_TBM_PAGE_JACK].x && x<figButton[ID_FIG_TBM_PAGE_JACK].x+figButton[ID_FIG_TBM_PAGE_JACK].width)
        {
            motion1=ID_FIG_TBM_PAGE_JACK;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    tbmPanelPage->Refresh();
}

void ConfigDlg::OnLeaveTbmPage(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    tbmPanelPage->Refresh();
}

void ConfigDlg::OnClickTbmPage(wxMouseEvent& event)
{
    if(motion1==ID_FIG_TBM_PAGE_GEN)
    {
        tbmPage=ID_FIG_TBM_PAGE_GEN;
        panelTbmgen->Show(true);
        panelTbmJack->Show(false);
    }
    else if(motion1==ID_FIG_TBM_PAGE_JACK)
    {
        tbmPage=ID_FIG_TBM_PAGE_JACK;
        panelTbmgen->Show(false);
        panelTbmJack->Show(true);
    }
    tbmPanelPage->Refresh();
}

void ConfigDlg::OnPaintButton(wxPaintEvent& event)
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
        memDC.DrawRectangle(0,10,w,h-10);
        memDC.SetBrush(wxBrush(wxColor(255,255,255),wxBDIAGONAL_HATCH));
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawRectangle(0,10,w,h-10);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetTextForeground(wxColor(71,71,71));
        memDC.SetFont(chs);
        int x,y,x2;
        int r,g,b;
        int btns=ID_FIG_BTN_LANG-ID_FIG_BTN_PRJ+1;
        int btn_h=36.0*sy;
        for(int i=0;i<btns;i++)
        {
            y=11+i*btn_h;
            x=1;
            x2=w-1;
            figButton[ID_FIG_BTN_PRJ+i].x=x;
            figButton[ID_FIG_BTN_PRJ+i].y=y;
            figButton[ID_FIG_BTN_PRJ+i].width=w-2;
            figButton[ID_FIG_BTN_PRJ+i].height=btn_h;

            if(motion1==ID_FIG_BTN_PRJ+i)
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
            if(page==i)
            {
                memDC.DrawLabel(_("◆ ")+figLabel[i],wxRect(10,y-btn_h+2,w-20,btn_h-1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(_("◇ ")+figLabel[i],wxRect(10,y-btn_h+2,w-20,btn_h-1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            //memDC.DrawLabel(btn_label[i],wxRect(x+w/10,y-btn_height+2,w*9/10,btn_height-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionButton(wxMouseEvent& event)
{
    int x,y;
    int w,h;
    x=event.GetX();
    y=event.GetY();
    panelButton->GetClientSize(&w,&h);
    int btns=ID_FIG_BTN_LANG-ID_FIG_BTN_PRJ+1;
    for(int i=0;i<btns;i++)
    {
        if(x>figButton[ID_FIG_BTN_PRJ+i].x && x<figButton[ID_FIG_BTN_PRJ+i].x+figButton[ID_FIG_BTN_PRJ+i].width)
        {
            if(y>figButton[ID_FIG_BTN_PRJ+i].y && y<figButton[ID_FIG_BTN_PRJ+i].y+figButton[ID_FIG_BTN_PRJ+i].height)
            {
                motion1=ID_FIG_BTN_PRJ+i;
                break;
            }
            else if(i==btns-1)
            {
                motion1=ID_FIG_NONE;
                break;
            }
            else
            {
                continue;
            }
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    //btn_left_down=-1;
    panelButton->Refresh();
}

void ConfigDlg::OnLeaveButton(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    panelButton->Refresh();
}

void ConfigDlg::OnClickButton(wxMouseEvent& event)
{
    if(motion1>=ID_FIG_BTN_PRJ)
    {
        int ifun=motion1-ID_FIG_BTN_PRJ;
        FigRun(ifun);
    }
    panelButton->Refresh();
}

void ConfigDlg::FigRun(int ifun)
{
    switch(ifun)
    {
    case 0:
        page=ifun;
        panelKey->Show(false);
        panelTars->Show(false);
        panelTbm->Show(false);
        panelTps->Show(false);
        panelSeg->Show(false);
        panelBlock->Show(false);
        panelM1->Show(false);
        panelSet->Show(false);
        panelUI->Show(false);
        panelUser->Show(false);
        panelLanguage->Show(false);
        panelPrj->Show(true);
        op1=ID_FIG_NONE;
        break;
    case 1:
        page=ifun;
        panelTars->Show(false);
        panelPrj->Show(false);
        panelTbm->Show(false);
        panelTps->Show(false);
        panelSeg->Show(false);
        panelBlock->Show(false);
        panelM1->Show(false);
        panelSet->Show(false);
        panelUI->Show(false);
        panelUser->Show(false);
        panelLanguage->Show(false);
        panelKey->Show(true);
        op1=ID_FIG_NONE;
        break;
    case 2:
        page=ifun;
        panelKey->Show(false);
        panelPrj->Show(false);
        panelTars->Show(false);
        panelTps->Show(false);
        panelSeg->Show(false);
        panelBlock->Show(false);
        panelM1->Show(false);
        panelSet->Show(false);
        panelUI->Show(false);
        panelUser->Show(false);
        panelLanguage->Show(false);
        panelTbm->Show(true);
        op1=ID_FIG_NONE;
        break;
    case 3:
        page=ifun;
        panelKey->Show(false);
        panelPrj->Show(false);
        panelTbm->Show(false);
        panelTps->Show(false);
        panelSeg->Show(false);
        panelBlock->Show(false);
        panelM1->Show(false);
        panelSet->Show(false);
        panelUI->Show(false);
        panelUser->Show(false);
        panelLanguage->Show(false);
        panelTars->Show(true);
        op1=ID_FIG_NONE;
        break;
    case 4:
        page=ifun;
        panelKey->Show(false);
        panelPrj->Show(false);
        panelTbm->Show(false);
        panelSeg->Show(false);
        panelBlock->Show(false);
        panelM1->Show(false);
        panelTars->Show(false);
        panelSet->Show(false);
        panelUI->Show(false);
        panelUser->Show(false);
        panelLanguage->Show(false);
        panelTps->Show(true);
        op1=ID_FIG_NONE;
        break;
    case 5:
        page=ifun;
        panelKey->Show(false);
        panelPrj->Show(false);
        panelTbm->Show(false);
        panelBlock->Show(false);
        panelM1->Show(false);
        panelTps->Show(false);
        panelTars->Show(false);
        panelSet->Show(false);
        panelUI->Show(false);
        panelUser->Show(false);
        panelLanguage->Show(false);
        panelSeg->Show(true);
        op1=ID_FIG_NONE;
        break;
    case 6:
        page=ifun;
        panelKey->Show(false);
        panelPrj->Show(false);
        panelTbm->Show(false);
        panelM1->Show(false);
        panelSeg->Show(false);
        panelTps->Show(false);
        panelTars->Show(false);
        panelSet->Show(false);
        panelUI->Show(false);
        panelUser->Show(false);
        panelLanguage->Show(false);
        panelBlock->Show(true);
        op1=ID_FIG_NONE;
        break;
    case 7:
        page=ifun;
        panelKey->Show(false);
        panelPrj->Show(false);
        panelTbm->Show(false);
        panelSeg->Show(false);
        panelTps->Show(false);
        panelTars->Show(false);
        panelBlock->Show(false);
        panelSet->Show(false);
        panelUI->Show(false);
        panelUser->Show(false);
        panelLanguage->Show(false);
        panelM1->Show(true);
        op1=ID_FIG_NONE;
        break;
    case 8:
        page=ifun;
        panelKey->Show(false);
        panelPrj->Show(false);
        panelTbm->Show(false);
        panelSeg->Show(false);
        panelTps->Show(false);
        panelTars->Show(false);
        panelBlock->Show(false);
        panelM1->Show(false);
        panelUI->Show(false);
        panelUser->Show(false);
        panelLanguage->Show(false);
        panelSet->Show(true);
        op1=ID_FIG_NONE;
        break;
    case 9:
        page=ifun;
        panelKey->Show(false);
        panelPrj->Show(false);
        panelTbm->Show(false);
        panelSeg->Show(false);
        panelTps->Show(false);
        panelTars->Show(false);
        panelBlock->Show(false);
        panelM1->Show(false);
        panelSet->Show(false);
        panelLanguage->Show(false);
        panelUser->Show(false);
        panelUI->Show(true);
        op1=ID_FIG_NONE;
        break;
    case 10:
        page=ifun;
        panelKey->Show(false);
        panelPrj->Show(false);
        panelTbm->Show(false);
        panelSeg->Show(false);
        panelTps->Show(false);
        panelTars->Show(false);
        panelBlock->Show(false);
        panelM1->Show(false);
        panelSet->Show(false);
        panelUI->Show(false);
        panelLanguage->Show(false);
        panelUser->Show(true);
        op1=ID_FIG_NONE;
        break;
    case 11:
        page=ifun;
        panelKey->Show(false);
        panelPrj->Show(false);
        panelTbm->Show(false);
        panelSeg->Show(false);
        panelTps->Show(false);
        panelTars->Show(false);
        panelBlock->Show(false);
        panelM1->Show(false);
        panelSet->Show(false);
        panelUI->Show(false);
        panelUser->Show(false);
        panelLanguage->Show(true);
        op1=ID_FIG_NONE;
        break;
    default:
        break;
    }
}

void ConfigDlg::OnPaintDuty(wxPaintEvent& event)
{
    wxPaintDC dc(prjDutyPanel);
    int w,h;
    prjDutyPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w/4;
        h1=h;
        figButton[ID_FIG_DUTY_SUB].x=x1;
        figButton[ID_FIG_DUTY_SUB].y=y1;
        figButton[ID_FIG_DUTY_SUB].width=w1;
        figButton[ID_FIG_DUTY_SUB].height=h1;

        if(motion1==ID_FIG_DUTY_SUB)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }


        x1=w-w1;
        figButton[ID_FIG_DUTY_ADD].x=x1;
        figButton[ID_FIG_DUTY_ADD].y=y1;
        figButton[ID_FIG_DUTY_ADD].width=w1;
        figButton[ID_FIG_DUTY_ADD].height=h1;
        if(motion1==ID_FIG_DUTY_ADD)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        memDC.SetTextForeground(icolor[0]);
        //memDC.DrawLabel(wxString::Format(_("%d"),mtg->ndty),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),ndty),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionDuty(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_DUTY_SUB].x && x<figButton[ID_FIG_DUTY_SUB].x+figButton[ID_FIG_DUTY_SUB].width)
    {
        if(y>figButton[ID_FIG_DUTY_SUB].y && y<figButton[ID_FIG_DUTY_SUB].y+figButton[ID_FIG_DUTY_SUB].height)
        {
            motion1=ID_FIG_DUTY_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_DUTY_ADD].x && x<figButton[ID_FIG_DUTY_ADD].x+figButton[ID_FIG_DUTY_ADD].width)
    {
        if(y>figButton[ID_FIG_DUTY_ADD].y && y<figButton[ID_FIG_DUTY_ADD].y+figButton[ID_FIG_DUTY_ADD].height)
        {
            motion1=ID_FIG_DUTY_ADD;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    prjDutyPanel->Refresh();
}

void ConfigDlg::OnLeaveDuty(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    prjDutyPanel->Refresh();
}

void ConfigDlg::OnClickDuty(wxMouseEvent& event)
{
    if(motion1==ID_FIG_DUTY_ADD)
    {
        if(ndty<4)
        {
            ndty+=1;
            //prjModified=1;
        }
    }
    else if(motion1==ID_FIG_DUTY_SUB)
    {
        if(ndty>1)
        {
            ndty-=1;
            //prjModified=1;
        }
    }

    if(ndty==1)
    {
        prjStaticText9->Show(false);
        op2Name->Show(false);
        prjStaticText10->Show(false);
        op3Name->Show(false);
        prjStaticText11->Show(false);
        op4Name->Show(false);
        op1Name->SetFocus();
        op1Name->SetSelection(-1,-1);
    }
    else if(ndty==2)
    {
        prjStaticText9->Show(true);
        op2Name->Show(true);
        prjStaticText10->Show(false);
        op3Name->Show(false);
        prjStaticText11->Show(false);
        op4Name->Show(false);
        op2Name->SetFocus();
        op2Name->SetSelection(-1,-1);
    }
    else if(ndty==3)
    {
        prjStaticText9->Show(true);
        op2Name->Show(true);
        prjStaticText10->Show(true);
        op3Name->Show(true);
        prjStaticText11->Show(false);
        op4Name->Show(false);
        op3Name->SetFocus();
        op3Name->SetSelection(-1,-1);
    }
    else if(ndty==4)
    {
        prjStaticText9->Show(true);
        op2Name->Show(true);
        prjStaticText10->Show(true);
        op3Name->Show(true);
        prjStaticText11->Show(true);
        op4Name->Show(true);
        op4Name->SetFocus();
        op4Name->SetSelection(-1,-1);
    }
    prjDutyPanel->Refresh();
    panelBottom->Refresh();
}

void ConfigDlg::OnPaintAjlistHeader(wxPaintEvent& event)
{
    wxPaintDC dc(panelJackList);
    int w,h;
    panelJackList->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=h;
        memDC.DrawLine(x1,y1+h1,w,y1+h1);

        int i=1;
        w1=jackList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=jackList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("油缸"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=jackList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("角度"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintNumTbmaj(wxPaintEvent& event)
{
    wxPaintDC dc(panelNumJack);
    int w,h;
    panelNumJack->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w/4;
        h1=h;
        figButton[ID_FIG_TBM_SUB_JACK].x=x1;
        figButton[ID_FIG_TBM_SUB_JACK].y=y1;
        figButton[ID_FIG_TBM_SUB_JACK].width=w1;
        figButton[ID_FIG_TBM_SUB_JACK].height=h1;
        if(jackType==ID_FIG_TBM_MAIN_JACK)
        {
            if(motion1==ID_FIG_TBM_SUB_JACK)
            {
                memDC.SetBrush(ibrush[1]);
                memDC.SetPen(ipen[1]);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetBrush(ibrush[0]);
                memDC.SetPen(ipen[0]);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(168,168,168)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        x1=w-w1;
        figButton[ID_FIG_TBM_ADD_JACK].x=x1;
        figButton[ID_FIG_TBM_ADD_JACK].y=y1;
        figButton[ID_FIG_TBM_ADD_JACK].width=w1;
        figButton[ID_FIG_TBM_ADD_JACK].height=h1;
        if(jackType==ID_FIG_TBM_MAIN_JACK)
        {
            if(motion1==ID_FIG_TBM_ADD_JACK)
            {
                memDC.SetBrush(ibrush[1]);
                memDC.SetPen(ipen[1]);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetBrush(ibrush[0]);
                memDC.SetPen(ipen[0]);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(168,168,168)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        memDC.SetTextForeground(icolor[0]);
        if(jackType==ID_FIG_TBM_MAIN_JACK)
            memDC.DrawLabel(wxString::Format(_("%d"),tbm.naj),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        else if(jackType==ID_FIG_TBM_TAIL_JACK)
            memDC.DrawLabel(wxString::Format(_("%d"),tbm.nbj),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        else if(jackType==ID_FIG_TBM_HEAD_JACK)
            memDC.DrawLabel(wxString::Format(_("%d"),tbm.nfj),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLabel(wxString::Format(_("%d"),ndty),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionNumTbmaj(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_TBM_SUB_JACK].x && x<figButton[ID_FIG_TBM_SUB_JACK].x+figButton[ID_FIG_TBM_SUB_JACK].width)
    {
        if(y>figButton[ID_FIG_TBM_SUB_JACK].y && y<figButton[ID_FIG_TBM_SUB_JACK].y+figButton[ID_FIG_TBM_SUB_JACK].height)
        {
            motion1=ID_FIG_TBM_SUB_JACK;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_TBM_ADD_JACK].x && x<figButton[ID_FIG_TBM_ADD_JACK].x+figButton[ID_FIG_TBM_ADD_JACK].width)
    {
        if(y>figButton[ID_FIG_TBM_ADD_JACK].y && y<figButton[ID_FIG_TBM_ADD_JACK].y+figButton[ID_FIG_TBM_ADD_JACK].height)
        {
            motion1=ID_FIG_TBM_ADD_JACK;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    panelNumJack->Refresh();
}

void ConfigDlg::OnLeaveNumTbmaj(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    panelNumJack->Refresh();
}

void ConfigDlg::OnClickNumTbmaj(wxMouseEvent& event)
{
    if(motion1==ID_FIG_TBM_ADD_JACK)
    {
        if(jackType==ID_FIG_TBM_MAIN_JACK)
        {
            if(tbm.naj>=6) return;
            tbm.naj++;
            UpdateJack();
            jackList->Select(tbm.naj-1);
            jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.aj[tbm.naj-1]*180.0/PI));
            panelJackfig->Refresh();
        }
        /*else if(jackType==ID_FIG_TBM_TAIL_JACK)
        {
            if(tbm.nbj>=10) return;
            tbm.nbj++;
            UpdateJack();
            jackList->Select(tbm.nbj-1);
            jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.bj[tbm.nbj-1]*180.0/PI));
            panelJackfig->Refresh();
        }
        else if(jackType==ID_FIG_TBM_HEAD_JACK)
        {
            if(tbm.nfj>=10) return;
            tbm.nfj++;
            UpdateJack();
            jackList->Select(tbm.nfj-1);
            jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.fj[tbm.nfj-1]*180.0/PI));
            panelJackfig->Refresh();
        }*/
    }
    else if(motion1==ID_FIG_TBM_SUB_JACK)
    {
        if(jackType==ID_FIG_TBM_MAIN_JACK)
        {
            if(tbm.naj<=4) return;
            tbm.naj--;
            UpdateJack();
            jackList->Select(tbm.naj-1);
            jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.aj[tbm.naj-1]*180.0/PI));
            panelJackfig->Refresh();
        }
        /*else if(jackType==ID_FIG_TBM_TAIL_JACK)
        {
            if(tbm.nbj<=4) return;
            tbm.nbj--;
            UpdateJack();
            jackList->Select(tbm.nbj-1);
            jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.bj[tbm.nbj-1]*180.0/PI));
            panelJackfig->Refresh();
        }
        else if(jackType==ID_FIG_TBM_HEAD_JACK)
        {
            if(tbm.nfj<=4) return;
            tbm.nfj--;
            UpdateJack();
            jackList->Select(tbm.nfj-1);
            jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.fj[tbm.nfj-1]*180.0/PI));
            panelJackfig->Refresh();
        }*/
    }

    panelNumJack->Refresh();
}

void ConfigDlg::OnPaintTypeJack(wxPaintEvent& event)
{
    wxPaintDC dc(panelTypJack);
    int w,h;
    panelTypJack->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont ens(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=75;
        h1=25;
        memDC.DrawLabel(_("油缸类型"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=100;
        w1=105;
        figButton[ID_FIG_TBM_MAIN_JACK].x=x1;
        figButton[ID_FIG_TBM_MAIN_JACK].y=y1;
        figButton[ID_FIG_TBM_MAIN_JACK].width=w1;
        figButton[ID_FIG_TBM_MAIN_JACK].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(jackType==ID_FIG_TBM_MAIN_JACK)
        {
            if(motion1==ID_FIG_TBM_MAIN_JACK)
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
            memDC.DrawLabel(_("主推进油缸"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_TBM_MAIN_JACK)
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
            memDC.DrawLabel(_("主推进油缸"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        w1=115;
        figButton[ID_FIG_TBM_TAIL_JACK].x=x1;
        figButton[ID_FIG_TBM_TAIL_JACK].y=y1;
        figButton[ID_FIG_TBM_TAIL_JACK].width=w1;
        figButton[ID_FIG_TBM_TAIL_JACK].height=h1;

        if(jackType==ID_FIG_TBM_TAIL_JACK)
        {
            if(motion1==ID_FIG_TBM_TAIL_JACK)
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
            memDC.DrawLabel(_("盾尾铰接油缸"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_TBM_TAIL_JACK)
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
            memDC.DrawLabel(_("盾尾铰接油缸"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        figButton[ID_FIG_TBM_HEAD_JACK].x=x1;
        figButton[ID_FIG_TBM_HEAD_JACK].y=y1;
        figButton[ID_FIG_TBM_HEAD_JACK].width=w1;
        figButton[ID_FIG_TBM_HEAD_JACK].height=h1;

        if(jackType==ID_FIG_TBM_HEAD_JACK)
        {
            if(motion1==ID_FIG_TBM_HEAD_JACK)
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
            memDC.DrawLabel(_("盾首铰接油缸"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_TBM_HEAD_JACK)
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
            memDC.DrawLabel(_("盾首铰接油缸"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1+=20;
        memDC.SetPen(wxPen(wxColor(160,160,160)));
        memDC.DrawLine(0,y1+12,w,y1+12);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(0,y1+13,w,y1+13);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionTypeJack(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_TBM_MAIN_JACK].y && y<figButton[ID_FIG_TBM_MAIN_JACK].y+figButton[ID_FIG_TBM_MAIN_JACK].height)
    {
        if(x>figButton[ID_FIG_TBM_MAIN_JACK].x && x<figButton[ID_FIG_TBM_MAIN_JACK].x+figButton[ID_FIG_TBM_MAIN_JACK].width)
        {
            motion1=ID_FIG_TBM_MAIN_JACK;
        }
        else if(x>figButton[ID_FIG_TBM_TAIL_JACK].x && x<figButton[ID_FIG_TBM_TAIL_JACK].x+figButton[ID_FIG_TBM_TAIL_JACK].width)
        {
            motion1=ID_FIG_TBM_TAIL_JACK;
        }
        else if(x>figButton[ID_FIG_TBM_HEAD_JACK].x && x<figButton[ID_FIG_TBM_HEAD_JACK].x+figButton[ID_FIG_TBM_HEAD_JACK].width)
        {
            motion1=ID_FIG_TBM_HEAD_JACK;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    panelTypJack->Refresh();
}

void ConfigDlg::OnLeaveTypeJack(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    panelTypJack->Refresh();
}

void ConfigDlg::OnClickTypeJack(wxMouseEvent& event)
{
    if(motion1==ID_FIG_TBM_MAIN_JACK)
    {
        jackType=ID_FIG_TBM_MAIN_JACK;
        tbmStaticText6->SetLabel(_("推进油缸组"));
        UpdateJack();
        jackList->Select(0);
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.aj[0]*180.0/PI));
        panelJackfig->Refresh();
        panelNumJack->Refresh();
    }
    else if(motion1==ID_FIG_TBM_TAIL_JACK)
    {
        jackType=ID_FIG_TBM_TAIL_JACK;
        tbmStaticText6->SetLabel(_("铰接油缸组"));
        UpdateJack();
        jackList->Select(0);
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.bj[0]*180.0/PI));
        panelJackfig->Refresh();
        panelNumJack->Refresh();
    }
    else if(motion1==ID_FIG_TBM_HEAD_JACK)
    {
        jackType=ID_FIG_TBM_HEAD_JACK;
        tbmStaticText6->SetLabel(_("铰接油缸组"));
        UpdateJack();
        jackList->Select(0);
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.fj[0]*180.0/PI));
        panelJackfig->Refresh();
        panelNumJack->Refresh();
    }

    panelTypJack->Refresh();
}

void ConfigDlg::OnPaintAngTbmaj(wxPaintEvent& event)
{
    wxPaintDC dc(panelAngJack);
    int w,h;
    panelAngJack->GetClientSize(&w,&h);
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
        wxFont chs1(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        wxFont chs2(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs1);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=90;
        h1=h;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        jackTxt->SetSize(x1+2,y1+3,w1-5,15);
        x1=x1+w1-1;
        w1=30;
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("°"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+7;
        w1=65;
        figButton[ID_FIG_TBM_SET_JACK].x=x1;
        figButton[ID_FIG_TBM_SET_JACK].y=y1;
        figButton[ID_FIG_TBM_SET_JACK].width=w1;
        figButton[ID_FIG_TBM_SET_JACK].height=h1;
        memDC.SetFont(chs2);
        if(motion1==ID_FIG_TBM_SET_JACK)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            memDC.DrawLabel(_("设置"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            memDC.DrawLabel(_("设置"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        //memDC.SetTextForeground(icolor[0]);
        //memDC.DrawLabel(_("设置"),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLabel(wxString::Format(_("%d"),ndty),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionAngTbmaj(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_TBM_SET_JACK].x && x<figButton[ID_FIG_TBM_SET_JACK].x+figButton[ID_FIG_TBM_SET_JACK].width)
    {
        if(y>figButton[ID_FIG_TBM_SET_JACK].y && y<figButton[ID_FIG_TBM_SET_JACK].y+figButton[ID_FIG_TBM_SET_JACK].height)
        {
            motion1=ID_FIG_TBM_SET_JACK;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    panelAngJack->Refresh();
}

void ConfigDlg::OnLeaveAngTbmaj(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    panelAngJack->Refresh();
}

void ConfigDlg::OnClickAngTbmaj(wxMouseEvent& event)
{
    if(motion1==ID_FIG_TBM_SET_JACK)
    {
        int sel=jackList->GetFirstSelected();
        if(sel<0 || sel>=10) return;
        if(jackType==ID_FIG_TBM_MAIN_JACK)
        {
            jackTxt->GetValue().ToDouble(&tbm.aj[sel]);
            tbm.aj[sel]=tbm.aj[sel]*PI/180.0;
            UpdateJack();
            jackList->Select(sel);
            panelJackfig->Refresh();
        }
        else if(jackType==ID_FIG_TBM_TAIL_JACK)
        {
            jackTxt->GetValue().ToDouble(&tbm.bj[sel]);
            tbm.bj[sel]=tbm.bj[sel]*PI/180.0;
            UpdateJack();
            jackList->Select(sel);
            panelJackfig->Refresh();
        }
        else if(jackType==ID_FIG_TBM_HEAD_JACK)
        {
            jackTxt->GetValue().ToDouble(&tbm.fj[sel]);
            tbm.fj[sel]=tbm.fj[sel]*PI/180.0;
            UpdateJack();
            jackList->Select(sel);
            panelJackfig->Refresh();
        }
    }

    panelAngJack->Refresh();
}

void ConfigDlg::OnPaintRoad(wxPaintEvent& event)
{
    wxPaintDC dc(keyRoadPanel);
    int w,h;
    keyRoadPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=100;
        h1=h;
        figButton[ID_FIG_HTIP].x=x1;
        figButton[ID_FIG_HTIP].y=y1;
        figButton[ID_FIG_HTIP].width=w1-20;
        figButton[ID_FIG_HTIP].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(prj.htip==0)
        {
            if(motion1==ID_FIG_HTIP)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("平曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("平曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_HTIP)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("平曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("平曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }


        x1=x1+w1-1;
        figButton[ID_FIG_VTIP].x=x1;
        figButton[ID_FIG_VTIP].y=y1;
        figButton[ID_FIG_VTIP].width=w1-20;
        figButton[ID_FIG_VTIP].height=h1;
        if(prj.vtip==0)
        {
            if(motion1==ID_FIG_VTIP)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("竖曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("竖曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_VTIP)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("竖曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("竖曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionRoad(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_HTIP].x && x<figButton[ID_FIG_HTIP].x+figButton[ID_FIG_HTIP].width)
    {
        if(y>figButton[ID_FIG_HTIP].y && y<figButton[ID_FIG_HTIP].y+figButton[ID_FIG_HTIP].height)
        {
            motion1=ID_FIG_HTIP;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_VTIP].x && x<figButton[ID_FIG_VTIP].x+figButton[ID_FIG_VTIP].width)
    {
        if(y>figButton[ID_FIG_VTIP].y && y<figButton[ID_FIG_VTIP].y+figButton[ID_FIG_VTIP].height)
        {
            motion1=ID_FIG_VTIP;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    keyRoadPanel->Refresh();
}

void ConfigDlg::OnLeaveRoad(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    keyRoadPanel->Refresh();
}

void ConfigDlg::OnClickRoad(wxMouseEvent& event)
{
    if(motion1==ID_FIG_HTIP)
    {
        if(prj.htip==0)
        {
            prj.htip=1;
        }
        else
        {
            prj.htip=0;
        }
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_VTIP)
    {
        if(prj.vtip==0)
        {
            prj.vtip=1;
        }
        else
        {
            prj.vtip=0;
        }
        //prjModified=1;
        panelBottom->Refresh();
    }
    keyRoadPanel->Refresh();
}

void ConfigDlg::OnPaintKeyGrid(wxPaintEvent& event)
{
    wxPaintDC dc(keyGridPanel);
    int w,h;
    keyGridPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=24;
        memDC.DrawLine(x1,y1+h1,w,y1+h1);

        w1=keyList->GetColumnWidth(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=keyList->GetColumnWidth(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("关键区域名称"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=keyList->GetColumnWidth(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起点里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=keyList->GetColumnWidth(3);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("终点里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintKeyButton1(wxPaintEvent& event)
{
    wxPaintDC dc(keyButton1Panel);
    int w,h;
    keyButton1Panel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=25;

        figButton[ID_FIG_KEY_ADD].x=x1+1;
        figButton[ID_FIG_KEY_ADD].y=y1+1;
        figButton[ID_FIG_KEY_ADD].width=w1-1;
        figButton[ID_FIG_KEY_ADD].height=h1-2;
        if(motion1==ID_FIG_KEY_ADD)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRoundedRectangle(figButton[ID_FIG_KEY_ADD],3);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawRoundedRectangle(figButton[ID_FIG_KEY_ADD],3);
        }
        memDC.DrawLabel(_("添加"),wxRect(figButton[ID_FIG_KEY_ADD]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+7;
        figButton[ID_FIG_KEY_EDI].x=x1+1;
        figButton[ID_FIG_KEY_EDI].y=y1+1;
        figButton[ID_FIG_KEY_EDI].width=w1-1;
        figButton[ID_FIG_KEY_EDI].height=h1-2;
        if(motion1==ID_FIG_KEY_EDI)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRoundedRectangle(figButton[ID_FIG_KEY_EDI],3);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawRoundedRectangle(figButton[ID_FIG_KEY_EDI],3);
        }
        memDC.DrawLabel(_("编辑"),wxRect(figButton[ID_FIG_KEY_EDI]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+7;
        figButton[ID_FIG_KEY_DEL].x=x1+1;
        figButton[ID_FIG_KEY_DEL].y=y1+1;
        figButton[ID_FIG_KEY_DEL].width=w1-1;
        figButton[ID_FIG_KEY_DEL].height=h1-2;
        if(motion1==ID_FIG_KEY_DEL)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRoundedRectangle(figButton[ID_FIG_KEY_DEL],3);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawRoundedRectangle(figButton[ID_FIG_KEY_DEL],3);
        }

        memDC.DrawLabel(_("删除"),wxRect(figButton[ID_FIG_KEY_DEL]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionKeyButton1(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_KEY_ADD].x && x<figButton[ID_FIG_KEY_ADD].x+figButton[ID_FIG_KEY_ADD].width)
    {
        if(y>figButton[ID_FIG_KEY_ADD].y && y<figButton[ID_FIG_KEY_ADD].y+figButton[ID_FIG_KEY_ADD].height)
        {
            motion1=ID_FIG_KEY_ADD;
        }
        else if(y>figButton[ID_FIG_KEY_EDI].y && y<figButton[ID_FIG_KEY_EDI].y+figButton[ID_FIG_KEY_EDI].height)
        {
            motion1=ID_FIG_KEY_EDI;
        }
        else if(y>figButton[ID_FIG_KEY_DEL].y && y<figButton[ID_FIG_KEY_DEL].y+figButton[ID_FIG_KEY_DEL].height)
        {
            motion1=ID_FIG_KEY_DEL;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    keyButton1Panel->Refresh();
}

void ConfigDlg::OnLeaveKeyButton1(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    keyButton1Panel->Refresh();
}

void ConfigDlg::OnClickKeyButton1(wxMouseEvent& event)
{
    if(mtg->onLine>0) return;
    //if(opLevel>0) return;
    wxString str1;
    double val;
    if(motion1==ID_FIG_KEY_ADD)
    {
        KeyDlg dlg(this);
        dlg.Center();
        dlg.a2z=prj.a2z;
        dlg.p1=prj.mile1;
        dlg.p2=prj.mile2;
        dlg.tip=prj.tip;
        dlg.keyName->SetFocus();
        if(dlg.ShowModal()==wxID_OK)
        {
            if(nks<1999)
            {
                strncpy(keys[nks].name,dlg.keyName->GetValue().mb_str(wxConvUTF8),64);
                dlg.mile1->GetValue().ToDouble(&keys[nks].mile1);
                dlg.mile2->GetValue().ToDouble(&keys[nks].mile2);
                if(keys[nks].mile2==0) keys[nks].mile2=keys[nks].mile1;
                nks++;
                WriteMsg(_("成功添加关键区域"),0);
                UpdateKeys();
                keyList->Select(nks);
                panelBottom->Refresh();
            }
        }
    }
    else if(motion1==ID_FIG_KEY_EDI)
    {
        int n = keyList->GetFirstSelected();
        int Num = keyList->GetItemCount();
        if(n<0 || n>Num-1) return;

        KeyDlg dlg(this);
        dlg.Center();
        dlg.keyName->SetValue(wxString(keys[n].name,wxConvUTF8));
        dlg.mile1->SetValue(wxString::Format(_("%.3f"),keys[n].mile1));
        dlg.mile2->SetValue(wxString::Format(_("%.3f"),keys[n].mile2));
        dlg.a2z=prj.a2z;
        dlg.p1=prj.mile1;
        dlg.p2=prj.mile2;
        dlg.tip=prj.tip;
        if(dlg.ShowModal()==wxID_OK)
        {
            strncpy(keys[n].name,dlg.keyName->GetValue().mb_str(wxConvUTF8),64);
            dlg.mile1->GetValue().ToDouble(&keys[n].mile1);
            dlg.mile2->GetValue().ToDouble(&keys[n].mile2);
            if(keys[n].mile2==0) keys[n].mile2=keys[n].mile1;
            WriteMsg(_("成功编辑关键区域"),0);
            UpdateKeys();
            keyList->Select(n);
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_KEY_DEL)
    {
        int n = keyList->GetFirstSelected();
        int Num = keyList->GetItemCount();
        if(n<0 || n>Num-1) return;

        nks--;
        for(int i=n;i<nks;i++)
        {
            user[i]=user[i+1];
        }
        UpdateKeys();
        if(n<nks)
        {
            keyList->Select(n);
            keyList->EnsureVisible(n);
        }
        else if(n>0)
        {
            keyList->Select(n-1);
            keyList->EnsureVisible(n-1);
        }
    }
    keyButton1Panel->Refresh();
}

void ConfigDlg::OnPaintKink(wxPaintEvent& event)
{
    wxPaintDC dc(tbmKinkPanel);
    int w,h;
    tbmKinkPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=100;
        h1=h;
        figButton[ID_FIG_KINK1].x=x1;
        figButton[ID_FIG_KINK1].y=y1;
        figButton[ID_FIG_KINK1].width=w1;
        figButton[ID_FIG_KINK1].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(tbm.type==1 || tbm.type==3)
        {
            if(motion1==ID_FIG_KINK1)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾尾铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾尾铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

        }
        else
        {
            if(motion1==ID_FIG_KINK1)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾尾铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾尾铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1=x1+w1-1;
        figButton[ID_FIG_KINK2].x=x1;
        figButton[ID_FIG_KINK2].y=y1;
        figButton[ID_FIG_KINK2].width=w1;
        figButton[ID_FIG_KINK2].height=h1;
        if(tbm.type==2 || tbm.type==3)
        {
            if(motion1==ID_FIG_KINK2)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾首铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾首铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_KINK2)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾首铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾首铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionKink(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_KINK1].x && x<figButton[ID_FIG_KINK1].x+figButton[ID_FIG_KINK1].width)
    {
        if(y>figButton[ID_FIG_KINK1].y && y<figButton[ID_FIG_KINK1].y+figButton[ID_FIG_KINK1].height)
        {
            motion1=ID_FIG_KINK1;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_KINK2].x && x<figButton[ID_FIG_KINK2].x+figButton[ID_FIG_KINK2].width)
    {
        if(y>figButton[ID_FIG_KINK2].y && y<figButton[ID_FIG_KINK2].y+figButton[ID_FIG_KINK2].height)
        {
            motion1=ID_FIG_KINK2;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    tbmKinkPanel->Refresh();
}

void ConfigDlg::OnLeaveKink(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    tbmKinkPanel->Refresh();
}

void ConfigDlg::OnClickKink(wxMouseEvent& event)
{
    if(motion1==ID_FIG_KINK1)
    {
        if(tbm.type==0)
        {
            tbm.type=1;
        }
        else if(tbm.type==1)
        {
            tbm.type=0;
        }
        else if(tbm.type==2)
        {
            tbm.type=3;
        }
        else if(tbm.type==3)
        {
            tbm.type=2;
        }
        //tbmModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_KINK2)
    {
        if(tbm.type==0)
        {
            tbm.type=2;
            if(tars.pos!=1)
            {
                tars.pos=1;
                tarsModified=1;
                modified[3]=1;
            }
        }
        else if(tbm.type==1)
        {
            tbm.type=3;
            if(tars.pos!=1)
            {
                tars.pos=1;
                tarsModified=1;
                modified[3]=1;
            }
        }
        else if(tbm.type==2)
        {
            tbm.type=0;
            if(tars.pos!=0)
            {
                tars.pos=0;
                tarsModified=1;
                modified[3]=1;
            }
        }
        else if(tbm.type==3)
        {
            tbm.type=1;
            if(tars.pos!=0)
            {
                tars.pos=0;
                tarsModified=1;
                modified[3]=1;
            }
        }
        //tbmModified=1;
        panelBottom->Refresh();
    }

    if(tbm.type==0)
    {
        //tbmL1->Enable(false);
        tbmL2->Enable(false);
        tbmL3->Enable(false);
        tbmL5->Enable(false);
        tbmL6->Enable(false);
        tbmL7->Enable(false);
        tbmL8->Enable(false);
        tbmD2->Enable(false);
        tbmD3->Enable(false);
        tbmD4->Enable(false);
        tbmD5->Enable(false);
    }
    else if(tbm.type==1)
    {
        //tbmL1->Enable(false);
        tbmL2->Enable(false);
        tbmL3->Enable(true);
        tbmL5->Enable(false);
        tbmL6->Enable(false);
        tbmL7->Enable(true);
        tbmL8->Enable(true);
        tbmD2->Enable(false);
        tbmD3->Enable(false);
        tbmD4->Enable(true);
        tbmD5->Enable(true);
    }
    else if(tbm.type==2)
    {
        //tbmL1->Enable(true);
        tbmL2->Enable(false);
        tbmL3->Enable(true);
        tbmL5->Enable(true);
        tbmL6->Enable(true);
        tbmL7->Enable(false);
        tbmL8->Enable(false);
        tbmD2->Enable(true);
        tbmD3->Enable(true);
        tbmD4->Enable(false);
        tbmD5->Enable(false);
    }
    else if(tbm.type==3)
    {
        //tbmL1->Enable(true);
        tbmL2->Enable(true);
        tbmL3->Enable(true);
        tbmL5->Enable(true);
        tbmL6->Enable(true);
        tbmL7->Enable(true);
        tbmL8->Enable(true);
        tbmD2->Enable(true);
        tbmD3->Enable(true);
        tbmD4->Enable(true);
        tbmD5->Enable(true);
    }

    tbmKinkPanel->Refresh();
    tbmFigPanel->Refresh();
    tbmTxtPanel->Refresh();
}

void ConfigDlg::OnPaintTbmTxt(wxPaintEvent& event)
{
    wxPaintDC dc(tbmTxtPanel);
    int w,h;
    tbmTxtPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont ens(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=10;
        y1=2;
        w1=90;
        h1=22;
        memDC.DrawLabel(_("前盾(L1)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL1->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);

        y1+=28;
        memDC.DrawLabel(_("中盾(L2)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL2->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);

        y1+=28;
        memDC.DrawLabel(_("后盾(L3)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==0)
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL3->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        /*y1+=30;
        memDC.DrawLabel(_("前筒体长度(L2)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==2 || tbm.type==3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL1->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=30;
        memDC.DrawLabel(_("后筒体长度(L3)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==1 || tbm.type==3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL2->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);*/
        y1+=28;
        memDC.DrawLabel(_("推进油缸至切口(L4)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL4->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=28;
        memDC.DrawLabel(_("盾首铰接至切口(L5)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==2 || tbm.type==3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL5->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=28;
        memDC.DrawLabel(_("盾首铰接(L6)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==2 || tbm.type==3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL6->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);

        y1+=28;
        memDC.DrawLabel(_("盾尾铰接至切口(L7)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==1 || tbm.type==3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL7->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=28;
        memDC.DrawLabel(_("盾尾铰接(L8)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==1 || tbm.type==3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL8->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=28;
        memDC.DrawLabel(_("切口至刀盘(L9)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL9->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=28;
        memDC.DrawLabel(_("推进油缸直径(R1)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmD1->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=28;
        memDC.DrawLabel(_("盾首铰接直径后(R2)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==2 || tbm.type==3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmD2->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=28;
        memDC.DrawLabel(_("盾首铰接直径前(R3)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==2 || tbm.type==3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmD3->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=28;
        memDC.DrawLabel(_("盾尾铰接直径前(R4)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==1 || tbm.type==3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmD4->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=28;
        memDC.DrawLabel(_("盾尾铰接直径后(R5)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type==1 || tbm.type==3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmD5->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        //tbmL1->Show(false);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintPrismPanel(wxPaintEvent& event)
{
    wxPaintDC dc(prismPanel);
    int w,h;
    prismPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont ens(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);


        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(w-30,0,0,h),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tarsPrism->SetSize(2,5,w-34,h-6);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintTarButton(wxPaintEvent& event)
{
    wxPaintDC dc(tarsButton);
    int w,h;
    tarsButton->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1=0;
        int y1=0;
        int w1=65;
        int h1=h;
        figButton[ID_FIG_TFILE].x=x1;
        figButton[ID_FIG_TFILE].y=y1;
        figButton[ID_FIG_TFILE].width=w1;
        figButton[ID_FIG_TFILE].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(motion1==ID_FIG_TFILE)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
        }

        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("导入"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+7;
        figButton[ID_FIG_TFILE_EXP].x=x1;
        figButton[ID_FIG_TFILE_EXP].y=y1;
        figButton[ID_FIG_TFILE_EXP].width=w1;
        figButton[ID_FIG_TFILE_EXP].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(motion1==ID_FIG_TFILE_EXP)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
        }

        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("导出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintTarFig(wxPaintEvent& event)
{
    wxPaintDC dc(tarsFig);
    int w,h;
    tarsFig->GetClientSize(&w,&h);
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
        wxFont ens(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1;
        int w1,h1,l1;
        int p=tars.ipos;
        x1=300;
        w1=90;
        y1=25;
        h1=30;
        x1=300;
        h1=22;
        memDC.DrawLabel(_("棱镜常数"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+85;
        w1=100;
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        //memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1-15,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tarsPrism->SetSize(x1+2,y1+3,w1-19,h1-4);

        x1=300;
        y1=y1+h1+8;
        memDC.DrawLabel(_("棱镜位置\n\n周期测量"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+85;
        w1=100;
        figButton[ID_FIG_PRISM_DOWN].x=x1;
        figButton[ID_FIG_PRISM_DOWN].y=y1;
        figButton[ID_FIG_PRISM_DOWN].width=w1;
        figButton[ID_FIG_PRISM_DOWN].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(p==0)
        {
            if(motion1==ID_FIG_PRISM_DOWN)
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
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("位于下方"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_PRISM_DOWN)
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
            memDC.DrawLabel(_("位于下方"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        y1=y1+h1;
        figButton[ID_FIG_PRISM_LEFT].x=x1;
        figButton[ID_FIG_PRISM_LEFT].y=y1;
        figButton[ID_FIG_PRISM_LEFT].width=w1;
        figButton[ID_FIG_PRISM_LEFT].height=h1;

        if(p==2)
        {
            if(motion1==ID_FIG_PRISM_LEFT)
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
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("位于左侧"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_PRISM_LEFT)
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
            memDC.DrawLabel(_("位于左侧"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        y1=y1+h1;
        figButton[ID_FIG_PRISM_UP].x=x1;
        figButton[ID_FIG_PRISM_UP].y=y1;
        figButton[ID_FIG_PRISM_UP].width=w1;
        figButton[ID_FIG_PRISM_UP].height=h1;

        if(p==1)
        {
            if(motion1==ID_FIG_PRISM_UP)
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
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("位于上方"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_PRISM_UP)
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
            memDC.DrawLabel(_("位于上方"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        y1=y1+h1;
        figButton[ID_FIG_PRISM_RIGHT].x=x1;
        figButton[ID_FIG_PRISM_RIGHT].y=y1;
        figButton[ID_FIG_PRISM_RIGHT].width=w1;
        figButton[ID_FIG_PRISM_RIGHT].height=h1;

        if(p==3)
        {
            if(motion1==ID_FIG_PRISM_RIGHT)
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
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("位于右侧"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_PRISM_RIGHT)
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
            memDC.DrawLabel(_("位于右侧"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=300;
        y1=y1+h1+8;
        memDC.DrawLabel(_("棱镜位置\n\n零位测量"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+85;
        w1=100;
        figButton[ID_FIG_PRISM_ODOWN].x=x1;
        figButton[ID_FIG_PRISM_ODOWN].y=y1;
        figButton[ID_FIG_PRISM_ODOWN].width=w1;
        figButton[ID_FIG_PRISM_ODOWN].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(m1.ipos==0)
        {
            if(motion1==ID_FIG_PRISM_ODOWN)
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
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("位于下方"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_PRISM_ODOWN)
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
            memDC.DrawLabel(_("位于下方"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        y1=y1+h1;
        figButton[ID_FIG_PRISM_OLEFT].x=x1;
        figButton[ID_FIG_PRISM_OLEFT].y=y1;
        figButton[ID_FIG_PRISM_OLEFT].width=w1;
        figButton[ID_FIG_PRISM_OLEFT].height=h1;

        if(m1.ipos==2)
        {
            if(motion1==ID_FIG_PRISM_OLEFT)
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
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("位于左侧"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_PRISM_OLEFT)
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
            memDC.DrawLabel(_("位于左侧"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        y1=y1+h1;
        figButton[ID_FIG_PRISM_OUP].x=x1;
        figButton[ID_FIG_PRISM_OUP].y=y1;
        figButton[ID_FIG_PRISM_OUP].width=w1;
        figButton[ID_FIG_PRISM_OUP].height=h1;

        if(m1.ipos==1)
        {
            if(motion1==ID_FIG_PRISM_OUP)
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
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("位于上方"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_PRISM_OUP)
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
            memDC.DrawLabel(_("位于上方"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        y1=y1+h1;
        figButton[ID_FIG_PRISM_ORIGHT].x=x1;
        figButton[ID_FIG_PRISM_ORIGHT].y=y1;
        figButton[ID_FIG_PRISM_ORIGHT].width=w1;
        figButton[ID_FIG_PRISM_ORIGHT].height=h1;

        if(m1.ipos==3)
        {
            if(motion1==ID_FIG_PRISM_ORIGHT)
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
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("位于右侧"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_PRISM_ORIGHT)
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
            memDC.DrawLabel(_("位于右侧"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=300;
        y1=y1+h1+15;
        memDC.DrawLabel(_("安装位置"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+85;
        w1=100;

        if(tbm.type==0 || tbm.type==1)
        {
            figButton[ID_FIG_TAR_POS0].x=x1;
            figButton[ID_FIG_TAR_POS0].y=y1;
            figButton[ID_FIG_TAR_POS0].width=w1;
            figButton[ID_FIG_TAR_POS0].height=h1;
            memDC.SetTextForeground(wxColor(168,168,168));

            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            memDC.DrawLabel(_("安装于前盾"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            y1=y1+h1;
            figButton[ID_FIG_TAR_POS1].x=x1;
            figButton[ID_FIG_TAR_POS1].y=y1;
            figButton[ID_FIG_TAR_POS1].width=w1;
            figButton[ID_FIG_TAR_POS1].height=h1;
            memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            memDC.SetBrush(wxBrush(wxColor(ipen[0].GetColour())));
            memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            memDC.DrawLabel(_("安装于中盾"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            figButton[ID_FIG_TAR_POS0].x=x1;
            figButton[ID_FIG_TAR_POS0].y=y1;
            figButton[ID_FIG_TAR_POS0].width=w1;
            figButton[ID_FIG_TAR_POS0].height=h1;
            if(tars.pos==0)
            {
                if(motion1==ID_FIG_TAR_POS0)
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
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
                }
                memDC.DrawLabel(_("安装于前盾"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion1==ID_FIG_TAR_POS0)
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
                memDC.DrawLabel(_("安装于前盾"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            y1=y1+h1;
            figButton[ID_FIG_TAR_POS1].x=x1;
            figButton[ID_FIG_TAR_POS1].y=y1;
            figButton[ID_FIG_TAR_POS1].width=w1;
            figButton[ID_FIG_TAR_POS1].height=h1;

            if(tars.pos==1)
            {
                if(motion1==ID_FIG_TAR_POS1)
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
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
                }
                memDC.DrawLabel(_("安装于中盾"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion1==ID_FIG_TAR_POS1)
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
                memDC.DrawLabel(_("安装于中盾"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1=300;
        y1=y1+h1+15;
        memDC.DrawLabel(_("倾斜仪个数"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+85;
        w1=100;
        //y1=y1+h1;
        figButton[ID_FIG_TAR_SINGLE].x=x1;
        figButton[ID_FIG_TAR_SINGLE].y=y1;
        figButton[ID_FIG_TAR_SINGLE].width=w1;
        figButton[ID_FIG_TAR_SINGLE].height=h1;

        if(tars.incdb==0)
        {
            if(motion1==ID_FIG_TAR_SINGLE)
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
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("单个"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_TAR_SINGLE)
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
            memDC.DrawLabel(_("单个"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        y1=y1+h1;
        figButton[ID_FIG_TAR_DOUBLE].x=x1;
        figButton[ID_FIG_TAR_DOUBLE].y=y1;
        figButton[ID_FIG_TAR_DOUBLE].width=w1;
        figButton[ID_FIG_TAR_DOUBLE].height=h1;

        if(tars.incdb==1)
        {
            if(motion1==ID_FIG_TAR_DOUBLE)
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
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.DrawLabel(_("两个"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_TAR_DOUBLE)
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
            memDC.DrawLabel(_("两个"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }


        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x2,y2,w2,h2;
        w2=150;
        h2=120;
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

        lines[0].x=x2+60;
        lines[0].y=y2+38;
        lines[1].x=lines[0].x+30;
        lines[1].y=lines[0].y;
        lines[2].x=lines[1].x;
        lines[2].y=lines[0].y+20;
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

        lines[0].x=x2+75;
        lines[0].y=y2+116;
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        memDC.DrawLine(lines[0].x-10,lines[0].y,lines[0].x+10,lines[0].y);
        memDC.DrawLine(lines[0].x,lines[0].y-10,lines[0].x,lines[0].y+10);
        figButton[ID_FIG_PRISM_PDOWN].x=lines[0].x-20;
        figButton[ID_FIG_PRISM_PDOWN].y=lines[0].y-20;
        figButton[ID_FIG_PRISM_PDOWN].width=40;
        figButton[ID_FIG_PRISM_PDOWN].height=40;
        if(p==0 || motion1==ID_FIG_PRISM_PDOWN)
        {
            memDC.SetPen(wxPen(wxColor(133,137,141)));
            memDC.DrawCircle(lines[0],20);
        }
        lines[0].x=x2+4;
        lines[0].y=y2+48;
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        memDC.DrawLine(lines[0].x-10,lines[0].y,lines[0].x+10,lines[0].y);
        memDC.DrawLine(lines[0].x,lines[0].y-10,lines[0].x,lines[0].y+10);
        figButton[ID_FIG_PRISM_PLEFT].x=lines[0].x-20;
        figButton[ID_FIG_PRISM_PLEFT].y=lines[0].y-20;
        figButton[ID_FIG_PRISM_PLEFT].width=40;
        figButton[ID_FIG_PRISM_PLEFT].height=40;
        if(p==2 || motion1==ID_FIG_PRISM_PLEFT)
        {
            memDC.SetPen(wxPen(wxColor(133,137,141)));
            memDC.DrawCircle(lines[0],20);
        }
        lines[0].x=x2+75;
        lines[0].y=y2+4;
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        memDC.DrawLine(lines[0].x-10,lines[0].y,lines[0].x+10,lines[0].y);
        memDC.DrawLine(lines[0].x,lines[0].y-10,lines[0].x,lines[0].y+10);
        figButton[ID_FIG_PRISM_PUP].x=lines[0].x-20;
        figButton[ID_FIG_PRISM_PUP].y=lines[0].y-20;
        figButton[ID_FIG_PRISM_PUP].width=40;
        figButton[ID_FIG_PRISM_PUP].height=40;
        if(p==1 || motion1==ID_FIG_PRISM_PUP)
        {
            memDC.SetPen(wxPen(wxColor(133,137,141)));
            memDC.DrawCircle(lines[0],20);
        }
        lines[0].x=x2+145;
        lines[0].y=y2+48;
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        memDC.DrawLine(lines[0].x-10,lines[0].y,lines[0].x+10,lines[0].y);
        memDC.DrawLine(lines[0].x,lines[0].y-10,lines[0].x,lines[0].y+10);
        figButton[ID_FIG_PRISM_PRIGHT].x=lines[0].x-20;
        figButton[ID_FIG_PRISM_PRIGHT].y=lines[0].y-20;
        figButton[ID_FIG_PRISM_PRIGHT].width=40;
        figButton[ID_FIG_PRISM_PRIGHT].height=40;
        if(p==3 || motion1==ID_FIG_PRISM_PRIGHT)
        {
            memDC.SetPen(wxPen(wxColor(133,137,141)));
            memDC.DrawCircle(lines[0],20);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionTarFig(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();

    if(x>figButton[ID_FIG_PRISM_DOWN].x && x<figButton[ID_FIG_PRISM_DOWN].x+figButton[ID_FIG_PRISM_DOWN].width)
    {
        if(y>figButton[ID_FIG_PRISM_DOWN].y && y<figButton[ID_FIG_PRISM_DOWN].y+figButton[ID_FIG_PRISM_DOWN].height)
        {
            motion1=ID_FIG_PRISM_DOWN;
        }
        else if(y>figButton[ID_FIG_PRISM_LEFT].y && y<figButton[ID_FIG_PRISM_LEFT].y+figButton[ID_FIG_PRISM_LEFT].height)
        {
            motion1=ID_FIG_PRISM_LEFT;
        }
        else if(y>figButton[ID_FIG_PRISM_UP].y && y<figButton[ID_FIG_PRISM_UP].y+figButton[ID_FIG_PRISM_UP].height)
        {
            motion1=ID_FIG_PRISM_UP;
        }
        else if(y>figButton[ID_FIG_PRISM_RIGHT].y && y<figButton[ID_FIG_PRISM_RIGHT].y+figButton[ID_FIG_PRISM_RIGHT].height)
        {
            motion1=ID_FIG_PRISM_RIGHT;
        }
        else if(y>figButton[ID_FIG_TAR_POS0].y && y<figButton[ID_FIG_TAR_POS0].y+figButton[ID_FIG_TAR_POS0].height)
        {
            motion1=ID_FIG_TAR_POS0;
        }
        else if(y>figButton[ID_FIG_TAR_POS1].y && y<figButton[ID_FIG_TAR_POS1].y+figButton[ID_FIG_TAR_POS1].height)
        {
            motion1=ID_FIG_TAR_POS1;
        }
        else if(y>figButton[ID_FIG_TAR_POS2].y && y<figButton[ID_FIG_TAR_POS2].y+figButton[ID_FIG_TAR_POS2].height)
        {
            motion1=ID_FIG_TAR_POS2;
        }
        else if(y>figButton[ID_FIG_PRISM_ODOWN].y && y<figButton[ID_FIG_PRISM_ODOWN].y+figButton[ID_FIG_PRISM_ODOWN].height)
        {
            motion1=ID_FIG_PRISM_ODOWN;
        }
        else if(y>figButton[ID_FIG_PRISM_OLEFT].y && y<figButton[ID_FIG_PRISM_OLEFT].y+figButton[ID_FIG_PRISM_OLEFT].height)
        {
            motion1=ID_FIG_PRISM_OLEFT;
        }
        else if(y>figButton[ID_FIG_PRISM_OUP].y && y<figButton[ID_FIG_PRISM_OUP].y+figButton[ID_FIG_PRISM_OUP].height)
        {
            motion1=ID_FIG_PRISM_OUP;
        }
        else if(y>figButton[ID_FIG_PRISM_ORIGHT].y && y<figButton[ID_FIG_PRISM_ORIGHT].y+figButton[ID_FIG_PRISM_ORIGHT].height)
        {
            motion1=ID_FIG_PRISM_ORIGHT;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_PRISM_PDOWN].x && x<figButton[ID_FIG_PRISM_PDOWN].x+figButton[ID_FIG_PRISM_PDOWN].width)
    {
        if(y>figButton[ID_FIG_PRISM_PDOWN].y && y<figButton[ID_FIG_PRISM_PDOWN].y+figButton[ID_FIG_PRISM_PDOWN].height)
        {
            motion1=ID_FIG_PRISM_PDOWN;
        }
        else if(y>figButton[ID_FIG_PRISM_PUP].y && y<figButton[ID_FIG_PRISM_PUP].y+figButton[ID_FIG_PRISM_PUP].height)
        {
            motion1=ID_FIG_PRISM_PUP;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_PRISM_PLEFT].x && x<figButton[ID_FIG_PRISM_PLEFT].x+figButton[ID_FIG_PRISM_PLEFT].width)
    {
        if(y>figButton[ID_FIG_PRISM_PLEFT].y && y<figButton[ID_FIG_PRISM_PLEFT].y+figButton[ID_FIG_PRISM_PLEFT].height)
        {
            motion1=ID_FIG_PRISM_PLEFT;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_PRISM_PRIGHT].x && x<figButton[ID_FIG_PRISM_PRIGHT].x+figButton[ID_FIG_PRISM_PRIGHT].width)
    {
        if(y>figButton[ID_FIG_PRISM_PRIGHT].y && y<figButton[ID_FIG_PRISM_PRIGHT].y+figButton[ID_FIG_PRISM_PRIGHT].height)
        {
            motion1=ID_FIG_PRISM_PRIGHT;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    tarsFig->Refresh();
}

void ConfigDlg::OnLeaveTarFig(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    tarsFig->Refresh();
}

void ConfigDlg::OnClickTarFig(wxMouseEvent& event)
{
    if(motion1==ID_FIG_PRISM_DOWN || motion1==ID_FIG_PRISM_PDOWN)
    {
        tars.ipos=0;
    }
    else if(motion1==ID_FIG_PRISM_LEFT || motion1==ID_FIG_PRISM_PLEFT)
    {
        tars.ipos=2;
    }
    else if(motion1==ID_FIG_PRISM_UP || motion1==ID_FIG_PRISM_PUP)
    {
        tars.ipos=1;
    }
    else if(motion1==ID_FIG_PRISM_RIGHT || motion1==ID_FIG_PRISM_PRIGHT)
    {
        tars.ipos=3;
    }
    else if(motion1==ID_FIG_TAR_POS0)
    {
        tars.pos=0;
    }
    else if(motion1==ID_FIG_TAR_POS1)
    {
        tars.pos=1;
    }
    else if(motion1==ID_FIG_PRISM_ODOWN)
    {
        m1.ipos=0;
    }
    else if(motion1==ID_FIG_PRISM_OUP)
    {
       m1.ipos=1;
    }
    else if(motion1==ID_FIG_PRISM_OLEFT)
    {
       m1.ipos=2;
    }
    else if(motion1==ID_FIG_PRISM_ORIGHT)
    {
       m1.ipos=3;
    }
    tarsFig->Refresh();
}

void ConfigDlg::OnMotionTarButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_TFILE].y && y<figButton[ID_FIG_TFILE].y+figButton[ID_FIG_TFILE].height)
    {
        if(x>figButton[ID_FIG_TFILE].x && x<figButton[ID_FIG_TFILE].x+figButton[ID_FIG_TFILE].width)
        {
            motion1=ID_FIG_TFILE;
        }
        else if(x>figButton[ID_FIG_TFILE_EXP].x && x<figButton[ID_FIG_TFILE_EXP].x+figButton[ID_FIG_TFILE_EXP].width)
        {
            motion1=ID_FIG_TFILE_EXP;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    tarsButton->Refresh();
}

void ConfigDlg::OnLeaveTarButton(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    tarsButton->Refresh();
}

void ConfigDlg::OnClickTarButton(wxMouseEvent& event)
{
    ///20190315 whq add
/*    if(mtg->tarset.stopped==1)
    {
        WriteMsg(_("角度异常，请立刻联系上海米度测量技术有限公司!"),1);
        return;//end add
    }*/
    if(mtg->onLine>0) return;
    op1=ID_FIG_NONE;
    if(motion1==ID_FIG_TFILE)
    {
        wxFileDialog dlg(this,_("请选择要打开的文件"),_(""),_(""),_("激光靶文件(*.tars)|*.tars"),wxFD_OPEN);
        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str=dlg.GetPath();
            char buf[1024];
            strcpy(buf,str.mb_str(wxConvLocal));
            FILE* fp=fopen(buf,"rb");

            //FILE* fp1=fopen("D:\\tar.log","w");
            if(fp)
            {
                wxImage m_img;
                point2d_t pts1[9],pts2[9];
                fread(&mtg->tarset.ver,sizeof(int),1,fp);   //版本
                fread(&mtg->camset[0].name,64,1,fp);        //相机名 系列号
                fread(&mtg->tarset.cam,sizeof(int),1,fp);    //相机类型
                fread(&mtg->tarset.inc,sizeof(int),1,fp);    //倾斜仪类型
                fread(&mtg->tarset.length,sizeof(double),1,fp);   //前屏与后屏的距离
                fread(&mtg->tarset.prc,sizeof(double),1,fp);    //棱镜常数
                fread(&mtg->camset[0].w,sizeof(int),1,fp);   //照片宽度
                fread(&mtg->camset[0].h,sizeof(int),1,fp);   //照片高度
                //fprintf(fp1,"ver=%d\n",mtg->tarset.ver);
                //fprintf(fp1,"name=%s\n",mtg->camset[0].name);
                //fprintf(fp1,"cam=%d\n",mtg->tarset.cam);
                //fprintf(fp1,"inc=%d\n",mtg->tarset.inc);
                //fprintf(fp1,"len=%.4f\n",mtg->tarset.length);
                //fprintf(fp1,"prc=%.4f\n",mtg->tarset.prc);
                //fprintf(fp1,"w=%d\n",mtg->camset[0].w);
                //fprintf(fp1,"h=%d\n",mtg->camset[0].h);

                for(int i=0;i<12;i++)     //棱镜位置数组
                {
                    fread(&mtg->tarset.prism[i],sizeof(double),1,fp);
                    //fprintf(fp1,"i:%d,%.4lf",i,mtg->tarset.prism[i]);
                }
                int ncal=0;
                for(int i=0;i<9;i++)
                {
                    fread(&pts1[i].x,sizeof(double),1,fp);
                    fread(&pts1[i].y,sizeof(double),1,fp);
                    pts1[i].y=mtg->camset[0].h-pts1[i].y;
                    fread(&pts2[i].x,sizeof(double),1,fp);
                    fread(&pts2[i].y,sizeof(double),1,fp);
                    if(pts1[i].x>1.0e-6 && pts1[i].y>1.0e-6)
                    {
                        ncal++;
                    }
                    //fprintf(fp1,"%.4lf,%.4lf,%.4lf,%.4lf\n",pts1[i].x,pts1[i].y,pts2[i].x,pts2[i].y);
                }
                m_img.Create(mtg->camset[0].w,mtg->camset[0].h);
                unsigned char* uc=new unsigned char[mtg->camset[0].w*mtg->camset[0].h*3];
                fread(uc,mtg->camset[0].w*mtg->camset[0].h*3,1,fp);
                m_img.SetData(uc);
                //fclose(fp1);
                affine_t aff;
                affine_init_points(&aff,ncal,pts1,pts2);
                mtg->camset[0].affine[0]=aff.a1;
                mtg->camset[0].affine[1]=aff.a2;
                mtg->camset[0].affine[2]=aff.a3;
                mtg->camset[0].affine[3]=aff.b1;
                mtg->camset[0].affine[4]=aff.b2;
                mtg->camset[0].affine[5]=aff.b3;
                mtg->camset[0].affine[6]=aff.c1;
                mtg->camset[0].affine[7]=aff.c2;
                mtg->camset[0].affine[8]=aff.c3;
                if(!feof(fp))
                {
                    fread(&mtg->tarset.incdb,sizeof(int),1,fp);
                    fread(&mtg->tarset.ctsalw,sizeof(int),1,fp);
                    fread(&mtg->tarset.dtsalw,sizeof(int),1,fp);
                    fread(&mtg->tarset.stopped,sizeof(int),1,fp);
                    fread(&mtg->tarset.angalw,sizeof(double),1,fp);
                }
                fclose(fp);

                mtg_store_camset(mtg);
                mtg->icli[14]=1;
                mtg_store_tars(mtg);
                mtg->icli[3]=1;

                wxMessageBox(_("导入成功！"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
                //tarsFile->SetValue(dlg.GetFilename());
                //trace(0,"cam:x1=%.4f,y1=%.4f,x2=%.4f,y2=%.4f\n",mtg->camset[0].x1,mtg->camset[0].y2,mtg->camset[0].x2,mtg->camset[0].y2);
                LoadDataBase();
                str=ipath+_("/plugins/")+wxString(mtg->camset[0].name,wxConvLocal)+_(".tars");
                strcpy(buf,str.mb_str(wxConvLocal));
                FILE* fp1=fopen(buf,"wb");
                if(fp1)
                {
                    fwrite(&mtg->tarset.ver,sizeof(int),1,fp1);
                    fwrite(mtg->camset[0].name,64,1,fp1);
                    fwrite(&mtg->tarset.cam,sizeof(int),1,fp1);
                    fwrite(&mtg->tarset.inc,sizeof(int),1,fp1);
                    fwrite(&mtg->tarset.length,sizeof(double),1,fp1);
                    fwrite(&mtg->tarset.prc,sizeof(double),1,fp1);
                    fwrite(&mtg->camset[0].w,sizeof(int),1,fp1);
                    fwrite(&mtg->camset[0].h,sizeof(int),1,fp1);
                    for(int i=0;i<12;i++)
                    {
                        fwrite(&mtg->tarset.prism[i],sizeof(double),1,fp1);
                    }

                    for(int i=0;i<9;i++)
                    {
                        fwrite(&pts1[i].x,sizeof(double),1,fp1);
                        pts1[i].y=mtg->camset[0].h-pts1[i].y;
                        fwrite(&pts1[i].y,sizeof(double),1,fp1);
                        fwrite(&pts2[i].x,sizeof(double),1,fp1);
                        fwrite(&pts2[i].y,sizeof(double),1,fp1);
                    }

                    unsigned char* uc=m_img.GetData();
                    fwrite(uc,mtg->camset[0].w*mtg->camset[0].h*3,1,fp1);

                    fwrite(&mtg->tarset.incdb,sizeof(int),1,fp);
                    fwrite(&mtg->tarset.ctsalw,sizeof(int),1,fp);
                    fwrite(&mtg->tarset.dtsalw,sizeof(int),1,fp);
                    fwrite(&mtg->tarset.stopped,sizeof(int),1,fp);
                    fwrite(&mtg->tarset.angalw,sizeof(double),1,fp);
                    fclose(fp1);
                }
            }
        }
        tarsFig->Refresh();
    }
    else if(motion1==ID_FIG_TFILE_EXP)
    {
        char buf[1024];
        wxString str;
        str=ipath+_("/plugins/")+wxString(mtg->camset[0].name,wxConvLocal)+_(".tars");
        strcpy(buf,str.mb_str(wxConvLocal));
        FILE* fp=fopen(buf,"rb");
        if(fp)
        {
            wxImage m_img;
            point2d_t pts1[9],pts2[9];
            int ver=0;
            char name[64];
            int cam=0;
            int inc=0;
            double len=0.0;
            double prc=0.0;
            int camw=0;
            int camh=0;
            double prism[12]={0.0};
            int incdb=0;
            int ctsalw=0;
            int dtsalw=0;
            int stopped=0;
            double angalw=0.0;
            fread(&ver,sizeof(int),1,fp);
            fread(&name,64,1,fp);
            fread(&cam,sizeof(int),1,fp);
            fread(&inc,sizeof(int),1,fp);
            fread(&len,sizeof(double),1,fp);
            fread(&prc,sizeof(double),1,fp);
            fread(&camw,sizeof(int),1,fp);
            fread(&camh,sizeof(int),1,fp);

            for(int i=0;i<12;i++)
            {
                fread(&prism[i],sizeof(double),1,fp);
                //fprintf(fp1,"i:%d,%.4lf",i,mtg->tarset.prism[i]);
            }
            int ncal=0;
            for(int i=0;i<9;i++)
            {
                fread(&pts1[i].x,sizeof(double),1,fp);
                fread(&pts1[i].y,sizeof(double),1,fp);
                //pts1[i].y=mtg->camset[0].h-pts1[i].y;
                fread(&pts2[i].x,sizeof(double),1,fp);
                fread(&pts2[i].y,sizeof(double),1,fp);
                //fprintf(fp1,"%.4lf,%.4lf,%.4lf,%.4lf\n",pts1[i].x,pts1[i].y,pts2[i].x,pts2[i].y);
            }
            m_img.Create(mtg->camset[0].w,mtg->camset[0].h);
            unsigned char* uc=new unsigned char[mtg->camset[0].w*mtg->camset[0].h*3];
            fread(uc,mtg->camset[0].w*mtg->camset[0].h*3,1,fp);
            m_img.SetData(uc);
            if(!feof(fp))
            {
                fread(&incdb,sizeof(int),1,fp);
                fread(&ctsalw,sizeof(int),1,fp);
                fread(&dtsalw,sizeof(int),1,fp);
                fread(&stopped,sizeof(int),1,fp);
                fread(&angalw,sizeof(double),1,fp);
            }
            fclose(fp);

            wxFileDialog dlg(this,_("请选择保存路径"),_(""),_(""),_("激光靶文件(*.tars)|*.tars"),wxFD_SAVE);
            if(dlg.ShowModal()==wxID_OK)
            {
                str=dlg.GetPath();
                strcpy(buf,str.mb_str(wxConvLocal));
                fp=fopen(buf,"wb");
                if(fp)
                {
                    fwrite(&ver,sizeof(int),1,fp);
                    fwrite(name,64,1,fp);
                    fwrite(&cam,sizeof(int),1,fp);
                    fwrite(&inc,sizeof(int),1,fp);
                    fwrite(&len,sizeof(double),1,fp);
                    fwrite(&prc,sizeof(double),1,fp);
                    fwrite(&camw,sizeof(int),1,fp);
                    fwrite(&camh,sizeof(int),1,fp);
                    for(int i=0;i<12;i++)
                    {
                        fwrite(&prism[i],sizeof(double),1,fp);
                    }

                    for(int i=0;i<9;i++)
                    {
                        fwrite(&pts1[i].x,sizeof(double),1,fp);
                        fwrite(&pts1[i].y,sizeof(double),1,fp);
                        fwrite(&pts2[i].x,sizeof(double),1,fp);
                        fwrite(&pts2[i].y,sizeof(double),1,fp);
                    }

                    unsigned char* uc=m_img.GetData();
                    fwrite(uc,camw*camh*3,1,fp);

                    fwrite(&incdb,sizeof(int),1,fp);
                    fwrite(&ctsalw,sizeof(int),1,fp);
                    fwrite(&dtsalw,sizeof(int),1,fp);
                    fwrite(&stopped,sizeof(int),1,fp);
                    fwrite(&angalw,sizeof(double),1,fp);

                    fclose(fp);
                    wxMessageBox(_("保存成功！"));
                }
            }
        }
    }
}

void ConfigDlg::OnPaintTbmFig(wxPaintEvent& event)
{
    wxPaintDC dc(tbmFigPanel);
    int w,h;
    tbmFigPanel->GetClientSize(&w,&h);
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
        memDC.SetFont(chs);

        int x1,y1,w1,h1;

        x1=90;
        y1=50;
        w1=w-160;
        h1=h-110;

        int x2,y2,w2,h2;
        x2=x1;
        y2=y1;
        w2=w1;
        h2=35;
        memDC.SetPen(wxPen(wxColor(58,58,58)));
        memDC.SetBrush(wxBrush(wxColor(255,0,0)));
        memDC.DrawRectangle(x2,y2,w2,h2);
        memDC.DrawRectangle(x2-8,y2-10,16,10);
        memDC.DrawRectangle(x2+w2-8,y2-10,16,10);

        memDC.SetPen(wxPen(wxColor(0,0,255)));

        memDC.DrawLine(x2-45,y2,x2-5,y2);
        memDC.DrawLine(x2-45,y2+h2,x2-5,y2+h2);
        memDC.DrawLine(x2-43,y2,x2-43,y2+h2);
        memDC.DrawLabel(_("L9"),wxRect(x2-45,y2,0,h2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(58,58,58)));
        int dw=10;
        x2=x2+dw;
        y2=y2+h2+5;
        w2=w2-dw*2;
        h2=h1-h2-5;
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        memDC.DrawRectangle(x2,y2,w2,h2);
        memDC.DrawLine(x2+5,y2,x2+5,y2+h2);
        memDC.DrawLine(x2+w2-5,y2,x2+w2-5,y2+h2);
        if(tbm.type==1)
        {
            memDC.DrawLine(x2+5,y2+h2*1/4-15,x2+w2-5,y2+h2*1/4-15);
            memDC.DrawLine(x2+5,y2+h2*1/4,x2+w2-5,y2+h2*1/4);

            memDC.DrawRectangle(x2+15,y2+h2*1/4,24,15);
            memDC.DrawRectangle(x2+12,y2+h2*1/4+17,30,15);
            memDC.DrawRectangle(x2+w2-45,y2+h2*1/4,24,15);
            memDC.DrawRectangle(x2+w2-48,y2+h2*1/4+17,30,15);
            memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT));
            memDC.DrawLine(x2+27,y2+h2*1/4+17,x2+27,y2+h2*1/4+32);
            memDC.DrawLine(x2+w2-33,y2+h2*1/4+17,x2+w2-33,y2+h2*1/4+32);
            memDC.SetPen(wxPen(wxColor(0,0,255)));

            memDC.DrawLine(x2+27,y2+h2*1/4+37,x2+32,y2+h2*1/4+42);
            memDC.DrawLine(x2+32,y2+h2*1/4+42,x2+w2/2-5,y2+h2*1/4+42);
            memDC.DrawLine(x2+w2/2-5,y2+h2*1/4+42,x2+w2/2,y2+h2*1/4+47);
            memDC.DrawLine(x2+w2/2,y2+h2*1/4+47,x2+w2/2+5,y2+h2*1/4+42);
            memDC.DrawLine(x2+w2/2+5,y2+h2*1/4+42,x2+w2-37,y2+h2*1/4+42);
            memDC.DrawLine(x2+w2-37,y2+h2*1/4+42,x2+w2-32,y2+h2*1/4+37);
            memDC.DrawLabel(_("R1"),wxRect(x2+27,y2+h2*1/4+50,w2-54,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

            memDC.SetPen(wxPen(wxColor(58,58,58)));
            memDC.DrawLine(x2+5,y2+h2*1/4+45,x2+15,y2+h2*1/4+45);
            memDC.DrawLine(x2+5,y2+h2*1/4+65,x2+15,y2+h2*1/4+65);
            memDC.DrawCircle(x2+15,y2+h2*1/4+55,10);

            memDC.DrawLine(x2+w2-15,y2+h2*1/4+45,x2+w2-5,y2+h2*1/4+45);
            memDC.DrawLine(x2+w2-15,y2+h2*1/4+65,x2+w2-5,y2+h2*1/4+65);
            memDC.DrawCircle(x2+w2-15,y2+h2*1/4+55,10);

            memDC.DrawLine(x2+5,y2+h2*1/4+85,x2+15,y2+h2*1/4+85);
            memDC.DrawLine(x2+5,y2+h2*1/4+105,x2+15,y2+h2*1/4+105);
            memDC.DrawCircle(x2+15,y2+h2*1/4+95,10);

            memDC.DrawLine(x2+w2-15,y2+h2*1/4+85,x2+w2-5,y2+h2*1/4+85);
            memDC.DrawLine(x2+w2-15,y2+h2*1/4+105,x2+w2-5,y2+h2*1/4+105);
            memDC.DrawCircle(x2+w2-15,y2+h2*1/4+95,10);

            memDC.SetPen(wxPen(wxColor(255,0,0)));
            memDC.DrawLine(x2+5,y2+h2*1/4+55,x2+5,y2+h2*1/4+95);
            memDC.DrawLine(x2+25,y2+h2*1/4+55,x2+25,y2+h2*1/4+95);

            memDC.DrawLine(x2+w2-5,y2+h2*1/4+55,x2+w2-5,y2+h2*1/4+95);
            memDC.DrawLine(x2+w2-25,y2+h2*1/4+55,x2+w2-25,y2+h2*1/4+95);

            memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT));
            memDC.DrawLine(x2+15,y2+h2*1/4+100,x2+15,y2+h2*1/4+85);
            memDC.DrawLine(x2+w2-15,y2+h2*1/4+100,x2+w2-15,y2+h2*1/4+85);
            memDC.DrawLine(x2+15,y2+h2*1/4+65,x2+15,y2+h2*1/4+45);
            memDC.DrawLine(x2+w2-15,y2+h2*1/4+65,x2+w2-15,y2+h2*1/4+45);

            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2+15,y2+h2*1/4+65,x2+20,y2+h2*1/4+70);
            memDC.DrawLine(x2+20,y2+h2*1/4+70,x2+w2/2-5,y2+h2*1/4+70);
            memDC.DrawLine(x2+w2/2-5,y2+h2*1/4+70,x2+w2/2,y2+h2*1/4+75);
            memDC.DrawLine(x2+w2/2,y2+h2*1/4+75,x2+w2/2+5,y2+h2*1/4+70);
            memDC.DrawLine(x2+w2/2+5,y2+h2*1/4+70,x2+w2-20,y2+h2*1/4+70);
            memDC.DrawLine(x2+w2-20,y2+h2*1/4+70,x2+w2-15,y2+h2*1/4+65);
            memDC.DrawLabel(_("R4"),wxRect(x2+15,y2+h2*1/4+80,w2-30,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

            memDC.DrawLine(x2+15,y2+h2*1/4+105,x2+20,y2+h2*1/4+110);
            memDC.DrawLine(x2+20,y2+h2*1/4+110,x2+w2/2-5,y2+h2*1/4+110);
            memDC.DrawLine(x2+w2/2-5,y2+h2*1/4+110,x2+w2/2,y2+h2*1/4+115);
            memDC.DrawLine(x2+w2/2,y2+h2*1/4+115,x2+w2/2+5,y2+h2*1/4+110);
            memDC.DrawLine(x2+w2/2+5,y2+h2*1/4+110,x2+w2-20,y2+h2*1/4+110);
            memDC.DrawLine(x2+w2-20,y2+h2*1/4+110,x2+w2-15,y2+h2*1/4+105);
            memDC.DrawLabel(_("R5"),wxRect(x2+15,y2+h2*1/4+120,w2-30,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2-55,y2+h2*1/4+55,x2+15,y2+h2*1/4+55);
            memDC.DrawLine(x2-53,y2,x2-53,y2+h2*1/4+55);
            memDC.DrawLabel(_("L7"),wxRect(x2-55,y2,0,h2*1/4+55),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLine(x2-55,y2+h2*1/4+95,x2+15,y2+h2*1/4+95);
            memDC.DrawLine(x2-53,y2+h2*1/5+55,x2-53,y2+h2*1/4+95);
            memDC.DrawLabel(_("L8"),wxRect(x2-55,y2+h2*1/4+55,0,40),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

            memDC.DrawLine(x2-5,y2,x2-35,y2);
            memDC.DrawLine(x2+15,y2+h2*1/4+32,x2-35,y2+h2*1/4+32);
            memDC.DrawLine(x2-33,y2,x2-33,y2+h2*1/4+32);
            memDC.DrawLabel(_("L4"),wxRect(x2-35,y2,0,h2*1/5+32),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLine(x2-35,y2,x2-5,y2);

            //memDC.DrawLine(x2+w2+5,y2,x2+w2+25,y2);
            //memDC.DrawLine(x2+w2-15,y2+h2*1/4+32,x2+w2+25,y2+h2*1/4+32);
           // memDC.DrawLine(x2+w2+23,y2,x2+w2+23,y2+h2*1/4+32);
            //memDC.DrawLabel(_("L4"),wxRect(x2+w2+20,y2,0,h2*1/4+32),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            //memDC.DrawLine(x2-45,y2,x2-5,y2);

            memDC.DrawLine(x2+w2+5,y2,x2+w2+35,y2);
            memDC.DrawLine(x2+w2+5,y2+h2*2/5+40,x2+w2+32,y2+h2*2/5+40);
            memDC.DrawLine(x2+w2+32,y2,x2+w2+32,y2+h2*2/5+40);
            memDC.DrawLabel(_("L1"),wxRect(x2+w2+40,y2,0,h2*2/5+40),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLine(x2+w2+5,y2+h2,x2+w2+35,y2+h2);
            memDC.DrawLine(x2+w2+32,y2+h2*2/5+40,x2+w2+32,y2+h2);
            memDC.DrawLabel(_("L3"),wxRect(x2+w2+40,y2+h2*2/5+70,0,h2*3/5-70),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        }
        else if(tbm.type==2 || tbm.type==3)
        {
            memDC.DrawLine(x2+5,y2+h2*2/5-15,x2+w2-5,y2+h2*2/5-15);
            memDC.DrawLine(x2+5,y2+h2*2/5,x2+w2-5,y2+h2*2/5);

            memDC.DrawRectangle(x2+15,y2+h2*2/5,24,15);
            memDC.DrawRectangle(x2+12,y2+h2*2/5+17,30,15);
            memDC.DrawRectangle(x2+w2-45,y2+h2*2/5,24,15);
            memDC.DrawRectangle(x2+w2-48,y2+h2*2/5+17,30,15);
            memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT));
            memDC.DrawLine(x2+27,y2+h2*2/5+17,x2+27,y2+h2*2/5+32);
            memDC.DrawLine(x2+w2-33,y2+h2*2/5+17,x2+w2-33,y2+h2*2/5+32);

            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2+27,y2+h2*2/5+37,x2+32,y2+h2*2/5+42);
            memDC.DrawLine(x2+32,y2+h2*2/5+42,x2+w2/2-5,y2+h2*2/5+42);
            memDC.DrawLine(x2+w2/2-5,y2+h2*2/5+42,x2+w2/2,y2+h2*2/5+47);
            memDC.DrawLine(x2+w2/2,y2+h2*2/5+47,x2+w2/2+5,y2+h2*2/5+42);
            memDC.DrawLine(x2+w2/2+5,y2+h2*2/5+42,x2+w2-38,y2+h2*2/5+42);
            memDC.DrawLine(x2+w2-38,y2+h2*2/5+42,x2+w2-33,y2+h2*2/5+37);
            memDC.DrawLabel(_("R1"),wxRect(x2+27,y2+h2*2/5+52,w2-54,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

            memDC.SetPen(wxPen(wxColor(58,58,58)));

            memDC.DrawLine(x2+5,y2+h2*2/5-75,x2+15,y2+h2*2/5-75);
            memDC.DrawLine(x2+5,y2+h2*2/5-55,x2+15,y2+h2*2/5-55);
            memDC.DrawCircle(x2+15,y2+h2*2/5-65,10);

            memDC.DrawLine(x2+w2-15,y2+h2*2/5-75,x2+w2-5,y2+h2*2/5-75);
            memDC.DrawLine(x2+w2-15,y2+h2*2/5-55,x2+w2-5,y2+h2*2/5-55);
            memDC.DrawCircle(x2+w2-15,y2+h2*2/5-65,10);

            memDC.DrawLine(x2+5,y2+h2*2/5-25,x2+15,y2+h2*2/5-25);
            memDC.DrawLine(x2+5,y2+h2*2/5-5,x2+15,y2+h2*2/5-5);
            memDC.DrawCircle(x2+15,y2+h2*2/5-15,10);

            memDC.DrawLine(x2+w2-15,y2+h2*2/5-25,x2+w2-5,y2+h2*2/5-25);
            memDC.DrawLine(x2+w2-15,y2+h2*2/5-5,x2+w2-5,y2+h2*2/5-5);
            memDC.DrawCircle(x2+w2-15,y2+h2*2/5-15,10);

            memDC.SetPen(wxPen(wxColor(255,0,0)));
            memDC.DrawLine(x2+5,y2+h2*2/5-65,x2+5,y2+h2*2/5-15);
            memDC.DrawLine(x2+25,y2+h2*2/5-65,x2+25,y2+h2*2/5-15);

            memDC.DrawLine(x2+w2-5,y2+h2*2/5-65,x2+w2-5,y2+h2*2/5-15);
            memDC.DrawLine(x2+w2-25,y2+h2*2/5-65,x2+w2-25,y2+h2*2/5-15);

            memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT));
            memDC.DrawLine(x2+15,y2+h2*2/5-10,x2+15,y2+h2*2/5-25);
            memDC.DrawLine(x2+w2-15,y2+h2*2/5-10,x2+w2-15,y2+h2*2/5-25);
            memDC.DrawLine(x2+15,y2+h2*2/5-55,x2+15,y2+h2*2/5-75);
            memDC.DrawLine(x2+w2-15,y2+h2*2/5-55,x2+w2-15,y2+h2*2/5-75);

            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2+15,y2+h2*2/5-20,x2+20,y2+h2*2/5-25);
            memDC.DrawLine(x2+20,y2+h2*2/5-25,x2+w2/2-5,y2+h2*2/5-25);
            memDC.DrawLine(x2+w2/2-5,y2+h2*2/5-25,x2+w2/2,y2+h2*2/5-30);
            memDC.DrawLine(x2+w2/2,y2+h2*2/5-30,x2+w2/2+5,y2+h2*2/5-25);
            memDC.DrawLine(x2+w2/2+5,y2+h2*2/5-25,x2+w2-20,y2+h2*2/5-25);
            memDC.DrawLine(x2+w2-20,y2+h2*2/5-25,x2+w2-15,y2+h2*2/5-20);
            memDC.DrawLabel(_("R2"),wxRect(x2+15,y2+h2*2/5-35,w2-30,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);

            memDC.DrawLine(x2+15,y2+h2*2/5-70,x2+20,y2+h2*2/5-75);
            memDC.DrawLine(x2+20,y2+h2*2/5-75,x2+w2/2-5,y2+h2*2/5-75);
            memDC.DrawLine(x2+w2/2-5,y2+h2*2/5-75,x2+w2/2,y2+h2*2/5-80);
            memDC.DrawLine(x2+w2/2,y2+h2*2/5-80,x2+w2/2+5,y2+h2*2/5-75);
            memDC.DrawLine(x2+w2/2+5,y2+h2*2/5-75,x2+w2-20,y2+h2*2/5-75);
            memDC.DrawLine(x2+w2-20,y2+h2*2/5-75,x2+w2-15,y2+h2*2/5-70);
            memDC.DrawLabel(_("R3"),wxRect(x2+15,y2+h2*2/5-82,w2-30,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
            memDC.SetPen(wxPen(wxColor(0,0,255)));

            memDC.DrawLine(x2-55,y2,x2-5,y2);
            if(tbm.type==3)
            {
                memDC.DrawLine(x2-15,y2+h2*2/5-65,x2+10,y2+h2*2/5-65);
                memDC.DrawLine(x2-13,y2,x2-13,y2+h2*2/5-65);
                memDC.DrawLabel(_("L5"),wxRect(x2-15,y2,0,h2*2/5-65),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLine(x2-15,y2+h2*2/5-15,x2+10,y2+h2*2/5-15);
                memDC.DrawLine(x2-13,y2+h2*2/5-65,x2-13,y2+h2*2/5-15);
                memDC.DrawLabel(_("L6"),wxRect(x2-15,y2+h2*2/5-65,0,50),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

                memDC.SetPen(wxPen(wxColor(58,58,58)));
                memDC.DrawLine(x2+5,y2+h2*2/5+45,x2+15,y2+h2*2/5+45);
                memDC.DrawLine(x2+5,y2+h2*2/5+65,x2+15,y2+h2*2/5+65);
                memDC.DrawCircle(x2+15,y2+h2*2/5+55,10);

                memDC.DrawLine(x2+w2-15,y2+h2*2/5+45,x2+w2-5,y2+h2*2/5+45);
                memDC.DrawLine(x2+w2-15,y2+h2*2/5+65,x2+w2-5,y2+h2*2/5+65);
                memDC.DrawCircle(x2+w2-15,y2+h2*2/5+55,10);

                memDC.DrawLine(x2+5,y2+h2*2/5+85,x2+15,y2+h2*2/5+85);
                memDC.DrawLine(x2+5,y2+h2*2/5+105,x2+15,y2+h2*2/5+105);
                memDC.DrawCircle(x2+15,y2+h2*2/5+95,10);

                memDC.DrawLine(x2+w2-15,y2+h2*2/5+85,x2+w2-5,y2+h2*2/5+85);
                memDC.DrawLine(x2+w2-15,y2+h2*2/5+105,x2+w2-5,y2+h2*2/5+105);
                memDC.DrawCircle(x2+w2-15,y2+h2*2/5+95,10);

                memDC.SetPen(wxPen(wxColor(255,0,0)));
                memDC.DrawLine(x2+5,y2+h2*2/5+55,x2+5,y2+h2*2/5+95);
                memDC.DrawLine(x2+25,y2+h2*2/5+55,x2+25,y2+h2*2/5+95);

                memDC.DrawLine(x2+w2-5,y2+h2*2/5+55,x2+w2-5,y2+h2*2/5+95);
                memDC.DrawLine(x2+w2-25,y2+h2*2/5+55,x2+w2-25,y2+h2*2/5+95);

                memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT));
                memDC.DrawLine(x2+15,y2+h2*2/5+100,x2+15,y2+h2*2/5+85);
                memDC.DrawLine(x2+w2-15,y2+h2*2/5+100,x2+w2-15,y2+h2*2/5+85);
                memDC.DrawLine(x2+15,y2+h2*2/5+65,x2+15,y2+h2*2/5+45);
                memDC.DrawLine(x2+w2-15,y2+h2*2/5+65,x2+w2-15,y2+h2*2/5+45);

                memDC.SetPen(wxPen(wxColor(0,0,255)));
                memDC.DrawLine(x2+15,y2+h2*2/5+65,x2+20,y2+h2*2/5+70);
                memDC.DrawLine(x2+20,y2+h2*2/5+70,x2+w2/2-5,y2+h2*2/5+70);
                memDC.DrawLine(x2+w2/2-5,y2+h2*2/5+70,x2+w2/2,y2+h2*2/5+75);
                memDC.DrawLine(x2+w2/2,y2+h2*2/5+75,x2+w2/2+5,y2+h2*2/5+70);
                memDC.DrawLine(x2+w2/2+5,y2+h2*2/5+70,x2+w2-20,y2+h2*2/5+70);
                memDC.DrawLine(x2+w2-20,y2+h2*2/5+70,x2+w2-15,y2+h2*2/5+65);
                memDC.DrawLabel(_("R4"),wxRect(x2+15,y2+h2*2/5+80,w2-30,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

                memDC.DrawLine(x2+15,y2+h2*2/5+105,x2+20,y2+h2*2/5+110);
                memDC.DrawLine(x2+20,y2+h2*2/5+110,x2+w2/2-5,y2+h2*2/5+110);
                memDC.DrawLine(x2+w2/2-5,y2+h2*2/5+110,x2+w2/2,y2+h2*2/5+115);
                memDC.DrawLine(x2+w2/2,y2+h2*2/5+115,x2+w2/2+5,y2+h2*2/5+110);
                memDC.DrawLine(x2+w2/2+5,y2+h2*2/5+110,x2+w2-20,y2+h2*2/5+110);
                memDC.DrawLine(x2+w2-20,y2+h2*2/5+110,x2+w2-15,y2+h2*2/5+105);
                memDC.DrawLabel(_("R5"),wxRect(x2+15,y2+h2*2/5+120,w2-30,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

                memDC.SetPen(wxPen(wxColor(0,0,255)));
                memDC.DrawLine(x2-55,y2+h2*2/5+55,x2+15,y2+h2*2/5+55);
                memDC.DrawLine(x2-53,y2,x2-53,y2+h2*2/5+55);
                memDC.DrawLabel(_("L7"),wxRect(x2-55,y2,0,h2*2/5+55),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLine(x2-55,y2+h2*2/5+95,x2+15,y2+h2*2/5+95);
                memDC.DrawLine(x2-53,y2+h2*2/5+55,x2-53,y2+h2*2/5+95);
                memDC.DrawLabel(_("L8"),wxRect(x2-55,y2+h2*2/5+55,0,40),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

                memDC.DrawLine(x2-5,y2,x2-35,y2);
                memDC.DrawLine(x2+15,y2+h2*2/5+32,x2-35,y2+h2*2/5+32);
                memDC.DrawLine(x2-33,y2,x2-33,y2+h2*2/5+32);
                memDC.DrawLabel(_("L4"),wxRect(x2-35,y2,0,h2*2/5+32),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLine(x2-35,y2,x2-5,y2);

                memDC.DrawLine(x2+w2+5,y2,x2+w2+35,y2);
                memDC.DrawLine(x2+w2+5,y2+h2*2/5-30,x2+w2+35,y2+h2*2/5-30);
                memDC.DrawLine(x2+w2+32,y2,x2+w2+32,y2+h2*2/5-30);
                memDC.DrawLabel(_("L1"),wxRect(x2+w2+40,y2,0,h2*2/5-30),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLine(x2+w2+5,y2+h2*2/5+70,x2+w2+35,y2+h2*2/5+70);
                memDC.DrawLine(x2+w2+32,y2+h2*2/5-30,x2+w2+32,y2+h2*2/5+70);
                memDC.DrawLabel(_("L2"),wxRect(x2+w2+40,y2+h2*2/5-30,0,100),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLine(x2+w2+5,y2+h2,x2+w2+35,y2+h2);
                memDC.DrawLine(x2+w2+32,y2+h2*2/5+70,x2+w2+32,y2+h2);
                memDC.DrawLabel(_("L3"),wxRect(x2+w2+40,y2+h2*2/5+70,0,h2*3/5-70),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLine(x2-5,y2,x2-55,y2);
                memDC.DrawLine(x2+15,y2+h2*2/5+32,x2-55,y2+h2*2/5+32);
                memDC.DrawLine(x2-53,y2,x2-53,y2+h2*2/5+32);
                memDC.DrawLabel(_("L4"),wxRect(x2-55,y2,0,h2*2/5+32),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

                memDC.DrawLine(x2-25,y2+h2*2/5-65,x2+10,y2+h2*2/5-65);
                memDC.DrawLine(x2-23,y2,x2-23,y2+h2*2/5-65);
                memDC.DrawLabel(_("L5"),wxRect(x2-25,y2,0,h2*2/5-65),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLine(x2-25,y2+h2*2/5-15,x2+20,y2+h2*2/5-15);
                memDC.DrawLine(x2-23,y2+h2*2/5-65,x2-23,y2+h2*2/5-15);
                memDC.DrawLabel(_("L6"),wxRect(x2-25,y2+h2*2/5-65,0,50),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

                memDC.DrawLine(x2+w2+5,y2,x2+w2+35,y2);
                memDC.DrawLine(x2+w2+5,y2+h2*2/5-30,x2+w2+35,y2+h2*2/5-30);
                memDC.DrawLine(x2+w2+32,y2,x2+w2+32,y2+h2*2/5-30);
                memDC.DrawLabel(_("L1"),wxRect(x2+w2+40,y2,0,h2*2/5-30),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLine(x2+w2+5,y2+h2,x2+w2+35,y2+h2);
                memDC.DrawLine(x2+w2+32,y2+h2*2/5-30,x2+w2+32,y2+h2);
                memDC.DrawLabel(_("L3"),wxRect(x2+w2+40,y2+h2*2/5-30,0,h2*3/5+30),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else if(tbm.type==0)
        {
            memDC.DrawLine(x2+5,y2+h2*3/5-15,x2+w2-5,y2+h2*3/5-15);
            memDC.DrawLine(x2+5,y2+h2*3/5,x2+w2-5,y2+h2*3/5);

            memDC.DrawRectangle(x2+15,y2+h2*3/5,24,15);
            memDC.DrawRectangle(x2+12,y2+h2*3/5+17,30,15);
            memDC.DrawRectangle(x2+w2-45,y2+h2*3/5,24,15);
            memDC.DrawRectangle(x2+w2-48,y2+h2*3/5+17,30,15);
            memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT));
            memDC.DrawLine(x2+27,y2+h2*3/5+17,x2+27,y2+h2*3/5+32);
            memDC.DrawLine(x2+w2-33,y2+h2*3/5+17,x2+w2-33,y2+h2*3/5+32);
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2+27,y2+h2*3/5+37,x2+27,y2+h2*3/5+47);
            memDC.DrawLine(x2+w2-33,y2+h2*3/5+37,x2+w2-33,y2+h2*3/5+47);
            memDC.DrawLine(x2+27,y2+h2*3/5+45,x2+w2-33,y2+h2*3/5+45);
            memDC.DrawLabel(_("R1"),wxRect(x2+27,y2+h2*3/5+45,w2-54,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
            memDC.SetPen(wxPen(wxColor(0,0,255)));

            memDC.DrawLine(x2+w2+5,y2,x2+w2+25,y2);
            memDC.DrawLine(x2+w2-15,y2+h2*3/5+32,x2+w2+25,y2+h2*3/5+32);
            memDC.DrawLine(x2+w2+23,y2,x2+w2+23,y2+h2*3/5+32);
            memDC.DrawLabel(_("L4"),wxRect(x2+w2+20,y2,0,h2*3/5+32),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintTbmajFig(wxPaintEvent& event)
{
    wxPaintDC dc(panelJackfig);
    int w,h;
    panelJackfig->GetClientSize(&w,&h);
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
        memDC.SetFont(chs);

        int x1,y1,r1;
        x1=w/2;
        y1=x1;
        r1=w/2-50;
        memDC.DrawCircle(x1,y1,r1);
        memDC.SetPen(wxPen(wxColor(58,68,78)));
        memDC.DrawLine(x1,y1,x1+r1+10,y1);
        memDC.DrawLine(x1,y1,x1,y1-r1-10);

        wxPoint tri[3];
        tri[0].x=x1+r1+16;
        tri[0].y=y1;
        tri[1].x=x1+r1+10;
        tri[1].y=y1-3;
        tri[2].x=x1+r1+10;
        tri[2].y=y1+3;
        memDC.SetBrush(wxBrush(wxColor(58,68,78)));
        memDC.DrawPolygon(3,tri);
        memDC.DrawLabel(_("X"),wxRect(tri[0].x+7,tri[0].y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        tri[0].x=x1;
        tri[0].y=y1-r1-16;
        tri[1].x=x1-3;
        tri[1].y=y1-r1-10;
        tri[2].x=x1+3;
        tri[2].y=y1-r1-10;
        memDC.SetBrush(wxBrush(wxColor(58,68,78)));
        memDC.DrawPolygon(3,tri);
        memDC.DrawLabel(_("Y"),wxRect(tri[0].x,tri[0].y,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);

        int sel=jackList->GetFirstSelected();
        int x2,y2;
        double ai,bi,ci,r2,beta;
        ci=r1*9.0/10.0;
        r2=r1/10.0;
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        int nj;
        if(jackType==ID_FIG_TBM_MAIN_JACK) nj=tbm.naj;
        else if(jackType==ID_FIG_TBM_TAIL_JACK) nj=tbm.nbj;
        else if(jackType==ID_FIG_TBM_HEAD_JACK) nj=tbm.nfj;

        for(int i=0;i<nj;i++)
        {
            if(jackType==ID_FIG_TBM_MAIN_JACK) beta=tbm.aj[i];
            else if(jackType==ID_FIG_TBM_TAIL_JACK) beta=tbm.bj[i];
            else if(jackType==ID_FIG_TBM_HEAD_JACK) beta=tbm.fj[i];
            //beta=tbm.aj[i];
            ai=ci*cos(beta);
            bi=ci*sin(beta);
            x2=x1+ai;
            y2=y1+bi;
            if(i==sel)
            {
                memDC.SetPen(*wxRED_PEN);
                memDC.DrawCircle(x2,y2,r2);
                memDC.SetPen(wxPen(wxColor(158,158,158),1,wxDOT_DASH));
                memDC.DrawLine(x1,y1,x2,y2);
                if(beta>0.017)
                {
                    ai=20.0*cos(beta);
                    bi=20.0*sin(beta);
                    x2=x1+ai;
                    y2=y1+bi;
                    memDC.DrawArc(x2,y2,x1+20,y1,x1,y1);
                    ai=30.0*cos(beta/2.0);
                    bi=30.0*sin(beta/2.0);
                    x2=x1+ai;
                    y2=y1+bi;
                    memDC.DrawLabel(wxString::Format(_("%.2f"),beta*180.0/PI),wxRect(x2,y2,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawCircle(x2,y2,r2);
            }

        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintLaserSet(wxPaintEvent& event)
{
    wxPaintDC dc(tpsSetPanel);
    int w,h;
    tpsSetPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont ens(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=90;
        h1=25;
        memDC.DrawLabel(_("全站仪型号"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        w1=150;
        x1+=100;
        figButton[ID_FIG_TPS_TYPE].x=x1;
        figButton[ID_FIG_TPS_TYPE].y=y1;
        figButton[ID_FIG_TPS_TYPE].width=w1;
        figButton[ID_FIG_TPS_TYPE].height=h1;
        if(motion1==ID_FIG_TPS_TYPE)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(figButton[ID_FIG_TPS_TYPE],3);

        /*if(motion1==ID_FIG_TPS_TYPE)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.DrawRectangle(x1,y1,w1,h1);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.DrawRectangle(x1,y1,w1,h1);
        }*/

        if(tps.type==TS_16)
        {
            memDC.DrawLabel(_("< Leica TS16 >"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else if(tps.type==TS_15)
        {
            memDC.DrawLabel(_("< Leica TS15 >"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else if(tps.type==TPS_1200)
        {
            memDC.DrawLabel(_("< Leica TPS1200 >"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else if(tps.type==TPS_1100)
        {
            memDC.DrawLabel(_("< Leica TPS1100 >"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else if(tps.type==TPS_1000)
        {
            memDC.DrawLabel(_("< Leica TPS1000 >"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else if(tps.type==TPS_TRIMBLE)
        {
            memDC.DrawLabel(_("< Trimble S5 >"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else if(tps.type==TPS_TRIMBLE_TCU)
        {
            memDC.DrawLabel(_("< Trimble TCU >"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1+=20;
        memDC.SetPen(wxPen(wxColor(160,160,160)));
        memDC.DrawLine(0,y1+12,w,y1+12);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(0,y1+13,w,y1+13);

        y1+=20;
        memDC.DrawLabel(_("激光类型"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=100;
        w1=155;
        figButton[ID_FIG_LASER0].x=x1;
        figButton[ID_FIG_LASER0].y=y1;
        figButton[ID_FIG_LASER0].width=w1;
        figButton[ID_FIG_LASER0].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(tps.lasertype==0)
        {
            if(motion1==ID_FIG_LASER0)
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
            memDC.DrawLabel(_("GUS74激光"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_LASER0)
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
            memDC.DrawLabel(_("GUS74激光"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        w1=155;
        figButton[ID_FIG_LASER1].x=x1;
        figButton[ID_FIG_LASER1].y=y1;
        figButton[ID_FIG_LASER1].width=w1;
        figButton[ID_FIG_LASER1].height=h1;

        if(tps.lasertype==1)
        {
            if(motion1==ID_FIG_LASER1)
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
            memDC.DrawLabel(_("同轴激光"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_LASER1)
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
            memDC.DrawLabel(_("同轴激光"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1+=20;
        memDC.SetPen(wxPen(wxColor(160,160,160)));
        memDC.DrawLine(0,y1+12,w,y1+12);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(0,y1+13,w,y1+13);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionLaserSet(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_TPS_TYPE].y && y<figButton[ID_FIG_TPS_TYPE].y+figButton[ID_FIG_TPS_TYPE].height)
    {
        if(x>figButton[ID_FIG_TPS_TYPE].x && x<figButton[ID_FIG_TPS_TYPE].x+figButton[ID_FIG_TPS_TYPE].width)
        {
            motion1=ID_FIG_TPS_TYPE;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        if(x>figButton[ID_FIG_LASER0].x && x<figButton[ID_FIG_LASER0].x+figButton[ID_FIG_LASER0].width)
        {
            if(y>figButton[ID_FIG_LASER0].y && y<figButton[ID_FIG_LASER0].y+figButton[ID_FIG_LASER0].height)
            {
                motion1=ID_FIG_LASER0;
            }
            else
            {
                motion1=ID_FIG_NONE;
            }
        }
        else if(x>figButton[ID_FIG_LASER1].x && x<figButton[ID_FIG_LASER1].x+figButton[ID_FIG_LASER1].width)
        {
            if(y>figButton[ID_FIG_LASER1].y && y<figButton[ID_FIG_LASER1].y+figButton[ID_FIG_LASER1].height)
            {
                motion1=ID_FIG_LASER1;
            }
            else
            {
                motion1=ID_FIG_NONE;
            }
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    tpsSetPanel->Refresh();
}

void ConfigDlg::OnLeaveLaserSet(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    tpsSetPanel->Refresh();
}

void ConfigDlg::OnClickLaserSet(wxMouseEvent& event)
{
    if(mtg->onLine>0) return;
    //if(opLevel>0) return;
    if(motion1==ID_FIG_LASER0)
    {
        tps.lasertype=0;
        tps.laserheight=0.0522;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_LASER1)
    {
        tps.lasertype=1;
        tps.laserheight=0.0;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_TPS_TYPE)
    {
        TpsDlg dlg(this);
        int x,y;
        tpsSetPanel->GetScreenPosition(&x,&y);
        x=x+figButton[ID_FIG_TPS_TYPE].x;
        y=y+figButton[ID_FIG_TPS_TYPE].y+figButton[ID_FIG_TPS_TYPE].height;
        dlg.SetPosition(wxPoint(x,y));
        //dlg.Center();
        //dlg.ListCount=4;
        //dlg.ListItem[1]=_("Leica TPS1100");
        //dlg.ListItem[2]=_("Leica TPS1200");
        //dlg.ListItem[3]=_("Leica TPS15");
        //dlg.ListItem[4]=_("Leica TPS16");
        dlg.SetTPS(tps.type);
        //dlg.type=tps.type;
        if(dlg.ShowModal()==wxID_OK)
        {
            motion1=ID_FIG_NONE;
            tps.type=dlg.GetTPS();
        }
    }
    tpsSetPanel->Refresh();
    tpsFigPanel->Refresh();
}

void ConfigDlg::OnPaintLaser(wxPaintEvent& event)
{
    wxPaintDC dc(tpsFigPanel);
    int w,h;
    tpsFigPanel->GetClientSize(&w,&h);
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
        wxFont ens(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;

        y1=10;
        x1=15;
        w1=65;
        h1=25;
        memDC.DrawLabel(_("激光矫正"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=100;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("L "),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        w1=120;
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        //memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("m"),wxRect(x1+w1-22,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tpsLaserDist->SetSize(x1+1,y1+5,w1-26,h1-6);

        x1=x1+w1+40;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("△X "),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawRectangle(x1,y1,w1,h1);
        tpsLaserDevX->SetSize(x1+1,y1+5,w1-38,h1-6);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1-32,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+40;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("△Y "),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawRectangle(x1,y1,w1,h1);
        tpsLaserDevY->SetSize(x1+1,y1+5,w1-38,h1-6);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1-32,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1=20;
        x1=15;
        w1=w-60;
        h1=h-y1;

        int x2,y2,w2,h2;
        if(bmpTPS1.IsOk())
        {
            w2=bmpTPS1.GetWidth();
            h2=bmpTPS1.GetHeight();
            x2=x1+w2/2;
            y2=y1+h1/2-h2/2-12;
            memDC.DrawBitmap(bmpTPS1,x2,y2);
        }

        int px1,px2,py1,py2;
        int px0,py0;
        int pw,ph;
        pw=160;
        ph=160;
        px0=w-pw/2-15;
        py0=y1+h1/2-36;

        px1=px0-pw/2;
        py1=py0-pw/2*tan(PI/6);
        px2=px0+pw/2;
        py2=py0+pw/2*tan(PI/6);

        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(px1,py1,px2,py2);
        if(tps.lasertype==0)
        {
            memDC.SetPen(wxPen(wxColor(122,122,122),1,wxDOT));
            memDC.DrawLine(px1,py1-22,px2,py2-22);
        }
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        px1=px2-10;
        py1=py2-10*tan(PI/6)-8;
        memDC.DrawLine(px1,py1,px2,py2);
        py1=py2-10*tan(PI/6)+8;
        memDC.DrawLine(px1,py1,px2,py2);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("X"),wxRect(px2,py2+10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        px1=px2=px0;
        py1=py0-ph/2;
        py2=py0+ph/2;
        memDC.DrawLine(px1,py1,px2,py2);
        px2=px1-8;
        py2=py1+10-8*tan(PI/6);
        memDC.DrawLine(px1,py1,px2,py2);
        px2=px1+8;
        py2=py1+10+8*tan(PI/6);
        memDC.DrawLine(px1,py1,px2,py2);
        memDC.DrawLabel(_("Y"),wxRect(px1,py1-10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        if(tps.lasertype==1)
        {
            memDC.SetPen(wxPen(wxColor(255,9,9),1,wxLONG_DASH));
            memDC.DrawLine(x2+w2,py0,px0-5,py0);
            memDC.DrawLabel(_("L"),wxRect(x2/2+w2/4+8+px0/2,py0+10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.SetPen(wxPen(wxColor(255,9,9),1));
            px1=px0+40;
            py1=py0-40;
            memDC.DrawLine(x2+w2,py0,px1-5,py1);
            px2=px0;
            py2=py1-40*tan(PI/6);
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(px1,py1,px2-5,py2);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("△X"),wxRect(px1/2+px2/2+7,py1/2+py2/2-10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            px2=px1;
            py2=py0+40*tan(PI/6);
            memDC.DrawLine(px1,py1,px2,py2);
            memDC.DrawLabel(_("△Y"),wxRect(px1+15,py1/2+py2/2,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else if(tps.lasertype==0)
        {
            memDC.SetPen(wxPen(wxColor(255,9,9),1,wxLONG_DASH));
            memDC.DrawLine(x2+w2-8,py0-21,px0-5,py0-21);
            memDC.DrawLabel(_("L"),wxRect(x2/2+w2/4+8+px0/2,py0-13,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.SetPen(wxPen(wxColor(255,9,9),1));
            px1=px0+40;
            py1=py0-40;
            memDC.DrawLine(x2+w2-8,py0-21,px1-5,py1);
            px2=px0;
            py2=py1-40*tan(PI/6);
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(px1,py1,px2,py2);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("△X"),wxRect(px1/2+px2/2+7,py1/2+py2/2-10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            px2=px1;
            py2=py0-21+40*tan(PI/6);
            memDC.DrawLine(px1,py1,px2,py2);
            memDC.DrawLabel(_("△Y"),wxRect(px1+15,py1/2+py2/2,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionLaser(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_LASER0].x && x<figButton[ID_FIG_LASER0].x+figButton[ID_FIG_LASER0].width)
    {
        if(y>figButton[ID_FIG_LASER0].y && y<figButton[ID_FIG_LASER0].y+figButton[ID_FIG_LASER0].height)
        {
            motion1=ID_FIG_LASER0;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_LASER1].x && x<figButton[ID_FIG_LASER1].x+figButton[ID_FIG_LASER1].width)
    {
        if(y>figButton[ID_FIG_LASER1].y && y<figButton[ID_FIG_LASER1].y+figButton[ID_FIG_LASER1].height)
        {
            motion1=ID_FIG_LASER1;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    tpsFigPanel->Refresh();
}

void ConfigDlg::OnLeaveLaser(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    tpsFigPanel->Refresh();
}

void ConfigDlg::OnClickLaser(wxMouseEvent& event)
{
    if(motion1==ID_FIG_LASER0)
    {
        tps.lasertype=0;
        //tpsModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_LASER1)
    {
        tps.lasertype=1;
        //tpsModified=1;
        panelBottom->Refresh();
    }
    tpsFigPanel->Refresh();
}

void ConfigDlg::OnPaintSegFig(wxPaintEvent& event)
{
    wxPaintDC dc(segFigPanel);
    int w,h;
    segFigPanel->GetClientSize(&w,&h);
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
        wxFont ens(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        int r1,r2;

        x1=35;
        y1=15;
        w1=w-70;
        h1=w1;
        r1=w1/2;
        r2=r1-15;
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawCircle(x1+r1,y1+r1,r1);
        memDC.DrawCircle(x1+r1,y1+r1,r2);

        memDC.SetPen(wxPen(wxColor(122,122,122),1,wxDOT_DASH));
        memDC.DrawLine(0,y1+r1,w,y1+r1);
        memDC.DrawLine(x1+r1,0,x1+r1,2*y1+2*r1);
        int ks=segset.Ks;
        double alf=360/ks;
        alf=alf*PI/180.0;
        double xi,yi,ri;
        ri=(r1+r2)/2;
        memDC.SetPen(wxPen(wxColor(28,28,28)));
        for(int i=0;i<ks;i++)
        {
            xi=x1+r1+ri*sin(alf*i);
            yi=y1+r1-ri*cos(alf*i);
            memDC.SetBrush(wxBrush(wxColor(33,40,48)));
            memDC.DrawCircle(xi,yi,5);

            if(i==0)
            {
                memDC.DrawLine(x1+r1,y1+r1,xi,yi);
                xi=x1+r1+ri*sin(alf);
                yi=y1+r1-ri*cos(alf);
                memDC.DrawLine(x1+r1,y1+r1,xi,yi);
                memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                memDC.DrawArc((x1+r1+xi)/2,(y1+r1+yi)/2,x1+r1,y1+r1/2,x1+r1,y1+r1);
                memDC.SetBrush(wxBrush(wxColor(255,255,0)));
                memDC.SetFont(ens);
                xi=x1+r1+ri/2*sin(alf/2);
                yi=y1+r1-ri/2*cos(alf/2);
                memDC.DrawLabel(_("θ"),wxRect(xi+5,yi-5,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
        }

        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.DrawLine(x1,y1+r1+38,x1+7,y1+r1+45);
        memDC.DrawLine(x1+7,y1+r1+45,x1+r1-7,y1+r1+45);
        memDC.DrawLine(x1+r1-7,y1+r1+45,x1+r1,y1+r1+52);
        memDC.DrawLine(x1+r1,y1+r1+52,x1+r1+7,y1+r1+45);
        memDC.DrawLine(x1+r1+7,y1+r1+45,x1+r1*2-7,y1+r1+45);
        memDC.DrawLine(x1+r1*2-7,y1+r1+45,x1+r1*2,y1+r1+38);
        memDC.DrawLabel(_("De"),wxRect(x1+r1,y1+r1+52,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.DrawLine(x1+r1-r2,y1+r1,x1+r1-r2+7,y1+r1+7);
        memDC.DrawLine(x1+r1-r2+7,y1+r1+7,x1+r1-7,y1+r1+7);
        memDC.DrawLine(x1+r1-7,y1+r1+7,x1+r1,y1+r1+14);
        memDC.DrawLine(x1+r1,y1+r1+14,x1+r1+7,y1+r1+7);
        memDC.DrawLine(x1+r1+7,y1+r1+7,x1+r1+r2-7,y1+r1+7);
        memDC.DrawLine(x1+r1+r2-7,y1+r1+7,x1+r1+r2,y1+r1);
        memDC.DrawLabel(_("D"),wxRect(x1+r1,y1+r1+18,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

        y1=y1+2*r1+64;
        h1=h-y1-45;
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetPen(wxPen(wxColor(122,122,122),1,wxDOT_DASH));
        memDC.DrawLine(x1+w1/2,y1-17,x1+w1/2,y1+h1+14);

        int x2,y2,w2,h2;
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(segset.in==1)
        {
            x2=x1+w1/2;
            y2=y1;
            h2=h1;
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2,y2,x2+7,y2+7);
            memDC.DrawLine(x2+7,y2+7,x2+7,y2+h2/2-7);
            memDC.DrawLine(x2+7,y2+h2/2-7,x2+14,y2+h2/2);
            memDC.DrawLine(x2+14,y2+h2/2,x2+7,y2+h2/2+7);
            memDC.DrawLine(x2+7,y2+h2/2+7,x2+7,y2+h2-7);
            memDC.DrawLine(x2+7,y2+h2-7,x2,y2+h2);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("L"),wxRect(x2+5,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(segset.f2b==0)
        {
            memDC.DrawLine(x1,y1,x1,y1-16);
            memDC.DrawLine(x1,y1-16,x1+w1,y1);
            memDC.DrawLine(x1,y1+h1,x1,y1+h1+16);
            memDC.DrawLine(x1,y1+h1+16,x1+w1,y1+h1);

            x2=x1+w1/2;
            y2=y1-8;
            h2=h1+16;
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2,y2,x2+7,y2+7);
            memDC.DrawLine(x2+7,y2+7,x2+7,y2+h2/2-7);
            memDC.DrawLine(x2+7,y2+h2/2-7,x2+14,y2+h2/2);
            memDC.DrawLine(x2+14,y2+h2/2,x2+7,y2+h2/2+7);
            memDC.DrawLine(x2+7,y2+h2/2+7,x2+7,y2+h2-7);
            memDC.DrawLine(x2+7,y2+h2-7,x2,y2+h2);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("L"),wxRect(x2+19,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            x2=x1;
            y2=y1-16;
            h2=h1+32;
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2,y2,x2+7,y2+7);
            memDC.DrawLine(x2+7,y2+7,x2+7,y2+h2/2-7);
            memDC.DrawLine(x2+7,y2+h2/2-7,x2+14,y2+h2/2);
            memDC.DrawLine(x2+14,y2+h2/2,x2+7,y2+h2/2+7);
            memDC.DrawLine(x2+7,y2+h2/2+7,x2+7,y2+h2-7);
            memDC.DrawLine(x2+7,y2+h2-7,x2,y2+h2);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("L1"),wxRect(x2+18,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            x2=x1+w1;
            y2=y1;
            h2=h1;
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2,y2,x2-7,y2+7);
            memDC.DrawLine(x2-7,y2+7,x2-7,y2+h2/2-7);
            memDC.DrawLine(x2-7,y2+h2/2-7,x2-14,y2+h2/2);
            memDC.DrawLine(x2-14,y2+h2/2,x2-7,y2+h2/2+7);
            memDC.DrawLine(x2-7,y2+h2/2+7,x2-7,y2+h2-7);
            memDC.DrawLine(x2-7,y2+h2-7,x2,y2+h2);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("L2"),wxRect(x2-19,y2,0,h2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

            memDC.DrawLabel(_("△L = L2-L1"),wxRect(x1+w1/2,y1+h1+15,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        }
        else
        {
            memDC.DrawLine(x1,y1,x1,y1-16);
            memDC.DrawLine(x1,y1-16,x1+w1,y1);

            x2=x1+w1/2;
            y2=y1-8;
            h2=h1+8;
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2,y2,x2+7,y2+7);
            memDC.DrawLine(x2+7,y2+7,x2+7,y2+h2/2-7);
            memDC.DrawLine(x2+7,y2+h2/2-7,x2+14,y2+h2/2);
            memDC.DrawLine(x2+14,y2+h2/2,x2+7,y2+h2/2+7);
            memDC.DrawLine(x2+7,y2+h2/2+7,x2+7,y2+h2-7);
            memDC.DrawLine(x2+7,y2+h2-7,x2,y2+h2);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("L"),wxRect(x2+19,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            x2=x1;
            y2=y1-16;
            h2=h1+16;
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2,y2,x2+7,y2+7);
            memDC.DrawLine(x2+7,y2+7,x2+7,y2+h2/2-7);
            memDC.DrawLine(x2+7,y2+h2/2-7,x2+14,y2+h2/2);
            memDC.DrawLine(x2+14,y2+h2/2,x2+7,y2+h2/2+7);
            memDC.DrawLine(x2+7,y2+h2/2+7,x2+7,y2+h2-7);
            memDC.DrawLine(x2+7,y2+h2-7,x2,y2+h2);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("L1"),wxRect(x2+18,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            x2=x1+w1;
            y2=y1;
            h2=h1;
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x2,y2,x2-7,y2+7);
            memDC.DrawLine(x2-7,y2+7,x2-7,y2+h2/2-7);
            memDC.DrawLine(x2-7,y2+h2/2-7,x2-14,y2+h2/2);
            memDC.DrawLine(x2-14,y2+h2/2,x2-7,y2+h2/2+7);
            memDC.DrawLine(x2-7,y2+h2/2+7,x2-7,y2+h2-7);
            memDC.DrawLine(x2-7,y2+h2-7,x2,y2+h2);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("L2"),wxRect(x2-19,y2,0,h2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

            memDC.DrawLabel(_("△L = L2-L1"),wxRect(x1+w1/2,y1+h1+15,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintSegTxt(wxPaintEvent& event)
{
    wxPaintDC dc(segTxtPanel);
    int w,h;
    segTxtPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont ens(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);

        int x1,y1,w1,h1;
        x1=20;
        y1=10;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("拼装方式"),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(x1+55,y1,w-x1,y1);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1+55,y1+1,w-x1,y1+1);

        y1=y1+15;
        w1=110;
        h1=25;
        figButton[ID_FIG_S2S_TYPE1].x=x1;
        figButton[ID_FIG_S2S_TYPE1].y=y1;
        figButton[ID_FIG_S2S_TYPE1].width=w1;
        figButton[ID_FIG_S2S_TYPE1].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(segset.in==0)
        {
            if(motion1==ID_FIG_S2S_TYPE1)
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
            memDC.DrawLabel(_("错缝拼装"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_S2S_TYPE1)
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
            memDC.DrawLabel(_("错缝拼装"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        figButton[ID_FIG_S2S_TYPE2].x=x1;
        figButton[ID_FIG_S2S_TYPE2].y=y1;
        figButton[ID_FIG_S2S_TYPE2].width=w1;
        figButton[ID_FIG_S2S_TYPE2].height=h1;
        if(segset.in==1)
        {
            if(motion1==ID_FIG_S2S_TYPE2)
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
            memDC.DrawLabel(_("通缝拼装"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_S2S_TYPE2)
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
            memDC.DrawLabel(_("通缝拼装"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=20;
        y1=y1+30;
        memDC.SetTextForeground(icolor[0]);
        memDC.DrawLabel(_("管环类型"),wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(x1+55,y1+h1/2,w-x1,y1+h1/2);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1+55,y1+h1/2+1,w-x1,y1+h1/2+1);
        y1=y1+25;
        w1=110;
        figButton[ID_FIG_SEG_TYPE1].x=x1;
        figButton[ID_FIG_SEG_TYPE1].y=y1;
        figButton[ID_FIG_SEG_TYPE1].width=w1;
        figButton[ID_FIG_SEG_TYPE1].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(segset.in==1)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            memDC.SetTextForeground(wxColor(158,158,158));
            memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            memDC.DrawLabel(_("标准环+转弯环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(segset.type==1)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_SEG_TYPE1)
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
            memDC.DrawLabel(_("标准环+转弯环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_SEG_TYPE1)
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
            memDC.DrawLabel(_("标准环+转弯环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        w1=90;
        figButton[ID_FIG_SEG_TYPE2].x=x1;
        figButton[ID_FIG_SEG_TYPE2].y=y1;
        figButton[ID_FIG_SEG_TYPE2].width=w1;
        figButton[ID_FIG_SEG_TYPE2].height=h1;
        if(segset.in==1)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            memDC.SetTextForeground(wxColor(158,158,158));
            memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            memDC.DrawLabel(_("通用管环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(segset.type==0)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_SEG_TYPE2)
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
            memDC.DrawLabel(_("通用管环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_SEG_TYPE2)
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
            memDC.DrawLabel(_("通用管环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        figButton[ID_FIG_SEG_TYPE3].x=x1;
        figButton[ID_FIG_SEG_TYPE3].y=y1;
        figButton[ID_FIG_SEG_TYPE3].width=w1;
        figButton[ID_FIG_SEG_TYPE3].height=h1;
        if(segset.in==1)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            memDC.SetTextForeground(wxColor(158,158,158));
            memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.SetBrush(wxBrush(wxColor(158,158,158)));
            memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            memDC.DrawLabel(_("标准管环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            memDC.SetTextForeground(wxColor(158,158,158));
            memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            memDC.DrawLabel(_("标准管环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=20;
        y1=y1+30;
        memDC.SetTextForeground(icolor[0]);
        memDC.DrawLabel(_("楔形类型"),wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(x1+55,y1+h1/2,w-x1,y1+h1/2);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1+55,y1+h1/2+1,w-x1,y1+h1/2+1);
        y1=y1+25;
        w1=110;
        figButton[ID_FIG_F2B_TTPE1].x=x1;
        figButton[ID_FIG_F2B_TTPE1].y=y1;
        figButton[ID_FIG_F2B_TTPE1].width=w1;
        figButton[ID_FIG_F2B_TTPE1].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(segset.in==1)
        {
            if(segset.f2b==0)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.SetBrush(wxBrush(wxColor(239,239,239)));
                memDC.SetTextForeground(wxColor(158,158,158));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetBrush(wxBrush(wxColor(158,158,158)));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
                memDC.DrawLabel(_("等腰梯形"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.SetBrush(wxBrush(wxColor(239,239,239)));
                memDC.SetTextForeground(wxColor(158,158,158));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.DrawLabel(_("等腰梯形"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else if(segset.f2b==0)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_F2B_TTPE1)
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
            memDC.DrawLabel(_("等腰梯形"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_F2B_TTPE1)
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
            memDC.DrawLabel(_("等腰梯形"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        figButton[ID_FIG_F2B_TTPE2].x=x1;
        figButton[ID_FIG_F2B_TTPE2].y=y1;
        figButton[ID_FIG_F2B_TTPE2].width=w1;
        figButton[ID_FIG_F2B_TTPE2].height=h1;
        if(segset.in==1)
        {
            if(segset.f2b==1)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.SetBrush(wxBrush(wxColor(239,239,239)));
                memDC.SetTextForeground(wxColor(158,158,158));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetBrush(wxBrush(wxColor(158,158,158)));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
                memDC.DrawLabel(_("直角梯形"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.SetBrush(wxBrush(wxColor(239,239,239)));
                memDC.SetTextForeground(wxColor(158,158,158));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.DrawLabel(_("直角梯形"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else if(segset.f2b==1)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_F2B_TTPE2)
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
            memDC.DrawLabel(_("直角梯形"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_F2B_TTPE2)
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
            memDC.DrawLabel(_("直角梯形"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=20;
        y1=y1+30;
        memDC.SetTextForeground(icolor[0]);
        memDC.DrawLabel(_("错缝条件"),wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(x1+55,y1+h1/2,w-x1,y1+h1/2);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1+55,y1+h1/2+1,w-x1,y1+h1/2+1);
        y1=y1+25;
        w1=110;
        figButton[ID_FIG_S2S_12].x=x1;
        figButton[ID_FIG_S2S_12].y=y1;
        figButton[ID_FIG_S2S_12].width=w1;
        figButton[ID_FIG_S2S_12].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(segset.in==1)
        {
            if(segset.s2s==2)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.SetBrush(wxBrush(wxColor(239,239,239)));
                memDC.SetTextForeground(wxColor(158,158,158));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetBrush(wxBrush(wxColor(158,158,158)));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
                memDC.DrawLabel(_("1/2 K块长度"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.SetBrush(wxBrush(wxColor(239,239,239)));
                memDC.SetTextForeground(wxColor(158,158,158));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.DrawLabel(_("1/2 K块长度"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else if(segset.s2s==2)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_S2S_12)
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
            memDC.DrawLabel(_("1/2 K块长度"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_S2S_12)
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
            memDC.DrawLabel(_("1/2 K块长度"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        figButton[ID_FIG_S2S_13].x=x1;
        figButton[ID_FIG_S2S_13].y=y1;
        figButton[ID_FIG_S2S_13].width=w1;
        figButton[ID_FIG_S2S_13].height=h1;
        if(segset.in==1)
        {
            if(segset.s2s==3)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.SetBrush(wxBrush(wxColor(239,239,239)));
                memDC.SetTextForeground(wxColor(158,158,158));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetBrush(wxBrush(wxColor(158,158,158)));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
                memDC.DrawLabel(_("1/3 K块长度"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.SetBrush(wxBrush(wxColor(239,239,239)));
                memDC.SetTextForeground(wxColor(158,158,158));
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.DrawLabel(_("1/3 K块长度"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else if(segset.s2s==3)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_S2S_13)
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
            memDC.DrawLabel(_("1/3 K块长度"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion1==ID_FIG_S2S_13)
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
            memDC.DrawLabel(_("1/3 K块长度"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=20;
        y1=y1+45;
        w1=100;
        h1=25;
        int w2=140;
        memDC.SetFont(chs);
        memDC.SetTextForeground(icolor[0]);
        memDC.DrawLabel(_("管环长度 L"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1,y1,w2,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w2-30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        segL->SetSize(x1+w1+1,y1+5,w2-32,h1-6);

        y1=y1+30;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("管环内直径 D"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1,y1,w2,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w2-30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        segD1->SetSize(x1+w1+1,y1+5,w2-32,h1-6);

        y1=y1+30;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("管环外直径 De"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1,y1,w2,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w2-30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        segD2->SetSize(x1+w1+1,y1+5,w2-32,h1-6);

        y1=y1+30;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("转动角度 θ"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1,y1,w2,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("°"),wxRect(x1+w1+w2-30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        segKs->SetSize(x1+w1+1,y1+5,w2-32,h1-6);

        y1=y1+30;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("标准盾尾间隙"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1,y1,w2,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w2-30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        segG0->SetSize(x1+w1+1,y1+5,w2-32,h1-6);

        y1=y1+30;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("最小盾尾间隙"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1,y1,w2,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w2-30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        segG1->SetSize(x1+w1+1,y1+5,w2-32,h1-6);

        y1=y1+30;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("管环楔形量 △L"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        if(segset.in==0)
        {
            memDC.SetPen(wxPen(wxColor(122,122,122)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.SetTextForeground(icolor[0]);
            segL2s->Enable(true);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            memDC.SetTextForeground(wxColor(158,158,158));
            segL2s->Enable(false);
        }
        memDC.DrawRectangle(x1+w1,y1,w2,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w2-30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        segL2s->SetSize(x1+w1+1,y1+5,w2-32,h1-6);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionSegTxt(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_S2S_TYPE1].y && y<figButton[ID_FIG_S2S_TYPE1].y+figButton[ID_FIG_S2S_TYPE1].height)
    {
        if(x>figButton[ID_FIG_S2S_TYPE1].x && x<figButton[ID_FIG_S2S_TYPE1].x+figButton[ID_FIG_S2S_TYPE1].width)
        {
            motion1=ID_FIG_S2S_TYPE1;
        }
        else if(x>figButton[ID_FIG_S2S_TYPE2].x && x<figButton[ID_FIG_S2S_TYPE2].x+figButton[ID_FIG_S2S_TYPE2].width)
        {
            motion1=ID_FIG_S2S_TYPE2;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_SEG_TYPE1].y && y<figButton[ID_FIG_SEG_TYPE1].y+figButton[ID_FIG_SEG_TYPE1].height)
    {
        if(x>figButton[ID_FIG_SEG_TYPE1].x && x<figButton[ID_FIG_SEG_TYPE1].x+figButton[ID_FIG_SEG_TYPE1].width)
        {
            motion1=ID_FIG_SEG_TYPE1;
        }
        else if(x>figButton[ID_FIG_SEG_TYPE2].x && x<figButton[ID_FIG_SEG_TYPE2].x+figButton[ID_FIG_SEG_TYPE2].width)
        {
            motion1=ID_FIG_SEG_TYPE2;
        }
        else if(x>figButton[ID_FIG_SEG_TYPE3].x && x<figButton[ID_FIG_SEG_TYPE3].x+figButton[ID_FIG_SEG_TYPE3].width)
        {
            motion1=ID_FIG_SEG_TYPE3;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_F2B_TTPE1].y && y<figButton[ID_FIG_F2B_TTPE1].y+figButton[ID_FIG_F2B_TTPE1].height)
    {
        if(x>figButton[ID_FIG_F2B_TTPE1].x && x<figButton[ID_FIG_F2B_TTPE1].x+figButton[ID_FIG_F2B_TTPE1].width)
        {
            motion1=ID_FIG_F2B_TTPE1;
        }
        else if(x>figButton[ID_FIG_F2B_TTPE2].x && x<figButton[ID_FIG_F2B_TTPE2].x+figButton[ID_FIG_F2B_TTPE2].width)
        {
            motion1=ID_FIG_F2B_TTPE2;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_S2S_12].y && y<figButton[ID_FIG_S2S_12].y+figButton[ID_FIG_S2S_12].height)
    {
        if(x>figButton[ID_FIG_S2S_12].x && x<figButton[ID_FIG_S2S_12].x+figButton[ID_FIG_S2S_12].width)
        {
            motion1=ID_FIG_S2S_12;
        }
        else if(x>figButton[ID_FIG_S2S_13].x && x<figButton[ID_FIG_S2S_13].x+figButton[ID_FIG_S2S_13].width)
        {
            motion1=ID_FIG_S2S_13;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    segTxtPanel->Refresh();
    segFigPanel->Refresh();
}

void ConfigDlg::OnLeaveSegTxt(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    segTxtPanel->Refresh();
    segFigPanel->Refresh();
}

void ConfigDlg::OnClickSegTxt(wxMouseEvent& event)
{
    if(motion1==ID_FIG_S2S_TYPE1)
    {
        if(segset.in==1)
        {
            segset.in=0;
            //segModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_S2S_TYPE2)
    {
        if(segset.in==0)
        {
            segset.in=1;
            //segModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_SEG_TYPE1)
    {
        if(segset.in==1) return;
        if(segset.type!=1)
        {
            segset.type=1;
            //segModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_SEG_TYPE2)
    {
        if(segset.in==1) return;
        if(segset.type!=0)
        {
            segset.type=0;
            //segModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_F2B_TTPE1)
    {
        if(segset.in==1) return;
        if(segset.f2b==1)
        {
            segset.f2b=0;
            //segModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_F2B_TTPE2)
    {
        if(segset.in==1) return;
        if(segset.f2b==0)
        {
            segset.f2b=1;
            //segModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_S2S_12)
    {
        if(segset.in==1) return;
        segset.s2s=2;
        //segModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_S2S_13)
    {
        if(segset.in==1) return;
        segset.s2s=3;
        //segModified=1;
        panelBottom->Refresh();
    }
    segTxtPanel->Refresh();
    segFigPanel->Refresh();
}

void ConfigDlg::OnPaintBlockList(wxPaintEvent& event)
{
    wxPaintDC dc(blkListPanel);
    int w,h;
    blkListPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=24;
        memDC.DrawLine(x1,y1+h1,w,y1+h1);

        w1=blockList->GetColumnWidth(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=blockList->GetColumnWidth(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("管块名称"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=blockList->GetColumnWidth(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("圆心角(°)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintBlkButton1(wxPaintEvent& event)
{
    wxPaintDC dc(blkButton1Panel);
    int w,h;
    blkButton1Panel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=25;

        figButton[ID_FIG_BLK_ADD].x=x1+1;
        figButton[ID_FIG_BLK_ADD].y=y1+1;
        figButton[ID_FIG_BLK_ADD].width=w1-1;
        figButton[ID_FIG_BLK_ADD].height=h1-2;
        if(motion1==ID_FIG_BLK_ADD)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(figButton[ID_FIG_BLK_ADD],3);
        memDC.DrawLabel(_("添加"),wxRect(figButton[ID_FIG_BLK_ADD]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+5;
        figButton[ID_FIG_BLK_EDI].x=x1+1;
        figButton[ID_FIG_BLK_EDI].y=y1+1;
        figButton[ID_FIG_BLK_EDI].width=w1-1;
        figButton[ID_FIG_BLK_EDI].height=h1-2;
        if(motion1==ID_FIG_BLK_EDI)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);

        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(figButton[ID_FIG_BLK_EDI],3);
        memDC.DrawLabel(_("编辑"),wxRect(figButton[ID_FIG_BLK_EDI]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+5;
        figButton[ID_FIG_BLK_DEL].x=x1+1;
        figButton[ID_FIG_BLK_DEL].y=y1+1;
        figButton[ID_FIG_BLK_DEL].width=w1-1;
        figButton[ID_FIG_BLK_DEL].height=h1-2;
        if(motion1==ID_FIG_BLK_DEL)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);

        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(figButton[ID_FIG_BLK_DEL],3);
        memDC.DrawLabel(_("删除"),wxRect(figButton[ID_FIG_BLK_DEL]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionBlkButton1(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();

    if(x>figButton[ID_FIG_BLK_ADD].x && x<figButton[ID_FIG_BLK_ADD].x+figButton[ID_FIG_BLK_ADD].width)
    {
        if(y>figButton[ID_FIG_BLK_ADD].y && y<figButton[ID_FIG_BLK_ADD].y+figButton[ID_FIG_BLK_ADD].height)
        {
            motion1=ID_FIG_BLK_ADD;
        }
        else if(y>figButton[ID_FIG_BLK_EDI].y && y<figButton[ID_FIG_BLK_EDI].y+figButton[ID_FIG_BLK_EDI].height)
        {
            motion1=ID_FIG_BLK_EDI;
        }
        else if(y>figButton[ID_FIG_BLK_DEL].y && y<figButton[ID_FIG_BLK_DEL].y+figButton[ID_FIG_BLK_DEL].height)
        {
            motion1=ID_FIG_BLK_DEL;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    blkButton1Panel->Refresh();
}

void ConfigDlg::OnLeaveBlkButton1(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    blkButton1Panel->Refresh();
}

void ConfigDlg::OnClickBlkButton1(wxMouseEvent& event)
{
    //if(opLevel>0) return;
    if(mtg->onLine>0) return;
    wxString str1;
    double val;
    if(motion1==ID_FIG_BLK_ADD)
    {
        BlockDlg dlg(this);
        dlg.Center();
        dlg.blkName->SetFocus();
        if(dlg.ShowModal()==wxID_OK)
        {
            MTG_BLOCK b;
            str1=dlg.blkName->GetValue();
            strncpy(b.name,str1.mb_str(wxConvUTF8),64);
            dlg.Angle->GetValue().ToDouble(&b.angle);
            b.angle=b.angle*PI/180.0;
            if(nblk>=36)
            {
                for(int i=0;i<35;i++)
                {
                    blocks[i]=blocks[i+1];
                }
                blocks[35]=b;
                nblk=36;
            }
            else
            {
                nblk++;
                blocks[nblk-1]=b;
            }
            UpdateBlocks();
            panelBottom->Refresh();
            blkFigPanel->Refresh();
        }
    }
    else if(motion1==ID_FIG_BLK_EDI)
    {
        int n = blockList->GetFirstSelected();
        int Num = blockList->GetItemCount();
        if(n<0 || n>Num-1) return;

        BlockDlg dlg(this);
        dlg.Center();
        str1=wxString(blocks[n].name,wxConvUTF8);
        dlg.blkName->SetValue(str1);
        str1=wxString::Format(_("%.2f"),blocks[n].angle*180.0/PI);
        dlg.Angle->SetValue(str1);
        if(dlg.ShowModal()==wxID_OK)
        {
            str1=dlg.blkName->GetValue();
            strncpy(blocks[n].name,str1.mb_str(wxConvUTF8),64);
            dlg.Angle->GetValue().ToDouble(&blocks[n].angle);
            blocks[n].angle=blocks[n].angle*PI/180.0;
            WriteMsg(_("编辑管块成功"),0);
            UpdateBlocks();
            //blockModified=1;
            panelBottom->Refresh();
            blkFigPanel->Refresh();
        }
    }
    else if(motion1==ID_FIG_BLK_DEL)
    {
        int n = blockList->GetFirstSelected();
        int Num = blockList->GetItemCount();
        if(n<0 || n>Num-1) return;

        nblk--;
        for(int i=n;i<nblk;i++)
        {
            blocks[i]=blocks[i+1];
        }
        UpdateBlocks();
        if(n<nblk)
        {
            blockList->Select(n);
            blockList->EnsureVisible(n);
        }
        else if(n>0)
        {
            blockList->Select(n-1);
            blockList->EnsureVisible(n-1);
        }
        blkFigPanel->Refresh();
        //blockModified=1;
        WriteMsg(_("删除管块成功"),0);
    }
    blkButton1Panel->Refresh();
}

void ConfigDlg::OnPaintBlkFig(wxPaintEvent& event)
{
    wxPaintDC dc(blkFigPanel);
    int w,h;
    blkFigPanel->GetClientSize(&w,&h);
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
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        int r1,r2;

        y1=10;
        h1=h-20;
        w1=h1;
        r1=w1/2;
        r2=r1-15;
        x1=w/2-r1;
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawCircle(x1+r1,y1+r1,r1);
        memDC.DrawCircle(x1+r1,y1+r1,r2);

        memDC.SetPen(wxPen(wxColor(122,122,122),1,wxDOT_DASH));
        memDC.DrawLine(0,y1+r1,w,y1+r1);
        memDC.DrawLine(x1+r1,0,x1+r1,2*y1+2*r1);

        int x2,y2,x3,y3,x4,x5;
        int x0,y0;
        x0=x1+r1;
        y0=y1+r1;
        if(nblk>0)
        {
            double angle = PI*3/2-blocks[0].angle/2.0;
            int sel=blockList->GetFirstSelected();
            if(sel>=0 && sel<nblk)
            {
                for(int i=0;i<sel;i++)
                {
                    angle+=blocks[i].angle;
                }
                x2=x0+r1*cos(angle);
                y2=y0+r1*sin(angle);
                x3=x0+r2*cos(angle);
                y3=y0+r2*sin(angle);
                x4=x2;
                memDC.SetPen(wxPen(wxColor(122,122,122)));
                memDC.DrawLine(x2,y2,x3,y3);
                memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT));
                memDC.DrawLine(x0,y0,x3,y3);
                angle+=blocks[sel].angle;
                x2=x0+r1*cos(angle);
                y2=y0+r1*sin(angle);
                x3=x0+r2*cos(angle);
                y3=y0+r2*sin(angle);
                x5=x2;
                memDC.SetPen(wxPen(wxColor(122,122,122)));
                memDC.DrawLine(x2,y2,x3,y3);
                memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT));
                memDC.DrawLine(x0,y0,x3,y3);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintM1Button(wxPaintEvent& event)
{
    wxPaintDC dc(m1ButtonPanel);
    int w,h;
    m1ButtonPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=25;

        figButton[ID_FIG_M1_IMPORT].x=x1;
        figButton[ID_FIG_M1_IMPORT].y=y1;
        figButton[ID_FIG_M1_IMPORT].width=w1;
        figButton[ID_FIG_M1_IMPORT].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(motion1==ID_FIG_M1_IMPORT)
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
        memDC.DrawLabel(_("导入"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+5;
        figButton[ID_FIG_M1_EXPORT].x=x1;
        figButton[ID_FIG_M1_EXPORT].y=y1;
        figButton[ID_FIG_M1_EXPORT].width=w1;
        figButton[ID_FIG_M1_EXPORT].height=h1;
        if(motion1==ID_FIG_M1_EXPORT)
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

        y1=165;
        figButton[ID_FIG_M1_MEA].x=x1;
        figButton[ID_FIG_M1_MEA].y=y1;
        figButton[ID_FIG_M1_MEA].width=w1;
        figButton[ID_FIG_M1_MEA].height=h1;

        if(motion1==ID_FIG_M1_MEA)
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
        memDC.DrawLabel(_("测量"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionM1Button(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_M1_IMPORT].x && x<figButton[ID_FIG_M1_IMPORT].x+figButton[ID_FIG_M1_IMPORT].width)
    {
        if(y>figButton[ID_FIG_M1_IMPORT].y && y<figButton[ID_FIG_M1_IMPORT].y+figButton[ID_FIG_M1_IMPORT].height)
        {
            motion1=ID_FIG_M1_IMPORT;
        }
        else if(y>figButton[ID_FIG_M1_MEA].y && y<figButton[ID_FIG_M1_MEA].y+figButton[ID_FIG_M1_MEA].height)
        {
            motion1=ID_FIG_M1_MEA;
        }
        else if(y>figButton[ID_FIG_M1_EXPORT].y && y<figButton[ID_FIG_M1_EXPORT].y+figButton[ID_FIG_M1_EXPORT].height)
        {
            motion1=ID_FIG_M1_EXPORT;
        }
        else if(y>figButton[ID_FIG_M1_MEA_P1].y && y<figButton[ID_FIG_M1_MEA_P1].y+figButton[ID_FIG_M1_MEA_P1].height)
        {
            motion1=ID_FIG_M1_MEA_P1;
        }
        else if(y>figButton[ID_FIG_M1_MEA_P2].y && y<figButton[ID_FIG_M1_MEA_P2].y+figButton[ID_FIG_M1_MEA_P2].height)
        {
            motion1=ID_FIG_M1_MEA_P2;
        }
        else if(y>figButton[ID_FIG_M1_MEA_P3].y && y<figButton[ID_FIG_M1_MEA_P3].y+figButton[ID_FIG_M1_MEA_P3].height)
        {
            motion1=ID_FIG_M1_MEA_P3;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    m1ButtonPanel->Refresh();
}

void ConfigDlg::OnLeaveM1Button(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    m1ButtonPanel->Refresh();
}

void ConfigDlg::OnClickM1Button(wxMouseEvent& event)
{
    if(motion1==ID_FIG_M1_MEA)
    {
        mtg->m=mtg->m0;
        if(mtg_start_origin(mtg)==-1)
        {
            WriteMsg(_("初始姿态测量失败，请检查"),1);
        }
    }
    else if(motion1==ID_FIG_M1_IMPORT)
    {
        wxFileDialog dlg(this,_("请选择要打开的文件"),_(""),_(""),_("零位数据文件(*.ori)|*.ori"),wxFD_OPEN);
        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str=dlg.GetPath();
            char buf[1024];
            strcpy(buf,str.mb_str(wxConvLocal));
            FILE* fp=fopen(buf,"rb");
            if(fp)
            {
                if(mtg->tarset.baseinc==1)
                {
                    fread(&m1.inc[5],sizeof(double),1,fp);
                    fread(&m1.inc[6],sizeof(double),1,fp);
                }
                else
                {
                    fread(&m1.inc[0],sizeof(double),1,fp);
                    fread(&m1.inc[1],sizeof(double),1,fp);
                }
			    fread(&m1.inc[2],sizeof(double),1,fp);
			    fread(&m1.inc[3],sizeof(double),1,fp);
			    fread(&m1.cam[0],sizeof(double),1,fp);
			    fread(&m1.cam[1],sizeof(double),1,fp);
			    fread(&m1.cam[2],sizeof(double),1,fp);
			    fread(&m1.cam[3],sizeof(double),1,fp);
			    fread(&m1.prism[0],sizeof(double),1,fp);
			    fread(&m1.prism[1],sizeof(double),1,fp);
			    fread(&m1.prism[2],sizeof(double),1,fp);
			    fread(&m1.angle[0],sizeof(double),1,fp);
			    fread(&m1.angle[1],sizeof(double),1,fp);
			    fread(&m1.comp[0],sizeof(double),1,fp);
			    fread(&m1.comp[1],sizeof(double),1,fp);
                fread(&m1.head[0],sizeof(double),1,fp);
                fread(&m1.head[1],sizeof(double),1,fp);
                fread(&m1.head[2],sizeof(double),1,fp);
			    fread(&m1.tail[0],sizeof(double),1,fp);
                fread(&m1.tail[1],sizeof(double),1,fp);
                fread(&m1.tail[2],sizeof(double),1,fp);
			    fread(&m1.faj[0],sizeof(double),1,fp);
			    fread(&m1.faj[1],sizeof(double),1,fp);
			    fread(&m1.faj[2],sizeof(double),1,fp);
			    fread(&m1.faj[3],sizeof(double),1,fp);
			    fread(&m1.baj[0],sizeof(double),1,fp);
			    fread(&m1.baj[1],sizeof(double),1,fp);
			    fread(&m1.baj[2],sizeof(double),1,fp);
			    fread(&m1.baj[3],sizeof(double),1,fp);
			    fread(&m1.aj[0],sizeof(double),1,fp);
			    fread(&m1.aj[1],sizeof(double),1,fp);
			    fread(&m1.aj[2],sizeof(double),1,fp);
			    fread(&m1.aj[3],sizeof(double),1,fp);
			    fread(&m1.inc1[0],sizeof(double),1,fp);
			    fread(&m1.inc1[1],sizeof(double),1,fp);
			    fread(&m1.inc1[2],sizeof(double),1,fp);
			    fread(&m1.prism[0],sizeof(double),1,fp);
			    fread(&m1.prism[1],sizeof(double),1,fp);
			    fread(&m1.prism[2],sizeof(double),1,fp);
			    fread(&m1.prism[3],sizeof(double),1,fp);
			    fread(&m1.prism[4],sizeof(double),1,fp);
			    fread(&m1.prism[5],sizeof(double),1,fp);
			    fread(&m1.prism[6],sizeof(double),1,fp);
			    fread(&m1.prism[7],sizeof(double),1,fp);
			    fread(&m1.prism[8],sizeof(double),1,fp);
			    fread(&m1.t1,sizeof(long),1,fp);
			    fread(&m1.t2,sizeof(long),1,fp);
			    fread(&m1.t3,sizeof(long),1,fp);
                fclose(fp);
                UpdateOrigin();
            }
        }
    }
    else if(motion1==ID_FIG_M1_EXPORT)
    {
        time_t t1;
        time(&t1);
        wxString str=wxString(prj.name,wxConvUTF8);
        str+=wxDateTime(t1).Format(_("(%Y%m%d%H%M).ori"));
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("零位数据文件(*.ori)|*.ori"),wxFD_SAVE);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            char cs[1024];
            strcpy(cs,str.mb_str(wxConvLocal));
            FILE* fp=fopen(cs,"wb");
            if(fp)
            {
                if(mtg->tarset.baseinc==1)
                {
                    fwrite(&m1.inc[5],sizeof(double),1,fp);
                    fwrite(&m1.inc[6],sizeof(double),1,fp);
                }
                else
                {
                    fwrite(&m1.inc[0],sizeof(double),1,fp);
                    fwrite(&m1.inc[1],sizeof(double),1,fp);
                }
			    fwrite(&m1.inc[2],sizeof(double),1,fp);
			    fwrite(&m1.inc[3],sizeof(double),1,fp);
			    fwrite(&m1.cam[0],sizeof(double),1,fp);
			    fwrite(&m1.cam[1],sizeof(double),1,fp);
			    fwrite(&m1.cam[2],sizeof(double),1,fp);
			    fwrite(&m1.cam[3],sizeof(double),1,fp);
			    fwrite(&m1.prism[0],sizeof(double),1,fp);
			    fwrite(&m1.prism[1],sizeof(double),1,fp);
			    fwrite(&m1.prism[2],sizeof(double),1,fp);
			    fwrite(&m1.angle[0],sizeof(double),1,fp);
			    fwrite(&m1.angle[1],sizeof(double),1,fp);
			    fwrite(&m1.comp[0],sizeof(double),1,fp);
			    fwrite(&m1.comp[1],sizeof(double),1,fp);
                fwrite(&m1.head[0],sizeof(double),1,fp);
                fwrite(&m1.head[1],sizeof(double),1,fp);
                fwrite(&m1.head[2],sizeof(double),1,fp);
			    fwrite(&m1.tail[0],sizeof(double),1,fp);
                fwrite(&m1.tail[1],sizeof(double),1,fp);
                fwrite(&m1.tail[2],sizeof(double),1,fp);
			    fwrite(&m1.faj[0],sizeof(double),1,fp);
			    fwrite(&m1.faj[1],sizeof(double),1,fp);
			    fwrite(&m1.faj[2],sizeof(double),1,fp);
			    fwrite(&m1.faj[3],sizeof(double),1,fp);
			    fwrite(&m1.baj[0],sizeof(double),1,fp);
			    fwrite(&m1.baj[1],sizeof(double),1,fp);
			    fwrite(&m1.baj[2],sizeof(double),1,fp);
			    fwrite(&m1.baj[3],sizeof(double),1,fp);
			    fwrite(&m1.aj[0],sizeof(double),1,fp);
			    fwrite(&m1.aj[1],sizeof(double),1,fp);
			    fwrite(&m1.aj[2],sizeof(double),1,fp);
			    fwrite(&m1.aj[3],sizeof(double),1,fp);
			    fwrite(&m1.inc1[0],sizeof(double),1,fp);
			    fwrite(&m1.inc1[1],sizeof(double),1,fp);
			    fwrite(&m1.inc1[2],sizeof(double),1,fp);
			    fwrite(&m1.prism[0],sizeof(double),1,fp);
			    fwrite(&m1.prism[1],sizeof(double),1,fp);
			    fwrite(&m1.prism[2],sizeof(double),1,fp);
			    fwrite(&m1.prism[3],sizeof(double),1,fp);
			    fwrite(&m1.prism[4],sizeof(double),1,fp);
			    fwrite(&m1.prism[5],sizeof(double),1,fp);
			    fwrite(&m1.prism[6],sizeof(double),1,fp);
			    fwrite(&m1.prism[7],sizeof(double),1,fp);
			    fwrite(&m1.prism[8],sizeof(double),1,fp);
			    fwrite(&m1.t1,sizeof(long),1,fp);
			    fwrite(&m1.t2,sizeof(long),1,fp);
			    fwrite(&m1.t3,sizeof(long),1,fp);
                fclose(fp);
            }
        }
    }
    m1ButtonPanel->Refresh();
}

void ConfigDlg::OnPaintSetTime(wxPaintEvent& event)
{
    wxPaintDC dc(setTimePanel);
    int w,h;
    setTimePanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=1;
        w1=60;
        h1=h-2;
        memDC.DrawLabel(_("测量周期"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        x1+=w1;
        w1=120;
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("秒"),wxRect(x1+w1-20,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        setMeasTime->SetSize(x1+1,y1+4,w1-22,h1-5);

        x1=x1+w1+35;
        w1=60;
        memDC.DrawLabel(_("后视检核"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        x1+=w1;
        w1=120;
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("秒"),wxRect(x1+w1-20,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        setBackTime->SetSize(x1+1,y1+4,w1-22,h1-5);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintSetDev(wxPaintEvent& event)
{
    wxPaintDC dc(setDevPanel);
    int w,h;
    setDevPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont ens(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=1;
        w1=60;
        h1=23;
        memDC.DrawLabel(_("偏差限差"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        x1+=w1;
        w1=120;
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1-32,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        setDev1->SetSize(x1+1,y1+4,w1-34,h1-5);

        x1=x1+w1+35;
        w1=60;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("偏差变化"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        x1+=w1;
        w1=120;
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1-32,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        setDev2->SetSize(x1+1,y1+4,w1-34,h1-5);

        x1=x1+w1+35;
        w1=60;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("转动角限差±"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        x1+=w1+20;
        w1=100;
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("°"),wxRect(x1+w1-32,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        setDev5->SetSize(x1+1,y1+4,w1-34,h1-5);

        x1=0;
        y1=y1+h1+5;
        w1=60;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("后视限差"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        x1+=w1;
        w1=120;
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1-32,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        setDev3->SetSize(x1+1,y1+4,w1-34,h1-5);

        x1=x1+w1+35;
        w1=60;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("时间限差"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        x1+=w1;
        w1=120;
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("秒"),wxRect(x1+w1-20,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        setDev4->SetSize(x1+1,y1+4,w1-22,h1-5);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintSetFun(wxPaintEvent& event)
{
    wxPaintDC dc(funPanel);
    int w,h;
    funPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=1;
        w1=60;
        h1=23;
        memDC.DrawLabel(_("施工环境"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_SET_VIBRATION_ON].x=x1;
        figButton[ID_FIG_SET_VIBRATION_ON].y=y1;
        figButton[ID_FIG_SET_VIBRATION_ON].width=w1;
        figButton[ID_FIG_SET_VIBRATION_ON].height=h1;

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.vibration==0)
        {
            if(motion1==ID_FIG_SET_VIBRATION_ON)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("常规施工环境"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_VIBRATION_ON)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("常规施工环境"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1+=w1;
        figButton[ID_FIG_SET_VIBRATION_YES].x=x1;
        figButton[ID_FIG_SET_VIBRATION_YES].y=y1;
        figButton[ID_FIG_SET_VIBRATION_YES].width=w1;
        figButton[ID_FIG_SET_VIBRATION_YES].height=h1;
        if(measet.vibration==1)
        {
            if(motion1==ID_FIG_SET_VIBRATION_YES)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("震动环境"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_VIBRATION_YES)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("震动环境"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1=y1+28;
        w1=60;
        memDC.DrawLabel(_("后视测量"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_STN_ACT0].x=x1;
        figButton[ID_FIG_STN_ACT0].y=y1;
        figButton[ID_FIG_STN_ACT0].width=w1;
        figButton[ID_FIG_STN_ACT0].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.rstn==0)
        {
            if(motion1==ID_FIG_STN_ACT0)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("检核，超限警告"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_STN_ACT0)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("检核，超限警告"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1+=w1;
        figButton[ID_FIG_STN_ACT1].x=x1;
        figButton[ID_FIG_STN_ACT1].y=y1;
        figButton[ID_FIG_STN_ACT1].width=w1;
        figButton[ID_FIG_STN_ACT1].height=h1;
        if(measet.rstn==1)
        {
            if(motion1==ID_FIG_STN_ACT1)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("测量并复位"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_STN_ACT1)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("测量并复位"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1=y1+28;
        w1=60;
        memDC.DrawLabel(_("掘进停止"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_SET_END_END].x=x1;
        figButton[ID_FIG_SET_END_END].y=y1;
        figButton[ID_FIG_SET_END_END].width=w1;
        figButton[ID_FIG_SET_END_END].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.tsyn==0)
        {
            if(motion1==ID_FIG_SET_END_END)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("停止测量"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_END_END)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("停止测量"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1+=w1;
        figButton[ID_FIG_SET_END_RUN].x=x1;
        figButton[ID_FIG_SET_END_RUN].y=y1;
        figButton[ID_FIG_SET_END_RUN].width=w1;
        figButton[ID_FIG_SET_END_RUN].height=h1;
        if(measet.tsyn==1)
        {
            if(motion1==ID_FIG_SET_END_RUN)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("继续测量"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_END_RUN)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("继续测量"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1=y1+28;
        w1=60;
        memDC.DrawLabel(_("环号计算"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_SET_RN1].x=x1;
        figButton[ID_FIG_SET_RN1].y=y1;
        figButton[ID_FIG_SET_RN1].width=w1;
        figButton[ID_FIG_SET_RN1].height=h1;
        if(measet.rget==0)
        {
            if(motion1==ID_FIG_SET_RN1)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("根据PLC状态计算"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_RN1)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("根据PLC状态计算"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1+=w1;
        figButton[ID_FIG_SET_RN2].x=x1;
        figButton[ID_FIG_SET_RN2].y=y1;
        figButton[ID_FIG_SET_RN2].width=w1;
        figButton[ID_FIG_SET_RN2].height=h1;
        if(measet.rget==1)
        {
            if(motion1==ID_FIG_SET_RN2)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("根据里程近似计算"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_RN2)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("根据里程近似计算"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1+=w1;
        figButton[ID_FIG_SET_RN3].x=x1;
        figButton[ID_FIG_SET_RN3].y=y1;
        figButton[ID_FIG_SET_RN3].width=w1;
        figButton[ID_FIG_SET_RN3].height=h1;
        if(measet.rget==2)
        {
            if(motion1==ID_FIG_SET_RN3)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("综合严密计算"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_RN3)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("综合严密计算"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

//        x1=0;
//        y1=y1+28;
//        w1=60;
//        memDC.DrawLabel(_("盾尾间隙"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//        x1+=w1;
//        w1=150;
//        figButton[ID_FIG_SET_GAP1].x=x1;
//        figButton[ID_FIG_SET_GAP1].y=y1;
//        figButton[ID_FIG_SET_GAP1].width=w1;
//        figButton[ID_FIG_SET_GAP1].height=h1;
//        if(measet.tgap==0)
//        {
//            if(motion1==ID_FIG_SET_GAP1)
//            {
//                memDC.SetPen(ipen[1]);
//                memDC.SetBrush(ibrush[0]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
//                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
//                memDC.SetBrush(ibrush[1]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
//            }
//            else
//            {
//                memDC.SetPen(ipen[2]);
//                memDC.SetBrush(ibrush[0]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
//                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
//                memDC.SetBrush(ibrush[2]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
//            }
//            memDC.SetFont(chs);
//            memDC.DrawLabel(_("手动输入"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//        }
//        else
//        {
//            if(motion1==ID_FIG_SET_GAP1)
//            {
//                memDC.SetPen(ipen[1]);
//                memDC.SetBrush(ibrush[0]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
//            }
//            else
//            {
//                memDC.SetPen(ipen[0]);
//                memDC.SetBrush(ibrush[0]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
//            }
//            memDC.SetFont(chs);
//            memDC.DrawLabel(_("手动输入"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//        }
//
//        x1+=w1;
//        figButton[ID_FIG_SET_GAP2].x=x1;
//        figButton[ID_FIG_SET_GAP2].y=y1;
//        figButton[ID_FIG_SET_GAP2].width=w1;
//        figButton[ID_FIG_SET_GAP2].height=h1;
//        if(measet.tgap==1)
//        {
//            if(motion1==ID_FIG_SET_GAP2)
//            {
//                memDC.SetPen(ipen[1]);
//                memDC.SetBrush(ibrush[0]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
//                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
//                memDC.SetBrush(ibrush[1]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
//            }
//            else
//            {
//                memDC.SetPen(ipen[2]);
//                memDC.SetBrush(ibrush[0]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
//                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
//                memDC.SetBrush(ibrush[2]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
//            }
//            memDC.SetFont(chs);
//            memDC.DrawLabel(_("自动测量"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//        }
//        else
//        {
//            if(motion1==ID_FIG_SET_GAP2)
//            {
//                memDC.SetPen(ipen[1]);
//                memDC.SetBrush(ibrush[0]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
//            }
//            else
//            {
//                memDC.SetPen(ipen[0]);
//                memDC.SetBrush(ibrush[0]);
//                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
//            }
//            memDC.SetFont(chs);
//            memDC.DrawLabel(_("自动测量"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//        }
//
//        x1=0;
//        y1=y1+28;
//        w1=60;
//        memDC.DrawLabel(_("掘进纠偏"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//        x1+=w1;
//        w1=150;
//        figButton[ID_FIG_SET_VDRIVING].x=x1;
//        figButton[ID_FIG_SET_VDRIVING].y=y1;
//        figButton[ID_FIG_SET_VDRIVING].width=w1;
//        figButton[ID_FIG_SET_VDRIVING].height=h1;
//        memDC.SetPen(wxPen(wxColor(158,158,158)));
//        if(measet.idrv==1)
//        {
//            if(motion1==ID_FIG_SET_VDRIVING)
//            {
//                memDC.SetPen(ipen[1]);
//                memDC.SetBrush(ibrush[1]);
//                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
//                memDC.SetTextForeground(icolor[1]);
//                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//                memDC.SetTextForeground(icolor[1]);
//                memDC.DrawLabel(_("计算并显示纠偏参数"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            }
//            else
//            {
//                memDC.SetPen(ipen[2]);
//                memDC.SetBrush(ibrush[2]);
//                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
//                memDC.SetTextForeground(icolor[2]);
//                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//                memDC.SetTextForeground(icolor[1]);
//                memDC.DrawLabel(_("计算并显示纠偏参数"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            }
//        }
//        else
//        {
//            if(motion1==ID_FIG_SET_VDRIVING)
//            {
//                memDC.SetPen(ipen[1]);
//                memDC.SetBrush(ibrush[1]);
//                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
//                memDC.SetTextForeground(icolor[0]);
//                memDC.DrawLabel(_("计算并显示纠偏参数"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            }
//            else
//            {
//                memDC.SetPen(ipen[0]);
//                memDC.SetBrush(ibrush[0]);
//                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
//                memDC.SetTextForeground(icolor[0]);
//                memDC.DrawLabel(_("计算并显示纠偏参数"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//            }
//        }

        x1=0;
        y1=y1+28;
        w1=90;
        memDC.DrawLabel(_("铰接计算方式"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_SET_SYMMETRY1].x=x1;
        figButton[ID_FIG_SET_SYMMETRY1].y=y1;
        figButton[ID_FIG_SET_SYMMETRY1].width=w1;
        figButton[ID_FIG_SET_SYMMETRY1].height=h1;
        if(measet.symtype==0)
        {
            if(motion1==ID_FIG_SET_SYMMETRY1)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("不对称"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_SYMMETRY1)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("不对称"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1+=w1;
        figButton[ID_FIG_SET_SYMMETRY2].x=x1;
        figButton[ID_FIG_SET_SYMMETRY2].y=y1;
        figButton[ID_FIG_SET_SYMMETRY2].width=w1;
        figButton[ID_FIG_SET_SYMMETRY2].height=h1;
        if(measet.symtype==1)
        {
            if(motion1==ID_FIG_SET_SYMMETRY2)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("对称"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_SYMMETRY2)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("对称"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1+=w1;
        figButton[ID_FIG_SET_SYMMETRY3].x=x1;
        figButton[ID_FIG_SET_SYMMETRY3].y=y1;
        figButton[ID_FIG_SET_SYMMETRY3].width=w1;
        figButton[ID_FIG_SET_SYMMETRY3].height=h1;
        if(measet.symtype==2)
        {
            if(motion1==ID_FIG_SET_SYMMETRY3)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("主动铰接(只有上左右)"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_SYMMETRY3)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("主动铰接(只有上左右)"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1=y1+28;
        w1=90;
        memDC.DrawLabel(_("后视检核"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_SET_CHECKBACK1].x=x1;
        figButton[ID_FIG_SET_CHECKBACK1].y=y1;
        figButton[ID_FIG_SET_CHECKBACK1].width=w1;
        figButton[ID_FIG_SET_CHECKBACK1].height=h1;
        if(measet.backflag==0)
        {
            if(motion1==ID_FIG_SET_CHECKBACK1)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("不进行"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_CHECKBACK1)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("不进行"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1+=w1;
        figButton[ID_FIG_SET_CHECKBACK2].x=x1;
        figButton[ID_FIG_SET_CHECKBACK2].y=y1;
        figButton[ID_FIG_SET_CHECKBACK2].width=w1;
        figButton[ID_FIG_SET_CHECKBACK2].height=h1;
        if(measet.backflag==1)
        {
            if(motion1==ID_FIG_SET_CHECKBACK2)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("进行"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_CHECKBACK2)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("进行"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1=y1+28;
        w1=90;
        memDC.DrawLabel(_("PLC读取方式"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_SET_PLCOPC].x=x1;
        figButton[ID_FIG_SET_PLCOPC].y=y1;
        figButton[ID_FIG_SET_PLCOPC].width=w1;
        figButton[ID_FIG_SET_PLCOPC].height=h1;
        if(measet.plctype==0)
        {
            if(motion1==ID_FIG_SET_PLCOPC)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("OPC"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_PLCOPC)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("OPC"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        x1+=w1;
        figButton[ID_FIG_SET_PLCWEB].x=x1;
        figButton[ID_FIG_SET_PLCWEB].y=y1;
        figButton[ID_FIG_SET_PLCWEB].width=w1;
        figButton[ID_FIG_SET_PLCWEB].height=h1;
        if(measet.plctype==1)
        {
            if(motion1==ID_FIG_SET_PLCWEB)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("WEB"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_PLCWEB)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("WEB"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }


        x1=0;
        y1=y1+35;
        w1=60;
        memDC.DrawLabel(_("功能保护"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        setLine4->SetSize(50,y1+12,w-50,-1);
        x1+=w1;
        w1=150;
        y1+=20;
        figButton[ID_FIG_SET_SEC_RUN].x=x1;
        figButton[ID_FIG_SET_SEC_RUN].y=y1;
        figButton[ID_FIG_SET_SEC_RUN].width=w1;
        figButton[ID_FIG_SET_SEC_RUN].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.prun==1)
        {
            if(motion1==ID_FIG_SET_SEC_RUN)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("开始测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("开始测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_RUN)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("开始测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("开始测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1+=w1;
        figButton[ID_FIG_SET_SEC_END].x=x1;
        figButton[ID_FIG_SET_SEC_END].y=y1;
        figButton[ID_FIG_SET_SEC_END].width=w1;
        figButton[ID_FIG_SET_SEC_END].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.pend==1)
        {
            if(motion1==ID_FIG_SET_SEC_END)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("停止测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("停止测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_END)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("停止测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("停止测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1+=w1;
        figButton[ID_FIG_SET_SEC_SAS].x=x1;
        figButton[ID_FIG_SET_SEC_SAS].y=y1;
        figButton[ID_FIG_SET_SEC_SAS].width=w1;
        figButton[ID_FIG_SET_SEC_SAS].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.psas==1)
        {
            if(motion1==ID_FIG_SET_SEC_SAS)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("管环选型"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("管环选型"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_SAS)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("管环选型"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("管环选型"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1=60;
        y1=y1+28;
        figButton[ID_FIG_SET_SEC_CHK].x=x1;
        figButton[ID_FIG_SET_SEC_CHK].y=y1;
        figButton[ID_FIG_SET_SEC_CHK].width=w1;
        figButton[ID_FIG_SET_SEC_CHK].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.pchk==1)
        {
            if(motion1==ID_FIG_SET_SEC_CHK)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("系统检核"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("系统检核"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_CHK)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("系统检核"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("系统检核"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1+=w1;
        figButton[ID_FIG_SET_SEC_QRY].x=x1;
        figButton[ID_FIG_SET_SEC_QRY].y=y1;
        figButton[ID_FIG_SET_SEC_QRY].width=w1;
        figButton[ID_FIG_SET_SEC_QRY].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.pqry==1)
        {
            if(motion1==ID_FIG_SET_SEC_QRY)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("数据查询"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("数据查询"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_QRY)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("数据查询"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("数据查询"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1+=w1;
        figButton[ID_FIG_SET_SEC_MAP].x=x1;
        figButton[ID_FIG_SET_SEC_MAP].y=y1;
        figButton[ID_FIG_SET_SEC_MAP].width=w1;
        figButton[ID_FIG_SET_SEC_MAP].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.pmap==1)
        {
            if(motion1==ID_FIG_SET_SEC_MAP)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("地质地物"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("地质地物"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_MAP)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("地质地物"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("地质地物"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1=60;
        y1+=28;
        figButton[ID_FIG_SET_SEC_SMR].x=x1;
        figButton[ID_FIG_SET_SEC_SMR].y=y1;
        figButton[ID_FIG_SET_SEC_SMR].width=w1;
        figButton[ID_FIG_SET_SEC_SMR].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.psmr==1)
        {
            if(motion1==ID_FIG_SET_SEC_SMR)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("管环沉降"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("管环沉降"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_SMR)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("管环沉降"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("管环沉降"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1+=w1;
        figButton[ID_FIG_SET_SEC_QUIT].x=x1;
        figButton[ID_FIG_SET_SEC_QUIT].y=y1;
        figButton[ID_FIG_SET_SEC_QUIT].width=w1;
        figButton[ID_FIG_SET_SEC_QUIT].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.pquit==1)
        {
            if(motion1==ID_FIG_SET_SEC_QUIT)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("退出系统"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("退出系统"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_QUIT)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("退出系统"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("退出系统"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionSetFun(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_SET_VIBRATION_ON].y && y<figButton[ID_FIG_SET_VIBRATION_ON].y+figButton[ID_FIG_SET_VIBRATION_ON].height)
    {
        if(x>figButton[ID_FIG_SET_VIBRATION_ON].x && x<figButton[ID_FIG_SET_VIBRATION_ON].x+figButton[ID_FIG_SET_VIBRATION_ON].width)
        {
            motion1=ID_FIG_SET_VIBRATION_ON;
        }
        else if(x>figButton[ID_FIG_SET_VIBRATION_YES].x && x<figButton[ID_FIG_SET_VIBRATION_YES].x+figButton[ID_FIG_SET_VIBRATION_YES].width)
        {
            motion1=ID_FIG_SET_VIBRATION_YES;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_STN_ACT0].y && y<figButton[ID_FIG_STN_ACT0].y+figButton[ID_FIG_STN_ACT0].height)
    {
        if(x>figButton[ID_FIG_STN_ACT0].x && x<figButton[ID_FIG_STN_ACT0].x+figButton[ID_FIG_STN_ACT0].width)
        {
            motion1=ID_FIG_STN_ACT0;
        }
        else if(x>figButton[ID_FIG_STN_ACT1].x && x<figButton[ID_FIG_STN_ACT1].x+figButton[ID_FIG_STN_ACT1].width)
        {
            motion1=ID_FIG_STN_ACT1;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_SET_END_END].y && y<figButton[ID_FIG_SET_END_END].y+figButton[ID_FIG_SET_END_END].height)
    {
        if(x>figButton[ID_FIG_SET_END_END].x && x<figButton[ID_FIG_SET_END_END].x+figButton[ID_FIG_SET_END_END].width)
        {
            motion1=ID_FIG_SET_END_END;
        }
        else if(x>figButton[ID_FIG_SET_END_RUN].x && x<figButton[ID_FIG_SET_END_RUN].x+figButton[ID_FIG_SET_END_RUN].width)
        {
            motion1=ID_FIG_SET_END_RUN;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_SET_RN1].y && y<figButton[ID_FIG_SET_RN1].y+figButton[ID_FIG_SET_RN1].height)
    {
        if(x>figButton[ID_FIG_SET_RN1].x && x<figButton[ID_FIG_SET_RN1].x+figButton[ID_FIG_SET_RN1].width)
        {
            motion1=ID_FIG_SET_RN1;
        }
        else if(x>figButton[ID_FIG_SET_RN2].x && x<figButton[ID_FIG_SET_RN2].x+figButton[ID_FIG_SET_RN2].width)
        {
            motion1=ID_FIG_SET_RN2;
        }
        else if(x>figButton[ID_FIG_SET_RN3].x && x<figButton[ID_FIG_SET_RN3].x+figButton[ID_FIG_SET_RN3].width)
        {
            motion1=ID_FIG_SET_RN3;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
//    else if(y>figButton[ID_FIG_SET_GAP1].y && y<figButton[ID_FIG_SET_GAP1].y+figButton[ID_FIG_SET_GAP1].height)
//    {
//        if(x>figButton[ID_FIG_SET_GAP1].x && x<figButton[ID_FIG_SET_GAP1].x+figButton[ID_FIG_SET_GAP1].width)
//        {
//            motion1=ID_FIG_SET_GAP1;
//        }
//        else if(x>figButton[ID_FIG_SET_GAP2].x && x<figButton[ID_FIG_SET_GAP2].x+figButton[ID_FIG_SET_GAP2].width)
//        {
//            motion1=ID_FIG_SET_GAP2;
//        }
//        else
//        {
//            motion1=ID_FIG_NONE;
//        }
//    }
//    else if(y>figButton[ID_FIG_SET_VDRIVING].y && y<figButton[ID_FIG_SET_VDRIVING].y+figButton[ID_FIG_SET_VDRIVING].height)
//    {
//        if(x>figButton[ID_FIG_SET_VDRIVING].x && x<figButton[ID_FIG_SET_VDRIVING].x+figButton[ID_FIG_SET_VDRIVING].width)
//        {
//            motion1=ID_FIG_SET_VDRIVING;
//        }
//        else
//        {
//            motion1=ID_FIG_NONE;
//        }
//    }
    else if(y>figButton[ID_FIG_SET_SYMMETRY1].y && y<figButton[ID_FIG_SET_SYMMETRY1].y+figButton[ID_FIG_SET_SYMMETRY1].height)
    {
        if(x>figButton[ID_FIG_SET_SYMMETRY1].x && x<figButton[ID_FIG_SET_SYMMETRY1].x+figButton[ID_FIG_SET_SYMMETRY1].width)
        {
            motion1=ID_FIG_SET_SYMMETRY1;
        }
        else if(x>figButton[ID_FIG_SET_SYMMETRY2].x && x<figButton[ID_FIG_SET_SYMMETRY2].x+figButton[ID_FIG_SET_SYMMETRY2].width)
        {
            motion1=ID_FIG_SET_SYMMETRY2;
        }
        else if(x>figButton[ID_FIG_SET_SYMMETRY3].x && x<figButton[ID_FIG_SET_SYMMETRY3].x+figButton[ID_FIG_SET_SYMMETRY3].width)
        {
            motion1=ID_FIG_SET_SYMMETRY3;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_SET_CHECKBACK1].y && y<figButton[ID_FIG_SET_CHECKBACK1].y+figButton[ID_FIG_SET_CHECKBACK1].height)
    {
        if(x>figButton[ID_FIG_SET_CHECKBACK1].x && x<figButton[ID_FIG_SET_CHECKBACK1].x+figButton[ID_FIG_SET_CHECKBACK1].width)
        {
            motion1=ID_FIG_SET_CHECKBACK1;
        }
        else if(x>figButton[ID_FIG_SET_CHECKBACK2].x && x<figButton[ID_FIG_SET_CHECKBACK2].x+figButton[ID_FIG_SET_CHECKBACK2].width)
        {
            motion1=ID_FIG_SET_CHECKBACK2;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_SET_PLCOPC].y && y<figButton[ID_FIG_SET_PLCOPC].y+figButton[ID_FIG_SET_PLCOPC].height)
    {
        if(x>figButton[ID_FIG_SET_PLCOPC].x && x<figButton[ID_FIG_SET_PLCOPC].x+figButton[ID_FIG_SET_PLCOPC].width)
        {
            motion1=ID_FIG_SET_PLCOPC;
        }
        else if(x>figButton[ID_FIG_SET_PLCWEB].x && x<figButton[ID_FIG_SET_PLCWEB].x+figButton[ID_FIG_SET_PLCWEB].width)
        {
            motion1=ID_FIG_SET_PLCWEB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_SET_SEC_RUN].y && y<figButton[ID_FIG_SET_SEC_RUN].y+figButton[ID_FIG_SET_SEC_RUN].height)
    {
        if(x>figButton[ID_FIG_SET_SEC_RUN].x && x<figButton[ID_FIG_SET_SEC_RUN].x+figButton[ID_FIG_SET_SEC_RUN].width)
        {
            motion1=ID_FIG_SET_SEC_RUN;
        }
        else if(x>figButton[ID_FIG_SET_SEC_END].x && x<figButton[ID_FIG_SET_SEC_END].x+figButton[ID_FIG_SET_SEC_END].width)
        {
            motion1=ID_FIG_SET_SEC_END;
        }
        else if(x>figButton[ID_FIG_SET_SEC_SAS].x && x<figButton[ID_FIG_SET_SEC_SAS].x+figButton[ID_FIG_SET_SEC_SAS].width)
        {
            motion1=ID_FIG_SET_SEC_SAS;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_SET_SEC_CHK].y && y<figButton[ID_FIG_SET_SEC_CHK].y+figButton[ID_FIG_SET_SEC_CHK].height)
    {
        if(x>figButton[ID_FIG_SET_SEC_CHK].x && x<figButton[ID_FIG_SET_SEC_CHK].x+figButton[ID_FIG_SET_SEC_CHK].width)
        {
            motion1=ID_FIG_SET_SEC_CHK;
        }
        else if(x>figButton[ID_FIG_SET_SEC_QRY].x && x<figButton[ID_FIG_SET_SEC_QRY].x+figButton[ID_FIG_SET_SEC_QRY].width)
        {
            motion1=ID_FIG_SET_SEC_QRY;
        }
        else if(x>figButton[ID_FIG_SET_SEC_MAP].x && x<figButton[ID_FIG_SET_SEC_MAP].x+figButton[ID_FIG_SET_SEC_MAP].width)
        {
            motion1=ID_FIG_SET_SEC_MAP;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_SET_SEC_SMR].y && y<figButton[ID_FIG_SET_SEC_SMR].y+figButton[ID_FIG_SET_SEC_SMR].height)
    {
        if(x>figButton[ID_FIG_SET_SEC_SMR].x && x<figButton[ID_FIG_SET_SEC_SMR].x+figButton[ID_FIG_SET_SEC_SMR].width)
        {
            motion1=ID_FIG_SET_SEC_SMR;
        }
        else if(x>figButton[ID_FIG_SET_SEC_QUIT].x && x<figButton[ID_FIG_SET_SEC_QUIT].x+figButton[ID_FIG_SET_SEC_QUIT].width)
        {
            motion1=ID_FIG_SET_SEC_QUIT;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    funPanel->Refresh();
}

void ConfigDlg::OnLeaveSetFun(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    funPanel->Refresh();
}

void ConfigDlg::OnClickSetFun(wxMouseEvent& event)
{
    if(motion1==ID_FIG_SET_VIBRATION_ON)
    {
        measet.vibration=0;
        ///设置常规测量模式,则需要停止震动模式判断线程
        mtg_close_aj(mtg);
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_VIBRATION_YES)
    {
        measet.vibration=1;
        ///设置震动模式,则需要开启震动模式判断线程
        if(!mtg->ajthread)
        {
            mtg_start_aj(mtg);
        }
        wxMessageBox(_("注意:\n切换为震动模式后必须在[盾构机停机]状态下进行[初始标定],否则不可掘进!"),_("警告"),wxOK);
//        {
//            wxMessageBox(_("OK"));
//        }
//        else
//        {
//            wxMessageBox(_("Cancel"));
//        }
        mtg->maj=mtg->maj0;
        mtg->maj.status=0;
        time(&mtg->maj.t4);
        if(sqlite_export_origin_aj(mtg,mtg->sqlitepath))
        {
            wxMessageBox(_("更新标定状态失败!"));
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_STN_ACT0)
    {
        measet.rstn=0;
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_STN_ACT1)
    {
        measet.rstn=1;
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_END_END)
    {
        measet.tsyn=0;
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_END_RUN)
    {
        measet.tsyn=1;
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_VIBRATION_ON)
    {
        if(measet.vibration==0)
        {
            measet.vibration=1;
        }
        else
        {
            measet.vibration=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_END_END)
    {
        if(measet.tsyn==0)
        {
            measet.tsyn=1;
        }
        else
        {
            measet.tsyn=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_RN1)
    {
        measet.rget=0;
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_RN2)
    {
        measet.rget=1;
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_RN3)
    {
        measet.rget=2;
        //settingModified=1;
        panelBottom->Refresh();
    }
//    else if(motion1==ID_FIG_SET_GAP1)
//    {
//        measet.tgap=0;
//        //settingModified=1;
//        panelBottom->Refresh();
//    }
//    else if(motion1==ID_FIG_SET_GAP2)
//    {
//        measet.tgap=1;
//        //settingModified=1;
//        panelBottom->Refresh();
//    }
//    else if(motion1==ID_FIG_SET_VDRIVING)
//    {
//        if(measet.idrv==0)
//        {
//            measet.idrv=1;
//        }
//        else
//        {
//            measet.idrv=0;
//        }
//        //settingModified=1;
//        panelBottom->Refresh();
//    }
    else if(motion1==ID_FIG_SET_SEC_RUN)
    {
        if(measet.prun==0)
        {
            measet.prun=1;
        }
        else
        {
            measet.prun=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_SEC_END)
    {
        if(measet.pend==0)
        {
            measet.pend=1;
        }
        else
        {
            measet.pend=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_SEC_SAS)
    {
        if(measet.psas==0)
        {
            measet.psas=1;
        }
        else
        {
            measet.psas=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_SEC_CHK)
    {
        if(measet.pchk==0)
        {
            measet.pchk=1;
        }
        else
        {
            measet.pchk=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_SEC_QRY)
    {
        if(measet.pqry==0)
        {
            measet.pqry=1;
        }
        else
        {
            measet.pqry=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_SEC_MAP)
    {
        if(measet.pmap==0)
        {
            measet.pmap=1;
        }
        else
        {
            measet.pmap=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_SEC_SMR)
    {
        if(measet.psmr==0)
        {
            measet.psmr=1;
        }
        else
        {
            measet.psmr=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_SEC_QUIT)
    {
        if(measet.pquit==0)
        {
            measet.pquit=1;
        }
        else
        {
            measet.pquit=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_SYMMETRY1)
    {
        measet.symtype=0;
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_SYMMETRY2)
    {
        measet.symtype=1;
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_SYMMETRY3)
    {
        measet.symtype=2;
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_CHECKBACK1)
    {
        measet.backflag=0;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_CHECKBACK2)
    {
        measet.backflag=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_PLCOPC)
    {
        measet.plctype=0;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_PLCWEB)
    {
        measet.plctype=1;
        panelBottom->Refresh();
    }
    funPanel->Refresh();
}

void ConfigDlg::OnPaintElement(wxPaintEvent& event)
{
    wxPaintDC dc(uiElementPanel);
    int w,h;
    uiElementPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont ens(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=1;
        w1=60;
        h1=23;
        memDC.DrawLabel(_("角度显示"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_UI_PER].x=x1;
        figButton[ID_FIG_UI_PER].y=y1;
        figButton[ID_FIG_UI_PER].width=w1;
        figButton[ID_FIG_UI_PER].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.unit==0)
        {
            if(motion1==ID_FIG_UI_PER)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("比例单位"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("(mm/m)"),wxRect(x1+radioBoxR1*2+57,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_UI_PER)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("比例单位"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("(mm/m)"),wxRect(x1+radioBoxR1*2+57,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1+=w1;
        w1=85;
        figButton[ID_FIG_UI_DEG].x=x1;
        figButton[ID_FIG_UI_DEG].y=y1;
        figButton[ID_FIG_UI_DEG].width=w1;
        figButton[ID_FIG_UI_DEG].height=h1;
        if(measet.unit==1)
        {
            if(motion1==ID_FIG_UI_DEG)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("度"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("( ° )"),wxRect(x1+radioBoxR1*2+20,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_UI_DEG)
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
            memDC.SetFont(chs);
            memDC.DrawLabel(_("度"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("( ° )"),wxRect(x1+radioBoxR1*2+20,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1=y1+28;
        w1=60;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("里程显示"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_UI_MILEAGE0].x=x1;
        figButton[ID_FIG_UI_MILEAGE0].y=y1;
        figButton[ID_FIG_UI_MILEAGE0].width=w1;
        figButton[ID_FIG_UI_MILEAGE0].height=h1;
        if(measet.vmileage==0)
        {
            if(motion1==ID_FIG_UI_MILEAGE0)
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
            memDC.DrawLabel(_("设计里程"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_UI_MILEAGE0)
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
            memDC.DrawLabel(_("设计里程"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        w1=85;
        figButton[ID_FIG_UI_MILEAGE1].x=x1;
        figButton[ID_FIG_UI_MILEAGE1].y=y1;
        figButton[ID_FIG_UI_MILEAGE1].width=w1;
        figButton[ID_FIG_UI_MILEAGE1].height=h1;
        if(measet.vmileage==1)
        {
            if(motion1==ID_FIG_UI_MILEAGE1)
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
            memDC.DrawLabel(_("实际里程"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_UI_MILEAGE1)
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
            memDC.DrawLabel(_("实际里程"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1=y1+28;
        w1=60;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("前端位置"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_SET_HEAD1].x=x1;
        figButton[ID_FIG_SET_HEAD1].y=y1;
        figButton[ID_FIG_SET_HEAD1].width=w1;
        figButton[ID_FIG_SET_HEAD1].height=h1;
        if(measet.head==0)
        {
            if(motion1==ID_FIG_SET_HEAD1)
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
            memDC.DrawLabel(_("切口位置"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_HEAD1)
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
            memDC.DrawLabel(_("切口位置"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        w1=85;
        figButton[ID_FIG_SET_HEAD2].x=x1;
        figButton[ID_FIG_SET_HEAD2].y=y1;
        figButton[ID_FIG_SET_HEAD2].width=w1;
        figButton[ID_FIG_SET_HEAD2].height=h1;
        if(measet.head==1)
        {
            if(motion1==ID_FIG_SET_HEAD2)
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
            memDC.DrawLabel(_("刀盘位置"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_HEAD2)
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
            memDC.DrawLabel(_("刀盘位置"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1=y1+28;
        w1=60;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("姿态图示"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_SET_FIG3D].x=x1;
        figButton[ID_FIG_SET_FIG3D].y=y1;
        figButton[ID_FIG_SET_FIG3D].width=w1;
        figButton[ID_FIG_SET_FIG3D].height=h1;
        if(measet.tbm3d==0)
        {
            if(motion1==ID_FIG_SET_FIG3D)
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
            memDC.DrawLabel(_("三维视图"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_FIG3D)
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
            memDC.DrawLabel(_("三维视图"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        w1=85;
        figButton[ID_FIG_SET_FIG2D].x=x1;
        figButton[ID_FIG_SET_FIG2D].y=y1;
        figButton[ID_FIG_SET_FIG2D].width=w1;
        figButton[ID_FIG_SET_FIG2D].height=h1;
        if(measet.tbm3d==1)
        {
            if(motion1==ID_FIG_SET_FIG2D)
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
            memDC.DrawLabel(_("十字视图"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_SET_FIG2D)
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
            memDC.DrawLabel(_("十字视图"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1=y1+28;
        w1=60;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("偏航显示"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_UI_HEADING0].x=x1;
        figButton[ID_FIG_UI_HEADING0].y=y1;
        figButton[ID_FIG_UI_HEADING0].width=w1;
        figButton[ID_FIG_UI_HEADING0].height=h1;
        if(measet.trend==0)
        {
            if(motion1==ID_FIG_UI_HEADING0)
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
            memDC.DrawLabel(_("基于轴线"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_UI_HEADING0)
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
            memDC.DrawLabel(_("基于轴线"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        w1=85;
        figButton[ID_FIG_UI_HEADING1].x=x1;
        figButton[ID_FIG_UI_HEADING1].y=y1;
        figButton[ID_FIG_UI_HEADING1].width=w1;
        figButton[ID_FIG_UI_HEADING1].height=h1;
        if(measet.trend==1)
        {
            if(motion1==ID_FIG_UI_HEADING1)
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
            memDC.DrawLabel(_("基于切线"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_UI_HEADING1)
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
            memDC.DrawLabel(_("基于切线"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=60;
        y1=y1+25;
        w1=130;
        h1=h-y1-31;
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        int xc,yc,x2,y2,x3,y3;
        wxPoint lines[60];
        xc=x1+w1/2;
        yc=y1+h1/2+w1;
        for(int i=240;i<300;i++)
        {
            lines[i-240].x=xc+w1*cos(i*PI/180.0);
            lines[i-240].y=yc+w1*sin(i*PI/180.0);
        }

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawLines(60,lines);
        x2=lines[15].x;
        y2=lines[15].y-5;
        x3=lines[45].x;
        y3=lines[45].y-15;
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        memDC.DrawLine(x2,y2,x3,y3);
        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.DrawLine(lines[15],lines[45]);
        memDC.SetPen(wxPen(wxColor(0,0,255),1,wxDOT));
        memDC.DrawLine(lines[15].x,lines[15].y-5,lines[45].x,lines[45].y-5);

        x1=x1+150;
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        xc=x1+w1/2;
        yc=y1+h1/2+w1;
        for(int i=240;i<300;i++)
        {
            lines[i-240].x=xc+w1*cos(i*PI/180.0);
            lines[i-240].y=yc+w1*sin(i*PI/180.0);
        }

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawLines(60,lines);
        x2=lines[15].x;
        y2=lines[15].y-5;
        x3=lines[45].x;
        y3=lines[45].y-15;
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        memDC.DrawLine(x2,y2,x3,y3);

        x2=lines[45].x-w1/4;
        y2=lines[45].y-w1/4*tan(PI/12);
        x3=lines[45].x+w1/4;
        y3=lines[45].y+w1/4*tan(PI/12);
        memDC.DrawLine(lines[45].x,lines[45].y-5,lines[45].x,lines[45].y+5);
        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.DrawLine(x2,y2,x3,y3);

        x2=lines[15].x;
        y2=lines[15].y-5;
        x3=x2+w1/2;
        y3=y2+w1/2*tan(PI/12);
        memDC.SetPen(wxPen(wxColor(0,0,255),1,wxDOT));
        memDC.DrawLine(x2,y2,x3,y3);

        ///20210317 ws add 盾尾铰接是否显示盾尾姿态选项
        x1=60;
        y1=y1+50;
        w1=150;
        h1=23;
        figButton[ID_FIG_UI_TAILAPPLY].x=x1;
        figButton[ID_FIG_UI_TAILAPPLY].y=y1;
        figButton[ID_FIG_UI_TAILAPPLY].width=w1;
        figButton[ID_FIG_UI_TAILAPPLY].height=h1;
        if(measet.tailapply==0)
        {
            if(motion1==ID_FIG_UI_TAILAPPLY)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾尾铰接模式显示盾尾偏航数据"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾尾铰接模式显示盾尾偏航数据"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_UI_TAILAPPLY)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾尾铰接模式显示盾尾偏航数据"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("盾尾铰接模式显示盾尾偏航数据"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionElement(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_UI_DEG].y && y<figButton[ID_FIG_UI_DEG].y+figButton[ID_FIG_UI_DEG].height)
    {
        if(x>figButton[ID_FIG_UI_DEG].x && x<figButton[ID_FIG_UI_DEG].x+figButton[ID_FIG_UI_DEG].width)
        {
            motion1=ID_FIG_UI_DEG;
        }
        else if(x>figButton[ID_FIG_UI_PER].x && x<figButton[ID_FIG_UI_PER].x+figButton[ID_FIG_UI_PER].width)
        {
            motion1=ID_FIG_UI_PER;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_UI_MILEAGE0].y && y<figButton[ID_FIG_UI_MILEAGE0].y+figButton[ID_FIG_UI_MILEAGE0].height)
    {
        if(x>figButton[ID_FIG_UI_MILEAGE0].x && x<figButton[ID_FIG_UI_MILEAGE0].x+figButton[ID_FIG_UI_MILEAGE0].width)
        {
            motion1=ID_FIG_UI_MILEAGE0;
        }
        else if(x>figButton[ID_FIG_UI_MILEAGE1].x && x<figButton[ID_FIG_UI_MILEAGE1].x+figButton[ID_FIG_UI_MILEAGE1].width)
        {
            motion1=ID_FIG_UI_MILEAGE1;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_SET_HEAD1].y && y<figButton[ID_FIG_SET_HEAD1].y+figButton[ID_FIG_SET_HEAD1].height)
    {
        if(x>figButton[ID_FIG_SET_HEAD1].x && x<figButton[ID_FIG_SET_HEAD1].x+figButton[ID_FIG_SET_HEAD1].width)
        {
            motion1=ID_FIG_SET_HEAD1;
        }
        else if(x>figButton[ID_FIG_SET_HEAD2].x && x<figButton[ID_FIG_SET_HEAD2].x+figButton[ID_FIG_SET_HEAD2].width)
        {
            motion1=ID_FIG_SET_HEAD2;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_SET_FIG3D].y && y<figButton[ID_FIG_SET_FIG3D].y+figButton[ID_FIG_SET_FIG3D].height)
    {
        if(x>figButton[ID_FIG_SET_FIG3D].x && x<figButton[ID_FIG_SET_FIG3D].x+figButton[ID_FIG_SET_FIG3D].width)
        {
            motion1=ID_FIG_SET_FIG3D;
        }
        else if(x>figButton[ID_FIG_SET_FIG2D].x && x<figButton[ID_FIG_SET_FIG2D].x+figButton[ID_FIG_SET_FIG2D].width)
        {
            motion1=ID_FIG_SET_FIG2D;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_UI_HEADING0].y && y<figButton[ID_FIG_UI_HEADING0].y+figButton[ID_FIG_UI_HEADING0].height)
    {
        if(x>figButton[ID_FIG_UI_HEADING0].x && x<figButton[ID_FIG_UI_HEADING0].x+figButton[ID_FIG_UI_HEADING0].width)
        {
            motion1=ID_FIG_UI_HEADING0;
        }
        else if(x>figButton[ID_FIG_UI_HEADING1].x && x<figButton[ID_FIG_UI_HEADING1].x+figButton[ID_FIG_UI_HEADING1].width)
        {
            motion1=ID_FIG_UI_HEADING1;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_UI_TAILAPPLY].y && y<figButton[ID_FIG_UI_TAILAPPLY].y+figButton[ID_FIG_UI_TAILAPPLY].height)
    {
        if(x>figButton[ID_FIG_UI_TAILAPPLY].x && x<figButton[ID_FIG_UI_TAILAPPLY].x+figButton[ID_FIG_UI_TAILAPPLY].width)
        {
            motion1=ID_FIG_UI_TAILAPPLY;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    uiElementPanel->Refresh();
}

void ConfigDlg::OnLeaveElement(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    uiElementPanel->Refresh();
}

void ConfigDlg::OnClickElement(wxMouseEvent& event)
{
    if(motion1==ID_FIG_UI_PER)
    {
        if(measet.unit!=0)
        {
            measet.unit=0;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_UI_DEG)
    {
        if(measet.unit!=1)
        {
            measet.unit=1;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_UI_MILEAGE0)
    {
        if(measet.vmileage!=0)
        {
            measet.vmileage=0;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_UI_MILEAGE1)
    {
        if(measet.vmileage!=1)
        {
            measet.vmileage=1;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_SET_HEAD1)
    {
        if(measet.head!=0)
        {
            measet.head=0;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_SET_HEAD2)
    {
        if(measet.head!=1)
        {
            measet.head=1;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_UI_HEADING0)
    {
        if(measet.trend!=0)
        {
            measet.trend=0;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_UI_HEADING1)
    {
        if(measet.trend!=1)
        {
            measet.trend=1;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_SET_FIG3D)
    {
        if(measet.tbm3d!=0)
        {
            measet.tbm3d=0;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_SET_FIG2D)
    {
        if(measet.tbm3d!=1)
        {
            measet.tbm3d=1;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_UI_TAILAPPLY)
    {
        if(measet.tailapply==0)
        {
            measet.tailapply=1;
        }
        else
        {
            measet.tailapply=0;
        }
        panelBottom->Refresh();
    }
    uiElementPanel->Refresh();
}

void ConfigDlg::OnPaintCaution(wxPaintEvent& event)
{
    wxPaintDC dc(uiCautionPanel);
    int w,h;
    uiCautionPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont ens(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=1;
        w1=60;
        h1=23;
        memDC.DrawLabel(_("偏差超限"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_DEV_CAUTION].x=x1;
        figButton[ID_FIG_DEV_CAUTION].y=y1;
        figButton[ID_FIG_DEV_CAUTION].width=w1;
        figButton[ID_FIG_DEV_CAUTION].height=h1;
        if(measet.povr==0)
        {
            if(motion1==ID_FIG_DEV_CAUTION)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("红色字体警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("红色字体警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_DEV_CAUTION)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("红色字体警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("红色字体警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1=0;
        y1=y1+28;
        w1=60;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("时间超限"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_TIME_CAUTION].x=x1;
        figButton[ID_FIG_TIME_CAUTION].y=y1;
        figButton[ID_FIG_TIME_CAUTION].width=w1;
        figButton[ID_FIG_TIME_CAUTION].height=h1;
        if(measet.tovr==0)
        {
            if(motion1==ID_FIG_TIME_CAUTION)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_TIME_CAUTION)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1=0;
        y1=y1+28;
        w1=60;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("后视超限"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_STN_CAUTION].x=x1;
        figButton[ID_FIG_STN_CAUTION].y=y1;
        figButton[ID_FIG_STN_CAUTION].width=w1;
        figButton[ID_FIG_STN_CAUTION].height=h1;
        if(measet.bovr==0)
        {
            if(motion1==ID_FIG_STN_CAUTION)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("停止且主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("停止且主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_STN_CAUTION)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("停止且主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("停止且主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1=0;
        y1=y1+28;
        w1=60;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("警示信息"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_INFO_ERR].x=x1;
        figButton[ID_FIG_INFO_ERR].y=y1;
        figButton[ID_FIG_INFO_ERR].width=w1;
        figButton[ID_FIG_INFO_ERR].height=h1;
        if(measet.toEr==0)
        {
            if(motion1==ID_FIG_INFO_ERR)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("设为系统错误警示信息"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("设为系统错误警示信息"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_INFO_ERR)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("设为系统错误警示信息"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("设为系统错误警示信息"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionCaution(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_DEV_CAUTION].y && y<figButton[ID_FIG_DEV_CAUTION].y+figButton[ID_FIG_DEV_CAUTION].height)
    {
        if(x>figButton[ID_FIG_DEV_CAUTION].x && x<figButton[ID_FIG_DEV_CAUTION].x+figButton[ID_FIG_DEV_CAUTION].width)
        {
            motion1=ID_FIG_DEV_CAUTION;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_TIME_CAUTION].y && y<figButton[ID_FIG_TIME_CAUTION].y+figButton[ID_FIG_TIME_CAUTION].height)
    {
        if(x>figButton[ID_FIG_TIME_CAUTION].x && x<figButton[ID_FIG_TIME_CAUTION].x+figButton[ID_FIG_TIME_CAUTION].width)
        {
            motion1=ID_FIG_TIME_CAUTION;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_STN_CAUTION].y && y<figButton[ID_FIG_STN_CAUTION].y+figButton[ID_FIG_STN_CAUTION].height)
    {
        if(x>figButton[ID_FIG_STN_CAUTION].x && x<figButton[ID_FIG_STN_CAUTION].x+figButton[ID_FIG_STN_CAUTION].width)
        {
            motion1=ID_FIG_STN_CAUTION;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(y>figButton[ID_FIG_INFO_ERR].y && y<figButton[ID_FIG_INFO_ERR].y+figButton[ID_FIG_INFO_ERR].height)
    {
        if(x>figButton[ID_FIG_INFO_ERR].x && x<figButton[ID_FIG_INFO_ERR].x+figButton[ID_FIG_INFO_ERR].width)
        {
            motion1=ID_FIG_INFO_ERR;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    uiCautionPanel->Refresh();
}

void ConfigDlg::OnLeaveCaution(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    uiCautionPanel->Refresh();
}

void ConfigDlg::OnClickCaution(wxMouseEvent& event)
{
    if(motion1==ID_FIG_DEV_CAUTION)
    {
        if(measet.povr==0)
        {
            measet.povr=1;
        }
        else
        {
            measet.povr=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_TIME_CAUTION)
    {
        if(measet.tovr==0)
        {
            measet.tovr=1;
        }
        else
        {
            measet.tovr=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_STN_CAUTION)
    {
        if(measet.bovr==0)
        {
            measet.bovr=1;
        }
        else
        {
            measet.bovr=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_INFO_ERR)
    {
        if(measet.toEr==0)
        {
            measet.toEr=1;
        }
        else
        {
            measet.toEr=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    uiCautionPanel->Refresh();
}

void ConfigDlg::OnPaintUserButton(wxPaintEvent& event)
{
    wxPaintDC dc(userButtonPanel);
    int w,h;
    userButtonPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=25;
        figButton[ID_FIG_USER_ADD].x=x1;
        figButton[ID_FIG_USER_ADD].y=y1;
        figButton[ID_FIG_USER_ADD].width=w1;
        figButton[ID_FIG_USER_ADD].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(motion1==ID_FIG_USER_ADD)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("添加"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+7;
        figButton[ID_FIG_USER_EDI].x=x1;
        figButton[ID_FIG_USER_EDI].y=y1;
        figButton[ID_FIG_USER_EDI].width=w1;
        figButton[ID_FIG_USER_EDI].height=h1;
        if(motion1==ID_FIG_USER_EDI)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("编辑"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+7;
        figButton[ID_FIG_USER_DEL].x=x1;
        figButton[ID_FIG_USER_DEL].y=y1;
        figButton[ID_FIG_USER_DEL].width=w1;
        figButton[ID_FIG_USER_DEL].height=h1;
        if(motion1==ID_FIG_USER_DEL)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("删除"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionUserButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_USER_ADD].x && x<figButton[ID_FIG_USER_ADD].x+figButton[ID_FIG_USER_ADD].width)
    {
        if(y>figButton[ID_FIG_USER_ADD].y && y<figButton[ID_FIG_USER_ADD].y+figButton[ID_FIG_USER_ADD].height)
        {
            motion1=ID_FIG_USER_ADD;
        }
        else if(y>figButton[ID_FIG_USER_EDI].y && y<figButton[ID_FIG_USER_EDI].y+figButton[ID_FIG_USER_EDI].height)
        {
            motion1=ID_FIG_USER_EDI;
        }
        else if(y>figButton[ID_FIG_USER_DEL].y && y<figButton[ID_FIG_USER_DEL].y+figButton[ID_FIG_USER_DEL].height)
        {
            motion1=ID_FIG_USER_DEL;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    userButtonPanel->Refresh();
}

void ConfigDlg::OnLeaveUserButton(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    userButtonPanel->Refresh();
}

void ConfigDlg::OnClickUserButton(wxMouseEvent& event)
{
    if(motion1==ID_FIG_USER_ADD)
    {
        //if(opLevel>0)
        if(mtg->onLine>0)
        {
            WriteMsg(_("无操作权限"),1);
            return;
        }

        if(nuser>=49)
        {
            WriteMsg(_("最多能添加50个用户，请检查！"),1);
            return;
        }
        UserEditDlg dlg(this);
        dlg.Center();
        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str=dlg.Name->GetValue();
            strncpy(user[nuser].name,str.mb_str(wxConvUTF8),64);
            str=dlg.Password->GetValue();
            int i=0;
            wxString str1;
            for(i=0;i<nuser;i++)
            {
                str1=wxString(user[i].password,wxConvUTF8);
                if(str.Cmp(str1)==0) break;
            }

            if(i<nuser)
            {
                WriteMsg(_("权限密码已存在，请重新设置！"),1);
                return;
            }
            WriteMsg(_("设置成功！"),0);
            strncpy(user[nuser].password,str.mb_str(wxConvUTF8),64);
            user[nuser].level=1;
            nuser++;
            UpdateUsers();
            userModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_USER_EDI)
    {
        int n = userList->GetFirstSelected();
        int Num = userList->GetItemCount();

        if(n<0 || n>Num-1) return;

        if(mtg->onLine>0 && mtg->onLine!=n)
        {
            WriteMsg(_("无操作权限"),1);
            return;
        }

        UserEditDlg dlg(this);
        dlg.Center();
        wxString str;
        str=wxString(user[n].name,wxConvUTF8);
        dlg.Name->SetValue(str);
        str=wxString(user[n].password,wxConvUTF8);
        dlg.Password->SetValue(str);
        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str=dlg.Name->GetValue();
            strncpy(user[n].name,str.mb_str(wxConvUTF8),64);
            str=dlg.Password->GetValue();
            int i=0;
            wxString str1;
            for(i=0;i<nuser;i++)
            {
                str1=wxString(user[i].password,wxConvUTF8);
                if(str.Cmp(str1)==0) break;
            }

            if(i<nuser)
            {
                WriteMsg(_("权限密码已存在，请重新编辑！"),1);
                return;
            }
            strncpy(user[n].password,str.mb_str(wxConvUTF8),64);
            userModified=1;
            WriteMsg(_("编辑成功！"),0);
            panelBottom->Refresh();
            UpdateUsers();
        }
    }
    else if(motion1==ID_FIG_USER_DEL)
    {
        int n = userList->GetFirstSelected();
        int Num = userList->GetItemCount();
        if(n<0 || n>Num-1) return;
        if(user[n].level==0)
        {
            WriteMsg(_("不能删除管理员"),1);
            return;
        }

        nuser--;
        for(int i=n;i<nuser;i++)
        {
            user[i]=user[i+1];
        }
        UpdateUsers();
        if(n<nuser)
        {
            userList->Select(n);
            userList->EnsureVisible(n);
        }
        else if(n>0)
        {
            userList->Select(n-1);
            userList->EnsureVisible(n-1);
        }
    }
}

void ConfigDlg::OnPaintUserGrid(wxPaintEvent& event)
{
    wxPaintDC dc(userGridPanel);
    int w,h;
    userGridPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=24;
        memDC.DrawLine(x1,y1+h1,w,y1+h1);

        w1=userList->GetColumnWidth(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=userList->GetColumnWidth(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("用户名"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=userList->GetColumnWidth(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("权限密码"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=userList->GetColumnWidth(3);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("用户权限"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintLanguage(wxPaintEvent& event)
{
    wxPaintDC dc(langButton);
    int w,h;
    langButton->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);


        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=65;
        h1=25;
        memDC.DrawLabel(_("系统语言"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;

        x1=x1+1;
        y1=1;
        w1=80;
        h1=h-2;
        figButton[ID_FIG_LANG_SIMP].x=x1;
        figButton[ID_FIG_LANG_SIMP].y=y1;
        figButton[ID_FIG_LANG_SIMP].width=w1;
        figButton[ID_FIG_LANG_SIMP].height=h1;
        if(measet.lang==0)
        {
            if(motion1==ID_FIG_LANG_SIMP)
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
            memDC.DrawLabel(_("简体中文"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_LANG_SIMP)
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
            memDC.DrawLabel(_("简体中文"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }


        x1=x1+w1+1;
        figButton[ID_FIG_LANG_TRAD].x=x1;
        figButton[ID_FIG_LANG_TRAD].y=y1;
        figButton[ID_FIG_LANG_TRAD].width=w1;
        figButton[ID_FIG_LANG_TRAD].height=h1;
        if(measet.lang==1)
        {
            if(motion1==ID_FIG_LANG_TRAD)
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
            memDC.DrawLabel(_("繁体中文"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_LANG_TRAD)
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
            memDC.DrawLabel(_("繁体中文"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1+1;
        figButton[ID_FIG_LANG_ENG].x=x1;
        figButton[ID_FIG_LANG_ENG].y=y1;
        figButton[ID_FIG_LANG_ENG].width=w1;
        figButton[ID_FIG_LANG_ENG].height=h1;
        if(measet.lang==2)
        {
            if(motion1==ID_FIG_LANG_ENG)
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
            memDC.DrawLabel(_("英语"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion1==ID_FIG_LANG_ENG)
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
            memDC.DrawLabel(_("英语"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionLanguage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_LANG_SIMP].y && y<figButton[ID_FIG_LANG_SIMP].y+figButton[ID_FIG_LANG_SIMP].height)
    {
        if(x>figButton[ID_FIG_LANG_SIMP].x && x<figButton[ID_FIG_LANG_SIMP].x+figButton[ID_FIG_LANG_SIMP].width)
        {
            motion1=ID_FIG_LANG_SIMP;
        }
        else if(x>figButton[ID_FIG_LANG_TRAD].x && x<figButton[ID_FIG_LANG_TRAD].x+figButton[ID_FIG_LANG_TRAD].width)
        {
            motion1=ID_FIG_LANG_TRAD;
        }
        else if(x>figButton[ID_FIG_LANG_ENG].x && x<figButton[ID_FIG_LANG_ENG].x+figButton[ID_FIG_LANG_ENG].width)
        {
            motion1=ID_FIG_LANG_ENG;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    langButton->Refresh();
}

void ConfigDlg::OnLeaveLanguage(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    langButton->Refresh();
}

void ConfigDlg::OnClickLanguage(wxMouseEvent& event)
{
    if(motion1==ID_FIG_LANG_SIMP)
    {
        if(measet.lang!=0)
        {
            measet.lang=0;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_LANG_TRAD)
    {
        if(measet.lang!=1)
        {
            measet.lang=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_LANG_ENG)
    {
        if(measet.lang!=2)
        {
            measet.lang=2;
            panelBottom->Refresh();
        }
    }
    langButton->Refresh();
}

void ConfigDlg::OnListBlockSelect(wxListEvent& event)
{
    blkFigPanel->Refresh();
    int n = blockList->GetFirstSelected();
    int Num = blockList->GetItemCount();
    if(n<0 || n>Num-1) return;

}

void ConfigDlg::OnListBlockActivated(wxListEvent& event)
{
    int n = blockList->GetFirstSelected();
    int Num = blockList->GetItemCount();

    if(n<0 || n>Num-1) return;

    BlockDlg dlg(this);
    dlg.Center();
    wxString str;
    str=wxString(blocks[n].name,wxConvUTF8);
    dlg.blkName->SetValue(str);
    str=wxString::Format(_("%.2f"),blocks[n].angle*180.0/PI);
    dlg.Angle->SetValue(str);
    if(dlg.ShowModal()==wxID_OK)
    {
        wxString str=dlg.blkName->GetValue();
        strncpy(blocks[n].name,str.mb_str(wxConvUTF8),64);
        dlg.Angle->GetValue().ToDouble(&blocks[n].angle);
        blocks[n].angle=blocks[n].angle/180.0*PI;
        panelBottom->Refresh();
        UpdateBlocks();
    }

}

void ConfigDlg::OnListBlockDeselect(wxListEvent& event)
{
    blkFigPanel->Refresh();

}

void ConfigDlg::OnListJackSelect(wxListEvent& event)
{
    int sel=jackList->GetFirstSelected();
    if(sel<0 || sel>=10) return;
    tbmStaticText7->SetLabel(ajname[sel]+_("油缸"));
    if(jackType==ID_FIG_TBM_MAIN_JACK)
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.aj[sel]*180.0/PI));
    else if(jackType==ID_FIG_TBM_TAIL_JACK)
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.bj[sel]*180.0/PI));
    else if(jackType==ID_FIG_TBM_HEAD_JACK)
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.fj[sel]*180.0/PI));
    panelJackfig->Refresh();
}

void ConfigDlg::OnListKeyActivated(wxListEvent& event)
{
    int n = keyList->GetFirstSelected();
    int Num = keyList->GetItemCount();

    if(n<0 || n>Num-1) return;
    KeyDlg dlg(this);
    dlg.Center();
    dlg.keyName->SetValue(wxString(keys[n].name,wxConvUTF8));
    dlg.mile1->SetValue(wxString::Format(_("%.3f"),keys[n].mile1));
    dlg.mile2->SetValue(wxString::Format(_("%.3f"),keys[n].mile2));
    dlg.a2z=prj.a2z;
    dlg.p1=prj.mile1;
    dlg.p2=prj.mile2;
    dlg.tip=prj.tip;
    if(dlg.ShowModal()==wxID_OK)
    {
        strncpy(keys[n].name,dlg.keyName->GetValue().mb_str(wxConvUTF8),64);
        dlg.mile1->GetValue().ToDouble(&keys[n].mile1);
        dlg.mile2->GetValue().ToDouble(&keys[n].mile2);
        if(keys[n].mile2==0) keys[n].mile2=keys[n].mile1;
        WriteMsg(_("成功编辑关键区域"),0);
        UpdateKeys();
        keyList->Select(n);
        panelBottom->Refresh();
    }
}

void ConfigDlg::OnListUserActivated(wxListEvent& event)
{
    int n = userList->GetFirstSelected();
    int Num = userList->GetItemCount();

    if(n<0 || n>Num-1) return;

    UserEditDlg dlg(this);
    dlg.Center();
    wxString str;
    str=wxString(user[n].name,wxConvUTF8);
    dlg.Name->SetValue(str);
    str=wxString(user[n].password,wxConvUTF8);
    dlg.Password->SetValue(str);
    if(dlg.ShowModal()==wxID_OK)
    {
        if(mtg->onLine>0 && mtg->onLine!=n)
        {
            WriteMsg(_("无操作权限"),1);
            return;
        }

        wxString str=dlg.Name->GetValue();
        strncpy(user[n].name,str.mb_str(wxConvUTF8),64);
        str=dlg.Password->GetValue();
        strncpy(user[n].password,str.mb_str(wxConvUTF8),64);
        userModified=1;
        panelBottom->Refresh();
        UpdateUsers();
    }

}

void ConfigDlg::UpdateBlocks()
{
    blockList->DeleteAllItems();

    for(int i=0; i<nblk; i++)
    {
        blockList->InsertItem(i,wxString::Format(_("%d"),i+1));
        blockList->SetItem(i,1,wxString(blocks[i].name,wxConvUTF8));
        blockList->SetItem(i,2,wxString::Format(_("%.2f"),blocks[i].angle*180/PI));
    }
}

void ConfigDlg::UpdateJack()
{
    jackList->DeleteAllItems();
    if(jackType==ID_FIG_TBM_MAIN_JACK)
    {
        for(int i=0; i<tbm.naj; i++)
        {
            if(i>=10) return;
            jackList->InsertItem(i,_(""));
            jackList->SetItem(i,1,wxString::Format(_("%d"),i+1));
            jackList->SetItem(i,2,ajname[i]);
            jackList->SetItem(i,3,wxString::Format(_("%.4f"),tbm.aj[i]*180.0/PI));
        }
    }
    else if(jackType==ID_FIG_TBM_TAIL_JACK)
    {
        for(int i=0; i<tbm.nbj; i++)
        {
            if(i>=10) return;
            jackList->InsertItem(i,_(""));
            jackList->SetItem(i,1,wxString::Format(_("%d"),i+1));
            jackList->SetItem(i,2,ajname[i]);
            jackList->SetItem(i,3,wxString::Format(_("%.4f"),tbm.bj[i]*180.0/PI));
        }
    }
    else if(jackType==ID_FIG_TBM_HEAD_JACK)
    {
        for(int i=0; i<tbm.nfj; i++)
        {
            if(i>=10) return;
            jackList->InsertItem(i,_(""));
            jackList->SetItem(i,1,wxString::Format(_("%d"),i+1));
            jackList->SetItem(i,2,ajname[i]);
            jackList->SetItem(i,3,wxString::Format(_("%.4f"),tbm.fj[i]*180.0/PI));
        }
    }
}

void ConfigDlg::UpdateKeys()
{
    keyList->DeleteAllItems();

    for(int i=0; i<nks; i++)
    {
        keyList->InsertItem(i,wxString::Format(_("%d"),i+1));
        keyList->SetItem(i,1,wxString(keys[i].name,wxConvUTF8));
        keyList->SetItem(i,2,wxString::Format(_("%.4f"),keys[i].mile1));
        keyList->SetItem(i,3,wxString::Format(_("%.4f"),keys[i].mile2));
    }
}

void ConfigDlg::UpdateOrigin()
{
    wxString str1,str2;
    double dbval;
    ///初始姿态
    if(tbm.type==0)
    {
        str1=wxString::Format(_("%.4f"),m1.head[0]);
        m1Head1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.head[1]);
        m1Head2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.head[2]);
        m1Head3->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.tail[0]);
        m1Tail1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.tail[1]);
        m1Tail2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.tail[2]);
        m1Tail3->SetValue(str1);
    }
    else if(tbm.type==1)
    {
        str1=wxString::Format(_("%.4f"),m1.head[0]);
        m1Head1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.head[1]);
        m1Head2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.head[2]);
        m1Head3->SetValue(str1);
        m1Tail1->Enable(false);
        m1Tail2->Enable(false);
        m1Tail3->Enable(false);
    }
    else
    {
        m1Head1->Enable(false);
        m1Head2->Enable(false);
        m1Head3->Enable(false);
        m1Tail1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.tail[1]);
        m1Tail2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.tail[2]);
        m1Tail3->SetValue(str1);
    }

    dbval=m1.inc1[0]*PI/180.0;
    str1=wxString::Format(_("%.5f"),rad2dms(dbval));
    m1Roll->SetValue(str1);
    CalMeasurement();
    str1=wxString::Format(_("%.4f"),m1.prism[0]);
    m1Prism1->SetValue(str1);
    str1=wxString::Format(_("%.4f"),m1.prism[1]);
    m1Prism2->SetValue(str1);

    str1=wxString::Format(_("%.4f"),m1.prism[2]);
    m1Prism3->SetValue(str1);
    if(mtg->tarset.baseinc==1)
        dbval=m1.inc[5]*PI/180.0;
    else
        dbval=m1.inc[0]*PI/180.0;
    str1=wxString::Format(_("%.5f"),rad2dms(dbval));
    m1Inc1->SetValue(str1);
    if(mtg->tarset.baseinc==1)
        dbval=m1.inc[6]*PI/180.0;
    else
        dbval=m1.inc[1]*PI/180.0;
    str1=wxString::Format(_("%.5f"),rad2dms(dbval));
    m1Inc2->SetValue(str1);
    dbval=m1.inc[2]*PI/180.0;
    str1=wxString::Format(_("%.5f"),rad2dms(dbval));
    m1Inc3->SetValue(str1);
}

void ConfigDlg::UpdateUsers()
{
    userList->DeleteAllItems();

    for(int i=0; i<nuser; i++)
    {
        userList->InsertItem(i,wxString::Format(_("%d"),i+1));
        userList->SetItem(i,1,wxString(user[i].name,wxConvUTF8));
        userList->SetItem(i,2,_("******"));
        if(user[i].level==1)
        {
            userList->SetItem(i,3,_("操作权限"));
        }
        else
        {
            userList->SetItem(i,3,_("管理权限"));
        }
    }
}

void ConfigDlg::LoadDataBase()
{
    int t1,t2;
    wxString str1,str2;
    double dbval;
    motion1=ID_FIG_NONE;
    op1=0;

    ///工程信息
    {
        prj=mtg->prj;
        duty[0]=mtg->duty[0];
        duty[1]=mtg->duty[1];
        duty[2]=mtg->duty[2];
        duty[3]=mtg->duty[3];
        ndty=mtg->ndty;
        onduty=mtg->onduty;
        str1=wxString(prj.name,wxConvUTF8);
        prjName->SetValue(str1);

        str1=wxString::Format(_("%.4f"),prj.mile1);
        prjMile1->SetValue(str1);

        str1=wxString::Format(_("%.4f"),prj.mile2);
        prjMile2->SetValue(str1);

        str1=wxString(duty[0].name,wxConvLocal);
        op1Name->SetValue(str1);
        str1=wxString(duty[1].name,wxConvLocal);
        op2Name->SetValue(str1);
        str1=wxString(duty[2].name,wxConvLocal);
        op3Name->SetValue(str1);
        str1=wxString(duty[3].name,wxConvLocal);
        op4Name->SetValue(str1);

        if(ndty==1)
        {
            prjStaticText9->Show(false);
            op2Name->Show(false);
            prjStaticText10->Show(false);
            op3Name->Show(false);
            prjStaticText11->Show(false);
            op4Name->Show(false);
        }
        if(ndty==2)
        {
            prjStaticText9->Show(true);
            op2Name->Show(true);
            prjStaticText10->Show(false);
            op3Name->Show(false);
            prjStaticText11->Show(false);
            op4Name->Show(false);
        }
        else if(ndty==3)
        {
            prjStaticText9->Show(true);
            op2Name->Show(true);
            prjStaticText10->Show(true);
            op3Name->Show(true);
            prjStaticText11->Show(false);
            op4Name->Show(false);
        }
        else if(ndty==4)
        {
            prjStaticText9->Show(true);
            op2Name->Show(true);
            prjStaticText10->Show(true);
            op3Name->Show(true);
            prjStaticText11->Show(true);
            op4Name->Show(true);
        }
    }

    ///关键区域
    str1=wxString::Format(_("%.3f"),prj.tip);
    keyTip->SetValue(str1);

    nks=mtg->nks;
    for(int i=0;i<nks;i++)
    {
        keys[i]=mtg->keys[i];
    }

    ///盾构机设置
    {
        tbm=mtg->tbm;
        if(tbm.type==0)
        {
            tbmL2->Enable(false);
            tbmL3->Enable(false);
            tbmL5->Enable(false);
            tbmL6->Enable(false);
            tbmL7->Enable(false);
            tbmL8->Enable(false);
            tbmD2->Enable(false);
            tbmD3->Enable(false);
            tbmD4->Enable(false);
            tbmD5->Enable(false);
        }
        else if(tbm.type==1)
        {
            tbmL2->Enable(false);
            tbmL3->Enable(true);
            tbmL5->Enable(false);
            tbmL6->Enable(false);
            tbmL7->Enable(true);
            tbmL8->Enable(true);
            tbmD2->Enable(false);
            tbmD3->Enable(false);
            tbmD4->Enable(true);
            tbmD5->Enable(true);
        }
        else if(tbm.type==2)
        {
            tbmL2->Enable(false);
            tbmL3->Enable(true);
            tbmL5->Enable(true);
            tbmL6->Enable(true);
            tbmL7->Enable(false);
            tbmL8->Enable(false);
            tbmD2->Enable(true);
            tbmD3->Enable(true);
            tbmD4->Enable(false);
            tbmD5->Enable(false);
        }
        else if(tbm.type==3)
        {
            tbmL2->Enable(true);
            tbmL3->Enable(true);
            tbmL5->Enable(true);
            tbmL6->Enable(true);
            tbmL7->Enable(true);
            tbmL8->Enable(true);
            tbmD2->Enable(true);
            tbmD3->Enable(true);
            tbmD4->Enable(true);
            tbmD5->Enable(true);
        }

        str1=wxString(tbm.name,wxConvUTF8);
        tbmIndex->SetValue(str1);

        str1=wxString::Format(_("%.1f"),tbm.D[0]*1000.0);   ///推进油缸直径
        tbmD1->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.D[1]*1000.0);   ///盾首铰接油缸直径前
        tbmD2->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.D[2]*1000.0);   ///盾首铰接油缸直径后
        tbmD3->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.D[3]*1000.0);   ///盾尾铰接油缸直径前
        tbmD4->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.D[4]*1000.0);   ///盾尾铰接油缸直径后
        tbmD5->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.L[0]*1000.0);   ///前盾长
        tbmL1->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.L[1]*1000.0);   ///中盾长
        tbmL2->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.L[2]*1000.0);   ///后盾长
        tbmL3->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.L[3]*1000.0);   ///推进油缸-切口
        tbmL4->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.L[4]*1000.0);   ///铰接油缸-切口
        tbmL5->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.L[5]*1000.0);   ///铰接油缸
        tbmL6->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.L[6]*1000.0);
        tbmL7->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.L[7]*1000.0);
        tbmL8->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tbm.L[8]*1000.0);
        tbmL9->SetValue(str1);
        //wxMessageBox(str1);
        UpdateJack();
        jackList->Select(0);
        tbmStaticText7->SetLabel(ajname[0]+_("油缸"));
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.aj[0]*180.0/PI));
    }
    ///激光靶设置
    tars=mtg->tarset;
    str1=wxString::Format(_("%.1f"),tars.prc);
    tarsPrism->SetValue(str1);
    str1=wxString(mtg->camset[0].name,wxConvLocal);
    tarsFile->SetValue(str1);

    ///全站仪设置
    tps=mtg->tps;
    if(tps.lasertype==0)
    {
        str1=wxString::Format(_("%.4f"),tps.laserdist[0]);
        tpsLaserDist->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tps.laserx[0]*1000.0);
        tpsLaserDevX->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tps.lasery[0]*1000.0);
        tpsLaserDevY->SetValue(str1);
    }
    else if(tps.lasertype==1)
    {
        str1=wxString::Format(_("%.4f"),tps.laserdist[1]);
        tpsLaserDist->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tps.laserx[1]*1000.0);
        tpsLaserDevX->SetValue(str1);
        str1=wxString::Format(_("%.1f"),tps.lasery[1]*1000.0);
        tpsLaserDevY->SetValue(str1);
    }

    ///管环设置
    segset=mtg->segset;
    str1=wxString::Format(_("%.1f"),segset.L*1000.0);
    segL->SetValue(str1);
    str1=wxString::Format(_("%.1f"),segset.D*1000.0);
    segD1->SetValue(str1);
    str1=wxString::Format(_("%.1f"),segset.De*1000.0);
    segD2->SetValue(str1);
    dbval=segset.Ks;
    str1=wxString::Format(_("%.1f"),360.0/dbval);
    segKs->SetValue(str1);
    str1=wxString::Format(_("%.1f"),segset.G0*1000.0);
    segG0->SetValue(str1);
    str1=wxString::Format(_("%.1f"),segset.G1*1000.0);
    segG1->SetValue(str1);
    str1=wxString::Format(_("%.1f"),segset.l2s*1000.0);
    segL2s->SetValue(str1);

    ///管块设置
    nblk=mtg->nblk;
    for(int i=0;i<nblk;i++)
    {
        blocks[i]=mtg->blocks[i];
    }

    ///测量设置
    measet=mtg->iset;
    str1=wxString::Format(_("%d"),(int)(measet.cyc));
    setMeasTime->SetValue(str1);
    str1=wxString::Format(_("%d"),(int)(measet.bcyc));
    setBackTime->SetValue(str1);
    str1=wxString::Format(_("%d"),(int)(measet.palw));
    setDev1->SetValue(str1);
    str1=wxString::Format(_("%d"),(int)(measet.jalw));
    setDev2->SetValue(str1);
    str1=wxString::Format(_("%d"),(int)(measet.balw));
    setDev3->SetValue(str1);
    str1=wxString::Format(_("%d"),(int)(measet.talw));
    setDev4->SetValue(str1);
    str1=wxString::Format(_("%.3f"),measet.aalw);
    setDev5->SetValue(str1);

    ///用户管理
    nuser=mtg->nuser;
    for(int i=0;i<nuser;i++)
    {
        user[i]=mtg->user[i];
    }

    ///初始姿态
    {
        m1=mtg->m0;
        str1=wxString::Format(_("%.4f"),m1.head[0]);
        m1Head1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.head[1]);
        m1Head2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.head[2]);
        m1Head3->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.tail[0]);
        m1Tail1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.tail[1]);
        m1Tail2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.tail[2]);
        m1Tail3->SetValue(str1);
        dbval=mtg->m0.inc1[0]*PI/180.0;
        str1=wxString::Format(_("%.5f"),rad2dms(dbval));
        m1Roll->SetValue(str1);
        CalMeasurement();
        str1=wxString::Format(_("%.4f"),m1.prism[0]);
        m1Prism1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.prism[1]);
        m1Prism2->SetValue(str1);

        str1=wxString::Format(_("%.4f"),m1.prism[2]);
        m1Prism3->SetValue(str1);
        if(mtg->tarset.baseinc==1)
            dbval=m1.inc[5]*PI/180.0;
        else
            dbval=m1.inc[0]*PI/180.0;
        str1=wxString::Format(_("%.5f"),rad2dms(dbval));
        m1Inc1->SetValue(str1);
        if(mtg->tarset.baseinc==1)
            dbval=m1.inc[6]*PI/180.0;
        else
            dbval=m1.inc[1]*PI/180.0;
        str1=wxString::Format(_("%.5f"),rad2dms(dbval));
        m1Inc2->SetValue(str1);
        dbval=m1.inc[2]*PI/180.0;
        str1=wxString::Format(_("%.5f"),rad2dms(dbval));
        m1Inc3->SetValue(str1);

        mp=mtg->mp;
        str1=wxString::Format(_("%.4f"),mp.prism[0]);
        m1CP11->SetValue(str1);
        str1=wxString::Format(_("%.4f"),mp.prism[1]);
        m1CP12->SetValue(str1);
        str1=wxString::Format(_("%.4f"),mp.prism[2]);
        m1CP13->SetValue(str1);
        str1=wxString::Format(_("%.4f"),mp.prism[3]);
        m1CP21->SetValue(str1);
        str1=wxString::Format(_("%.4f"),mp.prism[4]);
        m1CP22->SetValue(str1);
        str1=wxString::Format(_("%.4f"),mp.prism[5]);
        m1CP23->SetValue(str1);
        str1=wxString::Format(_("%.4f"),mp.prism[6]);
        //m1CP31->SetValue(str1);
        //str1=wxString::Format(_("%.4f"),mp.prism[7]);
        //m1CP32->SetValue(str1);
        //str1=wxString::Format(_("%.4f"),mp.prism[8]);
        //m1CP33->SetValue(str1);
    }
    ///远程监控

    ///语言
    UpdateBlocks();
    UpdateUsers();
    UpdateKeys();
}

void ConfigDlg::OnPaintBottom(wxPaintEvent& event)
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

        x1=9;
        y1=9;
        h1=26;
        w1=h1*4/3;

        figButton[ID_FIG_PRT_SCN].x=x1;
        figButton[ID_FIG_PRT_SCN].y=y1;
        figButton[ID_FIG_PRT_SCN].width=w1;
        figButton[ID_FIG_PRT_SCN].height=h1;
        if(motion1==ID_FIG_PRT_SCN)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
        }
        int x2,y2;
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

        x1=x1+w1+3;
        w1=32;

        figButton[ID_FIG_IMPORT].x=x1;
        figButton[ID_FIG_IMPORT].y=y1;
        figButton[ID_FIG_IMPORT].width=w1;
        figButton[ID_FIG_IMPORT].height=h1;
        if(motion1==ID_FIG_IMPORT)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            //memDC.SetPen(ipen[1]);
            //memDC.SetBrush(ibrush[1]);
            //memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            if(bmpImportPrj.IsOk())
            {
                w2=bmpImportPrj.GetWidth();
                h2=bmpImportPrj.GetHeight();
                memDC.DrawBitmap(bmpImportPrj,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            //memDC.SetPen(wxPen(wxColor(117,117,117)));
            //memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            //memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            if(bmpImportPrj.IsOk())
            {
                w2=bmpImportPrj.GetWidth();
                h2=bmpImportPrj.GetHeight();
                memDC.DrawBitmap(bmpImportPrj,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        x1=x1+w1+3;
        figButton[ID_FIG_EXPORT].x=x1;
        figButton[ID_FIG_EXPORT].y=y1;
        figButton[ID_FIG_EXPORT].width=w1;
        figButton[ID_FIG_EXPORT].height=h1;
        if(motion1==ID_FIG_EXPORT)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            //memDC.SetPen(ipen[1]);
            //memDC.SetBrush(ibrush[1]);
            //memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            if(bmpExportPrj.IsOk())
            {
                w2=bmpExportPrj.GetWidth();
                h2=bmpExportPrj.GetHeight();
                memDC.DrawBitmap(bmpExportPrj,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            //memDC.SetPen(wxPen(wxColor(117,117,117)));
            //memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            //memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);

            if(bmpExportPrj.IsOk())
            {
                w2=bmpExportPrj.GetWidth();
                h2=bmpExportPrj.GetHeight();
                memDC.DrawBitmap(bmpExportPrj,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+3;
        figButton[ID_FIG_CLEAR].x=x1;
        figButton[ID_FIG_CLEAR].y=y1;
        figButton[ID_FIG_CLEAR].width=w1;
        figButton[ID_FIG_CLEAR].height=h1;
        if(motion1==ID_FIG_CLEAR)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            //memDC.SetPen(ipen[1]);
            //memDC.SetBrush(ibrush[1]);
            //memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);

            if(bmpClearPrj.IsOk())
            {
                w2=bmpClearPrj.GetWidth();
                h2=bmpClearPrj.GetHeight();
                memDC.DrawBitmap(bmpClearPrj,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            //memDC.SetPen(wxPen(wxColor(117,117,117)));
            //memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            //memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);

            if(bmpClearPrj.IsOk())
            {
                w2=bmpClearPrj.GetWidth();
                h2=bmpClearPrj.GetHeight();
                memDC.DrawBitmap(bmpClearPrj,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        w1=65;
        x1=w-w1-12;
        figButton[ID_FIG_QUIT].x=x1;
        figButton[ID_FIG_QUIT].y=y1;
        figButton[ID_FIG_QUIT].width=w1;
        figButton[ID_FIG_QUIT].height=h1;
        if(motion1==ID_FIG_QUIT)
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
        //memDC.SetPen(wxPen(wxColor(117,117,117)));

        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("退出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1-w1-7;
        figButton[ID_FIG_APPLY].x=x1;
        figButton[ID_FIG_APPLY].y=y1;
        figButton[ID_FIG_APPLY].width=w1;
        figButton[ID_FIG_APPLY].height=h1;

        int n=ID_FIG_BTN_LANG-ID_FIG_BTN_PRJ+1;
        int save=0;
        for(int i=0;i<n;i++)
        {
            if(modified[i]==1)
            {
                save=1;
                break;
            }
        }
        if(save==1)
        {
            if(motion1==ID_FIG_APPLY)
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
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
        }

        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("应用"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        panelButton->GetSize(&w1,0);
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

void ConfigDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_QUIT].y && y<figButton[ID_FIG_QUIT].y+figButton[ID_FIG_QUIT].height)
    {
        if(x>figButton[ID_FIG_PRT_SCN].x && x<figButton[ID_FIG_PRT_SCN].x+figButton[ID_FIG_PRT_SCN].width)
        {
            motion1=ID_FIG_PRT_SCN;
        }
        else if(x>figButton[ID_FIG_QUIT].x && x<figButton[ID_FIG_QUIT].x+figButton[ID_FIG_QUIT].width)
        {
            motion1=ID_FIG_QUIT;
        }
        else if(x>figButton[ID_FIG_APPLY].x && x<figButton[ID_FIG_APPLY].x+figButton[ID_FIG_APPLY].width)
        {
            motion1=ID_FIG_APPLY;
        }
        else if(x>figButton[ID_FIG_IMPORT].x && x<figButton[ID_FIG_IMPORT].x+figButton[ID_FIG_IMPORT].width)
        {
            motion1=ID_FIG_IMPORT;
        }
        else if(x>figButton[ID_FIG_EXPORT].x && x<figButton[ID_FIG_EXPORT].x+figButton[ID_FIG_EXPORT].width)
        {
            motion1=ID_FIG_EXPORT;
        }
        else if(x>figButton[ID_FIG_CLEAR].x && x<figButton[ID_FIG_CLEAR].x+figButton[ID_FIG_CLEAR].width)
        {
            motion1=ID_FIG_CLEAR;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else
    {
        motion1=ID_FIG_NONE;
    }
    panelBottom->Refresh();
}

void ConfigDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    panelBottom->Refresh();
}

void ConfigDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion1==ID_FIG_QUIT)
    {
        int n=ID_FIG_BTN_LANG-ID_FIG_BTN_PRJ+1;
        int save=0;
        for(int i=0;i<n;i++)
        {
            if(modified[i]==1)
            {
                save=1;
                break;
            }
        }
        if(save==1)
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("不保存退出吗？");
            if(dlg.ShowModal()==wxID_OK)
            {
                Destroy();
            }
        }
        else
        {
            Destroy();
        }
    }
    else
    {
        if(motion1==ID_FIG_PRT_SCN)
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
            str=_("设置界面");
            str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
            wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
            if(dlg.ShowModal()==wxID_OK)
            {
                str=dlg.GetPath();
                bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
            }
        }
        else if(motion1==ID_FIG_IMPORT)
        {
            if(mtg->tarset.stopped==1)
            {
                WriteMsg(_("角度异常，请立刻联系上海米度测量技术有限公司!"),1);
                return;//end add
            }
            if(mtg->onLine==0) ImportDB();
        }
        else if(motion1==ID_FIG_EXPORT)
        {
            ExportDB();
        }
        else if(motion1==ID_FIG_CLEAR)
        {
            if(mtg->tarset.stopped==1)
            {
                WriteMsg(_("角度异常，请立刻联系上海米度测量技术有限公司!"),1);
                return;//end add
            }
            if(mtg->onLine==0) ClearDB();
        }
        else if(motion1==ID_FIG_APPLY)
        {
            if(mtg->tarset.stopped==1)
            {
                WriteMsg(_("角度异常，请尽快联系上海米度测量技术有限公司!"),1);
                return;//end add
            }
            if(mtg->ithread==MTG_THREAD_ORIGIN)
            {
                WriteMsg(_("正进行零位测量，请稍后"),1);
                return;
            }
            Apply();
        }
    }
}

void ConfigDlg::WriteMsg(wxString msg,int col)
{
    m_msg=msg;
    m_msgc=col;
    panelBottom->Refresh();
}

void ConfigDlg::ImportDB()
{
    wxMessageDialog dlg(this,_("还原操作将覆盖当前数据库中的数据，是否继续？"),_("警告"), wxOK | wxCANCEL);
    if(dlg.ShowModal()==wxID_OK)
    {
        PasswordDialog passDlg(this);
        passDlg.TextPassword->SetFocus();
        passDlg.Center();
        if(passDlg.ShowModal()==wxID_OK)
        {
            if(passDlg.TextPassword->GetValue().Cmp(wxString((const char*)mtg->user[0].password,wxConvLocal))!=0)
                return;
        }
        wxFileDialog fileDlg(this,_("选择待还原的工程文件"),wxEmptyString,wxEmptyString,_("工程文件(*.prj)|*.prj"),wxFD_OPEN);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            wxString strCmd=_("mysql -u root -p123 dba_laser <\"")+strFile+_("\"");
            bool bRet=wxShell(strCmd);
            trace(0,"config:cmd=%s\n",strCmd.mb_str(wxConvLocal));
            //wxMessageBox(strCmd);
            //wxProcess *p=new wxProcess;
            //p->Redirect();///屏闭shell窗口信息
            //int code = wxExecute(strCmd, wxEXEC_SYNC,p);
            if(bRet)
            {
                wxMessageBox(_("数据已还原！"),_("提示"));
                mtg_import_db(mtg);
                LoadDataBase();
                sqlite_export_db(mtg,mtg->sqlitepath);
            }
            else
            {
                wxMessageBox(_("还原失败！"),_("提示"));
            }
        }

    }
    LoadDataBase();
}

void ConfigDlg::ExportDB()
{
    wxFileDialog fileDlg(this,_("输入备份文件路径"),wxEmptyString,wxEmptyString,_("工程文件(*.prj)|*.prj"),wxFD_SAVE);
    //wxFileDialog fileDlg(this,_("输入备份文件路径"),wxEmptyString,wxEmptyString,_("工程文件(*.sql)|*.sql"),wxFD_SAVE);
    if(fileDlg.ShowModal()==wxID_OK)
    {
        wxString strFile=fileDlg.GetPath();
        //wxMessageBox(strFile);
        wxString strCmd=_("mysqldump -u root -p123 dba_laser >\"")+strFile+_("\"");
        //wxString strCmd=_("mysqldump -u root -p123 -h 111.231.69.234 mto_remote >\"")+strFile+_("\"");
        bool bRet=wxShell(strCmd);
        //trace(0,"cmd=%s\n",strCmd.mb_str(wxConvLocal));
        if(bRet)
        {
            wxMessageBox(_("数据已备份！"),_("提示"));
            //LoadDatabase();
        }
        else
        {
            wxMessageBox(_("备份失败！"),_("提示"));
        }
    }
    LoadDataBase();
}

void ConfigDlg::ClearDB()
{
    wxMessageDialog dlg(this,_("清空操作将清除当前数据库中的数据，是否继续？"),_("警告"), wxOK | wxCANCEL);
    if(dlg.ShowModal()==wxID_OK)
    {
        PasswordDialog passDlg(this);
        passDlg.TextPassword->SetFocus();
        passDlg.Center();
        if(passDlg.ShowModal()==wxID_OK)
        {
            if(passDlg.TextPassword->GetValue().Cmp(wxString((const char*)mtg->user[0].password,wxConvLocal))!=0)
                return;
        }

        tars=mtg->tarset;
        camset[0]=mtg->camset[0];
        camset[1]=mtg->camset[1];
        mtg_init_db(mtg);
        mtg_store_camset(mtg);
        mtg_store_tars(mtg);
        mtg_store_tbmset(mtg);
        mtg_store_origin(mtg);
        mtg_import_db(mtg);
        LoadDataBase();

        wxStandardPaths wsp;
        wxString str=wsp.GetDataDir()+wxString(_("\\log\\"));
        if(wxDir::Exists(str))
        {
            wxDir dir(str);
            dir.Open(str);
            if(dir.IsOpened())
            {
                int n=0;
                wxArrayString files;
                wxString token=wxT("*.log");
                n=dir.GetAllFiles(str,&files,token,wxDIR_DEFAULT);

                if(n>0)
                {
                    files.Sort(true);
                    for(int i=0;i<n;i++)
                    {
                        wxRemoveFile(files[i]);
                    }
                }
            }
        }

        str=wsp.GetDataDir()+wxString(_("\\TPS_LOG\\"));
        if(wxDir::Exists(str))
        {
            wxDir dir(str);
            dir.Open(str);
            if(dir.IsOpened())
            {
                int n=0;
                wxArrayString files;
                wxString token=wxT("*.log");
                n=dir.GetAllFiles(str,&files,token,wxDIR_DEFAULT);

                if(n>0)
                {
                    files.Sort(true);
                    for(int i=0;i<n;i++)
                    {
                        wxRemoveFile(files[i]);
                    }
                }
            }
        }
        wxMessageBox(_("数据已清空！"),_("提示"));
    }
}

void ConfigDlg::Apply()
{
    char msg[4096];

    if(prjModified==1)
    {
        mtg->prj=prj;
        mtg->duty[0]=duty[0];
        mtg->duty[1]=duty[1];
        mtg->duty[2]=duty[2];
        mtg->duty[3]=duty[3];
        mtg->ndty=ndty;
        if(!mtg_store_prj(mtg))
        {
            WriteMsg(_("工程设置保存失败！"),1);
            return;
        }
        sqlite_export_prj(mtg,mtg->sqlitepath);
        prjModified=0;
        mtg->icli[0]=1;
    }

    if(keyModified==1)
    {
        if(mtg->nks!=nks)
        {
            mtg->nks=nks;
            if(mtg->keys) mtg->keys=(MTG_KEY*)realloc(mtg->keys,nks*sizeof(MTG_KEY));
            else mtg->keys=(MTG_KEY*)malloc(nks*sizeof(MTG_KEY));
        }
        for(int i=0;i<nks;i++)
        {
            mtg->keys[i]=keys[i];
        }
        if(!mtg_store_keys(mtg))
        {
            WriteMsg(_("区域设置保存失败！"),1);
            return;
        }
        keyModified=0;
        mtg->icli[1]=1;
    }

    if(tbmModified==1)
    {
        mtg->tbm=tbm;
        if(!mtg_store_tbmset(mtg))
        {
            WriteMsg(_("盾构设置保存失败！"),1);
            return;
        }
        sqlite_export_tbmset(mtg,mtg->sqlitepath);
        tbmModified=0;
        mtg->icli[2]=1;
    }

    if(tarsModified==1)
    {
        /*if(tars.ipos!=mtg->tarset.ipos)
        {
            mtg_cal_prism_coord(mtg,tars.ipos);
        }*/
        mtg->tarset=tars;
        if(!mtg_store_tars(mtg))
        {
            mtg_cal_origin(mtg);
            WriteMsg(_("激光靶设置保存失败！"),1);
            return;
        }
        else
            mtg_cal_origin(mtg);
        tarsModified=0;
        mtg->icli[3]=1;
        //modified[3]=0;
    }

    if(tpsModified==1)
    {
        mtg->tps=tps;
        if(!mtg_store_tps(mtg))
        {
            WriteMsg(_("全站仪设置保存失败！"),1);
            return;
        }
        tpsModified=0;
        mtg->icli[4]=1;
    }

    if(segModified==1)
    {
        mtg->segset=segset;
        if(!mtg_store_segset(mtg))
        {
            WriteMsg(_("管环设置保存失败！"),1);
            return;
        }
        sqlite_export_segset(mtg,mtg->sqlitepath);
        segModified=0;
        mtg->icli[5]=1;
    }

    if(blockModified==1)
    {
        mtg->nblk=nblk;
        for(int i=0;i<nblk;i++)
        {
            mtg->blocks[i]=blocks[i];
        }
        //mtg->segset=segset;
        if(!mtg_store_block(mtg))
        {
            WriteMsg(_("管块设置保存失败！"),1);
            return;
        }
        sqlite_export_block(mtg,mtg->sqlitepath);
        blockModified=0;
        mtg->icli[6]=1;
    }

    if(m1Modified==1)
    {
        mtg->m0=m1;
        mtg->mp=mp;
        time(&mtg->m0.t4);
        //wxMessageBox(wxString::Format(_("mtg->m0:%.4f,%.4f,%.4f"),m1.inc[0],m1.inc[1],m1.inc[2]));
        if(!mtg_store_origin(mtg))
        {
            WriteMsg(_("初始姿态设置保存失败！"),1);
            return;
        }
        m1Modified=0;
        mtg->icli[7]=1;
        modified[7]=0;
        m1TimePanel->Refresh();
    }

    if(settingModified==1)
    {
        if(measet.plctype != mtg->iset.plctype)
        {
            IsChangeConnectPlcWay=1;
            wxMessageBox(_("已更改PLC读取方式,请重新启动软件！"));
        }

        mtg->iset=measet;
        if(!mtg_store_sets(mtg))
        {
            WriteMsg(_("参数设置保存失败！"),1);
            return;
        }
        settingModified=0;
        mtg->icli[8]=1;
    }

    if(userModified==1)
    {
        if(mtg->nuser!=nuser)
        {
            mtg->nuser=nuser;
            if(mtg->user) mtg->user=(MTG_USER*)realloc(mtg->user,mtg->nuser*sizeof(MTG_USER));
		    else mtg->user=(MTG_USER*)malloc(sizeof(MTG_USER));
        }
        for(int i=0;i<nuser;i++)
        {
            mtg->user[i]=user[i];
        }
        if(!mtg_store_user(mtg))
        {
            WriteMsg(_("用户设置保存失败！"),1);
            return;
        }
        userModified=0;
        mtg->icli[10]=1;
    }
}

void ConfigDlg::OnPaintBackground(wxPaintEvent& event)
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

void ConfigDlg::OnPaintNavi(wxPaintEvent& event)
{
    wxPaintDC dc(panelNavi);
    int w,h;
    panelNavi->GetClientSize(&w,&h);

    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(0,-1,w,h+1);
}

void ConfigDlg::OnPaintTimeFig(wxPaintEvent& event)
{
    wxPaintDC dc(m1TimePanel);
    int w,h;
    m1TimePanel->GetClientSize(&w,&h);
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
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,225)));
        memDC.DrawRectangle(1,1,w-2,25);
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawLine(0,25,w,25);
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));

        memDC.SetTextForeground(wxColor(0,0,255));
        if(mtg->m0.t4>0)
        {
            memDC.DrawLabel(wxDateTime(mtg->m0.t4).Format(_("%Y-%m-%d %H:%M:%S"))+_(" 保存零位数据!"),wxRect(15,0,w,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        memDC.SetTextForeground(icolor[0]);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::CalMeasurement()
{
    double ilen;
    double idx,idy,idz;
    double iinc[3];
    wxString istr=wxEmptyString;

    idx=m1.head[0]-m1.tail[0];
    idy=m1.head[1]-m1.tail[1];
    idz=m1.head[2]-m1.tail[2];
    ilen=idx*idx+idy*idy+idz*idz;
    ilen=sqrt(ilen);

    iinc[2]=atan2(idy,idx);
    if(iinc[2]<0) iinc[2]=iinc[2]+2.0*PI;

    if(ilen==0.0)
    {
        iinc[1]=0.0;
    }
    else
    {
        iinc[1]=atan(idz/ilen);
    }

    istr=wxString::Format(_("%.5f"),rad2dms(iinc[2]));
    m1Azi->SetValue(istr);
    istr=wxString::Format(_("%.5f"),rad2dms(iinc[1]));
    m1Pitch->SetValue(istr);
    m1Pitch->Enable(false);
}

void ConfigDlg::IsModified()
{
    //if(mtg->tarset.stopped==1) return;
    if(mtg->onLine==0)
    {
        wxString str,str1;
        long lval;
        double dbval;
        //int page=panelButtonList->btn_clicked;

        if(page==0)
        {
            modified[page]=0;
            str=prjName->GetValue();
            strncpy(prj.name,str.mb_str(wxConvUTF8),64);
            str=prjMile1->GetValue();
            str.ToDouble(&prj.mile1);
            str=prjMile2->GetValue();
            str.ToDouble(&prj.mile2);
            str=op1Name->GetValue();
            strncpy(duty[0].name,str.mb_str(wxConvLocal),64);
            str=op2Name->GetValue();
            strncpy(duty[1].name,str.mb_str(wxConvLocal),64);
            str=op3Name->GetValue();
            strncpy(duty[2].name,str.mb_str(wxConvLocal),64);
            str=op4Name->GetValue();
            strncpy(duty[3].name,str.mb_str(wxConvLocal),64);
            if(prj.mile1<=prj.mile2) prj.a2z=1;
            else prj.a2z=-1;

            str=op1Name->GetValue();
            str1=wxString(mtg->duty[0].name,wxConvLocal);
            if(str.Cmp(str1)!=0)
            {
                prjModified=1;
                modified[page]=1;
                return;
            }

            str=op2Name->GetValue();
            str1=wxString(mtg->duty[1].name,wxConvLocal);
            if(str.Cmp(str1)!=0)
            {
                prjModified=1;
                modified[page]=1;
                return;
            }

            str=op3Name->GetValue();
            str1=wxString(mtg->duty[2].name,wxConvLocal);
            if(str.Cmp(str1)!=0)
            {
                prjModified=1;
                modified[page]=1;
                return;
            }

            str=op4Name->GetValue();
            str1=wxString(mtg->duty[3].name,wxConvLocal);
            if(str.Cmp(str1)!=0)
            {
                prjModified=1;
                modified[page]=1;
                return;
            }

            str=prjName->GetValue();
            str1=wxString(mtg->prj.name,wxConvUTF8);
            if(str.Cmp(str1)!=0)
            {
                prjModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),prj.mile1);
            str1=wxString::Format(_("%.5f"),mtg->prj.mile1);
            if(str.Cmp(str1)!=0)
            {
                prjModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),prj.mile2);
            str1=wxString::Format(_("%.5f"),mtg->prj.mile2);
            if(str.Cmp(str1)!=0)
            {
                prjModified=1;
                modified[page]=1;
                return;
            }

            if(prj.a2z!=mtg->prj.a2z)
            {
                prjModified=1;
                modified[page]=1;
                return;
            }

            if(ndty!=mtg->ndty)
            {
                prjModified=1;
                modified[page]=1;
                return;
            }
        }
        else if(page==1)
        {
            modified[page]=0;
            str=keyTip->GetValue();
            str.ToDouble(&prj.tip);

            str=wxString::Format(_("%.5f"),prj.tip);
            str1=wxString::Format(_("%.5f"),mtg->prj.tip);
            if(str.Cmp(str1)!=0)
            {
                prjModified=1;
                modified[page]=1;
            }

            if(prj.htip!=mtg->prj.htip)
            {
                prjModified=1;
                modified[page]=1;
            }
            if(prj.vtip!=mtg->prj.vtip)
            {
                prjModified=1;
                modified[page]=1;
            }

            if(nks!=mtg->nks)
            {
                keyModified=1;
                modified[page]=1;
                return;
            }
            else
            {
                int i;
                for(i=0;i<nks;i++)
                {
                    str=wxString(keys[i].name,wxConvUTF8);
                    str1=wxString(mtg->keys[i].name,wxConvUTF8);
                    if(str.Cmp(str1)!=0)
                    {
                        keyModified=1;
                        modified[page]=1;
                        break;
                    }
                    str=wxString::Format(_("%.5f"),keys[i].mile1);
                    str1=wxString::Format(_("%.5f"),mtg->keys[i].mile1);
                    if(str.Cmp(str1)!=0)
                    {
                        keyModified=1;
                        modified[page]=1;
                        break;
                    }
                    str=wxString::Format(_("%.5f"),keys[i].mile2);
                    str1=wxString::Format(_("%.5f"),mtg->keys[i].mile2);
                    if(str.Cmp(str1)!=0)
                    {
                        keyModified=1;
                        modified[page]=1;
                        break;
                    }
                }
            }
        }
        else if(page==2)
        {
            modified[page]=0;
            str=tbmIndex->GetValue();
            strncpy(tbm.name,str.mb_str(wxConvUTF8),64);

            str=tbmL1->GetValue();
            str.ToDouble(&tbm.L[0]);
            str=tbmL2->GetValue();
            str.ToDouble(&tbm.L[1]);
            str=tbmL3->GetValue();
            str.ToDouble(&tbm.L[2]);
            str=tbmL4->GetValue();
            str.ToDouble(&tbm.L[3]);
            str=tbmL5->GetValue();
            str.ToDouble(&tbm.L[4]);
            str=tbmL6->GetValue();
            str.ToDouble(&tbm.L[5]);
            str=tbmL7->GetValue();
            str.ToDouble(&tbm.L[6]);
            str=tbmL8->GetValue();
            str.ToDouble(&tbm.L[7]);
            str=tbmL9->GetValue();
            str.ToDouble(&tbm.L[8]);

            str=tbmD1->GetValue();
            str.ToDouble(&tbm.D[0]);
            str=tbmD2->GetValue();
            str.ToDouble(&tbm.D[1]);
            str=tbmD3->GetValue();
            str.ToDouble(&tbm.D[2]);
            str=tbmD4->GetValue();
            str.ToDouble(&tbm.D[3]);
            str=tbmD5->GetValue();
            str.ToDouble(&tbm.D[4]);

            tbm.L[0]=tbm.L[0]/1000.0;
            tbm.L[1]=tbm.L[1]/1000.0;
            tbm.L[2]=tbm.L[2]/1000.0;
            tbm.L[3]=tbm.L[3]/1000.0;
            tbm.L[4]=tbm.L[4]/1000.0;
            tbm.L[5]=tbm.L[5]/1000.0;
            tbm.L[6]=tbm.L[6]/1000.0;
            tbm.L[7]=tbm.L[7]/1000.0;
            tbm.L[8]=tbm.L[8]/1000.0;

            tbm.D[0]=tbm.D[0]/1000.0;
            tbm.D[1]=tbm.D[1]/1000.0;
            tbm.D[2]=tbm.D[2]/1000.0;
            tbm.D[3]=tbm.D[3]/1000.0;
            tbm.D[4]=tbm.D[4]/1000.0;

            str=tbmIndex->GetValue();
            str1=wxString(mtg->tbm.name,wxConvUTF8);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.D[0]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.D[0]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.D[1]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.D[1]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.D[2]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.D[2]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.D[3]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.D[3]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.D[4]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.D[4]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.L[0]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.L[0]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.L[1]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.L[1]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.L[2]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.L[2]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.L[3]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.L[3]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.L[4]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.L[4]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.L[5]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.L[5]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.L[6]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.L[6]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.L[7]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.L[7]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tbm.L[8]);
            str1=wxString::Format(_("%.5f"),mtg->tbm.L[8]);
            if(str.Cmp(str1)!=0)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            if(tbm.type!=mtg->tbm.type)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            if(tbm.naj!=mtg->tbm.naj)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            if(tbm.nfj!=mtg->tbm.nfj)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }
            if(tbm.nbj!=mtg->tbm.nbj)
            {
                tbmModified=1;
                modified[page]=1;
                return;
            }

            for(int i=0;i<6;i++)
            {
                str=wxString::Format(_("%.5f"),tbm.aj[i]);
                str1=wxString::Format(_("%.5f"),mtg->tbm.aj[i]);
                if(str.Cmp(str1)!=0)
                {
                    tbmModified=1;
                    modified[page]=1;
                    return;
                }
                if(i>3) continue;
                str=wxString::Format(_("%.5f"),tbm.bj[i]);
                str1=wxString::Format(_("%.5f"),mtg->tbm.bj[i]);
                if(str.Cmp(str1)!=0)
                {
                    tbmModified=1;
                    modified[page]=1;
                    return;
                }
                str=wxString::Format(_("%.5f"),tbm.fj[i]);
                str1=wxString::Format(_("%.5f"),mtg->tbm.fj[i]);
                if(str.Cmp(str1)!=0)
                {
                    tbmModified=1;
                    modified[page]=1;
                    return;
                }
            }
        }
        else if(page==3)
        {
            modified[page]=0;
            str=tarsPrism->GetValue();
            str.ToDouble(&tars.prc);

            str=wxString::Format(_("%.5f"),tars.prc);
            str1=wxString::Format(_("%.5f"),mtg->tarset.prc);
            if(str.Cmp(str1)!=0)
            {
                tarsModified=1;
                modified[page]=1;
                return;
            }

            if(tars.pos!=mtg->tarset.pos)
            {
                tarsModified=1;
                modified[page]=1;
                return;
            }
            if(tars.ipos!=mtg->tarset.ipos)
            {
                tarsModified=1;
                modified[page]=1;
                return;
            }
            if(m1.ipos!=mtg->m0.ipos)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
        }
        else if(page==4)
        {
            modified[page]=0;
            str=tpsLaserDist->GetValue();
            if(tps.lasertype==0)
                str.ToDouble(&tps.laserdist[0]);
            else if(tps.lasertype==1) str.ToDouble(&tps.laserdist[1]);
            str=tpsLaserDevX->GetValue();
            str.ToDouble(&dbval);
            if(tps.lasertype==0)
                tps.laserx[0]=dbval/1000.0;
            else if(tps.lasertype==1)
                tps.laserx[1]=dbval/1000.0;
            str=tpsLaserDevY->GetValue();
            str.ToDouble(&dbval);
            if(tps.lasertype==0)
                tps.lasery[0]=dbval/1000.0;
            else if(tps.lasertype==1)
                tps.lasery[1]=dbval/1000.0;

            str=wxString::Format(_("%.5f"),tps.laserdist[0]);
            str1=wxString::Format(_("%.5f"),mtg->tps.laserdist[0]);
            if(str.Cmp(str1)!=0)
            {
                tpsModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tps.laserdist[1]);
            str1=wxString::Format(_("%.5f"),mtg->tps.laserdist[1]);
            if(str.Cmp(str1)!=0)
            {
                tpsModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tps.laserx[0]);
            str1=wxString::Format(_("%.5f"),mtg->tps.laserx[0]);
            if(str.Cmp(str1)!=0)
            {
                tpsModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tps.laserx[1]);
            str1=wxString::Format(_("%.5f"),mtg->tps.laserx[1]);
            if(str.Cmp(str1)!=0)
            {
                tpsModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tps.lasery[0]);
            str1=wxString::Format(_("%.5f"),mtg->tps.lasery[0]);
            if(str.Cmp(str1)!=0)
            {
                tpsModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),tps.lasery[1]);
            str1=wxString::Format(_("%.5f"),mtg->tps.lasery[1]);
            if(str.Cmp(str1)!=0)
            {
                tpsModified=1;
                modified[page]=1;
                return;
            }

            if(tps.lasertype!=mtg->tps.lasertype)
            {
                tpsModified=1;
                modified[page]=1;
                return;
            }
            if(tps.type!=mtg->tps.type)
            {
                tpsModified=1;
                modified[page]=1;
                return;
            }
        }
        else if(page==5)
        {
            modified[page]=0;
            str=segL->GetValue();
            str.ToDouble(&dbval);
            segset.L=dbval/1000.0;
            str=segD1->GetValue();
            str.ToDouble(&dbval);
            segset.D=dbval/1000.0;
            str=segD2->GetValue();
            str.ToDouble(&dbval);
            segset.De=dbval/1000.0;
            str=segKs->GetValue();
            str.ToDouble(&dbval);
            lval=360.0/dbval;
            segset.Ks=lval;
            str=segG0->GetValue();
            str.ToDouble(&dbval);
            segset.G0=dbval/1000.0;
            str=segG1->GetValue();
            str.ToDouble(&dbval);
            segset.G1=dbval/1000.0;
            str=segL2s->GetValue();
            str.ToDouble(&dbval);
            segset.l2s=dbval/1000.0;
            str=wxString::Format(_("%.5f"),segset.L);
            str1=wxString::Format(_("%.5f"),mtg->segset.L);
            if(str.Cmp(str1)!=0)
            {
                segModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),segset.D);
            str1=wxString::Format(_("%.5f"),mtg->segset.D);
            if(str.Cmp(str1)!=0)
            {
                segModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),segset.De);
            str1=wxString::Format(_("%.5f"),mtg->segset.De);
            if(str.Cmp(str1)!=0)
            {
                segModified=1;
                modified[page]=1;
                return;
            }

            if(segset.Ks!=mtg->segset.Ks)
            {
                segModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),segset.G0);
            str1=wxString::Format(_("%.5f"),mtg->segset.G0);
            if(str.Cmp(str1)!=0)
            {
                segModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),segset.G1);
            str1=wxString::Format(_("%.5f"),mtg->segset.G1);
            if(str.Cmp(str1)!=0)
            {
                segModified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),segset.l2s);
            str1=wxString::Format(_("%.5f"),mtg->segset.l2s);
            if(str.Cmp(str1)!=0)
            {
                segModified=1;
                modified[page]=1;
                return;
            }
            if(segset.in!=mtg->segset.in)
            {
                segModified=1;
                modified[page]=1;
                return;
            }
            if(segset.type!=mtg->segset.type)
            {
                segModified=1;
                modified[page]=1;
                return;
            }
            if(segset.f2b!=mtg->segset.f2b)
            {
                segModified=1;
                modified[page]=1;
                return;
            }
            if(segset.s2s!=mtg->segset.s2s)
            {
                segModified=1;
                modified[page]=1;
                return;
            }
        }
        else if(page==6)
        {
            modified[page]=0;
            if(nblk!=mtg->nblk)
            {
                blockModified=1;
                modified[page]=1;
                return;
            }
            else
            {
                int i;
                for(i=0;i<nblk;i++)
                {
                    str=wxString(blocks[i].name,wxConvUTF8);
                    str1=wxString(mtg->blocks[i].name,wxConvUTF8);
                    if(str.Cmp(str1)!=0)
                    {
                        blockModified=1;
                        modified[page]=1;
                        break;
                    }
                    str=wxString::Format(_("%.5f"),blocks[i].angle);
                    str1=wxString::Format(_("%.5f"),mtg->blocks[i].angle);
                    if(str.Cmp(str1)!=0)
                    {
                        blockModified=1;
                        modified[page]=1;
                        return;
                    }
                }
            }
        }
        else if(page==7)
        {
            modified[page]=0;
            str=m1Head1->GetValue();
            str.ToDouble(&m1.head[0]);
            str=m1Head2->GetValue();
            str.ToDouble(&m1.head[1]);
            str=m1Head3->GetValue();
            str.ToDouble(&m1.head[2]);

            str=m1Tail1->GetValue();
            str.ToDouble(&m1.tail[0]);
            str=m1Tail2->GetValue();
            str.ToDouble(&m1.tail[1]);
            str=m1Tail3->GetValue();
            str.ToDouble(&m1.tail[2]);
            CalMeasurement();

            str=m1Roll->GetValue();
            str.ToDouble(&dbval);
            m1.inc1[0]=dms2deg(dbval);

            str=m1Prism1->GetValue();
            str.ToDouble(&dbval);
            m1.prism[0]=dbval;
            str=m1Prism2->GetValue();
            str.ToDouble(&dbval);
            m1.prism[1]=dbval;
            str=m1Prism3->GetValue();
            str.ToDouble(&dbval);
            m1.prism[2]=dbval;

            str=m1Inc1->GetValue();
            str.ToDouble(&dbval);
            if(mtg->tarset.baseinc==1)
                m1.inc[5]=dms2deg(dbval);
            else
                m1.inc[0]=dms2deg(dbval);

            str=m1Inc2->GetValue();
            str.ToDouble(&dbval);
            if(mtg->tarset.baseinc==1)
                m1.inc[6]=dms2deg(dbval);
            else
                m1.inc[1]=dms2deg(dbval);

            str=m1Inc3->GetValue();
            str.ToDouble(&dbval);
            m1.inc[2]=dms2deg(dbval);

            str=m1CP11->GetValue();
            str.ToDouble(&dbval);
            mp.prism[0]=dbval;

            str=m1CP12->GetValue();
            str.ToDouble(&dbval);
            mp.prism[1]=dbval;

            str=m1CP13->GetValue();
            str.ToDouble(&dbval);
            mp.prism[2]=dbval;

            str=m1CP21->GetValue();
            str.ToDouble(&dbval);
            mp.prism[3]=dbval;

            str=m1CP22->GetValue();
            str.ToDouble(&dbval);
            mp.prism[4]=dbval;

            str=m1CP23->GetValue();
            str.ToDouble(&dbval);
            mp.prism[5]=dbval;

            //str=m1CP31->GetValue();
            //str.ToDouble(&dbval);
            //mp.prism[6]=dbval;

            //str=m1CP32->GetValue();
            //str.ToDouble(&dbval);
            //mp.prism[7]=dbval;

            //str=m1CP33->GetValue();
            //str.ToDouble(&dbval);
            //mp.prism[8]=dbval;
            if(mtg->tarset.baseinc==1)
            {
                str=wxString::Format(_("%.5f"),m1.inc[5]);
                str1=wxString::Format(_("%.5f"),mtg->m0.inc[5]);
            }
            else
            {
                str=wxString::Format(_("%.5f"),m1.inc[0]);
                str1=wxString::Format(_("%.5f"),mtg->m0.inc[0]);
            }
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }

            if(mtg->tarset.baseinc==1)
            {
                str=wxString::Format(_("%.5f"),m1.inc[6]);
                str1=wxString::Format(_("%.5f"),mtg->m0.inc[6]);
            }
            else
            {
                str=wxString::Format(_("%.5f"),m1.inc[1]);
                str1=wxString::Format(_("%.5f"),mtg->m0.inc[1]);
            }

            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }

            str=wxString::Format(_("%.5f"),m1.inc[2]);
            str1=wxString::Format(_("%.5f"),mtg->m0.inc[2]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }

            str=wxString::Format(_("%.5f"),m1.head[0]);
            str1=wxString::Format(_("%.5f"),mtg->m0.head[0]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),m1.head[1]);
            str1=wxString::Format(_("%.5f"),mtg->m0.head[1]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),m1.head[2]);
            str1=wxString::Format(_("%.5f"),mtg->m0.head[2]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }

            str=wxString::Format(_("%.5f"),m1.tail[0]);
            str1=wxString::Format(_("%.5f"),mtg->m0.tail[0]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),m1.tail[1]);
            str1=wxString::Format(_("%.5f"),mtg->m0.tail[1]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),m1.tail[2]);
            str1=wxString::Format(_("%.5f"),mtg->m0.tail[2]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }

            str=wxString::Format(_("%.4f"),m1.inc1[0]);
            str1=wxString::Format(_("%.4f"),mtg->m0.inc1[0]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }

            str=wxString::Format(_("%.5f"),m1.prism[0]);
            str1=wxString::Format(_("%.5f"),mtg->m0.prism[0]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),m1.prism[1]);
            str1=wxString::Format(_("%.5f"),mtg->m0.prism[1]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),m1.prism[2]);
            str1=wxString::Format(_("%.5f"),mtg->m0.prism[2]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),mp.prism[0]);
            str1=wxString::Format(_("%.5f"),mtg->mp.prism[0]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),mp.prism[1]);
            str1=wxString::Format(_("%.5f"),mtg->mp.prism[1]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),mp.prism[2]);
            str1=wxString::Format(_("%.5f"),mtg->mp.prism[2]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),mp.prism[3]);
            str1=wxString::Format(_("%.5f"),mtg->mp.prism[3]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),mp.prism[4]);
            str1=wxString::Format(_("%.5f"),mtg->mp.prism[4]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),mp.prism[5]);
            str1=wxString::Format(_("%.5f"),mtg->mp.prism[5]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),mp.prism[6]);
            str1=wxString::Format(_("%.5f"),mtg->mp.prism[6]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),mp.prism[7]);
            str1=wxString::Format(_("%.5f"),mtg->mp.prism[7]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
            str=wxString::Format(_("%.5f"),mp.prism[8]);
            str1=wxString::Format(_("%.5f"),mtg->mp.prism[8]);
            if(str.Cmp(str1)!=0)
            {
                m1Modified=1;
                modified[page]=1;
                return;
            }
        }
        else if(page==8)
        {
            modified[page]=0;
            str=setMeasTime->GetValue();
            str.ToDouble(&dbval);
            measet.cyc=dbval;
            str=setBackTime->GetValue();
            str.ToDouble(&dbval);
            measet.bcyc=dbval;
            str=setDev1->GetValue();
            str.ToDouble(&dbval);
            measet.palw=dbval;
            str=setDev2->GetValue();
            str.ToDouble(&dbval);
            measet.jalw=dbval;
            str=setDev3->GetValue();
            str.ToDouble(&dbval);
            measet.balw=dbval;
            str=setDev4->GetValue();
            str.ToDouble(&dbval);
            measet.talw=dbval;
            str=setDev5->GetValue();
            str.ToDouble(&dbval);
            measet.aalw=dbval;
            if(measet.tgap!=mtg->iset.tgap)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.symtype!=mtg->iset.symtype)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.backflag!=mtg->iset.backflag)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.plctype!=mtg->iset.plctype)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.cyc!=mtg->iset.cyc)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.bcyc!=mtg->iset.bcyc)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.palw!=mtg->iset.palw)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.jalw!=mtg->iset.jalw)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.balw!=mtg->iset.balw)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.talw!=mtg->iset.talw)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.aalw!=mtg->iset.aalw)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.vibration!=mtg->iset.vibration)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.rstn!=mtg->iset.rstn)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.tsyn!=mtg->iset.tsyn)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.rget!=mtg->iset.rget)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.idrv!=mtg->iset.idrv)
            {
                settingModified=1;
                modified[page]=1;
                //wxMessageBox(_("ok"));
                return;
            }
            if(measet.prun!=mtg->iset.prun)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.pend!=mtg->iset.pend)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.psas!=mtg->iset.psas)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.pchk!=mtg->iset.pchk)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.pqry!=mtg->iset.pqry)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.pmap!=mtg->iset.pmap)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.psmr!=mtg->iset.psmr)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.pquit!=mtg->iset.pquit)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
        }
        else if(page==9)
        {
            modified[page]=0;
            if(measet.unit!=mtg->iset.unit)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.vmileage!=mtg->iset.vmileage)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.head!=mtg->iset.head)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.tbm3d!=mtg->iset.tbm3d)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.trend!=mtg->iset.trend)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.tailapply!=mtg->iset.tailapply)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.povr!=mtg->iset.povr)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.jovr!=mtg->iset.jovr)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.tovr!=mtg->iset.tovr)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.bovr!=mtg->iset.bovr)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
            if(measet.toEr!=mtg->iset.toEr)
            {
                settingModified=1;
                modified[page]=1;
                return;
            }
        }
        else if(page==10)
        {
            modified[page]=0;
            if(nuser!=mtg->nuser)
            {
                userModified=1;
                modified[page]=1;
                return;
            }
            else
            {
                int i;
                for(i=0;i<nuser;i++)
                {
                    str=wxString(user[i].name,wxConvUTF8);
                    str1=wxString(mtg->user[i].name,wxConvUTF8);
                    if(str.Cmp(str1)!=0)
                    {
                        userModified=1;
                        modified[page]=1;
                        break;
                    }
                    str=wxString(user[i].password,wxConvUTF8);
                    str1=wxString(mtg->user[i].password,wxConvUTF8);
                    if(str.Cmp(str1)!=0)
                    {
                        userModified=1;
                        modified[page]=1;
                        break;
                    }
                    if(user[i].level!=mtg->user[i].level)
                    {
                        userModified=1;
                        modified[page]=1;
                        break;
                    }
                }
            }
        }
        else if(page==11)
        {
            modified[page]=0;
            if(measet.lang!=mtg->iset.lang)
            {
                settingModified=1;
                modified[page]=1;
            }
        }
    }

}

void ConfigDlg::OnTimer(wxTimerEvent& event)
{
    static int tick=0;
    int i=0;
    double dbval=0.0;
    wxString str;
    if(mtg->ithread==MTG_THREAD_SIM || mtg->ithread==MTG_THREAD_ORIGIN)
    {
        if(mtg->plog > 0)
        {
            wxString strLog;
            for(i=0;i<mtg->plog;i++)
            {
                strLog = wxString(mtg->plogs[i].msg,wxConvLocal);
                WriteMsg(strLog,mtg->plogs[i].type);
                if(mtg->plogs[i].nlog==MTG_LOG_FINISH_ORIGIN)
                {
                    //m1.prism[0]=mtg->m.prism[0];
                    //m1.prism[1]=mtg->m.prism[1];
                    //m1.prism[2]=mtg->m.prism[2];
                    //m1.inc[0]=mtg->m.inc[0];
                    //m1.inc[1]=mtg->m.inc[1];
                    //m1.inc[2]=mtg->m.inc[2];
                    //trace(0,"config:x=%.4f,y=%.4f,z=%.4f\n",m1.prism[0],m1.prism[1],m1.prism[2]);
                    m1=mtg->m;
                    //trace(0,"config:x=%.4f,y=%.4f,z=%.4f\n",m1.prism[0],m1.prism[1],m1.prism[2]);
                    wxString str;
                    double dbval=0;
                    if(mtg->tarset.baseinc==1)
                        dbval=m1.inc[5]*PI/180.0;
                    else
                        dbval=m1.inc[0]*PI/180.0;
                    str=wxString::Format(_("%.5f"),rad2dms(dbval));
                    m1Inc1->SetValue(str);

                    if(mtg->tarset.baseinc==1)
                        dbval=m1.inc[6]*PI/180.0;
                    else
                        dbval=m1.inc[1]*PI/180.0;
                    str=wxString::Format(_("%.5f"),rad2dms(dbval));
                    m1Inc2->SetValue(str);

                    dbval=m1.inc[2]*PI/180.0;
                    str=wxString::Format(_("%.5f"),rad2dms(dbval));
                    m1Inc3->SetValue(str);

                    str=wxString::Format(_("%.4f"),m1.prism[0]);
                    m1Prism1->SetValue(str);
                    str=wxString::Format(_("%.4f"),m1.prism[1]);
                    m1Prism2->SetValue(str);
                    str=wxString::Format(_("%.4f"),m1.prism[2]);
                    //trace(0,"fig:x=%.4f,y=%.4f,z=%.4f\n",m1.prism[0],m1.prism[1],m1.prism[2]);
                    //trace(0,"fig:x=%.4f,y=%.4f,z=%.4f\n",mtg->m.prism[0],mtg->m.prism[1],mtg->m.prism[2]);
                    m1Prism3->SetValue(str);
                    m1Modified=1;
                    modified[7]=1;
                    panelBottom->Refresh();
                    ///20190306whq add
                    m1TimePanel->Refresh();
                    mtg->ithread=-1;
                }
            }
            mtg->plog=0;
        }
    }

    tick++;
    if(tick % 5==0)
    {
        IsModified();
        panelBottom->Refresh();
    }
    if(tick==1200) tick=0;
}

