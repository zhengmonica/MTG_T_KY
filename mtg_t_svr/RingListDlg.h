#ifndef RINGLISTDLG_H_INCLUDED
#define RINGLISTDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDButtonList.h"
#include "mtg_t_svrApp.h"

//(*Headers(RingListDlg)
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
/// Class RingListDlg
///////////////////////////////////////////////////////////////////////////////
class RingListDlg : public wxDialog
{
	private:
	    //(*Handlers(RingListDlg)
        void OnPaintMain(wxPaintEvent& event);

        void OnPaintText(wxPaintEvent& event);
        //*)
        void UpdateList();
	protected:
	    //(*Identifiers(RingListDlg)
	    static const long ID_PANEL1;             //标题
        //*)
        enum
        {
            ID_RNG_LIST_NONE,
            ID_RNG_LIST_QUIT,
            ID_RNG_LIST_COUNT
        };

        wxPanel* panelMain;
        wxListView* segList;

        wxRect button[ID_RNG_LIST_COUNT];
        int motion;

	public:
		RingListDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("管环沉降监测"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,480), long style = wxDEFAULT_DIALOG_STYLE);
		~RingListDlg();

        int Type;
		//(*Declarations(MySetupDialog)

        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
