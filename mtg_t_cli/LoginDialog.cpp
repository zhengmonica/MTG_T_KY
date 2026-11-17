#include "wx_pch.h"
#include "LoginDialog.h"

#include "mtg_t_cliApp.h"

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

//(*IdInit(LoginDialog)
const long LoginDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LoginDialog,wxDialog)
	//(*EventTable(LoginDialog)
	//*)
END_EVENT_TABLE()

LoginDialog::LoginDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(LoginDialog)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_RAISED, _T("wxID_ANY"));
	SetClientSize(wxSize(240,180));
	int w=240;
	int h=180;
	m_title = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    m_title->IsMaximinize=0;
    m_title->m_close_box=0;
    m_title->Name=_("登录");
    panelLogin = new wxPanel(this, wxID_ANY, wxPoint(0,31), wxSize(w,h-31), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelLogin->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    ip1 = new wxMyTextCtrl(panelLogin, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    ip2 = new wxMyTextCtrl(panelLogin, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    ip3 = new wxMyTextCtrl(panelLogin, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);
    ip4 = new wxMyTextCtrl(panelLogin, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelLogin->Connect(wxEVT_PAINT,(wxObjectEventFunction)&LoginDialog::OnPaintLogin,0,this);
	panelLogin->Connect(wxEVT_MOTION,(wxObjectEventFunction)&LoginDialog::OnMotionLogin,0,this);
    panelLogin->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&LoginDialog::OnLeaveLogin,0,this);
    panelLogin->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&LoginDialog::OnClickLogin,0,this);
	//*)
}

LoginDialog::~LoginDialog()
{
	//(*Destroy(LoginDialog)
	//*)
}

void LoginDialog::OnPaintLogin(wxPaintEvent& event)
{
    wxPaintDC dc(panelLogin);
    int w,h;
    panelLogin->GetClientSize(&w,&h);
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
        memDC.DrawLabel(_("服务器IP地址"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        int x2,y2,w2,h2;

        x2=x1+2;
        y2=y1+7;
        w2=w1/4-4;
        h2=19;
        ip1->SetSize(x2,y2,w2-2,h2);
        x2=x2+w2+2;
        memDC.DrawLabel(_("."),wxRect(x2-2,y2+8,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        ip2->SetSize(x2,y2,w2-2,h2);
        x2=x2+w2+2;
        memDC.DrawLabel(_("."),wxRect(x2-2,y2+8,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        ip3->SetSize(x2,y2,w2-2,h2);
        x2=x2+w2+2;
        memDC.DrawLabel(_("."),wxRect(x2-2,y2+8,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        ip4->SetSize(x2,y2,w2-2,h2);
        y1=y1+h1+11;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x,y1,x+w,y1);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x,y1+1,x+w,y1+1);
        y1=y1+12;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,2);
        loginButton[ID_LOGIN_LOGIN].x=x1+1;
        loginButton[ID_LOGIN_LOGIN].y=y1+1;
        loginButton[ID_LOGIN_LOGIN].width=w1/2-1;
        loginButton[ID_LOGIN_LOGIN].height=h1-2;

        loginButton[ID_LOGIN_CANCEL].x=loginButton[ID_LOGIN_LOGIN].x+loginButton[ID_LOGIN_LOGIN].width;
        loginButton[ID_LOGIN_CANCEL].y=loginButton[ID_LOGIN_LOGIN].y;
        loginButton[ID_LOGIN_CANCEL].width=loginButton[ID_LOGIN_LOGIN].width;
        loginButton[ID_LOGIN_CANCEL].height=loginButton[ID_LOGIN_LOGIN].height;
        if(motion==ID_LOGIN_LOGIN)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(ibrush[0].GetColour())));
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRectangle(loginButton[ID_LOGIN_LOGIN]);
        memDC.DrawLabel(_("登 陆"),loginButton[ID_LOGIN_LOGIN],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_LOGIN_CANCEL)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(ibrush[0].GetColour())));
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRectangle(loginButton[ID_LOGIN_CANCEL]);
        memDC.DrawLabel(_("取 消"),loginButton[ID_LOGIN_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void LoginDialog::OnMotionLogin(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>loginButton[ID_LOGIN_LOGIN].y && y<loginButton[ID_LOGIN_LOGIN].y+loginButton[ID_LOGIN_LOGIN].height)
    {
        if(x>loginButton[ID_LOGIN_LOGIN].x && x<loginButton[ID_LOGIN_LOGIN].x+loginButton[ID_LOGIN_LOGIN].width)
        {
            motion=ID_LOGIN_LOGIN;
        }
        else if(x>loginButton[ID_LOGIN_CANCEL].x && x<loginButton[ID_LOGIN_CANCEL].x+loginButton[ID_LOGIN_CANCEL].width)
        {
            motion=ID_LOGIN_CANCEL;
        }
        else
        {
            motion=ID_LOGIN_NONE;
        }
    }
    else
    {
        motion=ID_LOGIN_NONE;
    }
    panelLogin->Refresh();
}

void LoginDialog::OnLeaveLogin(wxMouseEvent& event)
{
    motion=ID_LOGIN_NONE;
    panelLogin->Refresh();
}

void LoginDialog::OnClickLogin(wxMouseEvent& event)
{
    if(motion==ID_LOGIN_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }
    else if(motion==ID_LOGIN_LOGIN)
    {
        EndModal(wxID_OK);
    }
}


