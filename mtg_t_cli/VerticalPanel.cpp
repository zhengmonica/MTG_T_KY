#include "wx_pch.h"
#include "VerticalPanel.h"
#include "V_StartPoint.h"
#include "V_Line.h"
#include "V_Round.h"
#include "mtg_t_cliApp.h"
#include "dmsrad.h"
#include "HorizonPanel.h"

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(VerticalPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#endif
//(*InternalHeaders(VerticalPanel)
#include <wx/settings.h>
//*)

//(*IdInit(VerticalPanel)
const long VerticalPanel::ID_BUTTON1 = wxNewId();
const long VerticalPanel::ID_BUTTON2 = wxNewId();
const long VerticalPanel::ID_BUTTON3 = wxNewId();
const long VerticalPanel::ID_LISTCTRL1 = wxNewId();
const long VerticalPanel::ID_BUTTON4 = wxNewId();
const long VerticalPanel::ID_BUTTON5 = wxNewId();
const long VerticalPanel::ID_BUTTON6 = wxNewId();
const long VerticalPanel::ID_BUTTON7 = wxNewId();
const long VerticalPanel::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(VerticalPanel,wxPanel)
    //(*EventTable(VerticalPanel)
    //*)
    EVT_COMMAND(-1,wxEVT_POLYLINE_SEL,VerticalPanel::OnPolylineSel)
END_EVENT_TABLE()

VerticalPanel::VerticalPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(VerticalPanel)
    Create(parent, wxID_ANY, wxDefaultPosition, wxSize(424,339), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    StartPoint = new wxButton(this, ID_BUTTON1, _("起始点"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Line = new wxButton(this, ID_BUTTON2, _("直线"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Round = new wxButton(this, ID_BUTTON3, _("圆曲线"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    ListVertical = new wxListView(this, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxRAISED_BORDER, wxDefaultValidator, _T("ID_LISTCTRL1"));
    Up = new wxButton(this, ID_BUTTON4, _("向上"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Down = new wxButton(this, ID_BUTTON5, _("向下"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Modify = new wxButton(this, ID_BUTTON6, _("修改"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Delete = new wxButton(this, ID_BUTTON7, _("删除"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    GraphVertical = new MyCanvas(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VerticalPanel::OnStartPointClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VerticalPanel::OnLineClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VerticalPanel::OnRoundClick);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&VerticalPanel::OnListVerticalItemSelect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&VerticalPanel::OnListVerticalItemDeselect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&VerticalPanel::OnListVerticalItemActivated);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VerticalPanel::OnUpClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VerticalPanel::OnDownClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VerticalPanel::OnModifyClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VerticalPanel::OnDeleteClick);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&VerticalPanel::OnResize);
    //*)

    ListVertical->InsertColumn(0,_("序号"));
    ListVertical->InsertColumn(1,_("类型"));
    ListVertical->InsertColumn(2,_("起点里程"));
    ListVertical->InsertColumn(3,_("起点高程"));
    ListVertical->InsertColumn(4,_("起点坡度(‰)"));
    ListVertical->InsertColumn(5,_("长度"));
    ListVertical->InsertColumn(6,_("半径"));
    ListVertical->InsertColumn(7,_("曲线形状"));
    ListVertical->SetColumnWidth(4,100);
    GraphVertical->SetGraphTitle(_("竖曲线"));

    UpdateList();
    UpdateGraph(true);
}

VerticalPanel::~VerticalPanel()
{
    //(*Destroy(VerticalPanel)
    //*)
}


void VerticalPanel::OnResize(wxSizeEvent& event)
{
    int w,h;
    GetClientSize(&w,&h);
    StartPoint->SetSize(10,10,-1,-1);
    Line->SetSize(10,50,-1,-1);
    Round->SetSize(10,90,-1,-1);
    ListVertical->SetSize(100,10,w-105,h/2-40);
    Up->SetSize(100,h/2-25,-1,-1);
    Down->SetSize(200,h/2-25,-1,-1);
    Modify->SetSize(300,h/2-25,-1,-1);
    Delete->SetSize(400,h/2-25,-1,-1);
    GraphVertical->SetSize(100,h/2+5,w-105,h/2-10);
    //GraphVertical->FitAll();
   // Refresh();
}

void VerticalPanel::OnStartPointClick(wxCommandEvent& event)
{
    if(mtg->onLine == 0)
    {
        V_StartPoint dlg(this);
        dlg.Center();
        road * r=&mtg->r;
        v_element v={0};
        int n = road_number_vertical(r);
        if(n>0)
        {
            dlg.L->SetValue(GetCellString(0,2));
            dlg.H->SetValue(GetCellString(0,3));
            dlg.i->SetValue(GetCellString(0,4));
        }
        if(dlg.ShowModal() == wxID_OK)
        {
            double i;
            v.type = ROAD_TYPE_START_POINT;
            dlg.L->GetValue().ToDouble(&v.l1);
            dlg.H->GetValue().ToDouble(&v.h1);
            dlg.i->GetValue().ToDouble(&i);
            v.angle1 = atan(i/1000.0);
            if(n<=0)
            {
                road_insert_vertical(r,&v,0);
                road_apply_vertical(r);

    //            ListVertical->InsertItem(0,wxT("1"));
    //            ListVertical->SetItem(0,1,wxT("起点"));

                Line->Enable(true);
                Round->Enable(true);
            }
            else
            {
                road_modify_vertical(r,&v,0);
                road_apply_vertical(r);
            }
    //        ListVertical->SetItem(0,2,dlg.L->GetValue());
    //        ListVertical->SetItem(0,3,dlg.H->GetValue());
    //        ListVertical->SetItem(0,4,dlg.i->GetValue());
    //        ListVertical->Select(0);
            UpdateList();
            ListVertical->Select(0);
            UpdateGraph(true);
        }
        //if(mtg->iclient==2) client_edit_vertical(mtg,&v,0);
    }
}

void VerticalPanel::OnLineClick(wxCommandEvent& event)
{
    if(mtg->onLine == 0)
    {
        road * r=&mtg->r;
        int n = road_number_vertical(r)-1;
        double ori1,ori2;
        v_element* pv=road_vertical(r,n);
        ori1=pv->angle2;

        V_Line dlg(this);
        //dlg.Ori->SetValue(wxString::Format(_("%.4f"),tan(ori1)*1000.0));
        dlg.Center();

        v_element v={0};
        if(dlg.ShowModal() == wxID_OK)
        {
            v.type = ROAD_TYPE_LINE;
            dlg.L->GetValue().ToDouble(&v.length);
            //dlg.Ori->GetValue().ToDouble(&ori2);
            ori2=atan(ori2/1000.0);
            v.deta=ori2-ori1;
            road_insert_vertical(r,&v,n);
            road_apply_vertical(r);
            //if(mtg->iclient==2) client_edit_vertical(mtg,&v,n);

    //        ListVertical->InsertItem(n,wxString::Format(wxT("%d"),n+1));
    //        ListVertical->SetItem(n,1,wxT("直线"));
    //        ListVertical->SetItem(n,5,dlg.L->GetValue());
            UpdateList();
            ListVertical->Select(n);
            UpdateGraph(true);
        }
    }
}

void VerticalPanel::OnRoundClick(wxCommandEvent& event)
{
    if(mtg->onLine == 0)
    {
        V_Round dlg(this);
        dlg.Center();
        road * r=&mtg->r;
        v_element v={0};
        if(dlg.ShowModal() == wxID_OK)
        {
            v.type = ROAD_TYPE_ARC;
            dlg.R->GetValue().ToDouble(&v.radius);
            dlg.L->GetValue().ToDouble(&v.length);
            //if(dlg.Turn->GetSelection() == 0)
                v.pz = ROAD_UP;
            //else
                v.pz = ROAD_DOWN;
            int n = road_number_vertical(r)-1;
            road_insert_vertical(r,&v,n);
            road_apply_vertical(r);
            //if(mtg->iclient==2) client_edit_vertical(mtg,&v,n);

    //        ListVertical->InsertItem(n,wxString::Format(wxT("%d"),n+1));
    //        ListVertical->SetItem(n,1,wxT("圆曲线"));
    //        ListVertical->SetItem(n,5,dlg.L->GetValue());
    //        ListVertical->SetItem(n,6,dlg.R->GetValue());
    //        ListVertical->SetItem(n,7,dlg.Turn->GetStringSelection());
            UpdateList();
            ListVertical->Select(n);
            UpdateGraph(true);
        }
    }
}

void VerticalPanel::OnUpClick(wxCommandEvent& event)
{
    if(mtg->onLine == 0)
    {
        int n = ListVertical->GetFirstSelected();
        int Num = ListVertical->GetItemCount();
        if(n > 1 && n< Num-1)
        {
            road * r=&mtg->r;
            v_element v={0};
    //        wxString str;
    //        for(int i=1; i<10; i++)
    //        {
    //            str = GetCellString(n,i);
    //            ListVertical->SetItem(n,i,GetCellString(n-1,i));
    //            ListVertical->SetItem(n-1,i,str);
    //        }
    //        ListVertical->Select(n,false);
    //        ListVertical->Select(n-1);
            v.length = road_vertical(r,n-1)->length;
            v.pz = road_vertical(r,n-1)->pz;
            v.radius = road_vertical(r,n-1)->radius;
            v.type = road_vertical(r,n-1)->type;
            road_modify_vertical(r,road_vertical(r,n),n-1);
            //if(mtg->iclient==2) client_edit_vertical(mtg,road_vertical(r,n),n-1);

            road_modify_vertical(r,&v,n);
            //if(mtg->iclient==2) client_edit_vertical(mtg,&v,n);

            road_apply_vertical(r);
            UpdateList();
            ListVertical->Select(n,false);
            ListVertical->Select(n-1);
            UpdateGraph();
        }
    }
}

void VerticalPanel::OnDownClick(wxCommandEvent& event)
{
    if(mtg->onLine == 0)
    {
        int n = ListVertical->GetFirstSelected();
        int Num = ListVertical->GetItemCount();
        if(n > 0 && n< Num-2)
        {
            road * r=&mtg->r;
            v_element v={0};
    //        wxString str;
    //        for(int i=1; i<10; i++)
    //        {
    //            str = GetCellString(n,i);
    //            ListVertical->SetItem(n,i,GetCellString(n+1,i));
    //            ListVertical->SetItem(n+1,i,str);
    //        }
    //        ListVertical->Select(n,false);
    //        ListVertical->Select(n+1);
            v.length = road_vertical(r,n+1)->length;
            v.pz = road_vertical(r,n+1)->pz;
            v.radius = road_vertical(r,n+1)->radius;
            v.type = road_vertical(r,n+1)->type;
            road_modify_vertical(r,road_vertical(r,n),n+1);
            //if(mtg->iclient==2) client_edit_vertical(mtg,road_vertical(r,n),n+1);

            road_modify_vertical(r,&v,n);
            //if(mtg->iclient==2) client_edit_vertical(mtg,&v,n);

            road_apply_vertical(r);
            UpdateList();
            ListVertical->Select(n,false);
            ListVertical->Select(n+1);
            UpdateGraph();
        }
    }
}

const wxString VerticalPanel::GetCellString( int row, int col )
{
    wxListItem row_info;
    wxString str;
    row_info.m_itemId = row;
    row_info.m_col = col;
    row_info.m_mask = wxLIST_MASK_TEXT;
    ListVertical->GetItem(row_info);
    str = row_info.m_text;
    return str;
}

void VerticalPanel::OnModifyClick(wxCommandEvent& event)
{
    if(mtg->onLine == 0)
    {
        int n = ListVertical->GetFirstSelected();
        if(n<0) return;

        V_StartPoint dlg_P(this);
        V_Line dlg_L(this);
        V_Round dlg_R(this);
        dlg_P.Center();
        dlg_L.Center();
        dlg_R.Center();

        road * r=&mtg->r;
        v_element v={0};
        wxString type = GetCellString(n,1);
        if(type == wxT("起点"))
        {
            dlg_P.L->SetValue(GetCellString(n,2));
            dlg_P.H->SetValue(GetCellString(n,3));
            dlg_P.i->SetValue(GetCellString(n,4));
            if(dlg_P.ShowModal() == wxID_OK)
            {
    //            ListVertical->SetItem(n,2,dlg_P.L->GetValue());
    //            ListVertical->SetItem(n,3,dlg_P.H->GetValue());
    //            ListVertical->SetItem(n,4,dlg_P.i->GetValue());
    //            ListVertical->Select(n);

                double i;
                v.type = ROAD_TYPE_START_POINT;
                dlg_P.L->GetValue().ToDouble(&v.l1);
                dlg_P.H->GetValue().ToDouble(&v.h1);
                dlg_P.i->GetValue().ToDouble(&i);
                v.angle1 = atan(i/1000.0);
                road_modify_vertical(r,&v,n);
                //if(mtg->iclient==2) client_edit_vertical(mtg,&v,n);

                road_apply_vertical(r);
    //            UpdateGraph(true);
            }
        }
        else if(type == wxT("直线"))
        {
            dlg_L.L->SetValue(GetCellString(n,5));
            //dlg_L.Ori->SetValue(GetCellString(n,4));
            double ori1=0.0;
            GetCellString(n,4).ToDouble(&ori1);
            if(dlg_L.ShowModal() == wxID_OK)
            {
    //            ListVertical->SetItem(n,5,dlg_L.L->GetValue());
    //            ListVertical->Select(n);
                v.type = ROAD_TYPE_LINE;
                double ori2=0.0;
                //dlg_L.Ori->GetValue().ToDouble(&ori2);
                v.deta=road_vertical(r,n)->deta+atan(ori2/1000.0)-atan(ori1/1000.0);
                //v.deta = Angle_to_Radian()-ori1;
                dlg_L.L->GetValue().ToDouble(&v.length);
                road_modify_vertical(r,&v,n);
                road_apply_vertical(r);
    //            UpdateGraph(true);
            }
        }
        else if(type == wxT("圆曲线"))
        {
            dlg_R.L->SetValue(GetCellString(n,5));
            dlg_R.R->SetValue(GetCellString(n,6));
            //if(GetCellString(n,7) == wxT("上凸"))
                //dlg_R.Turn->SetSelection(0);
            //else
                //dlg_R.Turn->SetSelection(1);
            if(dlg_R.ShowModal() == wxID_OK)
            {
    //            ListVertical->SetItem(n,5,dlg_R.L->GetValue());
    //            ListVertical->SetItem(n,6,dlg_R.R->GetValue());
    //            ListVertical->SetItem(n,7,dlg_R.Turn->GetStringSelection());
    //            ListVertical->Select(n);

                v.type = ROAD_TYPE_ARC;
                dlg_R.L->GetValue().ToDouble(&v.length);
                dlg_R.R->GetValue().ToDouble(&v.radius);
                //if(dlg_R.Turn->GetSelection() == 0)
                    v.pz = ROAD_UP;
                //else
                    v.pz = ROAD_DOWN;
                road_modify_vertical(r,&v,n);
                road_apply_vertical(r);
    //            UpdateGraph(true);
            }
        }
        else if(type == wxT("终点"))
        {
            dlg_P.L->SetValue(GetCellString(n,2));
            dlg_P.H->SetValue(GetCellString(n,3));
            dlg_P.i->SetValue(GetCellString(n,4));
            dlg_P.L->Enable(false);
            dlg_P.H->Enable(false);
            dlg_P.i->Enable(false);
            //dlg_P.StaticText1->SetLabel(wxT("终点"));
            //dlg_P.ShowModal();
        }
        UpdateList();
        ListVertical->Select(n);
        UpdateGraph(true);
    }
}

void VerticalPanel::OnDeleteClick(wxCommandEvent& event)
{
    if(mtg->onLine == 0)
    {
        int n = ListVertical->GetFirstSelected();
        int Num = ListVertical->GetItemCount();
        if(n<=0 || n>=Num-1) return;
        wxMessageDialog dlg(this,_("删除操作将不可恢复\n确定要进行删除吗？"),_("竖曲线要素"),wxYES_NO|wxICON_INFORMATION);
        if(dlg.ShowModal() == wxID_YES)
        {
            road * r=&mtg->r;
            long del=n;

            if(del==0)
            {
                if(Num==1)
                {
    //               ListVertical->DeleteItem(del);
                    road_remove_vertical(r,n);
                    road_apply_vertical(r);
                }
                else
                    return;
            }
            else
            {
    //            ListVertical->DeleteItem(del);
    //            for(int i = n; i<Num; i++)
    //                ListVertical->SetItem(i,0,wxString::Format(wxT("%d"),i+1));
                road_remove_vertical(r,n);
                road_apply_vertical(r);
                if(n == Num-1)
                    ListVertical->Select(n-1);
                else
                    ListVertical->Select(n);
            }
            UpdateList();
            if(n == Num-1)
                ListVertical->Select(n-1);
            else
                ListVertical->Select(n);
            UpdateGraph();
        }
    }
}

void VerticalPanel::UpdateGraph(bool fit)
{
    road* r=&mtg->r;
    int n=road_number_vertical(r);
    GraphVertical->Clear();
    int i;

    int npt=0;
    double *xy=0;

    for(i=0; i<n; i++)
    {
        v_element* e=road_vertical(r,i);
        if(e->type==ROAD_TYPE_LINE)
        {
            npt=2;
            xy=new double[4];
            xy[0]=e->l1;
            xy[1]=e->h1;
            xy[2]=e->l2;
            xy[3]=e->h2;
            GraphVertical->AddPolyLine(npt,xy);
            delete xy;
        }
        else if(e->type==ROAD_TYPE_ARC)
        {
            npt=21;
            xy=new double[2*npt];
            int index=0;
            xy[2*index]=e->l1;
            xy[2*index+1]=e->h1;
            index++;
            double l=e->l1+e->length/20.0;
            while(e->length >0.001  && l<e->l2)
            {
                xy[2*index]=l;
                road_l2h(r,l,&xy[2*index+1],0);
                index++;
                if(index>=npt-1) break;
                l+=(e->length/20.0);
            }
            xy[2*index]=e->l2;
            xy[2*index+1]=e->h2;

            GraphVertical->AddPolyLine(npt,xy);
            delete xy;
        }


        GraphVertical->AddSymbol(e->l2,e->h2,0);
        wxString str;
        if(i==0)
        {
            str=_("QD");
        }
        else if(i==n-1)
        {
            str=_("ZD");
        }
        else if(i<n-2)
        {
            v_element* e1=road_vertical(r,i+1);
            if(e->type==ROAD_TYPE_LINE)
            {
                str+=_("Z");
            }
            else if(e->type==ROAD_TYPE_ARC)
            {
                str+=_("Y");
            }

            if(e1->type==ROAD_TYPE_LINE)
            {
                str+=_("Z");
            }
            else if(e1->type==ROAD_TYPE_ARC)
            {
                str+=_("Y");
            }
        }
        GraphVertical->AddText(str,e->l2,e->h2);
    }
    int sel=ListVertical->GetFirstSelected();
    GraphVertical->SelectPolyline(sel-1);
    if(fit)
    {
        GraphVertical->FitAll();
    }
    else
    {
        GraphVertical->ResetMapPoints();
    }
}


void VerticalPanel::UpdateList()
{
    ListVertical->DeleteAllItems();
    road* r=&mtg->r;
    int n=road_number_vertical(r);
    for(int i=0; i<n; i++)
    {
        ListVertical->InsertItem(i,wxString::Format(_("%d"),i+1));
        v_element* v=road_vertical(r,i);
        ListVertical->SetItem(i,2,wxString::Format(_("%.4f"),v->l1));
        ListVertical->SetItem(i,3,wxString::Format(_("%.4f"),v->h1));
        ListVertical->SetItem(i,4,wxString::Format(_("%.4f"),tan(v->angle1+v->deta)*1000.0));

        if(v->type==ROAD_TYPE_START_POINT)
        {
            ListVertical->SetItem(i,1,wxT("起点"));
//            ListVertical->SetItem(i,2,wxString::Format(_("%.4f"),v->l1));
//            ListVertical->SetItem(i,3,wxString::Format(_("%.4f"),v->h1));
//            ListVertical->SetItem(i,4,wxString::Format(_("%.4f"),tan(v->angle1)*100.0));
        }
        else if(v->type==ROAD_TYPE_LINE)
        {
            ListVertical->SetItem(i,1,wxT("直线"));
            ListVertical->SetItem(i,5,wxString::Format(_("%.4f"),v->length));
        }
        else if(v->type==ROAD_TYPE_ARC)
        {
            ListVertical->SetItem(i,1,wxT("圆曲线"));
            ListVertical->SetItem(i,5,wxString::Format(_("%.4f"),v->length));
            ListVertical->SetItem(i,6,wxString::Format(_("%.4f"),v->radius));
            //ListVertical->SetItem(n,7,dlg.Turn->GetStringSelection());
            if(v->pz==ROAD_LEFT)
            {
                ListVertical->SetItem(i,7,_("上凸"));
            }
            else
            {
                ListVertical->SetItem(i,7,_("下凹"));
            }

        }
        else if(v->type==ROAD_TYPE_END_POINT)
        {
            ListVertical->SetItem(i,1,wxT("终点"));
        }

    }
}

void VerticalPanel::OnListVerticalItemActivated(wxListEvent& event)
{
    wxCommandEvent e;
    OnModifyClick(e);
}

void VerticalPanel::OnListVerticalItemSelect(wxListEvent& event)
{
    wxArrayInt sels=GraphVertical->GetSelectedPolyLine();
    for(int i=0; i<sels.Count(); i++)
    {
        GraphVertical->SelectPolyline(sels[i],false);
    }
    if(event.GetIndex()>=1)
    {
        GraphVertical->SelectPolyline(event.GetIndex()-1);
        GraphVertical->Refresh(false);
    }

}

void VerticalPanel::OnListVerticalItemDeselect(wxListEvent& event)
{
    wxArrayInt sels=GraphVertical->GetSelectedPolyLine();
    for(int i=0; i<sels.Count(); i++)
    {
        GraphVertical->SelectPolyline(sels[i],false);
    }
    GraphVertical->Refresh(false);
}

void VerticalPanel::OnPolylineSel(wxCommandEvent& event)
{
    wxArrayInt sels=GraphVertical->GetSelectedPolyLine();
    for(int i=0; i<ListVertical->GetItemCount(); i++) ListVertical->Select(i,false);
    for(int i=0; i<sels.Count(); i++)
    {
        GraphVertical->SelectPolyline(sels[i],false);
    }
    int sel=event.GetId();
    ListVertical->Select(sel+1,true);
    GraphVertical->SelectPolyline(sel,true);
    GraphVertical->Refresh(false);
}

