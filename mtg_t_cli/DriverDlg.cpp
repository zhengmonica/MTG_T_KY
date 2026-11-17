///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DriverDlg.h"
#include "mtg_t_cliApp.h"
//#include "confirmdlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(DriverDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(DriverDlg)
#include <wx/font.h>
#include <stdio.h>
#include "wx/filefn.h"
#include <wx/dir.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(DriverDlg)

//*)
DriverDlg::DriverDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,122), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    listPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(0,0),wxSize(w,h), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    listPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DriverDlg::OnPaintMain,0,this);

    listPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DriverDlg::OnPaintList,0,this);
    listPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DriverDlg::OnMotionList,0,this);
    listPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DriverDlg::OnLeaveList,0,this);
    listPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DriverDlg::OnClickList,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    ListCount=0;
    for(int i=0;i<4;i++)
    {
        ListItem[i]=wxEmptyString;
    }

    motion=ID_DRV_NONE;
}

DriverDlg::~DriverDlg()
{

}

void DriverDlg::OnPaintList(wxPaintEvent& event)
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
        int i=1;
        while(i<mtg->ndty+1)
        {
            int j=i-1;
            tpsButton[i].x=x1;
            tpsButton[i].y=y1+h1*j;
            tpsButton[i].width=w1;
            tpsButton[i].height=h1;

            if(motion==i)
            {
                drv=motion;
                memDC.SetPen(wxPen(wxColor(50,155,255)));
                memDC.SetBrush(wxBrush(wxColor(50,155,255)));
                memDC.DrawRectangle(x1,y1+h1*j,w1,h1);
                memDC.SetTextForeground(wxColor(255,255,255));
                memDC.DrawLabel(ListItem[i],wxRect(x1+15,y1+h1*j,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else if(drv==i)
            {
                memDC.SetPen(wxPen(wxColor(50,155,255)));
                memDC.SetBrush(wxBrush(wxColor(50,155,255)));
                memDC.DrawRectangle(x1,y1+h1*j,w1,h1);
                memDC.SetTextForeground(wxColor(255,255,255));
                memDC.DrawLabel(ListItem[i],wxRect(x1+15,y1+h1*j,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetTextForeground(wxColor(25,35,45));
                memDC.DrawLabel(ListItem[i],wxRect(x1+15,y1+h1*j,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

            i++;
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DriverDlg::OnMotionList(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>tpsButton[ID_DRV_ONE].x && x<tpsButton[ID_DRV_ONE].x+tpsButton[ID_DRV_ONE].width)
    {
        if(y>tpsButton[ID_DRV_ONE].y && y<tpsButton[ID_DRV_ONE].y+tpsButton[ID_DRV_ONE].height)
        {
            motion=ID_DRV_ONE;
        }
        else if(y>tpsButton[ID_DRV_TWO].y && y<tpsButton[ID_DRV_TWO].y+tpsButton[ID_DRV_TWO].height)
        {
            motion=ID_DRV_TWO;
        }
        else if(y>tpsButton[ID_DRV_THREE].y && y<tpsButton[ID_DRV_THREE].y+tpsButton[ID_DRV_THREE].height)
        {
            motion=ID_DRV_THREE;
        }
        else if(y>tpsButton[ID_DRV_FOUR].y && y<tpsButton[ID_DRV_FOUR].y+tpsButton[ID_DRV_FOUR].height)
        {
            motion=ID_DRV_FOUR;
        }
        else
        {
            motion=ID_DRV_NONE;
        }
    }
    else
    {
        motion=ID_DRV_NONE;
    }
    listPanel->Refresh();
}

void DriverDlg::OnLeaveList(wxMouseEvent& event)
{
    motion=ID_DRV_NONE;
    listPanel->Refresh();
}

void DriverDlg::OnClickList(wxMouseEvent& event)
{
    if(motion>=1 && motion<=mtg->ndty)
    {
        EndModal(wxID_OK);
    }
}

void DriverDlg::OnPaintMain(wxPaintEvent& event)
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
