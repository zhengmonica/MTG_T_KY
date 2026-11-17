///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "V_Line.h"
#include "mtg_t_cliApp.h"
#include <wx/dcclient.h>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
const long V_Line::ID_PANEL2 = wxNewId();
///////////////////////////////////////////////////////////////////////////

V_Line::V_Line( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //this->SetSize(320,240);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize);
	//this->SetLabel(_("确认"));
	int w,h;
	this->GetClientSize(&w,&h);

    panelBackground = new wxPanel(this, ID_PANEL2, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelBackground->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    L = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    i = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    //m_x = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    //m_y = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);

    panelBackground->Connect(wxEVT_PAINT,(wxObjectEventFunction)&V_Line::OnPaintBackground,0,this);
    panelBackground->Connect(wxEVT_MOTION,(wxObjectEventFunction)&V_Line::OnMotionBackground,0,this);
    panelBackground->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&V_Line::OnLeaveBackground,0,this);
    panelBackground->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&V_Line::OnClickBackground,0,this);

	this->Centre( wxBOTH );
}

V_Line::~V_Line()
{
}

void V_Line::OnPaintBackground(wxPaintEvent& event)
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
        memDC.DrawLabel(_("长度"),wxRect(x1,y1,70,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        L->SetSize(x1+77,y1+6,w1-94,h1-7);
        y1=y1+h1+7;
        memDC.DrawLabel(_("坡度（‰）"),wxRect(x1,y1,70,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        i->SetSize(x1+77,y1+6,w1-94,h1-7);


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
        vlineButton[ID_VLINE_CONFIRM].x=x1+1;
        vlineButton[ID_VLINE_CONFIRM].y=y1+1;
        vlineButton[ID_VLINE_CONFIRM].width=w1/2-1;
        vlineButton[ID_VLINE_CONFIRM].height=h1-2;

        vlineButton[ID_VLINE_CANCEL].x=vlineButton[ID_VLINE_CONFIRM].x+vlineButton[ID_VLINE_CONFIRM].width;
        vlineButton[ID_VLINE_CANCEL].y=vlineButton[ID_VLINE_CONFIRM].y;
        vlineButton[ID_VLINE_CANCEL].width=vlineButton[ID_VLINE_CONFIRM].width;
        vlineButton[ID_VLINE_CANCEL].height=vlineButton[ID_VLINE_CONFIRM].height;
        if(motion==ID_VLINE_CONFIRM)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(vlineButton[ID_VLINE_CONFIRM]);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawLabel(_("确 定"),vlineButton[ID_VLINE_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_VLINE_CANCEL)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(vlineButton[ID_VLINE_CANCEL]);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
        }

        memDC.DrawLabel(_("取 消"),vlineButton[ID_VLINE_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void V_Line::OnMotionBackground(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>vlineButton[ID_VLINE_CONFIRM].y && y<vlineButton[ID_VLINE_CONFIRM].y+vlineButton[ID_VLINE_CONFIRM].height)
    {
        if(x>vlineButton[ID_VLINE_CONFIRM].x && x<vlineButton[ID_VLINE_CONFIRM].x+vlineButton[ID_VLINE_CONFIRM].width)
        {
            motion=ID_VLINE_CONFIRM;
        }
        else if(x>vlineButton[ID_VLINE_CANCEL].x && x<vlineButton[ID_VLINE_CANCEL].x+vlineButton[ID_VLINE_CANCEL].width)
        {
            motion=ID_VLINE_CANCEL;
        }
        else
        {
            motion=ID_VLINE_NONE;
        }
    }
    else
    {
        motion=ID_VLINE_NONE;
    }
    panelBackground->Refresh();
}

void V_Line::OnLeaveBackground(wxMouseEvent& event)
{
    motion=ID_VLINE_NONE;
    panelBackground->Refresh();
}

void V_Line::OnClickBackground(wxMouseEvent& event)
{
    if(motion==ID_VLINE_CONFIRM)
    {
        EndModal(wxID_OK);
    }
    else if(motion==ID_VLINE_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }
    else
    {
        panelBackground->Refresh();
    }
}
