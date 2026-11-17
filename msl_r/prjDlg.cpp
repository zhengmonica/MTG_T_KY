///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "prjDlg.h"
#include "msr_tApp.h"
#include "BlockEditDlg.h"
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
	//(*InternalHeadersPCH(prjDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(prjDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(prjDlg)

//*)

prjDlg::prjDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;

	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelPrj = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w,h-57), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPrj->SetBackgroundColour(wxColor(239,239,239));

    x1=14;
    y1=16;
    w1=w-x1*2;
    h1=h-y1-75;
    staticName = new wxStaticText(panelPrj, wxID_ANY, _("项目名称"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prjName = new wxMyTextCtrl(panelPrj, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1-3), wxSize(360,-1), 0);
    y1+=30;
    staticMile1 = new wxStaticText(panelPrj, wxID_ANY, _("起点里程"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prjMile1 = new wxMyTextCtrl(panelPrj, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1-3), wxSize(120,-1), 0);
    y1+=30;
    staticMile2 = new wxStaticText(panelPrj, wxID_ANY, _("终点里程"), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    prjMile2 = new wxMyTextCtrl(panelPrj, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1-3), wxSize(120,-1), 0);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&prjDlg::OnPaintMain,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&prjDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&prjDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&prjDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&prjDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));
    motion=ID_PRJ_NONE;

    prjName->SetValue(wxString(msr->prj.name,wxConvUTF8));
    prjMile1->SetValue(wxString::Format(_("%.1f"),msr->prj.mile1));
    prjMile2->SetValue(wxString::Format(_("%.1f"),msr->prj.mile2));
}

prjDlg::~prjDlg()
{

}

void prjDlg::OnPaintBottom(wxPaintEvent& event)
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


        w1=65;
        h1=26;
        x1=w/2+4;
        y1=9;
        button[ID_PRJ_CANCEL].x=x1;
        button[ID_PRJ_CANCEL].y=y1;
        button[ID_PRJ_CANCEL].width=w1;
        button[ID_PRJ_CANCEL].height=h1;
        if(motion==ID_PRJ_CANCEL)
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

        x1=x1-w1-8;
        button[ID_PRJ_OK].x=x1;
        button[ID_PRJ_OK].y=y1;
        button[ID_PRJ_OK].width=w1;
        button[ID_PRJ_OK].height=h1;
        if(motion==ID_PRJ_OK)
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

void prjDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_PRJ_CANCEL].y && y<button[ID_PRJ_CANCEL].y+button[ID_PRJ_CANCEL].height)
    {
        if(x>button[ID_PRJ_CANCEL].x && x<button[ID_PRJ_CANCEL].x+button[ID_PRJ_CANCEL].width)
        {
            motion=ID_PRJ_CANCEL;
        }
        else if(x>button[ID_PRJ_OK].x && x<button[ID_PRJ_OK].x+button[ID_PRJ_OK].width)
        {
            motion=ID_PRJ_OK;
        }
        else
        {
            motion=ID_PRJ_NONE;
        }
    }
    else
    {
        motion=ID_PRJ_NONE;
    }
    panelBottom->Refresh();
}

void prjDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_PRJ_NONE;
    panelBottom->Refresh();
}

void prjDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_PRJ_CANCEL)
    {
        Destroy();
    }
    else if(motion==ID_PRJ_OK)
    {
        wxStandardPaths wsp;
        wxString str=wsp.GetDataDir()+wxString(_("\\plugins\\"))+wxString(_("project.prj"));
        FILE* fp;
        char path[260];
        strcpy(path,str.mb_str(wxConvLocal));
        fp=fopen(path,"w");
        if(fp)
        {
            str=prjName->GetValue();
            strncpy(msr->prj.name,str.mb_str(wxConvUTF8),64);
            prjMile1->GetValue().ToDouble(&msr->prj.mile1);
            prjMile2->GetValue().ToDouble(&msr->prj.mile2);
            if(msr->prj.mile1<=msr->prj.mile2) msr->prj.a2z=1;
            else msr->prj.a2z=-1;
            fprintf(fp,"'%s',%f,%f,%d\n",msr->prj.name,msr->prj.mile1,msr->prj.mile2,msr->prj.a2z);
            fclose(fp);
        }
        Destroy();
    }
    //panelBottom->Refresh();
}

void prjDlg::OnPaintMain(wxPaintEvent& event)
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
