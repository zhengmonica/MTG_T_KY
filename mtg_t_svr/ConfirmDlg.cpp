#include "wx_pch.h"
#include "ConfirmDlg.h"
#include "mtg_t_svrApp.h"
#include <wx/stdpaths.h>
#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(ConfirmDlg )
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(ConfirmDlg )
#include <wx/font.h>
//*)

#include "KeyBoard.h"

//(*IdInit(ConfirmDlg )
const long ConfirmDlg ::ID_PANEL2 = wxNewId();
const long ConfirmDlg ::ID_CHOICE1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ConfirmDlg ,wxDialog)
	//(*EventTable(ConfirmDlg )
	//*)
END_EVENT_TABLE()

ConfirmDlg ::ConfirmDlg (wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ConfirmDlg )
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(240,149));
	wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);
    bmpTip1.LoadFile(path+_("/plugins/info1.png"),wxBITMAP_TYPE_PNG);
    bmpTip2.LoadFile(path+_("/plugins/error.png"),wxBITMAP_TYPE_PNG);

	int w=240;
	int h=149;
    panelConfirm = new wxPanel(this, ID_PANEL2, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelConfirm->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelConfirm->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfirmDlg ::OnPaintPassword,0,this);
	panelConfirm->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfirmDlg ::OnMotionPassword,0,this);
    panelConfirm->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfirmDlg ::OnLeavePassword,0,this);
    panelConfirm->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfirmDlg ::OnClickPassword,0,this);
	//*)

    motion=ID_CONFIRM_NONE;

    confirmMsg = _("确定退出软件？");
	type=0;      //确认对话框1错误提示对话框
}

ConfirmDlg ::~ConfirmDlg ()
{
	//(*Destroy(ConfirmDlg )
	//*)
}

void ConfirmDlg ::OnPaintPassword(wxPaintEvent& event)
{
    wxPaintDC dc(panelConfirm);
    int w,h;
    panelConfirm->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.SetPen(wxPen(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(68,68,68));

        int x,y;
        x=0;
        y=12;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x,y,w,y);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x,y+1,w,y+1);

        if(type==0)
        {
            SetTitle(_("提示"));
            if(bmpTip1.IsOk()) memDC.DrawBitmap(bmpTip1,48,h/2-28);
            memDC.DrawLabel(confirmMsg,wxRect(75,h/2-20,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            int x1,y1,w1,h1;
            x1=28;
            y1=20;
            h1=32;
            w1=w-56;
            //memDC.DrawLabel(_("请输入权限密码!"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            y1=y1+h1;

            y1=y1+h1+11;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawLine(x,y1,x+w,y1);
            memDC.SetPen(wxPen(wxColor(255,255,255)));
            memDC.DrawLine(x,y1+1,x+w,y1+1);
            y1=y1+12;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(255,255,255)));
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,2);
            confirmButton[ID_CONFIRM_CONFIRM].x=x1+1;
            confirmButton[ID_CONFIRM_CONFIRM].y=y1+1;
            confirmButton[ID_CONFIRM_CONFIRM].width=w1/2-1;
            confirmButton[ID_CONFIRM_CONFIRM].height=h1-2;

            confirmButton[ID_CONFIRM_CANCEL].x=confirmButton[ID_CONFIRM_CONFIRM].x+confirmButton[ID_CONFIRM_CONFIRM].width;
            confirmButton[ID_CONFIRM_CANCEL].y=confirmButton[ID_CONFIRM_CONFIRM].y;
            confirmButton[ID_CONFIRM_CANCEL].width=confirmButton[ID_CONFIRM_CONFIRM].width;
            confirmButton[ID_CONFIRM_CANCEL].height=confirmButton[ID_CONFIRM_CONFIRM].height;
            if(motion==ID_CONFIRM_CONFIRM)
            {
                memDC.SetPen(wxPen(ibrush[1].GetColour()));
                memDC.SetBrush(ibrush[1]);
                memDC.SetTextForeground(icolor[1]);
            }
            else
            {
                memDC.SetPen(wxPen(ibrush[0].GetColour()));
                memDC.SetBrush(ibrush[0]);
                memDC.SetTextForeground(icolor[0]);
            }
            memDC.DrawRectangle(confirmButton[ID_CONFIRM_CONFIRM]);
            memDC.DrawLabel(_("确 定"),confirmButton[ID_CONFIRM_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

            if(motion==ID_CONFIRM_CANCEL)
            {
                memDC.SetPen(wxPen(ibrush[1].GetColour()));
                memDC.SetBrush(ibrush[1]);
                memDC.SetTextForeground(icolor[1]);
            }
            else
            {
                memDC.SetPen(wxPen(ibrush[0].GetColour()));
                memDC.SetBrush(ibrush[0]);
                memDC.SetTextForeground(icolor[0]);
            }
            memDC.DrawRectangle(confirmButton[ID_CONFIRM_CANCEL]);
            memDC.DrawLabel(_("取 消"),confirmButton[ID_CONFIRM_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else if(type==1)
        {
            SetTitle(_("错误"));
            if(bmpTip2.IsOk()) memDC.DrawBitmap(bmpTip2,48,h/2-28);
            memDC.DrawLabel(confirmMsg,wxRect(75,h/2-20,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            int x1,y1,w1,h1;
            x1=28;
            y1=20;
            h1=32;
            w1=w-56;
            w1=w1/2;
            x1=x1+w1/2;
            y1=y1+h1;

            y1=y1+h1+11;
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawLine(x,y1,x+w,y1);
            memDC.SetPen(wxPen(wxColor(255,255,255)));
            memDC.DrawLine(x,y1+1,x+w,y1+1);

            y1=y1+12;
            confirmButton[ID_CONFIRM_CONFIRM].x=x1;
            confirmButton[ID_CONFIRM_CONFIRM].y=y1;
            confirmButton[ID_CONFIRM_CONFIRM].width=w1;
            confirmButton[ID_CONFIRM_CONFIRM].height=h1;

            if(motion==ID_CONFIRM_CONFIRM)
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
            memDC.DrawRoundedRectangle(confirmButton[ID_CONFIRM_CONFIRM],3);
            memDC.DrawLabel(_("确 定"),confirmButton[ID_CONFIRM_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfirmDlg ::OnMotionPassword(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>confirmButton[ID_CONFIRM_CONFIRM].y && y<confirmButton[ID_CONFIRM_CONFIRM].y+confirmButton[ID_CONFIRM_CONFIRM].height)
    {
        if(x>confirmButton[ID_CONFIRM_CONFIRM].x && x<confirmButton[ID_CONFIRM_CONFIRM].x+confirmButton[ID_CONFIRM_CONFIRM].width)
        {
            motion=ID_CONFIRM_CONFIRM;
        }
        else if(x>confirmButton[ID_CONFIRM_CANCEL].x && x<confirmButton[ID_CONFIRM_CANCEL].x+confirmButton[ID_CONFIRM_CANCEL].width)
        {
            motion=ID_CONFIRM_CANCEL;
        }
        else
        {
            motion=ID_CONFIRM_NONE;
        }
    }
    else
    {
        motion=ID_CONFIRM_NONE;
    }
    panelConfirm->Refresh();
}

void ConfirmDlg ::OnLeavePassword(wxMouseEvent& event)
{
    motion=ID_CONFIRM_NONE;
    panelConfirm->Refresh();
}

void ConfirmDlg ::OnClickPassword(wxMouseEvent& event)
{
    if(motion==ID_CONFIRM_CONFIRM)
    {
        EndModal(wxID_OK);
    }
    else if(motion==ID_CONFIRM_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }
    else
    {
        panelConfirm->Refresh();
    }
}

