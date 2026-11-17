#include "wx_pch.h"
#include "SegRecordDlg.h"
#include "mtg_t_svrApp.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(SegRecordDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(SegRecordDlg)
//*)

//(*IdInit(SegRecordDlg)
//*)

BEGIN_EVENT_TABLE(SegRecordDlg,wxDialog)
	//(*EventTable(SegRecordDlg)
	//*)
END_EVENT_TABLE()

SegRecordDlg::SegRecordDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	//(*Initialize(SegRecordDlg)

	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    SegNum = new wxTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    wxString choices[] ={_T("标准环"),_T("左转弯"),_T("右转弯"),_T("通用环")};
    SegType = new wxChoice(panelMain,wxID_ANY,wxDefaultPosition,wxDefaultSize,4,choices,0,wxDefaultValidator,_T("ID_choice2"));
    SegType->SetSelection(0);
    SegType->Show(true);
    Location = new wxTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

	panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegRecordDlg::OnPaintMain,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegRecordDlg::OnPaintBottom,0,this);
//    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegRecordDlg::OnMotionBottom,0,this);
//    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegRecordDlg::OnLeaveBottom,0,this);
//    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegRecordDlg::OnClickBottom,0,this);
	//*)
	this->SetBackgroundColour(wxColor(245,248,250));

    motion=ID_PT_NONE;
}

SegRecordDlg::~SegRecordDlg()
{
	//(*Destroy(SegRecordDlg)
	//*)
}

void SegRecordDlg::OnPaintMain(wxPaintEvent& event)
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
        memDC.SetPen(wxPen(wxColor(239,239,239)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=85;
        y1=30;
        w1=100;
        h1=30;
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        SegNum->SetSize(x1+10,y1-11,w1,-1);
        y1=y1+h1;
        memDC.DrawLabel(_("管环类型"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        SegType->SetSize(x1+10,y1-11,w1,-1);
        y1=y1+h1;
        memDC.DrawLabel(_("拼装点位"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        Location->SetSize(x1+10,y1-11,w1,-1);

        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(0,10,w,10);
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void SegRecordDlg::OnPaintBottom(wxPaintEvent& event)
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
//            memDC.SetPen(wxPen(wxColor(r1,g1,b1)));
            memDC.SetPen(wxPen(wxColor(255,0,0)));
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
        ptButton[ID_PT_QUIT].x=x1;
        ptButton[ID_PT_QUIT].y=y1;
        ptButton[ID_PT_QUIT].width=w1;
        ptButton[ID_PT_QUIT].height=h1;
        if(motion==ID_PT_QUIT)
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
        ptButton[ID_PT_OK].x=x1;
        ptButton[ID_PT_OK].y=y1;
        ptButton[ID_PT_OK].width=w1;
        ptButton[ID_PT_OK].height=h1;
        if(motion==ID_PT_OK)
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

