///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MypointDlg.h"
#include "mtg_t_cliApp.h"
#include "ConfirmDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MypointDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MypointDlg)
#include <wx/font.h>
#include <stdio.h>
#include "wx/filefn.h"
#include <wx/dir.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MypointDlg)

//*)

MypointDlg::MypointDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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

    ptName = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    ptx = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    pty = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    ptz = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MypointDlg::OnPaintMain,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MypointDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MypointDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MypointDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MypointDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    motion=ID_PT_NONE;
}

MypointDlg::~MypointDlg()
{

}

void MypointDlg::OnPaintBottom(wxPaintEvent& event)
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
        ptButton[ID_PT_QUIT].x=x1;
        ptButton[ID_PT_QUIT].y=y1;
        ptButton[ID_PT_QUIT].width=w1;
        ptButton[ID_PT_QUIT].height=h1;
        if(motion==ID_PT_QUIT)
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
        ptButton[ID_PT_OK].x=x1;
        ptButton[ID_PT_OK].y=y1;
        ptButton[ID_PT_OK].width=w1;
        ptButton[ID_PT_OK].height=h1;
        if(motion==ID_PT_OK)
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

void MypointDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>ptButton[ID_PT_QUIT].y && y<ptButton[ID_PT_QUIT].y+ptButton[ID_PT_QUIT].height)
    {
        if(x>ptButton[ID_PT_QUIT].x && x<ptButton[ID_PT_QUIT].x+ptButton[ID_PT_QUIT].width)
        {
            motion=ID_PT_QUIT;
        }
        else if(x>ptButton[ID_PT_OK].x && x<ptButton[ID_PT_OK].x+ptButton[ID_PT_OK].width)
        {
            motion=ID_PT_OK;
        }
        else
        {
            motion=ID_PT_NONE;
        }
    }
    else
    {
        motion=ID_PT_NONE;
    }
    panelBottom->Refresh();
}

void MypointDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_PT_NONE;
    panelBottom->Refresh();
}

void MypointDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_PT_OK)
    {
        if(ptName->GetValue().IsEmpty())
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("吊篮名称不能为空！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                ptName->SetFocus();
            }
            return;
        }
        else
        {
            EndModal(wxID_OK);
        }
    }
    else if(motion==ID_PT_QUIT)
    {
        Destroy();
    }
    //panelBottom->Refresh();
}

void MypointDlg::OnPaintMain(wxPaintEvent& event)
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
        y1=30;
        w1=100;
        h1=30;
        memDC.DrawLabel(_("点名"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        ptName->SetSize(x1+10,y1-11,w1,-1);
        y1=y1+h1;
        memDC.DrawLabel(_("北坐标( X )"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        ptx->SetSize(x1+10,y1-11,w1,-1);
        y1=y1+h1;
        memDC.DrawLabel(_("东坐标( Y )"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        pty->SetSize(x1+10,y1-11,w1,-1);
        y1=y1+h1;
        memDC.DrawLabel(_("高程( Z )"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        ptz->SetSize(x1+10,y1-11,w1,-1);

        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(0,10,w,10);
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

