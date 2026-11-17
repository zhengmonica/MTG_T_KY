#ifndef DRIVERDLG_H_INCLUDED
#define DRIVERDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>

//(*HeadersTpsDlg)
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
/// Class DriverDlg
///////////////////////////////////////////////////////////////////////////////
class DriverDlg : public wxDialog
{
	private:
	    //(*Handlers(DriverDlg)
        void OnPaintMain(wxPaintEvent& event);

        void OnPaintList(wxPaintEvent& event);
        void OnMotionList(wxMouseEvent& event);
        void OnLeaveList(wxMouseEvent& event);
        void OnClickList(wxMouseEvent& event);

        //void OnPaintBottom(wxPaintEvent& event);
        //void OnMotionBottom(wxMouseEvent& event);
        //void OnLeaveBottom(wxMouseEvent& event);
        //void OnClickBottom(wxMouseEvent& event);
        //*)

	protected:
	    //(*Identifiers(DriverDlg)

        //*)
        enum
        {
            ID_DRV_NONE,
            ID_DRV_ONE,
            ID_DRV_TWO,
            ID_DRV_THREE,
            ID_DRV_FOUR,
            ID_DRV_QUIT,
            ID_DRV_OK,
            ID_DRV_COUNT
        };

        wxPanel* panelMain;

        wxPanel* listPanel;

        wxRect tpsButton[ID_DRV_COUNT];
        int motion;

	public:
		DriverDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("系统日志"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(150,105), long style = wxBORDER_RAISED);
		~DriverDlg();

        wxString ListItem[5];
        int ListCount;
        int drv;
        //wxListView* basketList;
		//(*Declarations(MySetupDialog)

        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
