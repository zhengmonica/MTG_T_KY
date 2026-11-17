///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MapViewDlg.h"
#include "MapSettingDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#include "dl_dxf.h"

#include "mtg_t_svrApp.h"
#include "mtg_t_svrMain.h"


#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MapViewDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MapViewDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MapViewDlg)

//*)
const long MapViewDlg::ID_canvas=wxNewId();

MapViewDlg::MapViewDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

    panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPage = new wxPanel(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    x1=0;
    y1=49;
    w1=w;
    h1=h-95;
    hmapPanel=new DxfCanvas(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    hmapPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    vmapPanel=new DxfCanvas(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    vmapPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapViewDlg::OnPaintMain,0,this);
    panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapViewDlg::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MapViewDlg::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapViewDlg::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapViewDlg::OnClickPage,0,this);

    hmapPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MapViewDlg::OnMotionHmap,0,this);
    hmapPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapViewDlg::OnLeaveHmap,0,this);
    hmapPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapViewDlg::OnClickHmap,0,this);

    vmapPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MapViewDlg::OnMotionVmap,0,this);
    vmapPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapViewDlg::OnLeaveVmap,0,this);
    vmapPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapViewDlg::OnClickVmap,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapViewDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MapViewDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapViewDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapViewDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));



    //cross_cursor=wxCursor(wxCURSOR_CROSS);
    //stand_cursor=wxCursor(wxCURSOR_ARROW);
    OnUse=0;
    motion=ID_MAP_NONE;
    page=ID_MAP_PAGE_HORIZON;
    LoadData();
}

MapViewDlg::~MapViewDlg()
{

    mapDlg=0;
}

void MapViewDlg::OnMotionHmap(wxMouseEvent& event)
{
    motion=ID_MAP_HMAP;
    //hmapPanel->Refresh();
    event.Skip();
}

void MapViewDlg::OnLeaveHmap(wxMouseEvent& event)
{
    motion=ID_MAP_NONE;
    //hmapPanel->Refresh();
    event.Skip();
}

void MapViewDlg::OnClickHmap(wxMouseEvent& event)
{
    event.Skip();
    hmapPanel->Refresh();
}

void MapViewDlg::OnMotionVmap(wxMouseEvent& event)
{
    motion=ID_MAP_VMAP;
    //vmapPanel->Refresh();
    event.Skip();
}

void MapViewDlg::OnLeaveVmap(wxMouseEvent& event)
{
    motion=ID_MAP_NONE;
    //vmapPanel->Refresh();
    event.Skip();
}

void MapViewDlg::OnClickVmap(wxMouseEvent& event)
{
    event.Skip();
    vmapPanel->Refresh();
}

void MapViewDlg::OnPaintBottom(wxPaintEvent& event)
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
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x1,y1,w1,h1;
        int w2,h2;
        memDC.SetPen(wxPen(wxColor(117,117,117)));

        y1=9;
        w1=48;
        h1=28;
        x1=w/2-w1*3/2;

        mapButton[ID_MAP_ZOOM_OUT].x=x1+1;
        mapButton[ID_MAP_ZOOM_OUT].y=y1+1;
        mapButton[ID_MAP_ZOOM_OUT].width=w1-1;
        mapButton[ID_MAP_ZOOM_OUT].height=h1-2;

        mapButton[ID_MAP_ZOOM_PAM].x=x1+w1+1;
        mapButton[ID_MAP_ZOOM_PAM].y=y1+1;
        mapButton[ID_MAP_ZOOM_PAM].width=w1-1;
        mapButton[ID_MAP_ZOOM_PAM].height=h1-2;

        mapButton[ID_MAP_ZOOM_IN].x=x1+w1*2+1;
        mapButton[ID_MAP_ZOOM_IN].y=y1+1;
        mapButton[ID_MAP_ZOOM_IN].width=w1-2;
        mapButton[ID_MAP_ZOOM_IN].height=h1-2;

        memDC.DrawRectangle(x1,y1,w1*3,h1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLine(x1+w1*2,y1,x1+w1*2,y1+h1);

        if(/*zoom==ID_MAP_ZOOM_OUT || */motion==ID_MAP_ZOOM_OUT)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(mapButton[ID_MAP_ZOOM_OUT]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(ibrush[0].GetColour())));
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }

        memDC.DrawLabel(_("+"),mapButton[ID_MAP_ZOOM_OUT],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        int x2,y2;
        x2=mapButton[ID_MAP_ZOOM_PAM].x;
        y2=mapButton[ID_MAP_ZOOM_PAM].y;
        w2=mapButton[ID_MAP_ZOOM_PAM].width;
        h2=mapButton[ID_MAP_ZOOM_PAM].height;
        if(motion==ID_MAP_ZOOM_PAM)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(mapButton[ID_MAP_ZOOM_PAM]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(ibrush[0].GetColour())));
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawLabel(_("口"),mapButton[ID_MAP_ZOOM_PAM],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        if(/*zoom==ID_MAP_ZOOM_IN || */motion==ID_MAP_ZOOM_IN)
        {
            memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
            memDC.SetBrush(ibrush[1]);
            memDC.SetTextForeground(icolor[1]);
            memDC.DrawRectangle(mapButton[ID_MAP_ZOOM_IN]);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(ibrush[0].GetColour())));
            memDC.SetBrush(ibrush[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawLabel(_("-"),mapButton[ID_MAP_ZOOM_IN],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=9;
        y1=9;
        h1=26;
        w1=h1*4/3;

        mapButton[ID_MAP_PRT_SCN].x=x1;
        mapButton[ID_MAP_PRT_SCN].y=y1;
        mapButton[ID_MAP_PRT_SCN].width=w1;
        mapButton[ID_MAP_PRT_SCN].height=h1;
        if(motion==ID_MAP_PRT_SCN)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
        }
        //int x2,y2;
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

        x1=x1+w1+7;
        y1=mapButton[ID_MAP_ZOOM_PAM].y;
        w1=65;
        h1=mapButton[ID_MAP_ZOOM_PAM].height;
        mapButton[ID_MAP_FILE].x=x1;
        mapButton[ID_MAP_FILE].y=y1;
        mapButton[ID_MAP_FILE].width=w1;
        mapButton[ID_MAP_FILE].height=h1;
        if(motion==ID_MAP_FILE)
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
        memDC.DrawLabel(_("文件..."),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+7;
        mapButton[ID_MAP_SET].x=x1;
        mapButton[ID_MAP_SET].y=y1;
        mapButton[ID_MAP_SET].width=w1;
        mapButton[ID_MAP_SET].height=h1;
        if(motion==ID_MAP_SET)
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
        memDC.DrawLabel(_("设置"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=w-w1-12;
        mapButton[ID_MAP_QUIT].x=x1;
        mapButton[ID_MAP_QUIT].y=y1;
        mapButton[ID_MAP_QUIT].width=w1;
        mapButton[ID_MAP_QUIT].height=h1;
        if(motion==ID_MAP_QUIT)
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

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MapViewDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>mapButton[ID_MAP_QUIT].y && y<mapButton[ID_MAP_QUIT].y+mapButton[ID_MAP_QUIT].height)
    {
        if(x>mapButton[ID_MAP_QUIT].x && x<mapButton[ID_MAP_QUIT].x+mapButton[ID_MAP_QUIT].width)
        {
            motion=ID_MAP_QUIT;
        }
        else if(x>mapButton[ID_MAP_ZOOM_IN].x && x<mapButton[ID_MAP_ZOOM_IN].x+mapButton[ID_MAP_ZOOM_IN].width)
        {
            motion=ID_MAP_ZOOM_IN;
        }
        else if(x>mapButton[ID_MAP_ZOOM_OUT].x && x<mapButton[ID_MAP_ZOOM_OUT].x+mapButton[ID_MAP_ZOOM_OUT].width)
        {
            motion=ID_MAP_ZOOM_OUT;
        }
        else if(x>mapButton[ID_MAP_ZOOM_PAM].x && x<mapButton[ID_MAP_ZOOM_PAM].x+mapButton[ID_MAP_ZOOM_PAM].width)
        {
            motion=ID_MAP_ZOOM_PAM;
        }
        else if(x>mapButton[ID_MAP_PRT_SCN].x && x<mapButton[ID_MAP_PRT_SCN].x+mapButton[ID_MAP_PRT_SCN].width)
        {
            motion=ID_MAP_PRT_SCN;
        }
        else if(x>mapButton[ID_MAP_FILE].x && x<mapButton[ID_MAP_FILE].x+mapButton[ID_MAP_FILE].width)
        {
            motion=ID_MAP_FILE;
        }
        else if(x>mapButton[ID_MAP_SET].x && x<mapButton[ID_MAP_SET].x+mapButton[ID_MAP_SET].width)
        {
            motion=ID_MAP_SET;
        }
        else
        {
            motion=ID_MAP_NONE;
        }
    }
    else
    {
        motion=ID_MAP_NONE;
    }
    panelBottom->Refresh();
}

void MapViewDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_MAP_NONE;
    panelBottom->Refresh();
}

void MapViewDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_MAP_QUIT)
    {
        Show(false);
        OnUse=0;
        //mapDlg=0;
    }
    else
    {
        if(motion==ID_MAP_PRT_SCN)
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
            str=_("地质地物");
            str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
            wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
            if(dlg.ShowModal()==wxID_OK)
            {
                str=dlg.GetPath();
                bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
            }
        }
        else if(motion==ID_MAP_ZOOM_IN)
        {
            /*if(zoom==ID_MAP_ZOOM_IN)
            {
                zoom=ID_MAP_NONE;
            }
            else*/
            {
                zoom=ID_MAP_ZOOM_IN;
                wxMouseEvent evt(wxEVT_MOUSEWHEEL);
                int w,h;
                if(page==ID_MAP_PAGE_HORIZON)
                {
                    hmapPanel->GetClientSize(&w,&h);
                    hmapPanel->eventDet=-1;
                    wxPostEvent(hmapPanel,evt);
                }
                else
                {
                    vmapPanel->GetClientSize(&w,&h);
                    vmapPanel->eventDet=-1;
                    wxPostEvent(vmapPanel,evt);
                }
            }
        }
        else if(motion==ID_MAP_ZOOM_OUT)
        {
            /*if(zoom==ID_MAP_ZOOM_OUT)
            {
                zoom=ID_MAP_NONE;
            }
            else*/
            {
                zoom=ID_MAP_ZOOM_OUT;
                wxMouseEvent evt(wxEVT_MOUSEWHEEL);
                int w,h;
                if(page==ID_MAP_PAGE_HORIZON)
                {
                    hmapPanel->GetClientSize(&w,&h);
                    hmapPanel->eventDet=1;
                    wxPostEvent(hmapPanel,evt);
                }
                else
                {
                    vmapPanel->GetClientSize(&w,&h);
                    vmapPanel->eventDet=1;
                    wxPostEvent(vmapPanel,evt);
                }
            }
        }
        else if(motion==ID_MAP_ZOOM_PAM)
        {
            /*if(zoom==ID_MAP_ZOOM_PAM)
            {
                zoom=ID_MAP_NONE;
                UpdateGraph();
            }
            else*/
            {
                zoom=ID_MAP_ZOOM_PAM;
                if(page==ID_MAP_PAGE_HORIZON)
                {
                    UpdateGraph();
                    //hmapPanel->FitAll();
                }
                else if(page==ID_MAP_PAGE_VERTICAL)
                {
                    UpdateGraph();
                    //vmapPanel->FitAll();
                }
            }
        }
        else if(motion==ID_MAP_FILE && page==ID_MAP_PAGE_HORIZON)
        {
            wxFileDialog dlg(this,_("选择平面图文件"),wxEmptyString,wxEmptyString,_("平面图文件(*.DXF)|*.DXF"),wxFD_OPEN);
            dlg.Center();
            if(dlg.ShowModal()==wxID_OK)
            {
                wxString str=dlg.GetPath();
                string hstr=std::string(str.mb_str());

                wxStandardPaths wsp;
                wxString hstr2=wsp.GetDataDir()+wxString(_("\\data"));
                if(!wxFileName::FileExists(hstr2))
                {
                    wxMkDir(hstr2);
                }
                wxString hstr1=wsp.GetDataDir()+wxString(_("\\data\\Horizon.dxf"));
                if(str.compare(hstr1))
                {

                    if(wxFileName::FileExists(hstr1))
                    {
                        int rs1;
                        rs1=wxMessageBox(_("是否用该文件替换已存的文件？"),_("提示"),wxYES|wxNO);
                        if(rs1==wxYES)
                        {
                            wxCopyFile(str,hstr1,true);
                            int rs;
                            hmapPanel->Clear();
                            rs=hmapPanel->filein(hstr);
                        }
                    }
                    else
                    {
                        wxCopyFile(str,hstr1,true);
                        int rs;
                        rs=hmapPanel->filein(hstr);
                    }
                }
            }
        }
        else if(motion==ID_MAP_FILE && page==ID_MAP_PAGE_VERTICAL)
        {
            wxFileDialog dlg(this,_("选择地质图文件"),wxEmptyString,wxEmptyString,_("纵断面图文件(*.DXF)|*.DXF"),wxFD_OPEN);
            dlg.Center();
            if(dlg.ShowModal()==wxID_OK)
            {
                wxString str=dlg.GetPath();
                string vstr=std::string(str.mb_str());

                wxStandardPaths wsp;
                wxString vstr2=wsp.GetDataDir()+wxString(_("\\data"));
                if(!wxFileName::FileExists(vstr2))
                {
                    wxMkDir(vstr2);
                }
                wxString vstr1=wsp.GetDataDir()+wxString(_("\\data\\Vertical.dxf"));
                if(str.compare(vstr1))
                {

                    if(wxFileName::FileExists(vstr1))
                    {
                        int rs1;
                        rs1=wxMessageBox(_("是否用该文件替换已存的文件？"),_("提示"),wxYES|wxNO);
                        if(rs1==wxYES)
                        {
                            wxCopyFile(str,vstr1,true);
                            int rs;
                            vmapPanel->Clear();
                            rs=vmapPanel->filein(vstr);
                        }
                    }
                    else
                    {
                        wxCopyFile(str,vstr1,true);
                        int rs;
                        rs=vmapPanel->filein(vstr);
                    }
                }
            }
        }
        else if(motion==ID_MAP_SET && page==ID_MAP_PAGE_HORIZON)
        {
            MapSettingDlg dlg(this);
            dlg.MAP_TYPE=0;
            dlg.LoadData();
            dlg.Center();
            if(dlg.ShowModal()==wxID_OK)
            {
                ReLoadData();
            }
        }
        else if(motion==ID_MAP_SET && page==ID_MAP_PAGE_VERTICAL)
        {
            MapSettingDlg dlg(this);
            dlg.MAP_TYPE=1;
            dlg.LoadData();
            dlg.Center();
            if(dlg.ShowModal()==wxID_OK)
            {
                ReLoadData();
            }
        }
        hmapPanel->EventFlag=zoom;
        panelBottom->Refresh();
        hmapPanel->UpdateView();
    }
}

void MapViewDlg::LoadData()
{
    //wxMessageBox(_("ok"));
    wxStandardPaths wsp;
    wxString hstr=wsp.GetDataDir()+wxString(_("\\data\\Horizon.dxf"));
    wxString vstr=wsp.GetDataDir()+wxString(_("\\data\\Vertical.dxf"));
    string hstr1=std::string(hstr.mb_str());
    string vstr1=std::string(vstr.mb_str());
    int rsh,rsv;
    if(wxFileExists(hstr))
        rsh=hmapPanel->filein(hstr1);
    if(wxFileExists(vstr))
        rsv=vmapPanel->filein(vstr1);

    memset(&shield,0,sizeof(DxfMyShield));

    hx10=hx1=hy10=hy1=hx20=hx2=hy20=hy2=0;
    vx10=vx1=vy10=vy1=vx20=vx2=vy20=vy2=0;
    wxString str_conf=wsp.GetDataDir()+wxString(_("\\plugins\\h_conf.ini"));
    char ch_conf[1024];
    strcpy(ch_conf,str_conf.mb_str(wxConvLocal));
    FILE* fp=fopen(ch_conf,"r");
    char buf[1024];
    char* ret=NULL;
    if(fp)
    {
        ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf,%lf,%lf,%lf",&hx10,&hy10,&hx1,&hy1);
		ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf,%lf,%lf,%lf",&hx20,&hy20,&hx2,&hy2);
		ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf",&hs1);
		fclose(fp);
    }

    //free(fp);
    str_conf=wsp.GetDataDir()+wxString(_("\\plugins\\v_conf.ini"));
    strcpy(ch_conf,str_conf.mb_str(wxConvLocal));
    fp=fopen(ch_conf,"r");
    if(fp)
    {
        ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf,%lf,%lf,%lf",&vx10,&vy10,&vx1,&vy1);
		ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf,%lf,%lf,%lf",&vx20,&vy20,&vx2,&vy2);
		ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf",&vs1);
		fclose(fp);
    }

    hmapPanel->Show(true);
    vmapPanel->Show(false);
    UpdateGraph();
    //ready=1;
}

void MapViewDlg::ReLoadData()
{
    //wxMessageBox(_("ok"));
    wxStandardPaths wsp;

    hx10=hx1=hy10=hy1=hx20=hx2=hy20=hy2=0;
    vx10=vx1=vy10=vy1=vx20=vx2=vy20=vy2=0;
    wxString str_conf=wsp.GetDataDir()+wxString(_("\\plugins\\h_conf.ini"));
    char ch_conf[1024];
    strcpy(ch_conf,str_conf.mb_str(wxConvLocal));
    FILE* fp=fopen(ch_conf,"r");
    char buf[1024];
    char* ret=NULL;
    if(fp)
    {
        ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf,%lf,%lf,%lf",&hx10,&hy10,&hx1,&hy1);
		ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf,%lf,%lf,%lf",&hx20,&hy20,&hx2,&hy2);
		ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf",&hs1);
		fclose(fp);
    }

    //free(fp);
    str_conf=wsp.GetDataDir()+wxString(_("\\plugins\\v_conf.ini"));
    strcpy(ch_conf,str_conf.mb_str(wxConvLocal));
    fp=fopen(ch_conf,"r");
    if(fp)
    {
        ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf,%lf,%lf,%lf",&vx10,&vy10,&vx1,&vy1);
		ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf,%lf,%lf,%lf",&vx20,&vy20,&vx2,&vy2);
		ret=fgets(buf,1023,fp);
		sscanf(buf,"%lf",&vs1);
		fclose(fp);
    }

    //hmapPanel->Show(true);
    //vmapPanel->Show(false);
    UpdateGraph();
    //ready=1;
}

void MapViewDlg::OnPaintMain(wxPaintEvent& event)
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


        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(-1,38,w+2,10);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,48,w,48);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(-1,49,w+2,h-49);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MapViewDlg::OnPaintPage(wxPaintEvent& event)
{
    wxPaintDC dc(panelPage);
    int w,h;
    panelPage->GetSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        int r,g,b;
        x1=0;
        y1=0;
        w1=95;
        h1=h;
        mapButton[ID_MAP_PAGE_HORIZON].x=x1;
        mapButton[ID_MAP_PAGE_HORIZON].y=y1;
        mapButton[ID_MAP_PAGE_HORIZON].width=w1;
        mapButton[ID_MAP_PAGE_HORIZON].height=h1;

        if(page==ID_MAP_PAGE_HORIZON || motion==ID_MAP_PAGE_HORIZON)
        {
            r=200;
            g=225;
            b=250;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                //y1++;
            }

            if(page!=ID_MAP_PAGE_HORIZON)
            {
                memDC.SetPen(wxPen(wxColor(172,168,153)));
                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
            }
        }
        else
        {
            r=236;
            g=236;
            b=236;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                r--;
                g--;
                b--;
            }
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
        }
        memDC.DrawLabel(_("平面图"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);

        x1=x1+w1;
        mapButton[ID_MAP_PAGE_VERTICAL].x=x1;
        mapButton[ID_MAP_PAGE_VERTICAL].y=y1;
        mapButton[ID_MAP_PAGE_VERTICAL].width=w1;
        mapButton[ID_MAP_PAGE_VERTICAL].height=h1;
        if(page==ID_MAP_PAGE_VERTICAL || motion==ID_MAP_PAGE_VERTICAL)
        {
            r=200;
            g=225;
            b=250;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*j/(h1-2),g+20*j/(h1-2),b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                //y1++;
            }

            if(page!=ID_MAP_PAGE_VERTICAL)
            {
                memDC.SetPen(wxPen(wxColor(172,168,153)));
                memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
            }
        }
        else
        {
            r=236;
            g=236;
            b=236;
            for(int j=0;j<h1;j++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1,y1+j,x1+w1,y1+j);
                r--;
                g--;
                b--;
            }
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawLine(x1,y1+h1-1,x1+w1,y1+h1-1);
        }
        memDC.DrawLabel(_("地质图"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        r=236;
        g=236;
        b=236;
        x1=x1+w1;
        for(int j=0;j<h1;j++)
        {
            memDC.SetPen(wxPen(wxColor(r,g,b)));
            memDC.DrawLine(x1,y1+j,w,y1+j);
            r--;
            g--;
            b--;
        }
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,w,y1);
        memDC.DrawLine(x1,y1+h1-1,w,y1+h1-1);
        memDC.DrawLine(x1,y1,x1,y1+h1);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MapViewDlg::OnMotionPage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>mapButton[ID_MAP_PAGE_HORIZON].y && y<mapButton[ID_MAP_PAGE_HORIZON].y+mapButton[ID_MAP_PAGE_HORIZON].height)
    {
        if(x>mapButton[ID_MAP_PAGE_HORIZON].x && x<mapButton[ID_MAP_PAGE_HORIZON].x+mapButton[ID_MAP_PAGE_HORIZON].width)
        {
            motion=ID_MAP_PAGE_HORIZON;
        }
        else if(x>mapButton[ID_MAP_PAGE_VERTICAL].x && x<mapButton[ID_MAP_PAGE_VERTICAL].x+mapButton[ID_MAP_PAGE_VERTICAL].width)
        {
            motion=ID_MAP_PAGE_VERTICAL;
        }
        else
        {
            motion=ID_MAP_NONE;
        }
    }
    else
    {
        motion=ID_MAP_NONE;
    }
    panelPage->Refresh();
}

void MapViewDlg::OnLeavePage(wxMouseEvent& event)
{
    motion=ID_MAP_NONE;
    panelPage->Refresh();
}

void MapViewDlg::OnClickPage(wxMouseEvent& event)
{
    if(motion==ID_MAP_PAGE_HORIZON)
    {
        page=ID_MAP_PAGE_HORIZON;
        hmapPanel->Show(true);
        vmapPanel->Show(false);
    }
    else if(motion==ID_MAP_PAGE_VERTICAL)
    {
        page=ID_MAP_PAGE_VERTICAL;
        hmapPanel->Show(false);
        vmapPanel->Show(true);
    }
}

void MapViewDlg::UpdateGraph()
{
    double azi=0.0;
    double head[3],tail[3],mid[3];

    double hsx,hsy,vsx,vsy,hx0,hy0;
    double hdx,hdy,vdx,vdy,vx0,vy0;
    hdx=sqrt((hx10-hx20)*(hx10-hx20));
    hdy=sqrt((hy10-hy20)*(hy10-hy20));
    if(hdx<=0)
    {
        hsx=1;
        hx0=0;
    }
    else
    {
        hsx=(hx20-hx10)*1.0/(hx2-hx1);
        //hx0=hx10;
    }
    if(hdy<=0)
    {
        hsy=1;
        hy0=0;
    }
    else
    {
        hsy=(hy20-hy10)*1.0/(hy2-hy1);
        //hy0=hy10;
    }

    vdx=sqrt((vx10-vx20)*(vx10-vx20));
    vdy=sqrt((vy10-vy20)*(vy10-vy20));
    if(vdx<=0)
    {
        vsx=1;
        vx0=0;
    }
    else
    {
        vsx=(vx20-vx10)*1.0/(vx2-vx1);
        //vx0=vx10;
    }
    if(vdy<=0)
    {
        vsy=1;
        vy0=0;
    }
    else
    {
        vsy=(vy20-vy10)*1.0/(vy2-vy1);
        //vy0=vy10;
    }

    //if(page==ID_MAP_PAGE_HORIZON)
    {
        /*head[0]=mtg->m1.head[1];
        head[1]=mtg->m1.head[0];
        head[2]=mtg->m1.head[2];

        tail[0]=mtg->m1.tail[1];
        tail[1]=mtg->m1.tail[0];
        tail[2]=mtg->m1.tail[2];*/
        head[0]=mtg->m.head[1];
        head[1]=mtg->m.head[0];
        //head[2]=mtg->m1.head[2];

        tail[0]=mtg->m.tail[1];
        tail[1]=mtg->m.tail[0];
        //tail[2]=mtg->m1.tail[2];
        double l1,l2;
        road_xy2l(&mtg->r,mtg->m.head[0],mtg->m.head[1],&l1,&head[1],&head[0],0,0);
        road_xy2l(&mtg->r,mtg->m.tail[0],mtg->m.tail[1],&l2,&tail[1],&tail[0],0,0);

        //mid[0]=mtg->m1.mid[1];
        //mid[1]=mtg->m1.mid[0];
        //mid[2]=mtg->m1.mid[2];

        head[0]=(head[0]-hx1)*hsx+hx10;
        head[1]=(head[1]-hy1)*hsy+hy10;

        tail[0]=(tail[0]-hx1)*hsx+hx10;
        tail[1]=(tail[1]-hy1)*hsy+hy10;

        //mid[0]=(mid[0]-hx1)*hsx+hx10;
        //mid[1]=(mid[1]-hy1)*hsy+hy10;

        //shield.type=mtg->tbm.type;
        shield.type=0;
        //if(mtg->tbm.type==0)
        {
            shield.length=sqrt((head[0]-tail[0])*(head[0]-tail[0])+
                               (head[1]-tail[1])*(head[1]-tail[1]));
            shield.head[0]=head[0];
            shield.head[1]=head[1];

            shield.tail[0]=tail[0];
            shield.tail[1]=tail[1];

            shield.ipx=head[0];
            shield.ipy=head[1];

            shield.innerradius=2.7*hs1;
            double x,y;

            azi=atan2(head[1]-tail[1],head[0]-tail[0]);
            if(azi<0)
                azi+=2*PI;
            //wxMessageBox(wxString::Format(_("%.4lf"),azi*180/3.1415926));
            shield.angle1=azi;
            x=shield.innerradius*cos(azi+PI/2.0)*hsx;
            y=shield.innerradius*sin(azi+PI/2.0)*hsy;
            shield.r1=sqrt(x*x+y*y);

            //shield.direction=1;
        }
        /*else
        {
            shield.type=1;
            //shield.d1=sqrt((mid[0]-tail[0])*(mid[0]-tail[0])+(mid[1]-tail[1])*(mid[1]-tail[1]));
            //shield.d2=sqrt((head[0]-mid[0])*(head[0]-mid[0])+(head[1]-mid[1])*(head[1]-mid[1]));

            shield.length=sqrt((head[0]-tail[0])*(head[0]-tail[0])+
                               (head[1]-tail[1])*(head[1]-tail[1]));

            shield.head[0]=head[0];
            shield.head[1]=head[1];

            shield.tail[0]=tail[0];
            shield.tail[1]=tail[1];

            shield.mid[0]=mid[0];
            shield.mid[1]=mid[1];

            shield.ipx=tail[0];
            shield.ipy=tail[1];

            shield.innerradius=2.7;
            double x,y;

            azi=atan2(mid[1]-tail[1],mid[0]-tail[0]);
            if(azi<0)
                azi+=2*PI;
            shield.angle1=azi;

            x=shield.innerradius*cos(azi+PI/2.0)*hsx;
            y=shield.innerradius*sin(azi+PI/2.0)*hsy;
            shield.r1=sqrt(x*x+y*y);

            azi=atan2(head[1]-mid[1],head[0]-mid[0]);
            if(azi<0)
                azi+=2*PI;
            shield.angle2=azi;
            x=shield.innerradius*cos(azi+PI/2.0)*hsx;
            y=shield.innerradius*sin(azi+PI/2.0)*hsy;
            shield.r2=sqrt(x*x+y*y);
        }
        */
        hmapPanel->AddShield(shield);

        double d,r,x1,y1,x2,y2,l,x,y;
        l1=mtg->prj.mile1;
        l2=mtg->prj.mile2;
        d=mtg->segset.L;
        r=mtg->segset.De;
        if(l1<l2)
        {
            DxfMySeg seg;
            seg.innerradius=2.7;
            l=l1;
            while(l<mtg->m.tailc)
            {
                road_l2xy(&mtg->r,l,&y1,&x1,0);
                x1=(x1-hx1)*hsx+hx10;
                y1=(y1-hy1)*hsy+hy10;
                l+=d;
                road_l2xy(&mtg->r,l,&y2,&x2,0);
                x2=(x2-hx1)*hsx+hx10;
                y2=(y2-hy1)*hsy+hy10;
                seg.x1=x1;
                seg.y1=y1;
                seg.x2=x2;
                seg.y2=y2;
                azi=atan2(y2-y1,x2-x1);
                if(azi<0)
                    azi+=2*PI;
                seg.angle1=azi;
                x=seg.innerradius*cos(azi+PI/2.0)*hsx;
                y=seg.innerradius*sin(azi+PI/2.0)*hsy;
                seg.r1=sqrt(x*x+y*y);
                hmapPanel->AddSegment(seg);
            }
        }
        else if(l1>l2)
        {
            DxfMySeg seg;
            seg.innerradius=2.7;
            l=l2;
            while(l>mtg->m.tailc)
            {
                road_l2xy(&mtg->r,l,&x1,&y1,0);
                x1=(x1-hx1)*hsx+hx10;
                y1=(y1-hy1)*hsy+hy10;
                l+=-d;
                road_l2xy(&mtg->r,l,&x2,&y2,0);
                x2=(x2-hx1)*hsx+hx10;
                y2=(y2-hy1)*hsy+hy10;
                seg.x1=x1;
                seg.y1=y1;
                seg.x2=x2;
                seg.y2=y2;
                azi=atan2(y2-y1,x2-x1);
                if(azi<0)
                    azi+=2*PI;
                seg.angle1=azi;
                x=seg.innerradius*cos(azi+PI/2.0)*hsx;
                y=seg.innerradius*sin(azi+PI/2.0)*hsy;
                seg.r1=sqrt(x*x+y*y);
                hmapPanel->AddSegment(seg);
            }
        }
        hmapPanel->Fit((head[0]+tail[0])/2.0,(head[1]+tail[1])/2.0,4*shield.length,4*shield.length);
    }
    //if(page==ID_MAP_PAGE_VERTICAL)
    {
        head[0]=mtg->m.headc;
        head[1]=mtg->m.head[2];

        tail[0]=mtg->m.tailc;
        tail[1]=mtg->m.tail[2];

        double dx=tail[0]-head[0];
        double dy=tail[1]-head[1];
        tail[0]=head[0]+dx*vs1;
        tail[1]=head[1]+dy*vs1;

        road_l2h(&mtg->r,mtg->m.headc,&head[1],0);
        road_l2h(&mtg->r,mtg->m.tailc,&tail[1],0);

        //mid[0]=mtg->m1.midc;
        //mid[1]=mtg->m1.mid[2];

        head[0]=(head[0]-vx1)*vsx+vx10;
        head[1]=(head[1]-vy1)*vsy+vy10;

        tail[0]=(tail[0]-vx1)*vsx+vx10;
        tail[1]=(tail[1]-vy1)*vsy+vy10;

        //mid[0]=(mid[0]-vx1)*vsx+vx10;
        //mid[1]=(mid[1]-vy1)*vsy+vy10;

        //shield.type=mtg->tbm.type;
        shield.type=0;
        //if(mtg->tbm.type==0)
        {
            shield.length=sqrt((head[0]-tail[0])*(head[0]-tail[0])+
                               (head[1]-tail[1])*(head[1]-tail[1]));
            //shield.length=shield.length*vs1;
            shield.head[0]=head[0];
            shield.head[1]=head[1];

            shield.tail[0]=tail[0];
            shield.tail[1]=tail[1];

            shield.ipx=head[0];
            shield.ipy=head[1];

            shield.innerradius=2.7*vs1;

            double x,y;

            azi=atan2(head[1]-tail[1],head[0]-tail[0]);
            if(azi<0)
                azi+=2*PI;
            shield.angle1=azi;
            x=shield.innerradius*cos(azi+PI/2.0)*hsx;
            y=shield.innerradius*sin(azi+PI/2.0)*hsy;
            shield.r1=sqrt(x*x+y*y);

            //shield.direction=1;
        }
        /*else///主动铰接
        {
            shield.type=1;
            //shield.d1=sqrt((mid[0]-tail[0])*(mid[0]-tail[0])+(mid[1]-tail[1])*(mid[1]-tail[1]));
            //shield.d2=sqrt((head[0]-mid[0])*(head[0]-mid[0])+(head[1]-mid[1])*(head[1]-mid[1]));

            shield.length=sqrt((head[0]-tail[0])*(head[0]-tail[0])+
                               (head[1]-tail[1])*(head[1]-tail[1]));

            shield.head[0]=head[0];
            shield.head[1]=head[1];

            shield.tail[0]=tail[0];
            shield.tail[1]=tail[1];

            shield.mid[0]=mid[0];
            shield.mid[1]=mid[1];

            shield.ipx=tail[0];
            shield.ipy=tail[1];

            shield.innerradius=2.7;
            double x,y;

            azi=atan2(mid[1]-tail[1],mid[0]-tail[0]);
            if(azi<0)
                azi+=2*PI;
            shield.angle1=azi;
            x=shield.innerradius*cos(azi+PI/2.0)*hsx;
            y=shield.innerradius*sin(azi+PI/2.0)*hsy;
            shield.r1=sqrt(x*x+y*y);

            azi=atan2(head[1]-mid[1],head[0]-mid[0]);
            if(azi<0)
                azi+=2*PI;
            shield.angle2=azi;
            x=shield.innerradius*cos(azi+PI/2.0)*hsx;
            y=shield.innerradius*sin(azi+PI/2.0)*hsy;
            shield.r2=sqrt(x*x+y*y);
        }
        */
        vmapPanel->AddShield(shield);

        double d,r,x1,y1,x2,y2,l1,l2,l,x,y,h;
        l1=mtg->prj.mile1;
        l2=mtg->prj.mile2;
        d=mtg->segset.L*vs1;
        r=mtg->segset.De;
        if(l1<l2)
        {
            DxfMySeg seg;
            seg.innerradius=2.7*vs1;
            l=l1;
            double l3=mtg->m.headc-(mtg->m.headc-mtg->m.tailc)*vs1;
            while(l<l3)
            {
                road_l2h(&mtg->r,l,&h,0);
                x1=l;
                y1=h;
                x1=(x1-vx1)*vsx+vx10;
                y1=(y1-vy1)*vsy+vy10;

                l+=d;
                road_l2h(&mtg->r,l,&h,0);
                x2=l;
                y2=h;
                x2=(x2-vx1)*vsx+vx10;
                y2=(y2-vy1)*vsy+vy10;
                seg.x1=x1;
                seg.y1=y1;
                seg.x2=x2;
                seg.y2=y2;
                azi=atan2(y2-y1,x2-x1);
                if(azi<0)
                    azi+=2*PI;
                seg.angle1=azi;
                x=seg.innerradius*cos(azi+PI/2.0)*hsx;
                y=seg.innerradius*sin(azi+PI/2.0)*hsy;
                seg.r1=sqrt(x*x+y*y);
                vmapPanel->AddSegment(seg);
            }
        }
        else if(l1>l2)
        {
            DxfMySeg seg;
            seg.innerradius=2.7;
            l=l2;
            double l3=mtg->m.headc+(mtg->m.tailc-mtg->m.headc)*vs1;
            while(l>l3)
            {
                //road_l2xy(&mtg->r,l,&x1,&y1,0);
                road_l2h(&mtg->r,l,&h,0);
                x1=l;
                y1=h;
                x1=(x1-hx1)*hsx+hx10;
                y1=(y1-hy1)*hsy+hy10;
                l+=-d;
                //road_l2xy(&mtg->r,l,&x2,&y2,0);
                road_l2h(&mtg->r,l,&h,0);
                x2=l;
                y2=h;
                x2=(x2-hx1)*hsx+hx10;
                y2=(y2-hy1)*hsy+hy10;
                seg.x1=x1;
                seg.y1=y1;
                seg.x2=x2;
                seg.y2=y2;
                azi=atan2(y2-y1,x2-x1);
                if(azi<0)
                    azi+=2*PI;
                seg.angle1=azi;
                x=seg.innerradius*cos(azi+PI/2.0)*hsx;
                y=seg.innerradius*sin(azi+PI/2.0)*hsy;
                seg.r1=sqrt(x*x+y*y);
                vmapPanel->AddSegment(seg);
            }
        }

        vmapPanel->Fit((head[0]+tail[0])/2.0,(head[1]+tail[1])/2.0,4*shield.length,4*shield.length);
    }
}
