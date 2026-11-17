#include "wx_pch.h"
#include "HorizonPanel.h"
#include "H_StartPoint.h"
#include "H_Line.h"
#include "H_Round.h"
#include "H_Moderate.h"
#include "mtg_tApp.h"
#include "dmsrad.h"

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(HorizonPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#endif
//(*InternalHeaders(HorizonPanel)
#include <wx/settings.h>
//*)

//(*IdInit(HorizonPanel)
const long HorizonPanel::ID_BUTTON1 = wxNewId();
const long HorizonPanel::ID_BUTTON2 = wxNewId();
const long HorizonPanel::ID_BUTTON3 = wxNewId();
const long HorizonPanel::ID_BUTTON4 = wxNewId();
const long HorizonPanel::ID_LISTCTRL1 = wxNewId();
const long HorizonPanel::ID_BUTTON5 = wxNewId();
const long HorizonPanel::ID_BUTTON6 = wxNewId();
const long HorizonPanel::ID_BUTTON7 = wxNewId();
const long HorizonPanel::ID_BUTTON8 = wxNewId();
const long HorizonPanel::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(HorizonPanel,wxPanel)
    //(*EventTable(HorizonPanel)
    //*)
    EVT_COMMAND(-1,wxEVT_POLYLINE_SEL,HorizonPanel::OnPolylineSel)
END_EVENT_TABLE()

HorizonPanel::HorizonPanel(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(HorizonPanel)
    Create(parent, wxID_ANY, wxDefaultPosition, wxSize(560,500), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    StartPoint = new wxButton(this, ID_BUTTON1, _("起始点"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Line = new wxButton(this, ID_BUTTON2, _("直线"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Round = new wxButton(this, ID_BUTTON3, _("圆曲线"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Moderate = new wxButton(this, ID_BUTTON4, _("缓和曲线"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    ListHorizon = new wxListView(this, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxRAISED_BORDER, wxDefaultValidator, _T("ID_LISTCTRL1"));
    Up = new wxButton(this, ID_BUTTON5, _("向上"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Down = new wxButton(this, ID_BUTTON6, _("向下"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Modify = new wxButton(this, ID_BUTTON7, _("修改"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    Delete = new wxButton(this, ID_BUTTON8, _("删除"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    GraphHorizon = new MyCanvas(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HorizonPanel::OnStartPointClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HorizonPanel::OnLineClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HorizonPanel::OnRoundClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HorizonPanel::OnModerateClick);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&HorizonPanel::OnListHorizonItemSelect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&HorizonPanel::OnListHorizonItemDeselect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&HorizonPanel::OnListHorizonItemActivated);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HorizonPanel::OnUpClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HorizonPanel::OnDownClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HorizonPanel::OnModifyClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HorizonPanel::OnDeleteClick);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&HorizonPanel::OnResize);
    //*)
    ListHorizon->InsertColumn(0,_("序号"));
    ListHorizon->InsertColumn(1,_("类型"));
    ListHorizon->InsertColumn(2,_("起点里程"));
    ListHorizon->InsertColumn(3,_("线段长度"));
    ListHorizon->InsertColumn(4,_("起点坐标(X)"));
    ListHorizon->InsertColumn(5,_("起点坐标(Y)"));
    ListHorizon->InsertColumn(6,_("起始半径"));
    ListHorizon->InsertColumn(7,_("终止半径"));
    ListHorizon->InsertColumn(8,_("起始方位角"));
    ListHorizon->InsertColumn(9,_("偏转方向"));
    ListHorizon->SetColumnWidth(4,100);
    ListHorizon->SetColumnWidth(5,100);
    ListHorizon->SetColumnWidth(8,120);

    GraphHorizon->SetGraphTitle(_("平曲线"));

    UpdateList();
    UpdateGraph(true);
}

HorizonPanel::~HorizonPanel()
{
    //(*Destroy(HorizonPanel)
    //*)
}

void HorizonPanel::UpdateList()
{
    ListHorizon->DeleteAllItems();
    road* r=&cli->r;
    int n=road_number_horizon(r);
    for(int i=0; i<n; i++)
    {
        ListHorizon->InsertItem(i,wxString::Format(_("%d"),i+1));
        h_element* h=road_horizon(r,i);

        ListHorizon->SetItem(i,2,wxString::Format(_("%.4f"),h->l1));
        ListHorizon->SetItem(i,4,wxString::Format(_("%.4f"),h->x1));
        ListHorizon->SetItem(i,5,wxString::Format(_("%.4f"),h->y1));
        ListHorizon->SetItem(i,8,Radian_to_Angle(h->angle1));
        if(h->type==ROAD_TYPE_START_POINT)
        {
            ListHorizon->SetItem(i,1,wxT("起点"));
            ListHorizon->SetItem(i,2,wxString::Format(_("%.4f"),h->l1));
            ListHorizon->SetItem(i,4,wxString::Format(_("%.4f"),h->x1));
            ListHorizon->SetItem(i,5,wxString::Format(_("%.4f"),h->y1));
            ListHorizon->SetItem(i,8,Radian_to_Angle(h->angle1));
        }
        else if(h->type==ROAD_TYPE_LINE)
        {
            ListHorizon->SetItem(i,1,wxT("直线"));
            ListHorizon->SetItem(i,3,wxString::Format(_("%.4f"),h->length));
            ListHorizon->SetItem(i,8,Radian_to_Angle(h->angle1+h->deta));
        }
        else if(h->type==ROAD_TYPE_ARC)
        {
            ListHorizon->SetItem(i,1,wxT("圆曲线"));
            ListHorizon->SetItem(i,3,wxString::Format(_("%.4f"),h->length));
            ListHorizon->SetItem(i,6,wxString::Format(_("%.4f"),h->radius));
            ListHorizon->SetItem(i,7,wxString::Format(_("%.4f"),h->radius));
            if(h->pz==ROAD_LEFT)
            {
                ListHorizon->SetItem(i,9,_("左"));
            }
            else
            {
                ListHorizon->SetItem(i,9,_("右"));
            }

        }
        else if(h->type==ROAD_TYPE_SPIRAL)
        {
            ListHorizon->SetItem(i,1,wxT("缓和曲线"));
            ListHorizon->SetItem(i,3,wxString::Format(_("%.4f"),h->length));
            ListHorizon->SetItem(i,6,wxString::Format(_("%.4f"),h->rou1));
            ListHorizon->SetItem(i,7,wxString::Format(_("%.4f"),h->rou2));
            if(h->pz==ROAD_LEFT)
            {
                ListHorizon->SetItem(i,9,_("左"));
            }
            else
            {
                ListHorizon->SetItem(i,9,_("右"));
            }
        }
        else if(h->type==ROAD_TYPE_END_POINT)
        {
            ListHorizon->SetItem(i,1,wxT("终点"));
            ListHorizon->SetItem(i,2,wxString::Format(_("%.4f"),h->l1));
            ListHorizon->SetItem(i,4,wxString::Format(_("%.4f"),h->x1));
            ListHorizon->SetItem(i,5,wxString::Format(_("%.4f"),h->y1));
            ListHorizon->SetItem(i,8,Radian_to_Angle(h->angle1));
        }

    }
}

void HorizonPanel::OnResize(wxSizeEvent& event)
{
    int w,h;
    GetClientSize(&w,&h);
    StartPoint->SetSize(10,10,-1,-1);
    Line->SetSize(10,50,-1,-1);
    Round->SetSize(10,90,-1,-1);
    Moderate->SetSize(10,130,-1,-1);
    ListHorizon->SetSize(100,10,w-105,h/2-40);
    Up->SetSize(100,h/2-25,-1,-1);
    Down->SetSize(200,h/2-25,-1,-1);
    Modify->SetSize(300,h/2-25,-1,-1);
    Delete->SetSize(400,h/2-25,-1,-1);
    GraphHorizon->SetSize(100,h/2+5,w-105,h/2-10);
    //GraphHorizon->FitAll();
    //Refresh();
}

void HorizonPanel::OnStartPointClick(wxCommandEvent& event)
{
    if(cli->onLine == 0)
    {
        H_StartPoint dlg(this);
        dlg.Center();
        road * r=&cli->r;
        h_element h={0};
        int n=road_number_horizon(r);
        if(n>0)
        {
            //dlg.L->SetValue(GetCellString(0,2));
            //dlg.X->SetValue(GetCellString(0,4));
            //dlg.Y->SetValue(GetCellString(0,5));
            //dlg.W->SetValue(AngleConver(GetCellString(0,8)));
        }
        if(dlg.ShowModal() == wxID_OK)
        {
            //h.type = ROAD_TYPE_START_POINT;
            //h.angle1 = Angle_to_Radian(dlg.W->GetValue());
            //dlg.L->GetValue().ToDouble(&h.l1);
            //dlg.X->GetValue().ToDouble(&h.x1);
            //dlg.Y->GetValue().ToDouble(&h.y1);
            if(n<=0)
            {
                road_insert_horizon(r,&h,0);
                road_apply_horizon(r);
    //            ListHorizon->InsertItem(0,_("1"));
    //            ListHorizon->SetItem(0,1,wxT("起点"));
                Line->Enable();
                Round->Enable();
                Moderate->Enable();
            }
            else
            {
                road_modify_horizon(r,&h,0);
                road_apply_horizon(r);
            }
            //if(cli->iclient==2) client_edit_horizon(cli,&h,0);
    //        ListHorizon->SetItem(0,2,dlg.L->GetValue());
    //        ListHorizon->SetItem(0,4,dlg.X->GetValue());
    //        ListHorizon->SetItem(0,5,dlg.Y->GetValue());
    //        ListHorizon->SetItem(0,8,dlg.W->GetValue());
            UpdateList();
            ListHorizon->Select(0);
            UpdateGraph(true);
        }
    }
}

void HorizonPanel::OnLineClick(wxCommandEvent& event)
{
    if(cli->onLine == 0)
    {
        road * r=&cli->r;
        int n=road_number_horizon(r)-1;
        h_element *ph=road_horizon(r,n);
        double ori1,ori2;
        H_Line dlg(this);
        ori1=ph->angle2;
        //dlg.Ori->SetValue(Radian_to_point_Angle(ori1));
        //dlg.Center();
        h_element h={0};
        if(dlg.ShowModal() == wxID_OK)
        {
            h.type = ROAD_TYPE_LINE;
            //dlg.L->GetValue().ToDouble(&h.length);
            //ori2=Angle_to_Radian(dlg.Ori->GetValue());
            h.deta=ori2-ori1;
            road_insert_horizon(r,&h,n);
            road_apply_horizon(r);

            //if(cli->iclient==2) client_edit_horizon(cli,&h,n);

            UpdateList();
            ListHorizon->Select(n);
            UpdateGraph(true);
        }
    }
}

void HorizonPanel::OnRoundClick(wxCommandEvent& event)
{
    if(cli->onLine == 0)
    {
        H_Round dlg(this);
        dlg.Center();
        road * r=&cli->r;
        h_element h={0};
        if(dlg.ShowModal() == wxID_OK)
        {
            h.type = ROAD_TYPE_ARC;
            //dlg.R->GetValue().ToDouble(&h.radius);
            //dlg.L->GetValue().ToDouble(&h.length);
            //if(dlg.Turn->GetSelection() == 0)
              //  h.pz = ROAD_LEFT;
            //else
                //h.pz = ROAD_RIGHT;
            int n=road_number_horizon(r)-1;
            h.rou1=h.rou2=1/h.radius;
            road_insert_horizon(r,&h,n);
            road_apply_horizon(r);
            //if(cli->iclient==2) client_edit_horizon(cli,&h,n);


    //        ListHorizon->InsertItem(n,wxString::Format(wxT("%d"),n+1));
    //        ListHorizon->SetItem(n,1,wxT("圆曲线"));
    //        ListHorizon->SetItem(n,3,dlg.L->GetValue());
    //        ListHorizon->SetItem(n,6,dlg.R->GetValue());
    //        ListHorizon->SetItem(n,7,dlg.R->GetValue());
    //        ListHorizon->SetItem(n,9,dlg.Turn->GetStringSelection());
            UpdateList();
            ListHorizon->Select(n);
            UpdateGraph(true);
        }
    }
}

void HorizonPanel::OnModerateClick(wxCommandEvent& event)
{
    if(cli->onLine == 0)
    {
        H_Moderate dlg(this);
        dlg.Center();
        road * r=&cli->r;
        h_element h={0};
        if(dlg.ShowModal() == wxID_OK)
        {
            h.type = ROAD_TYPE_SPIRAL;
            dlg.R1->GetValue().ToDouble(&h.rou1);
            dlg.R2->GetValue().ToDouble(&h.rou2);
            dlg.L->GetValue().ToDouble(&h.length);
            //if(dlg.Turn->GetSelection() == 0)
                //h.pz = ROAD_LEFT;
            //else
               // h.pz = ROAD_RIGHT;
            int n = road_number_horizon(r)-1;
            road_insert_horizon(r,&h,n);
            road_apply_horizon(r);
            //if(cli->iclient==2) client_edit_horizon(cli,&h,n);

    //        ListHorizon->InsertItem(n,wxString::Format(wxT("%d"),n+1));
    //        ListHorizon->SetItem(n,1,wxT("缓和曲线"));
    //        ListHorizon->SetItem(n,3,dlg.L->GetValue());
    //        ListHorizon->SetItem(n,6,dlg.R1->GetValue());
    //        ListHorizon->SetItem(n,7,dlg.R2->GetValue());
    //        ListHorizon->SetItem(n,9,dlg.Turn->GetStringSelection());
    //        ListHorizon->Select(n);
            UpdateList();
            ListHorizon->Select(n);
            UpdateGraph(true);
        }
    }
}

void HorizonPanel::OnUpClick(wxCommandEvent& event)
{
    if(cli->onLine == 0)
    {
        int n = ListHorizon->GetFirstSelected();
        int Num = ListHorizon->GetItemCount();
        if(n > 1 && n<Num-1)
        {
            road * r=&cli->r;
            h_element h={0};
    //        wxString str;
    //        for(int i=1; i<10; i++)
    //        {
    //            str = GetCellString(n,i);
    //            ListHorizon->SetItem(n,i,GetCellString(n-1,i));
    //            ListHorizon->SetItem(n-1,i,str);
    //        }
    //        ListHorizon->Select(n,false);
    //        ListHorizon->Select(n-1);
            h.length = road_horizon(r,n-1)->length;
            h.pz = road_horizon(r,n-1)->pz;
            h.radius = road_horizon(r,n-1)->radius;
            h.rou1 = road_horizon(r,n-1)->rou1;
            h.rou2 = road_horizon(r,n-1)->rou2;
            h.type = road_horizon(r,n-1)->type;
            road_modify_horizon(r,road_horizon(r,n),n-1);
            road_modify_horizon(r,&h,n);
            road_apply_horizon(r);
            UpdateList();
            ListHorizon->Select(n,false);
            ListHorizon->Select(n-1);
            UpdateGraph();
        }
    }
}

void HorizonPanel::OnDownClick(wxCommandEvent& event)
{
    if(cli->onLine == 0)
    {
        int n = ListHorizon->GetFirstSelected();
        int Num = ListHorizon->GetItemCount();
        if(n > 0&& n<Num-2)
        {
            road * r=&cli->r;
            h_element h={0};
            h.length = road_horizon(r,n+1)->length;
            h.pz = road_horizon(r,n+1)->pz;
            h.radius = road_horizon(r,n+1)->radius;
            h.rou1 = road_horizon(r,n+1)->rou1;
            h.rou2 = road_horizon(r,n+1)->rou2;
            h.type = road_horizon(r,n+1)->type;
            road_modify_horizon(r,road_horizon(r,n),n+1);
            //if(cli->iclient==2) client_edit_horizon(cli,road_horizon(r,n),n+1);

            road_modify_horizon(r,&h,n);
            //if(cli->iclient==2) client_edit_horizon(cli,&h,n);

            road_apply_horizon(r);
            UpdateList();
            ListHorizon->Select(n,false);
            ListHorizon->Select(n+1);
            UpdateGraph();
        }
    }
}
void HorizonPanel::OnModifyClick(wxCommandEvent& event)
{
    if(cli->onLine == 0)
    {
        int n = ListHorizon->GetFirstSelected();
        int Num = ListHorizon->GetItemCount();

        if(n<0 || n>=Num-1) return;

        H_StartPoint dlg_P(this);
        H_Line dlg_L(this);
        H_Round dlg_R(this);
        H_Moderate dlg_M(this);
        dlg_P.Center();
        dlg_L.Center();
        dlg_R.Center();
        dlg_M.Center();


        road * r=&cli->r;
        h_element h={0};
        wxString type = GetCellString(n,1);

        if(type == wxT("起点"))
        {
            //dlg_P.L->SetValue(GetCellString(n,2));
            //dlg_P.X->SetValue(GetCellString(n,4));
            //dlg_P.Y->SetValue(GetCellString(n,5));
            //dlg_P.W->SetValue(AngleConver(GetCellString(n,8)));
            if(dlg_P.ShowModal() == wxID_OK)
            {
    //            ListHorizon->SetItem(0,2,dlg_P.L->GetValue());
    //            ListHorizon->SetItem(0,4,dlg_P.X->GetValue());
    //            ListHorizon->SetItem(0,5,dlg_P.Y->GetValue());
    //            ListHorizon->SetItem(0,8,dlg_P.W->GetValue());
    //            ListHorizon->Select(0);

                //h.type = ROAD_TYPE_START_POINT;
                //h.angle1 = Angle_to_Radian(dlg_P.W->GetValue());
                //dlg_P.L->GetValue().ToDouble(&h.l1);
                //dlg_P.X->GetValue().ToDouble(&h.x1);
                //dlg_P.Y->GetValue().ToDouble(&h.y1);
                road_modify_horizon(r,&h,n);
                //if(cli->iclient==2) client_edit_horizon(cli,&h,n);

                road_apply_horizon(r);
    //            UpdateGraph(true);
            }
        }
        else if(type == wxT("直线"))
        {
            //dlg_L.L->SetValue(GetCellString(n,3));
            //dlg_L.Ori->SetValue(AngleConver(GetCellString(n,8)));
            double ori1=Angle_to_Radian(AngleConver(GetCellString(n,8)));
            if(dlg_L.ShowModal() == wxID_OK)
            {
    //            ListHorizon->SetItem(n,3,dlg_L.L->GetValue());
    //            ListHorizon->Select(n);

                h.type = ROAD_TYPE_LINE;
                //dlg_L.L->GetValue().ToDouble(&h.length);
                //h.deta = road_horizon(r,n)->deta+Angle_to_Radian(dlg_L.Ori->GetValue())-ori1;
                road_modify_horizon(r,&h,n);
                //if(cli->iclient==2) client_edit_horizon(cli,&h,n);

                road_apply_horizon(r);
    //            UpdateGraph(true);
            }
        }
        else if(type == wxT("圆曲线"))
        {
            //dlg_R.R->SetValue(GetCellString(n,6));
            //dlg_R.L->SetValue(GetCellString(n,3));
            //if(GetCellString(n,9) == wxT("左"))
               // dlg_R.Turn->SetSelection(0);
            //else
              //  dlg_R.Turn->SetSelection(1);
            if(dlg_R.ShowModal() == wxID_OK)
            {
    //            ListHorizon->SetItem(n,6,dlg_R.R->GetValue());
    //            ListHorizon->SetItem(n,7,dlg_R.R->GetValue());
    //            ListHorizon->SetItem(n,3,dlg_R.L->GetValue());
    //            ListHorizon->SetItem(n,9,dlg_R.Turn->GetStringSelection());
    //            ListHorizon->Select(n);

                h.type = ROAD_TYPE_ARC;
                //dlg_R.R->GetValue().ToDouble(&h.radius);
                //dlg_R.L->GetValue().ToDouble(&h.length);
                //if(dlg_R.Turn->GetSelection() == 0)
                   // h.pz = ROAD_LEFT;
                //else
                    //h.pz = ROAD_RIGHT;
                road_modify_horizon(r,&h,n);
                //if(cli->iclient==2) client_edit_horizon(cli,&h,n);

                road_apply_horizon(r);
    //            UpdateGraph(true);
            }
        }
        else if(type==wxT("缓和曲线"))              ///缓和曲线
        {
            dlg_M.R1->SetValue(GetCellString(n,6));
            dlg_M.R2->SetValue(GetCellString(n,7));
            dlg_M.L->SetValue(GetCellString(n,3));
            //if(GetCellString(n,9) == wxT("左"))
                //dlg_M.Turn->SetSelection(0);
            //else
                //dlg_M.Turn->SetSelection(1);
            if(dlg_M.ShowModal() == wxID_OK)
            {
    //            ListHorizon->SetItem(n,6,dlg_M.R1->GetValue());
    //            ListHorizon->SetItem(n,7,dlg_M.R2->GetValue());
    //            ListHorizon->SetItem(n,3,dlg_M.L->GetValue());
    //            ListHorizon->SetItem(n,9,dlg_M.Turn->GetStringSelection());
    //            ListHorizon->Select(n);

                h.type = ROAD_TYPE_SPIRAL;
                dlg_M.R1->GetValue().ToDouble(&h.rou1);
                dlg_M.R2->GetValue().ToDouble(&h.rou2);
                dlg_M.L->GetValue().ToDouble(&h.length);
                //if(dlg_M.Turn->GetSelection() == 0)
                    //h.pz = ROAD_LEFT;
                //else
                   // h.pz = ROAD_RIGHT;
                road_modify_horizon(r,&h,n);
                //if(cli->iclient==2) client_edit_horizon(cli,&h,n);

                road_apply_horizon(r);
    //            UpdateGraph(true);
            }
        }
        else if(type == wxT("终点"))
        {
            //dlg_P.L->SetValue(GetCellString(n,2));
            //dlg_P.X->SetValue(GetCellString(n,4));
            //dlg_P.Y->SetValue(GetCellString(n,5));
            //dlg_P.W->SetValue(AngleConver(GetCellString(n,8)));
            //dlg_P.L->Enable(false);
            //dlg_P.X->Enable(false);
            //dlg_P.Y->Enable(false);
            //dlg_P.W->Enable(false);
            //dlg_P.StaticText5->SetLabel(wxT("终点"));
            //dlg_P.ShowModal();
        }
        UpdateList();
        ListHorizon->Select(n);
        UpdateGraph(true);
    }
}
void HorizonPanel::OnDeleteClick(wxCommandEvent& event)
{
    if(cli->onLine == 0)
    {
        int n = ListHorizon->GetFirstSelected();
        int Num = ListHorizon->GetItemCount();
        if(n<=0 || n>=Num-1) return;
        wxMessageDialog dlg(this,_("删除操作将不可恢复\n确定要进行删除吗？"),_("平曲线要素"),wxYES_NO|wxICON_INFORMATION);
        if(dlg.ShowModal() == wxID_YES)
        {
            road * r=&cli->r;
            long del=n;
            if(del==0)
            {
                if(Num==1)
                {
                    //ListHorizon->DeleteItem(del);
                    road_remove_horizon(r,n);
                    road_apply_horizon(r);
                    //if(cli->iclient==2) client_remove_horizon(cli,n);

                }
                else
                    return;
            }
            else
            {
                //ListHorizon->DeleteItem(del);
    //            for(int i = n; i<Num; i++)
    //                ListHorizon->SetItem(i,0,wxString::Format(wxT("%d"),i+1));
                road_remove_horizon(r,n);
                road_apply_horizon(r);
                //if(cli->iclient==2) client_remove_horizon(cli,n);

    //            if(n == Num-1)
    //                ListHorizon->Select(n-1);
    //            else
    //                ListHorizon->Select(n);
            }

            UpdateList();
            if(n == Num-1)
                ListHorizon->Select(n-1);
            else
                ListHorizon->Select(n);
            UpdateGraph();
        }
    }
}

const wxString HorizonPanel::GetCellString( int row, int col )
{
    wxListItem row_info;
    wxString str;
    row_info.m_itemId = row;
    row_info.m_col = col;
    row_info.m_mask = wxLIST_MASK_TEXT;
    ListHorizon->GetItem(row_info);
    str = row_info.m_text;
    return str;
}

void HorizonPanel::UpdateGraph(bool fit)
{
    road* r=&cli->r;
    int n=road_number_horizon(r);
    GraphHorizon->Clear();
    int i;
    //double l;

    int npt=0;
    double *xy=0;

    for(i=0; i<n; i++)
    {
        h_element* e=road_horizon(r,i);
        //l=e->l1;
        if(e->type==ROAD_TYPE_LINE)
        {
            npt=2;
            xy=new double[4];
            xy[0]=e->y1;
            xy[1]=e->x1;
            xy[2]=e->y2;
            xy[3]=e->x2;
            GraphHorizon->AddPolyLine(npt,xy);
            delete xy;
            //GraphHorizon->AddLine(e->y1,e->x1,e->y2,e->x2);
        }
        else if(e->type==ROAD_TYPE_ARC || e->type==ROAD_TYPE_SPIRAL)
        {
            npt=21;
            //wxMessageBox(wxString::Format(wxT("npt=%d"),npt));
            xy=new double[2*npt];
            int index=0;
            xy[2*index]=e->y1;
            xy[2*index+1]=e->x1;
            index++;
            double l=e->l1+e->length/20.0;
            while(e->length >0.001  && l<e->l1+e->length)
            {
                road_l2xy(r,l,&xy[2*index+1],&xy[2*index],0);
                index++;
                if(index>=npt-1) break;
                l+=(e->length/20.0);
                //wxMessageBox(wxString::Format(wxT("index=%d"),index));
            }
            xy[2*index]=e->y2;
            xy[2*index+1]=e->x2;

            GraphHorizon->AddPolyLine(npt,xy);
            delete xy;
        }

        GraphHorizon->AddSymbol(e->y2,e->x2,0);
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
            h_element* e1=road_horizon(r,i+1);
            if(e->type==ROAD_TYPE_LINE)
            {
                str+=_("Z");
            }
            else if(e->type==ROAD_TYPE_ARC)
            {
                str+=_("Y");
            }
            else if(e->type==ROAD_TYPE_SPIRAL)
            {
                str+=_("H");
            }
            if(e1->type==ROAD_TYPE_LINE)
            {
                str+=_("Z");
            }
            else if(e1->type==ROAD_TYPE_ARC)
            {
                str+=_("Y");
            }
            else if(e1->type==ROAD_TYPE_SPIRAL)
            {
                str+=_("H");
            }
        }
        GraphHorizon->AddText(str,e->y2,e->x2);
    }
    int sel=ListHorizon->GetFirstSelected();
    GraphHorizon->SelectPolyline(sel-1);
    if(fit)
    {
        GraphHorizon->FitAll();
    }
    else
    {
        GraphHorizon->ResetMapPoints();
    }
}

void HorizonPanel::OnListHorizonItemActivated(wxListEvent& event)
{
    if(cli->onLine == 0)
    {
        wxCommandEvent e;
        OnModifyClick(e);
    }
}

void HorizonPanel::OnListHorizonItemSelect(wxListEvent& event)
{
    wxArrayInt sels=GraphHorizon->GetSelectedPolyLine();
    for(int i=0; i<sels.Count(); i++)
    {
        GraphHorizon->SelectPolyline(sels[i],false);
    }
    if(event.GetIndex()>=1)
    {
        GraphHorizon->SelectPolyline(event.GetIndex()-1);
        GraphHorizon->Refresh(false);
    }
}

void HorizonPanel::OnListHorizonItemDeselect(wxListEvent& event)
{
    wxArrayInt sels=GraphHorizon->GetSelectedPolyLine();
    for(int i=0; i<sels.Count(); i++)
    {
        GraphHorizon->SelectPolyline(sels[i],false);
    }
    GraphHorizon->SelectPolyline(-1);
    GraphHorizon->Refresh(false);
}

void HorizonPanel::OnPolylineSel(wxCommandEvent& event)
{
    wxArrayInt sels=GraphHorizon->GetSelectedPolyLine();
    for(int i=0; i<ListHorizon->GetItemCount(); i++) ListHorizon->Select(i,false);
    for(int i=0; i<sels.Count(); i++)
    {
        GraphHorizon->SelectPolyline(sels[i],false);
    }
    int sel=event.GetId();
    ListHorizon->Select(sel+1,true);
    GraphHorizon->SelectPolyline(sel,true);
    GraphHorizon->Refresh(false);
}
