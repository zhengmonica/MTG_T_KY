///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "EntryDlg.h"
#include "mtg_tApp.h"
#include "ConfirmDlg.h"
///////////////////////////////////////////////////////////////////////////
const long EntryDlg::ID_PANEL1 = wxNewId();
const long EntryDlg::ID_PANEL2 = wxNewId();

EntryDlg::EntryDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
    int w,h;
	this->GetClientSize(&w,&h);

	m_title = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    m_title->IsMaximinize=0;
    m_title->m_close_box=0;
    m_title->Name=_("");
    panelBG = new wxPanel(this, ID_PANEL2, wxPoint(0,31), wxSize(w,h-31), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelBG->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    StaticText1 = new wxStaticText(panelBG, wxID_ANY, wxEmptyString, wxPoint(10,32),wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	Text1 = new wxMyTextCtrl( panelBG, wxID_ANY, wxEmptyString, wxPoint(20,25), wxSize(w-35,30), wxTE_CENTRE );
	Text1->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Times New Roman") ) );

    StaticText2 = new wxStaticText(panelBG, wxID_ANY, wxEmptyString, wxPoint(10,67),wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	Text2 = new wxMyTextCtrl( panelBG, wxID_ANY, wxEmptyString, wxPoint(20,60), wxSize(w-35,30), wxTE_CENTRE );
	Text2->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Times New Roman") ) );

    StaticText3 = new wxStaticText(panelBG, wxID_ANY, wxEmptyString, wxPoint(10,102),wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	Text3 = new wxMyTextCtrl( panelBG, wxID_ANY, wxEmptyString, wxPoint(20,95), wxSize(w-35,30), wxTE_CENTRE );
	Text3->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Times New Roman") ) );

    StaticText4 = new wxStaticText(panelBG, wxID_ANY, wxEmptyString, wxPoint(10,137),wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	Text4 = new wxMyTextCtrl( panelBG, wxID_ANY, wxEmptyString, wxPoint(20,130), wxSize(w-35,30), wxTE_CENTRE );
	Text4->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Times New Roman") ) );

    StaticText1->SetBackgroundColour(wxColor(235,235,235));
    StaticText2->SetBackgroundColour(wxColor(235,235,235));
    StaticText3->SetBackgroundColour(wxColor(235,235,235));
    StaticText4->SetBackgroundColour(wxColor(235,235,235));
    StaticText1->Show(false);
    StaticText2->Show(false);
    StaticText3->Show(false);
    StaticText4->Show(false);
    Text1->Show(false);
    Text2->Show(false);
    Text3->Show(false);
    Text4->Show(false);

	m_btnOK = new wxButton( panelBG, wxID_OK, wxT("确定"), wxPoint(35,h-70), wxSize(80,32), 0 );

	m_btnCancel = new wxButton( panelBG, wxID_CANCEL, wxT("取消"), wxPoint(135,h-70), wxSize(80,32), 0 );

	this->Centre( wxBOTH );

    panelBG->Connect(wxEVT_PAINT,(wxObjectEventFunction)&EntryDlg::OnPaintBackGround,0,this);
	//m_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntryDlg::OnBtnModify ), NULL, this );
}

EntryDlg::~EntryDlg()
{
    m_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntryDlg::OnBtnModify ), NULL, this );
}

void EntryDlg::SetTitle(wxString title)
{
    m_title->Name=title;
}

void EntryDlg::InitialDlg(int type,wxString* values)
{
    switch(type)
    {
    case 0:
        this->SetClientSize(240,150);
        panelBG->SetSize(240,119);
        m_btnOK->SetPosition(wxPoint(35,80));
        m_btnCancel->SetPosition(wxPoint(135,80));
        m_title->Name=_("管环编号");
        Text1->Show(true);
        Text1->SetValue(values[0]);
        panelBG->Refresh();
        break;
    case 1:
        this->SetClientSize(240,150);
        panelBG->SetSize(240,119);
        m_btnOK->SetPosition(wxPoint(35,80));
        m_btnCancel->SetPosition(wxPoint(135,80));
        m_title->Name=_("管环里程");
        Text1->Show(true);
        Text1->SetValue(values[0]);
        panelBG->Refresh();
        break;
    case 2:
        this->SetClientSize(240,255);
        panelBG->SetSize(240,224);
        m_btnOK->SetPosition(wxPoint(35,185));
        m_btnCancel->SetPosition(wxPoint(135,185));
        m_title->Name=_("油缸行程");
        Text1->Show(true);
        Text2->Show(true);
        Text3->Show(true);
        Text4->Show(true);
        StaticText1->Show(true);
        StaticText2->Show(true);
        StaticText3->Show(true);
        StaticText4->Show(true);
        StaticText1->SetLabel(_("上组(mm)"));
        StaticText2->SetLabel(_("下组(mm)"));
        StaticText3->SetLabel(_("左组(mm)"));
        StaticText4->SetLabel(_("右组(mm)"));
        Text1->SetSize(70,25,155,30);
        Text2->SetSize(70,60,155,30);
        Text3->SetSize(70,95,155,30);
        Text4->SetSize(70,130,155,30);
        Text1->SetValue(values[0]);
        Text2->SetValue(values[1]);
        Text3->SetValue(values[2]);
        Text4->SetValue(values[3]);
        panelBG->Refresh();
        break;
    case 3:
        this->SetClientSize(240,255);
        panelBG->SetSize(240,224);
        m_btnOK->SetPosition(wxPoint(35,185));
        m_btnCancel->SetPosition(wxPoint(135,185));
        m_title->Name=_("盾尾间隙");
        Text1->Show(true);
        Text2->Show(true);
        Text3->Show(true);
        Text4->Show(true);
        StaticText1->Show(true);
        StaticText2->Show(true);
        StaticText3->Show(true);
        StaticText4->Show(true);
        StaticText1->SetLabel(_("上部(mm)"));
        StaticText2->SetLabel(_("下部(mm)"));
        StaticText3->SetLabel(_("左部(mm)"));
        StaticText4->SetLabel(_("右部(mm)"));
        Text1->SetSize(70,25,155,30);
        Text2->SetSize(70,60,155,30);
        Text3->SetSize(70,95,155,30);
        Text4->SetSize(70,130,155,30);
        Text1->SetValue(values[0]);
        Text2->SetValue(values[1]);
        Text3->SetValue(values[2]);
        Text4->SetValue(values[3]);
        panelBG->Refresh();
        break;
    case 4:
        this->SetClientSize(240,150);
        panelBG->SetSize(240,119);
        m_btnOK->SetPosition(wxPoint(35,80));
        m_btnCancel->SetPosition(wxPoint(135,80));
        m_title->Name=_("管环上浮");
        StaticText1->Show(true);
        StaticText1->SetLabel(_("管环上浮(mm)"));
        Text1->Show(true);
        Text1->SetSize(100,28,125,26);
        Text1->SetValue(values[0]);
        panelBG->Refresh();
        break;
    case 5:
        break;
    default:
        break;
    }
}

void EntryDlg::OnBtnModify( wxCommandEvent& event )
{
    long val;
    if(Text1->GetValue().ToLong(&val))
    {
        //mtg->segs[4].numb = val-1;
        //mtg->seg.numb = val;
        //mtg->segs[4].t=0;
        //mtg_store_seg(mtg);
        MTG_SEG_SERIAL snum0={0};
        mtg->snum = snum0;
        mtg->snum.state = 1;
        mtg->snum.No = val;
        mtg->segs[4].numb = val;
        mtg->m1.iseg = val;
        //mtg_store_snum(mtg);
        //if(mtg_store_snum(mtg)==1) wxMessageBox(_("环号设置成功!"));

    }
    Close();
}

void EntryDlg::OnPaintBackGround(wxPaintEvent& event)
{
    wxPaintDC dc(panelBG);
    int w,h;
    panelBG->GetClientSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
        memDC.SetBrush(wxBrush(wxColor(235,235,235)));
        memDC.SetPen(wxPen(wxColor(235,235,235)));
        memDC.DrawRectangle(0,0,w,h);
        wxFont chs(11,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("宋体"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);

        memDC.SetPen(wxPen(wxColor(172,168,153)));
        memDC.DrawLine(0,15,w,15);
        memDC.DrawLine(0,h-50,w,h-50);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(0,16,w,16);
        memDC.DrawLine(0,h-49,w,h-49);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}
