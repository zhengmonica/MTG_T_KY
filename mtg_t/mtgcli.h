#ifndef MTGCLI_H_INCLUDE
#define MTGCLI_H_INCLUDE

#include "road.h"
#include "libtps.h"

#define MAX_COM_COUNT  50
#define MAX_TPS_COUNT  4
#define MAX_BACK_SIGHT 10
#define MAX_FORE_SIGHT 4

#define MAX_CLI   32
#define MAX_KEY   2000
#define MAX_SEG   40
#define MAX_USER  50
#define MAX_BASK  400
#define MAX_STN   200
#define MAX_LOG   200
#define MAX_BLOCK   36

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
    MTG_LOG_BEGIN_ERECT,
    MTG_LOG_BEGIN_COUNT,

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
    MTG_LOG_FINISH_ORIGIN,
    MTG_LOG_FINISH_CYCLE,
    MTG_LOG_FINISH_STORE_MEASURE,
    MTG_LOG_FINISH_STUDY,
    MTG_LOG_FINISH_COUNT,

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
    MTG_LOG_FAIL_ORIGIN,
    MTG_LOG_CANCEL_CYCLE,
    MTG_LOG_FAIL_STORE_MEASURE,
    MTG_LOG_ERROR_STUDY,
    MTG_LOG_FAIL_COUNT,

    MTG_LOG_ERROR_SENSE,
    MTG_LOG_ERROR_COMP,
    MTG_LOG_ERROR_COUNT,

    MTG_LOG_END_CYCLE,
    MTG_LOG_START_CYCLE,
    MTG_LOG_IS_RUNNING,
    MTG_LOG_ALL_READY,
    MTG_LOG_COMP_UPDATE,
    MTG_LOG_POWER_UPDATE,
    MTG_LOG_NOT_RUNNING,
    ///远程
    MTG_LOG_FINISH_CONNECT_HOST,
    MTG_LOG_FINISH_CONNECT_CLIENT,
    MTG_LOG_HOST_EXIT,
    MTG_LOG_CLIENT_EXIT,
    MTG_LOG_FINISH_GET_PRJ,
    MTG_LOG_FINISH_GET_KEY,
    MTG_LOG_FINISH_GET_TBM,
    MTG_LOG_FINISH_GET_TAR,
    MTG_LOG_FINISH_GET_CAM,
    MTG_LOG_FINISH_GET_TPS,
    MTG_LOG_FINISH_GET_SEG,
    MTG_LOG_FINISH_GET_BLOCK,
    MTG_LOG_FINISH_GET_ORIGIN,
    MTG_LOG_FINISH_GET_SETS,
    MTG_LOG_FINISH_GET_SMONITOR,
    MTG_LOG_FINISH_GET_USER,
    MTG_LOG_FINISH_GET_HE,
    MTG_LOG_FINISH_GET_VE,
    MTG_LOG_FINISH_GET_HO,
    MTG_LOG_FINISH_GET_VO,
    MTG_LOG_FINISH_GET_MO,
    MTG_LOG_FINISH_GET_BASK,
    MTG_LOG_FINISH_GET_STATION,
    MTG_LOG_FINISH_UPDATE_CLIENT,
    MTG_LOG_FINISH_GET_STATE,
    MTG_LOG_FINISH_GET_MEASURE,
    MTG_LOG_CLIENT_FINISH_COUNT,
    ///count
    MTG_LOG_COUNT
};

typedef int LANGUAGE_TYPE;
enum
{
    SIMPLIFIED_CHINESE,
    TRADITIONA_CHINESE,
    ENGLISH
};

typedef struct MTG_SYS_SET
{
    LANGUAGE_TYPE language;
}MTG_SYS_SET;

typedef struct MTG_CLIENT
{
    char name[64];
    char psw[64];
}MTG_CLIENT;

typedef struct MTG_PRJ
{
	char name[64];       ///项目名称
	double mile1;        ///起点里程
	double mile2;        ///终点里程
	int a2z;             ///掘进方向,1正向-1反向
	int duty;            ///班组（最多4个班组）
	long t1[4];          ///上班时间
	long t2[4];          ///下班时间
	int htip;            ///平曲线提示
	int vtip;            ///竖曲线提示
	double tip;          ///关键区域提示范围
	int dta;             ///用于标记中线数据输入的是db文件还是csv文件，0表示db文件，1表示csv文件
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
    int id;        ///1-camera1 2-camera2 3-inclinometer 4-tps
    char ip[16];   ///IP
    int port;      ///
}MTG_COM;

typedef struct MTG_TBM_PLC ///
{
    BOOL drive;           ///掘进开始
    BOOL amode;           ///拼装模式
    double uaj;           ///A组推进油缸行程
    double daj;           ///B组推进油缸行程
    double laj;           ///C组推进油缸行程
    double raj;           ///D组推进油缸行程
    double ufaj;          ///刀盘位移油缸1组
    double dfaj;          ///刀盘位移油缸2组
    double lfaj;          ///刀盘位移油缸3组
    double rfaj;          ///刀盘位移油缸4组
    double rtaj;          ///扭矩油缸右侧
    double ltaj;          ///扭矩油缸左侧
    double ubaj;          ///盾尾铰接油缸右上：上
    double dbaj;          ///盾尾铰接油缸左下：下
    double lbaj;          ///盾尾铰接油缸左上：左
    double rbaj;          ///盾尾铰接油缸右下：右
    double rusaj;         ///盾体铰接油缸右上
    double rdsaj;         ///盾体铰接油缸右下
    double ldsaj;         ///盾体铰接油缸左下
    double lusaj;         ///盾体铰接油缸左上
}MTG_TBM_PLC;

typedef struct MTG_SETS
{
    int cyc;                   ///测量周期
    int bcyc;                  ///后视检核周期
    int palw;                  ///偏差限差
    int jalw;                  ///偏差变化限差
    int balw;                  ///后视限差
    int talw;                  ///时间限差
    int vibration;             ///0正常震动环境1大幅震动环境
    int rstn;                  ///后视超限重新定向,0常规1重新定向
    int tsyn;                  ///0盾构掘进停止停止1盾构掘进停止继续测量
    int rget;                  ///环号计算方式0PLC状态1里程近似2综合严密
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
    int heading;               ///0以轴线为基准1以切口点切线为基准

    int povr;                  ///偏差超限
    int jovr;                  ///姿态跳变
    int tovr;                  ///时间间隔超限
    int bovr;                  ///后视检核超限
    int toEr;                  ///将警示信息设为错误信息

    double flen;               ///纠偏距离
    double fdev;               ///纠偏限差

    int lang;                  ///语言
}MTG_SETS;

typedef struct MTG_SEGMONITOR   ///
{
    int number;                  ///监测的管环编号
    int monitor;                 ///0无监测1监测
    int cycle;                   ///监测周期
    int last;                    ///持续监测环数
    double x,y,z;                ///坐标
    time_t t;                    ///时间
}MTG_SEGMONITOR;

typedef struct MTG_MP
{
    double head[6];           ///0-2初始3-5实测
    double tail[6];           ///0-2初始3-5实测
    double prism[18];           ///0-8初始9-17实测
    double inc[6];            ///0-2初始3-5实测
    double headc;             ///切口里程
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
    long t;
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
	double prism[3];         ///棱镜相对于前屏孔中心坐标
	double prc;              ///棱镜常数
	double length;           ///前屏与后屏的距离
	int cam;                 ///0 大恒相机，1 baumer相机
	int inc;                 ///倾斜仪类型 0为瑞芬倾斜仪1为NS-15倾斜仪20130702
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

typedef struct MTG_WORK
{
    double mileage;            ///里程
    double segs;               ///环数
    long t1;                   ///掘进时间
    long t2;                   ///停止时间
}MTG_WORK;

typedef struct MTG_SEGSET
{
	int type;             ///0通用环,1:2+1,2通缝拼装（标准环）
	int in;               ///0错缝1通缝
	int f2b;              ///0等腰梯形，1直角梯形
	double l2s;           ///管环楔形量
	double L;             ///管环长度
	double De;            ///管环外径
	double D;             ///管环内径
    double Dn;            ///管环公称直径
    int Ks;               ///K块拼装点位数量
    double G1;            ///盾尾最小间隙
    double G0;            ///标准盾尾间隙
    int s2s;              ///错缝条件
    double hmr;           ///水平最小纠偏半径
    double vmr;           ///垂直最小纠偏半径
}MTG_SEGSET;

typedef struct MTG_SEG_SERIAL
{
    int No;
	double mile[20];         ///起点里程
	double v1;               ///平均掘进速度
	double v2;               ///特别区域平均速度
	double v3;               ///当前掘进速度
	double tm;
	int sum1;                ///计入平均掘进速度的次数
	int sum2;                ///计入特别区域平均速度的次数
	int sum3;
	int sum4;
	int mode;                ///0:未测量，1:测量，平均速度0，2:测量，平均速度>0，3:测量，异常速度
	int state;               ///0:未修正，1:修正，起点里程未赋值，2:修正，起点里程赋值
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
    int type;                     ///铰接油缸：0无铰接，1被动铰接，2主动铰接
    int mode;                     ///铰接数据获取方式，0自动获取，1手动设置
    double D[6];                  ///0开挖直径1刀盘直径2尾盾外直径3尾盾内直径4推进油缸直径5铰接油缸直径
    double L[5];                  ///0盾构机长度1推进油缸至切口距离2切口至刀盘3铰接油缸至切口距离4后筒长度
    double d[4];                  ///油缸行程：0左侧1右侧2上侧3下侧

}MTG_TBM;

typedef struct MTG_MEASUREMENT
{
    double inc[3];       ///激光靶姿态角：0转动角、1俯仰角、2方位角
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
    double mid[3];       ///铰接位置
    double mdes[3];
    double midj[4];      ///铰接油缸行程
    double midh;
    double midv;
    double midc;
    double aj[4];        ///推进油缸行程
    double roll;         ///盾构机转动角
    double pitch;        ///盾构机俯仰角
    double azimuth;      ///盾构机方位角
    int seg;             ///1起点2中点3终点0其他点
    int iset;            ///所属测站ID
    int iseg;            ///管环编号
    time_t t1;           ///拍照时间
    time_t t2;           ///角度测量时间
    time_t t3;           ///测量棱镜时间
}MTG_MEASUREMENT;

typedef struct MTG_SEG
{
    int numb;              ///管环编号
    int type;              ///0 通用环  1 标准环  2 左转弯环  3 右转弯环
    int kpos;              ///k块位置
    int pos[36];           ///K块可安装位置 0可安装，1不满足错缝，-1不满足盾尾间隙
    double azi;            ///管片轴线方位角
    double tilt;           ///管片轴线俯仰角
    double azi1;           ///设计方位
    double tilt1;          ///设计坡度
    double azi2;           ///盾构机轴线方位角
    double tilt2;          ///盾构机轴线俯仰角
    double lgap;           ///盾尾间隙
    double rgap;
    double ugap;
    double dgap;
    double uaj;            ///推进油缸行程
    double daj;
    double laj;
    double raj;
    double uhj;            ///铰接油缸行程
    double dhj;
    double lhj;
    double rhj;
    double ufj;
    double dfj;
    double lfj;
    double rfj;
    double mile;          ///管片前端里程
    double mile1;         ///对应的切口里程
    double x;
    double y;
    double z;
    double x1;
    double y1;
    double z1;
    time_t t;            ///标记选型
    time_t t1;           ///标记计算
    double uds;
    double dh;
    double dv;
    double dh1;
    double dv1;
    double l2r;
    double d2u;
    double rim[4];          ///最大纠偏量
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
	double life;                   //待机时间
	double used;                   //当前待机时间
	int ATR;                    //ATR次数
	double a2t;                 //与待机时间换算
	double MOT;                 //上次马达转动角度
	double m2t;                 //与待机时间换算
	int DIST;                   //测距次数
	double d2t;                 //与待机时间换算
	int laser;
	double l2t;
	int t1;                     //开始使用时间
}MTG_POWER;

typedef struct mtg_cli
{
    MTG_PRJ prj;                     ///工程信息，包括项目名称、建设单位、建设时间、项目经理、项目备注
    MTG_COM comset[7];               ///硬件设备的连接端口，0-camera1 1-camera2 2-inclinometer 3-tps,4-client,5-tbm,6-target
    MTG_CAM camset[2];               ///相机参数
    MTG_MAP mapset[2];               ///地图参数
    MTG_SETS sets;                   ///测量参数：测量周期、后视检核周期、横向限差、垂直限差、后视检核限差
    MTG_MEASUREMENT m0;              ///零位数据
    MTG_MEASUREMENT m1;              ///上次测量数据
    MTG_MEASUREMENT m;               ///本次测量数据
    MTG_MEASUREMENT* qm;           ///历史数据查询
    int nqm;
    double headhMAX;
    double headvMAX;
    bool isquery;                    ///正在查询
    int nqlog;                      ///日志查询
    MTG_LOG* qlog;

    MTG_SEG segs[MAX_SEG];                ///5为待拼装管环
    int ns;

    MTG_SEGSET segset;               ///管片参数
    road r;                          ///设计中线数据
    MTG_TBM tbm;                     ///盾构参数
    MTG_TBM_PLC plc;                 ///盾构机数据
    road r1;                         ///纠偏曲线

    int nuser;                       ///用户数量
    MTG_USER* user;         ///账户管理
    int onLine;

    MTG_SEG_SERIAL snum;             ///环号计算

	MTG_TARGET tarset;               ///激光靶参数

    int nbsk;                        ///吊篮数量
    MTG_BASKET* bask;       ///
    int nstn;                        ///设站定向次数
    MTG_STATION* stns;       ///设站定向次数
    MTG_STATION istn;                ///当前设站定向


    int nblk;                        ///管块数量
    MTG_BLOCK* blocks;            ///管块
    int* kpos;

    int nks;                         ///关键区域数量
    MTG_KEY* keys;              ///关键区域
    MTG_MP mp;                       ///人工测量

    int stat;                        ///
    int opera;                       ///
    tps_t tps;                       ///全站仪

    ///客户端
    MTG_CLIENT guest[MAX_CLI];
    int ncli;

    MTG_WORK works[4];               ///班组

    MTG_SEGMONITOR smonitor;

    ///电池电量
    MTG_POWER bat[2];

    int lang;

    int nlog;                        ///日志
    MTG_LOG logs[MAX_LOG];
    MTG_LOG elog;                    ///错误日志
    FILE* flog;
    time_t tlog;

    int incycle;            ///运行状态
    int pause;              ///停止状态
    int restart;            ///重启
    int run;

    ///0-1-
    int itps;                  ///？
    int iinc;                  ///？
    int icam;                  ///？
    int iclient;               ///0断开1服务器连接状态2远程连接状态3获取基础数据状态
    int itbm;                  ///盾构机

    double inc[3];             ///测量棱镜时的倾斜仪角度
    int rotation;              ///刀盘转向:0停止-1左转1又转

    double baskdist;           ///后视测量距离
    int baskset;               ///吊篮
    double baskh;              ///？
    double d2c;                ///？
    double d2a;                ///？
    double d2d;                ///？
    double baskcoord[3];       ///后视点坐标
    double prismcoord[3];      ///棱镜坐标
    double backmeas[3];        ///后视测量数据水平角、垂直角、斜距


    ///TBM初始姿态(激光靶坐标系下的坐标值）
    double head[3];            ///切口坐标（零位）
    double tail[3];            ///盾尾坐标（零位）
    double left[3];            ///滚动（零位）

    int alw[9];                ///0偏差超限1偏差变化超限

    double detd;               ///后视检核水平差
    double deth;               ///后视检核水平差
    double detv;               ///后视检核高程差

    int failed;

    ///隧道界限
    double hlmt[100];
    double vlmt[100];
    int nlmt;

    MTG_ROAD* road;
    int nRoad;

    int istep;
    int imode;                  ///0仅查看1控制
    int ilocal;                 ///0远程1本地
    char iword[4096];
    int iget;                   ///0无数据1请求修改2修改完成
    int iOk;
}mtg_cli;

///
extern  int cli_init(mtg_cli*  cli);
extern  void cli_final();


extern  int cli_store_prj();
extern  int cli_store_safety();
extern  int cli_store_origin();
extern  int cli_store_measet();
extern  int cli_store_road();


/////开始周期测量
//extern  int cli_start_cycle();
/////停止周期测量
//extern  void cli_stop_cycle();

///
extern  void cli_write_log(const char* log,int type);
//extern  int cli_peek_log(log_t *logs,int nmax);

///
extern  int cli_query_time(long t1,long t2,MTG_MEASUREMENT** res);
extern  int cli_query_chain(double l1,double l2,MTG_MEASUREMENT** res);
extern  int cli_query_seg(int n1,int n2,MTG_MEASUREMENT** res);


///计算零位
//extern  int cli_cal_origin();
///计算盾构机姿态
//extern  int cli_cal_gesture();
///计算盾构机俯仰角，滚动角
//extern  int cli_cal_incline();


//extern  int cli_add_usr(const char* name,const char* psw);
//extern  int cli_remove_usr(const char* name,const char* psw);
//extern  int cli_modify_usr(const char* name,const char* psw,const char* psw1);

void DecodeCommand(const char* cmd);

void SendCommand(const char* cmd);


#endif // MTGCLI_H_INCLUDE
