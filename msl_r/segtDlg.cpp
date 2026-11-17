///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "segtDlg.h"
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
	//(*InternalHeadersPCH(segtDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(segtDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(segtDlg)

//*)

segtDlg::segtDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
    panelSeg = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w,h-57), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSeg->SetBackgroundColour(wxColor(239,239,239));

    x1=14;
    y1=16;
    w1=w-x1*2;
    h1=h-y1-75;
    panelFig = new wxPanel(panelSeg, wxID_ANY, wxPoint(x1,y1), wxSize(w1/2,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTxt = new wxPanel(panelSeg, wxID_ANY, wxPoint(x1+w1/2+14,y1), wxSize(w1/2-14,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTxt->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    segL = new wxTextCtrl(panelTxt, wxID_ANY, wxEmptyString, wxPoint(x1+60,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segD1 = new wxTextCtrl(panelTxt, wxID_ANY, wxEmptyString, wxPoint(x1+265,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segD2 = new wxTextCtrl(panelTxt, wxID_ANY, wxEmptyString, wxPoint(x1+470,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segKs = new wxTextCtrl(panelTxt, wxID_ANY, wxEmptyString, wxPoint(x1+60,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segG0 = new wxTextCtrl(panelTxt, wxID_ANY,wxEmptyString, wxPoint(x1+265,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segG1 = new wxTextCtrl(panelTxt, wxID_ANY, wxEmptyString, wxPoint(x1+470,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    y1+=25;
    segL2s = new wxTextCtrl(panelTxt, wxID_ANY, _(" mm"), wxPoint(x1+277,y1-3), wxSize(120,-1), wxBORDER_NONE | wxTE_RIGHT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&segtDlg::OnPaintMain,0,this);

    panelFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&segtDlg::OnPaintFig,0,this);
    panelTxt->Connect(wxEVT_PAINT,(wxObjectEventFunction)&segtDlg::OnPaintTxt,0,this);
    panelTxt->Connect(wxEVT_MOTION,(wxObjectEventFunction)&segtDlg::OnMotionTxt,0,this);
    panelTxt->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&segtDlg::OnLeaveTxt,0,this);
    panelTxt->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&segtDlg::OnClickTxt,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&segtDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&segtDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&segtDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&segtDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    motion=ID_SEG_NONE;

    checkBoxWidth=14;
    checkBoxHeight=14;
    radioBoxR1=7;
    radioBoxR2=4;

    ///数据
    segt=msr->segt;
    segL->SetValue(wxString::Format(_("%.1f"),segt.L*1000.0));
    segD1->SetValue(wxString::Format(_("%.1f"),segt.D*1000.0));
    segD2->SetValue(wxString::Format(_("%.1f"),segt.De*1000.0));
    segKs->SetValue(wxString::Format(_("%.1f"),360.0/segt.Ks));
    segG0->SetValue(wxString::Format(_("%.1f"),segt.G0*1000.0));
    segG1->SetValue(wxString::Format(_("%.1f"),segt.G1*1000.0));
    segL2s->SetValue(wxString::Format(_("%.1f"),segt.l2s*1000.0));
}

segtDlg::~segtDlg()
{

}

void segtDlg::OnPaintFig(wxPaintEvent& event)
{
    wxPaintDC dc(panelFig);
    int w,h;
    panelFig->GetClientSize(&w,&h);
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
        int ks=segt.Ks;
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
        if(segt.in==1)
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
        else if(segt.f2b==0)
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

void segtDlg::OnPaintTxt(wxPaintEvent& event)
{
    wxPaintDC dc(panelTxt);
    int w,h;
    panelTxt->GetClientSize(&w,&h);
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
        button[ID_SEG_S2S_TYPE1].x=x1;
        button[ID_SEG_S2S_TYPE1].y=y1;
        button[ID_SEG_S2S_TYPE1].width=w1;
        button[ID_SEG_S2S_TYPE1].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(segt.in==0)
        {
            if(motion==ID_SEG_S2S_TYPE1)
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
            if(motion==ID_SEG_S2S_TYPE1)
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
        button[ID_SEG_S2S_TYPE2].x=x1;
        button[ID_SEG_S2S_TYPE2].y=y1;
        button[ID_SEG_S2S_TYPE2].width=w1;
        button[ID_SEG_S2S_TYPE2].height=h1;
        if(segt.in==1)
        {
            if(motion==ID_SEG_S2S_TYPE2)
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
            if(motion==ID_SEG_S2S_TYPE2)
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
        button[ID_SEG_TYPE1].x=x1;
        button[ID_SEG_TYPE1].y=y1;
        button[ID_SEG_TYPE1].width=w1;
        button[ID_SEG_TYPE1].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(segt.in==1)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            memDC.SetTextForeground(wxColor(158,158,158));
            memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            memDC.DrawLabel(_("标准环+转弯环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(segt.type==1)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion==ID_SEG_TYPE1)
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
            if(motion==ID_SEG_TYPE1)
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
        button[ID_SEG_TYPE2].x=x1;
        button[ID_SEG_TYPE2].y=y1;
        button[ID_SEG_TYPE2].width=w1;
        button[ID_SEG_TYPE2].height=h1;
        if(segt.in==1)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.SetBrush(wxBrush(wxColor(239,239,239)));
            memDC.SetTextForeground(wxColor(158,158,158));
            memDC.DrawCircle(x1+radioBoxR1,y1+h1/2,radioBoxR1);
            memDC.DrawLabel(_("通用管环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(segt.type==0)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion==ID_SEG_TYPE2)
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
            if(motion==ID_SEG_TYPE2)
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
        button[ID_SEG_TYPE3].x=x1;
        button[ID_SEG_TYPE3].y=y1;
        button[ID_SEG_TYPE3].width=w1;
        button[ID_SEG_TYPE3].height=h1;
        if(segt.in==1)
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
        button[ID_SEG_F2B_TTPE1].x=x1;
        button[ID_SEG_F2B_TTPE1].y=y1;
        button[ID_SEG_F2B_TTPE1].width=w1;
        button[ID_SEG_F2B_TTPE1].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(segt.in==1)
        {
            if(segt.f2b==0)
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
        else if(segt.f2b==0)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion==ID_SEG_F2B_TTPE1)
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
            if(motion==ID_SEG_F2B_TTPE1)
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
        button[ID_SEG_F2B_TTPE2].x=x1;
        button[ID_SEG_F2B_TTPE2].y=y1;
        button[ID_SEG_F2B_TTPE2].width=w1;
        button[ID_SEG_F2B_TTPE2].height=h1;
        if(segt.in==1)
        {
            if(segt.f2b==1)
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
        else if(segt.f2b==1)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion==ID_SEG_F2B_TTPE2)
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
            if(motion==ID_SEG_F2B_TTPE2)
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
        button[ID_SEG_S2S_12].x=x1;
        button[ID_SEG_S2S_12].y=y1;
        button[ID_SEG_S2S_12].width=w1;
        button[ID_SEG_S2S_12].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(segt.in==1)
        {
            if(segt.s2s==2)
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
        else if(segt.s2s==2)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion==ID_SEG_S2S_12)
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
            if(motion==ID_SEG_S2S_12)
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
        button[ID_SEG_S2S_13].x=x1;
        button[ID_SEG_S2S_13].y=y1;
        button[ID_SEG_S2S_13].width=w1;
        button[ID_SEG_S2S_13].height=h1;
        if(segt.in==1)
        {
            if(segt.s2s==3)
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
        else if(segt.s2s==3)
        {
            memDC.SetTextForeground(icolor[0]);
            if(motion==ID_SEG_S2S_13)
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
            if(motion==ID_SEG_S2S_13)
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
        if(segt.in==0)
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

void segtDlg::OnMotionTxt(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_SEG_S2S_TYPE1].y && y<button[ID_SEG_S2S_TYPE1].y+button[ID_SEG_S2S_TYPE1].height)
    {
        if(x>button[ID_SEG_S2S_TYPE1].x && x<button[ID_SEG_S2S_TYPE1].x+button[ID_SEG_S2S_TYPE1].width)
        {
            motion=ID_SEG_S2S_TYPE1;
        }
        else if(x>button[ID_SEG_S2S_TYPE2].x && x<button[ID_SEG_S2S_TYPE2].x+button[ID_SEG_S2S_TYPE2].width)
        {
            motion=ID_SEG_S2S_TYPE2;
        }
        else
        {
            motion=ID_SEG_NONE;
        }
    }
    else if(y>button[ID_SEG_TYPE1].y && y<button[ID_SEG_TYPE1].y+button[ID_SEG_TYPE1].height)
    {
        if(x>button[ID_SEG_TYPE1].x && x<button[ID_SEG_TYPE1].x+button[ID_SEG_TYPE1].width)
        {
            motion=ID_SEG_TYPE1;
        }
        else if(x>button[ID_SEG_TYPE2].x && x<button[ID_SEG_TYPE2].x+button[ID_SEG_TYPE2].width)
        {
            motion=ID_SEG_TYPE2;
        }
        else if(x>button[ID_SEG_TYPE3].x && x<button[ID_SEG_TYPE3].x+button[ID_SEG_TYPE3].width)
        {
            motion=ID_SEG_TYPE3;
        }
        else
        {
            motion=ID_SEG_NONE;
        }
    }
    else if(y>button[ID_SEG_F2B_TTPE1].y && y<button[ID_SEG_F2B_TTPE1].y+button[ID_SEG_F2B_TTPE1].height)
    {
        if(x>button[ID_SEG_F2B_TTPE1].x && x<button[ID_SEG_F2B_TTPE1].x+button[ID_SEG_F2B_TTPE1].width)
        {
            motion=ID_SEG_F2B_TTPE1;
        }
        else if(x>button[ID_SEG_F2B_TTPE2].x && x<button[ID_SEG_F2B_TTPE2].x+button[ID_SEG_F2B_TTPE2].width)
        {
            motion=ID_SEG_F2B_TTPE2;
        }
        else
        {
            motion=ID_SEG_NONE;
        }
    }
    else if(y>button[ID_SEG_S2S_12].y && y<button[ID_SEG_S2S_12].y+button[ID_SEG_S2S_12].height)
    {
        if(x>button[ID_SEG_S2S_12].x && x<button[ID_SEG_S2S_12].x+button[ID_SEG_S2S_12].width)
        {
            motion=ID_SEG_S2S_12;
        }
        else if(x>button[ID_SEG_S2S_13].x && x<button[ID_SEG_S2S_13].x+button[ID_SEG_S2S_13].width)
        {
            motion=ID_SEG_S2S_13;
        }
        else
        {
            motion=ID_SEG_NONE;
        }
    }
    else
    {
        motion=ID_SEG_NONE;
    }
    panelSeg->Refresh();
    panelFig->Refresh();
}

void segtDlg::OnLeaveTxt(wxMouseEvent& event)
{
    motion=ID_SEG_NONE;
    panelSeg->Refresh();
    panelFig->Refresh();
}

void segtDlg::OnClickTxt(wxMouseEvent& event)
{
    if(motion==ID_SEG_S2S_TYPE1)
    {
        if(segt.in==1) segt.in=0;
    }
    else if(motion==ID_SEG_S2S_TYPE2)
    {
        if(segt.in==0) segt.in=1;
    }
    else if(motion==ID_SEG_TYPE1)
    {
        if(segt.in==1) return;
        if(segt.type!=1) segt.type=1;
    }
    else if(motion==ID_SEG_TYPE2)
    {
        if(segt.in==1) return;
        if(segt.type!=0) segt.type=0;
    }
    else if(motion==ID_SEG_F2B_TTPE1)
    {
        if(segt.in==1) return;
        if(segt.f2b==1) segt.f2b=0;
    }
    else if(motion==ID_SEG_F2B_TTPE2)
    {
        if(segt.in==1) return;
        if(segt.f2b==0) segt.f2b=1;
    }
    else if(motion==ID_SEG_S2S_12)
    {
        if(segt.in==1) return;
        segt.s2s=2;
    }
    else if(motion==ID_SEG_S2S_13)
    {
        if(segt.in==1) return;
        segt.s2s=3;
    }
    panelSeg->Refresh();
    panelFig->Refresh();
}

void segtDlg::OnPaintBottom(wxPaintEvent& event)
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
        button[ID_SEG_CANCEL].x=x1;
        button[ID_SEG_CANCEL].y=y1;
        button[ID_SEG_CANCEL].width=w1;
        button[ID_SEG_CANCEL].height=h1;
        if(motion==ID_SEG_CANCEL)
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
        button[ID_SEG_OK].x=x1;
        button[ID_SEG_OK].y=y1;
        button[ID_SEG_OK].width=w1;
        button[ID_SEG_OK].height=h1;
        if(motion==ID_SEG_OK)
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

void segtDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_SEG_CANCEL].y && y<button[ID_SEG_CANCEL].y+button[ID_SEG_CANCEL].height)
    {
        if(x>button[ID_SEG_CANCEL].x && x<button[ID_SEG_CANCEL].x+button[ID_SEG_CANCEL].width)
        {
            motion=ID_SEG_CANCEL;
        }
        else if(x>button[ID_SEG_OK].x && x<button[ID_SEG_OK].x+button[ID_SEG_OK].width)
        {
            motion=ID_SEG_OK;
        }
        else
        {
            motion=ID_SEG_NONE;
        }
    }
    else
    {
        motion=ID_SEG_NONE;
    }
    panelBottom->Refresh();
}

void segtDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_SEG_NONE;
    panelBottom->Refresh();
}

void segtDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_SEG_CANCEL)
    {
        Destroy();
    }
    else if(motion==ID_SEG_OK)
    {
        msr->segt=segt;
        wxStandardPaths wsp;
        wxString str=wsp.GetDataDir()+wxString(_("\\plugins\\"))+wxString(_("segment.segt"));
        FILE* fp;
        char path[260];
        strcpy(path,str.mb_str(wxConvLocal));
        fp=fopen(path,"w");
        if(fp)
        {
            fprintf(fp,"%d,%d,%d,%f,%f,%f,%f,%d,%f,%f,%d\n",
                segt.type,segt.in,segt.f2b,segt.l2s,segt.L,segt.De,segt.D,segt.Ks,segt.G0,segt.G1,segt.s2s);
            fclose(fp);
            double len=fabs(msr->prj.mile2-msr->prj.mile1);
            int n=len/msr->segt.L+1;
            if(n!=msr->ndes)
            {
                msr_init_des(msr);
            }
        }
        Destroy();
    }
    //panelBottom->Refresh();
}

void segtDlg::OnPaintMain(wxPaintEvent& event)
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
