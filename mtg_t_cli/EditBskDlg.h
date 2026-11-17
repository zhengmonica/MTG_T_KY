#ifndef EDITBSKDLG_H_INCLUDED
#define EDITBSKDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDTitle.h"
#include "MDButtonList.h"

//(*Headers(LogDialog)
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
/// ClassEditBskDlg
///////////////////////////////////////////////////////////////////////////////
class EditBskDlg : public wxDialog
{
	private:
	    //(*Handlers(EditBskDlg)
        void OnPaintBackground(wxPaintEvent& event);
        void OnButtonClick(wxMouseEvent& event);

        void OnPaintBasket(wxPaintEvent& event);
        void OnMotionBasket(wxMouseEvent& event);
        void OnLeaveBasket(wxMouseEvent& event);
        void OnClickBasket(wxMouseEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
        //*)
        wxStaticText* bskStaticText1;
        wxStaticText* bskStaticText2;
        wxStaticText* bskStaticText3;
        wxStaticText* bskStaticText4;

	protected:
	    //(*Identifiers(EditBskDlg)
	    static const long ID_PANEL1;             //БъЬт
        //*)
        enum
        {
            ID_EDITB_NONE,
            ID_EDITB_QUIT,
            ID_EDITB_OK,
            ID_EDITB_ADD,
            ID_EDITB_EDI,
            ID_EDITB_DEL,
            ID_EDITB_COUNT
        };

        wxPanel* panelMain;
        wxPanel* bskPanel;
        wxPanel* panelBottom;

        wxPanel* figPanel;

        wxRect bskButton[ID_EDITB_COUNT];
        int motion;

	public:
		EditBskDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _(""), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 480,360), long style = wxBORDER_RAISED);
		~EditBskDlg();

        wxTextCtrl* bskName;
        wxTextCtrl* bskX;
        wxTextCtrl* bskY;
        wxTextCtrl* bskZ;

		//(*Declarations(MySetupDialog)
        MDTitle* panelTitle;                    //ID_PANEL1
        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
