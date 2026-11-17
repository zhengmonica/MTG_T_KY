#include "wx_pch.h"
#include "KeyAreaDlg.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(KeyAreaDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(KeyAreaDlg)
#include <wx/font.h>
#include <wx/button.h>
//*)

//(*IdInit(KeyAreaDlg)
const long KeyAreaDlg::ID_STATICTEXT5 = wxNewId();
const long KeyAreaDlg::ID_STATICLINE1 = wxNewId();
const long KeyAreaDlg::ID_STATICTEXT3 = wxNewId();
const long KeyAreaDlg::ID_TEXTCTRL3 = wxNewId();
const long KeyAreaDlg::ID_STATICTEXT4 = wxNewId();
const long KeyAreaDlg::ID_TEXTCTRL4 = wxNewId();
const long KeyAreaDlg::ID_STATICTEXT1 = wxNewId();
const long KeyAreaDlg::ID_TEXTCTRL1 = wxNewId();
const long KeyAreaDlg::ID_STATICTEXT2 = wxNewId();
const long KeyAreaDlg::ID_TEXTCTRL2 = wxNewId();
const long KeyAreaDlg::ID_STATICLINE2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(KeyAreaDlg,wxDialog)
	//(*EventTable(KeyAreaDlg)
	//*)
END_EVENT_TABLE()

KeyAreaDlg::KeyAreaDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(KeyAreaDlg)
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;

	Create(parent, id, _("关键区域"), wxDefaultPosition, wxDefaultSize, wxCAPTION, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("添加关键区域"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont StaticText5Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	//StaticText5->SetFont(StaticText5Font);
	BoxSizer1->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(240,-1), wxLI_VERTICAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1 = new wxFlexGridSizer(4, 2, 0, 0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("区域名称"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	name = new wxMyTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(name, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("起点里程"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	mile1 = new wxMyTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer1->Add(mile1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("终点里程"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	mile2 = new wxMyTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(mile2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	//StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("提示距离"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	//FlexGridSizer1->Add(StaticText2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	//tips = new wxMyTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	//FlexGridSizer1->Add(tips, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	//StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Y           ="), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	//FlexGridSizer1->Add(StaticText2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	//Y = new wxMyTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	//FlexGridSizer1->Add(Y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(240,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	BoxSizer1->Add(StaticLine2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_OK, _("确定")));
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_CANCEL, _("取消")));
	StdDialogButtonSizer1->Realize();
	BoxSizer1->Add(StdDialogButtonSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

KeyAreaDlg::~KeyAreaDlg()
{
	//(*Destroy(KeyAreaDlg)
	//*)
	//wxMessageBox(_("ok"));
}

