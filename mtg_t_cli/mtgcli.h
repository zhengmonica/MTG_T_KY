#ifndef MTGCLI_H_INCLUDE
#define MTGCLI_H_INCLUDE

#include "libmtg.h"
#include "road.h"
#include "libtps.h"

typedef struct mtg_cli
{
    MTG_MEASURE* qm;           ///历史数据查询
    int nqm;
    double headhMAX;
    double headvMAX;
    int isquery;                     ///0正常1正在查询2查询完成
    MTG_STATION* qs;                 ///测站查询
    int nqs;
    int nqlog;                       ///日志查询
    MTG_LOG* qlog;
    int nr[5];
    int nr1[5];

    int ierr;

    int istep;
    int imode;                  ///0仅查看1控制
    char iword[4096];
    int iget;                   ///0无数据1请求修改2修改完成
    int iOk;
    int login;
    int local;
    int mode;                  ///1为单独使用
}mtg_cli;
///

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
extern  int cli_query_time(long t1,long t2,MTG_MEASURE** res);
extern  int cli_query_chain(double l1,double l2,MTG_MEASURE** res);
extern  int cli_query_seg(int n1,int n2,MTG_MEASURE** res);


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
