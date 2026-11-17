///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "StationDlg.h"
#include "mtg_tApp.h"
#include "confirmdlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(StationDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(StationDlg)
#include <wx/font.h>
#include <stdio.h>
#include "wx/filefn.h"
#include <wx/dir.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(StationDlg)


const long StationDlg::ID_PANEL1 = wxNewId();                  //标题
//*)

StationDlg::StationDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
    //panelTitle->Name=_("设站报告");
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,31), wxSize(w,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w;
    h1=h-88;
    stationPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    stationPanel->SetBackgroundColour(wxColor(239,239,239));

    x2=15;
    y2=15;
    w2=w-x2*2;
    h2=h1-30;
    stnReportPanel=new wxPanel(stationPanel, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    stnReportPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&StationDlg::OnPaintBackground,0,this);

    stnReportPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&StationDlg::OnPaintReport,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&StationDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&StationDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&StationDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&StationDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    motion=ID_STATION_NONE;
    sel=-1;
}

StationDlg::~StationDlg()
{

}

void StationDlg::OnPaintReport(wxPaintEvent& event)
{
    panelTitle->Name=_("设站 ")+wxDateTime(cli->stns[sel].t).Format(_("%Y-%m-%d %H:%M:%S"));
    panelTitle->Refresh();
    wxPaintDC dc(stnReportPanel);
    int w,h;
    stnReportPanel->GetClientSize(&w,&h);
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

        if(sel<0)
        {
            dc.Blit(0,0,w,h,&memDC,0,0);
            return;
        }

        int x1,y1,w1,h1;
        x1=15;
        y1=5;
        h1=25;
        w1=(w-30)/5;


        wxString stnStr;
        stnStr=_("测站点信息");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1,y1+h1,w-x1,y1+h1);
        y1=y1+h1+7;
        stnStr=wxString(cli->stns[sel].stat,wxConvUTF8);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1+30;
        stnStr=_("X ")+wxString::Format(_("%.4f"),cli->stns[sel].statx);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=_("Y ")+wxString::Format(_("%.4f"),cli->stns[sel].staty);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=_("Z ")+wxString::Format(_("%.4f"),cli->stns[sel].statz);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=_("仪高 ")+wxString::Format(_("%.4f"),cli->stns[sel].stath);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=15;
        y1=y1+h1+7;
        stnStr=_("后视点信息");
        memDC.DrawLine(x1,y1+h1,w-x1,y1+h1);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1+7;
        stnStr=wxString(cli->stns[sel].back,wxConvUTF8);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1+30;
        stnStr=_("X ")+wxString::Format(_("%.4f"),cli->stns[sel].backx);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=_("Y ")+wxString::Format(_("%.4f"),cli->stns[sel].backy);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=_("Z ")+wxString::Format(_("%.4f"),cli->stns[sel].backz);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=_("仪高 ")+wxString::Format(_("%.4f"),cli->stns[sel].backh);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);


        double L0,L;
        double H0,H;

        double dx=cli->stns[sel].backx-cli->stns[sel].statx;
        double dy=cli->stns[sel].backy-cli->stns[sel].staty;
        double dv=cli->stns[sel].backz+cli->stns[sel].backh-cli->stns[sel].statz-cli->stns[sel].stath;
        double dh=sqrt(dx*dx+dy*dy);
        double dh1=cli->stns[sel].backz1*cos(PI/2-cli->stns[sel].backy1);
        double dv1=cli->stns[sel].backz1*sin(PI/2-cli->stns[sel].backy1);

        x1=15;
        y1=y1+h1+7;
        stnStr = _("平距及高差");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1,y1+h1,w-x1,y1+h1);
        y1=y1+h1+7;
        stnStr = _("平距");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1+30;
        stnStr=_("理论 ")+wxString::Format(_("%.4f"),dh)+_(" m");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1+40;
        stnStr=_("实测 ")+wxString::Format(_("%.4f"),dh1)+_(" m");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1+40;
        stnStr = _("较差 ")+wxString::Format(_("%.1f"),(dh1-dh)*1000.0)+_(" mm");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=15;
        y1=y1+h1;
        stnStr = _("高差");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1+30;
        stnStr = _("理论 ")+wxString::Format(_("%.4f"),dv)+_(" m");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1+40;
        stnStr = _("实测 ")+wxString::Format(_("%.4f"),dv)+_(" m");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1+40;
        stnStr = _("较差 ")+wxString::Format(_("%.1f"),(dv1-dv)*1000.0)+_(" mm");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=15;
        y1=y1+h1+7;
        stnStr=_("设站前后盾构姿态");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(x1,y1+h1,w-x1,y1+h1);
        y1=y1+h1+15;
        w1=(w-30)/8;
        stnStr=_("水平偏差");
        x1+=w1;
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1*2;
        stnStr=_("垂直偏差");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1*2,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1*2;
        stnStr=_("转动角");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1*2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        stnStr=_("俯仰角");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1*2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        stnStr=_("方位角");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1*2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=15+w1;
        y1+=h1;
        stnStr=_("切口");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawLine(x1+10,y1,x1+w1*2-10,y1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        x1+=w1;
        stnStr=_("盾尾");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=_("切口");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawLine(x1+10,y1,x1+w1*2-10,y1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        x1+=w1;
        stnStr=_("盾尾");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=15;
        y1=y1+h1+7;
        stnStr=_("设站前");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].headh[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].tailh[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].headv[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].tailv[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].roll[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].pitch[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].azi[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=15;
        y1+=h1;
        stnStr=_("设站后");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].headh[1]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].tailh[1]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].headv[1]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].tailv[1]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].roll[1]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].pitch[1]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].azi[1]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=15;
        y1+=h1;
        stnStr=_("较  差");
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].headh[1]*1000.0-cli->stns[sel].headh[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].tailh[1]*1000.0-cli->stns[sel].tailh[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].headv[1]*1000.0-cli->stns[sel].headv[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].tailv[1]*1000.0-cli->stns[sel].tailv[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].roll[1]*1000.0-cli->stns[sel].roll[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].pitch[1]*1000.0-cli->stns[sel].pitch[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        stnStr=wxString::Format(_("%.1f"),cli->stns[sel].azi[1]*1000.0-cli->stns[sel].azi[0]*1000.0);
        memDC.DrawLabel(stnStr,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void StationDlg::OnPaintBottom(wxPaintEvent& event)
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
        x1=w/2-w1/2;
        myButton[ID_STATION_QUIT].x=x1;
        myButton[ID_STATION_QUIT].y=y1;
        myButton[ID_STATION_QUIT].width=w1;
        myButton[ID_STATION_QUIT].height=h1;
        if(motion==ID_STATION_QUIT)
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
        memDC.DrawLabel(_("退出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void StationDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>myButton[ID_STATION_QUIT].y && y<myButton[ID_STATION_QUIT].y+myButton[ID_STATION_QUIT].height)
    {
        if(x>myButton[ID_STATION_QUIT].x && x<myButton[ID_STATION_QUIT].x+myButton[ID_STATION_QUIT].width)
        {
            motion=ID_STATION_QUIT;
        }
        else
        {
            motion=ID_STATION_NONE;
        }
    }
    else
    {
        motion=ID_STATION_NONE;
    }
    panelBottom->Refresh();
}

void StationDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_STATION_NONE;
    panelBottom->Refresh();
}

void StationDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_STATION_QUIT)
    {
        Destroy();
    }
    //panelBottom->Refresh();
}

void StationDlg::OnPaintBackground(wxPaintEvent& event)
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

