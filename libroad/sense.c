#include "road.h"
#include "libele.h"
#include "hasp_api.h"
#include "hasp_vcode.h"

#include <stdio.h>
static int flag=0;

int ele_dosense()
{
    IO_PACKAGE input,output;
    time_t t1;
    char mac[4][13];
    int nMac=0;
    int bsense=0;
    int bi;

    nMac=GetMacAddress(mac,4);
    input.tag=CMD_GET_MACHINE_ID;
    input.len=12;
    time(&t1);
    srand(t1);

    for(bi=0;bi<12;bi++)
    {
        input.buff[bi]=rand() % 255;
    }
    if(DoSense("MEDO001","STGuider",&input,&output)==1)
    {
        //trace(0,"output=%s\n",output.buff);
        for(bi=0;bi<nMac;bi++)
        {
            if(strncmp(mac[bi],(const char*)output.buff,12)==0)
            {
                bsense=1;
                break;
            }
        }
    }

    if(!bsense&&flag==0)
    {
        input.tag=CMD_SET_MACHINE_ID;
        strncpy((char*)input.buff,mac[0],12);
        input.buff[12]=0;
        input.len=12;
        if(DoSense("MEDO001","STGuider",&input,&output)==1)
        {
            if(output.buff[0]==1)
            {
                bsense=1;
                flag=1;
            }
        }
    }
    return bsense;
}

int hasp_dosense1()
{
    hasp_status_t status;
    hasp_handle_t handle;
    hasp_time_t time;
    unsigned int day, month, year, hour, minute, second;
    status=hasp_login(173,(hasp_vendor_code_t *)vendor_code,&handle);
    if(status!=HASP_STATUS_OK)
    {
        return 0;
    }
    else
    {
        status=hasp_get_rtc(handle,&time);
        if(status==HASP_STATUS_OK)
        {
            status=hasp_hasptime_to_datetime(time,&day,&month,&year,&hour,&minute,&second);
            if(status!=HASP_STATUS_OK)
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    if(status==HASP_STATUS_OK)
        return 1;
    return 0;
}

int hasp_dosense(int id)
{
    hasp_status_t status;
    hasp_handle_t handle;
    hasp_time_t time;
    hasp_size_t memSize;
    int bsense=0;

    hasp_size_t offset = 0;
    hasp_size_t len = 48;
    unsigned char data[48];
    int i=0;
    char mac[4][13];
    char mac16[16];
    int nMac=0;
    ///20181023whq delete the file output
    ///20181105whq come back the file output and add the output before every return;
    FILE* fp=fopen("E://hasp_get_size.log","w");

    unsigned int day, month, year, hour, minute, second;
    //status=hasp_login(173,(hasp_vendor_code_t *)vendor_code,&handle);
    status=hasp_login(id,(hasp_vendor_code_t *)vendor_code,&handle);
    if(status!=HASP_STATUS_OK)
    {
        if(fp)
        {
            fprintf(fp,"status:%d",status);
            fflush(fp);
            fclose(fp);
            fp=NULL;
        }
        return 0;
    }
    else
    {
        status = hasp_read(handle, HASP_FILEID_RW, offset, len, data);
        //status=hasp_decrypt(handle,data,12);

        /* check if operation was successful */
        if (status != HASP_STATUS_OK)
        {
            hasp_logout(handle);
            if(fp)
            {
                fprintf(fp,"status:%d",status);
                fflush(fp);
                fclose(fp);
                fp=NULL;
            }
            return 0;
        }
        if(fp)
        {
            fprintf(fp,"hasp_read()  status:%d,data:%s\n",status,data);
            fflush(fp);
        }

        nMac=GetMacAddress(mac,4);
        if(fp)
        {
            for(i=0;i<nMac;i++)
            {
                fprintf(fp,"status:%d,n:%d,mac:%s\n",status,i,mac[i]);
                fflush(fp);
            }
        }
        for(i=0;i<nMac;i++)
        {
            if(strncmp(mac[i],(const char*)data,11)==0)
            {
                bsense=1;
                flag=1;
                break;
            }
        }
        if(!bsense&&strcmp((char*)data,"")==0&&flag==0)
        {
//            strncpy((char*)mac16,mac[0],12);
//            if(fp)
//            {
//                fprintf(fp,"hasp_encrypt origin : ");
//                fflush(fp);
//                for(i=0;i<16;i++)
//                {
//                    fprintf(fp,"%0x ",mac16[i]);
//                    fflush(fp);
//                }
//            }
            strncpy((char*)data,mac[0],12);
//            data[13]=0;
//            status=hasp_encrypt(handle,mac16,16);
//            if(fp)
//            {
//                fprintf(fp,"hasp_encrypt result: \n");
//                fflush(fp);
//                for(i=0;i<48;i++)
//                {
//                    if(i<12)
//                    data[i]=mac16[i]&0xff;
//                    else
//                        data[i]=0x00;
//                    //fprintf(fp,"%0x ",mac16[i]&0xff);
//                    fprintf(fp,"%0x ",data[i]);
//                    fflush(fp);
//                }
//            }
//
            status = hasp_write(handle, HASP_FILEID_RW, 0, len, data);
            if(fp)
            {
                fprintf(fp,"\nhasp_write()1  status:%d\n",status);
                fflush(fp);
            }

//            status = hasp_read(handle, HASP_FILEID_RW, 0, len, data);
//
//            if(fp)
//            {
//                fprintf(fp,"hasp_read()  status:%d,data:%s\n",status,data);
//                fflush(fp);
//            }
            if (status != HASP_STATUS_OK)
            {
                hasp_logout(handle);
                if(fp)
                {
                    fclose(fp);
                    fp=NULL;
                }
                return 0;
            }
            else
                bsense=1;
            if(fp)
            {
                fprintf(fp,"hasp_write()  status:%d\n",status);
                fflush(fp);
            }
        }
        hasp_logout(handle);
    }
    if(fp)
    {
        fclose(fp);
        fp=NULL;
    }

    return bsense;
}

int lock_sense(int type,int id)
{
    int ret=0;
    ///20181022whq add below for xi'an sixth company
    ///20181023whq delete below
    ///20181107whq add
    //type=0;
    if(type==0)
    {
        ret=ele_dosense();
    }
    else if(type==1)
    {
        ret=hasp_dosense(id);
    }
    return ret;
}
