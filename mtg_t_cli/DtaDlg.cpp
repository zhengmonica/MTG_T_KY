///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DtaDlg.h"
#include "mtg_t_cliMain.h"
#include "mtg_t_cliApp.h"
#include "H_StartPoint.h"
#include "H_Line.h"
#include "H_Round.h"
#include "H_Moderate.h"
#include "V_StartPoint.h"
#include "V_Line.h"
#include "V_Round.h"
#include "OffDialog.h"
#include "ConfirmDlg.h"
#include "PasswordDialog.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include "dmsrad.h"
#include <wx/filename.h>
#include "libele.h"

#define WEBPC 0

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(DtaDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(DtaDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(DtaDlg)
//*)

DtaDlg::DtaDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    //(*Initialize(ConfigDialog)
    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);
    bmpImport.LoadFile(path+_("/plugins/dta_import.png"),wxBITMAP_TYPE_PNG);
    bmpEmport.LoadFile(path+_("/plugins/dta_export.png"),wxBITMAP_TYPE_PNG);

	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Centre( wxBOTH );
	int w,h;
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int dh=20;
	this->GetClientSize(&w,&h);
    wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

	panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPage = new wxPanel(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x1=7;
    y1=59;
    w1=w-x1*2;
    h1=h-114;
    panelHorizon = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelVertical = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelVertical->Show(false);
    panelHoff = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelHoff->Show(false);
    panelVoff = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelVoff->Show(false);
    panelMoff = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1),wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMoff->Show(false);

    x2=5;
    y2=2;
    w2=w1-x2*2;
    h2=28;
    heButton = new wxPanel(panelHorizon, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    heButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    y2=y2+h2-1;
    h2=(h1-y2-24)/2;
    helistHeader = new wxPanel(panelHorizon, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    helistHeader->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    helist = new wxListView(helistHeader, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    y2=y2+h2+8;
    h2=h2+15;
    heFig = new MyCanvas(panelHorizon, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x2=5;
    y2=2;
    w2=w1-x2*2;
    h2=28;
    veButton = new wxPanel(panelVertical, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    veButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    y2=y2+h2-1;
    h2=(h1-y2-24)/2;
    velistHeader = new wxPanel(panelVertical, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    velistHeader->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    velist = new wxListView(velistHeader, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    y2=y2+h2+8;
    h2=h2+15;
    veFig = new MyCanvas(panelVertical, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x2=5;
    y2=2;
    w2=w1-x2*2;
    h2=28;
    hoButton = new wxPanel(panelHoff, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    hoButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y2=y2+h2-1;
    h2=(h1-y2-24)/2;
    holistHeader = new wxPanel(panelHoff, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    holistHeader->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    holist = new wxListView(holistHeader, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    y2=y2+h2+8;
    h2=h2+15;
    hoFig = new MyCanvas(panelHoff, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x2=5;
    y2=2;
    w2=w1-x2*2;
    h2=28;
    voButton = new wxPanel(panelVoff, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    voButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y2=y2+h2-1;
    h2=(h1-y2-24)/2;
    volistHeader = new wxPanel(panelVoff, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    volistHeader->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    volist = new wxListView(volistHeader, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    y2=y2+h2+8;
    h2=h2+15;
    voFig = new MyCanvas(panelVoff, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    x2=5;
    y2=2;
    w2=w1-x2*2;
    h2=28;
    moButton = new wxPanel(panelMoff, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    moButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y2=y2+h2-1;
    h2=(h1-y2-24)/2;
    molistHeader = new wxPanel(panelMoff, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    molistHeader->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    molist = new wxListView(molistHeader, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    y2=y2+h2+8;
    h2=h2+15;
    moFig = new MyCanvas(panelMoff, wxID_ANY, wxPoint(x2,y2),wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelHorizon->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelVertical->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelHoff->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelVoff->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMoff->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintMain,0,this);
    panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DtaDlg::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DtaDlg::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DtaDlg::OnClickPage,0,this);
    panelHorizon->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintHorizon,0,this);
	heButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintheButton,0,this);
    heButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DtaDlg::OnMotionheButton,0,this);
    heButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DtaDlg::OnLeaveheButton,0,this);
    heButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DtaDlg::OnClickheButton,0,this);

    panelVertical->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintVertical,0,this);
    veButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintveButton,0,this);
    veButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DtaDlg::OnMotionveButton,0,this);
    veButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DtaDlg::OnLeaveveButton,0,this);
    veButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DtaDlg::OnClickveButton,0,this);

    panelHoff->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintHoff,0,this);
    hoButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPainthoButton,0,this);
    hoButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DtaDlg::OnMotionhoButton,0,this);
    hoButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DtaDlg::OnLeavehoButton,0,this);
    hoButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DtaDlg::OnClickhoButton,0,this);

    panelVoff->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintVoff,0,this);
    voButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintvoButton,0,this);
    voButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DtaDlg::OnMotionvoButton,0,this);
    voButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DtaDlg::OnLeavevoButton,0,this);
    voButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DtaDlg::OnClickvoButton,0,this);

    panelMoff->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintMoff,0,this);
    moButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintmoButton,0,this);
    moButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DtaDlg::OnMotionmoButton,0,this);
    moButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DtaDlg::OnLeavemoButton,0,this);
    moButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DtaDlg::OnClickmoButton,0,this);

    helistHeader->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintHlistHeader,0,this);

    helist->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&DtaDlg::OnListHelementSelect,0,this);
    helist->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&DtaDlg::OnListHelementDeselect,0,this);
    helist->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&DtaDlg::OnListHelementActivated,0,this);

    velistHeader->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintVelistHeader,0,this);
    velist->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&DtaDlg::OnListVelementSelect,0,this);
    velist->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&DtaDlg::OnListVelementDeselect,0,this);
    velist->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&DtaDlg::OnListVelementActivated,0,this);



    holistHeader->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintHolistHeader,0,this);

    holist->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&DtaDlg::OnListHoffActivated,0,this);
    holist->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&DtaDlg::OnListHoffSelect,0,this);
    holist->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&DtaDlg::OnListHoffDeselect,0,this);

    volistHeader->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintVolistHeader,0,this);

    volist->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&DtaDlg::OnListVoffSelect,0,this);
    volist->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&DtaDlg::OnListVoffDeselect,0,this);
    volist->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&DtaDlg::OnListVoffActivated,0,this);

    molistHeader->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintMolistHeader,0,this);
    molist->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&DtaDlg::OnListMoffSelect,0,this);
    molist->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&DtaDlg::OnListMoffDeselect,0,this);
    molist->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&DtaDlg::OnListMoffActivated,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&DtaDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&DtaDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&DtaDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&DtaDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    motion=ID_DTA_NONE;
    ipage=ID_DTA_PAGE_HE;
    btn_width=75;
    hSel=-1;
    hAct=0;
    vSel=-1;
    vAct=0;

    int i=0;
    helist->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,40);
    helist->InsertColumn(i++,_("类型"),wxLIST_FORMAT_RIGHT,70);
    helist->InsertColumn(i++,_("起点里程"),wxLIST_FORMAT_RIGHT,90);
    helist->InsertColumn(i++,_("线段长度"),wxLIST_FORMAT_RIGHT,70);
    helist->InsertColumn(i++,_("起点坐标X"),wxLIST_FORMAT_RIGHT,90);
    helist->InsertColumn(i++,_("起点坐标Y"),wxLIST_FORMAT_RIGHT,90);
    helist->InsertColumn(i++,_("起点半径"),wxLIST_FORMAT_RIGHT,70);
    helist->InsertColumn(i++,_("终点半径"),wxLIST_FORMAT_RIGHT,70);
    helist->InsertColumn(i++,_("起点方位角"),wxLIST_FORMAT_RIGHT,95);
    helist->InsertColumn(i++,_("偏转"),wxLIST_FORMAT_CENTER,50);

    i=0;
    velist->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,40);
    velist->InsertColumn(i++,_("类型"),wxLIST_FORMAT_RIGHT,70);
    velist->InsertColumn(i++,_("起点里程"),wxLIST_FORMAT_RIGHT,90);
    velist->InsertColumn(i++,_("起点高程"),wxLIST_FORMAT_RIGHT,70);
    velist->InsertColumn(i++,_("起点坡度"),wxLIST_FORMAT_RIGHT,90);
    velist->InsertColumn(i++,_("长度"),wxLIST_FORMAT_RIGHT,90);
    velist->InsertColumn(i++,_("半径"),wxLIST_FORMAT_RIGHT,95);
    velist->InsertColumn(i++,_("曲线形状"),wxLIST_FORMAT_CENTER,65);

    i=0;
    holist->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    holist->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,120);
    holist->InsertColumn(i++,_("偏移量"),wxLIST_FORMAT_CENTRE,120);

    i=0;
    volist->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    volist->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,120);
    volist->InsertColumn(i++,_("偏移量"),wxLIST_FORMAT_CENTRE,120);

    i=0;
    molist->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,75);
    molist->InsertColumn(i++,_("原里程"),wxLIST_FORMAT_CENTRE,120);
    molist->InsertColumn(i++,_("新里程"),wxLIST_FORMAT_CENTRE,120);
    molist->InsertColumn(i++,_("短链长度"),wxLIST_FORMAT_CENTRE,120);

    dog=0;
    modify=0;
    #ifdef WEBPC
    /*IO_PACKAGE input,output;
    time_t t1;
    char mac[4][13];
    int nMac=0;
    int bsense=0;
    int bi;

    nMac=GetMacAddress(mac,4);
    input.tag=CMD_GET_MACHINE_ID;
    input.len=12;
    time(&t1);
    srand(t1);


    for(bi=0;bi<12;bi++)
    {
        input.buff[bi]=rand() % 255;
    }
    if(DoSense("MEDO001","STGuider",&input,&output)==1)
    {
        //trace(0,"output=%s\n",output.buff);
        for(bi=0;bi<nMac;bi++)
        {
            if(strncmp(mac[bi],(const char*)output.buff,12)==0)
            {
                bsense=1;
                break;
            }
        }
    }*/
    int bsense=0;
    bsense=lock_sense(1,174);

    dog=bsense;
    #endif

    road_init(&r);
    r=mtg->r;

    dta_tip=_("中线输入所有里程值均为实际里程，不包含长短链！");

    UpdateHorizonList();

    UpdateVerticalList();
    UpdateHoffList();
    UpdateVoffList();
    UpdateMoffList();
    //heFig->SetGraphTitle(_("平曲线"));
    UpdateHorizonFig(true);
    UpdateVerticalFig(true);
    UpdateHoffFig(true);
    UpdateVoffFig(true);
    UpdateMoffFig(true);
}

DtaDlg::~DtaDlg()
{
    if(modify)
    {
        int nh,nv;
        nh=road_number_horizon(&mtg->r);
        nv=road_number_vertical(&mtg->r);
        if(nh>2)
        {
            h_element* h0={0};
            h0=road_horizon(&mtg->r,0);
            mtg->prj.mile1=h0->l1;
            h0=road_horizon(&mtg->r,nh-1);
            mtg->prj.mile2=h0->l1;
        }
        if(nv>2)
        {
            v_element* v0={0};
            v0=road_vertical(&mtg->r,0);
            if(mtg->prj.mile1>v0->l1)
                mtg->prj.mile1=v0->l1;
            v0=road_vertical(&mtg->r,nv-1);
            if(mtg->prj.mile2<v0->l1)
                mtg->prj.mile2=v0->l1;
        }
    }
}

void DtaDlg::OnPaintHlistHeader(wxPaintEvent& event)
{
    wxPaintDC dc(helistHeader);
    int w,h;
    helistHeader->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(130,135,144)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;
        int i=0;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=helist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=helist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=helist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起点里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=helist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("线段长度"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=helist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起点（X）"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=helist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起点（Y）"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=helist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起点半径"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=helist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("终点半径"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=helist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起点方位角"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=helist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("偏转"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);



        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnPaintHelementFig(wxPaintEvent& event)
{
    wxPaintDC dc(heFig);
    int w,h;
    heFig->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);



        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnPaintVelistHeader(wxPaintEvent& event)
{
    wxPaintDC dc(velistHeader);
    int w,h;
    velistHeader->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(130,135,144)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;
        int i=0;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=velist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=velist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=velist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起点里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=velist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起点高程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=velist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("起点坡度"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=velist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("长度"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=velist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("半径"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=velist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("曲线形状"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnPaintHolistHeader(wxPaintEvent& event)
{
    wxPaintDC dc(holistHeader);
    int w,h;
    holistHeader->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(130,135,144)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;
        int i=0;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=holist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=holist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=holist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("偏移量"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnPaintVolistHeader(wxPaintEvent& event)
{
    wxPaintDC dc(volistHeader);
    int w,h;
    volistHeader->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;
        int i=0;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=volist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=volist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=volist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("偏移量"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnPaintMolistHeader(wxPaintEvent& event)
{
    wxPaintDC dc(molistHeader);
    int w,h;
    molistHeader->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;
        int i=0;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=molist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=molist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("原里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=molist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("新里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1=x1+w1;
        w1=molist->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("长度"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::UpdateHorizonList()
{
    helist->DeleteAllItems();
    road* r=&mtg->r;
    int n=road_number_horizon(r);
    for(int i=0; i<n; i++)
    {
        helist->InsertItem(i,wxString::Format(_("%d"),i+1));
        h_element* h=road_horizon(r,i);

        helist->SetItem(i,2,wxString::Format(_("%.3f"),h->l1));

        /*int nmoff=road_number_mile_off(r);
        if(nmoff>0)
        {
            for(int j=nmoff-1;j>=0;j--)
            {
                m_offset *mo=road_mile_off(r,j);
                if(h->l1>=mo->mile)
                {
                    h->l1=h->l1+mo->off;
                    helist->SetItem(i,2,wxString::Format(_("%.3f"),h->l1));
                }
            }
        }*/
        helist->SetItem(i,4,wxString::Format(_("%.3f"),h->x1));
        helist->SetItem(i,5,wxString::Format(_("%.3f"),h->y1));
        helist->SetItem(i,8,R2DMMSS(h->angle1));
        //wxMessageBox(Radian_to_Angle(h->angle1));
        if(h->type==ROAD_TYPE_START_POINT)
        {
            helist->SetItem(i,1,wxT("起点"));
            helist->SetItem(i,2,wxString::Format(_("%.3f"),h->l1));
            helist->SetItem(i,4,wxString::Format(_("%.3f"),h->x1));
            helist->SetItem(i,5,wxString::Format(_("%.3f"),h->y1));
            helist->SetItem(i,8,R2DMMSS(h->angle1));
        }
        else if(h->type==ROAD_TYPE_LINE)
        {
            helist->SetItem(i,1,wxT("直线"));
            helist->SetItem(i,3,wxString::Format(_("%.3f"),h->length));
            helist->SetItem(i,8,R2DMMSS(h->angle1+h->deta));
        }
        else if(h->type==ROAD_TYPE_ARC)
        {
            helist->SetItem(i,1,wxT("圆曲线"));
            helist->SetItem(i,3,wxString::Format(_("%.3f"),h->length));
            helist->SetItem(i,6,wxString::Format(_("%.3f"),h->radius));
            helist->SetItem(i,7,wxString::Format(_("%.3f"),h->radius));
            if(h->pz==ROAD_LEFT)
            {
                helist->SetItem(i,9,_("左"));
            }
            else
            {
                helist->SetItem(i,9,_("右"));
            }

        }
        else if(h->type==ROAD_TYPE_SPIRAL)
        {
            helist->SetItem(i,1,wxT("缓和曲线"));
            helist->SetItem(i,3,wxString::Format(_("%.3f"),h->length));
            helist->SetItem(i,6,wxString::Format(_("%.3f"),h->rou1));
            helist->SetItem(i,7,wxString::Format(_("%.3f"),h->rou2));
            if(h->pz==ROAD_LEFT)
            {
                helist->SetItem(i,9,_("左"));
            }
            else
            {
                helist->SetItem(i,9,_("右"));
            }
        }
        else if(h->type==ROAD_TYPE_END_POINT)
        {
            helist->SetItem(i,1,wxT("终点"));
            helist->SetItem(i,2,wxString::Format(_("%.3f"),h->l1));
            helist->SetItem(i,4,wxString::Format(_("%.3f"),h->x1));
            helist->SetItem(i,5,wxString::Format(_("%.3f"),h->y1));
            helist->SetItem(i,8,R2DMMSS(h->angle1));
        }

    }
}

void DtaDlg::UpdateVerticalList()
{
    velist->DeleteAllItems();
    road* r=&mtg->r;
    int n=road_number_vertical(r);
    for(int i=0; i<n; i++)
    {
        velist->InsertItem(i,wxString::Format(_("%d"),i+1));
        v_element* v=road_vertical(r,i);
        velist->SetItem(i,2,wxString::Format(_("%.4f"),v->l1));

        /*int nmoff=road_number_mile_off(r);
        if(nmoff>0)
        {
            for(int j=nmoff-1;j>=0;j--)
            {
                m_offset *mo=road_mile_off(r,j);
                if(v->l1>=mo->mile)
                {
                    v->l1=v->l1+mo->off;
                    velist->SetItem(i,2,wxString::Format(_("%.3f"),v->l1));
                }
            }
        }*/

        velist->SetItem(i,3,wxString::Format(_("%.4f"),v->h1));
        velist->SetItem(i,4,wxString::Format(_("%.4f"),tan(v->angle1+v->deta)*1000.0));

        if(v->type==ROAD_TYPE_START_POINT)
        {
            velist->SetItem(i,1,wxT("起点"));
//            velist->SetItem(i,2,wxString::Format(_("%.4f"),v->l1));
//            velist->SetItem(i,3,wxString::Format(_("%.4f"),v->h1));
//            velist->SetItem(i,4,wxString::Format(_("%.4f"),tan(v->angle1)*100.0));
        }
        else if(v->type==ROAD_TYPE_LINE)
        {
            velist->SetItem(i,1,wxT("直线"));
            velist->SetItem(i,5,wxString::Format(_("%.4f"),v->length));
        }
        else if(v->type==ROAD_TYPE_ARC)
        {
            velist->SetItem(i,1,wxT("圆曲线"));
            velist->SetItem(i,5,wxString::Format(_("%.4f"),v->length));
            velist->SetItem(i,6,wxString::Format(_("%.4f"),v->radius));
            //velist->SetItem(n,7,dlg.Turn->GetStringSelection());
            if(v->pz==ROAD_LEFT)
            {
                velist->SetItem(i,7,_("上凸"));
            }
            else
            {
                velist->SetItem(i,7,_("下凹"));
            }

        }
        else if(v->type==ROAD_TYPE_END_POINT)
        {
            velist->SetItem(i,1,wxT("终点"));
        }
    }
}

void DtaDlg::UpdateHoffList()
{
    road* r=&mtg->r;
    int n=road_number_horizon_off(r);
    holist->DeleteAllItems();
    for(int i=0;i<n;i++)
    {
        h_offset* ho=road_horizon_off(r,i);
        holist->InsertItem(i,wxString::Format(_("%d"),i+1));
        holist->SetItem(i,1,wxString::Format(_("%.3f"),ho->mile));
        holist->SetItem(i,2,wxString::Format(_("%.3f"),ho->off));
    }
}

void DtaDlg::UpdateVoffList()
{
    road* r=&mtg->r;
    int n=road_number_vertical_off(r);
    volist->DeleteAllItems();
    for(int i=0;i<n;i++)
    {
        v_offset* vo=road_vertical_off(r,i);
        volist->InsertItem(i,wxString::Format(_("%d"),i+1));
        volist->SetItem(i,1,wxString::Format(_("%.3f"),vo->mile));
        volist->SetItem(i,2,wxString::Format(_("%.3f"),vo->off));
    }
}

void DtaDlg::UpdateMoffList()
{
    road* r=&mtg->r;
    int n=road_number_mile_off(r);
    molist->DeleteAllItems();
    for(int i=0;i<n;i++)
    {
        m_offset* mo=road_mile_off(r,i);
        molist->InsertItem(i,wxString::Format(_("%d"),i+1));
        molist->SetItem(i,1,wxString::Format(_("%.3f"),mo->mile));
        molist->SetItem(i,2,wxString::Format(_("%.3f"),mo->off+mo->mile));
        molist->SetItem(i,3,wxString::Format(_("%.3f"),mo->off));
    }
}

void DtaDlg::UpdateHorizonFig(bool fit)
{
    road* r=&mtg->r;
    int n=road_number_horizon(r);
    heFig->Clear();
    int i;
    double xi,yi;
    //double l;

    int npt=0;
    double *xy=0;

    for(i=0; i<n; i++)
    {
        h_element* e=road_horizon(r,i);
        //l=e->l1;
        if(e->type==ROAD_TYPE_LINE)
        {
            npt=2;
            xy=new double[4];
            //xy[0]=e->y1;
            //xy[1]=e->x1;
            road_l2xy(r,e->l1,&xy[1],&xy[0],0);
            //xy[2]=e->y2;
            //xy[3]=e->x2;
            road_l2xy(r,e->l1+e->length,&xy[3],&xy[2],0);
            heFig->AddPolyLine(npt,xy);
            delete xy;
            //heFig->AddLine(e->y1,e->x1,e->y2,e->x2);
        }
        else if(e->type==ROAD_TYPE_ARC || e->type==ROAD_TYPE_SPIRAL)
        {
            npt=21;
            //wxMessageBox(wxString::Format(wxT("npt=%d"),npt));
            xy=new double[2*npt];
            int index=0;
            //xy[2*index]=e->y1;
            //xy[2*index+1]=e->x1;
            road_l2xy(r,e->l1,&xy[2*index+1],&xy[2*index],0);
            index++;
            double l=e->l1+e->length/20.0;
            while(e->length >0.001  && l<e->l1+e->length)
            {
                road_l2xy(r,l,&xy[2*index+1],&xy[2*index],0);
                index++;
                if(index>=npt-1) break;
                l+=(e->length/20.0);
                //wxMessageBox(wxString::Format(wxT("index=%d"),index));
            }
            //xy[2*index]=e->y2;
            //xy[2*index+1]=e->x2;
            road_l2xy(r,e->l1+e->length,&xy[2*index+1],&xy[2*index],0);
            heFig->AddPolyLine(npt,xy);
            delete xy;
        }
        road_l2xy(r,e->l1+e->length,&xi,&yi,0);
        heFig->AddSymbol(yi,xi,0);
        wxString str;
        if(i==0)
        {
            str=_("QD");
        }
        else if(i==n-1)
        {
            str=_("ZD");
        }
        else if(i<n-2)
        {
            h_element* e1=road_horizon(r,i+1);
            if(e->type==ROAD_TYPE_LINE)
            {
                str+=_("Z");
            }
            else if(e->type==ROAD_TYPE_ARC)
            {
                str+=_("Y");
            }
            else if(e->type==ROAD_TYPE_SPIRAL)
            {
                str+=_("H");
            }
            if(e1->type==ROAD_TYPE_LINE)
            {
                str+=_("Z");
            }
            else if(e1->type==ROAD_TYPE_ARC)
            {
                str+=_("Y");
            }
            else if(e1->type==ROAD_TYPE_SPIRAL)
            {
                str+=_("H");
            }
        }

        heFig->AddText(str,yi,xi);
    }
    int sel=helist->GetFirstSelected();
    heFig->SelectPolyline(sel-1);
    if(fit)
    {
        heFig->FitAll();
    }
    else
    {
        heFig->ResetMapPoints();
    }
}

void DtaDlg::UpdateVerticalFig(bool fit)
{
    road* r=&mtg->r;
    int n=road_number_vertical(r);
    veFig->Clear();
    int i;

    int npt=0;
    double *xy=0;

    for(i=0; i<n; i++)
    {
        v_element* e=road_vertical(r,i);
        if(e->type==ROAD_TYPE_LINE)
        {
            npt=2;
            xy=new double[4];
            xy[0]=e->l1;
            xy[1]=e->h1;
            xy[2]=e->l2;
            xy[3]=e->h2;
            veFig->AddPolyLine(npt,xy);
            delete xy;
        }
        else if(e->type==ROAD_TYPE_ARC)
        {
            npt=21;
            xy=new double[2*npt];
            int index=0;
            xy[2*index]=e->l1;
            xy[2*index+1]=e->h1;
            index++;
            //double l=e->l1+e->length/20.0;
            double l=e->l1+e->hd/20.0;
            //while(e->length >0.001  && l<e->l2)
            while(e->hd >0.001  && l<e->l2)
            {
                xy[2*index]=l;
                road_l2h(r,l,&xy[2*index+1],0);
                index++;
                if(index>=npt-1) break;
                //l+=(e->length/20.0);
                l+=(e->hd/20.0);
            }
            xy[2*index]=e->l2;
            xy[2*index+1]=e->h2;

            veFig->AddPolyLine(npt,xy);
            delete xy;
        }


        veFig->AddSymbol(e->l2,e->h2,0);
        wxString str;
        if(i==0)
        {
            str=_("QD");
        }
        else if(i==n-1)
        {
            str=_("ZD");
        }
        else if(i<n-2)
        {
            v_element* e1=road_vertical(r,i+1);
            if(e->type==ROAD_TYPE_LINE)
            {
                str+=_("Z");
            }
            else if(e->type==ROAD_TYPE_ARC)
            {
                str+=_("Y");
            }

            if(e1->type==ROAD_TYPE_LINE)
            {
                str+=_("Z");
            }
            else if(e1->type==ROAD_TYPE_ARC)
            {
                str+=_("Y");
            }
        }
        veFig->AddText(str,e->l2,e->h2);
    }
    int sel=velist->GetFirstSelected();
    veFig->SelectPolyline(sel-1);
    if(fit)
    {
        veFig->FitAll();
    }
    else
    {
        veFig->ResetMapPoints();
    }
}

void DtaDlg::UpdateHoffFig(bool fit)
{
    road* r=&mtg->r;
    int n=road_number_horizon_off(r);
    hoFig->Clear();

    double x1,y1,x2,y2;
    for(int i=0;i<n;i++)
    {
        h_offset* ho=road_horizon_off(r,i);
        if(i==0)
        {
            x1=ho->mile;
            y1=ho->off;
        }
        else
        {
            x2=ho->mile;
            y2=ho->off;
            hoFig->AddLine(x1,y1,x2,y2);
            x1=x2;
            y1=y2;
        }
        hoFig->AddText(wxString::Format(_("%.3f"),ho->mile),x1,y1);
    }
    if(fit) hoFig->FitAll();
    else hoFig->ResetMapPoints();
}

void DtaDlg::UpdateVoffFig(bool fit)
{
    road* r=&mtg->r;
    int n=road_number_vertical_off(r);
    voFig->Clear();

    double x1,y1,x2,y2;
    for(int i=0;i<n;i++)
    {
        v_offset* vo=road_vertical_off(r,i);
        if(i==0)
        {
            x1=vo->mile;
            y1=vo->off;
        }
        else
        {
            x2=vo->mile;
            y2=vo->off;
            voFig->AddLine(x1,y1,x2,y2);
            x1=x2;
            y1=y2;
        }
        voFig->AddText(wxString::Format(_("%.3f"),vo->mile),x1,y1);
    }
    if(fit) voFig->FitAll();
    else voFig->ResetMapPoints();
}

void DtaDlg::UpdateMoffFig(bool fit)
{
    road* r=&mtg->r;
    int n=road_number_mile_off(r);
    moFig->Clear();

    double x1,y1,x2,y2;
    for(int i=0;i<n;i++)
    {
        m_offset* mo=road_mile_off(r,i);
        if(i==0)
        {
            x1=mo->mile;
            y1=mo->off;
        }
        else
        {
            x2=mo->mile;
            y2=mo->off;
            moFig->AddLine(x1,y1,x2,y2);
            x1=x2;
            y1=y2;
        }
        moFig->AddText(wxString::Format(_("%.3f"),mo->mile),x1,y1);
    }
    if(fit) moFig->FitAll();
    else moFig->ResetMapPoints();
}

void DtaDlg::OnListHelementSelect(wxListEvent& event)
{
    wxArrayInt sels=heFig->GetSelectedPolyLine();
    for(int i=0; i<sels.Count(); i++)
    {
        heFig->SelectPolyline(sels[i],false);
    }
    hSel=event.GetIndex();
    if(event.GetIndex()>=1)
    {
        heFig->SelectPolyline(event.GetIndex()-1);
        heFig->Refresh(false);
    }
    heButton->Refresh();
}

void DtaDlg::OnListHelementDeselect(wxListEvent& event)
{
    wxArrayInt sels=heFig->GetSelectedPolyLine();
    for(int i=0; i<sels.Count(); i++)
    {
        heFig->SelectPolyline(sels[i],false);
    }
    heFig->SelectPolyline(-1);
    heFig->Refresh(false);
    heButton->Refresh();
    hSel=-1;
}

void DtaDlg::OnListHelementActivated(wxListEvent& event)
{
    if(mtg->onLine!=0) return;
    hAct=1;
    motion=ID_DTA_HORIZON_EDI;
    wxMouseEvent e;
    OnClickheButton(e);
}

void DtaDlg::OnListVelementSelect(wxListEvent& event)
{
    wxArrayInt sels=veFig->GetSelectedPolyLine();
    for(int i=0; i<sels.Count(); i++)
    {
        veFig->SelectPolyline(sels[i],false);
    }
    vSel=event.GetIndex();
    if(vSel>=1)
    {
        veFig->SelectPolyline(vSel-1);
        veFig->Refresh(false);
    }
    veButton->Refresh();
}

void DtaDlg::OnListVelementDeselect(wxListEvent& event)
{
    wxArrayInt sels=veFig->GetSelectedPolyLine();
    for(int i=0; i<sels.Count(); i++)
    {
        veFig->SelectPolyline(sels[i],false);
    }
    veFig->SelectPolyline(-1);
    veFig->Refresh(false);
    veButton->Refresh();
    vSel=-1;
}

void DtaDlg::OnListVelementActivated(wxListEvent& event)
{
    if(mtg->onLine!=0) return;
    vAct=1;
    motion=ID_DTA_VERTICAL_EDI;
    wxMouseEvent e;
    OnClickveButton(e);
    //OnClickVbutton(e);
}

void DtaDlg::OnListHoffSelect(wxListEvent& event)
{
    hoButton->Refresh();
}

void DtaDlg::OnListHoffDeselect(wxListEvent& event)
{
    hoButton->Refresh();
}

void DtaDlg::OnListHoffActivated(wxListEvent& event)
{
    if(mtg->onLine == 0)
    {
        int sel=holist->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        OffDialog dlg(this);
        dlg.Type=OFF_TYPE_HORIZON;
        h_offset *ho=road_horizon_off(r,sel);
        dlg.Mile->SetValue(wxString::Format(_("%.3f"),ho->mile));
        dlg.Off->SetValue(wxString::Format(_("%.3f"),ho->off*1000.0));

        if(dlg.ShowModal()==wxID_OK)
        {
            h_offset ho1;
            dlg.Mile->GetValue().ToDouble(&ho1.mile);
            dlg.Off->GetValue().ToDouble(&ho1.off);
            ho1.off=ho1.off/1000.0;
            if(road_modify_horizon_off(r,&ho1,sel)==0)
            {
                modify=1;
                UpdateHoffList();
                UpdateHoffFig(true);
            }
        }
    }
}

void DtaDlg::OnListVoffSelect(wxListEvent& event)
{
    voButton->Refresh();
}

void DtaDlg::OnListVoffDeselect(wxListEvent& event)
{
    voButton->Refresh();
}

void DtaDlg::OnListVoffActivated(wxListEvent& event)
{
    if(mtg->onLine == 0)
    {
        int sel=volist->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        OffDialog dlg(this);
        dlg.Type=OFF_TYPE_VERTICAL;
        v_offset *vo=road_vertical_off(r,sel);
        dlg.Mile->SetValue(wxString::Format(_("%.3f"),vo->mile));
        dlg.Off->SetValue(wxString::Format(_("%.3f"),vo->off*1000.0));

        if(dlg.ShowModal()==wxID_OK)
        {
            v_offset vo1;
            dlg.Mile->GetValue().ToDouble(&vo1.mile);
            dlg.Off->GetValue().ToDouble(&vo1.off);
            vo1.off=vo1.off/1000.0;
            if(road_modify_vertical_off(r,&vo1,sel)==0)
            {
                modify=1;
                UpdateVoffList();
                UpdateVoffFig(true);
            }
        }
    }
}

void DtaDlg::OnListMoffSelect(wxListEvent& event)
{
    moButton->Refresh();
}

void DtaDlg::OnListMoffDeselect(wxListEvent& event)
{
    moButton->Refresh();
}

void DtaDlg::OnListMoffActivated(wxListEvent& event)
{
    if(mtg->onLine == 0)
    {
        int sel=molist->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        OffDialog dlg(this);
        dlg.Type=OFF_TYPE_MILE;
        m_offset *mo=road_mile_off(r,sel);
        dlg.Mile->SetValue(wxString::Format(_("%.3f"),mo->mile));
        dlg.Off->SetValue(wxString::Format(_("%.3f"),mo->mile+mo->off));

        if(dlg.ShowModal()==wxID_OK)
        {
            m_offset mo1;
            double m1;
            dlg.Mile->GetValue().ToDouble(&mo1.mile);
            dlg.Off->GetValue().ToDouble(&m1);
            mo1.off=m1-mo1.mile;
            if(road_modify_mile_off(r,&mo1,sel)==0)
            {
                UpdateMoffList();
                UpdateMoffFig(true);
            }
        }
    }
}

const wxString DtaDlg::GetCellString( int row, int col )
{
    wxListItem row_info;
    wxString str;
    row_info.m_itemId = row;
    row_info.m_col = col;
    row_info.m_mask = wxLIST_MASK_TEXT;
    if(ipage==ID_DTA_PAGE_HE)
    {
        helist->GetItem(row_info);
    }
    else if(ipage==ID_DTA_PAGE_VE)
    {
        velist->GetItem(row_info);
    }
    else if(ipage==ID_DTA_PAGE_HO)
    {
        holist->GetItem(row_info);
    }
    else if(ipage==ID_DTA_PAGE_VO)
    {
        volist->GetItem(row_info);
    }
    else if(ipage==ID_DTA_PAGE_MO)
    {
        molist->GetItem(row_info);
    }
    str = row_info.m_text;
    return str;
}

void DtaDlg::OnPaintBottom(wxPaintEvent& event)
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
        memDC.SetPen(wxPen(wxColor(117,117,117)));

        x1=9;
        y1=9;
        h1=26;
        w1=h1*4/3;

        dtaButton[ID_DTA_PRT_SCN].x=x1;
        dtaButton[ID_DTA_PRT_SCN].y=y1;
        dtaButton[ID_DTA_PRT_SCN].width=w1;
        dtaButton[ID_DTA_PRT_SCN].height=h1;
        if(motion==ID_DTA_PRT_SCN)
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

        x1=x1+w1+3;
        w1=32;
        dtaButton[ID_DTA_IMPORT].x=x1;
        dtaButton[ID_DTA_IMPORT].y=y1;
        dtaButton[ID_DTA_IMPORT].width=w1;
        dtaButton[ID_DTA_IMPORT].height=h1;
        if(motion==ID_DTA_IMPORT)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);

        }
        if(bmpImport.IsOk()) memDC.DrawBitmap(bmpImport,dtaButton[ID_DTA_IMPORT].x+w1/2-12,dtaButton[ID_DTA_IMPORT].y+h1/2-8);

        x1=x1+w1+3;
        dtaButton[ID_DTA_EMPORT].x=x1;
        dtaButton[ID_DTA_EMPORT].y=y1;
        dtaButton[ID_DTA_EMPORT].width=w1;
        dtaButton[ID_DTA_EMPORT].height=h1;
        if(motion==ID_DTA_EMPORT)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
        }
        if(bmpEmport.IsOk()) memDC.DrawBitmap(bmpEmport,dtaButton[ID_DTA_EMPORT].x+w1/2-12,dtaButton[ID_DTA_EMPORT].y+h1/2-8);

        w1=65;
        x1=w-w1-18;
        dtaButton[ID_DTA_BTN_QUIT].x=x1;
        dtaButton[ID_DTA_BTN_QUIT].y=y1;
        dtaButton[ID_DTA_BTN_QUIT].width=w1;
        dtaButton[ID_DTA_BTN_QUIT].height=h1;
        if(motion==ID_DTA_BTN_QUIT)
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

        x1=dtaButton[ID_DTA_EMPORT].x+dtaButton[ID_DTA_EMPORT].width+14;

        if(m_msgc==0)
        {
            memDC.SetTextForeground(wxColor(0,0,255));
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,0,0));
        }

        if(m_msg!=wxEmptyString)
        {
            memDC.DrawLabel(m_msg,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,0,0));
            memDC.DrawLabel(dta_tip,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>dtaButton[ID_DTA_BTN_QUIT].y && y<dtaButton[ID_DTA_BTN_QUIT].y+dtaButton[ID_DTA_BTN_QUIT].height)
    {
        if(x>dtaButton[ID_DTA_BTN_QUIT].x && x<dtaButton[ID_DTA_BTN_QUIT].x+dtaButton[ID_DTA_BTN_QUIT].width)
        {
            motion=ID_DTA_BTN_QUIT;
        }
        else if(x>dtaButton[ID_DTA_PRT_SCN].x && x<dtaButton[ID_DTA_PRT_SCN].x+dtaButton[ID_DTA_PRT_SCN].width)
        {
            motion=ID_DTA_PRT_SCN;
        }
        else if(x>dtaButton[ID_DTA_IMPORT].x && x<dtaButton[ID_DTA_IMPORT].x+dtaButton[ID_DTA_IMPORT].width)
        {
            motion=ID_DTA_IMPORT;
            //WriteMsg(_("导入中线数据!"),0);
        }
        else if(x>dtaButton[ID_DTA_EMPORT].x && x<dtaButton[ID_DTA_EMPORT].x+dtaButton[ID_DTA_EMPORT].width)
        {
            motion=ID_DTA_EMPORT;
            //WriteMsg(_("导出中线数据!"),0);
        }
        else
        {
            motion=ID_DTA_NONE;
            //m_msg=wxEmptyString;
        }
    }
    else
    {
        motion=ID_DTA_NONE;
        //m_msg=wxEmptyString;
    }
    panelBottom->Refresh();
}

void DtaDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_DTA_NONE;
    panelBottom->Refresh();
}

void DtaDlg::WriteMsg(wxString msg,int col)
{
    m_msg=msg;
    m_msgc=col;
    panelBottom->Refresh();
}

void DtaDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_DTA_BTN_QUIT)
    {
        if(mtg->onLine==0)
        {
            mtg_store_road(mtg);
        }
        Destroy();
    }
    else
    {   if(motion==ID_DTA_PRT_SCN)
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
            str=_("中线界面");
            str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
            wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
            if(dlg.ShowModal()==wxID_OK)
            {
                str=dlg.GetPath();
                bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
            }
        }
        if(mtg->onLine!=0) return;
        if(motion==ID_DTA_IMPORT)
        {
            wxFileDialog dlg(this,_("选择文件"),wxEmptyString,wxEmptyString,_("中线数据(*.db)|*.db"),wxFD_OPEN);
            dlg.Center();
            if(dlg.ShowModal()==wxID_OK)
            {
                wxString str=dlg.GetPath();
                char path[260];
                strcpy(path,str.mb_str(wxConvUTF8));
                if(road_import_file(&mtg->r,path)==0)
                {
                    wxMessageBox(_("导入成功！"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
                    //UpdateGraph();
                    UpdateHorizonList();
                    UpdateVerticalList();
                    UpdateHoffList();
                    UpdateVoffList();
                    UpdateMoffList();
                    UpdateHorizonFig(true);
                    UpdateVerticalFig(true);
                    UpdateHoffFig(true);
                    UpdateVoffFig(true);
                    UpdateMoffFig(true);
                    double l1=road_horizon(&mtg->r,0)->l1;
                    double l2=road_vertical(&mtg->r,0)->l1;
                    if(l1<=l2) mtg->prj.mile1=l2;
                    else mtg->prj.mile1=l1;
                    int n=road_number_horizon(&mtg->r);
                    l1=road_horizon(&mtg->r,n-1)->l1;
                    n=road_number_vertical(&mtg->r);
                    l2=road_vertical(&mtg->r,n-1)->l1;
                    if(l1<=l2) mtg->prj.mile2=l1;
                    else mtg->prj.mile2=l2;
                    mtg_store_prj(mtg);
                    //mtg_store_road(mtg);
                }
                else
                {
                    wxMessageBox(_("导入失败！"),_("提示"),wxOK|wxCENTER|wxICON_ERROR);
                }
            }
        }
        else if(motion==ID_DTA_EMPORT)
        {
            wxFileDialog dlg(this,_("选择中线数据导出文件"),wxEmptyString,wxEmptyString,_("中线数据文件(*.db)|*.db"),wxFD_SAVE);
            dlg.Center();
            if(dlg.ShowModal()==wxID_OK)
            {
                wxString str=dlg.GetPath();
                char path[260];
                strcpy(path,str.mb_str(wxConvUTF8));
                if(road_export_file(&mtg->r,path)==0)
                {
                    wxMessageBox(_("导出成功！"),_("提示"),wxOK|wxCENTER|wxICON_INFORMATION);
                    //UpdateGraph();
                }
                else
                {
                    wxMessageBox(_("导出失败！"),_("提示"),wxOK|wxCENTER|wxICON_ERROR);
                }
            }
        }
        panelBottom->Refresh();
    }
}

void DtaDlg::OnPaintMain(wxPaintEvent& event)
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

void DtaDlg::OnPaintPage(wxPaintEvent& event)
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
        dtaButton[ID_DTA_PAGE_HE].x=x1;
        dtaButton[ID_DTA_PAGE_HE].y=y1;
        dtaButton[ID_DTA_PAGE_HE].width=w1;
        dtaButton[ID_DTA_PAGE_HE].height=h1;

        if(ipage==ID_DTA_PAGE_HE || motion==ID_DTA_PAGE_HE)
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

            if(ipage!=ID_DTA_PAGE_HE)
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
        memDC.DrawLabel(_("平曲线要素"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);

        x1=x1+w1;
        dtaButton[ID_DTA_PAGE_VE].x=x1;
        dtaButton[ID_DTA_PAGE_VE].y=y1;
        dtaButton[ID_DTA_PAGE_VE].width=w1;
        dtaButton[ID_DTA_PAGE_VE].height=h1;
        if(ipage==ID_DTA_PAGE_VE || motion==ID_DTA_PAGE_VE)
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

            if(ipage!=ID_DTA_PAGE_VE)
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
        memDC.DrawLabel(_("竖曲线要素"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1+w1;
        dtaButton[ID_DTA_PAGE_HO].x=x1;
        dtaButton[ID_DTA_PAGE_HO].y=y1;
        dtaButton[ID_DTA_PAGE_HO].width=w1;
        dtaButton[ID_DTA_PAGE_HO].height=h1;
        if(ipage==ID_DTA_PAGE_HO || motion==ID_DTA_PAGE_HO)
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

            if(ipage!=ID_DTA_PAGE_HO)
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
        memDC.DrawLabel(_("平面偏移"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1+w1;
        dtaButton[ID_DTA_PAGE_VO].x=x1;
        dtaButton[ID_DTA_PAGE_VO].y=y1;
        dtaButton[ID_DTA_PAGE_VO].width=w1;
        dtaButton[ID_DTA_PAGE_VO].height=h1;
        if(ipage==ID_DTA_PAGE_VO || motion==ID_DTA_PAGE_VO)
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

            if(ipage!=ID_DTA_PAGE_VO)
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
        memDC.DrawLabel(_("垂直偏移"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1+w1;
        dtaButton[ID_DTA_PAGE_MO].x=x1;
        dtaButton[ID_DTA_PAGE_MO].y=y1;
        dtaButton[ID_DTA_PAGE_MO].width=w1;
        dtaButton[ID_DTA_PAGE_MO].height=h1;
        if(ipage==ID_DTA_PAGE_MO || motion==ID_DTA_PAGE_MO)
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

            if(ipage!=ID_DTA_PAGE_MO)
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
        memDC.DrawLabel(_("短链"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

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

void DtaDlg::OnMotionPage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>dtaButton[ID_DTA_PAGE_HE].y && y<dtaButton[ID_DTA_PAGE_HE].y+dtaButton[ID_DTA_PAGE_HE].height)
    {
        if(x>dtaButton[ID_DTA_PAGE_HE].x && x<dtaButton[ID_DTA_PAGE_HE].x+dtaButton[ID_DTA_PAGE_HE].width)
        {
            motion=ID_DTA_PAGE_HE;
        }
        else if(x>dtaButton[ID_DTA_PAGE_VE].x && x<dtaButton[ID_DTA_PAGE_VE].x+dtaButton[ID_DTA_PAGE_VE].width)
        {
            motion=ID_DTA_PAGE_VE;
        }
        else if(x>dtaButton[ID_DTA_PAGE_HO].x && x<dtaButton[ID_DTA_PAGE_HO].x+dtaButton[ID_DTA_PAGE_HO].width)
        {
            motion=ID_DTA_PAGE_HO;
        }
        else if(x>dtaButton[ID_DTA_PAGE_VO].x && x<dtaButton[ID_DTA_PAGE_VO].x+dtaButton[ID_DTA_PAGE_VO].width)
        {
            motion=ID_DTA_PAGE_VO;
        }
        else if(x>dtaButton[ID_DTA_PAGE_MO].x && x<dtaButton[ID_DTA_PAGE_MO].x+dtaButton[ID_DTA_PAGE_MO].width)
        {
            motion=ID_DTA_PAGE_MO;
        }
        else
        {
            motion=ID_DTA_NONE;
        }
    }
    else
    {
        motion=ID_DTA_NONE;
    }
    panelPage->Refresh();
}

void DtaDlg::OnLeavePage(wxMouseEvent& event)
{
    motion=ID_DTA_NONE;
    panelPage->Refresh();
}

void DtaDlg::OnClickPage(wxMouseEvent& event)
{
    if(motion==ID_DTA_PAGE_HE)
    {
        ipage=ID_DTA_PAGE_HE;
        panelHorizon->Show(true);
        panelVertical->Show(false);
        panelHoff->Show(false);
        panelVoff->Show(false);
        panelMoff->Show(false);
    }
    else if(motion==ID_DTA_PAGE_VE)
    {
        ipage=ID_DTA_PAGE_VE;
        panelHorizon->Show(false);
        panelVertical->Show(true);
        panelHoff->Show(false);
        panelVoff->Show(false);
        panelMoff->Show(false);
    }
    else if(motion==ID_DTA_PAGE_HO)
    {
        ipage=ID_DTA_PAGE_HO;
        panelHorizon->Show(false);
        panelVertical->Show(false);
        panelHoff->Show(true);
        panelVoff->Show(false);
        panelMoff->Show(false);
    }
    else if(motion==ID_DTA_PAGE_VO)
    {
        ipage=ID_DTA_PAGE_VO;
        panelHorizon->Show(false);
        panelVertical->Show(false);
        panelHoff->Show(false);
        panelVoff->Show(true);
        panelMoff->Show(false);
    }
    else if(motion==ID_DTA_PAGE_MO)
    {
        ipage=ID_DTA_PAGE_MO;
        panelHorizon->Show(false);
        panelVertical->Show(false);
        panelHoff->Show(false);
        panelVoff->Show(false);
        panelMoff->Show(true);
    }

    ///panelBottom->Refresh();
}

void DtaDlg::OnPaintHorizon(wxPaintEvent& event)
{
    wxPaintDC dc(panelHorizon);
    int w,h;
    panelHorizon->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnPaintheButton(wxPaintEvent& event)
{
    wxPaintDC dc(heButton);
    int w,h;
    heButton->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(112,118,112)));
        memDC.DrawLine(0,h-1,w,h-1);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int nh=road_number_horizon(&mtg->r);
        int n = helist->GetFirstSelected();

        int x1=0;
        int y1=0;
        int w1=btn_width;
        int h1=h-2;
        int r,g,b;
        int y2;

        dtaButton[ID_DTA_HORIZON_START_POINT].x=x1;
        dtaButton[ID_DTA_HORIZON_START_POINT].y=y1;
        dtaButton[ID_DTA_HORIZON_START_POINT].width=w1;
        dtaButton[ID_DTA_HORIZON_START_POINT].height=h1;
        if(motion==ID_DTA_HORIZON_START_POINT)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=200;
            g=225;
            b=250;

            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
        }
        memDC.DrawLabel(_("起  点"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_HORIZON_LINE].x=x1;
        dtaButton[ID_DTA_HORIZON_LINE].y=y1;
        dtaButton[ID_DTA_HORIZON_LINE].width=w1;
        dtaButton[ID_DTA_HORIZON_LINE].height=h1;
        if(motion==ID_DTA_HORIZON_LINE)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=200;
            g=225;
            b=250;

            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
        }
        memDC.DrawLabel(_("直  线"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_HORIZON_ARC].x=x1;
        dtaButton[ID_DTA_HORIZON_ARC].y=y1;
        dtaButton[ID_DTA_HORIZON_ARC].width=w1;
        dtaButton[ID_DTA_HORIZON_ARC].height=h1;
        if(motion==ID_DTA_HORIZON_ARC)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=200;
            g=225;
            b=250;

            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
        }
        memDC.DrawLabel(_("圆曲线"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_HORIZON_SPIRAL].x=x1;
        dtaButton[ID_DTA_HORIZON_SPIRAL].y=y1;
        dtaButton[ID_DTA_HORIZON_SPIRAL].width=w1;
        dtaButton[ID_DTA_HORIZON_SPIRAL].height=h1;
        if(motion==ID_DTA_HORIZON_SPIRAL)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=200;
            g=225;
            b=250;

            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
        }
        memDC.DrawLabel(_("缓和曲线"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_HORIZON_EDI].x=x1;
        dtaButton[ID_DTA_HORIZON_EDI].y=y1;
        dtaButton[ID_DTA_HORIZON_EDI].width=w1;
        dtaButton[ID_DTA_HORIZON_EDI].height=h1;
        if(n>=0 && n<nh-1)
        {
            if(motion==ID_DTA_HORIZON_EDI)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=200;
                g=225;
                b=250;

                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

                }
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=215;
                g=215;
                b=215;
                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                    r++;
                    g++;
                    b++;
                }
            }
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawLabel(_("编  辑"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_HORIZON_DEL].x=x1;
        dtaButton[ID_DTA_HORIZON_DEL].y=y1;
        dtaButton[ID_DTA_HORIZON_DEL].width=w1;
        dtaButton[ID_DTA_HORIZON_DEL].height=h1;
        if(n>=1 && n<nh-1)
        {
            if(motion==ID_DTA_HORIZON_DEL)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=200;
                g=225;
                b=250;

                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

                }
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=215;
                g=215;
                b=215;
                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                    r++;
                    g++;
                    b++;
                }
            }
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawLabel(_("删  除"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnMotionheButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>dtaButton[ID_DTA_HORIZON_START_POINT].y && y<dtaButton[ID_DTA_HORIZON_START_POINT].y+dtaButton[ID_DTA_HORIZON_START_POINT].height)
    {
        if(x>dtaButton[ID_DTA_HORIZON_START_POINT].x && x<dtaButton[ID_DTA_HORIZON_START_POINT].x+dtaButton[ID_DTA_HORIZON_START_POINT].width)
        {
            motion=ID_DTA_HORIZON_START_POINT;
        }
        else if(x>dtaButton[ID_DTA_HORIZON_LINE].x && x<dtaButton[ID_DTA_HORIZON_LINE].x+dtaButton[ID_DTA_HORIZON_LINE].width)
        {
            motion=ID_DTA_HORIZON_LINE;
        }
        else if(x>dtaButton[ID_DTA_HORIZON_ARC].x && x<dtaButton[ID_DTA_HORIZON_ARC].x+dtaButton[ID_DTA_HORIZON_ARC].width)
        {
            motion=ID_DTA_HORIZON_ARC;
        }
        else if(x>dtaButton[ID_DTA_HORIZON_SPIRAL].x && x<dtaButton[ID_DTA_HORIZON_SPIRAL].x+dtaButton[ID_DTA_HORIZON_SPIRAL].width)
        {
            motion=ID_DTA_HORIZON_SPIRAL;
        }
        else if(x>dtaButton[ID_DTA_HORIZON_EDI].x && x<dtaButton[ID_DTA_HORIZON_EDI].x+dtaButton[ID_DTA_HORIZON_EDI].width)
        {
            motion=ID_DTA_HORIZON_EDI;
        }
        else if(x>dtaButton[ID_DTA_HORIZON_DEL].x && x<dtaButton[ID_DTA_HORIZON_DEL].x+dtaButton[ID_DTA_HORIZON_DEL].width)
        {
            motion=ID_DTA_HORIZON_DEL;
        }
        else
        {
            motion=ID_DTA_NONE;
        }
    }
    else
    {
        motion=ID_DTA_NONE;
    }

    heButton->Refresh();
}

void DtaDlg::OnLeaveheButton(wxMouseEvent& event)
{
    motion=ID_DTA_NONE;
    heButton->Refresh();
}

void DtaDlg::OnClickheButton(wxMouseEvent& event)
{
    if(mtg->onLine!=0) return;
    if(motion==ID_DTA_HORIZON_START_POINT)
    {
        H_StartPoint dlg(this);
        dlg.Center();
        road * r=&mtg->r;
        h_element h={0};
        int nh=road_number_horizon(r);
        wxString str;
        if(nh>0)
        {
            h_element* he=road_horizon(r,0);
            dlg.mile->SetValue(wxString::Format(_("%.4f"),he->l1));
            dlg.m_x->SetValue(wxString::Format(_("%.4f"),he->x1));
            dlg.m_y->SetValue(wxString::Format(_("%.4f"),he->y1));
            str=Radian_to_Angle(he->angle1);
            dlg.azi->SetValue(AngleConver(str));
            dlg.mile->SetFocus();
        }

        if(dlg.ShowModal()==wxID_OK)
        {
            h.type = ROAD_TYPE_START_POINT;
            h.angle1 = Angle_to_Radian(dlg.azi->GetValue());
            dlg.mile->GetValue().ToDouble(&h.l1);
            dlg.m_x->GetValue().ToDouble(&h.x1);
            dlg.m_y->GetValue().ToDouble(&h.y1);
            if(nh<=0)
            {
                road_insert_horizon(r,&h,0);
                road_apply_horizon(r);
                modify=1;
            }
            else
            {
                road_modify_horizon(r,&h,0);
                road_apply_horizon(r);
                modify=1;
            }
            UpdateHorizonList();
            helist->Select(0);
            UpdateHorizonFig(true);
        }
    }
    else if(motion==ID_DTA_HORIZON_LINE)
    {
        road * r=&mtg->r;
        int nh=road_number_horizon(r)-1;
        int n = helist->GetFirstSelected();
        if(n>=0 && n<nh)
        {
            nh=n+1;
        }
        h_element *ph=road_horizon(r,nh-1);
        double azi1,azi2;
        H_Line dlg(this);
        azi1=ph->angle2;
        dlg.L->SetFocus();
        dlg.azi->SetValue(Radian_to_point_Angle(azi1));
        dlg.Center();
        h_element h={0};

        if(dlg.ShowModal()==wxID_OK)
        {
            h.type = ROAD_TYPE_LINE;
            dlg.L->GetValue().ToDouble(&h.length);
            azi2=Angle_to_Radian(dlg.azi->GetValue());
            h.deta=azi2-azi1;
            road_insert_horizon(r,&h,nh);
            road_apply_horizon(r);
            UpdateHorizonList();
            helist->Select(nh);
            UpdateHorizonFig(true);
            modify=1;
        }
    }
    else if(motion==ID_DTA_HORIZON_ARC)
    {
        H_Round dlg(this);
        dlg.Center();
        road * r=&mtg->r;
        h_element h={0};

        int nh=road_number_horizon(r)-1;
        int n = helist->GetFirstSelected();
        if(n>=0 && n<nh)
        {
            nh=n+1;
        }

        h_element *ph=road_horizon(r,nh-1);
        if(ph->type==ROAD_TYPE_SPIRAL)
        {
            if(ph->rou2>ph->rou1)
            {
                dlg.R->SetValue(wxString::Format(_("%.4f"),ph->rou2));
                if(ph->pz==ROAD_RIGHT) dlg.Turn=1;
                dlg.L->SetFocus();
            }
            else
            {
                dlg.R->SetFocus();
            }
        }
        else
        {
            dlg.R->SetFocus();
        }

        if(dlg.ShowModal()==wxID_OK)
        {
            h.type = ROAD_TYPE_ARC;
            dlg.R->GetValue().ToDouble(&h.radius);
            dlg.L->GetValue().ToDouble(&h.length);
            if(dlg.Turn == 0)
                h.pz = ROAD_LEFT;
            else
                h.pz = ROAD_RIGHT;

            h.rou1=h.rou2=1/h.radius;
            road_insert_horizon(r,&h,nh);
            road_apply_horizon(r);

            UpdateHorizonList();
            helist->Select(nh);
            UpdateHorizonFig(true);
            modify=1;
        }
    }
    else if(motion==ID_DTA_HORIZON_SPIRAL)
    {
        H_Moderate dlg(this);
        dlg.Center();
        road * r=&mtg->r;
        h_element h={0};
        int nh=road_number_horizon(r)-1;
        int n = helist->GetFirstSelected();
        if(n>=0 && n<nh)
        {
            nh=n+1;
        }
        h_element *ph=road_horizon(r,nh-1);
        if(ph->type==ROAD_TYPE_ARC)
        {
            if(nh>2)
            {
                ph=road_horizon(r,nh-2);
                if(ph->type==ROAD_TYPE_SPIRAL)
                {
                    dlg.R1->SetValue(wxString::Format(_("%.4f"),ph->rou2));
                    dlg.R2->SetValue(wxString::Format(_("%.4f"),ph->rou1));
                    dlg.L->SetValue(wxString::Format(_("%.4f"),ph->length));
                    if(ph->pz==ROAD_RIGHT)
                    {
                        dlg.Turn=1;
                    }
                }
                else
                {
                    dlg.R1->SetFocus();
                }
            }
            else
            {
                dlg.R1->SetFocus();
            }
        }
        else if(ph->type==ROAD_TYPE_SPIRAL)
        {
            if(nh>2)
            {
                if(road_horizon(r,nh-2)->type==ROAD_TYPE_LINE)
                {
                    dlg.R1->SetValue(wxString::Format(_("%.4f"),ph->rou2));
                    dlg.R2->SetValue(wxString::Format(_("%.4f"),ph->rou1));
                    dlg.L->SetValue(wxString::Format(_("%.4f"),ph->length));
                    if(ph->pz==ROAD_RIGHT) dlg.Turn=1;
                }
                else
                {
                    dlg.R1->SetFocus();
                }
            }
            else
            {
                dlg.R1->SetFocus();
            }
        }
        else
        {
            dlg.R1->SetFocus();
        }


        if(dlg.ShowModal()==wxID_OK)
        {
            h.type = ROAD_TYPE_SPIRAL;
            dlg.R1->GetValue().ToDouble(&h.rou1);
            dlg.R2->GetValue().ToDouble(&h.rou2);
            dlg.L->GetValue().ToDouble(&h.length);
            if(dlg.Turn == 0)
                h.pz = ROAD_LEFT;
            else
                h.pz = ROAD_RIGHT;

            road_insert_horizon(r,&h,nh);
            road_apply_horizon(r);

            UpdateHorizonList();
            helist->Select(nh);
            UpdateHorizonFig(true);

            modify=1;
        }
    }
    else if(motion==ID_DTA_HORIZON_EDI)
    {
        int n = helist->GetFirstSelected();
        int Num = helist->GetItemCount();

        if(n<0 || n>=Num-1) return;

        H_StartPoint dlg_P(this);
        H_Line dlg_L(this);
        H_Round dlg_R(this);
        H_Moderate dlg_M(this);
        dlg_P.Center();
        dlg_L.Center();
        dlg_R.Center();
        dlg_M.Center();

        road * r=&mtg->r;
        h_element h={0};
        h_element* he=road_horizon(r,n);
        h=*he;
        wxString type = GetCellString(n,1);
        wxString str;
        if(type == wxT("起点"))
        {
            dlg_P.mile->SetValue(wxString::Format(_("%.4f"),he->l1));
            dlg_P.m_x->SetValue(wxString::Format(_("%.4f"),he->x1));
            dlg_P.m_y->SetValue(wxString::Format(_("%.4f"),he->y1));
            str=Radian_to_Angle(he->angle1);
            dlg_P.azi->SetValue(AngleConver(str));
            if(dlg_P.ShowModal()==wxID_OK)
            {
                h.type = ROAD_TYPE_START_POINT;
                h.angle1 = Angle_to_Radian(dlg_P.azi->GetValue());
                dlg_P.mile->GetValue().ToDouble(&h.l1);
                dlg_P.m_x->GetValue().ToDouble(&h.x1);
                dlg_P.m_y->GetValue().ToDouble(&h.y1);
                road_modify_horizon(r,&h,n);
                road_apply_horizon(r);

                modify=1;
            }
        }
        else if(type == wxT("直线"))
        {
            dlg_L.L->SetValue(wxString::Format(_("%.4f"),he->length));
            str=Radian_to_Angle(he->angle1);
            dlg_L.azi->SetValue(AngleConver(str));
            double azi1=Angle_to_Radian(AngleConver(str));

            if(dlg_L.ShowModal()==wxID_OK)
            {
                h.type = ROAD_TYPE_LINE;
                dlg_L.L->GetValue().ToDouble(&h.length);
                h.deta = road_horizon(r,n)->deta+Angle_to_Radian(dlg_L.azi->GetValue())-azi1;
                road_modify_horizon(r,&h,n);
                road_apply_horizon(r);

                modify=1;
            }
        }
        else if(type == wxT("圆曲线"))
        {
            dlg_R.R->SetValue(wxString::Format(_("%.4f"),he->radius));
            dlg_R.L->SetValue(wxString::Format(_("%.4f"),he->length));
            if(he->pz==ROAD_LEFT)
                dlg_R.Turn=0;
            else
                dlg_R.Turn=1;

            if(dlg_R.ShowModal()==wxID_OK)
            {
                h.type = ROAD_TYPE_ARC;
                dlg_R.R->GetValue().ToDouble(&h.radius);
                dlg_R.L->GetValue().ToDouble(&h.length);
                if(dlg_R.Turn == 0)
                    h.pz = ROAD_LEFT;
                else
                    h.pz = ROAD_RIGHT;
                road_modify_horizon(r,&h,n);
                road_apply_horizon(r);

                modify=1;
            }
        }
        else if(type == wxT("缓和曲线"))
        {
            dlg_M.R1->SetValue(wxString::Format(_("%.4f"),he->rou1));
            dlg_M.R2->SetValue(wxString::Format(_("%.4f"),he->rou2));
            dlg_M.L->SetValue(wxString::Format(_("%.4f"),he->length));

            if(he->pz == ROAD_LEFT)
                dlg_M.Turn=0;
            else
                dlg_M.Turn=1;
            if(dlg_M.ShowModal() == wxID_OK)
            {
                h.type = ROAD_TYPE_SPIRAL;
                dlg_M.R1->GetValue().ToDouble(&h.rou1);
                dlg_M.R2->GetValue().ToDouble(&h.rou2);
                dlg_M.L->GetValue().ToDouble(&h.length);
                if(dlg_M.Turn == 0)
                    h.pz = ROAD_LEFT;
                else
                    h.pz = ROAD_RIGHT;
                road_modify_horizon(r,&h,n);
                road_apply_horizon(r);

                modify=1;
            }
        }

        UpdateHorizonList();
        helist->Select(n);
        UpdateHorizonFig(true);
        hAct=0;
        motion=ID_DTA_NONE;
    }
    else if(motion==ID_DTA_HORIZON_DEL)
    {
        int n = helist->GetFirstSelected();
        int Num = helist->GetItemCount();
        if(n<=0 || n>=Num-1) return;
        ConfirmDlg dlg(this);
        dlg.confirmMsg=_("删除操作将不可恢复\n确定要进行删除吗？");
        //wxMessageDialog dlg(this,_("删除操作将不可恢复\n确定要进行删除吗？"),_("平曲线要素"),wxYES_NO|wxICON_INFORMATION);
        if(dlg.ShowModal()==wxID_OK)
        {
            road * r=&mtg->r;
            road_remove_horizon(r,n);
            road_apply_horizon(r);
            UpdateHorizonList();
            if(n==Num-2)
            {
                helist->Select(n-1);
            }
            else
            {
                helist->Select(n);
            }

            UpdateHorizonFig(true);

            modify=1;
        }
    }
    heButton->Refresh();
}

void DtaDlg::OnPaintVertical(wxPaintEvent& event)
{
    wxPaintDC dc(panelVertical);
    int w,h;
    panelVertical->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnPaintveButton(wxPaintEvent& event)
{
    wxPaintDC dc(veButton);
    int w,h;
    veButton->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(112,118,112)));
        memDC.DrawLine(0,h-1,w,h-1);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int nv=road_number_vertical(&mtg->r);
        int n = velist->GetFirstSelected();

        int x1=0;
        int y1=0;
        int w1=btn_width;
        int h1=h-2;
        int r,g,b;
        int y2;

        dtaButton[ID_DTA_VERTICAL_START_POINT].x=x1;
        dtaButton[ID_DTA_VERTICAL_START_POINT].y=y1;
        dtaButton[ID_DTA_VERTICAL_START_POINT].width=w1;
        dtaButton[ID_DTA_VERTICAL_START_POINT].height=h1;
        if(motion==ID_DTA_VERTICAL_START_POINT)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=200;
            g=225;
            b=250;

            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
        }
        memDC.DrawLabel(_("起  点"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_VERTICAL_LINE].x=x1;
        dtaButton[ID_DTA_VERTICAL_LINE].y=y1;
        dtaButton[ID_DTA_VERTICAL_LINE].width=w1;
        dtaButton[ID_DTA_VERTICAL_LINE].height=h1;
        if(motion==ID_DTA_VERTICAL_LINE)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=200;
            g=225;
            b=250;

            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
        }
        memDC.DrawLabel(_("直  线"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_VERTICAL_ARC].x=x1;
        dtaButton[ID_DTA_VERTICAL_ARC].y=y1;
        dtaButton[ID_DTA_VERTICAL_ARC].width=w1;
        dtaButton[ID_DTA_VERTICAL_ARC].height=h1;
        if(motion==ID_DTA_VERTICAL_ARC)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=200;
            g=225;
            b=250;

            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
        }
        memDC.DrawLabel(_("圆曲线"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_VERTICAL_EDI].x=x1;
        dtaButton[ID_DTA_VERTICAL_EDI].y=y1;
        dtaButton[ID_DTA_VERTICAL_EDI].width=w1;
        dtaButton[ID_DTA_VERTICAL_EDI].height=h1;
        if(n>=0 && n<nv-1)
        {
            if(motion==ID_DTA_VERTICAL_EDI)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=200;
                g=225;
                b=250;

                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

                }
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=215;
                g=215;
                b=215;
                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                    r++;
                    g++;
                    b++;
                }
            }
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawLabel(_("编  辑"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_VERTICAL_DEL].x=x1;
        dtaButton[ID_DTA_VERTICAL_DEL].y=y1;
        dtaButton[ID_DTA_VERTICAL_DEL].width=w1;
        dtaButton[ID_DTA_VERTICAL_DEL].height=h1;
        if(n>0 && n<nv-1)
        {
            if(motion==ID_DTA_VERTICAL_DEL)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=200;
                g=225;
                b=250;

                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

                }
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=215;
                g=215;
                b=215;
                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                    r++;
                    g++;
                    b++;
                }
            }
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawLabel(_("删  除"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnMotionveButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>dtaButton[ID_DTA_VERTICAL_START_POINT].y && y<dtaButton[ID_DTA_VERTICAL_START_POINT].y+dtaButton[ID_DTA_VERTICAL_START_POINT].height)
    {
        if(x>dtaButton[ID_DTA_VERTICAL_START_POINT].x && x<dtaButton[ID_DTA_VERTICAL_START_POINT].x+dtaButton[ID_DTA_VERTICAL_START_POINT].width)
        {
            motion=ID_DTA_VERTICAL_START_POINT;
        }
        else if(x>dtaButton[ID_DTA_VERTICAL_LINE].x && x<dtaButton[ID_DTA_VERTICAL_LINE].x+dtaButton[ID_DTA_VERTICAL_LINE].width)
        {
            motion=ID_DTA_VERTICAL_LINE;
        }
        else if(x>dtaButton[ID_DTA_VERTICAL_ARC].x && x<dtaButton[ID_DTA_VERTICAL_ARC].x+dtaButton[ID_DTA_VERTICAL_ARC].width)
        {
            motion=ID_DTA_VERTICAL_ARC;
        }
        else if(x>dtaButton[ID_DTA_VERTICAL_EDI].x && x<dtaButton[ID_DTA_VERTICAL_EDI].x+dtaButton[ID_DTA_VERTICAL_EDI].width)
        {
            motion=ID_DTA_VERTICAL_EDI;
        }
        else if(x>dtaButton[ID_DTA_VERTICAL_DEL].x && x<dtaButton[ID_DTA_VERTICAL_DEL].x+dtaButton[ID_DTA_VERTICAL_DEL].width)
        {
            motion=ID_DTA_VERTICAL_DEL;
        }
        else
        {
            motion=ID_DTA_NONE;
        }
    }
    else
    {
        motion=ID_DTA_NONE;
    }

    veButton->Refresh();
}

void DtaDlg::OnLeaveveButton(wxMouseEvent& event)
{
    motion=ID_DTA_NONE;
    veButton->Refresh();
}

void DtaDlg::OnClickveButton(wxMouseEvent& event)
{
    if(mtg->onLine!=0) return;
    if(motion==ID_DTA_VERTICAL_START_POINT)
    {
        V_StartPoint dlg(this);
        dlg.Center();
        road * r=&mtg->r;
        v_element v={0};
        int nv = road_number_vertical(r);
        if(nv>0)
        {
            v_element* ve=road_vertical(r,0);
            dlg.L->SetValue(wxString::Format(_("%.4f"),ve->l1));
            dlg.H->SetValue(wxString::Format(_("%.4f"),ve->h1));
            dlg.i->SetValue(wxString::Format(_("%.4f"),tan(ve->angle1)*1000.0));
        }

        if(dlg.ShowModal()==wxID_OK)
        {
            double i;
            v.type = ROAD_TYPE_START_POINT;
            dlg.L->GetValue().ToDouble(&v.l1);
            dlg.H->GetValue().ToDouble(&v.h1);
            dlg.i->GetValue().ToDouble(&i);
            v.angle1 = atan(i/1000.0);
            if(nv<=0)
            {
                road_insert_vertical(r,&v,0);
                road_apply_vertical(r);
            }
            else
            {
                road_modify_vertical(r,&v,0);
                road_apply_vertical(r);
            }
            UpdateVerticalList();
            velist->Select(0);
            UpdateVerticalFig(true);

            modify=1;
        }
    }
    else if(motion==ID_DTA_VERTICAL_LINE)
    {
        road * r=&mtg->r;
        int nv = road_number_vertical(r)-1;
        int n=velist->GetFirstSelected();
        if(n>=0 && n<nv)
        {
            nv=n+1;
        }
        double ori1,ori2;
        v_element* pv=road_vertical(r,nv-1);
        ori1=pv->angle2;

        V_Line dlg(this);
        dlg.i->SetValue(wxString::Format(_("%.4f"),tan(ori1)*1000.0));
        dlg.L->SetFocus();
        dlg.Center();

        v_element v={0};

        if(dlg.ShowModal()==wxID_OK)
        {
            v.type = ROAD_TYPE_LINE;
            dlg.L->GetValue().ToDouble(&v.length);
            dlg.i->GetValue().ToDouble(&ori2);
            ori2=atan(ori2/1000.0);
            v.deta=ori2-ori1;
            road_insert_vertical(r,&v,nv);
            road_apply_vertical(r);
            UpdateVerticalList();
            velist->Select(nv);
            UpdateVerticalFig(true);

            modify=1;
        }
    }
    else if(motion==ID_DTA_VERTICAL_ARC)
    {
        V_Round dlg(this);
        dlg.R->SetFocus();
        dlg.Center();
        road * r=&mtg->r;
        v_element v={0};

        if(dlg.ShowModal()==wxID_OK)
        {
            v.type = ROAD_TYPE_ARC;
            dlg.R->GetValue().ToDouble(&v.radius);
            dlg.L->GetValue().ToDouble(&v.length);
            v.T=v.length/2.0;
            if(dlg.Turn== 0)
                v.pz = ROAD_UP;
            else
                v.pz = ROAD_DOWN;
            int nv = road_number_vertical(r)-1;
            int n=velist->GetFirstSelected();
            if(n>=0 && n<nv)
            {
                nv=n+1;
            }
            road_insert_vertical(r,&v,nv);
            road_apply_vertical(r);

            UpdateVerticalList();
            velist->Select(nv);
            UpdateVerticalFig(true);

            modify=1;
        }

    }
    else if(motion==ID_DTA_VERTICAL_EDI)
    {
        int n = velist->GetFirstSelected();
        int Num = velist->GetItemCount();
        if(n<0 || n>=Num-1) return;

        if(n<0) return;

        V_StartPoint dlg_P(this);
        V_Line dlg_L(this);
        V_Round dlg_R(this);
        dlg_P.Center();
        dlg_L.Center();
        dlg_R.Center();

        road * r=&mtg->r;
        v_element v={0};
        v_element* ve=road_vertical(r,n);
        v=*ve;
        wxString type = GetCellString(n,1);

        if(type == wxT("起点"))
        {
            dlg_P.L->SetValue(wxString::Format(_("%.4f"),ve->l1));
            dlg_P.H->SetValue(wxString::Format(_("%.4f"),ve->h1));
            dlg_P.i->SetValue(wxString::Format(_("%.4f"),tan(ve->angle1)*1000.0));
            if(dlg_P.ShowModal() == wxID_OK)
            {
                double i;
                v.type = ROAD_TYPE_START_POINT;
                dlg_P.L->GetValue().ToDouble(&v.l1);
                dlg_P.H->GetValue().ToDouble(&v.h1);
                dlg_P.i->GetValue().ToDouble(&i);
                v.angle1 = atan(i/1000.0);
                road_modify_vertical(r,&v,n);
                road_apply_vertical(r);

                modify=1;
            }
        }
        else if(type == wxT("直线"))
        {
            dlg_L.L->SetValue(wxString::Format(_("%.4f"),ve->length));
            dlg_L.i->SetValue(wxString::Format(_("%.4f"),tan(ve->angle1)*1000.0));
            double ori1=tan(ve->angle1)*1000.0;

            if(dlg_L.ShowModal()==wxID_OK)
            {
                v.type = ROAD_TYPE_LINE;
                double ori2=0.0;
                dlg_L.i->GetValue().ToDouble(&ori2);
                v.deta=ve->deta+atan(ori2/1000.0)-atan(ori1/1000.0);
                //dlg_L.deta = Angle_to_Radian()-ori1;
                dlg_L.L->GetValue().ToDouble(&v.length);
                road_modify_vertical(r,&v,n);
                road_apply_vertical(r);

                modify=1;
            }
        }
        else if(type == wxT("圆曲线"))
        {
            dlg_R.L->SetValue(wxString::Format(_("%.4f"),ve->length));
            dlg_R.R->SetValue(wxString::Format(_("%.4f"),ve->radius));
            if(ve->pz==ROAD_UP)
                dlg_R.Turn=0;
            else
                dlg_R.Turn=1;

            if(dlg_R.ShowModal()==wxID_OK)
            {
                v.type = ROAD_TYPE_ARC;
                dlg_R.L->GetValue().ToDouble(&v.length);
                dlg_R.R->GetValue().ToDouble(&v.radius);
                v.T=v.length/2.0;
                if(dlg_R.Turn == 0)
                    v.pz = ROAD_UP;
                else
                    v.pz = ROAD_DOWN;
                road_modify_vertical(r,&v,n);
                road_apply_vertical(r);

                modify=1;
            }
        }
        UpdateVerticalList();
        velist->Select(n);
        UpdateVerticalFig(true);
        vAct=0;
    }
    else if(motion==ID_DTA_VERTICAL_DEL)
    {
        int n = velist->GetFirstSelected();
        int Num = velist->GetItemCount();
        if(n<0 || n>=Num-1) return;
        ConfirmDlg dlg(this);
        dlg.confirmMsg=_("删除操作将不可恢复\n确定要进行删除吗？");
        //wxMessageDialog dlg(this,_("删除操作将不可恢复\n确定要进行删除吗？"),_("竖曲线要素"),wxYES_NO|wxICON_INFORMATION);
        if(dlg.ShowModal()==wxID_OK)
        {
            road * r=&mtg->r;
            road_remove_vertical(r,n);
            road_apply_vertical(r);
            modify=1;
            UpdateVerticalList();
            if(n == Num-2)
                velist->Select(n-1);
            else
                velist->Select(n);
            UpdateVerticalFig(true);
        }
    }

    veButton->Refresh();
}

void DtaDlg::OnPaintHoff(wxPaintEvent& event)
{
    wxPaintDC dc(panelHoff);
    int w,h;
    panelHoff->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnPainthoButton(wxPaintEvent& event)
{
    wxPaintDC dc(hoButton);
    int w,h;
    hoButton->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(112,118,112)));
        memDC.DrawLine(0,h-1,w,h-1);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int nho=road_number_horizon_off(&mtg->r);
        int n = holist->GetFirstSelected();

        int x1=0;
        int y1=0;
        int w1=btn_width;
        int h1=h-2;
        int r,g,b;
        int y2;

        dtaButton[ID_DTA_HOFF_ADD].x=x1;
        dtaButton[ID_DTA_HOFF_ADD].y=y1;
        dtaButton[ID_DTA_HOFF_ADD].width=w1;
        dtaButton[ID_DTA_HOFF_ADD].height=h1;
        if(motion==ID_DTA_HOFF_ADD)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=200;
            g=225;
            b=250;

            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
        }
        memDC.DrawLabel(_("添  加"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_HOFF_EDI].x=x1;
        dtaButton[ID_DTA_HOFF_EDI].y=y1;
        dtaButton[ID_DTA_HOFF_EDI].width=w1;
        dtaButton[ID_DTA_HOFF_EDI].height=h1;
        if(n>=0 && n<nho)
        {
            if(motion==ID_DTA_HOFF_EDI)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=200;
                g=225;
                b=250;

                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

                }
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=215;
                g=215;
                b=215;
                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                    r++;
                    g++;
                    b++;
                }
            }
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawLabel(_("编  辑"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_HOFF_DEL].x=x1;
        dtaButton[ID_DTA_HOFF_DEL].y=y1;
        dtaButton[ID_DTA_HOFF_DEL].width=w1;
        dtaButton[ID_DTA_HOFF_DEL].height=h1;
        if(n>=0 && n<nho)
        {
            if(motion==ID_DTA_HOFF_DEL)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=200;
                g=225;
                b=250;

                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

                }
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=215;
                g=215;
                b=215;
                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                    r++;
                    g++;
                    b++;
                }
            }
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawLabel(_("删  除"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnMotionhoButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>dtaButton[ID_DTA_HOFF_ADD].y && y<dtaButton[ID_DTA_HOFF_ADD].y+dtaButton[ID_DTA_HOFF_ADD].height)
    {
        if(x>dtaButton[ID_DTA_HOFF_ADD].x && x<dtaButton[ID_DTA_HOFF_ADD].x+dtaButton[ID_DTA_HOFF_ADD].width)
        {
            motion=ID_DTA_HOFF_ADD;
        }
        else if(x>dtaButton[ID_DTA_HOFF_EDI].x && x<dtaButton[ID_DTA_HOFF_EDI].x+dtaButton[ID_DTA_HOFF_EDI].width)
        {
            motion=ID_DTA_HOFF_EDI;
        }
        else if(x>dtaButton[ID_DTA_HOFF_DEL].x && x<dtaButton[ID_DTA_HOFF_DEL].x+dtaButton[ID_DTA_HOFF_DEL].width)
        {
            motion=ID_DTA_HOFF_DEL;
        }
        else
        {
            motion=ID_DTA_NONE;
        }
    }
    else
    {
        motion=ID_DTA_NONE;
    }
    hoButton->Refresh();
}

void DtaDlg::OnLeavehoButton(wxMouseEvent& event)
{
    motion=ID_DTA_NONE;
    hoButton->Refresh();
}

void DtaDlg::OnClickhoButton(wxMouseEvent& event)
{
    if(mtg->onLine!=0) return;
    if(motion==ID_DTA_HOFF_ADD)
    {
        road* r=&mtg->r;
        OffDialog dlg(this);
        dlg.Type=OFF_TYPE_HORIZON;

        if(dlg.ShowModal()==wxID_OK)
        {
            h_offset ho;
            dlg.Mile->GetValue().ToDouble(&ho.mile);
            dlg.Off->GetValue().ToDouble(&ho.off);
            ho.off=ho.off/1000.0;
            if(road_insert_horizon_off(r,&ho)==0)
            {
                UpdateHoffList();
                UpdateHoffFig(true);
                //UpdateHorizonList();

                modify=1;
            }
        }
    }
    else if(motion==ID_DTA_HOFF_EDI)
    {
        int sel=holist->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        OffDialog dlg(this);
        dlg.Type=OFF_TYPE_HORIZON;
        h_offset *ho=road_horizon_off(r,sel);
        dlg.Mile->SetValue(wxString::Format(_("%.3f"),ho->mile));
        dlg.Off->SetValue(wxString::Format(_("%.3f"),ho->off*1000.0));

        if(dlg.ShowModal()==wxID_OK)
        {
            h_offset ho1;
            dlg.Mile->GetValue().ToDouble(&ho1.mile);
            dlg.Off->GetValue().ToDouble(&ho1.off);
            ho1.off=ho1.off/1000.0;
            if(road_modify_horizon_off(r,&ho1,sel)==0)
            {
                UpdateHoffList();
                UpdateHoffFig(true);
                //UpdateHorizonList();
                modify=1;
            }
        }
    }
    else if(motion==ID_DTA_HOFF_DEL)
    {
        int sel=holist->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        ConfirmDlg dlg(this);
        dlg.confirmMsg=_("你确定要删除该偏移值吗？");
        //wxMessageDialog dlg(this,_("你确定要删除该偏移值吗？"),_("提示"),wxOK|wxCANCEL|wxCENTER|wxICON_WARNING);
        if(dlg.ShowModal()==wxID_OK)
        {
            if(road_erase_horizon_off(r,sel)==0)
            {
                UpdateHoffList();
                UpdateHoffFig(true);
                //UpdateHorizonList();
                modify=1;
            }
        }
    }
    hoButton->Refresh();
}

void DtaDlg::OnPaintVoff(wxPaintEvent& event)
{
    wxPaintDC dc(panelVoff);
    int w,h;
    panelVoff->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnPaintvoButton(wxPaintEvent& event)
{
    wxPaintDC dc(voButton);
    int w,h;
    voButton->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(112,118,112)));
        memDC.DrawLine(0,h-1,w,h-1);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int nvo=road_number_vertical_off(&mtg->r);
        int n = volist->GetFirstSelected();

        int x1=0;
        int y1=0;
        int w1=btn_width;
        int h1=h-2;
        int r,g,b;
        int y2;

        dtaButton[ID_DTA_VOFF_ADD].x=x1;
        dtaButton[ID_DTA_VOFF_ADD].y=y1;
        dtaButton[ID_DTA_VOFF_ADD].width=w1;
        dtaButton[ID_DTA_VOFF_ADD].height=h1;
        if(motion==ID_DTA_VOFF_ADD)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=200;
            g=225;
            b=250;

            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
        }
        memDC.DrawLabel(_("添  加"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_VOFF_EDI].x=x1;
        dtaButton[ID_DTA_VOFF_EDI].y=y1;
        dtaButton[ID_DTA_VOFF_EDI].width=w1;
        dtaButton[ID_DTA_VOFF_EDI].height=h1;
        if(n>=0 && n<nvo)
        {
            if(motion==ID_DTA_VOFF_EDI)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=200;
                g=225;
                b=250;

                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

                }
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=215;
                g=215;
                b=215;
                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                    r++;
                    g++;
                    b++;
                }
            }
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawLabel(_("编  辑"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_VOFF_DEL].x=x1;
        dtaButton[ID_DTA_VOFF_DEL].y=y1;
        dtaButton[ID_DTA_VOFF_DEL].width=w1;
        dtaButton[ID_DTA_VOFF_DEL].height=h1;
        if(n>=0 && n<nvo)
        {
            if(motion==ID_DTA_VOFF_DEL)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=200;
                g=225;
                b=250;

                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

                }
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=215;
                g=215;
                b=215;
                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                    r++;
                    g++;
                    b++;
                }
            }
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawLabel(_("删  除"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnMotionvoButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>dtaButton[ID_DTA_VOFF_ADD].y && y<dtaButton[ID_DTA_VOFF_ADD].y+dtaButton[ID_DTA_VOFF_ADD].height)
    {
        if(x>dtaButton[ID_DTA_VOFF_ADD].x && x<dtaButton[ID_DTA_VOFF_ADD].x+dtaButton[ID_DTA_VOFF_ADD].width)
        {
            motion=ID_DTA_VOFF_ADD;
        }
        else if(x>dtaButton[ID_DTA_VOFF_EDI].x && x<dtaButton[ID_DTA_VOFF_EDI].x+dtaButton[ID_DTA_VOFF_EDI].width)
        {
            motion=ID_DTA_VOFF_EDI;
        }
        else if(x>dtaButton[ID_DTA_VOFF_DEL].x && x<dtaButton[ID_DTA_VOFF_DEL].x+dtaButton[ID_DTA_VOFF_DEL].width)
        {
            motion=ID_DTA_VOFF_DEL;
        }
        else
        {
            motion=ID_DTA_NONE;
        }
    }
    else
    {
        motion=ID_DTA_NONE;
    }
    voButton->Refresh();
}

void DtaDlg::OnLeavevoButton(wxMouseEvent& event)
{
    motion=ID_DTA_NONE;
    voButton->Refresh();
}

void DtaDlg::OnClickvoButton(wxMouseEvent& event)
{
    if(mtg->onLine!=0) return;
    if(motion==ID_DTA_VOFF_ADD)
    {
        road* r=&mtg->r;
        OffDialog dlg(this);
        dlg.Type=OFF_TYPE_VERTICAL;

        if(dlg.ShowModal()==wxID_OK)
        {
            v_offset vo;
            dlg.Mile->GetValue().ToDouble(&vo.mile);
            dlg.Off->GetValue().ToDouble(&vo.off);
            vo.off=vo.off/1000.0;
            if(road_insert_vertical_off(r,&vo)==0)
            {
                UpdateVoffList();
                UpdateVoffFig(true);
                UpdateVerticalList();

                modify=1;
            }
        }
    }
    else if(motion==ID_DTA_VOFF_EDI)
    {
        int sel=volist->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        OffDialog dlg(this);
        dlg.Type=OFF_TYPE_VERTICAL;
        v_offset *vo=road_vertical_off(r,sel);
        dlg.Mile->SetValue(wxString::Format(_("%.3f"),vo->mile));
        dlg.Off->SetValue(wxString::Format(_("%.3f"),vo->off*1000.0));

        if(dlg.ShowModal()==wxID_OK)
        {
            v_offset vo1;
            dlg.Mile->GetValue().ToDouble(&vo1.mile);
            dlg.Off->GetValue().ToDouble(&vo1.off);
            vo1.off=vo1.off/1000.0;
            if(road_modify_vertical_off(r,&vo1,sel)==0)
            {
                UpdateVoffList();
                UpdateVoffFig(true);
                UpdateVerticalList();
                modify=1;
            }
        }
    }
    else if(motion==ID_DTA_VOFF_DEL)
    {
        int sel=volist->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        ConfirmDlg dlg(this);
        dlg.confirmMsg=_("你确定要删除该偏移值吗？");
        //wxMessageDialog dlg(this,_("你确定要删除该偏移值吗？"),_("提示"),wxOK|wxCANCEL|wxCENTER|wxICON_WARNING);
        if(dlg.ShowModal()==wxID_OK)
        {
            if(road_erase_vertical_off(r,sel)==0)
            {
                UpdateVoffList();
                UpdateVoffFig(true);
                UpdateVerticalList();
                modify=1;
            }
        }
    }
    voButton->Refresh();
}

void DtaDlg::OnPaintMoff(wxPaintEvent& event)
{
    wxPaintDC dc(panelMoff);
    int w,h;
    panelMoff->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnPaintmoButton(wxPaintEvent& event)
{
    wxPaintDC dc(moButton);
    int w,h;
    moButton->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(112,118,112)));
        memDC.DrawLine(0,h-1,w,h-1);
        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int nmo=road_number_mile_off(&mtg->r);
        int n = molist->GetFirstSelected();

        int x1=0;
        int y1=0;
        int w1=btn_width;
        int h1=h-2;
        int r,g,b;
        int y2;

        dtaButton[ID_DTA_MOFF_ADD].x=x1;
        dtaButton[ID_DTA_MOFF_ADD].y=y1;
        dtaButton[ID_DTA_MOFF_ADD].width=w1;
        dtaButton[ID_DTA_MOFF_ADD].height=h1;
        if(motion==ID_DTA_MOFF_ADD)
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=200;
            g=225;
            b=250;

            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
        }
        memDC.DrawLabel(_("添  加"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_MOFF_EDI].x=x1;
        dtaButton[ID_DTA_MOFF_EDI].y=y1;
        dtaButton[ID_DTA_MOFF_EDI].width=w1;
        dtaButton[ID_DTA_MOFF_EDI].height=h1;
        if(n>=0 && n<nmo)
        {
            if(motion==ID_DTA_MOFF_EDI)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=200;
                g=225;
                b=250;

                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

                }
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=215;
                g=215;
                b=215;
                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                    r++;
                    g++;
                    b++;
                }
            }
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawLabel(_("编  辑"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=x1+w1+2;
        dtaButton[ID_DTA_MOFF_DEL].x=x1;
        dtaButton[ID_DTA_MOFF_DEL].y=y1;
        dtaButton[ID_DTA_MOFF_DEL].width=w1;
        dtaButton[ID_DTA_MOFF_DEL].height=h1;
        if(n>=0 && n<nmo)
        {
            if(motion==ID_DTA_MOFF_DEL)
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=200;
                g=225;
                b=250;

                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r+40*i/(h1-2),g+20*i/(h1-2),b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);

                }
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(158,158,158)));
                memDC.DrawRectangle(x1,y1,w1,h1);
                r=215;
                g=215;
                b=215;
                for(int i=y1+1;i<h1-1;i++)
                {
                    memDC.SetPen(wxPen(wxColor(r,g,b)));
                    memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                    r++;
                    g++;
                    b++;
                }
            }
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            r=215;
            g=215;
            b=215;
            for(int i=y1+1;i<h1-1;i++)
            {
                memDC.SetPen(wxPen(wxColor(r,g,b)));
                memDC.DrawLine(x1+1,y1+i,x1+w1-1,y1+i);
                r++;
                g++;
                b++;
            }
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawLabel(_("删  除"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void DtaDlg::OnMotionmoButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>dtaButton[ID_DTA_MOFF_ADD].y && y<dtaButton[ID_DTA_MOFF_ADD].y+dtaButton[ID_DTA_MOFF_ADD].height)
    {
        if(x>dtaButton[ID_DTA_MOFF_ADD].x && x<dtaButton[ID_DTA_MOFF_ADD].x+dtaButton[ID_DTA_MOFF_ADD].width)
        {
            motion=ID_DTA_MOFF_ADD;
        }
        else if(x>dtaButton[ID_DTA_MOFF_EDI].x && x<dtaButton[ID_DTA_MOFF_EDI].x+dtaButton[ID_DTA_MOFF_EDI].width)
        {
            motion=ID_DTA_MOFF_EDI;
        }
        else if(x>dtaButton[ID_DTA_MOFF_DEL].x && x<dtaButton[ID_DTA_MOFF_DEL].x+dtaButton[ID_DTA_MOFF_DEL].width)
        {
            motion=ID_DTA_MOFF_DEL;
        }
        else
        {
            motion=ID_DTA_NONE;
        }
    }
    else
    {
        motion=ID_DTA_NONE;
    }
    moButton->Refresh();
}

void DtaDlg::OnLeavemoButton(wxMouseEvent& event)
{
    motion=ID_DTA_NONE;
    moButton->Refresh();
}

void DtaDlg::OnClickmoButton(wxMouseEvent& event)
{
    if(mtg->onLine!=0) return;
    if(motion==ID_DTA_MOFF_ADD)
    {
        road* r=&mtg->r;
        OffDialog dlg(this);
        dlg.Type=OFF_TYPE_MILE;

        if(dlg.ShowModal()==wxID_OK)
        {
            m_offset mo;
            double m1;
            dlg.Mile->GetValue().ToDouble(&mo.mile);
            dlg.Off->GetValue().ToDouble(&m1);
            mo.off=m1-mo.mile;
            if(road_insert_mile_off(r,&mo)==0)
            {
                UpdateMoffList();
                UpdateMoffFig(true);
                //UpdateHorizonList();///20150814添加
                //UpdateVerticalList();
                modify=1;
            }
        }
    }
    else if(motion==ID_DTA_MOFF_EDI)
    {
        int sel=molist->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        OffDialog dlg(this);
        dlg.Type=OFF_TYPE_MILE;
        m_offset *mo=road_mile_off(r,sel);
        dlg.Mile->SetValue(wxString::Format(_("%.4f"),mo->mile));
        dlg.Off->SetValue(wxString::Format(_("%.4f"),mo->mile+mo->off));

        if(dlg.ShowModal()==wxID_OK)
        {
            m_offset mol;
            double m1;
            dlg.Mile->GetValue().ToDouble(&mol.mile);
            dlg.Off->GetValue().ToDouble(&m1);
            mol.off=m1-mol.mile;
            if(road_modify_mile_off(r,&mol,sel)==0)
            {
                UpdateMoffList();
                UpdateMoffFig(true);
                //UpdateHorizonList();
                //UpdateVerticalList();
                modify=1;
            }
        }
    }
    else if(motion==ID_DTA_MOFF_DEL)
    {
        int sel=molist->GetFirstSelected();
        if(sel<0) return;
        road* r=&mtg->r;
        ConfirmDlg dlg(this);
        dlg.confirmMsg=_("你确定要删除该短链吗？");
        //wxMessageDialog dlg(this,_("你确定要删除该偏移值吗？"),_("提示"),wxOK|wxCANCEL|wxCENTER|wxICON_WARNING);
        if(dlg.ShowModal()==wxID_OK)
        {
            if(road_erase_mile_off(r,sel)==0)
            {
                UpdateMoffList();
                UpdateMoffFig(true);
                //UpdateHorizonList();
                //UpdateVerticalList();
                modify=1;
            }
        }
    }
    moButton->Refresh();
}
