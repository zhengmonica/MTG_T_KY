///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SegmentMonitorDlg.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"
#include "confirmdlg.h"
#include "SegDialog.h"
#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(SegmentMonitorDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(SegmentMonitorDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(SegmentMonitorDlg)


const long SegmentMonitorDlg::ID_PANEL1 = wxNewId();                  //标题
//*)

SegmentMonitorDlg::SegmentMonitorDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelTitle = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));

    panelTitle->m_maximize_box=0;
    panelTitle->m_minimize_box=0;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("管环监测");
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,31), wxSize(w,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w;
    h1=h-88;
    smPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    smPanel->SetBackgroundColour(wxColor(239,239,239));

    x2=15;
    y2=15;
    w2=120;
    h2=h1-30;

    mListPanel=new wxPanel(smPanel, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    mListPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    smList = new wxListView(mListPanel, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    x2=x2+w2+15;
    w2=w1-w2-45;
    smTextPanel=new wxPanel(smPanel, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    smTextPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    detailList = new wxListView(smTextPanel, wxID_ANY, wxPoint(10,60), wxSize(w2-20,h2-80), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentMonitorDlg::OnPaintBackground,0,this);

    mListPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentMonitorDlg::OnPaintMonitorList,0,this);

    smTextPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentMonitorDlg::OnPaintMonitorText,0,this);
    smTextPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentMonitorDlg::OnMotionMonitorText,0,this);
    smTextPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentMonitorDlg::OnLeaveMonitorText,0,this);
    smTextPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentMonitorDlg::OnClickMonitorText,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentMonitorDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentMonitorDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentMonitorDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentMonitorDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    int i=0;
    smList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,95);

    i=0;
    detailList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,65);
    detailList->InsertColumn(i++,_("管环编号"),wxLIST_FORMAT_CENTRE,75);
    detailList->InsertColumn(i++,_("高程"),wxLIST_FORMAT_CENTRE,75);
    detailList->InsertColumn(i++,_("当前上浮"),wxLIST_FORMAT_CENTRE,95);
    detailList->InsertColumn(i++,_("累计上浮"),wxLIST_FORMAT_CENTRE,95);
    detailList->InsertColumn(i++,_("日期"),wxLIST_FORMAT_CENTRE,150);

	//measList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,55);
    //measList->InsertColumn(i++,_("X"),wxLIST_FORMAT_CENTRE,85);
    //measList->InsertColumn(i++,_("Y"),wxLIST_FORMAT_CENTRE,85);
    //measList->InsertColumn(i++,_("Z"),wxLIST_FORMAT_CENTRE,80);
    //measList->InsertColumn(i++,_("沉降"),wxLIST_FORMAT_CENTRE,75);
    //measList->InsertColumn(i++,_("时间"),wxLIST_FORMAT_CENTRE,135);

    motion=ID_SEGMENT_MONITOR_COUNT;
    vmode=0;
}

SegmentMonitorDlg::~SegmentMonitorDlg()
{

}

void SegmentMonitorDlg::OnPaintMonitorList(wxPaintEvent& event)
{
    wxPaintDC dc(mListPanel);
    int w,h;
    mListPanel->GetClientSize(&w,&h);
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
        int w1=w;
        int h1=25;
        memDC.SetPen(wxPen(wxColor(173,173,173)));
        memDC.SetBrush(wxBrush(wxColor(225,225,225)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        wxString  str;
        str=_("管环监测列表");
        memDC.DrawLabel(str,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentMonitorDlg::OnPaintMonitorText(wxPaintEvent& event)
{
    wxPaintDC dc(smTextPanel);
    int w,h;
    smTextPanel->GetClientSize(&w,&h);
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
        memDC.SetPen(wxPen(wxColor(173,173,173)));
        memDC.SetBrush(wxBrush(wxColor(225,225,225)));
        memDC.DrawRectangle(x1,y1,w,h1);
        smButton[ID_SEGMENT_MONITOR_VIEW_GRAPH].x=x1;
        smButton[ID_SEGMENT_MONITOR_VIEW_GRAPH].y=y1;
        smButton[ID_SEGMENT_MONITOR_VIEW_GRAPH].width=w1;
        smButton[ID_SEGMENT_MONITOR_VIEW_GRAPH].height=h1;
        if(vmode==1)
        {
            memDC.DrawRectangle(x1,y1,w1,h1);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(255,255,255)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.DrawRectangle(x1+1,y1+1,w1-2,h1);
            memDC.SetPen(wxPen(wxColor(173,173,173)));
            memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        }

        wxString  str;
        str=_("图表查看");
        memDC.DrawLabel(str,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1-1;
        smButton[ID_SEGMENT_MONITOR_VIEW_DATA].x=x1;
        smButton[ID_SEGMENT_MONITOR_VIEW_DATA].y=y1;
        smButton[ID_SEGMENT_MONITOR_VIEW_DATA].width=w1;
        smButton[ID_SEGMENT_MONITOR_VIEW_DATA].height=h1;
        memDC.SetPen(wxPen(wxColor(173,173,173)));
        memDC.SetBrush(wxBrush(wxColor(225,225,225)));
        if(vmode==0)
        {
            memDC.DrawRectangle(x1,y1,w1,h1);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(255,255,255)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.DrawRectangle(x1+1,y1+1,w1-2,h1);
            memDC.SetPen(wxPen(wxColor(173,173,173)));
            memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        }

        str=_("列表数据");
        memDC.DrawLabel(str,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        if(vmode==1)
        {
            detailList->GetPosition(&x1,&y1);
            detailList->GetSize(&w1,&h1);
            memDC.SetPen(wxPen(wxColor(135,135,135)));
            memDC.SetBrush(wxBrush(wxColor(225,225,225)));
            h1=25;
            y1=y1-h1+1;
            memDC.DrawRectangle(x1,y1,w1,h1);
            int i=0;
            w1=detailList->GetColumnWidth(i++);
            memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
            memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            x1=x1+w1;
            w1=detailList->GetColumnWidth(i++);
            memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
            memDC.DrawLabel(_("管环编号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            x1=x1+w1;
            w1=detailList->GetColumnWidth(i++);
            memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
            memDC.DrawLabel(_("高程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            x1=x1+w1;
            w1=detailList->GetColumnWidth(i++);
            memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
            memDC.DrawLabel(_("当前上浮(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            x1=x1+w1;
            w1=detailList->GetColumnWidth(i++);
            memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
            memDC.DrawLabel(_("累计上浮(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            x1=x1+w1;
            w1=detailList->GetColumnWidth(i++);
            memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
            memDC.DrawLabel(_("日期"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        }


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}


void SegmentMonitorDlg::OnMotionMonitorText(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>smButton[ID_SEGMENT_MONITOR_VIEW_GRAPH].y && y<smButton[ID_SEGMENT_MONITOR_VIEW_GRAPH].y+smButton[ID_SEGMENT_MONITOR_VIEW_GRAPH].height)
    {
        if(x>smButton[ID_SEGMENT_MONITOR_VIEW_GRAPH].x && x<smButton[ID_SEGMENT_MONITOR_VIEW_GRAPH].x+smButton[ID_SEGMENT_MONITOR_VIEW_GRAPH].width)
        {
            motion=ID_SEGMENT_MONITOR_VIEW_GRAPH;
        }
        else if(x>smButton[ID_SEGMENT_MONITOR_VIEW_DATA].x && x<smButton[ID_SEGMENT_MONITOR_VIEW_DATA].x+smButton[ID_SEGMENT_MONITOR_VIEW_DATA].width)
        {
            motion=ID_SEGMENT_MONITOR_VIEW_DATA;
        }
        else
        {
            motion=ID_SEGMENT_MONITOR_NONE;
        }
    }
    else
    {
        motion=ID_SEGMENT_MONITOR_NONE;
    }
    smTextPanel->Refresh();
}

void SegmentMonitorDlg::OnLeaveMonitorText(wxMouseEvent& event)
{
    motion=ID_SEGMENT_MONITOR_NONE;
    smTextPanel->Refresh();
}

void SegmentMonitorDlg::OnClickMonitorText(wxMouseEvent& event)
{
    if(motion==ID_SEGMENT_MONITOR_VIEW_DATA)
    {
        vmode=1;
    }
    else if(motion==ID_SEGMENT_MONITOR_VIEW_GRAPH)
    {
        vmode=0;
    }
    smTextPanel->Refresh();
}

void SegmentMonitorDlg::OnPaintBottom(wxPaintEvent& event)
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
        int w2,h2;
        memDC.SetPen(wxPen(wxColor(117,117,117)));

        y1=9;
        w1=32;
        h1=26;
        x1=9;

        w1=65;
        x1=w-w1-12;
        smButton[ID_SEGMENT_MONITOR_QUIT].x=x1;
        smButton[ID_SEGMENT_MONITOR_QUIT].y=y1;
        smButton[ID_SEGMENT_MONITOR_QUIT].width=w1;
        smButton[ID_SEGMENT_MONITOR_QUIT].height=h1;
        if(motion==ID_SEGMENT_MONITOR_QUIT)
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

void SegmentMonitorDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>smButton[ID_SEGMENT_MONITOR_QUIT].y && y<smButton[ID_SEGMENT_MONITOR_QUIT].y+smButton[ID_SEGMENT_MONITOR_QUIT].height)
    {
        if(x>smButton[ID_SEGMENT_MONITOR_QUIT].x && x<smButton[ID_SEGMENT_MONITOR_QUIT].x+smButton[ID_SEGMENT_MONITOR_QUIT].width)
        {
            motion=ID_SEGMENT_MONITOR_QUIT;
        }
        /*else if(x>smButton[ID_TARPOS_NEXT].x && x<smButton[ID_TARPOS_NEXT].x+smButton[ID_TARPOS_NEXT].width)
        {
            motion=ID_TARPOS_NEXT;
        }
        else if(x>smButton[ID_TARPOS_LAST].x && x<smButton[ID_TARPOS_LAST].x+smButton[ID_TARPOS_LAST].width)
        {
            motion=ID_TARPOS_LAST;
        }*/
        else
        {
            motion=ID_SEGMENT_MONITOR_NONE;
        }
    }
    else
    {
        motion=ID_SEGMENT_MONITOR_NONE;
    }
    panelBottom->Refresh();
}

void SegmentMonitorDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_SEGMENT_MONITOR_NONE;
    panelBottom->Refresh();
}

void SegmentMonitorDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_SEGMENT_MONITOR_QUIT)
    {
        Destroy();
    }
    //panelBottom->Refresh();
}

void SegmentMonitorDlg::OnPaintBackground(wxPaintEvent& event)
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
