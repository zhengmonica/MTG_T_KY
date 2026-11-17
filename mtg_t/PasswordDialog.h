#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

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

class PasswordDialog: public wxDialog
{
	public:

		PasswordDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~PasswordDialog();
        int iuser;
        int iget;           ///0操作权限1管理权限
		//(*Declarations(PasswordDialog)
		wxMyTextCtrl* TextPassword;
		//*)

	protected:

		//(*Identifiers(PasswordDialog)
        static const long ID_PANEL1;
        static const long ID_PANEL2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICLINE2;
		static const long ID_CHOICE1;
		//*)
		enum
		{
		    ID_PSW_NONE,
		    ID_PSW_CONFIRM,
		    ID_PSW_CANCEL,
		    ID_PSW_MANAGER,
		    ID_PSW_OPERAROR,
		    ID_PSW_COUNT
		};
        MDTitle* m_title;
	    wxPanel* panelPassword;

        int motion;
	    wxRect pswButton[ID_PSW_COUNT];
	private:

		//(*Handlers(PasswordDialog)
        void OnPaintPassword(wxPaintEvent& event);
        void OnMotionPassword(wxMouseEvent& event);
        void OnLeavePassword(wxMouseEvent& event);
        void OnClickPassword(wxMouseEvent& event);
		//*)


		DECLARE_EVENT_TABLE()
};

#endif
