///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BlockDlg.h"
#include "mtg_t_cliApp.h"
#include "ConfirmDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(BlockDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(BlockDlg)
#include <wx/font.h>
#include <stdio.h>
#include "wx/filefn.h"
#include <wx/dir.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(BlockDlg)


const long BlockDlg::ID_PANEL1 = wxNewId();                  //标题
//*)

BlockDlg::BlockDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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

    panelTitle->IsMaximinize=0;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("管块设置");
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,31), wxSize(w,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w;
    h1=h-88;
    blkPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    blkPanel->SetBackgroundColour(wxColor(239,239,239));
    x2=15;
    y2=10;
    w2=w1-x2*2;
    h2=25;
    blkStaticText1 = new wxStaticText(blkPanel, wxID_ANY, _("管块名称"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    blkName = new wxMyTextCtrl(blkPanel, wxID_ANY, wxEmptyString, wxPoint(x2,y2+20), wxSize(w2-5,h2), 0);
    y2=y2+50;
    blkStaticText2 = new wxStaticText(blkPanel, wxID_ANY, _("圆心角"), wxPoint(x2,y2), wxDefaultSize, 0, _("wxID_ANY"));
    Angle = new wxMyTextCtrl(blkPanel, wxID_ANY, wxEmptyString, wxPoint(x2,y2+20), wxSize(w2-4,25), 0);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&BlockDlg::OnPaintBackground,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&BlockDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&BlockDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&BlockDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&BlockDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    motion=ID_BLK_NONE;
}

BlockDlg::~BlockDlg()
{

}

void BlockDlg::OnPaintBottom(wxPaintEvent& event)
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
        button[ID_BLK_QUIT].x=x1;
        button[ID_BLK_QUIT].y=y1;
        button[ID_BLK_QUIT].width=w1;
        button[ID_BLK_QUIT].height=h1;
        if(motion==ID_BLK_QUIT)
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
        button[ID_BLK_OK].x=x1;
        button[ID_BLK_OK].y=y1;
        button[ID_BLK_OK].width=w1;
        button[ID_BLK_OK].height=h1;
        if(motion==ID_BLK_OK)
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

void BlockDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BLK_QUIT].y && y<button[ID_BLK_QUIT].y+button[ID_BLK_QUIT].height)
    {
        if(x>button[ID_BLK_QUIT].x && x<button[ID_BLK_QUIT].x+button[ID_BLK_QUIT].width)
        {
            motion=ID_BLK_QUIT;
        }
        else if(x>button[ID_BLK_OK].x && x<button[ID_BLK_OK].x+button[ID_BLK_OK].width)
        {
            motion=ID_BLK_OK;
        }
        else
        {
            motion=ID_BLK_NONE;
        }
    }
    else
    {
        motion=ID_BLK_NONE;
    }
    panelBottom->Refresh();
}

void BlockDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_BLK_NONE;
    panelBottom->Refresh();
}

void BlockDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_BLK_OK)
    {
        double val;
        if(blkName->GetValue().IsEmpty())
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("区域名称不能为空！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                blkName->SetFocus();
            }
            return;
        }
        if(Angle->GetValue().IsEmpty())
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("角度不能为空！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                Angle->SetFocus();
            }
            return;
        }

        if(!Angle->GetValue().ToDouble(&val))
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("角度输入错误，请检查！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                Angle->SetFocus();
            }
            return;
        }

        EndModal(wxID_OK);
    }
    else if(motion==ID_BLK_QUIT)
    {
        Destroy();
    }
    //panelBottom->Refresh();
}

void BlockDlg::OnPaintBackground(wxPaintEvent& event)
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

