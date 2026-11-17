///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "H_Moderate.h"
#include "mtg_t_svrApp.h"
#include <wx/dcclient.h>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>

const long H_Moderate::ID_PANEL2 = wxNewId();
///////////////////////////////////////////////////////////////////////////

H_Moderate::H_Moderate( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //this->SetSize(320,240);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize);
	//this->SetLabel(_("确认"));
	int w,h;
	this->GetClientSize(&w,&h);

    panelMain = new wxPanel(this, ID_PANEL2, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    R1 = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    R2 = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    L = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
   // m_y = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&H_Moderate::OnPaintMain,0,this);
    panelMain->Connect(wxEVT_MOTION,(wxObjectEventFunction)&H_Moderate::OnMotionMain,0,this);
    panelMain->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&H_Moderate::OnLeaveMain,0,this);
    panelMain->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&H_Moderate::OnClickMain,0,this);
    Turn=0;
	this->Centre( wxBOTH );
}

H_Moderate::~H_Moderate()
{
}

void H_Moderate::OnPaintMain(wxPaintEvent& event)
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
        memDC.DrawLabel(_("起点半径"),wxRect(x1,y1,67,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        R1->SetSize(x1+77,y1+6,w1-94,h1-7);
        y1=y1+h1+7;
        memDC.DrawLabel(_("终点半径"),wxRect(x1,y1,67,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        R2->SetSize(x1+77,y1+6,w1-94,h1-7);
        y1=y1+h1+7;
        memDC.DrawLabel(_("曲线长度"),wxRect(x1,y1,67,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        L->SetSize(x1+77,y1+6,w1-94,h1-7);
        y1=y1+h1+7;
        memDC.DrawLabel(_("曲线转向"),wxRect(x1,y1,67,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        hspiralButton[ID_HSPIRAL_LEFT].x=x1+75;
        hspiralButton[ID_HSPIRAL_LEFT].y=y1;
        hspiralButton[ID_HSPIRAL_LEFT].width=w1/2-45;
        hspiralButton[ID_HSPIRAL_LEFT].height=h1;
        if(Turn==0)
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[1]);
        }
        else if(motion==ID_HSPIRAL_LEFT)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
        }
        memDC.DrawRectangle(hspiralButton[ID_HSPIRAL_LEFT]);
        memDC.DrawLabel(_("左"),wxRect(hspiralButton[ID_HSPIRAL_LEFT]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        hspiralButton[ID_HSPIRAL_RIGHT].x=x1+w1/2+29;
        hspiralButton[ID_HSPIRAL_RIGHT].y=y1;
        hspiralButton[ID_HSPIRAL_RIGHT].width=w1/2-45;
        hspiralButton[ID_HSPIRAL_RIGHT].height=h1;
        if(Turn==1)
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[1]);
        }
        else if(motion==ID_HSPIRAL_RIGHT)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
        }
        memDC.DrawRectangle(hspiralButton[ID_HSPIRAL_RIGHT]);
        memDC.DrawLabel(_("右"),wxRect(hspiralButton[ID_HSPIRAL_RIGHT]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+15;
        w1=w1-30;
        y1=y1+h1+7;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x,y1,x+w,y1);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x,y1+1,x+w,y1+1);
        y1=y1+12;

        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,2);
        hspiralButton[ID_HSPIRAL_CONFIRM].x=x1+1;
        hspiralButton[ID_HSPIRAL_CONFIRM].y=y1+1;
        hspiralButton[ID_HSPIRAL_CONFIRM].width=w1/2-1;
        hspiralButton[ID_HSPIRAL_CONFIRM].height=h1-2;

        hspiralButton[ID_HSPIRAL_CANCEL].x=hspiralButton[ID_HSPIRAL_CONFIRM].x+hspiralButton[ID_HSPIRAL_CONFIRM].width;
        hspiralButton[ID_HSPIRAL_CANCEL].y=hspiralButton[ID_HSPIRAL_CONFIRM].y;
        hspiralButton[ID_HSPIRAL_CANCEL].width=hspiralButton[ID_HSPIRAL_CONFIRM].width;
        hspiralButton[ID_HSPIRAL_CANCEL].height=hspiralButton[ID_HSPIRAL_CONFIRM].height;
        if(motion==ID_HSPIRAL_CONFIRM)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(hspiralButton[ID_HSPIRAL_CONFIRM]);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
        }

        memDC.DrawLabel(_("确 定"),hspiralButton[ID_HSPIRAL_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_HSPIRAL_CANCEL)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(hspiralButton[ID_HSPIRAL_CANCEL]);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawLabel(_("取 消"),hspiralButton[ID_HSPIRAL_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void H_Moderate::OnMotionMain(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>hspiralButton[ID_HSPIRAL_CONFIRM].y && y<hspiralButton[ID_HSPIRAL_CONFIRM].y+hspiralButton[ID_HSPIRAL_CONFIRM].height)
    {
        if(x>hspiralButton[ID_HSPIRAL_CONFIRM].x && x<hspiralButton[ID_HSPIRAL_CONFIRM].x+hspiralButton[ID_HSPIRAL_CONFIRM].width)
        {
            motion=ID_HSPIRAL_CONFIRM;
        }
        else if(x>hspiralButton[ID_HSPIRAL_CANCEL].x && x<hspiralButton[ID_HSPIRAL_CANCEL].x+hspiralButton[ID_HSPIRAL_CANCEL].width)
        {
            motion=ID_HSPIRAL_CANCEL;
        }
        else
        {
            motion=ID_HSPIRAL_NONE;
        }
    }
    else if(y>hspiralButton[ID_HSPIRAL_LEFT].y && y<hspiralButton[ID_HSPIRAL_LEFT].y+hspiralButton[ID_HSPIRAL_LEFT].height)
    {
        if(x>hspiralButton[ID_HSPIRAL_LEFT].x && x<hspiralButton[ID_HSPIRAL_LEFT].x+hspiralButton[ID_HSPIRAL_LEFT].width)
        {
            motion=ID_HSPIRAL_LEFT;
        }
        else if(x>hspiralButton[ID_HSPIRAL_RIGHT].x && x<hspiralButton[ID_HSPIRAL_RIGHT].x+hspiralButton[ID_HSPIRAL_RIGHT].width)
        {
            motion=ID_HSPIRAL_RIGHT;
        }
        else
        {
            motion=ID_HSPIRAL_NONE;
        }
    }
    else
    {
        motion=ID_HSPIRAL_NONE;
    }
    panelMain->Refresh();
}

void H_Moderate::OnLeaveMain(wxMouseEvent& event)
{
    motion=ID_HSPIRAL_NONE;
    panelMain->Refresh();
}

void H_Moderate::OnClickMain(wxMouseEvent& event)
{
    if(motion==ID_HSPIRAL_CONFIRM)
    {
        EndModal(wxID_OK);
    }
    else if(motion==ID_HSPIRAL_CANCEL)
    {
        EndModal(wxID_CANCEL);
        Close();
    }
    else if(motion==ID_HSPIRAL_LEFT)
    {
        Turn=0;
    }
    else if(motion==ID_HSPIRAL_RIGHT)
    {
        Turn=1;
    }

    panelMain->Refresh();
}
