#include "wx_pch.h"
#include "UserManagerDlg.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(UserManagerDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(UserManagerDlg)
#include <wx/font.h>
#include <wx/button.h>
//*)

//(*IdInit(UserManagerDlg)
const long UserManagerDlg::ID_STATICTEXT5 = wxNewId();
const long UserManagerDlg::ID_STATICLINE1 = wxNewId();
const long UserManagerDlg::ID_STATICTEXT3 = wxNewId();
const long UserManagerDlg::ID_TEXTCTRL3 = wxNewId();
const long UserManagerDlg::ID_STATICTEXT4 = wxNewId();
const long UserManagerDlg::ID_TEXTCTRL4 = wxNewId();
const long UserManagerDlg::ID_STATICTEXT1 = wxNewId();
//const long UserManagerDlg::ID_TEXTCTRL1 = wxNewId();
const long UserManagerDlg::ID_STATICTEXT2 = wxNewId();
const long UserManagerDlg::ID_TEXTCTRL2 = wxNewId();
const long UserManagerDlg::ID_STATICLINE2 = wxNewId();
const long UserManagerDlg::ID_CHOICE1 = wxNewId();                //权限选择
//*)

BEGIN_EVENT_TABLE(UserManagerDlg,wxDialog)
	//(*EventTable(UserManagerDlg)
	//*)
END_EVENT_TABLE()

UserManagerDlg::UserManagerDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(UserManagerDlg)
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;

	Create(parent, id, _("用户管理"), wxDefaultPosition, wxDefaultSize, wxCAPTION, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("添加用户"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont StaticText5Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	//StaticText5->SetFont(StaticText5Font);
	BoxSizer1->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(240,-1), wxLI_VERTICAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1 = new wxFlexGridSizer(4, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("权限等级"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    levelChoice = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(140,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	levelChoice->SetSelection(levelChoice->Append(_("管理权限")) );
    levelChoice->Append(_("操作权限"));
	FlexGridSizer1->Add(levelChoice, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);

	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("用户名称"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	Name = new wxMyTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(140,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(Name, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("授权密码"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	Password = new wxMyTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(140,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer1->Add(Password, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);

	//mile2 = new wxMyTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(140,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));

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

UserManagerDlg::~UserManagerDlg()
{
	//(*Destroy(UserManagerDlg)
	//*)
}

