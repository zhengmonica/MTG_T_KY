///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "TpsDlg.h"
#include "mtg_t_cliApp.h"
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


const long TpsDlg::ID_PANEL1 = wxNewId();                  //标题
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
	panelTitle = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));

    panelTitle->m_maximize_box=0;
    panelTitle->m_minimize_box=0;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("全站仪");
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,31), wxSize(w,122), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w;
    h1=h-44;

    listPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(0,11),wxSize(w1,100), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    listPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TpsDlg::OnPaintBackground,0,this);

    listPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TpsDlg::OnPaintList,0,this);
    listPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TpsDlg::OnMotionList,0,this);
    listPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TpsDlg::OnLeaveList,0,this);
    listPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TpsDlg::OnClickList,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    ListCount=0;
    for(int i=0;i<4;i++)
    {
        ListItem[i]=wxEmptyString;
    }

    motion=ID_TPS_LIST_NONE;
}

TpsDlg::~TpsDlg()
{

}

void TpsDlg::OnPaintList(wxPaintEvent& event)
{
    wxPaintDC dc(listPanel);
    int w,h;
    listPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(-1,-1,w+2,h+2);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1=0;
        int y1=0;
        int w1=w;
        int h1=25;
        int i=0;
        while(i<4)
        {
            tpsButton[i+3].x=x1;
            tpsButton[i+3].y=y1+h1*i;
            tpsButton[i+3].width=w1;
            tpsButton[i+3].height=h1;

            if(motion==i+3)
            {
                tps=motion-3;
                memDC.SetPen(wxPen(wxColor(50,155,255)));
                memDC.SetBrush(wxBrush(wxColor(50,155,255)));
                memDC.DrawRectangle(x1,y1+h1*i,w1,h1);
                memDC.SetTextForeground(wxColor(255,255,255));
                memDC.DrawLabel(ListItem[i],wxRect(x1+50,y1+h1*i,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else if(tps==i)
            {
                memDC.SetPen(wxPen(wxColor(50,155,255)));
                memDC.SetBrush(wxBrush(wxColor(50,155,255)));
                memDC.DrawRectangle(x1,y1+h1*i,w1,h1);
                memDC.SetTextForeground(wxColor(255,255,255));
                memDC.DrawLabel(ListItem[i],wxRect(x1+50,y1+h1*i,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            }
            else
            {
                memDC.SetTextForeground(wxColor(25,35,45));
                memDC.DrawLabel(ListItem[i],wxRect(x1+50,y1+h1*i,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

            i++;
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}


void TpsDlg::OnMotionList(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>tpsButton[ID_TPS_LIST_TPS0].x && x<tpsButton[ID_TPS_LIST_TPS0].x+tpsButton[ID_TPS_LIST_TPS0].width)
    {
        if(y>tpsButton[ID_TPS_LIST_TPS0].y && y<tpsButton[ID_TPS_LIST_TPS0].y+tpsButton[ID_TPS_LIST_TPS0].height)
        {
            motion=ID_TPS_LIST_TPS0;
        }
        else if(y>tpsButton[ID_TPS_LIST_TPS1].y && y<tpsButton[ID_TPS_LIST_TPS1].y+tpsButton[ID_TPS_LIST_TPS1].height)
        {
            motion=ID_TPS_LIST_TPS1;
        }
        else if(y>tpsButton[ID_TPS_LIST_TPS2].y && y<tpsButton[ID_TPS_LIST_TPS2].y+tpsButton[ID_TPS_LIST_TPS2].height)
        {
            motion=ID_TPS_LIST_TPS2;
        }
        else if(y>tpsButton[ID_TPS_LIST_TPS3].y && y<tpsButton[ID_TPS_LIST_TPS3].y+tpsButton[ID_TPS_LIST_TPS3].height)
        {
            motion=ID_TPS_LIST_TPS3;
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
    listPanel->Refresh();
}

void TpsDlg::OnLeaveList(wxMouseEvent& event)
{
    motion=ID_TPS_LIST_NONE;
    listPanel->Refresh();
}

void TpsDlg::OnClickList(wxMouseEvent& event)
{
    if(motion>=3 && motion<=6)
    {
        EndModal(wxID_OK);
    }
}

void TpsDlg::OnPaintBackground(wxPaintEvent& event)
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
        memDC.DrawLine(0,111,w,111);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

