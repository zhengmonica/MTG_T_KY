///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DigformDlg.h"
#include "mtg_t_svrApp.h"
#include "confirmdlg.h"
//#include "SegDialog.h"
//#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(DigformDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(DigformDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(DigformDlg)


const long DigformDlg::ID_PANEL1 = wxNewId();                  //标题
//*)

DigformDlg::DigformDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
    panelTitle->Name=_("掘进报表");
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,31), wxSize(w,h-76), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x2=15;
    y2=26;
    w2=120;
    h2=h-118;

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

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DigformDlg::OnPaintMain,0,this);

    listPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DigformDlg::OnPaintList,0,this);

    textPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DigformDlg::OnPaintText,0,this);

    drvList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&DigformDlg::OnDriverSelect,0,this);
    textList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&DigformDlg::OnTextSelect,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DigformDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DigformDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DigformDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DigformDlg::OnClickBottom,0,this);
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

    motion=ID_DIGFORM_NONE;
    dvr=mtg->onduty;
    drvList->Select(dvr);
    nres=0;
    nres=mtg_query_duty(mtg,dvr,&res);
    txt=0;

    checkBoxWidth=14;
    checkBoxHeight=14;
    radioBoxR1=7;
    radioBoxR2=4;
}

DigformDlg::~DigformDlg()
{

}

void DigformDlg::UpdateText()
{
    int i=0;
    wxString str1;
    while(i<nres)
    {
        textList->InsertItem(i,wxString::Format(_("%d"),i+1));
        str1=wxString::Format(_("%d"),res[i].index[0])+_("～")+wxString::Format(_("%d"),res[i].index[1]);
        textList->SetItem(i,1,str1);
        double l1=res[i].mile[0];
        double l2=res[i].mile[1];
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
        t1=res[i].t[0];
        t2=res[i].t[1];
        if(t2<=t1) time(&t2);
        str1=wxDateTime(t1).Format(_("%Y-%m-%d %H:%M"))+_("～")+wxDateTime(t2).Format(_("%H:%M"));
        textList->SetItem(i,3,str1);
        i++;
    }
}

void DigformDlg::OnDriverSelect(wxListEvent& event)
{
    textList->DeleteAllItems();
    dvr=drvList->GetFirstSelected();
    nres=0;
    nres=mtg_query_duty(mtg,dvr,&res);
    UpdateText();
}

void DigformDlg::OnTextSelect(wxListEvent& event)
{
    txt=textList->GetFirstSelected();
    nms=0;
    time_t t1=res[txt].t[0];
    time_t t2=res[txt].t[1];
    if(t2<=t1) time(&t2);
    nms=mtg_query_time(mtg,t1,t2,&ms);
    int w,h;
    textPanel->GetSize(&w,&h);
    textPanel->RefreshRect(wxRect(0,h/2,w,h/2));
}

void DigformDlg::OnPaintList(wxPaintEvent& event)
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

void DigformDlg::OnPaintText(wxPaintEvent& event)
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
        memDC.DrawLabel(_("起止环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起止里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=textList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起止时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

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

        if(nres>0)
        {
            x1=45;
            y1=y1+10;
            w1=w-x1*2;
            h1=25;
            time_t t1,t2;
            double l1,l2;
            int r1,r2;
            int i=txt;
            wxString str1;
            r1=res[i].index[0];
            r2=res[i].index[1];
            str1=_("累计掘进：");
            if(r2<=r1) r2=mtg->m1.iseg;
            str1=str1+wxString::Format(_("%d环         "),r2-r1);

            l1=res[i].mile[0];
            l2=res[i].mile[1];
            if(mtg->prj.a2z==1)
            {
                if(l2<=l1) l2=mtg->m1.headc;
            }
            else
            {
                if(l2>=l1) l2=mtg->m1.headc;
            }
            str1=str1+wxString::Format(_("%.3f米         "),fabs(l2-l1));

            t1=res[i].t[0];
            t2=res[i].t[1];
            if(t2<=t1) time(&t2);;
            int h=(t2-t1)/3600;
            int m=t2-t1-h*3600;
            m=m/60;
            str1=str1+wxString::Format(_("%d小时"),h)+wxString::Format(_("%d分钟"),m);

            memDC.DrawLabel(str1,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

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
        if(res[txt].mxdev>0)
        {
            memDC.DrawLabel(wxString::Format(_("%d"),res[txt].mxdev),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("50"),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        y1=y1+h1;
        memDC.DrawLine(x1,y1,x1+w1,y1);
        if(res[txt].mxdev>0)
        {
            memDC.DrawLabel(wxString::Format(_("%d"),res[txt].mxdev/2),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("25"),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        memDC.DrawLabel(_("0"),wxRect(x1-7,y1+h1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1*2;
        memDC.DrawLine(x1,y1,x1+w1,y1);
        if(res[txt].mxdev>0)
        {
            memDC.DrawLabel(wxString::Format(_("%d"),-res[txt].mxdev/2),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("-25"),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        y1=y1+h1;
        memDC.DrawLine(x1,y1,x1+w1,y1);
        if(res[txt].mxdev>0)
        {
            memDC.DrawLabel(wxString::Format(_("%d"),-res[txt].mxdev),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("-50"),wxRect(x1-7,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        }

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

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DigformDlg::OnPaintBottom(wxPaintEvent& event)
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
        button[ID_DIGFORM_QUIT].x=x1;
        button[ID_DIGFORM_QUIT].y=y1;
        button[ID_DIGFORM_QUIT].width=w1;
        button[ID_DIGFORM_QUIT].height=h1;
        if(motion==ID_DIGFORM_QUIT)
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
        button[ID_DIGFORM_EXP].x=x1;
        button[ID_DIGFORM_EXP].y=y1;
        button[ID_DIGFORM_EXP].width=w1;
        button[ID_DIGFORM_EXP].height=h1;
        if(motion==ID_DIGFORM_EXP)
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

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DigformDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_DIGFORM_QUIT].y && y<button[ID_DIGFORM_QUIT].y+button[ID_DIGFORM_QUIT].height)
    {
        if(x>button[ID_DIGFORM_QUIT].x && x<button[ID_DIGFORM_QUIT].x+button[ID_DIGFORM_QUIT].width)
        {
            motion=ID_DIGFORM_QUIT;
        }
        else if(x>button[ID_DIGFORM_EXP].x && x<button[ID_DIGFORM_EXP].x+button[ID_DIGFORM_EXP].width)
        {
            motion=ID_DIGFORM_EXP;
        }
        else
        {
            motion=ID_DIGFORM_NONE;
        }
    }
    else
    {
        motion=ID_DIGFORM_NONE;
    }
    panelBottom->Refresh();
}

void DigformDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_DIGFORM_NONE;
    panelBottom->Refresh();
}

void DigformDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_DIGFORM_QUIT)
    {
        Destroy();
    }
    //panelBottom->Refresh();
}

void DigformDlg::OnPaintMain(wxPaintEvent& event)
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
