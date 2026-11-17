#include "wx_pch.h"
#include "DataDlg.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(DataDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(DataDlg)
#include <wx/font.h>
//*)

#include <wx/stdpaths.h>
#include <wx/imaglist.h>
#include "mtg_tApp.h"

//(*IdInit(DataDlg)
const long DataDlg::ID_STATICTEXT1 = wxNewId();
const long DataDlg::ID_STATICLINE1 = wxNewId();
const long DataDlg::ID_LISTVIEW1 = wxNewId();
const long DataDlg::ID_STATICLINE2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DataDlg,wxDialog)
	//(*EventTable(DataDlg)
	//*)
END_EVENT_TABLE()


DataDlg::DataDlg(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(DataDlg)
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxCAPTION, _T("id"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("隧道中线检查"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(12,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(600,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DataList = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxSize(600,400), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW1"));
	FlexGridSizer1->Add(DataList, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(600,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	FlexGridSizer1->Add(StaticLine2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, wxID_OK, _("退出"), wxDefaultPosition, wxSize(72,32), 0, wxDefaultValidator, _T("wxID_OK"));
	BoxSizer1->Add(Button1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_TOP, 5);
	FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	//*)

	DataList->InsertColumn(0,_("序号"),wxLIST_FORMAT_RIGHT,50);
    DataList->InsertColumn(1,_("里程"),wxLIST_FORMAT_RIGHT,100);
    DataList->InsertColumn(2,_("X"),wxLIST_FORMAT_RIGHT,100);
    DataList->InsertColumn(3,_("Y"),wxLIST_FORMAT_RIGHT,100);
    DataList->InsertColumn(4,_("Z"),wxLIST_FORMAT_RIGHT,90);
    DataList->InsertColumn(5,_("平偏"),wxLIST_FORMAT_RIGHT,60);
    DataList->InsertColumn(6,_("垂偏"),wxLIST_FORMAT_RIGHT,60);
}

DataDlg::~DataDlg()
{
	//(*Destroy(DataDlg)
	//*)
}

