#ifndef TAILSPACEDLG_H
#define TAILSPACEDLG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(TailSpaceDlg)
	#include <wx/dialog.h>
	//*)
#endif
#include "wxMyTextCtrl.h"
#include "MDButtonList.h"
#include "mtg_t_cliApp.h"
//(*Headers(TailSpaceDlg)
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
#include <wx/statline.h>
//*)

class TailSpaceDlg: public wxDialog
{
	public:

		//TailSpaceDlg(wxWindow* parent,wxWindowID id=wxID_ANY);
		TailSpaceDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("盾尾间隙"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_DIALOG_STYLE);
		virtual ~TailSpaceDlg();

		//(*Declarations(TailSpaceDlg)
		//*)

	protected:

		//(*Identifiers(TailSpaceDlg)
		//*)

	private:

		//(*Handlers(TailSpaceDlg)
        wxPanel* panelMain;
        wxPanel* panelBottom;
        wxPanel* panelPage;

	    wxPanel* panelSetting;
        wxPanel* btnLaser;
	    wxPanel* laserFig;
        wxListView* lasers;

	    wxStaticText* ipStaticText1;
	    wxStaticText* ipStaticText2;
	    wxStaticText* ipStaticText3;

	    wxMyTextCtrl* ipTxt1;
	    wxMyTextCtrl* ipTxt2;
	    wxMyTextCtrl* ipTxt3;
	    wxMyTextCtrl* ipTxt4;
	    wxMyTextCtrl* portTxt;
	    wxPanel* btnConnect;

	    wxMyTextCtrl* radiusTxt1;
	    wxMyTextCtrl* radiusTxt2;
        wxPanel* btnRadius;

        wxPanel* panelMeas;
        wxPanel* measFig;
        wxPanel* btnMeas;
        wxMyTextCtrl* gapTxt1;
	    wxMyTextCtrl* gapTxt2;
	    wxMyTextCtrl* gapTxt3;
	    wxMyTextCtrl* gapTxt4;
	    wxListView* measList;

        wxPanel* panelQuery;
        wxListView* qryList;
        wxPanel* btnQuery;

	    wxPanel* panelJust;
	    wxPanel* justFig;
        wxMyTextCtrl* measGap1;
	    wxMyTextCtrl* measGap2;
	    wxMyTextCtrl* measGap3;
	    wxMyTextCtrl* measGap4;
	    wxMyTextCtrl* justGap1;
	    wxMyTextCtrl* justGap2;
	    wxMyTextCtrl* justGap3;
	    wxMyTextCtrl* justGap4;
        wxPanel* btnJust;
		//*)
		void OnPaintMain(wxPaintEvent& event);

		void OnPaintPage(wxPaintEvent& event);
        void OnMotionPage(wxMouseEvent& event);
        void OnLeavePage(wxMouseEvent& event);
        void OnClickPage(wxMouseEvent& event);

        void OnPaintSettings(wxPaintEvent& event);
        void OnPaintQueryPage(wxPaintEvent& event);
        void OnPaintJust(wxPaintEvent& event);

        void OnPaintComm(wxPaintEvent& event);
        void OnMotionComm(wxMouseEvent& event);
        void OnLeaveComm(wxMouseEvent& event);
        void OnClickComm(wxMouseEvent& event);

        void OnPaintLaser(wxPaintEvent& event);
        void OnMotionLaser(wxMouseEvent& event);
        void OnLeaveLaser(wxMouseEvent& event);
        void OnClickLaser(wxMouseEvent& event);

        void OnPaintLaserFig(wxPaintEvent& event);
        void OnDisterActivated(wxListEvent& event);
        void OnDisterSelect(wxListEvent& event);
        void OnDisterDeselected(wxListEvent& event);

        void OnPaintDataList(wxPaintEvent& event);
        void OnPaintDataGraph(wxPaintEvent& event);
        void OnPaintJustFig(wxPaintEvent& event);

        void OnPaintMeasButton(wxPaintEvent& event);
        void OnMotionMeasButton(wxMouseEvent& event);
        void OnLeaveMeasButton(wxMouseEvent& event);
        void OnClickMeasButton(wxMouseEvent& event);

        void OnMeasSelect(wxListEvent& event);
        void OnMeasDeselected(wxListEvent& event);

        void OnPaintJustButton(wxPaintEvent& event);
        void OnMotionJustButton(wxMouseEvent& event);
        void OnLeaveJustButton(wxMouseEvent& event);
        void OnClickJustButton(wxMouseEvent& event);

        void OnPaintRadius(wxPaintEvent& event);
        void OnMotionRadius(wxMouseEvent& event);
        void OnLeaveRadius(wxMouseEvent& event);
        void OnClickRadius(wxMouseEvent& event);

        void OnPaintQuery(wxPaintEvent& event);
        void OnMotionQuery(wxMouseEvent& event);
        void OnLeaveQuery(wxMouseEvent& event);
        void OnClickQuery(wxMouseEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);

        void UpdateQuery();
        enum
        {
            ID_TG_NONE,
            ID_TG_PAGE_CONNECT,
            ID_TG_PAGE_MEAS,
            ID_TG_PAGE_QRY,
            ID_TG_PAGE_JUST,
            ID_TG_CONNECT,
            ID_TG_RADIUS,
            ID_TG_DIST_EDI,
            ID_TG_DIST_TBM,
            ID_TG_TBM_SAVE,
            ID_TG_DIST_SEG,
            ID_TG_DIST_SAVE,
            ID_TG_JUST_SAVE,
            ID_TG_QRY,
            ID_TG_EXP,
            ID_TG_BTN_QUIT,
            ID_TG_PRT_SCN,
            ID_TG_COUNT
        };

        ///界面元素
        int page;
        wxString m_msg;
        int m_msgc;

        wxRect tgButton[ID_TG_COUNT];
        int motion;
        void UpdateMeas();
        void UpdateLasers();
        void Apply();
        void LoadData();
        void WriteMsg(wxString msg,int col);

        MTG_GAPS* res;
        int nres;

        wxTimer Timer;
		void OnTimer(wxTimerEvent& event);

		DECLARE_EVENT_TABLE()
};

#endif
