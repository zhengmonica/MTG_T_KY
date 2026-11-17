///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SegmentMonitorDlg.h"
#include "mtg_t_svrApp.h"
//#include "confirmdlg.h"
//#include "SegDialog.h"
//#include "EntryDlg.h"
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

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x2=15;
    y2=26;
    w2=120;
    h2=h-87;

    listPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    listPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    segmentList = new wxListView(listPanel, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    x2=x2+w2+15;
    w2=w-w2-45;
    textPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    textPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    textList = new wxListView(textPanel, wxID_ANY, wxPoint(0,24), wxSize(w2,h2/2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentMonitorDlg::OnPaintMain,0,this);

    listPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentMonitorDlg::OnPaintList,0,this);

    textPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentMonitorDlg::OnPaintText,0,this);

    segmentList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&SegmentMonitorDlg::OnSegmentSelect,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegmentMonitorDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegmentMonitorDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegmentMonitorDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegmentMonitorDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    int i=0;
    segmentList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,0);
    segmentList->InsertColumn(i++,_("人员"),wxLIST_FORMAT_CENTRE,95);

    i=0;
    textList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    textList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,45);
    textList->InsertColumn(i++,_("时间"),wxLIST_FORMAT_CENTRE,150);
    textList->InsertColumn(i++,_("X"),wxLIST_FORMAT_CENTRE,100);
    textList->InsertColumn(i++,_("Y"),wxLIST_FORMAT_CENTRE,100);
    textList->InsertColumn(i++,_("Z"),wxLIST_FORMAT_CENTRE,85);
    textList->InsertColumn(i++,_("水平"),wxLIST_FORMAT_CENTRE,75);

    nsm=mtg_query_smlist(mtg,&sms);

    int n=mtg->ndty;
    wxString str;
    i=0;
    while(i<nsm)
    {
        segmentList->InsertItem(i,_(""));
        segmentList->SetItem(i,1,wxString::Format(_("%d"),sms[i]));
        i++;
    }

    i=i-1;
    motion=ID_SM_NONE;
    iseg=sms[i];
    segmentList->Select(i);
    nres=0;
    nres=mtg_query_smonitor(mtg,iseg,&res);
    txt=0;

    checkBoxWidth=14;
    checkBoxHeight=14;
    radioBoxR1=7;
    radioBoxR2=4;
    ///测试
    /*nres=80;
    res=(MTG_SEGMONITOR*)malloc(nres*sizeof(MTG_SEGMONITOR));
    res[0].iseg=10;
    time_t t;
    time(&t);
    res[0].t=t;
    res[0].x=0.0;
    res[0].y=0.0;
    res[0].z=0.0;
    res[0].dv=0.05;
    res[0].dv1=0.0;
    res[0].headc=100.0;
    double headc=res[0].headc;
    double detc=0.0;
    for(i=1;i<nres;i++)
    {
        res[i].x=res[i-1].x;
        res[i].y=res[i-1].y;
        res[i].z=res[i-1].z;
        res[i].t=res[i-1].t+100;
        res[i].dv=res[i-1].dv-0.001;
        if(i<50) res[i].dv1=res[i-1].dv1-0.001;
        else res[i].dv1=res[i-1].dv1;
        detc+=0.2;
        res[i].headc=headc+detc;
        if(detc>=mtg->segset.L)
        {
            detc=0.0;
            headc=res[i].headc;
            res[i].iseg=res[i-1].iseg+1;
        }
        else
        {
            res[i].iseg=res[i-1].iseg;
        }
    }*/
    UpdateText();
}

SegmentMonitorDlg::~SegmentMonitorDlg()
{
    if(res) free(res);
}

void SegmentMonitorDlg::UpdateText()
{
    int i=0;
    wxString str1;
    while(i<nres)
    {
        textList->InsertItem(i,_(""));
        str1=wxString::Format(_("%d"),i+1);
        textList->SetItem(i,1,str1);
        str1=wxDateTime(res[i].t).Format(_("%Y-%m-%d %H:%M:%S"));
        textList->SetItem(i,2,str1);
        str1=wxString::Format(_("%.3f"),res[i].x);
        textList->SetItem(i,3,str1);
        str1=wxString::Format(_("%.3f"),res[i].y);
        textList->SetItem(i,4,str1);
        str1=wxString::Format(_("%.3f"),res[i].z);
        textList->SetItem(i,5,str1);
        str1=wxString::Format(_("%.1f"),res[i].dv1*1000.0);
        textList->SetItem(i,6,str1);
        i++;
    }

}

void SegmentMonitorDlg::OnSegmentSelect(wxListEvent& event)
{
    textList->DeleteAllItems();
    int i=segmentList->GetFirstSelected();
    iseg=sms[i];
    nres=0;
    nres=mtg_query_smonitor(mtg,iseg,&res);
    //nres=mtg_query_duty(mtg,dvr,&res);
    UpdateText();
}

void SegmentMonitorDlg::OnPaintList(wxPaintEvent& event)
{
    wxPaintDC dc(listPanel);
    int w,h;
    listPanel->GetClientSize(&w,&h);
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
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        wxString  str;
        str=_("管环");
        memDC.DrawLabel(str,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentMonitorDlg::OnPaintText(wxPaintEvent& event)
{
    wxPaintDC dc(textPanel);
    int w,h;
    textPanel->GetClientSize(&w,&h);
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

        int x1,y1,w1,h1;
        textList->GetPosition(&x1,&y1);
        textList->GetSize(&w1,&h1);
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        h1=25;
        y1=y1-h1+1;
        memDC.DrawRectangle(x1,y1,w1,h1);
        int i=1;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("X"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("Y"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("Z"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("累计沉降"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=0;
        y1=h/2;
        w1=w;
        h1=h-h1;
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.SetPen(wxPen(wxColor(239,239,239)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        y1=y1+10;
        h1=h-y1;
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        x1=45;
        y1=y1+10;
        w1=w-x1*2;
        h1=25;
        double l1,l2;
        int n1,n2;
        double mxh;

        if(nres>0)
        {
            n1=res[0].iseg;
            n2=res[nres-1].iseg;
            l1=res[0].headc;
            l2=res[nres-1].headc;
            mxh=fabs(res[nres-1].dv1*1000.0);
            mxh=mxh+20.0;
        }
        else
        {
            n1=n2=0;
            l1=l2=0.0;
            mxh=50.0;
        }

        wxString istr;
        istr=_("监测过程：");
        istr=istr+wxString::Format(_(" %d ～ %d 环"),n1,n2)+_("         ");
        istr=istr+wxString::Format(_("%.3f ～ %.3f米"),l1,l2)+_("         ");
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        ///偏差曲线图
        int x2,y2,w2,h2;
        x2=x1;
        y2=y1+40;
        w2=w1;
        h2=h-y2-40;
        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.DrawLine(x2,y2+h2/2,x2+w2,y2+h2/2);
        memDC.DrawLine(x2,y2,x2,y2+h2);

        h1=h2/4;
        x1=x2;
        y1=y2;
        w1=w2;
        memDC.SetPen(wxPen(wxColor(201,201,201),1,wxDOT));
        memDC.DrawLine(x1,y1,x1+w1,y1);

        memDC.DrawLabel(wxString::Format(_("%.1f"),mxh),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1;
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLabel(wxString::Format(_("%.1f"),mxh/2.0),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("0"),wxRect(x1-7,y1+h1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1*2;
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLabel(wxString::Format(_("%.1f"),-mxh/2.0),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1;
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLabel(wxString::Format(_("%.1f"),-mxh),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLabel(wxString::Format(_("%d"),n1),wxRect(x1,y1+7,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(wxString::Format(_("%d"),n2),wxRect(x1+w1*4/4,y1+7,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

        double xs,ys;
        int xi,yi;
        int mkx;
        xs=(l2-l1)/w1;
        ys=mxh/(h1*2.0);
        h1=h2;
        x1=x2;
        y1=y2;
        w1=w2;
        memDC.SetPen(wxPen(wxColor(201,0,0)));
        memDC.SetBrush(wxBrush(wxColor(201,0,0)));
        for(int i=nres-1;i>0;i--)
        {
            if(i==nres-1)
            {
                xi=x1;
                yi=y1+h1/2-res[i].dv1*1000.0/ys;
                memDC.DrawRectangle(xi-3,yi-3,6,6);
                x2=xi;
                y2=yi;
                mkx=xi;
            }
            else
            {
                xi=x2+(res[i].headc-res[i-1].headc)/xs;
                yi=y1+h1/2-res[i].dv1*1000.0/ys;
                if(xi-mkx>12)
                {
                    memDC.DrawRectangle(xi-3,yi-3,6,6);
                    mkx=xi;
                }
                memDC.DrawLine(x2,y2,xi,yi);
                x2=xi;
                y2=yi;
            }
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
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
        button[ID_SM_QUIT].x=x1;
        button[ID_SM_QUIT].y=y1;
        button[ID_SM_QUIT].width=w1;
        button[ID_SM_QUIT].height=h1;
        if(motion==ID_SM_QUIT)
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

        x1=x1-w1-7;
        button[ID_SM_EXP].x=x1;
        button[ID_SM_EXP].y=y1;
        button[ID_SM_EXP].width=w1;
        button[ID_SM_EXP].height=h1;
        if(motion==ID_SM_EXP)
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
        memDC.DrawLabel(_("导出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=9;
        y1=9;
        h1=26;
        w1=h1*4/3;

        button[ID_SM_PRT_SCN].x=x1;
        button[ID_SM_PRT_SCN].y=y1;
        button[ID_SM_PRT_SCN].width=w1;
        button[ID_SM_PRT_SCN].height=h1;
        if(motion==ID_SM_PRT_SCN)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
        }
        int x2,y2;
        h2=h1-6;
        w2=h1;
        x2=x1+w1/2-w2/2;
        y2=y1+3;
        memDC.SetPen(wxPen(wxColor(168,181,178)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x2,y2,w2,h2-2);
        memDC.SetPen(wxPen(wxColor(47,139,205)));
        memDC.SetBrush(wxBrush(wxColor(47,139,205)));
        memDC.DrawRectangle(x2+3,y2+4,w2-6,h2-11);

        memDC.SetPen(wxPen(wxColor(168,181,178)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x2+w2/4-1,y2+h2-3,w2/2,4);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegmentMonitorDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_SM_QUIT].y && y<button[ID_SM_QUIT].y+button[ID_SM_QUIT].height)
    {
        if(x>button[ID_SM_QUIT].x && x<button[ID_SM_QUIT].x+button[ID_SM_QUIT].width)
        {
            motion=ID_SM_QUIT;
        }
        else if(x>button[ID_SM_EXP].x && x<button[ID_SM_EXP].x+button[ID_SM_EXP].width)
        {
            motion=ID_SM_EXP;
        }
        else if(x>button[ID_SM_PRT_SCN].x && x<button[ID_SM_PRT_SCN].x+button[ID_SM_PRT_SCN].width)
        {
            motion=ID_SM_PRT_SCN;
        }
        else
        {
            motion=ID_SM_NONE;
        }
    }
    else
    {
        motion=ID_SM_NONE;
    }
    panelBottom->Refresh();
}

void SegmentMonitorDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_SM_NONE;
    panelBottom->Refresh();
}

void SegmentMonitorDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_SM_QUIT)
    {
        Destroy();
    }
    else if(motion==ID_SM_PRT_SCN)
    {
        wxSize screenSize = GetSize();
        wxBitmap bitmap(screenSize.x, screenSize.y);
        wxScreenDC dc;
        wxMemoryDC memDC;
        memDC.SelectObject(bitmap);

        memDC.Blit(0,0,screenSize.x,screenSize.y, &dc,GetPosition().x,GetPosition().y);
        memDC.SelectObject(wxNullBitmap);

        wxString str;
        time_t t;
        time(&t);
        //str=wxString(mtg->duty[i].name,wxConvLocal);
        str=_("监测界面");
        str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
        }
    }
    //panelBottom->Refresh();
}

void SegmentMonitorDlg::OnPaintMain(wxPaintEvent& event)
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

        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.SetPen(wxPen(wxColor(239,239,239)));
        memDC.DrawRectangle(0,10,w,h-11);
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(0,10,w,10);
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}
