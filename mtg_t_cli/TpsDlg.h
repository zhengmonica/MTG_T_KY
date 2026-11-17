#ifndef TPSDLG_H_INCLUDED
#define TPSDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "MDTitle.h"
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
        void OnPaintBackground(wxPaintEvent& event);

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
	    //(*Identifiers(TpsDlg)
	    static const long ID_PANEL1;             //标题
        //*)
        enum
        {
            ID_TPS_LIST_NONE,
            ID_TPS_LIST_QUIT,
            ID_TPS_LIST_OK,
            ID_TPS_LIST_TPS0,
            ID_TPS_LIST_TPS1,
            ID_TPS_LIST_TPS2,
            ID_TPS_LIST_TPS3,
            ID_TPS_LIST_COUNT
        };

        wxPanel* panelMain;

        wxPanel* listPanel;

        wxRect tpsButton[ID_TPS_LIST_COUNT];
        int motion;

	public:
		TpsDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("系统日志"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(240,160), long style = wxBORDER_RAISED);
		~TpsDlg();

        wxString ListItem[4];
        int ListCount;
        int tps;
        //wxListView* basketList;
		//(*Declarations(MySetupDialog)
        MDTitle* panelTitle;                    //ID_PANEL1
        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
