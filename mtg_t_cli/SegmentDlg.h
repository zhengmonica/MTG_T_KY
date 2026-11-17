#ifndef SEGMENTDLG_H_INCLUDED
#define SEGMENTDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDButtonList.h"
#include "wxMyGrid.h"
#include "mtg_t_cliMain.h"
#include "mtg_t_cliApp.h"

//(*Headers(mtg_tFrame)
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
//*)

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MySetupDialog
///////////////////////////////////////////////////////////////////////////////
class SegmentDlg : public wxDialog
{
	private:
	    //(*Handlers(MySetupDialog)
        void OnPaintMain(wxPaintEvent& event);
        void OnPaintPage(wxPaintEvent& event);
        void OnMotionPage(wxMouseEvent& event);
        void OnLeavePage(wxMouseEvent& event);
        void OnClickPage(wxMouseEvent& event);

        void OnPaintSeging(wxPaintEvent& event);
        void OnPaintDesButton(wxPaintEvent& event);
        void OnMotionDesButton(wxMouseEvent& event);
        void OnLeaveDesButton(wxMouseEvent& event);
        void OnClickDesButton(wxMouseEvent& event);

        void OnPaintOne(wxPaintEvent& event);
        void OnMotionOne(wxMouseEvent& event);
        void OnLeaveOne(wxMouseEvent& event);
        void OnClickOne(wxMouseEvent& event);

        void OnPaintDtaHeader(wxPaintEvent& event);

        void OnPaintDtaFig(wxPaintEvent& event);
        void OnMotionDtaFig(wxMouseEvent& event);
        void OnLeaveDtaFig(wxMouseEvent& event);
        void OnClickDtaFig(wxMouseEvent& event);

        void OnPaintDeslistHeader(wxPaintEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);

        void OnDtaSelect(wxListEvent& event);
        //*)

        void WriteMsg(wxString msg,int col);
        void InitialSeging();
        void UpdateSegings();
        enum
        {
            ID_RNG_NONE,
            ID_RNG_PAGE_DONE,
            ID_RNG_PAGE_CAL,
            ID_RNG_PAGE_DES,
            ID_RNG_SEG_PRE,
            ID_RNG_SEG_GAP,
            ID_RNG_SEG_DETAIL,
            ID_RNG_SEG_KPOS,
            ID_RNG_SEG_NEXT,
            ID_RNG_SEG_AXIS,
            ID_RNG_DES_ONE,
            ID_RNG_DES_DTA,
            ID_RNG_TYPE_TL,
            ID_RNG_TYPE_TR,
            ID_RNG_TYPE_STD,
            ID_RNG_BTN_APPLY,
            ID_RNG_BTN_QUIT,
            ID_RNG_JUST_CAL,
            ID_RNG_BTN_EXP,
            ID_RNG_PRT_SCN,
            ID_SEGMENT_COUNT
        };
        wxPanel* panelMain;
        wxPanel* panelBottom;
	    wxPanel* panelPage;

        wxPanel* panelSeging;
        wxMyTextCtrl* des_mile_Text;
        wxMyTextCtrl* des_numb_Text;

        wxPanel* desbuttons;
        wxPanel* desOneText;
        wxPanel* dtaText;
        wxPanel* dtaPanel;
        wxListView* dtaList;
        wxPanel* dtaFig;
        wxMyTextCtrl* turn_Text;
        wxMyTextCtrl* std_Text;
        wxPanel* desListText;
        wxPanel* desListHeader;
        wxListView* desList;

        int motion;
        wxRect segButton[ID_SEGMENT_COUNT+100];
        int page;
        int despage;

        MTG_SEG iseg;
        MTG_SEG* res;
        int nres;

        MTG_SEG* seged;
        int nseged;

        int modified;

        int checkBoxWidth;
        int checkBoxHeight;
        int radioBoxR1;
        int radioBoxR2;

        int Mtype;
        wxString Msg;

        MTG_SEG isegs[MAX_SEG];                         ///实际排版

	protected:
	    //(*Identifiers(MySetupDialog)

        //*)

	public:
		SegmentDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("管环选型"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_DIALOG_STYLE);
		~SegmentDlg();

		void LoadData();

		//(*Declarations(MySetupDialog)

        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
