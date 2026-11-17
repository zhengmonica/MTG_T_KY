#ifndef SEGRECORDDLG_H
#define SEGRECORDDLG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(SegRecordDlg)
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(SegRecordDlg)
//*)

class SegRecordDlg: public wxDialog
{
	public:

		SegRecordDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _(""), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(220,230), long style = wxDEFAULT_DIALOG_STYLE);
		~SegRecordDlg();

        wxTextCtrl* SegNum;
        wxChoice* SegType;
        wxTextCtrl* Location;

		//(*Declarations(SegRecordDlg)
		//*)

	protected:

		//(*Identifiers(SegRecordDlg)
		//*)
		enum
        {
            ID_PT_NONE,
            ID_PT_QUIT,
            ID_PT_OK,
            ID_PT_COUNT
        };

        wxPanel* panelMain;
        wxPanel* panelBottom;

        wxRect ptButton[ID_PT_COUNT];
        int motion;

	private:

		//(*Handlers(SegRecordDlg)
        void OnPaintMain(wxPaintEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
