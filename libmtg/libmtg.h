#ifndef LIBMTG_H_INCLUDED
#define LIBMTG_H_INCLUDED

#include "road.h"
#include "stream.h"
#include "cam.h"
#include "libtps.h"
#include "inc.h"

#ifdef WIN32
#ifdef LIBMTG_MAKINGDLL
#define LIBMTG_API __declspec(dllexport)
#else
#define LIBMTG_API __declspec(dllimport)
#endif
#else
#define LIBMTG_API
#endif

#define MTG_OPERA_NONE      0
#define MTG_OPERA_CYCLE     1  ///粗测
#define MTG_OPERA_CHECK     2
#define MTG_OPERA_TRAVERSE  3  ///精测
#define MTG_OPERA_SETUP     4
#define MTG_OPERA_MEASURE   5

#define MAX_CLI   32    ///用户数目
#define MAX_SEG   40

#define DIST_CMD_NONE       0
#define DIST_CMD_TBM        1
#define DIST_CMD_SEG        2

#ifdef __cplusplus
extern "C"
{
#endif

enum
{
    MTG_LOG_BEGIN_TARGET_BACKSIGHT,
    MTG_LOG_BEGIN_TARGET_PRISM,
    MTG_LOG_BEGIN_STOP_LASER,
    MTG_LOG_BEGIN_FINEADJUST_BACKSIGHT,
    MTG_LOG_BEGIN_MEASURE_BACKSIGHT,
    MTG_LOG_BEGIN_FINEADJUST_PRISM,
    MTG_LOG_BEGIN_MEASURE_PRISM,
    MTG_LOG_BEGIN_TARGET_LASERUNIT,
    MTG_LOG_BEGIN_MEASURE_ANGLE,
    MTG_LOG_BEGIN_START_LASER,
    MTG_LOG_BEGIN_CONNECT_TPS,
    MTG_LOG_BEGIN_CONNECT_INCLINE,
    MTG_LOG_BEGIN_CONNECT_CAMERA,
    MTG_LOG_BEGIN_TARGET_BASKET,
    MTG_LOG_BEGIN_FINEADJUST_BASKET,
    MTG_LOG_BEGIN_MEASURE_BASKET,
    MTG_LOG_BEGIN_TARGET_SEGMENT,
    MTG_LOG_BEGIN_MEASURE_SEGMENT,
    MTG_LOG_BEGIN_FINEADJUST_SEGMENT,
    MTG_LOG_BEGIN_TARGET_RPISM,
    MTG_LOG_BEGIN_ERECT,
    MTG_LOG_BEGIN_DIST_CONNECT,
    MTG_LOG_BEGIN_DIST_TBM,
    MTG_LOG_BEGIN_DIST_SEG,
    MTG_LOG_BEGIN_COUNT,
    MTG_LOG_BEGIN_GET_TEMPERATURE,
    MTG_LOG_BEGIN_SET_TEMPERATURE,
    MTG_LOG_BEGIN_GET_ANGLE,

    MTG_LOG_FINISH_TARGET_BACKSIGHT,
    MTG_LOG_FINISH_TARGET_PRISM,
    MTG_LOG_FINISH_STOP_LASER,
    MTG_LOG_FINISH_FINEADJUST_BACKSIGHT,
    MTG_LOG_FINISH_MEASURE_BACKSIGHT,
    MTG_LOG_FINISH_FINEADJUST_PRISM,
    MTG_LOG_FINISH_MEASURE_PRISM,
    MTG_LOG_FINISH_TARGET_LASERUNIT,
    MTG_LOG_FINISH_MEASURE_ANGLE,
    MTG_LOG_FINISH_START_LASER,
    MTG_LOG_FINISH_CONNECT_TPS,
    MTG_LOG_FINISH_CONNECT_INCLINE,
    MTG_LOG_FINISH_CONNECT_CAMERA,
    MTG_LOG_FINISH_TARGET_BASKET,
    MTG_LOG_FINISH_FINEADJUST_BASKET,
    MTG_LOG_FINISH_MEASURE_BASKET,
    MTG_LOG_FINISH_TARGET_SEGMENT,
    MTG_LOG_FINISH_MEASURE_SEGMENT,
    MTG_LOG_FINISHFINEADJUST_SEGMENT,
    MTG_LOG_FINISH_COMP_ON,
    MTG_LOG_FINISH_COMP_OFF,
    MTG_LOG_FINISH_SET_STATION,
    MTG_LOG_FINISH_SET_PRISM_HEIGHT,
    MTG_LOG_FINISH_SET_ORIENTATION,
    MTG_LOG_FINISH_STORE_STATION,
    MTG_LOG_FINISH_ORIGIN,
    MTG_LOG_FINISH_CYCLE,
    MTG_LOG_FINISH_STORE_MEASURE,
    MTG_LOG_FINISH_STUDY,
    MTG_LOG_FINISH_MEASURE_RPISM,
    MTG_LOG_FINISH_SETMEASURE_BASKET,
    MTG_LOG_FINISH_GESTURE_CHECK,
    //MTG_LOG_FINISH_DIST_CONNECT,
    MTG_LOG_FINISH_DIST_CONNECT,
    MTG_LOG_FINISH_DIST_ADDRESS_READ,
    MTG_LOG_FINISH_DIST_ADDRESS_WRITE,
    MTG_LOG_FINISH_DIST_TBM,
    MTG_LOG_FINISH_DIST_SEG,
    MTG_LOG_FINISH_COUNT,
    MTG_LOG_FINISH_GET_TEMPERATURE,
    MTG_LOG_FINISH_SET_TEMPERATURE,
    MTG_LOG_FINISH_GET_ANGLE,
    MTG_LOG_FINISH_GET_INCLINE,
    MTG_LOG_FINISH_GET_LOG,
    MTG_LOG_FINISH_STORE_ORIGIN_SEG,
    MTG_LOG_FINISH_STORE_AJ_MEASURE,
    MTG_LOG_FINISH_RESET_ORIGIN_SEG,
    MTG_LOG_FINISH_STORE_PDMAX,
    MTG_LOG_FINISH_AJ_CYCLE,
    MTG_LOG_START_ORIGIN_SEG_CYCLE,
    MTG_LOG_FINISH_UPDATE_AJ_MEASURE,
    MTG_LOG_FINISH_GET_SPECKLE,

    MTG_LOG_FAIL_TARGET_BACKSIGHT,
    MTG_LOG_FAIL_TARGET_PRISM,
    MTG_LOG_FAIL_STOP_LASER,
    MTG_LOG_FAIL_FINEADJUST_BACKSIGHT,
    MTG_LOG_FAIL_MEASURE_BACKSIGHT,
    MTG_LOG_FAIL_FINEADJUST_PRISM,
    MTG_LOG_FAIL_MEASURE_PRISM,
    MTG_LOG_FAIL_TARGET_LASERUNIT,
    MTG_LOG_FAIL_MEASURE_ANGLE,
    MTG_LOG_FAIL_START_LASER,
    MTG_LOG_FAIL_CONNECT_TPS,
    MTG_LOG_FAIL_CONNECT_INCLINE,
    MTG_LOG_FAIL_CONNECT_CAMERA,
    MTG_LOG_FAIL_TARGET_BASKET,
    MTG_LOG_FAIL_FINEADJUST_BASKET,
    MTG_LOG_FAIL_MEASURE_BASKET,
    MTG_LOG_FAIL_TARGET_SEGMENT,
    MTG_LOG_FAIL_MEASURE_SEGMENT,
    MTG_LOG_FAIL_FINEADJUST_SEGMENT,
    MTG_LOG_FAIL_COMP_ON,
    MTG_LOG_FAIL_COMP_OFF,
    MTG_LOG_FAIL_SET_STATION,
    MTG_LOG_FAIL_SET_PRISM_HEIGHT,
    MTG_LOG_FAIL_SET_ORIENTATION,
    MTG_LOG_FAIL_STORE_STATION,
    MTG_LOG_FAIL_ORIGIN,
    MTG_LOG_CANCEL_CYCLE,
    MTG_LOG_FAIL_STORE_MEASURE,
    MTG_LOG_FAIL_TARGET_RPISM,
    MTG_LOG_FAIL_GESTURE_CHECK,
    MTG_LOG_ERROR_STUDY,
    MTG_LOG_FAIL_DIST_CONNECT,
    MTG_LOG_FAIL_DIST_ADDRESS_READ,
    MTG_LOG_FAIL_DIST_ADDRESS_WRITE,
    MTG_LOG_FAIL_DIST_TBM,
    MTG_LOG_FAIL_DIST_SEG,
    MTG_LOG_FAIL_GET_TEMPERATURE,
    MTG_LOG_FAIL_SET_TEMPERATURE,
    MTG_LOG_FAIL_GET_ANGLE,
    MTG_LOG_FAIL_CONNECT_INCLINE1,
    MTG_LOG_FAIL_CONNECT_INCLINE2,
    MTG_LOG_INC_OUT,
    MTG_LOG_FAIL_GET_INCLINE,
    MTG_LOG_FAIL_STORE_ORIGIN_SEG,
    MTG_LOG_FAIL_ORIGIN_SEG,
    MTG_LOG_FAIL_RESET_ORIGIN_SEG,
    MTG_LOG_FAIL_STORE_PDMAX,
    MTG_LOG_FAIL_AJ_CYCLE,
    MTG_LOG_FAIL_STORE_AJ_MEASURE,
    MTG_LOG_FAIL_UPDATE_AJ_MEASURE,
    MTG_LOG_FAIL_GET_IMAGE,
    MTG_LOG_FAIL_GET_SPECKLE,
    MTG_LOG_FAIL_GET_INCLINE1,
    MTG_LOG_FAIL_GET_INCLINE2,

    MTG_LOG_ERROR_SENSE,
    MTG_LOG_ERROR_COMP,

    MTG_LOG_END_CYCLE,
    MTG_LOG_START_CYCLE,
    MTG_LOG_IS_RUNNING,
    MTG_LOG_ALL_READY,
    MTG_LOG_COMP_UPDATE,
    MTG_LOG_POWER_UPDATE,
    MTG_LOG_NOT_RUNNING,
    MTG_LOG_AJ_IS_RUNNING,
    MTG_LOG_AJ_NOT_RUNNING,

    MTG_LOG_CAMERA_READY,
    MTG_LOG_CAMERA_FAIL,
    MTG_LOG_NO_PRISM_POSITION,//20180110whq增加
    MTG_LOG_ERROR_SIZE,
    MTG_LOG_BACKSIGHT_OVER_LIMIT,
    MTG_LOG_BEGIN_CONNECT_INCA,
    MTG_LOG_CONNECT_INCA_FINSH,
    MTG_LOG_CONNECT_INCA_FAIL,
    ///count
    MTG_LOG_COUNT
};

enum
{
    read_plc_start_val,
    read_plc_mode_val,

    read_plc_aj_a,
    read_plc_aj_b,
    read_plc_aj_c,
    read_plc_aj_d,
    read_plc_aj_e,
    read_plc_aj_f,

    read_plc_fj_a,
    read_plc_fj_b,
    read_plc_fj_c,
    read_plc_fj_d,

    read_plc_bj_a,
    read_plc_bj_b,
    read_plc_bj_c,
    read_plc_bj_d,

    read_plc_usaj_val,
    read_plc_dsaj_val,
    read_plc_lsaj_val,
    read_plc_rsaj_val,

    write_plc_pitch1_val,
    write_plc_roll1_val,
    write_plc_pitch2_val,
    write_plc_roll2_val,

    write_plc_mile1_val,
    write_plc_mile2_val,
    write_plc_mile3_val,

    write_plc_headh_val,
    write_plc_headv_val,
    write_plc_tailh_val,
    write_plc_tailv_val,
    write_plc_midh_val,
    write_plc_midv_val,

    write_plc_direct1_val,
    write_plc_direct2_val,
    write_plc_direct3_val,
    write_plc_direct4_val,

    write_plc_headx_val,
    write_plc_heady_val,
    write_plc_headz_val,
    write_plc_midy_val,
    write_plc_midx_val,
    write_plc_midz_val,
    write_plc_tailx_val,
    write_plc_taily_val,
    write_plc_tailz_val,

    write_plc_segmile1_val,
    write_plc_segmile2_val,
    write_plc_segmile3_val,
    write_plc_segh_val,
    write_plc_segv_val,
    write_plc_segy_val,
    write_plc_segx_val,
    write_plc_segz_val,
    write_plc_segk_val,

    write_plc_ugap_val,
    write_plc_rgap_val,
    write_plc_dgap_val,
    write_plc_lgap_val,
    write_plc_numb1_val,

    write_plc_len1_val,
    write_plc_len2_val,
    write_plc_len3_val,

    write_plc_mile4_val,
    write_plc_mile5_val,
    write_plc_mile6_val,

    write_plc_slum1_val,
    write_plc_slum2_val,
    write_plc_slum3_val,
    write_plc_slum4_val,
    write_plc_slum5_val,

    write_plc_numb2_val,
    write_plc_numb3_val,
    write_plc_type1_val,
    write_plc_type2_val,
    write_plc_kpos1_val,
    write_plc_kpos2_val,
    write_plc_kpos3_val,
    write_plc_kpos4_val,
    write_plc_slum_val,

    Mit_write_plc_direct1_val,
    Mit_write_plc_direct2_val,
    Mit_write_plc_midh_val,
    Mit_write_plc_midv_val,
    Mit_write_plc_seg_val,
    Mit_write_plc_mile1_val,
    Mit_write_plc_mile2_val,
    Mit_write_plc_mile3_val,
    Mit_write_plc_headh_val,
    Mit_write_plc_headv_val,
    Mit_write_plc_tailh_val,
    Mit_write_plc_tailv_val,
    Mit_write_plc_roll_val,
    Mit_write_plc_pitch_val,
    Mit_write_plc_seg_part_val,
    Mit_write_plc_seg_part2_val,    //掘进距离下部
    Mit_write_plc_azimuth1_val,    //方位角上部
    Mit_write_plc_azimuth2_val,    //方位角下部
    Mit_write_plc_azimuth3_val,     //设计方位角上部
    Mit_write_plc_azimuth4_val,     //设计方位角下部

    plc_count
};

enum    ///施耐德plc
{
    read_plc_aj_a1,
    read_plc_aj_b1,
    read_plc_aj_c1,
    read_plc_aj_d1,
    read_plc_status_amode,    //0停止  1推进   2换步
    read_plc_status_drive,    //0停止  1推进   2换步

    write_plc_roll_val,
    write_plc_pitch_val,
    write_plc_head_mile,
    write_plc_seg_num,
    write_plc_head_hoff,
    write_plc_mid_hoff,
    write_plc_tail_hoff,
    write_plc_head_voff,
    write_plc_mid_voff,
    write_plc_tail_voff,
    write_plc_fore_directh,
    write_plc_fore_directv,
    write_plc_back_directh,
    write_plc_back_directv,
    plc_count1
};

#define MTG_THREAD_CYCLE             0
#define MTG_THREAD_ORIGIN            1
#define MTG_THREAD_CONNECT           2
#define MTG_THREAD_BACKCHECK         3
#define MTG_THREAD_PRISMCHECK        4
#define MTG_THREAD_MEASUREBACK       5
#define MTG_THREAD_SETUP             6
#define MTG_THREAD_BASKET            7
#define MTG_THREAD_MEASUREPRISM      8
#define MTG_THREAD_GETCOMP           9
#define MTG_THREAD_GETPOWER          10
#define MTG_THREAD_POSITION_BACK      11
#define MTG_THREAD_POSITION_PRISM     12
#define MTG_THREAD_RE_SETUP           13
#define MTG_THREAD_SET_LASER          14
#define MTG_THREAD_SET_EDM            15
#define MTG_THREAD_SET_COMP           16
#define MTG_THREAD_MP                 17
#define MTG_THREAD_SIM                18
//
#define MTG_THREAD_START_LASER        19
#define MTG_THREAD_CLOSE_LASER        20
#define MTG_THREAD_GET_TEMPERATURE    21
#define MTG_THREAD_SET_TEMPERATURE    22
/******ָ*********/

typedef struct MTG_PRJ
{
	char name[64];       ///项目名称
	double mile1;        ///起点里程
	double mile2;        ///终点里程
	int a2z;             ///掘进方向,1正向-1反向
	int htip;            ///平曲线提示
	int vtip;            ///竖曲线提示
	double tip;          ///关键区域提示范围
}MTG_PRJ;

typedef struct layer_t
{
    int n;                     ///地层数
    double x1[16];             ///左边界
    double y1[16];             ///左边界
    double x2[16];             ///右边界
    double y2[16];             ///右边界
    double sign[30];           ///图例编号0不包含1包含
    double mile1;              ///起点
    double mile2;              ///终点
}layer_t;

typedef struct MTG_COM ///
{
    int id;                    ///1-camera1 2-camera2 3-inclinometer 4-tps
    char ip[16];               ///IP
    int port;                  ///
}MTG_COM;

typedef struct MTG_TBM_PLC ///
{
    BOOL drive;           ///掘进开始
    BOOL amode;           ///拼装模式
    double uaj;           ///推进油缸行程上
    double daj;           ///推进油缸行程下
    double laj;           ///推进油缸行程左
    double raj;           ///推进油缸行程右
    double ufaj;          ///盾首铰接油缸上
    double dfaj;          ///盾首铰接油缸下
    double lfaj;          ///盾首铰接油缸左
    double rfaj;          ///盾首铰接油缸右
    double ubaj;          ///盾尾铰接油缸上
    double dbaj;          ///盾尾铰接油缸下
    double lbaj;          ///盾尾铰接油缸左
    double rbaj;          ///盾尾铰接油缸右
    double uvaj;          ///刀盘位移油缸上
    double dvaj;          ///刀盘位移油缸下
    double lvaj;          ///刀盘位移油缸左
    double rvaj;          ///刀盘位移油缸右
}MTG_TBM_PLC;

typedef struct MTG_SETS
{
    int cyc;                   ///测量周期
    int bcyc;                  ///后视检核周期
    int palw;                  ///偏差限差
    int jalw;                  ///偏差变化限差
    int balw;                  ///后视限差
    int talw;                  ///时间限差
    double aalw;                  ///转动角限差
    int vibration;             ///0正常震动环境1大幅震动环境
    int rstn;                  ///后视超限重新定向,0常规1重新定向
    int tsyn;                  ///0盾构掘进停止停止1盾构掘进停止继续测量
    int rget;                  ///环号计算方式0 PLC状态 1里程近似 2综合严密
    int idrv;                  ///显示纠偏信息0不显示1显示
    int prun;                  ///周期测量运行
    int pend;                  ///停止运行
    int psas;                  ///管环选型功能保护
    int pchk;                  ///系统检核功能保护
    int pqry;                  ///查询功能保护
    int pmap;                  ///地图功能保护
    int psmr;                  ///管环监测功能保护
    int pquit;                 ///退出系统

    int unit;                  ///角度单位
    int vmileage;              ///0设计里程1实际里程
    int head;                  ///前端显示，0切口1刀盘
    int tbm3d;                 ///姿态显示 0为3D，1为2D
    int trend;                 ///0以轴线为基准1以切口点切线为基准

    int povr;                  ///偏差超限
    int jovr;                  ///姿态跳变
    int tovr;                  ///时间间隔超限
    int bovr;                  ///后视检核超限
    int toEr;                  ///将警示信息设为错误信息

    double flen;               ///纠偏距离
    double fdev;               ///纠偏限差

    int tgap;                  ///盾尾间隙系统

    int lang;                  ///语言
    int symtype;                ///铰接是否对称，0表示不对称，1表示对称（即左上左下右上右下）,2表示主动铰接三个铰接
    int backflag;               ///是否后视检核 ,0表示不进行  1表示进行
    int plctype;                ///plc类型，0表示opc   1表示web

    int tailapply;               ///盾尾铰接模式显示盾尾偏航数据，0显示 1不显示
}MTG_SETS;

typedef struct MTG_SEGMONITOR   ///
{
    int number;                  ///监测的管环编号
    int monitor;                 ///0无监测1监测
    int cycle;                   ///监测周期
    int last;                    ///持续监测环数
    int iseg;                    ///本次测量的管环编号
    double headc;
    double x0,y0,z0;             ///初始值
    double x,y,z;                ///坐标
    double dv;                   ///相对于上次沉降
    double dv1;                  ///累计沉降
    time_t t;                    ///时间
}MTG_SEGMONITOR;

typedef struct MTG_MP
{
    double head[6];           ///
    double tail[6];           ///
    double prism[18];         ///
    double inc[6];            ///
    double headc;             ///
    double headh;             ///水平偏差
    double headv;             ///垂直偏差
    double headh1;            ///激光：水平偏差
    double headv1;            ///激光：垂直偏差
    double tailc;             ///盾尾里程
    double tailh;             ///水平偏差
    double tailv;             ///垂直偏差
    double tailh1;            ///激光：水平偏差
    double tailv1;            ///激光：垂直偏差
    double pdev[3];
    time_t t;
}MTG_MP;

typedef struct MTG_CAM   ///
{
    int w;                ///照片宽度
    int h;                ///照片高度
    double affine[9];     ///校正参数（共9个点）
	char name[64];        ///相机名
	int x1;
	int y1;
	int x2;
	int y2;
}MTG_CAM;

typedef struct MTG_MAP   ///
{
    int w[5];                ///地图宽度
    int h[5];                ///地图高度
    double dx[5];            ///平移参数
    double dy[5];            ///平移参数
    double s[5];             ///缩放因子
    double beta;             ///旋转角度
	char name[64];           ///相机名
}MTG_MAP;

typedef struct MTG_TARGET
{
    int ver;                  ///0 MLT01(3代） 1 MLT01（4代） 2 MLT01(5代）
	double prism[12];         ///棱镜相对于前屏孔中心坐标
	double prc;               ///棱镜常数
	double length;            ///前屏与后屏的距离
	int cam;                  ///0 大恒相机，1 baumer相机
	int inc;                  ///倾斜仪类型 0为瑞芬倾斜仪1为NS-15倾斜仪20130702,2为726s倾斜仪
	int ipos;                 ///0正下方1左侧2上侧3右侧
	int pos;                  ///0安装于前盾1安装于中盾
	int incdb;                ///两个倾斜仪标记，0表示一个倾斜仪，1表示两个倾斜仪
	int ctsalw;              ///连续超限次数
	int dtsalw;              ///一天的超限次数
	int stopped;                   ///倾斜仪超限过多时是否停用，1表示停用，0表示不停用
	double angalw;             ///角度超限阈值
	int baseinc;             ///倾斜仪使用1号还是2号，0表示1号,2表示2号
}MTG_TARGET;

typedef struct MTG_BLOCK
{
	char name[64];       ///名字
	double angle ;    ///圆心角
}MTG_BLOCK;

///关键区域
typedef struct MTG_KEY
{
	char name[64];        ///区域名字
	double mile1;         ///区域起点里程
	double mile2;         ///区域终点里程
	//double tip;           ///提示范围
}MTG_KEY;

typedef struct
{
    int id;
    char name[64];
    double mile1;
    double mile2;
    int seg1;
    int seg2;
    time_t t1;
    time_t t2;
    double mxdev;           ///最大偏差
}MTG_DUTY;

typedef struct MTG_SEGSET
{
	int type;             ///0通用环,1:2+1,2通缝拼装（标准环）
	int in;               ///0错缝1通缝
	int f2b;              ///0等腰梯形，1前梯形，2后梯形
	double l2s;           ///管环楔形量
	double L;             ///管环长度
	double De;            ///管环外径
	double D;             ///管环内径
    double Dn;            ///管环公称直径
    int Ks;               ///K块拼装点位数量
    double G1;            ///盾尾最小间隙
    double G0;            ///标准盾尾间隙
    int s2s;              ///错缝条件
    double hmxr;          ///最小纠偏半径
    double vmxr;          ///最小纠偏半径
    double mxh;           ///每环的最大水平纠偏量
    double mxv;           ///每环的最大垂直纠偏量
    int just;             ///0最优间隙1最大纠偏
    int ih;
    int iv;
}MTG_SEGSET;

typedef struct MTG_SEG_SERIAL
{
    int iseg;
	double mile;         ///起点里程
	double tm;           ///当前环起点里程
}MTG_SEG_SERIAL;

typedef struct MTG_STATION   ///设站定向
{
    int id;
    char stat[64];                       ///测站
    char back[64];                       ///后视
    double statx,staty,statz,stath;      ///测站的坐标：x,y,y及仪器高h
    double backx,backy,backz,backh;      ///后视的坐标：x,y,y及棱镜高h
    double backx1,backy1,backz1;         ///后视的实测：x,y,y
    double headh[2];
    double headv[2];
    double midh[2];
    double midv[2];
    double tailh[2];
    double tailv[2];
    double azi[2];
    double pitch[2];
    double roll[2];
    time_t t;                            ///？
    double anglediff; ///设站定向理论方位角与实际水平角的差值
}MTG_STATION;

typedef struct MTG_BASKET   ///
{
    char name[64];               ///名称
    double x,y,z;                ///坐标
    time_t t;                    ///时间
}MTG_BASKET;

typedef struct MTG_USER   ///
{
    char name[64];                ///用户名
    char password[64];            ///密码
    int level;                    ///权限等级0管理员1操作权限
}MTG_USER;

typedef struct MTG_TBM            ///盾构
{
    char name[64];                ///盾构编号
    int type;                     ///铰接油缸：0无铰接，1盾尾铰接，2盾首铰接,3盾首交接+盾尾交接
    int mode;                     ///铰接数据获取方式，0自动获取，1手动设置
    double D[6];                  ///0推进油缸直径1盾首铰接油缸后端直径2盾首铰接油缸前端直径3尾盾铰接油缸前端4尾盾铰接油缸后端
    double L[9];                  ///0前盾长度 1中盾长度 2后盾长度3推进油缸至切口4盾首铰接至切口5盾尾铰接至切口6切口面至刀盘面
    double d[4];
    int naj;
    double aj[6];                 ///各组油缸对应的角度
    int aunit;                     ///推进油缸单位
    int nbj;
    double bj[4];                 ///各组油缸对应的角度
    int bunit;                     ///铰接油缸单位
    int nfj;
    double fj[4];                 ///各组油缸对应的角度
    int funit;                     ///铰接油缸单位
}MTG_TBM;

typedef struct MTG_MEASURE
{
    double inc[7];       ///激光靶姿态角：0转动角、1俯仰角、2方位角、3俯仰角、4转动角、5第二个倾斜仪的转动角、6第二个倾斜仪的俯仰角
    double cam[4];       ///相机：
    double prism[3];     ///激光靶棱镜坐标：x,y,z
    double angle[2];     ///水平角与竖直角（全站仪）
    double comp[2];      ///电子补偿
    double head[3];      ///切口实测坐标：x,y,z
    double hdes[3];      ///切口设计坐标：x,y,z
    double headc;        ///切口里程
    double headh;        ///切口横向偏差
    double headv;        ///切口垂直偏差
    double tail[3];      ///盾尾实测坐标：x,y,z
    double tdes[3];      ///盾尾设计坐标：x,y,z
    double tailc;        ///盾尾里程
    double tailh;        ///盾尾横向偏差
    double tailv;        ///盾尾垂直偏差
    double head1[3];     ///前盾姿态
    double hdes1[3];
    double headc1;
    double headh1;
    double headv1;
    double tail1[3];
    double tdes1[3];
    double tailc1;
    double tailh1;
    double tailv1;
    double head2[3];
    double hdes2[3];
    double headc2;
    double headh2;
    double headv2;
    double tail2[3];
    double tdes2[3];
    double tailc2;
    double tailh2;
    double tailv2;
    double mile1;
    double hdev1;       ///平面偏差前
    double vdev1;       ///垂直偏差前
    double mile2;
    double hdev2;       ///平面偏差中
    double vdev2;       ///垂直偏差中
    double mile3;
    double hdev3;       ///平面偏差后
    double vdev3;       ///垂直偏差后
    double ht[3];         ///20190308whq add 盾构机第三个位置的计算坐标，被动铰接时对应盾尾坐标，主动铰接时对应切口坐标
    double htdes[3];      ///20190308whq add 盾构机第三个位置的设计坐标，被动铰接时对应盾尾坐标，主动铰接时对应切口坐标
    double faj[4];
    double baj[4];
    double aj[4];        ///推进油缸行程
    double inc1[3];      ///0转动角1俯仰角2方位角
    double inc2[3];      ///0转动角1俯仰角2方位角
    double inc3[3];      ///0转动角1俯仰角2方位角
    double inc4[4];      ///撑紧盾滚动，俯仰
    int imp;             ///1起点2中点3终点0其他点
    int iset;            ///所属测站ID
    int iseg;            ///管环编号
    time_t t1;           ///拍照时间
    time_t t2;           ///角度测量时间
    time_t t3;           ///测量棱镜时间
    int ipos;            ///棱镜位置
    time_t t4;           ///20190307whq add 零位数据保存的时间
    time_t t5;           ///20190313whq add 增加第二个倾斜仪数据获取的时间
}MTG_MEASURE;

typedef struct MTG_SEG_SET
{
    int lpz;
    int rpz;
    int std;
    int lpz1;
    int rpz1;
    int std1;
}MTG_SEG_SET;

typedef struct MTG_SEG_P
{
    double hmxr;          ///最小纠偏半径
    double vmxr;          ///最小纠偏半径
    double mxh;           ///每环的最大水平纠偏量
    double mxv;           ///每环的最大垂直纠偏量
    double mxhi;          ///对应切口水平纠偏量
    double mxvi;          ///对应切口垂直纠偏量
    int mxi;
    int cal;
}MTG_SEG_P;

typedef struct MTG_SEG
{
    int numb;              ///管环编号
    int type;              ///0 通用环  1 标准环  2 左转弯环  3 右转弯环
    int k;                 ///k块位置
    int k1;                ///上环管环K块位置
    int* ipos;
    int mode;              ///0默认 1指定k块 2指定类型 3指定k块+类型
    double hpz;            ///水平偏转
    double vpz;            ///垂直偏转
    double x,y,z;          ///管环中心坐标
    double x1,y1,z1;       ///管环中心对应TBM轴线上的点
    double ori,phi;        ///管环方位角和俯仰角
    double ori1,phi1;      ///管环方位角和俯仰角（前端面）
    double mile,dh,dv;     ///管环中心里程、水平偏差、垂直偏差（相对于设计轴线）
    double dh1,dv1;        ///TBM轴线对应的水平偏差、垂直偏差（对应管环中心）
    double head[3];        ///前端
    double headc;
    double headh;
    double headv;
    double tail[3];        ///后端
    double tailc;
    double tailh;
    double tailv;
    double tbmh,tbmv;      ///TBM轴线
    double desh,desv;      ///设计轴线
    //double hz1;            ///TBM轴线
    //double vz1;            ///TBM轴线
    //double hz2;            ///设计轴线
    //double vz2;            ///设计轴线
    //double hz3;            ///管环前端面
    //double vz3;            ///管换前端面
    double gap[4];         ///盾尾间隙
    double aj[4];          ///推进油缸行程
    double faj[4];         ///盾首铰接
    double baj[4];         ///盾尾铰接
    double len[4];         ///上下左右管环长度
    double harc;
    double varc;
    time_t t;               ///标记选型
}MTG_SEG;

typedef struct MTG_LOG
{
    int nlog;
    int type;
    time_t t;
    char msg[260];
}MTG_LOG;

typedef struct MTG_OPERATION
{
    char name[64];
    time_t t;
    char msg[260];
}MTG_OPERATION;

typedef struct MTG_ROAD
{
    int No;
    double mile;
    double x1;
    double y1;
    double z1;
    double azi;
    double pitch;
}MTG_ROAD;

typedef struct MTG_POWER
{
	double life;                   ///待机时间
	double used;                   ///当前待机时间
	int atr;                       ///ATR次数
	double a2l;                    ///与待机时间换算
	double mot;                    ///上次马达转动角度
	double m2l;                    ///与待机时间换算
	int dist;                      ///测距次数
	double d2l;                    ///与待机时间换算
	int laser;
	double l2l;
	int t1;                        ///开始使用时间
}MTG_POWER;

typedef struct MTG_DISTER///盾尾间隙测量
{
    int id;                ///测距仪的编号
    double angle;          ///
    double dist;           ///
    double dist0;          ///
    double dist1;          ///
    int sel;               ///0选用1不选用
    int isok;              ///0满足要求1不满足要求
}MTG_DISTER;

typedef struct MTG_GAPS///盾尾间隙测量
{
    char IP[16];            ///IP or COM*
    int port;               ///port
    strsvr_t svr;
    thread_t thread;        ///测距仪线程状态
    double d1;              ///盾构断面内直径
    double x,y,z;
    double radius;
    double x1,y1,z1;
    double radius1;
    double ugap;
    double dgap;
    double lgap;
    double rgap;
    double ujust;
    double djust;
    double ljust;
    double rjust;
    int opera;              ///0盾构1管环
    double ugap1;
    double dgap1;
    double lgap1;
    double rgap1;
    int done;               ///0未测量 -1点数不够 -2盾壳 -3管环 1计算 2存储
    time_t t;               ///最新测量数据获取时间
}MTG_GAPS;

typedef struct MTG_RECHECK
{
    int idta;
    time_t dta_t;
}MTG_RECHECK;

typedef struct MTG_INC
{
    int contimes;   ///连续超限次数
    int daytimes;   ///一天累计的超限次数
    time_t t;       ///最后一次倾斜仪超限的时间
}MTG_INC;

typedef struct SEG_RECORD
{
    int segnum;         ///环号
    int segtype;        ///管环类型:0标准环 1左转弯 2右转弯 3通用环
    int location;       ///点位
    double mile;        ///里程
    double offh;        ///水平偏差
    double offv;        ///垂直偏差
    time_t t;           ///时间
}SEG_RECORD;

typedef struct INC_OVERRUN       ///双倾斜仪超限信息
{
    time_t t;   ///时间
    double inc0_1[2];   ///零位时倾斜仪1滚动角、俯仰角
    double inc0_2[2];   ///零位时倾斜仪2滚动角、俯仰角
    double inc_1[2];    ///周期时倾斜仪1滚动角、俯仰角
    double inc_2[2];    ///周期时倾斜仪2滚动角、俯仰角
    double diff0[2];    ///零位时两个倾斜仪滚动角、俯仰角的差值
    double diff[2];    ///周期时两个倾斜仪滚动角、俯仰角的差值
}INC_OVERRUN;

typedef struct MTG_MEASURE_AJ
{
    double inc[5];       ///激光靶姿态角：0转动角、1俯仰角、2方位角、3俯仰角、4转动角
    double cam[4];       ///相机：
    double prism[3];     ///激光靶棱镜坐标：x,y,z
    double angle[2];     ///水平角与竖直角（全站仪）
    double comp[2];      ///电子补偿
    double head[3];      ///切口实测坐标：x,y,z
    double hdes[3];      ///切口设计坐标：x,y,z
    double headc;        ///切口里程
    double headh;        ///切口横向偏差
    double headv;        ///切口垂直偏差
    double tail[3];      ///盾尾实测坐标：x,y,z
    double tdes[3];      ///盾尾设计坐标：x,y,z
    double tailc;        ///盾尾里程
    double tailh;        ///盾尾横向偏差
    double tailv;        ///盾尾垂直偏差
    double head1[3];     ///前盾姿态
    double hdes1[3];
    double headc1;
    double headh1;
    double headv1;
    double tail1[3];
    double tdes1[3];
    double tailc1;
    double tailh1;
    double tailv1;
    double head2[3];
    double hdes2[3];
    double headc2;
    double headh2;
    double headv2;
    double tail2[3];
    double tdes2[3];
    double tailc2;
    double tailh2;
    double tailv2;
    double mile1;
    double hdev1;
    double vdev1;
    double mile2;
    double hdev2;
    double vdev2;
    double mile3;
    double hdev3;
    double vdev3;
    double faj[4];
    double baj[4];
    double aj[4];        ///推进油缸行程
    double inc1[3];      ///0转动角1俯仰角2方位角
    double inc2[3];      ///0转动角1俯仰角2方位角
    double inc3[3];      ///0转动角1俯仰角2方位角
    int imp;             ///1起点2中点3终点0其他点
    int iset;            ///所属测站ID
    int iseg;            ///管环编号
    time_t t1;           ///拍照时间
    time_t t2;           ///角度测量时间
    time_t t3;           ///测量棱镜时间
    int ipos;            ///棱镜位置
    double daj[4];       ///推进油缸数值
    int iaj[4];          ///油缸状态
    time_t t4;           ///油缸计算时间
    int status;         ///是否完成一环的初始测量，1表示已完成
    double deth;
    double detv;
    int driving;
    int amoding;
    int coverflag;      ///油缸数据是否覆盖的标识，0标识未覆盖，1标识已覆盖
    double azidiff;     ///方位角校正值
    double pitchdiff;   ///俯仰角校正值
    double hdiff[3];    ///前、中、后的水平偏差校正值
    double vdiff[3];    ///前、中、后的垂直偏差校正值
}MTG_MEASURE_AJ;

typedef struct MTG_AJPD
{
    double max;           ///当前环油缸行程值均值的最大值
    time_t t;          ///当前环油缸行程值均值的最大值存储的时间
}MTG_AJPD;

typedef struct mtg_t
{
    MTG_PRJ prj;                     ///工程信息，包括项目名称、建设单位、建设时间、项目经理、项目备注
    MTG_COM comset[7];               ///硬件设备的连接端口，0-camera1 1-camera2 2-inclinometer 3-tps,4-host,5-tbm,6-target
    MTG_CAM camset[2];               ///相机参数
    MTG_MAP mapset[2];               ///地图参数
    MTG_SETS iset;                   ///测量参数：测量周期、后视检核周期、横向限差、垂直限差、后视检核限差
    MTG_MEASURE m0;                  ///零位数据
    MTG_MEASURE m1;                  ///上次测量数据
    MTG_MEASURE m;                   ///本次测量数据

    MTG_SEG_P spara;

    MTG_SEG segs[MAX_SEG];           ///1为待拼装管环
    MTG_SEG iseg;                    ///设计排版
    int sneed[3];                    ///0标准环1左转弯2右转弯

    MTG_SEGSET segset;               ///管片参数
    road r;                          ///设计中线数据
    MTG_TBM tbm;                     ///盾构参数
    MTG_TBM_PLC plc;                 ///盾构机数据
    road r1;                         ///纠偏曲线

    SEG_RECORD *segrecord;      ///管片选型-拼装记录
    int SegRecNum;                  ///记录个数，超过200需要追加

    int nuser;                       ///用户数量
    MTG_USER* user;                  ///账户管理
    int onLine;

    MTG_SEG_SERIAL snum;             ///环号计算

	MTG_TARGET tarset;               ///激光靶参数

    int nbsk;                        ///吊篮数量
    MTG_BASKET* bask;                ///吊篮

    int nblk;                        ///管块数量
    MTG_BLOCK* blocks;               ///管块
    int* kpos;                       ///拼装点位

    int nks;                         ///关键区域数量
    MTG_KEY* keys;                   ///关键区域
    MTG_MP mp;                       ///人工测量

    int stat;                        ///
    int opera;                       ///
    tps_t tps;                       ///全站仪
    camsvr_t camsvr;                 ///图像处理
    strsvr_t incsvr;                 ///倾斜仪

    MTG_STATION istn;                ///当前设站

    MTG_DUTY duty[4];               ///班组
    int onduty;                     ///值班
    int ndty;                       ///班组总数

    MTG_SEGMONITOR smonitor;

    ///电池电量
    MTG_POWER bat[2];

    int nlog;                        ///日志
    int plog;
    int flog;
    int nolog;
    MTG_LOG logs[20];
    MTG_LOG plogs[20];
    MTG_LOG flogs[260];
    MTG_LOG *ologs;          ///打开软件时读取的文件中的日志

    lock_t loglock;
    lock_t inclock;                 ///倾斜仪

    ///
    char host[64];
    char uid[64];
    char psw[64];
    char db[64];
    lock_t dblock;

    int incycle;                    ///周期测量中
    int pause;                      ///停止状态
    int restart;                    ///重启
    int run;                        ///运行状态

    ///0-1-
    int itps;                       ///全站仪
    int iinc;                       ///倾斜仪
    int icam;                       ///相机
    int itbm;                       ///盾构机

    thread_t thread;
    int ithread;                    ///线程类型
    thread_t incthread;
    thread_t logthread;             ///读取日志文件线程
    char fpath[260];

    double aor[5];                  ///记录连续5次转动记录
    int naor;
    int idrv;                       ///刀盘转向:0停止-1左转1右转

    double baskdist;                ///后视测量距离
    int baskset;                    ///吊篮
    double baskh;                   ///？
    double d2c;                     ///？
    double d2a;                     ///？
    double d2d;                     ///？
    double baskcoord[3];            ///后视点坐标
    double prismcoord[3];           ///棱镜坐标
    double backmeas[3];             ///后视测量数据水平角、垂直角、斜距
    double prismeas[3];             ///前视测量数据水平角、垂直角、斜距

    ///TBM初始姿态(激光靶坐标系下的坐标值）
    double head[3];                ///切口坐标（零位）
    double tail[3];                ///盾尾坐标（零位）
    double left[3];                ///滚动（零位）
    double ilen;
    double mppsm1[3];
    double mppsm2[3];
    double mppsm3[3];

    double detd;                   ///后视检核水平差
    double deth;                   ///后视检核水平差
    double detv;                   ///后视检核高程差

    ///隧道界限
    double hlmt[100];
    double vlmt[100];
    int nlmt;

    ///油缸
    double aj[6];
    double fj[4];
    double bj[4];
    int segok;
    double segx;
    double segy;
    double segz;
    double sazi;
    double sphi;

    int istep;
    ///远程监控
    int ncli;
    int icli[16];       ///0 工程、1 关键区域、2 TBM、3 激光靶、4 全站仪、5 管环、6 管块、7 零位、8 设置、9 管环监测、10 用户、11 中线、12 设站定向、13 吊篮、14 相机、 15 测量数据
    int blocal;
    ///PLC
    MTG_GAPS gaps;      ///盾尾间隙
    int igs;            ///测距仪连接状态
    MTG_DISTER dister[5];

    ///数据备份
    char dbpath[260];
    int backup;

    ///错误检查
    FILE* fbi;
    char pbi[260];
    FILE* fmain;
    char pmain[260];
    char popi[260];
    MTG_BASKET istat;
    MTG_BASKET iback;
    int ierr[32];

    double tempget,tempset;
    char sqlitepath[260];

    MTG_RECHECK recheck;        ///20190306增加用于检查中线保存的时间和零位保存的时间，以及中线是否复核
    MTG_INC inc_check;          ///20190315增加双倾斜仪超限次数和时间
    int incstat;                ///在系统检查界面手动点击按钮开始获取倾斜仪数据
    double tickinc1,tickinc2,tickinc3,tickinc4;

    double azidesign;     ///设计方位角
    int SmoothTime;       ///倾斜仪数据滤波的时间

    int nover;      ///双倾斜仪超限信息个数
    INC_OVERRUN *incover;
    ///20210617whq add
    double dcm[6];
    int dci[6];

    double hdev1;
    double vdev1;
    double hdev2;
    double vdev2;
    double hdev3;
    double vdev3;

    ///20220506whq add
    MTG_MEASURE_AJ maj0;    ///油缸计算的基础数据
    MTG_MEASURE_AJ maj01;   ///上一次标定成功的姿态数据
    MTG_MEASURE_AJ maj;     ///油缸计算的最新数据
    MTG_MEASURE_AJ maj1;    ///油缸计算的上一次数据

    //double pdmax;           ///当前环油缸行程值均值的最大值
    //time_t pdmaxt;          ///当前环油缸行程值均值的最大值存储的时间
    //mtg_tp testP;
    MTG_AJPD pd;
    time_t t0;
    time_t t;

    thread_t ajthread;       ///油缸计算的主线程
    int ajstat;              ///线程是否开始状态量，1开启，0关闭
    int autoflag;            ///自动标定是否停止，0停止，1表示开启
    int originstat;        ///当前正在初始标定1
    lock_t ajlock;

    double prc;             ///棱镜常数

    int incA_flag;          ///0 不显示撑紧盾， 1显示撑紧盾
    inc_t incA;             ///撑紧盾倾斜仪
    int iincA;              ///撑紧盾倾斜仪连接状态
    thread_t incthreadA;    ///撑紧盾倾斜仪线程
    double rollA;           ///撑紧盾滚动角
    double pitchA;           ///撑紧盾俯仰角
    double init_rollA;       ///撑紧盾滚动角标定初始值
    double init_pitchA;      ///撑紧盾俯仰角标定初始值
    int ver;                ///调整滚动和俯仰角 默认为0

    /**
    0   激光靶文件
    1   激光靶参数
    2   设站定向
    3   零位数据
    4   平曲线
    5   竖曲线
    6   全站仪连接失败
    7   相机连接失败
    8   倾斜仪连接失败
    9   设站定向数据异常
    **/
}mtg_t;

typedef struct web_unit
{
    int addr;        //地址
    int type;        //数据类型
    int readorwrite; //读写
    int val_int;
    double val_double;
    double val_add,val_mul;//加常数 乘常数
    double val_result;
    int format;    //是否缩放 0开头需要缩小 I开头需要放大
    int val_bit;
    int bitnum;     ///二进制位    若没有二进制位写-1
}web_unit;

typedef struct mtg_tw
{
    int nunit;
    web_unit units[300];
    char IDname[1024];
    int read_web_complete;
    int read_tbm_complete;
    int write_web_complete;
    int write_tbm_complete;
    TCHAR m_sUrlReadWeb[128];
    TCHAR m_sUrlReadTbm[128];
    TCHAR m_sUrlWriteWeb[128];
    TCHAR m_sUrlWriteTbm[128];
    TCHAR m_sIPWeb[128];
    TCHAR m_sIPTbm[128];
//    TCHAR m_sAccount[128];
//    TCHAR m_sPassword[128];

}mtg_tw;

extern LIBMTG_API mtg_tw testW;

///
extern LIBMTG_API int mtg_init(mtg_t*  mtg);
extern LIBMTG_API void mtg_final(mtg_t* mtg);

///
extern LIBMTG_API int mtg_import_db(mtg_t* mtg);
extern LIBMTG_API int mtg_init_db(mtg_t* mtg);

///
extern LIBMTG_API int mtg_add_basket(mtg_t* mtg,const MTG_BASKET* b);
extern LIBMTG_API int mtg_remove_basket(mtg_t* mtg,int index);
extern LIBMTG_API int mtg_modify_basket(mtg_t* mtg,int index,const MTG_BASKET* b);
extern LIBMTG_API int mtg_clear_basket(mtg_t* mtg);
extern LIBMTG_API int mtg_store_basket(mtg_t* mtg);
///掘进报告
extern LIBMTG_API int mtg_add_duty(mtg_t* mtg);
extern LIBMTG_API int mtg_edit_duty(mtg_t* mtg);
///用户设置
extern LIBMTG_API int mtg_add_user(mtg_t* mtg,const MTG_USER* u);
extern LIBMTG_API int mtg_remove_user(mtg_t* mtg,int index);
extern LIBMTG_API int mtg_modify_user(mtg_t* mtg,int index,const MTG_USER* u);
extern LIBMTG_API int mtg_store_user(mtg_t* mtg);
///
extern LIBMTG_API int mtg_add_block(mtg_t* mtg,const MTG_BLOCK* b);
extern LIBMTG_API int mtg_remove_block(mtg_t* mtg,int index);
extern LIBMTG_API int mtg_modify_block(mtg_t* mtg,int index,const MTG_BLOCK* b);
extern LIBMTG_API int mtg_store_block(mtg_t* mtg);
///
extern LIBMTG_API int mtg_add_key(mtg_t* mtg,const MTG_KEY* a);
extern LIBMTG_API int mtg_remove_key(mtg_t* mtg,int index);
extern LIBMTG_API int mtg_edit_key(mtg_t* mtg,int index,const MTG_KEY* a);
extern LIBMTG_API int mtg_store_keys(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_smonitor(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_tbmset(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_tps(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_sets(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_segset(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_comset(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_camset(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_mapset(mtg_t* mtg,int index);
///
extern LIBMTG_API int mtg_store_station(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_meas(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_seg(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_segs(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_origin(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_road(mtg_t* mtg);
///
extern LIBMTG_API int mtg_store_prj(mtg_t* mtg);
///修改激光靶参数
extern LIBMTG_API int mtg_store_tars(mtg_t* mtg);

extern LIBMTG_API int mtg_store_mp(mtg_t* mtg);
///中线数据导出至文件中
extern LIBMTG_API int mtg_road_export(road* r,const char* path);
///导入中线数据
extern LIBMTG_API int mtg_road_import(road* r, const char* path);

extern LIBMTG_API int sqlite_export_db(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_export_meas(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_export_tbmset(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_export_segset(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_export_block(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_export_plc(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_export_prj(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_export_road(mtg_t* mtg,const char* path);

///存储环号计算参数
extern LIBMTG_API int mtg_store_snum(mtg_t* mtg);
///
extern LIBMTG_API int mtg_inc_start(mtg_t* mtg);

extern LIBMTG_API int mtg_inc_startA(mtg_t* mtg);
///
extern LIBMTG_API int mtg_connect(mtg_t* mtg);
///
extern LIBMTG_API int mtg_close(mtg_t* mtg);

///
extern LIBMTG_API int mtg_start_cycle(mtg_t* mtg);
///
extern LIBMTG_API void mtg_stop(mtg_t* mtg);
///
extern LIBMTG_API void mtg_inc_close(mtg_t* mtg);
///
extern LIBMTG_API int mtg_pause_cycle(mtg_t* mtg);
///
extern LIBMTG_API int mtg_restore_cycle(mtg_t* mtg);
///
extern LIBMTG_API int mtg_start_origin(mtg_t* mtg);


///日志信息
extern LIBMTG_API void add_msg_log(mtg_t* mtg,char* log,int type);
extern LIBMTG_API void mtg_log(mtg_t* mtg,int log);
extern LIBMTG_API void mtg_write_log(mtg_t* mtg,MTG_LOG* logs);
extern LIBMTG_API int mtg_peek_log(mtg_t* mtg,MTG_LOG *logs,int nmax);
extern LIBMTG_API MTG_LOG *mtg_get_log(char* fpath,int *num);
extern LIBMTG_API int mtg_start_getlog(mtg_t* mtg);

///
extern LIBMTG_API int mtg_query_time(mtg_t* mtg,long t1,long t2,MTG_MEASURE** res);
extern LIBMTG_API int mtg_query_chain(mtg_t* mtg,double l1,double l2,MTG_MEASURE** res);
extern LIBMTG_API int mtg_query_seg(mtg_t* mtg,int n1,int n2,MTG_MEASURE** res);
extern LIBMTG_API int mtg_query_seged(mtg_t* mtg,int n1,int n2,MTG_SEG** res);
extern LIBMTG_API int mtg_query_segment_chain(mtg_t* mtg,double l1,double l2,MTG_MEASURE** res);
///管环监测列表
//extern LIBMTG_API int mtg_query_smlist(mtg_t* mtg,int** res);
///管环监测查询
//extern LIBMTG_API int mtg_query_smonitor(mtg_t* mtg,int iseg,MTG_SEGMONITOR** res);
///掘进报表查询
extern LIBMTG_API int mtg_query_duty(mtg_t* mtg,int dvr,MTG_DUTY** res);
///掘进报表查询
extern LIBMTG_API int mtg_query_segeds(mtg_t* mtg,MTG_SEG** res);
///测站
extern LIBMTG_API int mtg_query_station(mtg_t* mtg,MTG_STATION** res);
///
extern LIBMTG_API int mtg_get_lmt(mtg_t* mtg);
///
extern LIBMTG_API int mtg_check_prism(mtg_t* mtg);
extern LIBMTG_API int mtg_position_prism(mtg_t* mtg,double prism[3]);
extern LIBMTG_API int mtg_check_back(mtg_t* mtg);
extern LIBMTG_API int mtg_position_back(mtg_t* mtg);
extern LIBMTG_API int mtg_measure_prism(mtg_t* mtg);
extern LIBMTG_API int mtg_measure_back(mtg_t* mtg);  ///
extern LIBMTG_API int mtg_setup(mtg_t* mtg);
extern LIBMTG_API int mtg_resetup(mtg_t* mtg);
extern LIBMTG_API int mtg_measure_basket(mtg_t* mtg,double dist,double h,int set);

//20170620增加获取温度
extern LIBMTG_API int mtg_get_temperature(mtg_t* mtg);
extern LIBMTG_API int mtg_set_temperature(mtg_t* mtg);
//打开和关闭激光
extern LIBMTG_API int mtg_start_laser(mtg_t* mtg);
extern LIBMTG_API int mtg_stop_laser(mtg_t* mtg);

///计算零位
extern LIBMTG_API int mtg_cal_origin(mtg_t* mtg);
///计算姿态
extern LIBMTG_API int mtg_laser_gesture(mtg_t* mtg);
///计算前盾尾盾
extern LIBMTG_API int mtg_cal_tbm(mtg_t* mtg);
///盾首油缸
extern LIBMTG_API int mtg_cal_aj(double rad[2],double aj[4],double* res);
///
extern LIBMTG_API int mtg_cal_seg(mtg_t* mtg);
///通过油缸行程计算盾构姿态
extern LIBMTG_API int mtg_jack_gesture(mtg_t* mtg);
///2棱镜计算姿态
extern LIBMTG_API int mtg_prism_gesture(mtg_t* mtg);
///3棱镜计算姿态
extern LIBMTG_API int mtg_manual_gesture(mtg_t* mtg);

///计算盾构机俯仰角，滚动角
extern LIBMTG_API int mtg_tbm_incline(mtg_t* mtg);
///计算盾构机方位角
extern LIBMTG_API int mtg_tbm_azimuth(mtg_t* mtg);
///计算激光靶方位角
extern LIBMTG_API int mtg_laser_incline(mtg_t* mtg);

///里程计算激光耙位置
extern LIBMTG_API int mtg_cal_prism(mtg_t* mtg,double mile,double prism[3]);
///由盾尾计算棱镜位置
extern LIBMTG_API int mtg_cal_position(mtg_t* mtg,double* h,double* v);
///二棱镜测量检核
extern LIBMTG_API int mtg_prism_check(mtg_t* mtg);
///获取全站仪补偿器值
extern LIBMTG_API int mtg_get_comp(mtg_t* mtg);
///获取全站仪电池电量
extern LIBMTG_API int mtg_get_power(mtg_t* mtg);

///盾构状态分析
extern LIBMTG_API int mtg_is_driving(mtg_t* mtg,double aor);
///管环拼装位置
extern LIBMTG_API int mtg_init_kpos(mtg_t* mtg);
///计算姿态
extern LIBMTG_API int mtg_seg_parameters(mtg_t* mtg,MTG_SEG* iseg);
///管环姿态
extern LIBMTG_API int mtg_init_position(mtg_t* mtg);
///管环拼装位置
extern LIBMTG_API int mtg_get_kpos(mtg_t* mtg,MTG_SEG* iseg);

///管环初始化
extern LIBMTG_API int mtg_init_segs(mtg_t* mtg);
///管环初始化
extern LIBMTG_API int mtg_init_seging(mtg_t* mtg);
///存储初始管环
extern LIBMTG_API int mtg_store_seging(mtg_t* mtg);
///管环计算
extern LIBMTG_API int mtg_seg_cal(mtg_t* mtg);
///标准+转弯
extern LIBMTG_API int mtg_std_segs(mtg_t* mtg,int in);
///纠偏平曲线
extern LIBMTG_API int mtg_seg_helement(mtg_t* mtg);
///纠偏竖曲线
extern LIBMTG_API int mtg_seg_velement(mtg_t* mtg);
///设计排版
extern LIBMTG_API int mtg_std_segings(mtg_t* mtg,MTG_SEG** res);

///盾尾间隙
//extern LIBMTG_API int gaps_init(mtg_t* mtg);
//extern LIBMTG_API int disters_meas(mtg_t* mtg);
//extern LIBMTG_API int mtg_store_gaps(mtg_t* mtg);
//extern LIBMTG_API int mtg_cal_gaps(mtg_t* mtg);
//extern LIBMTG_API int mtg_gap_tbm(mtg_t* mtg);
//extern LIBMTG_API int mtg_store_measgaps(mtg_t* mtg);
//extern LIBMTG_API int mtg_query_gaps(mtg_t* mtg,MTG_GAPS** res);
extern LIBMTG_API int mtg_std_aj(mtg_t* mtg,double* res);
extern LIBMTG_API int mtg_std_bj(mtg_t* mtg,double* res);
extern LIBMTG_API int mtg_std_fj(mtg_t* mtg,double* res);
extern LIBMTG_API int stripWhiteSpace(char** s);
extern LIBMTG_API int mtg_change_tps(mtg_t* mtg);
extern LIBMTG_API int mtg_cal_prism_coord(mtg_t *mtg,int ipos);
extern LIBMTG_API int mtg_store_database(mtg_t *mtg,char * filename);
extern LIBMTG_API int mtg_std_fj_sym(mtg_t* mtg,double* res);
extern LIBMTG_API int mtg_std_bj_sym(mtg_t* mtg,double* res);
//20181107whq add
extern LIBMTG_API int mtg_import_road(mtg_t* mtg);
extern LIBMTG_API int mtg_store_recheck(mtg_t* mtg);
extern LIBMTG_API int mtg_store_inccheck(mtg_t* mtg);
extern LIBMTG_API int mtg_read_faj(mtg_t* mtg);

///访问服务器
extern LIBMTG_API int init_web(char* path);
extern LIBMTG_API int read_web();
extern LIBMTG_API int read_tbm();
extern LIBMTG_API int write_tbm();
extern LIBMTG_API int write_web();

///管环选型-拼装记录
extern LIBMTG_API int mtg_query_segrecord(mtg_t* mtg,SEG_RECORD* rec);
extern LIBMTG_API int mtg_query_segrecords(mtg_t* mtg,SEG_RECORD** rec,int n1,int n2);
extern LIBMTG_API int mtg_add_record(mtg_t* mtg,SEG_RECORD* rec);
extern LIBMTG_API int mtg_modify_record(mtg_t* mtg,int index,SEG_RECORD* rec);
extern LIBMTG_API int mtg_remove_record(mtg_t* mtg,int index);
extern LIBMTG_API int mtg_store_record(mtg_t* mtg);

///双倾斜仪超限处理
extern LIBMTG_API int mtg_store_overinfo(mtg_t* mtg,INC_OVERRUN* rec);
extern LIBMTG_API int mtg_query_overinfo(mtg_t* mtg);

///20210617whq add
extern LIBMTG_API int mtg_dc_meas(mtg_t* mtg,int dc);
extern LIBMTG_API int sqlite_export_dc_meas(mtg_t* mtg,const char* path);

///20220506whq add
extern LIBMTG_API int mtg_laser_to_aj(mtg_t* mtg);
extern LIBMTG_API int mtg_aj_tbm(mtg_t* mtg);
extern LIBMTG_API int mtg_cal_aj_gesture(mtg_t* mtg);

//extern LIBMTG_API int sqlite_export_db(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_import_aj(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_export_meas_aj(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_export_origin_aj(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_update_origin_aj(mtg_t* mtg,const char* path);
extern LIBMTG_API int sqlite_export_pdmax(mtg_t* mtg,const char* path);
extern LIBMTG_API int mtg_start_origin_segmeas(mtg_t* mtg);
extern LIBMTG_API int mtg_start_aj(mtg_t* mtg);
extern LIBMTG_API int mtg_close_aj(mtg_t* mtg);
extern LIBMTG_API int mtg_cal_diff(mtg_t* mtg);
extern LIBMTG_API int mtg_aj_tbm_nocorrection(mtg_t* mtg);

extern LIBMTG_API int mtg_lasertarget_cal(mtg_t* mtg);

#ifdef __cplusplus
}
#endif


#endif // LIBMTG_H_INCLUDED
