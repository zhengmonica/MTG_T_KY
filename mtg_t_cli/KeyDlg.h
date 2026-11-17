#ifndef KEYDLG_H_INCLUDED
#define KEYDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDTitle.h"
#include "MDButtonList.h"

//(*Headers(KeyDlg)
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
/// Class KeyDlg
///////////////////////////////////////////////////////////////////////////////
class KeyDlg : public wxDialog
{
	private:
	    //(*Handlers(KeyDlg)
        void OnPaintBackground(wxPaintEvent& event);
        void OnButtonClick(wxMouseEvent& event);

        void OnPaintKey(wxPaintEvent& event);
        void OnMotionKey(wxMouseEvent& event);
        void OnLeaveKey(wxMouseEvent& event);
        void OnClickKey(wxMouseEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
        //*)
        wxStaticText* bskStaticText1;
        wxStaticText* bskStaticText2;
        wxStaticText* bskStaticText3;

	protected:
	    //(*Identifiers(KeyDlg)
	    static const long ID_PANEL1;             //БъЬт
        //*)
        enum
        {
            ID_KEY_NONE,
            ID_KEY_QUIT,
            ID_KEY_OK,
            ID_KEY_ADD,
            ID_KEY_EDI,
            ID_KEY_DEL,
            ID_KEY_COUNT
        };

        wxPanel* panelMain;
        wxPanel* keyPanel;
        wxPanel* panelBottom;

        wxPanel* figPanel;

        wxRect button[ID_KEY_COUNT];
        int motion;

	public:
		KeyDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _(""), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 480,360), long style = wxBORDER_RAISED);
		~KeyDlg();

        wxTextCtrl* keyName;
        wxTextCtrl* mile1;
        wxTextCtrl* mile2;
        int a2z;
        double p1;
        double p2;
        double tip;
		//(*Declarations(MySetupDialog)
        MDTitle* panelTitle;                    //ID_PANEL1
        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
