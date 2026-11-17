///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ConfigDlg.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"
#include "confirmdlg.h"
#include "dmsrad.h"
#include "geometry.h"
#include "SegDialog.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>

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


const long ConfigDlg::ID_PANEL1 = wxNewId();                  //标题
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
    bmpImportPrj[0].LoadFile(path+_("/plugins/prj_import1.png"),wxBITMAP_TYPE_PNG);
    bmpImportPrj[1].LoadFile(path+_("/plugins/prj_import2.png"),wxBITMAP_TYPE_PNG);
    bmpExportPrj[0].LoadFile(path+_("/plugins/prj_export1.png"),wxBITMAP_TYPE_PNG);
    bmpExportPrj[1].LoadFile(path+_("/plugins/prj_export2.png"),wxBITMAP_TYPE_PNG);
    bmpClearPrj[0].LoadFile(path+_("/plugins/prj_clear1.png"),wxBITMAP_TYPE_PNG);
    bmpClearPrj[1].LoadFile(path+_("/plugins/prj_clear2.png"),wxBITMAP_TYPE_PNG);
    bmpTPS1.LoadFile(path+_("/plugins/TS15G.png"),wxBITMAP_TYPE_PNG);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x,y;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	this->GetClientSize(&w,&h);
	panelTitle = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelTitle->IsMaximinize=0;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("参数设置");
    panelButtonList = new MDButtonList(this, ID_PANEL2, wxPoint(0,31), wxSize(150,h-76), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(150,31), wxSize(w-150,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelNavi = new wxPanel(panelMain, wxID_ANY, wxPoint(600+w,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    w1=w-150;
    h1=h-88;
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
    prjStaticText6 = new wxStaticText(panelPrj, wxID_ANY, _("值班设置"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prjLine2 = new wxStaticLine(panelPrj, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=30;
    prjStaticText7 = new wxStaticText(panelPrj, wxID_ANY, _("值班班数"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prjDutyPanel = new wxPanel(panelPrj, wxID_ANY, wxPoint(x1+65,y1-3), wxSize(120,23), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    prjDutyPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y1+=35;
    h2=62;

    prjStaticText8 = new wxStaticText(panelPrj, wxID_ANY, _("班组[一]"), wxPoint(x1,y1+h2/2-8), wxDefaultSize, 0, _("wxID_ANY"));
    prjTime1Panel = new wxPanel(panelPrj, wxID_ANY, wxPoint(x1+65,y1), wxSize(235,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    prjTime1Panel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    prjDuty1hour1 = new wxMyTextCtrl(prjTime1Panel, wxID_ANY, wxEmptyString, wxPoint(1,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty1min1 = new wxMyTextCtrl(prjTime1Panel, wxID_ANY, wxEmptyString, wxPoint(51,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty1hour2 = new wxMyTextCtrl(prjTime1Panel, wxID_ANY, wxEmptyString, wxPoint(121,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty1min2 = new wxMyTextCtrl(prjTime1Panel, wxID_ANY, wxEmptyString, wxPoint(171,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    prjStaticText9 = new wxStaticText(panelPrj, wxID_ANY, _("班组[二]"), wxPoint(x1+315,y1+h2/2-8), wxDefaultSize, 0, _("wxID_ANY"));
    prjTime2Panel = new wxPanel(panelPrj, wxID_ANY, wxPoint(x1+380,y1), wxSize(235,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    prjTime2Panel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    prjDuty2hour1 = new wxMyTextCtrl(prjTime2Panel, wxID_ANY, wxEmptyString, wxPoint(1,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty2min1 = new wxMyTextCtrl(prjTime2Panel, wxID_ANY, wxEmptyString, wxPoint(51,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty2hour2 = new wxMyTextCtrl(prjTime2Panel, wxID_ANY, wxEmptyString, wxPoint(121,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty2min2 = new wxMyTextCtrl(prjTime2Panel, wxID_ANY, wxEmptyString, wxPoint(171,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    y1=y1+h2+10;
    prjStaticText10 = new wxStaticText(panelPrj, wxID_ANY, _("班组[三]"), wxPoint(x1,y1+h2/2-8), wxDefaultSize, 0, _("wxID_ANY"));
    prjTime3Panel = new wxPanel(panelPrj, wxID_ANY, wxPoint(x1+65,y1), wxSize(235,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    prjTime3Panel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    prjDuty3hour1 = new wxMyTextCtrl(prjTime3Panel, wxID_ANY, wxEmptyString, wxPoint(1,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty3min1 = new wxMyTextCtrl(prjTime3Panel, wxID_ANY, wxEmptyString, wxPoint(51,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty3hour2 = new wxMyTextCtrl(prjTime3Panel, wxID_ANY, wxEmptyString, wxPoint(121,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty3min2 = new wxMyTextCtrl(prjTime3Panel, wxID_ANY, wxEmptyString, wxPoint(171,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjStaticText11 = new wxStaticText(panelPrj, wxID_ANY, _("班组[四]"), wxPoint(x1+315,y1+h2/2-8), wxDefaultSize, 0, _("wxID_ANY"));
    prjTime4Panel = new wxPanel(panelPrj, wxID_ANY, wxPoint(x1+380,y1), wxSize(235,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    prjTime4Panel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    prjDuty4hour1 = new wxMyTextCtrl(prjTime4Panel, wxID_ANY, wxEmptyString, wxPoint(1,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty4min1 = new wxMyTextCtrl(prjTime4Panel, wxID_ANY, wxEmptyString, wxPoint(51,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty4hour2 = new wxMyTextCtrl(prjTime4Panel, wxID_ANY, wxEmptyString, wxPoint(121,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    prjDuty4min2 = new wxMyTextCtrl(prjTime4Panel, wxID_ANY, wxEmptyString, wxPoint(171,h2/2-7), wxSize(43,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelKey = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
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
    h2=h1-y1-18;
    keyFigPanel = new wxPanel(panelKey, wxID_ANY, wxPoint(x1,y1), wxSize(w2/3,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    keyFigPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x2=x1+w2/3+10;
    keyGridPanel = new wxPanel(panelKey, wxID_ANY, wxPoint(x2,y1), wxSize(w2*2/3-10,h2-91), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    keyGridPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    keyList = new wxListView(keyGridPanel, wxID_ANY, wxPoint(0,24), wxSize(w2*2/3-10,h2-115), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    y1=y1+h2-76;
    w2=w2/6-2;
    keyStaticText7 = new wxStaticText(panelKey, wxID_ANY, _("区域名称"), wxPoint(x2,y1), wxDefaultSize, 0, _("wxID_ANY"));
    keyStaticText8 = new wxStaticText(panelKey, wxID_ANY, _("起点里程"), wxPoint(x2+w2*2,y1), wxDefaultSize, 0, _("wxID_ANY"));
    keyStaticText9 = new wxStaticText(panelKey, wxID_ANY, _("终点里程"), wxPoint(x2+w2*3,y1), wxDefaultSize, 0, _("wxID_ANY"));
    y1=y1+20;
    keyName = new wxMyTextCtrl(panelKey, wxID_ANY, wxEmptyString, wxPoint(x2,y1), wxSize(w2*2-1,-1), 0);
    keyMile1 = new wxMyTextCtrl(panelKey, wxID_ANY, wxEmptyString, wxPoint(x2+w2*2,y1), wxSize(w2-1,-1), 0);
    keyMile2 = new wxMyTextCtrl(panelKey, wxID_ANY, wxEmptyString, wxPoint(x2+w2*3,y1), wxSize(w2-1,-1), 0);
    y1+=30;
    w2=w1-x1*2;
    w2=w2*2/3-10;
    keyButton1Panel = new wxPanel(panelKey, wxID_ANY, wxPoint(x2,y1), wxSize(w2,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    keyButton1Panel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelTbm = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTbm->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    tbmStaticText1 = new wxStaticText(panelTbm, wxID_ANY, _("盾构信息"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tbmLine1 = new wxStaticLine(panelTbm, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=30;
    tbmStaticText2 = new wxStaticText(panelTbm, wxID_ANY, _("盾构编号"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tbmIndex = new wxMyTextCtrl(panelTbm, wxID_ANY, wxEmptyString, wxPoint(x1+60,y1-3), wxSize(180,-1), 0);
    tbmStaticText3 = new wxStaticText(panelTbm, wxID_ANY, _("铰接类型"), wxPoint(x1+265,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tbmKinkPanel = new wxPanel(panelTbm, wxID_ANY, wxPoint(x1+325,y1-4), wxSize(260,23), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tbmKinkPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y1+=30;
    tbmStaticText4 = new wxStaticText(panelTbm, wxID_ANY, _("几何参数"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tbmLine2 = new wxStaticLine(panelTbm, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=30;
    tbmFigPanel = new wxPanel(panelTbm, wxID_ANY, wxPoint(x1,y1-5), wxSize(343,385), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tbmFigPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    tbmSettingPanel = new wxPanel(panelTbm, wxID_ANY, wxPoint(x1+353,y1-5), wxSize(w2-353,385), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tbmSettingPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1+=363;
    tbmL0 = new wxMyTextCtrl(tbmSettingPanel, wxID_ANY, wxEmptyString, wxPoint(125,2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL4 = new wxMyTextCtrl(tbmSettingPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL1 = new wxMyTextCtrl(tbmSettingPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL3 = new wxMyTextCtrl(tbmSettingPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL2 = new wxMyTextCtrl(tbmSettingPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmD4 = new wxMyTextCtrl(tbmSettingPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmD5 = new wxMyTextCtrl(tbmSettingPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelTars = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTars->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    y1+=7;
    tarsStaticText2 = new wxStaticText(panelTars, wxID_ANY, _("配置文件"), wxPoint(x1+1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tarsFile = new wxMyTextCtrl(panelTars, wxID_ANY, wxEmptyString, wxPoint(x1+60,y1-4), wxSize(210,25), 0);
    tarsFile->Enable(false);
    tarsStaticText3 = new wxStaticText(panelTars, wxID_ANY, _("棱镜常数"), wxPoint(x1+280,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prismPanel = new wxPanel(panelTars, wxID_ANY, wxPoint(x1+340,y1-4), wxSize(120,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    prismPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    tarsPrism = new wxMyTextCtrl(prismPanel, wxID_ANY, wxEmptyString, wxPoint(x1+340,y1-4), wxSize(120,25), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    tarsButton = new wxPanel(panelTars, wxID_ANY, wxPoint(w2-137+x1,y1-4), wxSize(137,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tarsButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y1+=27;
    tarsStaticText1 = new wxStaticText(panelTars, wxID_ANY, _("示意图"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tarsLine1 = new wxStaticLine(panelTars, wxID_ANY, wxPoint(x1+38,y1+8), wxSize(w2-38,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    h2=h1-y1-25;
    tarsFig = new wxPanel(panelTars, wxID_ANY, wxPoint(x1,y1), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tarsFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelTps = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTps->SetBackgroundColour(wxColor(239,239,239));

    x1=14;
    y1=9;
    w2=w1-x1*2;
    tpsStaticText1 = new wxStaticText(panelTps, wxID_ANY, _("全站仪"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tpsLine1 = new wxStaticLine(panelTps, wxID_ANY, wxPoint(x1+35,y1+8), wxSize(w2-38,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    tpsFigPanel = new wxPanel(panelTps, wxID_ANY, wxPoint(x1,y1), wxSize(w2-3,h1-y1-18), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tpsFigPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    tpsLaserDist = new wxMyTextCtrl(tpsFigPanel, wxID_ANY, wxEmptyString, wxPoint(x1+60,y1-2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    tpsLaserDevX = new wxMyTextCtrl(tpsFigPanel, wxID_ANY, _(" mm"), wxPoint(x1+250,y1-2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    tpsLaserDevY = new wxMyTextCtrl(tpsFigPanel, wxID_ANY, _(" mm"), wxPoint(x1+450,y1-2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelSeg = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
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

    panelBlock = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBlock->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    w2=w2/2-10;
    h2=h1-y1-18;
    blkFigPanel = new wxPanel(panelBlock, wxID_ANY, wxPoint(x1,y1), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    blkFigPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x2=x1+w2+10;
    blkGridPanel = new wxPanel(panelBlock, wxID_ANY, wxPoint(x2,y1), wxSize(w2,h2-91), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    blkGridPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    blockList = new wxListView(blkGridPanel, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-115), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    y1=h2-66;
    w2=w2/3;
    blkStaticText4 = new wxStaticText(panelBlock, wxID_ANY, _("序号"), wxPoint(x2,y1), wxDefaultSize, 0, _("wxID_ANY"));
    blkStaticText2 = new wxStaticText(panelBlock, wxID_ANY, _("管块名称"), wxPoint(x2+w2,y1), wxDefaultSize, 0, _("wxID_ANY"));
    blkStaticText3 = new wxStaticText(panelBlock, wxID_ANY, _("圆心角(°)"), wxPoint(x2+w2*2,y1), wxDefaultSize, 0, _("wxID_ANY"));
    y1=y1+20;
    blkID = new wxMyTextCtrl(panelBlock, wxID_ANY, wxEmptyString, wxPoint(x2,y1), wxSize(w2-1,-1), 0);
    blkID->Enable(false);
    blkName = new wxMyTextCtrl(panelBlock, wxID_ANY, wxEmptyString, wxPoint(x2+w2,y1), wxSize(w2-1,-1), 0);
    blkAngle = new wxMyTextCtrl(panelBlock, wxID_ANY, wxEmptyString, wxPoint(x2+w2*2,y1), wxSize(w2-1,-1), 0);
    y1+=30;
    blkButton1Panel = new wxPanel(panelBlock, wxID_ANY, wxPoint(x2,y1), wxSize(w2*3,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    blkButton1Panel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelM1 = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
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
    m1Line1 = new wxStaticLine(panelM1, wxID_ANY, wxPoint(x1+38,y1+8), wxSize(w2-38,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));

    int x5=x1;
    int y5=y1+25;

    m1StaticText2 = new wxStaticText(panelM1, wxID_ANY, _("切口"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
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

    x5=x1;
    y5+=30;
    m1StaticText6 = new wxStaticText(panelM1, wxID_ANY, _("铰接"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=45;
    m1Mid1 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1Mid2 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1Mid3 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);

    x5=x1;
    y5+=30;
    m1StaticText10 = new wxStaticText(panelM1, wxID_ANY, _("盾尾"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
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
    y5+=55;
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
    m1StaticText31 = new wxStaticText(panelM1, wxID_ANY, _("2#盾尾"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=45;
    m1CP21 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1CP22 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1CP23 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);

    x5=x1;
    y5+=30;
    m1StaticText32 = new wxStaticText(panelM1, wxID_ANY, _("3#盾尾"), wxPoint(x5,y5+18), wxDefaultSize, 0, _("wxID_ANY"));
    x5+=45;
    m1CP31 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1CP32 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);
    x5+=w5;
    m1CP33 = new wxMyTextCtrl(panelM1, wxID_ANY, wxEmptyString, wxPoint(x5,y5+15), wxSize(w5-7,h5), 0);

    x5=x1;
    y5+=35;
    h5=h1-y5-38;
    m1FigPanel = new wxPanel(panelM1, wxID_ANY, wxPoint(x5+45,y5+15), wxSize(w4-45,h5), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    m1FigPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    m1FigPanel->Show(false);

    m1ButtonPanel = new wxPanel(panelM1, wxID_ANY, wxPoint(x1+w2-w3,y1), wxSize(w3,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    m1ButtonPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelRem = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelRem->SetBackgroundColour(wxColor(239,239,239));

    x1=14;
    y1=14;
    remStaticText2 = new wxStaticText(panelRem, wxID_ANY, _("主机IP地址"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    remBgPanel = new wxPanel(panelRem, wxID_ANY, wxPoint(x1+65,y1-4), wxSize(152,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    remBgPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    remIP1 = new wxMyTextCtrl(remBgPanel, wxID_ANY, wxEmptyString, wxPoint(3,5), wxSize(35,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    remIP2 = new wxMyTextCtrl(remBgPanel, wxID_ANY, wxEmptyString, wxPoint(40,5), wxSize(35,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    remIP3 = new wxMyTextCtrl(remBgPanel, wxID_ANY, wxEmptyString, wxPoint(77,5), wxSize(35,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    remIP4 = new wxMyTextCtrl(remBgPanel, wxID_ANY, wxEmptyString, wxPoint(114,5), wxSize(35,17), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelSet = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
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
    y1+=65;
    setStaticText3 = new wxStaticText(panelSet, wxID_ANY, _("功能设置"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    setLine3 = new wxStaticLine(panelSet, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    funPanel = new wxPanel(panelSet, wxID_ANY, wxPoint(x1,y1), wxSize(w2,245), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    funPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    setLine4 = new wxStaticLine(funPanel, wxID_ANY, wxPoint(50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));

    panelUI = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelUI->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    uiStaticText1 = new wxStaticText(panelUI, wxID_ANY, _("界面显示"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    uiLine1 = new wxStaticLine(panelUI, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    uiElementPanel = new wxPanel(panelUI, wxID_ANY, wxPoint(x1,y1), wxSize(w2,185), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    uiElementPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y1+=190;
    uiStaticText2 = new wxStaticText(panelUI, wxID_ANY, _("警示设置"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    uiLine2 = new wxStaticLine(panelUI, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=25;
    uiCautionPanel = new wxPanel(panelUI, wxID_ANY, wxPoint(x1,y1), wxSize(w2,185), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    uiCautionPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelSMonitor = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSMonitor->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2;
    smOnOff = new wxPanel(panelSMonitor, wxID_ANY, wxPoint(x1+5,y1), wxSize(w2-5,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    smOnOff->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    smLine1 = new wxStaticLine(panelSMonitor, wxID_ANY, wxPoint(x1,y1+25), wxSize(w2,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    x5=x1+5;
    y5=y1+40;
    w5=120;
    h5=22;
    smStaticText1 = new wxStaticText(panelSMonitor, wxID_ANY, _("管环编号"), wxPoint(x5,y5), wxDefaultSize, 0, _("wxID_ANY"));
    smNumber = new wxMyTextCtrl(panelSMonitor, wxID_ANY, wxEmptyString, wxPoint(x5+80,y5-4), wxSize(w5,h5), wxTE_RIGHT);
    y5+=30;
    smStaticText2 = new wxStaticText(panelSMonitor, wxID_ANY, _("时间间隔"), wxPoint(x5,y5), wxDefaultSize, 0, _("wxID_ANY"));
    smTimePanel = new wxPanel(panelSMonitor, wxID_ANY, wxPoint(x5+80,y5-4), wxSize(w5,h5), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    smTimePanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    smTime = new wxMyTextCtrl(smTimePanel, wxID_ANY,wxEmptyString, wxPoint(1,4), wxSize(w5-24,16), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y5+=30;
    smStaticText3 = new wxStaticText(panelSMonitor, wxID_ANY, _("持续监测"), wxPoint(x5,y5), wxDefaultSize, 0, _("wxID_ANY"));
    smLastPanel = new wxPanel(panelSMonitor, wxID_ANY, wxPoint(x5+80,y5-4), wxSize(w5,h5), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    smLastPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    smLast = new wxMyTextCtrl(smLastPanel, wxID_ANY,wxEmptyString, wxPoint(1,4), wxSize(w5-24,16), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y5+=30;
    smStaticText4 = new wxStaticText(panelSMonitor, wxID_ANY, _("初始位置"), wxPoint(x5,y5), wxDefaultSize, 0, _("wxID_ANY"));
    smPosPanel = new wxPanel(panelSMonitor, wxID_ANY, wxPoint(x5+80,y5-4), wxSize(w5*3+30,h5), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    smPosPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    smX = new wxMyTextCtrl(smPosPanel, wxID_ANY,wxEmptyString, wxPoint(23,4), wxSize(w5-26,16), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    smY = new wxMyTextCtrl(smPosPanel, wxID_ANY,wxEmptyString, wxPoint(w5+33,4), wxSize(w5-26,16), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    smZ = new wxMyTextCtrl(smPosPanel, wxID_ANY,wxEmptyString, wxPoint(w5*2+43,4), wxSize(w5-26,16), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelUser = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
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

    panelLanguage = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
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

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintBackground,0,this);
	panelNavi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintNavi,0,this);

    prjDutyPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintDuty,0,this);
    prjDutyPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionDuty,0,this);
    prjDutyPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveDuty,0,this);
    prjDutyPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickDuty,0,this);

    prjTime1Panel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTime1,0,this);
    prjTime1Panel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionTime1,0,this);
    prjTime1Panel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveTime1,0,this);
    prjTime1Panel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickTime1,0,this);

    prjTime2Panel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTime2,0,this);
    prjTime2Panel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionTime2,0,this);
    prjTime2Panel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveTime2,0,this);
    prjTime2Panel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickTime2,0,this);

    prjTime3Panel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTime3,0,this);
    prjTime3Panel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionTime3,0,this);
    prjTime3Panel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveTime3,0,this);
    prjTime3Panel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickTime3,0,this);

    prjTime4Panel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTime4,0,this);
    prjTime4Panel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionTime4,0,this);
    prjTime4Panel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveTime4,0,this);
    prjTime4Panel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickTime4,0,this);

    keyRoadPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintRoad,0,this);
    keyRoadPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionRoad,0,this);
    keyRoadPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveRoad,0,this);
    keyRoadPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickRoad,0,this);

    keyFigPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintKeyFig,0,this);
    keyGridPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintKeyGrid,0,this);

    keyButton1Panel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintKeyButton1,0,this);
    keyButton1Panel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionKeyButton1,0,this);
    keyButton1Panel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveKeyButton1,0,this);
    keyButton1Panel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickKeyButton1,0,this);

    keyList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&ConfigDlg::OnListKeySelect,0,this);
    keyList->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&ConfigDlg::OnListKeyDeselect,0,this);

    tbmKinkPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintKink,0,this);
    tbmKinkPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionKink,0,this);
    tbmKinkPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveKink,0,this);
    tbmKinkPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickKink,0,this);

    tbmFigPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTbmFig,0,this);
    tbmSettingPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTbmSetting,0,this);

    prismPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintPrismPanel,0,this);
    tarsButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTarButton,0,this);
    tarsButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionTarButton,0,this);
    tarsButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveTarButton,0,this);
    tarsButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickTarButton,0,this);

    tarsFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintTarFig,0,this);

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

    blkGridPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintBlkGrid,0,this);
    blkFigPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintBlkFig,0,this);

    m1ButtonPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintM1Button,0,this);
    m1ButtonPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionM1Button,0,this);
    m1ButtonPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveM1Button,0,this);
    m1ButtonPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickM1Button,0,this);

    m1FigPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintM1Fig,0,this);

    remBgPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintRemBg,0,this);

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

    smOnOff->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintSmOnOff,0,this);
    smOnOff->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfigDlg::OnMotionSmOnOff,0,this);
    smOnOff->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfigDlg::OnLeaveSmOnOff,0,this);
    smOnOff->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnClickSmOnOff,0,this);

    smTimePanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintSmTime,0,this);
    smLastPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintSmLast,0,this);
    smPosPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfigDlg::OnPaintSmPos,0,this);

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

    panelButtonList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfigDlg::OnButtonClick,0,this);

    //tbmD0->Connect(wxEVT_LEFT_UP, (wxObjectEventFunction)&ConfigDlg::OnTbmD0Click,0,this);
    //tbmD1->Connect(wxEVT_LEFT_UP, (wxObjectEventFunction)&ConfigDlg::OnTbmD1Click,0,this);

    //tbmD3->Connect(wxEVT_LEFT_UP, (wxObjectEventFunction)&ConfigDlg::OnTbmD3Click,0,this);
    //tbmD6->Connect(wxEVT_LEFT_UP, (wxObjectEventFunction)&ConfigDlg::OnTbmD6Click,0,this);

    //*)

    Connect(wxEVT_TIMER,(wxObjectEventFunction)&ConfigDlg::OnTimer);
    timerStat.SetOwner(this);
    timerStat.Start(100,false);

    this->SetBackgroundColour(wxColor(245,248,250));

    panelButtonList->btn_height=30;
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
    panelButtonList->AddButton(_("远程监控"));
    panelButtonList->AddButton(_("用户权限"));
    panelButtonList->AddButton(_("语言设置"));
    panelButtonList->btn_clicked=0;
    int i=panelButtonList->GetNumberButtons();
    modified=(int*)malloc(i*sizeof(int));
    memset(modified,0,i);

    i=0;
    keyList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,65);
    keyList->InsertColumn(i++,_("名称"),wxLIST_FORMAT_LEFT,120);
    keyList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,85);
    keyList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,85);


    i=0;
    blockList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,85);
    blockList->InsertColumn(i++,_("名称"),wxLIST_FORMAT_CENTRE,85);
    blockList->InsertColumn(i++,_("圆心角"),wxLIST_FORMAT_CENTRE,85);

    i=0;
    userList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    userList->InsertColumn(i++,_("名称"),wxLIST_FORMAT_CENTRE,130);
    userList->InsertColumn(i++,_("密码"),wxLIST_FORMAT_CENTRE,130);
    userList->InsertColumn(i++,_("权限"),wxLIST_FORMAT_CENTRE,130);

    //memDC.SetBrush(wxBrush(wxColor(204,255,177)));

    checkBoxWidth=14;
    checkBoxHeight=14;
    radioBoxR1=7;
    radioBoxR2=4;


    m_msg=wxEmptyString;
    m_msgc=0;
    for(int i=0;i<20;i++)
    {
        settingErr[i]=0;
    }

    prjModified=keyModified=tbmModified=tarsModified=tpsModified=segModified=blockModified=m1Modified=settingModified=userModified=0;
    LoadDataBase();
}

ConfigDlg::~ConfigDlg()
{
    //confDlg=0;
}

void ConfigDlg::OnButtonClick(wxMouseEvent& event)
{
    int btn = panelButtonList->btn_left_down;
    int w,h;
    panelPrj->GetClientSize(&w,&h);

    switch(btn)
    {
    case 0:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelPrj->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 1:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelTars->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelKey->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 2:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelTbm->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 3:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelTars->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 4:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelTps->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 5:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelSeg->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 6:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelBlock->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 7:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelM1->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 8:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelSet->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 9:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelUI->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 10:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 11:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelRem->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 12:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelLanguage->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelUser->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    case 13:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelKey->SetSize(1024,11,w,h);
        panelPrj->SetSize(1024,11,w,h);
        panelTbm->SetSize(1024,11,w,h);
        panelSeg->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelTars->SetSize(1024,11,w,h);
        panelBlock->SetSize(1024,11,w,h);
        panelM1->SetSize(1024,11,w,h);
        panelRem->SetSize(1024,11,w,h);
        panelSet->SetSize(1024,11,w,h);
        panelUI->SetSize(1024,11,w,h);
        panelUser->SetSize(1024,11,w,h);
        panelSMonitor->SetSize(1024,11,w,h);
        panelLanguage->SetSize(0,11,w,h);
        op1=ID_FIG_NONE;
        break;
    default:
        break;
    }
}

void ConfigDlg::MeasurementInfomation(wxString msg)
{
    //m1Msg=msg;
    m1ButtonPanel->Refresh();
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
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
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
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        memDC.SetTextForeground(btnTextColor[0]);
        memDC.DrawLabel(wxString::Format(_("%d"),prj.duty),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

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
        if(prj.duty<4)
        {
            prj.duty+=1;
            //prjModified=1;
        }
    }
    else if(motion1==ID_FIG_DUTY_SUB)
    {
        if(prj.duty>1)
        {
            prj.duty-=1;
            //prjModified=1;
        }
    }

    if(prj.duty==1)
    {
        prjStaticText9->Show(false);
        prjStaticText10->Show(false);
        prjStaticText11->Show(false);
        prjTime2Panel->Show(false);
        prjTime3Panel->Show(false);
        prjTime4Panel->Show(false);
        prjDuty1hour1->SetFocus();
        prjDuty1hour1->SetSelection(-1,-1);
    }
    else if(prj.duty==2)
    {
        prjStaticText9->Show(true);
        prjStaticText10->Show(false);
        prjStaticText11->Show(false);
        prjTime2Panel->Show(true);
        prjTime3Panel->Show(false);
        prjTime4Panel->Show(false);
        prjDuty2hour1->SetFocus();
        prjDuty2hour1->SetSelection(-1,-1);
    }
    else if(prj.duty==3)
    {
        prjStaticText9->Show(true);
        prjStaticText10->Show(true);
        prjStaticText11->Show(false);
        prjTime2Panel->Show(true);
        prjTime3Panel->Show(true);
        prjTime4Panel->Show(false);
        prjDuty3hour1->SetFocus();
        prjDuty3hour1->SetSelection(-1,-1);
    }
    else if(prj.duty==4)
    {
        prjStaticText9->Show(true);
        prjStaticText10->Show(true);
        prjStaticText11->Show(true);
        prjTime2Panel->Show(true);
        prjTime3Panel->Show(true);
        prjTime4Panel->Show(true);
        prjDuty4hour1->SetFocus();
        prjDuty4hour1->SetSelection(-1,-1);
    }
    prjDutyPanel->Refresh();
    panelBottom->Refresh();
}

void ConfigDlg::OnPaintTime1(wxPaintEvent& event)
{
    wxPaintDC dc(prjTime1Panel);
    int w,h;
    prjTime1Panel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        h1=22;
        y1=h/2-h1/2;
        w1=95;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_(":"),wxRect(x1+45,y1,5,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("--"),wxRect(x1+w1,y1,25,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=120;
        h1=22;
        y1=h/2-11;
        w1=95;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_(":"),wxRect(x1+45,y1,5,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=0;
        y1=1;
        w1=w1/2+1;
        h1=20;
        figButton[ID_FIG_D1T1H_ADD].x=x1;
        figButton[ID_FIG_D1T1H_ADD].y=y1;
        figButton[ID_FIG_D1T1H_ADD].width=w1;
        figButton[ID_FIG_D1T1H_ADD].height=h1;
        if(motion1==ID_FIG_D1T1H_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D1T1M_ADD].x=x1;
        figButton[ID_FIG_D1T1M_ADD].y=y1;
        figButton[ID_FIG_D1T1M_ADD].width=w1;
        figButton[ID_FIG_D1T1M_ADD].height=h1;
        if(motion1==ID_FIG_D1T1M_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=0;
        y1=h/2+10;
        figButton[ID_FIG_D1T1H_SUB].x=x1;
        figButton[ID_FIG_D1T1H_SUB].y=y1;
        figButton[ID_FIG_D1T1H_SUB].width=w1;
        figButton[ID_FIG_D1T1H_SUB].height=h1;
        if(motion1==ID_FIG_D1T1H_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D1T1M_SUB].x=x1;
        figButton[ID_FIG_D1T1M_SUB].y=y1;
        figButton[ID_FIG_D1T1M_SUB].width=w1;
        figButton[ID_FIG_D1T1M_SUB].height=h1;
        if(motion1==ID_FIG_D1T1M_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=120;
        y1=1;
        figButton[ID_FIG_D1T2H_ADD].x=x1;
        figButton[ID_FIG_D1T2H_ADD].y=y1;
        figButton[ID_FIG_D1T2H_ADD].width=w1;
        figButton[ID_FIG_D1T2H_ADD].height=h1;
        if(motion1==ID_FIG_D1T2H_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D1T2M_ADD].x=x1;
        figButton[ID_FIG_D1T2M_ADD].y=y1;
        figButton[ID_FIG_D1T2M_ADD].width=w1;
        figButton[ID_FIG_D1T2M_ADD].height=h1;
        if(motion1==ID_FIG_D1T2M_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=120;
        y1=h/2+10;
        figButton[ID_FIG_D1T2H_SUB].x=x1;
        figButton[ID_FIG_D1T2H_SUB].y=y1;
        figButton[ID_FIG_D1T2H_SUB].width=w1;
        figButton[ID_FIG_D1T2H_SUB].height=h1;
        if(motion1==ID_FIG_D1T2H_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D1T2M_SUB].x=x1;
        figButton[ID_FIG_D1T2M_SUB].y=y1;
        figButton[ID_FIG_D1T2M_SUB].width=w1;
        figButton[ID_FIG_D1T2M_SUB].height=h1;
        if(motion1==ID_FIG_D1T2M_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionTime1(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_D1T1H_ADD].x && x<figButton[ID_FIG_D1T1H_ADD].x+figButton[ID_FIG_D1T1H_ADD].width)
    {
        if(y>figButton[ID_FIG_D1T1H_ADD].y && y<figButton[ID_FIG_D1T1H_ADD].y+figButton[ID_FIG_D1T1H_ADD].height)
        {
            motion1=ID_FIG_D1T1H_ADD;
        }
        else if(y>figButton[ID_FIG_D1T1H_SUB].y && y<figButton[ID_FIG_D1T1H_SUB].y+figButton[ID_FIG_D1T1H_SUB].height)
        {
            motion1=ID_FIG_D1T1H_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D1T1M_ADD].x && x<figButton[ID_FIG_D1T1M_ADD].x+figButton[ID_FIG_D1T1M_ADD].width)
    {
        if(y>figButton[ID_FIG_D1T1M_ADD].y && y<figButton[ID_FIG_D1T1M_ADD].y+figButton[ID_FIG_D1T1M_ADD].height)
        {
            motion1=ID_FIG_D1T1M_ADD;
        }
        else if(y>figButton[ID_FIG_D1T1M_SUB].y && y<figButton[ID_FIG_D1T1M_SUB].y+figButton[ID_FIG_D1T1M_SUB].height)
        {
            motion1=ID_FIG_D1T1M_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D1T2H_ADD].x && x<figButton[ID_FIG_D1T2H_ADD].x+figButton[ID_FIG_D1T2H_ADD].width)
    {
        if(y>figButton[ID_FIG_D1T2H_ADD].y && y<figButton[ID_FIG_D1T2H_ADD].y+figButton[ID_FIG_D1T2H_ADD].height)
        {
            motion1=ID_FIG_D1T2H_ADD;
        }
        else if(y>figButton[ID_FIG_D1T2H_SUB].y && y<figButton[ID_FIG_D1T2H_SUB].y+figButton[ID_FIG_D1T2H_SUB].height)
        {
            motion1=ID_FIG_D1T2H_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D1T2M_ADD].x && x<figButton[ID_FIG_D1T2M_ADD].x+figButton[ID_FIG_D1T2M_ADD].width)
    {
        if(y>figButton[ID_FIG_D1T2M_ADD].y && y<figButton[ID_FIG_D1T2M_ADD].y+figButton[ID_FIG_D1T2M_ADD].height)
        {
            motion1=ID_FIG_D1T2M_ADD;
        }
        else if(y>figButton[ID_FIG_D1T2M_SUB].y && y<figButton[ID_FIG_D1T2M_SUB].y+figButton[ID_FIG_D1T2M_SUB].height)
        {
            motion1=ID_FIG_D1T2M_SUB;
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
    prjTime1Panel->Refresh();
}

void ConfigDlg::OnLeaveTime1(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    prjTime1Panel->Refresh();
}

void ConfigDlg::OnClickTime1(wxMouseEvent& event)
{
    int t1,t2;
    wxString str1;
    if(motion1==ID_FIG_D1T1H_ADD)
    {
        t1=prj.t1[0]/3600;
        prj.t1[0]+=3600;
        if(t1<23)
        {
            t1++;
        }
        else
        {
            prj.t1[0]=prj.t1[0]-24*3600;
            t1=prj.t1[0]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty1hour1->SetValue(str1);
        prjDuty1hour1->SetFocus();
        prjDuty1hour1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D1T1H_SUB)
    {
        t1=prj.t1[0]/3600;
        prj.t1[0]-=3600;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            prj.t1[0]=prj.t1[0]+24*3600;
            t1=prj.t1[0]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty1hour1->SetValue(str1);
        prjDuty1hour1->SetFocus();
        prjDuty1hour1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D1T1M_ADD)
    {
        t2=prj.t1[0]/3600;
        t1=prj.t1[0]-t2*3600;
        t1=t1/60;
        if(t1<59)
        {
            t1++;
        }
        else
        {
            t1++;
            t1-=60;
        }
        prj.t1[0]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty1min1->SetValue(str1);
        prjDuty1min1->SetFocus();
        prjDuty1min1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D1T1M_SUB)
    {
        t2=prj.t1[0]/3600;
        t1=prj.t1[0]-t2*3600;
        t1=t1/60;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            t1--;
            t1+=60;
        }
        prj.t1[0]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty1min1->SetValue(str1);
        prjDuty1min1->SetFocus();
        prjDuty1min1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D1T2H_ADD)
    {
        t1=prj.t2[0]/3600;
        prj.t2[0]+=3600;
        if(t1<23)
        {
            t1++;
        }
        else
        {
            prj.t2[0]=prj.t2[0]-24*3600;
            t1=prj.t2[0]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty1hour2->SetValue(str1);
        prjDuty1hour2->SetFocus();
        prjDuty1hour2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D1T2H_SUB)
    {
        t1=prj.t2[0]/3600;
        prj.t2[0]-=3600;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            prj.t2[0]=prj.t2[0]+24*3600;
            t1=prj.t1[0]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty1hour2->SetValue(str1);
        prjDuty1hour2->SetFocus();
        prjDuty1hour2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D1T2M_ADD)
    {
        t2=prj.t2[0]/3600;
        t1=prj.t2[0]-t2*3600;
        t1=t1/60;
        if(t1<59)
        {
            t1++;
        }
        else
        {
            t1++;
            t1-=60;
        }
        prj.t2[0]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty1min2->SetValue(str1);
        prjDuty1min2->SetFocus();
        prjDuty1min2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D1T2M_SUB)
    {
        t2=prj.t2[0]/3600;
        t1=prj.t2[0]-t2*3600;
        t1=t1/60;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            t1--;
            t1+=60;
        }
        prj.t2[0]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty1min2->SetValue(str1);
        prjDuty1min2->SetFocus();
        prjDuty1min2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }

}

void ConfigDlg::OnPaintTime2(wxPaintEvent& event)
{
    wxPaintDC dc(prjTime2Panel);
    int w,h;
    prjTime2Panel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        h1=22;
        y1=h/2-h1/2;
        w1=95;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_(":"),wxRect(x1+45,y1,5,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("--"),wxRect(x1+w1,y1,25,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=120;
        h1=22;
        y1=h/2-11;
        w1=95;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_(":"),wxRect(x1+45,y1,5,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=0;
        y1=1;
        w1=w1/2+1;
        h1=20;
        figButton[ID_FIG_D2T1H_ADD].x=x1;
        figButton[ID_FIG_D2T1H_ADD].y=y1;
        figButton[ID_FIG_D2T1H_ADD].width=w1;
        figButton[ID_FIG_D2T1H_ADD].height=h1;
        if(motion1==ID_FIG_D2T1H_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D2T1M_ADD].x=x1;
        figButton[ID_FIG_D2T1M_ADD].y=y1;
        figButton[ID_FIG_D2T1M_ADD].width=w1;
        figButton[ID_FIG_D2T1M_ADD].height=h1;
        if(motion1==ID_FIG_D2T1M_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=0;
        y1=h/2+10;
        figButton[ID_FIG_D2T1H_SUB].x=x1;
        figButton[ID_FIG_D2T1H_SUB].y=y1;
        figButton[ID_FIG_D2T1H_SUB].width=w1;
        figButton[ID_FIG_D2T1H_SUB].height=h1;
        if(motion1==ID_FIG_D2T1H_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D2T1M_SUB].x=x1;
        figButton[ID_FIG_D2T1M_SUB].y=y1;
        figButton[ID_FIG_D2T1M_SUB].width=w1;
        figButton[ID_FIG_D2T1M_SUB].height=h1;
        if(motion1==ID_FIG_D2T1M_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=120;
        y1=1;
        figButton[ID_FIG_D2T2H_ADD].x=x1;
        figButton[ID_FIG_D2T2H_ADD].y=y1;
        figButton[ID_FIG_D2T2H_ADD].width=w1;
        figButton[ID_FIG_D2T2H_ADD].height=h1;
        if(motion1==ID_FIG_D2T2H_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D2T2M_ADD].x=x1;
        figButton[ID_FIG_D2T2M_ADD].y=y1;
        figButton[ID_FIG_D2T2M_ADD].width=w1;
        figButton[ID_FIG_D2T2M_ADD].height=h1;
        if(motion1==ID_FIG_D2T2M_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=120;
        y1=h/2+10;
        figButton[ID_FIG_D2T2H_SUB].x=x1;
        figButton[ID_FIG_D2T2H_SUB].y=y1;
        figButton[ID_FIG_D2T2H_SUB].width=w1;
        figButton[ID_FIG_D2T2H_SUB].height=h1;
        if(motion1==ID_FIG_D2T2H_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D2T2M_SUB].x=x1;
        figButton[ID_FIG_D2T2M_SUB].y=y1;
        figButton[ID_FIG_D2T2M_SUB].width=w1;
        figButton[ID_FIG_D2T2M_SUB].height=h1;
        if(motion1==ID_FIG_D2T2M_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionTime2(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_D2T1H_ADD].x && x<figButton[ID_FIG_D2T1H_ADD].x+figButton[ID_FIG_D2T1H_ADD].width)
    {
        if(y>figButton[ID_FIG_D2T1H_ADD].y && y<figButton[ID_FIG_D2T1H_ADD].y+figButton[ID_FIG_D2T1H_ADD].height)
        {
            motion1=ID_FIG_D2T1H_ADD;
        }
        else if(y>figButton[ID_FIG_D2T1H_SUB].y && y<figButton[ID_FIG_D2T1H_SUB].y+figButton[ID_FIG_D2T1H_SUB].height)
        {
            motion1=ID_FIG_D2T1H_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D2T1M_ADD].x && x<figButton[ID_FIG_D2T1M_ADD].x+figButton[ID_FIG_D2T1M_ADD].width)
    {
        if(y>figButton[ID_FIG_D2T1M_ADD].y && y<figButton[ID_FIG_D2T1M_ADD].y+figButton[ID_FIG_D2T1M_ADD].height)
        {
            motion1=ID_FIG_D2T1M_ADD;
        }
        else if(y>figButton[ID_FIG_D2T1M_SUB].y && y<figButton[ID_FIG_D2T1M_SUB].y+figButton[ID_FIG_D2T1M_SUB].height)
        {
            motion1=ID_FIG_D2T1M_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D2T2H_ADD].x && x<figButton[ID_FIG_D2T2H_ADD].x+figButton[ID_FIG_D2T2H_ADD].width)
    {
        if(y>figButton[ID_FIG_D2T2H_ADD].y && y<figButton[ID_FIG_D2T2H_ADD].y+figButton[ID_FIG_D2T2H_ADD].height)
        {
            motion1=ID_FIG_D2T2H_ADD;
        }
        else if(y>figButton[ID_FIG_D2T2H_SUB].y && y<figButton[ID_FIG_D2T2H_SUB].y+figButton[ID_FIG_D2T2H_SUB].height)
        {
            motion1=ID_FIG_D2T2H_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D2T2M_ADD].x && x<figButton[ID_FIG_D2T2M_ADD].x+figButton[ID_FIG_D2T2M_ADD].width)
    {
        if(y>figButton[ID_FIG_D2T2M_ADD].y && y<figButton[ID_FIG_D2T2M_ADD].y+figButton[ID_FIG_D2T2M_ADD].height)
        {
            motion1=ID_FIG_D2T2M_ADD;
        }
        else if(y>figButton[ID_FIG_D2T2M_SUB].y && y<figButton[ID_FIG_D2T2M_SUB].y+figButton[ID_FIG_D2T2M_SUB].height)
        {
            motion1=ID_FIG_D2T2M_SUB;
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
    prjTime2Panel->Refresh();
}

void ConfigDlg::OnLeaveTime2(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    prjTime2Panel->Refresh();
}

void ConfigDlg::OnClickTime2(wxMouseEvent& event)
{
    int t1,t2;
    wxString str1;
    if(motion1==ID_FIG_D2T1H_ADD)
    {
        t1=prj.t1[1]/3600;
        prj.t1[1]+=3600;
        if(t1<23)
        {
            t1++;
        }
        else
        {
            prj.t1[1]=prj.t1[1]-24*3600;
            t1=prj.t1[1]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty2hour1->SetValue(str1);
        prjDuty2hour1->SetFocus();
        prjDuty2hour1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D2T1H_SUB)
    {
        t1=prj.t1[1]/3600;
        prj.t1[1]-=3600;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            prj.t1[1]=prj.t1[1]+24*3600;
            t1=prj.t1[1]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty2hour1->SetValue(str1);
        prjDuty2hour1->SetFocus();
        prjDuty2hour1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D2T1M_ADD)
    {
        t2=prj.t1[1]/3600;
        t1=prj.t1[1]-t2*3600;
        t1=t1/60;
        if(t1<59)
        {
            t1++;
        }
        else
        {
            t1++;
            t1-=60;
        }
        prj.t1[1]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty2min1->SetValue(str1);
        prjDuty2min1->SetFocus();
        prjDuty2min1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D2T1M_SUB)
    {
        t2=prj.t1[1]/3600;
        t1=prj.t1[1]-t2*3600;
        t1=t1/60;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            t1--;
            t1+=60;
        }
        prj.t1[1]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty2min1->SetValue(str1);
        prjDuty2min1->SetFocus();
        prjDuty2min1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D2T2H_ADD)
    {
        t1=prj.t2[1]/3600;
        prj.t2[1]+=3600;
        if(t1<23)
        {
            t1++;
        }
        else
        {
            prj.t2[1]=prj.t2[1]-24*3600;
            t1=prj.t2[1]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty2hour2->SetValue(str1);
        prjDuty2hour2->SetFocus();
        prjDuty2hour2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D2T2H_SUB)
    {
        t1=prj.t2[1]/3600;
        prj.t2[1]-=3600;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            prj.t2[1]=prj.t2[1]+24*3600;
            t1=prj.t1[1]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty2hour2->SetValue(str1);
        prjDuty2hour2->SetFocus();
        prjDuty2hour2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D2T2M_ADD)
    {
        t2=prj.t2[1]/3600;
        t1=prj.t2[1]-t2*3600;
        t1=t1/60;
        if(t1<59)
        {
            t1++;
        }
        else
        {
            t1++;
            t1-=60;
        }
        prj.t2[1]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty2min2->SetValue(str1);
        prjDuty2min2->SetFocus();
        prjDuty2min2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D2T2M_SUB)
    {
        t2=prj.t2[1]/3600;
        t1=prj.t2[1]-t2*3600;
        t1=t1/60;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            t1--;
            t1+=60;
        }
        prj.t2[1]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty2min2->SetValue(str1);
        prjDuty2min2->SetFocus();
        prjDuty2min2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
}

void ConfigDlg::OnPaintTime3(wxPaintEvent& event)
{
    wxPaintDC dc(prjTime3Panel);
    int w,h;
    prjTime3Panel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        h1=22;
        y1=h/2-h1/2;
        w1=95;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_(":"),wxRect(x1+45,y1,5,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("--"),wxRect(x1+w1,y1,25,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=120;
        h1=22;
        y1=h/2-11;
        w1=95;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_(":"),wxRect(x1+45,y1,5,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=0;
        y1=1;
        w1=w1/2+1;
        h1=20;
        figButton[ID_FIG_D3T1H_ADD].x=x1;
        figButton[ID_FIG_D3T1H_ADD].y=y1;
        figButton[ID_FIG_D3T1H_ADD].width=w1;
        figButton[ID_FIG_D3T1H_ADD].height=h1;
        if(motion1==ID_FIG_D3T1H_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D3T1M_ADD].x=x1;
        figButton[ID_FIG_D3T1M_ADD].y=y1;
        figButton[ID_FIG_D3T1M_ADD].width=w1;
        figButton[ID_FIG_D3T1M_ADD].height=h1;
        if(motion1==ID_FIG_D3T1M_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=0;
        y1=h/2+10;
        figButton[ID_FIG_D3T1H_SUB].x=x1;
        figButton[ID_FIG_D3T1H_SUB].y=y1;
        figButton[ID_FIG_D3T1H_SUB].width=w1;
        figButton[ID_FIG_D3T1H_SUB].height=h1;
        if(motion1==ID_FIG_D3T1H_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D3T1M_SUB].x=x1;
        figButton[ID_FIG_D3T1M_SUB].y=y1;
        figButton[ID_FIG_D3T1M_SUB].width=w1;
        figButton[ID_FIG_D3T1M_SUB].height=h1;
        if(motion1==ID_FIG_D3T1M_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=120;
        y1=1;
        figButton[ID_FIG_D3T2H_ADD].x=x1;
        figButton[ID_FIG_D3T2H_ADD].y=y1;
        figButton[ID_FIG_D3T2H_ADD].width=w1;
        figButton[ID_FIG_D3T2H_ADD].height=h1;
        if(motion1==ID_FIG_D3T2H_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D3T2M_ADD].x=x1;
        figButton[ID_FIG_D3T2M_ADD].y=y1;
        figButton[ID_FIG_D3T2M_ADD].width=w1;
        figButton[ID_FIG_D3T2M_ADD].height=h1;
        if(motion1==ID_FIG_D3T2M_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=120;
        y1=h/2+10;
        figButton[ID_FIG_D3T2H_SUB].x=x1;
        figButton[ID_FIG_D3T2H_SUB].y=y1;
        figButton[ID_FIG_D3T2H_SUB].width=w1;
        figButton[ID_FIG_D3T2H_SUB].height=h1;
        if(motion1==ID_FIG_D3T2H_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D3T2M_SUB].x=x1;
        figButton[ID_FIG_D3T2M_SUB].y=y1;
        figButton[ID_FIG_D3T2M_SUB].width=w1;
        figButton[ID_FIG_D3T2M_SUB].height=h1;
        if(motion1==ID_FIG_D3T2M_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionTime3(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_D3T1H_ADD].x && x<figButton[ID_FIG_D3T1H_ADD].x+figButton[ID_FIG_D3T1H_ADD].width)
    {
        if(y>figButton[ID_FIG_D3T1H_ADD].y && y<figButton[ID_FIG_D3T1H_ADD].y+figButton[ID_FIG_D3T1H_ADD].height)
        {
            motion1=ID_FIG_D3T1H_ADD;
        }
        else if(y>figButton[ID_FIG_D3T1H_SUB].y && y<figButton[ID_FIG_D3T1H_SUB].y+figButton[ID_FIG_D3T1H_SUB].height)
        {
            motion1=ID_FIG_D3T1H_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D3T1M_ADD].x && x<figButton[ID_FIG_D3T1M_ADD].x+figButton[ID_FIG_D3T1M_ADD].width)
    {
        if(y>figButton[ID_FIG_D3T1M_ADD].y && y<figButton[ID_FIG_D3T1M_ADD].y+figButton[ID_FIG_D3T1M_ADD].height)
        {
            motion1=ID_FIG_D3T1M_ADD;
        }
        else if(y>figButton[ID_FIG_D3T1M_SUB].y && y<figButton[ID_FIG_D3T1M_SUB].y+figButton[ID_FIG_D3T1M_SUB].height)
        {
            motion1=ID_FIG_D3T1M_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D3T2H_ADD].x && x<figButton[ID_FIG_D3T2H_ADD].x+figButton[ID_FIG_D3T2H_ADD].width)
    {
        if(y>figButton[ID_FIG_D3T2H_ADD].y && y<figButton[ID_FIG_D3T2H_ADD].y+figButton[ID_FIG_D3T2H_ADD].height)
        {
            motion1=ID_FIG_D3T2H_ADD;
        }
        else if(y>figButton[ID_FIG_D3T2H_SUB].y && y<figButton[ID_FIG_D3T2H_SUB].y+figButton[ID_FIG_D3T2H_SUB].height)
        {
            motion1=ID_FIG_D3T2H_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D3T2M_ADD].x && x<figButton[ID_FIG_D3T2M_ADD].x+figButton[ID_FIG_D3T2M_ADD].width)
    {
        if(y>figButton[ID_FIG_D3T2M_ADD].y && y<figButton[ID_FIG_D3T2M_ADD].y+figButton[ID_FIG_D3T2M_ADD].height)
        {
            motion1=ID_FIG_D3T2M_ADD;
        }
        else if(y>figButton[ID_FIG_D3T2M_SUB].y && y<figButton[ID_FIG_D3T2M_SUB].y+figButton[ID_FIG_D3T2M_SUB].height)
        {
            motion1=ID_FIG_D3T2M_SUB;
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
    prjTime3Panel->Refresh();
}

void ConfigDlg::OnLeaveTime3(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    prjTime3Panel->Refresh();
}

void ConfigDlg::OnClickTime3(wxMouseEvent& event)
{
    int t1,t2;
    wxString str1;
    if(motion1==ID_FIG_D3T1H_ADD)
    {
        t1=prj.t1[2]/3600;
        prj.t1[2]+=3600;
        if(t1<23)
        {
            t1++;
        }
        else
        {
            prj.t1[2]=prj.t1[2]-24*3600;
            t1=prj.t1[2]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty3hour1->SetValue(str1);
        prjDuty3hour1->SetFocus();
        prjDuty3hour1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D3T1H_SUB)
    {
        t1=prj.t1[2]/3600;
        prj.t1[2]-=3600;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            prj.t1[2]=prj.t1[2]+24*3600;
            t1=prj.t1[2]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty3hour1->SetValue(str1);
        prjDuty3hour1->SetFocus();
        prjDuty3hour1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D3T1M_ADD)
    {
        t2=prj.t1[2]/3600;
        t1=prj.t1[2]-t2*3600;
        t1=t1/60;
        if(t1<59)
        {
            t1++;
        }
        else
        {
            t1++;
            t1-=60;
        }
        prj.t1[2]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty3min1->SetValue(str1);
        prjDuty3min1->SetFocus();
        prjDuty3min1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D3T1M_SUB)
    {
        t2=prj.t1[2]/3600;
        t1=prj.t1[2]-t2*3600;
        t1=t1/60;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            t1--;
            t1+=60;
        }
        prj.t1[2]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty3min1->SetValue(str1);
        prjDuty3min1->SetFocus();
        prjDuty3min1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D3T2H_ADD)
    {
        t1=prj.t2[2]/3600;
        prj.t2[2]+=3600;
        if(t1<23)
        {
            t1++;
        }
        else
        {
            prj.t2[2]=prj.t2[2]-24*3600;
            t1=prj.t2[2]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty3hour2->SetValue(str1);
        prjDuty3hour2->SetFocus();
        prjDuty3hour2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D3T2H_SUB)
    {
        t1=prj.t2[2]/3600;
        prj.t2[2]-=3600;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            prj.t2[2]=prj.t2[2]+24*3600;
            t1=prj.t2[2]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty3hour2->SetValue(str1);
        prjDuty3hour2->SetFocus();
        prjDuty3hour2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D3T2M_ADD)
    {
        t2=prj.t2[2]/3600;
        t1=prj.t2[2]-t2*3600;
        t1=t1/60;
        if(t1<59)
        {
            t1++;
        }
        else
        {
            t1++;
            t1-=60;
        }
        prj.t2[2]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty3min2->SetValue(str1);
        prjDuty3min2->SetFocus();
        prjDuty3min2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D3T2M_SUB)
    {
        t2=prj.t2[2]/3600;
        t1=prj.t2[2]-t2*3600;
        t1=t1/60;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            t1--;
            t1+=60;
        }
        prj.t2[2]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty3min2->SetValue(str1);
        prjDuty3min2->SetFocus();
        prjDuty3min2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
}

void ConfigDlg::OnPaintTime4(wxPaintEvent& event)
{
    wxPaintDC dc(prjTime4Panel);
    int w,h;
    prjTime4Panel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        h1=22;
        y1=h/2-h1/2;
        w1=95;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_(":"),wxRect(x1+45,y1,5,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLabel(_("--"),wxRect(x1+w1,y1,25,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=120;
        h1=22;
        y1=h/2-11;
        w1=95;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_(":"),wxRect(x1+45,y1,5,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=0;
        y1=1;
        w1=w1/2+1;
        h1=20;
        figButton[ID_FIG_D4T1H_ADD].x=x1;
        figButton[ID_FIG_D4T1H_ADD].y=y1;
        figButton[ID_FIG_D4T1H_ADD].width=w1;
        figButton[ID_FIG_D4T1H_ADD].height=h1;
        if(motion1==ID_FIG_D4T1H_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D4T1M_ADD].x=x1;
        figButton[ID_FIG_D4T1M_ADD].y=y1;
        figButton[ID_FIG_D4T1M_ADD].width=w1;
        figButton[ID_FIG_D4T1M_ADD].height=h1;
        if(motion1==ID_FIG_D4T1M_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=0;
        y1=h/2+10;
        figButton[ID_FIG_D4T1H_SUB].x=x1;
        figButton[ID_FIG_D4T1H_SUB].y=y1;
        figButton[ID_FIG_D4T1H_SUB].width=w1;
        figButton[ID_FIG_D4T1H_SUB].height=h1;
        if(motion1==ID_FIG_D4T1H_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D4T1M_SUB].x=x1;
        figButton[ID_FIG_D4T1M_SUB].y=y1;
        figButton[ID_FIG_D4T1M_SUB].width=w1;
        figButton[ID_FIG_D4T1M_SUB].height=h1;
        if(motion1==ID_FIG_D4T1M_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=120;
        y1=1;
        figButton[ID_FIG_D4T2H_ADD].x=x1;
        figButton[ID_FIG_D4T2H_ADD].y=y1;
        figButton[ID_FIG_D4T2H_ADD].width=w1;
        figButton[ID_FIG_D4T2H_ADD].height=h1;
        if(motion1==ID_FIG_D4T2H_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D4T2M_ADD].x=x1;
        figButton[ID_FIG_D4T2M_ADD].y=y1;
        figButton[ID_FIG_D4T2M_ADD].width=w1;
        figButton[ID_FIG_D4T2M_ADD].height=h1;
        if(motion1==ID_FIG_D4T2M_ADD)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("+"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=120;
        y1=h/2+10;
        figButton[ID_FIG_D4T2H_SUB].x=x1;
        figButton[ID_FIG_D4T2H_SUB].y=y1;
        figButton[ID_FIG_D4T2H_SUB].width=w1;
        figButton[ID_FIG_D4T2H_SUB].height=h1;
        if(motion1==ID_FIG_D4T2H_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1-1;
        figButton[ID_FIG_D4T2M_SUB].x=x1;
        figButton[ID_FIG_D4T2M_SUB].y=y1;
        figButton[ID_FIG_D4T2M_SUB].width=w1;
        figButton[ID_FIG_D4T2M_SUB].height=h1;
        if(motion1==ID_FIG_D4T2M_SUB)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.DrawLabel(_("-"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionTime4(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_D4T1H_ADD].x && x<figButton[ID_FIG_D4T1H_ADD].x+figButton[ID_FIG_D4T1H_ADD].width)
    {
        if(y>figButton[ID_FIG_D4T1H_ADD].y && y<figButton[ID_FIG_D4T1H_ADD].y+figButton[ID_FIG_D4T1H_ADD].height)
        {
            motion1=ID_FIG_D4T1H_ADD;
        }
        else if(y>figButton[ID_FIG_D4T1H_SUB].y && y<figButton[ID_FIG_D4T1H_SUB].y+figButton[ID_FIG_D4T1H_SUB].height)
        {
            motion1=ID_FIG_D4T1H_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D4T1M_ADD].x && x<figButton[ID_FIG_D4T1M_ADD].x+figButton[ID_FIG_D4T1M_ADD].width)
    {
        if(y>figButton[ID_FIG_D4T1M_ADD].y && y<figButton[ID_FIG_D4T1M_ADD].y+figButton[ID_FIG_D4T1M_ADD].height)
        {
            motion1=ID_FIG_D4T1M_ADD;
        }
        else if(y>figButton[ID_FIG_D4T1M_SUB].y && y<figButton[ID_FIG_D4T1M_SUB].y+figButton[ID_FIG_D4T1M_SUB].height)
        {
            motion1=ID_FIG_D4T1M_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D4T2H_ADD].x && x<figButton[ID_FIG_D4T2H_ADD].x+figButton[ID_FIG_D4T2H_ADD].width)
    {
        if(y>figButton[ID_FIG_D4T2H_ADD].y && y<figButton[ID_FIG_D4T2H_ADD].y+figButton[ID_FIG_D4T2H_ADD].height)
        {
            motion1=ID_FIG_D4T2H_ADD;
        }
        else if(y>figButton[ID_FIG_D4T2H_SUB].y && y<figButton[ID_FIG_D4T2H_SUB].y+figButton[ID_FIG_D4T2H_SUB].height)
        {
            motion1=ID_FIG_D4T2H_SUB;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_D4T2M_ADD].x && x<figButton[ID_FIG_D4T2M_ADD].x+figButton[ID_FIG_D4T2M_ADD].width)
    {
        if(y>figButton[ID_FIG_D4T2M_ADD].y && y<figButton[ID_FIG_D4T2M_ADD].y+figButton[ID_FIG_D4T2M_ADD].height)
        {
            motion1=ID_FIG_D4T2M_ADD;
        }
        else if(y>figButton[ID_FIG_D4T2M_SUB].y && y<figButton[ID_FIG_D4T2M_SUB].y+figButton[ID_FIG_D4T2M_SUB].height)
        {
            motion1=ID_FIG_D4T2M_SUB;
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
    prjTime4Panel->Refresh();
}

void ConfigDlg::OnLeaveTime4(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    prjTime4Panel->Refresh();
}

void ConfigDlg::OnClickTime4(wxMouseEvent& event)
{
    int t1,t2;
    wxString str1;
    if(motion1==ID_FIG_D4T1H_ADD)
    {
        t1=prj.t1[3]/3600;
        prj.t1[3]+=3600;
        if(t1<23)
        {
            t1++;
        }
        else
        {
            prj.t1[3]=prj.t1[3]-24*3600;
            t1=prj.t1[3]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty4hour1->SetValue(str1);
        prjDuty4hour1->SetFocus();
        prjDuty4hour1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D4T1H_SUB)
    {
        t1=prj.t1[3]/3600;
        prj.t1[3]-=3600;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            prj.t1[3]=prj.t1[3]+24*3600;
            t1=prj.t1[3]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty4hour1->SetValue(str1);
        prjDuty4hour1->SetFocus();
        prjDuty4hour1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D4T1M_ADD)
    {
        t2=prj.t1[3]/3600;
        t1=prj.t1[3]-t2*3600;
        t1=t1/60;
        if(t1<59)
        {
            t1++;
        }
        else
        {
            t1++;
            t1-=60;
        }
        prj.t1[3]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty4min1->SetValue(str1);
        prjDuty4min1->SetFocus();
        prjDuty4min1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D4T1M_SUB)
    {
        t2=prj.t1[3]/3600;
        t1=prj.t1[3]-t2*3600;
        t1=t1/60;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            t1--;
            t1+=60;
        }
        prj.t1[3]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty4min1->SetValue(str1);
        prjDuty4min1->SetFocus();
        prjDuty4min1->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D4T2H_ADD)
    {
        t1=prj.t2[3]/3600;
        prj.t2[3]+=3600;
        if(t1<23)
        {
            t1++;
        }
        else
        {
            prj.t2[3]=prj.t2[3]-24*3600;
            t1=prj.t2[3]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty4hour2->SetValue(str1);
        prjDuty4hour2->SetFocus();
        prjDuty4hour2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D4T2H_SUB)
    {
        t1=prj.t2[3]/3600;
        prj.t2[3]-=3600;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            prj.t2[3]=prj.t2[3]+24*3600;
            t1=prj.t2[3]/3600;
        }
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty4hour2->SetValue(str1);
        prjDuty4hour2->SetFocus();
        prjDuty4hour2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D4T2M_ADD)
    {
        t2=prj.t2[3]/3600;
        t1=prj.t2[3]-t2*3600;
        t1=t1/60;
        if(t1<59)
        {
            t1++;
        }
        else
        {
            t1++;
            t1-=60;
        }
        prj.t2[3]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty4min2->SetValue(str1);
        prjDuty4min2->SetFocus();
        prjDuty4min2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_D4T2M_SUB)
    {
        t2=prj.t2[3]/3600;
        t1=prj.t2[3]-t2*3600;
        t1=t1/60;
        if(t1>0)
        {
            t1--;
        }
        else
        {
            t1--;
            t1+=60;
        }
        prj.t2[3]=t2*3600+t1*60;
        if(t1<10)
        {
            str1=_("0")+wxString::Format(_("%d"),t1);
        }
        else
        {
            str1=wxString::Format(_("%d"),t1);
        }
        prjDuty4min2->SetValue(str1);
        prjDuty4min2->SetFocus();
        prjDuty4min2->SetSelection(-1,-1);
        //prjModified=1;
        panelBottom->Refresh();
    }
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
        figButton[ID_FIG_HTIP].width=w1;
        figButton[ID_FIG_HTIP].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(prj.htip==0)
        {
            if(motion1==ID_FIG_HTIP)
            {
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("平曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("平曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_HTIP)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("平曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("平曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }


        x1=x1+w1-1;
        figButton[ID_FIG_VTIP].x=x1;
        figButton[ID_FIG_VTIP].y=y1;
        figButton[ID_FIG_VTIP].width=w1;
        figButton[ID_FIG_VTIP].height=h1;
        if(prj.vtip==0)
        {
            if(motion1==ID_FIG_VTIP)
            {
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("竖曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("竖曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_VTIP)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("竖曲线要素"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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

void ConfigDlg::OnPaintKeyFig(wxPaintEvent& event)
{
    wxPaintDC dc(keyFigPanel);
    int w,h;
    keyFigPanel->GetClientSize(&w,&h);
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

        int x1,y1,x2,y2;
        x1=w/3+20;
        y1=0;
        x2=x1;
        y2=h;

        memDC.SetPen(wxPen(wxColor(122,122,122),1,wxDOT_DASH));
        memDC.DrawLine(x1,y1,x2,y2);

        int w1,h1;
        x1=w/2+20;
        y1=h/2-w/4;
        w1=w/4;
        h1=w1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        memDC.DrawLine(x2-10,y1,x2+10,y1);
        memDC.DrawLine(x2-10,y1+h1,x2+10,y1+h1);

        memDC.DrawLabel(_("起点里程"),wxRect(x2-15,y1+h1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("终点里程"),wxRect(x2-15,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.DrawLine(w/4,h/5-40,w/4,h/5);
        memDC.DrawLine(w/4-4,h/5-30,w/4,h/5-40);
        memDC.DrawLine(w/4+4,h/5-30,w/4,h/5-40);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
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
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        y1=0;
        w1=w/4;
        x1=w-w1;
        h1=h;

        figButton[ID_FIG_KEY_DEL].x=x1+1;
        figButton[ID_FIG_KEY_DEL].y=y1+1;
        figButton[ID_FIG_KEY_DEL].width=w1-1;
        figButton[ID_FIG_KEY_DEL].height=h1-2;
        if(motion1==ID_FIG_KEY_DEL)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(wxPen(ibrush[1].GetColour()));
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(figButton[ID_FIG_KEY_DEL]);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawLabel(_("删除"),wxRect(figButton[ID_FIG_KEY_DEL]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1-w1;
        figButton[ID_FIG_KEY_EDI].x=x1+1;
        figButton[ID_FIG_KEY_EDI].y=y1+1;
        figButton[ID_FIG_KEY_EDI].width=w1-1;
        figButton[ID_FIG_KEY_EDI].height=h1-2;
        if(motion1==ID_FIG_KEY_EDI)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(wxPen(ibrush[1].GetColour()));
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(figButton[ID_FIG_KEY_EDI]);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawLabel(_("编辑"),wxRect(figButton[ID_FIG_KEY_EDI]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1-w1;
        figButton[ID_FIG_KEY_ADD].x=x1+1;
        figButton[ID_FIG_KEY_ADD].y=y1+1;
        figButton[ID_FIG_KEY_ADD].width=w1-1;
        figButton[ID_FIG_KEY_ADD].height=h1-2;
        if(motion1==ID_FIG_KEY_ADD)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(wxPen(ibrush[1].GetColour()));
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(figButton[ID_FIG_KEY_ADD]);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
        }

        memDC.DrawLabel(_("添加"),wxRect(figButton[ID_FIG_KEY_ADD]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(x1,y1,x1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionKeyButton1(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_KEY_ADD].y && y<figButton[ID_FIG_KEY_ADD].y+figButton[ID_FIG_KEY_ADD].height)
    {
        if(x>figButton[ID_FIG_KEY_ADD].x && x<figButton[ID_FIG_KEY_ADD].x+figButton[ID_FIG_KEY_ADD].width)
        {
            motion1=ID_FIG_KEY_ADD;
        }
        else if(x>figButton[ID_FIG_KEY_EDI].x && x<figButton[ID_FIG_KEY_EDI].x+figButton[ID_FIG_KEY_EDI].width)
        {
            motion1=ID_FIG_KEY_EDI;
        }
        else if(x>figButton[ID_FIG_KEY_DEL].x && x<figButton[ID_FIG_KEY_DEL].x+figButton[ID_FIG_KEY_DEL].width)
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
    wxString str1;
    double val;
    if(motion1==ID_FIG_KEY_ADD)
    {
        str1=keyName->GetValue();
        if(str1==wxEmptyString)
        {
            WriteMsg(_("区域名称不能为空"),1);
            keyName->SetFocus();
            return;
        }
        if(!keyMile1->GetValue().ToDouble(&val))
        {
            WriteMsg(_("起点里程输入非法错误，请检查"),1);
            keyMile1->SetFocus();
            return;
        }
        else
        {
            if(prj.a2z==1)
            {
                if(val<prj.mile1-prj.tip || val>prj.mile2+prj.tip)
                {
                    WriteMsg(_("起点里程未在本工程范围内，请检查"),1);
                    return;
                }
            }
            else
            {
                if(val<prj.mile2-prj.tip || val>prj.mile1+prj.tip)
                {
                    WriteMsg(_("起点里程未在本工程范围内，请检查"),1);
                    keyGridPanel->Refresh();
                    return;
                }
            }
        }

        if(nks<1999)
        {
            strncpy(keys[nks].name,keyName->GetValue().mb_str(wxConvUTF8),64);
            keyMile1->GetValue().ToDouble(&keys[nks].mile1);
            keyMile2->GetValue().ToDouble(&keys[nks].mile2);
            if(keys[nks].mile2==0) keys[nks].mile2=keys[nks].mile1;
            nks++;
            WriteMsg(_("成功添加关键区域"),0);
            UpdateKeys();
            //keyModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_KEY_EDI)
    {
        int n = keyList->GetFirstSelected();
        int Num = keyList->GetItemCount();
        if(n<0 || n>Num-1) return;

        str1=keyName->GetValue();
        if(str1==wxEmptyString)
        {
            WriteMsg(_("区域名称不能为空"),1);
            keyName->SetFocus();
            return;
        }
        if(!keyMile1->GetValue().ToDouble(&val))
        {
            WriteMsg(_("起点里程输入非法错误，请检查"),1);
            keyMile1->SetFocus();
            return;
        }
        else
        {
            if(prj.a2z==1)
            {
                if(val<prj.mile1-prj.tip || val>prj.mile2+prj.tip)
                {
                    WriteMsg(_("起点里程未在本工程范围内，请检查"),1);
                    return;
                }
            }
            else
            {
                if(val<prj.mile2-prj.tip || val>prj.mile1+prj.tip)
                {
                    WriteMsg(_("起点里程未在本工程范围内，请检查"),1);
                    keyGridPanel->Refresh();
                    return;
                }
            }
        }

        strncpy(keys[n].name,keyName->GetValue().mb_str(wxConvUTF8),64);
        keyMile1->GetValue().ToDouble(&keys[n].mile1);
        keyMile2->GetValue().ToDouble(&keys[n].mile2);
        if(keys[n].mile2==0) keys[n].mile2=keys[n].mile1;
        WriteMsg(_("成功编辑关键区域"),0);
        UpdateKeys();
        //keyModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_KEY_DEL)
    {
        int n = keyList->GetFirstSelected();
        int Num = keyList->GetItemCount();

        if(n<0 || n>Num-1) return;

        nks--;
        for(int i=n;i<nks;i++)
        {
            keys[i]=keys[i+1];
        }
        WriteMsg(_("成功删除关键区域"),0);
        UpdateKeys();
        //keyModified=1;
        panelBottom->Refresh();
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
        w1=80;
        h1=h;
        figButton[ID_FIG_KINK1].x=x1;
        figButton[ID_FIG_KINK1].y=y1;
        figButton[ID_FIG_KINK1].width=w1;
        figButton[ID_FIG_KINK1].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(tbm.type==1)
        {
            if(motion1==ID_FIG_KINK1)
            {
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("被动铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("被动铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

        }
        else
        {
            if(motion1==ID_FIG_KINK1)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("被动铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("被动铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1=x1+w1-1;
        figButton[ID_FIG_KINK2].x=x1;
        figButton[ID_FIG_KINK2].y=y1;
        figButton[ID_FIG_KINK2].width=w1;
        figButton[ID_FIG_KINK2].height=h1;
        if(tbm.type==2)
        {
            if(motion1==ID_FIG_KINK2)
            {
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("主动铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("主动铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_KINK2)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("主动铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("主动铰接"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
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
        if(tbm.type==1)
        {
            tbm.type=0;
        }
        else
        {
            tbm.type=1;
        }
        //tbmModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_KINK2)
    {
        if(tbm.type==2)
        {
            tbm.type=0;
        }
        else
        {
            tbm.type=2;
        }
        //tbmModified=1;
        panelBottom->Refresh();
    }
    if(tbm.type>0)
    {
        tbmD5->Enable(true);
        //tbmD6->Enable(true);
        //tbmL2->Enable(true);
        tbmL3->Enable(true);
        tbmL4->Enable(true);
        m1Mid1->Enable(true);
        m1Mid2->Enable(true);
        m1Mid3->Enable(true);
        if(tbm.type==1)
        {
            m1Tail1->Enable(false);
            m1Tail2->Enable(false);
            m1Tail3->Enable(false);
            m1Head1->Enable(true);
            m1Head2->Enable(true);
            m1Head3->Enable(true);
        }
        else if(tbm.type==2)
        {
            m1Tail1->Enable(true);
            m1Tail2->Enable(true);
            m1Tail3->Enable(true);
            m1Head1->Enable(false);
            m1Head2->Enable(false);
            m1Head3->Enable(false);
        }
    }
    else
    {
        tbmD5->Enable(false);
        //tbmD6->Enable(false);
        //tbmL2->Enable(false);
        tbmL3->Enable(false);
        tbmL4->Enable(false);
        m1Mid1->Enable(false);
        m1Mid2->Enable(false);
        m1Mid3->Enable(false);
    }
    tbmKinkPanel->Refresh();
    tbmFigPanel->Refresh();
    tbmSettingPanel->Refresh();
}

void ConfigDlg::OnPaintTbmSetting(wxPaintEvent& event)
{
    wxPaintDC dc(tbmSettingPanel);
    int w,h;
    tbmSettingPanel->GetClientSize(&w,&h);
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
        memDC.DrawLabel(_("盾构机总长(L1)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL0->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=30;
        memDC.DrawLabel(_("后筒体长度(L2)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type>0)
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
        tbmL4->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=30;
        memDC.DrawLabel(_("推进油缸至切口(L3)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL1->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=30;
        memDC.DrawLabel(_("铰接油缸至切口(L4)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type>0)
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
        tbmL3->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=30;
        memDC.DrawLabel(_("切口至刀盘(L5)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL2->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=30;
        memDC.DrawLabel(_("推进油缸直径(R1)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmD4->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        y1+=30;
        memDC.DrawLabel(_("铰接油缸直径(R2)"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(tbm.type>0)
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
        //tbmL0->Show(false);
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
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }

        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("导入"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+7;
        figButton[ID_FIG_TAR_EMPORT].x=x1;
        figButton[ID_FIG_TAR_EMPORT].y=y1;
        figButton[ID_FIG_TAR_EMPORT].width=w1;
        figButton[ID_FIG_TAR_EMPORT].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(motion1==ID_FIG_TAR_EMPORT)
        {
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
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

        int xc,yc;
        xc=w/2;
        yc=h/2;
        int w1,h1,l1;
        w1=w/5;
        l1=w*3/10;
        h1=w1*4/5;
        double cosa,sina;
        cosa=cos(PI/6.0);
        sina=sin(PI/6.0);
        int x1,y1,x2,y2,x3,y3,x4,y4;
        memDC.SetPen(wxPen(wxColor(20,20,20)));
        x1=xc-l1/2*cosa;
        y1=yc-h1/2+l1/2*sina;
        x2=x1+w1/2*cosa;
        y2=y1+w1/2*sina;
        x1=x1-w1/2*cosa;
        y1=y1-w1/2*sina;
        memDC.DrawLine(x1,y1,x2,y2);
        memDC.DrawLine(x1,y1,x1,y1+h1);
        memDC.DrawLine(x2,y2,x2,y2+h1);
        memDC.DrawLine(x1,y1+h1,x2,y2+h1);

        x3=xc+l1/2*cosa;
        y3=yc-h1/2-l1/2*sina;
        x4=x3+w1/2*cosa;
        y4=y3+w1/2*sina;
        x3=x3-w1/2*cosa;
        y3=y3-w1/2*sina;
        memDC.DrawLine(x3,y3,x4,y4);
        memDC.DrawLine(x3,y3,x1,y1);
        memDC.DrawLine(x2,y2,x4,y4);
        memDC.DrawLine(x4,y4,x4,y4+h1);
        memDC.DrawLine(x2,y2+h1,x4,y4+h1);

        wxPoint pts1[180],pts2[180];
        int dx1,dy1,dx2,dy2;
        dx1=(x2-x1)/2.0;
        dy1=(y2-y1)/2.0;
        dx2=(x3-x1)/2.0;
        dy2=(y3-y1)/2.0;

        x1=x1+dx1;
        y1=y1+h1/2+dy1;
        x2=x2+dx1;
        y2=y2+h1/2+dy1;
        x3=x3+dx1;
        y3=y3+h1/2+dy1;

        memDC.SetPen(wxPen(wxColor(20,20,255),2));
        memDC.DrawLine(x1,y1,x2,y2);
        memDC.DrawLine(x1,y1,x1,y1-h1);
        memDC.DrawLine(x1,y1,x3,y3);
        ///Y 箭头
        pts1[0].x=x2;
        pts1[0].y=y2;
        pts1[1].x=x2-dx1*0.3+dx2*0.1;
        pts1[1].y=y2-dy1*0.3+dy2*0.1;
        pts1[2].x=x2-dx1*0.3-dx2*0.1;
        pts1[2].y=y2-dy1*0.3-dy2*0.1;

        memDC.SetPen(wxPen(wxColor(20,20,255)));
        memDC.SetBrush(wxBrush(wxColor(20,20,255)));
        memDC.DrawPolygon(3,pts1);
        pts1[0].x=x2+dx1*0.3;
        pts1[0].y=y2+dy1*0.3;
        pts1[1].x=pts1[0].x+dx2*0.1;
        pts1[1].y=pts1[0].y+dy2*0.1;
        pts1[2].x=pts1[0].x-dx2*0.1;
        pts1[2].y=pts1[0].y-dy2*0.1;
        pts1[3].x=pts1[1].x-dx1*0.1;
        pts1[3].y=pts1[1].y-dy1*0.1;
        pts1[4].x=pts1[1].x+dx1*0.1;
        pts1[4].y=pts1[1].y+dy1*0.1;
        memDC.SetPen(wxPen(wxColor(20,20,255),2));
        memDC.DrawLine(pts1[0],pts1[2]);
        memDC.DrawLine(pts1[0],pts1[3]);
        memDC.DrawLine(pts1[0],pts1[4]);

        ///X 箭头
        pts1[0].x=x3;
        pts1[0].y=y3;
        pts1[1].x=pts1[0].x-dx2*0.15-dx1*0.12;
        pts1[1].y=pts1[0].y-dy2*0.15-dy1*0.12;
        pts1[2].x=pts1[0].x-dx2*0.15+dx1*0.12;
        pts1[2].y=pts1[0].y-dy2*0.15+dy1*0.12;

        memDC.SetPen(wxPen(wxColor(20,20,255)));
        memDC.SetBrush(wxBrush(wxColor(20,20,255)));
        memDC.DrawPolygon(3,pts1);
        pts1[0].x=pts1[1].x+1+dx2*0.3;
        pts1[0].y=pts1[1].y+dy2*0.3;
        pts1[4].x=pts1[1].x+1+dx2*0.5;
        pts1[4].y=pts1[1].y+dy2*0.5;

        pts1[1].x=pts1[2].x-1+dx2*0.3;
        pts1[1].y=pts1[2].y+dy2*0.3;
        pts1[3].x=pts1[2].x-1+dx2*0.5;
        pts1[3].y=pts1[2].y+dy2*0.5;

        memDC.SetPen(wxPen(wxColor(20,20,255),2));
        memDC.DrawLine(pts1[0],pts1[3]);
        memDC.DrawLine(pts1[1],pts1[4]);

        ///Z 箭头
        pts1[0].x=x1;
        pts1[0].y=y1-h1;
        pts1[1].x=pts1[0].x-dx1*0.15;
        pts1[1].y=pts1[0].y+dy1*0.5-dy1*0.1;
        pts1[2].x=pts1[0].x+dx1*0.15;
        pts1[2].y=pts1[0].y+dy1*0.5+dy1*0.1;

        memDC.SetPen(wxPen(wxColor(20,20,255)));
        memDC.SetBrush(wxBrush(wxColor(20,20,255)));
        memDC.DrawPolygon(3,pts1);
        pts1[0].x=pts1[1].x+1;
        pts1[0].y=pts1[1].y-dy1*0.7;
        pts1[4].x=pts1[1].x+1;
        pts1[4].y=pts1[1].y-dy1*1.2;

        pts1[1].x=pts1[2].x-1;
        pts1[1].y=pts1[2].y-dy1*0.7;
        pts1[3].x=pts1[2].x-1;
        pts1[3].y=pts1[2].y-dy1*1.2;

        memDC.SetPen(wxPen(wxColor(20,20,255),2));
        memDC.DrawLine(pts1[4],pts1[3]);
        memDC.DrawLine(pts1[3],pts1[0]);
        memDC.DrawLine(pts1[0],pts1[1]);


        memDC.SetPen(wxPen(wxColor(20,20,20),2));
        int r1=w1/10;
        x1=xc-l1/2*cosa;
        y1=yc+h1/2+l1/2*sina;
        x2=xc-(l1/2+r1)*cosa;
        y2=yc+h1/2+(l1/2+r1)*sina;

        for(int i=0;i<180;i++)
        {
            pts1[i].x=x1+r1*cos(PI*i/90.0)*cosa;
            pts1[i].y=y1+r1*sin(PI*i/90.0)+r1*cos(PI*i/90.0)*sina;
            pts2[i].x=x2+r1*cos(PI*i/90.0)*cosa;
            pts2[i].y=y2+r1*sin(PI*i/90.0)+r1*cos(PI*i/90.0)*sina;
            memDC.DrawLine(pts1[i],pts2[i]);
        }
        memDC.SetBrush(*wxRED_BRUSH);
        memDC.DrawPolygon(180,pts2);

        memDC.SetPen(*wxWHITE_PEN);
        memDC.DrawLine(x2,y2,pts2[14].x,pts2[14].y);
        memDC.DrawLine(x2,y2,pts2[74].x,pts2[74].y);
        memDC.DrawLine(x2,y2,pts2[134].x,pts2[134].y);

        x1=15;
        y1=15;
        h1=30;
        wxString valstr;
        memDC.DrawLabel(_("前屏"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr=_("( 0.00, 0.00, 0.00 )");
        memDC.SetFont(ens);
        memDC.DrawLabel(valstr,wxRect(x1+38,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1;
        x1=15;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("后屏"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr=_("( ")+wxString::Format(_("%.2f"),tars.length)+_(", 0.00")+_(", 0.00 )");
        memDC.SetFont(ens);
        memDC.DrawLabel(valstr,wxRect(x1+38,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1;
        x1=15;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("棱镜"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        valstr=_("( ")+wxString::Format(_("%.2f"),tars.prism[0])+_(", ");
        valstr=valstr+wxString::Format(_("%.2f"),tars.prism[1])+_(", ");
        valstr=valstr+wxString::Format(_("%.2f"),tars.prism[2])+_(" )");
        memDC.SetFont(ens);
        memDC.DrawLabel(valstr,wxRect(x1+38,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionTarButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>figButton[ID_FIG_TFILE].x && x<figButton[ID_FIG_TFILE].x+figButton[ID_FIG_TFILE].width)
    {
        if(y>figButton[ID_FIG_TFILE].y && y<figButton[ID_FIG_TFILE].y+figButton[ID_FIG_TFILE].height)
        {
            motion1=ID_FIG_TFILE;
        }
        else
        {
            motion1=ID_FIG_NONE;
        }
    }
    else if(x>figButton[ID_FIG_TAR_EMPORT].x && x<figButton[ID_FIG_TAR_EMPORT].x+figButton[ID_FIG_TAR_EMPORT].width)
    {
        if(y>figButton[ID_FIG_TAR_EMPORT].y && y<figButton[ID_FIG_TAR_EMPORT].y+figButton[ID_FIG_TAR_EMPORT].height)
        {
            motion1=ID_FIG_TAR_EMPORT;
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
    op1=ID_FIG_NONE;
    if(motion1==ID_FIG_TFILE)
    {
        wxFileDialog dlg(this,_("请选择要导入的激光靶文件"),wxEmptyString,wxEmptyString,_("激光靶文件(*.tars)|*.tars"),wxFD_OPEN);
        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str=dlg.GetPath();
            char buf[1024];
            strcpy(buf,str.mb_str(wxConvLocal));
            FILE* fp=fopen(buf,"rb");
            if(fp)
            {

                point2d_t pts1[9],pts2[9];
                fread(&cli->camset[0].name,64,1,fp);
                fread(&cli->camset[0].w,sizeof(int),1,fp);
                fread(&cli->camset[0].h,sizeof(int),1,fp);
                fread(&cli->tarset.length,sizeof(double),1,fp);
                fread(&cli->tarset.prc,sizeof(double),1,fp);
                fread(&cli->tarset.inc,sizeof(int),1,fp);
                fread(&cli->tarset.cam,sizeof(int),1,fp);

                for(int i=0;i<3;i++)
                {
                    fread(&cli->tarset.prism[i],sizeof(double),1,fp);
                }
                int ncal=0;
                for(int i=0;i<9;i++)
                {
                    fread(&pts1[i].x,sizeof(double),1,fp);
                    fread(&pts1[i].y,sizeof(double),1,fp);
                    pts1[i].y=cli->camset[0].h-pts1[i].y;
                    fread(&pts2[i].x,sizeof(double),1,fp);
                    fread(&pts2[i].y,sizeof(double),1,fp);
                    if(pts1[i].x>1.0e-6 && pts1[i].y>1.0e-6)
                    {
                        ncal++;
                    }
                }
                affine_t aff;
                affine_init_points(&aff,ncal,pts1,pts2);
                cli->camset[0].affine[0]=aff.a1;
                cli->camset[0].affine[1]=aff.a2;
                cli->camset[0].affine[2]=aff.a3;
                cli->camset[0].affine[3]=aff.b1;
                cli->camset[0].affine[4]=aff.b2;
                cli->camset[0].affine[5]=aff.b3;
                cli->camset[0].affine[6]=aff.c1;
                cli->camset[0].affine[7]=aff.c2;
                cli->camset[0].affine[8]=aff.c3;
                fread(&cli->camset[0].x1,sizeof(double),1,fp);
                fread(&cli->camset[0].y1,sizeof(double),1,fp);
                fread(&cli->camset[0].x2,sizeof(double),1,fp);
                fread(&cli->camset[0].y2,sizeof(double),1,fp);

                fclose(fp);
                //mtg_store_camset(cli);
                //mtg_store_tars(cli);
                if(cli->iclient==2)
                {
                    //client_tars(cli,0);
                }

                //for(int i=0;i<cli->camsvr.count;i++)
                //{
                    //cli->camsvr.cams[i].type=cli->tarset.cam;
                //}

                wxMessageBox(_("导入成功！"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
                LoadDataBase();
            }
            fclose(fp);
        }
        tarsFig->Refresh();
        //tarsFig1->Refresh();
    }
    else if(motion1==ID_FIG_TAR_EMPORT)
    {

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

        x1=50;
        y1=50;
        w1=w-100;
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

        memDC.DrawLine(x2-25,y2,x2-5,y2);
        memDC.DrawLine(x2-25,y2+h2,x2-5,y2+h2);
        memDC.DrawLine(x2-23,y2,x2-23,y2+h2);
        memDC.DrawLabel(_("L5"),wxRect(x2-25,y2,0,h2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

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
        memDC.SetPen(wxPen(wxColor(58,58,58)));
        //tbm.type=1;
        if(tbm.type>0)
        {
            memDC.DrawLine(x2+5,y2+h2*3/5-75,x2+15,y2+h2*3/5-75);
            memDC.DrawLine(x2+5,y2+h2*3/5-55,x2+15,y2+h2*3/5-55);
            memDC.DrawCircle(x2+15,y2+h2*3/5-65,10);

            memDC.DrawLine(x2+w2-15,y2+h2*3/5-75,x2+w2-5,y2+h2*3/5-75);
            memDC.DrawLine(x2+w2-15,y2+h2*3/5-55,x2+w2-5,y2+h2*3/5-55);
            memDC.DrawCircle(x2+w2-15,y2+h2*3/5-65,10);

            memDC.DrawLine(x2+5,y2+h2*3/5-25,x2+15,y2+h2*3/5-25);
            memDC.DrawLine(x2+5,y2+h2*3/5-5,x2+15,y2+h2*3/5-5);
            memDC.DrawCircle(x2+15,y2+h2*3/5-15,10);

            memDC.DrawLine(x2+w2-15,y2+h2*3/5-25,x2+w2-5,y2+h2*3/5-25);
            memDC.DrawLine(x2+w2-15,y2+h2*3/5-5,x2+w2-5,y2+h2*3/5-5);
            memDC.DrawCircle(x2+w2-15,y2+h2*3/5-15,10);

            memDC.SetPen(wxPen(wxColor(255,0,0)));
            memDC.DrawLine(x2+5,y2+h2*3/5-65,x2+5,y2+h2*3/5-15);
            memDC.DrawLine(x2+25,y2+h2*3/5-65,x2+25,y2+h2*3/5-15);

            memDC.DrawLine(x2+w2-5,y2+h2*3/5-65,x2+w2-5,y2+h2*3/5-15);
            memDC.DrawLine(x2+w2-25,y2+h2*3/5-65,x2+w2-25,y2+h2*3/5-15);

            memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT));
            memDC.DrawLine(x2+15,y2+h2*3/5-10,x2+15,y2+h2*3/5-25);
            memDC.DrawLine(x2+w2-15,y2+h2*3/5-10,x2+w2-15,y2+h2*3/5-25);
            memDC.DrawLine(x2+15,y2+h2*3/5-55,x2+15,y2+h2*3/5-75);
            memDC.DrawLine(x2+w2-15,y2+h2*3/5-55,x2+w2-15,y2+h2*3/5-75);

            memDC.SetPen(wxPen(wxColor(0,0,255)));
            if(tbm.type==1)
            {
                memDC.DrawLine(x2+15,y2+h2*3/5-80,x2+15,y2+h2*3/5-90);
                memDC.DrawLine(x2+w2-15,y2+h2*3/5-80,x2+w2-15,y2+h2*3/5-90);
                memDC.DrawLine(x2+15,y2+h2*3/5-87,x2+w2-15,y2+h2*3/5-87);
                memDC.DrawLabel(_("R2"),wxRect(x2+15,y2+h2*3/5-87,w2-30,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
                memDC.SetPen(wxPen(wxColor(0,0,255)));

                memDC.DrawLine(x2-35,y2+h2*3/5-65,x2+15,y2+h2*3/5-65);
                memDC.DrawLine(x2-33,y2,x2-33,y2+h2*3/5-65);
                memDC.DrawLabel(_("L4"),wxRect(x2-30,y2,0,h2*3/5-65),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else if(tbm.type==2)
            {
                memDC.DrawLine(x2+15,y2+h2*3/5-30,x2+15,y2+h2*3/5-40);
                memDC.DrawLine(x2+w2-15,y2+h2*3/5-30,x2+w2-15,y2+h2*3/5-40);
                memDC.DrawLine(x2+15,y2+h2*3/5-37,x2+w2-15,y2+h2*3/5-37);
                memDC.DrawLabel(_("R2"),wxRect(x2+15,y2+h2*3/5-37,w2-30,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
                memDC.SetPen(wxPen(wxColor(0,0,255)));
                memDC.DrawLine(x2-35,y2+h2*3/5-15,x2+25,y2+h2*3/5-15);
                memDC.DrawLine(x2-33,y2,x2-33,y2+h2*3/5-15);
                memDC.DrawLabel(_("L4"),wxRect(x2-33,y2+10,0,h2*3/5-15),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            }
            memDC.DrawLine(x2-35,y2,x2-5,y2);
        }

        memDC.SetPen(wxPen(wxColor(0,0,255)));
        /*memDC.DrawLine(x2,y2+h2+5,x2,y2+h2+35);
        memDC.DrawLine(x2+w2,y2+h2+5,x2+w2,y2+h2+35);
        memDC.DrawLine(x2,y2+h2+33,x2+w2,y2+h2+33);
        memDC.DrawLine(x2+5,y2+h2+5,x2+5,y2+h2+25);
        memDC.DrawLine(x2+w2-5,y2+h2+5,x2+w2-5,y2+h2+25);
        memDC.DrawLine(x2+5,y2+h2+23,x2+w2-5,y2+h2+23);
        memDC.DrawLabel(_("R3"),wxRect(x2,y2+h2+35,w2,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(_("R4"),wxRect(x2+5,y2+h2+23,w2-10,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);*/

        memDC.DrawLine(x2+w2+5,y2,x2+w2+35,y2);
        memDC.DrawLine(x2+w2+5,y2+h2,x2+w2+35,y2+h2);
        memDC.DrawLine(x2+w2+33,y2,x2+w2+33,y2+h2);
        memDC.DrawLabel(_("L1"),wxRect(x2+w2+38,y2+h2/2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x2+w2+5,y2,x2+w2+25,y2);
        memDC.DrawLine(x2+w2-15,y2+h2*3/5+32,x2+w2+25,y2+h2*3/5+32);
        memDC.DrawLine(x2+w2+23,y2,x2+w2+23,y2+h2*3/5+32);
        memDC.DrawLabel(_("L3"),wxRect(x2+w2+20,y2,0,h2*3/5+32),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
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
        x1=15;
        y1=15;
        w1=90;
        h1=25;
        memDC.DrawLabel(_("激光类型"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=100;
        w1=150;
        figButton[ID_FIG_LASER0].x=x1;
        figButton[ID_FIG_LASER0].y=y1;
        figButton[ID_FIG_LASER0].width=w1;
        figButton[ID_FIG_LASER0].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(tps.lasertype==0)
        {
            if(motion1==ID_FIG_LASER0)
            {
                memDC.SetPen(btnPen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.DrawLabel(_("GUS74激光"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=x1+w1-1;
        w1=150;
        figButton[ID_FIG_LASER1].x=x1;
        figButton[ID_FIG_LASER1].y=y1;
        figButton[ID_FIG_LASER1].width=w1;
        figButton[ID_FIG_LASER1].height=h1;

        if(tps.lasertype==1)
        {
            if(motion1==ID_FIG_LASER1)
            {
                memDC.SetPen(btnPen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[1]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.DrawLabel(_("同轴激光"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        y1=45;
        x1=15;
        memDC.DrawLabel(_("激光矫正"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=100;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("L "),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        w1=110;
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("m"),wxRect(x1+w1-25,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tpsLaserDist->SetSize(x1+1,y1+5,w1-26,h1-6);

        x1=x1+w1+40;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("△X "),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawRectangle(x1,y1,w1,h1);
        tpsLaserDevX->SetSize(x1+1,y1+5,w1-38,h1-6);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1-35,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+40;
        memDC.SetFont(chs);
        memDC.DrawLabel(_("△Y "),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawRectangle(x1,y1,w1,h1);
        tpsLaserDevY->SetSize(x1+1,y1+5,w1-38,h1-6);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1-35,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1=105;
        x1=15;
        w1=w-60;
        h1=h-y1;

        int x2,y2,w2,h2;
        if(bmpTPS1.IsOk())
        {
            w2=bmpTPS1.GetWidth();
            h2=bmpTPS1.GetHeight();
            x2=x1;
            y2=y1+h1/2-h2/2;
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
            memDC.SetPen(wxPen(wxColor(255,9,9),2,wxLONG_DASH));
            memDC.DrawLine(x2+w2/2+15,py0,px0,py0);
            memDC.DrawLabel(_("L"),wxRect(x2/2+w2/4+8+px0/2,py0+10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.SetPen(wxPen(wxColor(255,9,9),2));
            px1=px0+40;
            py1=py0-40;
            memDC.DrawLine(x2+w2/2+15,py0,px1,py1);
            px2=px0;
            py2=py1-40*tan(PI/6);
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(px1,py1,px2,py2);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("△X"),wxRect(px1/2+px2/2+7,py1/2+py2/2-10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            px2=px1;
            py2=py0+40*tan(PI/6);
            memDC.DrawLine(px1,py1,px2,py2);
            memDC.DrawLabel(_("△Y"),wxRect(px1+15,py1/2+py2/2,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else if(tps.lasertype==0)
        {
            memDC.SetPen(wxPen(wxColor(255,9,9),2,wxLONG_DASH));
            memDC.DrawLine(x2+w2/2+15,py0-21,px0,py0-21);
            memDC.DrawLabel(_("L"),wxRect(x2/2+w2/4+8+px0/2,py0-13,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.SetPen(wxPen(wxColor(255,9,9),2));
            px1=px0+40;
            py1=py0-40;
            memDC.DrawLine(x2+w2/2+15,py0-21,px1,py1);
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

        x1=15;
        y1=15;
        w1=w-30;
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
        memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        for(int i=0;i<ks;i++)
        {
            xi=x1+r1+ri*sin(alf*i);
            yi=y1+r1-ri*cos(alf*i);
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
        memDC.DrawLine(x1,y1+r1,x1,y1+r1+35);
        memDC.DrawLine(x1-7,y1+r1+28,x1+7,y1+r1+42);
        memDC.DrawLine(x1+r1*2,y1+r1,x1+r1*2,y1+r1+35);
        memDC.DrawLine(x1+r1*2-7,y1+r1+28,x1+r1*2+7,y1+r1+42);
        memDC.DrawLine(x1,y1+r1+35,x1+r1*2,y1+r1+35);
        memDC.DrawLabel(_("De"),wxRect(x1+r1,y1+r1+38,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.DrawLine(x1+15,y1+r1,x1+15,y1+r1+15);
        memDC.DrawLine(x1+8,y1+r1+8,x1+22,y1+r1+22);
        memDC.DrawLine(x1+r1*2-15,y1+r1,x1+r1*2-15,y1+r1+15);
        memDC.DrawLine(x1+r1*2-22,y1+r1+8,x1+r1*2-8,y1+r1+22);
        memDC.DrawLine(x1+15,y1+r1+15,x1+r1*2-15,y1+r1+15);
        memDC.DrawLabel(_("D"),wxRect(x1+r1,y1+r1+18,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

        y1=4*y1+2*r1;
        h1=h-y1-45;
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        if(segset.in==1)
        {
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x1+w1/2,y1,x1+w1/2,y1+h1);
            memDC.DrawLine(x1+w1/2-7,y1-7,x1+w1/2+7,y1+7);
            memDC.DrawLine(x1+w1/2-7,y1+h1-7,x1+w1/2+7,y1+h1+7);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("L"),wxRect(x1+w1/2+5,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(segset.f2b==0)
        {
            memDC.DrawLine(x1,y1,x1,y1-16);
            memDC.DrawLine(x1,y1-16,x1+w1,y1);
            memDC.DrawLine(x1,y1+h1,x1,y1+h1+16);
            memDC.DrawLine(x1,y1+h1+16,x1+w1,y1+h1);

            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x1+w1/2,y1-8,x1+w1/2,y1+h1+8);
            memDC.DrawLine(x1+w1/2-7,y1-15,x1+w1/2+7,y1-1);
            memDC.DrawLine(x1+w1/2-7,y1+h1+1,x1+w1/2+7,y1+h1+15);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("L"),wxRect(x1+w1/2+5,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            memDC.DrawLine(x1-7,y1-23,x1+7,y1-9);
            memDC.DrawLine(x1-7,y1+h1+9,x1+7,y1+h1+23);
            memDC.DrawLabel(_("L1"),wxRect(x1+5,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLine(x1+w1-7,y1-7,x1+w1+7,y1+7);
            memDC.DrawLine(x1+w1-7,y1+h1-7,x1+w1+7,y1+h1+7);
            memDC.DrawLabel(_("L2"),wxRect(x1+w1-5,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

            memDC.DrawLabel(_("△L = L2-L1"),wxRect(x1+w1/2,y1+h1+15,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        }
        else
        {
            memDC.DrawLine(x1,y1,x1,y1-16);
            memDC.DrawLine(x1,y1-16,x1+w1,y1);

            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawLine(x1+w1/2,y1-8,x1+w1/2,y1+h1);
            memDC.DrawLine(x1+w1/2-7,y1-15,x1+w1/2+7,y1-1);
            memDC.DrawLine(x1+w1/2-7,y1+h1-7,x1+w1/2+7,y1+h1+7);
            memDC.SetFont(ens);
            memDC.DrawLabel(_("L"),wxRect(x1+w1/2+5,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            memDC.DrawLine(x1-7,y1-23,x1+7,y1-9);
            memDC.DrawLine(x1-7,y1+h1-7,x1+7,y1+h1+7);
            memDC.DrawLabel(_("L1"),wxRect(x1+5,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLine(x1+w1-7,y1-7,x1+w1+7,y1+7);
            memDC.DrawLine(x1+w1-7,y1+h1-7,x1+w1+7,y1+h1+7);
            memDC.DrawLabel(_("L2"),wxRect(x1+w1-5,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.DrawLabel(_("通缝拼装"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=20;
        y1=y1+30;
        memDC.SetTextForeground(btnTextColor[0]);
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
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_SEG_TYPE1)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.SetTextForeground(btnTextColor[0]);
            memDC.DrawLabel(_("标准环+转弯环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_SEG_TYPE1)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.SetTextForeground(btnTextColor[0]);
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
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_SEG_TYPE2)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            memDC.SetTextForeground(btnTextColor[0]);
            memDC.DrawLabel(_("通用管环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_SEG_TYPE2)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.SetTextForeground(btnTextColor[0]);
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
        memDC.SetTextForeground(btnTextColor[0]);
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
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_F2B_TTPE1)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_F2B_TTPE1)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_F2B_TTPE2)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_F2B_TTPE2)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.DrawLabel(_("直角梯形"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=20;
        y1=y1+30;
        memDC.SetTextForeground(btnTextColor[0]);
        memDC.DrawLabel(_("错峰条件"),wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
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
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_S2S_12)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_S2S_12)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_S2S_13)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
            memDC.SetTextForeground(btnTextColor[0]);
            if(motion1==ID_FIG_S2S_13)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
        memDC.SetTextForeground(btnTextColor[0]);
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
            memDC.SetTextForeground(btnTextColor[0]);
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

void ConfigDlg::OnPaintBlkGrid(wxPaintEvent& event)
{
    wxPaintDC dc(blkGridPanel);
    int w,h;
    blkGridPanel->GetClientSize(&w,&h);
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
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.SetBrush(wxBrush(wxColor(248,248,248)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w/3;
        h1=h;

        figButton[ID_FIG_BLK_ADD].x=x1+1;
        figButton[ID_FIG_BLK_ADD].y=y1+1;
        figButton[ID_FIG_BLK_ADD].width=w1-1;
        figButton[ID_FIG_BLK_ADD].height=h1-2;
        if(motion1==ID_FIG_BLK_ADD)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(wxPen(ibrush[1].GetColour()));
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(figButton[ID_FIG_BLK_ADD]);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawLabel(_("添加"),wxRect(figButton[ID_FIG_BLK_ADD]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1;
        figButton[ID_FIG_BLK_EDI].x=x1+1;
        figButton[ID_FIG_BLK_EDI].y=y1+1;
        figButton[ID_FIG_BLK_EDI].width=w1-1;
        figButton[ID_FIG_BLK_EDI].height=h1-2;
        if(motion1==ID_FIG_BLK_EDI)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(wxPen(ibrush[1].GetColour()));
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(figButton[ID_FIG_BLK_EDI]);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawLabel(_("编辑"),wxRect(figButton[ID_FIG_BLK_EDI]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(x1,y1,x1,y1+h1);
        x1=x1+w1;
        figButton[ID_FIG_BLK_DEL].x=x1+1;
        figButton[ID_FIG_BLK_DEL].y=y1+1;
        figButton[ID_FIG_BLK_DEL].width=w1-1;
        figButton[ID_FIG_BLK_DEL].height=h1-2;
        if(motion1==ID_FIG_BLK_DEL)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(wxPen(ibrush[1].GetColour()));
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(figButton[ID_FIG_BLK_DEL]);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
        }

        memDC.DrawLabel(_("删除"),wxRect(figButton[ID_FIG_BLK_DEL]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(x1,y1,x1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionBlkButton1(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_BLK_ADD].y && y<figButton[ID_FIG_BLK_ADD].y+figButton[ID_FIG_BLK_ADD].height)
    {
        if(x>figButton[ID_FIG_BLK_ADD].x && x<figButton[ID_FIG_BLK_ADD].x+figButton[ID_FIG_BLK_ADD].width)
        {
            motion1=ID_FIG_BLK_ADD;
        }
        else if(x>figButton[ID_FIG_BLK_EDI].x && x<figButton[ID_FIG_BLK_EDI].x+figButton[ID_FIG_BLK_EDI].width)
        {
            motion1=ID_FIG_BLK_EDI;
        }
        else if(x>figButton[ID_FIG_BLK_DEL].x && x<figButton[ID_FIG_BLK_DEL].x+figButton[ID_FIG_BLK_DEL].width)
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
    if(motion1==ID_FIG_BLK_ADD)
    {
        if(nblk>=35)
        {
            WriteMsg(_("管块数量超过36"),1);
            return;
        }
        int Num = blockList->GetItemCount();
        wxString str1;
        double val;
        str1=blkName->GetValue();
        if(str1==wxEmptyString)
        {
            WriteMsg(_("管块名称不能为空"),1);
            blkName->SetFocus();
            return;
        }
        if(!blkAngle->GetValue().ToDouble(&val))
        {
            WriteMsg(_("圆心角输入错误，请检查"),1);
            blkAngle->SetFocus();
            return;
        }
        else
        {
            if(val<0.0 || val>360.0)
            {
                WriteMsg(_("圆心角范围错误，请检查"),1);
                blkAngle->SetFocus();
                return;
            }
        }
        strncpy(blocks[Num].name,str1.mb_str(wxConvUTF8),64);
        blocks[Num].angle=val*PI/180.0;
        nblk++;
        WriteMsg(_("添加管块成功"),0);
        UpdateBlocks();
        //blockModified=1;
        blkID->SetValue(wxString::Format(_("%d"),nblk));
        panelBottom->Refresh();
        blkFigPanel->Refresh();
    }
    else if(motion1==ID_FIG_BLK_EDI)
    {
        int n = blockList->GetFirstSelected();
        int Num = blockList->GetItemCount();
        if(n<0 || n>Num-1) return;
        wxString str1;
        double val;
        str1=blkName->GetValue();
        if(str1==wxEmptyString)
        {
            WriteMsg(_("管块名称不能为空"),1);
            blkName->SetFocus();
            return;
        }
        if(!blkAngle->GetValue().ToDouble(&val))
        {
            WriteMsg(_("圆心角输入错误，请检查"),1);
            blkAngle->SetFocus();
            return;
        }
        else
        {
            if(val<0.0 || val>360.0)
            {
                WriteMsg(_("圆心角范围错误，请检查"),1);
                blkAngle->SetFocus();
                return;
            }
        }
        strncpy(blocks[n].name,str1.mb_str(wxConvUTF8),64);
        blocks[n].angle=val*PI/180.0;
        WriteMsg(_("编辑管块成功"),0);
        UpdateBlocks();
        //blockModified=1;
        panelBottom->Refresh();
        blkFigPanel->Refresh();
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

        x1=15;
        y1=15;
        w1=w-30;
        h1=w1;
        r1=w1/2;
        r2=r1-15;
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

        y1=4*y1+2*r1;
        h1=h-y1-45;
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        if(nblk>0)
        {
            int sel=blockList->GetFirstSelected();
            if(sel>=0 && sel<nblk)
            {
                memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT));
                memDC.DrawLine(x4,y1,x4,y1+h1);
                memDC.DrawLine(x5,y1,x5,y1+h1);
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

        figButton[ID_FIG_M1_MEA].x=x1;
        figButton[ID_FIG_M1_MEA].y=y1;
        figButton[ID_FIG_M1_MEA].width=w1;
        figButton[ID_FIG_M1_MEA].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(motion1==ID_FIG_M1_MEA)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[3]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("测量"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+7;
        figButton[ID_FIG_M1_IMPORT].x=x1;
        figButton[ID_FIG_M1_IMPORT].y=y1;
        figButton[ID_FIG_M1_IMPORT].width=w1;
        figButton[ID_FIG_M1_IMPORT].height=h1;
        if(motion1==ID_FIG_M1_IMPORT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[3]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("导入"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+7;
        figButton[ID_FIG_M1_EXPORT].x=x1;
        figButton[ID_FIG_M1_EXPORT].y=y1;
        figButton[ID_FIG_M1_EXPORT].width=w1;
        figButton[ID_FIG_M1_EXPORT].height=h1;

        if(motion1==ID_FIG_M1_EXPORT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[3]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("导出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

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
        //if(mtg_start_origin(cli)==-1)
        {
            WriteMsg(_("初始姿态测量失败，请检查"),1);
        }
    }
    m1ButtonPanel->Refresh();
}

void ConfigDlg::OnPaintM1Fig(wxPaintEvent& event)
{
    wxPaintDC dc(m1FigPanel);
    int w,h;
    m1FigPanel->GetClientSize(&w,&h);
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
        /*wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        if(cli->m0.t1>0)
        {
            int x1,y1,w1,h1;
            int x2,y2,w2,h2;

        }
        else
        {
            memDC.DrawLabel(_("激光靶未测量!"),wxRect(0,0,w,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }*/
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintRemBg(wxPaintEvent& event)
{
    wxPaintDC dc(remBgPanel);
    int w,h;
    remBgPanel->GetClientSize(&w,&h);
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
        x1=37;
        w1=37;
        y1=0;
        h1=h;
        memDC.DrawLabel(_("."),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        memDC.DrawLabel(_("."),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        memDC.DrawLabel(_("."),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.SetFont(chs);
            memDC.DrawLabel(_("综合严密计算"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=0;
        y1=y1+28;
        w1=60;
        memDC.DrawLabel(_("掘进纠偏"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=150;
        figButton[ID_FIG_SET_VDRIVING].x=x1;
        figButton[ID_FIG_SET_VDRIVING].y=y1;
        figButton[ID_FIG_SET_VDRIVING].width=w1;
        figButton[ID_FIG_SET_VDRIVING].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.idrv==1)
        {
            if(motion1==ID_FIG_SET_VDRIVING)
            {
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("计算并显示纠偏参数"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("计算并显示纠偏参数"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_VDRIVING)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("计算并显示纠偏参数"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("计算并显示纠偏参数"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("开始测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("开始测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_RUN)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("开始测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("停止测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("停止测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_END)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("停止测量"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("管环选型"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("管环选型"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_SAS)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("管环选型"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("系统检核"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("系统检核"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_CHK)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("系统检核"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("数据查询"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("数据查询"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_QRY)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("数据查询"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("地质地物"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("地质地物"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_MAP)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("地质地物"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("管环沉降"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("管环沉降"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_SMR)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("管环沉降"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("退出系统"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("退出系统"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEC_QUIT)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("退出系统"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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
    else if(y>figButton[ID_FIG_SET_VDRIVING].y && y<figButton[ID_FIG_SET_VDRIVING].y+figButton[ID_FIG_SET_VDRIVING].height)
    {
        if(x>figButton[ID_FIG_SET_VDRIVING].x && x<figButton[ID_FIG_SET_VDRIVING].x+figButton[ID_FIG_SET_VDRIVING].width)
        {
            motion1=ID_FIG_SET_VDRIVING;
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
        //settingModified=1;
        panelBottom->Refresh();
    }
    else if(motion1==ID_FIG_SET_VIBRATION_YES)
    {
        measet.vibration=1;
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
    else if(motion1==ID_FIG_SET_VDRIVING)
    {
        if(measet.idrv==0)
        {
            measet.idrv=1;
        }
        else
        {
            measet.idrv=0;
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
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
        figButton[ID_FIG_UI_DEG].x=x1;
        figButton[ID_FIG_UI_DEG].y=y1;
        figButton[ID_FIG_UI_DEG].width=w1;
        figButton[ID_FIG_UI_DEG].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(measet.unit==0)
        {
            if(motion1==ID_FIG_UI_DEG)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
        figButton[ID_FIG_UI_PER].x=x1;
        figButton[ID_FIG_UI_PER].y=y1;
        figButton[ID_FIG_UI_PER].width=w1;
        figButton[ID_FIG_UI_PER].height=h1;
        if(measet.unit==1)
        {
            if(motion1==ID_FIG_UI_PER)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
            if(motion1==ID_FIG_UI_PER)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
        if(measet.heading==0)
        {
            if(motion1==ID_FIG_UI_HEADING0)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
        if(measet.heading==1)
        {
            if(motion1==ID_FIG_UI_HEADING1)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            memDC.DrawLabel(_("基于切线"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        x1=60;
        y1=y1+25;
        w1=130;
        h1=h-y1-1;
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
    if(motion1==ID_FIG_UI_DEG)
    {
        if(measet.unit!=0)
        {
            measet.unit=0;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_UI_PER)
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
        if(measet.heading!=0)
        {
            measet.heading=0;
            //settingModified=1;
            panelBottom->Refresh();
        }
    }
    else if(motion1==ID_FIG_UI_HEADING1)
    {
        if(measet.heading!=1)
        {
            measet.heading=1;
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("红色字体警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("红色字体警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_DEV_CAUTION)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("红色字体警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_TIME_CAUTION)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("停止且主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("停止且主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_STN_CAUTION)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("停止且主界面警告"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("设为系统错误警示信息"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("设为系统错误警示信息"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_INFO_ERR)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("设为系统错误警示信息"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
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

void ConfigDlg::OnPaintSmOnOff(wxPaintEvent& event)
{
    wxPaintDC dc(smOnOff);
    int w,h;
    smOnOff->GetClientSize(&w,&h);
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
        w1=150;
        h1=23;
        figButton[ID_FIG_SET_SEG_MONITOR].x=x1;
        figButton[ID_FIG_SET_SEG_MONITOR].y=y1;
        figButton[ID_FIG_SET_SEG_MONITOR].width=w1;
        figButton[ID_FIG_SET_SEG_MONITOR].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(smonitor.monitor==1)
        {
            if(motion1==ID_FIG_SET_SEG_MONITOR)
            {
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("启动管环监测"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("启动管环监测"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion1==ID_FIG_SET_SEG_MONITOR)
            {
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("启动管环监测"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(btnTextColor[0]);
                memDC.DrawLabel(_("启动管环监测"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnMotionSmOnOff(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>figButton[ID_FIG_SET_SEG_MONITOR].y && y<figButton[ID_FIG_SET_SEG_MONITOR].y+figButton[ID_FIG_SET_SEG_MONITOR].height)
    {
        if(x>figButton[ID_FIG_SET_SEG_MONITOR].x && x<figButton[ID_FIG_SET_SEG_MONITOR].x+figButton[ID_FIG_SET_SEG_MONITOR].width)
        {
            motion1=ID_FIG_SET_SEG_MONITOR;
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
    smOnOff->Refresh();
}

void ConfigDlg::OnLeaveSmOnOff(wxMouseEvent& event)
{
    motion1=ID_FIG_NONE;
    smOnOff->Refresh();
}

void ConfigDlg::OnClickSmOnOff(wxMouseEvent& event)
{
    if(motion1==ID_FIG_SET_SEG_MONITOR)
    {
        if(smonitor.monitor==0)
        {
            smonitor.monitor=1;
            smNumber->Enable(true);
            smTime->Enable(true);
            smLast->Enable(true);
            smX->Enable(true);
            smY->Enable(true);
            smZ->Enable(true);
        }
        else
        {
            smonitor.monitor=0;
            smNumber->Enable(false);
            smTime->Enable(false);
            smLast->Enable(false);
            smX->Enable(false);
            smY->Enable(false);
            smZ->Enable(false);
        }
        //settingModified=1;
        panelBottom->Refresh();
    }
    smOnOff->Refresh();
    smTimePanel->Refresh();
    smLastPanel->Refresh();
    smPosPanel->Refresh();
}

void ConfigDlg::OnPaintSmTime(wxPaintEvent& event)
{
    wxPaintDC dc(smTimePanel);
    int w,h;
    smTimePanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        if(smonitor.monitor==1)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.SetTextForeground(btnTextColor[0]);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            memDC.SetTextForeground(wxColor(115,115,115));
        }
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.DrawLabel(_("秒"),wxRect(w-16,0,0,h),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintSmLast(wxPaintEvent& event)
{
    wxPaintDC dc(smLastPanel);
    int w,h;
    smLastPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        if(smonitor.monitor==1)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.SetTextForeground(btnTextColor[0]);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            memDC.SetTextForeground(wxColor(115,115,115));
        }
        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.DrawLabel(_("环"),wxRect(w-16,0,0,h),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfigDlg::OnPaintSmPos(wxPaintEvent& event)
{
    wxPaintDC dc(smPosPanel);
    int w,h;
    smPosPanel->GetClientSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int w1=w/3-10;
        memDC.SetPen(wxPen(wxColor(122,122,122)));

        if(smonitor.monitor==1)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.SetTextForeground(btnTextColor[0]);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            memDC.SetTextForeground(wxColor(115,115,115));
        }
        memDC.DrawRectangle(0,0,w1,h);
        memDC.DrawLabel(_("X"),wxRect(16,0,0,h),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawRectangle(w1+10,0,w1,h);
        memDC.DrawLabel(_("Y"),wxRect(w1+26,0,0,h),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawRectangle(w1*2+20,0,w1,h);
        memDC.DrawLabel(_("Z"),wxRect(w1+w1+36,0,0,h),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
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
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(btnBrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
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
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
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
            memDC.SetBrush(ibrush[3]);
            memDC.SetPen(btnPen[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(btnPen[0]);
            memDC.SetTextForeground(btnTextColor[0]);
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
        if(opLevel>0)
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

        if(opLevel>0 && opLevel!=n)
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
            strncpy(user[n].password,str.mb_str(wxConvUTF8),64);
            userModified=1;
            panelBottom->Refresh();
            UpdateUsers();
        }
    }
    else if(motion1==ID_FIG_USER_DEL)
    {
        if(opLevel==1)
        {
            WriteMsg(_("无操作权限"),1);
            return;
        }

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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
                memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                memDC.SetBrush(ibrush[1]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR2);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
                memDC.SetPen(btnPen[2]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
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
    wxString str1;
    str1=wxString::Format(_("%d"),n+1);
    blkID->SetValue(str1);
    str1=wxString(blocks[n].name,wxConvUTF8);
    blkName->SetValue(str1);
    str1=wxString::Format(_("%.2f"),blocks[n].angle*180/PI);
    blkAngle->SetValue(str1);
}

void ConfigDlg::OnListBlockDeselect(wxListEvent& event)
{
    blkFigPanel->Refresh();
    blkID->SetValue(wxEmptyString);
    blkName->SetValue(wxEmptyString);
    blkAngle->SetValue(wxEmptyString);
}

void ConfigDlg::OnListKeySelect(wxListEvent& event)
{
    int n = keyList->GetFirstSelected();
    int Num = keyList->GetItemCount();

    if(n<0 || n>Num-1) return;

    wxString str1;
    str1=wxString(keys[n].name,wxConvUTF8);
    keyName->SetValue(str1);

    str1=wxString::Format(_("%.4f"),keys[n].mile1);
    keyMile1->SetValue(str1);

    str1=wxString::Format(_("%.4f"),keys[n].mile2);
    keyMile2->SetValue(str1);

    blkFigPanel->Refresh();
}

void ConfigDlg::OnListKeyDeselect(wxListEvent& event)
{
    blkFigPanel->Refresh();
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
        if(opLevel>0 && opLevel!=n)
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
        str1=wxString::Format(_("%.4f"),cli->m0.head[0]);
        m1Head1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.head[1]);
        m1Head2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.head[2]);
        m1Head3->SetValue(str1);
        m1Mid1->Enable(false);
        m1Mid2->Enable(false);
        m1Mid3->Enable(false);
        str1=wxString::Format(_("%.4f"),cli->m0.tail[0]);
        m1Tail1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.tail[1]);
        m1Tail2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.tail[2]);
        m1Tail3->SetValue(str1);
    }
    else if(tbm.type==1)
    {
        str1=wxString::Format(_("%.4f"),cli->m0.head[0]);
        m1Head1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.head[1]);
        m1Head2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.head[2]);
        m1Head3->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.mid[0]);
        m1Mid1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.mid[1]);
        m1Mid2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.mid[2]);
        m1Mid3->SetValue(str1);
        m1Tail1->Enable(false);
        m1Tail2->Enable(false);
        m1Tail3->Enable(false);
    }
    else
    {
        m1Head1->Enable(false);
        m1Head2->Enable(false);
        m1Head3->Enable(false);
        str1=wxString::Format(_("%.4f"),cli->m0.mid[0]);
        m1Mid1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.mid[1]);
        m1Mid2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.mid[2]);
        m1Mid3->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.tail[0]);
        m1Tail1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.tail[1]);
        m1Tail2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),cli->m0.tail[2]);
        m1Tail3->SetValue(str1);
    }
    str1=wxString::Format(_("%.5f"),rad2dms(cli->m0.roll));
    m1Roll->SetValue(str1);
    CalMeasurement();
    str1=wxString::Format(_("%.4f"),cli->m0.prism[0]);
    m1Prism1->SetValue(str1);
    str1=wxString::Format(_("%.4f"),cli->m0.prism[1]);
    m1Prism2->SetValue(str1);

    str1=wxString::Format(_("%.4f"),cli->m0.prism[2]);
    m1Prism3->SetValue(str1);
    dbval=cli->m0.inc[0]*PI/180.0;
    str1=wxString::Format(_("%.5f"),rad2dms(dbval));
    m1Inc1->SetValue(str1);
    dbval=cli->m0.inc[1]*PI/180.0;
    str1=wxString::Format(_("%.5f"),rad2dms(dbval));
    m1Inc2->SetValue(str1);
    dbval=cli->m0.inc[2]*PI/180.0;
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
    prj=cli->prj;
    str1=wxString(prj.name,wxConvUTF8);
    prjName->SetValue(str1);

    str1=wxString::Format(_("%.4f"),prj.mile1);
    prjMile1->SetValue(str1);

    str1=wxString::Format(_("%.4f"),prj.mile2);
    prjMile2->SetValue(str1);

    //if(prj.duty==0) prj.duty=2;
    if(prj.duty==2)
    {
        prjStaticText9->Show(true);
        prjStaticText10->Show(false);
        prjStaticText11->Show(false);
        prjTime2Panel->Show(true);
        prjTime3Panel->Show(false);
        prjTime4Panel->Show(false);
    }
    else if(prj.duty==3)
    {
        prjStaticText9->Show(true);
        prjStaticText10->Show(true);
        prjStaticText11->Show(false);
        prjTime2Panel->Show(true);
        prjTime3Panel->Show(true);
        prjTime4Panel->Show(false);
    }
    else if(prj.duty==4)
    {
        prjStaticText9->Show(true);
        prjStaticText10->Show(true);
        prjStaticText11->Show(true);
        prjTime2Panel->Show(true);
        prjTime3Panel->Show(true);
        prjTime4Panel->Show(true);
    }

    if(prj.t1[0]==0)
    {
        prj.t1[0]=7*3600+30*60;
    }
    if(prj.t2[0]==0)
    {
        prj.t2[0]=19*3600+30*60;
    }
    if(prj.t1[1]==0)
    {
        prj.t1[1]=prj.t2[0];
    }
    if(prj.t2[1]==0)
    {
        prj.t2[1]=prj.t1[0];
    }

    t1=prj.t1[0]/3600;
    if(t1<10)
    {
        str1=_("0")+wxString::Format(_("%d"),t1);
    }
    else
    {
        str1=wxString::Format(_("%d"),t1);
    }
    t2=prj.t1[0]-t1*3600;
    t2=t2/60;
    if(t2<10)
    {
        str2=_("0")+wxString::Format(_("%d"),t2);
    }
    else
    {
        str2=wxString::Format(_("%d"),t2);
    }
    prjDuty1hour1->SetValue(str1);
    prjDuty1min1->SetValue(str2);
    t1=prj.t2[0]/3600;

    if(t1<10)
    {
        str1=_("0")+wxString::Format(_("%d"),t1);
    }
    else
    {
        str1=wxString::Format(_("%d"),t1);
    }
    t2=prj.t2[0]-t1*3600;
    t2=t2/60;
    if(t2<10)
    {
        str2=_("0")+wxString::Format(_("%d"),t2);
    }
    else
    {
        str2=wxString::Format(_("%d"),t2);
    }
    prjDuty1hour2->SetValue(str1);
    prjDuty1min2->SetValue(str2);

    t1=prj.t1[1]/3600;
    if(t1<10)
    {
        str1=_("0")+wxString::Format(_("%d"),t1);
    }
    else
    {
        str1=wxString::Format(_("%d"),t1);
    }
    t2=prj.t1[1]-t1*3600;
    t2=t2/60;
    if(t2<10)
    {
        str2=_("0")+wxString::Format(_("%d"),t2);
    }
    else
    {
        str2=wxString::Format(_("%d"),t2);
    }
    prjDuty2hour1->SetValue(str1);
    prjDuty2min1->SetValue(str2);

    t1=prj.t2[1]/3600;
    if(t1<10)
    {
        str1=_("0")+wxString::Format(_("%d"),t1);
    }
    else
    {
        str1=wxString::Format(_("%d"),t1);
    }
    t2=prj.t2[1]-t1*3600;
    t2=t2/60;
    if(t2<10)
    {
        str2=_("0")+wxString::Format(_("%d"),t2);
    }
    else
    {
        str2=wxString::Format(_("%d"),t2);
    }
    prjDuty2hour2->SetValue(str1);
    prjDuty2min2->SetValue(str2);


    t1=prj.t1[2]/3600;
    if(t1<10)
    {
        str1=_("0")+wxString::Format(_("%d"),t1);
    }
    else
    {
        str1=wxString::Format(_("%d"),t1);
    }
    t2=prj.t1[2]-t1*3600;
    t2=t2/60;
    if(t2<10)
    {
        str2=_("0")+wxString::Format(_("%d"),t2);
    }
    else
    {
        str2=wxString::Format(_("%d"),t2);
    }
    prjDuty3hour1->SetValue(str1);
    prjDuty3min1->SetValue(str2);

    t1=prj.t2[2]/3600;
    if(t1<10)
    {
        str1=_("0")+wxString::Format(_("%d"),t1);
    }
    else
    {
        str1=wxString::Format(_("%d"),t1);
    }
    t2=prj.t2[2]-t1*3600;
    t2=t2/60;
    if(t2<10)
    {
        str2=_("0")+wxString::Format(_("%d"),t2);
    }
    else
    {
        str2=wxString::Format(_("%d"),t2);
    }
    prjDuty3hour2->SetValue(str1);
    prjDuty3min2->SetValue(str2);


    t1=prj.t1[3]/3600;
    if(t1<10)
    {
        str1=_("0")+wxString::Format(_("%d"),t1);
    }
    else
    {
        str1=wxString::Format(_("%d"),t1);
    }
    t2=prj.t1[3]-t1*3600;
    t2=t2/60;
    if(t2<10)
    {
        str2=_("0")+wxString::Format(_("%d"),t2);
    }
    else
    {
        str2=wxString::Format(_("%d"),t2);
    }
    prjDuty4hour1->SetValue(str1);
    prjDuty4min1->SetValue(str2);

    t1=prj.t2[3]/3600;
    if(t1<10)
    {
        str1=_("0")+wxString::Format(_("%d"),t1);
    }
    else
    {
        str1=wxString::Format(_("%d"),t1);
    }
    t2=prj.t2[3]-t1*3600;
    t2=t2/60;
    if(t2<10)
    {
        str2=_("0")+wxString::Format(_("%d"),t2);
    }
    else
    {
        str2=wxString::Format(_("%d"),t2);
    }
    prjDuty4hour2->SetValue(str1);
    prjDuty4min2->SetValue(str2);


    str1=wxString::Format(_("%.3f"),prj.tip);
    keyTip->SetValue(str1);

    nks=cli->nks;
    for(int i=0;i<nks;i++)
    {
        keys[i]=cli->keys[i];
    }

    ///盾构机设置
    tbm=cli->tbm;
    if(tbm.type==0)
    {
        tbmD5->Enable(false);
        tbmL3->Enable(false);
        tbmL4->Enable(false);
    }
    str1=wxString(tbm.name,wxConvUTF8);
    tbmIndex->SetValue(str1);

    str1=wxString::Format(_("%.1f"),tbm.D[4]*1000.0);
    tbmD4->SetValue(str1);
    str1=wxString::Format(_("%.1f"),tbm.D[5]*1000.0);
    tbmD5->SetValue(str1);
    str1=wxString::Format(_("%.1f"),tbm.L[0]*1000.0);
    tbmL0->SetValue(str1);
    str1=wxString::Format(_("%.1f"),tbm.L[1]*1000.0);
    tbmL1->SetValue(str1);
    str1=wxString::Format(_("%.1f"),tbm.L[2]*1000.0);
    tbmL2->SetValue(str1);
    str1=wxString::Format(_("%.1f"),tbm.L[3]*1000.0);
    tbmL3->SetValue(str1);
    str1=wxString::Format(_("%.1f"),tbm.L[4]*1000.0);
    tbmL4->SetValue(str1);

    ///激光靶设置
    tars=cli->tarset;
    str1=wxString::Format(_("%.1f"),tars.prc);
    tarsPrism->SetValue(str1);
    //tarsPrism->Value=str1;
    str1=wxString(cli->camset[0].name,wxConvLocal);
    tarsFile->SetValue(str1);

    ///全站仪设置
    tps=cli->tps;
    str1=wxString::Format(_("%.4f"),tps.laserdist);
    tpsLaserDist->SetValue(str1);
    str1=wxString::Format(_("%.1f"),tps.laserx*1000.0);
    tpsLaserDevX->SetValue(str1);
    str1=wxString::Format(_("%.1f"),tps.lasery*1000.0);
    tpsLaserDevY->SetValue(str1);

    ///管环设置
    segset=cli->segset;
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
    nblk=cli->nblk;
    for(int i=0;i<nblk;i++)
    {
        blocks[i]=cli->blocks[i];
    }

    ///测量设置
    measet=cli->sets;
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

    ///用户管理
    nuser=cli->nuser;
    for(int i=0;i<nuser;i++)
    {
        user[i]=cli->user[i];
    }

    ///初始姿态
    m1=cli->m0;
    if(tbm.type==0)
    {
        str1=wxString::Format(_("%.4f"),m1.head[0]);
        m1Head1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.head[1]);
        m1Head2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.head[2]);
        m1Head3->SetValue(str1);
        m1Mid1->Enable(false);
        m1Mid2->Enable(false);
        m1Mid3->Enable(false);
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
        str1=wxString::Format(_("%.4f"),m1.mid[0]);
        m1Mid1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.mid[1]);
        m1Mid2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.mid[2]);
        m1Mid3->SetValue(str1);
        m1Tail1->Enable(false);
        m1Tail2->Enable(false);
        m1Tail3->Enable(false);
    }
    else
    {
        m1Head1->Enable(false);
        m1Head2->Enable(false);
        m1Head3->Enable(false);
        str1=wxString::Format(_("%.4f"),m1.mid[0]);
        m1Mid1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.mid[1]);
        m1Mid2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.mid[2]);
        m1Mid3->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.tail[0]);
        m1Tail1->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.tail[1]);
        m1Tail2->SetValue(str1);
        str1=wxString::Format(_("%.4f"),m1.tail[2]);
        m1Tail3->SetValue(str1);
    }
    str1=wxString::Format(_("%.5f"),rad2dms(m1.roll));
    m1Roll->SetValue(str1);
    CalMeasurement();
    str1=wxString::Format(_("%.4f"),m1.prism[0]);
    m1Prism1->SetValue(str1);
    str1=wxString::Format(_("%.4f"),m1.prism[1]);
    m1Prism2->SetValue(str1);


    str1=wxString::Format(_("%.4f"),m1.prism[2]);
    m1Prism3->SetValue(str1);
    dbval=m1.inc[0]*PI/180.0;
    str1=wxString::Format(_("%.5f"),rad2dms(dbval));
    m1Inc1->SetValue(str1);
    dbval=m1.inc[1]*PI/180.0;
    str1=wxString::Format(_("%.5f"),rad2dms(dbval));
    m1Inc2->SetValue(str1);
    dbval=m1.inc[2]*PI/180.0;
    str1=wxString::Format(_("%.5f"),rad2dms(dbval));
    m1Inc3->SetValue(str1);

    mp=cli->mp;
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
    m1CP31->SetValue(str1);
    str1=wxString::Format(_("%.4f"),mp.prism[7]);
    m1CP32->SetValue(str1);
    str1=wxString::Format(_("%.4f"),mp.prism[8]);
    m1CP33->SetValue(str1);

    ///远程监控
    wxString ip1=wxEmptyString;
    wxString ip2=wxEmptyString;
    wxString ip3=wxEmptyString;
    wxString ip4=wxEmptyString;
    //wxMessageBox(str1);

    int len = str1.length();
    int j = 0;
    for(int i=0;i<len;i++)
    {
        str2 = str1.Left(1);
        str1 = str1.Remove(0,1);
        if(str2.Cmp(_("."))==0)
        {
            j++;
            str2 = _("");
        }
        if(j==0)
        {
            ip1=ip1+str2;
        }
        if(j==1)
        {
            ip2=ip2+str2;
        }
        if(j==2)
        {
            ip3=ip3+str2;
        }
        if(j==3)
        {
            ip4=ip4+str2;
        }
    }
    remIP1->SetValue(ip1);
    remIP2->SetValue(ip2);
    remIP3->SetValue(ip3);
    remIP4->SetValue(ip4);

    ///管环监测
    smonitor=cli->smonitor;
    if(smonitor.monitor==1)
    {
        smNumber->Enable(true);
        str1=wxString::Format(_("%d"),smonitor.number);
        smNumber->SetValue(str1);
        smTime->Enable(true);
        str1=wxString::Format(_("%d"),smonitor.cycle);
        smTime->SetValue(str1);
        smLast->Enable(true);
        str1=wxString::Format(_("%d"),smonitor.last);
        smLast->SetValue(str1);
        smX->Enable(true);
        str1=wxString::Format(_("%.4f"),smonitor.x);
        smX->SetValue(str1);
        smY->Enable(true);
        str1=wxString::Format(_("%.4f"),smonitor.y);
        smY->SetValue(str1);
        smZ->Enable(true);
        str1=wxString::Format(_("%.4f"),smonitor.z);
        smZ->SetValue(str1);
    }
    else
    {
        smNumber->Enable(false);
        smTime->Enable(false);
        smLast->Enable(false);
        smX->Enable(false);
        smY->Enable(false);
        smZ->Enable(false);
    }

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

        y1=9;
        w1=32;
        h1=26;
        x1=9;
        figButton[ID_FIG_IMPORT].x=x1;
        figButton[ID_FIG_IMPORT].y=y1;
        figButton[ID_FIG_IMPORT].width=w1;
        figButton[ID_FIG_IMPORT].height=h1;
        if(motion1==ID_FIG_IMPORT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[3]);
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            if(bmpImportPrj[1].IsOk())
            {
                w2=bmpImportPrj[1].GetWidth();
                h2=bmpImportPrj[1].GetHeight();
                memDC.DrawBitmap(bmpImportPrj[1],x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            if(bmpImportPrj[0].IsOk())
            {
                w2=bmpImportPrj[0].GetWidth();
                h2=bmpImportPrj[0].GetHeight();
                memDC.DrawBitmap(bmpImportPrj[0],x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        x1=x1+w1+7;
        figButton[ID_FIG_EXPORT].x=x1;
        figButton[ID_FIG_EXPORT].y=y1;
        figButton[ID_FIG_EXPORT].width=w1;
        figButton[ID_FIG_EXPORT].height=h1;
        if(motion1==ID_FIG_EXPORT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[3]);
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            if(bmpExportPrj[1].IsOk())
            {
                w2=bmpExportPrj[1].GetWidth();
                h2=bmpExportPrj[1].GetHeight();
                memDC.DrawBitmap(bmpExportPrj[1],x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);

            if(bmpExportPrj[0].IsOk())
            {
                w2=bmpExportPrj[0].GetWidth();
                h2=bmpExportPrj[0].GetHeight();
                memDC.DrawBitmap(bmpExportPrj[0],x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+7;
        figButton[ID_FIG_CLEAR].x=x1;
        figButton[ID_FIG_CLEAR].y=y1;
        figButton[ID_FIG_CLEAR].width=w1;
        figButton[ID_FIG_CLEAR].height=h1;
        if(motion1==ID_FIG_CLEAR)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[3]);
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);

            if(bmpClearPrj[1].IsOk())
            {
                w2=bmpClearPrj[1].GetWidth();
                h2=bmpClearPrj[1].GetHeight();
                memDC.DrawBitmap(bmpClearPrj[1],x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);

            if(bmpClearPrj[0].IsOk())
            {
                w2=bmpClearPrj[0].GetWidth();
                h2=bmpClearPrj[0].GetHeight();
                memDC.DrawBitmap(bmpClearPrj[0],x1+w1/2-w2/2,y1+h1/2-h2/2);
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
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[3]);
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
        figButton[ID_FIG_APPLY].x=x1;
        figButton[ID_FIG_APPLY].y=y1;
        figButton[ID_FIG_APPLY].width=w1;
        figButton[ID_FIG_APPLY].height=h1;
        int n=panelButtonList->GetNumberButtons();
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
                memDC.SetPen(btnPen[1]);
                memDC.SetBrush(ibrush[3]);
                memDC.SetTextForeground(btnTextColor[1]);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(117,117,117)));
                memDC.SetBrush(wxBrush(wxColor(248,248,248)));
                memDC.SetTextForeground(btnTextColor[0]);
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

        panelButtonList->GetSize(&w1,0);
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
        if(x>figButton[ID_FIG_QUIT].x && x<figButton[ID_FIG_QUIT].x+figButton[ID_FIG_QUIT].width)
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
        if(prjModified==1 || keyModified==1 || tbmModified==1 || tarsModified==1 || tpsModified==1 || segModified==1 || blockModified==1 || m1Modified==1 || settingModified==1 || userModified==1)
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

        if(motion1==ID_FIG_IMPORT)
        {
            ImportDB();
        }
        else if(motion1==ID_FIG_EXPORT)
        {
            ExportDB();
        }
        else if(motion1==ID_FIG_CLEAR)
        {
            ClearDB();
        }
        else if(motion1==ID_FIG_APPLY)
        {
            //if(cli->threadType==MTG_THREAD_ORIGIN)
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
        wxFileDialog fileDlg(this,_("选择待还原的工程文件"),wxEmptyString,wxEmptyString,_("工程文件(*.prj)|*.prj"),wxFD_OPEN);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            wxString strCmd=_("mysql -u root -p123 db_laser <\"")+strFile+_("\"");
            bool bRet=wxShell(strCmd);
            //wxMessageBox(strCmd);
            //wxProcess *p=new wxProcess;
            //p->Redirect();///屏闭shell窗口信息
            //int code = wxExecute(strCmd, wxEXEC_SYNC,p);
            if(bRet)
            {
                wxMessageBox(_("数据已还原！"),_("提示"));
                //mtg_import_db(cli);
                LoadDataBase();
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
    if(fileDlg.ShowModal()==wxID_OK)
    {
        wxString strFile=fileDlg.GetPath();
        wxString strCmd=_("mysqldump -u root -p123 db_laser >\"")+strFile+_("\"");
        bool bRet=wxShell(strCmd);

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
        //mtg_init_db(cli);
        //mtg_import_db(cli);
        LoadDataBase();
        wxMessageBox(_("数据已清空！"),_("提示"));
    }
}

void ConfigDlg::ModifyPrj()
{
    char msg[4096];
    sprintf(msg,"%%R1Q,2:'%s',%lf,%lf,%d,%d,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%d,%d,%lf,%d\n",
            prj.name,prj.mile1,prj.mile2,prj.a2z,prj.duty,prj.t1[0],prj.t2[0],prj.t1[1],prj.t2[1],prj.t1[2],prj.t2[2],prj.t1[3],prj.t2[3],
            prj.htip,prj.vtip,prj.tip,prj.dta);
    sock->Write(msg,strlen(msg));
    time(&t1);
    sprintf(cmd,"%%R1Q,2:\n");
    cli->iget=1;
}

void ConfigDlg::ModifyKey()
{
    char msg[512];
    sprintf(msg,"%%R1Q,14:0:%d\n",nks);
    sock->Write(msg,strlen(msg));
    time(&t1);
    strcpy(msg,cmd);
    cli->iget=1;
    for(int i=0; i<nks; i++)
    {
        sprintf(msg,"%%R1Q,14:1,%d,'%s',%lf,%lf\n",i,keys[i].name,keys[i].mile1,keys[i].mile2);
        sock->Write(msg,strlen(msg));
        time(&t1);
    }
}

void ConfigDlg::ModifyTBM()
{
    char msg[4096];
    sprintf(msg,"%%R1Q,17:'%s',%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
                 cli->tbm.name,cli->tbm.type,cli->tbm.mode,cli->tbm.D[0],cli->tbm.D[1],cli->tbm.D[2],cli->tbm.D[3],
                 cli->tbm.D[4],cli->tbm.D[5],cli->tbm.L[0],cli->tbm.L[1],cli->tbm.L[2],cli->tbm.L[3],cli->tbm.L[4]);
    sock->Write(msg,strlen(msg));
}

void ConfigDlg::ModifyTar()
{
    char msg[4096];
    sprintf(msg,"%%R1Q,20:%lf,%lf,%lf,%lf,%lf,%d,%d\n",
         cli->tarset.prism[0],cli->tarset.prism[1],cli->tarset.prism[2],cli->tarset.prc,cli->tarset.length,
         cli->tarset.cam,cli->tarset.inc);
    sock->Write(msg,strlen(msg));
}

void ConfigDlg::ModifyTPS()
{
    char msg[4096];
    sprintf(msg,"%%R1Q,26:%d,%lf,%lf,%lf,%lf\n",
        cli->tps.lasertype,cli->tps.laserheight,cli->tps.laserdist,cli->tps.laserx,cli->tps.lasery);
    sock->Write(msg,strlen(msg));
}

void ConfigDlg::ModifySeg()
{
    char msg[4096];
    sprintf(msg,"%%R1Q,29:%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%d,%lf,%lf,%d\n",
        cli->segset.type,cli->segset.in,cli->segset.f2b,cli->segset.l2s,cli->segset.L,
        cli->segset.De,cli->segset.D,cli->segset.Dn,cli->segset.Ks,cli->segset.G0,cli->segset.G1,cli->segset.s2s);
    sock->Write(msg,strlen(msg));
}

void ConfigDlg::ModifyBlock()
{
    char msg[4096];
    sprintf(msg,"%%R1Q,32:0:%d\n",cli->nblk);
    sock->Write(msg,strlen(msg));
    for(int i=0;i<cli->nblk;i++)
    {
        sprintf(msg,"%%R1Q,32:1:%d,'%s',%lf\n",i,cli->blocks[i].name,cli->blocks[i].angle);
        sock->Write(msg,strlen(msg));
    }
}

void ConfigDlg::ModifyGiven()
{
    char msg[4096];
    sprintf(msg,"%%R1Q,8:%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
           %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
           %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%ld,%ld,%ld,%d\n",
         cli->m0.inc[0],cli->m0.inc[1],cli->m0.inc[1],
         cli->m0.cam[0],cli->m0.cam[1],cli->m0.cam[2],cli->m0.cam[3],
         cli->m0.prism[0],cli->m0.prism[1],cli->m0.prism[2],
         cli->m0.angle[0],cli->m0.angle[1],
         cli->m0.comp[0],cli->m0.comp[1],
         cli->m0.head[0],cli->m0.head[1],cli->m0.head[2],
         cli->m0.hdes[0],cli->m0.hdes[1],cli->m0.hdes[2],
         cli->m0.headc,cli->m0.headh,cli->m0.headv,
         cli->m0.tail[0],cli->m0.tail[1],cli->m0.tail[2],
         cli->m0.tdes[0],cli->m0.tdes[1],cli->m0.tdes[2],
         cli->m0.tailc,cli->m0.tailh,cli->m0.tailv,
         cli->m0.mid[0],cli->m0.mid[1],cli->m0.mid[2],
         cli->m0.mdes[0],cli->m0.mdes[1],cli->m0.mdes[2],
         cli->m0.midc,cli->m0.midh,cli->m0.midv,
         cli->m0.midj[0],cli->m0.midj[1],cli->m0.midj[2],cli->m0.midj[3],
         cli->m0.roll,cli->m0.pitch,cli->m0.azimuth,
         cli->m0.iseg,(long)cli->m0.t1,(long)cli->m0.t2,(long)cli->m0.t3,cli->m0.iset
         );
    sock->Write(msg,strlen(msg));
}

void ConfigDlg::ModifyMP()
{
    char msg[4096];
    //sprintf(msg,"%%R1Q,34:%d,%d,%d,%d,%lf,%lf,%lf,%ld\n",
        //cli->smonitor.number,cli->smonitor.monitor,cli->smonitor.cycle,cli->smonitor.last,cli->smonitor.x,cli->smonitor.y,cli->smonitor.z,(long)cli->smonitor.t);
    //sock->Write(msg,strlen(msg));
}

void ConfigDlg::ModifySettings()
{
    char msg[4096];
    sprintf(msg,"%%R1Q,11:%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\
            %d,%d,%lf,%lf,%d\n",
            cli->sets.cyc,cli->sets.bcyc,cli->sets.palw,cli->sets.jalw,cli->sets.balw,cli->sets.talw,
            cli->sets.vibration,cli->sets.rstn,cli->sets.tsyn,cli->sets.rget,cli->sets.idrv,cli->sets.prun,cli->sets.pend,
            cli->sets.psas,cli->sets.pchk,cli->sets.pqry,cli->sets.pmap,cli->sets.psmr,cli->sets.pquit,cli->sets.unit,
            cli->sets.vmileage,cli->sets.head,cli->sets.tbm3d,cli->sets.heading,cli->sets.povr,cli->sets.jovr,cli->sets.tovr,
            cli->sets.bovr,cli->sets.toEr,cli->sets.flen,cli->sets.fdev,cli->sets.lang);
    sock->Write(msg,strlen(msg));
}

void ConfigDlg::ModifySmonitor()
{
    char msg[4096];
    sprintf(msg,"%%R1Q,35:%d,%d,%d,%d,%lf,%lf,%lf,%ld\n",
            cli->smonitor.number,cli->smonitor.monitor,cli->smonitor.cycle,cli->smonitor.last,cli->smonitor.x,cli->smonitor.y,cli->smonitor.z,(long)cli->smonitor.t);
    sock->Write(msg,strlen(msg));
}

void ConfigDlg::ModifyUser()
{
    char msg[4096];
    sprintf(msg,"%%R1Q,41:0:%d\n",cli->nuser);
    sock->Write(msg,strlen(msg));
    for(int i=0; i<cli->nuser; i++)
    {
        sprintf(msg,"%%R1Q,41:1:%d,'%s','%s',%d\n",i,cli->user[i].name,cli->user[i].password,cli->user[i].level);
        sock->Write(msg,strlen(msg));
    }
}

void ConfigDlg::Apply()
{
    if(cli->imode==1)
    {
        if(keyModified==1)
        {
            ModifyKey();
        }
        if(userModified==1)
        {
            ModifyUser();
        }
        if(segModified==1)
        {
            ModifySeg();
        }
        if(blockModified==1)
        {
            ModifyBlock();
        }
        if(settingModified==1)
        {
            ModifySettings();
        }

        if(opLevel==1)
        {
            WriteMsg(_("需要管理员权限"),1);
            return;
        }

        if(prjModified==1)
        {
            ModifyPrj();
        }
        if(tbmModified==1)
        {
            ModifyTBM();
        }
        if(tarsModified==1)
        {
            ModifyTar();
        }
        if(tpsModified==1)
        {
            ModifyTPS();
        }
        if(m1Modified==1)
        {
            ModifyGiven();
        }
        if(mpModified==1)
        {
            ModifyMP();
        }
        if(smModified==1)
        {
            ModifySmonitor();
        }
    }
    else
    {
        WriteMsg(_("需要切换至控制模式！"),1);
    }


    /*int n=panelButtonList->GetNumberButtons();
    for(int i=0;i<n;i++)
    {
        modified[i]=0;
    }*/
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

void ConfigDlg::CalMeasurement()
{
    double x1,y1,z1,x2,y2,z2;
    double d1,d2,d3;
    double rj = cli->tbm.D[3];
    double azi,pitch,dazi,dpitch;
    double dx,dy,dz;
    double midj[4];
    double mid[3];
    wxString str1=wxEmptyString;

    if(tbm.type==0)
    {
        m1Head1->GetValue().ToDouble(&x1);
        m1Head2->GetValue().ToDouble(&y1);
        m1Head3->GetValue().ToDouble(&z1);
        m1Tail1->GetValue().ToDouble(&x2);
        m1Tail2->GetValue().ToDouble(&y2);
        m1Tail3->GetValue().ToDouble(&z2);
        dx=x1-x2;
        dy=y1-y2;
        dz=z1-z2;
        azi=atan2(dy,dx);
        if(azi<0.0) azi+=2.0*PI;
        str1=wxString::Format(_("%.5f"),rad2dms(azi));
        m1Azi->SetValue(str1);

        m1Azi->Enable(false);
        d1=dx*dx+dy*dy;
        d1=sqrt(d1);
        if(d1==0.0)
        {
            pitch=0.0;
        }
        else
        {
            pitch=atan(dz/d1);
        }
        str1=wxString::Format(_("%.5f"),rad2dms(pitch));
        m1Pitch->SetValue(str1);
        m1Pitch->Enable(false);
    }
    else if(tbm.type==1)
    {
        m1Head1->GetValue().ToDouble(&x1);
        m1Head2->GetValue().ToDouble(&y1);
        m1Head3->GetValue().ToDouble(&z1);
        m1Mid1->GetValue().ToDouble(&x2);
        m1Mid2->GetValue().ToDouble(&y2);
        m1Mid3->GetValue().ToDouble(&z2);
        dx=x1-x2;
        dy=y1-y2;
        dz=z1-z2;
        azi=atan2(dy,dx);
        if(azi<0.0) azi+=2.0*PI;
        str1=wxString::Format(_("%.5f"),rad2dms(azi));
        m1Azi->SetValue(str1);

        m1Azi->Enable(false);
        d1=dx*dx+dy*dy;
        d1=sqrt(d1);
        if(d1==0.0)
        {
            pitch=0.0;
        }
        else
        {
            pitch=atan(dz/d1);
        }
        //pitch=atan(dz/d1);
        str1=wxString::Format(_("%.5f"),rad2dms(pitch));
        m1Pitch->SetValue(str1);
        m1Pitch->Enable(false);
    }
    else
    {
        m1Mid1->GetValue().ToDouble(&x1);
        m1Mid2->GetValue().ToDouble(&y1);
        m1Mid3->GetValue().ToDouble(&z1);
        m1Tail1->GetValue().ToDouble(&x2);
        m1Tail2->GetValue().ToDouble(&y2);
        m1Tail3->GetValue().ToDouble(&z2);
        dx=x1-x2;
        dy=y1-y2;
        dz=z1-z2;
        azi=atan2(dy,dx);
        if(azi<0.0) azi+=2.0*PI;
        str1=wxString::Format(_("%.5f"),rad2dms(azi));
        m1Azi->SetValue(str1);
        m1Azi->Enable(false);
        d1=dx*dx+dy*dy;
        d1=sqrt(d1);
        if(d1==0.0)
        {
            pitch=0.0;
        }
        else
        {
            pitch=atan(dz/d1);
        }
        //pitch=atan(dz/d1);
        str1=wxString::Format(_("%.5f"),rad2dms(pitch));
        m1Pitch->SetValue(str1);
        m1Pitch->Enable(false);
    }
}

void ConfigDlg::IsModified()
{
    wxString str,str1;
    long lval;
    double dbval;
    int page=panelButtonList->btn_clicked;

    if(page==0)
    {
        modified[page]=0;
        str=prjName->GetValue();
        strncpy(prj.name,str.mb_str(wxConvUTF8),64);
        str=prjMile1->GetValue();
        str.ToDouble(&prj.mile1);
        str=prjMile2->GetValue();
        str.ToDouble(&prj.mile2);

        if(prj.mile1<=prj.mile2)
        {
            prj.a2z=1;
        }
        else
        {
            prj.a2z=-1;
        }

        str=prjDuty1hour1->GetValue();
        str.ToLong(&lval);
        prj.t1[0]=lval*3600;
        str=prjDuty1min1->GetValue();
        str.ToLong(&lval);
        prj.t1[0]=prj.t1[0]+lval*60;
        str=prjDuty1hour2->GetValue();
        str.ToLong(&lval);
        prj.t2[0]=lval*3600;
        str=prjDuty1min2->GetValue();
        str.ToLong(&lval);
        prj.t2[0]=prj.t2[0]+lval*60;

        str=prjDuty2hour1->GetValue();
        str.ToLong(&lval);
        prj.t1[1]=lval*3600;
        str=prjDuty2min1->GetValue();
        str.ToLong(&lval);
        prj.t1[1]=prj.t1[1]+lval*60;
        str=prjDuty2hour2->GetValue();
        str.ToLong(&lval);
        prj.t2[1]=lval*3600;
        str=prjDuty2min2->GetValue();
        str.ToLong(&lval);
        prj.t2[1]=prj.t2[1]+lval*60;

        str=prjDuty3hour1->GetValue();
        str.ToLong(&lval);
        prj.t1[2]=lval*3600;
        str=prjDuty3min1->GetValue();
        str.ToLong(&lval);
        prj.t1[2]=prj.t1[2]+lval*60;
        str=prjDuty3hour2->GetValue();
        str.ToLong(&lval);
        prj.t2[2]=lval*3600;
        str=prjDuty3min2->GetValue();
        str.ToLong(&lval);
        prj.t2[2]=prj.t2[2]+lval*60;

        str=prjDuty4hour1->GetValue();
        str.ToLong(&lval);
        prj.t1[3]=lval*3600;
        str=prjDuty4min1->GetValue();
        str.ToLong(&lval);
        prj.t1[3]=prj.t1[3]+lval*60;
        str=prjDuty4hour2->GetValue();
        str.ToLong(&lval);
        prj.t2[3]=lval*3600;
        str=prjDuty4min2->GetValue();
        str.ToLong(&lval);
        prj.t2[3]=prj.t2[3]+lval*60;

        str=prjName->GetValue();
        str1=wxString(cli->prj.name,wxConvUTF8);
        if(str.Cmp(str1)!=0)
        {
            prjModified=1;
            modified[page]=1;
            return;
        }
        else if(prj.mile1!=cli->prj.mile1)
        {
            prjModified=1;
            modified[page]=1;
            return;
        }
        else if(prj.mile2!=cli->prj.mile2)
        {
            prjModified=1;
            modified[page]=1;
            return;
        }
        else if(prj.a2z!=cli->prj.a2z)
        {
            prjModified=1;
            modified[page]=1;
            return;
        }
        else if(prj.duty!=cli->prj.duty)
        {
            prjModified=1;
            modified[page]=1;
            return;
        }
        else if(prj.duty==cli->prj.duty)
        {
            for(int i=0;i<prj.duty;i++)
            {
                if(prj.t1[i]!=cli->prj.t1[i])
                {
                    prjModified=1;
                    modified[page]=1;
                    return;
                }
                if(prj.t2[i]!=cli->prj.t2[i])
                {
                    prjModified=1;
                    modified[page]=1;
                    return;
                }
            }
        }
    }
    else if(page==1)
    {
        modified[page]=0;
        str=keyTip->GetValue();
        str.ToDouble(&prj.tip);

        if(prj.tip!=cli->prj.tip)
        {
            prjModified=1;
            modified[page]=1;
        }
        else if(prj.htip!=cli->prj.htip)
        {
            prjModified=1;
            modified[page]=1;
        }
        else if(prj.vtip!=cli->prj.vtip)
        {
            prjModified=1;
            modified[page]=1;
        }

        if(nks!=cli->nks)
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
                str1=wxString(cli->keys[i].name,wxConvUTF8);
                if(str.Cmp(str1)!=0)
                {
                    keyModified=1;
                    modified[page]=1;
                    break;
                }
                if(keys[i].mile1!=cli->keys[i].mile1)
                {
                    keyModified=1;
                    modified[page]=1;
                    break;
                }
                if(keys[i].mile2!=cli->keys[i].mile2)
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

        str=tbmD4->GetValue();
        str.ToDouble(&tbm.D[4]);
        tbm.D[4]=tbm.D[4]/1000.0;
        str=tbmD5->GetValue();
        str.ToDouble(&tbm.D[5]);
        tbm.D[5]=tbm.D[5]/1000.0;
        str=tbmL0->GetValue();
        str.ToDouble(&tbm.L[0]);
        tbm.L[0]=tbm.L[0]/1000.0;
        str=tbmL1->GetValue();
        str.ToDouble(&tbm.L[1]);
        tbm.L[1]=tbm.L[1]/1000.0;
        str=tbmL2->GetValue();
        str.ToDouble(&tbm.L[2]);
        tbm.L[2]=tbm.L[2]/1000.0;
        str=tbmL3->GetValue();
        str.ToDouble(&tbm.L[3]);
        tbm.L[3]=tbm.L[3]/1000.0;
        str=tbmL4->GetValue();
        str.ToDouble(&tbm.L[4]);
        tbm.L[4]=tbm.L[4]/1000.0;

        str=tbmIndex->GetValue();
        str1=wxString(cli->tbm.name,wxConvUTF8);
        if(str.Cmp(str1)!=0)
        {
            tbmModified=1;
            modified[page]=1;
            return;
        }
        else if(tbm.D[4]!=cli->tbm.D[4])
        {
            tbmModified=1;
            modified[page]=1;
            return;
        }
        else if(tbm.D[5]!=cli->tbm.D[5])
        {
            tbmModified=1;
            modified[page]=1;
            return;
        }
        else if(tbm.L[0]!=cli->tbm.L[0])
        {
            tbmModified=1;
            modified[page]=1;
            return;
        }
        else if(tbm.L[1]!=cli->tbm.L[1])
        {
            tbmModified=1;
            modified[page]=1;
            return;
        }
        else if(tbm.L[2]!=cli->tbm.L[2])
        {
            tbmModified=1;
            modified[page]=1;
            return;
        }
        else if(tbm.L[3]!=cli->tbm.L[3])
        {
            tbmModified=1;
            modified[page]=1;
            return;
        }
        else if(tbm.L[4]!=cli->tbm.L[4])
        {
            tbmModified=1;
            modified[page]=1;
            return;
        }
        else if(tbm.type!=cli->tbm.type)
        {
            tbmModified=1;
            modified[page]=1;
            return;
        }
    }
    else if(page==3)
    {
        modified[page]=0;
        str=tarsPrism->GetValue();
        str.ToDouble(&tars.prc);
        if(tars.prc!=cli->tarset.prc)
        {
            tarsModified=1;
            modified[page]=1;
        }
        else if(tarsModified==1)
        {
            modified[page]=1;
        }
    }
    else if(page==4)
    {
        modified[page]=0;
        str=tpsLaserDist->GetValue();
        str.ToDouble(&tps.laserdist);
        str=tpsLaserDevX->GetValue();
        str.ToDouble(&dbval);
        tps.laserx=dbval/1000.0;
        str=tpsLaserDevY->GetValue();
        str.ToDouble(&dbval);
        tps.lasery=dbval/1000.0;
        if(tps.laserdist!=cli->tps.laserdist)
        {
            tpsModified=1;
            modified[page]=1;
            return;
        }
        else if(tps.laserx!=cli->tps.laserx)
        {
            tpsModified=1;
            modified[page]=1;
            return;
        }
        else if(tps.lasery!=cli->tps.lasery)
        {
            tpsModified=1;
            modified[page]=1;
            return;
        }
        else if(tps.lasertype!=cli->tps.lasertype)
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
        if(segset.L!=cli->segset.L)
        {
            segModified=1;
            modified[page]=1;
            return;
        }
        else if(segset.D!=cli->segset.D)
        {
            segModified=1;
            modified[page]=1;
            return;
        }
        else if(segset.De!=cli->segset.De)
        {
            segModified=1;
            modified[page]=1;
            return;
        }
        else if(segset.Ks!=cli->segset.Ks)
        {
            segModified=1;
            modified[page]=1;
            return;
        }
        else if(segset.G0!=cli->segset.G0)
        {
            segModified=1;
            modified[page]=1;
            return;
        }
        else if(segset.G1!=cli->segset.G1)
        {
            segModified=1;
            modified[page]=1;
            return;
        }
        else if(segset.l2s!=cli->segset.l2s)
        {
            segModified=1;
            modified[page]=1;
            return;
        }
        else if(segset.in!=cli->segset.in)
        {
            segModified=1;
            modified[page]=1;
            return;
        }
        else if(segset.type!=cli->segset.type)
        {
            segModified=1;
            modified[page]=1;
            return;
        }
        else if(segset.f2b!=cli->segset.f2b)
        {
            segModified=1;
            modified[page]=1;
            return;
        }
        else if(segset.s2s!=cli->segset.s2s)
        {
            segModified=1;
            modified[page]=1;
            return;
        }
    }
    else if(page==6)
    {
        modified[page]=0;
        if(nblk!=cli->nblk)
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
                str1=wxString(cli->blocks[i].name,wxConvUTF8);
                if(str.Cmp(str1)!=0)
                {
                    blockModified=1;
                    modified[page]=1;
                    break;
                }
                if(blocks[i].angle!=cli->blocks[i].angle)
                {
                    blockModified=1;
                    modified[page]=1;
                    break;
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

        str=m1Mid1->GetValue();
        str.ToDouble(&m1.mid[0]);
        str=m1Mid2->GetValue();
        str.ToDouble(&m1.mid[1]);
        str=m1Mid2->GetValue();
        str.ToDouble(&m1.mid[2]);

        CalMeasurement();

        str=m1Roll->GetValue();
        str.ToDouble(&dbval);
        m1.roll=dms2rad(dbval);

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
        m1.inc[0]=dms2deg(dbval);

        str=m1Inc2->GetValue();
        str.ToDouble(&dbval);
        m1.inc[1]=dms2deg(dbval);

        str=m1Inc3->GetValue();
        str.ToDouble(&dbval);
        m1.inc[1]=dms2deg(dbval);

        str=m1CP11->GetValue();
        str.ToDouble(&dbval);
        mp.prism[0]=dms2deg(dbval);

        str=m1CP12->GetValue();
        str.ToDouble(&dbval);
        mp.prism[1]=dms2deg(dbval);

        str=m1CP13->GetValue();
        str.ToDouble(&dbval);
        mp.prism[2]=dms2deg(dbval);

        str=m1CP21->GetValue();
        str.ToDouble(&dbval);
        mp.prism[3]=dms2deg(dbval);

        str=m1CP22->GetValue();
        str.ToDouble(&dbval);
        mp.prism[4]=dms2deg(dbval);

        str=m1CP23->GetValue();
        str.ToDouble(&dbval);
        mp.prism[5]=dms2deg(dbval);

        str=m1CP31->GetValue();
        str.ToDouble(&dbval);
        mp.prism[6]=dms2deg(dbval);

        str=m1CP32->GetValue();
        str.ToDouble(&dbval);
        mp.prism[7]=dms2deg(dbval);

        str=m1CP33->GetValue();
        str.ToDouble(&dbval);
        mp.prism[8]=dms2deg(dbval);

        str=m1Inc1->GetValue();
        dbval=cli->m0.inc[0]*PI/180.0;
        str1=wxString::Format(_("%.5f"),rad2dms(dbval));
        if(str.Cmp(str1)!=0)
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }

        str=m1Inc2->GetValue();
        dbval=cli->m0.inc[1]*PI/180.0;
        str1=wxString::Format(_("%.5f"),rad2dms(dbval));
        if(str.Cmp(str1)!=0)
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }

        str=m1Inc3->GetValue();
        dbval=cli->m0.inc[2]*PI/180.0;
        str1=wxString::Format(_("%.5f"),rad2dms(dbval));
        if(str.Cmp(str1)!=0)
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }

        if(m1.head[0]!=cli->m0.head[0])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.head[1]!=cli->m0.head[1])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.head[2]!=cli->m0.head[2])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.tail[0]!=cli->m0.tail[0])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.tail[1]!=cli->m0.tail[1])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.tail[2]!=cli->m0.tail[2])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.mid[0]!=cli->m0.mid[0])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.mid[1]!=cli->m0.mid[1])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.mid[2]!=cli->m0.mid[2])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.roll!=cli->m0.roll)
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.prism[0]!=cli->m0.prism[0])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.prism[1]!=cli->m0.prism[1])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(m1.prism[2]!=cli->m0.prism[2])
        {
            m1Modified=1;
            modified[page]=1;
            return;
        }
        if(mp.prism[0]!=cli->mp.prism[0])
        {
            mpModified=1;
            modified[page]=1;
            return;
        }
        if(mp.prism[1]!=cli->mp.prism[1])
        {
            mpModified=1;
            modified[page]=1;
            return;
        }
        if(mp.prism[2]!=cli->mp.prism[2])
        {
            mpModified=1;
            modified[page]=1;
            return;
        }
        if(mp.prism[3]!=cli->mp.prism[3])
        {
            mpModified=1;
            modified[page]=1;
            return;
        }
        if(mp.prism[4]!=cli->mp.prism[4])
        {
            mpModified=1;
            modified[page]=1;
            return;
        }
        if(mp.prism[5]!=cli->mp.prism[5])
        {
            mpModified=1;
            modified[page]=1;
            return;
        }
        if(mp.prism[6]!=cli->mp.prism[6])
        {
            mpModified=1;
            modified[page]=1;
            return;
        }
        if(mp.prism[7]!=cli->mp.prism[7])
        {
            mpModified=1;
            modified[page]=1;
            return;
        }
        if(mp.prism[8]!=cli->mp.prism[8])
        {
            mpModified=1;
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
        if(measet.cyc!=cli->sets.cyc)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.bcyc!=cli->sets.bcyc)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.palw!=cli->sets.palw)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.jalw!=cli->sets.jalw)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.balw!=cli->sets.balw)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.talw!=cli->sets.talw)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.vibration!=cli->sets.vibration)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.rstn!=cli->sets.rstn)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.tsyn!=cli->sets.tsyn)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.rget!=cli->sets.rget)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.idrv!=cli->sets.idrv)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.prun!=cli->sets.prun)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.pend!=cli->sets.pend)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.psas!=cli->sets.psas)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.pchk!=cli->sets.pchk)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.pqry!=cli->sets.pqry)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.pmap!=cli->sets.pmap)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.psmr!=cli->sets.psmr)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.pquit!=cli->sets.pquit)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
    }
    else if(page==9)
    {
        modified[page]=0;
        if(measet.unit!=cli->sets.unit)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.vmileage!=cli->sets.vmileage)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.head!=cli->sets.head)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.tbm3d!=cli->sets.tbm3d)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.heading!=cli->sets.heading)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.povr!=cli->sets.povr)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.jovr!=cli->sets.jovr)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.tovr!=cli->sets.tovr)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.bovr!=cli->sets.bovr)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
        if(measet.toEr!=cli->sets.toEr)
        {
            settingModified=1;
            modified[page]=1;
            return;
        }
    }
    else if(page==10)
    {
        modified[page]=0;
        str=smNumber->GetValue();
        str.ToDouble(&dbval);
        smonitor.number=dbval;
        str=smTime->GetValue();
        str.ToDouble(&dbval);
        smonitor.cycle=dbval;
        str=smLast->GetValue();
        str.ToDouble(&dbval);
        smonitor.last=dbval;
        str=smX->GetValue();
        str.ToDouble(&dbval);
        smonitor.x=dbval;
        str=smY->GetValue();
        str.ToDouble(&dbval);
        smonitor.y=dbval;
        str=smZ->GetValue();
        str.ToDouble(&dbval);
        smonitor.z=dbval;
        if(smonitor.monitor!=cli->smonitor.monitor)
        {
            smModified=1;
            modified[page]=1;
            return;
        }
        if(smonitor.number!=cli->smonitor.number)
        {
            smModified=1;
            modified[page]=1;
            return;
        }
        if(smonitor.cycle!=cli->smonitor.cycle)
        {
            smModified=1;
            modified[page]=1;
            return;
        }
        if(smonitor.last!=cli->smonitor.last)
        {
            smModified=1;
            modified[page]=1;
            return;
        }
        if(smonitor.x!=cli->smonitor.x)
        {
            smModified=1;
            modified[page]=1;
            return;
        }
        if(smonitor.y!=cli->smonitor.y)
        {
            smModified=1;
            modified[page]=1;
            return;
        }
        if(smonitor.z!=cli->smonitor.z)
        {
            smModified=1;
            modified[page]=1;
            return;
        }
    }
    else if(page==11)
    {
        modified[page]=0;
        str=remIP1->GetValue();
        str=str+_(".")+remIP2->GetValue();
        str=str+_(".")+remIP3->GetValue();
        str=str+_(".")+remIP4->GetValue();
        remIP=str;
    }
    else if(page==12)
    {
        modified[page]=0;
        if(nuser!=cli->nuser)
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
                str1=wxString(cli->user[i].name,wxConvUTF8);
                if(str.Cmp(str1)!=0)
                {
                    userModified=1;
                    modified[page]=1;
                    break;
                }
                str=wxString(user[i].password,wxConvUTF8);
                str1=wxString(cli->user[i].password,wxConvUTF8);
                if(str.Cmp(str1)!=0)
                {
                    userModified=1;
                    modified[page]=1;
                    break;
                }
                if(user[i].level!=cli->user[i].level)
                {
                    userModified=1;
                    modified[page]=1;
                    break;
                }
            }
        }
    }
    else if(page==13)
    {
        modified[page]=0;
        if(measet.lang!=cli->sets.lang)
        {
            settingModified=1;
            modified[page]=1;
        }
    }
}

void ConfigDlg::OnTimer(wxTimerEvent& event)
{
    static int tick=0;
    double dbval=0.0;
    wxString str;
    tick++;
    if(tick % 5==0)
    {
        IsModified();
        panelBottom->Refresh();
    }
    if(tick==1200) tick=0;
}

void ConfigDlg::SettingOut(int t)
{

}
