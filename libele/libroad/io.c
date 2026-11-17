#include "road.h"
#include "sqlite3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libele.h"

/**
*导入文件
**/
extern int road_import_file(road* r,char* path)
{
    sqlite3 *db;
    int rc;
    char cmd[260];
    sqlite3_stmt * stmt;
    h_element h;
    v_element v;
    h_offset ho;
    v_offset vo;
    int index;

    IO_PACKAGE pack={0};
    time_t t1,t2,ts,tf;

    ///加密
    pack.tag=CMD_GET_TIME;
    time(&t1);

    if(DoSense("MEDO001","STGuider",&pack,&pack)==1)
    {

        memcpy(&t2,pack.buff,4);
        memcpy(&ts,pack.buff+4,4);
        memcpy(&tf,pack.buff+8,4);

        if(abs(t2-t1)>24*3600) return -1;
        if(t2-ts>=tf) return -1;
    }
    else
    {
        return -1;
    }

    road_clear_horizon(r);
    road_clear_vertical(r);
    road_clear_horizon_off(r);
    road_clear_vertical_off(r);

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }

    ///版本控制
//    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);
//    strcpy(cmd,"alter table horizon add deta;");
//    sqlite3_exec(db,cmd,0,0,0);
//    strcpy(cmd,"alter table vertical add deta;");
//    sqlite3_exec(db,cmd,0,0,0);
//    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);

    //平曲线
    strcpy(cmd,"select * from horizon;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    index=0;
    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        h.type=sqlite3_column_int(stmt,0);
        h.l1=sqlite3_column_double(stmt,1);
        h.length=sqlite3_column_double(stmt,2);
        h.angle1=sqlite3_column_double(stmt,3);
        h.angle2=sqlite3_column_double(stmt,4);
        h.radius=sqlite3_column_double(stmt,5);
        h.rou1=sqlite3_column_double(stmt,6);
        h.rou2=sqlite3_column_double(stmt,7);
        h.x1=sqlite3_column_double(stmt,8);
        h.y1=sqlite3_column_double(stmt,9);
        h.x2=sqlite3_column_double(stmt,10);
        h.y2=sqlite3_column_double(stmt,11);
        h.pz=sqlite3_column_int(stmt,12);
        h.deta=sqlite3_column_double(stmt,13);
        road_insert_horizon(r,&h,index++);
    }
    sqlite3_finalize(stmt);
    //竖曲线
    strcpy(cmd,"select * from vertical;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    index=0;
    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        v.type=sqlite3_column_int(stmt,0);
        v.l1=sqlite3_column_double(stmt,1);
        v.h1=sqlite3_column_double(stmt,2);
        v.l2=sqlite3_column_double(stmt,3);
        v.h2=sqlite3_column_double(stmt,4);
        v.length=sqlite3_column_double(stmt,5);
        v.radius=sqlite3_column_double(stmt,6);
        v.angle1=sqlite3_column_double(stmt,7);
        v.angle2=sqlite3_column_double(stmt,8);
        v.pz=sqlite3_column_double(stmt,9);
        v.deta=sqlite3_column_double(stmt,10);
        road_insert_vertical(r,&v,index++);
    }
    sqlite3_finalize(stmt);
    //平曲线偏移
    strcpy(cmd,"select * from hoff;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    index=0;
    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        ho.mile=sqlite3_column_double(stmt,0);
        ho.off=sqlite3_column_double(stmt,1);
        road_insert_horizon_off(r,&ho);
    }
    sqlite3_finalize(stmt);
    //竖曲线偏移
    strcpy(cmd,"select * from voff;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    index=0;
    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        vo.mile=sqlite3_column_double(stmt,0);
        vo.off=sqlite3_column_double(stmt,1);
        road_insert_vertical_off(r,&vo);
    }
    sqlite3_finalize(stmt);

	sqlite3_close(db);
    return 0;
}

/**
*导出文件
**/
extern int road_export_file(road* r,char* path)
{
    sqlite3 *db;
    int rc;
    char cmd[1024];
    int i,n;
    h_element* he;
    v_element* ve;
    h_offset* ho;
    v_offset* vo;

    IO_PACKAGE pack={0};
    time_t t1,t2,ts,tf;

    ///加密
    pack.tag=CMD_GET_TIME;
    time(&t1);

    if(DoSense("MEDO001","STGuider",&pack,&pack)==1)
    {

        memcpy(&t2,pack.buff,4);
        memcpy(&ts,pack.buff+4,4);
        memcpy(&tf,pack.buff+8,4);

        if(abs(t2-t1)>24*3600) return -1;
        if(t2-ts>=tf) return -1;
    }
    else
    {
        return -1;
    }

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }

    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

    ///版本控制
    strcpy(cmd,"alter table horizon add deta");
    sqlite3_exec(db,cmd,0,0,0);
    strcpy(cmd,"alter table vertical add deta");
    sqlite3_exec(db,cmd,0,0,0);

    ///创建表
    //平曲线表
    strcpy(cmd,"create table if not exists horizon(type,l1,length,angle1,angle2,radius,rou1,rou2,x1,y1,x2 ,y2,pz,deta);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    //竖曲线表
    strcpy(cmd,"create table if not exists vertical(type,l1,h1,l2,h2,length,radius,angle1,angle2,pz,deta);");
    rc = sqlite3_exec(db,  cmd, 0, 0, 0);
    //平曲线偏移表
    strcpy(cmd,"create table if not exists hoff(mile,off);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    //竖曲线偏移表
    strcpy(cmd,"create table if not exists voff(mile,off);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    //横断面模板
    strcpy(cmd,"create table if not exists model(id,name);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"create table if not exists node(oid ,hoff ,slope );");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    //横断面表
    strcpy(cmd,"create table if not exists section(mile1,mile2,mod);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    //支路表
    strcpy(cmd,"create table if not exists feeder(name,n1,n2,n3,n4,l0,l1,l2,r1,a1,off1,r2,a2,off2,det0,det1,det2,alf,e1,e2,e3,de_type);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"create table if not exists fele(nf ,nd ,np,ele );");
    sqlite3_exec(db,  cmd, 0, 0, 0);


    ///存储
    sqlite3_exec(db,"delete from  horizon",0,0,0);   ///平曲线
    n=road_number_horizon(r);
    for(i=0;i<n;i++)
    {
        he=road_horizon(r,i);
        sprintf(cmd,"insert into horizon values(\
                %d,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%d,%.12f)",
                he->type,he->l1,he->length,he->angle1,he->angle2,
                he->radius,he->rou1,he->rou2,
                he->x1,he->y1,he->x2,he->y2,he->pz,he->deta);
        sqlite3_exec(db,cmd,0,0,0);
    }
    sqlite3_exec(db,"delete from  vertical",0,0,0);  ///竖曲线
    n=road_number_vertical(r);
    for(i=0;i<n;i++)
    {
        ve=road_vertical(r,i);
        sprintf(cmd,"insert into vertical values(\
                %d,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%d,%.12f)",
                ve->type,ve->l1,ve->h1,ve->l2,ve->h2,
                ve->length,ve->radius,ve->angle1,ve->angle2,ve->pz,ve->deta);
        sqlite3_exec(db,cmd,0,0,0);
    }
    sqlite3_exec(db,"delete from  hoff",0,0,0);  ///平曲线偏移
    n=road_number_horizon_off(r);
    for(i=0;i<n;i++)
    {
        ho=road_horizon_off(r,i);
        sprintf(cmd,"insert into hoff values(%.12f,%.12f)",ho->mile,ho->off);
        sqlite3_exec(db,cmd,0,0,0);
    }
    sqlite3_exec(db,"delete from  voff",0,0,0);  ///竖曲线偏移
    n=road_number_vertical_off(r);
    for(i=0;i<n;i++)
    {
        vo=road_vertical_off(r,i);
        sprintf(cmd,"insert into voff values(%.12f,%.12f)",vo->mile,vo->off);
        sqlite3_exec(db,cmd,0,0,0);
    }

    sqlite3_exec(db,  "commit transaction", 0, 0, 0);
    sqlite3_close(db);
    return 0;
}
