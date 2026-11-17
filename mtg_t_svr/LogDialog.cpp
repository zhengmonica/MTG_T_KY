///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "LogDialog.h"
#include "mtg_t_svrMain.h"

//#include "confirmdlg.h"
//#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(LogDialog)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(LogDialog)
#include <wx/font.h>
#include <stdio.h>
#include "wx/filefn.h"
#include <wx/dir.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(LogDialog)

//*)

LogDialog::LogDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=11;
    w1=w;
    h1=h-57;
    logPanel=new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    logPanel->SetBackgroundColour(wxColor(239,239,239));

    x2=15;
    y2=15;
    w2=120;
    h2=h1-30;

    datePanel=new wxPanel(logPanel, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    datePanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    listDate = new wxListView(datePanel, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    x2=x2+w2+15;
    w2=w1-w2-45;
    logsPanel=new wxPanel(logPanel, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    logsPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    listLog = new wxListView(logsPanel, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&LogDialog::OnPaintBackground,0,this);

    datePanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&LogDialog::OnPaintDateList,0,this);

    logsPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&LogDialog::OnPaintLogs,0,this);

    listDate->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&LogDialog::OnHistorySelect,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&LogDialog::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&LogDialog::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&LogDialog::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&LogDialog::OnClickBottom,0,this);
    //*)
    this->Connect(wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&LogDialog::OnClose);

    this->SetBackgroundColour(wxColor(245,248,250));

    int i=0;
    listDate->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,95);

    i=0;
    listLog->InsertColumn(i++,_("类型"),wxLIST_FORMAT_CENTRE,0);
    listLog->InsertColumn(i++,_("类型"),wxLIST_FORMAT_CENTRE,50);
    listLog->InsertColumn(i++,_("时间"),wxLIST_FORMAT_CENTRE,140);
    listLog->InsertColumn(i++,_("信息"),wxLIST_FORMAT_LEFT,360);

    /*wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);

    wxImageList* imglist=new wxImageList(16,16);
    imglist->Add(wxIcon(path+_("/plugins/Info.ico"),wxBITMAP_TYPE_ICO));
    imglist->Add(wxBitmap(path+_("/plugins/Error.png"),wxBITMAP_TYPE_PNG));
    listLog->SetImageList(imglist,wxIMAGE_LIST_SMALL);*/

    //QureyLogs(0);
    isquerying=false;
    motion=ID_LOG_NONE;
    vmode=0;
    select=-1;
//    Connect(wxEVT_TIMER,(wxObjectEventFunction)&LogDialog::OnTimer);
//    stnTimer.SetOwner(this);
//    stnTimer.Start(10,false);
    UpdateLogName();
}

LogDialog::~LogDialog()
{
    //logDlg=0;
    /*if(cli->qlog)
    {
        free(cli->qlog);
        cli->qlog=0;
        cli->nqlog=0;
    }*/
    if(mtg->ologs)
    {
        free(mtg->ologs);
        mtg->ologs=NULL;
    }
//    stnTimer.Stop();
}

void LogDialog::OnClose(wxCloseEvent& event)
{
    //logDlg=0;
//    Destroy();
    logDlg->Show(false);
}

void LogDialog::UpdateLogName()
{
    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);
    path=path+_("/log");

    wxDir dir(path);

    if (!dir.IsOpened())
    {
        // deal with the error here - wxDir would already log an error message
        // explaining the exact reason of the failure
        return;
    }

    puts("Enumerating object files in current directory:");

    wxString filename;
    listDate->DeleteAllItems();

    bool cont = dir.GetFirst(&filename);
    while ( cont )
    {
        //printf("%s\n", filename.c_str());
        listDate->InsertItem(0,filename);
        cont = dir.GetNext(&filename);
    }
    if(dir.GetFirst(&filename))
    {
        if(select==-1)
            select=0;
        QureyLogs(select);
    }
}

void LogDialog::OnHistorySelect(wxListEvent& event)
{
    int n;
    n=select = listDate->GetFirstSelected();
    int Num = listDate->GetItemCount();
    if(n<0 || n>Num-1) return;

    QureyLogs(select);
}

int LogDialog::UpdateLogList()
{
    listLog->DeleteAllItems();
    for(int i=0;i<mtg->nolog;i++)
    {
        listLog->InsertItem(i,wxEmptyString);
        if(mtg->ologs[i].type==1)
        {
            listLog->SetItem(i,1,_("×"));
        }
        else
        {
            listLog->SetItem(i,1,_("!"));
        }
        listLog->SetItem(i,2,wxDateTime(mtg->ologs[i].t).Format(_("%Y-%m-%d %H:%M:%S")));
        listLog->SetItem(i,3,wxString(mtg->ologs[i].msg,wxConvLocal));
    }
    if(mtg->nolog>0)
        listLog->EnsureVisible(mtg->nolog-1);

    return 0;
}


void LogDialog::QureyLogs(int sel)
{
    wxString ipath;
    char path[260];
    ipath=listDate->GetItemText(sel);
    strncpy(path,ipath.mb_str(wxConvUTF8),260);
//    logs=0;
//    nlogs=0;
    //mtg->ologs=0;
    //wxMessageBox(wxString::Format(_("%d"),mtg->logthread));
    if(mtg->logthread)
    {
        wxMessageBox(_("系统繁忙！"));
        return;
    }

    mtg->logthread=0;
    strcpy(mtg->fpath,path);
//    logs = mtg_get_log(path,&nlogs);
    mtg_start_getlog(mtg);
//    listLog->DeleteAllItems();
//    for(int i=0;i<nlogs;i++)
//    for(int i=0;i<mtg->nolog;i++)
//    {
//        listLog->InsertItem(i,wxEmptyString);
//        if(mtg->ologs[i].type==1)
//        {
//            listLog->SetItem(i,1,_("×"));
//        }
//        else
//        {
//            listLog->SetItem(i,1,_("!"));
//        }
//        listLog->SetItem(i,2,wxDateTime(mtg->ologs[i].t).Format(_("%Y-%m-%d %H:%M:%S")));
//        listLog->SetItem(i,3,wxString(mtg->ologs[i].msg,wxConvLocal));
//    }
//    listLog->EnsureVisible(mtg->nolog-1);
}

void LogDialog::OnPaintDateList(wxPaintEvent& event)
{
    wxPaintDC dc(datePanel);
    int w,h;
    datePanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1=0;
        int y1=0;
        int w1=w;
        int h1=25;
        memDC.SetPen(wxPen(wxColor(173,173,173)));
        memDC.SetBrush(wxBrush(wxColor(225,225,225)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        wxString  str;
        str=_("日期");
        memDC.DrawLabel(str,wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void LogDialog::OnPaintLogs(wxPaintEvent& event)
{
    wxPaintDC dc(logsPanel);
    int w,h;
    logsPanel->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1=0;
        int y1=0;
        int w1=120;
        int h1=25;
        listLog->GetPosition(&x1,&y1);
        listLog->GetSize(&w1,&h1);
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(225,225,225)));
        h1=25;
        y1=y1-h1+1;
        memDC.DrawRectangle(x1,y1,w1,h1);
        int i=1;
        w1=listLog->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=listLog->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("时间"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=listLog->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("信息"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void LogDialog::OnPaintBottom(wxPaintEvent& event)
{
    wxPaintDC dc(panelBottom);
    int w,h;
    panelBottom->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        int r1,g1,b1;
        r1=236;
        g1=236;
        b1=236;
        for(int i=0;i<h;i++)
        {
            memDC.SetPen(wxPen(wxColor(r1,g1,b1)));
            memDC.DrawLine(0,i,w,i);
            if(i%3==0)
            {
                if(i<h/2)
                {
                    r1--;
                    g1--;
                    b1--;
                }
                else
                {
                    r1++;
                    g1++;
                    b1++;
                }
            }
        }

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;
        int w2,h2;
        memDC.SetPen(wxPen(wxColor(117,117,117)));

        y1=9;
        w1=32;
        h1=26;
        x1=9;

        w1=65;
        x1=w-w1-12;
        smButton[ID_LOG_QUIT].x=x1;
        smButton[ID_LOG_QUIT].y=y1;
        smButton[ID_LOG_QUIT].width=w1;
        smButton[ID_LOG_QUIT].height=h1;
        if(motion==ID_LOG_QUIT)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("退出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=w-w1-12;
        x1=x1-w1-10;
        smButton[ID_LOG_IPT].x=x1;
        smButton[ID_LOG_IPT].y=y1;
        smButton[ID_LOG_IPT].width=w1;
        smButton[ID_LOG_IPT].height=h1;
        if(motion==ID_LOG_IPT)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("导出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void LogDialog::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>smButton[ID_LOG_QUIT].y && y<smButton[ID_LOG_QUIT].y+smButton[ID_LOG_QUIT].height)
    {
        if(x>smButton[ID_LOG_QUIT].x && x<smButton[ID_LOG_QUIT].x+smButton[ID_LOG_QUIT].width)
        {
            motion=ID_LOG_QUIT;
        }
        else if(x>smButton[ID_LOG_IPT].x && x<smButton[ID_LOG_IPT].x+smButton[ID_LOG_IPT].width)
        {
            motion=ID_LOG_IPT;
        }
        else
        {
            motion=ID_LOG_NONE;
        }
    }
    else
    {
        motion=ID_LOG_NONE;
    }
    panelBottom->Refresh();
}

void LogDialog::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_LOG_NONE;
    panelBottom->Refresh();
}

void LogDialog::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_LOG_QUIT)
    {
        //logDlg=0;
//        EndModal(wxID_OK);
        Close();
    }
    else if(motion==ID_LOG_IPT)
    {
        if(mtg->nolog<=0) return;
        int sel=listDate->GetFirstSelected();
        int Num = listDate->GetItemCount();
        wxString istr;
        if(sel<0 || sel>Num-1)
        {
            istr=listDate->GetItemText(0);
        }
        else
        {
            istr=listDate->GetItemText(sel);
        }
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),istr,_("日志文件(*.log)|*.log"),wxFD_SAVE);

        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str=dlg.GetPath();
            char cs[1024];
            strcpy(cs,str.mb_str(wxConvLocal));
            FILE* fp=fopen(cs,"w");
            if(fp)
            {
                char path[260];
                for(int i=0;i<mtg->nolog;i++)
                {
                    strftime(path,64,"%Y-%m-%d %H:%M:%S",localtime(&mtg->ologs[i].t));
                    fprintf(fp,"%d,%d,%s,%s\n",mtg->ologs[i].nlog,mtg->ologs[i].type,path,mtg->ologs[i].msg);
                }
                fclose(fp);
                wxMessageBox(_("保存成功！"));
            }
        }
    }
    //panelBottom->Refresh();
}

void LogDialog::OnPaintBackground(wxPaintEvent& event)
{
    wxPaintDC dc(panelMain);
    int w,h;
    panelMain->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(0,10,w,10);
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

//void LogDialog::OnTimer(wxTimerEvent& event)
//{
//    static int tick=0;
//    int i=0;
//
//    if(mtg->plog > 0)
//    {
//        for(i=0;i<mtg->plog;i++)
//        {
//            if(mtg->plogs[i].nlog==MTG_LOG_FINISH_GET_LOG)
//            {
//                //UpdateLogList();
//            }
//        }
//        mtg->plog=0;
//    }
//    tick++;
//
//    if(tick == 1200) tick=0;
//}
