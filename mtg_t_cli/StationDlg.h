#ifndef STATIONDLG_H_INCLUDED
#define STATIONDLG_H_INCLUDED

#include "mtg_t_cliApp.h"
#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDButtonList.h"

//(*Headers(StationDlg)
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
/// Class StationDlg
///////////////////////////////////////////////////////////////////////////////
class StationDlg : public wxDialog
{
	private:
	    //(*Handlers(StationDlg)
        void OnPaintBackground(wxPaintEvent& event);
        void OnButtonClick(wxMouseEvent& event);

        void OnPaintReport(wxPaintEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
        //*)

	protected:
	    //(*Identifiers(StationDlg)
	    static const long ID_PANEL1;             //标题
        //*)
        enum
        {
            ID_STATION_NONE,
            ID_STATION_QUIT,
            ID_STATION_COUNT
        };

        wxPanel* panelMain;
        wxPanel* stationPanel;
        wxPanel* panelBottom;

        wxPanel* stnReportPanel;

        wxRect myButton[ID_STATION_COUNT];
        int motion;

	public:
		StationDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("设站报表"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,540), long style = wxDEFAULT_DIALOG_STYLE);
		~StationDlg();

		MTG_STATION stn;
		MTG_MEASURE m;
		//(*Declarations(MySetupDialog)

        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
