///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "H_Round.h"
#include "mtg_t_svrApp.h"
#include <wx/dcclient.h>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
const long H_Round::ID_PANEL2 = wxNewId();
///////////////////////////////////////////////////////////////////////////

H_Round::H_Round( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //this->SetSize(320,240);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize);
	//this->SetLabel(_("确认"));
	int w,h;
	this->GetClientSize(&w,&h);

    panelMain = new wxPanel(this, ID_PANEL2, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    R = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    L = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    //m_x = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    //m_y = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&H_Round::OnPaintMain,0,this);
    panelMain->Connect(wxEVT_MOTION,(wxObjectEventFunction)&H_Round::OnMotionMain,0,this);
    panelMain->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&H_Round::OnLeaveMain,0,this);
    panelMain->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&H_Round::OnClickMain,0,this);

    Turn=0;
	this->Centre( wxBOTH );
}

H_Round::~H_Round()
{
}

void H_Round::OnPaintMain(wxPaintEvent& event)
{
    wxPaintDC dc(panelMain);
    int w,h;
    panelMain->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
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

        int x1,y1,w1,h1;
        x1=7;
        y1=22;
        h1=28;
        w1=w-x1*2;
        memDC.DrawLabel(_("曲线半径"),wxRect(x1,y1,67,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        R->SetSize(x1+77,y1+6,w1-94,h1-7);
        y1=y1+h1+7;
        memDC.DrawLabel(_("曲线长度"),wxRect(x1,y1,67,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        L->SetSize(x1+77,y1+6,w1-94,h1-7);
        y1=y1+h1+7;
        memDC.DrawLabel(_("曲线转向"),wxRect(x1,y1,67,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        harcButton[ID_HARC_LEFT].x=x1+75;
        harcButton[ID_HARC_LEFT].y=y1;
        harcButton[ID_HARC_LEFT].width=w1/2-45;
        harcButton[ID_HARC_LEFT].height=h1;
        if(Turn==0)
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[1]);
        }
        else if(motion==ID_HARC_LEFT)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
        }
        memDC.DrawRectangle(harcButton[ID_HARC_LEFT]);
        memDC.DrawLabel(_("左"),wxRect(harcButton[ID_HARC_LEFT]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        harcButton[ID_HARC_RIGHT].x=x1+w1/2+29;
        harcButton[ID_HARC_RIGHT].y=y1;
        harcButton[ID_HARC_RIGHT].width=w1/2-45;
        harcButton[ID_HARC_RIGHT].height=h1;
        if(Turn==1)
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[1]);
        }
        else if(motion==ID_HARC_RIGHT)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
        }
        memDC.DrawRectangle(harcButton[ID_HARC_RIGHT]);
        memDC.DrawLabel(_("右"),wxRect(harcButton[ID_HARC_RIGHT]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+15;
        w1=w1-30;
        y1=y1+h1+7;
        memDC.SetPen(wxPen(wxColor(130,135,144)));
        memDC.DrawLine(x,y1,x+w,y1);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x,y1+1,x+w,y1+1);
        y1=y1+12;

        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,2);
        harcButton[ID_HARC_CONFIRM].x=x1+1;
        harcButton[ID_HARC_CONFIRM].y=y1+1;
        harcButton[ID_HARC_CONFIRM].width=w1/2-1;
        harcButton[ID_HARC_CONFIRM].height=h1-2;

        harcButton[ID_HARC_CANCEL].x=harcButton[ID_HARC_CONFIRM].x+harcButton[ID_HARC_CONFIRM].width;
        harcButton[ID_HARC_CANCEL].y=harcButton[ID_HARC_CONFIRM].y;
        harcButton[ID_HARC_CANCEL].width=harcButton[ID_HARC_CONFIRM].width;
        harcButton[ID_HARC_CANCEL].height=harcButton[ID_HARC_CONFIRM].height;
        if(motion==ID_HARC_CONFIRM)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(ibrush[0].GetColour())));
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRectangle(harcButton[ID_HARC_CONFIRM]);
        memDC.DrawLabel(_("确 定"),harcButton[ID_HARC_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_HARC_CANCEL)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(ibrush[0].GetColour())));
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRectangle(harcButton[ID_HARC_CANCEL]);

        memDC.DrawLabel(_("取 消"),harcButton[ID_HARC_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void H_Round::OnMotionMain(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>harcButton[ID_HARC_CONFIRM].y && y<harcButton[ID_HARC_CONFIRM].y+harcButton[ID_HARC_CONFIRM].height)
    {
        if(x>harcButton[ID_HARC_CONFIRM].x && x<harcButton[ID_HARC_CONFIRM].x+harcButton[ID_HARC_CONFIRM].width)
        {
            motion=ID_HARC_CONFIRM;
        }
        else if(x>harcButton[ID_HARC_CANCEL].x && x<harcButton[ID_HARC_CANCEL].x+harcButton[ID_HARC_CANCEL].width)
        {
            motion=ID_HARC_CANCEL;
        }
        else
        {
            motion=ID_HARC_NONE;
        }
    }
    else if(y>harcButton[ID_HARC_LEFT].y && y<harcButton[ID_HARC_LEFT].y+harcButton[ID_HARC_LEFT].height)
    {
        if(x>harcButton[ID_HARC_LEFT].x && x<harcButton[ID_HARC_LEFT].x+harcButton[ID_HARC_LEFT].width)
        {
            motion=ID_HARC_LEFT;
        }
        else if(x>harcButton[ID_HARC_RIGHT].x && x<harcButton[ID_HARC_RIGHT].x+harcButton[ID_HARC_RIGHT].width)
        {
            motion=ID_HARC_RIGHT;
        }
        else
        {
            motion=ID_HARC_NONE;
        }
    }
    else
    {
        motion=ID_HARC_NONE;
    }
    panelMain->Refresh();
}

void H_Round::OnLeaveMain(wxMouseEvent& event)
{
    motion=ID_HARC_NONE;
    panelMain->Refresh();
}

void H_Round::OnClickMain(wxMouseEvent& event)
{
    if(motion==ID_HARC_CONFIRM)
    {
        EndModal(wxID_OK);
    }
    else if(motion==ID_HARC_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }
    else if(motion==ID_HARC_LEFT)
    {
        Turn=0;
    }
    else if(motion==ID_HARC_RIGHT)
    {
        Turn=1;
    }

    panelMain->Refresh();
}
