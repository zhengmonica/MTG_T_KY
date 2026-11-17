#include "libmtg.h"
#include "geometry.h"
#include "trace.h"
#include "mysql/mysql.h"
#include <stdio.h>

#define PI  3.1415926535897932384626433832795

static double aziSurvey[10]={0};
static double aziSort[10]={0};
static int nazi=0;

double AddAzi(double azi)
{
    int i,j;
    double val=0.0;

    if(nazi<10)
    {
        aziSurvey[nazi]=azi;
        nazi++;
    }
    else
    {
        for(i=0;i<9;i++)
        {
            aziSurvey[i]=aziSurvey[i+1];
        }
        aziSurvey[9]=azi;
    }
    for(i=0;i<nazi;i++)
        aziSort[i]=aziSurvey[i];
    ///排序找中位数
    for(i=nazi-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(aziSort[j]>aziSort[j+1])
            {
                val=aziSort[j];
                aziSort[j]=aziSort[j+1];
                aziSort[j+1]=val;
            }
        }
    }
    if(nazi % 2 == 0)    ///偶数
    {
        i=nazi/2;
        j=i-1;
        val=(aziSort[i]+aziSort[j])/2.0;
    }
    else
    {
        i=nazi/2;
        val=aziSort[i];
    }

    return val;
}


///原修正代码
//roll=atan(tan(roll)/sqrt(1-pow(tan(pitch)*tan(roll),2.0))/cos(pitch));
///现改为
//roll=atan(tan(roll)/cos(pitch));
/**
            **************************
             **  ) |roll     **
              *  )*|        *-*  ---pitch
     roll1     *)  *       *  *
                *    *    *   *
                 *    *  *    *  ---a
                  *     *     *
                   *   * *    *
                    * *    *  *
                     **********
     -->tan(roll1)=(a/cos(pitch))/(a/tan(roll));
     -->roll1=atan(tan(roll)/cos(pitch));
**/
extern int mtg_cal_origin(mtg_t* mtg)
{
    double pitch,roll,ori;
    transform3d_t trans;
    double len;
    point3d_t head,tail,left,mppsm1,mppsm2,mppsm3;
    double phi,omega,kapa;
    double inc[3];
    double dx,dy,dz;
    double ilen;

    MTG_MEASURE* m0=0;
    FILE* fp=fopen("D:\\midu\\cal_origin.log","a");
    m0=&mtg->m0;

    len=sqrt((m0->head[0]-m0->tail[0])*(m0->head[0]-m0->tail[0])+(m0->head[1]-m0->tail[1])*(m0->head[1]-m0->tail[1]));
    if(len<=1.0e-6) return -1;

    if(mtg->tarset.baseinc==1)
    {
        inc[0]=m0->inc[5]*PI/180.0;
        inc[1]=m0->inc[6]*PI/180.0;
    }
    else
    {
        inc[0]=m0->inc[0]*PI/180.0;
        inc[1]=m0->inc[1]*PI/180.0;
    }
    inc[2]=m0->inc[2]*PI/180.0;

    ///将坐标系变换到激光耙坐标系下（原点在棱镜中心，以激光耙中轴线为X轴，激光耙平面向右为Y轴，向上为Z轴）
    head.x=m0->head[0];
    head.y=m0->head[1];
    head.z=m0->head[2];
    tail.x=m0->tail[0];
    tail.y=m0->tail[1];
    tail.z=m0->tail[2];
    mppsm1.x=mtg->mp.prism[0];
    mppsm1.y=mtg->mp.prism[1];
    mppsm1.z=mtg->mp.prism[2];
    mppsm2.x=mtg->mp.prism[3];
    mppsm2.y=mtg->mp.prism[4];
    mppsm2.z=mtg->mp.prism[5];
    mppsm3.x=mtg->mp.prism[6];
    mppsm3.y=mtg->mp.prism[7];
    mppsm3.z=mtg->mp.prism[8];
    ///盾构机滚动角基准点转换到大地坐标系
    left.x=0.0;
    left.y=100.0;
    left.z=0.0;
    phi=m0->inc1[0]*PI/180.0;
    omega=atan((m0->head[2]-m0->tail[2])/len);
    kapa=atan2(m0->head[1]-m0->tail[1],m0->head[0]-m0->tail[0]);
    if(kapa<0.0) kapa=kapa+2.0*PI;
    m0->inc1[1]=omega*180.0/PI;
    m0->inc1[2]=kapa*180.0/PI;
    ///
    transform3d_init(&trans,phi,omega,-kapa,m0->tail[0],m0->tail[1],m0->tail[2],1);
    transform3d_trans(&trans,&left,&left);

    ///将盾首，盾尾，滚动基准点转换到激光耙坐标系
    phi=inc[0];
    omega=inc[1];
    kapa=inc[2];
    transform3d_init(&trans,phi,omega,-kapa,m0->prism[0],m0->prism[1],m0->prism[2],1);
    transform3d_revtrans(&trans,&head,&head);
    transform3d_revtrans(&trans,&tail,&tail);
    transform3d_revtrans(&trans,&left,&left);
    transform3d_revtrans(&trans,&mppsm1,&mppsm1);
    transform3d_revtrans(&trans,&mppsm2,&mppsm2);
    transform3d_revtrans(&trans,&mppsm3,&mppsm3);

    ///零位数据赋值
    mtg->head[0]=head.x;
    mtg->head[1]=head.y;
    mtg->head[2]=head.z;
    mtg->tail[0]=tail.x;
    mtg->tail[1]=tail.y;
    mtg->tail[2]=tail.z;
    mtg->left[0]=left.x;
    mtg->left[1]=left.y;
    mtg->left[2]=left.z;
    mtg->mppsm1[0]=mppsm1.x;
    mtg->mppsm1[1]=mppsm1.y;
    mtg->mppsm1[2]=mppsm1.z;
    mtg->mppsm2[0]=mppsm2.x;
    mtg->mppsm2[1]=mppsm2.y;
    mtg->mppsm2[2]=mppsm2.z;
    mtg->mppsm3[0]=mppsm3.x;
    mtg->mppsm3[1]=mppsm3.y;
    mtg->mppsm3[2]=mppsm3.z;

    dx=head.x-tail.x;
    dy=head.y-tail.y;
    dz=head.z-tail.z;
    ilen=dx*dx+dy*dy+dz*dz;
    mtg->ilen=sqrt(ilen);

    //20180409whq增加下面内容
    if(mtg->m0.ipos!=mtg->tarset.ipos&&(mtg->m0.ipos>=0&&mtg->tarset.ipos>=0))
    {
        dx=(mtg->tarset.prism[mtg->m0.ipos*3+0]-mtg->tarset.prism[mtg->tarset.ipos*3+0])/1000.0;
        dy=(mtg->tarset.prism[mtg->m0.ipos*3+1]-mtg->tarset.prism[mtg->tarset.ipos*3+1])/1000.0;
        dz=(mtg->tarset.prism[mtg->m0.ipos*3+2]-mtg->tarset.prism[mtg->tarset.ipos*3+2])/1000.0;
        mtg->head[0]+=dx;
        mtg->head[1]+=dy;
        mtg->head[2]+=dz;
        mtg->tail[0]+=dx;
        mtg->tail[1]+=dy;
        mtg->tail[2]+=dz;
        mtg->left[0]+=dx;
        mtg->left[1]+=dy;
        mtg->left[2]+=dz;
        mtg->mppsm1[0]+=dx;
        mtg->mppsm1[1]+=dy;
        mtg->mppsm1[2]+=dz;
        mtg->mppsm2[0]+=dx;
        mtg->mppsm2[1]+=dy;
        mtg->mppsm2[2]+=dz;
        mtg->mppsm3[0]+=dx;
        mtg->mppsm3[1]+=dy;
        mtg->mppsm3[2]+=dz;
    }
    //trace(0,"given:headx=%f,heady=%f,headz=%f\n",head.x,head.y,head.z);
    //trace(0,"given:tailx=%f,taily=%f,tailz=%f\n",tail.x,tail.y,tail.z);
    //trace(0,"given:leftx=%f,lefty=%f,leftz=%f\n",left.x,left.y,left.z);
    //trace(0,"given:prismx=%f,prismy=%f,prismz=%f\n",mppsm3.x,mppsm3.y,mppsm3.z);
    if(fp)
    {
        fprintf(fp,"dx=%f,dy=%f,dz=%f\n",dx,dy,dz);
        fprintf(fp,"given:headx=%f,heady=%f,headz=%f\n",head.x,head.y,head.z);
        fprintf(fp,"given:tailx=%f,taily=%f,tailz=%f\n",tail.x,tail.y,tail.z);
        fprintf(fp,"given:leftx=%f,lefty=%f,leftz=%f\n",left.x,left.y,left.z);
        fprintf(fp,"mtg:headx=%f,heady=%f,headz=%f\n",mtg->head[0],mtg->head[1],mtg->head[2]);
        fprintf(fp,"mtg:tailx=%f,taily=%f,tailz=%f\n",mtg->tail[0],mtg->tail[1],mtg->tail[2]);
        fprintf(fp,"mtg:leftx=%f,lefty=%f,leftz=%f\n",mtg->left[0],mtg->left[1],mtg->left[2]);
        //fprintf(fp,"given:prismx=%f,prismy=%f,prismz=%f\n",mppsm3.x,mppsm3.y,mppsm3.z);
        fclose(fp);
    }

    return 0;
}

extern int mtg_std_fj_hzshj(mtg_t* mtg,double* res);
extern int mtg_laser_gesture(mtg_t* mtg)
{
    double phi,roll,ori;
    transform3d_t trans;
    point3d_t pt1,pt2,datum;
    double len=0.0;
    point3d_t head,tail,left,prism;
    double inc[3];
    point2d_t u1,u2;
    affine_t aff;
    MTG_MEASURE* m=0;
    double d1,d2;
    int a2z=mtg->prj.a2z;
    int op=mtg->onduty;
    double ires[3];
    time_t t;
    double temp=0;
    FILE* fp=fopen("D:\\midu\\mtgcal.log","a");

    m=&mtg->m;
    ///m->inc[0]在测量线程里更新数据
    ///m->inc[1]在测量线程里更新数据
    ///m->inc[2]mtg_laser_incline函数里更新数据
    if(mtg->tarset.baseinc==1)
    {
        inc[0]=m->inc[5]*PI/180.0;
        inc[1]=m->inc[6]*PI/180.0;
    }
    else
    {
        inc[0]=m->inc[0]*PI/180.0;
        inc[1]=m->inc[1]*PI/180.0;
    }
    ///侧转
    roll=inc[0];
    ///俯仰
    phi=inc[1];
    ///修正滚动角
    roll=atan(tan(roll)/cos(phi));
    transform3d_init(&trans,roll,phi,0,0,0,0,1);

    ori=m->inc[2]*PI/180.0;
    ///激光耙坐标系转到大地坐标系
    transform3d_init(&trans,roll,phi,-ori,m->prism[0],m->prism[1],m->prism[2],1);
    if(fp)
    {
        fprintf(fp,"roll:%.6f,phi:%.6f,ori:%.6f\n",roll,phi,ori);
        fflush(fp);
        fprintf(fp,"prism:%.6f,%.6f,%.6f\n",m->prism[0],m->prism[1],m->prism[2]);
        fflush(fp);
    }
    //trace(0,"mtg_laser_gesture inc:%.12f,%.12f,%.12f\n",roll,phi,ori);

    head.x=mtg->head[0];
    head.y=mtg->head[1];
    head.z=mtg->head[2];
    tail.x=mtg->tail[0];
    tail.y=mtg->tail[1];
    tail.z=mtg->tail[2];
    left.x=mtg->left[0];
    left.y=mtg->left[1];
    left.z=mtg->left[2];
    //trace(0,"cal_head:%f,%f,%f\n",head.x,head.y,head.z);
    //trace(0,"cal_tail:%f,%f,%f\n",tail.x,tail.y,tail.z);
    //trace(0,"cal_left:%f,%f,%f\n",left.x,left.y,left.z);
    if(fp)
    {
        fprintf(fp,"head:%.6f,%.6f,%.6f\n",mtg->head[0],mtg->head[1],mtg->head[2]);
        fflush(fp);
        fprintf(fp,"tail:%.6f,%.6f,%.6f\n",mtg->tail[0],mtg->tail[1],mtg->tail[2]);
        fflush(fp);
        fprintf(fp,"left:%.6f,%.6f,%.6f\n",mtg->left[0],mtg->left[1],mtg->left[2]);
        fflush(fp);
    }

    transform3d_trans(&trans,&head,&head);
    transform3d_trans(&trans,&tail,&tail);
    transform3d_trans(&trans,&left,&left);
    if(fp)
    {
        fprintf(fp,"headx:%.6f,heady:%.6f,headz:%.6f\n",head.x,head.y,head.z);
        fflush(fp);
        fprintf(fp,"tailx:%.6f,taily:%.6f,tailz:%.6f\n",tail.x,tail.y,tail.z);
        fflush(fp);
        fprintf(fp,"leftx:%.6f,lefty:%.6f,leftz:%.6f\n",left.x,left.y,left.z);
        fflush(fp);
    }
    d1 = point3d_dist(&head,&tail);
    d2 = sqrt((left.x-tail.x)*(left.x-tail.x)+(left.y-tail.y)*(left.y-tail.y));

    m->inc1[1]=atan((head.z-tail.z)/d1);
    m->inc1[0]=-atan((left.z-tail.z)/d2);
    m->inc1[0]=atan(tan(m->inc1[0])/cos(m->inc1[1]));
    m->inc1[2]=atan2(head.y-tail.y,head.x-tail.x);
    if(m->inc1[2]<0.0) m->inc1[2] = m->inc1[2]+2*PI;
    phi=m->inc1[1];
    ori=m->inc1[2];
    m->inc1[0]=m->inc1[0]*180.0/PI;
    m->inc1[1]=m->inc1[1]*180.0/PI;
    m->inc1[2]=m->inc1[2]*180.0/PI;
    if(fp)
    {
        fprintf(fp,"inc1:%.6f,%.6f,%.6f\n",m->inc1[0],m->inc1[1],m->inc1[2]);
        fflush(fp);
    }

    m->head[0]=head.x;
    m->head[1]=head.y;
    m->head[2]=head.z;
    if(mtg->iset.head==1)
    {
        if(mtg->tbm.type<2)
        {
            m->head[0]=m->head[0]+mtg->tbm.L[8]*cos(phi)*cos(ori);
            m->head[1]=m->head[1]+mtg->tbm.L[8]*cos(phi)*sin(ori);
            m->head[2]=m->head[2]+mtg->tbm.L[8]*sin(phi);
        }
        else if(mtg->tarset.pos==0)
        {
            m->head[0]=m->head[0]+mtg->tbm.L[8]*cos(phi)*cos(ori);
            m->head[1]=m->head[1]+mtg->tbm.L[8]*cos(phi)*sin(ori);
            m->head[2]=m->head[2]+mtg->tbm.L[8]*sin(phi);
        }
    }
    m->tail[0]=tail.x;
    m->tail[1]=tail.y;
    m->tail[2]=tail.z;



    ///偏差计算
    road_xy2l(&mtg->r,m->head[0],m->head[1],&m->headc,&m->hdes[0],&m->hdes[1],&mtg->azidesign,&m->headh);
    road_l2h(&mtg->r,m->headc,&m->hdes[2],0);
    m->headv=m->head[2]-m->hdes[2];
    road_xy2l(&mtg->r,m->tail[0],m->tail[1],&m->tailc,&m->tdes[0],&m->tdes[1],0,&m->tailh);
    road_l2h(&mtg->r,m->tailc,&m->tdes[2],0);
    m->tailv=m->tail[2]-m->tdes[2];


    if(m->headc<m->tailc)
    {
        if(mtg->prj.a2z==1)
        {
            mtg->prj.a2z=-1;
            mtg_store_prj(mtg);
        }
        if(mtg->prj.mile1<mtg->prj.mile2)
        {
            temp=mtg->prj.mile1;
            mtg->prj.mile1=mtg->prj.mile2;
            mtg->prj.mile2=temp;
            mtg_store_prj(mtg);
        }
    }
    else if(m->headc>m->tailc)
    {
        if(mtg->prj.a2z==-1)
        {
            mtg->prj.a2z=1;
            mtg_store_prj(mtg);
        }
        if(mtg->prj.mile1>mtg->prj.mile2)
        {
            temp=mtg->prj.mile1;
            mtg->prj.mile1=mtg->prj.mile2;
            mtg->prj.mile2=temp;
            mtg_store_prj(mtg);
        }
    }
    a2z=mtg->prj.a2z;

    m->headh=m->headh*a2z;
    m->tailh=m->tailh*a2z;


    ///前盾、尾盾计算（20160512）
    if(mtg->tbm.type>0)
    {
        mtg_cal_tbm(mtg);
    }
    else
    {
        m->mile1=m->headc;
        m->hdev1=m->headh;
        m->vdev1=m->headv;
        m->mile2=(m->headc+m->tailc)/2.0;
        m->hdev2=(m->headh+m->tailh)/2.0;
        m->vdev2=(m->headv+m->tailv)/2.0;
        m->mile3=m->tailc;
        m->hdev3=m->tailh;
        m->vdev3=m->tailv;
        m->ht[0]=0;
        m->ht[1]=0;
        m->ht[2]=0;
        m->htdes[0]=0;
        m->htdes[1]=0;
        m->htdes[2]=0;
    }

    if(fp)
    {
        fprintf(fp,"head:%.6f,%.6f,%.6f,    headc:%.6f,headh:%.6f,headv:%.6f\n",m->head[0],m->head[1],m->head[2],m->headc,m->headh,m->headv);
        fflush(fp);
        fprintf(fp,"tail:%.6f,%.6f,%.6f,    tailc:%.6f,tailh:%.6f,tailv:%.6f\n",m->tail[0],m->tail[1],m->tail[2],m->tailc,m->tailh,m->tailv);
        fflush(fp);
    }

    if(mtg->duty[op].t1<=0)
    {
        time(&t);
        mtg->duty[op].t1=t;
        mtg->duty[op].seg1=m->iseg;
        mtg->duty[op].mile1=m->headc;
        mtg->duty[op].t2=t;
        mtg->duty[op].seg2=m->iseg;
        mtg->duty[op].mile2=m->headc;
        mtg_edit_duty(mtg);
    }
    else
    {
        time(&t);
        mtg->duty[op].t2=t;
        mtg->duty[op].seg2=m->iseg;
        mtg->duty[op].mile2=m->headc;
        mtg_edit_duty(mtg);
    }

    ///环号
    if(mtg->snum.mile==0.0)
    {
        mtg->snum.mile=m->headc;
        mtg_store_snum(mtg);
    }

    ///20180112whq修改，mtg->iset.rget为0表示根据PLC近似计算，1表示根据里程近似计算，2暂时不考虑，以后会取消
    if(mtg->itbm>1 && mtg->iset.rget==0)///20180112whq修改，将if(mtg->itbm>1)改成if(mtg->itbm>1&&mtg->iset.rget==0)，原因是原先的代码不支持环号的计算方式设置
    {
        if(mtg->plc.drive)
        {
            mtg_std_aj(mtg,ires);

            if(mtg->tbm.type<2) d1=mtg->tbm.L[3];
            else d1=mtg->tbm.L[3]-mtg->tbm.L[0];
            d1=d1-ires[2];
            ori=m->inc1[2]*PI/180.0;
            phi=m->inc1[1]*PI/180.0;
            mtg->sazi=ori+ires[0];
            mtg->sphi=phi+ires[1];
            ori=ori+PI;
            phi=-phi;
            mtg->segx=m->head[0]+d1*cos(phi)*cos(ori);
            mtg->segy=m->head[1]+d1*cos(phi)*sin(ori);
            mtg->segz=m->head[2]+d1*sin(phi);
            mtg->segok=1;
        }
        m->iseg = mtg->snum.iseg;
        mtg->snum.tm=(m->headc-mtg->snum.mile)*mtg->prj.a2z;
    }
    else
    {
        mtg->snum.tm=(m->headc-mtg->snum.mile)*mtg->prj.a2z;
        m->iseg=mtg->snum.iseg+mtg->snum.tm/mtg->segset.L;

        //fprintf(fp,"\nheadc:%.4f,snum.mile:%.4f\n",m->headc,mtg->snum.mile);
        //fprintf(fp,"m->iseg:%d,snum.iseg:%d,tm:%.4f,L:%.4f\n",m->iseg,mtg->snum.iseg,mtg->snum.tm,mtg->segset.L);
        //m->iseg = mtg->snum.iseg+(m->headc-mtg->snum.mile)/mtg->segset.L;
        //mtg->snum.tm=fabs(m->headc-mtg->snum.mile)-m->iseg*mtg->segset.L;
        ///20180112whq添加下面的代码
        if(mtg->snum.tm>=mtg->segset.L)
        {
            mtg->snum.iseg=m->iseg;
            mtg->snum.mile=mtg->snum.mile+(floor)(mtg->snum.tm/mtg->segset.L)*(mtg->segset.L)/**mtg->prj.a2z*/;
            mtg_store_snum(mtg);
            //fprintf(fp,"store_snum:snum.mile:%.4f,snum.iseg:%d,tm:%.4f,L:%.4f\n",mtg->snum.mile,mtg->snum.iseg,mtg->snum.tm,mtg->segset.L);
        }
        ///20180112whq添加结束
    }

//    mtg->m.aj[0]=mtg->m1.aj[0];
//    mtg->m.aj[1]=mtg->m1.aj[1];
//    mtg->m.aj[2]=mtg->m1.aj[2];
//    mtg->m.aj[3]=mtg->m1.aj[3];
//
//    mtg->m.faj[0]=mtg->m1.faj[0];
//    mtg->m.faj[1]=mtg->m1.faj[1];
//    mtg->m.faj[2]=mtg->m1.faj[2];
//    mtg->m.faj[3]=mtg->m1.faj[3];
//
//    mtg->m.baj[0]=mtg->m1.baj[0];
//    mtg->m.baj[1]=mtg->m1.baj[1];
//    mtg->m.baj[2]=mtg->m1.baj[2];
//    mtg->m.baj[3]=mtg->m1.baj[3];

    //trace(0,"head:%f,%f,%f\n",m->head[0],m->head[1],m->head[2]);
    //trace(0,"tail:%f,%f,%f\n",m->tail[0],m->tail[1],m->tail[2]);
    //trace(0,"pitch:%.12f,roll:%.12f,azimuth:%.12f\n",m->rpa[1],m->rpa[0],m->rpa[2]);

    fclose(fp);

    return 0;
}

extern int mtg_cal_prism_coord(mtg_t *mtg,int ipos)
{
    point3d_t pt1,pt2;
    transform3d_t trans;
    double roll,pitch,ori;
    if(mtg->m1.t1>0)
    {
        if(mtg->tarset.baseinc==1)
        {
            roll=mtg->m1.inc[5]*PI/180.0;
            pitch=mtg->m1.inc[6]*PI/180.0;
        }
        else
        {
            roll=mtg->m1.inc[0]*PI/180.0;
            pitch=mtg->m1.inc[1]*PI/180.0;
        }
        roll=atan(tan(roll)/(cos(pitch)+0.0000000001));
        road_xy2l(&mtg->r,mtg->m.prism[0],mtg->m.prism[1],0,0,0,&ori,0);
        if(mtg->prj.a2z==-1)
        {
            ori = ori+PI;
            if(ori>2*PI) ori=ori-2*PI;
        }
        pt1.x=-mtg->tarset.prism[ipos*3]/1000.0+mtg->tarset.prism[mtg->tarset.ipos*3]/1000.0;
        pt1.y=-mtg->tarset.prism[ipos*3+1]/1000.0+mtg->tarset.prism[mtg->tarset.ipos*3+1]/1000.0;
        pt1.z=-mtg->tarset.prism[ipos*3+2]/1000.0+mtg->tarset.prism[mtg->tarset.ipos*3+2]/1000.0;

        transform3d_init(&trans,roll,pitch,-ori,0.0,0.0,0.0,1.0);
        transform3d_trans(&trans,&pt1,&pt2);
        mtg->m1.prism[0]=mtg->m1.prism[0]+pt2.x;
        mtg->m1.prism[1]=mtg->m1.prism[1]+pt2.x;
        mtg->m1.prism[2]=mtg->m1.prism[2]+pt2.x;
        mtg->m=mtg->m1;
        mtg_store_meas(mtg);
    }
    return 0;
}

extern int mtg_cal_tbm(mtg_t* mtg)
{
    double inc[3];
    double len1;
    double ix0,iy0,iz0;
    double ires[3]={0,0,0};
    double ori,phi;

    MTG_MEASURE* m=0;
    //FILE* fp=fopen("D:\\mtg_cal_tbm.log","w");
    m=&mtg->m;
    inc[1]=m->inc1[1]*PI/180.0;
    inc[2]=m->inc1[2]*PI/180.0;
    //trace(0,"mtg_cal_tbm:type=%d,pos=%d,phi=%.12f,ori=%.12f\n",mtg->tbm.type,mtg->tarset.pos,inc[1],inc[2]);
    if(mtg->tbm.type==1)
    {
        if(mtg->iset.symtype==0)
        {
            mtg_std_bj(mtg,ires);
        }
        else if(mtg->iset.symtype==1)
        {
            mtg_std_bj_sym(mtg,ires);
        }

        phi=-inc[1];
        ori=inc[2]+PI;
        if(mtg->iset.head==1) len1=mtg->tbm.L[6]+mtg->tbm.L[7]+mtg->tbm.L[8]-ires[2];
        else len1=mtg->tbm.L[6]+mtg->tbm.L[7]-ires[2];
        ix0=m->head[0]+len1*cos(phi)*cos(ori);
        iy0=m->head[1]+len1*cos(phi)*sin(ori);
        iz0=m->head[2]+len1*sin(phi);
        phi=inc[1]+ires[1];
        ori=inc[2]+ires[0];
        len1=mtg->tbm.L[6]+mtg->tbm.L[7]-mtg->tbm.L[0];
        m->head2[0]=ix0+len1*cos(phi)*cos(ori);
        m->head2[1]=iy0+len1*cos(phi)*sin(ori);
        m->head2[2]=iz0+len1*sin(phi);
        m->inc3[1]=phi*180.0/PI;
        m->inc3[2]=ori*180.0/PI;
        m->inc3[0]=m->inc1[0];

        phi=-phi;
        ori=ori+PI;
        len1=mtg->tbm.L[2];
        m->tail2[0]=m->head2[0]+len1*cos(phi)*cos(ori);
        m->tail2[1]=m->head2[1]+len1*cos(phi)*sin(ori);
        m->tail2[2]=m->head2[2]+len1*sin(phi);

        road_xy2l(&mtg->r,m->head2[0],m->head2[1],&m->headc2,&m->hdes2[0],&m->hdes2[1],0,&m->headh2);
        road_l2h(&mtg->r,m->headc2,&m->hdes2[2],0);
        m->headv2=m->head2[2]-m->hdes2[2];
        road_xy2l(&mtg->r,m->tail2[0],m->tail2[1],&m->tailc2,&m->tdes2[0],&m->tdes2[1],0,&m->tailh2);
        road_l2h(&mtg->r,m->tailc2,&m->tdes2[2],0);
        m->tailv2=m->tail2[2]-m->tdes2[2];

        m->headh2=m->headh2*mtg->prj.a2z;
        m->tailh2=m->tailh2*mtg->prj.a2z;

        m->mile1=m->headc;
        m->hdev1=m->headh;
        m->vdev1=m->headv;
        m->mile2=m->tailc;
        m->hdev2=m->tailh;
        m->vdev2=m->tailv;
        m->mile3=m->tailc2;
        m->hdev3=m->tailh2;
        m->vdev3=m->tailv2;
        m->ht[0]=m->tail2[0];
        m->ht[1]=m->tail2[1];
        m->ht[2]=m->tail2[2];
        m->htdes[0]=m->tdes2[0];
        m->htdes[1]=m->tdes2[1];
        m->htdes[2]=m->tdes2[2];
    }
    else if(mtg->tbm.type==2)
    {
//        #ifdef ZHONGMEI
//        mtg_std_fj_hzshj(mtg,ires);
//        #else
//        mtg_std_fj(mtg,ires);
//        #endif // ZHONGMEI

        if(mtg->iset.symtype==0)
            mtg_std_fj(mtg,ires);
        else if(mtg->iset.symtype==1)
            mtg_std_fj_sym(mtg,ires);
        else if(mtg->iset.symtype==2)
            mtg_std_fj_hzshj(mtg,ires);

        if(mtg->tarset.pos==0)
        {
            phi=-inc[1];
            ori=inc[2]+PI;
            if(mtg->iset.head==1) len1=mtg->tbm.L[4]+mtg->tbm.L[8];
            else len1=mtg->tbm.L[4];
            ix0=m->head[0]+len1*cos(phi)*cos(ori);
            iy0=m->head[1]+len1*cos(phi)*sin(ori);
            iz0=m->head[2]+len1*sin(phi);
            inc[1]=inc[1]-ires[1];
            inc[2]=inc[2]-ires[0];
            phi=-inc[1];
            ori=inc[2]+PI;
            len1=mtg->tbm.L[4]+mtg->tbm.L[5]-mtg->ilen+ires[2];
            m->head2[0]=ix0+len1*cos(phi)*cos(ori);
            m->head2[1]=iy0+len1*cos(phi)*sin(ori);
            m->head2[2]=iz0+len1*sin(phi);
            m->inc3[1]=inc[1]*180.0/PI;
            m->inc3[2]=inc[2]*180.0/PI;
            m->inc3[0]=m->inc1[0];

            len1=mtg->tbm.L[2];
            m->tail2[0]=m->head2[0]+len1*cos(phi)*cos(ori);
            m->tail2[1]=m->head2[1]+len1*cos(phi)*sin(ori);
            m->tail2[2]=m->head2[2]+len1*sin(phi);

            road_xy2l(&mtg->r,m->head2[0],m->head2[1],&m->headc2,&m->hdes2[0],&m->hdes2[1],0,&m->headh2);
            road_l2h(&mtg->r,m->headc2,&m->hdes2[2],0);
            m->headv2=m->head2[2]-m->hdes2[2];
            road_xy2l(&mtg->r,m->tail2[0],m->tail2[1],&m->tailc2,&m->tdes2[0],&m->tdes2[1],0,&m->tailh2);
            road_l2h(&mtg->r,m->tailc2,&m->tdes2[2],0);
            m->tailv2=m->tail2[2]-m->tdes2[2];

            m->headh2=m->headh2*mtg->prj.a2z;
            m->tailh2=m->tailh2*mtg->prj.a2z;

            m->mile1=m->headc;
            m->hdev1=m->headh;
            m->vdev1=m->headv;
            m->mile2=m->tailc;
            m->hdev2=m->tailh;
            m->vdev2=m->tailv;
            m->mile3=m->tailc2;
            m->hdev3=m->tailh2;
            m->vdev3=m->tailv2;
            m->ht[0]=m->tail2[0];
            m->ht[1]=m->tail2[1];
            m->ht[2]=m->tail2[2];
            m->htdes[0]=m->tdes2[0];
            m->htdes[1]=m->tdes2[1];
            m->htdes[2]=m->tdes2[2];
        }
        else if(mtg->tarset.pos==1)
        {
            phi=inc[1];
            ori=inc[2];
            len1=mtg->tbm.L[0]-mtg->tbm.L[4]+ires[2];
            //fprintf(fp,"mtg_cal_tbm:len1=%.4f,dh=%.12f,dv=%.12f,d=%.4f\n",len1,ires[0],ires[1],ires[2]);
            //fprintf(fp,"mtg_cal_tbm:ori=%.4f,phi=%.4f\n",ori,phi);
            //trace(0,"mtg_cal_tbm:dh=%.12f,dv=%.12f,d=%.4f\n",ires[0],ires[1],ires[2]);
            ix0=m->head[0]+len1*cos(phi)*cos(ori);
            iy0=m->head[1]+len1*cos(phi)*sin(ori);
            iz0=m->head[2]+len1*sin(phi);
            //fprintf(fp,"mtg_cal_tbm:x0=%.4f,y0=%.4f,z0=%.4f\n",ix0,iy0,iz0);
            //fprintf(fp,"mtg_cal_tbm:headx=%.4f,heady=%.4f,headz=%.4f\n",m->head[0],m->head[1],m->head[2]);
            //trace(0,"mtg_cal_tbm:x0=%.4f,y0=%.4f,z0=%.4f\n",ix0,iy0,iz0);
            phi=inc[1]+ires[1];
            ori=inc[2]+ires[0];
            //fprintf(fp,"mtg_cal_tbm:ori=%.4f,phi=%.4f\n",ori,phi);
            if(mtg->iset.head==1) len1=mtg->tbm.L[4]+mtg->tbm.L[8];
            else len1=mtg->tbm.L[4];
            //trace(0,"mtg_cal_tbm:phi=%.12f,ori=%.12f,len=%.4f\n",phi,ori,len1);
            m->head1[0]=ix0+len1*cos(phi)*cos(ori);
            m->head1[1]=iy0+len1*cos(phi)*sin(ori);
            m->head1[2]=iz0+len1*sin(phi);
            //fprintf(fp,"mtg_cal_tbm:len=%.4f,headx=%.4f,heady=%.4f,headz=%.4f\n",len1,m->head1[0],m->head1[1],m->head1[2]);
            //trace(0,"mtg_cal_tbm:headx=%.4f,heady=%.4f,headz=%.4f\n",m->head1[0],m->head1[1],m->head1[2]);
            m->inc2[1]=phi*180.0/PI;
            m->inc2[2]=ori*180.0/PI;
            m->inc2[0]=m->inc1[0];

            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[0];
            //trace(0,"mtg_cal_tbm:phi=%.12f,ori=%.12f,len=%.4f\n",phi,ori,len1);
            m->tail1[0]=m->head1[0]+len1*cos(phi)*cos(ori);
            m->tail1[1]=m->head1[1]+len1*cos(phi)*sin(ori);
            m->tail1[2]=m->head1[2]+len1*sin(phi);
            //fprintf(fp,"mtg_cal_tbm:len=%.4f,tailx=%.4f,taily=%.4f,tailz=%.4f\n",len1,m->tail1[0],m->tail1[1],m->tail1[2]);
            //trace(0,"mtg_cal_tbm:tailx=%.4f,taily=%.4f,tailz=%.4f\n",m->tail1[0],m->tail1[1],m->tail1[2]);
            road_xy2l(&mtg->r,m->head1[0],m->head1[1],&m->headc1,&m->hdes1[0],&m->hdes1[1],0,&m->headh1);
            road_l2h(&mtg->r,m->headc1,&m->hdes1[2],0);
            m->headv1=m->head1[2]-m->hdes1[2];
            road_xy2l(&mtg->r,m->tail1[0],m->tail1[1],&m->tailc1,&m->tdes1[0],&m->tdes1[1],0,&m->tailh1);
            road_l2h(&mtg->r,m->tailc1,&m->tdes1[2],0);
            m->tailv1=m->tail1[2]-m->tdes1[2];
            //fprintf(fp,"hdes1=%.4f\n",m->hdes1[2]);
            m->headh1=m->headh1*mtg->prj.a2z;
            m->tailh1=m->tailh1*mtg->prj.a2z;

            m->mile1=m->headc1;
            m->hdev1=m->headh1;
            m->vdev1=m->headv1;
            m->mile2=m->headc;
            m->hdev2=m->headh;
            m->vdev2=m->headv;
            m->mile3=m->tailc;
            m->hdev3=m->tailh;
            m->vdev3=m->tailv;
            m->ht[0]=m->head1[0];
            m->ht[1]=m->head1[1];
            m->ht[2]=m->head1[2];
            m->htdes[0]=m->hdes1[0];
            m->htdes[1]=m->hdes1[1];
            m->htdes[2]=m->hdes1[2];
        }
    }
    else if(mtg->tbm.type==3)
    {
        if(mtg->tarset.pos==0)
        {
            phi=-inc[1];
            ori=inc[2]+PI;
            if(mtg->iset.head==1) len1=mtg->tbm.L[4]+mtg->tbm.L[8];
            else len1=mtg->tbm.L[4];
            ix0=m->head[0]+len1*cos(phi)*cos(ori);
            iy0=m->head[1]+len1*cos(phi)*sin(ori);
            iz0=m->head[2]+len1*sin(phi);
            inc[1]=inc[1]-ires[1];
            inc[2]=inc[2]-ires[0];
            phi=-inc[1];
            ori=inc[2]+PI;
            len1=mtg->ilen-mtg->tbm.L[4]+ires[2];
            m->head1[0]=ix0+len1*cos(phi)*cos(ori);
            m->head1[1]=iy0+len1*cos(phi)*sin(ori);
            m->head1[2]=iz0+len1*sin(phi);
            m->inc2[1]=inc[1]*180.0/PI;
            m->inc2[2]=inc[2]*180.0/PI;
            m->inc2[0]=m->inc1[0];

            len1=mtg->tbm.L[2];
            m->tail1[0]=m->head1[0]+len1*cos(phi)*cos(ori);
            m->tail1[1]=m->head1[1]+len1*cos(phi)*sin(ori);
            m->tail1[2]=m->head1[2]+len1*sin(phi);

            road_xy2l(&mtg->r,m->head1[0],m->head1[1],&m->headc1,&m->hdes1[0],&m->hdes1[1],0,&m->headh1);
            road_l2h(&mtg->r,m->headc1,&m->hdes1[2],0);
            m->headv1=m->head1[2]-m->hdes1[2];
            road_xy2l(&mtg->r,m->tail1[0],m->tail1[1],&m->tailc1,&m->tdes1[0],&m->tdes1[1],0,&m->tailh1);
            road_l2h(&mtg->r,m->tailc1,&m->tdes1[2],0);
            m->tailv1=m->tail1[2]-m->tdes1[2];

            m->headh1=m->headh1*mtg->prj.a2z;
            m->tailh1=m->tailh1*mtg->prj.a2z;

            ///后筒体
            if(mtg->iset.symtype==0)
            {
                mtg_std_bj(mtg,ires);
            }
            else if(mtg->iset.symtype==1)
            {
                mtg_std_bj_sym(mtg,ires);
            }
            phi=-inc[1];
            ori=inc[2]+PI;
            len1=mtg->tbm.L[6]+mtg->tbm.L[7]-mtg->ilen-mtg->tbm.L[1]-ires[2];
            ix0=m->head1[0]+len1*cos(phi)*cos(ori);
            iy0=m->head1[1]+len1*cos(phi)*sin(ori);
            iz0=m->head1[2]+len1*sin(phi);
            len1=mtg->tbm.L[6]+mtg->tbm.L[7]-mtg->ilen-mtg->tbm.L[1];
            inc[1]=inc[1]+ires[1];
            inc[2]=inc[2]+ires[0];
            phi=inc[1];
            ori=inc[2];
            m->head2[0]=ix0+len1*cos(phi)*cos(ori);
            m->head2[0]=iy0+len1*cos(phi)*sin(ori);
            m->head2[0]=iz0+len1*sin(phi);
            len1=mtg->tbm.L[2];
            phi=-phi;
            ori=ori+PI;
            m->tail2[0]=m->head2[0]+len1*cos(phi)*cos(ori);
            m->tail2[0]=m->head2[0]+len1*cos(phi)*sin(ori);
            m->tail2[0]=m->head2[0]+len1*sin(phi);
            m->inc3[1]=inc[1]*180.0/PI;
            m->inc3[2]=inc[2]*180.0/PI;
            m->inc3[0]=m->inc1[0];

            road_xy2l(&mtg->r,m->head2[0],m->head2[1],&m->headc2,&m->hdes2[0],&m->hdes2[1],0,&m->headh2);
            road_l2h(&mtg->r,m->headc2,&m->hdes2[2],0);
            m->headv2=m->head2[2]-m->hdes2[2];
            road_xy2l(&mtg->r,m->tail2[0],m->tail2[1],&m->tailc2,&m->tdes2[0],&m->tdes2[1],0,&m->tailh2);
            road_l2h(&mtg->r,m->tailc2,&m->tdes2[2],0);
            m->tailv2=m->tail2[2]-m->tdes2[2];

            m->headh2=m->headh2*mtg->prj.a2z;
            m->tailh2=m->tailh2*mtg->prj.a2z;

            m->mile1=m->headc;
            m->hdev1=m->headh;
            m->vdev1=m->headv;
            m->mile2=m->tailc;
            m->hdev2=m->tailh;
            m->vdev2=m->tailv;
            m->mile3=m->tailc1;
            m->hdev3=m->tailh1;
            m->vdev3=m->tailv1;
        }
        else if(mtg->tarset.pos==1)
        {
            if(mtg->iset.symtype==0)
                mtg_std_fj(mtg,ires);
            else if(mtg->iset.symtype==1)
                mtg_std_fj_sym(mtg,ires);
            else if(mtg->iset.symtype==2)
                mtg_std_fj_hzshj(mtg,ires);
            len1=mtg->tbm.L[0]-mtg->tbm.L[4]+ires[2];
            phi=inc[1];
            ori=inc[2];
            ix0=m->head[0]+len1*cos(phi)*cos(ori);
            iy0=m->head[1]+len1*cos(phi)*sin(ori);
            iz0=m->head[2]+len1*sin(phi);

            phi=inc[1]+ires[1];
            ori=inc[2]+ires[0];
            if(mtg->iset.head==1) len1=mtg->tbm.L[4]+mtg->tbm.L[8];
            else len1=mtg->tbm.L[4];
            m->head1[0]=ix0+len1*cos(phi)*cos(ori);
            m->head1[1]=iy0+len1*cos(phi)*sin(ori);
            m->head1[2]=iz0+len1*sin(phi);
            m->inc2[1]=inc[1]*180.0/PI;
            m->inc2[2]=inc[2]*180.0/PI;
            m->inc2[0]=m->inc1[0];

            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[0];
            m->tail1[0]=m->head1[0]+len1*cos(phi)*cos(ori);
            m->tail1[1]=m->head1[1]+len1*cos(phi)*sin(ori);
            m->tail1[2]=m->head1[2]+len1*sin(phi);

            road_xy2l(&mtg->r,m->head1[0],m->head1[1],&m->headc1,&m->hdes1[0],&m->hdes1[1],0,&m->headh1);
            road_l2h(&mtg->r,m->headc1,&m->hdes1[2],0);
            m->headv1=m->head1[2]-m->hdes1[2];
            road_xy2l(&mtg->r,m->tail1[0],m->tail1[1],&m->tailc1,&m->tdes1[0],&m->tdes1[1],0,&m->tailh1);
            road_l2h(&mtg->r,m->tailc1,&m->tdes1[2],0);
            m->tailv1=m->tail1[2]-m->tdes1[2];

            m->headh1=m->headh1*mtg->prj.a2z;
            m->tailh1=m->tailh1*mtg->prj.a2z;

            ///后筒体
            mtg_std_bj(mtg,ires);
            phi=inc[1];
            ori=inc[2];
            len1=mtg->tbm.L[6]+mtg->tbm.L[7]-mtg->tbm.L[0]-mtg->ilen-ires[2];
            ix0=m->head[0]+len1*cos(phi)*cos(ori);
            iy0=m->head[1]+len1*cos(phi)*sin(ori);
            iz0=m->head[2]+len1*sin(phi);
            inc[1]=inc[1]+ires[1];
            inc[2]=inc[2]+ires[0];
            phi=inc[1];
            ori=inc[2];
            len1=mtg->tbm.L[6]+mtg->tbm.L[7]-mtg->tbm.L[0];
            m->head2[0]=ix0+len1*cos(phi)*cos(ori);
            m->head2[1]=iy0+len1*cos(phi)*sin(ori);
            m->head2[2]=iz0+len1*sin(phi);
            m->inc3[1]=inc[1]*180.0/PI;
            m->inc3[2]=inc[2]*180.0/PI;
            m->inc3[0]=m->inc1[0];
            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[2];
            m->tail2[0]=m->tail2[0]+len1*cos(phi)*cos(ori);
            m->tail2[1]=m->tail2[1]+len1*cos(phi)*sin(ori);
            m->tail2[2]=m->tail2[2]+len1*sin(phi);

            road_xy2l(&mtg->r,m->head2[0],m->head2[1],&m->headc2,&m->hdes2[0],&m->hdes2[1],0,&m->headh2);
            road_l2h(&mtg->r,m->headc2,&m->hdes2[2],0);
            m->headv2=m->head2[2]-m->hdes2[2];
            road_xy2l(&mtg->r,m->tail2[0],m->tail2[1],&m->tailc2,&m->tdes2[0],&m->tdes2[1],0,&m->tailh2);
            road_l2h(&mtg->r,m->tailc2,&m->tdes2[2],0);
            m->tailv2=m->tail2[2]-m->tdes2[2];

            m->headh2=m->headh2*mtg->prj.a2z;
            m->tailh2=m->tailh2*mtg->prj.a2z;

            m->mile1=m->headc1;
            m->hdev1=m->headh1;
            m->vdev1=m->headv1;
            m->mile2=m->headc;
            m->hdev2=m->headh;
            m->vdev2=m->headv;
            m->mile3=m->tailc;
            m->hdev3=m->tailh;
            m->vdev3=m->tailv;
        }
    }
    //fclose(fp);
    return 0;
}

extern int mtg_cal_seg(mtg_t* mtg)
{
    double ires[3];
    double d1;
    double ori,phi;

    mtg_std_aj(mtg,ires);

    //trace(0,"mtg_cal_seg:ori=%.12f,phi=%.12f,d=%.4f,d1=%.4f\n",ires[0],ires[1],ires[2],mtg->tbm.L[3]);

    if(mtg->tbm.type<2) d1=mtg->tbm.L[3];
    else d1=mtg->tbm.L[3]-mtg->tbm.L[0];
    d1=d1-ires[2];
    ori=mtg->m.inc1[2]*PI/180.0;
    phi=mtg->m.inc1[1]*PI/180.0;
    mtg->sazi=ori+ires[0];
    mtg->sphi=phi+ires[1];
    ori=ori+PI;
    phi=-phi;
    mtg->segx=mtg->m.head[0]+d1*cos(phi)*cos(ori);
    mtg->segy=mtg->m.head[1]+d1*cos(phi)*sin(ori);
    mtg->segz=mtg->m.head[2]+d1*sin(phi);
    //trace(0,"mtg_cal_seg:headx=%.4f,heady=%.4f,headz=%.4f\n",mtg->m.head[0],mtg->m.head[1],mtg->m.head[2]);
    //trace(0,"mtg_cal_seg:segx=%.4f,segy=%.4f,segz=%.4f\n",mtg->segx,mtg->segy,mtg->segz);
    //trace(0,"mtg_cal_seg:m_ori=%.12f,m_phi=%.12f\n",mtg->m.inc1[2]*PI/180.0,mtg->m.inc1[1]*PI/180.0);
    //trace(0,"mtg_cal_seg:s_ori=%.12f,s_phi=%.12f\n",mtg->sazi,mtg->sphi);
    return 0;
}

extern int mtg_jack_gesture(mtg_t* mtg)
{
    double ires[3];
    int a2z;
    double inc[3];
    double len1,ori,phi;
    double ix0,iy0,iz0;

    MTG_MEASURE* m=0;

    if(mtg->ilen==0) return -1;
    m=&mtg->m1;
    a2z=mtg->prj.a2z;
    mtg_std_aj(mtg,ires);
    //trace(0,"mtg_jack_gesture:ori=%.12f,phi=%.12f,d=%.4f,d1=%.4f\n",ires[0],ires[1],ires[2],mtg->tbm.L[3]);
    if(mtg->tbm.type==0)
    {
        if(mtg->iset.head==1) len1=mtg->tbm.L[3]+mtg->tbm.L[8]-ires[2];
        else len1=mtg->tbm.L[3]-ires[2];
        //trace(0,"mtg_jack_gesture:len1=%.4f\n",len1);
        ori=mtg->sazi-ires[0];
        phi=mtg->sphi-ires[1];
        m->head[0]=mtg->segx+len1*cos(phi)*cos(ori);
        m->head[1]=mtg->segy+len1*cos(phi)*sin(ori);
        m->head[2]=mtg->segz+len1*sin(phi);
        //trace(0,"mtg_jack_gesture:headx=%.4f,heady=%.4f,headz=%.4f\n",m->head[0],m->head[1],m->head[2]);
        phi=-phi;
        ori=ori+PI;
        len1=mtg->tbm.L[0];
        m->tail[0]=m->head[0]+len1*cos(phi)*cos(ori);
        m->tail[1]=m->head[1]+len1*cos(phi)*sin(ori);
        m->tail[2]=m->head[2]+len1*sin(phi);
        road_xy2l(&mtg->r,m->head[0],m->head[1],&m->headc,&m->hdes[0],&m->hdes[1],0,&m->headh);
        road_l2h(&mtg->r,m->headc,&m->hdes[2],0);
        m->headv=m->head[2]-m->hdes[2];
        road_xy2l(&mtg->r,m->tail[0],m->tail[1],&m->tailc,&m->tdes[0],&m->tdes[1],0,&m->tailh);
        road_l2h(&mtg->r,m->tailc,&m->tdes[2],0);
        m->tailv=m->tail[2]-m->tdes[2];
        m->headh=m->headh*a2z;
        m->tailh=m->tailh*a2z;
        m->mile1=m->headc;
        m->hdev1=m->headh;
        m->vdev1=m->headv;
        m->mile2=(m->headc+m->tailc)/2.0;
        m->hdev2=(m->headh+m->tailh)/2.0;
        m->vdev2=(m->headv+m->tailv)/2.0;
        m->mile3=m->tailc;
        m->hdev3=m->tailh;
        m->vdev3=m->tailv;
    }
    else if(mtg->tbm.type==1)
    {
        ori=mtg->sazi-ires[0];
        phi=mtg->sphi-ires[1];
        if(mtg->iset.head==1) len1=mtg->tbm.L[3]+mtg->tbm.L[8]-ires[2];
        else len1=mtg->tbm.L[3]-ires[2];
        m->head[0]=mtg->segx+len1*cos(phi)*cos(ori);
        m->head[1]=mtg->segy+len1*cos(phi)*sin(ori);
        m->head[2]=mtg->segz+len1*sin(phi);
        inc[1]=phi;
        inc[2]=ori;
        phi=-phi;
        ori=ori+PI;
        len1=mtg->tbm.L[0];
        m->tail[0]=m->head[0]+len1*cos(phi)*cos(ori);
        m->tail[1]=m->head[1]+len1*cos(phi)*sin(ori);
        m->tail[2]=m->head[2]+len1*sin(phi);
        road_xy2l(&mtg->r,m->head[0],m->head[1],&m->headc,&m->hdes[0],&m->hdes[1],0,&m->headh);
        road_l2h(&mtg->r,m->headc,&m->hdes[2],0);
        m->headv=m->head[2]-m->hdes[2];
        road_xy2l(&mtg->r,m->tail[0],m->tail[1],&m->tailc,&m->tdes[0],&m->tdes[1],0,&m->tailh);
        road_l2h(&mtg->r,m->tailc,&m->tdes[2],0);
        m->tailv=m->tail[2]-m->tdes[2];
        m->headh=m->headh*a2z;
        m->tailh=m->tailh*a2z;


        mtg_std_bj(mtg,ires);
        len1=mtg->tbm.L[6]+mtg->tbm.L[7]-ires[2];
        phi=-inc[1];
        ori=inc[2]+PI;
        ix0=m->head[0]+len1*cos(phi)*cos(ori);
        iy0=m->head[1]+len1*cos(phi)*sin(ori);
        iz0=m->head[2]+len1*sin(phi);
        phi=inc[1]+ires[1];
        ori=inc[2]+ires[0];
        len1=mtg->tbm.L[6]+mtg->tbm.L[7]-mtg->ilen;
        m->head2[0]=ix0+len1*cos(phi)*cos(ori);
        m->head2[1]=iy0+len1*cos(phi)*sin(ori);
        m->head2[2]=iz0+len1*sin(phi);

        phi=-phi;
        ori=ori+PI;
        len1=mtg->tbm.L[2];
        m->tail2[0]=m->head2[0]+len1*cos(phi)*cos(ori);
        m->tail2[1]=m->head2[1]+len1*cos(phi)*sin(ori);
        m->tail2[2]=m->head2[2]+len1*sin(phi);

        road_xy2l(&mtg->r,m->head2[0],m->head2[1],&m->headc2,&m->hdes2[0],&m->hdes2[1],0,&m->headh2);
        road_l2h(&mtg->r,m->headc2,&m->hdes2[2],0);
        m->headv2=m->head2[2]-m->hdes2[2];
        road_xy2l(&mtg->r,m->tail2[0],m->tail2[1],&m->tailc2,&m->tdes2[0],&m->tdes2[1],0,&m->tailh2);
        road_l2h(&mtg->r,m->tailc2,&m->tdes2[2],0);
        m->tailv2=m->tail2[2]-m->tdes2[2];
        m->headh2=m->headh2*mtg->prj.a2z;
        m->tailh2=m->tailh2*mtg->prj.a2z;

        m->mile1=m->headc;
        m->hdev1=m->headh;
        m->vdev1=m->headv;
        m->mile2=m->tailc;
        m->hdev2=m->tailh;
        m->vdev2=m->tailv;
        m->mile3=m->tailc2;
        m->hdev3=m->tailh2;
        m->vdev3=m->tailv2;
    }
    else if(mtg->tbm.type==2)
    {
        if(mtg->tarset.pos==0)
        {
            ori=mtg->sazi-ires[0];
            phi=mtg->sphi-ires[1];

            len1=mtg->tbm.L[3]-mtg->tbm.L[0]-ires[2];
            m->head2[0]=mtg->segx+len1*cos(phi)*cos(ori);
            m->head2[1]=mtg->segy+len1*cos(phi)*sin(ori);
            m->head2[2]=mtg->segz+len1*sin(phi);

            inc[1]=phi;
            inc[2]=ori;
            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[2];
            m->tail2[0]=m->head2[0]+len1*cos(phi)*cos(ori);
            m->tail2[1]=m->head2[1]+len1*cos(phi)*sin(ori);
            m->tail2[2]=m->head2[2]+len1*sin(phi);

            road_xy2l(&mtg->r,m->head2[0],m->head2[1],&m->headc2,&m->hdes2[0],&m->hdes2[1],0,&m->headh2);
            road_l2h(&mtg->r,m->headc2,&m->hdes2[2],0);
            m->headv2=m->head2[2]-m->hdes2[2];
            road_xy2l(&mtg->r,m->tail2[0],m->tail2[1],&m->tailc2,&m->tdes2[0],&m->tdes2[1],0,&m->tailh2);
            road_l2h(&mtg->r,m->tailc2,&m->tdes2[2],0);
            m->tailv2=m->tail2[2]-m->tdes2[2];
            m->headh2=m->headh2*a2z;
            m->tailh2=m->tailh2*a2z;

            mtg_std_fj(mtg,ires);
            phi=inc[1];
            ori=inc[2];

            len1=mtg->tbm.L[0]-mtg->tbm.L[4]+ires[2];
            ix0=m->head2[0]+len1*cos(phi)*cos(ori);
            iy0=m->head2[1]+len1*cos(phi)*sin(ori);
            iz0=m->head2[2]+len1*sin(phi);
            phi=phi+ires[1];
            ori=ori+ires[0];
            if(mtg->iset.head==1) len1=mtg->tbm.L[4]+mtg->tbm.L[8];
            else len1=mtg->tbm.L[4];
            m->head[0]=ix0+len1*cos(phi)*cos(ori);
            m->head[1]=iy0+len1*cos(phi)*sin(ori);
            m->head[2]=iz0+len1*sin(phi);
            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[0];
            m->tail[0]=m->head[0]+len1*cos(phi)*cos(ori);
            m->tail[1]=m->head[1]+len1*cos(phi)*sin(ori);
            m->tail[2]=m->head[2]+len1*sin(phi);
            road_xy2l(&mtg->r,m->head[0],m->head[1],&m->headc,&m->hdes[0],&m->hdes[1],0,&m->headh);
            road_l2h(&mtg->r,m->headc,&m->hdes[2],0);
            m->headv=m->head[2]-m->hdes[2];
            road_xy2l(&mtg->r,m->tail[0],m->tail[1],&m->tailc,&m->tdes[0],&m->tdes[1],0,&m->tailh);
            road_l2h(&mtg->r,m->tailc,&m->tdes[2],0);
            m->tailv=m->tail[2]-m->tdes[2];
            m->headh=m->headh*a2z;
            m->tailh=m->tailh*a2z;

            m->mile1=m->headc;
            m->hdev1=m->headh;
            m->vdev1=m->headv;
            m->mile2=m->tailc;
            m->hdev2=m->tailh;
            m->vdev2=m->tailv;
            m->mile3=m->tailc2;
            m->hdev3=m->tailh2;
            m->vdev3=m->tailv2;
        }
        else if(mtg->tarset.pos==1)
        {
            ori=mtg->sazi-ires[0];
            phi=mtg->sphi-ires[1];
            len1=mtg->tbm.L[3]-mtg->tbm.L[0]-ires[2];
            m->head[0]=mtg->segx+len1*cos(phi)*cos(ori);
            m->head[1]=mtg->segy+len1*cos(phi)*sin(ori);
            m->head[2]=mtg->segz+len1*sin(phi);
            inc[1]=phi;
            inc[2]=ori;
            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[2];
            m->tail[0]=m->head[0]+len1*cos(phi)*cos(ori);
            m->tail[1]=m->head[1]+len1*cos(phi)*sin(ori);
            m->tail[2]=m->head[2]+len1*sin(phi);
            road_xy2l(&mtg->r,m->head[0],m->head[1],&m->headc,&m->hdes[0],&m->hdes[1],0,&m->headh);
            road_l2h(&mtg->r,m->headc,&m->hdes[2],0);
            m->headv=m->head[2]-m->hdes[2];
            road_xy2l(&mtg->r,m->tail[0],m->tail[1],&m->tailc,&m->tdes[0],&m->tdes[1],0,&m->tailh);
            road_l2h(&mtg->r,m->tailc,&m->tdes[2],0);
            m->tailv=m->tail[2]-m->tdes[2];
            m->headh=m->headh*a2z;
            m->tailh=m->tailh*a2z;

            mtg_std_fj(mtg,ires);
            phi=inc[1];
            ori=inc[2];
            len1=mtg->tbm.L[0]-mtg->tbm.L[4]+ires[2];
            ix0=m->head[0]+len1*cos(phi)*cos(ori);
            iy0=m->head[1]+len1*cos(phi)*sin(ori);
            iz0=m->head[2]+len1*sin(phi);
            phi=phi+ires[1];
            ori=ori+ires[0];
            if(mtg->iset.head==1) len1=mtg->tbm.L[4]+mtg->tbm.L[8];
            else len1=mtg->tbm.L[4];
            m->head1[0]=ix0+len1*cos(phi)*cos(ori);
            m->head1[1]=iy0+len1*cos(phi)*sin(ori);
            m->head1[2]=iz0+len1*sin(phi);
            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[0];
            m->tail1[0]=m->head1[0]+len1*cos(phi)*cos(ori);
            m->tail1[1]=m->head1[1]+len1*cos(phi)*sin(ori);
            m->tail1[2]=m->head1[2]+len1*sin(phi);
            road_xy2l(&mtg->r,m->head1[0],m->head1[1],&m->headc1,&m->hdes1[0],&m->hdes1[1],0,&m->headh1);
            road_l2h(&mtg->r,m->headc1,&m->hdes1[2],0);
            m->headv1=m->head1[2]-m->hdes1[2];
            road_xy2l(&mtg->r,m->tail1[0],m->tail1[1],&m->tailc1,&m->tdes1[0],&m->tdes1[1],0,&m->tailh1);
            road_l2h(&mtg->r,m->tailc1,&m->tdes1[2],0);
            m->tailv1=m->tail1[2]-m->tdes1[2];
            m->headh1=m->headh1*a2z;
            m->tailh1=m->tailh1*a2z;
            m->mile1=m->headc1;
            m->hdev1=m->headh1;
            m->vdev1=m->headv1;
            m->mile2=m->headc;
            m->hdev2=m->headh;
            m->vdev2=m->headv;
            m->mile3=m->tailc;
            m->hdev3=m->tailh;
            m->vdev3=m->tailv;
        }
    }
    else if(mtg->tbm.type==3)
    {
        if(mtg->tarset.pos==0)
        {
            ori=mtg->sazi-ires[0];
            phi=mtg->sphi-ires[1];
            len1=mtg->tbm.L[3]-mtg->tbm.L[0]-ires[2];
            m->head1[0]=mtg->segx+len1*cos(phi)*cos(ori);
            m->head1[1]=mtg->segy+len1*cos(phi)*sin(ori);
            m->head1[2]=mtg->segz+len1*sin(phi);

            inc[1]=phi;
            inc[2]=ori;
            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[2];
            m->tail1[0]=m->head1[0]+len1*cos(phi)*cos(ori);
            m->tail1[1]=m->head1[1]+len1*cos(phi)*sin(ori);
            m->tail1[2]=m->head1[2]+len1*sin(phi);

            road_xy2l(&mtg->r,m->head1[0],m->head1[1],&m->headc1,&m->hdes1[0],&m->hdes1[1],0,&m->headh1);
            road_l2h(&mtg->r,m->headc1,&m->hdes1[2],0);
            m->headv1=m->head1[2]-m->hdes1[2];
            road_xy2l(&mtg->r,m->tail1[0],m->tail1[1],&m->tailc1,&m->tdes1[0],&m->tdes1[1],0,&m->tailh1);
            road_l2h(&mtg->r,m->tailc1,&m->tdes1[2],0);
            m->tailv1=m->tail1[2]-m->tdes1[2];
            m->headh1=m->headh1*a2z;
            m->tailh1=m->tailh1*a2z;

            mtg_std_fj(mtg,ires);
            phi=inc[1];
            ori=inc[2];
            len1=mtg->tbm.L[0]-mtg->tbm.L[4]+ires[2];
            ix0=m->head1[0]+len1*cos(phi)*cos(ori);
            iy0=m->head1[1]+len1*cos(phi)*sin(ori);
            iz0=m->head1[2]+len1*sin(phi);
            phi=phi+ires[1];
            ori=ori+ires[0];
            if(mtg->iset.head==1) len1=mtg->tbm.L[4]+mtg->tbm.L[8];
            else len1=mtg->tbm.L[4];
            m->head[0]=ix0+len1*cos(phi)*cos(ori);
            m->head[1]=iy0+len1*cos(phi)*sin(ori);
            m->head[2]=iz0+len1*sin(phi);
            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[0];
            m->tail[0]=m->head[0]+len1*cos(phi)*cos(ori);
            m->tail[1]=m->head[1]+len1*cos(phi)*sin(ori);
            m->tail[2]=m->head[2]+len1*sin(phi);
            road_xy2l(&mtg->r,m->head[0],m->head[1],&m->headc,&m->hdes[0],&m->hdes[1],0,&m->headh);
            road_l2h(&mtg->r,m->headc,&m->hdes[2],0);
            m->headv=m->head[2]-m->hdes[2];
            road_xy2l(&mtg->r,m->tail[0],m->tail[1],&m->tailc,&m->tdes[0],&m->tdes[1],0,&m->tailh);
            road_l2h(&mtg->r,m->tailc,&m->tdes[2],0);
            m->tailv=m->tail[2]-m->tdes[2];
            m->headh=m->headh*a2z;
            m->tailh=m->tailh*a2z;

            mtg_std_bj(mtg,ires);
            phi=-inc[1];
            ori=inc[2]+PI;
            len1=mtg->tbm.L[6]+mtg->tbm.L[7]-mtg->tbm.L[0]-mtg->tbm.L[1]-ires[2];
            ix0=m->tail1[0]+len1*cos(phi)*cos(ori);
            iy0=m->tail1[1]+len1*cos(phi)*sin(ori);
            iz0=m->tail1[2]+len1*sin(phi);
            phi=inc[1]+ires[1];
            ori=inc[2]+ires[0];
            len1=mtg->tbm.L[6]+mtg->tbm.L[7]-mtg->tbm.L[0]-mtg->tbm.L[1];
            m->head2[0]=ix0+len1*cos(phi)*cos(ori);
            m->head2[1]=iy0+len1*cos(phi)*sin(ori);
            m->head2[2]=iz0+len1*sin(phi);
            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[2];
            m->tail2[0]=m->head2[0]+len1*cos(phi)*cos(ori);
            m->tail2[1]=m->head2[1]+len1*cos(phi)*sin(ori);
            m->tail2[2]=m->head2[2]+len1*sin(phi);
            road_xy2l(&mtg->r,m->head2[0],m->head2[1],&m->headc2,&m->hdes2[0],&m->hdes2[1],0,&m->headh2);
            road_l2h(&mtg->r,m->headc2,&m->hdes2[2],0);
            m->headv2=m->head2[2]-m->hdes2[2];
            road_xy2l(&mtg->r,m->tail2[0],m->tail2[1],&m->tailc2,&m->tdes2[0],&m->tdes2[1],0,&m->tailh2);
            road_l2h(&mtg->r,m->tailc2,&m->tdes2[2],0);
            m->tailv2=m->tail2[2]-m->tdes2[2];
            m->headh2=m->headh2*a2z;
            m->tailh2=m->tailh2*a2z;

            m->mile1=m->headc;
            m->hdev1=m->headh;
            m->vdev1=m->headv;
            m->mile2=m->tailc;
            m->hdev2=m->tailh;
            m->vdev2=m->tailv;
            m->mile3=m->tailc1;
            m->hdev3=m->tailh1;
            m->vdev3=m->tailv1;
        }
        else if(mtg->tarset.pos==1)
        {
            ori=mtg->sazi-ires[0];
            phi=mtg->sphi-ires[1];
            len1=mtg->tbm.L[3]-mtg->tbm.L[0]-ires[2];
            m->head[0]=mtg->segx+len1*cos(phi)*cos(ori);
            m->head[1]=mtg->segy+len1*cos(phi)*sin(ori);
            m->head[2]=mtg->segz+len1*sin(phi);
            inc[1]=phi;
            inc[2]=ori;
            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[2];
            m->tail[0]=m->head[0]+len1*cos(phi)*cos(ori);
            m->tail[1]=m->head[1]+len1*cos(phi)*sin(ori);
            m->tail[2]=m->head[2]+len1*sin(phi);
            road_xy2l(&mtg->r,m->head[0],m->head[1],&m->headc,&m->hdes[0],&m->hdes[1],0,&m->headh);
            road_l2h(&mtg->r,m->headc,&m->hdes[2],0);
            m->headv=m->head[2]-m->hdes[2];
            road_xy2l(&mtg->r,m->tail[0],m->tail[1],&m->tailc,&m->tdes[0],&m->tdes[1],0,&m->tailh);
            road_l2h(&mtg->r,m->tailc,&m->tdes[2],0);
            m->tailv=m->tail[2]-m->tdes[2];
            m->headh=m->headh*a2z;
            m->tailh=m->tailh*a2z;

            mtg_std_fj(mtg,ires);
            phi=inc[1];
            ori=inc[2];
            len1=mtg->tbm.L[0]-mtg->tbm.L[4]+ires[2];
            ix0=m->head[0]+len1*cos(phi)*cos(ori);
            iy0=m->head[1]+len1*cos(phi)*sin(ori);
            iz0=m->head[2]+len1*sin(phi);
            phi=phi+ires[1];
            ori=ori+ires[0];
            if(mtg->iset.head==1) len1=mtg->tbm.L[4]+mtg->tbm.L[8];
            else len1=mtg->tbm.L[4];
            m->head1[0]=ix0+len1*cos(phi)*cos(ori);
            m->head1[1]=iy0+len1*cos(phi)*sin(ori);
            m->head1[2]=iz0+len1*sin(phi);
            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[0];
            m->tail1[0]=m->head1[0]+len1*cos(phi)*cos(ori);
            m->tail1[1]=m->head1[1]+len1*cos(phi)*sin(ori);
            m->tail1[2]=m->head1[2]+len1*sin(phi);
            road_xy2l(&mtg->r,m->head1[0],m->head1[1],&m->headc1,&m->hdes1[0],&m->hdes1[1],0,&m->headh1);
            road_l2h(&mtg->r,m->headc1,&m->hdes1[2],0);
            m->headv1=m->head1[2]-m->hdes1[2];
            road_xy2l(&mtg->r,m->tail1[0],m->tail1[1],&m->tailc1,&m->tdes1[0],&m->tdes1[1],0,&m->tailh1);
            road_l2h(&mtg->r,m->tailc1,&m->tdes1[2],0);
            m->tailv1=m->tail1[2]-m->tdes1[2];
            m->headh1=m->headh1*a2z;
            m->tailh1=m->tailh1*a2z;

            mtg_std_bj(mtg,ires);
            phi=-inc[1];
            ori=inc[2]+PI;
            len1=mtg->tbm.L[6]+mtg->tbm.L[7]-mtg->tbm.L[0]-mtg->tbm.L[1]-ires[2];
            ix0=m->tail[0]+len1*cos(phi)*cos(ori);
            iy0=m->tail[1]+len1*cos(phi)*sin(ori);
            iz0=m->tail[2]+len1*sin(phi);
            phi=inc[1]+ires[1];
            ori=inc[2]+ires[0];
            len1=mtg->tbm.L[6]+mtg->tbm.L[7]-mtg->tbm.L[0]-mtg->tbm.L[1];
            m->head2[0]=ix0+len1*cos(phi)*cos(ori);
            m->head2[1]=iy0+len1*cos(phi)*sin(ori);
            m->head2[2]=iz0+len1*sin(phi);
            phi=-phi;
            ori=ori+PI;
            len1=mtg->tbm.L[2];
            m->tail2[0]=m->head2[0]+len1*cos(phi)*cos(ori);
            m->tail2[1]=m->head2[1]+len1*cos(phi)*sin(ori);
            m->tail2[2]=m->head2[2]+len1*sin(phi);
            road_xy2l(&mtg->r,m->head2[0],m->head2[1],&m->headc2,&m->hdes2[0],&m->hdes2[1],0,&m->headh2);
            road_l2h(&mtg->r,m->headc2,&m->hdes2[2],0);
            m->headv2=m->head2[2]-m->hdes2[2];
            road_xy2l(&mtg->r,m->tail2[0],m->tail2[1],&m->tailc2,&m->tdes2[0],&m->tdes2[1],0,&m->tailh2);
            road_l2h(&mtg->r,m->tailc2,&m->tdes2[2],0);
            m->tailv2=m->tail2[2]-m->tdes2[2];
            m->headh2=m->headh2*a2z;
            m->tailh2=m->tailh2*a2z;

            m->mile1=m->headc1;
            m->hdev1=m->headh1;
            m->vdev1=m->headv1;
            m->mile2=m->headc;
            m->hdev2=m->headh;
            m->vdev2=m->headv;
            m->mile3=m->tailc;
            m->hdev3=m->tailh;
            m->vdev3=m->tailv;
        }
    }
    ///环号
    //mtg->snum.tm=fabs(m->headc-mtg->snum.mile);
    return 0;
}

extern int mtg_cal_aj(double rad[2],double aj[4],double* res)
{
    double ilen,ilen1,ilen2,dlen;
    double a,b,c;
    double iaj[3];
    if(!res) return 0;

    ilen=(rad[0]-rad[1])/2;
    ilen1=aj[0]*aj[0]-ilen*ilen;
    ilen1=sqrt(ilen1);
    ilen2=aj[1]*aj[1]-ilen*ilen;
    ilen2=sqrt(ilen2);

    a=rad[1];
    b=ilen2-ilen1;
    c=sqrt(a*a+b*b);
    dlen=(c-a)/2;
    dlen=dlen*a/c;
    //trace(0,"mtg_cal_aj:%.12f,a=%.12f,b=%.12f,c=%.12f,dlen=%.12f\n",ilen,a,b,c,dlen);
    while(dlen>0.00001)
    {
        ilen=ilen+dlen;
        ilen1=aj[0]*aj[0]-ilen*ilen;
        ilen1=sqrt(ilen1);
        ilen2=aj[1]*aj[1]-ilen*ilen;
        ilen2=sqrt(ilen2);
        a=rad[0]-2*ilen;
        b=ilen2-ilen1;
        c=sqrt(a*a+b*b);
        dlen=(c-rad[1])/2;
        dlen=dlen*a/c;
        //trace(0,"mtg_cal_aj:%.12f,a=%.12f,b=%.12f,c=%.12f,dlen=%.12f\n",ilen,a,b,c,dlen);
    }

    res[1]=atan(b/a);
    iaj[0]=aj[0]*aj[0]-ilen*ilen;
    iaj[0]=sqrt(iaj[0]);
    iaj[1]=aj[1]*aj[1]-ilen*ilen;
    iaj[1]=sqrt(iaj[1]);
    iaj[2]=(iaj[0]+iaj[1])/2;
    res[3]=iaj[2];

    ilen=(rad[0]-rad[1])/2;
    ilen1=aj[2]*aj[2]-ilen*ilen;
    ilen1=sqrt(ilen1);
    ilen2=aj[3]*aj[3]-ilen*ilen;
    ilen2=sqrt(ilen2);

    a=rad[1];
    b=ilen2-ilen1;
    c=sqrt(a*a+b*b);
    dlen=(c-a)/2;
    dlen=dlen*a/c;
    //trace(0,"mtg_cal_aj:%.12f,a=%.12f,b=%.12f,c=%.12f,dlen=%.12f\n",ilen,a,b,c,dlen);
    while(dlen>0.00001)
    {
        ilen=ilen+dlen;
        ilen1=aj[2]*aj[2]-ilen*ilen;
        ilen1=sqrt(ilen1);
        ilen2=aj[3]*aj[3]-ilen*ilen;
        ilen2=sqrt(ilen2);
        a=rad[0]-2*ilen;
        b=ilen2-ilen1;
        c=sqrt(a*a+b*b);
        dlen=(c-rad[1])/2;
        dlen=dlen*a/c;
    }

    res[0]=atan(b/a);

    //trace(0,"%.4f,%.4f,%.4f\n",aj[2],aj[3],ilen);
    iaj[0]=aj[2]*aj[2]-ilen*ilen;
    iaj[0]=sqrt(iaj[0]);
    //trace(0,"%.4f\n",iaj[0]);
    iaj[1]=aj[3]*aj[3]-ilen*ilen;
    iaj[1]=sqrt(iaj[1]);
    //trace(0,"%.4f\n",iaj[1]);
    iaj[2]=(iaj[0]+iaj[1])/2;
    //trace(0,"%.4f\n",iaj[2]);
    res[2]=(iaj[2]+res[3])/2.0;

    //trace(0,"mtg_cal_aj:azi=%.12f,pitch=%.12f,lenght=%.12f,lenght=%.12f\n",res[0],res[1],res[2],res[3]);
    return 0;
}

extern int mtg_std_aj(mtg_t* mtg,double* res)
{
    int i,j,n,ki;
    double yi[6]={0};
    double zi[6]={0};
    point3d_t pts[6]={0};
    double r1;
    double aj[6]={0};
    //double beta[6];
    double d0,d1,d2;
    double h0,h1,h2;
    double roll;
    double a,b,c,d;
    double dbval=0.0;
    plane_t* p;

    n=mtg->tbm.naj;
    //trace(0,"mtg_std_aj:naj=%d\n",n);
    if(n<3) return 0;
    r1=mtg->tbm.D[0]/2.0;
    //r2=mtg->tbm.D[4]/2.0;
    roll=mtg->m1.inc1[0]*PI/180.0;

    for(i=0;i<n;i++)
    {
        yi[i]=r1*cos(mtg->tbm.aj[i]+roll);
        pts[i].y=yi[i];
        zi[i]=-r1*sin(mtg->tbm.aj[i]+roll);
        pts[i].z=zi[i];
        aj[i]=mtg->aj[i];
        //trace(0,"mtg_std_aj:i=%d,aj=%.4f,yi=%.4f,zi=%.4f,ai=%.12f\n",i,mtg->aj[i],yi[i],zi[i],mtg->tbm.aj);
        //beta[i]=mtg->tbm.aj[i]+roll;
    }

    d1=0.0;
    for(i=0;i<n/2;i++)
    {
        d2=0.0;
        for(j=0;j<n;j++)
        {
            d1=(yi[i]-yi[j])*(yi[i]-yi[j])+(zi[i]-zi[j])*(zi[i]-zi[j]);
            d1=sqrt(d1);
            //trace(0,"mtg_std_aj:i=%d,j=%d,d1=%.4f\n",i,j,d1);
            //if(i==1) trace(0,"mtg_std_aj:j=%d,yj=%.4f,zj=%.4f,d1=%.4f,d2=%.4f\n",j,yi[j],zi[j],d1,d2);
            if(d1>d2)
            {
                d2=d1;
                ki=j;
            }
        }
        h1=aj[i];
        h2=aj[ki];
        h0=(h1+h2)/2.0;
        if(fabs(h0)<=0.1)
        {
            pts[i].x=0.0;
            pts[ki].x=0.0;
        }
        else
        {
            dbval=(aj[i]*aj[i]-aj[ki]*aj[ki])/(2.0*h0*d2);
            dbval=asin(dbval);
            pts[i].x=-(h0+d2*sin(dbval)/2.0);
            pts[ki].x=-(h0-d2*sin(dbval)/2.0);
        }
        //trace(0,"mtg_std_aj:i=%d,ki=%d,x1=%.4f,x2=%.4f\n",i,ki,pts[i].x,pts[ki].x);
        //ay[i]=pts[i].y-pts[ki].y;
        //az[i]=pts[i].z-pts[ki].z;
    }

    p=plane_create();
    if(!plane_init_points(p,n,pts))
    {
        free(p);
        //trace(0,"mtg_std_aj:failed!\n");
        return 0;
    }
    if(res)
    {
        a=p->a;
        b=p->b;
        c=p->c;
        d=sqrt(a*a+b*b);
        res[0]=atan2(b,a);
        res[1]=atan(c/d);
        d=0.0;
        for(i=0;i<n;i++)
        {
            d+=pts[i].x;
        }
        res[2]=d/n;
        mtg->m.aj[0]=res[2]+r1*tan(res[1]);
        mtg->m.aj[1]=res[2]-r1*tan(res[1]);
        mtg->m.aj[2]=res[2]-r1*tan(res[0]);
        mtg->m.aj[3]=res[2]+r1*tan(res[0]);
    }
    //trace(0,"mtg_std_aj:a=%.4f,b=%.4f,c=%.4f\n",res[0],res[1],res[2]);
    //trace(0,"mtg_std_aj:a=%.4f,b=%.4f,c=%.4f\n",p->a,p->b,p->c);
    free(p);
    return 1;
}

extern int mtg_std_bj(mtg_t* mtg,double* res)
{
    int i,j;
    double yi[4];
    double zi[4];
    point3d_t pts[4];
    double r1,r2;
    double bj[4];
    double beta[4];
    double d0,d1,d2,detd;
    double h0,h1,h2;
    double len,roll;
    double ax,ay,az;
    double bx,by,bz;
    double a,b,c,d;
    double dbval;
    double arc[4];
    double temp;
    int errordata=0;

    r1=mtg->tbm.D[3]/2.0;
    r2=mtg->tbm.D[4]/2.0;
    roll=mtg->m1.inc1[0]*PI/180.0;

    detd=r1-r2;
    len=mtg->tbm.L[7];
    len=len*len+detd*detd;
    len=sqrt(len);
    //trace(0,"mtg_std_fj:len=%.4f\n",len);
    pts[0].z=0.0;
    pts[1].z=0.0;
    pts[2].y=0.0;
    pts[3].y=0.0;

    ///20180112whq增加,当铰接油缸数据出现异常值时，则让其计算结果mtg->m.faj相应值为-10000，该数将存储于数据库
    for(i=0;i<4;i++)
    {
        mtg->m.baj[i]=mtg->bj[i];
        if(mtg->m.baj[i]>100000)
        {
            mtg->m.baj[i]=-100000;
            errordata++;
        }
    }
    if(errordata>0)
    {
        return -1;
    }
    ///20180112whq增加结束



    for(i=0;i<4;i++)
    {
        arc[i]=mtg->tbm.bj[i]+roll;
    }
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(arc[i]>arc[j])
            {
                temp=arc[i];
                arc[i]=arc[j];
                arc[j]=temp;
                temp=mtg->m.baj[i];
                mtg->m.baj[i]=mtg->m.baj[j];
                mtg->m.baj[j]=temp;
            }
        }
    }

    ///20171130whq修改pts[0]/pts[1]/pts[2]/pts[3]的判断语句，加入三个等号
    for(i=0;i<4;i++)
    {
        yi[i]=r2*cos(arc[i]);
        zi[i]=-r2*sin(arc[i]);
        if(zi[i]>=pts[0].z)
        {
            pts[0].z=zi[i];
            pts[0].y=yi[i];
            bj[0]=mtg->m.baj[i]+len;
            beta[0]=arc[i];
        }
        if(zi[i]<=pts[1].z)
        {
            pts[1].z=zi[i];
            pts[1].y=yi[i];
            bj[1]=mtg->m.baj[i]+len;
            beta[1]=arc[i];
        }
        if(yi[i]<=pts[2].y)
        {
            pts[2].y=yi[i];
            pts[2].z=zi[i];
            bj[2]=mtg->m.baj[i]+len;
            beta[2]=arc[i];
        }
        if(yi[i]>pts[3].y)
        {
            pts[3].y=yi[i];
            pts[3].z=zi[i];
            bj[3]=mtg->m.baj[i]+len;
            beta[3]=arc[i];
        }
    }

    for(i=0;i<4;i++)
    {
        yi[i]=r1*cos(beta[i]);
        zi[i]=-r1*sin(beta[i]);
        //trace(0,"mtg_std_fj:i=%d,y=%.4f,z=%.4f\n",i,yi[i],zi[i]);
    }
    //trace(0,"mtg_std_fj:u=%.4f,d=%.4f,l=%.4f,r=%.4f\n",fj[0],fj[1],fj[2],fj[3]);
    d1=(yi[2]-yi[3])*(yi[2]-yi[3])+(zi[2]-zi[3])*(zi[2]-zi[3]);
    d1=sqrt(d1);
    d2=(pts[2].y-pts[3].y)*(pts[2].y-pts[3].y)+(pts[2].z-pts[3].z)*(pts[2].z-pts[3].z);
    d2=sqrt(d2);

    //trace(0,"mtg_std_fj:d1=%.4f,d2=%.4f\n",d1,d2);
    detd=(d1-d2)/2.0;

    h1=bj[2]*bj[2]-detd*detd;
    h1=sqrt(h1);
    h2=bj[3]*bj[3]-detd*detd;
    h2=sqrt(h2);
    h0=(h1+h2)/2.0;


    ///20180112whq修改，用于防止分母为0
    dbval=(bj[2]*bj[2]-bj[3]*bj[3])/(2.0*h0*d2+0.0000000001);
    dbval=asin(dbval);
    pts[2].x=-(h0+d2*sin(dbval)/2.0);
    pts[3].x=-(h0-d2*sin(dbval)/2.0);
    //trace(0,"mtg_std_fj:lx=%.4f,rx=%.4f\n",pts[2].x,pts[3].x);
    //trace(0,"mtg_std_fj:ly=%.4f,ry=%.4f\n",pts[2].y,pts[3].y);
    //trace(0,"mtg_std_fj:lz=%.4f,rz=%.4f\n",pts[2].z,pts[3].z);

    d1=(yi[0]-yi[1])*(yi[0]-yi[1])+(zi[0]-zi[1])*(zi[0]-zi[1]);
    d1=sqrt(d1);
    d2=(pts[0].y-pts[1].y)*(pts[0].y-pts[1].y)+(pts[0].z-pts[1].z)*(pts[0].z-pts[1].z);
    d2=sqrt(d2);

    detd=(d1-d2)/2.0;

    h1=bj[0]*bj[0]-detd*detd;
    h1=sqrt(h1);
    h2=bj[1]*bj[1]-detd*detd;
    h2=sqrt(h2);
    h0=(h1+h2)/2.0;

    ///20180112whq修改，用于防止分母为0
    dbval=(bj[0]*bj[0]-bj[1]*bj[1])/(2.0*h0*d2+0.0000000001);
    dbval=asin(dbval);
    pts[0].x=-(h0+d2*sin(dbval)/2.0);
    pts[1].x=-(h0-d2*sin(dbval)/2.0);
    //trace(0,"mtg_std_fj:ux=%.4f,dx=%.4f\n",pts[0].x,pts[1].x);
    //trace(0,"mtg_std_fj:uy=%.4f,dy=%.4f\n",pts[0].y,pts[1].y);
    //trace(0,"mtg_std_fj:uz=%.4f,dz=%.4f\n",pts[0].z,pts[1].z);
    if(res)
    {
        ax=pts[2].x-pts[3].x;
        ay=pts[2].y-pts[3].y;
        az=pts[2].z-pts[3].z;

        bx=pts[1].x-pts[0].x;
        by=pts[1].y-pts[0].y;
        bz=pts[1].z-pts[0].z;

        a=ay*bz-az*by;
        b=az*bx-ax*bz;
        c=ax*by-ay*bx;
        d=sqrt(a*a+b*b);

        res[0]=atan2(b,a);
        res[1]=atan(c/d);
        d=pts[0].x+pts[1].x+pts[2].x+pts[3].x;
        res[2]=d/4.0+mtg->tbm.L[7];
        mtg->m.baj[0]=res[2]+r1*tan(res[1]);
        mtg->m.baj[1]=res[2]-r1*tan(res[1]);
        mtg->m.baj[2]=res[2]-r1*tan(res[0]);
        mtg->m.baj[3]=res[2]+r1*tan(res[0]);
    }
    //trace(0,"mtg_std_fj:a=%.4f,b=%.4f,c=%.4f\n",res[0],res[1],res[2]);
    return 0;
}

extern int mtg_std_fj(mtg_t* mtg,double* res)
{
    int i,j;
    double yi[4];
    double zi[4];
    point3d_t pts[4];
    double r1,r2;
    double fj[4];
    double beta[4];
    double d0,d1,d2,detd;
    double h0,h1,h2;
    double len,roll;
    double ax,ay,az;
    double bx,by,bz;
    double a,b,c,d;
    double dbval;
    double arc[4];
    double temp;
    int errordata=0;

    //FILE* fp=fopen("D:\\mtg_std_fj.log","w");
    r1=mtg->tbm.D[1]/2.0;
    r2=mtg->tbm.D[2]/2.0;
    roll=mtg->m1.inc1[0]*PI/180.0;

    detd=r1-r2;
    len=mtg->tbm.L[5];
    len=len*len+detd*detd;
    len=sqrt(len);
    //trace(0,"mtg_std_fj:len=%.4f\n",len);
    pts[0].z=0.0;
    pts[1].z=0.0;
    pts[2].y=0.0;
    pts[3].y=0.0;

    ///20180112whq增加,当铰接油缸数据出现异常值时，则让其计算结果mtg->m.faj相应值为-10000，该数将存储于数据库
    for(i=0;i<4;i++)
    {
        mtg->m.faj[i]=mtg->fj[i];
        if(mtg->m.faj[i]>100000)
        {
            mtg->m.faj[i]=-100000;
            errordata++;
        }
    }
    if(errordata>0)
    {
        return -1;
    }
    ///20180112whq增加结束

    for(i=0;i<4;i++)
    {
        arc[i]=mtg->tbm.fj[i]+roll;
    }
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(arc[i]>arc[j])
            {
                temp=arc[i];
                arc[i]=arc[j];
                arc[j]=temp;
                temp=mtg->m.faj[i];
                mtg->m.faj[i]=mtg->m.faj[j];
                mtg->m.faj[j]=temp;
            }
        }
    }
    ///20171130whq修改pts[0]/pts[1]/pts[2]/pts[3]的判断语句，加入三个等号
    for(i=0;i<4;i++)
    {
        yi[i]=r2*cos(arc[i]);
        zi[i]=-r2*sin(arc[i]);
        //trace(0,"mtg_std_fj:i=%d,yi=%.4f,zi=%.4f\n",i,yi[i],zi[i]);
        if(zi[i]>=pts[0].z)
        {
            pts[0].z=zi[i];
            pts[0].y=yi[i];
            fj[0]=mtg->m.faj[i]+len;
            beta[0]=arc[i];
        }
        if(zi[i]<=pts[1].z)
        {
            pts[1].z=zi[i];
            pts[1].y=yi[i];
            fj[1]=mtg->m.faj[i]+len;
            beta[1]=arc[i];
        }
        if(yi[i]<=pts[2].y)
        {
            pts[2].y=yi[i];
            pts[2].z=zi[i];
            fj[2]=mtg->m.faj[i]+len;
            beta[2]=arc[i];
        }
        if(yi[i]>pts[3].y)
        {
            pts[3].y=yi[i];
            pts[3].z=zi[i];
            fj[3]=mtg->m.faj[i]+len;
            beta[3]=arc[i];
        }
    }
    //trace(0,"mtg_std_fj:uy=%.4f,uz=%.4f\n",pts[0].y,pts[0].z);
    //trace(0,"mtg_std_fj:dy=%.4f,dz=%.4f\n",pts[1].y,pts[1].z);
    //trace(0,"mtg_std_fj:ly=%.4f,lz=%.4f\n",pts[2].y,pts[2].z);
    //trace(0,"mtg_std_fj:ry=%.4f,rz=%.4f\n",pts[3].y,pts[3].z);
    for(i=0;i<4;i++)
    {
        yi[i]=r1*cos(beta[i]);
        zi[i]=-r1*sin(beta[i]);
        //trace(0,"mtg_std_fj:i=%d,y=%.4f,z=%.4f\n",i,yi[i],zi[i]);
    }
    //trace(0,"mtg_std_fj:u=%.4f,d=%.4f,l=%.4f,r=%.4f\n",fj[0],fj[1],fj[2],fj[3]);
    d1=(yi[2]-yi[3])*(yi[2]-yi[3])+(zi[2]-zi[3])*(zi[2]-zi[3]);
    d1=sqrt(d1);
    d2=(pts[2].y-pts[3].y)*(pts[2].y-pts[3].y)+(pts[2].z-pts[3].z)*(pts[2].z-pts[3].z);
    d2=sqrt(d2);

    //trace(0,"mtg_std_fj:d1=%.4f,d2=%.4f\n",d1,d2);
    detd=(d1-d2)/2.0;

    h1=fj[2]*fj[2]-detd*detd;
    h1=sqrt(h1);
    h2=fj[3]*fj[3]-detd*detd;
    h2=sqrt(h2);
    h0=(h1+h2)/2.0;

    ///20180112whq修改，用于防止分母为0
    dbval=(fj[2]*fj[2]-fj[3]*fj[3])/(2.0*h0*d2+0.0000000001);
    dbval=asin(dbval);
    //trace(0,"mtg_std_fj:h1=%.4f,h2=%.4f\n",h1,h2);
    pts[2].x=h0+d2*sin(dbval)/2.0;
    pts[3].x=h0-d2*sin(dbval)/2.0;
    trace(0,"mtg_std_fj:lx=%.4f,rx=%.4f\n",pts[2].x,pts[3].x);
    trace(0,"mtg_std_fj:ly=%.4f,ry=%.4f\n",pts[2].y,pts[3].y);
    trace(0,"mtg_std_fj:lz=%.4f,rz=%.4f\n",pts[2].z,pts[3].z);

    d1=(yi[0]-yi[1])*(yi[0]-yi[1])+(zi[0]-zi[1])*(zi[0]-zi[1]);
    d1=sqrt(d1);
    d2=(pts[0].y-pts[1].y)*(pts[0].y-pts[1].y)+(pts[0].z-pts[1].z)*(pts[0].z-pts[1].z);
    d2=sqrt(d2);

    detd=(d1-d2)/2.0;

    h1=fj[0]*fj[0]-detd*detd;
    h1=sqrt(h1);
    h2=fj[1]*fj[1]-detd*detd;
    h2=sqrt(h2);
    h0=(h1+h2)/2.0;

    ///20180112whq修改，用于防止分母为0
    dbval=(fj[0]*fj[0]-fj[1]*fj[1])/(2.0*h0*d2+0.0000000001);
    dbval=asin(dbval);
    pts[0].x=h0+d2*sin(dbval)/2.0;
    pts[1].x=h0-d2*sin(dbval)/2.0;
    //trace(0,"mtg_std_fj:ux=%.4f,dx=%.4f\n",pts[0].x,pts[1].x);
    //trace(0,"mtg_std_fj:uy=%.4f,dy=%.4f\n",pts[0].y,pts[1].y);
    //trace(0,"mtg_std_fj:uz=%.4f,dz=%.4f\n",pts[0].z,pts[1].z);
    if(res)
    {
        ax=pts[2].x-pts[3].x;
        ay=pts[2].y-pts[3].y;
        az=pts[2].z-pts[3].z;

        bx=pts[1].x-pts[0].x;
        by=pts[1].y-pts[0].y;
        bz=pts[1].z-pts[0].z;

        a=ay*bz-az*by;
        b=az*bx-ax*bz;
        c=ax*by-ay*bx;
        d=sqrt(a*a+b*b);
        //trace(0,"mtg_std_fj:a=%.4f,b=%.4f,c=%.4f\n",a,b,c);
        res[0]=atan2(b,a);
        res[1]=atan(c/d);
        d=pts[0].x+pts[1].x+pts[2].x+pts[3].x;
        res[2]=d/4.0-mtg->tbm.L[5];
        mtg->m.faj[0]=res[2]-r1*tan(res[1]);
        mtg->m.faj[1]=res[2]+r1*tan(res[1]);
        mtg->m.faj[2]=res[2]+r1*tan(res[0]);
        mtg->m.faj[3]=res[2]-r1*tan(res[0]);
    }
    trace(0,"mtg_std_fj:a=%.4f,b=%.4f,c=%.4f\n",res[0],res[1],res[2]);
    //fclose(fp);
    return 0;
}

extern int mtg_std_fj_hzshj(mtg_t* mtg,double* res)
{
    int i,j;
    double yi[4];
    double zi[4];
    point3d_t pts[4];
    double r1,r2;
    double fj[4];
    double beta[4];
    double d0,d1,d2,detd;
    double h0,h1,h2;
    double len,roll;
    double ax,ay,az;
    double bx,by,bz;
    double a,b,c,d;
    double dbval;
    double arc[4];
    double temp;
    int errordata=0;
    //char* filepath;
    FILE* fp=NULL;
    //char buf[1024]={0};
    double dazi=0.0,dpitch=0.0;
    double dl;

    //filepath=_getcwd(NULL,0);
    //sprintf(buf,"%s\\mtg_std_fj.log",filepath);
    //fp=fopen(buf,"w");

    r1=mtg->tbm.D[1]/2.0;
    r2=mtg->tbm.D[2]/2.0;
    roll=mtg->m1.inc1[0]*PI/180.0;

    detd=r1-r2;
    len=mtg->tbm.L[5];
    len=len*len+detd*detd;
    len=sqrt(len);
    //trace(0,"mtg_std_fj:len=%.4f\n",len);
    pts[0].z=0.0;
    pts[1].z=0.0;
    pts[2].y=0.0;
    pts[3].y=0.0;

    ///20180112whq增加,当铰接油缸数据出现异常值时，则让其计算结果mtg->m.faj相应值为-10000，该数将存储于数据库
    for(i=0;i<4;i++)
    {
        mtg->m.faj[i]=mtg->fj[i];
        if(fp)
        {
            fprintf(fp,"faj[%d]:%.4f\n",i,mtg->m.faj[i]);
            fflush(fp);
        }
        if(mtg->fj[i]>100000)
        {
            mtg->m.faj[i]=-100000;
            errordata++;
        }
    }
    if(errordata>0)
    {
        return -1;
    }
    ///20180112whq增加结束

    for(i=0;i<4;i++)
    {
        arc[i]=mtg->tbm.fj[i];
    }
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(arc[i]>arc[j])
            {
                temp=arc[i];
                arc[i]=arc[j];
                arc[j]=temp;
                temp=mtg->m.faj[i];
                mtg->m.faj[i]=mtg->m.faj[j];
                mtg->m.faj[j]=temp;
            }
        }
    }
    ///20171130whq修改pts[0]/pts[1]/pts[2]/pts[3]的判断语句，加入三个等号
    for(i=0;i<4;i++)
    {
        yi[i]=r2*cos(arc[i]);
        zi[i]=-r2*sin(arc[i]);
        if(fp)
        {
            fprintf(fp,"arc[%d]:%.4f\n",i,arc[i]);
            fflush(fp);
        }
        //trace(0,"mtg_std_fj:i=%d,yi=%.4f,zi=%.4f\n",i,yi[i],zi[i]);
        if(zi[i]>=pts[0].z)
        {
            pts[0].z=zi[i];
            pts[0].y=yi[i];
            fj[0]=mtg->m.faj[i]+len;
            beta[0]=arc[i];
        }
        if(zi[i]<=pts[1].z)
        {
            pts[1].z=zi[i];
            pts[1].y=yi[i];
            fj[1]=mtg->m.faj[i]+len;
            beta[1]=arc[i];
        }
        if(yi[i]<=pts[2].y)
        {
            pts[2].y=yi[i];
            pts[2].z=zi[i];
            fj[2]=mtg->m.faj[i]+len;
            beta[2]=arc[i];
        }
        if(yi[i]>pts[3].y)
        {
            pts[3].y=yi[i];
            pts[3].z=zi[i];
            fj[3]=mtg->m.faj[i]+len;
            beta[3]=arc[i];
        }
    }

    //trace(0,"mtg_std_fj:uy=%.4f,uz=%.4f\n",pts[0].y,pts[0].z);
    //trace(0,"mtg_std_fj:dy=%.4f,dz=%.4f\n",pts[1].y,pts[1].z);
    //trace(0,"mtg_std_fj:ly=%.4f,lz=%.4f\n",pts[2].y,pts[2].z);
    //trace(0,"mtg_std_fj:ry=%.4f,rz=%.4f\n",pts[3].y,pts[3].z);
    for(i=0;i<4;i++)
    {
        yi[i]=r1*cos(beta[i]);
        zi[i]=-r1*sin(beta[i]);
        if(fp)
        {
            fprintf(fp,"beta[%d]:%.4f\n",i,beta[i]);
            fflush(fp);
        }
        //trace(0,"mtg_std_fj:i=%d,y=%.4f,z=%.4f\n",i,yi[i],zi[i]);
    }
    //下面是临时为杭州舜杰项目制定的计算方法，由于铰接只有上左右，pts[1]的数据没有

    for(i=0;i<4;i++)
    {
        pts[i].x=fj[i];
        if(fp)
        {
            fprintf(fp,"fj[%d]:%.4f,%.4f,%.4f\n",i,pts[i].x,pts[i].y,pts[i].z);
            fflush(fp);
        }
    }
    d1=(pts[2].y-pts[3].y)*(pts[2].y-pts[3].y)+(pts[2].z-pts[3].z)*(pts[2].z-pts[3].z);
    d1=sqrt(d1);
    dazi=atan((pts[2].x-pts[3].x)/d1);

    dl=r1*cos(beta[1]);
    if(fp)
    {
        fprintf(fp,"dl:%.4f\n",dl);
    }
    dl+=r1;
    if(fp)
    {
        fprintf(fp,"dl:%.4f\n",dl);
    }
    dl-=(r1*2-d1)/2.0;
    if(fp)
    {
        fprintf(fp,"dl:%.4f\n",dl);
    }
    pts[1].x=(pts[3].x-pts[2].x)/d1*dl+pts[2].x;
    pts[1].y=(pts[3].y-pts[2].y)/d1*dl+pts[2].y;
    pts[1].z=(pts[3].z-pts[2].z)/d1*dl+pts[2].z;
    if(fp)
    {
        fprintf(fp,"pts[1].x:%.4f\n",pts[1].x);
    }
    d2=(pts[0].y-pts[1].y)*(pts[0].y-pts[1].y)+(pts[0].z-pts[1].z)*(pts[0].z-pts[1].z);
    d2=sqrt(d2);
    dpitch=atan((pts[1].x-pts[0].x)/d2);

    res[0]=dazi;
    res[1]=dpitch;
    d=pts[0].x+pts[1].x+pts[2].x+pts[3].x;
    ///20181011whq发现对于舜杰项目专用的该函数此处存在问题，主要原因是fj[i]赋值值未加入len
    res[2]=d/4.0-mtg->tbm.L[5];

    if(fp)
    {
        fprintf(fp,"dazi:%.4f°,dpitch:%.4f°",dazi*180/PI,dpitch*180/PI);
        fflush(fp);
        fclose(fp);
        fp=NULL;
    }
    trace(0,"mtg_std_fj:a=%.4f,b=%.4f,c=%.4f\n",res[0],res[1],res[2]);
    //fclose(fp);
    return 0;
}

extern int mtg_prism_gesture(mtg_t* mtg)
{
    transform3d_t trans;
    point3d_t psm1[2],psm2[2];
    point3d_t head,tail,left;
    double roll,pitch;
    int flags[]={0,0,1,1,1,1,0};
    double inc[2];
    MTG_MP* mp=0;
    double d1,d2;
    int a2z=mtg->prj.a2z;

    mp=&mtg->mp;

    if(mtg->tarset.baseinc==1)
    {
        inc[0]=mtg->mp.inc[5]*PI/180.0;
        inc[1]=mtg->mp.inc[6]*PI/180.0;
    }
    else
    {
        inc[0]=mtg->mp.inc[0]*PI/180.0;
        inc[1]=mtg->mp.inc[1]*PI/180.0;
    }

    ///侧转
    roll=inc[0];
    ///俯仰
    pitch=inc[1];
    ///修正滚动角
    roll=atan(tan(roll)/cos(pitch));
    transform3d_init(&trans,roll,pitch,0,0,0,0,1);

    psm1[0].x=mtg->mppsm1[0];
    psm1[0].y=mtg->mppsm1[1];
    psm1[0].z=mtg->mppsm1[2];
    psm1[1].x=0;
    psm1[1].y=0;
    psm1[1].z=0;

    psm2[0].x=mp->prism[9];
    psm2[0].y=mp->prism[10];
    psm2[0].z=mp->prism[11];

    psm2[1].x=mtg->m.prism[0];
    psm2[1].y=mtg->m.prism[1];
    psm2[1].z=mtg->m.prism[2];

    if(transform3d_init_points(&trans,2,psm1,psm2,flags)!=1) return -1;

    ///七参数坐标转化
    head.x=mtg->head[0];
    head.y=mtg->head[1];
    head.z=mtg->head[2];
    transform3d_trans(&trans,&head,&head);
    tail.x=mtg->tail[0];
    tail.y=mtg->tail[1];
    tail.z=mtg->tail[2];
    transform3d_trans(&trans,&tail,&tail);

    left.x=mtg->left[0];
    left.y=mtg->left[1];
    left.z=mtg->left[2];
    transform3d_trans(&trans,&left,&left);

    mp->head[0]=head.x;
    mp->head[1]=head.y;
    mp->head[2]=head.z;

    mp->tail[0]=tail.x;
    mp->tail[1]=tail.y;
    mp->tail[2]=tail.z;

    ///偏差计算
    road_xy2l(&mtg->r,mp->head[0],mp->head[1],&mp->headc,0,0,0,&mp->headh);
    road_l2h(&mtg->r,mp->headc,&mp->headv,0);
    mp->headv=mp->head[2]-mp->headv;
    road_xy2l(&mtg->r,mp->tail[0],mp->tail[1],&mp->tailc,0,0,0,&mp->tailh);
    road_l2h(&mtg->r,mp->tailc,&mp->tailv,0);
    mp->tailv=mp->tail[2]-mp->tailv;

    mp->headh=mp->headh*a2z;
    mp->tailh=mp->tailh*a2z;

    d1 = point3d_dist(&head,&tail);
    d2 = sqrt((left.x-tail.x)*(left.x-tail.x)+(left.y-tail.y)*(left.y-tail.y));

    mp->inc[1]=atan((head.z-tail.z)/d1);
    mp->inc[0]=-atan((left.z-tail.z)/d2);
    mp->inc[0]=atan(tan(mp->inc[0])/cos(mp->inc[1]));
    mp->inc[2]=atan2(head.y-tail.y,head.x-tail.x);
    if(mp->inc[2]<0.0) mp->inc[2] = mp->inc[2]+2*PI;
    mp->inc[0]=mp->inc[0]*180.0/PI;
    mp->inc[1]=mp->inc[1]*180.0/PI;
    mp->inc[2]=mp->inc[2]*180.0/PI;

    trace(0,"2pgesture:headx=%f,heady=%f,headz=%f\n",head.x,head.y,head.z);
    trace(0,"2pgesture:tailx=%f,taily=%f,tailz=%f\n",tail.x,tail.y,tail.z);

    return 0;
}

extern int mtg_tbm_incline(mtg_t* mtg)
{
    double pitch,roll;
    transform3d_t trans;
    point3d_t pt1,pt2;
    double len=395.7;
    double ori;
    point3d_t head,tail,left;
    double inc[2];
    MTG_MEASURE* m=0;
    double dist;

    len=mtg->tarset.length;

    m=&mtg->m1;

    if(mtg->tarset.baseinc==1)
    {
        inc[0]=m->inc[5]*PI/180.0;
        inc[1]=m->inc[6]*PI/180.0;
    }
    else
    {
        inc[0]=m->inc[0]*PI/180.0;
        inc[1]=m->inc[1]*PI/180.0;
    }

    ///侧转
    roll=inc[0];
    ///俯仰
    pitch=inc[1];

    ///修正滚动角
    roll=atan(tan(roll)/cos(pitch));
    transform3d_init(&trans,roll,pitch,0.0,0,0,0,1);
    head.x=mtg->head[0];
    head.y=mtg->head[1];
    head.z=mtg->head[2];
    tail.x=mtg->tail[0];
    tail.y=mtg->tail[1];
    tail.z=mtg->tail[2];
    left.x=mtg->left[0];
    left.y=mtg->left[1];
    left.z=mtg->left[2];

    transform3d_trans(&trans,&head,&head);
    transform3d_trans(&trans,&tail,&tail);
    transform3d_trans(&trans,&left,&left);

    dist=sqrt((head.x-tail.x)*(head.x-tail.x)+(head.y-tail.y)*(head.y-tail.y));
    if(dist==0)
    {
        m->inc1[1]=pitch;
        m->inc1[0]=roll;
    }
    else
    {
        m->inc1[1]=atan((head.z-tail.z)/dist);
        m->inc1[0]=-atan((left.z-tail.z)/sqrt((left.x-tail.x)*(left.x-tail.x)+(left.y-tail.y)*(left.y-tail.y)));
        m->inc1[0]=atan(tan(m->inc1[0])/cos(m->inc1[1]));
    }
    m->inc1[1]=m->inc1[1]*180.0/PI;
    m->inc1[0]=m->inc1[0]*180.0/PI;

    return 0;
}

extern int mtg_tbm_azimuth(mtg_t* mtg)
{
    double pitch,roll;
    transform3d_t trans;
    point3d_t pt1,pt2;
    double len;
    double ori;
    point3d_t head,tail,left;
    double inc[2];
    point2d_t u1,u2;
    affine_t aff;
    MTG_MEASURE* m=0;

    len=mtg->tarset.length;

    m=&mtg->m;


    if(mtg->tarset.baseinc==1)
    {
        inc[0]=m->inc[5]*PI/180.0;
        inc[1]=m->inc[6]*PI/180.0;
    }
    else
    {
        inc[0]=m->inc[0]*PI/180.0;
        inc[1]=m->inc[1]*PI/180.0;
    }
    ///俯仰
    roll=inc[0];
    ///侧转
    pitch=inc[1];
    ///修正滚动角
    roll=atan(tan(roll)/cos(pitch));
    ///注意角度正负号
    transform3d_init(&trans,roll,pitch,0,0,0,0,1);

    ///前屏
    pt1.x=pt1.y=pt1.z=0.0;
    ///后屏
    affine_init(&aff,mtg->camset[0].affine);
    //for(i=0;i<9;i++) trace(0,"%f\n",mtg->camset[0].affine[i]);
    u1.x=m->cam[0];
    u1.y=mtg->camset[0].h-m->cam[1];
    //trace(0,"u1=%f,%f\n",u1.x,u1.y);
    affine_trans(&aff,&u1,&u2);
    trace(0,"u2=%f,%f\n",u2.x,u2.y);
    pt2.x=len;
    pt2.y=u2.x;
    pt2.z=u2.y;
    //trace(0,"pt1:%f,%f,%f\n",pt1.x,pt1.y,pt1.z);
    transform3d_trans(&trans,&pt2,&pt2);
    trace(0,"pt2:%f,%f,%f\n",pt2.x,pt2.y,pt2.z);

    ori=atan2(pt2.y-pt1.y,pt2.x-pt1.x);

    ///激光耙方位角
    ori=m->angle[0]-ori;
    ///激光耙坐标系转到大地坐标系
    transform3d_init(&trans,roll,pitch,-ori,0,0,0,1);
    head.x=mtg->head[0];
    head.y=mtg->head[1];
    head.z=mtg->head[2];
    tail.x=mtg->tail[0];
    tail.y=mtg->tail[1];
    tail.z=mtg->tail[2];
    left.x=mtg->left[0];
    left.y=mtg->left[1];
    left.z=mtg->left[2];
    transform3d_trans(&trans,&head,&head);
    transform3d_trans(&trans,&tail,&tail);
    transform3d_trans(&trans,&left,&left);

    ///姿态角计算
    m->inc1[1]=atan((head.z-tail.z)/sqrt((head.x-tail.x)*(head.x-tail.x)+(head.y-tail.y)*(head.y-tail.y)));
    m->inc1[0]=-atan((left.z-tail.z)/sqrt((left.x-tail.x)*(left.x-tail.x)+(left.y-tail.y)*(left.y-tail.y)));
    m->inc1[0]=atan(tan(m->inc1[0])/cos(m->inc1[1]));
    m->inc1[1]=atan2(head.y-tail.y,head.x-tail.x);

    return 0;
}

extern int mtg_laser_incline(mtg_t* mtg)
{
    double pitch,roll;
    transform3d_t trans;
    point3d_t pt1,pt2;
    double len;
    double ori;
    double inc[2];
    point2d_t u1,u2;
    affine_t aff;
    MTG_MEASURE* m=0;
    double val=0.0;

    len=mtg->tarset.length;

    m=&mtg->m;

    if(mtg->tarset.baseinc==1)
    {
        inc[0]=mtg->m.inc[5]*PI/180.0;
        inc[1]=mtg->m.inc[6]*PI/180.0;
    }
    else
    {
        inc[0]=mtg->m.inc[0]*PI/180.0;
        inc[1]=mtg->m.inc[1]*PI/180.0;
    }
    ///俯仰
    roll=inc[0];
    ///侧转
    pitch=inc[1];
    ///修正滚动角
    roll=atan(tan(roll)/cos(pitch));
    ///注意角度正负号
    transform3d_init(&trans,roll,pitch,0,0,0,0,1);

    ///前屏
    pt1.x=pt1.y=pt1.z=0.0;
    ///后屏
    affine_init(&aff,mtg->camset[0].affine);

    u1.x=m->cam[0];
    u1.y=mtg->camset[0].h-m->cam[1];
    affine_trans(&aff,&u1,&u2);
    pt2.x=len;
    pt2.y=u2.x;
    pt2.z=u2.y;
    pitch=asin(pt2.z/len);
    pitch=atan(tan(pitch)/cos(inc[0]));
    pitch=PI/2.0-m->angle[1]-pitch;
    m->inc[3]=pitch*180.0/PI;

    transform3d_trans(&trans,&pt2,&pt2);
    ///激光耙方位角
    ori=atan2(pt2.y-pt1.y,pt2.x-pt1.x);
    ori=m->angle[0]-ori;
    if(ori<0) ori+=2*PI;
    else if(ori>=2*PI) ori-=2*PI;
    m->inc[2]=ori*180.0/PI;

//    val=AddAzi(ori);
//    m->inc[2]=val*180.0/PI;


    return 0;
}

extern int mtg_cal_prism(mtg_t* mtg,double mile,double prism[3])
{
    double x,y,z;
    double ori=0.0;
    int flag[7]={0,0,0,1,1,1,0};
    point3d_t head;
    transform3d_t t;
    double len=0.0;
    double dx,dy,dz;

    dx=mtg->m0.head[0]-mtg->m0.tail[0];
    dy=mtg->m0.head[1]-mtg->m0.tail[1];
    dz=mtg->m0.head[2]-mtg->m0.tail[2];
    len=sqrt(dx*dx+dy*dy+dz*dz);

    mile-=len;
    ///零位转到当前
    head.x=mtg->tail[0];
    head.y=mtg->tail[1];
    head.z=mtg->tail[2];
    road_l2xy(&mtg->r,mile,&x,&y,&ori);
    if(mtg->prj.a2z==-1)
    {
        ori = ori+PI;
        if(ori>2*PI) ori=ori-2*PI;
    }
    road_l2h(&mtg->r,mile,&z,0);
    transform3d_init(&t,0,0,-ori,0,0,0,1);
    transform3d_trans(&t,&head,&head);
    //transform3d_trans(&t,&target,&target);
    ///平移
    prism[0]=x-head.x;
    prism[1]=y-head.y;
    prism[2]=z-head.z;
    return 0;
}

extern int mtg_cal_position(mtg_t* mtg,double* h,double* v)
{
    transform3d_t trans;
    double roll,pitch,ori;
    point3d_t p1,p2;
    point3d_t tail;
    double dh,dv;
    double dx,dy,dz,dl;
    double laserx,lasery;

    if(mtg->m0.t1<=0) return -1;

    if(mtg->tarset.baseinc==1)
    {
        roll=mtg->m.inc[5]*PI/180.0;
        pitch=mtg->m.inc[6]*PI/180.0;
    }
    else
    {
        roll=mtg->m.inc[0]*PI/180.0;
        pitch=mtg->m.inc[1]*PI/180.0;
    }
    roll=atan(tan(roll)/cos(pitch));
    ori=mtg->m1.inc[2]*PI/180.0;

    tail.x=mtg->m1.tail[0];
    tail.y=mtg->m1.tail[1];
    tail.z=mtg->m1.tail[2];

    transform3d_init(&trans,roll,pitch,-ori,tail.x,tail.y,tail.z,1);

    p1.x=mtg->tarset.prism[0];
    p1.y=mtg->tarset.prism[1];
    p1.z=mtg->tarset.prism[2];
    transform3d_trans(&trans,&p1,&p1);
    p2.x=0.0;
    p2.y=0.0;
    p2.z=0.0;
    transform3d_trans(&trans,&p2,&p2);

    dx=p1.x-mtg->istn.statx;
    dy=p1.y-mtg->istn.staty;
    dz=p1.z-mtg->istn.statz-mtg->istn.stath;
    dh=atan2(dy,dx);
    if(dh<0) dh+=2*PI;
    dl=sqrt(dx*dx+dy*dy);
    dv=PI/2-atan(dz/dl);

    h[0]=dh;
    v[0]=dv;

    dx=p2.x-mtg->istn.statx;
    dy=p2.y-mtg->istn.staty;
    dz=p2.z-mtg->istn.statz-mtg->istn.stath;
    dh=atan2(dy,dx);
    if(dh<0) dh+=2*PI;
    dl=sqrt(dx*dx+dy*dy);
    dv=PI/2-atan(dz/dl);

    h[1]=dh;
    v[1]=dv;

    return 0;
}

extern int mtg_std_bj_sym(mtg_t* mtg,double* res)
{
    int i,j;
    point3d_t pts[4];
    double r1,r2;
    double bj[4];
    double beta[4];
    double arc[4];
    double len,dh,dv,d;
    double roll;
    double dbval;
    double d1,d2,d3,d4;
    double disth,distv;
    double yi[4];
    double zi[4];
    double temp;
    int errordata=0;

    FILE* fp=fopen("D:\\midu\\mtg_std_bj_sym.log","w");
    r1=mtg->tbm.D[3]/2.0;
    r2=mtg->tbm.D[4]/2.0;
    roll=mtg->m1.inc1[0]*PI/180.0;
    len=mtg->tbm.L[7];

    ///20180112whq增加,当铰接油缸数据出现异常值时，则让其计算结果mtg->m.faj相应值为-10000，该数将存储于数据库
    for(i=0;i<4;i++)
    {
        fprintf(fp,"bj%d=%.4f\n",i,mtg->bj[i]);
        mtg->m.baj[i]=mtg->bj[i];
        if(mtg->m.baj[i]>100000)
        {
            mtg->m.baj[i]=-100000;
            errordata++;
        }
    }
    if(errordata>0)
    {
        return -1;
    }
    ///20180112whq增加结束

    for(i=0;i<4;i++)
    {
        arc[i]=mtg->tbm.bj[i]+roll;
    }
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(arc[i]>arc[j])
            {
                temp=arc[i];
                arc[i]=arc[j];
                arc[j]=temp;
                temp=mtg->m.baj[i];
                mtg->m.baj[i]=mtg->m.baj[j];
                mtg->m.baj[j]=temp;
            }
        }
    }
    ///20171130whq修改pts[0]/pts[1]/pts[2]/pts[3]的判断语句，加入三个等号
    for(i=0;i<4;i++)
    {
        if(arc[i]>0&&arc[i]<PI/2)
        {
            bj[0]=mtg->m.baj[i]+len;
            beta[0]=arc[i];
        }
        else if(arc[i]>PI/2&&arc[i]<PI)
        {
            bj[1]=mtg->m.baj[i]+len;
            beta[1]=arc[i];
        }
        else if(arc[i]>PI&&arc[i]<PI*3/2)
        {
            bj[2]=mtg->m.baj[i]+len;
            beta[2]=arc[i];
        }
        else if(arc[i]>PI*3/2&&arc[i]<2*PI)
        {
            bj[3]=mtg->m.baj[i]+len;
            beta[3]=arc[i];
        }
    }

    d1=(yi[0]-yi[1])*(yi[0]-yi[1])+(zi[0]-zi[1])*(zi[0]-zi[1]);
    d1=sqrt(d1);
    d2=(yi[2]-yi[3])*(yi[2]-yi[3])+(zi[2]-zi[3])*(zi[2]-zi[3]);
    d2=sqrt(d2);
    disth=(d1+d2)/2.0; ///水平距离

    d3=(yi[0]-yi[3])*(yi[0]-yi[3])+(zi[0]-zi[3])*(zi[0]-zi[3]);
    d3=sqrt(d3);
    d4=(yi[2]-yi[1])*(yi[2]-yi[1])+(zi[2]-zi[1])*(zi[2]-zi[1]);
    d4=sqrt(d4);
    distv=(d3+d4)/2.0;  ///垂直距离

    dv = ((bj[1]+bj[0])-(bj[2]+bj[3]))/2.0;//下-上
    dh = ((bj[1]+bj[2])-(bj[0]+bj[3]))/2.0;//左-右
    if(res)
    {
        if(disth>0) res[0]=atan(-dh/disth);
        else res[0]=0.0;
        if(distv>0) res[1]=atan(-dv/distv);
        else res[1]=0.0;
        d=bj[0]+bj[1]+bj[2]+bj[3];
//        res[2]=d/4.0-mtg->tbm.L[7];
//        mtg->m.baj[0]=res[2]+r1*tan(res[1]);
//        mtg->m.baj[1]=res[2]-r1*tan(res[1]);
//        mtg->m.baj[2]=res[2]-r1*tan(res[0]);
//        mtg->m.baj[3]=res[2]+r1*tan(res[0]);
        ///20190902whq 修改成下面
        res[2]=d/4.0+mtg->tbm.L[7];
        mtg->m.baj[0]=res[2]+r1*tan(res[1]);
        mtg->m.baj[1]=res[2]-r1*tan(res[1]);
        mtg->m.baj[2]=res[2]-r1*tan(res[0]);
        mtg->m.baj[3]=res[2]+r1*tan(res[0]);
    }
    if(fp)
    {
        fprintf(fp,"bj:%.4f,%.4f,%.4f,%.4f\n",bj[0],bj[1],bj[2],bj[3]);
        fprintf(fp,"mtg_std_bj:%.4f,%.4f,%.4f,%.4f\n",mtg->m.baj[0],mtg->m.baj[1],mtg->m.baj[2],mtg->m.baj[3]);
        fprintf(fp,"mtg_std_bj_:res0=%.4f,res1=%.4f,res2=%.4f\n",res[0],res[1],res[2]);
        fclose(fp);
    }
    return 0;
}

extern int mtg_std_fj_sym(mtg_t* mtg,double* res)
{
    int i,j;
    point3d_t pts[4];
    double r1,r2;
    double fj[4];
    double beta[4];
    double arc[4];
    double len,dh,dv,d;
    double roll;
    double dbval;
    double d1,d2,d3,d4;
    double disth,distv;
    double yi[4];
    double zi[4];
    double temp;
    int errordata=0;

    FILE* fp=fopen("D:\\midu\\mtg_std_fj_sym.log","w");
    r1=mtg->tbm.D[1]/2.0;
    r2=mtg->tbm.D[2]/2.0;
    roll=mtg->m1.inc1[0]*PI/180.0;
    len=mtg->tbm.L[5];

    ///20180112whq增加,当铰接油缸数据出现异常值时，则让其计算结果mtg->m.faj相应值为-10000，该数将存储于数据库
    for(i=0;i<4;i++)
    {
        fprintf(fp,"fj%d=%.4f\n",i,mtg->fj[i]);
        mtg->m.faj[i]=mtg->fj[i];
        if(mtg->m.faj[i]>100000)
        {
            mtg->m.faj[i]=-100000;
            errordata++;
        }
    }
    if(errordata>0)
    {
        return -1;
    }
    ///20180112whq增加结束

    for(i=0;i<4;i++)
    {
        arc[i]=mtg->tbm.fj[i]+roll;
    }
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(arc[i]>arc[j])
            {
                temp=arc[i];
                arc[i]=arc[j];
                arc[j]=temp;
                temp=mtg->m.faj[i];
                mtg->m.faj[i]=mtg->m.faj[j];
                mtg->m.faj[j]=temp;
            }
        }
    }
    ///20171130whq修改pts[0]/pts[1]/pts[2]/pts[3]的判断语句，加入三个等号
    for(i=0;i<4;i++)
    {
        if(arc[i]>0&&arc[i]<PI/2)
        {
            fj[0]=mtg->m.faj[i]+len;
            beta[0]=arc[i];
        }
        else if(arc[i]>PI/2&&arc[i]<PI)
        {
            fj[1]=mtg->m.faj[i]+len;
            beta[1]=arc[i];
        }
        else if(arc[i]>PI&&arc[i]<PI*3/2)
        {
            fj[2]=mtg->m.faj[i]+len;
            beta[2]=arc[i];
        }
        else if(arc[i]>PI*3/2&&arc[i]<2*PI)
        {
            fj[3]=mtg->m.faj[i]+len;
            beta[3]=arc[i];
        }
    }

    for(i=0;i<4;i++)
    {
        yi[i]=r2*cos(beta[i]);
        zi[i]=-r2*sin(beta[i]);
    }

    d1=(yi[0]-yi[1])*(yi[0]-yi[1])+(zi[0]-zi[1])*(zi[0]-zi[1]);
    d1=sqrt(d1);
    d2=(yi[2]-yi[3])*(yi[2]-yi[3])+(zi[2]-zi[3])*(zi[2]-zi[3]);
    d2=sqrt(d2);
    disth=(d1+d2)/2.0;

    d3=(yi[0]-yi[3])*(yi[0]-yi[3])+(zi[0]-zi[3])*(zi[0]-zi[3]);
    d3=sqrt(d3);
    d4=(yi[2]-yi[1])*(yi[2]-yi[1])+(zi[2]-zi[1])*(zi[2]-zi[1]);
    d4=sqrt(d4);
    distv=(d3+d4)/2.0;

    dv = ((fj[1]+fj[0])-(fj[2]+fj[3]))/2.0;///下-上
    dh = ((fj[1]+fj[2])-(fj[0]+fj[3]))/2.0;
    if(res)
    {
        if(disth>0) res[0]=atan(dh/disth);
        else res[0]=0.0;
        if(distv>0) res[1]=atan(dv/distv);
        else res[1]=0.0;

        d=fj[0]+fj[1]+fj[2]+fj[3];
        res[2]=d/4.0-mtg->tbm.L[5];
        mtg->m.faj[0]=res[2]-r1*tan(res[1]);
        mtg->m.faj[1]=res[2]+r1*tan(res[1]);
        mtg->m.faj[2]=res[2]+r1*tan(res[0]);
        mtg->m.faj[3]=res[2]-r1*tan(res[0]);
    }
    if(fp)
    {
        fprintf(fp,"disth:%.4f,distv:%.4f\n",disth,distv);
        fprintf(fp,"r1:%.4f,dh:%.4f,dv:%.4f,r2:%.4f\n",r1,dh,dv,r2);
        fprintf(fp,"fj:%.4f,%.4f,%.4f,%.4f\n",fj[0],fj[1],fj[2],fj[3]);
        fprintf(fp,"mtg_std_fj:%.4f,%.4f,%.4f,%.4f\n",mtg->m.faj[0],mtg->m.faj[1],mtg->m.faj[2],mtg->m.faj[3]);
        fprintf(fp,"mtg_std_fj_:res0=%.4f,res1=%.4f,res2=%.4f\n",res[0],res[1],res[2]);
        fclose(fp);
    }
    return 0;
}

///
extern int mtg_dc_meas_37(mtg_t* mtg,int dc)
{
    int i,n;
    double dcm;
    double dcm1;
    double detc;
    int step;
    ///dc:0前端水平，1处理前端垂直，2处理中水平，3处理中垂直，4处理尾水平，5处理尾垂直
    if(dc==0) dcm=mtg->m.hdev1;
    else if(dc==1) dcm=mtg->m.vdev1;
    else if(dc==2) dcm=mtg->m.hdev2;
    else if(dc==3) dcm=mtg->m.vdev2;
    else if(dc==4) dcm=mtg->m.hdev3;
    else if(dc==5) dcm=mtg->m.vdev3;

    ///mtg->dcm[dc]存储上次测量值
    ///mtg->dci[dc]存储上次姿态跳动持续次数
    ///dcm1本次姿态跳动数据
    if(mtg->dcm[dc]<100.0) dcm1=dcm-mtg->dcm[dc];
    else dcm1=0.0;
    detc=fabs(mtg->m.headc-mtg->m1.headc);

    if(detc>=0.07) dcm1=0.0;///里程差超过7cm，不做数据处理
    ///第一次测量，dcm1=0.0
    step=mtg->dci[dc];

    if(step==0)
    {
        if(dcm1>0.003)
        {
            ///姿态跳动大于4mm
            if(dcm1>=0.007)
            {
                mtg->dci[dc]=1;
            }
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else if(dcm1<-0.003)
        {
            ///姿态跳动大于4mm
            if(dcm1<=-0.007)
            {
                mtg->dci[dc]=-1;
            }
            dcm=mtg->dcm[dc];///取用上次的值
        }
    }
    else if(step==1)
    {
        if(dcm1>0.003)
        {
            ///姿态跳动大于4mm
            if(dcm1>=0.007)
            {
                mtg->dci[dc]=2;
            }
            else
            {
                mtg->dci[dc]=0;
            }
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else if(dcm1<-0.003)
        {
            mtg->dci[dc]=0;
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else
        {
            ///处理步骤归0
            mtg->dci[dc]=0;
        }
    }
    else if(step==2)
    {
        if(dcm1>0.003)
        {
            ///姿态跳动大于4mm
            if(dcm1>=0.007)
            {
                dcm=mtg->dcm[dc]+dcm1/4.0;
            }
            else
            {
                mtg->dci[dc]=0;
                dcm=mtg->dcm[dc];
            }
        }
        else if(dcm1<-0.003)
        {
            mtg->dci[dc]=0;
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else
        {
            ///处理步骤归0
            mtg->dci[dc]=0;
        }
    }
    else if(step==-1)
    {
        if(dcm1<-0.003)
        {
            if(dcm1<=-0.007)
            {
                mtg->dci[dc]=-2;
            }
            else
            {
                mtg->dci[dc]=0;
            }
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else if(dcm1>0.003)
        {
            mtg->dci[dc]=0;
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else
        {
            mtg->dci[dc]=0;
        }
    }
    else if(step==-2)
    {
        if(dcm1<-0.003)
        {
            if(dcm1<=-0.007)
            {
                dcm=mtg->dcm[dc]+dcm1/4.0;
            }
            else
            {
                mtg->dci[dc]=0;
                dcm=mtg->dcm[dc];
            }
        }
        else if(dcm1>0.003)
        {
            mtg->dci[dc]=0;
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else
        {
            ///处理步骤归0
            mtg->dci[dc]=0;
        }
    }

    mtg->dcm[dc]=dcm;
    if(dc==0) mtg->m.hdev1=dcm;
    else if(dc==1) mtg->m.vdev1=dcm;
    else if(dc==2) mtg->m.hdev2=dcm;
    else if(dc==3) mtg->m.vdev2=dcm;
    else if(dc==4) mtg->m.hdev3=dcm;
    else if(dc==5) mtg->m.vdev3=dcm;
    return 0;
}

extern int mtg_dc_meas(mtg_t* mtg,int dc)
{
    int i,n;
    double dcm;
    double dcm1;
    double detc;
    int step;
    ///dc:0前端水平，1处理前端垂直，2处理中水平，3处理中垂直，4处理尾水平，5处理尾垂直
    if(dc==0) dcm=mtg->m.hdev1;
    else if(dc==1) dcm=mtg->m.vdev1;
    else if(dc==2) dcm=mtg->m.hdev2;
    else if(dc==3) dcm=mtg->m.vdev2;
    else if(dc==4) dcm=mtg->m.hdev3;
    else if(dc==5) dcm=mtg->m.vdev3;

    ///mtg->dcm[dc]存储上次测量值
    ///mtg->dci[dc]存储上次姿态跳动持续次数
    ///dcm1本次姿态跳动数据
    if(mtg->dcm[dc]<100.0) dcm1=dcm-mtg->dcm[dc];
    else dcm1=0.0;
    detc=fabs(mtg->m.headc-mtg->m1.headc);

    if(detc>=0.07) dcm1=0.0;///里程差超过7cm，不做数据处理
    ///第一次测量，dcm1=0.0
    step=mtg->dci[dc];

    if(step==0)
    {
        if(dcm1>0.003)
        {
            ///姿态跳动大于4mm
            if(dcm1>=0.005)
            {
                mtg->dci[dc]=1;
            }
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else if(dcm1<-0.003)
        {
            ///姿态跳动大于4mm
            if(dcm1<=-0.005)
            {
                mtg->dci[dc]=-1;
            }
            dcm=mtg->dcm[dc];///取用上次的值
        }
    }
    else if(step==1)
    {
        if(dcm1>0.003)
        {
            ///姿态跳动大于4mm
            if(dcm1>=0.005)
            {
                mtg->dci[dc]=2;
            }
            else
            {
                mtg->dci[dc]=0;
            }
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else if(dcm1<-0.003)
        {
            mtg->dci[dc]=0;
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else
        {
            ///处理步骤归0
            mtg->dci[dc]=0;
        }
    }
    else if(step==2)
    {
        if(dcm1>0.003)
        {
            ///姿态跳动大于4mm
            if(dcm1>=0.005)
            {
                dcm=mtg->dcm[dc]+dcm1/4.0;
            }
            else
            {
                mtg->dci[dc]=0;
                dcm=mtg->dcm[dc];
            }
        }
        else if(dcm1<-0.003)
        {
            mtg->dci[dc]=0;
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else
        {
            ///处理步骤归0
            mtg->dci[dc]=0;
        }
    }
    else if(step==-1)
    {
        if(dcm1<-0.003)
        {
            if(dcm1<=-0.005)
            {
                mtg->dci[dc]=-2;
            }
            else
            {
                mtg->dci[dc]=0;
            }
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else if(dcm1>0.003)
        {
            mtg->dci[dc]=0;
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else
        {
            mtg->dci[dc]=0;
        }
    }
    else if(step==-2)
    {
        if(dcm1<-0.003)
        {
            if(dcm1<=-0.005)
            {
                dcm=mtg->dcm[dc]+dcm1/4.0;
            }
            else
            {
                mtg->dci[dc]=0;
                dcm=mtg->dcm[dc];
            }
        }
        else if(dcm1>0.003)
        {
            mtg->dci[dc]=0;
            dcm=mtg->dcm[dc];///取用上次的值
        }
        else
        {
            ///处理步骤归0
            mtg->dci[dc]=0;
        }
    }

    mtg->dcm[dc]=dcm;
    if(dc==0) mtg->m.hdev1=dcm;
    else if(dc==1) mtg->m.vdev1=dcm;
    else if(dc==2) mtg->m.hdev2=dcm;
    else if(dc==3) mtg->m.vdev2=dcm;
    else if(dc==4) mtg->m.hdev3=dcm;
    else if(dc==5) mtg->m.vdev3=dcm;
    return 0;
}

extern int mtg_lasertarget_cal(mtg_t* mtg)
{
    double pitch,roll;
    transform3d_t trans;
    point3d_t pt1,pt2;
    double len;
    double ori;
    double inc[2];
    point2d_t u1,u2;
    affine_t aff;
    MTG_MEASURE* m=0;
    int i=0;
    FILE* fp=fopen("D://mtg_lasertarger.log","w");

    len=mtg->tarset.length;

    m=&mtg->m;

    affine_init(&aff,mtg->camset[0].affine);
    pt1.x=pt1.y=pt1.z=0.0;
    if(fp)
    {
        fprintf(fp,"mtg_laser_incline:a1=%.12f,a2=%.12f,a3=%.12f\n",aff.a1,aff.a2,aff.a3);
        fprintf(fp,"mtg_laser_incline:b1=%.12f,b2=%.12f,b3=%.12f\n",aff.b1,aff.b2,aff.b3);
        fprintf(fp,"mtg_laser_incline:c1=%.12f,c2=%.12f,c3=%.12f\n",aff.c1,aff.c2,aff.c3);
    }
    for(i=0;i<4;i++)
    {
        if(i==0)
        {
            m->inc[0]=0.259;
            m->inc[1]=-0.327;
            m->angle[0]=3.4497/180.0*PI;
            m->angle[1]=94.8548/180.0*PI;
            m->cam[0]=1113.6915;
            m->cam[1]=897.3085;
        }
        else if(i==1)
        {
            m->inc[0]=0.2625;
            m->inc[1]=-0.327;
            m->angle[0]=6.7494/180.0*PI;
            m->angle[1]=94.848/180.0*PI;
            m->cam[0]=1326.975;
            m->cam[1]=892.6167;
        }
        else if(i==2)
        {
            m->inc[0]=0.261;
            m->inc[1]=-0.327;
            m->angle[0]=356.8903/180.0*PI;
            m->angle[1]=94.8599/180.0*PI;
            m->cam[0]=719.8776;
            m->cam[1]=901.7245;
        }
        else if(i==3)
        {
            m->inc[0]=0.263;
            m->inc[1]=-0.327;
            m->angle[0]=353.2122/180.0*PI;
            m->angle[1]=94.8414/180.0*PI;
            m->cam[0]=518.1471;
            m->cam[1]=904.9706;
        }

        inc[0]=m->inc[0]*PI/180.0;
        inc[1]=m->inc[1]*PI/180.0;
        ///俯仰
        roll=inc[0];
        ///侧转
        pitch=inc[1];
        ///修正滚动角
        roll=atan(tan(roll)/cos(pitch));
        ///注意角度正负号
        transform3d_init(&trans,roll,pitch,0,0,0,0,1);

        ///后屏

        u1.x=m->cam[0];
        u1.y=mtg->camset[0].h-m->cam[1];
        if(fp)
        fprintf(fp,"mtg_laser_incline:u1x=%.12f,u1y=%.12f\n",u1.x,u1.y);
        affine_trans(&aff,&u1,&u2);
        if(fp)
        fprintf(fp,"mtg_laser_incline:u2x=%.12f,u2y=%.12f\n",u2.x,u2.y);
        pt2.x=len;
        pt2.y=u2.x;
        pt2.z=u2.y;
        pitch=asin(pt2.z/len);

        ///20181115whq移至此处为了判断倾斜仪是否超限
        pitch=atan(tan(pitch)/cos(inc[0]));
        pitch=PI/2.0-m->angle[1]-pitch;
        m->inc[3]=pitch*180.0/PI;
        ///

        transform3d_trans(&trans,&pt2,&pt2);
        if(fp)
        fprintf(fp,"pt2:%f,%f,%f\n",pt2.x,pt2.y,pt2.z);
        ///激光耙方位角
        ori=atan2(pt2.y-pt1.y,pt2.x-pt1.x);
        if(fp)
        {
            fprintf(fp,"len:%.4f,ori:%.6f\n",len,ori*180.0/PI);fflush(fp);
        }
        ori=m->angle[0]-ori;
        if(ori<0) ori+=2*PI;
        if(fp)
        fprintf(fp,"mtg_laser_incline:camx=%.4f,camy=%.4f,roll=%.12f,phi=%.12f,ori=%.12f\n",m->cam[0],m->cam[1],m->inc[0],m->inc[1],ori);
        m->inc[2]=ori*180.0/PI;
        if(fp)
        {
            fprintf(fp,"i=%d,h=%d,ori=%.6f\n",i,mtg->camset[0].h,m->inc[2]);fflush(fp);
        }
    }
    if(fp)
    {
        fclose(fp);
    }
    //trace(0,"mtg_laser_incline:%f,%f,%f,%f\n",m->inc[0],m->inc[1],m->inc[2],m->inc[3]);
    return 0;
}

extern int mtg_laser_to_aj(mtg_t* mtg)
{
    mtg->maj.inc[0]=mtg->m1.inc[0];
    mtg->maj.inc[1]=mtg->m1.inc[1];
    mtg->maj.inc[2]=mtg->m1.inc[2];
    mtg->maj.inc[3]=mtg->m1.inc[3];
    mtg->maj.cam[0]=mtg->m1.cam[0];
    mtg->maj.cam[1]=mtg->m1.cam[1];
    mtg->maj.cam[2]=mtg->m1.cam[2];
    mtg->maj.cam[3]=mtg->m1.cam[3];
    mtg->maj.prism[0]=mtg->m1.prism[0];
    mtg->maj.prism[1]=mtg->m1.prism[1];
    mtg->maj.prism[2]=mtg->m1.prism[2];
    mtg->maj.angle[0]=mtg->m1.angle[0];
    mtg->maj.angle[1]=mtg->m1.angle[1];
    mtg->maj.comp[0]=mtg->m1.comp[0];
    mtg->maj.comp[1]=mtg->m1.comp[1];
    mtg->maj.head[0]=mtg->m1.head[0];
    mtg->maj.head[1]=mtg->m1.head[1];
    mtg->maj.head[2]=mtg->m1.head[2];
    mtg->maj.hdes[0]=mtg->m1.hdes[0];
    mtg->maj.hdes[1]=mtg->m1.hdes[1];
    mtg->maj.hdes[2]=mtg->m1.hdes[2];
    mtg->maj.headc=mtg->m1.headc;
    mtg->maj.headh=mtg->m1.headh;
    mtg->maj.headv=mtg->m1.headv;
    mtg->maj.tail[0]=mtg->m1.tail[0];
    mtg->maj.tail[1]=mtg->m1.tail[1];
    mtg->maj.tail[2]=mtg->m1.tail[2];
    mtg->maj.tdes[0]=mtg->m1.tdes[0];
    mtg->maj.tdes[1]=mtg->m1.tdes[1];
    mtg->maj.tdes[2]=mtg->m1.tdes[2];
    mtg->maj.tailc=mtg->m1.tailc;
    mtg->maj.tailh=mtg->m1.tailh;
    mtg->maj.tailv=mtg->m1.tailv;
    mtg->maj.mile1=mtg->m1.mile1;
    mtg->maj.hdev1=mtg->m1.hdev1;
    mtg->maj.vdev1=mtg->m1.vdev1;
    mtg->maj.mile2=mtg->m1.mile2;
    mtg->maj.hdev2=mtg->m1.hdev2;
    mtg->maj.vdev2=mtg->m1.vdev2;
    mtg->maj.mile3=mtg->m1.mile3;
    mtg->maj.hdev3=mtg->m1.hdev3;
    mtg->maj.vdev3=mtg->m1.vdev3;
    mtg->maj.faj[0]=mtg->m1.faj[0];
    mtg->maj.faj[1]=mtg->m1.faj[1];
    mtg->maj.faj[2]=mtg->m1.faj[2];
    mtg->maj.faj[3]=mtg->m1.faj[3];
    mtg->maj.baj[0]=mtg->m1.baj[0];
    mtg->maj.baj[1]=mtg->m1.baj[1];
    mtg->maj.baj[2]=mtg->m1.baj[2];
    mtg->maj.baj[3]=mtg->m1.baj[3];
    mtg->maj.aj[0]=mtg->m1.aj[0];
    mtg->maj.aj[1]=mtg->m1.aj[1];
    mtg->maj.aj[2]=mtg->m1.aj[2];
    mtg->maj.aj[3]=mtg->m1.aj[3];
    mtg->maj.inc1[0]=mtg->m1.inc1[0];
    mtg->maj.inc1[1]=mtg->m1.inc1[1];
    mtg->maj.inc1[2]=mtg->m1.inc1[2];
    mtg->maj.iseg=mtg->m1.iseg;
    mtg->maj.t1=mtg->m1.t1;
    mtg->maj.t2=mtg->m1.t2;
    mtg->maj.t3=mtg->m1.t3;
    mtg->maj.iset=mtg->m1.iset;
//    mtg->maj.daj[0]=mtg->m1.daj[0];
//    mtg->maj.daj[1]=mtg->m1.daj[1];
//    mtg->maj.daj[2]=mtg->m1.daj[2];
//    mtg->maj.daj[3]=mtg->m1.daj[3];
//    mtg->maj.iaj[0]=mtg->m1.iaj[0];
//    mtg->maj.iaj[1]=mtg->m1.iaj[1];
//    mtg->maj.iaj[2]=mtg->m1.iaj[2];
//    mtg->maj.iaj[3]=mtg->m1.iaj[3];
//    mtg->maj.t4=mtg->m1.t4;
}

///20220507whq change the mtg_aj_tbm,which is different from shield
extern int mtg_aj_tbm(mtg_t* mtg)
{
    MTG_TBM tbm={0};
    double xi[6]={0};
    double yi[6]={0};
    double zi[6]={0};
    double stdj[6]={0};       ///姿态测量完成后保存的油缸行程
    double meaj[6]={0};       ///推进过程中保存的油缸行程
    plane_t* p=NULL;
    point3d_t pts[6]={0};
    double hz,vz;
    double ohead[3]={0};
    double otail[3]={0};
    double oroll;
    double mhead[3]={0};
    double mtail[3]={0};
    double head[3]={0};
    double tail[3]={0};
    double inc[2]={0};      ///0转动角，1俯仰角
    double roll,pitch,ori;
    double inc0[2]={0};      ///0转动角，1俯仰角
    double roll0,pitch0,ori0;
    double dx,dy,dz,di,d1;
    int i,n;
    double r1;
    double ax,by,cz,dd;
    double ox,oy,oz;
    double Lab;            ///油缸底座位置到前端的长度
    double len;             ///切口到盾尾的距离
    MTG_MEASURE_AJ* m=NULL;
    double tm=0.0;
    time_t t;
    char timestr[256];
    double sumaj0=0.0,sumaj=0.0;
    double averaj0=0.0,averaj=0.0;
    double scale=0.0;

    FILE* fp=fopen("D:\\mtg_aj_tbm.log","w");
    n=0;
    if(fp)
    {
        time(&t);
        strftime(timestr,64,"%Y-%m-%d %H:%M:%S",localtime(&t));
        fprintf(fp,"%s\n",timestr);
        fflush(fp);
    }

    m=&mtg->maj;
    ///首先判断油缸数据获取成功的个数
    ///要求油缸数据的顺序分别是上下左右对应daj[0-3]
    for(i=0;i<mtg->tbm.naj;i++)
    {
        stdj[i]=mtg->maj0.daj[i];
        meaj[i]=mtg->maj.daj[i];
        tbm.aj[i]=mtg->tbm.aj[i];
        if(fp)
        {
            fprintf(fp,"i:%d,stdj[%d]:%.4f,meaj[%d]:%.4f,tbmaj[%d]:%.4f\n",
                    i,i,stdj[i],i,meaj[i],i,tbm.aj[i]);
            fflush(fp);
        }
        if(mtg->maj.iaj[i]==1)
        {
            sumaj0+=mtg->maj0.daj[i];
            sumaj+=mtg->maj.daj[i];
            n++;
        }
    }

    //n=tbm.naj;
    ///油缸数据小于等于三个停止计算
    if(n<=3)
    {
        if(fp)
        {
            fprintf(fp,"n:%d\n",n);
            fclose(fp);
        }
        return -1;
    }
    averaj0=sumaj0/n;
    averaj=sumaj/n;
    inc0[0]=mtg->maj0.inc[0]*PI/180.0;
    inc0[1]=mtg->maj0.inc[1]*PI/180.0;
    ///俯仰
    roll0=inc0[0];
    ///侧转
    pitch0=inc0[1];
    ///修正滚动角
    roll0=atan(tan(roll0)/cos(pitch0));

    oroll=mtg->maj0.inc1[0]*PI/180.0;
    ohead[0]=mtg->maj0.head[0];
    ohead[1]=mtg->maj0.head[1];
    ohead[2]=mtg->maj0.head[2];
    otail[0]=mtg->maj0.tail[0];
    otail[1]=mtg->maj0.tail[1];
    otail[2]=mtg->maj0.tail[2];
    if(mtg->tbm.type==2 ||mtg->tbm.type==3)
        Lab=mtg->tbm.L[3]-mtg->tbm.L[0];
    else
        Lab=mtg->tbm.L[3];
    len=sqrt((ohead[0]-otail[0])*(ohead[0]-otail[0])+(ohead[1]-otail[1])*(ohead[1]-otail[1])+(ohead[2]-otail[2])*(ohead[2]-otail[2]));
    r1=mtg->tbm.D[0]/2.0;

    inc[0]=mtg->maj.inc[0];
    inc[1]=mtg->maj.inc[1];

    if(fp)
    {
        fprintf(fp,"oroll:%.4f\n",oroll);
        fprintf(fp,"ohead[0]:%.4f,%.4f,%.4f\n",ohead[0],ohead[1],ohead[2]);
        fprintf(fp,"otail[0]:%.4f,%.4f,%.4f\n",otail[0],otail[1],otail[2]);
        fprintf(fp,"lab:%.4f,inc[0]:%.4f,inc[1]:%.4f\n",Lab,inc[0],inc[1]);
        fflush(fp);
    }

    for(i=0;i<n;i++)
    {
        yi[i]=r1*cos(tbm.aj[i]+oroll);
        zi[i]=-r1*sin(tbm.aj[i]+oroll);
        xi[i]=stdj[i];
        pts[i].y=yi[i];
        pts[i].z=zi[i];
        pts[i].x=xi[i];
        if(fp)
        {
            fprintf(fp,"i:%d,pts:%.4f,%.4f,%.4f\n",i,pts[i].x,pts[i].y,pts[i].z);fflush(fp);
        }
    }

//    p=plane_create();
//    if(fp)
//    {
//        fprintf(fp,"plane_create\n");fflush(fp);
//    }
//    if(!plane_init_points(p,n,pts))
//    {
//        free(p);
//        if(fp)
//        {
//            fprintf(fp,"plane_init_points failed\n");fclose(fp);
//        }
//        return -1;
//    }
//
//    dx=-p->a;
//    dy=-p->b;
//    dz=-p->c;
//    if(fp)
//    {
//        fprintf(fp,"vector0:%.4f,%.4f,%.4f\n",dx,dy,dz);
//        fflush(fp);
//    }
//    di=sqrt(dx*dx+dy*dy);
//    //hz=atan2(dy,dx);
//    hz=atan(dy);
//    vz=atan(dz/di);


    if(fp)
    {
        fprintf(fp,"origin:hz:%.4f,vz:%.4f\n",hz,vz);
        fflush(fp);
    }

    dx=ohead[0]-otail[0];
    dy=ohead[1]-otail[1];
    dz=ohead[2]-otail[2];
    di=sqrt(dx*dx+dy*dy);
    ori=atan2(dy,dx);
    if(ori<0.0) ori+=2.0*PI;
    pitch=atan(dz/di);

    //hz=ori-hz;
    hz=ori+hz;
    if(hz<0.0) hz+=2.0*PI;
    vz=pitch+vz;
    dd=fabs(p->d);

    ori+=PI;
    pitch=-pitch;
    ox=ohead[0]+(Lab+dd)*cos(pitch)*cos(ori);
    oy=ohead[1]+(Lab+dd)*cos(pitch)*sin(ori);
    oz=ohead[2]+(Lab+dd)*sin(pitch);
    if(fp)
    {
        fprintf(fp,"origindd:%.4f,ori:%.4f,pitch:%.4f\n",dd,ori-PI,-pitch);
        fprintf(fp,"oxyz:%.4f,%.4f,%.4f\n",ox,oy,oz);
        fflush(fp);
    }

    inc[0]=inc[0]*PI/180.0;
    inc[1]=inc[1]*PI/180.0;

    roll=inc[0];
    pitch=inc[1];
    roll=atan(tan(roll)/cos(pitch));

    ///20200320 whq add
    roll=(roll-roll0)+oroll;
    if(fp)
    {
        fprintf(fp,"roll:%.4f\n",roll);
        fprintf(fp,"inc[0]:%.4f,inc[1]:%.4f\n",inc[0],inc[1]);
        fflush(fp);
    }

    for(i=0;i<n;i++)
    {
        yi[i]=r1*cos(tbm.aj[i]+roll);
        zi[i]=-r1*sin(tbm.aj[i]+roll);
        xi[i]=meaj[i];
        pts[i].y=yi[i];
        pts[i].z=zi[i];
        pts[i].x=xi[i];
    }

    p=plane_create();
    if(!plane_init_points(p,n,pts))
    {
        free(p);
        return -1;
    }

    ori=hz;
    pitch=vz;

    dx=-p->a;
    dy=-p->b;
    dz=-p->c;
    if(fp)
    {
        fprintf(fp,"vector:%.4f,%.4f,%.4f\n",dx,dy,dz);
        fprintf(fp,"pd:%.4f,hz:%.4f,vz:%.4f\n",p->d,hz,vz);
        fflush(fp);
    }
    di=sqrt(dx*dx+dy*dy);
    //hz=atan2(dy,dx);
    hz=atan(dy);
    vz=atan(dz/di);

    ori=ori-hz;
    pitch=pitch-vz;
    if(fp)
    {
        fprintf(fp,"hz:%.4f,vz:%.4f\n",hz,vz);
        fprintf(fp,"ori:%.4f,pitch:%.4f\n",ori,pitch);
        fflush(fp);
    }
    ///202004020830whq add
    ///20200402whq delete
//    scale=(averaj-averaj0)/mtg->segset.L;
//    if(fp)
//    {
//        fprintf(fp,"scale:%.4f\n",scale);fflush(fp);
//    }
//    if(scale<0)
//        scale=0;
//
//    ori=ori+mtg->maj0.azidiff*scale;
//    pitch=pitch+mtg->maj0.pitchdiff*scale;
//    if(fp)
//    {
//        fprintf(fp,"after correction ori:%.4f,pitch:%.4f\n",ori,pitch);fflush(fp);
//    }

    head[0]=ox+(Lab+fabs(p->d))*cos(pitch)*cos(ori);
    head[1]=oy+(Lab+fabs(p->d))*cos(pitch)*sin(ori);
    head[2]=oz+(Lab+fabs(p->d))*sin(pitch);

    ori=ori+PI;
    pitch=-pitch;

    tail[0]=head[0]+len*cos(pitch)*cos(ori);
    tail[1]=head[1]+len*cos(pitch)*sin(ori);
    tail[2]=head[2]+len*sin(pitch);

    m->head[0]=head[0];
    m->head[1]=head[1];
    m->head[2]=head[2];
    m->tail[0]=tail[0];
    m->tail[1]=tail[1];
    m->tail[2]=tail[2];

    m->inc1[0]=roll;
    d1=sqrt((head[0]-tail[0])*(head[0]-tail[0])+(head[1]-tail[1])*(head[1]-tail[1]));
    m->inc1[1]=atan((head[2]-tail[2])/d1);
    m->inc1[2]=atan2(head[1]-tail[1],head[0]-tail[0]);
    if(m->inc1[2]<0)
        m->inc1[2]+=2*PI;

    m->inc1[0]=m->inc1[0]*180.0/PI;
    m->inc1[1]=m->inc1[1]*180.0/PI;
    m->inc1[2]=m->inc1[2]*180.0/PI;

    ///偏差计算
    road_xy2l(&mtg->r,m->head[0],m->head[1],&m->headc,&m->hdes[0],&m->hdes[1],0,&m->headh);
    road_l2h(&mtg->r,m->headc,&m->hdes[2],0);
    m->headv=m->head[2]-m->hdes[2];
    road_xy2l(&mtg->r,m->tail[0],m->tail[1],&m->tailc,&m->tdes[0],&m->tdes[1],0,&m->tailh);
    road_l2h(&mtg->r,m->tailc,&m->tdes[2],0);
    m->tailv=m->tail[2]-m->tdes[2];
    m->headh*=mtg->prj.a2z;
    m->tailh*=mtg->prj.a2z;

    ///20180112whq修改，mtg->iset.rget为0表示根据PLC近似计算，1表示根据里程近似计算，2暂时不考虑，以后会取消
    tm=fabs(m->headc-mtg->snum.mile);
    m->iseg=mtg->snum.iseg+tm/mtg->segset.L;
    time(&mtg->maj.t4);

    if(fp)
    {
        fprintf(fp,"t_laser:%ld,t_aj:%ld\n",mtg->m1.t3,(long)mtg->maj.t4);
        fprintf(fp,"head_laser:xyz %.4f,%.4f,%.4f\n",mtg->m1.head[0],mtg->m1.head[1],mtg->m1.head[2]);
        fprintf(fp,"head_aj   :xyz %.4f,%.4f,%.4f\n",mtg->maj.head[0],mtg->maj.head[1],mtg->maj.head[2]);
        fprintf(fp,"head_laser:off %.4f,%.4f,%.4f\n",mtg->m1.headh,mtg->m1.headv);
        fprintf(fp,"head_aj   :off %.4f,%.4f,%.4f\n",mtg->maj.headh,mtg->maj.headv);

        fprintf(fp,"tail_laser:xyz %.4f,%.4f,%.4f\n",mtg->m1.tail[0],mtg->m1.tail[1],mtg->m1.tail[2]);
        fprintf(fp,"tail_aj   :xyz %.4f,%.4f,%.4f\n",mtg->maj.tail[0],mtg->maj.tail[1],mtg->maj.tail[2]);
        fprintf(fp,"tail_laser:off %.4f,%.4f,%.4f\n",mtg->m1.tailh,mtg->m1.tailv);
        fprintf(fp,"tail_aj   :off %.4f,%.4f,%.4f\n",mtg->maj.tailh,mtg->maj.tailv);
        fprintf(fp,"inc10-2   :    %.4f,%.4f,%.4f\n",mtg->maj.inc1[0],mtg->maj.inc1[1],mtg->maj.inc1[2]);
        fprintf(fp,"m->iseg:       %d\n",m->iseg);
        fclose(fp);
    }

    return 0;
}

extern int mtg_aj_tbm_nocorrection(mtg_t* mtg)
{
    MTG_TBM tbm={0};
    double xi[6]={0};
    double yi[6]={0};
    double zi[6]={0};
    double stdj[6]={0};       ///姿态测量完成后保存的油缸行程
    double meaj[6]={0};       ///推进过程中保存的油缸行程
    plane_t* p;
    point3d_t pts[6]={0};
    double hz,vz;
    double ohead[3]={0};
    double otail[3]={0};
    double oroll;
    double mhead[3]={0};
    double mtail[3]={0};
    double head[3]={0};
    double tail[3]={0};
    double inc[2]={0};      ///0转动角，1俯仰角
    double roll,pitch,ori;
    double inc0[2]={0};      ///0转动角，1俯仰角
    double roll0,pitch0,ori0;
    double dx,dy,dz,di,d1;
    int i,n;
    double r1;
    double ax,by,cz,dd;
    double ox,oy,oz;
    double Lab;            ///油缸底座位置到前端的长度
    double len;             ///切口到盾尾的距离
    MTG_MEASURE_AJ* m=&mtg->maj;
    double tm=0.0;
    time_t t;
    char timestr[260];

    FILE* fp=fopen("D:\\mtg_aj_tbm_nocorrection.log","w");
    n=0;
    if(fp)
    {
        time(&t);
        strftime(timestr,64,"%Y-%m-%d %H:%M:%S",localtime(&t));
        fprintf(fp,"%s\n",timestr);
        fflush(fp);
    }
    ///首先判断油缸数据获取成功的个数
    for(i=0;i<mtg->tbm.naj;i++)
    {
        stdj[i]=mtg->maj01.daj[i];
        meaj[i]=mtg->maj.daj[i];
        tbm.aj[i]=mtg->tbm.aj[i];
        if(fp)
        {
            fprintf(fp,"i:%d,stdj[%d]:%.4f,meaj[%d]:%.4f,tbmaj[%d]:%.4f\n",
                    i,i,stdj[i],i,meaj[i],i,tbm.aj[i]);
            fflush(fp);
        }
        if(mtg->maj.iaj[i]==1)
        {
            n++;
        }
    }
    //n=tbm.naj;
    ///油缸数据小于三个停止计算
    if(n<3)
    {
        fprintf(fp,"n:%d\n",n);
        fclose(fp);
        return -1;
    }

    inc0[0]=mtg->maj01.inc[0]*PI/180.0;
    inc0[1]=mtg->maj01.inc[1]*PI/180.0;
    ///俯仰
    roll0=inc0[0];
    ///侧转
    pitch0=inc0[1];
    ///修正滚动角
    roll0=atan(tan(roll0)/cos(pitch0));

    oroll=mtg->maj01.inc1[0]*PI/180.0;
    ohead[0]=mtg->maj01.head[0];
    ohead[1]=mtg->maj01.head[1];
    ohead[2]=mtg->maj01.head[2];
    otail[0]=mtg->maj01.tail[0];
    otail[1]=mtg->maj01.tail[1];
    otail[2]=mtg->maj01.tail[2];
    if(mtg->tbm.type==2 ||mtg->tbm.type==3)
        Lab=mtg->tbm.L[3]-mtg->tbm.L[0];
    else
        Lab=mtg->tbm.L[3];
    len=sqrt((ohead[0]-otail[0])*(ohead[0]-otail[0])+(ohead[1]-otail[1])*(ohead[1]-otail[1])+(ohead[2]-otail[2])*(ohead[2]-otail[2]));
    r1=mtg->tbm.D[0]/2.0;

    inc[0]=mtg->maj.inc[0];
    inc[1]=mtg->maj.inc[1];

    if(fp)
    {
        fprintf(fp,"oroll:%.4f\n",oroll);
        fprintf(fp,"ohead[0]:%.4f,%.4f,%.4f\n",ohead[0],ohead[1],ohead[2]);
        fprintf(fp,"otail[0]:%.4f,%.4f,%.4f\n",otail[0],otail[1],otail[2]);
        fprintf(fp,"lab:%.4f,inc[0]:%.4f,inc[1]:%.4f\n",Lab,inc[0],inc[1]);
        fflush(fp);
    }

    for(i=0;i<n;i++)
    {
        yi[i]=r1*cos(tbm.aj[i]+oroll);
        zi[i]=-r1*sin(tbm.aj[i]+oroll);
        xi[i]=stdj[i];
        pts[i].y=yi[i];
        pts[i].z=zi[i];
        pts[i].x=xi[i];
        if(fp)
        {
            fprintf(fp,"i:%d,pts:%.4f,%.4f,%.4f\n",i,pts[i].x,pts[i].y,pts[i].z);fflush(fp);
        }
    }

    p=plane_create();
    if(fp)
    {
        fprintf(fp,"plane_create\n");fflush(fp);
    }
    if(!plane_init_points(p,n,pts))
    {
        free(p);
        if(fp)
        {
            fprintf(fp,"plane_init_points failed\n");fclose(fp);
        }
        return -1;
    }

    dx=-p->a;
    dy=-p->b;
    dz=-p->c;
    if(fp)
    {
        fprintf(fp,"vector0:%.4f,%.4f,%.4f\n",dx,dy,dz);
        fflush(fp);
    }
    di=sqrt(dx*dx+dy*dy);
    //hz=atan2(dy,dx);
    hz=atan(dy);
    vz=atan(dz/di);
    if(fp)
    {
        fprintf(fp,"origin:hz:%.4f,vz:%.4f\n",hz,vz);
        fflush(fp);
    }

    dx=ohead[0]-otail[0];
    dy=ohead[1]-otail[1];
    dz=ohead[2]-otail[2];
    di=sqrt(dx*dx+dy*dy);
    ori=atan2(dy,dx);
    if(ori<0.0) ori+=2.0*PI;
    pitch=atan(dz/di);

    //hz=ori-hz;
    hz=ori+hz;
    if(hz<0.0) hz+=2.0*PI;
    vz=pitch+vz;
//    dd=p->d;
    dd=fabs(p->d);

    ori+=PI;
    pitch=-pitch;
    ox=ohead[0]+(Lab+dd)*cos(pitch)*cos(ori);
    oy=ohead[1]+(Lab+dd)*cos(pitch)*sin(ori);
    oz=ohead[2]+(Lab+dd)*sin(pitch);
    if(fp)
    {
        fprintf(fp,"origindd:%.4f,ori:%.4f,pitch:%.4f\n",dd,ori-PI,-pitch);
        fprintf(fp,"oxyz:%.4f,%.4f,%.4f\n",ox,oy,oz);
        fflush(fp);
    }

    inc[0]=inc[0]*PI/180.0;
    inc[1]=inc[1]*PI/180.0;

    roll=inc[0];
    pitch=inc[1];
    roll=atan(tan(roll)/cos(pitch));

    ///20200320 whq add
    roll=(roll-roll0)+oroll;
    if(fp)
    {
        fprintf(fp,"roll:%.4f\n",roll);
        fprintf(fp,"inc[0]:%.4f,inc[1]:%.4f\n",inc[0],inc[1]);
        fflush(fp);
    }

    for(i=0;i<n;i++)
    {
        yi[i]=r1*cos(tbm.aj[i]+roll);
        zi[i]=-r1*sin(tbm.aj[i]+roll);
        xi[i]=meaj[i];
        pts[i].y=yi[i];
        pts[i].z=zi[i];
        pts[i].x=xi[i];
    }

    p=plane_create();
    if(!plane_init_points(p,n,pts))
    {
        free(p);
        return -1;
    }

    ori=hz;
    pitch=vz;

    dx=-p->a;
    dy=-p->b;
    dz=-p->c;
    if(fp)
    {
        fprintf(fp,"vector:%.4f,%.4f,%.4f\n",dx,dy,dz);
        fprintf(fp,"pd:%.4f,hz:%.4f,vz:%.4f\n",p->d,hz,vz);
        fflush(fp);
    }
    di=sqrt(dx*dx+dy*dy);
    //hz=atan2(dy,dx);
    hz=atan(dy);
    vz=atan(dz/di);

    //ori=ori+hz;
    ori=ori-hz;
    pitch=pitch-vz;
    if(fp)
    {
        fprintf(fp,"hz:%.4f,vz:%.4f\n",hz,vz);
        fprintf(fp,"ori:%.4f,pitch:%.4f\n",ori,pitch);
        fflush(fp);
    }

    //ori=ori+mtg->maj0.azidiff;
    //pitch=pitch+mtg->maj0.pitchdiff;

    head[0]=ox+(Lab+fabs(p->d))*cos(pitch)*cos(ori);
    head[1]=oy+(Lab+fabs(p->d))*cos(pitch)*sin(ori);
    head[2]=oz+(Lab+fabs(p->d))*sin(pitch);

    ori=ori+PI;
    pitch=-pitch;

    tail[0]=head[0]+len*cos(pitch)*cos(ori);
    tail[1]=head[1]+len*cos(pitch)*sin(ori);
    tail[2]=head[2]+len*sin(pitch);

    m->head[0]=head[0];
    m->head[1]=head[1];
    m->head[2]=head[2];
    m->tail[0]=tail[0];
    m->tail[1]=tail[1];
    m->tail[2]=tail[2];

    m->inc1[0]=roll;
    d1=sqrt((head[0]-tail[0])*(head[0]-tail[0])+(head[1]-tail[1])*(head[1]-tail[1]));
    m->inc1[1]=atan((head[2]-tail[2])/d1);
    m->inc1[2]=atan2(head[1]-tail[1],head[0]-tail[0]);
    if(m->inc1[2]<0)
        m->inc1[2]+=2*PI;

    m->inc1[0]=m->inc1[0]*180.0/PI;
    m->inc1[1]=m->inc1[1]*180.0/PI;
    m->inc1[2]=m->inc1[2]*180.0/PI;

    ///偏差计算
    road_xy2l(&mtg->r,m->head[0],m->head[1],&m->headc,&m->hdes[0],&m->hdes[1],0,&m->headh);
    road_l2h(&mtg->r,m->headc,&m->hdes[2],0);
    m->headv=m->head[2]-m->hdes[2];
    road_xy2l(&mtg->r,m->tail[0],m->tail[1],&m->tailc,&m->tdes[0],&m->tdes[1],0,&m->tailh);
    road_l2h(&mtg->r,m->tailc,&m->tdes[2],0);
    m->tailv=m->tail[2]-m->tdes[2];
    m->headh*=mtg->prj.a2z;
    m->tailh*=mtg->prj.a2z;

    ///20180112whq修改，mtg->iset.rget为0表示根据PLC近似计算，1表示根据里程近似计算，2暂时不考虑，以后会取消
    tm=fabs(m->headc-mtg->snum.mile);
    m->iseg=mtg->snum.iseg+tm/mtg->segset.L;
    time(&mtg->maj.t4);

    if(fp)
    {
        fprintf(fp,"t_laser:%ld,t_aj:%ld\n",mtg->m1.t3,(long)mtg->maj.t4);
        fprintf(fp,"head_laser:xyz %.4f,%.4f,%.4f\n",mtg->m1.head[0],mtg->m1.head[1],mtg->m1.head[2]);
        fprintf(fp,"head_aj   :xyz %.4f,%.4f,%.4f\n",mtg->maj.head[0],mtg->maj.head[1],mtg->maj.head[2]);
        fprintf(fp,"head_laser:off %.4f,%.4f,%.4f\n",mtg->m1.headh,mtg->m1.headv);
        fprintf(fp,"head_aj   :off %.4f,%.4f,%.4f\n",mtg->maj.headh,mtg->maj.headv);

        fprintf(fp,"tail_laser:xyz %.4f,%.4f,%.4f\n",mtg->m1.tail[0],mtg->m1.tail[1],mtg->m1.tail[2]);
        fprintf(fp,"tail_aj   :xyz %.4f,%.4f,%.4f\n",mtg->maj.tail[0],mtg->maj.tail[1],mtg->maj.tail[2]);
        fprintf(fp,"tail_laser:off %.4f,%.4f,%.4f\n",mtg->m1.tailh,mtg->m1.tailv);
        fprintf(fp,"tail_aj   :off %.4f,%.4f,%.4f\n",mtg->maj.tailh,mtg->maj.tailv);
        fprintf(fp,"inc10-2   :    %.4f,%.4f,%.4f\n",mtg->maj.inc1[0],mtg->maj.inc1[1],mtg->maj.inc1[2]);
        fprintf(fp,"m->iseg:       %d\n",m->iseg);
        fclose(fp);
    }

    return 0;
}

extern int mtg_aj_to_laser(mtg_t* mtg)
{
    mtg->m.inc[0]=mtg->maj.inc[0];
    mtg->m.inc[1]=mtg->maj.inc[1];
    //mtg->m.inc[2]=mtg->maj.inc[2];
    //mtg->m.inc[3]=mtg->maj.inc[3];
    //mtg->m.cam[0]=mtg->maj.cam[0];
    //mtg->m.cam[1]=mtg->maj.cam[1];
    //mtg->m.cam[2]=mtg->maj.cam[2];
    //mtg->m.cam[3]=mtg->maj.cam[3];
    //mtg->m.prism[0]=mtg->maj.prism[0];
    //mtg->m.prism[1]=mtg->maj.prism[1];
    //mtg->m.prism[2]=mtg->maj.prism[2];
    //mtg->m.angle[0]=mtg->maj.angle[0];
    //mtg->m.angle[1]=mtg->maj.angle[1];
    //mtg->m.comp[0]=mtg->maj.comp[0];
    //mtg->m.comp[1]=mtg->maj.comp[1];
    mtg->m.head[0]=mtg->maj.head[0];
    mtg->m.head[1]=mtg->maj.head[1];
    mtg->m.head[2]=mtg->maj.head[2];
    mtg->m.hdes[0]=mtg->maj.hdes[0];
    mtg->m.hdes[1]=mtg->maj.hdes[1];
    mtg->m.hdes[2]=mtg->maj.hdes[2];
    mtg->m.headc=mtg->maj.headc;
    mtg->m.headh=mtg->maj.headh;
    mtg->m.headv=mtg->maj.headv;
    mtg->m.tail[0]=mtg->maj.tail[0];
    mtg->m.tail[1]=mtg->maj.tail[1];
    mtg->m.tail[2]=mtg->maj.tail[2];
    mtg->m.tdes[0]=mtg->maj.tdes[0];
    mtg->m.tdes[1]=mtg->maj.tdes[1];
    mtg->m.tdes[2]=mtg->maj.tdes[2];
    mtg->m.tailc=mtg->maj.tailc;
    mtg->m.tailh=mtg->maj.tailh;
    mtg->m.tailv=mtg->maj.tailv;
//    mtg->m.mile1=mtg->maj.mile1;
//    mtg->m.hdev1=mtg->maj.hdev1;
//    mtg->m.vdev1=mtg->maj.vdev1;
//    mtg->m.mile2=mtg->maj.mile2;
//    mtg->m.hdev2=mtg->maj.hdev2;
//    mtg->m.vdev2=mtg->maj.vdev2;
//    mtg->m.mile3=mtg->maj.mile3;
//    mtg->m.hdev3=mtg->maj.hdev3;
//    mtg->m.vdev3=mtg->maj.vdev3;
//    mtg->m.faj[0]=mtg->maj.faj[0];
//    mtg->m.faj[1]=mtg->maj.faj[1];
//    mtg->m.faj[2]=mtg->maj.faj[2];
//    mtg->m.faj[3]=mtg->maj.faj[3];
//    mtg->m.baj[0]=mtg->maj.baj[0];
//    mtg->m.baj[1]=mtg->maj.baj[1];
//    mtg->m.baj[2]=mtg->maj.baj[2];
//    mtg->m.baj[3]=mtg->maj.baj[3];
//    mtg->m.aj[0]=mtg->maj.aj[0];
//    mtg->m.aj[1]=mtg->maj.aj[1];
//    mtg->m.aj[2]=mtg->maj.aj[2];
//    mtg->m.aj[3]=mtg->maj.aj[3];
    mtg->m.inc1[0]=mtg->maj.inc1[0];
    mtg->m.inc1[1]=mtg->maj.inc1[1];
    mtg->m.inc1[2]=mtg->maj.inc1[2];
    mtg->m.iseg=mtg->maj.iseg;
//    mtg->m.t1=mtg->maj.t1;
//    mtg->m.t2=mtg->maj.t2;
//    mtg->m.t3=mtg->maj.t3;
//    mtg->m.iset=mtg->maj.iset;
//    mtg->maj.daj[0]=mtg->m1.daj[0];
//    mtg->maj.daj[1]=mtg->m1.daj[1];
//    mtg->maj.daj[2]=mtg->m1.daj[2];
//    mtg->maj.daj[3]=mtg->m1.daj[3];
//    mtg->maj.iaj[0]=mtg->m1.iaj[0];
//    mtg->maj.iaj[1]=mtg->m1.iaj[1];
//    mtg->maj.iaj[2]=mtg->m1.iaj[2];
//    mtg->maj.iaj[3]=mtg->m1.iaj[3];
//    mtg->maj.t4=mtg->m1.t4;
}

int mtg_cal_aj_gesture(mtg_t* mtg)
{
    MTG_MEASURE* m=&mtg->m;
    ///用油缸计算出前端和后端中心坐标
    if(mtg_aj_tbm(mtg))
        return -1;

    mtg_aj_to_laser(mtg);
    ///前盾、尾盾计算（20160512）
    if(mtg->tbm.type>0)
    {
        mtg_cal_tbm(mtg);
    }
    else
    {
        m->mile1=m->headc;
        m->hdev1=m->headh;
        m->vdev1=m->headv;
        m->mile2=(m->headc+m->tailc)/2.0;
        m->hdev2=(m->headh+m->tailh)/2.0;
        m->vdev2=(m->headv+m->tailv)/2.0;
        m->mile3=m->tailc;
        m->hdev3=m->tailh;
        m->vdev3=m->tailv;
    }
    ///20180112whq修改，mtg->iset.rget为0表示根据PLC近似计算，1表示根据里程近似计算，2暂时不考虑，以后会取消
    if(mtg->itbm>1 && mtg->iset.rget==0)///20180112whq修改，将if(mtg->itbm>1)改成if(mtg->itbm>1&&mtg->iset.rget==0)，原因是原先的代码不支持环号的计算方式设置
    {
        m->iseg = mtg->snum.iseg;
        mtg->snum.tm=fabs(m->headc-mtg->snum.mile);
    }
    else
    {
        mtg->snum.tm=fabs(m->headc-mtg->snum.mile);
        m->iseg=mtg->snum.iseg+mtg->snum.tm/mtg->segset.L;
        ///20180112whq添加下面的代码
        if(mtg->snum.tm>=mtg->segset.L)
        {
            mtg->snum.iseg=m->iseg;
            mtg->snum.mile=mtg->snum.mile+(floor)(mtg->snum.tm/mtg->segset.L)*(mtg->segset.L)*mtg->prj.a2z;
            mtg_store_snum(mtg);
            //fprintf(fp,"store_snum:snum.mile:%.4f,snum.iseg:%d,tm:%.4f,L:%.4f\n",mtg->snum.mile,mtg->snum.iseg,mtg->snum.tm,mtg->segset.L);
        }
        ///20180112whq添加结束
    }
    return 0;
}

int mtg_cal_diff(mtg_t* mtg)
{
    double azidiff,pitchdiff;
    double minc1[3],majinc1[3];

    minc1[2]=mtg->m1.inc1[2]*PI/180;
    minc1[1]=mtg->m1.inc1[1]*PI/180;
    majinc1[2]=mtg->maj.inc1[2]*PI/180;
    majinc1[1]=mtg->maj.inc1[1]*PI/180;

    azidiff=minc1[2]-majinc1[2];
    pitchdiff=minc1[1]-majinc1[1];

    if(azidiff<-PI)
    {
        azidiff+=2*PI;
    }
    else if(azidiff>PI)
    {
        azidiff-=2*PI;
    }

    mtg->maj.azidiff=azidiff/2.0;
    mtg->maj.pitchdiff=pitchdiff/2.0;
    return 0;
}

