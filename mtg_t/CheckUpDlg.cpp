///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "CheckUpDlg.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"
#include "confirmdlg.h"
#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include "time.h"

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(CheckUpDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(CheckUpDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(CheckUpDlg)


const long CheckUpDlg::ID_PANEL1 = wxNewId();                  //标题
const long CheckUpDlg::ID_PANEL2 = wxNewId();                  //按钮
//*)

CheckUpDlg::CheckUpDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int dh=20;
	int x2,y2,w2,h2;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelTitle = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelTitle->IsMaximinize=0;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("系统检查");
    panelButtonList = new MDButtonList(this, ID_PANEL2, wxPoint(0,31), wxSize(150,h-76), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(150,31), wxSize(w-150,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelNavi = new wxPanel(panelMain, wxID_ANY, wxPoint(600+w,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x1=0;
    y1=11;
    w1=w-150;
    h1=h-88;
    panelTps = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTps->SetBackgroundColour(wxColor(239,239,239));

    x1=15;
    y1=17;
    //tpsStaticText1 = new wxStaticText(panelTps, wxID_ANY, _("异常信息"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    //tpsStaticLine1 = new wxStaticLine(panelTps, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w1-x1*2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    //x1+=7;
    //y1+=8;
    panelTpsList = new wxPanel(panelTps, wxID_ANY, wxPoint(x1,y1), wxSize(w1-x1*2,h1-y1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTpsList->SetBackgroundColour(wxColor(239,239,239));
    //tpsInfoGrid = new wxGrid(panelTpsList, wxID_ANY, wxPoint(1,25), wxSize(w1-x1*2-2,h1-y1-42), 0, _T("wxID_ANY"));
    tpsList = new wxListView(panelTpsList, wxID_ANY, wxPoint(0,24), wxSize(w1-x1*2,h1-y1-39), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelTars = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTars->SetBackgroundColour(wxColor(239,239,239));
    x1=15;
    y1=17;

    //tarStaticText1 = new wxStaticText(panelTars, wxID_ANY, _("姿态角"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    //tarStaticLine1 = new wxStaticLine(panelTars, wxID_ANY, wxPoint(x1+38,y1+8), wxSize(w1-x1*2-38,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    //x1+=7;
    //y1+=25;

    panelTarInc = new wxPanel(panelTars, wxID_ANY, wxPoint(x1,y1), wxSize(w1-x1*2,h1-y1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTarInc->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    incList = new wxListView(panelTarInc, wxID_ANY, wxPoint(0,24), wxSize(w1-x1*2,h1-y1-39), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelPLC = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPLC->SetBackgroundColour(wxColor(239,239,239));

    x1=15;
    y1=17;
    //plcStaticText1 = new wxStaticText(panelPLC, wxID_ANY, _("PLC数据"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    //plcStaticLine1 = new wxStaticLine(panelPLC, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w1-x1*2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    //x1+=7;
    //y1+=25;
    panelPlcList = new wxPanel(panelPLC, wxID_ANY, wxPoint(x1,y1), wxSize(w1-x1*2,h1-y1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPlcList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    plcList = new wxListView(panelPlcList, wxID_ANY, wxPoint(0,24), wxSize(w1-x1*2,h1-y1-39), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));


    panelDTA = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelDTA->SetBackgroundColour(wxColor(239,239,239));
    x1=15;
    y1=17;

    dtaStaticText2 = new wxStaticText(panelDTA, wxID_ANY, _("起算里程"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    dtaMile1 = new wxMyTextCtrl(panelDTA, wxID_ANY, wxEmptyString, wxPoint(x1+55,y1-5), wxSize(115,25), 0);
    dtaStaticText3 = new wxStaticText(panelDTA, wxID_ANY, _("计算步长"), wxPoint(x1+180,y1), wxDefaultSize, 0, _("wxID_ANY"));
    dtaStep = new wxMyTextCtrl(panelDTA, wxID_ANY, wxEmptyString, wxPoint(x1+235,y1-5), wxSize(115,25), 0);

    panelDtaButton = new wxPanel(panelDTA, wxID_ANY, wxPoint(x1+360,y1-5), wxSize(300,24), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelDtaButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y1+=30;
    panelDtaList = new wxPanel(panelDTA, wxID_ANY, wxPoint(x1,y1), wxSize(w1-x1*2,h1-y1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelDtaList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    dtaList = new wxListView(panelDtaList, wxID_ANY, wxPoint(0,24), wxSize(w1-x1*2,h1-y1-39), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelOriginal = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelOriginal->SetBackgroundColour(wxColor(239,239,239));
    x1=15;
    y1=17;
    w2=115;
    x2=x1;
    y2=y1;
    x2+=75;
    //originalStaticText1 = new wxStaticText(panelOriginal, wxID_ANY, _("初始姿态"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    //originalStaticLine1 = new wxStaticLine(panelOriginal, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w1-x1*2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    //x1+=7;
    //y1+=25;
    panelOriginalFig = new wxPanel(panelOriginal, wxID_ANY, wxPoint(x1,y1), wxSize(w1-x1*2,h1-y1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelOriginalFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelManual = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelManual->SetBackgroundColour(wxColor(239,239,239));
    x1=15;
    y1=9;
    manualStaticText10 = new wxStaticText(panelManual, wxID_ANY, _("测量数据"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    manualStaticLine2 = new wxStaticLine(panelManual, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w1-x1*2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    //x1+=7;
    y1+=20;
    x2=x1;
    y2=y1;
    x2+=65;
    manualStaticText11 = new wxStaticText(panelManual, wxID_ANY, _("X"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=w2;
    manualStaticText12 = new wxStaticText(panelManual, wxID_ANY, _("Y"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=w2;
    manualStaticText13 = new wxStaticText(panelManual, wxID_ANY, _("Z"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=w2;
    manualStaticText23 = new wxStaticText(panelManual, wxID_ANY, _("较差(mm)"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2=x1;
    y2+=30;
    manualStaticText14 = new wxStaticText(panelManual, wxID_ANY, _("1#棱镜"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=65;
    manualPrism1x2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism1y2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism1z2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrismD1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-20,25), 0);
    x2=x2+w2-15;
    panelManualButton = new wxPanel(panelManual, wxID_ANY, wxPoint(x2,y2-5), wxSize(w2-20,90), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelManualButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x1;
    y2+=30;
    manualStaticText15 = new wxStaticText(panelManual, wxID_ANY, _("2#棱镜"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=65;
    manualPrism2x2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism2y2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism2z2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrismD2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-20,25), 0);
    x2=x1;
    y2+=30;
    manualStaticText16 = new wxStaticText(panelManual, wxID_ANY, _("3#棱镜"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=65;
    manualPrism3x2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism3y2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism3z2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrismD3 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-20,25), 0);
    x1=15;
    y1=y2+30;
    manualStaticText17 = new wxStaticText(panelManual, wxID_ANY, _("计算结果"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    manualStaticLine3 = new wxStaticLine(panelManual, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w1-x1*2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    //x1+=7;
    y1+=20;
    x2=x1;
    y2=y1;
    x2+=65;
    manualStaticText18 = new wxStaticText(panelManual, wxID_ANY, _("X"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=w2;
    manualStaticText19 = new wxStaticText(panelManual, wxID_ANY, _("Y"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=w2;
    manualStaticText20 = new wxStaticText(panelManual, wxID_ANY, _("Z"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2=x2+w2;
    manualStaticText23 = new wxStaticText(panelManual, wxID_ANY, _("水平(mm)"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2=x2+w2-15;
    manualStaticText24 = new wxStaticText(panelManual, wxID_ANY, _("垂直(mm)"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2=x1;
    y2+=25;
    manualStaticText21 = new wxStaticText(panelManual, wxID_ANY, _("切口"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=65;
    manualHeadx2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualHeady2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualHeadz2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualHeadh = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-20,25), 0);
    x2=x2+w2-15;
    manualHeadv = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-20,25), 0);
    x2=x1;
    y2+=30;
    manualStaticText22 = new wxStaticText(panelManual, wxID_ANY, _("盾尾"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=65;
    manualTailx2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualTaily2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualTailz2 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualTailh = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-20,25), 0);
    x2=x2+w2-15;
    manualTailv = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-20,25), 0);

    x1=15;
    y1=y2+45;
    manualStaticText1 = new wxStaticText(panelManual, wxID_ANY, _("初始数据"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    manualStaticLine1 = new wxStaticLine(panelManual, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w1-x1*2-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    //x1+=7;
    y1+=20;
    x2=x1;
    y2=y1;
    x2+=65;
    manualStaticText2 = new wxStaticText(panelManual, wxID_ANY, _("X"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=w2;
    manualStaticText3 = new wxStaticText(panelManual, wxID_ANY, _("Y"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=w2;
    manualStaticText4 = new wxStaticText(panelManual, wxID_ANY, _("Z"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2=x1;
    y2+=25;
    manualStaticText5 = new wxStaticText(panelManual, wxID_ANY, _("切口"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=65;
    manualHeadx1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualHeady1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualHeadz1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2=x2+w2;
    panelManualFig = new wxPanel(panelManual, wxID_ANY, wxPoint(x2,y2-5), wxSize(w2*2-35,144), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelManualFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x1;
    y2+=30;
    manualStaticText6 = new wxStaticText(panelManual, wxID_ANY, _("盾尾"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=65;
    manualTailx1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualTaily1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualTailz1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2=x1;
    y2+=30;
    manualStaticText7 = new wxStaticText(panelManual, wxID_ANY, _("1#棱镜"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=65;
    manualPrism1x1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism1y1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism1z1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2=x1;
    y2+=30;
    manualStaticText8 = new wxStaticText(panelManual, wxID_ANY, _("2#棱镜"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=65;
    manualPrism2x1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism2y1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism2z1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2=x1;
    y2+=30;
    manualStaticText9 = new wxStaticText(panelManual, wxID_ANY, _("3#棱镜"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    x2+=65;
    manualPrism3x1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism3y1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);
    x2+=w2;
    manualPrism3z1 = new wxMyTextCtrl(panelManual, wxID_ANY, wxEmptyString, wxPoint(x2,y2-5), wxSize(w2-5,25), 0);

    manualHeadx2->SetEditable(false);
    manualHeady2->SetEditable(false);
    manualHeadz2->SetEditable(false);
    manualHeadh->SetEditable(false);
    manualHeadv->SetEditable(false);
    manualTailx2->SetEditable(false);
    manualTaily2->SetEditable(false);
    manualTailz2->SetEditable(false);
    manualTailh->SetEditable(false);
    manualTailv->SetEditable(false);


    x1=0;
    y1=11;
    w1=w-150;
    h1=h-88;

    panelCircle = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelCircle->SetBackgroundColour(wxColor(239,239,239));

    x1=15;
    y1=17;
    w1=320;
    h1=270;
    panelCircleGrid= new wxPanel(panelCircle, wxID_ANY, wxPoint(x1,y1), wxSize(525,256), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelCircleGrid->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    circleGrid=new wxGrid(panelCircleGrid, wxID_ANY, wxPoint(1,25), wxSize(523,230), 0, _T("wxID_ANY"));

    panelCircleButton=new wxPanel(panelCircle,wxID_ANY,wxPoint(x1+525,y1),wxSize(95,100), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelCircleButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelCircleFig= new wxPanel(panelCircle, wxID_ANY, wxPoint(x1,284), wxSize(525,207), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelCircleFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w-150;
    h1=h-88;

    panelTest = new wxPanel(panelMain, wxID_ANY, wxPoint(w+160,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTest->SetBackgroundColour(wxColor(239,239,239));

    x1=15;
    y1=17;
    w1=w-180;
    h1=h-122;
    testFig= new wxPanel(panelTest, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    testFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelNavi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintBackground,0,this);
	panelNavi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintNavi,0,this);

    panelTpsList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintTpsList,0,this);

    panelTarInc->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintTarInc,0,this);

    panelPlcList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintPlcList,0,this);

    panelDtaList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintDtaList,0,this);

    panelDtaButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintDtaButton,0,this);
    panelDtaButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&CheckUpDlg::OnMotionDtaButton,0,this);
    panelDtaButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&CheckUpDlg::OnLeaveDtaButton,0,this);
    panelDtaButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&CheckUpDlg::OnClickDtaButton,0,this);

    panelOriginalFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintOriginalFig,0,this);

    panelManualButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintManualButton,0,this);
    panelManualButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&CheckUpDlg::OnMotionManualButton,0,this);
    panelManualButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&CheckUpDlg::OnLeaveManualButton,0,this);
    panelManualButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&CheckUpDlg::OnClickManualButton,0,this);

    panelManualFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintManualFig,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&CheckUpDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&CheckUpDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&CheckUpDlg::OnClickBottom,0,this);

    panelButtonList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&CheckUpDlg::OnButtonClick,0,this);

    panelCircleFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintCircleFig,0,this);
    panelCircleButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintCircleButton,0,this);
    panelCircleButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&CheckUpDlg::OnMotionCircleButton,0,this);
    panelCircleButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&CheckUpDlg::OnLeaveCircleButton,0,this);
    panelCircleButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&CheckUpDlg::OnClickCircleButton,0,this);
    panelCircleGrid->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintCircleGrid,0,this);
    circleGrid->Connect(wxEVT_KILL_FOCUS,(wxObjectEventFunction)&CheckUpDlg::OnGridCirDataKillFocus,0,this);

    testFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CheckUpDlg::OnPaintTestFig,0,this);
    testFig->Connect(wxEVT_LEFT_DCLICK,(wxObjectEventFunction)&CheckUpDlg::OnDoubleClickTestFig,0,this);

    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    panelButtonList->btn_height=27;
    panelButtonList->AddButton(_("全站仪"));
    panelButtonList->AddButton(_("激光靶"));
    panelButtonList->AddButton(_("PLC数据"));
    panelButtonList->AddButton(_("隧道中线"));
    panelButtonList->AddButton(_("初始姿态"));
    panelButtonList->AddButton(_("人工姿态"));
    panelButtonList->AddButton(_("洞门中心"));
    panelButtonList->AddButton(_("光斑分析"));
    panelButtonList->btn_clicked=0;

    motion=ID_CHECK_NONE;
    clicked=ID_CHECK_NONE;

    int i=0;
    int j=0;

    wxGridCellAttr* GCA;

    tpsList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,55);
    tpsList->InsertColumn(i++,_("操作"),wxLIST_FORMAT_CENTRE,90);
    tpsList->InsertColumn(i++,_("返回信息"),wxLIST_FORMAT_CENTRE,260);
    tpsList->InsertColumn(i++,_("时间"),wxLIST_FORMAT_CENTRE,150);

    i=0;
    incList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,55);
    incList->InsertColumn(i++,_("转动角"),wxLIST_FORMAT_CENTRE,95);
    incList->InsertColumn(i++,_("俯仰角"),wxLIST_FORMAT_CENTRE,95);
    incList->InsertColumn(i++,_("方位角"),wxLIST_FORMAT_CENTRE,95);
    //incList->InsertColumn(i++,_("时间"),wxLIST_FORMAT_CENTRE,180);

    i=0;
    plcList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    plcList->InsertColumn(i++,_("数据项"),wxLIST_FORMAT_LEFT,150);
    plcList->InsertColumn(i++,_("值"),wxLIST_FORMAT_CENTRE,95);
    j=0;
    plcList->InsertItem(j,_("01"));
    plcList->SetItem(j++,1,_("掘进状态"));
    plcList->InsertItem(j,_("02"));
    plcList->SetItem(j++,1,_("拼装状态"));
    plcList->InsertItem(j,_("03"));
    plcList->SetItem(j++,1,_("推进油缸：上"));
    plcList->InsertItem(j,_("04"));
    plcList->SetItem(j++,1,_("推进油缸：下"));
    plcList->InsertItem(j,_("05"));
    plcList->SetItem(j++,1,_("推进油缸：左"));
    plcList->InsertItem(j,_("06"));
    plcList->SetItem(j++,1,_("推进油缸：右"));
    plcList->InsertItem(j,_("07"));
    plcList->SetItem(j++,1,_("铰接油缸：上"));
    plcList->InsertItem(j,_("08"));
    plcList->SetItem(j++,1,_("铰接油缸：下"));
    plcList->InsertItem(j,_("09"));
    plcList->SetItem(j++,1,_("铰接油缸：左"));
    plcList->InsertItem(j,_("10"));
    plcList->SetItem(j++,1,_("铰接油缸：右"));

    i=0;
    dtaList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_RIGHT,60);
    dtaList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_RIGHT,90);
    dtaList->InsertColumn(i++,_("X"),wxLIST_FORMAT_RIGHT,90);
    dtaList->InsertColumn(i++,_("Y"),wxLIST_FORMAT_RIGHT,90);
    dtaList->InsertColumn(i++,_("Z"),wxLIST_FORMAT_RIGHT,85);
    dtaList->InsertColumn(i++,_("水平偏差"),wxLIST_FORMAT_RIGHT,70);
    dtaList->InsertColumn(i++,_("高程偏差"),wxLIST_FORMAT_RIGHT,70);

	circleGrid->CreateGrid( 1, 7 );
	circleGrid->EnableGridLines( true );
	circleGrid->EnableDragGridSize( false );

	circleGrid->EnableDragColMove( false );
	circleGrid->EnableDragColSize( false );
	circleGrid->SetColLabelSize( 0 );

	circleGrid->EnableDragRowSize( false );
	circleGrid->SetRowLabelSize( 0 );
	circleGrid->SetDefaultRowSize(23);
    //circleGrid->SetSelectionMode(wxGrid::wxGridSelectRows);
	circleGrid->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	//circleGrid->EnableGridLines(false);
    i=0;
	circleGrid->SetColSize(i++,55);       ///序号
	circleGrid->SetColSize(i++,95);       ///X
	circleGrid->SetColSize(i++,95);       ///Y
	circleGrid->SetColSize(i++,75);       ///Z
	circleGrid->SetColSize(i++,45);       ///选取
	circleGrid->SetColSize(i++,60);       ///平面度
	circleGrid->SetColSize(i++,60);       ///圆度

	GCA = new wxGridCellAttr;
    wxGridCellBoolEditor* GCCE = new wxGridCellBoolEditor;
    wxGridCellBoolRenderer* GCBR = new wxGridCellBoolRenderer;
    GCA->SetEditor(GCCE);
    GCA->SetRenderer(GCBR);

    circleGrid->SetColAttr(4,GCA);
    GCA = new wxGridCellAttr;
    GCA->SetReadOnly();
    circleGrid->SetColAttr(5,GCA);
    circleGrid->SetColAttr(6,GCA);
    x0=y0=z0=l=ho=vo=0.0;

    ok=1;
    LoadData();
    CCircleFit();
    manualHeadx1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualHeady1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualHeadz1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualTailx1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualTaily1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualTailz1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualPrism1x1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualPrism1y1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualPrism1z1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualPrism2x1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualPrism2y1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualPrism2z1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualPrism3x1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualPrism3y1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
    manualPrism3z1->Connect(wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckUpDlg::OnUpdateManual,NULL,this);
}

CheckUpDlg::~CheckUpDlg()
{

}

void CheckUpDlg::OnButtonClick(wxMouseEvent& event)
{
    int btn = panelButtonList->btn_left_down;
    int w,h;
    panelTps->GetClientSize(&w,&h);

    switch(btn)
    {
    case 0:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelTars->SetSize(1024,11,w,h);
        panelPLC->SetSize(1024,11,w,h);
        panelDTA->SetSize(1024,11,w,h);
        panelOriginal->SetSize(1024,11,w,h);
        panelManual->SetSize(1024,11,w,h);
        panelCircle->SetSize(1024,11,w,h);
        panelTest->SetSize(1024,11,w,h);
        panelTps->SetSize(0,11,w,h);
        clicked=ID_CHECK_NONE;
        break;
    case 1:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelTps->SetSize(1024,11,w,h);
        panelPLC->SetSize(1024,11,w,h);
        panelDTA->SetSize(1024,11,w,h);
        panelOriginal->SetSize(1024,11,w,h);
        panelManual->SetSize(1024,11,w,h);
        panelCircle->SetSize(1024,11,w,h);
        panelTest->SetSize(1024,11,w,h);
        panelTars->SetSize(0,11,w,h);
        clicked=ID_CHECK_NONE;
        break;
    case 2:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelTars->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelDTA->SetSize(1024,11,w,h);
        panelOriginal->SetSize(1024,11,w,h);
        panelManual->SetSize(1024,11,w,h);
        panelCircle->SetSize(1024,11,w,h);
        panelTest->SetSize(1024,11,w,h);
        panelPLC->SetSize(0,11,w,h);
        clicked=ID_CHECK_NONE;
        break;
    case 3:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelTars->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelPLC->SetSize(1024,11,w,h);
        panelOriginal->SetSize(1024,11,w,h);
        panelManual->SetSize(1024,11,w,h);
        panelCircle->SetSize(1024,11,w,h);
        panelTest->SetSize(1024,11,w,h);
        panelDTA->SetSize(0,11,w,h);
        break;
    case 4:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelTars->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelPLC->SetSize(1024,11,w,h);
        panelDTA->SetSize(1024,11,w,h);
        panelManual->SetSize(1024,11,w,h);
        panelCircle->SetSize(1024,11,w,h);
        panelTest->SetSize(1024,11,w,h);
        panelOriginal->SetSize(0,11,w,h);
        clicked=ID_CHECK_NONE;
        break;
    case 5:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelTars->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelPLC->SetSize(1024,11,w,h);
        panelDTA->SetSize(1024,11,w,h);
        panelOriginal->SetSize(1024,11,w,h);
        panelCircle->SetSize(1024,11,w,h);
        panelTest->SetSize(1024,11,w,h);
        panelManual->SetSize(0,11,w,h);
        panelManualFig->Refresh();
        clicked=ID_CHECK_NONE;
        break;
    case 6:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelTars->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelPLC->SetSize(1024,11,w,h);
        panelDTA->SetSize(1024,11,w,h);
        panelOriginal->SetSize(1024,11,w,h);
        panelManual->SetSize(1024,11,w,h);
        panelTest->SetSize(1024,11,w,h);
        panelCircle->SetSize(0,11,w,h);
        clicked=ID_CHECK_NONE;
        break;
    case 7:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelTars->SetSize(1024,11,w,h);
        panelTps->SetSize(1024,11,w,h);
        panelPLC->SetSize(1024,11,w,h);
        panelDTA->SetSize(1024,11,w,h);
        panelOriginal->SetSize(1024,11,w,h);
        panelManual->SetSize(1024,11,w,h);
        panelCircle->SetSize(1024,11,w,h);
        panelTest->SetSize(0,11,w,h);
        clicked=ID_CHECK_NONE;
        break;
    default:
        break;
    }
}


void CheckUpDlg::OnPaintTpsList(wxPaintEvent& event)
{
    wxPaintDC dc(panelTpsList);
    int w,h;
    panelTpsList->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;

        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=tpsList->GetColumnWidth(0);
        //w1=tpsInfoGrid->GetColSize(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=tpsList->GetColumnWidth(1);
        //w1=tpsInfoGrid->GetColSize(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("操作"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=tpsList->GetColumnWidth(2);
        //w1=tpsInfoGrid->GetColSize(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("返回信息"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=tpsList->GetColumnWidth(3);
        //w1=tpsInfoGrid->GetColSize(3);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=tpsList->GetColumnWidth(4);
        //w1=tpsInfoGrid->GetColSize(4);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        x1=1;
        w1=tpsList->GetColumnWidth(0);
        //w1=tpsInfoGrid->GetColSize(0);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=tpsList->GetColumnWidth(1);
        //w1=tpsInfoGrid->GetColSize(1);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=tpsList->GetColumnWidth(2);
        //w1=tpsInfoGrid->GetColSize(2);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=tpsList->GetColumnWidth(3);
        //w1=tpsInfoGrid->GetColSize(3);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=tpsList->GetColumnWidth(4);
        //w1=tpsInfoGrid->GetColSize(4);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,w-1,y1+1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void CheckUpDlg::OnPaintTarInc(wxPaintEvent& event)
{
    wxPaintDC dc(panelTarInc);
    int w,h;
    panelTarInc->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;

        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=incList->GetColumnWidth(0);
        //w1=incGrid->GetColSize(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList->GetColumnWidth(1);
        //w1=incGrid->GetColSize(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("转动角(°)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList->GetColumnWidth(2);
        //w1=incGrid->GetColSize(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("俯仰角(°)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList->GetColumnWidth(3);
        //w1=incGrid->GetColSize(3);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("方位角(°)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=incList->GetColumnWidth(4);
        //memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        //memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //x1+=w1;
        //w1=incList->GetColumnWidth(5);
        //w1=incGrid->GetColSize(4);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        x1=1;
        w1=incList->GetColumnWidth(0);
        //w1=incGrid->GetColSize(0);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=incList->GetColumnWidth(1);
        //w1=incGrid->GetColSize(1);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=incList->GetColumnWidth(2);
        //w1=incGrid->GetColSize(2);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=incList->GetColumnWidth(3);
        //w1=incGrid->GetColSize(3);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=incList->GetColumnWidth(4);
        //w1=incGrid->GetColSize(4);
        //memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        //memDC.DrawLine(x1,y1+1,w-1,y1+1);
        //x1+=w1;
        //w1=incList->GetColumnWidth(5);
        //w1=incGrid->GetColSize(4);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,w-1,y1+1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void CheckUpDlg::OnPaintPlcList(wxPaintEvent& event)
{
    wxPaintDC dc(panelPlcList);
    int w,h;
    panelPlcList->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;

        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=plcList->GetColumnWidth(0);
        //w1=plcGrid->GetColSize(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=plcList->GetColumnWidth(1);
        //w1=plcGrid->GetColSize(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("数据项"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=plcList->GetColumnWidth(2);
        //w1=plcGrid->GetColSize(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("值"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=plcList->GetColumnWidth(3);
        //w1=plcGrid->GetColSize(3);
        //memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        //memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //x1+=w1;
        //w1=plcGrid->GetColSize(4);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        x1=1;
        w1=plcList->GetColumnWidth(0);
        //w1=plcGrid->GetColSize(0);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=plcList->GetColumnWidth(1);
        //w1=plcGrid->GetColSize(1);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=plcList->GetColumnWidth(2);
        //w1=plcGrid->GetColSize(2);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=plcList->GetColumnWidth(3);
        //w1=plcGrid->GetColSize(3);
        //memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        //memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        //x1+=w1;
        //w1=plcGrid->GetColSize(4);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,w-1,y1+1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void CheckUpDlg::OnPaintDtaList(wxPaintEvent& event)
{
    wxPaintDC dc(panelDtaList);
    int w,h;
    panelDtaList->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;

        int x2,y2;

        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=dtaList->GetColumnWidth(0);
        //w1=dtaGrid->GetColSize(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=dtaList->GetColumnWidth(1);
        //w1=dtaGrid->GetColSize(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=dtaList->GetColumnWidth(2);
        //w1=dtaGrid->GetColSize(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("X"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=dtaList->GetColumnWidth(3);
        //w1=dtaGrid->GetColSize(3);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("Y"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=dtaList->GetColumnWidth(4);
        //w1=dtaGrid->GetColSize(4);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("Z"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=dtaList->GetColumnWidth(5);
        //w1=dtaGrid->GetColSize(5);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("水平偏差"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=dtaList->GetColumnWidth(6);
        //w1=dtaGrid->GetColSize(6);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("垂直偏差"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        x1=1;
        w1=dtaList->GetColumnWidth(0);
        //w1=dtaGrid->GetColSize(0);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=dtaList->GetColumnWidth(1);
        //w1=dtaGrid->GetColSize(1);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=dtaList->GetColumnWidth(2);
        //w1=dtaGrid->GetColSize(2);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=dtaList->GetColumnWidth(3);
        //w1=dtaGrid->GetColSize(3);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=dtaList->GetColumnWidth(4);
        //w1=dtaGrid->GetColSize(4);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=dtaList->GetColumnWidth(5);
        //w1=dtaGrid->GetColSize(5);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=dtaList->GetColumnWidth(6);
        //w1=dtaGrid->GetColSize(6);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void CheckUpDlg::OnPaintDtaButton(wxPaintEvent& event)
{
    wxPaintDC dc(panelDtaButton);
    int w,h;
    panelDtaButton->GetClientSize(&w,&h);
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
        int w1=62;
        int h1=h;

        checkButton[ID_CHECK_DTA_CAL].x=x1;
        checkButton[ID_CHECK_DTA_CAL].y=y1;
        checkButton[ID_CHECK_DTA_CAL].width=w1;
        checkButton[ID_CHECK_DTA_CAL].height=h1;

        if(motion==ID_CHECK_DTA_CAL)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("计算"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+5;
        checkButton[ID_CHECK_DTA_CHECK].x=x1;
        checkButton[ID_CHECK_DTA_CHECK].y=y1;
        checkButton[ID_CHECK_DTA_CHECK].width=w1;
        checkButton[ID_CHECK_DTA_CHECK].height=h1;

        if(motion==ID_CHECK_DTA_CHECK)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("复核"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+5;
        checkButton[ID_CHECK_DTA_EMPORT].x=x1;
        checkButton[ID_CHECK_DTA_EMPORT].y=y1;
        checkButton[ID_CHECK_DTA_EMPORT].width=w1;
        checkButton[ID_CHECK_DTA_EMPORT].height=h1;

        if(motion==ID_CHECK_DTA_EMPORT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[1]);
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

void CheckUpDlg::OnMotionDtaButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>checkButton[ID_CHECK_DTA_CAL].y && y<checkButton[ID_CHECK_DTA_CAL].y+checkButton[ID_CHECK_DTA_CAL].height)
    {
        if(x>checkButton[ID_CHECK_DTA_CAL].x && x<checkButton[ID_CHECK_DTA_CAL].x+checkButton[ID_CHECK_DTA_CAL].width)
        {
            motion=ID_CHECK_DTA_CAL;
        }
        else if(x>checkButton[ID_CHECK_DTA_CHECK].x && x<checkButton[ID_CHECK_DTA_CHECK].x+checkButton[ID_CHECK_DTA_CHECK].width)
        {
            motion=ID_CHECK_DTA_CHECK;
        }
        else if(x>checkButton[ID_CHECK_DTA_EMPORT].x && x<checkButton[ID_CHECK_DTA_EMPORT].x+checkButton[ID_CHECK_DTA_EMPORT].width)
        {
            motion=ID_CHECK_DTA_EMPORT;
        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    else
    {
        motion=ID_CHECK_NONE;
    }

    panelDtaButton->Refresh();
}

void CheckUpDlg::OnLeaveDtaButton(wxMouseEvent& event)
{
    motion=ID_CHECK_NONE;
    panelDtaButton->Refresh();
}

void CheckUpDlg::OnClickDtaButton(wxMouseEvent& event)
{
    if(motion==ID_CHECK_DTA_CAL)
    {
        motion1=ID_CHECK_DTA_CAL;
        double val,mile,step;
        int Er=0;
        if(dtaMile1->GetValue().ToDouble(&val))
        {
            mile=val;
        }
        else
        {
            wxMessageBox(_("起算里程输入有误"),_("逐桩坐标计算"),wxOK);
            return;
        }
        if(dtaStep->GetValue().ToDouble(&val))
        {
            step=val;
            if(fabs(step)<=0)
            {
                wxMessageBox(_("步长输入有误"),_("逐桩坐标计算"),wxOK);
                return;
            }
        }
        else
        {
            wxMessageBox(_("步长输入有误"),_("逐桩坐标计算"),wxOK);
            return;
        }

        if(cli->prj.dta==0)
        {
            int nh,nv;
            nh=road_number_horizon(&cli->r);
            nv=road_number_vertical(&cli->r);
            if(nh<=2&&nv<=2)
            {
                wxMessageBox(_("中线数据未输入！"),_("逐桩坐标计算"),wxOK);
                return;
            }
            else
            {
                coord_cal(mile,step);
            }
        }
        else
        {
            int nh=cli->nRoad;
             if(nh<=2)
            {
                wxMessageBox(_("中线数据未输入！"),_("逐桩坐标计算"),wxOK);
                return;
            }
            else
            {
                coord_cal(mile,step);
            }
        }
    }
    else if(motion==ID_CHECK_DTA_CHECK)
    {
        motion1=ID_CHECK_DTA_CHECK;
        coord_check();
    }
    else if(motion==ID_CHECK_DTA_EMPORT)
    {
        if(cal_coord)
        {
            coord_export();
        }
    }
    panelDtaButton->Refresh();
}

void CheckUpDlg::OnPaintOriginalFig(wxPaintEvent& event)
{
    wxPaintDC dc(panelOriginalFig);
    int w,h;
    panelOriginalFig->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    cli->m=cli->m0;

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

        int x1,y1,w1,h1;
        x1=28;
        y1=28;
        w1=w-x1*2;
        h1=h-y1*2;
        int x2,y2,w2,h2;
        x2=x1;
        y2=y1;
        w2=w1/2-15;
        h2=h1/2-15;
        memDC.SetPen(wxPen(wxColor(189,189,189)));
        memDC.SetBrush(wxBrush(wxColor(189,189,189)));
        memDC.DrawRoundedRectangle(x2,y2,w2,h2,3);

        int R;
        R=w2>h2?h2:w2;
        R=R*2/5;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawCircle(x2+w2/2,y2+h2/2,R);

        double tbm[9];
        double laser[9];
        if(cli->m0.t1<=0)
        {
            tbm[0]=82804.3411;
            tbm[1]=79102.9331;
            tbm[2]=-7.9701;
            tbm[3]=82809.0781;
            tbm[4]=79101.6739;
            tbm[5]=-7.9532;
            laser[0]=82807.9431;
            laser[1]=79100.3172;
            laser[2]=-6.2956;
            laser[3]=2.881779;
            laser[4]=-0.0169;
            laser[5]=-0.017453293;
        }
        else
        {
            if(cli->tbm.type==0)
            {
                tbm[0]=cli->m0.head[0];
                tbm[1]=cli->m0.head[1];
                tbm[2]=cli->m0.head[2];
                tbm[3]=cli->m0.tail[0];
                tbm[4]=cli->m0.tail[1];
                tbm[5]=cli->m0.tail[2];
            }
            else if(cli->tbm.type==1)
            {
                tbm[0]=cli->m0.head[0];
                tbm[1]=cli->m0.head[1];
                tbm[2]=cli->m0.head[2];
                tbm[3]=cli->m0.mid[0];
                tbm[4]=cli->m0.mid[1];
                tbm[5]=cli->m0.mid[2];
            }
            else if(cli->tbm.type==2)
            {
                tbm[0]=cli->m0.mid[0];
                tbm[1]=cli->m0.mid[1];
                tbm[2]=cli->m0.mid[2];
                tbm[3]=cli->m0.tail[0];
                tbm[4]=cli->m0.tail[1];
                tbm[5]=cli->m0.tail[2];
            }
            laser[0]=cli->m0.prism[0];
            laser[1]=cli->m0.prism[1];
            laser[2]=cli->m0.prism[2];
            laser[3]=cli->azi[0];
            laser[4]=cli->azi[1];
            laser[5]=cli->azi[2];
        }


        tbm[6]=atan2(tbm[1]-tbm[4],tbm[0]-tbm[3]);
        if(tbm[6]<0) tbm[6]+=2.0*PI;
        tbm[7]=cli->m0.roll;

        double L[7];

        //TBM长度
        L[0]=(tbm[0]-tbm[3])*(tbm[0]-tbm[3])+(tbm[1]-tbm[4])*(tbm[1]-tbm[4])+(tbm[2]-tbm[5])*(tbm[2]-tbm[5]);
        L[0]=sqrt(L[0]);
        //TBM头-激光靶距离
        L[1]=(tbm[0]-laser[0])*(tbm[0]-laser[0])+(tbm[1]-laser[1])*(tbm[1]-laser[1])+(tbm[2]-laser[2])*(tbm[2]-laser[2]);
        L[1]=sqrt(L[1]);
        //TBM尾-激光靶距离
        L[2]=(tbm[3]-laser[0])*(tbm[3]-laser[0])+(tbm[4]-laser[1])*(tbm[4]-laser[1])+(tbm[5]-laser[2])*(tbm[5]-laser[2]);
        L[2]=sqrt(L[2]);
        //TBM俯仰角
        tbm[8]=(tbm[2]-tbm[5])/(L[0]+0.0000000001);
        tbm[8]=asin(tbm[8]);

        double p=L[0]*L[0]+L[1]*L[1]-L[2]*L[2];
        p=p/2/(L[0]+0.0000000001)/(L[1]+0.0000000001);
        //TBM尾-激光靶距离投影至TBM轴线的长度
        L[3]=L[1]*p;

        //memDC.DrawLabel(wxString::Format(_("%.4f"),tbm[6]),wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        double dx,dy,dz;
        dx=(tbm[3]-tbm[0])/(L[0]+0.0000000001);
        dy=(tbm[4]-tbm[1])/(L[0]+0.0000000001);
        dz=(tbm[5]-tbm[2])/(L[0]+0.0000000001);
        //激光靶投影至TBM轴线的点
        laser[6]=tbm[0]+L[3]*dx;
        laser[7]=tbm[1]+L[3]*dy;
        laser[8]=tbm[2]+L[3]*dz;
        //memDC.DrawLabel(wxString::Format(_("%.4f"),laser[8]),wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        //激光靶-TBM轴线的高差
        L[4]=laser[2]-laser[8];
        //TBM轴线-激光靶的距离
        L[5]=(laser[6]-laser[0])*(laser[6]-laser[0])+(laser[7]-laser[1])*(laser[7]-laser[1]);
        L[5]=sqrt(L[5]);
        //TBM轴线-激光靶水平距离
        L[6]=L[5]*L[5]-L[4]*L[4];
        L[6]=sqrt(L[6]);

        int e1,e2;
        double t2t=atan2(laser[1]-tbm[4],laser[0]-tbm[3]);
        if(t2t<0) t2t+=2.0*PI;
        t2t=t2t-tbm[6];
        if(t2t<0.0) t2t+=2.0*PI;
        if(t2t<=180)
        {
            e1=1;
        }
        else
        {
            e1=-1;
        }

        if(L[4]>0)
        {
            e2=1;
        }
        else
        {
            e2=-1;
        }

        double s=6.3/R/2;
        double PL[7];
        PL[4]=L[4]/s;
        PL[5]=L[5]/s;
        PL[6]=L[6]/s;

        int px[3];
        int py[3];
        wxPoint marks[7];

        px[0]=px[1]=x2+w2/2;
        py[0]=py[1]=y2+h2/2;
        px[2]=px[0]+PL[5]*e1;
        py[2]=py[0]-PL[4];

        memDC.SetPen(wxPen(wxColor(20,20,20),1,wxDOT_DASH));
        memDC.DrawLine(px[0]-R-10,py[0],px[0]+R+10,py[0]);
        memDC.DrawLine(px[0],py[0]-R-10,px[0],py[0]+R+10);

        memDC.SetPen(wxPen(wxColor(255,20,20)));
        memDC.SetBrush(wxBrush(wxColor(189,189,189)));
        memDC.DrawRoundedRectangle(px[2]-10,py[2]-8,20,16,2);

        marks[0].x=px[0];
        marks[0].y=py[2]-9*e2;
        marks[1].x=px[0]+2*e1;
        marks[1].y=py[2]-13*e2;
        marks[2].x=px[0]+PL[5]*e1/2-2*e1;
        marks[2].y=py[2]-13*e2;
        marks[3].x=px[0]+PL[5]*e1/2;
        marks[3].y=py[2]-15*e2;
        marks[4].x=px[0]+PL[5]*e1/2+2*e1;
        marks[4].y=py[2]-13*e2;
        marks[5].x=px[2]-2*e1;
        marks[5].y=py[2]-13*e2;
        marks[6].x=px[2];
        marks[6].y=py[2]-9*e2;
        memDC.SetPen(wxPen(wxColor(20,20,255)));
        memDC.DrawLines(7,marks);
        memDC.SetTextForeground(wxColor(20,20,255));
        memDC.DrawLabel(_("D"),wxRect(marks[4].x,marks[4].y-15*e2,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("D  ")+wxString::Format(_("%.3f"),L[5]),wxRect(x2+9,y2+h2-30,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        marks[0].x=px[2]+e1*9;
        marks[0].y=py[2];
        marks[1].x=px[2]+13*e1;
        marks[1].y=py[2]+2*e2;
        marks[2].x=px[2]+13*e1;
        marks[2].y=py[2]+PL[4]/2-2*e2;
        marks[3].x=px[2]+15*e1;
        marks[3].y=py[2]+PL[4]/2;
        marks[4].x=px[2]+13*e1;
        marks[4].y=py[2]+PL[4]/2+2*e2;
        marks[5].x=px[2]+13*e1;
        marks[5].y=py[0]-2*e2;
        marks[6].x=px[2]+e1*9;;
        marks[6].y=py[0];
        memDC.SetPen(wxPen(wxColor(20,20,255)));
        memDC.DrawLines(7,marks);
        memDC.SetTextForeground(wxColor(20,20,255));
        if(e1>0)
        {
            memDC.DrawLabel(_("H"),wxRect(marks[4].x+5,marks[4].y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("H"),wxRect(marks[4].x-5,marks[4].y,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        memDC.DrawLabel(_("H  ")+wxString::Format(_("%.3f"),L[4]),wxRect(x2+9,y2+h2-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x2=x1+w2+28;
        y2=y1;
        memDC.SetPen(wxPen(wxColor(189,189,189)));
        memDC.SetBrush(wxBrush(wxColor(189,189,189)));
        memDC.DrawRoundedRectangle(x2,y2,w2,h2,3);
        if(L[0]>L[3])
        {
            s=L[0]/R/2;
            PL[0]=L[0]/s;
            PL[1]=L[1]/s;
            PL[2]=L[2]/s;
            PL[3]=L[3]/s;
            px[0]=x2+w2/2;
            py[0]=y2+h2/2-PL[0]/2;
            px[1]=px[0];
            py[1]=y2+h2/2+PL[0]/2;
        }
        else
        {
            s=L[3]/R/2;
            PL[0]=L[0]/s;
            PL[1]=L[1]/s;
            PL[2]=L[2]/s;
            PL[3]=L[3]/s;
            px[0]=x2+w2/2;
            py[0]=y2+h2/2-PL[0]/2;
            px[1]=px[0];
            py[1]=y2+h2/2+PL[0]/2;
        }
        px[2]=px[0]+PL[5]*e1;
        py[2]=py[0]+PL[3];

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawRectangle(px[0]-R,py[0],R*2,PL[0]);

        memDC.SetPen(wxPen(wxColor(20,20,20),1,wxDOT_DASH ));
        memDC.DrawLine(px[0],py[0]-10,px[1],py[1]+10);

        marks[0].x=px[2]+e1*9;
        marks[0].y=py[2];
        marks[1].x=px[2]+13*e1;
        marks[1].y=py[2]-2*e2;
        marks[2].x=px[2]+13*e1;
        marks[2].y=py[2]-PL[3]/2+2*e2;
        marks[3].x=px[2]+15*e1;
        marks[3].y=py[2]-PL[3]/2;
        marks[4].x=px[2]+13*e1;
        marks[4].y=py[2]-PL[3]/2-2*e2;
        marks[5].x=px[2]+13*e1;
        marks[5].y=py[0]+2*e2;
        marks[6].x=px[2]+e1*9;;
        marks[6].y=py[0];
        memDC.SetPen(wxPen(wxColor(20,20,255)));
        memDC.DrawLines(7,marks);
        if(e1>0)
        {
            memDC.DrawLabel(_("L'"),wxRect(marks[3].x+5,marks[3].y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("L'"),wxRect(marks[3].x-5,marks[3].y,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        memDC.DrawLabel(_("L  ")+wxString::Format(_("%.3f"),L[0]),wxRect(x2+9,y2+h2-30,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        marks[0].x=px[1]-e1*9;
        marks[0].y=py[1];
        marks[1].x=px[1]-13*e1;
        marks[1].y=py[1]-2*e2;
        marks[2].x=px[1]-13*e1;
        marks[2].y=py[1]-PL[0]/2+2*e2;
        marks[3].x=px[1]-15*e1;
        marks[3].y=py[1]-PL[0]/2;
        marks[4].x=px[1]-13*e1;
        marks[4].y=py[1]-PL[0]/2-2*e2;
        marks[5].x=px[1]-13*e1;
        marks[5].y=py[0]+2*e2;
        marks[6].x=px[1]-e1*9;
        marks[6].y=py[0];
        memDC.SetPen(wxPen(wxColor(20,20,255)));
        memDC.DrawLines(7,marks);
        if(e1>0)
        {
            memDC.DrawLabel(_("L"),wxRect(marks[3].x-5,marks[3].y,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("L"),wxRect(marks[3].x+5,marks[3].y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        memDC.DrawLabel(_("L' ")+wxString::Format(_("%.3f"),L[3]),wxRect(x2+9,y2+h2-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(255,20,20)));
        memDC.DrawRectangle(px[2]-10,py[2]-30,20,30);

        int du,fen;
        double miao;
        double val=tbm[6]*180/PI;
        wxString str[3];

        x2=x1;
        y2=y1+h2+30;
        memDC.SetPen(wxPen(wxColor(189,189,189)));
        memDC.SetBrush(wxBrush(wxColor(189,189,189)));
        memDC.DrawRoundedRectangle(x2,y2,w2,h2,3);

        px[0]=px[0]-w2-28;
        py[0]=py[0]+h2+30;
        px[1]=px[1]-w2-28;
        py[1]=py[1]+h2+30;
        px[2]=px[2]-w2-28;
        py[2]=py[2]+h2+30;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawRectangle(px[0]-R,py[0],R*2,PL[0]);
        memDC.SetPen(wxPen(wxColor(20,20,20),1,wxDOT_DASH ));
        memDC.DrawLine(px[0],py[0]-10,px[1],py[1]+10);

        memDC.SetPen(wxPen(wxColor(255,20,20)));
        memDC.DrawRectangle(px[2]-10,py[2]-30,20,30);
        memDC.SetPen(wxPen(wxColor(255,20,20),1,wxDOT_DASH ));
        memDC.DrawLine(px[2],py[2]-40,px[2],py[2]+10);

        if(e1>0)
        {
            memDC.DrawLabel(_("α"),wxRect(px[0]-5,(py[0]+py[1])/2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("α'"),wxRect(px[2]+15,py[2]-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("α"),wxRect(px[0]+5,(py[0]+py[1])/2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("α'"),wxRect(px[2]-15,py[2]-15,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }

        du=val;
        fen=(val-du)*60;
        miao=val-du-fen/60;
        str[0]=wxString::Format(_("%d"),du)+_("°");
        if(fen<10)
        {
            str[1]=_("0")+wxString::Format(_("%d"),fen)+_("′");
        }
        else
        {
            str[1]=wxString::Format(_("%d"),fen)+_("′");
        }
        if(miao<10)
        {
            str[2]=_("0")+wxString::Format(_("%.1f"),miao)+_("″");
        }
        else
        {
            str[2]=wxString::Format(_("%.1f"),miao)+_("″");
        }

        memDC.DrawLabel(_("α  ")+str[0]+str[1]+str[2],wxRect(x2+9,y2+h2-30,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        val=laser[3]*180/PI;
        du=val;
        fen=(val-du)*60;
        miao=val-du-fen/60;
        str[0]=wxString::Format(_("%d"),du)+_("°");
        if(fen<10)
        {
            str[1]=_("0")+wxString::Format(_("%d"),fen)+_("′");
        }
        else
        {
            str[1]=wxString::Format(_("%d"),fen)+_("′");
        }
        if(miao<10)
        {
            str[2]=_("0")+wxString::Format(_("%.1f"),miao)+_("″");
        }
        else
        {
            str[2]=wxString::Format(_("%.1f"),miao)+_("″");
        }
        //memDC.DrawLabel(_("激光靶"),wxRect(x2+15,y2+h2/2+40+25,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("α' ")+str[0]+str[1]+str[2],wxRect(x2+9,y2+h2-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        int px1[3],py1[3];
        px1[0]=px[0]-x2-w2/2;
        py1[0]=py[0]-y2-h2/2;
        px1[1]=px[1]-x2-w2/2;
        py1[1]=py[1]-y2-h2/2;
        px1[2]=px[2]-x2-w2/2;
        py1[2]=py[2]-y2-h2/2;

        x2=x1+w2+28;
        y2=y1+h2+30;
        memDC.SetPen(wxPen(wxColor(189,189,189)));
        memDC.SetBrush(wxBrush(wxColor(189,189,189)));
        memDC.DrawRoundedRectangle(x2,y2,w2,h2,3);

        px[0]=x2+w2/2-py1[0];
        py[0]=y2+h2/2-px1[0];
        px[1]=x2+w2/2-py1[1];
        py[1]=y2+h2/2-px1[1];
        px[2]=x2+w2/2-py1[2];
        py[2]=y2+h2/2-PL[4];

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawRectangle(px[1],py[1]-R,PL[0],R*2);
        memDC.SetPen(wxPen(wxColor(20,20,20),1,wxDOT_DASH ));
        memDC.DrawLine(px[1]-10,py[1],px[0]+10,py[0]);

        memDC.SetPen(wxPen(wxColor(255,20,20)));
        memDC.DrawRectangle(px[2],py[2]-10,30,20);
        memDC.SetPen(wxPen(wxColor(255,20,20),1,wxDOT_DASH ));
        memDC.DrawLine(px[2]-10,py[2],px[2]+40,py[2]);

        if(e2>0)
        {
            memDC.DrawLabel(_("β"),wxRect(px[1],py[1]+5,PL[0],0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
            memDC.DrawLabel(_("β'"),wxRect(px[2],py[2]-15,30,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
        }
        else
        {
            memDC.DrawLabel(_("β"),wxRect(px[1],py[1]-5,PL[0],0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
            memDC.DrawLabel(_("β'"),wxRect(px[2],py[2]+15,30,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        }
        val=tan(tbm[8])*1000.0;
        memDC.DrawLabel(_("β  ")+wxString::Format(_("%.3f‰"),val),wxRect(x2+9,y2+h2-30,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        val=tan(laser[5])*1000.0;
        memDC.DrawLabel(_("β' ")+wxString::Format(_("%.3f‰"),val),wxRect(x2+9,y2+h2-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void CheckUpDlg::OnPaintManualButton(wxPaintEvent& event)
{
    wxPaintDC dc(panelManualButton);
    int w,h;
    panelManualButton->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(239,239,239)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);

        int x1,y1,w1,h1;
        w1=65;
        h1=24;
        x1=w-w1-10;
        y1=0;

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        checkButton[ID_CHECK_MANUAL_CAL].x=x1;
        checkButton[ID_CHECK_MANUAL_CAL].y=y1;
        checkButton[ID_CHECK_MANUAL_CAL].width=w1;
        checkButton[ID_CHECK_MANUAL_CAL].height=h1;
        if(motion==ID_CHECK_MANUAL_CAL)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("计算"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+7;
        checkButton[ID_CHECK_MANUAL_AUTO].x=x1;
        checkButton[ID_CHECK_MANUAL_AUTO].y=y1;
        checkButton[ID_CHECK_MANUAL_AUTO].width=w1;
        checkButton[ID_CHECK_MANUAL_AUTO].height=h1;
        if(motion==ID_CHECK_MANUAL_AUTO)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("自动"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+7;
        checkButton[ID_CHECK_MANUAL_EMPORT].x=x1;
        checkButton[ID_CHECK_MANUAL_EMPORT].y=y1;
        checkButton[ID_CHECK_MANUAL_EMPORT].width=w1;
        checkButton[ID_CHECK_MANUAL_EMPORT].height=h1;
        if(motion==ID_CHECK_MANUAL_EMPORT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[1]);
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

void CheckUpDlg::OnMotionManualButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>checkButton[ID_CHECK_MANUAL_CAL].y && y<checkButton[ID_CHECK_MANUAL_CAL].y+checkButton[ID_CHECK_MANUAL_CAL].height)
    {
        if(x>checkButton[ID_CHECK_MANUAL_CAL].x && x<checkButton[ID_CHECK_MANUAL_CAL].x+checkButton[ID_CHECK_MANUAL_CAL].width)
        {
            motion=ID_CHECK_MANUAL_CAL;
        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    else if(y>checkButton[ID_CHECK_MANUAL_AUTO].y && y<checkButton[ID_CHECK_MANUAL_AUTO].y+checkButton[ID_CHECK_MANUAL_AUTO].height)
    {
        if(x>checkButton[ID_CHECK_MANUAL_AUTO].x && x<checkButton[ID_CHECK_MANUAL_AUTO].x+checkButton[ID_CHECK_MANUAL_AUTO].width)
        {
            motion=ID_CHECK_MANUAL_AUTO;
        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    else if(y>checkButton[ID_CHECK_MANUAL_EMPORT].y && y<checkButton[ID_CHECK_MANUAL_EMPORT].y+checkButton[ID_CHECK_MANUAL_EMPORT].height)
    {
        if(x>checkButton[ID_CHECK_MANUAL_EMPORT].x && x<checkButton[ID_CHECK_MANUAL_EMPORT].x+checkButton[ID_CHECK_MANUAL_EMPORT].width)
        {
            motion=ID_CHECK_MANUAL_EMPORT;
        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    else
    {
        motion=ID_CHECK_NONE;
    }

    panelManualButton->Refresh();
}

void CheckUpDlg::OnLeaveManualButton(wxMouseEvent& event)
{
    motion=ID_CHECK_NONE;
    panelManualButton->Refresh();
}

void CheckUpDlg::OnClickManualButton(wxMouseEvent& event)
{
    if(motion==ID_CHECK_MANUAL_CAL)
    {
        double z,l,headc,tailc;
        point3d_t head0,tail0,prism0[3],head1,tail1,prism1[3],prismsurvey[5],prismdesign[5],prism;
        double headh,headv,tailh,tailv,dist[3];
        int a2z=cli->prj.a2z;

        manualHeadx1->GetValue().ToDouble(&head0.x);
        manualHeady1->GetValue().ToDouble(&head0.y);
        manualHeadz1->GetValue().ToDouble(&head0.z);
        manualTailx1->GetValue().ToDouble(&tail0.x);
        manualTaily1->GetValue().ToDouble(&tail0.y);
        manualTailz1->GetValue().ToDouble(&tail0.z);

        manualPrism1x1->GetValue().ToDouble(&prism0[0].x);
        manualPrism1y1->GetValue().ToDouble(&prism0[0].y);
        manualPrism1z1->GetValue().ToDouble(&prism0[0].z);

        manualPrism2x1->GetValue().ToDouble(&prism0[1].x);
        manualPrism2y1->GetValue().ToDouble(&prism0[1].y);
        manualPrism2z1->GetValue().ToDouble(&prism0[1].z);

        manualPrism3x1->GetValue().ToDouble(&prism0[2].x);
        manualPrism3y1->GetValue().ToDouble(&prism0[2].y);
        manualPrism3z1->GetValue().ToDouble(&prism0[2].z);


        manualPrism1x2->GetValue().ToDouble(&prism1[0].x);
        manualPrism1y2->GetValue().ToDouble(&prism1[0].y);
        manualPrism1z2->GetValue().ToDouble(&prism1[0].z);

        manualPrism2x2->GetValue().ToDouble(&prism1[1].x);
        manualPrism2y2->GetValue().ToDouble(&prism1[1].y);
        manualPrism2z2->GetValue().ToDouble(&prism1[1].z);

        manualPrism3x2->GetValue().ToDouble(&prism1[2].x);
        manualPrism3y2->GetValue().ToDouble(&prism1[2].y);
        manualPrism3z2->GetValue().ToDouble(&prism1[2].z);

        transform3d_t trans;
        transform3d_init(&trans,0,0,0,0,0,0,1);
        int flags[7]={1,1,1,1,1,1,0};
        transform3d_init_points(&trans,3,prism0,prism1,flags);
        transform3d_trans(&trans,&head0,&head1);
        transform3d_trans(&trans,&tail0,&tail1);
        for(int i=0;i<3;i++)
        {
            transform3d_trans(&trans,&prism0[i],&prism);
            dist[i]=sqrt((prism.x-prism1[i].x)*(prism.x-prism1[i].x)+(prism.y-prism1[i].y)*(prism.y-prism1[i].y)+(prism.z-prism1[i].z)*(prism.z-prism1[i].z));
        }
        manualHeadx2->SetValue(wxString::Format(_("%.4lf"),head1.x));
        manualHeady2->SetValue(wxString::Format(_("%.4lf"),head1.y));
        manualHeadz2->SetValue(wxString::Format(_("%.4lf"),head1.z));
        manualTailx2->SetValue(wxString::Format(_("%.4lf"),tail1.x));
        manualTaily2->SetValue(wxString::Format(_("%.4lf"),tail1.y));
        manualTailz2->SetValue(wxString::Format(_("%.4lf"),tail1.z));
        manualPrismD1->SetValue(wxString::Format(_("%.4lf"),dist[0]*1000.0));
        manualPrismD2->SetValue(wxString::Format(_("%.4lf"),dist[1]*1000.0));
        manualPrismD3->SetValue(wxString::Format(_("%.4lf"),dist[2]*1000.0));

        if(cli->prj.dta==0)
        {
            //wxMessageBox(_("1"));
            int nh,nv;
            nh=road_number_horizon(&cli->r);
            nv=road_number_vertical(&cli->r);
            if(nh>2||nv>2)
            {
                road_xy2l(&cli->r,head1.x,head1.y,&headc,0,0,0,&headh);
                road_l2h(&cli->r,headc,&z,0);
                headv=head1.z-z;
                headh*=a2z;

                road_xy2l(&cli->r,tail1.x,tail1.y,&tailc,0,0,0,&tailh);
                road_l2h(&cli->r,tailc,&z,0);
                tailv=tail1.z-z;
                tailh*=a2z;

                manualHeadh->SetValue(wxString::Format(_("%.4lf"),headh*1000.0));
                manualHeadv->SetValue(wxString::Format(_("%.4lf"),headv*1000.0));
                manualTailh->SetValue(wxString::Format(_("%.4lf"),tailh*1000.0));
                manualTailv->SetValue(wxString::Format(_("%.4lf"),tailv*1000.0));
            }
        }
        else
        {
            int nh,nv;
            nh=cli->nRoad;
            if(nh>2)
            {
                headv=head1.z-z;
                headh*=a2z;

                tailv=tail1.z-z;
                tailh*=a2z;

                manualHeadh->SetValue(wxString::Format(_("%.4lf"),headh*1000.0));
                manualHeadv->SetValue(wxString::Format(_("%.4lf"),headv*1000.0));
                manualTailh->SetValue(wxString::Format(_("%.4lf"),tailh*1000.0));
                manualTailv->SetValue(wxString::Format(_("%.4lf"),tailv*1000.0));
            }
        }
        cli->mp.head[0]=head0.x;
        cli->mp.head[1]=head0.y;
        cli->mp.head[2]=head0.z;
        cli->mp.head[3]=head1.x;
        cli->mp.head[4]=head1.y;
        cli->mp.head[5]=head1.z;
        cli->mp.tail[0]=tail0.x;
        cli->mp.tail[1]=tail0.y;
        cli->mp.tail[2]=tail0.z;
        cli->mp.tail[3]=tail1.x;
        cli->mp.tail[4]=tail1.y;
        cli->mp.tail[5]=tail1.z;
        cli->mp.prism[0]=prism0[0].x;
        cli->mp.prism[1]=prism0[0].y;
        cli->mp.prism[2]=prism0[0].z;
        cli->mp.prism[3]=prism0[1].x;
        cli->mp.prism[4]=prism0[1].y;
        cli->mp.prism[5]=prism0[1].z;
        cli->mp.prism[6]=prism0[2].x;
        cli->mp.prism[7]=prism0[2].y;
        cli->mp.prism[8]=prism0[2].z;

        cli->mp.prism[9]=prism1[0].x;
        cli->mp.prism[10]=prism1[0].y;
        cli->mp.prism[11]=prism1[0].z;
        cli->mp.prism[12]=prism1[1].x;
        cli->mp.prism[13]=prism1[1].y;
        cli->mp.prism[14]=prism1[1].z;
        cli->mp.prism[15]=prism1[2].x;
        cli->mp.prism[16]=prism1[2].y;
        cli->mp.prism[17]=prism1[2].z;
        cli->mp.pdev[0]=dist[0];
        cli->mp.pdev[1]=dist[1];
        cli->mp.pdev[2]=dist[2];
        cli->mp.headh=headh;
        cli->mp.headv=headv;
        cli->mp.tailh=tailh;
        cli->mp.tailv=tailv;
        time_t now;
        time(&now);
        cli->mp.t=now;
        //mtg_store_mp(cli);///20150814有待添加

        cli->m1.head[0]=head1.x;
        cli->m1.head[1]=head1.y;
        cli->m1.head[2]=head1.z;
        cli->m1.headh=headh;
        cli->m1.headv=headv;
        cli->m1.headc=headc;

        cli->m1.tail[0]=tail1.x;
        cli->m1.tail[1]=tail1.y;
        cli->m1.tail[2]=tail1.z;
        cli->m1.tailh=tailh;
        cli->m1.tailv=tailv;
        cli->m1.tailc=tailc;
        cli->m1.t1=now;
        point3d_t left,left1,left0;
        double phi,omega,kapa,dist1,d;
        dist1=sqrt((head0.x-tail0.x)*(head0.x-tail0.x)+(head0.y-tail0.y)*(head0.y-tail0.y));

        /*left.x=0.0;
        left.y=100.0;
        left.z=0.0;
        phi=0;*/
        omega=atan((head0.z-tail0.z)/dist1);
        kapa=atan2(head0.y-tail0.y,head0.x-tail0.x);
        ///修正角度
        phi=atan(tan(phi)/cos(omega));
        transform3d_t trans1;
        transform3d_init(&trans1,phi,omega,-kapa,tail0.x,tail0.y,tail0.z,1);
        //transform3d_trans(&trans1,&left,&left0);
        /*transform3d_trans(&trans,&left0,&left1);
        d = sqrt((left1.x-tail1.x)*(left1.x-tail1.x)+(left1.y-tail1.y)*(left1.y-tail1.y));*/
        double roll,pitch,azi;
        pitch=atan((head1.z-tail1.z)/dist1);
        /*roll=-atan((left1.z-tail1.z)/d);
        roll=atan(tan(roll)/cos(pitch));*/
        roll=0;
        azi=atan2(head1.y-tail1.y,head1.x-tail1.x);
        cli->m1.roll=roll;
        cli->m1.pitch=pitch;
        cli->m1.azimuth=azi;
        ((mtg_tFrame*)GetParent())->panelMetric->Refresh();
        ///cli->m1.t1=now;
        //cli->fmp=1;
    }
    else if(motion==ID_CHECK_MANUAL_EMPORT)
    {
        motion1=ID_CHECK_MANUAL_EMPORT;
        wxFileDialog dlg(this,_("人工姿态导出文件"),wxEmptyString,wxEmptyString,_("人工姿态计算数据(*.csv)|*.csv"),wxFD_SAVE);
        dlg.Center();
        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str = dlg.GetPath();
            if(wxFileExists(str))
            {
                int rs=wxMessageBox(_("该文件已经存在,是否应该覆盖?"),_("提示"),wxYES|wxNO);
                if(rs==wxYES)
                    wxRemoveFile(str);
                else
                    return;
            }
            char path[260];
            strcpy(path,str.mb_str(wxConvLocal));
            ExportSheildFile(path);
        }
    }
    else if(motion==ID_CHECK_MANUAL_AUTO)
    {
    }
    panelManualButton->Refresh();
}

void CheckUpDlg::OnPaintManualFig(wxPaintEvent& event)
{
    wxPaintDC dc(panelManualFig);
    int w,h;
    panelManualFig->GetClientSize(&w,&h);
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
        ///绘制盾构机
        int x1,y1,w1,h1;
        double sx,sy;
        double L[4],x[3],y[3],prismx,prismy,prismz;
        double dx,dy,dz;
        double p;

        int mapx[3],mapy[3];
        point3d_t head0,head1,tail0,tail1,prism0[3];

        head0.x=cli->mp.head[0];
        head0.y=cli->mp.head[1];
        head0.z=cli->mp.head[2];
        head1.x=cli->mp.head[3];
        head1.y=cli->mp.head[4];
        head1.z=cli->mp.head[5];
        tail0.x=cli->mp.tail[0];
        tail0.y=cli->mp.tail[1];
        tail0.z=cli->mp.tail[2];
        tail1.x=cli->mp.tail[3];
        tail1.y=cli->mp.tail[4];
        tail1.z=cli->mp.tail[5];
        prism0[0].x=cli->mp.prism[0];
        prism0[0].y=cli->mp.prism[1];
        prism0[0].z=cli->mp.prism[2];
        prism0[1].x=cli->mp.prism[3];
        prism0[1].y=cli->mp.prism[4];
        prism0[1].z=cli->mp.prism[5];
        prism0[2].x=cli->mp.prism[6];
        prism0[2].y=cli->mp.prism[7];
        prism0[2].z=cli->mp.prism[8];

        L[0]=sqrt((head0.x-tail0.x)*(head0.x-tail0.x)+(head0.y-tail0.y)*(head0.y-tail0.y)+(head0.z-tail0.z)*(head0.z-tail0.z));
        ///wxMessageBox(wxString::Format(_("%lf"),L[0]));

        for(int i=0;i<3;i++)
        {
            L[1]=sqrt((head0.x-prism0[i].x)*(head0.x-prism0[i].x)+(head0.y-prism0[i].y)*(head0.y-prism0[i].y)+(head0.z-prism0[i].z)*(head0.z-prism0[i].z));
            L[2]=sqrt((tail0.x-prism0[i].x)*(tail0.x-prism0[i].x)+(tail0.y-prism0[i].y)*(tail0.y-prism0[i].y)+(tail0.z-prism0[i].z)*(tail0.z-prism0[i].z));
            p=L[0]*L[0]+L[1]*L[1]-L[2]*L[2];
            p=p/2/L[0]/L[1];
            L[3]=L[1]*p;

            dx=-(head0.x-tail0.x)/L[0];
            dy=-(head0.y-tail0.y)/L[0];
            dz=-(head0.z-tail0.z)/L[0];
            prismx=head0.x+L[3]*dx;
            prismy=head0.y+L[3]*dy;
            prismz=head0.z+L[3]*dz;
            y[i]=prismz-prism0[i].z;
            x[i]=-L[3];
        }
        sx=L[0]/(w-50);
        sy=5.4/(h-40);
        if(sx>sy)
            sx=sy;
        ///memDC.SetBrush(wxBrush(wxTRANSPARENT));
        memDC.DrawRectangle(25,20,w-50,h-40);
        memDC.SetPen(wxPen(wxColor(158,158,158),1,wxLONG_DASH));
        x1=25;
        y1=h/2;
        w1=w-50;
        h1=(h-40)/2;
        ///wxMessageBox(wxString::Format(_("x=%d,y=%d"),x1,y1));
        memDC.DrawLine(x1-5,y1,x1+w1+5,y1);
        memDC.DrawLabel(_("尾"),wxRect(x1-20,y1,x1,y1+10),wxALIGN_LEFT | wxALIGN_TOP);
        memDC.DrawLabel(_("首"),wxRect(x1+w1+10,y1,x1+w1+25,y1+10),wxALIGN_LEFT | wxALIGN_TOP);

        ///wxMessageBox(wxString::Format(_("x=%d,y=%d"),x1,y1));
        if(ok==1)
        {
            x1=x1+w1;
            for(int i=0;i<3;i++)
            {
                mapx[i]=x1+(int)(x[i]/sx);
                mapy[i]=y1+(int)(y[i]/sy);
                memDC.DrawCircle(mapx[i],mapy[i],2);
                ///wxMessageBox(wxString::Format(_("%d:x=%d,y=%d"),i,mapx[i],mapy[i]));
                memDC.DrawLabel(wxString::Format(_("%d#"),i+1),wxRect(mapx[i],mapy[i],mapx[i]+10,mapy[i]+5),wxALIGN_LEFT | wxALIGN_TOP);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void CheckUpDlg::OnPaintBottom(wxPaintEvent& event)
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
        h1=26;
        x1=w-w1-14;
        y1=9;
        checkButton[ID_CHECK_QUIT].x=x1;
        checkButton[ID_CHECK_QUIT].y=y1;
        checkButton[ID_CHECK_QUIT].width=w1;
        checkButton[ID_CHECK_QUIT].height=h1;
        if(motion==ID_CHECK_QUIT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("退出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void CheckUpDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>checkButton[ID_CHECK_QUIT].y && y<checkButton[ID_CHECK_QUIT].y+checkButton[ID_CHECK_QUIT].height)
    {
        if(x>checkButton[ID_CHECK_QUIT].x && x<checkButton[ID_CHECK_QUIT].x+checkButton[ID_CHECK_QUIT].width)
        {
            motion=ID_CHECK_QUIT;
        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    else
    {
        motion=ID_CHECK_NONE;
    }
    panelBottom->Refresh();
}

void CheckUpDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_CHECK_NONE;
    panelBottom->Refresh();
}

void CheckUpDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_CHECK_QUIT)
    {
        Destroy();
    }
    ///panelBottom->Refresh();
}

void CheckUpDlg::LoadData()
{
    manualHeadx1->SetValue(wxString::Format(_("%.4lf"),cli->mp.head[0]));
    manualHeady1->SetValue(wxString::Format(_("%.4lf"),cli->mp.head[1]));
    manualHeadz1->SetValue(wxString::Format(_("%.4lf"),cli->mp.head[2]));
    manualTailx1->SetValue(wxString::Format(_("%.4lf"),cli->mp.tail[0]));
    manualTaily1->SetValue(wxString::Format(_("%.4lf"),cli->mp.tail[1]));
    manualTailz1->SetValue(wxString::Format(_("%.4lf"),cli->mp.tail[2]));

    manualPrism1x1->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[0]));
    manualPrism1y1->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[1]));
    manualPrism1z1->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[2]));

    manualPrism2x1->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[3]));
    manualPrism2y1->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[4]));
    manualPrism2z1->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[5]));

    manualPrism3x1->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[6]));
    manualPrism3y1->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[7]));
    manualPrism3z1->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[8]));

    manualPrism1x2->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[9]));
    manualPrism1y2->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[10]));
    manualPrism1z2->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[11]));

    manualPrism2x2->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[12]));
    manualPrism2y2->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[13]));
    manualPrism2z2->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[14]));

    manualPrism3x2->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[15]));
    manualPrism3y2->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[16]));
    manualPrism3z2->SetValue(wxString::Format(_("%.4lf"),cli->mp.prism[17]));

    manualHeadx2->SetValue(wxString::Format(_("%.4lf"),cli->mp.head[3]));
    manualHeady2->SetValue(wxString::Format(_("%.4lf"),cli->mp.head[4]));
    manualHeadz2->SetValue(wxString::Format(_("%.4lf"),cli->mp.head[5]));
    manualTailx2->SetValue(wxString::Format(_("%.4lf"),cli->mp.tail[3]));
    manualTaily2->SetValue(wxString::Format(_("%.4lf"),cli->mp.tail[4]));
    manualTailz2->SetValue(wxString::Format(_("%.4lf"),cli->mp.tail[5]));

    manualHeadh->SetValue(wxString::Format(_("%.1f"),cli->mp.headh*1000.0));
    manualHeadv->SetValue(wxString::Format(_("%.1f"),cli->mp.headv*1000.0));
    manualTailh->SetValue(wxString::Format(_("%.1f"),cli->mp.tailh*1000.0));
    manualTailv->SetValue(wxString::Format(_("%.1f"),cli->mp.tailv*1000.0));

    manualPrismD1->SetValue(wxString::Format(_("%.1f"),cli->mp.pdev[0]*1000.0));
    manualPrismD2->SetValue(wxString::Format(_("%.1f"),cli->mp.pdev[1]*1000.0));
    manualPrismD3->SetValue(wxString::Format(_("%.1f"),cli->mp.pdev[2]*1000.0));

    dtaMile1->SetValue(wxString::Format(_("%.4f"),cli->prj.mile1));
    dtaStep->SetValue(wxString::Format(_("%.4f"),cli->segset.L));
}

void CheckUpDlg::OnPaintBackground(wxPaintEvent& event)
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

void CheckUpDlg::OnPaintNavi(wxPaintEvent& event)
{
    wxPaintDC dc(panelNavi);
    int w,h;
    panelNavi->GetClientSize(&w,&h);

    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(0,0,w,h);
}

void CheckUpDlg::coord_cal(double mile,double step)
{
    int nh=road_number_horizon(&cli->r);
    int nv=road_number_vertical(&cli->r);
    if(nh<=2 && nv<=2)
    {
        wxMessageBox(_("中线数据不完整！"));
        return;
    }
    double maxl=road_horizon(&cli->r,nh-1)->l1;

    dtaList->DeleteAllItems();
    nck=0;
    ckl[nck]=mile;
    if(nh>2 && nv>2)
    {
        road_l2xy(&cli->r,ckl[nck],&ckx[nck],&cky[nck],0);
        road_l2h(&cli->r,l,&ckz[nck],0);
        dtaList->InsertItem(0,wxString::Format(_("%d"),nck+1));
        dtaList->SetItem(0,1,wxString::Format(_("%.3f"),ckl[nck]));
        dtaList->SetItem(0,2,wxString::Format(_("%.3f"),ckx[nck]));
        dtaList->SetItem(0,3,wxString::Format(_("%.3f"),cky[nck]));
        dtaList->SetItem(0,4,wxString::Format(_("%.3f"),ckz[nck]));
        nck++;
        nck1=0;
        ckl[nck]=ckl[nck-1]+step;
        while(ckl[nck]<maxl)
        {
            if(nck<5000)
            {
                road_l2xy(&cli->r,ckl[nck],&ckx[nck],&cky[nck],0);
                road_l2h(&cli->r,ckl[nck],&ckz[nck],0);
                dtaList->InsertItem(nck,wxString::Format(_("%d"),nck+1));
                dtaList->SetItem(nck,1,wxString::Format(_("%.3f"),ckl[nck]));
                dtaList->SetItem(nck,2,wxString::Format(_("%.3f"),ckx[nck]));
                dtaList->SetItem(nck,3,wxString::Format(_("%.3f"),cky[nck]));
                dtaList->SetItem(nck,4,wxString::Format(_("%.3f"),ckz[nck]));
                nck++;
                ckl[nck]=ckl[nck-1]+step;
            }
        }
    }
    else if(nh>2)
    {
        road_l2xy(&cli->r,ckl[nck],&ckx[nck],&cky[nck],0);
        dtaList->InsertItem(0,wxString::Format(_("%d"),nck+1));
        dtaList->SetItem(0,1,wxString::Format(_("%.3f"),ckl[nck]));
        dtaList->SetItem(0,2,wxString::Format(_("%.3f"),ckx[nck]));
        dtaList->SetItem(0,3,wxString::Format(_("%.3f"),cky[nck]));
        dtaList->SetItem(0,4,wxString::Format(_("%.3f"),0));
        nck++;
        nck1=0;
        ckl[nck]=ckl[nck-1]+step;
        while(ckl[nck]<maxl)
        {
            if(nck<5000)
            {
                road_l2xy(&cli->r,ckl[nck],&ckx[nck],&cky[nck],0);
                ckz[nck]=0.0;
                dtaList->InsertItem(nck,wxString::Format(_("%d"),nck+1));
                dtaList->SetItem(nck,1,wxString::Format(_("%.3f"),ckl[nck]));
                dtaList->SetItem(nck,2,wxString::Format(_("%.3f"),ckx[nck]));
                dtaList->SetItem(nck,3,wxString::Format(_("%.3f"),cky[nck]));
                dtaList->SetItem(nck,4,wxString::Format(_("%.3f"),ckz[nck]));
                nck++;
                ckl[nck]=ckl[nck-1]+step;
            }
        }
    }
    else if(nv>2)
    {
        road_l2h(&cli->r,l,&ckz[nck],0);
        ckx[nck]=0.0;
        cky[nck]=0.0;
        dtaList->InsertItem(0,wxString::Format(_("%d"),nck+1));
        dtaList->SetItem(0,1,wxString::Format(_("%.3f"),ckl[nck]));
        dtaList->SetItem(0,2,wxString::Format(_("%.3f"),ckx[nck]));
        dtaList->SetItem(0,3,wxString::Format(_("%.3f"),cky[nck]));
        dtaList->SetItem(0,4,wxString::Format(_("%.3f"),ckz[nck]));
        nck++;
        nck1=0;
        ckl[nck]=ckl[nck-1]+step;
        while(ckl[nck]<maxl)
        {
            if(nck<5000)
            {
                ckx[nck]=0.0;
                cky[nck]=0.0;
                road_l2h(&cli->r,ckl[nck],&ckz[nck],0);
                dtaList->InsertItem(nck,wxString::Format(_("%d"),nck+1));
                dtaList->SetItem(nck,1,wxString::Format(_("%.3f"),ckl[nck]));
                dtaList->SetItem(nck,2,wxString::Format(_("%.3f"),ckx[nck]));
                dtaList->SetItem(nck,3,wxString::Format(_("%.3f"),cky[nck]));
                dtaList->SetItem(nck,4,wxString::Format(_("%.3f"),ckz[nck]));
                nck++;
                ckl[nck]=ckl[nck-1]+step;
            }
        }
    }
}

void CheckUpDlg::coord_check()
{
    int nh=road_number_horizon(&cli->r);
    int nv=road_number_vertical(&cli->r);
    if(nh<=2 && nv<=2)
    {
        wxMessageBox(_("中线数据不完整！"));
        return;
    }

    wxFileDialog dlg(this,_("中线坐标数据"),wxEmptyString,wxEmptyString,_("中线坐标数据(*.csv)|*.csv"),wxFD_OPEN);
    dlg.Center();
    if(dlg.ShowModal()==wxID_OK)
    {
        wxString str1 = dlg.GetPath();
        char path[1024];
        char buf[1024];
        char mark[64];
        char coor1[64];
        char coor2[64];
        char coor3[64];

        dtaList->DeleteAllItems();

        strcpy(path,str1.mb_str(wxConvLocal));
        FILE* fp=fopen(path,"r");
        if(fp)
        {
            wxString valstr;
            while(!feof(fp))
            {
                fgets(buf,1024,fp);
                if(sscanf(buf,"%[^,],%[^,],%[^,],%s",mark,coor1,coor2,coor3)==4)
                {
                    if(nck1<5000)
                    {
                        valstr = wxString(coor1,wxConvUTF8);
                        if(valstr.ToDouble(&ckx1[nck1]))
                        {
                            valstr = wxString(coor2,wxConvUTF8);
                            if(valstr.ToDouble(&cky1[nck1]))
                            {
                                valstr = wxString(coor3,wxConvUTF8);

                                if(valstr.ToDouble(&ckz1[nck1]))
                                {
                                    if(nh>2 && nv>2)
                                    {
                                        road_xy2l(&cli->r,ckx1[nck1],cky1[nck1],&ckl[nck1],&ckx[nck1],&cky[nck1],0,&ckho[nck1]);
                                        road_l2h(&cli->r,ckl[nck1],&ckz[nck1],0);
                                        ckvo[nck1]=ckz1[nck1]-ckz[nck1];
                                        dtaList->InsertItem(nck1,wxString::Format(_("%d"),nck1+1));
                                        dtaList->SetItem(nck1,1,wxString::Format(_("%.3f"),ckl[nck1]));
                                        dtaList->SetItem(nck1,2,wxString::Format(_("%.3f"),ckx1[nck1]));
                                        dtaList->SetItem(nck1,3,wxString::Format(_("%.3f"),cky1[nck1]));
                                        dtaList->SetItem(nck1,4,wxString::Format(_("%.3f"),ckz1[nck1]));
                                        dtaList->SetItem(nck1,5,wxString::Format(_("%.3f"),ckho[nck1]));
                                        dtaList->SetItem(nck1,6,wxString::Format(_("%.3f"),ckvo[nck1]));
                                    }
                                    else if(nh>2)
                                    {
                                        road_xy2l(&cli->r,ckx1[nck1],cky1[nck1],&ckl[nck1],&ckx[nck1],&cky[nck1],0,&ckho[nck1]);
                                        dtaList->InsertItem(nck1,wxString::Format(_("%d"),nck1+1));
                                        dtaList->SetItem(nck1,1,wxString::Format(_("%.3f"),ckl[nck1]));
                                        dtaList->SetItem(nck1,2,wxString::Format(_("%.3f"),ckx1[nck1]));
                                        dtaList->SetItem(nck1,3,wxString::Format(_("%.3f"),cky1[nck1]));
                                        dtaList->SetItem(nck1,4,wxString::Format(_("%.3f"),0));
                                        dtaList->SetItem(nck1,5,wxString::Format(_("%.3f"),ckho[nck1]));
                                        dtaList->SetItem(nck1,6,wxString::Format(_("%.3f"),0));
                                    }
                                    nck1++;
                                    nck=0;
                                }
                            }
                        }
                    }
                }
            }
            fclose(fp);
        }
    }
}

void CheckUpDlg::coord_export()
{
    wxFileDialog dlg(this,_("保存文件"),wxEmptyString,wxEmptyString,_("坐标表数据(*.csv)|*.csv"),wxFD_SAVE);
    dlg.Center();
    if(dlg.ShowModal()==wxID_OK)
    {
        wxString str = dlg.GetPath();
        if(wxFileExists(str))
        {
            int rs=wxMessageBox(_("该文件已经存在,是否应该覆盖?"),_("提示"),wxYES|wxNO);
            if(rs==wxYES)
                wxRemoveFile(str);
            else
                return;
        }
        char path[260];
        strcpy(path,str.mb_str(wxConvLocal));
        FILE *fp;
        fp=fopen(path,"w");
        if(fp)
        {
            wxString str;
            if(motion1==ID_CHECK_DTA_CAL)
            {
                str=_("序号,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("里程,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("北坐标X,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("东坐标Y,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("高程Z\n");
                fprintf(fp,str.mb_str(wxConvLocal));
                for(int i=0;i<nck;i++)
                {
                    fprintf(fp,"%d,%.4f,%.4f,%.4f,%.4f\n",i+1,ckl[i],ckx[i],cky[i],ckz[i]);
                }
                fclose(fp);
                wxMessageBox(wxT("导出成功！"));
            }
            else if(motion1==ID_CHECK_DTA_CHECK)
            {
                str=_("序号,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("里程,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("导入X,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("导入Y,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("导入Z,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("设计X,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("设计Y,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("设计Z,");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("水平偏差(mm),");
                fprintf(fp,str.mb_str(wxConvLocal));
                str=_("垂直偏差(mm)\n");
                fprintf(fp,str.mb_str(wxConvLocal));
                for(int i=0;i<nck1;i++)
                {
                    fprintf(fp,"%d,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.1f,%.1f\n",i+1,ckl[i],ckx1[i],cky1[i],ckz1[i],ckx1[i],cky1[i],ckz1[i],ckho[i]*1000.0,ckvo[i]*1000.0);
                }
                fclose(fp);
                wxMessageBox(wxT("导出成功！"));
            }
        }
        //ExportSegmentFile(path);
    }
}

void CheckUpDlg::ExportSegmentFile(char* str1)
{
    /*FILE *fp;
    fp=fopen(str1,"w");
    if(fp==NULL)
    {
        wxMessageBox(_("文件打开失败"));
    }
    else
    {
        if(motion1==ID_CHECK_DTA_CAL)
        {
            int rows,No;
            double x,y,z,l;
            wxString str;
            double val;
            fprintf(fp,"No,mile,x,y,z\n");

            rows=dtaGrid->GetNumberRows();
            for(int i=0;i<rows;i++)
            {
                dtaGrid->GetCellValue(i,0).ToDouble(&val);
                No=(int)val;
                dtaGrid->GetCellValue(i,1).ToDouble(&l);
                dtaGrid->GetCellValue(i,2).ToDouble(&x);
                dtaGrid->GetCellValue(i,3).ToDouble(&y);
                dtaGrid->GetCellValue(i,4).ToDouble(&z);
                fprintf(fp,"%d,%lf,%lf,%lf,%lf\n",No,l,x,y,z);
            }
            fclose(fp);
            wxMessageBox(wxT("导出成功！"));
        }
        else if(motion1==ID_CHECK_DTA_CHECK)
        {
            int rows,No;
            double x,y,z,x1,y1,z1,l,hoff,voff;
            wxString str;
            double val;

            rows=dtaGrid->GetNumberRows();
            for(int i=0;i<rows;i++)
            {
                dtaGrid->GetCellValue(i,0).ToDouble(&val);
                No=(int)val;
                dtaGrid->GetCellValue(i,1).ToDouble(&l);
                dtaGrid->GetCellValue(i,2).ToDouble(&x);
                dtaGrid->GetCellValue(i,3).ToDouble(&y);
                dtaGrid->GetCellValue(i,4).ToDouble(&z);
//                dtaGrid->GetCellValue(i,4).ToDouble(&x1);
//                dtaGrid->GetCellValue(i,5).ToDouble(&y1);
//                dtaGrid->GetCellValue(i,6).ToDouble(&z1);
                dtaGrid->GetCellValue(i,5).ToDouble(&hoff);
                dtaGrid->GetCellValue(i,6).ToDouble(&voff);
                fprintf(fp,"%d,%lf,%lf,%lf,%lf,%lf,%lf\n",No,l,x,y,z,hoff,voff);
            }
            fclose(fp);
            wxMessageBox(wxT("导出成功！"));
        }
        else if(motion1==ID_CHECK_CIRCLE_EXPORT)
        {
            int n;
            n=circleFit.data.size();
            wxString str;
            str=_("拟合点数据");
            char chstr[260];
            strcpy(chstr,str.mb_str(wxConvLocal));
            fprintf(fp,"%s\n",chstr);
            str=_("点号,X(m),Y(m),Z(m),选取,圆度(mm),平面度(mm)\n");
            strcpy(chstr,str.mb_str(wxConvLocal));
            fprintf(fp,"%s",chstr);
            for(int i=0;i<n;i++)
            {
                fprintf(fp,"%d,%lf,%lf,%lf,%d,%lf,%lf\n",i+1,circleFit.data[i].x,circleFit.data[i].y,circleFit.data[i].z,circleFit.data[i].used,circleFit.data[i].dc,circleFit.data[i].dp);
            }
            fprintf(fp,"\n");
            str=_("计算结果");
            strcpy(chstr,str.mb_str(wxConvLocal));
            fprintf(fp,"%s\n",chstr);
            str=_("实际洞门中心");
            strcpy(chstr,str.mb_str(wxConvLocal));
            fprintf(fp,"%s,",chstr);
            double l,ho,vo,x0,y0,z0;
            /*road_xy2l(&cli->r,circleFit.center[0],circleFit.center[1],&l,&x0,&y0,0,&ho);
            road_l2h(&cli->r,l,&z0,0);
            vo=circleFit.center[2]-z0;*/
            /*fprintf(fp,"%lf,%lf,%lf,%lf,%lf,%lf\n",circleFit.center[0],circleFit.center[1],circleFit.center[2],l,ho,vo);
            str=_("设计洞门中心");
            strcpy(chstr,str.mb_str(wxConvLocal));
            fprintf(fp,"%s,",chstr);
            fprintf(fp,"%lf,%lf,%lf\n",x0,y0,z0);
            fclose(fp);
        }
    }*/
}

bool CheckUpDlg::ReadFile(char *str)
{
    return true;
}

void CheckUpDlg::ExportSheildFile(char* str1)
{
    FILE *fp;
    fp=fopen(str1,"w");
    if(fp==NULL)
    {
        wxMessageBox(_("文件打开失败"));
    }
    else
    {
        if(motion1==ID_CHECK_MANUAL_EMPORT)
        {
            wxString wxstr;
            char str[1024];

            wxstr=_("初始数据\n ,x,y,z");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s\n",str);


            wxstr=_("切口");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s,%lf,%lf,%lf\n",str,cli->mp.head[0],cli->mp.head[1],cli->mp.head[2]);

            wxstr=_("盾尾");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s,%lf,%lf,%lf\n",str,cli->mp.tail[0],cli->mp.tail[1],cli->mp.tail[2]);

            wxstr=_("1#棱镜");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s,%lf,%lf,%lf\n",str,cli->mp.prism[0],cli->mp.prism[1],cli->mp.prism[2]);

            wxstr=_("2#棱镜");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s,%lf,%lf,%lf\n",str,cli->mp.prism[3],cli->mp.prism[4],cli->mp.prism[5]);

            wxstr=_("3#棱镜");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s,%lf,%lf,%lf\n",str,cli->mp.prism[6],cli->mp.prism[7],cli->mp.prism[8]);

            fprintf(fp,"\n");

            wxstr=_("测量数据\n ,x,y,z,较差(mm)");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s\n",str);

            wxstr=_("1#棱镜");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s,%lf,%lf,%lf,%lf\n",str,cli->mp.prism[9],cli->mp.prism[10],cli->mp.prism[11],cli->mp.pdev[0]*1000.0);

            wxstr=_("2#棱镜");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s,%lf,%lf,%lf,%lf\n",str,cli->mp.prism[12],cli->mp.prism[13],cli->mp.prism[14],cli->mp.pdev[1]*1000.0);

            wxstr=_("3#棱镜");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s,%lf,%lf,%lf,%lf\n",str,cli->mp.prism[15],cli->mp.prism[16],cli->mp.prism[17],cli->mp.pdev[2]*1000.0);

            fprintf(fp,"\n");

            wxstr=_("计算结果\n ,x,y,z,水平偏差(mm),垂直偏差(mm)");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s\n",str);

            wxstr=_("切口");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s,%lf,%lf,%lf,%lf,%lf\n",str,cli->mp.head[3],cli->mp.head[4],cli->mp.head[5],cli->mp.headh*1000.0,cli->mp.headv*1000.0);

            wxstr=_("盾尾");
            strcpy(str,wxstr.mb_str(wxConvLocal));
            fprintf(fp,"%s,%lf,%lf,%lf,%lf,%lf\n",str,cli->mp.tail[3],cli->mp.tail[4],cli->mp.tail[5],cli->mp.tailh*1000.0,cli->mp.tailv*1000.0);

            fclose(fp);
            wxMessageBox(wxT("导出成功！"));
        }
    }
}

void CheckUpDlg::OnUpdateManual(wxCommandEvent& event)
{
    ok=0;
    if(!(manualHeadx1->GetValue().ToDouble(&cli->mp.head[0])))
    {
        event.Skip();
        return;
    }
    if(!(manualHeady1->GetValue().ToDouble(&cli->mp.head[1])))
    {
        event.Skip();
        return;
    }
    if(!(manualHeadz1->GetValue().ToDouble(&cli->mp.head[2])))
    {
        event.Skip();
        return;
    }
    if(!manualTailx1->GetValue().ToDouble(&cli->mp.tail[0]))
    {
        event.Skip();
        return;
    }
    if(!manualTaily1->GetValue().ToDouble(&cli->mp.tail[1]))
    {
        event.Skip();
        return;
    }
    if(!manualTailz1->GetValue().ToDouble(&cli->mp.tail[2]))
    {
        event.Skip();
        return;
    }

    if(!manualPrism1x1->GetValue().ToDouble(&cli->mp.prism[0]))
    {
        event.Skip();
        return;
    }
    if(!manualPrism1y1->GetValue().ToDouble(&cli->mp.prism[1]))
    {
        event.Skip();
        return;
    }
    if(!manualPrism1z1->GetValue().ToDouble(&cli->mp.prism[2]))
    {
        event.Skip();
        return;
    }
    if(!manualPrism2x1->GetValue().ToDouble(&cli->mp.prism[3]))
    {
        event.Skip();
        return;
    }
    if(!manualPrism2y1->GetValue().ToDouble(&cli->mp.prism[4]))
    {
        event.Skip();
        return;
    }
    if(!manualPrism2z1->GetValue().ToDouble(&cli->mp.prism[5]))
    {
        event.Skip();
        return;
    }

    if(!manualPrism3x1->GetValue().ToDouble(&cli->mp.prism[6]))
    {
        event.Skip();
        return;
    }
    if(!manualPrism3y1->GetValue().ToDouble(&cli->mp.prism[7]))
    {
        event.Skip();
        return;
    }
    if(!manualPrism3z1->GetValue().ToDouble(&cli->mp.prism[8]))
    {
        event.Skip();
        return;
    }
    ok=1;
    event.Skip();
    panelManualFig->Refresh();
}

void CheckUpDlg::OnPaintCircleButton(wxPaintEvent& event)
{
    wxPaintDC dc(panelCircleButton);
    int w,h;
    panelCircleButton->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(239,239,239)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);

        int x1,y1,w1,h1;
        w1=65;
        h1=24;
        x1=w-w1-10;
        y1=0;

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        /*checkButton[ID_CHECK_CIRCLE_ADD].x=x1;
        checkButton[ID_CHECK_CIRCLE_ADD].y=y1;
        checkButton[ID_CHECK_CIRCLE_ADD].width=w1;
        checkButton[ID_CHECK_CIRCLE_ADD].height=h1;
        if(motion==ID_CHECK_CIRCLE_ADD)
        {
            memDC.SetPen(btnPen[2]);
            memDC.SetBrush(ibrush[2]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("增加"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        ///y1=y1+h1+7;
          x1=x1+w1+5;
        checkButton[ID_CHECK_CIRCLE_DELETE].x=x1;
        checkButton[ID_CHECK_CIRCLE_DELETE].y=y1;
        checkButton[ID_CHECK_CIRCLE_DELETE].width=w1;
        checkButton[ID_CHECK_CIRCLE_DELETE].height=h1;
        if(motion==ID_CHECK_CIRCLE_DELETE)
        {
            memDC.SetPen(btnPen[2]);
            memDC.SetBrush(ibrush[2]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("删除"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        */

        ///y1=y1+h1+7;
        checkButton[ID_CHECK_CIRCLE_IMPORT].x=x1;
        checkButton[ID_CHECK_CIRCLE_IMPORT].y=y1;
        checkButton[ID_CHECK_CIRCLE_IMPORT].width=w1;
        checkButton[ID_CHECK_CIRCLE_IMPORT].height=h1;
        if(motion==ID_CHECK_CIRCLE_IMPORT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[1]);
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
        //  x1=x1+w1+5;
        checkButton[ID_CHECK_CIRCLE_EXPORT].x=x1;
        checkButton[ID_CHECK_CIRCLE_EXPORT].y=y1;
        checkButton[ID_CHECK_CIRCLE_EXPORT].width=w1;
        checkButton[ID_CHECK_CIRCLE_EXPORT].height=h1;
        if(motion==ID_CHECK_CIRCLE_EXPORT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[1]);
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

        y1=y1+h1+7;
        checkButton[ID_CHECK_CIRCLE_CAL].x=x1;
        checkButton[ID_CHECK_CIRCLE_CAL].y=y1;
        checkButton[ID_CHECK_CIRCLE_CAL].width=w1;
        checkButton[ID_CHECK_CIRCLE_CAL].height=h1;
        if(motion==ID_CHECK_CIRCLE_CAL)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("计算"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void CheckUpDlg::OnMotionCircleButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    /*if(y>checkButton[ID_CHECK_CIRCLE_ADD].y && y<checkButton[ID_CHECK_CIRCLE_ADD].y+checkButton[ID_CHECK_CIRCLE_ADD].height)
    {
        if(x>checkButton[ID_CHECK_CIRCLE_ADD].x && x<checkButton[ID_CHECK_CIRCLE_ADD].x+checkButton[ID_CHECK_CIRCLE_ADD].width)
        {
            motion=ID_CHECK_CIRCLE_ADD;
        }
        else if(x>checkButton[ID_CHECK_CIRCLE_DELETE].x && x<checkButton[ID_CHECK_CIRCLE_DELETE].x+checkButton[ID_CHECK_CIRCLE_DELETE].width)
        {
            motion=ID_CHECK_CIRCLE_DELETE;
        }
        else if(x>checkButton[ID_CHECK_CIRCLE_CAL].x && x<checkButton[ID_CHECK_CIRCLE_CAL].x+checkButton[ID_CHECK_CIRCLE_CAL].width)
        {
            motion=ID_CHECK_CIRCLE_CAL;
        }
        else if(x>checkButton[ID_CHECK_CIRCLE_IMPORT].x && x<checkButton[ID_CHECK_CIRCLE_IMPORT].x+checkButton[ID_CHECK_CIRCLE_IMPORT].width)
        {
            motion=ID_CHECK_CIRCLE_IMPORT;
        }
        else if(x>checkButton[ID_CHECK_CIRCLE_EXPORT].x && x<checkButton[ID_CHECK_CIRCLE_EXPORT].x+checkButton[ID_CHECK_CIRCLE_EXPORT].width)
        {
            motion=ID_CHECK_CIRCLE_EXPORT;
        }
        else
        {
            motion=ID_CHECK_NONE;
        }
    }*/
    if(x>checkButton[ID_CHECK_CIRCLE_IMPORT].x && x<checkButton[ID_CHECK_CIRCLE_IMPORT].y+checkButton[ID_CHECK_CIRCLE_IMPORT].width)
    {
        if(y>checkButton[ID_CHECK_CIRCLE_IMPORT].y && y<checkButton[ID_CHECK_CIRCLE_IMPORT].y+checkButton[ID_CHECK_CIRCLE_IMPORT].height)
        {
            motion=ID_CHECK_CIRCLE_IMPORT;
        }
        else if(y>checkButton[ID_CHECK_CIRCLE_EXPORT].y && y<checkButton[ID_CHECK_CIRCLE_EXPORT].y+checkButton[ID_CHECK_CIRCLE_EXPORT].height)
        {
            motion=ID_CHECK_CIRCLE_EXPORT;
        }
        else if(y>checkButton[ID_CHECK_CIRCLE_CAL].y && y<checkButton[ID_CHECK_CIRCLE_CAL].y+checkButton[ID_CHECK_CIRCLE_CAL].height)
        {
            motion=ID_CHECK_CIRCLE_CAL;
        }
        /*else if(y>checkButton[ID_CHECK_CIRCLE_DELETE].y && y<checkButton[ID_CHECK_CIRCLE_DELETE].y+checkButton[ID_CHECK_CIRCLE_DELETE].height)
        {
            motion=ID_CHECK_CIRCLE_DELETE;
        }
        else if(y>checkButton[ID_CHECK_CIRCLE_ADD].y && y<checkButton[ID_CHECK_CIRCLE_ADD].y+checkButton[ID_CHECK_CIRCLE_ADD].height)
        {
            motion=ID_CHECK_CIRCLE_ADD;
        }*/
        else
        {
            motion=ID_CHECK_NONE;
        }
    }
    panelCircleButton->Refresh();
}

void CheckUpDlg::OnLeaveCircleButton(wxMouseEvent& event)
{
    motion=ID_CHECK_NONE;
    panelCircleButton->Refresh();
}

void CheckUpDlg::OnClickCircleButton(wxMouseEvent& event)
{
    if(motion==ID_CHECK_CIRCLE_CAL)
    {
        motion1=ID_CHECK_CIRCLE_CAL;
        if(circleFit.Solv())
        {
            int nh,nv;
            double l,x0,y0,z0,ho,vo;
            int a2z=cli->prj.a2z;
            nh=road_number_horizon(&cli->r);
            nv=road_number_vertical(&cli->r);
            if((nh>2||nv>2)||cli->nRoad>2)
            {
                if(cli->prj.dta==0)
                {
                    road_xy2l(&cli->r,circleFit.center[0],circleFit.center[1],&l,&x0,&y0,0,&ho);
                    road_l2h(&cli->r,l,&z0,0);
                }
                else
                {

                }
                vo=circleFit.center[2]-z0;
                double xt,yt,zt,lt;
                xt=circleFit.center[0]+circleFit.normal[0];
                yt=circleFit.center[1]+circleFit.normal[1];
                if(cli->prj.dta==0)
                    road_xy2l(&cli->r,circleFit.center[0],circleFit.center[1],&lt,0,0,0,0);
                else

                ///wxMessageBox(wxString::Format(_("原始法向量：%lf,%lf,%lf"),circleFit.normal[0],circleFit.normal[1],circleFit.normal[2]));
                if(lt>l&&cli->prj.mile1>cli->prj.mile2)
                {
                    circleFit.normal[0]*=-1;
                    circleFit.normal[1]*=-1;
                    circleFit.normal[2]*=-1;
                    ho*=a2z;

                }
                else if(lt<l&&cli->prj.mile1<=cli->prj.mile2)
                {
                    circleFit.normal[0]*=-1;
                    circleFit.normal[1]*=-1;
                    circleFit.normal[2]*=-1;
                }
                ///wxMessageBox(wxString::Format(_("后面法向量：%lf,%lf,%lf"),circleFit.normal[0],circleFit.normal[1],circleFit.normal[2]));
            }
            int n;
            n=circleFit.data.size();
            for(int i=0;i<n;i++)
            {
                if(circleFit.data[i].used)
                {
                    circleGrid->SetCellValue(i,5,wxString::Format(_("%.4lf"),circleFit.data[i].dc));
                    circleGrid->SetCellValue(i,6,wxString::Format(_("%.4lf"),circleFit.data[i].dp));
                }
                else
                {
                    circleGrid->SetCellValue(i,5,wxEmptyString);
                    circleGrid->SetCellValue(i,6,wxEmptyString);
                }
            }
            panelCircleFig->Refresh();
        }
    }
    else if(motion==ID_CHECK_CIRCLE_EXPORT)
    {
        wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("文本文档(*.txt)|*.txt"),wxFD_SAVE);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            if(wxFileExists(strFile))
            {
                int rs=wxMessageBox(_("文件已存在,是否覆盖?"),_("提示"),wxYES|wxNO);
                if(rs==wxYES)
                    wxRemoveFile(strFile);
                else
                    return;
            }
            FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
            if(fp)
            {
                wxString txtstr;
                int n;
                int x1,x2,x3,x4,x5;
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                txtstr=_("                                           空间圆拟合\n");
                fprintf(fp,txtstr.mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                time_t now;
                time(&now);
                txtstr=wxDateTime(now).Format(_("%Y-%m-%d %H:%M:%S"));
                txtstr=txtstr+_("\n");
                fprintf(fp,txtstr.mb_str(wxConvLocal));
                txtstr=_("------------------------------------------------------------------------------------------------\n");
                fprintf(fp,txtstr.mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                txtstr=_("                              北坐标(X)         ");
                x1=txtstr.length();
                txtstr=_("                              北坐标(X)         东坐标(Y)         ");
                x2=txtstr.length();
                txtstr=_("                              北坐标(X)         东坐标(Y)         高程(Z)\n");
                fprintf(fp,txtstr.mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                txtstr=_("圆心坐标                      ");
                txtstr=txtstr+wxString::Format(_("%.4f"),circleFit.center[0]);
                n=txtstr.length();
                while(n<x1-1)
                {
                    txtstr=txtstr+_(" ");
                    n=txtstr.length();
                }

                txtstr=txtstr+wxString::Format(_("%.4f"),circleFit.center[1]);

                n=txtstr.length();
                while(n<x2+2)
                {
                    txtstr=txtstr+_(" ");
                    n=txtstr.length();
                }

                txtstr=txtstr+wxString::Format(_("%.4f"),circleFit.center[2]);
                fprintf(fp,txtstr.mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));

                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                txtstr=_("圆面向量                      ");
                txtstr=txtstr+wxString::Format(_("%.4f"),circleFit.normal[0]);
                n=txtstr.length();
                while(n<x1-1)
                {
                    txtstr=txtstr+_(" ");
                    n=txtstr.length();
                }
                txtstr=txtstr+wxString::Format(_("%.4f"),circleFit.normal[1]);

                n=txtstr.length();
                while(n<x2+2)
                {
                    txtstr=txtstr+_(" ");
                    n=txtstr.length();
                }
                txtstr=txtstr+wxString::Format(_("%.4f"),circleFit.normal[2]);
                fprintf(fp,txtstr.mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));

                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                txtstr=_("设计坐标                      ");
                txtstr=txtstr+wxString::Format(_("%.4f"),x0);
                n=txtstr.length();
                while(n<x1-1)
                {
                    txtstr=txtstr+_(" ");
                    n=txtstr.length();
                }
                txtstr=txtstr+wxString::Format(_("%.4f"),y0);

                n=txtstr.length();
                while(n<x2+2)
                {
                    txtstr=txtstr+_(" ");
                    n=txtstr.length();
                }
                txtstr=txtstr+wxString::Format(_("%.4f"),z0);
                fprintf(fp,txtstr.mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));

                txtstr=_("                              里程              水平偏差(mm)      垂直偏差(mm)\n");
                fprintf(fp,txtstr.mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                txtstr=_("                              ")+wxString::Format(_("%.4f"),l);
                n=txtstr.length();
                while(n<x1+3)
                {
                    txtstr=txtstr+_(" ");
                    n=txtstr.length();
                }
                txtstr=txtstr+wxString::Format(_("%.1f"),ho);
                n=txtstr.length();
                while(n<x2+6)
                {
                    txtstr=txtstr+_(" ");
                    n=txtstr.length();
                }
                txtstr=txtstr+wxString::Format(_("%.1f"),vo);
                fprintf(fp,txtstr.mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));

                txtstr=_("拟合半径                      ");
                txtstr=txtstr+wxString::Format(_("%.4f"),circleFit.radius);
                fprintf(fp,txtstr.mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));

                txtstr=_("点号                          ");
                x1=txtstr.length();
                txtstr=_("点号                          北坐标(X)      ");
                x2=txtstr.length();
                txtstr=_("点号                          北坐标(X)      东坐标(Y)      ");
                x3=txtstr.length();
                txtstr=_("点号                          北坐标(X)      东坐标(Y)      高程(Z)    ");
                x4=txtstr.length();
                txtstr=_("点号                          北坐标(X)      东坐标(Y)      高程(Z)    平面度(mm)   ");
                x5=txtstr.length();

                txtstr=_("点号                          北坐标(X)      东坐标(Y)      高程(Z)    平面度(mm)   圆度(mm)\n");
                fprintf(fp,txtstr.mb_str(wxConvLocal));

                int m=circleFit.data.size();
                for(int i=0;i<m;i++)
                {
                    if(circleFit.data[i].used)
                    {
                        txtstr=wxString::Format(_("%d"),i+1);
                        n=txtstr.length();
                        while(n<x1+2)
                        {
                            txtstr=txtstr+_(" ");
                            n=txtstr.length();
                        }
                        txtstr=txtstr+wxString::Format(_("%.4f"),circleFit.data[i].x);
                        n=txtstr.length();
                        while(n<x2+5)
                        {
                            txtstr=txtstr+_(" ");
                            n=txtstr.length();
                        }
                        txtstr=txtstr+wxString::Format(_("%.4f"),circleFit.data[i].y);
                        n=txtstr.length();
                        while(n<x3+8)
                        {
                            txtstr=txtstr+_(" ");
                            n=txtstr.length();
                        }
                        txtstr=txtstr+wxString::Format(_("%.4f"),circleFit.data[i].z);
                        n=txtstr.length();
                        while(n<x4+10)
                        {
                            txtstr=txtstr+_(" ");
                            n=txtstr.length();
                        }
                        txtstr=txtstr+wxString::Format(_("%.1f"),circleFit.data[i].dc*1000.0);
                        n=txtstr.length();
                        while(n<x5+13)
                        {
                            txtstr=txtstr+_(" ");
                            n=txtstr.length();
                        }
                        txtstr=txtstr+wxString::Format(_("%.1f"),circleFit.data[i].dp*1000.0);
                        fprintf(fp,txtstr.mb_str(wxConvLocal));
                        fprintf(fp,wxString(_("\n")).mb_str(wxConvLocal));
                    }
                }

                fclose(fp);

            }
        }

    }
    else if(motion==ID_CHECK_CIRCLE_IMPORT)
    {
        motion1=ID_CHECK_CIRCLE_IMPORT;
        wxFileDialog dlg(this,_("洞门测量数据"),wxEmptyString,wxEmptyString,_("洞门测量数据(*.csv)|*.csv"),wxFD_SAVE);
        dlg.Center();
        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str1 = dlg.GetPath();
            char path[1024];
            char buf[1024];
            char mark[64];
            char coor1[64];
            char coor2[64];
            char coor3[64];
            int index = 0;
            int i = 0;

            int row=circleGrid->GetNumberRows();
            circleGrid->DeleteRows(0,row);

            strcpy(path,str1.mb_str(wxConvLocal));
            FILE* fp=fopen(path,"r");

            if(fp)
            {
                wxString valstr;
                double x,y,z;
                circleFit.data.clear();
                while(!feof(fp))
                {
                    fgets(buf,1024,fp);
                    if(sscanf(buf,"%[^,],%[^,],%[^,],%s",mark,coor1,coor2,coor3)==4)
                    {
                        if(index>0)
                        {
                            int j=0;
                            circleGrid->AppendRows(1,true);
                            circleGrid->SetCellValue(i,j++,wxString::Format(_("%d"),i+1));
                            valstr = wxString(coor1,wxConvUTF8);
                            valstr.ToDouble(&x);
                            circleGrid->SetCellValue(i,j++,wxString::Format(_("%.4f"),x));
                            valstr = wxString(coor2,wxConvUTF8);
                            valstr.ToDouble(&y);
                            circleGrid->SetCellValue(i,j++,wxString::Format(_("%.4f"),y));
                            valstr = wxString(coor3,wxConvUTF8);
                            valstr.ToDouble(&z);
                            circleGrid->SetCellValue(i,j++,wxString::Format(_("%.4f"),z));
                            circleGrid->SetCellValue(i,j++,wxString::Format(_("%d"),1));
                            circleFit.AddData(x,y,z,1);
                            i++;
                        }
                        index++;
                    }
                }
            }
            fclose(fp);
        }
    }
    panelCircleButton->Refresh();
}

void CheckUpDlg::OnPaintCircleFig(wxPaintEvent& event)
{
    ///FILE* fp;
    ///fp=fopen("D:\\tmp\\circle.txt","w");
    wxPaintDC dc(panelCircleFig);
    int w,h;
    panelCircleFig->GetClientSize(&w,&h);
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
        int x,y,R;
        x=w/2;
        y=h/2;
        R=90;
        memDC.DrawCircle(x,y,R);
        memDC.DrawLabel(wxString::Format(_("O")),wxRect(x+5,y+8,5,-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(0,0,0)));
        memDC.DrawLine(x-5,y,x+5,y);
        memDC.DrawLine(x,y-5,x,y+5);

        memDC.SetPen(wxPen(wxColor(0,0,0)));
        memDC.DrawCircle(x,y,2);
        double x1,y1,z1;
        x1=circleFit.center[0];
        y1=circleFit.center[1];
        z1=circleFit.center[2];

        double sx,pitch,angle;
        transform3d_t t;
        vector3d_t v;
        if(circleFit.fit)
        {
            if(fabs(circleFit.radius)>0.000001)
            {
                ///fprintf(fp,"x1=%lf,y1=%lf,z1=%lf\n",x1,y1,z1);
                sx=R/circleFit.radius;
                ///fprintf(fp,"sx=%lf,r=%lf",sx,circleFit.radius);
                v.x=circleFit.normal[0];
                v.y=circleFit.normal[1];
                v.z=circleFit.normal[2];
                ///fprintf(fp,"vx=%lf,vy=%lf,vz=%lf\n",v.x,v.y,v.z);
                double len = vector3d_length(&v);
                pitch=asin(v.z/len);
                angle=atan2(v.y,v.x);
                transform3d_init(&t,0,pitch,-angle,x1,y1,z1,1);
                ///fprintf(fp,"pitch=%lf,angle=%lf,vz=%lf,x1=%lf,y1=%lf,z1=%lf\n",pitch,angle,x1,y1,z1);

                point3d_t p[2];
                int n;
                n=circleFit.data.size();
                for(int i=0;i<n;i++)
                {
                    p[0].x = circleFit.data[i].x;
                    p[0].y = circleFit.data[i].y;
                    p[0].z = circleFit.data[i].z;
                    transform3d_revtrans(&t,&p[0],&p[1]);
                    ///fprintf(fp,"%d,x0=%lf,y0=%lf,z0=%lf\n",i+1,p[0].x,p[0].y,p[0].z);
                    ///fprintf(fp,"x1=%lf,y1=%lf,z1=%lf\n",p[1].x,p[1].y,p[1].z);
                    if(circleFit.data[i].used)
                    {
                        memDC.SetPen(wxPen(wxColor(0,0,0)));
                    }
                    else
                    {
                        memDC.SetPen(wxPen(wxColor(0,0,255)));
                    }
                    x=p[1].y*sx+w/2;
                    y=-p[1].z*sx+h/2;
                    memDC.SetBrush(wxBrush(wxColor(0,0,0)));
                    memDC.DrawCircle(x,y,3);
                    ///fprintf(fp,"x=%d,y=%d\n",x,y);
                    memDC.SetBrush(wxBrush(wxColor(255,255,255)));
                    memDC.DrawLabel(wxString::Format(_("%d"),i+1),wxRect(x+5,y+8,5,-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                    memDC.SetPen(wxPen(wxColor(0,0,0)));
                }

                int nh,nv;
                nh=road_number_horizon(&cli->r);
                nv=road_number_vertical(&cli->r);
                ///double l,x0,y0,z0,ho,vo;
                if((nh>2||nv>2)||cli->nRoad>=2)
                {
                    p[0].x=x0;
                    p[0].y=y0;
                    p[0].z=z0;
                    transform3d_revtrans(&t,&p[0],&p[1]);

                    x=p[1].y*sx+w/2;
                    y=-p[1].z*sx+h/2;
                    memDC.SetBrush(wxBrush(wxColor(0,0,0)));
                    memDC.DrawCircle(x,y,2);
                    memDC.DrawLabel(wxString::Format(_("O'")),wxRect(x+5,y+8,5,-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                    memDC.SetPen(wxPen(wxColor(0,255,0)));
                    memDC.DrawLine(x-5,y,x+5,y);
                    memDC.DrawLine(x,y-5,x,y+5);

                    int x2,y2,w2,h2;
                    x2=20;
                    y2=5;
                    w2=40;
                    h2=20;
                    memDC.DrawLabel(_("实测中心"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//                    y2+=20;
//                    memDC.DrawLabel(_("X"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("X:%.4f"),circleFit.center[0]),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//                    y2+=20;
//                    memDC.DrawLabel(_("Y"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("Y:%.4f"),circleFit.center[1]),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//                    y2+=20;
//                    memDC.DrawLabel(_("Z"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("Z:%.4f"),circleFit.center[2]),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

                    y2+=30;
                    memDC.DrawLabel(_("设计中心"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//                    y2+=20;
//                    memDC.DrawLabel(_("X"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("X:%.4f"),x0),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//                    y2+=20;
//                    memDC.DrawLabel(_("Y"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("Y:%.4f"),y0),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
//                    y2+=20;
//                    memDC.DrawLabel(_("Z"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("Z:%.4f"),z0),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

                    y2+=25;
                    //memDC.DrawLabel(wxString::Format(_("半径")),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    //y2+=20;
                    memDC.DrawLabel(wxString::Format(_("半径:%.4f"),circleFit.radius),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

                    x2=w-80;
                    y2=5;
                    memDC.DrawLabel(_("里程"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("%.4f"),l),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(_("水平偏差(mm)"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("%.1f"),ho*1000.0),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(_("垂直偏差(mm)"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("%.1f"),vo*1000.0),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    int x2,y2,w2,h2;
                    x2=10;
                    y2=5;
                    w2=30;
                    h2=20;
                    memDC.DrawLabel(_("实测中心"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    //y2+=20;
                    //memDC.DrawLabel(_("X"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("X:%.4f"),circleFit.center[0]),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    //y2+=20;
                    //memDC.DrawLabel(_("Y"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("Y:%.4f"),circleFit.center[1]),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    //y2+=20;
                    //memDC.DrawLabel(_("Z"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    y2+=20;
                    memDC.DrawLabel(wxString::Format(_("Z:%.4lf"),circleFit.center[2]),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

                    y2+=25;
                    //memDC.DrawLabel(wxString::Format(_("半径")),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                    ///y2+=20;
                    memDC.DrawLabel(wxString::Format(_("半径:%.4f"),circleFit.radius),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }
            }
        }
        ///fclose(fp);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void CheckUpDlg::OnPaintCircleGrid(wxPaintEvent& event)
{
    wxPaintDC dc(panelCircleGrid);
    int w,h;
    panelCircleGrid->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        //background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;

        int x2,y2;

        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=circleGrid->GetColSize(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=circleGrid->GetColSize(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("X"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=circleGrid->GetColSize(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("Y"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=circleGrid->GetColSize(3);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("Z"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=circleGrid->GetColSize(4);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("选取"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=circleGrid->GetColSize(5);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("平面度"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=circleGrid->GetColSize(6);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("圆度"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        x1=1;
        w1=circleGrid->GetColSize(0);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=circleGrid->GetColSize(1);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=circleGrid->GetColSize(2);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=circleGrid->GetColSize(3);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=circleGrid->GetColSize(4);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=circleGrid->GetColSize(5);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=circleGrid->GetColSize(6);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void CheckUpDlg::OnGridCirDataKillFocus(wxFocusEvent& event)
{
    if(circleFit.data.size()>0)
    {
        int row,col;
        row=circleGrid->GetCursorRow();
        col=circleGrid->GetCursorColumn();
        if(col==4)
        {
            if(!circleGrid->IsMouseInWindow())return;
            if(circleGrid->GetCellValue(row,col).IsEmpty())
            {
                circleGrid->SetCellValue(row,col,_("1"));
                circleFit.data[row].used=true;
            }
            else
            {
                circleGrid->SetCellValue(row,col,_(""));
                circleFit.data[row].used=false;
            }
            circleGrid->SetGridCursor(row,col);
        }
    }
    event.Skip();
}

void CheckUpDlg::OnPaintTestFig(wxPaintEvent& event)
{
    wxPaintDC dc(testFig);
    int w,h;
    testFig->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        //background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        int x=0;
        int y=0;

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
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void CheckUpDlg::OnDoubleClickTestFig(wxMouseEvent& event)
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
            testFig->Refresh();
            //wxMessageBox(wxString::Format(_("%d"),ret));
        }
    }
}


