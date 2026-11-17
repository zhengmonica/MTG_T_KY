///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ModifySegDialog.h"
#include "mtg_t_cliApp.h"
//#include "ConfirmDlg.h"
///////////////////////////////////////////////////////////////////////////
const long ModifySegDialog::ID_PANEL1 = wxNewId();
const long ModifySegDialog::ID_PANEL2 = wxNewId();

ModifySegDialog::ModifySegDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_RAISED, _T("wxID_ANY"));
	SetClientSize(wxSize(240,180));
	int w=240;
	int h=180;

	m_title = new MDTitle(this, ID_PANEL1, wxPoint(0,0), wxSize(w,31), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    m_title->IsMaximinize=0;
    m_title->m_close_box=0;
    m_title->Name=_("修改环号");
    panelBG = new wxPanel(this, ID_PANEL2, wxPoint(0,31), wxSize(w,h-31), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelBG->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

	m_textSeg = new wxMyTextCtrl( panelBG, wxID_ANY, wxEmptyString, wxPoint(15,25), wxSize(w-30,30), wxTE_CENTRE );
	m_textSeg->SetFont( wxFont( 20, 70, 90, 92, false, wxT("Times New Roman") ) );
	m_textSeg->SetValue(wxString::Format(_("%d"),mtg->m1.iseg));

	m_btnModify = new wxButton( panelBG, wxID_ANY, wxT("修  改"), wxPoint(35,h-70), wxSize(80,32), 0 );

	m_btnCancel = new wxButton( panelBG, wxID_CANCEL, wxT("取  消"), wxPoint(135,h-70), wxSize(80,32), 0 );

	this->Centre( wxBOTH );

    panelBG->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ModifySegDialog::OnPaintBackGround,0,this);
	m_btnModify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ModifySegDialog::OnBtnModify ), NULL, this );
}

ModifySegDialog::~ModifySegDialog()
{
    m_btnModify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ModifySegDialog::OnBtnModify ), NULL, this );
}

void ModifySegDialog::OnBtnModify( wxCommandEvent& event )
{
    long val;
    if(m_textSeg->GetValue().ToLong(&val))
    {
        MTG_SEG_SERIAL snum={0};
        mtg->snum = snum;
        mtg->snum.iseg = val;
        mtg->segs[4].numb = val;
        mtg->m1.iseg = val;
        mtg_store_snum(mtg);
    }
    Close();
}

void ModifySegDialog::OnPaintBackGround(wxPaintEvent& event)
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

        memDC.SetPen(wxPen(wxColor(104,104,104)));
        memDC.DrawLine(0,15,w,15);
        memDC.DrawLabel(_("注:请在该环开始掘进时修改！"),wxRect(15,60,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(0,h-50,w,h-50);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}
