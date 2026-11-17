///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DutyDlg.h"
#include "mtg_t_cliApp.h"
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
	//(*InternalHeadersPCH(DutyDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(DutyDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(DutyDlg)

//*)

DutyDlg::DutyDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	//int dh=20;
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
    drvList = new wxListView(listPanel, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    x2=x2+w2+15;
    w2=w-w2-45;
    textPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    textPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    textList = new wxListView(textPanel, wxID_ANY, wxPoint(0,24), wxSize(w2,h2/2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DutyDlg::OnPaintMain,0,this);

    listPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DutyDlg::OnPaintList,0,this);

    textPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DutyDlg::OnPaintText,0,this);

    drvList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&DutyDlg::OnDriverSelect,0,this);
    textList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&DutyDlg::OnTextSelect,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DutyDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DutyDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DutyDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DutyDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    int i=0;
    drvList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,0);
    drvList->InsertColumn(i++,_("人员"),wxLIST_FORMAT_CENTRE,115);

    i=0;
    textList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,45);
    textList->InsertColumn(i++,_("环号"),wxLIST_FORMAT_CENTRE,100);
    textList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,170);
    textList->InsertColumn(i++,_("时间"),wxLIST_FORMAT_CENTRE,180);

    int n=mtg->ndty;
    wxString str;
    i=0;
    while(i<n)
    {
        drvList->InsertItem(i,_(""));
        drvList->SetItem(i,1,wxString(mtg->duty[i].name,wxConvLocal));
        i++;
    }

    motion=ID_DUTY_NONE;
    dvr=mtg->onduty;
    drvList->Select(dvr);
    nms=0;
    nres=0;
    nres=mtg_query_duty(mtg,dvr,&res);
    txt=0;
    checkBoxWidth=14;
    checkBoxHeight=14;
    radioBoxR1=7;
    radioBoxR2=4;
    ///测试
    /*nres=1;
    res=(MTG_DUTY*)malloc(nres*sizeof(MTG_DUTY));
    time_t t1;
    time(&t1);

    res[0].t1=t1-1987200;
    res[0].t2=t1-1641600;
    res[0].seg1=193;
    res[0].seg2=207;
    res[0].mile1=39372.7574;
    res[0].mile2=39392.9485;
    res[0].mxdev=0.2;
    nms=0;
    if(ms) free(ms);
    nms=mtg_query_time(mtg,(long)res[0].t1,(long)res[0].t2,&ms);*/
}

DutyDlg::~DutyDlg()
{
    //trace(0,"DutyDlg:nres=%d,nms=%d\n",nres,nms);
    //if(res) free(res);
    //if(ms) free(ms);
}

void DutyDlg::UpdateText()
{
    int i=0;
    wxString str1;
    while(i<nres)
    {
        textList->InsertItem(i,wxString::Format(_("%d"),i+1));
        str1=wxString::Format(_("%d"),res[i].seg1)+_("～")+wxString::Format(_("%d"),res[i].seg2);
        textList->SetItem(i,1,str1);
        double l1=res[i].mile1;
        double l2=res[i].mile2;
        if(mtg->prj.a2z==1)
        {
            if(l2<=l1) l2=mtg->m1.headc;
        }
        else
        {
            if(l2>=l1) l2=mtg->m1.headc;
        }
        str1=wxString::Format(_("%.3f"),l1)+_("～")+wxString::Format(_("%.3f"),l2);
        textList->SetItem(i,2,str1);
        time_t t1,t2;
        t1=res[i].t1;
        t2=res[i].t2;
        if(t2<=t1) time(&t2);
        str1=wxDateTime(t1).Format(_("%Y-%m-%d %H:%M"))+_("～")+wxDateTime(t2).Format(_("%H:%M"));
        textList->SetItem(i,3,str1);
        i++;
    }
}

void DutyDlg::OnDriverSelect(wxListEvent& event)
{
    textList->DeleteAllItems();
    dvr=drvList->GetFirstSelected();
    nres=0;
    if(res) free(res);
    nres=mtg_query_duty(mtg,dvr,&res);
    UpdateText();
}

void DutyDlg::OnTextSelect(wxListEvent& event)
{
    txt=textList->GetFirstSelected();
    nms=0;
    time_t t1=res[txt].t1;
    time_t t2=res[txt].t2;
    if(t2<=t1) time(&t2);
    if(ms) free(ms);
    nms=mtg_query_time(mtg,t1,t2,&ms);
    //trace(0,"DutyDlg:nms=%d\n",nms);
    int w,h;
    textPanel->GetSize(&w,&h);
    textPanel->RefreshRect(wxRect(0,h/2,w,h/2));
}

void DutyDlg::OnPaintList(wxPaintEvent& event)
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
        str=_("作业人员");
        memDC.DrawLabel(str,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DutyDlg::OnPaintText(wxPaintEvent& event)
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
        int i=0;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

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
        time_t t1,t2;
        int n1,n2;
        double l1,l2;
        double mxh=0.0;
        double val;
        i=txt;
        wxString istr;

        if(nms>1)
        {
            for(int k=nms-1;k>0;k--)
            {
                val=fabs(ms[k].headh);
                if(val<0.5 && val>mxh) mxh=val;
                val=fabs(ms[k].headv);
                if(val<0.5 && val>mxh) mxh=val;
                val=fabs(ms[k].tailh);
                if(val<0.5 && val>mxh) mxh=val;
                val=fabs(ms[k].tailv);
                if(val<0.5 && val>mxh) mxh=val;
            }
        }

        if(nres>0)
        {
            t1=res[i].t1;
            t2=res[i].t2;
            n1=res[i].seg1;
            n2=res[i].seg2;
            l1=res[i].mile1;
            l2=res[i].mile2;
            mxh=mxh*1000.0+5.0;
            //trace(0,"DutyDlg:mxh=%.4f\n",mxh);
            if(mtg->prj.a2z==1)
            {
                if(l2<l1) l2=mtg->m.headc;
            }
            else
            {
                if(l2>l1) l2=mtg->m.headc;
            }
            if(t2<=t1) time(&t2);
            if(n2<=n1) n2=mtg->m.iseg;
        }
        else
        {
            time(&t1);
            time(&t2);
            n1=n2=0;
            l1=l2=mtg->m.headc;
            mxh=50.0;
        }
        istr=_("掘进管环：")+wxString::Format(_(" %d环    "),n1-n1);
        istr=istr+_("掘进里程：")+wxString::Format(_(" %.3f     "),l2-l1);
        istr=istr+_("时间：")+wxDateTime(t1).Format(_("%Y-%m-%d %H:%M:%S"))+_(" ～ ");
        istr=istr+wxDateTime(t2).Format(_("%Y-%m-%d %H:%M:%S"));
        memDC.DrawLabel(istr,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);


        ///偏差曲线图
        int x2,y2,w2,h2;
        x2=x1;
        y2=y1+h1+10;
        w2=w1;
        h2=h-h1-20-y2;
        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.DrawLine(x2,y2+h2/2,x2+w2,y2+h2/2);
        memDC.DrawLine(x2,y2,x2,y2+h2);
        h1=h2/4;
        x1=x2;
        y1=y2;
        w1=w2;
        memDC.SetPen(wxPen(wxColor(201,201,201),1,wxDOT));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLabel(wxString::Format(_("%.1f"),mxh),wxRect(x1-5,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1;
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLabel(wxString::Format(_("%.1f"),mxh/2.0),wxRect(x1-5,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("0"),wxRect(x1-7,y1+h1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1*2;
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLabel(wxString::Format(_("%.1f"),-mxh/2.0),wxRect(x1-5,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1;
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLabel(wxString::Format(_("%.1f"),-mxh),wxRect(x1-5,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

        ///注记
        w1=w2-80;
        x1=x2+40;
        y1=y1+20;
        memDC.SetPen(wxPen(wxColor(255,0,0)));
        memDC.SetBrush(wxBrush(wxColor(255,0,0)));
        memDC.DrawLine(x1,y1,x1+20,y1);
        memDC.DrawRectangle(x1+8,y1-2,5,5);
        memDC.DrawLabel(_("切口平面"),wxRect(x1+30,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/4;
        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.SetBrush(wxBrush(wxColor(0,0,255)));
        memDC.DrawLine(x1,y1,x1+20,y1);
        memDC.DrawRectangle(x1+8,y1-2,5,5);
        memDC.DrawLabel(_("切口高程"),wxRect(x1+30,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/4;
        memDC.SetPen(wxPen(wxColor(0,255,0)));
        memDC.SetBrush(wxBrush(wxColor(0,255,0)));
        memDC.DrawLine(x1,y1,x1+20,y1);
        memDC.DrawRectangle(x1+8,y1-2,5,5);
        memDC.DrawLabel(_("盾尾平面"),wxRect(x1+30,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1/4;
        memDC.SetPen(wxPen(wxColor(0,255,255)));
        memDC.SetBrush(wxBrush(wxColor(0,255,255)));
        memDC.DrawLine(x1,y1,x1+20,y1);
        memDC.DrawRectangle(x1+8,y1-2,5,5);
        memDC.DrawLabel(_("盾尾高程"),wxRect(x1+30,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        double xs,ys;
        long t3=(long)t1;
        long t4=(long)t2;
        xs=((double)t4-(double)t3)/(double)w2;
        ys=mxh/(h2*0.5);

        double hhx1,hhy1,hhx2,hhy2;
        double hvx1,hvy1,hvx2,hvy2;
        double thx1,thy1,thx2,thy2;
        double tvx1,tvy1,tvx2,tvy2;
        int vp=0;

        for(i=nms-1;i>0;i--)
        {
            //trace(0,"DutyDlg:headh=%.4f,headv=%.4f,tailh=%.4f,tailv=%.4f,mxh=%.4f\n",
                  //ms[i].headh,ms[i].headv,ms[i].tailh,ms[i].tailv,mxh);
            if(fabs(ms[i].headh*1000.0)>mxh) continue;
            if(fabs(ms[i].headv*1000.0)>mxh) continue;
            if(fabs(ms[i].tailh*1000.0)>mxh) continue;
            if(fabs(ms[i].tailv*1000.0)>mxh) continue;
            if(vp==0)
            {
                hhx1=x2+0.0;
                hhy1=y2+h2/2-ms[i].headh*1000.0/ys;

                hvx1=x2+0.0;
                hvy1=y2+h2/2-ms[i].headv*1000.0/ys;

                thx1=x2+0.0;
                thy1=y2+h2/2-ms[i].tailh*1000.0/ys;

                tvx1=x2+0.0;
                tvy1=y2+h2/2-ms[i].tailv*1000.0/ys;
                vp=1;
            }
            else
            {
                val=(long)ms[i].t1;
                hhx2=x2+fabs(val-t3)/xs;
                hhy2=y2+h2/2-ms[i].headh*1000.0/ys;

                hvx2=hhx2;
                hvy2=y2+h2/2-ms[i].headv*1000.0/ys;

                thx2=hhx1;
                thy2=y2+h2/2-ms[i].tailh*1000.0/ys;

                tvx2=hhx1;
                tvy2=y2+h2/2-ms[i].tailv*1000.0/ys;

                memDC.SetPen(wxPen(wxColor(255,0,0)));
                memDC.DrawLine(hhx1,hhy1,hhx2,hhy2);
                hhx1=hhx2;
                hhy1=hhy2;

                memDC.SetPen(wxPen(wxColor(0,0,255)));
                memDC.DrawLine(hvx1,hvy1,hvx2,hvy2);
                hvx1=hvx2;
                hvy1=hvy2;

                memDC.SetPen(wxPen(wxColor(0,255,0)));
                memDC.DrawLine(thx1,thy1,thx2,thy2);
                thx1=thx2;
                thy1=thy2;

                memDC.SetPen(wxPen(wxColor(0,255,255)));
                memDC.DrawLine(tvx1,tvy1,tvx2,tvy2);
                tvx1=tvx2;
                tvy1=tvy2;
            }
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DutyDlg::OnPaintBottom(wxPaintEvent& event)
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
        x1=w-w1-12;
        button[ID_DUTY_QUIT].x=x1;
        button[ID_DUTY_QUIT].y=y1;
        button[ID_DUTY_QUIT].width=w1;
        button[ID_DUTY_QUIT].height=h1;
        if(motion==ID_DUTY_QUIT)
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
        button[ID_DUTY_EXP].x=x1;
        button[ID_DUTY_EXP].y=y1;
        button[ID_DUTY_EXP].width=w1;
        button[ID_DUTY_EXP].height=h1;
        if(motion==ID_DUTY_EXP)
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
        memDC.DrawLabel(_("报告"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=9;
        y1=9;
        h1=26;
        w1=h1*4/3;

        button[ID_DUTY_PRT_SCN].x=x1;
        button[ID_DUTY_PRT_SCN].y=y1;
        button[ID_DUTY_PRT_SCN].width=w1;
        button[ID_DUTY_PRT_SCN].height=h1;
        if(motion==ID_DUTY_PRT_SCN)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
        }
        int x2,y2,w2,h2;
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

void DutyDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_DUTY_QUIT].y && y<button[ID_DUTY_QUIT].y+button[ID_DUTY_QUIT].height)
    {
        if(x>button[ID_DUTY_QUIT].x && x<button[ID_DUTY_QUIT].x+button[ID_DUTY_QUIT].width)
        {
            motion=ID_DUTY_QUIT;
        }
        else if(x>button[ID_DUTY_EXP].x && x<button[ID_DUTY_EXP].x+button[ID_DUTY_EXP].width)
        {
            motion=ID_DUTY_EXP;
        }
        else if(x>button[ID_DUTY_PRT_SCN].x && x<button[ID_DUTY_PRT_SCN].x+button[ID_DUTY_PRT_SCN].width)
        {
            motion=ID_DUTY_PRT_SCN;
        }
        else
        {
            motion=ID_DUTY_NONE;
        }
    }
    else
    {
        motion=ID_DUTY_NONE;
    }
    panelBottom->Refresh();
}

void DutyDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_DUTY_NONE;
    panelBottom->Refresh();
}

void DutyDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_DUTY_QUIT)
    {
        Destroy();
    }
    else if(motion==ID_DUTY_PRT_SCN)
    {
        //wxScreenDC DC;
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
        int i=drvList->GetFirstSelected();
        //str=wxString(mtg->duty[i].name,wxConvLocal);
        str=_("掘进界面");
        str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
        }
    }
    else if(motion==ID_DUTY_EXP)
    {
        int w,h;
        w=1123;
        h=764;
        wxBitmap m_memBit;
        m_memBit.Create(w,h);
        if(m_memBit.IsOk())
        {
            wxMemoryDC memDC;
            memDC.SelectObject(m_memBit);
            memDC.SetPen(wxPen(wxColor(135,135,135)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.DrawRectangle(0,0,w,h);
            wxFont chs(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
            wxFont chs1(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);

            int x1,y1,w1,h1;
            x1=96;
            y1=89;
            w1=931;
            h1=554;
            time_t t1,t2;
            int n1,n2;
            double l1,l2;
            double mxh=0.0;
            double val;
            int i=txt;
            wxString istr;
            if(nms>0)
            {
                for(int k=nms-1;k>0;k--)
                {
                    val=fabs(ms[k].headh);
                    if(val<0.5 && val>mxh) mxh=val;
                    val=fabs(ms[k].headv);
                    if(val<0.5 && val>mxh) mxh=val;
                    val=fabs(ms[k].tailh);
                    if(val<0.5 && val>mxh) mxh=val;
                    val=fabs(ms[k].tailv);
                    if(val<0.5 && val>mxh) mxh=val;
                }
            }

            if(nres>0)
            {
                t1=res[i].t1;
                t2=res[i].t2;
                n1=res[i].seg1;
                n2=res[i].seg2;
                l1=res[i].mile1;
                l2=res[i].mile2;
                mxh=mxh*1000.0+5.0;
                if(mtg->prj.a2z==1)
                {
                    if(l2<l1) l2=mtg->m.headc;
                }
                else
                {
                    if(l2>l1) l2=mtg->m.headc;
                }
                if(t2<=t1) time(&t2);
                if(n2<=n1) n2=mtg->m.iseg;
            }
            else
            {
                time(&t1);
                time(&t2);
                n1=n2=0;
                l1=l2=mtg->m.headc;
                mxh=50.0;
            }
            istr=_("掘进报告");
            memDC.SetFont(chs1);
            memDC.DrawLabel(istr,wxRect(x1,y1,w1,30),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.SetFont(chs);
            y1+=60;
            i=mtg->onduty;
            istr=_("作业人员：")+wxString(mtg->duty[i].name,wxConvLocal);
            memDC.DrawLabel(istr,wxRect(x1,y1,0,30),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            istr=_("管环：")+wxString::Format(_(" %d环 ～ %d环"),n1,n2);
            memDC.DrawLabel(istr,wxRect(x1+w1/3,y1,0,30),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            istr=_("里程：")+wxString::Format(_(" %.3f ～ %.3f"),l1,l2);
            memDC.DrawLabel(istr,wxRect(x1+w1*2/3,y1,0,30),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            y1+=45;
            istr=_("时间：")+wxDateTime(t1).Format(_("%Y-%m-%d %H:%M:%S"))+_(" ～ ");
            istr=istr+wxDateTime(t2).Format(_("%Y-%m-%d %H:%M:%S"));
            memDC.DrawLabel(istr,wxRect(x1,y1,0,30),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            int x2,y2,w2,h2;
            x2=x1;
            y2=y1+60;
            w2=w1;
            h2=h1-y2;
            memDC.SetPen(wxPen(wxColor(201,201,201)));
            memDC.DrawLine(x2,y2+h2/2,x2+w2,y2+h2/2);
            memDC.DrawLine(x2,y2,x2,y2+h2);

            h1=h2/4;
            x1=x2;
            y1=y2;
            w1=w2;
            memDC.SetPen(wxPen(wxColor(201,201,201),1,wxDOT));
            memDC.DrawLine(x1,y1,x1+w1,y1);
            memDC.DrawLabel(wxString::Format(_("%.1f"),mxh),wxRect(x1-5,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            y1=y1+h1;
            memDC.DrawLine(x1,y1,x1+w1,y1);
            memDC.DrawLabel(wxString::Format(_("%.1f"),mxh/2.0),wxRect(x1-5,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("0"),wxRect(x1-7,y1+h1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            y1=y1+h1*2;
            memDC.DrawLine(x1,y1,x1+w1,y1);
            memDC.DrawLabel(wxString::Format(_("%.1f"),-mxh/2.0),wxRect(x1-5,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            y1=y1+h1;
            memDC.DrawLine(x1,y1,x1+w1,y1);
            memDC.DrawLabel(wxString::Format(_("%.1f"),-mxh),wxRect(x1-5,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

            ///注记
            w1=w2-80;
            x1=x2+40;
            y1=y1+45;
            memDC.SetPen(wxPen(wxColor(255,0,0)));
            memDC.SetBrush(wxBrush(wxColor(255,0,0)));
            memDC.DrawLine(x1,y1,x1+20,y1);
            memDC.DrawRectangle(x1+8,y1-2,6,6);
            memDC.DrawLabel(_("切口平面"),wxRect(x1+30,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            x1=x1+w1/4+w1/24;
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.SetBrush(wxBrush(wxColor(0,0,255)));
            memDC.DrawLine(x1,y1,x1+20,y1);
            memDC.DrawRectangle(x1+8,y1-2,6,6);
            memDC.DrawLabel(_("切口高程"),wxRect(x1+30,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            x1=x1+w1/4+w1/24;
            memDC.SetPen(wxPen(wxColor(0,255,0)));
            memDC.SetBrush(wxBrush(wxColor(0,255,0)));
            memDC.DrawLine(x1,y1,x1+20,y1);
            memDC.DrawRectangle(x1+8,y1-2,6,6);
            memDC.DrawLabel(_("盾尾平面"),wxRect(x1+30,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            x1=x1+w1/4+w1/24;
            memDC.SetPen(wxPen(wxColor(0,255,255)));
            memDC.SetBrush(wxBrush(wxColor(0,255,255)));
            memDC.DrawLine(x1,y1,x1+20,y1);
            memDC.DrawRectangle(x1+8,y1-2,6,6);
            memDC.DrawLabel(_("盾尾高程"),wxRect(x1+30,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            double xs,ys;
            long t3=(long)t1;
            long t4=(long)t2;
            xs=((double)t4-(double)t3)/(double)w2;
            ys=mxh/(h2*0.5);

            double hhx1,hhy1,hhx2,hhy2;
            double hvx1,hvy1,hvx2,hvy2;
            double thx1,thy1,thx2,thy2;
            double tvx1,tvy1,tvx2,tvy2;
            int vp=0;

            for(i=nms-1;i>0;i--)
            {
                //trace(0,"DutyDlg:headh=%.4f,headv=%.4f,tailh=%.4f,tailv=%.4f,mxh=%.4f\n",
                      //ms[i].headh,ms[i].headv,ms[i].tailh,ms[i].tailv,mxh);
                if(fabs(ms[i].headh*1000.0)>mxh) continue;
                if(fabs(ms[i].headv*1000.0)>mxh) continue;
                if(fabs(ms[i].tailh*1000.0)>mxh) continue;
                if(fabs(ms[i].tailv*1000.0)>mxh) continue;
                if(vp==0)
                {
                    hhx1=x2+0.0;
                    hhy1=y2+h2/2-ms[i].headh*1000.0/ys;

                    hvx1=x2+0.0;
                    hvy1=y2+h2/2-ms[i].headv*1000.0/ys;

                    thx1=x2+0.0;
                    thy1=y2+h2/2-ms[i].tailh*1000.0/ys;

                    tvx1=x2+0.0;
                    tvy1=y2+h2/2-ms[i].tailv*1000.0/ys;
                    vp=1;
                }
                else
                {
                    val=(long)ms[i].t1;
                    hhx2=x2+fabs(val-t3)/xs;
                    hhy2=y2+h2/2-ms[i].headh*1000.0/ys;

                    hvx2=hhx2;
                    hvy2=y2+h2/2-ms[i].headv*1000.0/ys;

                    thx2=hhx1;
                    thy2=y2+h2/2-ms[i].tailh*1000.0/ys;

                    tvx2=hhx1;
                    tvy2=y2+h2/2-ms[i].tailv*1000.0/ys;

                    memDC.SetPen(wxPen(wxColor(255,0,0)));
                    memDC.DrawLine(hhx1,hhy1,hhx2,hhy2);
                    hhx1=hhx2;
                    hhy1=hhy2;

                    memDC.SetPen(wxPen(wxColor(0,0,255)));
                    memDC.DrawLine(hvx1,hvy1,hvx2,hvy2);
                    hvx1=hvx2;
                    hvy1=hvy2;

                    memDC.SetPen(wxPen(wxColor(0,255,0)));
                    memDC.DrawLine(thx1,thy1,thx2,thy2);
                    thx1=thx2;
                    thy1=thy2;

                    memDC.SetPen(wxPen(wxColor(0,255,255)));
                    memDC.DrawLine(tvx1,tvy1,tvx2,tvy2);
                    tvx1=tvx2;
                    tvy1=tvy2;
                }
            }
            wxString str;
            time_t t;
            time(&t);
            i=drvList->GetFirstSelected();
            //str=wxString(mtg->duty[i].name,wxConvLocal);
            str=_("掘进报告");
            str+=wxDateTime(t1).Format(_("(%Y%m%d%H%M).bmp"))+_(" ～ ")+wxDateTime(t2).Format(_("(%Y%m%d%H%M).bmp"));
            wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
            if(dlg.ShowModal()==wxID_OK)
            {
                str=dlg.GetPath();
                m_memBit.SaveFile(str,wxBITMAP_TYPE_BMP);
            }
        }
    }
}

void DutyDlg::OnPaintMain(wxPaintEvent& event)
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
