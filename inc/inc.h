#ifndef LIBCOIL_H_INCLUDED
#define LIBCOIL_H_INCLUDED

#include "stream.h"

#ifdef WIN32
#ifdef LIBINC_MAKINGDLL
#define LIBINC_API __declspec(dllexport)
#else
#define LIBINC_API __declspec(dllimport)
#endif
#else
#define LIBINC_API
#endif

#define ANGLE_RANGE 90000  ///角度范围

//#include <vector>
//using namespace std;


#ifdef __cplusplus
extern "C" {
#endif



typedef struct inc_t
{
    int command;    //指令
    int timeout;
    strsvr_t svr;
    thread_t thread;
    int opera;  //线程运行的指令
    int ret;    //返回值是否完全正确
    double roll;    //滚动角
    double pitch;   //俯仰角
    int type;   //0 为服务端， 1为客户端
    lock_t incLock;
    int incStatus;
    int id; //设备id

    double rollNum[10];
    int rollCnt;
    double pitchNum[10];
    int pitchCnt;
    int ver;    //0 不平滑 1平滑
//    vector<double> rollNum;
//    vector<double> pitchNum;

}inc_t;


enum{
    inc_non,
    INC_GET,  //获取倾斜仪数值
    inc_count
};

extern int LIBINC_API inc_thread(inc_t* inc);
extern void LIBINC_API inc_init(inc_t* inc);
extern int LIBINC_API inc_connect(inc_t* inc,int *opts, int str, char *path);
extern void LIBINC_API inc_close(inc_t* inc);
extern int LIBINC_API inc_get_rc(inc_t* inc,int *opera,int* rc);


#ifdef __cplusplus
}
#endif

#endif // LIBCOIL_H_INCLUDED
