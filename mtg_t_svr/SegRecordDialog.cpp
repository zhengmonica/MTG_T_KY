#include "wx_pch.h"
#include "SegRecordDialog.h"
#include "mtg_t_svrApp.h"
#include "ConfirmDlg.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(SegRecordDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(SegRecordDialog)
//*)

//(*IdInit(SegRecordDialog)
const long SegRecordDialog::ID_STATICTEXT1 = wxNewId();
const long SegRecordDialog::ID_STATICTEXT2 = wxNewId();
const long SegRecordDialog::ID_STATICTEXT3 = wxNewId();
const long SegRecordDialog::ID_TEXTCTRL1 = wxNewId();
const long SegRecordDialog::ID_TEXTCTRL2 = wxNewId();
const long SegRecordDialog::ID_CHOICE1 = wxNewId();
const long SegRecordDialog::ID_PANEL1 = wxNewId();
const long SegRecordDialog::ID_PANEL2 = wxNewId();
const long SegRecordDialog::ID_STATICLINE1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SegRecordDialog,wxDialog)
	//(*EventTable(SegRecordDialog)
	//*)
END_EVENT_TABLE()

SegRecordDialog::SegRecordDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SegRecordDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(220,200));
	Move(wxDefaultPosition);
	panelMain = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(220,155), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	statictext1 = new wxStaticText(panelMain, ID_STATICTEXT1, _("环号"), wxPoint(30,25), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	statictext2 = new wxStaticText(panelMain, ID_STATICTEXT2, _("管环类型"), wxPoint(30,60), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	statictext3 = new wxStaticText(panelMain, ID_STATICTEXT3, _("拼装点位"), wxPoint(30,95), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
//	segnum = new wxTextCtrl(panelMain, ID_TEXTCTRL1, wxEmptyString, wxPoint(105,23), wxSize(100,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
//	location = new wxTextCtrl(panelMain, ID_TEXTCTRL2, wxEmptyString, wxPoint(105,92), wxSize(100,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	segnum = new wxMyTextCtrl(panelMain, ID_TEXTCTRL1, wxEmptyString, wxPoint(105,23), wxSize(100,22), 0);
	location = new wxMyTextCtrl(panelMain, ID_TEXTCTRL2, wxEmptyString, wxPoint(105,92), wxSize(100,22), 0);

	segtype = new wxChoice(panelMain, ID_CHOICE1, wxPoint(105,57), wxSize(100,22), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	segtype->SetSelection( segtype->Append(_("标准环")) );
	segtype->Append(_("左转弯"));
	segtype->Append(_("右转弯"));
	segtype->Append(_("通用环"));
	panelBottom = new wxPanel(this, ID_PANEL2, wxPoint(0,156), wxSize(220,45), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(0,155), wxSize(220,1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	//*)
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegRecordDialog::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&SegRecordDialog::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&SegRecordDialog::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&SegRecordDialog::OnClickBottom,0,this);

    motion=ID_PT_NONE;
}

SegRecordDialog::~SegRecordDialog()
{
	//(*Destroy(SegRecordDialog)
	//*)
}

void SegRecordDialog::OnPaintBottom(wxPaintEvent& event)
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

void SegRecordDialog::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>ptButton[ID_PT_QUIT].y && y<ptButton[ID_PT_QUIT].y+ptButton[ID_PT_QUIT].height)
    {
        if(x>ptButton[ID_PT_QUIT].x && x<ptButton[ID_PT_QUIT].x+ptButton[ID_PT_QUIT].width)
        {
            motion=ID_PT_QUIT;
        }
        else if(x>ptButton[ID_PT_OK].x && x<ptButton[ID_PT_OK].x+ptButton[ID_PT_OK].width)
        {
            motion=ID_PT_OK;
        }
        else
        {
            motion=ID_PT_NONE;
        }
    }
    else
    {
        motion=ID_PT_NONE;
    }
    panelBottom->Refresh();
}

void SegRecordDialog::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_PT_NONE;
    panelBottom->Refresh();
}

void SegRecordDialog::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_PT_OK)
    {
        if(segnum->GetValue().IsEmpty())
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("环号不能为空！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                segnum->SetFocus();
            }
            return;
        }
        else
        {
            if(location->GetValue().IsEmpty())
            {
                ConfirmDlg dlg(this);
                dlg.Center();
                dlg.confirmMsg=_("拼装点位不能为空！");
                dlg.type=1;
                if(dlg.ShowModal()==wxID_OK)
                {
                    location->SetFocus();
                }
                return;
            }
            else
            {
                EndModal(wxID_OK);
            }
        }
    }
    else if(motion==ID_PT_QUIT)
    {
        Destroy();
    }
}
