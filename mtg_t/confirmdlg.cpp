///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "confirmdlg.h"
#include "mtg_tApp.h"
#include <wx/dcclient.h>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
const long ConfirmDlg::ID_PANEL1 = wxNewId();
const long ConfirmDlg::ID_PANEL2 = wxNewId();
///////////////////////////////////////////////////////////////////////////

ConfirmDlg::ConfirmDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
    m_title->Name=_("确认");
    panelConfirm = new wxPanel(this, ID_PANEL2, wxPoint(0,31), wxSize(w,h-31), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelConfirm->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelConfirm->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ConfirmDlg::OnPaintConfirm,0,this);
    panelConfirm->Connect(wxEVT_MOTION,(wxObjectEventFunction)&ConfirmDlg::OnMotionConfirm,0,this);
    panelConfirm->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&ConfirmDlg::OnLeaveConfirm,0,this);
    panelConfirm->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ConfirmDlg::OnClickConfirm,0,this);
    confirmMsg = _("确定退出软件？");
	type=0;      //确认对话框1错误提示对话框
	this->Centre( wxBOTH );
}

ConfirmDlg::~ConfirmDlg()
{
    panelConfirm->Disconnect(wxEVT_PAINT,(wxObjectEventFunction)&ConfirmDlg::OnPaintConfirm,0,this);
    panelConfirm->Disconnect(wxEVT_PAINT,(wxObjectEventFunction)&ConfirmDlg::OnMotionConfirm,0,this);
    panelConfirm->Disconnect(wxEVT_PAINT,(wxObjectEventFunction)&ConfirmDlg::OnLeaveConfirm,0,this);
    panelConfirm->Disconnect(wxEVT_PAINT,(wxObjectEventFunction)&ConfirmDlg::OnClickConfirm,0,this);
}

void ConfirmDlg::OnPaintConfirm(wxPaintEvent& event)
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
            m_title->Name=_("提示");
            m_title->Refresh();
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
        }
        else if(type==1)
        {
            m_title->Name=_("错误");
            m_title->Refresh();
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
                memDC.SetPen(btnPen[1]);
                memDC.SetBrush(btnBrush[1]);
                memDC.SetTextForeground(btnTextColor[1]);
            }
            else
            {
                memDC.SetPen(btnPen[0]);
                memDC.SetBrush(btnBrush[0]);
                memDC.SetTextForeground(btnTextColor[0]);
            }
            memDC.DrawRoundedRectangle(confirmButton[ID_CONFIRM_CONFIRM],3);
            memDC.DrawLabel(_("确 定"),confirmButton[ID_CONFIRM_CONFIRM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void ConfirmDlg::OnMotionConfirm(wxMouseEvent& event)
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

void ConfirmDlg::OnLeaveConfirm(wxMouseEvent& event)
{
    motion=ID_CONFIRM_NONE;
    panelConfirm->Refresh();
}

void ConfirmDlg::OnClickConfirm(wxMouseEvent& event)
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
