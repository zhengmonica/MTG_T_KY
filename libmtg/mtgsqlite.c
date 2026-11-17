#include "sqlite3.h"
#include "libmtg.h"

int sqlite_export_db(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[1024];
    int ret=0;
    MTG_TBM* tbm=0;
    h_element* he;
    v_element* ve;
    h_offset* ho;
    v_offset* vo;
    m_offset* mo;

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }

    tbm=&mtg->tbm;
    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

    strcpy(cmd,"create table if not exists meas_set(numb,headc,headx,heady,headz,tailc,tailx,taily,tailz);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sqlite3_exec(db,"delete from  meas_set;",0,0,0);
    sprintf(cmd,"insert into meas_set values(\
            %d,%.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%.12f\
            );",
            mtg->m1.iseg,mtg->m1.headc,mtg->m1.head[0],mtg->m1.head[1],mtg->m1.head[2],
            mtg->m1.tailc,mtg->m1.tail[0],mtg->m1.tail[1],mtg->m1.tail[2]
            );
    ret=sqlite3_exec(db,cmd,0,0,0);

    strcpy(cmd,"create table if not exists tbm_set(name,type,mode,\
           D1,D2,D3,D4,D5,D6,\
           L1,L2,L3,L4,L5,L6,L7,L8,L9,\
           naj,aj1,aj2,aj3,aj4,aj5,aj6,ajunit,\
           nbj,bj1,bj2,bj3,bj4,bjunit,\
           nfj,fj1,fj2,fj3,fj4,fjunit\
           );");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sqlite3_exec(db,"delete from  tbm_set;",0,0,0);
    sprintf(cmd,"insert into tbm_set values(\
                '%s',%d,%d,\
                %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                %d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,\
                %d,%.12f,%.12f,%.12f,%.12f,%d,\
                %d,%.12f,%.12f,%.12f,%.12f,%d)",
                tbm->name,tbm->type,tbm->mode,
                tbm->D[0],tbm->D[1],tbm->D[2],tbm->D[3],tbm->D[4],tbm->D[5],
                tbm->L[0],tbm->L[1],tbm->L[2],tbm->L[3],tbm->L[4],tbm->L[5],tbm->L[6],tbm->L[7],tbm->L[8],
                tbm->naj,tbm->aj[0],tbm->aj[1],tbm->aj[2],tbm->aj[3],tbm->aj[4],tbm->aj[5],tbm->aunit,
                tbm->nbj,tbm->bj[0],tbm->bj[1],tbm->bj[2],tbm->bj[3],tbm->bunit,
                tbm->nfj,tbm->fj[0],tbm->fj[1],tbm->fj[2],tbm->fj[3],tbm->funit
            );
    ret=sqlite3_exec(db,cmd,0,0,0);

    strcpy(cmd,"create table if not exists segment_set(\
           type,ins,f2b,l2s,L,De,D,Ks,G0,G1,s2s);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sqlite3_exec(db,"delete from  segment_set;",0,0,0);
    sprintf(cmd,"insert into segment_set values(\
                %d,%d,%d,%.12f,%.12f,%.12f,%.12f,%d,%.12f,%.12f,%d)",
                mtg->segset.type,mtg->segset.in,mtg->segset.f2b,mtg->segset.l2s,
                mtg->segset.L,mtg->segset.De,mtg->segset.D,mtg->segset.Ks,mtg->segset.G0,mtg->segset.G1,mtg->segset.s2s);
    ret=sqlite3_exec(db,cmd,0,0,0);

    strcpy(cmd,"create table if not exists block_set(\
           name,angle);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sqlite3_exec(db,"delete from  block_set;",0,0,0);
    for(i=0;i<mtg->nblk;i++)
    {
        sprintf(cmd,"insert into block_set values(\
                    '%s',%.12f)",
                    mtg->blocks[i].name,mtg->blocks[i].angle);
        ret=sqlite3_exec(db,cmd,0,0,0);
    }

    strcpy(cmd,"create table if not exists plc_set(drive,amode,\
           aj1,aj2,aj3,aj4,\
           fj1,fj2,fj3,fj4,\
           bj1,bj2,bj3,bj4);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sqlite3_exec(db,"delete from  plc_set;",0,0,0);
    sprintf(cmd,"insert into plc_set values(\
                %d,%d,\
                %.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f)",
                (int)mtg->plc.drive,(int)mtg->plc.amode,
                mtg->aj[0],mtg->aj[1],mtg->aj[2],mtg->aj[3],
                mtg->fj[0],mtg->fj[1],mtg->fj[2],mtg->fj[3],
                mtg->bj[0],mtg->bj[1],mtg->bj[2],mtg->bj[3]
            );
    ret=sqlite3_exec(db,cmd,0,0,0);

    strcpy(cmd,"create table if not exists prj_set(name,mile1,mile2,a2z);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sqlite3_exec(db,"delete from  prj_set;",0,0,0);
    sprintf(cmd,"insert into prj_set values('%s',%.12f,%.12f,%d)",
                mtg->prj.name,mtg->prj.mile1,mtg->prj.mile2,mtg->prj.a2z);
    ret=sqlite3_exec(db,cmd,0,0,0);

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
    //长短链
    strcpy(cmd,"create table if not exists moff(mile,off);");
    sqlite3_exec(db,  cmd, 0, 0, 0);

    ///存储
    sqlite3_exec(db,"delete from  horizon",0,0,0);   ///平曲线
    n=road_number_horizon(&mtg->r);
    for(i=0;i<n;i++)
    {
        he=road_horizon(&mtg->r,i);
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
    n=road_number_vertical(&mtg->r);
    for(i=0;i<n;i++)
    {
        ve=road_vertical(&mtg->r,i);
        sprintf(cmd,"insert into vertical values(\
                %d,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%d,%.12f)",
                ve->type,ve->l1,ve->h1,ve->l2,ve->h2,
                ve->length,ve->radius,ve->angle1,ve->angle2,ve->pz,ve->deta);
        sqlite3_exec(db,cmd,0,0,0);
    }
    sqlite3_exec(db,"delete from hoff",0,0,0);  ///平曲线偏移
    n=road_number_horizon_off(&mtg->r);
    for(i=0;i<n;i++)
    {
        ho=road_horizon_off(&mtg->r,i);
        sprintf(cmd,"insert into hoff values(%.12f,%.12f)",ho->mile,ho->off);
        sqlite3_exec(db,cmd,0,0,0);
    }
    sqlite3_exec(db,"delete from voff",0,0,0);  ///竖曲线偏移
    n=road_number_vertical_off(&mtg->r);
    for(i=0;i<n;i++)
    {
        vo=road_vertical_off(&mtg->r,i);
        sprintf(cmd,"insert into voff values(%.12f,%.12f)",vo->mile,vo->off);
        sqlite3_exec(db,cmd,0,0,0);
    }
    sqlite3_exec(db,"delete from moff",0,0,0);  ///长短链
    n=road_number_mile_off(&mtg->r);
    for(i=0;i<n;i++)
    {
        mo=road_mile_off(&mtg->r,i);
        sprintf(cmd,"insert into moff values(%.12f,%.12f)",mo->mile,mo->off);
        sqlite3_exec(db,cmd,0,0,0);
    }

    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);
    tbm=0;
    return ret;
}

int sqlite_export_meas(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[1024];
    int ret=0;

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }
    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

    strcpy(cmd,"create table if not exists meas_set(numb,headc,headx,heady,headz,tailc,tailx,taily,tailz);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    //sqlite3_exec(db,"delete from  meas_set;",0,0,0);
    sprintf(cmd,"insert into meas_set values(\
            %d,%.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%.12f\
            );",
            mtg->m1.iseg,mtg->m1.headc,mtg->m1.head[0],mtg->m1.head[1],mtg->m1.head[2],
            mtg->m1.tailc,mtg->m1.tail[0],mtg->m1.tail[1],mtg->m1.tail[2]
            );
    ret=sqlite3_exec(db,cmd,0,0,0);
    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);
    return ret;
}

int sqlite_export_tbmset(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[1024];
    int ret=0;
    MTG_TBM* tbm=0;

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }

    tbm=&mtg->tbm;

    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

    strcpy(cmd,"create table if not exists tbm_set(name,type,mode,\
           D1,D2,D3,D4,D5,D6,\
           L1,L2,L3,L4,L5,L6,L7,L8,L9,\
           naj,aj1,aj2,aj3,aj4,aj5,aj6,ajunit,\
           nbj,bj1,bj2,bj3,bj4,bjunit,\
           nfj,fj1,fj2,fj3,fj4,fjunit\
           );");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sqlite3_exec(db,"delete from  tbm_set;",0,0,0);
    sprintf(cmd,"insert into tbm_set values(\
                '%s',%d,%d,\
                %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                %d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,\
                %d,%.12f,%.12f,%.12f,%.12f,%d,\
                %d,%.12f,%.12f,%.12f,%.12f,%d)",
                tbm->name,tbm->type,tbm->mode,
                tbm->D[0],tbm->D[1],tbm->D[2],tbm->D[3],tbm->D[4],tbm->D[5],
                tbm->L[0],tbm->L[1],tbm->L[2],tbm->L[3],tbm->L[4],tbm->L[5],tbm->L[6],tbm->L[7],tbm->L[8],
                tbm->naj,tbm->aj[0],tbm->aj[1],tbm->aj[2],tbm->aj[3],tbm->aj[4],tbm->aj[5],tbm->aunit,
                tbm->nbj,tbm->bj[0],tbm->bj[1],tbm->bj[2],tbm->bj[3],tbm->bunit,
                tbm->nfj,tbm->fj[0],tbm->fj[1],tbm->fj[2],tbm->fj[3],tbm->funit
            );
    ret=sqlite3_exec(db,cmd,0,0,0);
    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);
    tbm=0;
    return ret;
}

int sqlite_export_segset(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[1024];
    int ret=0;

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }

    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

    strcpy(cmd,"create table if not exists segment_set(\
           type,ins,f2b,l2s,L,De,D,Ks,G0,G1,s2s);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sqlite3_exec(db,"delete from  segment_set;",0,0,0);
    sprintf(cmd,"insert into segment_set values(\
                %d,%d,%d,%.12f,%.12f,%.12f,%.12f,%d,%.12f,%.12f,%d)",
                mtg->segset.type,mtg->segset.in,mtg->segset.f2b,mtg->segset.l2s,
                mtg->segset.L,mtg->segset.De,mtg->segset.D,mtg->segset.Ks,mtg->segset.G0,mtg->segset.G1,mtg->segset.s2s);
    ret=sqlite3_exec(db,cmd,0,0,0);
    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);
    return ret;
}

int sqlite_export_block(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[1024];
    int ret=0;

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }

    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

    strcpy(cmd,"create table if not exists block_set(\
           name,angle);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sqlite3_exec(db,"delete from  block_set;",0,0,0);
    for(i=0;i<mtg->nblk;i++)
    {
        sprintf(cmd,"insert into block_set values(\
                    '%s',%.12f)",
                    mtg->blocks[i].name,mtg->blocks[i].angle);
        ret=sqlite3_exec(db,cmd,0,0,0);
    }
    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);
    return ret;
}

int sqlite_export_plc(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[1024];
    int ret=0;

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }

    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

    strcpy(cmd,"create table if not exists plc_set(drive,amode,\
           aj1,aj2,aj3,aj4,\
           fj1,fj2,fj3,fj4,\
           bj1,bj2,bj3,bj4\
           );");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sqlite3_exec(db,"delete from  plc_set;",0,0,0);
    sprintf(cmd,"insert into plc_set values(\
                %d,%d,\
                %.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f\)",
                (int)mtg->plc.drive,(int)mtg->plc.amode,
                mtg->aj[0],mtg->aj[1],mtg->aj[2],mtg->aj[3],
                mtg->fj[0],mtg->fj[1],mtg->fj[2],mtg->fj[3],
                mtg->bj[0],mtg->bj[1],mtg->bj[2],mtg->bj[3]
            );
    ret=sqlite3_exec(db,cmd,0,0,0);
    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);

    return ret;
}

int sqlite_export_prj(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[1024];
    int ret=0;

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }

    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

    strcpy(cmd,"create table if not exists prj_set(name,mile1,mile2,a2z);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sqlite3_exec(db,"delete from  prj_set;",0,0,0);
    sprintf(cmd,"insert into prj_set values('%s',%.12f,%.12f,%d)",
                mtg->prj.name,mtg->prj.mile1,mtg->prj.mile2,mtg->prj.a2z);
    ret=sqlite3_exec(db,cmd,0,0,0);
    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);

    return ret;
}

int sqlite_export_road(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    char cmd[1024];
    int i,n;
    h_element* he;
    v_element* ve;
    h_offset* ho;
    v_offset* vo;
    m_offset* mo;
    road* r;

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }
    r=&mtg->r;

    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

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
    //长短链
    strcpy(cmd,"create table if not exists moff(mile,off);");
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
    sqlite3_exec(db,"delete from hoff",0,0,0);  ///平曲线偏移
    n=road_number_horizon_off(r);
    for(i=0;i<n;i++)
    {
        ho=road_horizon_off(r,i);
        sprintf(cmd,"insert into hoff values(%.12f,%.12f)",ho->mile,ho->off);
        sqlite3_exec(db,cmd,0,0,0);
    }
    sqlite3_exec(db,"delete from voff",0,0,0);  ///竖曲线偏移
    n=road_number_vertical_off(r);
    for(i=0;i<n;i++)
    {
        vo=road_vertical_off(r,i);
        sprintf(cmd,"insert into voff values(%.12f,%.12f)",vo->mile,vo->off);
        sqlite3_exec(db,cmd,0,0,0);
    }
    sqlite3_exec(db,"delete from moff",0,0,0);  ///长短链
    n=road_number_mile_off(r);
    for(i=0;i<n;i++)
    {
        mo=road_mile_off(r,i);
        sprintf(cmd,"insert into moff values(%.12f,%.12f)",mo->mile,mo->off);
        sqlite3_exec(db,cmd,0,0,0);
    }

    sqlite3_exec(db,  "commit transaction", 0, 0, 0);
    sqlite3_close(db);
    return 0;
}

int sqlite_export_dc_meas(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[1024];
    int ret=0;

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }
    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

    strcpy(cmd,"create table if not exists dc_meas_set(numb,headc,headh1,headh2,headv1,headv2,midh1,midh2,midv1,midv2,tailh1,tailh2,tailv1,tailv2,t);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    //sqlite3_exec(db,"delete from  meas_set;",0,0,0);
    sprintf(cmd,"insert into dc_meas_set values(\
            %d,%.12f,\
            %.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%.12f,\
            %.12f,%.12f,%.12f,%.12f,%ld\
            );",
            mtg->m.iseg,mtg->m.mile1,
            mtg->hdev1,mtg->m.hdev1,mtg->vdev1,mtg->m.vdev1,
            mtg->hdev2,mtg->m.hdev2,mtg->vdev2,mtg->m.vdev2,
            mtg->hdev3,mtg->m.hdev3,mtg->vdev3,mtg->m.vdev3,
            (long)mtg->m.t1
            );
    ret=sqlite3_exec(db,cmd,0,0,0);
    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);
    return ret;
}

int sqlite_export_meas_aj(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[4096];
    int ret=0;
    time_t t;
    char timestr[256];
    MTG_MEASURE_AJ* m=&mtg->maj;
    FILE* fp=fopen("D:\\sqlite_export_meas_aj.log","a");
    if(fp)
    {
        time(&t);
        strftime(timestr,64,"%Y-%m-%d %H:%M:%S",localtime(&t));
        fprintf(fp,"%s\n",timestr);fflush(fp);
    }

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        if(fp)
            fclose(fp);
        return -1;
    }
    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);
    //sqlite3_exec(db,  "drop table measure_set;", 0, 0, 0);
    time(&m->t4);
    strcpy(cmd,"create table if not exists measure_set(\
           inc1,inc2,inc3,inc4,cam1,cam2,cam3,cam4,\
           prism1,prism2,prism3,angle1,angle2,comp1,comp2,\
           head1,head2,head3,hdes1,hdes2,hdes3,headc,headh,headv,\
           tail1,tail2,tail3,tdes1,tdes2,tdes3,tailc,tailh,tailv,\
           mile1,hdev1,vdev1,mile2,hdev2,vdev2,mile3,hdev3,vdev3,\
           faj1,faj2,faj3,faj4,baj1,baj2,baj3,baj4,aj1,aj2,aj3,aj4,\
           roll,pitch,azimuth,iseg,t1,t2,t3,iset,\
           daj1,daj2,daj3,daj4,iaj1,iaj2,iaj3,iaj4,t4);");
    sqlite3_exec(db,  cmd, 0, 0, 0);

    sprintf(cmd,"insert into measure_set values(\
            %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%d,%ld,%ld,%ld,%d,\
            %.12f,%.12f,%.12f,%.12f,%d,%d,%d,%d,%ld)",
             m->inc[0],m->inc[1],m->inc[2],m->inc[3],m->cam[0],m->cam[1],m->cam[2],m->cam[3],m->prism[0],m->prism[1],m->prism[2],
             m->angle[0],m->angle[1],m->comp[0],m->comp[1],m->head[0],m->head[1],m->head[2],m->hdes[0],m->hdes[1],m->hdes[2],
             m->headc,m->headh,m->headv,m->tail[0],m->tail[1],m->tail[2],m->tdes[0],m->tdes[1],m->tdes[2],
             m->tailc,m->tailh,m->tailv,m->mile1,m->hdev1,m->vdev1,m->mile2,m->hdev2,m->vdev2,m->mile3,m->hdev3,m->vdev3,
             m->faj[0],m->faj[1],m->faj[2],m->faj[3],m->baj[0],m->baj[1],m->baj[2],m->baj[3],m->aj[0],m->aj[1],m->aj[2],m->aj[3],
             m->inc1[0],m->inc1[1],m->inc1[2],m->iseg,(long)m->t1,(long)m->t2,(long)m->t3,m->iset,
             m->daj[0],m->daj[1],m->daj[2],m->daj[3],m->iaj[0],m->iaj[1],m->iaj[2],m->iaj[3],(long)m->t4
            );

    ret=sqlite3_exec(db,cmd,0,0,0);
    if(ret==0)
    {
        mtg->maj1=*m;
    }
    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);

    if(fp)
    {
        fprintf(fp,"cmd:%s\nret:%d",cmd,ret);
        fflush(fp);fclose(fp);
    }
    return ret;
}

int sqlite_export_origin_aj(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[4096];
    int ret=0;
    time_t t;
    char timestr[256];
    MTG_MEASURE_AJ* m=&mtg->maj;
    FILE* fp=fopen("D:\\sqlite_export_origin_aj.log","a");
    if(fp)
    {
        time(&t);
        strftime(timestr,64,"%Y-%m-%d %H:%M:%S",localtime(&t));
        fprintf(fp,"%s\n",timestr);fflush(fp);
    }

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        if(fp)
            fclose(fp);
        return -1;
    }
    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

//    ret=sqlite3_exec(db,"drop table origin_set;",0,0,0);  ///平曲线偏移
//    if(fp)
//    {
//        fprintf(fp,"cmd:%s,ret:%d\n",cmd,ret);
//        fflush(fp);
//    }
    time(&m->t4);
    strcpy(cmd,"create table if not exists origin_set(\
           inc1,inc2,inc3,inc4,cam1,cam2,cam3,cam4,\
           prism1,prism2,prism3,angle1,angle2,comp1,comp2,\
           head1,head2,head3,hdes1,hdes2,hdes3,headc,headh,headv,\
           tail1,tail2,tail3,tdes1,tdes2,tdes3,tailc,tailh,tailv,\
           mile1,hdev1,vdev1,mile2,hdev2,vdev2,mile3,hdev3,vdev3,\
           faj1,faj2,faj3,faj4,baj1,baj2,baj3,baj4,aj1,aj2,aj3,aj4,\
           roll,pitch,azimuth,iseg,t1,t2,t3,iset,\
           daj1,daj2,daj3,daj4,iaj1,iaj2,iaj3,iaj4,t4,status);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"alter table origin_set add column deth");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"alter table origin_set add column detv");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"alter table origin_set add column coverflag");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"alter table origin_set add column azidiff");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"alter table origin_set add column pitchdiff");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sprintf(cmd,"insert into origin_set values(\
            %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%d,%ld,%ld,%ld,%d,\
            %.12f,%.12f,%.12f,%.12f,%d,%d,%d,%d,%ld,%d,%.12f,%.12f,%d,%.12f,%.12f)",
             m->inc[0],m->inc[1],m->inc[2],m->inc[3],m->cam[0],m->cam[1],m->cam[2],m->cam[3],m->prism[0],m->prism[1],m->prism[2],
             m->angle[0],m->angle[1],m->comp[0],m->comp[1],m->head[0],m->head[1],m->head[2],m->hdes[0],m->hdes[1],m->hdes[2],
             m->headc,m->headh,m->headv,m->tail[0],m->tail[1],m->tail[2],m->tdes[0],m->tdes[1],m->tdes[2],
             m->tailc,m->tailh,m->tailv,m->mile1,m->hdev1,m->vdev1,m->mile2,m->hdev2,m->vdev2,m->mile3,m->hdev3,m->vdev3,
             m->faj[0],m->faj[1],m->faj[2],m->faj[3],m->baj[0],m->baj[1],m->baj[2],m->baj[3],m->aj[0],m->aj[1],m->aj[2],m->aj[3],
             m->inc1[0],m->inc1[1],m->inc1[2],m->iseg,(long)m->t1,(long)m->t2,(long)m->t3,m->iset,
             m->daj[0],m->daj[1],m->daj[2],m->daj[3],m->iaj[0],m->iaj[1],m->iaj[2],m->iaj[3],(long)m->t4,m->status,m->deth,m->detv,
            m->coverflag,m->azidiff,m->pitchdiff
            );

    ret=sqlite3_exec(db,cmd,0,0,0);
    if(ret==0)
    {
        mtg->maj0=*m;
    }
    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);

    if(fp)
    {
        fprintf(fp,"cmd:%s\nret:%d\n",cmd,ret);
        fflush(fp);fclose(fp);
    }
    return ret;
}

int sqlite_update_origin_aj(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[4096];
    int ret=0;
    time_t t;
    char timestr[256];
    MTG_MEASURE_AJ* m=&mtg->maj0;
    FILE* fp=fopen("D:\\sqlite_update_origin_aj.log","a");
    if(fp)
    {
        time(&t);
        strftime(timestr,64,"%Y-%m-%d %H:%M:%S",localtime(&t));
        fprintf(fp,"%s\n",timestr);fflush(fp);
    }

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        if(fp)
            fclose(fp);
        return -1;
    }
    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

//    ret=sqlite3_exec(db,"drop table origin_set;",0,0,0);  ///平曲线偏移
//    if(fp)
//    {
//        fprintf(fp,"cmd:%s,ret:%d\n",cmd,ret);
//        fflush(fp);
//    }
    time(&m->t4);
    strcpy(cmd,"create table if not exists origin_set(\
           inc1,inc2,inc3,inc4,cam1,cam2,cam3,cam4,\
           prism1,prism2,prism3,angle1,angle2,comp1,comp2,\
           head1,head2,head3,hdes1,hdes2,hdes3,headc,headh,headv,\
           tail1,tail2,tail3,tdes1,tdes2,tdes3,tailc,tailh,tailv,\
           mile1,hdev1,vdev1,mile2,hdev2,vdev2,mile3,hdev3,vdev3,\
           faj1,faj2,faj3,faj4,baj1,baj2,baj3,baj4,aj1,aj2,aj3,aj4,\
           roll,pitch,azimuth,iseg,t1,t2,t3,iset,\
           daj1,daj2,daj3,daj4,iaj1,iaj2,iaj3,iaj4,t4,status);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"alter table origin_set add column deth");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"alter table origin_set add column detv");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"alter table origin_set add column coverflag");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"alter table origin_set add column azidiff");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"alter table origin_set add column pitchdiff");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sprintf(cmd,"insert into origin_set values(\
            %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%d,%ld,%ld,%ld,%d,\
            %.12f,%.12f,%.12f,%.12f,%d,%d,%d,%d,%ld,%d,%.12f,%.12f,%d,%.12f,%.12f)",
             m->inc[0],m->inc[1],m->inc[2],m->inc[3],m->cam[0],m->cam[1],m->cam[2],m->cam[3],m->prism[0],m->prism[1],m->prism[2],
             m->angle[0],m->angle[1],m->comp[0],m->comp[1],m->head[0],m->head[1],m->head[2],m->hdes[0],m->hdes[1],m->hdes[2],
             m->headc,m->headh,m->headv,m->tail[0],m->tail[1],m->tail[2],m->tdes[0],m->tdes[1],m->tdes[2],
             m->tailc,m->tailh,m->tailv,m->mile1,m->hdev1,m->vdev1,m->mile2,m->hdev2,m->vdev2,m->mile3,m->hdev3,m->vdev3,
             m->faj[0],m->faj[1],m->faj[2],m->faj[3],m->baj[0],m->baj[1],m->baj[2],m->baj[3],m->aj[0],m->aj[1],m->aj[2],m->aj[3],
             m->inc1[0],m->inc1[1],m->inc1[2],m->iseg,(long)m->t1,(long)m->t2,(long)m->t3,m->iset,
             m->daj[0],m->daj[1],m->daj[2],m->daj[3],m->iaj[0],m->iaj[1],m->iaj[2],m->iaj[3],(long)m->t4,m->status,m->deth,m->detv,
            m->coverflag,m->azidiff,m->pitchdiff
            );

    ret=sqlite3_exec(db,cmd,0,0,0);
    if(ret==0)
    {
        mtg->maj0=*m;
    }
    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);

    if(fp)
    {
        fprintf(fp,"cmd:%s\nret:%d\n",cmd,ret);
        fflush(fp);fclose(fp);
    }
    return ret;
}

int sqlite_export_pdmax(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[4096];
    int ret=0;
    time_t t;
    char timestr[256];
    FILE* fp=fopen("D:\\sqlite_export_pdmax.log","a");
    if(fp)
    {
        time(&t);
        strftime(timestr,64,"%Y-%m-%d %H:%M:%S",localtime(&t));
        fprintf(fp,"%s\n",timestr);fflush(fp);
    }

    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        if(fp)
            fclose(fp);
        return -1;
    }
    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

//    ret=sqlite3_exec(db,"drop table origin_set;",0,0,0);  ///平曲线偏移
//    if(fp)
//    {
//        fprintf(fp,"cmd:%s,ret:%d\n",cmd,ret);
//        fflush(fp);
//    }

    strcpy(cmd,"create table if not exists pdmax_set(pdmax,t);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    sprintf(cmd,"insert into pdmax_set values(%.12f,%ld)",mtg->pd.max,mtg->pd.t);

    ret=sqlite3_exec(db,cmd,0,0,0);
    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);

    if(fp)
    {
        fprintf(fp,"cmd:%s\nret:%d\n",cmd,ret);
        fflush(fp);fclose(fp);
    }
    return ret;
}

int sqlite_import_aj(mtg_t* mtg,const char* path)
{
    sqlite3 *db;
    int rc;
    char cmd[1024];
    sqlite3_stmt * stmt;

    int nResult;
    int nCol,nRow;
    char** pResult;
    char *errmsg;
    MTG_MEASURE_AJ* m={0};
    int ret=0;
    int i=0;
    FILE* fp=fopen("D://sqlite_import_aj.log","w");

    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        if(fp)
            fclose(fp);
        return -1;
    }
    strcpy(cmd,"create table if not exists origin_set(\
           inc1,inc2,inc3,inc4,cam1,cam2,cam3,cam4,\
           prism1,prism2,prism3,angle1,angle2,comp1,comp2,\
           head1,head2,head3,hdes1,hdes2,hdes3,headc,headh,headv,\
           tail1,tail2,tail3,tdes1,tdes2,tdes3,tailc,tailh,tailv,\
           mile1,hdev1,vdev1,mile2,hdev2,vdev2,mile3,hdev3,vdev3,\
           faj1,faj2,faj3,faj4,baj1,baj2,baj3,baj4,aj1,aj2,aj3,aj4,\
           roll,pitch,azimuth,iseg,t1,t2,t3,iset,\
           daj1,daj2,daj3,daj4,iaj1,iaj2,iaj3,iaj4,t4,status,deth,detv);");
    sqlite3_exec(db,  cmd, 0, 0, 0);

    strcpy(cmd,"create table if not exists measure_set(\
           inc1,inc2,inc3,inc4,cam1,cam2,cam3,cam4,\
           prism1,prism2,prism3,angle1,angle2,comp1,comp2,\
           head1,head2,head3,hdes1,hdes2,hdes3,headc,headh,headv,\
           tail1,tail2,tail3,tdes1,tdes2,tdes3,tailc,tailh,tailv,\
           mile1,hdev1,vdev1,mile2,hdev2,vdev2,mile3,hdev3,vdev3,\
           faj1,faj2,faj3,faj4,baj1,baj2,baj3,baj4,aj1,aj2,aj3,aj4,\
           roll,pitch,azimuth,iseg,t1,t2,t3,iset,\
           daj1,daj2,daj3,daj4,iaj1,iaj2,iaj3,iaj4,t4,status);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    strcpy(cmd,"create table if not exists pdmax_set(pdmax,t);");
    sqlite3_exec(db,  cmd, 0, 0, 0);

    strcpy(cmd,"select * from origin_set order by t4 desc limit 1;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    if(fp)
    {
        fprintf(fp,"cmd:%s\n",cmd);fflush(fp);
    }
    nResult=sqlite3_get_table(db,cmd,&pResult,&nRow,&nCol,&errmsg);
    if(fp)
    {
        fprintf(fp,"nRow:%d\n",nRow);fflush(fp);
    }
    m=&mtg->maj0;
    if(sqlite3_step(stmt)==SQLITE_ROW)
    {
        if(fp)
        {
            fprintf(fp,"sqlite3_step(stmt)==SQLITE_ROW\n");fflush(fp);
        }
        i=0;

        m->inc[0] = sqlite3_column_double(stmt,i++);
        m->inc[1] = sqlite3_column_double(stmt,i++);
        m->inc[2] = sqlite3_column_double(stmt,i++);
        m->inc[3] = sqlite3_column_double(stmt,i++);
        m->cam[0] = sqlite3_column_double(stmt,i++);
        m->cam[1] = sqlite3_column_double(stmt,i++);
        m->cam[2] = sqlite3_column_double(stmt,i++);
        m->cam[3] = sqlite3_column_double(stmt,i++);
        m->prism[0] = sqlite3_column_double(stmt,i++);
        m->prism[1] = sqlite3_column_double(stmt,i++);
        m->prism[2] = sqlite3_column_double(stmt,i++);
        m->angle[0] = sqlite3_column_double(stmt,i++);
        m->angle[1] = sqlite3_column_double(stmt,i++);
        m->comp[0] = sqlite3_column_double(stmt,i++);
        m->comp[1] = sqlite3_column_double(stmt,i++);
        m->head[0] = sqlite3_column_double(stmt,i++);
        m->head[1] = sqlite3_column_double(stmt,i++);
        m->head[2] = sqlite3_column_double(stmt,i++);
        m->hdes[0] = sqlite3_column_double(stmt,i++);
        m->hdes[1] = sqlite3_column_double(stmt,i++);
        m->hdes[2] = sqlite3_column_double(stmt,i++);
        m->headc = sqlite3_column_double(stmt,i++);
        m->headh = sqlite3_column_double(stmt,i++);
        m->headv = sqlite3_column_double(stmt,i++);
        m->tail[0] = sqlite3_column_double(stmt,i++);
        m->tail[1] = sqlite3_column_double(stmt,i++);
        m->tail[2] = sqlite3_column_double(stmt,i++);
        m->tdes[0] = sqlite3_column_double(stmt,i++);
        m->tdes[1] = sqlite3_column_double(stmt,i++);
        m->tdes[2] = sqlite3_column_double(stmt,i++);
        m->tailc = sqlite3_column_double(stmt,i++);
        m->tailh = sqlite3_column_double(stmt,i++);
        m->tailv = sqlite3_column_double(stmt,i++);
        m->mile1 = sqlite3_column_double(stmt,i++);
        m->hdev1 = sqlite3_column_double(stmt,i++);
        m->vdev1 = sqlite3_column_double(stmt,i++);
        m->mile2 = sqlite3_column_double(stmt,i++);
        m->hdev2 = sqlite3_column_double(stmt,i++);
        m->vdev2 = sqlite3_column_double(stmt,i++);
        m->mile3 = sqlite3_column_double(stmt,i++);
        m->hdev3 = sqlite3_column_double(stmt,i++);
        m->vdev3 = sqlite3_column_double(stmt,i++);
        m->faj[0] = sqlite3_column_double(stmt,i++);
        m->faj[1] = sqlite3_column_double(stmt,i++);
        m->faj[2] = sqlite3_column_double(stmt,i++);
        m->faj[3] = sqlite3_column_double(stmt,i++);
        m->baj[0] = sqlite3_column_double(stmt,i++);
        m->baj[1] = sqlite3_column_double(stmt,i++);
        m->baj[2] = sqlite3_column_double(stmt,i++);
        m->baj[3] = sqlite3_column_double(stmt,i++);
        m->aj[0] = sqlite3_column_double(stmt,i++);
        m->aj[1] = sqlite3_column_double(stmt,i++);
        m->aj[2] = sqlite3_column_double(stmt,i++);
        m->aj[3] = sqlite3_column_double(stmt,i++);
        m->inc1[0] = sqlite3_column_double(stmt,i++);
        m->inc1[1] = sqlite3_column_double(stmt,i++);
        m->inc1[2] = sqlite3_column_double(stmt,i++);
        m->iseg = sqlite3_column_int(stmt,i++);
        m->t1 = sqlite3_column_int(stmt,i++);
        m->t2 = sqlite3_column_int(stmt,i++);
        m->t3 = sqlite3_column_int(stmt,i++);
        m->iset = sqlite3_column_int(stmt,i++);
        m->daj[0] = sqlite3_column_double(stmt,i++);
        m->daj[1] = sqlite3_column_double(stmt,i++);
        m->daj[2] = sqlite3_column_double(stmt,i++);
        m->daj[3] = sqlite3_column_double(stmt,i++);
        m->iaj[0] = sqlite3_column_int(stmt,i++);
        m->iaj[1] = sqlite3_column_int(stmt,i++);
        m->iaj[2] = sqlite3_column_int(stmt,i++);
        m->iaj[3] = sqlite3_column_int(stmt,i++);
        m->t4= sqlite3_column_int(stmt,i++);
        m->status= sqlite3_column_int(stmt,i++);
        if(nCol>72)
        {
            mtg->deth=m->deth=sqlite3_column_double(stmt,i++);
            mtg->detv=m->detv=sqlite3_column_double(stmt,i++);
            if(fp)
            {
                fprintf(fp,"mtg->deth:%.4f,mtg->detv:%.4f,t4:%ld\n",mtg->deth,mtg->detv,(long)m->t4);fflush(fp);
            }
        }
        if(nCol>=77)
        {
            m->coverflag=sqlite3_column_int(stmt,i++);
            m->azidiff=sqlite3_column_double(stmt,i++);
            m->pitchdiff=sqlite3_column_double(stmt,i++);
        }
        else
        {
            m->coverflag=0;
            m->azidiff=m->pitchdiff=0.0;
        }
        //mtg->maj0=*m;
        ret++;
    }
    sqlite3_finalize(stmt);
    if(fp)
    {
        fprintf(fp,"ret:%d,maj0status:%d\n",ret,m->status);fflush(fp);
    }

    strcpy(cmd,"select * from origin_set where status = 1 order by t4 desc limit 1;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    if(fp)
    {
        fprintf(fp,"cmd:%s\n",cmd);fflush(fp);
    }
    nResult=sqlite3_get_table(db,cmd,&pResult,&nRow,&nCol,&errmsg);
    if(fp)
    {
        fprintf(fp,"nRow:%d\n",nRow);fflush(fp);
    }
    m=&mtg->maj01;
    if(sqlite3_step(stmt)==SQLITE_ROW)
    {
        i=0;
        m->inc[0] = sqlite3_column_double(stmt,i++);
        m->inc[1] = sqlite3_column_double(stmt,i++);
        m->inc[2] = sqlite3_column_double(stmt,i++);
        m->inc[3] = sqlite3_column_double(stmt,i++);
        m->cam[0] = sqlite3_column_double(stmt,i++);
        m->cam[1] = sqlite3_column_double(stmt,i++);
        m->cam[2] = sqlite3_column_double(stmt,i++);
        m->cam[3] = sqlite3_column_double(stmt,i++);
        m->prism[0] = sqlite3_column_double(stmt,i++);
        m->prism[1] = sqlite3_column_double(stmt,i++);
        m->prism[2] = sqlite3_column_double(stmt,i++);
        m->angle[0] = sqlite3_column_double(stmt,i++);
        m->angle[1] = sqlite3_column_double(stmt,i++);
        m->comp[0] = sqlite3_column_double(stmt,i++);
        m->comp[1] = sqlite3_column_double(stmt,i++);
        m->head[0] = sqlite3_column_double(stmt,i++);
        m->head[1] = sqlite3_column_double(stmt,i++);
        m->head[2] = sqlite3_column_double(stmt,i++);
        m->hdes[0] = sqlite3_column_double(stmt,i++);
        m->hdes[1] = sqlite3_column_double(stmt,i++);
        m->hdes[2] = sqlite3_column_double(stmt,i++);
        m->headc = sqlite3_column_double(stmt,i++);
        m->headh = sqlite3_column_double(stmt,i++);
        m->headv = sqlite3_column_double(stmt,i++);
        m->tail[0] = sqlite3_column_double(stmt,i++);
        m->tail[1] = sqlite3_column_double(stmt,i++);
        m->tail[2] = sqlite3_column_double(stmt,i++);
        m->tdes[0] = sqlite3_column_double(stmt,i++);
        m->tdes[1] = sqlite3_column_double(stmt,i++);
        m->tdes[2] = sqlite3_column_double(stmt,i++);
        m->tailc = sqlite3_column_double(stmt,i++);
        m->tailh = sqlite3_column_double(stmt,i++);
        m->tailv = sqlite3_column_double(stmt,i++);
        m->mile1 = sqlite3_column_double(stmt,i++);
        m->hdev1 = sqlite3_column_double(stmt,i++);
        m->vdev1 = sqlite3_column_double(stmt,i++);
        m->mile2 = sqlite3_column_double(stmt,i++);
        m->hdev2 = sqlite3_column_double(stmt,i++);
        m->vdev2 = sqlite3_column_double(stmt,i++);
        m->mile3 = sqlite3_column_double(stmt,i++);
        m->hdev3 = sqlite3_column_double(stmt,i++);
        m->vdev3 = sqlite3_column_double(stmt,i++);
        m->faj[0] = sqlite3_column_double(stmt,i++);
        m->faj[1] = sqlite3_column_double(stmt,i++);
        m->faj[2] = sqlite3_column_double(stmt,i++);
        m->faj[3] = sqlite3_column_double(stmt,i++);
        m->baj[0] = sqlite3_column_double(stmt,i++);
        m->baj[1] = sqlite3_column_double(stmt,i++);
        m->baj[2] = sqlite3_column_double(stmt,i++);
        m->baj[3] = sqlite3_column_double(stmt,i++);
        m->aj[0] = sqlite3_column_double(stmt,i++);
        m->aj[1] = sqlite3_column_double(stmt,i++);
        m->aj[2] = sqlite3_column_double(stmt,i++);
        m->aj[3] = sqlite3_column_double(stmt,i++);
        m->inc1[0] = sqlite3_column_double(stmt,i++);
        m->inc1[1] = sqlite3_column_double(stmt,i++);
        m->inc1[2] = sqlite3_column_double(stmt,i++);
        m->iseg = sqlite3_column_int(stmt,i++);
        m->t1 = sqlite3_column_int(stmt,i++);
        m->t2 = sqlite3_column_int(stmt,i++);
        m->t3 = sqlite3_column_int(stmt,i++);
        m->iset = sqlite3_column_int(stmt,i++);
        m->daj[0] = sqlite3_column_double(stmt,i++);
        m->daj[1] = sqlite3_column_double(stmt,i++);
        m->daj[2] = sqlite3_column_double(stmt,i++);
        m->daj[3] = sqlite3_column_double(stmt,i++);
        m->iaj[0] = sqlite3_column_int(stmt,i++);
        m->iaj[1] = sqlite3_column_int(stmt,i++);
        m->iaj[2] = sqlite3_column_int(stmt,i++);
        m->iaj[3] = sqlite3_column_int(stmt,i++);
        m->t4= sqlite3_column_int(stmt,i++);
        m->status= sqlite3_column_int(stmt,i++);
        if(nCol>72)
        {
            m->deth=sqlite3_column_double(stmt,i++);
            m->detv=sqlite3_column_double(stmt,i++);
        }
        if(nCol>=77)
        {
            m->coverflag=sqlite3_column_int(stmt,i++);
            m->azidiff=sqlite3_column_double(stmt,i++);
            m->pitchdiff=sqlite3_column_double(stmt,i++);
        }
        //mtg->maj01=*m;
        ret++;
    }
    sqlite3_finalize(stmt);
    if(fp)
    {
        fprintf(fp,"ret:%d,maj01status:%d\n",ret,m->status);fflush(fp);
    }

    strcpy(cmd,"select * from measure_set order by t4 desc limit 1;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    nResult=sqlite3_get_table(db,cmd,&pResult,&nRow,&nCol,&errmsg);
    m=&mtg->maj1;
    if(sqlite3_step(stmt)==SQLITE_ROW)
    {
        if(fp)
        {
            fprintf(fp,"2sqlite3_step(stmt)==SQLITE_ROW\n");fflush(fp);
        }
        i=0;

        m->inc[0] = sqlite3_column_double(stmt,i++);
        m->inc[1] = sqlite3_column_double(stmt,i++);
        m->inc[2] = sqlite3_column_double(stmt,i++);
        m->inc[3] = sqlite3_column_double(stmt,i++);
        m->cam[0] = sqlite3_column_double(stmt,i++);
        m->cam[1] = sqlite3_column_double(stmt,i++);
        m->cam[2] = sqlite3_column_double(stmt,i++);
        m->cam[3] = sqlite3_column_double(stmt,i++);
        m->prism[0] = sqlite3_column_double(stmt,i++);
        m->prism[1] = sqlite3_column_double(stmt,i++);
        m->prism[2] = sqlite3_column_double(stmt,i++);
        m->angle[0] = sqlite3_column_double(stmt,i++);
        m->angle[1] = sqlite3_column_double(stmt,i++);
        m->comp[0] = sqlite3_column_double(stmt,i++);
        m->comp[1] = sqlite3_column_double(stmt,i++);
        m->head[0] = sqlite3_column_double(stmt,i++);
        m->head[1] = sqlite3_column_double(stmt,i++);
        m->head[2] = sqlite3_column_double(stmt,i++);
        m->hdes[0] = sqlite3_column_double(stmt,i++);
        m->hdes[1] = sqlite3_column_double(stmt,i++);
        m->hdes[2] = sqlite3_column_double(stmt,i++);
        m->headc = sqlite3_column_double(stmt,i++);
        m->headh = sqlite3_column_double(stmt,i++);
        m->headv = sqlite3_column_double(stmt,i++);
        m->tail[0] = sqlite3_column_double(stmt,i++);
        m->tail[1] = sqlite3_column_double(stmt,i++);
        m->tail[2] = sqlite3_column_double(stmt,i++);
        m->tdes[0] = sqlite3_column_double(stmt,i++);
        m->tdes[1] = sqlite3_column_double(stmt,i++);
        m->tdes[2] = sqlite3_column_double(stmt,i++);
        m->tailc = sqlite3_column_double(stmt,i++);
        m->tailh = sqlite3_column_double(stmt,i++);
        m->tailv = sqlite3_column_double(stmt,i++);
        m->mile1 = sqlite3_column_double(stmt,i++);
        m->hdev1 = sqlite3_column_double(stmt,i++);
        m->vdev1 = sqlite3_column_double(stmt,i++);
        m->mile2 = sqlite3_column_double(stmt,i++);
        m->hdev2 = sqlite3_column_double(stmt,i++);
        m->vdev2 = sqlite3_column_double(stmt,i++);
        m->mile3 = sqlite3_column_double(stmt,i++);
        m->hdev3 = sqlite3_column_double(stmt,i++);
        m->vdev3 = sqlite3_column_double(stmt,i++);
        m->faj[0] = sqlite3_column_double(stmt,i++);
        m->faj[1] = sqlite3_column_double(stmt,i++);
        m->faj[2] = sqlite3_column_double(stmt,i++);
        m->faj[3] = sqlite3_column_double(stmt,i++);
        m->baj[0] = sqlite3_column_double(stmt,i++);
        m->baj[1] = sqlite3_column_double(stmt,i++);
        m->baj[2] = sqlite3_column_double(stmt,i++);
        m->baj[3] = sqlite3_column_double(stmt,i++);
        m->aj[0] = sqlite3_column_double(stmt,i++);
        m->aj[1] = sqlite3_column_double(stmt,i++);
        m->aj[2] = sqlite3_column_double(stmt,i++);
        m->aj[3] = sqlite3_column_double(stmt,i++);
        m->inc1[0] = sqlite3_column_double(stmt,i++);
        m->inc1[1] = sqlite3_column_double(stmt,i++);
        m->inc1[2] = sqlite3_column_double(stmt,i++);
        m->iseg = sqlite3_column_int(stmt,i++);
        m->t1 = sqlite3_column_int(stmt,i++);
        m->t2 = sqlite3_column_int(stmt,i++);
        m->t3 = sqlite3_column_int(stmt,i++);
        m->iset = sqlite3_column_int(stmt,i++);
        m->daj[0] = sqlite3_column_double(stmt,i++);
        m->daj[1] = sqlite3_column_double(stmt,i++);
        m->daj[2] = sqlite3_column_double(stmt,i++);
        m->daj[3] = sqlite3_column_double(stmt,i++);
        m->iaj[0] = sqlite3_column_int(stmt,i++);
        m->iaj[1] = sqlite3_column_int(stmt,i++);
        m->iaj[2] = sqlite3_column_int(stmt,i++);
        m->iaj[3] = sqlite3_column_int(stmt,i++);
        m->t4= sqlite3_column_int(stmt,i++);
        //mtg->maj1=*m;
        ret++;
    }
    sqlite3_finalize(stmt);

    strcpy(cmd,"select * from pdmax_set order by t desc limit 1;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    nResult=sqlite3_get_table(db,cmd,&pResult,&nRow,&nCol,&errmsg);

    if(sqlite3_step(stmt)==SQLITE_ROW)
    {
        if(fp)
        {
            fprintf(fp,"3sqlite3_step(stmt)==SQLITE_ROW\n");fflush(fp);
        }
        i=0;
        mtg->pd.max = sqlite3_column_double(stmt,i++);
        mtg->pd.t = sqlite3_column_int(stmt,i++);
        ret++;
    }
	sqlite3_finalize(stmt);
    if(fp)
    {
        fprintf(fp,"33sqlite3_step(stmt)==SQLITE_ROW\n");fflush(fp);
    }

    sqlite3_close(db);

    if(fp)
    {
        fprintf(fp,"ret:%d\nclose\n",ret);
        fclose(fp);
    }
    return ret;
}
