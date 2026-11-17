#include "wx_pch.h"
#include "DistDlg.h"
#include "mtg_t_svrApp.h"
#include "ConfirmDlg.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(DistDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(DistDlg)
const long DistDlg::ID_PANEL1=wxNewId();
//*)

//(*IdInit(DistDlg)
//*)

BEGIN_EVENT_TABLE(DistDlg,wxDialog)
	//(*EventTable(DistDlg)
	//*)
END_EVENT_TABLE()

//DistDlg::DistDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
DistDlg::DistDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	//(*Initialize(DistDlg)
	//Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	//SetClientSize(wxDefaultSize);
	//Move(wxDefaultPosition);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    disterName = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    disterName->Enable(false);
    disterAngle = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    disterText = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DistDlg::OnPaintMain,0,this);
    panelMain->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DistDlg::OnMotionMain,0,this);
    panelMain->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DistDlg::OnLeaveMain,0,this);
    panelMain->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DistDlg::OnClickMain,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DistDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DistDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DistDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DistDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    motion=ID_DISTER_NONE;
}

DistDlg::~DistDlg()
{
	//(*Destroy(DistDlg)
	//*)
}


void DistDlg::OnPaintBottom(wxPaintEvent& event)
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
        x1=w/2+5;
        dsButton[ID_DISTER_QUIT].x=x1;
        dsButton[ID_DISTER_QUIT].y=y1;
        dsButton[ID_DISTER_QUIT].width=w1;
        dsButton[ID_DISTER_QUIT].height=h1;
        if(motion==ID_DISTER_QUIT)
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

        x1=w/2-w1-5;
        dsButton[ID_DISTER_OK].x=x1;
        dsButton[ID_DISTER_OK].y=y1;
        dsButton[ID_DISTER_OK].width=w1;
        dsButton[ID_DISTER_OK].height=h1;
        if(motion==ID_DISTER_OK)
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

void DistDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>dsButton[ID_DISTER_QUIT].y && y<dsButton[ID_DISTER_QUIT].y+dsButton[ID_DISTER_QUIT].height)
    {
        if(x>dsButton[ID_DISTER_QUIT].x && x<dsButton[ID_DISTER_QUIT].x+dsButton[ID_DISTER_QUIT].width)
        {
            motion=ID_DISTER_QUIT;
        }
        else if(x>dsButton[ID_DISTER_OK].x && x<dsButton[ID_DISTER_OK].x+dsButton[ID_DISTER_OK].width)
        {
            motion=ID_DISTER_OK;
        }
        else
        {
            motion=ID_DISTER_NONE;
        }
    }
    else
    {
        motion=ID_DISTER_NONE;
    }
    panelBottom->Refresh();
}

void DistDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_DISTER_NONE;
    panelBottom->Refresh();
}

void DistDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_DISTER_OK)
    {
        if(disterName->GetValue().IsEmpty())
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("设备地址不能为空！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                disterName->SetFocus();
            }
            return;
        }
        else
        {
            EndModal(wxID_OK);
        }
    }
    else if(motion==ID_DISTER_QUIT)
    {
        Destroy();
    }
    //panelBottom->Refresh();
}

void DistDlg::OnPaintMain(wxPaintEvent& event)
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
        memDC.SetPen(wxPen(wxColor(239,239,239)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=85;
        y1=35;
        w1=100;
        h1=30;
        memDC.DrawLabel(_("设备编号"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        disterName->SetSize(x1+10,y1-11,w1,-1);
        y1=y1+h1;
        memDC.DrawLabel(_("圆心角(°)"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        disterAngle->SetSize(x1+10,y1-11,w1,-1);
        y1=y1+h1;
        memDC.DrawLabel(_("初始值(m)"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        disterText->SetSize(x1+10,y1-11,w1,-1);
        y1=y1+h1-3;
        memDC.DrawLabel(_("是否选用?"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        y1=y1-14;
        x1=x1+10;
        dsButton[ID_DISTER_SEL].x=x1;
        dsButton[ID_DISTER_SEL].y=y1;
        dsButton[ID_DISTER_SEL].width=w1;
        dsButton[ID_DISTER_SEL].height=23;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(Selected==0)
        {
            if(motion==ID_DISTER_SEL)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-7,14,14);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-7,14,14),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("选用"),wxRect(x1+14+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-7,14,14);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1,y1+h1/2-7,14,14),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("选用"),wxRect(x1+14+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion==ID_DISTER_SEL)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-7,14,14);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("选用"),wxRect(x1+14+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-7,14,14);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("选用"),wxRect(x1+14+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(0,10,w,10);
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DistDlg::OnMotionMain(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>dsButton[ID_DISTER_SEL].y && y<dsButton[ID_DISTER_SEL].y+dsButton[ID_DISTER_SEL].height)
    {
        if(x>dsButton[ID_DISTER_SEL].x && x<dsButton[ID_DISTER_SEL].x+dsButton[ID_DISTER_SEL].width)
        {
            motion=ID_DISTER_SEL;
        }
        else
        {
            motion=ID_DISTER_NONE;
        }
    }
    else
    {
        motion=ID_DISTER_NONE;
    }
    panelMain->Refresh();
}

void DistDlg::OnLeaveMain(wxMouseEvent& event)
{
    motion=ID_DISTER_NONE;
    panelMain->Refresh();
}

void DistDlg::OnClickMain(wxMouseEvent& event)
{
    if(motion==ID_DISTER_SEL)
    {
        if(Selected==0) Selected=1;
        else Selected=0;
    }
    panelMain->Refresh();
}
