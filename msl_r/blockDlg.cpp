///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "blockDlg.h"
#include "msr_tApp.h"
#include "BlockEditDlg.h"
#include "confirmdlg.h"
//#include "SegDialog.h"
//#include "EntryDlg.h"
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/event.h>

#define PI  3.1415926535897932384626433832795

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(blockDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(blockDlg)
#include <wx/font.h>
//*)

///////////////////////////////////////////////////////////////////////////
//(*IdInit(blockDlg)

//*)

blockDlg::blockDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
    panelBlock = new wxPanel(panelMain, wxID_ANY, wxPoint(0,11), wxSize(w,h-57), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBlock->SetBackgroundColour(wxColor(239,239,239));

    //panelTbmgen = new wxPanel(panelBlock, wxID_ANY, wxPoint(0,33), wxSize(w,h-85), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //panelTbmgen->SetBackgroundColour(wxColor(239,239,239));
    //panelTbmJack = new wxPanel(panelBlock, wxID_ANY, wxPoint(0,33), wxSize(w,h-85), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    //panelTbmJack->SetBackgroundColour(wxColor(239,239,239));
    //panelTbmJack->Show(false);
    x1=14;
    y1=16;
    w1=w-x1*2;
    h1=h-y1-75;
    panelList = new wxPanel(panelBlock, wxID_ANY, wxPoint(x1,y1), wxSize(w1-72,h1/2-5), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelList->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    blockList = new wxListView(panelList, wxID_ANY, wxPoint(0,24), wxSize(w1-72,h1/2-29), wxLC_REPORT | wxLC_NO_HEADER, wxDefaultValidator, _T("wxID_ANY"));
    panelButton = new wxPanel(panelBlock, wxID_ANY, wxPoint(x1+w1-65,y1), wxSize(65,h1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelButton->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelFig = new wxPanel(panelBlock, wxID_ANY, wxPoint(x1,y1+h1/2+10), wxSize(w1-72,h1/2-5), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelFig->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelBottom = new wxPanel(this, wxID_ANY, wxPoint(0,h-45), wxSize(w,45), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    panelBottom->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    panelMain->Connect(wxEVT_PAINT,(wxObjectEventFunction)&blockDlg::OnPaintMain,0,this);

    panelList->Connect(wxEVT_PAINT,(wxObjectEventFunction)&blockDlg::OnPaintListHeader,0,this);

    panelFig->Connect(wxEVT_PAINT,(wxObjectEventFunction)&blockDlg::OnPaintFig,0,this);

    panelButton->Connect(wxEVT_PAINT,(wxObjectEventFunction)&blockDlg::OnPaintButton,0,this);
    panelButton->Connect(wxEVT_MOTION,(wxObjectEventFunction)&blockDlg::OnMotionButton,0,this);
    panelButton->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&blockDlg::OnLeaveButton,0,this);
    panelButton->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&blockDlg::OnClickButton,0,this);

    blockList->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&blockDlg::OnListBlockSelect,0,this);
    blockList->Connect(wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&blockDlg::OnListBlockDeselect,0,this);
    blockList->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&blockDlg::OnListBlockActivated,0,this);

    panelBottom->Connect(wxEVT_PAINT,(wxObjectEventFunction)&blockDlg::OnPaintBottom,0,this);
    panelBottom->Connect(wxEVT_MOTION,(wxObjectEventFunction)&blockDlg::OnMotionBottom,0,this);
    panelBottom->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&blockDlg::OnLeaveBottom,0,this);
    panelBottom->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&blockDlg::OnClickBottom,0,this);
    //*)

    this->SetBackgroundColour(wxColor(245,248,250));

    int i=0;
    blockList->InsertColumn(i++,_("序号"),wxLIST_FORMAT_CENTRE,85);
    blockList->InsertColumn(i++,_("名称"),wxLIST_FORMAT_CENTRE,120);
    blockList->InsertColumn(i++,_("圆心角"),wxLIST_FORMAT_CENTRE,120);

    motion=ID_BLK_NONE;

    nb=msr->nblk;
    blocks=(BLOCK_T*)malloc(nb*sizeof(BLOCK_T));
    for(i=0;i<nb;i++)
    {
        blocks[i]=msr->blocks[i];
    }
    UpdateBlocks();
}

blockDlg::~blockDlg()
{

}

void blockDlg::OnPaintButton(wxPaintEvent& event)
{
    wxPaintDC dc(panelButton);
    int w,h;
    panelButton->GetClientSize(&w,&h);
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
        x1=0;
        y1=0;
        w1=w;
        h1=25;

        int n = blockList->GetFirstSelected();
        int Num = blockList->GetItemCount();
        int isel=0;
        if(n>=0 && n<Num) isel=1;

        button[ID_BLK_ADD].x=x1+1;
        button[ID_BLK_ADD].y=y1+1;
        button[ID_BLK_ADD].width=w1-1;
        button[ID_BLK_ADD].height=h1-2;
        if(motion==ID_BLK_ADD)
        {
            memDC.SetBrush(ibrush[1]);
            memDC.SetPen(ipen[1]);
            memDC.SetTextForeground(icolor[1]);
        }
        else
        {
            memDC.SetBrush(ibrush[0]);
            memDC.SetPen(ipen[0]);
            memDC.SetTextForeground(icolor[0]);
        }
        memDC.DrawRoundedRectangle(button[ID_BLK_ADD],3);
        memDC.DrawLabel(_("添加"),wxRect(button[ID_BLK_ADD]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+5;
        button[ID_BLK_EDI].x=x1+1;
        button[ID_BLK_EDI].y=y1+1;
        button[ID_BLK_EDI].width=w1-1;
        button[ID_BLK_EDI].height=h1-2;
        if(isel==1)
        {
            if(motion==ID_BLK_EDI)
            {
                memDC.SetBrush(ibrush[1]);
                memDC.SetPen(ipen[1]);
                memDC.SetTextForeground(icolor[1]);

            }
            else
            {
                memDC.SetBrush(ibrush[0]);
                memDC.SetPen(ipen[0]);
                memDC.SetTextForeground(icolor[0]);
            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawRoundedRectangle(button[ID_BLK_EDI],3);
        memDC.DrawLabel(_("编辑"),wxRect(button[ID_BLK_EDI]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y1=y1+h1+5;
        button[ID_BLK_DEL].x=x1+1;
        button[ID_BLK_DEL].y=y1+1;
        button[ID_BLK_DEL].width=w1-1;
        button[ID_BLK_DEL].height=h1-2;
        if(isel==1)
        {
            if(motion==ID_BLK_DEL)
            {
                memDC.SetBrush(ibrush[1]);
                memDC.SetPen(ipen[1]);
                memDC.SetTextForeground(icolor[1]);

            }
            else
            {
                memDC.SetBrush(ibrush[0]);
                memDC.SetPen(ipen[0]);
                memDC.SetTextForeground(icolor[0]);
            }
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(117,117,117)));
            memDC.SetBrush(wxBrush(wxColor(248,248,248)));
            memDC.SetTextForeground(wxColor(168,168,168));
        }
        memDC.DrawRoundedRectangle(button[ID_BLK_DEL],3);
        memDC.DrawLabel(_("删除"),wxRect(button[ID_BLK_DEL]),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void blockDlg::OnMotionButton(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();

    if(x>button[ID_BLK_ADD].x && x<button[ID_BLK_ADD].x+button[ID_BLK_ADD].width)
    {
        if(y>button[ID_BLK_ADD].y && y<button[ID_BLK_ADD].y+button[ID_BLK_ADD].height)
        {
            motion=ID_BLK_ADD;
        }
        else if(y>button[ID_BLK_EDI].y && y<button[ID_BLK_EDI].y+button[ID_BLK_EDI].height)
        {
            motion=ID_BLK_EDI;
        }
        else if(y>button[ID_BLK_DEL].y && y<button[ID_BLK_DEL].y+button[ID_BLK_DEL].height)
        {
            motion=ID_BLK_DEL;
        }
        else
        {
            motion=ID_BLK_NONE;
        }
    }
    else
    {
        motion=ID_BLK_NONE;
    }
    panelButton->Refresh();
}

void blockDlg::OnLeaveButton(wxMouseEvent& event)
{
    motion=ID_BLK_NONE;
    panelButton->Refresh();
}

void blockDlg::OnClickButton(wxMouseEvent& event)
{
    wxString str1;
    double val;
    if(motion==ID_BLK_ADD)
    {
        BlockEditDlg dlg(this);
        dlg.Center();
        dlg.blkName->SetFocus();
        if(dlg.ShowModal()==wxID_OK)
        {
            BLOCK_T b;
            str1=dlg.blkName->GetValue();
            strncpy(b.name,str1.mb_str(wxConvUTF8),64);
            dlg.Angle->GetValue().ToDouble(&b.angle);
            b.angle=b.angle*PI/180.0;

            if(nb>=36)
            {
                for(int i=0;i<35;i++)
                {
                    blocks[i]=blocks[i+1];
                }
                blocks[35]=b;
                nb=36;
            }
            else
            {
                nb++;
                blocks[nb-1]=b;
            }
            UpdateBlocks();
            panelBottom->Refresh();
            panelFig->Refresh();
        }
    }
    else if(motion==ID_BLK_EDI)
    {
        int n = blockList->GetFirstSelected();
        int Num = blockList->GetItemCount();
        if(n<0 || n>Num-1) return;

        BlockEditDlg dlg(this);
        dlg.Center();
        str1=wxString(blocks[n].name,wxConvUTF8);
        dlg.blkName->SetValue(str1);
        str1=wxString::Format(_("%.2f"),blocks[n].angle*180.0/PI);
        dlg.Angle->SetValue(str1);
        if(dlg.ShowModal()==wxID_OK)
        {
            str1=dlg.blkName->GetValue();
            strncpy(blocks[n].name,str1.mb_str(wxConvUTF8),64);
            dlg.Angle->GetValue().ToDouble(&blocks[n].angle);
            blocks[n].angle=blocks[n].angle*PI/180.0;
            UpdateBlocks();
            panelBottom->Refresh();
            panelFig->Refresh();
        }
    }
    else if(motion==ID_BLK_DEL)
    {
        ConfirmDlg dlg(this);
        dlg.Center();
        if(dlg.ShowModal()==wxID_OK)
        {
            int n = blockList->GetFirstSelected();
            int Num = blockList->GetItemCount();
            if(n<0 || n>Num-1) return;

            for(int i=n;i<nb;i++)
            {
                blocks[i]=blocks[i+1];
            }
            nb--;
            UpdateBlocks();
            if(n<nb)
            {
                blockList->Select(n);
                blockList->EnsureVisible(n);
            }
            else if(n>0)
            {
                blockList->Select(n-1);
                blockList->EnsureVisible(n-1);
            }
        }
        panelFig->Refresh();
    }
    panelButton->Refresh();
}

void blockDlg::OnListBlockSelect(wxListEvent& event)
{
    panelFig->Refresh();
    panelButton->Refresh();
}

void blockDlg::OnListBlockActivated(wxListEvent& event)
{
    int n = blockList->GetFirstSelected();
    int Num = blockList->GetItemCount();

    if(n<0 || n>Num-1) return;

    BlockEditDlg dlg(this);
    dlg.Center();
    wxString str;
    str=wxString(blocks[n].name,wxConvUTF8);
    dlg.blkName->SetValue(str);
    str=wxString::Format(_("%.2f"),blocks[n].angle*180.0/PI);
    dlg.Angle->SetValue(str);
    if(dlg.ShowModal()==wxID_OK)
    {
        wxString str=dlg.blkName->GetValue();
        strncpy(blocks[n].name,str.mb_str(wxConvUTF8),64);
        dlg.Angle->GetValue().ToDouble(&blocks[n].angle);
        blocks[n].angle=blocks[n].angle*PI/180.0;
        panelBottom->Refresh();
        UpdateBlocks();
    }
    panelButton->Refresh();
}

void blockDlg::OnListBlockDeselect(wxListEvent& event)
{
    panelFig->Refresh();
    panelButton->Refresh();
}

void blockDlg::OnPaintListHeader(wxPaintEvent& event)
{
    wxPaintDC dc(panelList);
    int w,h;
    panelList->GetClientSize(&w,&h);
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

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=24;
        memDC.DrawLine(x1,y1+h1,w,y1+h1);

        w1=blockList->GetColumnWidth(0);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("序号"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=blockList->GetColumnWidth(1);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("管块名称"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        x1+=w1;
        w1=blockList->GetColumnWidth(2);
        memDC.DrawLine(x1+w1,y1,x1+w1,y1+h1);
        memDC.DrawLabel(_("圆心角(°)"),wxRect(x1,y1,w1,h1),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void blockDlg::UpdateBlocks()
{
    blockList->DeleteAllItems();

    for(int i=0; i<nb; i++)
    {
        blockList->InsertItem(i,wxString::Format(_("%d"),i+1));
        blockList->SetItem(i,1,wxString(blocks[i].name,wxConvUTF8));
        blockList->SetItem(i,2,wxString::Format(_("%.2f"),blocks[i].angle*180/PI));
    }
}

void blockDlg::OnPaintFig(wxPaintEvent& event)
{
    wxPaintDC dc(panelFig);
    int w,h;
    panelFig->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        ///background
        memDC.SetPen(wxPen(wxColor(158,158,158)));
        memDC.SetBrush(wxBrush(wxColor(237,240,245)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Times New Roman"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        int x1,y1,w1,h1;
        x1=0;
        y1=0;
        w1=w;
        h1=h;
        int x2,y2,x3,y3,x4,y4,x5,y5;

        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.SetBrush(wxBrush(wxColor(238,244,250)));
        memDC.DrawRectangle(x1,y1,w1,h1);

        double radius=(h-20)/2.0;
        int sel = blockList->GetFirstSelected();
        x1=x1+w1/2;
        y1=y1+h1/2;
        if(msr->nblk>0)
        {
            int k=msr->segt.Ks;
            double a0=2.0*PI/k;
            double deta=blocks[0].angle/2.0;

            double a1=PI*3.0/2.0-deta;
            double a2=a1;
            for(int i=0;i<msr->nblk;i++)
            {
                x2=x1+radius*cos(a1+0.02);
                y2=y1+radius*sin(a1+0.02);
                x4=x1+(radius-20)*cos(a1+0.02);
                y4=y1+(radius-20)*sin(a1+0.02);
                a1+=blocks[i].angle;
                x3=x1+radius*cos(a1-0.02);
                y3=y1+radius*sin(a1-0.02);
                x5=x1+(radius-20)*cos(a1-0.02);
                y5=y1+(radius-20)*sin(a1-0.02);
                if(i==sel) memDC.SetPen(wxPen(wxColor(255,30,30)));
                else memDC.SetPen(wxPen(wxColor(132,128,113)));
                memDC.DrawArc(x3,y3,x2,y2,x1,y1);
                memDC.DrawArc(x5,y5,x4,y4,x1,y1);
            }

            memDC.SetPen(wxPen(wxColor(238,244,250)));
            memDC.SetBrush(wxBrush(wxColor(238,244,250)));
            memDC.DrawCircle(x1,y1,radius-22);
            memDC.SetPen(wxPen(wxColor(60,66,87)));
            memDC.DrawLine(x1-radius-5,y1,x1+radius+5,y1);
            memDC.DrawLine(x1,y1-radius-5,x1,y1+radius+5);

            a1=PI*3.0/2.0-deta;
            a1=a1;
            memDC.SetPen(wxPen(wxColor(60,66,87),1,wxDOT_DASH));
            for(int i=0;i<msr->nblk;i++)
            {
                a1+=blocks[i].angle;
                x5=x1+(radius-20)*cos(a1-0.02);
                y5=y1+(radius-20)*sin(a1-0.02);
                memDC.DrawLine(x5,y5,x1,y1);
            }
        }

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void blockDlg::OnPaintBottom(wxPaintEvent& event)
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
        int w2,h2;
        memDC.SetPen(wxPen(wxColor(117,117,117)));


        w1=65;
        h1=26;
        x1=w/2+4;
        y1=9;
        button[ID_BLK_CANCEL].x=x1;
        button[ID_BLK_CANCEL].y=y1;
        button[ID_BLK_CANCEL].width=w1;
        button[ID_BLK_CANCEL].height=h1;
        if(motion==ID_BLK_CANCEL)
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

        x1=x1-w1-8;
        button[ID_BLK_OK].x=x1;
        button[ID_BLK_OK].y=y1;
        button[ID_BLK_OK].width=w1;
        button[ID_BLK_OK].height=h1;
        if(motion==ID_BLK_OK)
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

void blockDlg::OnMotionBottom(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();
    if(y>button[ID_BLK_CANCEL].y && y<button[ID_BLK_CANCEL].y+button[ID_BLK_CANCEL].height)
    {
        if(x>button[ID_BLK_CANCEL].x && x<button[ID_BLK_CANCEL].x+button[ID_BLK_CANCEL].width)
        {
            motion=ID_BLK_CANCEL;
        }
        else if(x>button[ID_BLK_OK].x && x<button[ID_BLK_OK].x+button[ID_BLK_OK].width)
        {
            motion=ID_BLK_OK;
        }
        else
        {
            motion=ID_BLK_NONE;
        }
    }
    else
    {
        motion=ID_BLK_NONE;
    }
    panelBottom->Refresh();
}

void blockDlg::OnLeaveBottom(wxMouseEvent& event)
{
    motion=ID_BLK_NONE;
    panelBottom->Refresh();
}

void blockDlg::OnClickBottom(wxMouseEvent& event)
{
    if(motion==ID_BLK_CANCEL)
    {
        Destroy();
    }
    else if(motion==ID_BLK_OK)
    {
        wxStandardPaths wsp;
        wxString str=wsp.GetDataDir()+wxString(_("\\plugins\\"))+wxString(_("blocks.blk"));
        char path[260];
        strcpy(path,str.mb_str(wxConvLocal));
        FILE* fp=fopen(path,"w");

        if(msr->nblk!=nb) msr->blocks=(BLOCK_T*)realloc(msr->blocks,nb*sizeof(BLOCK_T));
        msr->nblk=nb;
        if(fp) fprintf(fp,"%%R1P,%d:%d\n",0,nb);
        for(int i=0;i<nb;i++)
        {
            msr->blocks[i]=blocks[i];
            if(fp) fprintf(fp,"%%R1P,%d:%d,'%s',%f\n",1,i,blocks[i].name,blocks[i].angle);
        }

        if(fp) fclose(fp);

        Destroy();
    }
    //panelBottom->Refresh();
}

void blockDlg::OnPaintMain(wxPaintEvent& event)
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
