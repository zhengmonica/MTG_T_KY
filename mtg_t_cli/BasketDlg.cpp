///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BasketDlg.h"
#include "mtg_t_cliApp.h"
//#include "confirmdlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(BasketDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(BasketDlg)
#include <wx/font.h>
#include <stdio.h>
#include "wx/filefn.h"
#include <wx/dir.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(BasketDlg)


const long BasketDlg::ID_PANEL1 = wxNewId();                  //标题
//*)

BasketDlg::BasketDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w;
    h1=h-57;
    bskPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    bskPanel->SetBackgroundColour(wxColor(239,239,239));

    x2=15;
    y2=15;
    w2=w-x2*2;
    h2=h1-30;
    basketsPanel=new wxPanel(bskPanel, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    basketsPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    basketList = new wxListView(basketsPanel, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&BasketDlg::OnPaintBackground,0,this);

    basketsPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&BasketDlg::OnPaintBasket,0,this);
    basketsPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&BasketDlg::OnMotionBasket,0,this);
    basketsPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&BasketDlg::OnLeaveBasket,0,this);
    basketsPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&BasketDlg::OnClickBasket,0,this);

    basketList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&BasketDlg::OnBasketListActivated,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&BasketDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&BasketDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&BasketDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&BasketDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    int i=0;
    basketList->InsertColumn(i++,_("点名"),wxLIST_FORMAT_CENTRE,55);
    basketList->InsertColumn(i++,_("X"),wxLIST_FORMAT_CENTRE,90);
    basketList->InsertColumn(i++,_("Y"),wxLIST_FORMAT_CENTRE,90);
    basketList->InsertColumn(i++,_("Z"),wxLIST_FORMAT_CENTRE,80);
    basketList->InsertColumn(i++,_("T"),wxLIST_FORMAT_CENTRE,115);
    basketList->InsertColumn(i++,_("测站/后视"),wxLIST_FORMAT_CENTRE,65);

    motion=ID_BASKET_NONE;
}

BasketDlg::~BasketDlg()
{

}

void BasketDlg::OnPaintBasket(wxPaintEvent& event)
{
    wxPaintDC dc(basketsPanel);
    int w,h;
    basketsPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1=0;
        int y1=0;
        int w1=120;
        int h1=25;
        basketList->GetPosition(&x1,&y1);
        basketList->GetSize(&w1,&h1);
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(225,225,225)));
        h1=25;
        y1=y1-h1+1;
        memDC.DrawRectangle(x1,y1,w1,h1);
        int i=0;
        w1=basketList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("点名"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=basketList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("北坐标(X)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=basketList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("东坐标(Y)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=basketList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("高程(Z)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=basketList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=basketList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("测站/后视"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}


void BasketDlg::OnMotionBasket(wxMouseEvent& event)
{

}

void BasketDlg::OnLeaveBasket(wxMouseEvent& event)
{

}

void BasketDlg::OnClickBasket(wxMouseEvent& event)
{

}

void BasketDlg::OnPaintBottom(wxPaintEvent& event)
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

        memDC.SetPen(wxPen(wxColor(117,117,117)));

        y1=9;
        w1=32;
        h1=26;
        x1=9;

        w1=65;
        x1=w/2+6;
        bskButton[ID_BASKET_QUIT].x=x1;
        bskButton[ID_BASKET_QUIT].y=y1;
        bskButton[ID_BASKET_QUIT].width=w1;
        bskButton[ID_BASKET_QUIT].height=h1;
        if(motion==ID_BASKET_QUIT)
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

        x1=w/2-w1-6;
        bskButton[ID_BASKET_OK].x=x1;
        bskButton[ID_BASKET_OK].y=y1;
        bskButton[ID_BASKET_OK].width=w1;
        bskButton[ID_BASKET_OK].height=h1;
        if(motion==ID_BASKET_OK)
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

void BasketDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>bskButton[ID_BASKET_QUIT].y && y<bskButton[ID_BASKET_QUIT].y+bskButton[ID_BASKET_QUIT].height)
    {
        if(x>bskButton[ID_BASKET_QUIT].x && x<bskButton[ID_BASKET_QUIT].x+bskButton[ID_BASKET_QUIT].width)
        {
            motion=ID_BASKET_QUIT;
        }
        else if(x>bskButton[ID_BASKET_OK].x && x<bskButton[ID_BASKET_OK].x+bskButton[ID_BASKET_OK].width)
        {
            motion=ID_BASKET_OK;
        }
        else
        {
            motion=ID_BASKET_NONE;
        }
    }
    else
    {
        motion=ID_BASKET_NONE;
    }
    panelBottom->Refresh();
}

void BasketDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_BASKET_NONE;
    panelBottom->Refresh();
}

void BasketDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_BASKET_OK)
    {
        EndModal(wxID_OK);
    }
    else if(motion==ID_BASKET_QUIT)
    {
        Destroy();
    }
    //panelBottom->Refresh();
}

void BasketDlg::OnBasketListActivated(wxListEvent& event)
{
    EndModal(wxID_OK);
}

void BasketDlg::OnPaintBackground(wxPaintEvent& event)
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

