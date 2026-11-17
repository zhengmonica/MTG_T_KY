#include "wx_pch.h"
#include "TailSpaceDlg.h"
#include "DistDlg.h"
//#include "ConfirmDlg.h"

#define PI 3.1415926
#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(TailSpaceDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(TailSpaceDlg)
//*)

//(*IdInit(TailSpaceDlg)
//*)

BEGIN_EVENT_TABLE(TailSpaceDlg,wxDialog)
	//(*EventTable(TailSpaceDlg)
	//*)
END_EVENT_TABLE()

TailSpaceDlg::TailSpaceDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	//(*Initialize(TailSpaceDlg)
	this->SetSizeHints(wxDefaultSize,wxDefaultSize);
	this->Centre(wxBOTH);
	int w,h;
	int x1,y1,x2,y2;
	int w1,h1,w2,h2;
	this->GetClientSize(&w,&h);
    panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPage = new wxPanel(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=7;
    y1=59;
    w1=w-x1*2;
    h1=h-114;

    panelSetting = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSetting->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelJust=new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelJust->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelJust->Show(false);
    panelMeas = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMeas->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelMeas->Show(false);
    panelQuery = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelQuery->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelQuery->Show(false);

    x1=14;
    y1=9;
    ipStaticText1 = new wxStaticText(panelSetting, wxID_ANY, _("."), wxPoint(x1+88,y1+20), wxDefaultSize, 0, _("wxID_ANY"));
    ipStaticText2 = new wxStaticText(panelSetting, wxID_ANY, _("."), wxPoint(x1+158,y1+20), wxDefaultSize, 0, _("wxID_ANY"));
    ipStaticText3 = new wxStaticText(panelSetting, wxID_ANY, _("."), wxPoint(x1+228,y1+20), wxDefaultSize, 0, _("wxID_ANY"));
    ipTxt1 = new wxMyTextCtrl(panelSetting, wxID_ANY, wxEmptyString, wxPoint(x1+25,y1+20), wxSize(60,-1), wxTE_CENTER);
    ipTxt2 = new wxMyTextCtrl(panelSetting, wxID_ANY, wxEmptyString, wxPoint(x1+95,y1+20), wxSize(60,-1), wxTE_CENTER);
    ipTxt3 = new wxMyTextCtrl(panelSetting, wxID_ANY, wxEmptyString, wxPoint(x1+165,y1+20), wxSize(60,-1), wxTE_CENTER);
    ipTxt4 = new wxMyTextCtrl(panelSetting, wxID_ANY, wxEmptyString, wxPoint(x1+235,y1+20), wxSize(60,-1), wxTE_CENTER);

    portTxt = new wxMyTextCtrl(panelSetting, wxID_ANY, wxEmptyString, wxPoint(x1+375,y1+20), wxSize(90,-1), wxTE_CENTER);
    btnConnect = new wxPanel(panelSetting, wxID_ANY, wxPoint(x1+480,y1+20), wxSize(65,22), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    btnConnect->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    lasers= new wxListView(panelSetting, wxID_ANY, wxPoint(x1,y1+115), wxSize(464,100), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    btnLaser = new wxPanel(panelSetting, wxID_ANY, wxPoint(x1+480,103), wxSize(65,100), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    btnLaser->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    laserFig = new wxPanel(panelSetting, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    laserFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    radiusTxt1 = new wxMyTextCtrl(panelSetting, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(90,-1), 0);
    radiusTxt1->Enable(false);
    radiusTxt2 = new wxMyTextCtrl(panelSetting, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(90,-1), 0);
    btnRadius = new wxPanel(panelSetting, wxID_ANY, wxPoint(x1+480,y1+20), wxSize(65,22), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    btnRadius->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x1=0;
    y1=0;
    measList= new wxListView(panelMeas, wxID_ANY, wxPoint(14,50), wxSize(464,100), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    measFig = new wxPanel(panelMeas, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    measFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    btnMeas = new wxPanel(panelMeas, wxID_ANY, wxPoint(x1+w1-100,y1), wxSize(65,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    btnMeas->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    gapTxt1 = new wxMyTextCtrl(panelMeas, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gapTxt2 = new wxMyTextCtrl(panelMeas, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gapTxt3 = new wxMyTextCtrl(panelMeas, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gapTxt4 = new wxMyTextCtrl(panelMeas, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gapTxt1->SetEditable(false);
    gapTxt2->SetEditable(false);
    gapTxt3->SetEditable(false);
    gapTxt4->SetEditable(false);

    justFig = new wxPanel(panelJust, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    justFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    measGap1 = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    measGap2 = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    measGap3 = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    measGap4 = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    measGap1->SetEditable(false);
    measGap2->SetEditable(false);
    measGap3->SetEditable(false);
    measGap4->SetEditable(false);
    justGap1 = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    justGap2 = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    justGap3 = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    justGap4 = new wxMyTextCtrl(panelJust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    btnJust = new wxPanel(panelJust, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    btnJust->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    qryList= new wxListView(panelQuery, wxID_ANY, wxPoint(14,30), wxSize(w1-118,h1-45), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    btnQuery = new wxPanel(panelQuery, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
    btnQuery->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintMain,0,this);

    panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickPage,0,this);

    panelSetting->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintSettings,0,this);
    panelQuery->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintQueryPage,0,this);

    btnConnect->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintComm,0,this);
    btnConnect->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionComm,0,this);
    btnConnect->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeaveComm,0,this);
    btnConnect->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickComm,0,this);

    btnLaser->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintLaser,0,this);
    btnLaser->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionLaser,0,this);
    btnLaser->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeaveLaser,0,this);
    btnLaser->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickLaser,0,this);

    laserFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintLaserFig,0,this);

    btnRadius->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintRadius,0,this);
    btnRadius->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionRadius,0,this);
    btnRadius->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeaveRadius,0,this);
    btnRadius->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickRadius,0,this);

    lasers->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&TailSpaceDlg::OnDisterActivated,0,this);
    lasers->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&TailSpaceDlg::OnDisterSelect,0,this);
    lasers->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&TailSpaceDlg::OnDisterDeselected,0,this);

    panelMeas->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintDataList,0,this);
    measFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintDataGraph,0,this);
    justFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintJustFig,0,this);

    btnMeas->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintMeasButton,0,this);
    btnMeas->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionMeasButton,0,this);
    btnMeas->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeaveMeasButton,0,this);
    btnMeas->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickMeasButton,0,this);

    //measList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&TailSpaceDlg::OnMeasActivated,0,this);
    measList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&TailSpaceDlg::OnMeasSelect,0,this);
    measList->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&TailSpaceDlg::OnMeasDeselected,0,this);

    panelJust->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintJust,0,this);
    btnJust->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintJustButton,0,this);
    btnJust->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionJustButton,0,this);
    btnJust->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeaveJustButton,0,this);
    btnJust->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickJustButton,0,this);

    btnQuery->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintQuery,0,this);
    btnQuery->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionQuery,0,this);
    btnQuery->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeaveQuery,0,this);
    btnQuery->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickQuery,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickBottom,0,this);

    this->SetBackgroundColour(wxColor(245,248,250));

    int i=0;
    lasers->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    lasers->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTER,55);
    lasers->InsertColumn(i++,_("编号"),wxLIST_FORMAT_CENTER,60);
    lasers->InsertColumn(i++,_("连接"),wxLIST_FORMAT_CENTER,60);
    lasers->InsertColumn(i++,_("角度（°）"),wxLIST_FORMAT_CENTER,85);
    lasers->InsertColumn(i++,_("测量值（m）"),wxLIST_FORMAT_CENTER,85);
    lasers->InsertColumn(i++,_("选用"),wxLIST_FORMAT_CENTER,60);

    i=0;
    measList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    measList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTER,65);
    measList->InsertColumn(i++,_("编号"),wxLIST_FORMAT_CENTER,65);
    measList->InsertColumn(i++,_("盾壳"),wxLIST_FORMAT_CENTER,70);
    measList->InsertColumn(i++,_("管片"),wxLIST_FORMAT_CENTER,70);
    //measList->InsertColumn(i++,_("状态"),wxLIST_FORMAT_CENTER,70);

    i=0;
    qryList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    qryList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTER,65);
    qryList->InsertColumn(i++,_("上"),wxLIST_FORMAT_CENTER,100);
    qryList->InsertColumn(i++,_("下"),wxLIST_FORMAT_CENTER,100);
    qryList->InsertColumn(i++,_("左"),wxLIST_FORMAT_CENTER,100);
    qryList->InsertColumn(i++,_("右"),wxLIST_FORMAT_CENTER,100);
    qryList->InsertColumn(i++,_("日期"),wxLIST_FORMAT_CENTER,130);

	//*)

	page=ID_TG_PAGE_CONNECT;
    motion=ID_TG_NONE;
    res=0;
    nres=0;

    Connect(wxEVT_TIMER,(wxObjectEventFunction)&TailSpaceDlg::OnTimer);
    Timer.SetOwner(this);
    Timer.Start(10,false);
	LoadData();
}

TailSpaceDlg::~TailSpaceDlg()
{
	//(*Destroy(TailSpaceDlg)
    Timer.Stop();
	//*)
}

void TailSpaceDlg::OnPaintMain(wxPaintEvent& event)
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
        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(0,0,w,h);


        //memDC.SetPen(wxPen(wxColor(241,245,250)));
        //memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        //memDC.DrawRectangle(-1,38,w+2,h-38);

        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,48,w,48);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(0,49,w,49);
        //memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        //memDC.DrawRectangle(-1,49,w+2,h-49);
        //memDC.SetPen(wxPen(wxColor(172,168,153)));
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnPaintPage(wxPaintEvent& event)
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
        tgButton[ID_TG_PAGE_CONNECT].x=x1;
        tgButton[ID_TG_PAGE_CONNECT].y=y1;
        tgButton[ID_TG_PAGE_CONNECT].width=w1;
        tgButton[ID_TG_PAGE_CONNECT].height=h1;

        if(page==ID_TG_PAGE_CONNECT || motion==ID_TG_PAGE_CONNECT)
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

            if(page!=ID_TG_PAGE_CONNECT)
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
        memDC.DrawLabel(_("参数设置"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);

        x1=x1+w1;
        tgButton[ID_TG_PAGE_MEAS].x=x1;
        tgButton[ID_TG_PAGE_MEAS].y=y1;
        tgButton[ID_TG_PAGE_MEAS].width=w1;
        tgButton[ID_TG_PAGE_MEAS].height=h1;
        if(page==ID_TG_PAGE_MEAS || motion==ID_TG_PAGE_MEAS)
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

            if(page!=ID_TG_PAGE_MEAS)
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
        memDC.DrawLabel(_("间隙测量"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1+w1;
        tgButton[ID_TG_PAGE_QRY].x=x1;
        tgButton[ID_TG_PAGE_QRY].y=y1;
        tgButton[ID_TG_PAGE_QRY].width=w1;
        tgButton[ID_TG_PAGE_QRY].height=h1;
        if(page==ID_TG_PAGE_QRY || motion==ID_TG_PAGE_QRY)
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

            if(page!=ID_TG_PAGE_QRY)
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
        memDC.DrawLabel(_("历史间隙"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1+w1;
        tgButton[ID_TG_PAGE_JUST].x=x1;
        tgButton[ID_TG_PAGE_JUST].y=y1;
        tgButton[ID_TG_PAGE_JUST].width=w1;
        tgButton[ID_TG_PAGE_JUST].height=h1;
        if(page==ID_TG_PAGE_JUST || motion==ID_TG_PAGE_JUST)
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
            if(page!=ID_TG_PAGE_JUST)
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
        memDC.DrawLabel(_("间隙矫正"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
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

void TailSpaceDlg::OnMotionPage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>tgButton[ID_TG_PAGE_CONNECT].y && y<tgButton[ID_TG_PAGE_CONNECT].y+tgButton[ID_TG_PAGE_CONNECT].height)
    {
        if(x>tgButton[ID_TG_PAGE_CONNECT].x && x<tgButton[ID_TG_PAGE_CONNECT].x+tgButton[ID_TG_PAGE_CONNECT].width)
        {
            motion=ID_TG_PAGE_CONNECT;
        }
        else if(x>tgButton[ID_TG_PAGE_JUST].x && x<tgButton[ID_TG_PAGE_JUST].x+tgButton[ID_TG_PAGE_JUST].width)
        {
            motion=ID_TG_PAGE_JUST;
        }
        else if(x>tgButton[ID_TG_PAGE_MEAS].x && x<tgButton[ID_TG_PAGE_MEAS].x+tgButton[ID_TG_PAGE_MEAS].width)
        {
            motion=ID_TG_PAGE_MEAS;
        }
        else if(x>tgButton[ID_TG_PAGE_QRY].x && x<tgButton[ID_TG_PAGE_QRY].x+tgButton[ID_TG_PAGE_QRY].width)
        {
            motion=ID_TG_PAGE_QRY;
        }
        else
        {
            motion=ID_TG_NONE;
        }
    }
    else
    {
        motion=ID_TG_NONE;
    }
    panelPage->Refresh();
}

void TailSpaceDlg::OnLeavePage(wxMouseEvent& event)
{
    motion=ID_TG_NONE;
    panelPage->Refresh();
}

void TailSpaceDlg::OnClickPage(wxMouseEvent& event)
{
    if(motion==ID_TG_PAGE_CONNECT)
    {
        page=ID_TG_PAGE_CONNECT;
        panelSetting->Show(true);
        panelJust->Show(false);
        panelMeas->Show(false);
        panelQuery->Show(false);
    }
    else if(motion==ID_TG_PAGE_JUST)
    {
        page=ID_TG_PAGE_JUST;
        panelSetting->Show(false);
        panelJust->Show(true);
        panelMeas->Show(false);
        panelQuery->Show(false);
    }
    else if(motion==ID_TG_PAGE_MEAS)
    {
        page=ID_TG_PAGE_MEAS;
        panelSetting->Show(false);
        panelJust->Show(false);
        panelMeas->Show(true);
        panelQuery->Show(false);
    }
    else if(motion==ID_TG_PAGE_QRY)
    {
        page=ID_TG_PAGE_QRY;
        panelSetting->Show(false);
        panelJust->Show(false);
        panelMeas->Show(false);
        panelQuery->Show(true);
    }

    panelPage->Refresh();
}

void TailSpaceDlg::OnPaintSettings(wxPaintEvent& event)
{
    wxPaintDC dc(panelSetting);
    int w,h;
    panelSetting->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(0,0,w,h);

        int x1,y1,w1,h1;
        x1=0;
        y1=8;
        w1=575;
        h1=55;
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(x1+8,y1,65,30);
        memDC.DrawLabel(_("通讯参数"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        int x2,y2,w2,h2;
        x2=x1+14;
        y2=28;
        w2=65;
        h2=23;
        memDC.DrawLabel(_("IP："),wxRect(x2,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x2=340;
        memDC.DrawLabel(_("端口号："),wxRect(x2,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+20;
        h1=155;
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(x1+8,y1,65,30);
        memDC.DrawLabel(_("设备状态"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x2=x1+14;
        y2=y1+20;
        w2=464;
        h2=25;
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        memDC.DrawRectangle(x2,y2,w2,h2);
        int i=1;
        w2=lasers->GetColumnWidth(i++);
        memDC.DrawLine(x2+w2,y2,x2+w2,y2+h2);
        memDC.DrawLabel(_("序号"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x2+=w2;
        w2=lasers->GetColumnWidth(i++);
        memDC.DrawLine(x2+w2,y2,x2+w2,y2+h2);
        memDC.DrawLabel(_("地址"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x2+=w2;
        w2=lasers->GetColumnWidth(i++);
        memDC.DrawLine(x2+w2,y2,x2+w2,y2+h2);
        memDC.DrawLabel(_("连接"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x2+=w2;
        w2=lasers->GetColumnWidth(i++);
        memDC.DrawLine(x2+w2,y2,x2+w2,y2+h2);
        memDC.DrawLabel(_("角度（°）"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x2+=w2;
        w2=lasers->GetColumnWidth(i++);
        memDC.DrawLine(x2+w2,y2,x2+w2,y2+h2);
        memDC.DrawLabel(_("初始值（m）"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x2+=w2;
        w2=lasers->GetColumnWidth(i++);
        memDC.DrawLine(x2+w2,y2,x2+w2,y2+h2);
        memDC.DrawLabel(_("选用"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        y1=y1+h1+20;
        h1=200;
        memDC.SetBrush(*wxTRANSPARENT_BRUSH);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(x1+8,y1,65,30);
        memDC.DrawLabel(_("安装及示意"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x2=x1+14;
        y2=y1+20;
        w2=165;
        h2=165;
        laserFig->SetSize(x2,y2,w2,h2);

        x2=x2+w2+25;
        w2=35;
        h2=20;
        memDC.DrawLabel(_("R1："),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        radiusTxt1->SetSize(x2+w2,y2,90,-1);
        memDC.DrawLabel(_("R2："),wxRect(x2+w2+110,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        radiusTxt2->SetSize(x2+2*w2+110,y2,90,-1);

        btnRadius->SetSize(x2+2*w2+220,y2,65,22);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnPaintQueryPage(wxPaintEvent& event)
{
    wxPaintDC dc(panelQuery);
    int w,h;
    panelQuery->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(0,0,w,h);

        int x1,y1,w1,h1;
        x1=14;
        y1=7;
        w1=w-118;
        h1=25;
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        btnQuery->SetSize(x1+w1+15,y1,65,51);
        int i=1;
        w1=qryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("上侧间隙（mm）"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("下侧间隙（mm）"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("左侧间隙（mm）"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("右侧间隙（mm）"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=qryList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("日期"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnPaintJust(wxPaintEvent& event)
{
    wxPaintDC dc(panelJust);
    int w,h;
    panelJust->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(0,0,w,h);

        int x1,y1,w1,h1;
        x1=0;
        y1=8;
        w1=w-115;
        h1=360;
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(x1+8,y1,65,30);
        memDC.DrawLabel(_("矫正参数"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        int x2,y2,w2,h2;
        x2=x1+14;
        y2=y1+20;
        w2=320;
        h2=320;
        justFig->SetSize(x2,y2,w2,h2);

        x1=x2+w2+25;
        y1=y2;
        w1=285;
        h1=150;
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(x1+8,y1,65,30);
        memDC.DrawLabel(_("系统测量"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x2=x1+15;
        y2=y1+20;
        h2=20;
        memDC.DrawLabel(_("上侧间隙："),wxRect(x2,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        measGap1->SetSize(x2+80,y2,90,-1);
        y2=y2+h2+7;
        memDC.DrawLabel(_("下侧间隙："),wxRect(x2,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        measGap2->SetSize(x2+80,y2,90,-1);
        y2=y2+h2+7;
        memDC.DrawLabel(_("左侧间隙："),wxRect(x2,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        measGap3->SetSize(x2+80,y2,90,-1);
        y2=y2+h2+7;
        memDC.DrawLabel(_("右侧间隙："),wxRect(x2,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        measGap4->SetSize(x2+80,y2,90,-1);

        y1=y1+h1+20;
        w1=285;
        h1=150;
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(x1+8,y1,65,30);
        memDC.DrawLabel(_("人工测量"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        x2=x1+15;
        y2=y1+20;
        h2=20;
        memDC.DrawLabel(_("上侧间隙："),wxRect(x2,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        justGap1->SetSize(x2+80,y2,90,-1);
        btnJust->SetSize(x2+185,y2,65,22);
        y2=y2+h2+7;
        memDC.DrawLabel(_("下侧间隙："),wxRect(x2,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        justGap2->SetSize(x2+80,y2,90,-1);
        y2=y2+h2+7;
        memDC.DrawLabel(_("左侧间隙："),wxRect(x2,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        justGap3->SetSize(x2+80,y2,90,-1);
        y2=y2+h2+7;
        memDC.DrawLabel(_("右侧间隙："),wxRect(x2,y2,0,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        justGap4->SetSize(x2+80,y2,90,-1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnPaintComm(wxPaintEvent& event)
{
    wxPaintDC dc(btnConnect);
    int w,h;
    btnConnect->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(0,0,w,h);

        if(motion==ID_TG_CONNECT)
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
        //memDC.SetPen(wxPen(wxColor(117,117,117)));

        memDC.DrawRoundedRectangle(0,0,w,h,3);
        memDC.DrawLabel(_("连接"),wxRect(0,0,w,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnMotionComm(wxMouseEvent& event)
{
    motion=ID_TG_CONNECT;
    btnConnect->Refresh();
}

void TailSpaceDlg::OnLeaveComm(wxMouseEvent& event)
{
    motion=ID_TG_NONE;
    btnConnect->Refresh();
}

void TailSpaceDlg::OnClickComm(wxMouseEvent& event)
{
    Apply();
    btnConnect->Refresh();
}

void TailSpaceDlg::OnPaintRadius(wxPaintEvent& event)
{
    wxPaintDC dc(btnRadius);
    int w,h;
    btnRadius->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(0,0,w,h);

        if(motion==ID_TG_RADIUS)
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
        //memDC.SetPen(wxPen(wxColor(117,117,117)));

        memDC.DrawRoundedRectangle(0,0,w,h,3);
        memDC.DrawLabel(_("设置"),wxRect(0,0,w,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnMotionRadius(wxMouseEvent& event)
{
    motion=ID_TG_RADIUS;
    btnRadius->Refresh();
}

void TailSpaceDlg::OnLeaveRadius(wxMouseEvent& event)
{
    motion=ID_TG_NONE;
    btnRadius->Refresh();
}

void TailSpaceDlg::OnClickRadius(wxMouseEvent& event)
{
    //radiusTxt1->GetValue().ToDouble(&mtg->gaps.radius);
    radiusTxt2->GetValue().ToDouble(&mtg->gaps.d1);
    if(mtg_store_gaps(mtg))
    {
        WriteMsg(_("参数设置成功！"),0);
        UpdateLasers();
        laserFig->Refresh();
    }
    else
    {
        WriteMsg(_("参数设置失败！"),1);
    }
    btnRadius->Refresh();
}

void TailSpaceDlg::OnPaintLaser(wxPaintEvent& event)
{
    wxPaintDC dc(btnLaser);
    int w,h;
    btnLaser->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(chs);
        memDC.SetPen(wxPen(wxColor(158,158,158)));

        int x1=0;
        int y1=0;
        int w1=w;
        int h1=22;
        tgButton[ID_TG_DIST_TBM].x=x1;
        tgButton[ID_TG_DIST_TBM].y=y1;
        tgButton[ID_TG_DIST_TBM].width=w1;
        tgButton[ID_TG_DIST_TBM].height=h1;
        if(motion==ID_TG_DIST_TBM)
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
        memDC.DrawLabel(_("测量"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+7;
        tgButton[ID_TG_DIST_EDI].x=x1;
        tgButton[ID_TG_DIST_EDI].y=y1;
        tgButton[ID_TG_DIST_EDI].width=w1;
        tgButton[ID_TG_DIST_EDI].height=h1;
        int sel = lasers->GetFirstSelected();

        if(sel>=0)
        {
            if(motion==ID_TG_DIST_EDI)
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
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("编辑"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+7;
        tgButton[ID_TG_TBM_SAVE].x=x1;
        tgButton[ID_TG_TBM_SAVE].y=y1;
        tgButton[ID_TG_TBM_SAVE].width=w1;
        tgButton[ID_TG_TBM_SAVE].height=h1;
        if(motion==ID_TG_TBM_SAVE)
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
        memDC.DrawLabel(_("保存"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnMotionLaser(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>tgButton[ID_TG_DIST_EDI].x && x<tgButton[ID_TG_DIST_EDI].x+tgButton[ID_TG_DIST_EDI].width)
    {
        if(y>tgButton[ID_TG_DIST_EDI].y && y<tgButton[ID_TG_DIST_EDI].y+tgButton[ID_TG_DIST_EDI].height)
        {
            motion=ID_TG_DIST_EDI;
        }
        else if(y>tgButton[ID_TG_DIST_TBM].y && y<tgButton[ID_TG_DIST_TBM].y+tgButton[ID_TG_DIST_TBM].height)
        {
            motion=ID_TG_DIST_TBM;
        }
        else if(y>tgButton[ID_TG_TBM_SAVE].y && y<tgButton[ID_TG_TBM_SAVE].y+tgButton[ID_TG_TBM_SAVE].height)
        {
            motion=ID_TG_TBM_SAVE;
        }
        else
        {
            motion=ID_TG_NONE;
        }
    }
    else
    {
        motion=ID_TG_NONE;
    }

    btnLaser->Refresh();
}

void TailSpaceDlg::OnLeaveLaser(wxMouseEvent& event)
{
    motion=ID_TG_NONE;
    btnLaser->Refresh();
}

void ID_converse(wxString str,int &ID)
{
    str.MakeUpper();
    char cmd[2];
    strncpy(cmd,str.mb_str(wxConvUTF8),2);
    ID=0;
    for(int i=0;i<2;i++)
    {
        if(i!=1)
        {
            if(cmd[i]>='A'&&cmd[i]<='F')
                ID=(ID+(cmd[i]-'A')+10)*16;
            else if(cmd[i]>='0'&&cmd[i]<='9')
                ID=(ID+(cmd[i]-'0'))*16;
        }
        else
        {
            if(cmd[i]>='A'&&cmd[i]<='F')
                ID=(ID+(cmd[i]-'A')+10);
            else if(cmd[i]>='0'&&cmd[i]<='9')
                ID=(ID+(cmd[i]-'0'));
        }
    }
}

void TailSpaceDlg::OnClickLaser(wxMouseEvent& event)
{
    int i=0;
    int ret=0;
    if(motion==ID_TG_DIST_TBM)
    {
        mtg->gaps.opera=DIST_CMD_TBM;
        ret = disters_meas(mtg);
    }
    else if(motion==ID_TG_TBM_SAVE)
    {
        mtg->gaps.opera==DIST_CMD_TBM;
        if(mtg_gap_tbm(mtg)==0)
        {
            if(mtg_store_gaps(mtg)) WriteMsg(_("参数保存成功！"),0);
            else WriteMsg(_("参数保存失败！"),1);
        }
        else
        {
            WriteMsg(_("参数计算失败！"),1);
        }
    }
    else if(motion==ID_TG_DIST_EDI)
    {
        int sel = lasers->GetFirstSelected();
        if(sel<0) return;
        DistDlg dlg(this);
        dlg.Center();
        dlg.disterName->SetValue(wxString::Format(_("0X%0X"),mtg->dister[sel].id));
        dlg.disterAngle->SetValue(wxString::Format(_("%.4f"),mtg->dister[sel].angle*180/PI));
        dlg.disterText->SetValue(wxString::Format(_("%.3f"),mtg->dister[sel].dist));
        dlg.Selected=mtg->dister[sel].sel;
        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str;
            str=dlg.disterName->GetValue();
            dlg.disterAngle->GetValue().ToDouble(&mtg->dister[sel].angle);
            mtg->dister[sel].angle=mtg->dister[sel].angle*PI/180.0;
            dlg.disterText->GetValue().ToDouble(&mtg->dister[sel].dist);
            mtg->dister[sel].sel=dlg.Selected;
            //UpdateLasers();
            //laserFig->Refresh();
            WriteMsg(_("参数设置成功！"),0);
            UpdateLasers();
            laserFig->Refresh();
        }
    }
    //motion=ID_TG_NONE;
    btnLaser->Refresh();
}

void TailSpaceDlg::OnPaintLaserFig(wxPaintEvent& event)
{
   wxPaintDC dc(laserFig);
   int w,h;
   laserFig->GetClientSize(&w,&h);
   wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

        int r1,r2;
        r1=70;
        r2=25;
        memDC.SetPen(wxPen(wxColor(122,118,103)));
        memDC.DrawCircle(w/2,h/2,r1);
        memDC.DrawCircle(w/2,h/2,r2);

        double xi,yi,ai;
        double x1,y1;
        for(int i=0;i<5;i++)
        {
            ai=mtg->dister[i].angle;
            xi=w/2.0+(r2+5.0)*cos(ai);
            yi=h/2.0+(r2+5.0)*sin(ai);
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawCircle(xi,yi,5);
            int sel=lasers->GetFirstSelected();
            if(sel==i)
            {
                x1=w/2.0+r1*cos(ai);
                y1=h/2.0+r1*sin(ai);
                memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT_DASH));
                memDC.DrawLine(xi,yi,x1,y1);
            }
        }
        memDC.SetFont(chs);
        memDC.SetPen(wxPen(wxColor(122,118,103)));
        memDC.DrawLine(10,10,30,10);
        memDC.DrawLine(25,7,30,10);
        memDC.DrawLine(25,13,30,10);
        memDC.DrawLabel(_("X"),wxRect(35,10,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(10,10,10,30);
        memDC.DrawLine(7,25,10,30);
        memDC.DrawLine(13,25,10,30);
        memDC.DrawLabel(_("Y"),wxRect(10,32,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

        memDC.DrawLine(w/2+r2*3/2,h/2-r1,w/2+r2*3/2+5,h/2-r1+5);
        memDC.DrawLine(w/2+r2*3/2+5,h/2-r1+5,w/2+r2*3/2+5,h/2-5);
        memDC.DrawLine(w/2+r2*3/2+5,h/2-5,w/2+r2*3/2+10,h/2);
        memDC.DrawLine(w/2+r2*3/2+10,h/2,w/2+r2*3/2+5,h/2+5);
        memDC.DrawLine(w/2+r2*3/2+5,h/2+5,w/2+r2*3/2+5,h/2+r1-5);
        memDC.DrawLine(w/2+r2*3/2+5,h/2+r1-5,w/2+r2*3/2,h/2+r1);
        memDC.DrawLabel(_("R1"),wxRect(w/2+r2*3/2+15,h/2,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLine(w/2-r2,h/2,w/2-r2+5,h/2+5);
        memDC.DrawLine(w/2-r2+5,h/2+5,w/2-5,h/2+5);
        memDC.DrawLine(w/2-5,h/2+5,w/2,h/2+10);
        memDC.DrawLine(w/2,h/2+10,w/2+5,h/2+5);
        memDC.DrawLine(w/2+5,h/2+5,w/2+r2-5,h/2+5);
        memDC.DrawLine(w/2+r2-5,h/2+5,w/2+r2,h/2);
        memDC.DrawLabel(_("R2"),wxRect(w/2,h/2+10,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnDisterActivated(wxListEvent& event)
{
    wxMouseEvent e;
    motion=ID_TG_DIST_EDI;
    OnClickLaser(e);
}

void TailSpaceDlg::OnDisterSelect(wxListEvent& event)
{
    btnLaser->Refresh();
    laserFig->Refresh();
}

void TailSpaceDlg::OnDisterDeselected(wxListEvent& event)
{
    btnLaser->Refresh();
    laserFig->Refresh();
}

void TailSpaceDlg::OnMeasSelect(wxListEvent& event)
{
    measFig->Refresh();
}

void TailSpaceDlg::OnMeasDeselected(wxListEvent& event)
{
    measFig->Refresh();
}

void TailSpaceDlg::OnPaintDataList(wxPaintEvent& event)
{
    wxPaintDC dc(panelMeas);
    int w,h;
    panelMeas->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=8;
        w1=575;
        h1=155;
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(x1+8,y1,65,30);
        memDC.DrawLabel(_("测量数据"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        int x2,y2,w2,h2;
        x2=x1+14;
        y2=y1+20;
        w2=464;
        h2=25;
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        memDC.DrawRectangle(x2,y2,w2,h2);
        int i=1;
        w2=measList->GetColumnWidth(i++);
        memDC.DrawLine(x2+w2,y2,x2+w2,y2+h2);
        memDC.DrawLabel(_("序号"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x2+=w2;
        w2=measList->GetColumnWidth(i++);
        memDC.DrawLine(x2+w2,y2,x2+w2,y2+h2);
        memDC.DrawLabel(_("地址"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x2+=w2;
        w2=measList->GetColumnWidth(i++);
        memDC.DrawLine(x2+w2,y2,x2+w2,y2+h2);
        memDC.DrawLabel(_("测量值"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x2+=w2;
        w2=measList->GetColumnWidth(i++);
        memDC.DrawLine(x2+w2,y2,x2+w2,y2+h2);
        memDC.DrawLabel(_("参考值"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //x2+=w2;
        //w2=measList->GetColumnWidth(i++);
        //memDC.DrawLine(x2+w2,y2,x2+w2,y2+h2);
        //memDC.DrawLabel(_("较差"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        btnMeas->SetSize(x1+493,y2,65,84);


        x1=0;
        y1=y1+h1+20;
        w1=575;
        h1=275;
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(x1+8,y1,65,30);
        memDC.DrawLabel(_("盾尾间隙"),wxRect(x1+14,y1,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x2=x1+14;
        y2=y1+20;
        w2=240;
        h2=240;
        measFig->SetSize(x2,y2,w2,h2);

        x2=x2+w2+35;
        y2=y2;
        w2=80;
        h2=20;
        memDC.SetTextForeground(wxColor(0,0,0));
        memDC.DrawLabel(_("上侧间隙"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        gapTxt1->SetSize(x2+80,y2,w2,-1);
        y2=y2+h2+7;
        memDC.DrawLabel(_("下侧间隙"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        gapTxt2->SetSize(x2+80,y2,w2,-1);
        y2=y2+h2+7;
        memDC.DrawLabel(_("左侧间隙"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        gapTxt3->SetSize(x2+80,y2,w2,-1);
        y2=y2+h2+7;
        memDC.DrawLabel(_("右侧间隙"),wxRect(x2,y2,w2,h2),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        gapTxt4->SetSize(x2+80,y2,w2,-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnPaintDataGraph(wxPaintEvent& event)
{
    wxPaintDC dc(measFig);
    int w,h;
    measFig->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

        int r1,r2;
        r1=100;
        r2=25;
        memDC.SetPen(wxPen(wxColor(122,118,103)));
        memDC.DrawCircle(w/2,h/2,r1);
        memDC.DrawCircle(w/2,h/2,r2);

        double xi,yi,ai;
        double x1,y1;
        for(int i=0;i<5;i++)
        {
            ai=mtg->dister[i].angle;
            xi=w/2.0+(r2+5.0)*cos(ai);
            yi=h/2.0+(r2+5.0)*sin(ai);
            memDC.SetPen(wxPen(wxColor(0,0,255)));
            memDC.DrawCircle(xi,yi,5);
            int sel=measList->GetFirstSelected();
            if(sel==i)
            {
                x1=w/2.0+r1*cos(ai);
                y1=h/2.0+r1*sin(ai);
                memDC.SetPen(wxPen(wxColor(255,0,0),1,wxDOT_DASH));
                memDC.DrawLine(xi,yi,x1,y1);
            }
        }
        memDC.SetFont(chs);
        memDC.SetPen(wxPen(wxColor(122,118,103)));
        memDC.DrawLine(10,10,30,10);
        memDC.DrawLine(25,7,30,10);
        memDC.DrawLine(25,13,30,10);
        memDC.DrawLabel(_("X"),wxRect(35,10,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(10,10,10,30);
        memDC.DrawLine(7,25,10,30);
        memDC.DrawLine(13,25,10,30);
        memDC.DrawLabel(_("Y"),wxRect(10,32,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnPaintJustFig(wxPaintEvent& event)
{
    wxPaintDC dc(justFig);
    int w,h;
    justFig->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(130,135,145)));
        memDC.SetBrush(wxBrush(wxColor(255,255,255)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1;
        x1=w/2;
        y1=h/2;
        int r1,r2;
        if(w>h)
            r1=h/2-20;
        else
            r1=w/2-20;
        r2=r1*4/5;
        memDC.SetPen(wxPen(wxColor(68,88,108)));
        memDC.DrawCircle(x1,y1,r1);

        memDC.DrawCircle(x1,y1,r2);

        memDC.SetPen(wxPen(wxColor(0,0,255)));
        int x2,y2,x3,y3;
        x2=x1;
        y2=y1-r1-5;
        x3=x1;
        y3=y1-r2+5;
        memDC.DrawLine(x2,y2,x3,y3);
        x2=x1-3;
        y2=y1-r1-3;
        x3=x1+3;
        y3=y1-r1+3;
        memDC.SetPen(wxPen(wxColor(0,0,255),2));
        memDC.DrawLine(x2,y2,x3,y3);

        x2=x1-3;
        y2=y1-r2-3;
        x3=x1+3;
        y3=y1-r2+3;
        memDC.SetPen(wxPen(wxColor(0,0,255),2));
        memDC.DrawLine(x2,y2,x3,y3);
        memDC.SetTextForeground(wxColor(0,0,255));
        memDC.DrawLabel(_("上"),wxRect(x1+10,y1-r1*9/10,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x2=x1+r2-5;
        y2=y1;
        x3=x1+r1+5;
        y3=y1;
        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.DrawLine(x2,y2,x3,y3);
        x2=x1+r2-3;
        y2=y1-3;
        x3=x1+r2+3;
        y3=y1+3;
        memDC.SetPen(wxPen(wxColor(0,0,255),2));
        memDC.DrawLine(x2,y2,x3,y3);

        x2=x1+r1-3;
        y2=y1-3;
        x3=x1+r1+3;
        y3=y1+3;
        memDC.SetPen(wxPen(wxColor(0,0,255),2));
        memDC.DrawLine(x2,y2,x3,y3);
        memDC.SetTextForeground(wxColor(0,0,255));
        memDC.DrawLabel(_("右"),wxRect(x1+r1*9/10,y1+5,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

        x2=x1;
        y2=y1+r2-5;
        x3=x1;
        y3=y1+r1+5;
        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.DrawLine(x2,y2,x3,y3);
        x2=x1-3;
        y2=y1+r2-3;
        x3=x1+3;
        y3=y1+r2+3;
        memDC.SetPen(wxPen(wxColor(0,0,255),2));
        memDC.DrawLine(x2,y2,x3,y3);

        x2=x1-3;
        y2=y1+r1-3;
        x3=x1+3;
        y3=y1+r1+3;
        memDC.SetPen(wxPen(wxColor(0,0,255),2));
        memDC.DrawLine(x2,y2,x3,y3);
        memDC.SetTextForeground(wxColor(0,0,255));
        memDC.DrawLabel(_("下"),wxRect(x1+10,y1+r1*9/10,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        x2=x1-r1-5;
        y2=y1;
        x3=x1-r2+5;
        y3=y1;
        memDC.SetPen(wxPen(wxColor(0,0,255)));
        memDC.DrawLine(x2,y2,x3,y3);
        x2=x1-r1-3;
        y2=y1-3;
        x3=x1-r1+3;
        y3=y1+3;
        memDC.SetPen(wxPen(wxColor(0,0,255),2));
        memDC.DrawLine(x2,y2,x3,y3);

        x2=x1-r2-3;
        y2=y1-3;
        x3=x1-r2+3;
        y3=y1+3;
        memDC.SetPen(wxPen(wxColor(0,0,255),2));
        memDC.DrawLine(x2,y2,x3,y3);
        memDC.SetTextForeground(wxColor(0,0,255));
        memDC.DrawLabel(_("左"),wxRect(x1-r1*9/10,y1+5,0,0),wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnPaintMeasButton(wxPaintEvent& event)
{
    wxPaintDC dc(btnMeas);
    int w,h;
    btnMeas->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(chs);
        memDC.SetPen(wxPen(wxColor(158,158,158)));

        int x1=0;
        int y1=0;
        int w1=w;
        int h1=22;

        tgButton[ID_TG_DIST_SEG].x=x1;
        tgButton[ID_TG_DIST_SEG].y=y1;
        tgButton[ID_TG_DIST_SEG].width=w1;
        tgButton[ID_TG_DIST_SEG].height=h1;

        if(motion==ID_TG_DIST_SEG)
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
        memDC.DrawLabel(_("测量"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=29;
        tgButton[ID_TG_DIST_SAVE].x=x1;
        tgButton[ID_TG_DIST_SAVE].y=y1;
        tgButton[ID_TG_DIST_SAVE].width=w1;
        tgButton[ID_TG_DIST_SAVE].height=h1;

        if(motion==ID_TG_DIST_SAVE)
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
        memDC.DrawLabel(_("保存"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnMotionMeasButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>tgButton[ID_TG_DIST_TBM].x && x<tgButton[ID_TG_DIST_TBM].x+tgButton[ID_TG_DIST_TBM].width)
    {
        if(y>tgButton[ID_TG_DIST_SEG].y && y<tgButton[ID_TG_DIST_SEG].y+tgButton[ID_TG_DIST_SEG].height)
        {
            motion=ID_TG_DIST_SEG;
        }
        else if(y>tgButton[ID_TG_DIST_SAVE].y && y<tgButton[ID_TG_DIST_SAVE].y+tgButton[ID_TG_DIST_SAVE].height)
        {
            motion=ID_TG_DIST_SAVE;
        }
        else
        {
            motion=ID_TG_NONE;
        }
    }
    else
    {
        motion=ID_TG_NONE;
    }

    btnMeas->Refresh();
}

void TailSpaceDlg::OnLeaveMeasButton(wxMouseEvent& event)
{
    motion=ID_TG_NONE;
    btnMeas->Refresh();
}

void TailSpaceDlg::OnClickMeasButton(wxMouseEvent& event)
{
    int ret=0;

    if(motion==ID_TG_DIST_SEG)
    {
        mtg->gaps.opera=DIST_CMD_SEG;
        ret = disters_meas(mtg);
    }
    else if(motion==ID_TG_DIST_SAVE)
    {
        /*if(mtg->gaps.done==0)
        {
            WriteMsg(_("间隙测量未完成！"),1);
            return;
        }
        else if(mtg->gaps.done==-1)
        {
            WriteMsg(_("间隙测量数据不足！"),1);
            return;
        }
        else if(mtg->gaps.done==-2)
        {
            WriteMsg(_("盾壳数据异常！"),1);
            return;
        }
        else if(mtg->gaps.done==-3)
        {
            WriteMsg(_("管环数据异常！"),1);
            return;
        }
        else if(mtg->gaps.done==2)
        {
            WriteMsg(_("间隙数据已成功存储！"),1);
            return;
        }*/
        time(&mtg->gaps.t);
        mtg->dister[0].dist0=mtg->dister[0].dist1;
        mtg->dister[1].dist0=mtg->dister[1].dist1;
        mtg->dister[2].dist0=mtg->dister[2].dist1;
        mtg->dister[3].dist0=mtg->dister[3].dist1;
        mtg->dister[4].dist0=mtg->dister[4].dist1;
        if(mtg_store_measgaps(mtg))
        {
            WriteMsg(_("数据存储成功！"),0);
        }
        else
        {
            WriteMsg(_("数据存储失败！"),1);
        }
    }
    //if(ret==-1) WriteMsg(_("间隙系统异常，请检查"),1);
    //if(ret==-1) wxMessageBox(_("正在测量中，请稍候重试"));
    btnMeas->Refresh();
}

void TailSpaceDlg::OnPaintJustButton(wxPaintEvent& event)
{
    wxPaintDC dc(btnJust);
    int w,h;
    btnJust->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(chs);
        memDC.SetPen(wxPen(wxColor(158,158,158)));

        int x1=0;
        int y1=0;
        int w1=w;
        int h1=22;

        tgButton[ID_TG_JUST_SAVE].x=x1;
        tgButton[ID_TG_JUST_SAVE].y=y1;
        tgButton[ID_TG_JUST_SAVE].width=w1;
        tgButton[ID_TG_JUST_SAVE].height=h1;

        if(motion==ID_TG_JUST_SAVE)
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
        memDC.DrawLabel(_("设置"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnMotionJustButton(wxMouseEvent& event)
{
    motion=ID_TG_JUST_SAVE;
    btnJust->Refresh();
}

void TailSpaceDlg::OnLeaveJustButton(wxMouseEvent& event)
{
    motion=ID_TG_NONE;
    btnJust->Refresh();
}

void TailSpaceDlg::OnClickJustButton(wxMouseEvent& event)
{
    int ret=0;
    if(motion==ID_TG_JUST_SAVE)
    {
        double dbval;
        justGap1->GetValue().ToDouble(&dbval);
        mtg->gaps.ujust=dbval-mtg->gaps.ugap1;
        justGap2->GetValue().ToDouble(&dbval);
        mtg->gaps.djust=dbval-mtg->gaps.dgap1;
        justGap3->GetValue().ToDouble(&dbval);
        mtg->gaps.ljust=dbval-mtg->gaps.lgap1;
        justGap4->GetValue().ToDouble(&dbval);
        mtg->gaps.rjust=dbval-mtg->gaps.rgap1;
        if(mtg_store_gaps(mtg))
        {
            WriteMsg(_("参数设置成功！"),0);
            UpdateLasers();
            laserFig->Refresh();
        }
        else
        {
            WriteMsg(_("参数设置失败！"),1);
        }
    }
    btnJust->Refresh();
}

void TailSpaceDlg::OnPaintQuery(wxPaintEvent& event)
{
    wxPaintDC dc(btnQuery);
    int w,h;
    btnQuery->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);

        memDC.SetFont(chs);
        memDC.SetPen(wxPen(wxColor(158,158,158)));

        int x1=0;
        int y1=0;
        int w1=w;
        int h1=22;

        tgButton[ID_TG_QRY].x=x1;
        tgButton[ID_TG_QRY].y=y1;
        tgButton[ID_TG_QRY].width=w1;
        tgButton[ID_TG_QRY].height=h1;

        if(motion==ID_TG_QRY)
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
        memDC.DrawLabel(_("查询"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+7;
        tgButton[ID_TG_EXP].x=x1;
        tgButton[ID_TG_EXP].y=y1;
        tgButton[ID_TG_EXP].width=w1;
        tgButton[ID_TG_EXP].height=h1;

        if(motion==ID_TG_EXP)
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

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnMotionQuery(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>tgButton[ID_TG_QRY].x && x<tgButton[ID_TG_QRY].x+tgButton[ID_TG_QRY].width)
    {
        if(y>tgButton[ID_TG_QRY].y && y<tgButton[ID_TG_QRY].y+tgButton[ID_TG_QRY].height)
        {
            motion=ID_TG_QRY;
        }
        else if(y>tgButton[ID_TG_EXP].y && y<tgButton[ID_TG_EXP].y+tgButton[ID_TG_EXP].height)
        {
            motion=ID_TG_EXP;
        }
        else
        {
            motion=ID_TG_NONE;
        }
    }
    else
    {
        motion=ID_TG_NONE;
    }
    btnQuery->Refresh();
}

void TailSpaceDlg::OnLeaveQuery(wxMouseEvent& event)
{
    motion=ID_TG_NONE;
    btnQuery->Refresh();
}

void TailSpaceDlg::OnClickQuery(wxMouseEvent& event)
{
    int ret=0;
    if(motion==ID_TG_QRY)
    {
        nres=0;
        if(res) free(res);
        res=0;
        nres=mtg_query_gaps(mtg,&res);
        UpdateQuery();
    }
    btnQuery->Refresh();
}

void TailSpaceDlg::UpdateQuery()
{
    qryList->DeleteAllItems();
    for(int i=0;i<nres;i++)
    {
        qryList->InsertItem(i,_(""));
        qryList->SetItem(i,1,wxString::Format(_("%d"),i+1));
        qryList->SetItem(i,2,wxString::Format(_("%.1f"),res[i].ugap1*1000.0));
        qryList->SetItem(i,3,wxString::Format(_("%.1f"),res[i].dgap1*1000.0));
        qryList->SetItem(i,4,wxString::Format(_("%.1f"),res[i].lgap1*1000.0));
        qryList->SetItem(i,5,wxString::Format(_("%.1f"),res[i].rgap1*1000.0));
        qryList->SetItem(i,6,wxDateTime(res[i].t).Format(_("%Y-%m-%d %H:%M:%S")));
    }
}

void TailSpaceDlg::OnPaintBottom(wxPaintEvent& event)
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

        w1=65;
        h1=26;
        x1=w-w1-12;
        y1=9;
        tgButton[ID_TG_BTN_QUIT].x=x1;
        tgButton[ID_TG_BTN_QUIT].y=y1;
        tgButton[ID_TG_BTN_QUIT].width=w1;
        tgButton[ID_TG_BTN_QUIT].height=h1;
        if(motion==ID_TG_BTN_QUIT)
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
        //memDC.SetPen(wxPen(wxColor(117,117,117)));

        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("退出"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1=56;

        if(m_msgc==0)
        {
            memDC.SetTextForeground(wxColor(0,0,255));
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,0,0));
        }
        if(m_msg!=wxEmptyString) memDC.DrawLabel(m_msg,wxRect(x1,y1,0,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,0,w,0);

        x1=9;
        y1=9;
        h1=26;
        w1=h1*4/3;

        tgButton[ID_TG_PRT_SCN].x=x1;
        tgButton[ID_TG_PRT_SCN].y=y1;
        tgButton[ID_TG_PRT_SCN].width=w1;
        tgButton[ID_TG_PRT_SCN].height=h1;
        if(motion==ID_TG_PRT_SCN)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
        }
        int x2,y2;
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

void TailSpaceDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>tgButton[ID_TG_BTN_QUIT].y && y<tgButton[ID_TG_BTN_QUIT].y+tgButton[ID_TG_BTN_QUIT].height)
    {
        if(x>tgButton[ID_TG_BTN_QUIT].x && x<tgButton[ID_TG_BTN_QUIT].x+tgButton[ID_TG_BTN_QUIT].width)
        {
            motion=ID_TG_BTN_QUIT;
            //if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
        }
        else if(x>tgButton[ID_TG_PRT_SCN].x && x<tgButton[ID_TG_PRT_SCN].x+tgButton[ID_TG_PRT_SCN].width)
        {
            motion=ID_TG_PRT_SCN;
            //if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
        }
        else
        {
            motion=ID_TG_NONE;
            //if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
        }
    }
    else
    {
        motion=ID_TG_NONE;
        //if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
    }
    panelBottom->Refresh();
}

void TailSpaceDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_TG_NONE;
    panelBottom->Refresh();
}

void TailSpaceDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_TG_BTN_QUIT)
    {
        Destroy();
    }
    else if(motion==ID_TG_PRT_SCN)
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
        str=_("间隙界面");
        str+=wxDateTime(t).Format(_("(%Y%m%d%H%M).bmp"));
        wxFileDialog dlg(this,_("请选择保存路径"),_(""),str,_("图像(*.bmp)|*.bmp"),wxFD_SAVE);
        if(dlg.ShowModal()==wxID_OK)
        {
            str=dlg.GetPath();
            bitmap.SaveFile(str,wxBITMAP_TYPE_BMP);
        }
    }
}

void TailSpaceDlg::WriteMsg(wxString msg,int col)
{
    m_msg=msg;
    m_msgc=col;
    panelBottom->Refresh();
}

void TailSpaceDlg::UpdateLasers()
{
    lasers->DeleteAllItems();
    //wxMessageBox(wxString::Format(_("%d"),mtg->gaps.nSensor));
    radiusTxt1->SetValue(wxString::Format(_("%.3f"),mtg->gaps.radius));
    for(int i=0;i<5;i++)
    {
        lasers->InsertItem(i,_(""));
        lasers->SetItem(i,1,wxString::Format(_("%d"),i+1));
        lasers->SetItem(i,2,wxString::Format(_("0X%0X"),mtg->dister[i].id));
        if(mtg->dister[i].isok==0) lasers->SetItem(i,3,_("√"));
        else lasers->SetItem(i,3,_("×"));
        lasers->SetItem(i,4,wxString::Format(_("%.4f"),mtg->dister[i].angle*180/PI));
        lasers->SetItem(i,5,wxString::Format(_("%.4f"),mtg->dister[i].dist));
        if(mtg->dister[i].sel==0) lasers->SetItem(i,6,_("√"));
        else lasers->SetItem(i,6,_("×"));
    }
}

void TailSpaceDlg::UpdateMeas()
{
    measList->DeleteAllItems();
    for(int i=0;i<5;i++)
    {
        measList->InsertItem(i,_(""));
        measList->SetItem(i,1,wxString::Format(_("%d"),i+1));
        measList->SetItem(i,2,wxString::Format(_("0X%0X"),mtg->dister[i].id));
        measList->SetItem(i,3,wxString::Format(_("%.4f"),mtg->dister[i].dist1));
        measList->SetItem(i,4,wxString::Format(_("%.4f"),mtg->dister[i].dist0));
    }
}

void TailSpaceDlg::LoadData()
{
    int val1,val2,val3,val4,val5;

    /*char *result=NULL;
    int No1,No2,No3,No4;
    trace(0,"tailspace:ip=%s\n",mtg->gaps.IP);
    result=strtok(mtg->gaps.IP,".");
    trace(0,"tailspace:ip=%s\n",mtg->gaps.IP);
    if(result!=NULL)
    {
        sscanf(result,"%d",&No1);
        result=strtok(NULL,".");
        if(result!=NULL)
        {
            sscanf(result,"%d",&No2);
            result=strtok(NULL,".");
            if(result!=NULL)
            {
                sscanf(result,"%d",&No3);
                result=strtok(NULL,".");
                sscanf(result,"%d",&No4);
            }
        }
    }*/
    ipTxt1->SetValue(wxString::Format(_("%d"),192));
    ipTxt2->SetValue(wxString::Format(_("%d"),168));
    ipTxt3->SetValue(wxString::Format(_("%d"),0));
    ipTxt4->SetValue(wxString::Format(_("%d"),113));
    portTxt->SetValue(wxString::Format(_("%d"),5300));
    radiusTxt1->SetValue(wxString::Format(_("%.3f"),mtg->gaps.radius));
    radiusTxt2->SetValue(wxString::Format(_("%.3f"),mtg->gaps.d1));
    laserFig->Refresh();
    gapTxt1->SetValue(wxString::Format(_("%.1f"),mtg->gaps.ugap1*1000.0));
    gapTxt2->SetValue(wxString::Format(_("%.1f"),mtg->gaps.dgap1*1000.0));
    gapTxt3->SetValue(wxString::Format(_("%.1f"),mtg->gaps.lgap1*1000.0));
    gapTxt4->SetValue(wxString::Format(_("%.1f"),mtg->gaps.rgap1*1000.0));
    measGap1->SetValue(wxString::Format(_("%.1f"),mtg->gaps.ugap1*1000.0));
    measGap2->SetValue(wxString::Format(_("%.1f"),mtg->gaps.dgap1*1000.0));
    measGap3->SetValue(wxString::Format(_("%.1f"),mtg->gaps.lgap1*1000.0));
    measGap4->SetValue(wxString::Format(_("%.1f"),mtg->gaps.rgap1*1000.0));
    justGap1->SetValue(wxString::Format(_("%.1f"),mtg->gaps.ugap*1000.0));
    justGap2->SetValue(wxString::Format(_("%.1f"),mtg->gaps.dgap*1000.0));
    justGap3->SetValue(wxString::Format(_("%.1f"),mtg->gaps.lgap*1000.0));
    justGap4->SetValue(wxString::Format(_("%.1f"),mtg->gaps.rgap*1000.0));
    UpdateLasers();
    UpdateMeas();
}

void TailSpaceDlg::Apply()
{
    //long val1,val2,val3,val4;
    //long val5;
    //char str1[20];
    //int baud[]={1200,2400,4800,9600.14400,38400,56000,115200};

    //ipTxt1->GetValue().ToLong(&val1);
    //ipTxt2->GetValue().ToLong(&val2);
    //ipTxt3->GetValue().ToLong(&val3);
    //ipTxt4->GetValue().ToLong(&val4);
    //sprintf(str1,"%d.%d.%d.%d",val1,val2,val3,val4);
    //strcpy(mtg->gaps.IP,str1);
    ///comset[0].port=baud[val5];
    //portTxt->GetValue().ToLong(&val5);
    //mtg->gaps.port=val5;
    //trace(0,"ip:%s,port:%d\n",mtg->gaps.IP,mtg->gaps.port);
    //mtg_store_gaps(mtg);
    //WriteMsg(_("保存通讯参数并连接..."),0);
    //else WriteMsg(_("端口打开失败，请检查！"),1);
}

void TailSpaceDlg::OnTimer(wxTimerEvent& event)
{
    static int tick=0;
    int i=0;
    double dbval=0.0;
    wxString str;
    if(mtg->plog>0)
    {
        wxString strLog;
        for(i=0;i<mtg->plog;i++)
        {
            switch(mtg->plogs[i].nlog)
            {
                case MTG_LOG_BEGIN_DIST_CONNECT:
                case MTG_LOG_FAIL_DIST_CONNECT:
                case MTG_LOG_BEGIN_DIST_TBM:
                case MTG_LOG_FINISH_DIST_TBM:
                case MTG_LOG_FAIL_DIST_TBM:
                case MTG_LOG_BEGIN_DIST_SEG:
                case MTG_LOG_FINISH_DIST_CONNECT:
                    strLog = wxString(mtg->plogs[i].msg,wxConvLocal);
                    WriteMsg(strLog,mtg->plogs[i].type);
                    UpdateLasers();
                    break;
                case MTG_LOG_FAIL_DIST_SEG:
                    strLog = wxString(mtg->plogs[i].msg,wxConvLocal);
                    WriteMsg(strLog,mtg->plogs[i].type);
                    break;
                case MTG_LOG_FINISH_DIST_SEG:
                    UpdateMeas();
                    gapTxt1->SetValue(wxString::Format(_("%.1f"),mtg->gaps.ugap1*1000.0));
                    gapTxt2->SetValue(wxString::Format(_("%.1f"),mtg->gaps.dgap1*1000.0));
                    gapTxt3->SetValue(wxString::Format(_("%.1f"),mtg->gaps.lgap1*1000.0));
                    gapTxt4->SetValue(wxString::Format(_("%.1f"),mtg->gaps.rgap1*1000.0));
                    strLog = wxString(mtg->plogs[i].msg,wxConvLocal);
                    WriteMsg(strLog,mtg->plogs[i].type);
                    break;
                default:
                    break;
            }
        }
    }
}


