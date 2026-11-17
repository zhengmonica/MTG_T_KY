///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MapSettingDlg.h"
//#include "confirmdlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#include "mtg_t_svrApp.h"
#include "mtg_t_svrMain.h"


#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MapSettingDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MapSettingDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MapSettingDlg)

//*)
const long MapSettingDlg::ID_canvas=wxNewId();

MapSettingDlg::MapSettingDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

    panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x1=0;
    y1=49;
    w1=w;
    h1=h-95;

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x10Text = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    y10Text = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    x1Text = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    y1Text = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    x20Text = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    y20Text = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    x2Text = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    y2Text = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    sText = new wxMyTextCtrl(panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapSettingDlg::OnPaintMain,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapSettingDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MapSettingDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapSettingDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapSettingDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));


    x10=0.0;
    y10=0.0;
    x1=0.0;
    y1=0.0;
    x20=0.0;
    y20=0.0;
    x2=0.0;
    y2=0.0;
    mscl=1.0;
    //cross_cursor=wxCursor(wxCURSOR_CROSS);
    //stand_cursor=wxCursor(wxCURSOR_ARROW);
    motion=ID_MSET_NONE;
    MAP_TYPE=0;
    LoadData();
}

MapSettingDlg::~MapSettingDlg()
{

}

void MapSettingDlg::OnPaintBottom(wxPaintEvent& event)
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
        int x2,y2,w2,h2;
        memDC.SetPen(wxPen(wxColor(117,117,117)));

        x1=9;
        y1=9;
        h1=26;
        w1=h1*4/3;

        msetButton[ID_MSET_PRT_SCN].x=x1;
        msetButton[ID_MSET_PRT_SCN].y=y1;
        msetButton[ID_MSET_PRT_SCN].width=w1;
        msetButton[ID_MSET_PRT_SCN].height=h1;
        if(motion==ID_MSET_PRT_SCN)
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

        w1=65;
        x1=w/2-w1-4;
        msetButton[ID_MSET_OK].x=x1;
        msetButton[ID_MSET_OK].y=y1;
        msetButton[ID_MSET_OK].width=w1;
        msetButton[ID_MSET_OK].height=h1;
        if(motion==ID_MSET_OK)
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

        x1=w/2+4;
        msetButton[ID_MSET_CANCEL].x=x1;
        msetButton[ID_MSET_CANCEL].y=y1;
        msetButton[ID_MSET_CANCEL].width=w1;
        msetButton[ID_MSET_CANCEL].height=h1;
        if(motion==ID_MSET_CANCEL)
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
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MapSettingDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>msetButton[ID_MSET_OK].y && y<msetButton[ID_MSET_OK].y+msetButton[ID_MSET_OK].height)
    {
        if(x>msetButton[ID_MSET_OK].x && x<msetButton[ID_MSET_OK].x+msetButton[ID_MSET_OK].width)
        {
            motion=ID_MSET_OK;
        }
        else if(x>msetButton[ID_MSET_CANCEL].x && x<msetButton[ID_MSET_CANCEL].x+msetButton[ID_MSET_CANCEL].width)
        {
            motion=ID_MSET_CANCEL;
        }
        else if(x>msetButton[ID_MSET_PRT_SCN].x && x<msetButton[ID_MSET_PRT_SCN].x+msetButton[ID_MSET_PRT_SCN].width)
        {
            motion=ID_MSET_PRT_SCN;
        }
        else
        {
            motion=ID_MSET_NONE;
        }
    }
    else
    {
        motion=ID_MSET_NONE;
    }
    panelBottom->Refresh();
}

void MapSettingDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_MSET_NONE;
    panelBottom->Refresh();
}

void MapSettingDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_MSET_OK)
    {
        x10Text->GetValue().ToDouble(&x10);
        y10Text->GetValue().ToDouble(&y10);
        x1Text->GetValue().ToDouble(&x1);
        y1Text->GetValue().ToDouble(&y1);
        x20Text->GetValue().ToDouble(&x20);
        y20Text->GetValue().ToDouble(&y20);
        x2Text->GetValue().ToDouble(&x2);
        y2Text->GetValue().ToDouble(&y2);
        sText->GetValue().ToDouble(&mscl);
        SaveData();
        EndModal(wxID_OK);
    }
    else if(motion==ID_MSET_CANCEL)
    {
        EndModal(wxID_CANCEL);
    }
    else if(motion==ID_MSET_PRT_SCN)
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
        if(MAP_TYPE==0) str=_("平面图参数");
        else if(MAP_TYPE==1) str=_("地质图参数");
        str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
        }

        panelBottom->Refresh();
    }
}

void MapSettingDlg::SaveData()
{
    wxStandardPaths wsp;
    wxString str_conf;
    if(MAP_TYPE==0) str_conf=wsp.GetDataDir()+wxString(_("\\plugins\\h_conf.ini"));
    else str_conf=wsp.GetDataDir()+wxString(_("\\plugins\\v_conf.ini"));
    char ch_conf[1024];
    strcpy(ch_conf,str_conf.mb_str(wxConvLocal));
    FILE* fp=fopen(ch_conf,"w");
    if(fp)
    {
        fprintf(fp,"%lf,%lf,%lf,%lf\n",x10,y10,x1,y1);
        fprintf(fp,"%lf,%lf,%lf,%lf\n",x20,y20,x2,y2);
        fprintf(fp,"%lf\n",mscl);
        fclose(fp);
    }
}

void MapSettingDlg::LoadData()
{
    if(MAP_TYPE==0) this->SetLabel(_("平面图参数"));
    else this->SetLabel(_("地质图参数"));
    wxStandardPaths wsp;
    wxString str_conf;
    if(MAP_TYPE==0) str_conf=wsp.GetDataDir()+wxString(_("\\plugins\\h_conf.ini"));
    else str_conf=wsp.GetDataDir()+wxString(_("\\plugins\\v_conf.ini"));
    char ch_conf[1024];
    strcpy(ch_conf,str_conf.mb_str(wxConvLocal));
    FILE* fp=fopen(ch_conf,"r");
    char buf[1024];
    char* ret=NULL;
    if(fp)
    {
        ret=fgets(buf,1023,fp);
        sscanf(buf,"%lf,%lf,%lf,%lf",&x10,&y10,&x1,&y1);
        ret=fgets(buf,1023,fp);
        sscanf(buf,"%lf,%lf,%lf,%lf",&x20,&y20,&x2,&y2);
        ret=fgets(buf,1023,fp);
        sscanf(buf,"%lf",&mscl);
		fclose(fp);
		x10Text->SetValue(wxString::Format(_("%.4f"),x10));
		y10Text->SetValue(wxString::Format(_("%.4f"),y10));
		x1Text->SetValue(wxString::Format(_("%.4f"),x1));
		y1Text->SetValue(wxString::Format(_("%.4f"),y1));
		x20Text->SetValue(wxString::Format(_("%.4f"),x20));
		y20Text->SetValue(wxString::Format(_("%.4f"),y20));
		x2Text->SetValue(wxString::Format(_("%.4f"),x2));
		y2Text->SetValue(wxString::Format(_("%.4f"),y2));
		sText->SetValue(wxString::Format(_("%.6f"),mscl));
    }
}

void MapSettingDlg::OnPaintMain(wxPaintEvent& event)
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        //memDC.SetPen(wxPen(wxColor(241,245,250)));
        //memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        //memDC.DrawRectangle(-1,38,w+2,10);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,19,w,19);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(-1,20,w+2,h-20);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,h-1,w,h-1);

        int x1,y1,w1,h1;
        int x2,y2,w2,h2;
        if(MAP_TYPE==0)
        {
            x1=14;
            y1=36;
            w1=w/2-26;
            h1=h-96;
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            memDC.SetPen(wxPen(wxColor(237,240,245)));
            memDC.DrawRectangle(x1+8,y1,65,30);
            memDC.DrawLabel(_("起点设置"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            x2=x1+15;
            y2=y1+35;
            memDC.DrawLabel(_("北坐标(X)"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x10Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("东坐标(Y)"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            y10Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("设计北坐标(X)"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x1Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("设计东坐标(Y)"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            y1Text->SetSize(x2+87,y2-11,110,-1);

            x1=w/2+3;
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            memDC.SetPen(wxPen(wxColor(237,240,245)));
            memDC.DrawRectangle(x1+8,y1,65,30);
            memDC.DrawLabel(_("终点设置"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            x2=x1+15;
            y2=y1+35;
            memDC.DrawLabel(_("北坐标(X)"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x20Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("东坐标(Y)"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            y20Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("设计北坐标(X)"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x2Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("设计东坐标(Y)"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            y2Text->SetSize(x2+87,y2-11,110,-1);

            x1=7;
            y1=y1+h1+30;
            memDC.DrawLabel(_("图形比例"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            sText->SetSize(x1+87,y1-11,110,-1);
        }
        else if(MAP_TYPE==1)
        {
            x1=14;
            y1=36;
            w1=w/2-26;
            h1=h-96;
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            memDC.SetPen(wxPen(wxColor(237,240,245)));
            memDC.DrawRectangle(x1+8,y1,65,30);
            memDC.DrawLabel(_("起点设置"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            x2=x1+15;
            y2=y1+35;
            memDC.DrawLabel(_("里程"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x10Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("高程"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            y10Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("设计里程"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x1Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("设计高程"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            y1Text->SetSize(x2+87,y2-11,110,-1);

            x1=w/2+3;
            memDC.SetPen(wxPen(wxColor(172,168,153)));
            memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
            memDC.SetPen(wxPen(wxColor(237,240,245)));
            memDC.DrawRectangle(x1+8,y1,65,30);
            memDC.DrawLabel(_("终点设置"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

            x2=x1+15;
            y2=y1+35;
            memDC.DrawLabel(_("里程"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x20Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("高程"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            y20Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("设计里程"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            x2Text->SetSize(x2+87,y2-11,110,-1);
            y2=y2+28;
            memDC.DrawLabel(_("设计高程"),wxRect(x2+80,y2,0,0),wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
            y2Text->SetSize(x2+87,y2-11,110,-1);

            x1=7;
            y1=y1+h1+30;
            memDC.DrawLabel(_("图形比例"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            sText->SetSize(x1+87,y1-11,110,-1);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}
