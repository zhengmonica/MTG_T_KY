/***************************************************************
 * Name:      mtg_tMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    dengdeyan (dengdeyan@medosurvey.com)
 * Created:   2011-03-21
 * Copyright: dengdeyan (http://www.medosurvey.com)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "msr_tMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(mtg_tFrame)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include <wx/dcclient.h>
#include "msr_tApp.h"
#include "DtaDlg.h"
#include "tbmDlg.h"
#include "segtDlg.h"
#include "blockDlg.h"
#include "prjDlg.h"
#include <wx/stdpaths.h>
#include <wx/imaglist.h>
#include <wx/dcbuffer.h>
#include "libele.h"
#include <wx/config.h>
#include "gtime.h"

#define PI  3.1415926535897932384626433832795

//(*IdInit(mtg_tFrame)

//*)

BEGIN_EVENT_TABLE(mtg_tFrame,wxFrame)
    //(*EventTable(mtg_tFrame)
    EVT_CLOSE(mtg_tFrame::OnClose)
    //*)
END_EVENT_TABLE()

mtg_tFrame::mtg_tFrame(wxWindow* parent,wxWindowID id)
{
    wxStandardPaths stdp;
    wxString path=stdp.GetExecutablePath();
    #ifdef WIN32
    int t=path.Find('\\',true);
    #else
    int t=path.Find('/',true);
    #endif
    path=path.SubString(0,t-1);
    bmpLogo.LoadFile(path+_("/plugins/logo.png"),wxBITMAP_TYPE_PNG);
    bmpImport.LoadFile(path+_("/plugins/prj_import.png"),wxBITMAP_TYPE_PNG);
    bmpExport.LoadFile(path+_("/plugins/prj_export.png"),wxBITMAP_TYPE_PNG);
    bmpClear.LoadFile(path+_("/plugins/prj_clear.png"),wxBITMAP_TYPE_PNG);
    bmpDTA.LoadFile(path+_("/plugins/dta.png"),wxBITMAP_TYPE_PNG);
    bmpTBM.LoadFile(path+_("/plugins/tbm.png"),wxBITMAP_TYPE_PNG);
    bmpBLK.LoadFile(path+_("/plugins/block.png"),wxBITMAP_TYPE_PNG);
    bmpNEW.LoadFile(path+_("/plugins/newprj.png"),wxBITMAP_TYPE_PNG);
    bmpReport.LoadFile(path+_("/plugins/sreport.png"),wxBITMAP_TYPE_PNG);
    bmpAbout.LoadFile(path+_("/plugins/about.png"),wxBITMAP_TYPE_PNG);
    bmpPrj.LoadFile(path+_("/plugins/prj.png"),wxBITMAP_TYPE_PNG);
    bmpSave.LoadFile(path+_("/plugins/save.png"),wxBITMAP_TYPE_PNG);
    bmpSave1.LoadFile(path+_("/plugins/save1.png"),wxBITMAP_TYPE_PNG);
    int w,h;

    //(*Initialize(mtg_tFrame)
    Create(parent, id, _("MSR-T盾构管环选型"), wxDefaultPosition, wxDefaultSize, wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN, _T("id"));
    SetClientSize(wxSize(1024,768));
    this->GetSize(&w,&h);
    panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTool = new wxPanel(panelMain, wxID_ANY, wxPoint(0,0), wxSize(w,32), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelTip = new wxPanel(panelMain, wxID_ANY, wxPoint(0,32), wxSize(w,24), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPage = new wxPanel(panelMain, wxID_ANY, wxPoint(0,56), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    int x1,y1,w1,h1;
    x1=0;
    y1=106;
    w1=w-x1*2;
    h1=h-161;
    panelDes = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelDes->Show(true);
    panelSel = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSel->Show(false);
    desButton = new wxPanel(panelDes, wxID_ANY, wxPoint(0,0), wxSize(115,h1-2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    desSelPage = new wxPanel(panelDes, wxID_ANY, wxPoint(115,0), wxSize(w-115,h1-2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desSelPage->SetBackgroundColour(wxColor(237,240,245));
    desSelPage->Show(true);
    designList = new wxPanel(panelDes, wxID_ANY, wxPoint(115,0), wxSize(w-115,h1-2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    designList->SetBackgroundColour(wxColor(237,240,245));
    designList->Show(false);
    int x2,y2,w2,h2;
    x2=14;
    y2=11;
    w2=(w-159)/2;
    h2=w2;
    desSelTi = new wxPanel(desSelPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desSelTi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y2=y2+95;

    desKi = new wxPanel(desSelPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desKi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x2+w2+14;
    y2=11;
    w2=w-145-x2;
    h2=88;
    desTxt = new wxPanel(desSelPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desTxt->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    des_id_text = new wxTextCtrl(desTxt, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    des_mile_text = new wxTextCtrl(desTxt, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    y2=y2+h2+7;
    desListHeader = new wxPanel(desSelPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,24), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    desListHeader->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y2+=23;
    h2=h1-y2-78;
    desListView = new wxListView(desSelPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    desListView->SetBackgroundColour(wxColor(238,244,250));
    designCal = new wxPanel(desSelPage, wxID_ANY, wxPoint(x2,y2), wxSize(80,23), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    designCal->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    designCal->Show(false);

    x2=14;
    y2=11;
    w2=w-179;
    h2=24;
    designListHeader = new wxPanel(designList, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    designListHeader->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y2+=24;
    h2=h1-y2-72;
    desList = new wxListView(designList, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));

    selButton = new wxPanel(panelSel, wxID_ANY, wxPoint(0,0), wxSize(115,h1-2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    selButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    selLastPage = new wxPanel(panelSel, wxID_ANY, wxPoint(115,0), wxSize(w-115,h1-2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    selLastPage->SetBackgroundColour(wxColor(237,240,245));
    selLastPage->Show(true);
    segPage = new wxPanel(panelSel, wxID_ANY, wxPoint(115,0), wxSize(w-115,h1-2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    segPage->SetBackgroundColour(wxColor(237,240,245));
    segPage->Show(false);
    x2=14;
    y2=11;
    w2=(w-159)/2;
    h2=w2;
    selLastKi = new wxPanel(selLastPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    selLastKi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x2+w2+14;
    w2=w-165-x2;
    h2=68;
    selLastPi = new wxPanel(selLastPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    selLastPi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    sel_last_idtxt = new wxTextCtrl(selLastPi, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    y2=y2+h2+7;
    selLastTi = new wxPanel(selLastPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,23), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    selLastTi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    x2=14;
    y2=11;
    w2=(w-159)/2;
    h2=87;
    //h2=w2;
    segList = new wxPanel(segPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    segList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    y2=y2+h2+7;
    h2=w2;
    segKi = new wxPanel(segPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    segKi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x2+w2+14;
    y2=0;
    w2=w-165-x2;
    h2=68;
    segTxt = new wxPanel(segPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,98), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    segTxt->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    seg_id_text = new wxTextCtrl(segTxt, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator);
    y2+=105;
    segTi = new wxPanel(segPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,23), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    segTi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    //y2+=30;
    h2=(w-159)/2;
    resFig = new wxPanel(segPage, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    resFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelBar = new wxPanel(this, wxID_ANY, wxPoint(0,h-28), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    panelLogo = new wxPanel(panelMain, wxID_ANY, wxPoint(834,0), wxSize(190,125), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    //panelBar->Show(false);
    panelLogo->Show(false);



    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTool->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelTip->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelDes->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelSel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelLogo->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelBar->SetBackgroundStyle(wxBG_STYLE_CUSTOM);


    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintMain,0,this);

    panelTool->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintTool,0,this);
    panelTool->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionTool,0,this);
    panelTool->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveTool,0,this);
    panelTool->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickTool,0,this);

    panelTip->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintTip,0,this);

    panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickPage,0,this);

    panelDes->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintDes,0,this);
    desButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintDesButton,0,this);
    desButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionDesButton,0,this);
    desButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveDesButton,0,this);
    desButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickDesButton,0,this);

    desKi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintDesKi,0,this);
    desKi->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionDesKi,0,this);
    desKi->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveDesKi,0,this);
    desKi->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickDesKi,0,this);

    desTxt->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintDesTxt,0,this);
    desTxt->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionDesTxt,0,this);
    desTxt->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveDesTxt,0,this);
    desTxt->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickDesTxt,0,this);

    desSelTi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintDesSelTi,0,this);
    desSelTi->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionDesSelTi,0,this);
    desSelTi->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveDesSelTi,0,this);
    desSelTi->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickDesSelTi,0,this);
    desListHeader->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintDesListHeader,0,this);

    designCal->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintDesignCal,0,this);
    designCal->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionDesignCal,0,this);
    designCal->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveDesignCal,0,this);
    designCal->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickDesignCal,0,this);

    designListHeader->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintDesignHeader,0,this);

    panelSel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintSel,0,this);
    selButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintSelButton,0,this);
    selButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionSelButton,0,this);
    selButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveSelButton,0,this);
    selButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickSelButton,0,this);

    selLastKi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintLastKi,0,this);
    selLastKi->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionLastKi,0,this);
    selLastKi->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveLastKi,0,this);
    selLastKi->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickLastKi,0,this);

    selLastPi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintLastPi,0,this);
    selLastPi->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionLastPi,0,this);
    selLastPi->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveLastPi,0,this);
    selLastPi->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickLastPi,0,this);

    selLastTi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintLastTi,0,this);
    selLastTi->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionLastTi,0,this);
    selLastTi->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveLastTi,0,this);
    selLastTi->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickLastTi,0,this);

    segList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintSegList,0,this);
    segList->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionSegList,0,this);
    segList->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveSegList,0,this);
    segList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickSegList,0,this);

    segKi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintKiFig,0,this);
    segKi->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionKiFig,0,this);
    segKi->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveKiFig,0,this);
    segKi->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickKiFig,0,this);

    segTxt->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintSegTxt,0,this);
    segTxt->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionSegTxt,0,this);
    segTxt->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveSegTxt,0,this);
    segTxt->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickSegTxt,0,this);

    resFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintResFig,0,this);

    segTi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintSegTi,0,this);
    segTi->Connect(wxEVT_MOTION,(wxObjectEventFunction)&mtg_tFrame::OnMotionSegTi,0,this);
    segTi->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&mtg_tFrame::OnLeaveSegTi,0,this);
    segTi->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&mtg_tFrame::OnClickSegTi,0,this);

    panelLogo->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintLogo,0,this);

    panelBar->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mtg_tFrame::OnPaintBar,0,this);


    this->Connect(wxEVT_SIZE,(wxObjectEventFunction)&mtg_tFrame::OnSize,0,this);
    //*)
    //Center();

    int i=0;
    desListView->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    desListView->InsertColumn(i++,_("环号"),wxLIST_FORMAT_CENTRE,55);
    desListView->InsertColumn(i++,_("类型"),wxLIST_FORMAT_CENTRE,60);
    desListView->InsertColumn(i++,_("点位"),wxLIST_FORMAT_CENTRE,50);
    desListView->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,85);
    desListView->InsertColumn(i++,_("左超(mm)"),wxLIST_FORMAT_CENTRE,60);
    desListView->InsertColumn(i++,_("上超(mm)"),wxLIST_FORMAT_CENTRE,60);
    i=0;
    desList->InsertColumn(i++,_(""),wxLIST_FORMAT_CENTRE,0);
    desList->InsertColumn(i++,_("环号"),wxLIST_FORMAT_CENTRE,75);
    desList->InsertColumn(i++,_("类型"),wxLIST_FORMAT_CENTRE,75);
    desList->InsertColumn(i++,_("点位"),wxLIST_FORMAT_CENTRE,75);
    desList->InsertColumn(i++,_("里程"),wxLIST_FORMAT_CENTRE,120);
    desList->InsertColumn(i++,_("左超前"),wxLIST_FORMAT_CENTRE,90);
    desList->InsertColumn(i++,_("上超前"),wxLIST_FORMAT_CENTRE,90);
    desList->InsertColumn(i++,_("水平偏差"),wxLIST_FORMAT_CENTRE,100);
    desList->InsertColumn(i++,_("垂直偏差"),wxLIST_FORMAT_CENTRE,100);

    motion=ID_BTN_NONE;
    page=ID_BTN_PAGE_DES;
    desPage=ID_BTN_DES_SEL;
    selPage=ID_BTN_SEL_LAST;

    isel=0;
    dsel=0;

    checkBoxWidth=14;
    checkBoxHeight=14;
    radioBoxR1=7;
    radioBoxR2=4;

    des_id_text->SetValue(wxString::Format(_("%d"),msr->dseg.numb));
    des_mile_text->SetValue(wxString::Format(_("%.4f"),msr->prj.mile1));
    if(msr->dcal==0)
    {
        int j=1;
        int k=msr->segt.Ks;
        wxString istr=wxEmptyString;
        desListView->InsertItem(0,_(""));
        desListView->SetItem(0,j++,wxString::Format(_("%d"),msr->des[0].numb)); ///管片号
        if(msr->des[0].type==0) istr=_("通用环");
        else if(msr->des[0].type==1) istr=_("标准环");
        else if(msr->des[0].type==2) istr=_("左转弯");
        else if(msr->des[0].type==3) istr=_("右转弯");
        desListView->SetItem(0,j++,istr); ///类型
        if(msr->des[0].k<k/2) istr=wxString::Format(_("%d"),msr->des[0].k+1);
        else istr=wxString::Format(_("%d"),msr->des[0].k+2);
        desListView->SetItem(0,j++,istr); ///点位
        desListView->SetItem(0,j++,wxString::Format(_("%.3f"),msr->des[0].mile)); ///
        desListView->SetItem(0,j++,wxString::Format(_("%.1f"),msr->des[0].harc*1000.0)); ///
        desListView->SetItem(0,j++,wxString::Format(_("%.1f"),msr->des[0].varc*1000.0)); ///
        desListView->Select(0);
    }
    SetIcon(wxICON(aaaa));
    //#endif
}

mtg_tFrame::~mtg_tFrame()
{
    //(*Destroy(mtg_tFrame)
    //*)
}

void mtg_tFrame::UpdateDesign()
{
    desList->DeleteAllItems();
    desListView->DeleteAllItems();
    wxString istr;
    double ls,rs;
    int k=msr->segt.Ks;
    for(int i=0;i<msr->ndes;i++)
    {
        int j=1;
        desList->InsertItem(i,_(""));
        desListView->InsertItem(i,_(""));
        desList->SetItem(i,j,wxString::Format(_("%d"),msr->des[i].numb)); ///管片号
        desListView->SetItem(i,j++,wxString::Format(_("%d"),msr->des[i].numb)); ///管片号
        if(msr->des[i].type==0) istr=_("通用环");
        else if(msr->des[i].type==1) istr=_("标准环");
        else if(msr->des[i].type==2) istr=_("左转弯");
        else if(msr->des[i].type==3) istr=_("右转弯");
        desList->SetItem(i,j,istr); ///类型
        desListView->SetItem(i,j++,istr); ///类型
        if(msr->des[i].k<k/2) istr=wxString::Format(_("%d"),msr->des[i].k+1);
        else istr=wxString::Format(_("%d"),msr->des[i].k+2);
        desList->SetItem(i,j,istr); ///点位
        desListView->SetItem(i,j++,istr); ///点位
        desList->SetItem(i,j,wxString::Format(_("%.3f"),msr->des[i].mile)); ///
        desListView->SetItem(i,j++,wxString::Format(_("%.3f"),msr->des[i].mile)); ///
        desList->SetItem(i,j,wxString::Format(_("%.1f"),msr->des[i].harc*1000.0)); ///
        desListView->SetItem(i,j++,wxString::Format(_("%.1f"),msr->des[i].harc*1000.0)); ///
        desList->SetItem(i,j,wxString::Format(_("%.1f"),msr->des[i].varc*1000.0)); ///
        desListView->SetItem(i,j++,wxString::Format(_("%.1f"),msr->des[i].varc*1000.0)); ///
        desList->SetItem(i,j++,wxString::Format(_("%.1f"),msr->des[i].dh*1000.0)); ///
        desList->SetItem(i,j++,wxString::Format(_("%.1f"),msr->des[i].dv*1000.0)); ///
        //desList->SetItem(i,j++,wxString::Format(_("%.1f"),mtg->segings[i].tailh*1000.0)); ///
        //desList->SetItem(i,j++,wxString::Format(_("%.1f"),mtg->segings[i].tailv*1000.0)); ///
    }
}

void mtg_tFrame::OnPaintDesListHeader(wxPaintEvent& event)
{
    wxPaintDC dc(desListHeader);
    int w,h;
    desListHeader->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=24;
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        int i=1;
        //memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=desListView->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desListView->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desListView->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desListView->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desListView->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("左超(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desListView->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("上超(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        /*x1+=w1;
        w1=desListView->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("平偏(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desListView->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("高偏(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        */
        x1+=w1;
        w1=desListView->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnPaintDesignHeader(wxPaintEvent& event)
{
    wxPaintDC dc(designListHeader);
    int w,h;
    designListHeader->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen((wxColor(238,244,250))));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        wxString istr;
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=25;
        memDC.SetPen(wxPen(wxColor(135,135,135)));
        memDC.SetBrush(wxBrush(wxColor(249,249,249)));
        memDC.DrawRectangle(x1,y1,w1,h1);
        int i=1;
        //memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("环号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("点位"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("左超前(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("上超前(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("平偏(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("高偏(mm)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        w1=desList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnPaintMain(wxPaintEvent& event)
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
        memDC.DrawRectangle(-1,84,w+2,20);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,104,w,104);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(-1,105,w+2,h-105);

        //memDC.DrawLabel(_("kk"),wxRect(0,84,100,20),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //memDC.SetPen(wxPen(wxColor(172,168,153)));
        //memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnClose(wxCloseEvent& event)
{
    event.Skip();
}

void mtg_tFrame::OnPaintTool(wxPaintEvent& event)
{
    wxBufferedPaintDC dc(panelTool);
    int w,h;
    panelTool->GetClientSize(&w,&h);

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
        //wxFont eng(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        int x1,y1,w1,h1;
        int w2,h2;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        x1=5;
        y1=3;
        h1=26;
        w1=h1*4/3;
        button[ID_BTN_NEW].x=x1;
        button[ID_BTN_NEW].y=y1;
        button[ID_BTN_NEW].width=w1;
        button[ID_BTN_NEW].height=h1;
        if(motion==ID_BTN_NEW)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(bmpNEW.IsOk())
            {
                w2=bmpNEW.GetWidth();
                h2=bmpNEW.GetHeight();
                memDC.DrawBitmap(bmpNEW,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            if(bmpNEW.IsOk())
            {
                w2=bmpNEW.GetWidth();
                h2=bmpNEW.GetHeight();
                memDC.DrawBitmap(bmpNEW,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+3;
        button[ID_BTN_CLEAR].x=x1;
        button[ID_BTN_CLEAR].y=y1;
        button[ID_BTN_CLEAR].width=w1;
        button[ID_BTN_CLEAR].height=h1;

        if(motion==ID_BTN_CLEAR)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(bmpClear.IsOk())
            {
                w2=bmpClear.GetWidth();
                h2=bmpClear.GetHeight();
                memDC.DrawBitmap(bmpClear,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            if(bmpClear.IsOk())
            {
                w2=bmpClear.GetWidth();
                h2=bmpClear.GetHeight();
                memDC.DrawBitmap(bmpClear,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+3;
        button[ID_BTN_IMP].x=x1;
        button[ID_BTN_IMP].y=y1;
        button[ID_BTN_IMP].width=w1;
        button[ID_BTN_IMP].height=h1;

        if(motion==ID_BTN_IMP)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(bmpImport.IsOk())
            {
                w2=bmpImport.GetWidth();
                h2=bmpImport.GetHeight();
                memDC.DrawBitmap(bmpImport,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            if(bmpImport.IsOk())
            {
                w2=bmpImport.GetWidth();
                h2=bmpImport.GetHeight();
                memDC.DrawBitmap(bmpImport,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+3;
        button[ID_BTN_EXP].x=x1;
        button[ID_BTN_EXP].y=y1;
        button[ID_BTN_EXP].width=w1;
        button[ID_BTN_EXP].height=h1;

        if(motion==ID_BTN_EXP)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(bmpExport.IsOk())
            {
                w2=bmpExport.GetWidth();
                h2=bmpExport.GetHeight();
                memDC.DrawBitmap(bmpExport,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            if(bmpExport.IsOk())
            {
                w2=bmpExport.GetWidth();
                h2=bmpExport.GetHeight();
                memDC.DrawBitmap(bmpExport,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+7;
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1,6,x1,h-6);
        x1+=1;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1,6,x1,h-6);

        x1=x1+7;
        button[ID_BTN_SAVE].x=x1;
        button[ID_BTN_SAVE].y=y1;
        button[ID_BTN_SAVE].width=w1;
        button[ID_BTN_SAVE].height=h1;

        if(motion==ID_BTN_SAVE)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(bmpSave.IsOk())
            {
                w2=bmpSave.GetWidth();
                h2=bmpSave.GetHeight();
                memDC.DrawBitmap(bmpSave,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            if(bmpSave.IsOk())
            {
                w2=bmpSave.GetWidth();
                h2=bmpSave.GetHeight();
                memDC.DrawBitmap(bmpSave,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+7;
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1,6,x1,h-6);
        x1+=1;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1,6,x1,h-6);

        x1=x1+7;
        button[ID_BTN_PRJ].x=x1;
        button[ID_BTN_PRJ].y=y1;
        button[ID_BTN_PRJ].width=w1;
        button[ID_BTN_PRJ].height=h1;

        if(motion==ID_BTN_PRJ)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(bmpPrj.IsOk())
            {
                w2=bmpPrj.GetWidth();
                h2=bmpPrj.GetHeight();
                memDC.DrawBitmap(bmpPrj,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            if(bmpPrj.IsOk())
            {
                w2=bmpPrj.GetWidth();
                h2=bmpPrj.GetHeight();
                memDC.DrawBitmap(bmpPrj,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+3;
        button[ID_BTN_DTA].x=x1;
        button[ID_BTN_DTA].y=y1;
        button[ID_BTN_DTA].width=w1;
        button[ID_BTN_DTA].height=h1;

        if(motion==ID_BTN_DTA)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(bmpDTA.IsOk())
            {
                w2=bmpDTA.GetWidth();
                h2=bmpDTA.GetHeight();
                memDC.DrawBitmap(bmpDTA,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            if(bmpDTA.IsOk())
            {
                w2=bmpDTA.GetWidth();
                h2=bmpDTA.GetHeight();
                memDC.DrawBitmap(bmpDTA,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+3;
        button[ID_BTN_TBM].x=x1;
        button[ID_BTN_TBM].y=y1;
        button[ID_BTN_TBM].width=w1;
        button[ID_BTN_TBM].height=h1;

        if(motion==ID_BTN_TBM)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(bmpTBM.IsOk())
            {
                w2=bmpTBM.GetWidth();
                h2=bmpTBM.GetHeight();
                memDC.DrawBitmap(bmpTBM,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            if(bmpTBM.IsOk())
            {
                w2=bmpTBM.GetWidth();
                h2=bmpTBM.GetHeight();
                memDC.DrawBitmap(bmpTBM,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+3;
        button[ID_BTN_GEO].x=x1;
        button[ID_BTN_GEO].y=y1;
        button[ID_BTN_GEO].width=w1;
        button[ID_BTN_GEO].height=h1;

        if(motion==ID_BTN_GEO)
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawRectangle(x1+7,y1+4,5,h1-8);
            memDC.SetPen(wxPen(wxColor(255,117,117)));
            memDC.DrawRectangle(x1+15,y1+4,5,h1-8);
            memDC.SetPen(wxPen(wxColor(0,117,255)));
            memDC.DrawRectangle(x1+23,y1+4,5,h1-8);
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.DrawRectangle(x1+7,y1+4,5,h1-8);
            memDC.SetPen(wxPen(wxColor(255,117,117)));
            memDC.DrawRectangle(x1+15,y1+4,5,h1-8);
            memDC.SetPen(wxPen(wxColor(0,117,255)));
            memDC.DrawRectangle(x1+23,y1+4,5,h1-8);
        }

        x1=x1+w1+3;
        button[ID_BTN_BLK].x=x1;
        button[ID_BTN_BLK].y=y1;
        button[ID_BTN_BLK].width=w1;
        button[ID_BTN_BLK].height=h1;
        if(motion==ID_BTN_BLK)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(bmpBLK.IsOk())
            {
                w2=bmpBLK.GetWidth();
                h2=bmpBLK.GetHeight();
                memDC.DrawBitmap(bmpBLK,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            if(bmpBLK.IsOk())
            {
                w2=bmpBLK.GetWidth();
                h2=bmpBLK.GetHeight();
                memDC.DrawBitmap(bmpBLK,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+7;
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1,6,x1,h-6);
        x1+=1;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1,6,x1,h-6);

        x1=x1+7;
        button[ID_BTN_REPORT].x=x1;
        button[ID_BTN_REPORT].y=y1;
        button[ID_BTN_REPORT].width=w1;
        button[ID_BTN_REPORT].height=h1;

        if(motion==ID_BTN_REPORT)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(bmpReport.IsOk())
            {
                w2=bmpReport.GetWidth();
                h2=bmpReport.GetHeight();
                memDC.DrawBitmap(bmpReport,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            if(bmpReport.IsOk())
            {
                w2=bmpReport.GetWidth();
                h2=bmpReport.GetHeight();
                memDC.DrawBitmap(bmpReport,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        x1=x1+w1+7;
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x1,6,x1,h-6);
        x1+=1;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(x1,6,x1,h-6);

        x1=x1+7;
        button[ID_BTN_ABOUT].x=x1;
        button[ID_BTN_ABOUT].y=y1;
        button[ID_BTN_ABOUT].width=w1;
        button[ID_BTN_ABOUT].height=h1;

        if(motion==ID_BTN_ABOUT)
        {
            memDC.SetPen(wxPen(wxColor(173,175,176)));
            memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            memDC.DrawRectangle(x1,y1,w1,h1);
            if(bmpAbout.IsOk())
            {
                w2=bmpAbout.GetWidth();
                h2=bmpAbout.GetHeight();
                memDC.DrawBitmap(bmpAbout,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }
        else
        {
            if(bmpAbout.IsOk())
            {
                w2=bmpAbout.GetWidth();
                h2=bmpAbout.GetHeight();
                memDC.DrawBitmap(bmpAbout,x1+w1/2-w2/2,y1+h1/2-h2/2);
            }
        }

        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawLine(0,h-2,w,h-2);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(0,h-1,w,h-1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionTool(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_CLEAR].y && y<button[ID_BTN_CLEAR].y+button[ID_BTN_CLEAR].height)
    {
        if(x>button[ID_BTN_CLEAR].x && x<button[ID_BTN_CLEAR].x+button[ID_BTN_CLEAR].width)
        {
            motion=ID_BTN_CLEAR;
        }
        else if(x>button[ID_BTN_EXP].x && x<button[ID_BTN_EXP].x+button[ID_BTN_EXP].width)
        {
            motion=ID_BTN_EXP;
        }
        else if(x>button[ID_BTN_IMP].x && x<button[ID_BTN_IMP].x+button[ID_BTN_IMP].width)
        {
            motion=ID_BTN_IMP;
        }
        else if(x>button[ID_BTN_PRJ].x && x<button[ID_BTN_PRJ].x+button[ID_BTN_PRJ].width)
        {
            motion=ID_BTN_PRJ;
        }
        else if(x>button[ID_BTN_DTA].x && x<button[ID_BTN_DTA].x+button[ID_BTN_DTA].width)
        {
            motion=ID_BTN_DTA;
        }
        else if(x>button[ID_BTN_TBM].x && x<button[ID_BTN_TBM].x+button[ID_BTN_TBM].width)
        {
            motion=ID_BTN_TBM;
        }
        else if(x>button[ID_BTN_GEO].x && x<button[ID_BTN_GEO].x+button[ID_BTN_GEO].width)
        {
            motion=ID_BTN_GEO;
        }
        else if(x>button[ID_BTN_BLK].x && x<button[ID_BTN_BLK].x+button[ID_BTN_BLK].width)
        {
            motion=ID_BTN_BLK;
        }
        else if(x>button[ID_BTN_NEW].x && x<button[ID_BTN_NEW].x+button[ID_BTN_NEW].width)
        {
            motion=ID_BTN_NEW;
        }
        else if(x>button[ID_BTN_REPORT].x && x<button[ID_BTN_REPORT].x+button[ID_BTN_REPORT].width)
        {
            motion=ID_BTN_REPORT;
        }
        else if(x>button[ID_BTN_ABOUT].x && x<button[ID_BTN_ABOUT].x+button[ID_BTN_ABOUT].width)
        {
            motion=ID_BTN_ABOUT;
        }
        else if(x>button[ID_BTN_SAVE].x && x<button[ID_BTN_SAVE].x+button[ID_BTN_SAVE].width)
        {
            motion=ID_BTN_SAVE;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }
    panelTool->Refresh();
    panelTip->Refresh();
}

void mtg_tFrame::OnLeaveTool(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    panelTool->Refresh();
}

void mtg_tFrame::OnClickTool(wxMouseEvent& event)
{
    if(motion==ID_BTN_DTA)
    {
        motion=ID_BTN_NONE;
        panelTip->Refresh();
        DtaDlg dlg(this);
        dlg.Center();
        dlg.ShowModal();
    }
    else if(motion==ID_BTN_TBM)
    {
        motion=ID_BTN_NONE;
        panelTip->Refresh();
        tbmDlg dlg(this);
        dlg.Center();
        dlg.ShowModal();
    }
    else if(motion==ID_BTN_GEO)
    {
        motion=ID_BTN_NONE;
        panelTip->Refresh();
        segtDlg dlg(this);
        dlg.Center();
        dlg.ShowModal();
    }
    else if(motion==ID_BTN_BLK)
    {
        motion=ID_BTN_NONE;
        panelTip->Refresh();
        blockDlg dlg(this);
        dlg.Center();
        dlg.ShowModal();
    }
    else if(motion==ID_BTN_PRJ)
    {
        motion=ID_BTN_NONE;
        panelTip->Refresh();
        prjDlg dlg(this);
        dlg.Center();
        dlg.ShowModal();
    }
    panelTool->Refresh();
}

void mtg_tFrame::OnPaintTip(wxPaintEvent& event)
{
    wxBufferedPaintDC dc(panelTip);
    int w,h;
    panelTip->GetClientSize(&w,&h);

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
        memDC.SetTextForeground(wxColor(0,0,255));

        wxString tips;
        int x,y;
        y=h/2;
        switch(motion)
        {
        case ID_BTN_CLEAR:
            tips=_("清空数据");
            x=button[ID_BTN_CLEAR].x;
            memDC.DrawLabel(tips,wxRect(x,y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            break;
        case ID_BTN_EXP:
            tips=_("导出工程");
            x=button[ID_BTN_EXP].x;
            memDC.DrawLabel(tips,wxRect(x,y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            break;
        case ID_BTN_IMP:
            tips=_("导入工程");
            x=button[ID_BTN_IMP].x;
            memDC.DrawLabel(tips,wxRect(x,y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            break;
        case ID_BTN_PRJ:
            tips=_("工程设置");
            x=button[ID_BTN_PRJ].x;
            memDC.DrawLabel(tips,wxRect(x,y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            break;
        case ID_BTN_DTA:
            tips=_("隧道中线");
            x=button[ID_BTN_DTA].x;
            memDC.DrawLabel(tips,wxRect(x,y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            break;
        case ID_BTN_TBM:
            tips=_("盾构参数");
            x=button[ID_BTN_TBM].x;
            memDC.DrawLabel(tips,wxRect(x,y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            break;
        case ID_BTN_GEO:
            tips=_("管环参数");
            x=button[ID_BTN_GEO].x;
            memDC.DrawLabel(tips,wxRect(x,y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            break;
        case ID_BTN_BLK:
            tips=_("管块参数");
            x=button[ID_BTN_BLK].x;
            memDC.DrawLabel(tips,wxRect(x,y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            break;
        case ID_BTN_NEW:
            tips=_("新建工程");
            x=button[ID_BTN_NEW].x;
            memDC.DrawLabel(tips,wxRect(x,y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            break;
        case ID_BTN_REPORT:
            tips=_("数据输出");
            x=button[ID_BTN_REPORT].x;
            memDC.DrawLabel(tips,wxRect(x,y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            break;
        case ID_BTN_ABOUT:
            tips=_("关于我们");
            x=button[ID_BTN_ABOUT].x;
            memDC.DrawLabel(tips,wxRect(x,y,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            break;
        default:
            break;
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnPaintPage(wxPaintEvent& event)
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
        w1=115;
        h1=h;
        button[ID_BTN_PAGE_DES].x=x1;
        button[ID_BTN_PAGE_DES].y=y1;
        button[ID_BTN_PAGE_DES].width=w1;
        button[ID_BTN_PAGE_DES].height=h1;

        if(page==ID_BTN_PAGE_DES || motion==ID_BTN_PAGE_DES)
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

            if(page!=ID_BTN_PAGE_DES)
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
        memDC.DrawLabel(_("设计排版"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);

        x1=x1+w1;
        button[ID_BTN_PAGE_CAL].x=x1;
        button[ID_BTN_PAGE_CAL].y=y1;
        button[ID_BTN_PAGE_CAL].width=w1;
        button[ID_BTN_PAGE_CAL].height=h1;
        if(page==ID_BTN_PAGE_CAL || motion==ID_BTN_PAGE_CAL)
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

            if(page!=ID_BTN_PAGE_CAL)
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
        memDC.DrawLabel(_("管环选型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1+w1;
        button[ID_BTN_PAGE_SEL].x=x1;
        button[ID_BTN_PAGE_SEL].y=y1;
        button[ID_BTN_PAGE_SEL].width=w1;
        button[ID_BTN_PAGE_SEL].height=h1;
        if(page==ID_BTN_PAGE_SEL || motion==ID_BTN_PAGE_SEL)
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
            if(page!=ID_BTN_PAGE_SEL)
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
        memDC.DrawLabel(_("历史拼装"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
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

void mtg_tFrame::OnMotionPage(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_PAGE_DES].y && y<button[ID_BTN_PAGE_DES].y+button[ID_BTN_PAGE_DES].height)
    {
        if(x>button[ID_BTN_PAGE_DES].x && x<button[ID_BTN_PAGE_DES].x+button[ID_BTN_PAGE_DES].width)
        {
            motion=ID_BTN_PAGE_DES;
        }
        else if(x>button[ID_BTN_PAGE_CAL].x && x<button[ID_BTN_PAGE_CAL].x+button[ID_BTN_PAGE_CAL].width)
        {
            motion=ID_BTN_PAGE_CAL;
        }
        else if(x>button[ID_BTN_PAGE_SEL].x && x<button[ID_BTN_PAGE_SEL].x+button[ID_BTN_PAGE_SEL].width)
        {
            motion=ID_BTN_PAGE_SEL;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }
    panelPage->Refresh();
}

void mtg_tFrame::OnLeavePage(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    panelPage->Refresh();
}

void mtg_tFrame::OnClickPage(wxMouseEvent& event)
{
    if(motion==ID_BTN_PAGE_DES)
    {
        page=ID_BTN_PAGE_DES;
        panelDes->Show(true);
        panelSel->Show(false);
        //panelSeged->Show(true);
        //panelSeg->Show(false);
        //panelSeging->Show(false);
        //segbuttons->Show(false);
    }
    else if(motion==ID_BTN_PAGE_CAL)
    {
        page=ID_BTN_PAGE_CAL;
        panelDes->Show(false);
        panelSel->Show(true);
        //panelSeged->Show(false);
        //panelSeg->Show(true);
        //panelSeging->Show(false);
        //segbuttons->Show(true);
    }
    else if(motion==ID_BTN_PAGE_SEL)
    {
        page=ID_BTN_PAGE_SEL;
        panelDes->Show(false);
        panelSel->Show(false);
        //panelSeged->Show(false);
        //panelSeg->Show(false);
        //panelSeging->Show(true);
        //segbuttons->Show(false);
    }
    panelPage->Refresh();
}

void mtg_tFrame::OnPaintDes(wxPaintEvent& event)
{
    wxPaintDC dc(panelDes);
    int w,h;
    panelDes->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,-1,w,h+1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnPaintDesButton(wxPaintEvent& event)
{
    wxPaintDC dc(desButton);
    int w,h;
    desButton->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetBrush(wxBrush(wxColor(240,240,240)));
        memDC.SetPen(wxPen(wxColor(240,240,240)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;

        x1=1;
        y1=1;
        w1=w-1;
        h1=25;
        button[ID_BTN_DES_SEL].x=x1;
        button[ID_BTN_DES_SEL].y=y1;
        button[ID_BTN_DES_SEL].width=w1;
        button[ID_BTN_DES_SEL].height=h1;

        if(desPage==ID_BTN_DES_SEL)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_BTN_DES_SEL)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(button[ID_BTN_DES_SEL]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        memDC.DrawLabel(_("设计排版"),wxRect(button[ID_BTN_DES_SEL]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+1;
        button[ID_BTN_DES_LIST].x=x1;
        button[ID_BTN_DES_LIST].y=y1;
        button[ID_BTN_DES_LIST].width=w1;
        button[ID_BTN_DES_LIST].height=h1;

        if(desPage==ID_BTN_DES_LIST)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_BTN_DES_LIST)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(button[ID_BTN_DES_LIST]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        memDC.DrawLabel(_("设计排版"),wxRect(button[ID_BTN_DES_LIST]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+1;
        button[ID_BTN_DES_DETAILS].x=x1;
        button[ID_BTN_DES_DETAILS].y=y1;
        button[ID_BTN_DES_DETAILS].width=w1;
        button[ID_BTN_DES_DETAILS].height=h1;

        if(desPage==ID_BTN_DES_DETAILS)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_BTN_DES_DETAILS)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(button[ID_BTN_DES_DETAILS]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        memDC.DrawLabel(_("管环比例"),wxRect(button[ID_BTN_DES_DETAILS]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLine(x1+w1-1,0,x1+w1-1,h);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionDesButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>button[ID_BTN_DES_SEL].x && x<button[ID_BTN_DES_SEL].x+button[ID_BTN_DES_SEL].width)
    {
        if(y>button[ID_BTN_DES_SEL].y && y<button[ID_BTN_DES_SEL].y+button[ID_BTN_DES_SEL].height)
        {
            motion=ID_BTN_DES_SEL;
        }
        else if(y>button[ID_BTN_DES_LIST].y && y<button[ID_BTN_DES_LIST].y+button[ID_BTN_DES_LIST].height)
        {
            motion=ID_BTN_DES_LIST;
        }
        else if(y>button[ID_BTN_DES_DETAILS].y && y<button[ID_BTN_DES_DETAILS].y+button[ID_BTN_DES_DETAILS].height)
        {
            motion=ID_BTN_DES_DETAILS;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }

    desButton->Refresh();
}

void mtg_tFrame::OnLeaveDesButton(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    desButton->Refresh();
}

void mtg_tFrame::OnClickDesButton(wxMouseEvent& event)
{
    if(motion==ID_BTN_DES_SEL)
    {
        desPage=ID_BTN_DES_SEL;
        desSelPage->Show(true);
        designList->Show(false);
        //desOneText->Show(true);
        //dtaText->Show(false);
        //desListText->Show(false);
        //segText->Show(false);
        //selectionText->Show(false);
    }
    else if(motion==ID_BTN_DES_LIST)
    {
        desPage=ID_BTN_DES_LIST;
        desSelPage->Show(false);
        designList->Show(true);
        //desOneText->Show(false);
        //dtaText->Show(true);
        //desListText->Show(false);
        //segText->Show(false);
        //selectionText->Show(false);
    }
    else if(motion==ID_BTN_DES_DETAILS)
    {
        desPage=ID_BTN_DES_DETAILS;
        desSelPage->Show(false);
        designList->Show(false);
        //mtg_init_position(mtg);
        //desOneText->Show(false);
        //dtaText->Show(false);
        //desListText->Show(true);
        //segText->Show(true);
        //selectionText->Show(false);
    }

    desButton->Refresh();
}

void mtg_tFrame::OnPaintDesKi(wxPaintEvent& event)
{
    wxPaintDC dc(desKi);
    int w,h;
    desKi->GetSize(&w,&h);
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
        x1=0;
        y1=0;
        w1=w;
        h1=h;
        int x2,y2,x3,y3,x4,y4,x5,y5;
        //x1=0;
        //y1=y1+h1+5;
        //w1=w;
        //h1=w1;

        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        double radius=(w1-30)/2.0;
        x1=x1+w1/2;
        y1=y1+h1/2;
        if(msr->nblk>0)
        {
            int k=msr->segt.Ks;
            int k1=msr->iseg.k;
            double a0=2.0*PI/k;
            double pz;
            double deta=msr->blocks[0].angle/2.0;
            for(int i=0;i<k;i++)
            {
                if(i*a0>PI/2)
                {
                    pz=i*a0-PI/2;
                    break;
                }
            }
            double a1=PI*3.0/2.0-deta+pz;
            double a2=a1+a0*k1;
            a1=a1+a0*k1;
            for(int i=0;i<msr->nblk;i++)
            {
                x2=x1+radius*cos(a1+0.02);
                y2=y1+radius*sin(a1+0.02);
                x4=x1+(radius-40)*cos(a1+0.02);
                y4=y1+(radius-40)*sin(a1+0.02);
                a1+=msr->blocks[i].angle;
                x3=x1+radius*cos(a1-0.02);
                y3=y1+radius*sin(a1-0.02);
                x5=x1+(radius-40)*cos(a1-0.02);
                y5=y1+(radius-40)*sin(a1-0.02);
                if(i==0) memDC.SetPen(wxPen(wxColor(255,30,30)));
                else memDC.SetPen(wxPen(wxColor(132,128,113)));
                memDC.DrawArc(x3,y3,x2,y2,x1,y1);
                memDC.DrawArc(x5,y5,x4,y4,x1,y1);
            }

            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
            memDC.DrawCircle(x1,y1,radius-42);
            memDC.SetPen(wxPen(wxColor(60,66,87)));
            memDC.DrawLine(x1-radius-5,y1,x1+radius+5,y1);
            memDC.DrawLine(x1,y1-radius-5,x1,y1+radius+5);

            a1=PI*3.0/2.0-deta+pz;
            a1=a1+a0*k1;
            memDC.SetPen(wxPen(wxColor(60,66,87),1,wxDOT_DASH));
            for(int i=0;i<msr->nblk;i++)
            {
                a1+=msr->blocks[i].angle;
                x5=x1+(radius-40)*cos(a1-0.02);
                y5=y1+(radius-40)*sin(a1-0.02);
                memDC.DrawLine(x5,y5,x1,y1);
            }

            a1=PI*3.0/2.0+pz;
            for(int i=0;i<k;i++)
            {
                x2=x1+(radius-20)*cos(a1+a0*i);
                y2=y1+(radius-20)*sin(a1+a0*i);
                button[ID_BTN_COUNT+i].x=x2;
                button[ID_BTN_COUNT+i].y=y2;
                button[ID_BTN_COUNT+i].width=20;
                button[ID_BTN_COUNT+i].height=20;
                memDC.SetPen(wxPen(wxColor(105,105,105)));
                memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                if(motion==ID_BTN_COUNT+i && i!=0) memDC.DrawCircle(x2,y2,20);
                memDC.DrawCircle(x2,y2,15);

                if(i==k1)
                {
                    if(msr->iseg.ipos[i]==0)
                    {
                        memDC.SetPen(wxPen(wxColor(47,139,205)));
                        memDC.SetBrush(wxBrush(wxColor(47,139,205)));
                        //memDC.SetPen(wxPen(wxColor(105,105,105)));
                        //memDC.SetBrush(wxBrush(wxColor(105,105,105)));
                    }
                    else if(msr->iseg.ipos[i]==1)
                    {
                        memDC.SetPen(*wxRED_PEN);
                        memDC.SetBrush(*wxRED_BRUSH);
                    }
                }
                else if(msr->iseg.ipos[i]==0)
                {
                    memDC.SetPen(wxPen(wxColor(105,105,105)));
                    memDC.SetBrush(wxBrush(wxColor(105,105,105)));
                }
                else if(msr->iseg.ipos[i]==1)
                {
                    //memDC.SetPen(wxPen(wxColor(47,139,205)));
                    //memDC.SetBrush(wxBrush(wxColor(47,139,205)));
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                }
                else if(msr->iseg.ipos[i]==2)
                {
                    memDC.SetPen(*wxRED_PEN);
                    memDC.SetBrush(*wxRED_BRUSH);
                }
                memDC.DrawCircle(x2,y2,5);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionDesKi(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int n=msr->segt.Ks;
    double r;
    for(int i=0;i<n+3;i++)
    {
        r=(x-button[ID_BTN_COUNT+i].x)*(x-button[ID_BTN_COUNT+i].x)+(y-button[ID_BTN_COUNT+i].y)*(y-button[ID_BTN_COUNT+i].y);
        r=sqrt(r);
        if(r<button[ID_BTN_COUNT+i].width)
        {
            motion=ID_BTN_COUNT+i;
            break;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    desKi->Refresh();
}

void mtg_tFrame::OnLeaveDesKi(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    desKi->Refresh();
}

void mtg_tFrame::OnClickDesKi(wxMouseEvent& event)
{
    int k=msr->segt.Ks;
    int i;
    for(i=0;i<k;i++)
    {
        if(motion==ID_BTN_COUNT+i)
        {
            if(msr->iseg.k!=i)
            {
                msr->iseg.k=i;
            }
            break;
        }
    }
    desKi->Refresh();
    //panelOption->Refresh();
}

void mtg_tFrame::OnPaintDesTxt(wxPaintEvent& event)
{
    wxPaintDC dc(desTxt);
    int w,h;
    desTxt->GetSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawRoundedRectangle(0,8,w,h-8,3);

        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(9,8,65,16);
        memDC.DrawLabel(_("起始管环"),wxRect(15,8,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        int x1,y1,w1,h1;
        x1=0;
        y1=25;
        w1=80;
        h1=23;
        memDC.DrawLabel(_("管环编号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        des_id_text->SetSize(x1+80,y1,w1+40,h1);
        y1+=30;
        memDC.DrawLabel(_("管环里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        des_mile_text->SetSize(x1+80,y1,w1+40,h1);

        x1=x1+w1+135;
        w1=65;
        button[ID_BTN_DES_SET].x=x1;
        button[ID_BTN_DES_SET].y=y1;
        button[ID_BTN_DES_SET].width=w1;
        button[ID_BTN_DES_SET].height=y1;
        if(motion==ID_BTN_DES_SET)
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
        memDC.DrawLabel(_("设置"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionDesTxt(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_DES_SET].y && y<button[ID_BTN_DES_SET].y+button[ID_BTN_DES_SET].height)
    {
        if(x>button[ID_BTN_DES_SET].x && x<button[ID_BTN_DES_SET].x+button[ID_BTN_DES_SET].width)
        {
            motion=ID_BTN_DES_SET;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }
    desTxt->Refresh();
}

void mtg_tFrame::OnLeaveDesTxt(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    desTxt->Refresh();
}

void mtg_tFrame::OnClickDesTxt(wxMouseEvent& event)
{
    if(motion==ID_BTN_DES_SET)
    {
        wxMessageBox(wxString::Format(_("%d"),msr->ndes));
        long ival;
        //int sel=desListView->GetFirstSelected();
        int sel=0;
        int num=desListView->GetItemCount();
        //if(sel<0 || sel>num) return;
        des_id_text->GetValue().ToLong(&ival);
        msr->des[sel].numb=ival;
        //wxMessageBox(wxString::Format(_("%d"),msr->iseg.numb));
        des_mile_text->GetValue().ToDouble(&msr->des[sel].mile);

        msr_cal_design(msr,sel);
        UpdateDesign();
    }
    desTxt->Refresh();
}

void mtg_tFrame::OnPaintDesSelTi(wxPaintEvent& event)
{
    wxPaintDC dc(desSelTi);
    int w,h;
    desSelTi->GetSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.DrawRoundedRectangle(0,8,w,h-8,3);

        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(9,8,65,16);
        memDC.DrawLabel(_("起始管环"),wxRect(15,8,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        int x1,y1,w1,h1;
        x1=0;
        y1=25;
        w1=80;
        h1=23;
        memDC.DrawLabel(_("垂直方向"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=80;
        button[ID_BTN_DES_VCAL].x=x1;
        button[ID_BTN_DES_VCAL].y=y1;
        button[ID_BTN_DES_VCAL].width=w1;
        button[ID_BTN_DES_VCAL].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(msr->dseg.vcal==0)
        {
            if(motion==ID_BTN_DES_VCAL)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1+2,y1,checkBoxWidth,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1+2,y1,checkBoxWidth,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion==ID_BTN_DES_VCAL)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1=0;
        y1+=30;
        memDC.DrawLabel(_("管环类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;

        if(msr->segt.type==1)
        {
            button[ID_BTN_TYPE_STD].x=x1;
            button[ID_BTN_TYPE_STD].y=y1;
            button[ID_BTN_TYPE_STD].width=w1;
            button[ID_BTN_TYPE_STD].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->dseg.type==1)
            {
                if(motion==ID_BTN_TYPE_STD)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_STD)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

            x1+=w1;
            button[ID_BTN_TYPE_TL].x=x1;
            button[ID_BTN_TYPE_TL].y=y1;
            button[ID_BTN_TYPE_TL].width=w1;
            button[ID_BTN_TYPE_TL].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->dseg.type==2)
            {
                if(motion==ID_BTN_TYPE_TL)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_TL)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

            x1+=w1;
            button[ID_BTN_TYPE_TR].x=x1;
            button[ID_BTN_TYPE_TR].y=y1;
            button[ID_BTN_TYPE_TR].width=w1;
            button[ID_BTN_TYPE_TR].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->dseg.type==3)
            {
                if(motion==ID_BTN_TYPE_TR)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_TR)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionDesSelTi(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_DES_VCAL].y && y<button[ID_BTN_DES_VCAL].y+button[ID_BTN_DES_VCAL].height)
    {
        if(x>button[ID_BTN_DES_VCAL].x && x<button[ID_BTN_DES_VCAL].x+button[ID_BTN_DES_VCAL].width)
        {
            motion=ID_BTN_DES_VCAL;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else if(y>button[ID_BTN_TYPE_TL].y && y<button[ID_BTN_TYPE_TL].y+button[ID_BTN_TYPE_TL].height)
    {
        if(x>button[ID_BTN_TYPE_TL].x && x<button[ID_BTN_TYPE_TL].x+button[ID_BTN_TYPE_TL].width)
        {
            motion=ID_BTN_TYPE_TL;
        }
        else if(x>button[ID_BTN_TYPE_TR].x && x<button[ID_BTN_TYPE_TR].x+button[ID_BTN_TYPE_TR].width)
        {
            motion=ID_BTN_TYPE_TR;
        }
        else if(x>button[ID_BTN_TYPE_STD].x && x<button[ID_BTN_TYPE_STD].x+button[ID_BTN_TYPE_STD].width)
        {
            motion=ID_BTN_TYPE_STD;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }
    desSelTi->Refresh();
}

void mtg_tFrame::OnLeaveDesSelTi(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    desSelTi->Refresh();
}

void mtg_tFrame::OnClickDesSelTi(wxMouseEvent& event)
{
    if(motion==ID_BTN_TYPE_STD)
    {
        msr->dseg.type=1;
    }
    else if(motion==ID_BTN_TYPE_TL)
    {
        msr->dseg.type=2;
    }
    else if(motion==ID_BTN_TYPE_TR)
    {
        msr->dseg.type=3;
    }
    else if(motion==ID_BTN_DES_VCAL)
    {
        if(msr->dseg.vcal==0) msr->dseg.vcal=1;
        else msr->dseg.vcal=0;
    }
    desSelTi->Refresh();
}

void mtg_tFrame::OnPaintDesignCal(wxPaintEvent& event)
{
    wxPaintDC dc(designCal);
    int w,h;
    designCal->GetSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        if(motion==ID_BTN_DES_SET)
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

        memDC.DrawRoundedRectangle(15,0,65,h,3);
        memDC.DrawLabel(_("计算"),wxRect(15,0,65,h),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionDesignCal(wxMouseEvent& event)
{
    motion=ID_BTN_DES_SET;
    designCal->Refresh();
}

void mtg_tFrame::OnLeaveDesignCal(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    designCal->Refresh();
}

void mtg_tFrame::OnClickDesignCal(wxMouseEvent& event)
{
    if(motion==ID_BTN_DES_SET)
    {
        long ival;
        des_id_text->GetValue().ToLong(&ival);
        msr->iseg.numb=ival;
        //wxMessageBox(wxString::Format(_("%d"),msr->iseg.numb));
        des_mile_text->GetValue().ToDouble(&msr->iseg.mile);

        int sel=desListView->GetFirstSelected();
        msr_cal_design(msr,sel);
        UpdateDesign();
    }
    designCal->Refresh();
}

void mtg_tFrame::OnPaintSel(wxPaintEvent& event)
{
    wxPaintDC dc(panelSel);
    int w,h;
    panelSel->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,-1,w,h+1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnPaintSelButton(wxPaintEvent& event)
{
    wxPaintDC dc(selButton);
    int w,h;
    selButton->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetBrush(wxBrush(wxColor(240,240,240)));
        memDC.SetPen(wxPen(wxColor(240,240,240)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        int x1,y1,w1,h1;

        x1=1;
        y1=1;
        w1=w-1;
        h1=25;
        button[ID_BTN_SEL_LAST].x=x1;
        button[ID_BTN_SEL_LAST].y=y1;
        button[ID_BTN_SEL_LAST].width=w1;
        button[ID_BTN_SEL_LAST].height=h1;

        if(selPage==ID_BTN_SEL_LAST)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_BTN_SEL_LAST)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(button[ID_BTN_SEL_LAST]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        memDC.DrawLabel(_("上一管环"),wxRect(button[ID_BTN_SEL_LAST]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+1;
        button[ID_BTN_SEL_SEL].x=x1;
        button[ID_BTN_SEL_SEL].y=y1;
        button[ID_BTN_SEL_SEL].width=w1;
        button[ID_BTN_SEL_SEL].height=h1;

        if(selPage==ID_BTN_SEL_SEL)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_BTN_SEL_SEL)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(button[ID_BTN_SEL_SEL]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        memDC.DrawLabel(_("管环选型"),wxRect(button[ID_BTN_SEL_SEL]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+1;
        button[ID_BTN_SEL_LINE].x=x1;
        button[ID_BTN_SEL_LINE].y=y1;
        button[ID_BTN_SEL_LINE].width=w1;
        button[ID_BTN_SEL_LINE].height=h1;

        if(selPage==ID_BTN_SEL_LINE)
        {
            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        }
        else
        {
            if(motion==ID_BTN_SEL_LINE)
            {
                memDC.SetPen(wxPen(wxColor(200,225,250)));
                memDC.SetBrush(wxBrush(wxColor(200,225,250)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(237,240,245)));
                memDC.SetBrush(wxBrush(wxColor(237,240,245)));
            }
        }
        memDC.DrawRectangle(button[ID_BTN_SEL_LINE]);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1+h1,x1+w1,y1+h1);
        memDC.DrawLabel(_("纠偏曲线"),wxRect(button[ID_BTN_SEL_LINE]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        memDC.DrawLine(x1+w1-1,0,x1+w1-1,h);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionSelButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>button[ID_BTN_SEL_LAST].x && x<button[ID_BTN_SEL_LAST].x+button[ID_BTN_SEL_LAST].width)
    {
        if(y>button[ID_BTN_SEL_LAST].y && y<button[ID_BTN_SEL_LAST].y+button[ID_BTN_SEL_LAST].height)
        {
            motion=ID_BTN_SEL_LAST;
        }
        else if(y>button[ID_BTN_SEL_SEL].y && y<button[ID_BTN_SEL_SEL].y+button[ID_BTN_SEL_SEL].height)
        {
            motion=ID_BTN_SEL_SEL;
        }
        else if(y>button[ID_BTN_SEL_LINE].y && y<button[ID_BTN_SEL_LINE].y+button[ID_BTN_SEL_LINE].height)
        {
            motion=ID_BTN_SEL_LINE;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }

    selButton->Refresh();
}

void mtg_tFrame::OnLeaveSelButton(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    selButton->Refresh();
}

void mtg_tFrame::OnClickSelButton(wxMouseEvent& event)
{
    if(motion==ID_BTN_SEL_LAST)
    {
        selPage=ID_BTN_SEL_LAST;
        selLastPage->Show(true);
        segPage->Show(false);
        //desOneText->Show(true);
        //dtaText->Show(false);
        //desListText->Show(false);
        //segText->Show(false);
        //selectionText->Show(false);
    }
    else if(motion==ID_BTN_SEL_SEL)
    {
        selPage=ID_BTN_SEL_SEL;
        selLastPage->Show(false);
        segPage->Show(true);
        //designList->Show(true);
        //desOneText->Show(false);
        //dtaText->Show(true);
        //desListText->Show(false);
        //segText->Show(false);
        //selectionText->Show(false);
    }
    else if(motion==ID_BTN_SEL_SEL)
    {
        //desPage=ID_BTN_DES_DETAILS;
        //desSelPage->Show(false);
        //designList->Show(false);
        //mtg_init_position(mtg);
        //desOneText->Show(false);
        //dtaText->Show(false);
        //desListText->Show(true);
        //segText->Show(true);
        //selectionText->Show(false);
    }

    selButton->Refresh();
}

void mtg_tFrame::OnPaintLastKi(wxPaintEvent& event)
{
    wxPaintDC dc(selLastKi);
    int w,h;
    selLastKi->GetSize(&w,&h);
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
        x1=0;
        y1=0;
        w1=w;
        h1=h;
        int x2,y2,x3,y3,x4,y4,x5,y5;
        //x1=0;
        //y1=y1+h1+5;
        //w1=w;
        //h1=w1;

        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        double radius=(w1-30)/2.0;
        x1=x1+w1/2;
        y1=y1+h1/2;
        if(msr->nblk>0)
        {
            int k=msr->segt.Ks;
            int k1=msr->iseg.k;
            double a0=2.0*PI/k;
            double pz;
            double deta=msr->blocks[0].angle/2.0;
            for(int i=0;i<k;i++)
            {
                if(i*a0>PI/2)
                {
                    pz=i*a0-PI/2;
                    break;
                }
            }
            double a1=PI*3.0/2.0-deta+pz;
            double a2=a1+a0*k1;
            a1=a1+a0*k1;
            for(int i=0;i<msr->nblk;i++)
            {
                x2=x1+radius*cos(a1+0.02);
                y2=y1+radius*sin(a1+0.02);
                x4=x1+(radius-40)*cos(a1+0.02);
                y4=y1+(radius-40)*sin(a1+0.02);
                a1+=msr->blocks[i].angle;
                x3=x1+radius*cos(a1-0.02);
                y3=y1+radius*sin(a1-0.02);
                x5=x1+(radius-40)*cos(a1-0.02);
                y5=y1+(radius-40)*sin(a1-0.02);
                if(i==0) memDC.SetPen(wxPen(wxColor(255,30,30)));
                else memDC.SetPen(wxPen(wxColor(132,128,113)));
                memDC.DrawArc(x3,y3,x2,y2,x1,y1);
                memDC.DrawArc(x5,y5,x4,y4,x1,y1);
            }

            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
            memDC.DrawCircle(x1,y1,radius-42);
            memDC.SetPen(wxPen(wxColor(60,66,87)));
            memDC.DrawLine(x1-radius-5,y1,x1+radius+5,y1);
            memDC.DrawLine(x1,y1-radius-5,x1,y1+radius+5);

            a1=PI*3.0/2.0-deta+pz;
            a1=a1+a0*k1;
            memDC.SetPen(wxPen(wxColor(60,66,87),1,wxDOT_DASH));
            for(int i=0;i<msr->nblk;i++)
            {
                a1+=msr->blocks[i].angle;
                x5=x1+(radius-40)*cos(a1-0.02);
                y5=y1+(radius-40)*sin(a1-0.02);
                memDC.DrawLine(x5,y5,x1,y1);
            }

            a1=PI*3.0/2.0+pz;
            for(int i=0;i<k;i++)
            {
                x2=x1+(radius-20)*cos(a1+a0*i);
                y2=y1+(radius-20)*sin(a1+a0*i);
                button[ID_BTN_COUNT+i].x=x2;
                button[ID_BTN_COUNT+i].y=y2;
                button[ID_BTN_COUNT+i].width=20;
                button[ID_BTN_COUNT+i].height=20;
                memDC.SetPen(wxPen(wxColor(105,105,105)));
                memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                if(motion==ID_BTN_COUNT+i && i!=0) memDC.DrawCircle(x2,y2,20);
                memDC.DrawCircle(x2,y2,15);

                if(i==k1)
                {
                    if(msr->iseg.ipos[i]==0)
                    {
                        memDC.SetPen(wxPen(wxColor(47,139,205)));
                        memDC.SetBrush(wxBrush(wxColor(47,139,205)));
                        //memDC.SetPen(wxPen(wxColor(105,105,105)));
                        //memDC.SetBrush(wxBrush(wxColor(105,105,105)));
                    }
                    else if(msr->iseg.ipos[i]==1)
                    {
                        memDC.SetPen(*wxRED_PEN);
                        memDC.SetBrush(*wxRED_BRUSH);
                    }
                }
                else if(msr->iseg.ipos[i]==0)
                {
                    memDC.SetPen(wxPen(wxColor(105,105,105)));
                    memDC.SetBrush(wxBrush(wxColor(105,105,105)));
                }
                else if(msr->iseg.ipos[i]==1)
                {
                    //memDC.SetPen(wxPen(wxColor(47,139,205)));
                    //memDC.SetBrush(wxBrush(wxColor(47,139,205)));
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                }
                else if(msr->iseg.ipos[i]==2)
                {
                    memDC.SetPen(*wxRED_PEN);
                    memDC.SetBrush(*wxRED_BRUSH);
                }
                memDC.DrawCircle(x2,y2,5);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionLastKi(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int n=msr->segt.Ks;
    double r;
    for(int i=0;i<n+3;i++)
    {
        r=(x-button[ID_BTN_COUNT+i].x)*(x-button[ID_BTN_COUNT+i].x)+(y-button[ID_BTN_COUNT+i].y)*(y-button[ID_BTN_COUNT+i].y);
        r=sqrt(r);
        if(r<button[ID_BTN_COUNT+i].width)
        {
            motion=ID_BTN_COUNT+i;
            break;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    selLastKi->Refresh();
}

void mtg_tFrame::OnLeaveLastKi(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    selLastKi->Refresh();
}

void mtg_tFrame::OnClickLastKi(wxMouseEvent& event)
{
    int k=msr->segt.Ks;
    int i;
    for(i=0;i<k;i++)
    {
        if(motion==ID_BTN_COUNT+i)
        {
            if(msr->iseg.k!=i)
            {
                msr->iseg.k=i;
            }
            break;
        }
    }
    selLastKi->Refresh();
    //panelOption->Refresh();
}

void mtg_tFrame::OnPaintLastPi(wxPaintEvent& event)
{
    wxPaintDC dc(selLastPi);
    int w,h;
    selLastPi->GetSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=15;
        w1=80;
        h1=23;
        memDC.DrawLabel(_("管环编号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        sel_last_idtxt->SetSize(x1+80,y1,w1+40,h1);
        //y1+=30;
        //memDC.DrawLabel(_("管环里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //sel_last_idtxt->SetSize(x1+80,y1,w1+40,h1);

        y1+=30;
        memDC.DrawLabel(_("垂直方向"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=80;
        button[ID_BTN_SEL_MODE].x=x1;
        button[ID_BTN_SEL_MODE].y=y1;
        button[ID_BTN_SEL_MODE].width=w1;
        button[ID_BTN_SEL_MODE].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(msr->mode==0)
        {
            if(motion==ID_BTN_SEL_MODE)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1+2,y1,checkBoxWidth,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1+2,y1,checkBoxWidth,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion==ID_BTN_SEL_MODE)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionLastPi(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_SEL_MODE].y && y<button[ID_BTN_SEL_MODE].y+button[ID_BTN_SEL_MODE].height)
    {
        if(x>button[ID_BTN_SEL_MODE].x && x<button[ID_BTN_SEL_MODE].x+button[ID_BTN_SEL_MODE].width)
        {
            motion=ID_BTN_SEL_MODE;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }
    selLastPi->Refresh();
}

void mtg_tFrame::OnLeaveLastPi(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    selLastPi->Refresh();
}

void mtg_tFrame::OnClickLastPi(wxMouseEvent& event)
{
    if(motion==ID_BTN_SEL_MODE)
    {
        if(msr->mode==0) msr->mode=1;
        else msr->mode=0;
    }
    selLastPi->Refresh();
}

void mtg_tFrame::OnPaintLastTi(wxPaintEvent& event)
{
    wxPaintDC dc(selLastTi);
    int w,h;
    selLastTi->GetSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=80;
        h1=23;
        memDC.DrawLabel(_("管环类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        if(msr->segt.type==1)
        {
            button[ID_BTN_TYPE_STD].x=x1;
            button[ID_BTN_TYPE_STD].y=y1;
            button[ID_BTN_TYPE_STD].width=w1;
            button[ID_BTN_TYPE_STD].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->iseg.type==1)
            {
                if(motion==ID_BTN_TYPE_STD)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_STD)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

            x1+=w1;
            button[ID_BTN_TYPE_TL].x=x1;
            button[ID_BTN_TYPE_TL].y=y1;
            button[ID_BTN_TYPE_TL].width=w1;
            button[ID_BTN_TYPE_TL].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->iseg.type==2)
            {
                if(motion==ID_BTN_TYPE_TL)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_TL)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

            x1+=w1;
            button[ID_BTN_TYPE_TR].x=x1;
            button[ID_BTN_TYPE_TR].y=y1;
            button[ID_BTN_TYPE_TR].width=w1;
            button[ID_BTN_TYPE_TR].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->iseg.type==3)
            {
                if(motion==ID_BTN_TYPE_TR)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_TR)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionLastTi(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_TYPE_TL].y && y<button[ID_BTN_TYPE_TL].y+button[ID_BTN_TYPE_TL].height)
    {
        if(x>button[ID_BTN_TYPE_TL].x && x<button[ID_BTN_TYPE_TL].x+button[ID_BTN_TYPE_TL].width)
        {
            motion=ID_BTN_TYPE_TL;
        }
        else if(x>button[ID_BTN_TYPE_TR].x && x<button[ID_BTN_TYPE_TR].x+button[ID_BTN_TYPE_TR].width)
        {
            motion=ID_BTN_TYPE_TR;
        }
        else if(x>button[ID_BTN_TYPE_STD].x && x<button[ID_BTN_TYPE_STD].x+button[ID_BTN_TYPE_STD].width)
        {
            motion=ID_BTN_TYPE_STD;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }
    selLastTi->Refresh();
}

void mtg_tFrame::OnLeaveLastTi(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    selLastTi->Refresh();
}

void mtg_tFrame::OnClickLastTi(wxMouseEvent& event)
{
    if(motion==ID_BTN_TYPE_STD) msr->iseg.type=1;
    else if(motion==ID_BTN_TYPE_TL) msr->iseg.type=2;
    else if(motion==ID_BTN_TYPE_TR) msr->iseg.type=3;
    selLastTi->Refresh();
}

void mtg_tFrame::OnPaintSegTxt(wxPaintEvent& event)
{
    wxPaintDC dc(segTxt);
    int w,h;
    segTxt->GetSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=11;
        w1=80;
        h1=23;
        memDC.DrawLabel(_("管环编号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        seg_id_text->SetSize(x1+80,y1,w1+40,h1);
        //y1+=30;
        //memDC.DrawLabel(_("管环里程"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        //des_mile_text->SetSize(x1+80,y1,w1+40,h1);

        y1+=30;
        memDC.DrawLabel(_("垂直方向"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=80;
        button[ID_BTN_DES_VCAL].x=x1;
        button[ID_BTN_DES_VCAL].y=y1;
        button[ID_BTN_DES_VCAL].width=w1;
        button[ID_BTN_DES_VCAL].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        if(msr->dmode==0)
        {
            if(motion==ID_BTN_DES_VCAL)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[1]);
                memDC.DrawLabel(_("√"),wxRect(x1+2,y1,checkBoxWidth,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[2]);
                memDC.SetBrush(ibrush[2]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[2]);
                memDC.DrawLabel(_("√"),wxRect(x1+2,y1,checkBoxWidth,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        else
        {
            if(motion==ID_BTN_DES_VCAL)
            {
                memDC.SetPen(ipen[1]);
                memDC.SetBrush(ibrush[1]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                memDC.SetPen(ipen[0]);
                memDC.SetBrush(ibrush[0]);
                memDC.DrawRectangle(x1,y1+h1/2-checkBoxHeight/2,checkBoxWidth,checkBoxHeight);
                memDC.SetTextForeground(icolor[0]);
                memDC.DrawLabel(_("忽略垂直方向"),wxRect(x1+checkBoxWidth+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }

        x1=0;
        y1+=30;
        memDC.DrawLabel(_("管环类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        segTi->Show(false);
        x1+=w1;
        if(msr->segt.type==1)
        {
            button[ID_BTN_TYPE_STD].x=x1;
            button[ID_BTN_TYPE_STD].y=y1;
            button[ID_BTN_TYPE_STD].width=w1;
            button[ID_BTN_TYPE_STD].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->iseg.type==1)
            {
                if(motion==ID_BTN_TYPE_STD)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_STD)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

            x1+=w1;
            button[ID_BTN_TYPE_TL].x=x1;
            button[ID_BTN_TYPE_TL].y=y1;
            button[ID_BTN_TYPE_TL].width=w1;
            button[ID_BTN_TYPE_TL].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->iseg.type==2)
            {
                if(motion==ID_BTN_TYPE_TL)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_TL)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

            x1+=w1;
            button[ID_BTN_TYPE_TR].x=x1;
            button[ID_BTN_TYPE_TR].y=y1;
            button[ID_BTN_TYPE_TR].width=w1;
            button[ID_BTN_TYPE_TR].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->iseg.type==3)
            {
                if(motion==ID_BTN_TYPE_TR)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_TR)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionSegTxt(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_DES_VCAL].y && y<button[ID_BTN_DES_VCAL].y+button[ID_BTN_DES_VCAL].height)
    {
        if(x>button[ID_BTN_DES_VCAL].x && x<button[ID_BTN_DES_VCAL].x+button[ID_BTN_DES_VCAL].width)
        {
            motion=ID_BTN_DES_VCAL;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }
    segTxt->Refresh();
}

void mtg_tFrame::OnLeaveSegTxt(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    segTxt->Refresh();
}

void mtg_tFrame::OnClickSegTxt(wxMouseEvent& event)
{
    if(motion==ID_BTN_DES_VCAL)
    {
        if(msr->dmode==0) msr->dmode=1;
        else msr->dmode=0;
    }
    segTxt->Refresh();
}

void mtg_tFrame::OnPaintSegTi(wxPaintEvent& event)
{
    wxPaintDC dc(segTi);
    int w,h;
    segTi->GetSize(&w,&h);
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
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=80;
        h1=23;
        memDC.DrawLabel(_("管环类型"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        x1+=w1;
        if(msr->segt.type==1)
        {
            button[ID_BTN_TYPE_STD].x=x1;
            button[ID_BTN_TYPE_STD].y=y1;
            button[ID_BTN_TYPE_STD].width=w1;
            button[ID_BTN_TYPE_STD].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->iseg.type==1)
            {
                if(motion==ID_BTN_TYPE_STD)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_STD)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("标准环"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

            x1+=w1;
            button[ID_BTN_TYPE_TL].x=x1;
            button[ID_BTN_TYPE_TL].y=y1;
            button[ID_BTN_TYPE_TL].width=w1;
            button[ID_BTN_TYPE_TL].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->iseg.type==2)
            {
                if(motion==ID_BTN_TYPE_TL)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_TL)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("左转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }

            x1+=w1;
            button[ID_BTN_TYPE_TR].x=x1;
            button[ID_BTN_TYPE_TR].y=y1;
            button[ID_BTN_TYPE_TR].width=w1;
            button[ID_BTN_TYPE_TR].height=h1;
            memDC.SetPen(wxPen(wxColor(158,158,158)));
            if(msr->iseg.type==3)
            {
                if(motion==ID_BTN_TYPE_TR)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[1].GetColour())));
                    memDC.SetBrush(ibrush[1]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                else
                {
                    memDC.SetPen(ipen[2]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                    memDC.SetPen(wxPen(wxColor(ibrush[2].GetColour())));
                    memDC.SetBrush(ibrush[2]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR2);
                }
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
            else
            {
                if(motion==ID_BTN_TYPE_TR)
                {
                    memDC.SetPen(ipen[1]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                else
                {
                    memDC.SetPen(ipen[0]);
                    memDC.SetBrush(ibrush[0]);
                    memDC.DrawCircle(x1+radioBoxR1,y1+h1/2+1,radioBoxR1);
                }
                memDC.DrawLabel(_("右转弯"),wxRect(x1+radioBoxR1*2+5,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
            }
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionSegTi(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BTN_TYPE_TL].y && y<button[ID_BTN_TYPE_TL].y+button[ID_BTN_TYPE_TL].height)
    {
        if(x>button[ID_BTN_TYPE_TL].x && x<button[ID_BTN_TYPE_TL].x+button[ID_BTN_TYPE_TL].width)
        {
            motion=ID_BTN_TYPE_TL;
        }
        else if(x>button[ID_BTN_TYPE_TR].x && x<button[ID_BTN_TYPE_TR].x+button[ID_BTN_TYPE_TR].width)
        {
            motion=ID_BTN_TYPE_TR;
        }
        else if(x>button[ID_BTN_TYPE_STD].x && x<button[ID_BTN_TYPE_STD].x+button[ID_BTN_TYPE_STD].width)
        {
            motion=ID_BTN_TYPE_STD;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    else
    {
        motion=ID_BTN_NONE;
    }
    segTi->Refresh();
}

void mtg_tFrame::OnLeaveSegTi(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    segTi->Refresh();
}

void mtg_tFrame::OnClickSegTi(wxMouseEvent& event)
{
    if(motion==ID_BTN_TYPE_STD) msr->iseg.type=1;
    else if(motion==ID_BTN_TYPE_TL) msr->iseg.type=2;
    else if(motion==ID_BTN_TYPE_TR) msr->iseg.type=3;
    segTi->Refresh();
}

void mtg_tFrame::OnPaintSegList(wxPaintEvent& event)
{
    wxPaintDC dc(segList);
    int w,h;
    segList->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=7;
        y1=7;
        w1=(w-30)/15;
        h1=h-14;
        memDC.SetPen(wxPen(wxColor(68,88,108)));
        for(int i=0;i<15;i++)
        {
            memDC.DrawRectangle(x1+w1*i+i,y1,w1,h1);
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionSegList(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int n=msr->segt.Ks;
    double r;
    for(int i=0;i<n+3;i++)
    {
        r=(x-button[ID_BTN_COUNT+i].x)*(x-button[ID_BTN_COUNT+i].x)+(y-button[ID_BTN_COUNT+i].y)*(y-button[ID_BTN_COUNT+i].y);
        r=sqrt(r);
        if(r<button[ID_BTN_COUNT+i].width)
        {
            motion=ID_BTN_COUNT+i;
            break;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    segList->Refresh();
}

void mtg_tFrame::OnLeaveSegList(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    segList->Refresh();
}

void mtg_tFrame::OnClickSegList(wxMouseEvent& event)
{
    int k=msr->segt.Ks;
    int i;
    for(i=0;i<k;i++)
    {
        if(motion==ID_BTN_COUNT+i)
        {
            if(msr->iseg.k!=i)
            {
                msr->iseg.k=i;
            }
            break;
        }
    }
    segList->Refresh();
    //panelOption->Refresh();
}

void mtg_tFrame::OnPaintKiFig(wxPaintEvent& event)
{
    wxPaintDC dc(segKi);
    int w,h;
    segKi->GetSize(&w,&h);
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
        x1=0;
        y1=0;
        w1=w;
        h1=h;
        int x2,y2,x3,y3,x4,y4,x5,y5;
        //x1=0;
        //y1=y1+h1+5;
        //w1=w;
        //h1=w1;

        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        double radius=(w1-30)/2.0;
        x1=x1+w1/2;
        y1=y1+h1/2;
        if(msr->nblk>0)
        {
            int k=msr->segt.Ks;
            int k1=msr->iseg.k;
            double a0=2.0*PI/k;
            double pz;
            double deta=msr->blocks[0].angle/2.0;
            for(int i=0;i<k;i++)
            {
                if(i*a0>PI/2)
                {
                    pz=i*a0-PI/2;
                    break;
                }
            }
            double a1=PI*3.0/2.0-deta+pz;
            double a2=a1+a0*k1;
            a1=a1+a0*k1;
            for(int i=0;i<msr->nblk;i++)
            {
                x2=x1+radius*cos(a1+0.02);
                y2=y1+radius*sin(a1+0.02);
                x4=x1+(radius-40)*cos(a1+0.02);
                y4=y1+(radius-40)*sin(a1+0.02);
                a1+=msr->blocks[i].angle;
                x3=x1+radius*cos(a1-0.02);
                y3=y1+radius*sin(a1-0.02);
                x5=x1+(radius-40)*cos(a1-0.02);
                y5=y1+(radius-40)*sin(a1-0.02);
                if(i==0) memDC.SetPen(wxPen(wxColor(255,30,30)));
                else memDC.SetPen(wxPen(wxColor(132,128,113)));
                memDC.DrawArc(x3,y3,x2,y2,x1,y1);
                memDC.DrawArc(x5,y5,x4,y4,x1,y1);
            }

            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
            memDC.DrawCircle(x1,y1,radius-42);
            memDC.SetPen(wxPen(wxColor(60,66,87)));
            memDC.DrawLine(x1-radius-5,y1,x1+radius+5,y1);
            memDC.DrawLine(x1,y1-radius-5,x1,y1+radius+5);

            a1=PI*3.0/2.0-deta+pz;
            a1=a1+a0*k1;
            memDC.SetPen(wxPen(wxColor(60,66,87),1,wxDOT_DASH));
            for(int i=0;i<msr->nblk;i++)
            {
                a1+=msr->blocks[i].angle;
                x5=x1+(radius-40)*cos(a1-0.02);
                y5=y1+(radius-40)*sin(a1-0.02);
                memDC.DrawLine(x5,y5,x1,y1);
            }

            a1=PI*3.0/2.0+pz;
            for(int i=0;i<k;i++)
            {
                x2=x1+(radius-20)*cos(a1+a0*i);
                y2=y1+(radius-20)*sin(a1+a0*i);
                button[ID_BTN_COUNT+i].x=x2;
                button[ID_BTN_COUNT+i].y=y2;
                button[ID_BTN_COUNT+i].width=20;
                button[ID_BTN_COUNT+i].height=20;
                memDC.SetPen(wxPen(wxColor(105,105,105)));
                memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                if(motion==ID_BTN_COUNT+i && i!=0) memDC.DrawCircle(x2,y2,20);
                memDC.DrawCircle(x2,y2,15);

                if(i==k1)
                {
                    if(msr->iseg.ipos[i]==0)
                    {
                        memDC.SetPen(wxPen(wxColor(47,139,205)));
                        memDC.SetBrush(wxBrush(wxColor(47,139,205)));
                        //memDC.SetPen(wxPen(wxColor(105,105,105)));
                        //memDC.SetBrush(wxBrush(wxColor(105,105,105)));
                    }
                    else if(msr->iseg.ipos[i]==1)
                    {
                        memDC.SetPen(*wxRED_PEN);
                        memDC.SetBrush(*wxRED_BRUSH);
                    }
                }
                else if(msr->iseg.ipos[i]==0)
                {
                    memDC.SetPen(wxPen(wxColor(105,105,105)));
                    memDC.SetBrush(wxBrush(wxColor(105,105,105)));
                }
                else if(msr->iseg.ipos[i]==1)
                {
                    //memDC.SetPen(wxPen(wxColor(47,139,205)));
                    //memDC.SetBrush(wxBrush(wxColor(47,139,205)));
                    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
                }
                else if(msr->iseg.ipos[i]==2)
                {
                    memDC.SetPen(*wxRED_PEN);
                    memDC.SetBrush(*wxRED_BRUSH);
                }
                memDC.DrawCircle(x2,y2,5);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnMotionKiFig(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    int n=msr->segt.Ks;
    double r;
    for(int i=0;i<n+3;i++)
    {
        r=(x-button[ID_BTN_COUNT+i].x)*(x-button[ID_BTN_COUNT+i].x)+(y-button[ID_BTN_COUNT+i].y)*(y-button[ID_BTN_COUNT+i].y);
        r=sqrt(r);
        if(r<button[ID_BTN_COUNT+i].width)
        {
            motion=ID_BTN_COUNT+i;
            break;
        }
        else
        {
            motion=ID_BTN_NONE;
        }
    }
    segKi->Refresh();
}

void mtg_tFrame::OnLeaveKiFig(wxMouseEvent& event)
{
    motion=ID_BTN_NONE;
    segKi->Refresh();
}

void mtg_tFrame::OnClickKiFig(wxMouseEvent& event)
{
    int k=msr->segt.Ks;
    int i;
    for(i=0;i<k;i++)
    {
        if(motion==ID_BTN_COUNT+i)
        {
            if(msr->iseg.k!=i)
            {
                msr->iseg.k=i;
            }
            break;
        }
    }
    segKi->Refresh();
    //panelOption->Refresh();
}

void mtg_tFrame::OnPaintResFig(wxPaintEvent& event)
{
    wxPaintDC dc(resFig);
    int w,h;
    resFig->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(108,108,108)));
        memDC.DrawLine(7,h/2,w-7,h/2);
        memDC.DrawLabel(_("平面"),wxRect(7,15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLabel(_("垂直"),wxRect(7,h/2+15,0,0),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=h;

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void mtg_tFrame::OnSize(wxSizeEvent& event)
{
    int w,h;
    GetClientSize(&w,&h);
    panelMain->SetSize(0,0,w,h-28);
    panelTool->SetSize(0,0,w,32);
    panelTip->SetSize(0,32,w,24);
    panelPage->SetSize(0,56,w,28);
    panelBar->SetSize(0,h-28,w,28);

    int x1,y1,w1,h1;
    x1=0;
    y1=106;
    w1=w-x1*2;
    h1=h-105;
    panelDes->SetSize(x1,y1,w1,h1);
    desButton->SetSize(0,0,115,h1-1);
    //panelBar->Show(false);
    panelMain->Refresh();
    panelTool->Refresh();
    panelTip->Refresh();
    panelPage->Refresh();
    panelBar->Refresh();
    panelLogo->Refresh();

}

void mtg_tFrame::OnPaintLogo(wxPaintEvent& event)
{
    wxPaintDC dc(panelLogo);
    int w,h;
    panelLogo->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.SetBrush(wxBrush(wxColor(236,241,254)));
        memDC.DrawRectangle(0,-1,w+2,h+2);

        if(bmpLogo.IsOk())
        {
            int w1,h1;
            w1=bmpLogo.GetWidth();
            h1=bmpLogo.GetHeight();
            double s=w1/3.0/w;
            memDC.SetUserScale(s,s);
            memDC.DrawBitmap(bmpLogo,w/2/s-w1/2,h/2/s-h1/2);
            memDC.SetUserScale(1.0,1.0);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}


void mtg_tFrame::PaintHorizon(wxMemoryDC* memDC, wxRect rect,double ds)
{
    int x,y;
	x = rect.x;
	y = rect.y;
    int w,h;
    GetSize(&w,&h);
    double sx,sy;
    sx = w/1024.0;
    sy = h/768.0;
    w = rect.width;
	h = rect.height;
    //FILE* fp = fopen("E:\\painthorizon.log","w");
	ds = h/6/ds;

	int nh = road_number_horizon(&msr->r);

    memDC->SetPen(wxPen(wxColor(112,112,112)));
    memDC->SetBrush(wxBrush(wxColor(248,248,248)));
    memDC->DrawRectangle(x,y,w,h-1);

    //fclose(fp);
}

void mtg_tFrame::PaintVertical(wxMemoryDC* memDC, wxRect rect,double ds)
{
    int x,y;
	x = rect.x;
	y = rect.y;
    int w,h;
    GetSize(&w,&h);
    double sx,sy;
    sx = w/1024.0;
    sy = h/768.0;
    w = rect.width;
	h = rect.height;
    ds=h/6/ds;
    //FILE* fp=fopen("E:\\PaintVertical.log","w");
    memDC->SetPen(wxPen(wxColor(112,112,112)));
    memDC->SetBrush(wxBrush(wxColor(248,248,248)));
    memDC->DrawRectangle(x,y+1,w,h-2);


    //fclose(fp);
}


void mtg_tFrame::OnPaintBar(wxPaintEvent& event)
{
    wxPaintDC dc(panelBar);
    int w,h;

    panelBar->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("黑体"),wxFONTENCODING_DEFAULT);
        wxFont eni(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_("Arial"),wxFONTENCODING_DEFAULT);
        //background
        memDC.SetPen(wxPen(wxColor(245,248,250)));
        memDC.SetBrush(wxBrush(wxColor(245,248,250)));
        memDC.DrawRectangle(0,0,w,h);
        memDC.SetPen(wxPen(wxColor(178,178,178)));
        memDC.DrawLine(0,0,w,0);


        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}
