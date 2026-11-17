#ifndef BLOCKDLG_H_INCLUDED
#define BLOCKDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDTitle.h"
#include "MDButtonList.h"

//(*Headers(BlockDlg)
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
/// Class BlockDlg
///////////////////////////////////////////////////////////////////////////////
class BlockDlg : public wxDialog
{
	private:
	    //(*Handlers(BlockDlg)
        void OnPaintBackground(wxPaintEvent& event);
        void OnButtonClick(wxMouseEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
        //*)
        wxStaticText* blkStaticText1;
        wxStaticText* blkStaticText2;

	protected:
	    //(*Identifiers(BlockDlg)
	    static const long ID_PANEL1;             //БъЬт
        //*)
        enum
        {
            ID_BLK_NONE,
            ID_BLK_QUIT,
            ID_BLK_OK,
            ID_BLK_ADD,
            ID_BLK_EDI,
            ID_BLK_DEL,
            ID_BLK_COUNT
        };

        wxPanel* panelMain;
        wxPanel* blkPanel;
        wxPanel* panelBottom;
        wxRect button[ID_BLK_COUNT];
        int motion;

	public:
		BlockDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _(""), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(200,210), long style = wxBORDER_RAISED);
		~BlockDlg();

        wxTextCtrl* blkName;
        wxTextCtrl* Angle;

		//(*Declarations(MySetupDialog)
        MDTitle* panelTitle;                    //ID_PANEL1
        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
