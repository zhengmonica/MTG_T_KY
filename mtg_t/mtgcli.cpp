#include <wx/wx.h>
#include "mtgcli.h"
#include "mtg_tApp.h"

void DecodeCommand(const char* cmd)
{
    int sid=-1,id=-1;
    char head[64];
    char word[64]="\0";
    char msg[260];
    int itl,itl2;
    const char *chal;
    char* m_log[260];
    double dbl,dbl2;
    wxString stl,stltodbl;
    int id1,id2;
    //FILE* fp=fopen("E:\\msg.log","w");

    int i=0,j=0;
    int index=0;
    long intl;
    long t1,t2,t3;
    sscanf(cmd,"%[^,],%d",head,&sid);
    int Vnum,Hnum,Vonum,Honum,Monum;
    int VnumC,HnumC,VonumC,HonumC,MonumC;
    Vnum=Hnum=Vonum=Honum=0;
    VnumC=HnumC=VonumC=HonumC=0;
    h_element he;
    v_element ve;
    h_offset hoff;
    v_offset voff;
    m_offset moff;
    //MTG_LOG *m_log=0;
    static int maxlog=0;
    fprintf(fp,"cmd:%s\n",cmd);
    fflush(fp);
    fprintf(fp,"sid=%d\n",sid);
    fflush(fp);
    switch(sid)
    {
    case 51:       ///日志
    {
        char lmsg[260]="\0";
        sscanf(cmd,"%%R1D,51:%d,%d,%ld,'%[^']'\n",&id1,&id2,&t1,lmsg);
        cli_write_log(lmsg,id2);

        break;
    }
    case 52:       ///测量数据
    {
        break;
    }
    case 54:       ///设站定向
    {
        if(cli->iget==1)
        {
            strcpy(cli->iword,cmd);
            cli->iget=2;
        }
        break;
    }
    case 55:       ///倾斜仪数据
    {
        sscanf(cmd,"%%R1D,55:%lf,%lf\n",&cli->m.pitch,&cli->m.roll);
        break;
    }
    case 1:        ///工程信息
    {
        sscanf(cmd,"%%R1P,1:'%[^']',%lf,%lf,%d,%d,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%d,%d,%lf,%d\n",
                cli->prj.name,&cli->prj.mile1,&cli->prj.mile2,&cli->prj.a2z,&cli->prj.duty,&cli->prj.t1[0],&cli->prj.t2[0],
             &cli->prj.t1[1],&cli->prj.t2[1],&cli->prj.t1[2],&cli->prj.t2[2],&cli->prj.t1[3],&cli->prj.t2[3],&cli->prj.htip,
             &cli->prj.vtip,&cli->prj.tip,&cli->prj.dta);
        if(strlen(cli->prj.name)==0)
        {
            sscanf(cmd,"%%R1P,1:'',%lf,%lf,%d,%d,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%d,%d,%lf,%d\n",
                 &cli->prj.mile1,&cli->prj.mile2,&cli->prj.a2z,&cli->prj.duty,&cli->prj.t1[0],&cli->prj.t2[0],
                 &cli->prj.t1[1],&cli->prj.t2[1],&cli->prj.t1[2],&cli->prj.t2[2],&cli->prj.t1[3],&cli->prj.t2[3],
                 &cli->prj.htip,&cli->prj.vtip,&cli->prj.tip,&cli->prj.dta);
        }
        cli_write_log("读取工程信息成功",0);
        break;
    }
    case 2:
    {
        sscanf(cmd,"%%R1P,2:%d\n",&itl);
        if(itl)
            cli_write_log("工程信息存储成功",0);
        else
            cli_write_log("工程信息存储失败",1);
        break;
    }
    case 3:        ///工程信息（广播）
    {
        if(cli->iget==1)
        {
            strcpy(cli->iword,cmd);
            cli->iget=2;
            break;
        }
        sscanf(cmd,"%%R1D,3:'%[^']',%lf,%lf,%d,%d,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%d,%d,%lf,%d\n",
                 cli->prj.name,&cli->prj.mile1,&cli->prj.mile2,&cli->prj.a2z,&cli->prj.duty,&cli->prj.t1[0],&cli->prj.t2[0],
             &cli->prj.t1[1],&cli->prj.t2[1],&cli->prj.t1[2],&cli->prj.t2[2],&cli->prj.t1[3],&cli->prj.t2[3],&cli->prj.htip,
             &cli->prj.vtip,&cli->prj.tip,&cli->prj.dta);
        if(strlen(cli->prj.name)==0)
        {
            sscanf(cmd,"%%R1D,3:'',%lf,%lf,%d,%d,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%d,%d,%lf,%d\n",
                 &cli->prj.mile1,&cli->prj.mile2,&cli->prj.a2z,&cli->prj.duty,&cli->prj.t1[0],&cli->prj.t2[0],&cli->prj.t1[1],
                 &cli->prj.t2[1],&cli->prj.t1[2],&cli->prj.t2[2],&cli->prj.t1[3],&cli->prj.t2[3],&cli->prj.htip,&cli->prj.vtip,
                 &cli->prj.tip,&cli->prj.dta);
        }
        cli_write_log("接收到工程信息广播",0);
        break;
    }
    case 4:        ///中线数据
    {
        sscanf(cmd,"%%R1P,4:%d:",&id);
        if(id==0)
        {
            sscanf(cmd,"%%R1P,4:0:%d,%d,%d,%d,%d\n",&Hnum,&Vnum,&Honum,&Vonum,&Monum);
            road_clear_horizon(&cli->r);
            road_clear_vertical(&cli->r);
            road_clear_horizon_off(&cli->r);
            road_clear_vertical_off(&cli->r);
            road_clear_mile_off(&cli->r);

            cli_write_log("读取中线数据",0);
        }
        else if(id==1)
        {
            sscanf(cmd,"%%R1P,4:1:%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d\n",
                   &id,&he.type,&he.l1,&he.length,&he.angle1,&he.angle2,&he.radius,
                   &he.rou1,&he.rou2,&he.x1,&he.y1,&he.x2,&he.y2,&he.pz);
            road_insert_horizon(&cli->r,&he,id);
            road_apply_horizon(&cli->r);
        }
        else if(id==2)
        {
            sscanf(cmd,"%%R1P,4:2:%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d\n",
                   &id,&ve.type,&ve.l1,&ve.h1,&ve.l2,&ve.h2,&ve.length,&ve.radius,&ve.angle1,&ve.angle2,&ve.pz);
            road_insert_vertical(&cli->r,&ve,id);
            road_apply_vertical(&cli->r);
        }
        else if(id==3)
        {
            sscanf(cmd,"%%R1P,4:3:%d,%lf,%lf\n",&id,&hoff.mile,&hoff.off);
            road_insert_horizon_off(&cli->r,&hoff);
        }
        else if(id==4)
        {
            sscanf(cmd,"%%R1P,4:4:%d,%lf,%lf\n",&id,&voff.mile,&voff.off);
            road_insert_vertical_off(&cli->r,&voff);
        }
        else if(id==5)
        {
            sscanf(cmd,"%%R1P,4:5:%d,%lf,%lf\n",&id,&moff.mile,&moff.off);
            road_insert_mile_off(&cli->r,&moff);
        }
        break;
    }
    case 5:
    {
        sscanf(cmd,"%%R1P,5:%d\n",&itl);
        if(itl)
        {
            cli_write_log("中线数据修改成功",0);
        }
        else
            cli_write_log("中线数据修改失败",1);
        break;
    }
    case 6:        ///中线数据（广播）
    {
        sscanf(cmd,"%%R1D,6:%d",&id);
        if(id==0)
        {
            sscanf(cmd,"%%R1D,6:0:%d,%d,%d,%d,%d\n",&Hnum,&Vnum,&Honum,&Vonum,&Monum);
            road_clear_horizon(&cli->r);
            road_clear_vertical(&cli->r);
            road_clear_horizon_off(&cli->r);
            road_clear_vertical_off(&cli->r);
            road_clear_mile_off(&cli->r);
            cli_write_log("接收到中线数据信息广播",0);
        }
        else if(id==1)
        {
            sscanf(cmd,"%%R1D,6:1:%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d\n",
                   &id,&he.type,&he.l1,&he.length,&he.angle1,&he.angle2,&he.radius,&he.rou1,&he.rou2,&he.x1,&he.y1,&he.x2,&he.y2,&he.pz);
            road_insert_horizon(&cli->r,&he,id);
            road_apply_horizon(&cli->r);
        }
        else if(id==2)
        {
            sscanf(cmd,"%%R1D,6:2:%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d\n",
                   &id,&ve.type,&ve.l1,&ve.h1,&ve.l2,&ve.h2,&ve.length,&ve.radius,&ve.angle1,&ve.angle2,&ve.pz);
            road_insert_vertical(&cli->r,&ve,id);
            road_apply_vertical(&cli->r);
        }
        else if(id==3)
        {
            sscanf(cmd,"%%R1D,6:3:%d,%lf,%lf\n",&id,&hoff.mile,&hoff.off);
            road_insert_horizon_off(&cli->r,&hoff);
            HonumC++;
        }
        else if(id==4)
        {
            sscanf(cmd,"%%R1D,6:4:%d,%lf,%lf\n",&id,&voff.mile,&voff.off);
            road_insert_vertical_off(&cli->r,&voff);
            VonumC++;
        }
        else if(id==5)
        {
            sscanf(cmd,"%%R1D,6:4:%d,%lf,%lf\n",&id,&moff.mile,&moff.off);
            road_insert_mile_off(&cli->r,&moff);
            MonumC++;
        }
        break;
    }
    case 7:        ///零位数据
    {
        sscanf(cmd,"%%R1P,7:%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\
           %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%ld,%ld,%ld,%d\n",
           &cli->m0.inc[0],&cli->m0.inc[1],&cli->m0.inc[1],&cli->m0.cam[0],&cli->m0.cam[1],&cli->m0.cam[2],&cli->m0.cam[3],
           &cli->m0.prism[0],&cli->m0.prism[1],&cli->m0.prism[2],&cli->m0.angle[0],&cli->m0.angle[1],&cli->m0.comp[0],
           &cli->m0.comp[1],&cli->m0.head[0],&cli->m0.head[1],&cli->m0.head[2],&cli->m0.hdes[0],&cli->m0.hdes[1],
           &cli->m0.hdes[2],&cli->m0.headc,&cli->m0.headh,&cli->m0.headv,&cli->m0.tail[0],&cli->m0.tail[1],&cli->m0.tail[2],
           &cli->m0.tdes[0],&cli->m0.tdes[1],&cli->m0.tdes[2],&cli->m0.tailc,&cli->m0.tailh,&cli->m0.tailv,&cli->m0.mid[0],
           &cli->m0.mid[1],&cli->m0.mid[2],&cli->m0.mdes[0],&cli->m0.mdes[1],&cli->m0.mdes[2],&cli->m0.midc,&cli->m0.midh,
           &cli->m0.midv,&cli->m0.midj[0],&cli->m0.midj[1],&cli->m0.midj[2],&cli->m0.midj[3],&cli->m0.roll,&cli->m0.pitch,
           &cli->m0.azimuth,&cli->m0.iseg,&cli->m0.t1,&cli->m0.t2,&cli->m0.t3,&cli->m0.iset);
        cli_write_log("读取零位数据成功",0);
        break;
    }
    case 8:
    {
        sscanf(cmd,"%%R1P,8:%d\n",&itl);
        if(itl)
            cli_write_log("零位数据修改成功",0);
        else
            cli_write_log("零位数据修改失败",1);
        break;
    }
    case 9:        ///零位数据（广播）
    {
        sscanf(cmd,"%%R1D,9:%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\
           %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%ld,%ld,%ld,%d\n",
           &cli->m0.inc[0],&cli->m0.inc[1],&cli->m0.inc[2],&cli->m0.cam[0],&cli->m0.cam[1],&cli->m0.cam[2],&cli->m0.cam[3],
           &cli->m0.prism[0],&cli->m0.prism[1],&cli->m0.prism[2],&cli->m0.angle[0],&cli->m0.angle[1],&cli->m0.comp[0],
           &cli->m0.comp[1],&cli->m0.head[0],&cli->m0.head[1],&cli->m0.head[2],&cli->m0.hdes[0],&cli->m0.hdes[1],
           &cli->m0.hdes[2],&cli->m0.headc,&cli->m0.headh,&cli->m0.headv,&cli->m0.tail[0],&cli->m0.tail[1],&cli->m0.tail[2],
           &cli->m0.tdes[0],&cli->m0.tdes[1],&cli->m0.tdes[2],&cli->m0.tailc,&cli->m0.tailh,&cli->m0.tailv,&cli->m0.mid[0],
           &cli->m0.mid[1],&cli->m0.mid[2],&cli->m0.mdes[0],&cli->m0.mdes[1],&cli->m0.mdes[2],&cli->m0.midc,&cli->m0.midh,
           &cli->m0.midv,&cli->m0.midj[0],&cli->m0.midj[1],&cli->m0.midj[2],&cli->m0.midj[3],&cli->m0.roll,&cli->m0.pitch,
           &cli->m0.azimuth,&cli->m0.iseg,&cli->m0.t1,&cli->m0.t2,&cli->m0.t3,&cli->m0.iset);
        cli_write_log("接收到零位数据信息广播",0);
        break;
    }
    case 10:       ///系统设置
    {
        sscanf(cmd,"%%R1P,10:%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%lf,%lf,%d\n",
            &cli->sets.cyc,&cli->sets.bcyc,&cli->sets.palw,&cli->sets.jalw,&cli->sets.balw,&cli->sets.talw,&cli->sets.vibration,
            &cli->sets.rstn,&cli->sets.tsyn,&cli->sets.rget,&cli->sets.idrv,&cli->sets.prun,&cli->sets.pend,&cli->sets.psas,
            &cli->sets.pchk,&cli->sets.pqry,&cli->sets.pmap,&cli->sets.psmr,&cli->sets.pquit,&cli->sets.unit,&cli->sets.vmileage,
            &cli->sets.head,&cli->sets.tbm3d,&cli->sets.heading,&cli->sets.povr,&cli->sets.jovr,&cli->sets.tovr,&cli->sets.bovr,
            &cli->sets.toEr,&cli->sets.flen,&cli->sets.fdev,&cli->sets.lang);
        cli_write_log("读取系统设置成功",0);
        break;
    }
    case 11:
    {
        sscanf(cmd,"%%R1P,11:%d\n",&itl);
        if(itl)
            cli_write_log("系统设置修改成功",0);
        else
            cli_write_log("系统设置修改失败",1);
        break;
    }
    case 12:       ///系统设置（广播）
    {
        sscanf(cmd,"%%R1D,12:%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%lf,%lf,%d\n",
            &cli->sets.cyc,&cli->sets.bcyc,&cli->sets.palw,&cli->sets.jalw,&cli->sets.balw,&cli->sets.talw,&cli->sets.vibration,
            &cli->sets.rstn,&cli->sets.tsyn,&cli->sets.rget,&cli->sets.idrv,&cli->sets.prun,&cli->sets.pend,&cli->sets.psas,
            &cli->sets.pchk,&cli->sets.pqry,&cli->sets.pmap,&cli->sets.psmr,&cli->sets.pquit,&cli->sets.unit,&cli->sets.vmileage,
            &cli->sets.head,&cli->sets.tbm3d,&cli->sets.heading,&cli->sets.povr,&cli->sets.jovr,&cli->sets.tovr,&cli->sets.bovr,
            &cli->sets.toEr,&cli->sets.flen,&cli->sets.fdev,&cli->sets.lang);
        cli_write_log("接收到系统设置信息广播",0);
        break;
    }
    case 13:       ///关键区域
    {
        int type=-1;
        i=0;
        sscanf(cmd,"%%R1P,13:%d:%d",&type,&i);
        if(type==0)
        {
            if(i>0) cli->keys=(MTG_KEY*)malloc(i*sizeof(MTG_KEY));
            cli->nks=i;
        }
        else
        {
            memset(cli->keys[i].name,0,64);
            sscanf(cmd,"%%R1P,13:1:%d,'%[^']',%lf,%lf\n",&id1,cli->keys[i].name,&cli->keys[i].mile1,&cli->keys[i].mile2);
            if(strlen(cli->keys[i].name)==0)
            {
                sscanf(cmd,"%%R1P,13:1:%d,'',%lf,%lf\n",&id1,&cli->keys[i].mile1,&cli->keys[i].mile2);
            }
            if(i==cli->nks-1) cli_write_log("读取关键区域成功",0);
        }
        break;
    }
    case 14:
    {
        sscanf(cmd,"%%R1P,14:%d\n",&itl);
        if(itl)
            cli_write_log("设置关键区域成功",0);
        else
            cli_write_log("设置关键区域失败",1);
        break;
    }
    case 15:       ///关键区域（广播）
    {
        if(cli->imode==1)
        {
            break;
        }
        int type=-1;
        i=0;
        sscanf(cmd,"%%R1D,15:%d:%d",&type,&i);
        if(type==0)
        {
            if(i>0) cli->keys=(MTG_KEY*)malloc(i*sizeof(MTG_KEY));
            cli->nks=i;
            break;
        }
        else
        {
            memset(cli->keys[i].name,0,64);
            sscanf(cmd,"%%R1D,15:1:%d,'%[^']',%lf,%lf\n",&id1,cli->keys[i].name,&cli->keys[i].mile1,&cli->keys[i].mile2);
            if(strlen(cli->keys[i].name)==0)
            {
                sscanf(cmd,"%%R1D,15:1:%d,'',%lf,%lf\n",&id1,&cli->keys[i].mile1,&cli->keys[i].mile2);
            }
            if(i==cli->nks-1) cli_write_log("接收到关键区域信息广播",0);
        }
        break;
    }
    case 16:       ///TBM设置
    {
        sscanf(cmd,"%%R1P,16:'%[^']',%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
             cli->tbm.name,&cli->tbm.type,&cli->tbm.mode,&cli->tbm.D[0],&cli->tbm.D[1],&cli->tbm.D[2],&cli->tbm.D[3],
             &cli->tbm.D[4],&cli->tbm.D[5],&cli->tbm.L[0],&cli->tbm.L[1],&cli->tbm.L[2],&cli->tbm.L[3],&cli->tbm.L[4]);
        if(strlen(cli->tbm.name)==0)
        {
            sscanf(cmd,"%%R1P,16:'',%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
                 &cli->tbm.type,&cli->tbm.mode,&cli->tbm.D[0],&cli->tbm.D[1],&cli->tbm.D[2],&cli->tbm.D[3],
                 &cli->tbm.D[4],&cli->tbm.D[5],&cli->tbm.L[0],&cli->tbm.L[1],&cli->tbm.L[2],&cli->tbm.L[3],&cli->tbm.L[4]);
        }
        cli_write_log("读取盾构参数成功",0);
        break;
    }
    case 17:
    {
        sscanf(cmd,"%%R1P,17:%d\n",&itl);
        if(itl)
            cli_write_log("设置盾构参数成功",0);
        else
            cli_write_log("设置盾构参数失败",1);
        break;
    }
    case 18:      ///TBM设置广播
    {
        sscanf(cmd,"%%R1D,18:'%s',%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
             cli->tbm.name,&cli->tbm.type,&cli->tbm.mode,&cli->tbm.D[0],&cli->tbm.D[1],&cli->tbm.D[2],&cli->tbm.D[3],
             &cli->tbm.D[4],&cli->tbm.D[5],&cli->tbm.L[0],&cli->tbm.L[1],&cli->tbm.L[2],&cli->tbm.L[3],&cli->tbm.L[4]);
        if(strlen(cli->tbm.name)==0)
        {
            sscanf(cmd,"%%R1D,18:'',%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
                 &cli->tbm.type,&cli->tbm.mode,&cli->tbm.D[0],&cli->tbm.D[1],&cli->tbm.D[2],&cli->tbm.D[3],
                 &cli->tbm.D[4],&cli->tbm.D[5],&cli->tbm.L[0],&cli->tbm.L[1],&cli->tbm.L[2],&cli->tbm.L[3],&cli->tbm.L[4]);
        }
        cli_write_log("接收到盾构参数信息广播",0);
        break;
    }
    case 19:      ///激光靶参数
    {
        sscanf(cmd,"%%R1P,19:%lf,%lf,%lf,%lf,%lf,%d,%d\n",
             &cli->tarset.prism[0],&cli->tarset.prism[1],&cli->tarset.prism[2],&cli->tarset.prc,&cli->tarset.length,
             &cli->tarset.cam,&cli->tarset.inc);
        cli_write_log("读取激光靶参数成功",0);
        break;
    }
    case 20:
    {
        sscanf(cmd,"%%R1P,20:%d\n",&itl);
        if(itl)
            cli_write_log("设置激光靶参数成功",0);
        else
            cli_write_log("设置激光靶参数失败",1);
        break;
    }
    case 21:      ///激光靶参数（广播）
    {
        sscanf(cmd,"%%R1D,21:%lf,%lf,%lf,%lf,%lf,%d,%d\n",
                 &cli->tarset.prism[0],&cli->tarset.prism[1],&cli->tarset.prism[2],&cli->tarset.prc,&cli->tarset.length,
                 &cli->tarset.cam,&cli->tarset.inc);
        cli_write_log("接收到激光靶参数信息广播",0);
        break;
    }
    case 22:      ///激光靶配置文件
    {
        sscanf(cmd,"%%R1P,22:%d",&i);
        sscanf(cmd,"%%R1P,22:%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,'%[^']'\n",
            &id1,&cli->camset[i].w,&cli->camset[i].h,&cli->camset[i].affine[0],&cli->camset[i].affine[1],&cli->camset[i].affine[2],
            &cli->camset[i].affine[3],&cli->camset[i].affine[4],&cli->camset[i].affine[5],&cli->camset[i].affine[6],
            &cli->camset[i].affine[7],&cli->camset[i].affine[8],cli->camset[i].name);
        if(i==1) cli_write_log("读取激光靶配置文件成功",0);
        break;
    }
    case 23:
    {
        sscanf(cmd,"%%R1P,23:%d\n",&itl);
        if(itl)
            cli_write_log("设置激光靶配置文件成功",0);
        else
            cli_write_log("设置激光靶配置文件失败",1);
        break;
    }
    case 24:      ///激光靶配置文件（广播）
    {
        sscanf(cmd,"%%R1D,24:%d",&i);
        sscanf(cmd,"%%R1D,24:%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,'%[^']'\n",
            &id1,&cli->camset[i].w,&cli->camset[i].h,&cli->camset[i].affine[0],&cli->camset[i].affine[1],&cli->camset[i].affine[2],
            &cli->camset[i].affine[3],&cli->camset[i].affine[4],&cli->camset[i].affine[5],&cli->camset[i].affine[6],
            &cli->camset[i].affine[7],&cli->camset[i].affine[8],cli->camset[i].name);
        if(i==1) cli_write_log("接收到激光靶配置文件信息广播",0);
        break;
    }
    case 25:      ///全站仪
    {
        sscanf(cmd,"%%R1P,25:%d,%lf,%lf,%lf,%lf\n",
            &cli->tps.lasertype,&cli->tps.laserheight,&cli->tps.laserdist,&cli->tps.laserx,&cli->tps.lasery);
        cli_write_log("读取全站仪参数成功",0);
        break;
    }
    case 26:
    {
        sscanf(cmd,"%%R1P,23:%d\n",&itl);
        if(itl)
            cli_write_log("设置全站仪参数成功",0);
        else
            cli_write_log("设置全站仪参数失败",1);
        break;
    }
    case 27:      ///全站仪（广播）
    {
        sscanf(cmd,"%%R1D,27:%d,%lf,%lf,%lf,%lf\n",
            &cli->tps.lasertype,&cli->tps.laserheight,&cli->tps.laserdist,&cli->tps.laserx,&cli->tps.lasery);
        cli_write_log("接收到全站仪参数信息广播",0);
    }
    case 28:      ///管环参数
    {
        sscanf(cmd,"%%R1P,28:%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%d,%lf,%lf,%d\n",
            &cli->segset.type,&cli->segset.in,&cli->segset.f2b,&cli->segset.l2s,&cli->segset.L,&cli->segset.De,
            &cli->segset.D,&cli->segset.Dn,&cli->segset.Ks,&cli->segset.G0,&cli->segset.G1,&cli->segset.s2s);
        if(cli->kpos) cli->kpos=(int*)realloc(cli->kpos,cli->segset.Ks*sizeof(int));
        else cli->kpos=(int*)malloc(sizeof(int));
        cli_write_log("读取管环参数成功",0);
        break;
    }
    case 29:
    {
        sscanf(cmd,"%%R1P,23:%d\n",&itl);
        if(itl)
            cli_write_log("设置管环参数成功",0);
        else
            cli_write_log("设置管环参数失败",1);
        break;
    }
    case 30:      ///管环参数（广播）
    {
        sscanf(cmd,"%%R1D,30:%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%d,%lf,%lf,%d\n",
            &cli->segset.type,&cli->segset.in,&cli->segset.f2b,&cli->segset.l2s,&cli->segset.L,&cli->segset.De,
            &cli->segset.D,&cli->segset.Dn,&cli->segset.Ks,&cli->segset.G0,&cli->segset.G1,&cli->segset.s2s);
        cli->kpos=(int*)malloc(cli->segset.Ks*sizeof(int));
        cli_write_log("接收到管环参数信息广播",0);
        break;
    }
    case 31:      ///管块参数
    {
        int type=-1;
        i=0;
        sscanf(cmd,"%%R1P,31:%d:%d",&type,&i);
        if(type==0)
        {
            if(i>0)
            {
                if(cli->blocks) cli->blocks=(MTG_BLOCK*)realloc(cli->blocks,i*sizeof(MTG_BLOCK));
                else cli->blocks=(MTG_BLOCK*)malloc(i*sizeof(MTG_BLOCK));
            }
            cli->nblk=i;
            break;
        }
        else
        {
            memset(cli->blocks[i].name,0,64);
            sscanf(cmd,"%%R1P,31:1:%d,'%[^']',%lf\n",&id1,cli->blocks[i].name,&cli->blocks[i].angle);
            if(strlen(cli->blocks[i].name)==0)
            {
                sscanf(cmd,"%%R1P,31:1:%d'',%lf\n",&id1,&cli->blocks[i].angle);
            }
        }
        if(i==cli->nblk-1) cli_write_log("读取管块参数成功",0);
        break;
    }
    case 32:
    {
        sscanf(cmd,"%%R1P,32:%d\n",&itl);
        if(itl)
            cli_write_log("设置管块参数成功",0);
        else
            cli_write_log("设置管块参数失败",1);
        break;
    }
    case 33:      ///管块参数（广播）
    {
        int type=-1;
        i=0;
        sscanf(cmd,"%%R1D,33:%d:%d",&type,&i);
        if(type==0)
        {
            if(i>0) cli->blocks=(MTG_BLOCK*)malloc(i*sizeof(MTG_BLOCK));
            cli->nks=i;
            break;
        }
        else
        {
            memset(cli->blocks[i].name,0,64);
            sscanf(cmd,"%%R1D,33:1:%d,'%[^']',%lf\n",&id1,cli->blocks[i].name,&cli->blocks[i].angle);
            if(strlen(cli->blocks[id2].name)==0)
            {
                sscanf(cmd,"%%R1D,33:1:%d,'',%lf\n",&id1,&cli->blocks[i].angle);
            }
            if(i==cli->nblk-1) cli_write_log("接收到管块参数信息广播",0);
        }
        break;
    }
    case 34:      ///管环监测参数
    {
        sscanf(cmd,"%%R1P,35:%d,%d,%d,%d,%lf,%lf,%lf,%ld\n",
        &cli->smonitor.number,&cli->smonitor.monitor,&cli->smonitor.cycle,&cli->smonitor.last,&cli->smonitor.x,&cli->smonitor.y,&cli->smonitor.z,&cli->smonitor.t);
        cli_write_log("读取管环监测参数成功",0);
        break;
    }
    case 35:
    {
        sscanf(cmd,"%%R1P,35:%d\n",&itl);
        if(itl)
            cli_write_log("设置管环监测参数成功",0);
        else
            cli_write_log("设置管环监测参数失败",1);
        break;
    }
    case 36:      ///管环监测参数（广播）
    {
        sscanf(cmd,"%%R1D,35:%d,%d,%d,%d,%lf,%lf,%lf,%ld\n",
        &cli->smonitor.number,&cli->smonitor.monitor,&cli->smonitor.cycle,&cli->smonitor.last,&cli->smonitor.x,&cli->smonitor.y,&cli->smonitor.z,&cli->smonitor.t);
        cli_write_log("接收到管环监测参数信息广播",0);
        break;
    }
    case 40:      ///用户
    {
        int type=-1;
        i=0;
        sscanf(cmd,"%%R1P,40:%d:%d",&type,&i);
        if(type==0)
        {
            if(i>0 && i!=cli->nuser)
            {
                if(cli->user) cli->user=(MTG_USER*)realloc(cli->user,i*sizeof(MTG_USER));
                else cli->user=(MTG_USER*)malloc(i*sizeof(MTG_USER));
            }
            cli->nuser=i;
            break;
        }
        else
        {
            memset(cli->user[i].name,0,64);
            memset(cli->user[i].password,0,64);
            sscanf(cmd,"%%R1P,40:1:%d,'%[^']','%[^']',%d\n",&id2,cli->user[i].name,cli->user[i].password,&cli->user[i].level);
            if(strlen(cli->user[i].name)==0 && strlen(cli->user[i].password)==0)
            {
                sscanf(cmd,"%%R1P,40:1:%d,'','',%d\n",&id2,&cli->user[i].level);
            }
            else if(strlen(cli->user[i].name)==0)
            {
                sscanf(cmd,"%%R1P,40:1:%d,'','%[^']',%d\n",&id2,cli->user[i].password,&cli->user[i].level);
            }
            else if(strlen(cli->user[i].password)==0)
            {
                sscanf(cmd,"%%R1P,40:1:%d,'%[^']','',%d\n",&id2,cli->user[i].name,&cli->user[i].level);
            }
        }
        if(i==cli->nuser-1)
        {
            cli_write_log("读取用户成功",0);
        }
        fprintf(fp,"user:%d,%s,%s,%d\n",cli->nuser,cli->user[i].name,cli->user[i].password,cli->user[i].level);
        break;
    }
    case 41:
    {
        sscanf(cmd,"%%R1P,41:%d\n",&itl);
        if(itl)
            cli_write_log("用户修改成功",0);
        else
            cli_write_log("用户修改失败",1);
        break;
    }
    case 42:      ///用户（广播）
    {
        int type=-1;
        i=0;
        sscanf(cmd,"%%R1D,42:%d:%d",&type,&i);
        if(type==0)
        {
            if(i>0)
            {
                if(cli->user) cli->user=(MTG_USER*)realloc(cli->user,i*sizeof(MTG_USER));
                else cli->user=(MTG_USER*)malloc(i*sizeof(MTG_USER));
            }
            cli->nuser=i;
            break;
        }
        else
        {
            sscanf(cmd,"%%R1D,42:%1:%d,'%[^']','%[^']',%d\n",&id2,cli->user[i].name,cli->user[i].password,&cli->user[i].level);
            memset(cli->user[i].name,0,64);
            memset(cli->user[i].password,0,64);
            if(strlen(cli->user[i].name)==0 && strlen(cli->user[i].password)==0)
            {
                sscanf(cmd,"%%R1D,42:1:%d,'','',%d\n",&id2,&cli->user[i].level);
            }
            else if(strlen(cli->user[i].name)==0)
            {
                sscanf(cmd,"%%R1D,42:1:%d,'','%[^']',%d\n",&id2,cli->user[i].password,&cli->user[i].level);
            }
            else if(strlen(cli->user[i].password)==0)
            {
                sscanf(cmd,"%%R1D,42:1:%d,'%[^']','',%d\n",&id2,cli->user[i].name,&cli->user[i].level);
            }

            if(i==cli->nuser-1)
            {
                cli_write_log("读取用户成功",0);
            }
        }

        if(i==cli->nuser-1) cli_write_log("接收到用户信息广播",0);
        break;
    }
    case 43:      ///吊篮
    {
        int type=-1;
        i=0;
        sscanf(cmd,"%%R1P,43:%d:%d",&type,&i);
        if(type==0)
        {
            if(i>0)
            {
                if(cli->bask) cli->bask=(MTG_BASKET*)realloc(cli->bask,i*sizeof(MTG_BASKET));
                else cli->bask=(MTG_BASKET*)malloc(i*sizeof(MTG_BASKET));
                cli->nbsk=i;
            }
        }
        else
        {
            memset(cli->bask[i].name,0,64);
            sscanf(cmd,"%%R1P,43:1:%d,'%[^']',%lf,%lf,%lf,%ld\n",&id2,cli->bask[i].name,&cli->bask[i].x,&cli->bask[i].y,&cli->bask[i].z,&t1);
            if(strlen(cli->bask[i].name)==0)
            {
                sscanf(cmd,"%%R1P,43:1:%d,'',%lf,%lf,%lf,%ld\n",&id2,&cli->bask[i].x,&cli->bask[i].y,&cli->bask[i].z,&t1);
            }
            cli->bask[i].t=t1;
            if(i==cli->nbsk-1) cli_write_log("读取吊篮成功",0);
        }
        break;
    }
    case 44:
    {
        sscanf(cmd,"%%R1P,44:%d\n",&itl);
        if(itl)
            cli_write_log("吊篮修改成功",0);
        else
            cli_write_log("吊篮修改失败",1);
        break;
    }
    case 45:     ///吊篮（广播）
    {
        if(cli->imode==1)
        {
            break;
        }
        int type=-1;
        i=0;
        sscanf(cmd,"%%R1D,45:%d:%d",&type,&i);
        if(type==0)
        {
            if(i>0)
            {
                if(cli->bask) cli->bask=(MTG_BASKET*)realloc(cli->bask,i*sizeof(MTG_BASKET));
                else cli->bask=(MTG_BASKET*)malloc(i*sizeof(MTG_BASKET));
            }
            cli->nbsk=i;
            break;
        }
        else
        {
            memset(cli->bask[i].name,0,64);
            sscanf(cmd,"%%R1D,45:1:%d,'%[^']',%lf,%lf,%lf,%ld\n",&id2,cli->bask[i].name,&cli->bask[i].x,&cli->bask[i].y,&cli->bask[i].z,&t1);
            if(strlen(cli->bask[i].name)==0)
            {
                sscanf(cmd,"%%R1D,45:1:%d,'',%lf,%lf,%lf,%ld\n",&id2,&cli->bask[i].x,&cli->bask[i].y,&cli->bask[i].z,&t1);
            }
            cli->bask[i].t=t1;
            if(i==cli->nbsk-1) cli_write_log("接收到吊篮信息广播",0);
            break;
        }
        break;
    }
    case 46:     ///测站
    {
        int type=-1;
        i=0;
        t1=0;
        sscanf(cmd,"%%R1P,46:%d:%d",&type,&i);
        if(type==0)
        {
            if(i>0)
            {
                if(cli->stns) cli->stns=(MTG_STATION*)realloc(cli->stns,i*sizeof(MTG_STATION));
                else cli->stns=(MTG_STATION*)malloc(i*sizeof(MTG_STATION));
            }
            else
            {
                cli_write_log("读取测站成功",0);
                cli->iOk=1;
            }
            cli->nstn=i;
        }
        else
        {
            memset(cli->stns[i].stat,0,64);
            memset(cli->stns[i].back,0,64);
            sscanf(cmd,"%%R1P,46:1:%d,'%[^']','%[^']',%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\
                        %lf,%lf,%lf,%lf,%ld\n",
                        &id1,cli->stns[i].stat,cli->stns[i].back,&cli->stns[i].statx,&cli->stns[i].staty,&cli->stns[i].statz,&cli->stns[i].stath,
                        &cli->stns[i].backx,&cli->stns[i].backy,&cli->stns[i].backz,&cli->stns[i].backh,&cli->stns[i].backx1,&cli->stns[i].backy1,&cli->stns[i].backz1,
                        &cli->stns[i].headh[0],&cli->stns[i].headh[1],&cli->stns[i].headv[0],&cli->stns[i].headv[1],&cli->stns[i].midh[0],&cli->stns[i].midh[1],
                        &cli->stns[i].midv[0],&cli->stns[i].midv[1],&cli->stns[i].tailh[0],&cli->stns[i].tailh[1],&cli->stns[i].tailv[0],&cli->stns[i].tailv[1],&cli->stns[i].azi[0],&cli->stns[i].azi[1],
                        &cli->stns[i].pitch[0],&cli->stns[i].pitch[1],&cli->stns[i].roll[0],&cli->stns[i].roll[1],&t1
                        );
            cli->stns[i].t=t1;

            if(i==cli->nstn-1)
            {
                cli->istn=cli->stns[i];
                cli_write_log("读取测站成功",0);
                cli->iOk=1;
            }
        }
        break;
    }
    case 47:
    {
        sscanf(cmd,"%%R1P,47:%d\n",&itl);
        if(itl)
            cli_write_log("测站修改成功",0);
        else
            cli_write_log("测站修改失败",1);
        break;
    }
    case 48:     ///测站（广播）
    {
        if(cli->imode==1)
        {
            break;
        }
        int type=-1;
        i=0;
        t1=0;
        sscanf(cmd,"%%R1D,48:%d:%d",&type,&i);
        if(type==0)
        {
            if(i>0)
            {
                if(cli->stns) cli->stns=(MTG_STATION*)realloc(cli->stns,i*sizeof(MTG_STATION));
                else cli->stns=(MTG_STATION*)malloc(i*sizeof(MTG_STATION));
            }
            cli->nstn=i;
            break;
        }
        else
        {
            memset(cli->stns[i].stat,0,64);
            memset(cli->stns[i].back,0,64);
            sscanf(cmd,"%%R1D,48:1:%d,'%[^']','%[^']',%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\
                        %lf,%lf,%lf,%lf,%ld\n",
                        &id1,cli->stns[i].stat,cli->stns[i].back,&cli->stns[i].statx,&cli->stns[i].staty,&cli->stns[i].statz,&cli->stns[i].stath,
                        &cli->stns[i].backx,&cli->stns[i].backy,&cli->stns[i].backz,&cli->stns[i].backh,&cli->stns[i].backx1,&cli->stns[i].backy1,&cli->stns[i].backz1,
                        &cli->stns[i].headh[0],&cli->stns[i].headh[1],&cli->stns[i].headv[0],&cli->stns[i].headv[1],&cli->stns[i].midh[0],&cli->stns[i].midh[1],
                        &cli->stns[i].midv[0],&cli->stns[i].midv[1],&cli->stns[i].tailh[0],&cli->stns[i].tailh[1],&cli->stns[i].tailv[0],&cli->stns[i].tailv[1],&cli->stns[i].azi[0],&cli->stns[i].azi[1],
                        &cli->stns[i].pitch[0],&cli->stns[i].pitch[1],&cli->stns[i].roll[0],&cli->stns[i].roll[1],&t1
                        );
            cli->stns[i].t=t1;

            if(i==cli->nstn-1)
            {
                cli->istn=cli->stns[i];
                cli_write_log("接收到测站信息广播",0);
            }
        }
        break;
    }
    case 49:     ///历史纪录查询
    {
        sscanf(cmd,"%%R1P,49:%d",&id);
        if(id==0)
        {
            sscanf(cmd,"%%R1P,49:0,%d",&i);
            if(cli->qm)
            {
                free(cli->qm);
                cli->qm=0;
                cli->nqm=0;
            }
            if(i>0)
                cli->qm = (MTG_MEASURE*)malloc(i*sizeof(MTG_MEASURE));
            cli->nqm=0;
            cli->headhMAX=0.0;
            cli->headvMAX=0.0;
            cli_write_log("接收历史查询数据",0);
        }
        else if(id==1)
        {
            double val[52];
            i=cli->nqm;
            if(sscanf(cmd,"%%R1P,49:1,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\
                      %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\
                      %lf,%lf,%lf,%lf,%lf,%lf%lf,%lf,%lf,%d,%d,%ld,%ld,%ld\n",
              &j,&val[0],&val[1],&val[2],&val[3],&val[4],&val[5],&val[6],&val[7],&val[8],&val[9],&val[10],&val[11],&val[12],
              &val[13],&val[14],&val[15],&val[16],&val[17],&val[18],&val[19],&val[20],&val[21],&val[22],&val[23],&val[24],
              &val[25],&val[26],&val[27],&val[28],&val[29],&val[30],&val[31],&val[32],&val[33],&val[34],&val[35],&val[36],
              &val[37],&val[38],&val[39],&val[40],&val[41],&val[42],&val[43],&val[44],&val[45],&val[46],&val[47],&val[48],
              &val[49],&val[50],&val[51],&val[52],&id1,&id2,&t1,&t2,&t3))
            {
                cli->qm[i].inc[0]=val[0];
                cli->qm[i].inc[1]=val[1];
                cli->qm[i].inc[2]=val[2];
                cli->qm[i].cam[0]=val[3];
                cli->qm[i].cam[1]=val[4];
                cli->qm[i].cam[2]=val[5];
                cli->qm[i].cam[3]=val[6];
                cli->qm[i].prism[0]=val[7];
                cli->qm[i].prism[1]=val[8];
                cli->qm[i].prism[2]=val[9];
                cli->qm[i].angle[0]=val[10];
                cli->qm[i].angle[1]=val[11];
                cli->qm[i].comp[0]=val[12];
                cli->qm[i].comp[1]=val[13];
                cli->qm[i].head[0]=val[14];
                cli->qm[i].head[1]=val[15];
                cli->qm[i].head[2]=val[16];
                cli->qm[i].hdes[0]=val[17];
                cli->qm[i].hdes[1]=val[18];
                cli->qm[i].hdes[2]=val[19];
                cli->qm[i].headc=val[20];
                cli->qm[i].headh=val[21];
                cli->qm[i].headv=val[22];
                cli->qm[i].tail[0]=val[23];
                cli->qm[i].tail[1]=val[24];
                cli->qm[i].tail[2]=val[25];
                cli->qm[i].tdes[0]=val[26];
                cli->qm[i].tdes[1]=val[27];
                cli->qm[i].tdes[2]=val[28];
                cli->qm[i].tailc=val[29];
                cli->qm[i].tailh=val[30];
                cli->qm[i].tailv=val[31];
                cli->qm[i].mid[0]=val[32];
                cli->qm[i].mid[1]=val[33];
                cli->qm[i].mid[2]=val[34];
                cli->qm[i].mdes[0]=val[35];
                cli->qm[i].mdes[1]=val[36];
                cli->qm[i].mdes[2]=val[37];
                cli->qm[i].midc=val[38];
                cli->qm[i].midh=val[39];
                cli->qm[i].midv=val[40];
                cli->qm[i].midj[0]=val[41];
                cli->qm[i].midj[1]=val[42];
                cli->qm[i].midj[2]=val[43];
                cli->qm[i].midj[3]=val[44];
                cli->qm[i].aj[0]=val[45];
                cli->qm[i].aj[1]=val[46];
                cli->qm[i].aj[2]=val[47];
                cli->qm[i].aj[3]=val[48];
                cli->qm[i].roll=val[49];
                cli->qm[i].pitch=val[50];
                cli->qm[i].azimuth=val[51];
                cli->qm[i].iset=id1;
                cli->qm[i].iseg=id2;
                cli->qm[i].t1=t1;
                cli->qm[i].t2=t2;
                cli->qm[i].t3=t3;
                cli->nqm++;
            }
        }
        break;
    }
    case 50:     ///查询日志
    {
        sscanf(cmd,"%%R1P,50:%d",&id);
        if(id==0)
        {
            cli->isquery=true;
            sscanf(cmd,"%%R1P,50:0,%d",&maxlog);
            //wxGetApp().logquery.Clear();
            if(cli->qlog)
            {
                free(cli->qlog);
                cli->qlog=0;
            }
            if(maxlog>0)
                cli->qlog = (MTG_LOG*)malloc(maxlog*sizeof(MTG_LOG));
            memset(cli->qlog,0,maxlog*sizeof(MTG_LOG));
            //fprintf(fp,"%d\n",i);
            //cli.lognum=i;
            cli->nqlog=0;
            cli_write_log("接收日志查询信息",0);
            //j=0;
            //fprintf(fp,"%d\n",cli.lognum);
        }
        else if(id==1)
        {
            char lmsg[260]="\0";
            //m_log = (log_t*)malloc(sizeof(log_t));
            //sscanf(cmd,"%%R1P,32:1,%d",&i);
            if(cli->qlog && cli->nqlog<maxlog && sscanf(cmd,"%%R1P,50:1,%d,%d,%ld,'%[^']'",&id1,&id2,&intl,lmsg))
            {
                cli->qlog[cli->nqlog].nlog=id1;
                cli->qlog[cli->nqlog].type=id2;
                cli->qlog[cli->nqlog].t=intl;
                strncpy(cli->qlog[cli->nqlog].msg,lmsg,260);
                cli->qlog[cli->nqm].msg[259]=0;
                cli->nqlog++;
            }
            else
                break;
        }
        else if(id==2)
        {
            cli->isquery=false;
            cli_write_log("日志查询结束",0);
        }
        break;
    }
    default:
        break;
    }
    //fprintf(fp,"total=%d\n",cli.meanum);
    //fprintf(fp,"driver=%s\n",cli.driver);
//    fprintf(fp,"tps='%s',   inc='%s'\n",cli.port.tpscom,cli.port.inccom);
    fclose(fp);
}

void SendCommand(const char* cmd)
{
    sock->Write(cmd,strlen(cmd));
}

int cli_init(mtg_cli*  cli)
{
    int i;
    MTG_MEASURE m0={0};

    memset(cli,0,sizeof(mtg_cli));
    road_init(&cli->r);

    cli->m=m0;
    cli->m1=m0;
    cli->nlog=0;
    cli->iinc=0;
    cli->qlog=0;
    cli->qm=0;

    cli->inc[0]=0.0;
    cli->inc[1]=0.0;
    cli->inc[2]=0.0;


    return 1;
}

void cli_final()
{

    //road_final(&cli.r);
}

void cli_write_log(const char* log,int type)
{
    if(cli->nlog>=200)
        cli->nlog=0;
    cli->nlog++;
    time_t t;
    time(&t);
    cli->logs[cli->nlog-1].t=t;
    cli->logs[cli->nlog-1].type=type;
    strcpy(cli->logs[cli->nlog-1].msg,log);
}

