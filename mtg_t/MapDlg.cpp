///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MapDlg.h"
#include "mtg_tMain.h"
#include "mtg_tApp.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>

#include "geometry.h"
#include "MyCreation.h"
#include "dl_dxf.h"

#include <wx/stdpaths.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(MapDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(MapDlg)
#include <wx/font.h>
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

///////////////////////////////////////////////////////////////////////////
//(*IdInit(MapDlg)
const long MapDlg::ID_PANEL1 = wxNewId();
const long MapDlg::ID_PANEL2 = wxNewId();
const long MapDlg::ID_PANEL3 = wxNewId();
const long MapDlg::ID_PANEL4 = wxNewId();
const long MapDlg::ID_PANEL5 = wxNewId();
const long MapDlg::ID_PANEL6 = wxNewId();
const long MapDlg::ID_PANEL10 = wxNewId();
const long MapDlg::ID_PANEL14 = wxNewId();
const long MapDlg::ID_PANEL15 = wxNewId();
const long MapDlg::ID_PANEL16 = wxNewId();                 //纵断面图
const long MapDlg::ID_PANEL20 = wxNewId();                 //铰接设置

const long MapDlg::ID_BUTTON1 = wxNewId();                 //取消
//const long MapDlg::ID_BUTTON2 = wxNewId();                 //应用
//const long MapDlg::ID_BUTTON3 = wxNewId();                 //工程
const long MapDlg::ID_BUTTON6 = wxNewId();                 //导入激光靶参数文件
const long MapDlg::ID_BUTTON7 = wxNewId();                 //测量激光靶

const long MapDlg::ID_STATICTEXT1 = wxNewId();
const long MapDlg::ID_STATICTEXT3 = wxNewId();             //起点里程

const long MapDlg::ID_TEXTCTRL5 = wxNewId();                //项目名称
const long MapDlg::ID_TEXTCTRL12 = wxNewId();               //激光靶参数文件
//*)

MapDlg::MapDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);
    //(*Initialize(ConfigDialog)
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
	panelMain = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelNavi = new wxPanel(panelMain, ID_PANEL2, wxPoint(0,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelBorder1 = new wxPanel(panelMain, ID_PANEL3, wxPoint(0,0), wxSize(w,10), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    panelBorder2 = new wxPanel(panelMain, ID_PANEL4, wxPoint(w-8,10), wxSize(8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    panelBtnSet = new wxPanel(panelNavi, ID_PANEL5, wxPoint(0,0), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    panelBtnHorizon = new wxPanel(panelNavi, ID_PANEL10, wxPoint(0,36), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    panelBtnVertical = new wxPanel(panelNavi, ID_PANEL6, wxPoint(0,72), wxSize(160,36), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    panelBtnArea = new wxPanel(panelMain, ID_PANEL15, wxPoint(0,h-80), wxSize(w,90), wxTAB_TRAVERSAL, _T("ID_PANEL15"));
    panelBtnArea->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelSet = new wxPanel(panelMain, ID_PANEL14, wxPoint(160,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL14"));
    panelSet->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelSet->SetBackgroundColour(wxColor(255,255,255));
    panelSet->SetFont(normalFont);

    panelVertical = new MapView(panelMain, ID_PANEL16, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL16"));
    panelVertical->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelVertical->SetBackgroundColour(wxColor(255,255,255));
    panelVertical->SetFont(normalFont);

    panelHorizon = new MapView(panelMain, ID_PANEL20, wxPoint(160+w+w,10), wxSize(w-160-8,h-90), wxTAB_TRAVERSAL, _T("ID_PANEL20"));
    panelHorizon->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelHorizon->SetBackgroundColour(wxColor(255,255,255));
    panelHorizon->SetFont(normalFont);

    //panelHorizOP = new MapView(panelMain, ID_PANEL17, wxPoint(w/2-120,h-90-60), wxSize(200,45), wxTAB_TRAVERSAL, _T("ID_PANEL17"));
    //panelHorizOP->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelHorizOP->SetBackgroundColour(wxColor(255,255,255));
    //panelHorizOP->SetFont(normalFont);

    btnCancel = new wxButton(panelBtnArea, ID_BUTTON1, _("退 出"), wxPoint(w-96-10,15), wxSize(96,36), 0, wxDefaultValidator, _T("ID_BUTTON1"));

    //panelOut->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelIn->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelPan->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //panelWin->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //btnApply = new wxButton(panelBtnArea, ID_BUTTON2, _("应 用"), wxPoint(w-96-15-96,15), wxSize(96,36), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    //btnProj = new wxButton(panelBtnArea, ID_BUTTON3, _("工 程"), wxPoint(25,15), wxSize(96,36), 0, wxDefaultValidator, _T("ID_BUTTON3"));

    StaticText1 = new wxStaticText(panelSet, ID_STATICTEXT1, _("平面图"), wxPoint(25,25),wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    hmap_text = new wxMyTextCtrl(panelSet, ID_TEXTCTRL12, wxEmptyString, wxPoint(120,20), wxSize(240,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    hmap_text->SetEditable(false);
    btnImportHmap = new wxButton(panelSet, ID_BUTTON6, _("导入..."), wxPoint(380,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    StaticText3 = new wxStaticText(panelSet, ID_STATICTEXT3, _("纵断面图"), wxPoint(25,80),wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    vmap_text = new wxMyTextCtrl(panelSet, ID_TEXTCTRL5, wxEmptyString, wxPoint(120,75), wxSize(240,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    vmap_text->SetEditable(false);
    btnImportVmap = new wxButton(panelSet, ID_BUTTON7, _("导入..."), wxPoint(380,75), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));

	panelNavi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBorder1->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBorder1->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnSet->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnVertical->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelBtnHorizon->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelSet->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

	panelNavi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapDlg::OnPaintNavi,0,this);
	panelBorder1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapDlg::OnPaintBorder1,0,this);
	panelBorder2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapDlg::OnPaintBorder2,0,this);
    panelBtnSet->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapDlg::OnPaintBtnSet,0,this);
    panelBtnVertical->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapDlg::OnPaintVertical,0,this);
    panelBtnHorizon->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapDlg::OnPaintHorizon,0,this);
    panelSet->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapDlg::OnPaintSet,0,this);
    panelBtnArea->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapDlg::OnPaintBtnArea,0,this);
    panelBtnArea->Connect(wxEVT_MOTION,(wxObjectEventFunction)&MapDlg::OnEnterZoom,0,this);
    panelBtnArea->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapDlg::OnZoomClick,0,this);
    //panelCalSegment->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MapDlg::OnEnterZoom,0,this);
    //panelVertical->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapDlg::OnPaintPanelVertical,0,this);
    //panelHorizon->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapDlg::OnPaintPanelHorizon,0,this);

    //panelHorizOP->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MapDlg::OnPaintHOP,0,this);

    panelBtnSet->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MapDlg::OnEnterBtnSet,0,this);
    panelBtnSet->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapDlg::OnLeaveBtnSet,0,this);
    panelBtnSet->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MapDlg::OnLeftDownBtnSet,0,this);
    panelBtnSet->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapDlg::OnBtnSetClick,0,this);

    panelBtnVertical->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MapDlg::OnEnterBtnVertical,0,this);
    panelBtnVertical->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapDlg::OnLeaveBtnVertical,0,this);
    panelBtnVertical->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MapDlg::OnLeftDownBtnVertical,0,this);
    panelBtnVertical->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapDlg::OnBtnVerticalClick,0,this);

    panelBtnHorizon->Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&MapDlg::OnEnterBtnHorizon,0,this);
    panelBtnHorizon->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&MapDlg::OnLeaveBtnHorizon,0,this);
    panelBtnHorizon->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&MapDlg::OnLeftDownBtnHorizon,0,this);
    panelBtnHorizon->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&MapDlg::OnBtnHorizonClick,0,this);

    panelMain->Connect(wxEVT_SIZE,(wxObjectEventFunction)&MapDlg::OnSize,0,this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MapDlg::OnBtnQuit);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MapDlg::OnBtnHmap);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MapDlg::OnBtnVmap);
    //*)
    btnSetState = 4;
    btnHorizonState = 0;
    btnVerticalState = 0;
    //if(h_map.IsOk()) panelHorizon->SetBitmap(h_map);
    //if(v_map.IsOk()) panelVertical->SetBitmap(h_map);
    zoom = -1;
    ReadMap();
    //InitDXF();
}

MapDlg::~MapDlg()
{
}

void MapDlg::ReadMap()
{
    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);

    wxString hpath,vpath;
    hpath = path+_("/h_map.map");
    vpath = path+_("/v_map.map");

    if(wxFileExists(hpath))
    {
        char buf[1024];
        strcpy(buf,hpath.mb_str(wxConvLocal));
        FILE* fp=fopen(buf,"rb");
        if(fp)
        {
            fread(hname,64,1,fp);
            fread(&hmaps,sizeof(int),1,fp);
            h_map = new wxImage[hmaps];
            hmapw = (int*)malloc(hmaps*sizeof(int));
            hmaph = (int*)malloc(hmaps*sizeof(int));
            panelHorizon->maps = hmaps;
            panelHorizon->InitMap();
            for(int i=0;i<hmaps;i++)
            {
                fread(&hmapw[i],sizeof(int),1,fp);
                fread(&hmaph[i],sizeof(int),1,fp);
                h_map[i].Create(hmapw[i],hmaph[i]);

                //unsigned char* huc=new unsigned char[hmapw[i]*hmaph[i]*3];
                unsigned char* uc=new unsigned char[hmapw[i]*hmaph[i]*3];
                fread(uc,hmapw[i]*hmaph[i]*3,1,fp);
                h_map[i].SetData(uc);
                panelHorizon->w[i] = hmapw[i];
                panelHorizon->h[i] = hmaph[i];
                //affine_init(&panelHorizon->aff,mtg->mapset[0].affine);
                //panelHorizon->SetBitmap(h_map);
            }
            for(int i=0;i<2;i++)
            {
                fread(&m_points[i].x,sizeof(double),1,fp);
                fread(&m_points[i].y,sizeof(double),1,fp);
                fread(&m_points[i].x1,sizeof(double),1,fp);
                fread(&m_points[i].y1,sizeof(double),1,fp);
            }
            panelHorizon->coor1_x1[0] = m_points[0].x;
            panelHorizon->coor1_y1[0] = m_points[0].y;
            panelHorizon->coor1_x2[0] = m_points[1].x;
            panelHorizon->coor1_y2[0] = m_points[1].y;
            panelHorizon->coor2_x1 = m_points[0].x1;
            panelHorizon->coor2_y1 = m_points[0].y1;
            panelHorizon->coor2_x2 = m_points[1].x1;
            panelHorizon->coor2_y2 = m_points[1].y1;
            panelHorizon->map_type = 0;
            double dval1 = 0.0;
            double dval2 = 0.0;
            road_xy2l(&mtg->r,m_points[0].x1,m_points[0].y1,0,0,0,0,&dval1);
            road_xy2l(&mtg->r,m_points[1].x1,m_points[1].y1,0,0,0,0,&dval2);
            if(fabs(dval1)>0.02 || fabs(dval2)>0.02)
            {
                panelHorizon->error_map = -1;
                wxRemoveFile(hpath);
            }
            else
            {
                panelHorizon->error_map = 0;
                panelHorizon->InitCoor2Map();
                panelHorizon->SetBitmap(h_map);

                hmap_text->SetValue(wxString(hname,wxConvLocal));
            }

        }
        fclose(fp);
    }

    if(wxFileExists(vpath))
    {
        char vbuf[1024];
        strcpy(vbuf,vpath.mb_str(wxConvLocal));
        FILE* fp=fopen(vbuf,"rb");
        if(fp)
        {
            fread(vname,64,1,fp);
            fread(&vmaps,sizeof(int),1,fp);
            v_map = new wxImage[vmaps];
            vmapw = (int*)malloc(vmaps*sizeof(int));
            vmaph = (int*)malloc(vmaps*sizeof(int));
            panelVertical->maps = vmaps;
            panelVertical->InitMap();

            //wxMessageBox(_("ok"));
            for(int i=0;i<vmaps;i++)
            {
                fread(&vmapw[i],sizeof(int),1,fp);
                fread(&vmaph[i],sizeof(int),1,fp);
                v_map[i].Create(vmapw[i],vmaph[i]);

                unsigned char* vuc=new unsigned char[vmapw[i]*vmaph[i]*3];
                fread(vuc,vmapw[i]*vmaph[i]*3,1,fp);
                v_map[i].SetData(vuc);
                panelVertical->w[i] = vmapw[i];
                panelVertical->h[i] = vmaph[i];
            }
            for(int i=2;i<4;i++)
            {
                fread(&m_points[i].x,sizeof(double),1,fp);
                fread(&m_points[i].y,sizeof(double),1,fp);
                fread(&m_points[i].x1,sizeof(double),1,fp);
                fread(&m_points[i].y1,sizeof(double),1,fp);
            }

            panelVertical->coor1_x1[0] = m_points[2].x;
            panelVertical->coor1_y1[0] = m_points[2].y;
            panelVertical->coor1_x2[0] = m_points[3].x;
            panelVertical->coor1_y2[0] = m_points[3].y;
            panelVertical->coor2_x1 = m_points[2].x1;
            panelVertical->coor2_y1 = m_points[2].y1;
            panelVertical->coor2_x2 = m_points[3].x1;
            panelVertical->coor2_y2 = m_points[3].y1;
            panelVertical->map_type = 1;
            double dval1 = 0.0;
            double dval2 = 0.0;
            road_l2h(&mtg->r,m_points[2].x1,&dval1,0);
            road_l2h(&mtg->r,m_points[3].x1,&dval2,0);
            dval1 = dval1-m_points[2].y1;
            dval2 = dval2-m_points[3].y1;
            if(fabs(dval1)>0.02 || fabs(dval2)>0.02)
            {
                panelVertical->error_map = -1;
                wxRemoveFile(vpath);
            }
            else
            {
                panelVertical->error_map = 0;
                vmap_text->SetValue(wxString(vname,wxConvLocal));
                panelVertical->InitCoor2Map();
                panelVertical->SetBitmap(v_map);
            }
        }
        fclose(fp);

    }

}

void MapDlg::OnEnterZoom(wxMouseEvent& event)
{
    int w,h;
    panelBtnArea->GetClientSize(&w,&h);

    wxPoint pt[3];
    pt[0].x = w/2-30;
    pt[0].y = 30;
    pt[1].x = w/2+30;
    pt[1].y = 30;
    pt[2].x = w/2+90;
    pt[2].y = 30;

    int x,y;
    event.GetPosition(&x,&y);
    //wxMessageBox(wxString::Format(_("%d"),rect1.width));
    //wxMessageBox(wxString::Format(_("%d"),rect1.height));
    for(int i=0;i<3;i++)
    {
        double r1 = (x-pt[i].x)*(x-pt[i].x)+(y-pt[i].y)*(y-pt[i].y);
        r1 = sqrt(r1);
        //wxMessageBox(wxString::Format(_("%.4f"),r1));
        if(r1<=15.0)
        {
            zoom = i+1;
            break;
        }
        else
        {
            zoom = -1;
        }
    }

    panelBtnArea->Refresh();
}

void MapDlg::OnZoomClick(wxMouseEvent& event)
{
    if(zoom == 1)
    {
        if(btnHorizonState == 4)
        {
            panelHorizon->ZoomIn();
        }
        else if(btnVerticalState == 4)
        {
            panelVertical->ZoomIn();
        }
    }
    else if(zoom == 2)
    {
        if(btnHorizonState == 4)
        {
            panelHorizon->ZoomOut();
        }
        else if(btnVerticalState == 4)
        {
            panelVertical->ZoomOut();
        }
    }
    else if(zoom == 3)
    {
        if(btnHorizonState == 4)
        {
            panelHorizon->FitWin();
        }
        else if(btnVerticalState == 4)
        {
            panelVertical->FitWin();
        }
    }
}

void MapDlg::OnSize(wxSizeEvent& event)
{
    panelHorizon->Refresh();
    panelVertical->Refresh();
    panelMain->Refresh();
    panelNavi->Refresh();
    panelBorder1->Refresh();
    panelBorder2->Refresh();
    panelBtnSet->Refresh();
    panelBtnHorizon->Refresh();
    panelBtnVertical->Refresh();
    panelSet->Refresh();
    panelBtnArea->Refresh();
}

void MapDlg::OnBtnQuit(wxCommandEvent& event)
{
    Destroy();
}

void MapDlg::OnBtnHmap(wxCommandEvent& event)
{
    wxFileDialog dlg(this,_("请选择要导入的地图文件"),wxEmptyString,wxEmptyString,_("地图文件(*.map)|*.map"),wxFD_OPEN);
    if(dlg.ShowModal()==wxID_OK)
    {
        wxString str=dlg.GetPath();
        char buf[1024];
        wxString str1;
        str1 = dlg.GetFilename();
        //strcpy(mtg->mapset[0].name,str1.mb_str(wxConvUTF8));
        strcpy(hname,str1.mb_str(wxConvLocal));
        strcpy(buf,str.mb_str(wxConvLocal));
        FILE* fp=fopen(buf,"rb");
        if(fp)
        {
            fread(&hmaps,sizeof(int),1,fp);
            h_map = new wxImage[hmaps];
            hmapw = (int*)malloc(hmaps*sizeof(int));
            hmaph = (int*)malloc(hmaps*sizeof(int));
            for(int i=0;i<hmaps;i++)
            {
                fread(&hmapw[i],sizeof(int),1,fp);
                fread(&hmaph[i],sizeof(int),1,fp);
                h_map[i].Create(hmapw[i],hmaph[i]);
                unsigned char* uc=new unsigned char[hmapw[i]*hmaph[i]*3];
                fread(uc,hmapw[i]*hmaph[i]*3,1,fp);
                h_map[i].SetData(uc);
                //m_img[i].SetData(uc);
            }
            for(int i=0;i<2;i++)
            {
                fread(&m_points[i].x,sizeof(double),1,fp);
                fread(&m_points[i].y,sizeof(double),1,fp);
                fread(&m_points[i].x1,sizeof(double),1,fp);
                fread(&m_points[i].y1,sizeof(double),1,fp);
            }
            wxStandardPaths stdp;
            wxString path=stdp.GetExecutablePath();
            #ifdef WIN32
            int t=path.Find('\\',true);
            #else
            int t=path.Find('/',true);
            #endif
            path=path.SubString(0,t-1);
            path = path+_("/h_map.map");
            char cs[1024];
            strcpy(cs,path.mb_str(wxConvLocal));
            FILE* fp1 = fopen(cs,"wb");
            if(fp1)
            {
                fwrite(hname,64,1,fp1);
                fwrite(&hmaps,sizeof(int),1,fp1);
                for(int i=0;i<hmaps;i++)
                {
                    fwrite(&hmapw[i],sizeof(int),1,fp1);
                    fwrite(&hmaph[i],sizeof(int),1,fp1);
                    unsigned char* uc=h_map[i].GetData();
                    fwrite(uc,hmapw[i]*hmaph[i]*3,1,fp1);
                }
                for(int i=0;i<2;i++)
                {
                    fwrite(&m_points[i].x,sizeof(double),1,fp1);
                    fwrite(&m_points[i].y,sizeof(double),1,fp1);
                    fwrite(&m_points[i].x1,sizeof(double),1,fp1);
                    fwrite(&m_points[i].y1,sizeof(double),1,fp1);
                }
            }
            fclose(fp1);
            ReadMap();
            //mtg_store_mapset(mtg,0);
            wxMessageBox(_("导入成功！"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
        }
        fclose(fp);
    }
}

void MapDlg::OnBtnVmap(wxCommandEvent& event)
{
    wxFileDialog dlg(this,_("请选择要导入的地图文件"),wxEmptyString,wxEmptyString,_("地图文件(*.map)|*.map"),wxFD_OPEN);
    if(dlg.ShowModal()==wxID_OK)
    {
        wxString str=dlg.GetPath();
        char buf[1024];
        wxString str1;
        str1 = dlg.GetFilename();
        //strcpy(mtg->mapset[1].name,str1.mb_str(wxConvUTF8));
        strcpy(vname,str1.mb_str(wxConvLocal));
        strcpy(buf,str.mb_str(wxConvLocal));
        FILE* fp=fopen(buf,"rb");
        if(fp)
        {
            fread(&vmaps,sizeof(int),1,fp);
            v_map = new wxImage[vmaps];
            vmapw = (int*)malloc(vmaps*sizeof(int));
            vmaph = (int*)malloc(vmaps*sizeof(int));
            for(int i=0;i<vmaps;i++)
            {
                fread(&vmapw[i],sizeof(int),1,fp);
                fread(&vmaph[i],sizeof(int),1,fp);
                v_map[i].Create(vmapw[i],vmaph[i]);
                unsigned char* uc=new unsigned char[vmapw[i]*vmaph[i]*3];
                fread(uc,vmapw[i]*vmaph[i]*3,1,fp);
                v_map[i].SetData(uc);
            }
            for(int i=2;i<4;i++)
            {
                fread(&m_points[i].x,sizeof(double),1,fp);
                fread(&m_points[i].y,sizeof(double),1,fp);
                fread(&m_points[i].x1,sizeof(double),1,fp);
                fread(&m_points[i].y1,sizeof(double),1,fp);
            }

            wxStandardPaths stdp;
            wxString path=stdp.GetExecutablePath();
            #ifdef WIN32
            int t=path.Find('\\',true);
            #else
            int t=path.Find('/',true);
            #endif
            path=path.SubString(0,t-1);
            path = path+_("/v_map.map");
            char cs[1024];
            strcpy(cs,path.mb_str(wxConvLocal));
            FILE* fp1 = fopen(cs,"wb");
            if(fp)
            {
                fwrite(vname,64,1,fp1);
                fwrite(&vmaps,sizeof(int),1,fp1);
                for(int i=0;i<vmaps;i++)
                {
                    fwrite(&vmapw[i],sizeof(int),1,fp1);
                    fwrite(&vmaph[i],sizeof(int),1,fp1);
                    unsigned char* uc=v_map[i].GetData();
                    fwrite(uc,vmapw[i]*vmaph[i]*3,1,fp1);
                }
                for(int i=2;i<4;i++)
                {
                    fwrite(&m_points[i].x,sizeof(double),1,fp1);
                    fwrite(&m_points[i].y,sizeof(double),1,fp1);
                    fwrite(&m_points[i].x1,sizeof(double),1,fp1);
                    fwrite(&m_points[i].y1,sizeof(double),1,fp1);
                }
            }
            fclose(fp1);
            ReadMap();
            //mtg_store_mapset(mtg,1);
            wxMessageBox(_("导入成功！"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
        }
        fclose(fp);
    }
}

int MapDlg::GetCurPoint()
{
    return m_cur;
}

void MapDlg::OnPaintNavi(wxPaintEvent& event)
{
    wxPaintDC dc(panelNavi);
    int w,h;
    panelNavi->GetClientSize(&w,&h);

    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(0,-1,w,h+1);
}

void MapDlg::OnPaintBorder1(wxPaintEvent& event)
{
    wxPaintDC dc(panelBorder1);
    int w,h;
    panelBorder1->GetClientSize(&w,&h);

    ///background
    int *maxPixels,*minPixels;
    maxPixels=(int*)malloc(3*sizeof(int));
    memset(maxPixels,0,3);

    minPixels=(int*)malloc(3*sizeof(int));
    memset(minPixels,0,3);

    wxRect rect(0,0,w,h);

    maxPixels[0]=227;
    maxPixels[1]=227;
    maxPixels[2]=227;

    minPixels[0]=249;
    minPixels[1]=249;
    minPixels[2]=249;

    PaintGradual(panelBorder1, rect, maxPixels,minPixels,0);

    free(maxPixels);
    free(minPixels);
}

void MapDlg::OnPaintBorder2(wxPaintEvent& event)
{
    wxPaintDC dc(panelBorder2);
    int w,h;
    panelBorder2->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.DrawLine(0,h-1,w,h-1);
}

void MapDlg::OnPaintBtnSet(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnSet);
    int w,h;
    panelBtnSet->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnSetState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("地图设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("地图设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("地图设置"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MapDlg::OnPaintVertical(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnVertical);
    int w,h;
    panelBtnVertical->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnVerticalState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("纵断面图"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("纵断面图"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("纵断面图"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MapDlg::OnPaintHorizon(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnHorizon);
    int w,h;
    panelBtnHorizon->GetClientSize(&w,&h);
    ///background
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetTextForeground(wxColor(80,80,80));
    switch(btnHorizonState)
    {
    case 0:
    case 2:
    case 3:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.DrawLine(w-1,0,w-1,h);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("平面图"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 1:
        dc.SetPen(wxPen(wxColor(245,245,245)));
        dc.SetBrush(wxBrush(wxColor(245,245,245)));
        dc.DrawRectangle(-1,-1,w+2,h+2);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(w-1,0,w-1,h);
        dc.DrawLine(0,0,0,h);
        dc.SetPen(wxPen(wxColor(227,227,227)));
        dc.SetBrush(wxBrush(wxColor(249,249,249)));
        dc.DrawRectangle(15,5,w-20,h-10);
        dc.SetFont(normalFont);
        dc.DrawLabel(_("平面图"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    case 4:
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.SetBrush(wxBrush(wxColor(255,255,255)));
        dc.DrawRectangle(8,0,w-7,h);
        dc.SetPen(wxPen(wxColor(201,201,201)));
        dc.DrawLine(0,0,0,h);
        dc.SetFont(boldFont);
        dc.DrawLabel(_("平面图"),wxRect(20,5,w-20,h-10),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        break;
    default:
        break;
    }
}

void MapDlg::OnEnterBtnSet(wxPaintEvent& event)
{
    if(btnSetState!=4)
    {
        btnSetState=1;
        panelBtnSet->Refresh();
    }
}

void MapDlg::OnLeaveBtnSet(wxMouseEvent& event)
{
    if(btnSetState!=4)
    {
        btnSetState=2;
        panelBtnSet->Refresh();
    }
}

void MapDlg::OnLeftDownBtnSet(wxMouseEvent& event)
{
    if(btnSetState!=4)
    {
        btnSetState=3;
        panelBtnSet->Refresh();
    }
}

void MapDlg::OnBtnSetClick(wxMouseEvent& event)
{
    if(btnSetState!=4)
    {
        btnSetState=4;
        int w,h;
        panelSet->GetClientSize(&w,&h);
        panelSet->SetSize(160,10,w,h);
        panelSet->Refresh();
        panelNavi->Refresh();
        panelBtnSet->Refresh();
        if(btnVerticalState==4)
        {
            btnVerticalState=0;
            panelVertical->SetPosition(wxPoint(w+w+160,10));
            panelBtnVertical->Refresh();
        }
        if(btnHorizonState==4)
        {
            btnHorizonState=0;
            panelHorizon->SetPosition(wxPoint(w+w+160,10));
            panelBtnHorizon->Refresh();
        }
        panelBtnArea->Refresh();
    }
}

void MapDlg::OnEnterBtnVertical(wxMouseEvent& event)
{
    if(btnVerticalState!=4)
    {
        btnVerticalState=1;
        panelBtnVertical->Refresh();
    }
}

void MapDlg::OnLeaveBtnVertical(wxPaintEvent& event)
{
    if(btnVerticalState!=4)
    {
        btnVerticalState=2;
        panelBtnVertical->Refresh();
    }
}

void MapDlg::OnLeftDownBtnVertical(wxMouseEvent& event)
{
    if(btnVerticalState!=4)
    {
        btnVerticalState=3;
        panelBtnVertical->Refresh();
    }
}

void MapDlg::OnBtnVerticalClick(wxMouseEvent& event)
{
    if(btnVerticalState!=4)
    {
        btnVerticalState=4;
        int w,h;
        panelVertical->GetClientSize(&w,&h);
        panelVertical->SetSize(160,10,w,h);
        panelVertical->Refresh();
        panelNavi->Refresh();
        panelBtnVertical->Refresh();
        if(btnSetState==4)
        {
            btnSetState=0;
            panelSet->SetPosition(wxPoint(w+w+160,10));
            panelBtnSet->Refresh();
        }
        if(btnHorizonState==4)
        {
            btnHorizonState=0;
            panelHorizon->SetPosition(wxPoint(w+w+160,10));
            panelBtnHorizon->Refresh();
        }
        panelBtnArea->Refresh();
    }
}

void MapDlg::OnEnterBtnHorizon(wxPaintEvent& event)
{
    if(btnHorizonState!=4)
    {
        btnHorizonState=1;
        panelBtnHorizon->Refresh();
    }
}

void MapDlg::OnLeaveBtnHorizon(wxMouseEvent& event)
{
     if(btnHorizonState!=4)
    {
        btnHorizonState=2;
        panelBtnHorizon->Refresh();
    }
}

void MapDlg::OnLeftDownBtnHorizon(wxMouseEvent& event)
{
     if(btnHorizonState!=4)
    {
        btnHorizonState=3;
        panelBtnHorizon->Refresh();
    }
}

void MapDlg::OnBtnHorizonClick(wxMouseEvent& event)
{
    if(btnHorizonState!=4)
    {
        btnHorizonState=4;
        int w,h;
        panelHorizon->GetClientSize(&w,&h);
        panelHorizon->SetSize(160,10,w,h);
        panelHorizon->Refresh();
        panelNavi->Refresh();
        panelBtnHorizon->Refresh();
        if(btnSetState==4)
        {
            btnSetState=0;
            panelSet->SetPosition(wxPoint(w+w+160,10));
            panelBtnSet->Refresh();
        }
        if(btnVerticalState==4)
        {
            btnVerticalState=0;
            panelVertical->SetPosition(wxPoint(w+w+160,10));
            panelBtnVertical->Refresh();
        }
        panelBtnArea->Refresh();
    }
}


void MapDlg::OnPaintSet(wxPaintEvent& event)
{
    wxPaintDC dc(panelSet);
    int w,h;
    panelSet->GetClientSize(&w,&h);
    ///background
    dc.SetPen(wxPen(wxColor(255,255,255)));
    dc.SetBrush(wxBrush(wxColor(255,255,255)));
    dc.DrawRectangle(-1,-1,w+2,h+2);
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.DrawLine(0,0,w,0);
    dc.DrawLine(w-1,0,w-1,h);
    dc.DrawLine(0,h-1,w,h-1);

    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    wxFont boldFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("宋体"),wxFONTENCODING_DEFAULT);
    dc.SetFont(boldFont);
    dc.SetTextForeground(wxColor(80,80,80));
    dc.SetPen(wxPen(wxColor(230,230,230)));
    //dc.DrawLabel(_("区间设置"),wxRect(25,7,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLabel(_("管片编号增加方式"),wxRect(25,79,120,36),wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
    //dc.DrawLine(25,36,w-25,36);
    //dc.DrawLine(25,108,w-25,108);
    //dc.DrawLine(25,180,w-25,180);
    //dc.DrawLine(25,252,w-25,252);
    //dc.DrawLine(25,384,w-25,384);
}

void MapDlg::OnPaintBtnArea(wxPaintEvent& event)
{
    wxPaintDC dc(panelBtnArea);
    int w,h;
    panelBtnArea->GetClientSize(&w,&h);
    ///background
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        memDC.SetPen(wxPen(wxColor(227,227,227)));
        memDC.SetBrush(wxBrush(wxColor(227,227,227)));
        memDC.DrawRectangle(0,0,w,h);

        memDC.SetPen(wxPen(wxColor(248,248,248)));
        memDC.DrawLine(0,0,w,0);

        if(btnSetState!=4)
        {
            memDC.SetPen(wxPen(wxColor(80,92,106),2));
            memDC.SetBrush(*wxTRANSPARENT_BRUSH);
            if(zoom == 1)
            {
                memDC.SetPen(wxPen(wxColor(122,176,232),2));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(80,92,106),2));
            }
            memDC.DrawCircle(w/2-30,30,15);
            if(zoom == 2)
            {
                memDC.SetPen(wxPen(wxColor(122,176,232),2));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(80,92,106),2));
            }
            memDC.DrawCircle(w/2+30,30,15);
            if(zoom == 3)
            {
                memDC.SetPen(wxPen(wxColor(122,176,232),2));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(80,92,106),2));
            }
            memDC.DrawCircle(w/2+90,30,15);

            ///zoomin
            if(zoom == 1)
            {
                memDC.SetPen(wxPen(wxColor(122,176,232)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(80,92,106)));
            }
            memDC.DrawLine(w/2-23,30,w/2-39,30);
            memDC.DrawLine(w/2-23,31,w/2-39,31);
            memDC.DrawLine(w/2-23,29,w/2-39,29);
            memDC.DrawLine(w/2-30,22,w/2-30,38);
            memDC.DrawLine(w/2-31,22,w/2-31,38);
            memDC.DrawLine(w/2-29,22,w/2-29,38);
            ///zoomout
            if(zoom == 2)
            {
                memDC.SetPen(wxPen(wxColor(122,176,232)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(80,92,106)));
            }
            memDC.DrawLine(w/2+21,30,w/2+37,30);
            memDC.DrawLine(w/2+21,31,w/2+37,31);
            memDC.DrawLine(w/2+21,29,w/2+37,29);
            ///pan
            if(zoom == 3)
            {
                memDC.SetPen(wxPen(wxColor(122,176,232)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(80,92,106)));
            }
            memDC.DrawLine(w/2+82,22,w/2+98,22);
            memDC.DrawLine(w/2+98,22,w/2+98,38);
            memDC.DrawLine(w/2+82,38,w/2+98,38);
            memDC.DrawLine(w/2+82,22,w/2+82,38);

        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void MapDlg::PaintGradual(wxPanel* panel, wxRect rect, int *maxColorValue,int *minColorValue,int paintStyle)
{
    if(rect.width==0 || rect.height==0)
    {
        return;
    }
    else
    {
        wxPaintDC dc(panel);
        int w,h;
        panel->GetClientSize(&w,&h);

        int maxr,maxg,maxb;
        int minr,ming,minb;
        double stepr,stepg,stepb;
        //int signr,signg,signb;

        maxr=maxColorValue[0];
        maxg=maxColorValue[1];
        maxb=maxColorValue[2];

        minr=minColorValue[0];
        ming=minColorValue[1];
        minb=minColorValue[2];

        int x0=rect.x,y0=rect.y;
        int x1=x0+rect.width,y1=y0+rect.height;

        int wb=rect.width;
        int hb=rect.height;


        //btnStartState=3;
        switch(paintStyle)
        {
        case 0:
            if(maxr-minr==0)
            {
                stepr=0.0;

            }
            else
            {
                stepr=(double)(maxr-minr);
                stepr=stepr/hb;
                //wxMessageBox(wxString::Format(_("%f"),stepr));
                //stepr=(double)((maxr-minr)/hb);
            }
            if(maxg-ming==0)
            {
                stepg=0.0;
            }
            else
            {
                stepg=(double)(maxg-ming);
                stepg=stepg/hb;
            }
            if(maxb-minb==0)
            {
                stepb=0.0;
            }
            else
            {
                stepb=(double)(maxb-minb);
                stepb=stepb/hb;
            }
            for(int i=0;i<hb;i++)
            {
                dc.SetPen(wxPen(wxColor(maxr,maxg,maxb)));
                dc.DrawLine(x0,y0+i,x1,y0+i);

                if(abs(stepr)>1)
                {
                    if(maxr-stepr<255&&maxr-stepr>0)
                    {
                        maxr-=stepr;
                    }
                }
                else
                {
                    if(maxr-stepr*i<255&&maxr-stepr*i>0)
                    {
                        maxr=maxColorValue[0]-(int)(stepr*(i+1));
                    }
                }

                if(abs(stepg)>1)
                {
                    if(maxg-stepg<255&&maxg-stepg>0)
                    {
                        maxg-=stepg;
                    }
                }
                else
                {
                    if(maxg-stepg*i<255&&maxg-stepg*i>0)
                    {
                        maxg=maxColorValue[1]-(int)(stepg*(i+1));
                    }
                }

                if(abs(stepb)>1)
                {
                    if(maxb-stepb<255&&maxb-stepb>0)
                    {
                        maxb-=stepb;
                    }
                }
                else
                {
                    if(maxb-stepb*i<255&&maxb-stepb*i>0)
                    {
                        maxb=maxColorValue[2]-(int)(stepb*(i+1));
                    }
                }
            }
            //dc.DrawLabel(name,wxRect(x0,y0,wb,hb),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL);
            break;
        case 1:
            if(maxr-minr==0)
            {
                stepr=0;
            }
            else
            {
                stepr=(maxr-minr)*2/hb;
            }

            if(maxg-ming==0)
            {
                stepg=0;
            }
            else
            {
                stepg=(maxg-ming)*2/hb;
            }

            if(maxb-minb==0)
            {
                stepb=0;
            }
            else
            {
                stepb=(maxb-minb)*2/hb;
            }

            for(int i=0;i<hb/2;i++)
            {
                dc.SetPen(wxPen(wxColor(maxr,maxg,maxb)));
                dc.DrawLine(x0,y0+i,x1,y0+i);
                if(abs(stepr)>1)
                {
                    if(maxr-stepr<255&&maxr-stepr>0)
                    {
                        maxr-=stepr;
                    }
                }
                else
                {
                    if(maxr-stepr*i<255&&maxr-stepr*i>0)
                    {
                        maxr=maxColorValue[0]-(int)(stepr*(i+1));
                    }
                }

                if(abs(stepg)>1)
                {
                    if(maxg-stepg<255&&maxg-stepg>0)
                    {
                        maxg-=stepg;
                    }
                }
                else
                {
                    if(maxg-stepg*i<255&&maxg-stepg*i>0)
                    {
                        maxg=maxColorValue[1]-(int)(stepg*(i+1));
                    }
                }

                if(abs(stepb)>1)
                {
                    if(maxb-stepb<255&&maxb-stepb>0)
                    {
                        maxb-=stepb;
                    }
                }
                else
                {
                    if(maxb-stepb*i<255&&maxb-stepb*i>0)
                    {
                        maxb=maxColorValue[2]-(int)(stepb*(i+1));
                    }
                }
            }

            maxColorValue[0]=maxr;
            maxColorValue[1]=maxg;
            maxColorValue[2]=maxb;
            for(int i=hb/2;i<hb;i++)
            {
                dc.SetPen(wxPen(wxColor(maxr,maxg,maxb)));
                dc.DrawLine(x0,y0+i,x1,y0+i);
                if(abs(stepr)>1)
                {
                    if(maxr-stepr<255&&maxr-stepr>0)
                    {
                        maxr+=stepr;
                    }
                }
                else
                {
                    if(maxr-stepr*i<255&&maxr-stepr*i>0)
                    {
                        maxr=maxColorValue[0]+stepr*(i-hb/2);
                    }
                }

                if(abs(stepg)>1)
                {
                    if(maxg-stepg<255&&maxg-stepg>0)
                    {
                        maxg+=stepg;
                    }
                }
                else
                {
                    if(maxg-stepg*i<255&&maxg-stepg*i>0)
                    {
                        maxg=maxColorValue[1]+stepg*(i-hb/2);
                    }
                }

                if(abs(stepb)>1)
                {
                    if(maxb-stepb<255&&maxb-stepb>0)
                    {
                        maxb+=stepb;
                    }
                }
                else
                {
                    if(maxb-stepb*i<255&&maxb-stepb*i>0)
                    {
                        maxb=maxColorValue[2]+stepb*(i-hb/2);
                    }
                }
            }
            break;
        default:
            break;
        }
    }
}


