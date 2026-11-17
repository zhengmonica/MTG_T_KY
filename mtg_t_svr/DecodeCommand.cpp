#include "mtg_t_svrMain.h"
#include "mtg_t_svrApp.h"
#include "enumser.h"
#include "libtps.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

void mtg_t_svrFrame::DecodeCommand(wxSocketBase* sock,const char* cmd)
{
    int m_id=0,id=-1,sid=-1;
    //FILE* fp=fopen("E:\\decommand.log","a");
    if(!sscanf(cmd,"%%R1Q,%d:%d",&id,&sid)) return;
    //fprintf(fp,"%s\n",cmd);
    //trace(0,"client: cmd=%s\n",cmd);
    char msg[4096];
    char m_log[1024];
    char uid[64],psw[64];
    int i=0,j=0;
    int m_index=-1;
    time_t now;
    static road r;
    int id1,id2;
    double prism[3];
    long t1,t2,t3;

    wxIPV4address  addr;
    sock->GetPeer(addr);

    for(i=0; i<ncli; i++)
    {
        if(strcmp(m_clients[i].addr,addr.IPAddress().mb_str(wxConvUTF8))==0)
        {
            m_index=i;
            break;
        }
    }

    i=0;
    switch(id)
    {
        case 53:     ///设站定向
        {
            //int type=-1;
            //sscanf(cmd,"%%R1Q,53:%d:%d",&type,&i);
            if(sid==0)
            {
                MTG_BASKET b;
                sscanf(cmd,"%%R1Q,53:0:%d,'%[^']',%lf,%lf,%lf\n",
                        &i,b.name,&b.x,&b.y,&b.z);
                if(strlen(b.name)==0)
                sscanf(cmd,"%%R1Q,53:0:%d,'',%lf,%lf,%lf\n",
                        &i,&b.x,&b.y,&b.z);
                time(&b.t);
                mtg_add_basket(mtg,&b);
                strcpy(msg,cmd);
                msg[3]='D';
                msg[6]='4';
                RadioMsg(msg);
                sprintf(m_log,"用户<%s>增加吊篮",m_clients[m_index].addr);
                add_msg_log(mtg,m_log,0);
            }
            else if(sid==1)
            {
                sscanf(cmd,"%%R1Q,53:1:%d,'%[^']',%lf,%lf,%lf\n",
                        &i,mtg->bask[i].name,&mtg->bask[i].x,&mtg->bask[i].y,&mtg->bask[i].z);
                if(strlen(mtg->bask[i].name)==0)
                sscanf(cmd,"%%R1Q,53:1:%d,'',%lf,%lf,%lf\n",
                    &i,&mtg->bask[i].x,&mtg->bask[i].y,&mtg->bask[i].z);
                time(&mtg->bask[i].t);
                mtg_modify_basket(mtg,i,&mtg->bask[i]);
                strcpy(msg,cmd);
                msg[3]='D';
                msg[6]='4';
                RadioMsg(msg);
                sprintf(m_log,"用户<%s>编辑吊篮",m_clients[m_index].addr);
                add_msg_log(mtg,m_log,0);
            }
            else if(sid==2)
            {
                sscanf(cmd,"%%R1Q,53:2:%d",&i);
                mtg_remove_basket(mtg,i);
                strcpy(msg,cmd);
                msg[3]='D';
                msg[6]='4';
                RadioMsg(msg);
                sprintf(m_log,"用户<%s>删除吊篮",m_clients[m_index].addr);
                add_msg_log(mtg,m_log,0);
            }
            else if(sid==3)
            {
                sscanf(cmd,"%%R1Q,53:3:%d",&i);
                strncpy(mtg->istn.stat,mtg->bask[i].name,64);
                mtg->istn.statx=mtg->bask[i].x;
                mtg->istn.staty=mtg->bask[i].y;
                mtg->istn.statz=mtg->bask[i].z;
                strcpy(msg,cmd);
                msg[3]='D';
                msg[6]='4';
                RadioMsg(msg);
                sprintf(m_log,"用户<%s>更改测站点",m_clients[m_index].addr);
                add_msg_log(mtg,m_log,0);
            }
            else if(sid==4)
            {
                sscanf(cmd,"%%R1Q,53:4:%d",&i);
                strncpy(mtg->istn.back,mtg->bask[i].name,64);
                mtg->istn.backx=mtg->bask[i].x;
                mtg->istn.backy=mtg->bask[i].y;
                mtg->istn.backz=mtg->bask[i].z;
                strcpy(msg,cmd);
                msg[3]='D';
                msg[6]='4';
                RadioMsg(msg);
                sprintf(m_log,"用户<%s>更改后视点",m_clients[m_index].addr);
                add_msg_log(mtg,m_log,0);
            }
            else if(sid==5)
            {
                mtg_measure_back(mtg);
            }
            else if(sid==6)
            {
                sscanf(cmd,"%%R1Q,53:6:%d,%lf,%lf\n",&i,&mtg->istn.stath,&mtg->istn.backh);
                mtg_setup(mtg);
            }
            else if(sid==7)
            {
                mtg_resetup(mtg);
            }
            else if(sid==8)
            {
                mtg_position_back(mtg);
            }
            else if(sid==9)
            {
                sscanf(cmd,"%%R1Q,53:9:%d,%lf,%lf,%lf\n",&i,&prism[0],&prism[1],&prism[2]);
                mtg_position_prism(mtg,prism);
            }
            else if(sid==10)
            {
                int turns=0;
                double prismh=0.0;
                sscanf(cmd,"%%R1Q,53:10:%d,%ld,%lf\n",&i,&turns,&prismh);
                mtg_measure_basket(mtg,0,prismh,turns);
            }
            else if(sid==11)
            {
                mtg_measure_prism(mtg);
            }
            else if(sid==12)
            {
                mtg_check_prism(mtg);
            }
            break;
        }
        case 0:     ///登录
        {
            //sscanf(cmd,"%%R1Q,0:%[^,],%[^\n]\n",uid,psw);
            for(i=0; i<ncli; i++)
            {
                if(strcmp(addr.IPAddress().mb_str(wxConvUTF8),m_clients[i].addr)==0)
                {
                    if(m_clients[i].sock && m_clients[i].sock!=sock)
                    {
                        m_clients[i].sock->Destroy();
                    }
                    m_clients[i].sock=sock;
                    m_clients[i].nbuf=0;
                    strcpy(m_clients[i].buffer,"\0");
                    sprintf(m_log,"用户<%s>登录",m_clients[i].addr);
                    add_msg_log(mtg,m_log,0);

                    sock->Write("%R1P,0:1\n",10);
                    break;
                }
                //strcpy(m_clients[i].addr,addr.IPAddress().mb_str(wxConvUTF8));
                //listClient->SetItem(i,2,addr.IPAddress());
            }

            if(i==ncli && ncli<MAX_CLI)
            {
                ncli++;
                if(m_clients[i].sock && m_clients[i].sock!=sock)
                {
                    m_clients[i].sock->Destroy();
                }
                m_clients[i].sock=sock;
                m_clients[i].nbuf=0;
                strcpy(m_clients[i].buffer,"\0");
                strcpy(m_clients[i].addr,addr.IPAddress().mb_str(wxConvUTF8));
                //listClient->SetItem(i,2,addr.IPAddress());
                sprintf(m_log,"用户<%s>登录",m_clients[i].addr);
                add_msg_log(mtg,m_log,0);
                sock->Write("%R1P,0:1\n",10);
            }
            else
            {
                sock->Write("%R1P,0:0\n",10);
            }
            break;
        }
        case 1:     ///取工程信息
        {
            sprintf(msg,"%%R1P,1:0:'%s',%lf,%lf,%d,%d,'%s','%s','%s','%s',%d,%d,%lf\n",
                mtg->prj.name,mtg->prj.mile1,mtg->prj.mile2,mtg->prj.a2z,mtg->ndty,mtg->duty[0].name,mtg->duty[1].name,
                mtg->duty[2].name,mtg->duty[3].name,mtg->prj.htip,mtg->prj.vtip,mtg->prj.tip);
            sock->Write(msg,strlen(msg));
            break;
        }
        case 2:     ///存工程信息 并广播
        {
            sscanf(cmd,"%%R1Q,2:0:'%[^']',%lf,%lf,%d,%d,'%[^']','%[^']','%[^']','%[^']',%d,%d,%lf\n",
                mtg->prj.name,&mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,mtg->duty[0].name,mtg->duty[1].name,
                mtg->duty[2].name,mtg->duty[3].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
            if(strlen(mtg->prj.name)==0)
            {
                sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'%[^']','%[^']','%[^']','%[^']',%d,%d,%lf\n",
                &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,mtg->duty[0].name,mtg->duty[1].name,
                mtg->duty[2].name,mtg->duty[3].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                if(strlen(mtg->duty[0].name)==0)
                {
                    sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','%[^']','%[^']','%[^']',%d,%d,%lf\n",
                    &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,mtg->duty[1].name,
                    mtg->duty[2].name,mtg->duty[3].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                    if(strlen(mtg->duty[1].name)==0)
                    {
                        sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','%[^']','%[^']',%d,%d,%lf\n",
                        &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,
                        mtg->duty[2].name,mtg->duty[3].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                        if(strlen(mtg->duty[2].name)==0)
                        {
                            sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','','%[^']',%d,%d,%lf\n",
                            &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,
                            mtg->duty[3].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            if(strlen(mtg->duty[3].name)==0)
                            {
                                sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','','',%d,%d,%lf\n",
                                &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            }
                        }
                        else
                        {
                            if(strlen(mtg->duty[3].name)==0)
                            {
                                sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','%[^']','',%d,%d,%lf\n",
                                &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,mtg->duty[2].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            }
                        }
                    }
                    else
                    {
                        if(strlen(mtg->duty[2].name)==0)
                        {
                            sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','','%[^']',%d,%d,%lf\n",
                            &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,
                            mtg->duty[3].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            if(strlen(mtg->duty[3].name)==0)
                            {
                                sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','','',%d,%d,%lf\n",
                                &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            }
                        }
                        else
                        {
                            if(strlen(mtg->duty[3].name)==0)
                            {
                                sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','%[^']','',%d,%d,%lf\n",
                                &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,mtg->duty[2].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            }
                        }
                    }
                }
            }
            else
            {
                if(strlen(mtg->duty[0].name)==0)
                {
                    sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','%[^']','%[^']','%[^']',%d,%d,%lf\n",
                    &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,mtg->duty[1].name,
                    mtg->duty[2].name,mtg->duty[3].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                    if(strlen(mtg->duty[1].name)==0)
                    {
                        sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','%[^']','%[^']',%d,%d,%lf\n",
                        &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,
                        mtg->duty[2].name,mtg->duty[3].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                        if(strlen(mtg->duty[2].name)==0)
                        {
                            sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','','%[^']',%d,%d,%lf\n",
                            &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,
                            mtg->duty[3].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            if(strlen(mtg->duty[3].name)==0)
                            {
                                sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','','',%d,%d,%lf\n",
                                &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            }
                        }
                        else
                        {
                            if(strlen(mtg->duty[3].name)==0)
                            {
                                sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','%[^']','',%d,%d,%lf\n",
                                &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,mtg->duty[2].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            }
                        }
                    }
                    else
                    {
                        if(strlen(mtg->duty[2].name)==0)
                        {
                            sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','','%[^']',%d,%d,%lf\n",
                            &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,
                            mtg->duty[3].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            if(strlen(mtg->duty[3].name)==0)
                            {
                                sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','','',%d,%d,%lf\n",
                                &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            }
                        }
                        else
                        {
                            if(strlen(mtg->duty[3].name)==0)
                            {
                                sscanf(cmd,"%%R1Q,2:0:'',%lf,%lf,%d,%d,'','','%[^']','',%d,%d,%lf\n",
                                &mtg->prj.mile1,&mtg->prj.mile2,&mtg->prj.a2z,&mtg->ndty,mtg->duty[2].name,&mtg->prj.htip,&mtg->prj.vtip,&mtg->prj.tip);
                            }
                        }
                    }
                }
            }

            mtg_store_prj(mtg);
            strcpy(msg,cmd);
            msg[3]='D';
            msg[5]='3';
            sock->Write("%R1P,2:1\n",10);
            RadioMsg(msg);
            sprintf(m_log,"用户<%s>修改了工程信息",m_clients[m_index].addr);
            add_msg_log(mtg,m_log,0);
            break;
        }
        case 4:     ///取中线
        {
            ///要素个数
            int nh,nv,nho,nvo,nmo;
            h_element *he;
            v_element *ve;
            h_offset  *ho;
            v_offset  *vo;
            m_offset  *mo;
            nh = road_number_horizon(&mtg->r);
            nv = road_number_vertical(&mtg->r);
            nho = road_number_horizon_off(&mtg->r);
            nvo = road_number_vertical_off(&mtg->r);
            nmo = road_number_mile_off(&mtg->r);
            sprintf(msg,"%%R1P,4:0:%d,%d,%d,%d,%d\n",nh,nv,nho,nvo,nmo);
            sock->Write(msg,strlen(msg));
            ///平曲线要素
            for(i=0; i<nh; i++)
            {
                he = road_horizon(&mtg->r,i);
                sprintf(msg,"%%R1P,4:1:%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d,%f\n",
                i,he->type,he->radius,he->rou1,he->rou2,he->x1,he->y1,he->x2,he->y2,he->angle1,he->angle2,he->l1,
                he->length,he->pz,he->deta);
                sock->Write(msg,strlen(msg));
            }
            ///竖曲线
            for(i=0; i<nv; i++)
            {
                ve = road_vertical(&mtg->r,i);
                sprintf(msg,"%%R1P,4:2:%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%d,%f\n",
                        i,ve->type,ve->radius,ve->l1,ve->h1,ve->l2,ve->h2,ve->angle1,ve->angle2,ve->length,ve->pz,ve->deta);
                sock->Write(msg,strlen(msg));
            }
            ///横偏
            for(i=0; i<nho; i++)
            {
                ho = road_horizon_off(&mtg->r,i);
                sprintf(msg,"%%R1P,4:3:%d,%f,%f\n",i,ho->mile,ho->off);
                sock->Write(msg,strlen(msg));
            }
            ///纵偏
            for(i=0; i<nvo; i++)
            {
                vo = road_vertical_off(&mtg->r,i);
                sprintf(msg,"%%R1P,4:4:%d,%f,%f\n",i,vo->mile,vo->off);
                sock->Write(msg,strlen(msg));
            }
            ///短链
            for(i=0; i<nmo; i++)
            {
                mo = road_mile_off(&mtg->r,i);
                sprintf(msg,"%%R1P,4:5:%d,%f,%f\n",i,mo->mile,mo->off);
                sock->Write(msg,strlen(msg));
            }
            break;
        }
        case 5:     ///存中线数据 并广播
        {
            if(mtg->opera != MTG_OPERA_NONE)
            {
                sock->Write("%R1P,5:0\n",10);break;
            }
            h_element he;
            v_element ve;
            h_offset ho;
            v_offset vo;
            m_offset mo;
            if(sid==0)
            {
                ///是否在存中线过程中
                if(nr[0]!=0 || nr[1]!=0 || nr[2]!=0 || nr[3]!=0 || nr[4]!=0)
                {
                    sock->Write("%R1P,5:0\n",10);
                    return;
                }
                sscanf(cmd,"%%R1Q,5:0:%d,%d,%d,%d,%d\n",&nr[0],&nr[1],&nr[2],&nr[3],&nr[4]);
                road_init(&r);
                road_clear_horizon(&r);
                road_clear_vertical(&r);
                road_clear_horizon_off(&r);
                road_clear_vertical_off(&r);
                road_clear_mile_off(&r);
            }
            else if(sid==1) ///平曲线
            {
                sscanf(cmd,"%%R1Q,5:1:%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d\n",
                   &i,&he.type,&he.l1,&he.length,&he.angle1,&he.angle2,&he.radius,
                   &he.rou1,&he.rou2,&he.x1,&he.y1,&he.x2,&he.y2,&he.pz);
                road_insert_horizon(&r,&he,i);
                road_apply_horizon(&r);
                nr[0]--;
            }
            else if(sid==2) ///竖曲线
            {
                sscanf(cmd,"%%R1Q,5:2:%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d\n",
                   &i,&ve.type,&ve.l1,&ve.h1,&ve.l2,&ve.h2,
                   &ve.length,&ve.radius,&ve.angle1,&ve.angle2,&ve.pz);
                road_insert_vertical(&r,&ve,i);
                road_apply_vertical(&r);
                nr[1]--;
            }
            else if(sid==3) ///横偏
            {
                sscanf(cmd,"%%R1Q,5:3:%d,%lf,%lf\n",&i,&ho.mile,&ho.off);
                road_insert_horizon_off(&r,&ho);
                nr[2]--;
            }
            else if(sid==4) ///纵偏
            {
                sscanf(cmd,"%%R1Q,5:4:%d,%lf,%lf\n",&i,&vo.mile,&vo.off);
                road_insert_vertical_off(&r,&vo);
                nr[3]--;
            }
            else if(sid==5) ///短链
            {
                sscanf(cmd,"%%R1Q,5:5:%d,%lf,%lf\n",&i,&mo.mile,&mo.off);
                road_insert_mile_off(&r,&mo);
                nr[4]--;
            }
            if(nr[0]==0 && nr[1]==0 && nr[2]==0 && nr[3]==0 && nr[4]==0)   ///保存完毕 并广播
            {
                ///要素个数
                int nh,nv,nho,nvo,nmo;
                road_clear_horizon(&mtg->r);
                road_clear_vertical(&mtg->r);
                road_clear_horizon_off(&mtg->r);
                road_clear_vertical_off(&mtg->r);
                road_clear_mile_off(&mtg->r);

                nh = road_number_horizon(&r);
                nv = road_number_vertical(&r);
                nho = road_number_horizon_off(&r);
                nvo = road_number_vertical_off(&r);
                nmo = road_number_mile_off(&r);
                sprintf(msg,"%%R1D,6:0:%d,%d,%d,%d,%d\n",nh,nv,nho,nvo,nmo);
                RadioMsg(msg);
                ///平曲线要素
                for(i=0; i<nh; i++)
                {
                    he = *(road_horizon(&r,i));
                    road_insert_horizon(&mtg->r,&he,i);
                    road_apply_horizon(&mtg->r);
                    sprintf(msg,"%%R1D,6:1:%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d\n",
                            i,he.type,he.l1,he.length,he.angle1,he.angle2,
                            he.radius,he.rou1,he.rou2,he.x1,he.y1,he.x2,he.y2,he.pz);
                    RadioMsg(msg);
                }
                ///竖曲线
                for(i=0; i<nv; i++)
                {
                    ve = *(road_vertical(&r,i));
                    road_insert_vertical(&mtg->r,&ve,i);
                    road_apply_vertical(&mtg->r);
                    sprintf(msg,"%%R1D,6:2:%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%d\n",
                            i,ve.type,ve.l1,ve.h1,ve.l2,ve.h2,
                            ve.length,ve.radius,ve.angle1,ve.angle2,ve.pz);
                    RadioMsg(msg);
                }
                ///横偏
                for(i=0; i<nho; i++)
                {
                    ho = *(road_horizon_off(&r,i));
                    road_insert_horizon_off(&mtg->r,&ho);
                    sprintf(msg,"%%R1P,6:3:%d,%f,%f\n",i,ho.mile,ho.off);
                    RadioMsg(msg);
                }
                ///纵偏
                for(i=0; i<nvo; i++)
                {
                    vo = *(road_vertical_off(&r,i));
                    road_insert_vertical_off(&mtg->r,&vo);
                    sprintf(msg,"%%R1P,6:4:%d,%f,%f\n",i,vo.mile,vo.off);
                    RadioMsg(msg);
                }
                ///短链
                for(i=0; i<nmo; i++)
                {
                    mo = *(road_mile_off(&r,i));
                    road_insert_mile_off(&mtg->r,&mo);
                    sprintf(msg,"%%R1P,6:5:%d,%f,%f\n",i,mo.mile,mo.off);
                    RadioMsg(msg);
                }
                sprintf(m_log,"用户<%s>修改了中线数据",m_clients[m_index].addr);
                add_msg_log(mtg,m_log,0);
                mtg_store_road(mtg);
            }
            break;
        }
        case 7:     ///取零位
        {
            sprintf(msg,"%%R1P,7:0:%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                    %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                    %lf,%lf,%lf,%lf,%lf,%d,%ld,%ld,%ld,%d,%lf,%lf,%lf,%lf,%lf,%lf\n",
                 mtg->m0.inc[0],mtg->m0.inc[1],mtg->m0.inc[2],mtg->m0.inc[3],
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
                 mtg->m0.faj[0],mtg->m0.faj[1],mtg->m0.faj[2],mtg->m0.faj[3],
                 mtg->m0.baj[0],mtg->m0.baj[1],mtg->m0.baj[2],mtg->m0.baj[3],
                 mtg->m0.aj[0],mtg->m0.aj[1],mtg->m0.aj[2],mtg->m0.aj[3],
                 mtg->m0.inc1[0],mtg->m0.inc1[1],mtg->m0.inc1[2],
                 mtg->m0.iseg,(long)mtg->m0.t1,(long)mtg->m0.t2,(long)mtg->m0.t3,mtg->m0.iset,
                 mtg->mp.prism[0],mtg->mp.prism[1],mtg->mp.prism[2],mtg->mp.prism[3],mtg->mp.prism[4],mtg->mp.prism[5]
                 );
            sock->Write(msg,strlen(msg));

            break;
        }
        case 8:     ///存零位 并广播
        {
            if(mtg->opera != MTG_OPERA_NONE)
            {
                sock->Write("%R1P,8:0\n",10);break;
            }
            sscanf(cmd,"%%R1Q,8:0:%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
               %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
               %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%ld,%ld,%ld,%d\n",
             &mtg->m0.inc[0],&mtg->m0.inc[1],&mtg->m0.inc[1],
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
             &mtg->m0.faj[0],&mtg->m0.faj[1],&mtg->m0.faj[2],&mtg->m0.faj[3],
             &mtg->m0.baj[0],&mtg->m0.baj[1],&mtg->m0.baj[2],&mtg->m0.baj[3],
             &mtg->m0.aj[0],&mtg->m0.aj[1],&mtg->m0.aj[2],&mtg->m0.aj[3],
             &mtg->m0.inc1[0],&mtg->m0.inc1[1],&mtg->m0.inc1[2],
             &mtg->m0.iseg,&mtg->m0.t1,&mtg->m0.t2,&mtg->m0.t3,&mtg->m0.iset
             );

            sprintf(m_log,"用户<%s>修改了零位数据",m_clients[m_index].addr);
            add_msg_log(mtg,m_log,0);
            mtg_store_origin(mtg);
            sock->Write("%R1P,8:1\n",10);
            strcpy(msg,cmd);
            msg[3]='D';
            msg[5]='9';
            RadioMsg(msg);
        }
        case 10:    ///取设置
        {
            sprintf(msg,"%%R1P,10:0:%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\
            %d,%d,%lf,%lf,%d\n",
            mtg->iset.cyc,mtg->iset.bcyc,mtg->iset.palw,mtg->iset.jalw,mtg->iset.balw,mtg->iset.talw,
            mtg->iset.vibration,mtg->iset.rstn,mtg->iset.tsyn,mtg->iset.rget,mtg->iset.idrv,mtg->iset.prun,mtg->iset.pend,
            mtg->iset.psas,mtg->iset.pchk,mtg->iset.pqry,mtg->iset.pmap,mtg->iset.psmr,mtg->iset.pquit,mtg->iset.unit,
            mtg->iset.vmileage,mtg->iset.head,mtg->iset.tbm3d,mtg->iset.trend,mtg->iset.povr,mtg->iset.jovr,mtg->iset.tovr,
            mtg->iset.bovr,mtg->iset.toEr,mtg->iset.flen,mtg->iset.fdev,mtg->iset.lang);
            sock->Write(msg,strlen(msg));
            break;
        }
        case 11:    ///存设置 并广播
        {
            if(mtg->opera != MTG_OPERA_NONE)
            {
                sock->Write("%R1P,11:0\n",11);break;
            }
            sscanf(cmd,"%%R1Q,11:0:%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%lf,%lf,%d\n",
                &mtg->iset.cyc,&mtg->iset.bcyc,&mtg->iset.palw,&mtg->iset.jalw,&mtg->iset.balw,&mtg->iset.talw,
                &mtg->iset.vibration,&mtg->iset.rstn,&mtg->iset.tsyn,&mtg->iset.rget,&mtg->iset.idrv,&mtg->iset.prun,&mtg->iset.pend,
                &mtg->iset.psas,&mtg->iset.pchk,&mtg->iset.pqry,&mtg->iset.pmap,&mtg->iset.psmr,&mtg->iset.pquit,&mtg->iset.unit,
                &mtg->iset.vmileage,&mtg->iset.head,&mtg->iset.tbm3d,&mtg->iset.trend,&mtg->iset.povr,&mtg->iset.jovr,&mtg->iset.tovr,
                &mtg->iset.bovr,&mtg->iset.toEr,&mtg->iset.flen,&mtg->iset.fdev,&mtg->iset.lang);
            sprintf(m_log,"用户<%s>修改了工程设置",m_clients[m_index].addr);
            add_msg_log(mtg,m_log,0);
            mtg_store_sets(mtg);
            sock->Write("%R1P,11:1\n",11);
            strcpy(msg,cmd);
            msg[3]='D';
            msg[6]='2';
            RadioMsg(msg);
            break;
        }
        case 13:    ///取关键区域
        {
            sprintf(msg,"%%R1P,13:0:%d\n",mtg->nks);
            sock->Write(msg,strlen(msg));
            for(i=0; i<mtg->nks; i++)
            {
                sprintf(msg,"%%R1P,13:1:%d,'%s',%lf,%lf\n",i,mtg->keys[i].name,mtg->keys[i].mile1,mtg->keys[i].mile2);
                sock->Write(msg,strlen(msg));
            }
            break;
        }
        case 14:    ///存关键区域并广播
        {
            if(sid==0)
            {
                i=0;
                sscanf(cmd,"%%R1Q,14:0:%d",&i);
                if(i>0)
                {
                    mtg->keys=(MTG_KEY*)malloc(i*sizeof(MTG_KEY));
                    mtg->nks=i;
                    strcpy(msg,cmd);
                    msg[3]='D';
                    msg[6]='5';
                    RadioMsg(msg);
                }
            }
            else
            {
                memset(mtg->keys[i].name,0,64);
                sscanf(cmd,"%%R1Q,14:1:%d,'%[^']',%lf,%lf\n",&i,mtg->keys[i].name,&mtg->keys[i].mile1,&mtg->keys[i].mile2);
                if(strlen(mtg->keys[i].name)==0)
                sscanf(cmd,"%%R1Q,14:1:%d,'',%lf,%lf\n",&i,&mtg->keys[i].mile1,&mtg->keys[i].mile2);
                strcpy(msg,cmd);
                msg[3]='D';
                msg[6]='5';
                RadioMsg(msg);
                if(i==mtg->nks-1)
                {
                    sprintf(m_log,"用户<%s>修改了关键区域",m_clients[m_index].addr);
                    add_msg_log(mtg,m_log,0);
                    mtg_store_keys(mtg);
                    sock->Write("%R1P,14:1\n",11);
                }
            }
            break;
        }
        case 16:    ///取盾构参数
        {
            sprintf(msg,"%%R1P,16:0:'%s',%d,%d,\
                %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,\
                %d,%.12f,%.12f,%.12f,%.12f,%d,\
                %d,%.12f,%.12f,%.12f,%.12f,%d\n",
                mtg->tbm.name,mtg->tbm.type,mtg->tbm.mode,
                mtg->tbm.D[0],mtg->tbm.D[1],mtg->tbm.D[2],mtg->tbm.D[3],mtg->tbm.D[4],mtg->tbm.D[5],mtg->tbm.L[0],mtg->tbm.L[1],mtg->tbm.L[2],mtg->tbm.L[3],mtg->tbm.L[4],mtg->tbm.L[5],
                mtg->tbm.L[6],mtg->tbm.L[7],mtg->tbm.L[8],mtg->tbm.naj,mtg->tbm.aj[0],mtg->tbm.aj[1],mtg->tbm.aj[2],mtg->tbm.aj[3],mtg->tbm.aj[4],mtg->tbm.aj[5],mtg->tbm.aunit,
                mtg->tbm.nbj,mtg->tbm.bj[0],mtg->tbm.bj[1],mtg->tbm.bj[2],mtg->tbm.bj[3],mtg->tbm.bunit,
                mtg->tbm.nfj,mtg->tbm.fj[0],mtg->tbm.fj[1],mtg->tbm.fj[2],mtg->tbm.fj[3],mtg->tbm.funit
             );
            sock->Write(msg,strlen(msg));
            break;
        }
        case 17:    ///存储盾构机设置并广播
        {
            sscanf(cmd,"%%R1Q,17:0:'%[^']',%d,%d,\
                %lf,%lf,%lf,%lf,%lf,%lf,\
                %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,\
                %d,%lf,%lf,%lf,%lf,%d,\
                %d,%lf,%lf,%lf,%lf,%d\n",mtg->tbm.name,&mtg->tbm.type,&mtg->tbm.mode,
                &mtg->tbm.D[0],&mtg->tbm.D[1],&mtg->tbm.D[2],&mtg->tbm.D[3],&mtg->tbm.D[4],&mtg->tbm.D[5],&mtg->tbm.L[0],&mtg->tbm.L[1],&mtg->tbm.L[2],&mtg->tbm.L[3],&mtg->tbm.L[4],&mtg->tbm.L[5],
                &mtg->tbm.L[6],&mtg->tbm.L[7],&mtg->tbm.L[8],&mtg->tbm.naj,&mtg->tbm.aj[0],&mtg->tbm.aj[1],&mtg->tbm.aj[2],&mtg->tbm.aj[3],&mtg->tbm.aj[4],&mtg->tbm.aj[5],&mtg->tbm.aunit,
                &mtg->tbm.nbj,&mtg->tbm.bj[0],&mtg->tbm.bj[1],&mtg->tbm.bj[2],&mtg->tbm.bj[3],&mtg->tbm.bunit,
                &mtg->tbm.nfj,&mtg->tbm.fj[0],&mtg->tbm.fj[1],&mtg->tbm.fj[2],&mtg->tbm.fj[3],&mtg->tbm.funit
                );
            if(strlen(mtg->prj.name)==0)
            sscanf(cmd,"%%R1Q,17:0:'',%d,%d,\
                %lf,%lf,%lf,%lf,%lf,%lf,\
                %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,\
                %d,%lf,%lf,%lf,%lf,%d,\
                %d,%lf,%lf,%lf,%lf,%d\n",&mtg->tbm.type,&mtg->tbm.mode,
                &mtg->tbm.D[0],&mtg->tbm.D[1],&mtg->tbm.D[2],&mtg->tbm.D[3],&mtg->tbm.D[4],&mtg->tbm.D[5],&mtg->tbm.L[0],&mtg->tbm.L[1],&mtg->tbm.L[2],&mtg->tbm.L[3],&mtg->tbm.L[4],&mtg->tbm.L[5],
                &mtg->tbm.L[6],&mtg->tbm.L[7],&mtg->tbm.L[8],&mtg->tbm.naj,&mtg->tbm.aj[0],&mtg->tbm.aj[1],&mtg->tbm.aj[2],&mtg->tbm.aj[3],&mtg->tbm.aj[4],&mtg->tbm.aj[5],&mtg->tbm.aunit,
                &mtg->tbm.nbj,&mtg->tbm.bj[0],&mtg->tbm.bj[1],&mtg->tbm.bj[2],&mtg->tbm.bj[3],&mtg->tbm.bunit,
                &mtg->tbm.nfj,&mtg->tbm.fj[0],&mtg->tbm.fj[1],&mtg->tbm.fj[2],&mtg->tbm.fj[3],&mtg->tbm.funit
                );
            sprintf(m_log,"用户<%s>修改了盾构参数",m_clients[m_index].addr);
            add_msg_log(mtg,m_log,0);
            mtg_store_tbmset(mtg);
            sock->Write("%R1P,17:1\n",11);
            strcpy(msg,cmd);
            msg[3]='D';
            msg[6]='8';
            RadioMsg(msg);
            break;
        }
        case 19:    ///取激光靶参数
        {
            sprintf(msg,"%%R1P,19:0:%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%d,%d,%d,%d\n",
                mtg->tarset.ver,mtg->tarset.prism[0],mtg->tarset.prism[1],mtg->tarset.prism[2],mtg->tarset.prism[3],mtg->tarset.prism[4],mtg->tarset.prism[5],
                mtg->tarset.prism[6],mtg->tarset.prism[7],mtg->tarset.prism[8],mtg->tarset.prc,mtg->tarset.length,mtg->tarset.cam,mtg->tarset.inc,mtg->tarset.ipos,mtg->tarset.pos
             );
            sock->Write(msg,strlen(msg));
            break;
        }
        case 20:    ///存储激光靶参数并广播
        {
            sscanf(cmd,"%%R1Q,20:0:%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,%d,%d\n",
                &mtg->tarset.ver,&mtg->tarset.prism[0],&mtg->tarset.prism[1],&mtg->tarset.prism[2],&mtg->tarset.prism[3],&mtg->tarset.prism[4],&mtg->tarset.prism[5],
                &mtg->tarset.prism[6],&mtg->tarset.prism[7],&mtg->tarset.prism[8],&mtg->tarset.prc,&mtg->tarset.length,&mtg->tarset.cam,&mtg->tarset.inc,&mtg->tarset.ipos,&mtg->tarset.pos);
            sprintf(m_log,"用户<%s>修改了激光靶参数",m_clients[m_index].uid);
            add_msg_log(mtg,m_log,0);
            mtg_store_tars(mtg);
            sock->Write("%R1P,20:1\n",11);
            strcpy(msg,cmd);
            msg[3]='D';
            msg[5]='2';
            msg[6]='1';
            RadioMsg(msg);
            break;
        }
        case 22:    ///取相机参数
        {
            for(i=0;i<2;i++)
            {
                sprintf(msg,"%%R1P,22:0:%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                    %d,%d,%d,%d,'%s'\n",
                    i,mtg->camset[i].w,mtg->camset[i].h,mtg->camset[i].affine[0],mtg->camset[i].affine[1],mtg->camset[i].affine[2],
                    mtg->camset[i].affine[3],mtg->camset[i].affine[4],mtg->camset[i].affine[5],
                    mtg->camset[i].affine[6],mtg->camset[i].affine[7],mtg->camset[i].affine[8],
                    mtg->camset[i].x1,mtg->camset[i].y1,mtg->camset[i].x2,mtg->camset[i].y2,mtg->camset[i].name);
                sock->Write(msg,strlen(msg));
            }
            break;
        }
        /*case 23:
        {
            sscanf(cmd,"%%R1Q,23:0:%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                %d,%d,%d,%d,'%s'\n",
                &i,&mtg->camset[i].w,&mtg->camset[i].h,&mtg->camset[i].affine[0],&mtg->camset[i].affine[1],&mtg->camset[i].affine[2],
                &mtg->camset[i].affine[3],&mtg->camset[i].affine[4],&mtg->camset[i].affine[5],
                &mtg->camset[i].affine[6],&mtg->camset[i].affine[7],&mtg->camset[i].affine[8],
                &mtg->camset[i].x1,&mtg->camset[i].y1,&mtg->camset[i].x2,&mtg->camset[i].y2,mtg->camset[i].name);
            if(i==1)
            {
                sprintf(m_log,"用户<%s>修改了激光靶配置文件",m_clients[m_index].uid);
                add_msg_log(mtg,m_log,0);
                mtg_store_camset(mtg);
                sock->Write("%R1P,23:1\n",11);
                strcpy(msg,cmd);
                msg[3]='D';
                msg[6]='4';
                RadioMsg(msg);
                FILE* fp=fopen("D://decode.log","w");
                fprintf(fp,"ssssss\n",fp);
                fflush(fp);fclose(fp);
            }
            break;
        }*/
        case 25:    ///取全站仪参数
        {
            sprintf(msg,"%%R1P,25:0:%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%d\n",
                mtg->tps.type,mtg->tps.lasertype,mtg->tps.laserheight,mtg->tps.laserdist[0],mtg->tps.laserdist[1],
                mtg->tps.laserx[0],mtg->tps.lasery[0],mtg->tps.laserx[1],mtg->tps.lasery[1],mtg->tps.edm,mtg->tps.comp);
            sock->Write(msg,strlen(msg));
            break;
        }
        case 26:    ///存储全站仪参数并广播
        {
            sscanf(cmd,"%%R1Q,26:0:%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d\n",
                &mtg->tps.type,&mtg->tps.lasertype,&mtg->tps.laserheight,&mtg->tps.laserdist[0],&mtg->tps.laserdist[1],
                &mtg->tps.laserx[0],&mtg->tps.lasery[0],&mtg->tps.laserx[1],&mtg->tps.lasery[1],&mtg->tps.edm,&mtg->tps.comp);
            sprintf(m_log,"用户<%s>修改了全站仪参数",m_clients[m_index].uid);
            add_msg_log(mtg,m_log,0);
            mtg_store_tps(mtg);
            sock->Write("%R1P,26:1\n",11);
            strcpy(msg,cmd);
            msg[3]='D';
            msg[6]='7';
            RadioMsg(msg);
            break;
        }
        case 28:    ///取管环参数
        {
            sprintf(msg,"%%R1P,28:0:%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%d,%.12f,%.12f,%d\n",
                mtg->segset.type,mtg->segset.in,mtg->segset.f2b,mtg->segset.l2s,
                mtg->segset.L,mtg->segset.De,mtg->segset.D,mtg->segset.Ks,mtg->segset.G0,mtg->segset.G1,mtg->segset.s2s
            );
            sock->Write(msg,strlen(msg));
            break;
        }
        case 29:    ///存储管环参数并广播
        {
            sscanf(msg,"%%R1Q,29:0:%d,%d,%d,%lf,%lf,%lf,%lf,%d,%lf,%lf,%d\n",
                &mtg->segset.type,&mtg->segset.in,&mtg->segset.f2b,&mtg->segset.l2s,
                &mtg->segset.L,&mtg->segset.De,&mtg->segset.D,&mtg->segset.Ks,&mtg->segset.G0,&mtg->segset.G1,&mtg->segset.s2s
            );
            sprintf(m_log,"用户<%s>修改了全站仪参数",m_clients[m_index].uid);
            add_msg_log(mtg,m_log,0);
            mtg_store_segset(mtg);
            sock->Write("%R1P,29:1\n",11);
            strcpy(msg,cmd);
            msg[3]='D';
            msg[6]='3';
            msg[6]='0';
            RadioMsg(msg);
            break;
        }
        case 31:    ///取管块参数
        {
            sprintf(msg,"%%R1P,31:0:%d\n",mtg->nblk);
            sock->Write(msg,strlen(msg));
            for(i=0;i<mtg->nblk;i++)
            {
                sprintf(msg,"%%R1P,31:1:%d,'%s',%lf\n",i,mtg->blocks[i].name,mtg->blocks[i].angle);
                sock->Write(msg,strlen(msg));
            }
            break;
        }
        case 32:
        {
            if(sid==0)
            {
                i=0;
                sscanf(cmd,"%%R1Q,32:0:%d",&i);
                if(i>0)
                {
                    mtg->blocks=(MTG_BLOCK*)malloc(i*sizeof(MTG_BLOCK));
                    mtg->nblk=i;
                    strcpy(msg,cmd);
                    msg[3]='D';
                    msg[6]='3';
                    RadioMsg(msg);
                }
            }
            else
            {
                sscanf(cmd,"%%R1Q,32:1:%d,'%[^']',%lf\n",&i,mtg->blocks[i].name,&mtg->blocks[i].angle);
                if(strlen(mtg->blocks[i].name)==0)
                sscanf(cmd,"%%R1Q,32:1:%d,'',%lf\n",&i,&mtg->blocks[i].angle);
                strcpy(msg,cmd);
                msg[3]='D';
                msg[6]='3';
                RadioMsg(msg);

                if(i==mtg->nblk-1)
                {
                    sprintf(m_log,"用户<%s>修改了管快参数",m_clients[m_index].addr);
                    add_msg_log(mtg,m_log,0);
                    mtg_store_block(mtg);
                    sock->Write("%R1P,32:1\n",11);
                }
            }
            break;
        }
        case 34:    ///取管环监测参数
        {
            sprintf(msg,"%%R1P,34:0:%d,%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%ld,%.12f,%.12f\n",
            mtg->smonitor.number,mtg->smonitor.monitor,mtg->smonitor.cycle,mtg->smonitor.last,mtg->smonitor.iseg,mtg->smonitor.headc,mtg->smonitor.x0,mtg->smonitor.y0,mtg->smonitor.z0,
            mtg->smonitor.x,mtg->smonitor.y,mtg->smonitor.z,(long)mtg->smonitor.t,mtg->smonitor.dv,mtg->smonitor.dv1);
            sock->Write(msg,strlen(msg));
            break;
        }
        case 35:    ///存储管环监测并广播
        {
            sscanf(cmd,"%%R1Q,35:0:%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,%ld,%lf,%lf\n",
            &mtg->smonitor.number,&mtg->smonitor.monitor,&mtg->smonitor.cycle,&mtg->smonitor.last,&mtg->smonitor.iseg,&mtg->smonitor.headc,&mtg->smonitor.x0,&mtg->smonitor.y0,&mtg->smonitor.z0,
            &mtg->smonitor.x,&mtg->smonitor.y,&mtg->smonitor.z,&t1,&mtg->smonitor.dv,&mtg->smonitor.dv1);
            mtg->smonitor.t=t1;
            sprintf(m_log,"用户<%s>修改了管环监测参数",m_clients[m_index].addr);
            add_msg_log(mtg,m_log,0);
            mtg_store_block(mtg);
            sock->Write("%R1P,35:1\n",11);
            strcpy(msg,cmd);
            msg[3]='D';
            msg[6]='6';
            RadioMsg(msg);
            break;
        }
        case 40:    ///取用户
        {
            sprintf(msg,"%%R1P,40:0:%d\n",mtg->nuser);
            sock->Write(msg,strlen(msg));
            for(i=0; i<mtg->nuser; i++)
            {
                sprintf(msg,"%%R1P,40:1:%d,'%s','%s',%d\n",i,mtg->user[i].name,mtg->user[i].password,mtg->user[i].level);
                sock->Write(msg,strlen(msg));
            }
            break;
        }
        case 41:    ///存密码 并广播
        {
            if(sid==0)
            {
                i=0;
                sscanf(cmd,"%%R1Q,41:0:%d",&i);
                if(i>0)
                {
                    mtg->user=(MTG_USER*)malloc(i*sizeof(MTG_USER));
                    mtg->nuser=i;
                    strcpy(msg,cmd);
                    msg[3]='D';
                    msg[6]='2';
                    RadioMsg(msg);
                }
            }
            else
            {
                sscanf(cmd,"%%R1Q,41:1:%d,'%[^']','%[^']',%d\n",&i,mtg->user[i].name,mtg->user[i].password,&mtg->user[i].level);
                if(strlen(mtg->user[i].name)==0)
                {
                    sscanf(msg,"%%R1Q,41:1:%d,'','%[^']',%d\n",&i,mtg->user[i].password,&mtg->user[i].level);
                    if(strlen(mtg->user[i].password)==0) sscanf(msg,"%%R1Q,41:1:%d,'','',%d\n",&i,&mtg->user[i].level);
                }
                else
                {
                    if(strlen(mtg->user[i].password)==0) sscanf(msg,"%%R1Q,41:1:%d,'%[^']','',%d\n",&i,mtg->user[i].name,&mtg->user[i].level);
                }
                strcpy(msg,cmd);
                msg[3]='D';
                msg[6]='2';
                RadioMsg(msg);
                if(i==mtg->nuser-1)
                {
                    sprintf(m_log,"用户<%s>修改了用户",m_clients[m_index].uid);
                    add_msg_log(mtg,m_log,0);
                    mtg_store_user(mtg);
                    sock->Write("%R1P,41:1\n",11);
                }
            }

            break;
        }
        case 43:    ///取吊篮
        {
            sprintf(msg,"%%R1P,43:0:%d\n",mtg->nbsk);
            sock->Write(msg,strlen(msg));
            for(i=0;i<mtg->nbsk;i++)
            {
                sprintf(msg,"%%R1P,43:1:%d,'%s',%lf,%lf,%lf,%ld\n",
                    i,mtg->bask[i].name,mtg->bask[i].x,mtg->bask[i].y,mtg->bask[i].z,(long)mtg->bask[i].t);
                sock->Write(msg,strlen(msg));
            }

            break;
        }
        case 44:    ///存吊篮 并广播
        {
            if(sid==0)
            {
                i=0;
                sscanf(cmd,"%%R1Q,44:0:%d",&i);
                if(i>0)
                {
                    mtg->bask=(MTG_BASKET*)malloc(i*sizeof(MTG_BASKET));
                    mtg->nbsk=i;
                    strcpy(msg,cmd);
                    msg[3]='D';
                    msg[6]='5';
                    RadioMsg(msg);
                }
            }
            else
            {
                sscanf(msg,"%%R1Q,44:1:%d,'%[^']',%lf,%lf,%lf,%ld\n",&i,mtg->bask[i].name,&mtg->bask[i].x,&mtg->bask[i].y,&mtg->bask[i].z,&t1);
                if(strlen(mtg->bask[i].name)==0)
                    sscanf(msg,"%%R1Q,44:1:%d,'',%lf,%lf,%lf,%ld\n",&i,&mtg->bask[i].x,&mtg->bask[i].y,&mtg->bask[i].z,&t1);
                mtg->bask[i].t=t1;
                strcpy(msg,cmd);
                msg[3]='D';
                msg[6]='5';
                RadioMsg(msg);
                if(i==mtg->nbsk-1)
                {
                    sprintf(m_log,"用户<%s>修改了吊篮",m_clients[m_index].uid);
                    add_msg_log(mtg,m_log,0);
                    mtg_store_basket(mtg);
                    sock->Write("%R1P,44:1\n",11);
                }
            }
            break;
        }
        case 46:    ///测站查询
        {
            int num=0;
            MTG_STATION* qs;
            qs=0;
            num = mtg_query_station(mtg,&qs);
            sprintf(msg,"%%R1P,46:0:%d\n",num);
            sock->Write(msg,strlen(msg));
            for(i=0;i<num;i++)
            {
                sprintf(msg,"%%R1P,46:1:%d,'%s','%s',%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\
                        %lf,%lf,%lf,%lf,%ld\n",
                        i,qs[i].stat,qs[i].back,qs[i].statx,qs[i].staty,qs[i].statz,qs[i].stath,
                        qs[i].backx,qs[i].backy,qs[i].backz,qs[i].backh,qs[i].backx1,qs[i].backy1,qs[i].backz1,
                        qs[i].headh[0],qs[i].headh[1],qs[i].headv[0],qs[i].headv[1],qs[i].midh[0],qs[i].midh[1],
                        qs[i].midv[0],qs[i].midv[1],qs[i].tailh[0],qs[i].tailh[1],qs[i].tailv[0],qs[i].tailv[1],qs[i].azi[0],qs[i].azi[1],
                        qs[i].pitch[0],qs[i].pitch[1],qs[i].roll[0],qs[i].roll[1],(long)qs[i].t
                        );
                sock->Write(msg,strlen(msg));
                //trace(0,"client: msg=%s\n",msg);
            }
            if(num>0) free(qs);
            break;
        }
        case 47:     ///测站修改
        {

            break;
        }
        case 48:     ///取测站
        {
            sprintf(msg,"%%R1P,48:0:'%s','%s',%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\
                %lf,%lf,%lf,%lf,%ld\n",
                mtg->istn.stat,mtg->istn.back,mtg->istn.statx,mtg->istn.staty,mtg->istn.statz,mtg->istn.stath,
                mtg->istn.backx,mtg->istn.backy,mtg->istn.backz,mtg->istn.backh,mtg->istn.backx1,mtg->istn.backy1,mtg->istn.backz1,
                mtg->istn.headh[0],mtg->istn.headh[1],mtg->istn.headv[0],mtg->istn.headv[1],mtg->istn.midh[0],mtg->istn.midh[1],
                mtg->istn.midv[0],mtg->istn.midv[1],mtg->istn.tailh[0],mtg->istn.tailh[1],mtg->istn.tailv[0],mtg->istn.tailv[1],mtg->istn.azi[0],mtg->istn.azi[1],
                mtg->istn.pitch[0],mtg->istn.pitch[1],mtg->istn.roll[0],mtg->istn.roll[1],(long)mtg->istn.t
                );
            sock->Write(msg,strlen(msg));
            break;
        }
        case 49:     ///查询历史数据
        {
            int num=0;
            double mile1,mile2;
            int seg1,seg2;
            MTG_MEASURE *om=0;
            if(sid==0)   ///按里程查询
            {
                sscanf(cmd,"%%R1Q,49:0:%lf,%lf\n",&mile1,&mile2);
                num = mtg_query_chain(mtg,mile1,mile2,&om);
            }
            else if(sid==1)
            {
                sscanf(cmd,"%%R1Q,49:1:%d,%d\n",&seg1,&seg2);
                num = mtg_query_seg(mtg,seg1,seg2,&om);
                trace(0,"client:num=%d\n",num);
            }
            sprintf(msg,"%%R1P,49:0:%d\n",num);
            sock->Write(msg,strlen(msg));
            for(i=0; i<num; i++)
            {
                sprintf(msg,"%%R1P,49:1:%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                 %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                 %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                 %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                 %lf,%lf,%lf,%d,%ld,%ld,%ld,%d\n",
                 i,om[i].inc[0],om[i].inc[1],om[i].inc[2],om[i].inc[3],om[i].cam[0],om[i].cam[1],om[i].cam[2],om[i].cam[3],om[i].prism[0],om[i].prism[1],om[i].prism[2],
                 om[i].angle[0],om[i].angle[1],om[i].comp[0],om[i].comp[1],om[i].head[0],om[i].head[1],om[i].head[2],om[i].hdes[0],om[i].hdes[1],om[i].hdes[2],
                 om[i].headc,om[i].headh,om[i].headv,om[i].tail[0],om[i].tail[1],om[i].tail[2],om[i].tdes[0],om[i].tdes[1],om[i].tdes[2],
                 om[i].tailc,om[i].tailh,om[i].tailv,om[i].mile1,om[i].hdev1,om[i].vdev1,om[i].mile2,om[i].hdev2,om[i].vdev2,om[i].mile3,om[i].hdev3,om[i].vdev3,
                 om[i].faj[0],om[i].faj[1],om[i].faj[2],om[i].faj[3],om[i].baj[0],om[i].baj[1],om[i].baj[2],om[i].baj[3],om[i].aj[0],om[i].aj[1],om[i].aj[2],om[i].aj[3],
                 om[i].inc1[0],om[i].inc1[1],om[i].inc1[2],om[i].iseg,(long)om[i].t1,(long)om[i].t2,(long)om[i].t3,om[i].iset
                );
                sock->Write(msg,strlen(msg));
            }
            if(num>0) free(om);
            break;
        }
        case 50:     ///取测量数据
        {
            sprintf(msg,"%%R1P,50:0:%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%d,%ld,%ld,%ld,%d\n",
             mtg->m.inc[0],mtg->m.inc[1],mtg->m.inc[2],mtg->m.inc[3],mtg->m.cam[0],mtg->m.cam[1],mtg->m.cam[2],mtg->m.cam[3],mtg->m.prism[0],mtg->m.prism[1],mtg->m.prism[2],
             mtg->m.angle[0],mtg->m.angle[1],mtg->m.comp[0],mtg->m.comp[1],mtg->m.head[0],mtg->m.head[1],mtg->m.head[2],mtg->m.hdes[0],mtg->m.hdes[1],mtg->m.hdes[2],
             mtg->m.headc,mtg->m.headh,mtg->m.headv,mtg->m.tail[0],mtg->m.tail[1],mtg->m.tail[2],mtg->m.tdes[0],mtg->m.tdes[1],mtg->m.tdes[2],
             mtg->m.tailc,mtg->m.tailh,mtg->m.tailv,mtg->m.mile1,mtg->m.hdev1,mtg->m.vdev1,mtg->m.mile2,mtg->m.hdev2,mtg->m.vdev2,mtg->m.mile3,mtg->m.hdev3,mtg->m.vdev3,
             mtg->m.faj[0],mtg->m.faj[1],mtg->m.faj[2],mtg->m.faj[3],mtg->m.baj[0],mtg->m.baj[1],mtg->m.baj[2],mtg->m.baj[3],mtg->m.aj[0],mtg->m.aj[1],mtg->m.aj[2],mtg->m.aj[3],
             mtg->m.inc1[0],mtg->m.inc1[1],mtg->m.inc1[2],mtg->m1.iseg,(long)mtg->m.t1,(long)mtg->m.t2,(long)mtg->m.t3,mtg->m.iset
            );

            /*sprintf(msg,"%%R1P,50:0:%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
             %lf,%lf,%lf,%d,%ld,%ld,%ld,%d\n",
             mtg->m.inc[0],mtg->m.inc[1],mtg->m.inc[2],mtg->m.inc[3],mtg->m.cam[0],mtg->m.cam[1],mtg->m.cam[2],mtg->m.cam[3],mtg->m.prism[0],mtg->m.prism[1],mtg->m.prism[2],
             mtg->m.angle[0],mtg->m.angle[1],mtg->m.comp[0],mtg->m.comp[1],mtg->m.head[0],mtg->m.head[1],mtg->m.head[2],mtg->m.hdes[0],mtg->m.hdes[1],mtg->m.hdes[2],
             mtg->m.headc,mtg->m.headh,mtg->m.headv,mtg->m.tail[0],mtg->m.tail[1],mtg->m.tail[2],mtg->m.tdes[0],mtg->m.tdes[1],mtg->m.tdes[2],
             mtg->m.tailc,mtg->m.tailh,mtg->m.tailv,mtg->m.mile1,mtg->m.hdev1,mtg->m.vdev1,mtg->m.mile2,mtg->m.hdev2,mtg->m.vdev2,mtg->m.mile3,mtg->m.hdev3,mtg->m.vdev3,
             mtg->m.faj[0],mtg->m.faj[1],mtg->m.faj[2],mtg->m.faj[3],mtg->m.baj[0],mtg->m.baj[1],mtg->m.baj[2],mtg->m.baj[3],mtg->m.aj[0],mtg->m.aj[1],mtg->m.aj[2],mtg->m.aj[3],
             mtg->m.inc1[0],mtg->m.inc1[1],mtg->m.inc1[2],mtg->m.iseg,(long)mtg->m.t1,(long)mtg->m.t2,(long)mtg->m.t3,mtg->m.iset
            );*/
            sock->Write(msg,strlen(msg));
            break;
        }
        case 56:     ///取测站
        {
            sprintf(msg,"%%R1P,55:0:'%s','%s',%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\
                %lf,%lf,%lf,%lf,%ld\n",
                mtg->istn.stat,mtg->istn.back,mtg->istn.statx,mtg->istn.staty,mtg->istn.statz,mtg->istn.stath,
                mtg->istn.backx,mtg->istn.backy,mtg->istn.backz,mtg->istn.backh,mtg->istn.backx1,mtg->istn.backy1,mtg->istn.backz1,
                mtg->istn.headh[0],mtg->istn.headh[1],mtg->istn.headv[0],mtg->istn.headv[1],mtg->istn.midh[0],mtg->istn.midh[1],
                mtg->istn.midv[0],mtg->istn.midv[1],mtg->istn.tailh[0],mtg->istn.tailh[1],mtg->istn.tailv[0],mtg->istn.tailv[1],mtg->istn.azi[0],mtg->istn.azi[1],
                mtg->istn.pitch[0],mtg->istn.pitch[1],mtg->istn.roll[0],mtg->istn.roll[1],(long)mtg->istn.t
                );
            sock->Write(msg,strlen(msg));
            break;
        }
        case 57:     ///取测量数据
        {

            break;
        }
        case 200:     ///更改具有管理权限的远程（仅1台远程电脑具有管理权限）
        {
            admin=m_index;
            break;
        }
        default:
            break;
    }
    //fclose(fp);
}

void mtg_t_svrFrame::TestSend()
{
    FILE* fp=fopen("D:\\midu\\send.log","w");
    char msg[4096];
    int i=0,j=0;
    if(fp)
    {
        ///取工程信息
        sprintf(msg,"%%R1P,1:0:'%s',%lf,%lf,%d,%d,'%s','%s','%s','%s',%d,%d,%lf\n",
            mtg->prj.name,mtg->prj.mile1,mtg->prj.mile2,mtg->prj.a2z,mtg->ndty,mtg->duty[0].name,mtg->duty[1].name,
            mtg->duty[2].name,mtg->duty[3].name,mtg->prj.htip,mtg->prj.vtip,mtg->prj.tip);
            fprintf(fp,"%s\n",msg);
        ///取中线
        int nh,nv,nho,nvo,nmo;
        h_element *he;
        v_element *ve;
        h_offset  *ho;
        v_offset  *vo;
        m_offset  *mo;
        nh = road_number_horizon(&mtg->r);
        nv = road_number_vertical(&mtg->r);
        nho = road_number_horizon_off(&mtg->r);
        nvo = road_number_vertical_off(&mtg->r);
        nmo = road_number_mile_off(&mtg->r);
        sprintf(msg,"%%R1P,4:0:%d,%d,%d,%d,%d\n",nh,nv,nho,nvo,nmo);
        fprintf(fp,"%s\n",msg);
        ///平曲线要素
        for(i=0; i<nh; i++)
        {
            he = road_horizon(&mtg->r,i);
            sprintf(msg,"%%R1P,4:1:%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d,%f\n",
            i,he->type,he->radius,he->rou1,he->rou2,he->x1,he->y1,he->x2,he->y2,he->angle1,he->angle2,he->l1,
            he->length,he->pz,he->deta);
            fprintf(fp,"%s\n",msg);
        }
        ///竖曲线
        for(i=0; i<nv; i++)
        {
            ve = road_vertical(&mtg->r,i);
            sprintf(msg,"%%R1P,4:2:%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%d,%f\n",
                    i,ve->type,ve->radius,ve->l1,ve->h1,ve->l2,ve->h2,ve->angle1,ve->angle2,ve->length,ve->pz,ve->deta);
            fprintf(fp,"%s\n",msg);
        }
        ///横偏
        for(i=0; i<nho; i++)
        {
            ho = road_horizon_off(&mtg->r,i);
            sprintf(msg,"%%R1P,4:3:%d,%f,%f\n",i,ho->mile,ho->off);
            fprintf(fp,"%s\n",msg);
        }
        ///纵偏
        for(i=0; i<nvo; i++)
        {
            vo = road_vertical_off(&mtg->r,i);
            sprintf(msg,"%%R1P,4:4:%d,%f,%f\n",i,vo->mile,vo->off);
            fprintf(fp,"%s\n",msg);
        }
        ///短链
        for(i=0; i<nmo; i++)
        {
            mo = road_mile_off(&mtg->r,i);
            sprintf(msg,"%%R1P,4:5:%d,%f,%f\n",i,mo->mile,mo->off);
            fprintf(fp,"%s\n",msg);
        }
        ///零位数据
        sprintf(msg,"%%R1P,7:0:%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
                %lf,%lf,%lf,%lf,%lf,%d,%ld,%ld,%ld,%d,%lf,%lf,%lf,%lf,%lf,%lf\n",
             mtg->m0.inc[0],mtg->m0.inc[1],mtg->m0.inc[2],mtg->m0.inc[3],
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
             mtg->m0.faj[0],mtg->m0.faj[1],mtg->m0.faj[2],mtg->m0.faj[3],
             mtg->m0.baj[0],mtg->m0.baj[1],mtg->m0.baj[2],mtg->m0.baj[3],
             mtg->m0.aj[0],mtg->m0.aj[1],mtg->m0.aj[2],mtg->m0.aj[3],
             mtg->m0.inc1[0],mtg->m0.inc1[1],mtg->m0.inc1[2],
             mtg->m0.iseg,(long)mtg->m0.t1,(long)mtg->m0.t2,(long)mtg->m0.t3,mtg->m0.iset,
             mtg->mp.prism[0],mtg->mp.prism[1],mtg->mp.prism[2],mtg->mp.prism[3],mtg->mp.prism[4],mtg->mp.prism[5]
             );
        fprintf(fp,"%s\n",msg);
        ///参数设置
        sprintf(msg,"%%R1P,10:0:%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\
            %d,%d,%lf,%lf,%d\n",
            mtg->iset.cyc,mtg->iset.bcyc,mtg->iset.palw,mtg->iset.jalw,mtg->iset.balw,mtg->iset.talw,
            mtg->iset.vibration,mtg->iset.rstn,mtg->iset.tsyn,mtg->iset.rget,mtg->iset.idrv,mtg->iset.prun,mtg->iset.pend,
            mtg->iset.psas,mtg->iset.pchk,mtg->iset.pqry,mtg->iset.pmap,mtg->iset.psmr,mtg->iset.pquit,mtg->iset.unit,
            mtg->iset.vmileage,mtg->iset.head,mtg->iset.tbm3d,mtg->iset.trend,mtg->iset.povr,mtg->iset.jovr,mtg->iset.tovr,
            mtg->iset.bovr,mtg->iset.toEr,mtg->iset.flen,mtg->iset.fdev,mtg->iset.lang);
        fprintf(fp,"%s\n",msg);
        ///关键区域
        sprintf(msg,"%%R1P,13:0:%d\n",mtg->nks);
        fprintf(fp,"%s\n",msg);
        for(i=0; i<mtg->nks; i++)
        {
            sprintf(msg,"%%R1P,13:1:%d,'%s',%lf,%lf\n",i,mtg->keys[i].name,mtg->keys[i].mile1,mtg->keys[i].mile2);
            fprintf(fp,"%s\n",msg);
        }
        ///盾构参数
        sprintf(msg,"%%R1P,16:0:'%s',%d,%d,\
            %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,\
            %d,%.12f,%.12f,%.12f,%.12f,%d,\
            %d,%.12f,%.12f,%.12f,%.12f,%d\n",
            mtg->tbm.name,mtg->tbm.type,mtg->tbm.mode,
            mtg->tbm.D[0],mtg->tbm.D[1],mtg->tbm.D[2],mtg->tbm.D[3],mtg->tbm.D[4],mtg->tbm.D[5],mtg->tbm.L[0],mtg->tbm.L[1],mtg->tbm.L[2],mtg->tbm.L[3],mtg->tbm.L[4],mtg->tbm.L[5],
            mtg->tbm.L[6],mtg->tbm.L[7],mtg->tbm.L[8],mtg->tbm.naj,mtg->tbm.aj[0],mtg->tbm.aj[1],mtg->tbm.aj[2],mtg->tbm.aj[3],mtg->tbm.aj[4],mtg->tbm.aj[5],mtg->tbm.aunit,
            mtg->tbm.nbj,mtg->tbm.bj[0],mtg->tbm.bj[1],mtg->tbm.bj[2],mtg->tbm.bj[3],mtg->tbm.bunit,
            mtg->tbm.nfj,mtg->tbm.fj[0],mtg->tbm.fj[1],mtg->tbm.fj[2],mtg->tbm.fj[3],mtg->tbm.funit
         );
        fprintf(fp,"%s\n",msg);
        ///激光靶
        sprintf(msg,"%%R1P,19:0:%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%d,%d,%d,%d\n",
            mtg->tarset.ver,mtg->tarset.prism[0],mtg->tarset.prism[1],mtg->tarset.prism[2],mtg->tarset.prism[3],mtg->tarset.prism[4],mtg->tarset.prism[5],
            mtg->tarset.prism[6],mtg->tarset.prism[7],mtg->tarset.prism[8],mtg->tarset.prc,mtg->tarset.length,mtg->tarset.cam,mtg->tarset.inc,mtg->tarset.ipos,mtg->tarset.pos
         );
        fprintf(fp,"%s\n",msg);
        ///相机
        for(i=0;i<2;i++)
        {
            sprintf(msg,"%%R1P,22:0:%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                %d,%d,%d,%d,'%s'\n",
                i,mtg->camset[i].w,mtg->camset[i].h,mtg->camset[i].affine[0],mtg->camset[i].affine[1],mtg->camset[i].affine[2],
                mtg->camset[i].affine[3],mtg->camset[i].affine[4],mtg->camset[i].affine[5],
                mtg->camset[i].affine[6],mtg->camset[i].affine[7],mtg->camset[i].affine[8],
                mtg->camset[i].x1,mtg->camset[i].y1,mtg->camset[i].x2,mtg->camset[i].y2,mtg->camset[i].name);
            fprintf(fp,"%s\n",msg);
        }
        ///取全站仪参数
        sprintf(msg,"%%R1P,25:0:%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%d\n",
            mtg->tps.type,mtg->tps.lasertype,mtg->tps.laserheight,mtg->tps.laserdist[0],mtg->tps.laserdist[1],
            mtg->tps.laserx[0],mtg->tps.lasery[0],mtg->tps.laserx[1],mtg->tps.lasery[1],mtg->tps.edm,mtg->tps.comp);
        fprintf(fp,"%s\n",msg);
        ///管环参数
        sprintf(msg,"%%R1P,28:0:%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%d,%.12f,%.12f,%d\n",
            mtg->segset.type,mtg->segset.in,mtg->segset.f2b,mtg->segset.l2s,
            mtg->segset.L,mtg->segset.De,mtg->segset.D,mtg->segset.Ks,mtg->segset.G0,mtg->segset.G1,mtg->segset.s2s
        );
        fprintf(fp,"%s\n",msg);
        ///取管块参数
        sprintf(msg,"%%R1P,31:0:%d\n",mtg->nblk);
        fprintf(fp,"%s\n",msg);
        for(i=0;i<mtg->nblk;i++)
        {
            sprintf(msg,"%%R1P,31:1:%d,'%s',%lf\n",i,mtg->blocks[i].name,mtg->blocks[i].angle);
            fprintf(fp,"%s\n",msg);
        }
        ///取管环监测参数
        sprintf(msg,"%%R1P,34:0:%d,%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%ld,%.12f,%.12f\n",
            mtg->smonitor.number,mtg->smonitor.monitor,mtg->smonitor.cycle,mtg->smonitor.last,mtg->smonitor.iseg,mtg->smonitor.headc,mtg->smonitor.x0,mtg->smonitor.y0,mtg->smonitor.z0,
            mtg->smonitor.x,mtg->smonitor.y,mtg->smonitor.z,(long)mtg->smonitor.t,mtg->smonitor.dv,mtg->smonitor.dv1);
        fprintf(fp,"%s\n",msg);
        ///用户
        sprintf(msg,"%%R1P,40:0:%d\n",mtg->nuser);
        fprintf(fp,"%s\n",msg);
        for(i=0; i<mtg->nuser; i++)
        {
            sprintf(msg,"%%R1P,40:1:%d,'%s','%s',%d\n",i,mtg->user[i].name,mtg->user[i].password,mtg->user[i].level);
            fprintf(fp,"%s\n",msg);
        }
        ///吊篮
        sprintf(msg,"%%R1P,43:0:%d\n",mtg->nbsk);
        fprintf(fp,"%s\n",msg);
        for(i=0;i<mtg->nbsk;i++)
        {
            sprintf(msg,"%%R1P,43:1:%d,'%s',%lf,%lf,%lf,%ld\n",
                i,mtg->bask[i].name,mtg->bask[i].x,mtg->bask[i].y,mtg->bask[i].z,(long)mtg->bask[i].t);
            fprintf(fp,"%s\n",msg);
        }
        ///测站
        sprintf(msg,"%%R1P,48:0:'%s','%s',%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\
            %lf,%lf,%lf,%lf,%ld\n",
            mtg->istn.stat,mtg->istn.back,mtg->istn.statx,mtg->istn.staty,mtg->istn.statz,mtg->istn.stath,
            mtg->istn.backx,mtg->istn.backy,mtg->istn.backz,mtg->istn.backh,mtg->istn.backx1,mtg->istn.backy1,mtg->istn.backz1,
            mtg->istn.headh[0],mtg->istn.headh[1],mtg->istn.headv[0],mtg->istn.headv[1],mtg->istn.midh[0],mtg->istn.midh[1],
            mtg->istn.midv[0],mtg->istn.midv[1],mtg->istn.tailh[0],mtg->istn.tailh[1],mtg->istn.tailv[0],mtg->istn.tailv[1],mtg->istn.azi[0],mtg->istn.azi[1],
            mtg->istn.pitch[0],mtg->istn.pitch[1],mtg->istn.roll[0],mtg->istn.roll[1],(long)mtg->istn.t
            );
        fprintf(fp,"%s\n",msg);
        ///测量数据
        sprintf(msg,"%%R1P,50:0:%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
         %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
         %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
         %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\
         %lf,%lf,%lf,%d,%ld,%ld,%ld,%d\n",
         mtg->m.inc[0],mtg->m.inc[1],mtg->m.inc[2],mtg->m.inc[3],mtg->m.cam[0],mtg->m.cam[1],mtg->m.cam[2],mtg->m.cam[3],mtg->m.prism[0],mtg->m.prism[1],mtg->m.prism[2],
         mtg->m.angle[0],mtg->m.angle[1],mtg->m.comp[0],mtg->m.comp[1],mtg->m.head[0],mtg->m.head[1],mtg->m.head[2],mtg->m.hdes[0],mtg->m.hdes[1],mtg->m.hdes[2],
         mtg->m.headc,mtg->m.headh,mtg->m.headv,mtg->m.tail[0],mtg->m.tail[1],mtg->m.tail[2],mtg->m.tdes[0],mtg->m.tdes[1],mtg->m.tdes[2],
         mtg->m.tailc,mtg->m.tailh,mtg->m.tailv,mtg->m.mile1,mtg->m.hdev1,mtg->m.vdev1,mtg->m.mile2,mtg->m.hdev2,mtg->m.vdev2,mtg->m.mile3,mtg->m.hdev3,mtg->m.vdev3,
         mtg->m.faj[0],mtg->m.faj[1],mtg->m.faj[2],mtg->m.faj[3],mtg->m.baj[0],mtg->m.baj[1],mtg->m.baj[2],mtg->m.baj[3],mtg->m.aj[0],mtg->m.aj[1],mtg->m.aj[2],mtg->m.aj[3],
         mtg->m.inc1[0],mtg->m.inc1[1],mtg->m.inc1[2],mtg->m.iseg,(long)mtg->m.t1,(long)mtg->m.t2,(long)mtg->m.t3,mtg->m.iset
        );
        fprintf(fp,"%s\n",msg);
        wxMessageBox(_("ok2"));
        int drv,asb;
        if(mtg->plc.drive) drv=1;
        else drv=0;
        if(mtg->plc.amode) asb=1;
        else asb=0;
        sprintf(msg,"%%R1D,55:0:%lf,%lf,%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,\
            %d,%lf,%lf,%lf,%lf,%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,%lf\n",mtg->m.inc1[1],mtg->m.inc1[0],mtg->itps,mtg->iinc,mtg->icam,mtg->itbm,
            mtg->tbm.naj,mtg->aj[0],mtg->aj[1],mtg->aj[2],mtg->aj[3],mtg->aj[4],mtg->aj[5],
            mtg->tbm.nfj,mtg->fj[0],mtg->fj[1],mtg->fj[2],mtg->fj[3],mtg->tbm.nbj,mtg->bj[0],mtg->bj[1],mtg->bj[2],mtg->bj[3],
            mtg->deth,mtg->detv,drv,asb,mtg->snum.mile);
        fprintf(fp,"%s\n",msg);
        wxMessageBox(_("ok1"));
        int id1=0,id2=0;
        sscanf(msg,"%%R1D,55:0:%lf,%lf,%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,\
               %d,%lf,%lf,%lf,%lf,%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,%lf\n",
               &mtg->m.inc1[1],&mtg->m.inc1[0],&mtg->itps,&mtg->iinc,&mtg->icam,&mtg->itbm,
               &mtg->tbm.naj,&mtg->aj[0],&mtg->aj[1],&mtg->aj[2],&mtg->aj[3],&mtg->aj[4],&mtg->aj[5],
               &mtg->tbm.nfj,&mtg->fj[0],&mtg->fj[1],&mtg->fj[2],&mtg->fj[3],
               &mtg->tbm.nbj,&mtg->bj[0],&mtg->bj[1],&mtg->bj[2],&mtg->bj[3],&mtg->deth,&mtg->detv,&id1,&id2,&mtg->snum.mile);
        if(id1==0) mtg->plc.drive=false;
        else mtg->plc.drive=true;
        if(id2==0) mtg->plc.amode=false;
        else mtg->plc.amode=true;
        wxMessageBox(_("ok"));
        if(mtg->plc.drive) drv=1;
        else drv=0;
        if(mtg->plc.amode) asb=1;
        else asb=0;
        sprintf(msg,"%%R1D,55:0:%lf,%lf,%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,\
            %d,%lf,%lf,%lf,%lf,%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,%lf\n",mtg->m.inc1[1],mtg->m.inc1[0],mtg->itps,mtg->iinc,mtg->icam,mtg->itbm,
            mtg->tbm.naj,mtg->aj[0],mtg->aj[1],mtg->aj[2],mtg->aj[3],mtg->aj[4],mtg->aj[5],
            mtg->tbm.nfj,mtg->fj[0],mtg->fj[1],mtg->fj[2],mtg->fj[3],mtg->tbm.nbj,mtg->bj[0],mtg->bj[1],mtg->bj[2],mtg->bj[3],
            mtg->deth,mtg->detv,drv,asb,mtg->snum.mile);
        fprintf(fp,"%s\n",msg);

        fclose(fp);
    }
}
