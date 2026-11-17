#ifndef MSR_H_INCLUDE
#define MSR_H_INCLUDE

#include "road.h"

#define MAX_COM_COUNT  50
#define MAX_TPS_COUNT  4
#define MAX_BACK_SIGHT 10
#define MAX_FORE_SIGHT 4

#define MAX_RNG   40
#define MAX_BLK   36

typedef struct PRJ_T
{
	char name[64];       ///项目名称
	double mile1;        ///起点里程
	double mile2;        ///终点里程
	int a2z;             ///掘进方向,1正向-1反向
	int dta;             ///用于标记中线数据输入的是db文件还是csv文件，0表示db文件，1表示csv文件
}PRJ_T;

typedef struct PLC_T ///
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
}PLC_T;

typedef struct BLOCK_T
{
	char name[64];       ///名字
	double angle ;    ///圆心角
}BLOCK_T;

typedef struct SEG_T
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
}SEG_T;

typedef struct TBM_T            ///盾构
{
    char name[64];                ///盾构编号
    int type;                     ///铰接油缸：0无铰接，1被动铰接，2主动铰接
    int mode;                     ///铰接数据获取方式，0自动获取，1手动设置
    double D[6];                  ///0开挖直径1刀盘直径2尾盾外直径3尾盾内直径4推进油缸直径5铰接油缸直径
    double L[9];                  ///0盾构机长度1推进油缸至切口距离2切口至刀盘3铰接油缸至切口距离4后筒长度
    double d[4];                  ///油缸行程：0左侧1右侧2上侧3下侧
    int naj;
    double aj[6];                 ///各组油缸对应的角度
    int aunit;                    ///推进油缸单位
    int nbj;
    double bj[4];                 ///各组油缸对应的角度
    int bunit;                    ///铰接油缸单位
    int nfj;
    double fj[4];                 ///各组油缸对应的角度
    int funit;                    ///铰接油缸单位

}TBM_T;

typedef struct SEG
{
    int numb;              ///管环编号
    int type;              ///0 通用环  1 标准环  2 左转弯环  3 右转弯环
    int k;                 ///k块位置
    int k1;                ///上环管环K块位置
    int* ipos;
    int mode;              ///0默认 1指定k块 2指定类型 3指定k块+类型
    int vcal;              ///0考虑垂直1忽略垂直
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
}SEG;

typedef struct msr_t
{
    PRJ_T prj;                        ///工程信息，包括项目名称、建设单位、建设时间、项目经理、项目备注
    SEG_T segt;                       ///管片参数
    int nblk;                         ///管块数量
    BLOCK_T* blocks;                  ///管块
    int* kpos;
    double* hpz;
    int nhp;
    double* vpz;
    int nvp;
    road r;                           ///设计中线数据
    TBM_T tbm;                        ///盾构参数
    PLC_T plc;                        ///盾构机数据
    road r1;                          ///纠偏曲线
    int ns;
    SEG segs[MAX_RNG];                ///
    SEG iseg;                         ///管环选型管环临时值
    SEG dseg;                         ///设计排版第一环管环
    int ndes;
    SEG* des;                ///
    int ical;                         ///管环已选型
    int dcal;                         ///设计排版已计算
    int dmode;
    int mode;
}msr_t;

///
extern  int msr_init(msr_t*  msr);
extern  int msr_init_des(msr_t*  msr);
extern  void msr_final();


extern  int msr_store_prj(msr_t*  msr);
extern  int msr_store_road(msr_t*  msr);

extern int msr_init_kpos(msr_t* msr);
extern int msr_get_kpos(msr_t* msr,SEG* iseg);
extern int msr_init_pz(msr_t* msr);

extern  int msr_cal_design(msr_t*  msr,int index);

#endif // MTGCLI_H_INCLUDE
