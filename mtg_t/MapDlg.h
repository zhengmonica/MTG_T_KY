#ifndef MAPDLG_H_INCLUDED
#define MAPDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"

//(*Headers(mtg_tFrame)
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
//*)

#include "MapView.h"
//#include "DxfCanvas.h"
#define PI   3.1415926535897932384626433832795
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MapDlg
///////////////////////////////////////////////////////////////////////////////
typedef struct
{
    double x,y;
    double x1,y1;
}MapPoint;

class MapDlg : public wxDialog
{
	private:
	    //(*Handlers(MapDlg)
        void OnSize(wxSizeEvent& event);
	    void OnPaintNavi(wxPaintEvent& event);
	    void OnPaintBorder1(wxPaintEvent& event);
	    void OnPaintBorder2(wxPaintEvent& event);
	    void OnPaintBtnSet(wxPaintEvent& event);
	    void OnPaintHorizon(wxPaintEvent& event);
	    void OnPaintVertical(wxPaintEvent& event);
	    void OnPaintBtnArea(wxPaintEvent& event);

        void OnPaintSet(wxPaintEvent& event);
	    void OnEnterBtnSet(wxPaintEvent& event);
        void OnLeaveBtnSet(wxMouseEvent& event);
        void OnLeftDownBtnSet(wxMouseEvent& event);
        void OnBtnSetClick(wxMouseEvent& event);

	    void OnEnterBtnHorizon(wxPaintEvent& event);
        void OnLeaveBtnHorizon(wxMouseEvent& event);
        void OnLeftDownBtnHorizon(wxMouseEvent& event);
        void OnBtnHorizonClick(wxMouseEvent& event);

        void OnEnterBtnVertical(wxMouseEvent& event);
        void OnLeaveBtnVertical(wxPaintEvent& event);
        void OnLeftDownBtnVertical(wxMouseEvent& event);
        void OnBtnVerticalClick(wxMouseEvent& event);

        void OnBtnQuit(wxCommandEvent& event);
        //void OnBtnApply(wxCommandEvent& event);
        void OnBtnHmap(wxCommandEvent& event);
        void OnBtnVmap(wxCommandEvent& event);
        void OnEnterZoom(wxMouseEvent& event);
        void OnZoomClick(wxMouseEvent& event);
        //*)
        ///仿射变换
        MapPoint m_points[4];


        ///当前点
        int m_cur;
        ///图幅参数
        char hname[64];
        char vname[64];
        int hmaps,vmaps;
        wxImage* h_map;
        wxImage* v_map;
        int* hmapw;
        int* hmaph;
        int* vmapw;
        int* vmaph;

        int zoom;
        //void InitDXF();

	protected:
	    //(*Identifiers(ReviewDlg)
        static const long ID_PANEL1;
	    static const long ID_PANEL2;
	    static const long ID_PANEL3;
	    static const long ID_PANEL4;
	    static const long ID_PANEL5;
	    static const long ID_PANEL6;
	    static const long ID_PANEL10;
	    static const long ID_PANEL14;
	    static const long ID_PANEL15;
	    static const long ID_PANEL16;           //纵断面图

	    static const long ID_PANEL20;           //平面图


	    static const long ID_BUTTON1;           //取消
        //static const long ID_BUTTON2;           //应用
        //static const long ID_BUTTON3;           //工程
        static const long ID_BUTTON6;           //导入激光靶参数文件
        static const long ID_BUTTON7;           //测量激光靶数据

        static const long ID_STATICTEXT1;       //区间设置
        static const long ID_STATICTEXT3;       //起点里程

	    static const long ID_TEXTCTRL5;         //工程名称
	    static const long ID_TEXTCTRL12;         //激光靶参数文件
        //*)

	public:


		MapDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("地图"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_DIALOG_STYLE |wxMINIMIZE_BOX);
		~MapDlg();

		void PaintGradual(wxPanel* panel, wxRect rect, int *maxColorValue,int *minColorValue,int paintStyle);
		int GetCurPoint();
        void ReadMap();

		///btnState
        int btnSetState;   ///0-一般状态 1-鼠标进入 2-鼠标离开 3-鼠标左键按下 4-鼠标左键弹起
        int btnHorizonState;
        int btnVerticalState;


		//(*Declarations(ReviewDlg)
        wxPanel* panelMain;                     //panel1
	    wxPanel* panelNavi;                     //panel2
	    wxPanel* panelBorder1;                  //panel3
        wxPanel* panelBorder2;                  //panel4
        wxPanel* panelBtnSet;                   //panel5
        wxPanel* panelBtnHorizon;                 //panel10
        wxPanel* panelBtnVertical;              //panel6
        MapView* panelHorizon;                    //panel20
        MapView* panelVertical;                   //panel16
        wxPanel* panelSet;                       //panel14
        wxPanel* panelBtnArea;                  //panel15


        //DxfCanvas* panelVertical;
        //DxfCanvas* panelHorizon;

        wxButton* btnImportHmap;                //ID_BUTTON6
        wxButton* btnImportVmap;                   //ID_BUTTON7
        wxButton* btnCancel;                    //ID_BUTTON1
        //wxButton* btnApply;                     //ID_BUTTON2
        //wxButton* btnProj;                      //ID_BUTTON3

        wxStaticText* StaticText1;              //区间设置
        wxStaticText* StaticText3;              //起点里程

        wxMyTextCtrl* hmap_text;               //平面图文件
        wxMyTextCtrl* vmap_text;                  //纵断面图文件
        //*)
};
#endif // MAPDLG_H_INCLUDED
