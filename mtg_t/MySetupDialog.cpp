///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////
#include "wx_pch.h"
#include "MySetupDialog.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"
#include "confirmdlg.h"
#include "dmsrad.h"
#include "geometry.h"
#include "BlockDlg.h"
#include "KeyAreaDlg.h"
#include "UserManagerDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/dirdlg.h>


#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MySetupDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MySetupDialog)
#include <wx/font.h>
//*)
#include <wx/stdpaths.h>
#include <wx/config.h>

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MySetupDialog)
const long MySetupDialog::ID_PANEL1 = wxNewId();
const long MySetupDialog::ID_PANEL2 = wxNewId();
const long MySetupDialog::ID_PANEL3 = wxNewId();
const long MySetupDialog::ID_PANEL4 = wxNewId();
const long MySetupDialog::ID_PANEL5 = wxNewId();
const long MySetupDialog::ID_PANEL6 = wxNewId();
const long MySetupDialog::ID_PANEL7 = wxNewId();
const long MySetupDialog::ID_PANEL8 = wxNewId();
const long MySetupDialog::ID_PANEL9 = wxNewId();
const long MySetupDialog::ID_PANEL10 = wxNewId();
const long MySetupDialog::ID_PANEL11 = wxNewId();
const long MySetupDialog::ID_PANEL12 = wxNewId();
const long MySetupDialog::ID_PANEL13 = wxNewId();
const long MySetupDialog::ID_PANEL14 = wxNewId();
const long MySetupDialog::ID_PANEL15 = wxNewId();
const long MySetupDialog::ID_PANEL16 = wxNewId();                 //数据库设置
const long MySetupDialog::ID_PANEL17 = wxNewId();                 //激光靶设置
const long MySetupDialog::ID_PANEL18 = wxNewId();                 //全站仪设置
const long MySetupDialog::ID_PANEL19 = wxNewId();                 //零位数据设置
const long MySetupDialog::ID_PANEL20 = wxNewId();                 //铰接设置
const long MySetupDialog::ID_PANEL21 = wxNewId();                 //测量设置
const long MySetupDialog::ID_PANEL22 = wxNewId();                 //用户权限
const long MySetupDialog::ID_PANEL23 = wxNewId();                 //语言设置
const long MySetupDialog::ID_PANEL24 = wxNewId();                 //管环设置页面
const long MySetupDialog::ID_PANEL25 = wxNewId();                 //管环设置按钮
const long MySetupDialog::ID_PANEL26 = wxNewId();                 //管环设置按钮
const long MySetupDialog::ID_PANEL27 = wxNewId();                 //管环设置按钮
const long MySetupDialog::ID_PANEL28 = wxNewId();                 //画管块
const long MySetupDialog::ID_PANEL29 = wxNewId();                 //激光校正
const long MySetupDialog::ID_PANEL30 = wxNewId();                 //关键区域按钮
const long MySetupDialog::ID_PANEL31 = wxNewId();                 //关键区域页面


const long MySetupDialog::ID_BUTTON1 = wxNewId();                 //取消
const long MySetupDialog::ID_BUTTON2 = wxNewId();                 //应用
const long MySetupDialog::ID_BUTTON3 = wxNewId();                 //工程
//const long MySetupDialog::ID_BUTTON4 = wxNewId();                 //浏览
//const long MySetupDialog::ID_BUTTON5 = wxNewId();                 //打开文件夹
const long MySetupDialog::ID_BUTTON6 = wxNewId();                 //导入激光靶参数文件
const long MySetupDialog::ID_BUTTON7 = wxNewId();                 //测量激光靶
const long MySetupDialog::ID_BUTTON8 = wxNewId();                 //导入激光靶
const long MySetupDialog::ID_BUTTON9 = wxNewId();                 //添加
const long MySetupDialog::ID_BUTTON10 = wxNewId();                 //编辑
const long MySetupDialog::ID_BUTTON11 = wxNewId();                 //删除
const long MySetupDialog::ID_BUTTON12 = wxNewId();                 //编辑管块
const long MySetupDialog::ID_BUTTON13 = wxNewId();                 //删除管快
const long MySetupDialog::ID_BUTTON14 = wxNewId();                 //增加关键区域
const long MySetupDialog::ID_BUTTON15 = wxNewId();                 //编辑关键区域
const long MySetupDialog::ID_BUTTON16 = wxNewId();                 //删除关键区域
const long MySetupDialog::ID_BUTTON17 = wxNewId();                 //添加用户
const long MySetupDialog::ID_BUTTON18 = wxNewId();                 //编辑用户
const long MySetupDialog::ID_BUTTON19 = wxNewId();                 //删除用户
const long MySetupDialog::ID_BUTTON20 = wxNewId();                 //时间+1
const long MySetupDialog::ID_BUTTON21 = wxNewId();                 //时间+2
const long MySetupDialog::ID_BUTTON22 = wxNewId();                 //时间+3
const long MySetupDialog::ID_BUTTON23 = wxNewId();                 //时间+4
const long MySetupDialog::ID_BUTTON24 = wxNewId();                 //时间+5
const long MySetupDialog::ID_BUTTON25 = wxNewId();                 //时间+6
const long MySetupDialog::ID_BUTTON26 = wxNewId();                 //时间+7
const long MySetupDialog::ID_BUTTON27 = wxNewId();                 //时间+8
//const long MySetupDialog::ID_BUTTON28 = wxNewId();                 //数据库备份路径
//const long MySetupDialog::ID_BUTTON29 = wxNewId();                 //报表存储路径


const long MySetupDialog::ID_STATICTEXT1 = wxNewId();
const long MySetupDialog::ID_STATICTEXT2 = wxNewId();
const long MySetupDialog::ID_STATICTEXT3 = wxNewId();             //起点里程
const long MySetupDialog::ID_STATICTEXT4 = wxNewId();             //终点里程
const long MySetupDialog::ID_STATICTEXT5 = wxNewId();             //管片长度
const long MySetupDialog::ID_STATICTEXT6 = wxNewId();             //管片参数
const long MySetupDialog::ID_STATICTEXT7 = wxNewId();             //管片至刀盘距离
const long MySetupDialog::ID_STATICTEXT8 = wxNewId();             //工程信息
const long MySetupDialog::ID_STATICTEXT9 = wxNewId();             //项目名称
const long MySetupDialog::ID_STATICTEXT10 = wxNewId();            //建设单位
const long MySetupDialog::ID_STATICTEXT11 = wxNewId();            //项目经理
const long MySetupDialog::ID_STATICTEXT12 = wxNewId();            //开工日期
const long MySetupDialog::ID_STATICTEXT13 = wxNewId();            //工程备注
const long MySetupDialog::ID_STATICTEXT14 = wxNewId();            //值班设置
const long MySetupDialog::ID_STATICTEXT15 = wxNewId();            //白班值班时间
const long MySetupDialog::ID_STATICTEXT16 = wxNewId();            //夜班上班时间
const long MySetupDialog::ID_STATICTEXT17 = wxNewId();            //数据备份时间单位
const long MySetupDialog::ID_STATICTEXT18 = wxNewId();            //激光靶配置文件
const long MySetupDialog::ID_STATICTEXT19 = wxNewId();            //激光靶棱镜常数
const long MySetupDialog::ID_STATICTEXT20 = wxNewId();            //激光靶棱镜常数单位
const long MySetupDialog::ID_STATICTEXT21 = wxNewId();            //激光靶棱镜位置
const long MySetupDialog::ID_STATICTEXT22 = wxNewId();            //全站仪激光类型
const long MySetupDialog::ID_STATICTEXT23 = wxNewId();            //激光至视准轴高度
const long MySetupDialog::ID_STATICTEXT24 = wxNewId();            //激光至视准轴高度单位
const long MySetupDialog::ID_STATICTEXT25 = wxNewId();            //激光修正
const long MySetupDialog::ID_STATICTEXT26 = wxNewId();            //修正距离
const long MySetupDialog::ID_STATICTEXT27 = wxNewId();            //横向修正
const long MySetupDialog::ID_STATICTEXT28 = wxNewId();            //垂直修正
const long MySetupDialog::ID_STATICTEXT29 = wxNewId();            //修正距离单位
const long MySetupDialog::ID_STATICTEXT30 = wxNewId();            //横向修正单位
const long MySetupDialog::ID_STATICTEXT31 = wxNewId();            //垂直修正单位
const long MySetupDialog::ID_STATICTEXT32 = wxNewId();            //盾构初始位置
const long MySetupDialog::ID_STATICTEXT33 = wxNewId();            //切口
const long MySetupDialog::ID_STATICTEXT34 = wxNewId();            //盾尾
const long MySetupDialog::ID_STATICTEXT35 = wxNewId();            //转动角
const long MySetupDialog::ID_STATICTEXT36 = wxNewId();            //盾构铰接初始数据
const long MySetupDialog::ID_STATICTEXT37 = wxNewId();            //铰接1
const long MySetupDialog::ID_STATICTEXT38 = wxNewId();            //铰接2
const long MySetupDialog::ID_STATICTEXT39 = wxNewId();            //激光靶初始数据
const long MySetupDialog::ID_STATICTEXT40 = wxNewId();            //棱镜
const long MySetupDialog::ID_STATICTEXT41 = wxNewId();            //激光屏1
const long MySetupDialog::ID_STATICTEXT42 = wxNewId();            //激光屏2
const long MySetupDialog::ID_STATICTEXT43 = wxNewId();            //激光
const long MySetupDialog::ID_STATICTEXT44 = wxNewId();            //姿态角
const long MySetupDialog::ID_STATICTEXT45 = wxNewId();            //铰接1设置
const long MySetupDialog::ID_STATICTEXT46 = wxNewId();            //铰接1至刀盘距离
const long MySetupDialog::ID_STATICTEXT47 = wxNewId();            //姿态测量
const long MySetupDialog::ID_STATICTEXT48 = wxNewId();            //后视检核
const long MySetupDialog::ID_STATICTEXT49 = wxNewId();            //限差
const long MySetupDialog::ID_STATICTEXT50 = wxNewId();            //平面偏差限差
const long MySetupDialog::ID_STATICTEXT51 = wxNewId();            //高程偏差限差
const long MySetupDialog::ID_STATICTEXT52 = wxNewId();            //姿态偏差限差
const long MySetupDialog::ID_STATICTEXT53 = wxNewId();            //偏差变化
const long MySetupDialog::ID_STATICTEXT54 = wxNewId();            //后视检核
const long MySetupDialog::ID_STATICTEXT55 = wxNewId();            //偏差超限
const long MySetupDialog::ID_STATICTEXT56 = wxNewId();            //偏差超限
const long MySetupDialog::ID_STATICTEXT57 = wxNewId();            //偏差超限
const long MySetupDialog::ID_STATICTEXT58 = wxNewId();            //管理员权限
const long MySetupDialog::ID_STATICTEXT59 = wxNewId();            //操作员权限
const long MySetupDialog::ID_STATICTEXT60 = wxNewId();            //系统语言
const long MySetupDialog::ID_STATICTEXT61 = wxNewId();            //盾首偏移油缸
const long MySetupDialog::ID_STATICTEXT62 = wxNewId();            //盾尾铰接油缸
const long MySetupDialog::ID_STATICTEXT63 = wxNewId();            //推进油缸
const long MySetupDialog::ID_STATICTEXT64 = wxNewId();            //掘进方向
const long MySetupDialog::ID_STATICTEXT65 = wxNewId();            //拼装方式
const long MySetupDialog::ID_STATICTEXT66 = wxNewId();            //楔形量
const long MySetupDialog::ID_STATICTEXT67 = wxNewId();            //楔形类型
const long MySetupDialog::ID_STATICTEXT68 = wxNewId();            //楔形量
const long MySetupDialog::ID_STATICTEXT69 = wxNewId();            //管块示意
const long MySetupDialog::ID_STATICTEXT70 = wxNewId();            //切口X
const long MySetupDialog::ID_STATICTEXT71 = wxNewId();            //切口Y
const long MySetupDialog::ID_STATICTEXT72 = wxNewId();            //切口Z
const long MySetupDialog::ID_STATICTEXT73 = wxNewId();            //盾尾位置
const long MySetupDialog::ID_STATICTEXT74 = wxNewId();            //盾尾X
const long MySetupDialog::ID_STATICTEXT75 = wxNewId();            //盾尾Y
const long MySetupDialog::ID_STATICTEXT76 = wxNewId();            //盾尾Z
const long MySetupDialog::ID_STATICTEXT77 = wxNewId();            //纠偏设置
const long MySetupDialog::ID_STATICTEXT78 = wxNewId();            //纠偏距离
const long MySetupDialog::ID_STATICTEXT79 = wxNewId();            //纠偏偏差
const long MySetupDialog::ID_STATICTEXT80 = wxNewId();            //纠偏不符值
const long MySetupDialog::ID_STATICTEXT81 = wxNewId();            //标准盾尾间隙
const long MySetupDialog::ID_STATICTEXT82 = wxNewId();            //最小盾尾间隙
const long MySetupDialog::ID_STATICTEXT83 = wxNewId();            //盾尾内径
const long MySetupDialog::ID_STATICTEXT84 = wxNewId();            //单位备注
const long MySetupDialog::ID_STATICTEXT85 = wxNewId();            //数据共享
const long MySetupDialog::ID_STATICTEXT86 = wxNewId();            //远程IP
const long MySetupDialog::ID_STATICTEXT87 = wxNewId();            //盾构IP
const long MySetupDialog::ID_STATICTEXT88 = wxNewId();            //提示范围
const long MySetupDialog::ID_STATICTEXT89 = wxNewId();            //提示范围
const long MySetupDialog::ID_STATICTEXT90 = wxNewId();            //盾构PLC IP地址
const long MySetupDialog::ID_STATICTEXT91 = wxNewId();            //错缝条件
const long MySetupDialog::ID_STATICTEXT92 = wxNewId();            //错缝角度

const long MySetupDialog::ID_STATICTEXT93 = wxNewId();            //推进油缸
const long MySetupDialog::ID_STATICTEXT94 = wxNewId();            //推进油缸直径
const long MySetupDialog::ID_STATICTEXT95 = wxNewId();            //盾尾铰接油缸
const long MySetupDialog::ID_STATICTEXT96 = wxNewId();            //盾尾铰接油缸直径
const long MySetupDialog::ID_STATICTEXT97 = wxNewId();            //盾首偏移油缸
const long MySetupDialog::ID_STATICTEXT98 = wxNewId();            //盾首偏移油缸直径
const long MySetupDialog::ID_STATICTEXT99 = wxNewId();            //激光靶参数设置
const long MySetupDialog::ID_STATICTEXT100 = wxNewId();            //激光类型
const long MySetupDialog::ID_STATICTEXT101 = wxNewId();            //铰接位置
const long MySetupDialog::ID_STATICTEXT102 = wxNewId();            //铰接X
const long MySetupDialog::ID_STATICTEXT103 = wxNewId();            //铰接Y
const long MySetupDialog::ID_STATICTEXT104 = wxNewId();            //铰接Z
const long MySetupDialog::ID_STATICTEXT105 = wxNewId();            //盾构姿态
const long MySetupDialog::ID_STATICTEXT106 = wxNewId();            //俯仰角
const long MySetupDialog::ID_STATICTEXT107 = wxNewId();            //方位角

const long MySetupDialog::ID_STATICTEXT108 = wxNewId();            //铰接油缸设置
const long MySetupDialog::ID_STATICTEXT109 = wxNewId();            //铰接油缸：上
const long MySetupDialog::ID_STATICTEXT110 = wxNewId();            //铰接油缸：下
const long MySetupDialog::ID_STATICTEXT111 = wxNewId();            //铰接油缸：左
const long MySetupDialog::ID_STATICTEXT112 = wxNewId();            //铰接油缸：右
const long MySetupDialog::ID_STATICTEXT113 = wxNewId();            //油缸直径示意图
const long MySetupDialog::ID_STATICTEXT114 = wxNewId();            //时间符号
const long MySetupDialog::ID_STATICTEXT115 = wxNewId();            //时间符号
const long MySetupDialog::ID_STATICTEXT116 = wxNewId();            //盾构机IP
const long MySetupDialog::ID_STATICTEXT117 = wxNewId();            //远程电脑IP
const long MySetupDialog::ID_STATICTEXT118 = wxNewId();            //地址分隔符
const long MySetupDialog::ID_STATICTEXT119 = wxNewId();            //地址分隔符
const long MySetupDialog::ID_STATICTEXT120 = wxNewId();            //地址分隔符
const long MySetupDialog::ID_STATICTEXT121 = wxNewId();            //上组油缸
const long MySetupDialog::ID_STATICTEXT122 = wxNewId();            //下组油缸
const long MySetupDialog::ID_STATICTEXT123 = wxNewId();            //左组油缸
const long MySetupDialog::ID_STATICTEXT124 = wxNewId();            //右组油缸

const long MySetupDialog::ID_TEXTCTRL1 = wxNewId();
const long MySetupDialog::ID_TEXTCTRL2 = wxNewId();
const long MySetupDialog::ID_TEXTCTRL3 = wxNewId();
const long MySetupDialog::ID_TEXTCTRL4 = wxNewId();                //管片至刀盘距离
const long MySetupDialog::ID_TEXTCTRL5 = wxNewId();                //项目名称
const long MySetupDialog::ID_TEXTCTRL6 = wxNewId();                //建设单位
const long MySetupDialog::ID_TEXTCTRL7 = wxNewId();                //项目经理
const long MySetupDialog::ID_TEXTCTRL8 = wxNewId();                //开工日期
const long MySetupDialog::ID_TEXTCTRL9 = wxNewId();                //开工日期
const long MySetupDialog::ID_TEXTCTRL10 = wxNewId();               //白班值班时间
const long MySetupDialog::ID_TEXTCTRL11 = wxNewId();               //夜班上班时间
const long MySetupDialog::ID_TEXTCTRL12 = wxNewId();               //激光靶参数文件
const long MySetupDialog::ID_TEXTCTRL13 = wxNewId();               //激光靶棱镜常数
const long MySetupDialog::ID_TEXTCTRL14 = wxNewId();               //视准轴至激光高度
const long MySetupDialog::ID_TEXTCTRL15 = wxNewId();               //校正距离
const long MySetupDialog::ID_TEXTCTRL16 = wxNewId();               //横向校正
const long MySetupDialog::ID_TEXTCTRL17 = wxNewId();               //垂直校正
const long MySetupDialog::ID_TEXTCTRL18 = wxNewId();               //切口X
const long MySetupDialog::ID_TEXTCTRL19 = wxNewId();               //切口Y
const long MySetupDialog::ID_TEXTCTRL20 = wxNewId();               //切口Z
const long MySetupDialog::ID_TEXTCTRL21 = wxNewId();               //盾尾X
const long MySetupDialog::ID_TEXTCTRL22 = wxNewId();               //盾尾Y
const long MySetupDialog::ID_TEXTCTRL23 = wxNewId();               //盾尾Z
const long MySetupDialog::ID_TEXTCTRL24 = wxNewId();               //转动角
const long MySetupDialog::ID_TEXTCTRL25 = wxNewId();               //铰接1H
const long MySetupDialog::ID_TEXTCTRL26 = wxNewId();               //铰接1V
const long MySetupDialog::ID_TEXTCTRL27 = wxNewId();               //铰接2H
const long MySetupDialog::ID_TEXTCTRL28 = wxNewId();               //铰接2V
const long MySetupDialog::ID_TEXTCTRL29 = wxNewId();               //激光靶棱镜X
const long MySetupDialog::ID_TEXTCTRL30 = wxNewId();               //激光靶棱镜Y
const long MySetupDialog::ID_TEXTCTRL31 = wxNewId();               //激光靶棱镜Z
const long MySetupDialog::ID_TEXTCTRL32 = wxNewId();               //后屏X
const long MySetupDialog::ID_TEXTCTRL33 = wxNewId();               //后屏Y
const long MySetupDialog::ID_TEXTCTRL34 = wxNewId();               //前屏X
const long MySetupDialog::ID_TEXTCTRL35 = wxNewId();               //前屏Y
const long MySetupDialog::ID_TEXTCTRL36 = wxNewId();               //激光束水平角
const long MySetupDialog::ID_TEXTCTRL37 = wxNewId();               //激光束竖直角
const long MySetupDialog::ID_TEXTCTRL38 = wxNewId();               //激光靶转动角
const long MySetupDialog::ID_TEXTCTRL39 = wxNewId();               //激光靶俯仰角
const long MySetupDialog::ID_TEXTCTRL40 = wxNewId();               //高程偏差限差
const long MySetupDialog::ID_TEXTCTRL41 = wxNewId();               //姿态偏差限差
const long MySetupDialog::ID_TEXTCTRL42 = wxNewId();               //偏差变化
const long MySetupDialog::ID_TEXTCTRL43 = wxNewId();               //后视检核限差
const long MySetupDialog::ID_TEXTCTRL44 = wxNewId();               //管理员密码
const long MySetupDialog::ID_TEXTCTRL45 = wxNewId();               //操作员密码
const long MySetupDialog::ID_TEXTCTRL46 = wxNewId();               //盾构机编号
const long MySetupDialog::ID_TEXTCTRL47 = wxNewId();               //盾首偏移油缸
const long MySetupDialog::ID_TEXTCTRL48 = wxNewId();               //管片厚度
const long MySetupDialog::ID_TEXTCTRL49 = wxNewId();               //螺栓孔圆心角
const long MySetupDialog::ID_TEXTCTRL50 = wxNewId();               //通用环楔形量
const long MySetupDialog::ID_TEXTCTRL51 = wxNewId();               //标准环楔形类型
const long MySetupDialog::ID_TEXTCTRL52 = wxNewId();               //标准化楔形量
const long MySetupDialog::ID_TEXTCTRL53 = wxNewId();         //切口x
const long MySetupDialog::ID_TEXTCTRL54 = wxNewId();         //切口y
const long MySetupDialog::ID_TEXTCTRL55 = wxNewId();         //切口z
const long MySetupDialog::ID_TEXTCTRL56 = wxNewId();         //盾尾X
const long MySetupDialog::ID_TEXTCTRL57 = wxNewId();         //盾尾Y
const long MySetupDialog::ID_TEXTCTRL58 = wxNewId();         //盾尾Z
const long MySetupDialog::ID_TEXTCTRL59 = wxNewId();         //纠偏距离
const long MySetupDialog::ID_TEXTCTRL60 = wxNewId();         //纠偏偏差
const long MySetupDialog::ID_TEXTCTRL61 = wxNewId();         //纠偏不符值
const long MySetupDialog::ID_TEXTCTRL62 = wxNewId();         //标准盾尾间隙
const long MySetupDialog::ID_TEXTCTRL63 = wxNewId();         //最小盾尾间隙
const long MySetupDialog::ID_TEXTCTRL64 = wxNewId();         //盾尾内径
const long MySetupDialog::ID_TEXTCTRL65 = wxNewId();         //远程IP
const long MySetupDialog::ID_TEXTCTRL67 = wxNewId();         //错缝角度
const long MySetupDialog::ID_TEXTCTRL91 = wxNewId();         //测量间隔提醒
const long MySetupDialog::ID_TEXTCTRL92 = wxNewId();         //白班时间
const long MySetupDialog::ID_TEXTCTRL93 = wxNewId();         //白班时间
const long MySetupDialog::ID_TEXTCTRL94 = wxNewId();         //白班时间
const long MySetupDialog::ID_TEXTCTRL95 = wxNewId();         //白班时间
const long MySetupDialog::ID_TEXTCTRL96 = wxNewId();         //推进油缸直径
const long MySetupDialog::ID_TEXTCTRL97 = wxNewId();         //盾尾铰接油缸直径
const long MySetupDialog::ID_TEXTCTRL98 = wxNewId();         //盾首偏移油缸直径
const long MySetupDialog::ID_TEXTCTRL99 = wxNewId();         //铰接X
const long MySetupDialog::ID_TEXTCTRL100 = wxNewId();         //铰接Y
const long MySetupDialog::ID_TEXTCTRL101 = wxNewId();         //铰接Z
const long MySetupDialog::ID_TEXTCTRL102 = wxNewId();         //俯仰角
const long MySetupDialog::ID_TEXTCTRL103 = wxNewId();         //方位角
const long MySetupDialog::ID_TEXTCTRL104 = wxNewId();         //铰接油缸：上
const long MySetupDialog::ID_TEXTCTRL105 = wxNewId();         //铰接油缸：下
const long MySetupDialog::ID_TEXTCTRL106 = wxNewId();         //铰接油缸：左
const long MySetupDialog::ID_TEXTCTRL107 = wxNewId();         //铰接油缸：右
const long MySetupDialog::ID_TEXTCTRL108 = wxNewId();         //数据库备份时间
const long MySetupDialog::ID_TEXTCTRL109 = wxNewId();         //数据库备份路径
const long MySetupDialog::ID_TEXTCTRL110 = wxNewId();         //数据库备份路径
const long MySetupDialog::ID_TEXTCTRL111 = wxNewId();         //数据库备份路径
const long MySetupDialog::ID_TEXTCTRL112 = wxNewId();         //数据库备份路径
const long MySetupDialog::ID_TEXTCTRL116 = wxNewId();         //数据库备份路径
const long MySetupDialog::ID_TEXTCTRL117 = wxNewId();         //数据库备份路径
const long MySetupDialog::ID_TEXTCTRL118 = wxNewId();         //数据库备份路径
const long MySetupDialog::ID_TEXTCTRL119 = wxNewId();         //数据库备份路径

const long MySetupDialog::ID_CHECKBOX1 = wxNewId();                //数据库自动备份
const long MySetupDialog::ID_CHECKBOX10 = wxNewId();                //推进油缸
const long MySetupDialog::ID_CHECKBOX11 = wxNewId();                //盾尾铰接油缸
const long MySetupDialog::ID_CHECKBOX12 = wxNewId();                //盾首偏移油缸
//const long MySetupDialog::ID_CHECKBOX13 = wxNewId();                //启用远程监控
const long MySetupDialog::ID_CHECKBOX14 = wxNewId();                //向盾构PLC写数据
const long MySetupDialog::ID_CHECKBOX15 = wxNewId();                //项盾构PLC读数据
const long MySetupDialog::ID_CHECKBOX16 = wxNewId();                //正向
const long MySetupDialog::ID_CHECKBOX17 = wxNewId();                //反向
const long MySetupDialog::ID_CHECKBOX18 = wxNewId();                //GUS74激光
const long MySetupDialog::ID_CHECKBOX19 = wxNewId();                //同轴激光
const long MySetupDialog::ID_CHECKBOX20 = wxNewId();                //用户自定义
const long MySetupDialog::ID_CHECKBOX21 = wxNewId();                //通用环
const long MySetupDialog::ID_CHECKBOX22 = wxNewId();                //标准环+转弯环
const long MySetupDialog::ID_CHECKBOX23 = wxNewId();                //等腰梯形
const long MySetupDialog::ID_CHECKBOX24 = wxNewId();                //直角梯形
const long MySetupDialog::ID_CHECKBOX25 = wxNewId();                //简体中文
const long MySetupDialog::ID_CHECKBOX26 = wxNewId();                //英文
const long MySetupDialog::ID_CHECKBOX27 = wxNewId();                //繁体中文
const long MySetupDialog::ID_CHECKBOX28 = wxNewId();                //前铰接
const long MySetupDialog::ID_CHECKBOX29 = wxNewId();                //后交接
const long MySetupDialog::ID_CHECKBOX30 = wxNewId();                //控制模式1
const long MySetupDialog::ID_CHECKBOX31 = wxNewId();                //控制模式2
const long MySetupDialog::ID_CHECKBOX32 = wxNewId();                //铰接数据

const long MySetupDialog::ID_RADIOBUTTON1 = wxNewId();
const long MySetupDialog::ID_RADIOBUTTON2 = wxNewId();
const long MySetupDialog::ID_RADIOBUTTON3 = wxNewId();
const long MySetupDialog::ID_RADIOBUTTON4 = wxNewId();             //激光靶下侧中间
const long MySetupDialog::ID_RADIOBUTTON5 = wxNewId();             //激光靶上侧中间
const long MySetupDialog::ID_RADIOBUTTON6 = wxNewId();             //激光靶右侧中间
const long MySetupDialog::ID_RADIOBUTTON7 = wxNewId();             //激光靶左侧中间
const long MySetupDialog::ID_RADIOBUTTON8 = wxNewId();             //激光类型：指示激光
const long MySetupDialog::ID_RADIOBUTTON9 = wxNewId();             //激光类型：GUS74
const long MySetupDialog::ID_RADIOBUTTON10 = wxNewId();            //激光类型：用户自定义
const long MySetupDialog::ID_RADIOBUTTON11 = wxNewId();             //简体中文
const long MySetupDialog::ID_RADIOBUTTON12 = wxNewId();             //繁体中文
const long MySetupDialog::ID_RADIOBUTTON13 = wxNewId();             //英文
//const long MySetupDialog::ID_RADIOBUTTON14 = wxNewId();             //繁体中文
//const long MySetupDialog::ID_RADIOBUTTON15 = wxNewId();             //掘进方向
const long MySetupDialog::ID_RADIOBUTTON16 = wxNewId();             //通用环
const long MySetupDialog::ID_RADIOBUTTON17 = wxNewId();             //标准+转弯

//const long MySetupDialog::ID_CHOICE1 = wxNewId();                //掘进方向
//const long MySetupDialog::ID_CHOICE2 = wxNewId();                //激光选择
const long MySetupDialog::ID_CHOICE3 = wxNewId();                //激光选择
const long MySetupDialog::ID_CHOICE4 = wxNewId();                //激光选择
const long MySetupDialog::ID_CHOICE5 = wxNewId();                //语言选择


const long MySetupDialog::ID_LIST1 = wxNewId();                        //管环类型
const long MySetupDialog::ID_LIST2 = wxNewId();                        //关键区域
const long MySetupDialog::ID_LIST3 = wxNewId();                        //用户列表
//*)

static const long ID_MENU_CLEAN = wxNewId();
static const long ID_MENU_BACKUP = wxNewId();
static const long ID_MENU_RESTORE = wxNewId();

MySetupDialog::MySetupDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelMain = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelNavi = new wxPanel(panelMain, ID_PANEL2, wxPoint(0,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelBorder1 = new wxPanel(panelMain, ID_PANEL3, wxPoint(0,0), wxSize(w,10), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    panelBorder2 = new wxPanel(panelMain, ID_PANEL4, wxPoint(w-8,10), wxSize(8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    panelBtnPrj = new wxPanel(panelNavi, ID_PANEL5, wxPoint(0,0), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    panelBtnKey = new wxPanel(panelNavi, ID_PANEL30, wxPoint(0,36), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL30"));
    panelBtnTBM = new wxPanel(panelNavi, ID_PANEL10, wxPoint(0,72), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    panelBtnTarget = new wxPanel(panelNavi, ID_PANEL7, wxPoint(0,108), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    panelBtnTheodolite = new wxPanel(panelNavi, ID_PANEL8, wxPoint(0,144), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    panelBtnSeg = new wxPanel(panelNavi, ID_PANEL25, wxPoint(0,180), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL25"));
    panelBtnBlock = new wxPanel(panelNavi, ID_PANEL26, wxPoint(0,216), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL26"));
    panelBtnOrigin = new wxPanel(panelNavi, ID_PANEL9, wxPoint(0,252), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    panelBtnDatabase = new wxPanel(panelNavi, ID_PANEL6, wxPoint(0,288), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL6"));

    panelBtnMeas = new wxPanel(panelNavi, ID_PANEL11, wxPoint(0,324), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL11"));
    panelBtnUser = new wxPanel(panelNavi, ID_PANEL12, wxPoint(0,360), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL12"));
    panelBtnLanguage = new wxPanel(panelNavi, ID_PANEL13, wxPoint(0,396), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL13"));
    panelBtnArea = new wxPanel(panelMain, ID_PANEL15, wxPoint(0,h-80), wxSize(w,90), wxTAB_TRAVERSAL, _T("ID_PANEL15"));

    panelPrj = new wxPanel(panelMain, ID_PANEL14, wxPoint(160,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL14"));
    panelPrj->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPrj->SetBackgroundColour(wxColor(255,255,255));
    //panelPrj->SetForegroundColour(wxColor(80,80,80));
    panelPrj->SetFont(normalFont);
    panelKey = new wxPanel(panelMain, ID_PANEL31, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL31"));
    panelKey->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelKey->SetBackgroundColour(wxColor(255,255,255));
    //panelKey->SetForegroundColour(wxColor(80,80,80));
    panelKey->SetFont(normalFont);
    //wxMessageBox(wxString::Format(_("%d,%d"),w,h));
    panelDb = new wxPanel(panelMain, ID_PANEL16, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL16"));
    panelDb->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelDb->SetBackgroundColour(wxColor(255,255,255));
    //panelPrj->SetForegroundColour(wxColor(80,80,80));
    panelDb->SetFont(normalFont);

    panelTarget = new wxPanel(panelMain, ID_PANEL17, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL17"));
    panelTarget->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTarget->SetBackgroundColour(wxColor(255,255,255));
    //panelPrj->SetForegroundColour(wxColor(80,80,80));
    panelTarget->SetFont(normalFont);

    panelTheo = new wxPanel(panelMain, ID_PANEL18, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL18"));
    panelTheo->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTheo->SetBackgroundColour(wxColor(255,255,255));
    //panelPrj->SetForegroundColour(wxColor(80,80,80));
    panelTheo->SetFont(normalFont);

    panelSeg = new wxPanel(panelMain, ID_PANEL24, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL24"));
    panelSeg->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelSeg->SetBackgroundColour(wxColor(255,255,255));
    //panelPrj->SetForegroundColour(wxColor(80,80,80));
    panelSeg->SetFont(normalFont);

    panelBlock = new wxPanel(panelMain, ID_PANEL27, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL27"));
    panelBlock->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBlock->SetBackgroundColour(wxColor(255,255,255));
    //panelPrj->SetForegroundColour(wxColor(80,80,80));
    panelBlock->SetFont(normalFont);

    panelOri = new wxPanel(panelMain, ID_PANEL19, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL19"));
    panelOri->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelOri->SetBackgroundColour(wxColor(255,255,255));
    //panelPrj->SetForegroundColour(wxColor(80,80,80));
    panelOri->SetFont(normalFont);

    panelTBM = new wxPanel(panelMain, ID_PANEL20, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL20"));
    panelTBM->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTBM->SetBackgroundColour(wxColor(255,255,255));
    //panelPrj->SetForegroundColour(wxColor(80,80,80));
    panelTBM->SetFont(normalFont);

    panelMeas = new wxPanel(panelMain, ID_PANEL21, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL21"));
    panelMeas->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMeas->SetBackgroundColour(wxColor(255,255,255));
    //panelPrj->SetForegroundColour(wxColor(80,80,80));
    panelMeas->SetFont(normalFont);

    panelUser = new wxPanel(panelMain, ID_PANEL22, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL22"));
    panelUser->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelUser->SetBackgroundColour(wxColor(255,255,255));
    //panelPrj->SetForegroundColour(wxColor(80,80,80));
    panelUser->SetFont(normalFont);

    panelLang = new wxPanel(panelMain, ID_PANEL23, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL23"));
    panelLang->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelLang->SetBackgroundColour(wxColor(255,255,255));
    //panelPrj->SetForegroundColour(wxColor(80,80,80));
    panelLang->SetFont(normalFont);

    //textMsg = new wxStaticText(panelBtnArea, ID_STATICTEXT91, _("取 消"), wxPoint(120,15), wxSize(600,20), 0, _T("ID_STATICTEXT91"));

    btnCancel = new wxButton(panelBtnArea, ID_BUTTON1, _("退 出"), wxPoint(w-96-10,15), wxSize(96,36), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btnApply = new wxButton(panelBtnArea, ID_BUTTON2, _("应 用"), wxPoint(w-96-15-96,15), wxSize(96,36), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    btnProj = new wxButton(panelBtnArea, ID_BUTTON3, _("工 程"), wxPoint(25,15), wxSize(96,36), 0, wxDefaultValidator, _T("ID_BUTTON3"));

    StaticText1 = new wxStaticText(panelPrj, ID_STATICTEXT1, _("工程信息"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColor(68,68,68));
    StaticText9 = new wxStaticText(panelPrj, ID_STATICTEXT9, _("项目名称"), wxPoint(120,25),wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    StaticText9->SetForegroundColour(wxColor(68,68,68));
    prj_name = new wxMyTextCtrl(panelPrj, ID_TEXTCTRL5, wxEmptyString, wxPoint(120,45), wxSize(380,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));

    StaticText3 = new wxStaticText(panelPrj, ID_STATICTEXT3, _("起点里程(单位:m)"), wxPoint(120,80),wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText3->SetForegroundColour(wxColor(68,68,68));
    prj_mile1 = new wxMyTextCtrl(panelPrj, ID_TEXTCTRL1, wxEmptyString, wxPoint(120,100), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText4 = new wxStaticText(panelPrj, ID_STATICTEXT4, _("终点里程(单位:m)"), wxPoint(120,135),wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText4->SetForegroundColour(wxColor(68,68,68));
    prj_mile2 = new wxMyTextCtrl(panelPrj, ID_TEXTCTRL2, wxEmptyString, wxPoint(120,155), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));

    StaticText64 = new wxStaticText(panelPrj, ID_STATICTEXT64, _("掘进方向"), wxPoint(120,190),wxDefaultSize, 0, _T("ID_STATICTEXT64"));
    StaticText64->SetForegroundColour(wxColor(68,68,68));
    //direct_choice = new wxChoice(panelPrj, ID_CHOICE1, wxPoint(120,155), wxSize(180,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    //direct_choice->SetSelection(direct_choice->Append(_("小里程→大里程")) );
    //direct_choice->Append(_("大里程→小里程"));
    //direct_choice->Show(false);

    forward_checkbox = new wxCheckBox(panelPrj,ID_CHECKBOX16,_("小里程至大里程"),wxPoint(120,160),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX16"));
    forward_checkbox->SetForegroundColour(wxColor(68,68,68));
    forward_checkbox->SetValue(true);
    reverse_checkbox = new wxCheckBox(panelPrj,ID_CHECKBOX17,_("大里程至小里程"),wxPoint(120,195),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX17"));
    reverse_checkbox->SetForegroundColour(wxColor(68,68,68));
    StaticText14 = new wxStaticText(panelPrj, ID_STATICTEXT14, _("值班设置"), wxPoint(25,265),wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    StaticText14->SetForegroundColour(wxColor(68,68,68));
    StaticText15 = new wxStaticText(panelPrj, ID_STATICTEXT15, _("白班上班时间(24h)"), wxPoint(120,265),wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	StaticText15->SetForegroundColour(wxColor(68,68,68));
    day_hour = new wxMyTextCtrl(panelPrj, ID_TEXTCTRL10, wxEmptyString, wxPoint(120,285), wxSize(40,20), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER | wxTE_PROCESS_TAB , wxDefaultValidator, _T("ID_TEXTCTRL10"));
    day_hour->SetMaxLength(2);
    day_min = new wxMyTextCtrl(panelPrj, ID_TEXTCTRL92, wxEmptyString, wxPoint(210,285), wxSize(40,20), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL92"));
    day_min->SetMaxLength(2);
    StaticText16 = new wxStaticText(panelPrj, ID_STATICTEXT16, _("夜班上班时间(24h)"), wxPoint(120,320),wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    StaticText16->SetForegroundColour(wxColor(68,68,68));
    night_hour = new wxMyTextCtrl(panelPrj, ID_TEXTCTRL11, wxEmptyString, wxPoint(120,340), wxSize(40,20), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    night_min = new wxMyTextCtrl(panelPrj, ID_TEXTCTRL93, wxEmptyString, wxPoint(210,340), wxSize(40,20), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL93"));
    StaticText114 = new wxStaticText(panelPrj, ID_STATICTEXT114, _(":"), wxPoint(120,265),wxDefaultSize, 0, _T("ID_STATICTEXT114"));
	StaticText114->SetForegroundColour(wxColor(68,68,68));
	StaticText115 = new wxStaticText(panelPrj, ID_STATICTEXT115, _(":"), wxPoint(120,265),wxDefaultSize, 0, _T("ID_STATICTEXT115"));
	StaticText115->SetForegroundColour(wxColor(68,68,68));
	btnAddDayh = new wxButton(panelPrj, ID_BUTTON20, _("+"), wxPoint(505,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON20"));
    btnAddDayh->SetForegroundColour(wxColor(68,68,68));
    btnSubDayh = new wxButton(panelPrj, ID_BUTTON21, _("-"), wxPoint(505,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON21"));
    btnSubDayh->SetForegroundColour(wxColor(68,68,68));
    btnAddDaym = new wxButton(panelPrj, ID_BUTTON22, _("+"), wxPoint(505,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON22"));
    btnAddDaym->SetForegroundColour(wxColor(68,68,68));
    btnSubDaym = new wxButton(panelPrj, ID_BUTTON23, _("-"), wxPoint(505,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON23"));
    btnSubDaym->SetForegroundColour(wxColor(68,68,68));

    btnAddNighth = new wxButton(panelPrj, ID_BUTTON24, _("+"), wxPoint(505,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON24"));
    btnAddNighth->SetForegroundColour(wxColor(68,68,68));
    btnSubNighth = new wxButton(panelPrj, ID_BUTTON25, _("-"), wxPoint(505,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON25"));
    btnSubNighth->SetForegroundColour(wxColor(68,68,68));
    btnAddNightm = new wxButton(panelPrj, ID_BUTTON26, _("+"), wxPoint(505,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON26"));
    btnAddNightm->SetForegroundColour(wxColor(68,68,68));
    btnSubNightm = new wxButton(panelPrj, ID_BUTTON27, _("-"), wxPoint(505,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON27"));
    btnSubNightm->SetForegroundColour(wxColor(68,68,68));

    StaticText20 = new wxStaticText(panelKey, ID_STATICTEXT20, _("关键区域"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    StaticText20->SetForegroundColour(wxColour(68,68,68));
    listArea = new wxListView(panelKey,ID_LIST2,wxPoint(120,20),wxSize(360,240),wxLC_REPORT, wxDefaultValidator,_T("ID_LIST2"));
    listArea->SetForegroundColour(wxColor(68,68,68));
    btnAddArea = new wxButton(panelKey, ID_BUTTON14, _("添加"), wxPoint(505,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON14"));
    btnAddArea->SetForegroundColour(wxColor(68,68,68));
    btnEditArea = new wxButton(panelKey, ID_BUTTON15, _("编辑"), wxPoint(505,55), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON15"));
    btnEditArea->SetForegroundColour(wxColor(68,68,68));
    btnEditArea->Enable(false);
    btnDelArea = new wxButton(panelKey, ID_BUTTON16, _("删除"), wxPoint(505,90), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON16"));
    btnDelArea->SetForegroundColour(wxColor(68,68,68));
    btnDelArea->Enable(false);
    StaticText88 = new wxStaticText(panelKey, ID_STATICTEXT88, _("提示范围"), wxPoint(25,295),wxDefaultSize, 0, _T("ID_STATICTEXT88"));
    StaticText88->SetForegroundColour(wxColor(68,68,68));
    StaticText89 = new wxStaticText(panelKey, ID_STATICTEXT89, _("关键区域到盾构机切口的距离，单位为mm。"), wxPoint(120,320),wxDefaultSize, 0, _T("ID_STATICTEXT89"));
    StaticText89->SetForegroundColour(wxColor(68,68,68));
    //StaticText89->Enable(false);
    tip_text = new wxMyTextCtrl(panelKey, ID_TEXTCTRL51, wxEmptyString, wxPoint(120,290), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL51"));

    StaticText45 = new wxStaticText(panelTBM, ID_STATICTEXT45, _("盾构机"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT45"));
	StaticText45->SetForegroundColour(wxColor(68,68,68));
	TBM_index = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL46, wxEmptyString, wxPoint(120,45), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL46"));
    StaticText83 = new wxStaticText(panelTBM, ID_STATICTEXT83, _("盾构机编号"), wxPoint(120,25),wxDefaultSize, 0, _T("ID_STATICTEXT83"));
    StaticText83->SetForegroundColour(wxColor(68,68,68));
    tail_radius_text = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL64, wxEmptyString, wxPoint(120,100), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL64"));
    StaticText84 = new wxStaticText(panelTBM, ID_STATICTEXT84, _("盾尾内径(单位:m)"), wxPoint(120,80),wxDefaultSize, 0, _T("ID_STATICTEXT84"));
    StaticText84->SetForegroundColour(wxColor(68,68,68));
    StaticText42 = new wxStaticText(panelTBM, ID_STATICTEXT42, _("油缸设置"), wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT42"));
    StaticText42->SetForegroundColour(wxColor(68,68,68));
    mainJack = new wxCheckBox(panelTBM,ID_CHECKBOX10,_("推进油缸至刀盘面距离(单位:m)"),wxPoint(120,150),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX10"));
	mainJack->SetValue(true);
	mainJack->Enable(false);
	mainJack->Show(false);
	jointDist1 = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL35, wxEmptyString, wxPoint(120,170), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL35"));
	backJack = new wxCheckBox(panelTBM,ID_CHECKBOX11,_("盾尾铰接油缸至刀盘面距离(单位:m)"),wxPoint(120,205),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX10"));
	backJack->SetForegroundColour(wxColor(68,68,68));
	backJack->Show(false);
	jointDist2 = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL36, wxEmptyString, wxPoint(120,225), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL36"));
    frontJack = new wxCheckBox(panelTBM,ID_CHECKBOX12,_("盾首偏移油缸至刀盘距离(单位:m)"),wxPoint(120,260),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX12"));
    frontJack->SetForegroundColour(wxColor(68,68,68));
    frontJack->Show(false);
    jointDist3 = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL47, wxEmptyString, wxPoint(120,280), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL47"));
    jack_radius_text = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL96, wxEmptyString, wxPoint(120,225), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL96"));
    backjack_radius_text = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL97, wxEmptyString, wxPoint(120,225), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL97"));
    frontjack_radius_text = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL98, wxEmptyString, wxPoint(120,225), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL98"));
    StaticText93 = new wxStaticText(panelTBM, ID_STATICTEXT93, wxEmptyString, wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT93"));
    StaticText93->SetForegroundColour(wxColor(68,68,68));
    StaticText94 = new wxStaticText(panelTBM, ID_STATICTEXT94, wxEmptyString, wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT94"));
    StaticText94->SetForegroundColour(wxColor(68,68,68));
    StaticText95 = new wxStaticText(panelTBM, ID_STATICTEXT95, wxEmptyString, wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT95"));
    StaticText95->SetForegroundColour(wxColor(68,68,68));
    StaticText96 = new wxStaticText(panelTBM, ID_STATICTEXT96, wxEmptyString, wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT96"));
    StaticText96->SetForegroundColour(wxColor(68,68,68));
    StaticText97 = new wxStaticText(panelTBM, ID_STATICTEXT97, wxEmptyString, wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT97"));
    StaticText97->SetForegroundColour(wxColor(68,68,68));
    StaticText98 = new wxStaticText(panelTBM, ID_STATICTEXT98, wxEmptyString, wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT98"));
    StaticText98->SetForegroundColour(wxColor(68,68,68));
    midf_checkbox = new wxCheckBox(panelTBM,ID_CHECKBOX28,_("盾首铰接"),wxPoint(120,205),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX28"));
	midf_checkbox->SetForegroundColour(wxColor(68,68,68));
	midb_checkbox = new wxCheckBox(panelTBM,ID_CHECKBOX29,_("盾尾铰接"),wxPoint(120,205),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX29"));
	midb_checkbox->SetForegroundColour(wxColor(68,68,68));
	midb_checkbox->SetValue(true);
    StaticText113 = new wxStaticText(panelTBM, ID_STATICTEXT113, wxEmptyString, wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT113"));
    StaticText113->SetForegroundColour(wxColor(68,68,68));
    StaticText121 = new wxStaticText(panelTBM, ID_STATICTEXT121, wxEmptyString, wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT121"));
    StaticText121->SetForegroundColour(wxColor(68,68,68));
    StaticText122 = new wxStaticText(panelTBM, ID_STATICTEXT122, wxEmptyString, wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT122"));
    StaticText122->SetForegroundColour(wxColor(68,68,68));
    StaticText123 = new wxStaticText(panelTBM, ID_STATICTEXT123, wxEmptyString, wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT123"));
    StaticText123->SetForegroundColour(wxColor(68,68,68));
    StaticText124 = new wxStaticText(panelTBM, ID_STATICTEXT124, wxEmptyString, wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT124"));
    StaticText124->SetForegroundColour(wxColor(68,68,68));
    mid_data_checkbox = new wxCheckBox(panelTBM,ID_CHECKBOX32,_("手动设置铰接油缸行程值"),wxPoint(120,205),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX32"));
	mid_data_checkbox->SetForegroundColour(wxColor(68,68,68));
	mid_data_checkbox->SetValue(false);
	mid_value_text1 = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL116, wxEmptyString, wxPoint(120,45), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL116"));
	mid_value_text2 = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL117, wxEmptyString, wxPoint(120,45), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL117"));
	mid_value_text3 = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL118, wxEmptyString, wxPoint(120,45), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL118"));
	mid_value_text4 = new wxMyTextCtrl(panelTBM, ID_TEXTCTRL119, wxEmptyString, wxPoint(120,45), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL119"));

    StaticText99 = new wxStaticText(panelTarget, ID_STATICTEXT99, _("配置文件"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT99"));
    StaticText18 = new wxStaticText(panelTarget, ID_STATICTEXT18, _("配置文件"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT18"));
	StaticText18->SetForegroundColour(wxColor(68,68,68));
	tar_file = new wxMyTextCtrl(panelTarget, ID_TEXTCTRL12, wxEmptyString, wxPoint(120,20), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    tar_file->Enable(false);
    btnImportPara = new wxButton(panelTarget, ID_BUTTON6, _("导入配置文件"), wxPoint(320,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    btnImportPara->SetForegroundColour(wxColor(68,68,68));
    StaticText19 = new wxStaticText(panelTarget, ID_STATICTEXT19, _("棱镜常数"), wxPoint(25,70),wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    StaticText19->SetForegroundColour(wxColor(68,68,68));
    target_prism = new wxMyTextCtrl(panelTarget, ID_TEXTCTRL13, wxEmptyString, wxPoint(120,65), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));


    StaticText22 = new wxStaticText(panelTheo, ID_STATICTEXT22, _("激光类型"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    StaticText22->SetForegroundColour(wxColor(68,68,68));
    StaticText100 = new wxStaticText(panelTheo, ID_STATICTEXT100, _("激光类型"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT100"));
    StaticText100->SetForegroundColour(wxColor(68,68,68));
    //laserChoice = new wxChoice(panelTheo, ID_CHOICE2, wxPoint(120,20), wxSize(180,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    //laserChoice->SetSelection( laserChoice->Append(_("徕卡GUS74专用激光")) );
    //laserChoice->Append(_("全站仪同轴免棱镜激光"));
    //laserChoice->Append(_("用户自定义激光"));
    //laserChoice->Show(false);

    gus_laser_checkbox = new wxCheckBox(panelTheo,ID_CHECKBOX18,_("GUS74激光"),wxPoint(120,160),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX18"));
    ref_laser_checkbox = new wxCheckBox(panelTheo,ID_CHECKBOX19,_("同轴激光"),wxPoint(120,160),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX19"));
    user_laser_checkbox = new wxCheckBox(panelTheo,ID_CHECKBOX20,_("自定义激光"),wxPoint(120,160),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX20"));
    //laserType1 = new wxRadioButton(panelTheo,ID_RADIOBUTTON8,_("全站仪同轴免棱镜激光"),wxPoint(120,25), wxDefaultSize,0, wxDefaultValidator, _T("ID_RADIOBUTTON8"));
    //laserType2 = new wxRadioButton(panelTheo,ID_RADIOBUTTON9,_("徕卡GUS74专用激光"),wxPoint(120,50), wxDefaultSize,0, wxDefaultValidator, _T("ID_RADIOBUTTON9"));
    //laserType3 = new wxRadioButton(panelTheo,ID_RADIOBUTTON10,_("用户自定义激光"),wxPoint(120,75), wxDefaultSize,0, wxDefaultValidator, _T("ID_RADIOBUTTON10"));
    //laserType1->SetValue(true);
    tps_laserh = new wxMyTextCtrl(panelTheo, ID_TEXTCTRL14, wxEmptyString, wxPoint(120,75), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));

    StaticText23 = new wxStaticText(panelTheo, ID_STATICTEXT23, _("激光高度(单位:mm)。"), wxPoint(120,55),wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    StaticText23->SetForegroundColour(wxColor(68,68,68));
    StaticText24 = new wxStaticText(panelTheo, ID_STATICTEXT24, _("激光矫正"), wxPoint(25,125),wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    StaticText24->SetForegroundColour(wxColor(68,68,68));
    StaticText25 = new wxStaticText(panelTheo, ID_STATICTEXT25, _("矫正距离(单位:m)"), wxPoint(120,125),wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    StaticText25->SetForegroundColour(wxColor(68,68,68));
    tps_laserd = new wxMyTextCtrl(panelTheo, ID_TEXTCTRL15, wxEmptyString, wxPoint(120,145), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    StaticText26 = new wxStaticText(panelTheo, ID_STATICTEXT26, _("水平矫正X(单位:mm)"), wxPoint(120,180),wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    StaticText26->SetForegroundColour(wxColor(68,68,68));
    tps_laserx = new wxMyTextCtrl(panelTheo, ID_TEXTCTRL16, wxEmptyString, wxPoint(120,200), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    StaticText27 = new wxStaticText(panelTheo, ID_STATICTEXT27, _("垂直矫正Y(单位:mm)"), wxPoint(120,235),wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    StaticText27->SetForegroundColour(wxColor(68,68,68));
    tps_lasery = new wxMyTextCtrl(panelTheo, ID_TEXTCTRL17, wxEmptyString, wxPoint(120,255), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    panelLasercorr = new wxPanel(panelTheo, ID_PANEL29, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL29"));
    panelLasercorr->SetSize(360,145,180,135);

    StaticText28 = new wxStaticText(panelSeg, ID_STATICTEXT28, _("管环参数"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT28"));
	StaticText28->SetForegroundColour(wxColor(68,68,68));
	StaticText29 = new wxStaticText(panelSeg, ID_STATICTEXT29, _("管环宽度(单位:m)"), wxPoint(120,25),wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    StaticText29->SetForegroundColour(wxColor(68,68,68));
    seg_len = new wxMyTextCtrl(panelSeg, ID_TEXTCTRL3, wxEmptyString, wxPoint(120,45), wxSize(180,-1),0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticText30 = new wxStaticText(panelSeg, ID_STATICTEXT30, _("管环内径(单位:m)"), wxPoint(360,25),wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    StaticText30->SetForegroundColour(wxColor(68,68,68));
    seg_r = new wxMyTextCtrl(panelSeg, ID_TEXTCTRL4, wxEmptyString, wxPoint(360,45), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    StaticText31 = new wxStaticText(panelSeg, ID_STATICTEXT31, _("管环厚度(单位:mm)"), wxPoint(120,80),wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    StaticText31->SetForegroundColour(wxColor(68,68,68));
    segThick = new wxMyTextCtrl(panelSeg, ID_TEXTCTRL48, wxEmptyString, wxPoint(120,100), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL48"));
    StaticText62 = new wxStaticText(panelSeg, ID_STATICTEXT62, _("最小旋转角(°)"), wxPoint(360,80),wxDefaultSize, 0, _T("ID_STATICTEXT62"));
    StaticText62->SetForegroundColour(wxColor(68,68,68));
    segScrow = new wxMyTextCtrl(panelSeg, ID_TEXTCTRL49, wxEmptyString, wxPoint(360,100), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL49"));
    StaticText81 = new wxStaticText(panelSeg, ID_STATICTEXT81, _("标准盾尾间隙(单位:mm)"), wxPoint(120,135),wxDefaultSize, 0, _T("ID_STATICTEXT81"));
    StaticText81->SetForegroundColour(wxColor(68,68,68));
    std_gap_text = new wxMyTextCtrl(panelSeg, ID_TEXTCTRL62, wxEmptyString, wxPoint(120,155), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL62"));
    StaticText82 = new wxStaticText(panelSeg, ID_STATICTEXT82, _("最小盾尾间隙(单位:mm)"), wxPoint(360,135),wxDefaultSize, 0, _T("ID_STATICTEXT82"));
    StaticText82->SetForegroundColour(wxColor(68,68,68));
    min_gap_text = new wxMyTextCtrl(panelSeg, ID_TEXTCTRL63, wxEmptyString, wxPoint(360,155), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL63"));

    StaticText63 = new wxStaticText(panelSeg, ID_STATICTEXT63, _("管环拼装"), wxPoint(25,210),wxDefaultSize, 0, _T("ID_STATICTEXT63"));
    StaticText63->SetForegroundColour(wxColor(68,68,68));
    StaticText65 = new wxStaticText(panelSeg, ID_STATICTEXT65, _("管片楔形量(单位:mm)"), wxPoint(120,265),wxDefaultSize, 0, _T("ID_STATICTEXT65"));
    StaticText65->SetForegroundColour(wxColor(68,68,68));
    StaticText66 = new wxStaticText(panelSeg, ID_STATICTEXT66, _("管环拼装方式"), wxPoint(120,210),wxDefaultSize, 0, _T("ID_STATICTEXT66"));
    StaticText66->SetForegroundColour(wxColor(68,68,68));
    methodChoice = new wxChoice(panelSeg, ID_CHOICE3, wxPoint(120,230), wxSize(180,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    methodChoice->SetSelection( methodChoice->Append(_("通用环")) );
    methodChoice->Append(_("标准环+转弯环"));
    StaticText67 = new wxStaticText(panelSeg, ID_STATICTEXT67, _("楔形类型"), wxPoint(360,210),wxDefaultSize, 0, _T("ID_STATICTEXT67"));
    StaticText67->SetForegroundColour(wxColor(68,68,68));
    WedgeChoice = new wxChoice(panelSeg, ID_CHOICE4, wxPoint(360,230), wxSize(180,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    WedgeChoice->SetSelection( WedgeChoice->Append(_("等腰梯形")) );
    WedgeChoice->Append(_("直角梯形"));
    Wedge_Text = new wxMyTextCtrl(panelSeg, ID_TEXTCTRL50, wxEmptyString, wxPoint(120,285), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL50"));
    StaticText91 = new wxStaticText(panelSeg, ID_STATICTEXT91, _("错缝条件"), wxPoint(25,335),wxDefaultSize, 0, _T("ID_STATICTEXT91"));
    StaticText91->SetForegroundColour(wxColor(68,68,68));
    StaticText92 = new wxStaticText(panelSeg, ID_STATICTEXT92, _("错缝角度大于(°)"), wxPoint(120,335),wxDefaultSize, 0, _T("ID_STATICTEXT92"));
    StaticText92->SetForegroundColour(wxColor(68,68,68));
    gapangle_text = new wxMyTextCtrl(panelSeg, ID_TEXTCTRL67, wxEmptyString, wxPoint(120,355), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL67"));
    //seguniv=new wxRadioButton(panelSeg,ID_RADIOBUTTON16,_("通用环管片"),wxPoint(320,235), wxDefaultSize,0, wxDefaultValidator, _T("ID_RADIOBUTTON16"));
    //segstdandturn=new wxRadioButton(panelSeg,ID_RADIOBUTTON17,_("标准化+转弯环"),wxPoint(120,235), wxDefaultSize,0, wxDefaultValidator, _T("ID_RADIOBUTTON17"));
    seg_method1_checkbox = new wxCheckBox(panelSeg,ID_CHECKBOX21,_("通用环"),wxPoint(120,160),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX21"));
    seg_method2_checkbox = new wxCheckBox(panelSeg,ID_CHECKBOX22,_("标准环+转弯环"),wxPoint(120,160),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX22"));
    seg_wedge1_checkbox = new wxCheckBox(panelSeg,ID_CHECKBOX23,_("等腰梯形"),wxPoint(120,160),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX23"));
    seg_wedge2_checkbox = new wxCheckBox(panelSeg,ID_CHECKBOX24,_("直角梯形"),wxPoint(120,160),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX24"));
    seg_method1_checkbox->SetForegroundColour(wxColor(68,68,68));
    seg_method2_checkbox->SetForegroundColour(wxColor(68,68,68));
    seg_wedge1_checkbox->SetForegroundColour(wxColor(68,68,68));
    seg_wedge2_checkbox->SetForegroundColour(wxColor(68,68,68));
    //stdWedge = new wxMyTextCtrl(panelSeg, ID_TEXTCTRL52, wxEmptyString, wxPoint(120,340), wxSize(140,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL52"));

    //StaticText69->Enable(false);

    StaticText80 = new wxStaticText(panelBlock, ID_STATICTEXT80, _("管块参数"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT80"));
    StaticText80->SetForegroundColour(wxColor(68,68,68));
    listBlock = new wxListView(panelBlock,ID_LIST1,wxPoint(120,20),wxSize(360,180),wxLC_REPORT, wxDefaultValidator,_T("ID_LIST1"));
    listBlock->SetForegroundColour(wxColor(68,68,68));
    btnAddBlock = new wxButton(panelBlock, ID_BUTTON8, _("添加"), wxPoint(505,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    btnAddBlock->SetForegroundColour(wxColor(68,68,68));
    btnEditBlock = new wxButton(panelBlock, ID_BUTTON12, _("编辑"), wxPoint(505,55), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
    btnEditBlock->SetForegroundColour(wxColor(68,68,68));
    btnEditBlock->Enable(false);
    btnDelBlock = new wxButton(panelBlock, ID_BUTTON13, _("删除"), wxPoint(505,90), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON13"));
    btnDelBlock->SetForegroundColour(wxColor(68,68,68));
    btnDelBlock->Enable(false);
    StaticText69 = new wxStaticText(panelBlock, ID_STATICTEXT69, _("管块示意"), wxPoint(25,225),wxDefaultSize, 0, _T("ID_STATICTEXT69"));
    StaticText69->SetForegroundColour(wxColor(68,68,68));
    GraphBlock = new wxPanel(panelBlock, ID_PANEL28, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL28"));
    GraphBlock->SetSize(120,220,360,230);
    //listSegClass->InsertColumn(0,_("序号"),wxLIST_FORMAT_CENTER,50);
    //listSegClass->InsertColumn(1,_("类型"),wxLIST_FORMAT_CENTER,75);
    //listSegClass->InsertColumn(2,_("楔形类型"),wxLIST_FORMAT_CENTER,75);
    //listSegClass->InsertColumn(3,_("楔形量"),wxLIST_FORMAT_CENTER,75);
    //btnAddSeg = new wxButton(panelSeg, ID_BUTTON9, _("添加"), wxPoint(420,270), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    //btnEditSeg = new wxButton(panelSeg, ID_BUTTON10, _("编辑"), wxPoint(420,305), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
    //btnDelSeg = new wxButton(panelSeg, ID_BUTTON11, _("删除"), wxPoint(420,345), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));

    StaticText32 = new wxStaticText(panelOri, ID_STATICTEXT32, _("盾构机初始参数设置"), wxPoint(35,25),wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    StaticText32->SetForegroundColour(wxColor(68,68,68));
    StaticText33 = new wxStaticText(panelOri, ID_STATICTEXT33, _("切口位置"), wxPoint(45,50),wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    StaticText33->SetForegroundColour(wxColor(68,68,68));
    StaticText70 = new wxStaticText(panelOri, ID_STATICTEXT70, _("X"), wxPoint(45,80),wxDefaultSize, 0, _T("ID_STATICTEXT70"));
    StaticText70->SetForegroundColour(wxColor(68,68,68));
    StaticText71 = new wxStaticText(panelOri, ID_STATICTEXT71, _("Y"), wxPoint(45,110),wxDefaultSize, 0, _T("ID_STATICTEXT71"));
    StaticText71->SetForegroundColour(wxColor(68,68,68));
    StaticText72 = new wxStaticText(panelOri, ID_STATICTEXT72, _("Z"), wxPoint(45,140),wxDefaultSize, 0, _T("ID_STATICTEXT72"));
    StaticText72->SetForegroundColour(wxColor(68,68,68));
    headx_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL53, wxEmptyString, wxPoint(65,75), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL53"));
    heady_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL54, wxEmptyString, wxPoint(65,105), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL54"));
    headz_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL55, wxEmptyString, wxPoint(65,135), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL55"));
    StaticText73 = new wxStaticText(panelOri, ID_STATICTEXT73, _("盾尾位置"), wxPoint(405,50),wxDefaultSize, 0, _T("ID_STATICTEXT73"));
    StaticText73->SetForegroundColour(wxColor(68,68,68));
    StaticText74 = new wxStaticText(panelOri, ID_STATICTEXT70, _("X"), wxPoint(405,80),wxDefaultSize, 0, _T("ID_STATICTEXT74"));
    StaticText74->SetForegroundColour(wxColor(68,68,68));
    StaticText75 = new wxStaticText(panelOri, ID_STATICTEXT71, _("Y"), wxPoint(405,110),wxDefaultSize, 0, _T("ID_STATICTEXT75"));
    StaticText75->SetForegroundColour(wxColor(68,68,68));
    StaticText76 = new wxStaticText(panelOri, ID_STATICTEXT72, _("Z"), wxPoint(405,140),wxDefaultSize, 0, _T("ID_STATICTEXT76"));
    StaticText76->SetForegroundColour(wxColor(68,68,68));
    tailx_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL56, wxEmptyString, wxPoint(425,75), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL56"));
    taily_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL57, wxEmptyString, wxPoint(425,105), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL57"));
    tailz_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL58, wxEmptyString, wxPoint(425,135), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL58"));


    StaticText34 = new wxStaticText(panelOri, ID_STATICTEXT34, _("动角度"), wxPoint(45,208),wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    StaticText34->SetForegroundColour(wxColor(68,68,68));
    tbmroll_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL24, wxEmptyString, wxPoint(100,203), wxSize(70,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL24"));
    StaticText36 = new wxStaticText(panelOri, ID_STATICTEXT36, _("激光靶"), wxPoint(25,225),wxDefaultSize, 0, _T("ID_STATICTEXT36"));
    StaticText36->SetForegroundColour(wxColor(68,68,68));
    StaticText37 = new wxStaticText(panelOri, ID_STATICTEXT37, _("激光靶位置(单位:m)"), wxPoint(140,225),wxDefaultSize, 0, _T("ID_STATICTEXT37"));
    StaticText37->SetForegroundColour(wxColor(68,68,68));
    StaticText35 = new wxStaticText(panelOri, ID_STATICTEXT35, _("X"), wxPoint(120,250),wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    StaticText35->SetForegroundColour(wxColor(68,68,68));
    StaticText38 = new wxStaticText(panelOri, ID_STATICTEXT38, _("Y"), wxPoint(120,280),wxDefaultSize, 0, _T("ID_STATICTEXT38"));
    StaticText38->SetForegroundColour(wxColor(68,68,68));
    StaticText39 = new wxStaticText(panelOri, ID_STATICTEXT39, _("Z"), wxPoint(120,310),wxDefaultSize, 0, _T("ID_STATICTEXT39"));
    StaticText39->SetForegroundColour(wxColor(68,68,68));
    tarx_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL29, wxEmptyString, wxPoint(140,245), wxSize(140,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL29"));
    tary_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL30, wxEmptyString, wxPoint(140,275), wxSize(140,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL30"));
    tarz_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL31, wxEmptyString, wxPoint(140,305), wxSize(140,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL31"));

    StaticText41 = new wxStaticText(panelOri, ID_STATICTEXT41, _("激光靶姿态(°)"), wxPoint(360,225),wxDefaultSize, 0, _T("ID_STATICTEXT41"));
    StaticText41->SetForegroundColour(wxColor(68,68,68));
    StaticText40 = new wxStaticText(panelOri, ID_STATICTEXT40, _("方位"), wxPoint(320,250),wxDefaultSize, 0, _T("ID_STATICTEXT40"));
    StaticText40->SetForegroundColour(wxColor(68,68,68));
    StaticText61 = new wxStaticText(panelOri, ID_STATICTEXT61, _("俯仰"), wxPoint(320,280),wxDefaultSize, 0, _T("ID_STATICTEXT61"));
    StaticText61->SetForegroundColour(wxColor(68,68,68));
    StaticText6 = new wxStaticText(panelOri, ID_STATICTEXT6, _("转动"), wxPoint(320,310),wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText6->SetForegroundColour(wxColor(68,68,68));
    tarazi_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL32, wxEmptyString, wxPoint(360,245), wxSize(140,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL32"));
    tarpitch_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL33, wxEmptyString, wxPoint(360,275), wxSize(140,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL33"));
	tarroll_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL34, wxEmptyString, wxPoint(360,305), wxSize(140,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL34"));
    btnTarMeas = new wxButton(panelOri, ID_BUTTON7, _("测量"), wxPoint(515,245), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    btnTarMeas->SetForegroundColour(wxColor(68,68,68));
    StaticText101 = new wxStaticText(panelOri, ID_STATICTEXT101, _("铰接位置"), wxPoint(225,50),wxDefaultSize, 0, _T("ID_STATICTEXT101"));
    StaticText101->SetForegroundColour(wxColor(68,68,68));
    StaticText102 = new wxStaticText(panelOri, ID_STATICTEXT102, _("X"), wxPoint(225,80),wxDefaultSize, 0, _T("ID_STATICTEXT102"));
    StaticText102->SetForegroundColour(wxColor(68,68,68));
    StaticText103 = new wxStaticText(panelOri, ID_STATICTEXT103, _("Y"), wxPoint(225,110),wxDefaultSize, 0, _T("ID_STATICTEXT103"));
    StaticText103->SetForegroundColour(wxColor(68,68,68));
    StaticText104 = new wxStaticText(panelOri, ID_STATICTEXT104, _("Z"), wxPoint(225,140),wxDefaultSize, 0, _T("ID_STATICTEXT104"));
    StaticText104->SetForegroundColour(wxColor(68,68,68));
    midx_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL99, wxEmptyString, wxPoint(245,75), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL99"));
    midy_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL100, wxEmptyString, wxPoint(245,105), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL100"));
    midz_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL101, wxEmptyString, wxPoint(245,135), wxSize(90,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL101"));
    StaticText105 = new wxStaticText(panelOri, ID_STATICTEXT105, _("盾构姿态角"), wxPoint(45,178),wxDefaultSize, 0, _T("ID_STATICTEXT105"));
    StaticText105->SetForegroundColour(wxColor(68,68,68));
    StaticText106 = new wxStaticText(panelOri, ID_STATICTEXT106, _("俯仰角"), wxPoint(220,208),wxDefaultSize, 0, _T("ID_STATICTEXT106"));
    StaticText106->SetForegroundColour(wxColor(68,68,68));
    StaticText107 = new wxStaticText(panelOri, ID_STATICTEXT107, _("方位角"), wxPoint(395,208),wxDefaultSize, 0, _T("ID_STATICTEXT107"));
    StaticText107->SetForegroundColour(wxColor(68,68,68));
    tbm_pitch_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL102, wxEmptyString, wxPoint(275,203), wxSize(70,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL102"));
    tbm_pitch_text->SetEditable(false);
    tbm_azi_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL103, wxEmptyString, wxPoint(450,303), wxSize(70,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL103"));
    tbm_azi_text->SetEditable(false);
    up_mid_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL104, wxEmptyString, wxPoint(65,266), wxSize(60,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL104"));
    down_mid_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL105, wxEmptyString, wxPoint(195,266), wxSize(60,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL105"));
    left_mid_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL106, wxEmptyString, wxPoint(325,266), wxSize(60,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL106"));
    right_mid_text = new wxMyTextCtrl(panelOri, ID_TEXTCTRL107, wxEmptyString, wxPoint(455,266), wxSize(60,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL107"));
    //up_mid_text->SetEditable(false);
    //down_mid_text->SetEditable(false);
    //left_mid_text->SetEditable(false);
    //right_mid_text->SetEditable(false);
    StaticText108 = new wxStaticText(panelOri, ID_STATICTEXT108, _("铰接油缸设置"), wxPoint(45,241),wxDefaultSize, 0, _T("ID_STATICTEXT108"));
    StaticText108->SetForegroundColour(wxColor(68,68,68));
    StaticText109 = new wxStaticText(panelOri, ID_STATICTEXT109, _("上"), wxPoint(45,271),wxDefaultSize, 0, _T("ID_STATICTEXT109"));
    StaticText109->SetForegroundColour(wxColor(68,68,68));
    StaticText110 = new wxStaticText(panelOri, ID_STATICTEXT110, _("下"), wxPoint(175,271),wxDefaultSize, 0, _T("ID_STATICTEXT110"));
    StaticText110->SetForegroundColour(wxColor(68,68,68));
    StaticText111 = new wxStaticText(panelOri, ID_STATICTEXT111, _("左"), wxPoint(305,271),wxDefaultSize, 0, _T("ID_STATICTEXT111"));
    StaticText111->SetForegroundColour(wxColor(68,68,68));
    StaticText112 = new wxStaticText(panelOri, ID_STATICTEXT112, _("右"), wxPoint(435,271),wxDefaultSize, 0, _T("ID_STATICTEXT112"));
    StaticText112->SetForegroundColour(wxColor(68,68,68));

    StaticText43 = new wxStaticText(panelMeas, ID_STATICTEXT43, _("测量间隔"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT43"));
    StaticText43->SetForegroundColour(wxColor(68,68,68));
    StaticText47 = new wxStaticText(panelMeas, ID_STATICTEXT47, _("姿态测量(单位:秒)"), wxPoint(120,25),wxDefaultSize, 0, _T("ID_STATICTEXT47"));
    StaticText47->SetForegroundColour(wxColor(68,68,68));
    measTime1 = new wxMyTextCtrl(panelMeas, ID_TEXTCTRL37, wxEmptyString, wxPoint(120,45), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL37"));
    StaticText48 = new wxStaticText(panelMeas, ID_STATICTEXT48, _("后视检核(单位:秒)"), wxPoint(360,25),wxDefaultSize, 0, _T("ID_STATICTEXT48"));
    StaticText48->SetForegroundColour(wxColor(68,68,68));
    measTime2 = new wxMyTextCtrl(panelMeas, ID_TEXTCTRL38, wxEmptyString, wxPoint(360,45), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL38"));
    StaticText49 = new wxStaticText(panelMeas, ID_STATICTEXT49, _("警告设置"), wxPoint(25,95),wxDefaultSize, 0, _T("ID_STATICTEXT49"));
	StaticText49->SetForegroundColour(wxColor(68,68,68));
	StaticText50 = new wxStaticText(panelMeas, ID_STATICTEXT50, _("平面偏差大于(单位:mm)"), wxPoint(120,95),wxDefaultSize, 0, _T("ID_STATICTEXT50"));
	StaticText50->SetForegroundColour(wxColor(68,68,68));
	horiDiff = new wxMyTextCtrl(panelMeas, ID_TEXTCTRL39, wxEmptyString, wxPoint(120,115), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL39"));
    StaticText51 = new wxStaticText(panelMeas, ID_STATICTEXT51, _("高程偏差大于(单位:mm)"), wxPoint(360,95),wxDefaultSize, 0, _T("ID_STATICTEXT51"));
    StaticText51->SetForegroundColour(wxColor(68,68,68));
    verDiff = new wxMyTextCtrl(panelMeas, ID_TEXTCTRL40, wxEmptyString, wxPoint(360,115), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL40"));
    StaticText52 = new wxStaticText(panelMeas, ID_STATICTEXT52, _("姿态偏差大于(单位:mm/m)"), wxPoint(120,150),wxDefaultSize, 0, _T("ID_STATICTEXT52"));
    StaticText52->SetForegroundColour(wxColor(68,68,68));
    angleDiff = new wxMyTextCtrl(panelMeas, ID_TEXTCTRL41, wxEmptyString, wxPoint(120,170), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL41"));
    StaticText53 = new wxStaticText(panelMeas, ID_STATICTEXT53, _("偏差变化大于(单位:mm)"), wxPoint(360,150),wxDefaultSize, 0, _T("ID_STATICTEXT53"));
    StaticText53->SetForegroundColour(wxColor(68,68,68));
    diffChange = new wxMyTextCtrl(panelMeas, ID_TEXTCTRL42, wxEmptyString, wxPoint(360,170), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL42"));
    StaticText54 = new wxStaticText(panelMeas, ID_STATICTEXT54, _("后视位置变化大于(单位:mm)"), wxPoint(120,205),wxDefaultSize, 0, _T("ID_STATICTEXT54"));
    StaticText54->SetForegroundColour(wxColor(68,68,68));
    backDiff = new wxMyTextCtrl(panelMeas, ID_TEXTCTRL43, wxEmptyString, wxPoint(120,225), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL43"));
    StaticText21 = new wxStaticText(panelMeas, ID_STATICTEXT21, _("测量间隔时间大于(单位：秒)"), wxPoint(360,205),wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    StaticText21->SetForegroundColour(wxColor(68,68,68));
    tolTime = new wxMyTextCtrl(panelMeas, ID_TEXTCTRL91, wxEmptyString, wxPoint(360,225), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL91"));

    StaticText77 = new wxStaticText(panelMeas, ID_STATICTEXT77, _("纠偏设置"), wxPoint(25,275),wxDefaultSize, 0, _T("ID_STATICTEXT77"));
    StaticText77->SetForegroundColour(wxColor(68,68,68));
    StaticText78 = new wxStaticText(panelMeas, ID_STATICTEXT78, _("纠偏至设计轴线的距离(单位:m)"), wxPoint(120,275),wxDefaultSize, 0, _T("ID_STATICTEXT78"));
    StaticText78->SetForegroundColour(wxColor(68,68,68));
    corr_dist_text = new wxMyTextCtrl(panelMeas, ID_TEXTCTRL59, wxEmptyString, wxPoint(120,295), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL59"));
    StaticText79 = new wxStaticText(panelMeas, ID_STATICTEXT79, _("每环管片盾构姿态最大纠偏偏差(单位:mm)"), wxPoint(120,330),wxDefaultSize, 0, _T("ID_STATICTEXT79"));
    StaticText79->SetForegroundColour(wxColor(68,68,68));
    corr_diff_text = new wxMyTextCtrl(panelMeas, ID_TEXTCTRL60, wxEmptyString, wxPoint(120,350), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL60"));

    //corr_nfit_text = new wxMyTextCtrl(panelMeas, ID_TEXTCTRL61, wxEmptyString, wxPoint(120,405), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL61"));


    //autoBackup = new wxCheckBox(panelDb,ID_CHECKBOX1,_("自动备份"),wxPoint(120,25),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX1"));
	//autoBackup->SetValue(true);

	//btnBrowse = new wxButton(panelDb, ID_BUTTON4, _("浏览"), wxPoint(370,70), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    //btnBrowse->SetForegroundColour(wxColor(68,68,68));
    //btnOpenFolder = new wxButton(panelDb, ID_BUTTON5, _("打开文件夹"), wxPoint(450,70), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    //btnOpenFolder->SetForegroundColour(wxColor(68,68,68));


    //report_path_text = new wxMyTextCtrl(panelDb, ID_TEXTCTRL67, wxEmptyString, wxPoint(120,195), wxSize(240,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL67"));
    //report_path_text->Enable(false);

    //btnReportPathOpen = new wxButton(panelDb, ID_BUTTON15, _("打开文件夹"), wxPoint(450,195), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON15"));
    //btnReportPathOpen->SetForegroundColour(wxColor(68,68,68));

    //StaticText85 = new wxStaticText(panelDb, ID_STATICTEXT85, _("数据存储管理"), wxPoint(35,25),wxDefaultSize, 0, _T("ID_STATICTEXT85"));
    //StaticText85->SetForegroundColour(wxColor(68,68,68));
    //remoteselected = new wxCheckBox(panelDb,ID_CHECKBOX13,_("启用远程监控"),wxPoint(120,245),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX13"));
    //remoteselected->SetForegroundColour(wxColor(68,68,68));
    //StaticText86 = new wxStaticText(panelDb, ID_STATICTEXT86, _("数据量备份路径"), wxPoint(35,60),wxDefaultSize, 0, _T("ID_STATICTEXT86"));
    //StaticText86->SetForegroundColour(wxColor(68,68,68));
    //report_path_text = new wxMyTextCtrl(panelDb, ID_TEXTCTRL108, wxEmptyString, wxPoint(180,90), wxSize(240,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL108"));
    //db_backuppath_text = new wxMyTextCtrl(panelDb, ID_TEXTCTRL109, wxEmptyString, wxPoint(180,55), wxSize(240,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL109"));
    //report_path_text->SetEditable(false);
    //db_backuppath_text->SetEditable(false);
    client_ip_text1 = new wxMyTextCtrl(panelDb, ID_TEXTCTRL65, wxEmptyString, wxPoint(180,226), wxSize(40,20), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL65"));
    client_ip_text2 = new wxMyTextCtrl(panelDb, ID_TEXTCTRL110, wxEmptyString, wxPoint(224,226), wxSize(40,20), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL110"));
    client_ip_text3 = new wxMyTextCtrl(panelDb, ID_TEXTCTRL111, wxEmptyString, wxPoint(268,226), wxSize(40,20), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL111"));
    client_ip_text4 = new wxMyTextCtrl(panelDb, ID_TEXTCTRL112, wxEmptyString, wxPoint(312,226), wxSize(40,20), wxBORDER_NONE | wxTE_CENTER | wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL112"));
    client_ip_text1->SetMaxLength(3);
    client_ip_text2->SetMaxLength(3);
    client_ip_text3->SetMaxLength(3);
    client_ip_text4->SetMaxLength(3);

    //StaticText87 = new wxStaticText(panelDb, ID_STATICTEXT87, _("报表生成路径"), wxPoint(35,95),wxDefaultSize, 0, _T("ID_STATICTEXT87"));
    //StaticText87->SetForegroundColour(wxColor(68,68,68));
    //readdatatotbm = new wxCheckBox(panelDb,ID_CHECKBOX14,_("从盾构PLC读取数据"),wxPoint(120,150),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX14"));
    //readdatatotbm->SetForegroundColour(wxColor(68,68,68));
    //writedatatotbm = new wxCheckBox(panelDb,ID_CHECKBOX15,_("从盾构PLC读取数据"),wxPoint(120,175),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX15"));
    //writedatatotbm->SetForegroundColour(wxColor(68,68,68));
    StaticText90 = new wxStaticText(panelDb, ID_STATICTEXT90, _("远程控制设置"), wxPoint(35,153),wxDefaultSize, 0, _T("ID_STATICTEXT90"));
    StaticText90->SetForegroundColour(wxColor(68,68,68));

    StaticText116 = new wxStaticText(panelDb, ID_STATICTEXT116, _("控制模式"), wxPoint(35,188),wxDefaultSize, 0, _T("ID_STATICTEXT116"));
    StaticText116->SetForegroundColour(wxColor(68,68,68));

    StaticText117 = new wxStaticText(panelDb, ID_STATICTEXT117, _("客户端IP"), wxPoint(35,226),wxDefaultSize, 0, _T("ID_STATICTEXT117"));
    StaticText117->SetForegroundColour(wxColor(68,68,68));
    StaticText118 = new wxStaticText(panelDb, ID_STATICTEXT118, _("."), wxPoint(220,226),wxDefaultSize, 0, _T("ID_STATICTEXT118"));
    StaticText118->SetForegroundColour(wxColor(68,68,68));

    StaticText119 = new wxStaticText(panelDb, ID_STATICTEXT119, _("."), wxPoint(264,226),wxDefaultSize, 0, _T("ID_STATICTEXT119"));
    StaticText119->SetForegroundColour(wxColor(68,68,68));
    StaticText120 = new wxStaticText(panelDb, ID_STATICTEXT120, _("."), wxPoint(308,226),wxDefaultSize, 0, _T("ID_STATICTEXT120"));
    StaticText120->SetForegroundColour(wxColor(68,68,68));

    control_checkbox1 = new wxCheckBox(panelDb,ID_CHECKBOX30,_("服务器操作模式"),wxPoint(120,90),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX30"));
	control_checkbox1->SetForegroundColour(wxColor(68,68,68));
	control_checkbox1->SetValue(true);

	control_checkbox2 = new wxCheckBox(panelDb,ID_CHECKBOX31,_("远程操作模式"),wxPoint(120,120),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX31"));
	control_checkbox2->SetForegroundColour(wxColor(68,68,68));
	control_checkbox2->SetValue(false);

    //btnDbPath = new wxButton(panelDb, ID_BUTTON28, _("浏览"), wxPoint(440,55), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON28"));
    //btnDbPath->SetForegroundColour(wxColor(68,68,68));
    //btnRtPath = new wxButton(panelDb, ID_BUTTON29, _("浏览"), wxPoint(440,90), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON29"));
    //btnRtPath->SetForegroundColour(wxColor(68,68,68));


    listUser = new wxListView(panelUser,ID_LIST3,wxPoint(120,20),wxSize(360,180),wxLC_REPORT, wxDefaultValidator,_T("ID_LIST3"));
    listUser->SetForegroundColour(wxColor(68,68,68));
    StaticText58= new wxStaticText(panelUser, ID_STATICTEXT58, _("管理员"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT58"));
    StaticText58->SetForegroundColour(wxColor(68,68,68));
    btnAddUser = new wxButton(panelUser,ID_BUTTON17, _("添加"), wxPoint(505,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON17"));
    btnAddUser->SetForegroundColour(wxColor(68,68,68));
    btnEditUser = new wxButton(panelUser, ID_BUTTON18, _("编辑"), wxPoint(505,55), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON18"));
    btnEditUser->SetForegroundColour(wxColor(68,68,68));
    btnEditUser->Enable(false);
    btnDelUser = new wxButton(panelUser, ID_BUTTON19, _("删除"), wxPoint(505,90), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON19"));
    btnDelUser->SetForegroundColour(wxColor(68,68,68));
    btnDelUser->Enable(false);

    //StaticText59 = new wxStaticText(panelUser, ID_STATICTEXT59, _("原密码"), wxPoint(120,25),wxDefaultSize, 0, _T("ID_STATICTEXT59"));
    //StaticText59->SetForegroundColour(wxColor(68,68,68));
    //old_manager_password = new wxMyTextCtrl(panelUser, ID_TEXTCTRL44, wxEmptyString, wxPoint(120,45), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL44"));

    //new_manager_password = new wxMyTextCtrl(panelUser, ID_TEXTCTRL18, wxEmptyString, wxPoint(120,45), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));

    //manager_password_confirm = new wxMyTextCtrl(panelUser, ID_TEXTCTRL19, wxEmptyString, wxPoint(120,100), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    //StaticText68 = new wxStaticText(panelUser, ID_STATICTEXT68, _("操作员"), wxPoint(25,150),wxDefaultSize, 0, _T("ID_STATICTEXT68"));
    //StaticText68->SetForegroundColour(wxColor(68,68,68));
    //StaticText56 = new wxStaticText(panelUser, ID_STATICTEXT56, _("原密码"), wxPoint(120,150),wxDefaultSize, 0, _T("ID_STATICTEXT56"));
    //StaticText56->SetForegroundColour(wxColor(68,68,68));
    //old_operator_password = new wxMyTextCtrl(panelUser, ID_TEXTCTRL45, wxEmptyString, wxPoint(120,170), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL45"));
    //StaticText57 = new wxStaticText(panelUser, ID_STATICTEXT57, _("新授权密码"), wxPoint(120,150),wxDefaultSize, 0, _T("ID_STATICTEXT57"));
    //StaticText57->SetForegroundColour(wxColor(68,68,68));
    //new_operator_password = new wxMyTextCtrl(panelUser, ID_TEXTCTRL20, wxEmptyString, wxPoint(120,170), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
    //StaticText5 = new wxStaticText(panelUser, ID_STATICTEXT5, _("新授权密码确认"), wxPoint(120,205),wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    //StaticText5->SetForegroundColour(wxColor(68,68,68));
    //operator_password_confirm = new wxMyTextCtrl(panelUser, ID_TEXTCTRL21, wxEmptyString, wxPoint(120,225), wxSize(180,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL21"));

    StaticText60 = new wxStaticText(panelLang, ID_STATICTEXT60, _("系统语言"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT60"));
    StaticText60->SetForegroundColour(wxColor(68,68,68));
    StaticText55 = new wxStaticText(panelLang, ID_STATICTEXT55, _("新授权密码确认"), wxPoint(120,80),wxDefaultSize, 0, _T("ID_STATICTEXT55"));
    StaticText55->SetForegroundColour(wxColor(68,68,68));
    StaticText17 = new wxStaticText(panelLang, ID_STATICTEXT17, _("新授权密码"), wxPoint(120,25),wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    StaticText17->SetForegroundColour(wxColor(68,68,68));

    lang1_checkbox = new wxCheckBox(panelLang,ID_CHECKBOX25,_("简体中文"),wxPoint(120,160),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX25"));
    lang1_checkbox->SetForegroundColour(wxColor(68,68,68));
    lang2_checkbox = new wxCheckBox(panelLang,ID_CHECKBOX26,_("英文"),wxPoint(120,160),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX26"));
    lang2_checkbox->SetForegroundColour(wxColor(68,68,68));
    lang3_checkbox = new wxCheckBox(panelLang,ID_CHECKBOX27,_("繁体中文"),wxPoint(120,160),wxDefaultSize,0,wxDefaultValidator,_T("ID_CHECKBOX27"));
    lang3_checkbox->SetForegroundColour(wxColor(68,68,68));
    langChoice = new wxChoice(panelLang, ID_CHOICE5, wxPoint(120,20), wxSize(180,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
    langChoice->SetSelection( langChoice->Append(_("简体中文")) );
    langChoice->Append(_("英文"));
    langChoice->Append(_("繁体中文"));
    //chineseSimp = new wxRadioButton(panelLang,ID_RADIOBUTTON11,_("简体中文"),wxPoint(120,25), wxDefaultSize,0, wxDefaultValidator, _T("ID_RADIOBUTTON11"));
    //chinese = new wxRadioButton(panelLang,ID_RADIOBUTTON12,_("繁体中文"),wxPoint(120,50), wxDefaultSize,0, wxDefaultValidator, _T("ID_RADIOBUTTON12"));
    //english = new wxRadioButton(panelLang,ID_RADIOBUTTON13,_("英文"),wxPoint(120,75), wxDefaultSize,0, wxDefaultValidator, _T("ID_RADIOBUTTON13"));

	panelNavi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBorder1->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBorder1->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnPrj->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnKey->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnDatabase->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnTarget->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnTheodolite->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnSeg->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnOrigin->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnTBM->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnMeas->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnUser->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnLanguage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPrj->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

	panelNavi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintNavi,0,this);
	panelBorder1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintBorder1,0,this);
	panelBorder2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintBorder2,0,this);
    panelBtnPrj->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintBtnPrj,0,this);
    panelBtnKey->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintBtnKey,0,this);
    panelBtnDatabase->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintDatabase,0,this);
    panelBtnTarget->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintTarget,0,this);
    panelBtnTheodolite->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintTheodolite,0,this);
    panelBtnSeg->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintSeg,0,this);
    panelBtnBlock->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintBlock,0,this);
    panelBtnOrigin->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintOrigin,0,this);
    panelBtnTBM->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintBtnTBM,0,this);
    panelBtnMeas->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintMeas,0,this);
    panelBtnUser->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintUser,0,this);
    panelBtnLanguage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintLanguage,0,this);
    panelPrj->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintPrj,0,this);
    panelKey->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintKey,0,this);
    panelBtnArea->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintBtnArea,0,this);
    panelDb->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintDb,0,this);
    panelTarget->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintPanelTarget,0,this);
    panelTheo->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintPanelTheo,0,this);
    panelOri->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintPanelOri,0,this);
    panelTBM->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintPanelTBM,0,this);
    panelMeas->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintPanelMeas,0,this);
    panelUser->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintPanelUser,0,this);
    panelLang->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintPanelLang,0,this);
    panelSeg->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintPanelSeg,0,this);
    panelBlock->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintPanelBlock,0,this);
    GraphBlock->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintGraphBlock,0,this);
    panelLasercorr->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MySetupDialog::OnPaintLasercorr,0,this);

    panelBtnPrj->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnPrj,0,this);
    panelBtnPrj->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnPrj,0,this);
    panelBtnPrj->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnPrj,0,this);
    panelBtnPrj->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnPrjClick,0,this);

    panelBtnKey->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnKey,0,this);
    panelBtnKey->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnKey,0,this);
    panelBtnKey->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnKey,0,this);
    panelBtnKey->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnKeyClick,0,this);

    panelBtnDatabase->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnDatabase,0,this);
    panelBtnDatabase->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnDatabase,0,this);
    panelBtnDatabase->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnDatabase,0,this);
    panelBtnDatabase->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnDatabaseClick,0,this);

    panelBtnTarget->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnTarget,0,this);
    panelBtnTarget->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnTarget,0,this);
    panelBtnTarget->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnTarget,0,this);
    panelBtnTarget->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnTargetClick,0,this);

    panelBtnTheodolite->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnTheodolite,0,this);
    panelBtnTheodolite->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnTheodolite,0,this);
    panelBtnTheodolite->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnTheodolite,0,this);
    panelBtnTheodolite->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnTheodoliteClick,0,this);

    panelBtnSeg->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnSeg,0,this);
    panelBtnSeg->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnSeg,0,this);
    panelBtnSeg->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnSeg,0,this);
    panelBtnSeg->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnSegClick,0,this);

    panelBtnBlock->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnBlock,0,this);
    panelBtnBlock->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnBlock,0,this);
    panelBtnBlock->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnBlock,0,this);
    panelBtnBlock->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnBlockClick,0,this);

    panelBtnOrigin->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnOrigin,0,this);
    panelBtnOrigin->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnOrigin,0,this);
    panelBtnOrigin->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnOrigin,0,this);
    panelBtnOrigin->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnOriginClick,0,this);

    panelBtnTBM->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnTBM,0,this);
    panelBtnTBM->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnTBM,0,this);
    panelBtnTBM->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnTBM,0,this);
    panelBtnTBM->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnTBMClick,0,this);

    panelBtnMeas->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnMeas,0,this);
    panelBtnMeas->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnMeas,0,this);
    panelBtnMeas->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnMeas,0,this);
    panelBtnMeas->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnMeasClick,0,this);

    panelBtnUser->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnUser,0,this);
    panelBtnUser->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnUser,0,this);
    panelBtnUser->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnUser,0,this);
    panelBtnUser->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnUserClick,0,this);

    panelBtnLanguage->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnEnterBtnLanguage,0,this);
    panelBtnLanguage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MySetupDialog::OnLeaveBtnLanguage,0,this);
    panelBtnLanguage->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MySetupDialog::OnLeftDownBtnLanguage,0,this);
    panelBtnLanguage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnBtnLanguageClick,0,this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnQuit);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnApply);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnProj);

    Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnAddAreaClick);
    Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnEditAreaClick);
    Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnDeleAreaClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnAddBlockClick);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnEditBlockClick);
    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnDeleBlockClick);
    Connect(ID_BUTTON20,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnDayHourAddClick);
    Connect(ID_BUTTON21,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnDayHourSubClick);
    Connect(ID_BUTTON22,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnDayMinAddClick);
    Connect(ID_BUTTON23,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnDayMinSubClick);
    Connect(ID_BUTTON24,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnNightHourAddClick);
    Connect(ID_BUTTON25,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnNightHourSubClick);
    Connect(ID_BUTTON26,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnNightMinAddClick);
    Connect(ID_BUTTON27,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnNightMinSubClick);

    Connect(ID_LIST1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&MySetupDialog::OnListBlockItemActivated);
    Connect(ID_LIST1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&MySetupDialog::OnListBlockItemSelect);
    Connect(ID_LIST1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&MySetupDialog::OnListBlockItemDeselect);

    Connect(ID_LIST2,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&MySetupDialog::OnListAreaItemActivated);
    Connect(ID_LIST2,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&MySetupDialog::OnListAreaItemSelect);
    Connect(ID_LIST2,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&MySetupDialog::OnListAreaItemDeselect);

    ///工程界面
    //Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MySetupDialog::OnDirectSelect);
    Connect(ID_TEXTCTRL10,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeDayh);
    //Connect(ID_TEXTCTRL10,wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnDayhClick);
    //Connect(ID_TEXTCTRL5,wxEVT_LEFT_UP,(wxObjectEventFunction)&MySetupDialog::OnPrjNameClick);
    prj_name->Connect(wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnPrjNameClick ), NULL, this );
    Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangePrjName);
    prj_mile1->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnPrjMile1Click ), NULL, this );
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangePrjMile1);
    prj_mile2->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnPrjMile2Click ), NULL, this );
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangePrjMile2);
    day_hour->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnDayhClick ), NULL, this );
    day_min->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnDaymClick ), NULL, this );
    night_hour->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnNighthClick ), NULL, this );
    night_min->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnNightmClick ), NULL, this );
    Connect(ID_TEXTCTRL92,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeDaym);
    Connect(ID_TEXTCTRL11,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeNighth);
    Connect(ID_TEXTCTRL93,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeNightm);
    Connect(ID_TEXTCTRL51,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTip);
    Connect(ID_CHECKBOX16,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetForward);
    Connect(ID_CHECKBOX17,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetReverse);

    ///盾构界面
    TBM_index->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnTbmIndexClick ), NULL, this);
    tail_radius_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnTbmRadiusClick ), NULL, this);
    jointDist1->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnTbmDist1Click ), NULL, this);
    jack_radius_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnTbmJackrClick ), NULL, this);
    jointDist2->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnTbmDist2Click ), NULL, this);
    backjack_radius_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler( MySetupDialog::OnTbmMidjrClick ), NULL, this);
    Connect(ID_CHECKBOX28,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetFront);
    Connect(ID_CHECKBOX29,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetBack);
    Connect(ID_CHECKBOX32,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetMnual);

    Connect(ID_TEXTCTRL46,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTbmIndex);
    Connect(ID_TEXTCTRL64,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTbmRadius);
    Connect(ID_TEXTCTRL35,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTbmDist1);
    Connect(ID_TEXTCTRL96,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTbmJackr);
    Connect(ID_TEXTCTRL97,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTbmMidjr);

    ///激光靶
    Connect(ID_TEXTCTRL13,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangePrc);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnImportTarClick);
    ///全站仪
    //Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MySetupDialog::OnLaserSelect);
    Connect(ID_TEXTCTRL14,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeLaserh);
    Connect(ID_TEXTCTRL15,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeCorrdist);
    Connect(ID_TEXTCTRL16,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeCorrX);
    Connect(ID_TEXTCTRL17,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeCorrY);
    Connect(ID_CHECKBOX18,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetGus74Laser);
    Connect(ID_CHECKBOX19,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetCoaxLaser);
    Connect(ID_CHECKBOX20,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetUserLaser);
    tps_laserh->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnLaserhClick), NULL, this);
    tps_laserd->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnLaserdClick), NULL, this);
    tps_laserx->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnLaserxClick), NULL, this);
    tps_lasery->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnLaseryClick), NULL, this);
    ///管环设置
    seg_len->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnSeglenClick), NULL, this);
    seg_r->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnSegrClick), NULL, this);
    segThick->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnSegThickClick), NULL, this);
    segScrow->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnSegangleClick), NULL, this);
    std_gap_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnSegstdgapClick), NULL, this);
    min_gap_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnSegmingapClick), NULL, this);
    Wedge_Text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnSegwedgeClick), NULL, this);
    gapangle_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnGapangleClick), NULL, this);
    Connect(ID_CHECKBOX21,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::OnMethod1Click);
    Connect(ID_CHECKBOX22,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::OnMethod2Click);
    Connect(ID_CHECKBOX23,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::OnWedge1Click);
    Connect(ID_CHECKBOX24,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::OnWedge2Click);

    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeSeglen);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeSegr);
    Connect(ID_TEXTCTRL48,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeSegthick);
    Connect(ID_TEXTCTRL49,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeSegangle);
    Connect(ID_TEXTCTRL62,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeStdSeggap);
    Connect(ID_TEXTCTRL63,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeMinSeggap);
    Connect(ID_TEXTCTRL50,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeSegWedge);
    Connect(ID_TEXTCTRL67,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeGapangle);

    ///零位界面
    headx_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnHeadxClick), NULL, this);
    heady_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnHeadyClick), NULL, this);
    headz_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnHeadzClick), NULL, this);
    tailx_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnTailxClick), NULL, this);
    taily_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnTailyClick), NULL, this);
    tailz_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnTailzClick), NULL, this);
    tbmroll_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnTbmrollClick), NULL, this);
    tarx_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnTarxClick), NULL, this);
    tary_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnTaryClick), NULL, this);
    tarz_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnTarzClick), NULL, this);
    tarazi_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnTaraziClick), NULL, this);
    tarpitch_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnTarpitchClick), NULL, this);
    tarroll_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OntarrollClick), NULL, this);
    midx_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnMidxClick), NULL, this);
    midy_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnMidyClick), NULL, this);
    midz_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnMidzClick), NULL, this);
    up_mid_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnUpmidClick), NULL, this);
    down_mid_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnDownmidClick), NULL, this);
    left_mid_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnLeftmidClick), NULL, this);
    right_mid_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnRightClick), NULL, this);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnMeas);
    Connect(ID_TEXTCTRL53,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeHeadx);
    Connect(ID_TEXTCTRL54,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeHeady);
    Connect(ID_TEXTCTRL55,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeHeadz);
    Connect(ID_TEXTCTRL56,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTailx);
    Connect(ID_TEXTCTRL57,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTaily);
    Connect(ID_TEXTCTRL58,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTailz);
    Connect(ID_TEXTCTRL99,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeMidx);
    Connect(ID_TEXTCTRL100,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeMidy);
    Connect(ID_TEXTCTRL101,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeMidz);

    Connect(ID_TEXTCTRL104,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeUmidj);
    Connect(ID_TEXTCTRL105,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeDmidj);
    Connect(ID_TEXTCTRL106,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeLmidj);
    Connect(ID_TEXTCTRL107,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeRmidj);

    Connect(ID_TEXTCTRL24,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTbmRoll);
    Connect(ID_TEXTCTRL29,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTarX);
    Connect(ID_TEXTCTRL30,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTarY);
    Connect(ID_TEXTCTRL31,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTarZ);
    Connect(ID_TEXTCTRL32,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTarAzi);
    Connect(ID_TEXTCTRL33,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTarPitch);
    Connect(ID_TEXTCTRL34,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeTarRoll);
    ///数据管理
    //Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::OnCheckedDbSave);
    //Connect(ID_TEXTCTRL10,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeDbpath);
    //Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnDbpathSet);
    //Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnDbpathOpen);
    //Connect(ID_TEXTCTRL11,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeDbtime);
    //Connect(ID_TEXTCTRL67,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeRppath);
    //Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnRppathSet);
    //Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnRppathOpen);
    //Connect(ID_CHECKBOX13,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::OnCheckedRemo);
    client_ip_text1->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnClientIP1Click), NULL, this);
    client_ip_text2->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnClientIP2Click), NULL, this);
    client_ip_text3->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnClientIP3Click), NULL, this);
    client_ip_text4->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnClientIP4Click), NULL, this);

    Connect(ID_CHECKBOX30,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetControlLocal);
    Connect(ID_CHECKBOX31,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetControlClient);

    //Connect(ID_BUTTON28,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnDBPathClick);
    //Connect(ID_BUTTON29,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnReportClick);

    Connect(ID_TEXTCTRL65,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeClientIP1);
    Connect(ID_TEXTCTRL110,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeClientIP2);
    Connect(ID_TEXTCTRL111,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeClientIP3);
    Connect(ID_TEXTCTRL112,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeClientIP4);

    ///测量设置
    measTime1->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnMeastime1Click), NULL, this);
    measTime2->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnMeastime2Click), NULL, this);
    horiDiff->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnHoridiffClick), NULL, this);
    verDiff->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnVerdiffClick), NULL, this);
    angleDiff->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnAnglediffClick), NULL, this);
    diffChange->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnDiffchangeClick), NULL, this);
    backDiff->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnBackdiffClick), NULL, this);
    tolTime->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnToltimeClcik), NULL, this);
    corr_dist_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnCorrdistClick), NULL, this);
    corr_diff_text->Connect(wxID_ANY,wxEVT_LEFT_UP, wxMouseEventHandler(MySetupDialog::OnCorrdiffClick), NULL, this);

    Connect(ID_TEXTCTRL37,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeMeasTime);
    Connect(ID_TEXTCTRL38,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeBackTime);
    Connect(ID_TEXTCTRL39,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeHtol);
    Connect(ID_TEXTCTRL40,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeVtol);
    Connect(ID_TEXTCTRL41,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeGtol);
    Connect(ID_TEXTCTRL42,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeDtol);
    Connect(ID_TEXTCTRL43,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeBtol);
    Connect(ID_TEXTCTRL59,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeDist);
    Connect(ID_TEXTCTRL60,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeCorrtol);

    Connect(ID_TEXTCTRL91,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeToltime);
    ///用户权限界面
    //Connect(ID_TEXTCTRL44,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeMOP);
    //Connect(ID_TEXTCTRL18,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeMNP);
    //Connect(ID_TEXTCTRL19,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeMPC);
    //Connect(ID_TEXTCTRL45,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeOOP);
    //Connect(ID_TEXTCTRL20,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeONP);
    //Connect(ID_TEXTCTRL21,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MySetupDialog::OnChangeOPC);
    //Connect(ID_CHOICE5,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MySetupDialog::OnLangSelect);

    Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnAddUserClick);
    Connect(ID_BUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnEditUserClick);
    Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MySetupDialog::OnBtnDelUserClick);
    Connect(ID_LIST3,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&MySetupDialog::OnListUserItemActivated);
    Connect(ID_LIST3,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&MySetupDialog::OnListUserItemSelect);
    Connect(ID_LIST3,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&MySetupDialog::OnListUserItemDeselect);
    ///语言选择
    Connect(ID_CHECKBOX25,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetLang1);
    Connect(ID_CHECKBOX26,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetLang2);
    Connect(ID_CHECKBOX27,wxEVT_COMMAND_CHECKBOX_CLICKED ,(wxObjectEventFunction)&MySetupDialog::SetLang3);
    //Connect(ID_TEXTCTRL10,wxEVT_LEFT_DOWN,(wxMouseEventHandler)&MySetupDialog::OnDayTimeClick);
    //m_textFrom->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( QueryDlg::OnSetFrom ), NULL, this );
    //*)

    Connect(ID_MENU_CLEAN,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MySetupDialog::OnMenuClean) );
    Connect(ID_MENU_BACKUP,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MySetupDialog::OnMenuBackup) );
    Connect(ID_MENU_RESTORE,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MySetupDialog::OnMenuRestore) );

    listArea->InsertColumn(0,_("序号"),wxLIST_FORMAT_CENTER,50);
    listArea->InsertColumn(1,_("区域名称"),wxLIST_FORMAT_CENTER,160);
    listArea->InsertColumn(2,_("起点里程"),wxLIST_FORMAT_CENTER,100);
    listArea->InsertColumn(3,_("终点里程"),wxLIST_FORMAT_CENTER,100);
    //listKeyarea->InsertColumn(4,_("提示距离"),wxLIST_FORMAT_CENTER,80);

    listBlock->InsertColumn(0,_("序 号"),wxLIST_FORMAT_CENTER,-1);
    listBlock->InsertColumn(1,_("名 称"),wxLIST_FORMAT_CENTER,-1);
    listBlock->InsertColumn(2,_("圆心角[°]"),wxLIST_FORMAT_CENTER,-1);
    listBlock->SetColumnWidth(0,60);
    listBlock->SetColumnWidth(1,120);
    listBlock->SetColumnWidth(2,120);

    listUser->InsertColumn(0,_("序 号"),wxLIST_FORMAT_CENTER,-1);
    listUser->InsertColumn(1,_("用户名"),wxLIST_FORMAT_CENTER,-1);
    listUser->InsertColumn(2,_("权限等级"),wxLIST_FORMAT_CENTER,-1);
    listUser->InsertColumn(3,_("权限密码"),wxLIST_FORMAT_CENTER,-1);
    listUser->SetColumnWidth(0,60);
    listUser->SetColumnWidth(1,120);
    listUser->SetColumnWidth(2,120);
    listUser->SetColumnWidth(3,120);

    blockSelect = listBlock->GetFirstSelected();
    areaSelect = listArea->GetFirstSelected();
    userSelect = listUser->GetFirstSelected();
    //GraphBlock->SetGraphTitle(_("管块示意图"));

    if(mtg->control_mode==1)
    {
        control_checkbox1->SetValue(true);
        control_checkbox2->SetValue(false);
    }
    else
    {
        control_checkbox1->SetValue(false);
        control_checkbox2->SetValue(true);
    }

    btnPrjState = 4;
    btnKeyState = 0;
    btnDatabaseState = 0;
    btnTargetState = 0;
    btnTheodoliteState = 0;
    btnOriginState = 0;
    btnTBMState = 0;
    btnMeasState = 0;
    btnUserState = 0;
    btnLanguageState = 0;
    btnSegState=0;
    btnBlockState=0;

    ///界面输入
    prjset = 0;
    tbmset = -1;
    tarsset = -1;
    tpsset = -1;
    segset = -1;
    origset = -1;
    dataset = -1;
    measet = -1;
    langset = -1;
    //提示信息
    msg_str = _("");
    msg_cor = wxColor(255,255,255);
    ///布局
    LayoutOrign();
    LayoutPrj();
    LayoutTar();
    LayoutMea();
    LayoutSeg();
    LayoutTheo();
    LayoutDB();
    LayoutTBM();
    LayoutKeyArea();
    LayoutUser();
    LayoutLang();

    Sortip();


    ///调试信息
    /*mtg->m0.roll = 0.035;
    mtg->angle0[0] = 2.468;
    mtg->angle0[1] = 0.068;
    mtg->angle0[2] = 0.044;*/
    prj_name->SetFocus();
    btnApply->Enable(false);
    //wxMessageBox(wxString::Format(_("%d"),mtg->nblk));
    LoadDatabase();
    UpdateBlock();
    UpdateArea();
    UpdateUser();
}

MySetupDialog::~MySetupDialog()
{
    //(*Destroy(ConfigDialog)
	//*)
	confDlg=0;
}

///工程界面
void MySetupDialog::SetForward(wxCommandEvent& event)
{
    double str;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&str);
        if(!Err)
        {
            if(reverse_checkbox->GetValue()==false)
            {
                forward_checkbox->SetValue(true);
            }
            else
            {
                forward_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&str);
        if(!Err)
        {
            if(reverse_checkbox->GetValue()==false)
            {
                forward_checkbox->SetValue(true);
            }
            else
            {
                forward_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err =day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            if(reverse_checkbox->GetValue()==false)
            {
                forward_checkbox->SetValue(true);
            }
            else
            {
                forward_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            if(reverse_checkbox->GetValue()==false)
            {
                forward_checkbox->SetValue(true);
            }
            else
            {
                forward_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 =  mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            if(reverse_checkbox->GetValue()==false)
            {
                forward_checkbox->SetValue(true);
            }
            else
            {
                forward_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            if(reverse_checkbox->GetValue()==false)
            {
                forward_checkbox->SetValue(true);
            }
            else
            {
                forward_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = -1;

    if(reverse_checkbox->GetValue()==false)
    {
        forward_checkbox->SetValue(true);
    }
    else
    {
        reverse_checkbox->SetValue(false);
        m_bModifyPrj = true;
        btnApply->Enable(true);
    }
}
void MySetupDialog::SetReverse(wxCommandEvent& event)
{
    double str;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&str);
        if(!Err)
        {
            if(forward_checkbox->GetValue()==false)
            {
                reverse_checkbox->SetValue(true);
            }
            else
            {
                reverse_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&str);
        if(!Err)
        {
            if(forward_checkbox->GetValue()==false)
            {
                reverse_checkbox->SetValue(true);
            }
            else
            {
                reverse_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err =day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            if(forward_checkbox->GetValue()==false)
            {
                reverse_checkbox->SetValue(true);
            }
            else
            {
                reverse_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            if(forward_checkbox->GetValue()==false)
            {
                reverse_checkbox->SetValue(true);
            }
            else
            {
                reverse_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 =  mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            if(forward_checkbox->GetValue()==false)
            {
                reverse_checkbox->SetValue(true);
            }
            else
            {
                reverse_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            if(forward_checkbox->GetValue()==false)
            {
                reverse_checkbox->SetValue(true);
            }
            else
            {
                reverse_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = -1;

    if(forward_checkbox->GetValue()==false)
    {

        reverse_checkbox->SetValue(true);
    }
    else
    {
        forward_checkbox->SetValue(false);
        m_bModifyPrj = true;
        btnApply->Enable(true);
    }
}

/*void MySetupDialog::OnDirectSelect(wxCommandEvent& event)
{
    int tempstr=direct_choice->GetCurrentSelection();
    if(tempstr!=mtg->prj.direction)
   {
        m_bModifyPrj=true;
        btnApply->Enable(true);
   }
}*/

void MySetupDialog::OnPrjNameClick(wxMouseEvent& event)
{
    double tempstr;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&tempstr);
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(!Err)
        {

            delete prj_name->g_kb;
            prj_name->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete prj_name->g_kb;
            prj_name->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(tempstr!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_name->g_kb;
            prj_name->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        str2 = mtg->prj.t1[0];
        //str3 = mtg->prj.daywork1;
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_name->g_kb;
            prj_name->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.daywork1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_name->g_kb;
            prj_name->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_name->g_kb;
            prj_name->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = 0;
    event.Skip();
}

void MySetupDialog::OnChangePrjName(wxCommandEvent& event)
{
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnPrjMile1Click(wxMouseEvent& event)
{
    double tempstr;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete prj_mile1->g_kb;
            prj_mile1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(tempstr!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_mile1->g_kb;
            prj_mile1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_mile1->g_kb;
            prj_mile1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_mile1->g_kb;
            prj_mile1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_mile1->g_kb;
            prj_mile1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = 1;
    event.Skip();
}

void MySetupDialog::OnChangePrjMile1(wxCommandEvent& event)
{
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnPrjMile2Click(wxMouseEvent& event)
{
    double tempstr;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete prj_mile2->g_kb;
            prj_mile2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(tempstr!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        break;
    case 3:
        Err = day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_mile2->g_kb;
            prj_mile2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_mile2->g_kb;
            prj_mile2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_mile2->g_kb;
            prj_mile2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete prj_mile2->g_kb;
            prj_mile2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = 2;
    event.Skip();
}

void MySetupDialog::OnChangePrjMile2(wxCommandEvent& event)
{
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnDayhClick(wxMouseEvent& event)
{
    double tempstr;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete day_hour->g_kb;
            day_hour->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(tempstr!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete day_hour->g_kb;
            day_hour->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(tempstr!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:

        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete day_hour->g_kb;
            day_hour->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete day_hour->g_kb;
            day_hour->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete day_hour->g_kb;
            day_hour->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = 3;
    event.Skip();
}

void MySetupDialog::OnDaymClick(wxMouseEvent& event)
{
    double tempstr;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete day_min->g_kb;
            day_min->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(tempstr!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete day_min->g_kb;
            day_min->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(tempstr!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err =day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete day_min->g_kb;
            day_min->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete day_min->g_kb;
            day_min->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete day_min->g_kb;
            day_min->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = 4;
    event.Skip();
}

void MySetupDialog::OnNighthClick(wxMouseEvent& event)
{
    double tempstr;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete night_hour->g_kb;
            night_hour->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(tempstr!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete night_hour->g_kb;
            night_hour->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(tempstr!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete night_hour->g_kb;
            night_hour->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete night_hour->g_kb;
            night_hour->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete night_hour->g_kb;
            night_hour->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        //str3 =  (mtg->prj.nightOperate-str3*3600)/60;
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = 5;
    event.Skip();
}

void MySetupDialog::OnNightmClick(wxMouseEvent& event)
{
    double tempstr;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete night_min->g_kb;
            night_min->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(tempstr!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete night_min->g_kb;
            night_min->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),tempstr));
        if(tempstr!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete night_min->g_kb;
            night_min->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete night_min->g_kb;
            night_min->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.daywork1/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete night_min->g_kb;
            night_min->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        break;
    default:
        break;
    }
    prjset = 6;
    event.Skip();
}

void MySetupDialog::OnChangeDayh(wxCommandEvent& event)
{
    long tempstr;
    day_hour->GetValue().ToLong(&tempstr);
    if(tempstr>2 && tempstr<10)
    {
        day_hour->SetMaxLength(1);
    }
    else
    {
        day_hour->SetMaxLength(2);
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}


void MySetupDialog::OnChangeDaym(wxCommandEvent& event)
{
    long tempstr;
    day_min->GetValue().ToLong(&tempstr);
    if(tempstr>5 && tempstr<10)
    {
        day_min->SetMaxLength(1);
    }
    else
    {
        day_min->SetMaxLength(2);
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeNighth(wxCommandEvent& event)
{
    long tempstr;
    night_hour->GetValue().ToLong(&tempstr);
    if(tempstr>2 && tempstr<10)
    {
        night_hour->SetMaxLength(1);
    }
    else
    {
        night_hour->SetMaxLength(2);
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeNightm(wxCommandEvent& event)
{
    long tempstr;
    night_min->GetValue().ToLong(&tempstr);
    if(tempstr>5 && tempstr<10)
    {
        night_min->SetMaxLength(1);
    }
    else
    {
        night_min->SetMaxLength(2);
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTip(wxCommandEvent& event)
{
    double tempstr;
    tip_text->GetValue().ToDouble(&tempstr);
    if(tempstr!=mtg->prj.tip)
    {
        m_bModifyPrj=true;
        btnApply->Enable(true);
    }
}

void MySetupDialog::OnDayHourAddClick(wxCommandEvent& event)
{
    double str;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err =day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        //str3 =  (mtg->prj.nightOperate-str3*3600)/60;
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = -1;

    long tempstr;
    day_hour->GetValue().ToLong(&tempstr);
    if(tempstr == 23)
    {
        day_hour->SetValue(_("00"));
    }
    else
    {
        if(tempstr <9)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),tempstr+1));
        }
        else
        {
            day_hour->SetValue(wxString::Format(_("%d"),tempstr+1));
        }
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnDayHourSubClick(wxCommandEvent& event)
{
    double str;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err =day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 =  mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = -1;

    long tempstr;
    day_hour->GetValue().ToLong(&tempstr);
    if(tempstr == 0)
    {
        day_hour->SetValue(_("23"));
    }
    else
    {
        if(tempstr <11)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),tempstr-1));
        }
        else
        {
            day_hour->SetValue(wxString::Format(_("%d"),tempstr-1));
        }
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnDayMinAddClick(wxCommandEvent& event)
{
    double str;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err =day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = -1;

    long tempstr;
    day_min->GetValue().ToLong(&tempstr);
    if(tempstr == 59)
    {
        day_min->SetValue(_("00"));
    }
    else
    {
        if(tempstr <9)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),tempstr+1));
        }
        else
        {
            day_min->SetValue(wxString::Format(_("%d"),tempstr+1));
        }
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnDayMinSubClick(wxCommandEvent& event)
{
    double str;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err =day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 =  mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = -1;

    long tempstr;
    day_min->GetValue().ToLong(&tempstr);
    if(tempstr == 0)
    {
        day_min->SetValue(_("59"));
    }
    else
    {
        if(tempstr <11)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),tempstr-1));
        }
        else
        {
            day_min->SetValue(wxString::Format(_("%d"),tempstr-1));
        }
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnNightHourAddClick(wxCommandEvent& event)
{
    double str;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err =day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = -1;

    long tempstr;
    night_hour->GetValue().ToLong(&tempstr);
    if(tempstr == 23)
    {
        night_hour->SetValue(_("00"));
    }
    else
    {
        if(tempstr <9)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),tempstr+1));
        }
        else
        {
            night_hour->SetValue(wxString::Format(_("%d"),tempstr+1));
        }
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnNightHourSubClick(wxCommandEvent& event)
{
    double str;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err =day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = -1;

    long tempstr;
    night_hour->GetValue().ToLong(&tempstr);
    if(tempstr == 0)
    {
        night_hour->SetValue(_("23"));
    }
    else
    {
        if(tempstr <11)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),tempstr-1));
        }
        else
        {
            night_hour->SetValue(wxString::Format(_("%d"),tempstr-1));
        }
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnNightMinAddClick(wxCommandEvent& event)
{
    double str;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err =day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = -1;

    long tempstr;
    night_min->GetValue().ToLong(&tempstr);
    if(tempstr == 59)
    {
        night_min->SetValue(_("00"));
    }
    else
    {
        if(tempstr <9)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),tempstr+1));
        }
        else
        {
            night_min->SetValue(wxString::Format(_("%d"),tempstr+1));
        }
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnNightMinSubClick(wxCommandEvent& event)
{
    double str;
    long str1,str2;
    bool Err;
    switch(prjset)
    {
    case 0:
        if(prj_name->GetValue().Cmp(wxString((const char*)mtg->prj.name,wxConvLocal))!=0)
        {
            m_bModifyPrj=true;
            btnApply->Enable(m_bModifyPrj);
        }
        break;
    case 1:
        Err = prj_mile1->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile1->SetFocus();
            prj_mile1->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile1)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = prj_mile2->GetValue().ToDouble(&str);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            prj_mile2->SetFocus();
            prj_mile2->SetSelection(-1,-1);
            return;
        }
        //prj_mile1->SetValue(wxString::Format(_("%.3f"),str));
        if(str!=mtg->prj.mile2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err =day_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_hour->SetFocus();
            day_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 4:
        Err = day_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            day_min->SetFocus();
            day_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.dayOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            day_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 5:
        Err = night_hour->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_hour->SetFocus();
            night_hour->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_hour->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    case 6:
        Err = night_min->GetValue().ToLong(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            night_min->SetFocus();
            night_min->SetSelection(-1,-1);
            return;
        }
        //str2 = (int)str1;
        //str3 = mtg->prj.nightOperate/3600;
        str2 = mtg->prj.t1[0];
        if(str1 != str2)
        {
            m_bModifyPrj=true;
            btnApply->Enable(true);
        }
        if(str1 < 10)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),str1));
        }
        break;
    default:
        break;
    }
    prjset = -1;

    long tempstr;
    night_min->GetValue().ToLong(&tempstr);
    if(tempstr == 0)
    {
        night_min->SetValue(_("59"));
    }
    else
    {
        if(tempstr <11)
        {
            night_min->SetValue(_("0")+wxString::Format(_("%d"),tempstr-1));
        }
        else
        {
            night_min->SetValue(wxString::Format(_("%d"),tempstr-1));
        }
    }
    m_bModifyPrj = true;
    btnApply->Enable(true);
}

///盾构界面
void MySetupDialog::OnTbmIndexClick(wxMouseEvent& event)
{
    double tempstr;
    bool Err;
    switch(tbmset)
    {
    case 0:
        break;
    case 1:
        Err = tail_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete TBM_index->g_kb;
            TBM_index->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tail_radius_text->SetFocus();
            tail_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[4])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = jointDist1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete TBM_index->g_kb;
            TBM_index->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist1->SetFocus();
            jointDist1->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.L[1])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = jack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            delete TBM_index->g_kb;
            TBM_index->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jack_radius_text->SetFocus();
            jack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[2])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = jointDist2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete TBM_index->g_kb;
            TBM_index->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist2->SetFocus();
            jointDist2->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }

        break;
    case 5:
        Err = backjack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete TBM_index->g_kb;
            TBM_index->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backjack_radius_text->SetFocus();
            backjack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        break;
    default:
        break;
    }
    tbmset = 0;
    event.Skip();
}

void MySetupDialog::OnChangeTbmIndex(wxCommandEvent& event)
{
    m_bModifyTbm = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnTbmRadiusClick(wxMouseEvent& event)
{
    double tempstr;
    bool Err;
    switch(tbmset)
    {
    case 0:
		if(TBM_index->GetValue().Cmp(wxString((const char*)mtg->tbm.name,wxConvLocal))!=0)
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 1:

        break;
    case 2:
        Err = jointDist1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            delete tail_radius_text->g_kb;
            tail_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist1->SetFocus();
            jointDist1->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.L[1])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = jack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            delete tail_radius_text->g_kb;
            tail_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jack_radius_text->SetFocus();
            jack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[2])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = jointDist2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete tail_radius_text->g_kb;
            tail_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist2->SetFocus();
            jointDist2->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }

        break;
    case 5:
        Err = backjack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete tail_radius_text->g_kb;
            tail_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backjack_radius_text->SetFocus();
            backjack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        break;
    default:
        break;
    }
    tbmset = 1;
    event.Skip();
}

void MySetupDialog::OnChangeTbmRadius(wxCommandEvent& event)
{
    m_bModifyTbm = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnTbmDist1Click(wxMouseEvent& event)
{
    double tempstr;
    bool Err;
    switch(tbmset)
    {
    case 0:
		if(TBM_index->GetValue().Cmp(wxString((const char*)mtg->tbm.name,wxConvLocal))!=0)
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = tail_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete jointDist1->g_kb;
            jointDist1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tail_radius_text->SetFocus();
            tail_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[4])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 2:

        break;
    case 3:
        Err = jack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            delete jointDist1->g_kb;
            jointDist1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jack_radius_text->SetFocus();
            jack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[2])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = jointDist2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete jointDist1->g_kb;
            jointDist1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist2->SetFocus();
            jointDist2->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }

        break;
    case 5:
        Err = backjack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete jointDist1->g_kb;
            jointDist1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backjack_radius_text->SetFocus();
            backjack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        break;
    default:
        break;
    }
    tbmset = 2;
    event.Skip();
}

void MySetupDialog::OnChangeTbmDist1(wxCommandEvent& event)
{
    m_bModifyTbm = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnTbmJackrClick(wxMouseEvent& event)
{
    double tempstr;
    bool Err;
    switch(tbmset)
    {
    case 0:
		if(TBM_index->GetValue().Cmp(wxString((const char*)mtg->tbm.name,wxConvLocal))!=0)
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = tail_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete jack_radius_text->g_kb;
            jack_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tail_radius_text->SetFocus();
            tail_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[4])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = jointDist1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            delete jack_radius_text->g_kb;
            jack_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist1->SetFocus();
            jointDist1->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.L[1])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 3:

        break;
    case 4:
        Err = jointDist2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete jack_radius_text->g_kb;
            jack_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist2->SetFocus();
            jointDist2->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }

        break;
    case 5:
        Err = backjack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete jack_radius_text->g_kb;
            jack_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backjack_radius_text->SetFocus();
            backjack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        break;
    default:
        break;
    }
    tbmset = 3;
    event.Skip();
}

void MySetupDialog::OnChangeTbmJackr(wxCommandEvent& event)
{
    m_bModifyTbm = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnTbmDist2Click(wxMouseEvent& event)
{
    double tempstr;
    bool Err;
    switch(tbmset)
    {
    case 0:
		if(TBM_index->GetValue().Cmp(wxString((const char*)mtg->tbm.name,wxConvLocal))!=0)
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = tail_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete jointDist2->g_kb;
            jointDist2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tail_radius_text->SetFocus();
            tail_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[4])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = jointDist1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            delete jointDist2->g_kb;
            jointDist2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist1->SetFocus();
            jointDist1->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.L[1])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = jack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            delete jointDist2->g_kb;
            jointDist2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jack_radius_text->SetFocus();
            jack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[2])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 4:

        break;
    case 5:
        Err = backjack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete jointDist2->g_kb;
            jointDist2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backjack_radius_text->SetFocus();
            backjack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        break;
    default:
        break;
    }
    tbmset = 4;
    event.Skip();
}

void MySetupDialog::OnChangeTbmDist2(wxCommandEvent& event)
{
    m_bModifyTbm = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnTbmMidjrClick(wxMouseEvent& event)
{
    double tempstr;
    bool Err;
    switch(tbmset)
    {
    case 0:
		if(TBM_index->GetValue().Cmp(wxString((const char*)mtg->tbm.name,wxConvLocal))!=0)
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = tail_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete backjack_radius_text->g_kb;
            backjack_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tail_radius_text->SetFocus();
            tail_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[4])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = jointDist1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            delete backjack_radius_text->g_kb;
            backjack_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist1->SetFocus();
            jointDist1->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.L[1])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = jack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            delete backjack_radius_text->g_kb;
            backjack_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jack_radius_text->SetFocus();
            jack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[2])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = jointDist2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete backjack_radius_text->g_kb;
            backjack_radius_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist2->SetFocus();
            jointDist2->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        break;
    case 5:

        break;
    default:
        break;
    }
    tbmset = 5;
    event.Skip();
}

void MySetupDialog::OnChangeTbmMidjr(wxCommandEvent& event)
{
    m_bModifyTbm = true;
    btnApply->Enable(true);
}

void MySetupDialog::SetControlLocal(wxCommandEvent& event)
{
    if(control_checkbox2->GetValue()==false)
    {
        control_checkbox1->SetValue(true);
    }
    else
    {
        control_checkbox2->SetValue(false);
    }
    ///服务器
    mtg->control_mode=1;
    if(mtg->iclient==1 && mtg->peeking==0) client_opera(mtg,1);
}

void MySetupDialog::SetControlClient(wxCommandEvent& event)
{
    if(control_checkbox1->GetValue()==false)
    {
        control_checkbox2->SetValue(true);
    }
    else
    {
        control_checkbox1->SetValue(false);
    }
    ///本机
    mtg->control_mode=2;
    if(mtg->iclient==1 && mtg->peeking==0) client_opera(mtg,2);
}

void MySetupDialog::SetFront(wxCommandEvent& event)
{

    double tempstr;
    bool Err;
    switch(tbmset)
    {
    case 0:
		if(TBM_index->GetValue().Cmp(wxString((const char*)mtg->tbm.name,wxConvLocal))!=0)
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = tail_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
			if(midf_checkbox->GetValue()==false)
			{
				midf_checkbox->SetValue(true);
			}
			else
            {
                midf_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tail_radius_text->SetFocus();
            tail_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[4])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = jointDist1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
			if(midf_checkbox->GetValue()==false)
			{
				midf_checkbox->SetValue(true);
			}
			else
            {
                midf_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist1->SetFocus();
            jointDist1->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.L[1])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = jack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            if(midf_checkbox->GetValue()==false)
			{
				midf_checkbox->SetValue(true);
			}
			else
            {
                midf_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jack_radius_text->SetFocus();
            jack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[2])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = jointDist2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
			if(midf_checkbox->GetValue()==false)
			{
				midf_checkbox->SetValue(true);
			}
			else
            {
                midf_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist2->SetFocus();
            jointDist2->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }


        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        break;
    case 5:
        Err = backjack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
			if(midf_checkbox->GetValue()==false)
			{
				midf_checkbox->SetValue(true);
			}
			else
            {
                midf_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backjack_radius_text->SetFocus();
            backjack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        break;
    default:
        break;
    }
    tbmset = -1;

    if(midf_checkbox->GetValue()==true)
    {
        midb_checkbox->SetValue(false);
        StaticText97->SetLabel(_("到切口距离"));

        //midx_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[0]));
        //midy_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[1]));
        //midz_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[2]));
        //up_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[0]));
        //down_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[1]));
        //left_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[2]));
        //right_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[3]));

        jointDist2->Enable(true);
        jointDist2->SetValue(wxString::Format(_("%.4f"),mtg->tbm.L[2]));
        backjack_radius_text->Enable(true);
        backjack_radius_text->SetValue(wxString::Format(_("%.4f"),mtg->tbm.D[3]));
        mid_data_checkbox->Enable(true);
    }
    else
    {
        if(midb_checkbox->GetValue()==false)
        {
            jointDist2->Enable(false);
            backjack_radius_text->Enable(false);
            mid_data_checkbox->Enable(false);
        }
        //midx_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[0]));
        //midy_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[1]));
        //midz_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[2]));
        //up_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[0]));
        //down_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[1]));
        //left_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[2]));
        //right_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[3]));
    }


    m_bModifyTbm = true;
    btnApply->Enable(true);
}

void MySetupDialog::SetBack(wxCommandEvent& event)
{
    double tempstr;
    bool Err;
    //mtg->tbm.hjd = 3.0;
    //mtg->tbm.hjr = 5.43;
    switch(tbmset)
    {
    case 0:
		if(TBM_index->GetValue().Cmp(wxString((const char*)mtg->tbm.name,wxConvLocal))!=0)
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = tail_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
			if(midb_checkbox->GetValue()==false)
			{
				midb_checkbox->SetValue(true);
			}
			else
            {
                midb_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tail_radius_text->SetFocus();
            tail_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[4])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = jointDist1->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
			if(midb_checkbox->GetValue()==false)
			{
				midb_checkbox->SetValue(true);
			}
			else
            {
                midb_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist1->SetFocus();
            jointDist1->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.L[1])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = jack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            if(midb_checkbox->GetValue()==false)
			{
				midb_checkbox->SetValue(true);
			}
			else
            {
                midb_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jack_radius_text->SetFocus();
            jack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tbm.D[2])
        {
            m_bModifyTbm=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = jointDist2->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
			if(midb_checkbox->GetValue()==false)
			{
				midb_checkbox->SetValue(true);
			}
			else
            {
                midb_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            jointDist2->SetFocus();
            jointDist2->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.L[2])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        break;
    case 5:
        Err = backjack_radius_text->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
			if(midb_checkbox->GetValue()==false)
			{
				midb_checkbox->SetValue(true);
			}
			else
            {
                midb_checkbox->SetValue(false);
            }
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backjack_radius_text->SetFocus();
            backjack_radius_text->SetSelection(-1,-1);
            return;
        }
        if(midb_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        else if(midf_checkbox->IsChecked())
        {
            if(tempstr!=mtg->tbm.D[3])
            {
                m_bModifyTbm=true;
                btnApply->Enable(true);
            }
        }
        break;
    default:
        break;
    }
    tbmset = -1;
    if(midb_checkbox->GetValue()==true)
    {
        midf_checkbox->SetValue(false);
        StaticText97->SetLabel(_("到盾尾距离"));

        jointDist2->Enable(true);
        jointDist2->SetValue(wxString::Format(_("%.4f"),mtg->tbm.L[2]));
        backjack_radius_text->Enable(true);
        backjack_radius_text->SetValue(wxString::Format(_("%.4f"),mtg->tbm.D[3]));
        mid_data_checkbox->Enable(true);
        //midx_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[0]));
        //midy_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[1]));
        //midz_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[2]));
        //up_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[0]));
        //down_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[1]));
        //left_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[2]));
        //right_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[3]));
    }
    else
    {
        if(midf_checkbox->GetValue()==false)
        {
            jointDist2->Enable(false);
            backjack_radius_text->Enable(false);
            mid_data_checkbox->Enable(false);
        }
        //midx_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[0]));
        //midy_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[1]));
        //midz_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[2]));
        //up_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[0]));
        //down_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[1]));
        //left_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[2]));
        //right_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[3]));
    }

    m_bModifyTbm = true;
    btnApply->Enable(true);
    //panelTBM->Refresh();
}

void MySetupDialog::SetMnual(wxCommandEvent& event)
{
    if(mid_data_checkbox->GetValue()==true)
    {
        mid_value_text1->Enable(true);
        mid_value_text2->Enable(true);
        mid_value_text3->Enable(true);
        mid_value_text4->Enable(true);
    }
    else
    {
        mid_value_text1->Enable(false);
        mid_value_text2->Enable(false);
        mid_value_text3->Enable(false);
        mid_value_text4->Enable(false);
    }
    m_bModifyTbm = true;
    btnApply->Enable(true);
}

///激光靶
void MySetupDialog::OnChangePrc(wxCommandEvent& event)
{
    m_bModifyTar=true;
    btnApply->Enable(true);
}

///全站仪
void MySetupDialog::OnChangeLaserh(wxCommandEvent& event)
{
    m_bModifyTps=true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeCorrdist(wxCommandEvent& event)
{
    m_bModifyTps=true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeCorrX(wxCommandEvent& event)
{
    m_bModifyTps=true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeCorrY(wxCommandEvent& event)
{
    m_bModifyTps=true;
    btnApply->Enable(true);
}

void MySetupDialog::SetGus74Laser(wxCommandEvent& event)
{
    bool Err;
    double tempstr;
    if(ref_laser_checkbox->GetValue()==false && user_laser_checkbox->GetValue()==false)
    {
        gus_laser_checkbox->SetValue(true);
    }
    else
    {
        ref_laser_checkbox->SetValue(false);
        user_laser_checkbox->SetValue(false);
        tps_laserh->SetValue(wxString::Format(_("%.2f"),52.2));
        tps_laserh->SetEditable(false);
        tps_laserd->SetFocus();
        m_bModifyTps = true;
        btnApply->Enable(true);
    }

    switch(tpsset)
    {
    case 0:
        if(tps_laserh->IsEditable())
        {
            Err = tps_laserh->GetValue().ToDouble(&tempstr);
            if(!Err)
            {
                wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
                tps_laserh->SetFocus();
                tps_laserh->SetSelection(-1,-1);
                return;
            }
            if(tempstr!=mtg->tps.laserheight)
            {
                m_bModifyTps=true;
                btnApply->Enable(true);
            }
        }
        break;
    case 1:
        Err = tps_laserd->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserd->SetFocus();
            tps_laserd->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.laserdist)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = tps_laserx->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserx->SetFocus();
            tps_laserx->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.laserx)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = tps_lasery->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_lasery->SetFocus();
            tps_lasery->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.lasery)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    tpsset = -1;
}

void MySetupDialog::SetCoaxLaser(wxCommandEvent& event)
{
    bool Err;
    double tempstr;
    if(gus_laser_checkbox->GetValue()==false && user_laser_checkbox->GetValue()==false)
    {
        ref_laser_checkbox->SetValue(true);
    }
    else
    {
        gus_laser_checkbox->SetValue(false);
        user_laser_checkbox->SetValue(false);
        tps_laserh->SetValue(wxString::Format(_("%.2f"),0.0));
        tps_laserh->SetEditable(false);
        tps_laserd->SetFocus();
        m_bModifyTps = true;
        btnApply->Enable(true);
    }

    switch(tpsset)
    {
    case 0:
        if(tps_laserh->IsEditable())
        {
            Err = tps_laserh->GetValue().ToDouble(&tempstr);
            if(!Err)
            {
                wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
                tps_laserh->SetFocus();
                tps_laserh->SetSelection(-1,-1);
                return;
            }
            if(tempstr!=mtg->tps.laserheight)
            {
                m_bModifyTps=true;
                btnApply->Enable(true);
            }
        }
        break;
    case 1:
        Err = tps_laserd->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserd->SetFocus();
            tps_laserd->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.laserdist)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = tps_laserx->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserx->SetFocus();
            tps_laserx->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.laserx)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = tps_lasery->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_lasery->SetFocus();
            tps_lasery->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.lasery)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    tpsset = -1;
}

void MySetupDialog::SetUserLaser(wxCommandEvent& event)
{
    bool Err;
    double tempstr;
    if(gus_laser_checkbox->GetValue()==false && ref_laser_checkbox->GetValue()==false)
    {
        user_laser_checkbox->SetValue(true);
    }
    else
    {
        gus_laser_checkbox->SetValue(false);
        ref_laser_checkbox->SetValue(false);
        tps_laserh->SetEditable(true);
        tps_laserh->SetFocus();
        tps_laserh->SetValue(wxString::Format(_("%.2f"),0.0));
        m_bModifyTps = true;
        btnApply->Enable(true);
    }

    switch(tpsset)
    {
    case 0:
        if(tps_laserh->IsEditable())
        {
            Err = tps_laserh->GetValue().ToDouble(&tempstr);
            if(!Err)
            {
                wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
                tps_laserh->SetFocus();
                tps_laserh->SetSelection(-1,-1);
                return;
            }
            if(tempstr!=mtg->tps.laserheight)
            {
                m_bModifyTps=true;
                btnApply->Enable(true);
            }
        }
        break;
    case 1:
        Err = tps_laserd->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserd->SetFocus();
            tps_laserd->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.laserdist)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = tps_laserx->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserx->SetFocus();
            tps_laserx->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.laserx)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = tps_lasery->GetValue().ToDouble(&tempstr);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_lasery->SetFocus();
            tps_lasery->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.lasery)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    tpsset = -1;
}

void MySetupDialog::OnLaserhClick(wxMouseEvent& event)
{
    double tempstr;
    bool Err;
    switch(tpsset)
    {
    case 0:
        break;
    case 1:
        Err = tps_laserd->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete tps_laserh->g_kb;
            tps_laserh->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserd->SetFocus();
            tps_laserd->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.laserdist)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = tps_laserx->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete tps_laserh->g_kb;
            tps_laserh->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserx->SetFocus();
            tps_laserx->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.laserx)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = tps_lasery->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete tps_laserh->g_kb;
            tps_laserh->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_lasery->SetFocus();
            tps_lasery->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.lasery)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    tpsset = 0;
    event.Skip();
}

void MySetupDialog::OnLaserdClick(wxMouseEvent& event)
{
    double tempstr;
    bool Err;
    switch(tpsset)
    {
    case 0:
        if(tps_laserh->IsEditable())
        {
            Err = tps_laserh->GetValue().ToDouble(&tempstr);
            if(!Err)
            {

                delete tps_laserd->g_kb;
                tps_laserd->g_kb = 0;
                wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
                tps_laserh->SetFocus();
                tps_laserh->SetSelection(-1,-1);
                return;
            }
            if(tempstr!=mtg->tps.laserheight)
            {
                m_bModifyTps=true;
                btnApply->Enable(true);
            }
        }
        break;
    case 1:
        break;
    case 2:
        Err = tps_laserx->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete tps_laserd->g_kb;
            tps_laserd->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserx->SetFocus();
            tps_laserx->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.laserx)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = tps_lasery->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete tps_laserd->g_kb;
            tps_laserd->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_lasery->SetFocus();
            tps_lasery->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.lasery)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    tpsset = 1;
    event.Skip();
}

void MySetupDialog::OnLaserxClick(wxMouseEvent& event)
{
    double tempstr;
    bool Err;
    switch(tpsset)
    {
    case 0:
        if(tps_laserh->IsEditable())
        {
            Err = tps_laserh->GetValue().ToDouble(&tempstr);
            if(!Err)
            {

                delete tps_laserx->g_kb;
                tps_laserx->g_kb = 0;
                wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
                tps_laserh->SetFocus();
                tps_laserh->SetSelection(-1,-1);
                return;
            }
            if(tempstr!=mtg->tps.laserheight)
            {
                m_bModifyTps=true;
                btnApply->Enable(true);
            }
        }
        break;
    case 1:
        Err = tps_laserd->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete tps_laserx->g_kb;
            tps_laserx->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserd->SetFocus();
            tps_laserd->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.laserdist)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        break;
    case 3:
        Err = tps_lasery->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete tps_laserx->g_kb;
            tps_laserx->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_lasery->SetFocus();
            tps_lasery->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.lasery)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    tpsset = 2;
    event.Skip();
}

void MySetupDialog::OnLaseryClick(wxMouseEvent& event)
{
    double tempstr;
    bool Err;
    switch(tpsset)
    {
    case 0:
        if(tps_laserh->IsEditable())
        {
            Err = tps_laserh->GetValue().ToDouble(&tempstr);
            if(!Err)
            {

                delete tps_lasery->g_kb;
                tps_lasery->g_kb = 0;
                wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
                tps_laserh->SetFocus();
                tps_laserh->SetSelection(-1,-1);
                return;
            }
            if(tempstr!=mtg->tps.laserheight)
            {
                m_bModifyTps=true;
                btnApply->Enable(true);
            }
        }
        break;
    case 1:
        Err = tps_laserd->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete tps_lasery->g_kb;
            tps_lasery->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserd->SetFocus();
            tps_laserd->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.laserdist)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = tps_laserx->GetValue().ToDouble(&tempstr);
        if(!Err)
        {

            delete tps_lasery->g_kb;
            tps_lasery->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tps_laserx->SetFocus();
            tps_laserx->SetSelection(-1,-1);
            return;
        }
        if(tempstr!=mtg->tps.lasery)
        {
            m_bModifyTps=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        break;
    default:
        break;
    }
    tpsset = 3;
    event.Skip();
}

///管环界面
void MySetupDialog::OnChangeSeglen(wxCommandEvent& event)
{
    m_bModifySeg=true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeSegr(wxCommandEvent& event)
{
    m_bModifySeg=true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeSegthick(wxCommandEvent& event)
{
    m_bModifySeg=true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeSegangle(wxCommandEvent& event)
{
    m_bModifySeg=true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeStdSeggap(wxCommandEvent& event)
{
    m_bModifySeg=true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeMinSeggap(wxCommandEvent& event)
{
    m_bModifySeg=true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeSegWedge(wxCommandEvent& event)
{
    m_bModifySeg=true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeGapangle(wxCommandEvent& event)
{
    m_bModifySeg=true;
    btnApply->Enable(true);
}

void MySetupDialog::OnSeglenClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(segset)
    {
    case 0:
        break;
    case 1:
        Err = seg_r->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_len->g_kb;
            seg_len->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_r->SetFocus();
            seg_r->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.D)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = segThick->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_len->g_kb;
            seg_len->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segThick->SetFocus();
            segThick->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Dn)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = segScrow->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_len->g_kb;
            seg_len->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segScrow->SetFocus();
            segScrow->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Ks)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = std_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_len->g_kb;
            seg_len->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            std_gap_text->SetFocus();
            std_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G0)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = min_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_len->g_kb;
            seg_len->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            min_gap_text->SetFocus();
            min_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = Wedge_Text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_len->g_kb;
            seg_len->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            Wedge_Text->SetFocus();
            Wedge_Text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.l2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = gapangle_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_len->g_kb;
            seg_len->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            gapangle_text->SetFocus();
            gapangle_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.s2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    segset = 0;
    event.Skip();
}

void MySetupDialog::OnSegrClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(segset)
    {
    case 0:
        Err = seg_len->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_r->g_kb;
            seg_r->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_len->SetFocus();
            seg_len->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.L)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        break;
    case 2:
        Err = segThick->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_r->g_kb;
            seg_r->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segThick->SetFocus();
            segThick->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.D)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = segScrow->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_r->g_kb;
            seg_r->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segScrow->SetFocus();
            segScrow->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Ks)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = std_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_r->g_kb;
            seg_r->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            std_gap_text->SetFocus();
            std_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G0)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = min_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_r->g_kb;
            seg_r->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            min_gap_text->SetFocus();
            min_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = Wedge_Text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_r->g_kb;
            seg_r->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            Wedge_Text->SetFocus();
            Wedge_Text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.l2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = gapangle_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete seg_r->g_kb;
            seg_r->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            gapangle_text->SetFocus();
            gapangle_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.s2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    segset = 1;
    event.Skip();
}

void MySetupDialog::OnSegThickClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(segset)
    {
    case 0:
        Err = seg_len->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segThick->g_kb;
            segThick->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_len->SetFocus();
            seg_len->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.L)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = seg_r->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segThick->g_kb;
            segThick->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_r->SetFocus();
            seg_r->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.D)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        break;
    case 3:
        Err = segScrow->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segThick->g_kb;
            segThick->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segScrow->SetFocus();
            segScrow->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Ks)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = std_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segThick->g_kb;
            segThick->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            std_gap_text->SetFocus();
            std_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G0)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = min_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segThick->g_kb;
            segThick->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            min_gap_text->SetFocus();
            min_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = Wedge_Text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segThick->g_kb;
            segThick->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            Wedge_Text->SetFocus();
            Wedge_Text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.l2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = gapangle_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segThick->g_kb;
            segThick->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            gapangle_text->SetFocus();
            gapangle_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.s2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    segset = 2;
    event.Skip();
}

void MySetupDialog::OnSegangleClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(segset)
    {
    case 0:
        Err = seg_len->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segScrow->g_kb;
            segScrow->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_len->SetFocus();
            seg_len->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.L)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = seg_r->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segThick->g_kb;
            segThick->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_r->SetFocus();
            seg_r->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.D)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = segThick->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segScrow->g_kb;
            segScrow->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segThick->SetFocus();
            segThick->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Dn)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        break;
    case 4:
        Err = std_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segScrow->g_kb;
            segScrow->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            std_gap_text->SetFocus();
            std_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G0)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = min_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segScrow->g_kb;
            segScrow->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            min_gap_text->SetFocus();
            min_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = Wedge_Text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segScrow->g_kb;
            segScrow->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            Wedge_Text->SetFocus();
            Wedge_Text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.l2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = gapangle_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete segScrow->g_kb;
            segScrow->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            gapangle_text->SetFocus();
            gapangle_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.s2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    segset = 3;
    event.Skip();
}

void MySetupDialog::OnSegstdgapClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(segset)
    {
    case 0:
        Err = seg_len->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete std_gap_text->g_kb;
            std_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_len->SetFocus();
            seg_len->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.L)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = seg_r->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete std_gap_text->g_kb;
            std_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_r->SetFocus();
            seg_r->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Dn)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = segThick->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete std_gap_text->g_kb;
            std_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segThick->SetFocus();
            segThick->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Dn)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = segScrow->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete std_gap_text->g_kb;
            std_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segScrow->SetFocus();
            segScrow->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Ks)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        break;
    case 5:
        Err = min_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete std_gap_text->g_kb;
            std_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            min_gap_text->SetFocus();
            min_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = Wedge_Text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete std_gap_text->g_kb;
            std_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            Wedge_Text->SetFocus();
            Wedge_Text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.l2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = gapangle_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete std_gap_text->g_kb;
            std_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            gapangle_text->SetFocus();
            gapangle_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.s2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    segset = 4;
    event.Skip();
}

void MySetupDialog::OnSegmingapClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(segset)
    {
    case 0:
        Err = seg_len->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete min_gap_text->g_kb;
            min_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_len->SetFocus();
            seg_len->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.L)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = seg_r->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete min_gap_text->g_kb;
            min_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_r->SetFocus();
            seg_r->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.D)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = segThick->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete min_gap_text->g_kb;
            min_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segThick->SetFocus();
            segThick->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Dn)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = segScrow->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete min_gap_text->g_kb;
            min_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segScrow->SetFocus();
            segScrow->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Ks)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = std_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete min_gap_text->g_kb;
            min_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            std_gap_text->SetFocus();
            std_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G0)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        break;
    case 6:
        Err = Wedge_Text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete min_gap_text->g_kb;
            min_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            Wedge_Text->SetFocus();
            Wedge_Text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.l2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = gapangle_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete min_gap_text->g_kb;
            min_gap_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            gapangle_text->SetFocus();
            gapangle_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.s2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    segset = 5;
    event.Skip();
}

void MySetupDialog::OnSegwedgeClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(segset)
    {
    case 0:
        Err = seg_len->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete Wedge_Text->g_kb;
            Wedge_Text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_len->SetFocus();
            seg_len->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.L)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = seg_r->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete Wedge_Text->g_kb;
            Wedge_Text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_r->SetFocus();
            seg_r->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.D)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = segThick->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete Wedge_Text->g_kb;
            Wedge_Text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segThick->SetFocus();
            segThick->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Dn)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = segScrow->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete Wedge_Text->g_kb;
            Wedge_Text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segScrow->SetFocus();
            segScrow->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Ks)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = std_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete Wedge_Text->g_kb;
            Wedge_Text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            std_gap_text->SetFocus();
            std_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G0)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = min_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete Wedge_Text->g_kb;
            Wedge_Text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            min_gap_text->SetFocus();
            min_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        break;
    case 7:
        Err = gapangle_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete Wedge_Text->g_kb;
            Wedge_Text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            gapangle_text->SetFocus();
            gapangle_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.s2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    segset = 6;
    event.Skip();
}

void MySetupDialog::OnGapangleClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(segset)
    {
    case 0:
        Err = seg_len->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete gapangle_text->g_kb;
            gapangle_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_len->SetFocus();
            seg_len->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.L)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = seg_r->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete gapangle_text->g_kb;
            gapangle_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_r->SetFocus();
            seg_r->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.D)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = segThick->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete gapangle_text->g_kb;
            gapangle_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segThick->SetFocus();
            segThick->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Dn)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = segScrow->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete gapangle_text->g_kb;
            gapangle_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segScrow->SetFocus();
            segScrow->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Ks)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = std_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete gapangle_text->g_kb;
            gapangle_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            std_gap_text->SetFocus();
            std_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = min_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete gapangle_text->g_kb;
            gapangle_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            min_gap_text->SetFocus();
            min_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = Wedge_Text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete gapangle_text->g_kb;
            gapangle_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            Wedge_Text->SetFocus();
            Wedge_Text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.l2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        break;
    default:
        break;
    }
    segset = 7;
    event.Skip();
}

void MySetupDialog::OnMethod1Click(wxCommandEvent& event)
{
    bool Err;
    double str1;
    if(seg_method2_checkbox->GetValue()==false)
    {
        seg_method1_checkbox->SetValue(true);
    }
    else
    {
        seg_method2_checkbox->SetValue(false);
        seg_wedge1_checkbox->SetValue(true);
        seg_wedge2_checkbox->Enable(false);
        seg_wedge2_checkbox->SetValue(false);
        m_bModifySeg = true;
        btnApply->Enable(true);
    }

    switch(segset)
    {
    case 0:
        Err = seg_len->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_len->SetFocus();
            seg_len->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.L)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = seg_r->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_r->SetFocus();
            seg_r->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.D)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = segThick->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segThick->SetFocus();
            segThick->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Dn)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = segScrow->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segScrow->SetFocus();
            segScrow->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Ks)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = std_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            std_gap_text->SetFocus();
            std_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G0)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = min_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            min_gap_text->SetFocus();
            min_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = Wedge_Text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            Wedge_Text->SetFocus();
            Wedge_Text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.l2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = gapangle_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            gapangle_text->SetFocus();
            gapangle_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.s2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    segset = -1;
    event.Skip();
}

void MySetupDialog::OnMethod2Click(wxCommandEvent& event)
{
    bool Err;
    double str1;
    if(seg_method1_checkbox->GetValue()==false)
    {
        seg_method2_checkbox->SetValue(true);
    }
    else
    {
        seg_method1_checkbox->SetValue(false);
        seg_wedge1_checkbox->SetValue(true);
        seg_wedge2_checkbox->Enable(true);
        seg_wedge2_checkbox->SetValue(false);
        m_bModifySeg = true;
        btnApply->Enable(true);
    }

    switch(segset)
    {
    case 0:
        Err = seg_len->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_len->SetFocus();
            seg_len->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.L)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = seg_r->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_r->SetFocus();
            seg_r->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.D)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = segThick->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segThick->SetFocus();
            segThick->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Dn)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = segScrow->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segScrow->SetFocus();
            segScrow->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Ks)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = std_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            std_gap_text->SetFocus();
            std_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G0)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = min_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            min_gap_text->SetFocus();
            min_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = Wedge_Text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            Wedge_Text->SetFocus();
            Wedge_Text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.l2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = gapangle_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            gapangle_text->SetFocus();
            gapangle_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.s2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    segset = -1;
    event.Skip();
}

void MySetupDialog::OnWedge1Click(wxCommandEvent& event)
{
    bool Err;
    double str1;
    if(seg_wedge2_checkbox->GetValue()==false)
    {
        seg_wedge1_checkbox->SetValue(true);
    }
    else
    {
        seg_wedge2_checkbox->SetValue(false);
        m_bModifySeg = true;
        btnApply->Enable(true);
    }

    switch(segset)
    {
    case 0:
        Err = seg_len->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_len->SetFocus();
            seg_len->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.L)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = seg_r->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_r->SetFocus();
            seg_r->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.D)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = segThick->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segThick->SetFocus();
            segThick->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Dn)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = segScrow->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segScrow->SetFocus();
            segScrow->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Ks)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = std_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            std_gap_text->SetFocus();
            std_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G0)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = min_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            min_gap_text->SetFocus();
            min_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = Wedge_Text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            Wedge_Text->SetFocus();
            Wedge_Text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.l2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = gapangle_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            gapangle_text->SetFocus();
            gapangle_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.s2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    segset = -1;
    event.Skip();
}

void MySetupDialog::OnWedge2Click(wxCommandEvent& event)
{
    bool Err;
    double str1;
    if(seg_wedge1_checkbox->GetValue()==false)
    {
        seg_wedge2_checkbox->SetValue(true);
    }
    else
    {
        seg_wedge1_checkbox->SetValue(false);
        m_bModifySeg = true;
        btnApply->Enable(true);
    }

    switch(segset)
    {
    case 0:
        Err = seg_len->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_len->SetFocus();
            seg_len->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.L)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = seg_r->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            seg_r->SetFocus();
            seg_r->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.D)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = segThick->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segThick->SetFocus();
            segThick->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Dn)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = segScrow->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            segScrow->SetFocus();
            segScrow->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.Ks)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = std_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            std_gap_text->SetFocus();
            std_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G0)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = min_gap_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            min_gap_text->SetFocus();
            min_gap_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.G1)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = Wedge_Text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            Wedge_Text->SetFocus();
            Wedge_Text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.l2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = gapangle_text->GetValue().ToDouble(&str1);
        if(!Err)
        {
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            gapangle_text->SetFocus();
            gapangle_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->segset.s2s)
        {
            m_bModifySeg=true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    segset = -1;
    event.Skip();
}

///零位界面
void MySetupDialog::OnChangeHeadx(wxCommandEvent& event)
{
    double x1,y1,z1,x2,y2,z2;
    double dist,azi,pitch;
    if(midb_checkbox->GetValue()==true)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        midx_text->GetValue().ToDouble(&x2);
        midy_text->GetValue().ToDouble(&y2);
        midz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalTail();
    }
    if(midb_checkbox->GetValue()==false && midf_checkbox->GetValue()==false)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeHeady(wxCommandEvent& event)
{
    double x1,y1,z1,x2,y2,z2;
    double dist,azi,pitch;
    if(midb_checkbox->GetValue()==true)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        midx_text->GetValue().ToDouble(&x2);
        midy_text->GetValue().ToDouble(&y2);
        midz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalTail();
    }
    if(midb_checkbox->GetValue()==false && midf_checkbox->GetValue()==false)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeHeadz(wxCommandEvent& event)
{
    double x1,y1,z1,x2,y2,z2;
    double dist,azi,pitch;
    if(midb_checkbox->GetValue()==true)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        midx_text->GetValue().ToDouble(&x2);
        midy_text->GetValue().ToDouble(&y2);
        midz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalTail();
    }
    if(midb_checkbox->GetValue()==false && midf_checkbox->GetValue()==false)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTailx(wxCommandEvent& event)
{
    double x1,y1,z1,x2,y2,z2;
    double dist,azi,pitch;
    if(midf_checkbox->GetValue()==true)
    {
        midx_text->GetValue().ToDouble(&x1);
        midy_text->GetValue().ToDouble(&y1);
        midz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalHead();
    }
    if(midb_checkbox->GetValue()==false && midf_checkbox->GetValue()==false)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTaily(wxCommandEvent& event)
{
    double x1,y1,z1,x2,y2,z2;
    double dist,azi,pitch;
    if(midf_checkbox->GetValue()==true)
    {
        midx_text->GetValue().ToDouble(&x1);
        midy_text->GetValue().ToDouble(&y1);
        midz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalHead();
    }
    if(midb_checkbox->GetValue()==false && midf_checkbox->GetValue()==false)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTailz(wxCommandEvent& event)
{
    double x1,y1,z1,x2,y2,z2;
    double dist,azi,pitch;
    if(midf_checkbox->GetValue()==true)
    {
        midx_text->GetValue().ToDouble(&x1);
        midy_text->GetValue().ToDouble(&y1);
        midz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalHead();
    }
    if(midb_checkbox->GetValue()==false && midf_checkbox->GetValue()==false)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeMidx(wxCommandEvent& event)
{
    double x1,y1,z1,x2,y2,z2;
    double dist,azi,pitch;
    if(midf_checkbox->GetValue()==true)
    {
        midx_text->GetValue().ToDouble(&x1);
        midy_text->GetValue().ToDouble(&y1);
        midz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalHead();
    }
    if(midb_checkbox->GetValue()==true)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        midx_text->GetValue().ToDouble(&x2);
        midy_text->GetValue().ToDouble(&y2);
        midz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalTail();
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeMidy(wxCommandEvent& event)
{
    double x1,y1,z1,x2,y2,z2;
    double dist,azi,pitch;
    if(midf_checkbox->GetValue()==true)
    {
        midx_text->GetValue().ToDouble(&x1);
        midy_text->GetValue().ToDouble(&y1);
        midz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalHead();
    }
    if(midb_checkbox->GetValue()==true)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        midx_text->GetValue().ToDouble(&x2);
        midy_text->GetValue().ToDouble(&y2);
        midz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalTail();
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeMidz(wxCommandEvent& event)
{
    double x1,y1,z1,x2,y2,z2;
    double dist,azi,pitch;
    if(midf_checkbox->GetValue()==true)
    {
        midx_text->GetValue().ToDouble(&x1);
        midy_text->GetValue().ToDouble(&y1);
        midz_text->GetValue().ToDouble(&z1);
        tailx_text->GetValue().ToDouble(&x2);
        taily_text->GetValue().ToDouble(&y2);
        tailz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalHead();
    }
    if(midb_checkbox->GetValue()==true)
    {
        headx_text->GetValue().ToDouble(&x1);
        heady_text->GetValue().ToDouble(&y1);
        headz_text->GetValue().ToDouble(&z1);
        midx_text->GetValue().ToDouble(&x2);
        midy_text->GetValue().ToDouble(&y2);
        midz_text->GetValue().ToDouble(&z2);
        dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist == 0.0)
        {
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
        }
        else
        {
            azi = atan2((y1-y2),(x1-x2));
            if(azi<0.0) azi = azi+2.0*PI;
            tbm_azi_text->SetValue(wxString::Format(_("%.4f"),azi*180.0/PI));
            pitch = atan((z1-z2)/dist);
            tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),pitch*180.0/PI));
        }
        CalTail();
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeUmidj(wxCommandEvent& event)
{
    if(midf_checkbox->GetValue()==true)
    {
        CalHead();
    }
    if(midb_checkbox->GetValue()==true)
    {
        CalTail();
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeDmidj(wxCommandEvent& event)
{
    if(midf_checkbox->GetValue()==true)
    {
        CalHead();
    }
    if(midb_checkbox->GetValue()==true)
    {
        CalTail();
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeLmidj(wxCommandEvent& event)
{
    if(midf_checkbox->GetValue()==true)
    {
        CalHead();
    }
    if(midb_checkbox->GetValue()==true)
    {
        CalTail();
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeRmidj(wxCommandEvent& event)
{
    if(midf_checkbox->GetValue()==true)
    {
        CalHead();
    }
    if(midb_checkbox->GetValue()==true)
    {
        CalTail();
    }
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}
void MySetupDialog::OnChangeTbmRoll(wxCommandEvent& event)
{
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTarX(wxCommandEvent& event)
{
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTarY(wxCommandEvent& event)
{
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTarZ(wxCommandEvent& event)
{
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTarAzi(wxCommandEvent& event)
{
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTarPitch(wxCommandEvent& event)
{
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTarRoll(wxCommandEvent& event)
{
    m_bModifyOrigin = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnHeadxClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        break;
    case 1:
        Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.roll)
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
        Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
        Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headx_text->g_kb;
            headx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 0;
    event.Skip();
}

void MySetupDialog::OnHeadyClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        break;
    case 2:
        Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.roll)
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
        Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
        Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete heady_text->g_kb;
            heady_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 1;
    event.Skip();
}

void MySetupDialog::OnHeadzClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        break;
    case 3:
        Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.roll)
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
        Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
        Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete headz_text->g_kb;
            headz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 2;
    event.Skip();
}

void MySetupDialog::OnTailxClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        break;
    case 4:
        Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.roll)
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
        Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
        Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailx_text->g_kb;
            tailx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 3;
    event.Skip();
}

void MySetupDialog::OnTailyClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        break;
    case 5:
        Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.roll)
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
        Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
        Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete taily_text->g_kb;
            taily_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 4;
    event.Skip();
}

void MySetupDialog::OnTailzClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        break;
    case 6:
        Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.roll)
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
        Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
        Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tailz_text->g_kb;
            tailz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 5;
    event.Skip();
}

void MySetupDialog::OnTbmrollClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
        Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
        Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tbmroll_text->g_kb;
            tbmroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 6;
    event.Skip();
}

void MySetupDialog::OnTarxClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:

        break;
    case 8:
        Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
        Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
        Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarx_text->g_kb;
            tarx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 7;
    event.Skip();
}

void MySetupDialog::OnTaryClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
        Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
        Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tary_text->g_kb;
            tary_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 8;
    event.Skip();
}

void MySetupDialog::OnTarzClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
		Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:

        break;
    case 10:
        Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
        Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarz_text->g_kb;
            tarz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 9;
    event.Skip();
}

void MySetupDialog::OnTaraziClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
		Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
        break;
    case 11:
        Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarazi_text->g_kb;
            tarazi_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 10;
    event.Skip();
}

void MySetupDialog::OnTarpitchClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
		Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
		Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarpitch_text->g_kb;
            tarpitch_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 11;
    event.Skip();
}

void MySetupDialog::OntarrollClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
		Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
		Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
		Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:

        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete tarroll_text->g_kb;
            tarroll_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 12;
    event.Skip();
}

void MySetupDialog::OnMidxClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
		Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
		Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
		Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:

        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midx_text->g_kb;
            midx_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 13;
    event.Skip();
}

void MySetupDialog::OnMidyClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
		Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
		Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
		Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:

        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midy_text->g_kb;
            midy_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 14;
    event.Skip();
}

void MySetupDialog::OnMidzClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
		Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
		Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
		Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;

            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:

        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete midz_text->g_kb;
            midz_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 15;
    event.Skip();
}

void MySetupDialog::OnUpmidClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
		Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
		Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
		Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:

        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete up_mid_text->g_kb;
            up_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 16;
    event.Skip();
}

void MySetupDialog::OnDownmidClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
		Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
		Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
		Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:

        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete down_mid_text->g_kb;
            down_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 17;
    event.Skip();
}

void MySetupDialog::OnLeftmidClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
		Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
		Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
		Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:

        break;
    case 19:
        Err = right_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete left_mid_text->g_kb;
            left_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            right_mid_text->SetFocus();
            right_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[3])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    origset = 18;
    event.Skip();
}

void MySetupDialog::OnRightClick(wxMouseEvent& event)
{
    double str1;
    bool Err;
    switch(origset)
    {
    case 0:
        Err = headx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headx_text->SetFocus();
            headx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = heady_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            heady_text->SetFocus();
            heady_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 2:
		Err = headz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            headz_text->SetFocus();
            headz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.head[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 3:
		Err = tailx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailx_text->SetFocus();
            tailx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 4:
		Err = taily_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            taily_text->SetFocus();
            taily_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 5:
		Err = tailz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tailz_text->SetFocus();
            tailz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.tail[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 6:
		Err = tbmroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tbmroll_text->SetFocus();
            tbmroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = tarx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarx_text->SetFocus();
            tarx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 8:
		Err = tary_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tary_text->SetFocus();
            tary_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tarz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarz_text->SetFocus();
            tarz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.prism[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 10:
		Err = tarazi_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarazi_text->SetFocus();
            tarazi_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 11:
		Err = tarpitch_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarpitch_text->SetFocus();
            tarpitch_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 12:
        Err = tarroll_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tarroll_text->SetFocus();
            tarroll_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->azi[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 13:
        Err = midx_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midx_text->SetFocus();
            midx_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 14:
        Err = midy_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midy_text->SetFocus();
            midy_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 15:
        Err = midz_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            midz_text->SetFocus();
            midz_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.mid[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 16:
        Err = up_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            up_mid_text->SetFocus();
            up_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[0])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 17:
        Err = down_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            down_mid_text->SetFocus();
            down_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[1])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 18:
        Err = left_mid_text->GetValue().ToDouble(&str1);
        if(!Err)
        {

            delete right_mid_text->g_kb;
            right_mid_text->g_kb=0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            left_mid_text->SetFocus();
            left_mid_text->SetSelection(-1,-1);
            return;
        }
        if(str1 != mtg->m0.midj[2])
        {
            m_bModifyOrigin =true;
            btnApply->Enable(true);
        }
        break;
    case 19:

        break;
    default:
        break;

    }
    origset = 19;
    event.Skip();
}

void MySetupDialog::OnBtnMeas(wxCommandEvent& event)
{
    //FILE* fp = fopen("E:\\testori.log","w");
    //fprintf(fp,"%.4f,%.4f\n",mtg->m.inc[0],mtg->m.inc[1]);
    if(mtg_start_origin(mtg)==-1)
    {
        WriteMsg(_("零位测量失败，请检查硬件连接或先停止测量..."),1);
    }
    else
    {
        if(mtg->tbm.type==1)
        {
            up_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->plc.ubaj*1000.0));
            down_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->plc.dbaj*1000.0));
            left_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->plc.lbaj*1000.0));
            right_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->plc.rbaj*1000.0));
        }
        else if(mtg->tbm.type==2)
        {
            up_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->plc.ufaj*1000.0));
            down_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->plc.dfaj*1000.0));
            left_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->plc.lfaj*1000.0));
            right_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->plc.rfaj*1000.0));
        }
        else
        {
            up_mid_text->SetValue(wxString::Format(_("%.1f"),0));
            down_mid_text->SetValue(wxString::Format(_("%.1f"),0));
            left_mid_text->SetValue(wxString::Format(_("%.1f"),0));
            right_mid_text->SetValue(wxString::Format(_("%.1f"),0));
        }
        //fprintf(fp,"%.4f,%.4f\n",mtg->m.inc[0],mtg->m.inc[1]);
        //mtg->origincal=0;
        //mtg_cal_angle(mtg);
        //fprintf(fp,"%.4f,%.4f\n",mtg->m.inc[0],mtg->m.inc[1]);
    }

    //fclose(fp);
}

///数据管理
void MySetupDialog::OnClientIP1Click(wxMouseEvent& event)
{
    long str1;
    bool Err;
    wxString str2;
    str2 = wxString(mtg->comset[4].ip,wxConvUTF8);
    //str2 = str2.Left(3);
    str2 = str2.SubString(2,8);
    switch(dataset)
    {
    case 0:
        break;
    case 1:
        Err = client_ip_text2->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text1->g_kb;
            client_ip_text1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            client_ip_text2->SetFocus();
            client_ip_text2->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text2->GetValue().Cmp(clientip2)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = client_ip_text3->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text1->g_kb;
            client_ip_text1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            client_ip_text3->SetFocus();
            client_ip_text3->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text3->GetValue().Cmp(clientip3)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = client_ip_text4->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text1->g_kb;
            client_ip_text1->g_kb = 0;

            client_ip_text4->SetFocus();
            client_ip_text4->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text4->GetValue().Cmp(clientip4)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    dataset = 0;
    event.Skip();
}

void MySetupDialog::OnClientIP2Click(wxMouseEvent& event)
{
    long str1;
    bool Err;
    wxString str2;
    str2 = wxString(mtg->comset[4].ip,wxConvUTF8);
    //str2 = str2.Left(3);
    str2 = str2.SubString(2,8);
    switch(dataset)
    {
    case 0:
		Err = client_ip_text1->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text2->g_kb;
            client_ip_text2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            client_ip_text1->SetFocus();
            client_ip_text1->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text1->GetValue().Cmp(clientip1)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        break;
    case 2:
        Err = client_ip_text3->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text2->g_kb;
            client_ip_text2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            client_ip_text3->SetFocus();
            client_ip_text3->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text3->GetValue().Cmp(clientip3)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = client_ip_text4->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text2->g_kb;
            client_ip_text2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            client_ip_text4->SetFocus();
            client_ip_text4->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text4->GetValue().Cmp(clientip4)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    dataset = 1;
    event.Skip();
}

void MySetupDialog::OnClientIP3Click(wxMouseEvent& event)
{
    long str1;
    bool Err;
    wxString str2;
    str2 = wxString(mtg->comset[4].ip,wxConvUTF8);
    //str2 = str2.Left(3);
    str2 = str2.SubString(2,8);
    switch(dataset)
    {
    case 0:
		Err = client_ip_text1->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text3->g_kb;
            client_ip_text3->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            client_ip_text1->SetFocus();
            client_ip_text1->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text1->GetValue().Cmp(clientip1)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = client_ip_text2->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text3->g_kb;
            client_ip_text3->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            client_ip_text2->SetFocus();
            client_ip_text2->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text2->GetValue().Cmp(clientip2)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    case 2:

        break;
    case 3:
        Err = client_ip_text4->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text3->g_kb;
            client_ip_text3->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            client_ip_text4->SetFocus();
            client_ip_text4->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text4->GetValue().Cmp(clientip4)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;
    }
    dataset = 2;
    event.Skip();
}

void MySetupDialog::OnClientIP4Click(wxMouseEvent& event)
{
    long str1;
    bool Err;
    wxString str2;
    str2 = wxString(mtg->comset[4].ip,wxConvUTF8);
    //str2 = str2.Left(3);
    str2 = str2.SubString(2,8);
    switch(dataset)
    {
    case 0:
		Err = client_ip_text1->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text4->g_kb;
            client_ip_text4->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            client_ip_text1->SetFocus();
            client_ip_text1->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text1->GetValue().Cmp(clientip1)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    case 1:
		Err = client_ip_text2->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text4->g_kb;
            client_ip_text4->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            client_ip_text2->SetFocus();
            client_ip_text2->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text2->GetValue().Cmp(clientip2)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = client_ip_text3->GetValue().ToLong(&str1);
        if(!Err)
        {

            delete client_ip_text4->g_kb;
            client_ip_text4->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            client_ip_text3->SetFocus();
            client_ip_text3->SetSelection(-1,-1);
            return;
        }
        if(client_ip_text3->GetValue().Cmp(clientip3)!=0)
        {
            m_bModifyData = true;
            btnApply->Enable(true);
        }
        break;
    case 3:

        break;
    default:
        break;
    }
    dataset = 3;
    event.Skip();
}


/*void MySetupDialog::OnBtnDBPathClick(wxCommandEvent& event)
{
    wxDirDialog dlg(this,_("请选择数据库备份路径"),wxEmptyString,wxDD_DEFAULT_STYLE,wxDefaultPosition,wxDefaultSize,_("数据库备份"));
    if(dlg.ShowModal()==wxID_OK)
    {
        wxString str=dlg.GetPath();
        //dbPath1 = str+_("\\mtg_data_temp.prj");
        //dbPath2 = str+_("\\mtg_data.prj");
        //db_backuppath_text->SetValue(str);
        //SaveDatabase();
        m_bModifyData = true;
        btnApply->Enable(true);
    }
    dataset = -1;
}*/

/*void MySetupDialog::OnBtnReportClick(wxCommandEvent& event)
{
   wxDirDialog dlg(this,_("请选择数据库备份路径"),wxEmptyString,wxDD_DEFAULT_STYLE,wxDefaultPosition,wxDefaultSize,_("数据库备份"));
    if(dlg.ShowModal()==wxID_OK)
    {
        wxString str=dlg.GetPath();
        //report_path_text->SetValue(str);
        m_bModifyData = true;
        btnApply->Enable(true);
    }
    dataset = -1;
}*/

void MySetupDialog::OnChangeClientIP1(wxCommandEvent& event)
{
    m_bModifyData = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeClientIP2(wxCommandEvent& event)
{
    m_bModifyData = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeClientIP3(wxCommandEvent& event)
{
    m_bModifyData = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeClientIP4(wxCommandEvent& event)
{
    m_bModifyData = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTbmIP1(wxCommandEvent& event)
{
    m_bModifyData = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTbmIP2(wxCommandEvent& event)
{
    m_bModifyData = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTbmIP3(wxCommandEvent& event)
{
    m_bModifyData = true;
    btnApply->Enable(true);
}

void MySetupDialog::OnChangeTbmIP4(wxCommandEvent& event)
{
    m_bModifyData = true;
    btnApply->Enable(true);
}



///测量界面
void MySetupDialog::OnMeastime1Click(wxMouseEvent& event)
{
    long str1;
    double str2;
    bool Err;
    switch(measet)
    {
    case 0:

        break;
    case 1:
        Err = measTime2->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime1->g_kb;
            measTime1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime2->SetFocus();
            measTime2->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.backcycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = horiDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime1->g_kb;
            measTime1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            horiDiff->SetFocus();
            horiDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_dev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = verDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime1->g_kb;
            measTime1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            verDiff->SetFocus();
            verDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_jdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = angleDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime1->g_kb;
            measTime1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            angleDiff->SetFocus();
            angleDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = diffChange->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime1->g_kb;
            measTime1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            diffChange->SetFocus();
            diffChange->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_timing)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = backDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime1->g_kb;
            measTime1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backDiff->SetFocus();
            backDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = corr_dist_text->GetValue().ToDouble(&str2);
        if(!Err)
        {
            delete measTime1->g_kb;
            measTime1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_dist_text->SetFocus();
            corr_dist_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.fit_len)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = corr_diff_text->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime1->g_kb;
            measTime1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_diff_text->SetFocus();
            corr_diff_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwcorr)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tolTime->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime1->g_kb;
            measTime1->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tolTime->SetFocus();
            tolTime->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwtime)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    measet = 0;
    event.Skip();
}

void MySetupDialog::OnMeastime2Click(wxMouseEvent& event)
{
    long str1;
    double str2;
    bool Err;
    switch(measet)
    {
    case 0:
		Err = measTime1->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime2->g_kb;
            measTime2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime1->SetFocus();
            measTime1->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.cycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 1:

        break;
    case 2:
        Err = horiDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime2->g_kb;
            measTime2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            horiDiff->SetFocus();
            horiDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_dev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = verDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime2->g_kb;
            measTime2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            verDiff->SetFocus();
            verDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_jdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = angleDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime2->g_kb;
            measTime2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            angleDiff->SetFocus();
            angleDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = diffChange->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime2->g_kb;
            measTime2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            diffChange->SetFocus();
            diffChange->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_timing)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = backDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime2->g_kb;
            measTime2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backDiff->SetFocus();
            backDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = corr_dist_text->GetValue().ToDouble(&str2);
        if(!Err)
        {
            delete measTime2->g_kb;
            measTime2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_dist_text->SetFocus();
            corr_dist_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.fit_len)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = corr_diff_text->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime2->g_kb;
            measTime2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_diff_text->SetFocus();
            corr_diff_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwcorr)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tolTime->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete measTime2->g_kb;
            measTime2->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tolTime->SetFocus();
            tolTime->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwtime)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    measet = 1;
    event.Skip();
}

void MySetupDialog::OnHoridiffClick(wxMouseEvent& event)
{
    long str1;
    double str2;
    bool Err;
    switch(measet)
    {
    case 0:
		Err = measTime1->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete horiDiff->g_kb;
            horiDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime1->SetFocus();
            measTime1->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.cycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = measTime2->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete horiDiff->g_kb;
            horiDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime2->SetFocus();
            measTime2->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.backcycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 2:

        break;
    case 3:
        Err = verDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete horiDiff->g_kb;
            horiDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            verDiff->SetFocus();
            verDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_jdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = angleDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete horiDiff->g_kb;
            horiDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            angleDiff->SetFocus();
            angleDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = diffChange->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete horiDiff->g_kb;
            horiDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            diffChange->SetFocus();
            diffChange->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_timing)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = backDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete horiDiff->g_kb;
            horiDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backDiff->SetFocus();
            backDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = corr_dist_text->GetValue().ToDouble(&str2);
        if(!Err)
        {
            delete horiDiff->g_kb;
            horiDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_dist_text->SetFocus();
            corr_dist_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.fit_len)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = corr_diff_text->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete horiDiff->g_kb;
            horiDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_diff_text->SetFocus();
            corr_diff_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwcorr)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tolTime->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete horiDiff->g_kb;
            horiDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tolTime->SetFocus();
            tolTime->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwtime)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    measet = 2;
    event.Skip();
}

void MySetupDialog::OnVerdiffClick(wxMouseEvent& event)
{
    long str1;
    double str2;
    bool Err;
    switch(measet)
    {
    case 0:
		Err = measTime1->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete verDiff->g_kb;
            verDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime1->SetFocus();
            measTime1->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.cycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = measTime2->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete verDiff->g_kb;
            verDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime2->SetFocus();
            measTime2->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.backcycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = horiDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete verDiff->g_kb;
            verDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            horiDiff->SetFocus();
            horiDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_dev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 3:

        break;
    case 4:
        Err = angleDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete verDiff->g_kb;
            verDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            angleDiff->SetFocus();
            angleDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = diffChange->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete verDiff->g_kb;
            verDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            diffChange->SetFocus();
            diffChange->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_timing)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = backDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete verDiff->g_kb;
            verDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backDiff->SetFocus();
            backDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = corr_dist_text->GetValue().ToDouble(&str2);
        if(!Err)
        {
            delete verDiff->g_kb;
            verDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_dist_text->SetFocus();
            corr_dist_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.fit_len)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = corr_diff_text->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete verDiff->g_kb;
            verDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_diff_text->SetFocus();
            corr_diff_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwcorr)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tolTime->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete verDiff->g_kb;
            verDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tolTime->SetFocus();
            tolTime->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwtime)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    measet = 3;
    event.Skip();
}

void MySetupDialog::OnAnglediffClick(wxMouseEvent& event)
{
    long str1;
    double str2;
    bool Err;
    switch(measet)
    {
    case 0:
		Err = measTime1->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete angleDiff->g_kb;
            angleDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime1->SetFocus();
            measTime1->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.cycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = measTime2->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete angleDiff->g_kb;
            angleDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime2->SetFocus();
            measTime2->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.backcycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = horiDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete angleDiff->g_kb;
            angleDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            horiDiff->SetFocus();
            horiDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = verDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete angleDiff->g_kb;
            angleDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            verDiff->SetFocus();
            verDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_jdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 4:

        break;
    case 5:
        Err = diffChange->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete angleDiff->g_kb;
            angleDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            diffChange->SetFocus();
            diffChange->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_timing)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = backDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete angleDiff->g_kb;
            angleDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backDiff->SetFocus();
            backDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = corr_dist_text->GetValue().ToDouble(&str2);
        if(!Err)
        {
            delete angleDiff->g_kb;
            angleDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_dist_text->SetFocus();
            corr_dist_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.fit_len)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = corr_diff_text->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete angleDiff->g_kb;
            angleDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_diff_text->SetFocus();
            corr_diff_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwcorr)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tolTime->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete angleDiff->g_kb;
            angleDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tolTime->SetFocus();
            tolTime->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwtime)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    measet = 4;
    event.Skip();
}

void MySetupDialog::OnDiffchangeClick(wxMouseEvent& event)
{
    long str1;
    double str2;
    bool Err;
    switch(measet)
    {
    case 0:
		Err = measTime1->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete diffChange->g_kb;
            diffChange->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime1->SetFocus();
            measTime1->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.cycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = measTime2->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete diffChange->g_kb;
            diffChange->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime2->SetFocus();
            measTime2->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.backcycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = horiDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete diffChange->g_kb;
            diffChange->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            horiDiff->SetFocus();
            horiDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_dev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = verDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete diffChange->g_kb;
            diffChange->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            verDiff->SetFocus();
            verDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_jdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = angleDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete diffChange->g_kb;
            diffChange->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            angleDiff->SetFocus();
            angleDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 5:

        break;
    case 6:
        Err = backDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete diffChange->g_kb;
            diffChange->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backDiff->SetFocus();
            backDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = corr_dist_text->GetValue().ToDouble(&str2);
        if(!Err)
        {
            delete diffChange->g_kb;
            diffChange->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_dist_text->SetFocus();
            corr_dist_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.fit_len)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = corr_diff_text->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete diffChange->g_kb;
            diffChange->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_diff_text->SetFocus();
            corr_diff_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwcorr)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tolTime->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete diffChange->g_kb;
            diffChange->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tolTime->SetFocus();
            tolTime->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwtime)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    measet = 5;
    event.Skip();
}

void MySetupDialog::OnBackdiffClick(wxMouseEvent& event)
{
    long str1;
    double str2;
    bool Err;
    switch(measet)
    {
    case 0:
		Err = measTime1->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete backDiff->g_kb;
            backDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime1->SetFocus();
            measTime1->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.cycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = measTime2->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete backDiff->g_kb;
            backDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime2->SetFocus();
            measTime2->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.backcycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = horiDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete backDiff->g_kb;
            backDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            horiDiff->SetFocus();
            horiDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_dev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = verDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete backDiff->g_kb;
            backDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            verDiff->SetFocus();
            verDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_jdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = angleDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete backDiff->g_kb;
            backDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            angleDiff->SetFocus();
            angleDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = diffChange->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete backDiff->g_kb;
            backDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            diffChange->SetFocus();
            diffChange->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_timing)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 6:

        break;
    case 7:
        Err = corr_dist_text->GetValue().ToDouble(&str2);
        if(!Err)
        {
            delete backDiff->g_kb;
            backDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_dist_text->SetFocus();
            corr_dist_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.fit_len)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = corr_diff_text->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete backDiff->g_kb;
            backDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_diff_text->SetFocus();
            corr_diff_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwcorr)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tolTime->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete backDiff->g_kb;
            backDiff->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tolTime->SetFocus();
            tolTime->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwtime)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    measet = 6;
    event.Skip();
}

void MySetupDialog::OnCorrdistClick(wxMouseEvent& event)
{
    long str1;
    double str2;
    bool Err;
    switch(measet)
    {
    case 0:
		Err = measTime1->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_dist_text->g_kb;
            corr_dist_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime1->SetFocus();
            measTime1->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.cycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = measTime2->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_dist_text->g_kb;
            corr_dist_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime2->SetFocus();
            measTime2->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.backcycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = horiDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_dist_text->g_kb;
            corr_dist_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            horiDiff->SetFocus();
            horiDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_dev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = verDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_dist_text->g_kb;
            corr_dist_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            verDiff->SetFocus();
            verDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_jdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = angleDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_dist_text->g_kb;
            corr_dist_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            angleDiff->SetFocus();
            angleDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = diffChange->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_dist_text->g_kb;
            corr_dist_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            diffChange->SetFocus();
            diffChange->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_timing)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = backDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_dist_text->g_kb;
            corr_dist_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backDiff->SetFocus();
            backDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 7:

        break;
    case 8:
        Err = corr_diff_text->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_dist_text->g_kb;
            corr_dist_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_diff_text->SetFocus();
            corr_diff_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwcorr)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 9:
        Err = tolTime->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_dist_text->g_kb;
            corr_dist_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tolTime->SetFocus();
            tolTime->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwtime)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    measet = 7;
    event.Skip();
}

void MySetupDialog::OnCorrdiffClick(wxMouseEvent& event)
{
    long str1;
    double str2;
    bool Err;
    switch(measet)
    {
    case 0:
		Err = measTime1->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_diff_text->g_kb;
            corr_diff_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime1->SetFocus();
            measTime1->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.cycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = measTime2->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_diff_text->g_kb;
            corr_diff_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime2->SetFocus();
            measTime2->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.backcycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = horiDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_diff_text->g_kb;
            corr_diff_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            horiDiff->SetFocus();
            horiDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_dev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = verDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_diff_text->g_kb;
            corr_diff_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            verDiff->SetFocus();
            verDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_jdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = angleDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_diff_text->g_kb;
            corr_diff_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            angleDiff->SetFocus();
            angleDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = diffChange->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_diff_text->g_kb;
            corr_diff_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            diffChange->SetFocus();
            diffChange->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_timing)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = backDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_diff_text->g_kb;
            corr_diff_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backDiff->SetFocus();
            backDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = corr_dist_text->GetValue().ToDouble(&str2);
        if(!Err)
        {
            delete corr_diff_text->g_kb;
            corr_diff_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_dist_text->SetFocus();
            corr_dist_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.fit_len)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        break;
    case 9:
        Err = tolTime->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete corr_diff_text->g_kb;
            corr_diff_text->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            tolTime->SetFocus();
            tolTime->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwtime)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    default:
        break;

    }
    measet = 8;
    event.Skip();
}

void MySetupDialog::OnToltimeClcik(wxMouseEvent& event)
{
    long str1;
    double str2;
    bool Err;
    switch(measet)
    {
    case 0:
		Err = measTime1->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete tolTime->g_kb;
            tolTime->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime1->SetFocus();
            measTime1->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.cycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 1:
        Err = measTime2->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete tolTime->g_kb;
            tolTime->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            measTime2->SetFocus();
            measTime2->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.backcycle)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 2:
        Err = horiDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete tolTime->g_kb;
            tolTime->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            horiDiff->SetFocus();
            horiDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_dev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 3:
        Err = verDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete tolTime->g_kb;
            tolTime->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            verDiff->SetFocus();
            verDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_jdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 4:
        Err = angleDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete tolTime->g_kb;
            tolTime->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            angleDiff->SetFocus();
            angleDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 5:
        Err = diffChange->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete tolTime->g_kb;
            tolTime->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            diffChange->SetFocus();
            diffChange->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_timing)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 6:
        Err = backDiff->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete tolTime->g_kb;
            tolTime->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            backDiff->SetFocus();
            backDiff->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alw_bdev)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 7:
        Err = corr_dist_text->GetValue().ToDouble(&str2);
        if(!Err)
        {
            delete tolTime->g_kb;
            tolTime->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_dist_text->SetFocus();
            corr_dist_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.fit_len)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
        break;
    case 8:
        Err = corr_diff_text->GetValue().ToLong(&str1);
        if(!Err)
        {
            delete tolTime->g_kb;
            tolTime->g_kb = 0;
            wxMessageBox(_("输入错误数据，请重新输入！"),_("错误"),wxOK|wxICON_ERROR);
            corr_diff_text->SetFocus();
            corr_diff_text->SetSelection(-1,-1);
            return;
        }
        if(str1!=mtg->measet.alwcorr)
        {
            m_bModifyMea = true;
            btnApply->Enable(true);
        }
		break;
    case 9:

        break;
    default:
        break;

    }
    measet = 9;
    event.Skip();
}


void MySetupDialog::OnChangeMeasTime(wxCommandEvent& event)
{
    long tempstr;
    int tempval;
    measTime1->GetValue().ToLong(&tempstr);
    tempval=tempstr;
    if(tempval!=mtg->measet.cycle)
    {
        m_bModifyMea=true;
        btnApply->Enable(true);
    }
}
void MySetupDialog::OnChangeBackTime(wxCommandEvent& event)
{
    long tempstr;
    int tempval;
    measTime2->GetValue().ToLong(&tempstr);
    tempval=tempstr;
    if(tempval!=mtg->measet.backcycle)
    {
        m_bModifyMea=true;
        btnApply->Enable(true);
    }
}
void MySetupDialog::OnChangeHtol(wxCommandEvent& event)
{
    long tempstr;
    int tempval;
    horiDiff->GetValue().ToLong(&tempstr);
    tempval=tempstr;
    if(tempval!=mtg->measet.alw_dev)
    {
        m_bModifyMea=true;
        btnApply->Enable(true);
    }
}
void MySetupDialog::OnChangeVtol(wxCommandEvent& event)
{
    long tempstr;
    int tempval;
    verDiff->GetValue().ToLong(&tempstr);
    tempval=tempstr;
    if(tempval!=mtg->measet.alw_jdev)
    {
        m_bModifyMea=true;
        btnApply->Enable(true);
    }
}
void MySetupDialog::OnChangeGtol(wxCommandEvent& event)
{
    long tempstr;
    int tempval;
    angleDiff->GetValue().ToLong(&tempstr);
    tempval=tempstr;
    if(tempval!=mtg->measet.alw_bdev)
    {
        m_bModifyMea=true;
        btnApply->Enable(true);
    }
}
void MySetupDialog::OnChangeDtol(wxCommandEvent& event)
{
    long tempstr;
    int tempval;
    diffChange->GetValue().ToLong(&tempstr);
    tempval=tempstr;
    if(tempval!=mtg->measet.alw_timing)
    {
        m_bModifyMea=true;
        btnApply->Enable(true);
    }
}
void MySetupDialog::OnChangeBtol(wxCommandEvent& event)
{
    long tempstr;
    int tempval;
    backDiff->GetValue().ToLong(&tempstr);
    tempval=tempstr;
    if(tempval!=mtg->measet.alw_bdev)
    {
        m_bModifyMea=true;
        btnApply->Enable(true);
    }
}
void MySetupDialog::OnChangeDist(wxCommandEvent& event)
{
    double tempval;
    corr_dist_text->GetValue().ToDouble(&tempval);
    if(tempval!=mtg->measet.fit_len)
    {
        m_bModifyMea=true;
        btnApply->Enable(true);
    }
}
void MySetupDialog::OnChangeCorrtol(wxCommandEvent& event)
{
    long tempstr;
    int tempval;
    corr_diff_text->GetValue().ToLong(&tempstr);
    tempval=tempstr;
    if(tempval!=mtg->measet.alwcorr)
    {
        m_bModifyMea=true;
        btnApply->Enable(true);
    }
}
void MySetupDialog::OnChangeToltime(wxCommandEvent& event)
{
    long tempstr;
    int tempval;
    tolTime->GetValue().ToLong(&tempstr);
    tempval=tempstr;
    if(tempval!=mtg->measet.alwtime)
    {
        m_bModifyMea=true;
        btnApply->Enable(true);
    }
}
///用户权限
void MySetupDialog::OnBtnAddUserClick(wxCommandEvent& event)
{
    UserManagerDlg dlg(this);
    dlg.Center();
    dlg.StaticText5->SetLabel(_("添加用户"));
    if(dlg.ShowModal() == wxID_OK)
    {
        for(int i=0;i<mtg->nuser;i++)
        {
            if(dlg.Name->GetValue().Cmp(wxString((const char*)mtg->user[i].name,wxConvLocal))==0)
            {
                if(dlg.Name->g_kb)
                {
                    delete dlg.Name->g_kb;
                    dlg.Name->g_kb=0;
                }
                if(dlg.Password->g_kb)
                {
                    delete dlg.Password->g_kb;
                    dlg.Password->g_kb=0;
                }
                wxMessageBox(_("用户名重复，请检查!"));
                wxCommandEvent e;
                OnBtnAddUserClick(e);
                return;
            }
        }
        if(dlg.Name->GetValue().IsEmpty())
        {
            if(dlg.Name->g_kb)
            {
                delete dlg.Name->g_kb;
                dlg.Name->g_kb=0;
            }
            if(dlg.Password->g_kb)
            {
                delete dlg.Password->g_kb;
                dlg.Password->g_kb=0;
            }
            wxMessageBox(_("用户名不能为空!"));
            wxCommandEvent e;
            OnBtnAddUserClick(e);
            return;
        }
        MTG_USER u={0};
        strncpy(u.name,dlg.Name->GetValue().mb_str(wxConvUTF8),64);
        strncpy(u.password,dlg.Password->GetValue().mb_str(wxConvUTF8),64);
        u.level = dlg.levelChoice->GetSelection();
        mtg_add_user(mtg,&u);
        //mtg_send_addacount(mtg,&u);
        UpdateUser();
        listUser->Select(mtg->nuser-1);
        //GraphBlock->Refresh();
    }
    else
    {
        return;
    }
}

void MySetupDialog::OnBtnDelUserClick(wxCommandEvent& event)
{
    int n = listUser->GetFirstSelected();
    int Num = listUser->GetItemCount();

    if(n<0 || n>=Num) return;

    wxMessageDialog dlg(this,_("删除操作将不可恢复\n确定要进行删除吗？"),_("用户设置"),wxYES_NO|wxICON_INFORMATION);
    if(dlg.ShowModal() == wxID_YES)
    {

        n = mtg_remove_user(mtg,n);
        //mtg_send_removeacount(mtg,n);
        UpdateUser();
        if(n+1<Num)
        {
            listUser->Select(n);
        }
        else if(n-1>=0)
        {
            listUser->Select(n-1);
        }
        else
        {
            btnEditUser->Enable(false);
            btnDelUser->Enable(false);
        }

        //UpdateBlock();
        //listBlock->Select(mtg->nblk-1);
        //GraphBlock->Refresh();
    }
    else
    {
        return;
    }
}

void MySetupDialog::OnBtnEditUserClick(wxCommandEvent& event)
{
    UserManagerDlg dlg(this);
    dlg.Center();
    dlg.StaticText5->SetLabel(_("编辑用户"));
    int n = listUser->GetFirstSelected();
    int Num = listUser->GetItemCount();
    if(n<0 || n>=Num) return;
    dlg.Name->SetValue(wxString(mtg->user[n].name,wxConvUTF8));
    dlg.Password->SetValue(wxString(mtg->user[n].password,wxConvUTF8));
    dlg.levelChoice->SetSelection(mtg->user[n].level);
    if(n==0) dlg.levelChoice->Enable(false);
    if(dlg.ShowModal() == wxID_OK)
    {
        MTG_USER u={0};
        strncpy(u.name,dlg.Name->GetValue().mb_str(wxConvUTF8),64);
        strncpy(u.password,dlg.Password->GetValue().mb_str(wxConvUTF8),64);
        u.level = dlg.levelChoice->GetSelection();
        mtg_modify_user(mtg,n,&u);
        //mtg_send_modifyacount(mtg,n,&u);
        UpdateUser();
        listUser->Select(mtg->nuser-1);
        //GraphBlock->Refresh();
    }
    else
    {
        return;
    }
}

///语言选择
void MySetupDialog::SetLang1(wxCommandEvent& event)
{
    if(lang2_checkbox->GetValue()==false && lang3_checkbox->GetValue()==false)
    {
        lang1_checkbox->SetValue(true);
    }
    else
    {
        lang2_checkbox->SetValue(false);
        lang3_checkbox->SetValue(false);

        m_bModifySeg = true;
        btnApply->Enable(true);
    }
}

void MySetupDialog::SetLang2(wxCommandEvent& event)
{
    if(lang1_checkbox->GetValue()==false && lang3_checkbox->GetValue()==false)
    {
        lang2_checkbox->SetValue(true);
    }
    else
    {
        lang1_checkbox->SetValue(false);
        lang3_checkbox->SetValue(false);

        m_bModifySeg = true;
        btnApply->Enable(true);
    }
}

void MySetupDialog::SetLang3(wxCommandEvent& event)
{
    if(lang1_checkbox->GetValue()==false && lang2_checkbox->GetValue()==false)
    {
        lang3_checkbox->SetValue(true);
    }
    else
    {
        lang1_checkbox->SetValue(false);
        lang2_checkbox->SetValue(false);

        m_bModifySeg = true;
        btnApply->Enable(true);
    }
}

/*void MySetupDialog::OnChangeMOP(wxCommandEvent& event)
{
    m_bModifyAdmin=true;
    btnApply->Enable(true);
}
void MySetupDialog::OnChangeMNP(wxCommandEvent& event)
{
    m_bModifyAdmin=true;
    btnApply->Enable(true);
}
void MySetupDialog::OnChangeMPC(wxCommandEvent& event)
{
    m_bModifyAdmin=true;
    btnApply->Enable(true);
}
void MySetupDialog::OnChangeOOP(wxCommandEvent& event)
{
    m_bModifyDriver=true;
    btnApply->Enable(true);
}
void MySetupDialog::OnChangeONP(wxCommandEvent& event)
{
    m_bModifyDriver=true;
    btnApply->Enable(true);
}
void MySetupDialog::OnChangeOPC(wxCommandEvent& event)
{
    m_bModifyDriver=true;
    btnApply->Enable(true);
}
///语言选择
void MySetupDialog::OnLangSelect(wxCommandEvent& event)
{
    m_bModifyLang=true;
    btnApply->Enable(true);
}*/

///设置应用
void MySetupDialog::OnBtnApply(wxCommandEvent& event)
{
    //FILE* fp = fopen("E:\\tst.log","w");
    /*if(mtg->client_type==2 && mtg->control_mode==1)
    {
        return;
    }*/
    long num1,num2;
    if(m_bModifyPrj)
    {
        strncpy(mtg->prj.name,prj_name->GetValue().mb_str(wxConvUTF8),64);
        prj_mile1->GetValue().ToDouble(&mtg->prj.mile1);
        prj_mile2->GetValue().ToDouble(&mtg->prj.mile2);
        //mtg->prj.direction=direct_choice->GetSelection();
        if(forward_checkbox->GetValue()==true)
        {
            mtg->prj.a2z=0;
        }
        else
        {
            mtg->prj.a2z=1;
        }
        day_hour->GetValue().ToLong(&num1);
        mtg->prj.t1[0] = num1;
        day_min->GetValue().ToLong(&num2);
        mtg->prj.t1[0] = num2;
        //mtg->prj.dayOperate = num1*3600+num2*60;
        night_hour->GetValue().ToLong(&num1);
        mtg->prj.t1[0] = num1;
        night_min->GetValue().ToLong(&num2);
        mtg->prj.t1[0] = num2;
        //mtg->prj.nightOperate = num1*3600+num2*60;
        tip_text->GetValue().ToDouble(&mtg->prj.tip);
        //mtg->prj.direction=direction;
        //strncpy(mtg->prj.company,textCompany->GetValue().mb_str(wxConvUTF8),64);
        //strncpy(mtg->prj.date_time,textTime->GetValue().mb_str(wxConvUTF8),64);
        //strncpy(mtg->prj.author,textAuthor->GetValue().mb_str(wxConvUTF8),64);
        //strncpy(mtg->prj.remarks,textRemarks->GetValue().mb_str(wxConvUTF8),64);
        mtg_store_prj(mtg);
        if(mtg->client_type==1 && mtg->control_mode==1)
        {
            if(mtg->iclient==1  && mtg->peeking==0) client_prj(mtg,0);
        }
        else if(mtg->client_type==2 && mtg->control_mode==2)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_prj(mtg,0);
        }
        m_bModifyPrj=false;
    }
    if(m_bModifyTbm)
    {
        strncpy(mtg->tbm.name,TBM_index->GetValue().mb_str(wxConvUTF8),64);
        tail_radius_text->GetValue().ToDouble(&mtg->tbm.D[4]);
        jointDist1->GetValue().ToDouble(&mtg->tbm.L[1]);
        jack_radius_text->GetValue().ToDouble(&mtg->tbm.D[2]);

        if(midb_checkbox->GetValue()==true)
        {
            mtg->tbm.type = 1;
            jointDist2->GetValue().ToDouble(&mtg->tbm.L[2]);
            backjack_radius_text->GetValue().ToDouble(&mtg->tbm.D[3]);
            //mtg->tbm.fjd = 0.0;
            //mtg->tbm.fjr = 0.0;
            if(mid_data_checkbox->GetValue()==true)
            {
                mtg->tbm.mode=1;
                mid_value_text1->GetValue().ToDouble(&mtg->tbm.d[2]);
                mid_value_text2->GetValue().ToDouble(&mtg->tbm.d[3]);
                mid_value_text3->GetValue().ToDouble(&mtg->tbm.d[0]);
                mid_value_text4->GetValue().ToDouble(&mtg->tbm.d[1]);
                mtg->tbm.d[2]=mtg->tbm.d[2]/1000.0;
                mtg->tbm.d[3]=mtg->tbm.d[3]/1000.0;
                mtg->tbm.d[0]=mtg->tbm.d[0]/1000.0;
                mtg->tbm.d[1]=mtg->tbm.d[1]/1000.0;
            }
            else
            {
                mtg->tbm.mode=0;
            }
        }
        else if(midf_checkbox->GetValue()==true)
        {
            mtg->tbm.type = 2;
            jointDist2->GetValue().ToDouble(&mtg->tbm.L[2]);
            backjack_radius_text->GetValue().ToDouble(&mtg->tbm.D[3]);
            //mtg->tbm.hjd = 0.0;
            //mtg->tbm.hjr = 0.0;
            if(mid_data_checkbox->GetValue()==true)
            {
                mtg->tbm.mode=1;
                mid_value_text1->GetValue().ToDouble(&mtg->tbm.d[2]);
                mid_value_text2->GetValue().ToDouble(&mtg->tbm.d[3]);
                mid_value_text3->GetValue().ToDouble(&mtg->tbm.d[0]);
                mid_value_text4->GetValue().ToDouble(&mtg->tbm.d[1]);
                mtg->tbm.d[2]=mtg->tbm.d[2]/1000.0;
                mtg->tbm.d[3]=mtg->tbm.d[3]/1000.0;
                mtg->tbm.d[0]=mtg->tbm.d[0]/1000.0;
                mtg->tbm.d[1]=mtg->tbm.d[1]/1000.0;
            }
            else
            {
                mtg->tbm.mode=0;
            }
        }
        else
        {
            mtg->tbm.type = 0;
            //mtg->tbm.hjd = 0.0;
            //mtg->tbm.hjr = 0.0;
            //mtg->tbm.fjd = 0.0;
            //mtg->tbm.fjr = 0.0;
        }
        mtg_store_tbmset(mtg);
        if(mtg->client_type==1 && mtg->control_mode==1)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_tbm(mtg,0);
        }
        else if(mtg->client_type==2 && mtg->control_mode==2)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_tbm(mtg,0);
        }

        if(mtg->tbm.mode==1)
        {
            if(mtg->tbm.type==1)
            {
                mtg_cal_tail(mtg);
            }
            else
            {
                mtg_cal_head(mtg);
            }
        }

        m_bModifyTbm=false;
    }
    if(m_bModifyTar)
    {
        target_prism->GetValue().ToDouble(&mtg->tarset.prc);
        mtg_store_tars(mtg);
        if(mtg->client_type==1 && mtg->control_mode==1)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_tars(mtg,0);
            //client_camset(mtg,0);
        }
        else if(mtg->client_type==2 && mtg->control_mode==2)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_tars(mtg,0);
            //client_camset(mtg,0);
        }
        m_bModifyTar=false;
    }
    if(m_bModifyTps)
    {
        if(gus_laser_checkbox->GetValue()==true)
        {
            mtg->tps.lasertype=0;
            mtg->tps.laserheight=52.2;
        }
        else if(ref_laser_checkbox->GetValue()==true)
        {
            mtg->tps.lasertype=1;
            mtg->tps.laserheight=0.0;
        }
        else
        {
            mtg->tps.lasertype=2;
            tps_laserh->GetValue().ToDouble(&mtg->tps.laserheight);
        }
        tps_laserd->GetValue().ToDouble(&mtg->tps.laserdist);
        tps_laserx->GetValue().ToDouble(&mtg->tps.laserx);
        tps_lasery->GetValue().ToDouble(&mtg->tps.lasery);
        //wxMessageBox(wxString::Format(_("%d"),mtg->tps.lasertype));
        mtg_store_tps(mtg);
        if(mtg->client_type==1 && mtg->control_mode==1)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_tps(mtg,0);
        }
        else if(mtg->client_type==2 && mtg->control_mode==2)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_tps(mtg,0);
        }
        //mtg_send_tps(mtg,0);
        m_bModifyTps=false;
    }
    if(m_bModifySeg)
    {
        seg_len->GetValue().ToDouble(&mtg->segset.L);
        seg_r->GetValue().ToDouble(&mtg->segset.D);
        segThick->GetValue().ToDouble(&mtg->segset.Dn);
        //segScrow->GetValue().ToDouble(&mtg->segset.Ks);
        std_gap_text->GetValue().ToDouble(&mtg->segset.G0);
        min_gap_text->GetValue().ToDouble(&mtg->segset.G1);
        Wedge_Text->GetValue().ToDouble(&mtg->segset.l2s);

        if(seg_method1_checkbox->GetValue()==true)
        {
            mtg->segset.type = 0;
            mtg->segset.f2b = 0;
        }
        else
        {
            mtg->segset.type = 1;
            if(seg_wedge1_checkbox->GetValue()==true)
            {
                mtg->segset.f2b = 0;
            }
            else
            {
                mtg->segset.f2b = 1;
            }
        }
        //gapangle_text->GetValue().ToLong(&mtg->segset.s2s);
        mtg_store_segset(mtg);
        if(mtg->client_type==1 && mtg->control_mode==1)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_segset(mtg,0);
        }
        else if(mtg->client_type==2 && mtg->control_mode==2)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_segset(mtg,0);
        }
        //mtg_available_kpos(mtg);
        m_bModifySeg=false;
    }
    if(m_bModifyOrigin)
    {
        double dms;
        headx_text->GetValue().ToDouble(&mtg->m0.head[0]);
        heady_text->GetValue().ToDouble(&mtg->m0.head[1]);
        headz_text->GetValue().ToDouble(&mtg->m0.head[2]);
        tailx_text->GetValue().ToDouble(&mtg->m0.tail[0]);
        taily_text->GetValue().ToDouble(&mtg->m0.tail[1]);
        tailz_text->GetValue().ToDouble(&mtg->m0.tail[2]);
        tbmroll_text->GetValue().ToDouble(&dms);
        mtg->m0.roll = dms2rad(dms);
        //tbmroll_text->GetValue().ToDouble(&mtg->m0.roll);
        midx_text->GetValue().ToDouble(&mtg->m0.mid[0]);
        midy_text->GetValue().ToDouble(&mtg->m0.mid[1]);
        midz_text->GetValue().ToDouble(&mtg->m0.mid[2]);
        up_mid_text->GetValue().ToDouble(&mtg->m0.midj[0]);
        down_mid_text->GetValue().ToDouble(&mtg->m0.midj[1]);
        left_mid_text->GetValue().ToDouble(&mtg->m0.midj[2]);
        right_mid_text->GetValue().ToDouble(&mtg->m0.midj[3]);
        mtg->m0.midj[0]=mtg->m0.midj[0]/1000.0;
        mtg->m0.midj[1]=mtg->m0.midj[1]/1000.0;
        mtg->m0.midj[2]=mtg->m0.midj[2]/1000.0;
        mtg->m0.midj[3]=mtg->m0.midj[3]/1000.0;
        //fprintf(fp,"1:%.12f\n",mtg->m0.roll);
        tarx_text->GetValue().ToDouble(&mtg->m0.prism[0]);
        tary_text->GetValue().ToDouble(&mtg->m0.prism[1]);
        tarz_text->GetValue().ToDouble(&mtg->m0.prism[2]);
        tarazi_text->GetValue().ToDouble(&dms);
        mtg->azi[0]= dms2rad(dms);
        tarpitch_text->GetValue().ToDouble(&dms);
        mtg->azi[2]= dms2rad(dms);
        tarroll_text->GetValue().ToDouble(&dms);
        mtg->azi[1]= dms2rad(dms);
        mtg->m0.cam[0]=mtg->m.cam[0];
        mtg->m0.cam[1]=mtg->m.cam[1];
        mtg->m0.cam[2]=mtg->m.cam[2];
        mtg->m0.cam[3]=mtg->m.cam[3];
        mtg->m0.inc[0]=mtg->m.inc[0];
        mtg->m0.inc[1]=mtg->m.inc[1];
        mtg->m0.angle[0]=mtg->m.angle[0];
        mtg->m0.angle[1]=mtg->m.angle[1];
        time_t t;
        time(&t);
        mtg->m0.t1=mtg->m0.t2=mtg->m0.t3=t;
        //wxMessageBox(wxString::Format(_("origin")));
        //mtg->m0 = mtg->m;
        //mtg_cal_origin(mtg);
//        fprintf(fp,"2:%.12f\n",mtg->m0.roll);
        mtg_store_origin(mtg);
        if(mtg->client_type==1 && mtg->control_mode==1)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_origin(mtg,0);
        }
        else if(mtg->client_type==2 && mtg->control_mode==2)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_origin(mtg,0);
        }
        //mtg_send_origin(mtg,0);
//        fprintf(fp,"3:%.12f\n",mtg->m0.roll);
        m_bModifyOrigin=false;
    }
    if(m_bModifyData)
    {
        //strncpy(mtg->dtset.dbpath,db_backuppath_text->GetValue().mb_str(wxConvUTF8),16);
        //strncpy(mtg->dtset.dtpath,report_path_text->GetValue().mb_str(wxConvUTF8),16);
        wxString ipstr;
        ipstr = client_ip_text1->GetValue()+_(".")+client_ip_text2->GetValue()+_(".")+client_ip_text3->GetValue()+_(".")+client_ip_text4->GetValue();
        strncpy(mtg->comset[4].ip,ipstr.mb_str(wxConvUTF8),16);
        //mtg->dtset.writetbm=readdatatotbm->IsChecked();
        //mtg->dtset.readtbm=writedatatotbm->IsChecked();
        //mtg_store_dataset(mtg);
        //wxMessageBox(_("ok"));
        mtg_store_comset(mtg);
        //mtg_send_comset(mtg);
        m_bModifyData=false;

    }
    if(m_bModifyMea)
    {
        long tempval;
        measTime1->GetValue().ToLong(&tempval);
        mtg->measet.cycle=tempval;
        measTime2->GetValue().ToLong(&tempval);
        mtg->measet.backcycle=tempval;
        horiDiff->GetValue().ToLong(&tempval);
        mtg->measet.alw_dev=tempval;
        verDiff->GetValue().ToLong(&tempval);
        mtg->measet.alw_jdev=tempval;
        angleDiff->GetValue().ToLong(&tempval);
        mtg->measet.alw_bdev=tempval;
        diffChange->GetValue().ToLong(&tempval);
        mtg->measet.alw_timing=tempval;
        backDiff->GetValue().ToLong(&tempval);
        mtg->measet.alw_bdev=tempval;
        corr_diff_text->GetValue().ToLong(&tempval);
        mtg->measet.alwcorr=tempval;
        corr_dist_text->GetValue().ToDouble(&mtg->measet.fit_len);
        tolTime->GetValue().ToLong(&tempval);
        mtg->measet.alwtime=tempval;
        mtg_store_measet(mtg);
        if(mtg->client_type==1 && mtg->control_mode==1)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_measet(mtg,0);
        }
        else if(mtg->client_type==2 && mtg->control_mode==2)
        {
            if(mtg->iclient==1 && mtg->peeking==0) client_measet(mtg,0);
        }
        m_bModifyMea=false;
    }
    /*if(m_bModifyAdmin)
    {
        if(new_manager_password->GetValue().Cmp(manager_password_confirm->GetValue())==0)
        {
            strncpy(mtg->admin,new_manager_password->GetValue().mb_str(wxConvUTF8),64);
        }
        else
        {
            wxMessageBox(_("新密码与密码确认不一致，请检查！"),_("用户权限"),wxOK);
            wxMouseEvent e=wxEVT_LEFT_UP;
            OnBtnUserClick(e);
        }
        m_bModifyAdmin=false;
    }
    if(m_bModifyDriver)
    {
        if(new_operator_password->GetValue().Cmp(operator_password_confirm->GetValue())==0)
        {
            strncpy(mtg->admin,new_operator_password->GetValue().mb_str(wxConvUTF8),64);
        }
        else
        {
            wxMessageBox(_("新密码与密码确认不一致，请检查！"),_("用户权限"),wxOK);
            wxMouseEvent e=wxEVT_LEFT_UP;
            OnBtnUserClick(e);
        }
        mtg_store_safety(mtg);
        m_bModifyDriver=false;
    }*/
    if(m_bModifyLang)
    {


        m_bModifyLang=false;
    }
    btnApply->Enable(false);
//    fclose(fp);
}

void MySetupDialog::OnImportTarClick(wxCommandEvent& event)
{
    wxFileDialog dlg(this,_("请选择要导入的激光靶文件"),wxEmptyString,wxEmptyString,_("激光靶文件(*.tars)|*.tars"),wxFD_OPEN);
    if(dlg.ShowModal()==wxID_OK)
    {
        wxString str=dlg.GetPath();
        char buf[1024];
        strcpy(buf,str.mb_str(wxConvLocal));
        FILE* fp=fopen(buf,"rb");
        if(fp)
        {

            point2d_t pts1[9],pts2[9];
            fread(mtg->camset[0].name,64,1,fp);
            fread(&mtg->camset[0].w,sizeof(int),1,fp);
            fread(&mtg->camset[0].h,sizeof(int),1,fp);
            fread(&mtg->tarset.length,sizeof(double),1,fp);
            fread(&mtg->tarset.prc,sizeof(double),1,fp);
            fread(&mtg->tarset.inc,sizeof(int),1,fp);
            fread(&mtg->tarset.model,sizeof(int),1,fp);

            //wxMessageBox(wxString::Format(_("%d"),mtg->tarset.frontScreenType));
            for(int i=0;i<3;i++)
            {
                fread(&mtg->tarset.prism[i],sizeof(double),1,fp);
            }
            int ncal=0;
            for(int i=0;i<9;i++)
            {
                fread(&pts1[i].x,sizeof(double),1,fp);
                fread(&pts1[i].y,sizeof(double),1,fp);
                pts1[i].y=mtg->camset[0].h-pts1[i].y;
                fread(&pts2[i].x,sizeof(double),1,fp);
                fread(&pts2[i].y,sizeof(double),1,fp);
                if(pts1[i].x>1.0e-6 && pts1[i].y>1.0e-6)
                {
                    ncal++;
                }

                /*else
                {
                    break;
                }*/
            }
            affine_t aff;
            affine_init_points(&aff,ncal,pts1,pts2);
            mtg->camset[0].affine[0]=aff.a1;
            mtg->camset[0].affine[1]=aff.a2;
            mtg->camset[0].affine[2]=aff.a3;
            mtg->camset[0].affine[3]=aff.b1;
            mtg->camset[0].affine[4]=aff.b2;
            mtg->camset[0].affine[5]=aff.b3;
            mtg->camset[0].affine[6]=aff.c1;
            mtg->camset[0].affine[7]=aff.c2;
            mtg->camset[0].affine[8]=aff.c3;
            //if(!feof(fp))
            //{
            //    fread(&mtg->tarset.frontScreenType,sizeof(int),1,fp);
            //    wxMessageBox(wxString::Format(_("%d"),mtg->tarset.frontScreenType));
            //}
            //fread(&mtg->tarset.frontScreenType,sizeof(int),1,fp);
            //double range[4]={0};
            fread(&mtg->camset[0].left,sizeof(double),1,fp);
            fread(&mtg->camset[0].up,sizeof(double),1,fp);
            fread(&mtg->camset[0].right,sizeof(double),1,fp);
            fread(&mtg->camset[0].down,sizeof(double),1,fp);

            fclose(fp);
            mtg_store_camset(mtg);
            //mtg_send_camset(mtg,0);
            mtg_store_tars(mtg);

            if(mtg->client_type==1 && mtg->control_mode==1)
            {
                if(mtg->iclient==1 && mtg->peeking==0) client_tars(mtg,0);
                if(mtg->iclient==1 && mtg->peeking==0) client_camset(mtg,0);
            }
            else if(mtg->client_type==2 && mtg->control_mode==2)
            {
                if(mtg->iclient==1 && mtg->peeking==0) client_tars(mtg,0);
                if(mtg->iclient==1 && mtg->peeking==0) client_camset(mtg,0);
            }
            //mtg_send_tars(mtg,0);
            //mtg_cal_origin(mtg);

            for(int i=0;i<mtg->camsvr.count;i++)
            {
                mtg->camsvr.cams[i].type=mtg->tarset.model;
                //wxMessageBox(wxString::Format(_("%d"),mtg->camsvr.cams[i].type));
            }



            //mtg_import_db(mtg);
            //LoadDatabase();
            wxMessageBox(_("导入成功！"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
            LoadDatabase();

        }
        fclose(fp);
    }
}

void MySetupDialog::OnAddAreaClick(wxCommandEvent& event)
{
    KeyAreaDlg dlg(this);
    double val;
    int Er=0;
    dlg.Center();
    dlg.StaticText5->SetLabel(_("添加关键区域"));
    if(dlg.ShowModal() == wxID_OK)
    {
        //wxMessageBox(_("ok"));
        MTG_KEY a={0};
        strncpy(a.name,dlg.name->GetValue().mb_str(wxConvUTF8),64);
        if(dlg.mile1->GetValue().ToDouble(&val))
        {
            a.mile1 = val;
        }
        else
        {
            wxMessageBox(_("输入非法字符，请检查！"),_("关键区域设置"),wxOK);
            Er = 1;
        }
        if(dlg.mile2->GetValue().ToDouble(&val))
        {
            a.mile2 = val;
        }
        else
        {
            wxMessageBox(_("输入非法字符，请检查！"),_("关键区域设置"),wxOK);
            Er = 1;
        }
        if(Er == 0)
        {
            mtg_add_area(mtg,&a);
            //mtg_send_add_area(mtg,&a);
            UpdateArea();
            listArea->Select(mtg->nks-1);
        }
        else
        {
            wxCommandEvent e;
            OnAddAreaClick(e);
        }
        //GraphBlock->Refresh();
    }
    else
    {
        return;
    }
}

void MySetupDialog::OnEditAreaClick(wxCommandEvent& event)
{
    KeyAreaDlg dlg(this);
    double val;
    dlg.Center();
    dlg.StaticText5->SetLabel(_("编辑关键区域"));
    int n = listArea->GetFirstSelected();
    int Num = listArea->GetItemCount();
    if(n<0 || n>=Num) return;
    dlg.name->SetValue(wxString(mtg->keys[n].name,wxConvUTF8));
    dlg.mile1->SetValue(wxString::Format(_("%.2f"),mtg->keys[n].mile1));
    dlg.mile2->SetValue(wxString::Format(_("%.2f"),mtg->keys[n].mile2));
    if(dlg.ShowModal() == wxID_OK)
    {
        MTG_KEY a={0};
        strncpy(a.name,dlg.name->GetValue().mb_str(wxConvUTF8),64);
        val = mtg->keys[n].mile1;
        if(!dlg.mile1->GetValue().ToDouble(&a.mile1))
        {
            a.mile1 = val;
            wxMessageBox(_("输入非法字符，请检查！"),_("关键区域设置"),wxOK);
            wxCommandEvent e;
            OnEditAreaClick(e);
        }
        val = mtg->keys[n].mile2;
        if(!dlg.mile2->GetValue().ToDouble(&a.mile2))
        {
            a.mile2 = val;
            wxMessageBox(_("输入非法字符，请检查！"),_("关键区域设置"),wxOK);
            wxCommandEvent e;
            OnEditAreaClick(e);
        }

        mtg_edit_area(mtg,n,&a);
        //mtg_send_modify_area(mtg,n,&a);
        UpdateArea();

        listArea->Select(n);

        //listArea->Refresh();
    }
    else
    {
        return;
    }
    //wxMessageBox(_("ok"));
}

void MySetupDialog::OnDeleAreaClick(wxCommandEvent& event)
{
    int n = listArea->GetFirstSelected();
    int Num = listArea->GetItemCount();
    if(n<0 || n>=Num) return;
    wxMessageDialog dlg(this,_("删除操作将不可恢复\n确定要进行删除吗？"),_("关键区域设置"),wxYES_NO|wxICON_INFORMATION);
    if(dlg.ShowModal() == wxID_YES)
    {
        mtg_remove_area(mtg,n);
        //mtg_send_remove_area(mtg,n);
        UpdateArea();
        if(n+1<Num)
        {
            listArea->Select(n);
        }
        else if(n-1>=0)
        {
            listArea->Select(n-1);
        }
        else
        {
            btnEditArea->Enable(false);
            btnDelArea->Enable(false);
        }
        //GraphBlock->Refresh();
    }
    else
    {
        return;
    }
}

void MySetupDialog::OnListAreaItemActivated(wxListEvent& event)
{
    wxCommandEvent e;
    OnEditAreaClick(e);
}

void MySetupDialog::OnListAreaItemSelect(wxListEvent& event)
{
    areaSelect=listArea->GetFirstSelected();
    btnEditArea->Enable(true);
    btnDelArea->Enable(true);
}

void MySetupDialog::OnListAreaItemDeselect(wxListEvent& event)
{
    areaSelect =-1;
    btnEditArea->Enable(false);
    btnDelArea->Enable(false);
}


void MySetupDialog::OnAddBlockClick(wxCommandEvent& event)
{
    BlockDlg dlg(this);
    dlg.Center();
    dlg.StaticText5->SetLabel(_("添加管块"));
    if(dlg.ShowModal() == wxID_OK)
    {
        MTG_BLOCK b={0};
        strncpy(b.name,dlg.blockName->GetValue().mb_str(wxConvUTF8),64);
        dlg.blockAngle->GetValue().ToDouble(&b.angle);
        b.angle=b.angle*PI/180.0;
        mtg_add_block(mtg,&b);
        UpdateBlock();
        listBlock->Select(mtg->nblk-1);
        GraphBlock->Refresh();
    }
    else
    {
        return;
    }
}

void MySetupDialog::OnEditBlockClick(wxCommandEvent& event)
{
    BlockDlg dlg(this);
    dlg.Center();
    dlg.StaticText5->SetLabel(_("编辑管块"));
    int n = listBlock->GetFirstSelected();
    int Num = listBlock->GetItemCount();
    if(n<0 || n>=Num) return;

    dlg.blockName->SetValue(wxString(mtg->blocks[n].name,wxConvUTF8));
    dlg.blockAngle->SetValue(wxString::Format(_("%.2f"),mtg->blocks[n].angle*180.0/PI));
    if(dlg.ShowModal() == wxID_OK)
    {
        MTG_BLOCK b={0};
        strncpy(b.name,dlg.blockName->GetValue().mb_str(wxConvUTF8),64);
        dlg.blockAngle->GetValue().ToDouble(&b.angle);
        b.angle=b.angle*PI/180.0;
        mtg_modify_block(mtg,n,&b);
        //mtg_send_modify_block(mtg,n,&b);
        UpdateBlock();
        listBlock->Select(n);
        GraphBlock->Refresh();
    }
    else
    {
        return;
    }
}

void MySetupDialog::OnDeleBlockClick(wxCommandEvent& event)
{
    int n = listBlock->GetFirstSelected();
    int Num = listBlock->GetItemCount();
    if(n<0 || n>=Num) return;
    wxMessageDialog dlg(this,_("删除操作将不可恢复\n确定要进行删除吗？"),_("管块设置"),wxYES_NO|wxICON_INFORMATION);
    if(dlg.ShowModal() == wxID_YES)
    {
        mtg_remove_block(mtg,n);
        //mtg_send_remove_block(mtg,n);
        UpdateBlock();
        if(n+1<Num)
        {
            listBlock->Select(n);
        }
        else if(n-1>=0)
        {
            listBlock->Select(n-1);
        }
        else
        {
            btnEditBlock->Enable(false);
            btnDelBlock->Enable(false);
        }
        GraphBlock->Refresh();
    }
    else
    {
        return;
    }
}

void MySetupDialog::UpdateArea()
{
    //wxMessageBox(wxString::Format(_("%d"),mtg->nblk));
    listArea->DeleteAllItems();
    //wxMessageBox(wxString::Format(_("%d"),mtg->nblk));
    for(int i=0; i<mtg->nks; i++)
    {
        listArea->InsertItem(i,wxString::Format(_("%d"),i+1));
        listArea->SetItem(i,1,wxString(mtg->keys[i].name,wxConvUTF8));
        listArea->SetItem(i,2,wxString::Format(_("%.2f"),mtg->keys[i].mile1));
        listArea->SetItem(i,3,wxString::Format(_("%.2f"),mtg->keys[i].mile2));
    }
}

void MySetupDialog::UpdateUser()
{
    //wxMessageBox(wxString::Format(_("%d"),mtg->nblk));
    listUser->DeleteAllItems();
    //wxMessageBox(wxString::Format(_("%d"),mtg->nblk));
    for(int i=0; i<mtg->nuser; i++)
    {
        listUser->InsertItem(i,wxString::Format(_("%d"),i+1));
        if(mtg->user[i].level==0)
        {
            listUser->SetItem(i,1,_("管理权限"));
        }
        if(mtg->user[i].level==1)
        {
            listUser->SetItem(i,1,_("操作权限"));
        }
        listUser->SetItem(i,2,wxString(mtg->user[i].name,wxConvUTF8));
        listUser->SetItem(i,3,_("********"));
    }
}

void MySetupDialog::UpdateBlock()
{
    //wxMessageBox(wxString::Format(_("%d"),mtg->nblk));
    //if(mtg->nblk<=0) return ;
    listBlock->DeleteAllItems();
    //wxMessageBox(wxString::Format(_("%d"),mtg->nblk));
    for(int i=0; i<mtg->nblk; i++)
    {
        listBlock->InsertItem(i,wxString::Format(_("%d"),i+1));
        listBlock->SetItem(i,1,wxString(mtg->blocks[i].name,wxConvUTF8));
        listBlock->SetItem(i,2,wxString::Format(_("%.2f"),mtg->blocks[i].angle*180/PI));
    }
}


void MySetupDialog::OnListBlockItemActivated(wxListEvent& event)
{
    if(mtg->onLine==0)
    {
        wxCommandEvent e;
        OnEditBlockClick(e);
    }
}

void MySetupDialog::OnListBlockItemSelect(wxListEvent& event)
{
    blockSelect=listBlock->GetFirstSelected();
    if(mtg->onLine == 0)
    {
        btnEditBlock->Enable(true);
        btnDelBlock->Enable(true);
    }
    GraphBlock->Refresh();
}

void MySetupDialog::OnListBlockItemDeselect(wxListEvent& event)
{
    blockSelect=-1;
    btnDelBlock->Enable(false);
    btnEditBlock->Enable(false);
    GraphBlock->Refresh();
}

void MySetupDialog::OnListUserItemActivated(wxListEvent& event)
{
    int n = listUser->GetFirstSelected();
    if(mtg->onLine==0 || mtg->onLine==n)
    {
        wxCommandEvent e;
        OnBtnEditUserClick(e);
    }
}

void MySetupDialog::OnListUserItemSelect(wxListEvent& event)
{
    int n = listUser->GetFirstSelected();
    if(mtg->onLine==0 || mtg->onLine==n)
    {
        userSelect = n;
        btnEditUser->Enable(true);
        if(mtg->onLine==0 && n>0)
        {
            btnDelUser->Enable(true);
        }
    }
    //GraphBlock->Refresh();
}

void MySetupDialog::OnListUserItemDeselect(wxListEvent& event)
{
    userSelect=-1;
    btnDelUser->Enable(false);
    btnEditUser->Enable(false);
    //GraphBlock->Refresh();
}

void MySetupDialog::Sortip()
{
    wxString str1,str2;
    int len;
    str1 = wxString(mtg->comset[4].ip,wxConvUTF8);
    len = str1.length();
    int j = 0;
    for(int i=0;i<len;i++)
    {
        str2 = str1.Left(1);
        str1 = str1.Remove(0,1);
        //wxMessageBox(str1);
        //wxMessageBox(str2);
        if(str2.Cmp(_("."))==0)
        {
            j++;
            str2 = _("");
        }
        if(j==0)
        {
            clientip1 = clientip1+str2;
        }
        if(j==1)
        {
            clientip2 = clientip2+str2;
        }
        if(j==2)
        {
            clientip3 = clientip3+str2;
        }
        if(j==3)
        {
            clientip4 = clientip4+str2;
        }
    }

    str1 = wxString(mtg->comset[5].ip,wxConvUTF8);
    len = str1.length();
    j = 0;
    for(int i=0;i<len;i++)
    {
        str2 = str1.Left(1);
        str1 = str1.Remove(0,1);
        //wxMessageBox(str1);
        //wxMessageBox(str2);
        if(str2.Cmp(_("."))==0)
        {
            j++;
            str2 = _("");
        }
        if(j==0)
        {
            tbmip1 = tbmip1+str2;
        }
        if(j==1)
        {
            tbmip2 = tbmip2+str2;
        }
        if(j==2)
        {
            tbmip3 = tbmip3+str2;
        }
        if(j==3)
        {
            tbmip4 = tbmip4+str2;
        }
    }
}

void MySetupDialog::LoadDatabase()
{
    wxString str;
    int h,m;
    ///工程 信息
    prj_name->SetValue(wxString(mtg->prj.name,wxConvUTF8));
    prj_mile1->SetValue(wxString::Format(_("%.4f"),mtg->prj.mile1));
    prj_mile2->SetValue(wxString::Format(_("%.4f"),mtg->prj.mile2));
    if(mtg->prj.a2z == 0)
    {
        forward_checkbox->SetValue(true);
        reverse_checkbox->SetValue(false);
    }
    else
    {
        forward_checkbox->SetValue(false);
        reverse_checkbox->SetValue(true);
    }
    //direct_choice->SetSelection(mtg->prj.direction);
    //h = mtg->prj.dayOperate/3600;
    //m = (mtg->prj.dayOperate-h*3600)/60;
    //wxMessageBox(wxString::Format(_("%d"),h));
    //wxMessageBox(wxString::Format(_("%d"),m));
    //str = wxString::Format(_("%d"),h);
    day_hour->SetValue(wxString::Format(_("%d"),mtg->prj.t1[0]));
    //str = wxString::Format(_("%d"),m);
    day_min->SetValue(wxString::Format(_("%d"),mtg->prj.t1[0]));
    //h = mtg->prj.nightOperate/3600;
    //m = (mtg->prj.nightOperate-h*3600)/60;
    //str = wxString::Format(_("%d"),h);
    night_hour->SetValue(wxString::Format(_("%d"),mtg->prj.t1[0]));
    //str = wxString::Format(_("%d"),m);
    night_min->SetValue(wxString::Format(_("%d"),mtg->prj.t1[0]));


    tip_text->SetValue(wxString::Format(_("%.2f"),mtg->prj.tip));

    if(mtg->user[mtg->onLine].level == 1)
    {
        prj_mile1->SetEditable(false);
        prj_mile2->SetEditable(false);
        forward_checkbox->Enable(false);
        reverse_checkbox->Enable(false);
    }
    ///盾构设置
    TBM_index->SetValue(wxString(mtg->tbm.name,wxConvUTF8));
    tail_radius_text->SetValue(wxString::Format(_("%.4f"),mtg->tbm.D[4]));
    jointDist1->SetValue(wxString::Format(_("%.4f"),mtg->tbm.L[1]));
    jack_radius_text->SetValue(wxString::Format(_("%.4f"),mtg->tbm.L[1]));
    mid_value_text1->SetValue(wxString::Format(_("%.1f"),mtg->tbm.d[2]*1000.0));
    mid_value_text2->SetValue(wxString::Format(_("%.1f"),mtg->tbm.d[3]*1000.0));
    mid_value_text3->SetValue(wxString::Format(_("%.1f"),mtg->tbm.d[0]*1000.0));
    mid_value_text4->SetValue(wxString::Format(_("%.1f"),mtg->tbm.d[1]*1000.0));
    if(mtg->tbm.type==0)
    {
        midb_checkbox->SetValue(false);
        midf_checkbox->SetValue(false);
        jointDist2->Enable(false);
        jointDist2->SetValue(wxString::Format(_("%.4f"),0.0));
        backjack_radius_text->Enable(false);
        backjack_radius_text->SetValue(wxString::Format(_("%.4f"),0.0));
        mid_data_checkbox->SetValue(false);
        mid_data_checkbox->Enable(false);
        mid_value_text1->Enable(false);
        mid_value_text2->Enable(false);
        mid_value_text3->Enable(false);
        mid_value_text4->Enable(false);
    }
    else if(mtg->tbm.type==1)
    {
        midb_checkbox->SetValue(true);
        midf_checkbox->SetValue(false);
        jointDist2->Enable(true);
        jointDist2->SetValue(wxString::Format(_("%.4f"),mtg->tbm.L[2]));
        //wxMessageBox(wxString::Format(_("%.4f"),mtg->tbm.hjd));
        backjack_radius_text->Enable(true);
        backjack_radius_text->SetValue(wxString::Format(_("%.4f"),mtg->tbm.D[3]));
        mid_data_checkbox->Enable(true);
        if(mtg->tbm.mode==0)
        {
            mid_data_checkbox->SetValue(false);
            mid_value_text1->Enable(false);
            mid_value_text2->Enable(false);
            mid_value_text3->Enable(false);
            mid_value_text4->Enable(false);
        }
        else
        {
            mid_data_checkbox->SetValue(true);
            mid_value_text1->Enable(true);
            mid_value_text2->Enable(true);
            mid_value_text3->Enable(true);
            mid_value_text4->Enable(true);
        }
    }
    else
    {
        midb_checkbox->SetValue(false);
        midf_checkbox->SetValue(true);
        jointDist2->Enable(true);
        jointDist2->SetValue(wxString::Format(_("%.4f"),mtg->tbm.L[2]));
        backjack_radius_text->Enable(true);
        backjack_radius_text->SetValue(wxString::Format(_("%.4f"),mtg->tbm.D[3]));

        mid_data_checkbox->Enable(true);
        if(mtg->tbm.mode==0)
        {
            mid_data_checkbox->SetValue(false);
            mid_value_text1->Enable(false);
            mid_value_text2->Enable(false);
            mid_value_text3->Enable(false);
            mid_value_text4->Enable(false);
        }
        else
        {
            mid_data_checkbox->SetValue(true);
            mid_value_text1->Enable(true);
            mid_value_text2->Enable(true);
            mid_value_text3->Enable(true);
            mid_value_text4->Enable(true);
        }
    }

    if(mtg->user[mtg->onLine].level == 1)
    {
        tail_radius_text->SetEditable(false);
        jointDist1->SetEditable(false);
        jack_radius_text->SetEditable(false);
        midb_checkbox->Enable(false);
        midf_checkbox->Enable(false);
    }

    ///激光靶
    tar_file->SetValue(wxString(mtg->camset[0].name,wxConvLocal));
    target_prism->SetValue(wxString::Format(_("%.2f"),mtg->tarset.prc));
    if(mtg->user[mtg->onLine].level == 1)
    {
        btnImportPara->Enable(false);
        target_prism->SetEditable(false);
    }
    //textCompany->SetValue(wxString(mtg->prj.company,wxConvUTF8));
    //textTime->SetValue(wxString(mtg->prj.date_time,wxConvUTF8));
    //textAuthor->SetValue(wxString(mtg->prj.author,wxConvUTF8));
    //textRemarks->SetValue(wxString(mtg->prj.remarks,wxConvUTF8));
    ///全站仪设置
    //laserChoice->SetSelection(mtg->tps.lasertype);
    if(mtg->tps.lasertype==0)
    {
        gus_laser_checkbox->SetValue(true);
        ref_laser_checkbox->SetValue(false);
        user_laser_checkbox->SetValue(false);
        tps_laserh->SetValue(wxString::Format(_("%.2f"),mtg->tps.laserheight));
        tps_laserh->SetEditable(false);
    }
    else if(mtg->tps.lasertype==1)
    {
        gus_laser_checkbox->SetValue(false);
        ref_laser_checkbox->SetValue(true);
        user_laser_checkbox->SetValue(false);
        tps_laserh->SetValue(wxString::Format(_("%.2f"),mtg->tps.laserheight));
        tps_laserh->SetEditable(false);
    }
    else
    {
        gus_laser_checkbox->SetValue(false);
        ref_laser_checkbox->SetValue(false);
        user_laser_checkbox->SetValue(true);
        tps_laserh->SetValue(wxString::Format(_("%.2f"),mtg->tps.laserheight));
        tps_laserh->SetEditable(true);
    }
    tps_laserd->SetValue(wxString::Format(_("%.2f"),mtg->tps.laserdist));
    tps_laserx->SetValue(wxString::Format(_("%.2f"),mtg->tps.laserx));
    tps_lasery->SetValue(wxString::Format(_("%.2f"),mtg->tps.lasery));
    if(mtg->user[mtg->onLine].level == 1)
    {
        tps_laserh->SetEditable(false);
        tps_laserd->SetEditable(false);
        tps_laserx->SetEditable(false);
        tps_lasery->SetEditable(false);
        gus_laser_checkbox->Enable(false);
        ref_laser_checkbox->Enable(false);
        user_laser_checkbox->Enable(false);
    }
    ///管环设置
    seg_len->SetValue(wxString::Format(_("%.2f"),mtg->segset.L));
    seg_r->SetValue(wxString::Format(_("%.2f"),mtg->segset.D));
    segThick->SetValue(wxString::Format(_("%.2f"),mtg->segset.Dn));
    segScrow->SetValue(wxString::Format(_("%.2f"),mtg->segset.Ks));
    std_gap_text->SetValue(wxString::Format(_("%.2f"),mtg->segset.G0));
    min_gap_text->SetValue(wxString::Format(_("%.2f"),mtg->segset.G1));

    if(mtg->segset.type==0)
    {
        seg_method1_checkbox->SetValue(true);
        seg_method2_checkbox->SetValue(false);
        seg_wedge2_checkbox->Enable(false);
    }
    else
    {
        seg_method1_checkbox->SetValue(false);
        seg_method2_checkbox->SetValue(true);
        seg_wedge2_checkbox->Enable(true);
    }
    if(mtg->segset.f2b==0)
    {
        seg_wedge1_checkbox->SetValue(true);
        seg_wedge2_checkbox->SetValue(false);
    }
    else
    {
        seg_wedge1_checkbox->SetValue(false);
        seg_wedge2_checkbox->SetValue(true);
    }
    Wedge_Text->SetValue(wxString::Format(_("%.2f"),mtg->segset.l2s));
    gapangle_text->SetValue(wxString::Format(_("%.2f"),mtg->segset.s2s));
    if(mtg->user[mtg->onLine].level == 1)
    {
        seg_len->SetEditable(false);
        seg_r->SetEditable(false);
        segThick->SetEditable(false);
        segScrow->SetEditable(false);
        std_gap_text->SetEditable(false);
        min_gap_text->SetEditable(false);
        Wedge_Text->SetEditable(false);
        gapangle_text->SetEditable(false);

        seg_method1_checkbox->Enable(false);
        seg_method2_checkbox->Enable(false);
        seg_wedge1_checkbox->Enable(false);
        seg_wedge2_checkbox->Enable(false);
    }
    ///管块设置
    if(mtg->user[mtg->onLine].level == 1)
    {
        btnAddBlock->Enable(false);
        btnEditBlock->Enable(false);
        btnDelBlock->Enable(false);
    }

    ///零位测量
    headx_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.head[0]));
    heady_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.head[1]));
    headz_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.head[2]));
    tailx_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.tail[0]));
    taily_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.tail[1]));
    tailz_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.tail[2]));
    tbmroll_text->SetValue(wxString::Format(_("%.5f"),rad2dms(mtg->m0.roll)));
    tarx_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.prism[0]));
    tary_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.prism[1]));
    tarz_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.prism[2]));
    tarazi_text->SetValue(wxString::Format(_("%.5f"),rad2dms(mtg->azi[0])));
    tarpitch_text->SetValue(wxString::Format(_("%.5f"),rad2dms(mtg->azi[2])));
    tarroll_text->SetValue(wxString::Format(_("%.5f"),rad2dms(mtg->azi[1])));
    tbm_azi_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.azimuth));
    tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.pitch));

    midx_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[0]));
    midy_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[1]));
    midz_text->SetValue(wxString::Format(_("%.4f"),mtg->m0.mid[2]));
    up_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[0]*1000.0));
    down_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[1]*1000.0));
    left_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[2]*1000.0));
    right_mid_text->SetValue(wxString::Format(_("%.1f"),mtg->m0.midj[3]*1000.0));
    if(mtg->tbm.type==0)
    {
        midx_text->Enable(false);
        midy_text->Enable(false);
        midz_text->Enable(false);
        up_mid_text->Enable(false);
        left_mid_text->Enable(false);
        down_mid_text->Enable(false);
        right_mid_text->Enable(false);
    }
    else
    {
        midx_text->Enable(true);
        midy_text->Enable(true);
        midz_text->Enable(true);
        up_mid_text->Enable(true);
        left_mid_text->Enable(true);
        down_mid_text->Enable(true);
        right_mid_text->Enable(true);
        if(mtg->tbm.type==1)
        {
            CalTail();
        }
        else if(mtg->tbm.type==2)
        {
            CalHead();
        }
    }
    if(mtg->user[mtg->onLine].level == 1)
    {
        headx_text->SetEditable(false);
        heady_text->SetEditable(false);
        headz_text->SetEditable(false);
        tailx_text->SetEditable(false);
        taily_text->SetEditable(false);
        tailz_text->SetEditable(false);
        tbmroll_text->SetEditable(false);
        midx_text->SetEditable(false);
        midy_text->SetEditable(false);
        midz_text->SetEditable(false);
        tarx_text->SetEditable(false);
        tary_text->SetEditable(false);
        tarz_text->SetEditable(false);
        tarazi_text->SetEditable(false);
        tarpitch_text->SetEditable(false);
        tarroll_text->SetEditable(false);
        btnTarMeas->Enable(false);
    }
    ///数据管理
    //db_backuppath_text->SetValue(wxString(mtg->dtset.dbpath,wxConvUTF8));
    //report_path_text->SetValue(wxString(mtg->dtset.dtpath,wxConvUTF8));
    client_ip_text1->SetValue(clientip1);
    client_ip_text2->SetValue(clientip2);
    client_ip_text3->SetValue(clientip3);
    client_ip_text4->SetValue(clientip4);
    if(mtg->user[mtg->onLine].level == 1)
    {
        //db_backuppath_text->SetEditable(false);
        //report_path_text->SetEditable(false);
        client_ip_text1->SetEditable(false);
        client_ip_text2->SetEditable(false);
        client_ip_text3->SetEditable(false);
        client_ip_text4->SetEditable(false);
        //btnDbPath->Enable(false);
        //btnRtPath->Enable(false);
    }
    //writedatatotbm->SetValue(mtg->dtset.writetbm);
    //readdatatotbm->SetValue(mtg->dtset.readtbm);

    ///测量设置
    //mtg->measet.cycle=30;
    measTime1->SetValue(wxString::Format(_("%d"),mtg->measet.cycle));
    measTime2->SetValue(wxString::Format(_("%d"),mtg->measet.backcycle));
    horiDiff->SetValue(wxString::Format(_("%d"),mtg->measet.alw_dev));
    verDiff->SetValue(wxString::Format(_("%d"),mtg->measet.alw_jdev));
    angleDiff->SetValue(wxString::Format(_("%d"),mtg->measet.alw_bdev));
    diffChange->SetValue(wxString::Format(_("%d"),mtg->measet.alw_timing));
    backDiff->SetValue(wxString::Format(_("%d"),mtg->measet.alw_bdev));
    corr_dist_text->SetValue(wxString::Format(_("%.4f"),mtg->measet.fit_len));
    corr_diff_text->SetValue(wxString::Format(_("%d"),mtg->measet.alwcorr));
    tolTime->SetValue(wxString::Format(_("%d"),mtg->measet.alwtime));
    if(mtg->user[mtg->onLine].level == 1)
    {
        backDiff->SetEditable(false);
        corr_dist_text->SetEditable(false);
        corr_diff_text->SetEditable(false);
    }
    //textSegLength->SetValue(wxString::Format(_("%.4f"),mtg->ref_seg.length));
    ///零位数据
    /*textHeadX->SetValue(wxString::Format(_("%.4f"),mtg->m0.head[0]));
    textHeadY->SetValue(wxString::Format(_("%.4f"),mtg->m0.head[1]));
    textHeadZ->SetValue(wxString::Format(_("%.4f"),mtg->m0.head[2]));
    textTailX->SetValue(wxString::Format(_("%.4f"),mtg->m0.tail[0]));
    textTailY->SetValue(wxString::Format(_("%.4f"),mtg->m0.tail[1]));
    textTailZ->SetValue(wxString::Format(_("%.4f"),mtg->m0.tail[2]));
    textRoll->SetValue(wxString::Format(_("%.4f"),mtg->m0.roll));
    textJiaojieH->SetValue(wxString::Format(_("%.4f"),mtg->m0.jiaojieH*180.0/PI));
    textJiaojieV->SetValue(wxString::Format(_("%.4f"),mtg->m0.jiaojieV*180.0/PI));
    textPrismX->SetValue(wxString::Format(_("%.4f"),mtg->m0.prism[0]));
    textPrismY->SetValue(wxString::Format(_("%.4f"),mtg->m0.prism[1]));
    textPrismZ->SetValue(wxString::Format(_("%.4f"),mtg->m0.prism[2]));
    textTargetX1->SetValue(wxString::Format(_("%.4f"),mtg->m0.cam[0]));
    textTargetY1->SetValue(wxString::Format(_("%.4f"),mtg->m0.cam[1]));
    textTargetX2->SetValue(wxString::Format(_("%.4f"),mtg->m0.cam[2]));
    textTargetY2->SetValue(wxString::Format(_("%.4f"),mtg->m0.cam[3]));
    textInclineX->SetValue(wxString::Format(_("%.4f"),mtg->m0.inc[0]));
    textInclineY->SetValue(wxString::Format(_("%.4f"),mtg->m0.inc[1]));
    textAngle1->SetValue(wxString::Format(_("%.4f"),rad2dms(mtg->m0.angle[0])));
    textAngle2->SetValue(wxString::Format(_("%.4f"),rad2dms(mtg->m0.angle[1])));*/

    //PrismPos->SetSelection(mtg->tarset.pos);
    //LaserType->SetSelection(mtg->tarset.lasertype);
    //LaserHeight->SetValue(wxString::Format(_("%.2f"),mtg->tarset.laserheight));
    //LaserDist->SetValue(wxString::Format(_("%.4f"),mtg->tarset.laserdist));
    //LaserX->SetValue(wxString::Format(_("%.2f"),mtg->tarset.laserx));
    //LaserY->SetValue(wxString::Format(_("%.2f"),mtg->tarset.lasery));
    ///管块设置
    if(mtg->user[mtg->onLine].level == 1)
    {
        btnAddUser->Enable(false);
        btnEditUser->Enable(false);
        btnDelUser->Enable(false);
    }
    ///语言
    wxConfig *config = new wxConfig(_("MTG-T"));
    long lang=0;
    config->Read(_("Language"),&lang,0);
    if(lang == 0)
    {
        lang1_checkbox->SetValue(true);
        lang2_checkbox->SetValue(false);
        lang3_checkbox->SetValue(false);
    }
    else if(lang == 1)
    {
        lang1_checkbox->SetValue(false);
        lang2_checkbox->SetValue(true);
        lang3_checkbox->SetValue(false);
    }
    else if(lang == 2)
    {
        lang1_checkbox->SetValue(false);
        lang2_checkbox->SetValue(false);
        lang3_checkbox->SetValue(true);
    }
    //langChoice->SetSelection(lang);
    m_bModifyTbm=m_bModifyTps=m_bModifyTar=m_bModifySeg=m_bModifyOrigin=m_bModifyData=m_bModifyMea=m_bModifyAdmin=m_bModifyDriver=m_bModifyLang=false;
}


void MySetupDialog::OnMenuRestore(wxCommandEvent& event)
{
    wxMessageDialog dlg(this,_("还原操作将覆盖当前数据库中的数据，是否继续？"),_("警告"), wxOK | wxCANCEL);
    if(dlg.ShowModal()==wxID_OK)
    {
        wxFileDialog fileDlg(this,_("选择待还原的工程文件"),wxEmptyString,wxEmptyString,_("工程文件(*.prj)|*.prj"),wxFD_OPEN);
        if(fileDlg.ShowModal()==wxID_OK)
        {
            wxString strFile=fileDlg.GetPath();
            wxString strCmd=_("mysql -u root -p123 db_laser <\"")+strFile+_("\"");
            bool bRet=wxShell(strCmd);
            //wxMessageBox(strCmd);
            //wxProcess *p=new wxProcess;
            //p->Redirect();///屏闭shell窗口信息
            //int code = wxExecute(strCmd, wxEXEC_SYNC,p);
            if(bRet)
            {
                wxMessageBox(_("数据已还原！"),_("提示"));
                mtg_import_db(mtg);
                LoadDatabase();
            }
            else
            {
                wxMessageBox(_("还原失败！"),_("提示"));
            }
        }

    }
    LoadDatabase();
    m_bModifyTbm=m_bModifyTps=m_bModifyTar=m_bModifySeg=m_bModifyOrigin=m_bModifyData=m_bModifyMea=m_bModifyAdmin=m_bModifyDriver=m_bModifyLang=false;
}

void MySetupDialog::OnMenuBackup(wxCommandEvent& event)
{
    wxFileDialog fileDlg(this,_("输入备份文件路径"),wxEmptyString,wxEmptyString,_("工程文件(*.prj)|*.prj"),wxFD_SAVE);
    if(fileDlg.ShowModal()==wxID_OK)
    {
        wxString strFile=fileDlg.GetPath();
        wxString strCmd=_("mysqldump -u root -p123 db_laser >\"")+strFile+_("\"");
        bool bRet=wxShell(strCmd);
        //wxMessageBox(strCmd);
        //wxProcess *p=new wxProcess;
        //p->Redirect();///屏闭shell窗口信息
        //int code = wxExecute(strCmd, wxEXEC_SYNC,p);
        if(bRet)
        {
            wxMessageBox(_("数据已备份！"),_("提示"));
            //LoadDatabase();
        }
        else
        {
            wxMessageBox(_("备份失败！"),_("提示"));
        }
    }
    LoadDatabase();
    m_bModifyTbm=m_bModifyTps=m_bModifyTar=m_bModifySeg=m_bModifyOrigin=m_bModifyData=m_bModifyMea=m_bModifyAdmin=m_bModifyDriver=m_bModifyLang=false;
}

void MySetupDialog::OnMenuClean(wxCommandEvent& event)
{
    wxMessageDialog dlg(this,_("清空操作将清除当前数据库中的数据，是否继续？"),_("警告"), wxOK | wxCANCEL);
    if(dlg.ShowModal()==wxID_OK)
    {
        mtg_init_db(mtg);
        //mtg_init(mtg);
        mtg_import_db(mtg);
        LoadDatabase();
        wxMessageBox(_("数据已清空！"),_("提示"));

        wxStandardPaths stdp;
        wxString path=stdp.GetExecutablePath();
        #ifdef WIN32
        int t=path.Find('\\',true);
        #else
        int t=path.Find('/',true);
        #endif
        path=path.SubString(0,t-1);

        wxString hpath,vpath;
        hpath = path+_("/plugins/h_map.map");
        vpath = path+_("/plugins/v_map.map");

        wxRemoveFile(hpath);
        wxRemoveFile(vpath);
        /*wxStandardPaths*  stdPath=(wxStandardPaths*)&wxStandardPaths::Get();
        wxString path=stdPath->GetExecutablePath();
        #ifdef WIN32
        int ns=path.Find('\\',true);
        #else
        int ns=path.Find('/',true);
        #endif
        wxString strDir=path.Mid(0,ns);

        ///先备份
        //wxString strCmd=_("mysqldump -u root -p123 db_laser >\"")+strDir+_("\backup.sql"");
        //bool bRet=wxShell(strCmd);

         wxString   strCmd=_("mysql -u root -p123 db_laser <\"")+strDir+_("/init.sql\"");
         bool   bRet=wxShell(strCmd);

        //wxMessageBox(strCmd);
        //wxProcess *p=new wxProcess;
        //p->Redirect();///屏闭shell窗口信息
        //int code = wxExecute(strCmd, wxEXEC_SYNC,p);
        //if(code==0)
        if(bRet)
        {
            //wxGetApp().LoadDatabase();
            wxMessageBox(_("数据已清空！"),_("提示"));
            //LoadDatabase();
        }
        else
        {
            wxMessageBox(_("清空失败！"),_("提示"));
        }*/
    }
    //LoadDatabase();
    m_bModifyTbm=m_bModifyTps=m_bModifyTar=m_bModifySeg=m_bModifyOrigin=m_bModifyData=m_bModifyMea=m_bModifyAdmin=m_bModifyDriver=m_bModifyLang=false;
}


void MySetupDialog::OnBtnProj(wxCommandEvent& event)
{
    wxStandardPaths*  stdPath=(wxStandardPaths*)&wxStandardPaths::Get();
    wxString path=stdPath->GetExecutablePath();
    #ifdef WIN32
    int ns=path.Find('\\',true);
    #else
    int ns=path.Find('/',true);
    #endif
    wxString strDir=path.Mid(0,ns);

    wxMenu* pMenu=new wxMenu();

    #ifdef SINGLE_CAM
//    wxMenuItem *item4=new wxMenuItem(pMenu,ID_MENU_TARGET,_("激光靶"));
//    wxBitmap bmp4(strDir+_("/plugins/config.png"),wxBITMAP_TYPE_PNG);
//    item4->SetBitmap(bmp4);
//    pMenu->Append(item4);
//    pMenu->AppendSeparator();
    #endif

    wxMenuItem *item1=new wxMenuItem(pMenu,ID_MENU_CLEAN,_("清空"));
    wxBitmap bmp1(strDir+_("/plugins/clean.png"),wxBITMAP_TYPE_PNG);
    item1->SetBitmap(bmp1);
    pMenu->Append(item1);
    pMenu->AppendSeparator();
    wxMenuItem *item2=new wxMenuItem(pMenu,ID_MENU_BACKUP,_("备份"));
    wxBitmap bmp2(strDir+_("/plugins/restore.png"),wxBITMAP_TYPE_PNG);
    item2->SetBitmap(bmp2);
    pMenu->Append(item2);
    pMenu->AppendSeparator();
    wxMenuItem *item3=new wxMenuItem(pMenu,ID_MENU_RESTORE,_("还原"));
    wxBitmap bmp3(strDir+_("/plugins/backup.png"),wxBITMAP_TYPE_PNG);
    item3->SetBitmap(bmp3);
    pMenu->Append(item3);
    //pMenu->AppendSeparator();
    if(mtg->onLine == 1)
    {
        item1->Enable(false);
        item3->Enable(false);
    }
    wxPoint rb=btnProj->GetRect().GetTopLeft();
    //int h=pMenu->GetSize().GetHeight();
    panelBtnArea->PopupMenu(pMenu,rb.x,rb.y-90);
}

void MySetupDialog::OnBtnQuit(wxCommandEvent& event)
{
    if(mtg->thread && mtg->threadType==MTG_THREAD_ORIGIN)
    {
        WriteMsg(_("正在进行零位测量，请稍侯..."),1);
        return;
    }
    if(m_bModifyTbm || m_bModifyTps || m_bModifyTar || m_bModifySeg || m_bModifyOrigin || m_bModifyData || m_bModifyMea || m_bModifyAdmin || m_bModifyDriver || m_bModifyLang)
    {
        ConfirmDlg dlg(this);
        dlg.confirmMsg=_("不保存退出吗？");
        if(dlg.ShowModal()==wxID_OK)
        {
            mtg->onLine=-1;
            Destroy();
        }
    }
    else
    {
        mtg->onLine=-1;
        //mtg_send_areas(mtg);
        //mtg_send_blocks(mtg);
        Destroy();
    }
}


void MySetupDialog::WriteMsg(const wxString& str,int color)
{
    switch(color)
    {
        case 0:
            msg_cor = wxColor(0,0,255);
        break;
        case 1:
            msg_cor = wxColor(255,0,0);
        break;
        default:
        break;
    }
    msg_str = str;
    panelBtnArea->Refresh();
}

///对话框部分
void MySetupDialog::OnPaintGraphBlock(wxPaintEvent& event)
{
    wxPaintDC dc(GraphBlock);
    int w,h;
    GraphBlock->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(130,130,130)));
    dc.DrawRectangle(0,0,w,h);

    double radius =(h-30)/2.0;
    double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;

    wxPen pen1=wxPen(wxColor(255,0,0),2);
    wxPen pen2=wxPen(wxColor(30,30,30));
    wxPen pen3=wxPen(wxColor(30,30,30),1,wxLONG_DASH);

    x1=w/2.0;
    y1=h/2.0;
    //wxMessageBox(wxString::Format(_("%d"),mtg->nblk));
    if(mtg->nblk>0)
    {
        double angle = PI*3/2-mtg->blocks[0].angle/2.0;
        for(int i=0;i<mtg->nblk;i++)
        {
            x2=x1+radius*cos(angle+0.02);
            y2=y1+radius*sin(angle+0.02);
            x4=x1+(radius-25)*cos(angle+0.02);
            y4=y1+(radius-25)*sin(angle+0.02);
            angle+=mtg->blocks[i].angle;
            x3=x1+radius*cos(angle-0.02);
            y3=y1+radius*sin(angle-0.02);
            x5=x1+(radius-25)*cos(angle-0.02);
            y5=y1+(radius-25)*sin(angle-0.02);
            if(blockSelect==i)
            {
                dc.SetPen(pen1);
            }
            else
            {
                dc.SetPen(pen2);
            }
            //dc.SetBrush(brush1);
            dc.DrawArc(x3,y3,x2,y2,x1,y1);
            dc.DrawArc(x5,y5,x4,y4,x1,y1);
            dc.DrawLine(x3+(x5-x3)/10,y3+(y5-y3)/10,x5-(x5-x3)/10,y5-(y5-y3)/10);
            dc.DrawLine(x2+(x4-x2)/10,y2+(y4-y2)/10,x4-(x4-x2)/10,y4-(y4-y2)/10);
            dc.SetPen(pen3);
            dc.DrawLine(x4,y4,x1,y1);
        }
    }
}

void MySetupDialog::OnPaintLasercorr(wxPaintEvent& event)
{
    wxPaintDC dc(panelLasercorr);
    int w,h;
    panelLasercorr->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(130,130,130)));

    dc.DrawRectangle(0,0,w,h);

    dc.DrawLine(5,h/2,w-10,h/2);
    dc.DrawLine(w/2,5,w/2,h-10);
    dc.SetBrush(wxBrush(wxColor(130,130,130)));
    wxPoint arrowPts[3];
    arrowPts[0]=wxPoint(w-10,h/2);
    arrowPts[1]=wxPoint(w-10-5,h/2+5);
    arrowPts[2]=wxPoint(w-10-5,h/2-5);
    dc.DrawPolygon(WXSIZEOF(arrowPts),arrowPts,0,0);
    arrowPts[0]=wxPoint(w/2,5);
    arrowPts[1]=wxPoint(w/2-5,10);
    arrowPts[2]=wxPoint(w/2+5,10);
    dc.DrawPolygon(WXSIZEOF(arrowPts),arrowPts,0,0);

    //dc.DrawPolyPolygon(3,);
    dc.SetBrush(wxBrush(wxColor(255,0,0)));
    dc.DrawCircle(w*4/5,h*1/5,5);
    dc.SetPen(wxPen(wxColor(255,0,0)));
    dc.DrawLine(w/2,h/5,w*4/5,h/5);
    dc.DrawLine(w*4/5,h/2,w*4/5,h/5);
    //dc.DrawLabel(_T("Y"),wxRect(w*7/10,h/2,0,0)),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
    dc.DrawLabel(_T("X"),wxRect(w*13/20,h/5,0,0),wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM);
    dc.DrawLabel(_T("Y"),wxRect(w*4/5+5,h*7/20,0,0),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
}


void MySetupDialog::OnPaintNavi(wxPaintEvent& event)
{
    wxPaintDC dc(panelNavi);
    int w,h;
    panelNavi->GetClientSize(&w,&h);

    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(0,-1,w,h+1);
}

void MySetupDialog::OnPaintBorder1(wxPaintEvent& event)
{
    wxPaintDC dc(panelBorder1);
    int w,h;
    panelBorder1->GetClientSize(&w,&h);

    ///background
    int *maxPixels,*minPixels;
    maxPixels=(int*)malloc(3*sizeof(int));
    memset(maxPixels,0,3);

    minPixels=(int*)malloc(3*sizeof(int));
    memset(minPixels,0,3);

    wxRect rect(0,0,w,h);

    maxPixels[0]=227;
    maxPixels[1]=227;
    maxPixels[2]=227;

    minPixels[0]=249;
    minPixels[1]=249;
    minPixels[2]=249;

    PaintGradual(panelBorder1, rect, maxPixels,minPixels,0);

    free(maxPixels);
    free(minPixels);
}

void MySetupDialog::OnPaintBorder2(wxPaintEvent& event)
{
    wxPaintDC dc(panelBorder2);
    int w,h;
    panelBorder2->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.DrawLine(0,h-1,w,h-1);
}

void MySetupDialog::OnPaintBtnPrj(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnPrj);
    int w,h;
    panelBtnPrj->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnPrjState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("工程设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("工程设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("工程设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnPaintBtnKey(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnKey);
    int w,h;
    panelBtnKey->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnKeyState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("关键区域"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("关键区域"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("关键区域"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnPaintDatabase(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnDatabase);
    int w,h;
    panelBtnDatabase->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnDatabaseState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("远程监控"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("远程监控"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("远程监控"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnPaintTarget(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnTarget);
    int w,h;
    panelBtnTarget->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnTargetState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("激光靶设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("激光靶设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("激光靶设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnPaintTheodolite(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnTheodolite);
    int w,h;
    panelBtnTheodolite->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnTheodoliteState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("全站仪设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("全站仪设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("全站仪设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnPaintSeg(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnSeg);
    int w,h;
    panelBtnSeg->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnSegState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("管环设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("管环设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("管环设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnPaintBlock(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnBlock);
    int w,h;
    panelBtnBlock->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnBlockState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("管块设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("管块设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("管块设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnPaintOrigin(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnOrigin);
    int w,h;
    panelBtnOrigin->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnOriginState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("零位设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("零位设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("零位设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnPaintBtnTBM(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnTBM);
    int w,h;
    panelBtnTBM->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnTBMState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("盾构设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("盾构设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("盾构设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnPaintMeas(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnMeas);
    int w,h;
    panelBtnMeas->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnMeasState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("测量设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("测量设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("测量设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnPaintUser(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnUser);
    int w,h;
    panelBtnUser->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnUserState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("用户权限"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("用户权限"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("用户权限"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnPaintLanguage(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnLanguage);
    int w,h;
    panelBtnLanguage->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnLanguageState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("语言设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("语言设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("语言设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MySetupDialog::OnEnterBtnPrj(wxPaintEvent& event)
{
    if(btnPrjState!=4)
    {
        btnPrjState=1;
        panelBtnPrj->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnPrj(wxMouseEvent& event)
{
    if(btnPrjState!=4)
    {
        btnPrjState=2;
        panelBtnPrj->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnPrj(wxMouseEvent& event)
{
    if(btnPrjState!=4)
    {
        btnPrjState=3;
        panelBtnPrj->Refresh();
    }
}

void MySetupDialog::OnBtnPrjClick(wxMouseEvent& event)
{
    if(btnPrjState!=4)
    {
        btnPrjState=4;
        int w,h;
        panelPrj->GetClientSize(&w,&h);
        panelPrj->SetSize(160,10,w,h);
        panelPrj->Refresh();
        panelNavi->Refresh();
        panelBtnPrj->Refresh();
        prj_name->SetFocus();
        if(btnDatabaseState==4)
        {
            btnDatabaseState=0;
            panelDb->SetPosition(wxPoint(w+w+160,10));
            panelBtnDatabase->Refresh();
        }
        if(btnKeyState==4)
        {
            btnKeyState=0;
            panelKey->SetPosition(wxPoint(w+w+160,10));
            panelBtnKey->Refresh();
        }
        if(btnTargetState==4)
        {
            btnTargetState=0;
            panelTarget->SetPosition(wxPoint(w+w+160,10));
            panelBtnTarget->Refresh();
        }
        if(btnTheodoliteState==4)
        {
            btnTheodoliteState=0;
            panelTheo->SetPosition(wxPoint(w+w+160,10));
            panelBtnTheodolite->Refresh();
        }
        if(btnOriginState==4)
        {
            btnOriginState=0;
            panelOri->SetPosition(wxPoint(w+w+160,10));
            panelBtnOrigin->Refresh();
        }
        if(btnTBMState==4)
        {
            btnTBMState=0;
            panelTBM->SetPosition(wxPoint(w+w+160,10));
            panelBtnTBM->Refresh();
        }
        if(btnMeasState==4)
        {
            btnMeasState=0;
            panelMeas->SetPosition(wxPoint(w+w+160,10));
            panelBtnMeas->Refresh();
        }
        if(btnUserState==4)
        {
            btnUserState=0;
            panelUser->SetPosition(wxPoint(w+w+160,10));
            panelBtnUser->Refresh();
        }
        if(btnLanguageState==4)
        {
            btnLanguageState=0;
            panelLang->SetPosition(wxPoint(w+w+160,10));
            panelBtnLanguage->Refresh();
        }
        if(btnSegState==4)
        {
            btnSegState=0;
            panelSeg->SetPosition(wxPoint(w+w+160,10));
            panelBtnSeg->Refresh();
        }
        if(btnBlockState==4)
        {
            btnBlockState=0;
            panelBlock->SetPosition(wxPoint(w+w+160,10));
            panelBtnBlock->Refresh();
        }
    }
}

void MySetupDialog::OnEnterBtnKey(wxPaintEvent& event)
{
    if(btnKeyState!=4)
    {
        btnKeyState=1;
        panelBtnKey->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnKey(wxMouseEvent& event)
{
    if(btnKeyState!=4)
    {
        btnKeyState=2;
        panelBtnKey->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnKey(wxMouseEvent& event)
{
    if(btnKeyState!=4)
    {
        btnKeyState=3;
        panelBtnKey->Refresh();
    }
}

void MySetupDialog::OnBtnKeyClick(wxMouseEvent& event)
{
    if(btnKeyState!=4)
    {
        btnKeyState=4;
        int w,h;
        panelKey->GetClientSize(&w,&h);
        panelKey->SetSize(160,10,w,h);
        panelKey->Refresh();
        panelNavi->Refresh();
        panelBtnKey->Refresh();
        //prjName->SetFocus();
        if(btnPrjState==4)
        {
            btnPrjState=0;
            panelPrj->SetPosition(wxPoint(w+w+160,10));
            panelBtnPrj->Refresh();
        }
        if(btnDatabaseState==4)
        {
            btnDatabaseState=0;
            panelDb->SetPosition(wxPoint(w+w+160,10));
            panelBtnDatabase->Refresh();
        }
        if(btnTargetState==4)
        {
            btnTargetState=0;
            panelTarget->SetPosition(wxPoint(w+w+160,10));
            panelBtnTarget->Refresh();
        }
        if(btnTheodoliteState==4)
        {
            btnTheodoliteState=0;
            panelTheo->SetPosition(wxPoint(w+w+160,10));
            panelBtnTheodolite->Refresh();
        }
        if(btnOriginState==4)
        {
            btnOriginState=0;
            panelOri->SetPosition(wxPoint(w+w+160,10));
            panelBtnOrigin->Refresh();
        }
        if(btnTBMState==4)
        {
            btnTBMState=0;
            panelTBM->SetPosition(wxPoint(w+w+160,10));
            panelBtnTBM->Refresh();
        }
        if(btnMeasState==4)
        {
            btnMeasState=0;
            panelMeas->SetPosition(wxPoint(w+w+160,10));
            panelBtnMeas->Refresh();
        }
        if(btnUserState==4)
        {
            btnUserState=0;
            panelUser->SetPosition(wxPoint(w+w+160,10));
            panelBtnUser->Refresh();
        }
        if(btnLanguageState==4)
        {
            btnLanguageState=0;
            panelLang->SetPosition(wxPoint(w+w+160,10));
            panelBtnLanguage->Refresh();
        }
        if(btnSegState==4)
        {
            btnSegState=0;
            panelSeg->SetPosition(wxPoint(w+w+160,10));
            panelBtnSeg->Refresh();
        }
        if(btnBlockState==4)
        {
            btnBlockState=0;
            panelBlock->SetPosition(wxPoint(w+w+160,10));
            panelBtnBlock->Refresh();
        }
    }
}


void MySetupDialog::OnEnterBtnDatabase(wxMouseEvent& event)
{
    if(btnDatabaseState!=4)
    {
        btnDatabaseState=1;
        panelBtnDatabase->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnDatabase(wxPaintEvent& event)
{
    if(btnDatabaseState!=4)
    {
        btnDatabaseState=2;
        panelBtnDatabase->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnDatabase(wxMouseEvent& event)
{
    if(btnDatabaseState!=4)
    {
        btnDatabaseState=3;
        panelBtnDatabase->Refresh();
    }
}

void MySetupDialog::OnBtnDatabaseClick(wxMouseEvent& event)
{
    if(btnDatabaseState!=4)
    {
        btnDatabaseState=4;
        int w,h;
        panelDb->GetClientSize(&w,&h);
        panelDb->SetSize(160,10,w,h);
        panelDb->Refresh();
        panelNavi->Refresh();
        panelBtnDatabase->Refresh();
        if(btnPrjState==4)
        {
            btnPrjState=0;
            panelPrj->SetPosition(wxPoint(w+w+160,10));
            panelBtnPrj->Refresh();
        }
        if(btnKeyState==4)
        {
            btnKeyState=0;
            panelKey->SetPosition(wxPoint(w+w+160,10));
            panelBtnKey->Refresh();
        }
        if(btnTargetState==4)
        {
            btnTargetState=0;
            panelTarget->SetPosition(wxPoint(w+w+160,10));
            panelBtnTarget->Refresh();
        }
        if(btnTheodoliteState==4)
        {
            btnTheodoliteState=0;
            panelTheo->SetPosition(wxPoint(w+w+160,10));
            panelBtnTheodolite->Refresh();
        }
        if(btnOriginState==4)
        {
            btnOriginState=0;
            panelOri->SetPosition(wxPoint(w+w+160,10));
            panelBtnOrigin->Refresh();
        }
        if(btnTBMState==4)
        {
            btnTBMState=0;
            panelTBM->SetPosition(wxPoint(w+w+160,10));
            panelBtnTBM->Refresh();
        }
        if(btnMeasState==4)
        {
            btnMeasState=0;
            panelMeas->SetPosition(wxPoint(w+w+160,10));
            panelBtnMeas->Refresh();
        }
        if(btnUserState==4)
        {
            btnUserState=0;
            panelUser->SetPosition(wxPoint(w+w+160,10));
            panelBtnUser->Refresh();
        }
        if(btnLanguageState==4)
        {
            btnLanguageState=0;
            panelLang->SetPosition(wxPoint(w+w+160,10));
            panelBtnLanguage->Refresh();
        }
         if(btnSegState==4)
        {
            btnSegState=0;
            panelSeg->SetPosition(wxPoint(w+w+160,10));
            panelBtnSeg->Refresh();
        }
        if(btnBlockState==4)
        {
            btnBlockState=0;
            panelBlock->SetPosition(wxPoint(w+w+160,10));
            panelBtnBlock->Refresh();
        }
    }
}

void MySetupDialog::OnEnterBtnTarget(wxMouseEvent& event)
{
    if(btnTargetState!=4)
    {
        btnTargetState=1;
        panelBtnTarget->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnTarget(wxMouseEvent& event)
{
    if(btnTargetState!=4)
    {
        btnTargetState=2;
        panelBtnTarget->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnTarget(wxPaintEvent& event)
{
    if(btnTargetState!=4)
    {
        btnTargetState=3;
        panelBtnTarget->Refresh();
    }
}

void MySetupDialog::OnBtnTargetClick(wxPaintEvent& event)
{
    if(btnTargetState!=4)
    {
        btnTargetState=4;
        int w,h;
        panelTarget->GetClientSize(&w,&h);
        panelTarget->SetSize(160,10,w,h);
        panelTarget->Refresh();
        panelNavi->Refresh();
        panelBtnTarget->Refresh();
        target_prism->SetFocus();
        if(btnPrjState==4)
        {
            btnPrjState=0;
            panelPrj->SetPosition(wxPoint(w+w+160,10));
            panelBtnPrj->Refresh();
        }
        if(btnKeyState==4)
        {
            btnKeyState=0;
            panelKey->SetPosition(wxPoint(w+w+160,10));
            panelBtnKey->Refresh();
        }
        if(btnDatabaseState==4)
        {
            btnDatabaseState=0;
            panelDb->SetPosition(wxPoint(w+w+160,10));
            panelBtnDatabase->Refresh();
        }
        if(btnTheodoliteState==4)
        {
            btnTheodoliteState=0;
            panelTheo->SetPosition(wxPoint(w+w+160,10));
            panelBtnTheodolite->Refresh();
        }
        if(btnOriginState==4)
        {
            btnOriginState=0;
            panelOri->SetPosition(wxPoint(w+w+160,10));
            panelBtnOrigin->Refresh();
        }
        if(btnTBMState==4)
        {
            btnTBMState=0;
            panelTBM->SetPosition(wxPoint(w+w+160,10));
            panelBtnTBM->Refresh();
        }
        if(btnMeasState==4)
        {
            btnMeasState=0;
            panelMeas->SetPosition(wxPoint(w+w+160,10));
            panelBtnMeas->Refresh();
        }
        if(btnUserState==4)
        {
            btnUserState=0;
            panelUser->SetPosition(wxPoint(w+w+160,10));
            panelBtnUser->Refresh();
        }
        if(btnLanguageState==4)
        {
            btnLanguageState=0;
            panelLang->SetPosition(wxPoint(w+w+160,10));
            panelBtnLanguage->Refresh();
        }
        if(btnSegState==4)
        {
            btnSegState=0;
            panelSeg->SetPosition(wxPoint(w+w+160,10));
            panelBtnSeg->Refresh();
        }
        if(btnBlockState==4)
        {
            btnBlockState=0;
            panelBlock->SetPosition(wxPoint(w+w+160,10));
            panelBtnBlock->Refresh();
        }
    }
}

void MySetupDialog::OnEnterBtnSeg(wxPaintEvent& event)
{
    if(btnSegState!=4)
    {
        btnSegState=1;
        panelBtnSeg->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnSeg(wxMouseEvent& event)
{
    if(btnSegState!=4)
    {
        btnSegState=2;
        panelBtnSeg->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnSeg(wxMouseEvent& event)
{
    if(btnSegState!=4)
    {
        btnSegState=3;
        panelBtnSeg->Refresh();
    }
}

void MySetupDialog::OnBtnSegClick(wxMouseEvent& event)
{
    if(btnSegState!=4)
    {
        btnSegState=4;
        int w,h;
        panelSeg->GetClientSize(&w,&h);
        panelSeg->SetSize(160,10,w,h);
        panelSeg->Refresh();
        panelNavi->Refresh();
        panelBtnSeg->Refresh();
        seg_len->SetFocus();
        if(btnPrjState==4)
        {
            btnPrjState=0;
            panelPrj->SetPosition(wxPoint(w+w+160,10));
            panelBtnPrj->Refresh();
        }
        if(btnKeyState==4)
        {
            btnKeyState=0;
            panelKey->SetPosition(wxPoint(w+w+160,10));
            panelBtnKey->Refresh();
        }
        if(btnTargetState==4)
        {
            btnTargetState=0;
            panelTarget->SetPosition(wxPoint(w+w+160,10));
            panelBtnTarget->Refresh();
        }
        if(btnDatabaseState==4)
        {
            btnDatabaseState=0;
            panelDb->SetPosition(wxPoint(w+w+160,10));
            panelBtnDatabase->Refresh();
        }
        if(btnOriginState==4)
        {
            btnOriginState=0;
            panelOri->SetPosition(wxPoint(w+w+160,10));
            panelBtnOrigin->Refresh();
        }
        if(btnTBMState==4)
        {
            btnTBMState=0;
            panelTBM->SetPosition(wxPoint(w+w+160,10));
            panelBtnTBM->Refresh();
        }
        if(btnMeasState==4)
        {
            btnMeasState=0;
            panelMeas->SetPosition(wxPoint(w+w+160,10));
            panelBtnMeas->Refresh();
        }
        if(btnUserState==4)
        {
            btnUserState=0;
            panelUser->SetPosition(wxPoint(w+w+160,10));
            panelBtnUser->Refresh();
        }
        if(btnLanguageState==4)
        {
            btnLanguageState=0;
            panelLang->SetPosition(wxPoint(w+w+160,10));
            panelBtnLanguage->Refresh();
        }
        if(btnTheodoliteState==4)
        {
            btnTheodoliteState=0;
            panelTheo->SetPosition(wxPoint(w+w+160,10));
            panelBtnTheodolite->Refresh();
        }
        if(btnBlockState==4)
        {
            btnBlockState=0;
            panelBlock->SetPosition(wxPoint(w+w+160,10));
            panelBtnBlock->Refresh();
        }
    }
}

void MySetupDialog::OnEnterBtnBlock(wxPaintEvent& event)
{
    if(btnBlockState!=4)
    {
        btnBlockState=1;
        panelBtnBlock->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnBlock(wxMouseEvent& event)
{
    if(btnBlockState!=4)
    {
        btnBlockState=2;
        panelBtnBlock->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnBlock(wxMouseEvent& event)
{
    if(btnBlockState!=4)
    {
        btnBlockState=3;
        panelBtnBlock->Refresh();
    }
}

void MySetupDialog::OnBtnBlockClick(wxMouseEvent& event)
{
    if(btnBlockState!=4)
    {
        btnBlockState=4;
        int w,h;
        panelBlock->GetClientSize(&w,&h);
        panelBlock->SetSize(160,10,w,h);
        panelBlock->Refresh();
        panelNavi->Refresh();
        panelBtnBlock->Refresh();
        ///工程信息
        if(btnPrjState==4)
        {
            btnPrjState=0;
            panelPrj->SetPosition(wxPoint(w+w+160,10));
            panelBtnPrj->Refresh();
        }
        if(btnKeyState==4)
        {
            btnKeyState=0;
            panelKey->SetPosition(wxPoint(w+w+160,10));
            panelBtnKey->Refresh();
        }
        ///盾构
        if(btnTBMState==4)
        {
            btnTBMState=0;
            panelTBM->SetPosition(wxPoint(w+w+160,10));
            panelBtnTBM->Refresh();
        }
        ///激光靶
        if(btnTargetState==4)
        {
            btnTargetState=0;
            panelTarget->SetPosition(wxPoint(w+w+160,10));
            panelBtnTarget->Refresh();
        }
        ///全站仪
        if(btnTheodoliteState==4)
        {
            btnTheodoliteState=0;
            panelTheo->SetPosition(wxPoint(w+w+160,10));
            panelBtnTheodolite->Refresh();
        }
        ///管环
        if(btnSegState==4)
        {
            btnSegState=0;
            panelSeg->SetPosition(wxPoint(w+w+160,10));
            panelBtnSeg->Refresh();
        }
        ///零位
        if(btnOriginState==4)
        {
            btnOriginState=0;
            panelOri->SetPosition(wxPoint(w+w+160,10));
            panelBtnOrigin->Refresh();
        }
        ///数据
        if(btnDatabaseState==4)
        {
            btnDatabaseState=0;
            panelDb->SetPosition(wxPoint(w+w+160,10));
            panelBtnDatabase->Refresh();
        }
        ///测量
        if(btnMeasState==4)
        {
            btnMeasState=0;
            panelMeas->SetPosition(wxPoint(w+w+160,10));
            panelBtnMeas->Refresh();
        }
        ///用户
        if(btnUserState==4)
        {
            btnUserState=0;
            panelUser->SetPosition(wxPoint(w+w+160,10));
            panelBtnUser->Refresh();
        }
        ///语言
        if(btnLanguageState==4)
        {
            btnLanguageState=0;
            panelLang->SetPosition(wxPoint(w+w+160,10));
            panelBtnLanguage->Refresh();
        }
    }
}


void MySetupDialog::OnEnterBtnTheodolite(wxPaintEvent& event)
{
    if(btnTheodoliteState!=4)
    {
        btnTheodoliteState=1;
        panelBtnTheodolite->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnTheodolite(wxMouseEvent& event)
{
    if(btnTheodoliteState!=4)
    {
        btnTheodoliteState=2;
        panelBtnTheodolite->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnTheodolite(wxMouseEvent& event)
{
    if(btnTheodoliteState!=4)
    {
        btnTheodoliteState=3;
        panelBtnTheodolite->Refresh();
    }
}

void MySetupDialog::OnBtnTheodoliteClick(wxMouseEvent& event)
{
    if(btnTheodoliteState!=4)
    {
        btnTheodoliteState=4;
        int w,h;
        panelTheo->GetClientSize(&w,&h);
        panelTheo->SetSize(160,10,w,h);
        panelTheo->Refresh();
        panelNavi->Refresh();
        panelBtnTheodolite->Refresh();
        if(mtg->tps.lasertype == 2)
        {
            tps_laserh->SetFocus();
            tpsset = 0;
        }
        else
        {
            tps_laserd->SetFocus();
            tpsset = 1;
        }
        if(btnPrjState==4)
        {
            btnPrjState=0;
            panelPrj->SetPosition(wxPoint(w+w+160,10));
            panelBtnPrj->Refresh();
        }
        if(btnKeyState==4)
        {
            btnKeyState=0;
            panelKey->SetPosition(wxPoint(w+w+160,10));
            panelBtnKey->Refresh();
        }
        if(btnTargetState==4)
        {
            btnTargetState=0;
            panelTarget->SetPosition(wxPoint(w+w+160,10));
            panelBtnTarget->Refresh();
        }
        if(btnDatabaseState==4)
        {
            btnDatabaseState=0;
            panelDb->SetPosition(wxPoint(w+w+160,10));
            panelBtnDatabase->Refresh();
        }
        if(btnOriginState==4)
        {
            btnOriginState=0;
            panelOri->SetPosition(wxPoint(w+w+160,10));
            panelBtnOrigin->Refresh();
        }
        if(btnTBMState==4)
        {
            btnTBMState=0;
            panelTBM->SetPosition(wxPoint(w+w+160,10));
            panelBtnTBM->Refresh();
        }
        if(btnMeasState==4)
        {
            btnMeasState=0;
            panelMeas->SetPosition(wxPoint(w+w+160,10));
            panelBtnMeas->Refresh();
        }
        if(btnUserState==4)
        {
            btnUserState=0;
            panelUser->SetPosition(wxPoint(w+w+160,10));
            panelBtnUser->Refresh();
        }
        if(btnLanguageState==4)
        {
            btnLanguageState=0;
            panelLang->SetPosition(wxPoint(w+w+160,10));
            panelBtnLanguage->Refresh();
        }
        if(btnSegState==4)
        {
            btnSegState=0;
            panelSeg->SetPosition(wxPoint(w+w+160,10));
            panelBtnSeg->Refresh();
        }
        if(btnBlockState==4)
        {
            btnBlockState=0;
            panelBlock->SetPosition(wxPoint(w+w+160,10));
            panelBtnBlock->Refresh();
        }
    }
}


void MySetupDialog::OnEnterBtnOrigin(wxPaintEvent& event)
{
    if(btnOriginState!=4)
    {
        btnOriginState=1;
        panelBtnOrigin->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnOrigin(wxMouseEvent& event)
{
    if(btnOriginState!=4)
    {
        btnOriginState=2;
        panelBtnOrigin->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnOrigin(wxMouseEvent& event)
{
    if(btnOriginState!=4)
    {
        btnOriginState=3;
        panelBtnOrigin->Refresh();
    }
}

void MySetupDialog::OnBtnOriginClick(wxMouseEvent& event)
{
    if(btnOriginState!=4)
    {
        if(midf_checkbox->GetValue()==true)
        {
            midx_text->Enable(true);
            midy_text->Enable(true);
            midz_text->Enable(true);
            up_mid_text->Enable(true);
            left_mid_text->Enable(true);
            down_mid_text->Enable(true);
            right_mid_text->Enable(true);

            tailx_text->SetEditable(true);
            taily_text->SetEditable(true);
            tailz_text->SetEditable(true);
            headx_text->SetEditable(false);
            heady_text->SetEditable(false);
            headz_text->SetEditable(false);
            CalHead();
        }
        else if(midb_checkbox->GetValue()==true)
        {
            midx_text->Enable(true);
            midy_text->Enable(true);
            midz_text->Enable(true);
            up_mid_text->Enable(true);
            left_mid_text->Enable(true);
            down_mid_text->Enable(true);
            right_mid_text->Enable(true);

            tailx_text->SetEditable(false);
            taily_text->SetEditable(false);
            tailz_text->SetEditable(false);
            headx_text->SetEditable(true);
            heady_text->SetEditable(true);
            headz_text->SetEditable(true);
            CalTail();
        }
        else
        {
            midx_text->Enable(false);
            midy_text->Enable(false);
            midz_text->Enable(false);
            up_mid_text->Enable(false);
            left_mid_text->Enable(false);
            down_mid_text->Enable(false);
            right_mid_text->Enable(false);
        }
        btnOriginState=4;
        int w,h;
        panelOri->GetClientSize(&w,&h);
        panelOri->SetSize(160,10,w,h);
        panelOri->Refresh();
        panelNavi->Refresh();
        panelBtnOrigin->Refresh();
        headx_text->SetFocus();
        if(btnPrjState==4)
        {
            btnPrjState=0;
            panelPrj->SetPosition(wxPoint(w+w+160,10));
            panelBtnPrj->Refresh();
        }
        if(btnKeyState==4)
        {
            btnKeyState=0;
            panelKey->SetPosition(wxPoint(w+w+160,10));
            panelBtnKey->Refresh();
        }
        if(btnTargetState==4)
        {
            btnTargetState=0;
            panelTarget->SetPosition(wxPoint(w+w+160,10));
            panelBtnTarget->Refresh();
        }
        if(btnTheodoliteState==4)
        {
            btnTheodoliteState=0;
            panelTheo->SetPosition(wxPoint(w+w+160,10));
            panelBtnTheodolite->Refresh();
        }
        if(btnDatabaseState==4)
        {
            btnDatabaseState=0;
            panelDb->SetPosition(wxPoint(w+w+160,10));
            panelBtnDatabase->Refresh();
        }
        if(btnTBMState==4)
        {
            btnTBMState=0;
            panelTBM->SetPosition(wxPoint(w+w+160,10));
            panelBtnTBM->Refresh();
        }
        if(btnMeasState==4)
        {
            btnMeasState=0;
            panelMeas->SetPosition(wxPoint(w+w+160,10));
            panelBtnMeas->Refresh();
        }
        if(btnUserState==4)
        {
            btnUserState=0;
            panelUser->SetPosition(wxPoint(w+w+160,10));
            panelBtnUser->Refresh();
        }
        if(btnLanguageState==4)
        {
            btnLanguageState=0;
            panelLang->SetPosition(wxPoint(w+w+160,10));
            panelBtnLanguage->Refresh();
        }
        if(btnSegState==4)
        {
            btnSegState=0;
            panelSeg->SetPosition(wxPoint(w+w+160,10));
            panelBtnSeg->Refresh();
        }
        if(btnBlockState==4)
        {
            btnBlockState=0;
            panelBlock->SetPosition(wxPoint(w+w+160,10));
            panelBtnBlock->Refresh();
        }
    }
}

void MySetupDialog::OnEnterBtnTBM(wxPaintEvent& event)
{
    if(btnTBMState!=4)
    {
        btnTBMState=1;
        panelBtnTBM->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnTBM(wxMouseEvent& event)
{
     if(btnTBMState!=4)
    {
        btnTBMState=2;
        panelBtnTBM->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnTBM(wxMouseEvent& event)
{
     if(btnTBMState!=4)
    {
        btnTBMState=3;
        panelBtnTBM->Refresh();
    }
}

void MySetupDialog::OnBtnTBMClick(wxMouseEvent& event)
{
     if(btnTBMState!=4)
    {
        btnTBMState=4;
        int w,h;
        panelTBM->GetClientSize(&w,&h);
        panelTBM->SetSize(160,10,w,h);
        panelTBM->Refresh();
        panelNavi->Refresh();
        panelBtnTBM->Refresh();
        TBM_index->SetFocus();
        if(btnPrjState==4)
        {
            btnPrjState=0;
            panelPrj->SetPosition(wxPoint(w+w+160,10));
            panelBtnPrj->Refresh();
        }
        if(btnKeyState==4)
        {
            btnKeyState=0;
            panelKey->SetPosition(wxPoint(w+w+160,10));
            panelBtnKey->Refresh();
        }
        if(btnTargetState==4)
        {
            btnTargetState=0;
            panelTarget->SetPosition(wxPoint(w+w+160,10));
            panelBtnTarget->Refresh();
        }
        if(btnTheodoliteState==4)
        {
            btnTheodoliteState=0;
            panelTheo->SetPosition(wxPoint(w+w+160,10));
            panelBtnTheodolite->Refresh();
        }
        if(btnOriginState==4)
        {
            btnOriginState=0;
            panelOri->SetPosition(wxPoint(w+w+160,10));
            panelBtnOrigin->Refresh();
        }
        if(btnDatabaseState==4)
        {
            btnDatabaseState=0;
            panelDb->SetPosition(wxPoint(w+w+160,10));
            panelBtnDatabase->Refresh();
        }
        if(btnMeasState==4)
        {
            btnMeasState=0;
            panelMeas->SetPosition(wxPoint(w+w+160,10));
            panelBtnMeas->Refresh();
        }
        if(btnUserState==4)
        {
            btnUserState=0;
            panelUser->SetPosition(wxPoint(w+w+160,10));
            panelBtnUser->Refresh();
        }
        if(btnLanguageState==4)
        {
            btnLanguageState=0;
            panelLang->SetPosition(wxPoint(w+w+160,10));
            panelBtnLanguage->Refresh();
        }
        if(btnSegState==4)
        {
            btnSegState=0;
            panelSeg->SetPosition(wxPoint(w+w+160,10));
            panelBtnSeg->Refresh();
        }
        if(btnBlockState==4)
        {
            btnBlockState=0;
            panelBlock->SetPosition(wxPoint(w+w+160,10));
            panelBtnBlock->Refresh();
        }
    }
}

void MySetupDialog::OnEnterBtnMeas(wxPaintEvent& event)
{
    if(btnMeasState!=4)
    {
        btnMeasState=1;
        panelBtnMeas->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnMeas(wxMouseEvent& event)
{
   if(btnMeasState!=4)
    {
        btnMeasState=2;
        panelBtnMeas->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnMeas(wxMouseEvent& event)
{
    if(btnMeasState!=4)
    {
        btnMeasState=3;
        panelBtnMeas->Refresh();
    }
}

void MySetupDialog::OnBtnMeasClick(wxMouseEvent& event)
{
    if(btnMeasState!=4)
    {
        btnMeasState=4;
        int w,h;
        panelMeas->GetClientSize(&w,&h);
        panelMeas->SetSize(160,10,w,h);
        panelMeas->Refresh();
        panelNavi->Refresh();
        panelBtnMeas->Refresh();
        measTime1->SetFocus();
        if(btnPrjState==4)
        {
            btnPrjState=0;
            panelPrj->SetPosition(wxPoint(w+w+160,10));
            panelBtnPrj->Refresh();
        }
        if(btnKeyState==4)
        {
            btnKeyState=0;
            panelKey->SetPosition(wxPoint(w+w+160,10));
            panelBtnKey->Refresh();
        }
        if(btnTargetState==4)
        {
            btnTargetState=0;
            panelTarget->SetPosition(wxPoint(w+w+160,10));
            panelBtnTarget->Refresh();
        }
        if(btnTheodoliteState==4)
        {
            btnTheodoliteState=0;
            panelTheo->SetPosition(wxPoint(w+w+160,10));
            panelBtnTheodolite->Refresh();
        }
        if(btnOriginState==4)
        {
            btnOriginState=0;
            panelOri->SetPosition(wxPoint(w+w+160,10));
            panelBtnOrigin->Refresh();
        }
        if(btnTBMState==4)
        {
            btnTBMState=0;
            panelTBM->SetPosition(wxPoint(w+w+160,10));
            panelBtnTBM->Refresh();
        }
        if(btnDatabaseState==4)
        {
            btnDatabaseState=0;
            panelDb->SetPosition(wxPoint(w+w+160,10));
            panelBtnDatabase->Refresh();
        }
        if(btnUserState==4)
        {
            btnUserState=0;
            panelUser->SetPosition(wxPoint(w+w+160,10));
            panelBtnUser->Refresh();
        }
        if(btnLanguageState==4)
        {
            btnLanguageState=0;
            panelLang->SetPosition(wxPoint(w+w+160,10));
            panelBtnLanguage->Refresh();
        }
        if(btnSegState==4)
        {
            btnSegState=0;
            panelSeg->SetPosition(wxPoint(w+w+160,10));
            panelBtnSeg->Refresh();
        }
        if(btnBlockState==4)
        {
            btnBlockState=0;
            panelBlock->SetPosition(wxPoint(w+w+160,10));
            panelBtnBlock->Refresh();
        }
    }
}

void MySetupDialog::OnEnterBtnUser(wxPaintEvent& event)
{
    if(btnUserState!=4)
    {
        btnUserState=1;
        panelBtnUser->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnUser(wxMouseEvent& event)
{
    if(btnUserState!=4)
    {
        btnUserState=2;
        panelBtnUser->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnUser(wxMouseEvent& event)
{
    if(btnUserState!=4)
    {
        btnUserState=3;
        panelBtnUser->Refresh();
    }
}

void MySetupDialog::OnBtnUserClick(wxMouseEvent& event)
{
    if(btnUserState!=4)
    {
        btnUserState=4;
        int w,h;
        panelUser->GetClientSize(&w,&h);
        panelUser->SetSize(160,10,w,h);
        panelUser->Refresh();
        panelNavi->Refresh();
        panelBtnUser->Refresh();
        //old_manager_password->SetFocus();
        if(btnPrjState==4)
        {
            btnPrjState=0;
            panelPrj->SetPosition(wxPoint(w+w+160,10));
            panelBtnPrj->Refresh();
        }
        if(btnKeyState==4)
        {
            btnKeyState=0;
            panelKey->SetPosition(wxPoint(w+w+160,10));
            panelBtnKey->Refresh();
        }
        if(btnTargetState==4)
        {
            btnTargetState=0;
            panelTarget->SetPosition(wxPoint(w+w+160,10));
            panelBtnTarget->Refresh();
        }
        if(btnTheodoliteState==4)
        {
            btnTheodoliteState=0;
            panelTheo->SetPosition(wxPoint(w+w+160,10));
            panelBtnTheodolite->Refresh();
        }
        if(btnOriginState==4)
        {
            btnOriginState=0;
            panelOri->SetPosition(wxPoint(w+w+160,10));
            panelBtnOrigin->Refresh();
        }
        if(btnTBMState==4)
        {
            btnTBMState=0;
            panelTBM->SetPosition(wxPoint(w+w+160,10));
            panelBtnTBM->Refresh();
        }
        if(btnMeasState==4)
        {
            btnMeasState=0;
            panelMeas->SetPosition(wxPoint(w+w+160,10));
            panelBtnMeas->Refresh();
        }
        if(btnDatabaseState==4)
        {
            btnDatabaseState=0;
            panelDb->SetPosition(wxPoint(w+w+160,10));
            panelBtnDatabase->Refresh();
        }
        if(btnLanguageState==4)
        {
            btnLanguageState=0;
            panelLang->SetPosition(wxPoint(w+w+160,10));
            panelBtnLanguage->Refresh();
        }
        if(btnSegState==4)
        {
            btnSegState=0;
            panelSeg->SetPosition(wxPoint(w+w+160,10));
            panelBtnSeg->Refresh();
        }
        if(btnBlockState==4)
        {
            btnBlockState=0;
            panelBlock->SetPosition(wxPoint(w+w+160,10));
            panelBtnBlock->Refresh();
        }
    }
}

void MySetupDialog::OnEnterBtnLanguage(wxPaintEvent& event)
{
    if(btnLanguageState!=4)
    {
        btnLanguageState=1;
        panelBtnLanguage->Refresh();
    }
}

void MySetupDialog::OnLeaveBtnLanguage(wxMouseEvent& event)
{
    if(btnLanguageState!=4)
    {
        btnLanguageState=2;
        panelBtnLanguage->Refresh();
    }
}

void MySetupDialog::OnLeftDownBtnLanguage(wxMouseEvent& event)
{
    if(btnLanguageState!=4)
    {
        btnLanguageState=3;
        panelBtnLanguage->Refresh();
    }
}

void MySetupDialog::OnBtnLanguageClick(wxMouseEvent& event)
{
    if(btnLanguageState!=4)
    {
        btnLanguageState=4;
        int w,h;
        panelLang->GetClientSize(&w,&h);

        panelLang->SetPosition(wxPoint(160,10));
        panelLang->Refresh();
        panelNavi->Refresh();
        panelBtnLanguage->Refresh();
        if(btnPrjState==4)
        {
            //wxMessageBox(wxString::Format(_("%d"),w));
            btnPrjState=0;
            panelPrj->SetPosition(wxPoint(w+w+160,10));
            wxPoint pt;
            panelPrj->GetPosition(&pt.x,&pt.y);
            //wxMessageBox(wxString::Format(_("%d,%d"),pt.x,pt.y));
            panelBtnPrj->Refresh();
        }
        if(btnKeyState==4)
        {
            btnKeyState=0;
            panelKey->SetPosition(wxPoint(w+w+160,10));
            panelBtnKey->Refresh();
        }
        if(btnTargetState==4)
        {
            btnTargetState=0;
            panelTarget->SetPosition(wxPoint(w+w+160,10));
            panelBtnTarget->Refresh();
        }
        if(btnTheodoliteState==4)
        {
            btnTheodoliteState=0;
            panelTheo->SetPosition(wxPoint(w+w+160,10));
            panelBtnTheodolite->Refresh();
        }
        if(btnOriginState==4)
        {
            btnOriginState=0;
            panelOri->SetPosition(wxPoint(w+w+160,10));
            panelBtnOrigin->Refresh();
        }
        if(btnTBMState==4)
        {
            btnTBMState=0;
            panelTBM->SetPosition(wxPoint(w+w+160,10));
            panelBtnTBM->Refresh();
        }
        if(btnMeasState==4)
        {
            btnMeasState=0;
            panelMeas->SetPosition(wxPoint(w+w+160,10));
            panelBtnMeas->Refresh();
        }
        if(btnUserState==4)
        {
            btnUserState=0;
            panelUser->SetPosition(wxPoint(w+w+160,10));
            panelBtnUser->Refresh();
        }
        if(btnDatabaseState==4)
        {
            btnDatabaseState=0;
            panelDb->SetPosition(wxPoint(w+w+160,10));
            panelBtnDatabase->Refresh();
        }
        if(btnSegState==4)
        {
            btnSegState=0;
            panelSeg->SetPosition(wxPoint(w+w+160,10));
            panelBtnSeg->Refresh();
        }
        if(btnBlockState==4)
        {
            btnBlockState=0;
            panelBlock->SetPosition(wxPoint(w+w+160,10));
            panelBtnBlock->Refresh();
        }
    }
}

void MySetupDialog::LayoutPrj()
{
    StaticText1->SetPosition(wxPoint(35,25));
    StaticText1->SetLabel(_("工程信息设置"));
    StaticText9->SetPosition(wxPoint(35,60));
    StaticText9->SetLabel(_("工程名称"));
    prj_name->SetPosition(wxPoint(120,55));
    StaticText3->SetPosition(wxPoint(35,95));
    StaticText3->SetLabel(_("起点里程"));
    prj_mile1->SetPosition(wxPoint(120,90));
    StaticText4->SetPosition(wxPoint(35,130));
    StaticText4->SetLabel(_("终点里程"));
    prj_mile2->SetPosition(wxPoint(120,125));
    StaticText64->SetPosition(wxPoint(35,165));
    StaticText64->SetLabel(_("掘进方向"));
    //direct_choice->SetPosition(wxPoint(120,155));
    forward_checkbox->SetPosition(wxPoint(120,165));
    reverse_checkbox->SetPosition(wxPoint(280,165));
    StaticText14->SetPosition(wxPoint(35,223));
    StaticText14->SetLabel(_("值班时间设置"));
    StaticText15->SetPosition(wxPoint(65,253));
    StaticText15->SetLabel(_("白班上班时间"));
    day_hour->SetPosition(wxPoint(65,313));
    day_min->SetPosition(wxPoint(115,313));
    StaticText114->SetPosition(wxPoint(106,313));
    btnAddDayh->SetPosition(wxPoint(65,283));
    btnAddDayh->SetSize(wxSize(40,-1));
    btnAddDayh->SetLabel(_("↑"));
    btnSubDayh->SetPosition(wxPoint(65,338));
    btnSubDayh->SetSize(wxSize(40,-1));
    btnSubDayh->SetLabel(_("↓"));
    btnAddDaym->SetPosition(wxPoint(115,283));
    btnAddDaym->SetSize(wxSize(40,-1));
    btnAddDaym->SetLabel(_("↑"));
    btnSubDaym->SetPosition(wxPoint(115,338));
    btnSubDaym->SetSize(wxSize(40,-1));
    btnSubDaym->SetLabel(_("↓"));
    StaticText16->SetPosition(wxPoint(240,253));
    StaticText16->SetLabel(_("夜班上班时间"));
    night_hour->SetPosition(wxPoint(240,313));
    night_min->SetPosition(wxPoint(290,313));
    btnAddNighth->SetPosition(wxPoint(240,283));
    btnAddNighth->SetSize(wxSize(40,-1));
    btnAddNighth->SetLabel(_("↑"));
    btnSubNighth->SetPosition(wxPoint(240,338));
    btnSubNighth->SetSize(wxSize(40,-1));
    btnSubNighth->SetLabel(_("↓"));
    btnAddNightm->SetPosition(wxPoint(290,283));
    btnAddNightm->SetSize(wxSize(40,-1));
    btnAddNightm->SetLabel(_("↑"));
    btnSubNightm->SetPosition(wxPoint(290,338));
    btnSubNightm->SetSize(wxSize(40,-1));
    btnSubNightm->SetLabel(_("↓"));
    StaticText115->SetPosition(wxPoint(281,313));
}

void MySetupDialog::OnPaintPrj(wxPaintEvent& event)
{
    wxPaintDC dc(panelPrj);
    int w,h;
    panelPrj->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.DrawRectangle(300-2,285,4,25);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetBrush(wxBrush(wxColor(219,219,219)));
    /*
    StaticText1  工程信息  StaticText9  项目名称  prj_name  工程名称文本框
    StaticText3  起点里程  prj_mile1  起点里程文本框  StaticText4  终点里程
    prj_mile2  终点里程文本框  StaticText64  掘进方向  direct_choice  掘进方向选择
    StaticText14  值班设置  StaticText15  白班设置  day_hour  白班时间
    StaticText16  夜班设置  night_hour  夜班时间
    */
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,32,585,32);
    dc.DrawLine(25,32,25,115);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(300,90,45,25);
    dc.DrawLabel(wxString::Format(_("m ")),wxRect(300,90,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(300,125,45,25);
    dc.DrawLabel(wxString::Format(_("m")),wxRect(300,125,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,32,25,195);
    dc.DrawLine(585,32,585,195);
    dc.DrawLine(25,195,585,195);
    dc.DrawLine(25,230,585,230);
    dc.DrawLine(25,230,25,403);
    dc.DrawLine(585,230,585,403);
    dc.DrawLine(25,403,585,403);
    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,108,w-25,108);
    //dc.DrawLine(25,180,w-25,180);
    //dc.DrawLine(25,252,w-25,252);
    //dc.DrawLine(25,384,w-25,384);
}

void MySetupDialog::LayoutKeyArea()
{
    StaticText20->SetPosition(wxPoint(35,25));
    StaticText20->SetLabel(_("关键区域设置"));
    listArea->SetPosition(wxPoint(45,55));
    listArea->SetSize(wxSize(435,190));
    btnAddArea->SetPosition(wxPoint(495,55));
    btnEditArea->SetPosition(wxPoint(495,85));
    btnDelArea->SetPosition(wxPoint(495,115));
    StaticText88->SetPosition(wxPoint(35,303));
    StaticText88->SetLabel(_("提示范围设置"));
    StaticText89->SetPosition(wxPoint(35,338));
    StaticText89->SetLabel(_("关键区域到切口的距离"));
    tip_text->SetPosition(wxPoint(220,333));
    tip_text->SetSize(100,-1);
}

void MySetupDialog::OnPaintKey(wxPaintEvent& event)
{
    wxPaintDC dc(panelKey);
    int w,h;
    panelKey->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.SetBrush(wxBrush(wxColor(219,219,219)));

    dc.DrawLine(25,32,585,32);

    dc.DrawLine(25,32,25,275);
    dc.DrawLine(585,32,585,275);
    dc.DrawLine(25,275,585,275);

    dc.DrawLine(25,310,585,310);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(320,333,45,25);
    dc.DrawLabel(wxString::Format(_("m")),wxRect(320,333,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,310,25,373);
    dc.DrawLine(585,310,585,373);
    dc.DrawLine(25,373,585,373);


    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,108,w-25,108);
    //dc.DrawLine(25,180,w-25,180);
    //dc.DrawLine(25,252,w-25,252);
    //dc.DrawLine(25,384,w-25,384);
}

void MySetupDialog::LayoutDB()
{
    //StaticText85->SetPosition(wxPoint(35,25));
    //StaticText85->SetLabel(_("数据存储管理"));
    //dc.DrawLine(35,57,205,57);
    //StaticText86->SetPosition(wxPoint(35,60));
    //StaticText86->SetLabel(_("数据量备份路径"));
    //db_backuppath_text->SetPosition(wxPoint(180,55));
    //btnDbPath->SetPosition(wxPoint(440,55));
    //StaticText87->SetPosition(wxPoint(35,95));
    //StaticText87->SetLabel(_("报表生成路径"));
    //report_path_text->SetPosition(wxPoint(180,90));
    //btnRtPath->SetPosition(wxPoint(440,90));
    StaticText90->SetPosition(wxPoint(35,25));
    StaticText90->SetLabel(_("远程监控设置"));

    StaticText117->SetPosition(wxPoint(45,66));
    if(mtg->client_type==1)
    {
        StaticText117->SetLabel(_("客户端IP"));
    }
    else
    {
        StaticText117->SetLabel(_("服务器IP"));
    }
    client_ip_text1->SetPosition(wxPoint(120,65));
    client_ip_text1->SetSize(wxSize(40,20));
    StaticText118->SetPosition(wxPoint(160,65));
    client_ip_text2->SetPosition(wxPoint(164,65));
    client_ip_text2->SetSize(wxSize(40,20));
    StaticText119->SetPosition(wxPoint(204,65));
    client_ip_text3->SetPosition(wxPoint(208,65));
    client_ip_text3->SetSize(wxSize(40,20));
    StaticText120->SetPosition(wxPoint(248,65));
    client_ip_text4->SetPosition(wxPoint(252,65));
    client_ip_text4->SetSize(wxSize(40,20));

    StaticText116->SetPosition(wxPoint(45,110));
    StaticText116->SetLabel(_("控制模式"));
    control_checkbox1->SetPosition(wxPoint(120,110));
    control_checkbox2->SetPosition(wxPoint(120,140));
    if(mtg->client_type==1)
    {
        control_checkbox2->SetLabel(_("远程操作模式"));
    }
}

void MySetupDialog::OnPaintDb(wxPaintEvent& event)
{
    wxPaintDC dc(panelDb);
    int w,h;
    panelDb->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.SetBrush(wxBrush(wxColor(219,219,219)));

    dc.DrawLine(25,32,585,32);

    dc.DrawLine(25,180,585,180);
    dc.DrawLine(25,32,25,180);
    dc.DrawLine(585,32,585,180);

    //dc.DrawLine(25,160,585,160);

    dc.DrawLine(118,58,294,58);
    dc.DrawLine(118,87,294,87);
    dc.DrawLine(118,58,118,87);
    dc.DrawLine(294,58,294,87);

    //dc.DrawLine(178,83,354,83);
    //dc.DrawLine(178,112,354,112);
    //dc.DrawLine(178,83,178,112);
    //dc.DrawLine(354,83,354,112);

    //dc.DrawLine(25,263,585,263);
    //dc.DrawLine(25,160,25,263);
    //dc.DrawLine(585,160,585,263);
}

void MySetupDialog::LayoutTar()
{
    StaticText99->SetPosition(wxPoint(35,25));
    StaticText99->SetLabel(_("激光靶参数设置"));
    StaticText18->SetPosition(wxPoint(35,60));
    StaticText18->SetLabel(_("配置文件"));
    tar_file->SetPosition(wxPoint(120,55));
    btnImportPara->SetPosition(wxPoint(320,55));
    btnImportPara->SetLabel(_("导入..."));
    btnImportPara->SetSize(wxSize(80,-1));
    StaticText19->SetPosition(wxPoint(35,95));
    StaticText19->SetLabel(_("棱镜常数"));
    target_prism->SetPosition(wxPoint(120,90));
}

void MySetupDialog::OnPaintPanelTarget(wxPaintEvent& event)
{
    wxPaintDC dc(panelTarget);
    int w,h;
    panelTarget->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.SetBrush(wxBrush(wxColor(219,219,219)));

    dc.DrawLine(25,32,585,32);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(300,90,45,25);
    dc.DrawLabel(wxString::Format(_(" mm ")),wxRect(300,90,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,135,585,135);
    dc.DrawLine(25,32,25,135);
    dc.DrawLine(585,32,585,135);
    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,108,w-25,108);
    //dc.DrawLine(25,180,w-25,180);
    //dc.DrawLine(25,252,w-25,252);
    //dc.DrawLine(25,384,w-25,384);
}

void MySetupDialog::LayoutTheo()
{
    StaticText22->SetPosition(wxPoint(35,25));
    StaticText22->SetLabel(_("激光类型设置"));
    StaticText100->SetPosition(wxPoint(35,60));
    StaticText100->SetLabel(_("激光类型"));
    gus_laser_checkbox->SetPosition(wxPoint(120,60));
    ref_laser_checkbox->SetPosition(wxPoint(220,60));
    user_laser_checkbox->SetPosition(wxPoint(320,60));
    StaticText23->SetPosition(wxPoint(35,90));
    StaticText23->SetLabel(_("激光高度"));
    tps_laserh->SetPosition(wxPoint(120,85));
    tps_laserh->SetSize(wxSize(120,-1));
    StaticText24->SetPosition(wxPoint(35,158));
    StaticText24->SetLabel(_("激光矫正设置"));
    StaticText25->SetPosition(wxPoint(35,193));
    StaticText25->SetLabel(_("矫正距离"));
    tps_laserd->SetPosition(wxPoint(120,188));
    tps_laserd->SetSize(wxSize(120,-1));
    StaticText26->SetPosition(wxPoint(35,228));
    StaticText26->SetLabel(_("水平矫正X"));
    tps_laserx->SetPosition(wxPoint(120,223));
    tps_laserx->SetSize(wxSize(120,-1));
    StaticText27->SetPosition(wxPoint(35,263));
    StaticText27->SetLabel(_("垂直矫正Y"));
    tps_lasery->SetPosition(wxPoint(120,258));
    tps_lasery->SetSize(wxSize(120,-1));
    panelLasercorr->SetSize(320,188,125,95);
}

void MySetupDialog::OnPaintPanelTheo(wxPaintEvent& event)
{
    wxPaintDC dc(panelTheo);
    int w,h;
    panelTheo->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetBrush(wxBrush(wxColor(219,219,219)));

    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,32,585,32);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(240,85,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(240,85,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,130,585,130);
    dc.DrawLine(25,32,25,130);
    dc.DrawLine(585,32,585,130);

    dc.DrawLine(25,165,585,165);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(240,188,45,25);
    dc.DrawLabel(wxString::Format(_("m")),wxRect(240,188,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(240,223,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(240,223,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(240,258,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(240,258,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,298,585,298);
    dc.DrawLine(25,165,25,298);
    dc.DrawLine(585,165,585,298);
    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,108,w-25,108);
    //dc.DrawLine(25,180,w-25,180);
    //dc.DrawLine(25,252,w-25,252);
    //dc.DrawLine(25,384,w-25,384);
}

void MySetupDialog::LayoutOrign()
{
    StaticText32->SetPosition(wxPoint(35,25));
    StaticText32->SetLabel(_("盾构机初始参数设置"));
    StaticText33->SetPosition(wxPoint(45,50));
    StaticText33->SetLabel(_("切口位置(m)"));
    StaticText70->SetPosition(wxPoint(50,80));
    StaticText70->SetLabel(_("X"));
    StaticText71->SetPosition(wxPoint(50,110));
    StaticText71->SetLabel(_("Y"));
    StaticText72->SetPosition(wxPoint(50,140));
    StaticText72->SetLabel(_("Z"));
    headx_text->SetPosition(wxPoint(70,75));
    headx_text->SetSize(wxSize(120,-1));
    heady_text->SetPosition(wxPoint(70,105));
    heady_text->SetSize(wxSize(120,-1));
    headz_text->SetPosition(wxPoint(70,135));
    headz_text->SetSize(wxSize(120,-1));
    StaticText101->SetPosition(wxPoint(225,50));
    StaticText101->SetLabel(_("铰接位置(m)"));
    StaticText102->SetPosition(wxPoint(230,80));
    StaticText102->SetLabel(_("X"));
    StaticText103->SetPosition(wxPoint(230,110));
    StaticText103->SetLabel(_("Y"));
    StaticText104->SetPosition(wxPoint(230,140));
    StaticText104->SetLabel(_("Z"));
    midx_text->SetPosition(wxPoint(250,75));
    midx_text->SetSize(wxSize(120,-1));
    midy_text->SetPosition(wxPoint(250,105));
    midy_text->SetSize(wxSize(120,-1));
    midz_text->SetPosition(wxPoint(250,135));
    midz_text->SetSize(wxSize(120,-1));
    StaticText73->SetPosition(wxPoint(405,50));
    StaticText73->SetLabel(_("盾尾位置(m)"));
    StaticText74->SetPosition(wxPoint(410,80));
    StaticText74->SetLabel(_("X"));
    StaticText75->SetPosition(wxPoint(410,110));
    StaticText75->SetLabel(_("Y"));
    StaticText76->SetPosition(wxPoint(410,140));
    StaticText76->SetLabel(_("Z"));
    tailx_text->SetPosition(wxPoint(430,75));
    tailx_text->SetSize(wxSize(120,-1));
    taily_text->SetPosition(wxPoint(430,105));
    taily_text->SetSize(wxSize(120,-1));
    tailz_text->SetPosition(wxPoint(430,135));
    tailz_text->SetSize(wxSize(120,-1));
    StaticText105->SetPosition(wxPoint(45,178));
    StaticText105->SetLabel(_("转动角(d.ms)"));
    //StaticText34->SetPosition(wxPoint(50,208));
    //StaticText34->SetLabel(_("转动角"));
    StaticText34->Show(false);
    tbmroll_text->SetPosition(wxPoint(70,203));
    tbmroll_text->SetSize(wxSize(120,-1));
    //StaticText106->SetPosition(wxPoint(227,208));
    //StaticText106->SetLabel(_("俯仰角"));
    StaticText106->Show(false);
    //tbm_pitch_text->SetPosition(wxPoint(282,203));
    //tbm_pitch_text->SetSize(wxSize(90,-1));
    tbm_pitch_text->Show(false);
    //StaticText107->SetPosition(wxPoint(404,208));
    //StaticText107->SetLabel(_("方位角"));
    StaticText107->Show(false);
    //tbm_azi_text->SetPosition(wxPoint(459,203));
    //tbm_azi_text->SetSize(wxSize(90,-1));
    tbm_azi_text->Show(false);
    StaticText108->SetPosition(wxPoint(225,178));
    StaticText108->SetLabel(_("铰接油缸行程(mm)"));
    StaticText109->SetPosition(wxPoint(230,208));
    StaticText109->SetLabel(_("上"));
    up_mid_text->SetPosition(wxPoint(250,203));
    up_mid_text->SetSize(wxSize(120,-1));
    StaticText110->SetPosition(wxPoint(230,238));
    StaticText110->SetLabel(_("下"));
    down_mid_text->SetPosition(wxPoint(250,233));
    down_mid_text->SetSize(wxSize(120,-1));
    StaticText111->SetPosition(wxPoint(410,208));
    StaticText111->SetLabel(_("左"));
    left_mid_text->SetPosition(wxPoint(430,203));
    left_mid_text->SetSize(wxSize(120,-1));
    StaticText112->SetPosition(wxPoint(410,238));
    StaticText112->SetLabel(_("右"));
    right_mid_text->SetPosition(wxPoint(430,233));
    right_mid_text->SetSize(wxSize(120,-1));
    StaticText36->SetPosition(wxPoint(35,296));
    StaticText36->SetLabel(_("激光靶初始参数设置"));
    StaticText37->SetPosition(wxPoint(45,321));
    StaticText37->SetLabel(_("激光靶位置(m)"));
    StaticText35->SetPosition(wxPoint(50,351));
    StaticText35->SetLabel(_("X"));
    StaticText38->SetPosition(wxPoint(50,381));
    StaticText38->SetLabel(_("Y"));
    StaticText39->SetPosition(wxPoint(50,411));
    StaticText39->SetLabel(_("Z"));
    tarx_text->SetPosition(wxPoint(70,346));
    tarx_text->SetSize(wxSize(120,-1));
    tary_text->SetPosition(wxPoint(70,376));
    tary_text->SetSize(wxSize(120,-1));
    tarz_text->SetPosition(wxPoint(70,406));
    tarz_text->SetSize(wxSize(120,-1));
    StaticText41->SetPosition(wxPoint(225,321));
    StaticText41->SetLabel(_("激光靶姿态角(d.ms)"));
    StaticText40->SetPosition(wxPoint(230,351));
    StaticText40->SetLabel(_("方位"));
    StaticText61->SetPosition(wxPoint(230,381));
    StaticText61->SetLabel(_("俯仰"));
    StaticText6->SetPosition(wxPoint(230,411));
    StaticText6->SetLabel(_("转动"));
    tarazi_text->SetPosition(wxPoint(270,346));
    tarazi_text->SetSize(wxSize(120,-1));
    tarpitch_text->SetPosition(wxPoint(270,376));
    tarpitch_text->SetSize(wxSize(120,-1));
    tarroll_text->SetPosition(wxPoint(270,406));
    tarroll_text->SetSize(wxSize(120,-1));
    btnTarMeas->SetPosition(wxPoint(495,328));
    btnTarMeas->SetSize(wxSize(75,-1));
    btnTarMeas->SetLabel(_("测 量"));
}

void MySetupDialog::OnPaintPanelOri(wxPaintEvent& event)
{
    wxPaintDC dc(panelOri);
    int w,h;
    panelOri->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.SetBrush(wxBrush(wxColor(245,246,247)));
    dc.DrawLine(25,32,585,32);


    //dc.DrawRectangle(155,75,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(155,75,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(155,105,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(155,105,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(155,135,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(155,135,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    ///切口位置
    dc.DrawLine(35,57,205,57);
    dc.DrawLine(35,165,205,165);
    dc.DrawLine(35,57,35,165);
    dc.DrawLine(205,57,205,165);


    //dc.DrawRectangle(335,75,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(335,75,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(335,105,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(335,105,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(335,135,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(335,135,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    //dc.SetPen(wxPen(wxColor(189,189,189)));
    ///铰接位置
    dc.DrawLine(215,57,385,57);
    dc.DrawLine(215,165,385,165);
    dc.DrawLine(215,57,215,165);
    dc.DrawLine(385,57,385,165);



    //dc.SetPen(wxPen(wxColor(245,246,247)));
    //dc.DrawRectangle(515,75,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(515,75,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(515,105,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(515,105,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(515,135,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(515,135,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    //dc.SetPen(wxPen(wxColor(189,189,189)));
    ///盾尾位置
    dc.DrawLine(395,57,570,57);
    dc.DrawLine(395,165,570,165);
    dc.DrawLine(395,57,395,165);
    dc.DrawLine(570,57,570,165);



    //dc.SetPen(wxPen(wxColor(245,246,247)));
    //dc.DrawRectangle(170,203,35,25);
    //dc.DrawLabel(wxString::Format(_(" ° ")),wxRect(170,203,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(345,203,35,25);
    //dc.DrawLabel(wxString::Format(_(" ° ")),wxRect(345,203,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(520,203,35,25);
    //dc.DrawLabel(wxString::Format(_(" ° ")),wxRect(520,203,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    //dc.SetPen(wxPen(wxColor(189,189,189)));
    ///姿态角
    dc.DrawLine(35,185,205,185);
    dc.DrawLine(35,268,205,268);
    dc.DrawLine(35,185,35,268);
    dc.DrawLine(205,185,205,268);



    //dc.SetPen(wxPen(wxColor(245,246,247)));
    //dc.DrawRectangle(125,266,35,25);
    //dc.DrawLabel(wxString::Format(_("mm")),wxRect(125,266,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(255,266,35,25);
    //dc.DrawLabel(wxString::Format(_("mm")),wxRect(255,266,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(385,266,35,25);
    //dc.DrawLabel(wxString::Format(_("mm")),wxRect(385,266,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(515,266,35,25);
    //dc.DrawLabel(wxString::Format(_("mm")),wxRect(515,266,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    //dc.SetPen(wxPen(wxColor(189,189,189)));
    ///油缸行程
    dc.DrawLine(215,185,570,185);
    dc.DrawLine(215,268,570,268);
    dc.DrawLine(215,185,215,268);
    dc.DrawLine(570,185,570,268);

    dc.DrawLine(25,281,585,281);
    dc.DrawLine(25,32,25,281);
    dc.DrawLine(585,32,585,281);

    //dc.DrawLine(25,220,585,220);

    //dc.DrawLine(25,293,585,293);

    dc.DrawLine(25,303,585,303);
    ///激光靶位置
    dc.DrawLine(35,328,205,328);
    dc.DrawLine(35,436,205,436);
    dc.DrawLine(35,328,35,436);
    dc.DrawLine(205,328,205,436);
    //dc.SetPen(wxPen(wxColor(245,246,247)));
    //dc.DrawRectangle(165,371,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(165,371,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(165,401,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(165,401,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(165,431,35,25);
    //dc.DrawLabel(wxString::Format(_("m")),wxRect(165,431,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    //dc.SetPen(wxPen(wxColor(189,189,189)));

    ///激光靶姿态角
    dc.DrawLine(215,328,405,328);
    dc.DrawLine(215,436,405,436);
    dc.DrawLine(215,328,215,436);
    dc.DrawLine(405,328,405,436);
    //dc.SetPen(wxPen(wxColor(245,246,247)));
    //dc.DrawRectangle(395,371,35,25);
    //dc.DrawLabel(wxString::Format(_("°")),wxRect(395,371,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(395,401,35,25);
    //dc.DrawLabel(wxString::Format(_("°")),wxRect(395,401,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.DrawRectangle(395,431,35,25);
    //dc.DrawLabel(wxString::Format(_("°")),wxRect(395,431,35,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    //dc.SetPen(wxPen(wxColor(189,189,189)));


    dc.DrawLine(25,446,585,446);
    dc.DrawLine(25,303,25,446);
    dc.DrawLine(585,303,585,446);


    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,168,w-25,168);
    //dc.DrawLine(25,270,w-25,270);
    //dc.DrawLine(25,252,w-25,252);
    //dc.DrawLine(25,384,w-25,384);
}

void MySetupDialog::LayoutTBM()
{
    StaticText45->SetPosition(wxPoint(35,25));
    StaticText45->SetLabel(_("盾构机信息"));
    StaticText83->SetPosition(wxPoint(35,60));
    StaticText83->SetLabel(_("盾构机编号"));
    TBM_index->SetPosition(wxPoint(120,55));
    StaticText84->SetPosition(wxPoint(280,60));
    StaticText84->SetLabel(_("盾尾内直径"));
    tail_radius_text->SetPosition(wxPoint(365,55));
    StaticText42->SetPosition(wxPoint(35,113));
    StaticText42->SetLabel(_("推进油缸设置"));
    StaticText93->SetPosition(wxPoint(35,148));
    StaticText93->SetLabel(_("到切口距离"));
    jointDist1->SetPosition(wxPoint(120,143));
    jointDist1->SetSize(wxSize(90,-1));
    StaticText94->SetPosition(wxPoint(280,148));
    StaticText94->SetLabel(_("油缸组直径"));
    jack_radius_text->SetPosition(wxPoint(365,143));
    jack_radius_text->SetSize(wxSize(90,-1));
    StaticText95->SetPosition(wxPoint(35,201));
    StaticText95->SetLabel(_("铰接油缸设置"));
    StaticText96->SetPosition(wxPoint(35,231));
    StaticText96->SetLabel(_("铰接类型"));
    midb_checkbox->SetPosition(wxPoint(120,231));
    midf_checkbox->SetPosition(wxPoint(215,231));
    StaticText97->SetPosition(wxPoint(35,261));
    if(mtg->tbm.type==2)
    {
        StaticText97->SetLabel(_("到切口距离"));
    }
    else
    {
        StaticText97->SetLabel(_("到盾尾距离"));
    }

    jointDist2->SetPosition(wxPoint(120,256));
    jointDist2->SetSize(wxSize(90,-1));
    StaticText98->SetPosition(wxPoint(280,261));
    StaticText98->SetLabel(_("油缸组直径"));
    backjack_radius_text->SetPosition(wxPoint(365,256));
    backjack_radius_text->SetSize(wxSize(90,-1));
    StaticText113->SetPosition(wxPoint(35,314));
    StaticText113->SetLabel(_("铰接油缸行程"));
    //mid_data_checkbox->SetLabel(_("手动设置铰接油缸行程值"));
    mid_data_checkbox->SetPosition(wxPoint(35,344));
    StaticText121->SetPosition(wxPoint(35,374));
    StaticText121->SetLabel(_("上组油缸"));
    StaticText122->SetPosition(wxPoint(280,374));
    StaticText122->SetLabel(_("下组油缸"));
    StaticText123->SetPosition(wxPoint(35,409));
    StaticText123->SetLabel(_("左组油缸"));
    StaticText124->SetPosition(wxPoint(280,409));
    StaticText124->SetLabel(_("右组油缸"));
    mid_value_text1->SetPosition(wxPoint(120,369));
    mid_value_text1->SetSize(wxSize(90,-1));
    mid_value_text2->SetPosition(wxPoint(365,369));
    mid_value_text2->SetSize(wxSize(90,-1));
    mid_value_text3->SetPosition(wxPoint(120,404));
    mid_value_text3->SetSize(wxSize(90,-1));
    mid_value_text4->SetPosition(wxPoint(365,404));
    mid_value_text4->SetSize(wxSize(90,-1));
    jointDist3->Show(false);
    frontjack_radius_text->Show(false);
}

void MySetupDialog::OnPaintPanelTBM(wxPaintEvent& event)
{
    wxPaintDC dc(panelTBM);
    int w,h;
    panelTBM->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.SetBrush(wxBrush(wxColor(219,219,219)));

    dc.DrawLine(25,32,585,32);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(455,55,45,25);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLabel(wxString::Format(_("m")),wxRect(455,55,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.DrawLine(25,32,25,95);
    dc.DrawLine(585,32,585,95);
    dc.DrawLine(25,95,585,95);

    dc.DrawLine(25,120,585,120);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(210,143,45,25);
    dc.DrawLabel(wxString::Format(_("m")),wxRect(210,143,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(455,143,45,25);
    dc.DrawLabel(wxString::Format(_("m")),wxRect(455,143,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,120,25,183);
    dc.DrawLine(585,120,585,183);
    dc.DrawLine(25,183,585,183);

    dc.DrawLine(25,208,585,208);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(210,256,45,25);
    dc.DrawLabel(wxString::Format(_("m")),wxRect(210,256,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(455,256,45,25);
    dc.DrawLabel(wxString::Format(_("m")),wxRect(455,256,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,208,25,296);
    dc.DrawLine(585,208,585,296);
    dc.DrawLine(25,296,585,296);
    //dc.DrawLine(25,170,25,268);
    //dc.DrawLine(300,170,300,268);
    //jointDist1->Show(false);
    //jointDist2->Show(false);
    dc.DrawLine(25,321,585,321);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(210,369,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(210,369,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.DrawRectangle(455,369,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(455,369,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.DrawRectangle(210,404,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(210,404,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.DrawRectangle(455,404,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(455,404,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,321,25,444);
    dc.DrawLine(585,321,585,444);
    dc.DrawLine(25,444,585,444);

    //dc.SetBrush(*wxTRANSPARENT_BRUSH);
    //dc.SetPen(wxPen(wxColor(255,60,20)));
    //dc.DrawCircle(375,280,8);
    //dc.DrawCircle(535,280,8);
    //dc.DrawCircle(455,200,8);
    //dc.DrawCircle(455,360,8);
    //dc.SetPen(wxPen(wxColor(45,45,45)));
    //dc.DrawCircle(455,280,80);
    //dc.DrawLine(397,337,512,222);
    //dc.SetPen(wxPen(wxColor(255,60,20)));
    //dc.DrawLine(387,337,407,337);
    //dc.DrawLine(502,222,522,222);
    //dc.DrawLabel(wxString::Format(_(" R")),wxRect(522,222,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
    /*
    jointDist3->SetPosition(wxPoint(220,333));

    frontjack_radius_text->SetPosition(wxPoint(220,368));*/
    //dc.DrawLine(25,418,585,418);
    //dc.DrawLine(25,175,25,418);
    //dc.DrawLine(585,175,585,418);
    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,108,w-25,108);
    //dc.DrawLine(25,180,w-25,180);
    //dc.DrawLine(25,252,w-25,252);
    //dc.DrawLine(25,384,w-25,384);
}

void MySetupDialog::LayoutMea()
{
    StaticText43->SetPosition(wxPoint(35,25));
    StaticText43->SetLabel(_("测量时间设置"));
    StaticText47->SetPosition(wxPoint(35,60));
    StaticText47->SetLabel(_("姿态测量"));
    measTime1->SetPosition(wxPoint(165,55));
    measTime1->SetSize(wxSize(80,-1));
    StaticText48->SetPosition(wxPoint(310,60));
    StaticText48->SetLabel(_("后视检核"));
    measTime2->SetPosition(wxPoint(440,55));
    measTime2->SetSize(wxSize(80,-1));
    StaticText49->SetPosition(wxPoint(35,108));
    StaticText49->SetLabel(_("警告参数设置"));
    StaticText50->SetPosition(wxPoint(35,143));
    StaticText50->SetLabel(_("平面偏差大于"));
    horiDiff->SetPosition(wxPoint(165,138));
    horiDiff->SetSize(wxSize(80,-1));
    StaticText51->SetPosition(wxPoint(310,143));
    StaticText51->SetLabel(_("垂直偏差大于"));
    verDiff->SetPosition(wxPoint(440,138));
    verDiff->SetSize(wxSize(80,-1));
    StaticText52->SetPosition(wxPoint(35,178));
    StaticText52->SetLabel(_("姿态偏差大于"));
    angleDiff->SetPosition(wxPoint(165,173));
    angleDiff->SetSize(wxSize(80,-1));
    StaticText53->SetPosition(wxPoint(310,178));
    StaticText53->SetLabel(_("偏差变化大于"));
    diffChange->SetPosition(wxPoint(440,173));
    diffChange->SetSize(wxSize(80,-1));
    StaticText54->SetPosition(wxPoint(35,213));
    StaticText54->SetLabel(_("后视位置变化大于"));
    backDiff->SetPosition(wxPoint(165,208));
    backDiff->SetSize(wxSize(80,-1));
    StaticText21->SetPosition(wxPoint(310,213));
    StaticText21->SetLabel(_("测量间隔时间大于"));
    tolTime->SetPosition(wxPoint(440,208));
    tolTime->SetSize(wxSize(80,-1));
    StaticText77->SetPosition(wxPoint(35,260));
    StaticText77->SetLabel(_("纠偏参数设置"));
    StaticText78->SetPosition(wxPoint(35,295));
    StaticText78->SetLabel(_("将盾构姿态纠偏至设计轴线需要掘进的距离"));
    corr_dist_text->SetPosition(wxPoint(360,290));
    corr_dist_text->SetSize(wxSize(100,-1));
    StaticText79->SetPosition(wxPoint(35,330));
    StaticText79->SetLabel(_("盾构掘进一环盾构姿态的最大纠偏偏差"));
    corr_diff_text->SetPosition(wxPoint(360,325));
    corr_diff_text->SetSize(wxSize(100,-1));
}

void MySetupDialog::OnPaintPanelMeas(wxPaintEvent& event)
{
    wxPaintDC dc(panelMeas);
    int w,h;
    panelMeas->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.SetBrush(wxBrush(wxColor(219,219,219)));
    dc.DrawLine(25,32,585,32);

    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(245,55,45,25);
    dc.DrawLabel(wxString::Format(_("秒")),wxRect(245,55,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(520,55,45,25);
    dc.DrawLabel(wxString::Format(_("秒")),wxRect(520,55,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,90,585,90);
    dc.DrawLine(25,32,25,90);
    dc.DrawLine(585,32,585,90);

    dc.DrawLine(25,115,585,115);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(245,138,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(245,138,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(520,138,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(520,138,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(245,173,45,25);
    dc.DrawLabel(wxString::Format(_("mm/m")),wxRect(245,173,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(520,173,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(520,173,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(245,208,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(245,208,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(520,208,45,25);
    dc.DrawLabel(wxString::Format(_("秒")),wxRect(520,208,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,243,585,243);
    dc.DrawLine(25,115,25,243);
    dc.DrawLine(585,115,585,243);

    dc.DrawLine(25,267,585,267);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(460,290,45,25);
    dc.DrawLabel(wxString::Format(_("m")),wxRect(460,290,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(460,325,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(460,325,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,360,585,360);
    dc.DrawLine(25,267,25,360);
    dc.DrawLine(585,267,585,360);

    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,108,w-25,108);
    //dc.DrawLine(25,180,w-25,180);
    //dc.DrawLine(25,243,w-25,243);
    //dc.DrawLine(25,318,w-25,318);
    //dc.DrawLine(25,393,w-25,393);
}

void MySetupDialog::LayoutUser()
{
    StaticText58->SetPosition(wxPoint(35,25));
    StaticText58->SetLabel(_("用户权限设置"));
    listUser->SetPosition(wxPoint(45,55));
    listUser->SetSize(wxSize(436,240));
    btnAddUser->SetPosition(wxPoint(495,55));
    btnEditUser->SetPosition(wxPoint(495,85));
    btnDelUser->SetPosition(wxPoint(495,115));
}

void MySetupDialog::OnPaintPanelUser(wxPaintEvent& event)
{
    wxPaintDC dc(panelUser);
    int w,h;
    panelUser->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(189,189,189)));

    //new_manager_password->Show(false);

    //manager_password_confirm->Show(false);
    //StaticText68->Show(false);
    //StaticText57->Show(false);
    //StaticText5->Show(false);
    //operator_password_confirm->Show(false);
    //new_operator_password->Show(false);
    dc.DrawLine(25,32,585,32);

    dc.DrawLine(25,325,585,325);
    dc.DrawLine(25,32,25,325);
    dc.DrawLine(585,32,585,325);
    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,108,w-25,108);
    //dc.DrawLine(25,180,w-25,180);
    //dc.DrawLine(25,252,w-25,252);
    //dc.DrawLine(25,384,w-25,384);
}

void MySetupDialog::LayoutLang()
{
    StaticText60->Show(false);
    langChoice->Show(false);
    StaticText17->SetPosition(wxPoint(35,25));
    StaticText17->SetLabel(_("语言设置"));
    StaticText55->SetPosition(wxPoint(35,55));
    StaticText55->SetLabel(_("语言选择"));
    lang1_checkbox->SetPosition(wxPoint(120,55));
    lang2_checkbox->SetPosition(wxPoint(217,55));
    lang3_checkbox->SetPosition(wxPoint(290,55));
}

void MySetupDialog::OnPaintPanelLang(wxPaintEvent& event)
{
    wxPaintDC dc(panelLang);
    int w,h;
    panelLang->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));

    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,32,585,32);

    dc.DrawLine(25,80,585,80);
    dc.DrawLine(25,32,25,80);
    dc.DrawLine(585,32,585,80);
    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,108,w-25,108);
    //dc.DrawLine(25,180,w-25,180);
    //dc.DrawLine(25,252,w-25,252);
    //dc.DrawLine(25,384,w-25,384);
}

void MySetupDialog::LayoutSeg()
{
    StaticText28->SetPosition(wxPoint(35,25));
    StaticText28->SetLabel(_("管环参数设置"));
    StaticText29->SetPosition(wxPoint(35,60));
    StaticText29->SetLabel(_("管环宽度"));
    seg_len->SetPosition(wxPoint(140,55));
    seg_len->SetSize(wxSize(100,-1));
    StaticText30->SetPosition(wxPoint(310,60));
    StaticText30->SetLabel(_("管环内直径"));
    seg_r->SetPosition(wxPoint(410,55));
    seg_r->SetSize(wxSize(100,-1));
    StaticText31->SetPosition(wxPoint(35,95));
    StaticText31->SetLabel(_("管环厚度"));
    segThick->SetPosition(wxPoint(140,90));
    segThick->SetSize(wxSize(100,-1));
    StaticText62->SetPosition(wxPoint(310,95));
    StaticText62->SetLabel(_("最小旋转角"));
    segScrow->SetPosition(wxPoint(410,90));
    segScrow->SetSize(wxSize(100,-1));
    StaticText81->SetPosition(wxPoint(35,130));
    StaticText81->SetLabel(_("标准盾尾间隙"));
    std_gap_text->SetPosition(wxPoint(140,125));
    std_gap_text->SetSize(wxSize(100,-1));
    StaticText82->SetPosition(wxPoint(310,130));
    StaticText82->SetLabel(_("最小盾尾间隙"));
    min_gap_text->SetPosition(wxPoint(410,125));
    min_gap_text->SetSize(wxSize(100,-1));
    StaticText63->SetPosition(wxPoint(35,198));
    StaticText63->SetLabel(_("管环拼装设置"));
    StaticText66->SetPosition(wxPoint(35,233));
    StaticText66->SetLabel(_("拼装方式"));
    methodChoice->Show(false);
    WedgeChoice->Show(false);
    seg_method1_checkbox->SetPosition(wxPoint(140,233));
    seg_method2_checkbox->SetPosition(wxPoint(255,233));
    StaticText67->SetPosition(wxPoint(35,258));
    StaticText67->SetLabel(_("楔形类型"));
    seg_wedge1_checkbox->SetPosition(wxPoint(140,258));
    seg_wedge2_checkbox->SetPosition(wxPoint(255,258));
    StaticText65->SetPosition(wxPoint(35,288));
    StaticText65->SetLabel(_("管环楔形量"));
    Wedge_Text->SetPosition(wxPoint(140,283));
    StaticText91->SetPosition(wxPoint(35,346));
    StaticText91->SetLabel(_("管环错缝条件设置"));
    StaticText92->SetPosition(wxPoint(35,381));
    StaticText92->SetLabel(_("错缝角度大于"));
    gapangle_text->SetPosition(wxPoint(140,376));
}

void MySetupDialog::OnPaintPanelSeg(wxPaintEvent& event)
{
    wxPaintDC dc(panelSeg);
    int w,h;
    panelSeg->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.SetBrush(wxBrush(wxColor(219,219,219)));
    dc.DrawLine(25,32,585,32);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(240,55,45,25);
    dc.DrawLabel(wxString::Format(_("m")),wxRect(240,55,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(510,55,45,25);
    dc.DrawLabel(wxString::Format(_("m")),wxRect(510,55,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(240,90,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(240,90,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(510,90,45,25);
    dc.DrawLabel(wxString::Format(_("°")),wxRect(510,90,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(240,125,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(240,125,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    dc.DrawRectangle(510,125,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(510,125,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,170,585,170);
    dc.DrawLine(25,32,25,170);
    dc.DrawLine(585,32,585,170);

    dc.DrawLine(25,205,585,205);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(320,283,45,25);
    dc.DrawLabel(wxString::Format(_("mm")),wxRect(320,283,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,318,585,318);
    dc.DrawLine(25,205,25,318);
    dc.DrawLine(585,205,585,318);

    dc.DrawLine(25,353,585,353);
    dc.SetPen(wxPen(wxColor(219,219,219)));
    dc.DrawRectangle(320,376,45,25);
    dc.DrawLabel(wxString::Format(_("°")),wxRect(320,376,45,25),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    dc.SetPen(wxPen(wxColor(189,189,189)));
    dc.DrawLine(25,411,585,411);
    dc.DrawLine(25,353,25,411);
    dc.DrawLine(585,353,585,411);
    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,108,w-25,108);
    //dc.DrawLine(25,180,w-25,180);
    //dc.DrawLine(25,252,w-25,252);
    //dc.DrawLine(25,384,w-25,384);
}

void MySetupDialog::OnPaintPanelBlock(wxPaintEvent& event)
{
    wxPaintDC dc(panelBlock);
    int w,h;
    panelBlock->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(230,230,230)));
    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,108,w-25,108);
    //dc.DrawLine(25,180,w-25,180);
    //dc.DrawLine(25,252,w-25,252);
    //dc.DrawLine(25,384,w-25,384);
}

void MySetupDialog::OnPaintBtnArea(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnArea);
    int w,h;
    panelBtnArea->GetClientSize(&w,&h);
    ///background
    int *maxPixels,*minPixels;
    maxPixels=(int*)malloc(3*sizeof(int));
    memset(maxPixels,0,3);

    minPixels=(int*)malloc(3*sizeof(int));
    memset(minPixels,0,3);

    wxRect rect(0,0,w,h);

    maxPixels[0]=227;
    maxPixels[1]=227;
    maxPixels[2]=227;

    minPixels[0]=209;
    minPixels[1]=209;
    minPixels[2]=209;

    PaintGradual(panelBtnArea, rect, maxPixels,minPixels,0);

    free(maxPixels);
    free(minPixels);

    dc.SetPen(wxPen(wxColor(248,248,248)));
    dc.DrawLine(0,0,w,0);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetFont(normalFont);
    dc.SetTextForeground(msg_cor);
    dc.DrawLabel(msg_str,wxRect(230,30,0,15),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
}

void MySetupDialog::PaintGradual(wxPanel* panel, wxRect rect, int *maxColorValue,int *minColorValue,int paintStyle)
{
    if(rect.width==0||rect.height==0)
    {
        return;
    }
    else
    {
        wxPaintDC dc(panel);
        int w,h;
        panel->GetClientSize(&w,&h);

        int maxr,maxg,maxb;
        int minr,ming,minb;
        double stepr,stepg,stepb;
        //int signr,signg,signb;

        maxr=maxColorValue[0];
        maxg=maxColorValue[1];
        maxb=maxColorValue[2];

        minr=minColorValue[0];
        ming=minColorValue[1];
        minb=minColorValue[2];

        int x0=rect.x,y0=rect.y;
        int x1=x0+rect.width,y1=y0+rect.height;

        int wb=rect.width;
        int hb=rect.height;


        //btnStartState=3;
        switch(paintStyle)
        {
        case 0:
            if(maxr-minr==0)
            {
                stepr=0.0;

            }
            else
            {
                stepr=(double)(maxr-minr);
                stepr=stepr/hb;
                //wxMessageBox(wxString::Format(_("%f"),stepr));
                //stepr=(double)((maxr-minr)/hb);
            }
            if(maxg-ming==0)
            {
                stepg=0.0;
            }
            else
            {
                stepg=(double)(maxg-ming);
                stepg=stepg/hb;
            }
            if(maxb-minb==0)
            {
                stepb=0.0;
            }
            else
            {
                stepb=(double)(maxb-minb);
                stepb=stepb/hb;
            }
            for(int i=0;i<hb;i++)
            {
                dc.SetPen(wxPen(wxColor(maxr,maxg,maxb)));
                dc.DrawLine(x0,y0+i,x1,y0+i);

                if(abs(stepr)>1)
                {
                    if(maxr-stepr<255&&maxr-stepr>0)
                    {
                        maxr-=stepr;
                    }
                }
                else
                {
                    if(maxr-stepr*i<255&&maxr-stepr*i>0)
                    {
                        maxr=maxColorValue[0]-(int)(stepr*(i+1));
                    }
                }

                if(abs(stepg)>1)
                {
                    if(maxg-stepg<255&&maxg-stepg>0)
                    {
                        maxg-=stepg;
                    }
                }
                else
                {
                    if(maxg-stepg*i<255&&maxg-stepg*i>0)
                    {
                        maxg=maxColorValue[1]-(int)(stepg*(i+1));
                    }
                }

                if(abs(stepb)>1)
                {
                    if(maxb-stepb<255&&maxb-stepb>0)
                    {
                        maxb-=stepb;
                    }
                }
                else
                {
                    if(maxb-stepb*i<255&&maxb-stepb*i>0)
                    {
                        maxb=maxColorValue[2]-(int)(stepb*(i+1));
                    }
                }
            }
            //dc.DrawLabel(name,wxRect(x0,y0,wb,hb),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
            break;
        case 1:
            if(maxr-minr==0)
            {
                stepr=0;
            }
            else
            {
                stepr=(maxr-minr)*2/hb;
            }

            if(maxg-ming==0)
            {
                stepg=0;
            }
            else
            {
                stepg=(maxg-ming)*2/hb;
            }

            if(maxb-minb==0)
            {
                stepb=0;
            }
            else
            {
                stepb=(maxb-minb)*2/hb;
            }

            for(int i=0;i<hb/2;i++)
            {
                dc.SetPen(wxPen(wxColor(maxr,maxg,maxb)));
                dc.DrawLine(x0,y0+i,x1,y0+i);
                if(abs(stepr)>1)
                {
                    if(maxr-stepr<255&&maxr-stepr>0)
                    {
                        maxr-=stepr;
                    }
                }
                else
                {
                    if(maxr-stepr*i<255&&maxr-stepr*i>0)
                    {
                        maxr=maxColorValue[0]-(int)(stepr*(i+1));
                    }
                }

                if(abs(stepg)>1)
                {
                    if(maxg-stepg<255&&maxg-stepg>0)
                    {
                        maxg-=stepg;
                    }
                }
                else
                {
                    if(maxg-stepg*i<255&&maxg-stepg*i>0)
                    {
                        maxg=maxColorValue[1]-(int)(stepg*(i+1));
                    }
                }

                if(abs(stepb)>1)
                {
                    if(maxb-stepb<255&&maxb-stepb>0)
                    {
                        maxb-=stepb;
                    }
                }
                else
                {
                    if(maxb-stepb*i<255&&maxb-stepb*i>0)
                    {
                        maxb=maxColorValue[2]-(int)(stepb*(i+1));
                    }
                }
            }

            maxColorValue[0]=maxr;
            maxColorValue[1]=maxg;
            maxColorValue[2]=maxb;
            for(int i=hb/2;i<hb;i++)
            {
                dc.SetPen(wxPen(wxColor(maxr,maxg,maxb)));
                dc.DrawLine(x0,y0+i,x1,y0+i);
                if(abs(stepr)>1)
                {
                    if(maxr-stepr<255&&maxr-stepr>0)
                    {
                        maxr+=stepr;
                    }
                }
                else
                {
                    if(maxr-stepr*i<255&&maxr-stepr*i>0)
                    {
                        maxr=maxColorValue[0]+stepr*(i-hb/2);
                    }
                }

                if(abs(stepg)>1)
                {
                    if(maxg-stepg<255&&maxg-stepg>0)
                    {
                        maxg+=stepg;
                    }
                }
                else
                {
                    if(maxg-stepg*i<255&&maxg-stepg*i>0)
                    {
                        maxg=maxColorValue[1]+stepg*(i-hb/2);
                    }
                }

                if(abs(stepb)>1)
                {
                    if(maxb-stepb<255&&maxb-stepb>0)
                    {
                        maxb+=stepb;
                    }
                }
                else
                {
                    if(maxb-stepb*i<255&&maxb-stepb*i>0)
                    {
                        maxb=maxColorValue[2]+stepb*(i-hb/2);
                    }
                }
            }
            break;
        default:
            break;
        }
    }
}

void MySetupDialog::CalHead()
{
    double x1,y1,z1,x2,y2,z2;
    double d1,d2,d3;
    double rj = mtg->tbm.D[3];
    double azi,pitch,dazi,dpitch;
    double dx,dy,dz;
    double midj[4];
    double mid[3];
    //FILE* fp = fopen("D:\\calhead.log","w");

    midx_text->GetValue().ToDouble(&x1);
    midy_text->GetValue().ToDouble(&y1);
    midz_text->GetValue().ToDouble(&z1);
    tailx_text->GetValue().ToDouble(&x2);
    taily_text->GetValue().ToDouble(&y2);
    tailz_text->GetValue().ToDouble(&z2);

    up_mid_text->GetValue().ToDouble(&midj[0]);
    down_mid_text->GetValue().ToDouble(&midj[1]);
    left_mid_text->GetValue().ToDouble(&midj[2]);
    right_mid_text->GetValue().ToDouble(&midj[3]);
    backjack_radius_text->GetValue().ToDouble(&rj);

    midx_text->GetValue().ToDouble(&mid[0]);
    midy_text->GetValue().ToDouble(&mid[1]);
    midz_text->GetValue().ToDouble(&mid[2]);

    midj[0] = midj[0]/1000.0;
    midj[1] = midj[1]/1000.0;
    midj[2] = midj[2]/1000.0;
    midj[3] = midj[3]/1000.0;

    d3 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    if(d3 > 0.0)
    {
        azi = atan2((y1-y2),(x1-x2));
        if(azi<0.0) azi = azi+2.0*PI;
        pitch = atan((z1-z2)/d3);
        jointDist2->GetValue().ToDouble(&d3);

        d1 = midj[2]-midj[3];
        d2 = midj[1]-midj[0];
        dazi = atan(d1/rj);
        dpitch = atan(d2/rj);

        d1 = (midj[0]+midj[1]+midj[2]+midj[3])/4.0;
        d1 = fabs(d1*cos(pitch+dpitch));
        x1 = mid[0]+d1*cos(azi+dazi);
        y1 = mid[1]+d1*sin(azi+dazi);
        z1 = mid[2]+d1*tan(pitch+dpitch);
        d3 = fabs(d3*cos(pitch+dpitch));
        x1 = x1+d3*cos(azi+dazi);
        y1 = y1+d3*sin(azi+dazi);
        z1 = z1+d3*tan(pitch+dpitch);

        //fprintf(fp,"%.12f,%.4f,%.4f,%.4f,%.12f,%.12f\n",azi,d3,d1,d2,dazi,dpitch);

        //fprintf(fp,"%.4f,%.4f,%.4f\n",x1,y1,z1);
        headx_text->SetValue(wxString::Format(_("%.4f"),x1));
        heady_text->SetValue(wxString::Format(_("%.4f"),y1));
        headz_text->SetValue(wxString::Format(_("%.4f"),z1));
        //fprintf(fp,"%.4f,%.4f,%.4f\n",x1,y1,z1);
        //tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
        //tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
    }
    else
    {
        headx_text->SetValue(wxString::Format(_("%.4f"),0));
        heady_text->SetValue(wxString::Format(_("%.4f"),0));
        headz_text->SetValue(wxString::Format(_("%.4f"),0));
    }
    //fclose(fp);
}

void MySetupDialog::CalTail()
{
    double x1,y1,z1,x2,y2,z2;
    double d1,d2,d3;
    double rj;
    double azi,pitch,dazi,dpitch;
    double dx,dy,dz;

    double midj[4];
    double mid[3];
    //FILE* fp = fopen("D:\\CalTail.log","w");

    up_mid_text->GetValue().ToDouble(&midj[0]);
    down_mid_text->GetValue().ToDouble(&midj[1]);
    left_mid_text->GetValue().ToDouble(&midj[2]);
    right_mid_text->GetValue().ToDouble(&midj[3]);

    //fprintf(fp,"%.4f,%.4f,%.4f,%.4f\n",midj[0],midj[1],midj[2],midj[3]);
    midx_text->GetValue().ToDouble(&mid[0]);
    midy_text->GetValue().ToDouble(&mid[1]);
    midz_text->GetValue().ToDouble(&mid[2]);
    backjack_radius_text->GetValue().ToDouble(&rj);
    //fprintf(fp,"%.4f,%.4f,%.4f\n",mid[0],mid[1],mid[2]);
    midj[0] = midj[0]/1000.0;
    midj[1] = midj[1]/1000.0;
    midj[2] = midj[2]/1000.0;
    midj[3] = midj[3]/1000.0;

    headx_text->GetValue().ToDouble(&x1);
    heady_text->GetValue().ToDouble(&y1);
    headz_text->GetValue().ToDouble(&z1);
    x2 = mid[0];
    y2 = mid[1];
    z2 = mid[2];

    d3 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(d3 > 0.0)
    {
        azi = atan2((y1-y2),(x1-x2));
        if(azi<0.0) azi = azi+2.0*PI;
        pitch = atan((z1-z2)/d3);
        pitch = -pitch;
        jointDist2->GetValue().ToDouble(&d3);
        d1 = midj[2]-midj[3];
        d2 = midj[1]-midj[0];
        dazi = atan(d1/rj);
        dpitch = atan(d2/rj);
        //fprintf(fp,"%.12f,%.12f\n",azi,pitch);
        //fprintf(fp,"%.12f,%.12f\n",dazi,dpitch);
        d1 = (midj[0]+midj[1]+midj[2]+midj[3])/4.0;
        d1 = fabs(d1*cos(pitch-dpitch));
        //fprintf(fp,"%.4f\n",d1);
        x1 = mid[0]+d1*cos(azi+PI-dazi);
        y1 = mid[1]+d1*sin(azi+PI-dazi);
        z1 = mid[2]+d1*tan(pitch-dpitch);
        d3 = fabs(d3*cos(pitch-dpitch));
        //fprintf(fp,"%.4f\n",d3);
        //fprintf(fp,"%.4f\n",z1);
        x1 = x1+d3*cos(azi+PI-dazi);
        y1 = y1+d3*sin(azi+PI-dazi);
        z1 = z1+d3*tan(pitch-dpitch);
        //fprintf(fp,"%.4f\n",d3*tan(pitch-dpitch));
        tailx_text->SetValue(wxString::Format(_("%.4f"),x1));
        taily_text->SetValue(wxString::Format(_("%.4f"),y1));
        tailz_text->SetValue(wxString::Format(_("%.4f"),z1));
        //fprintf(fp,"%.4f,%.4f,%.4f\n",mtg->m0.mid[0]+dx,mtg->m0.mid[1]+dy,mtg->m0.mid[2]+dz);
        //tbm_pitch_text->SetValue(wxString::Format(_("%.4f"),0.0));
        //tbm_azi_text->SetValue(wxString::Format(_("%.4f"),0.0));
    }
    else
    {
        tailx_text->SetValue(wxString::Format(_("%.4f"),0));
        taily_text->SetValue(wxString::Format(_("%.4f"),0));
        tailz_text->SetValue(wxString::Format(_("%.4f"),0));
    }
    //fclose(fp);
}

