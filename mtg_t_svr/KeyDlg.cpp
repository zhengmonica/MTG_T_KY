///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "KeyDlg.h"
#include "mtg_t_svrApp.h"
#include "ConfirmDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(KeyDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(KeyDlg)
#include <wx/font.h>
#include <stdio.h>
#include "wx/filefn.h"
#include <wx/dir.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(KeyDlg)


const long KeyDlg::ID_PANEL1 = wxNewId();                  //标题
//*)

KeyDlg::KeyDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
    keyPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    keyPanel->SetBackgroundColour(wxColor(239,239,239));
    x2=15;
    y2=15;
    w2=220;
    bskStaticText1 = new wxStaticText(keyPanel, wxID_ANY, _("区域名称"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    keyName = new wxMyTextCtrl(keyPanel, wxID_ANY, wxEmptyString, wxPoint(x2,y2+20), wxSize(w2-5,25), 0);
    x2=x2+w2+1;
    w2=(w1-x2-15)/2;
    bskStaticText2 = new wxStaticText(keyPanel, wxID_ANY, _("起点里程"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    mile1 = new wxMyTextCtrl(keyPanel, wxID_ANY, wxEmptyString, wxPoint(x2,y2+20), wxSize(w2-4,25), 0);
    x2=x2+w2+1;
    bskStaticText3 = new wxStaticText(keyPanel, wxID_ANY, _("终点里程"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    mile2 = new wxMyTextCtrl(keyPanel, wxID_ANY, wxEmptyString, wxPoint(x2,y2+20), wxSize(w2-4,25), 0);

    x2=15;
    y2=70;
    w2=w-x2*2;
    h2=h1-85;
    figPanel=new wxPanel(keyPanel, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    figPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x2=x2+w2+10;
    w2=75;

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&KeyDlg::OnPaintBackground,0,this);

    figPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&KeyDlg::OnPaintKey,0,this);
    figPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&KeyDlg::OnMotionKey,0,this);
    figPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&KeyDlg::OnLeaveKey,0,this);
    figPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&KeyDlg::OnClickKey,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&KeyDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&KeyDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&KeyDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&KeyDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    motion=ID_KEY_NONE;
}

KeyDlg::~KeyDlg()
{

}

void KeyDlg::OnPaintKey(wxPaintEvent& event)
{
    wxPaintDC dc(figPanel);
    int w,h;
    figPanel->GetClientSize(&w,&h);
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

        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(25,h/2,w-25,h/2);

        wxPoint bounds[5];
        bounds[0].x=w/3;
        bounds[0].y=h/2+30;
        bounds[1].x=w*3/5;
        bounds[1].y=h/2+20;
        bounds[2].x=w*2/3;
        bounds[2].y=h/2+70;
        bounds[3].x=w*2/5;
        bounds[3].y=h/2+60;
        bounds[4].x=bounds[0].x;
        bounds[4].y=bounds[0].y;
        memDC.DrawLines(5,bounds);

        memDC.DrawLine(bounds[0].x,h/2,bounds[0].x,bounds[0].y-5);
        memDC.DrawLine(bounds[2].x,h/2,bounds[2].x,bounds[2].y-5);

        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.DrawCircle(bounds[0],7);
        memDC.DrawCircle(bounds[2],7);

        memDC.DrawLabel(_("起点里程"),wxRect(bounds[0].x,h/2-5,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
        memDC.DrawLabel(_("终点里程"),wxRect(bounds[2].x,h/2-5,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);

        memDC.SetPen(wxPen(wxColor(122,122,122)));
        memDC.DrawLine(w/3,h/4-20,w*2/3,h/4-20);
        memDC.DrawLine(w*2/3-7,h/4-27,w*2/3,h/4-20);
        memDC.DrawLine(w*2/3-7,h/4-13,w*2/3,h/4-20);
        memDC.DrawLabel(_("掘进方向"),wxRect(w*2/3+10,h/4-20,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}


void KeyDlg::OnMotionKey(wxMouseEvent& event)
{

}

void KeyDlg::OnLeaveKey(wxMouseEvent& event)
{

}

void KeyDlg::OnClickKey(wxMouseEvent& event)
{

}

void KeyDlg::OnPaintBottom(wxPaintEvent& event)
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
        button[ID_KEY_QUIT].x=x1;
        button[ID_KEY_QUIT].y=y1;
        button[ID_KEY_QUIT].width=w1;
        button[ID_KEY_QUIT].height=h1;
        if(motion==ID_KEY_QUIT)
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
        button[ID_KEY_OK].x=x1;
        button[ID_KEY_OK].y=y1;
        button[ID_KEY_OK].width=w1;
        button[ID_KEY_OK].height=h1;
        if(motion==ID_KEY_OK)
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

void KeyDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_KEY_QUIT].y && y<button[ID_KEY_QUIT].y+button[ID_KEY_QUIT].height)
    {
        if(x>button[ID_KEY_QUIT].x && x<button[ID_KEY_QUIT].x+button[ID_KEY_QUIT].width)
        {
            motion=ID_KEY_QUIT;
        }
        else if(x>button[ID_KEY_OK].x && x<button[ID_KEY_OK].x+button[ID_KEY_OK].width)
        {
            motion=ID_KEY_OK;
        }
        else
        {
            motion=ID_KEY_NONE;
        }
    }
    else
    {
        motion=ID_KEY_NONE;
    }
    panelBottom->Refresh();
}

void KeyDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_KEY_NONE;
    panelBottom->Refresh();
}

void KeyDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_KEY_OK)
    {
        double val;
        if(keyName->GetValue().IsEmpty())
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("区域名称不能为空！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                keyName->SetFocus();
            }
            return;
        }
        if(mile1->GetValue().IsEmpty())
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("起点里程不能为空！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                mile1->SetFocus();
            }
            return;
        }

        if(!mile1->GetValue().ToDouble(&val))
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("起点里程输入非法错误，请检查！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                mile1->SetFocus();
            }
            return;
        }
        else
        {
            if(a2z==1)
            {
                if(val<p1-tip || val>p2+tip)
                {
                    ConfirmDlg dlg(this);
                    dlg.Center();
                    dlg.confirmMsg=_("起点里程未在本工程范围内，请检查");
                    dlg.type=1;
                    if(dlg.ShowModal()==wxID_OK)
                    {
                        mile2->SetFocus();
                    }
                    return;
                }
            }
            else
            {
                if(val<p2-tip || val>p1+tip)
                {
                    ConfirmDlg dlg(this);
                    dlg.Center();
                    dlg.confirmMsg=_("起点里程未在本工程范围内，请检查");
                    dlg.type=1;
                    if(dlg.ShowModal()==wxID_OK)
                    {
                        mile1->SetFocus();
                    }
                    return;
                }
            }
        }
        if(mile2->GetValue().IsEmpty())
        {
            mile2->SetValue(wxString::Format(_("%.3f"),val));
        }
        else if(!mile2->GetValue().ToDouble(&val))
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("终点里程输入错误，请检查！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                mile2->SetFocus();
            }
            return;
        }

        EndModal(wxID_OK);
    }
    else if(motion==ID_KEY_QUIT)
    {
        Destroy();
    }
    //panelBottom->Refresh();
}

void KeyDlg::OnPaintBackground(wxPaintEvent& event)
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

