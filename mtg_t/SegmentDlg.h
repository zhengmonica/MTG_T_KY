#ifndef SEGMENTDLG_H_INCLUDED
#define SEGMENTDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDTitle.h"
#include "MDButtonList.h"
#include "wxMyGrid.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"

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
        void OnPaintBackground(wxPaintEvent& event);
        void OnButtonClick(wxMouseEvent& event);

        void OnPaintFigSeg1(wxPaintEvent& event);
        void OnMotionSeg1(wxMouseEvent& event);
        void OnLeaveSeg1(wxMouseEvent& event);
        void OnClickSeg1(wxMouseEvent& event);

        void OnPaintSeging(wxPaintEvent& event);
        void OnMotionSeging(wxMouseEvent& event);
        void OnLeaveSeging(wxMouseEvent& event);
        void OnClickSeging(wxMouseEvent& event);

        void LeftajChanged(wxCommandEvent& event);
        void UpajChanged(wxCommandEvent& event);
        void RightajChanged(wxCommandEvent& event);
        void DownajChanged(wxCommandEvent& event);

        void LeftGapChanged(wxCommandEvent& event);
        void UpGapChanged(wxCommandEvent& event);
        void RightGapChanged(wxCommandEvent& event);
        void DownGapChanged(wxCommandEvent& event);
        void OnPaintSegingsListTitle(wxPaintEvent& event);

        void OnPaintFigSeg(wxPaintEvent& event);
        void OnMotionSeg(wxMouseEvent& event);
        void OnLeaveSeg(wxMouseEvent& event);
        void OnClickSeg(wxMouseEvent& event);
        void OnPaintSegsListTitle(wxPaintEvent& event);

        void OnPaintFigSeged(wxPaintEvent& event);

        void OnPaintDemo(wxPaintEvent& event);
        void OnMotionDemo(wxMouseEvent& event);
        void OnLeaveDemo(wxMouseEvent& event);
        void OnClickDemo(wxMouseEvent& event);

        void OnPaintDemoList(wxPaintEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
	    void OnPaintNavi(wxPaintEvent& event);
        //*)

        void WriteMsg(wxString msg,int col);

        enum
        {
            ID_SEGMENT_NONE,
            ID_SEGMENT_TYPE_TL,
            ID_SEGMENT_TYPE_TR,
            ID_SEGMENT_SEGH,
            ID_SEGMENT_SEGV,
            ID_SEGMENT_LASTH,
            ID_SEGMENT_LASTV,
            ID_SEGMENT_TYPE_STD,
            ID_SEGMENT_BTN_APPLY,
            ID_SEGMENT_BTN_QUIT,
            ID_SEGMENT_COUNT
        };
        wxPanel* panelSeg1;
        wxPanel* panelFigSeg1;

        wxPanel* panelSeging;
        wxPanel* panelFigSeging;
        wxMyGrid* segingGrid;
        wxMyTextCtrl* seg_dh_Text;
        wxMyTextCtrl* tbm_laj_Text;
        wxMyTextCtrl* tbm_raj_Text;
        wxMyTextCtrl* tbm_uaj_Text;
        wxMyTextCtrl* tbm_daj_Text;

        wxMyTextCtrl* tbm_lgap_Text;
        wxMyTextCtrl* tbm_rgap_Text;
        wxMyTextCtrl* tbm_ugap_Text;
        wxMyTextCtrl* tbm_dgap_Text;

        wxPanel* panelSegings;
        wxPanel* panelSegingsList;
        wxMyGrid* gridSegings;

        wxPanel* panelSeg;
        wxPanel* panelFigSeg;
        wxMyTextCtrl* seg_mile_Text;

        wxPanel* panelSegs;
        wxPanel* panelSegsList;
        wxMyGrid* gridSegs;

        wxPanel* panelSeged;
        wxPanel* panelSegedList;
        wxMyGrid* gridSeged;

        wxPanel* panelDemo;
        wxPanel* panelFigDemo;
        wxMyTextCtrl* demo_dh_Text;
        wxMyTextCtrl* demo_laj_Text;
        wxMyTextCtrl* demo_raj_Text;
        wxMyTextCtrl* demo_uaj_Text;
        wxMyTextCtrl* demo_daj_Text;

        wxMyTextCtrl* demo_lgap_Text;
        wxMyTextCtrl* demo_rgap_Text;
        wxMyTextCtrl* demo_ugap_Text;
        wxMyTextCtrl* demo_dgap_Text;

        wxMyTextCtrl* demo_headh_Text;
        wxMyTextCtrl* demo_headv_Text;
        wxMyTextCtrl* demo_tailh_Text;
        wxMyTextCtrl* demo_tailv_Text;

        wxPanel* panelDemoSegs;
        wxPanel* panelDemoList;
        wxMyGrid* gridDemo;

        int motion;
        wxRect segButton[ID_SEGMENT_COUNT+100];

        int checkBoxWidth;
        int checkBoxHeight;
        int radioBoxR1;
        int radioBoxR2;

        int Mtype;
        wxString Msg;

        MTG_SEG segings[40];                         ///实际排版
        int ns;
        int id;
        MTG_SEG segs[2500];                          ///设计排版
        int ns1;
        int id1;
        MTG_SEG demo[40];                          ///演示
        int ns2;
        int id2;
        MTG_SEG seged[2500];                         ///历史拼装
        int ns3;
        int id3;
	protected:
	    //(*Identifiers(MySetupDialog)
	    static const long ID_PANEL1;             //标题
	    static const long ID_PANEL2;             //按钮
        //*)

	public:
		SegmentDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("管环选型"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxBORDER_RAISED);
		~SegmentDlg();

		void LoadData();

		//(*Declarations(MySetupDialog)
        MDTitle* panelTitle;                    //ID_PANEL1
        MDButtonList* panelButtonList;          //ID_PANEL2
        wxPanel* panelMain;
        wxPanel* panelBottom;
	    wxPanel* panelNavi;
        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
