#include "libmtg.h"
#include "geometry.h"
#include "libele.h"
#include "trace.h"

#define PI 3.1415926

int gaps_init(mtg_t* mtg)
{
    strcpy(mtg->gaps.IP,"192.168.0.113");
    mtg->gaps.port=5300;
    strsvrinit(&mtg->gaps.svr);
    mtg->gaps.opera=DIST_CMD_NONE;
    mtg->gaps.d1=2.4;
    mtg->gaps.radius=6.34;
    mtg->gaps.ujust=0.0;
    mtg->gaps.djust=0.0;
    mtg->gaps.ljust=0.0;
    mtg->gaps.rjust=0.0;
    mtg->gaps.ugap=0.0;
    mtg->gaps.dgap=0.0;
    mtg->gaps.lgap=0.0;
    mtg->gaps.rgap=0.0;
    mtg->gaps.ugap1=0.0;
    mtg->gaps.dgap1=0.0;
    mtg->gaps.lgap1=0.0;
    mtg->gaps.rgap1=0.0;
    mtg->gaps.t=0;
    mtg->igs=0;

    mtg->dister[0].id=0x81;
    mtg->dister[1].id=0x82;
    mtg->dister[2].id=0x83;
    mtg->dister[3].id=0x84;
    mtg->dister[4].id=0x85;

    mtg->dister[0].angle=PI*3.0/2.0;
    mtg->dister[1].angle=0.0;
    mtg->dister[2].angle=PI*1.0/6.0;
    mtg->dister[3].angle=PI*5.0/6.0;
    mtg->dister[4].angle=PI;

    mtg->dister[0].dist0=0.0;
    mtg->dister[1].dist0=0.0;
    mtg->dister[2].dist0=0.0;
    mtg->dister[3].dist0=0.0;
    mtg->dister[4].dist0=0.0;

    mtg->dister[0].dist=0.0;
    mtg->dister[1].dist=0.0;
    mtg->dister[2].dist=0.0;
    mtg->dister[3].dist=0.0;
    mtg->dister[4].dist=0.0;

    mtg->dister[0].dist1=0.0;
    mtg->dister[1].dist1=0.0;
    mtg->dister[2].dist1=0.0;
    mtg->dister[3].dist1=0.0;
    mtg->dister[4].dist1=0.0;

    mtg->dister[0].sel=0;
    mtg->dister[1].sel=0;
    mtg->dister[2].sel=0;
    mtg->dister[3].sel=0;
    mtg->dister[4].sel=0;

    mtg->dister[0].isok=1;
    mtg->dister[1].isok=1;
    mtg->dister[2].isok=1;
    mtg->dister[3].isok=1;
    mtg->dister[4].isok=1;
    mtg->gaps.done=0;
    return 0;
}

void meas_dist(unsigned char* buff,int ID)
{
    int i=0;
    buff[0]=0x68;
    buff[1]=0x01;
    buff[2]=(unsigned char)ID;
    buff[3]=0x47;
    buff[4]=0x00;
    buff[5]=0;
	for(i=1;i<=4;i++)
        buff[5]+=(unsigned char)buff[i];
	buff[5]=(unsigned char)buff[5];
    buff[6]=0x16;
    buff[7]=0x00;
    trace(0,"meas_dist:%0x,%0x,%0x,%0x,%0x,%0x,%0x\n",buff[0],buff[1],buff[2],buff[3],buff[4],buff[5],buff[6]);
}

void read_dist(unsigned char* buff,int ID)
{
    int i=0;
    buff[0]=0x68;
    buff[1]=0x00;
    buff[2]=(unsigned char)ID;
    buff[3]=0x06;
    buff[4]=0;
    for(i=1;i<=3;i++)
        buff[4]+=(unsigned char)buff[i];
    buff[4]=(unsigned char)buff[4];

    buff[5]=0x16;
    buff[6]=0x00;
}

static DWORD WINAPI _disterthread(void *arg)
{
    int opts[5]={60000,1000,100,4096,100};
    char path[260];
    mtg_t* mtg;
    int len=0;
    //char buff[1024]={0};
    unsigned char buff[260]={0};
    unsigned char buff_rt[260]={0};
	char buff_print[1024]={0};
	char buf_ll[5]={0};
    int tick=0;
    unsigned char sum=0;
    int ret=0;
    int nret=0;
    int i,j,k;
    double ds=0.0;

    MTG_GAPS* gs;
    mtg=(mtg_t*)arg;
    gs=&mtg->gaps;

    if(!gs->svr.state)
    {
        sprintf(path,"%s:%d",gs->IP,gs->port);
        gs->svr.state=strsvrstart(&gs->svr,opts,STR_TCPCLI,path);
        trace(0,"distconn:01:path=%s\n",path);
    }
    trace(0,"distconn:gs.state=%d\n",gs->svr.state);

    if(gs->svr.state)
    {
        if(gs->opera==DIST_CMD_NONE)
            mtg_log(mtg,MTG_LOG_BEGIN_DIST_CONNECT);
        else if(gs->opera==DIST_CMD_TBM)
            mtg_log(mtg,MTG_LOG_BEGIN_DIST_TBM);
        else if(gs->opera==DIST_CMD_SEG)
            mtg_log(mtg,MTG_LOG_BEGIN_DIST_SEG);
        trace(0,"distconn:02\n");
        nret=0;
        for(i=0;i<5;i++)
        {
            if(mtg->dister[i].sel==1) continue;
            meas_dist(buff,mtg->dister[i].id);
            trace(0,"distconn:%d,%0x,%0x,%0x,%0x,%0x,%0x,%0x\n",i,buff[0],buff[1],buff[2],buff[3],buff[4],buff[5],buff[6]);
            if(strsvrput(&gs->svr,(unsigned char*)buff,7))
            {
                sleepms(500);
                trace(0,"distconn:%d,3\n",i);
                read_dist(buff,mtg->dister[i].id);
                tick=tickget();
                ret=0;
                while(tickget()-tick<4000)
                {
                    if(strsvrput(&gs->svr,(unsigned char*)buff,6))
                    {
                        sleepms(100);
                        len+=strsvrpeek(&gs->svr,(unsigned char*)(buff_rt+len),259-len);
                        buff_rt[len]=0;
                        for(j=0;j<len;j++)
                        {
                            //trace(0,"distconn:4,%d,%0x\n",len,buff_rt[j+9]);
                            if((unsigned char)buff_rt[j]==0x68&&(unsigned char)buff_rt[j+9]==0x16)
                            {
                                trace(0,"distconn:5,%d\n",i);
                                sum=0;
                                for(k=1;k<=7;k++)
                                {
                                    sum+=(unsigned char)buff_rt[j+k];
                                }
                                if((unsigned char)sum==(unsigned char)buff_rt[j+8])
                                {
                                    trace(0,"distconn:6,%d\n",i);
                                    if((unsigned char)buff_rt[j+3]==0x86&&(unsigned char)buff_rt[j+2]==(unsigned char)mtg->dister[i].id)
                                    {
                                        trace(0,"distconn:7,%d\n",i);
                                        mtg->dister[i].dist1=(((unsigned char)buff_rt[j+7])*256*256*256.0+((unsigned char)buff_rt[j+6])*256*256.0+((unsigned char)buff_rt[j+5])*256.0+((unsigned char)buff_rt[j+4])*1.0)/1000.0;
                                        mtg->dister[i].isok=0;
                                        if(gs->opera==DIST_CMD_SEG)
                                        {
                                            if(mtg->gaps.t>0)
                                            {
                                                ds=fabs(mtg->dister[i].dist1-mtg->dister[i].dist0);
                                                if(ds<=0.075)
                                                {
                                                    mtg->dister[i].isok=0;
                                                    //mtg->dister[i].dist0=mtg->dister[i].dist1;
                                                }
                                                else
                                                {
                                                    mtg->dister[i].isok=1;
                                                }
                                            }
                                            //else
                                            //{
                                                //mtg->dister[i].dist0=mtg->dister[i].dist1;
                                            //}
                                        }
                                        else if(gs->opera==DIST_CMD_TBM)
                                        {
                                            mtg->dister[i].dist=mtg->dister[i].dist1;
                                            mtg->dister[i].dist1=0.0;
                                        }
                                        ret=1;
                                        if(mtg->dister[i].isok==0) nret++;
                                        //time(&mtg->dister[i].t);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if(ret==1) break;
                    //sleepms(50);
                }
				sprintf(buff_print,"distconn:8,%d,%d",i,len);
				for(j=0;j<len;j++)
				{
					sprintf(buf_ll,",%0x",(unsigned char)buff_rt[j]);
					strcat(buff_print,buf_ll);
				}
				sprintf(buf_ll,"\n");
				strcat(buff_print,buf_ll);
				trace(0,buff_print);
                trace(0,"distconn:9,i=%d,nret=%d\n",i,nret);
                memset(buff_rt,0,260);
                len=0;
            }
        }
        trace(0,"distconn:10,i=%d,nret=%d\n",i,nret);
        if(nret>=3)
        {
            if(gs->opera==DIST_CMD_NONE)
            {
                mtg->igs=1;
                mtg_log(mtg,MTG_LOG_FINISH_DIST_CONNECT);
            }
            else if(gs->opera==DIST_CMD_TBM)
            {
                mtg->igs=1;
                mtg_gap_tbm(mtg);
                mtg_log(mtg,MTG_LOG_FINISH_DIST_TBM);
            }
            else if(gs->opera==DIST_CMD_SEG)
            {
                mtg_cal_gaps(mtg);
                mtg_log(mtg,MTG_LOG_FINISH_DIST_SEG);
            }
        }
        else
        {
            if(gs->opera==DIST_CMD_NONE)
            {
                mtg->igs=0;
                strsvrstop(&gs->svr);
                mtg_log(mtg,MTG_LOG_FAIL_DIST_CONNECT);
            }
            if(gs->opera==DIST_CMD_TBM)
            {
                mtg_log(mtg,MTG_LOG_FAIL_DIST_TBM);
            }
            else if(gs->opera==DIST_CMD_SEG)
            {
                mtg_log(mtg,MTG_LOG_FAIL_DIST_SEG);
            }
        }
    }
    else
    {
        mtg_log(mtg,MTG_LOG_FAIL_DIST_CONNECT);
    }

finish:
    gs->opera=DIST_CMD_NONE;
    gs->thread=0;
    return 0;
}

int disters_meas(mtg_t* mtg)
{
    /*IO_PACKAGE input,output;
    time_t now;
    char mac[4][13];
    int nMac=0;
    int bsense=0;
    char path[260];
    int opts[5]={60000,1000,100,4096,100};
    int i;

    nMac=GetMacAddress(mac,4);
    input.tag=CMD_GET_MACHINE_ID;
    input.len=12;
    time(&now);
    srand(now);

    for(i=0;i<12;i++)
    {
        input.buff[i]=rand() % 255;
    }
    if(DoSense("MEDO001","STGuider",&input,&output)==1)
    {
        //trace(0,"output=%s\n",output.buff);
        for(i=0;i<nMac;i++)
        {
            if(strncmp(mac[i],(const char*)output.buff,12)==0)
            {
                bsense=1;
                break;
            }
        }
    }
    if(!bsense)
    {
        //mtg_log(mtg,MTG_LOG_SENSE_ERROR);
        return -1;
    }*/
    if(lock_sense(1,174)==0)
        return -1;

    if(mtg->gaps.thread)
    {
        return -1;
    }
    else
    {
        #ifdef WIN32
            if(!(mtg->gaps.thread=CreateThread(NULL,0,_disterthread,mtg,0,NULL)))
        #else
            if(pthread_create(&mtg->gaps.thread,NULL,_disterthread,mtg))
        #endif // WIN32
        {
            return -1;
        }
        return 0;
    }
}

int mtg_cal_gaps(mtg_t* mtg)
{
    int i,j;
    double li,beta,xi,yi;
    point3d_t meas[5];
    point3d_t pts1[5];
    point3d_t pts2[5];
    circle3d_t cir;
    //circle3d_t tbm;
    //circle3d_t seg;
    //double *pout1;
    //double *pout2;
    double dx,dy;
    double bda,bdb,bdc;
    double gap;
    double gap1;
    double beta1,beta2,beta3;
    double bounda,boundb,boundc;
    double x1,y1,x2,y2;

    //tbm.r = 0.0;
    //seg.r = 0.0;
    j=0;
    for(i=0;i<5;i++)
    {
        if(mtg->dister[i].sel==0 /*&& mtg->dister[i].isok==0*/)
        {
            li=mtg->gaps.d1/2.0+mtg->dister[i].dist1;
            beta=mtg->dister[i].angle;
            xi=li*cos(beta);
            yi=li*sin(beta);

            meas[j].x=xi;
            meas[j].y=yi;
            meas[j].z=0.0;
            trace(0,"mtg_cal_gaps:i=%d,d1=%.4f\n",i,mtg->dister[i].dist1);
            j++;
        }
    }
    trace(0,"mtg_cal_gaps:valid=%d\n",j);
    if(j>=3)
    {
        if(!circle3d_init_points(&cir,j,meas,0))
        {
            return 1;
        }

        trace(0,"mtg_cal_gaps:r1=%.4f,x1=%.4f,y1=%.4f\n",mtg->gaps.radius,mtg->gaps.x,mtg->gaps.y);
        trace(0,"mtg_cal_gaps:r2=%.4f,x2=%.4f,y2=%.4f\n",cir.r,cir.x,cir.y);

        dx=cir.x-mtg->gaps.x;
        dy=cir.y-mtg->gaps.y;
        gap=mtg->gaps.radius/2.0-cir.r;
        gap1=cir.r-sqrt(cir.r*cir.r-dx*dx);

        mtg->gaps.ugap1=gap+dy+gap1-(mtg->segset.De-mtg->segset.D)/2.0;
        mtg->gaps.dgap1=gap-dy+gap1-(mtg->segset.De-mtg->segset.D)/2.0;

        gap1=cir.r-sqrt(cir.r*cir.r-dy*dy);
        mtg->gaps.lgap1=gap-dx+gap1-(mtg->segset.De-mtg->segset.D)/2.0;
        mtg->gaps.rgap1=gap+dx+gap1-(mtg->segset.De-mtg->segset.D)/2.0;
        mtg->gaps.x1=cir.x;
        mtg->gaps.y1=cir.y;
        mtg->gaps.z1=cir.z;
        mtg->gaps.radius1=cir.r*2.0;
        //trace(0,"mtg_cal_gaps:ugap=%.4f,dgap=%.4f,\n",mtg->gaps.ugap1,mtg->gaps.dgap1);
        //trace(0,"mtg_cal_gaps:lgap=%.4f,rgap=%.4f,\n",mtg->gaps.lgap1,mtg->gaps.rgap1);
        //trace(0,"gaps:u=%.4f,d=%.4f,l=%.4f,r=%.4f\n",mtg->gaps.ugap1,mtg->gaps.dgap1,mtg->gaps.lgap1,mtg->gaps.rgap1);
    }
    else
    {
        return -1;
    }


    return 0;
}

int mtg_gap_tbm(mtg_t* mtg)
{
    int i,j;
    double li,beta,xi,yi;
    point3d_t meas[5];
    //point3d_t pts1[5];
    //point3d_t pts2[5];
    circle3d_t cir;
    //circle3d_t tbm;
    //circle3d_t seg;
    //double *pout1;
    //double *pout2;
    double beta1,beta2,beta3;
    double bounda,boundb,boundc;
    double x1,y1,x2,y2;

    //tbm.r = 0.0;
    //seg.r = 0.0;
    j=0;
    for(i=0;i<5;i++)
    {
        if(mtg->dister[i].sel==0)
        {
            li=mtg->gaps.d1/2.0+mtg->dister[i].dist;
            beta=mtg->dister[i].angle;
            xi=li*cos(beta);
            yi=li*sin(beta);

            meas[j].x=xi;
            meas[j].y=yi;
            meas[j].z=0.0;

            trace(0,"mtg_gap_tbm:i=%d,d1=%.4f\n",i,mtg->dister[i].dist);
            j++;
        }
    }
    trace(0,"mtg_gap_tbm:valid=%d\n",j);
    if(j>=3)
    {
        if(!circle3d_init_points(&cir,j,meas,0))
        {
            return 1;
        }

        mtg->gaps.x=cir.x;
        mtg->gaps.y=cir.y;
        mtg->gaps.z=cir.z;
        mtg->gaps.radius=cir.r*2.0;
        trace(0,"mtg_gap_tbm:x=%.4f,y=%.4f,z=%.4f,r=%.4f\n",mtg->gaps.x,mtg->gaps.y,mtg->gaps.z,mtg->gaps.radius);
    }
    else
    {
        return -1;
    }


    return 0;
}
