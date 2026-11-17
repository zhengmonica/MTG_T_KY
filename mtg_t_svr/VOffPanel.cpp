#include "wx_pch.h"
#include "VOffPanel.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(VOffPanel)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(VOffPanel)
//*)

#include "mtg_t_svrApp.h"
#include "OffDialog.h"
#include <wx/msgdlg.h>

//(*IdInit(VOffPanel)
const long VOffPanel::ID_BUTTON1 = wxNewId();
const long VOffPanel::ID_BUTTON2 = wxNewId();
const long VOffPanel::ID_BUTTON3 = wxNewId();
const long VOffPanel::ID_LISTCTRL1 = wxNewId();
const long VOffPanel::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(VOffPanel,wxPanel)
	//(*EventTable(VOffPanel)
	//*)
END_EVENT_TABLE()

VOffPanel::VOffPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(VOffPanel)
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	btnAdd = new wxButton(this, ID_BUTTON1, _("增加"), wxPoint(8,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	btnEdit = new wxButton(this, ID_BUTTON2, _("编辑"), wxPoint(8,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	btnDel = new wxButton(this, ID_BUTTON3, _("删除"), wxPoint(8,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	listOff = new wxListView(this, ID_LISTCTRL1, wxPoint(112,16), wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxRAISED_BORDER, wxDefaultValidator, _T("ID_LISTCTRL1"));
	panelGraph = new MyCanvas(this, ID_PANEL1, wxPoint(112,120), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VOffPanel::OnBtnAdd);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VOffPanel::OnBtnEdit);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VOffPanel::OnBtnDel);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&VOffPanel::OnlistOffItemActivated);
	Connect(wxEVT_SIZE,(wxObjectEventFunction)&VOffPanel::OnResize);
	//*)

	listOff->InsertColumn(0,_("序号"));
    listOff->InsertColumn(1,_("里程"));
    listOff->InsertColumn(2,_("偏移"));

    UpdateList();
    UpdateGraph(true);
}

VOffPanel::~VOffPanel()
{
	//(*Destroy(VOffPanel)
	//*)
}


void VOffPanel::OnResize(wxSizeEvent& event)
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

void VOffPanel::OnBtnAdd(wxCommandEvent& event)
{
    if(mtg->onLine == 0)
    {
        road* r=&mtg->r;
        OffDialog dlg(this);
        if(dlg.ShowModal()==wxID_OK)
        {
            v_offset vo;
            //dlg.textChain->GetValue().ToDouble(&vo.mile);
            //dlg.textOff->GetValue().ToDouble(&vo.off);
            if(road_insert_vertical_off(r,&vo)==0)
            {
                //if(mtg->iclient==2) client_add_voff(mtg,&vo);

                UpdateList();
                UpdateGraph(true);
            }
        }
    }
}

void VOffPanel::OnBtnEdit(wxCommandEvent& event)
{
    if(mtg->onLine == 0)
    {
        int sel=listOff->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        OffDialog dlg(this);
        v_offset *vo=road_vertical_off(r,sel);
        //dlg.textChain->SetValue(wxString::Format(_("%.3f"),vo->mile));
        //dlg.textOff->SetValue(wxString::Format(_("%.3f"),vo->off));
        if(dlg.ShowModal()==wxID_OK)
        {
            v_offset vo1;
            //dlg.textChain->GetValue().ToDouble(&vo1.mile);
            //dlg.textOff->GetValue().ToDouble(&vo1.off);
            if(road_modify_vertical_off(r,&vo1,sel)==0)
            {
                //if(mtg->iclient==2) client_edit_voff(mtg,&vo1,sel);

                UpdateList();
                UpdateGraph(true);
            }
        }
    }
}

void VOffPanel::OnBtnDel(wxCommandEvent& event)
{
    if(mtg->onLine == 0)
    {
        int sel=listOff->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        wxMessageDialog dlg(this,_("你确定要删除该偏移值吗？"),_("提示"),wxOK|wxCANCEL|wxCENTER|wxICON_WARNING);
        if(dlg.ShowModal()==wxID_OK)
        {
            if(road_erase_vertical_off(r,sel)==0)
            {
                //if(mtg->iclient==2) client_remove_voff(mtg,sel);

                UpdateList();
                UpdateGraph(true);
            }
        }
    }
}

void VOffPanel::UpdateList()
{
    road* r=&mtg->r;
    int n=road_number_vertical_off(r);
    listOff->DeleteAllItems();
    for(int i=0;i<n;i++)
    {
        v_offset* vo=road_vertical_off(r,i);
        listOff->InsertItem(i,wxString::Format(_("%d"),i+1));
        listOff->SetItem(i,1,wxString::Format(_("%.3f"),vo->mile));
        listOff->SetItem(i,2,wxString::Format(_("%.3f"),vo->off));
    }
}

void VOffPanel::UpdateGraph(bool fit)
{
    road* r=&mtg->r;
    int n=road_number_vertical_off(r);
    panelGraph->Clear();

    double x1,y1,x2,y2;
    for(int i=0;i<n;i++)
    {
        v_offset* vo=road_vertical_off(r,i);
        if(i==0)
        {
            x1=vo->mile;
            y1=vo->off;
        }
        else
        {
            x2=vo->mile;
            y2=vo->off;
            panelGraph->AddLine(x1,y1,x2,y2);
            x1=x2;
            y1=y2;
        }
        panelGraph->AddText(wxString::Format(_("%.3f"),vo->mile),x1,y1);
    }
    if(fit) panelGraph->FitAll();
    else panelGraph->ResetMapPoints();
}

void VOffPanel::OnlistOffItemActivated(wxListEvent& event)
{
    if(mtg->onLine == 0)
    {
        int sel=listOff->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        OffDialog dlg(this);
        v_offset *vo=road_vertical_off(r,sel);
        //dlg.textChain->SetValue(wxString::Format(_("%.3f"),vo->mile));
        //dlg.textOff->SetValue(wxString::Format(_("%.3f"),vo->off));
        if(dlg.ShowModal()==wxID_OK)
        {
            v_offset vo1;
            //dlg.textChain->GetValue().ToDouble(&vo1.mile);
            //dlg.textOff->GetValue().ToDouble(&vo1.off);
            if(road_modify_vertical_off(r,&vo1,sel)==0)
            {
                //if(mtg->iclient==2) client_edit_voff(mtg,&vo1,sel);

                UpdateList();
                UpdateGraph(true);
            }
        }
    }
}
