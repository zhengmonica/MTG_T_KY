#ifndef TAILSPACEDLG_H
#define TAILSPACEDLG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(TailSpaceDlg)
	#include <wx/dialog.h>
	//*)
#endif
#include "wxMyTextCtrl.h"
#include "MDButtonList.h"
#include "mtg_t_svrApp.h"
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
        MDButtonList* panelButtonList;          //ID_PANEL2
		//*)

	protected:

		//(*Identifiers(TailSpaceDlg)
		//*)

	private:

		//(*Handlers(TailSpaceDlg)
        wxPanel* panelMain;
        wxPanel* panelBottom;
        wxPanel* panelPage;
	    wxPanel* panelNavi;

	    wxPanel* panelComm;

	    wxStaticText* comStaticText1;
	    wxStaticText* comStaticText2;
	    wxStaticText* comStaticText4;
	    wxStaticText* comStaticText5;
	    wxStaticText* comStaticText6;


	    wxMyTextCtrl* comTextCtrl1;
	    wxMyTextCtrl* comTextCtrl2;
	    wxMyTextCtrl* comTextCtrl3;
	    wxMyTextCtrl* comTextCtrl4;
	    wxMyTextCtrl* txtPort;

	    wxPanel* panelCommtype;
	    wxChoice* comChoice1;
	    wxChoice* comChoice2;

	    wxPanel* panelAddress;
	    wxPanel* panelListTitle;
	    wxPanel* panelSetButton;
	    wxPanel* panelGraph;
	    wxPanel* panelData;
	    wxPanel* panelMeasButton;
	    wxPanel* panelDataListTitle;
	    wxPanel* panelDataGraph;

	    wxListView* panelList;
	    wxListView* panelDataList;
		//*)
		void OnPaintMain(wxPaintEvent& event);

		void OnPaintPage(wxPaintEvent& event);
        void OnMotionPage(wxMouseEvent& event);
        void OnLeavePage(wxMouseEvent& event);
        void OnClickPage(wxMouseEvent& event);

        void OnButtonClick(wxMouseEvent& event);
        void OnPaintNavi(wxPaintEvent& event);

        void OnPaintCommtype(wxPaintEvent& event);
        void OnMotionCommtype(wxMouseEvent& event);
        void OnLeaveCommtype(wxMouseEvent& event);
        void OnClickCommtype(wxMouseEvent& event);

        void OnPaintSetButton(wxPaintEvent& event);
        void OnMotionSetButton(wxMouseEvent& event);
        void OnLeaveSetButton(wxMouseEvent& event);
        void OnClickSetButton(wxMouseEvent& event);

        void OnPaintGraph(wxPaintEvent& event);
        void OnPaintList(wxPaintEvent& event);
        void OnListActivated(wxListEvent& event);

        void OnPaintDataList(wxPaintEvent& event);
        void OnPaintDataGraph(wxPaintEvent& event);

        void OnPaintMeasButton(wxPaintEvent& event);
        void OnMotionMeasButton(wxMouseEvent& event);
        void OnLeaveMeasButton(wxMouseEvent& event);
        void OnClickMeasButton(wxMouseEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);

        enum
        {
            ID_TG_NONE,
            ID_TG_PAGE_CONNECT,
            ID_TG_PAGE_ID,
            ID_TG_PAGE_GAP,
            ID_TG_COMM_SERIAL1,
            ID_TG_COMM_TCPCLI1,
            ID_FIG_DIST_ADD,
            ID_FIG_DIST_EDI,
            ID_FIG_DIST_DEL,
            ID_FIG_DIST_OBTAIN_ADDRESS,
            ID_FIG_DIST_MODIFY_ADDRESS,
            ID_FIG_DIST_MEAS_ORIGIN,
            ID_FIG_DIST_MEAS,
            ID_FIG_BTN_APPLY,
            ID_FIG_BTN_QUIT,
            ID_FIG_COUNT
        };

        ///界面元素
        int page;
        wxString m_msg;
        int m_msgc;

        wxRect tgButton[ID_FIG_COUNT];
        int motion;
        void UpdateDataList();
        void UpdateDistList();
        void Apply();
        void LoadData();
        void WriteMsg(wxString msg,int col);

        wxTimer Timer;
		void OnTimer(wxTimerEvent& event);

		DECLARE_EVENT_TABLE()
};

#endif
