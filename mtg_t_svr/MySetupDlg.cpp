///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MySetupDlg.h"
#include "mtg_t_svrMain.h"
#include "mtg_t_svrApp.h"
#include "BasketDlg.h"
#include "MypointDlg.h"
#include "StationDlg.h"
#include "ConfirmDlg.h"
#include "dmsrad.h"
#include "HeadMileDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MySetupDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MySetupDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MySetupDlg)
//const long MySetupDlg::ID_PANEL2 = wxNewId();                  //按钮
//*)

MySetupDlg::MySetupDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
    bmpAdmin1.LoadFile(path+_("/plugins/Admin_01.png"),wxBITMAP_TYPE_PNG);
    bmpAdmin2.LoadFile(path+_("/plugins/Admin_02.png"),wxBITMAP_TYPE_PNG);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

	panelButton = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(150,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
	panelButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(150,0), wxSize(w-150,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelNavi = new wxPanel(panelMain, wxID_ANY, wxPoint(600+w,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x1=0;
    y1=11;
    w1=w-150;
    h1=h-57;
    panelStation = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStation->SetBackgroundColour(wxColor(239,239,239));

    x1=14;
    y1=9;

    x2=x1;
    y2=y1;
    w2=(w1-x2*2-75)/5;
    h2=25;
    int gw2=7;
    int gh2=20;
    stnStaticText2 = new wxStaticText(panelStation, wxID_ANY, _("测站"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    stationName = new wxMyTextCtrl(panelStation, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-gw2,h2), 0);
    stationName->Enable(false);
    x2+=w2;
    stnStaticText3 = new wxStaticText(panelStation, wxID_ANY, _("X"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    stationX = new wxMyTextCtrl(panelStation, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-gw2,h2), 0);
    stationX->Enable(false);
    x2+=w2;

    stnStaticText4 = new wxStaticText(panelStation, wxID_ANY, _("Y"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    stationY = new wxMyTextCtrl(panelStation, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-gw2,h2), 0);
    stationY->Enable(false);
    x2+=w2;
    stnStaticText5 = new wxStaticText(panelStation, wxID_ANY, _("Z"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    stationZ = new wxMyTextCtrl(panelStation, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-gw2,h2), 0);
    stationZ->Enable(false);
    x2+=w2;
    stnStaticText6 = new wxStaticText(panelStation, wxID_ANY, _("仪器高(m)"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    stationH = new wxMyTextCtrl(panelStation, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-gw2,h2), 0);
    x2+=w2;
    selectStation = new wxPanel(panelStation, wxID_ANY, wxPoint(w1-x1-65,y2+gh2), wxSize(65,h2-1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    selectStation->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    y2+=55;
    x2=x1;
    stnStaticText8 = new wxStaticText(panelStation, wxID_ANY, _("后视"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    backName = new wxMyTextCtrl(panelStation, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-gw2,h2), 0);
    backName->Enable(false);
    x2+=w2;
    stnStaticText9 = new wxStaticText(panelStation, wxID_ANY, _("X"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    backX = new wxMyTextCtrl(panelStation, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-gw2,h2), 0);
    backX->Enable(false);
    x2+=w2;
    stnStaticText10 = new wxStaticText(panelStation, wxID_ANY, _("Y"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    backY = new wxMyTextCtrl(panelStation, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-gw2,h2), 0);
    backY->Enable(false);
    x2+=w2;
    stnStaticText11 = new wxStaticText(panelStation, wxID_ANY, _("Z"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    backZ = new wxMyTextCtrl(panelStation, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-gw2,h2), 0);
    backZ->Enable(false);
    x2+=w2;
    stnStaticText12 = new wxStaticText(panelStation, wxID_ANY, _("棱镜高(m)"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    backH = new wxMyTextCtrl(panelStation, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-gw2,h2), 0);
    x2+=w2;
    selectBack = new wxPanel(panelStation, wxID_ANY, wxPoint(w1-x1-65,y2+gh2), wxSize(65,h2-1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    selectBack->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x2=x1;
    w2=w1-x1*2-83;
    y2=y2+h2+gh2+18;
    h2=h1-y2-15;
    panelStationFig = new wxPanel(panelStation, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStationFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x2+w2+18;
    w2=65;
    stationButton = new wxPanel(panelStation, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    stationButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w-150;
    h1=h-57;
    panelBasketMeas = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBasketMeas->SetBackgroundColour(wxColor(239,239,239));
    x2=14;
    y2=9;
    w2=180;
    h2=25;
    measStaticText2 = new wxStaticText(panelBasketMeas, wxID_ANY, _("吊篮编号"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    measName = new wxMyTextCtrl(panelBasketMeas, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-25,h2), 0);
    x2=x2+w2+9;
    measStaticText3 = new wxStaticText(panelBasketMeas, wxID_ANY, _("测回数"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    measTurns = new wxMyTextCtrl(panelBasketMeas, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-25,h2), 0);
    x2=x2+w2+9;
    measStaticText4 = new wxStaticText(panelBasketMeas, wxID_ANY, _("棱镜高(m)"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    measHeight = new wxMyTextCtrl(panelBasketMeas, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-25,h2), 0);

    x2=14;
    y2=y2+h2+gh2+11;
    h2=h1-y2-15;
    w2=w1-28-83;

    panelMeasFig = new wxPanel(panelBasketMeas, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMeasFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x2+w2+18;
    w2=65;
    panelBasketButton = new wxPanel(panelBasketMeas, wxID_ANY, wxPoint(x2,y1+gh2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBasketButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w-150;
    h1=h-57;
    panelStudy = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStudy->SetBackgroundColour(wxColor(239,239,239));

    x2=14;
    y2=9;
    w2=130;
    h2=25;
    studyStaticText1 = new wxStaticText(panelStudy, wxID_ANY, _("北坐标（X）"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    studyX = new wxMyTextCtrl(panelStudy, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-25,h2), 0);
    x2=x2+w2+9;
    studyStaticText2 = new wxStaticText(panelStudy, wxID_ANY, _("东坐标（Y）"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    studyY = new wxMyTextCtrl(panelStudy, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-25,h2), 0);
    x2=x2+w2+9;
    studyStaticText3 = new wxStaticText(panelStudy, wxID_ANY, _("高程（Z）"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    studyZ = new wxMyTextCtrl(panelStudy, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-25,h2), 0);
    x2=x2+w2+9;
    studyStaticText4 = new wxStaticText(panelStudy, wxID_ANY, _("棱镜常数(mm)"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    studyPrc = new wxMyTextCtrl(panelStudy, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-25,h2), 0);

    x2=14;
    y2=y2+h2+gh2+11;
    h2=h1-y2-15;
    w2=w1-28-83;
    panelStuyFig = new wxPanel(panelStudy, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStuyFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x2=x2+w2+18;
    w2=65;
    studyButton = new wxPanel(panelStudy, wxID_ANY, wxPoint(x2,y1+gh2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    studyButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w-150;
    h1=h-57;
    panelBasket = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBasket->SetBackgroundColour(wxColor(239,239,239));
    x2=14;
    y2=9;
    w2=w1-28-75;
    h2=h1-y1-15;
    panelBasketList = new wxPanel(panelBasket, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBasketList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    baskList = new wxListView(panelBasketList, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    x2=x2+w2+10;
    w2=65;
    panelBaskListButton = new wxPanel(panelBasket, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBaskListButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelBaskListButton->Show(false);

    x1=0;
    y1=11;
    w1=w-150;
    h1=h-57;
    panelStationList = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStationList->SetBackgroundColour(wxColor(239,239,239));
    x2=14;
    y2=9;
    w2=w1-28;
    h2=h1-9-15;
    panelStationListTitle = new wxPanel(panelStationList, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStationListTitle->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    stnList = new wxListView(panelStationListTitle, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    x2=x2+w2+10;
    w2=65;
    //panelStationListButton = new wxPanel(panelStationList, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //panelStationListButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w-150;
    h1=h-57;
    panelCheck = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelCheck->SetBackgroundColour(wxColor(239,239,239));
    x2=14;
    y2=9;
    w2=w1-x2*2-75;
    h2=h1-y2-15;
    checkText = new wxPanel(panelCheck, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    checkText->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x2+w2+10;
    w2=65;
    checkButton = new wxPanel(panelCheck, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    checkButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelCheck->Show(false);
    panelBasketMeas->Show(false);
    panelStudy->Show(false);
    panelBasket->Show(false);
    panelStationList->Show(false);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelNavi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintButton,0,this);
    panelButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionButton,0,this);
    panelButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveButton,0,this);
    panelButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickButton,0,this);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintBackground,0,this);
	panelNavi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintNavi,0,this);

    stationButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintStationButton,0,this);
    stationButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionStationButton,0,this);
    stationButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveStationButton,0,this);
    stationButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickStationButton,0,this);

    selectStation->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintSelectStation,0,this);
    selectStation->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionSelectStation,0,this);
    selectStation->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveSelectStation,0,this);
    selectStation->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickSelectStation,0,this);

    selectBack->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintSelectBack,0,this);
    selectBack->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionSelectBack,0,this);
    selectBack->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveSelectBack,0,this);
    selectBack->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickSelectBack,0,this);

    panelStationFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintStationFig,0,this);

    panelMeasFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintMeasFig,0,this);

    panelStuyFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintStudyFig,0,this);
    studyButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintStudyButton,0,this);
    studyButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionStudyButton,0,this);
    studyButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveStudyButton,0,this);
    studyButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickStudyButton,0,this);

    panelBasketButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintBasketMeas,0,this);
    panelBasketButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionBasketMeas,0,this);
    panelBasketButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveBasketMeas,0,this);
    panelBasketButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickBasketMeas,0,this);

    panelBasketList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintBasketList,0,this);

    panelBaskListButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintBaskListButton,0,this);
    panelBaskListButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionBaskListButton,0,this);
    panelBaskListButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveBaskListButton,0,this);
    panelBaskListButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickBaskListButton,0,this);

    panelStationListTitle->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintStationGrid,0,this);

    //panelStationListButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintStationListButton,0,this);
    //panelStationListButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionStationListButton,0,this);
    //panelStationListButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveStationListButton,0,this);
    //panelStationListButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickStationListButton,0,this);

    stnList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&MySetupDlg::OnListStationActivated,0,this);

    checkButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintCheckButton,0,this);
    checkButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionCheckButton,0,this);
    checkButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveCheckButton,0,this);
    checkButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickCheckButton,0,this);

    checkText->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintCheckText,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickBottom,0,this);

    baskList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&MySetupDlg::OnBasketSelect,0,this);
    baskList->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&MySetupDlg::OnBasketDeselected,0,this);
    baskList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&MySetupDlg::OnBasketActivated,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    page=0;
    motion=ID_STN_NONE;
    iok=0;
    int i=0;
    stnLabel[i++]=_("设站定向");
    //stnLabel[i++]=_("姿态复核");
    stnLabel[i++]=_("换站测量");
    stnLabel[i++]=_("学习测量");
    stnLabel[i++]=_("吊篮列表");
    stnLabel[i++]=_("设站记录");

    baskList->InsertColumn(i++,_("点名"),wxLIST_FORMAT_CENTRE,55);
    baskList->InsertColumn(i++,_("X"),wxLIST_FORMAT_CENTRE,90);
    baskList->InsertColumn(i++,_("Y"),wxLIST_FORMAT_CENTRE,90);
    baskList->InsertColumn(i++,_("Z"),wxLIST_FORMAT_CENTRE,80);
    baskList->InsertColumn(i++,_("T"),wxLIST_FORMAT_CENTRE,115);
    baskList->InsertColumn(i++,_("测站/后视"),wxLIST_FORMAT_CENTRE,65);

	i=0;
	stnList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,65);
    stnList->InsertColumn(i++,_("测站"),wxLIST_FORMAT_CENTRE,75);
    stnList->InsertColumn(i++,_("后视"),wxLIST_FORMAT_CENTRE,75);
    stnList->InsertColumn(i++,_("平距差"),wxLIST_FORMAT_CENTRE,95);
    stnList->InsertColumn(i++,_("高程"),wxLIST_FORMAT_CENTRE,95);
    stnList->InsertColumn(i++,_("T"),wxLIST_FORMAT_CENTRE,145);
    //mtg->m1.t3=0;
    wxString empstr;
    ///设站定向数据

    //istn=mtg->istn;
    memset(&istn,0,sizeof(MTG_STATION));
    istn.id=mtg->istn.id;
    strcpy(istn.stat,mtg->istn.stat);
    strcpy(istn.back,mtg->istn.back);
    istn.statx=mtg->istn.statx;
    istn.staty=mtg->istn.staty;
    istn.statz=mtg->istn.statz;
    istn.stath=mtg->istn.stath;
    istn.backx=mtg->istn.backx;
    istn.backy=mtg->istn.backy;
    istn.backz=mtg->istn.backz;
    istn.backh=mtg->istn.backh;
    istn.backx1=mtg->istn.backx1;
    istn.backy1=mtg->istn.backy1;
    istn.backz1=mtg->istn.backz1;
    istn.t=mtg->istn.t;
    istn.headh[0]=mtg->istn.headh[0];
    istn.headh[1]=mtg->istn.headh[1];
    istn.tailh[0]=mtg->istn.tailh[0];
    istn.tailh[1]=mtg->istn.tailh[1];
    istn.headv[0]=mtg->istn.headv[0];
    istn.headv[1]=mtg->istn.headv[1];
    istn.tailv[0]=mtg->istn.tailv[0];
    istn.tailv[1]=mtg->istn.tailv[1];
    istn.azi[0]=mtg->istn.azi[0];
    istn.azi[1]=mtg->istn.azi[1];
    istn.pitch[0]=mtg->istn.pitch[0];
    istn.pitch[1]=mtg->istn.pitch[1];
    istn.roll[0]=mtg->istn.roll[0];
    istn.roll[1]=mtg->istn.roll[1];
    //istn.anglediff=mtg->istn.anglediff;

    s2d=0.0;
    b2d=0.0;
    if(istn.t>0)
    {
        road_xy2l(&mtg->r,istn.statx,istn.staty,0,0,0,0,&s2d);
        road_xy2l(&mtg->r,istn.backx,istn.backy,0,0,0,0,&b2d);
        s2d=s2d*mtg->prj.a2z;
        b2d=b2d*mtg->prj.a2z;
    }
    mBask.t=0;

    measName->SetValue(empstr);
    measTurns->SetValue(_("3"));
    measHeight->SetValue(_("0.2400"));

    nres=0;
    nres=mtg_query_station(mtg,&sres);

    studyX->SetValue(wxString::Format(_("%.4f"),mtg->m1.prism[0]));
    studyY->SetValue(wxString::Format(_("%.4f"),mtg->m1.prism[1]));
    studyZ->SetValue(wxString::Format(_("%.4f"),mtg->m1.prism[2]));
    studyPrc->SetValue(wxString::Format(_("-16.9")));

    t1=0;
    t2=1000;
    mBask.t=0;
    istudy=0;
    ///过程记录
    UpdateStation();
    UpdateBaskList();
    UpdateStationList();
    Connect(wxEVT_TIMER,(wxObjectEventFunction)&MySetupDlg::OnTimer);
    stnTimer.SetOwner(this);
    stnTimer.Start(10,false);
}

MySetupDlg::~MySetupDlg()
{
    stnTimer.Stop();
}

void MySetupDlg::OnPaintButton(wxPaintEvent& event)
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
        int btns=ID_STN_STATION_LIST-ID_STN_SET_STATION+1;
        int btn_h=36.0*sy;
        for(int i=0;i<btns-1;i++)
        {
            y=11+i*btn_h;
            x=1;
            x2=w-1;
            stnButton[ID_STN_SET_STATION+i].x=x;
            stnButton[ID_STN_SET_STATION+i].y=y;
            stnButton[ID_STN_SET_STATION+i].width=w-2;
            stnButton[ID_STN_SET_STATION+i].height=btn_h;

            if(motion==ID_STN_SET_STATION+i)
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
                memDC.DrawLabel(_("◆ ")+stnLabel[i],wxRect(10,y-btn_h+2,w-20,btn_h-1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(_("◇ ")+stnLabel[i],wxRect(10,y-btn_h+2,w-20,btn_h-1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            //memDC.DrawLabel(btn_label[i],wxRect(x+w/10,y-btn_height+2,w*9/10,btn_height-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnMotionButton(wxMouseEvent& event)
{
    int x,y;
    int w,h;
    x=event.GetX();
    y=event.GetY();
    panelButton->GetClientSize(&w,&h);
    int btns=ID_STN_STATION_LIST-ID_STN_SET_STATION+1;
    for(int i=0;i<btns;i++)
    {
        if(x>stnButton[ID_STN_SET_STATION+i].x && x<stnButton[ID_STN_SET_STATION+i].x+stnButton[ID_STN_SET_STATION+i].width)
        {
            if(y>stnButton[ID_STN_SET_STATION+i].y && y<stnButton[ID_STN_SET_STATION+i].y+stnButton[ID_STN_SET_STATION+i].height)
            {
                motion=ID_STN_SET_STATION+i;
                break;
            }
            else if(i==btns-1)
            {
                motion=ID_STN_NONE;
                break;
            }
            else
            {
                continue;
            }
        }
        else
        {
            motion=ID_STN_NONE;
        }
    }
    //btn_left_down=-1;
    panelButton->Refresh();
}

void MySetupDlg::OnLeaveButton(wxMouseEvent& event)
{
    motion=ID_STN_NONE;
    panelButton->Refresh();
}

void MySetupDlg::OnClickButton(wxMouseEvent& event)
{
    int w,h;
    panelStation->GetClientSize(&w,&h);
    if(motion>=ID_STN_SET_STATION)
    {
        int ifun=motion-ID_STN_SET_STATION;
        page=ifun;
        switch(ifun)
        {
        case 0:
            panelStation->Show(true);
            panelCheck->Show(false);
            panelBasketMeas->Show(false);
            panelStudy->Show(false);
            panelBasket->Show(false);
            panelStationList->Show(false);
            break;
//        case 1:
//            panelStation->Show(false);
//            panelCheck->Show(true);
//            panelBasketMeas->Show(false);
//            panelStudy->Show(false);
//            panelBasket->Show(false);
//            panelStationList->Show(false);
//            break;
        case 1:
            panelStation->Show(false);
            panelCheck->Show(false);
            panelBasketMeas->Show(true);
            panelStudy->Show(false);
            panelBasket->Show(false);
            panelStationList->Show(false);
            break;
        case 2:
            panelStation->Show(false);
            panelCheck->Show(false);
            panelBasketMeas->Show(false);
            panelStudy->Show(true);
            panelBasket->Show(false);
            panelStationList->Show(false);
            break;
        case 3:
            panelStation->Show(false);
            panelCheck->Show(false);
            panelBasketMeas->Show(false);
            panelStudy->Show(false);
            panelBasket->Show(true);
            panelStationList->Show(false);
            break;
        case 4:
            panelStation->Show(false);
            panelCheck->Show(false);
            panelBasketMeas->Show(false);
            panelStudy->Show(false);
            panelBasket->Show(false);
            panelStationList->Show(true);
            UpdateStationList();
            break;
        default:
            break;
        }
        //FigRun(ifun);
    }
    panelButton->Refresh();
}

void MySetupDlg::OnBasketSelect(wxListEvent& event)
{
    panelBaskListButton->Refresh();
}

void MySetupDlg::OnBasketDeselected(wxListEvent& event)
{
    panelBaskListButton->Refresh();
}

void MySetupDlg::OnBasketActivated(wxListEvent& event)
{
    wxMouseEvent e;
    motion=ID_STN_BSK_EDI;
    OnClickBaskListButton(e);
}

void MySetupDlg::OnPaintSelectStation(wxPaintEvent& event)
{
    wxPaintDC dc(selectStation);
    int w,h;
    selectStation->GetClientSize(&w,&h);
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

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(motion==ID_STN_SEL_STATION)
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
        memDC.DrawRoundedRectangle(0,0,w,h,3);

        memDC.DrawLabel(_("<...>"),wxRect(0,0,w,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnMotionSelectStation(wxMouseEvent& event)
{
    motion=ID_STN_SEL_STATION;
    selectStation->Refresh();
}

void MySetupDlg::OnLeaveSelectStation(wxMouseEvent& event)
{
    motion=ID_STN_NONE;
    selectStation->Refresh();
}

void MySetupDlg::OnClickSelectStation(wxMouseEvent& event)
{
    BasketDlg dlg(this);
    dlg.basketList->DeleteAllItems();
    for(int i=0; i<mtg->nbsk; i++)
    {
        dlg.basketList->InsertItem(i,wxString(mtg->bask[i].name,wxConvUTF8));
        dlg.basketList->SetItem(i,1,wxString::Format(_("%.4f"),mtg->bask[i].x));
        dlg.basketList->SetItem(i,2,wxString::Format(_("%.4f"),mtg->bask[i].y));
        dlg.basketList->SetItem(i,3,wxString::Format(_("%.4f"),mtg->bask[i].z));
        dlg.basketList->SetItem(i,4,wxDateTime(mtg->bask[i].t).Format(_("%Y-%m-%d %H:%M")));
        if(i==istation)
        {
            dlg.basketList->SetItem(i,5,_("测站"));
        }
        else if(i==iback)
        {
            dlg.basketList->SetItem(i,5,_("后视"));
        }
    }
    dlg.Center();
    if(dlg.ShowModal()==wxID_OK)
    {
        int sel=dlg.basketList->GetFirstSelected();
        if(sel>=0 && sel<mtg->nbsk)
        {
            strcpy(istn.stat,mtg->bask[sel].name);
            istn.statx=mtg->bask[sel].x;
            istn.staty=mtg->bask[sel].y;
            istn.statz=mtg->bask[sel].z;
            UpdateStation();
            road_xy2l(&mtg->r,istn.statx,istn.staty,0,0,0,0,&s2d);
            s2d=s2d*mtg->prj.a2z;
            panelStationFig->Refresh();
        }
    }
    selectStation->Refresh();
}

void MySetupDlg::OnPaintSelectBack(wxPaintEvent& event)
{
    wxPaintDC dc(selectBack);
    int w,h;
    selectBack->GetClientSize(&w,&h);
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

        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRoundedRectangle(0,0,w,h,3);

        if(motion==ID_STN_SEL_BACK)
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
        memDC.DrawRoundedRectangle(0,0,w,h,3);

        memDC.DrawLabel(_("<...>"),wxRect(0,0,w,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnMotionSelectBack(wxMouseEvent& event)
{
    motion=ID_STN_SEL_BACK;
    selectBack->Refresh();
}

void MySetupDlg::OnLeaveSelectBack(wxMouseEvent& event)
{
    motion=ID_STN_NONE;
    selectBack->Refresh();
}

void MySetupDlg::OnClickSelectBack(wxMouseEvent& event)
{
    BasketDlg dlg(this);
    dlg.basketList->DeleteAllItems();
    for(int i=0; i<mtg->nbsk; i++)
    {
        dlg.basketList->InsertItem(i,wxString(mtg->bask[i].name,wxConvUTF8));
        dlg.basketList->SetItem(i,1,wxString::Format(_("%.4f"),mtg->bask[i].x));
        dlg.basketList->SetItem(i,2,wxString::Format(_("%.4f"),mtg->bask[i].y));
        dlg.basketList->SetItem(i,3,wxString::Format(_("%.4f"),mtg->bask[i].z));
        dlg.basketList->SetItem(i,4,wxDateTime(mtg->bask[i].t).Format(_("%Y-%m-%d %H:%M")));
        if(i==istation)
        {
            dlg.basketList->SetItem(i,5,_("测站"));
        }
        else if(i==iback)
        {
            dlg.basketList->SetItem(i,5,_("后视"));
        }
    }
    dlg.Center();
    if(dlg.ShowModal()==wxID_OK)
    {
        int sel=dlg.basketList->GetFirstSelected();
        if(sel>=0 && sel<mtg->nbsk)
        {
            strcpy(istn.back,mtg->bask[sel].name);
            istn.backx=mtg->bask[sel].x;
            istn.backy=mtg->bask[sel].y;
            istn.backz=mtg->bask[sel].z;
            UpdateStation();
            road_xy2l(&mtg->r,istn.backx,istn.backy,0,0,0,0,&b2d);
            b2d=b2d*mtg->prj.a2z;
            panelStationFig->Refresh();
        }
    }
    selectBack->Refresh();
}

void MySetupDlg::OnPaintStationButton(wxPaintEvent& event)
{
    wxPaintDC dc(stationButton);
    int w,h;
    stationButton->GetClientSize(&w,&h);
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
        int w1=w;
        int h1=25;

        stnButton[ID_STN_SET_MEAS].x=x1;
        stnButton[ID_STN_SET_MEAS].y=y1;
        stnButton[ID_STN_SET_MEAS].width=w1;
        stnButton[ID_STN_SET_MEAS].height=h1;

        if(motion==ID_STN_SET_MEAS)
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
        memDC.DrawLabel(_("测  量"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_SET].x=x1;
        stnButton[ID_STN_SET].y=y1;
        stnButton[ID_STN_SET].width=w1;
        stnButton[ID_STN_SET].height=h1;

        if(motion==ID_STN_SET)
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
        memDC.DrawLabel(_("设  置"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_SET_RESET].x=x1;
        stnButton[ID_STN_SET_RESET].y=y1;
        stnButton[ID_STN_SET_RESET].width=w1;
        stnButton[ID_STN_SET_RESET].height=h1;

        if(motion==ID_STN_SET_RESET)
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
        memDC.DrawLabel(_("复  位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_SET_TO_BACK].x=x1;
        stnButton[ID_STN_SET_TO_BACK].y=y1;
        stnButton[ID_STN_SET_TO_BACK].width=w1;
        stnButton[ID_STN_SET_TO_BACK].height=h1;

        if(motion==ID_STN_SET_TO_BACK)
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
        memDC.DrawLabel(_("至后视"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_SET_TO_TARGET].x=x1;
        stnButton[ID_STN_SET_TO_TARGET].y=y1;
        stnButton[ID_STN_SET_TO_TARGET].width=w1;
        stnButton[ID_STN_SET_TO_TARGET].height=h1;

        if(motion==ID_STN_SET_TO_TARGET)
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
        memDC.DrawLabel(_("至前视"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnMotionStationButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>stnButton[ID_STN_SET_MEAS].x && x<stnButton[ID_STN_SET_MEAS].x+stnButton[ID_STN_SET_MEAS].width)
    {
        if(y>stnButton[ID_STN_SET_MEAS].y && y<stnButton[ID_STN_SET_MEAS].y+stnButton[ID_STN_SET_MEAS].height)
        {
            motion=ID_STN_SET_MEAS;
        }
        else if(y>stnButton[ID_STN_SET].y && y<stnButton[ID_STN_SET].y+stnButton[ID_STN_SET].height)
        {
            motion=ID_STN_SET;
        }
        else if(y>stnButton[ID_STN_SET_RESET].y && y<stnButton[ID_STN_SET_RESET].y+stnButton[ID_STN_SET_RESET].height)
        {
            motion=ID_STN_SET_RESET;
        }
        else if(y>stnButton[ID_STN_SET_TO_BACK].y && y<stnButton[ID_STN_SET_TO_BACK].y+stnButton[ID_STN_SET_TO_BACK].height)
        {
            motion=ID_STN_SET_TO_BACK;
        }
        else if(y>stnButton[ID_STN_SET_TO_TARGET].y && y<stnButton[ID_STN_SET_TO_TARGET].y+stnButton[ID_STN_SET_TO_TARGET].height)
        {
            motion=ID_STN_SET_TO_TARGET;
        }
        else
        {
            motion=ID_STN_NONE;
        }
    }
    else
    {
        motion=ID_STN_NONE;
    }
    stationButton->Refresh();
}

void MySetupDlg::OnLeaveStationButton(wxMouseEvent& event)
{
    motion=ID_STN_NONE;
    stationButton->Refresh();
}

void MySetupDlg::OnClickStationButton(wxMouseEvent& event)
{
    if(mtg->tarset.stopped==1)
    {
        WriteMsg(_("角度异常，请立刻联系上海米度测量技术有限公司!"),1);
        return;//end add
    }
    if(motion==ID_STN_SET_MEAS)
    {
        if(mtg->thread)
        {
            if(mtg->ithread==MTG_THREAD_MEASUREBACK)
            {
                WriteMsg(_("正在测量中，请稍侯..."),1);
                return;
            }

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

            WriteMsg(_("系统忙，请稍侯..."),1);
            return;
        }

        if(mtg_measure_back(mtg))
        {
            WriteMsg(_("后视点测量失败！"),1);
        }
    }
    else if(motion==ID_STN_SET)
    {
        char msg[260];
        double h1,h2;
        wxString valstr;
        valstr=stationH->GetValue();
        if(valstr.IsEmpty())
        {
            h1=0.0;
            stationH->SetValue(_("0.0000"));
        }
        else if(!valstr.ToDouble(&h1))
        {
            WriteMsg(_("仪器高输入错误，请检查！"),1);
            stationH->SetFocus();
            //stationH->SetSelection(-1,-1);
            return;
        }
        valstr=backH->GetValue();
        if(valstr.IsEmpty())
        {
            h1=0.0;
            backH->SetValue(_("0.0000"));
        }
        else if(!valstr.ToDouble(&h1))
        {
            WriteMsg(_("棱镜高输入错误，请检查！"),1);
            backH->SetFocus();
            //backH->SetSelection(-1,-1);
            return;
        }

        if(mtg->thread)
        {
            if(mtg->ithread==MTG_THREAD_MEASUREBACK)
            {
                WriteMsg(_("正在测量中，请稍侯..."),1);
                return;
            }

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

            WriteMsg(_("系统忙，请稍侯..."),1);
            return;
        }

        mtg->istn=istn;
        if(mtg_setup(mtg))
        {
            WriteMsg(_("设站失败！"),1);
        }
    }
    else if(motion==ID_STN_SET_TO_BACK)
    {
        if(mtg->thread)
        {
            if(mtg->ithread==MTG_THREAD_MEASUREBACK)
            {
                WriteMsg(_("正在测量中，请稍侯..."),1);
                return;
            }

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

            WriteMsg(_("系统忙，请稍侯..."),1);
            return;
        }

        if(mtg_position_back(mtg))
        {
            WriteMsg(_("转向后视点失败！"),1);
        }
    }
    else if(motion==ID_STN_SET_TO_TARGET)
    {
        if(mtg->thread)
        {
            if(mtg->ithread==MTG_THREAD_MEASUREBACK)
            {
                WriteMsg(_("正在测量中，请稍侯..."),1);
                return;
            }

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

            WriteMsg(_("系统忙，请稍侯..."),1);
            return;
        }

        if(mtg_position_prism(mtg,mtg->m1.prism))
        {
            WriteMsg(_("转向激光靶失败！"),1);
        }
    }
    else if(motion==ID_STN_SET_RESET)
    {
        if(mtg_resetup(mtg))
       {
           WriteMsg(_("复位失败！"),1);
       }
    }
}

void MySetupDlg::OnPaintStationFig(wxPaintEvent& event)
{
    wxPaintDC dc(panelStationFig);
    int w,h;
    panelStationFig->GetClientSize(&w,&h);
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
        if(istn.t>0)
        {
            memDC.DrawLabel(wxDateTime(istn.t).Format(_("%Y-%m-%d %H:%M:%S"))+_(" 设置"),wxRect(15,0,w,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        memDC.SetTextForeground(icolor[0]);


        double statx,staty,statz,stath;
        double backx,backy,backz,backh;
        double backx1,backy1,backz1;

        statx=istn.statx;
        staty=istn.staty;
        statz=istn.statz;
        stath=istn.stath;

        backx=istn.backx;
        backy=istn.backy;
        backz=istn.backz;
        backh=istn.backh;

        backx1=istn.backx1;
        backy1=istn.backy1;
        backz1=istn.backz1;

        int x1,y1,w1,h1;

        double dx=backx-statx;
        double dy=backy-staty;
        double dz1=backz+backh-statz-stath;
        double hs1=sqrt(dx*dx+dy*dy);
        double hs2=backz1*cos(PI/2-backy1);
        double dz2=backz1*sin(PI/2-backy1);
        double hi=atan2(dy,dx);
        if(hi<0.0) hi+=2.0*PI;
        hi=hi*180/PI;

        double mi,sec;
        mi=hi-(int)hi;
        mi=mi*60;
        sec=mi-(int)mi;
        sec=sec*60;
        x1=15;
        y1=34;
        w1=(w-x1*2)/3;
        h1=25;
        wxString istr;
        istr = _("理论方位");
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1/2-20;
        istr = wxString::Format(_("%d°"),(int)hi)+wxString::Format(_("%d′"),(int)mi)+wxString::Format(_("%.1f″"),sec);
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1+=h1;
        x1=15;
        istr = _("理论平距");
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/2-20;
        istr =wxString::Format(_("%.4f"),hs1)+_(" m");
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/2+20;
        istr = _("实测平距");
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/2-20;
        istr =wxString::Format(_("%.4f"),hs2)+_(" m");
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/2+20;
        istr = _("平距差");
        memDC.DrawLabel(istr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1/2-20;
        istr =wxString::Format(_("%.4f"),hs2-hs1)+_(" m");
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=15;
        y1+=h1;
        istr = _("理论高差 ");
        memDC.DrawLabel(istr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/2-20;
        istr =wxString::Format(_("%.4f"),dz1)+_(" m");
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/2+20;
        istr = _("实测高差");
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/2-20;
        istr =wxString::Format(_("%.4f"),dz2)+_(" m");
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/2+20;
        istr = _("高差差");
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1/2-20;
        if(istn.t>0) istr = wxString::Format(_("%.4f"),dz2-dz1)+_(" m");
        else istr=wxEmptyString;
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=15;
        y1=y1+h1+7;
        w1=w-x1*2;
        memDC.SetPen(wxPen(wxColor(189,189,189)));
        memDC.DrawLine(x1,y1,x1+w1,y1);

        int r2=90;
        double sx,sy,bx,by;

        x1=15;
        y1=y1/2+h/2;
        h1=h*1/4;
        memDC.SetPen(wxPen(wxColor(189,189,189),1,wxDOT));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);

        double vs=fabs(s2d/b2d);
        if(vs>1.0)
        {
            vs=1.0/vs;
            sx=w*3/4;
            sy=y1+fabs(s2d)/s2d*h1;
            bx=w/4;
            by=y1+fabs(b2d)/b2d*h1*vs;
        }
        else
        {
            sx=w*3/4;
            sy=y1+fabs(s2d)/s2d*h1*vs;
            bx=w/4;
            by=y1+fabs(b2d)/b2d*h1;
        }

        if(s2d==0.0) sy=y1;
        if(b2d==0.0) by=y1;

        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.DrawLine(sx,sy,bx,by);

        if(fabs(b2d)>0.01)
        {
            memDC.DrawLine(bx-10,y1,bx-13,y1+fabs(b2d)/b2d*3);
            memDC.DrawLine(bx-13,y1+fabs(b2d)/b2d*3,bx-13,(y1+by)/2-fabs(b2d)/b2d*3);
            memDC.DrawLine(bx-13,(y1+by)/2-fabs(b2d)/b2d*3,bx-16,(y1+by)/2);
            istr=wxString::Format(_("%.3f m"),b2d);
            memDC.DrawLabel(istr,wxRect(bx-16,(y1+by)/2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLine(bx-16,(y1+by)/2,bx-13,(y1+by)/2+fabs(b2d)/b2d*3);
            memDC.DrawLine(bx-13,(y1+by)/2+fabs(b2d)/b2d*3,bx-13,by-fabs(b2d)/b2d*3);
            memDC.DrawLine(bx-13,by-fabs(b2d)/b2d*3,bx-10,by);
        }

        if(fabs(s2d)>0.001)
        {
            memDC.DrawLine(sx+10,y1,sx+13,y1+fabs(s2d)/s2d*3.0);
            memDC.DrawLine(sx+13,y1+fabs(s2d)/s2d*3.0,sx+13,(y1+sy)/2-fabs(s2d)/s2d*3.0);
            memDC.DrawLine(sx+13,(y1+sy)/2-fabs(s2d)/s2d*3.0,sx+16,(y1+sy)/2);
            istr=wxString::Format(_("%.3f m"),s2d);
            memDC.DrawLabel(istr,wxRect(sx+21,(y1+sy)/2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLine(sx+16,(y1+sy)/2,sx+13,(y1+sy)/2+fabs(s2d)/s2d*3.0);
            memDC.DrawLine(sx+13,(y1+sy)/2+fabs(s2d)/s2d*3.0,sx+13,sy-fabs(s2d)/s2d*3.0);
            memDC.DrawLine(sx+13,sy-fabs(s2d)/s2d*3.0,sx+10,sy);
        }
        //trace(0,"sx=%.4f,sx=%.4f,sx=%.4f,sx=%.4f\n",sx,sy,bx,by);
        memDC.SetPen(*wxMEDIUM_GREY_PEN);
        memDC.DrawCircle(bx,by,7);
        memDC.DrawRectangle(sx-7,sy-7,14,14);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnPaintMeasFig(wxPaintEvent& event)
{
    wxPaintDC dc(panelMeasFig);
    int w,h;
    panelMeasFig->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,225)));
        memDC.DrawRectangle(1,1,w-2,25);
        memDC.SetPen(wxPen(wxColor(179,179,179)));
        memDC.DrawLine(1,25,w-1,25);
        int x1,y1,w1,h1;
        x1=15;
        y1=34;
        w1=(w-x1*2-90)/3;
        h1=25;

        if(mBask.t>0)
        {
            memDC.SetTextForeground(wxColor(0,0,255));
            memDC.DrawLabel(wxDateTime(mBask.t).Format(_("%Y-%m-%d %H:%M:%S"))+_(" 测定"),wxRect(x1,0,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetTextForeground(icolor[0]);
            w1=80;
            memDC.DrawLabel(_("实测坐标"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            w1=140;
            memDC.DrawLabel(_("x"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%.4f"),mBask.x),wxRect(x1+10,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            memDC.DrawLabel(_("y"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%.4f"),mBask.y),wxRect(x1+10,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            memDC.DrawLabel(_("z"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%.4f"),mBask.z),wxRect(x1+10,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            y1+=25;
            x1=15;
            w1=80;
            memDC.DrawLabel(_("测量质量"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            w1=140;
            memDC.DrawLabel(_("2C"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),(int)(d2c*0000.0)),wxRect(x1+10,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            memDC.DrawLabel(_("△α"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),(int)(d2a*206265.0)),wxRect(x1+10,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            memDC.DrawLabel(_("△s"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),(int)(d2d*1000.0)),wxRect(x1+10,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            w1=120;
            memDC.DrawLabel(_("实测坐标"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            w1=140;
            memDC.DrawLabel(_("x"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            memDC.DrawLabel(_("y"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            memDC.DrawLabel(_("z"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

            y1+=25;
            x1=15;
            w1=120;
            memDC.DrawLabel(_("测量质量"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            w1=140;
            memDC.DrawLabel(_("2C"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            memDC.DrawLabel(_("△α"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            memDC.DrawLabel(_("△s"),wxRect(x1,y1,0,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        x1=15;
        y1+=28;
        w1=w-2*x1;
        memDC.DrawLine(x1,y1,x1+w1,y1);

        double bx,by,bz;
        bx=mBask.x;
        by=mBask.y;
        bz=mBask.z;

        if(mBask.t>0)
        {
            x1=w/2;
            y1=y1+(h-y1)/2;
            int R2=120;

            memDC.SetPen(wxPen(wxColor(117,117,117),1,wxLONG_DASH));
            memDC.DrawCircle(x1,y1,R2);
            memDC.SetPen(wxPen(wxColor(117,117,117),1,wxDOT_DASH));
            memDC.DrawLine(x1-R2-20,y1,x1+R2+20,y1);
            memDC.DrawLine(x1,y1-R2-20,x1,y1+R2+20);

            double L1,L2,H1,H2;
            double R1,Mile;

            road_xy2l(&mtg->r,bx,by,&Mile,0,0,0,&L1);
            road_l2h(&mtg->r,Mile,&H1,0);
            H1=bz-H1;
            R1=L1*L1+H1*H1;
            R1=sqrt(R1);
            if(mtg->prj.a2z==-1)
            {
                L1=-L1;
            }

            L2=R2*L1/R1;
            H2=R2*H1/R1;
            memDC.SetPen(wxPen(wxColor(255,20,20)));
            memDC.DrawLine(x1,y1,x1+L2,y1);

            memDC.DrawLine(x1+L2,y1,x1+L2,y1-H2);
            memDC.DrawLine(x1,y1,x1+L2,y1-H2);

            if(L1>0.0)
            {
                if(H1>0.0)
                {
                    memDC.DrawLabel(wxString::Format(_("%.4f"),L1),wxRect(x1,y1+10,L2,y1+10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
                    memDC.DrawLabel(wxString::Format(_("%.4f"),H1),wxRect(x1+L2+10,y1-H2,0,H2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(wxString::Format(_("%.4f"),L1),wxRect(x1,y1-10,L2,y1-10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
                    memDC.DrawLabel(wxString::Format(_("%.4f"),-H1),wxRect(x1+L2+10,y1-H2,0,H2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }
            }
            else
            {
                if(H1>0.0)
                {
                    memDC.DrawLabel(wxString::Format(_("%.4f"),-L1),wxRect(x1,y1+10,L2,y1+10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
                    memDC.DrawLabel(wxString::Format(_("%.4f"),H1),wxRect(x1+L2-10,y1-H2,0,H2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(wxString::Format(_("%.4f"),-L1),wxRect(x1,y1-10,L2,y1-10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
                    memDC.DrawLabel(wxString::Format(_("%.4f"),-H1),wxRect(x1+L2-10,y1-H2,0,H2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                }
            }

            memDC.DrawLabel(_("里程 ")+wxString::Format(_("%.4f"),Mile),wxRect(x1,y1+R2+20,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnPaintStudyFig(wxPaintEvent& event)
{
    wxPaintDC dc(panelStuyFig);
    int w,h;
    panelStuyFig->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,225)));
        memDC.DrawRectangle(1,1,w-2,25);
        memDC.SetPen(wxPen(wxColor(179,179,179)));
        memDC.DrawLine(1,25,w-1,25);

        wxString opstr;
        opstr=_("方式一 直接输入   方式二 输入切口里程计算   方式三 粗略瞄准目标测量");
        memDC.DrawLabel(opstr,wxRect(15,0,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        int x1,y1,w1,h1;
        x1=15;
        y1=25;
        w1=w-2*x1;

        double bx,by,bz;
        studyX->GetValue().ToDouble(&bx);
        studyY->GetValue().ToDouble(&by);
        studyZ->GetValue().ToDouble(&bz);
        //bx=0;
        //by=0;
        //bz=0;
        //bx=mtg->prismcoord[0];
        //by=mtg->prismcoord[1];
        //bz=mtg->prismcoord[2];
        //memDC.DrawLabel(_("系列")+wxString::Format(_("%d"),mtg->tps.kind),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLabel(_("型号")+wxString::Format(_("%d"),mtg->tps.type),wxRect(x1,y1+25,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLabel(_("型号")+wxString::Format(_("%d"),TPS_DEVICE_LPNT),wxRect(x1,y1+50,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=w/2;
        y1=y1/2+h/2;
        int R2=120;

        memDC.SetPen(wxPen(wxColor(117,117,117),1,wxLONG_DASH));
        memDC.DrawCircle(x1,y1,R2);
        memDC.SetPen(wxPen(wxColor(117,117,117),1,wxDOT_DASH));
        memDC.DrawLine(x1-R2-20,y1,x1+R2+20,y1);
        memDC.DrawLine(x1,y1-R2-20,x1,y1+R2+20);

        double L1,L2,H1,H2;
        double R1,Mile;

        if(road_xy2l(&mtg->r,bx,by,&Mile,0,0,0,&L1)==-1)
        {
            Mile=0;
            L1=0;
            H1=0;
        }
        else if(road_l2h(&mtg->r,Mile,&H1,0)==-1)
        {
            H1=0;
        }

        H1=bz-H1;
        R1=L1*L1+H1*H1;
        R1=sqrt(R1);
        if(mtg->prj.a2z==-1)
        {
            L1=-L1;
        }

        L2=R2*L1/R1;
        H2=R2*H1/R1;
        if(R1==0)
        {
            L2=0;
            H2=0;
        }
        memDC.SetPen(wxPen(wxColor(255,20,20)));
        memDC.DrawLine(x1,y1,x1+L2,y1);

        memDC.DrawLine(x1+L2,y1,x1+L2,y1-H2);
        memDC.DrawLine(x1,y1,x1+L2,y1-H2);

        if(L1>0.0)
        {
            if(H1>0.0)
            {
                memDC.DrawLabel(wxString::Format(_("%.4f"),L1),wxRect(x1,y1+10,L2,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
                memDC.DrawLabel(wxString::Format(_("%.4f"),H1),wxRect(x1+L2+10,y1-H2,0,H2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(wxString::Format(_("%.4f"),L1),wxRect(x1,y1-10,L2,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
                memDC.DrawLabel(wxString::Format(_("%.4f"),-H1),wxRect(x1+L2+10,y1-H2,0,H2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(H1>0.0)
            {
                memDC.DrawLabel(wxString::Format(_("%.4f"),-L1),wxRect(x1,y1+10,L2,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
                memDC.DrawLabel(wxString::Format(_("%.4f"),H1),wxRect(x1+L2-10,y1-H2,0,H2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(wxString::Format(_("%.4f"),-L1),wxRect(x1,y1-10,L2,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
                memDC.DrawLabel(wxString::Format(_("%.4f"),-H1),wxRect(x1+L2-10,y1-H2,0,H2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            }
        }

        memDC.DrawLabel(_("里程 ")+wxString::Format(_("%.4f"),Mile),wxRect(x1,y1+R2+20,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnPaintStudyButton(wxPaintEvent& event)
{
    wxPaintDC dc(studyButton);
    int w,h;
    studyButton->GetClientSize(&w,&h);
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
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=25;
        stnButton[ID_STN_STUDY_MEAS].x=x1;
        stnButton[ID_STN_STUDY_MEAS].y=x1;
        stnButton[ID_STN_STUDY_MEAS].width=w1;
        stnButton[ID_STN_STUDY_MEAS].height=h1;
        if(motion==ID_STN_STUDY_MEAS)
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
        memDC.DrawLabel(_("测量"),wxRect(x1,y1,w1,h1), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_STUDY_CAL].x=x1;
        stnButton[ID_STN_STUDY_CAL].y=y1;
        stnButton[ID_STN_STUDY_CAL].width=w1;
        stnButton[ID_STN_STUDY_CAL].height=h1;
        if(motion==ID_STN_STUDY_CAL)
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
        memDC.DrawLabel(_("计算"),wxRect(x1,y1,w1,h1), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_STUDY_CHECK].x=x1;
        stnButton[ID_STN_STUDY_CHECK].y=y1;
        stnButton[ID_STN_STUDY_CHECK].width=w1;
        stnButton[ID_STN_STUDY_CHECK].height=h1;
        if(motion==ID_STN_STUDY_CHECK)
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
        memDC.DrawLabel(_("检查"),wxRect(x1,y1,w1,h1), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_STUDY_SET].x=x1;
        stnButton[ID_STN_STUDY_SET].y=y1;
        stnButton[ID_STN_STUDY_SET].width=w1;
        stnButton[ID_STN_STUDY_SET].height=h1;
        if(motion==ID_STN_STUDY_SET)
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
        memDC.DrawLabel(_("设置"),wxRect(x1,y1,w1,h1), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnMotionStudyButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>stnButton[ID_STN_STUDY_MEAS].x && x<stnButton[ID_STN_STUDY_MEAS].x+stnButton[ID_STN_STUDY_MEAS].width)
    {
        if(y>stnButton[ID_STN_STUDY_MEAS].y && y<stnButton[ID_STN_STUDY_MEAS].y+stnButton[ID_STN_STUDY_MEAS].height)
        {
            motion=ID_STN_STUDY_MEAS;
        }
        else if(y>stnButton[ID_STN_STUDY_CAL].y && y<stnButton[ID_STN_STUDY_CAL].y+stnButton[ID_STN_STUDY_CAL].height)
        {
            motion=ID_STN_STUDY_CAL;
        }
        else if(y>stnButton[ID_STN_STUDY_CHECK].y && y<stnButton[ID_STN_STUDY_CHECK].y+stnButton[ID_STN_STUDY_CHECK].height)
        {
            motion=ID_STN_STUDY_CHECK;
        }
        else if(y>stnButton[ID_STN_STUDY_SET].y && y<stnButton[ID_STN_STUDY_SET].y+stnButton[ID_STN_STUDY_SET].height)
        {
            motion=ID_STN_STUDY_SET;
        }
        else
        {
            motion=ID_STN_NONE;
        }
    }
    else
    {
        motion=ID_STN_NONE;
    }

    studyButton->Refresh();
}

void MySetupDlg::OnLeaveStudyButton(wxMouseEvent& event)
{
    motion=ID_STN_NONE;
    studyButton->Refresh();
}

void MySetupDlg::OnClickStudyButton(wxMouseEvent& event)
{
    if(motion==ID_STN_STUDY_MEAS)
    {
        if(mtg->thread)
        {
            if(mtg->ithread==MTG_THREAD_MEASUREBACK)
            {
                WriteMsg(_("正在测量中，请稍侯..."),1);
                return;
            }

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

            WriteMsg(_("系统忙，请稍侯..."),1);
            return;
        }
        double prc=0.0;
        wxString valstr;
        valstr=studyPrc->GetValue();
        if(valstr==wxEmptyString)
        {
            prc=0.0;
            studyPrc->SetValue(_("0.0"));
        }
        else if(valstr.ToDouble(&prc)==0)
        {
            WriteMsg(_("请正确设置棱镜常数"),1);
            studyPrc->SetFocus();
            studyPrc->SetSelection(-1,-1);
            return;
        }
        mtg->prc=prc;

        if(mtg_measure_prism(mtg))
        {
            WriteMsg(_("学习测量失败！"),1);
        }
    }
    else if(motion==ID_STN_STUDY_CAL)
    {
        double mile;
        HeadMileDlg dlg(this);
        dlg.Center();
        dlg.Mile->SetFocus();
        if(dlg.ShowModal()==wxID_OK)
        {
            double psm[3];
            dlg.Mile->GetValue().ToDouble(&mile);
            mtg_cal_prism(mtg,mile,psm);
            studyX->SetValue(wxString::Format(_("%.4f"),psm[0]));
            studyY->SetValue(wxString::Format(_("%.4f"),psm[1]));
            studyZ->SetValue(wxString::Format(_("%.4f"),psm[2]));
            panelStuyFig->Refresh();
            istudy=0;
        }

    }
    else if(motion==ID_STN_STUDY_CHECK)
    {
        if(mtg->thread)
        {
            if(mtg->ithread==MTG_THREAD_MEASUREBACK)
            {
                WriteMsg(_("正在测量中，请稍侯..."),1);
                return;
            }

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

            WriteMsg(_("系统忙，请稍侯..."),1);
            return;
        }

        studyX->GetValue().ToDouble(&mtg->prismcoord[0]);
        studyY->GetValue().ToDouble(&mtg->prismcoord[1]);
        studyZ->GetValue().ToDouble(&mtg->prismcoord[2]);
        if(mtg_check_prism(mtg))
        {
            WriteMsg(_("后视点测量失败！"),1);
        }
    }
    else if(motion==ID_STN_STUDY_SET)
    {
        if(mtg->thread)
        {
            if(mtg->ithread==MTG_THREAD_MEASUREBACK)
            {
                WriteMsg(_("正在测量中，请稍侯..."),1);
                return;
            }
        }
        else
        {
            if(istudy==1)
            {
                studyX->GetValue().ToDouble(&mtg->m1.prism[0]);
                studyY->GetValue().ToDouble(&mtg->m1.prism[1]);
                studyZ->GetValue().ToDouble(&mtg->m1.prism[2]);
                time(&mtg->m1.t3);
                WriteMsg(_("学习测量设置完成！"),0);
            }
            else
            {
                WriteMsg(_("请先检查目标位置，再设置！"),1);
            }
        }
    }
    studyButton->Refresh();
}

void MySetupDlg::OnPaintBasketMeas(wxPaintEvent& event)
{
    wxPaintDC dc(panelBasketButton);
    int w,h;
    panelBasketButton->GetClientSize(&w,&h);
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
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=25;
        stnButton[ID_STN_MEAS_MEAS].x=x1;
        stnButton[ID_STN_MEAS_MEAS].y=x1;
        stnButton[ID_STN_MEAS_MEAS].width=w1;
        stnButton[ID_STN_MEAS_MEAS].height=h1;
        if(motion==ID_STN_MEAS_MEAS)
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
        memDC.DrawLabel(_("测量"),wxRect(x1,y1,w1,h1), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_MEAS_SAVE].x=x1;
        stnButton[ID_STN_MEAS_SAVE].y=y1;
        stnButton[ID_STN_MEAS_SAVE].width=w1;
        stnButton[ID_STN_MEAS_SAVE].height=h1;
        if(motion==ID_STN_MEAS_SAVE)
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
        memDC.DrawLabel(_("保存"),wxRect(x1,y1,w1,h1), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnMotionBasketMeas(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>stnButton[ID_STN_MEAS_MEAS].x && x<stnButton[ID_STN_MEAS_MEAS].x+stnButton[ID_STN_MEAS_MEAS].width)
    {
        if(y>stnButton[ID_STN_MEAS_MEAS].y && y<stnButton[ID_STN_MEAS_MEAS].y+stnButton[ID_STN_MEAS_MEAS].height)
        {
            motion=ID_STN_MEAS_MEAS;
        }
        else if(y>stnButton[ID_STN_MEAS_SAVE].y && y<stnButton[ID_STN_MEAS_SAVE].y+stnButton[ID_STN_MEAS_SAVE].height)
        {
            motion=ID_STN_MEAS_SAVE;
        }
        else
        {
            motion=ID_STN_NONE;
        }
    }
    else
    {
        motion=ID_STN_NONE;
    }

    panelBasketButton->Refresh();
}

void MySetupDlg::OnLeaveBasketMeas(wxMouseEvent& event)
{
    motion=ID_STN_NONE;
    panelBasketButton->Refresh();
}

void MySetupDlg::OnClickBasketMeas(wxMouseEvent& event)
{
    if(motion==ID_STN_MEAS_MEAS)
    {
        double dist=0.0;
        long turns;
        double prismh;
        wxString valstr;
        valstr=measTurns->GetValue();
        if(valstr.ToLong(&turns)==0)
        {
            WriteMsg(_("请正确设置测回数"),1);
            measTurns->SetFocus();
            measTurns->SetSelection(-1,-1);
            return;
        }

        if(turns<=0)
        {
            WriteMsg(_("请正确设置测回数"),1);
            measTurns->SetFocus();
            measTurns->SetSelection(-1,-1);
            return;
        }
        valstr=measHeight->GetValue();
        if(valstr==wxEmptyString)
        {
            prismh=0.0;
            measHeight->SetValue(_("0.0000"));
        }
        else if(valstr.ToDouble(&prismh)==0)
        {
            WriteMsg(_("请正确设置棱镜高"),1);
            measHeight->SetFocus();
            measHeight->SetSelection(-1,-1);
            return;
        }

        if(mtg_measure_basket(mtg,0,prismh,turns))
        {
            WriteMsg(_("吊篮测量失败！"),1);
            return;
        }
    }
    else if(motion==ID_STN_MEAS_SAVE)
    {
        if(mBask.t<=0)
        {
            WriteMsg(_("吊篮未测量！"),1);
            return;
        }

        wxString str=measName->GetValue();
        if(str==wxEmptyString)
        {
            WriteMsg(_("请正确设置吊篮名称"),1);
            measName->SetFocus();
            measName->SetSelection(-1,-1);
            return;
        }

        strncpy(mBask.name,str.mb_str(wxConvUTF8),64);
        if(mtg_add_basket(mtg,&mBask))
        {
            WriteMsg(_("新吊篮保存成功！"),0);
            UpdateBaskList();
        }
        else
        {
            WriteMsg(_("新吊篮保存失败！"),1);
        }

    }

    panelBasketButton->Refresh();
}

void MySetupDlg::OnPaintBasketList(wxPaintEvent& event)
{
    wxPaintDC dc(panelBasketList);
    int w,h;
    panelBasketList->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(130,135,145)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;

        int i=0;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("点名"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("X"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("Y"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("Z"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("测站/后视"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        i=0;
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        x1=1;
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=baskList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,w-1,y1+1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnPaintBaskListButton(wxPaintEvent& event)
{
    wxPaintDC dc(panelBaskListButton);
    int w,h;
    panelBaskListButton->GetClientSize(&w,&h);
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
        memDC.SetPen(wxPen(wxColor(158,158,158)));

        int x1=0;
        int y1=0;
        int w1=w;
        int h1=25;

        stnButton[ID_STN_BSK_ADD].x=x1;
        stnButton[ID_STN_BSK_ADD].y=y1;
        stnButton[ID_STN_BSK_ADD].width=w1;
        stnButton[ID_STN_BSK_ADD].height=h1;

        if(motion==ID_STN_BSK_ADD)
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
        memDC.DrawLabel(_("添加"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        y1+=32;
        stnButton[ID_STN_BSK_EDI].x=x1;
        stnButton[ID_STN_BSK_EDI].y=y1;
        stnButton[ID_STN_BSK_EDI].width=w1;
        stnButton[ID_STN_BSK_EDI].height=h1;
        int sel = baskList->GetFirstSelected();

        if(sel>=0)
        {
            if(motion==ID_STN_BSK_EDI)
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
        memDC.DrawLabel(_("编辑"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_BSK_DEL].x=x1;
        stnButton[ID_STN_BSK_DEL].y=y1;
        stnButton[ID_STN_BSK_DEL].width=w1;
        stnButton[ID_STN_BSK_DEL].height=h1;
        //int sel = baskList->GetFirstSelected();
        if(sel==-1)
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        else
        {
            if(motion==ID_STN_BSK_DEL)
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
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("删除"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnMotionBaskListButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>stnButton[ID_STN_BSK_ADD].y && y<stnButton[ID_STN_BSK_ADD].y+stnButton[ID_STN_BSK_ADD].height)
    {
        if(x>stnButton[ID_STN_BSK_ADD].x && x<stnButton[ID_STN_BSK_ADD].x+stnButton[ID_STN_BSK_ADD].width)
        {
            motion=ID_STN_BSK_ADD;
        }
        else
        {
            motion=ID_STN_NONE;
        }
    }
    else if(y>stnButton[ID_STN_BSK_EDI].y && y<stnButton[ID_STN_BSK_EDI].y+stnButton[ID_STN_BSK_EDI].height)
    {
        if(x>stnButton[ID_STN_BSK_EDI].x && x<stnButton[ID_STN_BSK_EDI].x+stnButton[ID_STN_BSK_EDI].width)
        {
            motion=ID_STN_BSK_EDI;
        }
        else
        {
            motion=ID_STN_NONE;
        }
    }
    else if(y>stnButton[ID_STN_BSK_DEL].y && y<stnButton[ID_STN_BSK_DEL].y+stnButton[ID_STN_BSK_DEL].height)
    {
        if(x>stnButton[ID_STN_BSK_DEL].x && x<stnButton[ID_STN_BSK_DEL].x+stnButton[ID_STN_BSK_DEL].width)
        {
            motion=ID_STN_BSK_DEL;
        }
        else
        {
            motion=ID_STN_NONE;
        }
    }
    else
    {
        motion=ID_STN_NONE;
    }

    panelBaskListButton->Refresh();
}

void MySetupDlg::OnLeaveBaskListButton(wxMouseEvent& event)
{
    motion=ID_STN_NONE;
    panelBaskListButton->Refresh();
}

void MySetupDlg::OnClickBaskListButton(wxMouseEvent& event)
{
    if(mtg->tarset.stopped==1)
    {
        WriteMsg(_("角度异常，请立刻联系上海米度测量技术有限公司!"),1);
        return;//end add
    }
    if(motion==ID_STN_BSK_ADD)
    {
        MypointDlg dlg(this);
        dlg.Center();
        dlg.ptName->SetFocus();
        if(dlg.ShowModal()==wxID_OK)
        {
            MTG_BASKET b;
            wxString str;
            str=dlg.ptName->GetValue();
            strncpy(b.name,str.mb_str(wxConvUTF8),64);
            dlg.ptx->GetValue().ToDouble(&b.x);
            dlg.pty->GetValue().ToDouble(&b.y);
            dlg.ptz->GetValue().ToDouble(&b.z);
            time(&b.t);
            if(mtg_add_basket(mtg,&b))
            {
                WriteMsg(_("增加吊篮成功！"),0);
                UpdateBaskList();
            }
            else
            {
                WriteMsg(_("增加吊篮失败！"),1);
            }
        }
    }
    else if(motion==ID_STN_BSK_EDI)
    {
        int sel = baskList->GetFirstSelected();
        if(sel<0) return;
        MypointDlg dlg(this);
        dlg.Center();
        dlg.ptName->SetValue(wxString(mtg->bask[sel].name,wxConvUTF8));
        dlg.ptName->Enable(false);
        dlg.ptx->SetValue(wxString::Format(_("%.4f"),mtg->bask[sel].x));
        dlg.pty->SetValue(wxString::Format(_("%.4f"),mtg->bask[sel].y));
        dlg.ptz->SetValue(wxString::Format(_("%.4f"),mtg->bask[sel].z));

        if(dlg.ShowModal()==wxID_OK)
        {
            MTG_BASKET b;
            wxString str;
            str=dlg.ptName->GetValue();
            strncpy(b.name,str.mb_str(wxConvUTF8),64);
            dlg.ptx->GetValue().ToDouble(&b.x);
            dlg.pty->GetValue().ToDouble(&b.y);
            dlg.ptz->GetValue().ToDouble(&b.z);
            time(&b.t);
            if(mtg_modify_basket(mtg,sel,&b))
            {
                WriteMsg(_("编辑吊篮成功！"),0);
                UpdateBaskList();
            }
            else
            {
                WriteMsg(_("编辑吊篮失败！"),1);
            }
        }
        motion=ID_STN_NONE;
    }
    else if(motion==ID_STN_BSK_DEL)
    {
        int sel = baskList->GetFirstSelected();
        if(sel<0) return;
        ConfirmDlg dlg(this);
        dlg.confirmMsg=_("确定删除")+wxString(mtg->bask[sel].name,wxConvUTF8)+_("吊篮吗？");
        dlg.Center();
        if(dlg.ShowModal()==wxID_OK)
        {
            if(mtg_remove_basket(mtg,sel))
            {
                WriteMsg(_("删除吊篮成功！"),0);
                UpdateBaskList();
            }
            else
            {
                WriteMsg(_("删除吊篮失败！"),1);
            }
        }
    }

    panelBaskListButton->Refresh();
}

void MySetupDlg::OnPaintStationGrid(wxPaintEvent& event)
{
    wxPaintDC dc(panelStationListTitle);
    int w,h;
    panelStationListTitle->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(130,135,145)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;
        int i=0;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=stnList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=stnList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("测站"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=stnList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("后视"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=stnList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("平距差(毫米)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=stnList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("高差(毫米)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=stnList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnPaintCheckButton(wxPaintEvent& event)
{
    wxPaintDC dc(checkButton);
    int w,h;
    checkButton->GetClientSize(&w,&h);
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
        memDC.SetPen(wxPen(wxColor(158,158,158)));

        int x1=0;
        int y1=0;
        int w1=w;
        int h1=25;

        stnButton[ID_STN_CHECK_MEAS].x=x1;
        stnButton[ID_STN_CHECK_MEAS].y=y1;
        stnButton[ID_STN_CHECK_MEAS].width=w1;
        stnButton[ID_STN_CHECK_MEAS].height=h1;

        if(motion==ID_STN_CHECK_MEAS)
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
        memDC.DrawLabel(_("复核"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        /*stnButton[ID_STN_CHECK_EXPT].x=x1;
        stnButton[ID_STN_CHECK_EXPT].y=y1;
        stnButton[ID_STN_CHECK_EXPT].width=w1;
        stnButton[ID_STN_CHECK_EXPT].height=h1;

        if(motion==ID_STN_CHECK_EXPT)
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
        */
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnMotionCheckButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>stnButton[ID_STN_CHECK_MEAS].y && y<stnButton[ID_STN_CHECK_MEAS].y+stnButton[ID_STN_CHECK_MEAS].height)
    {
        if(x>stnButton[ID_STN_CHECK_MEAS].x && x<stnButton[ID_STN_CHECK_MEAS].x+stnButton[ID_STN_CHECK_MEAS].width)
        {
            motion=ID_STN_CHECK_MEAS;
        }
        else
        {
            motion=ID_STN_NONE;
        }
    }
    else if(y>stnButton[ID_STN_CHECK_EXPT].y && y<stnButton[ID_STN_CHECK_EXPT].y+stnButton[ID_STN_CHECK_EXPT].height)
    {
        if(x>stnButton[ID_STN_CHECK_EXPT].x && x<stnButton[ID_STN_CHECK_EXPT].x+stnButton[ID_STN_CHECK_EXPT].width)
        {
            motion=ID_STN_CHECK_EXPT;
        }
        else
        {
            motion=ID_STN_NONE;
        }
    }
    else
    {
        motion=ID_STN_NONE;
    }

    checkButton->Refresh();
}

void MySetupDlg::OnLeaveCheckButton(wxMouseEvent& event)
{
    motion=ID_STN_NONE;
    checkButton->Refresh();
}

void MySetupDlg::OnClickCheckButton(wxMouseEvent& event)
{
    if(motion==ID_STN_CHECK_MEAS)
    {
        //wxMessageBox(_("复核"));
        mtg_prism_check(mtg);
    }
    else if(motion==ID_STN_CHECK_EXPT)
    {

    }
    checkButton->Refresh();
    checkText->Refresh();
}

void MySetupDlg::OnPaintCheckText(wxPaintEvent& event)
{
    wxPaintDC dc(checkText);
    int w,h;
    checkText->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(130,135,145)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        int colx,coly;
        x1=0;
        y1=10;
        w1=w/5;
        h1=25;
        int i=1;
        memDC.DrawLabel(_("转动角"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(_("俯仰角"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(_("方位角"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(_("切口水平偏差"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(_("切口垂直偏差"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(_("盾尾水平偏差"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(_("盾尾垂直偏差"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        i+=2;
        memDC.DrawLabel(_("切口X"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(_("切口Y"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(_("切口Z"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i+=2;
        memDC.DrawLabel(_("盾尾X"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(_("盾尾Y"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(_("盾尾Z"),wxRect(x1,y1+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+20;
        colx=x1;
        coly=y1+h1;
        memDC.DrawLabel(_("激光"),wxRect(x1,y1,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        memDC.DrawLabel(_("棱镜"),wxRect(x1,y1,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        memDC.DrawLabel(_("较差"),wxRect(x1,y1,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        i=0;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.inc[3]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.inc[4]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.inc[5]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.headh1*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.headv1*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.tailh1*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.tailv1*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        i+=2;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.head[3]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.head[4]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.head[5]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i+=2;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.tail[3]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.tail[4]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.tail[5]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        colx=colx+w1;
        i=0;
        if(mtg->tarset.baseinc==1)
        {
            memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.inc[5]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            i++;
            memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.inc[6]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.inc[0]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            i++;
            memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.inc[1]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.inc[2]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.headh*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.headv*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.tailh*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.tailv*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        i+=2;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.head[0]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.head[1]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.head[2]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i+=2;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.tail[0]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.tail[1]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.tail[2]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        colx=colx+w1;
        i=0;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.inc[3]-mtg->mp.inc[0]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.inc[4]-mtg->mp.inc[1]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.inc[5]-mtg->mp.inc[2]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.headh1*1000.0-mtg->mp.headh*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.headv1*1000.0-mtg->mp.headv*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.tailh1*1000.0-mtg->mp.tailh*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.1f"),mtg->mp.tailv1*1000.0-mtg->mp.tailv*1000.0),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        i+=2;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.head[3]-mtg->mp.head[0]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.head[4]-mtg->mp.head[1]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.head[5]-mtg->mp.head[2]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i+=2;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.tail[3]-mtg->mp.tail[0]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.tail[4]-mtg->mp.tail[1]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        i++;
        memDC.DrawLabel(wxString::Format(_("%.3f"),mtg->mp.tail[5]-mtg->mp.tail[2]),wxRect(colx,coly+h1*i,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnPaintBottom(wxPaintEvent& event)
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
        h1=28;
        stnButton[ID_STN_BTN_QUIT].x=x1;
        stnButton[ID_STN_BTN_QUIT].y=y1;
        stnButton[ID_STN_BTN_QUIT].width=w1;
        stnButton[ID_STN_BTN_QUIT].height=h1;
        if(motion==ID_STN_BTN_QUIT)
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

        stnButton[ID_STN_PRT_SCN].x=x1;
        stnButton[ID_STN_PRT_SCN].y=y1;
        stnButton[ID_STN_PRT_SCN].width=w1;
        stnButton[ID_STN_PRT_SCN].height=h1;
        if(motion==ID_STN_PRT_SCN)
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

        panelButton->GetSize(&w1,0);
        x1=w1+14;
        w1=w-x1*2;
        //memDC.SetPen(ipen[0]);
        //memDC.SetBrush(wxBrush(wxColor(255,255,225)));
        //memDC.DrawRectangle(x1,y1,w1,h1);

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

void MySetupDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>stnButton[ID_STN_BTN_QUIT].y && y<stnButton[ID_STN_BTN_QUIT].y+stnButton[ID_STN_BTN_QUIT].height)
    {
        if(x>stnButton[ID_STN_BTN_QUIT].x && x<stnButton[ID_STN_BTN_QUIT].x+stnButton[ID_STN_BTN_QUIT].width)
        {
            motion=ID_STN_BTN_QUIT;
            //if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
        }
        else if(x>stnButton[ID_STN_PRT_SCN].x && x<stnButton[ID_STN_PRT_SCN].x+stnButton[ID_STN_PRT_SCN].width)
        {
            motion=ID_STN_PRT_SCN;
            //if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
        }
        else if(x>stnButton[ID_STN_BTN_APPLY].x && x<stnButton[ID_STN_BTN_APPLY].x+stnButton[ID_STN_BTN_APPLY].width)
        {
            motion=ID_STN_BTN_APPLY;
            //if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
        }
        else
        {
            motion=ID_STN_NONE;
            //if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
        }
    }
    else
    {
        motion=ID_STN_NONE;
        //if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
    }
    panelBottom->Refresh();
}

void MySetupDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_STN_NONE;
    panelBottom->Refresh();
}

void MySetupDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_STN_BTN_QUIT)
    {
        if(iok==1)
        {
            ConfirmDlg dlg(this);
            dlg.confirmMsg=_("未设站定向，确定退出？");
            dlg.Center();
            if(dlg.ShowModal()==wxID_OK)
            {
                Destroy();
            }
            else
            {
                return;
            }
        }
        else
        {
            if(mtg->istat.x!=mtg->istn.statx ||
               mtg->istat.y!=mtg->istn.staty ||
               mtg->istat.z!=mtg->istn.statz ||
               mtg->iback.x!=mtg->istn.backx ||
               mtg->iback.y!=mtg->istn.backy ||
               mtg->iback.z!=mtg->istn.backz)
            {
                ConfirmDlg dlg(this);
                dlg.confirmMsg=_("测站异常，请检查！");
                dlg.Center();
                if(dlg.ShowModal()==wxID_OK)
                {
                    Destroy();
                }
                else
                {
                    return;
                }
            }
            else
            {
                Destroy();
            }
        }
    }
    else if(motion==ID_STN_PRT_SCN)
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
        str=_("移站界面");
        str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
        }
    }
    else if(motion==ID_STN_BTN_APPLY)
    {
        panelBottom->Refresh();
    }
}

void MySetupDlg::UpdateBaskList()
{
    baskList->DeleteAllItems();

    for(int i=0; i<mtg->nbsk; i++)
    {
        baskList->InsertItem(i,wxString(mtg->bask[i].name,wxConvUTF8));
        baskList->SetItem(i,1,wxString::Format(_("%.4f"),mtg->bask[i].x));
        baskList->SetItem(i,2,wxString::Format(_("%.4f"),mtg->bask[i].y));
        baskList->SetItem(i,3,wxString::Format(_("%.4f"),mtg->bask[i].z));
        baskList->SetItem(i,4,wxDateTime(mtg->bask[i].t).Format(_("%Y-%m-%d %H:%M")));
        /*if(i==selBask[0])
        {
            baskList->SetItem(i,5,_("测站"));
        }
        else if(i==selBask[1])
        {
            baskList->SetItem(i,5,_("后视"));
        }*/
    }
}

void MySetupDlg::OnListStationActivated(wxListEvent& event)
{
    StationDlg dlg(this);
    int sel=stnList->GetFirstSelected();
    dlg.stn=sres[sel];
    //dlg.m=mtg->m1;
    dlg.Center();
    dlg.ShowModal();
}

void MySetupDlg::UpdateStationList()
{
    stnList->DeleteAllItems();

    for(int i=0;i<nres;i++)
    {
        stnList->InsertItem(i,wxString::Format(_("%d"),i+1));
        stnList->SetItem(i,1,wxString(sres[i].stat,wxConvUTF8));
        stnList->SetItem(i,2,wxString(sres[i].back,wxConvUTF8));
        double dx=sres[i].backx-sres[i].statx;
        double dy=sres[i].backy-sres[i].staty;
        double dv=sres[i].backz+sres[i].backh-sres[i].statz-sres[i].stath;
        double dh=sqrt(dx*dx+dy*dy);
        double dh1=sres[i].backz1*cos(PI/2-sres[i].backy1);
        double dv1=sres[i].backz1*sin(PI/2-sres[i].backy1);
        stnList->SetItem(i,3,wxString::Format(_("%.1f"),((dh1-dh)*1000.0)));
        stnList->SetItem(i,4,wxString::Format(_("%.1f"),((dv1-dv)*1000.0)));
        stnList->SetItem(i,5,wxDateTime(sres[i].t).Format(_("%Y-%m-%d %H:%M:%S")));
    }
    stnList->Select(nres-1);
    stnList->EnsureVisible(nres-1);
}

void MySetupDlg::UpdateStation()
{
    ///设站定向页面
    stationName->SetValue(wxString(istn.stat,wxConvUTF8));
    stationX->SetValue(wxString::Format(_("%.4f"),istn.statx));
    stationY->SetValue(wxString::Format(_("%.4f"),istn.staty));
    stationZ->SetValue(wxString::Format(_("%.4f"),istn.statz));
    stationH->SetValue(wxString::Format(_("%.4f"),istn.stath));
    backName->SetValue(wxString(istn.back,wxConvUTF8));
    backX->SetValue(wxString::Format(_("%.4f"),istn.backx));
    backY->SetValue(wxString::Format(_("%.4f"),istn.backy));
    backZ->SetValue(wxString::Format(_("%.4f"),istn.backz));
    backH->SetValue(wxString::Format(_("%.4f"),istn.backh));
    InitiaBasketSelected();
}

void MySetupDlg::UpdateView(int page)
{
    if(page==0)
    {
        stationName->SetValue(wxString(mtg->istn.stat,wxConvUTF8));
        stationX->SetValue(wxString::Format(_("%.4f"),mtg->istn.statx));
        stationY->SetValue(wxString::Format(_("%.4f"),mtg->istn.staty));
        stationZ->SetValue(wxString::Format(_("%.4f"),mtg->istn.statz));
        stationH->SetValue(wxString::Format(_("%.4f"),mtg->istn.stath));
        backName->SetValue(wxString(mtg->istn.back,wxConvUTF8));
        backX->SetValue(wxString::Format(_("%.4f"),mtg->istn.backx));
        backY->SetValue(wxString::Format(_("%.4f"),mtg->istn.backy));
        backZ->SetValue(wxString::Format(_("%.4f"),mtg->istn.backz));
        backH->SetValue(wxString::Format(_("%.4f"),mtg->istn.backh));
        panelStationFig->Refresh();
    }
    else if(page==1)
    {
        panelMeasFig->Refresh();
    }
    else if(page==2)
    {
        studyX->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[0]));
        studyY->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[1]));
        studyZ->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[2]));
        panelStuyFig->Refresh();
    }
}

void MySetupDlg::UpdateMeasBasket()
{
    panelMeasFig->Refresh();
}

void MySetupDlg::UpdateStudy()
{
    studyX->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[0]));
    studyY->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[1]));
    studyZ->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[2]));
    panelStuyFig->Refresh();
}

void MySetupDlg::WriteMsg(wxString msg,int col)
{
    m_msg=msg;
    m_msgc=col;
    panelBottom->Refresh();
}

void MySetupDlg::InitiaBasketSelected()
{
    wxString str1=wxString(mtg->istn.stat,wxConvUTF8);
    wxString str2=wxString(mtg->istn.back,wxConvUTF8);
    istation=-1;
    iback=-1;
    for(int i=0;i<mtg->nbsk;i++)
    {
        if(str1.Cmp(wxString((const char*)mtg->bask[i].name,wxConvLocal))==0)
        {
            istation=i;
        }
        else if(str2.Cmp(wxString((const char*)mtg->bask[i].name,wxConvLocal))==0)
        {
            iback=i;
        }
    }
}

void MySetupDlg::OnPaintBackground(wxPaintEvent& event)
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

void MySetupDlg::OnPaintNavi(wxPaintEvent& event)
{
    wxPaintDC dc(panelNavi);
    int w,h;
    panelNavi->GetClientSize(&w,&h);

    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(0,-1,w,h+1);
}

void MySetupDlg::OnTimer(wxTimerEvent& event)
{
    static int tick=0;
    int i=0;
    double dbval=0.0;
    wxString str;
    if(mtg->ithread==MTG_THREAD_MEASUREBACK ||
       mtg->ithread==MTG_THREAD_SETUP ||
       mtg->ithread==MTG_THREAD_BASKET ||
       mtg->ithread==MTG_THREAD_MEASUREPRISM ||
       mtg->ithread==MTG_THREAD_POSITION_BACK ||
       mtg->ithread==MTG_THREAD_POSITION_PRISM ||
       mtg->ithread==MTG_THREAD_RE_SETUP ||
       mtg->ithread==MTG_THREAD_PRISMCHECK ||
       mtg->ithread==MTG_THREAD_MP)
    {
        if(mtg->plog > 0)
        {
            wxString strLog;
            for(i=0;i<mtg->plog;i++)
            {
                strLog = wxString(mtg->plogs[i].msg,wxConvLocal);
                WriteMsg(strLog,mtg->plogs[i].type);

                if(mtg->ithread==MTG_THREAD_MEASUREBACK)
                {
                    if(mtg->plogs[i].nlog==MTG_LOG_FINISH_MEASURE_PRISM)
                    {
                        istn.backx1=mtg->backmeas[0];
                        istn.backy1=mtg->backmeas[1];
                        istn.backz1=mtg->backmeas[2];
                        time(&istn.t);
                        iok=1;
                        panelStationFig->Refresh();
                    }
                }
                else if(mtg->ithread==MTG_THREAD_SETUP)
                {
                    if(mtg->plogs[i].nlog==MTG_LOG_FINISH_SET_ORIENTATION)
                    {
                        if(mtg_store_station(mtg))
                        {
                            WriteMsg(_("设站完成！"),0);
                            iok=0;
                            istn.id++;
                        }
                        else
                        {
                            WriteMsg(_("测站存储失败"),1);
                        }
                    }
                    else if(mtg->plogs[i].nlog==MTG_LOG_FAIL_SET_ORIENTATION)
                    {
                        WriteMsg(_("设站失败！"),1);
                        iok=0;
                    }
                }
                else if(mtg->ithread==MTG_THREAD_BASKET)
                {
                    if(mtg->plogs[i].nlog==MTG_LOG_FINISH_SETMEASURE_BASKET)
                    {
                        mBask.x=mtg->baskcoord[0];
                        mBask.y=mtg->baskcoord[1];
                        mBask.z=mtg->baskcoord[2];
                        time(&mBask.t);
                        panelMeasFig->Refresh();
                    }
                }
                else if(mtg->ithread==MTG_THREAD_MEASUREPRISM)
                {
                    if(mtg->plogs[i].nlog==MTG_LOG_FINISH_MEASURE_PRISM)
                    {
                        studyX->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[0]));
                        studyY->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[1]));
                        studyZ->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[2]));
                        istudy=1;
                    }
                }
                else if(mtg->ithread==MTG_THREAD_PRISMCHECK)
                {
                    if(mtg->plogs[i].nlog==MTG_LOG_FINISH_MEASURE_PRISM)
                    {
                        studyX->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[0]));
                        studyY->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[1]));
                        studyZ->SetValue(wxString::Format(_("%.4f"),mtg->prismcoord[2]));
                        istudy=1;
                    }
                }
                else if(mtg->plogs[i].nlog==MTG_LOG_FINISH_GESTURE_CHECK)
                {
                    mtg->mp.headh1=mtg->m.headh;
                    mtg->mp.headv1=mtg->m.headv;
                    mtg->mp.tailh1=mtg->m.tailh;
                    mtg->mp.tailv1=mtg->m.tailv;
                    mtg->mp.inc[3]=mtg->m.inc1[0];
                    mtg->mp.inc[4]=mtg->m.inc1[1];
                    mtg->mp.inc[5]=mtg->m.inc1[2];
                    mtg->mp.head[3]=mtg->m.head[0];
                    mtg->mp.head[4]=mtg->m.head[1];
                    mtg->mp.head[5]=mtg->m.head[2];
                    mtg->mp.tail[3]=mtg->m.tail[0];
                    mtg->mp.tail[4]=mtg->m.tail[1];
                    mtg->mp.tail[5]=mtg->m.tail[2];
                    checkText->Refresh();
                    mtg_store_mp(mtg);
                }
            }
            mtg->plog=0;
        }
    }

    tick++;
    if(tick % 10==0)
    {
        stationH->GetValue().ToDouble(&dbval);
        if(dbval!=istn.stath)
        {
            istn.stath=dbval;
            panelStationFig->Refresh();
        }

        backH->GetValue().ToDouble(&dbval);
        if(dbval!=istn.backh)
        {
            istn.backh=dbval;
            panelStationFig->Refresh();
        }
    }

    if(tick == 1200) tick=0;
}


