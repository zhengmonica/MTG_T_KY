///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "V_Round.h"
#include "mtg_tApp.h"
#include <wx/dcclient.h>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
const long V_Round::ID_PANEL1 = wxNewId();
const long V_Round::ID_PANEL2 = wxNewId();
///////////////////////////////////////////////////////////////////////////

V_Round::V_Round( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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

    panelBackground->Connect(wxEVT_PAINT,(wxObjectEventFunction)&V_Round::OnPaintBackground,0,this);
    panelBackground->Connect(wxEVT_MOTION,(wxObjectEventFunction)&V_Round::OnMotionBackground,0,this);
    panelBackground->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&V_Round::OnLeaveBackground,0,this);
    panelBackground->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&V_Round::OnClickBackground,0,this);


    Turn=0;
	this->Centre( wxBOTH );
}

V_Round::~V_Round()
{
}

void V_Round::OnPaintBackground(wxPaintEvent& event)
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
        memDC.DrawLabel(_("曲线形状"),wxRect(x1,y1,67,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        varcButton[ID_VARC_TURN].x=x1+75;
        varcButton[ID_VARC_TURN].y=y1;
        varcButton[ID_VARC_TURN].width=w1-90;
        varcButton[ID_VARC_TURN].height=h1;
        if(motion==ID_VARC_TURN)
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
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        if(Turn==0)
        {
            memDC.DrawLabel(_("凸曲线"),wxRect(varcButton[ID_VARC_TURN]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("凹曲线"),wxRect(varcButton[ID_VARC_TURN]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
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
        varcButton[ID_VARC_CONFIRM].x=x1+1;
        varcButton[ID_VARC_CONFIRM].y=y1+1;
        varcButton[ID_VARC_CONFIRM].width=w1/2-1;
        varcButton[ID_VARC_CONFIRM].height=h1-2;

        varcButton[ID_VARC_CANCEL].x=varcButton[ID_VARC_CONFIRM].x+varcButton[ID_VARC_CONFIRM].width;
        varcButton[ID_VARC_CANCEL].y=varcButton[ID_VARC_CONFIRM].y;
        varcButton[ID_VARC_CANCEL].width=varcButton[ID_VARC_CONFIRM].width;
        varcButton[ID_VARC_CANCEL].height=varcButton[ID_VARC_CONFIRM].height;
        if(motion==ID_VARC_CONFIRM)
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
            memDC.SetBrush(btnBrush[2]);
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(varcButton[ID_VARC_CONFIRM]);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawLabel(_("确 定"),varcButton[ID_VARC_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_VARC_CANCEL)
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
            memDC.SetBrush(btnBrush[2]);
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(varcButton[ID_VARC_CANCEL]);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
        }

        memDC.DrawLabel(_("取 消"),varcButton[ID_VARC_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void V_Round::OnMotionBackground(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>varcButton[ID_VARC_CONFIRM].y && y<varcButton[ID_VARC_CONFIRM].y+varcButton[ID_VARC_CONFIRM].height)
    {
        if(x>varcButton[ID_VARC_CONFIRM].x && x<varcButton[ID_VARC_CONFIRM].x+varcButton[ID_VARC_CONFIRM].width)
        {
            motion=ID_VARC_CONFIRM;
        }
        else if(x>varcButton[ID_VARC_CANCEL].x && x<varcButton[ID_VARC_CANCEL].x+varcButton[ID_VARC_CANCEL].width)
        {
            motion=ID_VARC_CANCEL;
        }
        else
        {
            motion=ID_VARC_NONE;
        }
    }
    else if(y>varcButton[ID_VARC_TURN].y && y<varcButton[ID_VARC_TURN].y+varcButton[ID_VARC_TURN].height)
    {
        if(x>varcButton[ID_VARC_TURN].x && x<varcButton[ID_VARC_TURN].x+varcButton[ID_VARC_TURN].width)
        {
            motion=ID_VARC_TURN;
        }
        else
        {
            motion=ID_VARC_NONE;
        }
    }
    else
    {
        motion=ID_VARC_NONE;
    }
    panelBackground->Refresh();
}

void V_Round::OnLeaveBackground(wxMouseEvent& event)
{
    motion=ID_VARC_NONE;
    panelBackground->Refresh();
}

void V_Round::OnClickBackground(wxMouseEvent& event)
{
    if(motion==ID_VARC_CONFIRM)
    {
       EndModal(wxID_OK);
    }
    else if(motion==ID_VARC_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }
    else if(motion==ID_VARC_TURN)
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
