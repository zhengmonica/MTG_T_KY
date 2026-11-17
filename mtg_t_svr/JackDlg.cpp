///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "JackDlg.h"
#include "mtg_t_svrApp.h"
#include "MypointDlg.h"
#include "MyfileDlg.h"
//#include "confirmdlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include "time.h"
#include "laserimg.h"

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(JackDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(JackDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(JackDlg)
const long JackDlg::ID_PANEL2 = wxNewId();                  //按钮
//*)

JackDlg::JackDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int dh=20;
	int x2,y2,w2,h2;
	this->GetClientSize(&w,&h);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,31), wxSize(w,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPage = new wxPanel(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x1=7;
    y1=59;
    w1=w-x1*2;
    h1=h-150;
    panelHorizon = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelVertical = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelVertical->Show(false);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelHorizon->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelVertical->SetBackgroundStyle(wxBG_STYLE_CUSTOM);


    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&JackDlg::OnPaintMain,0,this);
    panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&JackDlg::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&JackDlg::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&JackDlg::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&JackDlg::OnClickPage,0,this);

    panelHorizon->Connect(wxEVT_PAINT,(wxObjectEventFunction)&JackDlg::OnPaintHorizon,0,this);
    panelVertical->Connect(wxEVT_PAINT,(wxObjectEventFunction)&JackDlg::OnPaintVertical,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&JackDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&JackDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&JackDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&JackDlg::OnClickBottom,0,this);
    //*)

    Connect(wxEVT_TIMER,(wxObjectEventFunction)&JackDlg::OnTimer);
    timerStat.SetOwner(this);
    timerStat.Start(100,false);

    this->SetBackgroundColour(wxColor(245,248,250));

    motion=ID_JACK_NONE;
    page=ID_JACK_PAGE_HORIZON;
    mtg_jack_gesture(mtg);
}

JackDlg::~JackDlg()
{

}

void JackDlg::OnPaintHorizon(wxPaintEvent& event)
{
    wxPaintDC dc(panelHorizon);
    int w,h;
    panelHorizon->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(33,40,48)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(219,229,239)));
        memDC.DrawRectangle(1,1,w-2,h-2);
        int x1,y1,w1,h1;
        w1=w/3;
        h1=h-60;
        x1=w/2-w1/2;
        y1=30;

        //memDC.DrawRectangle(x1,y1,w1,h1);

        double hs[2],vs[2];
        if(mtg->tbm.type==0)
        {
            double ilen=mtg->ilen;
            double len;

            len=mtg->tbm.L[3];
        }
        else if(mtg->tbm.type==3)
        {
            double len[3];
            double ival;

            if(mtg->tarset.pos==1)
            {
                len[0]=mtg->tbm.L[0];
                len[1]=mtg->ilen;
                len[2]=mtg->tbm.L[2];
                ival=mtg->tbm.D[0];
                for(int i=1;i<5;i++)
                {
                    if(ival<mtg->tbm.D[i]) ival=mtg->tbm.D[i];
                }
                vs[0]=(len[0]+len[1]+len[2])/h1;
                hs[0]=ival/w1;

                hs[1]=hs[0]*0.5;
                vs[1]=vs[0]*0.2;

                double ix[10],iy[10];
                double iangle;
                double iw,ih;
                double dx,dy,dz;
                iw=w1/2;
                ih=len[1]/vs[0];
                ix[0]=x1+w1/2+mtg->m1.headh/hs[1];
                iy[0]=y1+h1/2-ih/2;
                ix[1]=x1+w1/2+mtg->m1.tailh/hs[1];
                iy[1]=y1+h1/2+ih/2;
                iangle=atan2(iy[0]-iy[1],ix[0]-ix[1]);
                if(iangle<0) iangle=iangle+PI*2.0;

                ix[6]=ix[0]+iw*cos(iangle-PI/2);
                iy[6]=iy[0]+iw*sin(iangle-PI/2);
                ix[7]=ix[0]+iw*cos(iangle+PI/2);
                iy[7]=iy[0]+iw*sin(iangle+PI/2);

                ix[8]=ix[1]+iw*cos(iangle+PI/2);
                iy[8]=iy[1]+iw*sin(iangle+PI/2);
                ix[9]=ix[1]+iw*cos(iangle-PI/2);
                iy[9]=iy[1]+iw*sin(iangle-PI/2);

                memDC.SetPen(wxPen(wxColor(255,0,0)));
                memDC.DrawLine(ix[6],iy[6],ix[7],iy[7]);
                memDC.DrawLine(ix[7],iy[7],ix[8],iy[8]);
                memDC.DrawLine(ix[8],iy[8],ix[9],iy[9]);
                memDC.DrawLine(ix[9],iy[9],ix[6],iy[6]);
                memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT_DASH));
                memDC.DrawLine(ix[0],iy[0],ix[1],iy[1]);

                dx=mtg->m1.tail1[0]-mtg->m1.head[0];
                dy=mtg->m1.tail1[1]-mtg->m1.head[1];
                dz=mtg->m1.tail1[2]-mtg->m1.head[2];
                ival=dx*dx+dy*dy+dz*dz;
                ival=sqrt(ival);
                ival=ival/vs[1];

                ix[3]=ix[0]+ival*cos(iangle);
                iy[3]=iy[0]+ival*sin(iangle);

                ival=len[0]/vs[0];
                ix[2]=x1+w1/2+mtg->m1.headh1/hs[1];
                iy[2]=iy[3]-ival;

                iangle=atan2(iy[2]-iy[3],ix[2]-ix[3]);
                if(iangle<0) iangle=iangle+PI*2.0;

                ix[6]=ix[2]+iw*cos(iangle-PI/2);
                iy[6]=iy[2]+iw*sin(iangle-PI/2);
                ix[7]=ix[2]+iw*cos(iangle+PI/2);
                iy[7]=iy[2]+iw*sin(iangle+PI/2);

                ix[8]=ix[3]+iw*cos(iangle+PI/2);
                iy[8]=iy[3]+iw*sin(iangle+PI/2);
                ix[9]=ix[3]+iw*cos(iangle-PI/2);
                iy[9]=iy[3]+iw*sin(iangle-PI/2);

                memDC.SetPen(wxPen(wxColor(255,0,0)));
                memDC.DrawLine(ix[6],iy[6],ix[7],iy[7]);
                memDC.DrawLine(ix[7],iy[7],ix[8],iy[8]);
                memDC.DrawLine(ix[8],iy[8],ix[9],iy[9]);
                memDC.DrawLine(ix[9],iy[9],ix[6],iy[6]);
                memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT_DASH));
                memDC.DrawLine(ix[2],iy[2],ix[3],iy[3]);

                dx=mtg->m1.head2[0]-mtg->m1.tail[0];
                dy=mtg->m1.head2[1]-mtg->m1.tail[1];
                dz=mtg->m1.head2[2]-mtg->m1.tail[2];
                ival=dx*dx+dy*dy+dz*dz;
                ival=sqrt(ival);
                ival=ival/vs[1];
                iangle=atan2(iy[1]-iy[0],ix[1]-ix[0]);
                if(iangle<0) iangle=iangle+PI*2.0;
                ix[4]=ix[1]+ival*cos(iangle);
                iy[4]=iy[1]+ival*sin(iangle);

                ival=len[2]/vs[0];
                ix[5]=x1+w1/2+mtg->m1.tailh2/hs[1];
                iy[5]=iy[4]+ival;
                iangle=atan2(iy[4]-iy[5],ix[4]-ix[5]);
                if(iangle<0) iangle=iangle+PI*2.0;

                ix[6]=ix[4]+iw*cos(iangle-PI/2);
                iy[6]=iy[4]+iw*sin(iangle-PI/2);
                ix[7]=ix[4]+iw*cos(iangle+PI/2);
                iy[7]=iy[4]+iw*sin(iangle+PI/2);

                ix[8]=ix[5]+iw*cos(iangle+PI/2);
                iy[8]=iy[5]+iw*sin(iangle+PI/2);
                ix[9]=ix[5]+iw*cos(iangle-PI/2);
                iy[9]=iy[5]+iw*sin(iangle-PI/2);

                memDC.SetPen(wxPen(wxColor(255,0,0)));
                memDC.DrawLine(ix[6],iy[6],ix[7],iy[7]);
                memDC.DrawLine(ix[7],iy[7],ix[8],iy[8]);
                memDC.DrawLine(ix[8],iy[8],ix[9],iy[9]);
                memDC.DrawLine(ix[9],iy[9],ix[6],iy[6]);
                memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT_DASH));
                memDC.DrawLine(ix[4],iy[4],ix[5],iy[5]);

                memDC.SetPen(wxPen(wxColor(0,255,0),1,wxDOT_DASH));
                memDC.DrawLine(w/2,2,w/2,h-2);

            }
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}


void JackDlg::OnPaintVertical(wxPaintEvent& event)
{
    wxPaintDC dc(panelVertical);
    int w,h;

    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(33,40,48)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(219,229,239)));
        memDC.DrawRectangle(1,1,w-2,h-2);
        int x1,y1,w1,h1;


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void JackDlg::OnPaintBottom(wxPaintEvent& event)
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
        w1=65;
        h1=26;
        x1=w-w1-14;
        y1=9;
        jackButton[ID_JACK_QUIT].x=x1;
        jackButton[ID_JACK_QUIT].y=y1;
        jackButton[ID_JACK_QUIT].width=w1;
        jackButton[ID_JACK_QUIT].height=h1;
        if(motion==ID_JACK_QUIT)
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
        memDC.DrawLabel(_("退出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void JackDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>jackButton[ID_JACK_QUIT].y && y<jackButton[ID_JACK_QUIT].y+jackButton[ID_JACK_QUIT].height)
    {
        if(x>jackButton[ID_JACK_QUIT].x && x<jackButton[ID_JACK_QUIT].x+jackButton[ID_JACK_QUIT].width)
        {
            motion=ID_JACK_QUIT;
        }
        else
        {
            motion=ID_JACK_NONE;
        }
    }
    else
    {
        motion=ID_JACK_NONE;
    }
    panelBottom->Refresh();
}

void JackDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_JACK_NONE;
    panelBottom->Refresh();
}

void JackDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_JACK_QUIT)
    {
        Destroy();
    }
    ///panelBottom->Refresh();
}

void JackDlg::OnPaintMain(wxPaintEvent& event)
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


        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(-1,38,w+2,10);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,48,w,48);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(-1,49,w+2,h-49);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void JackDlg::OnPaintPage(wxPaintEvent& event)
{
    wxPaintDC dc(panelPage);
    int w,h;
    panelPage->GetSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        int r,g,b;
        x1=0;
        y1=0;
        w1=95;
        h1=h;
        jackButton[ID_JACK_PAGE_HORIZON].x=x1;
        jackButton[ID_JACK_PAGE_HORIZON].y=y1;
        jackButton[ID_JACK_PAGE_HORIZON].width=w1;
        jackButton[ID_JACK_PAGE_HORIZON].height=h1;

        if(page==ID_JACK_PAGE_HORIZON || motion==ID_JACK_PAGE_HORIZON)
        {
            r=200;
            g=225;
            b=250;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                //y1++;
            }

            if(page!=ID_JACK_PAGE_HORIZON)
            {
                memDC.SetPen(wxPen(wxColor(172,168,153)));
                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
            }
        }
        else
        {
            r=236;
            g=236;
            b=236;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                r--;
                g--;
                b--;
            }
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
        }
        memDC.DrawLabel(_("平面"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);

        x1=x1+w1;
        jackButton[ID_JACK_PAGE_VERTICAL].x=x1;
        jackButton[ID_JACK_PAGE_VERTICAL].y=y1;
        jackButton[ID_JACK_PAGE_VERTICAL].width=w1;
        jackButton[ID_JACK_PAGE_VERTICAL].height=h1;
        if(page==ID_JACK_PAGE_VERTICAL || motion==ID_JACK_PAGE_VERTICAL)
        {
            r=200;
            g=225;
            b=250;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                //y1++;
            }
            if(page!=ID_JACK_PAGE_VERTICAL)
            {
                memDC.SetPen(wxPen(wxColor(172,168,153)));
                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
            }
        }
        else
        {
            r=236;
            g=236;
            b=236;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                r--;
                g--;
                b--;
            }
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
        }
        memDC.DrawLabel(_("垂直"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        r=236;
        g=236;
        b=236;
        x1=x1+w1;
        for(int j=0;j<h1;j++)
        {
            memDC.SetPen(wxPen(wxColor(r,g,b)));
            memDC.DrawLine(x1,y1+j,w,y1+j);
            r--;
            g--;
            b--;
        }
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,w,y1);
        memDC.DrawLine(x1,y1+h1-1,w,y1+h1-1);
        memDC.DrawLine(x1,y1,x1,y1+h1);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void JackDlg::OnMotionPage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>jackButton[ID_JACK_PAGE_HORIZON].y && y<jackButton[ID_JACK_PAGE_HORIZON].y+jackButton[ID_JACK_PAGE_HORIZON].height)
    {
        if(x>jackButton[ID_JACK_PAGE_HORIZON].x && x<jackButton[ID_JACK_PAGE_HORIZON].x+jackButton[ID_JACK_PAGE_HORIZON].width)
        {
            motion=ID_JACK_PAGE_HORIZON;
        }
        else if(x>jackButton[ID_JACK_PAGE_VERTICAL].x && x<jackButton[ID_JACK_PAGE_VERTICAL].x+jackButton[ID_JACK_PAGE_VERTICAL].width)
        {
            motion=ID_JACK_PAGE_VERTICAL;
        }
        else
        {
            motion=ID_JACK_NONE;
        }
    }
    else
    {
        motion=ID_JACK_NONE;
    }
    panelPage->Refresh();
}

void JackDlg::OnLeavePage(wxMouseEvent& event)
{
    motion=ID_JACK_NONE;
    panelPage->Refresh();
}

void JackDlg::OnClickPage(wxMouseEvent& event)
{
    if(motion==ID_JACK_PAGE_HORIZON)
    {
        page=ID_JACK_PAGE_HORIZON;

        panelHorizon->Show(true);
        panelVertical->Show(false);
    }
    else if(motion==ID_JACK_PAGE_VERTICAL)
    {
        page=ID_JACK_PAGE_VERTICAL;
        panelVertical->Show(true);
        panelHorizon->Show(false);
    }
    ///panelBottom->Refresh();
}

void JackDlg::OnTimer(wxTimerEvent& event)
{
    static int tick=0;
    tick++;
    if(tick % 10==0)
    {

    }
    if(tick==1200) tick=0;
}
