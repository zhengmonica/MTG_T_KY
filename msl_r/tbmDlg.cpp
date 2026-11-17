///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "tbmDlg.h"
#include "msr_tApp.h"
//#include "confirmdlg.h"
//#include "SegDialog.h"
//#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(tbmDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(tbmDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(tbmDlg)

//*)

tbmDlg::tbmDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;

	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTbm = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w,h-57), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTbm->SetBackgroundColour(wxColor(239,239,239));
    panelPage = new wxPanel(panelTbm, wxID_ANY, wxPoint(0,5), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTbmgen = new wxPanel(panelTbm, wxID_ANY, wxPoint(0,33), wxSize(w,h-85), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTbmgen->SetBackgroundColour(wxColor(239,239,239));
    panelTbmJack = new wxPanel(panelTbm, wxID_ANY, wxPoint(0,33), wxSize(w,h-85), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTbmJack->SetBackgroundColour(wxColor(239,239,239));
    panelTbmJack->Show(false);
    x1=14;
    //y1=9;
    w1=w-x1*2;
    y1=16;

    tbmStaticText2 = new wxStaticText(panelTbmgen, wxID_ANY, _("盾构编号"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tbmIndex = new wxTextCtrl(panelTbmgen, wxID_ANY, wxEmptyString, wxPoint(x1+60,y1-3), wxSize(180,-1), 0);
    tbmStaticText3 = new wxStaticText(panelTbmgen, wxID_ANY, _("铰接类型"), wxPoint(x1+305,y1), wxDefaultSize, 0, _("wxID_ANY"));
    kinkPanel = new wxPanel(panelTbmgen, wxID_ANY, wxPoint(x1+385,y1-4), wxSize(320,23), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    kinkPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    jackFig = new wxPanel(panelTbmJack, wxID_ANY, wxPoint(x1,y1+45), wxSize(w1/2,w1/2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    jackFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    tbmStaticText6 = new wxStaticText(panelTbmJack, wxID_ANY, _("推进油缸组"), wxPoint(x1+w1/2+15,y1+48), wxDefaultSize, 0, _("wxID_ANY"));
    tbmStaticText7 = new wxStaticText(panelTbmJack, wxID_ANY, _("A组油缸"), wxPoint(x1+w1/2+15,y1+78), wxDefaultSize, 0, _("wxID_ANY"));
    panelTypJack = new wxPanel(panelTbmJack, wxID_ANY, wxPoint(x1,y1), wxSize(w1-x1*2-5,42), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTypJack->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelNumJack = new wxPanel(panelTbmJack, wxID_ANY, wxPoint(x1+w1/2+95,y1+45), wxSize(120,22), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelNumJack->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelAngJack = new wxPanel(panelTbmJack, wxID_ANY, wxPoint(x1+w1/2+95,y1+75), wxSize(192,22), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelAngJack->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    jackTxt = new wxTextCtrl(panelAngJack, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    panelJackList = new wxPanel(panelTbmJack, wxID_ANY, wxPoint(x1+w1/2+15,y1+105), wxSize(272,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelJackList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    jackList = new wxListView(panelTbmJack, wxID_ANY, wxPoint(x1+w1/2+15,y1+129), wxSize(272,w1/2-84), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    y1+=30;
    tbmStaticText4 = new wxStaticText(panelTbmgen, wxID_ANY, _("几何参数"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    tbmLine2 = new wxStaticLine(panelTbmgen, wxID_ANY, wxPoint(x1+50,y1+8), wxSize(w1-50,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    y1+=30;
    tbmFigPanel = new wxPanel(panelTbmgen, wxID_ANY, wxPoint(x1,y1-5), wxSize(343,395), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tbmFigPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    tbmTxtPanel = new wxPanel(panelTbmgen, wxID_ANY, wxPoint(x1+353,y1-5), wxSize(w1-353,405), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    tbmTxtPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1+=363;
    tbmL1 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(125,2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL2 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(125,2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL3 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(125,2), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL4 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL5 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL6 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL7 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL8 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmL9 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    y1+=30;
    tbmD1 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmD2 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmD3 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmD4 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=30;
    tbmD5 = new wxTextCtrl(tbmTxtPanel, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tbmDlg::OnPaintMain,0,this);

    panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tbmDlg::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&tbmDlg::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&tbmDlg::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&tbmDlg::OnClickPage,0,this);

    kinkPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tbmDlg::OnPaintKink,0,this);
    kinkPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&tbmDlg::OnMotionKink,0,this);
    kinkPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&tbmDlg::OnLeaveKink,0,this);
    kinkPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&tbmDlg::OnClickKink,0,this);

    jackFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tbmDlg::OnPaintTbmajFig,0,this);

    panelTypJack->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tbmDlg::OnPaintTypeJack,0,this);
    panelTypJack->Connect(wxEVT_MOTION,(wxObjectEventFunction)&tbmDlg::OnMotionTypeJack,0,this);
    panelTypJack->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&tbmDlg::OnLeaveTypeJack,0,this);
    panelTypJack->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&tbmDlg::OnClickTypeJack,0,this);

    panelNumJack->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tbmDlg::OnPaintNumTbmaj,0,this);
    panelNumJack->Connect(wxEVT_MOTION,(wxObjectEventFunction)&tbmDlg::OnMotionNumTbmaj,0,this);
    panelNumJack->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&tbmDlg::OnLeaveNumTbmaj,0,this);
    panelNumJack->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&tbmDlg::OnClickNumTbmaj,0,this);

    panelAngJack->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tbmDlg::OnPaintAngTbmaj,0,this);
    panelAngJack->Connect(wxEVT_MOTION,(wxObjectEventFunction)&tbmDlg::OnMotionAngTbmaj,0,this);
    panelAngJack->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&tbmDlg::OnLeaveAngTbmaj,0,this);
    panelAngJack->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&tbmDlg::OnClickAngTbmaj,0,this);

    tbmFigPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tbmDlg::OnPaintTbmFig,0,this);
    tbmTxtPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tbmDlg::OnPaintTbmTxt,0,this);
    panelJackList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tbmDlg::OnPaintAjlistHeader,0,this);
    jackList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&tbmDlg::OnListJackSelect,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tbmDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&tbmDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&tbmDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&tbmDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    int i=0;
    jackList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    jackList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,65);
    jackList->InsertColumn(i++,_("油缸"),wxLIST_FORMAT_CENTRE,65);
    jackList->InsertColumn(i++,_("角度"),wxLIST_FORMAT_CENTRE,85);

    wxString str;
    i=0;

    i=i-1;
    motion=ID_TBM_NONE;
    page=ID_TBM_PAGE_GEN;
    jack=ID_TBM_MAIN_JACK;

    tbm=msr->tbm;

    checkBoxWidth=14;
    checkBoxHeight=14;
    radioBoxR1=7;
    radioBoxR2=4;

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

    UpdateJack();
    jackList->Select(0);

    tbmIndex->SetValue(wxString(tbm.name,wxConvUTF8));
    tbmD1->SetValue(wxString::Format(_("%.1f"),tbm.D[0]*1000.0));
    tbmD2->SetValue(wxString::Format(_("%.1f"),tbm.D[1]*1000.0));
    tbmD3->SetValue(wxString::Format(_("%.1f"),tbm.D[2]*1000.0));
    tbmD4->SetValue(wxString::Format(_("%.1f"),tbm.D[3]*1000.0));
    tbmD5->SetValue(wxString::Format(_("%.1f"),tbm.D[4]*1000.0));
    tbmL1->SetValue(wxString::Format(_("%.1f"),tbm.L[0]*1000.0));
    tbmL2->SetValue(wxString::Format(_("%.1f"),tbm.L[1]*1000.0));
    tbmL3->SetValue(wxString::Format(_("%.1f"),tbm.L[2]*1000.0));
    tbmL4->SetValue(wxString::Format(_("%.1f"),tbm.L[3]*1000.0));
    tbmL5->SetValue(wxString::Format(_("%.1f"),tbm.L[4]*1000.0));
    tbmL6->SetValue(wxString::Format(_("%.1f"),tbm.L[5]*1000.0));
    tbmL7->SetValue(wxString::Format(_("%.1f"),tbm.L[6]*1000.0));
    tbmL8->SetValue(wxString::Format(_("%.1f"),tbm.L[7]*1000.0));
    tbmL9->SetValue(wxString::Format(_("%.1f"),tbm.L[8]*1000.0));
}

tbmDlg::~tbmDlg()
{

}

void tbmDlg::UpdateJack()
{
    jackList->DeleteAllItems();
    if(jack==ID_TBM_MAIN_JACK)
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
    else if(jack==ID_TBM_TAIL_JACK)
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
    else if(jack==ID_TBM_HEAD_JACK)
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

void tbmDlg::OnPaintAjlistHeader(wxPaintEvent& event)
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

void tbmDlg::OnListJackSelect(wxListEvent& event)
{
    int sel=jackList->GetFirstSelected();
    if(sel<0 || sel>=10) return;
    tbmStaticText7->SetLabel(ajname[sel]+_("油缸"));
    if(jack==ID_TBM_MAIN_JACK)
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.aj[sel]*180.0/PI));
    else if(jack==ID_TBM_TAIL_JACK)
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.bj[sel]*180.0/PI));
    else if(jack==ID_TBM_HEAD_JACK)
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.fj[sel]*180.0/PI));
    jackFig->Refresh();
}

void tbmDlg::OnPaintPage(wxPaintEvent& event)
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
        button[ID_TBM_PAGE_GEN].x=x1;
        button[ID_TBM_PAGE_GEN].y=y1;
        button[ID_TBM_PAGE_GEN].width=w1;
        button[ID_TBM_PAGE_GEN].height=h1;

        if(page==ID_TBM_PAGE_GEN || motion==ID_TBM_PAGE_GEN)
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

            if(page!=ID_TBM_PAGE_GEN)
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
        button[ID_TBM_PAGE_JACK].x=x1;
        button[ID_TBM_PAGE_JACK].y=y1;
        button[ID_TBM_PAGE_JACK].width=w1;
        button[ID_TBM_PAGE_JACK].height=h1;
        if(page==ID_TBM_PAGE_JACK || motion==ID_TBM_PAGE_JACK)
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
            if(page!=ID_TBM_PAGE_JACK)
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

void tbmDlg::OnMotionPage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_TBM_PAGE_GEN].y && y<button[ID_TBM_PAGE_GEN].y+button[ID_TBM_PAGE_GEN].height)
    {
        if(x>button[ID_TBM_PAGE_GEN].x && x<button[ID_TBM_PAGE_GEN].x+button[ID_TBM_PAGE_GEN].width)
        {
            motion=ID_TBM_PAGE_GEN;
        }
        else if(x>button[ID_TBM_PAGE_JACK].x && x<button[ID_TBM_PAGE_JACK].x+button[ID_TBM_PAGE_JACK].width)
        {
            motion=ID_TBM_PAGE_JACK;
        }
        else
        {
            motion=ID_TBM_NONE;
        }
    }
    else
    {
        motion=ID_TBM_NONE;
    }
    panelPage->Refresh();
}

void tbmDlg::OnLeavePage(wxMouseEvent& event)
{
    motion=ID_TBM_NONE;
    panelPage->Refresh();
}

void tbmDlg::OnClickPage(wxMouseEvent& event)
{
    if(motion==ID_TBM_PAGE_GEN)
    {
        page=ID_TBM_PAGE_GEN;
        panelTbmgen->Show(true);
        panelTbmJack->Show(false);
    }
    else if(motion==ID_TBM_PAGE_JACK)
    {
        page=ID_TBM_PAGE_JACK;
        panelTbmgen->Show(false);
        panelTbmJack->Show(true);
    }
    panelPage->Refresh();
}

void tbmDlg::OnPaintKink(wxPaintEvent& event)
{
    wxPaintDC dc(kinkPanel);
    int w,h;
    kinkPanel->GetClientSize(&w,&h);
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
        button[ID_TBM_KINK1].x=x1;
        button[ID_TBM_KINK1].y=y1;
        button[ID_TBM_KINK1].width=w1;
        button[ID_TBM_KINK1].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(tbm.type==1 || tbm.type==3)
        {
            if(motion==ID_TBM_KINK1)
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
            if(motion==ID_TBM_KINK1)
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
        button[ID_TBM_KINK2].x=x1;
        button[ID_TBM_KINK2].y=y1;
        button[ID_TBM_KINK2].width=w1;
        button[ID_TBM_KINK2].height=h1;
        if(tbm.type==2 || tbm.type==3)
        {
            if(motion==ID_TBM_KINK2)
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
            if(motion==ID_TBM_KINK2)
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

void tbmDlg::OnMotionKink(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>button[ID_TBM_KINK1].x && x<button[ID_TBM_KINK1].x+button[ID_TBM_KINK1].width)
    {
        if(y>button[ID_TBM_KINK1].y && y<button[ID_TBM_KINK1].y+button[ID_TBM_KINK1].height)
        {
            motion=ID_TBM_KINK1;
        }
        else
        {
            motion=ID_TBM_NONE;
        }
    }
    else if(x>button[ID_TBM_KINK2].x && x<button[ID_TBM_KINK2].x+button[ID_TBM_KINK2].width)
    {
        if(y>button[ID_TBM_KINK2].y && y<button[ID_TBM_KINK2].y+button[ID_TBM_KINK2].height)
        {
            motion=ID_TBM_KINK2;
        }
        else
        {
            motion=ID_TBM_NONE;
        }
    }
    else
    {
        motion=ID_TBM_NONE;
    }
    kinkPanel->Refresh();
}

void tbmDlg::OnLeaveKink(wxMouseEvent& event)
{
    motion=ID_TBM_NONE;
    kinkPanel->Refresh();
}

void tbmDlg::OnClickKink(wxMouseEvent& event)
{
    if(motion==ID_TBM_KINK1)
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
    }
    else if(motion==ID_TBM_KINK2)
    {
        if(tbm.type==0)
        {
            tbm.type=2;
        }
        else if(tbm.type==1)
        {
            tbm.type=3;
        }
        else if(tbm.type==2)
        {
            tbm.type=0;
        }
        else if(tbm.type==3)
        {
            tbm.type=1;
        }
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

    kinkPanel->Refresh();
    tbmFigPanel->Refresh();
    tbmTxtPanel->Refresh();
}

void tbmDlg::OnPaintTbmajFig(wxPaintEvent& event)
{
    wxPaintDC dc(jackFig);
    int w,h;
    jackFig->GetClientSize(&w,&h);
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
        if(jack==ID_TBM_MAIN_JACK) nj=tbm.naj;
        else if(jack==ID_TBM_TAIL_JACK) nj=tbm.nbj;
        else if(jack==ID_TBM_HEAD_JACK) nj=tbm.nfj;

        for(int i=0;i<nj;i++)
        {
            if(jack==ID_TBM_MAIN_JACK) beta=tbm.aj[i];
            else if(jack==ID_TBM_TAIL_JACK) beta=tbm.bj[i];
            else if(jack==ID_TBM_HEAD_JACK) beta=tbm.fj[i];
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

void tbmDlg::OnPaintTypeJack(wxPaintEvent& event)
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
        button[ID_TBM_MAIN_JACK].x=x1;
        button[ID_TBM_MAIN_JACK].y=y1;
        button[ID_TBM_MAIN_JACK].width=w1;
        button[ID_TBM_MAIN_JACK].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(jack==ID_TBM_MAIN_JACK)
        {
            if(motion==ID_TBM_MAIN_JACK)
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
            if(motion==ID_TBM_MAIN_JACK)
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
        button[ID_TBM_TAIL_JACK].x=x1;
        button[ID_TBM_TAIL_JACK].y=y1;
        button[ID_TBM_TAIL_JACK].width=w1;
        button[ID_TBM_TAIL_JACK].height=h1;

        if(jack==ID_TBM_TAIL_JACK)
        {
            if(motion==ID_TBM_TAIL_JACK)
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
            if(motion==ID_TBM_TAIL_JACK)
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
        button[ID_TBM_HEAD_JACK].x=x1;
        button[ID_TBM_HEAD_JACK].y=y1;
        button[ID_TBM_HEAD_JACK].width=w1;
        button[ID_TBM_HEAD_JACK].height=h1;

        if(jack==ID_TBM_HEAD_JACK)
        {
            if(motion==ID_TBM_HEAD_JACK)
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
            if(motion==ID_TBM_HEAD_JACK)
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

void tbmDlg::OnMotionTypeJack(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_TBM_MAIN_JACK].y && y<button[ID_TBM_MAIN_JACK].y+button[ID_TBM_MAIN_JACK].height)
    {
        if(x>button[ID_TBM_MAIN_JACK].x && x<button[ID_TBM_MAIN_JACK].x+button[ID_TBM_MAIN_JACK].width)
        {
            motion=ID_TBM_MAIN_JACK;
        }
        else if(x>button[ID_TBM_TAIL_JACK].x && x<button[ID_TBM_TAIL_JACK].x+button[ID_TBM_TAIL_JACK].width)
        {
            motion=ID_TBM_TAIL_JACK;
        }
        else if(x>button[ID_TBM_HEAD_JACK].x && x<button[ID_TBM_HEAD_JACK].x+button[ID_TBM_HEAD_JACK].width)
        {
            motion=ID_TBM_HEAD_JACK;
        }
        else
        {
            motion=ID_TBM_NONE;
        }
    }
    else
    {
        motion=ID_TBM_NONE;
    }
    panelTypJack->Refresh();
}

void tbmDlg::OnLeaveTypeJack(wxMouseEvent& event)
{
    motion=ID_TBM_NONE;
    panelTypJack->Refresh();
}

void tbmDlg::OnClickTypeJack(wxMouseEvent& event)
{
    if(motion==ID_TBM_MAIN_JACK)
    {
        jack=ID_TBM_MAIN_JACK;
        tbmStaticText6->SetLabel(_("推进油缸组"));
        UpdateJack();
        jackList->Select(0);
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.aj[0]*180.0/PI));
        jackFig->Refresh();
        panelNumJack->Refresh();
    }
    else if(motion==ID_TBM_TAIL_JACK)
    {
        jack=ID_TBM_TAIL_JACK;
        tbmStaticText6->SetLabel(_("铰接油缸组"));
        UpdateJack();
        jackList->Select(0);
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.bj[0]*180.0/PI));
        jackFig->Refresh();
        panelNumJack->Refresh();
    }
    else if(motion==ID_TBM_HEAD_JACK)
    {
        jack=ID_TBM_HEAD_JACK;
        tbmStaticText6->SetLabel(_("铰接油缸组"));
        UpdateJack();
        jackList->Select(0);
        jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.fj[0]*180.0/PI));
        jackFig->Refresh();
        panelNumJack->Refresh();
    }

    panelTypJack->Refresh();
}

void tbmDlg::OnPaintNumTbmaj(wxPaintEvent& event)
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
        button[ID_TBM_SUB_JACK].x=x1;
        button[ID_TBM_SUB_JACK].y=y1;
        button[ID_TBM_SUB_JACK].width=w1;
        button[ID_TBM_SUB_JACK].height=h1;
        if(jack==ID_TBM_MAIN_JACK)
        {
            if(motion==ID_TBM_SUB_JACK)
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
        button[ID_TBM_ADD_JACK].x=x1;
        button[ID_TBM_ADD_JACK].y=y1;
        button[ID_TBM_ADD_JACK].width=w1;
        button[ID_TBM_ADD_JACK].height=h1;
        if(jack==ID_TBM_MAIN_JACK)
        {
            if(motion==ID_TBM_ADD_JACK)
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
        if(jack==ID_TBM_MAIN_JACK)
            memDC.DrawLabel(wxString::Format(_("%d"),tbm.naj),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        else if(jack==ID_TBM_TAIL_JACK)
            memDC.DrawLabel(wxString::Format(_("%d"),tbm.nbj),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        else if(jack==ID_TBM_HEAD_JACK)
            memDC.DrawLabel(wxString::Format(_("%d"),tbm.nfj),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLabel(wxString::Format(_("%d"),ndty),wxRect(w1,y1,w-w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void tbmDlg::OnMotionNumTbmaj(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>button[ID_TBM_SUB_JACK].x && x<button[ID_TBM_SUB_JACK].x+button[ID_TBM_SUB_JACK].width)
    {
        if(y>button[ID_TBM_SUB_JACK].y && y<button[ID_TBM_SUB_JACK].y+button[ID_TBM_SUB_JACK].height)
        {
            motion=ID_TBM_SUB_JACK;
        }
        else
        {
            motion=ID_TBM_NONE;
        }
    }
    else if(x>button[ID_TBM_ADD_JACK].x && x<button[ID_TBM_ADD_JACK].x+button[ID_TBM_ADD_JACK].width)
    {
        if(y>button[ID_TBM_ADD_JACK].y && y<button[ID_TBM_ADD_JACK].y+button[ID_TBM_ADD_JACK].height)
        {
            motion=ID_TBM_ADD_JACK;
        }
        else
        {
            motion=ID_TBM_NONE;
        }
    }
    else
    {
        motion=ID_TBM_NONE;
    }
    panelNumJack->Refresh();
}

void tbmDlg::OnLeaveNumTbmaj(wxMouseEvent& event)
{
    motion=ID_TBM_NONE;
    panelNumJack->Refresh();
}

void tbmDlg::OnClickNumTbmaj(wxMouseEvent& event)
{
    if(motion==ID_TBM_ADD_JACK)
    {
        if(jack==ID_TBM_MAIN_JACK)
        {
            if(tbm.naj>=6) return;
            tbm.naj++;
            UpdateJack();
            jackList->Select(tbm.naj-1);
            jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.aj[tbm.naj-1]*180.0/PI));
            jackFig->Refresh();
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
    else if(motion==ID_TBM_SUB_JACK)
    {
        if(jack==ID_TBM_MAIN_JACK)
        {
            if(tbm.naj<=4) return;
            tbm.naj--;
            UpdateJack();
            jackList->Select(tbm.naj-1);
            jackTxt->SetValue(wxString::Format(_("%.2f"),tbm.aj[tbm.naj-1]*180.0/PI));
            jackFig->Refresh();
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

void tbmDlg::OnPaintAngTbmaj(wxPaintEvent& event)
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
        button[ID_TBM_SET_JACK].x=x1;
        button[ID_TBM_SET_JACK].y=y1;
        button[ID_TBM_SET_JACK].width=w1;
        button[ID_TBM_SET_JACK].height=h1;
        memDC.SetFont(chs2);
        if(motion==ID_TBM_SET_JACK)
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

void tbmDlg::OnMotionAngTbmaj(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>button[ID_TBM_SET_JACK].x && x<button[ID_TBM_SET_JACK].x+button[ID_TBM_SET_JACK].width)
    {
        if(y>button[ID_TBM_SET_JACK].y && y<button[ID_TBM_SET_JACK].y+button[ID_TBM_SET_JACK].height)
        {
            motion=ID_TBM_SET_JACK;
        }
        else
        {
            motion=ID_TBM_NONE;
        }
    }
    else
    {
        motion=ID_TBM_NONE;
    }
    panelAngJack->Refresh();
}

void tbmDlg::OnLeaveAngTbmaj(wxMouseEvent& event)
{
    motion=ID_TBM_NONE;
    panelAngJack->Refresh();
}

void tbmDlg::OnClickAngTbmaj(wxMouseEvent& event)
{
    if(motion==ID_TBM_SET_JACK)
    {
        int sel=jackList->GetFirstSelected();
        if(sel<0 || sel>=10) return;
        if(jack==ID_TBM_MAIN_JACK)
        {
            jackTxt->GetValue().ToDouble(&tbm.aj[sel]);
            tbm.aj[sel]=tbm.aj[sel]*PI/180.0;
            UpdateJack();
            jackList->Select(sel);
            jackFig->Refresh();
        }
        else if(jack==ID_TBM_TAIL_JACK)
        {
            jackTxt->GetValue().ToDouble(&tbm.bj[sel]);
            tbm.bj[sel]=tbm.bj[sel]*PI/180.0;
            UpdateJack();
            jackList->Select(sel);
            jackFig->Refresh();
        }
        else if(jack==ID_TBM_HEAD_JACK)
        {
            jackTxt->GetValue().ToDouble(&tbm.fj[sel]);
            tbm.fj[sel]=tbm.fj[sel]*PI/180.0;
            UpdateJack();
            jackList->Select(sel);
            jackFig->Refresh();
        }
    }

    panelAngJack->Refresh();
}

void tbmDlg::OnPaintTbmFig(wxPaintEvent& event)
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

void tbmDlg::OnPaintTbmTxt(wxPaintEvent& event)
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
            tbmL2->Enable(true);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            tbmL2->Enable(false);
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
            tbmL3->Enable(false);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            tbmL3->Enable(true);
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmL3->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);

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
            tbmL5->Enable(true);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            tbmL5->Enable(false);
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
            tbmL6->Enable(true);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            tbmL6->Enable(false);
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
            tbmL7->Enable(true);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            tbmL7->Enable(false);
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
            tbmL8->Enable(true);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            tbmL8->Enable(false);
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
            tbmD2->Enable(true);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            tbmD2->Enable(false);
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
            tbmD3->Enable(true);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            tbmD3->Enable(false);
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
            tbmD4->Enable(true);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            tbmD4->Enable(false);
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
            tbmD5->Enable(true);
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            tbmD5->Enable(false);
        }
        memDC.DrawRectangle(x1+w1+30,y1,w1+30,h1);
        memDC.SetFont(ens);
        memDC.DrawLabel(_("mm"),wxRect(x1+w1+w1+30,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        tbmD5->SetSize(x1+w1+30+2,y1+3,w1-4,h1-4);
        //tbmL1->Show(false);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void tbmDlg::OnPaintBottom(wxPaintEvent& event)
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
        int w2,h2;
        memDC.SetPen(wxPen(wxColor(117,117,117)));


        w1=65;
        h1=26;
        x1=w/2+4;
        y1=9;
        button[ID_TBM_CANCEL].x=x1;
        button[ID_TBM_CANCEL].y=y1;
        button[ID_TBM_CANCEL].width=w1;
        button[ID_TBM_CANCEL].height=h1;
        if(motion==ID_TBM_CANCEL)
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
        memDC.DrawLabel(_("取消"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1-w1-8;
        button[ID_TBM_OK].x=x1;
        button[ID_TBM_OK].y=y1;
        button[ID_TBM_OK].width=w1;
        button[ID_TBM_OK].height=h1;
        if(motion==ID_TBM_OK)
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
        memDC.DrawLabel(_("确定"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void tbmDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_TBM_CANCEL].y && y<button[ID_TBM_CANCEL].y+button[ID_TBM_CANCEL].height)
    {
        if(x>button[ID_TBM_CANCEL].x && x<button[ID_TBM_CANCEL].x+button[ID_TBM_CANCEL].width)
        {
            motion=ID_TBM_CANCEL;
        }
        else if(x>button[ID_TBM_OK].x && x<button[ID_TBM_OK].x+button[ID_TBM_OK].width)
        {
            motion=ID_TBM_OK;
        }
        else
        {
            motion=ID_TBM_NONE;
        }
    }
    else
    {
        motion=ID_TBM_NONE;
    }
    panelBottom->Refresh();
}

void tbmDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_TBM_NONE;
    panelBottom->Refresh();
}

void tbmDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_TBM_CANCEL)
    {
        Destroy();
    }
    else if(motion==ID_TBM_OK)
    {
        msr->tbm=tbm;
        wxStandardPaths wsp;
        wxString str=wsp.GetDataDir()+wxString(_("\\plugins\\"))+wxString(_("geometry.tbm"));
        FILE* fp;
        char path[260];
        strcpy(path,str.mb_str(wxConvLocal));
        fp=fopen(path,"w");
        if(fp)
        {
            fprintf(fp,"'%s',%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d,%f,%f,%f,%f,%f,%f%d,\
                %d,%f,%f,%f,%f,%d,%d,%f,%f,%f,%f,%d\n",
                tbm.name,tbm.type,tbm.mode,
                tbm.D[0],tbm.D[1],tbm.D[2],tbm.D[3],tbm.D[4],tbm.D[5],tbm.L[0],tbm.L[1],tbm.L[2],tbm.L[3],tbm.L[4],tbm.L[5],
                tbm.L[6],tbm.L[7],tbm.L[8],tbm.naj,tbm.aj[0],tbm.aj[1],tbm.aj[2],tbm.aj[3],tbm.aj[4],tbm.aj[5],tbm.aunit,
                tbm.nbj,tbm.bj[0],tbm.bj[1],tbm.bj[2],tbm.bj[3],tbm.bunit,
                tbm.nfj,tbm.fj[0],tbm.fj[1],tbm.fj[2],tbm.fj[3],tbm.funit
                );
            fclose(fp);
        }
        Destroy();
    }
    //panelBottom->Refresh();
}

void tbmDlg::OnPaintMain(wxPaintEvent& event)
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
