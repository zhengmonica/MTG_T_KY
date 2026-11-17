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

class ConfirmDlg : public wxDialog
{
	public:

		ConfirmDlg (wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ConfirmDlg ();

        wxString confirmMsg;
		int type;
		//(*Declarations(ConfirmDlg )
		//*)

	protected:

		//(*Identifiers(ConfirmDlg )

        static const long ID_PANEL2;
		static const long ID_STATICLINE2;
		static const long ID_CHOICE1;
		//*)
		enum
		{
		    ID_CONFIRM_NONE,
		    ID_CONFIRM_CONFIRM,
		    ID_CONFIRM_CANCEL,
		    DLG_TYPE_OK,
		    DLG_TYPE_YESNO,
		    ID_CONFIRM_COUNT
		};
        wxPanel* panelConfirm;

        int motion;
	    wxRect confirmButton[ID_CONFIRM_COUNT];
	private:
        wxBitmap bmpTip1;
        wxBitmap bmpTip2;

		//(*Handlers(ConfirmDlg )
        void OnPaintPassword(wxPaintEvent& event);
        void OnMotionPassword(wxMouseEvent& event);
        void OnLeavePassword(wxMouseEvent& event);
        void OnClickPassword(wxMouseEvent& event);
		//*)


		DECLARE_EVENT_TABLE()
};

#endif
