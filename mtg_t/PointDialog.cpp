#include "wx_pch.h"
#include "PointDialog.h"
#include "MapViewDlg.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(PointDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(PointDialog)
//*)
#include "wx/textctrl.h"
#include "wx/statbox.h"
#include "wx/stattext.h"
//(*IdInit(PointDialog)
//*)
//const long PointDialog::ID_StaticBox1=wxNewId();
//const long PointDialog::ID_StaticBox2=wxNewId();
const long PointDialog::ID_StaticText1=wxNewId();
const long PointDialog::ID_StaticText2=wxNewId();
const long PointDialog::ID_StaticText3=wxNewId();
const long PointDialog::ID_StaticText4=wxNewId();
const long PointDialog::ID_TextCtrl1=wxNewId();
const long PointDialog::ID_TextCtrl2=wxNewId();
const long PointDialog::ID_TextCtrl3=wxNewId();
const long PointDialog::ID_TextCtrl4=wxNewId();
const long PointDialog::ID_Button1=wxNewId();
const long PointDialog::ID_Button2=wxNewId();
const long PointDialog::ID_PANEL1 = wxNewId();                  //标题

BEGIN_EVENT_TABLE(PointDialog,wxDialog)
	//(*EventTable(PointDialog)
	//*)
END_EVENT_TABLE()

//PointDialog::PointDialog(wxWindow* parent,wxWindowID id)
PointDialog::PointDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style): wxDialog( parent, id, title, pos, size, style )
{
	//(*Initialize(PointDialog)
	//Create(parent, id, _("坐标旋转点设置--起点"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	//*)
	//SetClientSize(400,275);
	//Centre(wxBOTH);

	//this->SetSizeHints( 400, 275 );
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int dh=20;
	int x2,y2,w2,h2;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelTitle = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelTitle->IsMaximinize=0;
    panelTitle->m_close_box=1;
    panelTitle->Name=_("坐标旋转点设置--起点");

    x1=0;
    y1=10;
    panel= new wxPanel(this,wxID_ANY,wxPoint(0,230), wxSize(400,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    this->SetFont(chs);
    StaticLine1=new wxStaticLine(this,wxID_ANY,wxPoint(15,31+9), wxSize(370,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    StaticLine2=new wxStaticLine(this,wxID_ANY,wxPoint(15,220), wxSize(370,-1), wxLI_HORIZONTAL, _T("wxID_ANY"));
    //StaticBox1=new wxStaticBox(this,ID_StaticBox1,_("原始坐标"),wxPoint(10,31+y1+10),wxSize(380,70),wxTAB_TRAVERSAL,_T("ID_StaticBox1"));
    StaticText1=new wxStaticText(this,ID_StaticText1,_("X"),wxPoint(15,31+y1+40),wxSize(20,30),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL,_T("ID_StaticText1"));
    TextCtrl1=new wxMyTextCtrl(this,ID_TextCtrl1,_(""),wxPoint(40,31+y1+35),wxSize(155,30),0,wxDefaultValidator,_T("ID_TextCtrl1"));

    StaticText2=new wxStaticText(this,ID_StaticText1,_("Y"),wxPoint(205,31+y1+40),wxSize(20,30),wxALIGN_CENTER,_T("ID_StaticText1"));
    TextCtrl2=new wxMyTextCtrl(this,ID_TextCtrl2,_(""),wxPoint(230,31+y1+35),wxSize(155,30),0,wxDefaultValidator,_T("ID_TextCtrl2"));

    //StaticBox2=new wxStaticBox(this,ID_StaticBox2,_("旋转后坐标"),wxPoint(10,15+y1+110),wxSize(380,70),wxTAB_TRAVERSAL,_T("ID_StaticBox2"));
    StaticText3=new wxStaticText(this,ID_StaticText3,_("X"),wxPoint(15,15+y1+140),wxSize(20,32),wxALIGN_CENTER,_T("ID_StaticText3"));
    TextCtrl3=new wxMyTextCtrl(this,ID_TextCtrl3,_(""),wxPoint(40,15+y1+135),wxSize(150,32),0,wxDefaultValidator,_T("ID_TextCtrl3"));

    StaticText4=new wxStaticText(this,ID_StaticText4,_("Y"),wxPoint(205,15+y1+40),wxSize(20,30),wxALIGN_CENTER,_T("ID_StaticText4"));
    TextCtrl4=new wxMyTextCtrl(this,ID_TextCtrl4,_(""),wxPoint(230,15+y1+135),wxSize(155,30),0,wxDefaultValidator,_T("ID_TextCtrl4"));

    //BtnSave=new wxButton(this,ID_Button1,_("保存"),wxPoint(100,240),wxSize(80,30),0,wxDefaultValidator,_T("ID_Button1"));
    //BtnClose=new wxButton(this,ID_Button2,_("退出"),wxPoint(230,240),wxSize(80,30),0,wxDefaultValidator,_T("ID_Button2"));
//    //BtnSave->Connect(wxEVT_BUTTON,(wxObjectEventFunction)&PointDialog::OnBtnSave,0,this);
//   // BtnExit->Connect(wxEVT_BUTTON,(wxObjectEventFunction)&PointDialog::OnBtnExit,0,this);
   //Connect(ID_Button1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PointDialog::OnBtnSave);
   //Connect(ID_Button2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PointDialog::OnBtnExit);
    panel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&PointDialog::OnPaintPanel,0,this);
    panel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&PointDialog::OnMotionPanel,0,this);
    panel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&PointDialog::OnLeavePanel,0,this);
    panel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&PointDialog::OnClickPanel,0,this);

    motion=ID_PT_NONE;

    level=ID_PT_NONE;

   Init();
}

PointDialog::~PointDialog()
{
	//(*Destroy(PointDialog)
	//*)
}

void PointDialog::OnBtnSave(wxCommandEvent& event)
{
    wxString str1,str2,str3,str4;
    str1=TextCtrl1->GetValue();
    if(!str1.IsEmpty())
    {
        str1.ToDouble(&x0);
    }
    str2=TextCtrl2->GetValue();
    if(!str2.IsEmpty())
    {
        str2.ToDouble(&y0);
    }
    str3=TextCtrl3->GetValue();
    if(!str3.IsEmpty())
    {
        str3.ToDouble(&x);
    }
    str4=TextCtrl4->GetValue();
    if(!str4.IsEmpty())
    {
        str4.ToDouble(&y);
    }
    if((!str1.IsEmpty()&&!str2.IsEmpty())&&(!str3.IsEmpty()&&!str4.IsEmpty()))
    {
        if(flag==0)
        {
            if(ok==0||ok==2)
               ok=ok+1;
        }
        else if(flag==1)
        {
            if(ok==0||ok==1)
                ok=ok+2;
        }
    }
    //wxMessageBox(_("保存成功！"));
    ((MapViewDlg*)GetParent())->rotatemap();
    ///EndModal(wxID_OK);
}

void PointDialog::OnBtnExit(wxCommandEvent& event)
{
    Close();
    ((MapViewDlg*)GetParent())->pushed=0;
}

void PointDialog::Init()
{
    if(flag==1)
    {
        //SetTitle(_("坐标旋转点设置--终点"));
        panelTitle->Name=_("终点设置");
    }
    else if(flag==0)
    {
        //SetTitle(_("坐标旋转点设置--起点"));
        panelTitle->Name=_("起点设置");
    }
    TextCtrl1->SetValue(wxString::Format(wxT("%.4lf"),x0));
    TextCtrl2->SetValue(wxString::Format(wxT("%.4lf"),y0));
    TextCtrl3->SetValue(wxString::Format(wxT("%.4lf"),x));
    TextCtrl4->SetValue(wxString::Format(wxT("%.4lf"),y));
}

void PointDialog::OnPaintPanel(wxPaintEvent& event)
{
    wxPaintDC dc(panel);
    int w,h;
    panel->GetClientSize(&w,&h);
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
//        memDC.SetPen(wxPen(wxColor(117,117,117)));
//        memDC.DrawLine(x,y,w,y);
//        memDC.SetPen(wxPen(wxColor(255,255,255)));
//        memDC.DrawLine(x,y+1,w,y+1);

        int x1,y1,w1,h1;
        x1=75;
        y1=20;
        h1=32;
        w1=w-75*2;

        y1=h-55;
//        memDC.SetPen(wxPen(wxColor(117,117,117)));
//        memDC.DrawLine(x,y1,x+w,y1);
//        memDC.SetPen(wxPen(wxColor(255,255,255)));
//        memDC.DrawLine(x,y1+1,x+w,y1+1);
//        y1=y1+12;
        y1=0;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,2);
        /*ptButton[ID_PT_SAVE].x=x1+1;
        ptButton[ID_PT_SAVE].y=y1+1;
        ptButton[ID_PT_SAVE].width=w1/2-1;
        ptButton[ID_PT_SAVE].height=h1-2;

        ptButton[ID_PT_EXIT].x=ptButton[ID_PT_SAVE].x+ptButton[ID_PT_SAVE].width;
        ptButton[ID_PT_EXIT].y=ptButton[ID_PT_SAVE].y;
        ptButton[ID_PT_EXIT].width=ptButton[ID_PT_SAVE].width;
        ptButton[ID_PT_EXIT].height=ptButton[ID_PT_SAVE].height;
        if(level==ID_PT_SAVE || motion==ID_PT_SAVE)
        {
            memDC.SetPen(wxPen(wxColor(255,255,0)));
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.DrawRectangle(ptButton[ID_PT_SAVE]);
        }
        memDC.DrawLabel(_("确 定"),ptButton[ID_PT_SAVE],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        if(level==ID_PT_EXIT || motion==ID_PT_EXIT)
        {
            memDC.SetPen(wxPen(wxColor(255,255,0)));
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.DrawRectangle(ptButton[ID_PT_EXIT]);
        }

        memDC.DrawLabel(_("取 消"),ptButton[ID_PT_EXIT],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);*/

        rect[ID_PT_SAVE].x=x1+1;
        rect[ID_PT_SAVE].y=y1+1;
        rect[ID_PT_SAVE].width=w1/2-1;
        rect[ID_PT_SAVE].height=h1-2;

        if(motion==ID_PT_SAVE)
        {
            memDC.SetPen(wxPen(wxColor(255,255,0)));
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.DrawRectangle(rect[ID_PT_SAVE]);
        }
        memDC.DrawLabel(_("确 定"),rect[ID_PT_SAVE],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1+w1/2-1,y1+2,x1+w1/2-1,y1+h1-2);

        rect[ID_PT_EXIT].x=rect[ID_PT_SAVE].x+rect[ID_PT_SAVE].width;
        rect[ID_PT_EXIT].y=rect[ID_PT_SAVE].y;
        rect[ID_PT_EXIT].width=rect[ID_PT_SAVE].width;
        rect[ID_PT_EXIT].height=rect[ID_PT_SAVE].height;
        if(motion==ID_PT_EXIT)
        {
            memDC.SetPen(wxPen(wxColor(255,255,0)));
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.DrawRectangle(rect[ID_PT_EXIT]);
        }

        memDC.DrawLabel(_("取 消"),rect[ID_PT_EXIT],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void PointDialog::OnMotionPanel(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>rect[ID_PT_SAVE].y && y<rect[ID_PT_SAVE].y+rect[ID_PT_SAVE].height)
    {
        if(x>rect[ID_PT_SAVE].x && x<rect[ID_PT_SAVE].x+rect[ID_PT_SAVE].width)
        {
            motion=ID_PT_SAVE;
        }
        else if(x>rect[ID_PT_EXIT].x && x<rect[ID_PT_EXIT].x+rect[ID_PT_EXIT].width)
        {
            motion=ID_PT_EXIT;
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
    panel->Refresh();
}

void PointDialog::OnLeavePanel(wxMouseEvent& event)
{
    motion=ID_PT_NONE;
    panel->Refresh();
}

void PointDialog::OnClickPanel(wxMouseEvent& event)
{
    if(motion==ID_PT_SAVE)
    {
        level=ID_PT_SAVE;
        wxString str1,str2,str3,str4;
        str1=TextCtrl1->GetValue();
        if(!str1.IsEmpty())
        {
            str1.ToDouble(&x0);
        }
        str2=TextCtrl2->GetValue();
        if(!str2.IsEmpty())
        {
            str2.ToDouble(&y0);
        }
        str3=TextCtrl3->GetValue();
        if(!str3.IsEmpty())
        {
            str3.ToDouble(&x);
        }
        str4=TextCtrl4->GetValue();
        if(!str4.IsEmpty())
        {
            str4.ToDouble(&y);
        }
        if((!str1.IsEmpty()&&!str2.IsEmpty())&&(!str3.IsEmpty()&&!str4.IsEmpty()))
        {
            if(flag==0)
            {
                if(ok==0||ok==2)
                   ok=ok+1;
            }
            else if(flag==1)
            {
                if(ok==0||ok==1)
                    ok=ok+2;
            }
        }
        ((MapViewDlg*)GetParent())->rotatemap();
        ///EndModal(wxID_OK);
    }
    else if(motion==ID_PT_EXIT)
    {
        level=ID_PT_EXIT;
        Close();
        ((MapViewDlg*)GetParent())->cancel();
        ///EndModal(wxID_CANCEL);
    }
    panel->Refresh();
}
