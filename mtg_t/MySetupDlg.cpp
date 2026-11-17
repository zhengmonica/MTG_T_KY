///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MySetupDlg.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"
#include "BasketDlg.h"
#include "EditBskDlg.h"
#include "StationDlg.h"
#include "confirmdlg.h"
#include "SegDialog.h"
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


const long MySetupDlg::ID_PANEL1 = wxNewId();                  //标题
const long MySetupDlg::ID_PANEL2 = wxNewId();                  //按钮
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
	panelTitle = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelTitle->IsMaximinize=0;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("移站设置");
    panelButtonList = new MDButtonList(this, ID_PANEL2, wxPoint(0,31), wxSize(150,h-76), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(150,31), wxSize(w-150,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelNavi = new wxPanel(panelMain, wxID_ANY, wxPoint(600+w,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x1=0;
    y1=11;
    w1=w-150;
    h1=h-88;
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

    panelBasketMeas = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBasketMeas->SetBackgroundColour(wxColor(239,239,239));

    x2=x1;
    y2=y1;
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

    x2=x1;
    y2=y2+h2+gh2+11;
    h2=h1-y2-15;
    w2=w1-x1*2-83;

    panelMeasFig = new wxPanel(panelBasketMeas, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMeasFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x2+w2+18;
    w2=65;
    panelBasketButton = new wxPanel(panelBasketMeas, wxID_ANY, wxPoint(x2,y1+gh2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBasketButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelStudy = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStudy->SetBackgroundColour(wxColor(239,239,239));

    x2=x1;
    y2=y1;
    w2=180;
    h2=25;
    studyStaticText1 = new wxStaticText(panelStudy, wxID_ANY, _("北坐标（X）"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    studyX = new wxMyTextCtrl(panelStudy, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-25,h2), 0);
    x2=x2+w2+9;
    studyStaticText2 = new wxStaticText(panelStudy, wxID_ANY, _("东坐标（Y）"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    studyY = new wxMyTextCtrl(panelStudy, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-25,h2), 0);
    x2=x2+w2+9;
    studyStaticText3 = new wxStaticText(panelStudy, wxID_ANY, _("高程（Z）"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    studyZ = new wxMyTextCtrl(panelStudy, wxID_ANY, wxEmptyString, wxPoint(x2,y2+gh2), wxSize(w2-25,h2), 0);

    x2=x1;
    y2=y2+h2+gh2+11;
    h2=h1-y2-15;
    w2=w1-x1*2-83;
    panelStuyFig = new wxPanel(panelStudy, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStuyFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x2=x2+w2+18;
    w2=65;
    studyButton = new wxPanel(panelStudy, wxID_ANY, wxPoint(x2,y1+gh2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    studyButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);


    panelBasket = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBasket->SetBackgroundColour(wxColor(239,239,239));
    x2=x1;
    y2=y1;
    w2=w1-x1*2-75;
    h2=h1-y1-15;
    panelBasketList = new wxPanel(panelBasket, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBasketList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    baskList = new wxListView(panelBasketList, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    x2=x2+w2+10;
    w2=65;
    panelBaskListButton = new wxPanel(panelBasket, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBaskListButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelBaskListButton->Show(false);

    panelStationList = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStationList->SetBackgroundColour(wxColor(239,239,239));
    x2=x1;
    y2=y1;
    w2=w1-x1*2-75;
    h2=h1-y1-15;
    panelStationGrid = new wxPanel(panelStationList, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStationGrid->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    stnList = new wxListView(panelStationGrid, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    x2=x2+w2+10;
    w2=65;
    panelStationListButton = new wxPanel(panelStationList, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelStationListButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelLooking = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelLooking->SetBackgroundColour(wxColor(239,239,239));
    x2=x1;
    y2=y1;
    w2=w1-x1*2-75;
    h2=h1-y1-15;
    lookingText = new wxPanel(panelLooking, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    lookingText->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x2+w2+10;
    w2=65;
    lookingButton = new wxPanel(panelLooking, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    lookingButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);


    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelNavi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

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

    panelStationGrid->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintStationGrid,0,this);

    panelStationListButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintStationListButton,0,this);
    panelStationListButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionStationListButton,0,this);
    panelStationListButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveStationListButton,0,this);
    panelStationListButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickStationListButton,0,this);

    stnList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&MySetupDlg::OnListStationActivated,0,this);

    lookingButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintLookingButton,0,this);
    lookingButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionLookingButton,0,this);
    lookingButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveLookingButton,0,this);
    lookingButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickLookingButton,0,this);

    lookingText->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintLookingText,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MySetupDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnClickBottom,0,this);

    baskList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&MySetupDlg::OnBasketSelect,0,this);
    baskList->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&MySetupDlg::OnBasketDeselected,0,this);
    baskList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&MySetupDlg::OnBasketActivated,0,this);

    panelButtonList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDlg::OnButtonClick,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    panelButtonList->btn_height=27;
    panelButtonList->AddButton(_("设站定向"));
    panelButtonList->AddButton(_("姿态复核"));
    panelButtonList->AddButton(_("换站测量"));
    panelButtonList->AddButton(_("学习测量"));
    panelButtonList->AddButton(_("吊篮列表"));
    panelButtonList->AddButton(_("设站记录"));
    panelButtonList->btn_clicked=0;

    motion=ID_STN_NONE;

    int i=0;
    baskList->InsertColumn(i++,_("点名"),wxLIST_FORMAT_CENTRE,55);
    baskList->InsertColumn(i++,_("X"),wxLIST_FORMAT_CENTRE,90);
    baskList->InsertColumn(i++,_("Y"),wxLIST_FORMAT_CENTRE,90);
    baskList->InsertColumn(i++,_("Z"),wxLIST_FORMAT_CENTRE,80);
    baskList->InsertColumn(i++,_("T"),wxLIST_FORMAT_CENTRE,115);
    baskList->InsertColumn(i++,_("测站/后视"),wxLIST_FORMAT_CENTRE,65);

	i=0;
	stnList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,55);
    stnList->InsertColumn(i++,_("测站"),wxLIST_FORMAT_CENTRE,65);
    stnList->InsertColumn(i++,_("后视"),wxLIST_FORMAT_CENTRE,65);
    stnList->InsertColumn(i++,_("平距差"),wxLIST_FORMAT_CENTRE,95);
    stnList->InsertColumn(i++,_("高程"),wxLIST_FORMAT_CENTRE,85);
    stnList->InsertColumn(i++,_("T"),wxLIST_FORMAT_CENTRE,135);

    wxString empstr;
    ///设站定向数据
    mBask.t=0;

    measName->SetValue(empstr);
    measTurns->SetValue(_("3"));
    measHeight->SetValue(_("0.2400"));

    t1=0;
    t2=1000;
    mBask.t=0;

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

void MySetupDlg::OnButtonClick(wxMouseEvent& event)
{
    int btn = panelButtonList->btn_left_down;
    int w,h;
    panelStation->GetClientSize(&w,&h);

    switch(btn)
    {
    case 0:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelBasketMeas->SetSize(1024,11,w,h);
        panelStudy->SetSize(1024,11,w,h);
        panelBasket->SetSize(1024,11,w,h);
        panelStationList->SetSize(1024,11,w,h);
        panelLooking->SetSize(1024,11,w,h);
        panelStation->SetSize(0,11,w,h);
        break;
    case 1:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelStation->SetSize(1024,11,w,h);
        panelStudy->SetSize(1024,11,w,h);
        panelBasket->SetSize(1024,11,w,h);
        panelStationList->SetSize(1024,11,w,h);
        panelBasketMeas->SetSize(1024,11,w,h);
        panelLooking->SetSize(0,11,w,h);
        break;
    case 2:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelStation->SetSize(1024,11,w,h);
        panelStudy->SetSize(1024,11,w,h);
        panelBasket->SetSize(1024,11,w,h);
        panelStationList->SetSize(1024,11,w,h);
        panelLooking->SetSize(1024,11,w,h);
        panelBasketMeas->SetSize(0,11,w,h);
        break;
    case 3:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelBasketMeas->SetSize(1024,11,w,h);
        panelStation->SetSize(1024,11,w,h);
        panelBasket->SetSize(1024,11,w,h);
        panelStationList->SetSize(1024,11,w,h);
        panelLooking->SetSize(1024,11,w,h);
        panelStudy->SetSize(0,11,w,h);
        break;
    case 4:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelBasketMeas->SetSize(1024,11,w,h);
        panelStation->SetSize(1024,11,w,h);
        panelStudy->SetSize(1024,11,w,h);
        panelStationList->SetSize(1024,11,w,h);
        panelLooking->SetSize(1024,11,w,h);
        panelBasket->SetSize(0,11,w,h);
        break;
    case 5:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelBasketMeas->SetSize(1024,11,w,h);
        panelStation->SetSize(1024,11,w,h);
        panelStudy->SetSize(1024,11,w,h);
        panelBasket->SetSize(1024,11,w,h);
        panelLooking->SetSize(1024,11,w,h);
        panelStationList->SetSize(0,11,w,h);
        UpdateStationList();
        break;
    default:
        break;
    }
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
    if(cli->imode==0)
    {
        WriteMsg(_("需要控制权限！"),1);
        return;
    }

    if(cli->iget>0)
    {
        WriteMsg(_("系统忙，请稍后！"),1);
        return;
    }

    BasketDlg dlg(this);
    dlg.basketList->DeleteAllItems();
    for(int i=0; i<cli->nbsk; i++)
    {
        dlg.basketList->InsertItem(i,wxString(cli->bask[i].name,wxConvUTF8));
        dlg.basketList->SetItem(i,1,wxString::Format(_("%.4f"),cli->bask[i].x));
        dlg.basketList->SetItem(i,2,wxString::Format(_("%.4f"),cli->bask[i].y));
        dlg.basketList->SetItem(i,3,wxString::Format(_("%.4f"),cli->bask[i].z));
        dlg.basketList->SetItem(i,4,wxDateTime(cli->bask[i].t).Format(_("%Y-%m-%d %H:%M")));
        if(i==istn)
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
        if(sel>=0 && sel<cli->nbsk)
        {
            char msg[260];
            sprintf(msg,"%%R1Q,53:3:%d\n",sel);
            sock->Write(msg,strlen(msg));
            time(&t1);
            sprintf(cmd,"%%R1Q,53:3:%d\n",sel);
            cli->iget=1;
        }
    }
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
    if(cli->imode==0)
    {
        WriteMsg(_("需要控制权限！"),1);
        return;
    }

    if(cli->iget>0)
    {
        WriteMsg(_("系统忙，请稍后！"),1);
        return;
    }

    BasketDlg dlg(this);
    dlg.basketList->DeleteAllItems();
    for(int i=0; i<cli->nbsk; i++)
    {
        dlg.basketList->InsertItem(i,wxString(cli->bask[i].name,wxConvUTF8));
        dlg.basketList->SetItem(i,1,wxString::Format(_("%.4f"),cli->bask[i].x));
        dlg.basketList->SetItem(i,2,wxString::Format(_("%.4f"),cli->bask[i].y));
        dlg.basketList->SetItem(i,3,wxString::Format(_("%.4f"),cli->bask[i].z));
        dlg.basketList->SetItem(i,4,wxDateTime(cli->bask[i].t).Format(_("%Y-%m-%d %H:%M")));
        if(i==istn)
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
        if(sel>=0 && sel<cli->nbsk)
        {
            char msg[260];
            sprintf(msg,"%%R1Q,53:4:%d\n",sel);
            sock->Write(msg,strlen(msg));
            time(&t1);
            sprintf(cmd,"%%R1Q,53:4:%d\n",sel);
            cli->iget=1;
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
        memDC.DrawLabel(_("测  量"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_SET].x=x1;
        stnButton[ID_STN_SET].y=y1;
        stnButton[ID_STN_SET].width=w1;
        stnButton[ID_STN_SET].height=h1;

        if(motion==ID_STN_SET)
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
        memDC.DrawLabel(_("设  置"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_SET_RESET].x=x1;
        stnButton[ID_STN_SET_RESET].y=y1;
        stnButton[ID_STN_SET_RESET].width=w1;
        stnButton[ID_STN_SET_RESET].height=h1;

        if(motion==ID_STN_SET_RESET)
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
        memDC.DrawLabel(_("复  位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_SET_TO_BACK].x=x1;
        stnButton[ID_STN_SET_TO_BACK].y=y1;
        stnButton[ID_STN_SET_TO_BACK].width=w1;
        stnButton[ID_STN_SET_TO_BACK].height=h1;

        if(motion==ID_STN_SET_TO_BACK)
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
        memDC.DrawLabel(_("至后视"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_SET_TO_TARGET].x=x1;
        stnButton[ID_STN_SET_TO_TARGET].y=y1;
        stnButton[ID_STN_SET_TO_TARGET].width=w1;
        stnButton[ID_STN_SET_TO_TARGET].height=h1;

        if(motion==ID_STN_SET_TO_TARGET)
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
    if(cli->imode==0)
    {
        WriteMsg(_("需要控制权限！"),1);
        return;
    }

    if(motion==ID_STN_SET_MEAS)
    {
        char msg[260];
        sprintf(msg,"%%R1Q,53:5:%d\n",0);
        sock->Write(msg,strlen(msg));
        time(&t1);
        sprintf(cmd,"%%R1Q,53:5:%d\n",0);
        cli->iget=1;
    }
    else if(motion==ID_STN_SET)
    {
        char msg[260];
        double h1,h2;
        wxString valstr;
        valstr=stationH->GetValue();
        if(valstr.IsEmpty())
        {
            h1=0;
            stationH->SetValue(_("0.0000"));
            WriteMsg(_(""),0);
        }
        else if(!valstr.ToDouble(&h1))
        {
            WriteMsg(_("仪器高输入错误，请检查！"),1);
            stationH->SetFocus();
            stationH->SetSelection(-1,-1);
            return;
        }
        valstr=backH->GetValue();
        if(valstr.IsEmpty())
        {
            h1=0;
            backH->SetValue(_("0.0000"));
            WriteMsg(_(""),0);
        }
        else if(!valstr.ToDouble(&h1))
        {
            WriteMsg(_("棱镜高输入错误，请检查！"),1);
            backH->SetFocus();
            backH->SetSelection(-1,-1);
            return;
        }
        sprintf(msg,"%%R1Q,53:6:%d,%lf,%lf\n",0,h1,h2);
        sock->Write(msg,strlen(msg));
        time(&t1);
        sprintf(cmd,"%%R1Q,53:6:%d,%lf,%lf\n",0,h1,h2);
        cli->iget=1;
    }
    else if(motion==ID_STN_SET_TO_BACK)
    {
        char msg[260];
        sprintf(msg,"%%R1Q,53:8:%d\n",0);
        sock->Write(msg,strlen(msg));
        time(&t1);
        sprintf(cmd,"%%R1Q,53:8:%d\n",0);
        cli->iget=1;
    }
    else if(motion==ID_STN_SET_TO_TARGET)
    {
        char msg[260];
        //cli->prismcoord[0]=-9.86;
        //cli->prismcoord[1]=-0.578;
        //cli->prismcoord[2]=0.0125;
        sprintf(msg,"%%R1Q,53:9:%d,%lf,%lf,%lf\n",0,cli->prismcoord[0],cli->prismcoord[1],cli->prismcoord[2]);
        sock->Write(msg,strlen(msg));
        time(&t1);
        sprintf(cmd,"%%R1Q,53:9:%d\n",0);
        cli->iget=1;
    }
    else if(motion==ID_STN_SET_RESET)
    {
        char msg[260];
        sprintf(msg,"%%R1Q,53:7:%d\n",0);
        sock->Write(msg,strlen(msg));
        time(&t1);
        sprintf(cmd,"%%R1Q,53:7:%d\n",0);
        cli->iget=1;
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
        if(cli->istn.t>0)
        {
            memDC.DrawLabel(wxDateTime(cli->istn.t).Format(_("%Y-%m-%d %H:%M:%S"))+_(" 设置"),wxRect(15,0,w,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        memDC.SetTextForeground(btnTextColor[0]);
        double stnx,stny,stnz,stnh;
        double backx,backy,backz,backh;
        double backx1,backy1,backz1;
        int sel[4]={0};
        long t1,t2,t3;
        int n1,n2;
        n1=istn;
        n2=iback;
        t1=cli->istn.t;
        t2=cli->bask[n1].t;
        t3=cli->bask[n2].t;

        stnx=cli->istn.statx;
        stny=cli->istn.staty;
        stnz=cli->istn.statz;
        stnh=cli->istn.stath;

        backx=cli->istn.backx;
        backy=cli->istn.backy;
        backz=cli->istn.backz;
        backh=cli->istn.backh;

        if(cli->istn.t>0)
        {
            backx1=cli->istn.backx1;
            backy1=cli->istn.backy1;
            backz1=cli->istn.backz1;
        }
        else
        {
            backx1=0.0;
            backy1=0.0;
            backz1=0.0;
        }

        int x1,y1,w1,h1;

        double L0,L;
        double H0,H;

        double dx=backx-stnx;
        double dy=backy-stny;
        double dv=backz+backh-stnz-stnh;
        double dh=sqrt(dx*dx+dy*dy);
        double dh1=backz1*cos(PI/2-backy1);
        double dv1=backz1*sin(PI/2-backy1);


        x1=15;
        y1=34;
        w1=(w-x1*2-90)/3;
        h1=25;
        wxString infoSTR;
        infoSTR = _("平距");
        memDC.DrawLabel(infoSTR,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=90;
        if(t2>0 && t3>0)
        {
            infoSTR = _("理论值 ")+wxString::Format(_("%.4f"),dh)+_(" m");
        }
        else
        {
            infoSTR = _("理论值 ");
        }
        memDC.DrawLabel(infoSTR,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        if(t1>0)
        {
            infoSTR = _("实测值 ")+wxString::Format(_("%.4f"),dh1)+_(" m");
        }
        else
        {
            infoSTR = _("实测值 ");
        }
        memDC.DrawLabel(infoSTR,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        if(t1>0)
        {
            infoSTR = _("较差 ")+wxString::Format(_("%.1f"),(dh1-dh)*1000.0)+_(" mm");
        }
        else
        {
            infoSTR = _("较差 ");
        }
        memDC.DrawLabel(infoSTR,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=15;
        y1=y1+h1;
        infoSTR = _("高差");
        memDC.DrawLabel(infoSTR,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=90;
        if(t2>0 && t3>0)
        {
            infoSTR = _("理论值 ")+wxString::Format(_("%.4f"),dv)+_(" m");
        }
        else
        {
            infoSTR = _("理论值 ");
        }
        memDC.DrawLabel(infoSTR,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        if(t1>0)
        {
            infoSTR = _("实测值 ")+wxString::Format(_("%.4f"),dv1)+_(" m");
        }
        else
        {
            infoSTR = _("实测值 ");
        }
        memDC.DrawLabel(infoSTR,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        if(t1>0)
        {
            infoSTR = _("较差 ")+wxString::Format(_("%.1f"),(dv1-dv)*1000.0)+_(" mm");
        }
        else
        {
            infoSTR = _("较差 ");
        }
        memDC.DrawLabel(infoSTR,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        int nh=road_number_horizon(&cli->r);
        int nv=road_number_vertical(&cli->r);
        if(nh>2 && nv>2)
        {
            x1=15;
            y1=y1+h1+7;
            memDC.SetPen(wxPen(wxColor(189,189,189)));
            memDC.DrawLine(x1,y1,w-x1,y1);

            int R2=90;
            double L1,L2,H1,H2;
            double R1,Mile;

            int x2,y2;
            if(t2>0)
            {
                x2=w/4;
                y2=y1+(h-y1)/2;


                memDC.SetPen(wxPen(wxColor(58,58,58)));
                memDC.DrawCircle(x2,y2,R2);
                memDC.SetPen(wxPen(wxColor(58,58,58),1,wxDOT_DASH));
                memDC.DrawLine(x2-R2-20,y2,x2+R2+20,y2);
                memDC.DrawLine(x2,y2-R2-20,x2,y2+R2+20);

                road_xy2l(&cli->r,stnx,stny,&Mile,0,0,0,&L1);
                road_l2h(&cli->r,Mile,&H1,0);
                H1=stnz-H1;
                R1=L1*L1+H1*H1;
                R1=sqrt(R1);
                if(cli->prj.a2z==-1)
                {
                    L1=-L1;
                }

                L2=R2*L1/R1;
                H2=R2*H1/R1;
                memDC.SetPen(wxPen(wxColor(255,20,20)));
                memDC.DrawLine(x2,y2,x2+L2,y2);

                memDC.DrawLine(x2+L2,y2,x2+L2,y2-H2);
                memDC.DrawLine(x2,y2,x2+L2,y2-H2);

                if(L1>0.0)
                {
                    if(H1>0.0)
                    {
                        memDC.DrawLabel(wxString::Format(_("%.4f"),L1),wxRect(x2,y2+10,L2,y2+10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
                        memDC.DrawLabel(wxString::Format(_("%.4f"),H1),wxRect(x2+L2+10,y2-H2,0,H2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    }
                    else
                    {
                        memDC.DrawLabel(wxString::Format(_("%.4f"),L1),wxRect(x2,y2-10,L2,y2-10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
                        memDC.DrawLabel(wxString::Format(_("%.4f"),-H1),wxRect(x2+L2+10,y2-H2,0,H2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    }
                }
                else
                {
                    if(H1>0.0)
                    {
                        memDC.DrawLabel(wxString::Format(_("%.4f"),-L1),wxRect(x2,y2+10,L2,y2+10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
                        memDC.DrawLabel(wxString::Format(_("%.4f"),H1),wxRect(x2+L2-10,y2-H2,0,H2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                    }
                    else
                    {
                        memDC.DrawLabel(wxString::Format(_("%.4f"),-L1),wxRect(x2,y2-10,L2,y2-10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
                        memDC.DrawLabel(wxString::Format(_("%.4f"),-H1),wxRect(x2+L2-10,y2-H2,0,H2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                    }
                }

                memDC.DrawLabel(_("[测站] "),wxRect(x2-R2,y2-R2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

                memDC.DrawLabel(wxString::Format(_("%.4f"),Mile),wxRect(x2,y2+R2+20,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }

            if(t3>0)
            {
                x2=w*3/4;
                y2=y1+(h-y1)/2;

                memDC.SetPen(wxPen(wxColor(58,58,58)));
                memDC.DrawCircle(x2,y2,R2);
                memDC.SetPen(wxPen(wxColor(58,58,58),1,wxDOT_DASH));
                memDC.DrawLine(x2-R2-20,y2,x2+R2+20,y2);
                memDC.DrawLine(x2,y2-R2-20,x2,y2+R2+20);

                road_xy2l(&cli->r,backx,backy,&Mile,0,0,0,&L1);
                road_l2h(&cli->r,Mile,&H1,0);
                H1=backz-H1;
                R1=L1*L1+H1*H1;
                R1=sqrt(R1);
                if(cli->prj.a2z==-1)
                {
                    L1=-L1;
                }

                L2=R2*L1/R1;
                H2=R2*H1/R1;
                memDC.SetPen(wxPen(wxColor(255,20,20)));
                memDC.DrawLine(x2,y2,x2+L2,y2);

                memDC.DrawLine(x2+L2,y2,x2+L2,y2-H2);
                memDC.DrawLine(x2,y2,x2+L2,y2-H2);

                if(L1>0.0)
                {
                    if(H1>0.0)
                    {
                        memDC.DrawLabel(wxString::Format(_("%.4f"),L1),wxRect(x2,y2+10,L2,y2+10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
                        memDC.DrawLabel(wxString::Format(_("%.4f"),H1),wxRect(x2+L2+10,y2-H2,0,H2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    }
                    else
                    {
                        memDC.DrawLabel(wxString::Format(_("%.4f"),L1),wxRect(x2,y2-10,L2,y2-10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
                        memDC.DrawLabel(wxString::Format(_("%.4f"),-H1),wxRect(x2+L2+10,y2-H2,0,H2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    }
                }
                else
                {
                    if(H1>0.0)
                    {
                        memDC.DrawLabel(wxString::Format(_("%.4f"),-L1),wxRect(x2,y2+10,L2,y2+10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
                        memDC.DrawLabel(wxString::Format(_("%.4f"),H1),wxRect(x2+L2-10,y2-H2,0,H2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                    }
                    else
                    {
                        memDC.DrawLabel(wxString::Format(_("%.4f"),-L1),wxRect(x2,y2-10,L2,y2-10),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
                        memDC.DrawLabel(wxString::Format(_("%.4f"),-H1),wxRect(x2+L2-10,y2-H2,0,H2),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                    }
                }

                memDC.DrawLabel(_("[后视] "),wxRect(x2-R2,y2-R2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

                memDC.DrawLabel(wxString::Format(_("%.4f"),Mile),wxRect(x2,y2+R2+20,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
        }
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
            memDC.SetTextForeground(btnTextColor[0]);
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

            road_xy2l(&cli->r,bx,by,&Mile,0,0,0,&L1);
            road_l2h(&cli->r,Mile,&H1,0);
            H1=bz-H1;
            R1=L1*L1+H1*H1;
            R1=sqrt(R1);
            if(cli->prj.a2z==-1)
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
        opstr=_("1 直接输入前视坐标   2 输入切口里程计算前视坐标   3 粗略瞄准前视测量前视坐标");
        memDC.DrawLabel(opstr,wxRect(15,0,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        int x1,y1,w1,h1;
        x1=15;
        y1=25;
        w1=w-2*x1;

        double bx,by,bz;
        bx=cli->prismcoord[0];
        by=cli->prismcoord[1];
        bz=cli->prismcoord[2];
        //memDC.DrawLabel(_("系列")+wxString::Format(_("%d"),cli->tps.kind),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLabel(_("型号")+wxString::Format(_("%d"),cli->tps.type),wxRect(x1,y1+25,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLabel(_("型号")+wxString::Format(_("%d"),TPS_DEVICE_LPNT),wxRect(x1,y1+50,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

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

        road_xy2l(&cli->r,bx,by,&Mile,0,0,0,&L1);
        road_l2h(&cli->r,Mile,&H1,0);
        H1=bz-H1;
        R1=L1*L1+H1*H1;
        R1=sqrt(R1);
        if(cli->prj.a2z==-1)
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
        memDC.DrawLabel(_("测量"),wxRect(x1,y1,w1,h1), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_STUDY_CAL].x=x1;
        stnButton[ID_STN_STUDY_CAL].y=y1;
        stnButton[ID_STN_STUDY_CAL].width=w1;
        stnButton[ID_STN_STUDY_CAL].height=h1;
        if(motion==ID_STN_STUDY_CAL)
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
        memDC.DrawLabel(_("计算"),wxRect(x1,y1,w1,h1), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_STUDY_CHECK].x=x1;
        stnButton[ID_STN_STUDY_CHECK].y=y1;
        stnButton[ID_STN_STUDY_CHECK].width=w1;
        stnButton[ID_STN_STUDY_CHECK].height=h1;
        if(motion==ID_STN_STUDY_CHECK)
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
        memDC.DrawLabel(_("检查"),wxRect(x1,y1,w1,h1), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

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
    if(cli->imode==0)
    {
        WriteMsg(_("需要控制权限！"),1);
        return;
    }

    if(motion==ID_STN_STUDY_MEAS)
    {
        char msg[260];
        sprintf(msg,"%%R1Q,53:11:%d\n",0);
        sock->Write(msg,strlen(msg));
        time(&t1);
        sprintf(cmd,"%%R1Q,53:11:%d\n",0);
        cli->iget=1;
    }
    else if(motion==ID_STN_STUDY_CAL)
    {
        double mile;
        HeadMileDlg dlg(this);
        dlg.Center();
        dlg.Mile->SetFocus();
        if(dlg.ShowModal()==wxID_OK)
        {
            dlg.Mile->GetValue().ToDouble(&mile);
            //mtg_cal_prism(cli,mile,styPrism);
            studyX->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[0]));
            studyY->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[1]));
            studyZ->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[2]));
            panelStuyFig->Refresh();
        }

    }
    else if(ID_STN_STUDY_CHECK)
    {
        char msg[260];
        sprintf(msg,"%%R1Q,53:12:%d\n",0);
        sock->Write(msg,strlen(msg));
        time(&t1);
        sprintf(cmd,"%%R1Q,53:12:%d\n",0);
        cli->iget=1;
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
        memDC.DrawLabel(_("测量"),wxRect(x1,y1,w1,h1), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_MEAS_SAVE].x=x1;
        stnButton[ID_STN_MEAS_SAVE].y=y1;
        stnButton[ID_STN_MEAS_SAVE].width=w1;
        stnButton[ID_STN_MEAS_SAVE].height=h1;
        if(motion==ID_STN_MEAS_SAVE)
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
    if(cli->imode==0)
    {
        WriteMsg(_("需要控制权限！"),1);
        return;
    }

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

        char msg[260];
        sprintf(msg,"%%R1Q,53:10:%d,%d,%lf\n",0,turns,prismh);
        sock->Write(msg,strlen(msg));
        time(&t1);
        sprintf(cmd,"%%R1Q,53:10:%d\n",0);
        cli->iget=1;
        istep=-1;
        iface=-1;
        itar=1;
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
        char msg[260];
        sprintf(msg,"%%R1Q,53:0:%d,'%s',%lf,%lf,%lf\n",
             cli->nbsk,mBask.name,mBask.x,mBask.y,mBask.z);
        sock->Write(msg,strlen(msg));
        time(&t1);
        sprintf(cmd,"%%R1Q,53:0:%d\n",0);
        cli->iget=1;
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
    if(cli->imode==0)
    {
        WriteMsg(_("需要控制权限！"),1);
        return;
    }

    if(motion==ID_STN_BSK_ADD)
    {
        if(cli->iget>0)
        {
            WriteMsg(_("系统忙，请稍后！"),1);
            return;
        }
        EditBskDlg dlg(this);
        dlg.Center();
        dlg.bskName->SetFocus();
        if(dlg.ShowModal()==wxID_OK)
        {
            if(cli->nbsk<MAX_BASK)
            {
                wxString str;
                char bname[64];
                double bx,by,bz;
                str=dlg.bskName->GetValue();
                strncpy(bname,str.mb_str(wxConvUTF8),64);
                dlg.bskX->GetValue().ToDouble(&bx);
                dlg.bskY->GetValue().ToDouble(&by);
                dlg.bskZ->GetValue().ToDouble(&bz);

                char msg[260];
                sprintf(msg,"%%R1Q,53:0:%d,'%s',%lf,%lf,%lf\n",
                     cli->nbsk,bname,bx,by,bz);
                sock->Write(msg,strlen(msg));
                time(&t1);
                sprintf(cmd,"%%R1Q,53:0:%d\n",0);
                cli->iget=1;
            }
        }
    }
    else if(motion==ID_STN_BSK_EDI)
    {
        if(cli->iget>0)
        {
            WriteMsg(_("系统忙，请稍后！"),1);
            return;
        }
        int sel = baskList->GetFirstSelected();
        if(sel<0) return;
        EditBskDlg dlg(this);
        dlg.Center();
        dlg.bskName->SetValue(wxString(cli->bask[sel].name,wxConvUTF8));
        dlg.bskX->SetValue(wxString::Format(_("%.4f"),cli->bask[sel].x));
        dlg.bskY->SetValue(wxString::Format(_("%.4f"),cli->bask[sel].y));
        dlg.bskZ->SetValue(wxString::Format(_("%.4f"),cli->bask[sel].z));

        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str;
            char bname[64];
            double bx,by,bz;
            str=dlg.bskName->GetValue();
            strncpy(bname,str.mb_str(wxConvUTF8),64);
            dlg.bskX->GetValue().ToDouble(&bx);
            dlg.bskY->GetValue().ToDouble(&by);
            dlg.bskZ->GetValue().ToDouble(&bz);
            char msg[260];
            sprintf(msg,"%%R1Q,53:1:%d,'%s',%lf,%lf,%lf\n",
                 sel,bname,bx,by,bz);
            sock->Write(msg,strlen(msg));
            time(&t1);
            sprintf(cmd,"%%R1Q,53:1:%d\n",0);
            cli->iget=1;
        }
        motion=ID_STN_NONE;
    }
    else if(motion==ID_STN_BSK_DEL)
    {
        if(cli->iget>0)
        {
            WriteMsg(_("系统忙，请稍后！"),1);
            return;
        }
        int sel = baskList->GetFirstSelected();
        //wxMessageBox(wxString::Format(_("%d"),sel));
        if(sel>=0)
        {
            ConfirmDlg dlg(this);
            dlg.confirmMsg=_("确定删除")+wxString(cli->bask[sel].name,wxConvUTF8)+_("吊篮吗？");
            dlg.Center();
            if(dlg.ShowModal()==wxID_OK)
            {
                char msg[260];
                sprintf(msg,"%%R1Q,53:2:%d\n",sel);
                sock->Write(msg,strlen(msg));
                time(&t1);
                sprintf(cmd,"%%R1Q,53:2:%d\n",sel);
                cli->iget=1;
            }
        }
    }

    panelBaskListButton->Refresh();
}

void MySetupDlg::OnPaintStationGrid(wxPaintEvent& event)
{
    wxPaintDC dc(panelStationGrid);
    int w,h;
    panelStationGrid->GetClientSize(&w,&h);
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

void MySetupDlg::OnPaintStationListButton(wxPaintEvent& event)
{
    wxPaintDC dc(panelStationListButton);
    int w,h;
    panelStationListButton->GetClientSize(&w,&h);
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

        stnButton[ID_STN_STN_EPT].x=x1;
        stnButton[ID_STN_STN_EPT].y=y1;
        stnButton[ID_STN_STN_EPT].width=w1;
        stnButton[ID_STN_STN_EPT].height=h1;

        if(motion==ID_STN_STN_EPT)
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

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnMotionStationListButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>stnButton[ID_STN_STN_EPT].y && y<stnButton[ID_STN_STN_EPT].y+stnButton[ID_STN_STN_EPT].height)
    {
        if(x>stnButton[ID_STN_STN_EPT].x && x<stnButton[ID_STN_STN_EPT].x+stnButton[ID_STN_STN_EPT].width)
        {
            motion=ID_STN_STN_EPT;
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

    panelStationListButton->Refresh();
}

void MySetupDlg::OnLeaveStationListButton(wxMouseEvent& event)
{
    motion=ID_STN_NONE;
    panelStationListButton->Refresh();
}

void MySetupDlg::OnClickStationListButton(wxMouseEvent& event)
{
    if(motion==ID_STN_STN_EPT)
    {

    }
    panelStationListButton->Refresh();
    panelStationGrid->Refresh();
}

void MySetupDlg::OnPaintLookingButton(wxPaintEvent& event)
{
    wxPaintDC dc(lookingButton);
    int w,h;
    lookingButton->GetClientSize(&w,&h);
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

        stnButton[ID_STN_LOOKING_MEAS].x=x1;
        stnButton[ID_STN_LOOKING_MEAS].y=y1;
        stnButton[ID_STN_LOOKING_MEAS].width=w1;
        stnButton[ID_STN_LOOKING_MEAS].height=h1;

        if(motion==ID_STN_LOOKING_MEAS)
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
        memDC.DrawLabel(_("复核"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        stnButton[ID_STN_LOOKING_EXPT].x=x1;
        stnButton[ID_STN_LOOKING_EXPT].y=y1;
        stnButton[ID_STN_LOOKING_EXPT].width=w1;
        stnButton[ID_STN_LOOKING_EXPT].height=h1;

        if(motion==ID_STN_LOOKING_EXPT)
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

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MySetupDlg::OnMotionLookingButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>stnButton[ID_STN_LOOKING_MEAS].y && y<stnButton[ID_STN_LOOKING_MEAS].y+stnButton[ID_STN_LOOKING_MEAS].height)
    {
        if(x>stnButton[ID_STN_LOOKING_MEAS].x && x<stnButton[ID_STN_LOOKING_MEAS].x+stnButton[ID_STN_LOOKING_MEAS].width)
        {
            motion=ID_STN_LOOKING_MEAS;
        }
        else
        {
            motion=ID_STN_NONE;
        }
    }
    else if(y>stnButton[ID_STN_LOOKING_EXPT].y && y<stnButton[ID_STN_LOOKING_EXPT].y+stnButton[ID_STN_LOOKING_EXPT].height)
    {
        if(x>stnButton[ID_STN_LOOKING_EXPT].x && x<stnButton[ID_STN_LOOKING_EXPT].x+stnButton[ID_STN_LOOKING_EXPT].width)
        {
            motion=ID_STN_LOOKING_EXPT;
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

    lookingButton->Refresh();
}

void MySetupDlg::OnLeaveLookingButton(wxMouseEvent& event)
{
    motion=ID_STN_NONE;
    lookingButton->Refresh();
}

void MySetupDlg::OnClickLookingButton(wxMouseEvent& event)
{
    if(motion==ID_STN_LOOKING_MEAS)
    {

    }
    else if(motion==ID_STN_LOOKING_EXPT)
    {

    }
    lookingButton->Refresh();
    lookingText->Refresh();
}

void MySetupDlg::OnPaintLookingText(wxPaintEvent& event)
{
    wxPaintDC dc(lookingText);
    int w,h;
    lookingText->GetClientSize(&w,&h);
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
        w1=w1;
        memDC.DrawLabel(_("激光"),wxRect(x1,y1,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=w1;
        memDC.DrawLabel(_("棱镜"),wxRect(x1,y1,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        memDC.DrawLabel(_("较差"),wxRect(x1,y1,w1,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

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
        y1=6;
        w1=32;
        h1=32;
        x1=9;
        stnButton[ID_STN_EMODE].x=x1;
        stnButton[ID_STN_EMODE].y=y1;
        stnButton[ID_STN_EMODE].width=w1;
        stnButton[ID_STN_EMODE].height=h1;

        if(cli->imode==0)
        {
            if(motion==ID_STN_EMODE)
            {
                memDC.SetPen(btnPen[1]);
                memDC.SetBrush(btnBrush[3]);
                memDC.DrawRoundedRectangle(stnButton[ID_STN_EMODE],3);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(117,117,117)));
                memDC.SetBrush(wxBrush(wxColor(248,248,248)));
                memDC.DrawRoundedRectangle(stnButton[ID_STN_EMODE],3);
            }
            if(bmpAdmin2.IsOk()) memDC.DrawBitmap(bmpAdmin2,x1+1,y1+2);

        }
        else
        {
            if(motion==ID_STN_EMODE)
            {
                memDC.SetPen(btnPen[1]);
                memDC.SetBrush(btnBrush[3]);
                memDC.DrawRoundedRectangle(stnButton[ID_STN_EMODE],3);
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(117,117,117)));
                memDC.SetBrush(wxBrush(wxColor(248,248,248)));
                memDC.DrawRoundedRectangle(stnButton[ID_STN_EMODE],3);
            }
            if(bmpAdmin1.IsOk()) memDC.DrawBitmap(bmpAdmin1,x1+1,y1+2);
        }


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

        panelButtonList->GetSize(&w1,0);
        x1=w1+14;
        w1=w-x1*2;
        //memDC.SetPen(btnPen[0]);
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
            if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
        }
        else if(x>stnButton[ID_STN_BTN_APPLY].x && x<stnButton[ID_STN_BTN_APPLY].x+stnButton[ID_STN_BTN_APPLY].width)
        {
            motion=ID_STN_BTN_APPLY;
            if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
        }
        else if(x>stnButton[ID_STN_EMODE].x && x<stnButton[ID_STN_EMODE].x+stnButton[ID_STN_EMODE].width)
        {
            motion=ID_STN_EMODE;
            if(cli->imode==0)
                WriteMsg(_("切换为控制模式"),0);
            else
                WriteMsg(_("切换为查看模式"),0);
        }
        else
        {
            motion=ID_STN_NONE;
            if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
        }
    }
    else
    {
        motion=ID_STN_NONE;
        if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
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
        Destroy();
    }
    else if(motion==ID_STN_BTN_APPLY)
    {
        panelBottom->Refresh();
    }
}

void MySetupDlg::UpdateBaskList()
{
    baskList->DeleteAllItems();

    for(int i=0; i<cli->nbsk; i++)
    {
        baskList->InsertItem(i,wxString(cli->bask[i].name,wxConvUTF8));
        baskList->SetItem(i,1,wxString::Format(_("%.4f"),cli->bask[i].x));
        baskList->SetItem(i,2,wxString::Format(_("%.4f"),cli->bask[i].y));
        baskList->SetItem(i,3,wxString::Format(_("%.4f"),cli->bask[i].z));
        baskList->SetItem(i,4,wxDateTime(cli->bask[i].t).Format(_("%Y-%m-%d %H:%M")));
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
    dlg.sel=stnList->GetFirstSelected();
    dlg.Center();
    if(dlg.ShowModal()==wxID_OK)
    {

    }
}

void MySetupDlg::UpdateStationList()
{
    stnList->DeleteAllItems();

    for(int i=0;i<cli->nstn;i++)
    {
        stnList->InsertItem(i,wxString::Format(_("%d"),i+1));
        stnList->SetItem(i,1,wxString(cli->stns[i].stat,wxConvUTF8));
        stnList->SetItem(i,2,wxString(cli->stns[i].back,wxConvUTF8));
        double dx=cli->stns[i].backx-cli->stns[i].statx;
        double dy=cli->stns[i].backy-cli->stns[i].staty;
        double dv=cli->stns[i].backz+cli->stns[i].backh-cli->stns[i].statz-cli->stns[i].stath;
        double dh=sqrt(dx*dx+dy*dy);
        double dh1=cli->stns[i].backz1*cos(PI/2-cli->stns[i].backy1);
        double dv1=cli->stns[i].backz1*sin(PI/2-cli->stns[i].backy1);
        stnList->SetItem(i,3,wxString::Format(_("%.1f"),((dh1-dh)*1000.0)));
        stnList->SetItem(i,4,wxString::Format(_("%.1f"),((dv1-dv)*1000.0)));
        stnList->SetItem(i,5,wxDateTime(cli->stns[i].t).Format(_("%Y-%m-%d %H:%M:%S")));
    }
    stnList->Select(cli->nstn-1);
    stnList->EnsureVisible(cli->nstn-1);
}

void MySetupDlg::UpdateStation()
{
    ///设站定向页面
    stationName->SetValue(wxString(cli->istn.stat,wxConvUTF8));
    stationX->SetValue(wxString::Format(_("%.4f"),cli->istn.statx));
    stationY->SetValue(wxString::Format(_("%.4f"),cli->istn.staty));
    stationZ->SetValue(wxString::Format(_("%.4f"),cli->istn.statz));
    stationH->SetValue(wxString::Format(_("%.4f"),cli->istn.stath));
    backName->SetValue(wxString(cli->istn.back,wxConvUTF8));
    backX->SetValue(wxString::Format(_("%.4f"),cli->istn.backx));
    backY->SetValue(wxString::Format(_("%.4f"),cli->istn.backy));
    backZ->SetValue(wxString::Format(_("%.4f"),cli->istn.backz));
    backH->SetValue(wxString::Format(_("%.4f"),cli->istn.backh));
    InitiaBasketSelected();
}

void MySetupDlg::UpdateView(int page)
{
    if(page==0)
    {
        stationName->SetValue(wxString(cli->istn.stat,wxConvUTF8));
        stationX->SetValue(wxString::Format(_("%.4f"),cli->istn.statx));
        stationY->SetValue(wxString::Format(_("%.4f"),cli->istn.staty));
        stationZ->SetValue(wxString::Format(_("%.4f"),cli->istn.statz));
        stationH->SetValue(wxString::Format(_("%.4f"),cli->istn.stath));
        backName->SetValue(wxString(cli->istn.back,wxConvUTF8));
        backX->SetValue(wxString::Format(_("%.4f"),cli->istn.backx));
        backY->SetValue(wxString::Format(_("%.4f"),cli->istn.backy));
        backZ->SetValue(wxString::Format(_("%.4f"),cli->istn.backz));
        backH->SetValue(wxString::Format(_("%.4f"),cli->istn.backh));
        panelStationFig->Refresh();
    }
    else if(page==1)
    {
        panelMeasFig->Refresh();
    }
    else if(page==2)
    {
        studyX->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[0]));
        studyY->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[1]));
        studyZ->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[2]));
        panelStuyFig->Refresh();
    }
}

void MySetupDlg::UpdateMeasBasket()
{
    panelMeasFig->Refresh();
}

void MySetupDlg::UpdateStudy()
{
    studyX->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[0]));
    studyY->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[1]));
    studyZ->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[2]));
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
    wxString str1=wxString(cli->istn.stat,wxConvUTF8);
    wxString str2=wxString(cli->istn.back,wxConvUTF8);
    istn=-1;
    iback=-1;
    for(int i=0;i<cli->nbsk;i++)
    {
        if(str1.Cmp(wxString((const char*)cli->bask[i].name,wxConvLocal))==0)
        {
            istn=i;
        }
        else if(str2.Cmp(wxString((const char*)cli->bask[i].name,wxConvLocal))==0)
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
    int i,j,k;
    time_t t;
    int type;
    char icmd[260]="\0";
    char imsg[260]="\0";
    char iword[4096]="\0";
    //FILE* fp=fopen("E:\\logtimer.log","w");
    if(cli->iget==1)
    {
        time(&t);
        if(t-t1>t2)
        {
            type=-1;
            sscanf(cmd,"%%R1Q,53:%d:%d",&type,&i);
            if(type==0)
            {
                WriteMsg(_("增加吊篮超时，请检查网络！"),1);
            }
            else if(type==1)
            {
                WriteMsg(_("编辑吊篮超时，请检查网络！"),1);
            }
            else if(type==2)
            {
                WriteMsg(_("删除吊篮超时，请检查网络！"),1);
            }
            else if(type==3)
            {
                WriteMsg(_("设置测站点超时，请检查网络！"),1);
            }
            else if(type==4)
            {
                WriteMsg(_("设置后视点超时，请检查网络！"),1);
            }
            else if(type==5)
            {
                WriteMsg(_("后视测量超时，请检查网络！"),1);
            }
            else if(type==6) ///设站定向
            {
                WriteMsg(_("设站定向超时，请检查网络！"),1);
            }
            else if(type==7) ///复位
            {
                WriteMsg(_("复位超时，请检查网络！"),1);
            }
            else if(type==8) ///转向后视
            {
                WriteMsg(_("转向后视超时，请检查网络！"),1);
            }
            else if(type==9) ///转向前视
            {
                WriteMsg(_("转向前视超时，请检查网络！"),1);
            }
            strcpy(cmd,icmd);
            cli->iget=0;
            UpdateBaskList();
        }
    }
    else if(cli->iget==2)
    {
        type=-1;
        sscanf(cli->iword,"%%R1D,54:%d:%d",&type,&i);
        if(type==0) ///增加吊篮
        {
            cli->nbsk++;
		    if(cli->bask) cli->bask=(MTG_BASKET*)realloc(cli->bask,cli->nbsk*sizeof(MTG_BASKET));
		    else cli->bask=(MTG_BASKET*)malloc(sizeof(MTG_BASKET));

		    i=cli->nbsk-1;
            sscanf(cli->iword,"%%R1D,54:0:%d,'%[^']',%lf,%lf,%lf\n",
                    &j,cli->bask[i].name,&cli->bask[i].x,&cli->bask[i].y,&cli->bask[i].z);
            time(&cli->bask[i].t);

            WriteMsg(_("增加吊篮成功！"),0);
            UpdateBaskList();
            strcpy(cli->iword,iword);
            strcpy(cmd,icmd);
            cli->iget=0;
        }
        else if(type==1) ///编辑吊篮
        {
            sscanf(cli->iword,"%%R1D,54:1:%d,'%[^']',%lf,%lf,%lf\n",
                    &j,cli->bask[i].name,&cli->bask[i].x,&cli->bask[i].y,&cli->bask[i].z);
            time(&cli->bask[i].t);
            WriteMsg(_("编辑吊篮成功！"),0);
            //cli_write_log("编辑吊篮成功！",0);
            UpdateBaskList();
            strcpy(cli->iword,iword);
            strcpy(cmd,icmd);
            cli->iget=0;
        }
        else if(type==2) ///删除吊篮
        {
            for(j=i;j<cli->nbsk-1;j++)
            {
                cli->bask[j]=cli->bask[j+1];
            }
            cli->nbsk--;
            WriteMsg(_("删除吊篮成功！"),0);
            UpdateBaskList();
            strcpy(cli->iword,iword);
            strcpy(cmd,icmd);
            cli->iget=0;
        }
        else if(type==3) ///更改测站点
        {
            strncpy(cli->istn.stat,cli->bask[i].name,64);
            cli->istn.statx=cli->bask[i].x;
            cli->istn.staty=cli->bask[i].y;
            cli->istn.statz=cli->bask[i].z;
            istn=i;
            UpdateStation();
            strcpy(cli->iword,iword);
            strcpy(cmd,icmd);
            cli->iget=0;
            panelStationFig->Refresh();
        }
        else if(type==4) ///更改后视点
        {
            strncpy(cli->istn.back,cli->bask[i].name,64);
            cli->istn.backx=cli->bask[i].x;
            cli->istn.backy=cli->bask[i].y;
            cli->istn.backz=cli->bask[i].z;
            iback=i;
            UpdateStation();
            strcpy(cli->iword,iword);
            strcpy(cmd,icmd);
            cli->iget=0;
            panelStationFig->Refresh();
        }
        else if(type==5) ///测量后视
        {
            i=-1;
            sscanf(cli->iword,"%%R1D,54:5:%d\n",&i);
            if(i==0)
            {
                WriteMsg(_("照准后视......"),0);
                time(&t1);
            }
            else if(i==1)
            {
                WriteMsg(_("照准后视失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==2)
            {
                WriteMsg(_("照准后视成功！"),0);
                time(&t1);
            }
            else if(i==3)
            {
                WriteMsg(_("测量后视......"),0);
                time(&t1);
            }
            else if(i==4)
            {
                WriteMsg(_("测量后视失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==5)
            {
                WriteMsg(_("转向后视......"),0);
                time(&t1);
            }
            else if(i==6)
            {
                WriteMsg(_("转向后视失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==7)
            {
                sscanf(cli->iword,"%%R1D,54:5:%d,%lf,%lf,%lf\n",&i,&cli->istn.backx1,&cli->istn.backy1,&cli->istn.backz1);
                time(&cli->istn.t);
                panelStationFig->Refresh();
                WriteMsg(_("测量后视完成！"),0);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
        }
        else if(type==6) ///设站定向
        {
            i=-1;
            sscanf(cli->iword,"%%R1D,54:6:%d\n",&i);
            if(i==8)
            {
                WriteMsg(_("设置测站坐标和仪器高失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==9)
            {
                WriteMsg(_("设置测站坐标和仪器高成功！"),0);
                time(&t1);
            }
            if(i==10)
            {
                WriteMsg(_("设置棱镜高失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==11)
            {
                WriteMsg(_("设置棱镜高成功！"),0);
                time(&t1);
            }
            else if(i==12)
            {
                WriteMsg(_("设站定向失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==13)
            {
                cli->nstn++;
                if(cli->stns) cli->stns=(MTG_STATION*)realloc(cli->stns,cli->nstn*sizeof(MTG_STATION));
                else cli->stns=(MTG_STATION*)malloc(sizeof(MTG_STATION));
                cli->stns[cli->nstn-1]=cli->istn;
                panelStationFig->Refresh();
                WriteMsg(_("设站定向完成！"),0);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
        }
        else if(type==7) ///重新设站定向
        {
            i=-1;
            sscanf(cli->iword,"%%R1D,54:7:%d\n",&i);
            if(i==0)
            {
                WriteMsg(_("照准后视......"),0);
                time(&t1);
            }
            else if(i==1)
            {
                WriteMsg(_("照准后视失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==2)
            {
                WriteMsg(_("照准后视成功！"),0);
                time(&t1);
            }
            else if(i==3)
            {
                WriteMsg(_("测量后视......"),0);
                time(&t1);
            }
            else if(i==4)
            {
                WriteMsg(_("测量后视失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==5)
            {
                WriteMsg(_("转向后视......"),0);
                time(&t1);
            }
            else if(i==6)
            {
                WriteMsg(_("转向后视失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==7)
            {
                sscanf(cli->iword,"%%R1D,54:7:%d,%lf,%lf,%lf\n",&i,&cli->istn.backx1,&cli->istn.backy1,&cli->istn.backz1);
                time(&cli->istn.t);
                panelStationFig->Refresh();
                WriteMsg(_("测量后视完成！"),0);
            }
            else if(i==8)
            {
                WriteMsg(_("设置测站坐标和仪器高失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==9)
            {
                WriteMsg(_("设置测站坐标和仪器高成功！"),0);
                time(&t1);
            }
            if(i==10)
            {
                WriteMsg(_("设置棱镜高失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==11)
            {
                WriteMsg(_("设置棱镜高成功！"),0);
                time(&t1);
            }
            else if(i==12)
            {
                WriteMsg(_("设站定向失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==13)
            {
                cli->nstn++;
                if(cli->stns) cli->stns=(MTG_STATION*)realloc(cli->stns,cli->nstn*sizeof(MTG_STATION));
                else cli->stns=(MTG_STATION*)malloc(sizeof(MTG_STATION));
                cli->stns[cli->nstn-1]=cli->istn;
                panelStationFig->Refresh();
                WriteMsg(_("设站定向完成！"),0);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==14)
            {
                WriteMsg(_("转向后视完成！"),0);
                time(&t1);
            }
        }
        else if(type==8) ///转向后视
        {
            if(i==0)
            {
                WriteMsg(_("转向后视......"),0);
                time(&t1);
            }
            else if(i==1)
            {
                WriteMsg(_("转向后视失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==2)
            {
                WriteMsg(_("转向后视完成！"),0);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
        }
        else if(type==9) ///转向前视
        {
            if(i==0)
            {
                WriteMsg(_("转向前视......"),0);
                time(&t1);
            }
            else if(i==1)
            {
                WriteMsg(_("转向前视失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==2)
            {
                WriteMsg(_("转向前视完成！"),0);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
        }
        else if(type==10) ///换站测量
        {
            if(i==0)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 照准吊篮......",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘左：照准吊篮......"),0);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 照准吊篮......",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘右：照准吊篮......"),0);
                }
                else
                {
                    WriteMsg(_("照准吊篮......"),0);
                }
                time(&t1);
            }
            else if(i==1)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 照准吊篮失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘左：照准吊篮失败，请检查！"),1);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 照准吊篮失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘右：照准吊篮失败，请检查！"),1);
                }
                else
                {
                    WriteMsg(_("照准吊篮失败，请检查！"),1);
                }
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            if(i==2)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 照准吊篮完成！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘左：照准吊篮完成！"),0);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 照准吊篮完成！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘右：照准吊篮完成！"),0);
                }
                else
                {
                    WriteMsg(_("照准吊篮完成！"),0);
                }
                time(&t1);
            }
            else if(i==3)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 测量吊篮......",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘左：测量吊篮......"),0);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 测量吊篮......",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘右：测量吊篮......"),0);
                }
                else
                {
                    WriteMsg(_("测量吊篮......"),0);
                }
                time(&t1);
            }
            else if(i==4)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 测量吊篮失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘左：测量吊篮失败，请检查！"),1);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 测量吊篮失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘右：测量吊篮失败，请检查！"),1);
                }
                else
                {
                    WriteMsg(_("测量吊篮失败，请检查！"),1);
                }
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==5)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 测量完成！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘左：测量完成！"),0);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 测量完成！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘右：测量完成！"),0);
                }
                else
                {
                    WriteMsg(_("测量完成！"),0);
                }
                time(&t1);
            }
            else if(i==6)
            {
                if(iface==-1)
                {
                    iface=0;
                    itar=0;
                    istep=0;
                    sprintf(imsg,"测回<%d> <盘左> 转向后视......",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    time(&t1);
                    strcpy(cli->iword,iword);
                }
                else if(iface==0)
                {
                    if(istep==-1) istep=0;
                    if(itar==0)
                    {
                        iface=1;
                        istep++;
                        sprintf(imsg,"测回<%d> <盘右> 转向后视......",istep+1);
                        WriteMsg(wxString(imsg,wxConvLocal),0);
                        //WriteMsg(_("盘右：转向后视......"),0);
                        time(&t1);
                    }
                    else
                    {
                        sprintf(imsg,"测回<%d> <盘左> 转向后视......",istep+1);
                        WriteMsg(wxString(imsg,wxConvLocal),0);
                        //WriteMsg(_("盘左：转向后视......"),0);
                        itar=0;
                        time(&t1);
                    }
                    strcpy(cli->iword,iword);
                }
                else if(iface==1)
                {
                    if(istep==-1) istep=0;
                    if(itar==0)
                    {
                        iface=0;
                        istep++;
                        sprintf(imsg,"测回<%d> <盘左> 转向后视......",istep+1);
                        WriteMsg(wxString(imsg,wxConvLocal),0);
                        //WriteMsg(_("盘左：转向后视......"),0);
                        time(&t1);
                    }
                    else
                    {
                        itar=0;
                        sprintf(imsg,"测回<%d> <盘右> 转向后视......",istep+1);
                        WriteMsg(wxString(imsg,wxConvLocal),0);
                        //WriteMsg(_("盘右：转向后视......"),0);
                        time(&t1);
                    }
                }
                strcpy(cli->iword,iword);
            }
            else if(i==7)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 转向后视失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘左：转向后视失败，请检查！"),1);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 转向后视失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘右：转向后视失败，请检查！"),1);
                }
                else
                {
                    WriteMsg(_("转向后视失败，请检查！"),1);
                }
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==8)
            {
                if(iface==-1)
                {
                    iface=0;
                    itar=1;
                    WriteMsg(_("盘左：转向吊篮......"),0);
                    strcpy(cli->iword,iword);
                }
                else if(iface==0)
                {
                    if(itar==1)
                    {
                        iface=1;
                        sprintf(imsg,"测回<%d> <盘右> 转向吊篮......",istep+1);
                        WriteMsg(wxString(imsg,wxConvLocal),0);
                        //WriteMsg(_("盘右：转向吊篮......"),0);
                        strcpy(cli->iword,iword);
                    }
                    else
                    {
                        itar=1;
                        sprintf(imsg,"测回<%d> <盘左> 转向吊篮......",istep+1);
                        WriteMsg(wxString(imsg,wxConvLocal),0);
                        //WriteMsg(_("盘左：转向吊篮......"),0);
                        strcpy(cli->iword,iword);
                    }
                }
                else if(iface==1)
                {
                    if(itar==1)
                    {
                        iface=0;
                        sprintf(imsg,"测回<%d> <盘左> 转向吊篮......",istep+1);
                        WriteMsg(wxString(imsg,wxConvLocal),0);
                        //WriteMsg(_("盘左：转向吊篮......"),0);
                        strcpy(cli->iword,iword);
                    }
                    else
                    {
                        itar=1;
                        sprintf(imsg,"测回<%d> <盘右> 转向吊篮......",istep+1);
                        WriteMsg(wxString(imsg,wxConvLocal),0);
                        //WriteMsg(_("盘右：转向吊篮......"),0);
                        strcpy(cli->iword,iword);
                    }
                }
                time(&t1);
            }
            else if(i==9)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 转向吊篮失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘左：转向吊篮失败，请检查！"),1);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 转向吊篮失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘右：转向吊篮失败，请检查！"),1);
                }
                else
                {
                    WriteMsg(_("转向吊篮失败，请检查！"),1);
                }

                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==10)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 照准后视......",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘左：照准后视......"),0);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 照准后视......",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘右：照准后视......"),0);
                }
                else
                {
                    WriteMsg(_("照准后视......"),0);
                }
                time(&t1);
            }
            else if(i==11)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 照准后视失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘左：照准后视失败，请检查！"),1);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 照准后视失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘右：照准后视失败，请检查！"),1);
                }
                else
                {
                    WriteMsg(_("照准后视失败，请检查！"),1);
                }
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==12)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 照准后视完成！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘左：照准后视完成！"),0);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 照准后视完成！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘右：照准后视完成！"),0);
                }
                else
                {
                    WriteMsg(_("照准后视完成！"),0);
                }
                time(&t1);
            }
            else if(i==13)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 测量后视......",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘左：测量后视......"),0);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 测量后视......",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),0);
                    //WriteMsg(_("盘右：测量后视......"),0);
                }
                else
                {
                    WriteMsg(_("测量后视......"),0);
                }
                time(&t1);
            }
            else if(i==14)
            {
                if(iface==0)
                {
                    sprintf(imsg,"测回<%d> <盘左> 测量后视失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘左：测量后视失败，请检查！"),1);
                }
                else if(iface==1)
                {
                    sprintf(imsg,"测回<%d> <盘右> 测量后视失败，请检查！",istep+1);
                    WriteMsg(wxString(imsg,wxConvLocal),1);
                    //WriteMsg(_("盘右：测量后视失败，请检查！"),1);
                }
                else
                {
                    WriteMsg(_("测量后视失败，请检查！"),1);
                }
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==15)
            {
                sscanf(cli->iword,"%%R1D,54:10:%d,%lf,%lf,%lf,%lf,%lf,%lf\n",&i,&mBask.x,&mBask.y,&mBask.z,&d2a,&d2d,&d2c);
                time(&mBask.t);
                panelMeasFig->Refresh();
                WriteMsg(_("新吊篮测量完成"),0);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
                iface=-1;
            }
        }
        else if(type==11) ///学习测量
        {
            if(i==0)
            {
                WriteMsg(_("照准棱镜......"),0);
                time(&t1);
            }
            else if(i==1)
            {
                WriteMsg(_("照准棱镜失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==2)
            {
                WriteMsg(_("照准棱镜完成！"),0);
                time(&t1);
            }
            else if(i==3)
            {
                WriteMsg(_("开始测量......"),0);
                time(&t1);
            }
            else if(i==4)
            {
                WriteMsg(_("测量棱镜失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==5)
            {
                sscanf(cli->iword,"%%R1D,54:11:%d,%lf,%lf,%lf\n",&i,&cli->prismcoord[0],&cli->prismcoord[1],&cli->prismcoord[2]);
                studyX->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[0]));
                studyY->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[1]));
                studyZ->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[2]));
                WriteMsg(_("学习测量完成！"),0);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
                iface=-1;
            }
        }
        else if(type==12) ///学习测量（检查）
        {
            if(i==0)
            {
                WriteMsg(_("转向棱镜......"),0);
                time(&t1);
            }
            else if(i==1)
            {
                WriteMsg(_("转向棱镜失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==2)
            {
                WriteMsg(_("转向棱镜完成！"),0);
                time(&t1);
            }
            else if(i==3)
            {
                WriteMsg(_("照准棱镜......"),0);
                time(&t1);
            }
            else if(i==4)
            {
                WriteMsg(_("照准棱镜失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==5)
            {
                WriteMsg(_("照准棱镜完成！"),0);
                time(&t1);
            }
            else if(i==6)
            {
                WriteMsg(_("开始测量......"),0);
                time(&t1);
            }
            else if(i==7)
            {
                WriteMsg(_("测量棱镜失败，请检查！"),1);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
            }
            else if(i==8)
            {
                sscanf(cli->iword,"%%R1D,54:11:%d,%lf,%lf,%lf\n",&i,&cli->prismcoord[0],&cli->prismcoord[1],&cli->prismcoord[2]);
                studyX->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[0]));
                studyY->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[1]));
                studyZ->SetValue(wxString::Format(_("%.4f"),cli->prismcoord[2]));
                WriteMsg(_("学习测量完成！"),0);
                strcpy(cli->iword,iword);
                strcpy(cmd,icmd);
                cli->iget=0;
                iface=-1;
            }
        }
    }
    //fclose(fp);
}


