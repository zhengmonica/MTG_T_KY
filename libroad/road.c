#include "road.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libele.h"
#include "stdio.h"
#define PI 3.1415926535897932384626433832795
#define ZERO 1.0e-12
#define WEBPC 0
/*********************局部函数***********************/
//正算，已知里程，计算坐标和切线方向
static void l2xy(h_element* h,double l,double* px,double *py,double *pori)
{
    double xi=0.0,yi=0.0;
    double alf=0.0,a=0.0,b=0.0,li=0.0;
    double x=0.0,y=0.0,beta=0.0;
    double rou1=0.0,rou2=0.0;
    //FILE* fp=fopen("E:\\l2xy.log","w");
    switch (h->type)
    {
    case ROAD_TYPE_LINE:///直线段
    case ROAD_TYPE_START_POINT:
    case ROAD_TYPE_END_POINT:
        xi=l-h->l1;
        yi=0;
        alf=0.0;
        break;
    case ROAD_TYPE_ARC:///圆曲线
        alf=(l-h->l1)/h->radius;
        xi=h->radius*sin(alf);
        yi=h->radius*(1-cos(alf));
        if (h->pz==ROAD_LEFT)
        {
            yi*=-1.0;
            alf*=-1.0;
        }
        break;
    case ROAD_TYPE_SPIRAL:///缓和曲线
        if(h->rou1>1.0e-5) rou1=1.0/h->rou1;
        if(h->rou2>1.0e-5) rou2=1.0/h->rou2;
        a=rou1;
        b=(rou2-rou1)/(2.0*h->length);
        li=l-h->l1;
        alf=a*li+b*li*li;
        xi=yi=0;
        xi= li
            - a * a/6.0*pow(li,3.0)
            - a*b/4.0*pow(li,4.0)
            + (a*a*a*a/120.0-b*b/10.0)*pow(li,5.0)
            + a*a*a*b/36.0*pow(li,6.0)
            + (-a*a*a*a*a*a/5040.0+a*a*b*b/28.0)*pow(li,7.0)
            + (-b*a*a*a*a*a/960.0+a*b*b*b/48.0)*pow(li,8.0)
            + (a*a*a*a*a*a*a*a/362880-a*a*a*a*b*b/432.0+b*b*b*b/216.0)*pow(li,9.0);
        yi = a/2.0*pow(li,2.0)
             +b/3.0*pow(li,3.0)
             -a*a*a/24.0*pow(li,4.0)
             -a*a*b/10.0*pow(li,5.0)
             +(a*a*a*a*a/720.0-a*b*b/12.0)*pow(li,6.0)
             -(b*b*b/42.0-a*a*a*a*b/168.0)*pow(li,7.0)
             +(-a*a*a*a*a*a*a/40320.0+a*a*a*b*b/96.0)*pow(li,8.0)
             +(-a*a*a*a*a*a*b/6480.0+a*a*b*b*b/108.0)*pow(li,9.0);
        if (h->pz==ROAD_LEFT)
        {
            yi*=-1.0;
            alf*=-1.0;
        }
        break;
    default:
        break;
    }
    x=h->x1+cos(h->angle1+h->deta)*xi-sin(h->angle1+h->deta)*yi;
    y=h->y1+sin(h->angle1+h->deta)*xi+cos(h->angle1+h->deta)*yi;

    beta=h->angle1+h->deta+alf;
    //fprintf(fp,"%.12f,%.12f,%.12f\n",beta,h->angle1,h->deta);
    //fflush(fp);
    while(beta<0) beta+=2*PI;
    while(beta>2*PI) beta-=2*PI;

    if(px) *px=x;
    if(py) *py=y;
    if(pori) *pori=beta;
    //fclose(fp);
}

static void l2h(v_element* v,double l,double *ph,double *pori)
{
    double h=0.0,alf=0.0,beta=0.0;
    double cx=0.0,cy=0.0;
    double hdist,sdist,theta,angle1,angle2;

    switch (v->type)
    {
    case ROAD_TYPE_START_POINT:
    case ROAD_TYPE_END_POINT:
    case ROAD_TYPE_LINE:///直线段
        h=v->h1+(l-v->l1)*tan(v->angle1+v->deta);
        beta=v->angle1+v->deta;
        break;
    case ROAD_TYPE_ARC:///圆曲线
        if(v->pz==ROAD_UP)
        {
            alf=v->angle1+v->deta-PI/2;
        }
        else
        {
            alf=v->angle1+v->deta+PI/2;
        }
        cx=v->l1+v->radius*cos(alf);
        cy=v->h1+v->radius*sin(alf);
        ///20210708whq delete the following
//        ///y=sqrt(r^2-(x-x0)^2)+y0;
//        h=sqrt(v->radius*v->radius-(l-cx)*(l-cx));
//        if(v->pz==ROAD_DOWN) h*=-1.0;
//        h+=cy;
//        alf=atan2(cy-h,cx-l);
//        if(v->pz==ROAD_UP)
//        {
//            beta=alf+PI/2;
//        }
//        else
//        {
//            beta=alf-PI/2;
//        }
////        if(v->pz==ROAD_UP)
////            beta=v->angle1-(l-v->l1)/v->radius;
        ///20210708whq add the following
        angle1=v->angle1+v->deta;
        alf=2*atan(v->T/v->radius);
        if(v->pz==ROAD_UP)
            angle2=angle1-alf;
        else
            angle2=angle1+alf;
        if(l-v->l1<=v->hd1)
        {
            hdist=l-v->l1;
            sdist=fabs(hdist)/cos(v->angle1+v->deta);
            theta=atan(sdist/v->radius);
            if(v->pz==ROAD_UP)
            {
                beta=angle1-theta;
            }
            else
            {
                beta=angle1+theta;
            }
        }
        else
        {
            hdist=l-(v->l1+v->hd1+v->hd2);
            hdist*=-1;
            sdist=fabs(hdist)/cos(angle2);
            theta=atan(sdist/v->radius);
            if(v->pz==ROAD_UP)
            {
                beta=angle2+theta;
            }
            else
            {
                beta=angle2-theta;
            }
        }

        if(v->pz==ROAD_UP)
        {
            alf=beta+PI/2;
        }
        else
        {
            alf=beta-PI/2;
        }
        h=cy+v->radius*sin(alf);
        break;
    }
    while(beta<0) beta+=2*PI;
    while(beta>2*PI) beta-=2*PI;

    if(ph) *ph=h;
    if(pori) *pori=beta;
}

///反算，已知坐标，计算线上里程,切线方位和偏移值
static void xy2l(h_element* e,double x,double y,double *pxc,double *pyc,double *pl,double *pori,double* poff)
{
    double alf,beta,dist;
    double dAcenter,dXcenter,dYcenter;
    double detl,dist1,dist2;
    double sina,cosa;
    double detX,detY;
    ///结果
    double l,xc,yc,ori;
    int iter;
//    FILE* fp=fopen("C:\\road.txt","w");
//    fprintf(fp,"l1=%.3f,l2=%.3f\n",e->l1,e->l1+e->length);
    //FILE *fp= fopen("C:\\xy2l.txt","a");
    switch (e->type)
    {
    case ROAD_TYPE_LINE:
    case ROAD_TYPE_START_POINT:
    case ROAD_TYPE_END_POINT:
        {
            alf=atan2(y-e->y1,x-e->x1);
            dist=sqrt((x-e->x1)*(x-e->x1)+(y-e->y1)*(y-e->y1))*cos(alf-e->angle1-e->deta);
            xc=e->x1+dist*cos(e->angle1+e->deta);
            yc=e->y1+dist*sin(e->angle1+e->deta);
            l=e->l1+dist;
            ori=e->angle1+e->deta;
            //bRet=1;
        }
        break;
    case ROAD_TYPE_ARC:
        {
            ///圆心坐标
            if(e->pz==ROAD_LEFT)
            {
                dAcenter=e->angle1-PI/2;
            }
            else
            {
                dAcenter=e->angle1+PI/2;
            }
            dXcenter=e->x1+e->radius*cos(dAcenter);
            dYcenter=e->y1+e->radius*sin(dAcenter);
            ///最近点
            alf=atan2(y-dYcenter,x-dXcenter);
            xc=dXcenter+e->radius*cos(alf);
            yc=dYcenter+e->radius*sin(alf);
            ///切线方位
            if (e->pz==ROAD_LEFT)
            {
                alf-=PI/2;
            }
            else
            {
                alf+=PI/2;
            }
//            while (alf<0) alf+=2*PI;
//            while (alf>2*PI) alf-=2*PI;
            ori=alf;
            beta=e->angle1;
//            while(beta<0) beta+=2*PI;
//            while(beta>2*PI) beta-=2*PI;
//            fprintf(fp,"alf=%.3f,beta=%.3f\n",alf,beta);
            beta=alf-beta;
            while(beta<0) beta+=2*PI;
            while(beta>2*PI) beta-=2*PI;
            if(e->pz==ROAD_LEFT) beta=2*PI-beta;
            l=e->l1+e->radius*fabs(beta);
//            fprintf(fp,"l=%.3f,beta=%.3f\n",l,beta);
//            fclose(fp);
            //if (e->pz==ROAD_LEFT && alf>e->angle2 && alf<e->angle1) bRet=1;
            //if (e->pz==ROAD_RIGHT && alf<e->angle2 &&  alf>e->angle1) bRet=1;
        }
        break;
    case ROAD_TYPE_SPIRAL:
        {
            dist1=sqrt((x-e->x1)*(x-e->x1)+(y-e->y1)*(y-e->y1));
            dist2=sqrt((x-e->x2)*(x-e->x2)+(y-e->y2)*(y-e->y2));
            l=e->l1+e->length*dist1/(dist1+dist2);
            ///迭代求解
            iter=0;
            while(iter<20)
            {
                l2xy(e,l,&xc,&yc,&ori);
                sina=sin(ori);
                cosa=cos(ori);
               // detl=(x-xc)+(y-yc)*tan(ori);
                detl=(x-xc)/cosa+(y-yc-(x-xc)*tan(ori))*sina;
//                fprintf(fp,"sina=%f,cosa=%f,x=%f,y=%f\n",sina,cosa,x,y);
//                fprintf(fp,"l=%f,xc=%f,yc=%f,detl=%f\n",l,xc,yc,detl);
//                fflush(fp);
                if(fabs(detl)<ZERO)
                {
                    break;
                }
                l+=detl;
                iter++;
            }
        }
        break;
    default:
        break;
    }
//    fprintf(fp,"begin\n");
//    fflush(fp);
    while(ori<0) ori+=2*PI;
    while(ori>2*PI) ori-=2*PI;
    ///录脝脣茫脝芦脪脝脕驴
    if(pxc) *pxc=xc;
    if(pyc) *pyc=yc;
    if(pl) *pl=l;
    if(pori) *pori=ori;
    if(poff)
    {
        detX=x-xc;
        detY=y-yc;
        *poff=sqrt(detX*detX+detY*detY);
        alf=atan2(detY,detX);
        while (alf<0) alf+=2*PI;
        while (alf>2*PI) alf-=2*PI;
        beta=alf-ori;
        while (beta<0) beta+=2*PI;
        while (beta>2*PI) beta-=2*PI;
        if(beta>PI) *poff*=-1;
    }
    //return bRet;
}

void road_init(road* r)
{
    h_element e={0};
    v_element e1={0};

    vpool_init(&r->he,sizeof(h_element),0);
    vpool_init(&r->ve,sizeof(v_element),0);
    vpool_init(&r->ho,sizeof(h_offset),0);
    vpool_init(&r->vo,sizeof(v_offset),0);
    vpool_init(&r->mo,sizeof(m_offset),0);

    ///添加起点终点
    e.type=ROAD_TYPE_START_POINT;
    vpool_insert(&r->he,0,&e,sizeof(h_element));
    e.type=ROAD_TYPE_END_POINT;
    vpool_insert(&r->he,sizeof(h_element),&e,sizeof(h_element));

    e1.type=ROAD_TYPE_START_POINT;
    vpool_insert(&r->ve,0,&e1,sizeof(v_element));
    e1.type=ROAD_TYPE_END_POINT;
    vpool_insert(&r->ve,sizeof(v_element),&e1,sizeof(v_element));
}

void road_init_horizon(road* r)
{
    h_element e1={0},e2={0};
    int n= road_number_horizon(r);
    e1=*(road_horizon(r,0));
    e2=*(road_horizon(r,n-1));
    road_clear_horizon(r);

    vpool_init(&r->he,sizeof(h_element),0);

    ///添加起点终点
    vpool_insert(&r->he,0,&e1,sizeof(h_element));
    vpool_insert(&r->he,sizeof(h_element),&e2,sizeof(h_element));
    road_apply_horizon(r);
}

void road_init_vertical(road* r)
{
    v_element e1={0},e2={0};
    int n= road_number_vertical(r);
    e1=*(road_vertical(r,0));
    e2=*(road_vertical(r,n-1));
    road_clear_vertical(r);

    vpool_init(&r->ve,sizeof(v_element),0);

    ///添加起点终点
    vpool_insert(&r->ve,0,&e1,sizeof(v_element));
    vpool_insert(&r->ve,sizeof(v_element),&e2,sizeof(v_element));
    road_apply_vertical(r);
}

void road_final(road* r)
{
    vpool_final(&r->he);
    vpool_final(&r->ve);
    vpool_final(&r->ho);
    vpool_final(&r->vo);
    vpool_final(&r->mo);
}

#include <stdio.h>
/**
*应用平曲线元素更改
**/
extern double road_design_mileage(road* r,double l)
{
    int nmo;
    m_offset* mo1;
    m_offset* mo2;
    int i;
    double l1=0;

    nmo=vpool_get_length(&r->mo)/sizeof(m_offset);
    if(nmo==0)
    {
        l1=l;
    }
    else
    {
        for(i=0;i<nmo;i++)
        {
            mo1=(m_offset*)vpool_get_buf(&r->mo)+i;
            if(i+1<nmo)
            {
                mo2=(m_offset*)vpool_get_buf(&r->mo)+i+1;
                if(l>=mo1->mile && l<mo2->mile)
                {
                    l1=l+mo1->off;
                    break;
                }
            }
            else
            {
                if(l>=mo1->mile)
                {
                    l1=l+mo1->off;
                }
                else
                {
                    l1=l;
                }
            }
        }
    }
    //trace(0,"road_design_mileage:mile=%.4f\n",l1);
    return l1;
}

extern double road_actual_mileage(road* r,double l)
{
    return 0;
}
/**
*应用平曲线元素更改
**/
extern int road_apply_horizon(road* r)
{
    int i,n;
    h_element *now,*pre;
#ifdef WEBPC
    /*IO_PACKAGE input,output;
    time_t t1;
    char mac[4][13];
    int nMac=0;
    int bsense=0;
    int bi;

    nMac=GetMacAddress(mac,4);
    input.tag=CMD_GET_MACHINE_ID;
    input.len=12;
    time(&t1);
    srand(t1);


    for(bi=0;bi<12;bi++)
    {
        input.buff[bi]=rand() % 255;
    }
    if(DoSense("MEDO001","STGuider",&input,&output)==1)
    {
        //trace(0,"output=%s\n",output.buff);
        for(bi=0;bi<nMac;bi++)
        {
            if(strncmp(mac[bi],(const char*)output.buff,12)==0)
            {
                bsense=1;
                break;
            }
        }
    }
    if(!bsense)
    {
        return 0;
    }*/
    ///加密
    /*IO_PACKAGE pack={0};
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
    }*/
    if(lock_sense(1,174)==0)
    {
        return -1;
    }
#endif
    n=road_number_horizon(r);

    for(i=0;i<n;i++)
    {
        now=(h_element*)vpool_get_buf(&r->he) + i;
        ///坐标，方位，里程的延续
        if(i==0)
        {
            now->x2=now->x1;
            now->y2=now->y1;
            now->angle2=now->angle1;
            now->length=0.0;
            now->radius=now->rou1=now->rou2=0.0;
        }
        else
        {
            pre=(h_element*)vpool_get_buf(&r->he) + i -1;
            now->x1=pre->x2;
            now->y1=pre->y2;
            now->angle1=pre->angle2;
            if(i==n-1) now->deta=0;
            //now->rou1=now->rou2=1.0/now->radius;
            now->l1=pre->l1+pre->length;
            l2xy(now,now->l1+now->length,&now->x2,&now->y2,&now->angle2);
        }
    }

    return 0;
}
///无加密
extern int road_apply_horizon1(road* r)
{
    int i,n;
    h_element *now,*pre;
    n=road_number_horizon(r);

    for(i=0;i<n;i++)
    {
        now=(h_element*)vpool_get_buf(&r->he) + i;
        ///坐标，方位，里程的延续
        if(i==0)
        {
            now->x2=now->x1;
            now->y2=now->y1;
            now->angle2=now->angle1;
            now->length=0.0;
            now->radius=now->rou1=now->rou2=0.0;
        }
        else
        {
            pre=(h_element*)vpool_get_buf(&r->he) + i -1;
            now->x1=pre->x2;
            now->y1=pre->y2;
            now->angle1=pre->angle2;

            //now->rou1=now->rou2=1.0/now->radius;
            now->l1=pre->l1+pre->length;
            l2xy(now,now->l1+now->length,&now->x2,&now->y2,&now->angle2);
        }
    }

    return 0;
}


/**
*增加平曲线元素
**/
extern int road_insert_horizon(road* r,h_element* h,int index)
{
    int n;

    n=road_number_horizon(r);
    if(index<0 || index>n) return -1;


    ///插入
    vpool_insert(&r->he,index*sizeof(h_element),h,sizeof(h_element));

    return 0;
}

/**
*更改平曲线元素
**/
extern int road_modify_horizon(road* r,h_element* h,int index)
{
    int n;

    n=road_number_horizon(r);
    if(index<0 || index>=n) return -1;

    ///更新
    memcpy((char*)vpool_get_buf(&r->he)+index*sizeof(h_element),h,sizeof(h_element));

    return 0;
}

/**
*删除平曲线元素
**/
extern int road_remove_horizon(road* r,int index)
{
    int n;

    n=road_number_horizon(r);
    if(index < 0 || index >= n) return -1;

    ///删除
    return vpool_truncate(&r->he,index*sizeof(h_element),sizeof(h_element),VPOOL_EXCLUDE);
}

extern void road_clear_horizon(road* r)
{
    vpool_reset(&r->he);
}

/**
*插入竖曲线元素
**/
extern int road_insert_vertical(road* r,v_element* v,int index)
{
    int n;

    n=road_number_vertical(r);
    if(index<0 || index>n) return -1;

    ///插入
    vpool_insert(&r->ve,index*sizeof(v_element),v,sizeof(v_element));
    return 0;
}

/**
*应用竖曲线更改
**/
extern int road_apply_vertical(road* r)
{
    int i,n;
    v_element *now=0,*pre=0;
    double angle1,angle2,alfa;
    FILE*fp=NULL;
    ///fp=fopen("D://road_apply_vertical.log","w");
#ifdef WEBPC
    ///加密
    if(lock_sense(1,174)==0)
    {
        return -1;
    }
#endif
    n=road_number_vertical(r);

    for(i=0;i<n;i++)
    {
        now=(v_element*)vpool_get_buf(&r->ve)+i;
        if(fp)
        {
            fprintf(fp,"l1:%.4f\n",now->l1);fflush(fp);
        }
        if(i==0)
        {
            now->l2=now->l1;
            now->h2=now->h1;
            now->angle2=now->angle1;
            now->hd=0;
        }
        else
        {
            pre=(v_element*)vpool_get_buf(&r->ve)+i-1;
            now->l1=pre->l2;
            now->h1=pre->h2;
            now->angle1=pre->angle2;
            ///20210708whq modify the following
//            now->l2=now->l1+now->length;
//            l2h(now,now->l1+now->length,&now->h2,&now->angle2);
            ///20210708whq add
            if(now->type==ROAD_TYPE_LINE)
            {
                now->hd=now->length*cos(now->angle1+now->deta);
            }
            else if(now->type==ROAD_TYPE_ARC)
            {
                angle1=now->angle1+now->deta;
                alfa=2*atan(now->T/now->radius);
                //now->length=alfa*now->radius;
                if(now->pz==ROAD_UP)
                    angle2=angle1-alfa;
                else
                    angle2=angle1+alfa;
                now->hd1=now->T*cos(angle1);
                now->hd2=now->T*cos(angle2);
                now->hd=now->hd1+now->hd2;
                now->angle2=angle2;
                if(fp)
                {
                    fprintf(fp,"T:%.4f,length:%.4f\n",now->T,now->length);
                    fprintf(fp,"now->angle1:%.4f,now->deta:%.4f,angle1:%.4f,alfa:%.4f,angle2:%.4f,slope:%.4f\n",now->angle1,now->deta,angle1,alfa,angle2,tan(now->angle2));fflush(fp);
                }
            }
            now->l2=now->l1+now->hd;
            l2h(now,now->l2,&now->h2,&angle2);
            now->angle2=angle2;
            if(fp)
            {
                fprintf(fp,"now->l1:%.4f,now->l2:%.4f,now->h2:%.4f,now->angle2:%.4f\n",now->l1,now->l2,now->h2,now->angle2);fflush(fp);
            }
        }
    }
    if(fp)
    {
        fclose(fp);
    }
    return 0;
}

///无加密
extern int road_apply_vertical1(road* r)
{
    int i,n;
    v_element *now=0,*pre=0;
    double angle1,angle2,alfa;
    FILE* fp=NULL;
    ///fp=fopen("D://road_apply_vertical1.log","w");

    n=road_number_vertical(r);

    for(i=0;i<n;i++)
    {
        now=(v_element*)vpool_get_buf(&r->ve)+i;
        if(i==0)
        {
            now->l2=now->l1;
            now->h2=now->h1;
            now->angle2=now->angle1;
        }
        else
        {
            pre=(v_element*)vpool_get_buf(&r->ve)+i-1;
            now->l1=pre->l2;
            now->h1=pre->h2;
            now->angle1=pre->angle2;
//            now->l2=now->l1+now->length;
//            l2h(now,now->l1+now->length,&now->h2,&now->angle2);
            ///20210708whq add
            if(now->type==ROAD_TYPE_LINE)
            {
                now->hd=now->length*cos(now->angle1+now->deta);
            }
            else if(now->type==ROAD_TYPE_ARC)
            {
                angle1=now->angle1+now->deta;
                alfa=2*atan(now->T/now->radius);
                //now->length=alfa*now->radius;
                if(now->pz==ROAD_UP)
                    angle2=angle1-alfa;
                else
                    angle2=angle1+alfa;
                now->hd1=now->T*cos(angle1);
                now->hd2=now->T*cos(angle2);
                now->hd=now->hd1+now->hd2;
                now->angle2=angle2;
//                if(fp)
//                {
//                    fprintf(fp,"now->angle1:%.4f,now->deta:%.4f,angle1:%.4f,alfa:%.4f,angle2:%.4f,slope:%.4f\n",now->angle1,now->deta,angle1,alfa,angle2,tan(now->angle2));fflush(fp);
//                }
            }
            now->l2=now->l1+now->hd;
            l2h(now,now->l2,&now->h2,&angle2);
            now->angle2=angle2;
//            if(fp)
//            {
//                fprintf(fp,"now->l2:%.4f,now->h2:%.4f,now->angle2:%.4f",now->l2,now->h2,now->angle2);fflush(fp);
//            }
        }
    }
    if(fp)
        fclose(fp);
    return 0;
}

/**
*删除竖曲线元素
**/
extern int road_remove_vertical(road* r,int index)
{
    int n;

    n=road_number_vertical(r);
    if(index < 0 || index >= n) return -1;

    ///删除
    return vpool_truncate(&r->ve,index*sizeof(v_element),sizeof(v_element),VPOOL_EXCLUDE);
}

/**
*更改竖曲线元素
**/
extern int road_modify_vertical(road* r,v_element* v,int index)
{
    int n;

    n=road_number_vertical(r);
    if(index<0 || index>=n) return -1;

    ///更新
    memcpy((char*)vpool_get_buf(&r->ve)+index*sizeof(v_element),v,sizeof(v_element));

    return 0;
}

/**
*清空竖曲线
**/
extern void road_clear_vertical(road* r)
{
    ///清空
    vpool_reset(&r->ve);
}

/**
*获取平曲线元素
**/
extern h_element* road_horizon(road* r,int index)
{
    int n=0;
    n=road_number_horizon(r);
    if(index<0 || index>=n) return 0;
    return (h_element*)vpool_get_buf(&r->he)+index;
}

/**
*获取平曲线元素及序号
**/
extern h_element* road_horizon_chain(road* r,double l,int* index)
{
    int n=0;
    h_element* e=0;
    double minl,maxl;
    int i;
    n=road_number_horizon(r);
    if(n<=2)
    {
        return 0;
    }
    else
    {
        e=road_horizon(r,0);
        minl=e->l1;
        e=road_horizon(r,n-1);
        maxl=e->l1+e->length;
        if(l<minl)
        {
            e=road_horizon(r,0);
            if(index) *index=0;
        }
        else if(l>maxl)
        {
            e=road_horizon(r,n-1);
            if(index) *index=n-1;
        }
        else
        {
            for(i=1;i<n;i++)
            {
                e=road_horizon(r,i);
                if(l>=e->l1 && l<=e->l1+e->length)
                {
                    break;
                }
            }
            if(i<=n)
            {
                e=road_horizon(r,i);
                if(index) *index=i;
            }
        }
    }
    return e;
}
/**
*获取竖曲线元素
**/
extern v_element* road_vertical(road* r,int index)
{
    int n=0;
    n=road_number_vertical(r);
    if(index<0 || index>=n) return 0;
    return (v_element*)vpool_get_buf(&r->ve)+index;
}
/**
*获取竖曲线元素及序号
**/
extern v_element* road_vertical_chain(road* r,double l,int* index)
{
    int n=0;
    v_element* e=0;
    double minl,maxl;
    int i;
    n=road_number_vertical(r);
    if(n<=2)
    {
        e=0;
        if(index) *index=0;
    }
    else
    {
        e=road_vertical(r,0);
        minl=e->l1;
        e=road_vertical(r,n-1);
        maxl=e->l1+e->length;
        if(l<minl)
        {
            e=road_vertical(r,0);
            if(index) *index=0;
        }
        else if(l>maxl)
        {
            e=road_vertical(r,n-1);
            if(index) *index=n-1;
        }
        else
        {
            for(i=1;i<n;i++)
            {
                e=road_vertical(r,i);
                if(l>=e->l1 && l<=e->l1+e->length)
                {
                    break;
                }
            }
            if(i<=n)
            {
                e=road_vertical(r,i);
                if(index) *index=i;
            }
        }
    }
    return e;
}
/**
*平曲线元素个数
**/
extern int road_number_horizon(road* r)
{
    return vpool_get_length(&r->he)/sizeof(h_element);
}

/**
*竖曲线元素个数
**/
extern int road_number_vertical(road* r)
{
    return vpool_get_length(&r->ve)/sizeof(v_element);
}


/******************偏移**********************/
/**
*平曲线偏移个数
**/
extern int road_number_horizon_off(road* r)
{
    return vpool_get_length(&r->ho)/sizeof(h_offset);
}

/**
*获取平曲线偏移
**/
extern h_offset* road_horizon_off(road* r,int index)
{
    int n;
    n=road_number_horizon_off(r);
    if(index<0 || index >=n) return 0;
    return (h_offset*)vpool_get_buf(&r->ho)+index;
}
/**
*插入平曲线偏移
**/
extern int road_insert_horizon_off(road* r,h_offset* off)
{
    int i,n;
    n=road_number_horizon_off(r);
    for(i=0;i<n;i++)
    {
        if(road_horizon_off(r,i)->mile>=off->mile) break;
    }
    vpool_insert(&r->ho,i*sizeof(h_offset),off,sizeof(h_offset));

    return 0;
}

/**
*修改平曲线偏移
**/
extern int road_modify_horizon_off(road* r,h_offset* off,int index)
{
    int n;
    n=road_number_horizon_off(r);
    if(index<0 || index>=n) return -1;
    memcpy(road_horizon_off(r,index),off,sizeof(h_offset));
    return 0;
}
/**
*删除平曲线偏移
**/
extern int road_erase_horizon_off(road* r,int index)
{
    int n;
    n=road_number_horizon_off(r);
    if(index<0 || index>=n) return -1;
    vpool_truncate(&r->ho,index*sizeof(h_offset),sizeof(h_offset),VPOOL_EXCLUDE);
    return 0;
}

/**
*清空平曲线偏移
**/
extern int road_clear_horizon_off(road* r)
{
    int n;
    n=road_number_horizon_off(r);
    vpool_truncate(&r->ho,0,n*sizeof(h_offset),VPOOL_EXCLUDE);
    return 0;
}
/**
*竖曲线偏移个数
**/
extern int road_number_vertical_off(road* r)
{
    return vpool_get_length(&r->vo)/sizeof(v_offset);
}

/**
*获取竖曲线偏移
**/
extern v_offset* road_vertical_off(road* r,int index)
{
    int n;
    n=road_number_vertical_off(r);
    if(index<0 || index >=n) return 0;
    return (v_offset*)vpool_get_buf(&r->vo)+index;
}
/**
*插入竖曲线偏移
**/
extern int road_insert_vertical_off(road* r,v_offset* off)
{
    int i,n;
    n=road_number_vertical_off(r);
    for(i=0;i<n;i++)
    {
        if(road_vertical_off(r,i)->mile>=off->mile) break;
    }
    vpool_insert(&r->vo,i*sizeof(v_offset),off,sizeof(v_offset));

    return 0;
}

/**
*修改竖曲线偏移
**/
extern int road_modify_vertical_off(road* r,v_offset* off,int index)
{
    int n;
    n=road_number_vertical_off(r);
    if(index<0 || index>=n) return -1;
    memcpy(road_vertical_off(r,index),off,sizeof(v_offset));
    return 0;
}
/**
*删除竖曲线偏移
**/
extern int road_erase_vertical_off(road* r,int index)
{
    int n;
    n=road_number_vertical_off(r);
    if(index<0 || index>=n) return -1;
    vpool_truncate(&r->vo,index*sizeof(v_offset),sizeof(v_offset),VPOOL_EXCLUDE);
    return 0;
}

/**
*清空竖曲线偏移
**/
extern int road_clear_vertical_off(road* r)
{
    int n;
    n=road_number_vertical_off(r);
    vpool_truncate(&r->vo,0,n*sizeof(v_offset),VPOOL_EXCLUDE);
    return 0;
}

/**
*里程偏移个数
**/
extern int road_number_mile_off(road* r)
{
    return vpool_get_length(&r->mo)/sizeof(m_offset);
}

/**
*获取里程偏移
**/
extern v_offset* road_mile_off(road* r,int index)
{
    int n;
    n=road_number_mile_off(r);
    if(index<0 || index >=n) return 0;
    return (m_offset*)vpool_get_buf(&r->mo)+index;
}

/**
*插入里程偏移
**/
extern int road_insert_mile_off(road* r,m_offset* off)
{
    int i,n;
    n=road_number_mile_off(r);
    for(i=0;i<n;i++)
    {
        if(road_mile_off(r,i)->mile>=off->mile) break;
    }
    vpool_insert(&r->mo,i*sizeof(m_offset),off,sizeof(m_offset));

    return 0;
}

/**
*修改里程偏移
**/
extern int road_modify_mile_off(road* r,m_offset* off,int index)
{
    int n;
    n=road_number_mile_off(r);
    if(index<0 || index>=n) return -1;
    memcpy(road_mile_off(r,index),off,sizeof(m_offset));
    return 0;
}

/**
*删除里程偏移
**/
extern int road_erase_mile_off(road* r,int index)
{
    int n;
    n=road_number_mile_off(r);
    if(index<0 || index>=n) return -1;
    vpool_truncate(&r->mo,index*sizeof(m_offset),sizeof(m_offset),VPOOL_EXCLUDE);
    return 0;
}

/**
*清空里程偏移
**/
extern int road_clear_mile_off(road* r)
{
    int n;
    n=road_number_mile_off(r);
    vpool_truncate(&r->mo,0,n*sizeof(m_offset),VPOOL_EXCLUDE);
    return 0;
}

/************线路计算************************/
/**
*道路正算
*/
extern int road_l2xy(road* r,double l,double* px,double *py,double* pori)
{
    int n;
	h_element* e=0;
	int i,j;
	double x,y,t;
	double minl,maxl;
	///平曲线偏移值
	double hoff=0;
	h_offset* p1,*p2;
	int ret=-1;
    //FILE* fp=fopen("E:\\road_l2xy.log","w");

	n=road_number_horizon(r);
	if(n<2) return -1;

    e=road_horizon(r,0);
    minl=e->l1;
    e=road_horizon(r,n-1);
    maxl=e->l1+e->length;
    //fprintf(fp,"%.4f,%.4f,%.4f\n",minl,maxl,l);
    //fflush(fp);
    if(l<=minl)
    {
        e=road_horizon(r,0);
        x=e->x1+(l-e->l1)*cos(e->angle1);
        y=e->y1+(l-e->l1)*sin(e->angle1);
        t=e->angle1;
        ret=0;
    }
    else if(l>=maxl)
    {
        e=road_horizon(r,n-1);
        x=e->x2+(l-e->l1-e->length)*cos(e->angle2);
        y=e->y2+(l-e->l1-e->length)*sin(e->angle2);
        t=e->angle2;
        if(px) *px=x;
        if(py) *py=y;
        if(pori) *pori=t;
        ret = n-1;
    }
    else
    {
        for(i=1;i<n-1;i++)
        {
            e=road_horizon(r,i);
            //fprintf(fp,"%d,%.4f,%.4f\n",i,e->l1,e->l1+e->length);
            //fflush(fp);
            if(l>=e->l1 && l<=e->l1+e->length)
            {
                break;
            }
        }
        //fprintf(fp,"%d\n",i);
        //fflush(fp);
        if(i<n-1)
        {
            e=road_horizon(r,i);
            //fprintf(fp,"%.4f\n",e->deta);
            //fflush(fp);
            l2xy(e,l,&x,&y,&t);
            ret=i;
        }
    }
    //fprintf(fp,"%d\n",0);
    //fflush(fp);
     ///偏移
    for(j=0;j<road_number_horizon_off(r);j++)
    {
        p1=road_horizon_off(r,j);
        p2=road_horizon_off(r,j+1);
        if(j<road_number_horizon_off(r)-1)
        {
            if(l>=p1->mile && l<=p2->mile)
            {
                hoff=p1->off+(p2->off-p1->off)*(l-p1->mile)/(p2->mile-p1->mile);
                x+=hoff*cos(t+PI/2);
                y+=hoff*sin(t+PI/2);
                //fprintf(fp,"%d\n",1);
                //fflush(fp);
                break;
            }
        }
        else if(j == road_number_horizon_off(r)-1)
        {
            if(l>=p1->mile)
            {
                hoff=p1->off;
                x+=hoff*cos(t+PI/2);
                y+=hoff*sin(t+PI/2);

                //fflush(fp);
                break;
            }
        }
        /*if(l>=p1->mile && l<=p2->mile)
        {
            hoff=p1->off+(p2->off-p1->off)*(l-p1->mile)/(p2->mile-p1->mile);
            x+=hoff*cos(t+PI/2);
            y+=hoff*sin(t+PI/2);
            //fprintf(fp,"%d\n",1);
            //fflush(fp);
            break;
        }*/
    }
    //fprintf(fp,"%d\n",1);
    //fflush(fp);
    //fprintf(fp,"%d\n",road_number_horizon_off(r));
    if(px) *px=x;
    if(py) *py=y;
    if(pori) *pori=t;
    //close(fp);
    return ret;
}

extern int road_lo2xy(road* r,double l,double off,double* px,double *py,double* pori)
{
    double x0=0.0,y0=0.0,ori=0.0,x,y;

    road_l2xy(r,l,&x0,&y0,&ori);
    x=x0+off*cos(ori+PI/2);
    y=y0+off*sin(ori+PI/2);

    if(px) *px=x;
    if(py) *py=y;
    if(pori) *pori=ori;
    return 0;
}

/**
*道路反算
**/
extern int road_xy2l(road* r,double x,double y,double* pl,double* pcx,double *pcy,double *pori,double* poff)
{
    double l,xc,yc,orient,off;
    double alf,beta;
	vpool es;
	h_element* e;
	int i,n,j;
	int theItor=-1;
    double theDist=0.0,dist;
    double x1,y1,x2,y2;
    double ext=100.0; ///延长100米
    h_offset *p1,*p2;
    double hoff=0.0;
    double dist1,dist2;
    double maxr=0.0;
    //FILE* fp=fopen("E:\\xy2l.log","a");

    n=road_number_horizon(r);

    if(n<=2) return -1;

    vpool_init(&es,sizeof(int),0);

    ///在元素中寻找
    for(i=0;i<n;i++)
    {
		e=road_horizon(r,i);
		if(i==0)
        {
            x1=e->x1-ext*cos(e->angle1);
            y1=e->y1-ext*sin(e->angle1);
            x2=e->x2;y2=e->y2;
        }
        else if(i==n-1)
        {
            x2=e->x2+ext*cos(e->angle1);
            y2=e->y2+ext*sin(e->angle1);
            x1=e->x1;y1=e->y1;
        }
        else
        {
            x1=e->x1;y1=e->y1;
            x2=e->x2;y2=e->y2;
        }
        dist1 = sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
        dist2 = sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));

        if(e->type==3)
        {
            maxr = (e->rou1>e->rou2) ?e->rou1:e->rou2;
            if((dist1>maxr)&&(dist2>maxr))
            {
                continue;
            }
        }
//		///点与元素起始点方位的夹角
//        alf=atan2(y-y1,x-x1)-e->angle1;
//        beta=atan2(y-y2,x-x2)-e->angle2;
//        ///角度归化到0-2*PI之间
//        while(alf<0) alf+=2*PI;
//        while(alf>2*PI) alf-=2*PI;
//        while(beta<0) beta+=2*PI;
//        while(beta>2*PI) beta-=2*PI;
//
//        ///判断点是否落在第一、四象限
//        if(fabs(alf-PI)>=PI/2 && fabs(beta-PI)<=PI/2 )
//        {
//            vpool_insert(&es,vpool_get_length(&es),&i,sizeof(int));
//        }
		///点与元素起止点方位的夹角
        alf=atan2(y-y1,x-x1)-e->angle1+PI/2;
        beta=atan2(y-y2,x-x2)-e->angle2+PI/2;
        ///角度化算到-PI---PI之间
        while(alf>PI) alf-=2*PI;
        while(alf<-PI) alf+=2*PI;
        while(beta>PI) beta-=2*PI;
        while(beta<-PI) beta+=2*PI;
        ///判断方位角是否介于两者之间

//        fprintf(fp,"i=%d,alf=%f,beta=%f\n",i,alf,beta);
//        fflush(fp);
        if(alf*beta<0)
        {
            vpool_insert(&es,vpool_get_length(&es),&i,sizeof(int));
        }
    }

    if(vpool_is_empty(&es))
    {
        vpool_final(&es);
        return -1;
    }

	n=vpool_get_length(&es)/sizeof(int);

	///在备选项中选出偏移最小的元素作为目标元素
    for(i=0;i<n;i++)
    {
        j=*((int*)vpool_get_buf(&es)+i);
		e=road_horizon(r,j);
		xy2l(e,x,y,&xc,&yc,&l,&orient,&off);
		dist=fabs(off);
       // dist=(x-(e->x1+e->x2)/2.0)*(x-(e->x1+e->x2)/2.0)+(y-(e->y1+e->y2)/2.0)*(y-(e->y1+e->y2)/2.0);

        if(i==0 || dist<theDist)
        {
            theItor=j;
            theDist=dist;
        }
    }
    if(theItor>=0)
	{
	    e=road_horizon(r,theItor);
		xy2l(e,x,y,&xc,&yc,&l,&orient,&off);

		 ///偏移
        for(j=0;j<road_number_horizon_off(r)-1;j++)
        {
            p1=road_horizon_off(r,j);
            p2=road_horizon_off(r,j+1);
            if(l>=p1->mile && l<=p2->mile)
            {
                hoff=p1->off+(p2->off-p1->off)*(l-p1->mile)/(p2->mile-p1->mile);
                xc+=hoff*cos(orient+PI/2);
                yc+=hoff*sin(orient+PI/2);
                off-=hoff;
                break;
            }
        }

        if(pcx) *pcx=xc;
        if(pcy) *pcy=yc;
        if(pl) *pl=l;
        if(pori) *pori=orient;
        if(poff) *poff=off;
	}
    //fprintf(fp,"%off:%.4f\n",off);
	//fclose(fp);

	vpool_final(&es);
	return theItor;
}

/**
*高程正算
**/
extern int road_l2h(road* r,double l,double *ph,double *pori)
{
    int n;
	v_element* e=0;
	int i,j;
	double h,t;
	double minl,maxl;
	double voff=0;
	v_offset* p1,*p2;
	int ret=-1;
    FILE* fp;
	//fp=fopen("D:\\road_l2h.log","a");

	n=road_number_vertical(r);
	if(n<=1) return -1;

	minl=road_vertical(r,0)->l1;
	maxl=road_vertical(r,n-1)->l2;

	if(l<=minl)  ///反向延长
    {
        e=road_vertical(r,0);
        h=e->h1+(l-e->l1)*tan(e->angle1);
        t=e->angle1;
        ret=0;
    }
    else if(l>=maxl)  ///尾部延长
    {
        e=road_vertical(r,n-1);
        h=e->h2+(l-e->l2)*tan(e->angle2);
        t=e->angle2;
        ret=n-1;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            e=road_vertical(r,i);
            if(l>=e->l1 && l<=e->l2)
            {
                break;
            }
        }

        if(i<n)
        {
            e=road_vertical(r,i);
            l2h(e,l,&h,&t);
            ret=i;
        }
    }

     ///偏移
    for(j=0;j<road_number_vertical_off(r);j++)
    {
        p1=road_vertical_off(r,j);
        p2=road_vertical_off(r,j+1);
        if(j<road_number_vertical_off(r)-1)
        {
            if(l>=road_vertical_off(r,j)->mile && l<=road_vertical_off(r,j+1)->mile)
            {
                //fprintf(fp,"nvoff=%d,j=%d,l1=%.4f,l2=%.4f\n",road_number_vertical_off(r),j,road_vertical_off(r,j)->mile,road_vertical_off(r,j+1)->mile);
                voff=p1->off+(p2->off-p1->off)*(l-p1->mile)/(p2->mile-p1->mile);
                h+=voff;
                break;
            }
        }
        else if(j==road_number_vertical_off(r)-1)
        {
            if(l>=road_vertical_off(r,j)->mile)
            {

                voff=p1->off;
                h+=voff;
                break;
            }
        }

        /*if(l>=road_vertical_off(r,j)->mile && l<=road_vertical_off(r,j+1)->mile)
        {

            voff=p1->off+(p2->off-p1->off)*(l-p1->mile)/(p2->mile-p1->mile);
            h+=voff;
            break;
        }*/
    }
    if(ph) *ph=h;
    if(pori) *pori=t;
    //fclose(fp);
    return ret;
}
