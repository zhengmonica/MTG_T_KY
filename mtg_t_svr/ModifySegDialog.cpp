///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ModifySegDialog.h"
#include "mtg_t_svrApp.h"
//#include "ConfirmDlg.h"
///////////////////////////////////////////////////////////////////////////
const long ModifySegDialog::ID_PANEL2 = wxNewId();

ModifySegDialog::ModifySegDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	Create(parent, wxID_ANY, _("环号设置"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(240,154));
	int w=240;
	int h=149;

    panelBG = new wxPanel(this, ID_PANEL2, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    panelBG->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

	m_textSeg = new wxMyTextCtrl( panelBG, wxID_ANY, wxEmptyString, wxPoint(15,30), wxSize(w-30,30), wxTE_CENTRE );
	m_textSeg->SetFont( wxFont( 16, 70, 90, 92, false, wxT("Times New Roman") ) );
	m_textSeg->SetValue(wxString::Format(_("%d"),mtg->m1.iseg));

	m_btnModify = new wxButton( panelBG, wxID_ANY, wxT("修  改"), wxPoint(35,h-39), wxSize(80,32), 0 );

	m_btnCancel = new wxButton( panelBG, wxID_CANCEL, wxT("取  消"), wxPoint(135,h-39), wxSize(80,32), 0 );

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
    FILE *fp=fopen("D:\\midu\\mainchangseg.log","w");
    if(m_textSeg->GetValue().ToLong(&val))
    {
        mtg->snum.iseg=val;
        mtg->snum.mile=mtg->m1.headc;
        mtg->snum.tm=0.0;
        mtg->m1.iseg=mtg->snum.iseg;
        mtg_store_snum(mtg);
        SegStart=SegDoing=SegEnd=0;    ///20200602ws add
        if(fp)
        {
            fprintf(fp,"iseg=%d,%d\n",mtg->snum.iseg,mtg->m1.iseg);fflush(fp);
            fprintf(fp,"mile=%d\n",mtg->snum.mile);fflush(fp);
        }
    }
    if(fp)
    {
        fprintf(fp,"\n");
        fflush(fp);
        fclose(fp);
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
        memDC.SetTextForeground(wxColor(255,0,0));
        memDC.DrawLabel(_("注:请在该环开始掘进时修改！"),wxRect(15,65,0,25),wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
        memDC.DrawLine(0,h-50,w,h-50);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}
