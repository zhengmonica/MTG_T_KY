#include "wx_pch.h"
#include "LoginDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(LoginDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(LoginDialog)
#include <wx/font.h>
//*)

//(*IdInit(LoginDialog)
const long LoginDialog::ID_STATICTEXT1 = wxNewId();
const long LoginDialog::ID_STATICLINE1 = wxNewId();
const long LoginDialog::ID_STATICTEXT2 = wxNewId();
const long LoginDialog::ID_TEXTCTRL1 = wxNewId();
const long LoginDialog::ID_STATICTEXT3 = wxNewId();
const long LoginDialog::ID_TEXTCTRL2 = wxNewId();
const long LoginDialog::ID_STATICLINE2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LoginDialog,wxDialog)
	//(*EventTable(LoginDialog)
	//*)
END_EVENT_TABLE()

LoginDialog::LoginDialog(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(LoginDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(344,233));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("用户登录"), wxPoint(128,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(0,48), wxSize(360,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("用户名"), wxPoint(64,80), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	TextUid = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(128,72), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("密码"), wxPoint(64,120), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	TextPsw = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(128,120), wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxPoint(0,168), wxSize(360,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	ButtonOK = new wxButton(this, wxID_OK, _("确定"), wxPoint(56,192), wxSize(100,30), 0, wxDefaultValidator, _T("wxID_OK"));
	ButtonCANCEL = new wxButton(this, wxID_CANCEL, _("取消"), wxPoint(192,192), wxSize(100,30), 0, wxDefaultValidator, _T("wxID_CANCEL"));
	//*)
}

LoginDialog::~LoginDialog()
{
	//(*Destroy(LoginDialog)
	//*)
}

