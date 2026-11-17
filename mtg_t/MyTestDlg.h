#ifndef MYTESTDLG_H_INCLUDED
#define MYTESTDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/notebook.h>
#include <wx/listctrl.h>
#include "wxMyTextCtrl.h"
#include "wxMyGrid.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"

//(*Headers(MyTestDlg)
#include <wx/panel.h>
#include <wx/button.h>


//*)

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyTestDlg
///////////////////////////////////////////////////////////////////////////////
class MyTestDlg : public wxDialog
{
	private:
	    //(*Handlers(MyTestDlg)
	    //void OnPaintNavi(wxPaintEvent& event);
        void OnBtnQuit(wxCommandEvent& event);
        void OnBtnQuery(wxCommandEvent& event);
        void OnSegSelect(wxCommandEvent& event);
        //void OnEditSegnumbClick(wxCommandEvent& event);
        void OnReport( wxCommandEvent& event );
        void OnPaintSet(wxPaintEvent& event);

        void OnPaintNums(wxPaintEvent& event);

        void OnListSetsItemSelect(wxListEvent& event);

        void OnSegTop( wxCommandEvent& event );
        void OnSegPre( wxCommandEvent& event );
        void OnSegNext( wxCommandEvent& event );
        void OnSegBottom( wxCommandEvent& event );

        void OnDtsTop( wxCommandEvent& event );
        void OnDtsPre( wxCommandEvent& event );
        void OnDtsNext( wxCommandEvent& event );
        void OnDtsBottom( wxCommandEvent& event );

        void OnStart( wxCommandEvent& event );
        void OnStop( wxCommandEvent& event );
        void OnBtnV1( wxCommandEvent& event );
        void OnBtnV2( wxCommandEvent& event );
        void OnBtnV3( wxCommandEvent& event );
        void OnInitial( wxCommandEvent& event );

        void OnOrigin( wxCommandEvent& event );


        void OnTestTimer(wxTimerEvent& event);
        //*)

        ///timer
        wxTimer timerTestStat;

	protected:
	    //(*Identifiers(MyTestDlg)
        static const long ID_PANEL1;            //主panel
        static const long ID_PANEL2;            //历史数据
        static const long ID_PANEL3;            //历史数据详细
        static const long ID_PANEL4;            //设站定向
        static const long ID_PANEL5;            //设站前
        static const long ID_PANEL6;            //详细数据

        static const long ID_PANEL7;            //环号测试

	    static const long ID_BUTTON1;           //退出
	    static const long ID_BUTTON2;           //查询
	    static const long ID_BUTTON3;           //详细
	    static const long ID_BUTTON4;           //报表

	    static const long ID_BUTTON5;           //管环-顶
	    static const long ID_BUTTON6;           //管环-上
	    static const long ID_BUTTON7;           //管环-下
	    static const long ID_BUTTON8;           //管环-底
	    static const long ID_BUTTON9;           //详细-顶
	    static const long ID_BUTTON10;           //详细-上
	    static const long ID_BUTTON11;           //详细-下
	    static const long ID_BUTTON12;           //详细-底

	    static const long ID_BUTTON13;           //掘进
	    static const long ID_BUTTON14;           //停止
	    static const long ID_BUTTON15;           //速度1
	    static const long ID_BUTTON16;           //速度2
	    static const long ID_BUTTON17;           //速度3
	    static const long ID_BUTTON18;           //初始化

	    static const long ID_BUTTON19;           //零位测量

	    static const long ID_LIST1;             //设站信息表

        wxPanel* m_panelHistory;
        wxPanel* m_panelDetail;
        wxPanel* m_panelSetup;
        wxPanel* m_panelDetails;

        wxPanel* m_panelNums;

	    wxNotebook* m_notebook;
	    //wxMyGrid* m_gridHistory;

	    wxChoice* segChoice;                           //选择环号
	    //wxChoice* methodChoice;                        //查看方式
	    wxStaticText* m_staticSeg;               ///测量记录
	    //wxStaticText* m_staticSegView;                 ///查看记录
	    //wxStaticText* m_staticViewMethod;              ///查看记录
	    //wxMyTextCtrl* m_textSegView;                   ///查看记录
	    //wxMyGrid* m_gridSegData;
	    wxMyGrid* m_gridDetails;                       ///详细历史数据

        wxListView* listSets;             //设站定向列表

	    wxStaticText* m_staticFrom;
		wxMyTextCtrl* m_textFrom;
		wxStaticText* m_staticTo;
		wxMyTextCtrl* m_textTo;
		wxStaticText* m_staticMessage;

		wxMyTextCtrl* m_textSegPage;
		wxMyTextCtrl* m_textDtsPage;

        //*)
		int n1,n2;
		int nres1;
		int nres2;
		int nres3;
		//meas* res1;
		MTG_MEASURE* qres1;
		MTG_MEASURE* qres2;
		MTG_MEASURE* qres3;
		//int nqres1;
		//int nqres2;

		int seg_pages;
		int dts_pages;

		int seg_page;
		int dts_page;

        ///设站定向
        wxString m_setPath;
        int is_save_set;

        ///速度
        double ds1;
        double ds2;
        int ds3;

        //int nres1;
		//QRes* res1;

	public:


		MyTestDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("数据查询"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MyTestDlg();

        void InitMyGrid();
        void InitSegGrid();
        void InitDetailsGrid();
        void ShowResults();
        void CalRes(int n1,int n2);
        void ShowDetails();
        void UpdateSets();
        wxPanel* panelMain;                     //panel1
        wxPanel* m_panelSet;
	                  //panel27
        wxButton* btnQuit;                    //ID_BUTTON1
        wxButton* btnQuery;                    //ID_BUTTON2
        //wxButton* btnDetail;                    //ID_BUTTON3
        wxButton* btnReport;                    //ID_BUTTON4
        wxButton* btnSegTop;                    //ID_BUTTON5
        wxButton* btnSegPre;                    //ID_BUTTON6
        wxButton* btnSegNext;                    //ID_BUTTON7
        wxButton* btnSegBottom;                    //ID_BUTTON8
        wxButton* btnDtsTop;                    //ID_BUTTON9
        wxButton* btnDtsPre;                    //ID_BUTTON10
        wxButton* btnDtsNext;                    //ID_BUTTON11
        wxButton* btnDtsBottom;                    //ID_BUTTON12
        wxButton* btnStart;                       //ID_BUTTON13
        wxButton* btnStop;                        //ID_BUTTON14
        wxButton* btnV1;                        //ID_BUTTON15
        wxButton* btnV2;                        //ID_BUTTON16
        wxButton* btnV3;                        //ID_BUTTON17
        wxButton* btnInit;                        //ID_BUTTON18
        wxButton* btnOrigin;                        //ID_BUTTON19
        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
