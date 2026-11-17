#include "wx_pch.h"
#include "PasswordDialog.h"
#include "mtg_tApp.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(PasswordDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(PasswordDialog)
#include <wx/font.h>
//*)

#include "KeyBoard.h"

//(*IdInit(PasswordDialog)

const long PasswordDialog::ID_PANEL1 = wxNewId();
const long PasswordDialog::ID_PANEL2 = wxNewId();
const long PasswordDialog::ID_TEXTCTRL1 = wxNewId();
const long PasswordDialog::ID_CHOICE1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PasswordDialog,wxDialog)
	//(*EventTable(PasswordDialog)
	//*)
END_EVENT_TABLE()

PasswordDialog::PasswordDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(PasswordDialog)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_RAISED, _T("wxID_ANY"));
	SetClientSize(wxSize(240,180));
	int w=240;
	int h=180;
	m_title = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    m_title->IsMaximinize=0;
    m_title->m_close_box=0;
    m_title->Name=_("登录");
    panelPassword = new wxPanel(this, ID_PANEL2, wxPoint(0,31), wxSize(w,h-31), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelPassword->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	TextPassword = new wxMyTextCtrl(panelPassword, ID_TEXTCTRL1, wxEmptyString, wxPoint(70,63), wxSize(140,-1), wxTE_PASSWORD | wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	panelPassword->Connect(wxEVT_PAINT,(wxObjectEventFunction)&PasswordDialog::OnPaintPassword,0,this);
	panelPassword->Connect(wxEVT_MOTION,(wxObjectEventFunction)&PasswordDialog::OnMotionPassword,0,this);
    panelPassword->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&PasswordDialog::OnLeavePassword,0,this);
    panelPassword->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&PasswordDialog::OnClickPassword,0,this);
	//*)
    motion=ID_PSW_NONE;
    iuser=-1;
    iget=0;
}

PasswordDialog::~PasswordDialog()
{
	//(*Destroy(PasswordDialog)
	//*)
}

void PasswordDialog::OnPaintPassword(wxPaintEvent& event)
{
    wxPaintDC dc(panelPassword);
    int w,h;
    panelPassword->GetClientSize(&w,&h);
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

        int x1,y1,w1,h1;
        x1=28;
        y1=20;
        h1=32;
        w1=w-56;
        memDC.DrawLabel(_("请输入权限密码!"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        TextPassword->SetSize(x1+3,y1+7,w1-6,19);

        y1=y1+h1+11;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x,y1,x+w,y1);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x,y1+1,x+w,y1+1);
        y1=y1+12;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,2);
        pswButton[ID_PSW_CONFIRM].x=x1+1;
        pswButton[ID_PSW_CONFIRM].y=y1+1;
        pswButton[ID_PSW_CONFIRM].width=w1/2-1;
        pswButton[ID_PSW_CONFIRM].height=h1-2;

        pswButton[ID_PSW_CANCEL].x=pswButton[ID_PSW_CONFIRM].x+pswButton[ID_PSW_CONFIRM].width;
        pswButton[ID_PSW_CANCEL].y=pswButton[ID_PSW_CONFIRM].y;
        pswButton[ID_PSW_CANCEL].width=pswButton[ID_PSW_CONFIRM].width;
        pswButton[ID_PSW_CANCEL].height=pswButton[ID_PSW_CONFIRM].height;
        if(motion==ID_PSW_CONFIRM)
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(pswButton[ID_PSW_CONFIRM]);
        memDC.DrawLabel(_("确 定"),pswButton[ID_PSW_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_PSW_CANCEL)
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[1].GetColour())));
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(btnBrush[0].GetColour())));
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(pswButton[ID_PSW_CANCEL]);
        memDC.DrawLabel(_("取 消"),pswButton[ID_PSW_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void PasswordDialog::OnMotionPassword(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>pswButton[ID_PSW_CONFIRM].y && y<pswButton[ID_PSW_CONFIRM].y+pswButton[ID_PSW_CONFIRM].height)
    {
        if(x>pswButton[ID_PSW_CONFIRM].x && x<pswButton[ID_PSW_CONFIRM].x+pswButton[ID_PSW_CONFIRM].width)
        {
            motion=ID_PSW_CONFIRM;
        }
        else if(x>pswButton[ID_PSW_CANCEL].x && x<pswButton[ID_PSW_CANCEL].x+pswButton[ID_PSW_CANCEL].width)
        {
            motion=ID_PSW_CANCEL;
        }
        else
        {
            motion=ID_PSW_NONE;
        }
    }
    else if(y>pswButton[ID_PSW_MANAGER].y && y<pswButton[ID_PSW_MANAGER].y+pswButton[ID_PSW_MANAGER].height)
    {
        if(x>pswButton[ID_PSW_MANAGER].x && x<pswButton[ID_PSW_MANAGER].x+pswButton[ID_PSW_MANAGER].width)
        {
            motion=ID_PSW_MANAGER;
        }
        else if(x>pswButton[ID_PSW_OPERAROR].x && x<pswButton[ID_PSW_OPERAROR].x+pswButton[ID_PSW_OPERAROR].width)
        {
            motion=ID_PSW_OPERAROR;
        }
        else
        {
            motion=ID_PSW_NONE;
        }
    }
    else
    {
        motion=ID_PSW_NONE;
    }
    panelPassword->Refresh();
}

void PasswordDialog::OnLeavePassword(wxMouseEvent& event)
{
    motion=ID_PSW_NONE;
    panelPassword->Refresh();
}

void PasswordDialog::OnClickPassword(wxMouseEvent& event)
{
    if(motion==ID_PSW_CONFIRM)
    {
        int i;
        wxString str=TextPassword->GetValue();
        if(iget==1)
        {
            if(str.Cmp(wxString((const char*)cli->user[0].password,wxConvUTF8))==0)
            {
                iuser=0;
                EndModal(wxID_OK);
            }
            else
            {
                TextPassword->SetSelection(-1,-1);
                return;
            }
        }
        else
        {
            for(i=0;i<cli->nuser;i++)
            {
                if(str.Cmp(wxString((const char*)cli->user[i].password,wxConvUTF8))==0)
                {
                    iuser=i;
                    break;
                }
            }
            if(iuser>=0)
            {
                EndModal(wxID_OK);
            }
            else
            {
                TextPassword->SetSelection(-1,-1);
                return;
            }
        }
    }
    else if(motion==ID_PSW_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }
    else
    {
        panelPassword->Refresh();
    }
}




