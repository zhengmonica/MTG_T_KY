///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "HeadMileDlg.h"
#include "mtg_t_svrApp.h"
#include <wx/dcclient.h>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
const long HeadMileDlg::ID_PANEL1 = wxNewId();
const long HeadMileDlg::ID_PANEL2 = wxNewId();
///////////////////////////////////////////////////////////////////////////

HeadMileDlg::HeadMileDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //this->SetSize(320,240);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize);
	//this->SetLabel(_("确认"));
	int w,h;
	this->GetClientSize(&w,&h);

    panelBackground = new wxPanel(this, ID_PANEL2, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelBackground->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    Mile = new wxMyTextCtrl(panelBackground, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER);

    panelBackground->Connect(wxEVT_PAINT,(wxObjectEventFunction)&HeadMileDlg::OnPaintBackground,0,this);
    panelBackground->Connect(wxEVT_MOTION,(wxObjectEventFunction)&HeadMileDlg::OnMotionBackground,0,this);
    panelBackground->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&HeadMileDlg::OnLeaveBackground,0,this);
    panelBackground->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&HeadMileDlg::OnClickBackground,0,this);

	this->Centre( wxBOTH );
}

HeadMileDlg::~HeadMileDlg()
{
}

void HeadMileDlg::OnPaintBackground(wxPaintEvent& event)
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
        memDC.DrawLabel(_("请输入切口里程"),wxRect(x1,y1,85,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1+=27;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        Mile->SetSize(x1+2,y1+6,w1-4,h1-7);

        //x1=x1+15;
        //w1=w1-30;
        y1=y1+h1+15;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x,y1,x+w,y1);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x,y1+1,x+w,y1+1);
        y1=y1+12;

        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,2);
        headMileButton[ID_HEADMILE_OK].x=x1+1;
        headMileButton[ID_HEADMILE_OK].y=y1+1;
        headMileButton[ID_HEADMILE_OK].width=w1/2-1;
        headMileButton[ID_HEADMILE_OK].height=h1-2;

        headMileButton[ID_HEADMILE_CANCEL].x=headMileButton[ID_HEADMILE_OK].x+headMileButton[ID_HEADMILE_OK].width;
        headMileButton[ID_HEADMILE_CANCEL].y=headMileButton[ID_HEADMILE_OK].y;
        headMileButton[ID_HEADMILE_CANCEL].width=headMileButton[ID_HEADMILE_OK].width;
        headMileButton[ID_HEADMILE_CANCEL].height=headMileButton[ID_HEADMILE_OK].height;
        if(motion==ID_HEADMILE_OK)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(headMileButton[ID_HEADMILE_OK]);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
        }

        memDC.DrawLabel(_("确 定"),headMileButton[ID_HEADMILE_OK],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_HEADMILE_CANCEL)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(headMileButton[ID_HEADMILE_CANCEL]);
        }
        else
        {
            memDC.SetTextForeground(icolor[0]);
        }

        memDC.DrawLabel(_("取 消"),headMileButton[ID_HEADMILE_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void HeadMileDlg::OnMotionBackground(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>headMileButton[ID_HEADMILE_OK].y && y<headMileButton[ID_HEADMILE_OK].y+headMileButton[ID_HEADMILE_OK].height)
    {
        if(x>headMileButton[ID_HEADMILE_OK].x && x<headMileButton[ID_HEADMILE_OK].x+headMileButton[ID_HEADMILE_OK].width)
        {
            motion=ID_HEADMILE_OK;
        }
        else if(x>headMileButton[ID_HEADMILE_CANCEL].x && x<headMileButton[ID_HEADMILE_CANCEL].x+headMileButton[ID_HEADMILE_CANCEL].width)
        {
            motion=ID_HEADMILE_CANCEL;
        }
        else
        {
            motion=ID_HEADMILE_NONE;
        }
    }
    else
    {
        motion=ID_HEADMILE_NONE;
    }
    panelBackground->Refresh();
}

void HeadMileDlg::OnLeaveBackground(wxMouseEvent& event)
{
    motion=ID_HEADMILE_NONE;
    panelBackground->Refresh();
}

void HeadMileDlg::OnClickBackground(wxMouseEvent& event)
{
    if(motion==ID_HEADMILE_OK)
    {
        EndModal(wxID_OK);
    }
    else if(motion==ID_HEADMILE_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }
    else
    {
        panelBackground->Refresh();
    }
}
