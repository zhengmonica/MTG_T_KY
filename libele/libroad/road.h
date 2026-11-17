/***************************************************************
 * Name:      road.h
 * Purpose:   Code for Road Center Line
 * Author:    dengdeyan (dengdeyan@medosurvey.com)
 * Created:   2010-12-28
 * Copyright: dengdeyan (http://www.medosurvey.com)
 * License:
 **************************************************************/

#ifndef ROAD_H_INCLUDED
#define ROAD_H_INCLUDED

#include "vpool.h"

#ifdef WIN32
#ifdef LIBROAD_MAKINGDLL
#define LIBROAD_API __declspec(dllexport)
#else
#define LIBROAD_API __declspec(dllimport)
#endif
#else
#define LIBROAD_API
#endif

#ifdef __cplusplus
extern "C"
{
#endif

///元素类型
enum
{
    ROAD_TYPE_START_POINT=0, ///起点
    ROAD_TYPE_LINE=1,        ///直线
    ROAD_TYPE_ARC=2,         ///圆曲线
    ROAD_TYPE_SPIRAL=3,      ///缓和曲线
    ROAD_TYPE_END_POINT=4    ///终点
};

///圆曲线偏转方向
enum
{
    ROAD_LEFT=0,    ///左偏
    ROAD_RIGHT=1    ///右偏
};
enum
{
    ROAD_UP=0,      ///凸
    ROAD_DOWN=1     ///凹
};

typedef struct h_element  ///平曲线要素
{
    int type;       ///元素类型
    double radius;  ///圆曲线半径
    double rou1;    ///起点曲率半径
    double rou2;    ///终点曲率半径
    double x1;      ///起点坐标
    double y1;
    double x2;      ///终点坐标
    double y2;
    double angle1;  ///起点方位
    double angle2;  ///终点方位
    double l1;      ///起点里程
    double length;  ///曲线长度
    int pz;         ///偏转方向
    double deta;    ///方位角修正值
}h_element;

typedef struct v_element
{
    int type;       ///元素类型
    double radius;  ///圆曲线半径
    double l1;      ///起点坐标
    double h1;
    double l2;      ///终点坐标
    double h2;
    double angle1;  ///起点方位
    double angle2;  ///终点方位
    double length;  ///曲线长度
    int pz;         ///偏转方向
    double deta;    ///坡度修正值
}v_element;


typedef struct offset  ///偏移
{
    double mile;       ///里程
    double off;        ///偏移量
}h_offset;

typedef struct offset v_offset;

typedef struct road
{
    vpool he;  ///平曲线元素
    vpool ve;  ///竖曲线元素
    vpool ho;  ///平曲线偏移
    vpool vo;  ///竖曲线偏移
}road;


/*****************内存管理******************/
///内存初始化
extern void LIBROAD_API road_init(road* r);
extern void LIBROAD_API road_init_horizon(road* r);
extern void LIBROAD_API road_init_vertical(road* r);
///内存释放
extern void LIBROAD_API road_final(road* r);
/*****************曲线要素******************/
extern int LIBROAD_API road_insert_horizon(road* r,h_element* h,int index);
extern int LIBROAD_API road_modify_horizon(road* r,h_element* h,int index);
extern int  LIBROAD_API road_remove_horizon(road* r,int index);
extern void LIBROAD_API road_clear_horizon(road* r);
extern int  LIBROAD_API road_apply_horizon(road* r);
extern int LIBROAD_API road_number_horizon(road* r);
extern LIBROAD_API h_element* road_horizon(road* r,int index);
extern LIBROAD_API h_element* road_horizon_chain(road* r,double l,int* index);
extern int LIBROAD_API road_insert_vertical(road* r,v_element* v,int index);
extern int LIBROAD_API road_modify_vertical(road* r,v_element* v,int index);
extern int LIBROAD_API road_remove_vertical(road* r,int index);
extern void LIBROAD_API road_clear_vertical(road* r);
extern int LIBROAD_API road_apply_vertical(road* r);
extern LIBROAD_API v_element* road_vertical(road* r,int index);
extern LIBROAD_API v_element* road_vertical_chain(road* r,double,int* index);
extern int LIBROAD_API road_number_vertical(road* r);

/******************偏移**********************/
extern int LIBROAD_API road_number_horizon_off(road* r);
extern LIBROAD_API h_offset* road_horizon_off(road* r,int index);
extern int LIBROAD_API road_insert_horizon_off(road* r,h_offset* off);
extern int LIBROAD_API road_modify_horizon_off(road* r,h_offset* off,int index);
extern int LIBROAD_API road_erase_horizon_off(road* r,int index);
extern int LIBROAD_API road_clear_horizon_off(road* r);
extern int LIBROAD_API road_number_vertical_off(road* r);
extern LIBROAD_API v_offset* road_vertical_off(road* r,int index);
extern int LIBROAD_API road_insert_vertical_off(road* r,v_offset* off);
extern int LIBROAD_API road_modify_vertical_off(road* r,v_offset* off,int index);
extern int LIBROAD_API road_erase_vertical_off(road* r,int index);
extern int LIBROAD_API road_clear_vertical_off(road* r);
/************线路计算************************/
extern int LIBROAD_API road_l2xy(road* r,double l,double* px,double *py,double* pori);
extern int LIBROAD_API road_lo2xy(road* r,double l,double off,double* px,double* py,double* pori);
extern int LIBROAD_API road_xy2l(road* r,double x,double y,double* pl,double* pcx,double *pcy,double *pori,double* poff);
extern int LIBROAD_API road_l2h(road* r,double l,double *ph,double *pori);
/************输入输出************************/
extern int LIBROAD_API road_import_file(road* r,char* path);
extern int LIBROAD_API road_export_file(road* r,char* path);

#ifdef __cplusplus
}
#endif

#endif // ROAD_H_INCLUDED
