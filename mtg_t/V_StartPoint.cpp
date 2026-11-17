///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "V_StartPoint.h"
#include "mtg_tApp.h"
#include <wx/dcclient.h>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
const long V_StartPoint::ID_PANEL1 = wxNewId();
const long V_StartPoint::ID_PANEL2 = wxNewId();
///////////////////////////////////////////////////////////////////////////

V_StartPoint::V_StartPoint( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //this->SetSize(320,240);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize);
	//this->SetLabel(_("确认"));
	int w,h;
	this->GetClientSize(&w,&h);

    m_title = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    m_title->IsMaximinize=0;
    m_title->m_close_box=0;
    m_title->Name=_("起点");
    panelBackground = new wxPanel(this, ID_PANEL2, wxPoint(0,31), wxSize(w,h-31), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelBackground->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    H = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    i = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    L = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    //m_y = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);

    panelBackground->Connect(wxEVT_PAINT,(wxObjectEventFunction)&V_StartPoint::OnPaintBackground,0,this);
    panelBackground->Connect(wxEVT_MOTION,(wxObjectEventFunction)&V_StartPoint::OnMotionBackground,0,this);
    panelBackground->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&V_StartPoint::OnLeaveBackground,0,this);
    panelBackground->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&V_StartPoint::OnClickBackground,0,this);


	this->Centre( wxBOTH );
}

V_StartPoint::~V_StartPoint()
{
}

void V_StartPoint::OnPaintBackground(wxPaintEvent& event)
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
        memDC.DrawLabel(_("起点里程"),wxRect(x1,y1,70,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        L->SetSize(x1+77,y1+6,w1-94,h1-7);
        y1=y1+h1+7;
        memDC.DrawLabel(_("起点高程"),wxRect(x1,y1,70,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        H->SetSize(x1+77,y1+6,w1-94,h1-7);
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
        vpointButton[ID_VPOINT_CONFIRM].x=x1+1;
        vpointButton[ID_VPOINT_CONFIRM].y=y1+1;
        vpointButton[ID_VPOINT_CONFIRM].width=w1/2-1;
        vpointButton[ID_VPOINT_CONFIRM].height=h1-2;

        vpointButton[ID_VPOINT_CANCEL].x=vpointButton[ID_VPOINT_CONFIRM].x+vpointButton[ID_VPOINT_CONFIRM].width;
        vpointButton[ID_VPOINT_CANCEL].y=vpointButton[ID_VPOINT_CONFIRM].y;
        vpointButton[ID_VPOINT_CANCEL].width=vpointButton[ID_VPOINT_CONFIRM].width;
        vpointButton[ID_VPOINT_CANCEL].height=vpointButton[ID_VPOINT_CONFIRM].height;
        if(motion==ID_VPOINT_CONFIRM)
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
            memDC.SetBrush(btnBrush[2]);
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(vpointButton[ID_VPOINT_CONFIRM]);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawLabel(_("确 定"),vpointButton[ID_VPOINT_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_VPOINT_CANCEL)
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[2].GetColour())));
            memDC.SetBrush(btnBrush[2]);
            memDC.SetTextForeground(btnTextColor[1]);
            memDC.DrawRectangle(vpointButton[ID_VPOINT_CANCEL]);
        }
        else
        {
            memDC.SetTextForeground(btnTextColor[0]);
        }

        memDC.DrawLabel(_("取 消"),vpointButton[ID_VPOINT_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void V_StartPoint::OnMotionBackground(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>vpointButton[ID_VPOINT_CONFIRM].y && y<vpointButton[ID_VPOINT_CONFIRM].y+vpointButton[ID_VPOINT_CONFIRM].height)
    {
        if(x>vpointButton[ID_VPOINT_CONFIRM].x && x<vpointButton[ID_VPOINT_CONFIRM].x+vpointButton[ID_VPOINT_CONFIRM].width)
        {
            motion=ID_VPOINT_CONFIRM;
        }
        else if(x>vpointButton[ID_VPOINT_CANCEL].x && x<vpointButton[ID_VPOINT_CANCEL].x+vpointButton[ID_VPOINT_CANCEL].width)
        {
            motion=ID_VPOINT_CANCEL;
        }
        else
        {
            motion=ID_VPOINT_NONE;
        }
    }
    else
    {
        motion=ID_VPOINT_NONE;
    }
    panelBackground->Refresh();
}

void V_StartPoint::OnLeaveBackground(wxMouseEvent& event)
{
    motion=ID_VPOINT_NONE;
    panelBackground->Refresh();
}

void V_StartPoint::OnClickBackground(wxMouseEvent& event)
{
    if(motion==ID_VPOINT_CONFIRM)
    {
        EndModal(wxID_OK);
    }
    else if(motion==ID_VPOINT_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }
    else
    {
        panelBackground->Refresh();
    }
}
