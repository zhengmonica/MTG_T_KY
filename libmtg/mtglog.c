#include "libmtg.h"
#include "trace.h"
#include <string.h>
#include <stdio.h>

void mtg_write_log(mtg_t* mtg,MTG_LOG* logs)
{
    char path[260];
    char szFull[_MAX_PATH];
    char szDrive[_MAX_DRIVE];
    char szDir[_MAX_DIR];
    int nlog=mtg->flog;
    int i=0;
    time_t t1;
    FILE* fp;

    if(nlog<=0) return;
    GetModuleFileName(NULL, szFull, _MAX_PATH);
    _splitpath(szFull, szDrive, szDir, NULL, NULL);
    strcpy(szFull, szDrive);
    strcat(szFull, szDir);

    strcat(szFull,"log\\");

    time(&t1);
    strftime(path,64,"%Y-%m-%d.log",localtime(&t1));
    strcat(szFull,path);

    fp=fopen(szFull,"a");
    if(fp)
    {
        for(i=0;i<nlog;i++)
        {
            strftime(path,64,"%Y-%m-%d %H:%M:%S",localtime(&logs[i].t));
            fprintf(fp,"%d,%d,%s,%s\n",logs[i].nlog,logs[i].type,path,logs[i].msg);
        }
        mtg->flog=0;
        fclose(fp);
    }
}

void add_msg_log(mtg_t* mtg,char* log,int type)
{
    time_t t;

    time(&t);
    lock(&mtg->loglock);
    if(mtg->nlog>=20) mtg->nlog=0;
    mtg->nlog++;
    mtg->logs[mtg->nlog-1].nlog=-1;
    mtg->logs[mtg->nlog-1].t=t;
    mtg->logs[mtg->nlog-1].type=type;
    strcpy(mtg->logs[mtg->nlog-1].msg,log);
    //mtg_write_log(mtg,&mtg->logs[mtg->nlog-1]);

    unlock(&mtg->loglock);
    sleepms(100);

}

void mtg_log(mtg_t* mtg,int log)
{
    time_t t;
    time(&t);
    lock(&mtg->loglock);
    if(mtg->nlog>=20) mtg->nlog=0;
    mtg->nlog++;
    mtg->logs[mtg->nlog-1].nlog=log;
    mtg->logs[mtg->nlog-1].t=t;
    switch(log)
    {
    case MTG_LOG_BEGIN_TARGET_BACKSIGHT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向后视......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_TARGET_PRISM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向目标棱镜......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_STOP_LASER:
        sprintf(mtg->logs[mtg->nlog-1].msg,"停止激光......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_FINEADJUST_BACKSIGHT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"照准后视......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_MEASURE_BACKSIGHT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量后视......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_FINEADJUST_PRISM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"照准目标棱镜......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_MEASURE_PRISM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量目标棱镜......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_TARGET_LASERUNIT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向激光屏......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_MEASURE_ANGLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"获取激光参数......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_START_LASER:
        sprintf(mtg->logs[mtg->nlog-1].msg,"打开激光......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_CONNECT_TPS:
        sprintf(mtg->logs[mtg->nlog-1].msg,"全站仪初始化......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_CONNECT_INCLINE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"姿态仪初始化......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_CONNECT_CAMERA:
        sprintf(mtg->logs[mtg->nlog-1].msg,"激光屏初始化......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_TARGET_BASKET:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向吊篮......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_FINEADJUST_BASKET:
        sprintf(mtg->logs[mtg->nlog-1].msg,"照准吊篮......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_MEASURE_BASKET:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量吊篮......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_TARGET_SEGMENT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"管环监测开始......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_MEASURE_SEGMENT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"正监测管环......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_BEGIN_FINEADJUST_SEGMENT: break;
    case MTG_LOG_BEGIN_ERECT: break;
    case MTG_LOG_FINISH_TARGET_BACKSIGHT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向后视完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_TARGET_PRISM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向目标棱镜完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_STOP_LASER:
        sprintf(mtg->logs[mtg->nlog-1].msg,"停止激光完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_FINEADJUST_BACKSIGHT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"照准后视完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_MEASURE_BACKSIGHT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量后视完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_FINEADJUST_PRISM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"照准目标棱镜完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_MEASURE_PRISM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量目标棱镜完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_TARGET_LASERUNIT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向激光屏完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_MEASURE_ANGLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"获取激光参数完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_START_LASER:
        sprintf(mtg->logs[mtg->nlog-1].msg,"打开激光完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_CONNECT_TPS:
        sprintf(mtg->logs[mtg->nlog-1].msg,"全站仪初始化成功！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_CONNECT_INCLINE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"姿态仪初始化成功！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_CONNECT_CAMERA:
        sprintf(mtg->logs[mtg->nlog-1].msg,"激光屏初始化成功！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_TARGET_BASKET:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向吊篮完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_FINEADJUST_BASKET:
        sprintf(mtg->logs[mtg->nlog-1].msg,"照准吊篮完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_MEASURE_BASKET:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量吊篮完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_TARGET_SEGMENT:break;
    case MTG_LOG_FINISHFINEADJUST_SEGMENT:break;
    case MTG_LOG_FINISH_MEASURE_SEGMENT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"管环监测完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_COMP_ON:
        sprintf(mtg->logs[mtg->nlog-1].msg,"电子补偿器打开！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_COMP_OFF:
        sprintf(mtg->logs[mtg->nlog-1].msg,"电子补偿器关闭！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_SET_STATION:
        sprintf(mtg->logs[mtg->nlog-1].msg,"设站完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_SET_PRISM_HEIGHT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"设置棱镜高完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_SET_ORIENTATION:
        sprintf(mtg->logs[mtg->nlog-1].msg,"定向完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_ORIGIN:
        sprintf(mtg->logs[mtg->nlog-1].msg,"零位测量完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_CYCLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"周期测量完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_STORE_MEASURE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"数据存储成功！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_STUDY:
        sprintf(mtg->logs[mtg->nlog-1].msg,"学习测量完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_STORE_AJ_MEASURE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"保存姿态数据完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_RESET_ORIGIN_SEG:
        sprintf(mtg->logs[mtg->nlog-1].msg,"复位初始标定状态完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_STORE_PDMAX:
        sprintf(mtg->logs[mtg->nlog-1].msg,"保存长度数据完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_AJ_CYCLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"姿态测量完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_UPDATE_AJ_MEASURE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"更新姿态完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_START_ORIGIN_SEG_CYCLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"开始初始标定测量...");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_GET_SPECKLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"提取光斑完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FAIL_TARGET_BACKSIGHT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向后视失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_TARGET_PRISM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向目标棱镜失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_STOP_LASER:
        sprintf(mtg->logs[mtg->nlog-1].msg,"停止激光失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_FINEADJUST_BACKSIGHT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"照准后视失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_MEASURE_BACKSIGHT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量后视失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_FINEADJUST_PRISM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"照准目标棱镜失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_MEASURE_PRISM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量目标棱镜失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_TARGET_LASERUNIT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向激光屏失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_MEASURE_ANGLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"获取激光参数失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_START_LASER:
        sprintf(mtg->logs[mtg->nlog-1].msg,"打开激光失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_CONNECT_TPS:
        sprintf(mtg->logs[mtg->nlog-1].msg,"全站仪初始化失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_CONNECT_INCLINE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"姿态仪初始化失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_CONNECT_CAMERA:
        sprintf(mtg->logs[mtg->nlog-1].msg,"激光屏初始化失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_TARGET_BASKET:
        sprintf(mtg->logs[mtg->nlog-1].msg,"转向吊篮失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_FINEADJUST_BASKET:
        sprintf(mtg->logs[mtg->nlog-1].msg,"照准吊篮失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_MEASURE_BASKET:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量吊篮失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_TARGET_SEGMENT:break;
    case MTG_LOG_FAIL_FINEADJUST_SEGMENT:break;
    case MTG_LOG_FAIL_MEASURE_SEGMENT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"管环监测失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_COMP_ON:
        sprintf(mtg->logs[mtg->nlog-1].msg,"电子补偿器打开失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_COMP_OFF:
        sprintf(mtg->logs[mtg->nlog-1].msg,"电子补偿器关闭失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_SET_STATION:
        sprintf(mtg->logs[mtg->nlog-1].msg,"设站失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_SET_PRISM_HEIGHT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"棱镜高设置失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_SET_ORIENTATION:
        sprintf(mtg->logs[mtg->nlog-1].msg,"定向设置失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_ORIGIN:
        sprintf(mtg->logs[mtg->nlog-1].msg,"零位测量失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_CANCEL_CYCLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量取消，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_STORE_MEASURE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"数据存储失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_ERROR_STUDY:
        sprintf(mtg->logs[mtg->nlog-1].msg,"棱镜初始位置错误，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_ERROR_SENSE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"加密锁错误，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_ERROR_COMP:
        sprintf(mtg->logs[mtg->nlog-1].msg,"电子补偿器错误，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_STORE_ORIGIN_SEG:
        sprintf(mtg->logs[mtg->nlog-1].msg,"保存初始标定数据失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_ORIGIN_SEG:
        sprintf(mtg->logs[mtg->nlog-1].msg,"初始标定失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_RESET_ORIGIN_SEG:
        sprintf(mtg->logs[mtg->nlog-1].msg,"复位初始标定状态失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_STORE_PDMAX:
        sprintf(mtg->logs[mtg->nlog-1].msg,"保存长度数据失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_AJ_CYCLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"姿态测量失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_STORE_AJ_MEASURE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"保存姿态数据失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_UPDATE_AJ_MEASURE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"更新姿态数据失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_END_CYCLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量终止！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_START_CYCLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量开始！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_IS_RUNNING:
        sprintf(mtg->logs[mtg->nlog-1].msg,"正在运行！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_ALL_READY:
        sprintf(mtg->logs[mtg->nlog-1].msg,"准备就绪！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_COMP_UPDATE:break;
    case MTG_LOG_POWER_UPDATE:break;
    case MTG_LOG_NOT_RUNNING:
        sprintf(mtg->logs[mtg->nlog-1].msg,"系统未运行！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_AJ_IS_RUNNING:
        sprintf(mtg->logs[mtg->nlog-1].msg,"油缸推算状态判断正在运行！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_AJ_NOT_RUNNING:
        sprintf(mtg->logs[mtg->nlog-1].msg,"油缸推算状态判断未运行！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_SETMEASURE_BASKET:
        sprintf(mtg->logs[mtg->nlog-1].msg,"新吊篮测量完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_MEASURE_RPISM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量棱镜成功！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_GESTURE_CHECK:
        sprintf(mtg->logs[mtg->nlog-1].msg,"姿态复核完成！");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FAIL_GESTURE_CHECK:
        sprintf(mtg->logs[mtg->nlog-1].msg,"姿态复核失败！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_BEGIN_DIST_CONNECT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"盾尾间隙系统初始化...");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_DIST_CONNECT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"盾尾间隙系统初始化成功!");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FAIL_DIST_CONNECT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"盾尾间隙系统初始化失败，请检查!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_BEGIN_DIST_TBM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"开始测量...");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_DIST_ADDRESS_READ:
        sprintf(mtg->logs[mtg->nlog-1].msg,"获取距离测量设备地址成功!");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FAIL_DIST_ADDRESS_READ:
        sprintf(mtg->logs[mtg->nlog-1].msg,"获取距离测量设备地址失败!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_BEGIN_DIST_SEG:
        sprintf(mtg->logs[mtg->nlog-1].msg,"开始测量...");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_DIST_ADDRESS_WRITE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"设置距离测量设备地址成功!");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FAIL_DIST_ADDRESS_WRITE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"设置距离测量设备地址失败!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FINISH_DIST_TBM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量成功!");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FAIL_DIST_TBM:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量失败!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FINISH_DIST_SEG:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量成功!");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FAIL_DIST_SEG:
        sprintf(mtg->logs[mtg->nlog-1].msg,"测量失败!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FINISH_STORE_STATION:
        sprintf(mtg->logs[mtg->nlog-1].msg,"存储测站成功!");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FAIL_STORE_STATION:
        sprintf(mtg->logs[mtg->nlog-1].msg,"存储测站失败!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
        //case
    case MTG_LOG_CAMERA_READY:
        sprintf(mtg->logs[mtg->nlog-1].msg,"相机准备启动!");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_NO_PRISM_POSITION:
        sprintf(mtg->logs[mtg->nlog-1].msg,"棱镜位置不存在!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_ERROR_SIZE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"照片尺寸不符,请检查配置文件!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_BACKSIGHT_OVER_LIMIT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"后视超限,设站失败,请检查!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_BEGIN_GET_ANGLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"开始获取角度!");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FINISH_GET_ANGLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"获取角度成功!");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FAIL_GET_ANGLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"获取角度失败,请检查!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FINISH_GET_INCLINE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"激光靶角度测量成功!");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FAIL_GET_INCLINE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"激光靶角度测量失败,请检查!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_GET_INCLINE1:
        sprintf(mtg->logs[mtg->nlog-1].msg,"激光靶主角度测量失败,请检查!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_GET_INCLINE2:
        sprintf(mtg->logs[mtg->nlog-1].msg,"激光靶检核角度测量失败,请检查!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_INC_OUT:
        sprintf(mtg->logs[mtg->nlog-1].msg,"激光靶角度异常,请立刻联系上海米度测量技术有限公司!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_CONNECT_INCLINE1:
        sprintf(mtg->logs[mtg->nlog-1].msg,"姿态仪初始化失败,请检查!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_CONNECT_INCLINE2:
        sprintf(mtg->logs[mtg->nlog-1].msg,"角度初始化失败,请检查!");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FINISH_GET_LOG:
        sprintf(mtg->logs[mtg->nlog-1].msg,"历史日志获取成功!");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_FAIL_GET_IMAGE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"采集照片失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_FAIL_GET_SPECKLE:
        sprintf(mtg->logs[mtg->nlog-1].msg,"提取光斑失败，请检查！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    case MTG_LOG_BEGIN_CONNECT_INCA:
        sprintf(mtg->logs[mtg->nlog-1].msg,"连接撑紧盾倾斜仪......");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_CONNECT_INCA_FINSH:
        sprintf(mtg->logs[mtg->nlog-1].msg,"连接撑紧盾倾斜仪成功");
        mtg->logs[mtg->nlog-1].type=0;
        break;
    case MTG_LOG_CONNECT_INCA_FAIL:
        sprintf(mtg->logs[mtg->nlog-1].msg,"连接撑紧盾倾斜仪失败！");
        mtg->logs[mtg->nlog-1].type=1;
        break;
    default:
        break;
    }
    //mtg_write_log(mtg,&mtg->logs[mtg->nlog-1]);
    //strcpy(mtg->logs[mtg->nlog-1].msg,"\0");
    unlock(&mtg->loglock);
    sleepms(100);
}

int mtg_peek_log(mtg_t* mtg,MTG_LOG *logs,int nmax)
{
    int n=0;
    int i;
    n=mtg->nlog;
    mtg->plog=n;
    if(nmax<n) n=nmax;
    if(n>0)
    {
        lock(&mtg->loglock);
        for(i=0;i<n;i++)
        {
            logs[i].nlog=mtg->logs[mtg->nlog-n+i].nlog;
            logs[i].t=mtg->logs[mtg->nlog-n+i].t;
            logs[i].type=mtg->logs[mtg->nlog-n+i].type;
            strcpy(logs[i].msg,mtg->logs[mtg->nlog-n+i].msg);
            mtg->plogs[i].nlog=logs[i].nlog;
            mtg->plogs[i].t=logs[i].t;
            mtg->plogs[i].type=logs[i].type;
            strcpy(mtg->plogs[i].msg,logs[i].msg);

            if(mtg->flog>=260)
            {
                mtg_write_log(mtg,mtg->flogs);
                mtg->flog=0;
            }
            mtg->flogs[mtg->flog].nlog=logs[i].nlog;
            mtg->flogs[mtg->flog].t=logs[i].t;
            mtg->flogs[mtg->flog].type=logs[i].type;
            strcpy(mtg->flogs[mtg->flog].msg,logs[i].msg);
            mtg->flog++;
        }
        mtg->nlog=0;
        unlock(&mtg->loglock);
    }
    return n;
}

MTG_LOG *mtg_get_log(char* fpath,int *num)
{
    char path[260];
    char str[300];
    char stime[64];
    FILE* flog=0;
    MTG_LOG * log=0;
    int k=10;
    int i=0;
    struct tm mt;
    //FILE* fp=fopen("E:\\mtg_get_log.log","a");
    //strftime(path,260,"log/%Y-%m-%d.log",localtime(&t));
    sprintf(path,"log/");
    sprintf(path,"%s%s",path,fpath);

    if((flog=fopen(path,"r"))==NULL)         /*打开文件并判断是否出错*/
    {
        *num=0;
        return 0;
    }
    log=(MTG_LOG*)malloc(k*sizeof(MTG_LOG));
    rewind(flog);                            /*将文件指针移到首位*/
    while(!feof(flog))                        /*判断是否读到文件结束位置*/
    {
        if(i>=k)
        {
            k+=10;
            log=(MTG_LOG*)realloc(log,k*sizeof(MTG_LOG));     /*动态分配内存*/
        }
        fgets(str,300,flog);                            /*读取文件的结构数组元素*/
        sscanf(str,"%d,%d,%[^,],%[^\n]\n",&log[i].nlog,&log[i].type,stime,log[i].msg);
        sscanf(stime,"%d-%d-%d %d:%d:%d",&mt.tm_year,&mt.tm_mon,&mt.tm_mday,
                                        &mt.tm_hour,&mt.tm_min,&mt.tm_sec);
        mt.tm_year -= 1900;
        mt.tm_mon--;
        mt.tm_isdst=-1;
        log[i].t = mktime(&mt);
        i++;
    }
    *num=i-1;
    fclose(flog);
    return log;
}

#ifdef WIN32
static DWORD WINAPI _logthread(void* arg)
#else
static void *_logthread(void *arg)
#endif
{
    mtg_t* mtg=0;
    char path[260];
    char str[300];
    char stime[64];
    FILE* flog=0;
    FILE *fp=NULL;
    //FILE *fp=fopen("D:\\logthread.log","w");
    //MTG_LOG * log=0;
    int k=10;
    int i=0;
    struct tm mt;

    mtg=(mtg_t*)arg;

    sprintf(path,"log/");
    sprintf(path,"%s%s",path,mtg->fpath);

    if((flog=fopen(path,"r"))==NULL)         /*打开文件并判断是否出错*/
    {
        mtg->nolog=0;
        mtg->logthread=0;
        if(fp)
            fclose(fp);
        return 0;
    }

    mtg->nolog=0;
    if(mtg->ologs)
        free(mtg->ologs);
    mtg->ologs=NULL;

    if(fp)
    {
        fprintf(fp,"nolog:%d\n",mtg->nolog);
        fflush(fp);
    }

    rewind(flog);                            /*将文件指针移到首位*/
    while(!feof(flog))                        /*判断是否读到文件结束位置*/
    {
        fgets(str,300,flog);
        i++;
    }
    if(fp)
    {
        fprintf(fp,"number:%d\n",i);
        fflush(fp);
    }
    if(i>0)
    {
        rewind(flog);
        mtg->ologs=(MTG_LOG*)malloc(i*sizeof(MTG_LOG));
        i=0;
        while(!feof(flog) && mtg->ologs)                        /*判断是否读到文件结束位置*/
        {
            fgets(str,300,flog);                            /*读取文件的结构数组元素*/
            sscanf(str,"%d,%d,%[^,],%[^\n]\n",&mtg->ologs[i].nlog,&mtg->ologs[i].type,stime,mtg->ologs[i].msg);
            sscanf(stime,"%d-%d-%d %d:%d:%d",&mt.tm_year,&mt.tm_mon,&mt.tm_mday,
                                            &mt.tm_hour,&mt.tm_min,&mt.tm_sec);
            mt.tm_year -= 1900;
            mt.tm_mon--;
            mt.tm_isdst=-1;
            mtg->ologs[i].t = mktime(&mt);
            i++;
            if(fp)
            {
                fprintf(fp,"i:%d\n",i);
                fflush(fp);
            }
        }
    }
    mtg->nolog=i-1;
    //mtg->ologs=(MTG_LOG*)malloc(mtg->nolog*sizeof(MTG_LOG));
    //mtg->ologs=log;
    //free(log);
    fclose(flog);

    mtg->logthread=0;
    mtg_log(mtg,MTG_LOG_FINISH_GET_LOG);
    if(fp)
        fclose(fp);

    return 0;
}

int mtg_start_getlog(mtg_t* mtg)
{
    if(!mtg->logthread)
    {
    #ifdef WIN32
    if(!(mtg->logthread=CreateThread(NULL,0,_logthread,mtg,0,NULL)))
    #else
        if(pthread_create(&mtg->logthread,NULL,_logthread,mtg))
    #endif
        {
            return -1;
        }
    }
    return 0;
}
