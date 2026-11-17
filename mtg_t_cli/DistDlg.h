#ifndef DISTDLG_H
#define DISTDLG_H

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDButtonList.h"

#ifndef WX_PRECOMP
	//(*HeadersPCH(DistDlg)
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(DistDlg)
   #include <wx/panel.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
#include <wx/statline.h>
#include <wx/grid.h>
//*)

class DistDlg: public wxDialog
{
	public:

		//DistDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		DistDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("²â¾àÒÇ"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(220,220), long style = wxDEFAULT_DIALOG_STYLE);
		virtual ~DistDlg();

		//(*Declarations(DistDlg)

		//*)
		wxTextCtrl* disterName;
		wxTextCtrl* disterAngle;
        wxTextCtrl* disterText;
        int Selected;

	protected:

		//(*Identifiers(DistDlg)
        static const long ID_PANEL1;             //§¢§ì§¾§ä
		//*)
		enum
        {
            ID_DISTER_NONE,
            ID_DISTER_QUIT,
            ID_DISTER_OK,
            ID_DISTER_ADD,
            ID_DISTER_EDI,
            ID_DISTER_DEL,
            ID_DISTER_SEL,
            ID_DISTER_COUNT
        };

        wxPanel* panelMain;
        wxPanel* panelBottom;

        wxRect dsButton[ID_DISTER_COUNT];
        int motion;

	private:

		//(*Handlers(DistDlg)
        void OnPaintMain(wxPaintEvent& event);
        void OnMotionMain(wxMouseEvent& event);
        void OnLeaveMain(wxMouseEvent& event);
        void OnClickMain(wxMouseEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
