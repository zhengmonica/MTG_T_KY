#ifndef CONFIGDLG_H_INCLUDED
#define CONFIGDLG_H_INCLUDED

#ifndef WX_PRECOMP
	//(*HeadersPCH(ConfigDialog)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/radiobox.h>
	#include <wx/textctrl.h>
	#include <wx/statbox.h>
	#include <wx/panel.h>
	#include <wx/choice.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(ConfigDialog)
#include <wx/notebook.h>
#include <wx/statline.h>
#include <wx/grid.h>
//*)
#include "mtg_t_cliApp.h"
#include "wxMyTextCtrl.h"
#include "MDButtonList.h"
#include "UserEditDlg.h"
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class ConfigDlg
///////////////////////////////////////////////////////////////////////////////
class ConfigDlg : public wxDialog
{
	private:
	    //(*Handlers(ConfigDlg)
        void OnPaintBackground(wxPaintEvent& event);
        void OnButtonClick(wxMouseEvent& event);

        void OnPaintDuty(wxPaintEvent& event);
        void OnMotionDuty(wxMouseEvent& event);
        void OnLeaveDuty(wxMouseEvent& event);
        void OnClickDuty(wxMouseEvent& event);

        void OnPaintRoad(wxPaintEvent& event);
        void OnMotionRoad(wxMouseEvent& event);
        void OnLeaveRoad(wxMouseEvent& event);
        void OnClickRoad(wxMouseEvent& event);

        void OnPaintKeyGrid(wxPaintEvent& event);

        void OnPaintKeyButton1(wxPaintEvent& event);
        void OnMotionKeyButton1(wxMouseEvent& event);
        void OnLeaveKeyButton1(wxMouseEvent& event);
        void OnClickKeyButton1(wxMouseEvent& event);

        void OnListKeyActivated(wxListEvent& event);

        void OnPaintKink(wxPaintEvent& event);
        void OnMotionKink(wxMouseEvent& event);
        void OnLeaveKink(wxMouseEvent& event);
        void OnClickKink(wxMouseEvent& event);
        void OnPaintTbmTxt(wxPaintEvent& event);

        void OnPaintTbmFig(wxPaintEvent& event);
        void OnPaintTbmajFig(wxPaintEvent& event);
        void OnPaintAjlistHeader(wxPaintEvent& event);

        void OnPaintTypeJack(wxPaintEvent& event);
        void OnMotionTypeJack(wxMouseEvent& event);
        void OnLeaveTypeJack(wxMouseEvent& event);
        void OnClickTypeJack(wxMouseEvent& event);

        void OnPaintNumTbmaj(wxPaintEvent& event);
        void OnMotionNumTbmaj(wxMouseEvent& event);
        void OnLeaveNumTbmaj(wxMouseEvent& event);
        void OnClickNumTbmaj(wxMouseEvent& event);

        void OnPaintAngTbmaj(wxPaintEvent& event);
        void OnMotionAngTbmaj(wxMouseEvent& event);
        void OnLeaveAngTbmaj(wxMouseEvent& event);
        void OnClickAngTbmaj(wxMouseEvent& event);

        void OnPaintPrismPanel(wxPaintEvent& event);

        void OnPaintTarButton(wxPaintEvent& event);
        void OnMotionTarButton(wxMouseEvent& event);
        void OnLeaveTarButton(wxMouseEvent& event);
        void OnClickTarButton(wxMouseEvent& event);

        void OnPaintTarFig(wxPaintEvent& event);
        void OnMotionTarFig(wxMouseEvent& event);
        void OnLeaveTarFig(wxMouseEvent& event);
        void OnClickTarFig(wxMouseEvent& event);

        void OnPaintLaserSet(wxPaintEvent& event);
        void OnMotionLaserSet(wxMouseEvent& event);
        void OnLeaveLaserSet(wxMouseEvent& event);
        void OnClickLaserSet(wxMouseEvent& event);

        void OnPaintLaser(wxPaintEvent& event);
        void OnMotionLaser(wxMouseEvent& event);
        void OnLeaveLaser(wxMouseEvent& event);
        void OnClickLaser(wxMouseEvent& event);

        void OnPaintSegFig(wxPaintEvent& event);
        void OnPaintSegTxt(wxPaintEvent& event);
        void OnMotionSegTxt(wxMouseEvent& event);
        void OnLeaveSegTxt(wxMouseEvent& event);
        void OnClickSegTxt(wxMouseEvent& event);

        void OnPaintBlkButton1(wxPaintEvent& event);
        void OnMotionBlkButton1(wxMouseEvent& event);
        void OnLeaveBlkButton1(wxMouseEvent& event);
        void OnClickBlkButton1(wxMouseEvent& event);

        void OnListBlockSelect(wxListEvent& event);
        void OnListBlockDeselect(wxListEvent& event);
        void OnListBlockActivated(wxListEvent& event);

        void OnListJackSelect(wxListEvent& event);
        //void OnListAjDeselect(wxListEvent& event);
        //void OnListAjActivated(wxListEvent& event);

        void OnPaintBlkFig(wxPaintEvent& event);

        void OnPaintM1Button(wxPaintEvent& event);
        void OnMotionM1Button(wxMouseEvent& event);
        void OnLeaveM1Button(wxMouseEvent& event);
        void OnClickM1Button(wxMouseEvent& event);

        void OnPaintSetTime(wxPaintEvent& event);
        void OnPaintSetDev(wxPaintEvent& event);

        void OnPaintElement(wxPaintEvent& event);
        void OnMotionElement(wxMouseEvent& event);
        void OnLeaveElement(wxMouseEvent& event);
        void OnClickElement(wxMouseEvent& event);

        void OnPaintCaution(wxPaintEvent& event);
        void OnMotionCaution(wxMouseEvent& event);
        void OnLeaveCaution(wxMouseEvent& event);
        void OnClickCaution(wxMouseEvent& event);

        void OnPaintSetFun(wxPaintEvent& event);
        void OnMotionSetFun(wxMouseEvent& event);
        void OnLeaveSetFun(wxMouseEvent& event);
        void OnClickSetFun(wxMouseEvent& event);

        void OnPaintTbmPage(wxPaintEvent& event);
        void OnMotionTbmPage(wxMouseEvent& event);
        void OnLeaveTbmPage(wxMouseEvent& event);
        void OnClickTbmPage(wxMouseEvent& event);

        void OnPaintUserButton(wxPaintEvent& event);
        void OnMotionUserButton(wxMouseEvent& event);
        void OnLeaveUserButton(wxMouseEvent& event);
        void OnClickUserButton(wxMouseEvent& event);
        void OnListUserActivated(wxListEvent& event);
        void OnPaintLanguage(wxPaintEvent& event);
        void OnMotionLanguage(wxMouseEvent& event);
        void OnLeaveLanguage(wxMouseEvent& event);
        void OnClickLanguage(wxMouseEvent& event);

        void OnPaintUserGrid(wxPaintEvent& event);

        void OnPaintBlockList(wxPaintEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
	    void OnPaintNavi(wxPaintEvent& event);

        void OnTbmD0Click(wxMouseEvent& event);
        void OnTbmD1Click(wxMouseEvent& event);
        void OnTbmD2Click(wxMouseEvent& event);
        void OnTbmD3Click(wxMouseEvent& event);
        void OnTbmD6Click(wxMouseEvent& event);
        //*)

        void OnTimer(wxTimerEvent& event);
        wxTimer timerStat;

        void ImportDB();
        void ExportDB();
        void ClearDB();
        void IsModified();

        enum
        {
            ID_FIG_NONE,               ///无
            ID_FIG_A2B,                ///正向
            ID_FIG_B2A,                ///反向
            ID_FIG_DUTY_ADD,           ///班组++
            ID_FIG_DUTY_SUB,           ///班组--
            ID_FIG_HTIP,              ///
            ID_FIG_VTIP,              ///
            ID_FIG_KEY_ADD,           ///
            ID_FIG_KEY_EDI,           ///
            ID_FIG_KEY_DEL,           ///
            ID_FIG_KINK1,             ///
            ID_FIG_KINK2,             ///
            ID_FIG_TFILE,             ///
            ID_FIG_PRISM_UP,             ///
            ID_FIG_PRISM_DOWN,             ///
            ID_FIG_PRISM_LEFT,             ///
            ID_FIG_PRISM_RIGHT,             ///
            ID_FIG_PRISM_PUP,             ///
            ID_FIG_PRISM_PDOWN,             ///
            ID_FIG_PRISM_PLEFT,             ///
            ID_FIG_PRISM_PRIGHT,             ///
            ID_FIG_TAR_POS0,             ///
            ID_FIG_TAR_POS1,             ///
            ID_FIG_TAR_POS2,             ///
            ID_FIG_LASER0,            ///
            ID_FIG_LASER1,            ///
            ID_FIG_TPS_TYPE,            ///
            ID_FIG_S2S_TYPE1,         ///
            ID_FIG_S2S_TYPE2,         ///
            ID_FIG_SEG_TYPE1,         ///
            ID_FIG_SEG_TYPE2,         ///
            ID_FIG_SEG_TYPE3,         ///
            ID_FIG_F2B_TTPE1,         ///
            ID_FIG_F2B_TTPE2,         ///
            ID_FIG_S2S_12,            ///
            ID_FIG_S2S_13,            ///
            ID_FIG_BLK_IPT,           ///
            ID_FIG_BLK_ADD,           ///
            ID_FIG_BLK_DEL,           ///
            ID_FIG_BLK_EPT,           ///
            ID_FIG_KEY_IPT,           ///
            ID_FIG_KEY_EPT,           ///
            ID_FIG_M1_MEA,            ///
            ID_FIG_M1_MEA_P1,            ///
            ID_FIG_M1_MEA_P2,            ///
            ID_FIG_M1_MEA_P3,            ///
            ID_FIG_M1_IMPORT,         ///
            ID_FIG_M1_EXPORT,         ///
            ID_FIG_REM_LOCAL,         ///
            ID_FIG_REM_REMOTE,        ///
            ID_FIG_SET_END_END,          ///
            ID_FIG_SET_END_RUN,          ///
            ID_FIG_SET_CONT,          ///
            ID_FIG_SET_TW,             ///
            ID_FIG_SET_RN1,            ///
            ID_FIG_SET_RN2,            ///
            ID_FIG_SET_RN3,            ///
            ID_FIG_SET_GAP1,
            ID_FIG_SET_GAP2,
            ID_FIG_SET_SEG_MONITOR,    ///
            ID_FIG_SET_VIBRATION_YES,      ///
            ID_FIG_SET_VIBRATION_ON,      ///
            ID_FIG_SET_SEC_RUN,            ///
            ID_FIG_SET_SEC_END,            ///
            ID_FIG_SET_SEC_SAS,            ///
            ID_FIG_SET_SEC_CHK,            ///
            ID_FIG_SET_SEC_QRY,            ///
            ID_FIG_SET_SEC_MAP,            ///
            ID_FIG_SET_SEC_SMR,            ///
            ID_FIG_SET_SEC_QUIT,           ///
            ID_FIG_UI_DEG,                 ///
            ID_FIG_UI_PER,                 ///
            ID_FIG_UI_MILEAGE0,                 ///
            ID_FIG_UI_MILEAGE1,                 ///
            ID_FIG_UI_HEADING0,            ///
            ID_FIG_UI_HEADING1,            ///
            ID_FIG_STN_ACT0,            ///
            ID_FIG_STN_ACT1,            ///
            ID_FIG_SET_VDRIVING,       ///
            ID_FIG_SET_HEAD1,          ///
            ID_FIG_SET_HEAD2,          ///
            ID_FIG_SET_FIG3D,          ///
            ID_FIG_SET_FIG2D,          ///
            ID_FIG_DEV_CAUTION,        ///
            ID_FIG_TIME_CAUTION,        ///
            ID_FIG_STN_CAUTION,        ///
            ID_FIG_INFO_ERR,        ///
            ID_FIG_DEV_C5,             ///
            ID_FIG_DEV_C6,             ///
            ID_FIG_BLK_EDI,            ///
            ID_FIG_BLK_CLEAR,          ///
            ID_FIG_USER_ADD,           ///
            ID_FIG_USER_EDI,           ///
            ID_FIG_USER_IPT,           ///
            ID_FIG_USER_DEL,           ///
            ID_FIG_USER_CLEAR,         ///
            ID_FIG_USER_EPT,           ///
            ID_FIG_USER_OK,            ///
            ID_FIG_USER_CANCEL,        ///
            ID_FIG_KEY_OK,            ///
            ID_FIG_KEY_CANCEL,        ///
            ID_FIG_BLK_OK,            ///
            ID_FIG_BLK_CANCEL,        ///
            ID_FIG_LANG_SIMP,         ///
            ID_FIG_LANG_TRAD,         ///
            ID_FIG_LANG_ENG,          ///
            ID_FIG_TPS_SET,           ///
            ID_FIG_IMPORT,            ///
            ID_FIG_EXPORT,            ///
            ID_FIG_CLEAR,             ///
            ID_FIG_APPLY,             ///
            ID_FIG_QUIT,              ///
            ID_FIG_PRJ_MILE1,            ///
            ID_FIG_PRJ_MILE2,            ///
            ID_FIG_PRJ_T10,            ///
            ID_FIG_PRJ_T11,            ///
            ID_FIG_PRJ_T12,            ///
            ID_FIG_PRJ_T13,            ///
            ID_FIG_PRJ_T20,            ///
            ID_FIG_PRJ_T21,            ///
            ID_FIG_PRJ_T22,            ///
            ID_FIG_PRJ_T23,            ///
            ID_FIG_PRJ_TIP,            ///
            ID_FIG_TBM_D0,              ///
            ID_FIG_TBM_D1,              ///
            ID_FIG_TBM_D2,              ///
            ID_FIG_TBM_D3,              ///
            ID_FIG_TBM_D4,              ///
            ID_FIG_TBM_D5,              ///
            ID_FIG_TBM_D6,              ///
            ID_FIG_TBM_L0,              ///
            ID_FIG_TBM_L1,              ///
            ID_FIG_TBM_L2,              ///
            ID_FIG_TBM_L3,              ///
            ID_FIG_TBM_L4,              ///
            ID_FIG_TBM_PAGE_GEN,        ///
            ID_FIG_TBM_PAGE_JACK,        ///
            ID_FIG_TBM_MAIN_JACK,        ///
            ID_FIG_TBM_TAIL_JACK,        ///
            ID_FIG_TBM_HEAD_JACK,        ///
            ID_FIG_TBM_ADD_JACK,        ///
            ID_FIG_TBM_SUB_JACK,        ///
            ID_FIG_TBM_SET_JACK,        ///
            ID_FIG_TAR_PRC,              ///
            ID_FIG_TPS_LASERHEIGHT,              ///
            ID_FIG_TPS_DISTANCE,              ///
            ID_FIG_TPS_X,              ///
            ID_FIG_TPS_Y,              ///
            ID_FIG_SEG_L,              ///
            ID_FIG_SEG_D,              ///
            ID_FIG_SEG_De,              ///
            ID_FIG_SEG_K,              ///
            ID_FIG_SEG_STDG,              ///
            ID_FIG_SEG_MING,              ///
            ID_FIG_SEG_L2S,              ///
            ID_FIG_SEG_S2S,              ///
            ID_FIG_BLK_NAME,              ///
            ID_FIG_BLK_ANG,              ///
            ID_FIG_SET_TIME,              ///
            ID_FIG_SET_BACK,              ///
            ID_FIG_SET_HDEV,              ///
            ID_FIG_SET_VDEV,              ///
            ID_FIG_SET_GDEV,              ///
            ID_FIG_SET_DDEV,              ///
            ID_FIG_SET_BDEV,              ///
            ID_FIG_SET_TDEV,              ///
            ID_FIG_SIM_MB,                ///
            ID_FIG_SIM_MT,                ///
            ID_FIG_SIM_CAL,               ///
            ID_FIG_SIM_SET,               ///
            ID_FIG_PRT_SCN,
            ID_FIG_COUNT
        };

        wxPanel* panelPrj;
        wxPanel* panelKey;
        wxPanel* panelTbm;
        wxPanel* panelTars;
        wxPanel* panelTps;
        wxPanel* panelSeg;
        wxPanel* panelBlock;
        wxPanel* panelM1;
        wxPanel* panelSet;
        wxPanel* panelUI;
        wxPanel* panelUser;
        wxPanel* panelLanguage;

        wxStaticText* prjStaticText1;
        wxStaticLine* prjLine1;
        wxStaticText* prjStaticText2;
        wxMyTextCtrl* prjName;
        wxStaticText* prjStaticText3;
        wxMyTextCtrl* prjMile1;
        wxStaticText* prjStaticText4;
        wxMyTextCtrl* prjMile2;
        wxStaticText* prjStaticText12;
        wxPanel* prjSoilPanel;

        wxStaticText* prjStaticText6;
        wxStaticLine* prjLine2;
        wxStaticText* prjStaticText7;
        wxPanel* prjDutyPanel;
        wxStaticText* prjStaticText8;
        wxStaticText* prjStaticText9;
        wxStaticText* prjStaticText10;
        wxStaticText* prjStaticText11;

        wxMyTextCtrl* op1Name;
        wxMyTextCtrl* op2Name;
        wxMyTextCtrl* op3Name;
        wxMyTextCtrl* op4Name;

        wxStaticText* keyStaticText1;
        wxStaticLine* keyLine1;
        wxStaticText* keyStaticText2;
        wxMyTextCtrl* keyTip;
        wxStaticText* keyStaticText3;
        wxStaticText* keyStaticText4;
        wxPanel* keyRoadPanel;
        wxStaticText* keyStaticText5;
        wxStaticLine* keyLine2;
        wxPanel* keyGridPanel;
        wxListView* keyList;
        wxPanel* keyButtonPanel;
        wxPanel* keyButton1Panel;

        wxPanel* tbmPanelPage;
        wxPanel* panelTbmgen;
        wxPanel* panelTbmJack;

        wxStaticText* tbmStaticText2;
        wxMyTextCtrl* tbmIndex;
        wxStaticText* tbmStaticText3;
        wxPanel* tbmKinkPanel;
        wxStaticText* tbmStaticText4;
        wxStaticLine* tbmLine2;
        wxPanel* tbmFigPanel;
        wxPanel* tbmTxtPanel;
        wxStaticText* tbmStaticText5;
        wxStaticText* tbmStaticText6;
        wxStaticText* tbmStaticText7;
        wxPanel* panelTypJack;
        wxPanel* panelNumJack;
        wxPanel* panelAngJack;
        wxMyTextCtrl* jackTxt;
        wxPanel* panelJackList;
        wxListView* jackList;

        wxMyTextCtrl* tbmD1;
        wxMyTextCtrl* tbmD2;
        wxMyTextCtrl* tbmD3;
        wxMyTextCtrl* tbmD4;
        wxMyTextCtrl* tbmD5;

        wxMyTextCtrl* tbmL1;
        wxMyTextCtrl* tbmL2;
        wxMyTextCtrl* tbmL3;
        wxMyTextCtrl* tbmL4;
        wxMyTextCtrl* tbmL5;
        wxMyTextCtrl* tbmL6;
        wxMyTextCtrl* tbmL7;
        wxMyTextCtrl* tbmL8;
        wxMyTextCtrl* tbmL9;

        wxPanel* panelJackfig;

        wxStaticLine* tarsLine1;
        wxStaticText* tarsStaticText2;
        wxMyTextCtrl* tarsFile;
        wxPanel* tarsButton;
        wxPanel* prismPanel;
        wxMyTextCtrl* tarsPrism;
        wxPanel* tarsFig;

        wxStaticLine* tpsLine2;
        wxPanel* tpsSetPanel;
        wxPanel* tpsFigPanel;
        wxStaticText* tpsStaticText3;
        wxMyTextCtrl* tpsLaserDist;
        wxMyTextCtrl* tpsLaserDevX;
        wxMyTextCtrl* tpsLaserDevY;

        wxStaticText* segStaticText1;
        wxStaticLine* segLine1;
        wxPanel* segFigPanel;
        wxPanel* segTxtPanel;

        wxMyTextCtrl* segL;
        wxMyTextCtrl* segD1;
        wxMyTextCtrl* segD2;
        wxMyTextCtrl* segKs;
        wxMyTextCtrl* segG0;
        wxMyTextCtrl* segG1;
        wxMyTextCtrl* segL2s;

        wxStaticText* blkStaticText1;
        wxStaticLine* blkLine1;
        wxPanel* blkListPanel;
        wxListView* blockList;
        wxPanel* blkFigPanel;

        wxPanel* blkButton1Panel;

        wxStaticText* m1StaticText1;
        wxStaticLine* m1Line1;
        wxStaticText* m1StaticText2;
        wxStaticText* m1StaticText3;
        wxMyTextCtrl* m1Head1;
        wxStaticText* m1StaticText4;
        wxMyTextCtrl* m1Head2;
        wxStaticText* m1StaticText5;
        wxMyTextCtrl* m1Head3;
        wxStaticText* m1StaticText6;
        //wxMyTextCtrl* m1Mid1;
        //wxMyTextCtrl* m1Mid2;
        //wxMyTextCtrl* m1Mid3;
        wxStaticText* m1StaticText10;
        wxMyTextCtrl* m1Tail1;
        wxMyTextCtrl* m1Tail2;
        wxMyTextCtrl* m1Tail3;

        wxStaticText* m1StaticText15;
        wxStaticText* m1StaticText7;
        wxMyTextCtrl* m1Roll;
        wxStaticText* m1StaticText16;
        wxMyTextCtrl* m1Pitch;
        wxStaticText* m1StaticText17;
        wxMyTextCtrl* m1Azi;
        wxStaticText* m1StaticText18;
        wxStaticLine* m1Line3;
        wxStaticText* m1StaticText19;
        wxStaticText* m1StaticText20;
        wxMyTextCtrl* m1Prism1;
        wxStaticText* m1StaticText21;
        wxMyTextCtrl* m1Prism2;
        wxStaticText* m1StaticText22;
        wxMyTextCtrl* m1Prism3;
        wxStaticText* m1StaticText23;
        wxStaticText* m1StaticText8;
        wxMyTextCtrl* m1Inc1;
        wxStaticText* m1StaticText24;
        wxMyTextCtrl* m1Inc2;
        wxStaticText* m1StaticText25;
        wxMyTextCtrl* m1Inc3;

        wxStaticText* m1StaticText26;
        wxStaticLine* m1Line4;
        wxStaticText* m1StaticText27;
        wxStaticText* m1StaticText28;
        wxMyTextCtrl* m1CP11;
        wxStaticText* m1StaticText29;
        wxMyTextCtrl* m1CP12;
        wxStaticText* m1StaticText30;
        wxMyTextCtrl* m1CP13;

        wxStaticText* m1StaticText31;
        wxMyTextCtrl* m1CP21;
        wxMyTextCtrl* m1CP22;
        wxMyTextCtrl* m1CP23;

        //wxStaticText* m1StaticText32;
        //wxMyTextCtrl* m1CP31;
        //wxMyTextCtrl* m1CP32;
        //wxMyTextCtrl* m1CP33;

        wxPanel* m1ButtonPanel;
        //wxPanel* m1Posision;

        wxStaticText* setStaticText1;
        wxStaticLine* setLine1;
        wxMyTextCtrl* setMeasTime;
        wxMyTextCtrl* setBackTime;
        wxPanel* setTimePanel;
        wxStaticText* setStaticText2;
        wxStaticLine* setLine2;
        wxPanel* setDevPanel;
        wxMyTextCtrl* setDev1;
        wxMyTextCtrl* setDev2;
        wxMyTextCtrl* setDev3;
        wxMyTextCtrl* setDev4;
        wxStaticText* setStaticText3;
        wxStaticLine* setLine3;
        wxPanel* funPanel;
        wxStaticLine* setLine4;

        wxStaticText* uiStaticText1;
        wxStaticLine* uiLine1;
        wxPanel* uiElementPanel;

        wxStaticText* uiStaticText2;
        wxStaticLine* uiLine2;
        wxPanel* uiCautionPanel;

        wxPanel* smOnOff;
        wxStaticLine* smLine1;
        wxStaticText* smStaticText1;
        wxMyTextCtrl* smNumber;
        wxStaticText* smStaticText2;
        wxPanel* smTimePanel;
        wxMyTextCtrl* smTime;
        wxStaticText* smStaticText3;
        wxPanel* smLastPanel;
        wxMyTextCtrl* smLast;
        wxStaticText* smStaticText4;
        wxPanel* smPosPanel;
        wxMyTextCtrl* smX;
        wxMyTextCtrl* smY;
        wxMyTextCtrl* smZ;

        wxPanel* simfig;
        wxMyTextCtrl* headh;
        wxMyTextCtrl* headv;
        wxMyTextCtrl* tailh;
        wxMyTextCtrl* tailv;
        wxPanel* simButton;

        wxPanel* userGridPanel;
        wxListView* userList;
        wxPanel* userButtonPanel;
        wxPanel* langButton;

        MTG_PRJ prj;
        MTG_KEY keys[2000];
        int nks;
        MTG_DUTY duty[4];
        int ndty;
        int onduty;
        MTG_TBM tbm;
        int jackType;
        MTG_TARGET tars;

        MTG_SEGSET segset;
        MTG_BLOCK blocks[36];
        int nblk;
        MTG_SETS measet;
        MTG_MP mp;
        MTG_USER user[50];
        wxString remIP;
        int nuser;
        MTG_MEASURE m1;
        tps_t tps;

        int motion1;
        int op1;                                ///当前click

        wxRect figButton[ID_FIG_COUNT];

        int checkBoxWidth;
        int checkBoxHeight;
        int radioBoxR1;
        int radioBoxR2;

        int tbmPage;
        //wxString exeMsg;
        //int msgType;
        wxString m_msg;
        int m_msgc;

        wxBitmap bmpTPS;
        wxBitmap bmpImportPrj;
        wxBitmap bmpExportPrj;
        wxBitmap bmpClearPrj;
        wxBitmap bmpTPS1;
        wxBitmap bmpTPS2;
        wxBitmap bmpTPS3;

        int* modified;
        int prjModified;
        int keyModified;
        int tbmModified;
        int tarsModified;
        int tpsModified;
        int segModified;
        int blockModified;
        int m1Modified;
        int settingModified;
        int userModified;
        int mpModified;
        int settingErr[20];
        char cmd[260];
        time_t t1;
        time_t t2;

        wxString ajname[10];
	protected:
	    //(*Identifiers(ConfigDlg)
	    static const long ID_PANEL2;             //按钮
	    static const long ID_BUTTON1;            //取消
        static const long ID_BUTTON2;            //应用
        //*)

	public:
		ConfigDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("系统设置"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ConfigDlg();

		void LoadDataBase();
        void UpdateBlocks();
        void UpdateKeys();
        void UpdateUsers();
        void UpdateOrigin();
        void CalMeasurement();
        void WriteMsg(wxString msg,int col);
        void Apply();
        void UpdateJack();

        int opLevel;

		//(*Declarations(ConfigDlg)
        MDButtonList* panelButtonList;          //ID_PANEL2
        wxPanel* panelMain;
        wxPanel* panelBottom;
	    wxPanel* panelNavi;
        //*)
};

#endif // CONFIGDLG_H_INCLUDED
