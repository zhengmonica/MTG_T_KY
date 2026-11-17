#include "wx_pch.h"
#include "TailSpaceDlg.h"
#include "DistDlg.h"
#define PI 3.1415926
#include "ConfirmDlg.h"

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
	//Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	this->SetSizeHints(wxDefaultSize,wxDefaultSize);
	this->Centre(wxBOTH);
	int w,h;
	int x1,y1,x2,y2;
	int w1,h1,w2,h2;
	this->GetClientSize(&w,&h);
	wxFont normalFont(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
    panelMain = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h-45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelPage = new wxPanel(panelMain, wxID_ANY, wxPoint(0,10), wxSize(w,28), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelPage->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

	panelButtonList=new MDButtonList(this,wxID_ANY,wxPoint(0,31),wxSize(150,h-76), wxTAB_TRAVERSAL, _T("ID_PANEL2"));

    panelNavi = new wxPanel(panelMain, wxID_ANY, wxPoint(600+w,10), wxSize(160,h-90), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelNavi->Show(false);
    x1=7;
    y1=59;
    w1=w-x1*2;
    h1=h-114;

    panelComm = new wxPanel(panelMain, wxID_ANY, wxPoint(x1,y1), wxSize(w1,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelComm->SetBackgroundColour(wxColor(238,244,250));
    x2=0;
    y2=0;
    w2=w1;
    h2=40;
    panelCommtype = new wxPanel(panelComm, wxID_ANY, wxPoint(0,0), wxSize(w1,25), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelCommtype->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelCommtype->Show(false);
    x1=14;
    y1=9;
    w2=w1-x1*2;
    comStaticText1 = new wxStaticText(panelComm, wxID_ANY, _("IP地址："), wxPoint(x1,y1), wxDefaultSize, 0, _("wxID_ANY"));
    comStaticText4 = new wxStaticText(panelComm, wxID_ANY, _("."), wxPoint(x1+108,y1), wxDefaultSize, 0, _("wxID_ANY"));
    comStaticText5 = new wxStaticText(panelComm, wxID_ANY, _("."), wxPoint(x1+158,y1), wxDefaultSize, 0, _("wxID_ANY"));
    comStaticText6 = new wxStaticText(panelComm, wxID_ANY, _("."), wxPoint(x1+208,y1), wxDefaultSize, 0, _("wxID_ANY"));
    comTextCtrl1 = new wxMyTextCtrl(panelComm, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1), wxSize(40,-1), 0);
    comTextCtrl2 = new wxMyTextCtrl(panelComm, wxID_ANY, wxEmptyString, wxPoint(x1+115,y1), wxSize(40,-1), 0);
    comTextCtrl3 = new wxMyTextCtrl(panelComm, wxID_ANY, wxEmptyString, wxPoint(x1+165,y1), wxSize(40,-1), 0);
    comTextCtrl4 = new wxMyTextCtrl(panelComm, wxID_ANY, wxEmptyString, wxPoint(x1+215,y1), wxSize(40,-1), 0);
    y1+=30;
    comStaticText2 = new wxStaticText(panelComm, wxID_ANY, _("端口号："), wxPoint(x1,y1+7), wxDefaultSize, 0, _("wxID_ANY"));
    txtPort = new wxMyTextCtrl(panelComm, wxID_ANY, wxEmptyString, wxPoint(x1+65,y1), wxSize(90,25), 0);



    wxString choice[]={_("COM1"),_("COM2"),_("COM3"),_("COM4"),_("COM5"),_("COM6"),_("COM7"),_("COM8"),_("COM9"),_("COM10")};
    comChoice1=new wxChoice(panelComm,wxID_ANY,wxPoint(x1+65,y1),wxSize(130,25),10,choice,0,wxDefaultValidator,_("wxID_ANY"));
    comChoice1->Show(false);

    y1+=30;
    wxString choice1[]={_("1200"),_("2400"),_("4800"),_("9600"),_("14400"),_("19200"),_("38400"),_("56000"),_("57600"),_("115200")};
    comChoice2=new wxChoice(panelComm,wxID_ANY,wxPoint(x1+65,y1),wxSize(130,25),10,choice1,0,wxDefaultValidator,_("wxID_ANY"));
    comChoice2->Show(false);

    if(mtg->ts.comtype==STR_SERIAL)
    {
        //comStaticText3->SetLabel(_("端口号"));

        //comStaticText3->Show(true);
        //comChoice1->Show(true);
        //comStaticText4->Show(false);
        //comStaticText5->Show(false);
        //comStaticText6->Show(false);
        //comTextCtrl1->Show(false);
        //comTextCtrl2->Show(false);
        //comTextCtrl3->Show(false);
        //comTextCtrl4->Show(false);
        //txtPort->Show(false);
        //comChoice2->Show(true);
    }
    else if(mtg->ts.comtype==STR_TCPCLI)
    {
        //comStaticText3->SetLabel(_("IP地址"));

        //comChoice1->Show(false);
        //comStaticText4->Show(true);
        //comStaticText5->Show(true);
        //comStaticText6->Show(true);
        //comTextCtrl1->Show(true);
        //comTextCtrl2->Show(true);
        //comTextCtrl3->Show(true);
        //comTextCtrl4->Show(true);
        //txtPort->Show(true);
        //comChoice2->Show(false);
    }

    panelAddress=new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelAddress->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2-75;
    h2=(h1-y1-15)/2;
    panelListTitle = new wxPanel(panelAddress, wxID_ANY, wxPoint(x1,y1), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //panelListTitle->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelList= new wxListView(panelListTitle, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-23), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    panelList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x1+w2+10;
    y2=y1;
    w2=65;
    panelSetButton = new wxPanel(panelAddress, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelSetButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    y2=y1+h2;
    x2=x1;
    w2=w1-x1*2-75;
    h2=(h1-y1-15)/2;
    panelGraph = new wxPanel(panelAddress, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //panelGraph->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelData = new wxPanel(panelMain, wxID_ANY, wxPoint(w+150,11), wxSize(w-150,h-88), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelData->SetBackgroundColour(wxColor(239,239,239));
    x1=14;
    y1=9;
    w2=w1-x1*2-75;
    h2=(h1-y1-15)/2;
    panelDataListTitle = new wxPanel(panelData, wxID_ANY, wxPoint(x1,y1), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //panelDataListTitle->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    panelDataList= new wxListView(panelDataListTitle, wxID_ANY, wxPoint(0,24), wxSize(w2,h2-24), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    panelDataList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    x2=x1+w2+10;
    y2=y1;
    w2=65;
    panelMeasButton=new wxPanel(panelData,wxID_ANY,wxPoint(x2,y2),wxSize(w2,h2),wxTAB_TRAVERSAL,_T("wxID_ANY"));
    panelMeasButton->SetBackgroundColour(wxColor(239,239,239));

    y2=y1+h2;
    x2=x1;
    w2=w1-x1*2-75;
    h2=(h1-y1-15)/2;
    panelDataGraph = new wxPanel(panelData, wxID_ANY, wxPoint(x2,y2), wxSize(w2,h2), wxTAB_TRAVERSAL, _T("wxID_ANY"));

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	panelNavi->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintMain,0,this);

    panelPage->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintPage,0,this);
    panelPage->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionPage,0,this);
    panelPage->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeavePage,0,this);
    panelPage->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickPage,0,this);

	panelNavi->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintNavi,0,this);

    panelCommtype->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintCommtype,0,this);
    panelCommtype->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionCommtype,0,this);
    panelCommtype->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeaveCommtype,0,this);
    panelCommtype->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickCommtype,0,this);

    panelSetButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintSetButton,0,this);
    panelSetButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionSetButton,0,this);
    panelSetButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeaveSetButton,0,this);
    panelSetButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickSetButton,0,this);

    panelGraph->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintGraph,0,this);

    panelListTitle->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintList,0,this);
    panelList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&TailSpaceDlg::OnListActivated,0,this);

    panelDataListTitle->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintDataList,0,this);
    panelDataGraph->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintDataGraph,0,this);

    panelMeasButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintMeasButton,0,this);
    panelMeasButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionMeasButton,0,this);
    panelMeasButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeaveMeasButton,0,this);
    panelMeasButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickMeasButton,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&TailSpaceDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&TailSpaceDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&TailSpaceDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnClickBottom,0,this);

    panelButtonList->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&TailSpaceDlg::OnButtonClick,0,this);
    this->SetBackgroundColour(wxColor(245,248,250));

    panelButtonList->btn_height=27;
    panelButtonList->AddButton(_("通讯参数"));
    panelButtonList->AddButton(_("设备地址"));
    panelButtonList->AddButton(_("间隙测量"));
    panelButtonList->btn_clicked=0;
    panelButtonList->Show(false);
    int i=0;
    panelList->InsertColumn(i++,_("位置序号"),wxLIST_FORMAT_CENTER,100);
    panelList->InsertColumn(i++,_("圆心角(°)"),wxLIST_FORMAT_CENTER,100);
    panelList->InsertColumn(i++,_("设备的理论地址"),wxLIST_FORMAT_CENTER,150);
    panelList->InsertColumn(i++,_("设备的当前地址"),wxLIST_FORMAT_CENTER,150);

	//*)

	page=ID_TG_PAGE_CONNECT;
    motion=ID_TG_NONE;
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
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.SetPen(wxPen(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);


        memDC.SetPen(wxPen(wxColor(241,245,250)));
        memDC.SetBrush(wxBrush(wxColor(241,245,250)));
        memDC.DrawRectangle(-1,38,w+2,h-38);

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
        memDC.DrawLabel(_("通讯参数"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);

        x1=x1+w1;
        tgButton[ID_TG_PAGE_ID].x=x1;
        tgButton[ID_TG_PAGE_ID].y=y1;
        tgButton[ID_TG_PAGE_ID].width=w1;
        tgButton[ID_TG_PAGE_ID].height=h1;
        if(page==ID_TG_PAGE_ID || motion==ID_TG_PAGE_ID)
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

            if(page!=ID_TG_PAGE_ID)
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
        memDC.DrawLabel(_("设备地址"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(x1,y1,x1+w1,y1);
        memDC.DrawLine(x1,y1,x1,y1+h1);

        x1=x1+w1;
        tgButton[ID_TG_PAGE_GAP].x=x1;
        tgButton[ID_TG_PAGE_GAP].y=y1;
        tgButton[ID_TG_PAGE_GAP].width=w1;
        tgButton[ID_TG_PAGE_GAP].height=h1;
        if(page==ID_TG_PAGE_GAP || motion==ID_TG_PAGE_GAP)
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
            if(page!=ID_TG_PAGE_GAP)
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
        else if(x>tgButton[ID_TG_PAGE_ID].x && x<tgButton[ID_TG_PAGE_ID].x+tgButton[ID_TG_PAGE_ID].width)
        {
            motion=ID_TG_PAGE_ID;
        }
        else if(x>tgButton[ID_TG_PAGE_GAP].x && x<tgButton[ID_TG_PAGE_GAP].x+tgButton[ID_TG_PAGE_GAP].width)
        {
            motion=ID_TG_PAGE_GAP;
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
        panelComm->Show(true);
        panelAddress->Show(false);
        panelData->Show(false);
        //segbuttons->Show(false);
    }
    else if(motion==ID_TG_PAGE_ID)
    {
        page=ID_TG_PAGE_ID;
        panelComm->Show(false);
        panelAddress->Show(true);
        panelData->Show(false);
        //segbuttons->Show(true);
    }
    else if(motion==ID_TG_PAGE_GAP)
    {
        page=ID_TG_PAGE_GAP;
        panelComm->Show(false);
        panelAddress->Show(false);
        panelData->Show(true);
        //segbuttons->Show(false);
    }
    panelPage->Refresh();
}

void TailSpaceDlg::OnPaintNavi(wxPaintEvent& event)
{
    wxPaintDC dc(panelNavi);
    int w,h;
    panelNavi->GetClientSize(&w,&h);

    ///background
    dc.SetPen(wxPen(wxColor(201,201,201)));
    dc.SetBrush(wxBrush(wxColor(245,245,245)));
    dc.DrawRectangle(0,-1,w,h+1);
}

void TailSpaceDlg::OnPaintCommtype(wxPaintEvent& event)
{
    wxPaintDC dc(panelCommtype);
    int w,h;
    panelCommtype->GetClientSize(&w,&h);
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
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=h;
        int i=1;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);

        w1=w/3;

        tgButton[ID_TG_COMM_SERIAL1].x=x1;
        tgButton[ID_TG_COMM_SERIAL1].y=y1;
        tgButton[ID_TG_COMM_SERIAL1].width=w1;
        tgButton[ID_TG_COMM_SERIAL1].height=h1;
        memDC.SetPen(wxPen(wxColor(158,158,158)));

        if(mtg->ts.comtype==STR_SERIAL)
        {
            memDC.SetBrush(ibrush[2]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("  串口"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(motion==ID_TG_COMM_SERIAL1)
        {
            memDC.SetBrush(ibrush[2]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("  串口"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_("  串口"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        x1=x1+w1-1;
        tgButton[ID_TG_COMM_TCPCLI1].x=x1;
        tgButton[ID_TG_COMM_TCPCLI1].y=y1;
        tgButton[ID_TG_COMM_TCPCLI1].width=w1;
        tgButton[ID_TG_COMM_TCPCLI1].height=h1;
        if(mtg->ts.comtype==STR_TCPCLI)
        {
            memDC.SetBrush(ibrush[2]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_(" 网络"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else if(motion==ID_TG_COMM_TCPCLI1)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_(" 网络"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.DrawRectangle(x1,y1,w1,h1);
            memDC.DrawLabel(_(" 网络"),wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnMotionCommtype(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(x>tgButton[ID_TG_COMM_SERIAL1].x && x<tgButton[ID_TG_COMM_SERIAL1].x+tgButton[ID_TG_COMM_SERIAL1].width)
    {
        if(y>tgButton[ID_TG_COMM_SERIAL1].y && y<tgButton[ID_TG_COMM_SERIAL1].y+tgButton[ID_TG_COMM_SERIAL1].height)
        {
            motion=ID_TG_COMM_SERIAL1;
        }
        else
        {
            motion=ID_TG_NONE;
        }
    }
    else if(x>tgButton[ID_TG_COMM_TCPCLI1].x && x<tgButton[ID_TG_COMM_TCPCLI1].x+tgButton[ID_TG_COMM_TCPCLI1].width)
    {
        if(y>tgButton[ID_TG_COMM_TCPCLI1].y && y<tgButton[ID_TG_COMM_TCPCLI1].y+tgButton[ID_TG_COMM_TCPCLI1].height)
        {
            motion=ID_TG_COMM_TCPCLI1;
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
    panelCommtype->Refresh();
}

void TailSpaceDlg::OnLeaveCommtype(wxMouseEvent& event)
{
    motion=ID_TG_NONE;
    panelCommtype->Refresh();
}

void TailSpaceDlg::OnClickCommtype(wxMouseEvent& event)
{
    if(motion==ID_TG_COMM_SERIAL1)
    {
        /*mtg->ts.comtype=STR_SERIAL;
        //comStaticText1->SetLabel(_("端口号"));


        comChoice1->Show(true);
        comStaticText4->Show(false);
        comStaticText5->Show(false);
        comStaticText6->Show(false);
        comTextCtrl1->Show(false);
        comTextCtrl2->Show(false);
        comTextCtrl3->Show(false);
        comTextCtrl4->Show(false);
        comChoice2->Show(true);
        txtPort->Show(false);*/
    }
    else if(motion==ID_TG_COMM_TCPCLI1)
    {
        /*mtg->ts.comtype=STR_TCPCLI;
        comStaticText1->SetLabel(_("IP地址"));

        comChoice1->Show(false);
        comStaticText4->Show(true);
        comStaticText5->Show(true);
        comStaticText6->Show(true);
        comTextCtrl1->Show(true);
        comTextCtrl2->Show(true);
        comTextCtrl3->Show(true);
        comTextCtrl4->Show(true);
        comChoice2->Show(false);
        txtPort->Show(true);*/
    }
    panelCommtype->Refresh();
}

void TailSpaceDlg::OnPaintList(wxPaintEvent& event)
{
    wxPaintDC dc(panelListTitle);
    int w,h;
    panelListTitle->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(130,135,145)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;

        int i=0;
        memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
        w1=panelList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("设备序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=panelList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("圆心角(°)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=panelList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("设备的理论地址"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=panelList->GetColumnWidth(i++);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("设备的当前地址"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        i=0;
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        x1=1;
        w1=panelList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=panelList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=panelList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        x1+=w1;
        w1=panelList->GetColumnWidth(i++);
        memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
        memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
        panelList->SetSize(0,h1,w,h-h1);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnPaintSetButton(wxPaintEvent& event)
{
    wxPaintDC dc(panelSetButton);
    int w,h;
    panelSetButton->GetClientSize(&w,&h);
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
        memDC.SetPen(wxPen(wxColor(158,158,158)));

        int x1=0;
        int y1=0;
        int w1=w;
        int h1=25;

        tgButton[ID_FIG_DIST_ADD].x=x1;
        tgButton[ID_FIG_DIST_ADD].y=y1;
        tgButton[ID_FIG_DIST_ADD].width=w1;
        tgButton[ID_FIG_DIST_ADD].height=h1;

        if(motion==ID_FIG_DIST_ADD)
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
        memDC.DrawLabel(_("添加"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);


        y1+=32;
        tgButton[ID_FIG_DIST_EDI].x=x1;
        tgButton[ID_FIG_DIST_EDI].y=y1;
        tgButton[ID_FIG_DIST_EDI].width=w1;
        tgButton[ID_FIG_DIST_EDI].height=h1;
        int sel = panelList->GetFirstSelected();

        if(sel>=0)
        {
            if(motion==ID_FIG_DIST_EDI)
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
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("编辑"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        tgButton[ID_FIG_DIST_DEL].x=x1;
        tgButton[ID_FIG_DIST_DEL].y=y1;
        tgButton[ID_FIG_DIST_DEL].width=w1;
        tgButton[ID_FIG_DIST_DEL].height=h1;
        //int sel = baskList->GetFirstSelected();
        if(sel==-1)
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        else
        {
            if(motion==ID_FIG_DIST_DEL)
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
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("删除"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        tgButton[ID_FIG_DIST_OBTAIN_ADDRESS].x=x1;
        tgButton[ID_FIG_DIST_OBTAIN_ADDRESS].y=y1;
        tgButton[ID_FIG_DIST_OBTAIN_ADDRESS].width=w1;
        tgButton[ID_FIG_DIST_OBTAIN_ADDRESS].height=h1;

        if(motion==ID_FIG_DIST_OBTAIN_ADDRESS)
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
        memDC.DrawLabel(_("获取地址"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        tgButton[ID_FIG_DIST_MODIFY_ADDRESS].x=x1;
        tgButton[ID_FIG_DIST_MODIFY_ADDRESS].y=y1;
        tgButton[ID_FIG_DIST_MODIFY_ADDRESS].width=w1;
        tgButton[ID_FIG_DIST_MODIFY_ADDRESS].height=h1;

        if(sel==-1)
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        else
        {
            if(motion==ID_FIG_DIST_MODIFY_ADDRESS)
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
        }
        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("修改地址"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnMotionSetButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>tgButton[ID_FIG_DIST_ADD].y && y<tgButton[ID_FIG_DIST_ADD].y+tgButton[ID_FIG_DIST_ADD].height)
    {
        if(x>tgButton[ID_FIG_DIST_ADD].x && x<tgButton[ID_FIG_DIST_ADD].x+tgButton[ID_FIG_DIST_ADD].width)
        {
            motion=ID_FIG_DIST_ADD;
        }
        else
        {
            motion=ID_TG_NONE;
        }
    }
    else if(y>tgButton[ID_FIG_DIST_EDI].y && y<tgButton[ID_FIG_DIST_EDI].y+tgButton[ID_FIG_DIST_EDI].height)
    {
        if(x>tgButton[ID_FIG_DIST_EDI].x && x<tgButton[ID_FIG_DIST_EDI].x+tgButton[ID_FIG_DIST_EDI].width)
        {
            motion=ID_FIG_DIST_EDI;
        }
        else
        {
            motion=ID_TG_NONE;
        }
    }
    else if(y>tgButton[ID_FIG_DIST_DEL].y && y<tgButton[ID_FIG_DIST_DEL].y+tgButton[ID_FIG_DIST_DEL].height)
    {
        if(x>tgButton[ID_FIG_DIST_DEL].x && x<tgButton[ID_FIG_DIST_DEL].x+tgButton[ID_FIG_DIST_DEL].width)
        {
            motion=ID_FIG_DIST_DEL;
        }
        else
        {
            motion=ID_TG_NONE;
        }
    }
    else if(y>tgButton[ID_FIG_DIST_OBTAIN_ADDRESS].y && y<tgButton[ID_FIG_DIST_OBTAIN_ADDRESS].y+tgButton[ID_FIG_DIST_OBTAIN_ADDRESS].height)
    {
        if(x>tgButton[ID_FIG_DIST_OBTAIN_ADDRESS].x && x<tgButton[ID_FIG_DIST_OBTAIN_ADDRESS].x+tgButton[ID_FIG_DIST_OBTAIN_ADDRESS].width)
        {
            motion=ID_FIG_DIST_OBTAIN_ADDRESS;
        }
        else
        {
            motion=ID_TG_NONE;
        }
    }
    else if(y>tgButton[ID_FIG_DIST_MODIFY_ADDRESS].y && y<tgButton[ID_FIG_DIST_MODIFY_ADDRESS].y+tgButton[ID_FIG_DIST_MODIFY_ADDRESS].height)
    {
        if(x>tgButton[ID_FIG_DIST_MODIFY_ADDRESS].x && x<tgButton[ID_FIG_DIST_MODIFY_ADDRESS].x+tgButton[ID_FIG_DIST_MODIFY_ADDRESS].width)
        {
            motion=ID_FIG_DIST_MODIFY_ADDRESS;
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

    panelSetButton->Refresh();
}

void TailSpaceDlg::OnLeaveSetButton(wxMouseEvent& event)
{
    motion=ID_TG_NONE;
    panelSetButton->Refresh();
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

void TailSpaceDlg::OnClickSetButton(wxMouseEvent& event)
{
    int i=0;
    if(motion==ID_FIG_DIST_ADD)
    {
        DistDlg dlg(this);
        dlg.Center();
        dlg.ptName->SetFocus();
        if(dlg.ShowModal()==wxID_OK)
        {
            mtg->ts.nSensor++;
            if(mtg->ts.nSensor>5)
            {
                MTG_TAILSPACE tailspace;
                tailspace=mtg->ts;
                free(mtg->ts.dist);
                free(mtg->ts.dist0);
                free(mtg->ts.angle);
                free(mtg->ts.stat);
                free(mtg->ts.ID);
                /*double* ID;
                ID=(double*)malloc((mtg->ts.nSensor-1)*sizeof(double));
                for(i=0;i<mtg->ts.nSensor-1;i++)
                    ID[i]=mtg->ID[i];*/

                mtg->ts.dist=(double*)malloc(mtg->ts.nSensor*sizeof(double));
                mtg->ts.dist0=(double*)malloc(mtg->ts.nSensor*sizeof(double));
                mtg->ts.angle=(double*)malloc(mtg->ts.nSensor*sizeof(double));
                mtg->ts.stat=(int*)malloc(mtg->ts.nSensor*sizeof(int));
                mtg->ts.ID=(int*)malloc(mtg->ts.nSensor*sizeof(int));
                //mtg->ID=(int*)malloc(mtg->ts.nSensor*sizeof(int));
                for(i=0;i<mtg->ts.nSensor-1;i++)
                {
                    mtg->ts.dist[i]=tailspace.dist[i];
                    mtg->ts.dist0[i]=tailspace.dist0[i];
                    mtg->ts.angle[i]=tailspace.angle[i];
                    mtg->ts.stat[i]=tailspace.stat[i];
                    mtg->ts.ID[i]=tailspace.ID[i];
                    //mtg->ID[i]=ID[i];
                }
                //free(ID);
            }
            wxString str;
            str=dlg.ptName->GetValue();
            //strncpy(b.name,str.mb_str(wxConvUTF8),64);
            int ID;
            ID_converse(str,ID);
            mtg->ts.ID[mtg->ts.nSensor-1]=ID;
            //wxMessageBox(wxString::Format(_("%0X"),mtg->ts.ID[mtg->ts.nSensor-1]));
            dlg.ptAngle->GetValue().ToDouble(&mtg->ts.angle[mtg->ts.nSensor-1]);
            mtg->ts.angle[mtg->ts.nSensor-1]=mtg->ts.angle[mtg->ts.nSensor-1]*PI/180.0;
            ///UpdateDistList();
            ///panelGraph->Refresh();

            if(mtg_store_distpara(mtg))
            {
                WriteMsg(_("增加测距仪成功"),0);
                UpdateDistList();
                panelGraph->Refresh();

                UpdateDataList();
                panelDataGraph->Refresh();
                panelDataListTitle->Refresh();
            }
            else
            {
                WriteMsg(_("增加测距仪失败"),1);
            }
        }
    }
    else if(motion==ID_FIG_DIST_EDI)
    {
        int sel = panelList->GetFirstSelected();
        if(sel<0) return;
        DistDlg dlg(this);
        dlg.Center();
        dlg.ptName->SetValue(wxString::Format(_("%0X"),mtg->ts.ID[sel]));
        dlg.ptAngle->SetValue(wxString::Format(_("%.4f"),mtg->ts.angle[sel]*180/PI));

        if(dlg.ShowModal()==wxID_OK)
        {
            wxString str;
            str=dlg.ptName->GetValue();
            //strncpy(b.name,str.mb_str(wxConvUTF8),64);
            int ID;
            ID_converse(str,ID);
            mtg->ts.ID[sel]=ID;
            dlg.ptAngle->GetValue().ToDouble(&mtg->ts.angle[sel]);
            mtg->ts.angle[sel]=mtg->ts.angle[sel]*PI/180.0;
            //UpdateDistList();
            //panelGraph->Refresh();

            if(mtg_store_distpara(mtg))
            {
                WriteMsg(_("编辑测距仪成功！"),0);
                UpdateDistList();
                panelGraph->Refresh();
            }
            else
            {
                WriteMsg(_("编辑测距仪失败！"),1);
            }
        }
        motion=ID_TG_NONE;
    }
    else if(motion==ID_FIG_DIST_DEL)
    {
        int sel = panelList->GetFirstSelected();
        if(sel<0) return;
        ConfirmDlg dlg(this);
        dlg.confirmMsg=_("确定删除")+wxString::Format(_("%d号位置"),sel+1)+_("测距仪吗？");
        dlg.Center();
        if(dlg.ShowModal()==wxID_OK)
        {
            for(int i=sel;i<panelList->GetItemCount();i++)
            {
                mtg->ts.ID[i]=mtg->ts.ID[i+1];
                mtg->ts.angle[i]=mtg->ts.angle[i+1];
                mtg->ID[i]=mtg->ID[i+1];
            }
            mtg->ts.nSensor--;
            //UpdateDistList();
            //panelGraph->Refresh();
            if(mtg_store_distpara(mtg))
            {
                WriteMsg(_("删除吊篮成功！"),0);
                UpdateDistList();
                panelGraph->Refresh();

                UpdateDataList();
                panelDataGraph->Refresh();
                panelDataListTitle->Refresh();
            }
            else
            {
                WriteMsg(_("删除吊篮失败！"),1);
            }
        }
    }
    else if(motion==ID_FIG_DIST_OBTAIN_ADDRESS)
    {
        int sel = panelList->GetFirstSelected();
        if(sel<0) sel=-1;
        if(sel>=0)
        {
            if(!distsvr_read(mtg,sel))
            {
                WriteMsg(wxString::Format(_("获取%d号位置测距仪的设备地址成功!"),sel+1),0);
                UpdateDistList();
            }
            else
                WriteMsg(wxString::Format(_("获取%d号位置测距仪的设备地址失败!"),sel+1),1);
        }
        else
        {
            if(!distsvr_read(mtg,sel))
            {
                WriteMsg(wxString::Format(_("获取所有测距仪的当前设备地址成功!")),0);
                UpdateDistList();
            }
            else
                WriteMsg(wxString::Format(_("获取所有位置测距仪的当前设备地址失败!")),1);
        }
    }
    else if(motion==ID_FIG_DIST_MODIFY_ADDRESS)
    {
        int sel = panelList->GetFirstSelected();
        if(sel<0) return;
        if(!distsvr_write(mtg,mtg->ID[sel],mtg->ts.ID[sel]))
        {
            WriteMsg(wxString::Format(_("设置%d号位置测距仪的理论设备地址成功!"),sel+1),0);
            //mtg->ts.ID[sel]=mtg->ID[sel];
            mtg_store_distpara(mtg);
            UpdateDistList();
        }
        else
            WriteMsg(wxString::Format(_("设置%d号位置测距仪的理论设备地址失败!"),sel+1),1);
    }
    panelSetButton->Refresh();
}

void TailSpaceDlg::OnPaintGraph(wxPaintEvent& event)
{
   wxPaintDC dc(panelGraph);
   int w,h;
   panelGraph->GetClientSize(&w,&h);
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

        int x1,y1;
        x1=w/2;
        y1=h/2;
        int R;
        if(w>h)
            R=h/2-5;
        else
            R=w/2-5;
        memDC.SetPen(wxPen(wxColor(0,0,0),1));
        memDC.DrawCircle(x1,y1,R);

        int r;
        r=R/5;
        memDC.DrawCircle(x1,y1,r);

        int x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x0,y0,xt,yt;
        double angle;
        for(int i=0;i<mtg->ts.nSensor;i++)
        {
            angle=mtg->ts.angle[i];
            x2=x1+r*2.5*sin(angle);
            y2=y1-r*2.5*cos(angle);
            x3=x1+R*sin(angle);
            y3=y1-R*cos(angle);
            memDC.SetPen(wxPen(wxColor(255,0,0)));
            memDC.DrawLine(x2,y2,x3,y3);

            memDC.SetPen(wxPen(wxColor(0,0,0)));

            x3=x1+r*sin(angle);
            y3=y1-r*cos(angle);
            x4=x3+r/2*sin(angle-PI/2.0);
            y4=y3-r/2*cos(angle-PI/2.0);
            xt=x4;
            yt=y4;
            x5=x3+r/2*sin(angle+PI/2.0);
            y5=y3-r/2*cos(angle+PI/2.0);
            memDC.DrawLine(x4,y4,x5,y5);
            x0=0;
            y0=0;
            x0+=x4;
            y0+=y4;
            x0+=x5;
            y0+=y5;

            x4=x5;
            y4=y5;
            x5=x4+r*sin(angle);
            y5=y4-r*cos(angle);
            memDC.DrawLine(x4,y4,x5,y5);
            x0+=x5;
            y0+=y5;

            x4=x5;
            y4=y5;
            x5=x4+r*sin(angle-PI/2.0);
            y5=y4-r*cos(angle-PI/2.0);
            memDC.DrawLine(x4,y4,x5,y5);
            x0+=x5;
            y0+=y5;

            x6=x2;
            y6=y2;
            memDC.DrawLine(x4,y4,x6,y6);
            memDC.DrawLine(x5,y5,x6,y6);

            x4=x5;
            y4=y5;
            x5=xt;
            y5=yt;
            memDC.DrawLine(x4,y4,x5,y5);
            x0+=x5;
            y0+=y5;

            x0=x0/5;
            y0=y0/5;
            memDC.DrawLabel(wxString::Format(_("%d#"),i+1),wxRect(x0-5,y0-5,10,10),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL,-1);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnListActivated(wxListEvent& event)
{
    wxMouseEvent e;
    motion=ID_FIG_DIST_EDI;
    OnClickSetButton(e);
}

void TailSpaceDlg::OnPaintDataList(wxPaintEvent& event)
{
    wxPaintDC dc(panelDataListTitle);
    int w,h;
    panelDataListTitle->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        ///background
        memDC.SetPen(wxPen(wxColor(130,135,145)));
        memDC.SetBrush(wxBrush(wxColor(239,239,239)));
        memDC.DrawRectangle(0,0,w,h);
        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        h1=25;

        int i=0;
        if(mtg->ts.nSensor>0)
        {
            memDC.DrawLine(x1+1,y1+h1-1,w-1,y1+h1-1);
            w1=panelDataList->GetColumnWidth(i++);
            memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
            memDC.DrawLabel(_("数据说明"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            for(i=0;i<mtg->ts.nSensor;i++)
            {
                x1+=w1;
                w1=panelDataList->GetColumnWidth(i+1);
                memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
                memDC.DrawLabel(wxString::Format(_("%d号距离"),i+1),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            }
            x1+=w1;
            w1=panelDataList->GetColumnWidth(i+1);
            memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
            memDC.DrawLabel(wxString::Format(_("时间")),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

            /*i=0;
            memDC.SetPen(wxPen(wxColor(255,255,255)));
            x1=1;
            w1=panelList->GetColumnWidth(i++);
            memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
            memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
            x1+=w1;
            w1=panelList->GetColumnWidth(i++);
            memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
            memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);
            x1+=w1;
            w1=panelList->GetColumnWidth(i++);
            memDC.DrawLine(x1,y1+1,x1,y1+h1-2);
            memDC.DrawLine(x1,y1+1,x1+w1-2,y1+1);*/
            panelDataList->SetSize(0,h1,w,h-h1);
        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnPaintDataGraph(wxPaintEvent& event)
{
    wxPaintDC dc(panelDataGraph);
   int w,h;
   panelDataGraph->GetClientSize(&w,&h);
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

        int x1,y1;
        x1=w/2;
        y1=h/2;
        int R;
        if(w>h)
            R=h/2-20;
        else
            R=w/2-20;

        memDC.SetPen(wxPen(wxColor(0,0,0),1));
        memDC.DrawCircle(x1,y1,R);

        int r;
        r=R/5;
        memDC.DrawCircle(x1,y1,r);

        double maxd,maxR;
        maxd=-1;
        maxR=-1;
        if(mtg->ts.t0<=0)
        {
            mtg->ts.dist0[0]=10;
            mtg->ts.dist[0]=20;
        }
        for(int i=0;i<mtg->ts.nSensor;i++)
        {
            if(maxd<fabs(mtg->ts.dist[i]-mtg->ts.dist0[i]))
                maxd=fabs(mtg->ts.dist[i]-mtg->ts.dist0[i]);
            if(maxR<mtg->ts.dist0[i])
                maxR=mtg->ts.dist0[i];
        }

        double s=maxd*2/R;

        int x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x0,y0,xt,yt;
        double angle;
        double delta=0;

        for(int i=0;i<mtg->ts.nSensor;i++)
        {
            delta=(mtg->ts.dist[i]-mtg->ts.dist0[i]);
            angle=mtg->ts.angle[i];
            x2=x1+R*sin(angle);
            y2=y1-R*cos(angle);
            x3=x1+(R+delta/s)*sin(angle);
            y3=y1-(R+delta/s)*cos(angle);
            memDC.SetPen(wxPen(wxColor(255,0,0)));
            memDC.DrawLine(x2,y2,x3,y3);
            memDC.SetPen(wxPen(wxColor(255,0,0),2));
            memDC.DrawCircle(x3,y3,2);
            memDC.SetPen(wxPen(wxColor(0,0,255),2));
            memDC.DrawCircle(x2,y2,2);
            memDC.SetPen(wxPen(wxColor(0,0,0)));
            memDC.DrawLabel(wxString::Format(_("%d#"),i+1),wxRect(x2+5,y2,10,10),wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL,-1);

        }
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnPaintMeasButton(wxPaintEvent& event)
{
    wxPaintDC dc(panelMeasButton);
    int w,h;
    panelMeasButton->GetClientSize(&w,&h);
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
        memDC.SetPen(wxPen(wxColor(158,158,158)));

        int x1=0;
        int y1=0;
        int w1=w;
        int h1=25;

        tgButton[ID_FIG_DIST_MEAS_ORIGIN].x=x1;
        tgButton[ID_FIG_DIST_MEAS_ORIGIN].y=y1;
        tgButton[ID_FIG_DIST_MEAS_ORIGIN].width=w1;
        tgButton[ID_FIG_DIST_MEAS_ORIGIN].height=h1;

        if(motion==ID_FIG_DIST_MEAS_ORIGIN)
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
        memDC.DrawLabel(_("初始测距"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1+=32;
        tgButton[ID_FIG_DIST_MEAS].x=x1;
        tgButton[ID_FIG_DIST_MEAS].y=y1;
        tgButton[ID_FIG_DIST_MEAS].width=w1;
        tgButton[ID_FIG_DIST_MEAS].height=h1;

        if(motion==ID_FIG_DIST_MEAS)
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
        memDC.DrawLabel(_("测距"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnMotionMeasButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>tgButton[ID_FIG_DIST_MEAS_ORIGIN].y && y<tgButton[ID_FIG_DIST_MEAS_ORIGIN].y+tgButton[ID_FIG_DIST_MEAS_ORIGIN].height)
    {
        if(x>tgButton[ID_FIG_DIST_MEAS_ORIGIN].x && x<tgButton[ID_FIG_DIST_MEAS_ORIGIN].x+tgButton[ID_FIG_DIST_MEAS_ORIGIN].width)
        {
            motion=ID_FIG_DIST_MEAS_ORIGIN;
        }
        else
        {
            motion=ID_TG_NONE;
        }
    }
    else if(y>tgButton[ID_FIG_DIST_MEAS].y && y<tgButton[ID_FIG_DIST_MEAS].y+tgButton[ID_FIG_DIST_MEAS].height)
    {
        if(x>tgButton[ID_FIG_DIST_MEAS].x && x<tgButton[ID_FIG_DIST_MEAS].x+tgButton[ID_FIG_DIST_MEAS].width)
        {
            motion=ID_FIG_DIST_MEAS;
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

    panelMeasButton->Refresh();
}

void TailSpaceDlg::OnLeaveMeasButton(wxMouseEvent& event)
{
    motion=ID_TG_NONE;
    panelMeasButton->Refresh();
}

void TailSpaceDlg::OnClickMeasButton(wxMouseEvent& event)
{
    if(motion==ID_FIG_DIST_MEAS_ORIGIN)
    {
        mtg->ts.opera=DIST_CMD_MEASDIST_ORIGIN;
        distsvr_meas(mtg);
    }
    else if(motion==ID_FIG_DIST_MEAS)
    {
        mtg->ts.opera=DIST_CMD_MEASDIST_CYCLE;
        distsvr_meas(mtg);
    }
    panelMeasButton->Refresh();
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
        tgButton[ID_FIG_BTN_QUIT].x=x1;
        tgButton[ID_FIG_BTN_QUIT].y=y1;
        tgButton[ID_FIG_BTN_QUIT].width=w1;
        tgButton[ID_FIG_BTN_QUIT].height=h1;
        if(motion==ID_FIG_BTN_QUIT)
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

        x1=x1-w1-7;
        tgButton[ID_FIG_BTN_APPLY].x=x1;
        tgButton[ID_FIG_BTN_APPLY].y=y1;
        tgButton[ID_FIG_BTN_APPLY].width=w1;
        tgButton[ID_FIG_BTN_APPLY].height=h1;
        if(panelButtonList->btn_clicked==0)
        {
            if(motion==ID_FIG_BTN_APPLY)
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
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
        }

        memDC.DrawRoundedRectangle(x1,y1,w1,h1,3);
        memDC.DrawLabel(_("应用"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        panelButtonList->GetSize(&w1,0);
        x1=w1+14;
        w1=w-x1*2;
        //memDC.SetPen(ipen[0]);
        //memDC.SetBrush(wxBrush(wxColor(255,255,225)));
        //memDC.DrawRectangle(x1,y1,w1,h1);

        if(m_msgc==0)
        {
            memDC.SetTextForeground(wxColor(0,0,255));
        }
        else
        {
            memDC.SetTextForeground(wxColor(255,0,0));
        }
        if(m_msg!=wxEmptyString) memDC.DrawLabel(m_msg,wxRect(x1,y1,w1,h1),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);

        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,0,w,0);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void TailSpaceDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>tgButton[ID_FIG_BTN_QUIT].y && y<tgButton[ID_FIG_BTN_QUIT].y+tgButton[ID_FIG_BTN_QUIT].height)
    {
        if(x>tgButton[ID_FIG_BTN_QUIT].x && x<tgButton[ID_FIG_BTN_QUIT].x+tgButton[ID_FIG_BTN_QUIT].width)
        {
            motion=ID_FIG_BTN_QUIT;
            //if(m_msg==_("切换为控制模式") || m_msg==_("切换为查看模式")) m_msg=wxEmptyString;
        }
        else if(x>tgButton[ID_FIG_BTN_APPLY].x && x<tgButton[ID_FIG_BTN_APPLY].x+tgButton[ID_FIG_BTN_APPLY].width)
        {
            motion=ID_FIG_BTN_APPLY;
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
    if(motion==ID_FIG_BTN_QUIT)
    {
        Destroy();
    }
    else if(motion==ID_FIG_BTN_APPLY&&panelButtonList->btn_clicked==0)
    {
        Apply();
        panelBottom->Refresh();
    }
}

void TailSpaceDlg::WriteMsg(wxString msg,int col)
{
    m_msg=msg;
    m_msgc=col;
    panelBottom->Refresh();
}

void TailSpaceDlg::UpdateDistList()
{
    panelList->DeleteAllItems();
    //wxMessageBox(wxString::Format(_("%d"),mtg->ts.nSensor));
    for(int i=0;i<mtg->ts.nSensor;i++)
    {
        panelList->InsertItem(i,wxString::Format(_("%d号位置"),i+1));
        panelList->SetItem(i,1,wxString::Format(_("%.4f"),mtg->ts.angle[i]*180/PI));
        panelList->SetItem(i,2,wxString::Format(_("0X%0X"),mtg->ts.ID[i]));
        panelList->SetItem(i,3,wxString::Format(_("0X%0X"),mtg->ID[i]));
    }
}

void TailSpaceDlg::UpdateDataList()
{
    int i=0;
    int j=0;
    panelDataList->DeleteAllItems();
    panelDataList->InsertColumn(i++,_("数据说明"),wxLIST_FORMAT_CENTER,80);
    for(i=0;i<mtg->ts.nSensor;i++)
    {
        panelDataList->InsertColumn(i+1,wxString::Format(_("设备%d距离"),i+1),wxLIST_FORMAT_CENTER,90);
    }
    panelDataList->InsertColumn(i+1,wxString::Format(_("时间")),wxLIST_FORMAT_CENTER,130);

    //j++;
    panelDataList->InsertItem(j,wxString::Format(_("初始数据")));
    panelDataList->SetItemTextColour(j,wxColor(0,0,255));
    for(i=0;i<mtg->ts.nSensor;i++)
    {
        panelDataList->SetItem(j,i+1,wxString::Format(_("%.4f"),mtg->ts.dist0[i]));
    }
    panelDataList->SetItem(j,i+1,wxDateTime(mtg->ts.t0).Format(_("%Y-%m-%d %H:%M:%S")));

    //panelDataList->SetItemTextColour(j,wxColor(0,0,0));
    j++;
    panelDataList->InsertItem(j,wxString::Format(_("最新数据")));
    panelDataList->SetItemTextColour(j,wxColor(255,0,0));
    for(i=0;i<mtg->ts.nSensor;i++)
    {
        panelDataList->SetItem(j,i+1,wxString::Format(_("%.4f"),mtg->ts.dist[i]));
    }
    panelDataList->SetItem(j,i+1,wxDateTime(mtg->ts.t).Format(_("%Y-%m-%d %H:%M:%S")));
}

void TailSpaceDlg::OnButtonClick(wxMouseEvent& event)
{
    int btn=panelButtonList->btn_left_down;
    int w,h;
    panelComm->GetClientSize(&w,&h);
    switch(btn)
    {
    case 0:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelAddress->SetSize(1024,11,w,h);
        panelData->SetSize(1024,11,w,h);
        panelComm->SetSize(0,11,w,h);
        panelBottom->Refresh();
        break;
    case 1:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelAddress->SetSize(0,11,w,h);
        panelData->SetSize(1024,11,w,h);
        panelComm->SetSize(1024,11,w,h);
        panelBottom->Refresh();
        break;
    case 2:
        panelButtonList->btn_clicked=btn;
        panelButtonList->Refresh();
        panelAddress->SetSize(1024,11,w,h);
        panelData->SetSize(0,11,w,h);
        panelComm->SetSize(1024,11,w,h);
        panelBottom->Refresh();
        break;
    default:
        break;
    }
}

void TailSpaceDlg::LoadData()
{
    int val1,val2,val3,val4,val5;
    int baud[]={1200,2400,4800,9600,14400,19200,39200,56000,57600,115200};
    if(mtg->ts.comtype==STR_SERIAL)
    {
        /*comStaticText1->SetLabel(_("端口号"));
        comChoice1->Show(true);
        comStaticText4->Show(false);
        comStaticText5->Show(false);
        comStaticText6->Show(false);
        comTextCtrl1->Show(false);
        comTextCtrl2->Show(false);
        comTextCtrl3->Show(false);
        comTextCtrl4->Show(false);
        int No;
        ///No=(unsigned int)comset[0].ip[4];
        sscanf(mtg->ts.IP,"COM%d",&No);
        if(No<=10&&No>0)
        {
            comChoice1->SetSelection(No-1);
        }
        else
            comChoice1->SetSelection(0);

        for(int i=0;i<10;i++)
        {
            if(mtg->ts.port==baud[i])
            {
                comChoice2->SetSelection(i);
                break;
            }
        }*/
    }
    else if(mtg->ts.comtype==STR_TCPCLI)
    {
        /*comStaticText1->SetLabel(_("IP地址"));
        comChoice1->Show(false);
        comStaticText4->Show(true);
        comStaticText5->Show(true);
        comStaticText6->Show(true);
        comTextCtrl1->Show(true);
        comTextCtrl2->Show(true);
        comTextCtrl3->Show(true);
        comTextCtrl4->Show(true);
        char *result=NULL;
        int No1,No2,No3,No4;
        result=strtok(mtg->ts.IP,".");
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
        }
        comTextCtrl1->SetValue(wxString::Format(_("%d"),No1));
        comTextCtrl2->SetValue(wxString::Format(_("%d"),No2));
        comTextCtrl3->SetValue(wxString::Format(_("%d"),No3));
        comTextCtrl4->SetValue(wxString::Format(_("%d"),No4));
        txtPort->SetValue(wxString::Format(_("%d"),mtg->ts.port));*/
    }
    panelGraph->Refresh();
    UpdateDistList();
    UpdateDataList();
}

void TailSpaceDlg::Apply()
{
    if(panelButtonList->btn_clicked==0)
    {
        int val1,val2,val3,val4,val5;
        double val6;
        char str1[20];
        int baud[]={1200,2400,4800,9600.14400,38400,56000,115200};
        if(mtg->ts.comtype==STR_SERIAL)
        {
            val1=comChoice1->GetSelection();
            val2=comChoice2->GetSelection();
            sprintf(str1,"COM%d",val1+1);
            strcpy(mtg->ts.IP,str1);
            mtg->ts.port=baud[val2];
        }
        else
        {
            comTextCtrl1->GetValue().ToDouble(&val6);
            val1=(int)val6;
            comTextCtrl2->GetValue().ToDouble(&val6);
            val2=(int)val6;
            comTextCtrl3->GetValue().ToDouble(&val6);
            val3=(int)val6;
            comTextCtrl4->GetValue().ToDouble(&val6);
            val4=(int)val6;
            ///val5=comChoice2->GetSelection();
            sprintf(str1,"%d.%d.%d.%d",val1,val2,val3,val4);
            strcpy(mtg->ts.IP,str1);
            ///comset[0].port=baud[val5];
            txtPort->GetValue().ToDouble(&val6);
            mtg->ts.port=val6;
        }
        mtg_store_tailspace(mtg);
        WriteMsg(_("保存通讯参数并连接..."),0);
        distsvr_connect(mtg);
    }
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
                if(((mtg->plogs[i].nlog>=MTG_LOG_BEGIN_DIST_CONNECT) &&( mtg->plogs[i].nlog<=MTG_LOG_BEGIN_DIST_ADDRESS_WRITE))||
                   (mtg->plogs[i].nlog>=MTG_LOG_FINISH_DIST_CONNECT && mtg->plogs[i].nlog<=MTG_LOG_FINISH_DIST_MEASURE_CYCLE)||
                   (mtg->plogs[i].nlog>=MTG_LOG_FAIL_DIST_CONNECT && mtg->plogs[i].nlog<=MTG_LOG_FAIL_DIST_MEASURE_CYCLE))
                {
                    strLog = wxString(mtg->plogs[i].msg,wxConvLocal);
                    WriteMsg(strLog,mtg->plogs[i].type);
                    if(mtg->plogs[i].nlog==MTG_LOG_FINISH_DIST_MEASURE_CYCLE||mtg->plogs[i].nlog==MTG_LOG_FINISH_DIST_MEASURE_ORIGIN)
                    {
                        UpdateDataList();
                    }
                }
            }
    }
}


