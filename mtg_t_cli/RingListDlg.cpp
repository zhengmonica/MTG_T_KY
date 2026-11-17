///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "RingListDlg.h"
#include "mtg_t_cliApp.h"
//#include "ConfirmDlg.h"
//#include "SegDialog.h"
//#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(RingListDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(RingListDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(RingListDlg)


const long RingListDlg::ID_PANEL1 = wxNewId();                  //标题
//*)

RingListDlg::RingListDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int dh=20;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelTitle = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));

    panelTitle->m_maximize_box=0;
    panelTitle->m_minimize_box=0;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("管环选型");
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,31), wxSize(w,h-31), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    segList = new wxListView(panelMain, wxID_ANY, wxPoint(0,45), wxSize(w,h-50), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&RingListDlg::OnPaintMain,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    int i=0;
    segList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    segList->InsertColumn(i++,_("环号"),wxLIST_FORMAT_CENTRE,65);
    segList->InsertColumn(i++,_("类型"),wxLIST_FORMAT_CENTRE,65);
    segList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,90);
    segList->InsertColumn(i++,_("点位"),wxLIST_FORMAT_CENTRE,65);
    segList->InsertColumn(i++,_("水平偏差"),wxLIST_FORMAT_CENTRE,75);
    segList->InsertColumn(i++,_("垂直偏差"),wxLIST_FORMAT_CENTRE,75);
    segList->InsertColumn(i++,_("水平超前量"),wxLIST_FORMAT_CENTRE,75);
    segList->InsertColumn(i++,_("垂直超前量"),wxLIST_FORMAT_CENTRE,75);
    segList->InsertColumn(i++,_("日期"),wxLIST_FORMAT_CENTRE,140);

    Type=0;
    motion=ID_RNG_LIST_NONE;
    UpdateList();
}

RingListDlg::~RingListDlg()
{

}

void RingListDlg::UpdateList()
{
    segList->DeleteAllItems();
    wxString istr;
    double ival;
    double ilen=mtg->segset.De;
    time_t now;
    time(&now);
    if(Type==0)
    {
        for(int i=0;i<MAX_SEG;i++)
        {
            int j=1;

            segList->InsertItem(i,_(""));

            segList->SetItem(i,j++,wxString::Format(_("%d"),mtg->segs[i].numb)); ///管片号
            if(mtg->segs[i].type==0)
            {
                istr=_("通用环");
            }
            else if(mtg->segs[i].type==1)
            {
                istr=_("标准环");
            }
            else if(mtg->segs[i].type==2)
            {
                istr=_("左转环");
            }
            else if(mtg->segs[i].type==3)
            {
                istr=_("右转环");
            }
            segList->SetItem(i,j++,istr); ///类型
            //segList->SetItem(i,j++,wxString::Format(_("%.3f"),mtg->segs[i].tailc)); ///
            if(mtg->segs[i].k==0) segList->SetItem(i,j++,wxString::Format(_("%d"),mtg->segset.Ks)); ///
            else segList->SetItem(i,j++,wxString::Format(_("%d"),mtg->segs[i].k)); ///
            //segList->SetItem(i,j++,wxString::Format(_("%.1f"),mtg->segs[i].tailh*1000.0)); ///
            //segList->SetItem(i,j++,wxString::Format(_("%.1f"),mtg->segs[i].tailv*1000.0)); ///
            ival=ilen*tan(mtg->segs[i].hpz);
            segList->SetItem(i,j++,wxString::Format(_("%.1f"),ival*1000.0));
            ival=ilen*tan(mtg->segs[i].vpz);
            segList->SetItem(i,j++,wxString::Format(_("%.1f"),ival*1000.0));
            segList->SetItem(i,j++,wxDateTime(now).Format(_("%Y-%m-%d %H:%M:%S")));
        }
    }
    else if(Type==1)
    {

    }
}

void RingListDlg::OnPaintMain(wxPaintEvent& event)
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        memDC.DrawRectangle(0,5,w,41);
        int x1,y1,w1,h1;
        x1=0;
        y1=5;
        h1=41;
        int i=1;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
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
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1+h1/2,x1+w1,y1+h1);
        memDC.DrawLabel(_("水平"),wxRect(x1,y1+h1/2,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1,y1+h1/2,x1+w1*2,y1+h1/2);
        memDC.DrawLabel(_("位置偏差[ mm ]"),wxRect(x1,y1,w1*2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("垂直"),wxRect(x1,y1+h1/2,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1+h1/2,x1+w1,y1+h1);
        memDC.DrawLabel(_("左-右"),wxRect(x1,y1+h1/2,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1,y1+h1/2,x1+w1*2,y1+h1/2);
        memDC.DrawLabel(_("超前量[ mm ]"),wxRect(x1,y1,w1*2,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("上-下"),wxRect(x1,y1+h1/2,w1,h1/2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("日期"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=segList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}
