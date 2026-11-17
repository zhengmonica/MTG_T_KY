///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MySetupDialog__
#define __MySetupDialog__

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "wxMyTextCtrl.h"
//(*Headers(MySetupDialog)
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
class MySetupDialog : public wxDialog
{
	private:
	    //(*Handlers(MySetupDialog)
        void OnBtnProj(wxCommandEvent& event);
	    void OnPaintNavi(wxPaintEvent& event);
	    void OnPaintBorder1(wxPaintEvent& event);
	    void OnPaintBorder2(wxPaintEvent& event);
	    void OnPaintBtnPrj(wxPaintEvent& event);
	    void OnPaintBtnKey(wxPaintEvent& event);
	    void OnPaintDatabase(wxPaintEvent& event);
	    void OnPaintTarget(wxPaintEvent& event);
	    void OnPaintTheodolite(wxPaintEvent& event);
	    void OnPaintOrigin(wxPaintEvent& event);
	    void OnPaintBtnTBM(wxPaintEvent& event);
	    void OnPaintMeas(wxPaintEvent& event);
	    void OnPaintUser(wxPaintEvent& event);
	    void OnPaintLanguage(wxPaintEvent& event);
	    void OnPaintPrj(wxPaintEvent& event);
	    void OnPaintKey(wxPaintEvent& event);
	    void OnPaintBtnArea(wxPaintEvent& event);
	    void OnPaintDb(wxPaintEvent& event);
	    void OnPaintPanelTarget(wxPaintEvent& event);
	    void OnPaintPanelTheo(wxPaintEvent& event);
	    void OnPaintPanelOri(wxPaintEvent& event);
	    void OnPaintPanelTBM(wxPaintEvent& event);
	    void OnPaintPanelMeas(wxPaintEvent& event);
	    void OnPaintPanelUser(wxPaintEvent& event);
	    void OnPaintPanelLang(wxPaintEvent& event);
	    void OnPaintPanelSeg(wxPaintEvent& event);
	    void OnPaintPanelBlock(wxPaintEvent& event);
	    void OnPaintSeg(wxPaintEvent& event);
	    void OnPaintBlock(wxPaintEvent& event);
	    void OnPaintGraphBlock(wxPaintEvent& event);
	    void OnPaintLasercorr(wxPaintEvent& event);

	    void OnListBlockItemActivated(wxListEvent& event);
	    void OnListBlockItemSelect(wxListEvent& event);
	    void OnListBlockItemDeselect(wxListEvent& event);

	    void OnListAreaItemActivated(wxListEvent& event);
	    void OnListAreaItemSelect(wxListEvent& event);
	    void OnListAreaItemDeselect(wxListEvent& event);

	    void OnEnterBtnPrj(wxPaintEvent& event);
        void OnLeaveBtnPrj(wxMouseEvent& event);
        void OnLeftDownBtnPrj(wxMouseEvent& event);
        void OnBtnPrjClick(wxMouseEvent& event);

        void OnEnterBtnKey(wxPaintEvent& event);
        void OnLeaveBtnKey(wxMouseEvent& event);
        void OnLeftDownBtnKey(wxMouseEvent& event);
        void OnBtnKeyClick(wxMouseEvent& event);

        void OnEnterBtnDatabase(wxMouseEvent& event);
        void OnLeaveBtnDatabase(wxPaintEvent& event);
        void OnLeftDownBtnDatabase(wxMouseEvent& event);
        void OnBtnDatabaseClick(wxMouseEvent& event);

        void OnEnterBtnTarget(wxMouseEvent& event);
        void OnLeaveBtnTarget(wxMouseEvent& event);
        void OnLeftDownBtnTarget(wxPaintEvent& event);
        void OnBtnTargetClick(wxPaintEvent& event);

        void OnEnterBtnTheodolite(wxPaintEvent& event);
        void OnLeaveBtnTheodolite(wxMouseEvent& event);
        void OnLeftDownBtnTheodolite(wxMouseEvent& event);
        void OnBtnTheodoliteClick(wxMouseEvent& event);

        void OnEnterBtnSeg(wxPaintEvent& event);
        void OnLeaveBtnSeg(wxMouseEvent& event);
        void OnLeftDownBtnSeg(wxMouseEvent& event);
        void OnBtnSegClick(wxMouseEvent& event);

        void OnEnterBtnBlock(wxPaintEvent& event);
        void OnLeaveBtnBlock(wxMouseEvent& event);
        void OnLeftDownBtnBlock(wxMouseEvent& event);
        void OnBtnBlockClick(wxMouseEvent& event);

        void OnEnterBtnOrigin(wxPaintEvent& event);
        void OnLeaveBtnOrigin(wxMouseEvent& event);
        void OnLeftDownBtnOrigin(wxMouseEvent& event);
        void OnBtnOriginClick(wxMouseEvent& event);

        void OnEnterBtnTBM(wxPaintEvent& event);
        void OnLeaveBtnTBM(wxMouseEvent& event);
        void OnLeftDownBtnTBM(wxMouseEvent& event);
        void OnBtnTBMClick(wxMouseEvent& event);

        void OnEnterBtnMeas(wxPaintEvent& event);
        void OnLeaveBtnMeas(wxMouseEvent& event);
        void OnLeftDownBtnMeas(wxMouseEvent& event);
        void OnBtnMeasClick(wxMouseEvent& event);

        void OnEnterBtnUser(wxPaintEvent& event);
        void OnLeaveBtnUser(wxMouseEvent& event);
        void OnLeftDownBtnUser(wxMouseEvent& event);
        void OnBtnUserClick(wxMouseEvent& event);

        void OnEnterBtnLanguage(wxPaintEvent& event);
        void OnLeaveBtnLanguage(wxMouseEvent& event);
        void OnLeftDownBtnLanguage(wxMouseEvent& event);
        void OnBtnLanguageClick(wxMouseEvent& event);

        void OnBtnCancel(wxCommandEvent& event);
        void OnBtnApply(wxCommandEvent& event);
        void OnBtnQuit(wxCommandEvent& event);
        void OnBrowsDB(wxCommandEvent& event);
        void OnImportTarClick(wxCommandEvent& event);

        void OnAddAreaClick(wxCommandEvent& event);
        void OnEditAreaClick(wxCommandEvent& event);
        void OnDeleAreaClick(wxCommandEvent& event);
        void OnAddBlockClick(wxCommandEvent& event);
        void OnEditBlockClick(wxCommandEvent& event);
        void OnDeleBlockClick(wxCommandEvent& event);

        ///工程界面
        //void OnDirectSelect(wxCommandEvent& event);
        void OnChangeDayh(wxCommandEvent& event);
        void OnChangeDaym(wxCommandEvent& event);
        void OnChangeNighth(wxCommandEvent& event);
        void OnChangeNightm(wxCommandEvent& event);
        void OnChangeTip(wxCommandEvent& event);
        void SetForward(wxCommandEvent& event);
        void SetReverse(wxCommandEvent& event);
        void OnPrjNameClick(wxMouseEvent& event);
        void OnChangePrjName(wxCommandEvent& event);
        void OnPrjMile1Click(wxMouseEvent& event);
        void OnChangePrjMile1(wxCommandEvent& event);
        void OnPrjMile2Click(wxMouseEvent& event);
        void OnChangePrjMile2(wxCommandEvent& event);
        void OnDayhClick(wxMouseEvent& event);
        void OnDaymClick(wxMouseEvent& event);
        void OnNighthClick(wxMouseEvent& event);
        void OnNightmClick(wxMouseEvent& event);
        void OnDayHourAddClick(wxCommandEvent& event);
        void OnDayHourSubClick(wxCommandEvent& event);
        void OnDayMinAddClick(wxCommandEvent& event);
        void OnDayMinSubClick(wxCommandEvent& event);
        void OnNightHourAddClick(wxCommandEvent& event);
        void OnNightHourSubClick(wxCommandEvent& event);
        void OnNightMinAddClick(wxCommandEvent& event);
        void OnNightMinSubClick(wxCommandEvent& event);
        ///盾构界面
        void OnTbmIndexClick(wxMouseEvent& event);
        void OnChangeTbmIndex(wxCommandEvent& event);
        void OnTbmRadiusClick(wxMouseEvent& event);
        void OnChangeTbmRadius(wxCommandEvent& event);
        void OnTbmDist1Click(wxMouseEvent& event);
        void OnChangeTbmDist1(wxCommandEvent& event);
        void OnTbmJackrClick(wxMouseEvent& event);
        void OnChangeTbmJackr(wxCommandEvent& event);
        void OnTbmDist2Click(wxMouseEvent& event);
        void OnChangeTbmDist2(wxCommandEvent& event);
        void OnTbmMidjrClick(wxMouseEvent& event);
        void OnChangeTbmMidjr(wxCommandEvent& event);
        void SetFront(wxCommandEvent& event);
        void SetBack(wxCommandEvent& event);
        void SetMnual(wxCommandEvent& event);
        void SetControlLocal(wxCommandEvent& event);
        void SetControlClient(wxCommandEvent& event);

        ///激光靶
        void OnChangePrc(wxCommandEvent& event);
        ///全站仪
        //void OnLaserSelect(wxCommandEvent& event);
        void OnChangeLaserh(wxCommandEvent& event);
        void OnChangeCorrdist(wxCommandEvent& event);
        void OnChangeCorrX(wxCommandEvent& event);
        void OnChangeCorrY(wxCommandEvent& event);
        void SetGus74Laser(wxCommandEvent& event);
        void SetCoaxLaser(wxCommandEvent& event);
        void SetUserLaser(wxCommandEvent& event);
        void OnLaserhClick(wxMouseEvent& event);
        void OnLaserdClick(wxMouseEvent& event);
        void OnLaserxClick(wxMouseEvent& event);
        void OnLaseryClick(wxMouseEvent& event);

        ///管环
        void OnSeglenClick(wxMouseEvent& event);
        void OnSegrClick(wxMouseEvent& event);
        void OnSegThickClick(wxMouseEvent& event);
        void OnSegangleClick(wxMouseEvent& event);
        void OnSegstdgapClick(wxMouseEvent& event);
        void OnSegmingapClick(wxMouseEvent& event);
        void OnSegwedgeClick(wxMouseEvent& event);
        void OnGapangleClick(wxMouseEvent& event);
        void OnMethod1Click(wxCommandEvent& event);
        void OnMethod2Click(wxCommandEvent& event);
        void OnWedge1Click(wxCommandEvent& event);
        void OnWedge2Click(wxCommandEvent& event);

        void OnChangeSeglen(wxCommandEvent& event);
        void OnChangeSegr(wxCommandEvent& event);
        void OnChangeSegthick(wxCommandEvent& event);
        void OnChangeSegangle(wxCommandEvent& event);
        void OnChangeStdSeggap(wxCommandEvent& event);
        void OnChangeMinSeggap(wxCommandEvent& event);
        void OnChangeSegWedge(wxCommandEvent& event);
        void OnChangeGapangle(wxCommandEvent& event);
        ///零位
        void OnHeadxClick(wxMouseEvent& event);
        void OnHeadyClick(wxMouseEvent& event);
        void OnHeadzClick(wxMouseEvent& event);
        void OnTailxClick(wxMouseEvent& event);
        void OnTailyClick(wxMouseEvent& event);
        void OnTailzClick(wxMouseEvent& event);
        void OnTbmrollClick(wxMouseEvent& event);
        void OnTarxClick(wxMouseEvent& event);
        void OnTaryClick(wxMouseEvent& event);
        void OnTarzClick(wxMouseEvent& event);
        void OnTaraziClick(wxMouseEvent& event);
        void OnTarpitchClick(wxMouseEvent& event);
        void OntarrollClick(wxMouseEvent& event);
        void OnMidxClick(wxMouseEvent& event);
        void OnMidyClick(wxMouseEvent& event);
        void OnMidzClick(wxMouseEvent& event);
        void OnUpmidClick(wxMouseEvent& event);
        void OnDownmidClick(wxMouseEvent& event);
        void OnLeftmidClick(wxMouseEvent& event);
        void OnRightClick(wxMouseEvent& event);
        void OnBtnMeas(wxCommandEvent& event);
        void OnChangeHeadx(wxCommandEvent& event);
        void OnChangeHeady(wxCommandEvent& event);
        void OnChangeHeadz(wxCommandEvent& event);
        void OnChangeTailx(wxCommandEvent& event);
        void OnChangeTaily(wxCommandEvent& event);
        void OnChangeTailz(wxCommandEvent& event);
        void OnChangeMidx(wxCommandEvent& event);
        void OnChangeMidy(wxCommandEvent& event);
        void OnChangeMidz(wxCommandEvent& event);
        void OnChangeTbmRoll(wxCommandEvent& event);
        void OnChangeTarX(wxCommandEvent& event);
        void OnChangeTarY(wxCommandEvent& event);
        void OnChangeTarZ(wxCommandEvent& event);
        void OnChangeTarAzi(wxCommandEvent& event);
        void OnChangeTarPitch(wxCommandEvent& event);
        void OnChangeTarRoll(wxCommandEvent& event);
        void OnChangeUmidj(wxCommandEvent& event);
        void OnChangeDmidj(wxCommandEvent& event);
        void OnChangeLmidj(wxCommandEvent& event);
        void OnChangeRmidj(wxCommandEvent& event);

        ///数据管理
        //void OnCheckedDbSave(wxCommandEvent& event);
        //void OnChangeDbpath(wxCommandEvent& event);
        //void OnBtnDbpathSet(wxCommandEvent& event);
        //void OnBtnDbpathOpen(wxCommandEvent& event);
        //void OnChangeDbtime(wxCommandEvent& event);
        //void OnChangeRppath(wxCommandEvent& event);
        //void OnBtnRppathSet(wxCommandEvent& event);
        //void OnBtnRppathOpen(wxCommandEvent& event);
        //void OnCheckedRemo(wxCommandEvent& event);
        void OnClientIP1Click(wxMouseEvent& event);
        void OnClientIP2Click(wxMouseEvent& event);
        void OnClientIP3Click(wxMouseEvent& event);
        void OnClientIP4Click(wxMouseEvent& event);
        void OnTbmIP1Click(wxMouseEvent& event);
        void OnTbmIP2Click(wxMouseEvent& event);
        void OnTbmIP3Click(wxMouseEvent& event);
        void OnTbmIP4Click(wxMouseEvent& event);
        //void OnBtnDBPathClick(wxCommandEvent& event);
        //void OnBtnReportClick(wxCommandEvent& event);
        void OnChangeClientIP1(wxCommandEvent& event);
        void OnChangeClientIP2(wxCommandEvent& event);
        void OnChangeClientIP3(wxCommandEvent& event);
        void OnChangeClientIP4(wxCommandEvent& event);
        void OnChangeTbmIP1(wxCommandEvent& event);
        void OnChangeTbmIP2(wxCommandEvent& event);
        void OnChangeTbmIP3(wxCommandEvent& event);
        void OnChangeTbmIP4(wxCommandEvent& event);
        ///测量设置
        void OnMeastime1Click(wxMouseEvent& event);
        void OnMeastime2Click(wxMouseEvent& event);
        void OnHoridiffClick(wxMouseEvent& event);
        void OnVerdiffClick(wxMouseEvent& event);
        void OnAnglediffClick(wxMouseEvent& event);
        void OnDiffchangeClick(wxMouseEvent& event);
        void OnBackdiffClick(wxMouseEvent& event);
        void OnToltimeClcik(wxMouseEvent& event);
        void OnCorrdistClick(wxMouseEvent& event);
        void OnCorrdiffClick(wxMouseEvent& event);

        void OnChangeMeasTime(wxCommandEvent& event);
        void OnChangeBackTime(wxCommandEvent& event);
        void OnChangeHtol(wxCommandEvent& event);
        void OnChangeVtol(wxCommandEvent& event);
        void OnChangeGtol(wxCommandEvent& event);
        void OnChangeDtol(wxCommandEvent& event);
        void OnChangeBtol(wxCommandEvent& event);
        void OnChangeDist(wxCommandEvent& event);
        void OnChangeCorrtol(wxCommandEvent& event);
        void OnChangeToltime(wxCommandEvent& event);
        ///用户权限
        //void OnChangeMOP(wxCommandEvent& event);
        //void OnChangeMNP(wxCommandEvent& event);
        //void OnChangeMPC(wxCommandEvent& event);
        //void OnChangeOOP(wxCommandEvent& event);
        //void OnChangeONP(wxCommandEvent& event);
        //void OnChangeOPC(wxCommandEvent& event);
        void OnBtnAddUserClick(wxCommandEvent& event);
        void OnBtnDelUserClick(wxCommandEvent& event);
        void OnBtnEditUserClick(wxCommandEvent& event);
        void OnListUserItemActivated(wxListEvent& event);
	    void OnListUserItemSelect(wxListEvent& event);
	    void OnListUserItemDeselect(wxListEvent& event);
	    ///语言设置
	    //void OnLangSelect(wxCommandEvent& event);
	    void SetLang1(wxCommandEvent& event);
	    void SetLang2(wxCommandEvent& event);
	    void SetLang3(wxCommandEvent& event);
        //*)

        void OnMenuClean(wxCommandEvent& event);
		void OnMenuBackup(wxCommandEvent& event);
		void OnMenuRestore(wxCommandEvent& event);

		void CalHead();
		void CalTail();

	protected:
	    //(*Identifiers(MySetupDialog)
        static const long ID_PANEL1;
	    static const long ID_PANEL2;
	    static const long ID_PANEL3;
	    static const long ID_PANEL4;
	    static const long ID_PANEL5;
	    static const long ID_PANEL6;
	    static const long ID_PANEL7;
	    static const long ID_PANEL8;
	    static const long ID_PANEL9;
	    static const long ID_PANEL10;
	    static const long ID_PANEL11;
	    static const long ID_PANEL12;
	    static const long ID_PANEL13;
	    static const long ID_PANEL14;
	    static const long ID_PANEL15;
	    static const long ID_PANEL16;           //数据库设置
	    static const long ID_PANEL17;           //数据库设置
	    static const long ID_PANEL18;           //全站仪设置
	    static const long ID_PANEL19;           //零位数据设置
	    static const long ID_PANEL20;           //铰接设置
	    static const long ID_PANEL21;           //测量设置
	    static const long ID_PANEL22;           //用户权限
	    static const long ID_PANEL23;           //语言设置
	    static const long ID_PANEL24;           //管片设置
	    static const long ID_PANEL25;           //管片页面按钮
	    static const long ID_PANEL26;           //管块页面按钮
	    static const long ID_PANEL27;           //管块页面
	    static const long ID_PANEL28;           //管块图
	    static const long ID_PANEL29;           //激光校正图
	    static const long ID_PANEL30;           //关键区域按钮
	    static const long ID_PANEL31;           //关键区域页面

	    static const long ID_BUTTON1;           //取消
        static const long ID_BUTTON2;           //应用
        static const long ID_BUTTON3;           //工程
        //static const long ID_BUTTON4;           //浏览
        static const long ID_BUTTON5;           //打开文件夹
        static const long ID_BUTTON6;           //导入激光靶参数文件
        static const long ID_BUTTON7;           //测量激光靶数据
        static const long ID_BUTTON8;           //测量激光靶数据
        static const long ID_BUTTON9;           //添加管片
        static const long ID_BUTTON10;           //编辑管片
        static const long ID_BUTTON11;           //删除管片
        static const long ID_BUTTON12;           //添加管块
        static const long ID_BUTTON13;           //删除管块
        static const long ID_BUTTON14;           //增加关键区域
        static const long ID_BUTTON15;           //编辑关键区域
        static const long ID_BUTTON16;           //删除关键区域
        static const long ID_BUTTON17;           //添加用户
        static const long ID_BUTTON18;           //编辑用户
        static const long ID_BUTTON19;           //删除用户
        static const long ID_BUTTON20;           //小时+1
        static const long ID_BUTTON21;           //小时+2
        static const long ID_BUTTON22;           //小时+3
        static const long ID_BUTTON23;           //小时+4
        static const long ID_BUTTON24;           //小时+5
        static const long ID_BUTTON25;           //小时+6
        static const long ID_BUTTON26;           //小时+7
        static const long ID_BUTTON27;           //小时+8
        static const long ID_BUTTON28;           //数据库备份路径
        static const long ID_BUTTON29;           //报表存储路径

        static const long ID_STATICTEXT1;       //区间设置
        static const long ID_STATICTEXT2;       //管片编号
        static const long ID_STATICTEXT3;       //起点里程
        static const long ID_STATICTEXT4;       //终点里程
        static const long ID_STATICTEXT5;       //管片长度
        static const long ID_STATICTEXT6;       //管片参数
        static const long ID_STATICTEXT7;       //管片至切口距离
        static const long ID_STATICTEXT8;       //工程信息
        static const long ID_STATICTEXT9;       //项目名称
        static const long ID_STATICTEXT10;       //建设单位
        static const long ID_STATICTEXT11;       //项目经理
        static const long ID_STATICTEXT12;       //开工日期
        static const long ID_STATICTEXT13;       //工程备注
        static const long ID_STATICTEXT14;       //值班设置
        static const long ID_STATICTEXT15;       //白班值班时间
        static const long ID_STATICTEXT16;       //夜班上班时间
        static const long ID_STATICTEXT17;       //数据库自动备份时间单位
        static const long ID_STATICTEXT18;       //激光靶配置文件
        static const long ID_STATICTEXT19;       //激光靶棱镜常数
        static const long ID_STATICTEXT20;       //激光靶棱镜常数单位
        static const long ID_STATICTEXT21;       //激光靶棱镜位置
        static const long ID_STATICTEXT22;       //全站仪激光类型
        static const long ID_STATICTEXT23;       //视准轴至激光高度
        static const long ID_STATICTEXT24;       //视准轴至激光高度单位
        static const long ID_STATICTEXT25;       //激光修正
        static const long ID_STATICTEXT26;       //修正距离
        static const long ID_STATICTEXT27;       //横向修正
        static const long ID_STATICTEXT28;       //垂直修正
        static const long ID_STATICTEXT29;       //修正距离单位
        static const long ID_STATICTEXT30;       //横向修正单位
        static const long ID_STATICTEXT31;       //垂直修正单位
        static const long ID_STATICTEXT32;       //盾构初始位置
        static const long ID_STATICTEXT33;       //切口
        static const long ID_STATICTEXT34;       //盾尾
        static const long ID_STATICTEXT35;       //滚动角
        static const long ID_STATICTEXT36;       //盾构机初始铰接数据
        static const long ID_STATICTEXT37;       //铰接1
        static const long ID_STATICTEXT38;       //铰接2
        static const long ID_STATICTEXT39;       //激光靶初始位置
        static const long ID_STATICTEXT40;       //棱镜
        static const long ID_STATICTEXT41;       //后屏
        static const long ID_STATICTEXT42;       //前屏
        static const long ID_STATICTEXT43;       //激光
        static const long ID_STATICTEXT44;       //姿态
        static const long ID_STATICTEXT45;       //铰接1设置
        static const long ID_STATICTEXT46;       //铰接1至刀盘距离
        static const long ID_STATICTEXT47;       //姿态测量
        static const long ID_STATICTEXT48;       //后视检核
        static const long ID_STATICTEXT49;       //测量限差
        static const long ID_STATICTEXT50;       //平面偏差限差
        static const long ID_STATICTEXT51;       //高程偏差限差
        static const long ID_STATICTEXT52;       //姿态偏差限差
        static const long ID_STATICTEXT53;       //偏差变化
        static const long ID_STATICTEXT54;       //后视检核限差
        static const long ID_STATICTEXT55;       //偏差超限
        static const long ID_STATICTEXT56;       //偏差变化超限
        static const long ID_STATICTEXT57;       //后视检核超限
        static const long ID_STATICTEXT58;       //管理员
        static const long ID_STATICTEXT59;       //操作员
        static const long ID_STATICTEXT60;       //系统语言
        static const long ID_STATICTEXT61;       //盾首偏移油缸
        static const long ID_STATICTEXT62;       //盾尾铰接油缸
        static const long ID_STATICTEXT63;       //推进油缸
        static const long ID_STATICTEXT64;       //掘进方向
        static const long ID_STATICTEXT65;       //拼装方式
        static const long ID_STATICTEXT66;       //楔形量
        static const long ID_STATICTEXT67;       //楔形类型
        static const long ID_STATICTEXT68;       //楔形量
        static const long ID_STATICTEXT69;       //管块示意
        static const long ID_STATICTEXT70;       //X
        static const long ID_STATICTEXT71;       //Y
        static const long ID_STATICTEXT72;       //Z
        static const long ID_STATICTEXT73;       //盾尾位置
        static const long ID_STATICTEXT74;       //X
        static const long ID_STATICTEXT75;       //Y
        static const long ID_STATICTEXT76;       //Z
        static const long ID_STATICTEXT77;       //纠偏设置
        static const long ID_STATICTEXT78;       //纠偏距离
        static const long ID_STATICTEXT79;       //每环管片盾构姿态纠偏偏差
        static const long ID_STATICTEXT80;       //纠偏不符值
        static const long ID_STATICTEXT81;       //标准盾尾间隙
        static const long ID_STATICTEXT82;       //最小盾构间隙
        static const long ID_STATICTEXT83;       //盾尾内径
        static const long ID_STATICTEXT84;       //备注
        static const long ID_STATICTEXT85;       //数据共享
        static const long ID_STATICTEXT86;       //远程监控IP
        static const long ID_STATICTEXT87;       //盾构机IP
        static const long ID_STATICTEXT88;       //提示范围
        static const long ID_STATICTEXT89;       //提示范围
        static const long ID_STATICTEXT90;       //盾构PLC IP地址
        static const long ID_STATICTEXT91;       //错缝条件
        static const long ID_STATICTEXT92;       //错缝条件
        static const long ID_STATICTEXT93;       //推进油缸
        static const long ID_STATICTEXT94;       //推进油缸直径
        static const long ID_STATICTEXT95;       //盾尾铰接油缸
        static const long ID_STATICTEXT96;       //盾尾铰接油缸直径
        static const long ID_STATICTEXT97;       //盾首偏移油缸
        static const long ID_STATICTEXT98;       //盾首偏移油缸直径
        static const long ID_STATICTEXT99;       //激光靶参数设置
        static const long ID_STATICTEXT100;       //激光类型
        static const long ID_STATICTEXT101;       //铰接位置
        static const long ID_STATICTEXT102;       //铰接X
        static const long ID_STATICTEXT103;       //铰接Y
        static const long ID_STATICTEXT104;       //铰接Z
        static const long ID_STATICTEXT105;       //盾构姿态
        static const long ID_STATICTEXT106;       //俯仰角
        static const long ID_STATICTEXT107;       //方位角
        static const long ID_STATICTEXT108;       //铰接油缸设置
        static const long ID_STATICTEXT109;       //铰接油缸：上
        static const long ID_STATICTEXT110;       //铰接油缸：下
        static const long ID_STATICTEXT111;       //铰接油缸：左
        static const long ID_STATICTEXT112;       //铰接油缸：右
        static const long ID_STATICTEXT113;       //油缸直径示意图
        static const long ID_STATICTEXT114;       //时间符号
        static const long ID_STATICTEXT115;       //时间符号
        static const long ID_STATICTEXT116;       //盾构机IP
        static const long ID_STATICTEXT117;       //远程电脑IP
        static const long ID_STATICTEXT118;       //地址分隔符
        static const long ID_STATICTEXT119;       //地址分隔符
        static const long ID_STATICTEXT120;       //地址分隔符
        static const long ID_STATICTEXT121;       //上组铰接油缸
        static const long ID_STATICTEXT122;       //下组铰接油缸
        static const long ID_STATICTEXT123;       //左组铰接油缸
        static const long ID_STATICTEXT124;       //右组铰接油缸

	    static const long ID_TEXTCTRL1;         //起点里程
	    static const long ID_TEXTCTRL2;         //终点里程
	    static const long ID_TEXTCTRL3;         //管片长度
	    static const long ID_TEXTCTRL4;         //管片至切口距离
	    static const long ID_TEXTCTRL5;         //工程名称
	    static const long ID_TEXTCTRL6;         //建设单位
	    static const long ID_TEXTCTRL7;         //项目经理
	    static const long ID_TEXTCTRL8;         //开工日期
	    static const long ID_TEXTCTRL9;         //工程备注

	    static const long ID_TEXTCTRL10;         //白班值班时间
	    static const long ID_TEXTCTRL11;         //夜班上班时间
	    static const long ID_TEXTCTRL12;         //激光靶参数文件
	    static const long ID_TEXTCTRL13;         //激光靶棱镜常数
	    static const long ID_TEXTCTRL14;         //视准轴至激光高度
	    static const long ID_TEXTCTRL15;         //校正距离
	    static const long ID_TEXTCTRL16;         //横向校正
	    static const long ID_TEXTCTRL17;         //垂直校正
	    static const long ID_TEXTCTRL18;         //切口X
	    static const long ID_TEXTCTRL19;         //切口Y
	    static const long ID_TEXTCTRL20;         //切口Z
	    static const long ID_TEXTCTRL21;         //盾尾X
	    static const long ID_TEXTCTRL22;         //盾尾Y
	    static const long ID_TEXTCTRL23;         //盾尾Z
	    static const long ID_TEXTCTRL24;         //滚动角
	    static const long ID_TEXTCTRL25;         //铰接1H
	    static const long ID_TEXTCTRL26;         //铰接1V
	    static const long ID_TEXTCTRL27;         //铰接2H
	    static const long ID_TEXTCTRL28;         //铰接2V
	    static const long ID_TEXTCTRL29;         //激光靶棱镜X
	    static const long ID_TEXTCTRL30;         //激光靶棱镜Y
	    static const long ID_TEXTCTRL31;         //激光靶棱镜Z
	    static const long ID_TEXTCTRL32;         //后屏X
	    static const long ID_TEXTCTRL33;         //后屏Y
	    static const long ID_TEXTCTRL34;         //前屏X
	    static const long ID_TEXTCTRL35;         //前屏Y
	    static const long ID_TEXTCTRL36;         //激光束水平角
	    static const long ID_TEXTCTRL37;         //激光束竖直角
	    static const long ID_TEXTCTRL38;         //激光靶转动角
	    static const long ID_TEXTCTRL39;         //激光靶俯仰角
	    static const long ID_TEXTCTRL40;         //高程偏差限差
	    static const long ID_TEXTCTRL41;         //姿态偏差
	    static const long ID_TEXTCTRL42;         //偏差变化
	    static const long ID_TEXTCTRL43;         //后视检核限差
	    static const long ID_TEXTCTRL44;         //管理员
	    static const long ID_TEXTCTRL45;         //操作员
	    static const long ID_TEXTCTRL46;         //盾构编号
	    static const long ID_TEXTCTRL47;         //盾首偏移油缸
	    static const long ID_TEXTCTRL48;         //管片厚度
	    static const long ID_TEXTCTRL49;         //管片厚度
	    static const long ID_TEXTCTRL50;         //通用环楔形量
	    static const long ID_TEXTCTRL51;         //标准环楔形类型
	    static const long ID_TEXTCTRL52;         //标准化楔形量
	    static const long ID_TEXTCTRL53;         //切口x
	    static const long ID_TEXTCTRL54;         //切口y
	    static const long ID_TEXTCTRL55;         //切口z
	    static const long ID_TEXTCTRL56;         //盾尾X
	    static const long ID_TEXTCTRL57;         //盾尾Y
	    static const long ID_TEXTCTRL58;         //盾尾Z
	    static const long ID_TEXTCTRL59;         //纠偏距离
	    static const long ID_TEXTCTRL60;         //纠偏偏差
	    static const long ID_TEXTCTRL61;         //纠偏不符值
	    static const long ID_TEXTCTRL62;         //标准盾尾间隙
	    static const long ID_TEXTCTRL63;         //最小盾尾间隙
	    static const long ID_TEXTCTRL64;         //盾尾内径
	    static const long ID_TEXTCTRL65;         //远程IP
	    static const long ID_TEXTCTRL66;         //盾构IP
	    static const long ID_TEXTCTRL67;         //错缝角度
	    static const long ID_TEXTCTRL91;         //测量时间间隔
	    static const long ID_TEXTCTRL92;         //白班时间
	    static const long ID_TEXTCTRL93;         //白班时间
	    static const long ID_TEXTCTRL94;         //夜班时间
	    static const long ID_TEXTCTRL95;         //夜班时间
	    static const long ID_TEXTCTRL96;         //推进油缸直径
	    static const long ID_TEXTCTRL97;         //盾尾铰接油缸直径
	    static const long ID_TEXTCTRL98;         //盾首偏移油缸直径
        static const long ID_TEXTCTRL99;         //铰接X
        static const long ID_TEXTCTRL100;         //铰接Y
        static const long ID_TEXTCTRL101;         //铰接Z
        static const long ID_TEXTCTRL102;         //俯仰角
        static const long ID_TEXTCTRL103;         //方位角
        static const long ID_TEXTCTRL104;         //铰接油缸：上
        static const long ID_TEXTCTRL105;         //铰接油缸：下
        static const long ID_TEXTCTRL106;         //铰接油缸：左
        static const long ID_TEXTCTRL107;         //铰接油缸：右
        static const long ID_TEXTCTRL108;         //报表存储路径
        static const long ID_TEXTCTRL109;         //数据库备份路径
        static const long ID_TEXTCTRL110;         //IP地址2
        static const long ID_TEXTCTRL111;         //IP地址3
        static const long ID_TEXTCTRL112;         //IP地址4
        static const long ID_TEXTCTRL113;         //IP地址2
        static const long ID_TEXTCTRL114;         //IP地址3
        static const long ID_TEXTCTRL115;         //IP地址4
        static const long ID_TEXTCTRL116;         //上组油缸
        static const long ID_TEXTCTRL117;         //下组油缸
        static const long ID_TEXTCTRL118;         //左组油缸
        static const long ID_TEXTCTRL119;         //右组油缸

        static const long ID_CHECKBOX1;          //数据库自动备份
        static const long ID_CHECKBOX10;         //推进油缸
        static const long ID_CHECKBOX11;         //盾尾铰接油缸
        static const long ID_CHECKBOX12;         //盾首偏移油缸
        //static const long ID_CHECKBOX13;       //启用远程监控
        static const long ID_CHECKBOX14;         //向盾构plc写数据
        static const long ID_CHECKBOX15;         //向盾构plc读数据
        static const long ID_CHECKBOX16;         //小里程至大里程
        static const long ID_CHECKBOX17;         //大里程至小里程
        static const long ID_CHECKBOX18;         //GUS74激光
        static const long ID_CHECKBOX19;         //同轴激光
        static const long ID_CHECKBOX20;         //自定义激光
        static const long ID_CHECKBOX21;         //通用环
        static const long ID_CHECKBOX22;         //标准环+转弯环
        static const long ID_CHECKBOX23;         //等腰梯形
        static const long ID_CHECKBOX24;         //直角梯形
        static const long ID_CHECKBOX25;         //简体中文
        static const long ID_CHECKBOX26;         //英语
        static const long ID_CHECKBOX27;         //繁体中文
        static const long ID_CHECKBOX28;         //前铰接
        static const long ID_CHECKBOX29;         //后铰接

        static const long ID_CHECKBOX30;         //控制模式1
        static const long ID_CHECKBOX31;         //控制模式2
        static const long ID_CHECKBOX32;         //铰接数据

	    static const long ID_RADIOBUTTON1;      //管片号增加方法一
	    static const long ID_RADIOBUTTON2;      //管片号增加方法一
	    static const long ID_RADIOBUTTON3;      //管片号增加方法一
	    static const long ID_RADIOBUTTON4;      //激光靶下侧中间
	    static const long ID_RADIOBUTTON5;      //激光靶上侧中间
	    static const long ID_RADIOBUTTON6;      //激光靶右侧中间
	    static const long ID_RADIOBUTTON7;      //激光靶左侧中间
	    static const long ID_RADIOBUTTON8;      //激光类型：指示激光
	    static const long ID_RADIOBUTTON9;      //激光类型：GUS74
	    static const long ID_RADIOBUTTON10;     //激光类型：用户自定义
	    static const long ID_RADIOBUTTON11;      //简体中文
	    static const long ID_RADIOBUTTON12;      //繁体中文
	    static const long ID_RADIOBUTTON13;      //英文
	    //static const long ID_RADIOBUTTON14;      //小里程至大里程
	    //static const long ID_RADIOBUTTON15;      //大里程至小里程
	    static const long ID_RADIOBUTTON16;      //通用环
	    static const long ID_RADIOBUTTON17;      //标准环+转弯环

	    //static const long ID_CHOICE1;            //掘进方向
	    //static const long ID_CHOICE2;            //激光选择
	    static const long ID_CHOICE3;            //激光选择
	    static const long ID_CHOICE4;            //激光选择
	    static const long ID_CHOICE5;            //语言选择

	    static const long ID_LIST1;              //管块参数列表
	    static const long ID_LIST2;              //关键区域
	    static const long ID_LIST3;              //用户列表
        //*)

	public:


		MySetupDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("设置"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MySetupDialog();

		void PaintGradual(wxPanel* panel, wxRect rect, int *maxColorValue,int *minColorValue,int paintStyle);

        void LoadDatabase();
        void WriteMsg(const wxString& str,int color=0);
        ///更新列表
        void UpdateBlock();
        void UpdateArea();
        void UpdateUser();
        ///ip地址
        void Sortip();
        ///布局
        void LayoutOrign();
        void LayoutPrj();
        void LayoutTar();
        void LayoutMea();
        void LayoutSeg();
        void LayoutTheo();
        void LayoutDB();
        void LayoutTBM();
        void LayoutKeyArea();
        void LayoutUser();
        void LayoutLang();
        ///远程IP
        wxString clientip1;
        wxString clientip2;
        wxString clientip3;
        wxString clientip4;
        ///盾构IP
        wxString tbmip1;
        wxString tbmip2;
        wxString tbmip3;
        wxString tbmip4;
		///btnState
        int btnPrjState;   ///0-一般状态 1-鼠标进入 2-鼠标离开 3-鼠标左键按下 4-鼠标左键弹起
        int btnDatabaseState;
        int btnTargetState;
        int btnTheodoliteState;
        int btnOriginState;
        int btnTBMState;
        int btnMeasState;
        int btnUserState;
        int btnLanguageState;
        int btnSegState;
        int btnBlockState;
        int btnKeyState;

        int blockSelect;
        int areaSelect;
        int userSelect;

        bool m_bModifyPrj;
        bool m_bModifyTbm;
        bool m_bModifyTps;
        bool m_bModifyTar;
        bool m_bModifySeg;
        bool m_bModifyOrigin;
        bool m_bModifyData;
		bool m_bModifyMea;
		bool m_bModifyAdmin;
		bool m_bModifyDriver;
		bool m_bModifyJiaojie;
		bool m_bModifyLang;

        ///
        double tarX1;
        double tarY1;
        double tarX2;
        double tarY2;
        double laserAngle1;
        double laserAngle2;
        ///文本框输入
        int prjset;
        int tbmset;
        int tarsset;
        int tpsset;
        int segset;
        int origset;
        int dataset;
        int measet;
        int langset;
        ///提示信息
        wxString msg_str;
        wxColor  msg_cor;
		//(*Declarations(MySetupDialog)
        wxPanel* panelMain;                     //panel1
	    wxPanel* panelNavi;                     //panel2
	    wxPanel* panelBorder1;                  //panel3
        wxPanel* panelBorder2;                  //panel4
        wxPanel* panelBtnPrj;                   //panel5
        wxPanel* panelBtnDatabase;              //panel6
        wxPanel* panelBtnTarget;                //panel7
        wxPanel* panelBtnTheodolite;            //panel8
        wxPanel* panelBtnOrigin;                //panel9
        wxPanel* panelBtnTBM;                 //panel10
        wxPanel* panelBtnMeas;                  //panel11
        wxPanel* panelBtnUser;                  //panel12
        wxPanel* panelBtnLanguage;              //panel13
        wxPanel* panelBtnSeg;                   //panel25
        wxPanel* panelPrj;                      //panel14
        wxPanel* panelBtnArea;                  //panel14
        wxPanel* panelDb;                       //panel16
        wxPanel* panelTarget;                   //panel17
        wxPanel* panelTheo;                     //panel18
        wxPanel* panelOri;                      //panel19
        wxPanel* panelTBM;                    //panel20
        wxPanel* panelMeas;                     //panel21
        wxPanel* panelUser;                     //panel22
        wxPanel* panelLang;                     //panel23
        wxPanel* panelSeg;                      //panel24
        wxPanel* panelBtnBlock;                      //panel26
        wxPanel* panelBlock;                      //panel27
        wxPanel* GraphBlock;                      //panel28
        wxPanel* panelLasercorr;                      //panel28
        wxPanel* panelKey;                           //panel31
        wxPanel* panelBtnKey;                      //panel30

        wxButton* btnCancel;                    //ID_BUTTON1
        wxButton* btnApply;                     //ID_BUTTON2
        wxButton* btnProj;                      //ID_BUTTON3
        //wxButton* btnBrowse;                    //ID_BUTTON4
        //wxButton* btnOpenFolder;                //ID_BUTTON5
        wxButton* btnImportPara;                //ID_BUTTON6
        wxButton* btnTarMeas;                   //ID_BUTTON7
        wxButton* btnAddBlock;                    //ID_BUTTON8
        wxButton* btnAddSeg;                    //ID_BUTTON9
        wxButton* btnEditSeg;                    //ID_BUTTON10
        wxButton* btnDelSeg;                    //ID_BUTTON11
        wxButton* btnEditBlock;                    //ID_BUTTON12
        wxButton* btnDelBlock;                    //ID_BUTTON13
        wxButton* btnAddArea;                    //ID_BUTTON14
        wxButton* btnEditArea;                    //ID_BUTTON15
        wxButton* btnDelArea;                     //ID_BUTTON16
        wxButton* btnAddUser;                     //ID_BUTTON17
        wxButton* btnEditUser;                     //ID_BUTTON18
        wxButton* btnDelUser;                     //ID_BUTTON19
        wxButton* btnAddDayh;                     //时间+1
        wxButton* btnSubDayh;                     //时间+2
        wxButton* btnAddDaym;                     //时间+3
        wxButton* btnSubDaym;                     //时间+4
        wxButton* btnAddNighth;                     //时间+5
        wxButton* btnSubNighth;                     //时间+6
        wxButton* btnAddNightm;                     //时间+7
        wxButton* btnSubNightm;                     //时间+8
        wxButton* btnDbPath;                     //数据库备份路径
        wxButton* btnRtPath;                     //报表保存路径

        wxStaticText* StaticText1;              //区间设置
        wxStaticText* StaticText2;              //管片编号增加
        wxStaticText* StaticText3;              //起点里程
        wxStaticText* StaticText4;              //终点里程
        wxStaticText* StaticText5;              //管片长度
        wxStaticText* StaticText6;              //管片参数
        wxStaticText* StaticText7;              //管片至切口距离
        wxStaticText* StaticText8;              //工程信息
        wxStaticText* StaticText9;              //工程名称
        wxStaticText* StaticText10;             //建设单位
        wxStaticText* StaticText11;             //项目经理
        wxStaticText* StaticText12;             //开工日期
        wxStaticText* StaticText13;             //工程备注
        wxStaticText* StaticText14;             //值班设置
        wxStaticText* StaticText15;             //白班值班开始时间
        wxStaticText* StaticText16;             //夜班上班时间
        wxStaticText* StaticText17;             //数据库自动备份时间单位
        wxStaticText* StaticText18;             //激光靶配置文件
        wxStaticText* StaticText19;             //激光靶棱镜常数
        wxStaticText* StaticText20;             //激光靶棱镜常数单位
        wxStaticText* StaticText21;             //激光靶棱镜位置
        wxStaticText* StaticText22;             //全站仪激光类型
        wxStaticText* StaticText23;             //激光至视准轴高度
        wxStaticText* StaticText24;             //激光至视准轴高度单位
        wxStaticText* StaticText25;             //激光修正
        wxStaticText* StaticText26;             //修正距离
        wxStaticText* StaticText27;             //横向修正
        wxStaticText* StaticText28;             //垂直修正
        wxStaticText* StaticText29;             //修正距离单位
        wxStaticText* StaticText30;             //横向修正单位
        wxStaticText* StaticText31;             //垂直修正单位
        wxStaticText* StaticText32;             //盾构初始位置
        wxStaticText* StaticText33;             //切口
        wxStaticText* StaticText34;             //盾尾
        wxStaticText* StaticText35;             //滚动角
        wxStaticText* StaticText36;             //盾构机初始铰接数据
        wxStaticText* StaticText37;             //铰接1
        wxStaticText* StaticText38;             //铰接2
        wxStaticText* StaticText39;             //激光靶初始位置
        wxStaticText* StaticText40;             //棱镜
        wxStaticText* StaticText41;             //前屏
        wxStaticText* StaticText42;             //铰接1至切口距离
        wxStaticText* StaticText43;             //测量时间
        wxStaticText* StaticText44;             //姿态角
        wxStaticText* StaticText45;             //铰接1设置
        wxStaticText* StaticText46;             //铰接1至刀盘距离
        wxStaticText* StaticText47;             //姿态测量
        wxStaticText* StaticText48;             //后视检核
        wxStaticText* StaticText49;             //测量限差
        wxStaticText* StaticText50;             //平面偏差限差
        wxStaticText* StaticText51;             //高程偏差限差
        wxStaticText* StaticText52;             //后视检核限差
        wxStaticText* StaticText53;             //偏差变化
        wxStaticText* StaticText54;             //后视检核限差
        wxStaticText* StaticText55;             //偏差超限
        //wxStaticText* StaticText56;             //用户权限设置
        //wxStaticText* StaticText57;             //偏差变化超限
        wxStaticText* StaticText58;             //管理员授权
        //wxStaticText* StaticText59;             //操作员授权
        wxStaticText* StaticText60;             //系统语言
        wxStaticText* StaticText61;             //盾首偏移油缸
        wxStaticText* StaticText62;             //盾尾铰接油缸
        wxStaticText* StaticText63;             //推进油缸
        wxStaticText* StaticText64;             //掘进方向
        wxStaticText* StaticText65;             //拼装方式
        wxStaticText* StaticText66;             //楔形量
        wxStaticText* StaticText67;             //楔形类型
        //wxStaticText* StaticText68;             //操作员
        wxStaticText* StaticText69;             //楔形类型说明
        wxStaticText* StaticText70;             //X
        wxStaticText* StaticText71;             //Y
        wxStaticText* StaticText72;             //Z
        wxStaticText* StaticText73;             //盾尾位置
        wxStaticText* StaticText74;             //X
        wxStaticText* StaticText75;             //Y
        wxStaticText* StaticText76;             //Z
        wxStaticText* StaticText77;             //纠偏设置
        wxStaticText* StaticText78;             //纠偏距离
        wxStaticText* StaticText79;             //每环管片盾构姿态纠偏偏差
        wxStaticText* StaticText80;             //纠偏不符值
        wxStaticText* StaticText81;             //标准盾尾间隙
        wxStaticText* StaticText82;             //最小盾尾间隙
        wxStaticText* StaticText83;             //盾尾内径
        wxStaticText* StaticText84;             //盾尾内径
        wxStaticText* StaticText85;       //数据共享
        wxStaticText* StaticText86;       //远程监控IP
        wxStaticText* StaticText87;       //盾构机IP
        wxStaticText* StaticText88;       //提示范围
        wxStaticText* StaticText89;       //关键区域提示范围
        wxStaticText* StaticText90;       //盾构机PLC IP地址
        wxStaticText* StaticText91;            //错缝条件
        wxStaticText* StaticText92;            //错缝角度
        wxStaticText* StaticText93;            //推进油缸
        wxStaticText* StaticText94;            //推进油缸直径
        wxStaticText* StaticText95;            //盾尾铰接油缸
        wxStaticText* StaticText96;            //盾尾铰接油缸直径
        wxStaticText* StaticText97;            //盾首偏移油缸
        wxStaticText* StaticText98;            //盾首偏移油缸直径
        wxStaticText* StaticText99;            //激光靶参数设置
        wxStaticText* StaticText100;            //激光类型
        wxStaticText* StaticText101;            //铰接位置
        wxStaticText* StaticText102;            //铰接X
        wxStaticText* StaticText103;            //铰接Y
        wxStaticText* StaticText104;            //铰接Z
        wxStaticText* StaticText105;            //盾构姿态
        wxStaticText* StaticText106;            //俯仰角
        wxStaticText* StaticText107;            //方位角
        wxStaticText* StaticText108;            //铰接油缸设置
        wxStaticText* StaticText109;            //铰接油缸：上
        wxStaticText* StaticText110;            //铰接油缸：下
        wxStaticText* StaticText111;            //铰接油缸：左
        wxStaticText* StaticText112;            //铰接油缸：右
        wxStaticText* StaticText113;            //油缸直径示意图
        wxStaticText* StaticText114;            //时间符号
        wxStaticText* StaticText115;            //时间符号
        wxStaticText* StaticText116;            //盾构机IP
        wxStaticText* StaticText117;            //远程电脑IP
        wxStaticText* StaticText118;            //地址分隔符
        wxStaticText* StaticText119;            //地址分隔符
        wxStaticText* StaticText120;            //地址分隔符
        wxStaticText* StaticText121;            //上组油缸
        wxStaticText* StaticText122;            //下组油缸
        wxStaticText* StaticText123;            //左组油缸
        wxStaticText* StaticText124;            //右组油缸

        wxMyTextCtrl* prj_mile1;                //区间起点里程文本框
        wxMyTextCtrl* prj_mile2;                //区间终点里程文本框
        wxMyTextCtrl* seg_len;            //区间管片长度文本框
        wxMyTextCtrl* seg_r;                //管片至刀盘距离
        wxMyTextCtrl* prj_name;                  //工程名称
        //wxMyTextCtrl* company;                  //建设单位
        //wxMyTextCtrl* manager;                  //项目经理
        //wxMyTextCtrl* beginDate;                //开工日期
        //wxMyTextCtrl* prjMarks;                 //工程备注
        wxMyTextCtrl* db_backuppath_text;         //数据库备份路径
        wxMyTextCtrl* tar_file;               //激光靶参数文件
        wxMyTextCtrl* target_prism;          //激光靶棱镜常数
        wxMyTextCtrl* tps_laserh;              //视准轴至激光高度
        wxMyTextCtrl* tps_laserd;             //激光矫正距离
        wxMyTextCtrl* tps_laserx;         //校正X
        wxMyTextCtrl* tps_lasery;         //校正Y
        //wxMyTextCtrl* new_manager_password;                 //新密码
        //wxMyTextCtrl* manager_password_confirm;                 //新密码确认
        //wxMyTextCtrl* new_operator_password;                 //新密码
        //wxMyTextCtrl* operator_password_confirm;                 //盾尾X
        wxMyTextCtrl* oriTailY;                 //盾尾Y
        wxMyTextCtrl* oriTailZ;                 //盾尾Z
        wxMyTextCtrl* tbmroll_text;                  //滚动角
        wxMyTextCtrl* oriJoint1H;               //铰接1H
        wxMyTextCtrl* oriJoint1V;               //铰接1V
        wxMyTextCtrl* oriJoint2H;               //铰接2H
        wxMyTextCtrl* oriJoint2V;               //铰接2V
        wxMyTextCtrl* tarx_text;               //激光靶棱镜X
        wxMyTextCtrl* tary_text;               //激光靶棱镜Y
        wxMyTextCtrl* tarz_text;               //激光靶棱镜Z
        wxMyTextCtrl* tarazi_text;              //方位角偏差
        wxMyTextCtrl* tarpitch_text;            //俯仰角偏差
        wxMyTextCtrl* tarroll_text;             //转动角偏差
        wxMyTextCtrl* jointDist1;               //铰接1至切口距离
        wxMyTextCtrl* jointDist2;               //铰接2至切口距离
        wxMyTextCtrl* measTime1;                //姿态测量时间
        wxMyTextCtrl* measTime2;                //后视检核时间
        wxMyTextCtrl* horiDiff;                 //平面偏差限差
        wxMyTextCtrl* verDiff;                  //高程偏差限差
        wxMyTextCtrl* angleDiff;                //姿态偏差限差
        wxMyTextCtrl* diffChange;               //偏差变化
        wxMyTextCtrl* backDiff;                 //后视检核限差
        wxMyTextCtrl* tolTime;                //测量间隔
        wxMyTextCtrl* TBM_index;                     //盾构编号
        wxMyTextCtrl* jointDist3;                     //盾首偏移油缸
        wxMyTextCtrl* segThick;                     //管片厚度
        wxMyTextCtrl* segScrow;                     //螺栓孔圆心角
        wxMyTextCtrl* Wedge_Text;                     //通用环楔形量
        //wxMyTextCtrl* stdType;                     //标准化楔形类型
        //wxMyTextCtrl* stdWedge;                     //标准化楔形量
        wxMyTextCtrl* headx_text;                     //切口X
        wxMyTextCtrl* heady_text;                     //切口Y
        wxMyTextCtrl* headz_text;                     //切口Z
        wxMyTextCtrl* tailx_text;                     //盾尾X
        wxMyTextCtrl* taily_text;                     //盾尾Y
        wxMyTextCtrl* tailz_text;                     //盾尾Z
        wxMyTextCtrl* corr_dist_text;                     //纠偏距离
        wxMyTextCtrl* corr_diff_text;                     //纠偏偏差
        wxMyTextCtrl* corr_nfit_text;                     //纠偏不符值
        wxMyTextCtrl* min_gap_text;                     //纠偏不符值
        wxMyTextCtrl* std_gap_text;                     //标准盾尾间隙
        wxMyTextCtrl* tail_radius_text;                     //盾尾内径
        wxMyTextCtrl* report_path_text;                     //报表存储路径
        wxMyTextCtrl* gapangle_text;                     //错缝条件
        wxMyTextCtrl* day_hour;                          //白班值班时间
        wxMyTextCtrl* day_min;                           //白班值班时间
        wxMyTextCtrl* night_hour;                        //夜班值班时间
        wxMyTextCtrl* night_min;                        //夜班值班时间
        wxMyTextCtrl* tip_text;                           ///提示范围
        wxMyTextCtrl* jack_radius_text;                   ///推进油缸直径
        wxMyTextCtrl* backjack_radius_text;               ///盾尾铰接油缸直径
        wxMyTextCtrl* frontjack_radius_text;              ///盾首偏移油缸直径
        wxMyTextCtrl* midx_text;                          ///铰接X
        wxMyTextCtrl* midy_text;                          ///铰接Y
        wxMyTextCtrl* midz_text;                          ///铰接Z
        wxMyTextCtrl* tbm_pitch_text;                     ///俯仰角
        wxMyTextCtrl* tbm_azi_text;                       ///方位角
        wxMyTextCtrl* up_mid_text;                       ///铰接油缸行程：上
        wxMyTextCtrl* down_mid_text;                       ///铰接油缸行程：下
        wxMyTextCtrl* left_mid_text;                       ///铰接油缸行程：左
        wxMyTextCtrl* right_mid_text;                       ///铰接油缸行程：右

        wxMyTextCtrl* client_ip_text1;                     //远程IP
        wxMyTextCtrl* client_ip_text2;                     //远程IP
        wxMyTextCtrl* client_ip_text3;                     //远程IP
        wxMyTextCtrl* client_ip_text4;                     //远程IP

        wxMyTextCtrl* mid_value_text1;                     //上组油缸
        wxMyTextCtrl* mid_value_text2;                     //下组油缸
        wxMyTextCtrl* mid_value_text3;                     //左组油缸
        wxMyTextCtrl* mid_value_text4;                     //右组油缸


        wxCheckBox* autoBackup;                   //数据库自动备份
        wxCheckBox* mainJack;               //推进油缸
        wxCheckBox* backJack;               //盾尾铰接油缸
        wxCheckBox* frontJack;               //盾首偏移油缸
        //wxCheckBox* remoteselected;               //启用远程监控
        wxCheckBox* writedatatotbm;               //向盾构机写数据
        wxCheckBox* readdatatotbm;               //向盾构机读数据
        wxCheckBox* forward_checkbox;        //正向
        wxCheckBox* reverse_checkbox;        //反向
        wxCheckBox* gus_laser_checkbox;        //gus74激光
        wxCheckBox* ref_laser_checkbox;        //同轴激光
        wxCheckBox* user_laser_checkbox;        //用户定义激光
        wxCheckBox* seg_method1_checkbox;        //通用环
        wxCheckBox* seg_method2_checkbox;        //标准环+转弯环
        wxCheckBox* seg_wedge1_checkbox;        //等腰梯形
        wxCheckBox* seg_wedge2_checkbox;        //直角梯形
        wxCheckBox* lang1_checkbox;        //简体中文
        wxCheckBox* lang2_checkbox;        //英语
        wxCheckBox* lang3_checkbox;        //繁体中文
        wxCheckBox* midf_checkbox;        //前铰接
        wxCheckBox* midb_checkbox;        //后铰接
        wxCheckBox* mid_data_checkbox;    //铰接数据

        wxCheckBox* control_checkbox1;     //控制模式1
        wxCheckBox* control_checkbox2;     //控制模式2


        wxListView* listBlock;            //管快参数
        wxListView* listArea;             //关键区域
        wxListView* listUser;             //关键区域

        //wxChoice* direct_choice;               //掘进方向
        //wxChoice* laserChoice;               //激光选择
        wxChoice* methodChoice;               //拼装方式
        wxChoice* WedgeChoice;               //激光选择
        wxChoice* langChoice;               //语言选择

        wxRadioButton* segIndexMethod1;         //管片号增加方法一
        wxRadioButton* segIndexMethod2;         //管片号增加方法二
        wxRadioButton* segIndexMethod3;         //管片号增加方法三
        wxRadioButton* prismPos1;         //激光靶棱镜位置一，激光靶下侧中间
        wxRadioButton* prismPos2;         //激光靶棱镜位置二，激光靶上侧中间
        wxRadioButton* prismPos3;         //激光靶棱镜位置三，激光靶右侧中间
        wxRadioButton* prismPos4;         //激光靶棱镜位置三，激光靶左侧中间
        wxRadioButton* laserType1;        //全站仪激光类型一，指示激光
        wxRadioButton* laserType2;        //全站仪激光类型一，GUS74
        wxRadioButton* laserType3;        //全站仪激光类型一，自定义激光
        wxRadioButton* chineseSimp;        //简体中文
        wxRadioButton* chinese;        //繁体中文
        wxRadioButton* english;        //英文
        //wxRadioButton* seguniv;        //通用环
        //wxRadioButton* segstdandturn ;        //标准环+转弯环

        //void LoadDatabase();
		//void WriteMsg(const wxString& str,int color=0);

        //*)
};

#endif //MySetupDialog
