///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyHistoryDlg.h"
#include "mtg_t_svrApp.h"
//#include "confirmdlg.h"
//#include "SegDialog.h"
//#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>
#include <wx/dcbuffer.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MyHistoryDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MyHistoryDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MyHistoryDlg)

//*)

MyHistoryDlg::MyHistoryDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMetric = new wxPanel(panelMain, wxID_ANY, wxPoint(0,0), wxSize(800,375), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    metroFig1 = new wxPanel(panelMetric, wxID_ANY, wxPoint(150,20), wxSize(320,320), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    metroFig2 = new wxPanel(panelMetric, wxID_ANY, wxPoint(480,20), wxSize(320,320), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    metroFig3 = new wxPanel(panelMetric, wxID_ANY, wxPoint(0,20), wxSize(140,320), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelGraph = new wxPanel(panelMain, wxID_ANY, wxPoint(0,375), wxSize(800,h-420), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    panelMetric->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    metroFig1->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    metroFig2->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    metroFig3->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelGraph->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMetric->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyHistoryDlg::OnPaintMetric,0,this);
    metroFig1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyHistoryDlg::OnPaintMetroFig1,0,this);
    metroFig2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyHistoryDlg::OnPaintMetroFig2,0,this);
    metroFig3->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyHistoryDlg::OnPaintMetroFig3,0,this);
    panelGraph->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyHistoryDlg::OnPaintGraph,0,this);
    panelGraph->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyHistoryDlg::OnClickGraph,0,this);
    panelGraph->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyHistoryDlg::OnLeaveGraph,0,this);
    panelGraph->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyHistoryDlg::OnMotionGraph,0,this);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);


    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyHistoryDlg::OnPaintMain,0,this);
    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyHistoryDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyHistoryDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyHistoryDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyHistoryDlg::OnClickBottom,0,this);
    //*)
    Connect(wxEVT_TIMER,(wxObjectEventFunction)&MyHistoryDlg::OnTimer);
    hisTimer.SetOwner(this);
    hisTimer.Start(10,false);

    this->SetBackgroundColour(wxColor(245,248,250));

    double l2=mtg->m1.headc;
    double l1=l2-15.0*mtg->prj.a2z;
    ms=0;
    nms=0;
    if(l1>l2)
    {
        double temp=l2;
        l2=l1;
        l1=temp;
    }
    nms=mtg_query_chain(mtg,l1,l2,&ms);

    if(nms>0)
    {
        res[0]=ms[0];
        nres=1;
        double detL=0.0;
        for(int i=1;i<nms;i++)
        {
            detL=fabs(ms[i].headc-res[nres-1].headc);
            if(detL>=0.1)
            {
                res[nres]=ms[i];
                nres++;
            }
        }
    }
    imile=l2;
    //res[nres].mile1=mtg->m1.mile1+1.0*mtg->prj.a2z;
    dp1=0;
    dp2=0;
    iplay=0;      ///1向前播放2向后播放
    //wxMessageBox(wxString::Format(_("%d,%d"),nms,nres));
    motion=ID_HIS_NONE;
    //mtg_cal_seg(mtg);
}

MyHistoryDlg::~MyHistoryDlg()
{
    if(iplay>0)
    {
        iplay=0;
        sleepms(20);
    }
    if(ms) free(ms);
}

void MyHistoryDlg::GetMetro()
{
    int maxw,maxh;
    double val;
    int a2z=mtg->prj.a2z;
    double x,y,z;

    maxw=0;
    maxh=0;

    headc=res[dp1].mile1;
    headh=res[dp1].hdev1*1000.0;
    headv=res[dp1].vdev1*1000.0;
    midc=res[dp1].mile2;
    midh=res[dp1].hdev2*1000.0;
    midv=res[dp1].vdev2*1000.0;
    tailc=res[dp1].mile3;
    tailh=res[dp1].hdev3*1000.0;
    tailv=res[dp1].vdev3*1000.0;

    if(mtg->tbm.type==0)
    {
        head[0]=res[dp1].head[0];
        head[1]=res[dp1].head[1];
        head[2]=res[dp1].head[2];
        tail[0]=res[dp1].tail[0];
        tail[1]=res[dp1].tail[1];
        tail[2]=res[dp1].tail[2];
        hdes[0]=res[dp1].hdes[0];
        hdes[1]=res[dp1].hdes[1];
        hdes[2]=res[dp1].hdes[2];
        tdes[0]=res[dp1].tdes[0];
        tdes[1]=res[dp1].tdes[1];
        tdes[2]=res[dp1].tdes[2];
        inc[0]=res[dp1].inc1[0]*PI/180.0;
        inc[1]=res[dp1].inc1[1]*PI/180.0;
        inc[2]=res[dp1].inc1[2]*PI/180.0;
        //trace(0,"metro:ori=%.4f,phi=%.4f,roll=%.4f\n",mtg->m1.inc[0],mtg->m1.inc[0],mtg->m1.inc[0]);


        tbmlen=(head[0]-tail[0])*(head[0]-tail[0])+(head[1]-tail[1])*(head[1]-tail[1]);
        tbmlen = sqrt(tbmlen);
        //trace(0,"metro:len=%.4f\n",tbmlen);
        maxw = abs(headh)>abs(tailh)?abs(headh):abs(tailh);
        maxh = abs(headv)>abs(tailv)?abs(headv):abs(tailv);
        if(mtg->iset.trend==1)
        {
            double i1,i2;
            road_l2xy(&mtg->r,headc,0,0,&i1);
            road_l2h(&mtg->r,headc,0,&i2);
            //trace(0,"metro:i1=%.4f,i2=%.4f\n",i1,i2);
            //trace(0,"metro:ori=%.4f,phi=%.4f\n",inc[2],inc[1]);
            if(a2z==-1)
            {
                i1+=PI;
                i2=-i2;
                if(i1>2.0*PI) i1-=2.0*PI;
                if(i2>2.0*PI) i2-=2.0*PI;
                //trace(0,"metro:dori=%.4f,dphi=%.4f\n",i1,i2);
            }
            val=inc[2]-i1;
            htrend=tan(val)*1000.0;
            val=inc[1]-i2;
            vtrend=tan(val)*1000.0;
            //trace(0,"metro:htrend=%.4f,vtrend=%.4f\n",htrend,vtrend);
        }
        else
        {
            htrend=(headh-tailh)/tbmlen;
            vtrend=(headv-tailv)/tbmlen;
        }
    }
    else if(mtg->tbm.type==1)
    {
        head[0]=res[dp1].head[0];
        head[1]=res[dp1].head[1];
        head[2]=res[dp1].head[2];
        mid[0]=res[dp1].tail[0];
        mid[1]=res[dp1].tail[1];
        mid[2]=res[dp1].tail[2];
        tail[0]=res[dp1].tail2[0];
        tail[1]=res[dp1].tail2[1];
        tail[2]=res[dp1].tail2[2];
        hdes[0]=res[dp1].hdes[0];
        hdes[1]=res[dp1].hdes[1];
        hdes[2]=res[dp1].hdes[2];
        mdes[0]=res[dp1].tdes[0];
        mdes[1]=res[dp1].tdes[1];
        mdes[2]=res[dp1].tdes[2];
        tdes[0]=res[dp1].tdes2[0];
        tdes[1]=res[dp1].tdes2[1];
        tdes[2]=res[dp1].tdes2[2];
        inc[0]=res[dp1].inc1[0]*PI/180.0;
        inc[1]=res[dp1].inc1[1]*PI/180.0;
        inc[2]=res[dp1].inc1[2]*PI/180.0;

        tbmlen=(head[0]-mid[0])*(head[0]-mid[0])+(head[1]-mid[1])*(head[1]-mid[1]);
        tbmlen = sqrt(tbmlen);
        maxw = abs(headh)>abs(midh)?abs(headh):abs(midh);
        maxh = abs(headv)>abs(midv)?abs(headv):abs(midv);

        if(mtg->iset.trend==1)
        {
            double i1,i2;
            road_l2xy(&mtg->r,headc,0,0,&i1);
            road_l2h(&mtg->r,headc,0,&i2);
            //trace(0,"metro:headc=%.4f,i1=%.4f,i2=%.4f\n",headc,i1,i2);
            //trace(0,"metro:ori=%.4f,phi=%.4f\n",inc[2],inc[1]);
            if(a2z==-1)
            {
                i1+=PI;
                i2=-i2;
                if(i1>2.0*PI) i1-=2.0*PI;
                if(i2>2.0*PI) i2-=2.0*PI;
            }
            val=inc[2]-i1;
            htrend=tan(val)*1000.0;
            val=inc[1]-i2;
            vtrend=tan(val)*1000.0;
            //trace(0,"metro:htrend=%.4f,vtrend=%.4f\n",htrend,vtrend);
        }
        else
        {
            htrend=(headh-midh)/tbmlen;
            vtrend=(headv-midv)/tbmlen;
        }
    }
    else if(mtg->tbm.type==2)
    {
        if(mtg->tarset.pos==0)
        {
            head[0]=res[dp1].head[0];
            head[1]=res[dp1].head[1];
            head[2]=res[dp1].head[2];
            mid[0]=res[dp1].tail[0];
            mid[1]=res[dp1].tail[1];
            mid[2]=res[dp1].tail[2];
            tail[0]=res[dp1].tail2[0];
            tail[1]=res[dp1].tail2[1];
            tail[2]=res[dp1].tail2[2];
            hdes[0]=res[dp1].hdes[0];
            hdes[1]=res[dp1].hdes[1];
            hdes[2]=res[dp1].hdes[2];
            mdes[0]=res[dp1].tdes[0];
            mdes[1]=res[dp1].tdes[1];
            mdes[2]=res[dp1].tdes[2];
            tdes[0]=res[dp1].tdes2[0];
            tdes[1]=res[dp1].tdes2[1];
            tdes[2]=res[dp1].tdes2[2];
            inc[0]=res[dp1].inc1[0]*PI/180.0;
            inc[1]=res[dp1].inc1[1]*PI/180.0;
            inc[2]=res[dp1].inc1[2]*PI/180.0;
        }
        else if(mtg->tarset.pos==1)
        {
            head[0]=res[dp1].head1[0];
            head[1]=res[dp1].head1[1];
            head[2]=res[dp1].head1[2];
            mid[0]=res[dp1].tail1[0];
            mid[1]=res[dp1].tail1[1];
            mid[2]=res[dp1].tail1[2];
            tail[0]=res[dp1].tail[0];
            tail[1]=res[dp1].tail[1];
            tail[2]=res[dp1].tail[2];
            hdes[0]=res[dp1].hdes1[0];
            hdes[1]=res[dp1].hdes1[1];
            hdes[2]=res[dp1].hdes1[2];
            mdes[0]=res[dp1].tdes1[0];
            mdes[1]=res[dp1].tdes1[1];
            mdes[2]=res[dp1].tdes1[2];
            tdes[0]=res[dp1].tdes[0];
            tdes[1]=res[dp1].tdes[1];
            tdes[2]=res[dp1].tdes[2];
            inc[0]=res[dp1].inc2[0]*PI/180.0;
            inc[1]=res[dp1].inc2[1]*PI/180.0;
            inc[2]=res[dp1].inc2[2]*PI/180.0;
        }

        //tbmlen=(head[0]-mid[0])*(head[0]-mid[0])+(head[1]-mid[1])*(head[1]-mid[1]);
        //tbmlen = sqrt(tbmlen);
        tbmlen=res[0].mile1-res[0].mile2;
        tbmlen=fabs(tbmlen);
        //wxMessageBox(wxString::Format(_("%.4f,%.4f"),tbmlen,mid[0]));
        //trace(0,"ui:pit=%.12f,azi=%.12f\n",inc[1],inc[2]);
        maxw = abs(headh)>abs(midh)?abs(headh):abs(midh);
        maxh = abs(headv)>abs(midv)?abs(headv):abs(midv);

        if(mtg->iset.trend==1)
        {
            double i1,i2;
            road_l2xy(&mtg->r,headc,0,0,&i1);
            road_l2h(&mtg->r,headc,0,&i2);
            //trace(0,"metro:headc=%.4f,i1=%.4f,i2=%.4f\n",headc,i1,i2);
            //trace(0,"metro:ori=%.4f,phi=%.4f\n",inc[2],inc[1]);
            if(a2z==-1)
            {
                i1+=PI;
                i2=-i2;
                if(i1>2.0*PI) i1-=2.0*PI;
                if(i2>2.0*PI) i2-=2.0*PI;
            }
            val=inc[2]-i1;
            htrend=tan(val)*1000.0;
            val=inc[1]-i2;
            vtrend=tan(val)*1000.0;
            //trace(0,"metro:htrend=%.4f,vtrend=%.4f\n",htrend,vtrend);
        }
        else
        {
            htrend=(headh-midh)/tbmlen;
            //wxMessageBox(wxString::Format(_("%.4f,%.4f"),htrend,mid[0]));
            vtrend=(headv-midv)/tbmlen;
        }
    }

    //wxMessageBox(wxString::Format(_("%d"),mtg->tarset.pos));
    maxdev = (maxw>maxh)?maxw:maxh;

    int n=maxdev/50;
    maxdev=50*n+50;
    //wxMessageBox(wxString::Format(_("%d"),maxdev));

    if(tbmlen==0)
    {
        htrend=0.0;
        vtrend=0.0;
    }
}

void MyHistoryDlg::OnPaintGraph(wxPaintEvent& event)
{
    wxPaintDC dc(panelGraph);
    int w,h;
    panelGraph->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        ///background
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.DrawLine(0,h/2,w,h/2);
        memDC.SetPen(wxPen(wxColor(201,201,201),1,wxDOT));
        memDC.DrawLine(0,h/4,w,h/4);
        memDC.DrawLine(0,h*3/4,w,h*3/4);

        double hs=w/30.0;
        double vs=h*1.0/4.0/50.0;
        double li,xi[2],yi[2],zi[2];
        xi[0]=w/2;
        yi[0]=h/2+res[0].hdev1*1000.0*vs;
        zi[0]=h/2-res[0].vdev1*1000.0*vs;
        //memDC.SetBrush(wxBrush(wxColor(255,0,0)));
        //memDC.DrawCircle(xi[0],yi[0],4);

        for(int i=1;i<nres;i++)
        {
            li=(res[0].mile1-res[i].mile1)*mtg->prj.a2z;
            li=li*hs;
            xi[1]=w/2-li;
            yi[1]=h/2+res[i].hdev1*1000.0*vs;
            zi[1]=h/2-res[i].vdev1*1000.0*vs;
            if(xi[0]<w/2 && xi[1]>w/2)
            {
                xi[0]=xi[1];
                yi[0]=yi[1];
                zi[0]=zi[1];
                continue;
            }
            memDC.SetPen(wxPen(wxColor(255,0,0)));
            memDC.DrawLine(xi[0],yi[0],xi[1],yi[1]);
            memDC.SetPen(wxPen(wxColor(0,255,0)));
            memDC.DrawLine(xi[0],zi[0],xi[1],zi[1]);
            xi[0]=xi[1];
            yi[0]=yi[1];
            zi[0]=zi[1];
        }

        memDC.SetPen(wxPen(wxColor(105,105,150)));
        memDC.DrawLine(0,h-1,w,h-1);
        li=(res[0].mile1-res[dp1].mile1)*mtg->prj.a2z;
        li=li*hs;
        xi[0]=w/2-li;
        memDC.DrawLine(xi[0],h*1/8,xi[0],h*7/8);

        memDC.SetPen(wxPen(wxColor(105,105,150),1,wxDOT));
        if(dp2>0 && iplay==0) memDC.DrawLine(dp2,h*1/8,dp2,h*7/8);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyHistoryDlg::OnMotionGraph(wxMouseEvent& event)
{
    dp2=event.GetX();
    panelGraph->Refresh();
}

void MyHistoryDlg::OnLeaveGraph(wxMouseEvent& event)
{
    dp2=0;
    panelGraph->Refresh();
}

void MyHistoryDlg::OnClickGraph(wxMouseEvent& event)
{
    if(iplay>0) return;
    int x=event.GetX();
    int w;
    panelGraph->GetSize(&w,0);
    double s=w/30.0;
    x=w/2-x;
    x=x/s;
    double l2=imile-x;
    double l1;
    if(mtg->prj.a2z==1)
    {
        if(l2>mtg->m1.headc) l2=mtg->m1.headc;
        l1=l2-15.0;
    }
    else
    {
        if(l2<mtg->m1.headc) l2=mtg->m1.headc;
        l1=l2+15.0;
    }

    if(ms) free(ms);
    ms=0;
    nms=0;
    if(l1>l2)
    {
        double temp=0;
        temp=l1;
        l1=l2;
        l2=temp;
    }
    nms=mtg_query_chain(mtg,l1,l2,&ms);
    if(nms>0)
    {
        res[0]=ms[0];
        nres=1;
        double detL=0.0;
        for(int i=1;i<nms;i++)
        {
            detL=fabs(ms[i].headc-res[nres-1].headc);
            if(detL>0.1)
            {
                res[nres]=ms[i];
                nres++;
            }
        }
    }
    else
    {
        nres=0;
    }

    imile=l2;
    //dp3=nres;
    if(mtg->prj.a2z==1)
    {
        l1=l2+0.05;
        if(l2+15.0>mtg->m1.headc) l2=mtg->m1.headc;
        else l2+=15.0;
    }
    else
    {
        l1=l2-0.05;
        if(l2-15.0<mtg->m1.headc) l2=mtg->m1.headc;
        else l2-=15.0;
    }

    if(ms) free(ms);
    ms=0;
    nms=0;
	if(l1>l2)
    {
        double temp=l2;
        l2=l1;
        l1=temp;
    }
    nms=mtg_query_chain(mtg,l1,l2,&ms);
    if(nms>0)
    {
        if(nres==0)
        {
            res[0]=ms[0];
            nres=1;
        }
        double detL=0.0;
        for(int i=1;i<nms;i++)
        {
            detL=fabs(ms[i].headc-res[nres-1].headc);
            if(detL>0.1)
            {
                res[nres]=ms[i];
                nres++;
            }
        }
    }
    dp1=0;
    panelMetric->Refresh();
    panelGraph->Refresh();
    panelBottom->Refresh();
    //wxMessageBox(wxString::Format(_("%d,%d,%d"),dp1,dp3,nres));
}

void MyHistoryDlg::OnPaintMetric(wxPaintEvent& event)
{
    wxPaintDC dc(panelMetric);
	///调试
    GetMetro();
    //trace(0,"metric:headh=%d,headv=%d\n",headh,headv);
    int w,h;
    panelMetric->GetClientSize(&w,&h);
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

        memDC.SetPen(wxPen(wxColor(105,105,150)));
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyHistoryDlg::OnPaintMetroFig1(wxPaintEvent& event)
{
    wxPaintDC dc(metroFig1);
    int w,h;
    metroFig1->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        //FILE* fp=fopen("E:\\metricFig1.log","w");
        ///background
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);
        ///字体
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng1(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        wxFont eng2(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);

        ///姿态区域
        road* cl = &mtg->r;
        int nh = road_number_horizon(cl);
        int nv = road_number_vertical(cl);
        int a2z=mtg->prj.a2z;
        double x[6]={0.0};
        double y[6]={0.0};
        double z[6]={0.0};
        int r[6];
        r[0] = w/2-1;
        //r[0] = r[0]*9/10;
        for(int i=1;i<6;i++)
        {
            r[i]=r[i-1]-15;
        }
        int cell = r[0]/5;
        double s = (4.0*cell)/maxdev;
        double val;

        ///盾构三维图
        double sw = mtg->segset.L;
        double mile =mtg->m1.headc;
        double alf1,alf2,ph;
        double sr1,sr2;
        int h1 = 20;

        int gx1=w/2;
        int gy1=h/2;

        if(mtg->m1.t1<=0)
        {
            if(a2z==1)
            {
                mile = mtg->prj.mile1;
                road_l2xy(cl,mile,&x[0],&y[0],&alf1);
                road_l2h(cl,mile,&z[0],&alf2);
            }
            else
            {
                mile = mtg->prj.mile2;
                road_l2xy(cl,mile,&x[0],&y[0],&alf1);
                alf1 = alf1+PI;
                if(alf1>2.0*PI) alf1 = alf1-2.0*PI;
                road_l2h(cl,mile,&z[0],&alf2);
                alf2 = alf2+PI;
                if(alf2>2.0*PI) alf2 = alf2-2.0*PI;
            }
        }
        else
        {
            if(a2z==1)
            {
                road_l2xy(cl,mile,&x[0],&y[0],&alf1);
                road_l2h(cl,mile,&z[0],&alf2);
            }
            else
            {
                road_l2xy(cl,mile,&x[0],&y[0],&alf1);
                alf1 = alf1+PI;
                if(alf1>2.0*PI) alf1 = alf1-2.0*PI;
                road_l2h(cl,mile,&z[0],&alf2);
                alf2 = alf2+PI;
                if(alf2>2.0*PI) alf2 = alf2-2.0*PI;
            }
        }
        h_element* he;
        v_element* ve;
        if(nh>2)
        {
            sr1 = 1.5;
            sr2 = 0.75;
            he = road_horizon_chain(cl,mile,0);
            if(he)
            {
                if(he->radius>300 && he->radius<=1500)
                {
                    sr1 = sr1+(he->radius-300)*0.5/1200;
                }
                else if(he->radius>1500 && he->radius<=3000)
                {
                    sr1 = sr1+0.5+(he->radius-1500)*1.0/1500;
                }
                else if(he->radius > 3000)
                {
                    sr1 = 3.0;
                }
                else
                {
                    sr1 = sr1+(he->radius-300)*1/300;
                }
            }
            ve=road_vertical_chain(cl,mile,0);
            if(ve)
            {
                double slope = 0.0;
                road_l2h(&mtg->r,mile,0,&slope);
                slope=slope*1000.0;
                if(slope<=5)
                {
                    sr2 = 1.25;
                }
                else if(slope>5 && slope<=15)
                {
                    sr2 = 1.25-0.5*(slope-5)/10;
                }
                else if(slope>15 && slope<=30)
                {
                    sr2 = 0.75-0.25*(slope-15)/15;
                }
                else
                {
                    sr2 = 0.5;
                }
            }
            for(int i=1;i<6;i++)
            {
                x[i] = x[0]+(sw*i)*cos(alf1);
                y[i] = y[0]+(sw*i)*sin(alf1);
                //fprintf(fp,"x[%d]=%.4f,y[%d]=%.4f\n",i,x[i],i,y[i]);
                //fprintf(fp,"sr1=%.12f\n",sr1);
                val=0;
                road_xy2l(cl,x[i],y[i],0,0,0,0,&val);
                //fprintf(fp,"val=%.12f\n",val);
                x[i]=val;

                if(a2z==1)
                {
                    x[i] = -x[i]*1000.0*sr1+(double)gx1;
                }
                else
                {
                    x[i] = x[i]*1000.0*sr1+(double)gx1;
                }
                if(nv>2)
                {
                    z[i] = z[0];
                    if(a2z==1)
                    {
                        road_l2h(cl,mile+sw*i,&ph,0);
                        //fprintf(fp,"ph:%.4f\n",ph);
                    }
                    else
                    {
                        road_l2h(cl,mile-sw*i,&ph,0);

                    }
                    y[i] = (z[i]-ph)*1000.0*sr2+gy1;

                }
                else
                {
                    y[i] = gy1;
                }
                //fprintf(fp,"2:x[%d]=%.4f,y[%d]=%.4f\n",i,x[i],i,y[i]);
            }
        }
        else
        {
            for(int i=1;i<6;i++)
            {
                x[i] = gx1;
                if(nv>2)
                {
                    ve=road_vertical_chain(cl,mtg->m1.headc,0);
                    if(ve)
                    {
                        if(ve->type == ROAD_TYPE_ARC)
                        {
                            z[i] = z[0]+(sw*i)*sin(alf2);
                        }
                        else
                        {
                            z[i] = z[0];
                        }
                        if(mtg->prj.a2z==1)
                        {
                            road_l2h(cl,mile+sw*i,&ph,0);
                        }
                        else
                        {
                            road_l2h(cl,mile-sw*i,&ph,0);
                        }
                        if(ve->type == ROAD_TYPE_ARC)
                        {
                            y[i] = (z[i]-ph)*1000.0+gy1;
                        }
                        else
                        {
                            y[i] = (z[i]-ph)*1000.0/2+gy1;
                        }
                    }
                }
                else
                {
                    y[i] = gy1;
                }
            }
        }

        wxPoint pts[6][1440];
        x[0] = gx1;
        y[0] = gy1;
        double d1;
        double alf3;
        double alf;
        int x2,y2;

        int k;
        for(int i=0;i<6;i++)
        {
            if(i==0)
            {
                memDC.SetPen(wxPen(wxColor(237,248,254),1));
                memDC.SetBrush(wxBrush(wxColor(237,248,254)));
            }
            else if(i==1)
            {
                memDC.SetPen(wxPen(wxColor(188,218,244),1));
                memDC.SetBrush(wxBrush(wxColor(188,218,244)));
            }
            else if(i==2)
            {
                memDC.SetPen(wxPen(wxColor(160,200,235),1));
                memDC.SetBrush(wxBrush(wxColor(160,200,235)));
            }
            else if(i==3)
            {
                memDC.SetPen(wxPen(wxColor(144,189,225),1));
                memDC.SetBrush(wxBrush(wxColor(144,189,225)));
            }
            else if(i==4)
            {
                memDC.SetPen(wxPen(wxColor(129,178,210),1));
                memDC.SetBrush(wxBrush(wxColor(129,178,210)));
            }
            else if(i==5)
            {
                memDC.SetPen(wxPen(wxColor(119,172,204),1));
                memDC.SetBrush(wxBrush(wxColor(119,172,204)));
            }

            int inter = 0;
            double A[5] = {0.0};
            double B[5] = {0.0};
            for(int m=0;m<i;m++)
            {
                d1 = sqrt((x[i]-x[m])*(x[i]-x[m])+(y[i]-y[m])*(y[i]-y[m]));
                //fprintf(fp,"d1:%d,%d,%.12f,%d,%d\n",m,i,d1,r[m],r[i]);
                if(d1>(double)(r[m]-r[i]))
                {
                    alf1 = atan2(y[m]-y[i],x[m]-x[i]);
                    //fprintf(fp,"t1:%.12f,%.12f,%.12f,%.12f,%.12f\n",x[m],y[m],x[i],y[i],alf1);
                    if(alf1<0.0) alf1 = alf1+2.0*PI;
                    alf2 = acos((d1*d1+r[i]*r[i]-r[m]*r[m])/(2*d1*r[i]));

                    A[inter] = alf1+alf2;
                    //fprintf(fp,"t1:%.12f,%.12f,%.12f\n",alf1,alf2,A[inter]);
                    if(A[inter] > 2.0*PI) A[inter] = A[inter]-2.0*PI;
                    B[inter] = alf1-alf2;
                    //fprintf(fp,"t1:%.12f,%.12f,%.12f\n",alf1,alf2,A[inter]);
                    if(B[inter] < 0) B[inter] = B[inter]+2.0*PI;

                    inter++;
                }
            }
            alf1 = A[0];
            alf2 = B[0];

            for(int n=0;n<inter;n++)
            {
                if(alf1>A[n] && alf1-A[n]<PI)
                {
                    alf1 = A[n];
                }

                if(alf1<A[n] && A[n]-alf1>PI)
                {
                    alf1 = A[n];
                }


                if(alf2<B[n] && B[n]-alf2<PI)
                {
                    alf2 = B[n];
                }
                if(alf2>B[n] && alf2-B[n]>PI)
                {
                    alf2 = B[n];
                }
            }

            for(int j=0;j<1440;j++)
            {
                alf = PI*j/720;
                x2 = x[i]+r[i]*cos(alf);
                y2 = y[i]+r[i]*sin(alf);
                //fprintf(fp,"x[%d]=%.4f,y[%d]=%.4f\n",i,x[i],i,y[i]);
                if(i==0)
                {
                    pts[i][j].x = x2;
                    pts[i][j].y = y2;
                }
                else
                {
                    alf3 = atan2(y2-y[i-1],x2-x[i-1]);
                    if(alf3<0.0) alf3 = alf3+2.0*PI;
                    k = alf3/(PI/720);
                    if(inter == 0)
                    {
                        pts[i][j].x = x2;
                        pts[i][j].y = y2;
                    }
                    else
                    {
                        if(alf1<=alf2)
                        {
                            if(alf>alf1 && alf<alf2)
                            {
                                pts[i][j].x = pts[i-1][k].x;
                                pts[i][j].y = pts[i-1][k].y;
                            }
                            else
                            {
                                pts[i][j].x = x2;
                                pts[i][j].y = y2;
                            }
                        }
                        else
                        {
                            if(alf>alf1 || alf<alf2)
                            {
                                pts[i][j].x = pts[i-1][k].x;
                                pts[i][j].y = pts[i-1][k].y;
                            }
                            else
                            {
                                pts[i][j].x = x2;
                                pts[i][j].y = y2;
                            }
                        }
                    }
                }
            }
            memDC.DrawPolygon(1440,pts[i]);
            memDC.SetPen(wxPen(wxColor(70,75,80),2));
            memDC.SetBrush(*wxTRANSPARENT_BRUSH);
            memDC.DrawCircle(x[0],y[0],r[0]+1);
        }

        memDC.SetPen(wxPen(wxColor(70,75,80),2));
        memDC.DrawLine(gx1-r[0],gy1,gx1+r[0],gy1);
        memDC.DrawLine(gx1,gy1-r[0],gx1,gy1+r[0]);
        memDC.SetPen(wxPen(wxColor(255,20,20),1,wxLONG_DASH));
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);

        if(maxdev==50) memDC.DrawCircle(gx1,gy1,4.0*cell);
        else if(maxdev==100) memDC.DrawCircle(gx1,gy1,2.0*cell);
        else if(maxdev==150) memDC.DrawCircle(gx1,gy1,4.0*cell/3.0);
        else memDC.DrawCircle(gx1,gy1,1.0*cell);

        memDC.SetPen(wxPen(wxColor(20,20,20)));
        memDC.DrawLine(gx1-cell,gy1-4,gx1-cell,gy1+4);
        memDC.DrawLine(gx1-2*cell,gy1-4,gx1-2*cell,gy1+4);
        memDC.DrawLine(gx1-3*cell,gy1-4,gx1-3*cell,gy1+4);
        memDC.DrawLine(gx1-4*cell,gy1-4,gx1-4*cell,gy1+4);
        memDC.DrawLine(gx1+cell,gy1-4,gx1+cell,gy1+4);
        memDC.DrawLine(gx1+2*cell,gy1-4,gx1+2*cell,gy1+4);
        memDC.DrawLine(gx1+3*cell,gy1-4,gx1+3*cell,gy1+4);
        memDC.DrawLine(gx1+4*cell,gy1-4,gx1+4*cell,gy1+4);
        memDC.DrawLine(gx1-4,gy1-cell,gx1+4,gy1-cell);
        memDC.DrawLine(gx1-4,gy1-2*cell,gx1+4,gy1-2*cell);
        memDC.DrawLine(gx1-4,gy1-3*cell,gx1+4,gy1-3*cell);
        memDC.DrawLine(gx1-4,gy1-4*cell,gx1+4,gy1-4*cell);
        memDC.DrawLine(gx1-4,gy1+cell,gx1+4,gy1+cell);
        memDC.DrawLine(gx1-4,gy1+2*cell,gx1+4,gy1+2*cell);
        memDC.DrawLine(gx1-4,gy1+3*cell,gx1+4,gy1+3*cell);
        memDC.DrawLine(gx1-4,gy1+4*cell,gx1+4,gy1+4*cell);

        memDC.SetFont(eng1);
        if(maxdev>100) memDC.SetTextForeground(wxColor(255,0,0));
        else memDC.SetTextForeground(wxColor(28,28,28));

        memDC.DrawLabel(wxString::Format(_("%d"),maxdev),wxRect(gx1-4*cell,gy1+4,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(wxString::Format(_("%d"),maxdev),wxRect(gx1+4*cell,gy1+4,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
        memDC.DrawLabel(wxString::Format(_("%d"),maxdev),wxRect(gx1+4,gy1+4*cell,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(wxString::Format(_("%d"),maxdev),wxRect(gx1+4,gy1-4*cell,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        ///盾构机图形
        double x6;
        double y6;
        double x5;
        double y5;
        double ps=0.0;
        if(mtg->tbm.type==0)
        {
            x6=gx1+tailh*s;
            y6=gy1-tailv*s;
            x5=gx1+headh*s;
            y5=gy1-headv*s;
            /*if(abs(headh-tailh)>abs(headv-tailv))
            {
                ps=abs(headh-tailh)*1.0/maxdev;
            }
            else
            {
                ps=abs(headv-tailv)*1.0/maxdev;
            }*/
        }
        else
        {
            x6=gx1+midh*s;
            y6=gy1-midv*s;
            x5=gx1+headh*s;
            y5=gy1-headv*s;
            /*if(abs(headh-midh)>abs(headv-midv))
            {
                ps=abs(headh-midh)*1.0/maxdev;
            }
            else
            {
                ps=abs(headv-midv)*1.0/maxdev;
            }*/
        }
        ps=0.32;
        //if(ps>1.0) ps=1.0;

        double cor[4][2];
        double cor1[4][2];
        double cosa[3],sina[3];
        double ms[3];
        double rx[4]={0};
        double ry[4]={0};
        double rz[4]={0};
        double azi = atan(htrend/1000.0);
        double pitch = atan(vtrend/1000.0);
        double roll=mtg->m1.inc1[0]*PI/180.0;
        //trace(0,"metro:roll=%.4f,y=%.4f\n",mtg->m.inc1[0],vtrend);
        ms[0] = 6.0;
        ms[1] = 6.0;
        ms[2] = 6.0;
        if(fabs(pitch)>0.00872664625997165 && fabs(pitch)<=0.0174532925199433)
        {
            ms[1] = ms[1]-1.0*(fabs(pitch)-0.00872664625997165)/0.00872664625997165;
        }
        else if(fabs(pitch)>0.0174532925199433 && fabs(pitch)<=0.0261799387799149)
        {
            ms[1] = ms[1]-1.0-0.5*(fabs(pitch)-0.0174532925199433)/0.00872664625997165;
        }
        else if(fabs(pitch)>0.0261799387799149 && fabs(pitch)<=0.0349065850398866)
        {
            ms[1] = ms[1]-1.0-0.5-0.5*(fabs(pitch)-0.0261799387799149)/0.00872664625997165;
        }
        else if(fabs(pitch)>0.0349065850398866 && fabs(pitch)<=0.0436332312998582)
        {
            ms[1] = ms[1]-1.0-0.5-0.5-0.5*(fabs(pitch)-0.0349065850398866)/0.00872664625997165;
        }
        else if(fabs(pitch)>0.0436332312998582 && fabs(pitch)<=0.0523598775598299)
        {
            ms[1] = ms[1]-1.0-0.5-0.5-0.5-0.5*(fabs(pitch)-0.0436332312998582)/0.00872664625997165;
        }
        else if(fabs(pitch) > 0.0523598775598299)
        {
            ms[1] = 3.0;
        }
        cosa[1] = cos(pitch*ms[1]);
        sina[1] = sin(pitch*ms[1]);

        if(fabs(roll)>0.00872664625997165 && fabs(roll)<=0.0174532925199433)
        {
            ms[0] = ms[0]-1.0*(fabs(roll)-0.00872664625997165)/0.00872664625997165;
        }
        else if(fabs(roll)>0.0174532925199433 && fabs(roll)<=0.0261799387799149)
        {
            ms[0] = ms[0]-1.0-0.5*(fabs(roll)-0.0174532925199433)/0.00872664625997165;
        }
        else if(fabs(roll)>0.0261799387799149 && fabs(roll)<=0.0349065850398866)
        {
            ms[0] = ms[0]-1.0-0.5-0.5*(fabs(roll)-0.0261799387799149)/0.00872664625997165;
        }
        else if(fabs(roll)>0.0349065850398866 && fabs(roll)<=0.0436332312998582)
        {
            ms[0] = ms[0]-1.0-0.5-0.5-0.5*(fabs(roll)-0.0349065850398866)/0.00872664625997165;
        }
        else if(fabs(roll)>0.0436332312998582 && fabs(roll)<=0.0523598775598299)
        {
            ms[0] = ms[0]-1.0-0.5-0.5-0.5-0.5*(fabs(roll)-0.0436332312998582)/0.00872664625997165;
        }
        else if(fabs(roll) > 0.0523598775598299)
        {
            ms[0] = 3.0;
        }
        cosa[0] = cos(roll*ms[0]);
        sina[0] = sin(roll*ms[0]);
        //trace(0,"fig1:roll=%.4f,ms=%.4f\n",roll,ms[0]);

        if(fabs(azi)>0.00872664625997165 && fabs(azi)<=0.0174532925199433)
        {
            ms[2] = ms[2]-1.0*(fabs(azi)-0.00872664625997165)/0.00872664625997165;
        }
        else if(fabs(azi)>0.0174532925199433 && fabs(azi)<=0.0261799387799149)
        {
            ms[2] = ms[2]-1.0-0.5*(fabs(azi)-0.0174532925199433)/0.00872664625997165;
        }
        else if(fabs(azi)>0.0261799387799149 && fabs(azi)<=0.0349065850398866)
        {
            ms[2] = ms[2]-1.0-0.5-0.5*(fabs(azi)-0.0261799387799149)/0.00872664625997165;
        }
        else if(fabs(azi)>0.0349065850398866 && fabs(azi)<=0.0436332312998582)
        {
            ms[2] = ms[2]-1.0-0.5-0.5-0.5*(fabs(azi)-0.0349065850398866)/0.00872664625997165;
        }
        else if(fabs(azi)>0.0436332312998582 && fabs(azi)<=0.0523598775598299)
        {
            ms[2] = ms[2]-1.0-0.5-0.5-0.5-0.5*(fabs(azi)-0.0436332312998582)/0.00872664625997165;
        }
        else if(fabs(azi) > 0.0523598775598299)
        {
            ms[2] = 3.0;
        }
        cosa[2] = cos(azi*ms[2]);
        sina[2] = sin(azi*ms[2]);

        rx[0] = 0.0;
        ry[0] = -1.5*cell-3.0*ps*cell;
        rz[0] = 0.0;
        rx[1] = 0.0;
        ry[1] = -ry[0];
        rz[1] = 0.0;
        rx[2] = -1.5*cell-3.0*ps*cell;
        ry[2] = 0.0;
        rz[2] = 0.0;
        rx[3] = -rx[2];
        ry[3] = 0.0;
        rz[3] = 0.0;
        //trace(0,"fig1:rx1=%.4f,tx2=%.4f,rx3=%.4f\n",rx[0],rx[1],rx[2]);
        //trace(0,"fig1:rx1=%.4f,tx2=%.4f,rx3=%.4f\n",ry[0],ry[1],ry[2]);
        //trace(0,"fig1:rx1=%.4f,tx2=%.4f,rx3=%.4f\n",rz[0],rz[1],rz[2]);
        ///转动角修正
        rx[0] = (1.5+3*ps)*cell*sina[0];
        ry[0] = -(1.5+3*ps)*cell*cosa[0];
        rx[1] = -rx[0];
        ry[1] = -ry[0];
        rx[2] = -(1.5+3*ps)*cell*cosa[0];
        ry[2] = -(1.5+3*ps)*cell*sina[0];
        rx[3] = -rx[2];
        ry[3] = -ry[2];
        //trace(0,"fig1:rx1=%.4f,tx2=%.4f,rx3=%.4f\n",rx[0],rx[1],rx[2]);
        //trace(0,"fig1:rx1=%.4f,tx2=%.4f,rx3=%.4f\n",ry[0],ry[1],ry[2]);
        //trace(0,"fig1:sina=%.4f,cosa=%.4f\n",sina[0],cosa[0]);
        ///方位角修正
        rx[0] = rx[0]*cosa[2];
        rz[0] = -rx[0]*sina[2];
        rx[1] = -rx[0];
        rz[1] = -rx[1]*sina[2];
        rx[2] = rx[2]*cosa[2];
        rz[2] = -rx[2]*sina[2];
        rx[3] = -rx[2];
        rz[3] = -rx[3]*sina[2];
        ///俯仰角修正
        rx[0] = rx[0]+ry[0]*sina[1]*sina[2];
        rz[0] = rz[0]+ry[0]*sina[1]*cosa[2];
        ry[0] = ry[0]*cosa[1];
        rx[1] = rx[1]+ry[1]*sina[1]*sina[2];
        rz[1] = rz[1]+ry[1]*sina[1]*cosa[2];
        ry[1] = -ry[0];
        rx[2] = rx[2]+ry[2]*sina[1]*sina[2];
        rz[2] = rz[2]+ry[2]*sina[1]*cosa[2];
        ry[2] = ry[2]*cosa[1];
        rx[3] = rx[3]+ry[3]*sina[1]*sina[2];
        rz[3] = rz[3]+ry[3]*sina[1]*cosa[2];
        ry[3] = -ry[2];

        ///up
        cor[0][0]=x6+rx[0];
        cor[0][1]=y6+ry[0];
        ///down
        cor[1][0]=x6+rx[1];
        cor[1][1]=y6+ry[1];
        ///left
        cor[2][0]=x6+rx[2];
        cor[2][1]=y6+ry[2];
        ///right
        cor[3][0]=x6+rx[3];
        cor[3][1]=y6+ry[3];


        wxBrush posBrush[4];
        //posBrush[0]=wxBrush(wxColor(254,254,0));
        //posBrush[1]=wxBrush(wxColor(234,234,0));
        //posBrush[2]=wxBrush(wxColor(214,214,0));
        //posBrush[3]=wxBrush(wxColor(194,194,0));
        posBrush[0]=wxBrush(wxColor(110,140,155));
        posBrush[1]=wxBrush(wxColor(100,120,135));
        posBrush[2]=wxBrush(wxColor(80,100,110));
        posBrush[3]=wxBrush(wxColor(85,105,115));
        //wxPen posPen(wxColor(0,0,204));
        wxPen posPen(wxColor(58,68,88));
        //memDC.SetPen(posPen);
        int index[4]={0,1,2,3};
        double a,b;
        a = (y5-y6)*1.0/(x5-x6);
        b = y5-a*x5;
        h1 = a*cor[2][0]+b;
        if(x5<x6)
        {
            if(y5<y6)
            {
                if(h1>cor[2][1])
                {
                    index[0]=0;
                    index[1]=2;
                    index[2]=3;
                    index[3]=1;
                }
                else
                {
                    index[0]=1;
                    index[1]=3;
                    index[2]=0;
                    index[3]=2;
                }
            }
            else
            {
                if(h1>cor[2][1])
                {
                    index[0]=0;
                    index[1]=3;
                    index[2]=2;
                    index[3]=1;
                }
                else
                {
                    index[0]=3;
                    index[1]=1;
                    index[2]=2;
                    index[3]=0;
                }
            }
        }
        else
        {
            if(y5<y6)
            {
                if(h1>cor[2][1])
                {
                    index[0]=1;
                    index[1]=2;
                    index[2]=0;
                    index[3]=3;
                }
                else
                {
                    index[0]=2;
                    index[1]=0;
                    index[2]=1;
                    index[3]=3;
                }
            }
            else
            {
                if(h1>cor[2][1])
                {
                    index[0]=2;
                    index[1]=0;
                    index[2]=1;
                    index[3]=3;
                }
                else
                {
                    index[0]=0;
                    index[1]=2;
                    index[2]=1;
                    index[3]=3;
                }
            }
        }

        //up
        rx[0]=(cor[0][0]-x6)*1/5;
        ry[0]=(cor[0][1]-y6)*1/5;
        //down
        rx[1]=(cor[1][0]-x6)*1/5;
        ry[1]=(cor[1][1]-y6)*1/5;
        //left
        rx[2]=(cor[2][0]-x6)*1/5;
        ry[2]=(cor[2][1]-y6)*1/5;
        //right
        rx[3]=(cor[3][0]-x6)*1/5;
        ry[3]=(cor[3][1]-y6)*1/5;

        double px[4];
        double py[4];
        for(int i=0;i<4;i++)
        {
            int j=index[i];
            px[i]=cor[j][0];
            py[i]=cor[j][1];
        }

        memDC.SetPen(wxPen(wxColor(215,57,28),3));
        memDC.DrawLine(rx[0]+x5,ry[0]+y5,rx[1]+x5,ry[1]+y5);
        memDC.DrawLine(rx[2]+x5,ry[2]+y5,rx[3]+x5,ry[3]+y5);
        //trace(0,"fig1:%.1f,%.1f,%.1f,%.1f\n",rx[0],ry[0],rx[1],ry[1]);
        //trace(0,"fig1:%.1f,%.1f,%.1f,%.1f\n",rx[2],ry[2],rx[3],ry[3]);
        memDC.SetPen(posPen);
        wxPoint tbm_pts[3];
        tbm_pts[1].x=x6;
        tbm_pts[1].y=y6;
        tbm_pts[2].x=x5;
        tbm_pts[2].y=y5;
        for(int i=0;i<4;i++)
        {
            int j=index[i];
            //if(i==1) continue;
            memDC.SetBrush(posBrush[j]);
            tbm_pts[0].x=px[i];
            tbm_pts[0].y=py[i];
            if(mtg->iset.tbm3d==0) memDC.DrawPolygon(3,tbm_pts);
        }

        memDC.SetPen(wxPen(wxColor(0,1,219),3));
        memDC.DrawLine(rx[0]+x6,ry[0]+y6,rx[1]+x6,ry[1]+y6);
        memDC.DrawLine(rx[2]+x6,ry[2]+y6,rx[3]+x6,ry[3]+y6);
        //trace(0,"fig1:%.1f,%.1f,%.1f,%.1f\n",rx[0]+x6,ry[0]+y6,rx[1]+x6,ry[1]+y6);
        //trace(0,"fig1:%.1f,%.1f,%.1f,%.1f\n",rx[2]+x6,ry[2]+y6,rx[3]+x6,ry[3]+y6);
        /*if(mtg->iset.idrv==1)
        {
            memDC.SetPen(wxPen(wxColor(255,0,0)));
            memDC.SetBrush(*wxWHITE_BRUSH);
            x5=gx1-r[0]+15;
            y5=gy1;
            memDC.DrawCircle(x5,y5,15);

            x5=gx1+r[0]-15;
            y5=gy1;
            memDC.DrawCircle(x5,y5,15);

            x5=gx1;
            y5=gy1-r[0]+15;
            memDC.DrawCircle(x5,y5,15);

            x5=gx1;
            y5=gy1+r[0]-15;
            memDC.DrawCircle(x5,y5,15);
        }*/

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyHistoryDlg::OnPaintMetroFig2(wxPaintEvent& event)
{
    wxPaintDC dc(metroFig2);
    int w,h;
    metroFig2->GetClientSize(&w,&h);
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
        ///字体
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng1(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        wxFont eng2(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=h/2;
        PaintHorizon(&memDC, wxRect(x1,y1,w1,h1),maxdev);
        y1=h/2;
        PaintVertical(&memDC, wxRect(x1,y1,w1,h1),maxdev);

        ///偏差及趋势
        memDC.SetBrush(wxBrush(wxColor(204,233,177)));
        memDC.SetPen(wxPen(wxColor(204,233,177)));
        memDC.SetTextForeground(wxColor(28,28,28));
        memDC.SetFont(chs);
        y1=0;
        if(mtg->tbm.type==0)
        {
            memDC.DrawLabel(_("切口 "),wxRect(x1+w1*1/2+32,y1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("盾尾 "),wxRect(x1+32,y1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("水平偏航"),wxRect(x1+32,y1+h1-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("切口 "),wxRect(x1+w1*1/2+32,y1+h1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("盾尾 "),wxRect(x1+32,y1+h1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("垂直偏航"),wxRect(x1+32,y1+h1*2-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetTextForeground(wxColor(0,0,0));
            memDC.SetFont(eng2);
            memDC.DrawLabel(wxString::Format(_("%d"),headh),wxRect(x1+w1/2+80,y1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),tailh),wxRect(x1+80,y1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),headv),wxRect(x1+w1/2+80,y1+h1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),tailv),wxRect(x1+80,y1+h1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            memDC.SetFont(eng1);
            if(tbmlen==0.0)
            {
                memDC.DrawLabel(wxString::Format(_("%d"),0.0)+_(" mm/m"),wxRect(x1+w1/2+32,y1+h1-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%d"),0.0)+_(" mm/m"),wxRect(x1+w1/2+32,y1+h1+h1-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(wxString::Format(_("%.1f"),htrend)+_(" mm/m"),wxRect(x1+w1/2+32,y1+h1-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%.1f"),vtrend)+_(" mm/m"),wxRect(x1+w1/2+32,y1+h1+h1-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            memDC.DrawLabel(_("前"),wxRect(x1+w1*2/3+10,y1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("中"),wxRect(x1+w1/3+10,y1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("后"),wxRect(x1+10,y1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("水平偏航"),wxRect(x1+10,y1+h1-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("前"),wxRect(x1+w1*2/3+10,y1+h1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("中"),wxRect(x1+w1/3+10,y1+h1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("后"),wxRect(x1+10,y1+h1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("垂直偏航"),wxRect(x1+10,y1+h1*2-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetFont(eng2);
            memDC.DrawLabel(wxString::Format(_("%d"),headh),wxRect(x1+w1*2/3+32,y1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),midh),wxRect(x1+w1/3+32,y1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),tailh),wxRect(x1+32,y1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),headv),wxRect(x1+w1*2/3+32,y1+h1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),midv),wxRect(x1+w1/3+32,y1+h1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%d"),tailv),wxRect(x1+32,y1+h1+10,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.SetFont(eng1);

            if(tbmlen==0.0)
            {
                memDC.DrawLabel(wxString::Format(_("%d"),0.0)+_(" mm/m"),wxRect(x1+w1/2+32,y1+h1-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%d"),0.0)+_(" mm/m"),wxRect(x1+w1/2+32,y1+h1+h1-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(wxString::Format(_("%.1f"),htrend)+_(" mm/m"),wxRect(x1+w1/2+32,y1+h1-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.DrawLabel(wxString::Format(_("%.1f"),vtrend)+_(" mm/m"),wxRect(x1+w1/2+32,y1+h1+h1-15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyHistoryDlg::OnPaintMetroFig3(wxPaintEvent& event)
{
    wxPaintDC dc(metroFig3);
    int w,h;

    metroFig3->GetClientSize(&w,&h);
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
        ///字体
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont eng1(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        wxFont eng2(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);

        wxString valstr;

        ///环号
        int x1,y1,w1,h1;
        x1=-1;
        y1=0;
        w1=w;
        h1=h/4;
        memDC.SetPen(wxPen(wxColor(105,105,105)));
        memDC.SetBrush(wxBrush(wxColor(248,248,248)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        int gx1,gy1,gw1,gh1;
        gx1=10;
        gy1=15;
        gw1=w1-10-10;
        gh1=35;

        memDC.DrawRoundedRectangle(gx1,gy1,gw1,gh1,3);

        //memDC.SetPen(wxPen(wxColor(140,144,147)));
        //memDC.DrawRoundedRectangle(gx1,gy1,gw1,gh1,3);
        memDC.SetFont(eng2);
        memDC.SetTextForeground(wxColor(25,35,45));
        memDC.DrawLabel(wxString::Format(_("%d"),res[0].iseg)+_(" 环"),wxRect(gx1,gy1,gw1,gh1),wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        /*int gx2,gy2,gw2,gh2;
        gx2=10;
        gy2=60;
        gw2=w1-20;
        gh2=h1-75;
        memDC.SetPen(wxPen(wxColor(140,144,147)));
        memDC.SetBrush(wxBrush(wxColor(212,218,224)));
        memDC.DrawRectangle(gx2,gy2,gw2,gh2);

        double per = mtg->snum.tm;
        if(per>mtg->segset.L*2.0) per=0.0;
        memDC.SetFont(eng1);
        valstr=wxString::Format(_("%d"),(int)(per*1000.0));
        per = per/mtg->segset.L;
        if(per>1.0) per=1;
        memDC.SetPen(wxPen(wxColor(234,251,230)));
        memDC.SetBrush(wxBrush(wxColor(234,251,230)));
        gx2=gx2+1;
        gy2=gy2+1;
        gw2=gw2-2;
        gh2=gh2-2;
        memDC.DrawRectangle(gx2,gy2,gw2*per,gh2);
        memDC.DrawLabel(valstr,wxRect(gx2,gy2,gw2,gh2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);*/

        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        ///转动角
        y1 = y1+h1;
        memDC.SetPen(wxPen(wxColor(105,105,105)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(28,28,28));
        memDC.DrawLabel(_("转动角"),wxRect(x1,y1,w1,30),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetFont(eng1);
        if(mtg->iset.unit==0)
        {
            memDC.DrawLabel(_("[ mm/m ]"),wxRect(x1,y1+15,w1,35),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("[  °  ]"),wxRect(x1,y1+15,w1,35),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetFont(eng2);
        memDC.SetTextForeground(wxColor(25,35,45));
        if(mtg->iset.unit==0)
        {
            memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->m1.inc1[0]*PI/180.0)*1000.0),wxRect(x1,y1+33,w1,h1-33),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->m1.inc1[0]),wxRect(x1,y1+33,w1,h1-33),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }


        ///俯仰角
        y1 = y1+h1;
        memDC.SetPen(wxPen(wxColor(105,105,105)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(28,28,28));
        memDC.DrawLabel(_("俯仰角"),wxRect(x1,y1,w1,30),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetFont(eng1);
        if(mtg->iset.unit==0)
        {
            memDC.DrawLabel(_("[ mm/m ]"),wxRect(x1,y1+15,w1,35),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("[  °  ]"),wxRect(x1,y1+15,w1,35),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetFont(eng2);
        memDC.SetTextForeground(wxColor(25,35,45));
        if(mtg->iset.unit==0)
        {
            memDC.DrawLabel(wxString::Format(_("%.1f"),tan(mtg->m1.inc1[1]*PI/180.0)*1000.0),wxRect(x1,y1+33,w1,h1-33),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(wxString::Format(_("%.2f"),mtg->m1.inc1[1]),wxRect(x1,y1+33,w1,h1-33),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        y1 = y1+h1;
        memDC.SetPen(wxPen(wxColor(112,112,112)));
        memDC.SetBrush(wxBrush(wxColor(248,248,248)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(28,28,28));
        memDC.DrawLabel(_("切口里程"),wxRect(x1,y1,w1,30),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLabel(_("盾尾里程"),wxRect(x1,y1+50,w1,30),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetFont(eng1);
        memDC.DrawLabel(wxString::Format(_("%.2f"),headc),wxRect(x1,y1+25,w1,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.DrawLabel(wxString::Format(_("%.2f"),tailc),wxRect(x1,y1+75,w1,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyHistoryDlg::PaintHorizon(wxMemoryDC* memDC, wxRect rect,double ds)
{
    int x,y;
	x = rect.x;
	y = rect.y;
    int w,h;

    w = rect.width;
	h = rect.height;
    //FILE* fp = fopen("E:\\painthorizon.log","w");
	ds = h/6/ds;

	int nh = road_number_horizon(&mtg->r);

    memDC->SetPen(wxPen(wxColor(112,112,112)));
    memDC->SetBrush(wxBrush(wxColor(248,248,248)));
    memDC->DrawRectangle(x,y,w,h-1);
    double d1,d2,pds;
    if(mtg->m1.t1>0)
    {
        d1 = fabs(midc-tailc);
        d2 = fabs(headc-midc);
        //d2 = (mtg->m0.tail[0]-mtg->m0.mid[0])*(mtg->m0.tail[0]-mtg->m0.mid[0])+(mtg->m0.tail[1]-mtg->m0.mid[1])*(mtg->m0.tail[1]-mtg->m0.mid[1])+(mtg->m0.tail[2]-mtg->m0.mid[2])*(mtg->m0.tail[2]-mtg->m0.mid[2]);
        //d2 = sqrt(d2);
        pds = d2/(d1+d2);
        //pds=0.0;
    }
    else
    {
        d1=mtg->tbm.L[3];
        d2=mtg->tbm.L[0]-mtg->tbm.L[3];
        pds = d2/(d1+d2);
    }
    //fprintf(fp,"%.4f,%.4f,%.4f\n",d1,d2,pds);
    //fflush(fp);
    ///??????
    int w1=w*1/4;
    int h1=y+h/2;
    int w2=w*3/4;
    int h2=y+h/2;
    int w3=w1+w/2*pds;
    int h3=y+h/2;

    //mtg->m1.headc=22992.493;
    ///????200?
    double l1,l2;
    if(mtg->m1.t1<=0)
    {
        if(mtg->prj.a2z==1)
        {
            l1 = mtg->prj.mile1-25.0;
            l2 = l1+50.0;
        }
        else
        {
            l1 = mtg->prj.mile2+25;
            l2 = l1-50.0;
        }
    }
    else
    {
        if(mtg->prj.a2z==1)
        {
            l1 = mtg->m1.headc-25.0;
            l2 = l1+50.0;
        }
        else
        {
            l1 = mtg->m1.headc+25.0;
            l2 = l1-50.0;
        }
    }

    double x1=0.0,y1=0.0,x2=0.0,y2=0.0,x3=0.0,y3=0.0;
    double alf=0.0,alf1=0.0,alf2=0.0;

    if(nh>2)
    {
        road_l2xy(&mtg->r,l1,&x1,&y1,0);
        road_l2xy(&mtg->r,l2,&x2,&y2,0);

        alf1 = atan2(y2-y1,x2-x1);
        if(alf1<0.0) alf1 = alf1+2.0*PI;
        double li=l1;
        double s=w/50.0;
        wxPoint lines[60];
        int nlines=0;
        double len = 0.0;
        h_element* e;
        int hi;
        e = road_horizon_chain(&mtg->r,li,&hi);

        while(1)
        {
            if(nlines>59) break;
            e = road_horizon(&mtg->r,hi);

            if(e)
            {
                //fprintf(fp,"%d,%d\n",nlines,hi);
                //if(nlines>0) fprintf(fp,"%d,%.4f,%d,%d\n",nlines,li,lines[nlines-1].x,lines[nlines-1].y);
                if(e->type==ROAD_TYPE_START_POINT)
                {
                    lines[nlines].x = x;
                    lines[nlines].y = y+h/2;
                    nlines++;
                    if(mtg->prj.a2z==1)
                    {
                        hi++;
                    }
                    else
                    {
                        road_l2xy(&mtg->r,l2,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        if(alf<-PI/2.0) alf=alf+PI;
                        if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        nlines++;
                        break;
                    }
                    //fprintf(fp,"%d,%.4f,%.4f\n",nlines,lines[nlines-1].x,lines[nlines-1].y);
                }
                else if(e->type==ROAD_TYPE_LINE)
                {
                    if(mtg->prj.a2z==1)
                    {
                        road_l2xy(&mtg->r,li,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        if(alf<-PI/2.0) alf=alf+PI;
                        if(alf>PI/2.0) alf=alf-PI;

                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        nlines++;
                        //fprintf(fp,"%d,%d,%d\n",nlines,lines[nlines].x,lines[nlines].y);
                        if(l2>e->l1+e->length)
                        {
                            //x2 = e->x2;
                            //y2 = e->y2;
                            if(mtg->prj.a2z==1)
                                road_l2xy(&mtg->r,e->l1+e->length,&x2,&y2,0);
                            else
                                road_l2xy(&mtg->r,e->l1+e->length,&x2,&y2,0);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            if(alf<-PI/2.0) alf=alf+PI;
                            if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            hi++;
                            li = e->l1+e->length;
                        }
                        else
                        {
                            road_l2xy(&mtg->r,l2,&x2,&y2,0);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            if(alf<-PI/2.0) alf=alf+PI;
                            if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            //fprintf(fp,"%d,%d,%d\n",nlines,lines[nlines].x,lines[nlines].y);
                            break;
                        }
                    }
                    else
                    {
                        road_l2xy(&mtg->r,li,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        if(alf<-PI/2.0) alf=alf+PI;
                        if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;

                        nlines++;

                        if(l2<e->l1)
                        {
                            //x2 = e->x1;
                            //y2 = e->y1;
                            road_l2xy(&mtg->r,e->l1,&x2,&y2,0);

                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            if(alf<-PI/2.0) alf=alf+PI;
                            if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            hi--;
                            li = e->l1;
                        }
                        else
                        {
                            road_l2xy(&mtg->r,l2,&x2,&y2,0);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            alf=alf2-alf1;
                            if(alf<-PI/2.0) alf=alf+PI;
                            if(alf>PI/2.0) alf=alf-PI;
                            x2 = x+len*cos(alf);
                            y2 = y+h/2+len*sin(alf)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            break;
                        }
                    }
                }
                else if(e->type==ROAD_TYPE_ARC || e->type==ROAD_TYPE_SPIRAL)
                {
                    if(road_l2xy(&mtg->r,li,&x2,&y2,0)>=0)
                    {
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        if(alf<-PI/2.0) alf=alf+PI;
                        if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;

                        if(lines[nlines].x == x+w)
                        {
                            nlines++;
                            break;
                        }
                        else if(lines[nlines].x > x+w)
                        {
                            lines[nlines].y = lines[nlines].y+(lines[nlines].y-lines[nlines-1].y)*(x+w-lines[nlines-1].x)/(lines[nlines].x-lines[nlines-1].x);
                            lines[nlines].x = x+w;
                            nlines++;
                            break;
                        }
                        nlines++;
                    }
                    if(mtg->prj.a2z==1)
                    {
                        li+=1;
                    }
                    else
                    {
                        li=li-1;
                    }
                }
                else if(e->type==ROAD_TYPE_END_POINT)
                {
                    if(mtg->prj.a2z==-1)
                    {
                        hi--;
                    }
                    else
                    {
                        road_l2xy(&mtg->r,l2,&x2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        alf=alf2-alf1;
                        if(alf<-PI/2.0) alf=alf+PI;
                        if(alf>PI/2.0) alf=alf-PI;
                        x2 = x+len*cos(alf);
                        y2 = y+h/2+len*sin(alf)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        nlines++;
                        break;
                    }
                }
            }
        }

        if(nlines>0)
        {
            int i1=0;
            for(int i=0;i<nlines-1;i++)
            {
                memDC->SetPen(wxPen(wxColor(255,255,255),1));
                memDC->SetPen(wxPen(wxColor(58,58,58),1));
                memDC->DrawLine(lines[i].x,lines[i].y,lines[i+1].x,lines[i+1].y);

                if(lines[i].x<=x+w1 && lines[i+1].x>x+w1)
                {
                    h1 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w1-lines[i].x)/(lines[i+1].x-lines[i].x);
                }

                if(lines[i].x<=x+w3 && lines[i+1].x>x+w3)
                {
                    h3 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w3-lines[i].x)/(lines[i+1].x-lines[i].x);
                }

                if(lines[i].x<=x+w2 && lines[i+1].x>x+w2)
                {
                    h2 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w2-lines[i].x)/(lines[i+1].x-lines[i].x);
                }
            }
        }
        else
        {
            memDC->DrawLine(x,y+h/2,x+w,y+h/2);
            h1 = y+h/2;
            h2 = y+h/2;
            h3 = y+h/2;
        }
    }
    else
    {
        memDC->DrawLine(x,y+h/2,x+w,y+h/2);
        h1 = y+h/2;
        h2 = y+h/2;
        h3 = y+h/2;
    }

    if(mtg->m1.t1>0)
    {
        h1 = h1+tailh*ds;
        h2 = h2+headh*ds;
        h3 = h3+midh*ds;
        //if(fabs(mtg->m1.midh)>0.5) mtg->m1.midh = (mtg->m1.headh+mtg->m1.tailh)/2.0;
        //h3 = h3+mtg->m1.midh*1000*ds;
    }
    else
    {
        h1 = y+h/2;
        h2 = y+h/2;
        h3 = y+h/2;
    }

    int w4,h4;
    int dw1=15;
    int dh1;
    int dw2,dh2;
    double xd;
    wxPoint arrow[3];
    if(mtg->tbm.type>0)
    {
        xd = (w2-w3)*(w2-w3)+(h2-h3)*(h2-h3);
        xd = sqrt(xd);
        dh1 = (h3-h2)*dw1/xd;
        dw1 = (w3-w2)*dw1/xd;
        dw2 = dh1/3;
        dh2 = dw1/3;

        w4=x+w2+dw1;
        h4=h2+dh1;
        arrow[0].x=w4-dw2;
        arrow[0].y=h4-dh2;
        arrow[1].x=x+w2;
        arrow[1].y=h2;
        arrow[2].x=w4+dw2;
        arrow[2].y=h4+dh2;
    }
    else
    {
        xd = (w2-w1)*(w2-w1)+(h2-h1)*(h2-h1);
        xd = sqrt(xd);
        dh1 = (h1-h2)*dw1/xd;
        dw1 = (w1-w2)*dw1/xd;
        dw2 = dh1/3;
        dh2 = dw1/3;

        w4=x+w2+dw1;
        h4=h2+dh1;

        arrow[0].x=w4-dw2;
        arrow[0].y=h4-dh2;
        arrow[1].x=x+w2;
        arrow[1].y=h2;
        arrow[2].x=w4+dw2;
        arrow[2].y=h4+dh2;
    }

    memDC->SetPen(wxPen(wxColor(0,75,255)));
    memDC->SetBrush(wxBrush(wxColor(0,75,255)));
    memDC->DrawPolygon(3,arrow);

    if(mtg->tbm.type>0)
    {
        memDC->SetPen(wxPen(wxColor(0,75,255)));
        memDC->DrawLine(x+w1,h1,x+w3,h3);
        memDC->DrawLine(x+w3,h3,x+w2,h2);
        memDC->SetPen(wxPen(wxColor(255,0,0)));
        memDC->DrawLine(x+w3-dw2*3/2,h3-dh2*3/2-1,x+w3+dw2*3/2,h3+dh2*3/2);
    }
    else
    {
        memDC->SetPen(wxPen(wxColor(255,255,255)));
        memDC->SetPen(wxPen(wxColor(0,75,255)));
        memDC->DrawLine(x+w1,h1,x+w2,h2);
    }
    //fclose(fp);
}

void MyHistoryDlg::PaintVertical(wxMemoryDC* memDC, wxRect rect,double ds)
{
    int x,y;
	x = rect.x;
	y = rect.y;
    int w,h;
    w = rect.width;
	h = rect.height;
    ds=h/6/ds;
    //FILE* fp=fopen("E:\\PaintVertical.log","w");
    memDC->SetPen(wxPen(wxColor(112,112,112)));
    memDC->SetBrush(wxBrush(wxColor(248,248,248)));
    memDC->DrawRectangle(x,y+1,w,h-2);
    /*
    int r,g,b;
    int r2,g2,b2;
    int detr,detg,detb;
    detr=74-237;
    detg=144-254;
    detb=204-254;
    r=237;
    g=248;
    b=254;
    int ph=h/2-2;
    detr=detr/ph;
    detg=detg/ph;
    detb=detb/ph;
    for(int i=y+3;i<y+h-2;i++)
    {
        if(i<y+h/2)
        {
            r+=detr;
            g+=detg;
            b+=detb;
        }
        else
        {
            r-=detr;
            g-=detg;
            b-=detb;
        }
        memDC->SetPen(wxPen(wxColor(r,g,b),2));
        memDC->DrawLine(x+1,i,x+w-1,i);
    }*/


    double d1,d2,pds;
    if(mtg->m1.t1>0)
    {
        d1 = fabs(midc-tailc);
        d2 = fabs(headc-midc);
        //d2 = (mtg->m0.tail[0]-mtg->m0.mid[0])*(mtg->m0.tail[0]-mtg->m0.mid[0])+(mtg->m0.tail[1]-mtg->m0.mid[1])*(mtg->m0.tail[1]-mtg->m0.mid[1])+(mtg->m0.tail[2]-mtg->m0.mid[2])*(mtg->m0.tail[2]-mtg->m0.mid[2]);
        //d2 = sqrt(d2);
        pds = d2/(d1+d2);
    }
    else
    {
        d1=mtg->tbm.L[3];
        d2=mtg->tbm.L[0]-mtg->tbm.L[3];
        pds = d2/(d1+d2);
    }

    int nv = road_number_vertical(&mtg->r);

    int w1=w/4;
    int h1=y+h/2;
    int w2=w*3/4;
    int h2=y+h/2;
    int w3 = w1+w/2*d2/(d1+d2);
    int h3=y+h/2;
    ///????200?
    //mtg->m1.headc=22992.493;
    double l1,l2;
    if(mtg->m1.t1<=0)
    {
        if(mtg->prj.a2z==1)
        {
            l1 = mtg->prj.mile1-25.0;
            l2 = l1+50.0;
        }
        else
        {
            l1 = mtg->prj.mile2+25;
            l2 = l1-50.0;
        }
    }
    else
    {
        if(mtg->prj.a2z==1)
        {
            l1 = mtg->m1.headc-25.0;
            l2 = l1+50.0;
        }
        else
        {
            l1 = mtg->m1.headc+25.0;
            l2 = l1-50.0;
        }
    }

    double x1=0.0,y1=0.0,x2=0.0,y2=0.0,x3=0.0,y3=0.0;
    double alf=0.0,alf1=0.0,alf2=0.0;
    x1 = l1;

    if(nv>2)
    {
        double li=l1;
        double s=w/50.0;
        wxPoint lines[60];
        int nlines=0;
        double len = 0.0;
        int vi;
        v_element* e = road_vertical_chain(&mtg->r,li,&vi);
        road_l2h(&mtg->r,l1,&y1,&alf1);
        if(alf1<0.0) alf1 = alf1+2.0*PI;
        //fprintf(fp,"%d,%.4f,%.4f,%.12f\n",vi,li,y1,alf1);
        while(1)
        {
            if(nlines>59) break;
            e = road_vertical(&mtg->r,vi);
            if(e)
            {
                if(e->type==ROAD_TYPE_START_POINT)
                {
                    lines[nlines].x = x;
                    lines[nlines].y = y+h/2;
                    nlines++;
                    if(mtg->prj.a2z==1)
                    {
                        vi++;
                        li=e->l1;
                    }
                    else
                    {
                        break;
                    }
                }
                else if(e->type==ROAD_TYPE_LINE)
                {
                    if(mtg->prj.a2z==1)
                    {
                        x2 = li;
                        road_l2h(&mtg->r,li,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        x2 = x+len*cos(alf2);
                        y2 = y+h/2-len*sin(alf2)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        //fprintf(fp,"%d,%d,%d,%d,%.4f\n",nlines,lines[nlines].x,lines[nlines].y,x,li);
                        nlines++;

                        if(l2>e->l1+e->length)
                        {
                            x2 = e->l1+e->length;
                            y2 = e->h2;
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            x2 = x+len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            vi++;
                            li = e->l1+e->length;
                        }
                        else
                        {
                            x2 = l2;
                            road_l2h(&mtg->r,l2,&y2,0);
                            //fprintf(fp,"l2:%.4f,y2:%.4f\n",l2,y2);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;
                            //fprintf(fp,"%.4f,%.4f,%.4f\n",x2,y2,len);

                            x2 = x+len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            break;
                        }
                    }
                    else
                    {
                        x2 = li;
                        road_l2h(&mtg->r,li,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        //alf = mtg_sub_angle(alf2,alf1);
                        x2 = x-len*cos(alf2);
                        y2 = y+h/2-len*sin(alf2)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;

                        nlines++;
                        //fprintf(fp,"%.4f,%.4f\n",l2,e->l1);
                        if(l2<e->l1-e->length)
                        {
                            //wxMessageBox(_("ok"));
                            x2 = e->l1;
                            y2 = e->h1;
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            x2 = x-len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;
                            nlines++;
                            vi++;
                            li=e->l1;
                        }
                        else
                        {
                            x2 = l2;
                            road_l2h(&mtg->r,l2,&y2,0);
                            len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                            len = sqrt(len)*s;
                            alf2 = atan2(y2-y1,x2-x1);
                            if(alf2<0.0) alf2 = alf2+2.0*PI;

                            //alf = mtg_sub_angle(alf2,alf1);
                            x2 = x-len*cos(alf2);
                            y2 = y+h/2-len*sin(alf2)*2.0;

                            lines[nlines].x = x2;
                            lines[nlines].y = y2;

                            nlines++;
                            break;
                        }
                    }
                }
                else if(e->type==ROAD_TYPE_ARC)
                {
                    if(road_l2h(&mtg->r,li,&y2,0)>=0)
                    {
                        //fprintf(fp,"%.4f,%.4f\n",li,y2);
                        //fflush(fp);
                        x2 = li;
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;

                        x2 = x+fabs(len*cos(alf2));
                        y2 = y+h/2-len*sin(alf2)*2.0;
                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        //fprintf(fp,"%d,%d\n",lines[nlines].x,x+w);
                        //fflush(fp);
                        if(lines[nlines].x > x+w)
                        {
                            lines[nlines].y = lines[nlines].y+(lines[nlines].y-lines[nlines-1].y)*(x+w-lines[nlines-1].x)/(lines[nlines].x-lines[nlines-1].x);
                            lines[nlines].x = x+w;
                            nlines++;
                            break;
                        }
                        nlines++;
                    }
                    if(mtg->prj.a2z==1)
                    {
                        li+=1;
                    }
                    else
                    {
                        li=li-1;
                    }
                }
                else if(e->type==ROAD_TYPE_END_POINT)
                {
                    if(mtg->prj.a2z==1)
                    {
                        lines[nlines].x = x+w;
                        lines[nlines].y = y+h/2;
                        nlines++;
                        vi--;
                    }
                    else
                    {
                        x2 = l2;
                        road_l2h(&mtg->r,l2,&y2,0);
                        len = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                        len = sqrt(len)*s;
                        alf2 = atan2(y2-y1,x2-x1);
                        if(alf2<0.0) alf2 = alf2+2.0*PI;
                        //fprintf(fp,"%.4f,%.4f,%.4f\n",x2,y2,len);
                        //alf = mtg_sub_angle(alf2,alf1);
                        x2 = x+len*cos(alf2);
                        y2 = y+h/2-len*sin(alf2)*2.0;

                        lines[nlines].x = x2;
                        lines[nlines].y = y2;
                        nlines++;
                        break;
                    }
                }
            }
        }


        if(nlines>0)
        {
            for(int i=0;i<nlines-1;i++)
            {
                //if(lines[i].x>x && lines[i+1].x<x+w)
                {
                    //memDC->SetPen(wxPen(wxColor(255,255,255),1));
                    //memDC->DrawLine(lines[i].x,lines[i].y-1,lines[i+1].x,lines[i+1].y-1);
                    //memDC->DrawLine(lines[i].x,lines[i].y+1,lines[i+1].x,lines[i+1].y+1);
                    memDC->SetPen(wxPen(wxColor(58,58,58),1));
                    memDC->DrawLine(lines[i].x,lines[i].y,lines[i+1].x,lines[i+1].y);
                }

                //memDC->DrawLine(lines[i],lines[i+1]);

                if(lines[i].x<=x+w1 && lines[i+1].x>x+w1)
                {
                    h1 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w1-lines[i].x)/(lines[i+1].x-lines[i].x);
                }

                if(lines[i].x<=x+w2 && lines[i+1].x>x+w2)
                {
                    h2 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w2-lines[i].x)/(lines[i+1].x-lines[i].x);
                }

                if(lines[i].x<=x+w3 && lines[i+1].x>x+w3)
                {
                    h3 = lines[i].y+(lines[i+1].y-lines[i].y)*(x+w3-lines[i].x)/(lines[i+1].x-lines[i].x);
                }
            }
        }
        else
        {
            memDC->DrawLine(x,y+h/2,x+w,y+h/2);
            h1 = y+h/2;
            h2 = y+h/2;
            h3 = y+h/2;
        }
    }
    else
    {
        memDC->SetPen(wxPen(wxColor(58,58,58),1));
        memDC->DrawLine(x,y+h/2,x+w,y+h/2);
        h1 = y+h/2;
        h2 = y+h/2;
        h3 = y+h/2;
    }

    if(mtg->m1.t1>0)
    {
        h1 = h1-tailv*ds;
        h2 = h2-headv*ds;
        h3 = h3-midv*ds;
        //if(fabs(mtg->m1.midv)>0.5) mtg->m1.midv = (mtg->m1.headv+mtg->m1.tailv)/2.0;
        //h3 = h3 - mtg->m1.midv*1000*ds;
        //h3=0;
    }
    int w4,h4;
    int dw1=15;
    int dh1;
    int dw2,dh2;
    double xd;
    wxPoint arrow[3];
    if(mtg->tbm.type>0)
    {
        xd = (w2-w3)*(w2-w3)+(h2-h3)*(h2-h3);
        xd = sqrt(xd);
        dh1 = (h3-h2)*dw1/xd;
        dw1 = (w3-w2)*dw1/xd;
        dw2 = dh1/3;
        dh2 = dw1/3;
        //alf=atan2((double)(h2-h3),(double)(w2-w3))+PI/2;
        //wxMessageBox(wxString::Format(_("%.4f"),alf));
        w4=x+w2+dw1;
        h4=h2+dh1;
        arrow[0].x=w4-dw2;
        arrow[0].y=h4-dh2;
        arrow[1].x=x+w2;
        arrow[1].y=h2;
        arrow[2].x=w4+dw2;
        arrow[2].y=h4+dh2;
    }
    else
    {
        xd = (w2-w1)*(w2-w1)+(h2-h1)*(h2-h1);
        xd = sqrt(xd);
        dh1 = (h1-h2)*dw1/xd;
        dw1 = (w1-w2)*dw1/xd;
        dw2 = dh1/3;
        dh2 = dw1/3;
        //alf=atan2((double)(h2-h3),(double)(w2-w3))+PI/2;
        //wxMessageBox(wxString::Format(_("%.4f"),alf));
        w4=x+w2+dw1;
        h4=h2+dh1;
        arrow[0].x=w4-dw2;
        arrow[0].y=h4-dh2;
        arrow[1].x=x+w2;
        arrow[1].y=h2;
        arrow[2].x=w4+dw2;
        arrow[2].y=h4+dh2;
    }

    memDC->SetPen(wxPen(wxColor(0,75,255)));
    memDC->SetBrush(wxBrush(wxColor(0,75,255)));
    memDC->DrawPolygon(3,arrow);

    if(mtg->tbm.type>0)
    {
        //memDC->SetPen(wxPen(wxColor(255,255,255)));
        //memDC->DrawLine(x+w1,h1-1,x+w3,h3-1);
        //memDC->DrawLine(x+w1,h1+1,x+w3,h3+1);
        //memDC->DrawLine(x+w3,h3-1,x+w2,h2-1);
        //memDC->DrawLine(x+w3,h3+1,x+w2,h2+1);
        memDC->SetPen(wxPen(wxColor(0,75,255)));
        memDC->DrawLine(x+w1,h1,x+w3,h3);
        memDC->DrawLine(x+w3,h3,x+w2,h2);
        memDC->SetPen(wxPen(wxColor(255,0,0)));
        memDC->SetBrush(*wxTRANSPARENT_BRUSH);
        memDC->DrawLine(x+w3-dw2*3/2,h3-dh2*3/2-1,x+w3+dw2*3/2,h3+dh2*3/2);
    }
    else
    {
        memDC->SetPen(wxPen(wxColor(0,75,255)));
        memDC->DrawLine(x+w1,h1,x+w2,h2);
    }
    //fclose(fp);
}

void MyHistoryDlg::OnPaintBottom(wxPaintEvent& event)
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
        button[ID_HIS_QUIT].x=x1;
        button[ID_HIS_QUIT].y=y1;
        button[ID_HIS_QUIT].width=w1;
        button[ID_HIS_QUIT].height=h1;
        if(motion==ID_HIS_QUIT)
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

        /*x1=x1-w1-7;
        button[ID_HIS_EXP].x=x1;
        button[ID_HIS_EXP].y=y1;
        button[ID_HIS_EXP].width=w1;
        button[ID_HIS_EXP].height=h1;
        if(motion==ID_HIS_EXP)
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
        */
        x1=9;
        y1=9;
        h1=26;
        w1=h1*4/3;

        button[ID_HIS_PRT_SCN].x=x1;
        button[ID_HIS_PRT_SCN].y=y1;
        button[ID_HIS_PRT_SCN].width=w1;
        button[ID_HIS_PRT_SCN].height=h1;
        if(motion==ID_HIS_PRT_SCN)
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

        wxPoint pt[3];
        w1=65;
        double len=w1/7.0;
        x1=w/2-w1*2;

        x1=x1+w1-1;
        button[ID_HIS_PLAY_PREV].x=x1;
        button[ID_HIS_PLAY_PREV].y=y1;
        button[ID_HIS_PLAY_PREV].width=w1;
        button[ID_HIS_PLAY_PREV].height=h1;
        if(motion==ID_HIS_PLAY_PREV)
        {
            if(iplay==1)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                memDC.SetPen(ipen[0]);
                pt[0].x=x1+w1/2-len/2.0;
                pt[0].y=y1+h1/2-len/2.0;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawRectangle(pt[0].x,pt[0].y,3,len);
                pt[0].x+=len-4;
                //pt[0].y=y1+h1/2-len/2.0;
                //memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawRectangle(pt[0].x,pt[0].y,3,len);
            }
            else
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                memDC.SetPen(ipen[0]);
                pt[0].x=x1+w1/2-len/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x+len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
            }
            //pt[0].x=pt[0].x-len*0.866025404;
            //pt[1].x=pt[1].x-len*0.866025404;
            //pt[2].x=pt[2].x-len*0.866025404;
            //memDC.DrawPolygon(3,pt);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(motion==ID_HIS_PLAY_PREV)
            {
                memDC.SetPen(ipen[1]);
                memDC.DrawLine(x1,y1,x1,y1+h1);
                memDC.SetPen(ipen[0]);
            }
            if(iplay==1)
            {
                pt[0].x=x1+w1/2-len/2.0;
                pt[0].y=y1+h1/2-len/2.0;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawRectangle(pt[0].x,pt[0].y,3,len);
                pt[0].x+=len-4;
                //pt[0].y=y1+h1/2-len/2.0;
                //memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawRectangle(pt[0].x,pt[0].y,3,len);
            }
            else
            {
                pt[0].x=x1+w1/2-len/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x+len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
            }
            //pt[0].x=pt[0].x-len*0.866025404;
            //pt[1].x=pt[1].x-len*0.866025404;
            //pt[2].x=pt[2].x-len*0.866025404;
            //memDC.DrawPolygon(3,pt);
        }

        x1=x1+w1-1;
        button[ID_HIS_PLAY_NEXT].x=x1;
        button[ID_HIS_PLAY_NEXT].y=y1;
        button[ID_HIS_PLAY_NEXT].width=w1;
        button[ID_HIS_PLAY_NEXT].height=h1;
        if(motion==ID_HIS_PLAY_NEXT)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.SetPen(ipen[0]);
            if(iplay==2)
            {
                pt[0].x=x1+w1/2-len/2.0;
                pt[0].y=y1+h1/2-len/2.0;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawRectangle(pt[0].x,pt[0].y,3,len);
                pt[0].x+=len-4;
                //pt[0].y=y1+h1/2-len/2.0;
                //memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawRectangle(pt[0].x,pt[0].y,3,len);
            }
            else
            {
                pt[0].x=x1+w1/2+len/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x-len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
            }
            //pt[0].x=pt[0].x-len*0.866025404;
            //pt[1].x=pt[1].x-len*0.866025404;
            //pt[2].x=pt[2].x-len*0.866025404;
            //memDC.DrawPolygon(3,pt);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(motion==ID_HIS_PLAY_PREV)
            {
                memDC.SetPen(ipen[1]);
                memDC.DrawLine(x1,y1,x1,y1+h1);
                memDC.SetPen(ipen[0]);
            }
            if(iplay==2)
            {
                pt[0].x=x1+w1/2-len/2.0;
                pt[0].y=y1+h1/2-len/2.0;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawRectangle(pt[0].x,pt[0].y,3,len);
                pt[0].x+=len-4;
                //pt[0].y=y1+h1/2-len/2.0;
                //memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawRectangle(pt[0].x,pt[0].y,3,len);
            }
            else
            {
                pt[0].x=x1+w1/2+len/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x-len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
            }
            //pt[0].x=pt[0].x-len*0.866025404;
            //pt[1].x=pt[1].x-len*0.866025404;
            //pt[2].x=pt[2].x-len*0.866025404;
            //memDC.DrawPolygon(3,pt);
        }

        /*x1=x1+w1-1;
        button[ID_HIS_END].x=x1;
        button[ID_HIS_END].y=y1;
        button[ID_HIS_END].width=w1;
        button[ID_HIS_END].height=h1;
        if(lst==0)
        {
            if(motion==ID_HIS_END)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                memDC.SetPen(ipen[0]);
                pt[0].x=x1+w1/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x-len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
                pt[0].x=pt[0].x-len*0.866025404;
                pt[1].x=pt[1].x-len*0.866025404;
                pt[2].x=pt[2].x-len*0.866025404;
                memDC.DrawPolygon(3,pt);
                memDC.SetPen(wxPen(wxColor(0,0,0)));
                pt[0].y=pt[1].y+1;
                pt[1].x=pt[0].x;
                pt[1].y=pt[2].y;
                memDC.DrawLine(pt[0],pt[1]);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawRectangle(x1,y1,w1,h1);
                if(motion==ID_HIS_END)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.DrawLine(x1,y1,x1,y1+h1);
                    memDC.SetPen(ipen[0]);
                }
                pt[0].x=x1+w1/2;
                pt[0].y=y1+h1/2;
                pt[1].x=pt[0].x-len*0.866025404;
                pt[1].y=pt[0].y-len/2.0;
                pt[2].x=pt[1].x;
                pt[2].y=pt[1].y+len;
                memDC.SetBrush(wxBrush(wxColor(68,68,68)));
                memDC.DrawPolygon(3,pt);
                //pt[0].x=pt[0].x-len*0.866025404;
                //pt[1].x=pt[1].x-len*0.866025404;
                //pt[2].x=pt[2].x-len*0.866025404;
                //memDC.DrawPolygon(3,pt);
                memDC.SetPen(wxPen(wxColor(0,0,0)));
                pt[0].y=pt[1].y+1;
                pt[1].x=pt[0].x;
                pt[1].y=pt[2].y;
                memDC.DrawLine(pt[0],pt[1]);
            }
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(motion==ID_HIS_END)
            {
                memDC.SetPen(ipen[1]);
                memDC.DrawLine(x1,y1,x1,y1+h1);
                memDC.SetPen(ipen[0]);
            }
            pt[0].x=x1+w1/2;
            pt[0].y=y1+h1/2;
            pt[1].x=pt[0].x-len*0.866025404;
            pt[1].y=pt[0].y-len/2.0;
            pt[2].x=pt[1].x;
            pt[2].y=pt[1].y+len;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(117,117,117)));
            memDC.DrawPolygon(3,pt);
            //pt[0].x=pt[0].x-len*0.866025404;
            //pt[1].x=pt[1].x-len*0.866025404;
            //pt[2].x=pt[2].x-len*0.866025404;
            //memDC.DrawPolygon(3,pt);
            memDC.SetPen(wxPen(wxColor(0,0,0)));
            pt[0].y=pt[1].y+1;
            pt[1].x=pt[0].x;
            pt[1].y=pt[2].y;
            memDC.DrawLine(pt[0],pt[1]);
        }*/
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyHistoryDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_HIS_QUIT].y && y<button[ID_HIS_QUIT].y+button[ID_HIS_QUIT].height)
    {
        if(x>button[ID_HIS_QUIT].x && x<button[ID_HIS_QUIT].x+button[ID_HIS_QUIT].width)
        {
            motion=ID_HIS_QUIT;
        }
        else if(x>button[ID_HIS_EXP].x && x<button[ID_HIS_EXP].x+button[ID_HIS_EXP].width)
        {
            motion=ID_HIS_EXP;
        }
        else if(x>button[ID_HIS_PRT_SCN].x && x<button[ID_HIS_PRT_SCN].x+button[ID_HIS_PRT_SCN].width)
        {
            motion=ID_HIS_PRT_SCN;
        }
        else if(x>button[ID_HIS_PLAY_PREV].x && x<button[ID_HIS_PLAY_PREV].x+button[ID_HIS_PLAY_PREV].width)
        {
            motion=ID_HIS_PLAY_PREV;
        }
        else if(x>button[ID_HIS_PLAY_NEXT].x && x<button[ID_HIS_PLAY_NEXT].x+button[ID_HIS_PLAY_NEXT].width)
        {
            motion=ID_HIS_PLAY_NEXT;
        }
        else
        {
            motion=ID_HIS_NONE;
        }
    }
    else
    {
        motion=ID_HIS_NONE;
    }
    panelBottom->Refresh();
}

void MyHistoryDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_HIS_NONE;
    panelBottom->Refresh();
}

void MyHistoryDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_HIS_QUIT)
    {
        Destroy();
    }
    else if(motion==ID_HIS_PRT_SCN)
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
    else if(motion==ID_HIS_PLAY_NEXT)
    {
        if(iplay==2) iplay=0;
        else iplay=2;
    }
    else if(motion==ID_HIS_PLAY_PREV)
    {
        if(iplay==1) iplay=0;
        else iplay=1;
    }
    //panelBottom->Refresh();
}

void MyHistoryDlg::OnPaintMain(wxPaintEvent& event)
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

        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(0,h-1,w,h-1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyHistoryDlg::OnTimer(wxTimerEvent& event)
{
    static int tick=0;
    double l1,l2;
    tick++;
    if(tick % 20==0)
    {
        if(iplay==1)
        {
            if(dp1<nres-1)
            {
                if(dp1==0)
                {
                    dp1++;
                }
                else if(dp1==nres-1)
                {
                    if(mtg->prj.a2z==1 && res[dp1].mile1>res[0].mile1) dp1=0;
                    else if(mtg->prj.a2z==-1 && res[dp1].mile1<res[0].mile1) dp1=0;
                    else iplay=0;
                }
                else
                {
                    if(mtg->prj.a2z==1)
                    {
                        ///在有右侧
                        if(res[dp1].mile1>res[0].mile1 && res[dp1+1].mile1<res[dp1].mile1)
                        {
                            dp1++;
                        }
                        else if(res[dp1].mile1<res[0].mile1 && res[dp1+1].mile1<res[dp1].mile1)
                        {
                            dp1++;
                        }
                        else if(res[dp1].mile1>res[0].mile1)
                        {
                            dp1=0;
                        }
                        else
                        {
                            iplay=0;
                        }
                    }
                    else
                    {
                        if(res[dp1].mile1<res[0].mile1 && res[dp1+1].mile1>res[dp1].mile1)
                        {
                            dp1++;
                        }
                        else if(res[dp1].mile1>res[0].mile1 && res[dp1+1].mile1>res[dp1].mile1)
                        {
                            dp1++;
                        }
                        else if(res[dp1].mile1<res[0].mile1)
                        {
                            dp1=0;
                        }
                        else
                        {
                            iplay=0;
                        }
                    }
                }
            }
            else
            {
                iplay=0;
            }

            panelMetric->Refresh();
            panelGraph->Refresh();
        }
        else if(iplay==2)
        {
            if(dp1<nres-1)
            {
                if(dp1==0)
                {
                    dp1=nres-1;
                    //wxMessageBox(wxString::Format(_("%d,%d,%d"),dp1,dp3,nres));
                }
                else if(dp1==nres-1)
                {
                    if(mtg->prj.a2z==1 && res[dp1-1].mile1>res[dp1].mile1) dp1--;
                    else if(mtg->prj.a2z==-1 && res[dp1-1].mile1<res[dp1].mile1) dp1--;
                    else iplay=0;
                }
                else
                {
                    if(mtg->prj.a2z==1)
                    {
                        ///在有右侧
                        if(res[dp1].mile1>res[0].mile1 && res[dp1-1].mile1>res[dp1].mile1)
                        {
                            dp1--;
                        }
                        else if(res[dp1].mile1<res[0].mile1 && res[dp1-1].mile1>res[dp1].mile1)
                        {
                            dp1--;
                        }
                        else
                        {
                            iplay=0;
                        }
                    }
                    else
                    {
                        if(res[dp1].mile1>res[0].mile1 && res[dp1-1].mile1<res[dp1].mile1)
                        {
                            dp1--;
                        }
                        else if(res[dp1].mile1<res[0].mile1 && res[dp1-1].mile1<res[dp1].mile1)
                        {
                            dp1--;
                        }
                        else
                        {
                            iplay=0;
                        }
                    }
                }
            }
            else
            {
                iplay=0;
            }
            panelMetric->Refresh();
            panelGraph->Refresh();
            panelBottom->Refresh();
        }
    }
    if(tick == 1200) tick=0;
}
