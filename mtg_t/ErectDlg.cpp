///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////
#if 0
#include "MyCanvas.h"
#else
#include <wx/chartpanel.h>
#endif
#include "ErectDlg.h"

///////////////////////////////////////////////////////////////////////////

ErectDlg::ErectDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText21 = new wxStaticText( this, wxID_ANY, _("管环拼装"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	m_staticText21->SetFont( wxFont( 12, 70, 90, 92, false, wxEmptyString ) );

	fgSizer1->Add( m_staticText21, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("管环信息") ), wxVERTICAL );

	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText2 = new wxStaticText( this, wxID_ANY, _("环号"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer3->Add( m_staticText2, 0, wxALL, 5 );

	m_textSeg = new wxMyTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textSeg->SetMinSize( wxSize( 100,-1 ) );

	fgSizer3->Add( m_textSeg, 0, wxALL, 5 );

	sbSizer2->Add( fgSizer3, 1, wxEXPAND, 5 );

	fgSizer4->Add( sbSizer2, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("盾构姿态") ), wxVERTICAL );

    #if 0
	m_panelHorizon = new MyCanvas( this );
	#else
	m_panelHorizon = new wxChartPanel(this);
	#endif
	m_panelHorizon->SetMinSize( wxSize( 400,150 ) );

	sbSizer1->Add( m_panelHorizon, 1, wxEXPAND | wxALL, 1 );

    #if 0
	m_panelVertical = new MyCanvas( this);
	#else
	m_panelVertical = new wxChartPanel(this);
	#endif
	m_panelVertical->SetMinSize( wxSize( 400,150 ) );

	sbSizer1->Add( m_panelVertical, 1, wxEXPAND | wxALL, 1 );

	fgSizer4->Add( sbSizer1, 1, wxEXPAND, 5 );

	fgSizer1->Add( fgSizer4, 1, wxEXPAND, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer1->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	m_btnModify = new wxButton( this, wxID_ANY, _("修改环号"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnModify->SetMinSize( wxSize( -1,32 ) );

	bSizer3->Add( m_btnModify, 0, wxALL, 5 );

	m_btnErect = new wxButton( this, wxID_ANY, _("开始拼装"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnErect->SetMinSize( wxSize( -1,32 ) );

	bSizer3->Add( m_btnErect, 0, wxALL, 5 );

	m_btnCancel = new wxButton( this, wxID_CANCEL, _("取消"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnCancel->SetMinSize( wxSize( -1,32 ) );

	bSizer3->Add( m_btnCancel, 0, wxALL, 5 );

	fgSizer1->Add( bSizer3, 1, wxEXPAND, 5 );

	this->SetSizer( fgSizer1 );
	this->Layout();
	fgSizer1->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_btnModify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ErectDlg::OnBtnModify ), NULL, this );
	m_btnErect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ErectDlg::OnBtnErect ), NULL, this );
}

ErectDlg::~ErectDlg()
{
	// Disconnect Events
	m_btnModify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ErectDlg::OnBtnModify ), NULL, this );
	m_btnErect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ErectDlg::OnBtnErect ), NULL, this );

}
