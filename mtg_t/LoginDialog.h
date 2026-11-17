#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(LoginDialog)
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(LoginDialog)
#include <wx/statline.h>
//*)
#include "mtgcli.h"
#include "wxMyTextCtrl.h"

class LoginDialog: public wxDialog
{
	public:

		LoginDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~LoginDialog();

		//(*Declarations(LoginDialog)
		wxButton* ButtonCANCEL;
		wxStaticText* StaticText2;
		wxButton* ButtonOK;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* TextPsw;
		wxStaticLine* StaticLine2;
		wxTextCtrl* TextUid;
		wxStaticLine* StaticLine1;
		//*)

	protected:

		//(*Identifiers(LoginDialog)
		static const long ID_STATICTEXT1;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICLINE2;
		//*)

	private:

		//(*Handlers(LoginDialog)
		void OnButtonOKClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
