///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "H_Round.h"
#include "mtg_tApp.h"
#include <wx/dcclient.h>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
const long H_Round::ID_PANEL1 = wxNewId();
const long H_Round::ID_PANEL2 = wxNewId();
///////////////////////////////////////////////////////////////////////////

H_Round::H_Round( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //this->SetSize(320,240);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize);
	//this->SetLabel(_("确认"));
	int w,h;
	this->GetClientSize(&w,&h);

    m_title = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    m_title->IsMaximinize=0;
    m_title->m_close_box=0;
    m_title->Name=_("圆曲线");
    panelBackground = new wxPanel(this, ID_PANEL2, wxPoint(0,31), wxSize(w,h-31), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelBackground->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    R = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    L = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    //m_x = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    //m_y = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);

    panelBackground->Connect(wxEVT_PAINT,(wxObjectEventFunction)&H_Round::OnPaintBackground,0,this);
    panelBackground->Connect(wxEVT_MOTION,(wxObjectEventFunction)&H_Round::OnMotionBackground,0,this);
    panelBackground->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&H_Round::OnLeaveBackground,0,this);
    panelBackground->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&H_Round::OnClickBackground,0,this);

    Turn=0;
	this->Centre( wxBOTH );
}

H_Round::~H_Round()
{
}

void H_Round::OnPaintBackground(wxPaintEvent& event)
{
    wxPaintDC dc(panelBackground);
    int w,h;
    panelBackground->GetClientSize(&w,&h);
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
        harcButton[ID_HARC_TURN].x=x1+75;
        harcButton[ID_HARC_TURN].y=y1;
        harcButton[ID_HARC_TURN].width=w1-90;
        harcButton[ID_HARC_TURN].height=h1;
        if(motion==ID_HARC_TURN)
        {
            memDC.SetPen(btnPen[2]);
            memDC.SetBrush(btnBrush[2]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(harcButton[ID_HARC_TURN],3);
        if(Turn==0)
        {
            memDC.DrawLabel(_("左转弯"),wxRect(harcButton[ID_HARC_TURN]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("右转弯"),wxRect(harcButton[ID_HARC_TURN]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        //m_x->SetSize(x1+92,y1+4,w1-94,h1-7);
        //y1=y1+h1+5;
        //memDC.DrawLabel(_("起点坐标(Y)"),wxRect(x1,y1,85,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        //memDC.SetPen(wxPen(wxColor(117,117,117)));
        //memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        //memDC.DrawRoundedRectangle(x1+90,y1-2,w1-90,h1,3);
        //m_y->SetSize(x1+92,y1+4,w1-94,h1-7);

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
            memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
            memDC.SetBrush(btnBrush[2]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(harcButton[ID_HARC_CONFIRM]);
        memDC.DrawLabel(_("确 定"),harcButton[ID_HARC_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_HARC_CANCEL)
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
            memDC.SetBrush(btnBrush[2]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(harcButton[ID_HARC_CANCEL]);

        memDC.DrawLabel(_("取 消"),harcButton[ID_HARC_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void H_Round::OnMotionBackground(wxMouseEvent& event)
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
    else if(y>harcButton[ID_HARC_TURN].y && y<harcButton[ID_HARC_TURN].y+harcButton[ID_HARC_TURN].height)
    {
        if(x>harcButton[ID_HARC_TURN].x && x<harcButton[ID_HARC_TURN].x+harcButton[ID_HARC_TURN].width)
        {
            motion=ID_HARC_TURN;
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
    panelBackground->Refresh();
}

void H_Round::OnLeaveBackground(wxMouseEvent& event)
{
    motion=ID_HARC_NONE;
    panelBackground->Refresh();
}

void H_Round::OnClickBackground(wxMouseEvent& event)
{
    if(motion==ID_HARC_CONFIRM)
    {
        EndModal(wxID_OK);
    }
    else if(motion==ID_HARC_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }
    else if(motion==ID_HARC_TURN)
    {
        if(Turn==0)
        {
            Turn=1;
        }
        else
        {
            Turn=0;
        }
        panelBackground->Refresh();
    }
    else
    {
        panelBackground->Refresh();
    }
}
