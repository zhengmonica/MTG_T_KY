#include "libmtg.h"

#include <direct.h>
#include <string.h>
#include "WinInet.h"
#include <winsock.h>
#include <iomanip>
#include "stdio.h"
#include "stdlib.h"

mtg_tw testW={0};

int init_web(char *path)
{
    FILE* initFile=NULL;
    char* filepath;
    char buf[1024]={0};
    char* ret=NULL;
    int i=0;
    BOOL bRet = FALSE;

    filepath=_getcwd(NULL,0);
    sprintf(buf,"%s\\init_web.log",filepath);
    FILE* fp = fopen(buf,"w");
    fprintf(fp,"%s\n",path);fflush(fp);

    initFile = fopen(path,"r");
    if(initFile==NULL) return 0;
    fprintf(fp,"open ok\n");fflush(fp);

    ret = fgets(buf,1023,initFile);
    if(!ret)
    {
        fclose(initFile);
        return 0;
    }
    sscanf(buf,"%d",&i);
    fprintf(fp,"%d\n",i);fflush(fp);

    testW.nunit=i;
    for(i=0;i<testW.nunit&&!feof(initFile);i++)
    {
        ret = fgets(buf,1023,initFile);
        if(!ret) break;
		fprintf(fp,"%s\n",buf);
		fflush(fp);
		//sscanf(buf,"%d,%d,%d,%d",&testW.units[i].addr,&testW.units[i].type,&testW.units[i].readorwrite,&testW.units[i].format);
		//fprintf(fp,"i=%d,addr=%d,type=%d,readorwrite=%d,format=%d\n",i,testW.units[i].addr,testW.units[i].type,testW.units[i].readorwrite,testW.units[i].format);
		sscanf(buf,"%d,%d,%d,%d,%d,%lf,%lf",&testW.units[i].addr,&testW.units[i].bitnum,&testW.units[i].type,&testW.units[i].readorwrite,&testW.units[i].format,&testW.units[i].val_add,&testW.units[i].val_mul);
		fprintf(fp,"i=%d,addr=%d,bitnum=%d,type=%d,readorwrite=%d,format=%d,val_add=%.4f,val_mul=%.4f\n",i,testW.units[i].addr,testW.units[i].bitnum,testW.units[i].type,testW.units[i].readorwrite,testW.units[i].format,testW.units[i].val_add,testW.units[i].val_mul);
		fflush(fp);
    }
    fclose(initFile);
    if(i==0)
	{
		//if(testW.units) free(testW.units);
		fclose(fp);
		return 0;
	}
	testW.nunit=i;
    fclose(fp);
    return 1;
}


void UnicodeToAnsi(LPCWSTR tchar, char * _char)
{
	int iLength;
	//获取字节长度
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//将tchar值赋给_char
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}

/**
 * 字节数组到int的转换.
 */
int base64_decode(unsigned char* dst, const unsigned char* src)
{
    static unsigned char   basis64[] = {
        77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77,
        77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77,
        77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 62, 77, 77, 77, 63,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 77, 77, 77, 77, 77, 77,
        77,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 77, 77, 77, 77, 77,
        77, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 77, 77, 77, 77, 77,

        77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77,
        77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77,
        77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77,
        77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77,
        77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77,
        77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77,
        77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77,
        77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77
    };

    int srclen = strlen((char*)src);
    int len = 0;

    for (; len < srclen; len++)
    {
        if (src[len] == '=')
        {
            break;
        }

        if (basis64[src[len]] == 77)
        {
            return -1;
        }
    }


    if ((len >> 2) == 1)
    {
        return -1;
    }

    while (len > 3)
    {
        *dst++ = (unsigned char)((basis64[src[0]] << 2) | (basis64[src[1]] >> 4));
        *dst++ = (unsigned char)((basis64[src[1]] << 4) | (basis64[src[2]] >> 2));
        *dst++ = (unsigned char)((basis64[src[2]] << 6) | basis64[src[3]]);

        src += 4;
        len -= 4;
    }


    if (len > 1)
    {
        *dst++ = (unsigned char)((basis64[src[0]] << 2) | (basis64[src[1]] >> 4));
    }
    if (len > 2)
    {
        *dst++ = (unsigned char)((basis64[src[1]] << 4) | (basis64[src[2]] >> 2));
    }

    *dst = '\0';
    return 1;
}

int GetBitValue(int value,int *tag)
{
    int i=0;
    FILE *fp=fopen("D:\\midu\\GetBitValue.log","w");
    if(fp)
    {
        fprintf(fp,"value=%d\n",value);
        fflush(fp);
    }
    while(value)
    {
        if(value & 1 ==1)
        {
            tag[i]=1;
        }
        if(fp)
        {
            fprintf(fp,"i=%d,tag=%d\n",i,tag[i]);
            fflush(fp);
        }

        i++;
        if(i==128)
            break;
        value=value >> 1;
    }
    if(fp)
        fclose(fp);
    return 1;
}


int get_data(char* result)
{
    int i=0;
    int addr=0;
    int val=0;
    int  val1=0;
    char *str1=0;
    char buf[5020]={0};
    char *bufin=0;
    byte temp[2]={0};
    int rec=0;

    FILE *fp=fopen("D:\\midu\\read_web_get.log","w");
    if(fp)
    {
        fprintf(fp,"start %s\n",result);
        fflush(fp);
    }

    str1=strstr(result,"<base64Binary");

    if(str1)
    {
        for(i=0;i<100;i++)
        {
            if(str1[i]=='>')
            {
                bufin=str1+i+1;
                break;
            }
        }
    }
    if(bufin==NULL)
    {
        if(fp)
            fclose(fp);
      return -1;
    }

    if(base64_decode((unsigned char*)buf,(const unsigned char*)bufin)==-1)
    {
        if(fp)
            fclose(fp);
        return -1;
    }

    for(i=read_plc_start_val;i<=read_plc_bj_d;i++)   ///从掘进状态开始获取数据,共六个
    {
        if(testW.units[i].readorwrite!=0)   //不是读的数据跳过
            continue;
        //从addr的位置开始获取两个字节的数据通过计算作为实际数据
        addr=testW.units[i].addr;

        val=buf[addr];
        val1=buf[addr+1];
        if(fp)
        {
            fprintf(fp,"i=%d,addr=%d,val=%d,val1=%d\n",i,addr,val,val1);
            fflush(fp);
        }

//        if(testW.units[i].format<0)
//            val=-val/testW.units[i].format;
//        else
//            val=val*testW.units[i].format;
        if(i<=read_plc_mode_val)//掘进状态 拼装状态
        {

			if(testW.units[i].type==11)//bool
            {
                testW.units[i].val_int=(int)(val*testW.units[i].val_mul+testW.units[i].val_add);
                testW.units[i].val_double=(val*testW.units[i].val_mul+testW.units[i].val_add)*1.0;
            }
            else if(testW.units[i].type==2)//int
            {
                testW.units[i].val_int=(int)(val1*testW.units[i].val_mul+testW.units[i].val_add);
                testW.units[i].val_double=(val1*testW.units[i].val_mul+testW.units[i].val_add)*1.0;
            }

           // testW.units[i].val_int=val1;
           // testW.units[i].val_double=val1*1.0;

        }
        else
        {
            if(val1<0)
                val=val*256+val1+256;
            else
                val=val*256+val1;


            //testW.units[i].val_int=val;
            //testW.units[i].val_double=val*1.0;
		   if(i>=2)
		   {
				testW.units[i].val_int=(int)(val*testW.units[i].val_mul+testW.units[i].val_add);
				testW.units[i].val_double=(val*testW.units[i].val_mul+testW.units[i].val_add)*1.0;
		   }
		}
		if(testW.units[i].bitnum>0)
		{
			int tag[128]={0};
			GetBitValue(testW.units[i].val_int,tag);
			testW.units[i].val_bit=tag[testW.units[i].bitnum];
			if(fp)
			{
				fprintf(fp,"bitnum=%d,val_bit=%d\n",testW.units[i].bitnum,testW.units[i].val_bit);
				fflush(fp);
			}
		}
        if(fp)
        {
            fprintf(fp,"i=%d,addr=%d,val=%d\n",i,addr,testW.units[i].val_int);
            fflush(fp);
        }
    }
    if(fp)
        fclose(fp);
    return 1;
}

extern int read_web()
{
    char url[1024]={0};
    //int len;
    FILE *fp=fopen("D:\\midu\\read_web.log","w");

//    sprintf(url,"%s","http://192.168.110.103");
//    len=strlen(url);
//    WCHAR *exchange_text_from_url=(WCHAR*)calloc(2*len,sizeof(WCHAR));
//    MultiByteToWideChar( 0, 0,url, -1, exchange_text_from_url, 2*len );
//    LPCWSTR py = exchange_text_from_url;

    HINTERNET hInternetOpen = InternetOpen(testW.m_sIPWeb,INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0);

    if(fp)
    {
        UnicodeToAnsi(testW.m_sIPWeb,url);
        fprintf(fp,"url page %s\n",url);
        fflush(fp);
    }

    if(hInternetOpen < 0 )
    {
        if(fp)
        {
            fprintf(fp,"Can't open the page\n");
            fflush(fp);
        }
    }
    else
    {
        HINTERNET hInternetConnect = InternetConnect(hInternetOpen,testW.m_sIPWeb,80,NULL,L"HTTP/1.1",INTERNET_SERVICE_HTTP,0,0);
        if(hInternetConnect < 0 )
        {
            if(fp)
            {
                fprintf(fp,"Can't connect to the server\n");
                fflush(fp);
            }
        }
        else
        {
//            HINTERNET  hHttpOpenRequest = HttpOpenRequest(hInternetConnect,L"POST",L"/Service.asmx?op=Data2Client",L"HTTP/1.1",NULL,0,INTERNET_FLAG_RELOAD,0);
//            HINTERNET  hHttpOpenRequest = HttpOpenRequest(hInternetConnect,L"POST",L"/Service.asmx/Data2Client",L"HTTP/1.1",NULL,0,INTERNET_FLAG_RELOAD,0);
//            HINTERNET  hHttpOpenRequest = HttpOpenRequest(hInternetConnect,L"POST",testW.m_sUrlReadWeb,L"HTTP/1.1",NULL,0,INTERNET_FLAG_RELOAD,0);
            HINTERNET  hHttpOpenRequest = HttpOpenRequest(hInternetConnect,L"GET",testW.m_sUrlReadWeb,L"HTTP/1.1",NULL,0,INTERNET_FLAG_RELOAD,0);
//            HINTERNET  hHttpOpenRequest = HttpOpenRequest(hInternetConnect,L"GET",L"/Service.asmx/Data2Client?mac=DZ1023&psw=02bacd",L"HTTP/1.1",NULL,0,INTERNET_FLAG_RELOAD,0);
            if(fp)
            {
                fprintf(fp,"m_sUrlReadWeb:%s\n",testW.m_sUrlReadWeb);
                fflush(fp);
            }
            if(hHttpOpenRequest < 0 )
            {
                if(fp)
                {
                    fprintf(fp,"Open request fail\n");
                    fflush(fp);
                }
            }
            else
            {
                char  chData[128] = "";
                DWORD len = strlen(chData);
                int bRet = HttpSendRequest(hHttpOpenRequest,L"Content-Type:   application/x-www-form-urlencoded",
		 strlen("Content-Type:   application/x-www-form-urlencoded"),(LPVOID *)chData,len);

                if(fp)
                {
                    fprintf(fp,"bret:%d\n",bRet);
                    fflush(fp);
                }

                char tChars[5020];
                memset(tChars,0,5020);
                DWORD dwReadLen;
                BOOL bl=  InternetReadFile(hHttpOpenRequest,(LPVOID *)tChars,5020,&dwReadLen);
                if(dwReadLen > 0)
                {
                    if(fp)
                    {
                        fprintf(fp,"tChars :%s,%d,%d\n",tChars,dwReadLen,bl);
                        fflush(fp);
                    }
                    if(get_data(tChars)==1)
                    {
                        testW.read_web_complete=1;
                        if(fp)
                        {
                            fprintf(fp,"read_web_complete=%d\n",testW.read_web_complete);
                            fflush(fp);
                        }
                    }
                }
                else
                {
                    if(fp)
                    {
                        fprintf(fp,"Read the reply fail\n");
                        fflush(fp);
                    }
                }
            }
            InternetCloseHandle(hHttpOpenRequest);
        }
        InternetCloseHandle(hInternetConnect);
    }
    InternetCloseHandle(hInternetOpen);

    if(fp)
        fclose(fp);

    return 1;
}

int get_att(char* att,char *str1)
{
    int i=0;
    int head=0;
    int tail=0;
    int endn=0;
    char buf[1024]={0};
//    FILE *fp=fopen("D:\\20191224.log","w");
//    fprintf(fp,"%s\n",att);

    if(att)
    {
        for(i=0;i<strlen(att);i++)
        {
//            fprintf(fp,"i=%d,atti:%c\n",i,att[i]);
            if(att[i]=='>')
                head=i;

            if(att[i]=='<')
                tail=i;

            if(tail>head)
                break;
        }
    }
//    fprintf(fp,"head=%d,tail=%d\n",head,tail);

    memcpy(str1,att+head+1,tail-head-1);
//    fprintf(fp,"%s\n",str1);

    memcpy(buf,att+tail+13,strlen(att)-tail-13);
    strcpy(att,buf);

//    fclose(fp);
    return 1;
}

int get_tbm(char* result)
{
    int i=0;
    int len=0;
    char *str1=0;
    char str2[128]={0};
    char buf[128]={0};
    int head=0;
    int tail=0;
    int n=0;

    FILE *fp=fopen("D:\\midu\\read_tbm_get.log","w");

    //len=strlen(result);
    str1=strstr(result,"<string>");
    if (!str1)
    {
        if(fp)
        {
            fprintf(fp,"find <string> error\n");
            fclose(fp);
        }

        return 0;
    }

    if(fp)
    {
        fprintf(fp,"str1:%s\n",str1);
        fflush(fp);
    }

    get_att(str1,str2);
//    if(fp)
//    {
//        fprintf(fp,"str1:%s\n str2:%s\n",str1,str2);
//        fflush(fp);
//    }
    memset(str2,0,sizeof(char)*128);

//    n=6;
//    while(strlen(str1)>16)
//    {
//        get_att(str1,str2);
////        if(fp)
////        {
////            fprintf(fp,"str1:%s\n str2:%s\n",str1,str2);
////            fflush(fp);
////        }
//        if(n>=testW.nunit)
//            break;
//        testW.units[n].val_double=atof(str2);
//        n++;
//        memset(str2,0,sizeof(char)*128);
//    }
//
//    for(i=6;i<testW.nunit;i++)
//    {
//        if(fp)
//        {
//            fprintf(fp,"i=%d,%.4f\n",i,testW.units[i].val_double);
//            fflush(fp);
//        }
//    }

    n=0;
    while(strlen(str1)>16)
    {
        get_att(str1,str2);
        if(n>=testW.nunit)
            break;

        if(n==0)
        {
            testW.units[3].val_double=atof(str2);
        }
        else if(n>0&&n<12)
        {

        }
        else if(n==12)
        {
            testW.units[2].val_double=atof(str2);
        }
        n++;
        memset(str2,0,sizeof(char)*128);
    }

    if(fp)
    {
        i=2;
        fprintf(fp,"i=%d,%.4f\n",i,testW.units[i].val_double);
        i=3;
        fprintf(fp,"i=%d,%.4f\n",i,testW.units[i].val_double);
        fflush(fp);
    }

    if(fp)
        fclose(fp);
    return 1;
}

extern int read_tbm()   ///暂时不用
{
    FILE *fp=fopen("D:\\midu\\read_tbm.log","w");

    HINTERNET hInternetOpen = InternetOpen(testW.m_sIPTbm,INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0);
    if(hInternetOpen < 0 )
    {
        if(fp)
        {
            fprintf(fp,"Can't open the page\n");
            fflush(fp);
        }
    }
    else
    {
        HINTERNET hInternetConnect = InternetConnect(hInternetOpen,testW.m_sIPTbm,80,NULL,L"HTTP/1.1",INTERNET_SERVICE_HTTP,0,0);
        if(hInternetConnect < 0 )
        {
            if(fp)
            {
                fprintf(fp,"Can't connect to the server\n");
                fflush(fp);
            }
        }
        else
        {
//            HINTERNET  hHttpOpenRequest = HttpOpenRequest(hInternetConnect,L"POST",L"/Service.asmx?op=GetTBM",L"HTTP/1.1",NULL,0,INTERNET_FLAG_RELOAD,0);
//            HINTERNET  hHttpOpenRequest = HttpOpenRequest(hInternetConnect,L"POST",L"/Service.asmx/GetTBM",L"HTTP/1.1",NULL,0,INTERNET_FLAG_RELOAD,0);
            HINTERNET  hHttpOpenRequest = HttpOpenRequest(hInternetConnect,L"POST",testW.m_sUrlReadTbm,L"HTTP/1.1",NULL,0,INTERNET_FLAG_RELOAD,0);
            if(hHttpOpenRequest < 0 )
            {
                if(fp)
                {
                    fprintf(fp,"Open request fail\n");
                    fflush(fp);
                }
            }
            else
            {
                char  chData[128] = "";
                DWORD len = strlen(chData);
                int bRet = HttpSendRequest(hHttpOpenRequest,L"Content-Type:   application/x-www-form-urlencoded",
                        strlen("Content-Type:   application/x-www-form-urlencoded"),(LPVOID *)chData,len);

                char tChars[5020];
                memset(tChars,0,5020);
                DWORD dwReadLen;
                InternetReadFile(hHttpOpenRequest,(LPVOID *)tChars,5020,&dwReadLen);
                if(dwReadLen > 0)
                {
                    if(fp)
                    {
                        fprintf(fp,"%s\n",tChars);
                        fflush(fp);
                    }
                    if(get_tbm(tChars)==1)
                    {
                        testW.read_tbm_complete=1;
                        if(fp)
                        {
                            fprintf(fp,"read_tbm_complete=%d\n",testW.read_tbm_complete);
                            fflush(fp);
                        }
                    }
                    else
                    {
                        if(fp)
                        {
                            fprintf(fp,"get_tbm warning error\n");
                            fflush(fp);
                            fclose(fp);
                        }
                        InternetCloseHandle(hHttpOpenRequest);
                        InternetCloseHandle(hInternetConnect);
                        InternetCloseHandle(hInternetOpen);
                        return 0;
                    }
                }
                else
                {
                    if(fp)
                    {
                        fprintf(fp,"Read the reply fail\n");
                        fflush(fp);
                    }
                }
            }
            InternetCloseHandle(hHttpOpenRequest);
        }
        InternetCloseHandle(hInternetConnect);
    }
    InternetCloseHandle(hInternetOpen);

    if(fp)
        fclose(fp);
    return 1;
}

int write_tbm_data(char* data)
{
//    char upbuf[5024]={0};
    char ch[128]={0};
    char *chstart="<string>";
    char *chend="</string>\n";
    int i=0;

    strcpy(data,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n\
           <soap:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:soap=\"http://schemas.xmlsoap.org/soap/envel未结束>\n\
             <soap:Body>\n\
               <setData xmlns=\"http://www.crcc.cn/\">\n\
                 <data>\n");
    for(i=write_plc_pitch1_val;i<write_plc_numb1_val;i++)   //数据部分
    {
        if(testW.units[i].readorwrite!=1)
            continue;

        strcat(data,chstart);
        sprintf(ch,"%.4f",testW.units[i].val_double);
        strcat(data,ch);
        strcat(data,chend);
    }
    strcat(data,chstart);
    sprintf(ch,"%d",testW.units[write_plc_numb1_val].val_int);
    strcat(data,ch);
    strcat(data,chend);

    strcat(data,"</data>\n</setData>\n</soap:Body>\n</soap:Envelope>");

    return 1;
}

extern int write_tbm()
{
    FILE *fp=fopen("D:\\midu\\write_tbm.log","w");

    HINTERNET hInternetOpen = InternetOpen(testW.m_sIPTbm,INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0);
    if(hInternetOpen < 0 )
    {
        if(fp)
        {
            fprintf(fp,"Can't open the page\n");
            fflush(fp);
        }
    }
    else
    {
        HINTERNET hInternetConnect = InternetConnect(hInternetOpen,testW.m_sIPTbm,80,NULL,L"HTTP/1.1",INTERNET_SERVICE_HTTP,0,0);
        if(hInternetConnect < 0 )
        {
            if(fp)
            {
                fprintf(fp,"Can't connect to the server\n");
                fflush(fp);
            }
        }
        else
        {
            HINTERNET  hHttpOpenRequest = HttpOpenRequest(hInternetConnect,L"POST",testW.m_sUrlWriteTbm,L"HTTP/1.1",NULL,0,INTERNET_FLAG_RELOAD,0);
            if(hHttpOpenRequest < 0 )
            {
                if(fp)
                {
                    fprintf(fp,"Open request fail\n");
                    fflush(fp);
                }
            }
            else
            {
                char chData[5020] ={0};
                if(write_tbm_data(chData))
                {
                    if(fp)
                    {
                        fprintf(fp,"%s\n",chData);
                        fflush(fp);
                    }
                    DWORD len = strlen(chData);
                    int bRet = HttpSendRequest(hHttpOpenRequest,L"Content-Type:text/xml",strlen("Content-Type:text/xml"),(LPVOID *)chData,len);

                    char tChars[5020];
                    memset(tChars,0,5020);
                    DWORD dwReadLen;
                    InternetReadFile(hHttpOpenRequest,(LPVOID *)tChars,5020,&dwReadLen);
                    if(dwReadLen > 0)
                    {
                        testW.write_tbm_complete=1;
                        if(fp)
                        {
                            fprintf(fp,"%s\n",tChars);
                            fflush(fp);
                            fprintf(fp,"write_tbm_complete=%d\n",testW.write_tbm_complete);
                            fflush(fp);
                        }

                    }
                    else
                    {
                        if(fp)
                        {
                            fprintf(fp,"Write data fail\n");
                            fflush(fp);
                        }
                    }
                }
                else
                {
                    if(fp)
                    {
                        fprintf(fp,"write_tbm_data function fail\n");
                        fflush(fp);
                    }
                }
            }
            InternetCloseHandle(hHttpOpenRequest);
        }
        InternetCloseHandle(hInternetConnect);
    }
    InternetCloseHandle(hInternetOpen);

    if(fp)
        fclose(fp);
    return 1;
}
