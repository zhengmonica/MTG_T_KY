///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyfileDlg.h"
#include "mtg_t_svrApp.h"
//#include "confirmdlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MyfileDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MyfileDlg)
#include <wx/font.h>
#include <stdio.h>
#include "wx/filefn.h"
#include <wx/dir.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MyfileDlg)

//*)

MyfileDlg::MyfileDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    fileButton = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    fileButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    filePath = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    fileList = new wxListView(panelMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyfileDlg::OnPaintMain,0,this);

    fileButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyfileDlg::OnPaintFile,0,this);
    fileButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyfileDlg::OnMotionFile,0,this);
    fileButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyfileDlg::OnLeaveFile,0,this);
    fileButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyfileDlg::OnClickFile,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MyfileDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MyfileDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MyfileDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MyfileDlg::OnClickBottom,0,this);

    fileList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&MyfileDlg::OnFileActivated,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    int i=0;
    fileList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    fileList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    fileList->InsertColumn(i++,_("名称"),wxLIST_FORMAT_LEFT,235);
    UptateFileList();
    motion=ID_FP_NONE;

    wxStandardPaths stdp;
    path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);
    path=path+_("/data/");

    fpath=wxEmptyString;
    Type=wxEmptyString;
    iname=wxEmptyString;
    ipath=wxEmptyString;
}

MyfileDlg::~MyfileDlg()
{

}

void MyfileDlg::OnFileActivated(wxListEvent& event)
{
    wxMouseEvent e;
    motion=ID_FP_OK;
    OnClickBottom(e);
}

wxString MyfileDlg::GetFile()
{
    return ipath;
}

wxString MyfileDlg::GetFileName()
{
    return path+Type+iname;
}

void MyfileDlg::UptateFileList()
{
    wxDir dir(path);

    if (!dir.IsOpened())
    {
        // deal with the error here - wxDir would already log an error message
        // explaining the exact reason of the failure
        return;
    }

    puts("Enumerating object files in current directory:");

    wxString filename;
    wxString istr;
    wxString str1;
    bool cont = dir.GetFirst(&filename);
    int i=0;
    int j=0;

    fileList->DeleteAllItems();
    while ( cont )
    {
        //printf("%s\n", filename.c_str());
        istr=filename.Left(4);
        filename.Remove(0,4);
        if(istr.Cmp(Type)==0)
        {
            fileList->InsertItem(i,_(""));
            fileList->SetItem(i,1,wxString::Format(_("%d"),i+1));
            fileList->SetItem(i,2,filename);
            i++;
        }

        cont = dir.GetNext(&filename);
    }
}

void MyfileDlg::OnPaintBottom(wxPaintEvent& event)
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

        memDC.SetPen(wxPen(wxColor(117,117,117)));

        y1=9;
        w1=32;
        h1=26;
        x1=9;

        w1=65;
        x1=w/2+5;
        fpButton[ID_FP_QUIT].x=x1;
        fpButton[ID_FP_QUIT].y=y1;
        fpButton[ID_FP_QUIT].width=w1;
        fpButton[ID_FP_QUIT].height=h1;
        if(motion==ID_FP_QUIT)
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
        memDC.DrawLabel(_("取消"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=w/2-w1-5;
        fpButton[ID_FP_OK].x=x1;
        fpButton[ID_FP_OK].y=y1;
        fpButton[ID_FP_OK].width=w1;
        fpButton[ID_FP_OK].height=h1;
        if(motion==ID_FP_OK)
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
        memDC.DrawLabel(_("确定"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyfileDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>fpButton[ID_FP_QUIT].y && y<fpButton[ID_FP_QUIT].y+fpButton[ID_FP_QUIT].height)
    {
        if(x>fpButton[ID_FP_QUIT].x && x<fpButton[ID_FP_QUIT].x+fpButton[ID_FP_QUIT].width)
        {
            motion=ID_FP_QUIT;
        }
        else if(x>fpButton[ID_FP_OK].x && x<fpButton[ID_FP_OK].x+fpButton[ID_FP_OK].width)
        {
            motion=ID_FP_OK;
        }
        else
        {
            motion=ID_FP_NONE;
        }
    }
    else
    {
        motion=ID_FP_NONE;
    }
    panelBottom->Refresh();
}

void MyfileDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_FP_NONE;
    panelBottom->Refresh();
}

void MyfileDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_FP_OK)
    {
        int sel=fileList->GetFirstSelected();
        int num=fileList->GetItemCount();
        if(sel==num-1)
        {
            if(fpath==wxEmptyString)
            {
                wxListItem item;
                item.m_mask=wxLIST_MASK_TEXT;
                item.m_itemId=sel;
                item.m_col=2;
                fileList->GetItem(item);
                iname=item.GetText();
                ipath=path+Type+iname;
            }
            else
            {
                ipath=fpath;
            }
        }
        else if(sel>=0 && sel<num-1)
        {
            wxListItem item;
            item.m_mask=wxLIST_MASK_TEXT;
            item.m_itemId=sel;
            item.m_col=2;
            fileList->GetItem(item);
            iname=item.GetText();
            ipath=path+Type+iname;
        }
        else
        {
            wxMessageBox(_("请选择文件！"));
            return;
        }
        EndModal(wxID_OK);
    }
    else if(motion==ID_FP_QUIT)
    {
        Destroy();
    }
    //panelBottom->Refresh();
}

void MyfileDlg::OnPaintFile(wxPaintEvent& event)
{
    wxPaintDC dc(fileButton);
    int w,h;
    fileButton->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(239,239,239)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        if(motion==ID_FP_FILE)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
        }
        else
        {
            memDC.SetPen(ipen[0]);
            memDC.SetBrush(ibrush[0]);
        }
        memDC.DrawRoundedRectangle(0,0,w,h,3);
        memDC.DrawLabel(_("浏览..."),wxRect(0,0,w,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MyfileDlg::OnMotionFile(wxMouseEvent& event)
{
    motion=ID_FP_FILE;
    fileButton->Refresh();
}

void MyfileDlg::OnLeaveFile(wxMouseEvent& event)
{
    motion=ID_FP_NONE;
    fileButton->Refresh();
}

void MyfileDlg::OnClickFile(wxMouseEvent& event)
{
    wxFileDialog dlg(this,_("姿态数据"),wxEmptyString,wxEmptyString,_("姿态数据(*.csv)|*.csv"),wxFD_OPEN);
    dlg.Center();
    int add=0;
    if(dlg.ShowModal()==wxID_OK)
    {
        if(fpath==wxEmptyString) add=1;

        iname = dlg.GetFilename();
        fpath = dlg.GetPath();

        filePath->SetValue(iname);

        if(add==1)
        {
            int i=fileList->GetItemCount();
            fileList->InsertItem(i,_(""));
            fileList->SetItem(i,1,wxString::Format(_("%d"),i+1));
            fileList->SetItem(i,2,iname);
            fileList->Select(i);
        }
        else
        {
            int i=fileList->GetItemCount()-1;
            fileList->SetItem(i,2,iname);
            fileList->Select(i);
        }
    }
    fileButton->Refresh();
}

void MyfileDlg::OnPaintMain(wxPaintEvent& event)
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
        memDC.SetPen(wxPen(wxColor(239,239,239)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=45;
        y1=35;
        w1=240;
        h1=30;
        memDC.DrawLabel(_("文件"),wxRect(x1,y1,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
        filePath->SetSize(x1+10,y1-11,w1,-1);
        fileButton->SetSize(x1+w1+20,y1-11,65,23);

        x1=20;
        y1=y1+25;
        w1=350;
        h1=25;
        fileList->SetSize(x1,y1+h1-1,w1,h-y1-45);
        memDC.SetPen(wxPen(wxColor(130,135,144)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        int i=1;
        w1=fileList->GetColumnWidth(i++);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        memDC.DrawLine(x1,y1,x1,y1+h1);
        w1=fileList->GetColumnWidth(i++);
        memDC.DrawLabel(_("文件名称"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(0,10,w,10);
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

