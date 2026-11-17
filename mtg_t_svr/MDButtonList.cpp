#include "wx_pch.h"
#include "MDButtonList.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MDButtonList)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MDButtonList)
//*)

#include <wx/stdpaths.h>
#include <wx/msgdlg.h>
#include <wx/display.h>
//(*IdInit(MDButtonList)

//*)

BEGIN_EVENT_TABLE(MDButtonList,wxPanel)
	//(*EventTable(MDButtonList)
	//*)
END_EVENT_TABLE()

MDButtonList::MDButtonList(wxWindow* parent,
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

    bmpArrow1.LoadFile(path+_("/plugins/btn_arrow1.png"),wxBITMAP_TYPE_PNG);
    bmpArrow2.LoadFile(path+_("/plugins/btn_arrow2.png"),wxBITMAP_TYPE_PNG);

	this->Connect(wxEVT_PAINT,wxPaintEventHandler( MDButtonList::OnPaint), NULL, this );
	this->Connect(wxEVT_MOTION,wxMouseEventHandler( MDButtonList::OnMotion), NULL, this );
	this->Connect(wxEVT_LEFT_DOWN,wxMouseEventHandler( MDButtonList::OnLeftDown), NULL, this );
	//this->Connect(wxEVT_LEFT_UP,wxMouseEventHandler( MDButtonList::OnClick), NULL, this );
	this->Connect(wxEVT_LEAVE_WINDOW,wxMouseEventHandler( MDButtonList::OnLeave), NULL, this );
	//this->Connect( wxEVT_SIZE,wxSizeEventHandler(MDButtonList::OnSize));
    this->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    for(int i=0;i<20;i++)
    {
        btn_use[i]=0;
        btn_label[i]=_("");
    }
    btns=0;
    pos_left=0;
    btn_clicked=-1;
    btn_on=-1;
    btn_height=27;
    btn_label_align=0;
}

MDButtonList::~MDButtonList()
{
	//(*Destroy(MDButtonList)
	//*)
	this->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MDButtonList::OnMotion ));
    this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MDButtonList::OnPaint));
    this->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MDButtonList::OnLeftDown ));
    //this->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( MDButtonList::OnClick ));
    this->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( MDButtonList::OnLeave ));
    //this->Disconnect(wxEVT_SIZE,wxSizeEventHandler(MDButtonList::OnSize));
    this->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
}

void MDButtonList::AddButton(wxString label)
{
    if(btns>19) return;
    btn_use[btns]=1;
    btn_label[btns] = label;
    btns++;
    Refresh();
}

void MDButtonList::InertButton(wxString label,int id)
{
    if(id>19) return;
    int n;
    if(btns>19)
    {
        n=19;
    }
    else
    {
        n=btns;
        btn_use[btns]=1;
        btns++;
    }

    for(int i=n;i>id;i--)
    {
        btn_label[i] = btn_label[i-1];
    }
    btn_label[id]=label;
    Refresh();
}

void MDButtonList::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    int w,h;
    GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);

        memDC.SetBrush(wxBrush(wxColor(204,204,204)));
        if(pos_left==0)
        {
            memDC.DrawRectangle(-1,10,w+1,h-10);
            memDC.SetBrush(wxBrush(wxColor(255,255,255),wxBDIAGONAL_HATCH));
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.DrawRectangle(-1,10,w+1,h-10);
        }
        else if(pos_left==1)
        {
            memDC.DrawRectangle(0,10,w+1,h-10);
            memDC.SetBrush(wxBrush(wxColor(255,255,255),wxBDIAGONAL_HATCH));
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.DrawRectangle(0,10,w+1,h-10);
        }

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetTextForeground(wxColor(71,71,71));
        memDC.SetFont(chs);
        int x,y,x2;
        int r,g,b;

        for(int i=0;i<btns;i++)
        {
            y=11+i*btn_height;
            if(pos_left==0)
            {
                x=0;
                x2=w-1;
            }
            else if(pos_left==1)
            {
                x=1;
                x2=w;
            }

            if(btn_on==i)
            {
                r=200;
                g=225;
                b=250;
                for(int j=0;j<btn_height-2;j++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*j/(btn_height-2),g+20*j/(btn_height-2),b)));
                    memDC.DrawLine(x,y,x2,y);
                    y++;
                }
            }
            else
            {
                r=236;
                g=236;
                b=236;
                for(int j=0;j<btn_height-2;j++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x,y,x2,y);
                    r--;
                    g--;
                    b--;
                    y++;
                }
            }
            memDC.SetPen(wxPen(wxColor(236,236,236)));
            memDC.DrawLine(x,y,x2,y);
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.DrawLine(x,y+1,x2,y+1);
            if(btn_clicked==i)
            {
                if(btn_label_align==0)
                {
                    memDC.DrawLabel(_("◆ ")+btn_label[i],wxRect(10,y-btn_height+2,w-20,btn_height-1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }
                else if(btn_label_align==1)
                {
                    memDC.DrawLabel(_("◆ ")+btn_label[i],wxRect(10,y-btn_height+2,w-20,btn_height-1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                }
                else if(btn_label_align==2)
                {
                    memDC.DrawLabel(_("◆ ")+btn_label[i],wxRect(10,y-btn_height+2,w-20,btn_height-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }

            }
            else
            {
                if(btn_label_align==0)
                {
                    memDC.DrawLabel(_("◇ ")+btn_label[i],wxRect(10,y-btn_height+2,w-20,btn_height-1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                }
                else if(btn_label_align==1)
                {
                    memDC.DrawLabel(_("◇ ")+btn_label[i],wxRect(10,y-btn_height+2,w-20,btn_height-1),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
                }
                else if(btn_label_align==2)
                {
                    memDC.DrawLabel(_("◇ ")+btn_label[i],wxRect(10,y-btn_height+2,w-20,btn_height-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
            //memDC.DrawLabel(btn_label[i],wxRect(x+w/10,y-btn_height+2,w*9/10,btn_height-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}


void MDButtonList::OnMotion(wxMouseEvent& event)
{
    int x,y;
    int w,h;
    x=event.GetX();
    y=event.GetY();
    GetClientSize(&w,&h);

    for(int i=0;i<btns;i++)
    {
        if(x>0 && x<w)
        {
            if(y>11+i*btn_height && y<11+i*btn_height+btn_height)
            {
                btn_on=i;
                break;
            }
            else if(i==btns-1)
            {
                btn_on=-1;
                break;
            }
            else
            {
                continue;
            }
        }
        else
        {
            btn_on=-1;
        }
    }
    btn_left_down=-1;
    Refresh();
}


void MDButtonList::OnLeftDown(wxMouseEvent& event)
{
    btn_left_down=btn_on;
}

void MDButtonList::OnLeave(wxMouseEvent& event)
{
    btn_on=-1;
    Refresh();
}

int MDButtonList::GetNumberButtons()
{
    return btns;
}
