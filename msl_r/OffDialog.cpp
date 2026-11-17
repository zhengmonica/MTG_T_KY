///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "OffDialog.h"
#include "msr_tApp.h"
#include <wx/dcclient.h>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
const long OffDialog::ID_PANEL2 = wxNewId();
///////////////////////////////////////////////////////////////////////////

OffDialog::OffDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //this->SetSize(320,240);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize);
	//this->SetLabel(_("确认"));
	int w,h;
	this->GetClientSize(&w,&h);

    panelBackground = new wxPanel(this, ID_PANEL2, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelBackground->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    Mile = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    Off = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    //m_x = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);
    //m_y = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);

    panelBackground->Connect(wxEVT_PAINT,(wxObjectEventFunction)&OffDialog::OnPaintBackground,0,this);
    panelBackground->Connect(wxEVT_MOTION,(wxObjectEventFunction)&OffDialog::OnMotionBackground,0,this);
    panelBackground->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&OffDialog::OnLeaveBackground,0,this);
    panelBackground->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&OffDialog::OnClickBackground,0,this);
    Type=OFF_TYPE_HORIZON;
	this->Centre( wxBOTH );
}

OffDialog::~OffDialog()
{
}

void OffDialog::OnPaintBackground(wxPaintEvent& event)
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
        if(Type==OFF_TYPE_MILE)
        {
            SetTitle(_("长短链"));
            memDC.DrawLabel(_("原里程"),wxRect(x1,y1,70,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        else if(Type==OFF_TYPE_HORIZON)
        {
            SetTitle(_("平面偏移"));
            memDC.DrawLabel(_("里程"),wxRect(x1,y1,70,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            SetTitle(_("垂直偏移"));
            memDC.DrawLabel(_("里程"),wxRect(x1,y1,70,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        Mile->SetSize(x1+77,y1+6,w1-94,h1-7);
        y1=y1+h1+7;
        if(Type==OFF_TYPE_MILE)
        {
            memDC.DrawLabel(_("新里程"),wxRect(x1,y1,70,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("偏移(毫米)"),wxRect(x1,y1,70,h1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1+75,y1,w1-90,h1,3);
        Off->SetSize(x1+77,y1+6,w1-94,h1-7);


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
        offButton[ID_OFF_CONFIRM].x=x1+1;
        offButton[ID_OFF_CONFIRM].y=y1+1;
        offButton[ID_OFF_CONFIRM].width=w1/2-1;
        offButton[ID_OFF_CONFIRM].height=h1-2;

        offButton[ID_OFF_CANCEL].x=offButton[ID_OFF_CONFIRM].x+offButton[ID_OFF_CONFIRM].width;
        offButton[ID_OFF_CANCEL].y=offButton[ID_OFF_CONFIRM].y;
        offButton[ID_OFF_CANCEL].width=offButton[ID_OFF_CONFIRM].width;
        offButton[ID_OFF_CANCEL].height=offButton[ID_OFF_CONFIRM].height;
        if(motion==ID_OFF_CONFIRM)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.DrawRectangle(offButton[ID_OFF_CONFIRM]);
        }
        memDC.DrawLabel(_("确 定"),offButton[ID_OFF_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_OFF_CANCEL)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.DrawRectangle(offButton[ID_OFF_CANCEL]);
        }

        memDC.DrawLabel(_("取 消"),offButton[ID_OFF_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void OffDialog::OnMotionBackground(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>offButton[ID_OFF_CONFIRM].y && y<offButton[ID_OFF_CONFIRM].y+offButton[ID_OFF_CONFIRM].height)
    {
        if(x>offButton[ID_OFF_CONFIRM].x && x<offButton[ID_OFF_CONFIRM].x+offButton[ID_OFF_CONFIRM].width)
        {
            motion=ID_OFF_CONFIRM;
        }
        else if(x>offButton[ID_OFF_CANCEL].x && x<offButton[ID_OFF_CANCEL].x+offButton[ID_OFF_CANCEL].width)
        {
            motion=ID_OFF_CANCEL;
        }
        else
        {
            motion=ID_OFF_NONE;
        }
    }
    else
    {
        motion=ID_OFF_NONE;
    }
    panelBackground->Refresh();
}

void OffDialog::OnLeaveBackground(wxMouseEvent& event)
{
    motion=ID_OFF_NONE;
    panelBackground->Refresh();
}

void OffDialog::OnClickBackground(wxMouseEvent& event)
{
    if(motion==ID_OFF_CONFIRM)
    {
        EndModal(wxID_OK);
    }
    else if(motion==ID_OFF_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }
    else
    {
        panelBackground->Refresh();
    }
}
