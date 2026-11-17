#include "wx_pch.h"
#include "MDTitle.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MDTitle)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MDTitle)
//*)

#include <wx/stdpaths.h>
#include <wx/msgdlg.h>
#include <wx/display.h>
//(*IdInit(MDTitle)

//*)

BEGIN_EVENT_TABLE(MDTitle,wxPanel)
	//(*EventTable(MDTitle)
	//*)
END_EVENT_TABLE()

MDTitle::MDTitle(wxWindow* parent,
                 wxWindowID id,
                 const wxPoint& pos,
                 const wxSize& size ,
                 long style,
                 const wxString& name ):wxPanel(parent,id,pos,size,style,name)
{
    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);

    bmpApp.LoadFile(path+_("/plugins/appico.png"),wxBITMAP_TYPE_PNG);
	this->Connect(wxEVT_PAINT,wxPaintEventHandler( MDTitle::OnPaint), NULL, this );
	this->Connect(wxEVT_MOTION,wxMouseEventHandler( MDTitle::OnMotion), NULL, this );
	this->Connect(wxEVT_LEFT_DOWN,wxMouseEventHandler( MDTitle::OnLeftDown), NULL, this );
	this->Connect(wxEVT_LEFT_UP,wxMouseEventHandler( MDTitle::OnClick), NULL, this );
	this->Connect(wxEVT_LEFT_DCLICK,wxMouseEventHandler( MDTitle::OnDClick), NULL, this );
	this->Connect(wxEVT_LEAVE_WINDOW,wxMouseEventHandler( MDTitle::OnLeave), NULL, this );
	//this->Connect( wxEVT_SIZE,wxSizeEventHandler(MDTitle::OnSize));
    this->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    mouse_pos=POS_NONE;
    w_move=0;
    isMax=0;
    m_close_box=1;
    m_maximize_box=0;
    m_minimize_box=0;
    IsMaximinize=1;
}

MDTitle::~MDTitle()
{
	//(*Destroy(MDTitle)
	//*)
	this->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MDTitle::OnMotion ));
    this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MDTitle::OnPaint));
    this->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MDTitle::OnLeftDown ));
    this->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( MDTitle::OnClick ));
    this->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MDTitle::OnDClick ));
    this->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( MDTitle::OnLeave ));
    //this->Disconnect(wxEVT_SIZE,wxSizeEventHandler(MDTitle::OnSize));
}

void MDTitle::OnPaint(wxPaintEvent& event)
{
    if(w_move==1) return;
    wxPaintDC dc(this);
    int w,h;
    GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        memDC.SetBrush(wxBrush(wxColor(98,159,235)));
        memDC.SetPen(wxPen(wxColor(63,103,140)));
        memDC.DrawRectangle(0,0,w,h);

        if(bmpApp.IsOk()) memDC.DrawBitmap(bmpApp,1,-2);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetTextForeground(wxColor(255,255,255));
        memDC.SetFont(chs);
        memDC.DrawLabel(Name,wxRect(38,0,0,h),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        ///画关闭按钮
        if(m_close_box==1)
        {
            if(mouse_pos==POS_CLOSE)
            {
                memDC.SetBrush(wxBrush(wxColor(210,65,40)));
                memDC.SetPen(wxPen(wxColor(210,65,40)));
                memDC.DrawRectangle(w-30,1,29,29);
            }

            memDC.SetPen(wxPen(wxColor(255,255,255),2));
            memDC.DrawLine(w-20,10,w-10,20);
            memDC.DrawLine(w-20,20,w-10,10);
        }

        if(m_minimize_box==1)
        {
            if(mouse_pos==POS_MINIMIZE)
            {
                memDC.SetBrush(wxBrush(wxColor(120,175,220)));
                memDC.SetPen(wxPen(wxColor(120,175,220)));
                memDC.DrawRectangle(w-90,1,29,29);
            }

            memDC.SetPen(wxPen(wxColor(255,255,255),2));
            memDC.DrawLine(w-80,20,w-70,20);
        }

        if(m_maximize_box==1)
        {
            if(mouse_pos==POS_MAXIMIZE)
            {
                memDC.SetBrush(wxBrush(wxColor(120,175,220)));
                memDC.SetPen(wxPen(wxColor(120,175,220)));
                memDC.DrawRectangle(w-60,1,29,29);
            }

            memDC.SetPen(wxPen(wxColor(255,255,255),2));
            if(isMax==0)
            {
                memDC.DrawLine(w-50,10,w-40,10);
                memDC.SetPen(wxPen(wxColor(255,255,255)));
                memDC.DrawLine(w-50,20,w-40,20);
                memDC.DrawLine(w-50,10,w-50,21);
                memDC.DrawLine(w-40,10,w-40,21);
            }
            else
            {
                memDC.DrawLine(w-48,10,w-40,10);
                memDC.DrawLine(w-52,14,w-44,14);
                memDC.SetPen(wxPen(wxColor(255,255,255)));
                memDC.DrawLine(w-48,18,w-40,18);
                memDC.DrawLine(w-52,21,w-44,21);
                memDC.DrawLine(w-48,10,w-48,19);
                memDC.DrawLine(w-52,14,w-52,22);
                memDC.DrawLine(w-40,10,w-40,19);
                memDC.DrawLine(w-44,14,w-44,22);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MDTitle::OnMotion(wxMouseEvent& event)
{
    int x,y;
    int w,h;
    x=event.GetX();
    y=event.GetY();
    GetClientSize(&w,&h);
    if(w_move==1)
    {
        wxWindow* p = this->GetParent();
        p->GetScreenPosition(&m_x0,&m_y0);
        p->SetPosition(wxPoint(m_x0+x-m_x1,m_y0+y-m_y1));
    }
    else
    {
        if(y>0 && y<h)
        {
            if(x>w-30 && x<w)
            {
                if(m_close_box==1)
                {
                    mouse_pos=POS_CLOSE;
                }
                else
                {
                    mouse_pos=POS_CAPTION;
                }
            }
            else if(x>w-60 && x<w-30)
            {
                if(m_maximize_box==1)
                {
                    mouse_pos=POS_MAXIMIZE;
                }
                else
                {
                    mouse_pos=POS_CAPTION;
                }
            }
            else if(x>w-90 && x<w-60)
            {
                if(m_minimize_box==1)
                {
                    mouse_pos=POS_MINIMIZE;
                }
                else
                {
                    mouse_pos=POS_CAPTION;
                }
            }
            else
            {
                mouse_pos=POS_CAPTION;
            }
        }
        else
        {
            mouse_pos=POS_NONE;
        }
    }
    Refresh();
}


void MDTitle::OnLeftDown(wxMouseEvent& event)
{
    m_x1=event.GetX();
    m_y1=event.GetY();
    if(mouse_pos==POS_CAPTION)
    {
        w_move=1;
    }
}

void MDTitle::OnClick(wxMouseEvent& event)
{
    int x,y;
    x = event.GetX();
    y = event.GetY();
    wxWindow* p = this->GetParent();
    wxFrame* pf = (wxFrame*)p;
    if(mouse_pos==POS_CLOSE)
    {
        p->Close();
    }
    else if(mouse_pos==POS_MINIMIZE)
    {
        pf->Iconize(true);
    }
    else if(mouse_pos==POS_MAXIMIZE)
    {
        if(isMax==0)
        {
            isMax = 1;
            rect1 = p->GetScreenRect();
            wxDisplay Screen;
            wxRect ClientRect = Screen.GetClientArea();
            p->SetSize(ClientRect);
        }
        else
        {
            isMax=0;
            p->SetSize(rect1);
        }
    }
    w_move=0;
}

void MDTitle::OnDClick(wxMouseEvent& event)
{
    if(IsMaximinize==1)
    {
        if(mouse_pos==POS_CAPTION)
        {
            wxWindow* p = this->GetParent();
            if(isMax==0)
            {
                isMax = 1;
                rect1 = p->GetScreenRect();
                wxDisplay Screen;
                wxRect ClientRect = Screen.GetClientArea();
                p->SetSize(ClientRect);
            }
            else
            {
                isMax=0;
                p->SetSize(rect1);
            }
        }
    }
}

void MDTitle::OnLeave(wxMouseEvent& event)
{
    w_move=0;
    mouse_pos=POS_NONE;
    Refresh();
}

/*
void MDTitle::OnSize(wxSizeEvent& event)
{
    this->Refresh();
}*/
