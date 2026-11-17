///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "TpsDlg.h"
#include "mtg_t_svrApp.h"
//#include "confirmdlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(TpsDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(TpsDlg)
#include <wx/font.h>
#include <stdio.h>
#include "wx/filefn.h"
#include <wx/dir.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(TpsDlg)

//*)
TpsDlg::TpsDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //listPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(0,0),wxSize(w,h), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //listPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //listPanel->Show(false);
    tpsList = new wxListView(panelMain, wxID_ANY, wxPoint(0,24), wxSize(w,h-90), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TpsDlg::OnPaintMain,0,this);
    panelMain->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TpsDlg::OnMotionMain,0,this);
    panelMain->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TpsDlg::OnLeaveMain,0,this);
    panelMain->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TpsDlg::OnClickMain,0,this);

    tpsList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&TpsDlg::OnListTpsActivated,0,this);

    //listPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TpsDlg::OnPaintList,0,this);
    //listPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TpsDlg::OnMotionList,0,this);
    //listPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TpsDlg::OnLeaveList,0,this);
    //listPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TpsDlg::OnClickList,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));
    int i=0;
    tpsList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,0);
    tpsList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    tpsList->InsertColumn(i++,_("名称"),wxLIST_FORMAT_LEFT,200);

    ListItem[0]=_("Leica TPS1000");
    ListItem[1]=_("Leica TPS1100");
    ListItem[2]=_("Leica TPS1200");
    ListItem[3]=_("Leica TPS15");
    ListItem[4]=_("Leica TPS16");
    ListItem[5]=_("Trimble S5");
    ListItem[6]=_("Trimble TCU");

    for(i=0;i<7;i++)
    {
        tpsList->InsertItem(i,_(""));
        tpsList->SetItem(i,1,wxString::Format(_("%d"),i+1));
        tpsList->SetItem(i,2,ListItem[i]);
    }

    //tpsList->Select(type);
    motion=ID_TPS_LIST_NONE;
}

TpsDlg::~TpsDlg()
{

}

void TpsDlg::SetTPS(int tps)
{
    tpsList->Select(tps);
}

int TpsDlg::GetTPS()
{
    return tpsList->GetFirstSelected();
}

void TpsDlg::OnListTpsActivated(wxListEvent& event)
{
    EndModal(wxID_OK);
}

void TpsDlg::OnPaintMain(wxPaintEvent& event)
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
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.SetPen(wxPen(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(68,68,68));

        int x,y;
        x=0;
        y=12;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x,y,w,y);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x,y+1,w,y+1);

        y=h-54;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x,y,w,y);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x,y+1,w,y+1);

        int x1,y1,w1,h1;
        x1=w/2-90;
        y1=y+12;
        h1=32;
        w1=180;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,2);
        tpsButton[ID_TPS_LIST_OK].x=x1+1;
        tpsButton[ID_TPS_LIST_OK].y=y1+1;
        tpsButton[ID_TPS_LIST_OK].width=w1/2-1;
        tpsButton[ID_TPS_LIST_OK].height=h1-2;

        tpsButton[ID_TPS_LIST_CANCEL].x=tpsButton[ID_TPS_LIST_OK].x+tpsButton[ID_TPS_LIST_OK].width;
        tpsButton[ID_TPS_LIST_CANCEL].y=tpsButton[ID_TPS_LIST_OK].y;
        tpsButton[ID_TPS_LIST_CANCEL].width=tpsButton[ID_TPS_LIST_OK].width;
        tpsButton[ID_TPS_LIST_CANCEL].height=tpsButton[ID_TPS_LIST_OK].height;
        if(motion==ID_TPS_LIST_OK)
        {
            memDC.SetPen(wxPen(ibrush[1].GetColour()));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(ibrush[0].GetColour()));
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRectangle(tpsButton[ID_TPS_LIST_OK]);
        memDC.DrawLabel(_("确 定"),tpsButton[ID_TPS_LIST_OK],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_TPS_LIST_CANCEL)
        {
            memDC.SetPen(wxPen(ibrush[1].GetColour()));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(ibrush[0].GetColour()));
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRectangle(tpsButton[ID_TPS_LIST_CANCEL]);
        memDC.DrawLabel(_("取 消"),tpsButton[ID_TPS_LIST_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TpsDlg::OnMotionMain(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>tpsButton[ID_TPS_LIST_OK].y && y<tpsButton[ID_TPS_LIST_OK].y+tpsButton[ID_TPS_LIST_OK].height)
    {
        if(x>tpsButton[ID_TPS_LIST_OK].x && x<tpsButton[ID_TPS_LIST_OK].x+tpsButton[ID_TPS_LIST_OK].width)
        {
            motion=ID_TPS_LIST_OK;
        }
        else if(x>tpsButton[ID_TPS_LIST_CANCEL].x && x<tpsButton[ID_TPS_LIST_CANCEL].x+tpsButton[ID_TPS_LIST_CANCEL].width)
        {
            motion=ID_TPS_LIST_CANCEL;
        }
        else
        {
            motion=ID_TPS_LIST_NONE;
        }
    }
    else
    {
        motion=ID_TPS_LIST_NONE;
    }
    int w,h;
    panelMain->GetSize(&w,&h);
    panelMain->RefreshRect(wxRect(0,h-60,w,60));
}

void TpsDlg::OnLeaveMain(wxMouseEvent& event)
{
    motion=ID_TPS_LIST_NONE;
    int w,h;
    panelMain->GetSize(&w,&h);
    panelMain->RefreshRect(wxRect(0,h-60,w,60));
}

void TpsDlg::OnClickMain(wxMouseEvent& event)
{
    //type = tpsList->GetFirstSelected();
    if(motion==ID_TPS_LIST_OK)
    {
        EndModal(wxID_OK);
    }
    else if(motion==ID_TPS_LIST_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }

}
