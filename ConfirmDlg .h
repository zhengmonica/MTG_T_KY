#ifndef CONFIRMDLG_H
#define CONFIRMDLG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(ConfirmDlg )
	#include <wx/stattext.h>
	#include "wxMyTextCtrl.h"
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(ConfirmDlg )
#include <wx/statline.h>
//*)

#include "wxMyTextCtrl.h"

class ConfirmDlg : public wxDialog
{
	public:

		ConfirmDlg (wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ConfirmDlg ();
        int iuser;
        int iget;           ///0操作权限1管理权限
		//(*Declarations(ConfirmDlg )
		wxMyTextCtrl* TextPassword;
		//*)

	protected:

		//(*Identifiers(ConfirmDlg )

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

	    wxPanel* panelPassword;

        int motion;
	    wxRect pswButton[ID_PSW_COUNT];
	private:

		//(*Handlers(ConfirmDlg )
        void OnPaintPassword(wxPaintEvent& event);
        void OnMotionPassword(wxMouseEvent& event);
        void OnLeavePassword(wxMouseEvent& event);
        void OnClickPassword(wxMouseEvent& event);
		//*)


		DECLARE_EVENT_TABLE()
};

#endif
