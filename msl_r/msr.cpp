#include <wx/wx.h>
#include "msr.h"
#include "msr_tApp.h"

#define PI  3.1415926535897932384626433832795

extern int msr_init(msr_t*  msr)
{
    road_init(&msr->r);
    ///工程参数
    strcpy(msr->prj.name,"123");
    msr->prj.mile1=0.0;
    msr->prj.mile2=0.0;
    msr->prj.a2z=1;
    msr->prj.dta=0;
    ///管环参数
    msr->segt.type=1;
    msr->segt.in=0;
    msr->segt.f2b=0;
    msr->segt.l2s=0.048;
    msr->segt.L=1.2;
    msr->segt.De=5.85;
    msr->segt.D=5.5;
    msr->segt.Ks=10;
    msr->segt.G1=0.015;
    msr->segt.G0=0.075;
    msr->segt.s2s=2;
    msr->kpos=(int*)malloc(msr->segt.Ks*sizeof(int));

    ///管块
    msr->nblk=6;
    msr->blocks=(BLOCK_T*)malloc(msr->nblk*sizeof(BLOCK_T));
    strcpy(msr->blocks[0].name,"K");
    msr->blocks[0].angle=0.375245789178781;
    strcpy(msr->blocks[1].name,"B2");
    msr->blocks[1].angle=1.18682389135614;
    strcpy(msr->blocks[2].name,"A3");
    msr->blocks[2].angle=1.17809724509617;
    strcpy(msr->blocks[3].name,"A2");
    msr->blocks[3].angle=1.17809724509617;
    strcpy(msr->blocks[4].name,"A1");
    msr->blocks[4].angle=1.17809724509617;
    strcpy(msr->blocks[5].name,"B1");
    msr->blocks[5].angle=1.18682389135614;
    ///TBM参数
    strcpy(msr->tbm.name,"123");
    msr->tbm.type=0;
    msr->tbm.mode=0;
    msr->tbm.D[0]=5.5;
    msr->tbm.D[1]=5.8;
    msr->tbm.D[2]=5.0;
    msr->tbm.D[3]=6.0;
    msr->tbm.D[4]=6.28;
    msr->tbm.D[5]=6.28;
    msr->tbm.L[0]=3.28;
    msr->tbm.L[1]=3.0;
    msr->tbm.L[2]=3.46;
    msr->tbm.L[3]=5.28;
    msr->tbm.L[4]=2.78;
    msr->tbm.L[5]=1.0;
    msr->tbm.L[6]=5.78;
    msr->tbm.L[7]=1.0;
    msr->tbm.L[8]=0.4;
    msr->tbm.naj=4;
    msr->tbm.aj[0]=4.71238898;
    msr->tbm.aj[1]=0.0;
    msr->tbm.aj[2]=1.570796327;
    msr->tbm.aj[3]=3.141592654;
    msr->tbm.aj[4]=0.0;
    msr->tbm.aj[5]=0.0;
    msr->tbm.aunit=1;
    msr->tbm.nbj=4;
    msr->tbm.bj[0]=4.71238898;
    msr->tbm.bj[1]=0.0;
    msr->tbm.bj[2]=1.570796327;
    msr->tbm.bj[3]=3.141592654;
    msr->tbm.bunit=1;
    msr->tbm.nfj=4;
    msr->tbm.fj[0]=4.71238898;
    msr->tbm.fj[1]=0.0;
    msr->tbm.fj[2]=1.570796327;
    msr->tbm.fj[3]=3.141592654;
    msr->tbm.funit=1;

    ///设计排版
    msr->iseg.k=0;
    msr->iseg.type=1;
    msr->iseg.ipos=(int*)malloc(msr->segt.Ks*sizeof(int));
    memset(msr->iseg.ipos,0,sizeof(int));
    msr->ns=0;

    ///设计排版
    msr->dseg.k=0;
    msr->dseg.type=1;
    msr->dseg.ipos=(int*)malloc(msr->segt.Ks*sizeof(int));
    memset(msr->dseg.ipos,0,sizeof(int));


    return 1;
}

extern int msr_init_des(msr_t*  msr)
{
    double len=0.0;
    len=fabs(msr->prj.mile2-msr->prj.mile1);
    msr->ndes=len/msr->segt.L+1;
    if(msr->des) msr->des=(SEG*)realloc(msr->des,msr->ndes*sizeof(SEG));
    else msr->des=(SEG*)malloc(msr->ndes*sizeof(SEG));
    msr->des[0].k=0;
    msr->des[0].type=1;
    msr->des[0].mile=msr->prj.mile1;
    msr->des[0].ipos=(int*)malloc(msr->segt.Ks*sizeof(int));
    memset(msr->des[0].ipos,0,sizeof(int));
    return 0;
}

extern int msr_store_road(msr_t*  msr)
{

    return 0;
}

extern int msr_store_prj(msr_t*  msr)
{

    return 0;
}

extern void msr_final()
{

    //road_final(&cli.r);
}

extern int msr_init_kpos(msr_t* msr)
{
    int k=msr->segt.Ks;
    int b=msr->nblk;
    double* hz;
    double* ihz;
    int s2s=msr->segt.s2s;    ///2 1/2k块的角度； 3 1/3k块的角度
    int i,j,ik;
    double roll,ival;


    hz=(double*)malloc(b*sizeof(double));
    ihz=(double*)malloc(b*sizeof(double));

    hz[0]=msr->blocks[0].angle/2;
    for(i=1;i<b;i++)
    {
        hz[i]=hz[i-1]+msr->blocks[i].angle;
    }

    roll=2.0*PI/k;
    for(i=0;i<k;i++)
    {
        if(i==0)
        {
            msr->kpos[0]=1;
        }
        else
        {
            for(j=0;j<b;j++)
            {
                ihz[j]=hz[j]+roll*i;
                while(ihz[j]>=2.0*PI)
                {
                    ihz[j]=ihz[j]-2.0*PI;
                }
            }

            for(j=0;j<b;j++)
            {
                for(ik=0;ik<b;ik++)
                {
                    ival=fabs(ihz[j]-hz[ik]);
                    if(ival<hz[0]*2/s2s) break;
                }
                if(ik<b)
                {
                    msr->kpos[i]=1;
                    break;
                }
                else
                {
                    msr->kpos[i]=0;
                }
            }
        }
    }

    return 0;
}

extern int msr_init_pz(msr_t* msr)
{
    int k=msr->segt.Ks;
    int i;
    double l2s;
    double beta,deta,pz;
    //FILE* fp=fopen("D:\\msr_init_pz.log","w");
    beta=2.0*PI/k;
    l2s=msr->segt.l2s;
    for(i=0;i<k;i++)
    {
        if(i*beta>PI/2) break;
    }
    msr->hpz=(double*)malloc(i*sizeof(double));
    msr->nhp=i;
    msr->vpz=(double*)malloc(i*sizeof(double));
    msr->nvp=i;
    for(i=0;i<msr->nhp;i++)
    {
        deta=i*beta;
        pz=atan(l2s/2.0*sin(deta)/msr->segt.De);
        msr->hpz[i]=pz*2.0;
        pz=atan(l2s/2.0*cos(deta)/msr->segt.De);
        msr->vpz[i]=pz*2.0;
        //if(fp) fprintf(fp,"i=%d,pz=%.4f\n",i,msr->pz[i]);
    }

    //if(fp) fclose(fp);
    return 0;
}

extern int msr_get_kpos(msr_t* msr,SEG* iseg)
{
    int k=msr->segt.Ks;
    int i,j,ik;

    if(msr->segt.in==1) return 0;

    j=iseg->k1;
    if(j==k) j=0;
    for(i=0;i<k;i++)
    {
        ik=i-j;
        if(ik<0) ik=ik+k;
        iseg->ipos[i]=msr->kpos[ik];
    }

    return 0;
}

extern int msr_cal_design(msr_t*  msr,int index)
{
    int ret=0;
    double iw,len;
    int i,j,ns;
    //SEG* segs=0;
    double l2s;
    double li,h1,h2,dh,dv;
    double x,y,z;
    double dx,dy,dz;
    double ori,phi;
    int k=msr->segt.Ks;
    double off,mxh;
    int ki;
    FILE* fp=fopen("D:\\msr_cal_design.log","w");

    if (msr->ndes==1) return 0;
    iw=msr->segt.L;

    mxh=iw*sin(msr->hpz[msr->nhp-1]);

    //segs=(SEG*)malloc(ns*sizeof(SEG));
    ///计算楔形量
    ns=index;
    li=msr->des[ns].mile;
    road_l2xy(&msr->r,li,&x,&y,0);
    road_l2h(&msr->r,li,&z,0);
    msr->des[ns].x=x;
    msr->des[ns].y=y;
    msr->des[ns].z=z;
    //msr->des[index].ipos=(int*)malloc(k*sizeof(int));
    //msr->des[index].numb=msr->dseg.numb;
    if(msr->prj.a2z>0)
    {
        while(li<msr->prj.mile2)
        {
            li+=iw;
            road_l2xy(&msr->r,li,&x,&y,0);
            road_l2h(&msr->r,li,&z,0);
            dx=x-msr->des[ns].x;
            dy=y-msr->des[ns].y;
            dz=z-msr->des[ns].z;
            ori=atan2(dy,dx);
            if(ori<0.0) ori+=2.0*PI;
            phi=asin(dz/iw);
            msr->des[ns].ori=ori;
            msr->des[ns].phi=phi;

            ns+=1;
            msr->des[ns].x=x;
            msr->des[ns].y=y;
            msr->des[ns].z=z;
            msr->des[ns].mile=li;
            //if(fp) fprintf(fp,"i=%d,x=%.4f,y=%.4f,z=%.4f,li=%.4f\n",ns,segs[ns].x,segs[ns].y,segs[ns].z,segs[ns].mile);
        }
    }
    else
    {
        while(li>msr->prj.mile2)
        {
            li-=iw;
            road_l2xy(&msr->r,li,&x,&y,0);
            road_l2h(&msr->r,li,&z,0);
            dx=x-msr->des[ns].x;
            dy=y-msr->des[ns].y;
            dz=z-msr->des[ns].z;
            ori=atan2(dy,dx);
            if(ori<0.0) ori+=2.0*PI;
            phi=asin(dz/iw);
            msr->des[ns].ori=ori;
            msr->des[ns].phi=phi;

            ns+=1;
            msr->des[ns].x=x;
            msr->des[ns].y=y;
            msr->des[ns].z=z;
            msr->des[ns].mile=li;
        }
    }

    ///
    //segs[0].k=msr->dseg.k;
    //segs[0].type=msr->dseg.type;
    i=index;
    ki=msr->des[i].k;
    if(ki>msr->nhp) ki=k-ki-1;
    if(msr->des[i].type==1) msr->des[i].ori1=msr->des[i].ori;
    else if(msr->des[i].type==2) msr->des[i].ori1=msr->des[i].ori-msr->hpz[ki]/2.0;
    else if(msr->des[i].type==3) msr->des[i].ori1=msr->des[i].ori+msr->hpz[ki]/2.0;
    i+=1;

    while(i<ns)
    {
        msr->des[i].k1=msr->des[i-1].k;
        msr->des[i].ipos=(int*)malloc(k*sizeof(int));
        msr_get_kpos(msr,&msr->des[i]);

        h1=msr->des[i-1].ori1;
        h2=msr->des[i+1].ori;
        if(h2<PI/2.0 && h1>PI*3.0/2.0) dh=h2+PI*2.0-h1;
        else if(h1<PI/2.0 && h2>PI*3.0/2.0) dh=h2-PI*2.0-h1;
        else dh=h2-h1;
        msr->des[i].numb=msr->des[i-1].numb+1;
        //if(fp) fprintf(fp,"i=%d,h1=%.4f,h2=%.4f,dh=%.4f\n",i,h1,h2,dh);
        if(fabs(dh)<0.0001)
        {
            ori=msr->des[i-1].ori1;
            x=msr->des[i-1].x+iw*cos(ori);
            y=msr->des[i-1].y+iw*sin(ori);
            road_xy2l(&msr->r,x,y,0,0,0,0,&off);
            off=off*msr->prj.a2z;

            if(off>=mxh && dh<=0.0)
            {
                msr->des[i].type=2;
                if(msr->des[i].ipos[0]==0) msr->des[i].k=0;
                else if(msr->des[i].ipos[k-1]==0) msr->des[i].k=k-1;
                ki=msr->nhp-1;
                msr->des[i].ori=msr->des[i-1].ori1-msr->hpz[ki]/2.0;
                msr->des[i].ori1=msr->des[i].ori-msr->hpz[ki]/2.0;
            }
            else if(off<=-mxh && dh>=0.0)
            {
                msr->des[i].type=3;
                if(msr->des[i].ipos[0]==0) msr->des[i].k=0;
                else if(msr->des[i].ipos[k-1]==0) msr->des[i].k=k-1;
                ki=msr->nhp-1;
                msr->des[i].ori=msr->des[i-1].ori1+msr->hpz[ki]/2.0;
                msr->des[i].ori1=msr->des[i].ori+msr->hpz[ki]/2.0;
            }
            else
            {
                msr->des[i].type=1;
                if(msr->des[i].ipos[0]==0) msr->des[i].k=0;
                else if(msr->des[i].ipos[k-1]==0) msr->des[i].k=k-1;
                msr->des[i].ori=msr->des[i-1].ori1;
                msr->des[i].ori1=msr->des[i-1].ori1;
            }
        }
        else
        {
            for(j=msr->nhp-1;j>0;j--)
            {
                //if(fp) fprintf(fp,"j=%d,dh=%.4f,pz=%.4f\n",j,dh,msr->hpz[j]);
                if(fabs(dh)>=msr->hpz[j])
                {
                    ki=msr->nhp-j-1;
                    if(fp) fprintf(fp,"ki=%d\n",ki);
                    if(msr->des[i].ipos[ki]==0) msr->des[i].k=ki;
                    else msr->des[i].k=k-ki-1;
                    if(dh>0.0)
                    {
                        msr->des[i].type=3;
                        msr->des[i].ori=msr->des[i-1].ori1+msr->hpz[j]/2.0;
                        msr->des[i].ori1=msr->des[i].ori+msr->hpz[j]/2.0;
                    }
                    else
                    {
                        msr->des[i].type=2;
                        msr->des[i].ori=msr->des[i-1].ori1-msr->hpz[j]/2.0;
                        msr->des[i].ori1=msr->des[i].ori-msr->hpz[j]/2.0;
                    }
                    break;
                }
                if(j==1) break;
            }

            //if(fp) fprintf(fp,"j=%d\n",j);

            if(j==1)
            {
                ori=msr->des[i-1].ori1;
                x=msr->des[i-1].x+iw*cos(ori);
                y=msr->des[i-1].y+iw*sin(ori);
                road_xy2l(&msr->r,x,y,0,0,0,0,&off);
                off=off*msr->prj.a2z;
                ki=msr->nhp-1;
                //if(fp) fprintf(fp,"i=%d,off=%.4f,dh=%.4f,mxh=%.4f\n",i,off,dh,mxh);
                if(off>=mxh && dh<=0.0)
                {
                    msr->des[i].type=2;

                    if(msr->des[i].ipos[0]==0) msr->des[i].k=0;
                    else if(msr->des[i].ipos[k-1]==0) msr->des[i].k=k-1;
                    ki=msr->nhp-1;
                    msr->des[i].ori=msr->des[i-1].ori1-msr->hpz[ki]/2.0;
                    msr->des[i].ori1=msr->des[i].ori-msr->hpz[ki]/2.0;
                }
                else if(off<=-mxh && dh>=0.0)
                {
                    msr->des[i].type=3;
                    if(msr->des[i].ipos[0]==0) msr->des[i].k=0;
                    else if(msr->des[i].ipos[k-1]==0) msr->des[i].k=k-1;
                    ki=msr->nhp-1;
                    msr->des[i].ori=msr->des[i-1].ori1+msr->hpz[ki]/2.0;
                    msr->des[i].ori1=msr->des[i].ori+msr->hpz[ki]/2.0;
                }
                else
                {
                    msr->des[i].type=1;
                    if(msr->des[i].ipos[0]==0) msr->des[i].k=0;
                    else if(msr->des[i].ipos[k-1]==0) msr->des[i].k=k-1;
                    msr->des[i].ori=msr->des[i-1].ori1;
                    msr->des[i].ori1=msr->des[i-1].ori1;
                }
            }
        }
        ori=msr->des[i].ori;
        x=msr->des[i-1].x+iw*cos(ori);
        y=msr->des[i-1].y+iw*sin(ori);
        road_xy2l(&msr->r,x,y,0,0,0,0,&off);
        off=off*msr->prj.a2z;
        msr->des[i].x=x;
        msr->des[i].y=y;
        msr->des[i].dh=off;
        if(msr->des[i].type==1)
        {
            msr->des[i].harc=0.0;
            msr->des[i].varc=0.0;
        }
        else if(msr->des[i].type==2)
        {
            ki=msr->des[i].k;
            if(ki>msr->nhp) ki=k-ki-1;
            ki=msr->nhp-ki-1;
            ori=msr->hpz[ki]/2.0;
            msr->des[i].harc=msr->segt.De*tan(ori)*2.0;

            if(msr->des[i].k>msr->nhp) msr->des[i].varc=msr->segt.De*tan(phi)*2.0;
            else msr->des[i].varc=-msr->segt.De*tan(phi)*2.0;
        }
        else if(msr->des[i].type==3)
        {
            ki=msr->des[i].k;
            if(ki>msr->nhp) ki=k-ki-1;
            ki=msr->nhp-ki-1;
            ori=msr->hpz[ki]/2.0;
            msr->des[i].harc=-msr->segt.De*tan(ori)*2.0;
            phi=msr->vpz[ki]/2.0;
            if(msr->des[i].k>msr->nhp)
            {
                msr->des[i].varc=-msr->segt.De*tan(phi)*2.0;
            }
            else
            {
                msr->des[i].varc=msr->segt.De*tan(phi)*2.0;
            }
        }

        i++;
    }

    msr->des[ns].numb=msr->des[ns-1].numb+1;
    msr->des[ns].k1=msr->des[ns-1].k;
    msr->des[ns].ipos=(int*)malloc(k*sizeof(int));
    msr_get_kpos(msr,&msr->des[ns]);
    msr->des[ns].type=1;
    if(msr->des[ns].ipos[0]==0) msr->des[ns].k=0;
    else if(msr->des[ns].ipos[k-1]==0) msr->des[ns].k=k-1;
    msr->des[ns].ori=msr->des[ns-1].ori1;
    msr->des[ns].ori1=msr->des[ns-1].ori1;
    ori=msr->des[ns].ori;
    x=msr->des[ns-1].x+iw*cos(ori);
    y=msr->des[ns-1].y+iw*sin(ori);
    road_xy2l(&msr->r,x,y,&li,0,0,0,&off);
    off=off*msr->prj.a2z;
    msr->des[ns].mile=li;
    msr->des[ns].x=x;
    msr->des[ns].y=y;
    msr->des[ns].dh=off;
    msr->des[ns].harc=0.0;
    msr->des[ns].varc=0.0;

    if(fp) fclose(fp);

    return ns+1;
}
