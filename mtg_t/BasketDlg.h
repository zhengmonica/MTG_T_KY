#ifndef BASKETDLG_H_INCLUDED
#define BASKETDLG_H_INCLUDED

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
/// Class BasketDlg
///////////////////////////////////////////////////////////////////////////////
class BasketDlg : public wxDialog
{
	private:
	    //(*Handlers(BasketDlg)
        void OnPaintBackground(wxPaintEvent& event);
        void OnButtonClick(wxMouseEvent& event);

        void OnPaintBasket(wxPaintEvent& event);
        void OnMotionBasket(wxMouseEvent& event);
        void OnLeaveBasket(wxMouseEvent& event);
        void OnClickBasket(wxMouseEvent& event);
        void OnBasketListActivated(wxListEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
        //*)

	protected:
	    //(*Identifiers(BasketDlg)
	    static const long ID_PANEL1;             //标题
        //*)
        enum
        {
            ID_BASKET_NONE,
            ID_BASKET_QUIT,
            ID_BASKET_OK,
            ID_BASKET_COUNT
        };

        wxPanel* panelMain;
        wxPanel* bskPanel;
        wxPanel* panelBottom;

        wxPanel* basketsPanel;

        wxRect bskButton[ID_BASKET_COUNT];
        int motion;

	public:
		BasketDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("系统日志"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,540), long style = wxBORDER_RAISED);
		~BasketDlg();

        wxListView* basketList;
		//(*Declarations(MySetupDialog)
        MDTitle* panelTitle;                    //ID_PANEL1
        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
