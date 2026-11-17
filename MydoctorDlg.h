#ifndef MYDOCTORDLG_H_INCLUDED
#define MYDOCTORDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDButtonList.h"
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

        //void OnPaintSeged(wxPaintEvent& event);
        void OnPaintSegedListHeader(wxPaintEvent& event);

        void OnPaintLast(wxPaintEvent& event);
        void OnMotionLast(wxMouseEvent& event);
        void OnLeaveLast(wxMouseEvent& event);
        void OnClickLast(wxMouseEvent& event);

        void OnPaintGapText(wxPaintEvent& event);
        void OnPaintSegText(wxPaintEvent& event);

        void OnPaintSelection(wxPaintEvent& event);
        void OnMotionSelection(wxMouseEvent& event);
        void OnLeaveSelection(wxMouseEvent& event);
        void OnClickSelection(wxMouseEvent& event);

        void OnPaintSeg(wxPaintEvent& event);

        void OnPaintSegButton(wxPaintEvent& event);
        void OnMotionSegButton(wxMouseEvent& event);
        void OnLeaveSegButton(wxMouseEvent& event);
        void OnClickSegButton(wxMouseEvent& event);

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
        void OnPaintSeglistHeader(wxPaintEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);

        void OnPaintJust(wxPaintEvent& event);
        void OnMotionJust(wxMouseEvent& event);
        void OnLeaveJust(wxMouseEvent& event);
        void OnClickJust(wxMouseEvent& event);

        void OnSegSelect(wxListEvent& event);
        void OnDtaSelect(wxListEvent& event);
        //*)
        //void OnTimer(wxTimerEvent& event);
        //wxTimer timerStat;

        void WriteMsg(wxString msg,int col);
        void UpdateSegs();
        void UpdateSeged();
        void InitialPosition();
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

        wxPanel* panelSeged;
        wxPanel* segedListHeader;
        wxListView* segedList;
        wxPanel* lastSegText;
        wxMyTextCtrl* last_numb_Text;

        wxPanel* panelSeg;
        wxPanel* segbuttons;

        wxPanel* gapText;
        wxPanel* segText;
        wxPanel* selectionText;
        wxPanel* nextSegs;
        wxPanel* segListHeader;
        wxListView* segList;

        ///测试
        wxPanel* panelJust;
        wxMyTextCtrl* just_uaj_Text;
        wxMyTextCtrl* just_daj_Text;
        wxMyTextCtrl* just_laj_Text;
        wxMyTextCtrl* just_raj_Text;

        wxMyTextCtrl* just_headh_Text;
        wxMyTextCtrl* just_headv_Text;
        wxMyTextCtrl* just_tailh_Text;
        wxMyTextCtrl* just_tailv_Text;

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

        wxMyTextCtrl* tbm_lgap_Text;
        wxMyTextCtrl* tbm_rgap_Text;
        wxMyTextCtrl* tbm_ugap_Text;
        wxMyTextCtrl* tbm_dgap_Text;

        int motion;
        wxRect segButton[ID_SEGMENT_COUNT+100];
        int page;
        int segpage;
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
	    //(*Identifiers(MydoctorDlg)

        //*)

	public:
		MydoctorDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("管环选型"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_DIALOG_STYLE);
		~MydoctorDlg();

		void LoadData();

		//(*Declarations(MydoctorDlg)

        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
