#include "libmtg.h"
#include <string.h>
#define PI  3.1415926535897932384626433832795

extern void mtg_client_init(mtg_t* mtg)
{
    strsvrinit(&mtg->clientsvr);
	mtg->client.timeout=1000;
	mtg->cliThread=0;
    mtg->client.type=CLIENT_TYPE_HOST;
}

#ifdef WIN32
static DWORD WINAPI _client_thread(void* arg)
#else
static void *_client_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    char buf[2048]={0};
	char word[2048]={0};
	char iword[260]={0};
	char ibuf[260]={0};
    char cip[64];
	int opts[5]={60000,1000,100,4096,100};
	int op;

    int log;
    int rc;

    unsigned int tick;
    int len=0,len1=0,len2=0;
    int n,i,j=0;

    int mode = 0;
	int nword=0;
	char path[260];

    long t1 ;
    long t2 ;


    h_element* he;
    h_element h={0};
    v_element* ve;
    v_element v={0};
    h_offset* ho;
    h_offset ho1={0};
    v_offset* vo;
    v_offset vo1={0};
    m_offset* mo;
    m_offset mo1={0};
    MTG_KEY key={0};
    MTG_BLOCK block={0};
    MTG_USER user={0};
    MTG_BASKET bask={0};
    MTG_STATION stn={0};
    MTG_CAM cam={0};

    FILE* fp=fopen("E:\\client.log","w");
    mtg=(mtg_t*)arg;
    mtg->tarset.prc=0.0;
    sprintf(path,"%s:%d",mtg->sets.reip,mtg->comset[4].port);

    mtg->client.tick=0;

    if(mtg->client.type==CLIENT_TYPE_HOST)
    {
        strsvrstart(&mtg->clientsvr,opts,STR_TCPSVR,path);
    }
    else
    {
        strsvrstart(&mtg->clientsvr,opts,STR_TCPCLI,path);
    }

    ///清空串口数据
    strsvrpeek(&mtg->clientsvr,(unsigned char*)buf,2048);
    memcpy(buf,word,2048);
    mtg->clistat=1;
    while(mtg->clistat)
    {
        tick=tickget()-mtg->client.tick;

        if(mtg->client.type==CLIENT_TYPE_HOST)
        {
            if(tick>2000)
            {
                mtg_client_connect(mtg);
            }
        }
        else
        {
            if(tick>4000)
            {
                if(mtg->iclient==2)
                {
                    mtg->iclient=-1;
                    mtg_log(mtg,MTG_LOG_HOST_EXIT);
                }
                else if(mtg->iclient==3)
                {
                    mtg->iclient=0;
                    mtg_log(mtg,MTG_LOG_HOST_EXIT);
                }
            }
        }

        if(mtg->client.cmd==CLIENT_CMD_DISCONNECTED)
        {
            mtg_client_disconnected(mtg);
            sleepms(10);
            break;
        }

        len1=strsvrpeek(&mtg->clientsvr,(unsigned char*)(buf+len),2048-len);
        if(len1==0)
        {
            sleepms(10);
            continue;
        }
        len+=len1;
        for(i=0;i<len-1;i++)
        {
            ///读到回车换行结束
            if(*(buf+i+1)=='\n')
            {
                memcpy(word,buf,i+2);
                word[i+2]=0;
                nword=i+2;
                len=len-i-2;
                memmove(buf,buf+i+2,len);
                break;
            }
        }

        if(nword>0)
        {
            len2=strlen(word);
            for(i=0;i<len2;i++)
            {
                if(word[i]==',')
                {
                    memcpy(iword,word,i);
                    break;
                }
            }
            op=atoi(iword);
            fprintf(fp,"word:%s\n",word);
            fflush(fp);
            memcpy(iword,ibuf,260);
            //fprintf(fp,"op:%d\n",op);
            //fflush(fp);

            switch(op)
            {
                case CLIENT_CMD_CONNECT:
                {
                    mtg_client_connected(mtg);
                    if(mtg->iclient<=0)
                    {
                        sscanf(word,"%d,%d\n",&op,&i);
                        if(mtg->client.type==CLIENT_TYPE_HOST)
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_CONNECT_CLIENT);
                            if(i==-1)
                            {
                                mtg->iclient=1;
                            }
                            else
                            {
                                mtg->iclient=3;
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_CONNECT_HOST);
                            if(mtg->iclient==0)
                            {
                                mtg_get_helement(mtg,0);
                                mtg->iclient=3;
                            }
                            else
                            {
                                mtg->iclient=2;
                            }
                        }
                    }
                    break;
                }
                case CLIENT_CMD_CONNECTED:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    if(mtg->iclient<=0)
                    {
                        if(mtg->client.type==CLIENT_TYPE_HOST)
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_CONNECT_CLIENT);
                            if(i==-1)
                            {
                                mtg->iclient=1;
                            }
                            else
                            {
                                mtg->iclient=3;
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_CONNECT_HOST);
                            if(mtg->iclient==0)
                            {
                                mtg_get_helement(mtg,0);
                                mtg->iclient=3;
                            }
                            else
                            {
                                mtg->iclient=2;
                            }
                        }
                    }
                    break;
                }
                case CLIENT_CMD_DISCONNECTED:
                {
                    if(mtg->iclient>0)
                    {
                        if(mtg->client.type==CLIENT_TYPE_HOST)
                        {
                            mtg_log(mtg,MTG_LOG_CLIENT_EXIT);
                            mtg->iclient=0;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_HOST_EXIT);
                            if(mtg->iclient==3)
                            {
                                mtg->iclient=0;
                            }
                            else
                            {
                                mtg->iclient=-1;
                            }
                        }
                    }
                    break;
                }
                case CLIENT_CMD_LOG:
                {
                    sscanf(word,"%d,%d\n",&op,&log);
                    mtg_log(mtg,log);
                    break;
                }
                case CLIENT_CMD_SET_MEASUREMENT:
                {
                    sscanf(word,"%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                         %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                         %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%ld,%ld,%ld,%d\n",
                         &op,&mtg->m.inc[0],&mtg->m.inc[1],
                         &mtg->m.cam[0],&mtg->m.cam[1],&mtg->m.cam[2],&mtg->m.cam[3],
                         &mtg->m.prism[0],&mtg->m.prism[1],&mtg->m.prism[2],
                         &mtg->m.angle[0],&mtg->m.angle[1],
                         &mtg->m.comp[0],&mtg->m.comp[1],
                         &mtg->m.head[0],&mtg->m.head[1],&mtg->m.head[2],
                         &mtg->m.hdes[0],&mtg->m.hdes[1],&mtg->m.hdes[2],
                         &mtg->m.headc,&mtg->m.headh,&mtg->m.headv,
                         &mtg->m.tail[0],&mtg->m.tail[1],&mtg->m.tail[2],
                         &mtg->m.tdes[0],&mtg->m.tdes[1],&mtg->m.tdes[2],
                         &mtg->m.tailc,&mtg->m.tailh,&mtg->m.tailv,
                         &mtg->m.roll,&mtg->m.pitch,&mtg->m.azimuth,
                         &mtg->m.mid[0],&mtg->m.mid[1],&mtg->m.mid[2],&mtg->m.midj[0],&mtg->m.midj[1],&mtg->m.midj[2],&mtg->m.midj[3],
                         &mtg->m.iseg,(long)&mtg->m.t1,(long)&mtg->m.t2,(long)&mtg->m.t3,&mtg->m.iset
                         );
                    mtg_store_meas(mtg);
                    break;
                }
                case CLIENT_CMD_SET_SERIAL:
                {
                    sscanf(word,"%d,%d,%lf,%lf,%lf,%lf,%lf,\
                        %lf,%lf,%lf,%lf,%lf,\
                        %lf,%lf,%lf,%lf,%lf,\
                        %lf,%lf,%lf,%lf,%lf,\
                        %lf,%lf,%lf,%lf,\
                        %d,%d,%d,%d,%d,%d\n",
                         &op,&mtg->snum.No,&mtg->snum.mile[0],&mtg->snum.mile[1],&mtg->snum.mile[2],&mtg->snum.mile[3],&mtg->snum.mile[4],
                         &mtg->snum.mile[5],&mtg->snum.mile[6],&mtg->snum.mile[7],&mtg->snum.mile[8],&mtg->snum.mile[9],
                         &mtg->snum.mile[10],&mtg->snum.mile[11],&mtg->snum.mile[12],&mtg->snum.mile[13],&mtg->snum.mile[14],
                         &mtg->snum.mile[15],&mtg->snum.mile[16],&mtg->snum.mile[17],&mtg->snum.mile[18],&mtg->snum.mile[19],
                         &mtg->snum.v1,&mtg->snum.v2,&mtg->snum.v3,&mtg->snum.tm,
                         &mtg->snum.sum1,&mtg->snum.sum2,&mtg->snum.sum3,&mtg->snum.sum4,&mtg->snum.mode,&mtg->snum.state
                         );
                    mtg_store_snum(mtg);
                    break;
                }
                case CLIENT_CMD_GET_HE:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    mtg_client_helement(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_HE:
                {
                    he=&h;
                    sscanf(word,"%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%lf\n",
                        &op,&mode,&i,&n,&he->type,&he->l1,&he->length,&he->angle1,&he->angle2,&he->radius,&he->rou1,&he->rou2,&he->x1,&he->y1,&he->x2,&he->y2,&he->pz,&he->deta);
                    if(n==0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_HE);
                        if(mode==3) mtg_get_velement(mtg,0);
                    }
                    else if(i==0)
                    {
                        road_init(&mtg->r);
                        road_modify_horizon(&mtg->r,he,i);
                        road_apply_horizon(&mtg->r);
                        mtg_get_helement(mtg,i+1);
                    }
                    else if(i<n-1)
                    {
                        road_insert_horizon(&mtg->r,he,i);
                        road_apply_horizon(&mtg->r);
                        mtg_get_helement(mtg,i+1);
                    }
                    else if(i==n-1)
                    {
                        road_modify_horizon(&mtg->r,he,i);
                        road_apply_horizon(&mtg->r);
                        mtg_log(mtg,MTG_LOG_FINISH_GET_HE);
                        if(mode==3) mtg_get_velement(mtg,0);
                    }
                    break;
                }
                case CLIENT_CMD_GET_VE:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    mtg_client_velement(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_VE:
                {
                    ve=&v;
                    sscanf(word,"%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%lf\n",
                        &op,&mode,&i,&n,&ve->type,&ve->l1,&ve->h1,&ve->l2,&ve->h2,&ve->length,&ve->radius,&ve->angle1,&ve->angle2,&ve->pz,&ve->deta);
                    if(n==0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_VE);
                        if(mode==3) mtg_get_hoff(mtg,0);
                    }
                    else if(i==0)
                    {
                        road_modify_vertical(&mtg->r,ve,i);
                        road_apply_vertical(&mtg->r);
                        mtg_get_velement(mtg,i+1);
                    }
                    else if(i<n-1)
                    {
                        road_insert_vertical(&mtg->r,ve,i);
                        road_apply_vertical(&mtg->r);
                        mtg_get_velement(mtg,i+1);
                    }
                    else if(i==n-1)
                    {
                        road_modify_vertical(&mtg->r,ve,i);
                        road_apply_vertical(&mtg->r);
                        mtg_log(mtg,MTG_LOG_FINISH_GET_VE);
                        if(mode==3) mtg_get_hoff(mtg,0);
                    }
                    break;
                }
                case CLIENT_CMD_GET_HO:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    mtg_client_hoff(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_HO:
                {
                    ho=&ho1;
                    sscanf(word,"%d,%d,%d,%d,%lf,%lf\n",&op,&mode,&i,&n,&ho->mile,&ho->off);
                    if(n==0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_HO);
                        if(mode==3) mtg_get_voff(mtg,0);
                    }
                    else if(i<n-1)
                    {
                        road_insert_horizon_off(&mtg->r,ho);
                        mtg_get_hoff(mtg,i+1);
                    }
                    else if(i==n-1)
                    {
                        road_insert_horizon_off(&mtg->r,ho);
                        mtg_log(mtg,MTG_LOG_FINISH_GET_HO);
                        if(mode==3) mtg_get_voff(mtg,0);
                    }
                    break;
                }
                case CLIENT_CMD_GET_VO:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    mtg_client_voff(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_VO:
                {
                    vo=&vo1;
                    sscanf(word,"%d,%d,%d,%d,%lf,%lf\n",&op,&mode,&i,&n,&vo->mile,&vo->off);
                    if(n==0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_VO);
                        if(mode==3) mtg_get_moff(mtg,0);
                    }
                    else if(i<n-1)
                    {
                        road_insert_vertical_off(&mtg->r,vo);
                        mtg_client_voff(mtg,i+1);
                    }
                    else if(i==n-1)
                    {
                        road_insert_vertical_off(&mtg->r,vo);
                        mtg_log(mtg,MTG_LOG_FINISH_GET_VO);
                        if(mode==3) mtg_get_moff(mtg,0);
                    }
                    break;
                }
                case CLIENT_CMD_GET_MO:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    mtg_client_moff(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_MO:
                {
                    mo=&mo1;
                    sscanf(word,"%d,%d,%d,%d,%lf,%lf\n",&op,&mode,&i,&n,&mo->mile,&mo->off);
                    if(n==0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_MO);
                        mtg_store_road(mtg);
                        if(mode==3) mtg_get_prj(mtg);
                    }
                    else if(i<n-1)
                    {
                        road_insert_mile_off(&mtg->r,vo);
                        mtg_client_moff(mtg,i+1);
                    }
                    else if(i==n-1)
                    {
                        road_insert_mile_off(&mtg->r,vo);
                        mtg_log(mtg,MTG_LOG_FINISH_GET_MO);
                        mtg_store_road(mtg);
                        if(mode==3) mtg_get_prj(mtg);
                    }
                    break;
                }
                case CLIENT_CMD_GET_PRJ:
                {
                    mtg_client_prj(mtg);
                    break;
                }
                case CLIENT_CMD_SET_PRJ:
                {
                    sscanf(word,"%d,%d,%[^,],%lf,%lf,%d,%d,\
                           %ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%d,%d,%lf,%d\n",
                    &op,&mode,&mtg->prj.name,&mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->prj.duty,
                    &mtg->prj.t1[0],&mtg->prj.t2[1],&mtg->prj.t1[1],&mtg->prj.t2[1],&mtg->prj.t1[2],&mtg->prj.t2[2],&mtg->prj.t1[3],&mtg->prj.t2[3],
                    &mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip,&mtg->prj.dta);
                    if(mtg_store_prj(mtg))
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_PRJ);
                        if(mode==3) mtg_get_key(mtg,0);
                    }
                    break;
                }
                case CLIENT_CMD_GET_KEY:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    mtg_client_key(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_KEY:
                {
                    sscanf(word,"%d,%d,%d,%d,%[^,],%lf,%lf\n",&op,&mode,&i,&n,&key.name,&key.mile1,&key.mile2);
                    if(n==0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_KEY);
                        if(mode==3) mtg_get_tbm(mtg);
                    }
                    else if(i<n-1)
                    {
                        mtg->keys[i]=key;
                        mtg_get_key(mtg,i+1);
                    }
                    else if(i==n-1)
                    {
                        mtg->nks=n;
                        mtg->keys[i]=key;
                        mtg_store_keys(mtg);
                        mtg_log(mtg,MTG_LOG_FINISH_GET_KEY);
                        if(mode==3) mtg_get_tbm(mtg);
                    }
                    break;
                }
                case CLIENT_CMD_GET_TBM:
                {
                    mtg_client_tbm(mtg);
                    break;
                }
                case CLIENT_CMD_SET_TBM:
                {
                    sscanf(word,"%d,%d,%[^,],%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
                           &op,&mode,&mtg->tbm.name,&mtg->tbm.type,&mtg->tbm.mode,&mtg->tbm.D[0],&mtg->tbm.D[1],
                           &mtg->tbm.D[2],&mtg->tbm.D[3],&mtg->tbm.D[4],&mtg->tbm.D[5],&mtg->tbm.L[0],
                           &mtg->tbm.L[1],&mtg->tbm.L[2],&mtg->tbm.L[3]);
                    if(mtg_store_tbmset(mtg))
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_TBM);
                        if(mode==3) mtg_get_tars(mtg);
                    }
                    break;
                }
                case CLIENT_CMD_GET_TAR:
                {
                    mtg_client_tars(mtg);
                    break;
                }
                case CLIENT_CMD_SET_TAR:
                {
                    sscanf(word,"%d,%d,%lf,%lf,%lf,%lf,%lf,%d,%d\n",
                           &op,&mode,&mtg->tarset.prism[0],&mtg->tarset.prism[1],&mtg->tarset.prism[2],&mtg->tarset.prc,&mtg->tarset.length,
                           &mtg->tarset.cam,&mtg->tarset.inc);
                    if(mtg_store_tbmset(mtg))
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_TAR);
                        if(mode==3) mtg_get_cam(mtg,0);
                    }
                    break;
                }
                case CLIENT_CMD_GET_CAM:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    mtg_client_cam(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_CAM:
                {
                    sscanf(word,"%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%s\n",
                            &op,&mode,&i,&cam.w,&cam.h,&cam.affine[0],&cam.affine[1],&cam.affine[2],
                            &cam.affine[3],&cam.affine[4],&cam.affine[5],
                            &cam.affine[6],&cam.affine[7],&cam.affine[8],&cam.name);
                    if(i==0)
                    {
                        mtg->camset[0]=cam;
                        mtg_get_cam(mtg,1);
                    }
                    else if(i==1)
                    {
                        mtg->camset[1]=cam;
                        if(mtg_store_camset(mtg))
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_GET_CAM);
                            if(mode==3) mtg_get_tps(mtg);
                        }
                    }

                    break;
                }
                case CLIENT_CMD_GET_TPS:
                {
                    mtg_client_tps(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_TPS:
                {
                    sscanf(word,"%d,%d,%d,%lf,%lf,%lf,%lf\n",&op,&mode,&mtg->tps.lasertype,&mtg->tps.laserheight,&mtg->tps.laserdist,&mtg->tps.laserx,&mtg->tps.lasery);
                    if(mtg_store_tps(mtg))
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_TPS);
                        if(mode==3) mtg_get_seg(mtg);
                    }
                    break;
                }
                case CLIENT_CMD_GET_SEG:
                {
                    mtg_client_seg(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_SEG:
                {
                    sscanf(word,"%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%d,%lf,%lf,%d\n",&op,&mode,&mtg->segset.type,&mtg->segset.in,&mtg->segset.f2b,&mtg->segset.l2s,&mtg->segset.L,
                           &mtg->segset.De,&mtg->segset.D,&mtg->segset.Dn,&mtg->segset.Ks,&mtg->segset.G0,&mtg->segset.G1,&mtg->segset.s2s);
                    if(mtg_store_tps(mtg))
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_SEG);
                        if(mode==3) mtg_get_block(mtg,0);
                    }
                    break;
                }
                case CLIENT_CMD_GET_BLOCK:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    mtg_client_block(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_BLOCK:
                {
                    sscanf(word,"%d,%d,%d,%d,%[^,],%lf\n",&op,&mode,&i,&n,&block.name,&block.angle);
                    if(n==0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_BLOCK);
                        if(mode==3) mtg_get_original(mtg);
                    }
                    else if(i<n-1)
                    {
                        mtg_get_block(mtg,i+1);
                        mtg->blocks[i]=block;
                    }
                    else if(i==n-1)
                    {
                        mtg->nblk=n;
                        mtg->blocks[i]=block;
                        if(mtg_store_block(mtg))
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_GET_BLOCK);
                            if(mode==3) mtg_get_original(mtg);
                        }
                    }
                    break;
                }
                case CLIENT_CMD_GET_ORIGINAL:
                {
                    mtg_client_original(mtg);
                    break;
                }
                case CLIENT_CMD_SET_ORIGINAL:
                {
                    sscanf(word,"%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                           %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                           %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%ld,%ld,%ld,%d\n",
                         &op,&mode,&mtg->m0.inc[0],&mtg->m0.inc[1],&mtg->m0.inc[1],
                         &mtg->m0.cam[0],&mtg->m0.cam[1],&mtg->m0.cam[2],&mtg->m0.cam[3],
                         &mtg->m0.prism[0],&mtg->m0.prism[1],&mtg->m0.prism[2],
                         &mtg->m0.angle[0],&mtg->m0.angle[1],
                         &mtg->m0.comp[0],&mtg->m0.comp[1],
                         &mtg->m0.head[0],&mtg->m0.head[1],&mtg->m0.head[2],
                         &mtg->m0.hdes[0],&mtg->m0.hdes[1],&mtg->m0.hdes[2],
                         &mtg->m0.headc,&mtg->m0.headh,&mtg->m0.headv,
                         &mtg->m0.tail[0],&mtg->m0.tail[1],&mtg->m0.tail[2],
                         &mtg->m0.tdes[0],&mtg->m0.tdes[1],&mtg->m0.tdes[2],
                         &mtg->m0.tailc,&mtg->m0.tailh,&mtg->m0.tailv,
                         &mtg->m0.mid[0],&mtg->m0.mid[1],&mtg->m0.mid[2],
                         &mtg->m0.mdes[0],&mtg->m0.mdes[1],&mtg->m0.mdes[2],
                         &mtg->m0.midc,&mtg->m0.midh,&mtg->m0.midv,
                         &mtg->m0.midj[0],&mtg->m0.midj[1],&mtg->m0.midj[2],&mtg->m0.midj[3],
                         &mtg->m0.roll,&mtg->m0.pitch,&mtg->m0.azimuth,
                         &mtg->m0.iseg,&mtg->m0.t1,&mtg->m0.t2,&mtg->m0.t3,&mtg->m0.iset
                         );
                    if(mtg_store_origin(mtg))
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_ORIGIN);
                        if(mode==3) mtg_get_sets(mtg);
                    }
                    break;
                }
                case CLIENT_CMD_GET_SETS:
                {
                    mtg_client_sets(mtg);
                    break;
                }
                case CLIENT_CMD_SET_SETS:
                {
                    sscanf(word,"%d,%d,%d,%d,%d,%d,%d,%d,\
                            %d,%d,%d,%d,%d,%d,%d,\
                            %d,%d,%d,%d,%d,%d,%d,\
                            %d,%d,%d,%d,%d,%d,%d,\
                            %d,%d,%lf,%lf,%d,%s\n",
                            &op,&mode,&mtg->sets.cyc,&mtg->sets.bcyc,&mtg->sets.palw,&mtg->sets.jalw,&mtg->sets.balw,&mtg->sets.talw,
                            &mtg->sets.vibration,&mtg->sets.rstn,&mtg->sets.tsyn,&mtg->sets.rget,&mtg->sets.idrv,&mtg->sets.prun,&mtg->sets.pend,
                            &mtg->sets.psas,&mtg->sets.pchk,&mtg->sets.pqry,&mtg->sets.pmap,&mtg->sets.psmr,&mtg->sets.pquit,&mtg->sets.unit,
                            &mtg->sets.vmileage,&mtg->sets.head,&mtg->sets.tbm3d,&mtg->sets.heading,&mtg->sets.povr,&mtg->sets.jovr,&mtg->sets.tovr,
                            &mtg->sets.bovr,&mtg->sets.toEr,&mtg->sets.flen,&mtg->sets.fdev,&mtg->sets.lang,&cip);
                    if(mtg_store_settings(mtg))
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_SETS);
                        if(mode==3) mtg_get_smonitor(mtg);
                    }
                    break;
                }
                case CLIENT_CMD_GET_SMONITOR:
                {
                    mtg_client_smonitor(mtg);
                    break;
                }
                case CLIENT_CMD_SET_SMONITOR:
                {
                    sscanf(word,"%d,%d,%d,%d,%d,%d,%lf,%lf,%lf,%ld\n",
                            &op,&mode,&mtg->smonitor.number,&mtg->smonitor.monitor,&mtg->smonitor.cycle,&mtg->smonitor.last,
                            &mtg->smonitor.x,&mtg->smonitor.y,&mtg->smonitor.z,&mtg->smonitor.t);
                    if(mtg_store_smonitor(mtg))
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_SMONITOR);
                        if(mode==3) mtg_get_user(mtg,0);
                    }
                    break;
                }
                case CLIENT_CMD_GET_USER:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    mtg_client_user(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_USER:
                {
                    sscanf(word,"%d,%d,%d,%d,%[^,],%[^,],%d\n",&op,&mode,&i,&n,&user.name,&user.password,&user.level);
                    if(n==0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_USER);
                        if(mode==3) mtg_get_basket(mtg,mtg->nbsk);
                    }
                    else if(i<n-1)
                    {
                        mtg->user[i]=user;
                        mtg_get_user(mtg,i+1);
                    }
                    else if(i==n-1)
                    {
                        mtg->user[i]=user;
                        mtg->nuser=n;
                        if(mtg_store_user(mtg))
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_GET_USER);
                            if(mode==3) mtg_get_basket(mtg,mtg->nbsk);
                        }
                    }
                    break;
                }
                case CLIENT_CMD_GET_BASKET:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    mtg_client_basket(mtg,i);
                    break;
                }
                case CLIENT_CMD_SET_BASKET:
                {
                    sscanf(word,"%d,%d,%d,%d,%[^,],%lf,%lf,%lf,%ld\n",
                            &op,&mode,&i,&n,&bask.name,&bask.x,&bask.y,&bask.z,&bask.t);
                    if(n==0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_BASK);
                        if(mode==3) mtg_get_station(mtg,mtg->nstn);
                    }
                    else if(i<n-1)
                    {
                        mtg->bask[i]=bask;
                        mtg_get_basket(mtg,i+1);
                    }
                    else if(i==n-1)
                    {
                        mtg->bask[i]=bask;
                        if(mtg_store_basket(mtg))
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_GET_BASK);
                            if(mode==3) mtg_get_station(mtg,mtg->nstn);
                        }
                    }
                    break;
                }
                case CLIENT_CMD_GET_STN:
                {
                    sscanf(word,"%d,%d\n",&op,&i);
                    mtg_client_station(mtg,i);
                    if(mtg->nstn==0) mtg->iclient=1;
                    else if(i==mtg->nstn-1) mtg->iclient=1;
                    break;
                }
                case CLIENT_CMD_SET_STN:
                {
                    sscanf(word,"%d,%d,%d,%d,%[^,],%[^,],%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%ld\n",
                             &op,&i,&n,&stn.id,&stn.stat,&stn.back,&stn.statx,&stn.staty,
                             &stn.statz,&stn.stath,&stn.backx,&stn.backy,&stn.backz,
                             &stn.backh,&stn.backx1,&stn.backy1,&stn.backz1,&stn.t);
                    if(n==0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_GET_STATION);
                        mtg->iclient=2;
                    }
                    else if(i<n-1)
                    {
                        mtg->stns[i]=stn;
                        mtg_get_station(mtg,i+1);
                    }
                    else if(i==n-1)
                    {
                        mtg->stns[i]=stn;
                        if(mtg_store_stns(mtg))
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_GET_STATION);
                            mtg->iclient=2;
                        }
                    }
                    break;
                }
                case CLIENT_CMD_SET_SEGS:
                {
                    sscanf(word,"%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,\
                        %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                        %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                        %lf,%lf,%ld\n",
                        &op,&mode,&mtg->segs[4].numb,&mtg->segs[4].type,&mtg->segs[4].kpos,&mtg->segs[4].ugap,&mtg->segs[4].dgap,&mtg->segs[4].lgap,&mtg->segs[4].rgap,
                        &mtg->segs[4].uaj,&mtg->segs[4].daj,&mtg->segs[4].laj,&mtg->segs[4].raj,&mtg->segs[4].uhj,&mtg->segs[4].dhj,&mtg->segs[4].lhj,&mtg->segs[4].rhj,
                        &mtg->segs[4].ufj,&mtg->segs[4].dfj,&mtg->segs[4].lfj,&mtg->segs[4].rfj,&mtg->segs[4].mile,&mtg->segs[4].x,&mtg->segs[4].y,&mtg->segs[4].z,
                        &mtg->segs[4].azi,&mtg->segs[4].tilt,&mtg->segs[4].t
                        );
                    mtg_store_seg(mtg,&mtg->segs[4]);
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

        sleepms(0);
    }


    fclose(fp);
    if(he) free(he);
    if(ve) free(ve);
    if(ho) free(ho);
    if(vo) free(vo);
    if(mo) free(mo);
    mtg->cliThread=0;
    return 0;
}

extern int mtg_client_start(mtg_t* mtg)
{
    if(mtg->clistat) return 0;

    if(!mtg->cliThread)
    {
    #ifdef WIN32
        if(!(mtg->cliThread=CreateThread(NULL,0,_client_thread,mtg,0,NULL)))
    #else
        if(pthread_create(&mtg->cliThread,NULL,_client_thread,mtg))
    #endif
        {
            return -1;
        }
    }
    return 0;
}

extern int mtg_client_stop(mtg_t* mtg)
{
    if(!mtg->clistat) return 0;
    mtg->clistat=0;
    while(mtg->cliThread)
    {
        sleepms(10);
    }
    return 0;
}

///连接
extern int mtg_client_connect(mtg_t* mtg)
{
    char cmd[260];
    sprintf(cmd,"%d,%d\n",CLIENT_CMD_CONNECT,mtg->iclient);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_connected(mtg_t* mtg)
{
    char cmd[260];
    sprintf(cmd,"%d,%d\n",CLIENT_CMD_CONNECTED,mtg->iclient);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();
    return 0;
}

///退出
extern int mtg_client_disconnected(mtg_t* mtg)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_DISCONNECTED,0);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));

    return 0;
}

///系统日志
extern int mtg_client_log(mtg_t* mtg,int log)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_LOG,log);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();
    return 0;
}

///工程数据
extern int mtg_get_prj(mtg_t* mtg)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_PRJ,0);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();
    return;
}

extern int mtg_client_prj(mtg_t* mtg)
{
    char cmd[1024];

    sprintf(cmd,"%d,%d,%s,%.12f,%.12f,%d,%d,\
				%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,\
                %d,%d,%.12f,%d\n",
                 CLIENT_CMD_SET_PRJ,mtg->iclient,mtg->prj.name,mtg->prj.mile1,mtg->prj.mile2,mtg->prj.a2z,mtg->prj.duty,
				 mtg->prj.t1[0],mtg->prj.t2[0],mtg->prj.t1[1],mtg->prj.t2[1],mtg->prj.t1[2],mtg->prj.t2[2],mtg->prj.t1[3],mtg->prj.t2[3],
				 mtg->prj.htip,mtg->prj.vtip,mtg->prj.tip,mtg->prj.dta
             );
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

///关键区域
extern int mtg_get_key(mtg_t* mtg,int index)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_KEY,index);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return;
}

extern int mtg_client_key(mtg_t* mtg,int index)
{
    char cmd[260];
    char name[64]={0};
    int n = mtg->nks;

    if(n==0)
    {
        sprintf(cmd,"%d,%d,%d,%d,%s,%.12f,%.12f\n",CLIENT_CMD_SET_KEY,mtg->iclient,0,0,name,0,0);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    else if(index<n)
    {
        sprintf(cmd,"%d,%d,%d,%d,%s,%.12f,%.12f\n",CLIENT_CMD_SET_KEY,mtg->iclient,index,n,mtg->keys[index].name,mtg->keys[index].mile1,mtg->keys[index].mile2);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    mtg->client.tick=tickget();

    return 0;
}

///关键区域
extern int mtg_get_tbm(mtg_t* mtg)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_TBM,0);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return;
}

extern int mtg_client_tbm(mtg_t* mtg)
{
    char cmd[1024];

    sprintf(cmd,"%d,%d,%s,%d,%d,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f\n",
                 CLIENT_CMD_SET_TBM,mtg->iclient,mtg->tbm.name,mtg->tbm.type,mtg->tbm.mode,mtg->tbm.D[0],mtg->tbm.D[1],mtg->tbm.D[2],mtg->tbm.D[3],
                 mtg->tbm.D[4],mtg->tbm.D[5],mtg->tbm.L[0],mtg->tbm.L[1],mtg->tbm.L[2],mtg->tbm.L[3],mtg->tbm.L[4]
             );
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

///激光靶
extern int mtg_get_tars(mtg_t* mtg)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_TAR,0);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return;
}

extern int mtg_client_tars(mtg_t* mtg)
{
    char cmd[1024];

    sprintf(cmd,"%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%d\n",
             CLIENT_CMD_SET_TAR,mtg->iclient,mtg->tarset.prism[0],mtg->tarset.prism[1],mtg->tarset.prism[2],mtg->tarset.prc,mtg->tarset.length,
             mtg->tarset.cam,mtg->tarset.inc
             );
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

///相机参数
extern int mtg_get_cam(mtg_t* mtg,int index)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_CAM,index);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return;
}

extern int mtg_client_cam(mtg_t* mtg,int index)
{
    char cmd[2048];
    char name[64]={0};
    int i=index;

    if(i<2)
    {
        sprintf(cmd,"%d,%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%s\n",
                    CLIENT_CMD_SET_CAM,mtg->iclient,i,mtg->camset[i].w,mtg->camset[i].h,mtg->camset[i].affine[0],mtg->camset[i].affine[1],mtg->camset[i].affine[2],
                    mtg->camset[i].affine[3],mtg->camset[i].affine[4],mtg->camset[i].affine[5],
                    mtg->camset[i].affine[6],mtg->camset[i].affine[7],mtg->camset[i].affine[8],mtg->camset[i].name);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    else
    {
        sprintf(cmd,"%d,%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%s\n",
                    CLIENT_CMD_SET_CAM,mtg->iclient,0,0,0,0,0,0,0,0,0,0,0,0,name);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    mtg->client.tick=tickget();

    return 0;
}

///全站仪
extern int mtg_get_tps(mtg_t* mtg)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_TPS,0);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return;
}

extern int mtg_client_tps(mtg_t* mtg)
{
    char cmd[260];

    sprintf(cmd,"%d,%d,%d,%.12f,%.12f,%.12f,%.12f\n",
             CLIENT_CMD_SET_TPS,mtg->iclient,mtg->tps.lasertype,mtg->tps.laserheight,mtg->tps.laserdist,mtg->tps.laserx,mtg->tps.lasery);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

///管环
extern int mtg_get_seg(mtg_t* mtg)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_SEG,0);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return;
}

extern int mtg_client_seg(mtg_t* mtg)
{
    char cmd[260];

    sprintf(cmd,"%d,%d,%d,%d,%d,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%d,%.12f,%.12f,%d\n",
            CLIENT_CMD_SET_SEG,mtg->iclient,mtg->segset.type,mtg->segset.in,mtg->segset.f2b,mtg->segset.l2s,mtg->segset.L,
            mtg->segset.De,mtg->segset.D,mtg->segset.Dn,mtg->segset.Ks,mtg->segset.G0,mtg->segset.G1,mtg->segset.s2s
            );
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

///管块
extern int mtg_get_block(mtg_t* mtg,int index)//请求管块参数
{
    char cmdstr[260];

    sprintf(cmdstr,"%d,%d\n",CLIENT_CMD_GET_BLOCK,index);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmdstr,strlen(cmdstr));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_block(mtg_t* mtg,int index)
{
    char cmd[260];
    char name[64]={0};
    int n = mtg->nblk;
    int i=index;

    if(n==0)
    {
        sprintf(cmd,"%d,%d,%d,%d,%s,%.12f\n",CLIENT_CMD_SET_BLOCK,mtg->iclient,0,0,name,0);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    else if(i<n)
    {
        sprintf(cmd,"%d,%d,%d,%d,%s,%.12f\n",CLIENT_CMD_SET_BLOCK,mtg->iclient,i,n,mtg->blocks[i].name,mtg->blocks[i].angle);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    mtg->client.tick=tickget();

    return 0;
}

///零位数据
extern int mtg_get_original(mtg_t* mtg)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_ORIGINAL,0);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return;
}

extern int mtg_client_original(mtg_t* mtg)
{
    char cmd[2048];

    sprintf(cmd,"%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                   %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                   %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%ld,%ld,%ld,%d\n",
                 CLIENT_CMD_SET_ORIGINAL,mtg->iclient,mtg->m0.inc[0],mtg->m0.inc[1],mtg->m0.inc[1],
                 mtg->m0.cam[0],mtg->m0.cam[1],mtg->m0.cam[2],mtg->m0.cam[3],
                 mtg->m0.prism[0],mtg->m0.prism[1],mtg->m0.prism[2],
                 mtg->m0.angle[0],mtg->m0.angle[1],
                 mtg->m0.comp[0],mtg->m0.comp[1],
                 mtg->m0.head[0],mtg->m0.head[1],mtg->m0.head[2],
                 mtg->m0.hdes[0],mtg->m0.hdes[1],mtg->m0.hdes[2],
                 mtg->m0.headc,mtg->m0.headh,mtg->m0.headv,
                 mtg->m0.tail[0],mtg->m0.tail[1],mtg->m0.tail[2],
                 mtg->m0.tdes[0],mtg->m0.tdes[1],mtg->m0.tdes[2],
                 mtg->m0.tailc,mtg->m0.tailh,mtg->m0.tailv,
                 mtg->m0.mid[0],mtg->m0.mid[1],mtg->m0.mid[2],
                 mtg->m0.mdes[0],mtg->m0.mdes[1],mtg->m0.mdes[2],
                 mtg->m0.midc,mtg->m0.midh,mtg->m0.midv,
                 mtg->m0.midj[0],mtg->m0.midj[1],mtg->m0.midj[2],mtg->m0.midj[3],
                 mtg->m0.roll,mtg->m0.pitch,mtg->m0.azimuth,
                 mtg->m0.iseg,(long)mtg->m0.t1,(long)mtg->m0.t2,(long)mtg->m0.t3,mtg->m0.iset
                 );
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

///系统设置
extern int mtg_get_sets(mtg_t* mtg)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_SETS,0);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return;
}

extern int mtg_client_sets(mtg_t* mtg)
{
    char cmd[2048];

    sprintf(cmd,"%d,%d,%d,%d,%d,%d,%d,%d,\
            %d,%d,%d,%d,%d,%d,%d,\
            %d,%d,%d,%d,%d,%d,%d,\
            %d,%d,%d,%d,%d,%d,%d,\
            %d,%d,%.12f,%.12f,%d,%s\n",
            CLIENT_CMD_SET_SETS,mtg->iclient,mtg->sets.cyc,mtg->sets.bcyc,mtg->sets.palw,mtg->sets.jalw,mtg->sets.balw,mtg->sets.talw,
            mtg->sets.vibration,mtg->sets.rstn,mtg->sets.tsyn,mtg->sets.rget,mtg->sets.idrv,mtg->sets.prun,mtg->sets.pend,
            mtg->sets.psas,mtg->sets.pchk,mtg->sets.pqry,mtg->sets.pmap,mtg->sets.psmr,mtg->sets.pquit,mtg->sets.unit,
            mtg->sets.vmileage,mtg->sets.head,mtg->sets.tbm3d,mtg->sets.heading,mtg->sets.povr,mtg->sets.jovr,mtg->sets.tovr,
            mtg->sets.bovr,mtg->sets.toEr,mtg->sets.flen,mtg->sets.fdev,mtg->sets.lang,mtg->sets.reip);

    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

///管环监测
extern int mtg_get_smonitor(mtg_t* mtg)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_SMONITOR,0);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return;
}

extern int mtg_client_smonitor(mtg_t* mtg)
{
    char cmd[1024];

    sprintf(cmd,"%d,%d,%d,%d,%d,%d,%.12f,%.12f,%.12f,%ld\n",
            CLIENT_CMD_SET_SMONITOR,mtg->iclient,mtg->smonitor.number,mtg->smonitor.monitor,mtg->smonitor.cycle,mtg->smonitor.last,mtg->smonitor.x,mtg->smonitor.y,mtg->smonitor.z,(long)mtg->smonitor.t);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return;
}

///用户
extern int mtg_get_user(mtg_t* mtg,int index)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_USER,index);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_user(mtg_t* mtg,int index)
{
    char cmd[260];
    char name[64]={0};
    int n = mtg->nuser;
    int i=index;

    if(n==0)
    {
        sprintf(cmd,"%d,%d,%d,%d,%s,%s,%d\n",CLIENT_CMD_SET_USER,mtg->iclient,0,0,name,name,0);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    else if(i<n)
    {
        mtg->client.cmd=CLIENT_CMD_SET_USER;

        sprintf(cmd,"%d,%d,%d,%d,%s,%s,%d\n",CLIENT_CMD_SET_USER,mtg->iclient,i,n,mtg->user[i].name,mtg->user[i].password,mtg->user[i].level);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    mtg->client.tick=tickget();

    return 0;
}

///平曲线要素
extern int mtg_get_helement(mtg_t* mtg,int index)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_HE,index);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_helement(mtg_t* mtg,int index)
{
    char cmd[1024];
    int n = road_number_horizon(&mtg->r);
    h_element *he;
    int i=index;

    if(n==0)
    {
        he=road_horizon(&mtg->r,i);
        sprintf(cmd,"%d,%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%.12f\n",
                CLIENT_CMD_SET_HE,mtg->iclient,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    else if(i<n)
    {
        he=road_horizon(&mtg->r,i);
        sprintf(cmd,"%d,%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%.12f\n",
                CLIENT_CMD_SET_HE,mtg->iclient,i,n,he->type,he->l1,he->length,he->angle1,he->angle2,he->radius,he->rou1,he->rou2,he->x1,he->y1,he->x2,he->y2,he->pz,he->deta);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    mtg->client.tick=tickget();

    return 0;
}

///竖曲线
extern int mtg_get_velement(mtg_t* mtg,int index)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_VE,index);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_velement(mtg_t* mtg,int index)
{
    char cmd[260];
    int n = road_number_vertical(&mtg->r);
    v_element *ve;
    int i=index;

    if(n==0)
    {
        ve=road_vertical(&mtg->r,i);
        sprintf(cmd,"%d,%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%.12f\n",
                CLIENT_CMD_SET_VE,mtg->iclient,0,0,0,0,0,0,0,0,0,0,0,0,0);

        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    else if(i<n)
    {
        ve=road_vertical(&mtg->r,i);
        sprintf(cmd,"%d,%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%.12f\n",
                CLIENT_CMD_SET_VE,mtg->iclient,i,n,ve->type,ve->l1,ve->h1,ve->l2,ve->h2,ve->length,ve->radius,ve->angle1,ve->angle2,ve->pz,ve->deta);

        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    mtg->client.tick=tickget();

    return 0;
}

///平面偏移
extern int mtg_get_hoff(mtg_t* mtg,int index)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_HO,index);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_hoff(mtg_t* mtg,int index)
{
    char cmd[260];
    int n = road_number_horizon_off(&mtg->r);
    h_offset *ho;
    int i=index;
    if(n==0)
    {
        ho=road_horizon_off(&mtg->r,i);
        sprintf(cmd,"%d,%d,%d,%d,%.12f,%.12f\n",CLIENT_CMD_SET_HO,mtg->iclient,0,0,0,0);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    else if(i<n)
    {
        ho=road_horizon_off(&mtg->r,i);
        sprintf(cmd,"%d,%d,%d,%d,%.12f,%.12f\n",CLIENT_CMD_SET_HO,mtg->iclient,i,n,ho->mile,ho->off);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    mtg->client.tick=tickget();

    return 0;
}

///垂直偏移
extern int mtg_get_voff(mtg_t* mtg,int index)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_VO,index);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_voff(mtg_t* mtg,int index)
{
    char cmd[260];
    int n = road_number_vertical_off(&mtg->r);
    v_offset *vo;
    int i=index;

    if(n==0)
    {
        vo=road_vertical_off(&mtg->r,i);
        sprintf(cmd,"%d,%d,%d,%d,%.12f,%.12f\n",CLIENT_CMD_SET_VO,mtg->iclient,0,0,0,0);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    else if(i<n)
    {
        vo=road_vertical_off(&mtg->r,i);
        sprintf(cmd,"%d,%d,%d,%d,%.12f,%.12f\n",CLIENT_CMD_SET_VO,mtg->iclient,i,n,vo->mile,vo->off);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    mtg->client.tick=tickget();

    return 0;
}
///长短链
extern int mtg_get_moff(mtg_t* mtg,int index)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_MO,index);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_moff(mtg_t* mtg,int index)
{
    char cmd[260];
    int n = road_number_mile_off(&mtg->r);
    m_offset *mo;
    int i=index;
    if(n==0)
    {
        mo=road_mile_off(&mtg->r,i);
        sprintf(cmd,"%d,%d,%d,%d,%.12f,%.12f\n",CLIENT_CMD_SET_MO,mtg->iclient,0,0,0,0);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    else if(i<n)
    {
        mo=road_mile_off(&mtg->r,i);
        sprintf(cmd,"%d,%d,%d,%d,%.12f,%.12f\n",CLIENT_CMD_SET_MO,mtg->iclient,i,n,mo->mile,mo->off);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_meas(mtg_t* mtg)
{
    char cmd[2048];

    sprintf(cmd,"%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                 %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                 %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%ld,%ld,%ld,%d\n",
                 CLIENT_CMD_SET_MEASUREMENT,mtg->m1.inc[0],mtg->m1.inc[1],
                 mtg->m1.cam[0],mtg->m1.cam[1],mtg->m1.cam[2],mtg->m1.cam[3],
                 mtg->m1.prism[0],mtg->m1.prism[1],mtg->m1.prism[2],
                 mtg->m1.angle[0],mtg->m1.angle[1],
                 mtg->m1.comp[0],mtg->m1.comp[1],
                 mtg->m1.head[0],mtg->m1.head[1],mtg->m1.head[2],
                 mtg->m1.hdes[0],mtg->m1.hdes[1],mtg->m1.hdes[2],
                 mtg->m1.headc,mtg->m1.headh,mtg->m1.headv,
                 mtg->m1.tail[0],mtg->m1.tail[1],mtg->m1.tail[2],
                 mtg->m1.tdes[0],mtg->m1.tdes[1],mtg->m1.tdes[2],
                 mtg->m1.tailc,mtg->m1.tailh,mtg->m1.tailv,
                 mtg->m1.roll,mtg->m1.pitch,mtg->m1.azimuth,
                 mtg->m1.mid[0],mtg->m1.mid[1],mtg->m1.mid[2],mtg->m1.midj[0],mtg->m1.midj[1],mtg->m1.midj[2],mtg->m1.midj[3],
                 mtg->m1.iseg,(long)mtg->m1.t1,(long)mtg->m1.t2,(long)mtg->m1.t3,mtg->m1.iset
                 );
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_serial(mtg_t* mtg)
{
    char cmd[2048];

    sprintf(cmd,"%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%.12f,\
            %d,%d,%d,%d,%d,%d\n",
             CLIENT_CMD_SET_SERIAL,mtg->snum.No,mtg->snum.mile[0],mtg->snum.mile[1],mtg->snum.mile[2],mtg->snum.mile[3],mtg->snum.mile[4],
             mtg->snum.mile[5],mtg->snum.mile[6],mtg->snum.mile[7],mtg->snum.mile[8],mtg->snum.mile[9],
             mtg->snum.mile[10],mtg->snum.mile[11],mtg->snum.mile[12],mtg->snum.mile[13],mtg->snum.mile[14],
             mtg->snum.mile[15],mtg->snum.mile[16],mtg->snum.mile[17],mtg->snum.mile[18],mtg->snum.mile[19],
             mtg->snum.v1,mtg->snum.v2,mtg->snum.v3,mtg->snum.tm,
             mtg->snum.sum1,mtg->snum.sum2,mtg->snum.sum3,mtg->snum.sum4,mtg->snum.mode,mtg->snum.state
             );
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_segs(mtg_t* mtg)
{
    char cmd[2048];

    sprintf(cmd,"%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%ld\n",
            CLIENT_CMD_SET_SEGS,mtg->segs[4].numb,mtg->segs[4].type,mtg->segs[4].kpos,mtg->segs[4].ugap,mtg->segs[4].dgap,mtg->segs[4].lgap,mtg->segs[4].rgap,
            mtg->segs[4].uaj,mtg->segs[4].daj,mtg->segs[4].laj,mtg->segs[4].raj,mtg->segs[4].uhj,mtg->segs[4].dhj,mtg->segs[4].lhj,mtg->segs[4].rhj,
            mtg->segs[4].ufj,mtg->segs[4].dfj,mtg->segs[4].lfj,mtg->segs[4].rfj,mtg->segs[4].mile,mtg->segs[4].x,mtg->segs[4].y,mtg->segs[4].z,
            mtg->segs[4].azi,mtg->segs[4].tilt,mtg->segs[4].t
            );
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_get_station(mtg_t* mtg,int index)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_STN,index);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_station(mtg_t* mtg,int index)
{
    char cmd[2048];
    char name[64]={0};
    int n = mtg->nstn;
    int i=index;

    if(n==0)
    {
        sprintf(cmd,"%d,%d,%d,%d,%d,%s,%s,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%ld\n",
                 CLIENT_CMD_SET_STN,mtg->iclient,0,0,0,name,name,0,0,0,0,0,0,0,0,0,0,0,0);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    else if(i<n)
    {
        sprintf(cmd,"%d,%d,%d,%d,%d,%s,%s,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%ld\n",
                 CLIENT_CMD_SET_STN,mtg->iclient,i,n,mtg->stns[i].id,mtg->stns[i].stat,mtg->stns[i].back,mtg->stns[i].statx,mtg->stns[i].staty,
                 mtg->stns[i].statz,mtg->stns[i].stath,mtg->stns[i].backx,mtg->stns[i].backy,mtg->stns[i].backz,mtg->stns[i].
                 backh,mtg->stns[i].backx1,mtg->stns[i].backy1,mtg->stns[i].backz1,(long)mtg->stns[i].t);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_get_basket(mtg_t* mtg,int index)
{
    char cmd[260];

    sprintf(cmd,"%d,%d\n",CLIENT_CMD_GET_BASKET,index);
    strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_basket(mtg_t* mtg,int index)
{
    char cmd[1024];
    char name[64]={0};
    int n = mtg->nbsk;
    int i=index;

    if(n==0)
    {
        sprintf(cmd,"%d,%d,%d,%d,%s,%.12f,%.12f,%.12f,%ld\n",
                 CLIENT_CMD_SET_BASKET,mtg->iclient,0,0,name,0,0,0,0);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    else if(i<n)
    {
        sprintf(cmd,"%d,%d,%d,%d,%s,%.12f,%.12f,%.12f,%ld\n",
                 CLIENT_CMD_SET_BASKET,mtg->iclient,i,n,mtg->bask[i].name,mtg->bask[i].x,mtg->bask[i].y,mtg->bask[i].z,(long)mtg->bask[i].t);
        strsvrput(&mtg->clientsvr,(unsigned char*)cmd,strlen(cmd));
    }
    mtg->client.tick=tickget();

    return 0;
}

extern int mtg_client_state(mtg_t* mtg)
{
    char cmd[260];


    mtg->client.tick=tickget();
    return 0;
}
