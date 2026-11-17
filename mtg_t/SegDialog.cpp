#include "wx_pch.h"
#include "SegDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(SegDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(SegDialog)
#include <wx/font.h>
//*)

#include "KeyBoard.h"

#define PI  3.1415926535897932384626433832795

//(*IdInit(SegDialog)
const long SegDialog::ID_PANEL1 = wxNewId();        //主panel
const long SegDialog::ID_BUTTON1 = wxNewId();        //主panel
const long SegDialog::ID_BUTTON2 = wxNewId();        //主panel
const long SegDialog::ID_STATICTEXT1 = wxNewId();
const long SegDialog::ID_STATICLINE1 = wxNewId();
const long SegDialog::ID_STATICTEXT2 = wxNewId();
const long SegDialog::ID_STATICTEXT3 = wxNewId();
const long SegDialog::ID_TEXTCTRL1 = wxNewId();
const long SegDialog::ID_TEXTCTRL2 = wxNewId();
const long SegDialog::ID_TEXTCTRL3 = wxNewId();
const long SegDialog::ID_TEXTCTRL4 = wxNewId();
const long SegDialog::ID_STATICLINE2 = wxNewId();
const long SegDialog::ID_CHOICE1 = wxNewId();
const long SegDialog::ID_CHOICE2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SegDialog,wxDialog)
	//(*EventTable(SegDialog)
	//*)
END_EVENT_TABLE()

SegDialog::SegDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SegDialog)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxCAPTION, _T("wxID_ANY"));
	SetClientSize(wxSize(600,450));
	panelMain = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(600,450), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	wxFont StaticText1Font(12,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Segtype = new wxChoice(panelMain, ID_CHOICE1, wxPoint(380,160), wxSize(140,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Kpos = new wxChoice(panelMain, ID_CHOICE2, wxPoint(380,230), wxSize(140,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Text1 = new wxMyTextCtrl(panelMain, ID_TEXTCTRL1, wxEmptyString, wxPoint(380,90), wxSize(140,25), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Text2 = new wxMyTextCtrl(panelMain, ID_TEXTCTRL2, wxEmptyString, wxPoint(380,160), wxSize(140,25), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	Text3 = new wxMyTextCtrl(panelMain, ID_TEXTCTRL3, wxEmptyString, wxPoint(380,230), wxSize(140,25), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	Text4 = new wxMyTextCtrl(panelMain, ID_TEXTCTRL4, wxEmptyString, wxPoint(380,300), wxSize(140,25), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	Button1 = new wxButton(panelMain, ID_BUTTON1, _("设 置"), wxPoint(416,410), wxSize(72,-1), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(panelMain, ID_BUTTON2, _("退 出"), wxPoint(513,410), wxSize(72,-1), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button1->SetForegroundColour(wxColor(68,68,68));
	Button2->SetForegroundColour(wxColor(68,68,68));
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&SegDialog::OnTypeSelect);
	Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&SegDialog::OnKposSelect);

	panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&SegDialog::OnPaintPanel,0,this);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SegDialog::OnBtnSave);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SegDialog::OnBtnQuit);
	//*)

    int n = 360/mtg->segset.Ks;
    for(int i=0;i<n;i++)
    {
        Kpos->Append(wxString::Format(_("%d"),i+1));
    }
    Kpos->SetSelection(mtg->segs[4].kpos-1);
    if(mtg->segset.type==0)
    {
        Segtype->Append(wxString::Format(_("通用环")));
        Segtype->SetSelection(0);
        Segtype->Enable(false);
    }
    else
    {
        Segtype->Append(wxString::Format(_("标准环")));
        Segtype->Append(wxString::Format(_("左转弯")));
        Segtype->Append(wxString::Format(_("右转弯")));
        Segtype->Enable(true);
        Segtype->SetSelection(0);
    }
    //LoadData();
    //TextPassword->Connect(wxEVT_LEFT_UP,wxMouseEventHandler(SegDialog::OnSetFocus),NULL,this);
}

SegDialog::~SegDialog()
{
	//(*Destroy(SegDialog)
	//*)
}

void SegDialog::LoadData()
{
    if(type == 0)
    {
        Text1->SetValue(wxString::Format(_("%d"),mtg->segs[4].numb));
        //Text2->SetValue(wxString::Format(_("%.4f"),mtg->seg1.mile));
        Kpos->SetSelection(mtg->segs[4].kpos-1);
        Segtype->SetSelection(mtg->segs[4].type);
    }
    else if(type == 1)
    {
        if(mtg->itbm==1)
        {
            Text1->SetValue(wxString::Format(_("%.4f"),mtg->plc.laj));
            Text2->SetValue(wxString::Format(_("%.4f"),mtg->plc.uaj));
            Text3->SetValue(wxString::Format(_("%.4f"),mtg->plc.raj));
            Text4->SetValue(wxString::Format(_("%.4f"),mtg->plc.daj));
        }
        else
        {
            Text1->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].laj));
            Text2->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].uaj));
            Text3->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].raj));
            Text4->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].daj));
        }
    }
    else if(type == 2)
    {
        if(mtg->itbm==1)
        {
            Text1->SetValue(wxString::Format(_("%.4f"),mtg->plc.lbaj));
            Text2->SetValue(wxString::Format(_("%.4f"),mtg->plc.ubaj));
            Text3->SetValue(wxString::Format(_("%.4f"),mtg->plc.rbaj));
            Text4->SetValue(wxString::Format(_("%.4f"),mtg->plc.dbaj));
        }
        else
        {
            Text1->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].lhj));
            Text2->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].uhj));
            Text3->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].rhj));
            Text4->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].dhj));
        }
    }
    else if(type == 3)
    {
        Text1->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].lgap));
        Text2->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].ugap));
        Text3->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].rgap));
        Text4->SetValue(wxString::Format(_("%.4f"),mtg->segs[4].dgap));
    }
}

void SegDialog::OnTypeSelect(wxCommandEvent& event)
{
    Text1->SetFocus();
}

void SegDialog::OnKposSelect(wxCommandEvent& event)
{
    panelMain->RefreshRect(wxRect(20,60,320,320));
}

void SegDialog::OnBtnSave(wxCommandEvent& event)
{
    long lval;
    double dval;
    if(type == 0)
    {
        Text1->GetValue().ToLong(&lval);
        //mtg->segs[4].numb = lval;
        Text2->GetValue().ToDouble(&dval);
        mtg->segs[4].mile = dval;
        mtg->segs[4].kpos = Kpos->GetSelection()+1;
        mtg->segs[4].type = Segtype->GetSelection();
        //time_t now;
        //time(&now);
        //mtg->segs[4].t = now;
        //mtg_store_seg(mtg);
    }
    else if(type == 1)
    {
        Text1->GetValue().ToDouble(&dval);
        mtg->segs[5].laj = dval;
        Text2->GetValue().ToDouble(&dval);
        mtg->segs[5].uaj = dval;
        Text3->GetValue().ToDouble(&dval);
        mtg->segs[5].raj = dval;
        Text4->GetValue().ToDouble(&dval);
        mtg->segs[5].daj = dval;
    }
    else if(type == 2)
    {
        Text1->GetValue().ToDouble(&dval);
        mtg->segs[5].lhj = dval;
        Text2->GetValue().ToDouble(&dval);
        mtg->segs[5].uhj = dval;
        Text3->GetValue().ToDouble(&dval);
        mtg->segs[5].rhj = dval;
        Text4->GetValue().ToDouble(&dval);
        mtg->segs[5].dhj = dval;
    }
    else if(type == 3)
    {
        Text1->GetValue().ToDouble(&dval);
        mtg->segs[5].lgap = dval;
        Text2->GetValue().ToDouble(&dval);
        mtg->segs[5].ugap = dval;
        Text3->GetValue().ToDouble(&dval);
        mtg->segs[5].rgap = dval;
        Text4->GetValue().ToDouble(&dval);
        mtg->segs[5].dgap = dval;
    }
}

void SegDialog::OnBtnQuit(wxCommandEvent& event)
{
    Destroy();
}

void SegDialog::OnPaintPanel(wxPaintEvent& event)
{
    wxPaintDC dc(panelMain);
    int w,h;
    panelMain->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        wxFont chsFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont engFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetBrush(wxBrush(wxColor(240,240,240)));
        memDC.SetPen(wxPen(wxColor(240,240,240)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(0,40,w,40);
        memDC.DrawLine(0,400,w,400);
        memDC.SetPen(wxPen(wxColor(168,168,168)));
        memDC.DrawLine(0,39,w,39);
        memDC.DrawLine(0,399,w,399);

        memDC.SetFont(engFont);
        memDC.SetTextForeground(wxColor(88,88,88));
        if(type==0)
        {
            memDC.DrawLabel(_("上环管环参数"),wxRect(w/2,20,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            memDC.DrawLabel(_("管环编号"),wxRect(380,75,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            //memDC.DrawLabel(_("管环里程"),wxRect(380,145,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            //memDC.DrawLabel(_("管环类型"),wxRect(380,215,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            //memDC.DrawLabel(_("K块位置"),wxRect(380,285,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("管环类型"),wxRect(380,145,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("K块位置"),wxRect(380,215,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            //memDC.DrawLabel(_("K块位置"),wxRect(380,285,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            //Text2->SetEditable(false);
            Segtype->Show(true);
            Kpos->Show(true);
            //Segtype->SetPosition(wxPoint(380,160));
            //Kpos->SetPosition(wxPoint(380,230));
            Text3->Show(false);
            Text4->Show(false);


            //Text1->SetValue(wxString::Format(_("%d"),mtg->seg1.numb));
            //Text2->SetValue(wxString::Format(_("%.4f"),mtg->seg1.mile));
            //Kpos->SetSelection(mtg->seg1.kpos-1);
            //Segtype->SetSelection(mtg->seg1.type);

            double roll = Kpos->GetSelection()*mtg->segset.Ks+mtg->segset.Ks;
            roll = roll*PI/180;
            roll = roll + PI*3/2;
            PaintSeg(&memDC,wxRect(20,60,320,320),3,roll);
        }
        else if(type==1)
        {
            memDC.DrawLabel(_("推进油缸行程[mm]"),wxRect(w/2,20,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("左组油缸行程"),wxRect(380,75,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("上组油缸行程"),wxRect(380,145,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("右组油缸行程"),wxRect(380,215,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("下组油缸行程"),wxRect(380,285,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            Text3->Show(true);
            Text4->Show(true);
            Segtype->Show(false);
            Kpos->Show(false);

            double roll = Kpos->GetSelection()*mtg->segset.Ks+mtg->segset.Ks;
            roll = roll*PI/180;
            roll = roll + PI*3/2;

            PaintSeg(&memDC,wxRect(20,60,320,320),0,roll);
        }
        else if(type==2)
        {
            memDC.DrawLabel(_("盾尾铰接油缸行程[mm]"),wxRect(w/2,20,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("左组油缸行程"),wxRect(380,75,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("上组油缸行程"),wxRect(380,145,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("右组油缸行程"),wxRect(380,215,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("下组油缸行程"),wxRect(380,285,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            Text3->Show(true);
            Text4->Show(true);
            Segtype->Show(false);
            Kpos->Show(false);

            double roll = Kpos->GetSelection()*mtg->segset.Ks+mtg->segset.Ks;
            roll = roll*PI/180;
            roll = roll + PI*3/2;
            PaintSeg(&memDC,wxRect(20,60,320,320),1,roll);
        }
        else if(type==3)
        {
            memDC.DrawLabel(_("盾尾间隙[mm]"),wxRect(w/2,20,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("盾尾间隙：左"),wxRect(380,75,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("盾尾间隙：上"),wxRect(380,145,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("盾尾间隙：右"),wxRect(380,215,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(_("盾尾间隙：下"),wxRect(380,285,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            Text3->Show(true);
            Text4->Show(true);
            Segtype->Show(false);
            Kpos->Show(false);

            double roll = Kpos->GetSelection()*mtg->segset.Ks+mtg->segset.Ks;
            roll = roll*PI/180;
            roll = roll + PI*3/2;
            PaintSeg(&memDC,wxRect(20,60,320,320),2,roll);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
    //PaintSeg(wxMemoryDC* dc,wxRect rect,int step,double roll);
}

void SegDialog::PaintSeg(wxMemoryDC* dc,wxRect rect,int step,double roll)
{
    if(rect.width==0 || rect.height==0)
    {
        return;
    }
    else
    {
        int w,h;
        w=rect.width;
        h=rect.height;
        wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
        dc->SetTextForeground(wxColor(0,0,0));
        dc->SetPen(wxPen(wxColor(130,130,130)));
        dc->SetBrush(wxBrush(wxColor(255,255,255)));
        dc->DrawRectangle(rect.x,rect.y,w,h);
        dc->SetFont(boldFont);

        double radius = w<h?w:h;
        double radius1 = radius*7/20;
        double radius2 = radius*9/20;
        double radius3 = 10;
        double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
        double angle = roll-mtg->blocks[0].angle/2.0;
        wxPen pen1=wxPen(wxColor(30,30,30));
        wxPen pen2=wxPen(wxColor(30,30,30));
        wxPen pen3=wxPen(wxColor(30,30,30),1,wxLONG_DASH);

        x1=rect.x+w/2.0;
        y1=rect.y+h/2.0;
        dc->SetPen(wxPen(wxColor(133,133,133),4));
        dc->DrawCircle(x1,y1,radius2);
        //wxMessageBox(wxString::Format(_("%d"),mtg->nblk));
        for(int i=0;i<mtg->nblk;i++)
        {
            x2=x1+radius1*cos(angle+0.02);
            y2=y1+radius1*sin(angle+0.02);
            x4=x1+(radius1-radius3*2)*cos(angle+0.02);
            y4=y1+(radius1-radius3*2)*sin(angle+0.02);
            angle+=mtg->blocks[i].angle;
            x3=x1+radius1*cos(angle-0.02);
            y3=y1+radius1*sin(angle-0.02);
            x5=x1+(radius1-radius3*2)*cos(angle-0.02);
            y5=y1+(radius1-radius3*2)*sin(angle-0.02);
            if(i==0 && step == 3)
            {
                dc->SetPen(wxPen(wxColor(255,0,0)));
            }
            else
            {
                dc->SetPen(pen2);
            }

            //dc.SetBrush(brush1);
            dc->DrawArc(x3,y3,x2,y2,x1,y1);
            dc->DrawArc(x5,y5,x4,y4,x1,y1);
            dc->DrawLine(x3+(x5-x3)/10,y3+(y5-y3)/10,x5-(x5-x3)/10,y5-(y5-y3)/10);
            dc->DrawLine(x2+(x4-x2)/10,y2+(y4-y2)/10,x4-(x4-x2)/10,y4-(y4-y2)/10);
            dc->SetPen(pen3);
            dc->DrawLine(x4,y4,x1,y1);
        }

        dc->SetPen(pen1);
        dc->SetBrush(wxBrush(wxColor(255,255,0)));
        //dc->SetTextForeground(wxColor(0,255,0));
        angle = mtg->segset.Ks;
        int n = 360/angle;
        angle = angle*PI/180.0;
        wxPoint pts[3];
        int i = 0;
        switch(step)
        {
        case 0:
            dc->DrawCircle(x1,y1-radius1+radius3,radius3+5);
            dc->DrawLabel(_("上"),wxRect(x1,y1-radius1+radius3,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            dc->DrawCircle(x1,y1+radius1-radius3,radius3+5);
            dc->DrawLabel(_("下"),wxRect(x1,y1+radius1-radius3,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            dc->DrawCircle(x1-radius1+radius3,y1,radius3+5);
            dc->DrawLabel(_("左"),wxRect(x1-radius1+radius3,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            dc->DrawCircle(x1+radius1-radius3,y1,radius3+5);
            dc->DrawLabel(_("右"),wxRect(x1+radius1-radius3,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            break;
        case 1:
            dc->DrawCircle(x1,y1-radius2+radius3,radius3+5);
            dc->DrawLabel(_("上"),wxRect(x1,y1-radius2+radius3,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            dc->DrawCircle(x1,y1+radius2-radius3,radius3+5);
            dc->DrawLabel(_("下"),wxRect(x1,y1+radius2-radius3,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            dc->DrawCircle(x1-radius2+radius3,y1,radius3+5);
            dc->DrawLabel(_("左"),wxRect(x1-radius2+radius3,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            dc->DrawCircle(x1+radius2-radius3,y1,radius3+5);
            dc->DrawLabel(_("右"),wxRect(x1+radius2-radius3,y1,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            break;

        case 2:
            pts[0].x=x1;
            pts[0].y=y1-radius2;
            pts[1].x=x1-(radius2-radius1)/2;
            pts[1].y=y1-radius1;
            pts[2].x=x1+(radius2-radius1)/2;
            pts[2].y=y1-radius1;
            dc->SetPen(wxPen(wxColor(20,125,255),2));
            dc->DrawLine(x1,y1-radius2-5,x1,y1-radius1+5);
            dc->DrawLine(x1+5,y1-radius2+5,x1-6,y1-radius2-6);
            dc->DrawLine(x1+5,y1-radius1+5,x1-6,y1-radius1-6);
            //dc->DrawPolygon(3,pts);
            dc->DrawLabel(_("上"),wxRect(x1+5,pts[0].y,0,radius2-radius1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            pts[0].x=x1;
            pts[0].y=y1+radius2;
            pts[1].x=x1-(radius2-radius1)/2;
            pts[1].y=y1+radius1;
            pts[2].x=x1+(radius2-radius1)/2;
            pts[2].y=y1+radius1;
            dc->DrawLine(x1,y1+radius2+5,x1,y1+radius1-5);
            dc->DrawLine(x1+5,y1+radius2+5,x1-6,y1+radius2-6);
            dc->DrawLine(x1+5,y1+radius1+5,x1-6,y1+radius1-6);
            //dc->DrawPolygon(3,pts);
            dc->DrawLabel(_("下"),wxRect(x1+5,pts[1].y,0,radius2-radius1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            pts[0].x=x1-radius2;
            pts[0].y=y1;
            pts[1].x=x1-radius1;
            pts[1].y=y1-(radius2-radius1)/2;
            pts[2].x=x1-radius1;
            pts[2].y=y1+(radius2-radius1)/2;
            dc->DrawLine(x1-radius2-5,y1,x1-radius1+5,y1);
            dc->DrawLine(x1-radius2+5,y1-6,x1-radius2-6,y1+5);
            dc->DrawLine(x1-radius1+5,y1-6,x1-radius1-6,y1+5);

            //dc->DrawPolygon(3,pts);
            dc->DrawLabel(_("左"),wxRect(x1-radius2,y1-5,radius2-radius1,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
            pts[0].x=x1+radius2;
            pts[0].y=y1;
            pts[1].x=x1+radius1;
            pts[1].y=y1-(radius2-radius1)/2;
            pts[2].x=x1+radius1;
            pts[2].y=y1+(radius2-radius1)/2;
            dc->DrawLine(x1+radius2+5,y1,x1+radius1-5,y1);
            dc->DrawLine(x1+radius2+5,y1-6,x1+radius2-6,y1+5);
            dc->DrawLine(x1+radius1+5,y1-6,x1+radius1-6,y1+5);
            //dc->DrawPolygon(3,pts);
            dc->DrawLabel(_("右"),wxRect(x1+radius1,y1-5,radius2-radius1,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM);
            break;
        case 3:
            dc->SetBrush(wxBrush(wxColor(68,68,68)));
            dc->SetFont(normalFont);
            for(i=0;i<n;i++)
            {
                x2=x1+(radius1-radius3)*cos(PI*3/2+angle+i*angle);
                y2=y1+(radius1-radius3)*sin(PI*3/2+angle+i*angle);
                dc->DrawCircle(x2,y2,3);
                x2=x1+(radius1+radius3)*cos(PI*3/2+angle+i*angle);
                y2=y1+(radius1+radius3)*sin(PI*3/2+angle+i*angle);
                dc->DrawLabel(wxString::Format(_("%d"),i+1),wxRect(x2,y2,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
            }
            break;
        default:
            break;
        }
    }
}
