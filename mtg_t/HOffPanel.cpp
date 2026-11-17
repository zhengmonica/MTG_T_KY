#include "wx_pch.h"
#include "HOffPanel.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(HOffPanel)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(HOffPanel)
//*)

#include "mtg_tApp.h"
#include "OffDialog.h"
#include <wx/msgdlg.h>

//(*IdInit(HOffPanel)
const long HOffPanel::ID_BUTTON1 = wxNewId();
const long HOffPanel::ID_BUTTON2 = wxNewId();
const long HOffPanel::ID_BUTTON3 = wxNewId();
const long HOffPanel::ID_LISTCTRL1 = wxNewId();
const long HOffPanel::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(HOffPanel,wxPanel)
	//(*EventTable(HOffPanel)
	//*)
END_EVENT_TABLE()

HOffPanel::HOffPanel(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(HOffPanel)
	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	btnAdd = new wxButton(this, ID_BUTTON1, _("增加"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	btnEdit = new wxButton(this, ID_BUTTON2, _("编辑"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	btnDel = new wxButton(this, ID_BUTTON3, _("删除"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	listOff = new wxListView(this, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxRAISED_BORDER, wxDefaultValidator, _T("ID_LISTCTRL1"));
	panelGraph = new MyCanvas(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HOffPanel::OnBtnAdd);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HOffPanel::OnBtnEdit);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HOffPanel::OnBtnDel);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&HOffPanel::OnlistOffItemActivated);
	Connect(wxEVT_SIZE,(wxObjectEventFunction)&HOffPanel::OnResize);
	//*)

	listOff->InsertColumn(0,_("序号"));
    listOff->InsertColumn(1,_("里程"));
    listOff->InsertColumn(2,_("偏移"));

    UpdateList();
    UpdateGraph(true);
}

HOffPanel::~HOffPanel()
{
	//(*Destroy(HOffPanel)
	//*)
}


void HOffPanel::OnResize(wxSizeEvent& event)
{
    int w,h;
    GetClientSize(&w,&h);
    btnAdd->SetSize(10,10,-1,-1);
    btnEdit->SetSize(10,50,-1,-1);
    btnDel->SetSize(10,90,-1,-1);
    listOff->SetSize(100,10,w-105,h/2-20);
    panelGraph->SetSize(100,h/2,w-105,h/2-20);

    //panelGraph->FitAll();
}

void HOffPanel::OnBtnAdd(wxCommandEvent& event)
{
    if(cli->onLine == 0)
    {
        road* r=&cli->r;
        OffDialog dlg(this);
        if(dlg.ShowModal()==wxID_OK)
        {
            h_offset ho;
            //dlg.textChain->GetValue().ToDouble(&ho.mile);
            //dlg.textOff->GetValue().ToDouble(&ho.off);
            if(road_insert_horizon_off(r,&ho)==0)
            {
                //if(cli->iclient==2) client_add_hoff(cli,&ho);

                UpdateList();
                UpdateGraph(true);
            }
        }
    }
}

void HOffPanel::OnBtnEdit(wxCommandEvent& event)
{
    if(cli->onLine == 0)
    {
        int sel=listOff->GetFirstSelected();
        if(sel<0) return;
        road* r=&cli->r;
        OffDialog dlg(this);
        h_offset *ho=road_horizon_off(r,sel);
        //dlg.textChain->SetValue(wxString::Format(_("%.3f"),ho->mile));
        //dlg.textOff->SetValue(wxString::Format(_("%.3f"),ho->off));
        if(dlg.ShowModal()==wxID_OK)
        {
            h_offset ho1;
            //dlg.textChain->GetValue().ToDouble(&ho1.mile);
            //dlg.textOff->GetValue().ToDouble(&ho1.off);
            if(road_modify_horizon_off(r,&ho1,sel)==0)
            {
                //if(cli->iclient==2) client_edit_hoff(cli,&ho1,sel);

                UpdateList();
                UpdateGraph(true);
            }
        }
    }
}

void HOffPanel::OnBtnDel(wxCommandEvent& event)
{
    if(cli->onLine == 0)
    {
        int sel=listOff->GetFirstSelected();
        if(sel<0) return;
        road* r=&cli->r;
        wxMessageDialog dlg(this,_("你确定要删除该偏移值吗？"),_("提示"),wxOK|wxCANCEL|wxCENTER|wxICON_WARNING);
        if(dlg.ShowModal()==wxID_OK)
        {
            if(road_erase_horizon_off(r,sel)==0)
            {
                //f(cli->iclient==2) client_remove_hoff(cli,sel);

                UpdateList();
                UpdateGraph(true);
            }
        }
    }
}

void HOffPanel::UpdateList()
{
    road* r=&cli->r;
    int n=road_number_horizon_off(r);
    listOff->DeleteAllItems();
    for(int i=0;i<n;i++)
    {
        h_offset* ho=road_horizon_off(r,i);
        listOff->InsertItem(i,wxString::Format(_("%d"),i+1));
        listOff->SetItem(i,1,wxString::Format(_("%.3f"),ho->mile));
        listOff->SetItem(i,2,wxString::Format(_("%.3f"),ho->off));
    }
}

void HOffPanel::UpdateGraph(bool fit)
{
    road* r=&cli->r;
    int n=road_number_horizon_off(r);
    panelGraph->Clear();

    double x1,y1,x2,y2;
    for(int i=0;i<n;i++)
    {
        h_offset* ho=road_horizon_off(r,i);
        if(i==0)
        {
            x1=ho->mile;
            y1=ho->off;
        }
        else
        {
            x2=ho->mile;
            y2=ho->off;
            panelGraph->AddLine(x1,y1,x2,y2);
            x1=x2;
            y1=y2;
        }
        panelGraph->AddText(wxString::Format(_("%.3f"),ho->mile),x1,y1);
    }
    if(fit) panelGraph->FitAll();
    else panelGraph->ResetMapPoints();
}


void HOffPanel::OnlistOffItemActivated(wxListEvent& event)
{
    if(cli->onLine == 0)
    {
        int sel=listOff->GetFirstSelected();
        if(sel<0) return;
        road* r=&cli->r;
        OffDialog dlg(this);
        h_offset *ho=road_horizon_off(r,sel);
        //dlg.textChain->SetValue(wxString::Format(_("%.3f"),ho->mile));
        //dlg.textOff->SetValue(wxString::Format(_("%.3f"),ho->off));
        if(dlg.ShowModal()==wxID_OK)
        {
            h_offset ho1;
            //dlg.textChain->GetValue().ToDouble(&ho1.mile);
            //dlg.textOff->GetValue().ToDouble(&ho1.off);
            if(road_modify_horizon_off(r,&ho1,sel)==0)
            {
                //if(cli->iclient==2) client_edit_hoff(cli,&ho1,sel);

                UpdateList();
                UpdateGraph(true);
            }
        }
    }
}
