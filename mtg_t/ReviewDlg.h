///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __ReviewDlg__
#define __ReviewDlg__

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "wxMyGrid.h"


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
typedef struct
{
    double l;
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
    double hd;
    double vd;
}DPoint;

class ReviewDlg : public wxDialog
{
	private:
	    //(*Handlers(MySetupDialog)
	    void OnPaintNavi(wxPaintEvent& event);
	    void OnPaintBorder1(wxPaintEvent& event);
	    void OnPaintBorder2(wxPaintEvent& event);
	    //void OnPaintBtnSys(wxPaintEvent& event);
	    void OnPaintBtnDta(wxPaintEvent& event);
	    void OnPaintBtnPst(wxPaintEvent& event);
	    void OnPaintBtnTps(wxPaintEvent& event);
        void OnPaintBtnTars(wxPaintEvent& event);
        void OnPaintBtnOp(wxPaintEvent& event);

        void OnCheckDta(wxMouseEvent& event);
        void OnEnterDta(wxMouseEvent& event);

        void OnCheckOp(wxMouseEvent& event);
        void OnEnterOp(wxMouseEvent& event);

        void OnCheckPst(wxMouseEvent& event);
        void OnEnterPst(wxMouseEvent& event);
        void OnPaintPst(wxPaintEvent& event);
        void OnPaintTps(wxPaintEvent& event);

        void OnEnterBtnTars(wxMouseEvent& event);
        void OnLeaveBtnTars(wxMouseEvent& event);
        void OnLeftDownBtnTars(wxMouseEvent& event);
        void OnBtnTarsClick(wxMouseEvent& event);
        void OnPaintTars(wxPaintEvent& event);
        void OnEnterBtnOp(wxMouseEvent& event);
        void OnLeaveBtnOp(wxMouseEvent& event);
        void OnLeftDownBtnOp(wxMouseEvent& event);
        void OnBtnOpClick(wxMouseEvent& event);
        void OnPaintOp(wxPaintEvent& event);

        void OnEnterBtnTps(wxMouseEvent& event);
        void OnLeaveBtnTps(wxMouseEvent& event);
        void OnLeftDownBtnTps(wxMouseEvent& event);
        void OnBtnTpsClick(wxMouseEvent& event);
	    void OnPaintSys(wxPaintEvent& event);
	    void OnPaintBtnArea(wxPaintEvent& event);
	    void OnPaintDta(wxPaintEvent& event);
	    void OnEnterBtnSys(wxMouseEvent& event);
        void OnLeftDownBtnSys(wxMouseEvent& event);
        void OnLeaveBtnSys(wxMouseEvent& event);
        void OnBtnSysClick(wxMouseEvent& event);
        void OnEnterBtnPst(wxMouseEvent& event);
        void OnLeaveBtnPst(wxMouseEvent& event);
        void OnLeftDownBtnPst(wxMouseEvent& event);
        void OnBtnPstClick(wxMouseEvent& event);
        void OnEnterBtnDta(wxMouseEvent& event);
        void OnLeaveBtnDta(wxMouseEvent& event);
        void OnLeftDownBtnDta(wxMouseEvent& event);
        void OnBtnDtaClick(wxMouseEvent& event);
        void OnBtnCancel(wxCommandEvent& event);
        void OnBtnQuit(wxCommandEvent& event);

        void OnEnterBtnLevel(wxMouseEvent& event);
        void OnLeaveBtnLevel(wxMouseEvent& event);
        void OnLeftDownBtnLevel(wxMouseEvent& event);
        void OnBtnLevelClick(wxMouseEvent& event);

        void OnEnterBtnPlc(wxMouseEvent& event);
        void OnLeaveBtnPlc(wxMouseEvent& event);
        void OnLeftDownBtnPlc(wxMouseEvent& event);
        void OnBtnPlcClick(wxMouseEvent& event);

        void OnPaintBtnLevel(wxPaintEvent& event);
        void OnPaintLevel(wxPaintEvent& event);
        void OnPaintBtnPlc(wxPaintEvent& event);
        void OnPaintPlc(wxPaintEvent& event);
        //*)
        int dta_btn;             ///0检查 1平面 2垂直 3>1 4>2 5>3 6>4 7>5 8>6 9>7 10>上一段 11>下一段 12>详细 -1>无
        int dta_btn_clicked;     ///0检查 1平面 2垂直 3>1 4>2 5>3 6>4 7>5 8>6 9>7 10>上一段 11>下一段 12>详细 -1>无
        int dta_type_clicked;    ///0平面 1垂直
        int btnTbmCheck;

        DPoint* dpts;
        int npts;

        //double l1_val,l2_val,l3_val,l4_val,l5_val;
        //wxString l1_str,l2_str,l3_str,l4_str,l5_str;

        //int nl[10];          ///0-4平面5-9垂直


        ///画图参数
        double x1[2],y1[2];
        double x2[2],y2[2];
        double sxy;
        double ang;
        wxBitmap m_memBit;

        ///状态
        int checked[2];
        double maxh,maxv;

        ///TBM姿态
        double hd1[3];
        double hd2[3];
        double tl1[3];
        double tl2[3];
        double* cpx1;
        double* cpy1;
        double* cpz1;
        double* cpx2;
        double* cpy2;
        double* cpz2;

        bool isPstCheck;

        int isop;                 ///0测量1后视

        int ncp;
        ///系统操作
        int psm_x,psm_y;
        int tar_x,tar_y;
        int tps_x,tps_y;


        ///提示信息
        wxString msg_str;
        wxColor  msg_cor;
	protected:
	    //(*Identifiers(MySetupDialog)
        static const long ID_PANEL1;    //主panel
	    static const long ID_PANEL2;    //导航panel
	    static const long ID_PANEL3;    //分割panel1
	    static const long ID_PANEL4;    //分割panel2
	    static const long ID_PANEL5;    //中线检查按钮
	    static const long ID_PANEL6;    //姿态检查按钮

        static const long ID_PANEL7;    //姿态页面
        static const long ID_PANEL8;    //姿态页面
        static const long ID_PANEL9;    //姿态页面
	    static const long ID_PANEL10;       //当前环管片按钮
	    static const long ID_PANEL11;       //激光靶
	    static const long ID_PANEL12;       //激光靶页面
	    static const long ID_PANEL14;          //上一环管片页面
	    static const long ID_PANEL15;                //按钮区域
	    static const long ID_PANEL16;                //操作
	    static const long ID_PANEL17;                //操作页面

	    static const long ID_PANEL20;                //设计中线页面
	    static const long ID_PANEL21;                //稳定性按钮
	    static const long ID_PANEL22;                //稳定性页面
	    static const long ID_PANEL23;                //盾构机参数按钮
	    static const long ID_PANEL24;                //盾构机参数页面


	    static const long ID_BUTTON1;                  //退出
        static const long ID_BUTTON2;                  //全站仪参数
        static const long ID_BUTTON3;                  //全站仪操作

        wxMyGrid* m_dtaGrid;                          //设计中线表

        //*)
	public:


		ReviewDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("检查"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ReviewDlg();

		void PaintGradual(wxPanel* panel, wxRect rect, int *maxColorValue,int *minColorValue,int paintStyle);
		//int LoadData();
        void InitMyGrid();

		int ReadXYZ();
		void ReadTBM();
		void LoadTBM();

		void DrawTCA(wxMemoryDC* dc,wxRect rect,double ang);
		void DrawPrism();
		void DrawTarget();
        void WriteMsg(const wxString& str,int color);
        void UpdateView();
        void CalTBM();

		///btnState
        int btnSysState;   ///0-一般状态 1-鼠标进入 2-鼠标离开 3-鼠标左键按下 4-鼠标左键弹起
        int btnPstState;
        int btnDtaState;
        int btnTpsState;
        int btnTarsState;
        int btnOpState;
        int btnLevelState;
        int btnPlcState;

        wxBitmap bmpTps;

        double prism[3];
        double back[3];
        //double head[3];
        //double tail[3];
        double headh;
        double headv;
        double tailh;
        double tailv;
        double azi;
        double pitch;
        //double roll;
        double station[3];
        bool m_bCheckPrism;
        bool m_bCheckBack;
        ///检测工作在进行
        int checking;
		//(*Declarations(MySetupDialog)
        wxPanel* panelMain;                     //panel1
	    wxPanel* panelNavi;                     //panel2
	    wxPanel* panelBorder1;                  //panel3
        wxPanel* panelBorder2;                  //panel4

        ///中线检查
        //wxPanel* panelSys;                      ///panel14
        //wxPanel* panelBtnSys;                   ///panel5
        wxPanel* panelDta;                      ///panel20
        wxPanel* panelBtnDta;                   ///panel10
        wxPanel* panelOrig;                     ///panel17
        wxPanel* panelBtnPst;                   ///panel6
        wxPanel* panelBtnArea;                  ///panel14
        wxPanel* panelPst;                      ///panel7
        wxPanel* panelBtnTps;                   ///panel8
        wxPanel* panelTps;                      ///panel9
        wxPanel* panelBtnTars;                   ///panel11
        wxPanel* panelTars;                      ///panel12
        wxPanel* panelBtnOp;                   ///panel16
        wxPanel* panelOp;                      ///panel17
        wxPanel* panelBtnLevel;                ///panel21
        wxPanel* panelLevel;                   ///panel22
        wxPanel* panelBtnPlc;                  ///panel23
        wxPanel* panelPlc;                     ///panel24

        //wxStaticText* textMsg;

        wxButton* btnCancel;               ///ID_BUTTON1
        wxButton* btnTpsGet;               ///ID_BUTTON2
        wxButton* btnTpsRun;               ///ID_BUTTON3
        //wxButton* btnTarRun;               ///ID_BUTTON3

        //*)

};

#endif //ReviewDlg
