#include "wx_pch.h"
#include "BlockDlg.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(BlockDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(BlockDlg)
#include <wx/font.h>
#include <wx/button.h>
//*)

//(*IdInit(BlockDlg)
const long BlockDlg::ID_STATICTEXT5 = wxNewId();
const long BlockDlg::ID_STATICLINE1 = wxNewId();
const long BlockDlg::ID_STATICTEXT3 = wxNewId();
const long BlockDlg::ID_TEXTCTRL3 = wxNewId();
const long BlockDlg::ID_STATICTEXT4 = wxNewId();
const long BlockDlg::ID_TEXTCTRL4 = wxNewId();
const long BlockDlg::ID_STATICTEXT1 = wxNewId();
const long BlockDlg::ID_TEXTCTRL1 = wxNewId();
const long BlockDlg::ID_STATICTEXT2 = wxNewId();
const long BlockDlg::ID_TEXTCTRL2 = wxNewId();
const long BlockDlg::ID_STATICLINE2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(BlockDlg,wxDialog)
	//(*EventTable(BlockDlg)
	//*)
END_EVENT_TABLE()

BlockDlg::BlockDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(BlockDlg)
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;

	Create(parent, id, _("管块设置"), wxDefaultPosition, wxDefaultSize, wxCAPTION, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("添加管块"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont StaticText5Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	//StaticText5->SetFont(StaticText5Font);
	BoxSizer1->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(250,-1), wxLI_VERTICAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1 = new wxFlexGridSizer(4, 2, 0, 0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("管块名称"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	blockName = new wxMyTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(blockName, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("圆心角"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	blockAngle = new wxMyTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer1->Add(blockAngle, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	//StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("X           ="), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	//FlexGridSizer1->Add(StaticText1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	//X = new wxMyTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	//FlexGridSizer1->Add(X, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	//StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Y           ="), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	//FlexGridSizer1->Add(StaticText2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	//Y = new wxMyTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	//FlexGridSizer1->Add(Y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(250,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
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

BlockDlg::~BlockDlg()
{
	//(*Destroy(BlockDlg)
	//*)
}

