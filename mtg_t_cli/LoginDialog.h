#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(PasswordDialog)
	#include <wx/stattext.h>
	#include "wxMyTextCtrl.h"
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(PasswordDialog)
#include <wx/statline.h>
//*)

#include "wxMyTextCtrl.h"
#include "MDTitle.h"

class LoginDialog: public wxDialog
{
	public:

		LoginDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~LoginDialog();

		//(*Declarations(LoginDialog)
		wxMyTextCtrl* ip1;
		wxMyTextCtrl* ip2;
		wxMyTextCtrl* ip3;
		wxMyTextCtrl* ip4;
		//*)

	protected:

		//(*Identifiers(LoginDialog)
        static const long ID_PANEL1;
		//*)
        enum
		{
		    ID_LOGIN_NONE,
		    ID_LOGIN_LOGIN,
		    ID_LOGIN_CANCEL,
		    ID_LOGIN_COUNT
		};
        MDTitle* m_title;
	    wxPanel* panelLogin;

        int motion;
	    wxRect loginButton[ID_LOGIN_COUNT];
	private:

		//(*Handlers(LoginDialog)
		void OnPaintLogin(wxPaintEvent& event);
        void OnMotionLogin(wxMouseEvent& event);
        void OnLeaveLogin(wxMouseEvent& event);
        void OnClickLogin(wxMouseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
