#include "ping.h"
#include <iostream>
#include<fstream>
using namespace std;


char CheckChar(int index)
{
    FILE *f;
    char fn[40]="d:\\ping.txt";
    char ln[80];
    char yn;
    int  n;

    yn='N';
    f=fopen(fn,"r");
    if(NULL!=f)
    {
        n=0;
        while(1)
        {
            if(NULL==fgets(ln,80,f))
                break;//
            if(strstr(ln,"ms"))
            {
                yn='Y';
                break;//
            }
            n++;
            if(n>=4)
                break;//
        }
        fclose(f);
    }
    return yn;
}

BOOL IsIpValid(char * pcsIp)
{
    char cmdstr[256] = {0};
    int i;
    char c;
    BOOL bConnected = FALSE;

    std::ofstream Out("d:/logFile.txt");

    sprintf(cmdstr,"cmd /c ping %s -n 1 -w 1000 >d:\\ping.txt", pcsIp);
    WinExec(cmdstr,SW_HIDE);

    Sleep(3000);
    sprintf(cmdstr,"%c %s\n",CheckChar(0), pcsIp);
    Out << cmdstr ;

    Sleep(3000);
    ::WinExec("cmd /c del /q d:\\ping.txt",SW_HIDE);

    if(CheckChar(0)=='Y')
        bConnected=TRUE;
    else
        bConnected=FALSE;

    Sleep(1000);

    ::WinExec("cmd /c del /q d:\\logFile.txt",SW_HIDE);

    return bConnected;
}
