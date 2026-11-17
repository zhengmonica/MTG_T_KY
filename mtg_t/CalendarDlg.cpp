///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "CalendarDlg.h"

///////////////////////////////////////////////////////////////////////////

CalendarDlg::CalendarDlg( wxWindow* parent, wxWindowID id, const wxString& title,
                         const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("日期"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( 12, 70, 90, 92, false, wxEmptyString ) );

	fgSizer1->Add( m_staticText1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	m_calendar = new wxCalendarCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_SHOW_HOLIDAYS );
	m_calendar->SetFont( wxFont( 16, 74, 90, 92, false, wxT("Sans") ) );

	fgSizer1->Add( m_calendar, 0, wxALL, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer1->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button1 = new wxButton( this, wxID_OK, wxT("确定"), wxDefaultPosition, wxSize( -1,30 ), 0 );
	bSizer2->Add( m_button1, 0, wxALL, 5 );

	m_button2 = new wxButton( this, wxID_CANCEL, wxT("取消"), wxDefaultPosition, wxSize( -1,30 ), 0 );
	bSizer2->Add( m_button2, 0, wxALL, 5 );

	fgSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	this->SetSizer( fgSizer1 );
	this->Layout();
	fgSizer1->Fit( this );
}

CalendarDlg::~CalendarDlg()
{
}
