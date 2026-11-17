#include "libmtg.h"
#include "mysql/mysql.h"
#define PI  3.1415926535897932384626433832795
#include "sqlite3.h"
#include "string.h"

int mtg_init_db(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[4096];
	int i = 0;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,0,0,NULL,CLIENT_MULTI_STATEMENTS))
    {
        sprintf(cmd,"create database if not exists %s",mtg->db);
	    mysql_real_query(&mysql,cmd,strlen(cmd));
	    mysql_close(&mysql);
	    trace(0,"Database: create database successful\n");
    }
    mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    ret=1;
	    ///begin
	    strcpy(cmd,"start transaction");
	    mysql_real_query(&mysql,cmd,strlen(cmd));
	    strcpy(cmd,"drop table prj_set");
	    mysql_real_query(&mysql,cmd,strlen(cmd));
	    ///工程信息表
	    strcpy(cmd,"create table prj_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `name` char(64) DEFAULT NULL,\
            `mile1` double DEFAULT NULL,\
            `mile2` double DEFAULT NULL,\
            `a2z` int(11) DEFAULT NULL,\
            `duty` int(11) DEFAULT NULL,\
            `duty1` char(64) DEFAULT NULL,\
            `duty2` char(64) DEFAULT NULL,\
            `duty3` char(64) DEFAULT NULL,\
            `duty4` char(64) DEFAULT NULL,\
            `htip` int(11) DEFAULT NULL,\
            `vtip` int(11) DEFAULT NULL,\
            `tip` double DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		strcpy(cmd,"insert into prj_set values (1,'123',0.0,0.0,1,2,'张三','李四','','',0,0,50)");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        ///关键区域
		strcpy(cmd,"drop table key_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table key_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `name` char(64) DEFAULT NULL,\
            `mile1` double DEFAULT NULL,\
            `mile2` double DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		///管环监测
		strcpy(cmd,"drop table smonitor_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table smonitor_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `number` int(11) DEFAULT NULL,\
            `monitor` int(11) DEFAULT NULL,\
            `cycle` int(11) DEFAULT NULL,\
            `last` int(11) DEFAULT NULL,\
            `iseg` int(11) DEFAULT NULL,\
            `headc` double DEFAULT NULL,\
            `x` double DEFAULT NULL,\
            `y` double DEFAULT NULL,\
            `z` double DEFAULT NULL,\
            `x1` double DEFAULT NULL,\
            `y1` double DEFAULT NULL,\
            `z1` double DEFAULT NULL,\
            `t` int(11) DEFAULT NULL,\
            `dv` double DEFAULT NULL,\
            `dv1` double DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		///环号计算
		strcpy(cmd,"drop table serial_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table serial_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `iseg` int(11) DEFAULT NULL,\
            `mile` double DEFAULT NULL,\
            `tm` double DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		///盾构设置
        strcpy(cmd,"drop table tbm_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table tbm_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `name` char(64) DEFAULT NULL,\
            `type` int(11) DEFAULT NULL,\
            `mode` int(11) DEFAULT NULL,\
            `D1` double DEFAULT NULL,\
            `D2` double DEFAULT NULL,\
            `D3` double DEFAULT NULL,\
            `D4` double DEFAULT NULL,\
            `D5` double DEFAULT NULL,\
            `D6` double DEFAULT NULL,\
            `L1` double DEFAULT NULL,\
            `L2` double DEFAULT NULL,\
            `L3` double DEFAULT NULL,\
            `L4` double DEFAULT NULL,\
            `L5` double DEFAULT NULL,\
            `L6` double DEFAULT NULL,\
            `L7` double DEFAULT NULL,\
            `L8` double DEFAULT NULL,\
            `L9` double DEFAULT NULL,\
            `naj` int(11) DEFAULT NULL,\
            `aj1` double DEFAULT NULL,\
            `aj2` double DEFAULT NULL,\
            `aj3` double DEFAULT NULL,\
            `aj4` double DEFAULT NULL,\
            `aj5` double DEFAULT NULL,\
            `aj6` double DEFAULT NULL,\
            `ajunit` int(11) DEFAULT NULL,\
            `nbj` int(11) DEFAULT NULL,\
            `bj1` double DEFAULT NULL,\
            `bj2` double DEFAULT NULL,\
            `bj3` double DEFAULT NULL,\
            `bj4` double DEFAULT NULL,\
            `bjunit` int(11) DEFAULT NULL,\
            `nfj` int(11) DEFAULT NULL,\
            `fj1` double DEFAULT NULL,\
            `fj2` double DEFAULT NULL,\
            `fj3` double DEFAULT NULL,\
            `fj4` double DEFAULT NULL,\
            `fjunit` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		strcpy(cmd,"insert into tbm_set values (1,'123',0,0,5.5,5.8,5.0,6.0,6.28,6.28,3.28,3.0,3.45,5.28,2.78,1.0,5.78,1.0,0.4,\
         4,4.71238898,0.0,1.570796327,3.141592654,0.0,0.0,1,\
         4,4.71238898,0.0,1.570796327,3.141592654,1,\
         4,4.71238898,0.0,1.570796327,3.141592654,1)");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);

		///相机参数设置
		strcpy(cmd,"drop table cam_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table cam_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `width` int(11) DEFAULT NULL,\
            `height` int(11) DEFAULT NULL,\
            `a1` double DEFAULT NULL,\
            `a2` double DEFAULT NULL,\
            `a3` double DEFAULT NULL,\
            `b1` double DEFAULT NULL,\
            `b2` double DEFAULT NULL,\
            `b3` double DEFAULT NULL,\
            `c1` double DEFAULT NULL,\
            `c2` double DEFAULT NULL,\
            `c3` double DEFAULT NULL,\
            `lx` int(11) DEFAULT NULL,\
            `ly` int(11) DEFAULT NULL,\
            `rx` int(11) DEFAULT NULL,\
            `ry` int(11) DEFAULT NULL,\
			`name` char(64) DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);

		///地图参数设置
		strcpy(cmd,"drop table map_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table map_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `w1` int(11) DEFAULT NULL,\
            `h1` int(11) DEFAULT NULL,\
            `dx1` double DEFAULT NULL,\
            `dy1` double DEFAULT NULL,\
            `s1` double DEFAULT NULL,\
            `w2` int(11) DEFAULT NULL,\
            `h2` int(11) DEFAULT NULL,\
            `dx2` double DEFAULT NULL,\
            `dy2` double DEFAULT NULL,\
            `s2` double DEFAULT NULL,\
            `w3` int(11) DEFAULT NULL,\
            `h3` int(11) DEFAULT NULL,\
            `dx3` double DEFAULT NULL,\
            `dy3` double DEFAULT NULL,\
            `s3` double DEFAULT NULL,\
            `w4` int(11) DEFAULT NULL,\
            `h4` int(11) DEFAULT NULL,\
            `dx4` double DEFAULT NULL,\
            `dy4` double DEFAULT NULL,\
            `s4` double DEFAULT NULL,\
            `w5` int(11) DEFAULT NULL,\
            `h5` int(11) DEFAULT NULL,\
            `dx5` double DEFAULT NULL,\
            `dy5` double DEFAULT NULL,\
            `s5` double DEFAULT NULL,\
            `r` double DEFAULT NULL,\
			`name` char(64) DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		///激光靶参数设置
		strcpy(cmd,"drop table target_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table target_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `ver` int(11) DEFAULT NULL,\
            `prism1` double DEFAULT NULL,\
            `prism2` double DEFAULT NULL,\
            `prism3` double DEFAULT NULL,\
            `prism4` double DEFAULT NULL,\
            `prism5` double DEFAULT NULL,\
            `prism6` double DEFAULT NULL,\
            `prism7` double DEFAULT NULL,\
            `prism8` double DEFAULT NULL,\
            `prism9` double DEFAULT NULL,\
            `prism10` double DEFAULT NULL,\
            `prism11` double DEFAULT NULL,\
            `prism12` double DEFAULT NULL,\
            `prc` double DEFAULT NULL,\
            `length` double DEFAULT NULL,\
            `cam` int(11) DEFAULT NULL,\
            `inc` int(11) DEFAULT NULL,\
            `pposition` int(11) DEFAULT NULL,\
            `tposition` int(11) DEFAULT NULL,\
            `incdb` int(11) DEFAULT NULL,\
            `ctsalw` int(11) DEFAULT NULL,\
            `dtsalw` int(11) DEFAULT NULL,\
            `stpd` int(11) DEFAULT NULL,\
            `angalw` double DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);

		///全站仪参数设置
		strcpy(cmd,"drop table tps_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table tps_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `type` int(11) DEFAULT NULL,\
            `laser` int(11) DEFAULT NULL,\
            `laserh` double DEFAULT NULL,\
            `laserd1` double DEFAULT NULL,\
            `laserd2` double DEFAULT NULL,\
            `laserx1` double DEFAULT NULL,\
            `lasery1` double DEFAULT NULL,\
            `laserx2` double DEFAULT NULL,\
            `lasery2` double DEFAULT NULL,\
            `edm` int(11) DEFAULT NULL,\
            `comp` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		strcpy(cmd,"insert into tps_set values (1,3,1,0.0,100.0,100.0,0.0,0.0,0.0,0.0,1,1)");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
		///管块设置
		strcpy(cmd,"drop table block_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table block_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `name` char(64) DEFAULT NULL,\
            `angle` double DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
        sprintf(cmd,
             "insert into block_set values (1,'K',0.375245789178781),(2,'B2',1.18682389135614),(3,'A3',1.17809724509617),(4,'A2',1.17809724509617),(5,'A1',1.17809724509617),(6,'B1',1.18682389135614)");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);

		///测量设置
		strcpy(cmd,"drop table config_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table config_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `cyc` int(11) DEFAULT NULL,\
            `bcyc` int(11) DEFAULT NULL,\
            `palw` int(11) DEFAULT NULL,\
            `jalw` int(11) DEFAULT NULL,\
            `balw` int(11) DEFAULT NULL,\
            `talw` int(11) DEFAULT NULL,\
            `vibration` int(11) DEFAULT NULL,\
            `rstn` int(11) DEFAULT NULL,\
            `tsyn` int(11) DEFAULT NULL,\
            `rget` int(11) DEFAULT NULL,\
            `idrv` int(11) DEFAULT NULL,\
            `prun` int(11) DEFAULT NULL,\
            `pend` int(11) DEFAULT NULL,\
            `psas` int(11) DEFAULT NULL,\
            `pchk` int(11) DEFAULT NULL,\
            `pqry` int(11) DEFAULT NULL,\
            `pmap` int(11) DEFAULT NULL,\
            `psmr` int(11) DEFAULT NULL,\
            `pquit` int(11) DEFAULT NULL,\
            `unit` int(11) DEFAULT NULL,\
            `vmileage` int(11) DEFAULT NULL,\
            `head` int(11) DEFAULT NULL,\
            `tbm3d` int(11) DEFAULT NULL,\
            `heading` int(11) DEFAULT NULL,\
            `povr` int(11) DEFAULT NULL,\
            `jovr` int(11) DEFAULT NULL,\
            `bovr` int(11) DEFAULT NULL,\
            `tovr` int(11) DEFAULT NULL,\
            `toEr` int(11) DEFAULT NULL,\
            `flen` double DEFAULT NULL,\
            `fdev` double DEFAULT NULL,\
            `tgap` double DEFAULT NULL,\
            `lang` int(11) DEFAULT NULL,\
            `symtype` int(11) DEFAULT NULL,\
            `backflag` int(11) DEFAULT NULL,\
            `plctype` int(11) DEFAULT NULL,\
            `aalw` double DEFAULT NULL,\
            `tailapply` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		strcpy(cmd,"insert into config_set values (1,120,1800,50,15,8,360,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0,0,0,1,0,2.0,0)");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
		///吊篮坐标
		strcpy(cmd,"drop table basket_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table basket_set(\
            `name` char(64) DEFAULT NULL,\
            `x` double DEFAULT NULL,\
            `y` double DEFAULT NULL,\
            `z` double DEFAULT NULL,\
            `t` int(11) DEFAULT NULL,\
            PRIMARY KEY (`name`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		///账户管理
		strcpy(cmd,"drop table user_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table user_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `name` char(64) DEFAULT NULL,\
            `password` char(64) DEFAULT NULL,\
            `level` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		strcpy(cmd,"insert into user_set values (1,'Admin','20100101',0)");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        strcpy(cmd,"insert into user_set values (2,'Operator','123',1)");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
		///零位数据
		strcpy(cmd,"drop table given_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table given_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `inc1` double DEFAULT NULL,\
            `inc2` double DEFAULT NULL,\
            `inc3` double DEFAULT NULL,\
            `inc4` double DEFAULT NULL,\
            `cam1` double DEFAULT NULL,\
            `cam2` double DEFAULT NULL,\
            `cam3` double DEFAULT NULL,\
            `cam4` double DEFAULT NULL,\
            `prism1` double DEFAULT NULL,\
            `prism2` double DEFAULT NULL,\
            `prism3` double DEFAULT NULL,\
            `angle1` double DEFAULT NULL,\
            `angle2` double DEFAULT NULL,\
            `comp1`  double DEFAULT NULL,\
            `comp2`  double DEFAULT NULL,\
            `head1` double DEFAULT NULL,\
            `head2` double DEFAULT NULL,\
            `head3` double DEFAULT NULL,\
            `tail1` double DEFAULT NULL,\
            `tail2` double DEFAULT NULL,\
            `tail3` double DEFAULT NULL,\
            `faj1` double DEFAULT NULL,\
            `faj2` double DEFAULT NULL,\
            `faj3` double DEFAULT NULL,\
            `faj4` double DEFAULT NULL,\
            `baj1` double DEFAULT NULL,\
            `baj2` double DEFAULT NULL,\
            `baj3` double DEFAULT NULL,\
            `baj4` double DEFAULT NULL,\
            `aj1` double DEFAULT NULL,\
            `aj2` double DEFAULT NULL,\
            `aj3` double DEFAULT NULL,\
            `aj4` double DEFAULT NULL,\
            `roll` double DEFAULT NULL,\
            `pitch` double DEFAULT NULL,\
            `azimuth` double DEFAULT NULL,\
            `mppsm1` double DEFAULT NULL,\
            `mppsm2` double DEFAULT NULL,\
            `mppsm3` double DEFAULT NULL,\
            `mppsm4` double DEFAULT NULL,\
            `mppsm5` double DEFAULT NULL,\
            `mppsm6` double DEFAULT NULL,\
            `mppsm7` double DEFAULT NULL,\
            `mppsm8` double DEFAULT NULL,\
            `mppsm9` double DEFAULT NULL,\
            `t1` int(11) DEFAULT NULL,\
            `t2` int(11) DEFAULT NULL,\
            `t3` int(11) DEFAULT NULL,\
            `ipos` int(11) DEFAULT NULL,\
            `t4` int(11) DEFAULT 0,\
            `t5` int(11) DEFAULT 0,\
            `inc12` double DEFAULT 0,\
            `inc22` double DEFAULT 0,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);

		///观测值
		strcpy(cmd,"drop table measure_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table measure_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `inc1` double DEFAULT NULL,\
            `inc2` double DEFAULT NULL,\
            `inc3` double DEFAULT NULL,\
            `inc4` double DEFAULT NULL,\
            `cam1` double DEFAULT NULL,\
            `cam2` double DEFAULT NULL,\
            `cam3` double DEFAULT NULL,\
            `cam4` double DEFAULT NULL,\
            `prism1` double DEFAULT NULL,\
            `prism2` double DEFAULT NULL,\
            `prism3` double DEFAULT NULL,\
            `angle1` double DEFAULT NULL,\
            `angle2` double DEFAULT NULL,\
            `comp1`  double DEFAULT NULL,\
            `comp2`  double DEFAULT NULL,\
            `head1` double DEFAULT NULL,\
            `head2` double DEFAULT NULL,\
            `head3` double DEFAULT NULL,\
            `hdes1` double DEFAULT NULL,\
            `hdes2` double DEFAULT NULL,\
            `hdes3` double DEFAULT NULL,\
            `headc` double DEFAULT NULL,\
            `headh` double DEFAULT NULL,\
            `headv` double DEFAULT NULL,\
            `tail1` double DEFAULT NULL,\
            `tail2` double DEFAULT NULL,\
            `tail3` double DEFAULT NULL,\
            `tdes1` double DEFAULT NULL,\
            `tdes2` double DEFAULT NULL,\
            `tdes3` double DEFAULT NULL,\
            `tailc` double DEFAULT NULL,\
            `tailh` double DEFAULT NULL,\
            `tailv` double DEFAULT NULL,\
            `mile1` double DEFAULT NULL,\
            `hdev1` double DEFAULT NULL,\
            `vdev1` double DEFAULT NULL,\
            `mile2` double DEFAULT NULL,\
            `hdev2` double DEFAULT NULL,\
            `vdev2` double DEFAULT NULL,\
            `mile3` double DEFAULT NULL,\
            `hdev3` double DEFAULT NULL,\
            `vdev3` double DEFAULT NULL,\
            `faj1` double DEFAULT NULL,\
            `faj2` double DEFAULT NULL,\
            `faj3` double DEFAULT NULL,\
            `faj4` double DEFAULT NULL,\
            `baj1` double DEFAULT NULL,\
            `baj2` double DEFAULT NULL,\
            `baj3` double DEFAULT NULL,\
            `baj4` double DEFAULT NULL,\
            `aj1` double DEFAULT NULL,\
            `aj2` double DEFAULT NULL,\
            `aj3` double DEFAULT NULL,\
            `aj4` double DEFAULT NULL,\
            `roll` double DEFAULT NULL,\
            `pitch` double DEFAULT NULL,\
            `azimuth` double DEFAULT NULL,\
            `iseg` int(11) DEFAULT NULL,\
            `t1` int(11) DEFAULT NULL,\
            `t2` int(11) DEFAULT NULL,\
            `t3` int(11) DEFAULT NULL,\
            `iset` int(11) DEFAULT NULL,\
            `headtail1` double DEFAULT NULL,\
            `headtail2` double DEFAULT NULL,\
            `headtail3` double DEFAULT NULL,\
            `headtaildes1` double DEFAULT NULL,\
            `headtaildes2` double DEFAULT NULL,\
            `headtaildes3` double DEFAULT NULL,\
            `t5` int(11) DEFAULT 0,\
            `inc12` double DEFAULT 0,\
            `inc22` double DEFAULT 0,\
            `inc41` double DEFAULT 0,\
            `inc42` double DEFAULT 0,\
            PRIMARY KEY (`id`)\
            )");

		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);

        ///棱镜检核
		strcpy(cmd,"drop table mcheck_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table mcheck_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `head1` double DEFAULT NULL,\
            `head2` double DEFAULT NULL,\
            `head3` double DEFAULT NULL,\
            `head4` double DEFAULT NULL,\
            `head5` double DEFAULT NULL,\
            `head6` double DEFAULT NULL,\
            `tail1` double DEFAULT NULL,\
            `tail2` double DEFAULT NULL,\
            `tail3` double DEFAULT NULL,\
            `tail4` double DEFAULT NULL,\
            `tail5` double DEFAULT NULL,\
            `tail6` double DEFAULT NULL,\
            `psm1` double DEFAULT NULL,\
            `psm2` double DEFAULT NULL,\
            `psm3` double DEFAULT NULL,\
            `psm4` double DEFAULT NULL,\
            `psm5` double DEFAULT NULL,\
            `psm6` double DEFAULT NULL,\
            `psm7` double DEFAULT NULL,\
            `psm8`  double DEFAULT NULL,\
            `inc1`  double DEFAULT NULL,\
            `inc2` double DEFAULT NULL,\
            `inc3` double DEFAULT NULL,\
            `inc4`  double DEFAULT NULL,\
            `inc5` double DEFAULT NULL,\
            `inc6` double DEFAULT NULL,\
            `headc` double DEFAULT NULL,\
            `headh` double DEFAULT NULL,\
            `headv` double DEFAULT NULL,\
            `headh1` double DEFAULT NULL,\
            `headv1` double DEFAULT NULL,\
            `tailc` double DEFAULT NULL,\
            `tailh` double DEFAULT NULL,\
            `tailv` double DEFAULT NULL,\
            `tailh1` double DEFAULT NULL,\
            `tailv1` double DEFAULT NULL,\
            `t` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);

		///设站信息
		strcpy(cmd,"drop table station_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table station_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `stat` char(64) DEFAULT NULL,\
            `back` char(64) DEFAULT NULL,\
            `statx` double DEFAULT NULL,\
            `staty` double DEFAULT NULL,\
            `statz` double DEFAULT NULL,\
            `stath` double DEFAULT NULL,\
            `backx` double DEFAULT NULL,\
            `backy` double DEFAULT NULL,\
            `backz` double DEFAULT NULL,\
            `backh` double DEFAULT NULL,\
            `backx1` double DEFAULT NULL,\
            `backy1` double DEFAULT NULL,\
            `backz1` double DEFAULT NULL,\
            `headh1` double DEFAULT NULL,\
            `headh2` double DEFAULT NULL,\
            `tailh1` double DEFAULT NULL,\
            `tailh2` double DEFAULT NULL,\
            `headv1` double DEFAULT NULL,\
            `headv2` double DEFAULT NULL,\
            `tailv1` double DEFAULT NULL,\
            `tailv2` double DEFAULT NULL,\
            `azi1` double DEFAULT NULL,\
            `azi2` double DEFAULT NULL,\
            `pitch1` double DEFAULT NULL,\
            `pitch2` double DEFAULT NULL,\
            `roll1` double DEFAULT NULL,\
            `roll2` double DEFAULT NULL,\
            `t` int(11) DEFAULT NULL,\
            `anglediff` double DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		///平曲线表
		strcpy(cmd,"drop table horizon_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table horizon_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `type` int(11) default null,\
               `l1` double default null,\
               `length` double default null,\
               `angle1` double default null,\
               `angle2` double default null,\
               `radius` double default null,\
               `rou1` double default null,\
               `rou2` double default null,\
               `x1` double default null,\
               `y1` double default null,\
               `x2` double default null,\
               `y2` double default null,\
               `pz` int(11) default null,\
               `deta` double default null,\
               PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        strcpy(cmd,"insert into horizon_set values (1,0,0,0,0,0,0,0,0,0,0,0,0,0,0.0),(2,4,0,0,0,0,0,0,0,0,0,0,0,0,0.0)");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        ///竖曲线表
        strcpy(cmd,"drop table vertical_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table vertical_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `type` int(11) default null,\
               `l1`  double default null,\
               `h1` double default null,\
               `l2` double default null,\
               `h2` double default null,\
               `length` double default null,\
               `radius` double default null,\
               `angle1` double default null,\
               `angle2` double default null,\
               `pz` int(11) default null,\
               `deta` double default null,\
               PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        strcpy(cmd,"insert into vertical_set values (1,0,0,0,0,0,0,0,0,0,0,0.0),(2,4,0,0,0,0,0,0,0,0,0,0.0)");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        ///平曲线偏移表
        strcpy(cmd,"drop table hoff_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table hoff_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `mile` double default null,\
               `off` double default null,\
               PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        ///竖曲线偏移表
        strcpy(cmd,"drop table voff_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table voff_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `mile` double default null,\
               `off` double default null,\
               PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        ///里程偏移表
        strcpy(cmd,"drop table moff_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table moff_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `mile` double default null,\
               `off` double default null,\
               PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        ///管环历史拼装
        strcpy(cmd,"drop table seged_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table seged_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `numb` int(11) DEFAULT NULL,\
               `type` int(11) DEFAULT NULL,\
               `k` int(11) DEFAULT NULL,\
               `mode` int(11) DEFAULT NULL,\
               `hpz` double default null,\
               `vpz` double default null,\
               `x` double default null,\
               `y` double default null,\
               `z` double default null,\
               `x1` double default null,\
               `y1` double default null,\
               `z1` double default null,\
               `ori` double default null,\
               `phi` double default null,\
               `ori1` double default null,\
               `phi1` double default null,\
               `mile` double default null,\
               `dh` double default null,\
               `dv` double default null,\
               `dh1` double default null,\
               `dv1` double default null,\
               `headx` double default null,\
               `heady` double default null,\
               `headz` double default null,\
               `headc` double default null,\
               `headh` double default null,\
               `headv` double default null,\
               `tailx` double default null,\
               `taily` double default null,\
               `tailz` double default null,\
               `tailc` double default null,\
               `tailh` double default null,\
               `tailv` double default null,\
               `tbmh` double default null,\
               `tbmv` double default null,\
               `desh` double default null,\
               `desv` double default null,\
               `ugap` double default null,\
               `dgap` double default null,\
               `lgap` double default null,\
               `rgap` double default null,\
               `uaj` double default null,\
               `daj` double default null,\
               `laj` double default null,\
               `raj` double default null,\
               `ufaj` double default null,\
               `dfaj` double default null,\
               `lfaj` double default null,\
               `rfaj` double default null,\
               `ubaj` double default null,\
               `dbaj` double default null,\
               `lbaj` double default null,\
               `rbaj` double default null,\
               `harc` double default null,\
               `varc` double default null,\
               `t` int(11) default null,\
               PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        ///管环选型
        strcpy(cmd,"drop table segs_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table segs_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `numb` int(11) DEFAULT NULL,\
               `type` int(11) DEFAULT NULL,\
               `k` int(11) DEFAULT NULL,\
               `mode` int(11) DEFAULT NULL,\
               `hpz` double default null,\
               `vpz` double default null,\
               `x` double default null,\
               `y` double default null,\
               `z` double default null,\
               `x1` double default null,\
               `y1` double default null,\
               `z1` double default null,\
               `ori` double default null,\
               `phi` double default null,\
               `ori1` double default null,\
               `phi1` double default null,\
               `mile` double default null,\
               `dh` double default null,\
               `dv` double default null,\
               `dh1` double default null,\
               `dv1` double default null,\
               `headx` double default null,\
               `heady` double default null,\
               `headz` double default null,\
               `headc` double default null,\
               `headh` double default null,\
               `headv` double default null,\
               `tailx` double default null,\
               `taily` double default null,\
               `tailz` double default null,\
               `tailc` double default null,\
               `tailh` double default null,\
               `tailv` double default null,\
               `tbmh` double default null,\
               `tbmv` double default null,\
               `desh` double default null,\
               `desv` double default null,\
               `ugap` double default null,\
               `dgap` double default null,\
               `lgap` double default null,\
               `rgap` double default null,\
               `uaj` double default null,\
               `daj` double default null,\
               `laj` double default null,\
               `raj` double default null,\
               `ufaj` double default null,\
               `dfaj` double default null,\
               `lfaj` double default null,\
               `rfaj` double default null,\
               `lbaj` double default null,\
               `dbaj` double default null,\
               `lbaj` double default null,\
               `rbaj` double default null,\
               `harc` double default null,\
               `varc` double default null,\
               `t` int(11) default null,\
               PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);

        ///管环拼装
        strcpy(cmd,"drop table seging_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table seging_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `numb` int(11) DEFAULT NULL,\
               `type` int(11) DEFAULT NULL,\
               `kpos` int(11) DEFAULT NULL,\
               `headc` double default null,\
               `std` int(11) DEFAULT NULL,\
               `left` int(11) DEFAULT NULL,\
               `right` int(11) DEFAULT NULL,\
               `t` int(11) default null,\
               PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));

        //trace(0,"Database: %s\n",cmd);
        strcpy(cmd,"insert into seging_set values (1,0,0,0,0.0,0,0,0,0)");
        mysql_real_query(&mysql,cmd,strlen(cmd));

        ///管环设置
		strcpy(cmd,"drop table segment_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table segment_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `type` int(11) DEFAULT NULL,\
            `ins` int(11) DEFAULT NULL,\
            `f2b` int(11) DEFAULT NULL,\
            `l2s` double DEFAULT NULL,\
            `L` double DEFAULT NULL,\
            `De` double DEFAULT NULL,\
            `D` double DEFAULT NULL,\
            `Ks` int(11) DEFAULT NULL,\
            `G0` double DEFAULT NULL,\
            `G1` double DEFAULT NULL,\
            `s2s` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		//trace(0,"Database: %s\n",cmd);
		strcpy(cmd,"insert into segment_set values (1,1,0,0,0.048,1.2,5.85,5.5,10,0.075,0.015,2)");
        mysql_real_query(&mysql,cmd,strlen(cmd));

        ///管环拼装记录
        strcpy(cmd,"drop table segrecord_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table segrecord_set(\
                `id` int(11) NOT NULL AUTO_INCREMENT,\
                `segnum` int(11) DEFAULT NULL,\
                `segtype` int(11) DEFAULT NULL,\
                `location` int(11) DEFAULT NULL,\
                `mile` double DEFAULT NULL,\
                `offh` double DEFAULT NULL,\
                `offv` double DEFAULT NULL,\
                `t` int(11) DEFAULT NULL,\
                 PRIMARY KEY (`id`)\
                )");
        mysql_real_query(&mysql,cmd,strlen(cmd));

        ///mp
        strcpy(cmd,"drop table check_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table check_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `headx0` double DEFAULT NULL,\
            `heady0` double DEFAULT NULL,\
            `headz0` double DEFAULT NULL,\
            `headx1` double DEFAULT NULL,\
            `heady1` double DEFAULT NULL,\
            `headz1` double DEFAULT NULL,\
            `tailx0` double DEFAULT NULL,\
            `taily0` double DEFAULT NULL,\
            `tailz0` double DEFAULT NULL,\
            `tailx1` double DEFAULT NULL,\
            `taily1` double DEFAULT NULL,\
            `tailz1` double DEFAULT NULL,\
            `prism1x0` double DEFAULT NULL,\
            `prism1y0` double DEFAULT NULL,\
            `prism1z0` double DEFAULT NULL,\
            `prism1x1` double DEFAULT NULL,\
            `prism1y1` double DEFAULT NULL,\
            `prism1z1` double DEFAULT NULL,\
            `prism2x0` double DEFAULT NULL,\
            `prism2y0` double DEFAULT NULL,\
            `prism2z0` double DEFAULT NULL,\
            `prism2x1` double DEFAULT NULL,\
            `prism2y1` double DEFAULT NULL,\
            `prism2z1` double DEFAULT NULL,\
            `prism3x0` double DEFAULT NULL,\
            `prism3y0` double DEFAULT NULL,\
            `prism3z0` double DEFAULT NULL,\
            `prism3x1` double DEFAULT NULL,\
            `prism3y1` double DEFAULT NULL,\
            `prism3z1` double DEFAULT NULL,\
            `roll` double DEFAULT NULL,\
            `pitch` double DEFAULT NULL,\
            `azimuth` double DEFAULT NULL,\
            `roll1` double DEFAULT NULL,\
            `pitch1` double DEFAULT NULL,\
            `azimuth1` double DEFAULT NULL,\
            `pdev1` double DEFAULT NULL,\
            `pdev2` double DEFAULT NULL,\
            `pdev3` double DEFAULT NULL,\
            `headh` double DEFAULT NULL,\
            `headv` double DEFAULT NULL,\
            `headh1` double DEFAULT NULL,\
            `headv1` double DEFAULT NULL,\
            `tailh` double DEFAULT NULL,\
            `tailv` double DEFAULT NULL,\
            `tailh1` double DEFAULT NULL,\
            `tailv1` double DEFAULT NULL,\
            `t` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        ///电池1
        strcpy(cmd,"drop table power1_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table power1_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `life` double DEFAULT NULL,\
            `used` double DEFAULT NULL,\
            `atr` int(11) DEFAULT NULL,\
            `a2l` double DEFAULT NULL,\
            `mot` double DEFAULT NULL,\
            `m2l` double DEFAULT NULL,\
            `dist` int(11) DEFAULT NULL,\
            `d2l` double DEFAULT NULL,\
            `laser` int(11) DEFAULT NULL,\
            `l2l` double DEFAULT NULL,\
            `t1` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        ///电池2
        strcpy(cmd,"drop table power2_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table power2_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `life` double DEFAULT NULL,\
            `used` double DEFAULT NULL,\
            `atr` int(11) DEFAULT NULL,\
            `a2l` double DEFAULT NULL,\
            `mot` double DEFAULT NULL,\
            `m2l` double DEFAULT NULL,\
            `dist` int(11) DEFAULT NULL,\
            `d2l` double DEFAULT NULL,\
            `laser` int(11) DEFAULT NULL,\
            `l2l` double DEFAULT NULL,\
            `t1` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);
        ///作业人员掘进统计
        strcpy(cmd,"drop table duty_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table duty_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `onduty` int(11) DEFAULT NULL,\
            `name` char(64) DEFAULT NULL,\
            `seg1` int(11) DEFAULT NULL,\
            `seg2` int(11) DEFAULT NULL,\
            `l1` double DEFAULT NULL,\
            `l2` double DEFAULT NULL,\
            `t1` int(11) DEFAULT NULL,\
            `t2` int(11) DEFAULT NULL,\
            `mxdv` double DEFAULT NULL,\
            PRIMARY KEY (`id`));");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);

        ///盾尾间隙参数
        strcpy(cmd,"drop table gaps_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table gaps_set(\
                `id` int(11) NOT NULL AUTO_INCREMENT,\
                `a1` double DEFAULT NULL,\
                `a2` double DEFAULT NULL,\
                `a3` double DEFAULT NULL,\
                `a4` double DEFAULT NULL,\
                `a5` double DEFAULT NULL,\
                `s1` double DEFAULT NULL,\
                `s2` double DEFAULT NULL,\
                `s3` double DEFAULT NULL,\
                `s4` double DEFAULT NULL,\
                `s5` double DEFAULT NULL,\
                `sel1` int(11) DEFAULT NULL,\
                `sel2` int(11) DEFAULT NULL,\
                `sel3` int(11) DEFAULT NULL,\
                `sel4` int(11) DEFAULT NULL,\
                `sel5` int(11) DEFAULT NULL,\
                `x` double DEFAULT NULL,\
                `y` double DEFAULT NULL,\
                `z` double DEFAULT NULL,\
                `radius` double DEFAULT NULL,\
                `radius1` double DEFAULT NULL,\
                `ugap` double DEFAULT NULL,\
                `dgap` double DEFAULT NULL,\
                `lgap` double DEFAULT NULL,\
                `rgap` double DEFAULT NULL,\
                `ujust` double DEFAULT NULL,\
                `djust` double DEFAULT NULL,\
                `ljust` double DEFAULT NULL,\
                `rjust` double DEFAULT NULL,\
               PRIMARY KEY (`id`)\
               )");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);

        ///盾尾间隙测量表
        strcpy(cmd,"drop table gapmeas_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table gapmeas_set(\
                `id` int(11) NOT NULL AUTO_INCREMENT,\
                `s1` double DEFAULT NULL,\
                `s2` double DEFAULT NULL,\
                `s3` double DEFAULT NULL,\
                `s4` double DEFAULT NULL,\
                `s5` double DEFAULT NULL,\
                `d1` double DEFAULT NULL,\
                `d2` double DEFAULT NULL,\
                `d3` double DEFAULT NULL,\
                `d4` double DEFAULT NULL,\
                `d5` double DEFAULT NULL,\
                `x` double DEFAULT NULL,\
                `y` double DEFAULT NULL,\
                `z` double DEFAULT NULL,\
                `radius` double DEFAULT NULL,\
                `ugap` double DEFAULT NULL,\
                `dgap` double DEFAULT NULL,\
                `lgap` double DEFAULT NULL,\
                `rgap` double DEFAULT NULL,\
                `t` int(11) DEFAULT NULL,\
               PRIMARY KEY (`id`)\
               )");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"Database: %s\n",cmd);

        strcpy(cmd,"drop table recheck_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table recheck_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `iredta` int(11) DEFAULT 0,\
               `tredta` int(11) DEFAULT 0,\
               PRIMARY KEY (`id`)\
               )");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"insert into recheck_set values (1,0,0)");
        mysql_real_query(&mysql,cmd,strlen(cmd));

        strcpy(cmd,"drop table inccheck_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table inccheck_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `contimes` int(11) DEFAULT 0,\
               `daytimes` int(11) DEFAULT 0,\
               `t` int(11) DEFAULT 0,\
               PRIMARY KEY (`id`)\
               )");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"insert into inccheck_set values (1,0,0,0)");
        mysql_real_query(&mysql,cmd,strlen(cmd));

        strcpy(cmd,"drop table incover_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table incover_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `t` int(11) DEFAULT 0,\
               `inc0_11` double DEFAULT NULL,\
               `inc0_12` double DEFAULT NULL,\
               `inc0_21` double DEFAULT NULL,\
               `inc0_22` double DEFAULT NULL,\
               `inc_11` double DEFAULT NULL,\
               `inc_12` double DEFAULT NULL,\
               `inc_21` double DEFAULT NULL,\
               `inc_22` double DEFAULT NULL,\
               `diff01` double DEFAULT NULL,\
               `diff02` double DEFAULT NULL,\
               `diff1` double DEFAULT NULL,\
               `diff2` double DEFAULT NULL,\
               PRIMARY KEY (`id`)\
               )");
        mysql_real_query(&mysql,cmd,strlen(cmd));

		///commit
		strcpy(cmd,"commit");
		mysql_real_query(&mysql,cmd,strlen(cmd));
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	return ret;
}

static void init_cam(mtg_t* mtg)
{
	int **sizes=0;
    char **names=0;
    int* types=0;
    int i;
	///
    sizes=(int**)malloc(sizeof(int*));
    names=(char**)malloc(sizeof(char*));
    types=(int*)malloc(sizeof(int));
    for(i=0;i<1;i++)
    {
        sizes[i]=(int*)malloc(2*sizeof(int));
        sizes[i][0]=mtg->camset[i].w;
        sizes[i][1]=mtg->camset[i].h;
        types[i]=mtg->tarset.cam;
        names[i]=(char*)malloc(64);
		strcpy(names[i],mtg->camset[i].name);
    }
    camsvr_init(&mtg->camsvr,1,sizes,types,names);
    free(sizes);
    for(i=0;i<1;i++) free(names[i]);
    free(names);
    free(types);
}

int mtg_import_db(mtg_t* mtg)
{
	int ret=0;
	MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[4096];
	int index=0,i;
	h_element h;
    v_element v;
    h_offset ho;
    v_offset vo;
    m_offset mo;
    MTG_MEASURE m={0};
    MTG_SEG segs = {0};
    MTG_STATION stn={0};
    MTG_PRJ prj={0};
    MTG_SETS sets={0};
    MTG_TBM tbm = {0};
    MTG_SEGSET seg = {0};
    MTG_SEG_SERIAL snum={0};
    MTG_MP mp = {0};
    MTG_TARGET tarset={0};

    int rows=0,cols=0;

    long t;
    FILE* fp=fopen("D:\\midu\\mtg_import.log","w");

    memset(&stn,0,sizeof(MTG_STATION));
    memset(&m,0,sizeof(MTG_MEASURE));
    memset(&mtg->maj0,0,sizeof(MTG_MEASURE_AJ));
    memset(&mtg->maj1,0,sizeof(MTG_MEASURE_AJ));
    memset(&mtg->maj,0,sizeof(MTG_MEASURE_AJ));

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        trace(0,"Database: import db\n");
	    ///工程信息1
	    mtg->prj=prj;
	    strcpy(cmd,"select * from prj_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    if((record = mysql_fetch_row(results)))
			{
			    i=1;
			    strcpy(mtg->prj.name,record[i++]);
			    sscanf(record[i++],"%lf",&mtg->prj.mile1);
			    sscanf(record[i++],"%lf",&mtg->prj.mile2);
			    sscanf(record[i++],"%d",&mtg->prj.a2z);
			    sscanf(record[i++],"%d",&mtg->ndty);
			    strcpy(mtg->duty[0].name,record[i++]);
			    strcpy(mtg->duty[1].name,record[i++]);
			    strcpy(mtg->duty[2].name,record[i++]);
			    strcpy(mtg->duty[3].name,record[i++]);
			    sscanf(record[i++],"%d",&mtg->prj.htip);
			    sscanf(record[i++],"%d",&mtg->prj.vtip);
			    sscanf(record[i++],"%lf",&mtg->prj.tip);
			    if(mtg->fbi)
			    {
			        fprintf(mtg->fbi,"%%R1P,%d,%d\n",0,1);
                    fflush(mtg->fbi);
			    }
			}
			else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",0,0);
                    fflush(mtg->fbi);
                }
            }
			mysql_free_result(results);
			ret++;

		}
        //trace(0,"Database: %s,%d\n",cmd,ret);

		///关键区域2
		mtg->nks = 0;
		strcpy(cmd,"select * from key_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    mtg->nks = mysql_num_rows(results);
            if(mtg->nks>0) mtg->keys=(MTG_KEY*)malloc(mtg->nks*sizeof(MTG_KEY));
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    strcpy(mtg->keys[index].name,record[1]);
			    sscanf(record[2],"%lf",&mtg->keys[index].mile1);
			    sscanf(record[3],"%lf",&mtg->keys[index].mile2);
			    index++;
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",1,index);
                fflush(mtg->fbi);
			}
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);
        ///管环监测3
        strcpy(cmd,"select * from smonitor_set");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    if((record = mysql_fetch_row(results)))
            {
                sscanf(record[1],"%d",&mtg->smonitor.number);
                sscanf(record[2],"%d",&mtg->smonitor.monitor);
                sscanf(record[3],"%d",&mtg->smonitor.cycle);
                sscanf(record[4],"%d",&mtg->smonitor.last);
                sscanf(record[5],"%d",&mtg->smonitor.iseg);
                sscanf(record[6],"%lf",&mtg->smonitor.headc);
                sscanf(record[7],"%lf",&mtg->smonitor.x0);
                sscanf(record[8],"%lf",&mtg->smonitor.y0);
                sscanf(record[9],"%lf",&mtg->smonitor.z0);
                sscanf(record[10],"%lf",&mtg->smonitor.x);
                sscanf(record[11],"%lf",&mtg->smonitor.y);
                sscanf(record[12],"%lf",&mtg->smonitor.z);
                sscanf(record[13],"%ld",&mtg->smonitor.t);
                sscanf(record[14],"%lf",&mtg->smonitor.dv);
                sscanf(record[15],"%lf",&mtg->smonitor.dv1);
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",2,1);
                    fflush(mtg->fbi);
                }
            }
            else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",2,0);
                    fflush(mtg->fbi);
                }
            }
            mysql_free_result(results);
			ret++;

		}
		//trace(0,"Database: %s,%d\n",cmd,ret);
		///环号计算4
		mtg->snum = snum;
		strcpy(cmd,"select * from serial_set order by id desc limit 1");
		//strcpy(cmd,"select * from snum");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    if((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%d",&mtg->snum.iseg);
			    sscanf(record[2],"%lf",&mtg->snum.mile);
			    sscanf(record[3],"%lf",&mtg->snum.tm);
			    if(mtg->fbi)
			    {
			        fprintf(mtg->fbi,"%%R1P,%d,%d\n",3,1);
                    fflush(mtg->fbi);
			    }
			}
			else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",3,0);
                    fflush(mtg->fbi);
                }
            }
			mysql_free_result(results);
			ret++;

		}
        //trace(0,"Database: %s,%d\n",cmd,ret);
		///盾构设置5
		///测试部分
		//tbm.naj=4;
        //tbm.nbj=4;
        //tbm.nfj=4;
        //tbm.aj=(double*)malloc(4*sizeof(double));
        //tbm.bj=(double*)malloc(4*sizeof(double));
        //tbm.fj=(double*)malloc(4*sizeof(double));
        //tbm.aj[0]=PI*3.0/2.0;
        //tbm.aj[1]=0.0;
        //tbm.aj[2]=PI/2.0;
        //tbm.aj[3]=PI;
		mtg->tbm = tbm;
		strcpy(cmd,"select * from tbm_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    if((record = mysql_fetch_row(results)))
			{
			    i=1;
			    strcpy(mtg->tbm.name,record[i++]);
			    sscanf(record[i++],"%d",&mtg->tbm.type);
			    sscanf(record[i++],"%d",&mtg->tbm.mode);
			    sscanf(record[i++],"%lf",&mtg->tbm.D[0]);
			    sscanf(record[i++],"%lf",&mtg->tbm.D[1]);
			    sscanf(record[i++],"%lf",&mtg->tbm.D[2]);
			    sscanf(record[i++],"%lf",&mtg->tbm.D[3]);
			    sscanf(record[i++],"%lf",&mtg->tbm.D[4]);
			    sscanf(record[i++],"%lf",&mtg->tbm.D[5]);
			    sscanf(record[i++],"%lf",&mtg->tbm.L[0]);
			    sscanf(record[i++],"%lf",&mtg->tbm.L[1]);
			    sscanf(record[i++],"%lf",&mtg->tbm.L[2]);
			    sscanf(record[i++],"%lf",&mtg->tbm.L[3]);
			    sscanf(record[i++],"%lf",&mtg->tbm.L[4]);
			    sscanf(record[i++],"%lf",&mtg->tbm.L[5]);
			    sscanf(record[i++],"%lf",&mtg->tbm.L[6]);
			    sscanf(record[i++],"%lf",&mtg->tbm.L[7]);
			    sscanf(record[i++],"%lf",&mtg->tbm.L[8]);
			    sscanf(record[i++],"%d",&mtg->tbm.naj);
			    sscanf(record[i++],"%lf",&mtg->tbm.aj[0]);
			    sscanf(record[i++],"%lf",&mtg->tbm.aj[1]);
			    sscanf(record[i++],"%lf",&mtg->tbm.aj[2]);
			    sscanf(record[i++],"%lf",&mtg->tbm.aj[3]);
			    sscanf(record[i++],"%lf",&mtg->tbm.aj[4]);
			    sscanf(record[i++],"%lf",&mtg->tbm.aj[5]);
			    sscanf(record[i++],"%d",&mtg->tbm.aunit);
			    sscanf(record[i++],"%d",&mtg->tbm.nbj);
			    sscanf(record[i++],"%lf",&mtg->tbm.bj[0]);
			    sscanf(record[i++],"%lf",&mtg->tbm.bj[1]);
			    sscanf(record[i++],"%lf",&mtg->tbm.bj[2]);
			    sscanf(record[i++],"%lf",&mtg->tbm.bj[3]);
			    sscanf(record[i++],"%d",&mtg->tbm.bunit);
			    sscanf(record[i++],"%d",&mtg->tbm.nfj);
			    sscanf(record[i++],"%lf",&mtg->tbm.fj[0]);
			    sscanf(record[i++],"%lf",&mtg->tbm.fj[1]);
			    sscanf(record[i++],"%lf",&mtg->tbm.fj[2]);
			    sscanf(record[i++],"%lf",&mtg->tbm.fj[3]);
			    sscanf(record[i++],"%d",&mtg->tbm.funit);
			    if(mtg->fbi)
			    {
			        fprintf(mtg->fbi,"%%R1P,%d,%d\n",4,1);
                    fflush(mtg->fbi);
			    }
			}
			else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",4,0);
                    fflush(mtg->fbi);
                }
            }
			mysql_free_result(results);
			ret++;
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);
		///相机设置6
		strcpy(cmd,"select * from cam_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%d",&mtg->camset[index].w);
			    sscanf(record[2],"%d",&mtg->camset[index].h);
			    for(i=0;i<9;i++)
			    {
			        sscanf(record[i+3],"%lf",&mtg->camset[index].affine[i]);
			    }
			    sscanf(record[12],"%d",&mtg->camset[index].x1);
			    sscanf(record[13],"%d",&mtg->camset[index].y1);
			    sscanf(record[14],"%d",&mtg->camset[index].x2);
			    sscanf(record[15],"%d",&mtg->camset[index].y2);
			    strcpy(mtg->camset[index].name,record[16]);
			    index++;
			    if(index>=2) break;
			}
			mysql_free_result(results);
			ret++;
			if(index==0) mtg->ierr[0]=1;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",5,index);
                fflush(mtg->fbi);
			}
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);
        ///地图设置7
		strcpy(cmd,"select * from map_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    for(i=0;i<5;i++)
			    {
			        sscanf(record[i*5+1],"%d",&mtg->mapset[index].w[i]);
			        sscanf(record[i*5+2],"%d",&mtg->mapset[index].h[i]);
			        sscanf(record[i*5+3],"%lf",&mtg->mapset[index].dx[i]);
			        sscanf(record[i*5+4],"%lf",&mtg->mapset[index].dy[i]);
			        sscanf(record[i*5+5],"%lf",&mtg->mapset[index].s[i]);
			    }
			    sscanf(record[26],"%lf",&mtg->mapset[index].beta);
			    strcpy(mtg->mapset[index].name,record[27]);
			    index++;
			    if(index>=2) break;
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",6,index);
                fflush(mtg->fbi);
			}
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);
		///激光靶设置8
		tarset.incdb=0;
		tarset.ctsalw=50;
		tarset.dtsalw=100;
		tarset.stopped=0;
		tarset.angalw=0.3;
		mtg->tarset=tarset;
		strcpy(cmd,"select * from target_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    cols=mysql_num_fields(results);
		    index=0;
		    if((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%d",&mtg->tarset.ver);
			    sscanf(record[2],"%lf",&mtg->tarset.prism[0]);
			    sscanf(record[3],"%lf",&mtg->tarset.prism[1]);
				sscanf(record[4],"%lf",&mtg->tarset.prism[2]);
				sscanf(record[5],"%lf",&mtg->tarset.prism[3]);
			    sscanf(record[6],"%lf",&mtg->tarset.prism[4]);
				sscanf(record[7],"%lf",&mtg->tarset.prism[5]);
				sscanf(record[8],"%lf",&mtg->tarset.prism[6]);
			    sscanf(record[9],"%lf",&mtg->tarset.prism[7]);
				sscanf(record[10],"%lf",&mtg->tarset.prism[8]);
				i=11;
				if(cols>17)
				{
                    sscanf(record[i++],"%lf",&mtg->tarset.prism[9]);
                    sscanf(record[i++],"%lf",&mtg->tarset.prism[10]);
                    sscanf(record[i++],"%lf",&mtg->tarset.prism[11]);
                }
                else
                {
                    strcpy(cmd,"ALTER TABLE `target_set` ADD COLUMN `prism10` int(11) default 0 AFTER `prism9`;");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    strcpy(cmd,"ALTER TABLE `target_set` ADD COLUMN `prism11` int(11) default 0 AFTER `prism10`;");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    strcpy(cmd,"ALTER TABLE `target_set` ADD COLUMN `prism12` int(11) default 0 AFTER `prism11`;");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                }
                sscanf(record[i++],"%lf",&mtg->tarset.prc);
                sscanf(record[i++],"%lf",&mtg->tarset.length);
                sscanf(record[i++],"%d",&mtg->tarset.cam);
                sscanf(record[i++],"%d",&mtg->tarset.inc);
                sscanf(record[i++],"%d",&mtg->tarset.ipos);
                sscanf(record[i++],"%d",&mtg->tarset.pos);

                if(cols>=24)
                {
                    sscanf(record[i++],"%d",&mtg->tarset.incdb);
                    sscanf(record[i++],"%d",&mtg->tarset.ctsalw);
                    sscanf(record[i++],"%d",&mtg->tarset.dtsalw);
                    sscanf(record[i++],"%d",&mtg->tarset.stopped);
                    sscanf(record[i++],"%lf",&mtg->tarset.angalw);
                }
                if(cols<=20)
                {
                    strcpy(cmd,"ALTER TABLE `target_set` ADD COLUMN `incdb` int(11) default 0 AFTER `tposition`;");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    strcpy(cmd,"ALTER TABLE `target_set` ADD COLUMN `ctsalw` int(11) default 50 AFTER `incdb`;");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    strcpy(cmd,"ALTER TABLE `target_set` ADD COLUMN `dtsalw` int(11) default 100 AFTER `ctsalw`;");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    strcpy(cmd,"ALTER TABLE `target_set` ADD COLUMN `stpd` int(11) default 0 AFTER `dtsalw`;");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    strcpy(cmd,"ALTER TABLE `target_set` ADD COLUMN `angalw` double default 0.3 AFTER `stpd`;");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                }
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",7,1);
                    fflush(mtg->fbi);
                }
			}
			else
            {
                mtg->ierr[1]=1;
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",7,0);
                    fflush(mtg->fbi);
                }
            }
			mysql_free_result(results);
			ret++;
		}
		//trace(0,"target:ver=%d,x=%.4f\n",mtg->tarset.ver,mtg->tarset.prism[0]);
        //trace(0,"Database: %s,%d\n",cmd,ret);
		///全站仪9
		strcpy(cmd,"select * from tps_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    index=0;
		    if((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%d",&mtg->tps.type);
			    sscanf(record[2],"%d",&mtg->tps.lasertype);
			    sscanf(record[3],"%lf",&mtg->tps.laserheight);
				sscanf(record[4],"%lf",&mtg->tps.laserdist[0]);
				sscanf(record[5],"%lf",&mtg->tps.laserdist[1]);
				sscanf(record[6],"%lf",&mtg->tps.laserx[0]);
				sscanf(record[7],"%lf",&mtg->tps.lasery[0]);
				sscanf(record[8],"%lf",&mtg->tps.laserx[1]);
				sscanf(record[9],"%lf",&mtg->tps.lasery[1]);
				sscanf(record[10],"%d",&mtg->tps.edm);
				sscanf(record[11],"%d",&mtg->tps.comp);
				if(mtg->fbi)
				{
				    fprintf(mtg->fbi,"%%R1P,%d,%d\n",8,1);
                    fflush(mtg->fbi);
				}
			}
			else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",8,0);
                    fflush(mtg->fbi);
                }
            }
			mysql_free_result(results);
			ret++;
		}
		trace(0,"Database: type=%d,d=%.4f,x=%.4f,y=%.4f\n",mtg->tps.lasertype,mtg->tps.laserdist[1],mtg->tps.laserx[1],mtg->tps.lasery[1]);
        //trace(0,"Database: %s,%d\n",cmd,ret);
		///管块设置10
		mtg->nblk = 0;
		strcpy(cmd,"select * from block_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    mtg->nblk = mysql_num_rows(results);
		    if(mtg->nblk>0) mtg->blocks=(MTG_BLOCK*)malloc(mtg->nblk*sizeof(MTG_BLOCK));

		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    strcpy(mtg->blocks[index].name,record[1]);
			    sscanf(record[2],"%lf",&mtg->blocks[index].angle);
			    index++;
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",9,index);
                fflush(mtg->fbi);
			}
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);
		///系统设置11
		mtg->iset=sets;
	    strcpy(cmd,"select * from config_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    cols=mysql_num_fields(results);
		    if(cols==34)
            {
                strcpy(cmd,"ALTER TABLE `config_set` ADD COLUMN `symtype` int(11) DEFAULT '0' AFTER `lang`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
            }
            if(cols==35)
            {
                strcpy(cmd,"ALTER TABLE `config_set` ADD COLUMN `backflag` int(11) DEFAULT '0' AFTER `symtype`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
            }
            if(cols==36)
            {
                strcpy(cmd,"ALTER TABLE `config_set` ADD COLUMN `plctype` int(11) DEFAULT '0' AFTER `backflag`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
            }
            if(cols==37)
            {
                strcpy(cmd,"ALTER TABLE `config_set` ADD COLUMN `aalw` double NULL DEFAULT '2.0' AFTER `plctype`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
            }
            if(cols==38)
            {
                strcpy(cmd,"ALTER TABLE `config_set` ADD COLUMN `tailapply` int(11) DEFAULT '0' AFTER `aalw`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
            }
		    if((record = mysql_fetch_row(results)))
			{
			    i=1;
			    sscanf(record[i++],"%d",&mtg->iset.cyc);
			    sscanf(record[i++],"%d",&mtg->iset.bcyc);
			    sscanf(record[i++],"%d",&mtg->iset.palw);
			    sscanf(record[i++],"%d",&mtg->iset.jalw);
			    sscanf(record[i++],"%d",&mtg->iset.balw);
			    sscanf(record[i++],"%d",&mtg->iset.talw);
			    sscanf(record[i++],"%d",&mtg->iset.vibration);
			    sscanf(record[i++],"%d",&mtg->iset.rstn);
			    sscanf(record[i++],"%d",&mtg->iset.tsyn);
			    sscanf(record[i++],"%d",&mtg->iset.rget);
			    sscanf(record[i++],"%d",&mtg->iset.idrv);
			    sscanf(record[i++],"%d",&mtg->iset.prun);
			    sscanf(record[i++],"%d",&mtg->iset.pend);
			    sscanf(record[i++],"%d",&mtg->iset.psas);
			    sscanf(record[i++],"%d",&mtg->iset.pchk);
			    sscanf(record[i++],"%d",&mtg->iset.pqry);
			    sscanf(record[i++],"%d",&mtg->iset.pmap);
			    sscanf(record[i++],"%d",&mtg->iset.psmr);
			    sscanf(record[i++],"%d",&mtg->iset.pquit);
			    sscanf(record[i++],"%d",&mtg->iset.unit);
			    sscanf(record[i++],"%d",&mtg->iset.vmileage);
			    sscanf(record[i++],"%d",&mtg->iset.head);
			    sscanf(record[i++],"%d",&mtg->iset.tbm3d);
			    sscanf(record[i++],"%d",&mtg->iset.trend);
			    sscanf(record[i++],"%d",&mtg->iset.povr);
			    sscanf(record[i++],"%d",&mtg->iset.jovr);
			    sscanf(record[i++],"%d",&mtg->iset.bovr);
			    sscanf(record[i++],"%d",&mtg->iset.tovr);
			    sscanf(record[i++],"%d",&mtg->iset.toEr);
			    sscanf(record[i++],"%lf",&mtg->iset.flen);
			    sscanf(record[i++],"%lf",&mtg->iset.fdev);
			    sscanf(record[i++],"%d",&mtg->iset.tgap);
			    sscanf(record[i++],"%d",&mtg->iset.lang);
			    if(cols>34)
                {
                    sscanf(record[i++],"%d",&mtg->iset.symtype);
                }
                if(cols>35)
                {
                    sscanf(record[i++],"%d",&mtg->iset.backflag);
                }
                if(cols>36)
                {
                    sscanf(record[i++],"%d",&mtg->iset.plctype);
                }
                if(cols>37)
                {
                    sscanf(record[i++],"%lf",&mtg->iset.aalw);
                }
                if(cols>38)
                {
                    sscanf(record[i++],"%d",&mtg->iset.tailapply);
                }
			    if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",10,1);
                    fflush(mtg->fbi);
                }
			}
			else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",10,0);
                    fflush(mtg->fbi);
                }
            }
			mysql_free_result(results);
			ret++;
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);
		///吊篮坐标12
		mtg->nbsk=0;
		strcpy(cmd,"select * from basket_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    mtg->nbsk=mysql_num_rows(results);
		    if(mtg->nbsk>0) mtg->bask=(MTG_BASKET*)malloc(mtg->nbsk*sizeof(MTG_BASKET));
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    strcpy(mtg->bask[index].name,record[0]);
			    sscanf(record[1],"%lf",&mtg->bask[index].x);
			    sscanf(record[2],"%lf",&mtg->bask[index].y);
			    sscanf(record[3],"%lf",&mtg->bask[index].z);
			    sscanf(record[4],"%ld",&t);
			    mtg->bask[index].t=t;
			    index++;
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",11,index);
                fflush(mtg->fbi);
			}
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);
		///账号管理13
		mtg->nuser=0;
		strcpy(cmd,"select * from user_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    mtg->nuser=mysql_num_rows(results);
		    if(mtg->nuser>0) mtg->user=(MTG_USER*)malloc(mtg->nuser*sizeof(MTG_USER));
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    strcpy(mtg->user[index].name,record[1]);
			    strcpy(mtg->user[index].password,record[2]);
			    sscanf(record[3],"%d",&mtg->user[index].level);
			    index++;
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",12,index);
                fflush(mtg->fbi);
			}
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);
		///设站信息14
		mtg->istn=stn;
		//mtg->stn=stn;
		strcpy(cmd,"select * from station_set order by id desc limit 1");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    cols=mysql_num_fields(results);
		    rows=mysql_num_rows(results);
            if(cols==29)
            {
                strcpy(cmd,"ALTER TABLE `station_set` ADD COLUMN `anglediff` double NULL DEFAULT '0' AFTER `t`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                //strcpy(cmd,"ALTER TABLE `station_set` CHANGE COLUMN `anglediff` `anglediff` DOUBLE NULL DEFAULT NULL AFTER `roll2`;");
                //mysql_real_query(&mysql,cmd,strlen(cmd));
            }
		    if((record = mysql_fetch_row(results)))
            {
                sscanf(record[0],"%d",&mtg->istn.id);
                strcpy(mtg->istn.stat,record[1]);
                strcpy(mtg->istn.back,record[2]);
                sscanf(record[3],"%lf",&mtg->istn.statx);
                sscanf(record[4],"%lf",&mtg->istn.staty);
                sscanf(record[5],"%lf",&mtg->istn.statz);
                sscanf(record[6],"%lf",&mtg->istn.stath);
                sscanf(record[7],"%lf",&mtg->istn.backx);
                sscanf(record[8],"%lf",&mtg->istn.backy);
                sscanf(record[9],"%lf",&mtg->istn.backz);
                sscanf(record[10],"%lf",&mtg->istn.backh);
                sscanf(record[11],"%lf",&mtg->istn.backx1);
                sscanf(record[12],"%lf",&mtg->istn.backy1);
                sscanf(record[13],"%lf",&mtg->istn.backz1);
                sscanf(record[14],"%lf",&mtg->istn.headh[0]);
                sscanf(record[15],"%lf",&mtg->istn.headh[1]);
                sscanf(record[16],"%lf",&mtg->istn.tailh[0]);
                sscanf(record[17],"%lf",&mtg->istn.tailh[1]);
                sscanf(record[18],"%lf",&mtg->istn.headv[0]);
                sscanf(record[19],"%lf",&mtg->istn.headv[1]);
                sscanf(record[20],"%lf",&mtg->istn.tailv[0]);
                sscanf(record[21],"%lf",&mtg->istn.tailv[1]);
                sscanf(record[22],"%lf",&mtg->istn.azi[0]);
                sscanf(record[23],"%lf",&mtg->istn.azi[1]);
                sscanf(record[24],"%lf",&mtg->istn.pitch[0]);
                sscanf(record[25],"%lf",&mtg->istn.pitch[1]);
                sscanf(record[26],"%lf",&mtg->istn.roll[0]);
                sscanf(record[27],"%lf",&mtg->istn.roll[1]);
                sscanf(record[28],"%ld",&t);
                mtg->istn.t=t;
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",13,1);
                    fflush(mtg->fbi);
                }

                mtg->istat.x=mtg->istn.statx;
                mtg->istat.y=mtg->istn.staty;
                mtg->istat.z=mtg->istn.statz;
                mtg->iback.x=mtg->istn.backx;
                mtg->iback.y=mtg->istn.backy;
                mtg->iback.z=mtg->istn.backz;
                strcpy(mtg->istat.name,mtg->istn.stat);
                strcpy(mtg->iback.name,mtg->istn.back);

                if(cols>29)
                {
                    sscanf(record[29],"%lf",&mtg->istn.anglediff);
                    //fprintf(fp,"%d,%.4f\n",i,mtg->stns[index].anglediff);
                    //fflush(fp);
                }
                else
                {
                    strcpy(cmd,"ALTER TABLE `station_set` ADD COLUMN `anglediff` double NULL DEFAULT '0' AFTER `t`");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    //strcpy(cmd,"ALTER TABLE `stn_set` CHANGE COLUMN `anglediff` `anglediff` DOUBLE NULL DEFAULT NULL AFTER `roll2`;");
                    //mysql_real_query(&mysql,cmd,strlen(cmd));
                }
            }
            else
            {
                mtg->ierr[2]=1;
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",13,0);
                    fflush(mtg->fbi);
                }
            }
		    mysql_free_result(results);
			ret++;

		}
        trace(0,"Database: %s,%d\n",cmd,ret);
		///零位数据15
		mtg->m0=m;
		mtg->mp=mp;
		strcpy(cmd,"select * from given_set order by id desc limit 1");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    i=1;
		    results = mysql_store_result(&mysql);
		    cols=mysql_num_fields(results);
		    if((record = mysql_fetch_row(results)))
			{
			    sscanf(record[i++],"%lf",&mtg->m0.inc[0]);
			    sscanf(record[i++],"%lf",&mtg->m0.inc[1]);
			    sscanf(record[i++],"%lf",&mtg->m0.inc[2]);
			    sscanf(record[i++],"%lf",&mtg->m0.inc[3]);
			    sscanf(record[i++],"%lf",&mtg->m0.cam[0]);
			    sscanf(record[i++],"%lf",&mtg->m0.cam[1]);
			    sscanf(record[i++],"%lf",&mtg->m0.cam[2]);
			    sscanf(record[i++],"%lf",&mtg->m0.cam[3]);
			    sscanf(record[i++],"%lf",&mtg->m0.prism[0]);
			    sscanf(record[i++],"%lf",&mtg->m0.prism[1]);
			    sscanf(record[i++],"%lf",&mtg->m0.prism[2]);
			    sscanf(record[i++],"%lf",&mtg->m0.angle[0]);
                sscanf(record[i++],"%lf",&mtg->m0.angle[1]);
                sscanf(record[i++],"%lf",&mtg->m0.comp[0]);
			    sscanf(record[i++],"%lf",&mtg->m0.comp[1]);
			    sscanf(record[i++],"%lf",&mtg->m0.head[0]);
			    sscanf(record[i++],"%lf",&mtg->m0.head[1]);
			    sscanf(record[i++],"%lf",&mtg->m0.head[2]);
			    sscanf(record[i++],"%lf",&mtg->m0.tail[0]);
			    sscanf(record[i++],"%lf",&mtg->m0.tail[1]);
			    sscanf(record[i++],"%lf",&mtg->m0.tail[2]);
			    sscanf(record[i++],"%lf",&mtg->m0.faj[0]);
			    sscanf(record[i++],"%lf",&mtg->m0.faj[1]);
			    sscanf(record[i++],"%lf",&mtg->m0.faj[2]);
			    sscanf(record[i++],"%lf",&mtg->m0.faj[3]);
			    sscanf(record[i++],"%lf",&mtg->m0.baj[0]);
			    sscanf(record[i++],"%lf",&mtg->m0.baj[1]);
			    sscanf(record[i++],"%lf",&mtg->m0.baj[2]);
			    sscanf(record[i++],"%lf",&mtg->m0.baj[3]);
			    sscanf(record[i++],"%lf",&mtg->m0.aj[0]);
			    sscanf(record[i++],"%lf",&mtg->m0.aj[1]);
			    sscanf(record[i++],"%lf",&mtg->m0.aj[2]);
			    sscanf(record[i++],"%lf",&mtg->m0.aj[3]);
			    sscanf(record[i++],"%lf",&mtg->m0.inc1[0]);
			    sscanf(record[i++],"%lf",&mtg->m0.inc1[1]);
			    sscanf(record[i++],"%lf",&mtg->m0.inc1[2]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[0]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[1]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[2]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[3]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[4]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[5]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[6]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[7]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[8]);
			    sscanf(record[i++],"%ld",&t);
			    mtg->m0.t1=t;
			    sscanf(record[i++],"%ld",&t);
			    mtg->m0.t2=t;
			    sscanf(record[i++],"%ld",&t);
			    mtg->m0.t3=t;
			    if(cols>49)
                   sscanf(record[i++],"%ld",&mtg->m0.ipos);
                else
                {
                    sprintf(cmd,"alter table given_set add ipos int unsigned not Null");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    sprintf(cmd,"alter table given_set add t4 int unsigned not Null");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    sprintf(cmd,"alter table given_set add t5 int unsigned not Null");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    sprintf(cmd,"alter table given_set add inc12 double default 0");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    sprintf(cmd,"alter table given_set add inc22 double default 0");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                }

                if(cols>50)
                {
                    sscanf(record[i++],"%ld",&t);
                    mtg->m0.t4=t;
                }
                else
                {
                    sprintf(cmd,"alter table given_set add t4 int unsigned not Null");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    sprintf(cmd,"alter table given_set add t5 int unsigned not Null");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    sprintf(cmd,"alter table given_set add inc12 double default 0");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                    sprintf(cmd,"alter table given_set add inc22 double default 0");
                    mysql_real_query(&mysql,cmd,strlen(cmd));
                }

                if(cols>53)
                {
                    sscanf(record[i++],"%ld",&t);
                    mtg->m0.t5=t;
                    sscanf(record[i++],"%lf",&mtg->m0.inc[5]);
                    sscanf(record[i++],"%lf",&mtg->m0.inc[6]);
                }
			    if(mtg->fbi)
			    {
			        fprintf(mtg->fbi,"%%R1P,%d,%d\n",14,1);
                    fflush(mtg->fbi);
			    }
			    if(fp)
                {
                    fprintf(fp,"%d,%d\n",cols,mtg->m0.ipos);
                    fflush(fp);
                }
			}
			else
            {
                mtg->ierr[3]=1;
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",14,0);
                    fflush(mtg->fbi);
                }
            }
			mtg_cal_origin(mtg);
			if(fp)
            {
                fprintf(fp,"mtg_cal_origin:%d\n",mtg->m0.ipos);
                fflush(fp);
            }
			mysql_free_result(results);
			ret++;
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);

		///观测值（上一次）16
		mtg->m1=m;
		mtg->m=m;
		strcpy(cmd,"select * from measure_set order by id desc limit 1");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    i=1;
		    results = mysql_store_result(&mysql);
		    cols=mysql_num_fields(results);
		    if((record = mysql_fetch_row(results)))
			{
			    sscanf(record[i++],"%lf",&mtg->m1.inc[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.inc[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.inc[2]);
			    sscanf(record[i++],"%lf",&mtg->m1.inc[3]);
			    sscanf(record[i++],"%lf",&mtg->m1.cam[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.cam[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.cam[2]);
			    sscanf(record[i++],"%lf",&mtg->m1.cam[3]);
			    sscanf(record[i++],"%lf",&mtg->m1.prism[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.prism[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.prism[2]);
			    sscanf(record[i++],"%lf",&mtg->m1.angle[0]);
                sscanf(record[i++],"%lf",&mtg->m1.angle[1]);
                sscanf(record[i++],"%lf",&mtg->m1.comp[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.comp[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.head[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.head[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.head[2]);
			    sscanf(record[i++],"%lf",&mtg->m1.hdes[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.hdes[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.hdes[2]);
			    sscanf(record[i++],"%lf",&mtg->m1.headc);
			    sscanf(record[i++],"%lf",&mtg->m1.headh);
			    sscanf(record[i++],"%lf",&mtg->m1.headv);
			    sscanf(record[i++],"%lf",&mtg->m1.tail[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.tail[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.tail[2]);
			    sscanf(record[i++],"%lf",&mtg->m1.tdes[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.tdes[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.tdes[2]);
			    sscanf(record[i++],"%lf",&mtg->m1.tailc);
			    sscanf(record[i++],"%lf",&mtg->m1.tailh);
			    sscanf(record[i++],"%lf",&mtg->m1.tailv);
			    sscanf(record[i++],"%lf",&mtg->m1.mile1);
			    sscanf(record[i++],"%lf",&mtg->m1.hdev1);
			    sscanf(record[i++],"%lf",&mtg->m1.vdev1);
			    sscanf(record[i++],"%lf",&mtg->m1.mile2);
			    sscanf(record[i++],"%lf",&mtg->m1.hdev2);
			    sscanf(record[i++],"%lf",&mtg->m1.vdev2);
			    sscanf(record[i++],"%lf",&mtg->m1.mile3);
			    sscanf(record[i++],"%lf",&mtg->m1.hdev3);
			    sscanf(record[i++],"%lf",&mtg->m1.vdev3);
			    sscanf(record[i++],"%lf",&mtg->m1.faj[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.faj[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.faj[2]);
			    sscanf(record[i++],"%lf",&mtg->m1.faj[3]);
			    sscanf(record[i++],"%lf",&mtg->m1.baj[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.baj[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.baj[2]);
			    sscanf(record[i++],"%lf",&mtg->m1.baj[3]);
			    sscanf(record[i++],"%lf",&mtg->m1.aj[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.aj[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.aj[2]);
			    sscanf(record[i++],"%lf",&mtg->m1.aj[3]);
			    sscanf(record[i++],"%lf",&mtg->m1.inc1[0]);
			    sscanf(record[i++],"%lf",&mtg->m1.inc1[1]);
			    sscanf(record[i++],"%lf",&mtg->m1.inc1[2]);
			    sscanf(record[i++],"%d",&mtg->m1.iseg);
			    if(fp)
                {
                    fprintf(fp,"iseg:%d\n",mtg->m1.iseg);
                    fflush(fp);
                }
			    sscanf(record[i++],"%ld",&t);
			    mtg->m1.t1=t;
			    sscanf(record[i++],"%ld",&t);
			    mtg->m1.t2=t;
			    sscanf(record[i++],"%ld",&t);
			    mtg->m1.t3=t;
			    sscanf(record[i++],"%d",&mtg->m1.iset);
			    mtg->m1.iseg=mtg->snum.iseg;
			    mtg->m=mtg->m1;
			    mtg->m.aj[0]=mtg->m1.aj[0];
			    mtg->m.aj[1]=mtg->m1.aj[1];
			    mtg->m.aj[2]=mtg->m1.aj[2];
			    mtg->m.aj[3]=mtg->m1.aj[3];
                mtg_cal_seg(mtg);

                if(cols>=69)
                {
                    sscanf(record[i++],"%lf",&mtg->m1.ht[0]);
                    sscanf(record[i++],"%lf",&mtg->m1.ht[1]);
                    sscanf(record[i++],"%lf",&mtg->m1.ht[2]);
                    sscanf(record[i++],"%lf",&mtg->m1.htdes[0]);
                    sscanf(record[i++],"%lf",&mtg->m1.htdes[1]);
                    sscanf(record[i++],"%lf",&mtg->m1.htdes[2]);
                }
                if(cols>=72)
                {
                    sscanf(record[i++],"%ld",&t);
                    mtg->m1.t5=t;
                    sscanf(record[i++],"%lf",&mtg->m1.inc[5]);
                    sscanf(record[i++],"%lf",&mtg->m1.inc[6]);
                }
                //trace(0,"jack:u=%.4f,d=%.4f,l=%.4f,r=%.4f\n",mtg->m.aj[0],mtg->m.aj[1],mtg->m.aj[2],mtg->m.aj[3]);
                //mtg->snum.tm=fabs(mtg->m1.headc-mtg->snum.mile);
			    //trace(0,"iseg:%d,%d\n",mtg->m1.iseg,mtg->m.iseg);
			    //trace(0,"database m1:headh=%.4f,headv=%.4f,headc=%.4f\n",mtg->m1.headh,mtg->m1.headv,mtg->m1.headc);
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",15,1);
                    fflush(mtg->fbi);
                }
			}
			else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",15,0);
                    fflush(mtg->fbi);
                }
                mtg->m1.iseg=mtg->snum.iseg;
            }
			mysql_free_result(results);
			ret++;

			if(mtg->m1.t3<=0)
            {
                mtg->m1.t3=mtg->m0.t3;
                mtg->m1.prism[0] = mtg->m0.prism[0];
                mtg->m1.prism[1] = mtg->m0.prism[1];
                mtg->m1.prism[2] = mtg->m0.prism[2];
            }
//            //测试用
//            mtg->m=mtg->m1;
//            mtg_laser_gesture(mtg);
		}

        //trace(0,"Database: %s,%d\n",cmd,ret);

		///姿态复核
		strcpy(cmd,"select * from mcheck_set order by id desc limit 1");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            i=1;
            results = mysql_store_result(&mysql);
		    if((record = mysql_fetch_row(results)))
            {
                sscanf(record[i++],"%lf",&mtg->mp.head[0]);
			    sscanf(record[i++],"%lf",&mtg->mp.head[1]);
			    sscanf(record[i++],"%lf",&mtg->mp.head[2]);
			    sscanf(record[i++],"%lf",&mtg->mp.head[3]);
			    sscanf(record[i++],"%lf",&mtg->mp.head[4]);
			    sscanf(record[i++],"%lf",&mtg->mp.head[5]);
			    sscanf(record[i++],"%lf",&mtg->mp.tail[0]);
			    sscanf(record[i++],"%lf",&mtg->mp.tail[1]);
			    sscanf(record[i++],"%lf",&mtg->mp.tail[2]);
			    sscanf(record[i++],"%lf",&mtg->mp.tail[3]);
			    sscanf(record[i++],"%lf",&mtg->mp.tail[4]);
			    sscanf(record[i++],"%lf",&mtg->mp.tail[5]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[9]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[10]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[11]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[12]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[13]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[14]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[15]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[16]);
			    //sscanf(record[i++],"%lf",&mtg->mp.prism[17]);
			    sscanf(record[i++],"%lf",&mtg->mp.inc[0]);
			    sscanf(record[i++],"%lf",&mtg->mp.inc[1]);
			    sscanf(record[i++],"%lf",&mtg->mp.inc[2]);
			    sscanf(record[i++],"%lf",&mtg->mp.inc[3]);
			    sscanf(record[i++],"%lf",&mtg->mp.inc[4]);
			    sscanf(record[i++],"%lf",&mtg->mp.inc[5]);
			    sscanf(record[i++],"%lf",&mtg->mp.headc);
			    sscanf(record[i++],"%lf",&mtg->mp.headh);
			    sscanf(record[i++],"%lf",&mtg->mp.headv);
			    sscanf(record[i++],"%lf",&mtg->mp.headh1);
			    sscanf(record[i++],"%lf",&mtg->mp.headv1);
			    sscanf(record[i++],"%lf",&mtg->mp.tailc);
			    sscanf(record[i++],"%lf",&mtg->mp.tailh);
			    sscanf(record[i++],"%lf",&mtg->mp.tailv);
			    sscanf(record[i++],"%lf",&mtg->mp.tailh1);
			    sscanf(record[i++],"%lf",&mtg->mp.tailv1);
			    sscanf(record[i++],"%ld",&t);
			    mtg->mp.t=t;
			    if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",16,1);
                    fflush(mtg->fbi);
                }
            }
            else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",16,0);
                    fflush(mtg->fbi);
                }
            }
            mysql_free_result(results);
			ret++;

        }
        if(mtg->mp.t<=0)
        {
            mtg->mp.prism[9]=mtg->mp.prism[0];
            mtg->mp.prism[10]=mtg->mp.prism[1];
            mtg->mp.prism[11]=mtg->mp.prism[2];
            mtg->mp.prism[12]=mtg->mp.prism[3];
            mtg->mp.prism[13]=mtg->mp.prism[4];
            mtg->mp.prism[14]=mtg->mp.prism[5];
            mtg->mp.prism[15]=mtg->mp.prism[6];
            mtg->mp.prism[16]=mtg->mp.prism[7];
            mtg->mp.prism[17]=mtg->mp.prism[8];
        }
		//trace(0,"Database: %s,%d\n",cmd,ret);

		road_clear_horizon(&mtg->r);
        road_clear_vertical(&mtg->r);
        road_clear_horizon_off(&mtg->r);
        road_clear_vertical_off(&mtg->r);
        road_clear_mile_off(&mtg->r);
		///平曲线17
		strcpy(cmd,"select * from horizon_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%d",&h.type);
			    sscanf(record[2],"%lf",&h.l1);
			    sscanf(record[3],"%lf",&h.length);
			    sscanf(record[4],"%lf",&h.angle1);
			    sscanf(record[5],"%lf",&h.angle2);
			    sscanf(record[6],"%lf",&h.radius);
			    sscanf(record[7],"%lf",&h.rou1);
			    sscanf(record[8],"%lf",&h.rou2);
			    sscanf(record[9],"%lf",&h.x1);
			    sscanf(record[10],"%lf",&h.y1);
			    sscanf(record[11],"%lf",&h.x2);
			    sscanf(record[12],"%lf",&h.y2);
			    sscanf(record[13],"%d",&h.pz);
			    sscanf(record[14],"%lf",&h.deta);
                road_insert_horizon(&mtg->r,&h,index);
                index++;
			}

			mysql_free_result(results);
			ret++;
			if(index<=2) mtg->ierr[4]=1;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",17,index);
                fflush(mtg->fbi);
			}
		}
		//trace(0,"Database: %s,%d\n",cmd,ret);
		///竖曲线18
		strcpy(cmd,"select * from vertical_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%d",&v.type);
			    sscanf(record[2],"%lf",&v.l1);
			    sscanf(record[3],"%lf",&v.h1);
			    sscanf(record[4],"%lf",&v.l2);
			    sscanf(record[5],"%lf",&v.h2);
			    sscanf(record[6],"%lf",&v.length);
			    sscanf(record[7],"%lf",&v.radius);
			    sscanf(record[8],"%lf",&v.angle1);
			    sscanf(record[9],"%lf",&v.angle2);
			    sscanf(record[10],"%d",&v.pz);
			    sscanf(record[11],"%lf",&v.deta);
			    v.T=v.length/2.0;
                road_insert_vertical(&mtg->r,&v,index);
                index++;
			}

			mysql_free_result(results);
			ret++;
			if(index<=2) mtg->ierr[5]=1;
			if(mtg->fbi)
            {
                fprintf(mtg->fbi,"%%R1P,%d,%d\n",18,index);
                fflush(mtg->fbi);
            }
		}
		//trace(0,"Database: %s,%d\n",cmd,ret);
		///平曲线偏移19
		strcpy(cmd,"select * from hoff_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%lf",&ho.mile);
			    sscanf(record[2],"%lf",&ho.off);
                road_insert_horizon_off(&mtg->r,&ho);
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",19,index);
                fflush(mtg->fbi);
			}
		}
		//trace(0,"Database: %s,%d\n",cmd,ret);
		///竖曲线偏移20
		strcpy(cmd,"select * from voff_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%lf",&vo.mile);
			    sscanf(record[2],"%lf",&vo.off);
                road_insert_vertical_off(&mtg->r,&vo);
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",20,index);
                fflush(mtg->fbi);
			}
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);
        ///里程偏移21
		strcpy(cmd,"select * from moff_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%lf",&mo.mile);
			    sscanf(record[2],"%lf",&mo.off);
                road_insert_mile_off(&mtg->r,&mo);
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",21,index);
                fflush(mtg->fbi);
			}
		}
        if(road_number_horizon(&mtg->r)>2)
        {
            road_apply_horizon1(&mtg->r);
        }
        if(road_number_vertical(&mtg->r)>2)
        {
            road_apply_vertical1(&mtg->r);
        }

        //trace(0,"Database: %s,%d\n",cmd,ret);
		///管环选型数据
		mtg->segs[0]=segs;
		strcpy(cmd,"select * from segs_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    i=1;
			    sscanf(record[i++],"%d",&mtg->segs[index].numb);
			    //trace(0,"index=%d,numb=%d\n",index,mtg->segs[index].numb);
			    sscanf(record[i++],"%d",&mtg->segs[index].type);
			    sscanf(record[i++],"%d",&mtg->segs[index].k);
			    sscanf(record[i++],"%d",&mtg->segs[index].mode);
			    sscanf(record[i++],"%lf",&mtg->segs[index].hpz);
			    sscanf(record[i++],"%lf",&mtg->segs[index].vpz);
			    sscanf(record[i++],"%lf",&mtg->segs[index].x);
			    sscanf(record[i++],"%lf",&mtg->segs[index].y);
			    sscanf(record[i++],"%lf",&mtg->segs[index].z);
			    sscanf(record[i++],"%lf",&mtg->segs[index].x1);
			    sscanf(record[i++],"%lf",&mtg->segs[index].y1);
			    sscanf(record[i++],"%lf",&mtg->segs[index].z1);
			    sscanf(record[i++],"%lf",&mtg->segs[index].ori);
			    sscanf(record[i++],"%lf",&mtg->segs[index].phi);
			    sscanf(record[i++],"%lf",&mtg->segs[index].ori1);
			    sscanf(record[i++],"%lf",&mtg->segs[index].phi1);
			    sscanf(record[i++],"%lf",&mtg->segs[index].mile);
			    sscanf(record[i++],"%lf",&mtg->segs[index].dh);
			    sscanf(record[i++],"%lf",&mtg->segs[index].dv);
			    sscanf(record[i++],"%lf",&mtg->segs[index].dh1);
                sscanf(record[i++],"%lf",&mtg->segs[index].dv1);
			    sscanf(record[i++],"%lf",&mtg->segs[index].head[0]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].head[1]);
                sscanf(record[i++],"%lf",&mtg->segs[index].head[2]);
                sscanf(record[i++],"%lf",&mtg->segs[index].headc);
			    sscanf(record[i++],"%lf",&mtg->segs[index].headh);
			    sscanf(record[i++],"%lf",&mtg->segs[index].headv);
			    sscanf(record[i++],"%lf",&mtg->segs[index].tail[0]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].tail[1]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].tail[2]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].tailc);
			    sscanf(record[i++],"%lf",&mtg->segs[index].tailh);
			    sscanf(record[i++],"%lf",&mtg->segs[index].tailv);
			    sscanf(record[i++],"%lf",&mtg->segs[index].tbmh);
			    sscanf(record[i++],"%lf",&mtg->segs[index].tbmv);
			    sscanf(record[i++],"%lf",&mtg->segs[index].desh);
			    sscanf(record[i++],"%lf",&mtg->segs[index].desv);
			    sscanf(record[i++],"%lf",&mtg->segs[index].gap[0]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].gap[1]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].gap[2]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].gap[3]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].aj[0]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].aj[1]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].aj[2]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].aj[3]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].faj[0]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].faj[1]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].faj[2]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].faj[3]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].baj[0]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].baj[1]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].baj[2]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].baj[3]);
			    sscanf(record[i++],"%lf",&mtg->segs[index].harc);
			    sscanf(record[i++],"%lf",&mtg->segs[index].varc);
			    sscanf(record[i++],"%ld",&t);
			    mtg->segs[index].t=t;
			    index++;
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",22,index);
                fflush(mtg->fbi);
			}
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);

        strcpy(cmd,"select * from seging_set");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            results = mysql_store_result(&mysql);
            if((record = mysql_fetch_row(results)))
            {
                sscanf(record[1],"%d",&mtg->iseg.numb);
                sscanf(record[2],"%d",&mtg->iseg.type);
                sscanf(record[3],"%d",&mtg->iseg.k);
                sscanf(record[4],"%lf",&mtg->iseg.headc);
                sscanf(record[5],"%d",&mtg->sneed[0]);
                sscanf(record[6],"%d",&mtg->sneed[1]);
                sscanf(record[7],"%d",&mtg->sneed[2]);
                sscanf(record[8],"%ld",&t);
			    mtg->iseg.t=t;
			    if(mtg->fbi)
			    {
			        fprintf(mtg->fbi,"%%R1P,%d,%d\n",23,1);
                    fflush(mtg->fbi);
			    }
            }
            else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",23,0);
                    fflush(mtg->fbi);
                }
            }
            mysql_free_result(results);
            ret++;

        }
        //trace(0,"Database: %s,%d\n",cmd,ret);
        ///管环参数23
		mtg->segset = seg;
		strcpy(cmd,"select * from segment_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    if((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%d",&mtg->segset.type);
			    sscanf(record[2],"%d",&mtg->segset.in);
				sscanf(record[3],"%d",&mtg->segset.f2b);
				sscanf(record[4],"%lf",&mtg->segset.l2s);
				sscanf(record[5],"%lf",&mtg->segset.L);
				sscanf(record[6],"%lf",&mtg->segset.De);
				sscanf(record[7],"%lf",&mtg->segset.D);
				sscanf(record[8],"%d",&mtg->segset.Ks);
				sscanf(record[9],"%lf",&mtg->segset.G0);
				sscanf(record[10],"%lf",&mtg->segset.G1);
				sscanf(record[11],"%d",&mtg->segset.s2s);
				if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",24,1);
                    fflush(mtg->fbi);
                }
			}
			else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",24,0);
                    fflush(mtg->fbi);
                }
            }
			mysql_free_result(results);
			mtg->iseg.ipos=(int*)malloc(mtg->segset.Ks*sizeof(int));
			mtg_init_segs(mtg);
			ret++;
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);

		strcpy(cmd,"select * from check_set order by id desc limit 1");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    if((record = mysql_fetch_row(results)))
			{
			    i=0;
			    sscanf(record[i++],"%lf",&mtg->mp.head[0]);
			    sscanf(record[i++],"%lf",&mtg->mp.head[1]);
			    sscanf(record[i++],"%lf",&mtg->mp.head[2]);

			    sscanf(record[i++],"%lf",&mtg->mp.head[3]);
			    sscanf(record[i++],"%lf",&mtg->mp.head[4]);
			    sscanf(record[i++],"%lf",&mtg->mp.head[5]);

			    sscanf(record[i++],"%lf",&mtg->mp.tail[0]);
			    sscanf(record[i++],"%lf",&mtg->mp.tail[1]);
			    sscanf(record[i++],"%lf",&mtg->mp.tail[2]);

			    sscanf(record[i++],"%lf",&mtg->mp.tail[3]);
			    sscanf(record[i++],"%lf",&mtg->mp.tail[4]);
                sscanf(record[i++],"%lf",&mtg->mp.tail[5]);

                sscanf(record[i++],"%lf",&mtg->mp.prism[0]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[1]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[2]);

			    sscanf(record[i++],"%lf",&mtg->mp.prism[3]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[4]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[5]);

			    sscanf(record[i++],"%lf",&mtg->mp.prism[6]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[7]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[8]);

			    sscanf(record[i++],"%lf",&mtg->mp.prism[9]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[10]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[11]);

			    sscanf(record[i++],"%lf",&mtg->mp.prism[12]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[13]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[14]);

			    sscanf(record[i++],"%lf",&mtg->mp.prism[15]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[16]);
			    sscanf(record[i++],"%lf",&mtg->mp.prism[17]);

			    sscanf(record[i++],"%lf",&mtg->mp.inc[0]);
			    sscanf(record[i++],"%lf",&mtg->mp.inc[1]);
			    sscanf(record[i++],"%lf",&mtg->mp.inc[2]);
			    sscanf(record[i++],"%lf",&mtg->mp.inc[3]);
			    sscanf(record[i++],"%lf",&mtg->mp.inc[4]);
			    sscanf(record[i++],"%lf",&mtg->mp.inc[5]);

			    sscanf(record[i++],"%lf",&mtg->mp.pdev[3]);
			    sscanf(record[i++],"%lf",&mtg->mp.pdev[4]);
			    sscanf(record[i++],"%lf",&mtg->mp.pdev[5]);

			    sscanf(record[i++],"%lf",&mtg->mp.headh);
			    sscanf(record[i++],"%lf",&mtg->mp.headv);
			    sscanf(record[i++],"%lf",&mtg->mp.headh1);
			    sscanf(record[i++],"%lf",&mtg->mp.headv1);
			    sscanf(record[i++],"%lf",&mtg->mp.tailh);
			    sscanf(record[i++],"%lf",&mtg->mp.tailv);
			    sscanf(record[i++],"%lf",&mtg->mp.tailh1);
			    sscanf(record[i++],"%lf",&mtg->mp.tailv1);
			    sscanf(record[i++],"%ld",&mtg->mp.t);
			    if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",25,1);
                    fflush(mtg->fbi);
                }
			}
			else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",25,0);
                    fflush(mtg->fbi);
                }
            }
			mysql_free_result(results);
			ret++;
		}
		//trace(0,"Database: %s,%d\n",cmd,ret);

		///管环拼装记录
        strcpy(cmd,"create table if not exists segrecord_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `segnum` int(11) DEFAULT 0,\
               `segtype` int(11) DEFAULT 0,\
               `location` int(11) DEFAULT 0,\
               `mile` double DEFAULT NULL,\
               `offh` double DEFAULT NULL,\
               `offv` double DEFAULT NULL,\
               `t` int(11) DEFAULT 0,\
               PRIMARY KEY (`id`)\
               )");
        mysql_real_query(&mysql,cmd,strlen(cmd));

        strcpy(cmd,"select * from segrecord_set");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            results = mysql_store_result(&mysql);
            rows=mysql_num_rows(results);
            mtg->SegRecNum=rows;
            mtg->segrecord=(SEG_RECORD*)malloc(rows*sizeof(SEG_RECORD));
            index=0;
            while((record = mysql_fetch_row(results)))
            {
                i=1;
                sscanf(record[i++],"%d",&mtg->segrecord[index].segnum);
                sscanf(record[i++],"%d",&mtg->segrecord[index].segtype);
                sscanf(record[i++],"%d",&mtg->segrecord[index].location);
                sscanf(record[i++],"%lf",&mtg->segrecord[index].mile);
                sscanf(record[i++],"%lf",&mtg->segrecord[index].offh);
                sscanf(record[i++],"%lf",&mtg->segrecord[index].offv);
                sscanf(record[i++],"%ld",&t);
                mtg->segrecord[index].t=t;
                index++;
            }
            mysql_free_result(results);
        }



		///掘进报表
		strcpy(cmd,"select * from duty_set order by id desc limit 1");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    i=0;
		    results = mysql_store_result(&mysql);
		    if((record = mysql_fetch_row(results)))
			{
			    sscanf(record[0],"%d",&index);
			    sscanf(record[1],"%d",&i);
			    mtg->onduty=i;
			    mtg->duty[i].id=index;
			    strcpy(mtg->duty[i].name,record[2]);
			    sscanf(record[3],"%d",&mtg->duty[i].seg1);
			    sscanf(record[4],"%d",&mtg->duty[i].seg2);
			    sscanf(record[5],"%lf",&mtg->duty[i].mile1);
			    sscanf(record[6],"%lf",&mtg->duty[i].mile2);
			    sscanf(record[7],"%ld",&t);
			    mtg->duty[i].t1=t;
			    sscanf(record[8],"%ld",&t);
			    mtg->duty[i].t2=t;
			    sscanf(record[9],"%lf",&mtg->duty[i].mxdev);
			    if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",26,1);
                    fflush(mtg->fbi);
                }
			}
			else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",26,0);
                    fflush(mtg->fbi);
                }
            }
			mysql_free_result(results);
			ret++;
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);

        ///盾尾间隙
        strcpy(cmd,"create table if not exists gaps_set(\
                `id` int(11) NOT NULL AUTO_INCREMENT,\
                `a1` double DEFAULT NULL,\
                `a2` double DEFAULT NULL,\
                `a3` double DEFAULT NULL,\
                `a4` double DEFAULT NULL,\
                `a5` double DEFAULT NULL,\
                `s1` double DEFAULT NULL,\
                `s2` double DEFAULT NULL,\
                `s3` double DEFAULT NULL,\
                `s4` double DEFAULT NULL,\
                `s5` double DEFAULT NULL,\
                `sel1` int(11) DEFAULT NULL,\
                `sel2` int(11) DEFAULT NULL,\
                `sel3` int(11) DEFAULT NULL,\
                `sel4` int(11) DEFAULT NULL,\
                `sel5` int(11) DEFAULT NULL,\
                `x` double DEFAULT NULL,\
                `y` double DEFAULT NULL,\
                `z` double DEFAULT NULL,\
                `radius` double DEFAULT NULL,\
                `radius1` double DEFAULT NULL,\
                `ugap` double DEFAULT NULL,\
                `dgap` double DEFAULT NULL,\
                `lgap` double DEFAULT NULL,\
                `rgap` double DEFAULT NULL,\
                `ujust` double DEFAULT NULL,\
                `djust` double DEFAULT NULL,\
                `ljust` double DEFAULT NULL,\
                `rjust` double DEFAULT NULL,\
               PRIMARY KEY (`id`)\
               )");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"gaps_set:%d\n",mysql_real_query(&mysql,cmd,strlen(cmd)));

        strcpy(cmd,"select * from gaps_set order by id desc limit 1");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            results=mysql_store_result(&mysql);
            if((record = mysql_fetch_row(results)))
            {
                //strcpy(mtg->gaps.IP,record[1]);
                i=1;
                sscanf(record[i++],"%lf",&mtg->dister[0].angle);
                sscanf(record[i++],"%lf",&mtg->dister[1].angle);
                sscanf(record[i++],"%lf",&mtg->dister[2].angle);
                sscanf(record[i++],"%lf",&mtg->dister[3].angle);
                sscanf(record[i++],"%lf",&mtg->dister[4].angle);
                sscanf(record[i++],"%lf",&mtg->dister[0].dist);
                sscanf(record[i++],"%lf",&mtg->dister[1].dist);
                sscanf(record[i++],"%lf",&mtg->dister[2].dist);
                sscanf(record[i++],"%lf",&mtg->dister[3].dist);
                sscanf(record[i++],"%lf",&mtg->dister[4].dist);
                sscanf(record[i++],"%d",&mtg->dister[0].sel);
                sscanf(record[i++],"%d",&mtg->dister[1].sel);
                sscanf(record[i++],"%d",&mtg->dister[2].sel);
                sscanf(record[i++],"%d",&mtg->dister[3].sel);
                sscanf(record[i++],"%d",&mtg->dister[4].sel);
                sscanf(record[i++],"%lf",&mtg->gaps.x);
                sscanf(record[i++],"%lf",&mtg->gaps.y);
                sscanf(record[i++],"%lf",&mtg->gaps.z);
                sscanf(record[i++],"%lf",&mtg->gaps.radius);
                sscanf(record[i++],"%lf",&mtg->gaps.d1);
                sscanf(record[i++],"%lf",&mtg->gaps.ugap);
                sscanf(record[i++],"%lf",&mtg->gaps.dgap);
                sscanf(record[i++],"%lf",&mtg->gaps.lgap);
                sscanf(record[i++],"%lf",&mtg->gaps.rgap);
                sscanf(record[i++],"%lf",&mtg->gaps.ujust);
                sscanf(record[i++],"%lf",&mtg->gaps.djust);
                sscanf(record[i++],"%lf",&mtg->gaps.ljust);
                sscanf(record[i++],"%lf",&mtg->gaps.rjust);
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",27,1);
                    fflush(mtg->fbi);
                }
            }
            else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",27,0);
                    fflush(mtg->fbi);
                }
            }
            mysql_free_result(results);
            ret++;
        }

        strcpy(cmd,"create table if not exists gapmeas_set(\
                `id` int(11) NOT NULL AUTO_INCREMENT,\
                `s1` double DEFAULT NULL,\
                `s2` double DEFAULT NULL,\
                `s3` double DEFAULT NULL,\
                `s4` double DEFAULT NULL,\
                `s5` double DEFAULT NULL,\
                `d1` double DEFAULT NULL,\
                `d2` double DEFAULT NULL,\
                `d3` double DEFAULT NULL,\
                `d4` double DEFAULT NULL,\
                `d5` double DEFAULT NULL,\
                `x` double DEFAULT NULL,\
                `y` double DEFAULT NULL,\
                `z` double DEFAULT NULL,\
                `radius` double DEFAULT NULL,\
                `ugap` double DEFAULT NULL,\
                `dgap` double DEFAULT NULL,\
                `lgap` double DEFAULT NULL,\
                `rgap` double DEFAULT NULL,\
                `t` int(11) DEFAULT NULL,\
               PRIMARY KEY (`id`)\
               )");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        //trace(0,"gapmeas_set:%d\n", mysql_real_query(&mysql,cmd,strlen(cmd)));
        strcpy(cmd,"select * from gapmeas_set order by id desc limit 1");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            results=mysql_store_result(&mysql);
            if((record = mysql_fetch_row(results)))
            {
                i=1;
                sscanf(record[i++],"%lf",&mtg->dister[0].dist0);
                sscanf(record[i++],"%lf",&mtg->dister[1].dist0);
                sscanf(record[i++],"%lf",&mtg->dister[2].dist0);
                sscanf(record[i++],"%lf",&mtg->dister[3].dist0);
                sscanf(record[i++],"%lf",&mtg->dister[4].dist0);
                sscanf(record[i++],"%lf",&mtg->dister[0].dist1);
                sscanf(record[i++],"%lf",&mtg->dister[1].dist1);
                sscanf(record[i++],"%lf",&mtg->dister[2].dist1);
                sscanf(record[i++],"%lf",&mtg->dister[3].dist1);
                sscanf(record[i++],"%lf",&mtg->dister[4].dist1);
                sscanf(record[i++],"%lf",&mtg->gaps.x1);
                sscanf(record[i++],"%lf",&mtg->gaps.y1);
                sscanf(record[i++],"%lf",&mtg->gaps.z1);
                sscanf(record[i++],"%lf",&mtg->gaps.radius1);
                sscanf(record[i++],"%lf",&mtg->gaps.ugap1);
                sscanf(record[i++],"%lf",&mtg->gaps.dgap1);
                sscanf(record[i++],"%lf",&mtg->gaps.lgap1);
                sscanf(record[i++],"%lf",&mtg->gaps.rgap1);
                sscanf(record[i++],"%ld",&t);
                mtg->gaps.t=t;
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",28,1);
                    fflush(mtg->fbi);
                }
            }
            else
            {
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d\n",28,0);
                    fflush(mtg->fbi);
                }
            }
            mysql_free_result(results);
            ret++;
        }

        strcpy(cmd,"create table if not exists recheck_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `iredta` int(11) DEFAULT 0,\
               `tredta` int(11) DEFAULT 0,\
               PRIMARY KEY (`id`)\
               )");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        mtg->recheck.idta=0;
        mtg->recheck.dta_t=0;
        strcpy(cmd,"select * from recheck_set order by id desc limit 1");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            results=mysql_store_result(&mysql);
            if((record = mysql_fetch_row(results)))
            {
                i=1;
                sscanf(record[i++],"%d",&mtg->recheck.idta);
                sscanf(record[i++],"%ld",&t);
                mtg->recheck.dta_t=t;
            }
            mysql_free_result(results);
            ret++;
        }

        strcpy(cmd,"create table if not exists inccheck_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `contimes` int(11) DEFAULT 0,\
               `daytimes` int(11) DEFAULT 0,\
               `t` int(11) DEFAULT 0,\
               PRIMARY KEY (`id`)\
               )");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        mtg->inc_check.contimes=0;
        mtg->inc_check.daytimes=0;
        mtg->inc_check.t=0;
        strcpy(cmd,"select * from inccheck_set order by id desc limit 1");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            results=mysql_store_result(&mysql);
            if((record = mysql_fetch_row(results)))
            {
                i=1;
                sscanf(record[i++],"%d",&mtg->inc_check.contimes);
                sscanf(record[i++],"%d",&mtg->inc_check.daytimes);
                sscanf(record[i++],"%ld",&t);
                mtg->inc_check.t=t;
            }
            mysql_free_result(results);
            ret++;
        }
	}
	trace(0,"headh:%.4f,%.4f\n",mtg->m1.hdev1,mtg->m1.vdev1);
    trace(0,"Database: import db successful\n");

	mysql_close(&mysql);
	unlock(&mtg->dblock);
	init_cam(mtg);
	//fclose(mtg->fbi);
	if(fp)
    {
        fclose(fp);
        fp=NULL;
    }
	return ret;
}

int mtg_store_road(mtg_t* mtg)
{
    int i,n;
    int ret=0;
	MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[1024];
	int index=0;
	h_element *he;
    v_element *ve;
    h_offset *ho;
    v_offset *vo;
    m_offset *mo;

    FILE* fp=NULL;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    ///begin
	    strcpy(cmd,"start transaction");
	    mysql_real_query(&mysql,cmd,strlen(cmd));
        ///存储
        strcpy(cmd,"truncate  horizon_set");   ///平曲线
        mysql_real_query(&mysql,cmd,strlen(cmd));
        n=road_number_horizon(&mtg->r);
        if(fp)
        fprintf(fp,"%%R1P,1:0:%d,%d,%d,%d,%d\n",
               n,road_number_vertical(&mtg->r),road_number_horizon_off(&mtg->r),road_number_vertical_off(&mtg->r),road_number_mile_off(&mtg->r));
        for(i=0;i<n;i++)
        {
            he=road_horizon(&mtg->r,i);
            if(i==n-1 && he->type>4)
            {
                he->type=4;
            }
            sprintf(cmd,"insert into horizon_set values(\
                    %d,%d,%.12f,%.12f,%.12f,%.12f,\
                    %.12f,%.12f,%.12f,\
                    %.12f,%.12f,%.12f,%.12f,%d,%.12f)",
                    i+1,he->type,he->l1,he->length,he->angle1,he->angle2,
                    he->radius,he->rou1,he->rou2,
                    he->x1,he->y1,he->x2,he->y2,he->pz,he->deta);
            trace(0,"cmd=%s\n",cmd);
            if(fp)
            fprintf(fp,"%%R1P,1:1:%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d,%f\n",i,he->type,
               he->l1,he->length,he->angle1,he->angle2,he->radius,he->rou1,he->rou2,he->x1,he->y1,
               he->x2,he->y2,he->pz,he->deta);
            mysql_real_query(&mysql,cmd,strlen(cmd));
        }
        strcpy(cmd,"truncate  vertical_set");  ///竖曲线
        mysql_real_query(&mysql,cmd,strlen(cmd));
        n=road_number_vertical(&mtg->r);
        for(i=0;i<n;i++)
        {
            ve=road_vertical(&mtg->r,i);
            if(i==n-1&&ve->type>4)
            {
                ve->type=4;
            }
            sprintf(cmd,"insert into vertical_set values(\
                    %d,%d,%.12f,%.12f,%.12f,%.12f,\
                    %.12f,%.12f,%.12f,%.12f,%d,%.12f)",
                    i+1,ve->type,ve->l1,ve->h1,ve->l2,ve->h2,
                    ve->length,ve->radius,ve->angle1,ve->angle2,ve->pz,ve->deta);
            mysql_real_query(&mysql,cmd,strlen(cmd));
            trace(0,"cmd=%s\n",cmd);
            if(fp)
            fprintf(fp,"%%R1P,1:2:%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%d,%f\n",i,ve->type,ve->l1,ve->h1,ve->l2,ve->h2,
                    ve->length,ve->radius,ve->angle1,ve->angle2,ve->pz,ve->deta);
        }
        strcpy(cmd,"truncate  hoff_set");  ///平曲线偏移
        mysql_real_query(&mysql,cmd,strlen(cmd));
        n=road_number_horizon_off(&mtg->r);
        for(i=0;i<n;i++)
        {
            ho=road_horizon_off(&mtg->r,i);
            sprintf(cmd,"insert into hoff_set values(%d,%.12f,%.12f)",i+1,ho->mile,ho->off);
            mysql_real_query(&mysql,cmd,strlen(cmd));
            if(fp)
            fprintf(fp,"%%R1P,1:3:%d,%f,%f\n",i,ho->mile,ho->off);
        }
        strcpy(cmd,"truncate voff_set");  ///竖曲线偏移
        mysql_real_query(&mysql,cmd,strlen(cmd));
        n=road_number_vertical_off(&mtg->r);
        for(i=0;i<n;i++)
        {
            vo=road_vertical_off(&mtg->r,i);
            sprintf(cmd,"insert into voff_set values(%d,%.12f,%.12f)",i+1,vo->mile,vo->off);
            mysql_real_query(&mysql,cmd,strlen(cmd));
            if(fp)
            fprintf(fp,"%%R1P,1:4:%d,%d,%f,%f\n",i,vo->mile,vo->off);
        }
        strcpy(cmd,"truncate moff_set");  ///竖曲线偏移
        mysql_real_query(&mysql,cmd,strlen(cmd));
        n=road_number_mile_off(&mtg->r);
        for(i=0;i<n;i++)
        {
            mo=road_mile_off(&mtg->r,i);
            sprintf(cmd,"insert into moff_set values(%d,%.12f,%.12f)",i+1,mo->mile,mo->off);
            mysql_real_query(&mysql,cmd,strlen(cmd));
            if(fp)
            fprintf(fp,"%%R1P,1:5:%d,%f,%f\n",i,mo->mile,mo->off);
        }
        ///commit
		strcpy(cmd,"commit");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		ret=1;
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);

	return ret;
}

int mtg_import_road(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[4096];
	int index=0,i;
	h_element h;
    v_element v;
    h_offset ho;
    v_offset vo;
    m_offset mo;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        road_clear_horizon(&mtg->r);
        road_clear_vertical(&mtg->r);
        road_clear_horizon_off(&mtg->r);
        road_clear_vertical_off(&mtg->r);
        road_clear_mile_off(&mtg->r);
		///平曲线17
		strcpy(cmd,"select * from horizon_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%d",&h.type);
			    sscanf(record[2],"%lf",&h.l1);
			    sscanf(record[3],"%lf",&h.length);
			    sscanf(record[4],"%lf",&h.angle1);
			    sscanf(record[5],"%lf",&h.angle2);
			    sscanf(record[6],"%lf",&h.radius);
			    sscanf(record[7],"%lf",&h.rou1);
			    sscanf(record[8],"%lf",&h.rou2);
			    sscanf(record[9],"%lf",&h.x1);
			    sscanf(record[10],"%lf",&h.y1);
			    sscanf(record[11],"%lf",&h.x2);
			    sscanf(record[12],"%lf",&h.y2);
			    sscanf(record[13],"%d",&h.pz);
			    sscanf(record[14],"%lf",&h.deta);
                road_insert_horizon(&mtg->r,&h,index);
                index++;
			}

			mysql_free_result(results);
			ret++;
			if(index<=2) mtg->ierr[4]=1;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",17,index);
                fflush(mtg->fbi);
			}
		}
		//trace(0,"Database: %s,%d\n",cmd,ret);
		///竖曲线18
		strcpy(cmd,"select * from vertical_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%d",&v.type);
			    sscanf(record[2],"%lf",&v.l1);
			    sscanf(record[3],"%lf",&v.h1);
			    sscanf(record[4],"%lf",&v.l2);
			    sscanf(record[5],"%lf",&v.h2);
			    sscanf(record[6],"%lf",&v.length);
			    sscanf(record[7],"%lf",&v.radius);
			    sscanf(record[8],"%lf",&v.angle1);
			    sscanf(record[9],"%lf",&v.angle2);
			    sscanf(record[10],"%d",&v.pz);
			    sscanf(record[11],"%lf",&v.deta);
                road_insert_vertical(&mtg->r,&v,index);
                index++;
			}

			mysql_free_result(results);
			ret++;
			if(index<=2) mtg->ierr[5]=1;
			if(mtg->fbi)
            {
                fprintf(mtg->fbi,"%%R1P,%d,%d\n",18,index);
                fflush(mtg->fbi);
            }
		}
		//trace(0,"Database: %s,%d\n",cmd,ret);
		///平曲线偏移19
		strcpy(cmd,"select * from hoff_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%lf",&ho.mile);
			    sscanf(record[2],"%lf",&ho.off);
                road_insert_horizon_off(&mtg->r,&ho);
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",19,index);
                fflush(mtg->fbi);
			}
		}
		//trace(0,"Database: %s,%d\n",cmd,ret);
		///竖曲线偏移20
		strcpy(cmd,"select * from voff_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%lf",&vo.mile);
			    sscanf(record[2],"%lf",&vo.off);
                road_insert_vertical_off(&mtg->r,&vo);
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",20,index);
                fflush(mtg->fbi);
			}
		}
        //trace(0,"Database: %s,%d\n",cmd,ret);
        ///里程偏移21
		strcpy(cmd,"select * from moff_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%lf",&mo.mile);
			    sscanf(record[2],"%lf",&mo.off);
                road_insert_mile_off(&mtg->r,&mo);
			}
			mysql_free_result(results);
			ret++;
			if(mtg->fbi)
			{
			    fprintf(mtg->fbi,"%%R1P,%d,%d\n",21,index);
                fflush(mtg->fbi);
			}
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	return ret;
}

///存储环号计算参数
int mtg_store_snum(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
	MTG_SEG_SERIAL* snum=0;
    FILE* fp=NULL;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");
	snum=&mtg->snum;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        sprintf(cmd,"insert into serial_set(\
                iseg,mile,tm) values(\
                %d,%.12f,%.12f)",
                snum->iseg,snum->mile,snum->tm);
        trace(0,"cmd=%s\n",cmd);
        if(fp)
            fprintf(fp,"%%R1P,2:0:%d,%f,%f\n",snum->iseg,snum->mile,snum->tm);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            ret=1;
        }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
    if(fp)
    {
        fclose(fp);
        fp=NULL;
    }
	return ret;
}

///添加用户
int mtg_add_user(mtg_t* mtg,const MTG_USER* u)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,
             "insert into user_set values(%d,'%s','%s',%d)",
             mtg->nuser+1,u->name,u->password,u->level);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->nuser++;
		    if(mtg->user) mtg->user=(MTG_USER*)realloc(mtg->user,mtg->nuser*sizeof(MTG_USER));
		    else mtg->user=(MTG_USER*)malloc(sizeof(MTG_USER));
		    mtg->user[mtg->nuser-1]=*u;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	return ret;
}

///删除用户
int mtg_remove_user(mtg_t* mtg,int index)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
    int i;

    for(i=index;i<mtg->nuser-1;i++)
    {
        mtg->user[i]=mtg->user[i+1];
    }

    mtg->nuser--;
    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    strcpy(cmd,"drop table user_set");
	    mysql_real_query(&mysql,cmd,strlen(cmd));

	    strcpy(cmd,"create table user_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `name` char(64) DEFAULT NULL,\
            `password` char(64) DEFAULT NULL,\
            `level` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
        mysql_real_query(&mysql,cmd,strlen(cmd));

        for(i=0;i<mtg->nuser;i++)
	    {
	        sprintf(cmd,
             "insert into user_set values(%d,'%s','%s',%d)",
             i+1,mtg->user[i].name,mtg->user[i].password,mtg->user[i].level);

            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
            {
                ret=1;
            }
	    }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	return ret;
}

///存储用户
int mtg_store_user(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
    int i;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    strcpy(cmd,"drop table user_set");
	    mysql_real_query(&mysql,cmd,strlen(cmd));

	    strcpy(cmd,"create table user_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `name` char(64) DEFAULT NULL,\
            `password` char(64) DEFAULT NULL,\
            `level` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        if(fp) fprintf(fp,"%%R1P,3:0:%d\n",mtg->nuser);
        for(i=0;i<mtg->nuser;i++)
	    {
	        sprintf(cmd,
             "insert into user_set values(%d,'%s','%s',%d)",
             i+1,mtg->user[i].name,mtg->user[i].password,mtg->user[i].level);
            if(fp)
            fprintf(fp,"%%R1P,3:1:%d,'%s','%s',%d\n",i,mtg->user[i].name,mtg->user[i].password,mtg->user[i].level);
            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
            {
                ret=1;
            }
	    }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
    if(fp) fclose(fp);
	return ret;
}

///编辑用户
int mtg_modify_user(mtg_t* mtg,int index,const MTG_USER* u)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"update user_set set name='%s',password='%s',level=%d where id=%d",u->name,u->password,u->level,index+1);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->user[index]=*u;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	return ret;
}

///添加吊篮
int mtg_add_basket(mtg_t* mtg,const MTG_BASKET* b)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");
    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,
             "insert into basket_set values('%s',%.12f,%.12f,%.12f,%ld)",
             b->name,b->x,b->y,b->z,(long)b->t);
        if(fp)
        fprintf(fp,"%%R1P,4:0:'%s',%f,%f,%f,%ld\n",b->name,b->x,b->y,b->z,(long)b->t);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->nbsk++;
		    if(mtg->bask) mtg->bask=(MTG_BASKET*)realloc(mtg->bask,mtg->nbsk*sizeof(MTG_BASKET));
		    else mtg->bask=(MTG_BASKET*)malloc(sizeof(MTG_BASKET));
		    mtg->bask[mtg->nbsk-1]=*b;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);
	return ret;
}

int mtg_remove_basket(mtg_t* mtg,int index)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");
    if(fp) fprintf(fp,"%%R1P,4:1:%d\n",index);

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"delete from basket_set where name='%s'",mtg->bask[index].name);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    for(i=index;i<mtg->nbsk-1;i++)
            {
                mtg->bask[i]=mtg->bask[i+1];
            }
		    mtg->nbsk--;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);
	return ret;
}

int mtg_clear_basket(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");
    if(fp) fprintf(fp,"%%R1P,4:2:%d\n",0);

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    strcpy(cmd,"truncate basket_set");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->nbsk=0;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);
	return ret;
}

int mtg_modify_basket(mtg_t* mtg,int index,const MTG_BASKET* b)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];

    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");
    if(fp) fprintf(fp,"%%R1P,4:3:%d,%f,%f,%f\n",index,b->x,b->y,b->z);

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"update  basket_set set x=%.12f,y=%.12f,z=%.12f  where name='%s'",b->x,b->y,b->z,mtg->bask[index].name);
		trace(0,"dbase:cmd=%s\n",cmd);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->bask[index].x=b->x;
		    mtg->bask[index].y=b->y;
		    mtg->bask[index].z=b->z;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);
	return ret;
}

int mtg_store_basket(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
    int i = 0;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        strcpy(cmd,"drop table basket_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table basket_set(\
                `name` char(64) DEFAULT NULL,\
                `x` double DEFAULT NULL,\
                `y` double DEFAULT NULL,\
                `z` double DEFAULT NULL,\
                `t` int(11) DEFAULT NULL,\
                PRIMARY KEY (`name`)\
                )");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        if(fp) fprintf(fp,"%%R1P,4:4:%d\n",mtg->nbsk);
        for(i=0;i<mtg->nbsk;i++)
        {
            sprintf(cmd,
                "insert into basket_set values('%s',%.12f,%.12f,%.12f,%ld)",
                mtg->bask[i].name,mtg->bask[i].x,mtg->bask[i].y,mtg->bask[i].z,(long)mtg->bask[i].t);
            if(fp)
            fprintf(fp,"%%R1P,4:5:%d,'%s',%f,%f,%f,%ld\n",i,mtg->bask[i].name,mtg->bask[i].x,mtg->bask[i].y,mtg->bask[i].z,(long)mtg->bask[i].t);
            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
            {
                ret=1;
                //mtg->nbsk++;
            }
        }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
	if(fp) fclose(fp);
	return ret;
}

///拼装记录
int mtg_add_record(mtg_t* mtg,SEG_RECORD* rec)
{
    int ret=0;
    MYSQL mysql;
	char cmd[1024];
    FILE* fp;
    if(mtg->backup==0)
        fp=fopen(mtg->dbpath,"a");
    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,
             "insert into segrecord_set(\
                segnum,segtype,location,mile,offh,offv,t)values(%d,%d,%d,%.12f,%.12f,%.12f,%ld)",
             rec->segnum,rec->segtype,rec->location,rec->mile,rec->offh,rec->offv,(long)rec->t);
        if(fp)
        {
            fprintf(fp,"%%R1P,70:0:%d,%d,%d,%.12f,%.12f,%.12f,%ld\n",rec->segnum,rec->segtype,rec->location,rec->mile,rec->offh,rec->offv,(long)rec->t);
            fflush(fp);
        }
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->SegRecNum++;
		    if(mtg->segrecord)
                mtg->segrecord=(SEG_RECORD*)realloc(mtg->segrecord,mtg->SegRecNum*sizeof(SEG_RECORD));
		    else
                mtg->segrecord=(SEG_RECORD*)malloc(sizeof(SEG_RECORD));
		    mtg->segrecord[mtg->SegRecNum-1]=*rec;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp)
        fclose(fp);
    return ret;
}

int mtg_modify_record(mtg_t* mtg,int index,SEG_RECORD* rec)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];

    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");
    if(fp)
    {
        fprintf(fp,"%%R1P,71:3:%d,%d,%d,%d\n",index,rec->segnum,rec->segtype,rec->location);
        fflush(fp);
    }

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"update segrecord_set set segnum=%d,segtype=%d,location=%d,mile=%lf,offh=%lf,offv=%lf,t=%ld where segnum=%d",
             rec->segnum,rec->segtype,rec->location,rec->mile,rec->offh,rec->offv,rec->t,mtg->segrecord[index].segnum);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->segrecord[index]=*rec;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp)
        fclose(fp);
	return ret;
}

int mtg_remove_record(mtg_t* mtg,int index)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
    FILE* fp;
    if(mtg->backup==0)
        fp=fopen(mtg->dbpath,"a");
    if(fp)
    {
        fprintf(fp,"%%R1P,72:1:%d\n",index);
        fflush(fp);
    }

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"delete from segrecord_set where segnum=%d",mtg->segrecord[index].segnum);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    for(i=index;i<mtg->SegRecNum-1;i++)
            {
                mtg->segrecord[i]=mtg->segrecord[i+1];
            }
		    mtg->SegRecNum--;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp)
        fclose(fp);
	return ret;
}

int mtg_store_record(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
    int i = 0;
    FILE* fp;
    if(mtg->backup==0)
        fp=fopen(mtg->dbpath,"a");

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        strcpy(cmd,"drop table segrecord_set");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        strcpy(cmd,"create table segrecord_set(\
                `id` int(11) NOT NULL AUTO_INCREMENT,\
                `segnum` int(11) DEFAULT NULL,\
                `segtype` int(11) DEFAULT NULL,\
                `location` int(11) DEFAULT NULL,\
                `mile` double DEFAULT NULL,\
                `offh` double DEFAULT NULL,\
                `offv` double DEFAULT NULL,\
                `t` int(11) DEFAULT NULL,\
                 PRIMARY KEY (`id`)\
                )");
        mysql_real_query(&mysql,cmd,strlen(cmd));
        if(fp)
            fprintf(fp,"%%R1P,74:4:%d\n",mtg->SegRecNum);
        for(i=0;i<mtg->SegRecNum;i++)
        {
            sprintf(cmd,
                "insert into segrecord_set(\
                segnum,segtype,location,mile,offh,offv,t) values(%d,%d,%d,%.12f,%.12f,%.12f,%ld)",
                mtg->segrecord[i].segnum,mtg->segrecord[i].segtype,mtg->segrecord[i].location,mtg->segrecord[i].mile,mtg->segrecord[i].offh,mtg->segrecord[i].offv,(long)mtg->segrecord[i].t);
            if(fp)
            fprintf(fp,"%%R1P,74:5:%d,%d,%d,%d,%.12f,%.12f,%.12f,%ld\n",i,mtg->segrecord[i].segnum,mtg->segrecord[i].segtype,mtg->segrecord[i].location,mtg->segrecord[i].mile,mtg->segrecord[i].offh,mtg->segrecord[i].offv,(long)mtg->segrecord[i].t);
            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
            {
                ret=1;
            }
        }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
	if(fp)
        fclose(fp);
	return ret;
}

///掘进报表
int mtg_add_duty(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
    int i=mtg->onduty;
    MTG_DUTY* duty;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

	duty=&mtg->duty[i];

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"insert into onduty \
             values(%d,%d,'%s',%d,%d,%.12f,%.12f,%ld,%ld,%.12f)",
             duty->id+1,i,duty->name,duty->seg1,duty->seg2,duty->mile1,duty->mile2,(long)duty->t1,(long)duty->t2,duty->mxdev);
        trace(0,"cmd=%s\n",cmd);
        if(fp)
        fprintf(fp,"%%R1P,5:0:%d,%d,'%s',%d,%d,%f,%f,%ld,%ld,%f\n",duty->id,i,duty->name,duty->seg1,duty->seg2,duty->mile1,duty->mile2,
                (long)duty->t1,(long)duty->t2,duty->mxdev);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    duty->id++;
		    ret=1;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
	if(fp) fclose(fp);
	return ret;
}

int mtg_edit_duty(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
    int i=mtg->onduty;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"update duty_set set onduty=%d,name='%s',seg1=%d,seg2=%d,l1=%.12f,\
             l2=%.12f,t1=%ld,t2=%ld,mxdv=%.12f where id=%d",
             i,mtg->duty[i].name,mtg->duty[i].seg1,mtg->duty[i].seg2,mtg->duty[i].mile1,mtg->duty[i].mile2,
             mtg->duty[i].t1,mtg->duty[i].t2,mtg->duty[i].mxdev,mtg->duty[i].id+1);
        trace(0,"cmd=%s\n",cmd);
        if(fp)
        fprintf(fp,"%%R1P,5:1:%d,%d,'%s',%d,%d,%f,%f,%ld,%ld,%f\n",i,mtg->duty[i].id,mtg->duty[i].name,mtg->duty[i].seg1,mtg->duty[i].seg2,mtg->duty[i].mile1,mtg->duty[i].mile2,
                (long)mtg->duty[i].t1,(long)mtg->duty[i].t2,mtg->duty[i].mxdev);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
	if(fp) fclose(fp);
	return ret;
}

///添加关键区域
int mtg_add_key(mtg_t* mtg,const MTG_KEY* a)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,
             "insert into key_set values(%d,'%s',%.12f,%0.12f)",
             mtg->nks+1,a->name,a->mile1,a->mile2);
        //fprintf(fp,"%s\n",cmd);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->nks++;
		    if(mtg->keys) mtg->keys=(MTG_KEY*)realloc(mtg->keys,mtg->nks*sizeof(MTG_KEY));
		    else mtg->keys=(MTG_KEY*)malloc(sizeof(MTG_KEY));
		    mtg->keys[mtg->nks-1]=*a;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
	//fclose(fp);
	return ret;
}

///编辑关键区域
int mtg_edit_key(mtg_t* mtg,int index,const MTG_KEY* a)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"update  key_set set name='%s',mile1=%.12f,mile2=%.12f where id=%d",a->name,a->mile1,a->mile2,index+1);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->keys[index]=*a;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	return ret;
}

///删除关键区域
int mtg_remove_key(mtg_t* mtg,int index)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;

    for(i=index;i<mtg->nks-1;i++)
    {
        mtg->keys[i]=mtg->keys[i+1];
    }
    mtg->nks--;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    strcpy(cmd,"drop table key_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table key_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `name` char(64) DEFAULT NULL,\
            `mile1` double DEFAULT 0.0,\
            `mile2` double DEFAULT 0.0,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
	    for(i=0;i<mtg->nks;i++)
	    {
	        sprintf(cmd,"insert into key_set values(%d,'%s',%.12f,%.12f)",
             i+1,mtg->keys[i].name,mtg->keys[i].mile1,mtg->keys[i].mile2);
            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
            {
                ret=1;
            }
	    }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	return ret;
}

///存储关键区域
int mtg_store_keys(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    strcpy(cmd,"drop table key_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table key_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `name` char(64) DEFAULT NULL,\
            `mile1` double DEFAULT 0.0,\
            `mile2` double DEFAULT 0.0,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		if(fp)
        fprintf(fp,"%%R1P,6:0:%d\n",mtg->nks);
	    for(i=0;i<mtg->nks;i++)
	    {
	        sprintf(cmd,
             "insert into key_set values(%d,'%s',%.12f,%.12f)",
             i+1,mtg->keys[i].name,mtg->keys[i].mile1,mtg->keys[i].mile2);
            if(fp)
            fprintf(fp,"%%R1P,6:1:%d,'%s',%f,%f\n",i,mtg->keys[i].name,mtg->keys[i].mile1,mtg->keys[i].mile2);
            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
            {
                ret=1;
            }
	    }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);
	return ret;
}

///添加管块
int mtg_add_block(mtg_t* mtg,const MTG_BLOCK* b)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,
             "insert into block_set values(%d,'%s',%.12f)",
             mtg->nblk+1,b->name,b->angle);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->nblk++;
		    if(mtg->blocks) mtg->blocks=(MTG_BLOCK*)realloc(mtg->blocks,mtg->nblk*sizeof(MTG_BLOCK));
		    else mtg->blocks=(MTG_BLOCK*)malloc(sizeof(MTG_BLOCK));
		    mtg->blocks[mtg->nblk-1]=*b;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
	return ret;
}

///删除管块
int mtg_remove_block(mtg_t* mtg,int index)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;

    for(i=index;i<mtg->nblk-1;i++)
    {
        mtg->blocks[i]=mtg->blocks[i+1];
    }
    mtg->nblk--;
    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    strcpy(cmd,"drop table block_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table block_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `name` char(64) DEFAULT NULL,\
            `angle` double DEFAULT 0.0,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
	    for(i=0;i<mtg->nblk;i++)
	    {
	        sprintf(cmd,
             "insert into block_set values(%d,'%s',%.12f)",
             i+1,mtg->blocks[i].name,mtg->blocks[i].angle);
            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
            {
                ret++;
            }
	    }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	return ret;
}

///存储管块
int mtg_store_block(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    strcpy(cmd,"drop table block_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table block_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `name` char(64) DEFAULT NULL,\
            `angle` double DEFAULT 0.0,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		if(fp) fprintf(fp,"%%R1P,7:0:%d\n",mtg->nblk);
	    for(i=0;i<mtg->nblk;i++)
	    {
	        sprintf(cmd,
             "insert into block_set values(%d,'%s',%.12f)",
             i+1,mtg->blocks[i].name,mtg->blocks[i].angle);
            if(fp)
            fprintf(fp,"%%R1P,7:1:%d,'%s',%f\n",i,mtg->blocks[i].name,mtg->blocks[i].angle);
            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
            {
                ret++;
            }
	    }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
    if(fp) fclose(fp);
	return ret;
}

///编辑管块参数
int mtg_modify_block(mtg_t* mtg,int index,const MTG_BLOCK* b)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"update  block_set set name='%s',angle=%.12f  where id=%d",b->name,b->angle,index+1);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->blocks[index]=*b;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	return ret;
}

///盾构设置
int mtg_store_tbmset(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
	MTG_TBM* tbm=0;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");


	tbm=&mtg->tbm;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{

        sprintf(cmd,"replace into tbm_set values(1,'%s',%d,%d,\
                %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,\
                %d,%.12f,%.12f,%.12f,%.12f,%d,\
                %d,%.12f,%.12f,%.12f,%.12f,%d)",
                tbm->name,tbm->type,tbm->mode,
                tbm->D[0],tbm->D[1],tbm->D[2],tbm->D[3],tbm->D[4],tbm->D[5],tbm->L[0],tbm->L[1],tbm->L[2],tbm->L[3],tbm->L[4],tbm->L[5],
                tbm->L[6],tbm->L[7],tbm->L[8],tbm->naj,tbm->aj[0],tbm->aj[1],tbm->aj[2],tbm->aj[3],tbm->aj[4],tbm->aj[5],tbm->aunit,
                tbm->nbj,tbm->bj[0],tbm->bj[1],tbm->bj[2],tbm->bj[3],tbm->bunit,
                tbm->nfj,tbm->fj[0],tbm->fj[1],tbm->fj[2],tbm->fj[3],tbm->funit
                );
        trace(0,cmd);
        if(fp)
        fprintf(fp,"%%R1P,8:0:'%s',%d,%d,\
                %f,%f,%f,%f,%f,%f,\
                %f,%f,%f,%f,%f,%f,%f,%f,%f,%d,%f,%f,%f,%f,%f,%f,%d,\
                %d,%f,%f,%f,%f,%d,\
                %d,%f,%f,%f,%f,%d\n",tbm->name,tbm->type,tbm->mode,
                tbm->D[0],tbm->D[1],tbm->D[2],tbm->D[3],tbm->D[4],tbm->D[5],tbm->L[0],tbm->L[1],tbm->L[2],tbm->L[3],tbm->L[4],tbm->L[5],
                tbm->L[6],tbm->L[7],tbm->L[8],tbm->naj,tbm->aj[0],tbm->aj[1],tbm->aj[2],tbm->aj[3],tbm->aj[4],tbm->aj[5],tbm->aunit,
                tbm->nbj,tbm->bj[0],tbm->bj[1],tbm->bj[2],tbm->bj[3],tbm->bunit,
                tbm->nfj,tbm->fj[0],tbm->fj[1],tbm->fj[2],tbm->fj[3],tbm->funit
                );
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            ret++;
        }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	//init_cam(mtg);
    if(fp) fclose(fp);
	return ret;
}

int mtg_store_comset(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;

	MTG_COM* cs=0;


    mtg->comset[0].id=1;
    strcpy(mtg->comset[0].ip,"192.168.0.201");
    mtg->comset[0].port=1000;

    mtg->comset[1].id=2;
    strcpy(mtg->comset[1].ip,"192.168.0.202");
    mtg->comset[1].port=1000;

    mtg->comset[2].id=3;
    strcpy(mtg->comset[2].ip,"192.168.0.203");
    mtg->comset[2].port=5300;

    mtg->comset[3].id=4;
    //strcpy(mtg->comset[3].ip,"192.168.0.204");
    strcpy(mtg->comset[3].ip,"192.168.0.204");
    mtg->comset[3].port=5300;

    cs=mtg->comset;
    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    strcpy(cmd,"drop table com_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table com_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `ip` char(16) DEFAULT NULL,\
            `port` int(11) DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));

	    for(i=0;i<6;i++)
        {
            sprintf(cmd,"insert into com_set values(%d,'%s',%d)",mtg->comset[i].id,mtg->comset[i].ip,mtg->comset[i].port);
            if(mysql_real_query(&mysql,cmd,strlen(cmd)))
            {
                ret++;
                break;
            }
            //fprintf(fp,"%d,%s\n",i,cmd);
        }
        if(i==6)
        {
            ret=1;
        }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
    //fclose(fp);
	return ret;
}

int mtg_store_camset(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
	MTG_CAM* cs=0;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

	cs=mtg->camset;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    for(i=0;i<2;i++)
        {
            sprintf(cmd,"replace into cam_set values(\
                    %d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                    %d,%d,%d,%d,'%s')",
                    i+1,cs[i].w,cs[i].h,cs[i].affine[0],cs[i].affine[1],cs[i].affine[2],
                    cs[i].affine[3],cs[i].affine[4],cs[i].affine[5],
                    cs[i].affine[6],cs[i].affine[7],cs[i].affine[8],
                    cs[i].x1,cs[i].y1,cs[i].x2,cs[i].y2,cs[i].name);
            trace(0,cmd);
            if(fp)
            fprintf(fp,"%%R1P,9:0:%d,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d,%d,%d,%d,'%s'\n",
                    i,cs[i].w,cs[i].h,cs[i].affine[0],cs[i].affine[1],cs[i].affine[2],
                    cs[i].affine[3],cs[i].affine[4],cs[i].affine[5],
                    cs[i].affine[6],cs[i].affine[7],cs[i].affine[8],
                    cs[i].x1,cs[i].y1,cs[i].x2,cs[i].y2,cs[i].name
                );
            if(mysql_real_query(&mysql,cmd,strlen(cmd)))
            {
                break;
            }
        }
        if(i==2)
        {
            ret=1;
        }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	//init_cam(mtg);
    if(fp) fclose(fp);
	return ret;
}

int mtg_store_mapset(mtg_t* mtg,int index)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;

	MTG_MAP* cs=0;

	cs=mtg->mapset;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        sprintf(cmd,"replace into map_set values(%d,%d,%d,%.12f,%.12f,%.12f,\
                %d,%d,%.12f,%.12f,%.12f,\
                %d,%d,%.12f,%.12f,%.12f,\
                %d,%d,%.12f,%.12f,%.12f,\
                %d,%d,%.12f,%.12f,%.12f,\
                %.12f,'%s')",
                index+1,cs[index].w[0],cs[index].h[0],cs[index].dx[0],cs[index].dy[0],cs[index].s[0],
                cs[index].w[1],cs[index].h[1],cs[index].dx[1],cs[index].dy[1],cs[index].s[1],
                cs[index].w[2],cs[index].h[2],cs[index].dx[2],cs[index].dy[2],cs[index].s[2],
                cs[index].w[3],cs[index].h[3],cs[index].dx[3],cs[index].dy[3],cs[index].s[3],
                cs[index].w[4],cs[index].h[4],cs[index].dx[4],cs[index].dy[4],cs[index].s[4],
                cs[index].beta,cs[index].name);
        //trace(0,cmd);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0) ret=1;
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
    //fclose(fp);
	//init_cam(mtg);
	return ret;
}

///激光靶参数
int mtg_store_tars(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[2024];
	int i;
	MTG_TARGET* ts=0;
    FILE* fp=0;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

	ts=&mtg->tarset;

    lock(&mtg->dblock);
	mysql_init(&mysql);

	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    strcpy(cmd,"drop table target_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		strcpy(cmd,"create table target_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `ver` int(11) DEFAULT NULL,\
            `prism1` double DEFAULT NULL,\
            `prism2` double DEFAULT NULL,\
            `prism3` double DEFAULT NULL,\
            `prism4` double DEFAULT NULL,\
            `prism5` double DEFAULT NULL,\
            `prism6` double DEFAULT NULL,\
            `prism7` double DEFAULT NULL,\
            `prism8` double DEFAULT NULL,\
            `prism9` double DEFAULT NULL,\
            `prism10` double DEFAULT NULL,\
            `prism11` double DEFAULT NULL,\
            `prism12` double DEFAULT NULL,\
            `prc` double DEFAULT NULL,\
            `length` double DEFAULT NULL,\
            `cam` int(11) DEFAULT NULL,\
            `inc` int(11) DEFAULT NULL,\
            `pposition` int(11) DEFAULT NULL,\
            `tposition` int(11) DEFAULT NULL,\
            `incdb` int(11) DEFAULT NULL,\
            `ctsalw` int(11) DEFAULT NULL,\
            `dtsalw` int(11) DEFAULT NULL,\
            `stpd` int(11) DEFAULT NULL,\
            `angalw` double DEFAULT NULL,\
            PRIMARY KEY (`id`)\
            )");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            sprintf(cmd,"insert into target_set values(%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                    %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%d,%d,%d,\
                    %d,%d,%d,%d,%.12f)",
                    1,ts->ver,ts->prism[0],ts->prism[1],ts->prism[2],ts->prism[3],ts->prism[4],ts->prism[5],
                    ts->prism[6],ts->prism[7],ts->prism[8],ts->prism[9],ts->prism[10],ts->prism[11],ts->prc,ts->length,ts->cam,ts->inc,ts->ipos,ts->pos,
                    ts->incdb,ts->ctsalw,ts->dtsalw,ts->stopped,ts->angalw);
            trace(0,cmd);
            if(fp)
            {
                fprintf(fp,"%s\n",cmd);
                fprintf(fp,"%%R1P,10:0:%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d,%d,%d,%d,%d,%d,%d,%d,%.12f\n",
                    ts->ver,ts->prism[0],ts->prism[1],ts->prism[2],ts->prism[3],ts->prism[4],ts->prism[5],
                    ts->prism[6],ts->prism[7],ts->prism[8],ts->prc,ts->length,ts->cam,ts->inc,ts->ipos,ts->pos,
                    ts->incdb,ts->ctsalw,ts->dtsalw,ts->stopped,ts->angalw);
            }
            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0) ret=1;
        }
        if(fp)
        {
            fprintf(fp,"ret:%d\n",ret);fflush(fp);
        }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
    if(fp) fclose(fp);
	return ret;
}

///全站仪
int mtg_store_tps(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

    lock(&mtg->dblock);
	mysql_init(&mysql);

	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        sprintf(cmd,"replace into tps_set values(%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%d,%d)",
                1,mtg->tps.type,mtg->tps.lasertype,mtg->tps.laserheight,mtg->tps.laserdist[0],mtg->tps.laserdist[1],
                mtg->tps.laserx[0],mtg->tps.lasery[0],mtg->tps.laserx[1],mtg->tps.lasery[1],mtg->tps.edm,mtg->tps.comp);
        trace(0,cmd);
        if(fp)
        fprintf(fp,"%%R1P,11:0:%d,%d,%f,%f,%f,%f,%f,%f,%f,%d,%d\n",
                mtg->tps.type,mtg->tps.lasertype,mtg->tps.laserheight,mtg->tps.laserdist[0],mtg->tps.laserdist[1],
                mtg->tps.laserx[0],mtg->tps.lasery[0],mtg->tps.laserx[1],mtg->tps.lasery[1],mtg->tps.edm,mtg->tps.comp);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0) ret=1;
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);
	return ret;
}

///设计排版初始管环
int mtg_store_seging(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");
    lock(&mtg->dblock);
	mysql_init(&mysql);

	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
    {
        sprintf(cmd,"replace into seging_set values(1,%d,%d,%d,%.12f,%d,%d,%d,%ld)",
                mtg->iseg.numb,mtg->iseg.type,mtg->iseg.k,mtg->iseg.headc,mtg->sneed[0],
                mtg->sneed[1],mtg->sneed[2],mtg->iseg.t
                );
        trace(0,cmd);
        if(fp)
        fprintf(fp,"%%R1P,12:0:%d,%d,%d,%f,%d,%d,%d,%ld\n",
                mtg->iseg.numb,mtg->iseg.type,mtg->iseg.k,mtg->iseg.headc,mtg->sneed[0],
                mtg->sneed[1],mtg->sneed[2],mtg->iseg.t);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0) ret=1;
    }
    mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);
	return ret;
}

///管环设置
int mtg_store_segset(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

    lock(&mtg->dblock);
	mysql_init(&mysql);

	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        sprintf(cmd,"replace into segment_set values(1,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%d,%.12f,%.12f,%d)",
                mtg->segset.type,mtg->segset.in,mtg->segset.f2b,mtg->segset.l2s,
                mtg->segset.L,mtg->segset.De,mtg->segset.D,mtg->segset.Ks,mtg->segset.G0,mtg->segset.G1,mtg->segset.s2s);
        trace(0,cmd);
        if(fp)
        fprintf(fp,"%%R1P,13:0:%d,%d,%d,%f,%f,%f,%f,%d,%f,%f,%d\n",
                mtg->segset.type,mtg->segset.in,mtg->segset.f2b,mtg->segset.l2s,
                mtg->segset.L,mtg->segset.De,mtg->segset.D,mtg->segset.Ks,mtg->segset.G0,mtg->segset.G1,mtg->segset.s2s);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0) ret=1;
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);
	return ret;
}

int mtg_store_sets(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
	MTG_SETS* ms=0;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");


	ms=&mtg->iset;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        sprintf(cmd,"replace into config_set values(1,%d,%d,%d,%d,%d,%d,%d,\
                %d,%d,%d,%d,%d,%d,%d,%d,\
                %d,%d,%d,%d,%d,%d,%d,%d,%d,\
                %d,%d,%d,%d,%d,%.12f,%.12f,%d,%d,%d,%d,\
                %d,%.12f,%d)",
                ms->cyc,ms->bcyc,ms->palw,ms->jalw,ms->balw,ms->talw,ms->vibration,
                ms->rstn,ms->tsyn,ms->rget,ms->idrv,ms->prun,ms->pend,ms->psas,ms->pchk,
                ms->pqry,ms->pmap,ms->psmr,ms->pquit,ms->unit,ms->vmileage,ms->head,ms->tbm3d,ms->trend,
                ms->povr,ms->jovr,ms->bovr,ms->tovr,ms->toEr,ms->flen,ms->fdev,ms->tgap,ms->lang,ms->symtype,ms->backflag,
                ms->plctype,ms->aalw,ms->tailapply);
        if(fp)
        {
            fprintf(fp,"%s\n",cmd);
            fflush(fp);
        }
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            ret=1;
        }
        trace(0,"cmd=%s\n",cmd);
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);
	return ret;
}

int mtg_store_prj(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	int i;
    MTG_PRJ* p=0;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

	p=&mtg->prj;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        sprintf(cmd,"replace into prj_set values(1,'%s',%.12f,%.12f,%d,%d,\
                '%s','%s','%s','%s',%d,%d,%.12f)",
                p->name,p->mile1,p->mile2,p->a2z,mtg->ndty,mtg->duty[0].name,mtg->duty[1].name,
                mtg->duty[2].name,mtg->duty[3].name,p->htip,p->vtip,p->tip);
        if(fp)
        fprintf(fp,"%%R1P,15:0:'%s',%f,%f,%d,%d,'%s','%s','%s','%s',%d,%d,%f\n",
                p->name,p->mile1,p->mile2,p->a2z,mtg->ndty,mtg->duty[0].name,mtg->duty[1].name,
                mtg->duty[2].name,mtg->duty[3].name,p->htip,p->vtip,p->tip);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            ret=1;
        }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);
	return ret;
}

int mtg_store_smonitor(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[2048];
	MTG_SEGMONITOR* sm;
	FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

	sm=&mtg->smonitor;
	lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"insert into smonitor_set(\
             number,monitor,cycle,last,iseg,headc,x,y,z,x1,y1,z1,t,dv,dv1) values(\
             %d,%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%ld,%.12f,%.12f)",
             sm->number,sm->monitor,sm->cycle,sm->last,sm->iseg,sm->headc,sm->x0,sm->y0,sm->z0,
             sm->x,sm->y,sm->z,(long)sm->t,sm->dv,sm->dv1
             );
		if(fp)
        fprintf(fp,"%%R1P,16:0:%d,%d,%d,%d,%d,%f,%f,%f,%f,%ld,%f,%f\n",
            sm->number,sm->monitor,sm->cycle,sm->last,sm->iseg,sm->headc,sm->x0,sm->y0,sm->z0,
            sm->x,sm->y,sm->z,(long)sm->t,sm->dv,sm->dv1);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		}
	}

	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);
	return ret;
}

void check(double *val)
{
	double valid=1.0E+15;
    if(fabs(*val)>valid)
        *val=-100000;
}

void check_int(int* val)
{
    int valid=10000;
    if(abs(*val)>valid)
        *val=-10000;
}

int mtg_store_meas(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[3036];
	MTG_MEASURE* m;
	FILE* fp=NULL;
	MYSQL_RES* results;
	int cols=0;

    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

	m=&mtg->m;

    check(&m->inc[0]);
    check(&m->inc[1]);
    check(&m->inc[2]);
    check(&m->inc[3]);

    check(&m->cam[0]);
    check(&m->cam[1]);
    check(&m->cam[2]);
    check(&m->cam[3]);

    check(&m->prism[0]);
    check(&m->prism[1]);
    check(&m->prism[2]);

    check(&m->angle[0]);
    check(&m->angle[1]);

    check(&m->comp[0]);
    check(&m->comp[1]);

    check(&m->head[0]);
    check(&m->head[1]);
    check(&m->head[2]);

    check(&m->hdes[0]);
    check(&m->hdes[1]);
    check(&m->hdes[2]);

    check(&m->headc);
    check(&m->headh);
    check(&m->headv);

    check(&m->tail[0]);
    check(&m->tail[1]);
    check(&m->tail[2]);

    check(&m->tdes[0]);
    check(&m->tdes[1]);
    check(&m->tdes[2]);

    check(&m->tailc);
    check(&m->tailh);
    check(&m->tailv);

    check(&m->mile1);
    check(&m->hdev1);
    check(&m->vdev1);

    check(&m->mile2);
    check(&m->hdev2);
    check(&m->vdev2);

    check(&m->mile3);
    check(&m->hdev3);
    check(&m->vdev3);

    check(&m->faj[0]);
    check(&m->faj[1]);
    check(&m->faj[2]);
    check(&m->faj[3]);

    check(&m->baj[0]);
    check(&m->baj[1]);
    check(&m->baj[2]);
    check(&m->baj[3]);

    check(&m->aj[0]);
    check(&m->aj[1]);
    check(&m->aj[2]);
    check(&m->aj[3]);

    check(&m->inc1[0]);
    check(&m->inc1[1]);
    check(&m->inc1[2]);

    check(&m->inc4[0]);
    check(&m->inc4[1]);

    //trace(0,"iseg:%d\n",m->iseg);
    check_int(&m->iseg);
    check_int(&m->iset);

    //trace(0,"Database: save data\n");
    lock(&mtg->dblock);
	mysql_init(&mysql);
	//trace(0,"Database:error=%s\n",mysql_error(&mysql));
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"select * from measure_set order by id desc limit 1");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            results=mysql_store_result(&mysql);
            cols=mysql_num_fields(results);
            if(cols==63)
            {
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `headtail1` double DEFAULT 0 AFTER `iset`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `headtail2` double DEFAULT 0 AFTER `headtail1`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `headtail3` double DEFAULT 0 AFTER `headtail2`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `headtaildes1` double DEFAULT 0 AFTER `headtail3`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `headtaildes2` double DEFAULT 0 AFTER `headtaildes1`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `headtaildes3` double DEFAULT 0 AFTER `headtaildes2`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `t5` int(11) DEFAULT 0 AFTER `headtaildes3`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `inc12` double DEFAULT 0 AFTER `t5`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `inc22` double DEFAULT 0 AFTER `inc12`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
            }
            else if(cols==69)
            {
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `t5` int(11) DEFAULT 0 AFTER `headtaildes3`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `inc12` double DEFAULT 0 AFTER `t5`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `inc22` double DEFAULT 0 AFTER `inc12`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
            }
            else if(cols==72)
            {
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `inc41` double DEFAULT 0 AFTER `inc22`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                strcpy(cmd,"ALTER TABLE `measure_set` ADD COLUMN `inc42` double DEFAULT 0 AFTER `inc41`;");
                mysql_real_query(&mysql,cmd,strlen(cmd));
            }
            sprintf(cmd,"insert into measure_set(\
                 inc1,inc2,inc3,inc4,cam1,cam2,cam3,cam4,prism1,prism2,prism3,\
                 angle1,angle2,comp1,comp2,head1,head2,head3,hdes1,hdes2,hdes3,headc,headh,headv,\
                 tail1,tail2,tail3,tdes1,tdes2,tdes3,tailc,tailh,tailv,mile1,hdev1,vdev1,mile2,hdev2,vdev2,mile3,hdev3,vdev3,\
                 faj1,faj2,faj3,faj4,baj1,baj2,baj3,baj4,aj1,aj2,aj3,aj4,\
                 roll,pitch,azimuth,iseg,t1,t2,t3,iset,\
                 headtail1,headtail2,headtail3,headtaildes1,headtaildes2,headtaildes3,\
                    t5,inc12,inc22,inc41,inc42) values(\
                 %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                 %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                 %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                 %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                 %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                 %.12f,%.12f,%.12f,%d,%ld,%ld,%ld,%d,\
                 %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                    %ld,%.12f,%.12f,%.12f,%.12f)",
                 m->inc[0],m->inc[1],m->inc[2],m->inc[3],m->cam[0],m->cam[1],m->cam[2],m->cam[3],m->prism[0],m->prism[1],m->prism[2],
                 m->angle[0],m->angle[1],m->comp[0],m->comp[1],m->head[0],m->head[1],m->head[2],m->hdes[0],m->hdes[1],m->hdes[2],
                 m->headc,m->headh,m->headv,m->tail[0],m->tail[1],m->tail[2],m->tdes[0],m->tdes[1],m->tdes[2],
                 m->tailc,m->tailh,m->tailv,m->mile1,m->hdev1,m->vdev1,m->mile2,m->hdev2,m->vdev2,m->mile3,m->hdev3,m->vdev3,
                 m->faj[0],m->faj[1],m->faj[2],m->faj[3],m->baj[0],m->baj[1],m->baj[2],m->baj[3],m->aj[0],m->aj[1],m->aj[2],m->aj[3],
                 m->inc1[0],m->inc1[1],m->inc1[2],m->iseg,(long)m->t1,(long)m->t2,(long)m->t3,m->iset,
                 m->ht[0],m->ht[1],m->ht[2],m->htdes[0],m->htdes[1],m->htdes[2],
                 (long)m->t5,m->inc[5],m->inc[6],m->inc4[0],m->inc4[1]
                 );
            trace(0,"mtg_store_meas: %s\n",cmd);
            if(fp)
            fprintf(fp,"%%R1P,17:0:%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
                 %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
                 %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
                 %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
                 %f,%f,%f,%d,%ld,%ld,%ld,%d,\
                 %f,%f,%f,%f,%f,%f,\
                    %ld,%f,%f\n",
                 m->inc[0],m->inc[1],m->inc[2],m->inc[3],m->cam[0],m->cam[1],m->cam[2],m->cam[3],m->prism[0],m->prism[1],m->prism[2],
                 m->angle[0],m->angle[1],m->comp[0],m->comp[1],m->head[0],m->head[1],m->head[2],m->hdes[0],m->hdes[1],m->hdes[2],m->headc,m->headh,m->headv,
                 m->tail[0],m->tail[1],m->tail[2],m->tdes[0],m->tdes[1],m->tdes[2],m->tailc,m->tailh,m->tailv,
                 m->mile1,m->hdev1,m->vdev1,m->mile2,m->hdev2,m->vdev2,m->mile3,m->hdev3,m->vdev3,m->faj[0],m->faj[1],m->faj[2],m->faj[3],
                 m->baj[0],m->baj[1],m->baj[2],m->baj[3],m->aj[0],m->aj[1],m->aj[2],m->aj[3],
                 m->inc1[0],m->inc1[1],m->inc1[2],m->iseg,(long)m->t1,(long)m->t2,(long)m->t3,m->iset,
                 m->ht[0],m->ht[1],m->ht[2],m->htdes[0],m->htdes[1],m->htdes[2],
                 m->t5,m->inc[5],m->inc[6]);
            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
            {
                ret=1;
                mtg->m1=*m;
                trace(0,"store_meas:%d\n",ret);
            }
        }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp)
    {
        fclose(fp);
        fp=NULL;
    }
	return ret;
}

///管环数据
int mtg_store_seg(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[2048];
	int i=0;
	FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");
	lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    time(&mtg->segs[11].t);
	    sprintf(cmd,"insert into seged_set(\
             numb,type,k,mode,hpz,vpz,x,y,z,x1,y1,z1,ori,phi,ori1,phi1,mile,dh,dv,dh1,dv1,headx,\
             heady,headz,headc,headh,headv,tailx,taily,tailz,tailc,tailh,tailv,tbmh,tbmv,desh,desv,\
             ugap,dgap,lgap,rgap,uaj,daj,laj,raj,ufaj,dfaj,lfaj,rfaj,ubaj,dbaj,lbaj,rbaj,harc,varc,t) \
             values(%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%ld)",
             mtg->segs[11].numb,mtg->segs[11].type,mtg->segs[11].k,mtg->segs[11].mode,mtg->segs[11].hpz,mtg->segs[11].vpz,
             mtg->segs[11].x,mtg->segs[11].y,mtg->segs[11].z,mtg->segs[11].x1,mtg->segs[11].y1,mtg->segs[11].z1,
             mtg->segs[11].ori,mtg->segs[11].phi,mtg->segs[11].ori1,mtg->segs[11].phi1,mtg->segs[11].mile,
             mtg->segs[11].dh,mtg->segs[11].dv,mtg->segs[11].dh1,mtg->segs[11].dv1,mtg->segs[11].head[0],mtg->segs[11].head[1],mtg->segs[11].head[2],
             mtg->segs[11].headc,mtg->segs[11].headh,mtg->segs[11].headv,mtg->segs[11].tail[0],mtg->segs[11].tail[1],mtg->segs[11].tail[2],
             mtg->segs[11].tailc,mtg->segs[11].tailh,mtg->segs[11].tailv,mtg->segs[11].tbmv,mtg->segs[11].tbmh,mtg->segs[11].desh,mtg->segs[11].desv,
             mtg->segs[11].gap[0],mtg->segs[11].gap[1],mtg->segs[11].gap[2],mtg->segs[11].gap[3],mtg->segs[11].aj[0],mtg->segs[11].aj[1],
             mtg->segs[11].aj[2],mtg->segs[11].aj[3],mtg->segs[11].faj[0],mtg->segs[11].faj[1],mtg->segs[11].faj[2],mtg->segs[11].faj[3],
             mtg->segs[11].baj[0],mtg->segs[11].baj[1],mtg->segs[11].baj[2],mtg->segs[11].baj[3],mtg->segs[11].harc,mtg->segs[11].varc,
             mtg->segs[11].t);
             //trace(0,"cmd:%s\n",cmd);
        if(fp)
        fprintf(fp,"%%R1P,18:0:%d,%d,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,\
             %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
             %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
             %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%ld\n",
             mtg->segs[11].numb,mtg->segs[11].type,mtg->segs[11].k,mtg->segs[11].mode,mtg->segs[11].hpz,mtg->segs[11].vpz,
             mtg->segs[11].x,mtg->segs[11].y,mtg->segs[11].z,mtg->segs[11].x1,mtg->segs[11].y1,mtg->segs[11].z1,
             mtg->segs[11].ori,mtg->segs[11].phi,mtg->segs[11].ori1,mtg->segs[11].phi1,mtg->segs[11].mile,
             mtg->segs[11].dh,mtg->segs[11].dv,mtg->segs[11].dh1,mtg->segs[11].dv1,mtg->segs[11].head[0],mtg->segs[11].head[1],mtg->segs[11].head[2],
             mtg->segs[11].headc,mtg->segs[11].headh,mtg->segs[11].headv,mtg->segs[11].tail[0],mtg->segs[11].tail[1],mtg->segs[11].tail[2],
             mtg->segs[11].tailc,mtg->segs[11].tailh,mtg->segs[11].tailv,mtg->segs[11].tbmv,mtg->segs[11].tbmh,mtg->segs[11].desh,mtg->segs[11].desv,
             mtg->segs[11].gap[0],mtg->segs[11].gap[1],mtg->segs[11].gap[2],mtg->segs[11].gap[3],mtg->segs[11].aj[0],mtg->segs[11].aj[1],
             mtg->segs[11].aj[2],mtg->segs[11].aj[3],mtg->segs[11].faj[0],mtg->segs[11].faj[1],mtg->segs[11].faj[2],mtg->segs[11].faj[3],
             mtg->segs[11].baj[0],mtg->segs[11].baj[1],mtg->segs[11].baj[2],mtg->segs[11].baj[3],mtg->segs[11].harc,mtg->segs[11].varc,
             mtg->segs[11].t);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    for(i=0;i<MAX_SEG-1;i++)
            {
                mtg->segs[i]=mtg->segs[i+1];
            }
            mtg->segs[MAX_SEG-1].numb++;
		}
		//trace(0,"store seg:%d\n",ret);
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
	if(fp) fclose(fp);
	return ret;
}
///管环数据
int mtg_store_segs(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[4096];
    int i;
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    strcpy(cmd,"drop table segs_set");
		mysql_real_query(&mysql,cmd,strlen(cmd));

		strcpy(cmd,"create table segs_set(\
            `id` int(11) NOT NULL AUTO_INCREMENT,\
            `numb` int(11) DEFAULT NULL,\
            `type` int(11) DEFAULT NULL,\
            `k` int(11) DEFAULT NULL,\
            `mode` int(11) DEFAULT NULL,\
            `hpz` double default null,\
            `vpz` double default null,\
            `x` double default null,\
            `y` double default null,\
            `z` double default null,\
            `x1` double default null,\
            `y1` double default null,\
            `z1` double default null,\
            `ori` double default null,\
            `phi` double default null,\
            `ori1` double default null,\
            `phi1` double default null,\
            `mile` double default null,\
            `dh` double default null,\
            `dv` double default null,\
            `dh1` double default null,\
            `dv1` double default null,\
            `headx` double default null,\
            `heady` double default null,\
            `headz` double default null,\
            `headc` double default null,\
            `headh` double default null,\
            `headv` double default null,\
            `tailx` double default null,\
            `taily` double default null,\
            `tailz` double default null,\
            `tailc` double default null,\
            `tailh` double default null,\
            `tailv` double default null,\
            `tbmh` double default null,\
            `tbmv` double default null,\
            `desh` double default null,\
            `desv` double default null,\
            `ugap` double default null,\
            `dgap` double default null,\
            `lgap` double default null,\
            `rgap` double default null,\
            `uaj` double default null,\
            `daj` double default null,\
            `laj` double default null,\
            `raj` double default null,\
            `ufaj` double default null,\
            `dfaj` double default null,\
            `lfaj` double default null,\
            `rfaj` double default null,\
            `ubaj` double default null,\
            `dbaj` double default null,\
            `lbaj` double default null,\
            `rbaj` double default null,\
            `harc` double default null,\
            `varc` double default null,\
            `t` int(11) default null,\
             PRIMARY KEY (`id`)\
            )");
		mysql_real_query(&mysql,cmd,strlen(cmd));
		trace(0,"cmd:%s\n",cmd);
	    for(i=0;i<MAX_SEG;i++)
        {
            sprintf(cmd,
                 "insert into segs_set(\
                 numb,type,k,mode,hpz,vpz,x,y,z,x1,y1,z1,ori,phi,ori1,phi1,mile,dh,dv,dh1,dv1,headx,\
                 heady,headz,headc,headh,headv,tailx,taily,tailz,tailc,tailh,tailv,tbmh,tbmv,desh,desv,\
                 ugap,dgap,lgap,rgap,uaj,daj,laj,raj,ufaj,dfaj,lfaj,rfaj,ubaj,dbaj,lbaj,rbaj,harc,varc,t) \
                 values(%d,%d,%d,%d,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                 %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                 %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
                 %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%ld)",
                 mtg->segs[i].numb,mtg->segs[i].type,mtg->segs[i].k,mtg->segs[i].mode,mtg->segs[i].hpz,mtg->segs[i].vpz,
                 mtg->segs[i].x,mtg->segs[i].y,mtg->segs[i].z,mtg->segs[i].x1,mtg->segs[i].y1,mtg->segs[i].z1,
                 mtg->segs[i].ori,mtg->segs[i].phi,mtg->segs[i].ori1,mtg->segs[i].phi1,mtg->segs[i].mile,
                 mtg->segs[i].dh,mtg->segs[i].dv,mtg->segs[i].dh1,mtg->segs[i].dv1,mtg->segs[i].head[0],mtg->segs[i].head[1],mtg->segs[i].head[2],
                 mtg->segs[i].headc,mtg->segs[i].headh,mtg->segs[i].headv,mtg->segs[i].tail[0],mtg->segs[i].tail[1],mtg->segs[i].tail[2],
                 mtg->segs[i].tailc,mtg->segs[i].tailh,mtg->segs[i].tailv,mtg->segs[i].tbmv,mtg->segs[i].tbmh,mtg->segs[i].desh,mtg->segs[i].desv,
                 mtg->segs[i].gap[0],mtg->segs[i].gap[1],mtg->segs[i].gap[2],mtg->segs[i].gap[3],mtg->segs[i].aj[0],mtg->segs[i].aj[1],
                 mtg->segs[i].aj[2],mtg->segs[i].aj[3],mtg->segs[i].faj[0],mtg->segs[i].faj[1],mtg->segs[i].faj[2],mtg->segs[i].faj[3],
                 mtg->segs[i].baj[0],mtg->segs[i].baj[1],mtg->segs[i].baj[2],mtg->segs[i].baj[3],mtg->segs[i].harc,mtg->segs[i].varc,
                 mtg->segs[i].t);
            if(fp)
            fprintf(fp,"%%R1P,19:0:%d,%d,%d,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,\
                 %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
                 %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
                 %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%ld\n",
                 i,mtg->segs[i].numb,mtg->segs[i].type,mtg->segs[i].k,mtg->segs[i].mode,mtg->segs[i].hpz,mtg->segs[i].vpz,
                 mtg->segs[i].x,mtg->segs[i].y,mtg->segs[i].z,mtg->segs[i].x1,mtg->segs[i].y1,mtg->segs[i].z1,
                 mtg->segs[i].ori,mtg->segs[i].phi,mtg->segs[i].ori1,mtg->segs[i].phi1,mtg->segs[i].mile,
                 mtg->segs[i].dh,mtg->segs[i].dv,mtg->segs[i].dh1,mtg->segs[i].dv1,mtg->segs[i].head[0],mtg->segs[i].head[1],mtg->segs[i].head[2],
                 mtg->segs[i].headc,mtg->segs[i].headh,mtg->segs[i].headv,mtg->segs[i].tail[0],mtg->segs[i].tail[1],mtg->segs[i].tail[2],
                 mtg->segs[i].tailc,mtg->segs[i].tailh,mtg->segs[i].tailv,mtg->segs[i].tbmv,mtg->segs[i].tbmh,mtg->segs[i].desh,mtg->segs[i].desv,
                 mtg->segs[i].gap[0],mtg->segs[i].gap[1],mtg->segs[i].gap[2],mtg->segs[i].gap[3],mtg->segs[i].aj[0],mtg->segs[i].aj[1],
                 mtg->segs[i].aj[2],mtg->segs[i].aj[3],mtg->segs[i].faj[0],mtg->segs[i].faj[1],mtg->segs[i].faj[2],mtg->segs[i].faj[3],
                 mtg->segs[i].baj[0],mtg->segs[i].baj[1],mtg->segs[i].baj[2],mtg->segs[i].baj[3],mtg->segs[i].harc,mtg->segs[i].varc,
                 mtg->segs[i].t);
            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
            {
                ret++;
            }
        }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
	if(fp) fclose(fp);
	return ret;
}

int mtg_store_origin(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[2048];
	MTG_MEASURE* m;
    FILE* fp;
    int cols=0;
    MYSQL_RES *results;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

	m=&mtg->m0;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        strcpy(cmd,"select * from given_set order by id desc");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            results = mysql_store_result(&mysql);
            cols=mysql_num_fields(results);
            if(cols==49)
            {
                sprintf(cmd,"alter table given_set add ipos int unsigned not Null");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));

                sprintf(cmd,"alter table given_set add t4 int unsigned not Null");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                sprintf(cmd,"alter table given_set add t5 int unsigned not Null");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                sprintf(cmd,"alter table given_set add inc12 double default 0");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                sprintf(cmd,"alter table given_set add inc22 double default 0");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
            }
            else if(cols==50)
            {
                sprintf(cmd,"alter table given_set add t4 int unsigned not Null");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                sprintf(cmd,"alter table given_set add t5 int unsigned not Null");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                sprintf(cmd,"alter table given_set add inc12 double default 0");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                sprintf(cmd,"alter table given_set add inc22 double default 0");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
            }
            else if(cols==51)
            {
                sprintf(cmd,"alter table given_set add t5 int unsigned not Null");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                sprintf(cmd,"alter table given_set add inc12 double default 0");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                sprintf(cmd,"alter table given_set add inc22 double default 0");
                //trcpy(cmd,"ALTER TABLE `given_set` ADD COLUMN `ipos` double NULL DEFAULT '0' AFTER `t3`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
            }
        }
	    sprintf(cmd,"insert into given_set(\
             inc1,inc2,inc3,inc4,cam1,cam2,cam3,cam4,prism1,prism2,prism3,\
             angle1,angle2,comp1,comp2,head1,head2,head3,tail1,tail2,tail3,faj1,faj2,faj3,faj4,\
             baj1,baj2,baj3,baj4,aj1,aj2,aj3,aj4,roll,pitch,azimuth,mppsm1,mppsm2,mppsm3,mppsm4,\
             mppsm5,mppsm6,mppsm7,mppsm8,mppsm9,t1,t2,t3,ipos,t4,\
             t5,inc12,inc22) values(\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%ld,%ld,%ld,%d,%ld,\
             %ld,%.12f,%.12f)",
             m->inc[0],m->inc[1],m->inc[2],m->inc[3],m->cam[0],m->cam[1],m->cam[2],m->cam[3],
             m->prism[0],m->prism[1],m->prism[2],m->angle[0],m->angle[1],m->comp[0],m->comp[1],
             m->head[0],m->head[1],m->head[2],m->tail[0],m->tail[1],m->tail[2],m->faj[0],
             m->faj[1],m->faj[2],m->faj[3],m->baj[0],m->baj[1],m->baj[2],m->baj[3],
             m->aj[0],m->aj[1],m->aj[2],m->aj[3],m->inc1[0],m->inc1[1],m->inc1[2],
             mtg->mp.prism[0],mtg->mp.prism[1],mtg->mp.prism[2],mtg->mp.prism[3],
             mtg->mp.prism[4],mtg->mp.prism[5],mtg->mp.prism[6],mtg->mp.prism[7],
             mtg->mp.prism[8],(long)m->t1,(long)m->t2,(long)m->t3,m->ipos,(long)m->t4,
             (long)m->t5,m->inc[5],m->inc[6]
             );

        trace(0,"Database: %s\n",cmd);
        if(fp)
        fprintf(fp,"%%R1P,20:0:%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
             %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
             %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
             %f,%f,%f,%f,%f,%ld,%ld,%ld,%d,%ld,\
             %ld,%.12f,%.12f\n",
             m->inc[0],m->inc[1],m->inc[2],m->inc[3],m->cam[0],m->cam[1],m->cam[2],m->cam[3],
             m->prism[0],m->prism[1],m->prism[2],m->angle[0],m->angle[1],m->comp[0],m->comp[1],
             m->head[0],m->head[1],m->head[2],m->tail[0],m->tail[1],m->tail[2],m->faj[0],
             m->faj[1],m->faj[2],m->faj[3],m->baj[0],m->baj[1],m->baj[2],m->baj[3],
             m->aj[0],m->aj[1],m->aj[2],m->aj[3],m->inc1[0],m->inc1[1],m->inc1[2],
             mtg->mp.prism[0],mtg->mp.prism[1],mtg->mp.prism[2],mtg->mp.prism[3],
             mtg->mp.prism[4],mtg->mp.prism[5],mtg->mp.prism[6],mtg->mp.prism[7],
             mtg->mp.prism[8],(long)m->t1,(long)m->t2,(long)m->t3,m->ipos,(long)m->t4,
            (long)m->t5,m->inc[5],m->inc[6]);

		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		    mtg->m0=*m;
		    mtg->m1.t3=m->t3;
		    mtg->m1.prism[0] = m->prism[0];
		    mtg->m1.prism[1] = m->prism[1];
		    mtg->m1.prism[2] = m->prism[2];

		    mtg->mp.prism[9]=mtg->mp.prism[0];
            mtg->mp.prism[10]=mtg->mp.prism[1];
            mtg->mp.prism[11]=mtg->mp.prism[2];
            mtg->mp.prism[12]=mtg->mp.prism[3];
            mtg->mp.prism[13]=mtg->mp.prism[4];
            mtg->mp.prism[14]=mtg->mp.prism[5];
            mtg->mp.prism[15]=mtg->mp.prism[6];
            mtg->mp.prism[16]=mtg->mp.prism[7];
            mtg->mp.prism[17]=mtg->mp.prism[8];
            mtg_cal_origin(mtg);
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
    if(fp) fclose(fp);
	return ret;
}

extern LIBMTG_API int mtg_store_station(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[1024];
	MTG_STATION *s;
    FILE* fp;
    int cols=0;
    MYSQL_RES *results;

    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

	s=&mtg->istn;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    strcpy(cmd,"select * from station_set order by id desc limit 1");
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    cols=mysql_num_fields(results);
            if(cols==29)
            {
                strcpy(cmd,"ALTER TABLE `station_set` ADD COLUMN `anglediff` double NULL DEFAULT '0' AFTER `t`");
                mysql_real_query(&mysql,cmd,strlen(cmd));
                //strcpy(cmd,"ALTER TABLE `station_set` CHANGE COLUMN `anglediff` `anglediff` DOUBLE NULL DEFAULT NULL AFTER `roll2`;");
                //mysql_real_query(&mysql,cmd,strlen(cmd));
            }
            mysql_free_result(results);
		}
		check(&s->statx);
		check(&s->staty);
		check(&s->statz);
		check(&s->stath);
		check(&s->backx);
		check(&s->backy);
		check(&s->backz);
		check(&s->backh);
		check(&s->backx1);
		check(&s->backy1);
		check(&s->backz1);

		check(&s->headh[0]);
		check(&s->headh[1]);
		check(&s->tailh[0]);
		check(&s->tailh[1]);
		check(&s->headv[0]);
		check(&s->headv[1]);
		check(&s->tailv[0]);
		check(&s->tailv[1]);
		check(&s->azi[0]);
		check(&s->azi[1]);
		check(&s->pitch[0]);
		check(&s->pitch[1]);
		check(&s->roll[0]);
		check(&s->roll[1]);
		check(&s->anglediff);

	    sprintf(cmd,"insert into station_set \
             values(%d,'%s','%s',\
             %.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%ld,%.12f)",
             s->id+1,s->stat,s->back,
             s->statx,s->staty,s->statz,s->stath,
             s->backx,s->backy,s->backz,s->backh,
             s->backx1,s->backy1,s->backz1,
             s->headh[0],s->headh[1],s->tailh[0],s->tailh[1],
             s->headv[0],s->headv[1],s->tailv[0],s->tailv[1],
             s->azi[0],s->azi[1],s->pitch[0],s->pitch[1],
             s->roll[0],s->roll[0],(long)s->t,s->anglediff);

		if(fp)
        fprintf(fp,"%%R1P,21:0:%d,'%s','%s',%f,%f,%f,%f,%f,%f,%f,%f,\
             %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
             %f,%f,%ld,%f\n",
             s->id+1,s->stat,s->back,
             s->statx,s->staty,s->statz,s->stath,
             s->backx,s->backy,s->backz,s->backh,
             s->backx1,s->backy1,s->backz1,
             s->headh[0],s->headh[1],s->tailh[0],s->tailh[1],
             s->headv[0],s->headv[1],s->tailv[0],s->tailv[1],
             s->azi[0],s->azi[1],s->pitch[0],s->pitch[1],
             s->roll[0],s->roll[0],(long)s->t,s->anglediff);
        trace(0,"mtg_store_station:%s\n",cmd);

		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    s->id++;

		    ret=1;
            mtg->m.iset=s->id;
		    mtg->istat.x=s->statx;
		    mtg->istat.y=s->staty;
		    mtg->istat.z=s->statz;
		    mtg->iback.x=s->backx;
		    mtg->iback.y=s->backy;
		    mtg->iback.z=s->backz;
		    strcpy(mtg->istat.name,s->stat);
		    strcpy(mtg->iback.name,s->back);
		    mtg->istn=*s;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

    if(fp) fclose(fp);

	return ret;
}

extern LIBMTG_API int mtg_store_mp(mtg_t* mtg)
{
    int ret=0;
	MYSQL mysql;
	char cmd[2048];
	MTG_MP *mp={0};
    FILE* fp;
    if(mtg->backup==0) fp=fopen(mtg->dbpath,"a");

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    mp=&mtg->mp;
	    sprintf(cmd,"insert into mcheck_set(\
             head1,head2,head3,head4,head5,head6,\
             tail1,tail2,tail3,tail4,tail5,tail6,\
             psm1,psm2,psm3,psm4,psm5,psm6,psm7,psm8,\
             inc1,inc2,inc3,inc4,inc5,inc6,\
             headc,headh,headv,headh1,headv1,\
             tailc,tailh,tailv,tailh1,tailv1,t) values(\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,\
             %.12f,%.12f,%.12f,%.12f,%.12f,%ld)",
             mp->head[0],mp->head[1],mp->head[2],mp->head[3],mp->head[4],mp->head[5],
             mp->tail[0],mp->tail[1],mp->tail[2],mp->tail[3],mp->tail[4],mp->tail[5],
             mp->prism[9],mp->prism[10],mp->prism[11],mp->prism[12],mp->prism[13],mp->prism[14],
             mp->prism[15],mp->prism[16]/*,mp->prism[17]*/,mp->inc[0],mp->inc[1],mp->inc[2],
             mp->inc[3],mp->inc[4],mp->inc[5],mp->headc,mp->headh,mp->headv,mp->headh1,mp->headv1,
             mp->tailc,mp->tailh,mp->tailv,mp->tailh1,mp->tailv1,(long)mp->t);

        if(fp)
        fprintf(fp,"%%R1P,22:0:%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
             %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,\
             %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%ld\n",
             mp->head[0],mp->head[1],mp->head[2],mp->head[3],mp->head[4],mp->head[5],
             mp->tail[0],mp->tail[1],mp->tail[2],mp->tail[3],mp->tail[4],mp->tail[5],
             mp->prism[9],mp->prism[10],mp->prism[11],mp->prism[12],mp->prism[13],mp->prism[14],
             mp->prism[15],mp->prism[16]/*,mp->prism[17]*/,mp->inc[0],mp->inc[1],mp->inc[2],
             mp->inc[3],mp->inc[4],mp->inc[5],mp->headc,mp->headh,mp->headv,mp->headh1,mp->headv1,
             mp->tailc,mp->tailh,mp->tailv,mp->tailh1,mp->tailv1,(long)mp->t);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    ret=1;
		}
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);
    if(fp) fclose(fp);
	return ret;
}

extern LIBMTG_API int mtg_query_station(mtg_t* mtg,MTG_STATION** res)
{
    MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[1024];
	int index=0,nret=0,i=0;
	MTG_STATION* s=0;
	long t;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
    {
        sprintf(cmd,"select * from station_set");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    nret=mysql_num_rows(results);
		    s=(MTG_STATION*)malloc(nret*sizeof(MTG_STATION));
		    index=0;
		    while((record = mysql_fetch_row(results)))
            {
                sscanf(record[0],"%d",&s[index].id);
                strcpy(s[index].stat,record[1]);
                strcpy(s[index].back,record[2]);
                sscanf(record[3],"%lf",&s[index].statx);
                sscanf(record[4],"%lf",&s[index].staty);
                sscanf(record[5],"%lf",&s[index].statz);
                sscanf(record[6],"%lf",&s[index].stath);
                sscanf(record[7],"%lf",&s[index].backx);
                sscanf(record[8],"%lf",&s[index].backy);
                sscanf(record[9],"%lf",&s[index].backz);
                sscanf(record[10],"%lf",&s[index].backh);
                sscanf(record[11],"%lf",&s[index].backx1);
                sscanf(record[12],"%lf",&s[index].backy1);
                sscanf(record[13],"%lf",&s[index].backz1);
                sscanf(record[14],"%lf",&s[index].headh[0]);
                sscanf(record[15],"%lf",&s[index].headh[1]);
                sscanf(record[16],"%lf",&s[index].tailh[0]);
                sscanf(record[17],"%lf",&s[index].tailh[1]);
                sscanf(record[18],"%lf",&s[index].headv[0]);
                sscanf(record[19],"%lf",&s[index].headv[1]);
                sscanf(record[20],"%lf",&s[index].tailv[0]);
                sscanf(record[21],"%lf",&s[index].tailv[1]);
                sscanf(record[22],"%lf",&s[index].azi[0]);
                sscanf(record[23],"%lf",&s[index].azi[1]);
                sscanf(record[24],"%lf",&s[index].pitch[0]);
                sscanf(record[25],"%lf",&s[index].pitch[1]);
                sscanf(record[26],"%lf",&s[index].roll[0]);
                sscanf(record[27],"%lf",&s[index].roll[1]);
                sscanf(record[28],"%ld",&t);
                s[index].t=t;
                index++;
            }
            mysql_free_result(results);
		}
    }

    mysql_close(&mysql);
	unlock(&mtg->dblock);

    *res=s;

	return nret;
}

extern LIBMTG_API int mtg_query_chain(mtg_t* mtg,double l1,double l2,MTG_MEASURE** res)
{
	MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[1024];
	int index=0,nret=0,i=0;
	MTG_MEASURE* m=0;
	long t;
	int cols=0;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
		///
		sprintf(cmd,"select * from measure_set where headc >= %.3f and headc <= %.3f  order by id desc ",l1,l2);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    nret=mysql_num_rows(results);
		    ///if(nret>2000) nret=2000;
		    m=(MTG_MEASURE*)malloc(nret*sizeof(MTG_MEASURE));
		    cols=mysql_num_fields(results);
		    index=0;

		    while((record = mysql_fetch_row(results)))
			{
			    i=1;
			    sscanf(record[i++],"%lf",&m[index].inc[0]);
			    sscanf(record[i++],"%lf",&m[index].inc[1]);
			    sscanf(record[i++],"%lf",&m[index].inc[2]);
			    sscanf(record[i++],"%lf",&m[index].inc[3]);
			    sscanf(record[i++],"%lf",&m[index].cam[0]);
			    sscanf(record[i++],"%lf",&m[index].cam[1]);
			    sscanf(record[i++],"%lf",&m[index].cam[2]);
			    sscanf(record[i++],"%lf",&m[index].cam[3]);
			    sscanf(record[i++],"%lf",&m[index].prism[0]);
			    sscanf(record[i++],"%lf",&m[index].prism[1]);
			    sscanf(record[i++],"%lf",&m[index].prism[2]);
			    sscanf(record[i++],"%lf",&m[index].angle[0]);
                sscanf(record[i++],"%lf",&m[index].angle[1]);
                sscanf(record[i++],"%lf",&m[index].comp[0]);
			    sscanf(record[i++],"%lf",&m[index].comp[1]);
			    sscanf(record[i++],"%lf",&m[index].head[0]);
			    sscanf(record[i++],"%lf",&m[index].head[1]);
			    sscanf(record[i++],"%lf",&m[index].head[2]);
			    sscanf(record[i++],"%lf",&m[index].hdes[0]);
			    sscanf(record[i++],"%lf",&m[index].hdes[1]);
			    sscanf(record[i++],"%lf",&m[index].hdes[2]);
			    sscanf(record[i++],"%lf",&m[index].headc);
			    sscanf(record[i++],"%lf",&m[index].headh);
			    sscanf(record[i++],"%lf",&m[index].headv);
			    sscanf(record[i++],"%lf",&m[index].tail[0]);
			    sscanf(record[i++],"%lf",&m[index].tail[1]);
			    sscanf(record[i++],"%lf",&m[index].tail[2]);
			    sscanf(record[i++],"%lf",&m[index].tdes[0]);
			    sscanf(record[i++],"%lf",&m[index].tdes[1]);
			    sscanf(record[i++],"%lf",&m[index].tdes[2]);
			    sscanf(record[i++],"%lf",&m[index].tailc);
			    sscanf(record[i++],"%lf",&m[index].tailh);
			    sscanf(record[i++],"%lf",&m[index].tailv);
			    sscanf(record[i++],"%lf",&m[index].mile1);
			    sscanf(record[i++],"%lf",&m[index].hdev1);
			    sscanf(record[i++],"%lf",&m[index].vdev1);
			    sscanf(record[i++],"%lf",&m[index].mile2);
			    sscanf(record[i++],"%lf",&m[index].hdev2);
			    sscanf(record[i++],"%lf",&m[index].vdev2);
			    sscanf(record[i++],"%lf",&m[index].mile3);
			    sscanf(record[i++],"%lf",&m[index].hdev3);
			    sscanf(record[i++],"%lf",&m[index].vdev3);
			    sscanf(record[i++],"%lf",&m[index].faj[0]);
			    sscanf(record[i++],"%lf",&m[index].faj[1]);
			    sscanf(record[i++],"%lf",&m[index].faj[2]);
			    sscanf(record[i++],"%lf",&m[index].faj[3]);
			    sscanf(record[i++],"%lf",&m[index].baj[0]);
			    sscanf(record[i++],"%lf",&m[index].baj[1]);
			    sscanf(record[i++],"%lf",&m[index].baj[2]);
			    sscanf(record[i++],"%lf",&m[index].baj[3]);
			    sscanf(record[i++],"%lf",&m[index].aj[0]);
			    sscanf(record[i++],"%lf",&m[index].aj[1]);
			    sscanf(record[i++],"%lf",&m[index].aj[2]);
			    sscanf(record[i++],"%lf",&m[index].aj[3]);
			    sscanf(record[i++],"%lf",&m[index].inc1[0]);
			    sscanf(record[i++],"%lf",&m[index].inc1[1]);
			    sscanf(record[i++],"%lf",&m[index].inc1[2]);
			    sscanf(record[i++],"%d",&m[index].iseg);
			    sscanf(record[i++],"%ld",&t);
			    m[index].t1=t;
			    sscanf(record[i++],"%ld",&t);
			    m[index].t2=t;
			    sscanf(record[i++],"%ld",&t);
			    m[index].t3=t;
			    sscanf(record[i++],"%d",&m[index].iset);
			    if(cols>=69)
                {
                    sscanf(record[i++],"%lf",&m[index].ht[0]);
                    sscanf(record[i++],"%lf",&m[index].ht[1]);
                    sscanf(record[i++],"%lf",&m[index].ht[2]);
                    sscanf(record[i++],"%lf",&m[index].htdes[0]);
                    sscanf(record[i++],"%lf",&m[index].htdes[1]);
                    sscanf(record[i++],"%lf",&m[index].htdes[2]);
                }
                if(cols>=72)
                {
                    sscanf(record[i++],"%ld",&m[index].t5);
                    sscanf(record[i++],"%lf",&m[index].inc[5]);
                    sscanf(record[i++],"%lf",&m[index].inc[6]);
                }
                if(cols>=74)
                {
                    sscanf(record[i++],"%lf",&m[index].inc4[0]);
                    sscanf(record[i++],"%lf",&m[index].inc4[1]);
                }
			    index++;
			    ///if(index>2000) break;
			}
			mysql_free_result(results);
		}
	}

	mysql_close(&mysql);
	unlock(&mtg->dblock);

    *res=m;

	return nret;
}

extern LIBMTG_API int mtg_query_segment_chain(mtg_t* mtg,double l1,double l2,MTG_MEASURE** res)
{
	MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[1024];
	int index=0,nret=0;
	MTG_MEASURE* m=0;
	long t;
	int i=0;
	int cols=0;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
		///
		sprintf(cmd,"select * from seg_meas where headc >= %.3f and headc <= %.3f  order by id desc ",l1,l2);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    nret=mysql_num_rows(results);
		    m=(MTG_MEASURE*)malloc(nret*sizeof(MTG_MEASURE));
		    cols=mysql_num_fields(results);
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    sscanf(record[1],"%lf",&m[index].inc[0]);
			    sscanf(record[2],"%lf",&m[index].inc[1]);
			    sscanf(record[3],"%lf",&m[index].inc[2]);
			    //sscanf(record[4],"%lf",&m[index].inc[3]);
			    i=4;
			    sscanf(record[i++],"%lf",&m[index].cam[0]);
			    sscanf(record[i++],"%lf",&m[index].cam[1]);
			    sscanf(record[i++],"%lf",&m[index].cam[2]);
			    sscanf(record[i++],"%lf",&m[index].cam[3]);
			    sscanf(record[i++],"%lf",&m[index].prism[0]);
			    sscanf(record[i++],"%lf",&m[index].prism[1]);
			    sscanf(record[i++],"%lf",&m[index].prism[2]);
			    sscanf(record[i++],"%lf",&m[index].angle[0]);
                sscanf(record[i++],"%lf",&m[index].angle[1]);
                sscanf(record[i++],"%lf",&m[index].comp[0]);
			    sscanf(record[i++],"%lf",&m[index].comp[1]);
			    sscanf(record[i++],"%lf",&m[index].head[0]);
			    sscanf(record[i++],"%lf",&m[index].head[1]);
			    sscanf(record[i++],"%lf",&m[index].head[2]);
			    sscanf(record[i++],"%lf",&m[index].hdes[0]);
			    sscanf(record[i++],"%lf",&m[index].hdes[1]);
			    sscanf(record[i++],"%lf",&m[index].hdes[2]);
			    sscanf(record[i++],"%lf",&m[index].headc);
			    sscanf(record[i++],"%lf",&m[index].headh);
			    sscanf(record[i++],"%lf",&m[index].headv);
			    sscanf(record[i++],"%lf",&m[index].tail[0]);
			    sscanf(record[i++],"%lf",&m[index].tail[1]);
			    sscanf(record[i++],"%lf",&m[index].tail[2]);
			    sscanf(record[i++],"%lf",&m[index].tdes[0]);
			    sscanf(record[i++],"%lf",&m[index].tdes[1]);
			    sscanf(record[i++],"%lf",&m[index].tdes[2]);
			    sscanf(record[i++],"%lf",&m[index].tailc);
			    sscanf(record[i++],"%lf",&m[index].tailh);
			    sscanf(record[i++],"%lf",&m[index].tailv);
			    sscanf(record[i++],"%lf",&m[index].faj[0]);
			    sscanf(record[i++],"%lf",&m[index].faj[1]);
			    sscanf(record[i++],"%lf",&m[index].faj[2]);
			    sscanf(record[i++],"%lf",&m[index].faj[3]);
			    sscanf(record[i++],"%lf",&m[index].baj[0]);
			    sscanf(record[i++],"%lf",&m[index].baj[1]);
			    sscanf(record[i++],"%lf",&m[index].baj[2]);
			    sscanf(record[i++],"%lf",&m[index].baj[3]);
			    sscanf(record[i++],"%lf",&m[index].aj[0]);
			    sscanf(record[i++],"%lf",&m[index].aj[1]);
			    sscanf(record[i++],"%lf",&m[index].aj[2]);
			    sscanf(record[i++],"%lf",&m[index].aj[3]);
			    sscanf(record[i++],"%lf",&m[index].inc1[0]);
			    sscanf(record[i++],"%lf",&m[index].inc1[1]);
			    sscanf(record[i++],"%lf",&m[index].inc1[2]);
			    sscanf(record[i++],"%d",&m[index].iseg);
			    sscanf(record[i++],"%ld",&t);
			    m[index].t1=t;
			    sscanf(record[i++],"%ld",&t);
			    m[index].t2=t;
			    sscanf(record[i++],"%ld",&t);
			    m[index].t3=t;
			    sscanf(record[i++],"%d",&m[index].iset);
			    if(cols>=69)
                {
                    sscanf(record[i++],"%lf",&m[index].ht[0]);
                    sscanf(record[i++],"%lf",&m[index].ht[1]);
                    sscanf(record[i++],"%lf",&m[index].ht[2]);
                    sscanf(record[i++],"%lf",&m[index].htdes[0]);
                    sscanf(record[i++],"%lf",&m[index].htdes[1]);
                    sscanf(record[i++],"%lf",&m[index].htdes[2]);
                }
                if(cols>=72)
                {
                    sscanf(record[i++],"%ld",&m[index].t5);
                    sscanf(record[i++],"%lf",&m[index].inc[5]);
                    sscanf(record[i++],"%lf",&m[index].inc[6]);
                }
                if(cols>=74)
                {
                    sscanf(record[i++],"%lf",&m[index].inc4[0]);
                    sscanf(record[i++],"%lf",&m[index].inc4[1]);
                }
			    index++;
			}
			mysql_free_result(results);
		}
	}

	mysql_close(&mysql);
	unlock(&mtg->dblock);

    *res=m;
	return nret;
}

extern LIBMTG_API int mtg_query_seg(mtg_t* mtg,int n1,int n2,MTG_MEASURE** res)
{
	MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[1024];
	int index=0,nret=0,i=0;
	MTG_MEASURE* m=0;
	long t;
	int j=0;
	int cols=0;
	FILE *fp=fopen("D:\\midu\\mtg_query_seg.log","w");

    trace(0,"database:n1=%d,n2=%d\n",n1,n2);
    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
		///
		sprintf(cmd,"select * from measure_set where iseg >= %d and iseg <= %d order by id desc",n1,n2);
		trace(0,"database:cmd=%s\n",cmd);
		if(fp)
        {
            fprintf(fp,"%s\n",cmd);
            fflush(fp);
        }
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    nret=mysql_num_rows(results);
		    //if(nret>2000) nret=2000;
		    m=(MTG_MEASURE*)malloc(nret*sizeof(MTG_MEASURE));
		    cols=mysql_num_fields(results);
		    index=0;

		    while((record = mysql_fetch_row(results)))
			{
			    i=1;
			    sscanf(record[i++],"%lf",&m[index].inc[0]);
			    sscanf(record[i++],"%lf",&m[index].inc[1]);
			    sscanf(record[i++],"%lf",&m[index].inc[2]);
			    sscanf(record[i++],"%lf",&m[index].inc[3]);
			    sscanf(record[i++],"%lf",&m[index].cam[0]);
			    sscanf(record[i++],"%lf",&m[index].cam[1]);
			    sscanf(record[i++],"%lf",&m[index].cam[2]);
			    sscanf(record[i++],"%lf",&m[index].cam[3]);
			    sscanf(record[i++],"%lf",&m[index].prism[0]);
			    sscanf(record[i++],"%lf",&m[index].prism[1]);
			    sscanf(record[i++],"%lf",&m[index].prism[2]);
			    sscanf(record[i++],"%lf",&m[index].angle[0]);
                sscanf(record[i++],"%lf",&m[index].angle[1]);
                sscanf(record[i++],"%lf",&m[index].comp[0]);
			    sscanf(record[i++],"%lf",&m[index].comp[1]);
			    sscanf(record[i++],"%lf",&m[index].head[0]);
			    sscanf(record[i++],"%lf",&m[index].head[1]);
			    sscanf(record[i++],"%lf",&m[index].head[2]);
			    sscanf(record[i++],"%lf",&m[index].hdes[0]);
			    sscanf(record[i++],"%lf",&m[index].hdes[1]);
			    sscanf(record[i++],"%lf",&m[index].hdes[2]);
			    sscanf(record[i++],"%lf",&m[index].headc);
			    sscanf(record[i++],"%lf",&m[index].headh);
			    sscanf(record[i++],"%lf",&m[index].headv);
			    sscanf(record[i++],"%lf",&m[index].tail[0]);
			    sscanf(record[i++],"%lf",&m[index].tail[1]);
			    sscanf(record[i++],"%lf",&m[index].tail[2]);
			    sscanf(record[i++],"%lf",&m[index].tdes[0]);
			    sscanf(record[i++],"%lf",&m[index].tdes[1]);
			    sscanf(record[i++],"%lf",&m[index].tdes[2]);
			    sscanf(record[i++],"%lf",&m[index].tailc);
			    sscanf(record[i++],"%lf",&m[index].tailh);
			    sscanf(record[i++],"%lf",&m[index].tailv);
			    sscanf(record[i++],"%lf",&m[index].mile1);
			    sscanf(record[i++],"%lf",&m[index].hdev1);
			    sscanf(record[i++],"%lf",&m[index].vdev1);
			    sscanf(record[i++],"%lf",&m[index].mile2);
			    sscanf(record[i++],"%lf",&m[index].hdev2);
			    sscanf(record[i++],"%lf",&m[index].vdev2);
			    sscanf(record[i++],"%lf",&m[index].mile3);
			    sscanf(record[i++],"%lf",&m[index].hdev3);
			    sscanf(record[i++],"%lf",&m[index].vdev3);
			    sscanf(record[i++],"%lf",&m[index].faj[0]);
			    sscanf(record[i++],"%lf",&m[index].faj[1]);
			    sscanf(record[i++],"%lf",&m[index].faj[2]);
			    sscanf(record[i++],"%lf",&m[index].faj[3]);
			    sscanf(record[i++],"%lf",&m[index].baj[0]);
			    sscanf(record[i++],"%lf",&m[index].baj[1]);
			    sscanf(record[i++],"%lf",&m[index].baj[2]);
			    sscanf(record[i++],"%lf",&m[index].baj[3]);
			    sscanf(record[i++],"%lf",&m[index].aj[0]);
			    sscanf(record[i++],"%lf",&m[index].aj[1]);
			    sscanf(record[i++],"%lf",&m[index].aj[2]);
			    sscanf(record[i++],"%lf",&m[index].aj[3]);
			    sscanf(record[i++],"%lf",&m[index].inc1[0]);
			    sscanf(record[i++],"%lf",&m[index].inc1[1]);
			    sscanf(record[i++],"%lf",&m[index].inc1[2]);
			    sscanf(record[i++],"%d",&m[index].iseg);
			    sscanf(record[i++],"%ld",&t);
			    m[index].t1=t;
			    sscanf(record[i++],"%ld",&t);
			    m[index].t2=t;
			    sscanf(record[i++],"%ld",&t);
			    m[index].t3=t;
			    sscanf(record[i++],"%d",&m[index].iset);
//			    if(j<6)
//                {
//                    mtg->m=m[index];
//                    mtg_laser_incline(mtg);
//                }
                if(cols>=69)
                {
                    sscanf(record[i++],"%lf",&m[index].ht[0]);
                    sscanf(record[i++],"%lf",&m[index].ht[1]);
                    sscanf(record[i++],"%lf",&m[index].ht[2]);
                    sscanf(record[i++],"%lf",&m[index].htdes[0]);
                    sscanf(record[i++],"%lf",&m[index].htdes[1]);
                    sscanf(record[i++],"%lf",&m[index].htdes[2]);
                }
                if(cols>=72)
                {
                    sscanf(record[i++],"%ld",&m[index].t5);
                    sscanf(record[i++],"%lf",&m[index].inc[5]);
                    sscanf(record[i++],"%lf",&m[index].inc[6]);
                }
                if(cols>=74)
                {
                    sscanf(record[i++],"%lf",&m[index].inc4[0]);
                    sscanf(record[i++],"%lf",&m[index].inc4[1]);
                }
			    index++;
			    j++;
			    //if(index>2000) break;
			}
			mysql_free_result(results);
		}
	}

	mysql_close(&mysql);
	unlock(&mtg->dblock);
	if(fp)
        fclose(fp);

    *res=m;
	return nret;
}

extern LIBMTG_API int mtg_query_time(mtg_t* mtg,long t1,long t2,MTG_MEASURE** res)
{
	MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[2048];
	int index=0,nret=0;
	int i;
	MTG_MEASURE* m=0;
	long t;
	int cols=0;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	//trace(0,"t1=%ld,t2=%ld\n",t1,t2);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
		sprintf(cmd,"select * from measure_set where t1 >= %ld and t1 <= %ld order by id desc",t1,t2);
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    nret=mysql_num_rows(results);
		    //trace(0,"nret=%d\n",nret);
		    m=(MTG_MEASURE*)malloc(nret*sizeof(MTG_MEASURE));
		    cols=mysql_num_fields(results);
		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    i=1;
			    sscanf(record[i++],"%lf",&m[index].inc[0]);
			    sscanf(record[i++],"%lf",&m[index].inc[1]);
			    sscanf(record[i++],"%lf",&m[index].inc[2]);
			    sscanf(record[i++],"%lf",&m[index].inc[3]);
			    sscanf(record[i++],"%lf",&m[index].cam[0]);
			    sscanf(record[i++],"%lf",&m[index].cam[1]);
			    sscanf(record[i++],"%lf",&m[index].cam[2]);
			    sscanf(record[i++],"%lf",&m[index].cam[3]);
			    sscanf(record[i++],"%lf",&m[index].prism[0]);
			    sscanf(record[i++],"%lf",&m[index].prism[1]);
			    sscanf(record[i++],"%lf",&m[index].prism[2]);
			    sscanf(record[i++],"%lf",&m[index].angle[0]);
                sscanf(record[i++],"%lf",&m[index].angle[1]);
                sscanf(record[i++],"%lf",&m[index].comp[0]);
			    sscanf(record[i++],"%lf",&m[index].comp[1]);
			    sscanf(record[i++],"%lf",&m[index].head[0]);
			    sscanf(record[i++],"%lf",&m[index].head[1]);
			    sscanf(record[i++],"%lf",&m[index].head[2]);
			    sscanf(record[i++],"%lf",&m[index].hdes[0]);
			    sscanf(record[i++],"%lf",&m[index].hdes[1]);
			    sscanf(record[i++],"%lf",&m[index].hdes[2]);
			    sscanf(record[i++],"%lf",&m[index].headc);
			    sscanf(record[i++],"%lf",&m[index].headh);
			    sscanf(record[i++],"%lf",&m[index].headv);
			    sscanf(record[i++],"%lf",&m[index].tail[0]);
			    sscanf(record[i++],"%lf",&m[index].tail[1]);
			    sscanf(record[i++],"%lf",&m[index].tail[2]);
			    sscanf(record[i++],"%lf",&m[index].tdes[0]);
			    sscanf(record[i++],"%lf",&m[index].tdes[1]);
			    sscanf(record[i++],"%lf",&m[index].tdes[2]);
			    sscanf(record[i++],"%lf",&m[index].tailc);
			    sscanf(record[i++],"%lf",&m[index].tailh);
			    sscanf(record[i++],"%lf",&m[index].tailv);
			    sscanf(record[i++],"%lf",&m[index].mile1);
			    sscanf(record[i++],"%lf",&m[index].hdev1);
			    sscanf(record[i++],"%lf",&m[index].vdev1);
			    sscanf(record[i++],"%lf",&m[index].mile2);
			    sscanf(record[i++],"%lf",&m[index].hdev2);
			    sscanf(record[i++],"%lf",&m[index].vdev2);
			    sscanf(record[i++],"%lf",&m[index].mile3);
			    sscanf(record[i++],"%lf",&m[index].hdev3);
			    sscanf(record[i++],"%lf",&m[index].vdev3);
			    sscanf(record[i++],"%lf",&m[index].faj[0]);
			    sscanf(record[i++],"%lf",&m[index].faj[1]);
			    sscanf(record[i++],"%lf",&m[index].faj[2]);
			    sscanf(record[i++],"%lf",&m[index].faj[0]);
			    sscanf(record[i++],"%lf",&m[index].baj[0]);
			    sscanf(record[i++],"%lf",&m[index].baj[1]);
			    sscanf(record[i++],"%lf",&m[index].baj[2]);
			    sscanf(record[i++],"%lf",&m[index].baj[3]);
			    sscanf(record[i++],"%lf",&m[index].aj[0]);
			    sscanf(record[i++],"%lf",&m[index].aj[1]);
			    sscanf(record[i++],"%lf",&m[index].aj[2]);
			    sscanf(record[i++],"%lf",&m[index].aj[3]);
			    sscanf(record[i++],"%lf",&m[index].inc1[0]);
			    sscanf(record[i++],"%lf",&m[index].inc1[1]);
			    sscanf(record[i++],"%lf",&m[index].inc1[2]);
			    sscanf(record[i++],"%d",&m[index].iseg);
			    sscanf(record[i++],"%ld",&t);
			    m[index].t1=t;
			    sscanf(record[i++],"%ld",&t);
			    m[index].t2=t;
			    sscanf(record[i++],"%ld",&t);
			    m[index].t3=t;
			    sscanf(record[i++],"%d",&m[index].iset);
			    if(cols>=69)
                {
                    sscanf(record[i++],"%lf",&m[index].ht[0]);
                    sscanf(record[i++],"%lf",&m[index].ht[1]);
                    sscanf(record[i++],"%lf",&m[index].ht[2]);
                    sscanf(record[i++],"%lf",&m[index].htdes[0]);
                    sscanf(record[i++],"%lf",&m[index].htdes[1]);
                    sscanf(record[i++],"%lf",&m[index].htdes[2]);
                }
                if(cols>=72)
                {
                    sscanf(record[i++],"%ld",&m[index].t5);
                    sscanf(record[i++],"%lf",&m[index].inc[5]);
                    sscanf(record[i++],"%lf",&m[index].inc[6]);
                }
                if(cols>=74)
                {
                    sscanf(record[i++],"%lf",&m[index].inc4[0]);
                    sscanf(record[i++],"%lf",&m[index].inc4[1]);
                }
			    index++;
			}
			mysql_free_result(results);
		}
	}

	mysql_close(&mysql);
	unlock(&mtg->dblock);

    *res=m;
	return nret;
}

extern LIBMTG_API int mtg_query_duty(mtg_t* mtg,int dvr,MTG_DUTY** res)
{
    MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[1024];
	int index=0,ret=0;
	MTG_DUTY* duty=0;
	long t;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        sprintf(cmd,"select * from duty_set where onduty = %d order by id desc",dvr);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    ret=mysql_num_rows(results);
		    duty=(MTG_DUTY*)malloc(ret*sizeof(MTG_DUTY));
		    index=0;
		    while((record = mysql_fetch_row(results)))
            {
                sscanf(record[3],"%d",&duty[index].seg1);
                sscanf(record[4],"%d",&duty[index].seg2);
                sscanf(record[5],"%lf",&duty[index].mile1);
                sscanf(record[6],"%lf",&duty[index].mile2);
                sscanf(record[7],"%ld",&t);
                duty[index].t1=t;
                sscanf(record[8],"%ld",&t);
			    duty[index].t2=t;
			    sscanf(record[9],"%lf",&duty[index].mxdev);
			    index++;
            }
            mysql_free_result(results);
		}
		trace(0,"cmd=%s\n",cmd);
	}

	mysql_close(&mysql);
	unlock(&mtg->dblock);

	*res=duty;
	return ret;
}

extern LIBMTG_API int mtg_query_segeds(mtg_t* mtg,MTG_SEG** res)
{
    MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[4096];
	int index=0,ret=0;
	MTG_SEG* seg=0;
	int i=0;
	long t;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        sprintf(cmd,"select * from seged_set");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    ret=mysql_num_rows(results);
		    seg=(MTG_SEG*)malloc(ret*sizeof(MTG_SEG));
		    index=0;
		    while((record = mysql_fetch_row(results)))
            {
                i=1;
                sscanf(record[i++],"%d",&seg[index].numb);
                sscanf(record[i++],"%d",&seg[index].type);
                sscanf(record[i++],"%d",&seg[index].k);
                sscanf(record[i++],"%d",&seg[index].mode);
                sscanf(record[i++],"%lf",&seg[index].hpz);
                sscanf(record[i++],"%lf",&seg[index].vpz);
                sscanf(record[i++],"%lf",&seg[index].x);
                sscanf(record[i++],"%lf",&seg[index].y);
                sscanf(record[i++],"%lf",&seg[index].z);
                sscanf(record[i++],"%lf",&seg[index].x1);
                sscanf(record[i++],"%lf",&seg[index].y1);
                sscanf(record[i++],"%lf",&seg[index].z1);
                sscanf(record[i++],"%lf",&seg[index].ori);
                sscanf(record[i++],"%lf",&seg[index].phi);
                sscanf(record[i++],"%lf",&seg[index].ori1);
                sscanf(record[i++],"%lf",&seg[index].phi1);
                sscanf(record[i++],"%lf",&seg[index].mile);
                sscanf(record[i++],"%lf",&seg[index].dh);
                sscanf(record[i++],"%lf",&seg[index].dv);
                sscanf(record[i++],"%lf",&seg[index].dh1);
                sscanf(record[i++],"%lf",&seg[index].dv1);
                sscanf(record[i++],"%lf",&seg[index].head[0]);
                sscanf(record[i++],"%lf",&seg[index].head[1]);
                sscanf(record[i++],"%lf",&seg[index].head[2]);
                sscanf(record[i++],"%lf",&seg[index].headc);
                sscanf(record[i++],"%lf",&seg[index].headh);
                sscanf(record[i++],"%lf",&seg[index].headv);
                sscanf(record[i++],"%lf",&seg[index].tail[0]);
                sscanf(record[i++],"%lf",&seg[index].tail[1]);
                sscanf(record[i++],"%lf",&seg[index].tail[2]);
                sscanf(record[i++],"%lf",&seg[index].tailc);
                sscanf(record[i++],"%lf",&seg[index].tailh);
                sscanf(record[i++],"%lf",&seg[index].tailv);
                sscanf(record[i++],"%lf",&seg[index].tbmh);
                sscanf(record[i++],"%lf",&seg[index].tbmv);
                sscanf(record[i++],"%lf",&seg[index].desh);
                sscanf(record[i++],"%lf",&seg[index].desv);
                sscanf(record[i++],"%lf",&seg[index].gap[0]);
                sscanf(record[i++],"%lf",&seg[index].gap[1]);
                sscanf(record[i++],"%lf",&seg[index].gap[2]);
                sscanf(record[i++],"%lf",&seg[index].gap[3]);
                sscanf(record[i++],"%lf",&seg[index].aj[0]);
                sscanf(record[i++],"%lf",&seg[index].aj[1]);
                sscanf(record[i++],"%lf",&seg[index].aj[2]);
                sscanf(record[i++],"%lf",&seg[index].aj[3]);
                sscanf(record[i++],"%lf",&seg[index].faj[0]);
                sscanf(record[i++],"%lf",&seg[index].faj[1]);
                sscanf(record[i++],"%lf",&seg[index].faj[2]);
                sscanf(record[i++],"%lf",&seg[index].faj[3]);
                sscanf(record[i++],"%lf",&seg[index].baj[0]);
                sscanf(record[i++],"%lf",&seg[index].baj[1]);
                sscanf(record[i++],"%lf",&seg[index].baj[2]);
                sscanf(record[i++],"%lf",&seg[index].baj[3]);
                sscanf(record[i++],"%lf",&seg[index].harc);
                sscanf(record[i++],"%lf",&seg[index].varc);
                sscanf(record[i++],"%ld",&t);
                seg[index].t=t;
			    index++;
            }
            mysql_free_result(results);
		}
		//trace(0,"cmd=%s\n",cmd);
	}

	mysql_close(&mysql);
	unlock(&mtg->dblock);

	*res=seg;
	return ret;
}

extern LIBMTG_API int mtg_query_seged(mtg_t* mtg,int n1,int n2,MTG_SEG** res)
{
    MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[4096];
	int index=0,ret=0;
	MTG_SEG* seg=0;
	int i=0;
	long t;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"select * from seged_set where iseg >= %d and iseg <= %d order by id desc",n1,n2);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    ret=mysql_num_rows(results);
		    seg=(MTG_SEG*)malloc(ret*sizeof(MTG_SEG));
		    index=0;
		    while((record = mysql_fetch_row(results)))
            {
                i=1;
                sscanf(record[i++],"%d",&seg[index].numb);
                sscanf(record[i++],"%d",&seg[index].type);
                sscanf(record[i++],"%d",&seg[index].k);
                sscanf(record[i++],"%d",&seg[index].mode);
                sscanf(record[i++],"%lf",&seg[index].hpz);
                sscanf(record[i++],"%lf",&seg[index].vpz);
                sscanf(record[i++],"%lf",&seg[index].x);
                sscanf(record[i++],"%lf",&seg[index].y);
                sscanf(record[i++],"%lf",&seg[index].z);
                sscanf(record[i++],"%lf",&seg[index].x1);
                sscanf(record[i++],"%lf",&seg[index].y1);
                sscanf(record[i++],"%lf",&seg[index].z1);
                sscanf(record[i++],"%lf",&seg[index].ori);
                sscanf(record[i++],"%lf",&seg[index].phi);
                sscanf(record[i++],"%lf",&seg[index].ori1);
                sscanf(record[i++],"%lf",&seg[index].phi1);
                sscanf(record[i++],"%lf",&seg[index].mile);
                sscanf(record[i++],"%lf",&seg[index].dh);
                sscanf(record[i++],"%lf",&seg[index].dv);
                sscanf(record[i++],"%lf",&seg[index].dh1);
                sscanf(record[i++],"%lf",&seg[index].dv1);
                sscanf(record[i++],"%lf",&seg[index].head[0]);
                sscanf(record[i++],"%lf",&seg[index].head[1]);
                sscanf(record[i++],"%lf",&seg[index].head[2]);
                sscanf(record[i++],"%lf",&seg[index].headc);
                sscanf(record[i++],"%lf",&seg[index].headh);
                sscanf(record[i++],"%lf",&seg[index].headv);
                sscanf(record[i++],"%lf",&seg[index].tail[0]);
                sscanf(record[i++],"%lf",&seg[index].tail[1]);
                sscanf(record[i++],"%lf",&seg[index].tail[2]);
                sscanf(record[i++],"%lf",&seg[index].tailc);
                sscanf(record[i++],"%lf",&seg[index].tailh);
                sscanf(record[i++],"%lf",&seg[index].tailv);
                sscanf(record[i++],"%lf",&seg[index].tbmh);
                sscanf(record[i++],"%lf",&seg[index].tbmv);
                sscanf(record[i++],"%lf",&seg[index].desh);
                sscanf(record[i++],"%lf",&seg[index].desv);
                sscanf(record[i++],"%lf",&seg[index].gap[0]);
                sscanf(record[i++],"%lf",&seg[index].gap[1]);
                sscanf(record[i++],"%lf",&seg[index].gap[2]);
                sscanf(record[i++],"%lf",&seg[index].gap[3]);
                sscanf(record[i++],"%lf",&seg[index].aj[0]);
                sscanf(record[i++],"%lf",&seg[index].aj[1]);
                sscanf(record[i++],"%lf",&seg[index].aj[2]);
                sscanf(record[i++],"%lf",&seg[index].aj[3]);
                sscanf(record[i++],"%lf",&seg[index].faj[0]);
                sscanf(record[i++],"%lf",&seg[index].faj[1]);
                sscanf(record[i++],"%lf",&seg[index].faj[2]);
                sscanf(record[i++],"%lf",&seg[index].faj[3]);
                sscanf(record[i++],"%lf",&seg[index].baj[0]);
                sscanf(record[i++],"%lf",&seg[index].baj[1]);
                sscanf(record[i++],"%lf",&seg[index].baj[2]);
                sscanf(record[i++],"%lf",&seg[index].baj[3]);
                sscanf(record[i++],"%lf",&seg[index].harc);
                sscanf(record[i++],"%lf",&seg[index].varc);
                sscanf(record[i++],"%ld",&t);
                seg[index].t=t;
			    index++;
            }
            mysql_free_result(results);
		}
		//trace(0,"cmd=%s\n",cmd);
	}

	mysql_close(&mysql);
	unlock(&mtg->dblock);

	*res=seg;
	return ret;
}

extern LIBMTG_API int mtg_query_segrecord(mtg_t* mtg,SEG_RECORD* rec)
{
    MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[1024];
	int i=0;
	int ret=0;
	FILE *fp=fopen("D:\\midu\\mtg_query_segrecord.log","w");

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
		sprintf(cmd,"select * from measure_set where iseg = %d order by id desc",rec->segnum);
		if(fp)
        {
            fprintf(fp,"%s\n",cmd);
            fflush(fp);
        }
		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    if((record = mysql_fetch_row(results)))
			{
			    ret=1;
			    i=34;
			    sscanf(record[i++],"%lf",&rec->mile);
			    sscanf(record[i++],"%lf",&rec->offh);
			    sscanf(record[i++],"%lf",&rec->offv);
			}
			mysql_free_result(results);

			if(fp)
            {
                fprintf(fp,"%.lf,%.lf,%.lf\n",rec->mile,rec->offh,rec->offv);
                fflush(fp);
            }
		}
	}

	mysql_close(&mysql);
	unlock(&mtg->dblock);
	if(fp)
        fclose(fp);

	return ret;
}

extern LIBMTG_API int mtg_query_segrecords(mtg_t* mtg,SEG_RECORD** rec,int n1,int n2)
{
    MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[4096];
	int index=0,ret=0;
	SEG_RECORD* seg;
	int i=0;
	long t;

    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    sprintf(cmd,"select * from segrecord_set where segnum >= %d and segnum <= %d order by segnum asc",n1,n2);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    ret=mysql_num_rows(results);
		    seg=(SEG_RECORD*)malloc(ret*sizeof(SEG_RECORD));
		    index=0;
		    while((record = mysql_fetch_row(results)))
            {
                i=1;
                sscanf(record[i++],"%d",&seg[index].segnum);
                sscanf(record[i++],"%d",&seg[index].segtype);
                sscanf(record[i++],"%d",&seg[index].location);
                sscanf(record[i++],"%lf",&seg[index].mile);
                sscanf(record[i++],"%lf",&seg[index].offh);
                sscanf(record[i++],"%lf",&seg[index].offv);
                sscanf(record[i++],"%ld",&t);
                seg[index].t=t;
			    index++;
            }
            mysql_free_result(results);
		}
	}

	mysql_close(&mysql);
	unlock(&mtg->dblock);

	*rec=seg;
	return ret;
}

extern LIBMTG_API int mtg_get_lmt(mtg_t* mtg)
{
	MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[1024];
	int index=0,nret=0;
    double l1,l2;
    int a2z=mtg->prj.a2z;


    lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
	    l2=mtg->m1.headc;
	    l1=l2-10.0*a2z;
	    sprintf(cmd,"select * from measure_set where headc >= %.3f order by id desc  ",l1);

		if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
		{
		    results = mysql_store_result(&mysql);
		    nret=mysql_num_rows(results);

		    index=0;
		    while((record = mysql_fetch_row(results)))
			{
			    if(index==0)
			    {
			        l1=l2-0.1*a2z;
			        sscanf(record[21],"%lf",&mtg->hlmt[index]);
                    sscanf(record[22],"%lf",&mtg->vlmt[index]);
                    index++;
                    mtg->nlmt++;
			    }
			    else
                {
                    sscanf(record[20],"%lf",&l2);
                    if(l2<l1 && a2z>0)
                    {
                        l1-=0.1;
                        sscanf(record[21],"%lf",&mtg->hlmt[index]);
                        sscanf(record[22],"%lf",&mtg->vlmt[index]);
                        index++;
                        mtg->nlmt++;
                    }
                    else if(l2>l1 && a2z<0)
                    {
                        l1+=0.1;
                        sscanf(record[21],"%lf",&mtg->hlmt[index]);
                        sscanf(record[22],"%lf",&mtg->vlmt[index]);
                        index++;
                        mtg->nlmt++;
                    }
                }
			    if(index==100) break;
			}
			mysql_free_result(results);
		}
	}

	mysql_close(&mysql);
	unlock(&mtg->dblock);

	return nret;
}

extern LIBMTG_API int mtg_road_import(road* r, const char* path)
{
    sqlite3 *db;
    int rc;
    char cmd[1024];

    h_element h;
    v_element v;
    h_offset ho;
    v_offset vo;
    m_offset mo;

    h_element h0={0};
    v_element e0={0};

    int index;
    int nResult;
    int nCol,nRow;
    char** pResult;
    char *errmsg;
    sqlite3_stmt * stmt;

    road_clear_horizon(r);
    road_clear_vertical(r);
    road_clear_horizon_off(r);
    road_clear_vertical_off(r);
    road_clear_mile_off(r);
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

        if(abs(t2-t1)>24*3600) return -1;
        if(t2-ts>=tf) return -1;
    }
    else
    {
        return -1;
    }

#endif*/
    ///打开文件
    rc = sqlite3_open(path, &db);
    if( rc )
    {
        sqlite3_close(db);
        return -1;
    }

    ///平曲线表
    strcpy(cmd,"select * from horizon_set;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    index=0;
    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        h.type=sqlite3_column_int(stmt,0);
        h.l1=sqlite3_column_double(stmt,1);
        h.length=sqlite3_column_double(stmt,2);
        h.angle1=sqlite3_column_double(stmt,3);
        h.angle2=sqlite3_column_double(stmt,4);
        h.radius=sqlite3_column_double(stmt,5);
        h.rou1=sqlite3_column_double(stmt,6);
        h.rou2=sqlite3_column_double(stmt,7);
        h.x1=sqlite3_column_double(stmt,8);
        h.y1=sqlite3_column_double(stmt,9);
        h.x2=sqlite3_column_double(stmt,10);
        h.y2=sqlite3_column_double(stmt,11);
        h.pz=sqlite3_column_int(stmt,12);
        h.deta=sqlite3_column_double(stmt,13);
        road_insert_horizon(r,&h,index++);
    }
    if(index>0&&h.type>4)
    {
        h.type=4;
        road_modify_horizon(r,&h,index-1);
    }
    road_apply_horizon1(r);///whq添加，为了解决打开文件时显示的平曲线示意图有错的问题
    sqlite3_finalize(stmt);
    ///竖曲线
    strcpy(cmd,"select * from vertical_set;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);

    ///whq修改 ，为了兼容以前的数据库中将2倍切线长视为平面里程添加下面的修改内容
    nResult=sqlite3_get_table(db,cmd,&pResult,&nRow,&nCol,&errmsg);
    ///return 0;
    if(nCol==12)
    {
        index=0;
        while(sqlite3_step(stmt)==SQLITE_ROW)
        {
            v.type=sqlite3_column_int(stmt,0);
            v.l1=sqlite3_column_double(stmt,1);
            v.h1=sqlite3_column_double(stmt,2);
            v.l2=sqlite3_column_double(stmt,3);
            v.h2=sqlite3_column_double(stmt,4);
            v.length=sqlite3_column_double(stmt,5);
            v.radius=sqlite3_column_double(stmt,6);
            v.angle1=sqlite3_column_double(stmt,7);
            v.angle2=sqlite3_column_double(stmt,8);
            v.pz=sqlite3_column_int(stmt,9);
            v.deta=sqlite3_column_double(stmt,10);
//            v.T=sqlite3_column_double(stmt,11);
//            if(v.type==ROAD_TYPE_ARC)
//                v.length=2*v.T;
            road_insert_vertical(r,&v,index++);
        }
        if(index>0&&v.type>4)
        {
            v.type=4;
            road_modify_vertical(r,&v,index-1);
        }
    }
    else if(nCol==11)
    {
        index=0;
        while(sqlite3_step(stmt)==SQLITE_ROW)
        {
            v.type=sqlite3_column_int(stmt,0);
            v.l1=sqlite3_column_double(stmt,1);
            v.h1=sqlite3_column_double(stmt,2);
            v.l2=sqlite3_column_double(stmt,3);
            v.h2=sqlite3_column_double(stmt,4);
            ///v.T=sqlite3_column_double(stmt,5)/2.0;///这里进行修改，原先是长度，现在是切线长2倍
            v.length=sqlite3_column_double(stmt,5);
            v.radius=sqlite3_column_double(stmt,6);
            v.angle1=sqlite3_column_double(stmt,7);
            v.angle2=sqlite3_column_double(stmt,8);
            v.pz=sqlite3_column_int(stmt,9);
            v.deta=sqlite3_column_double(stmt,10);
            road_insert_vertical(r,&v,index++);
        }
        if(index>0&&v.type>4)
        {
            v.type=4;
            road_modify_vertical(r,&v,index-1);
        }
    }
    road_apply_vertical1(r);///whq自己添加，为了解决打开文件时显示的平曲线示意图有错的问题
    sqlite3_finalize(stmt);
    ///平曲线偏移
    strcpy(cmd,"select * from hoff_set;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    index=0;
    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        ho.mile=sqlite3_column_double(stmt,0);
        ho.off=sqlite3_column_double(stmt,1);
        road_insert_horizon_off(r,&ho);
    }
    sqlite3_finalize(stmt);
    ///竖曲线偏移
    strcpy(cmd,"select * from voff_set;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    index=0;
    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        vo.mile=sqlite3_column_double(stmt,0);
        vo.off=sqlite3_column_double(stmt,1);
        road_insert_vertical_off(r,&vo);
    }
    sqlite3_finalize(stmt);
    //whq添加
    //短链
    strcpy(cmd,"select * from moff_set;");
    sqlite3_prepare(db,cmd,-1,&stmt,0);
    index=0;
    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        mo.mile=sqlite3_column_double(stmt,0);
        mo.off=sqlite3_column_double(stmt,1);
        road_insert_mile_off(r,&mo);
    }
    sqlite3_finalize(stmt);//短链添加结束

    sqlite3_close(db);

    if(road_number_horizon(r)<1)
    {
        h0.type=ROAD_TYPE_START_POINT;
        road_insert_horizon(r,&h0,0);
        h0.type=ROAD_TYPE_END_POINT;
        road_insert_horizon(r,&h0,1);
    }
    if(road_number_vertical(r)<1)
    {
        e0.type=ROAD_TYPE_START_POINT;
        road_insert_vertical(r,&e0,0);
        e0.type=ROAD_TYPE_END_POINT;
        road_insert_vertical(r,&e0,1);
    }
    return 0;
}
///////////////////////////////////////////////////////////
extern LIBMTG_API int mtg_road_export(road* r, const char* path)
{
    sqlite3 *db;
    int rc;
    int i,n;
    char cmd[1024];

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
    sqlite3_exec(db,  "begin transaction;", 0, 0, 0);

     ///版本控制
    ///创建表
   //平曲线表
    strcpy(cmd,"create table if not exists horizon_set(type,l1,length,angle1,angle2,radius,rou1,rou2,x1,y1,x2,y2,pz,deta);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    //竖曲线表
    ///strcpy(cmd,"create table if not exists vertical_set(type,l1,h1,l2,h2,length,radius,angle1,angle2,pz,deta,T);");
    strcpy(cmd,"create table if not exists vertical_set(type,l1,h1,l2,h2,length,radius,angle1,angle2,pz,deta);");
    rc = sqlite3_exec(db,  cmd, 0, 0, 0);
    //平曲线偏移表
    strcpy(cmd,"create table if not exists hoff_set(mile,off);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    //竖曲线偏移表
    strcpy(cmd,"create table if not exists voff_set(mile,off);");
    sqlite3_exec(db,  cmd, 0, 0, 0);
    //whq添加,短链数据
    strcpy(cmd,"create table if not exists moff_set(mile,off);");
    sqlite3_exec(db,cmd,0,0,0);//添加结束
    ///存储
    sqlite3_exec(db,"delete from  horizon_set;",0,0,0);   ///平曲线
    n=road_number_horizon(r);
    for(i=0; i<n; i++)
    {
        he=road_horizon(r,i);
        if(i==n-1>0&&he->type>4)
        {
            he->type=4;
        }
        sprintf(cmd,"insert into horizon_set values(\
                %d,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%d,%.12f);",
                he->type,he->l1,he->length,he->angle1,he->angle2,
                he->radius,he->rou1,he->rou2,
                he->x1,he->y1,he->x2,he->y2,he->pz,he->deta);
        sqlite3_exec(db,cmd,0,0,0);
    }

    sqlite3_exec(db,"delete from  vertical_set;",0,0,0);  ///竖曲线
    n=road_number_vertical(r);
    for(i=0; i<n; i++)
    {
        ve=road_vertical(r,i);
        if(i==n-1>0&&ve->type>4)
        {
            ve->type=4;
        }
        /*sprintf(cmd,"insert into vertical_set values(\
                %d,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%d,%.12f);",
                ve->type,ve->l1,ve->h1,ve->l2,ve->h2,
                ve->length,ve->radius,ve->angle1,ve->angle2,ve->pz,ve->deta);*////源代码

        sprintf(cmd,"insert into vertical_set values(\
                %d,%.12f,%.12f,%.12f,%.12f,\
                %.12f,%.12f,%.12f,%.12f,%d,%.12f);",
                ve->type,ve->l1,ve->h1,ve->l2,ve->h2,
                ve->length,ve->radius,ve->angle1,ve->angle2,ve->pz,ve->deta);
        sqlite3_exec(db,cmd,0,0,0);
    }

    sqlite3_exec(db,"delete from  hoff_set;",0,0,0);  ///平曲线偏移
    n=road_number_horizon_off(r);
    for(i=0; i<n; i++)
    {
        ho=road_horizon_off(r,i);
        sprintf(cmd,"insert into hoff_set values(%.12f,%.12f);",ho->mile,ho->off);
        sqlite3_exec(db,cmd,0,0,0);
    }

    sqlite3_exec(db,"delete from  voff_set;",0,0,0);  ///竖曲线偏移
    n=road_number_vertical_off(r);
    for(i=0; i<n; i++)
    {
        vo=road_vertical_off(r,i);
        sprintf(cmd,"insert into voff_set values(%.12f,%.12f);",vo->mile,vo->off);
        sqlite3_exec(db,cmd,0,0,0);
    }

    //whq添加
    sqlite3_exec(db,"delete from moff_set;",0,0,0);
    n=road_number_mile_off(r);
    for(i=0;i<n;i++)
    {
        mo=road_mile_off(r,i);
        sprintf(cmd,"insert into moff_set values(%.12f,%.12f);",mo->mile,mo->off);
        sqlite3_exec(db,cmd,0,0,0);
    }//添加结束

    sqlite3_exec(db,  "commit transaction;", 0, 0, 0);
    sqlite3_close(db);
    return 0;
}

int mtg_store_database(mtg_t* mtg,char *filename)
{
    int ret=0;
    MYSQL mysql;
    char cmd[1024];
//    FILE* fp=fopen("D:/mtg_import_db.log","w");

    lock(&mtg->dblock);
    mysql_init(&mysql);
    if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
    {
        sprintf(cmd,"mysqldump -uroot -p123 dba_laser --skip-lock-tables >\"%s\"",filename);
//        if(fp)
//        {
//            fprintf(fp,"%s\n",cmd);
//            fflush(fp);
//        }
        //ret=WinExec(cmd,SW_HIDE);
        //ret=WinExec(cmd,SW_SHOW);
        ret=system(cmd);
    }
    mysql_close(&mysql);
    unlock(&mtg->dblock);
//    if(fp)
//    {
//        fprintf(fp,"ret:%d\n",ret);
//        fflush(fp);
//        fclose(fp);
//    }

    return ret;
}

int mtg_store_recheck(mtg_t* mtg)
{
    int ret=0;
    MYSQL mysql;
    char cmd[1024];
    lock(&mtg->dblock);
    mysql_init(&mysql);
    if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
    {
        sprintf(cmd,"insert into recheck_set(iredta,tredta) values(%d,%ld)",
                mtg->recheck.idta,(long)(mtg->recheck.dta_t));
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            ret=1;
        }
    }
    mysql_close(&mysql);
    unlock(&mtg->dblock);
    return ret;
}

int mtg_store_inccheck(mtg_t* mtg)
{
    int ret=0;
    MYSQL mysql;
    char cmd[1024];
    lock(&mtg->dblock);
    mysql_init(&mysql);
    if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
    {
        sprintf(cmd,"insert into inccheck_set(contimes,daytimes,t) values(%d,%d,%ld)",
                mtg->inc_check.contimes,mtg->inc_check.daytimes,(long)mtg->inc_check.t);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            ret=1;
        }
    }
    mysql_close(&mysql);
    unlock(&mtg->dblock);
    return ret;
}

int mtg_store_overinfo(mtg_t* mtg,INC_OVERRUN* rec)
{
    int ret=0;
    MYSQL mysql;
    char cmd[1024];
    lock(&mtg->dblock);
    mysql_init(&mysql);
    if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
    {
        strcpy(cmd,"create table if not exists incover_set(\
               `id` int(11) NOT NULL AUTO_INCREMENT,\
               `t` int(11) DEFAULT 0,\
               `inc0_11` double DEFAULT NULL,\
               `inc0_12` double DEFAULT NULL,\
               `inc0_21` double DEFAULT NULL,\
               `inc0_22` double DEFAULT NULL,\
               `inc_11` double DEFAULT NULL,\
               `inc_12` double DEFAULT NULL,\
               `inc_21` double DEFAULT NULL,\
               `inc_22` double DEFAULT NULL,\
               `diff01` double DEFAULT NULL,\
               `diff02` double DEFAULT NULL,\
               `diff1` double DEFAULT NULL,\
               `diff2` double DEFAULT NULL,\
               PRIMARY KEY (`id`)\
               )");
        mysql_real_query(&mysql,cmd,strlen(cmd));

        sprintf(cmd,"insert into incover_set(t,inc0_11,inc0_12,inc0_21,inc0_22,inc_11,inc_12,inc_21,inc_22,diff01,diff02,diff1,diff2)\
                values(%ld,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f,%.12f)",
                (long)rec->t,rec->inc0_1[0],rec->inc0_1[1],rec->inc0_2[0],rec->inc0_2[1],rec->inc_1[0],rec->inc_1[1],
                rec->inc_2[0],rec->inc_2[1],rec->diff0[0],rec->diff0[1],rec->diff[0],rec->diff[1]);
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            ret=1;
        }
    }
    mysql_close(&mysql);
    unlock(&mtg->dblock);
    return ret;
}

int mtg_query_overinfo(mtg_t* mtg)
{
    MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[4096];
	INC_OVERRUN *rec;
	int i=0;
	int ret=0;
	int index=0;
	long t;

	lock(&mtg->dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,mtg->host,mtg->uid,mtg->psw,mtg->db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        sprintf(cmd,"select * from incover_set order by id desc");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            results = mysql_store_result(&mysql);
            ret=mysql_num_rows(results);
            mtg->nover=ret;
            rec=(INC_OVERRUN*)malloc(ret*sizeof(INC_OVERRUN));
            index=0;
            while((record = mysql_fetch_row(results)))
            {
                i=1;
                sscanf(record[i++],"%ld",&t);
                rec[index].t=t;
                sscanf(record[i++],"%lf",&rec[index].inc0_1[0]);
                sscanf(record[i++],"%lf",&rec[index].inc0_1[1]);
                sscanf(record[i++],"%lf",&rec[index].inc0_2[0]);
                sscanf(record[i++],"%lf",&rec[index].inc0_2[1]);
                sscanf(record[i++],"%lf",&rec[index].inc_1[0]);
                sscanf(record[i++],"%lf",&rec[index].inc_1[1]);
                sscanf(record[i++],"%lf",&rec[index].inc_2[0]);
                sscanf(record[i++],"%lf",&rec[index].inc_2[1]);
                sscanf(record[i++],"%lf",&rec[index].diff0[0]);
                sscanf(record[i++],"%lf",&rec[index].diff0[1]);
                sscanf(record[i++],"%lf",&rec[index].diff[0]);
                sscanf(record[i++],"%lf",&rec[index].diff[1]);
                index++;
            }
            mysql_free_result(results);
        }
	}
	mysql_close(&mysql);
	unlock(&mtg->dblock);

	if(index>0)
        mtg->incover=rec;

    return ret;
}
