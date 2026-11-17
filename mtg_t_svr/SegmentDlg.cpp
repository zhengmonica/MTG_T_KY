///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SegmentDlg.h"
#include "mtg_t_svrMain.h"
#include "mtg_t_svrApp.h"
//#include "confirmdlg.h"
#include "RingListDlg.h"
//#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include "SegRecordDialog.h"
#include "ConfirmDlg.h"
#include "RecordQueryDlg.h"

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

//*)

SegmentDlg::SegmentDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
    int x2,y2,w2,h2;
    x1=7;
    y1=59;
    w1=w-x1*2;
    h1=h-114;

    panelSeging = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSegRecord = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    x2=14;
    y2=9;
    w2=w1-28-75;
    h2=h1-9-15;
    panelSegRecordList = new wxPanel(panelSegRecord, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    SegRecordList = new wxListView(panelSegRecordList, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    x2=x2+w2+10;
    w2=65;
    panelSegRecordButton = new wxPanel(panelSegRecord, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));


    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelSeging->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelSegRecord->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelSegRecordList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelSegRecordButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelSegRecord->Show(false);


    x2=0;
    y2=0;
    w2=w1;
    h2=40;
    desbuttons = new wxPanel(panelSeging, wxID_ANY, wxPoint(1,1), wxSize(120,h1-2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desbuttons->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    desOneText = new wxPanel(panelSeging, wxID_ANY, wxPoint(128,8), wxSize(w1-135,h1-15), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desOneText->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
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

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintMain,0,this);

	panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentDlg::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentDlg::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnClickPage,0,this);

    panelSeging->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintSeging,0,this);
    panelSegRecord->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintSegRecord,0,this);

    desbuttons->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintDesButton,0,this);
    desbuttons->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentDlg::OnMotionDesButton,0,this);
    desbuttons->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentDlg::OnLeaveDesButton,0,this);
    desbuttons->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnClickDesButton,0,this);

    desOneText->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintOne,0,this);
    desOneText->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentDlg::OnMotionOne,0,this);
    desOneText->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentDlg::OnLeaveOne,0,this);
    desOneText->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnClickOne,0,this);

    dtaPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintDtaHeader,0,this);

    dtaFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintDtaFig,0,this);
    dtaFig->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentDlg::OnMotionDtaFig,0,this);
    dtaFig->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentDlg::OnLeaveDtaFig,0,this);
    dtaFig->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnClickDtaFig,0,this);

    desListHeader->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintDeslistHeader,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnClickBottom,0,this);

    dtaList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&SegmentDlg::OnDtaSelect,0,this);

    panelSegRecordList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintSegRecordList,0,this);
    panelSegRecordButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentDlg::OnPaintSegRecordButton,0,this);
    panelSegRecordButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentDlg::OnMotionSegRecordButton,0,this);
    panelSegRecordButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentDlg::OnLeaveSegRecordButton,0,this);
    panelSegRecordButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentDlg::OnClickSegRecordButton,0,this);

    SegRecordList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&SegmentDlg::OnRecordSelect,0,this);
    SegRecordList->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&SegmentDlg::OnRecordDeselected,0,this);
    SegRecordList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&SegmentDlg::OnRecordActivated,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    page=ID_RNG_PAGE_DES;
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
    SegRecordList->InsertColumn(i++,_("环号"),wxLIST_FORMAT_CENTRE,50);
    SegRecordList->InsertColumn(i++,_("管环类型"),wxLIST_FORMAT_CENTRE,90);
    SegRecordList->InsertColumn(i++,_("点位"),wxLIST_FORMAT_CENTRE,50);
    SegRecordList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,80);
    SegRecordList->InsertColumn(i++,_("水平偏差"),wxLIST_FORMAT_CENTRE,75);
    SegRecordList->InsertColumn(i++,_("垂直偏差"),wxLIST_FORMAT_CENTRE,75);
    SegRecordList->InsertColumn(i++,_("时间"),wxLIST_FORMAT_CENTRE,140);

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
    LoadData();
}

SegmentDlg::~SegmentDlg()
{

}

void SegmentDlg::LoadData()
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

    //InitialSeging();
    mtg_init_seging(mtg);
    des_numb_Text->SetValue(wxString::Format(_("%d"),mtg->iseg.numb));
    des_mile_Text->SetValue(wxString::Format(_("%.3f"),mtg->iseg.headc));
    //trace(0,"segment:cal=%d\n",cal);
    res=0;
    nres=0;
    nres=mtg_std_segings(mtg,&res);
    UpdateSegings();
    UpdateRecordList();

    modified=0;
}

void SegmentDlg::OnDtaSelect(wxListEvent& event)
{
    //isel=segList->GetFirstSelected();
    dtaFig->Refresh();
}

void SegmentDlg::InitialSeging()
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

void SegmentDlg::UpdateSegings()
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

void SegmentDlg::OnMotionBottom(wxMouseEvent& event)
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

void SegmentDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    panelBottom->Refresh();
}

void SegmentDlg::OnClickBottom(wxMouseEvent& event)
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
//            UpdateSegs();
//            nseged=0;
//            if(seged) free(seged);
//            seged=0;
//            nseged=mtg_query_segeds(mtg,&seged);
//            UpdateSeged();
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
//            UpdateSegs();
//            nseged=0;
//            if(seged) free(seged);
//            seged=0;
//            nseged=mtg_query_segeds(mtg,&seged);
//            UpdateSeged();
        }
        modified=0;
    }
    else if(motion==ID_RNG_BTN_EXP)
    {
        if(page==ID_RNG_PAGE_DES)
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
        else if(page==ID_RNG_PAGE_REC)
        {
            if(mtg->SegRecNum<=0) return;
            wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
            if(fileDlg.ShowModal()==wxID_OK)
            {
                wxString strpath=fileDlg.GetPath();
                FILE *fp=fopen(strpath.mb_str(wxConvLocal),"w");
                if(fp)
                {
                    wxString strtype;
                    fprintf(fp,"环号,管环类型,点位,里程,水平偏差,垂直偏差,时间\n");
                    fflush(fp);
                    for(int i=0;i<mtg->SegRecNum;i++)
                    {
                        if(mtg->segrecord[i].segtype==0)
                            strtype=_("标准环");
                        else if(mtg->segrecord[i].segtype==1)
                            strtype=_("左转弯");
                        else if(mtg->segrecord[i].segtype==2)
                            strtype=_("右转弯");
                        else if(mtg->segrecord[i].segtype==3)
                            strtype=_("通用环");
                        fprintf(fp,"%d,",mtg->segrecord[i].segnum);fflush(fp);
                        fprintf(fp,"%s,",strtype.mb_str(wxConvLocal));fflush(fp);
                        fprintf(fp,"%d,",mtg->segrecord[i].location);fflush(fp);
                        fprintf(fp,"%.4f,",mtg->segrecord[i].mile);fflush(fp);
                        fprintf(fp,"%d,",(int)(mtg->segrecord[i].offh*1000.0));fflush(fp);
                        fprintf(fp,"%d,",(int)(mtg->segrecord[i].offv*1000.0));fflush(fp);
                        strtype=wxDateTime(mtg->segrecord[i].t).Format(_("%Y-%m-%d %H:%M:%S"));
                        fprintf(fp,"%s\n",strtype.mb_str(wxConvLocal));fflush(fp);
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

void SegmentDlg::WriteMsg(wxString msg,int col)
{
    Msg=msg;
    Mtype=col;
    panelBottom->Refresh();
}

void SegmentDlg::OnPaintMain(wxPaintEvent& event)
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

void SegmentDlg::OnPaintPage(wxPaintEvent& event)
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

        x1+=w1;
        segButton[ID_RNG_PAGE_REC].x=x1;
        segButton[ID_RNG_PAGE_REC].y=y1;
        segButton[ID_RNG_PAGE_REC].width=w1;
        segButton[ID_RNG_PAGE_REC].height=h1;
        if(page==ID_RNG_PAGE_REC || motion==ID_RNG_PAGE_REC)
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
            if(page!=ID_RNG_PAGE_REC)
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
        memDC.DrawLabel(_("拼装记录"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
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

void SegmentDlg::OnMotionPage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    //if(y>segButton[ID_RNG_PAGE_DONE].y && y<segButton[ID_RNG_PAGE_DONE].y+segButton[ID_RNG_PAGE_DONE].height)
    if(y>segButton[ID_RNG_PAGE_DES].y && y<segButton[ID_RNG_PAGE_DES].y+segButton[ID_RNG_PAGE_DES].height)
    {
        if(x>segButton[ID_RNG_PAGE_DES].x && x<segButton[ID_RNG_PAGE_DES].x+segButton[ID_RNG_PAGE_DES].width)
        {
            motion=ID_RNG_PAGE_DES;
        }
        else if(x>segButton[ID_RNG_PAGE_REC].x && x<segButton[ID_RNG_PAGE_REC].x+segButton[ID_RNG_PAGE_REC].width)
        {
            motion=ID_RNG_PAGE_REC;
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

void SegmentDlg::OnLeavePage(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    panelPage->Refresh();
}

void SegmentDlg::OnClickPage(wxMouseEvent& event)
{
    if(motion==ID_RNG_PAGE_DES)
    {
        page=ID_RNG_PAGE_DES;
        panelSeging->Show(true);
        panelSegRecord->Show(false);
    }
    else if(motion==ID_RNG_PAGE_REC)
    {
        page=ID_RNG_PAGE_REC;
        panelSeging->Show(false);
        panelSegRecord->Show(true);
    }
    panelPage->Refresh();
}

void SegmentDlg::OnPaintSeging(wxPaintEvent& event)
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

void SegmentDlg::OnPaintSegRecord(wxPaintEvent& event)
{
    wxPaintDC dc(panelSegRecord);
    int w,h;
    panelSegRecord->GetSize(&w,&h);
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

void SegmentDlg::OnPaintDesButton(wxPaintEvent& event)
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

void SegmentDlg::OnMotionDesButton(wxMouseEvent& event)
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

void SegmentDlg::OnLeaveDesButton(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    desbuttons->Refresh();
}

void SegmentDlg::OnClickDesButton(wxMouseEvent& event)
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

void SegmentDlg::OnPaintOne(wxPaintEvent& event)
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

void SegmentDlg::OnMotionOne(wxMouseEvent& event)
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

void SegmentDlg::OnLeaveOne(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    desOneText->Refresh();
}

void SegmentDlg::OnClickOne(wxMouseEvent& event)
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

void SegmentDlg::OnPaintDtaHeader(wxPaintEvent& event)
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

void SegmentDlg::OnPaintDtaFig(wxPaintEvent& event)
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

void SegmentDlg::OnMotionDtaFig(wxMouseEvent& event)
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

void SegmentDlg::OnLeaveDtaFig(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    dtaFig->Refresh();
}

void SegmentDlg::OnClickDtaFig(wxMouseEvent& event)
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

void SegmentDlg::OnPaintDeslistHeader(wxPaintEvent& event)
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

void SegmentDlg::OnPaintSegRecordList(wxPaintEvent& event)
{
    wxPaintDC dc(panelSegRecordList);
    int w,h;
    panelSegRecordList->GetClientSize(&w,&h);
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
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("管环类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("水平偏差"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("垂直偏差"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        i=0;
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        x1=1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=SegRecordList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,w-1,y1+1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentDlg::OnPaintSegRecordButton(wxPaintEvent& event)
{
    wxPaintDC dc(panelSegRecordButton);
    int w,h;
    panelSegRecordButton->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(238,244,250)));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(chs);
        memDC.SetPen(wxPen(wxColor(158,158,158)));

        int x1=0;
        int y1=0;
        int w1=w;
        int h1=25;

        segButton[ID_RNG_REC_ADD].x=x1;
        segButton[ID_RNG_REC_ADD].y=y1;
        segButton[ID_RNG_REC_ADD].width=w1;
        segButton[ID_RNG_REC_ADD].height=h1;
        if(motion==ID_RNG_REC_ADD)
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
        segButton[ID_RNG_REC_EDI].x=x1;
        segButton[ID_RNG_REC_EDI].y=y1;
        segButton[ID_RNG_REC_EDI].width=w1;
        segButton[ID_RNG_REC_EDI].height=h1;
        int sel = SegRecordList->GetFirstSelected();
        if(sel>=0)
        {
            if(motion==ID_RNG_REC_EDI)
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
        segButton[ID_RNG_REC_DEL].x=x1;
        segButton[ID_RNG_REC_DEL].y=y1;
        segButton[ID_RNG_REC_DEL].width=w1;
        segButton[ID_RNG_REC_DEL].height=h1;
        if(sel==-1)
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        else
        {
            if(motion==ID_RNG_REC_DEL)
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

        y1+=32;
        segButton[ID_RNG_REC_QRY].x=x1;
        segButton[ID_RNG_REC_QRY].y=y1;
        segButton[ID_RNG_REC_QRY].width=w1;
        segButton[ID_RNG_REC_QRY].height=h1;
        if(motion==ID_RNG_REC_QRY)
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
        memDC.DrawLabel(_("查询"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentDlg::OnMotionSegRecordButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>segButton[ID_RNG_REC_ADD].y && y<segButton[ID_RNG_REC_ADD].y+segButton[ID_RNG_REC_ADD].height)
    {
        if(x>segButton[ID_RNG_REC_ADD].x && x<segButton[ID_RNG_REC_ADD].x+segButton[ID_RNG_REC_ADD].width)
        {
            motion=ID_RNG_REC_ADD;
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }
    else if(y>segButton[ID_RNG_REC_EDI].y && y<segButton[ID_RNG_REC_EDI].y+segButton[ID_RNG_REC_EDI].height)
    {
        if(x>segButton[ID_RNG_REC_EDI].x && x<segButton[ID_RNG_REC_EDI].x+segButton[ID_RNG_REC_EDI].width)
        {
            motion=ID_RNG_REC_EDI;
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }
    else if(y>segButton[ID_RNG_REC_DEL].y && y<segButton[ID_RNG_REC_DEL].y+segButton[ID_RNG_REC_DEL].height)
    {
        if(x>segButton[ID_RNG_REC_DEL].x && x<segButton[ID_RNG_REC_DEL].x+segButton[ID_RNG_REC_DEL].width)
        {
            motion=ID_RNG_REC_DEL;
        }
        else
        {
            motion=ID_RNG_NONE;
        }
    }
    else if(y>segButton[ID_RNG_REC_QRY].y && y<segButton[ID_RNG_REC_QRY].y+segButton[ID_RNG_REC_QRY].height)
    {
        if(x>segButton[ID_RNG_REC_QRY].x && x<segButton[ID_RNG_REC_QRY].x+segButton[ID_RNG_REC_QRY].width)
        {
            motion=ID_RNG_REC_QRY;
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

    panelSegRecordButton->Refresh();
}

void SegmentDlg::OnLeaveSegRecordButton(wxMouseEvent& event)
{
    motion=ID_RNG_NONE;
    panelSegRecordButton->Refresh();
}

void SegmentDlg::OnClickSegRecordButton(wxMouseEvent& event)
{
    if(motion==ID_RNG_REC_ADD)
    {
        SegRecordDialog dlg(this);
        dlg.Center();
        dlg.segnum->SetFocus();
        if(dlg.ShowModal()==wxID_OK)
        {
            SEG_RECORD rec;
            double d;
            wxString str;
            dlg.segnum->GetValue().ToDouble(&d);
            rec.segnum=(int)d;

            str=dlg.segtype->GetStringSelection();
            if(_("标准环")==str)
                rec.segtype=0;
            else if(_("左转弯")==str)
                rec.segtype=1;
            else if(_("右转弯")==str)
                rec.segtype=2;
            else if(_("通用环")==str)
                rec.segtype=3;

            dlg.location->GetValue().ToDouble(&d);
            rec.location=(int)d;
            time(&rec.t);

            ///根据环号查询该环最新记录中的里程、切口水平偏差、切口垂直偏差
            if(mtg_query_segrecord(mtg,&rec))
            {
                if(mtg_add_record(mtg,&rec))
                {
                    WriteMsg(_("增加拼装记录成功！"),0);
                    UpdateRecordList();
                }
                else
                {
                    WriteMsg(_("增加拼装记录失败！"),1);
                }
            }
            else
            {
                WriteMsg(_("增加拼装记录失败！"),1);
            }
        }
    }
    else if(motion==ID_RNG_REC_EDI)
    {
        int sel = SegRecordList->GetFirstSelected();
        if(sel<0)
            return;
        SegRecordDialog dlg(this);
        dlg.Center();
        dlg.segnum->SetValue(wxString::Format(_("%d"),mtg->segrecord[sel].segnum));
        if(mtg->segrecord[sel].segtype==0)
            dlg.segtype->SetStringSelection(_("标准环"));
        else if(mtg->segrecord[sel].segtype==1)
            dlg.segtype->SetStringSelection(_("左转弯"));
        else if(mtg->segrecord[sel].segtype==2)
            dlg.segtype->SetStringSelection(_("右转弯"));
        else if(mtg->segrecord[sel].segtype==3)
            dlg.segtype->SetStringSelection(_("通用环"));
        dlg.location->SetValue(wxString::Format(_("%d"),mtg->segrecord[sel].location));

        if(dlg.ShowModal()==wxID_OK)
        {
            SEG_RECORD rec;
            double d;
            wxString str;
            dlg.segnum->GetValue().ToDouble(&d);
            rec.segnum=(int)d;

            str=dlg.segtype->GetStringSelection();
            if(_("标准环")==str)
                rec.segtype=0;
            else if(_("左转弯")==str)
                rec.segtype=1;
            else if(_("右转弯")==str)
                rec.segtype=2;
            else if(_("通用环")==str)
                rec.segtype=3;

            dlg.location->GetValue().ToDouble(&d);
            rec.location=(int)d;
            time(&rec.t);
            if(mtg_query_segrecord(mtg,&rec))   ///判断该环是不是存在
            {
                if(mtg_modify_record(mtg,sel,&rec))
                {
                    WriteMsg(_("编辑拼装记录成功！"),0);
                    UpdateRecordList();
                }
                else
                {
                    WriteMsg(_("编辑拼装记录失败！"),1);
                }
            }
            else
            {
                WriteMsg(_("编辑拼装记录失败！"),1);
            }
        }
    }
    else if(motion==ID_RNG_REC_DEL)
    {
        int sel = SegRecordList->GetFirstSelected();
        if(sel<0)
            return;
        ConfirmDlg dlg(this);
        dlg.confirmMsg=_("确定删除第")+wxString::Format(_("%d"),mtg->segrecord[sel].segnum)+_("环拼装记录吗？");
        dlg.Center();
        if(dlg.ShowModal()==wxID_OK)
        {
            if(mtg_remove_record(mtg,sel))
            {
                WriteMsg(_("删除拼装记录成功！"),0);
                UpdateRecordList();
            }
            else
            {
                WriteMsg(_("删除拼装记录失败！"),1);
            }
        }
    }
    else if(motion==ID_RNG_REC_QRY)
    {
        RecordQueryDlg dlg(this);
        dlg.Center();
        dlg.ShowModal();
//        wxString str=_T("成功查询到")+wxString::Format(_(" %d 条拼装记录！"),dlg.nres);
//        WriteMsg(str,0);
    }
}

void SegmentDlg::UpdateRecordList()
{
    SegRecordList->DeleteAllItems();
//    wxMessageBox(wxString::Format(_("%d"),mtg->SegRecNum));
    for(int i=0;i<mtg->SegRecNum;i++)
    {
        SegRecordList->InsertItem(i,wxString::Format(_("%d"),mtg->segrecord[i].segnum));
        if(mtg->segrecord[i].segtype==0)
            SegRecordList->SetItem(i,1,_("标准环"));
        else if(mtg->segrecord[i].segtype==1)
            SegRecordList->SetItem(i,1,_("左转弯"));
        else if(mtg->segrecord[i].segtype==2)
            SegRecordList->SetItem(i,1,_("右转弯"));
        else if(mtg->segrecord[i].segtype==3)
            SegRecordList->SetItem(i,1,_("通用环"));
        SegRecordList->SetItem(i,2,wxString::Format(_("%d"),mtg->segrecord[i].location));
        SegRecordList->SetItem(i,3,wxString::Format(_("%.4f"),mtg->segrecord[i].mile));
        SegRecordList->SetItem(i,4,wxString::Format(_("%d"),(int)(mtg->segrecord[i].offh*1000.0)));
        SegRecordList->SetItem(i,5,wxString::Format(_("%d"),(int)(mtg->segrecord[i].offv*1000.0)));
        SegRecordList->SetItem(i,6,wxDateTime(mtg->segrecord[i].t).Format(_("%Y-%m-%d %H:%M:%S")));
    }
}

void SegmentDlg::OnRecordSelect(wxListEvent& event)
{
    panelSegRecordButton->Refresh();
}

void SegmentDlg::OnRecordDeselected(wxListEvent& event)
{
    panelSegRecordButton->Refresh();
}

void SegmentDlg::OnRecordActivated(wxListEvent& event)
{
    wxMouseEvent e;
    motion=ID_RNG_REC_EDI;
    OnClickSegRecordButton(e);
}
