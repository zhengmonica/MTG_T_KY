#include "CircleFit.h"
#include "geometry.h"
#include <math.h>

#define PI 3.1415926


CCircleFit::CCircleFit()
{
    fit = false;
    //ctor
}

CCircleFit::~CCircleFit()
{
    //dtor
}

bool CCircleFit::AddData(double x, double y, double z, bool used)
{
    CCircleData Cdata;
    Cdata.x=x;
    Cdata.y=y;
    Cdata.z=z;
    Cdata.used=used;
    data.push_back(Cdata);
    return true;
}

bool CCircleFit::ModifyData(int id, double x, double y, double z)
{
    if (id>=0 && id<data.size())
    {
        data[id].x=x;
        data[id].y=y;
        data[id].z=z;
        return true;
    }
    return false;
}

bool CCircleFit::RemoveData(int id)
{
    if (id>=0 && id<data.size())
    {
        data.erase(data.begin()+id);
        return true;
    }
    return false;
}

bool CCircleFit::UseData(int id, bool used)
{
    if (id>=0 && id<data.size())
    {
        data[id].used=used;
        return true;
    }
    return false;
}

typedef struct pointpair
{
    int n1;
    int n2;
    double dist2;
}pointpair;

bool CCircleFit::Solv()
{
    /*#ifdef WEBPC
    IO_PACKAGE pack={0};
    time_t t1,t2,ts,tf;

    ///加密
    pack.tag=CMD_GET_TIME;
    time(&t1);

    if(DoSense("MEDO002","TunnelWizard",&pack,&pack)==1)
    {

        memcpy(&t2,pack.buff,4);
        memcpy(&ts,pack.buff+4,4);
        memcpy(&tf,pack.buff+8,4);

        if(abs(t2-t1)>24*3600) return false;
        if(t2-ts>=tf) return false;
    }
    else
    {
        return false;
    }

#endif*/
    int n=data.size();
    if(n<3) return false;
    int i,j=0;

    double mp,mc;
    point3d_t* pts=(point3d_t*)malloc(n*sizeof(point3d_t));
    for(i=0; i<n&&j<n; i++)
    {
        if(!data[i].used)continue;
        pts[j].x=data[i].x;
        pts[j].y=data[i].y;
        pts[j].z=data[i].z;
        j++;
    }
    if(j<3)
    {
        free(pts);
        fit=false;
        return false;
    }
    circle3d_t cir;
    cir.r = 0;

    double *pout=(double*)malloc((4+2*j)*sizeof(double));
    if(!circle3d_init_points(&cir,j,pts,pout))
    {
        free(pts);
        free(pout);
        return false;
    }
    center[0]=cir.x;
    center[1]=cir.y;
    center[2]=cir.z;
    radius =cir.r;
    normal[0]=pout[0];
    normal[1]=pout[1];
    normal[2]=pout[2];
    vector3d_t t;
    t.x = pout[0];
    t.y = pout[1];
    t.z = pout[2];
    vector3d_normal(&t);
    normal[0]=t.x;
    normal[1]=t.y;
    normal[2]=t.z;
//    double normal_length = sqrt(normal[0]*normal[0]+normal[1]*normal[1]+normal[2]*normal[2]);
//    int sides[4]; //0-up,1-down,2-left,3-right,记录四个边界点的序号
//    double Vmax,Vmin,Hleft,Hright;
//    Vmax=Vmin=Hleft=Hright=0.0;
//    for(i=0; i<n; i++)
//    {
//        if(!data[i].used)continue;
//        if (data[i].z>Vmax)
//        {
//            Vmax = data[i].z;
//            sides[0] = i;
//        }
//        if (data[i].z<Vmin)
//        {
//            Vmin = data[i].z;
//            sides[1] = i;
//        }
//        if (sqrt((data[i].x-center[0])*(data[i].x-center[0])+(data[i].y-center[1])*(data[i].y-center[1]))>Hleft)
//        {
//            Hleft = sqrt((data[i].x-center[0])*(data[i].x-center[0])+(data[i].y-center[1])*(data[i].y-center[1]));
//            sides[2] = i;
//        }
//    }
//    for(i=0; i<n; i++)
//    {
//        if(!data[i].used || i=sides[2])continue;
//        if (sqrt((data[i].x-data[sides[2]].x)*(data[i].x-data[sides[2]].x)+(data[i].y-data[sides[2]].y)*(data[i].y-data[sides[2]].y))>Hright)
//        {
//            Hright = sqrt((data[i].x-data[sides[2]].x)*(data[i].x-data[sides[2]].x)+(data[i].y-data[sides[2]].y)*(data[i].y-data[sides[2]].y));
//            sides[3] = i;
//        }
//    }
//    double fuyang,pianzhuan;
//    fuyang = atan((data[sides[0]].z-data[sides[1]].z)/sqrt((data[sides[0]].x-data[sides[1]].x)*(data[sides[0]].x-data[sides[1]].x)+(data[sides[0]].y-data[sides[1]].y)*(data[sides[0]].y-data[sides[1]].y)))-PI/2;
//    pianzhuan = atan2(data[sides[2]].y-data[sides[3]].y,data[sides[2]].x-data[sides[3]].x)+PI/2;

    j=0;
    mp=mc=0.0;
    for(i=0; i<n&&j<n; i++)
    {
        if(!data[i].used)continue;
        data[i].dc=pout[4+2*j+1];       ///圆度
        data[i].dp=pout[4+2*j];         ///平面度
        mc += pout[4+2*j+1]*pout[4+2*j+1];
        mp += pout[4+2*j]*pout[4+2*j];
        j++;
    }
    dplane = sqrt(mp/j);
    dcircle = sqrt(mc/j);

    ///直接法求法向量
    transform3d_t trans;
    double pitch=atan(normal[2]/(sqrt((normal[0]*normal[0]+normal[1]*normal[1]))));
    double azimuth=atan2(normal[1],normal[0]);
    transform3d_init(&trans,0.0,pitch,-azimuth,center[0],center[1],center[2],1);
    for(i=0; i<n; i++)
    {
        pts[i].x=data[i].x;
        pts[i].y=data[i].y;
        pts[i].z=data[i].z;
        if(!data[i].used)continue;
        transform3d_revtrans(&trans,&pts[i],&pts[i]);
        //j++;
    }

    vector<pointpair> pairsv,pairsh;
    for(i=0;i<n;i++)
    {
        if(!data[i].used) continue;
        for(j=i+1;j<n;j++)
        {
            if(!data[j].used) continue;
            if(fabs(pts[i].z-pts[j].z)<0.2)
            {
                pointpair p;
                p.n1=i;
                p.n2=j;
                p.dist2=(pts[i].y-pts[j].y)*(pts[i].y-pts[j].y)+(pts[i].z-pts[j].z)*(pts[i].z-pts[j].z);
                pairsh.push_back(p);
            }
            else if(fabs(pts[i].y-pts[j].y)<0.2)
            {
                pointpair p;
                p.n1=i;
                p.n2=j;
                p.dist2=(pts[i].y-pts[j].y)*(pts[i].y-pts[j].y)+(pts[i].z-pts[j].z)*(pts[i].z-pts[j].z);
                pairsv.push_back(p);
            }
        }
    }
    int n1=-1,n2=-1,n3=-1,n4=-1;
    double maxd=0.0;
    for(i=0;i<pairsh.size();i++)
    {
        if(pairsh[i].dist2>maxd)
        {
            n1=pairsh[i].n1;
            n2=pairsh[i].n2;
            maxd=pairsh[i].dist2;
        }
    }
    maxd=0.0;
    for(i=0;i<pairsv.size();i++)
    {
        if(pairsv[i].dist2>maxd)
        {
            n3=pairsv[i].n1;
            n4=pairsv[i].n2;
            maxd=pairsv[i].dist2;
        }
    }
    if(n1>=0 && n2>=0 && n3>=0 && n4>=0)
    {
        ///n1在左，n2在右
        if(pts[n2].y<pts[n1].y)
        {
            n=n1;
            n1=n2;
            n2=n;
        }
        /// n3在下,n4在上
        if(pts[n4].z<pts[n3].z)
        {
            n=n3;
            n3=n4;
            n4=n;
        }
        pitch=atan(sqrt((data[n3].x-data[n4].x)*(data[n3].x-data[n4].x)+(data[n3].y-data[n4].y)*(data[n3].y-data[n4].y))/(data[n3].z-data[n4].z));
        if(pts[n3].x>pts[n4].x) pitch*=-1.0;
        azimuth=atan2(data[n2].y-data[n1].y,data[n2].x-data[n1].x)+PI/2;
        normal1[0]=cos(pitch)*cos(azimuth);
        normal1[1]=cos(pitch)*sin(azimuth);
        normal1[2]=sin(pitch);
    }
    else
    {
        normal1[0]=normal1[1]=normal1[2]=0.0;
    }
    free(pts);
    free(pout);
    fit=true;
    return true;
}

