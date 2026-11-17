///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "EditBskDlg.h"
#include "mtg_tApp.h"
#include "confirmdlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(EditBskDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(EditBskDlg)
#include <wx/font.h>
#include <stdio.h>
#include "wx/filefn.h"
#include <wx/dir.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(EditBskDlg)


const long EditBskDlg::ID_PANEL1 = wxNewId();                  //标题
//*)

EditBskDlg::EditBskDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);
	panelTitle = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));

    panelTitle->m_maximize_box=0;
    panelTitle->m_minimize_box=0;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("吊篮坐标");
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,31), wxSize(w,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w;
    h1=h-88;
    bskPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    bskPanel->SetBackgroundColour(wxColor(239,239,239));
    x2=15;
    y2=15;
    w2=(w-x2*2)/4;
    bskStaticText1 = new wxStaticText(bskPanel, wxID_ANY, _("点名"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    bskName = new wxMyTextCtrl(bskPanel, wxID_ANY, wxEmptyString, wxPoint(x2,y2+20), wxSize(w2-5,25), 0);
    bskStaticText2 = new wxStaticText(bskPanel, wxID_ANY, _("北坐标(X)"), wxPoint(x2+w2+1,y2), wxDefaultSize, 0, _("wxID_ANY"));
    bskX = new wxMyTextCtrl(bskPanel, wxID_ANY, wxEmptyString, wxPoint(x2+w2+1,y2+20), wxSize(w2-4,25), 0);
    bskStaticText3 = new wxStaticText(bskPanel, wxID_ANY, _("东坐标(Y)"), wxPoint(x2+w2*2+3,y2), wxDefaultSize, 0, _("wxID_ANY"));
    bskY = new wxMyTextCtrl(bskPanel, wxID_ANY, wxEmptyString, wxPoint(x2+w2*2+3,y2+20), wxSize(w2-4,25), 0);
    bskStaticText4 = new wxStaticText(bskPanel, wxID_ANY, _("高程(Z)"), wxPoint(x2+w2*3+5,y2), wxDefaultSize, 0, _("wxID_ANY"));
    bskZ = new wxMyTextCtrl(bskPanel, wxID_ANY, wxEmptyString, wxPoint(x2+w2*3+5,y2+20), wxSize(w2-4,25), 0);

    x2=15;
    y2=70;
    w2=w-x2*2;
    h2=h1-85;
    figPanel=new wxPanel(bskPanel, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    figPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x2=x2+w2+10;
    w2=75;

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&EditBskDlg::OnPaintBackground,0,this);

    figPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&EditBskDlg::OnPaintBasket,0,this);
    figPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&EditBskDlg::OnMotionBasket,0,this);
    figPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&EditBskDlg::OnLeaveBasket,0,this);
    figPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&EditBskDlg::OnClickBasket,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&EditBskDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&EditBskDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&EditBskDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&EditBskDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    motion=ID_EDITB_NONE;
}

EditBskDlg::~EditBskDlg()
{

}

void EditBskDlg::OnPaintBasket(wxPaintEvent& event)
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

        int x1=0;
        int y1=0;
        int w1=120;
        int h1=25;


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}


void EditBskDlg::OnMotionBasket(wxMouseEvent& event)
{

}

void EditBskDlg::OnLeaveBasket(wxMouseEvent& event)
{

}

void EditBskDlg::OnClickBasket(wxMouseEvent& event)
{

}

void EditBskDlg::OnPaintBottom(wxPaintEvent& event)
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
        bskButton[ID_EDITB_QUIT].x=x1;
        bskButton[ID_EDITB_QUIT].y=y1;
        bskButton[ID_EDITB_QUIT].width=w1;
        bskButton[ID_EDITB_QUIT].height=h1;
        if(motion==ID_EDITB_QUIT)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("取消"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=w/2-w1-5;
        bskButton[ID_EDITB_OK].x=x1;
        bskButton[ID_EDITB_OK].y=y1;
        bskButton[ID_EDITB_OK].width=w1;
        bskButton[ID_EDITB_OK].height=h1;
        if(motion==ID_EDITB_OK)
        {
            memDC.SetPen(btnPen[1]);
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(btnPen[0]);
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("确定"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void EditBskDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>bskButton[ID_EDITB_QUIT].y && y<bskButton[ID_EDITB_QUIT].y+bskButton[ID_EDITB_QUIT].height)
    {
        if(x>bskButton[ID_EDITB_QUIT].x && x<bskButton[ID_EDITB_QUIT].x+bskButton[ID_EDITB_QUIT].width)
        {
            motion=ID_EDITB_QUIT;
        }
        else if(x>bskButton[ID_EDITB_OK].x && x<bskButton[ID_EDITB_OK].x+bskButton[ID_EDITB_OK].width)
        {
            motion=ID_EDITB_OK;
        }
        else
        {
            motion=ID_EDITB_NONE;
        }
    }
    else
    {
        motion=ID_EDITB_NONE;
    }
    panelBottom->Refresh();
}

void EditBskDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_EDITB_NONE;
    panelBottom->Refresh();
}

void EditBskDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_EDITB_OK)
    {
        if(bskName->GetValue().IsEmpty())
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("吊篮名称不能为空！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                bskName->SetFocus();
            }
            return;
        }
        else
        {
            EndModal(wxID_OK);
        }
    }
    else if(motion==ID_EDITB_QUIT)
    {
        Destroy();
    }
    //panelBottom->Refresh();
}

void EditBskDlg::OnPaintBackground(wxPaintEvent& event)
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

