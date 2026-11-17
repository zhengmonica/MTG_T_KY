#include "libmtg.h"
#include "geometry.h"
#include "libele.h"

#include <stdio.h>

#define PI  3.1415926535897932384626433832795

#define MTG_OPERA_INC      0x0001
#define MTG_OPERA_CAM      0x0010
#define MTG_OPERA_TPS      0x0100
#define MTG_OPERA_GESTURE  0x1000

static double pitchSurvey[10]={0};
static double pitchSort[10]={0};
static int nPitch=0;
static double rotateSurvey[10]={0};
static double rotateSort[10]={0};
static int nRotate=0;

static double pitchSurvey_v[1000]={0};
static double pitchSort_v[1000]={0};
static int nPitch_v=0;
static double rotateSurvey_v[1000]={0};
static double rotateSort_v[1000]={0};
static int nRotate_v=0;

static double pitchSurvey1[10]={0};
static double pitchSort1[10]={0};
static int nPitch1=0;
static double rotateSurvey1[10]={0};
static double rotateSort1[10]={0};
static int nRotate1=0;

static double pitchSurvey1_v[1000]={0};
static double pitchSort1_v[1000]={0};
static int nPitch1_v=0;
static double rotateSurvey1_v[1000]={0};
static double rotateSort1_v[1000]={0};
static int nRotate1_v=0;

static double pitchSurvey2_v[1000]={0};
static double pitchSort2_v[1000]={0};
static int nPitch2_v=0;
static double rotateSurvey2_v[1000]={0};
static double rotateSort2_v[1000]={0};
static int nRotate2_v=0;

///平滑倾斜仪数据
double AddPitch(double pitch)
{
    int i,j;
    double val=0.0;
    //val=pitch;
    if(nPitch<10)
    {
        pitchSurvey[nPitch]=pitch;
        nPitch++;
    }
    else  ///nPich==10
    {
       for(i=0;i<9;i++)
       {
           pitchSurvey[i]=pitchSurvey[i+1];
       }
       pitchSurvey[9]=pitch;
    }
    for(i=0;i<nPitch;i++) pitchSort[i]=pitchSurvey[i];
    ///排序找中位数
    for(i=nPitch-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(pitchSort[j]>pitchSort[j+1])
            {
                val=pitchSort[j];
                pitchSort[j]=pitchSort[j+1];
                pitchSort[j+1]=val;
            }
        }
    }
    if(nPitch % 2==0) ///偶数
    {
        i=nPitch/2;
        j=i-1;
        val=(pitchSort[i]+pitchSort[j])/2.0;
    }
    else
    {
        i=nPitch/2;
        val=pitchSort[i];
    }
    return val;
}

double AddRotate(double rotate)
{
    int i,j;
    double val=0.0;
    //val=rotate;
    if(nRotate<10)
    {
        rotateSurvey[nRotate]=rotate;
        nRotate++;
    }
    else  ///nPich==10
    {
       for(i=0;i<9;i++)
       {
           rotateSurvey[i]=rotateSurvey[i+1];
       }
       rotateSurvey[9]=rotate;
    }
    for(i=0;i<nRotate;i++) rotateSort[i]=rotateSurvey[i];
    ///排序找中位数
    for(i=nRotate-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(rotateSort[j]>rotateSort[j+1])
            {
                val=rotateSort[j];
                rotateSort[j]=rotateSort[j+1];
                rotateSort[j+1]=val;
            }
        }
    }
    if(nRotate % 2==0) ///偶数
    {
        i=nRotate/2;
        j=i-1;
        val=(rotateSort[i]+rotateSort[j])/2.0;
    }
    else
    {
        i=nRotate/2;
        val=rotateSort[i];
    }
    return val;
}

double AddPitch_vibration(double pitch,int time)
{
    int i,j;
    double val=0.0;

    if(nPitch_v<15*time)
    {
        pitchSurvey_v[nPitch_v]=pitch;
        nPitch_v++;
    }
    else  ///nPich==10
    {
       for(i=0;i<15*time-1;i++)
       {
           pitchSurvey_v[i]=pitchSurvey_v[i+1];
       }
       pitchSurvey_v[15*time-1]=pitch;
    }
    for(i=0;i<nPitch_v;i++) pitchSort_v[i]=pitchSurvey_v[i];
    ///排序
    for(i=nPitch_v-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(pitchSort_v[j]>pitchSort_v[j+1])
            {
                val=pitchSort_v[j];
                pitchSort_v[j]=pitchSort_v[j+1];
                pitchSort_v[j+1]=val;
            }
        }
    }

    for(i=1;i<nPitch_v-1;i++)
    {
        val+=pitchSort_v[i];
    }
    val=val/(nPitch_v-2);

    return val;
}

double AddRotate_vibration(double rotate,int time)
{
    int i,j;
    double val=0.0;
    //val=rotate;
    if(nRotate_v<15*time)
    {
        rotateSurvey_v[nRotate_v]=rotate;
        nRotate_v++;
    }
    else  ///nPich==10
    {
       for(i=0;i<15*time-1;i++)
       {
           rotateSurvey_v[i]=rotateSurvey_v[i+1];
       }
       rotateSurvey_v[15*time-1]=rotate;
    }
    for(i=0;i<nRotate_v;i++) rotateSort_v[i]=rotateSurvey_v[i];
    ///排序
    for(i=nRotate_v-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(rotateSort_v[j]>rotateSort_v[j+1])
            {
                val=rotateSort_v[j];
                rotateSort_v[j]=rotateSort_v[j+1];
                rotateSort_v[j+1]=val;
            }
        }
    }

    for(i=1;i<nRotate_v-1;i++)
    {
        val+=rotateSort_v[i];
    }
    val=val/(nRotate_v-2);

    return val;
}

///双倾斜
double AddPitch1(double pitch)
{
    int i,j;
    double val=0.0;
    //val=pitch;
    if(nPitch1<10)
    {
        pitchSurvey1[nPitch1]=pitch;
        nPitch1++;
    }
    else  ///nPich==10
    {
       for(i=0;i<9;i++)
       {
           pitchSurvey1[i]=pitchSurvey1[i+1];
       }
       pitchSurvey1[9]=pitch;
    }
    for(i=0;i<nPitch1;i++) pitchSort1[i]=pitchSurvey1[i];
    ///排序找中位数
    for(i=nPitch1-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(pitchSort1[j]>pitchSort1[j+1])
            {
                val=pitchSort1[j];
                pitchSort1[j]=pitchSort1[j+1];
                pitchSort1[j+1]=val;
            }
        }
    }
    if(nPitch1 % 2==0) ///偶数
    {
        i=nPitch1/2;
        j=i-1;
        val=(pitchSort1[i]+pitchSort1[j])/2.0;
    }
    else
    {
        i=nPitch1/2;
        val=pitchSort1[i];
    }
    return val;
}

double AddRotate1(double rotate)
{
    int i,j;
    double val=0.0;
    //val=rotate;
    if(nRotate1<10)
    {
        rotateSurvey1[nRotate1]=rotate;
        nRotate1++;
    }
    else  ///nPich==10
    {
       for(i=0;i<9;i++)
       {
           rotateSurvey1[i]=rotateSurvey1[i+1];
       }
       rotateSurvey1[9]=rotate;
    }
    for(i=0;i<nRotate1;i++) rotateSort1[i]=rotateSurvey1[i];
    ///排序找中位数
    for(i=nRotate1-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(rotateSort1[j]>rotateSort1[j+1])
            {
                val=rotateSort1[j];
                rotateSort1[j]=rotateSort1[j+1];
                rotateSort1[j+1]=val;
            }
        }
    }
    if(nRotate1 % 2==0) ///偶数
    {
        i=nRotate1/2;
        j=i-1;
        val=(rotateSort1[i]+rotateSort1[j])/2.0;
    }
    else
    {
        i=nRotate1/2;
        val=rotateSort1[i];
    }
    return val;
}

double AddPitch1_vibration(double pitch,int time)
{
    int i,j;
    double val=0.0;
    //val=pitch;
    if(nPitch1_v<10*time)
    {
        pitchSurvey1_v[nPitch1_v]=pitch;
        nPitch1_v++;
    }
    else  ///nPich==10
    {
       for(i=0;i<10*time-1;i++)
       {
           pitchSurvey1_v[i]=pitchSurvey1_v[i+1];
       }
       pitchSurvey1_v[10*time-1]=pitch;
    }
    for(i=0;i<nPitch1_v;i++) pitchSort1_v[i]=pitchSurvey1_v[i];
    ///排序找中位数
    for(i=nPitch1_v-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(pitchSort1_v[j]>pitchSort1_v[j+1])
            {
                val=pitchSort1_v[j];
                pitchSort1_v[j]=pitchSort1_v[j+1];
                pitchSort1_v[j+1]=val;
            }
        }
    }

    for(i=1;i<nPitch1_v-1;i++)
        val+=pitchSort1_v[i];
    val=val/(nPitch1_v-2);

    return val;
}

double AddRotate1_vibration(double rotate,int time)
{
    int i,j;
    double val=0.0;
    //val=rotate;
    if(nRotate1_v<10*time)
    {
        rotateSurvey1_v[nRotate1_v]=rotate;
        nRotate1_v++;
    }
    else  ///nPich==10
    {
       for(i=0;i<10*time-1;i++)
       {
           rotateSurvey1_v[i]=rotateSurvey1_v[i+1];
       }
       rotateSurvey1_v[10*time-1]=rotate;
    }
    for(i=0;i<nRotate1_v;i++) rotateSort1_v[i]=rotateSurvey1_v[i];
    ///排序找中位数
    for(i=nRotate1_v-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(rotateSort1_v[j]>rotateSort1_v[j+1])
            {
                val=rotateSort1_v[j];
                rotateSort1_v[j]=rotateSort1_v[j+1];
                rotateSort1_v[j+1]=val;
            }
        }
    }
    for(i=1;i<nRotate1_v-1;i++)
        val+=rotateSort1_v[i];
    val=val/(nRotate1_v-2);

    return val;
}

double AddPitch2_vibration(double pitch,int time)
{
    int i,j;
    double val=0.0;
    //val=pitch;
    if(nPitch2_v<10*time)
    {
        pitchSurvey2_v[nPitch2_v]=pitch;
        nPitch2_v++;
    }
    else  ///nPich==10
    {
       for(i=0;i<10*time-1;i++)
       {
           pitchSurvey2_v[i]=pitchSurvey2_v[i+1];
       }
       pitchSurvey2_v[10*time-1]=pitch;
    }
    for(i=0;i<nPitch2_v;i++) pitchSort2_v[i]=pitchSurvey2_v[i];
    ///排序找中位数
    for(i=nPitch2_v-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(pitchSort2_v[j]>pitchSort2_v[j+1])
            {
                val=pitchSort2_v[j];
                pitchSort2_v[j]=pitchSort2_v[j+1];
                pitchSort2_v[j+1]=val;
            }
        }
    }

    for(i=1;i<nPitch2_v-1;i++)
        val+=pitchSort2_v[i];
    val=val/(nPitch2_v-2);

    return val;
}

double AddRotate2_vibration(double rotate,int time)
{
    int i,j;
    double val=0.0;
    //val=rotate;
    if(nRotate2_v<10*time)
    {
        rotateSurvey2_v[nRotate2_v]=rotate;
        nRotate2_v++;
    }
    else  ///nPich==10
    {
       for(i=0;i<10*time-1;i++)
       {
           rotateSurvey2_v[i]=rotateSurvey2_v[i+1];
       }
       rotateSurvey2_v[10*time-1]=rotate;
    }
    for(i=0;i<nRotate2_v;i++) rotateSort2_v[i]=rotateSurvey2_v[i];
    ///排序找中位数
    for(i=nRotate2_v-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(rotateSort2_v[j]>rotateSort2_v[j+1])
            {
                val=rotateSort2_v[j];
                rotateSort2_v[j]=rotateSort2_v[j+1];
                rotateSort2_v[j+1]=val;
            }
        }
    }
    for(i=1;i<nRotate2_v-1;i++)
        val+=rotateSort2_v[i];
    val=val/(nRotate2_v-2);

    return val;
}

static int RBCDtoInt(char chl)
{
    int itl=(unsigned char)chl;
    return itl-=6*floor(itl/16.0);
}

//下面是CRC16 modbus校验算法，适用于任意长度的字符串
static unsigned char auchCRCHi[]={
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
};

static unsigned char auchCRCLo[]={
0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
0x43, 0x83, 0x41, 0x81, 0x80, 0x40
};

unsigned short CRC16(unsigned char* puchMsg, unsigned short usDataLen,char *out)
{
    unsigned char uchCRCHi = 0xFF ;
    unsigned char uchCRCLo = 0xFF ;
    unsigned char uIndex ;
    while (usDataLen--)
    {
    uIndex = uchCRCHi ^ *puchMsg++;
    uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex];
    uchCRCLo = auchCRCLo[uIndex];
    }
    out[1]=uchCRCLo%256;
    out[0]=uchCRCHi%256;
    return (uchCRCHi << 8 | uchCRCLo) ;
};

void send_char(char* buffer,int index)///发送继电器指令字符串
{
    //buffer[0]=0x01;
    buffer[0]=0x00+index;
    buffer[2]=0x00;
    buffer[1]=0x03;
    buffer[3]=0x02;
    buffer[4]=0x00;
    buffer[5]=0x04;
    buffer[8]=0x00;
}

///下面是增加小倾斜仪的线程，暂时规定 mtg->tarset.inc=2为小倾斜仪，待商定
#ifdef WIN32
static DWORD WINAPI _incthread(void* arg)
#else
static void *_incthread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int inclen=0;
    char incbuf[1024]={0};
    char incword[1024]={0};
    int i,j,k;
    int nword=0;
    char* ptr=0;
    double dinc=0.0;
    int tickinc1=0,tickinc2=0,tickinc3=0,tickinc4=0;
    time_t now;
    unsigned char chal=0;
    double rlt=0.0;
    unsigned char output[16];
    int length=11;

    time_t t=0;
	char path[1024]={0};
	char strFull[1024]={0};
	double incx1=0.0,incx2=0.0,incy1=0.0,incy2=0.0;
	unsigned int tick=0;
	unsigned char cmd[256];
	char timestr[256];
	INC_OVERRUN overinfo;

	FILE* fp=NULL;
	///fp=fopen("D:\\midu\\incthread.log","w");

    mtg=(mtg_t*)arg;

    if(mtg->m0.t1>0)
    {
        incx1=mtg->m0.inc[5]-mtg->m0.inc[0];
        incy1=mtg->m0.inc[6]-mtg->m0.inc[1];
    }
	///20171122whq增加，使倾斜仪的类型强制为小的瑞芬倾斜仪，量程10°
    //mtg->tarset.inc=2;

    while(mtg->iinc==1 && mtg->tarset.incdb==0)
    {
        tickinc1=mtg->tickinc1;
        tickinc2=mtg->tickinc2;
        ///倾斜仪数据
        inclen+=strsvrpeek(&mtg->incsvr,(unsigned char*)(incbuf+inclen),1023-inclen);
        incbuf[inclen]=0;

        ///瑞芬倾斜仪
        if(mtg->tarset.inc==0)
        {
            for(i=0;i<inclen-1;i++)
            {
                if((unsigned char)incbuf[i]==0x68 && (unsigned char)incbuf[i+1]==0x0D && inclen-i>=14)
                {
                    memcpy(incword,incbuf+i,inclen-i);
                    inclen-=(i+14);
                    memmove(incbuf,incbuf+i+14,inclen);
                    chal=0;
                    for(k=1;k<13;k++)
                    {
                        chal+=(unsigned char)incword[k];
                    }

                    if((unsigned char)chal==(unsigned char)incword[13])
                    {
                        rlt=RBCDtoInt(incword[4])%10*100.0+RBCDtoInt(incword[5])+RBCDtoInt(incword[6])/100.0;
                        if(RBCDtoInt(incword[4])>=10) rlt=-rlt;

                        lock(&mtg->inclock);
                        if(mtg->iset.vibration==0)
                        {
                            if(mtg->tarset.ver==0)
                            {
                                if(fp)
                                {
                                    fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                }
                                mtg->m1.inc[1]=AddPitch(rlt/10.0);
                            }
                            else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                            {
                                if(fp)
                                {
                                    fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                }
                                mtg->m1.inc[0]=AddRotate(-rlt/10.0);
                                mtg_is_driving(mtg,-rlt/10.0);
                            }
                        }
                        else
                        {
                            if(mtg->tarset.ver==0)
                            {
                                if(fp)
                                {
                                    fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                }
                                mtg->m1.inc[1]=AddPitch_vibration(rlt/10.0,mtg->SmoothTime);
                            }
                            else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                            {
                                if(fp)
                                {
                                    fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                }
                                mtg->m1.inc[0]=AddRotate_vibration(-rlt/10.0,mtg->SmoothTime);
                                mtg_is_driving(mtg,-rlt/10.0);
                            }
                        }
                        unlock(&mtg->inclock);
                        tickinc2++;
                        rlt=RBCDtoInt(incword[7])%10*100.0+RBCDtoInt(incword[8])+RBCDtoInt(incword[9])/100.0;
                        if(RBCDtoInt(incword[7])>=10) rlt=-rlt;
                        lock(&mtg->inclock);
                        if(mtg->iset.vibration==0)
                        {
                            if(mtg->tarset.ver==0)
                            {
                                if(fp)
                                {
                                    fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                }
                                mtg->m1.inc[0]=AddRotate(-rlt/10.0);
                                mtg_is_driving(mtg,-rlt/10.0);
                            }
                            else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                            {
                                if(fp)
                                {
                                    fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                }
                                mtg->m1.inc[1]=AddPitch(-rlt/10.0);
                            }
                        }
                        else
                        {
                            if(mtg->tarset.ver==0)
                            {
                                if(fp)
                                {
                                    fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                }
                                mtg->m1.inc[0]=AddRotate_vibration(-rlt/10.0,mtg->SmoothTime);
                                mtg_is_driving(mtg,-rlt/10.0);
                            }
                            else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                            {
                                if(fp)
                                {
                                    fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                }
                                mtg->m1.inc[1]=AddPitch_vibration(-rlt/10.0,mtg->SmoothTime);
                            }
                        }
                        unlock(&mtg->inclock);
                        tickinc1++;
                    }
                    if(tickinc1>0 && tickinc2>0)
                    {
                        //time(&now);
                        //mtg->m.t2=now;
                        mtg_tbm_incline(mtg);
                        break;
                    }
                }
            }
        }
        else if(mtg->tarset.inc==1)
        {
            for(i=0;i<inclen;i++)
            {
                if(incbuf[i]=='\n')
                {
                    memcpy(incword,incbuf,i+1);
                    incword[i+1]=0;
                    nword=i+1;
                    inclen-=(i+1);
                    memmove(incbuf,incbuf+i+1,inclen);
                    //trace(0,"incword=%s\n",incword);
                    ptr=strstr(incword,"X=");
                    if(ptr && sscanf(ptr,"X=%lf",&dinc))
                    {
                        if(fp)
                        {
                            fprintf(fp,"pitch:%.6f\n",dinc);fflush(fp);
                        }
                        lock(&mtg->inclock);
                        if(mtg->iset.vibration==0)
                            mtg->m1.inc[1]=AddPitch(-dinc);
                        else
                            mtg->m1.inc[1]=AddPitch_vibration(-dinc,mtg->SmoothTime);
                        unlock(&mtg->inclock);
                        tickinc2++;
                    }
                    ptr=strstr(incword,"Y=");
                    if(sscanf(incword,"Y=%lf",&dinc))
                    {
                        if(fp)
                        {
                            fprintf(fp,"roll:%.6f\n",dinc);fflush(fp);
                        }
                        lock(&mtg->inclock);
                        if(mtg->iset.vibration==0)
                            mtg->m1.inc[0]=AddRotate(-dinc);
                        else
                            mtg->m1.inc[0]=AddRotate_vibration(-dinc,mtg->SmoothTime);
                        mtg_is_driving(mtg,-dinc);
                        unlock(&mtg->inclock);
                        tickinc1++;
                    }
                    if(tickinc1>0 && tickinc2>0)
                    {
                        //time(&now);
                        //mtg->m.t2=now;

                        mtg_tbm_incline(mtg);
                    }
                    i=-1;
                }
            }
        }
        else if(mtg->tarset.inc==2)///小倾斜仪
        {
            ///20210121ws add 为了连接应答模式的726倾斜仪
//            send_char(cmd,1);      ///
//            CRC16((unsigned char*)cmd,6,(char*)output);     ///
//            cmd[6]=(unsigned char)(output[0]);      ///
//            cmd[7]=(unsigned char)(output[1]);      ///
//            strsvrput(&mtg->incsvr,cmd,8);          ///
//            tick=tickget();                         ///
//            inclen=0;                               ///
//            while(tickget()-tick<2000)              ///
//            {
//                inclen+=strsvrpeek(&mtg->incsvr,(unsigned char*)(incbuf+inclen),1023-inclen);       ///
//                incbuf[inclen]=0;           ///
                for(i=0;i<inclen-1;i++)
                {
                    if((unsigned char)incbuf[i]==0x01 && (unsigned char)incbuf[i+1]==0x03 && ((unsigned char)incbuf[i+2]==0x08 && inclen-i>=13))
                    {
                        memcpy(incword,incbuf+i,inclen-i);
                        inclen-=(i+13);
                        memmove(incbuf,incbuf+i+13,inclen);
                        CRC16((unsigned char*)incbuf,(unsigned short)length,(char*)output);
                        if((unsigned char)incbuf[i+11]==(unsigned char)output[0] && (unsigned char)incbuf[i+12]==(unsigned char)output[1])
                        {
                            rlt=((unsigned char)incbuf[i+6]*256*256*256+(unsigned char)incbuf[i+5]*256*256+(unsigned char)incbuf[i+4]*256+(unsigned char)incbuf[i+3]-90000)*0.001;
                            lock(&mtg->inclock);
                            if(mtg->iset.vibration==0)
                            {
                                if(mtg->tarset.ver==0)
                                {
                                    if(fp)
                                    {
                                        fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                    }
                                    mtg->m1.inc[1]=AddPitch(rlt);
                                }
                                else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                                {
                                    if(fp)
                                    {
                                        fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                    }
                                    mtg->m1.inc[0]=AddRotate(-rlt);
                                    mtg_is_driving(mtg,-rlt);
                                }
                            }
                            else
                            {
                                if(mtg->tarset.ver==0)
                                {
                                    if(fp)
                                    {
                                        fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                    }
                                    mtg->m1.inc[1]=AddPitch_vibration(rlt,mtg->SmoothTime);
                                }
                                else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                                {
                                    if(fp)
                                    {
                                        fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                    }
                                    mtg->m1.inc[0]=AddRotate_vibration(-rlt,mtg->SmoothTime);
                                    mtg_is_driving(mtg,-rlt);
                                }
                            }
                            unlock(&mtg->inclock);
                            tickinc2++;

                            rlt=((unsigned char)incbuf[i+10]*256*256*256+(unsigned char)incbuf[i+9]*256*256+(unsigned char)incbuf[i+8]*256+(unsigned char)incbuf[i+7]-90000)*0.001;

                            lock(&mtg->inclock);
                            if(mtg->iset.vibration==0)
                            {
                                if(mtg->tarset.ver==0)
                                {
                                    if(fp)
                                    {
                                        fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                    }
                                    mtg->m1.inc[0]=AddRotate(-rlt);
                                    mtg_is_driving(mtg,-rlt);
                                }
                                else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                                {
                                    if(fp)
                                    {
                                        fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                    }
                                    mtg->m1.inc[1]=AddPitch(-rlt);
                                }
                            }
                            else
                            {
                                if(mtg->tarset.ver==0)
                                {
                                    if(fp)
                                    {
                                        fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                    }
                                    mtg->m1.inc[0]=AddRotate_vibration(-rlt,mtg->SmoothTime);
                                    mtg_is_driving(mtg,-rlt);
                                }
                                else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                                {
                                    if(fp)
                                    {
                                        fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                    }
                                    mtg->m1.inc[1]=AddPitch_vibration(-rlt,mtg->SmoothTime);
                                }
                            }
                            unlock(&mtg->inclock);
                            tickinc1++;
                        }
                        if(tickinc1>0 && tickinc2>0)
                        {
                            mtg_tbm_incline(mtg);

                            break;
                        }
                    }
                }
//            }   ///

        }
        mtg->tickinc1=tickinc1;
        mtg->tickinc2=tickinc2;
        sleepms(10);
    }

    while(mtg->iinc && mtg->tarset.incdb)
    {
        if((mtg->opera & MTG_OPERA_INC) || mtg->incstat)
        {
            tickinc1=mtg->tickinc1;
            tickinc2=mtg->tickinc2;
            tickinc3=mtg->tickinc3;
            tickinc4=mtg->tickinc4;
            ///倾斜仪数据
            //tickinc3=ticninc4=0;
            send_char(cmd,2);
            CRC16((unsigned char*)cmd,6,(char*)output);
            cmd[6]=(unsigned char)(output[0]);
            cmd[7]=(unsigned char)(output[1]);
            if(fp)
            {
                time(&t);
                strftime(timestr,64,"one send:%Y-%m-%d %H:%M:%S",localtime(&t));
                fprintf(fp,"%s, %ld\n",timestr,t);
                fflush(fp);
            }
            strsvrput(&mtg->incsvr,cmd,8);
            tick=tickget();
            inclen=0;
            if(fp)
            {
                fprintf(fp,"tickinc1:%d,%d,%d,%d\n",tickinc1,tickinc2,tickinc3,tickinc4);fflush(fp);
            }
            while(tickget()-tick<2000)
            {
                inclen+=strsvrpeek(&mtg->incsvr,(unsigned char*)(incbuf+inclen),1023-inclen);
                incbuf[inclen]=0;
                ///瑞芬倾斜仪
                if(mtg->tarset.inc==2)///小倾斜仪
                {
                    for(i=0;i<inclen-1;i++)
                    {
                        if((unsigned char)incbuf[i]==0x02 && (unsigned char)incbuf[i+1]==0x03 && ((unsigned char)incbuf[i+2]==0x08 && inclen-i>=13))
                        {
                            memcpy(incword,incbuf+i,inclen-i);
                            inclen-=(i+13);
                            memmove(incbuf,incbuf+i+13,inclen);
                            CRC16((unsigned char*)incbuf,(unsigned short)length,(char*)output);
                            if((unsigned char)incbuf[i+11]==(unsigned char)output[0] && (unsigned char)incbuf[i+12]==(unsigned char)output[1])
                            {
                                rlt=((unsigned char)incbuf[i+6]*256*256*256+(unsigned char)incbuf[i+5]*256*256+(unsigned char)incbuf[i+4]*256+(unsigned char)incbuf[i+3]-90000)*0.001;
                                if(fp)
                                {
                                    fprintf(fp,"roll2:%.6f\n",rlt);fflush(fp);
                                }
                                lock(&mtg->inclock);
                                if(mtg->iset.vibration==0)
                                {
                                    if(mtg->incstat)
                                        mtg->m1.inc[5]=-rlt;
                                    else
                                        mtg->m1.inc[5]=AddRotate1(-rlt);
                                }
                                else
                                {
                                    if(mtg->incstat)
                                        mtg->m1.inc[5]=-rlt;
                                    else
                                        mtg->m1.inc[5]=AddRotate1_vibration(-rlt,mtg->SmoothTime);
                                }
                                mtg_is_driving(mtg,rlt);

                                unlock(&mtg->inclock);
                                tickinc4++;

                                rlt=((unsigned char)incbuf[i+10]*256*256*256+(unsigned char)incbuf[i+9]*256*256+(unsigned char)incbuf[i+8]*256+(unsigned char)incbuf[i+7]-90000)*0.001;
                                if(fp)
                                {
                                    fprintf(fp,"pitch2:%.6f\n",rlt);fflush(fp);
                                }
                                lock(&mtg->inclock);
                                if(mtg->iset.vibration==0)
                                {
                                    if(mtg->incstat)
                                        mtg->m1.inc[6]=-rlt;
                                    else
                                        mtg->m1.inc[6]=AddPitch1(-rlt);
                                }
                                else
                                {
                                    if(mtg->incstat)
                                        mtg->m1.inc[6]=-rlt;
                                    else
                                        mtg->m1.inc[6]=AddPitch1_vibration(-rlt,mtg->SmoothTime);
                                }
                                unlock(&mtg->inclock);
                                tickinc3++;
                            }
                            if(tickinc3>mtg->tickinc3 && tickinc4>mtg->tickinc4)
                            {
                                if(fp)
                                {
                                    time(&t);
                                    strftime(timestr,64,"one getok:%Y-%m-%d %H:%M:%S",localtime(&t));
                                    fprintf(fp,"%s, %ld\n",timestr,t);
                                    fflush(fp);
                                }
                                //mtg_tbm_incline(mtg);
                                time(&now);
                                mtg->m1.t5=now;

                                if(mtg->tarset.baseinc==1)
                                {
                                    mtg_tbm_incline(mtg);
                                }
                                break;
                            }
                        }
                    }
                    if(tickinc3>mtg->tickinc3 && tickinc4>mtg->tickinc4)
                    {
                        break;
                    }
                }
                sleepms(10);
            }

            ///倾斜仪数据
            send_char(cmd,1);
            CRC16((unsigned char*)cmd,6,(char*)output);
            cmd[6]=(unsigned char)(output[0]);
            cmd[7]=(unsigned char)(output[1]);
            if(fp)
            {
                time(&t);
                strftime(timestr,64,"two send:%Y-%m-%d %H:%M:%S",localtime(&t));
                fprintf(fp,"%s, %ld\n",timestr,t);
                fflush(fp);
            }
            strsvrput(&mtg->incsvr,cmd,8);
            tick=tickget();
            inclen=0;
            while(tickget()-tick<2000)
            {
                inclen+=strsvrpeek(&mtg->incsvr,(unsigned char*)(incbuf+inclen),1023-inclen);
                incbuf[inclen]=0;
                //瑞芬倾斜仪
                if(mtg->tarset.inc==2)///小倾斜仪
                {
                    for(i=0;i<inclen-1;i++)
                    {
                        if((unsigned char)incbuf[i]==0x01 && (unsigned char)incbuf[i+1]==0x03 && ((unsigned char)incbuf[i+2]==0x08 && inclen-i>=13))
                        {
                            memcpy(incword,incbuf+i,inclen-i);
                            inclen-=(i+13);
                            memmove(incbuf,incbuf+i+13,inclen);
                            CRC16((unsigned char*)incbuf,(unsigned short)length,(char*)output);
                            if((unsigned char)incbuf[i+11]==(unsigned char)output[0] && (unsigned char)incbuf[i+12]==(unsigned char)output[1])
                            {
                                rlt=((unsigned char)incbuf[i+6]*256*256*256+(unsigned char)incbuf[i+5]*256*256+(unsigned char)incbuf[i+4]*256+(unsigned char)incbuf[i+3]-90000)*0.001;
                                lock(&mtg->inclock);
                                if(mtg->iset.vibration==0)
                                {
                                    if(mtg->tarset.ver==0)
                                    {
                                        if(fp)
                                        {
                                            fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                        }
                                        mtg->m1.inc[1]=AddPitch(-rlt);
                                    }
                                    else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                                    {
                                        if(fp)
                                        {
                                            fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                        }
                                        mtg->m1.inc[0]=AddRotate(rlt);
                                        mtg_is_driving(mtg,rlt);
                                    }
                                }
                                else
                                {
                                    if(mtg->tarset.ver==0)
                                    {
                                        if(fp)
                                        {
                                            fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                        }
                                        mtg->m1.inc[1]=AddPitch2_vibration(-rlt,mtg->SmoothTime);
                                    }
                                    else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                                    {
                                        if(fp)
                                        {
                                            fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                        }
                                        mtg->m1.inc[0]=AddRotate2_vibration(rlt,mtg->SmoothTime);
                                        mtg_is_driving(mtg,rlt);
                                    }
                                }
                                unlock(&mtg->inclock);
                                tickinc2++;

                                rlt=((unsigned char)incbuf[i+10]*256*256*256+(unsigned char)incbuf[i+9]*256*256+(unsigned char)incbuf[i+8]*256+(unsigned char)incbuf[i+7]-90000)*0.001;

                                lock(&mtg->inclock);
                                if(mtg->iset.vibration==0)
                                {
                                    if(mtg->tarset.ver==0)
                                    {
                                        if(fp)
                                        {
                                            fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                        }
                                        mtg->m1.inc[0]=AddRotate(rlt);
                                        mtg_is_driving(mtg,rlt);
                                    }
                                    else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                                    {
                                        if(fp)
                                        {
                                            fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                        }
                                        mtg->m1.inc[1]=AddPitch(rlt);
                                    }
                                }
                                else
                                {
                                    if(mtg->tarset.ver==0)
                                    {
                                        if(fp)
                                        {
                                            fprintf(fp,"roll:%.6f\n",rlt);fflush(fp);
                                        }
                                        mtg->m1.inc[0]=AddRotate2_vibration(rlt,mtg->SmoothTime);
                                        mtg_is_driving(mtg,rlt);
                                    }
                                    else if(mtg->tarset.ver==1 || mtg->tarset.ver==2)
                                    {
                                        if(fp)
                                        {
                                            fprintf(fp,"pitch:%.6f\n",rlt);fflush(fp);
                                        }
                                        mtg->m1.inc[1]=AddPitch2_vibration(rlt,mtg->SmoothTime);
                                    }
                                }
                                unlock(&mtg->inclock);
                                tickinc1++;
                            }
                            if(tickinc1>mtg->tickinc1 && tickinc2>mtg->tickinc2)
                            {
                                if(fp)
                                {
                                    time(&t);
                                    strftime(timestr,64,"two getok:%Y-%m-%d %H:%M:%S",localtime(&t));
                                    fprintf(fp,"%s, %ld\n",timestr,t);
                                    fflush(fp);
                                }
                                time(&now);
                                mtg->m1.t2=now;
                                if(mtg->tarset.baseinc==0)
                                {
                                    mtg_tbm_incline(mtg);
                                }
                                break;
                            }
                        }
                    }

                    if(tickinc1>mtg->tickinc1 && tickinc2>mtg->tickinc2)
                    {
                        break;
                    }
                }
                sleepms(10);
            }
            if(fp)
            {
                fprintf(fp,"000 incx2:,incx1:,incy2:,incy1:\n");
                fprintf(fp,"tickinc2:%d,%d,%d,%d\n",tickinc1,tickinc2,tickinc3,tickinc4);fflush(fp);
                fflush(fp);
            }
            //if(tickinc1>mtg->tickinc1 && tickinc2>mtg->tickinc2 && tickinc3>mtg->tickinc3 && tickinc4>mtg->tickinc4)
            if(((mtg->tarset.baseinc==0 && tickinc1>mtg->tickinc1 && tickinc2>mtg->tickinc2) || mtg->tarset.baseinc==1) && tickinc3>mtg->tickinc3 && tickinc4>mtg->tickinc4)
            {
                if(fp)
                {
                    fprintf(fp,"tickinc3:%d,%d,%d,%d\n",tickinc1,tickinc2,tickinc3,tickinc4);fflush(fp);
                    fprintf(fp,"tickinc4:%d,%d,%d,%d\n",mtg->tickinc1,mtg->tickinc2,mtg->tickinc3,mtg->tickinc4);fflush(fp);
                    fflush(fp);
                }
                incx2=mtg->m1.inc[5]-mtg->m1.inc[0];
                incy2=mtg->m1.inc[6]-mtg->m1.inc[1];
                mtg->m.inc[5]=mtg->m1.inc[5];
                mtg->m.inc[6]=mtg->m1.inc[6];
                mtg->m.inc[0]=mtg->m1.inc[0];
                mtg->m.inc[1]=mtg->m1.inc[1];
                mtg->m.t2=mtg->m1.t2;
                mtg->m.t5=mtg->m1.t5;
                if(mtg->incstat)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_GET_INCLINE);
                }
                if(mtg->m0.t1>0&&mtg->tarset.baseinc==0)
                {
                    if(fp)
                    {
                        //fprintf(fp,"incx2:,incx1:,incy2:,incy1:\n");
                        fprintf(fp,"incx2:%.4f,incx1:%.4f,incy2:%.4f,incy1:%.4f\n",incx2,incx1,incy2,incy1);
                        fflush(fp);
                    }
                    if(fabs(incx2-incx1)>mtg->tarset.angalw || fabs(incy2-incy1)>mtg->tarset.angalw)
                    {
                        if(mtg->tarset.stopped==0)
                        {
                            mtg->inc_check.contimes++;
                            mtg->inc_check.daytimes++;
                            time(&mtg->inc_check.t);
                            mtg_store_inccheck(mtg);

                            if(fp)
                            {
                                fprintf(fp,"inc0:%.4f,inc1:%.4f,inc5:%.4f,inc6:%4f\n");fflush(fp);
                                fprintf(fp,"incx2:%.4f,incx1:%.4f,incy2:%.4f,incy1:%.4f\n",incx2,incx1,incy2,incy1);
                                fprintf(fp,"dtsalw:%d,ctsalw:%d,daytimes:%d,contimes:%d\n",mtg->tarset.dtsalw,mtg->tarset.ctsalw,mtg->inc_check.daytimes,mtg->inc_check.contimes);
                                fflush(fp);
                            }

                            ///20210326 ws add 判断角度是否异常，若异常则保存角度信息
//                            if(mtg->plc.drive)
//                            {
//                                time(&overinfo.t);
//                                overinfo.inc0_1[0]=mtg->m0.inc[0];
//                                overinfo.inc0_1[1]=mtg->m0.inc[1];
//                                overinfo.inc0_2[0]=mtg->m0.inc[5];
//                                overinfo.inc0_2[1]=mtg->m0.inc[6];
//                                overinfo.inc_1[0]=mtg->m1.inc[0];
//                                overinfo.inc_1[1]=mtg->m1.inc[1];
//                                overinfo.inc_2[0]=mtg->m1.inc[5];
//                                overinfo.inc_2[1]=mtg->m1.inc[6];
//                                overinfo.diff0[0]=incx1;
//                                overinfo.diff0[1]=incy1;
//                                overinfo.diff[0]=incx2;
//                                overinfo.diff[1]=incy2;
//                                mtg_store_overinfo(mtg,&overinfo);
//                            }///20220927whq delete

                            ///20191211 暂时注释，不判断是否角度异常
//                            if(mtg->inc_check.daytimes>mtg->tarset.dtsalw||mtg->inc_check.contimes>mtg->tarset.ctsalw)
//                            {
//                                mtg->ierr[10]=1;
//                                if(!mtg->tarset.stopped)
//                                {
//                                    if(mtg->thread)
//                                        mtg_stop(mtg);
//                                    mtg_log(mtg,MTG_LOG_INC_OUT);
//                                    mtg->tarset.stopped=1;
//                                    mtg_store_tars(mtg);
//                                }
//                            }
                        }
                    }
                    else
                    {
                        mtg->inc_check.contimes=0;
                        mtg_store_inccheck(mtg);
                    }
                }
                if(mtg->ithread!=MTG_THREAD_CYCLE&&mtg->ithread!=MTG_THREAD_ORIGIN)
                {
                    //mtg_log(mtg,MTG_LOG_FINISH_GET_INCLINE);
                    tickinc1=tickinc2=tickinc3=tickinc4=0;
                    if(fp)
                    {
                        fprintf(fp,"mtg->ithread\n");fflush(fp);
                    }
                }
            }
            else
            {
                if(mtg->ithread!=MTG_THREAD_CYCLE&&mtg->ithread!=MTG_THREAD_ORIGIN)
                {
                    tickinc1=tickinc2=tickinc3=tickinc4=0;
                }
            }

            mtg->tickinc1=tickinc1;
            mtg->tickinc2=tickinc2;
            mtg->tickinc3=tickinc3;
            mtg->tickinc4=tickinc4;
        }

        sleepms(100);
    }
    if(fp)
        fclose(fp);

    mtg->incthread=0;

    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtgthread(void* arg)
#else
static void *_mtgthread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int istep=0;

    double cam[3];
    time_t now;
    int opera=0,rc=0;
    int tickcam1=0,tickcam2=0,ticktps=0;
    unsigned int tickcycle=0,ticknow=0,tickback=0;
    int bc=1;
    int fail=0;
    double dx,dy,dz,dh,dv,dl;
    int timeout=30000;
    unsigned int tickwait=0,tickpower=0;
    double laserheight=0.0;
    double laserx=0.0,lasery=0.0;
    double ori,ver,dist;
    int opts[5]={90000,1000,100,4096,100};
    char path[260],dbpath[1024];
    time_t t;
    int tickinc=0;
    double tpshz=0.0;
    FILE* fp=fopen("D:\\midu\\mtg_thread.log","w");

    mtg=(mtg_t*)arg;
    mtg_log(mtg,MTG_LOG_START_CYCLE);

    mtg->fmain=fopen(mtg->pmain,"w");
    sprintf(dbpath,"D:\\midu\\dc_meas.db");

    laserheight=mtg->tps.laserheight;

    if(mtg->tps.lasertype==0)
    {
        if(mtg->tps.laserdist[0]>1.0e-6)
        {
            laserx=atan(mtg->tps.laserx[0]/mtg->tps.laserdist[0]);
            lasery=atan(mtg->tps.lasery[0]/mtg->tps.laserdist[0]);
        }
    }
    else if(mtg->tps.lasertype==1)
    {
        if(mtg->tps.laserdist[1]>1.0e-6)
        {
            laserx=atan(mtg->tps.laserx[1]/mtg->tps.laserdist[1]);
            lasery=atan(mtg->tps.lasery[1]/mtg->tps.laserdist[1]);
        }
    }
    if(mtg->fmain)
    {
        fprintf(mtg->fmain,"%%R1P,%d,%d,%.4f,%.4f,%.4f\n",0,mtg->tps.lasertype,laserheight,laserx,lasery);
        fflush(mtg->fmain);
    }
    mtg->stat=1;
    mtg->opera=MTG_OPERA_TPS|MTG_OPERA_INC;
    mtg->tickinc1=mtg->tickinc2=mtg->tickinc3=mtg->tickinc4=0;
    mtg->camsvr.cams[0].ret=-2;

    bc=1;
    istep=0;
    mtg->incycle=1;
    while(mtg->stat)
    {
        ///相机
        if(mtg->opera & MTG_OPERA_CAM)
        {
            if(camsvr_peek(&mtg->camsvr,0,0,cam,&now))
            {
                mtg->m.cam[0]=cam[0];
                mtg->m.cam[1]=cam[1];
                mtg->m.cam[2]=cam[2];
                mtg->m.inc[0] = mtg->m1.inc[0];
                mtg->m.inc[1] = mtg->m1.inc[1];
                mtg->m.inc[5] = mtg->m1.inc[5];
                mtg->m.inc[6] = mtg->m1.inc[6];
                mtg->m.t1=now;
                time(&now);
                mtg->m.t2=mtg->m1.t2;
                mtg->m.t5=mtg->m1.t5;
                mtg_laser_incline(mtg);
                tickcam1++;
                if(mtg->fmain)
                {
                    fprintf(mtg->fmain,"%%R1P,%d,%.4f,%.4f,%.4f\n",1,cam[0],cam[1],cam[2]);
                    fflush(mtg->fmain);
                }
            }
        }

        ///
        if(mtg->opera & MTG_OPERA_TPS)
        {
            if(istep==0)
            {
                if(mtg->tarset.cam==1)
                {
                    if(camsvr_dh_start(&mtg->camsvr,10))
                    {
                        mtg_log(mtg,MTG_LOG_CAMERA_READY);
                    }
                }
                else if(mtg->tarset.cam==0)
                {
                    if(camsvr_bm_start(&mtg->camsvr,10))
                    {
                        mtg_log(mtg,MTG_LOG_CAMERA_READY);
                    }
                }

                if(mtg->fmain)
                {
                    fprintf(mtg->fmain,"%%R1P,%d,%d\n",2,mtg->tarset.cam);
                    fflush(mtg->fmain);
                }

                if(mtg->ithread==MTG_THREAD_CYCLE)
                {
                    mtg->run = 1;
                    if(bc && mtg->iset.backflag==1) ///转向后视   若选择后视检核才进行检核
                    {
                        dx=mtg->istn.backx-mtg->istn.statx;
                        dy=mtg->istn.backy-mtg->istn.staty;
                        dz=mtg->istn.backz+mtg->istn.backh-mtg->istn.statz-mtg->istn.stath;
                        dh=atan2(dy,dx);
                        //if(dh<0) dh+=2*PI;
                        //if(dh>2*PI) dh-=2*PI;
                        dh=dh-mtg->istn.anglediff;
                        //if(dh<0) dh+=2*PI;
                        //if(dh>2*PI) dh-=2*PI;

                        dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                        dv=PI/2-atan(dz/dl);
                        if(tps_make_position(&mtg->tps,dh,dv)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_BACKSIGHT);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                            fail=1;
                        }
                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.7f,%.7f\n",3,dh,dv);
                            fflush(mtg->fmain);
                        }
                    }
                    else  ///转向激光耙小棱镜
                    {
                        istep=6;
                        dx=mtg->m1.prism[0]-mtg->istn.statx;
                        dy=mtg->m1.prism[1]-mtg->istn.staty;
                        dz=mtg->m1.prism[2]-mtg->istn.statz-mtg->istn.stath;
                        dh=atan2(dy,dx);
                        //if(dh<0) dh+=2*PI;
                        //if(dh>2*PI) dh-=2*PI;
                        //天宝全站仪
                        dh=dh-mtg->istn.anglediff;
                        //if(dh<0) dh+=2*PI;
                        //if(dh>2*PI) dh-=2*PI;

                        dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                        dv=PI/2-atan(dz/dl);
                        if(tps_make_position(&mtg->tps,dh,dv)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                            fail=1;
                        }

                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.7f,%.7f\n",4,dh,dv);
                            fflush(mtg->fmain);
                        }
                    }
                }
                else if(mtg->ithread==MTG_THREAD_ORIGIN)   ///照准激光耙小棱镜
                {
                    istep=7;

                    ///ȷ׼ǰ
                    if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                        fail=1;
                    }
                }
            }
            else if(istep==16)  ///计算存储周期测量的数据
            {
                if(tickinc<=0)
                {
                    //if(mtg->tarset.incdb&&(mtg->tickinc1>0&&mtg->tickinc2>0&&mtg->tickinc3&&mtg->tickinc4>0))   //
                    if(mtg->tarset.incdb&&(((mtg->tarset.baseinc==0&&mtg->tickinc1>0&&mtg->tickinc2>0)||mtg->tarset.baseinc==1)&&mtg->tickinc3&&mtg->tickinc4>0))
                    {
                        tickinc++;
                        mtg_log(mtg,MTG_LOG_FINISH_GET_INCLINE);
                    }
                    else if(!mtg->tarset.incdb&&(mtg->tickinc1>0&&mtg->tickinc2>0))
                    {
                        tickinc++;
                        mtg_log(mtg,MTG_LOG_FINISH_GET_INCLINE);
                    }
                }
                if(tickcam1 >0&&tickinc>0)
                {
                    mtg->opera ^= MTG_OPERA_CAM;
//                    mtg->opera ^= MTG_OPERA_INC;
                    if(mtg->ithread==MTG_THREAD_CYCLE)
                    {
                        ///ܹ̬
                        mtg_laser_gesture(mtg);
                        ///20210617whq add,为了解决铁建838现场姿态跳动问题
//                        mtg_dc_meas(mtg,0);
//                        mtg_dc_meas(mtg,1);
//                        mtg_dc_meas(mtg,2);
//                        mtg_dc_meas(mtg,3);
//                        mtg_dc_meas(mtg,4);
//                        mtg_dc_meas(mtg,5);
//                        mtg->hdev1=mtg->m.hdev1;
//                        mtg->vdev1=mtg->m.vdev1;
//                        mtg->hdev2=mtg->m.hdev2;
//                        mtg->vdev2=mtg->m.vdev2;
//                        mtg->hdev3=mtg->m.hdev3;
//                        mtg->vdev3=mtg->m.vdev3;
//                        sqlite_export_dc_meas(mtg,dbpath);
                        ///add end

                        if(mtg_store_meas(mtg))
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_STORE_MEASURE);
                            //mtg_store_alw(mtg);
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_STORE_MEASURE);
                        }
                    }

                    ///
                    if(mtg->tps.lasertype==0||mtg->tps.type==TPS_TRIMBLE)  ///GUS74激光头
                    {
                        if(tps_stop_laser(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                            fail=1;
                        }
                    }
                    else if(mtg->tps.lasertype==1)   ///无棱镜测距激光
                    {
                        if(tps_stop_laserpoint(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                            fail=1;
                        }
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                        istep=18;
                    }
                }
                else
                {
                    if(tickget()-tickwait>timeout)
                    {
                        if(tickinc<=0)
                        {
                            if((mtg->tickinc1<=0||mtg->tickinc2<=0)&&mtg->tarset.baseinc==0)
                                mtg_log(mtg,MTG_LOG_FAIL_GET_INCLINE1);
                            else if(mtg->tickinc3<=0||mtg->tickinc4<=0)
                                mtg_log(mtg,MTG_LOG_FAIL_GET_INCLINE2);
                            else
                                mtg_log(mtg,MTG_LOG_FAIL_GET_INCLINE);
                        }

                        if(tickcam1<=0)
                        {
                            if(mtg->camsvr.cams[0].ret==-2)///获取照片失败
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_GET_IMAGE);
                            }
                            else if(mtg->camsvr.cams[0].ret==-1)///未提取出光斑
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_GET_SPECKLE);
                            }
                            else if(mtg->camsvr.cams[0].ret==0)///尺寸不符
                            {
                                mtg_log(mtg,MTG_LOG_ERROR_SIZE);
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_GET_SPECKLE);
                        }
                        fail=1;
                        if(mtg->tps.lasertype==0||mtg->tps.type==TPS_TRIMBLE)  ///GUS74激光头
                        {
                            if(tps_stop_laser(&mtg->tps)==0)
                            {
                                mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                                tickwait=tickget();
                                rc=-1;
                                while(tps_get_rc(&mtg->tps,&opera,&rc) && tickget()-tickwait<timeout) sleepms(10);
                                if(rc==0)
                                {
                                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                                }
                                else
                                {
                                    mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                                }
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                            }
                        }
                        else if(mtg->tps.lasertype==1)   ///无棱镜测距激光
                        {
                            if(tps_stop_laserpoint(&mtg->tps)==0)
                            {
                                mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                                tickwait=tickget();
                                rc=-1;
                                while(tps_get_rc(&mtg->tps,&opera,&rc) && tickget()-tickwait<timeout) sleepms(10);
                                if(rc==0)
                                {
                                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                                }
                                else
                                {
                                    mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                                }
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                        }
                    }
                }
            }
            else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
            {
                if(rc==0)
                {
                    if(istep==1)    ///照准后视
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_TARGET_BACKSIGHT);
                        if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_BACKSIGHT);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BACKSIGHT);
                            fail=1;
                        }
                    }
                    else if(istep==2)   ///测量后视
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_BACKSIGHT);
                        if(tps_do_measure(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_BACKSIGHT);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                            fail=1;
                        }
                    }
                    else if(istep==3)   ///获取测量值
                    {
                        if(tps_get_measure(&mtg->tps)==0)
                        {
                            istep++;
                            //20180110whq待增加
                            //mtg_log(mtg,MTG_LOG_BEGIN_GET_MEASURERESULT);
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                            fail=1;
                        }

                    }
                    else if(istep==4)   ///计算后视水平、垂直偏差
                    {
                        double ori,ver,dist;
                        ori=atan2(mtg->istn.backy-mtg->istn.staty,mtg->istn.backx-mtg->istn.statx);
                        if(ori<0.0) ori+=2.0*PI;
                        dist=sqrt((mtg->istn.backx-mtg->istn.statx)*(mtg->istn.backx-mtg->istn.statx)+
                                  (mtg->istn.backy-mtg->istn.staty)*(mtg->istn.backy-mtg->istn.staty))+0.0000000001;
                        ver=atan((mtg->istn.backz+mtg->istn.backh-mtg->istn.statz-mtg->istn.stath)/dist);
                        mtg->detd=mtg->tps.dist*cos(PI/2.0-mtg->tps.vertical)-dist;
                        mtg->deth=mtg->tps.dist*cos(PI/2.0-mtg->tps.vertical)*sin(mtg->tps.horizon+mtg->istn.anglediff-ori);
                        mtg->detv=mtg->tps.dist*sin(PI/2.0-mtg->tps.vertical)-mtg->tps.dist*cos(PI/2.0-mtg->tps.vertical)*tan(ver);
                        tpshz=mtg->tps.horizon;
                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.4f,%.4f,%.4f\n",5,mtg->detd,mtg->deth,mtg->detv);
                            fflush(mtg->fmain);
                        }

                        if(tps_clear_measure(&mtg->tps)==0)
                        {
                            //istep++;
                            //20180110whq增加
                            //mtg_log(mtg,MTG_LOG_FINISH_GET_MEASURE);
                            tickback=tickget();
                            if(mtg->iset.rstn==1)
                            {
                                if(fabs(mtg->deth)>mtg->iset.balw/1000.0 || fabs(mtg->detv)>mtg->iset.balw/1000.0)
                                {
                                    istep++;
                                }
                                else
                                {
                                    istep=6;
                                }
                            }
                            else
                            {
                                istep=6;
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                            fail=1;
                        }
                    }
                    else if(istep==5)    ///定向
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BACKSIGHT);
                        ori=atan2(mtg->istn.backy-mtg->istn.staty,mtg->istn.backx-mtg->istn.statx);
                        if(ori<0) ori+=2*PI;
                        if(tps_set_orientation(&mtg->tps,ori)==0)
                        {
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_SET_ORIENTATION);
                            fail=1;
                        }
                    }
                    else if(istep==6)   ///保存定向数据、转向激光耙小棱镜
                    {
                        tickback=tickget();

                        if(mtg->iset.rstn==1)
                        {
                            if(fabs(mtg->deth)>mtg->iset.balw/1000.0 || fabs(mtg->detv)>mtg->iset.balw/1000.0)
                            {
//                                mtg->istn.anglediff=ori-mtg->tps.horizon;
                                mtg->istn.anglediff=ori-tpshz;
                                time(&mtg->istn.t);
                                mtg_store_station(mtg);
                                mtg_log(mtg,MTG_LOG_FINISH_SET_ORIENTATION);
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BACKSIGHT);
                            }
                        }
                        else
                            mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BACKSIGHT);
                        //mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BACKSIGHT);
                        dx=mtg->m1.prism[0]-mtg->istn.statx;
                        dy=mtg->m1.prism[1]-mtg->istn.staty;
                        dz=mtg->m1.prism[2]-mtg->istn.statz-mtg->istn.stath;

                        dh=atan2(dy,dx);
                        //if(dh<0.0) dh+=2.0*PI;
                        //if(dh>2*PI)) dh-=2*PI;
                        //加入方位角与全站仪的水平角差值
                        dh=dh-mtg->istn.anglediff;
                        //if(dh<0) dh+=2*PI;
                        //if(dh>2*PI) dh-=2*PI;


                        dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                        dv=PI/2.0-atan(dz/dl);

                        if(tps_make_position(&mtg->tps,dh,dv)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                            istep++;
                            mtg->opera |= MTG_OPERA_INC;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                            fail=1;
                        }
                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.7f,%.7f\n",6,dh,dv);
                            fflush(mtg->fmain);
                        }
                    }
                    else if(istep==7)   ///照准激光耙小棱镜
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_TARGET_PRISM);
                        if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==8)   ///测量小棱镜
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_PRISM);
                        if(tps_do_measure(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==9)  ///获取测量数据
                    {
                        if(tps_get_measure(&mtg->tps)==0)
                        {
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==10)  ///计算小棱镜坐标
                    {
                        dh=mtg->tps.horizon;
                        dv=mtg->tps.vertical;
                        //if(mtg->tps.type==TPS_TRIMBLE)
                            //mtg->tps.dist+=mtg->tps.prism;
                        dl=mtg->tps.dist+mtg->tarset.prc/1000.0;
                        dh=dh+mtg->istn.anglediff;

                        mtg->m.prism[0]=mtg->istn.statx+dl*cos(PI/2-dv)*cos(dh);
                        mtg->m.prism[1]=mtg->istn.staty+dl*cos(PI/2-dv)*sin(dh);
                        mtg->m.prism[2]=mtg->istn.statz+mtg->istn.stath+dl*sin(PI/2.0-dv);
                        time(&mtg->m.t3);
                        if(tps_clear_measure(&mtg->tps)==0)
                        {
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.4f,%.4f,%.4f,%.4f,%.4f\n",7,mtg->m.prism[0],mtg->m.prism[1],mtg->m.prism[2],mtg->tps.dist,mtg->tarset.prc/1000.0);
                            fflush(mtg->fmain);
                        }
                    }
                    else if(istep==11)  ///转向激光屏
                    {
                        ///修正滚动角，俯仰角对激光耙中心照准的影响
                        point3d_t pt1,pt2;
                        transform3d_t trans;
                        double roll,pitch,ori;
                        if(mtg->tarset.baseinc==1)
                        {
                            roll=mtg->m1.inc[5]*PI/180.0;
                            pitch=mtg->m1.inc[6]*PI/180.0;
                        }
                        else
                        {
                            roll=mtg->m1.inc[0]*PI/180.0;
                            pitch=mtg->m1.inc[1]*PI/180.0;
                        }

                        roll=atan(tan(roll)/(cos(pitch)+0.0000000001));
                        //ori=atan2(mtg->m.prism[1]-mtg->istn.staty,mtg->m.prism[0]-mtg->istn.statx);
                        //trace(0,"prism:%f,%f,%f\n",mtg->m.prism[0],mtg->m.prism[1],mtg->m.prism[2]);
                        //trace(0,"station:%f,%f,%f\n",mtg->istn.statx,mtg->istn.staty,mtg->istn.statz);
                        ///激光靶方位角取设计中线的切线方位
//                        road_xy2l(&mtg->r,mtg->m.prism[0],mtg->m.prism[1],0,0,0,&ori,0);
//
//                        //trace(0,"ori:%f\n",ori);
//                        if(mtg->prj.a2z==-1)
//                        {
//                            ori = ori+PI;
//                            if(ori>2*PI) ori=ori-2*PI;
//                        }
                        ///20210625whq change
                        ori=dh;
                        ///change end
                        dh=mtg->tps.horizon;
                        if(mtg->tarset.ipos<0||mtg->tarset.ipos>3)
                        {
                            //20180110whq增加
                            mtg_log(mtg,MTG_LOG_NO_PRISM_POSITION);
                            fail=1;
                        }
                        else
                        {
                            pt1.x=-mtg->tarset.prism[mtg->tarset.ipos*3]/1000.0;
                            pt1.y=-mtg->tarset.prism[mtg->tarset.ipos*3+1]/1000.0;
                            pt1.z=-mtg->tarset.prism[mtg->tarset.ipos*3+2]/1000.0;

                            if(mtg->fmain)
                            {
                                fprintf(mtg->fmain,"%%R1P,meas:%.4f,%.4f,%.4f\n",pt1.x,pt1.y,pt1.z);
                                fflush(mtg->fmain);
                            }

                            transform3d_init(&trans,roll,pitch,-ori,0.0,0.0,0.0,1.0);
                            transform3d_trans(&trans,&pt1,&pt2);
                            if(mtg->fmain)
                            {
                                fprintf(mtg->fmain,"%%R1P,meas:%.4f,%.4f,%.4f\n",pt2.x,pt2.y,pt2.z);
                                fflush(mtg->fmain);
                            }
                            ///斜距,平距
                            dx=mtg->m.prism[0]+pt2.x-mtg->istn.statx;
                            dy=mtg->m.prism[1]+pt2.y-mtg->istn.staty;
                            dz=mtg->m.prism[2]+pt2.z-mtg->istn.statz-mtg->istn.stath;
                            dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                            dz-=laserheight*(dl*dl+dz*dz)/(sqrt(dl*dl+dz*dz-laserheight*laserheight)*dl+laserheight*dz+0.0000000001);
                            ///转向激光耙
                            //dh=atan2(dy,dx)-laserx;
                            if(mtg->fmain)
                            {
                                fprintf(mtg->fmain,"%%R1P,meas dh:%.4f\n",dh);
                                fflush(mtg->fmain);
                            }

//                            if(mtg->tarset.ipos==2||mtg->tarset.ipos==3)
//                            {
//                                dh=atan2(dy,dx)-laserx;
//                                dh=dh-mtg->istn.anglediff;
//                            }
//                            else
//                            {
//                                ///20210526whq xiugai
//                                ///dh=dh-laserx;
//                                dh=atan2(dy,dx)-laserx;
//                                dh=dh-mtg->istn.anglediff;
//                                ///change end
//                            }
                            ///20210628whq modify again
                            dh=atan2(dy,dx)-laserx;
                            dh=dh-mtg->istn.anglediff;
                            ///end
                            if(mtg->fmain)
                            {
                                fprintf(mtg->fmain,"%%R1P,meas dh:%.4f\n",dh);
                                fflush(mtg->fmain);
                            }

                            dv=PI/2.0-atan(dz/dl)+lasery;
                            mtg_log(mtg,MTG_LOG_FINISH_MEASURE_PRISM);
                            if(tps_make_position(&mtg->tps,dh,dv)==0)
                            {
                                mtg_log(mtg,MTG_LOG_BEGIN_TARGET_LASERUNIT);
                                istep++;
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_TARGET_LASERUNIT);
                                fail=1;
                            }
                            if(mtg->fmain)
                            {
                                fprintf(mtg->fmain,"%%R1P,%d,%.7f,%.7f\n",8,dh,dv);
                                fflush(mtg->fmain);
                            }
                        }
                    }
                    else if(istep==12)  ///获取电子补偿器信息(气泡）
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_TARGET_LASERUNIT);
                        if(tps_get_incline(&mtg->tps)==0)
                        {
                            //mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_ANGLE);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_ANGLE);
                            fail=1;
                        }
                    }
                    else if(istep==13)  ///记录气泡角度数据、打开激光
                    {
                        ///comp
                        //mtg_log(mtg,MTG_LOG_FINISH_MEASURE_ANGLE);
                        //20180115whq修改，在后面增加mtg->istn.anglediff
                        //mtg->m.angle[0]=mtg->tps.horizon+laserx+mtg->istn.anglediff;
                        //mtg->m.angle[1]=mtg->tps.vertical+lasery;
                        //20180116whq修改上面的两句话 改成下面的
                        mtg->m.angle[0]=dh+mtg->istn.anglediff;
                        mtg->m.angle[1]=dv;
                        //20180116whq修改结束

                        mtg->m.comp[0]=mtg->tps.incline[0];
                        mtg->m.comp[1]=mtg->tps.incline[1];

                        if(mtg->tps.lasertype==0||mtg->tps.type==TPS_TRIMBLE)
                        {
                            if(tps_start_laser(&mtg->tps)==0)
                            {
                                mtg_log(mtg,MTG_LOG_BEGIN_START_LASER);
                                //istep++;
                                istep=15;
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
                                fail=1;
                            }

                        }
                        else if(mtg->tps.lasertype==1)
                        {
                            if(tps_start_laserpoint(&mtg->tps)==0)
                            {
                                mtg_log(mtg,MTG_LOG_BEGIN_START_LASER);
                                //istep++;
                                istep=15;
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
                                fail=1;
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_START_LASER);
                            camsvr_start_capture(&mtg->camsvr);
                            mtg->opera |= MTG_OPERA_CAM;
                            //tickinc1=tickinc2=0;
                            tickcam1=tickcam2=0;
                            tickwait=tickget();
                            istep=16;
                        }
                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.7f,%.7f,%.7f,%.7f\n",9,mtg->m.angle[0],mtg->m.angle[1],mtg->m.comp[0],mtg->m.comp[1]);
                            fflush(mtg->fmain);
                        }
                    }
                    else if(istep==14)  ///获取角度
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_START_LASER);
                        sleepms(2000);
                        if(tps_get_angle(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_GET_ANGLE);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_GET_ANGLE);
                            fail=1;
                        }
                    }
                    else if(istep==15)
                    {
                        //mtg_log(mtg,MTG_LOG_FINISH_GET_ANGLE);
                        mtg_log(mtg,MTG_LOG_FINISH_START_LASER);
                        time(&t);
                        if(fp)
                        {
                            fprintf(fp,"time:%Y-%m-%d %H:%M:%S ",localtime(&t));
                            fprintf(fp,",h:%.7f,v:%.7f\n",mtg->tps.horizon,mtg->tps.vertical);
                            fflush(fp);
                        }
                        if(camsvr_start_capture(&mtg->camsvr)==0)
                        {
                            mtg->opera |= MTG_OPERA_CAM;
                            istep++;
                            tickcam1=tickcam2=0;
                            tickwait=tickget();
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_CAMERA_FAIL);
                            fail=1;
                        }
                    }
                    else if(istep==17)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                        istep++;
                    }
                }
                else
                {
                    if(istep==1)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                    }
                    else if(istep==2)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BACKSIGHT);
                    }
                    else if(istep==3 || istep==4)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                    }
                    else if(istep==6)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_SET_ORIENTATION);
                    }
                    else if(istep==7)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                    }
                    else if(istep==8)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                    }
                    else if(istep==9 || istep==10 || istep==11)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                    }
                    else if(istep==12)
                    {
                        if(rc==8704&&mtg->tps.type==TS_16)
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_TARGET_LASERUNIT);
                            if(tps_get_incline(&mtg->tps)==0)
                            {
                                //mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_ANGLE);
                                istep++;
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_MEASURE_ANGLE);
                                fail=1;
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_LASERUNIT);
                        }
                    }
                    else if(istep==13)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_ANGLE);
                    }
                    else if(istep==14)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
                    }
                    else if(istep==15)
                    {
                        //mtg_log(mtg,MTG_LOG_FAIL_GET_ANGLE);
                        mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
                    }
                    else if(istep==17)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                    }
                    fail=1;
                    if(istep==12&&rc==8704&&mtg->tps.type==TS_16)
                    {
                        fail=0;

                    }
                }
            }
        }
        if(mtg->ithread ==  MTG_THREAD_CYCLE)
        {
            if(mtg->incycle)
            {
                if(fail)
                {
                    mtg_log(mtg,MTG_LOG_CANCEL_CYCLE);
                    mtg->incycle=0;
                    tickcam1=tickcam2=tickinc=0;
                    ticktps=0;
                    //mtg->opera = MTG_OPERA_INC;
                    mtg->opera = 0;
                    tickcycle=tickget();
                    fail=0;
                    camsvr_stop(&mtg->camsvr);
                    if(rc==-1 && mtg->tps.type==TPS_TRIMBLE_TCU)   //返回超时重启串口,适用于天宝TCU
                    {
                        tps_close(&mtg->tps);
                        sleepms(1000);
                        sprintf(path,"COM5:115200");
                        if(tps_connect(&mtg->tps,opts,STR_SERIAL,path)==0)
                        {
                            mtg->ierr[6]=1;
                            break;
                        }
                    }
                    fclose(mtg->fmain);
                    mtg->fmain=0;
                }
                else if(istep==18)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_CYCLE);
                    mtg->incycle=0;
                    tickcam1=tickcam2=tickinc=0;
                    ticktps=0;
                    //mtg->opera = MTG_OPERA_INC;
                    mtg->opera = 0;
                    tickcycle=tickget();
                    fail=0;
                    camsvr_stop(&mtg->camsvr);
                    fclose(mtg->fmain);
                    mtg->fmain=0;
                }
            }
            else
            {
                //trace(0,"tickcycle=%d,tick=%d,cyc=%d\n",tickcycle,tickget(),mtg->iset.cyc);
                if(!mtg->pause && (mtg->restart || tickget()-tickcycle>mtg->iset.cyc*1000))
                {
                    //trace(0,"1:tick=%d,cyc=%d\n",tickget(),mtg->iset.cyc);
                    mtg->restart=0;
                    mtg->incycle=1;
                    mtg->opera = MTG_OPERA_TPS | MTG_OPERA_INC;
                    tickcam1=tickcam2=tickinc=0;
                    ticktps=0;
                    mtg->tickinc3=mtg->tickinc4=mtg->tickinc1=mtg->tickinc2=tickinc=0;
                    if(tickget()-tickback>mtg->iset.bcyc*1000)   ///达到后视检核的周期时间
                    {
                        bc=1;
                    }
                    else
                    {
                        bc=0;
                    }
                    istep=0;
                    mtg_log(mtg,MTG_LOG_START_CYCLE);
                    mtg->fmain=fopen(mtg->pmain,"w");
                    mtg->camsvr.cams[0].ret=-2;
                    //trace(0,"2:tick=%d,cyc=%d\n",tickget(),mtg->iset.cyc);
                }
                else  ///get power capacity
                {
                    //trace(0,"3:tick=%d,cyc=%d,tickpower=%d\n",tickget(),mtg->iset.cyc,tickpower);
                    if(tickpower == 3000)
                    {
                        tickpower=0;
                        //if(tps_get_power(&mtg->tps)==0)
                        if(tps_get_incline(&mtg->tps)==0)
                        {
                            //trace(0,"4:tick=%d,cyc=%d\n",tickget(),mtg->iset.cyc);
                            while(tps_get_rc(&mtg->tps,0,&rc)) sleepms(0);
                            if(rc==0)
                            {
                                //trace(0,"5:tick=%d,cyc=%d\n",tickget(),mtg->iset.cyc);
                            }
                            else
                            {
                                //trace(0,"6:tick=%d,cyc=%d\n",tickget(),mtg->iset.cyc);
                            }
                        }
                    }
                    tickpower++;
                }
            }
        }
        else if(mtg->ithread == MTG_THREAD_ORIGIN)
        {
            if(fail)
            {
                camsvr_stop(&mtg->camsvr);
                mtg_log(mtg,MTG_LOG_FAIL_ORIGIN);
                fclose(mtg->fmain);
                mtg->fmain=0;
                break;
            }
            else if(istep==18)
            {
                camsvr_stop(&mtg->camsvr);
                mtg_log(mtg,MTG_LOG_FINISH_ORIGIN);
                fclose(mtg->fmain);
                mtg->fmain=0;
                //trace(0,"cam:%f,%f,%f,%f\n",mtg->m.cam[0],mtg->m.cam[1],mtg->m.cam[2],mtg->m.cam[3]);
                //trace(0,"inc:%f,%f\n",mtg->m.inc[0],mtg->m.inc[1]);
                //trace(0,"angle:%f,%f\n",mtg->m.angle[0],mtg->m.angle[1]);
                break;
            }
        }
        sleepms(10);
    }

    ///等待全站仪操作结束
    if(mtg->tps.opera)
    {
        while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(10);
    }

    if((fail || !mtg->stat) && (istep>=15&&istep<=17))
    {
        if(mtg->tps.lasertype==0||mtg->tps.type==TPS_TRIMBLE)
        {
            if(tps_stop_laser(&mtg->tps)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(10);
                if(rc==0)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                }
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
            }
        }
        else if(mtg->tps.lasertype==1)
        {
            if(tps_stop_laserpoint(&mtg->tps)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(10);
                if(rc==0)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                }
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);

            }
        }

    }

    if(mtg->ithread==MTG_THREAD_CYCLE)
    {
        mtg_log(mtg,MTG_LOG_END_CYCLE);
    }
    mtg->thread=0;
    mtg->stat=0;

    if(fp)
    {
        fclose(fp);
        fp=NULL;
    }
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtgthread_origin_segmeas(void* arg)
#else
static void *_mtgthread_origin_segmeas(void *arg)
#endif
{
    mtg_t* mtg=0;
    int istep=0;

    double cam[3];
    time_t now;
    int opera=0,rc=0;
    int tickcam1=0,tickcam2=0,ticktps=0;
    unsigned int tickcycle=0,ticknow=0,tickback=0;
    int bc=1;
    int fail=0;
    double dx,dy,dz,dh,dv,dl;
    int timeout=30000;
    unsigned int tickwait=0,tickpower=0;
    double laserheight=0.0;
    double laserx=0.0,lasery=0.0;
    double ori;
    double tpshz;
    int tickinc=0;

    time_t t;
    char timestr[256];
    FILE* fp=fopen("D://mtg_thread_origin_seg.log","w");
    if(fp)
    {
        time(&t);
        strftime(timestr,64,"%Y-%m-%d %H:%M:%S",localtime(&t));
        fprintf(fp,"%s\n",timestr);
        fflush(fp);
    }

    mtg=(mtg_t*)arg;
    mtg_log(mtg,MTG_LOG_START_ORIGIN_SEG_CYCLE);
    mtg->camsvr.cams[0].ret=-2;

    mtg->fmain=fopen(mtg->pmain,"w");

    laserheight=mtg->tps.laserheight;

    if(mtg->tps.lasertype==0)
    {
        if(mtg->tps.laserdist[0]>1.0e-6)
        {
            laserx=atan(mtg->tps.laserx[0]/mtg->tps.laserdist[0]);
            lasery=atan(mtg->tps.lasery[0]/mtg->tps.laserdist[0]);
        }
    }
    else if(mtg->tps.lasertype==1)
    {
        if(mtg->tps.laserdist[1]>1.0e-6)
        {
            laserx=atan(mtg->tps.laserx[1]/mtg->tps.laserdist[1]);
            lasery=atan(mtg->tps.lasery[1]/mtg->tps.laserdist[1]);
        }
    }
    if(mtg->fmain)
    {
        fprintf(mtg->fmain,"%%R1P,%d,%d,%.4f,%.4f,%.4f\n",0,mtg->tps.lasertype,laserheight,laserx,lasery);
        fflush(mtg->fmain);
    }
    //trace(0,"_mtgthread:laserx=%.4f,lasery=%.4f\n",laserx,lasery);
    mtg->originstat=mtg->stat=1;
    mtg->opera=MTG_OPERA_TPS;

    bc=1;
    istep=0;
    mtg->incycle=1;
    while(mtg->stat)
    {
        //trace(0,"stat=%d,istep=%d\n",mtg->stat,istep);
        ///相机
        if(mtg->opera & MTG_OPERA_CAM)
        {
            if(camsvr_peek(&mtg->camsvr,0,0,cam,&now))
            {
                mtg->m.cam[0]=cam[0];
                mtg->m.cam[1]=cam[1];
                mtg->m.cam[2]=cam[2];
                mtg->m.inc[0] = mtg->m1.inc[0];
                mtg->m.inc[1] = mtg->m1.inc[1];
                mtg->m.t1=now;
                time(&now);
                mtg->m.t2=now;
                mtg_laser_incline(mtg);
                tickcam1++;
                if(mtg->fmain)
                {
                    fprintf(mtg->fmain,"%%R1P,%d,%.4f,%.4f,%.4f\n",1,cam[0],cam[1],cam[2]);
                    fflush(mtg->fmain);
                }
            }
        }
        ///
        if(mtg->opera & MTG_OPERA_TPS)
        {
            //trace(0,"thread:step=%d\n",istep);

            if(istep==0)
            {
                if(mtg->tarset.cam==1)
                {
                    if(camsvr_dh_start(&mtg->camsvr,10))
                    {
                        mtg_log(mtg,MTG_LOG_CAMERA_READY);
                    }
                }
                else if(mtg->tarset.cam==0)
                {
                    if(camsvr_bm_start(&mtg->camsvr,10))
                    {
                        mtg_log(mtg,MTG_LOG_CAMERA_READY);
                    }
                }

                if(mtg->fmain)
                {
                    fprintf(mtg->fmain,"%%R1P,%d,%d\n",2,mtg->tarset.cam);
                    fflush(mtg->fmain);
                }

                if(mtg->ithread==MTG_THREAD_CYCLE)
                {
                    mtg->run = 1;
                    if(bc) ///ת⾵
                    {
                        dx=mtg->istn.backx-mtg->istn.statx;
                        dy=mtg->istn.backy-mtg->istn.staty;
                        dz=mtg->istn.backz+mtg->istn.backh-mtg->istn.statz-mtg->istn.stath;
                        dh=atan2(dy,dx);
                        //if(dh<0) dh+=2*PI;
                        //if(dh>2*PI) dh-=2*PI;
                        dh=dh-mtg->istn.anglediff;
                        //if(dh<0) dh+=2*PI;
                        //if(dh>2*PI) dh-=2*PI;

                        dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                        dv=PI/2-atan(dz/dl);
                        if(tps_make_position(&mtg->tps,dh,dv)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_BACKSIGHT);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                            fail=1;
                        }
                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.7f,%.7f\n",3,dh,dv);
                            fflush(mtg->fmain);
                        }
                    }
                    else  ///תǰ⾵
                    {
                        istep=6;
                        dx=mtg->m1.prism[0]-mtg->istn.statx;
                        dy=mtg->m1.prism[1]-mtg->istn.staty;
                        dz=mtg->m1.prism[2]-mtg->istn.statz-mtg->istn.stath;
                        dh=atan2(dy,dx);
                        //if(dh<0) dh+=2*PI;
                        //if(dh>2*PI) dh-=2*PI;
                        //天宝全站仪
                        dh=dh-mtg->istn.anglediff;
                        //if(dh<0) dh+=2*PI;
                        //if(dh>2*PI) dh-=2*PI;

                        dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                        dv=PI/2-atan(dz/dl);
                        if(tps_make_position(&mtg->tps,dh,dv)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                            fail=1;
                        }

                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.7f,%.7f\n",4,dh,dv);
                            fflush(mtg->fmain);
                        }
                    }
                }
                else if(mtg->ithread==MTG_THREAD_ORIGIN)
                {
                    istep=7;

                    ///ȷ׼ǰ
                    if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                        fail=1;
                    }
                }
            }
            else if(istep==16)  ///ȴڽ
            {
                if(tickinc<=0)
                {
                    if(mtg->tarset.incdb&&(mtg->tickinc1>0&&mtg->tickinc2>0&&mtg->tickinc3&&mtg->tickinc4>0))   //
                    {
                        tickinc++;
                        mtg_log(mtg,MTG_LOG_FINISH_GET_INCLINE);
                    }
                    else if(!mtg->tarset.incdb)
                    {
                        tickinc++;
                    }
                }
                if(tickcam1 >0&&tickinc>0)
                {
                    mtg->opera ^= MTG_OPERA_CAM;
                    if(mtg->ithread==MTG_THREAD_CYCLE)
                    {
                        ///ܹ̬
                        mtg_laser_gesture(mtg);
                        if(mtg_store_meas(mtg))
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_STORE_MEASURE);
                            //mtg_store_alw(mtg);
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_STORE_MEASURE);
                        }
                    }

                    ///
                    if(mtg->tps.lasertype==0||mtg->tps.type==TPS_TRIMBLE)  ///GUS74激光头
                    {
                        if(tps_stop_laser(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                            fail=1;
                        }
                    }
                    else if(mtg->tps.lasertype==1)   ///无棱镜测距激光
                    {
                        if(tps_stop_laserpoint(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                            fail=1;
                        }
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                        istep=18;
                    }
                }
                else
                {
                    if(tickget()-tickwait>timeout)
                    {
                        if(tickinc<=0)
                            mtg_log(mtg,MTG_LOG_FAIL_GET_INCLINE);
                        if(tickcam1<=0)
                        {
                            if(mtg->camsvr.cams[0].ret==-2)///获取照片失败
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_GET_IMAGE);
                            }
                            else if(mtg->camsvr.cams[0].ret==-1)///未提取出光斑
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_GET_SPECKLE);
                            }
                            else if(mtg->camsvr.cams[0].ret==0)///尺寸不符
                            {
                                mtg_log(mtg,MTG_LOG_ERROR_SIZE);
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_GET_SPECKLE);
                        }
                        fail=1;
                        if(mtg->tps.lasertype==0||mtg->tps.type==TPS_TRIMBLE)  ///GUS74激光头
                        {
                            if(tps_stop_laser(&mtg->tps)==0)
                            {
                                mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                                tickwait=tickget();
                                rc=-1;
                                while(tps_get_rc(&mtg->tps,&opera,&rc) && tickget()-tickwait<timeout) sleepms(10);
                                if(rc==0)
                                {
                                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                                }
                                else
                                {
                                    mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                                }
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                            }
                        }
                        else if(mtg->tps.lasertype==1)   ///无棱镜测距激光
                        {
                            if(tps_stop_laserpoint(&mtg->tps)==0)
                            {
                                mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                                tickwait=tickget();
                                rc=-1;
                                while(tps_get_rc(&mtg->tps,&opera,&rc) && tickget()-tickwait<timeout) sleepms(10);
                                if(rc==0)
                                {
                                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                                }
                                else
                                {
                                    mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                                }
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                        }
                    }
                }
            }
            else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
            {
                if(rc==0)
                {
                    if(istep==1)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_TARGET_BACKSIGHT);
                        if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_BACKSIGHT);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BACKSIGHT);
                            fail=1;
                        }
                    }
                    else if(istep==2)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_BACKSIGHT);
                        if(tps_do_measure(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_BACKSIGHT);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                            fail=1;
                        }
                    }
                    else if(istep==3)
                    {
                        if(tps_get_measure(&mtg->tps)==0)
                        {
                            istep++;
                            //20180110whq待增加
                            //mtg_log(mtg,MTG_LOG_BEGIN_GET_MEASURERESULT);
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                            fail=1;
                        }

                    }
                    else if(istep==4)
                    {
                        double ori,ver,dist;
                        ori=atan2(mtg->istn.backy-mtg->istn.staty,mtg->istn.backx-mtg->istn.statx);
                        if(ori<0.0) ori+=2.0*PI;
                        dist=sqrt((mtg->istn.backx-mtg->istn.statx)*(mtg->istn.backx-mtg->istn.statx)+
                                  (mtg->istn.backy-mtg->istn.staty)*(mtg->istn.backy-mtg->istn.staty))+0.0000000001;
                        ver=atan((mtg->istn.backz+mtg->istn.backh-mtg->istn.statz-mtg->istn.stath)/dist);
                        mtg->detd=mtg->tps.dist*cos(PI/2.0-mtg->tps.vertical)-dist;
                        mtg->deth=mtg->tps.dist*cos(PI/2.0-mtg->tps.vertical)*sin(mtg->tps.horizon+mtg->istn.anglediff-ori);
                        mtg->detv=mtg->tps.dist*sin(PI/2.0-mtg->tps.vertical)-mtg->tps.dist*cos(PI/2.0-mtg->tps.vertical)*tan(ver);
                        tpshz=mtg->tps.horizon;

                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.4f,%.4f,%.4f\n",5,mtg->detd,mtg->deth,mtg->detv);
                            fflush(mtg->fmain);
                        }

                        if(tps_clear_measure(&mtg->tps)==0)
                        {
                            //istep++;
                            //20180110whq增加
                            //mtg_log(mtg,MTG_LOG_FINISH_GET_MEASURE);
                            tickback=tickget();
                            //if(mtg->iset.rstn==1)
                            {
                                //if(/*fabs(mtg->deth)<0.005&&*/(fabs(mtg->deth)>mtg->iset.balw/1000.0 || fabs(mtg->detv)>mtg->iset.balw/1000.0))
                                {
                                    istep++;
                                }
//                                else
//                                {
//                                    istep=6;
//                                }
                            }
                            //else
//                            {
//                                istep=6;
//                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                            fail=1;
                        }
                    }
                    else if(istep==5)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BACKSIGHT);
                        ori=atan2(mtg->istn.backy-mtg->istn.staty,mtg->istn.backx-mtg->istn.statx);
                        if(ori<0) ori+=2*PI;
                        if(tps_set_orientation(&mtg->tps,ori)==0)
                        {
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_SET_ORIENTATION);
                            fail=1;
                        }
                    }
                    else if(istep==6)
                    {
                        tickback=tickget();
                        //if(mtg->iset.rstn==1)
                        {
                            //if(fabs(mtg->deth)>mtg->iset.balw/1000.0 || fabs(mtg->detv)>mtg->iset.balw/1000.0)
                            {
                               // mtg->istn.anglediff=ori-mtg->tps.horizon;
                                mtg->istn.anglediff=ori-tpshz;
                                mtg_store_station(mtg);
                                mtg_log(mtg,MTG_LOG_FINISH_SET_ORIENTATION);
                            }
//                            else
//                            {
//                                mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BACKSIGHT);
//                            }
                        }
//                        else
//                            mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BACKSIGHT);
                        dx=mtg->m1.prism[0]-mtg->istn.statx;
                        dy=mtg->m1.prism[1]-mtg->istn.staty;
                        dz=mtg->m1.prism[2]-mtg->istn.statz-mtg->istn.stath;

                        dh=atan2(dy,dx);
                        //if(dh<0.0) dh+=2.0*PI;
                        //if(dh>2*PI)) dh-=2*PI;
                        //加入方位角与全站仪的水平角差值
                        dh=dh-mtg->istn.anglediff;
                        //if(dh<0) dh+=2*PI;
                        //if(dh>2*PI) dh-=2*PI;


                        dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                        dv=PI/2.0-atan(dz/dl);

                        if(tps_make_position(&mtg->tps,dh,dv)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                            fail=1;
                        }
                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.7f,%.7f\n",6,dh,dv);
                            fflush(mtg->fmain);
                        }
                    }
                    else if(istep==7)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_TARGET_PRISM);
                        if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==8)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_PRISM);
                        if(tps_do_measure(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==9)  ///ǰӲɹ
                    {
                        if(tps_get_measure(&mtg->tps)==0)
                        {
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==10)  ///ȡɹ
                    {
                        dh=mtg->tps.horizon;
                        dv=mtg->tps.vertical;
                        //if(mtg->tps.type==TPS_TRIMBLE)
                            //mtg->tps.dist+=mtg->tps.prism;
                        dl=mtg->tps.dist+mtg->tarset.prc/1000.0;
                        dh=dh+mtg->istn.anglediff;

                        mtg->m.prism[0]=mtg->istn.statx+dl*cos(PI/2-dv)*cos(dh);
                        mtg->m.prism[1]=mtg->istn.staty+dl*cos(PI/2-dv)*sin(dh);
                        mtg->m.prism[2]=mtg->istn.statz+mtg->istn.stath+dl*sin(PI/2.0-dv);
                        time(&mtg->m.t3);
                        if(tps_clear_measure(&mtg->tps)==0)
                        {
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.4f,%.4f,%.4f,%.4f,%.4f\n",7,mtg->m.prism[0],mtg->m.prism[1],mtg->m.prism[2],mtg->tps.dist,mtg->tarset.prc/1000.0);
                            fflush(mtg->fmain);
                        }
                    }
                    else if(istep==11)
                    {
                        ///修正滚动角，俯仰角对激光耙中心照准的影响
                        point3d_t pt1,pt2;
                        transform3d_t trans;
                        double roll,pitch,ori;
                        roll=mtg->m1.inc[0]*PI/180.0;
                        pitch=mtg->m1.inc[1]*PI/180.0;
                        roll=atan(tan(roll)/(cos(pitch)+0.0000000001));
                        //ori=atan2(mtg->m.prism[1]-mtg->istn.staty,mtg->m.prism[0]-mtg->istn.statx);
                        //trace(0,"prism:%f,%f,%f\n",mtg->m.prism[0],mtg->m.prism[1],mtg->m.prism[2]);
                        //trace(0,"station:%f,%f,%f\n",mtg->istn.statx,mtg->istn.staty,mtg->istn.statz);
                        ///激光靶方位角取设计中线的切线方位
                        road_xy2l(&mtg->r,mtg->m.prism[0],mtg->m.prism[1],0,0,0,&ori,0);

                        //trace(0,"ori:%f\n",ori);
                        if(mtg->prj.a2z==-1)
                        {
                            ori = ori+PI;
                            if(ori>2*PI) ori=ori-2*PI;
                        }
                        dh=mtg->tps.horizon;
                        if(mtg->tarset.ipos<0||mtg->tarset.ipos>3)
                        {
                            //20180110whq增加
                            mtg_log(mtg,MTG_LOG_NO_PRISM_POSITION);
                            fail=1;
                        }
                        else
                        {
                            pt1.x=-mtg->tarset.prism[mtg->tarset.ipos*3]/1000.0;
                            pt1.y=-mtg->tarset.prism[mtg->tarset.ipos*3+1]/1000.0;
                            pt1.z=-mtg->tarset.prism[mtg->tarset.ipos*3+2]/1000.0;

                            if(mtg->fmain)
                            {
                                fprintf(mtg->fmain,"%%R1P,meas:%.4f,%.4f,%.4f\n",pt1.x,pt1.y,pt1.z);
                                fflush(mtg->fmain);
                            }

                            transform3d_init(&trans,roll,pitch,-ori,0.0,0.0,0.0,1.0);
                            transform3d_trans(&trans,&pt1,&pt2);
                            if(mtg->fmain)
                            {
                                fprintf(mtg->fmain,"%%R1P,meas:%.4f,%.4f,%.4f\n",pt2.x,pt2.y,pt2.z);
                                fflush(mtg->fmain);
                            }
                            ///斜距,平距
                            dx=mtg->m.prism[0]+pt2.x-mtg->istn.statx;
                            dy=mtg->m.prism[1]+pt2.y-mtg->istn.staty;
                            dz=mtg->m.prism[2]+pt2.z-mtg->istn.statz-mtg->istn.stath;
                            dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                            dz-=laserheight*(dl*dl+dz*dz)/(sqrt(dl*dl+dz*dz-laserheight*laserheight)*dl+laserheight*dz+0.0000000001);
                            ///转向激光耙
                            //dh=atan2(dy,dx)-laserx;
                            //dh=dh-laserx;
                            ///20190408whq change
                            if(mtg->tarset.ipos==2||mtg->tarset.ipos==3)
                            {
                                dh=atan2(dy,dx)-laserx;
                                dh=dh-mtg->istn.anglediff;
                            }
                            else
                                dh=dh-laserx;
                            if(mtg->fmain)
                            {
                                fprintf(mtg->fmain,"%%R1P,meas dh:%.4f\n",dh);
                                fflush(mtg->fmain);
                            }


                            if(mtg->fmain)
                            {
                                fprintf(mtg->fmain,"%%R1P,meas dh:%.4f\n",dh);
                                fflush(mtg->fmain);
                            }

                            dv=PI/2.0-atan(dz/dl)+lasery;
                            mtg_log(mtg,MTG_LOG_FINISH_MEASURE_PRISM);
                            if(tps_make_position(&mtg->tps,dh,dv)==0)
                            {
                                mtg_log(mtg,MTG_LOG_BEGIN_TARGET_LASERUNIT);
                                istep++;
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_TARGET_LASERUNIT);
                                fail=1;
                            }
                            if(mtg->fmain)
                            {
                                fprintf(mtg->fmain,"%%R1P,%d,%.7f,%.7f\n",8,dh,dv);
                                fflush(mtg->fmain);
                            }
                        }
                    }
                    else if(istep==12) ///
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_TARGET_LASERUNIT);
                        if(tps_get_incline(&mtg->tps)==0)
                        {
                            //mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_ANGLE);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_ANGLE);
                            fail=1;
                        }
                    }
                    else if(istep==13)
                    {
                        ///comp
                        //mtg_log(mtg,MTG_LOG_FINISH_MEASURE_ANGLE);
                        //20180115whq修改，在后面增加mtg->istn.anglediff
                        //mtg->m.angle[0]=mtg->tps.horizon+laserx+mtg->istn.anglediff;
                        //mtg->m.angle[1]=mtg->tps.vertical+lasery;
                        //20180116whq修改上面的两句话 改成下面的
                        mtg->m.angle[0]=dh+mtg->istn.anglediff;
                        mtg->m.angle[1]=dv;
                        //20180116whq修改结束

                        mtg->m.comp[0]=mtg->tps.incline[0];
                        mtg->m.comp[1]=mtg->tps.incline[1];

                        if(mtg->tps.lasertype==0||mtg->tps.type==TPS_TRIMBLE)
                        {
                            if(tps_start_laser(&mtg->tps)==0)
                            {
                                mtg_log(mtg,MTG_LOG_BEGIN_START_LASER);
                                istep=15;
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
                                fail=1;
                            }

                        }
                        else if(mtg->tps.lasertype==1)
                        {
                            if(tps_start_laserpoint(&mtg->tps)==0)
                            {
                                mtg_log(mtg,MTG_LOG_BEGIN_START_LASER);
                                istep=15;
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
                                fail=1;
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_START_LASER);
                            camsvr_start_capture(&mtg->camsvr);
                            mtg->opera |= MTG_OPERA_CAM;
                            //tickinc1=tickinc2=0;
                            tickcam1=tickcam2=0;
                            tickwait=tickget();
                            istep=16;
                        }
                        if(mtg->fmain)
                        {
                            fprintf(mtg->fmain,"%%R1P,%d,%.7f,%.7f,%.7f,%.7f\n",9,mtg->m.angle[0],mtg->m.angle[1],mtg->m.comp[0],mtg->m.comp[1]);
                            fflush(mtg->fmain);
                        }
                    }
                    else if(istep==14)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_START_LASER);
                        sleepms(2000);
                        if(tps_get_angle(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_GET_ANGLE);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_GET_ANGLE);
                            fail=1;
                        }
                    }
                    else if(istep==15)
                    {
                        //mtg_log(mtg,MTG_LOG_FINISH_GET_ANGLE);
                        mtg_log(mtg,MTG_LOG_FINISH_START_LASER);
//                        time(&t);
//                        if(fp)
//                        {
//                            fprintf(fp,"time:%Y-%m-%d %H:%M:%S ",localtime(&t));
//                            fprintf(fp,",h:%.7f,v:%.7f\n",mtg->tps.horizon,mtg->tps.vertical);
//                            fflush(fp);
//                        }
                        if(camsvr_start_capture(&mtg->camsvr)==0)
                        {
                            mtg->opera |= MTG_OPERA_CAM;
                            istep++;
                            tickcam1=tickcam2=0;
                            tickwait=tickget();
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_CAMERA_FAIL);
                            fail=1;
                        }
                    }
                    else if(istep==17)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                        istep++;
                    }
                }
                else
                {
                    if(istep==1)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                    }
                    else if(istep==2)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BACKSIGHT);
                    }
                    else if(istep==3 || istep==4 || istep==5)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                    }
                    else if(istep==6)
                    {
                        if(mtg->iset.rstn==1)
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_SET_ORIENTATION);
                        }
                    }
                    else if(istep==7)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                    }
                    else if(istep==8)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                    }
                    else if(istep==11 || istep==9 || istep==10)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                    }
                    else if(istep==12)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_TARGET_LASERUNIT);
                    }
                    else if(istep==13)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_ANGLE);
                    }
                    else if(istep==14)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
                    }
                    else if(istep==15)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_GET_ANGLE);
                    }
                    else if(istep==17)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                    }
                    fail=1;
                }
            }
        }
        if(mtg->ithread ==  MTG_THREAD_CYCLE)
        {
            if(mtg->incycle)
            {
                if(fail)
                {
                    mtg_log(mtg,MTG_LOG_CANCEL_CYCLE);
                    mtg->incycle=0;
                    tickcam1=tickcam2=0;
                    ticktps=0;
                    mtg->opera = MTG_OPERA_INC;
                    tickcycle=tickget();
                    fail=0;
                    camsvr_stop(&mtg->camsvr);
                    if(mtg->fmain)
                    {
                        fclose(mtg->fmain);
                        mtg->fmain=0;
                    }

                    mtg->deth=mtg->maj0.deth;
                    mtg->detv=mtg->maj0.detv;
                    break;
                }
                else if(istep==18)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_CYCLE);
                    mtg->incycle=0;
                    tickcam1=tickcam2=0;
                    ticktps=0;
                    mtg->opera = MTG_OPERA_INC;
                    tickcycle=tickget();
                    fail=0;
                    camsvr_stop(&mtg->camsvr);
                    if(mtg->fmain)
                    {
                        fclose(mtg->fmain);
                        mtg->fmain=0;
                    }

                    ///20200320whq add 存储初始标定数据
                    ///判断如果有标定记录且现在的里程与上一次标定成功的里程相差大于0.9L则计算全站仪姿态与油缸姿态的角度差
                    if(mtg->maj01.t4>0&&(mtg->m1.headc-mtg->maj01.headc)*mtg->prj.a2z<1.8)
                    {
                        mtg->maj.inc[0]=mtg->m1.inc[0];
                        mtg->maj.inc[1]=mtg->m1.inc[1];
                        mtg_aj_tbm_nocorrection(mtg);
                        ///计算油缸姿态与全站仪姿态的方位角和俯仰角差值
                        ///20200413whq delete the following
                        //mtg_cal_diff(mtg);
                    }
                    else
                    {
                        mtg->maj.azidiff=0.0;
                        mtg->maj.pitchdiff=0.0;
                    }
                    mtg_laser_to_aj(mtg);
                    time(&mtg->maj.t4);
                    mtg->maj.status=1;
                    mtg->maj.deth=mtg->deth;
                    mtg->maj.detv=mtg->detv;
                    mtg->maj.coverflag=0;
                    //lock(&mtg->ajlock);
                    if(sqlite_export_origin_aj(mtg,mtg->sqlitepath)==0)
                    {
                        ///成功
                        mtg_log(mtg,MTG_LOG_FINISH_STORE_ORIGIN_SEG);
                        mtg->pd.max=0;
                        time(&mtg->pd.t);
                        if(sqlite_export_pdmax(mtg,mtg->sqlitepath))
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_STORE_PDMAX);
                            ///fail=1;
                            mtg->maj.status=0;
                            if(sqlite_export_origin_aj(mtg,mtg->sqlitepath)==0)
                            {
                                mtg_log(mtg,MTG_LOG_FINISH_RESET_ORIGIN_SEG);
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_RESET_ORIGIN_SEG);
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FINISH_STORE_PDMAX);
                            mtg->maj01=mtg->maj0;
                        }
                    }
                    else
                    {
                        ///失败
                        mtg_log(mtg,MTG_LOG_FAIL_STORE_ORIGIN_SEG);
                        ///fail=1;
                    }
                    //unlock(&mtg->ajlock);
                    break;
                }
            }
            else
            {
                //trace(0,"tickcycle=%d,tick=%d,cyc=%d\n",tickcycle,tickget(),mtg->iset.cyc);
                if(!mtg->pause && (mtg->restart || tickget()-tickcycle>mtg->iset.cyc*1000))
                {
                    //trace(0,"1:tick=%d,cyc=%d\n",tickget(),mtg->iset.cyc);
                    mtg->restart=0;
                    mtg->incycle=1;
                    mtg->opera = MTG_OPERA_TPS;
                    tickcam1=tickcam2=0;
                    ticktps=0;
                    if(tickget()-tickback>mtg->iset.bcyc*1000)
                    {
                        bc=1;
                    }
                    else
                    {
                        bc=0;
                    }
                    istep=0;
                    mtg_log(mtg,MTG_LOG_START_CYCLE);
                    mtg->fmain=fopen(mtg->pmain,"w");
                    //trace(0,"2:tick=%d,cyc=%d\n",tickget(),mtg->iset.cyc);
                }
                else  ///get power capacity
                {
                    //trace(0,"3:tick=%d,cyc=%d,tickpower=%d\n",tickget(),mtg->iset.cyc,tickpower);
                    if(tickpower == 3000)
                    {
                        tickpower=0;
                        //if(tps_get_power(&mtg->tps)==0)
                        if(tps_get_incline(&mtg->tps)==0)
                        {
                            //trace(0,"4:tick=%d,cyc=%d\n",tickget(),mtg->iset.cyc);
                            while(tps_get_rc(&mtg->tps,0,&rc)) sleepms(0);
                            if(rc==0)
                            {
                                //trace(0,"5:tick=%d,cyc=%d\n",tickget(),mtg->iset.cyc);
                            }
                            else
                            {
                                //trace(0,"6:tick=%d,cyc=%d\n",tickget(),mtg->iset.cyc);
                            }
                        }
                    }
                    tickpower++;
                }
            }
        }
        else if(mtg->ithread == MTG_THREAD_ORIGIN)
        {
            if(fail)
            {
                camsvr_stop(&mtg->camsvr);
                mtg_log(mtg,MTG_LOG_FAIL_ORIGIN);
                if(mtg->fmain)
                {
                    fclose(mtg->fmain);
                    mtg->fmain=0;
                }
                break;
            }
            else if(istep==18)
            {
                camsvr_stop(&mtg->camsvr);
                mtg_log(mtg,MTG_LOG_FINISH_ORIGIN);
                if(mtg->fmain)
                {
                    fclose(mtg->fmain);
                    mtg->fmain=0;
                }
                //trace(0,"cam:%f,%f,%f,%f\n",mtg->m.cam[0],mtg->m.cam[1],mtg->m.cam[2],mtg->m.cam[3]);
                //trace(0,"inc:%f,%f\n",mtg->m.inc[0],mtg->m.inc[1]);
                //trace(0,"angle:%f,%f\n",mtg->m.angle[0],mtg->m.angle[1]);
                break;
            }
        }
        sleepms(10);
    }

    //trace(0,"stat=%d,istep=%d\n",mtg->stat,istep);
    ///等待全站仪操作结束
    if(mtg->tps.opera)
    {
        while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(10);
    }

    if((fail || !mtg->stat) && (istep>=15 && istep!=18))
    {
        if(mtg->tps.lasertype==0||mtg->tps.type==TPS_TRIMBLE)
        {
            if(tps_stop_laser(&mtg->tps)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(10);
                if(rc==0)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                }
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
            }
        }
        else if(mtg->tps.lasertype==1)
        {
            if(tps_stop_laserpoint(&mtg->tps)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(10);
                if(rc==0)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                }
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);

            }
        }

    }

    /*if(fail&&istep==18)
    {
        mtg_log(mtg,MTG_LOG_FAIL_ORIGIN_SEG);

    }
    else */if(mtg->ithread==MTG_THREAD_CYCLE)
    {
        mtg_log(mtg,MTG_LOG_END_CYCLE);
    }
    mtg->thread=0;
    mtg->originstat=mtg->stat=0;
    mtg->run=0;

    if(fp)
    {
        fclose(fp);
        fp=NULL;
    }
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _ajthread(void* arg)
#else
static void *_ajthread(void *arg)
#endif
{
    mtg_t* mtg=0;
    unsigned int tickcycle=0;
    int fail=0;
    int naj=0;
    double sumaj=0;
    time_t t;
    int ntimes=5;
    int curtimes=0;
    //double* pds=(double*)malloc(ntimes*sizeof(double));
    double pd0=0,pd=0;
    double temppdmax;
    time_t temppdt;
    int i=0;
    char timestr[256];
    int num1,num2;

    FILE* fp=fopen("D://mtg_thread_aj_meas.log","a");

    mtg=(mtg_t*)arg;
    if(fp)
    {
        time(&t);
        strftime(timestr,64,"%Y-%m-%d %H:%M:%S",localtime(&t));
        fprintf(fp,"%s\n",timestr);
        fprintf(fp,"ajthread\n");
        fflush(fp);
    }
    mtg->ajstat=1;
    while(mtg->ajstat)
    {
        if(mtg->t>mtg->t0)///获取PLC数据更新
        {
            if(fp)
            {
                strftime(timestr,64,"%Y-%m-%d %H:%M:%S",localtime(&mtg->t));
                fprintf(fp,"t:%s\n",timestr);
                strftime(timestr,64,"%Y-%m-%d %H:%M:%S",localtime(&mtg->t0));
                fprintf(fp,"t:%s\n",timestr);
                fflush(fp);
            }
            mtg->t0=mtg->t;
            naj=0;
            sumaj=0;
            for(i=0;i<mtg->tbm.naj;i++)
            {
                if(mtg->maj.iaj[i]==1)
                {
                    naj++;
                    sumaj+=mtg->maj.daj[i];
                }
            }
            if(naj<=0)
            {
                //continue;
            }

            pd=sumaj/naj;
            if(fp)
            {
                fprintf(fp,"pd:%.4f,sumaj:%.4f,naj:%d\n",pd,sumaj,naj);fflush(fp);
            }

            ///在掘进状态下判断油缸最大值是否需要更新
            if(mtg->maj.driving==1)
            {
                if(fp)
                {
                    fprintf(fp,"pd:%.4f,max:%.4f\n",pd,mtg->pd.max);
                    fflush(fp);
                }
                if(pd>mtg->pd.max)
                {
                    temppdmax=mtg->pd.max;
                    temppdt=mtg->pd.t;
                    mtg->pd.max=pd;
                    time(&mtg->pd.t);
                    fail=0;
                    if(sqlite_export_pdmax(mtg,mtg->sqlitepath))
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_STORE_PDMAX);
                        fail=1;
                        mtg->pd.max=temppdmax;
                        mtg->pd.t=temppdt;
                    }
                    else
                    {
                        //mtg_log(mtg,MTG_LOG_FINISH_STORE_PDMAX);
                    }
                    if(fp)
                    {
                        fprintf(fp,"pd:%.4f,max:%.4f,fail:%d\n",pd,mtg->pd.max,fail);
                        fflush(fp);
                    }

                }
                ///在初始标定的情况下每隔一定周期计算一次
                if(mtg->maj0.status==1&&tickget()-tickcycle>mtg->iset.cyc*1000)
                {
                    ///20200413whq delete the following
                    /*if(mtg->maj0.coverflag==0)
                    {
                        num1=num2=0;
                        for(i=0;i<mtg->tbm.naj;i++)
                        {
                            if(mtg->maj.daj[i]-mtg->maj0.daj[i]<0.03)
                            {
                                num1++;
                            }
                            else if(mtg->maj.daj[i]-mtg->maj0.daj[i]>0.03)
                            {
                                num2++;
                            }
                        }
                        if(num1==mtg->tbm.naj)
                        {
                            mtg->maj.coverflag=1;
                            time(&mtg->maj.t4);
                            if(sqlite_export_origin_aj(mtg,mtg->sqlitepath)==0)
                            {
                                ///成功
                                mtg_log(mtg,MTG_LOG_FINISH_UPDATE_AJ_MEASURE);
                            }
                            else
                            {
                                ///失败
                                mtg_log(mtg,MTG_LOG_FAIL_UPDATE_AJ_MEASURE);
                                fail=1;
                            }
                        }
                        else if(num2==mtg->tbm.naj)
                        {
                            mtg->maj0.coverflag=1;
                            time(&mtg->maj0.t4);
                            if(sqlite_update_origin_aj(mtg,mtg->sqlitepath)==0)
                            {
                                ///成功
                                mtg_log(mtg,MTG_LOG_FINISH_UPDATE_AJ_MEASURE);
                            }
                            else
                            {
                                ///失败
                                mtg_log(mtg,MTG_LOG_FAIL_UPDATE_AJ_MEASURE);
                                fail=1;
                                mtg->maj0.coverflag=0;
                            }
                        }
                    }
                    else*/
                    {
                        fail=0;
                        mtg->maj.inc[0]=mtg->m1.inc[0];
                        mtg->maj.inc[1]=mtg->m1.inc[1];
                        if(fp)
                        {
                            fprintf(fp,"mtg_cal_aj_gesture\n");fflush(fp);
                        }

	                    if(mtg_cal_aj_gesture(mtg)==0)
	                    {
	                        time(&mtg->m.t1);
	                        time(&mtg->m.t2);
	                        time(&mtg->m.t3);
	                        if(mtg_store_meas(mtg))
	                        {
	                            mtg_log(mtg,MTG_LOG_FINISH_STORE_MEASURE);
	                        }
	                        else
	                        {
	                            mtg_log(mtg,MTG_LOG_FAIL_STORE_MEASURE);
	                            fail=1;
	                        }
	                        if(sqlite_export_meas_aj(mtg,mtg->sqlitepath)==0)
	                        {
	                            ///成功
	                            mtg_log(mtg,MTG_LOG_FINISH_STORE_AJ_MEASURE);
	                        }
	                        else
	                        {
	                            ///失败
	                            mtg_log(mtg,MTG_LOG_FAIL_STORE_AJ_MEASURE);
	                            fail=1;
	                        }
	                        if(fail==0)
	                        {
	                            mtg_log(mtg,MTG_LOG_FINISH_CYCLE);
	                        }
	                        tickcycle=tickget();
	                    }
	                    else
	                    {
	                        ///油缸数据不足，少于3个，或者在平面拟合时出错
	                        fail=1;
	                    }
	                    if(fail==0)
	                    {
	                        mtg_log(mtg,MTG_LOG_FINISH_AJ_CYCLE);
	                    }
	                    else
	                    {
	                        mtg_log(mtg,MTG_LOG_FAIL_AJ_CYCLE);
	                    }
	                }
	            }
			}

            ///当前的行程比最大的行程小0.1以上且当前处于标定好状态，则标定状态更新为0，说明需要进入一下环标定了
            if(mtg->maj.driving==0)
            {
                if(!mtg->originstat)
                {
                    if((mtg->pd.max-pd)>0.1&&mtg->maj0.status==1)
                    {
                        mtg->maj.deth=mtg->maj0.deth;
                        mtg->maj.detv=mtg->maj0.detv;
                        mtg->maj.status=0;
                        fail=0;
                        if(sqlite_export_origin_aj(mtg,mtg->sqlitepath))
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_RESET_ORIGIN_SEG);
                            fail=1;
                        }
                        curtimes=0;
                    }
                }

                ///当前油缸长度小于最大长度，且差值有L*0.9时,累计ntimes次则认为可以进行自动标定了
                if(mtg->maj0.status==0 && mtg->maj.amoding==0)
                {
                    if((mtg->pd.max-pd)>mtg->segset.L*0.9)
                    {
                        if(fabs(pd-pd0)<0.001)
                            curtimes++;
//                        else
//                        {
//                            if(pd-pd0>0.005)
//                                curtimes=0;
//                        }
                    }
                    if(fp)
                    {
                        fprintf(fp,"curtimes:%d,ntimes:%d,autoflag:%d,pdmax:%.4f,pd:%.4f,pd0:%.4f\n",curtimes,ntimes,mtg->autoflag,mtg->pd.max,pd,pd0);fflush(fp);
                        if(mtg->thread)
                        {
                            fprintf(fp,"mtg->thread is running\n");fflush(fp);
                        }
                    }
                    if(curtimes>=ntimes)
                    {
                        ///启动自动标定过程,在非拼装状态下和可以自动标定情况下
                        ///20200413whq delete the following
//                        if(!mtg->thread && mtg->maj.amoding==0 && mtg->autoflag==1)
//                            mtg_start_origin_segmeas(mtg);
                    }
                }

                if(mtg->maj0.status==1)
                    curtimes=0;
            }

            pd0=pd;
        }
        sleepms(10);
    }

    mtg->ajthread=0;
    mtg->ajstat=0;

    if(fp)
    {
        fprintf(fp,"close\n");
        fclose(fp);
        fp=NULL;
    }
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_check_thread(void* arg)
#else
static void *_mtg_check_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int istep=0;
    char incbuf[1024]={0};
    char incword[1024]={0};
    char* ptr=0;
    int nword=0;
    int inclen=0;
    int i,k;
    double cam[2];
    time_t now;
    int opera=0,rc=0,grc=0;
    int tickinc1=0,tickinc2=0,tickcam1=0,tickcam2=0,ticktps=0;
    unsigned int tickcycle=0,ticknow=0,tickback=0;
    int bc=1;
    int fail=0;
    double dx,dy,dz,dh,dv,dl;
    double tx[10],ty[10],sx[10],sy[10];
    int nxy=0;
    int timeout=30000;
    unsigned int tickwait=0,tickpower=0;
    double dinc=0.0;
    double laserheight=0.0;
    double laserx=0.0,lasery=0.0;
    unsigned char chal=0;
    double rlt=0.0;

    nPitch=0;
    nRotate=0;
    mtg=(mtg_t*)arg;
    mtg_log(mtg,MTG_LOG_START_CYCLE);

    laserheight=mtg->tps.laserheight/1000.0;
    if(mtg->tps.lasertype==0)
    {
        if(mtg->tps.laserdist[0]>1.0e-6)
        {
            laserx=atan(mtg->tps.laserx[0]/1000.0/mtg->tps.laserdist[0]);
            lasery=atan(mtg->tps.lasery[0]/1000.0/mtg->tps.laserdist[0]);
        }
    }
    else if(mtg->tps.lasertype==1)
    {
        if(mtg->tps.laserdist[1]>1.0e-6)
        {
            laserx=atan(mtg->tps.laserx[1]/1000.0/mtg->tps.laserdist[1]);
            lasery=atan(mtg->tps.lasery[1]/1000.0/mtg->tps.laserdist[1]);
        }
    }

    mtg->stat=1;
    mtg->opera=MTG_OPERA_TPS | MTG_OPERA_INC;

    istep=0;
    mtg->incycle=1;
    while(mtg->stat)
    {
        ///

        if(mtg->opera & MTG_OPERA_TPS)
        {
            if(istep==0)
            {
                dx=mtg->m1.prism[0]-mtg->istn.statx;
                dy=mtg->m1.prism[1]-mtg->istn.staty;
                dz=mtg->m1.prism[2]-mtg->istn.statz-mtg->istn.stath;
                dh=atan2(dy,dx);
                if(dh<0) dh+=2*PI;
                //if(dh>=2*PI) dh-=2*PI;
                //20180115whq增加下面的语句
                dh-=mtg->istn.anglediff;
                if(dh<0) dh+=2*PI;
                //if(dh>=2*PI) dh-=2*PI;
                //20180115whq增加结束

                dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                dv=PI/2-atan(dz/dl);
                if(tps_make_position(&mtg->tps,dh,dv)==0)
                {
                    mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                    istep++;
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                    fail=1;
                }
            }
            else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
            {
                if(rc==0)
                {
                    if(istep==1)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_TARGET_PRISM);
                        if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==2)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_PRISM);
                        if(tps_do_measure(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);

                            fail=1;
                        }
                    }
                    else if(istep==3)
                    {
                        if(tps_get_measure(&mtg->tps)==0)
                        {
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);

                            fail=1;
                        }
                    }
                    else if(istep==4)
                    {
                        dh=mtg->tps.horizon;
                        dv=mtg->tps.vertical;
                        //if(mtg->tps.type==TPS_TRIMBLE)
                            //mtg->tps.dist+=mtg->tps.prism;
                        //20180115whq增加下面的第一句
                        dh+=mtg->istn.anglediff;
                        //20180115whq增加结束

                        dl=mtg->tps.dist+mtg->tarset.prc/1000.0;
                        mtg->mp.prism[6]=mtg->istn.statx+dl*cos(PI/2-dv)*cos(dh);
                        mtg->mp.prism[7]=mtg->istn.staty+dl*cos(PI/2-dv)*sin(dh);
                        mtg->mp.prism[8]=mtg->istn.statz+mtg->istn.stath+dl*sin(PI/2-dv);

                        if(tps_clear_measure(&mtg->tps)==0)
                        {
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==5)
                    {
                        dx=mtg->mp.prism[9]-mtg->istn.statx;
                        dy=mtg->mp.prism[10]-mtg->istn.staty;
                        dz=mtg->mp.prism[11]-mtg->istn.statz-mtg->istn.stath;
                        dh=atan2(dy,dx);
                        //if(dh<0) dh+=2*PI;
                        //if(dh>=2*PI) dh-=2*PI;
                        //20180115whq增加下面的语句
                        dh-=mtg->istn.anglediff;
                        //if(dh<0) dh+=2*PI;
                        //if(dh>=2*PI) dh-=2*PI;
                        //20180115whq增加结束

                        dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                        dv=PI/2-atan(dz/dl);
                        if(tps_make_position(&mtg->tps,dh,dv)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==6)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_TARGET_PRISM);
                        if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==7)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_PRISM);
                        if(tps_do_measure(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==8)
                    {
                        if(tps_get_measure(&mtg->tps)==0)
                        {
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==9)
                    {
                        dh=mtg->tps.horizon;
                        dv=mtg->tps.vertical;
                        dl=mtg->tps.dist;
                        //20180115whq增加下面的语句
                        dh+=mtg->istn.anglediff;
                        //20180115whq增加结束

                        mtg->mp.prism[9]=mtg->istn.statx+dl*cos(PI/2-dv)*cos(dh);
                        mtg->mp.prism[10]=mtg->istn.staty+dl*cos(PI/2-dv)*sin(dh);
                        mtg->mp.prism[11]=mtg->istn.statz+mtg->istn.stath+dl*sin(PI/2-dv);

                        if(tps_clear_measure(&mtg->tps)==0)
                        {
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                    }
                    else if(istep==10)
                    {
                        mtg->mp.inc[3] = mtg->m.inc[0];
                        mtg->mp.inc[4] = mtg->m.inc[1];
                        //mtg_2p_gesture(mtg);
                    }
                }
            }

        }
        sleepms(10);
    }

    //trace(0,"stat=%d,istep=%d\n",mtg->stat,istep);
    ///等待全站仪操作结束
    if(mtg->tps.opera)
    {
        while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(10);
    }


    if((fail || !mtg->stat) && istep>=14)
    {
        if(mtg->tps.lasertype==0)
        {
            if(tps_stop_laser(&mtg->tps)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(10);
                if(rc==0)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);

                }
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);

            }
        }
        else if(mtg->tps.lasertype==1)
        {
            if(tps_stop_laserpoint(&mtg->tps)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(10);
                if(rc==0)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);

                }
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);

            }
        }

    }

    if(mtg->ithread==MTG_THREAD_CYCLE)
    {
        mtg_log(mtg,MTG_LOG_END_CYCLE);
    }
    mtg->thread=0;
    mtg->stat=0;
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_position_thread(void* arg)
#else
static void *_mtg_position_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int istep=0;
    int opera=0,rc=0,grc;
    int fail=0;
    double dx,dy,dz,dh,dv,dl;

    mtg=(mtg_t*)arg;

    mtg->stat=1;

    while(mtg->stat)
    {
        //trace(0,"step=%d\n",istep);
        if(mtg->ithread==MTG_THREAD_POSITION_BACK)
        {
            if(istep==0)
            {
                dx=mtg->prismcoord[0]-mtg->istn.statx;
                dy=mtg->prismcoord[1]-mtg->istn.staty;
                dz=mtg->prismcoord[2]-mtg->istn.statz-mtg->istn.stath;
                dh=atan2(dy,dx);
                dh-=mtg->istn.anglediff;
                //if(dh<0) dh+=2*PI;
                //if(dh>=2*PI) dh-=2*PI;
                dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                dv=PI/2-atan(dz/dl);
                //trace(0,"back:dh=%.12f,dv=%.12f\n",dh,dv);
                if(tps_make_position(&mtg->tps,dh,dv)==0)
                {
                    mtg_log(mtg,MTG_LOG_BEGIN_TARGET_BACKSIGHT);
                    istep++;
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                    fail=1;
                }
            }
            else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
            {
                if(rc==0)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_TARGET_BACKSIGHT);
                    break;
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                    fail=1;
                }
            }
        }
        else if(mtg->ithread==MTG_THREAD_POSITION_PRISM)
        {
            if(istep==0)
            {
                dx=mtg->prismcoord[0]-mtg->istn.statx;
                dy=mtg->prismcoord[1]-mtg->istn.staty;
                dz=mtg->prismcoord[2]-mtg->istn.statz-mtg->istn.stath;
                dh=atan2(dy,dx);
                dh-=mtg->istn.anglediff;

                //if(dh<0) dh+=2*PI;
                //if(dh>=2*PI) dh-=2*PI;
                dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                dv=PI/2-atan(dz/dl);
                //trace(0,"prism:dh=%.12f,dv=%.12f\n",dh,dv);
                if(tps_make_position(&mtg->tps,dh,dv)==0)
                {
                    mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                    istep++;
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                    fail=1;
                }
            }
            else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
            {
                if(rc==0)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_TARGET_PRISM);
                    break;
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                    fail=1;
                }
            }
        }

        if(fail)
        {
            break;
        }
        sleepms(10);
    }
    mtg->thread=0;
    mtg->stat=0;
    //if(mtg->iclient==2) client_thread(mtg,0);
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_measure_thread(void* arg)
#else
static void *_mtg_measure_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int istep=0;
    int opera=0,rc=0,grc=0;
    int fail=0;
    double dh,dv,dl;
    double h,v;
    FILE *fp=fopen("D:\\midu\\measurethread.log","w");
    mtg=(mtg_t*)arg;

    mtg->stat=1;

    while(mtg->stat)
    {
        if(istep==0)
        {
            if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                istep++;
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                fail=1;
            }
        }
        else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
        {
            if(rc==0)
            {
                if(istep==1)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_PRISM);
                    if(tps_do_measure(&mtg->tps)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_PRISM);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                        fail=1;
                    }
                }
                else if(istep==2)
                {
                    if(tps_get_measure(&mtg->tps)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                        fail=1;
                    }
                }
                else if(istep==3)
                {
                    if(fp)
                    {
                        fprintf(fp,"vertical=%.4f\n",mtg->tps.vertical);
                        fflush(fp);
                    }
                    if(mtg->tps.vertical>PI)
                    {
                        h=mtg->tps.horizon-PI;
                        if(h<0.0) h+=2.0*PI;
                        v=2.0*PI-mtg->tps.vertical;
                        if(tps_make_position(&mtg->tps,h,v)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                            fail=1;
                        }
                    }
                    else
                    {
                        if(mtg->ithread==MTG_THREAD_MEASUREBACK)
                        {
                            mtg->backmeas[0]=mtg->tps.horizon+mtg->istn.anglediff;
                            mtg->backmeas[1]=mtg->tps.vertical;
                            mtg->backmeas[2]=mtg->tps.dist;
                            //trace(0,"measurethread:hz=%.12f,vz=%.12f,s=%.12f\n",mtg->backmeas[0],mtg->backmeas[1],mtg->backmeas[2]);
                        }
                        else if(mtg->ithread==MTG_THREAD_MEASUREPRISM)
                        {
                            if(fp)
                            {
                                fprintf(fp,"MTG_THREAD_MEASUREPRISM\n");
                            }
                            dh=mtg->tps.horizon;
                            dv=mtg->tps.vertical;
                            //if(mtg->tps.type==TPS_TRIMBLE)
                                //mtg->tps.dist+=mtg->tps.prism;
                            ///dl=mtg->tps.dist+mtg->tarset.prc/1000.0;
                            dl=mtg->tps.dist+0.0344+mtg->prc/1000.0;

                            dh+=mtg->istn.anglediff;

                            mtg->prismcoord[0]=mtg->istn.statx+dl*cos(PI/2-dv)*cos(dh);
                            mtg->prismcoord[1]=mtg->istn.staty+dl*cos(PI/2-dv)*sin(dh);
                            mtg->prismcoord[2]=mtg->istn.statz+mtg->istn.stath+dl*sin(PI/2-dv);
                            //time(&mtg->m.t3);
                        }

                        if(fp)
                        {
                            fprintf(fp,"before\n");fflush(fp);
                        }
                        if(tps_clear_measure(&mtg->tps)==0)
                        {
                            if(fp)
                            {
                                fprintf(fp,"tps_clear_measure ok\n");fflush(fp);
                            }
                            istep=5;
                        }
                        else
                        {
                            if(fp)
                            {
                                fprintf(fp,"tps_clear_measure fail\n");fflush(fp);
                            }
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                    }
                }
                else if(istep==4)
                {
                    if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                        istep=1;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                        fail=1;
                    }
                }
                else if(istep==5)
                {
                    if(fp)
                    {
                        fprintf(fp,"istep5,ok\n");fflush(fp);
                    }
                    mtg_log(mtg,MTG_LOG_FINISH_MEASURE_PRISM);
                    break;
                }
            }
            else
            {
                if(istep==1)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                }
                else if(istep==2 || istep==3 || istep==4)
                {
                    if(fp)
                    {
                        fprintf(fp,"istrp%dfail\n",istep);fflush(fp);
                    }
                    mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                }
                fail=1;
            }
        }

        if(fail)
        {
            break;
        }
        sleepms(10);
    }

    if(fp)
    {
        fprintf(fp,"end\n");
        fflush(fp);
        fclose(fp);
    }
    mtg->thread=0;
    mtg->stat=0;
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_setup_thread(void* arg)
#else
static void *_mtg_setup_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int istep=0;
    int opera=0,rc=0,grc;
    int fail=0;
    double ori=0.0;
    double dh,dv,dl,x,y,z,dx,dy,dz;
    //FILE* fp=fopen("D://setup.log","w");

    mtg=(mtg_t*)arg;

    mtg->stat=1;

    while(mtg->stat)
    {
        if(istep==0)
        {
            if(tps_set_station(&mtg->tps,mtg->istn.statx,mtg->istn.staty,mtg->istn.statz,mtg->istn.stath)==0)
            {
                istep++;
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_SET_STATION);
                fail=1;
            }
        }
        else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
        {
            if(rc==0)
            {
                if(istep==1)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_SET_STATION);
                    if(tps_set_height(&mtg->tps,mtg->istn.backh)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_SET_PRISM_HEIGHT);
                        fail=1;
                    }
                }
                else if(istep==2)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_SET_PRISM_HEIGHT);
                    ori=atan2(mtg->istn.backy-mtg->istn.staty,mtg->istn.backx-mtg->istn.statx);
                    if(ori<0) ori+=2*PI;
                    if(tps_set_orientation(&mtg->tps,ori)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_SET_ORIENTATION);
                        fail=1;
                    }
                }
                else if(istep==3)
                {
                    //mtg_log(mtg,MTG_LOG_FINISH_SET_ORIENTATION);
                    /*time(&mtg->istn.t);
                    if(mtg_store_station(mtg))
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_STORE_STATION);
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_STORE_STATION);
                        fail=1;
                    }*/
                    //break;
                    if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_BACKSIGHT,0);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BACKSIGHT,1);
                        fail=1;
                    }
                }
                else if(istep==4)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_BACKSIGHT);
                    if(tps_do_measure(&mtg->tps)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_BACKSIGHT,0);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                        fail=1;
                    }
                }
                else if(istep==5)
                {
                    if(tps_get_measure(&mtg->tps)==0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BACKSIGHT);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                        fail=1;
                    }
                }
                else if(istep==6)
                {
                    dh=mtg->tps.horizon;
                    dv=mtg->tps.vertical;
                    //if(mtg->tps.type==TPS_TRIMBLE)
                        //mtg->tps.dist+=mtg->tps.prism;
                    dl=mtg->tps.dist;

                    mtg->istn.anglediff=ori-dh;
                    //x=mtg->istn.statx+dl*cos(PI/2-dv)*cos(dh);
                    //y=mtg->istn.staty+dl*cos(PI/2-dv)*sin(dh);
                    z=mtg->istn.statz+mtg->istn.stath+dl*sin(PI/2-dv);

                    //dx=mtg->istn.backx-x;
                    //dy=mtg->istn.backy-y;

                    //20180115whq修改，原先的代码中没有mtg->istn.backh
                    //dz=mtg->istn.backz+mtg->istn.backh-z;

                    //fprintf(fp,"x,y,z:%.4f,%.4f,%.4f\n",x,y,z);
                    //fprintf(fp,"dx,dy,dz:%.4f,%.4f,%.4f\n",dx,dy,dz);
                    //fprintf(fp,"balw:%d\n",mtg->iset.balw);
                    //fflush(fp);
                    x=sqrt((mtg->istn.backy-mtg->istn.staty)*(mtg->istn.backy-mtg->istn.staty)+(mtg->istn.backx-mtg->istn.statx)*(mtg->istn.backx-mtg->istn.statx));
                    dx=x-dl*cos(PI/2-dv);
                    dz=mtg->istn.backz+mtg->istn.backh-z;

                    //trace(0,"dist=%.4f,dl=%.4f,dv=%.4f,pitch=%.4f",dist,dl,PI/2-dv,pitch);
                    //20180115whq修改，恢复原来对后视的检核过程
                    if(fabs(dx)<mtg->iset.balw/1000.0&&fabs(dz)<mtg->iset.balw/1000.0)
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_SET_ORIENTATION,0);
                        goto finish;
                        break;
                    }
                    else
                    {
                        fail=1;
                        mtg_log(mtg,MTG_LOG_BACKSIGHT_OVER_LIMIT);
                        //mtg_log(mtg,MTG_LOG_FAIL_SET_ORIENTATION);
                        goto finish;
                        break;
                    }
                }
            }
            else
            {
                if(istep==1)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_SET_STATION);
                }
                else if(istep==2)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_SET_PRISM_HEIGHT);
                }
                else if(istep==3)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BACKSIGHT);
                }
                else if(istep==4)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                }
                else if(istep==5)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                }
                else if(istep==6)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_SET_ORIENTATION);
                }
                fail=1;
            }
        }
        if(fail)
        {
            break;
        }
        sleepms(10);
    }
    finish:
    mtg->thread=0;
    mtg->stat=0;
    //fclose(fp);
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_resetup_thread(void* arg)
#else
static void *_mtg_resetup_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int istep=0;
    int opera=0,rc=0,grc;
    int fail=0;
    double ori=0.0;
    double dx,dy,dz,dh;
    double dl,dv;

    mtg=(mtg_t*)arg;

    mtg->stat=1;

    while(mtg->stat)
    {
        if(istep==0)
        {
            dx=mtg->istn.backx-mtg->istn.statx;
            dy=mtg->istn.backy-mtg->istn.staty;
            dz=mtg->istn.backz+mtg->istn.backh-mtg->istn.statz-mtg->istn.stath;
            dh=atan2(dy,dx);
            //if(dh<0) dh+=2*PI;
            //if(dh>=2*PI) dh-=2*PI;
            //加入方位角与全站仪的水平角差值
            dh=dh-mtg->istn.anglediff;
            //if(dh<0) dh+=2*PI;
            //if(dh>=2*PI) dh-=2*PI;

            dl=sqrt(dx*dx+dy*dy)+0.0000000001;
            dv=PI/2-atan(dz/dl);
            if(tps_make_position(&mtg->tps,dh,dv)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_TARGET_BACKSIGHT);
                istep++;
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                fail=1;
            }
        }
        else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
        {
            if(rc==0)
            {
                if(istep==1)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_TARGET_BACKSIGHT);

                    if(tps_fine_adjust(&mtg->tps,0.1,0.1)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_BACKSIGHT);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BACKSIGHT);
                        fail=1;
                    }
                }
                else if(istep==2)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_BACKSIGHT);
                    if(tps_do_measure(&mtg->tps)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_BACKSIGHT);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                        fail=1;
                    }
                }
                else if(istep==3)
                {
                    if(tps_get_measure(&mtg->tps)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                        fail=1;
                    }
                }
                else if(istep==4)
                {
                    dh=mtg->backmeas[0]=mtg->tps.horizon;
                    dv=mtg->backmeas[1]=mtg->tps.vertical;
                    //if(mtg->tps.type==TPS_TRIMBLE)
                        //mtg->tps.dist+=mtg->tps.prism;
                    dl=mtg->backmeas[2]=mtg->tps.dist;
                    if(tps_clear_measure(&mtg->tps)==0)
                    {
                        //istep=5;
                        istep++;
                    }
                    else
                    {
                        fail=1;
                    }
                }
                else if(istep==5)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BACKSIGHT);
                    if(tps_set_station(&mtg->tps,mtg->istn.statx,mtg->istn.staty,mtg->istn.statz,mtg->istn.stath)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_SET_STATION);
                        fail=1;
                    }
                }
                else if(istep==6)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_SET_STATION);
                    if(tps_set_height(&mtg->tps,mtg->istn.backh)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_SET_PRISM_HEIGHT);
                        fail=1;
                    }
                }
                else if(istep==7)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_SET_PRISM_HEIGHT);
                    ori=atan2(mtg->istn.backy-mtg->istn.staty,mtg->istn.backx-mtg->istn.statx);
                    if(ori<0) ori+=2*PI;
                    if(tps_set_orientation(&mtg->tps,ori)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_SET_ORIENTATION);
                        fail=1;
                    }
                }
                else if(istep==8)
                {
                    mtg->istn.anglediff=ori-dh;
                    mtg_log(mtg,MTG_LOG_FINISH_SET_ORIENTATION);
                    break;
                }
            }
            else
            {
                if(istep==1)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                }
                else if(istep==2)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BACKSIGHT);
                }
                else if(istep==3 || istep==4)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                }
                else if(istep==5)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_SET_STATION);
                }
                else if(istep==6)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_SET_PRISM_HEIGHT);
                }
                else if(istep==7)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_SET_ORIENTATION);
                }
                fail=1;
            }
        }

        if(fail)
        {
            break;
        }
        sleepms(10);
    }
    mtg->thread=0;
    mtg->stat=0;
    //if(mtg->iclient==2) client_thread(mtg,0);
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_basket_thread(void* arg)
#else
static void *_mtg_basket_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int istep=0;
    int opera=0,rc=0,grc=0;
    int fail=0;
    double l0,l1,x1,y1;
    double dx,dy,dz,dh,dv,dl;
    double dh1,dh2,dh3,dv1,dv2,dv3;
    double *val=0,*val1=0;
    int i,j;
    int iset=0;
    int itarget=0;
    double hi1,hi2,vi1,vi2,di1,di2,hi,vi,di,h,v,dist;


    mtg=(mtg_t*)arg;

    mtg->stat=1;

    val=(double*)malloc(mtg->baskset*4*3*sizeof(double));

    /*road_xy2l(&mtg->r,mtg->setup.statx,mtg->setup.staty,&l0,0,0,0,0);

    road_l2xy(&mtg->r,l0+mtg->baskdist,&x1,&y1,0);
    dx=x1-mtg->setup.statx;
    dy=y1-mtg->setup.staty;
    dz=0.0;
    dh2=atan2(dy,dx);
    if(dh2<0) dh2+=2*PI;
    dl=sqrt(dx*dx+dy*dy);
    dv2=PI/2-atan(dz/dl);*/

    while(mtg->stat && !fail)
    {
        if(istep==0)
        {
            if(tps_fine_adjust(&mtg->tps,0.1,0.1)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_BASKET);
                istep++;
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BASKET);
                fail=1;
            }
        }
        else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
        {
            if(rc==0)
            {
                if(istep==1)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_BASKET);
                    if(tps_do_measure(&mtg->tps)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_BASKET);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BASKET);
                        fail=1;
                    }
                }
                else if(istep==2)
                {
                    if(tps_get_measure(&mtg->tps)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BASKET);
                        fail=1;
                    }
                }
                else if(istep==3)
                {
                    if(mtg->tps.vertical>PI)
                    {
                        h=mtg->tps.horizon-PI;
                        if(h<0.0) h+=2.0*PI;
                        v=2.0*PI-mtg->tps.vertical;
                        if(tps_make_position(&mtg->tps,h,v)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_BASKET);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_BASKET);
                            fail=1;
                        }
                    }
                    else
                    {
                        dh2=mtg->tps.horizon;
                        dv2=mtg->tps.vertical;

                        if(tps_clear_measure(&mtg->tps)==0)
                        {
                            istep=5;
                        }
                        else
                        {
                            fail=1;
                        }
                    }
                }
                else if(istep==4)
                {
                    if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_BASKET);
                        istep=1;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BASKET);
                        fail=1;
                    }
                }
                else if(istep==5)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BASKET);
                    break;
                }
            }
            else
            {
                if(istep==1 || istep==4)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BASKET);
                }
                else if(istep==2 || istep==3 || istep==5)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BASKET);
                }
                fail=1;
            }
        }
        sleepms(10);
    }
    istep=0;
    while(mtg->stat && !fail)
    {
        if(istep==0)
        {
            dx=mtg->istn.backx-mtg->istn.statx;
            dy=mtg->istn.backy-mtg->istn.staty;
            dz=mtg->istn.backz+mtg->istn.backh-(mtg->istn.statz+mtg->istn.stath);
            dh=atan2(dy,dx);
            dh-=mtg->istn.anglediff;

            if(dh<0) dh+=2*PI;
            if(dh>=2*PI) dh-=2*PI;
            dl=sqrt(dx*dx+dy*dy)+0.0000000001;
            dv=PI/2-atan(dz/dl);
            dh1=dh+PI;
            if(dh1>2*PI) dh1-=2*PI;
            dv1=2*PI-dv;
            dh3=dh2+PI;
            if(dh3>2*PI) dh3-=2*PI;
            dv3=2*PI-dv2;
            for(i=0;i<mtg->baskset;i++)
            {
                val[12*i]=dh;
                val[12*i+1]=dv;
                val[12*i+3]=dh2;
                val[12*i+4]=dv2;
                val[12*i+6]=dh3;
                val[12*i+7]=dv3;
                val[12*i+9]=dh1;
                val[12*i+10]=dv1;
            }
            //mtg_log(mtg,MTG_LOG_BEGIN_SETMEASURE_BASKET);
            ///backsight
            if(tps_make_position(&mtg->tps,dh,dv)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_TARGET_BACKSIGHT);
                istep++;
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                fail=1;
            }
        }
        else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
        {
            iset=istep/20;
            itarget=(istep % 20)/5;
            if(rc==0)
            {
                if(istep % 5==0)
                {
                    if(iset==mtg->baskset)
                    {
                        ///
                        val1=(double*)malloc(3*mtg->baskset*sizeof(double));
                        h=v=dist=0.0;
                        mtg->d2a=mtg->d2c=mtg->d2d=0.0;
                        for(i=0;i<mtg->baskset;i++)
                        {
                            ///horizon
                            hi1=val[3*(i*4+1)]-val[3*(i*4)];
                            if(hi1<0) hi1+=2*PI;
                            hi2=val[3*(i*4+2)]-val[3*(i*4+3)];
                            if(hi2<0) hi2+=2*PI;
                            if(fabs(hi1-hi2)>mtg->d2c) mtg->d2c=fabs(hi1-hi2);
                            hi=(hi1+hi2)/2.0;
                            val1[3*i]=hi;
                            h+=hi;
                            ///vertical
                            vi1=val[3*(i*4+1)+1];
                            vi2=2*PI-val[3*(i*4+2)+1];
                            vi=(vi1+vi2)/2.0;
                            val1[3*i+1]=vi;
                            //if(fabs(vi1-vi2)>mtg->d2c) mtg->d2c=fabs(vi1-vi2);
                            v+=vi;
                            ///dist
                            di1=val[3*(i*4+1)+2];
                            di2=val[3*(i*4+2)+2];
                            di=(di1+di2)/2.0;
                            val1[3*i+2]=di;
                            dist+=di;

                            //trace(0,"iset=%d,hi=%f,vi=%f,di=%f\n",i,hi,vi,di);
                        }
                        h/=mtg->baskset;
                        v/=mtg->baskset;
                        dist/=mtg->baskset;
                        dx=mtg->istn.backx-mtg->istn.statx;
                        dy=mtg->istn.backy-mtg->istn.staty;
                        h+=atan2(dy,dx);
                        v=PI/2-v;

                        //trace(0,"h=%f,v=%f,dist=%f\n",h,v,dist);

                        mtg->baskcoord[0]=mtg->istn.statx+dist*cos(v)*cos(h);
                        mtg->baskcoord[1]=mtg->istn.staty+dist*cos(v)*sin(h);
                        mtg->baskcoord[2]=mtg->istn.statz+mtg->istn.stath+dist*sin(v)-mtg->baskh;
                        //if(mtg->iclient==2) client_prism(mtg,3,mtg->baskcoord[0],mtg->baskcoord[1],mtg->baskcoord[2]);
                        ///d2a,d2d
                        hi1=2*PI;
                        hi2=0;
                        di1=1.0e30;
                        di2=0;
                        for(i=0;i<mtg->baskset;i++)
                        {
                            if(val1[3*i]<hi1) hi1=val1[3*i];
                            if(val1[3*i]>hi2) hi2=val1[3*i];
                            if(val1[3*i+2]<di1) di1=val1[3*i+2];
                            if(val1[3*i+2]>di2) di2=val1[3*i+2];
                        }
                        mtg->d2a=hi2-hi1;
                        mtg->d2d=di2-di1;
                        //if(mtg->iclient==2) client_prism(mtg,4,mtg->d2a,mtg->d2c,mtg->d2d);
                        free(val1);
                        val1=0;
                        mtg_log(mtg,MTG_LOG_FINISH_SETMEASURE_BASKET);
                        break;
                    }
                    if(itarget==0)  ///
                    {
                        if(tps_make_position(&mtg->tps,dh,dv)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_BACKSIGHT);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                            fail=1;
                        }
                    }
                    if(itarget==1)  ///ǰ
                    {
                        if(tps_make_position(&mtg->tps,dh2,dv2)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_BASKET);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_BASKET);
                            fail=1;
                        }
                    }
                    else if(itarget==2)  ///ǰ
                    {
                        if(tps_make_position(&mtg->tps,dh3,dv3)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_BASKET);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_BASKET);
                            fail=1;
                        }
                    }
                    else if(itarget==3) ///Һ
                    {
                        if(tps_make_position(&mtg->tps,dh1,dv1)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_BACKSIGHT);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                            fail=1;
                        }
                    }
                }
                else if(istep % 5 ==1)  ///תɹʼ׼
                {
                    ///ȷ׼
                    if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                    {
                        if(itarget==1 || itarget==2) mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_BASKET);
                        else mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_BACKSIGHT);
                        istep++;
                    }
                    else
                    {
                        if(itarget==1 || itarget==2) mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BASKET);
                        else mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BACKSIGHT);
                        fail=1;
                    }
                }
                else if(istep%5==2)  ///׼ɹ
                {
                    if(itarget==1 || itarget==2) mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_BASKET);
                    else mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_BACKSIGHT);
                    ///ʼ
                    if(tps_do_measure(&mtg->tps)==0)
                    {
                        if(itarget==1 || itarget==2) mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_BASKET);
                        else mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_BACKSIGHT);
                        istep++;
                    }
                    else
                    {
                        if(itarget==1 || itarget==2) mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BASKET);
                        else mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                        fail=1;
                    }
                }
                else if(istep%5==3) ///ɹ
                {
                    ///ȡǶȾ
                    if(tps_get_measure(&mtg->tps)==0)
                    {
                        istep++;
                        if(itarget==1 || itarget==2) mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BASKET);
                        else mtg_log(mtg,MTG_LOG_FINISH_MEASURE_BACKSIGHT);
                    }
                    else
                    {
                        if(itarget==1 || itarget==2) mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BASKET);
                        else mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                        fail=1;
                    }
                }
                else if(istep % 5 ==4)
                {
                    ///긳ֵ
                    //trace(0,"iset=%d,itarget=%d,h=%f,v=%f,dist=%f\n",iset,itarget,mtg->tps.horizon,mtg->tps.vertical,mtg->tps.dist);
                    val[3*(4*iset+itarget)]=mtg->tps.horizon+mtg->istn.anglediff;
                    val[3*(4*iset+itarget)+1]=mtg->tps.vertical;
                    val[3*(4*iset+itarget)+2]=mtg->tps.dist;
                    if(tps_clear_measure(&mtg->tps)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        fail=1;
                    }
                }
            }
            else
            {
                ///ʧ
                if(istep%5==0 || istep%5==3 || istep%5==4)
                {
                    if(itarget ==1 || itarget==2) mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BASKET);
                    else mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                }
                if(istep%5==1)
                {
                    if(itarget ==1 || itarget==2) mtg_log(mtg,MTG_LOG_FAIL_TARGET_BASKET);
                    else mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                }
                else if(istep%5==2)
                {
                    if(itarget ==1 || itarget==2) mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BASKET);
                    else mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BACKSIGHT);
                }
                fail=1;
            }
        }
        sleepms(10);
    }

    free(val);
    mtg->thread=0;
    mtg->stat=0;

    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_connect_thread(void* arg)
#else
static void *_mtg_connect_thread(void *arg)///20150819修改
#endif
{
    mtg_t* mtg=0;
    int opts[5]={90000,1000,100,4096,100};
    char path[260];
    int opera=0,rc=0,grc=0;
    int stat=-1;
    unsigned int tick=0;
    int timeout0=5000;
    int inclen=0;
    int tickinc=0;
    int tickclient=0;
    int i=0,j=0;
    unsigned char incbuf[260];
    int tpstype;
    int timeout=1000;
    int istep=0;
    unsigned int tickwait=0;
    FILE* fp;
    char dir[1024]={0};
    char* pdir;
    unsigned char cmd[256];
    unsigned char output[10];
    int ret=0;

    mtg=(mtg_t*)arg;
    tpstype=mtg->tps.type;
    pdir=_getcwd(NULL,0);
    sprintf(dir,"%s\\mtg_thread_test.log",pdir);
    fp=fopen(dir,"w");
    if(fp)
    {
        fprintf(fp,"tpstype:%d\n",tpstype);
        fflush(fp);
    }

    mtg->stat=1;

    timeout0=mtg->tps.timeout;

    ///tps
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_BEGIN_CONNECT_TPS);
        if(mtg->tps.type==TPS_TRIMBLE_TCU)
        {
            sprintf(path,"COM5:115200");
            trace(0,"connect tps: path:%s\n",path);
            if(tps_connect(&mtg->tps,opts,STR_SERIAL,path))
            {
                for(i=0;i<2;i++)
                {
                    if(tps_set_atr(&mtg->tps,1)==-1)
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
                        mtg->ierr[6]=1;
                        tps_close(&mtg->tps);
                    }
                    else
                    {
                        while(tps_get_rc(&mtg->tps,0,&rc)) sleepms(0);
                        if(rc==0)
                        {
                            mtg->itps=1;
                            mtg->ierr[6]=0;
                            mtg_log(mtg,MTG_LOG_FINISH_CONNECT_TPS);
                            break;
                        }
                    }
                }

                if(!mtg->itps)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
                    tps_close(&mtg->tps);
                    mtg->ierr[6]=1;
                    if(mtg->fbi)
                    {
                        fprintf(mtg->fbi,"%%R1P,%d,%d,%s\n",29,0,path);
                        fflush(mtg->fbi);
                    }
                }
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
                tps_close(&mtg->tps);
                mtg->ierr[6]=1;
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d,%s\n",29,1,path);
                    fflush(mtg->fbi);
                }
            }
        }
        else
        {
            sprintf(path,"%s:%d",mtg->comset[3].ip,mtg->comset[3].port);
            trace(0,"connect tps: path:%s\n",path);
            if(tps_connect(&mtg->tps,opts,STR_TCPCLI,path))
            {
//                mtg->tps.timeout=5000;
                mtg->tps.timeout=50000;
                if(tpstype==TPS_TRIMBLE)
                {
                    sleepms(1000);
                    for(i=0;i<1;i++)
                    {
                        if(tps_set_atr(&mtg->tps,1)==-1)
                        {
                            //fprintf(fp,"%d\n",0);
                            fprintf(fp,"tps_set_atr:failed\n");
                            fflush(fp);
                            mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
                            tps_close(&mtg->tps);
                            //goto finish;
                        }
                        else
                        {
                            fprintf(fp,"tps_set_atr=0\n");
                            fflush(fp);
                            //fprintf(fp,"%d\n",1);
                            while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(0);
                            //tps_translation_rc(&grc);
                            //mtg_store_tpsop(mtg,opera,grc);
                            if(rc==0)
                            {
                                fprintf(fp,"tps_set_atr:success\n");
                                fflush(fp);
                                //fprintf(fp,"%d\n",2);
                                mtg->itps=1;
                                mtg_log(mtg,MTG_LOG_FINISH_CONNECT_TPS);
                                fprintf(fp,"tps_set_atr:success2\n");
                                fflush(fp);
                                break;
                            }
                        }
                        if(mtg->itps==1) break;
                        sleepms(5000);
                    }
                }
                else
                {
                    tpstype=TS_15;
                    for(i=0;i<2;i++)
                    {
                        if(tps_set_atr(&mtg->tps,1)==-1)
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
                            mtg->ierr[6]=1;
                            tps_close(&mtg->tps);
                        }
                        else
                        {
                            while(tps_get_rc(&mtg->tps,0,&rc)) sleepms(0);
                            if(rc==0)
                            {
                                mtg->itps=1;
                                mtg->ierr[6]=0;
                                mtg_log(mtg,MTG_LOG_FINISH_CONNECT_TPS);
                                /*if(tps_set_timeout(&mtg->tps,20,20)==-1)
                                {
                                    mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
                                }
                                else
                                {
                                    while(tps_get_rc(&mtg->tps,0,&rc)) sleepms(0);
                                    if(rc==0)
                                    {
                                        mtg_log(mtg,MTG_LOG_FINISH_CONNECT_TPS);
                                    }
                                    else
                                    {
                                        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
                                    }
                                }*/

                                break;
                            }
                        }
                    }
                }

                if(!mtg->itps)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
                    tps_close(&mtg->tps);
                    mtg->ierr[6]=1;
                    if(mtg->fbi)
                    {
                        fprintf(mtg->fbi,"%%R1P,%d,%d,%s\n",29,0,path);
                        fflush(mtg->fbi);
                    }
                }

            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
                tps_close(&mtg->tps);
                mtg->ierr[6]=1;
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d,%s\n",29,1,path);
                    fflush(mtg->fbi);
                }
            }
        }

    }
    ///cam
    if(!mtg->stat) goto finish;

    if(!mtg->icam)
    {
        mtg_log(mtg,MTG_LOG_BEGIN_CONNECT_CAMERA);
        sprintf(path,"%s:%d",mtg->comset[0].ip,mtg->comset[0].port);
        //trace(0,"connect target: path:%s\n",path);
        if(mtg->tarset.cam==1)
        {
            if(camsvr_dh_start(&mtg->camsvr,100))
            {
                mtg->icam=1;
                mtg->ierr[7]=0;
                mtg_log(mtg,MTG_LOG_FINISH_CONNECT_CAMERA);
                camsvr_stop(&mtg->camsvr);
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_CONNECT_CAMERA);
                camsvr_stop(&mtg->camsvr);
                mtg->ierr[7]=1;
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d,%s\n",30,mtg->tarset.cam,path);
                    fflush(mtg->fbi);
                }
            }
        }
        else if(mtg->tarset.cam==0)
        {
            if(camsvr_bm_start(&mtg->camsvr,10))
            {
                mtg->icam=1;
                mtg->ierr[7]=0;
                mtg_log(mtg,MTG_LOG_FINISH_CONNECT_CAMERA);
            }
            else
            {
                strsvrstop(&mtg->camsvr);
                mtg_log(mtg,MTG_LOG_FAIL_CONNECT_CAMERA);
                mtg->ierr[7]=1;
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d,%s\n",30,mtg->tarset.cam,path);
                    fflush(mtg->fbi);
                }
            }
        }
    }

    if(!mtg->stat) goto finish;


    //撑紧盾倾斜仪
    if(mtg->incA_flag==1 && !mtg->iincA)
    {
        mtg_log(mtg,MTG_LOG_BEGIN_CONNECT_INCA);
        sprintf(path,"%s:%d",mtg->comset[6].ip,mtg->comset[6].port);

        if(strncmp(path, "COM", 3)==0){
            ret=inc_connect(&mtg->incA,opts,STR_SERIAL,path);
        }
        else{
            ret=inc_connect(&mtg->incA,opts,STR_TCPCLI,path);
        }
        if(ret==1)
        {
            mtg->incA.command=INC_GET;
            inc_thread(&mtg->incA);
            while(inc_get_rc(&mtg->incA,0,&rc)) sleepms(10);
            if(rc==0){
                mtg_log(mtg,MTG_LOG_CONNECT_INCA_FINSH);
                mtg->iincA=1;
            }
            else{
                mtg_log(mtg,MTG_LOG_CONNECT_INCA_FAIL);
                inc_close(&mtg->incA);
            }
        }
        else{
            mtg_log(mtg,MTG_LOG_CONNECT_INCA_FAIL);
            inc_close(&mtg->incA);
        }
    }
    if(!mtg->stat) goto finish;

    //incline
    ///20171122whq增加，使倾斜仪的类型强制为小的瑞芬倾斜仪，量程10°
    //mtg->tarset.inc=2;
    //mtg->tarset.incdb=1;
    if(!mtg->iinc && !mtg->tarset.incdb)
    {
        mtg_log(mtg,MTG_LOG_BEGIN_CONNECT_INCLINE);
        sprintf(path,"%s:%d",mtg->comset[2].ip,mtg->comset[2].port);
        //sprintf(path,"COM3:9600");
        trace(0,"connect Inclinometer: path:%s\n",path);
        if(fp)
        {
            fprintf(fp,"%s\n",path);
            fflush(fp);
        }
        if(strsvrstart(&mtg->incsvr,opts,STR_TCPCLI,path))
        //if(strsvrstart(&mtg->incsvr,opts,STR_SERIAL,path))
        {
            if(fp)
            {
                fprintf(fp,"strsvrstart\n");
                fflush(fp);
            }

            ///20210121ws add 为了连接应答模式的726倾斜仪
//            if(mtg->tarset.inc==2)///瑞芬726s倾斜仪
//            {
//                send_char(cmd,1);
//                CRC16((unsigned char*)cmd,6,(char*)output);
//                cmd[6]=(unsigned char)(output[0]);
//                cmd[7]=(unsigned char)(output[1]);
//
//                if(fp)
//                {
//                    for(j=0;j<8;j++)
//                    {
//                        fprintf(fp,"%0x ",(unsigned char)(cmd[j]));
//                        fflush(fp);
//                    }
//                    fprintf(fp,"\n");
//                    fflush(fp);
//                }
//
//                strsvrput(&mtg->incsvr,(unsigned char*)cmd,8);
//            }

            tick=tickget();
            while(tickget()-tick<5000)
            {
                inclen+=strsvrpeek(&mtg->incsvr,(unsigned char*)(incbuf)+inclen,259-inclen);
                if(fp)
                {
                    fprintf(fp,"inclen:%d\n",inclen);
                    fflush(fp);
                }
                if(inclen>0)
                {
                    if(fp)
                    {
                        fprintf(fp,"incbuf:%s\n",incbuf);
                        fflush(fp);
                    }
                    for(j=0;j<inclen;j++)
                    {
                        if(fp)
                        {
                            fprintf(fp,"%0x ",(unsigned char)incbuf[j]);
                            fflush(fp);
                        }
                    }
                    if(fp)
                    {
                        fprintf(fp,"\n");
                        fflush(fp);
                    }
                    incbuf[inclen]=0;
                    ///瑞芬倾斜仪
                    if(mtg->tarset.inc==0)
                    {
                        for(j=0;j<inclen-1;j++)
                        {
                            if((unsigned char)incbuf[j]==0x68 && (unsigned char)incbuf[j+1]==0x0D)
                            {
                                tickinc++;
                                break;
                            }
                        }
                    }
                    else if(mtg->tarset.inc==1)///德国倾斜仪
                    {
                        if(strstr(incbuf,"X=") || strstr(incbuf,"Y="))
                        {
                            tickinc++;
                            break;
                        }
                    }
                    else if(mtg->tarset.inc==2)///瑞芬726s倾斜仪
                    {
                        for(j=0;j<inclen-1;j++)
                        {
                            if((unsigned char)incbuf[j]==0x01 && ((unsigned char)incbuf[j+1]==0x03 && (unsigned char)incbuf[j+2]==0x08))
                            {
                                tickinc++;
                                if(fp)
                                {
                                    fprintf(fp,"j:%d\n",j);
                                    fflush(fp);
                                }
                                break;
                            }
                        }
                    }
                }
                sleepms(100);
            }
            if(tickinc>0 )
            {
                mtg->iinc=1;
                mtg->ierr[8]=0;
                mtg_log(mtg,MTG_LOG_FINISH_CONNECT_INCLINE);
            }
            else
            {
                strsvrstop(&mtg->incsvr);
                mtg_log(mtg,MTG_LOG_FAIL_CONNECT_INCLINE);
                mtg->ierr[8]=1;
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d,%d,%s\n",31,0,mtg->tarset.inc,path);
                    fflush(mtg->fbi);
                }
            }
        }
        else
        {
            strsvrstop(&mtg->incsvr);
            mtg_log(mtg,MTG_LOG_FAIL_CONNECT_INCLINE);
            mtg->ierr[8]=1;
            if(mtg->fbi)
            {
                fprintf(mtg->fbi,"%%R1P,%d,%d,%d,%s\n",31,1,mtg->tarset.inc,path);
                fflush(mtg->fbi);
            }
        }
    }

    if(!mtg->iinc && mtg->tarset.incdb)
    {
        tickinc=0;
        mtg_log(mtg,MTG_LOG_BEGIN_CONNECT_INCLINE);
        sprintf(path,"%s:%d",mtg->comset[2].ip,mtg->comset[2].port);
        //sprintf(path,"COM12:9600");
        if(fp)
        {
            fprintf(fp,"%s\n",path);
            fprintf(fp,"inctype:%d\n",mtg->tarset.inc);
            fflush(fp);
        }
        //
        trace(0,"connect Inclinometer: path:%s\n",path);
        if(strsvrstart(&mtg->incsvr,opts,STR_TCPCLI,path))
        ///if(strsvrstart(&mtg->incsvr,opts,STR_SERIAL,path))
        {
            //send_char(incbuf,1);
            send_char(cmd,1);
//            cmd[0]=0x04;
//            cmd[1]=0x06;
//            cmd[2]=0x00;
//            cmd[3]=0x11;
//            cmd[4]=0x00;
//            cmd[5]=0x02;
//            cmd[6]=0xD8;
//            cmd[7]=0x0C;
            CRC16((unsigned char*)cmd,6,(char*)output);
            cmd[6]=(unsigned char)(output[0]);
            cmd[7]=(unsigned char)(output[1]);
            //strsvrput(&mtg->incsvr,incbuf,strlen(incbuf));
            if(fp)
            {
                for(j=0;j<8;j++)
                {
                    fprintf(fp,"%0x ",(unsigned char)(cmd[j]));
                    fflush(fp);
                }
                fprintf(fp,"\n");
                fflush(fp);
            }
            strsvrput(&mtg->incsvr,(unsigned char*)cmd,8);
            tick=tickget();
            inclen=0;
            while(tickget()-tick<5000)
            {
                inclen+=strsvrpeek(&mtg->incsvr,(unsigned char*)incbuf+inclen,259-inclen);
                if(inclen>0)
                {
                    incbuf[inclen]=0;
                    if(fp)
                    {
                        fprintf(fp,"inclen1:%d\n",inclen);
                        fflush(fp);
                    }
                    for(j=0;j<inclen;j++)
                    {
                        if(fp)
                        {
                            fprintf(fp,"%0x ",(unsigned char)(incbuf[j]));
                            fflush(fp);
                        }
                    }
                    if(fp)
                    {
                        fprintf(fp,"\n");
                        fflush(fp);
                    }
                    ///瑞芬倾斜仪
                    if(mtg->tarset.inc==2)///瑞芬726s倾斜仪
                    {
                        for(j=0;j<inclen-1;j++)
                        {
                            if((unsigned char)incbuf[j]==0x01 && ((unsigned char)incbuf[j+1]==0x03 && (unsigned char)incbuf[j+2]==0x08))
                            {
                                tickinc++;
                                if(fp)
                                {
                                    fprintf(fp,"tickinc1:%d\n",tickinc);
                                    fflush(fp);
                                }
                                break;
                            }
                        }
                        if(tickinc&0x01)
                        {
                            break;
                        }
                    }
                }
                sleepms(100);
            }

            //send_char(incbuf,2);
            //strsvrput(&mtg->incsvr,incbuf,strlen(incbuf));
            send_char(cmd,2);
//            cmd[0]=0x04;
//            cmd[1]=0x06;
//            cmd[2]=0x00;
//            cmd[3]=0x11;
//            cmd[4]=0x00;
//            cmd[5]=0x02;
//            //cmd[6]=0xD8;
//            //cmd[7]=0x0C;
            CRC16((unsigned char*)cmd,6,(char*)output);
            cmd[6]=(unsigned char)(output[0]);
            cmd[7]=(unsigned char)(output[1]);
            //strsvrput(&mtg->incsvr,incbuf,strlen(incbuf));
            if(fp)
            {
                for(j=0;j<8;j++)
                {
                    fprintf(fp,"%0x ",(unsigned char)(cmd[j]));
                    fflush(fp);
                }
                fprintf(fp,"\n");
                fflush(fp);
            }
            strsvrput(&mtg->incsvr,(unsigned char*)cmd,8);
            tick=tickget();
            inclen=0;
            while(tickget()-tick<2000)
            {
                inclen+=strsvrpeek(&mtg->incsvr,(unsigned char*)(incbuf)+inclen,259-inclen);
                if(inclen>0)
                {
                    incbuf[inclen]=0;

                    if(fp)
                    {
                        fprintf(fp,"inclen2:%d\n",inclen);
                        fflush(fp);
                    }
                    for(j=0;j<inclen;j++)
                    {
                        if(fp)
                        {
                            fprintf(fp,"%0x ",(unsigned char)(incbuf[j]));
                            fflush(fp);
                        }
                    }
                    if(fp)
                    {
                        fprintf(fp,"\n");
                        fflush(fp);
                    }
                    ///瑞芬倾斜仪
                    if(mtg->tarset.inc==2)///瑞芬726s倾斜仪
                    {
                        for(j=0;j<inclen-1;j++)
                        {
                            if((unsigned char)incbuf[j]==0x02 && ((unsigned char)incbuf[j+1]==0x03 && (unsigned char)incbuf[j+2]==0x08))
                            {
                                tickinc+=2;
                                if(fp)
                                {
                                    fprintf(fp,"tickinc2:%d\n",tickinc);
                                    fflush(fp);
                                }

                                break;
                            }
                        }
                        if(tickinc&0x02)
                        {
                            break;
                        }
                    }
                }
                sleepms(100);
            }

            if(tickinc>=3||(tickinc&0x02&&mtg->tarset.baseinc==1) )
            {
                //mtg->iinc=tickinc;
 /*               if(tickinc==1)
                {
                    //strsvrstop(&mtg->incsvr);
                    mtg->ierr[8]=1;
                    mtg_log(mtg,MTG_LOG_FAIL_CONNECT_INCLINE2);
                }
                else if(tickinc==2)
                {
                    //strsvrstop(&mtg->incsvr);
                    //mtg->iinc=0;
                    mtg->ierr[8]=1;
                    mtg_log(mtg,MTG_LOG_FAIL_CONNECT_INCLINE1);
                }
                else if(tickinc==3)*/
                {
                    mtg->iinc=1;
                    mtg->ierr[8]=0;
                    mtg_log(mtg,MTG_LOG_FINISH_CONNECT_INCLINE);
                }
            }
            else
            {
                strsvrstop(&mtg->incsvr);
                mtg_log(mtg,MTG_LOG_FAIL_CONNECT_INCLINE);
                mtg->ierr[8]=1;
                if(mtg->fbi)
                {
                    fprintf(mtg->fbi,"%%R1P,%d,%d,%d,%s\n",31,0,mtg->tarset.inc,path);
                    fflush(mtg->fbi);
                }
            }
        }
        else
        {
            strsvrstop(&mtg->incsvr);
            mtg_log(mtg,MTG_LOG_FAIL_CONNECT_INCLINE);
            mtg->ierr[8]=1;
            if(mtg->fbi)
            {
                fprintf(mtg->fbi,"%%R1P,%d,%d,%d,%s\n",31,1,mtg->tarset.inc,path);
                fflush(mtg->fbi);
            }
        }
    }

finish:
    mtg->tps.timeout=timeout0;
    mtg->tps.opera=TPS_CMD_NONE;
    mtg->thread=0;
    mtg->stat=0;
    camsvr_stop(&mtg->camsvr);
    if(mtg->fbi)
    {
        fclose(mtg->fbi);
        mtg->fbi=0;
    }
    ///20180110whq添加
    if(fp)
    {
        fclose(fp);
    }
    ///20180110whq添加结束
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_getcomp_thread(void* arg)
#else
static void *_mtg_getcomp_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int opera=0,rc=0,grc=0;

    mtg=(mtg_t*)arg;
    mtg->stat=1;

    if(tps_get_incline(&mtg->tps)==0)
    {
        while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(0);
        if(rc==0)
        {
            mtg->m.comp[0]=mtg->tps.incline[0];
            mtg->m.comp[1]=mtg->tps.incline[1];
        }
    }

finish:
    mtg->thread=0;
    mtg->stat=0;
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_getpower_thread(void* arg)
#else
static void *_mtg_getpower_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int opera=0,rc=0,grc=0;

    mtg=(mtg_t*)arg;
    mtg->stat=1;

    if(tps_get_power(&mtg->tps)==0)
    {
        while(tps_get_rc(&mtg->tps,&opera,&rc)) sleepms(0);
        if(rc==0)
        {
            //mtg_log(mtg,MTG_LOG_UPDATE_POWER);
        }
    }

finish:
    mtg->thread=0;
    mtg->stat=0;
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_prismcheck_thread(void* arg)
#else
static void *_mtg_prismcheck_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int istep=0;
    int opera=0,rc=0;
    int fail=0;
    double dx,dy,dz,dh,dv,dl;

    mtg=(mtg_t*)arg;

    mtg->stat=1;

    while(mtg->stat)
    {
        if(istep==0)
        {
            dx=mtg->prismcoord[0]-mtg->istn.statx;
            dy=mtg->prismcoord[1]-mtg->istn.staty;
            dz=mtg->prismcoord[2]-mtg->istn.statz-mtg->istn.stath;
            dh=atan2(dy,dx);
            //if(dh<0) dh+=2*PI;
            //if(dh>2*PI) dh-=2*PI;
            dh-=mtg->istn.anglediff;
            //if(dh<0) dh+=2*PI;
            //if(dh>2*PI) dh-=2*PI;

            dl=sqrt(dx*dx+dy*dy)+0.0000000001;
            dv=PI/2-atan(dz/dl);

            if(tps_make_position(&mtg->tps,dh,dv)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                istep++;
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                fail=1;
            }
        }
        else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
        {
            if(rc==0)
            {
                if(istep==1)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_TARGET_PRISM);
                    if(tps_fine_adjust(&mtg->tps,0.1,0.1)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                        fail=1;
                    }
                }
                else if(istep==2)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_PRISM);
                    if(tps_do_measure(&mtg->tps)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_PRISM);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                        fail=1;
                    }
                }
                else if(istep==3)
                {
                    //20180119whq将下面的tps_get_coordfinate改成tps_get_measure
                    //if(tps_get_coordinate(&mtg->tps)==0)
                    if(tps_get_measure(&mtg->tps)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                        fail=1;
                    }
                }
                else if(istep==4)
                {
                    //mtg->prismcoord[0]=mtg->tps.coord[0];
                    //mtg->prismcoord[1]=mtg->tps.coord[1];
                    //mtg->prismcoord[2]=mtg->tps.coord[2];
                    dh=mtg->tps.horizon;
                    dv=mtg->tps.vertical;

                    //if(mtg->tps.type==TPS_TRIMBLE)
                        //mtg->tps.dist+=mtg->tps.prism;

                    dl=mtg->tps.dist+mtg->tarset.prc/1000.0;

                    dh+=mtg->istn.anglediff;

                    mtg->prismcoord[0]=mtg->istn.statx+dl*cos(PI/2-dv)*cos(dh);
                    mtg->prismcoord[1]=mtg->istn.staty+dl*cos(PI/2-dv)*sin(dh);
                    mtg->prismcoord[2]=mtg->istn.statz+mtg->istn.stath+dl*sin(PI/2-dv);

                    if(tps_clear_measure(&mtg->tps)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        fail=1;
                    }
                }
                else if(istep==5)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_MEASURE_PRISM);
                    break;
                }
            }
            else
            {
                if(istep==1)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                }
                else if(istep==2)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                }
                else if(istep==3 || istep==4 || istep==5)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                }
                fail=1;
            }
        }
        if(fail)
        {
            break;
        }
        sleepms(10);
    }

    mtg->thread=0;
    mtg->stat=0;

    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_prism_thread(void* arg)
#else
static void *_mtg_prism_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    int istep=0;
    double cam[3];
    time_t now;
    int opera=0,rc=0;
    int tickcam1=0,tickcam2=0,ticktps=0;
    unsigned int tickwait=0;
    int fail=0;
    double dx,dy,dz,dh,dv,dl;
    double laserheight=0.0;
    double laserx=0.0,lasery=0.0;
    int timeout=30000;

    mtg=(mtg_t*)arg;

    laserheight=mtg->tps.laserheight/1000.0;
    if(mtg->tps.lasertype==0)
    {
        if(mtg->tps.laserdist[0]>1.0e-6)
        {
            laserx=atan(mtg->tps.laserx[0]/1000.0/mtg->tps.laserdist[0]);
            lasery=atan(mtg->tps.lasery[0]/1000.0/mtg->tps.laserdist[0]);
        }
        else if(mtg->tps.laserdist[1]>1.0e-6)
        {
            laserx=atan(mtg->tps.laserx[1]/1000.0/mtg->tps.laserdist[1]);
            lasery=atan(mtg->tps.lasery[1]/1000.0/mtg->tps.laserdist[1]);
        }
    }

    mtg->opera=MTG_OPERA_TPS;

    mtg->stat=1;

    while(mtg->stat)
    {
        ///相机
        if(mtg->opera & MTG_OPERA_CAM)
        {
            if(camsvr_peek(&mtg->camsvr,0,0,cam,&now))
            {
                mtg->m.cam[0]=cam[0];
                mtg->m.cam[1]=cam[1];
                mtg->m.cam[2]=cam[2];
                mtg->m.inc[0] = mtg->m1.inc[0];
                mtg->m.inc[1] = mtg->m1.inc[1];
                mtg->m.inc[5] = mtg->m1.inc[5];
                mtg->m.inc[6] = mtg->m1.inc[6];
                mtg->m.t1=now;
                time(&now);
                mtg->m.t2=now;
                mtg_laser_incline(mtg);
                tickcam1++;
            }
        }

        if(istep==0)
        {
            if(mtg->tarset.cam==1)
            {
                if(camsvr_dh_start(&mtg->camsvr,10))
                {
                    mtg_log(mtg,MTG_LOG_CAMERA_READY);
                }
            }

            dx=mtg->mp.prism[9]-mtg->istn.statx;
            dy=mtg->mp.prism[10]-mtg->istn.staty;
            dz=mtg->mp.prism[11]-mtg->istn.statz-mtg->istn.stath;
            trace(0,"mp.prism[9]=%.4f,prism[10]=%.4f,prism[11]=%.4f\n",mtg->mp.prism[9],mtg->mp.prism[10],mtg->mp.prism[11]);
            dh=atan2(dy,dx);
            //if(dh<0) dh+=2*PI;
            //if(dh>2*PI) dh-=2*PI;

            dh-=mtg->istn.anglediff;
            //if(dh<0) dh+=2*PI;
            //if(dh>2*PI) dh-=2*PI;

            dl=sqrt(dx*dx+dy*dy)+0.0000000001;
            dv=PI/2-atan(dz/dl);

            if(tps_make_position(&mtg->tps,dh,dv)==0)
            {
                mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                istep++;
            }
            else
            {
                mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                fail=1;
            }
        }
        else if(istep==15)  ///ȴڽ
        {
            if(tickcam1 >0)
            {
                mtg->opera ^= MTG_OPERA_CAM;
                ///ܹ̬
                mtg_laser_gesture(mtg);
                if(mtg_store_meas(mtg))
                {
                    mtg_log(mtg,MTG_LOG_FINISH_STORE_MEASURE);
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FAIL_STORE_MEASURE);
                }

                ///
                if(mtg->tps.lasertype==0)  ///GUS74激光头
                {
                    if(tps_stop_laser(&mtg->tps)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                        fail=1;
                    }
                }
                else if(mtg->tps.lasertype==1)   ///无棱镜测距激光
                {
                    if(tps_stop_laserpoint(&mtg->tps)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                        fail=1;
                    }
                }
                else
                {
                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                    istep=16;
                }
            }
            else
            {
                if(tickget()-tickwait>timeout)
                {
                    fail=1;
                    if(mtg->tps.lasertype==0)  ///GUS74激光头
                    {
                        if(tps_stop_laser(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                            tickwait=tickget();
                            rc=-1;
                            while(tps_get_rc(&mtg->tps,&opera,&rc) && tickget()-tickwait<timeout) sleepms(10);
                            if(rc==0)
                            {
                                mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                        }
                    }
                    else if(mtg->tps.lasertype==1)   ///无棱镜测距激光
                    {
                        if(tps_stop_laserpoint(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
                            tickwait=tickget();
                            rc=-1;
                            while(tps_get_rc(&mtg->tps,&opera,&rc) && tickget()-tickwait<timeout) sleepms(10);
                            if(rc==0)
                            {
                                mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                            }
                            else
                            {
                                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                            }
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                        }
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                    }
                }
            }
        }
        else if(tps_get_rc(&mtg->tps,&opera,&rc)==0)
        {
            if(rc==0)
            {
                if(istep==1)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_TARGET_PRISM);
                    if(tps_fine_adjust(&mtg->tps,0.1,0.1)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                        fail=1;
                    }
                }
                else if(istep==2)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_PRISM);
                    if(tps_do_measure(&mtg->tps)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_PRISM);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                        fail=1;
                    }
                }
                else if(istep==3)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_PRISM);
                    if(tps_get_measure(&mtg->tps)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_PRISM);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                        fail=1;
                    }
                }
                else if(istep==4)
                {
                    if(mtg->tps.vertical>PI)
                    {
                        dh=mtg->tps.horizon-PI;
                        if(dh<0.0) dh+=2.0*PI;
                        dv=2.0*PI-mtg->tps.vertical;
                        if(tps_make_position(&mtg->tps,dh,dv)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                            fail=1;
                        }
                    }
                    else
                    {
                        dh=mtg->tps.horizon;
                        dv=mtg->tps.vertical;

                        dh+=mtg->istn.anglediff;

                        //if(mtg->tps.type==TPS_TRIMBLE)
                            //mtg->tps.dist+=mtg->tps.prism;

                        dl=mtg->tps.dist+mtg->tarset.prc/1000.0;
                        //trace(0,"_mtg_prism_thread:s=%f\n",dl);
                        mtg->mp.prism[9]=mtg->istn.statx+dl*cos(PI/2-dv)*cos(dh);
                        mtg->mp.prism[10]=mtg->istn.staty+dl*cos(PI/2-dv)*sin(dh);
                        mtg->mp.prism[11]=mtg->istn.statz+mtg->istn.stath+dl*sin(PI/2-dv);
                        //trace(0,"_mtg_prism_thread:x=%f,y=%f,z=%f\n",mtg->mp.prism[9],mtg->mp.prism[10],mtg->mp.prism[11]);
                        if(tps_clear_measure(&mtg->tps)==0)
                        {
                            istep=6;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                            fail=1;
                        }
                    }
                }
                else if(istep==5)
                {
                    if(tps_fine_adjust(&mtg->tps,0.07,0.07)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                        istep=1;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                        fail=1;
                    }
                }
                else if(istep==6)
                {
                    dx=mtg->m1.prism[0]-mtg->istn.statx;
                    dy=mtg->m1.prism[1]-mtg->istn.staty;
                    dz=mtg->m1.prism[2]-mtg->istn.statz-mtg->istn.stath;
                    dh=atan2(dy,dx);
                    //if(dh<0) dh+=2*PI;
                    //if(dh>2*PI) dh-=2*PI;
                    dh-=mtg->istn.anglediff;
                    //if(dh<0) dh+=2*PI;
                    //if(dh>2*PI) dh-=2*PI;

                    dl=sqrt(dx*dx+dy*dy)+0.0000000001;
                    dv=PI/2-atan(dz/dl);

                    if(tps_make_position(&mtg->tps,dh,dv)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_TARGET_PRISM);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                        fail=1;
                    }
                }
                else if(istep==7)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_TARGET_PRISM);
                    if(tps_fine_adjust(&mtg->tps,0.1,0.1)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_FINEADJUST_PRISM);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                        fail=1;
                    }
                }
                else if(istep==8)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_FINEADJUST_PRISM);
                    if(tps_do_measure(&mtg->tps)==0)
                    {
                        mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_PRISM);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                        fail=1;
                    }
                }
                else if(istep==9) ///ǰӲɹ
                {
                    if(tps_get_measure(&mtg->tps)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                        fail=1;
                    }
                }
                else if(istep==10)
                {
                    dh=mtg->tps.horizon;
                    dv=mtg->tps.vertical;
                    //if(mtg->tps.type==TPS_TRIMBLE)
                        //mtg->tps.dist+=mtg->tps.prism;

                    dl=mtg->tps.dist+mtg->tarset.prc/1000.0;

                    dh+=mtg->istn.anglediff;

                    mtg->m.prism[0]=mtg->istn.statx+dl*cos(PI/2-dv)*cos(dh);
                    mtg->m.prism[1]=mtg->istn.staty+dl*cos(PI/2-dv)*sin(dh);
                    mtg->m.prism[2]=mtg->istn.statz+mtg->istn.stath+dl*sin(PI/2-dv);
                    time(&mtg->m.t3);
                    time(&mtg->mp.t);
                    mtg->mp.inc[3]=mtg->m1.inc[0];
                    mtg->mp.inc[4]=mtg->m1.inc[1];
                    //trace(0,"4:mp.prism[9]=%.4f,prism[10]=%.4f,prism[11]=%.4f\n",mtg->mp.prism[9],mtg->mp.prism[10],mtg->mp.prism[11]);

                    mtg_prism_gesture(mtg);
                    if(tps_clear_measure(&mtg->tps)==0)
                    {
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                        fail=1;
                    }
                }
                else if(istep==11)
                {
                    ///修正滚动角，俯仰角对激光耙中心照准的影响
                    point3d_t pt1,pt2;
                    transform3d_t trans;
                    double roll,pitch,ori;
                    if(mtg->tarset.baseinc==1)
                    {
                        roll=mtg->m1.inc[5]*PI/180.0;
                        pitch=mtg->m1.inc[6]*PI/180.0;
                    }
                    else
                    {
                        roll=mtg->m1.inc[0]*PI/180.0;
                        pitch=mtg->m1.inc[1]*PI/180.0;
                    }
                    roll=atan(tan(roll)/(cos(pitch)+0.0000000001));
                    //ori=atan2(mtg->m.prism[1]-mtg->istn.staty,mtg->m.prism[0]-mtg->istn.statx);
                    //trace(0,"prism:%f,%f,%f\n",mtg->m.prism[0],mtg->m.prism[1],mtg->m.prism[2]);
                    //trace(0,"station:%f,%f,%f\n",mtg->istn.statx,mtg->istn.staty,mtg->istn.statz);
                    ///激光靶方位角取设计中线的切线方位
                    road_xy2l(&mtg->r,mtg->m.prism[0],mtg->m.prism[1],0,0,0,&ori,0);
                    //trace(0,"ori:%f\n",ori);
                    if(mtg->prj.a2z==-1)
                    {
                        ori = ori+PI;
                        if(ori>2*PI) ori=ori-2*PI;
                    }
                    //20180115whq增加
                    if(mtg->tarset.ipos<0||mtg->tarset.ipos>2)
                    {
                        //20180115whq增加
                        mtg_log(mtg,MTG_LOG_NO_PRISM_POSITION);
                        fail=1;
                    }
                    else
                    {
                        pt1.x=-mtg->tarset.prism[mtg->tarset.ipos*3]/1000.0;
                        pt1.y=-mtg->tarset.prism[mtg->tarset.ipos*3+1]/1000.0;
                        pt1.z=-mtg->tarset.prism[mtg->tarset.ipos*3+2]/1000.0;

                        transform3d_init(&trans,roll,pitch,-ori,0.0,0.0,0.0,1.0);
                        transform3d_trans(&trans,&pt1,&pt2);
                        ///斜距,平距
                        dx=mtg->m.prism[0]+pt2.x-mtg->istn.statx;
                        dy=mtg->m.prism[1]+pt2.y-mtg->istn.staty;
                        dz=mtg->m.prism[2]+pt2.z-mtg->istn.statz-mtg->istn.stath;
                        dl=sqrt(dx*dx+dy*dy);
                        dz-=laserheight*(dl*dl+dz*dz)/(sqrt(dl*dl+dz*dz-laserheight*laserheight)*dl+laserheight*dz+0.0000000001);
                        ///转向激光耙
                        dh=atan2(dy,dx)-laserx;
                        dh-=mtg->istn.anglediff;

                        //if(dh<0) dh+=2*PI;
                        //if(dh>2*PI) dh-=2*PI;
                        dv=PI/2-atan(dz/dl)+lasery;
                        trace(0,"dh=%.12f,dv=%.12f\n",dh,dv);
                        mtg_log(mtg,MTG_LOG_FINISH_MEASURE_PRISM);
                        if(tps_make_position(&mtg->tps,dh,dv)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_TARGET_LASERUNIT);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_TARGET_LASERUNIT);
                            fail=1;
                        }
                    }
                }
                else if(istep==12) ///
                {
                    mtg_log(mtg,MTG_LOG_FINISH_TARGET_LASERUNIT);
                    if(tps_get_incline(&mtg->tps)==0)
                    {
                        //mtg_log(mtg,MTG_LOG_BEGIN_MEASURE_ANGLE);
                        istep++;
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FAIL_MEASURE_ANGLE);
                        fail=1;
                    }
                }
                else if(istep==13)
                {
                    ///comp
                    //mtg_log(mtg,MTG_LOG_FINISH_MEASURE_ANGLE);
                    //20180115whq修改，在后面增加mtg->istn.anglediff
                    //mtg->m.angle[0]=mtg->tps.horizon+laserx+mtg->istn.anglediff;
                    //mtg->m.angle[1]=mtg->tps.vertical+lasery;

                    mtg->m.angle[0]=dh+mtg->istn.anglediff;
                    if(mtg->m.angle[0]<0) mtg->m.angle[0]+=2*PI;
                    if(mtg->m.angle[0]>0) mtg->m.angle[0]-=2*PI;
                    mtg->m.angle[1]=dv;
                    mtg->m.comp[0]=mtg->tps.incline[0];
                    mtg->m.comp[1]=mtg->tps.incline[1];

                    if(mtg->tps.lasertype==0)
                    {
                        if(tps_start_laser(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_START_LASER);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
                            fail=1;
                        }

                    }
                    else if(mtg->tps.lasertype==1)
                    {
                        if(tps_start_laserpoint(&mtg->tps)==0)
                        {
                            mtg_log(mtg,MTG_LOG_BEGIN_START_LASER);
                            istep++;
                        }
                        else
                        {
                            mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
                            fail=1;
                        }
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_FINISH_START_LASER);
                        camsvr_start_capture(&mtg->camsvr);
                        mtg->opera |= MTG_OPERA_CAM;
                        //tickinc1=tickinc2=0;
                        tickcam1=tickcam2=0;
                        tickwait=tickget();
                        istep=14;
                    }

                }
                else if(istep==14)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_START_LASER);
                    if(camsvr_start_capture(&mtg->camsvr)==0)
                    {
                        mtg->opera |= MTG_OPERA_CAM;
                        istep++;
                        tickcam1=tickcam2=0;
                        tickwait=tickget();
                    }
                    else
                    {
                        mtg_log(mtg,MTG_LOG_CAMERA_FAIL);
                        fail=1;
                    }
                }
                else if(istep==16)
                {
                    mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
                    istep++;
                }
            }
            else
            {
                if(istep==1)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_TARGET_BACKSIGHT);
                }
                else if(istep==2)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_BACKSIGHT);
                }
                else if(istep==3 || istep==4 || istep==5)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_MEASURE_BACKSIGHT);
                }
                else if(istep==6)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_TARGET_PRISM);
                }
                else if(istep==7)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_FINEADJUST_PRISM);
                }
                else if(istep==8 || istep==9 || istep==10)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_MEASURE_PRISM);
                }
                else if(istep==11)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_TARGET_LASERUNIT);
                }
                else if(istep==12)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_MEASURE_ANGLE);
                }
                else if(istep==13)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
                }
                else if(istep==15)
                {
                    mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
                }
                fail=1;
            }
        }

        if(fail)
        {
            mtg_log(mtg,MTG_LOG_FAIL_GESTURE_CHECK);
            break;
        }
        else if(istep==17)
        {
            mtg_log(mtg,MTG_LOG_FINISH_GESTURE_CHECK);
            //trace(0,"cam:%f,%f,%f,%f\n",mtg->m.cam[0],mtg->m.cam[1],mtg->m.cam[2],mtg->m.cam[3]);
            //trace(0,"inc:%f,%f\n",mtg->m.inc[0],mtg->m.inc[1]);
            //trace(0,"angle:%f,%f\n",mtg->m.angle[0],mtg->m.angle[1]);
            break;
        }

        sleepms(10);
    }

    camsvr_stop(&mtg->camsvr);
    mtg->thread=0;
    mtg->stat=0;
    return 0;
}

int mtg_prism_check(mtg_t* mtg)
{
    if(mtg->thread)
    {
        return -1;
    }
    if(!mtg->itps)
    {
        return -1;
    }
    mtg->ithread=MTG_THREAD_MP;
#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_prism_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_prism_thread,mtg))
#endif
    {
        return -1;
    }
	return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_openlaser_thread(void* arg)
#else
static void *_mtg_openlaser_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    //int timeout0=0;
    int opera=0,rc=0,grc=0;

    mtg=(mtg_t*)arg;
    mtg->stat=1;

    //timeout0=mtg->tps.timeout;
    //mtg->tps.timeout=1000;
    if(mtg->tps.type==TPS_TRIMBLE||mtg->tps.lasertype==0)
    {
        if(tps_start_laser(&mtg->tps)==0)
        {
            mtg_log(mtg,MTG_LOG_BEGIN_START_LASER);
            while(tps_get_rc(&mtg->tps,&opera,&rc,&grc)) sleepms(0);
            //tps_translation_rc(&grc);
            //mtg_store_tpsop(mtg,opera,grc);
            if(rc==0)
            {
                mtg_log(mtg,MTG_LOG_FINISH_START_LASER);
            }
            else
                mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
        }
        else
            mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
    }
    else
    {
        if(tps_start_laserpoint(&mtg->tps)==0)
        {
            mtg_log(mtg,MTG_LOG_BEGIN_START_LASER);
            while(tps_get_rc(&mtg->tps,&opera,&rc,&grc)) sleepms(0);
            //tps_translation_rc(&grc);
            //mtg_store_tpsop(mtg,opera,grc);
            if(rc==0)
            {
                mtg_log(mtg,MTG_LOG_FINISH_START_LASER);
            }
            else
                mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
        }
        else
            mtg_log(mtg,MTG_LOG_FAIL_START_LASER);
    }

finish:
    //mtg->tps.timeout=timeout0;
    mtg->thread=0;
    mtg->stat=0;
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_closelaser_thread(void* arg)
#else
static void *_mtg_closelaser_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    //int timeout0=0;
    int opera=0,rc=0,grc=0;

    mtg=(mtg_t*)arg;
    mtg->stat=1;

    //timeout0=mtg->tps.timeout;
    //mtg->tps.timeout=1000;
    if(mtg->tps.type==TPS_TRIMBLE||mtg->tps.lasertype==0)
    {
        if(tps_stop_laser(&mtg->tps)==0)
        {
            mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
            while(tps_get_rc(&mtg->tps,&opera,&rc,&grc)) sleepms(50);
            //tps_translation_rc(&grc);
            //mtg_store_tpsop(mtg,opera,grc);
            if(rc==0)
            {
                mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
            }
            else
                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
        }
        else
            mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
    }
    else
    {
        if(tps_stop_laserpoint(&mtg->tps)==0)
        {
            mtg_log(mtg,MTG_LOG_BEGIN_STOP_LASER);
            while(tps_get_rc(&mtg->tps,&opera,&rc,&grc)) sleepms(50);
            //tps_translation_rc(&grc);
            //mtg_store_tpsop(mtg,opera,grc);
            if(rc==0)
            {
                mtg_log(mtg,MTG_LOG_FINISH_STOP_LASER);
            }
            else
                mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
        }
        else
            mtg_log(mtg,MTG_LOG_FAIL_STOP_LASER);
    }

finish:
    //mtg->tps.timeout=timeout0;
    mtg->thread=0;
    mtg->stat=0;
    return 0;
}


#ifdef WIN32
static DWORD WINAPI _mtg_gettem_thread(void* arg)
#else
static void *_mtg_gettem_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    //int timeout0=0;
    int opera=0,rc=0,grc=0;

    mtg=(mtg_t*)arg;
    mtg->stat=1;

    if(tps_get_tempreture(&mtg->tps)==0)
    {
        //mtg_log(mtg,MTG_LOG_BEGIN_GET_TEMPERATURE);
        while(tps_get_rc(&mtg->tps,&opera,&rc,&grc)) sleepms(0);
        //tps_translation_rc(&grc);
        //mtg_store_tpsop(mtg,opera,grc);
        if(rc==0)
        {
            mtg->tempget=mtg->tps.tempreture;
            //mtg_log(mtg,MTG_LOG_FINISH_GET_TEMPERATURE);
        }
        else
            mtg_log(mtg,MTG_LOG_FAIL_GET_TEMPERATURE);
    }
    else
        mtg_log(mtg,MTG_LOG_FAIL_GET_TEMPERATURE);

finish:
    //mtg->tps.timeout=timeout0;
    mtg->thread=0;
    mtg->stat=0;
    return 0;
}

#ifdef WIN32
static DWORD WINAPI _mtg_settem_thread(void* arg)
#else
static void *_mtg_settem_thread(void *arg)
#endif
{
    mtg_t* mtg=0;
    //int timeout0=0;
    int opera=0,rc=0,grc=0;

    mtg=(mtg_t*)arg;
    mtg->stat=1;

    if(tps_set_tempreture(&mtg->tps,mtg->tempset)==0)
    {
        mtg_log(mtg,MTG_LOG_BEGIN_SET_TEMPERATURE);
        while(tps_get_rc(&mtg->tps,&opera,&rc,&grc)) sleepms(0);
        //tps_translation_rc(&grc);
        //mtg_store_tpsop(mtg,opera,grc);
        if(rc==0)
        {
            mtg_log(mtg,MTG_LOG_FINISH_SET_TEMPERATURE);
        }
        else
            mtg_log(mtg,MTG_LOG_FAIL_SET_TEMPERATURE);
    }
    else
        mtg_log(mtg,MTG_LOG_FAIL_SET_TEMPERATURE);

finish:
    //mtg->tps.timeout=timeout0;
    mtg->thread=0;
    mtg->stat=0;
    return 0;
}


int mtg_get_comp(mtg_t* mtg)
{
    if(mtg->thread)
    {
        return -1;
    }
    if(!mtg->itps)
    {
        return -1;
    }
    mtg->ithread=MTG_THREAD_GETCOMP;
#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_getcomp_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_getcomp_thread,mtg))
#endif
    {
        return -1;
    }
	return 0;
}

int mtg_get_power(mtg_t* mtg)
{
    if(mtg->thread)
    {
        return -1;
    }
    if(!mtg->itps)
    {
        return -1;
    }
    mtg->ithread=MTG_THREAD_GETPOWER;

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_getpower_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_getpower_thread,mtg))
#endif
    {
        return -1;
    }
	return 0;
}

///倾斜仪线程
int mtg_inc_start(mtg_t* mtg)
{
    if(!mtg->incthread)
    {
    #ifdef WIN32
        if(!(mtg->incthread=CreateThread(NULL,0,_incthread,mtg,0,NULL)))
    #else
        if(pthread_create(&mtg->incthread,NULL,_incthread,mtg))
    #endif
        {
            return -1;
        }
        mtg->opera=MTG_OPERA_INC;
    }
    return 0;
}

///结束倾斜仪线程
void mtg_inc_close(mtg_t* mtg)
{
    if(!mtg->iinc && !mtg->iincA) return;
    mtg->iinc=0;
    mtg->iincA=0;
    while(mtg->incthread)
    {
        sleepms(10);
    }
    while(mtg->incthreadA)
    {
        sleepms(10);
    }
}

///硬件连接
int mtg_connect(mtg_t* mtg)///20150819修改
{
    ///加密
    /*IO_PACKAGE input={0},output={0};
    time_t now;
    char mac[4][13];
    int nMac=0;
    int bsense=0;
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
        for(i=0;i<nMac;i++)
        {
            if(strncmp(mac[i],output.buff,12)==0)
            {
                bsense=1;
                break;
            }
        }
    }
    if(!bsense)
    {
        mtg_log(mtg,MTG_LOG_ERROR_SENSE);
        trace(0,"License: sensor error\n");
        return -1;
    }
    */
    if(lock_sense(1,174)==0)
    {
        mtg_log(mtg,MTG_LOG_ERROR_SENSE);
        trace(0,"License: sensor error\n");
        return -1;
    }

    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }

    if(mtg->itps && mtg->icam && mtg->iinc)
    {
        if(mtg->incA_flag==1)
        {
            if(mtg->iincA)
            {
                mtg_log(mtg,MTG_LOG_ALL_READY);
                return -1;
            }
        }
        else{
            mtg_log(mtg,MTG_LOG_ALL_READY);
            return -1;
        }

    }
    ///加密
    mtg->ithread=MTG_THREAD_CONNECT;

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_connect_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_connect_thread,mtg))
#endif
    {
        return -1;
    }

    return 0;
}

///ʼ߳
int mtg_start_cycle(mtg_t* mtg)///20150819修改
{
    ///加密
    if(lock_sense(1,174)==0)
    {
        mtg_log(mtg,MTG_LOG_ERROR_SENSE);
        trace(0,"License: sensor error\n");
        return -1;
    }

    ///加密
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(!mtg->icam)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_CAMERA);
        return -1;
    }
    if(!mtg->iinc)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_INCLINE);
        return -1;
    }
    if(mtg->thread)
    {
        if(mtg->ithread!=MTG_THREAD_CYCLE)
        {
            mtg_log(mtg,MTG_LOG_IS_RUNNING);
            return -1;
        }
        else if(mtg->incycle==1)
        {
            mtg_log(mtg,MTG_LOG_IS_RUNNING);
            return -1;
        }
        else
        {
            mtg->pause=0;
            mtg->restart=1;
            return 0;
        }
    }

    if(mtg->m1.t3<=0)
    {
        mtg_log(mtg,MTG_LOG_ERROR_STUDY);
        return -1;
    }
    mtg->ithread=MTG_THREAD_CYCLE;

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtgthread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtgthread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_start_origin(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(!mtg->icam)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_CAMERA);
        return -1;
    }
    if(!mtg->iinc)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_INCLINE);
        return -1;
    }
    if(mtg->thread)
    {
        trace(0,"thread=%x\n",mtg->thread);
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_ORIGIN;

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtgthread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtgthread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_start_origin_segmeas(mtg_t* mtg)///20150819修改
{
    if(lock_sense(1,174)==0)
    {
        mtg_log(mtg,MTG_LOG_ERROR_SENSE);
        trace(0,"License: sensor error\n");
        return -1;
    }

    ///加密
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(!mtg->icam)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_CAMERA);
        return -1;
    }
    if(!mtg->iinc)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_INCLINE);
        return -1;
    }
    if(mtg->thread)
    {
        if(mtg->ithread!=MTG_THREAD_CYCLE)
        {
            mtg_log(mtg,MTG_LOG_IS_RUNNING);
            return -1;
        }
        else if(mtg->incycle==1)
        {
            mtg_log(mtg,MTG_LOG_IS_RUNNING);
            return -1;
        }
        else
        {
            mtg->pause=0;
            mtg->restart=1;
            return 0;
        }
    }

    if(mtg->m1.t3<=0)
    {
        mtg_log(mtg,MTG_LOG_ERROR_STUDY);
        return -1;
    }
    mtg->ithread=MTG_THREAD_CYCLE;

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtgthread_origin_segmeas,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtgthread_origin_segmeas,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_check_back(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_BACKCHECK;

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_check_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_check_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_check_prism(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_PRISMCHECK;

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_prismcheck_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_prismcheck_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_position_prism(mtg_t* mtg,double prism[3])
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_POSITION_PRISM;

    mtg->prismcoord[0]=prism[0];
    mtg->prismcoord[1]=prism[1];
    mtg->prismcoord[2]=prism[2];
#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_position_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_position_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_position_back(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_POSITION_BACK;

    mtg->prismcoord[0]=mtg->istn.backx;
    mtg->prismcoord[1]=mtg->istn.backy;
    mtg->prismcoord[2]=mtg->istn.backz;
#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_position_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_position_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_measure_back(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_MEASUREBACK;
    //if(mtg->iclient==2) client_threadtype(mtg,MTG_THREAD_MEASUREBACK);

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_measure_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_measure_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_measure_prism(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_MEASUREPRISM;
    //if(mtg->iclient==2) client_threadtype(mtg,MTG_THREAD_MEASUREPRISM);

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_measure_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_measure_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_setup(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_SETUP;

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_setup_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_setup_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_resetup(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_RE_SETUP;

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_resetup_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_resetup_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_measure_basket(mtg_t* mtg,double dist,double h,int set)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_BASKET;

    mtg->baskdist=dist;
    mtg->baskh=h;
    mtg->baskset=set;
#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_basket_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_basket_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

///ֹ߳
void mtg_stop(mtg_t* mtg)
{
    if(!mtg->thread || !mtg->stat)
    {
        mtg_log(mtg,MTG_LOG_NOT_RUNNING);///20150819修改,原因是会出错
        return;
    }
    mtg->stat = 0;
    mtg->run = 0;
    while(mtg->thread) sleepms(10);
}

///ͣ
int mtg_pause_cycle(mtg_t* mtg)
{
    if(!mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_NOT_RUNNING);
        return -1;
    }
    ///ڽڲѾͣʧ
    if(mtg->incycle || mtg->pause)
    {
        mtg_log(mtg,MTG_LOG_NOT_RUNNING);
        return -1;
    }
    mtg->pause=1;
    return 0;
}

///ָ
int mtg_restore_cycle(mtg_t* mtg)
{
    if(!mtg->pause) return -1;
    mtg->pause=0;
    return 0;
}

int mtg_get_temperature(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_GET_TEMPERATURE;
    //if(mtg->iclient==2) client_threadType(mtg,MTG_THREAD_MEASUREBACK);

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_gettem_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_gettem_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_set_temperature(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_SET_TEMPERATURE;
    //if(mtg->iclient==2) client_threadType(mtg,MTG_THREAD_MEASUREBACK);

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_settem_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_settem_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_change_tps(mtg_t* mtg)
{
    mtg_stop(mtg);

    if(mtg->itps)
    {
        tps_close(&mtg->tps);
        mtg->itps=0;
    }
    tps_init(&mtg->tps,mtg->tps.type);
    //mtg_connect(mtg);
    return 0;
}

int mtg_start_laser(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_START_LASER;
    //if(mtg->iclient==2) client_threadType(mtg,MTG_THREAD_MEASUREBACK);

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_openlaser_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_openlaser_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_stop_laser(mtg_t* mtg)
{
    if(!mtg->itps)
    {
        mtg_log(mtg,MTG_LOG_FAIL_CONNECT_TPS);
        return -1;
    }
    if(mtg->thread)
    {
        mtg_log(mtg,MTG_LOG_IS_RUNNING);
        return -1;
    }
    mtg->ithread=MTG_THREAD_CLOSE_LASER;
    //if(mtg->iclient==2) client_threadType(mtg,MTG_THREAD_MEASUREBACK);

#ifdef WIN32
    if(!(mtg->thread=CreateThread(NULL,0,_mtg_closelaser_thread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_mtg_closelaser_thread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_start_aj(mtg_t* mtg)
{
    if(mtg->ajthread)
    {
        mtg_log(mtg,MTG_LOG_AJ_IS_RUNNING);
        return -1;
    }

#ifdef WIN32
    if(!(mtg->ajthread=CreateThread(NULL,0,_ajthread,mtg,0,NULL)))
#else
    if(pthread_create(&mtg->thread,NULL,_ajthread,mtg))
#endif
    {
        return -1;
    }
    return 0;
}

int mtg_close_aj(mtg_t* mtg)
{
    if(!mtg->ajthread || !mtg->ajstat)
    {
        mtg_log(mtg,MTG_LOG_AJ_NOT_RUNNING);///20150819修改,原因是会出错
        return;
    }
    mtg->ajstat = 0;
    while(mtg->ajthread) sleepms(10);
    return 0;
}



#ifdef WIN32
static DWORD WINAPI _incthreadA(void* arg)
#else
static void *_incthreadA(void *arg)
#endif
{
    mtg_t* mrs=0;
    FILE* fp=NULL;
    int rc;

    mrs=(mtg_t*)arg;

    mrs->incA.command=INC_GET;

    while(mrs->iincA)
    {
        //fp=fopen("D:\\midu\\_incthread.log","w");
//        if(fp)
//        {
//            fprintf(fp,"iincA:%d,iincB:%d\n",mrs->iincA,mrs->iincB);fflush(fp);
//            fprintf(fp,"mrs->opera:%d\n",mrs->opera & MRS_OPERA_INC);fflush(fp);
//            fclose(fp);
//        }
       // if(mrs->iincA)
        {
            inc_thread(&mrs->incA);
            while(inc_get_rc(&mrs->incA,0,&rc)) sleepms(10);
            if(rc==0){
                if(mrs->ver==0)
                {
                    mrs->rollA=mrs->incA.roll+mrs->init_rollA;
                    mrs->pitchA=mrs->incA.pitch+mrs->init_pitchA;
                }
                else{
                    mrs->rollA=mrs->incA.pitch+mrs->init_rollA;
                    mrs->pitchA=mrs->incA.roll+mrs->init_pitchA;
                }
            }
        }
        mrs->m1.inc4[0]=mrs->m.inc4[0]=mrs->rollA;
        mrs->m1.inc4[1]=mrs->m.inc4[1]=mrs->pitchA;
        sleepms(100);
    }

    mrs->incthreadA=0;
}

int mtg_inc_startA(mtg_t* mtg)
{
    if(!mtg->incthreadA)
    {
    #ifdef WIN32
        if(!(mtg->incthreadA=CreateThread(NULL,0,_incthreadA,mtg,0,NULL)))
    #else
        if(pthread_create(&mtg->incthreadA,NULL,_incthreadA,mtg))
    #endif
        {
            return -1;
        }
    }
    return 0;

}


