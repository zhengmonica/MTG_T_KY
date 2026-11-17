/***************************************************************
 * Name:      ResetTargetMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    whq ()
 * Created:   2019-05-14
 * Copyright: whq ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "ResetTargetMain.h"
#include <wx/msgdlg.h>
#include "mysql/mysql.h"

//(*InternalHeaders(ResetTargetDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ResetTargetDialog)
const long ResetTargetDialog::ID_BUTTON1 = wxNewId();
const long ResetTargetDialog::ID_BUTTON2 = wxNewId();
const long ResetTargetDialog::ID_STATICLINE1 = wxNewId();
const long ResetTargetDialog::ID_PANEL3 = wxNewId();
const long ResetTargetDialog::ID_PANEL1 = wxNewId();
const long ResetTargetDialog::ID_PANEL2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ResetTargetDialog,wxDialog)
    //(*EventTable(ResetTargetDialog)
    //*)
END_EVENT_TABLE()

ResetTargetDialog::ResetTargetDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ResetTargetDialog)
    Create(parent, wxID_ANY, _("双倾斜仪恢复工具"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(400,240));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(400,240), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel3 = new wxPanel(Panel1, ID_PANEL3, wxPoint(0,180), wxSize(400,64), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Button1 = new wxButton(Panel3, ID_BUTTON1, _("读取数据"), wxPoint(96,16), wxSize(75,32), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(Panel3, ID_BUTTON2, _("清空数据"), wxPoint(232,16), wxSize(75,32), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticLine1 = new wxStaticLine(Panel3, ID_STATICLINE1, wxPoint(0,1), wxSize(400,1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(0,0), wxSize(400,180), wxTAB_TRAVERSAL, _T("ID_PANEL2"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ResetTargetDialog::OnReadClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ResetTargetDialog::OnClearClick);
    Panel2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ResetTargetDialog::OnPaintMain,0,this);
    //*)
    Center();

    strcpy(host,"localhost");
    strcpy(uid,"root");
    strcpy(psw,"123");//
    strcpy(db,"dba_laser");
    initlock(&dblock);
    stopped=-1;
    readOK=0;
}

ResetTargetDialog::~ResetTargetDialog()
{
    //(*Destroy(ResetTargetDialog)
    //*)
}

int ResetTargetDialog::ReadDB()
{
    int ret=0;
	MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[1024];
	int i;
    int cols=0;

    lock(&dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,host,uid,psw,db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        sprintf(cmd,"select * from target_set order by id desc limit 1");
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            results=mysql_store_result(&mysql);
            cols=mysql_num_fields(results);
            if(cols>=25)
            {
                if(record=mysql_fetch_row(results))
                {
                    sscanf(record[23],"%d",&stopped);
                }

                ret=1;
            }
            mysql_free_result(results);
        }
	}
	mysql_close(&mysql);
	unlock(&dblock);
	return ret;
}

int ResetTargetDialog::WriteDB()
{
    int ret=0;
	MYSQL mysql;
	MYSQL_RES *results;
	MYSQL_ROW record;
	char cmd[1024];
	int i;
    int cols=0;
    FILE* fp=fopen("D://WriteDB.log","w");

    lock(&dblock);
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,host,uid,psw,db,0,NULL,CLIENT_MULTI_STATEMENTS))
	{
        sprintf(cmd,"update target_set set stpd=0 where id=1");
        if(fp)
        {
            fprintf(fp,"%%R1P,10:0:'%s'\n",cmd);fflush(fp);
        }
        if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
        {
            ret=1;
        }
        if(ret==1)
        {
            ret=0;
            sprintf(cmd,"truncate table inccheck_set");
            if(mysql_real_query(&mysql,cmd,strlen(cmd))==0)
            {
                ret=1;
            }
        }
	}
	mysql_close(&mysql);
	unlock(&dblock);
	if(fp)
        fclose(fp);
	return ret;
}

void ResetTargetDialog::OnReadClick(wxCommandEvent& event)
{
    if(ReadDB())
    {
        wxMessageBox(_("读取成功!"));
        readOK=1;
        Panel2->Refresh();
    }
    else
    {
        wxMessageBox(_("读取失败!"));
    }
}

void ResetTargetDialog::OnClearClick(wxCommandEvent& event)
{
    if(readOK)
    {
        if(stopped==1)
        {
            if(WriteDB())
            {
                wxMessageBox(_("清空成功!"));
                stopped=0;
                Panel2->Refresh();
            }
            else
                wxMessageBox(_("清空失败!"));
        }
        else
        {
            wxMessageBox(_("当前状态无需重置!"));
        }
    }
    else
        wxMessageBox(_("尚未读取到数据,无法清空!"));
}

void ResetTargetDialog::OnPaintMain(wxPaintEvent& event)
{
    wxPaintDC dc(Panel2);
    int w,h;
    Panel2->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawLine(0,0,w,0);
        memDC.SetBrush(wxBrush(wxColor(233,233,233)));
        memDC.SetPen(wxPen(wxColor(233,233,233)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        x1=96;
        w1=w-x1*2;
        y1=h/4;
        h1=h/4;
        if(stopped==0)
        {
            memDC.SetTextForeground(wxColor(0,0,255));
            memDC.DrawLabel(_("当前状态：可继续测量"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(stopped==1)
        {
            memDC.SetTextForeground(wxColor(255,0,0));
            memDC.DrawLabel(_("当前状态：停止"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(stopped==-1)
        {
            memDC.SetTextForeground(wxColor(0,0,0));
            memDC.DrawLabel(_("当前状态：--"),wxRect(x1,y1,w,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}
