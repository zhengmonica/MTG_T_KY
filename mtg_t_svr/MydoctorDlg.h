#ifndef MYDOCTORDLG_H_INCLUDED
#define MYDOCTORDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "wxMyGrid.h"
#include "mtg_t_svrMain.h"
#include "mtg_t_svrApp.h"

//(*Headers(MydoctorDlg)
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
//*)

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MydoctorDlg
///////////////////////////////////////////////////////////////////////////////
class MydoctorDlg : public wxDialog
{
	private:
	    //(*Handlers(MydoctorDlg)
        void OnPaintMain(wxPaintEvent& event);
        void OnPaintPage(wxPaintEvent& event);
        void OnMotionPage(wxMouseEvent& event);
        void OnLeavePage(wxMouseEvent& event);
        void OnClickPage(wxMouseEvent& event);
        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
        void OnPaintLaser(wxPaintEvent& event);
        void OnDoubleClickLaser(wxMouseEvent& event);
        //*)

        enum
        {
            ID_DOC_NONE,
            ID_DOC_BTN_QUIT,
            ID_DOC_BTN_EXP,
            ID_DOC_PRT_SCN,
            ID_DOC_PAGE_START,
            ID_DOC_PAGE_MAIN,
            ID_DOC_PAGE_OP,
            ID_DOC_PAGE_LASER,
            ID_DOC_COUNT
        };
        wxPanel* panelMain;
        wxPanel* panelBottom;
	    wxPanel* panelPage;
        wxListView* biList;
        wxListView* mainList;
        wxListView* opList;
        wxPanel* panelLaser;

        void LoadMessage();

        int motion;
        wxRect docButton[ID_DOC_COUNT];
        int page;
        wxString docLabel[ID_DOC_COUNT-ID_DOC_PAGE_START];

        ///测试部分
        wxImage m_img;
        wxBitmap bmpLaser;
        double speckle[2];
	protected:
	    //(*Identifiers(MydoctorDlg)

        //*)

	public:
		MydoctorDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("问题诊断"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_DIALOG_STYLE);
		~MydoctorDlg();
		//(*Declarations(MydoctorDlg)

        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
