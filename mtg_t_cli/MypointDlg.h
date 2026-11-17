#ifndef MYPOINTDLG_H_INCLUDED
#define MYPOINTDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDButtonList.h"

//(*Headers(MypointDlg)
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
#include <wx/statline.h>
#include <wx/grid.h>
//*)

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// ClassMypointDlg
///////////////////////////////////////////////////////////////////////////////
class MypointDlg : public wxDialog
{
	private:
	    //(*Handlers(MypointDlg)
        void OnPaintMain(wxPaintEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
        //*)

	protected:
	    //(*Identifiers(MypointDlg)

        //*)
        enum
        {
            ID_PT_NONE,
            ID_PT_QUIT,
            ID_PT_OK,
            ID_PT_ADD,
            ID_PT_EDI,
            ID_PT_DEL,
            ID_PT_COUNT
        };

        wxPanel* panelMain;
        wxPanel* panelBottom;

        wxRect ptButton[ID_PT_COUNT];
        int motion;

	public:
		MypointDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _(""), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(220,230), long style = wxDEFAULT_DIALOG_STYLE);
		~MypointDlg();

        wxTextCtrl* ptName;
        wxTextCtrl* ptx;
        wxTextCtrl* pty;
        wxTextCtrl* ptz;

		//(*Declarations(MySetupDialog)

        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
