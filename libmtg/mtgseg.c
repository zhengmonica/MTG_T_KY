#include "libmtg.h"
#include "geometry.h"
#include "trace.h"
#include "mysql/mysql.h"
#include <stdio.h>

#define PI  3.1415926535897932384626433832795

///初始化管环
extern int mtg_init_segs(mtg_t* mtg)
{
    int k=mtg->segset.Ks;
    int i,j,ik,mxi,n;
    double De=mtg->segset.De;
    double ihz;
    double l2s=mtg->segset.l2s;
    double ilen=mtg->segset.L;
    double a,b,c;
    double mxh,mxv,ival;
    double hmxr,vmxr;
    MTG_SEG iseg;

    mtg->kpos=(int*)malloc(k*sizeof(int));
    mtg_init_kpos(mtg);

    if(mtg->segset.f2b==0)
    {
        ihz=atan(l2s/2.0/De);
        a=ilen/2+l2s/2;
        b=a/tan(ihz);
        //mtg->segset.mxjust=ilen*tan(ihz);

    }
    else if(mtg->segset.f2b==1)
    {
        ihz=atan(l2s/De);
        a=ilen+l2s/2;
        b=a/sin(ihz);
        //mtg->segset.mxjust=ilen*tan(2*ihz);
    }

    //mtg->segset.minr=b;
    for(i=0;i<MAX_SEG;i++)
    {
        if(mtg->segset.type==0) mtg->segs[i].type=0;
        else if(mtg->segset.type==1) mtg->segs[i].type=1;
        mtg->segs[i].k=0;
        mtg->segs[i].gap[0] = mtg->segset.G0;
        mtg->segs[i].gap[1] = mtg->segset.G0;
        mtg->segs[i].gap[2] = mtg->segset.G0;
        mtg->segs[i].gap[3] = mtg->segset.G0;
        mtg->segs[i].ipos=(int*)malloc(k*sizeof(int));
        if(i>0) mtg->segs[i].numb=mtg->segs[i-1].numb+1;
    }

    if(mtg->segs[0].t>0)
    {
        j=mtg->segs[0].k;
        if(j==k) j=0;
        for(i=0;i<k;i++)
        {
            ik=i+j;
            if(ik>=k) ik=ik-k;
            mtg->segs[1].ipos[ik]=mtg->kpos[i];
        }
    }
    else
    {
        if(mtg->segset.type==0) mtg->segs[0].type=0;
        else if(mtg->segset.type==1) mtg->segs[0].type=1;
        mtg->segs[0].k=0;
    }

    iseg=mtg->segs[0];
    De=mtg->segset.De;
    iseg.type=2;
    mxh=0.0;
    mxv=0.0;
    hmxr=0.0;
    vmxr=0.0;

    for(i=0;i<k;i++)
    {
        iseg.k=i;
        mtg_seg_parameters(mtg,&iseg);
        ival=fabs(iseg.hpz)*2.0;
        if(mxh<ival) mxh=ival;
        ival=fabs(iseg.vpz)*2.0;
        if(mxv<ival)
        {
            mxv=ival;
            mxi=i;
        }
    }

    hmxr=ilen/sin(mxh);
    vmxr=ilen/sin(mxv);
    mtg->spara.hmxr=hmxr;
    mtg->spara.vmxr=vmxr;
    mxh=ilen*sin(mxh)*2.0;
    mxv=ilen*sin(mxv)*2.0;
    mtg->spara.mxh=mxh;
    mtg->spara.mxv=mxv;
    mtg->spara.mxi=mxi;
    mtg->spara.mxhi=asin(mxh/ilen);
    mtg->spara.mxvi=asin(mxv/ilen);
    return 0;
}

extern int mtg_init_seging(mtg_t* mtg)
{
    double l1,l2,len;
    double x1,y1,z1;
    double x2,y2,z2;
    double hz1,vz1,hz2,vz2;
    double beta,deta;
    double ds1,ds2;
    double mxh,mxv,ival;
    double mxi,mxj;
    double iL=mtg->segset.L;
    double De=mtg->segset.De;
    int k=mtg->segset.Ks;
    MTG_SEG iseg;
    int i,n;

    for(i=0;i<k;i++)
    {
        mtg->iseg.ipos[i]=0;
    }
    trace(0,"mtg_init_seging:%d\n",mtg->iseg.t);
    if(mtg->iseg.t<=0)
    {
        l1=mtg->prj.mile1;
        mtg->iseg.numb=0;
        if(mtg->prj.a2z==1) mtg->iseg.headc=l1+iL;
        else mtg->iseg.headc=l1-iL;
        trace(0,"l1=%.4f\n",l1);
    }
    else
    {
        if(mtg->prj.a2z==1) l1=mtg->iseg.headc-iL;
        else l1=mtg->iseg.headc+iL;
    }

    road_l2xy(&mtg->r,l1,&x1,&y1,&hz1);
    road_l2h(&mtg->r,l1,&z1,&vz1);
    l2=mtg->iseg.headc;
    road_l2xy(&mtg->r,l2,&x2,&y2,&hz2);
    road_l2h(&mtg->r,l2,&z2,&vz2);
    beta=atan2(y2-y1,x2-x1);
    if(beta<0.0) beta+=2.0*PI;
    deta=beta-hz1;
    ds1=De*tan(deta);
    deta=hz2-beta;
    ds1=ds1+De*tan(deta);
    beta=asin((z2-z1)/iL);
    deta=beta-vz1;
    ds2=De*tan(beta);
    deta=vz2-beta;
    ds2=ds2+De*tan(deta);

    iseg=mtg->iseg;
    iseg.type=2;

    for(i=0;i<k;i++)
    {
        iseg.k=i;
        mtg_seg_parameters(mtg,&iseg);
        ival=fabs(iseg.len[2]-iseg.len[3]);
        if(mxh<ival)
        {
            mxh=ival;
            mxi=i;
        }
        ival=fabs(iseg.len[0]-iseg.len[1]);
        if(mxv<ival)
        {
            mxv=ival;
            mxj=i;
        }
    }
    if(mtg->segset.type==0) mtg->iseg.type=0;
    else if(mtg->segset.type==1) mtg->iseg.type=1;
    if(ds1<=-mxh)
    {
        if(mtg->segset.type==1) mtg->iseg.type=3;
        mtg->iseg.k=mxi;
    }
    else if(ds1>=mxh)
    {
        if(mtg->segset.type==1) mtg->iseg.type=2;
        mtg->iseg.k=mxi;
    }
    else if(ds2<=-mxv)
    {
        if(mtg->segset.type==1) mtg->iseg.type=3;
        mtg->iseg.k=mxj;
    }
    else if(ds2>=mxv)
    {
        if(mtg->segset.type==1) mtg->iseg.type=2;
        mtg->iseg.k=mxj;
    }

    return 0;
}

///管环参数计算
extern int mtg_seg_parameters(mtg_t* mtg,MTG_SEG* iseg)
{
    int k=mtg->segset.Ks;
    int i,k1;
    double beta,deta,len;
    double pz,dlen,mxdl;
    double a,b;

    beta=2.0*PI/k;
    len=mtg->segset.L;
    k1=iseg->k;
    mxdl=mtg->segset.l2s;
    b=mtg->segset.De;
    for(i=0;i<k;i++)
    {
        if(i*beta>PI/2)
        {
            pz=i*beta-PI/2;
            break;
        }
    }

    if(iseg->type==0)
    {
        deta=pz+k1*beta;
        dlen=mxdl*cos(deta);
        iseg->len[0]=len+dlen/2.0;
        iseg->len[1]=len-dlen/2.0;
        deta+=PI/2.0;
        dlen=mxdl*cos(deta);
        iseg->len[2]=len+dlen/2.0;
        iseg->len[3]=len-dlen/2.0;
    }
    else if(iseg->type==1)
    {
        iseg->len[0]=len;
        iseg->len[1]=len;
        iseg->len[2]=len;
        iseg->len[3]=len;
    }
    else if(iseg->type==2)
    {
        deta=PI/2.0+pz+k1*beta;
        if(deta>2.0*PI) deta=deta-2.0*PI;
        dlen=mxdl*cos(deta);
        iseg->len[0]=len+dlen/2.0;
        iseg->len[1]=len-dlen/2.0;
        deta+=PI/2.0;
        dlen=mxdl*cos(deta);
        iseg->len[2]=len+dlen/2.0;
        iseg->len[3]=len-dlen/2.0;
    }
    else if(iseg->type==3)
    {
        deta=PI*3.0/2.0+pz+k1*beta;
        if(deta>2.0*PI) deta=deta-2.0*PI;
        dlen=mxdl*cos(deta);
        iseg->len[0]=len+dlen/2.0;
        iseg->len[1]=len-dlen/2.0;
        deta+=PI/2.0;
        dlen=mxdl*cos(deta);
        iseg->len[2]=len+dlen/2.0;
        iseg->len[3]=len-dlen/2.0;
    }

    a=(iseg->len[2]-iseg->len[3])/2.0;
    iseg->hpz=atan(a/b);
    a=(iseg->len[0]-iseg->len[1])/2.0;
    iseg->vpz=-atan(a/b);
    //trace(0,"u=%.4f,d=%.4f,l=%.4f,r=%.4f\n",iseg->len[0],iseg->len[1],iseg->len[2],iseg->len[3]);
    return 0;
}

///起始管环中心坐标
extern int mtg_init_position(mtg_t* mtg)
{
    double a,b,c;
    double inc[3];
    double iinc[3];
    double dx,dy,dz;
    //double ilen,len;
    double ihead[3],itail[3];
    double il=mtg->segset.L;
    double dh1,dv1,ori1,phi1;
    double ix,iy,iz;
    double ix1,iy1,iz1;
    double headc,tailc,mxhi,vxmi;
    double gap[4];
    double dh,dv,dhz,dvz;
    double len1;
    double len[2],ilen[2];
    int i;
    MTG_SEG* iseg=&mtg->segs[10];

    gap[0]=iseg->gap[0];
    gap[1]=iseg->gap[1];
    gap[2]=iseg->gap[2];
    gap[3]=iseg->gap[3];

    if(mtg->m1.t1<=0)
    {
        headc=mtg->prj.mile1;
        road_l2xy(&mtg->r,headc,&ihead[0],&ihead[1],&inc[2]);
        road_l2h(&mtg->r,headc,&ihead[2],&inc[1]);

        if(mtg->ilen==0) mtg->ilen=5.4;
        if(mtg->prj.a2z==1) tailc=headc-mtg->ilen;
        else tailc=headc+mtg->ilen;
        road_l2xy(&mtg->r,tailc,&itail[0],&itail[1],0);
        road_l2h(&mtg->r,tailc,&itail[2],0);

        if(mtg->prj.a2z==-1)
        {
            inc[2]+=PI;
            if(inc[2]>2.0*PI) inc[2]-=2.0*PI;
            inc[1]+=PI;
            if(inc[1]>2.0*PI) inc[1]-=2.0*PI;
        }

        iseg->headc=headc;
        iseg->head[0]=ihead[0];
        iseg->head[1]=ihead[1];
        iseg->head[2]=ihead[2];
        iseg->headc=tailc;
        iseg->tail[0]=itail[0];
        iseg->tail[1]=itail[1];
        iseg->tail[2]=itail[2];
        iseg->tbmh=inc[2];
        iseg->tbmv=inc[1];
        iseg->ori1=inc[2];
        iseg->phi1=inc[1];
        iseg->dh1=0.0;
        iseg->dv1=0.0;
        iseg->dh=0.0;
        iseg->dv=0.0;
        iseg->desh=inc[2];
        iseg->desv=inc[1];

        iseg->aj[0]=iseg->aj[1]=iseg->aj[2]=iseg->aj[3]=0.0;
        iseg->baj[0]=iseg->baj[1]=iseg->baj[2]=iseg->baj[3]=0.0;
        iseg->faj[0]=iseg->faj[1]=iseg->faj[2]=iseg->faj[3]=0.0;
        iseg->ori=0.0;
        iseg->phi=0.0;
        iseg->harc=0.0;
        iseg->varc=0.0;

        if(mtg->tbm.type<2) ilen[0]=mtg->tbm.L[3];
        else ilen[0]=mtg->tbm.L[3]-mtg->tbm.L[0];

        inc[2]=inc[2]+PI;
        inc[1]=-inc[1];
        ix=ihead[0]+ilen[0]*cos(inc[1])*cos(inc[2]);
        ix=ihead[1]+ilen[0]*cos(inc[1])*sin(inc[2]);
        ix=ihead[2]+ilen[0]*sin(inc[1]);

        iseg->x1=ix;
        iseg->y1=iy;
        iseg->z1=iz;
        iseg->x=ix;
        iseg->y=iy;
        iseg->z=iz;
        if(mtg->prj.a2z==1) iseg->mile=headc-ilen[0];
        else iseg->mile=headc+ilen[0];
    }
    else
    {
        if(mtg->tbm.type<2)
        {
            itail[0]=mtg->m.tail[0];
            itail[1]=mtg->m.tail[1];
            itail[2]=mtg->m.tail[2];
            ihead[0]=mtg->m.head[0];
            ihead[1]=mtg->m.head[1];
            ihead[2]=mtg->m.head[2];
            inc[2]=mtg->m.inc1[2]*PI/180.0;
            inc[1]=mtg->m.inc1[1]*PI/180.0;
            headc=mtg->m.headc;
            tailc=mtg->m.tailc;
            len1=mtg->ilen;
            len[0]=mtg->tbm.L[3]+(mtg->m.aj[0]+mtg->m.aj[1]+mtg->m.aj[2]+mtg->m.aj[3])/4.0;
            len[1]=len1-len[0];
        }
        else
        {
            if(mtg->tarset.pos==0)
            {
                itail[0]=mtg->m.tail1[0];
                itail[1]=mtg->m.tail1[1];
                itail[2]=mtg->m.tail1[2];
                inc[1]=mtg->m.inc2[1]*PI/180;
                inc[2]=mtg->m.inc2[2]*PI/180;
                ihead[0]=mtg->m.head1[0];
                ihead[1]=mtg->m.head1[1];
                ihead[2]=mtg->m.head1[2];
                headc=mtg->m.headc1;
                tailc=mtg->m.tailc1;
                len1=mtg->ilen;
                len[0]=mtg->tbm.L[3]-len1+(mtg->m.aj[0]+mtg->m.aj[1]+mtg->m.aj[2]+mtg->m.aj[3])/4.0;
                if(mtg->tbm.type==2) len[1]=mtg->tbm.L[2]-len[0];
                else len[1]=mtg->tbm.L[1]-len[0];
            }
            else
            {
                itail[0]=mtg->m.tail[0];
                itail[1]=mtg->m.tail[1];
                itail[2]=mtg->m.tail[2];
                inc[1]=mtg->m.inc1[1]*PI/180;
                inc[2]=mtg->m.inc1[2]*PI/180;
                ihead[0]=mtg->m.head[0];
                ihead[1]=mtg->m.head[1];
                ihead[2]=mtg->m.head[2];
                headc=mtg->m.headc;
                tailc=mtg->m.tailc;
                len1=mtg->ilen;
                len[0]=mtg->tbm.L[3]-mtg->tbm.L[0]+(mtg->m.aj[0]+mtg->m.aj[1]+mtg->m.aj[2]+mtg->m.aj[3])/4.0;
                len[1]=len1-len[0];
            }

        }
        ///管片前端中心坐标
        len1=len[1];
        ix=itail[0]+len1*cos(inc[1])*cos(inc[2]);
        iy=itail[1]+len1*cos(inc[1])*sin(inc[2]);
        iz=itail[2]+len1*sin(inc[1]);

        iseg->headc=headc;
        iseg->head[0]=ihead[0];
        iseg->head[1]=ihead[1];
        iseg->head[2]=ihead[2];
        iseg->tailc=tailc;
        iseg->tail[0]=itail[0];
        iseg->tail[1]=itail[1];
        iseg->tail[2]=itail[2];
        iseg->tbmh=inc[2];
        iseg->tbmv=inc[1];
        iseg->x1=ix;
        iseg->y1=iy;
        iseg->z1=iz;
        iseg->tbmh=inc[2];
        iseg->tbmv=inc[1];

        a=mtg->tbm.D[0];
        b=mtg->m1.aj[2]-mtg->m1.aj[3];

        iinc[0]=atan(b/a);
        iinc[2]=inc[2]-iinc[0];
        b=mtg->m1.aj[0]-mtg->m1.aj[1];
        iinc[0]=atan(b/a);
        iinc[1]=inc[1]+iinc[0];
        iseg->ori1=iinc[2];
        iseg->phi1=iinc[1];

        len1=(gap[2]-gap[3])/2.0;
        iseg->dh1=len1;

        inc[0]=iinc[2]+PI/2.0;
        ix=ix+len1*cos(inc[0]);
        iy=iy+len1*sin(inc[0]);
        len1=(gap[0]-gap[1])/2.0;
        iseg->dv1=-len1;
        inc[0]=iinc[1];
        iz=iz-len1*cos(inc[0]);

        iseg->x=ix;
        iseg->y=iy;
        iseg->z=iz;

        road_xy2l(&mtg->r,ix,iy,&iseg->mile,0,0,&inc[2],&iseg->dh);
        road_l2h(&mtg->r,iseg->mile,&iseg->dv,&inc[1]);
        iseg->dv=iz-iseg->dv;
        if(mtg->prj.a2z==-1)
        {
            iseg->dh=-iseg->dh;
            inc[2]=inc[2]+PI;
            if(inc[2]>2.0*PI) inc[2]-=2.0*PI;
            inc[1]+=PI;
            if(inc[1]>2.0*PI) inc[1]-=2.0*PI;
        }
        iseg->desh=inc[2];
        iseg->desv=inc[1];

        iseg->aj[0]=mtg->m1.aj[0];
        iseg->aj[1]=mtg->m1.aj[1];
        iseg->aj[2]=mtg->m1.aj[2];
        iseg->aj[3]=mtg->m1.aj[3];

        iseg->faj[0]=mtg->m1.faj[0];
        iseg->faj[1]=mtg->m1.faj[1];
        iseg->faj[2]=mtg->m1.faj[2];
        iseg->faj[3]=mtg->m1.faj[3];

        iseg->baj[0]=mtg->m1.baj[0];
        iseg->baj[1]=mtg->m1.baj[1];
        iseg->baj[2]=mtg->m1.baj[2];
        iseg->baj[3]=mtg->m1.baj[3];

        mtg_seg_parameters(mtg,iseg);
        iseg->ori=iseg->ori1-iseg->hpz;
        iseg->phi=iseg->phi1-iseg->vpz;
        iseg->harc=mtg->segs[0].aj[2]-mtg->segs[0].aj[3];
        iseg->varc=mtg->segs[0].aj[0]-mtg->segs[0].aj[1];

    }

    if(iseg->t>0)
    {
        dh1=iseg->dh;
        dv1=iseg->dv;
        dh1=fabs(dh1-iseg->dh1);
        dv1=fabs(dv1-iseg->dv1);
        //ori1=iseg->ori1;
        //phi1=iseg->phi1;
        if(dh1>=mtg->spara.mxh || dv1>=mtg->spara.mxh) mtg->spara.cal=1;
        else mtg->spara.cal=0;
    }
    else
    {
        mtg->spara.cal=1;
    }

    return 0;
}

extern int mtg_init_kpos(mtg_t* mtg)
{
    int k=mtg->segset.Ks;
    int b=mtg->nblk;
    double* hz;
    double* ihz;
    int s2s=mtg->segset.s2s;    ///2 1/2k块的角度； 3 1/3k块的角度
    int i,j,ik;
    double roll,ival;


    hz=(double*)malloc(b*sizeof(double));
    ihz=(double*)malloc(b*sizeof(double));

    hz[0]=mtg->blocks[0].angle/2;
    for(i=1;i<b;i++)
    {
        hz[i]=hz[i-1]+mtg->blocks[i].angle;
    }

    roll=2.0*PI/k;
    for(i=0;i<k;i++)
    {
        if(i==0)
        {
            mtg->kpos[0]=1;
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
                    mtg->kpos[i]=1;
                    break;
                }
                else
                {
                    mtg->kpos[i]=0;
                }
            }
        }
        //trace(0,"mtg_init_kpos:i=%d,pos=%d\n",i,mtg->kpos[i]);
    }

    return 0;
}

extern int mtg_get_kpos(mtg_t* mtg,MTG_SEG* iseg)
{
    int k=mtg->segset.Ks;
    int i,j,ik;

    if(mtg->segset.in==1) return 0;

    j=iseg->k1;
    if(j==k) j=0;
    //trace(0,"k1=%d\n",j);
    for(i=0;i<k;i++)
    {
        ik=i-j;
        if(ik<0) ik=ik+k;
        //trace(0,"ik=%d\n",ik);
        iseg->ipos[i]=mtg->kpos[ik];
        //trace(0,"i=%d,kpos=%d\n",i,iseg.ipos[i]);
    }

    return 0;
}

extern int mtg_seg_cal(mtg_t* mtg)
{
    double headc,iL;
    double head[3],tail[3];
    double ori,phi;
    double De,dh,dv;
    double a,b,c,c1;
    double beta,deta;
    double harc,varc;
    double tailc,tailh,tailv;
    iL=mtg->segset.L;
    De=mtg->segset.De;

    mtg_seg_parameters(mtg,&mtg->segs[11]);
    mtg->segs[11].tbmh=mtg->segs[10].tbmh;
    mtg->segs[11].tbmv=mtg->segs[10].tbmv;
    ori=mtg->segs[10].ori1+mtg->segs[11].hpz;
    phi=mtg->segs[10].phi1+mtg->segs[11].vpz;
    mtg->segs[11].ori1=ori+mtg->segs[11].hpz;
    mtg->segs[11].phi1=phi+mtg->segs[11].vpz;
    mtg->segs[11].ori=ori;
    mtg->segs[11].phi=phi;
    head[0]=mtg->segs[10].head[0]+iL*cos(phi)*cos(ori);
    head[1]=mtg->segs[10].head[1]+iL*cos(phi)*sin(ori);
    head[2]=mtg->segs[10].head[2]+iL*sin(phi);

    tail[0]=mtg->segs[10].tail[0]+iL*cos(phi)*cos(ori);
    tail[1]=mtg->segs[10].tail[1]+iL*cos(phi)*sin(ori);
    tail[2]=mtg->segs[10].tail[2]+iL*sin(phi);

    road_xy2l(&mtg->r,head[0],head[1],&headc,0,0,&ori,&dh);
    road_l2h(&mtg->r,headc,&dv,&phi);
    dv=head[2]-dv;
    road_xy2l(&mtg->r,tail[0],tail[1],&tailc,0,0,0,&tailh);
    road_l2h(&mtg->r,tailc,&tailv,0);
    tailv=tail[2]-tailv;
    if(mtg->prj.a2z==-1)
    {
        dh=-dh;
        ori+=PI;
        if(ori>2.0*PI) ori+=2.0*PI;
        phi+=PI;
        if(phi>2.0*PI) phi+=2.0*PI;
    }
    mtg->segs[11].headc=headc;
    mtg->segs[11].head[0]=head[0];
    mtg->segs[11].head[1]=head[1];
    mtg->segs[11].head[2]=head[2];
    mtg->segs[11].headh=dh;
    mtg->segs[11].headv=dv;
    mtg->segs[11].tailc=tailc;
    mtg->segs[11].tail[0]=tail[0];
    mtg->segs[11].tail[1]=tail[1];
    mtg->segs[11].tail[2]=tail[2];
    mtg->segs[11].tailh=tailh;
    mtg->segs[11].tailv=tailv;

    deta=ori-mtg->segs[11].ori1+PI/2.0;

    c1=De/cos(mtg->segs[11].hpz);
    c=c1/2.0-dh/sin(deta);
    harc=c*cos(deta);
    c=c1-c;
    harc=harc+c*cos(deta);
    mtg->segs[11].harc=harc;

    deta=phi-mtg->segs[11].phi1+PI/2.0;
    c=c1/2.0+dv/sin(deta);
    varc=c*cos(deta);
    c=c1-c;
    varc=varc+c*cos(deta);
    mtg->segs[11].varc=varc;

    return 0;
}

///实际排版（标准+转弯）
extern int mtg_std_segs(mtg_t* mtg,int in)
{
    int k=mtg->segset.Ks;
    int i,j,n;
    double iL=mtg->segset.L;
    double l1,x1,y1,z1;
    double l2,x2,y2,z2;
    double li,xi,yi,zi;
    double ori,ori1,phi,phi1;
    double dx,dy,dz,dh,dv;
    double dh1,dv1;
    double hz,vz,hz1,vz1;
    double len,beta,beta1,deta,deta1;
    double gap;
    int cal=0;
    int just=0;
    double hc,hc1,hc2,vc,vc1,vc2;
    double r,a,b,c;
    double lx1,ly1,lz1,lx2,ly2,lz2;
    int hpz,vpz;
    double lori,lphi;

    gap=mtg->segset.G0-mtg->segset.G1;
    if(in==0)
    {
        if(mtg->segs[11].t<=0 || mtg->spara.cal==1)
        {
            i=11;
            cal=1;
        }
    }
    else
    {
        i=12;
        cal=1;
    }

    if(cal==1)
    {
        //hc=mtg->segs[i-1].headc;
        hc1=hc2=hc=0.0;
        vc=vc1=vc2=0.0;
        j=mtg->spara.mxi;
        while(i<MAX_SEG)
        {
            dh=mtg->segs[i-1].dh1;
            dv=mtg->segs[i-1].dv1;
            //trace(0,"seg:%d,dh=%.4f,dh1=%.4f\n",i,dh,dv);
            ori1=mtg->segs[i-1].ori1;
            phi1=mtg->segs[i-1].phi1;
            ori=mtg->segs[i-1].tbmh;
            phi=mtg->segs[i-1].tbmv;
            beta=ori1-ori;
            deta=phi1-phi;
            dh1=dh+iL*sin(beta);
            dv1=dv+iL*sin(deta);

            //trace(0,"seg:%d,%d,dh=%.4f,dh1=%.4f\n",i,mtg->segs[i-1].numb,dh,dh1);
            //trace(0,"seg:%d,dv=%.4f,dv1=%.4f\n",i,dv,dv1);
            //trace(0,"seg:%d,headv=%.4f,tailv=%.4f\n",i,mtg->segs[i-1].headv,mtg->segs[i-1].tailv);
            if(dh1<=-gap && dh1<=dh)
            {
                just=1;
                mtg->segs[i].type=3;
                mtg->segs[i].k1=mtg->segs[i-1].k;
                mtg_get_kpos(mtg,&mtg->segs[i]);
                if(dv1<=-gap && dv1<=dv)
                {
                    if(mtg->segs[i].ipos[k-2]==0) mtg->segs[i].k=k-2;
                    else if(mtg->segs[i].ipos[k-1]==0) mtg->segs[i].k=k-1;
                }
                else if(dv1>=gap && dv1>=dv)
                {
                    if(mtg->segs[i].ipos[1]==0) mtg->segs[i].k=1;
                    else if(mtg->segs[i].ipos[0]==0) mtg->segs[i].k=0;
                }
                else
                {
                    if(mtg->segs[i].ipos[0]==0) mtg->segs[i].k=0;
                    else if(mtg->segs[i].ipos[k-1]==0) mtg->segs[i].k=k-1;
                }
            }
            else if(dh1>=gap && dh1>=dh)
            {
                just=1;
                mtg->segs[i].type=2;
                mtg->segs[i].k1=mtg->segs[i-1].k;
                mtg_get_kpos(mtg,&mtg->segs[i]);
                if(dv1<=-gap && dv1<=dv)
                {
                    if(mtg->segs[i].ipos[1]==0) mtg->segs[i].k=1;
                    else if(mtg->segs[i].ipos[0]==0) mtg->segs[i].k=0;
                }
                else if(dv1>=gap && dv1>=dv)
                {
                    if(mtg->segs[i].ipos[k-2]==0) mtg->segs[i].k=k-2;
                    else if(mtg->segs[i].ipos[k-1]==0) mtg->segs[i].k=k-1;
                }
                else
                {
                    if(mtg->segs[i].ipos[0]==0) mtg->segs[i].k=0;
                    else if(mtg->segs[i].ipos[k-1]==0) mtg->segs[i].k=k-1;
                }
            }
            else if(dv1<=-gap && dv1<=dv)
            {
                just=1;
                mtg->segs[i].k1=mtg->segs[i-1].k;
                mtg_get_kpos(mtg,&mtg->segs[i]);
                if(mtg->segs[i].ipos[j]==0)
                {
                    mtg->segs[i].type=2;
                    mtg->segs[i].k=j;
                }
                else
                {
                    mtg->segs[i].type=3;
                    mtg->segs[i].k=j+k/2;
                }
            }
            else if(dv1>=gap && dv1>=dv)
            {
                just=1;
                mtg->segs[i].k1=mtg->segs[i-1].k;
                mtg_get_kpos(mtg,&mtg->segs[i]);
                if(mtg->segs[i].ipos[j]==0)
                {
                    mtg->segs[i].type=3;
                    mtg->segs[i].k=j;
                }
                else
                {
                    mtg->segs[i].type=2;
                    mtg->segs[i].k=j+k/2;
                }
            }
            else
            {
                just=0;
            }
            //trace(0,"%d,just=%d\n",i,just);
            if(just==1)
            {
                mtg->segs[i].tbmh=ori;
                mtg->segs[i].tbmv=phi;
                x1=mtg->segs[i-1].head[0]+iL*cos(phi)*cos(ori);
                y1=mtg->segs[i-1].head[1]+iL*cos(phi)*sin(ori);
                z1=mtg->segs[i-1].head[2]+iL*sin(phi);
                x2=mtg->segs[i-1].tail[0]+iL*cos(phi)*cos(ori);
                y2=mtg->segs[i-1].tail[1]+iL*cos(phi)*sin(ori);
                z2=mtg->segs[i-1].tail[2]+iL*sin(phi);

                road_xy2l(&mtg->r,x1,y1,&l1,0,0,0,&mtg->segs[i].headh);
                road_l2h(&mtg->r,l1,&mtg->segs[i].headv,0);
                mtg->segs[i].headv=z1-mtg->segs[i].headv;
                if(mtg->prj.a2z==-1) mtg->segs[i].headh=-mtg->segs[i].headh;
                mtg->segs[i].headc=l1;

                road_xy2l(&mtg->r,x2,y2,&l2,0,0,0,&mtg->segs[i].tailh);
                road_l2h(&mtg->r,l2,&mtg->segs[i].tailv,0);
                mtg->segs[i].tailv=z2-mtg->segs[i].tailv;
                if(mtg->prj.a2z==-1) mtg->segs[i].tailh=-mtg->segs[i].tailh;
                mtg->segs[i].tailc=l2;

                xi=mtg->segs[i-1].x1+iL*cos(phi)*cos(ori);
                yi=mtg->segs[i-1].y1+iL*cos(phi)*sin(ori);
                zi=mtg->segs[i-1].z1+iL*sin(phi);
                mtg->segs[i].x1=xi;
                mtg->segs[i].y1=yi;
                mtg->segs[i].z1=zi;
                road_xy2l(&mtg->r,xi,yi,&li,0,0,0,&mtg->segs[i].dh1);
                road_l2h(&mtg->r,li,&mtg->segs[i].dv1,0);
                mtg->segs[i].dv1=zi-mtg->segs[i].dv1;
                if(mtg->prj.a2z==-1) mtg->segs[i].dh1=-mtg->segs[i].dh1;

                mtg_seg_parameters(mtg,&mtg->segs[i]);
                ori=mtg->segs[i-1].ori1+mtg->segs[i].hpz;
                phi=mtg->segs[i-1].phi1+mtg->segs[i].vpz;
                xi=mtg->segs[i-1].x+iL*cos(phi)*cos(ori);
                yi=mtg->segs[i-1].y+iL*cos(phi)*sin(ori);
                zi=mtg->segs[i-1].z+iL*sin(phi);
                mtg->segs[i].x=xi;
                mtg->segs[i].y=yi;
                mtg->segs[i].z=zi;
                mtg->segs[i].ori=ori;
                mtg->segs[i].phi=phi;
                ori1=ori+mtg->segs[i].hpz;
                phi1=phi+mtg->segs[i].vpz;
                mtg->segs[i].ori1=ori1;
                mtg->segs[i].phi1=phi1;
                road_xy2l(&mtg->r,xi,yi,&li,0,0,0,&mtg->segs[i].dh);
                road_l2h(&mtg->r,li,&mtg->segs[i].dv,0);
                mtg->segs[i].dv=zi-mtg->segs[i].dv;
                if(mtg->prj.a2z==-1) mtg->segs[i].dh=-mtg->segs[i].dh;
                mtg->segs[i].mile=li;
                //trace(0,"%d,dh=%.4f,dv=%.4f\n",i,mtg->segs[i].dh,mtg->segs[i].dv);

                mtg->segs[i].dh1=mtg->segs[i].dh-mtg->segs[i].dh1;
                mtg->segs[i].dv1=mtg->segs[i].dv-mtg->segs[i].dv1;
                //trace(0,"%d,dh1=%.4f,dv1=%.4f\n",i,mtg->segs[i].dh1,mtg->segs[i].dv1);
                just=0;
            }
            else
            {
                l1=mtg->segs[i-1].headc;
                if(mtg->prj.a2z==1) l2=l1+iL*10.0;
                else l2=l1-iL*10.0;
                //trace(0,"%d,l1=%.4f,l2=%.4f\n",i,l1,l2);
                if(hc==0.0 && hc1==0.0 && hc2==0.0)
                {
                    r=mtg->spara.hmxr;
                    ori1=mtg->segs[i-1].tbmh;
                    //trace(0,"ori1=%.12f,ori=%.12f\n",ori1,mtg->m.inc1[2]*PI/180.0);
                    road_l2xy(&mtg->r,l2,&x2,&y2,&ori);
                    //trace(0,"ori=%.12f\n",ori);
                    beta=ori1-ori;
                    if(beta<-PI) beta+=2.0*PI;
                    else if(beta>PI) beta-=2.0*PI;
                    dh=mtg->segs[i-1].headh;
                    dh1=dh+iL*sin(beta);
                    //trace(0,"dh=%.4f,dh1=%.4f,beta=%.12f\n",dh,dh1,beta);
                    if(dh1<=-0.02 && dh1<dh)
                    {
                        hpz=0;
                        deta=-beta/2.0;
                        hz=ori1+deta;
                        c=2.0*r*sin(deta);
                        x1=mtg->segs[i-1].head[0]+c*cos(hz);
                        y1=mtg->segs[i-1].head[1]+c*sin(hz);
                        dx=x2-x1;
                        dy=y2-y1;
                        a=sqrt(dx*dx+dy*dy);
                        deta1=atan2(dy,dx);
                        if(deta1<0.0) deta1+=2.0*PI;
                        deta1=deta1-ori;
                        b=a*sin(deta1);
                        deta1=PI/2.0-deta1;

                        a=a/2.0;
                        c=sqrt(r*r+a*a-2*r*a*cos(deta1));
                        deta1=acos(r/c);
                        beta1=acos((r*r+c*c-a*a)/(2.0*r*c));
                        deta1=(beta1-deta1)/2.0;

                        hz=ori+deta1;
                        c=2.0*r*sin(deta1);
                        x1=x1+c*cos(hz);
                        y1=y1+c*sin(hz);

                        hz=hz+deta1;
                        lori=hz;
                        b=b-2.0*(r-r*cos(deta1*2.0));
                        c=b/sin(deta1*2.0);
                        x2=x1+c*cos(hz);
                        y2=y1+c*sin(hz);
                        road_xy2l(&mtg->r,x1,y1,&hc,0,0,0,0);
                        road_xy2l(&mtg->r,x2,y2,&hc1,0,0,0,0);
                        if(mtg->prj.a2z==1) hc2=hc1+r*sin(deta1*2.0);
                        else hc2=hc1-r*sin(deta1*2.0);
                        lx1=x1;
                        ly1=y1;
                        lx2=x2;
                        ly2=y2;
                    }
                    else if(dh1>=0.02 && dh1>dh)
                    {
                        hpz=1;
                        deta=beta/2.0;
                        hz=ori1-deta;
                        c=2.0*r*sin(deta);
                        x1=mtg->segs[i-1].head[0]+c*cos(hz);
                        y1=mtg->segs[i-1].head[1]+c*sin(hz);
                        dx=x2-x1;
                        dy=y2-y1;
                        a=sqrt(dx*dx+dy*dy);
                        deta1=atan2(dy,dx);
                        if(deta1<0.0) deta1+=2.0*PI;
                        deta1=ori-deta1;
                        b=a*sin(deta1);
                        deta1=PI/2.0-deta1;

                        a=a/2.0;
                        c=sqrt(r*r+a*a-2*r*a*cos(deta1));
                        deta1=acos(r/c);
                        beta1=acos((r*r+c*c-a*a)/(2.0*r*c));
                        deta1=(beta1-deta1)/2.0;

                        hz=ori-deta1;
                        c=2.0*r*sin(deta1);
                        x1=x1+c*cos(hz);
                        y1=y1+c*sin(hz);

                        hz=hz-deta1;
                        lori=hz;
                        b=b-2.0*(r-r*cos(deta1*2.0));
                        c=b/sin(deta1*2.0);
                        x2=x1+c*cos(hz);
                        y2=y1+c*sin(hz);
                        road_xy2l(&mtg->r,x1,y1,&hc,0,0,0,0);
                        road_xy2l(&mtg->r,x2,y2,&hc1,0,0,0,0);
                        if(mtg->prj.a2z==1) hc2=hc1+r*sin(deta1*2.0);
                        else hc2=hc1-r*sin(deta1*2.0);
                        lx1=x1;
                        ly1=y1;
                        lx2=x2;
                        ly2=y2;
                    }
                }

                if(vc==0.0 && vc1==0.0 && vc2==0.0)
                {
                    r=mtg->spara.vmxr;
                    phi1=mtg->segs[i-1].tbmv;
                    road_l2h(&mtg->r,l2,&z2,&phi);
                    deta=phi1-phi;
                    if(deta<-PI) deta+=2.0*PI;
                    else if(deta>PI) deta-=2.0*PI;
                    //if(i==22) trace(0,"phi1=%.12f,phi=%.12f\n",phi1,phi);
                    dv=mtg->segs[i-1].headv;
                    dv1=dv+iL*sin(deta);

                    if(dv1<=-0.02 && dv1<dv)
                    {
                        vpz=0;
                        beta=-deta;
                        //trace(0,"beta=%.12f\n",r*sin(beta));
                        a=r*sin(beta);
                        if(mtg->prj.a2z==1) x1=mtg->segs[i-1].headc+a*cos(phi);
                        else x1=mtg->segs[i-1].headc-a*cos(phi);
                        b=r-r*cos(beta);
                        a=a*sin(phi);
                        b=b*cos(phi);
                        y1=mtg->segs[i-1].head[2]+a-b;
                        x2=l2;
                        y2=z2;
                        //if(i==22) trace(0,"x0=%.4f,y0=%.4f,x1=%.4f,y1=%.4f,x2=%.4f,y2=%.4f\n",mtg->segs[i-1].headc,mtg->segs[i-1].head[2],x1,y1,x2,y2);
                        if(mtg->prj.a2z==1) dx=x2-x1;
                        else dx=x1-x2;
                        dy=y2-y1;
                        a=sqrt(dx*dx+dy*dy);
                        beta1=atan(dy/dx);
                        if(beta1<0.0) beta1+=2.0*PI;
                        //if(i==22) trace(0,"beta1:%.12f,phi:%.12f\n",beta1,phi);
                        beta1=beta1-phi;

                        b=a*cos(beta1);
                        beta1=PI/2.0-beta1;
                        //if(i==22) trace(0,"beta1:%.12f\n",beta1);
                        a=a/2.0;
                        c=sqrt(r*r+a*a-2.0*r*a*cos(beta1));
                        beta1=acos(r/c);
                        //if(i==22) trace(0,"beta1:%.12f\n",beta1);
                        deta1=acos((r*r+c*c-a*a)/(2.0*r*c));
                        if(i==22)
                        {
                            //trace(0,"deta1:%.12f\n",deta1);
                            //trace(0,"r=%.4f,a=%.4f,c=%.4f\n",r,a,c);
                        }
                        beta1=deta1-beta1;
                        lphi=phi+beta1;
                        //if(i==22) trace(0,"phi=%.12f,beta1=%.12f\n",phi,beta1);
                        if(mtg->prj.a2z==1)
                        {
                            vc=x1+r*sin(beta1);
                            vc1=vc+b-r*sin(beta1);
                            vc2=vc1+r*sin(beta1);
                        }
                        else
                        {
                            vc=x1-r*sin(beta1);
                            vc1=vc-b+r*sin(beta1);
                            vc2=vc1-r*sin(beta1);
                        }
                        lz1=y1+r-r*cos(beta1);
                        b=b-2.0*r*sin(beta1);
                        lz2=lz1+b*tan(beta1);
                    }
                    else if(dv1>=0.02 && dv1>dv)
                    {
                        vpz=1;
                        x1=mtg->segs[i-1].headc+r*sin(deta);
                        y1=mtg->segs[i-1].head[2]+r-r*cos(deta);
                        x2=l2;
                        y2=z2;
                        dx=x2-x1;
                        dy=y2-y1;
                        a=sqrt(dx*dx+dy*dy);
                        beta1=atan2(dy,dx);
                        if(beta1<0.0) beta1+=2.0*PI;
                        beta1=phi-beta1;
                        b=a*cos(beta1);
                        beta1=PI/2.0-beta1;

                        a=a/2.0;
                        c=sqrt(r*r+a*a-2*r*a*cos(beta1));
                        beta1=acos(r/c);
                        deta1=acos((r*r+c*c-a*a)/(2.0*r*c));
                        beta1=deta1-beta1;
                        lphi=phi-beta1;
                        if(mtg->prj.a2z==1)
                        {
                            vc=x1+r*sin(beta1);
                            vc1=vc+b-r*sin(beta1);
                            vc2=vc1+r*sin(beta1);
                        }
                        else
                        {
                            vc=x1+r*sin(beta1);
                            vc1=vc+b-r*sin(beta1);
                            vc2=vc1-r*sin(beta1);
                        }
                        lz1=y1-r+r*cos(beta1);
                        b=b-2.0*r*sin(beta1);
                        lz2=lz1-b*tan(beta1);
                    }
                }
                //trace(0,"vc=%.4f,vc1=%.4f,vc2=%.4f\n",vc,vc1,vc2);
                l1=mtg->segs[i-1].headc;
                r=mtg->spara.hmxr;
                if(mtg->prj.a2z==1) li=l1+iL;
                else li=l1-iL;

                if(li<=hc)
                {
                    if(hpz==0) ori=mtg->segs[i-1].tbmh+mtg->spara.mxhi;
                    else ori=mtg->segs[i-1].tbmh-mtg->spara.mxhi;
                    xi=mtg->segs[i-1].head[0]+iL*cos(ori);
                    yi=mtg->segs[i-1].head[1]+iL*sin(ori);
                }
                else if(li>hc && li<=hc1)
                {
                    len=li-hc;
                    xi=lx1+len*cos(lori);
                    yi=ly1+len*sin(lori);
                }
                else if(li>hc1 && li<=hc2)
                {
                    len=li-hc1;
                    hz=asin(len/2.0/r)*2.0;
                    if(hpz==0) ori=lori-hz;
                    else ori=lori+hz;
                    xi=lx2+len*cos(ori);
                    yi=ly2+len*sin(ori);
                }
                else if(hc==0.0 && hc1==0.0 && hc2==0.0)
                {
                    ori=mtg->segs[i-1].tbmh;
                    xi=mtg->segs[i-1].head[0]+iL*cos(ori);
                    yi=mtg->segs[i-1].head[1]+iL*sin(ori);
                }
                else
                {
                    road_l2xy(&mtg->r,li,&xi,&yi,0);
                    hc=hc1=hc2=0.0;
                }

                r=mtg->spara.vmxr;
                if(li<=vc)
                {
                    if(vpz==0) phi=mtg->segs[i-1].tbmv+mtg->spara.mxvi;
                    else phi=mtg->segs[i-1].tbmv-mtg->spara.mxvi;
                    zi=mtg->segs[i-1].head[2]+iL*sin(phi);
                }
                else if(li>vc && li<=vc1)
                {
                    len=li-vc;
                    zi=lz1+len*tan(lphi);
                }
                else if(li>vc1 && li<=vc2)
                {
                    len=li-vc1;
                    vz=asin(len/2.0/r)*2.0;
                    if(vpz==0) phi=lphi-vz;
                    else phi=lphi+vz;
                    zi=mtg->segs[i-1].head[2]+len*sin(phi);
                    //if(i==25)
                    //{
                        //trace(0,"zi=%.4f,z1=%.4f\n",zi,mtg->segs[i-1].head[2]);
                        //trace(0,"lphi=%.12f,vz=%.12f,phi=%.12f\n",lphi,vz,phi);
                    //}
                }
                else if(vc==0.0 && vc1==0.0 && vc2==0.0)
                {
                    phi=mtg->segs[i-1].tbmv;
                    zi=mtg->segs[i-1].head[2]+iL*sin(phi);
                }
                else
                {
                    road_l2h(&mtg->r,li,&zi,0);
                    phi=mtg->segs[i-1].tbmv;
                    vc=vc1=vc2=0.0;
                }

                mtg->segs[i].head[0]=xi;
                mtg->segs[i].head[1]=yi;
                mtg->segs[i].head[2]=zi;
                road_xy2l(&mtg->r,xi,yi,&li,0,0,0,&mtg->segs[i].headh);
                road_l2h(&mtg->r,li,&mtg->segs[i].headv,0);
                //trace(0,"l1=%.4f,l2=%.4f\n",li,mtg->segs[i-1].headc);
                if(mtg->prj.a2z==-1) mtg->segs[i].headh=-mtg->segs[i].headh;
                mtg->segs[i].headv=zi-mtg->segs[i].headv;
                mtg->segs[i].headc=li;

                //ori=mtg->segs[i-1].tbmh+PI;
                //phi=mtg->segs[i-1].tbmv+PI;
                x1=mtg->segs[i-1].tail[0]+iL*cos(phi)*cos(ori);
                y1=mtg->segs[i-1].tail[1]+iL*cos(phi)*sin(ori);
                z1=mtg->segs[i-1].tail[2]+iL*sin(phi);
                //if(i==25) trace(0,"tailzi=%.4f,tailz1=%.4f,phi=%.12f\n",z1,mtg->segs[i-1].tail[2],phi);
                mtg->segs[i].tail[0]=x1;
                mtg->segs[i].tail[1]=y1;
                mtg->segs[i].tail[2]=z1;
                road_xy2l(&mtg->r,x1,y1,&li,0,0,0,&mtg->segs[i].tailh);
                road_l2h(&mtg->r,li,&mtg->segs[i].tailv,0);
                if(mtg->prj.a2z==-1) mtg->segs[i].tailh=-mtg->segs[i].tailh;
                mtg->segs[i].tailv=z1-mtg->segs[i].tailv;

                dx=xi-x1;
                dy=yi-y1;
                dz=zi-z1;
                len=sqrt(dx*dx+dy*dy);
                //trace(0,"%d,zi=%.4f,z1=%.4f\n",i,zi,z1);
                ori=atan2(dy,dx);
                if(ori<0.0) ori+=2.0*PI;
                phi=atan(dz/len);
                if(phi<0.0) phi+=2.0*PI;
                mtg->segs[i].tbmh=ori;
                mtg->segs[i].tbmv=phi;
                x1=mtg->segs[i-1].x1+iL*cos(phi)*cos(ori);
                y1=mtg->segs[i-1].y1+iL*cos(phi)*sin(ori);
                z1=mtg->segs[i-1].z1+iL*sin(phi);
                //trace(0,"%d,z1=%.4f,z2=%.4f,iL=%.4f,phi=%.12f\n",i,z1,mtg->segs[i-1].z1,iL,phi);
                mtg->segs[i].x1=x1;
                mtg->segs[i].y1=y1;
                mtg->segs[i].z1=z1;
                road_xy2l(&mtg->r,x1,y1,&li,0,0,0,&mtg->segs[i].dh1);
                road_l2h(&mtg->r,li,&mtg->segs[i].dv1,0);
                if(mtg->prj.a2z==-1) mtg->segs[i].dh1=-mtg->segs[i].dh1;
                mtg->segs[i].dv1=z1-mtg->segs[i].dv1;

                ori=mtg->segs[i-1].ori1;
                phi=mtg->segs[i-1].phi1;

                xi=mtg->segs[i-1].x+iL*cos(phi)*cos(ori);
                yi=mtg->segs[i-1].y+iL*cos(phi)*sin(ori);
                zi=mtg->segs[i-1].z+iL*sin(phi);

                road_xy2l(&mtg->r,xi,yi,&li,0,0,0,&dh1);
                road_l2h(&mtg->r,li,&dv1,0);
                dv1=zi-dv1;
                if(mtg->prj.a2z==-1) dh1=-dh1;
                road_xy2l(&mtg->r,x1,y1,&li,0,0,0,&dh);
                road_l2h(&mtg->r,li,&dv,0);
                if(mtg->prj.a2z==-1) dh=-dh;
                dv=z1-dv;
                dh1=dh1-dh;
                dh=mtg->segs[i-1].dh1;
                dv1=dv1-dv;
                dv=mtg->segs[i-1].dv1;

                //if(i==25) trace(0,"%d,%d,dv=%.4f,dv1=%.4f,gap=%.4f\n",i,mtg->segs[i].numb,dv,dv1,gap*0.8);
                mtg->segs[i].k1=mtg->segs[i-1].k;
                mtg_get_kpos(mtg,&mtg->segs[i]);
                if(dh1<=-gap*0.8 && dh1<=dh)
                {
                    mtg->segs[i].type=3;
                    dv1=atan((dv1-dv)/iL);
                    if(dv1<-mtg->spara.mxvi && dv<-0.02)
                    {
                        if(mtg->segs[i].ipos[k-2]==0) mtg->segs[i].k=k-2;
                        else mtg->segs[i].k=k-1;
                    }
                    else if(dv1>mtg->spara.mxvi && dv<-0.02)
                    {
                        if(mtg->segs[i].ipos[1]==0) mtg->segs[i].k=1;
                        else mtg->segs[i].k=0;
                    }
                    else
                    {
                        dv=dv1-dv;
                        dv1=atan(dv/iL);
                        if(dv1<=-mtg->spara.mxvi)
                        {
                            if(mtg->segs[i].ipos[k-2]==0) mtg->segs[i].k=k-2;
                            else mtg->segs[i].k=k-1;
                        }
                        else if(dv1>=mtg->spara.mxvi)
                        {
                            if(mtg->segs[i].ipos[1]==0) mtg->segs[i].k=1;
                            else mtg->segs[i].k=0;
                        }
                        else
                        {
                            if(mtg->segs[i].ipos[0]==0) mtg->segs[i].k=0;
                            else mtg->segs[i].k=k-1;
                        }
                    }
                }
                else if(dh1>=gap*0.8 && dh1>=dh)
                {
                    mtg->segs[i].type=2;
                    dv1=atan((dv1-dv)/iL);
                    if(dv1<=-mtg->spara.mxvi && dv<=-0.02)
                    {
                        if(mtg->segs[i].ipos[1]==0) mtg->segs[i].k=1;
                        else mtg->segs[i].k=0;
                    }
                    else if(dv1>=mtg->spara.mxvi && dv>=0.02)
                    {
                        if(mtg->segs[i].ipos[k-2]==0) mtg->segs[i].k=k-2;
                        else mtg->segs[i].k=k-1;
                    }
                    else
                    {
                        dv1=atan((dv1-dv)/iL);
                        if(dv1<=-mtg->spara.mxvi && dv<-0.02)
                        {
                            if(mtg->segs[i].ipos[1]==0) mtg->segs[i].k=1;
                            else mtg->segs[i].k=0;
                        }
                        else if(dv1>=mtg->spara.mxvi && dv>0.02)
                        {
                            if(mtg->segs[i].ipos[k-2]==0) mtg->segs[i].k=k-2;
                            else mtg->segs[i].k=k-1;
                        }
                        else
                        {
                            if(mtg->segs[i].ipos[0]==0) mtg->segs[i].k=0;
                            else mtg->segs[i].k=k-1;
                        }
                    }
                }
                else if(dv1<=-gap*0.8 && dv1<=dv)
                {
                    dh1=atan((dh1-dh)/iL);
                    if(dh1<=-mtg->spara.mxhi && dh<-0.02)
                    {
                        mtg->segs[i].type=3;
                        if(mtg->segs[i].ipos[j+k/2+1]==0) mtg->segs[i].k=j+k/2+1;
                        else mtg->segs[i].k=j+k/2+2;
                    }
                    else if(dh1>mtg->spara.mxhi && dh>0.02)
                    {
                        mtg->segs[i].type=2;
                        if(mtg->segs[i].ipos[j-1]==0) mtg->segs[i].k=j-1;
                        else mtg->segs[i].k=j-2;
                    }
                    else
                    {
                        if(mtg->segs[i].ipos[j]==0)
                        {
                            mtg->segs[i].k=j;
                            mtg->segs[i].type=2;
                        }
                        else
                        {
                            mtg->segs[i].k=j+k/2;
                            mtg->segs[i].type=3;
                        }
                    }
                }
                else if(dv1>=gap*0.8 && dv1>=dv)
                {
                    dh1=atan((dh1-dh)/iL);
                    if(dh1<=-mtg->spara.mxhi && dh<-0.02)
                    {
                        mtg->segs[i].type=2;
                        if(mtg->segs[i].ipos[j+k/2+1]==0) mtg->segs[i].k=j+k/2+1;
                        else mtg->segs[i].k=j+k/2+2;
                    }
                    else if(dh1>mtg->spara.mxhi && dh>0.02)
                    {
                        mtg->segs[i].type=2;
                        if(mtg->segs[i].ipos[j-1]==0) mtg->segs[i].k=j-1;
                        else mtg->segs[i].k=j-2;
                    }
                    else
                    {
                        if(mtg->segs[i].ipos[j]==0)
                        {
                            mtg->segs[i].k=j;
                            mtg->segs[i].type=3;
                        }
                        else
                        {
                            mtg->segs[i].k=j+k/2;
                            mtg->segs[i].type=2;
                        }
                    }
                }
                else
                {
                    dh1=dh1+dh1-dh;
                    dv1=dv1+dv1-dv;
                    //if(i==25) trace(0,"%d,dv=%.4f,dv1=%.4f,gap=%.4f\n",i,dv,dv1,gap*0.8);
                    if(dh1<=-gap*0.8)
                    {
                        mtg->segs[i].type=3;
                        if(mtg->segs[i].ipos[0]==0) mtg->segs[i].k=0;
                        else mtg->segs[i].k=k-1;
                    }
                    else if(dh1>=gap*0.8)
                    {
                        mtg->segs[i].type=2;
                        if(mtg->segs[i].ipos[0]==0) mtg->segs[i].k=0;
                        else mtg->segs[i].k=k-1;
                    }
                    else if(dv1<=-gap*0.8)
                    {
                        if(mtg->segs[i].ipos[j]==0)
                        {
                            mtg->segs[i].k=j;
                            //trace(0,"%d,dv=%.4f,dv1=%.4f,gap=%.4f\n",i,dv,dv1,gap*0.8);
                            mtg->segs[i].type=2;
                        }
                        else
                        {
                            mtg->segs[i].k=j+k/2;
                            mtg->segs[i].type=3;
                        }
                    }
                    else if(dv1>=gap*0.8)
                    {
                        if(mtg->segs[i].ipos[j]==0)
                        {
                            mtg->segs[i].k=j;
                            mtg->segs[i].type=3;
                        }
                        else
                        {
                            mtg->segs[i].k=j+k/2;
                            mtg->segs[i].type=2;
                        }
                    }
                    else
                    {
                        mtg->segs[i].type=1;
                        if(mtg->segs[i].ipos[0]==0) mtg->segs[i].k=0;
                        else mtg->segs[i].k=k-1;
                    }
                }

                mtg_seg_parameters(mtg,&mtg->segs[i]);
                ori=mtg->segs[i-1].ori1+mtg->segs[i].hpz;
                phi=mtg->segs[i-1].phi1+mtg->segs[i].vpz;
                //if(i==25) trace(0,"%d,vpz=%.12f\n",i,mtg->segs[i].vpz);
                xi=mtg->segs[i-1].x+iL*cos(phi)*cos(ori);
                yi=mtg->segs[i-1].y+iL*cos(phi)*sin(ori);
                zi=mtg->segs[i-1].z+iL*sin(phi);
                mtg->segs[i].x=xi;
                mtg->segs[i].y=yi;
                mtg->segs[i].z=zi;
                mtg->segs[i].ori=ori;
                mtg->segs[i].phi=phi;
                ori1=ori+mtg->segs[i].hpz;
                phi1=phi+mtg->segs[i].vpz;

                mtg->segs[i].ori1=ori1;
                mtg->segs[i].phi1=phi1;
                road_xy2l(&mtg->r,xi,yi,&li,0,0,&ori,&mtg->segs[i].dh);
                //if(i==11) trace(0,"%.4f,%.4f,%.4f,%.4f\n",mtg->segs[10].mile,mtg->segs[10].x,mtg->segs[10].y,mtg->segs[10].z);
                road_l2h(&mtg->r,li,&mtg->segs[i].dv,&phi);
                mtg->segs[i].dv=zi-mtg->segs[i].dv;
                if(mtg->prj.a2z==-1)
                {
                    mtg->segs[i].dh=-mtg->segs[i].dh;
                    ori+=PI;
                    phi+=PI;
                    if(ori>2.0*PI) ori-=2.0*PI;
                    if(phi>2.0*PI) phi-=2.0*PI;
                }
                mtg->segs[i].mile=li;
                mtg->segs[i].dh1=mtg->segs[i].dh-mtg->segs[i].dh1;
                mtg->segs[i].dv1=mtg->segs[i].dv-mtg->segs[i].dv1;
                mtg->segs[i].desh=ori;
                mtg->segs[i].desv=phi;
            }

            beta=mtg->segs[i].desh-mtg->segs[i].ori1;
            deta=mtg->segs[i].desv-mtg->segs[i].phi1;
            if(beta<-PI) beta+=2.0*PI;
            else if(beta>PI) beta-=2.0*PI;
            if(deta<-PI) deta+=2.0*PI;
            else if(deta>PI) deta-=2.0*PI;

            b=mtg->segset.De;
            mtg->segs[i].harc=-b*sin(beta);
            mtg->segs[i].varc=-b*sin(deta);

            i++;
        }
    }

    return 0;
}

///判断盾构是否掘进
extern int mtg_is_driving(mtg_t* mtg,double aor)
{
    int i,j;
    double ival;
    if(mtg->naor<5)
    {
        mtg->aor[mtg->naor]=aor;
        mtg->naor++;
    }
    else
    {
        for(i=0;i<4;i++)
        {
            mtg->aor[i]=mtg->aor[i+1];
        }
        mtg->aor[4]=aor;
    }

    ///判断是否处在掘进状态中
    i=mtg->naor-1;
    ival=0;
    while(i>0)
    {
        ival=ival+mtg->aor[i]-mtg->aor[i-1];
        i--;
    }
    if(ival>0.01) mtg->idrv=-1;
    else if(ival<-0.01) mtg->idrv=1;
    else mtg->idrv=0;
    //trace(0,"idrive:%d,%.4f,%.4f\n",mtg->idrv,ival,aor);
    return 0;
}

///设计排版标准环+转弯环
extern int mtg_std_segings(mtg_t* mtg,MTG_SEG** res)
{
    int k=mtg->segset.Ks;
    int i,j,n;
    double iL=mtg->segset.L;
    double l1,l2;
    double x1,y1,z1;
    double ori,phi;
    double li,xi,yi,zi;
    double beta,deta;
    double mxh,mxv,ival;
    int mxi;
    double De,dh,dv;
    double a,b,c,c1;
    double harc,varc;
    MTG_SEG iseg;
    int index;
    //int nh;

    MTG_SEG* segs=0;

    if(mtg->prj.a2z==1) l1=mtg->iseg.headc-iL;
    else l1=mtg->iseg.headc+iL;
    l2=mtg->prj.mile2;
    n=fabs(l2-l1)/iL+1;

    segs=(MTG_SEG*)malloc(n*sizeof(MTG_SEG));
    for(i=0;i<n;i++)
    {
        segs[i].ipos=(int*)malloc(k*sizeof(int));
    }

    De=mtg->segset.De;
    iseg=mtg->iseg;
    iseg.type=2;
    mxh=mtg->spara.mxh;
    mxv=mtg->spara.mxv;
    mxi=mtg->spara.mxi;

    //trace(0,"mxh=%.4f,mxv=%.4f\n",mxh,mxv);
    road_l2xy(&mtg->r,l1,&x1,&y1,&ori);
    road_l2h(&mtg->r,l1,&z1,&phi);
    if(mtg->prj.a2z==-1)
    {
        ori+=PI;
        if(ori>2.0*PI) ori-=2.0*PI;
        phi+=PI;
        if(phi>2.0*PI) phi-=2.0*PI;
    }
    index=0;
    i=0;
    segs[0]=mtg->iseg;
    //trace(0,"type=%d,k=%d\n",segs[0].type,segs[0].k);
    mtg->sneed[0]=0;
    mtg->sneed[1]=0;
    mtg->sneed[2]=0;
    while(i<n)
    {
        if(mtg->prj.a2z==1) li=l1+iL*(i+1);
        else li=l1-iL*(i+1);
        road_l2xy(&mtg->r,li,&xi,&yi,0);
        road_l2h(&mtg->r,li,&zi,0);
        road_horizon_chain(&mtg->r,li,&index);
        beta=atan2(yi-y1,xi-x1);
        if(beta<0.0) beta+=2.0*PI;
        deta=beta-ori;
        dh=iL*sin(deta);

        beta=asin((zi-z1)/iL);
        if(beta<0.0) beta+=2.0*PI;
        deta=beta-phi;
        dv=iL*sin(deta);

        //trace(0,"i=%d,dh=%.4f,dv=%.4f\n",i,dh,dv);
        if(dh<=-mxh && fabs(dh)>fabs(dv)/2.0)
        {
            segs[i].type=2;
            mtg->sneed[1]++;
            if(i>0)
            {
                segs[i].k1=segs[i-1].k;
                mtg_get_kpos(mtg,&segs[i]);
                if(dv<=-mxv)
                {
                    if(segs[i].ipos[k-2]==0) segs[i].k=k-2;
                    else if(segs[i].ipos[k-1]==0) segs[i].k=k-1;
                }
                else if(dv>=mxv)
                {
                    if(segs[i].ipos[1]==0) segs[i].k=1;
                    else if(segs[i].ipos[0]==0) segs[i].k=0;
                }
                else
                {
                    if(segs[i].ipos[0]==0) segs[i].k=0;
                    else if(segs[i].ipos[k-1]==0) segs[i].k=k-1;
                }
            }
        }
        else if(dh>=mxh && fabs(dh)>fabs(dv)/2.0)
        {
            segs[i].type=3;
            mtg->sneed[2]++;
            if(i>0)
            {
                segs[i].k1=segs[i-1].k;
                mtg_get_kpos(mtg,&segs[i]);
                if(dv<=-mxv)
                {
                    if(segs[i].ipos[1]==0) segs[i].k=1;
                    else if(segs[i].ipos[0]==0) segs[i].k=0;
                }
                else if(dv>=mxv)
                {
                    if(segs[i].ipos[k-2]==0) segs[i].k=k-2;
                    else if(segs[i].ipos[k-1]==0) segs[i].k=k-1;
                }
                else
                {
                    if(segs[i].ipos[0]==0) segs[i].k=0;
                    else if(segs[i].ipos[k-1]==0) segs[i].k=k-1;
                }
            }
        }
        else if(dv<=-mxv)
        {
            if(i>0)
            {
                segs[i].k1=segs[i-1].k;
                mtg_get_kpos(mtg,&segs[i]);
                if(segs[i].ipos[mxi]==0)
                {
                    segs[i].k=mxi;
                    segs[i].type=3;
                    mtg->sneed[2]++;
                }
                else if(segs[i].ipos[mxi+k/2]==0)
                {
                    segs[i].k=mxi+k/2;
                    segs[i].type=2;
                    mtg->sneed[1]++;
                }
            }
        }
        else if(dv>=mxv)
        {
            if(i>0)
            {
                segs[i].k1=segs[i-1].k;
                mtg_get_kpos(mtg,&segs[i]);
                if(segs[i].ipos[mxi]==0)
                {
                    segs[i].k=mxi;
                    segs[i].type=2;
                    mtg->sneed[1]++;
                }
                else if(segs[i].ipos[mxi+k/2]==0)
                {
                    segs[i].k=mxi+k/2;
                    segs[i].type=3;
                    mtg->sneed[2]++;
                }
            }
        }
        else
        {
            if(i==0)
            {
                if(segs[i].type==1) mtg->sneed[0]++;
                else if(segs[i].type==2) mtg->sneed[1]++;
                else if(segs[i].type==3) mtg->sneed[2]++;
            }
            else
            {
                segs[i].type=1;
                mtg->sneed[0]++;
                if(i>0)
                {
                    segs[i].k1=segs[i-1].k;
                    mtg_get_kpos(mtg,&segs[i]);
                    if(segs[i].ipos[0]==0) segs[i].k=0;
                    else if(segs[i].ipos[k-1]==0) segs[i].k=k-1;
                }
            }
        }

        mtg_seg_parameters(mtg,&segs[i]);

        if(i==0)
        {
            segs[i].headc=li;
            x1=xi;
            y1=yi;
            z1=zi;
            segs[i].head[0]=xi;
            segs[i].head[1]=yi;
            segs[i].head[2]=zi;
            ori=ori+segs[i].hpz;
            phi=phi+segs[i].vpz;
            segs[i].ori=ori;
            segs[i].phi=phi;
            ori=ori+segs[i].hpz;
            phi=phi+segs[i].vpz;
            segs[i].ori1=ori;
            segs[i].phi1=phi;
        }
        else
        {
            ori=ori+segs[i].hpz;
            phi=phi+segs[i].vpz;
            //trace(0,"i=%d,ori=%.12f,phi=%.12f\n",i,ori,phi);
            x1=segs[i-1].head[0]+iL*cos(phi)*cos(ori);
            y1=segs[i-1].head[1]+iL*cos(phi)*sin(ori);
            z1=segs[i-1].head[2]+iL*sin(phi);
            segs[i].headc=li;
            segs[i].head[0]=x1;
            segs[i].head[1]=y1;
            segs[i].head[2]=z1;
            segs[i].ori=ori;
            segs[i].phi=phi;
            ori=ori+segs[i].hpz;
            phi=phi+segs[i].vpz;
            segs[i].ori1=ori;
            segs[i].phi1=phi;
            segs[i].numb=segs[i-1].numb+1;
        }

        road_xy2l(&mtg->r,x1,y1,&li,0,0,&beta,&dh);
        if(mtg->prj.a2z==-1)
        {
            dh=-dh;
            beta=beta+PI;
            if(beta>2,0*PI) beta-=2.0*PI;
        }
        deta=beta-ori;
        harc=De*sin(deta);

        segs[i].harc=-harc;
        road_l2h(&mtg->r,li,&dv,&beta);
        if(mtg->prj.a2z==-1)
        {
            beta=beta+PI;
            if(beta>2,0*PI) beta-=2.0*PI;
        }
        dv=z1-dv;
        deta=beta-phi;
        varc=De*sin(deta);
        segs[i].varc=varc;

        segs[i].headh=dh;
        segs[i].headv=dv;


        //trace(0,"i=%d,dh=%.4f,dv=%.4f\n",i,dh,dv);
        //trace(0,"index=%d,l=%d,r=%d,std=%d\n",index,mtg->sset[index].lpz,mtg->sset[index].rpz,mtg->sset[index].std);
        i++;
    }
    *res=segs;
    //trace(0,"type=%d,k=%d\n",segs[0].type,segs[0].k);
    //trace(0,"index=%d\n",index);
    return n;
}
