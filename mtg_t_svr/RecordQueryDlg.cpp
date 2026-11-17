#include "wx_pch.h"
#include "RecordQueryDlg.h"
#include "mtg_t_svrApp.h"
#include "ConfirmDlg.h"
#include <wx/filedlg.h>

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(RecordQueryDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(RecordQueryDlg)
//*)

//(*IdInit(RecordQueryDlg)
const long RecordQueryDlg::ID_STATICTEXT1 = wxNewId();
const long RecordQueryDlg::ID_STATICTEXT2 = wxNewId();
const long RecordQueryDlg::ID_TEXTCTRL1 = wxNewId();
const long RecordQueryDlg::ID_TEXTCTRL2 = wxNewId();
const long RecordQueryDlg::ID_PANEL2 = wxNewId();
const long RecordQueryDlg::ID_PANEL3 = wxNewId();
const long RecordQueryDlg::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(RecordQueryDlg,wxDialog)
	//(*EventTable(RecordQueryDlg)
	//*)
END_EVENT_TABLE()

RecordQueryDlg::RecordQueryDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(RecordQueryDlg)
	Create(parent, wxID_ANY, _("拼装记录查询"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(570,350));
	PanelMain = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(570,350), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	PanelTop = new wxPanel(PanelMain, ID_PANEL2, wxPoint(0,0), wxSize(570,50), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	StaticText1 = new wxStaticText(PanelTop, ID_STATICTEXT1, _("环号："), wxPoint(16,16), wxSize(40,16), 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(PanelTop, ID_STATICTEXT2, _("~"), wxPoint(144,16), wxSize(16,16), 0, _T("ID_STATICTEXT2"));
//	TextCtrl1 = new wxTextCtrl(PanelTop, ID_TEXTCTRL1, wxEmptyString, wxPoint(64,14), wxSize(70,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
//	TextCtrl2 = new wxTextCtrl(PanelTop, ID_TEXTCTRL2, wxEmptyString, wxPoint(166,14), wxSize(70,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl1 = new wxMyTextCtrl(PanelTop, ID_TEXTCTRL1, wxEmptyString, wxPoint(64,14), wxSize(70,22), 0);
	TextCtrl2 = new wxMyTextCtrl(PanelTop, ID_TEXTCTRL2, wxEmptyString, wxPoint(166,14), wxSize(70,22), 0);
	PanelBody = new wxPanel(PanelMain, ID_PANEL3, wxPoint(0,50), wxSize(570,300), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	//*)
	StaticText1->Show(false);
	StaticText2->Show(false);
	PanelTop->SetBackgroundColour(wxColor(255,255,255));
	PanelBody->SetBackgroundColour(wxColor(255,255,255));
	PanelTop->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    PanelBody->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    QueryList = new wxListView(PanelBody, wxID_ANY, wxPoint(0,24), wxSize(570,300), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

	PanelBody->Connect(wxEVT_PAINT,(wxObjectEventFunction)&RecordQueryDlg::OnPaintQueryList,0,this);
	PanelTop->Connect(wxEVT_PAINT,(wxObjectEventFunction)&RecordQueryDlg::OnPaintTop,0,this);
    PanelTop->Connect(wxEVT_MOTION,(wxObjectEventFunction)&RecordQueryDlg::OnMotionTop,0,this);
    PanelTop->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&RecordQueryDlg::OnLeaveTop,0,this);
    PanelTop->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&RecordQueryDlg::OnClickTop,0,this);

    if(mtg->SegRecNum>1)
    {
        TextCtrl1->SetValue(wxString::Format(_("%d"),mtg->segrecord[mtg->SegRecNum-1].segnum-1));
        TextCtrl2->SetValue(wxString::Format(_("%d"),mtg->segrecord[mtg->SegRecNum-1].segnum));
    }
    else if(mtg->SegRecNum==1)
    {
        TextCtrl1->SetValue(wxString::Format(_("%d"),mtg->segrecord[mtg->SegRecNum-1].segnum));
        TextCtrl2->SetValue(wxString::Format(_("%d"),mtg->segrecord[mtg->SegRecNum-1].segnum));
    }
    else
    {
        TextCtrl1->SetValue(_("0"));
        TextCtrl2->SetValue(_("0"));
    }

    int i=0;
    QueryList->InsertColumn(i++,_("环号"),wxLIST_FORMAT_CENTRE,50);
    QueryList->InsertColumn(i++,_("管环类型"),wxLIST_FORMAT_CENTRE,90);
    QueryList->InsertColumn(i++,_("点位"),wxLIST_FORMAT_CENTRE,50);
    QueryList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,80);
    QueryList->InsertColumn(i++,_("水平偏差"),wxLIST_FORMAT_CENTRE,75);
    QueryList->InsertColumn(i++,_("垂直偏差"),wxLIST_FORMAT_CENTRE,75);
    QueryList->InsertColumn(i++,_("时间"),wxLIST_FORMAT_CENTRE,140);

    motion=ID_PT_NONE;
}

RecordQueryDlg::~RecordQueryDlg()
{
	//(*Destroy(RecordQueryDlg)
	//*)
}

void RecordQueryDlg::OnPaintTop(wxPaintEvent& event)
{
    wxPaintDC dc(PanelTop);
    int w,h;
    PanelTop->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;

        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        memDC.SetPen(wxPen(wxColor(117,117,117)));
        y1=10;
        w1=65;
        h1=26;
        x1=280;

        ptButton[ID_PT_QRY].x=x1;
        ptButton[ID_PT_QRY].y=y1;
        ptButton[ID_PT_QRY].width=w1;
        ptButton[ID_PT_QRY].height=h1;
        if(motion==ID_PT_QRY)
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
        memDC.DrawLabel(_("查询"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=85;
        ptButton[ID_PT_OUTPUT].x=x1;
        ptButton[ID_PT_OUTPUT].y=y1;
        ptButton[ID_PT_OUTPUT].width=w1;
        ptButton[ID_PT_OUTPUT].height=h1;
        if(motion==ID_PT_OUTPUT)
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
        memDC.DrawLabel(_("导出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(0,h-1,w,h-1);


        memDC.DrawLabel(_("环号："),wxRect(16,16,40,16),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("~"),wxRect(144,20,16,16),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void RecordQueryDlg::OnMotionTop(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>ptButton[ID_PT_QRY].y && y<ptButton[ID_PT_QRY].y+ptButton[ID_PT_QRY].height)
    {
        if(x>ptButton[ID_PT_QRY].x && x<ptButton[ID_PT_QRY].x+ptButton[ID_PT_QRY].width)
        {
            motion=ID_PT_QRY;
        }
        else if(x>ptButton[ID_PT_OUTPUT].x && x<ptButton[ID_PT_OUTPUT].x+ptButton[ID_PT_OUTPUT].width)
        {
            motion=ID_PT_OUTPUT;
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
    PanelTop->Refresh();
}

void RecordQueryDlg::OnLeaveTop(wxMouseEvent& event)
{
    motion=ID_PT_NONE;
    PanelTop->Refresh();
}

void RecordQueryDlg::OnClickTop(wxMouseEvent& event)
{
    if(motion==ID_PT_QRY)
    {
        wxString str1,str2;
        double seg1,seg2;
        int n1,n2;

        if(res)
            free(res);
        res=0;
        nres=0;

        str1=TextCtrl1->GetValue();
        str2=TextCtrl2->GetValue();
        if(!str1.IsEmpty() && !str2.IsEmpty())
        {
            str1.ToDouble(&seg1);
            str2.ToDouble(&seg2);
            n1=(int)seg1;
            n2=(int)seg2;
            nres=mtg_query_segrecords(mtg,&res,n1,n2);
            UpdateQueryList();
        }
        else
        {
            ConfirmDlg dlg(this);
            dlg.Center();
            dlg.confirmMsg=_("环号不能为空！");
            dlg.type=1;
            if(dlg.ShowModal()==wxID_OK)
            {
                TextCtrl1->SetFocus();
            }
        }
    }
    else if(motion==ID_PT_OUTPUT)
    {
        if(nres<=0) return;
        wxFileDialog fileDlg(this,_T("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strpath=fileDlg.GetPath();
            FILE *fp=fopen(strpath.mb_str(wxConvLocal),"w");
            if(fp)
            {
                wxString strtype;
                fprintf(fp,"环号,管环类型,点位,里程,水平偏差,垂直偏差,时间\n");
                fflush(fp);
                for(int i=0;i<nres;i++)
                {
                    if(res[i].segtype==0)
                        strtype=_("标准环");
                    else if(res[i].segtype==1)
                        strtype=_("左转弯");
                    else if(res[i].segtype==2)
                        strtype=_("右转弯");
                    else if(res[i].segtype==3)
                        strtype=_("通用环");
                    fprintf(fp,"%d,",res[i].segnum);fflush(fp);
                    fprintf(fp,"%s,",strtype.mb_str(wxConvLocal));fflush(fp);
                    fprintf(fp,"%d,",res[i].location);fflush(fp);
                    fprintf(fp,"%.4f,",res[i].mile);fflush(fp);
                    fprintf(fp,"%d,",(int)(res[i].offh*1000.0));fflush(fp);
                    fprintf(fp,"%d,",(int)(res[i].offv*1000.0));fflush(fp);
                    strtype=wxDateTime(res[i].t).Format(_("%Y-%m-%d %H:%M:%S"));
                    fprintf(fp,"%s\n",strtype.mb_str(wxConvLocal));fflush(fp);
                }
                fclose(fp);
                wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
            }
        }
    }
}

void RecordQueryDlg::OnPaintQueryList(wxPaintEvent& event)
{
    wxPaintDC dc(PanelBody);
    int w,h;
    PanelBody->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(130,135,145)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;

        int i=0;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("管环类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("水平偏差"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("垂直偏差"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        i=0;
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        x1=1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=QueryList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,w-1,y1+1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void RecordQueryDlg::UpdateQueryList()
{
    QueryList->DeleteAllItems();
    for(int i=0;i<nres;i++)
    {
        QueryList->InsertItem(i,wxString::Format(_("%d"),res[i].segnum));
        if(res[i].segtype==0)
            QueryList->SetItem(i,1,_("标准环"));
        else if(res[i].segtype==1)
            QueryList->SetItem(i,1,_("左转弯"));
        else if(res[i].segtype==2)
            QueryList->SetItem(i,1,_("右转弯"));
        else if(res[i].segtype==3)
            QueryList->SetItem(i,1,_("通用环"));
        QueryList->SetItem(i,2,wxString::Format(_("%d"),res[i].location));
        QueryList->SetItem(i,3,wxString::Format(_("%.4f"),res[i].mile));
        QueryList->SetItem(i,4,wxString::Format(_("%d"),(int)(res[i].offh*1000.0)));
        QueryList->SetItem(i,5,wxString::Format(_("%d"),(int)(res[i].offv*1000.0)));
        QueryList->SetItem(i,6,wxDateTime(res[i].t).Format(_("%Y-%m-%d %H:%M:%S")));
    }
}
