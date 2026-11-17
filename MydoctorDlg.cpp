///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MydoctorDlg.h"
#include "mtg_t_svrMain.h"
#include "mtg_t_svrApp.h"
//#include "confirmdlg.h"
#include "RingListDlg.h"
//#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MydoctorDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MydoctorDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MydoctorDlg)

//*)

MydoctorDlg::MydoctorDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPage = new wxPanel(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    int x1,y1,w1,h1;
    x1=7;
    y1=59;
    w1=w-x1*2;
    h1=h-114;

    panelSeged = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSeg = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSeging = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    //panelMain->SetBackgroundColour(wxColor(238,244,250));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelSeg->SetBackgroundColour(wxColor(238,244,250));
    panelSeg->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelSeging->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelSeging->SetBackgroundColour(wxColor(238,244,250));
    panelSeging->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelSeg->Show(false);
    panelSeging->Show(false);

    int x2,y2,w2,h2;
    x2=0;
    y2=0;
    w2=w1;
    h2=40;

    segedListHeader = new wxPanel(panelSeged, wxID_ANY, wxPoint(0,0), wxSize(w1,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    segedListHeader->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    segedList = new wxListView(panelSeged, wxID_ANY, wxPoint(0,24), wxSize(w1,h1-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    segbuttons = new wxPanel(panelSeg, wxID_ANY, wxPoint(1,1), wxSize(120,h1-2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    segbuttons->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    lastSegText = new wxPanel(panelSeg, wxID_ANY, wxPoint(128,8), wxSize(w1-135,h1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    lastSegText->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    last_numb_Text = new wxMyTextCtrl(lastSegText, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    gapText = new wxPanel(panelSeg, wxID_ANY, wxPoint(128,8), wxSize(w1-135,h1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    gapText->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    gapText->Show(false);
    tbm_lgap_Text = new wxMyTextCtrl(gapText, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    tbm_rgap_Text = new wxMyTextCtrl(gapText, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    tbm_ugap_Text = new wxMyTextCtrl(gapText, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    tbm_dgap_Text = new wxMyTextCtrl(gapText, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    segText = new wxPanel(panelSeg, wxID_ANY, wxPoint(128,8), wxSize(w1-135,h1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    segText->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    segText->Show(false);
    selectionText = new wxPanel(panelSeg, wxID_ANY, wxPoint(128,8), wxSize(w1-135,h1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    selectionText->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    selectionText->Show(false);

    nextSegs = new wxPanel(panelSeg, wxID_ANY, wxPoint(128,8), wxSize(w1-135,h1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    nextSegs->Show(false);
    segListHeader = new wxPanel(nextSegs, wxID_ANY, wxPoint(0,0), wxSize(w1-135,24), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    segListHeader->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    segList = new wxListView(nextSegs, wxID_ANY, wxPoint(0,24), wxSize(w1-135,h1-54), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelJust = new wxPanel(panelSeg, wxID_ANY, wxPoint(128,8), wxSize(w1-135,h1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelJust->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelJust->Show(false);
    just_uaj_Text = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    just_daj_Text = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    just_laj_Text = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    just_raj_Text = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);

    just_headh_Text = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    just_headv_Text = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    just_tailh_Text = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    just_tailv_Text = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);

    desbuttons = new wxPanel(panelSeging, wxID_ANY, wxPoint(1,1), wxSize(120,h1-2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desbuttons->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    desOneText = new wxPanel(panelSeging, wxID_ANY, wxPoint(128,8), wxSize(w1-135,h1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desOneText->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //desOneText->Show(false);
    des_mile_Text = new wxMyTextCtrl(desOneText, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    des_numb_Text = new wxMyTextCtrl(desOneText, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);

    dtaText = new wxPanel(panelSeging, wxID_ANY, wxPoint(128,8), wxSize(w1-135,h1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    dtaText->SetBackgroundColour(wxColor(238,244,250));
    dtaText->Show(false);
    dtaPanel = new wxPanel(dtaText, wxID_ANY, wxPoint(0,0), wxSize(280,h1-30), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    dtaPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    dtaList = new wxListView(dtaPanel, wxID_ANY, wxPoint(0,24), wxSize(280,h1-54), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    dtaFig = new wxPanel(dtaText, wxID_ANY, wxPoint(287,0), wxSize(w1-426,h1-30), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    dtaFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    desListText = new wxPanel(panelSeging, wxID_ANY, wxPoint(128,8), wxSize(w1-135,h1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desListText->SetBackgroundColour(wxColor(238,244,250));
    desListText->Show(false);
    desListHeader = new wxPanel(desListText, wxID_ANY, wxPoint(0,0), wxSize(w1-135,24), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desListHeader->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    desList = new wxListView(desListText, wxID_ANY, wxPoint(0,24), wxSize(w1-135,h1-54), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    //segList->Show(false);
    //desList->Show(false);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintMain,0,this);

	panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MydoctorDlg::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MydoctorDlg::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MydoctorDlg::OnClickPage,0,this);

    segedListHeader->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintSegedListHeader,0,this);

    panelSeg->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintSeg,0,this);
    panelSeging->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintSeging,0,this);

    lastSegText->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintLast,0,this);
    lastSegText->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MydoctorDlg::OnMotionLast,0,this);
    lastSegText->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MydoctorDlg::OnLeaveLast,0,this);
    lastSegText->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MydoctorDlg::OnClickLast,0,this);

    gapText->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintGapText,0,this);
    segText->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintSegText,0,this);
    selectionText->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintSelection,0,this);
    selectionText->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MydoctorDlg::OnMotionSelection,0,this);
    selectionText->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MydoctorDlg::OnLeaveSelection,0,this);
    selectionText->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MydoctorDlg::OnClickSelection,0,this);

    segbuttons->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintSegButton,0,this);
    segbuttons->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MydoctorDlg::OnMotionSegButton,0,this);
    segbuttons->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MydoctorDlg::OnLeaveSegButton,0,this);
    segbuttons->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MydoctorDlg::OnClickSegButton,0,this);

    desbuttons->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintDesButton,0,this);
    desbuttons->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MydoctorDlg::OnMotionDesButton,0,this);
    desbuttons->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MydoctorDlg::OnLeaveDesButton,0,this);
    desbuttons->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MydoctorDlg::OnClickDesButton,0,this);

    desOneText->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintOne,0,this);
    desOneText->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MydoctorDlg::OnMotionOne,0,this);
    desOneText->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MydoctorDlg::OnLeaveOne,0,this);
    desOneText->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MydoctorDlg::OnClickOne,0,this);

    dtaPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintDtaHeader,0,this);

    dtaFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintDtaFig,0,this);
    dtaFig->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MydoctorDlg::OnMotionDtaFig,0,this);
    dtaFig->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MydoctorDlg::OnLeaveDtaFig,0,this);
    dtaFig->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MydoctorDlg::OnClickDtaFig,0,this);

    desListHeader->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintDeslistHeader,0,this);
    segListHeader->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintSeglistHeader,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MydoctorDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MydoctorDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MydoctorDlg::OnClickBottom,0,this);

    panelJust->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintJust,0,this);
    panelJust->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MydoctorDlg::OnMotionJust,0,this);
    panelJust->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MydoctorDlg::OnLeaveJust,0,this);
    panelJust->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MydoctorDlg::OnClickJust,0,this);

    segList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&MydoctorDlg::OnSegSelect,0,this);
    dtaList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&MydoctorDlg::OnDtaSelect,0,this);
    //*)
    //Connect(wxEVT_TIMER,(wxObjectEventFunction)&MydoctorDlg::OnTimer);
    //timerStat.SetOwner(this);
    //timerStat.Start(100,false);

    this->SetBackgroundColour(wxColor(245,248,250));

    page=ID_RNG_PAGE_DONE;
    segpage=ID_RNG_SEG_PRE;
    despage=ID_RNG_DES_ONE;
    motion=ID_RNG_NONE;
    checkBoxWidth=14;
    checkBoxHeight=14;
    radioBoxR1=7;
    radioBoxR2=4;

    Mtype=0;
    Msg=wxEmptyString;
    int nk = mtg->segset.Ks;

    int i=0;
    segedList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    segedList->InsertColumn(i++,_("环号"),wxLIST_FORMAT_CENTRE,65);
    segedList->InsertColumn(i++,_("类型"),wxLIST_FORMAT_LEFT,65);
    segedList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_LEFT,90);
    segedList->InsertColumn(i++,_("点位"),wxLIST_FORMAT_LEFT,65);
    segedList->InsertColumn(i++,_("水平偏差"),wxLIST_FORMAT_LEFT,75);
    segedList->InsertColumn(i++,_("垂直偏差"),wxLIST_FORMAT_LEFT,75);
    segedList->InsertColumn(i++,_("水平超前量"),wxLIST_FORMAT_LEFT,75);
    segedList->InsertColumn(i++,_("垂直超前量"),wxLIST_FORMAT_LEFT,75);
    segedList->InsertColumn(i++,_("日期"),wxLIST_FORMAT_LEFT,140);
    i=0;
    segList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    segList->InsertColumn(i++,_("环号"),wxLIST_FORMAT_CENTRE,60);
    segList->InsertColumn(i++,_("类型"),wxLIST_FORMAT_CENTRE,70);
    segList->InsertColumn(i++,_("点位"),wxLIST_FORMAT_CENTRE,70);
    segList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,95);
    segList->InsertColumn(i++,_("左超前"),wxLIST_FORMAT_CENTRE,70);
    segList->InsertColumn(i++,_("上超前"),wxLIST_FORMAT_CENTRE,70);
    segList->InsertColumn(i++,_("水平偏差"),wxLIST_FORMAT_CENTRE,70);
    segList->InsertColumn(i++,_("垂直偏差"),wxLIST_FORMAT_CENTRE,70);

    i=0;
    dtaList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    dtaList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,55);
    dtaList->InsertColumn(i++,_("起点里程"),wxLIST_FORMAT_CENTRE,90);
    dtaList->InsertColumn(i++,_("终点里程"),wxLIST_FORMAT_CENTRE,90);

    i=0;
    desList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    desList->InsertColumn(i++,_("环号"),wxLIST_FORMAT_CENTRE,60);
    desList->InsertColumn(i++,_("类型"),wxLIST_FORMAT_CENTRE,70);
    desList->InsertColumn(i++,_("点位"),wxLIST_FORMAT_CENTRE,70);
    desList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,95);
    desList->InsertColumn(i++,_("左超前"),wxLIST_FORMAT_CENTRE,70);
    desList->InsertColumn(i++,_("上超前"),wxLIST_FORMAT_CENTRE,70);
    desList->InsertColumn(i++,_("水平偏差"),wxLIST_FORMAT_CENTRE,70);
    desList->InsertColumn(i++,_("垂直偏差"),wxLIST_FORMAT_CENTRE,70);

    dtaList->DeleteAllItems();
    wxString istr;
    int nh=road_number_horizon(&mtg->r);
    h_element* he;

    int index=0;
    i=1;
    while(i<nh)
    {
        he=road_horizon(&mtg->r,i);
        if(he->type==ROAD_TYPE_LINE)
        {
            dtaList->InsertItem(index,_(""));
            dtaList->SetItem(index,1,wxString::Format(_("%d"),index+1)); ///
            dtaList->SetItem(index,2,_("直线")); ///
            dtaList->SetItem(index,3,wxString::Format(_("%.3f"),he->l1)); ///
            index++;
        }
        else if(he->type==ROAD_TYPE_SPIRAL)
        {
            dtaList->InsertItem(index,_(""));
            dtaList->SetItem(index,1,wxString::Format(_("%d"),index+1)); ///
            dtaList->SetItem(index,2,_("缓和曲线")); ///
            dtaList->SetItem(index,3,wxString::Format(_("%.3f"),he->l1)); ///
            index++;
        }
        else if(he->type==ROAD_TYPE_ARC)
        {
            dtaList->InsertItem(index,_(""));
            dtaList->SetItem(index,1,wxString::Format(_("%d"),index+1)); ///
            dtaList->SetItem(index,2,_("园曲线")); ///
            dtaList->SetItem(index,3,wxString::Format(_("%.3f"),he->l1)); ///
            index++;
        }
        i++;
    }

    dtaList->Select(0);

    just_uaj_Text->SetValue(_("1720"));
    just_daj_Text->SetValue(_("1720"));
    just_laj_Text->SetValue(_("1710"));
    just_raj_Text->SetValue(_("1730"));
    just_headh_Text->SetValue(_("20"));
    just_headv_Text->SetValue(_("10"));
    just_tailh_Text->SetValue(_("-10"));
    just_tailv_Text->SetValue(_("-5"));
    //mtg->m.head[0]=395052.39;
    //mtg->m.head[1]=532402.137;
    //mtg->m.head[2]=8.934;
    //mtg->m.tail[0]=395048.947;
    //mtg->m.tail[1]=532401.084;
    //mtg->m.tail[2]=8.927;
    //mtg->m.inc1[2]=17.00561955;
    //mtg->m.inc1[1]=0.111395178;
    //road_xy2l(&mtg->r,mtg->m.head[0],mtg->m.head[1],&mtg->m.headc,0,0,0,&mtg->m.headh);
    //road_xy2l(&mtg->r,mtg->m.tail[0],mtg->m.tail[1],&mtg->m.tailc,0,0,0,&mtg->m.tailh);
    LoadData();
}

MydoctorDlg::~MydoctorDlg()
{

}
void MydoctorDlg::LoadData()
{
    int cal=0;
    int inum;
    if(mtg->segs[10].t<=0)
    {
        inum=mtg->m.iseg-1;
        cal=1;
    }

    for(int i=0;i<MAX_SEG;i++)
    {
        if(cal==1)
        {
            mtg->segs[i].numb=inum-10+i;
            if(mtg->segset.type==0) mtg->segs[i].type=0;
            else mtg->segs[i].type=0;
        }
        isegs[i]=mtg->segs[i];
    }

    if(mtg->segs[11].t<=0)
    {
        mtg_init_position(mtg);
        mtg_std_segs(mtg,0);
    }

    UpdateSegs();
    last_numb_Text->SetValue(wxString::Format(_("%d"),isegs[0].numb));
    //UpdateSegs();
    tbm_lgap_Text->SetValue(wxString::Format(_("%.1f"),mtg->segs[1].gap[2]*1000));
    tbm_rgap_Text->SetValue(wxString::Format(_("%.1f"),mtg->segs[1].gap[3]*1000));
    tbm_ugap_Text->SetValue(wxString::Format(_("%.1f"),mtg->segs[1].gap[0]*1000));
    tbm_dgap_Text->SetValue(wxString::Format(_("%.1f"),mtg->segs[1].gap[1]*1000));

    //InitialSeging();
    mtg_init_seging(mtg);
    des_numb_Text->SetValue(wxString::Format(_("%d"),mtg->iseg.numb));
    des_mile_Text->SetValue(wxString::Format(_("%.3f"),mtg->iseg.headc));
    //trace(0,"segment:cal=%d\n",cal);
    res=0;
    nres=0;
    nres=mtg_std_segings(mtg,&res);
    UpdateSegings();

    nseged=0;
    if(seged) free(seged);
    seged=0;
    nseged=mtg_query_segeds(mtg,&seged);
    UpdateSeged();
    modified=0;
}

void MydoctorDlg::InitialPosition()
{
    double ugap,dgap,lgap,rgap;
    long num;
    last_numb_Text->GetValue().ToLong(&num);
    tbm_ugap_Text->GetValue().ToDouble(&ugap);
    tbm_dgap_Text->GetValue().ToDouble(&dgap);
    tbm_lgap_Text->GetValue().ToDouble(&lgap);
    tbm_rgap_Text->GetValue().ToDouble(&rgap);
    ugap=ugap/1000.0;
    dgap=dgap/1000.0;
    lgap=lgap/1000.0;
    rgap=rgap/1000.0;
    if(ugap!=mtg->segs[10].gap[0] ||
       dgap!=mtg->segs[10].gap[1] ||
       lgap!=mtg->segs[10].gap[2] ||
       rgap!=mtg->segs[10].gap[3] ||
       num!=mtg->segs[10].numb)
    {
        //wxMessageBox(_("ok"));
        mtg->segs[10].gap[0]=ugap;
        mtg->segs[10].gap[1]=dgap;
        mtg->segs[10].gap[2]=lgap;
        mtg->segs[10].gap[3]=rgap;
        mtg->segs[10].numb=num;
        mtg_init_position(mtg);
        mtg_std_segs(mtg,0);
        UpdateSegs();
    }
}

void MydoctorDlg::InitialSeging()
{
    double mile;
    long numb;
    des_mile_Text->GetValue().ToDouble(&mile);
    des_numb_Text->GetValue().ToLong(&numb);
    if(mtg->prj.a2z==1) mile=mile+mtg->segset.L;
    else mile=mile-mtg->segset.L;
    //wxMessageBox(wxString::Format(_("%.4f"),mile));
    if(mile!=mtg->iseg.headc)
    {
        mtg_init_seging(mtg);
        nres=0;
        if(res) free(res);
        res=0;
        nres=mtg_std_segings(mtg,&res);
        UpdateSegings();
    }
    if(numb!=mtg->iseg.numb)
    {
        for(int i=1;i<nres;i++)
        {
            res[i].numb=res[i-1].numb+1;
        }
    }
}

void MydoctorDlg::OnSegSelect(wxListEvent& event)
{
    //isel=segList->GetFirstSelected();
    //panelSeg->Refresh();
}

void MydoctorDlg::OnDtaSelect(wxListEvent& event)
{
    //isel=segList->GetFirstSelected();
    dtaFig->Refresh();
}

void MydoctorDlg::UpdateSegs()
{
    segList->DeleteAllItems();
    wxString istr;
    int k=mtg->segset.Ks;
    //wxMessageBox(wxString::Format(_("%d"),mtg->segs[10].type));
    for(int i=10;i<MAX_SEG;i++)
    {
        int j=1;
        segList->InsertItem(i-10,_(""));
        segList->SetItem(i-10,j++,wxString::Format(_("%d"),mtg->segs[i].numb)); ///管片号
        if(mtg->segs[i].type==0) istr=_("通用环");
        else if(mtg->segs[i].type==1) istr=_("标准环");
        else if(mtg->segs[i].type==2) istr=_("左转弯");
        else if(mtg->segs[i].type==3) istr=_("右转弯");
        segList->SetItem(i-10,j++,istr); ///类型
        if(mtg->segs[i].k<k/2) istr=wxString::Format(_("%d"),mtg->segs[i].k+1);
        else istr=wxString::Format(_("%d"),mtg->segs[i].k+2);
        segList->SetItem(i-10,j++,istr); ///类型
        segList->SetItem(i-10,j++,wxString::Format(_("%.3f"),mtg->segs[i].mile)); ///
        segList->SetItem(i-10,j++,wxString::Format(_("%.1f"),mtg->segs[i].headh*1000.0)); ///
        segList->SetItem(i-10,j++,wxString::Format(_("%.1f"),mtg->segs[i].headv*1000.0)); ///
        segList->SetItem(i-10,j++,wxString::Format(_("%.1f"),mtg->segs[i].dh*1000.0)); ///
        segList->SetItem(i-10,j++,wxString::Format(_("%.1f"),mtg->segs[i].dv*1000.0)); ///
        //segList->SetItem(i,j++,wxString::Format(_("%.1f"),mtg->segs[i].tailh*1000.0)); ///
        //segList->SetItem(i,j++,wxString::Format(_("%.1f"),mtg->segs[i].tailv*1000.0)); ///
    }
    //segList->Select(isel);
}

void MydoctorDlg::UpdateSeged()
{
    segedList->DeleteAllItems();
    wxString istr;
    int k=mtg->segset.Ks;
    //wxMessageBox(wxString::Format(_("%d"),nseged));
    for(int i=0;i<nseged;i++)
    {
        int j=1;
        segedList->InsertItem(i,_(""));
        segedList->SetItem(i,j++,wxString::Format(_("%d"),seged[i].numb)); ///管片号
        if(seged[i].type==0) istr=_("通用环");
        else if(seged[i].type==1) istr=_("标准环");
        else if(seged[i].type==2) istr=_("左转弯");
        else if(seged[i].type==3) istr=_("右转弯");
        segedList->SetItem(i,j++,istr); ///类型
        segedList->SetItem(i,j++,wxString::Format(_("%.3f"),seged[i].mile)); ///
        if(seged[i].k<k/2) istr=wxString::Format(_("%d"),seged[i].k+1);
        else istr=wxString::Format(_("%d"),seged[i].k+2);
        segedList->SetItem(i,j++,istr); ///类型
        segedList->SetItem(i,j++,wxString::Format(_("%.1f"),seged[i].dh*1000.0)); ///
        segedList->SetItem(i,j++,wxString::Format(_("%.1f"),seged[i].dv*1000.0)); ///
        segedList->SetItem(i,j++,wxString::Format(_("%.1f"),seged[i].harc*1000.0)); ///
        segedList->SetItem(i,j++,wxString::Format(_("%.1f"),seged[i].varc*1000.0)); ///
        segedList->SetItem(i,j++,wxDateTime(seged[i].t).Format(_("%Y-%m-%d %H:%M:%S")));
    }
    //segList->Select(isel);
}

void MydoctorDlg::UpdateSegings()
{
    desList->DeleteAllItems();
    wxString istr;
    double ls,rs;
    int k=mtg->segset.Ks;

    for(int i=0;i<nres;i++)
    {
        int j=1;
        desList->InsertItem(i,_(""));
        desList->SetItem(i,j++,wxString::Format(_("%d"),res[i].numb)); ///管片号
        if(res[i].type==0) istr=_("通用环");
        else if(res[i].type==1) istr=_("标准环");
        else if(res[i].type==2) istr=_("左转弯");
        else if(res[i].type==3) istr=_("右转弯");
        desList->SetItem(i,j++,istr); ///类型
        if(res[i].k<k/2) istr=wxString::Format(_("%d"),res[i].k+1);
        else istr=wxString::Format(_("%d"),res[i].k+2);
        desList->SetItem(i,j++,istr); ///类型
        desList->SetItem(i,j++,wxString::Format(_("%.3f"),res[i].headc)); ///
        desList->SetItem(i,j++,wxString::Format(_("%.1f"),res[i].harc*1000.0)); ///
        desList->SetItem(i,j++,wxString::Format(_("%.1f"),res[i].varc*1000.0)); ///
        desList->SetItem(i,j++,wxString::Format(_("%.1f"),res[i].headh*1000.0)); ///
        desList->SetItem(i,j++,wxString::Format(_("%.1f"),res[i].headv*1000.0)); ///
        //desList->SetItem(i,j++,wxString::Format(_("%.1f"),mtg->segings[i].tailh*1000.0)); ///
        //desList->SetItem(i,j++,wxString::Format(_("%.1f"),mtg->segings[i].tailv*1000.0)); ///
    }
    //desList->Select(sel);
}

void MydoctorDlg::OnPaintBottom(wxPaintEvent& event)
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
        segButton[ID_RNG_BTN_QUIT].x=x1;
        segButton[ID_RNG_BTN_QUIT].y=y1;
        segButton[ID_RNG_BTN_QUIT].width=w1;
        segButton[ID_RNG_BTN_QUIT].height=h1;
        if(motion==ID_RNG_BTN_QUIT)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(icolor[0]);
        }
        //memDC.SetPen(wxPen(wxColor(117,117,117)));

        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("退出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1-w1-7;
        segButton[ID_RNG_BTN_APPLY].x=x1;
        segButton[ID_RNG_BTN_APPLY].y=y1;
        segButton[ID_RNG_BTN_APPLY].width=w1;
        segButton[ID_RNG_BTN_APPLY].height=h1;
        if(modified==0)
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        else if(motion==ID_RNG_BTN_APPLY)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("应用"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1-w1-7;
        segButton[ID_RNG_BTN_EXP].x=x1;
        segButton[ID_RNG_BTN_EXP].y=y1;
        segButton[ID_RNG_BTN_EXP].width=w1;
        segButton[ID_RNG_BTN_EXP].height=h1;
        if(motion==ID_RNG_BTN_EXP)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("导出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,0,w,0);

        x1=9;
        y1=9;
        h1=26;
        w1=h1*4/3;

        segButton[ID_RNG_PRT_SCN].x=x1;
        segButton[ID_RNG_PRT_SCN].y=y1;
        segButton[ID_RNG_PRT_SCN].width=w1;
        segButton[ID_RNG_PRT_SCN].height=h1;
        if(motion==ID_RNG_PRT_SCN)
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

        x1=w1+76;
        w1=w-x1*2;
        if(Mtype==0)
        {
            memDC.SetTextForeground(wxColor(0,0,255));
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,0,0));
        }
        //Msg=_("哈哈哈");
        if(Msg!=wxEmptyString) memDC.DrawLabel(_(" ！ ")+Msg,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>segButton[ID_RNG_BTN_QUIT].y && y<segButton[ID_RNG_BTN_QUIT].y+segButton[ID_RNG_BTN_QUIT].height)
    {
        if(x>segButton[ID_RNG_BTN_QUIT].x && x<segButton[ID_RNG_BTN_QUIT].x+segButton[ID_RNG_BTN_QUIT].width)
        {
            motion=ID_RNG_BTN_QUIT;
        }
        else if(x>segButton[ID_RNG_BTN_APPLY].x && x<segButton[ID_RNG_BTN_APPLY].x+segButton[ID_RNG_BTN_APPLY].width)
        {
            motion=ID_RNG_BTN_APPLY;
        }
        else if(x>segButton[ID_RNG_BTN_EXP].x && x<segButton[ID_RNG_BTN_EXP].x+segButton[ID_RNG_BTN_EXP].width)
        {
            motion=ID_RNG_BTN_EXP;
        }
        else if(x>segButton[ID_RNG_PRT_SCN].x && x<segButton[ID_RNG_PRT_SCN].x+segButton[ID_RNG_PRT_SCN].width)
        {
            motion=ID_RNG_PRT_SCN;
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }
    else
    {
        motion=ID_RNG_NONE;
    }
    panelBottom->Refresh();
}

void MydoctorDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    panelBottom->Refresh();
}

void MydoctorDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_RNG_BTN_QUIT)
    {
        Destroy();
    }
    else if(motion==ID_RNG_BTN_APPLY)
    {
        if(modified==0) return;
        if(modified==1)
        {
            mtg_store_seg(mtg);
            mtg_store_segs(mtg);
            UpdateSegs();
            nseged=0;
            if(seged) free(seged);
            seged=0;
            nseged=mtg_query_segeds(mtg,&seged);
            UpdateSeged();
        }
        else if(modified==2)
        {
            mtg_store_seging(mtg);
            //wxMessageBox(_("ok"));
        }
        else if(modified==3)
        {
            mtg_store_seg(mtg);
            mtg_store_segs(mtg);
            UpdateSegs();
            nseged=0;
            if(seged) free(seged);
            seged=0;
            nseged=mtg_query_segeds(mtg,&seged);
            UpdateSeged();
        }
        modified=0;
    }
    else if(motion==ID_RNG_BTN_EXP)
    {
        if(page==ID_RNG_PAGE_DONE)
        {
            if(nseged<=0) return;
            wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
            if(fileDlg.ShowModal()==wxID_OK)
            {
                wxString strFile=fileDlg.GetPath();
                FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
                if(fp)
                {
                    fprintf(fp,wxString(_("环号,里程K（m）,类型,K点,管环中心（系统）,,,管环中心（实测）,,,偏差（导向）,,偏差（实测）,,较差,,备注\n")).mb_str(wxConvLocal));
                    fprintf(fp,wxString(_(",,,,X,Y,Z,X,Y,Z,横向（mm）,竖向（mm）,横向（mm）,竖向（mm）,横向（mm）,竖向（mm）,\n")).mb_str(wxConvLocal));
                    for(int i=0;i<nseged;i++)
                    {
                        fprintf(fp,"%d,",seged[i].numb);
                        fprintf(fp,"%.4f,",seged[i].mile);
                        if(seged[i].type==0) fprintf(fp,"通用环,");
                        else if(seged[i].type==1) fprintf(fp,"标准环,");
                        else if(seged[i].type==2) fprintf(fp,"左转弯,");
                        else if(seged[i].type==3) fprintf(fp,"右转弯,");
                        if(mtg->segset.Ks<12)
                        {
                            if(seged[i].k<mtg->segset.Ks/2) fprintf(fp,"%d,",seged[i].k+1);
                            else fprintf(fp,"%d,",seged[i].k+2);
                        }
                        else
                        {
                            fprintf(fp,"%d,",seged[i].k+1);
                        }
                        fprintf(fp,"%.4f,",seged[i].x);
                        fprintf(fp,"%.4f,",seged[i].y);
                        fprintf(fp,"%.4f,",seged[i].z);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f,",seged[i].dh);
                        fprintf(fp,"%.4f,",seged[i].dv);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f\n",0.0);
                    }
                    fclose(fp);
                    wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
                }
            }
        }
        else if(page==ID_RNG_PAGE_CAL)
        {
            wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
            if(fileDlg.ShowModal()==wxID_OK)
            {
                wxString strFile=fileDlg.GetPath();
                FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
                if(fp)
                {
                    fprintf(fp,wxString(_("环号,里程K（m）,类型,K点,管环中心,,,偏差\n")).mb_str(wxConvLocal));
                    fprintf(fp,wxString(_(",,,,X,Y,Z,横向（mm）,竖向（mm）\n")).mb_str(wxConvLocal));
                    for(int i=0;i<MAX_SEG;i++)
                    {
                        fprintf(fp,"%d,",mtg->segs[i].numb);
                        fprintf(fp,"%.4f,",mtg->segs[i].mile);
                        if(mtg->segs[i].type==0) fprintf(fp,"通用环,");
                        else if(mtg->segs[i].type==1) fprintf(fp,"标准环,");
                        else if(mtg->segs[i].type==2) fprintf(fp,"左转弯,");
                        else if(mtg->segs[i].type==3) fprintf(fp,"右转弯,");
                        if(mtg->segset.Ks<12)
                        {
                            if(mtg->segs[i].k<mtg->segset.Ks/2) fprintf(fp,"%d,",mtg->segs[i].k+1);
                            else fprintf(fp,"%d,",mtg->segs[i].k+2);
                        }
                        else
                        {
                            fprintf(fp,"%d,",mtg->segs[i].k+1);
                        }
                        fprintf(fp,"%.4f,",mtg->segs[i].x);
                        fprintf(fp,"%.4f,",mtg->segs[i].y);
                        fprintf(fp,"%.4f,",mtg->segs[i].z);
                        fprintf(fp,"%.4f,",mtg->segs[i].dh);
                        fprintf(fp,"%.4f\n",mtg->segs[i].dv);
                    }
                    fclose(fp);
                    wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
                }
            }
        }
        else if(page==ID_RNG_PAGE_DES)
        {
            if(nres<=0) return;
            wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
            if(fileDlg.ShowModal()==wxID_OK)
            {
                wxString strFile=fileDlg.GetPath();
                FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
                if(fp)
                {
                    fprintf(fp,wxString(_("环号,里程K（m）,类型,K点,管环中心,,,偏差\n")).mb_str(wxConvLocal));
                    fprintf(fp,wxString(_(",,,,X,Y,Z,横向（mm）,竖向（mm）\n")).mb_str(wxConvLocal));
                    for(int i=0;i<nres;i++)
                    {
                        fprintf(fp,"%d,",res[i].numb);
                        fprintf(fp,"%.4f,",res[i].headc);
                        if(res[i].type==0) fprintf(fp,"通用环,");
                        else if(res[i].type==1) fprintf(fp,"标准环,");
                        else if(res[i].type==2) fprintf(fp,"左转弯,");
                        else if(res[i].type==3) fprintf(fp,"右转弯,");
                        if(mtg->segset.Ks<12)
                        {
                            if(res[i].k<mtg->segset.Ks/2) fprintf(fp,"%d,",res[i].k+1);
                            else fprintf(fp,"%d,",res[i].k+2);
                        }
                        else
                        {
                            fprintf(fp,"%d,",res[i].k+1);
                        }
                        fprintf(fp,"%.4f,",res[i].head[0]);
                        fprintf(fp,"%.4f,",res[i].head[1]);
                        fprintf(fp,"%.4f,",res[i].head[2]);
                        fprintf(fp,"%.4f,",res[i].headh);
                        fprintf(fp,"%.4f\n",res[i].headv);
                    }
                    fclose(fp);
                    wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
                }
            }
        }
    }
    else if(motion==ID_RNG_PRT_SCN)
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
        str=_("选型界面");
        str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
        }
    }
}

void MydoctorDlg::WriteMsg(wxString msg,int col)
{
    Msg=msg;
    Mtype=col;
    panelBottom->Refresh();
}


void MydoctorDlg::OnPaintMain(wxPaintEvent& event)
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
        //memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnPaintSeg(wxPaintEvent& event)
{
    wxPaintDC dc(panelSeg);
    int w,h;
    panelSeg->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnPaintSegButton(wxPaintEvent& event)
{
    wxPaintDC dc(segbuttons);
    int w,h;
    segbuttons->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;

        x1=1;
        y1=1;
        w1=w-1;
        h1=25;
        segButton[ID_RNG_SEG_PRE].x=x1;
        segButton[ID_RNG_SEG_PRE].y=y1;
        segButton[ID_RNG_SEG_PRE].width=w1;
        segButton[ID_RNG_SEG_PRE].height=h1;

        if(segpage==ID_RNG_SEG_PRE)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_RNG_SEG_PRE)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(segButton[ID_RNG_SEG_PRE]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        //if(segpage!=ID_RNG_SEG_PRE) memDC.DrawLine(x1+w1-1,y1,x1+w1-1,y1+h1);
        memDC.DrawLabel(_("上环管环"),wxRect(segButton[ID_RNG_SEG_PRE]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+1;
        segButton[ID_RNG_SEG_GAP].x=x1;
        segButton[ID_RNG_SEG_GAP].y=y1;
        segButton[ID_RNG_SEG_GAP].width=w1;
        segButton[ID_RNG_SEG_GAP].height=h1;

        if(segpage==ID_RNG_SEG_GAP)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_RNG_SEG_GAP)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(segButton[ID_RNG_SEG_GAP]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        //if(segpage!=ID_RNG_SEG_GAP) memDC.DrawLine(x1+w1-1,y1,x1+w1-1,y1+h1);
        memDC.DrawLabel(_("盾尾间隙"),wxRect(segButton[ID_RNG_SEG_GAP]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+1;
        segButton[ID_RNG_SEG_KPOS].x=x1;
        segButton[ID_RNG_SEG_KPOS].y=y1;
        segButton[ID_RNG_SEG_KPOS].width=w1;
        segButton[ID_RNG_SEG_KPOS].height=h1;

        if(segpage==ID_RNG_SEG_KPOS)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_RNG_SEG_KPOS)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(segButton[ID_RNG_SEG_KPOS]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        //if(segpage!=ID_RNG_SEG_KPOS) memDC.DrawLine(x1+w1-1,y1,x1+w1-1,y1+h1);
        memDC.DrawLabel(_("管环选型"),wxRect(segButton[ID_RNG_SEG_KPOS]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+1;
        segButton[ID_RNG_SEG_NEXT].x=x1;
        segButton[ID_RNG_SEG_NEXT].y=y1;
        segButton[ID_RNG_SEG_NEXT].width=w1;
        segButton[ID_RNG_SEG_NEXT].height=h1;

        if(segpage==ID_RNG_SEG_NEXT)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_RNG_SEG_NEXT)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(segButton[ID_RNG_SEG_NEXT]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        //if(segpage!=ID_RNG_SEG_NEXT) memDC.DrawLine(x1+w1-1,y1,x1+w1-1,y1+h1);
        memDC.DrawLabel(_("后续管环"),wxRect(segButton[ID_RNG_SEG_NEXT]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLine(x1+w1-1,0,x1+w1-1,h);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnMotionSegButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>segButton[ID_RNG_SEG_PRE].x && x<segButton[ID_RNG_SEG_PRE].x+segButton[ID_RNG_SEG_PRE].width)
    {
        if(y>segButton[ID_RNG_SEG_PRE].y && y<segButton[ID_RNG_SEG_PRE].y+segButton[ID_RNG_SEG_PRE].height)
        {
            motion=ID_RNG_SEG_PRE;
        }
        else if(y>segButton[ID_RNG_SEG_GAP].y && y<segButton[ID_RNG_SEG_GAP].y+segButton[ID_RNG_SEG_GAP].height)
        {
            motion=ID_RNG_SEG_GAP;
        }
        else if(y>segButton[ID_RNG_SEG_KPOS].y && y<segButton[ID_RNG_SEG_KPOS].y+segButton[ID_RNG_SEG_KPOS].height)
        {
            motion=ID_RNG_SEG_KPOS;
        }
        else if(y>segButton[ID_RNG_SEG_NEXT].y && y<segButton[ID_RNG_SEG_NEXT].y+segButton[ID_RNG_SEG_NEXT].height)
        {
            motion=ID_RNG_SEG_NEXT;
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }
    else
    {
        motion=ID_RNG_NONE;
    }

    segbuttons->Refresh();
}

void MydoctorDlg::OnLeaveSegButton(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    segbuttons->Refresh();
}

void MydoctorDlg::OnClickSegButton(wxMouseEvent& event)
{
    if(motion==ID_RNG_SEG_PRE)
    {
        InitialPosition();
        segpage=ID_RNG_SEG_PRE;
        lastSegText->Show(true);
        gapText->Show(false);
        segText->Show(false);
        selectionText->Show(false);
        nextSegs->Show(false);
        panelJust->Show(false);
    }
    else if(motion==ID_RNG_SEG_GAP)
    {
        InitialPosition();
        segpage=ID_RNG_SEG_GAP;
        lastSegText->Show(false);
        gapText->Show(true);
        segText->Show(false);
        selectionText->Show(false);
        nextSegs->Show(false);
        //panelJust->Show(false);
    }
    else if(motion==ID_RNG_SEG_KPOS)
    {
        InitialPosition();

        //mtg_get_kpos(mtg,&mtg->segs[1]);
        //mtg_std_segs(mtg,1);
        //UpdateSegs();
        segpage=ID_RNG_SEG_KPOS;
        lastSegText->Show(false);
        gapText->Show(false);
        segText->Show(false);
        selectionText->Show(true);
        nextSegs->Show(false);
        //panelJust->Show(false);
    }
    else if(motion==ID_RNG_SEG_NEXT)
    {
        InitialPosition();
        segpage=ID_RNG_SEG_NEXT;
        lastSegText->Show(false);
        gapText->Show(false);
        segText->Show(false);
        selectionText->Show(false);
        nextSegs->Show(true);
        //panelJust->Show(true);
    }

    segbuttons->Refresh();
}

void MydoctorDlg::OnPaintSeging(wxPaintEvent& event)
{
    wxPaintDC dc(panelSeging);
    int w,h;
    panelSeging->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnPaintDesButton(wxPaintEvent& event)
{
    wxPaintDC dc(desbuttons);
    int w,h;
    desbuttons->GetSize(&w,&h);
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

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;

        x1=1;
        y1=1;
        w1=w-1;
        h1=25;
        segButton[ID_RNG_DES_ONE].x=x1;
        segButton[ID_RNG_DES_ONE].y=y1;
        segButton[ID_RNG_DES_ONE].width=w1;
        segButton[ID_RNG_DES_ONE].height=h1;

        if(despage==ID_RNG_DES_ONE)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_RNG_DES_ONE)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(segButton[ID_RNG_DES_ONE]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        //if(despage!=ID_RNG_DES_ONE) memDC.DrawLine(x1+w1-1,y1,x1+w1-1,y1+h1);
        memDC.DrawLabel(_("初始管环"),wxRect(segButton[ID_RNG_DES_ONE]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+1;
        segButton[ID_RNG_SEG_DETAIL].x=x1;
        segButton[ID_RNG_SEG_DETAIL].y=y1;
        segButton[ID_RNG_SEG_DETAIL].width=w1;
        segButton[ID_RNG_SEG_DETAIL].height=h1;

        if(despage==ID_RNG_SEG_DETAIL)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_RNG_SEG_DETAIL)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(segButton[ID_RNG_SEG_DETAIL]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        //if(despage!=ID_RNG_SEG_DETAIL) memDC.DrawLine(x1+w1-1,y1,x1+w1-1,y1+h1);
        memDC.DrawLabel(_("设计排版"),wxRect(segButton[ID_RNG_SEG_DETAIL]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+1;
        segButton[ID_RNG_DES_DTA].x=x1;
        segButton[ID_RNG_DES_DTA].y=y1;
        segButton[ID_RNG_DES_DTA].width=w1;
        segButton[ID_RNG_DES_DTA].height=h1;

        if(despage==ID_RNG_DES_DTA)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_RNG_DES_DTA)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(segButton[ID_RNG_DES_DTA]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        //if(despage!=ID_RNG_DES_DTA) memDC.DrawLine(x1+w1-1,y1,x1+w1-1,y1+h1);
        memDC.DrawLabel(_("管环比例"),wxRect(segButton[ID_RNG_DES_DTA]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLine(x1+w1-1,0,x1+w1-1,h);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnMotionDesButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>segButton[ID_RNG_DES_ONE].x && x<segButton[ID_RNG_DES_ONE].x+segButton[ID_RNG_DES_ONE].width)
    {
        if(y>segButton[ID_RNG_DES_ONE].y && y<segButton[ID_RNG_DES_ONE].y+segButton[ID_RNG_DES_ONE].height)
        {
            motion=ID_RNG_DES_ONE;
        }
        else if(y>segButton[ID_RNG_DES_DTA].y && y<segButton[ID_RNG_DES_DTA].y+segButton[ID_RNG_DES_DTA].height)
        {
            motion=ID_RNG_DES_DTA;
        }
        else if(y>segButton[ID_RNG_SEG_DETAIL].y && y<segButton[ID_RNG_SEG_DETAIL].y+segButton[ID_RNG_SEG_DETAIL].height)
        {
            motion=ID_RNG_SEG_DETAIL;
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }
    else
    {
        motion=ID_RNG_NONE;
    }

    desbuttons->Refresh();
}

void MydoctorDlg::OnLeaveDesButton(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    desbuttons->Refresh();
}

void MydoctorDlg::OnClickDesButton(wxMouseEvent& event)
{
    if(motion==ID_RNG_DES_ONE)
    {
        despage=ID_RNG_DES_ONE;
        desOneText->Show(true);
        dtaText->Show(false);
        desListText->Show(false);
        //segText->Show(false);
        //selectionText->Show(false);
    }
    else if(motion==ID_RNG_DES_DTA)
    {
        if(despage==ID_RNG_DES_ONE)
        {
            InitialSeging();
        }
        despage=ID_RNG_DES_DTA;
        desOneText->Show(false);
        dtaText->Show(true);
        desListText->Show(false);
        //segText->Show(false);
        //selectionText->Show(false);
    }
    else if(motion==ID_RNG_SEG_DETAIL)
    {
        if(despage==ID_RNG_DES_ONE)
        {
            InitialSeging();
        }
        despage=ID_RNG_SEG_DETAIL;
        //mtg_init_position(mtg);
        desOneText->Show(false);
        dtaText->Show(false);
        desListText->Show(true);
        //segText->Show(true);
        //selectionText->Show(false);
    }

    desbuttons->Refresh();
}

void MydoctorDlg::OnPaintPage(wxPaintEvent& event)
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
        segButton[ID_RNG_PAGE_DONE].x=x1;
        segButton[ID_RNG_PAGE_DONE].y=y1;
        segButton[ID_RNG_PAGE_DONE].width=w1;
        segButton[ID_RNG_PAGE_DONE].height=h1;

        if(page==ID_RNG_PAGE_DONE || motion==ID_RNG_PAGE_DONE)
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

            if(page!=ID_RNG_PAGE_DONE)
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
        memDC.DrawLabel(_("历史拼装"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);

        x1=x1+w1;
        segButton[ID_RNG_PAGE_CAL].x=x1;
        segButton[ID_RNG_PAGE_CAL].y=y1;
        segButton[ID_RNG_PAGE_CAL].width=w1;
        segButton[ID_RNG_PAGE_CAL].height=h1;
        if(page==ID_RNG_PAGE_CAL || motion==ID_RNG_PAGE_CAL)
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

            if(page!=ID_RNG_PAGE_CAL)
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
        memDC.DrawLabel(_("管环选型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1+w1;
        segButton[ID_RNG_PAGE_DES].x=x1;
        segButton[ID_RNG_PAGE_DES].y=y1;
        segButton[ID_RNG_PAGE_DES].width=w1;
        segButton[ID_RNG_PAGE_DES].height=h1;
        if(page==ID_RNG_PAGE_DES || motion==ID_RNG_PAGE_DES)
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
            if(page!=ID_RNG_PAGE_DES)
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
        memDC.DrawLabel(_("设计排版"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
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

void MydoctorDlg::OnMotionPage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>segButton[ID_RNG_PAGE_DONE].y && y<segButton[ID_RNG_PAGE_DONE].y+segButton[ID_RNG_PAGE_DONE].height)
    {
        if(x>segButton[ID_RNG_PAGE_DONE].x && x<segButton[ID_RNG_PAGE_DONE].x+segButton[ID_RNG_PAGE_DONE].width)
        {
            motion=ID_RNG_PAGE_DONE;
        }
        else if(x>segButton[ID_RNG_PAGE_CAL].x && x<segButton[ID_RNG_PAGE_CAL].x+segButton[ID_RNG_PAGE_CAL].width)
        {
            motion=ID_RNG_PAGE_CAL;
        }
        else if(x>segButton[ID_RNG_PAGE_DES].x && x<segButton[ID_RNG_PAGE_DES].x+segButton[ID_RNG_PAGE_DES].width)
        {
            motion=ID_RNG_PAGE_DES;
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }
    else
    {
        motion=ID_RNG_NONE;
    }
    panelPage->Refresh();
}

void MydoctorDlg::OnLeavePage(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    panelPage->Refresh();
}

void MydoctorDlg::OnClickPage(wxMouseEvent& event)
{
    if(motion==ID_RNG_PAGE_DONE)
    {
        page=ID_RNG_PAGE_DONE;
        panelSeged->Show(true);
        panelSeg->Show(false);
        panelSeging->Show(false);
        //segbuttons->Show(false);
    }
    else if(motion==ID_RNG_PAGE_CAL)
    {
        page=ID_RNG_PAGE_CAL;
        panelSeged->Show(false);
        panelSeg->Show(true);
        panelSeging->Show(false);
        //segbuttons->Show(true);
    }
    else if(motion==ID_RNG_PAGE_DES)
    {
        page=ID_RNG_PAGE_DES;
        panelSeged->Show(false);
        panelSeg->Show(false);
        panelSeging->Show(true);
        //segbuttons->Show(false);
    }
    panelPage->Refresh();
}

void MydoctorDlg::OnPaintSegedListHeader(wxPaintEvent& event)
{
    wxPaintDC dc(segedListHeader);
    int w,h;
    segedListHeader->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=h;
        int i=1;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=segedList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segedList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segedList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segedList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segedList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("平偏(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segedList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("高偏(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segedList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("左超(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segedList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("上超(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segedList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("日期"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=segedList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnPaintLast(wxPaintEvent& event)
{
    wxPaintDC dc(lastSegText);
    int w,h;
    lastSegText->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        int x1,y1,w1,h1;
        int x2,y2,x3,y3,x4,y4,x5,y5;
        x1=0;
        y1=7;
        w1=320;
        h1=320;
        memDC.SetPen(ipen[0]);
        memDC.SetBrush(wxBrush(wxColor(33,40,48)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        double radius=(w1-20)/2.0;
        x1=x1+w1/2;
        y1=y1+h1/2;
        if(mtg->nblk>0)
        {
            int k=mtg->segset.Ks;
            int k1=mtg->segs[10].k;
            double a0=2.0*PI/k;
            double pz;
            double deta=mtg->blocks[0].angle/2.0;
            for(int i=0;i<k;i++)
            {
                if(i*a0>PI/2)
                {
                    pz=i*a0-PI/2;
                    break;
                }
            }
            double a1=PI*3.0/2.0-deta+pz;
            double a2=a1+a0*k1;
            a1=a1+a0*k1;

            for(int i=0;i<mtg->nblk;i++)
            {
                x2=x1+radius*cos(a1+0.02);
                y2=y1+radius*sin(a1+0.02);
                x4=x1+(radius-25)*cos(a1+0.02);
                y4=y1+(radius-25)*sin(a1+0.02);
                a1+=mtg->blocks[i].angle;
                x3=x1+radius*cos(a1-0.02);
                y3=y1+radius*sin(a1-0.02);
                x5=x1+(radius-25)*cos(a1-0.02);
                y5=y1+(radius-25)*sin(a1-0.02);
                if(i==0) memDC.SetPen(wxPen(wxColor(255,30,30)));
                else memDC.SetPen(wxPen(wxColor(255,255,30)));
                memDC.DrawArc(x3,y3,x2,y2,x1,y1);
                memDC.DrawArc(x5,y5,x4,y4,x1,y1);
            }

            memDC.SetPen(wxPen(wxColor(105,105,105)));
            memDC.SetBrush(wxBrush(wxColor(33,40,48)));
            memDC.DrawCircle(x1,y1,radius-27);
            memDC.SetPen(wxPen(wxColor(60,66,87)));
            memDC.DrawLine(x1-radius-5,y1,x1+radius+5,y1);
            memDC.DrawLine(x1,y1-radius-5,x1,y1+radius+5);

            a1=PI*3.0/2.0-deta+pz;
            a1=a1+a0*k1;
            memDC.SetPen(wxPen(wxColor(60,66,87),1,wxDOT_DASH));
            for(int i=0;i<mtg->nblk;i++)
            {
                a1+=mtg->blocks[i].angle;
                x5=x1+(radius-25)*cos(a1-0.02);
                y5=y1+(radius-25)*sin(a1-0.02);
                memDC.DrawLine(x5,y5,x1,y1);
            }

            a1=PI*3.0/2.0+pz;
            for(int i=0;i<k;i++)
            {
                x2=x1+(radius-13)*cos(a1+a0*i);
                y2=y1+(radius-13)*sin(a1+a0*i);
                segButton[ID_SEGMENT_COUNT+i].x=x2;
                segButton[ID_SEGMENT_COUNT+i].y=y2;
                segButton[ID_SEGMENT_COUNT+i].width=12;
                segButton[ID_SEGMENT_COUNT+i].height=12;
                if(motion==ID_SEGMENT_COUNT+i)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                    memDC.DrawCircle(x2,y2,12);
                    //k2=i;
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                    memDC.DrawCircle(x2,y2,12);
                }

                if(i==k1)
                {
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                }
                else if(mtg->iseg.ipos[i]==0)
                {
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                }
                else if(mtg->iseg.ipos[i]==1)
                {
                    memDC.SetPen(wxPen(wxColor(255,255,0)));
                    memDC.SetBrush(wxBrush(wxColor(255,255,0)));
                }
                else if(mtg->iseg.ipos[i]==2)
                {
                    memDC.SetPen(*wxRED_PEN);
                    memDC.SetBrush(*wxRED_BRUSH);
                }
                memDC.DrawCircle(x2,y2,5);
            }
        }

        memDC.SetTextForeground(wxColor(0,0,0));
        int w2,h2;
        h2=h1;
        x1=x1+w1/2+14;
        y1=7;
        w1=75;
        h1=25;
        memDC.DrawLabel(_("管环编号"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        last_numb_Text->SetSize(x1+w1,y1,120,-1);
        istr=wxString::Format(_("%d"),mtg->segs[10].numb);
        last_numb_Text->SetValue(istr);
        x2=x1;

        if(mtg->segset.type==1)
        {
            y1=y1+h1+5;
            memDC.DrawLabel(_("管环类型"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            segButton[ID_RNG_TYPE_STD].x=x1;
            segButton[ID_RNG_TYPE_STD].y=y1;
            segButton[ID_RNG_TYPE_STD].width=w1;
            segButton[ID_RNG_TYPE_STD].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));

            if(mtg->segs[10].type==1)
            {
                if(motion==ID_RNG_TYPE_STD)
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
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_RNG_TYPE_STD)
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
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }


            x1+=w1;
            segButton[ID_RNG_TYPE_TL].x=x1;
            segButton[ID_RNG_TYPE_TL].y=y1;
            segButton[ID_RNG_TYPE_TL].width=w1;
            segButton[ID_RNG_TYPE_TL].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));

            if(mtg->segs[10].type==2)
            {
                if(motion==ID_RNG_TYPE_TL)
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
                memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                    if(motion==ID_RNG_TYPE_TL)
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
                    memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }

            x1+=w1;
            segButton[ID_RNG_TYPE_TR].x=x1;
            segButton[ID_RNG_TYPE_TR].y=y1;
            segButton[ID_RNG_TYPE_TR].width=w1;
            segButton[ID_RNG_TYPE_TR].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));

            if(mtg->segs[10].type==3)
            {
                if(motion==ID_RNG_TYPE_TR)
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
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_RNG_TYPE_TR)
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
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

        }

        y1=y1+h1+5;
        x1=x2;
        w1=w-x1-14;
        h1=h2-y1+7;
        memDC.SetPen(ipen[0]);
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        x2=x1+w1/2;
        y2=y1+h1/2;
        w2=w1-28;
        h2=h1-28;
        memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT_DASH));
        memDC.DrawLine(x2,y2-h2/2,x2,y2+h2/2);

        //if(mtg->segs[0].t>0)
        {
            double deta=mtg->segs[10].ori1-mtg->segs[10].tbmh;
            double beta=mtg->segs[10].hpz;
            double iw=w2/2.0;
            double ih=iw/3.0;
            deta=deta*5.0;
            beta=beta*5.0;
            double px1,py1,px2,py2,px3,py3,px4,py4,px5,py5,dx,dy;
            //trace(0,"type=%d,deta=%.12f,hpz=%.12f,hz1=%.12f\n",mtg->segs[0].type,deta,mtg->segs[0].hpz,mtg->segs[0].hz1);
            memDC.SetPen(wxPen(wxColor(0,0,0),1,wxDOT));
            px1=x2-iw/2.0*cos(deta);
            py1=y2-iw/2.0*sin(deta);
            px2=px1+iw*cos(deta);
            py2=py1+iw*sin(deta);
            px3=px2+ih*cos(deta+PI/2.0);
            py3=py2+ih*sin(deta+PI/2.0);
            px4=px3+iw*cos(deta+PI);
            py4=py3+iw*sin(deta+PI);

            if(mtg->segs[10].type==2 && beta<0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta-beta;
                px3=px2+(ih+ih1*2.0)*cos(deta+PI/2.0);
                py3=py2+(ih+ih1*2.0)*sin(deta+PI/2.0);
                px4=px1+(ih-ih1*1.0)*cos(deta+PI/2.0);
                py4=py1+(ih-ih1*1.0)*sin(deta+PI/2.0);
            }
            else if(mtg->segs[10].type==2 && beta>0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta-beta;
                px4=px1+(ih+ih1*2.0)*cos(deta+PI/2.0);
                py4=py1+(ih+ih1*2.0)*sin(deta+PI/2.0);
                px3=px2+(ih-ih1*1.0)*cos(deta+PI/2.0);
                py3=py2+(ih-ih1*1.0)*sin(deta+PI/2.0);
            }
            else if(mtg->segs[10].type==3 && beta>0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta-beta;
                px4=px1+(ih+ih1*2.0)*cos(deta+PI/2.0);
                py4=py1+(ih+ih1*2.0)*sin(deta+PI/2.0);
                px3=px2+(ih-ih1*1.0)*cos(deta+PI/2.0);
                py3=py2+(ih-ih1*1.0)*sin(deta+PI/2.0);
            }
            else if(mtg->segs[10].type==3 && beta<0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta-beta;
                px3=px2+(ih+ih1*2.0)*cos(deta+PI/2.0);
                py3=py2+(ih+ih1*2.0)*sin(deta+PI/2.0);
                px4=px1+(ih-ih1*1.0)*cos(deta+PI/2.0);
                py4=py1+(ih-ih1*1.0)*sin(deta+PI/2.0);
            }
            memDC.DrawLine(px1,py1,px2,py2);
            memDC.DrawLine(px2,py2,px3,py3);
            memDC.DrawLine(px3,py3,px4,py4);
            memDC.DrawLine(px1,py1,px4,py4);

            deta=mtg->segs[10].ori1-mtg->segs[10].tbmh;
            deta=deta*5.0;
            px3=(px1+px2)/2.0;
            py3=(py1+py2)/2.0;
            px4=px3+h2/2.0*sin(deta);
            py4=py3-h2/2.0*cos(deta);
            memDC.DrawLine(px3,py3,px4,py4);
        }

        x2=x2-w2/2+15;
        y2=y2-h2/2+15;
        memDC.SetTextForeground(wxColor(0,0,0));
        istr=_("左超：")+wxString::Format(_("%.1f mm"),mtg->segs[10].harc*1000.0);
        memDC.DrawLabel(istr,wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y2+=25;
        istr=_("上超：")+wxString::Format(_("%.1f mm"),mtg->segs[10].varc*1000.0);
        memDC.DrawLabel(istr,wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnMotionLast(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int n=mtg->segset.Ks;
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
            motion=ID_RNG_NONE;
        }
    }

    if(motion==ID_RNG_NONE)
    {
        if(y>segButton[ID_RNG_TYPE_TL].y && y<segButton[ID_RNG_TYPE_TL].y+segButton[ID_RNG_TYPE_TL].height)
        {
            if(x>segButton[ID_RNG_TYPE_TL].x && x<segButton[ID_RNG_TYPE_TL].x+segButton[ID_RNG_TYPE_TL].width)
            {
                motion=ID_RNG_TYPE_TL;
            }
            else if(x>segButton[ID_RNG_TYPE_TR].x && x<segButton[ID_RNG_TYPE_TR].x+segButton[ID_RNG_TYPE_TR].width)
            {
                motion=ID_RNG_TYPE_TR;
            }
            else if(x>segButton[ID_RNG_TYPE_STD].x && x<segButton[ID_RNG_TYPE_STD].x+segButton[ID_RNG_TYPE_STD].width)
            {
                motion=ID_RNG_TYPE_STD;
            }
            else
            {
                motion=ID_RNG_NONE;
            }
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }

    lastSegText->Refresh();
}

void MydoctorDlg::OnLeaveLast(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    lastSegText->Refresh();
}

void MydoctorDlg::OnClickLast(wxMouseEvent& event)
{
    int k=mtg->segset.Ks;
    int i;

    for(i=0;i<k;i++)
    {
        if(motion==ID_SEGMENT_COUNT+i)
        {
            if(mtg->segs[10].k!=i)
            {
                mtg->segs[10].k=i;
                mtg_init_position(mtg);
                mtg_std_segs(mtg,0);
                UpdateSegs();
                if(modified==2) modified=3;
                else modified=1;
                panelBottom->Refresh();
            }
            break;
        }
    }

    if(i==k)
    {
        if(motion==ID_RNG_TYPE_TL)
        {
            if(mtg->segs[10].type!=2)
            {
                mtg->segs[10].type=2;
                mtg_init_position(mtg);
                mtg_std_segs(mtg,0);
                UpdateSegs();
                if(modified==2) modified=3;
                else modified=1;
                panelBottom->Refresh();
            }
        }
        else if(motion==ID_RNG_TYPE_TR)
        {
            if(mtg->segs[10].type!=3)
            {
                mtg->segs[10].type=3;
                mtg_init_position(mtg);
                mtg_std_segs(mtg,0);
                UpdateSegs();
                if(modified==2) modified=3;
                else modified=1;
                panelBottom->Refresh();
            }
        }
        else if(motion==ID_RNG_TYPE_STD)
        {
            if(mtg->segs[10].type!=1)
            {
                mtg->segs[10].type=1;
                mtg_init_position(mtg);
                mtg_std_segs(mtg,0);
                UpdateSegs();
                if(modified==2) modified=3;
                else modified=1;
                panelBottom->Refresh();
            }
        }
    }
    //mtg_seg_parameters(mtg,&mtg->segs[0]);
    lastSegText->Refresh();
}

void MydoctorDlg::OnPaintSelection(wxPaintEvent& event)
{
    wxPaintDC dc(selectionText);
    int w,h;
    selectionText->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        int x1,y1,w1,h1;
        int x2,y2,x3,y3,x4,y4,x5,y5;
        x1=0;
        y1=7;
        w1=320;
        h1=320;
        memDC.SetPen(ipen[0]);
        memDC.SetBrush(wxBrush(wxColor(33,40,48)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        double radius=(w1-20)/2.0;
        x1=x1+w1/2;
        y1=y1+h1/2;
        if(mtg->nblk>0)
        {
            int k=mtg->segset.Ks;
            int k1=mtg->segs[11].k;
            double a0=2.0*PI/k;
            double pz;
            double deta=mtg->blocks[0].angle/2.0;
            for(int i=0;i<k;i++)
            {
                if(i*a0>PI/2)
                {
                    pz=i*a0-PI/2;
                    break;
                }
            }
            double a1=PI*3.0/2.0-deta+pz;
            double a2=a1+a0*k1;
            a1=a1+a0*k1;

            for(int i=0;i<mtg->nblk;i++)
            {
                x2=x1+radius*cos(a1+0.02);
                y2=y1+radius*sin(a1+0.02);
                x4=x1+(radius-25)*cos(a1+0.02);
                y4=y1+(radius-25)*sin(a1+0.02);
                a1+=mtg->blocks[i].angle;
                x3=x1+radius*cos(a1-0.02);
                y3=y1+radius*sin(a1-0.02);
                x5=x1+(radius-25)*cos(a1-0.02);
                y5=y1+(radius-25)*sin(a1-0.02);
                if(i==0) memDC.SetPen(wxPen(wxColor(255,30,30)));
                else memDC.SetPen(wxPen(wxColor(255,255,30)));
                memDC.DrawArc(x3,y3,x2,y2,x1,y1);
                memDC.DrawArc(x5,y5,x4,y4,x1,y1);
            }

            memDC.SetPen(wxPen(wxColor(105,105,105)));
            memDC.SetBrush(wxBrush(wxColor(33,40,48)));
            memDC.DrawCircle(x1,y1,radius-27);
            memDC.SetPen(wxPen(wxColor(60,66,87)));
            memDC.DrawLine(x1-radius-5,y1,x1+radius+5,y1);
            memDC.DrawLine(x1,y1-radius-5,x1,y1+radius+5);

            a1=PI*3.0/2.0-deta+pz;
            a1=a1+a0*k1;
            memDC.SetPen(wxPen(wxColor(60,66,87),1,wxDOT_DASH));
            for(int i=0;i<mtg->nblk;i++)
            {
                a1+=mtg->blocks[i].angle;
                x5=x1+(radius-25)*cos(a1-0.02);
                y5=y1+(radius-25)*sin(a1-0.02);
                memDC.DrawLine(x5,y5,x1,y1);
            }

            a1=PI*3.0/2.0+pz;
            for(int i=0;i<k;i++)
            {
                x2=x1+(radius-13)*cos(a1+a0*i);
                y2=y1+(radius-13)*sin(a1+a0*i);
                segButton[ID_SEGMENT_COUNT+i].x=x2;
                segButton[ID_SEGMENT_COUNT+i].y=y2;
                segButton[ID_SEGMENT_COUNT+i].width=12;
                segButton[ID_SEGMENT_COUNT+i].height=12;
                if(motion==ID_SEGMENT_COUNT+i)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                    memDC.DrawCircle(x2,y2,12);
                    //k2=i;
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                    memDC.DrawCircle(x2,y2,12);
                }

                if(i==k1)
                {
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                }
                else if(mtg->segs[11].ipos[i]==0)
                {
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                }
                else if(mtg->segs[11].ipos[i]==1)
                {
                    memDC.SetPen(wxPen(wxColor(255,255,0)));
                    memDC.SetBrush(wxBrush(wxColor(255,255,0)));
                }
                else if(mtg->segs[11].ipos[i]==2)
                {
                    memDC.SetPen(*wxRED_PEN);
                    memDC.SetBrush(*wxRED_BRUSH);
                }
                memDC.DrawCircle(x2,y2,5);
            }
        }

        memDC.SetTextForeground(wxColor(0,0,0));
        int w2,h2;
        h2=h1;
        x1=x1+w1/2+14;
        y1=7;
        w1=75;
        h1=25;

        x2=x1;
        if(mtg->segset.type==1)
        {
            //y1=y1+h1+5;
            memDC.DrawLabel(_("管环类型"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            segButton[ID_RNG_TYPE_STD].x=x1;
            segButton[ID_RNG_TYPE_STD].y=y1;
            segButton[ID_RNG_TYPE_STD].width=w1;
            segButton[ID_RNG_TYPE_STD].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));

            if(mtg->segs[11].type==1)
            {
                if(motion==ID_RNG_TYPE_STD)
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
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_RNG_TYPE_STD)
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
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }


            x1+=w1;
            segButton[ID_RNG_TYPE_TL].x=x1;
            segButton[ID_RNG_TYPE_TL].y=y1;
            segButton[ID_RNG_TYPE_TL].width=w1;
            segButton[ID_RNG_TYPE_TL].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));

            if(mtg->segs[11].type==2)
            {
                if(motion==ID_RNG_TYPE_TL)
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
                memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                    if(motion==ID_RNG_TYPE_TL)
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
                    memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }

            x1+=w1;
            segButton[ID_RNG_TYPE_TR].x=x1;
            segButton[ID_RNG_TYPE_TR].y=y1;
            segButton[ID_RNG_TYPE_TR].width=w1;
            segButton[ID_RNG_TYPE_TR].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));

            if(mtg->segs[11].type==3)
            {
                if(motion==ID_RNG_TYPE_TR)
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
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_RNG_TYPE_TR)
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
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

        }

        y1=y1+h1+5;
        x1=x2;
        w1=w-x1-14;
        h1=h2-y1+7;
        memDC.SetPen(ipen[0]);
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        x2=x1+w1/2;
        y2=y1+h1/2;
        w2=w1-28;
        h2=h1-28;
        memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT_DASH));
        memDC.DrawLine(x2,y2-h2/2,x2,y2+h2/2);

        //if(mtg->segs[0].t>0)
        {
            double deta=mtg->segs[10].ori1-mtg->segs[10].tbmh;
            double beta=mtg->segs[10].hpz;
            double iw=w2/2.0;
            double ih=iw/3.0;
            deta=deta*5.0;
            beta=beta*5.0;
            double px1,py1,px2,py2,px3,py3,px4,py4,px5,py5,dx,dy;
            //trace(0,"type=%d,deta=%.12f,hpz=%.12f,hz1=%.12f\n",mtg->segs[0].type,deta,mtg->segs[0].hpz,mtg->segs[0].hz1);
            memDC.SetPen(wxPen(wxColor(0,0,0),1,wxDOT));
            px1=x2-iw/2.0*cos(deta);
            py1=y2-iw/2.0*sin(deta);
            px2=px1+iw*cos(deta);
            py2=py1+iw*sin(deta);
            px3=px2+ih*cos(deta+PI/2.0);
            py3=py2+ih*sin(deta+PI/2.0);
            px4=px3+iw*cos(deta+PI);
            py4=py3+iw*sin(deta+PI);

            if(mtg->segs[10].type==2 && beta<0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta-beta;
                px3=px2+(ih+ih1*2.0)*cos(deta+PI/2.0);
                py3=py2+(ih+ih1*2.0)*sin(deta+PI/2.0);
                px4=px1+(ih-ih1*1.0)*cos(deta+PI/2.0);
                py4=py1+(ih-ih1*1.0)*sin(deta+PI/2.0);
            }
            else if(mtg->segs[10].type==2 && beta>0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta-beta;
                px4=px1+(ih+ih1*2.0)*cos(deta+PI/2.0);
                py4=py1+(ih+ih1*2.0)*sin(deta+PI/2.0);
                px3=px2+(ih-ih1*1.0)*cos(deta+PI/2.0);
                py3=py2+(ih-ih1*1.0)*sin(deta+PI/2.0);
            }
            else if(mtg->segs[10].type==3 && beta>0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta-beta;
                px4=px1+(ih+ih1*2.0)*cos(deta+PI/2.0);
                py4=py1+(ih+ih1*2.0)*sin(deta+PI/2.0);
                px3=px2+(ih-ih1*1.0)*cos(deta+PI/2.0);
                py3=py2+(ih-ih1*1.0)*sin(deta+PI/2.0);
            }
            else if(mtg->segs[10].type==3 && beta<0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta-beta;
                px3=px2+(ih+ih1*2.0)*cos(deta+PI/2.0);
                py3=py2+(ih+ih1*2.0)*sin(deta+PI/2.0);
                px4=px1+(ih-ih1*1.0)*cos(deta+PI/2.0);
                py4=py1+(ih-ih1*1.0)*sin(deta+PI/2.0);
            }
            memDC.DrawLine(px1,py1,px2,py2);
            memDC.DrawLine(px2,py2,px3,py3);
            memDC.DrawLine(px3,py3,px4,py4);
            memDC.DrawLine(px1,py1,px4,py4);

            deta=mtg->segs[10].ori1-mtg->segs[10].tbmh;
            beta=mtg->segs[11].hpz;
            deta=deta*5.0;
            beta=beta*5.0;
            memDC.SetPen(wxPen(wxColor(0,0,0),1,wxDOT));
            px1=x2-iw/2.0*cos(deta);
            py1=y2-iw/2.0*sin(deta);
            px2=px1+iw*cos(deta);
            py2=py1+iw*sin(deta);
            px3=px2+ih*cos(deta-PI/2.0);
            py3=py2+ih*sin(deta-PI/2.0);
            px4=px3+iw*cos(deta-PI);
            py4=py3+iw*sin(deta-PI);

            if(mtg->segs[11].type==2 && beta<0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta+beta;
                px3=px2+(ih+ih1*2.0)*cos(deta-PI/2.0);
                py3=py2+(ih+ih1*2.0)*sin(deta-PI/2.0);
                px4=px1+(ih-ih1*1.0)*cos(deta-PI/2.0);
                py4=py1+(ih-ih1*1.0)*sin(deta-PI/2.0);
            }
            else if(mtg->segs[11].type==2 && beta>0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta+beta;
                px4=px1+(ih+ih1*2.0)*cos(deta-PI/2.0);
                py4=py1+(ih+ih1*2.0)*sin(deta-PI/2.0);
                px3=px2+(ih-ih1*1.0)*cos(deta-PI/2.0);
                py3=py2+(ih-ih1*1.0)*sin(deta-PI/2.0);
            }
            else if(mtg->segs[11].type==3 && beta>0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta+beta;
                px4=px1+(ih+ih1*2.0)*cos(deta-PI/2.0);
                py4=py1+(ih+ih1*2.0)*sin(deta-PI/2.0);
                px3=px2+(ih-ih1*1.0)*cos(deta-PI/2.0);
                py3=py2+(ih-ih1*1.0)*sin(deta-PI/2.0);
            }
            else if(mtg->segs[11].type==3 && beta<0.0)
            {
                double ih1=fabs(iw*tan(beta));
                deta=deta+beta;
                px3=px2+(ih+ih1*2.0)*cos(deta-PI/2.0);
                py3=py2+(ih+ih1*2.0)*sin(deta-PI/2.0);
                px4=px1+(ih-ih1*1.0)*cos(deta-PI/2.0);
                py4=py1+(ih-ih1*1.0)*sin(deta-PI/2.0);
            }
            memDC.DrawLine(px1,py1,px2,py2);
            memDC.DrawLine(px2,py2,px3,py3);
            memDC.DrawLine(px3,py3,px4,py4);
            memDC.DrawLine(px1,py1,px4,py4);

            deta=mtg->segs[11].ori1-mtg->segs[10].tbmh;
            deta=deta*5.0;
            px3=(px3+px4)/2.0;
            py3=(py3+py4)/2.0;
            px4=px3+(h2/2.0-ih)*sin(deta);
            py4=py3-(h2/2.0-ih)*cos(deta);
            memDC.DrawLine(px3,py3,px4,py4);
        }

        x2=x2-w2/2+15;
        y2=y2-h2/2+15;
        memDC.SetTextForeground(wxColor(0,0,0));
        istr=_("左超：")+wxString::Format(_("%.1f mm"),mtg->segs[11].harc*1000.0);
        memDC.DrawLabel(istr,wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y2+=25;
        istr=_("上超：")+wxString::Format(_("%.1f mm"),mtg->segs[11].varc*1000.0);
        memDC.DrawLabel(istr,wxRect(x2,y2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnMotionSelection(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int n=mtg->segset.Ks;
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
            motion=ID_RNG_NONE;
        }
    }

    if(motion==ID_RNG_NONE)
    {
        if(y>segButton[ID_RNG_TYPE_TL].y && y<segButton[ID_RNG_TYPE_TL].y+segButton[ID_RNG_TYPE_TL].height)
        {
            if(x>segButton[ID_RNG_TYPE_TL].x && x<segButton[ID_RNG_TYPE_TL].x+segButton[ID_RNG_TYPE_TL].width)
            {
                motion=ID_RNG_TYPE_TL;
            }
            else if(x>segButton[ID_RNG_TYPE_TR].x && x<segButton[ID_RNG_TYPE_TR].x+segButton[ID_RNG_TYPE_TR].width)
            {
                motion=ID_RNG_TYPE_TR;
            }
            else if(x>segButton[ID_RNG_TYPE_STD].x && x<segButton[ID_RNG_TYPE_STD].x+segButton[ID_RNG_TYPE_STD].width)
            {
                motion=ID_RNG_TYPE_STD;
            }
            else
            {
                motion=ID_RNG_NONE;
            }
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }

    selectionText->Refresh();
}

void MydoctorDlg::OnLeaveSelection(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    selectionText->Refresh();
}

void MydoctorDlg::OnClickSelection(wxMouseEvent& event)
{
    int k=mtg->segset.Ks;
    int i;

    for(i=0;i<k;i++)
    {
        if(motion==ID_SEGMENT_COUNT+i)
        {
            if(mtg->segs[11].k!=i)
            {
                mtg->segs[11].k=i;
                mtg_seg_cal(mtg);
                mtg_std_segs(mtg,1);
                UpdateSegs();
                if(modified==2) modified=3;
                else modified=1;
                panelBottom->Refresh();
            }
            break;
        }
    }

    if(i==k)
    {
        if(motion==ID_RNG_TYPE_TL)
        {
            if(mtg->segs[11].type!=2)
            {
                mtg->segs[11].type=2;
                mtg_seg_cal(mtg);
                mtg_std_segs(mtg,1);
                UpdateSegs();
                if(modified==2) modified=3;
                else modified=1;
                panelBottom->Refresh();
            }
        }
        else if(motion==ID_RNG_TYPE_TR)
        {
            if(mtg->segs[11].type!=3)
            {
                mtg->segs[11].type=3;
                mtg_seg_cal(mtg);
                mtg_std_segs(mtg,1);
                UpdateSegs();
                if(modified==2) modified=3;
                else modified=1;
                panelBottom->Refresh();
            }
        }
        else if(motion==ID_RNG_TYPE_STD)
        {
            if(mtg->segs[11].type!=1)
            {
                mtg->segs[11].type=1;
                mtg_seg_cal(mtg);
                mtg_std_segs(mtg,1);
                UpdateSegs();
                if(modified==2) modified=3;
                else modified=1;
                panelBottom->Refresh();
            }
        }
    }
    selectionText->Refresh();
}

void MydoctorDlg::OnPaintGapText(wxPaintEvent& event)
{
    wxPaintDC dc(gapText);
    int w,h;
    gapText->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        int x1,y1,w1,h1;
        x1=0;
        y1=7;
        w1=320;
        h1=320;
        memDC.SetPen(ipen[0]);
        memDC.SetBrush(wxBrush(wxColor(33,40,48)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        x1=x1+w1/2;
        y1=y1+h1/2;
        double radius=140;
        memDC.DrawCircle(x1,y1,radius);

        memDC.SetPen(wxPen(wxColor(178,178,178),4));
        memDC.DrawCircle(x1,y1,radius-25.0);

        memDC.SetPen(wxPen(wxColor(255,0,0)));
        memDC.SetTextForeground(wxColor(170,170,170));
        memDC.DrawLine(x1-radius+25,y1,x1-radius,y1);
        memDC.DrawLabel(_("左"),wxRect(x1-radius+30,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1+radius-25,y1,x1+radius,y1);
        memDC.DrawLabel(_("右"),wxRect(x1+radius-30,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1,y1-radius,x1,y1-radius+25);
        memDC.DrawLabel(_("上"),wxRect(x1,y1-radius+30,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLine(x1,y1+radius-25,x1,y1+radius);
        memDC.DrawLabel(_("下"),wxRect(x1,y1+radius-30,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);

        memDC.SetTextForeground(wxColor(0,0,0));
        x1=x1+w1/2+15;
        y1=7;
        w1=80;
        h1=25;
        memDC.DrawLabel(_("盾尾间隙"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+5;
        memDC.DrawLabel(_("上"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbm_ugap_Text->SetSize(x1+25,y1,120,-1);
        y1=y1+h1+5;
        memDC.DrawLabel(_("下"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbm_dgap_Text->SetSize(x1+25,y1,120,-1);
        y1=y1+h1+5;
        memDC.DrawLabel(_("左"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbm_lgap_Text->SetSize(x1+25,y1,120,-1);
        y1=y1+h1+5;
        memDC.DrawLabel(_("右"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbm_rgap_Text->SetSize(x1+25,y1,120,-1);

        y1=y1+h1+10;
        memDC.DrawLabel(_("管环中心"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        istr=_("X = ")+wxString::Format(_("%.4f, "),mtg->segs[10].head[0]);
        istr=istr+_("Y = ")+wxString::Format(_("%.4f, "),mtg->segs[10].head[1]);
        istr=istr+_("Z = ")+wxString::Format(_("%.4f"),mtg->segs[10].head[2]);
        y1=y1+h1;
        memDC.DrawLabel(istr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        istr=_("里程：")+wxString::Format(_("%.3f"),mtg->segs[10].headc);
        y1=y1+h1;
        memDC.DrawLabel(istr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        istr=_("平偏：")+wxString::Format(_("%.3f"),mtg->segs[10].dh);
        y1=y1+h1;
        memDC.DrawLabel(istr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        istr=_("高偏：")+wxString::Format(_("%.3f"),mtg->segs[10].dv);
        y1=y1+h1;
        memDC.DrawLabel(istr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnPaintSegText(wxPaintEvent& event)
{
    wxPaintDC dc(segText);
    int w,h;
    segText->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(33,40,48)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        int x1,y1,w1,h1;
        x1=14;
        y1=7;
        w1=0;
        h1=25;
        memDC.SetTextForeground(wxColor(178,178,178));
        memDC.DrawLabel(_("管环中心坐标"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1+=h1;

        istr=_("X = ")+wxString::Format(_("%.4f"),mtg->segs[0].head[0]);
        memDC.DrawLabel(istr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        istr=_("Y = ")+wxString::Format(_("%.4f"),mtg->segs[0].head[1]);
        memDC.DrawLabel(istr,wxRect(x1+120,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        istr=_("Z = ")+wxString::Format(_("%.4f"),mtg->segs[0].head[2]);
        memDC.DrawLabel(istr,wxRect(x1+240,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1+5;
        memDC.DrawLabel(_("管环中心位置和偏差"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1+=h1;
        istr=_("里程 = ")+wxString::Format(_("%.3f"),mtg->segs[0].headc);
        memDC.DrawLabel(istr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        istr=_("水平偏差 = ")+wxString::Format(_("%.1f mm"),mtg->segs[0].headh*1000.0);
        memDC.DrawLabel(istr,wxRect(x1+120,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        istr=_("垂直偏差 = ")+wxString::Format(_("%.1f mm"),mtg->segs[0].headv*1000.0);
        memDC.DrawLabel(istr,wxRect(x1+240,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+5;
        memDC.DrawLabel(_("上环累计超前量"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1+=h1;
        double mile=mtg->segs[0].headc;
        double ori,phi;
        road_l2xy(&mtg->r,mile,0,0,&ori);
        road_l2h(&mtg->r,mile,0,&phi);
        double pz=mtg->segs[0].ori1-ori;
        if(pz<-PI) pz=pz+2.0*PI;
        if(pz>PI) pz=pz-2.0*PI;
        double len=mtg->segset.De;
        double ival=len*sin(pz);
        istr=_("左超前 = ")+wxString::Format(_("%.1f mm"),ival*1000.0);
        memDC.DrawLabel(istr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        pz=mtg->segs[0].phi1-phi;
        if(pz<-PI) pz=pz+2.0*PI;
        if(pz>PI) pz=pz-2.0*PI;
        ival=len*sin(pz);
        istr=_("上超前 = ")+wxString::Format(_("%.1f mm"),ival*1000.0);
        memDC.DrawLabel(istr,wxRect(x1+120,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+5;
        memDC.DrawLabel(_("中线信息"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1+=h1;
        istr=_("平曲线：");
        int index;
        h_element* he=road_horizon_chain(&mtg->r,mile,&index);
        if(he->type==ROAD_TYPE_START_POINT)
        {
            istr=istr+_("直线");
            he=road_horizon(&mtg->r,index+2);
            len=he->l1;
            len=fabs(len-mile);
            istr=istr+_("  前方")+wxString::Format(_("%.3f"),len);
            if(he->type==ROAD_TYPE_LINE)
            {
                istr=istr+_("米处为直线");
            }
            else if(he->type==ROAD_TYPE_ARC)
            {
                if(he->pz==ROAD_LEFT)
                {
                    istr=istr+_("米处为左转弯的园曲线");
                }
                else
                {
                    istr=istr+_("米处为右转弯的园曲线");
                }
            }
            else if(he->type==ROAD_TYPE_SPIRAL)
            {
                if(he->pz==ROAD_LEFT)
                {
                    istr=istr+_("米处为左转弯的缓和曲线");
                }
                else
                {
                    istr=istr+_("米处为右转弯的缓和曲线");
                }
            }
        }
        else if(he->type==ROAD_TYPE_LINE)
        {
            istr=istr+_("直线");
            he=road_horizon(&mtg->r,index+1);
            len=he->l1;
            len=fabs(len-mile);
            istr=istr+_("  前方")+wxString::Format(_("%.3f"),len);
            if(he->type==ROAD_TYPE_LINE)
            {
                istr=istr+_("米处为直线");
            }
            else if(he->type==ROAD_TYPE_ARC)
            {
                if(he->pz==ROAD_LEFT)
                {
                    istr=istr+_("米处为左转弯的园曲线");
                }
                else
                {
                    istr=istr+_("米处为右转弯的园曲线");
                }
            }
            else if(he->type==ROAD_TYPE_SPIRAL)
            {
                if(he->pz==ROAD_LEFT)
                {
                    istr=istr+_("米处为左转弯的缓和曲线");
                }
                else
                {
                    istr=istr+_("米处为右转弯的缓和曲线");
                }
            }
        }
        else if(he->type==ROAD_TYPE_ARC)
        {
            if(he->pz==ROAD_LEFT)
            {
                istr=istr+wxString::Format(_("R=%.3f"),he->radius)+_("的左转弯园曲线");
            }
            else
            {
                istr=istr+wxString::Format(_("R=%.3f"),he->radius)+_("的右转弯园曲线");
            }
            he=road_horizon(&mtg->r,index+1);
            len=he->l1;
            len=fabs(len-mile);
            istr=istr+_("  前方")+wxString::Format(_("%.3f"),len);
            if(he->type==ROAD_TYPE_LINE)
            {
                istr=istr+_("米处为直线");
            }
            else if(he->type==ROAD_TYPE_ARC)
            {
                if(he->pz==ROAD_LEFT)
                {
                    istr=istr+_("米处为左转弯的园曲线");
                }
                else
                {
                    istr=istr+_("米处为右转弯的园曲线");
                }
            }
            else if(he->type==ROAD_TYPE_SPIRAL)
            {
                if(he->pz==ROAD_LEFT)
                {
                    istr=istr+_("米处为左转弯的缓和曲线");
                }
                else
                {
                    istr=istr+_("米处为右转弯的缓和曲线");
                }
            }
        }
        else if(he->type==ROAD_TYPE_SPIRAL)
        {
            if(he->pz==ROAD_LEFT)
            {
                istr=istr+_("左转弯缓和曲线");
            }
            else
            {
                istr=istr+_("左转弯缓和曲线");
            }
            he=road_horizon(&mtg->r,index+1);
            len=he->l1;
            len=fabs(len-mile);
            istr=istr+_("  前方")+wxString::Format(_("%.3f"),len);
            if(he->type==ROAD_TYPE_LINE)
            {
                istr=istr+_("米处为直线");
            }
            else if(he->type==ROAD_TYPE_ARC)
            {
                if(he->pz==ROAD_LEFT)
                {
                    istr=istr+_("米处为左转弯的园曲线");
                }
                else
                {
                    istr=istr+_("米处为右转弯的园曲线");
                }
            }
            else if(he->type==ROAD_TYPE_SPIRAL)
            {
                if(he->pz==ROAD_LEFT)
                {
                    istr=istr+_("米处为左转弯的缓和曲线");
                }
                else
                {
                    istr=istr+_("米处为右转弯的缓和曲线");
                }
            }
        }
        memDC.DrawLabel(istr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1+=h1;
        istr=_("竖曲线：");
        v_element* ve=road_vertical_chain(&mtg->r,mile,&index);
        if(ve->type==ROAD_TYPE_START_POINT)
        {
            istr=istr+_("直线");
            ve=road_vertical(&mtg->r,index+2);
            len=ve->l1;
            len=fabs(len-mile);
            istr=istr+_("  前方")+wxString::Format(_("%.3f"),len);
            if(ve->type==ROAD_TYPE_LINE)
            {
                istr=istr+_("米处为直线");
            }
            else if(ve->type==ROAD_TYPE_ARC)
            {
                if(ve->pz==ROAD_UP)
                {
                    istr=istr+_("米处为上凸的园曲线");
                }
                else
                {
                    istr=istr+_("米处为下凹的园曲线");
                }
            }
        }
        else if(ve->type==ROAD_TYPE_LINE)
        {
            istr=istr+_("直线");
            ve=road_vertical(&mtg->r,index+1);
            len=ve->l1;
            len=fabs(len-mile);
            istr=istr+_("  前方")+wxString::Format(_("%.3f"),len);
            if(ve->type==ROAD_TYPE_LINE)
            {
                istr=istr+_("米处为直线");
            }
            else if(ve->type==ROAD_TYPE_ARC)
            {
                if(ve->pz==ROAD_UP)
                {
                    istr=istr+_("米处为上凸的园曲线");
                }
                else
                {
                    istr=istr+_("米处为下凹的园曲线");
                }
            }
        }
        else if(ve->type==ROAD_TYPE_ARC)
        {
            istr=istr+_("园曲线");
            ve=road_vertical(&mtg->r,index+1);
            len=ve->l1;
            len=fabs(len-mile);
            istr=istr+_("  前方")+wxString::Format(_("%.3f"),len);
            if(ve->type==ROAD_TYPE_LINE)
            {
                istr=istr+_("米处为直线");
            }
            else if(ve->type==ROAD_TYPE_ARC)
            {
                if(ve->pz==ROAD_UP)
                {
                    istr=istr+_("米处为上凸的园曲线");
                }
                else
                {
                    istr=istr+_("米处为下凹的园曲线");
                }
            }
        }

        memDC.DrawLabel(istr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnPaintOne(wxPaintEvent& event)
{
    wxPaintDC dc(desOneText);
    int w,h;
    desOneText->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        int x1,y1,w1,h1;
        int x2,y2,x3,y3,x4,y4,x5,y5;
        x1=0;
        y1=7;
        w1=320;
        h1=320;
        memDC.SetPen(ipen[0]);
        memDC.SetBrush(wxBrush(wxColor(33,40,48)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        double radius=(w1-20)/2.0;
        x1=x1+w1/2;
        y1=y1+h1/2;
        if(mtg->nblk>0)
        {
            int k=mtg->segset.Ks;
            int k1=mtg->iseg.k;
            double a0=2.0*PI/k;
            double pz;
            double deta=mtg->blocks[0].angle/2.0;
            for(int i=0;i<k;i++)
            {
                if(i*a0>PI/2)
                {
                    pz=i*a0-PI/2;
                    break;
                }
            }
            double a1=PI*3.0/2.0-deta+pz;
            double a2=a1+a0*k1;
            a1=a1+a0*k1;

            for(int i=0;i<mtg->nblk;i++)
            {
                x2=x1+radius*cos(a1+0.02);
                y2=y1+radius*sin(a1+0.02);
                x4=x1+(radius-25)*cos(a1+0.02);
                y4=y1+(radius-25)*sin(a1+0.02);
                a1+=mtg->blocks[i].angle;
                x3=x1+radius*cos(a1-0.02);
                y3=y1+radius*sin(a1-0.02);
                x5=x1+(radius-25)*cos(a1-0.02);
                y5=y1+(radius-25)*sin(a1-0.02);
                if(i==0) memDC.SetPen(wxPen(wxColor(255,30,30)));
                else memDC.SetPen(wxPen(wxColor(255,255,30)));
                memDC.DrawArc(x3,y3,x2,y2,x1,y1);
                memDC.DrawArc(x5,y5,x4,y4,x1,y1);
            }

            memDC.SetPen(wxPen(wxColor(105,105,105)));
            memDC.SetBrush(wxBrush(wxColor(33,40,48)));
            memDC.DrawCircle(x1,y1,radius-27);
            memDC.SetPen(wxPen(wxColor(60,66,87)));
            memDC.DrawLine(x1-radius-5,y1,x1+radius+5,y1);
            memDC.DrawLine(x1,y1-radius-5,x1,y1+radius+5);

            a1=PI*3.0/2.0-deta+pz;
            a1=a1+a0*k1;
            memDC.SetPen(wxPen(wxColor(60,66,87),1,wxDOT_DASH));
            for(int i=0;i<mtg->nblk;i++)
            {
                a1+=mtg->blocks[i].angle;
                x5=x1+(radius-25)*cos(a1-0.02);
                y5=y1+(radius-25)*sin(a1-0.02);
                memDC.DrawLine(x5,y5,x1,y1);
            }

            a1=PI*3.0/2.0+pz;
            for(int i=0;i<k;i++)
            {
                x2=x1+(radius-13)*cos(a1+a0*i);
                y2=y1+(radius-13)*sin(a1+a0*i);
                segButton[ID_SEGMENT_COUNT+i].x=x2;
                segButton[ID_SEGMENT_COUNT+i].y=y2;
                segButton[ID_SEGMENT_COUNT+i].width=12;
                segButton[ID_SEGMENT_COUNT+i].height=12;
                if(motion==ID_SEGMENT_COUNT+i)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                    memDC.DrawCircle(x2,y2,12);
                    //k2=i;
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                    memDC.DrawCircle(x2,y2,12);
                }

                if(i==k1)
                {
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                }
                else if(mtg->iseg.ipos[i]==0)
                {
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                }
                else if(mtg->iseg.ipos[i]==1)
                {
                    memDC.SetPen(wxPen(wxColor(255,255,0)));
                    memDC.SetBrush(wxBrush(wxColor(255,255,0)));
                }
                else if(mtg->iseg.ipos[i]==2)
                {
                    memDC.SetPen(*wxRED_PEN);
                    memDC.SetBrush(*wxRED_BRUSH);
                }
                memDC.DrawCircle(x2,y2,5);
            }
        }

        memDC.SetTextForeground(wxColor(178,178,178));
        istr=_("左超前：")+wxString::Format(_("%.1f mm"),(mtg->iseg.len[2]-mtg->iseg.len[3])*1000.0);
        memDC.DrawLabel(istr,wxRect(x1,y1-25,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        istr=_("上超前：")+wxString::Format(_("%.1f mm"),(mtg->iseg.len[0]-mtg->iseg.len[1])*1000.0);
        memDC.DrawLabel(istr,wxRect(x1,y1+25,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetTextForeground(wxColor(0,0,0));
        x1=x1+w1/2+14;
        y1=7;
        w1=75;
        h1=25;
        memDC.DrawLabel(_("管环编号"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        des_numb_Text->SetSize(x1+w1,y1,120,-1);
        istr=wxString::Format(_("%d"),mtg->iseg.numb);
        des_numb_Text->SetValue(istr);
        y1=y1+h1+5;
        memDC.DrawLabel(_("管环里程"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        des_mile_Text->SetSize(x1+w1,y1,120,-1);
        //istr=wxString::Format(_("%.3f"),mtg->iseg.headc);
        //des_mile_Text->SetValue(istr);
        if(mtg->segset.type==1)
        {
            y1=y1+h1+5;
            memDC.DrawLabel(_("管环类型"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            x1+=w1;
            segButton[ID_RNG_TYPE_STD].x=x1;
            segButton[ID_RNG_TYPE_STD].y=y1;
            segButton[ID_RNG_TYPE_STD].width=w1;
            segButton[ID_RNG_TYPE_STD].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));

            if(mtg->iseg.type==1)
            {
                if(motion==ID_RNG_TYPE_STD)
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
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_RNG_TYPE_STD)
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
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }


            x1+=w1;
            segButton[ID_RNG_TYPE_TL].x=x1;
            segButton[ID_RNG_TYPE_TL].y=y1;
            segButton[ID_RNG_TYPE_TL].width=w1;
            segButton[ID_RNG_TYPE_TL].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));

            if(mtg->iseg.type==2)
            {
                if(motion==ID_RNG_TYPE_TL)
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
                memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                    if(motion==ID_RNG_TYPE_TL)
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
                    memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }

            x1+=w1;
            segButton[ID_RNG_TYPE_TR].x=x1;
            segButton[ID_RNG_TYPE_TR].y=y1;
            segButton[ID_RNG_TYPE_TR].width=w1;
            segButton[ID_RNG_TYPE_TR].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));

            if(mtg->iseg.type==3)
            {
                if(motion==ID_RNG_TYPE_TR)
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
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_RNG_TYPE_TR)
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
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnMotionOne(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int k=mtg->segset.Ks;
    double r;
    for(int i=0;i<k;i++)
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
            motion=ID_RNG_NONE;
        }
    }

    if(motion==ID_RNG_NONE)
    {
        if(y>segButton[ID_RNG_TYPE_TL].y && y<segButton[ID_RNG_TYPE_TL].y+segButton[ID_RNG_TYPE_TL].height)
        {
            if(x>segButton[ID_RNG_TYPE_TL].x && x<segButton[ID_RNG_TYPE_TL].x+segButton[ID_RNG_TYPE_TL].width)
            {
                motion=ID_RNG_TYPE_TL;
            }
            else if(x>segButton[ID_RNG_TYPE_TR].x && x<segButton[ID_RNG_TYPE_TR].x+segButton[ID_RNG_TYPE_TR].width)
            {
                motion=ID_RNG_TYPE_TR;
            }
            else if(x>segButton[ID_RNG_TYPE_STD].x && x<segButton[ID_RNG_TYPE_STD].x+segButton[ID_RNG_TYPE_STD].width)
            {
                motion=ID_RNG_TYPE_STD;
            }
            else
            {
                motion=ID_RNG_NONE;
            }
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }

    desOneText->Refresh();
}

void MydoctorDlg::OnLeaveOne(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    desOneText->Refresh();
}

void MydoctorDlg::OnClickOne(wxMouseEvent& event)
{
    int k=mtg->segset.Ks;
    int i;

    for(i=0;i<k;i++)
    {
        if(motion==ID_SEGMENT_COUNT+i)
        {
            if(mtg->iseg.k!=i)
            {
                mtg->iseg.k=i;
                nres=0;
                if(res) free(res);
                res=0;
                nres=mtg_std_segings(mtg,&res);
                UpdateSegings();
                if(modified==1) modified=3;
                else modified=2;
                panelBottom->Refresh();
            }
            break;
        }
    }

    if(i==k)
    {
        if(motion==ID_RNG_TYPE_TL)
        {
            if(mtg->iseg.type!=2)
            {
                //wxMessageBox(_("ok"));
                mtg->iseg.type=2;
                nres=0;
                if(res) free(res);
                res=0;
                nres=mtg_std_segings(mtg,&res);
                UpdateSegings();
                if(modified==1) modified=3;
                else modified=2;
                panelBottom->Refresh();
            }
        }
        else if(motion==ID_RNG_TYPE_TR)
        {
            if(mtg->iseg.type!=3)
            {
                mtg->iseg.type=3;
                nres=0;
                if(res) free(res);
                res=0;
                nres=mtg_std_segings(mtg,&res);
                UpdateSegings();
                if(modified==1) modified=3;
                else modified=2;
                panelBottom->Refresh();
            }
        }
        else if(motion==ID_RNG_TYPE_STD)
        {
            if(mtg->iseg.type!=1)
            {
                mtg->iseg.type=1;
                nres=0;
                if(res) free(res);
                res=0;
                nres=mtg_std_segings(mtg,&res);
                UpdateSegings();
                if(modified==1) modified=3;
                else modified=2;
                panelBottom->Refresh();
            }
        }
    }
    mtg->iseg=res[0];

    desOneText->Refresh();
}

void MydoctorDlg::OnPaintDtaHeader(wxPaintEvent& event)
{
    wxPaintDC dc(dtaPanel);
    int w,h;
    dtaPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=320;
        h1=25;
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        int i=1;
        //memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=dtaList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=dtaList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起点"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=dtaList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("终点"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=dtaList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnPaintDtaFig(wxPaintEvent& event)
{
    wxPaintDC dc(dtaFig);
    int w,h;
    dtaFig->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        wxString turnstr;
        wxString stdstr;
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=h;
        memDC.SetPen(ipen[0]);
        memDC.SetBrush(wxBrush(wxColor(33,40,48)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        memDC.SetTextForeground(wxColor(178,178,178));
        memDC.SetPen(wxPen(wxColor(178,178,178)));
        h_element* he;
        int sel=dtaList->GetFirstSelected();
        int n=dtaList->GetItemCount();

        double l1,l2,li,l3,l4;
        double iL,len;
        double ix1,iy1,ix2,iy2,ixi,iyi;
        double dx,dy;
        double ori;
        double s1,s2,si;
        int x2,y2,w2,h2;
        int x3,y3,xi,yi;
        iL=mtg->segset.L;
        int i;
        int nh=road_number_horizon(&mtg->r);
        int pzl,pzr,pz0;
        x2=x1+15;
        y2=y1+15;
        w2=w1-30;
        h2=h1-30;

        he=road_horizon(&mtg->r,0);
        ix1=he->x1;
        iy1=he->y1;
        l1=he->l1;
        he=road_horizon(&mtg->r,nh-1);
        ix2=he->x1;
        iy2=he->y1;
        l2=he->l1;
        dx=ix2-ix1;
        dy=iy2-iy1;

        s1=h2/fabs(dx);
        s2=w2/fabs(dy);
        if(s1>s2) si=s2;
        else si=s1;

        xi=dy*si;
        yi=dx*si;
        x2=x2+w2/2;
        y2=y2+h2/2;
        x2=x2-xi/2;
        y2=y2+yi/2;
        x3=x2;
        y3=y2;
        memDC.SetTextForeground(wxColor(255,0,0));
        memDC.DrawLabel(_("QD"),wxRect(x3,y3,0,0),wxALIGN_CENTER_HORIZONTAL || wxALIGN_CENTER_VERTICAL);
        if(sel>=0 && sel<n)
        {
            he=road_horizon(&mtg->r,sel+1);
            l3=he->l1;
            l4=l3+he->length;
        }
        else
        {
            sel=-1;
        }

        li=l1;
        i=1;
        while(li<l2)
        {
            li=l1+iL*i;
            road_l2xy(&mtg->r,li,&ixi,&iyi,0);
            dx=ixi-ix1;
            dy=iyi-iy1;
            xi=x2+dy*si;
            yi=y2-dx*si;
            if(sel>=0)
            {
                if(li>=l3 && li<=l4) memDC.SetPen(wxPen(wxColor(255,58,58)));
                else memDC.SetPen(wxPen(wxColor(170,170,170)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(170,170,170)));
            }
            memDC.DrawLine(x3,y3,xi,yi);
            x3=xi;
            y3=yi;
            i++;
        }
        memDC.SetTextForeground(wxColor(255,0,0));
        memDC.DrawLabel(_("ZD"),wxRect(x3,y3,0,0),wxALIGN_CENTER_HORIZONTAL || wxALIGN_CENTER_VERTICAL);

        memDC.SetTextForeground(wxColor(170,170,170));
        pz0=0;
        pzl=0;
        pzr=0;
        for(i=0;i<nres;i++)
        {
            if(sel>=0)
            {
                li=res[i].headc;
                if(li>=l3 && li<=l4)
                {
                    if(res[i].type==1) pz0++;
                    else if(res[i].type==2) pzl++;
                    else if(res[i].type==3) pzr++;
                }
            }
        }

        x1=15;
        y1=15;
        memDC.DrawLabel(_("总计"),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1+=25;
        istr=_("标准环 = ")+ wxString::Format(_("%d"),mtg->sneed[0]);
        memDC.DrawLabel(istr,wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1+=25;
        istr=_("左转弯 = ")+ wxString::Format(_("%d"),mtg->sneed[1]);
        memDC.DrawLabel(istr,wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1+=25;
        istr=_("右转弯 = ")+ wxString::Format(_("%d"),mtg->sneed[2]);
        memDC.DrawLabel(istr,wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        if(sel>=0)
        {
            y1+=30;
            istr=wxString::Format(_("曲线 %d"),sel+1);
            memDC.DrawLabel(istr,wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            y1+=25;
            istr=_("标准环 = ")+ wxString::Format(_("%d"),pz0);
            memDC.DrawLabel(istr,wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            y1+=25;
            istr=_("左转弯 = ")+ wxString::Format(_("%d"),pzl);
            memDC.DrawLabel(istr,wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            y1+=25;
            istr=_("右转弯 = ")+ wxString::Format(_("%d"),pzr);
            memDC.DrawLabel(istr,wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnMotionDtaFig(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int k=mtg->segset.Ks;
    double r;
    for(int i=0;i<k;i++)
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
            motion=ID_RNG_NONE;
        }
    }

    if(motion==ID_RNG_NONE)
    {
        if(y>segButton[ID_RNG_TYPE_TL].y && y<segButton[ID_RNG_TYPE_TL].y+segButton[ID_RNG_TYPE_TL].height)
        {
            if(x>segButton[ID_RNG_TYPE_TL].x && x<segButton[ID_RNG_TYPE_TL].x+segButton[ID_RNG_TYPE_TL].width)
            {
                motion=ID_RNG_TYPE_TL;
            }
            else if(x>segButton[ID_RNG_TYPE_TR].x && x<segButton[ID_RNG_TYPE_TR].x+segButton[ID_RNG_TYPE_TR].width)
            {
                motion=ID_RNG_TYPE_TR;
            }
            else if(x>segButton[ID_RNG_TYPE_STD].x && x<segButton[ID_RNG_TYPE_STD].x+segButton[ID_RNG_TYPE_STD].width)
            {
                motion=ID_RNG_TYPE_STD;
            }
            else
            {
                motion=ID_RNG_NONE;
            }
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }
    dtaFig->Refresh();
}

void MydoctorDlg::OnLeaveDtaFig(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    dtaFig->Refresh();
}

void MydoctorDlg::OnClickDtaFig(wxMouseEvent& event)
{
    int k=mtg->segset.Ks;
    int i;

    for(i=0;i<k;i++)
    {
        if(motion==ID_SEGMENT_COUNT+i)
        {
            mtg->iseg.k=i;
            break;
        }
    }

    if(i==k)
    {
        if(motion==ID_RNG_TYPE_TL)
        {
            mtg->iseg.type=2;
        }
        else if(motion==ID_RNG_TYPE_TR)
        {
            mtg->iseg.type=3;
        }
        else if(motion==ID_RNG_TYPE_STD)
        {
            mtg->iseg.type=1;
        }
    }

    dtaFig->Refresh();
}

void MydoctorDlg::OnPaintDeslistHeader(wxPaintEvent& event)
{
    wxPaintDC dc(desListHeader);
    int w,h;
    desListHeader->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=25;
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        int i=1;
        //memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("左超前(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("上超前(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("平偏(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("高偏(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnPaintSeglistHeader(wxPaintEvent& event)
{
    wxPaintDC dc(segListHeader);
    int w,h;
    segListHeader->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=25;
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        int i=1;
        //memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("左超前(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("上超前(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("平偏(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("高偏(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnPaintJust(wxPaintEvent& event)
{
    wxPaintDC dc(panelJust);
    int w,h;
    panelJust->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        int x1,y1,w1,h1;
        x1=10;
        y1=15;
        memDC.DrawLabel(_("油缸行程"),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("左"),wxRect(x1+80,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        just_laj_Text->SetSize(x1+100,y1-11,85,-1);
        memDC.DrawLabel(_("右"),wxRect(x1+200,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        just_raj_Text->SetSize(x1+220,y1-11,85,-1);
        memDC.DrawLabel(_("上"),wxRect(x1+320,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        just_uaj_Text->SetSize(x1+340,y1-11,85,-1);
        memDC.DrawLabel(_("下"),wxRect(x1+440,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        just_daj_Text->SetSize(x1+460,y1-11,85,-1);

        //y1+=40;
        //memDC.DrawLabel(_("盾构姿态"),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1+=40;
        memDC.DrawLabel(_("前端"),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("水平"),wxRect(x1+65,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        just_headh_Text->SetSize(x1+100,y1-11,85,-1);

        memDC.DrawLabel(_("垂直"),wxRect(x1+305,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        just_headv_Text->SetSize(x1+340,y1-11,85,-1);
        y1+=30;
        memDC.DrawLabel(_("后端"),wxRect(x1,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("水平"),wxRect(x1+65,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        just_tailh_Text->SetSize(x1+100,y1-11,85,-1);
        memDC.DrawLabel(_("垂直"),wxRect(x1+305,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        just_tailv_Text->SetSize(x1+340,y1-11,85,-1);

        segButton[ID_RNG_JUST_CAL].x=x1+460;
        segButton[ID_RNG_JUST_CAL].y=y1-12;
        segButton[ID_RNG_JUST_CAL].width=65;
        segButton[ID_RNG_JUST_CAL].height=25;
        if(motion==ID_RNG_JUST_CAL)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            //memDC.SetTextForeground(icolor[2]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            //memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(segButton[ID_RNG_JUST_CAL],3);
        memDC.DrawLabel(_("计算"),segButton[ID_RNG_JUST_CAL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=30;
        w1=w-x1*2;
        h1=h-y1-10;
        memDC.SetPen(ipen[0]);
        memDC.SetBrush(wxBrush(wxColor(30,40,50)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        int nh=road_number_horizon(&mtg->r1);
        h_element* he;
        memDC.SetTextForeground(wxColor(255,255,255));
        for(int i=0;i<nh;i++)
        {
            he=road_horizon(&mtg->r1,i);
            if(he->type==ROAD_TYPE_START_POINT)
            {
                istr=wxString::Format(_("%d "),i+1)+_("起点 ")+wxString::Format(_("x=%.3f "),he->x1);
                istr=istr+wxString::Format(_("y=%.3f "),he->y1);
                istr=istr+wxString::Format(_("方位  %.5f "),he->angle1*180/PI);
                memDC.DrawLabel(istr,wxRect(x1+10,y1+15+i*25,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else if(he->type==ROAD_TYPE_LINE)
            {
                istr=wxString::Format(_("%d "),i+1)+_("直线 ")+wxString::Format(_("L=%.3f "),he->length);
                memDC.DrawLabel(istr,wxRect(x1+10,y1+15+i*25,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else if(he->type==ROAD_TYPE_ARC)
            {
                istr=wxString::Format(_("%d "),i+1)+_("园曲线 ")+wxString::Format(_("R=%.3f "),he->radius);
                istr=istr+wxString::Format(_("L=%.3f "),he->length);
                if(he->pz==ROAD_RIGHT) istr=istr+ _("右转弯");
                else istr=istr+ _("左转弯");
                memDC.DrawLabel(istr,wxRect(x1+10,y1+15+i*25,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else if(he->type==ROAD_TYPE_END_POINT)
            {
                istr=wxString::Format(_("%d "),i+1)+_("终点 ")+wxString::Format(_("x=%.3f "),he->x1);
                istr=istr+wxString::Format(_("y=%.3f "),he->y1);
                istr=istr+wxString::Format(_("mile=%.3f "),he->l1);
                //istr=istr+wxString::Format(_("方位  %.5f "),he->angle1*180/PI);
                memDC.DrawLabel(istr,wxRect(x1+10,y1+15+i*25,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }


        if(nh>2)
        {
            double l1,l2,li;
            double jx1,jy1,jx2,jy2;
            double dx,dy;
            double ori,beta,deta;
            int x2,y2,w2,h2;
            int x3,y3,xi,yi;
            double s1,s2,len;

            x2=x1+10;
            y2=y1+h1/2;
            w2=w1-20;
            h2=h1-20;

            l1=road_horizon(&mtg->r1,0)->l1;
            l2=road_horizon(&mtg->r1,nh-1)->l1;
            road_l2xy(&mtg->r1,l1,&jx1,&jy1,0);
            road_l2xy(&mtg->r1,l2,&jx2,&jy2,0);
            road_l2xy(&mtg->r,l1,0,0,&ori);
            dx=jx2-jx1;
            dy=jy2-jy1;
            beta=atan2(dy,dx);
            if(beta<0.0) beta+=2.0*PI;
            deta=beta-ori;
            if(deta<-PI) deta+=2.0*PI;
            else if(deta>PI) deta-=2.0*PI;
            len=sqrt(dx*dx+dy*dy);
            len=len*cos(deta);
            s1=len/w2;
            s2=s1/2.0;

            x3=x2;
            y3=y2;
            //trace(0,"len=%.4f,w2=%d,si=%.12f\n",len,w2,si);
            while(l1<l2)
            {
                l1+=1.0;
                road_l2xy(&mtg->r1,l1,&jx2,&jy2,0);
                //trace(0,"x2=%.4f,y2=%.4f\n",jx2,jy2);
                dx=jx2-jx1;
                dy=jy2-jy1;
                len=sqrt(dx*dx+dy*dy);
                beta=atan2(dy,dx);
                if(beta<0.0) beta+=2.0*PI;
                deta=beta-ori;
                if(deta<-PI) deta+=2.0*PI;
                else if(deta>PI) deta-=2.0*PI;
                dx=len*cos(deta)/s1;
                dy=len*sin(deta)/s2;
                xi=x2+dx;
                yi=y2+dy;
                //trace(0,"dx=%.4f,dy=%.4f,x1=%d,y1=%d,x2=%d,y2=%d\n",dx,dy,x2,y2,xi,yi);
                memDC.DrawLine(x3,y3,xi,yi);
                x3=xi;
                y3=yi;
            }
            //trace(0,"done,%d\n",1);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnMotionJust(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>segButton[ID_RNG_JUST_CAL].x && x<segButton[ID_RNG_JUST_CAL].x+segButton[ID_RNG_JUST_CAL].width)
    {
        if(y>segButton[ID_RNG_JUST_CAL].y && y<segButton[ID_RNG_JUST_CAL].y+segButton[ID_RNG_JUST_CAL].height)
        {
            motion=ID_RNG_JUST_CAL;
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }
    else
    {
        motion=ID_RNG_NONE;
    }
    panelJust->Refresh();
}

void MydoctorDlg::OnLeaveJust(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    panelJust->Refresh();
}

void MydoctorDlg::OnClickJust(wxMouseEvent& event)
{
    if(motion==ID_RNG_JUST_CAL)
    {
        double ival;
        just_uaj_Text->GetValue().ToDouble(&ival);
        mtg->m1.aj[0]=ival/1000.0;
        just_daj_Text->GetValue().ToDouble(&ival);
        mtg->m1.aj[1]=ival/1000.0;
        just_laj_Text->GetValue().ToDouble(&ival);
        mtg->m1.aj[2]=ival/1000.0;
        just_raj_Text->GetValue().ToDouble(&ival);
        mtg->m1.aj[3]=ival/1000.0;

        just_headh_Text->GetValue().ToDouble(&ival);
        mtg->m.headh=ival/1000.0;
        just_headv_Text->GetValue().ToDouble(&ival);
        mtg->m.headv=ival/1000.0;
        just_tailh_Text->GetValue().ToDouble(&ival);
        mtg->m.tailh=ival/1000.0;
        just_tailv_Text->GetValue().ToDouble(&ival);
        mtg->m.tailv=ival/1000.0;

        ///计算姿态数据
        mtg->m.tailc=mtg->prj.mile1;
        mtg->m.headc=mtg->m.tailc+5.4;
        double x1,y1,z1;
        double x2,y2,z2;
        double ori,phi;
        road_l2xy(&mtg->r,mtg->m.headc,&x1,&y1,&ori);
        ori+=PI/2.0;
        mtg->m.head[0]=x1+mtg->m.headh*cos(ori);
        mtg->m.head[1]=y1+mtg->m.headh*sin(ori);
        road_l2h(&mtg->r,mtg->m.headc,&z1,0);
        mtg->m.head[2]=z1+mtg->m.headv;

        road_l2xy(&mtg->r,mtg->m.tailc,&x1,&y1,&ori);
        ori+=PI/2.0;
        mtg->m.tail[0]=x1+mtg->m.tailh*cos(ori);
        mtg->m.tail[1]=y1+mtg->m.tailh*sin(ori);
        road_l2h(&mtg->r,mtg->m.tailc,&z1,0);
        mtg->m.tail[2]=z1+mtg->m.tailv;

        x1=mtg->m.head[0];
        y1=mtg->m.head[1];
        z1=mtg->m.head[2];

        x2=mtg->m.tail[0];
        y2=mtg->m.tail[1];
        z2=mtg->m.tail[2];

        ori=atan2(y1-y2,x1-x2);
        if(ori<0.0) ori+=2.0*PI;
        mtg->m.inc1[2]=ori*180.0/PI;

        double len=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        phi=atan((z1-z2)/len);
        if(phi<0.0) phi+=2.0*PI;
        mtg->m.inc1[1]=phi*180.0/PI;

        mtg->m.aj[0]=mtg->m1.aj[0];
        mtg->m.aj[1]=mtg->m1.aj[1];
        mtg->m.aj[2]=mtg->m1.aj[2];
        mtg->m.aj[3]=mtg->m1.aj[3];
        mtg->m1=mtg->m;

        mtg_init_position(mtg);
        mtg_seg_cal(mtg);
        mtg_std_segs(mtg,0);
    }
    panelJust->Refresh();
}

/*
void MydoctorDlg::OnTimer(wxTimerEvent& event)
{
    static int tick=0;
    double ival;
    double mile;
    int in;
    tick++;
    //isel=segList->GetFirstSelected();
    //if(isel<=0) in=1;
    if(tick % 10==0)
    {

    }
    if(tick==1200) tick=0;
}*/
