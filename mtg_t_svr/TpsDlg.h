#ifndef TPSDLG_H_INCLUDED
#define TPSDLG_H_INCLUDED

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
/// Class TpsDlg
///////////////////////////////////////////////////////////////////////////////
class TpsDlg : public wxDialog
{
	private:
	    //(*Handlers(TpsDlg)
        void OnPaintMain(wxPaintEvent& event);
        void OnMotionMain(wxMouseEvent& event);
        void OnLeaveMain(wxMouseEvent& event);
        void OnClickMain(wxMouseEvent& event);

        void OnPaintList(wxPaintEvent& event);
        void OnMotionList(wxMouseEvent& event);
        void OnLeaveList(wxMouseEvent& event);
        void OnClickList(wxMouseEvent& event);
        void OnListTpsActivated(wxListEvent& event);
        //void OnPaintBottom(wxPaintEvent& event);
        //void OnMotionBottom(wxMouseEvent& event);
        //void OnLeaveBottom(wxMouseEvent& event);
        //void OnClickBottom(wxMouseEvent& event);
        //*)
	protected:
	    //(*Identifiers(TpsDlg)

        //*)
        enum
        {
            ID_TPS_LIST_NONE,
            ID_TPS_LIST_TPS1100,
            ID_TPS_LIST_TPS1200,
            ID_TPS_LIST_TPS15,
            ID_TPS_LIST_TPS16,
            ID_TPS_LIST_QUIT,
            ID_TPS_LIST_OK,
            ID_TPS_LIST_CANCEL,
            ID_TPS_LIST_COUNT
        };

        wxPanel* panelMain;

        //wxPanel* listPanel;
        wxListView* tpsList;

        wxRect tpsButton[ID_TPS_LIST_COUNT];
        wxString ListItem[7];
        int motion;

	public:
		TpsDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("х╚у╬рг"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(320,320), long style = wxDEFAULT_DIALOG_STYLE);
		~TpsDlg();

        //int ListCount;
        //int type;
        void SetTPS(int tps);
        int GetTPS();
        //wxListView* basketList;
		//(*Declarations(MySetupDialog)

        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
