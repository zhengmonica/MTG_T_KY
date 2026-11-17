///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "UserEditDlg.h"
#include "mtg_tApp.h"
#include <wx/dcclient.h>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
const long UserEditDlg::ID_PANEL1 = wxNewId();
const long UserEditDlg::ID_PANEL2 = wxNewId();
///////////////////////////////////////////////////////////////////////////

UserEditDlg::UserEditDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //this->SetSize(320,240);
	this->SetSizeHints( wxDefaultSize, wxDefaultSize);
	//this->SetLabel(_("确认"));
	int w,h;
	this->GetClientSize(&w,&h);

    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);
    bmpTip1.LoadFile(path+_("/plugins/info.png"),wxBITMAP_TYPE_PNG);
    bmpTip2.LoadFile(path+_("/plugins/error.png"),wxBITMAP_TYPE_PNG);

    m_title = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    m_title->IsMaximinize=0;
    m_title->m_close_box=0;
    m_title->Name=_("用户管理");
    panelConfirm = new wxPanel(this, ID_PANEL2, wxPoint(0,31), wxSize(w,h-31), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelConfirm->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    Name = new wxMyTextCtrl(panelConfirm, wxID_ANY, wxEmptyString, wxPoint(65,30), wxSize(120,-1), wxBORDER_NONE | wxTE_LEFT | wxTE_PROCESS_ENTER, wxDefaultValidator);
    Password = new wxMyTextCtrl(panelConfirm, wxID_ANY, wxEmptyString, wxPoint(65,60), wxSize(120,-1), wxBORDER_NONE | wxTE_LEFT | wxTE_PROCESS_ENTER, wxDefaultValidator);

    panelConfirm->Connect(wxEVT_PAINT,(wxObjectEventFunction)&UserEditDlg::OnPaintConfirm,0,this);
    panelConfirm->Connect(wxEVT_MOTION,(wxObjectEventFunction)&UserEditDlg::OnMotionConfirm,0,this);
    panelConfirm->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&UserEditDlg::OnLeaveConfirm,0,this);
    panelConfirm->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&UserEditDlg::OnClickConfirm,0,this);

	this->Centre( wxBOTH );
}

UserEditDlg::~UserEditDlg()
{
}

void UserEditDlg::OnPaintConfirm(wxPaintEvent& event)
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

        int x1,y1,w1,h1;
        x1=28;
        y1=15;
        h1=27;
        w1=w-56;
        memDC.DrawLabel(_("请输入用户名称!"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        Name->SetSize(x1+3,y1+6,w1-6,19);
        y1=y1+h1;
        memDC.DrawLabel(_("请输入授权密码!"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        Password->SetSize(x1+3,y1+6,w1-6,19);

        y1=135;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x,y1,x+w,y1);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x,y1+1,x+w,y1+1);
        y1=y1+12;
        h1=32;
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
            memDC.SetPen(wxPen(btnBrush[1].GetColour()));
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(btnBrush[0].GetColour()));
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(confirmButton[ID_CONFIRM_CONFIRM]);
        memDC.DrawLabel(_("确 定"),confirmButton[ID_CONFIRM_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(motion==ID_CONFIRM_CANCEL)
        {
            memDC.SetPen(wxPen(btnBrush[1].GetColour()));
            memDC.SetBrush(btnBrush[1]);
            memDC.SetTextForeground(btnTextColor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(btnBrush[0].GetColour()));
            memDC.SetBrush(btnBrush[0]);
            memDC.SetTextForeground(btnTextColor[0]);
        }
        memDC.DrawRectangle(confirmButton[ID_CONFIRM_CANCEL]);
        memDC.DrawLabel(_("取 消"),confirmButton[ID_CONFIRM_CANCEL],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void UserEditDlg::OnMotionConfirm(wxMouseEvent& event)
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

void UserEditDlg::OnLeaveConfirm(wxMouseEvent& event)
{
    motion=ID_CONFIRM_NONE;
    panelConfirm->Refresh();
}

void UserEditDlg::OnClickConfirm(wxMouseEvent& event)
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
