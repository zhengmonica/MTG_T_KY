///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MydoctorDlg.h"
#include "mtg_t_svrMain.h"
#include "mtg_t_svrApp.h"
//#include "confirmdlg.h"
//#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include "laserimg.h"

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MydoctorDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MydoctorDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MydoctorDlg)

//*)

MydoctorDlg::MydoctorDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelMain = new wxPanel(this, wxID_ANY, wxPoint(150,0), wxSize(w-150,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPage = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(150,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    biList = new wxListView(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w-150,h-55), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    mainList = new wxListView(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w-150,h-55), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    mainList->Show(false);
    opList = new wxListView(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w-150,h-55), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    opList->Show(false);

    panelLaser = new wxPanel(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w-150,h-55), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelLaser->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelLaser->Show(false);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintMain,0,this);

	panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MydoctorDlg::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MydoctorDlg::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MydoctorDlg::OnClickPage,0,this);
    panelLaser->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintLaser,0,this);
    panelLaser->Connect(wxEVT_LEFT_DCLICK,(wxObjectEventFunction)&MydoctorDlg::OnDoubleClickLaser,0,this);
    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MydoctorDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MydoctorDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MydoctorDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MydoctorDlg::OnClickBottom,0,this);
    //*)
    //Connect(wxEVT_TIMER,(wxObjectEventFunction)&MydoctorDlg::OnTimer);
    //timerStat.SetOwner(this);
    //timerStat.Start(100,false);

    this->SetBackgroundColour(wxColor(245,248,250));

    page=0;
    motion=ID_DOC_NONE;

    int i=0;
    docLabel[i++]=_("系统启动");
    docLabel[i++]=_("主过程");
    docLabel[i++]=_("操作记录");
    docLabel[i++]=_("光斑分析");

    i=0;
	biList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    biList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    biList->InsertColumn(i++,_("内容"),wxLIST_FORMAT_LEFT,480);
    i=0;
	mainList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    mainList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    mainList->InsertColumn(i++,_("内容"),wxLIST_FORMAT_LEFT,480);
    i=0;
	opList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    opList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,55);
    opList->InsertColumn(i++,_("日期"),wxLIST_FORMAT_CENTRE,150);
    opList->InsertColumn(i++,_("内容"),wxLIST_FORMAT_LEFT,350);
    //biList->InsertColumn(i++,_("错误"),wxLIST_FORMAT_CENTRE,75);
    LoadMessage();
}

MydoctorDlg::~MydoctorDlg()
{

}

void MydoctorDlg::OnPaintLaser(wxPaintEvent& event)
{
    wxPaintDC dc(panelLaser);
    int w,h;
    panelLaser->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        //background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        int x=0;
        int y=0;

        if(bmpLaser.IsOk())
        {
            int w1;
            int h1;
            w1=bmpLaser.GetWidth();
            h1=bmpLaser.GetHeight();
            double s=(w-2)*1.0/w1;
            memDC.SetUserScale(s,s);
            memDC.DrawBitmap(bmpLaser,1,1);
            memDC.SetUserScale(1.0,1.0);
            memDC.SetTextForeground(wxColor(255,255,255));
            memDC.DrawLabel(wxString::Format(_("%.4f"),speckle[0]),wxRect(10,30,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            memDC.DrawLabel(wxString::Format(_("%.4f"),speckle[1]),wxRect(10,60,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnDoubleClickLaser(wxMouseEvent& event)
{
    wxFileDialog dlg(this,_("请选择要打开的图片"),_(""),_(""),_("图像文件(*.*)|*.*"),wxFD_OPEN);
    if(dlg.ShowModal()==wxID_OK)
    {
        wxString path=dlg.GetPath();
        if(m_img.LoadFile(path))
        {
            bmpLaser=wxBitmap(m_img);

            unsigned char* uc=m_img.GetData();
            unsigned char* uc1;
            int w,h;
            w=m_img.GetWidth();
            h=m_img.GetHeight();
            int ret;
            int k;
            int rgb=0;
            for(int x=0;x<w;x++)
            {
                for(int y=0;y<h;y++)
                {
                    k=y*w+x;
                    rgb=uc[3*k+2];
                    uc[3*k+2]=uc[3*k];
                    uc[3*k]=rgb;
                }
            }
            ret=laser_image_speckle2(uc,w,h,speckle);
            panelLaser->Refresh();
            wxMessageBox(wxString::Format(_("%d"),ret));
        }
    }
}

void MydoctorDlg::LoadMessage()
{
    if(page==0)
    {
        FILE* fp=fopen(mtg->pbi,"r");

        if(fp)
        {
            rewind(fp);

            char str[300];
            int it1,it2;
            int i=0;
            biList->DeleteAllItems();
            while(!feof(fp))
            {
                fgets(str,300,fp);
                if(!sscanf(str,"%%R1P,%d,%d",&it1,&it2))
                {
                    continue;
                }
                //wxMessageBox(wxString::Format(_("it1=%d,it2=%d"),it1,it2));
                switch(it1)
                {
                    case 0:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("工程数据"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            i++;
                        }
                        break;
                    }
                    case 1:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("关键区域"));
                            //biList->SetItem(i,3,wxString::Format(_("%d"),it2));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            i++;
                        }
                        break;
                    }
                    case 2:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("管环监测"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            i++;
                        }
                        break;
                    }
                    case 3:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("环号计算"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            i++;
                        }
                        break;
                    }
                    case 4:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("盾构参数"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            i++;
                        }
                        break;
                    }
                    case 5:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("激光靶配置文件缺失,请检查!"));
                            //biList->SetItem(i,3,wxString::Format(_("%d"),it2));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 6:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("地图参数"));
                            //biList->SetItem(i,3,wxString::Format(_("%d"),it2));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            i++;
                        }
                        break;
                    }
                    case 7:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("激光靶参数错误，请检查!"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 8:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("全站仪参数错误，请检查!"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 9:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("缺少管块参数，影响管环选型功能的使用。"));
                            //biList->SetItem(i,3,wxString::Format(_("%d"),it2));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            i++;
                        }
                        break;
                    }
                    case 10:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("系统参数错误，请检查!"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 11:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("缺少吊篮坐标，请检查!"));
                            //biList->SetItem(i,3,wxString::Format(_("%d"),it2));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 12:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("权限未设置，请检查!"));
                            //biList->SetItem(i,3,wxString::Format(_("%d"),it2));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 13:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("测站未设置，请检查!"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 14:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("初始姿态数据缺失，请检查!"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 15:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("系统缺少测量数据"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            //biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 16:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("缺少姿态复核数据，姿态复核功能不能使用。"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            //biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 17:
                    {
                        if(it2<=2)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("缺少平曲线要素，请检查!"));
                            //biList->SetItem(i,3,wxString::Format(_("%d"),it2));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 18:
                    {
                        if(it2<=2)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("缺少竖曲线要素，请检查!"));
                            //biList->SetItem(i,3,wxString::Format(_("%d"),it2));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 19:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("平曲线偏移"));
                            //biList->SetItem(i,3,wxString::Format(_("%d"),it2));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            //biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 20:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("竖曲线偏移"));
                            //biList->SetItem(i,3,wxString::Format(_("%d"),it2));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            //biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 21:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("断链参数"));
                            //biList->SetItem(i,3,wxString::Format(_("%d"),it2));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            //biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 22:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("缺少管环选型参数，管环选型功能不能正常使用。"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            //biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 23:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("缺少管环设计排版必须的起算数据，管环设计排版不能计算。"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            //biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 24:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("缺少管环参数，讲影响系统部分功能正常使用。"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                            biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 25:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("姿态复核数据确实，姿态复核功能不能使用。"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            //biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 26:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("缺少掘进统计数据"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            //biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 27:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("缺少盾尾间隙必须的数据，盾尾间隙功能不能使用。"));
                            //biList->SetItem(i,3,_("×"));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            //biList->SetItemTextColour(i,wxColor(255,255,255));
                            i++;
                        }
                        break;
                    }
                    case 28:
                    {
                        if(it2==0)
                        {
                            biList->InsertItem(i,_(""));
                            biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                            biList->SetItem(i,2,_("缺少盾尾间隙测量数据"));
                            biList->SetItemBackgroundColour(i,wxColor(255,255,0));
                            i++;
                        }
                        break;
                    }
                    case 29:
                    {
                        biList->InsertItem(i,_(""));
                        biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        biList->SetItem(i,2,_("全站仪连接失败，请检查!"));
                        biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                        biList->SetItemTextColour(i,wxColor(255,255,255));
                        i++;
                        break;
                    }
                    case 30:
                    {
                        biList->InsertItem(i,_(""));
                        biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        biList->SetItem(i,2,_("激光屏初始化失败，请检查!"));
                        biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                        biList->SetItemTextColour(i,wxColor(255,255,255));
                        i++;
                        break;
                    }
                    case 31:
                    {
                        biList->InsertItem(i,_(""));
                        biList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        biList->SetItem(i,2,_("姿态仪初始化失败，请检查!"));
                        biList->SetItemBackgroundColour(i,wxColor(255,0,0));
                        biList->SetItemTextColour(i,wxColor(255,255,255));
                        i++;
                        break;
                    }
                    default:
                        break;
                }
                memset(str,0,300);
            }
            fclose(fp);
        }
    }
    else if(page==1)
    {
        FILE* fp=fopen(mtg->pmain,"r");
        if(fp)
        {
            rewind(fp);
            char str[300];
            int it1;
            int i=0;
            mainList->DeleteAllItems();
            wxString istr=wxEmptyString;
            double ival[10]={0};
            int id[10]={0};
            while(!feof(fp))
            {
                it1=-1;
                fgets(str,300,fp);

                if(!sscanf(str,"%%R1P,%d",&it1))
                {
                    continue;
                }

                switch(it1)
                {
                    case 0:
                    {
                        sscanf(str,"%%R1P,%d,%d,%f,%f,%f",&it1,&id[0],&ival[0],&ival[1],&ival[2]);
                        mainList->InsertItem(i,_(""));
                        mainList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        if(id[0]==0) istr=_("激光类型:同轴激光,");
                        else if(id[0]==1) istr=_("激光类型:GUS74专用激光,");
                        istr=istr+wxString::Format(_("激光高度=%.4f m,"),ival[0])+wxString::Format(_("水平矫正=%.4f m,"),ival[1]);
                        istr=istr+wxString::Format(_("垂直矫正=%.4f m,"),ival[2]);
                        mainList->SetItem(i,2,istr);
                        i++;
                        break;
                    }
                    case 1:
                    {
                        sscanf(str,"%%R1P,%d,%f,%f",&it1,&ival[0],&ival[1]);
                        mainList->InsertItem(i,_(""));
                        mainList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxString::Format(_("激光屏:X=%.1f,Y=%.1f"),ival[0],ival[1]);
                        mainList->SetItem(i,2,istr);
                        i++;
                        break;
                    }
                    case 2:
                    {
                        sscanf(str,"%%R1P,%d,%d",&it1,&id[0]);
                        mainList->InsertItem(i,_(""));
                        mainList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxString::Format(_("激光屏类型:%d"),id[0]);
                        mainList->SetItem(i,2,istr);
                        i++;
                        break;
                    }
                    case 3:
                    {
                        sscanf(str,"%%R1P,%d,%f,%f",&it1,&ival[0],&ival[1]);
                        mainList->InsertItem(i,_(""));
                        mainList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxString::Format(_("转向后视:水平角=%.4f,竖直角=%.4f"),ival[0]*180.0/PI,ival[1]*180.0/PI);
                        mainList->SetItem(i,2,istr);
                        i++;
                        break;
                    }
                    case 4:
                    {
                        sscanf(str,"%%R1P,%d,%f,%f",&it1,&ival[0],&ival[1]);
                        mainList->InsertItem(i,_(""));
                        mainList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxString::Format(_("转向棱镜:水平角=%.4f,竖直角=%.4f"),ival[0]*180.0/PI,ival[1]*180.0/PI);
                        mainList->SetItem(i,2,istr);
                        i++;
                        break;
                    }
                    case 5:
                    {
                        sscanf(str,"%%R1P,%d,%f,%f,%f",&it1,&ival[0],&ival[1],&ival[2]);
                        mainList->InsertItem(i,_(""));
                        mainList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxString::Format(_("后视测量:平距差=%.4f m,横向偏差=%.4f m,,垂直偏差=%.4f m"),ival[0],ival[1],ival[2]);
                        mainList->SetItem(i,2,istr);
                        i++;
                        break;
                    }
                    case 6:
                    {
                        sscanf(str,"%%R1P,%d,%f,%f",&it1,&ival[0],&ival[1]);
                        mainList->InsertItem(i,_(""));
                        mainList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxString::Format(_("转向棱镜:水平角=%.4f,竖直角=%.4f"),ival[0]*180.0/PI,ival[1]*180.0/PI);
                        mainList->SetItem(i,2,istr);
                        i++;
                        break;
                    }
                    case 7:
                    {
                        sscanf(str,"%%R1P,%d,%f,%f,%f",&it1,&ival[0],&ival[1],&ival[2]);
                        mainList->InsertItem(i,_(""));
                        mainList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxString::Format(_("棱镜坐标:X=%.4f,Y=%.4f,Z=%.4f"),ival[0],ival[1],ival[2]);
                        mainList->SetItem(i,2,istr);
                        i++;
                        break;
                    }
                    case 8:
                    {
                        sscanf(str,"%%R1P,%d,%f,%f",&it1,&ival[0],&ival[1]);
                        mainList->InsertItem(i,_(""));
                        mainList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxString::Format(_("转向激光屏:水平角=%.4f,竖直角=%.4f"),ival[0]*180.0/PI,ival[1]*180.0/PI);
                        mainList->SetItem(i,2,istr);
                        i++;
                        break;
                    }
                    case 9:
                    {
                        sscanf(str,"%%R1P,%d,%f,%f",&it1,&ival[0],&ival[1]);
                        mainList->InsertItem(i,_(""));
                        mainList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxString::Format(_("激光参数:水平角=%.4f,竖直角=%.4f"),ival[0]*180.0/PI,ival[1]*180.0/PI);
                        mainList->SetItem(i,2,istr);
                        i++;
                        break;
                    }
                    default:
                        break;
                }
                memset(str,0,300);

                if(i==0)
                {
                    mainList->InsertItem(i,_(""));
                    mainList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                    istr=_("无主过程信息!");
                    mainList->SetItem(i,2,istr);
                }
            }
            fclose(fp);
        }
        else
        {
            mainList->InsertItem(0,_(""));
            mainList->SetItem(0,1,wxString::Format(_("%d"),1));
            mainList->SetItem(0,2,_("无主过程信息!"));
        }
    }
    else if(page==2)
    {
        FILE* fp=fopen(mtg->popi,"r");
        if(fp)
        {
            rewind(fp);
            char str[300];
            wxString istr;
            int it1;
            int i=0;
            long t1;
            time_t t2;
            int op;
            opList->DeleteAllItems();
            while(!feof(fp))
            {
                fgets(str,300,fp);
                if(!sscanf(str,"%%R1P,%d,%ld",&it1,&t1))
                {
                    continue;
                }
                t2=t1;
                //wxMessageBox(wxString::Format(_("%ld"),(long)t1));
                switch(it1)
                {
                    case 0:
                    {
                        opList->InsertItem(i,_(""));
                        opList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxDateTime(t2).Format(_("%Y-%m-%d %H:%M:%S"));
                        opList->SetItem(i,2,istr);
                        opList->SetItem(i,3,_("系统启动"));
                        i++;
                        break;
                    }
                    case 1:
                    {
                        opList->InsertItem(i,_(""));
                        opList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxDateTime(t2).Format(_("%Y-%m-%d %H:%M:%S"));
                        opList->SetItem(i,2,istr);
                        opList->SetItem(i,3,_("系统退出"));
                        i++;
                        break;
                    }
                    case 2:
                    {
                        opList->InsertItem(i,_(""));
                        opList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxDateTime(t2).Format(_("%Y-%m-%d %H:%M:%S"));
                        opList->SetItem(i,2,istr);
                        opList->SetItem(i,3,_("启动周期测量"));
                        i++;
                        break;
                    }
                    case 3:
                    {
                        opList->InsertItem(i,_(""));
                        opList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxDateTime(t2).Format(_("%Y-%m-%d %H:%M:%S"));
                        opList->SetItem(i,2,istr);
                        opList->SetItem(i,3,_("终止周期测量"));
                        i++;
                        break;
                    }
                    case 4:
                    {
                        opList->InsertItem(i,_(""));
                        opList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxDateTime(t2).Format(_("%Y-%m-%d %H:%M:%S"));
                        opList->SetItem(i,2,istr);
                        opList->SetItem(i,3,_("管环选型"));
                        i++;
                        break;
                    }
                    case 12:
                    {
                        sscanf(str,"%%R1P,%d,%ld,%d",&it1,&t1,&op);
                        opList->InsertItem(i,_(""));
                        opList->SetItem(i,1,wxString::Format(_("%d"),i+1));
                        istr=wxDateTime(t2).Format(_("%Y-%m-%d %H:%M:%S"));
                        opList->SetItem(i,2,istr);
                        istr=wxString(mtg->user[op].name,wxConvUTF8);
                        istr=istr+_("  系统设置");
                        opList->SetItem(i,3,istr);
                        i++;
                        break;
                    }
                    default:
                        break;
                }
                memset(str,0,300);
            }
        }
    }
}

void MydoctorDlg::OnPaintBottom(wxPaintEvent& event)
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
        w1=65;
        x1=w-w1-14;
        y1=9;
        h1=28;
        docButton[ID_DOC_BTN_QUIT].x=x1;
        docButton[ID_DOC_BTN_QUIT].y=y1;
        docButton[ID_DOC_BTN_QUIT].width=w1;
        docButton[ID_DOC_BTN_QUIT].height=h1;
        if(motion==ID_DOC_BTN_QUIT)
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

        x1=x1-w1-7;
        docButton[ID_DOC_BTN_EXP].x=x1;
        docButton[ID_DOC_BTN_EXP].y=y1;
        docButton[ID_DOC_BTN_EXP].width=w1;
        docButton[ID_DOC_BTN_EXP].height=h1;
        if(motion==ID_DOC_BTN_EXP)
        {
            memDC.SetPen(ipen[1]);
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("导出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=9;
        y1=9;
        h1=26;
        w1=h1*4/3;

        docButton[ID_DOC_PRT_SCN].x=x1;
        docButton[ID_DOC_PRT_SCN].y=y1;
        docButton[ID_DOC_PRT_SCN].width=w1;
        docButton[ID_DOC_PRT_SCN].height=h1;
        if(motion==ID_DOC_PRT_SCN)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
        }
        int x2,y2,w2,h2;
        h2=h1-6;
        w2=h1;
        x2=x1+w1/2-w2/2;
        y2=y1+3;
        memDC.SetPen(wxPen(wxColor(168,181,178)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x2,y2,w2,h2-2);
        memDC.SetPen(wxPen(wxColor(47,139,205)));
        memDC.SetBrush(wxBrush(wxColor(47,139,205)));
        memDC.DrawRectangle(x2+3,y2+4,w2-6,h2-11);

        memDC.SetPen(wxPen(wxColor(168,181,178)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(x2+w2/4-1,y2+h2-3,w2/2,4);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>docButton[ID_DOC_BTN_QUIT].y && y<docButton[ID_DOC_BTN_QUIT].y+docButton[ID_DOC_BTN_QUIT].height)
    {
        if(x>docButton[ID_DOC_BTN_QUIT].x && x<docButton[ID_DOC_BTN_QUIT].x+docButton[ID_DOC_BTN_QUIT].width)
        {
            motion=ID_DOC_BTN_QUIT;
        }
        else if(x>docButton[ID_DOC_BTN_EXP].x && x<docButton[ID_DOC_BTN_EXP].x+docButton[ID_DOC_BTN_EXP].width)
        {
            motion=ID_DOC_BTN_EXP;
        }
        else if(x>docButton[ID_DOC_PRT_SCN].x && x<docButton[ID_DOC_PRT_SCN].x+docButton[ID_DOC_PRT_SCN].width)
        {
            motion=ID_DOC_PRT_SCN;
        }
        else
        {
            motion=ID_DOC_NONE;
        }
    }
    else
    {
        motion=ID_DOC_NONE;
    }
    panelBottom->Refresh();
}

void MydoctorDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_DOC_NONE;
    panelBottom->Refresh();
}

void MydoctorDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_DOC_BTN_QUIT)
    {
        Destroy();
    }
    else if(motion==ID_DOC_BTN_EXP)
    {
        /*if(page==ID_RNG_PAGE_DONE)
        {
            if(nseged<=0) return;
            wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
            if(fileDlg.ShowModal()==wxID_OK)
            {
                wxString strFile=fileDlg.GetPath();
                FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
                if(fp)
                {
                    fprintf(fp,wxString(_("环号,里程K（m）,类型,K点,管环中心（系统）,,,管环中心（实测）,,,偏差（导向）,,偏差（实测）,,较差,,备注\n")).mb_str(wxConvLocal));
                    fprintf(fp,wxString(_(",,,,X,Y,Z,X,Y,Z,横向（mm）,竖向（mm）,横向（mm）,竖向（mm）,横向（mm）,竖向（mm）,\n")).mb_str(wxConvLocal));
                    for(int i=0;i<nseged;i++)
                    {
                        fprintf(fp,"%d,",seged[i].numb);
                        fprintf(fp,"%.4f,",seged[i].mile);
                        if(seged[i].type==0) fprintf(fp,"通用环,");
                        else if(seged[i].type==1) fprintf(fp,"标准环,");
                        else if(seged[i].type==2) fprintf(fp,"左转弯,");
                        else if(seged[i].type==3) fprintf(fp,"右转弯,");
                        if(mtg->segset.Ks<12)
                        {
                            if(seged[i].k<mtg->segset.Ks/2) fprintf(fp,"%d,",seged[i].k+1);
                            else fprintf(fp,"%d,",seged[i].k+2);
                        }
                        else
                        {
                            fprintf(fp,"%d,",seged[i].k+1);
                        }
                        fprintf(fp,"%.4f,",seged[i].x);
                        fprintf(fp,"%.4f,",seged[i].y);
                        fprintf(fp,"%.4f,",seged[i].z);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f,",seged[i].dh);
                        fprintf(fp,"%.4f,",seged[i].dv);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f,",0.0);
                        fprintf(fp,"%.4f\n",0.0);
                    }
                    fclose(fp);
                    wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
                }
            }
        }
        else if(page==ID_RNG_PAGE_CAL)
        {
            wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
            if(fileDlg.ShowModal()==wxID_OK)
            {
                wxString strFile=fileDlg.GetPath();
                FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
                if(fp)
                {
                    fprintf(fp,wxString(_("环号,里程K（m）,类型,K点,管环中心,,,偏差\n")).mb_str(wxConvLocal));
                    fprintf(fp,wxString(_(",,,,X,Y,Z,横向（mm）,竖向（mm）\n")).mb_str(wxConvLocal));
                    for(int i=0;i<MAX_SEG;i++)
                    {
                        fprintf(fp,"%d,",mtg->segs[i].numb);
                        fprintf(fp,"%.4f,",mtg->segs[i].mile);
                        if(mtg->segs[i].type==0) fprintf(fp,"通用环,");
                        else if(mtg->segs[i].type==1) fprintf(fp,"标准环,");
                        else if(mtg->segs[i].type==2) fprintf(fp,"左转弯,");
                        else if(mtg->segs[i].type==3) fprintf(fp,"右转弯,");
                        if(mtg->segset.Ks<12)
                        {
                            if(mtg->segs[i].k<mtg->segset.Ks/2) fprintf(fp,"%d,",mtg->segs[i].k+1);
                            else fprintf(fp,"%d,",mtg->segs[i].k+2);
                        }
                        else
                        {
                            fprintf(fp,"%d,",mtg->segs[i].k+1);
                        }
                        fprintf(fp,"%.4f,",mtg->segs[i].x);
                        fprintf(fp,"%.4f,",mtg->segs[i].y);
                        fprintf(fp,"%.4f,",mtg->segs[i].z);
                        fprintf(fp,"%.4f,",mtg->segs[i].dh);
                        fprintf(fp,"%.4f\n",mtg->segs[i].dv);
                    }
                    fclose(fp);
                    wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
                }
            }
        }
        else if(page==ID_RNG_PAGE_DES)
        {
            if(nres<=0) return;
            wxFileDialog fileDlg(this,_("导出"),wxEmptyString,wxEmptyString,_("CSV文件(*.csv)|*.csv"),wxFD_SAVE);
            if(fileDlg.ShowModal()==wxID_OK)
            {
                wxString strFile=fileDlg.GetPath();
                FILE* fp=fopen(strFile.mb_str(wxConvLocal),"w");
                if(fp)
                {
                    fprintf(fp,wxString(_("环号,里程K（m）,类型,K点,管环中心,,,偏差\n")).mb_str(wxConvLocal));
                    fprintf(fp,wxString(_(",,,,X,Y,Z,横向（mm）,竖向（mm）\n")).mb_str(wxConvLocal));
                    for(int i=0;i<nres;i++)
                    {
                        fprintf(fp,"%d,",res[i].numb);
                        fprintf(fp,"%.4f,",res[i].headc);
                        if(res[i].type==0) fprintf(fp,"通用环,");
                        else if(res[i].type==1) fprintf(fp,"标准环,");
                        else if(res[i].type==2) fprintf(fp,"左转弯,");
                        else if(res[i].type==3) fprintf(fp,"右转弯,");
                        if(mtg->segset.Ks<12)
                        {
                            if(res[i].k<mtg->segset.Ks/2) fprintf(fp,"%d,",res[i].k+1);
                            else fprintf(fp,"%d,",res[i].k+2);
                        }
                        else
                        {
                            fprintf(fp,"%d,",res[i].k+1);
                        }
                        fprintf(fp,"%.4f,",res[i].head[0]);
                        fprintf(fp,"%.4f,",res[i].head[1]);
                        fprintf(fp,"%.4f,",res[i].head[2]);
                        fprintf(fp,"%.4f,",res[i].headh);
                        fprintf(fp,"%.4f\n",res[i].headv);
                    }
                    fclose(fp);
                    wxMessageBox(_("报表已导出"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
                }
            }
        }*/
    }
    else if(motion==ID_DOC_PRT_SCN)
    {
        wxSize screenSize = GetSize();
        wxBitmap bitmap(screenSize.x, screenSize.y);
        wxScreenDC dc;
        wxMemoryDC memDC;
        memDC.SelectObject(bitmap);

        memDC.Blit(0,0,screenSize.x,screenSize.y, &dc,GetPosition().x,GetPosition().y);
        memDC.SelectObject(wxNullBitmap);

        wxString str;
        time_t t;
        time(&t);
        //str=wxString(mtg->duty[i].name,wxConvLocal);
        str=_("选型界面");
        str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
        }
    }
}

void MydoctorDlg::OnPaintMain(wxPaintEvent& event)
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

void MydoctorDlg::OnPaintPage(wxPaintEvent& event)
{
    wxPaintDC dc(panelPage);
    int w,h;
    GetSize(&w,&h);
    double sx,sy,sxy;
	sx = w/1024.0;
	sy = h/768.0;
	if(sx>sy)
	{
		sxy = sy;
	}
	else
	{
		sxy = sx;
	}

    panelPage->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);

    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);

        memDC.SetBrush(wxBrush(wxColor(204,204,204)));
        memDC.DrawRectangle(0,10,w,h-10);
        memDC.SetBrush(wxBrush(wxColor(255,255,255),wxBDIAGONAL_HATCH));
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawRectangle(0,10,w,h-10);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);

        memDC.SetTextForeground(wxColor(71,71,71));
        memDC.SetFont(chs);
        int x,y,x2;
        int r,g,b;
        int btns=ID_DOC_COUNT-ID_DOC_PAGE_START;
        int btn_h=36.0*sy;
        for(int i=0;i<btns;i++)
        {
            y=11+i*btn_h;
            x=1;
            x2=w-1;
            docButton[ID_DOC_PAGE_START+i].x=x;
            docButton[ID_DOC_PAGE_START+i].y=y;
            docButton[ID_DOC_PAGE_START+i].width=w-2;
            docButton[ID_DOC_PAGE_START+i].height=btn_h;

            if(motion==ID_DOC_PAGE_START+i)
            {
                r=200;
                g=225;
                b=250;
                for(int j=0;j<btn_h-2;j++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*j/(btn_h-2),g+20*j/(btn_h-2),b)));
                    memDC.DrawLine(x,y,x2,y);
                    y++;
                }
            }
            else
            {
                r=236;
                g=236;
                b=236;
                for(int j=0;j<btn_h-2;j++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x,y,x2,y);
                    r--;
                    g--;
                    b--;
                    y++;
                }
            }
            memDC.SetPen(wxPen(wxColor(236,236,236)));
            memDC.DrawLine(x,y,x2,y);
            memDC.SetPen(wxPen(wxColor(104,104,104)));
            memDC.DrawLine(x,y+1,x2,y+1);
            if(page==i)
            {
                memDC.DrawLabel(_("◆ ")+docLabel[i],wxRect(10,y-btn_h+2,w-20,btn_h-1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.DrawLabel(_("◇ ")+docLabel[i],wxRect(10,y-btn_h+2,w-20,btn_h-1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            //memDC.DrawLabel(btn_label[i],wxRect(x+w/10,y-btn_height+2,w*9/10,btn_height-1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MydoctorDlg::OnMotionPage(wxMouseEvent& event)
{
    int x,y;
    int w,h;
    x=event.GetX();
    y=event.GetY();
    panelPage->GetClientSize(&w,&h);
    int btns=ID_DOC_COUNT-ID_DOC_PAGE_START;
    for(int i=0;i<btns;i++)
    {
        if(x>docButton[ID_DOC_PAGE_START+i].x && x<docButton[ID_DOC_PAGE_START+i].x+docButton[ID_DOC_PAGE_START+i].width)
        {
            if(y>docButton[ID_DOC_PAGE_START+i].y && y<docButton[ID_DOC_PAGE_START+i].y+docButton[ID_DOC_PAGE_START+i].height)
            {
                motion=ID_DOC_PAGE_START+i;
                break;
            }
            else if(i==btns-1)
            {
                motion=ID_DOC_NONE;
                break;
            }
            else
            {
                continue;
            }
        }
        else
        {
            motion=ID_DOC_NONE;
        }
    }
    //btn_left_down=-1;
    panelPage->Refresh();
}

void MydoctorDlg::OnLeavePage(wxMouseEvent& event)
{
    motion=ID_DOC_NONE;
    panelPage->Refresh();
}

void MydoctorDlg::OnClickPage(wxMouseEvent& event)
{
    if(motion==ID_DOC_PAGE_START)
    {
        page=0;
        LoadMessage();
        biList->Show(true);
        mainList->Show(false);
        opList->Show(false);
        panelLaser->Show(false);
    }
    else if(motion==ID_DOC_PAGE_MAIN)
    {
        page=1;
        LoadMessage();
        biList->Show(false);
        mainList->Show(true);
        opList->Show(false);
        panelLaser->Show(false);
    }
    else if(motion==ID_DOC_PAGE_OP)
    {
        page=2;
        LoadMessage();
        biList->Show(false);
        mainList->Show(false);
        opList->Show(true);
        panelLaser->Show(false);
    }
    else if(motion==ID_DOC_PAGE_LASER)
    {
        page=3;
        LoadMessage();
        biList->Show(false);
        mainList->Show(false);
        opList->Show(false);
        panelLaser->Show(true);
    }
    panelPage->Refresh();
}
