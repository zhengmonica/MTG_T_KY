///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "setupdlg.h"

///////////////////////////////////////////////////////////////////////////

SetupDlg::SetupDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer161;
	fgSizer161 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer161->SetFlexibleDirection( wxBOTH );
	fgSizer161->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText53 = new wxStaticText( this, wxID_ANY, wxT("换站"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	m_staticText53->SetFont( wxFont( 12, 70, 90, 92, false, wxEmptyString ) );

	fgSizer161->Add( m_staticText53, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticline212 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer161->Add( m_staticline212, 0, wxEXPAND | wxALL, 5 );

	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelSetup = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticline1 = new wxStaticLine( m_panelSetup, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline1->SetMinSize( wxSize( 550,-1 ) );

	fgSizer7->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	m_staticText6 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("测站"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	m_staticText6->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer7->Add( m_staticText6, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 2, 5, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("点名"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer8->Add( m_staticText1, 0, wxALL, 5 );

	m_staticText85 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("X"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	fgSizer8->Add( m_staticText85, 0, wxALL, 5 );

	m_staticText86 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText86->Wrap( -1 );
	fgSizer8->Add( m_staticText86, 0, wxALL, 5 );

	m_staticText87 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("Z     "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText87->Wrap( -1 );
	fgSizer8->Add( m_staticText87, 0, wxALL, 5 );

	m_staticText5 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("仪器高"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer8->Add( m_staticText5, 0, wxALL, 5 );

	wxArrayString m_statNameChoices;
	m_statName = new wxChoice( m_panelSetup, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_statNameChoices, 0 );
	m_statName->SetSelection( 0 );
	m_statName->SetMinSize( wxSize( 100,-1 ) );

	fgSizer8->Add( m_statName, 0, wxALL, 5 );

	m_statX = new wxMyTextCtrl( m_panelSetup, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_statX->Enable( false );

	fgSizer8->Add( m_statX, 0, wxALL, 5 );

	m_statY = new wxMyTextCtrl( m_panelSetup, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_statY->Enable( false );

	fgSizer8->Add( m_statY, 0, wxALL, 5 );

	m_statZ = new wxMyTextCtrl( m_panelSetup, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_statZ->Enable( false );

	fgSizer8->Add( m_statZ, 0, wxALL, 5 );

	m_statDev = new wxMyTextCtrl( m_panelSetup, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_statDev, 0, wxALL, 5 );

	fgSizer7->Add( fgSizer8, 1, wxEXPAND, 5 );

	m_staticline2 = new wxStaticLine( m_panelSetup, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer7->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	m_staticText7 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("后视 "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	m_staticText7->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer7->Add( m_staticText7, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 2, 5, 0, 0 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText8 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("点名"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer9->Add( m_staticText8, 0, wxALL, 5 );

	m_staticText88 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("X"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText88->Wrap( -1 );
	fgSizer9->Add( m_staticText88, 0, wxALL, 5 );

	m_staticText89 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText89->Wrap( -1 );
	fgSizer9->Add( m_staticText89, 0, wxALL, 5 );

	m_staticText90 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("Z     "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText90->Wrap( -1 );
	fgSizer9->Add( m_staticText90, 0, wxALL, 5 );

	m_staticText12 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("棱镜高"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	fgSizer9->Add( m_staticText12, 0, wxALL, 5 );

	wxArrayString m_backNameChoices;
	m_backName = new wxChoice( m_panelSetup, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_backNameChoices, 0 );
	m_backName->SetSelection( 0 );
	m_backName->SetMinSize( wxSize( 100,-1 ) );

	fgSizer9->Add( m_backName, 0, wxALL, 5 );

	m_backX = new wxMyTextCtrl( m_panelSetup, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_backX->Enable( false );

	fgSizer9->Add( m_backX, 0, wxALL, 5 );

	m_backY = new wxMyTextCtrl( m_panelSetup, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_backY->Enable( false );

	fgSizer9->Add( m_backY, 0, wxALL, 5 );

	m_backZ = new wxMyTextCtrl( m_panelSetup, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_backZ->Enable( false );

	fgSizer9->Add( m_backZ, 0, wxALL, 5 );

	m_backDev = new wxMyTextCtrl( m_panelSetup, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_backDev, 0, wxALL, 5 );

	fgSizer7->Add( fgSizer9, 1, wxEXPAND, 5 );

	m_staticline3 = new wxStaticLine( m_panelSetup, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer7->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );

	m_staticText14 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("测量结果"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	m_staticText14->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer7->Add( m_staticText14, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer10->SetFlexibleDirection( wxBOTH );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText15 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("平距差"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	fgSizer10->Add( m_staticText15, 0, wxALL, 5 );

	m_diffH = new wxStaticText( m_panelSetup, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_diffH->Wrap( -1 );
	m_diffH->SetMinSize( wxSize( 100,-1 ) );

	fgSizer10->Add( m_diffH, 0, wxALL, 5 );

	m_staticText19 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("高差"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	fgSizer10->Add( m_staticText19, 0, wxALL, 5 );

	m_diffV = new wxStaticText( m_panelSetup, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_diffV->Wrap( -1 );
	m_diffV->SetMinSize( wxSize( 100,-1 ) );

	fgSizer10->Add( m_diffV, 0, wxALL, 5 );

	fgSizer7->Add( fgSizer10, 1, wxEXPAND, 5 );

	m_staticline5 = new wxStaticLine( m_panelSetup, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer7->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );

	m_staticText191 = new wxStaticText( m_panelSetup, wxID_ANY, wxT("信息提示"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText191->Wrap( -1 );
	m_staticText191->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer7->Add( m_staticText191, 0, wxALL, 5 );

	m_staticMsg1 = new wxStaticText( m_panelSetup, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticMsg1->Wrap( -1 );
	m_staticMsg1->SetMinSize( wxSize( 400,20 ) );

	fgSizer7->Add( m_staticMsg1, 0, wxALL, 5 );

	m_staticline4 = new wxStaticLine( m_panelSetup, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer7->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );

	m_panelSetup->SetSizer( fgSizer7 );
	m_panelSetup->Layout();
	fgSizer7->Fit( m_panelSetup );
	m_notebook->AddPage( m_panelSetup, wxT("设站定向"), true );
	m_panel4 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer131;
	fgSizer131 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer131->SetFlexibleDirection( wxBOTH );
	fgSizer131->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticline20 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer131->Add( m_staticline20, 0, wxEXPAND | wxALL, 5 );

	m_staticText46 = new wxStaticText( m_panel4, wxID_ANY, wxT("里程计算棱镜位置"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	m_staticText46->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer131->Add( m_staticText46, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer141;
	fgSizer141 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer141->SetFlexibleDirection( wxBOTH );
	fgSizer141->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText48 = new wxStaticText( m_panel4, wxID_ANY, wxT("刀盘里程"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_staticText48->Wrap( -1 );
	fgSizer141->Add( m_staticText48, 0, wxALL, 5 );

	m_textHead = new wxMyTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer141->Add( m_textHead, 0, wxALL, 5 );


	fgSizer141->Add( 300, 0, 1, wxEXPAND, 5 );

	m_button9 = new wxButton( m_panel4, wxID_ANY, wxT("计算"), wxDefaultPosition, wxSize( -1,30 ), 0 );
	fgSizer141->Add( m_button9, 0, wxALL, 5 );

	fgSizer131->Add( fgSizer141, 1, wxEXPAND, 5 );

	m_staticline14 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer131->Add( m_staticline14, 0, wxEXPAND | wxALL, 5 );

	m_staticText461 = new wxStaticText( m_panel4, wxID_ANY, wxT("棱镜坐标"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText461->Wrap( -1 );
	m_staticText461->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer131->Add( m_staticText461, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer1411;
	fgSizer1411 = new wxFlexGridSizer( 2, 6, 0, 0 );
	fgSizer1411->SetFlexibleDirection( wxBOTH );
	fgSizer1411->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText481 = new wxStaticText( m_panel4, wxID_ANY, wxT("棱镜I"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_staticText481->Wrap( -1 );
	fgSizer1411->Add( m_staticText481, 0, wxALL, 5 );

	m_textX1 = new wxMyTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1411->Add( m_textX1, 0, wxALL, 5 );

	m_textY1 = new wxMyTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1411->Add( m_textY1, 0, wxALL, 5 );

	m_textZ1 = new wxMyTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1411->Add( m_textZ1, 0, wxALL, 5 );


	fgSizer1411->Add( 80, 0, 1, wxEXPAND, 5 );

	m_btnMeasure1 = new wxButton( m_panel4, wxID_ANY, wxT("测量"), wxDefaultPosition, wxSize( -1,30 ), 0 );
	fgSizer1411->Add( m_btnMeasure1, 0, wxALL, 5 );

	fgSizer131->Add( fgSizer1411, 1, wxEXPAND, 5 );


	fgSizer131->Add( 0, 100, 1, wxEXPAND, 5 );

	m_staticline151 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer131->Add( m_staticline151, 0, wxEXPAND | wxALL, 5 );

	m_staticText591 = new wxStaticText( m_panel4, wxID_ANY, wxT("信息提示"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText591->Wrap( -1 );
	m_staticText591->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer131->Add( m_staticText591, 0, wxALL, 5 );

	m_staticMsg2 = new wxStaticText( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticMsg2->Wrap( -1 );
	m_staticMsg2->SetMinSize( wxSize( 500,20 ) );

	fgSizer131->Add( m_staticMsg2, 0, wxALL, 5 );

	m_staticline19 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer131->Add( m_staticline19, 0, wxEXPAND | wxALL, 5 );

	m_panel4->SetSizer( fgSizer131 );
	m_panel4->Layout();
	fgSizer131->Fit( m_panel4 );
	m_notebook->AddPage( m_panel4, wxT("学习测量"), false );
	m_panelChange = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticline11 = new wxStaticLine( m_panelChange, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline11->SetMinSize( wxSize( 550,-1 ) );

	fgSizer13->Add( m_staticline11, 0, wxEXPAND | wxALL, 5 );

	m_staticText61 = new wxStaticText( m_panelChange, wxID_ANY, wxT("测量设置"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	m_staticText61->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer13->Add( m_staticText61, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer14;
	fgSizer14 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer14->SetFlexibleDirection( wxBOTH );
	fgSizer14->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText13 = new wxStaticText( m_panelChange, wxID_ANY, wxT("新吊篮编号"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	fgSizer14->Add( m_staticText13, 0, wxALL, 5 );

	/*m_staticText39 = new wxStaticText( m_panelChange, wxID_ANY, wxT("到测站距离"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText39->Wrap( -1 );
	fgSizer14->Add( m_staticText39, 0, wxALL, 5 );*/

	m_staticText21 = new wxStaticText( m_panelChange, wxID_ANY, wxT("测回数"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer14->Add( m_staticText21, 0, wxALL, 5 );

	m_staticText31 = new wxStaticText( m_panelChange, wxID_ANY, wxT("棱镜高"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer14->Add( m_staticText31, 0, wxALL, 5 );

	m_basketName = new wxMyTextCtrl( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer14->Add( m_basketName, 0, wxALL, 5 );

	/*m_basketDist = new wxMyTextCtrl( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer14->Add( m_basketDist, 0, wxALL, 5 );*/

	m_basketSet = new wxMyTextCtrl( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer14->Add( m_basketSet, 0, wxALL, 5 );

	m_basketDev = new wxMyTextCtrl( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer14->Add( m_basketDev, 0, wxALL, 5 );

	fgSizer13->Add( fgSizer14, 1, wxEXPAND, 5 );

	m_staticline21 = new wxStaticLine( m_panelChange, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer13->Add( m_staticline21, 0, wxEXPAND | wxALL, 5 );

	m_staticText71 = new wxStaticText( m_panelChange, wxID_ANY, wxT("新吊篮坐标"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	m_staticText71->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer13->Add( m_staticText71, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer15;
	fgSizer15 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer15->SetFlexibleDirection( wxBOTH );
	fgSizer15->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText81 = new wxStaticText( m_panelChange, wxID_ANY, wxT("点名"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	fgSizer15->Add( m_staticText81, 0, wxALL, 5 );

	m_staticText91 = new wxStaticText( m_panelChange, wxID_ANY, wxT("北坐标(X)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	fgSizer15->Add( m_staticText91, 0, wxALL, 5 );

	m_staticText101 = new wxStaticText( m_panelChange, wxID_ANY, wxT("东坐标(Y)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	fgSizer15->Add( m_staticText101, 0, wxALL, 5 );

	m_staticText111 = new wxStaticText( m_panelChange, wxID_ANY, wxT("高程(H)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	fgSizer15->Add( m_staticText111, 0, wxALL, 5 );

	m_basketName1 = new wxMyTextCtrl( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_basketName1->Enable( false );

	fgSizer15->Add( m_basketName1, 0, wxALL, 5 );

	m_basketX = new wxMyTextCtrl( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_basketX->Enable( false );

	fgSizer15->Add( m_basketX, 0, wxALL, 5 );

	m_basketY = new wxMyTextCtrl( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_basketY->Enable( false );

	fgSizer15->Add( m_basketY, 0, wxALL, 5 );

	m_basketZ = new wxMyTextCtrl( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_basketZ->Enable( false );

	fgSizer15->Add( m_basketZ, 0, wxALL, 5 );

	fgSizer13->Add( fgSizer15, 1, wxEXPAND, 5 );

	m_staticline31 = new wxStaticLine( m_panelChange, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer13->Add( m_staticline31, 0, wxEXPAND | wxALL, 5 );

	m_staticText141 = new wxStaticText( m_panelChange, wxID_ANY, wxT("测量结果"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	m_staticText141->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer13->Add( m_staticText141, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer16;
	fgSizer16 = new wxFlexGridSizer( 2, 6, 0, 0 );
	fgSizer16->SetFlexibleDirection( wxBOTH );
	fgSizer16->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText151 = new wxStaticText( m_panelChange, wxID_ANY, wxT("2C互差"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText151->Wrap( -1 );
	fgSizer16->Add( m_staticText151, 0, wxALL, 5 );

	m_diff2c = new wxStaticText( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_diff2c->Wrap( -1 );
	fgSizer16->Add( m_diff2c, 0, wxALL, 5 );

	m_staticText192 = new wxStaticText( m_panelChange, wxID_ANY, wxT("测回间测角互差"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText192->Wrap( -1 );
	fgSizer16->Add( m_staticText192, 0, wxALL, 5 );

	m_diff2a = new wxStaticText( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_diff2a->Wrap( -1 );
	fgSizer16->Add( m_diff2a, 0, wxALL, 5 );

	m_staticText58 = new wxStaticText( m_panelChange, wxID_ANY, wxT("测回间测距互差"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText58->Wrap( -1 );
	fgSizer16->Add( m_staticText58, 0, wxALL, 5 );

	m_diff2d = new wxStaticText( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_diff2d->Wrap( -1 );
	fgSizer16->Add( m_diff2d, 0, wxALL, 5 );

	fgSizer13->Add( fgSizer16, 1, wxEXPAND, 5 );

	m_staticline51 = new wxStaticLine( m_panelChange, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer13->Add( m_staticline51, 0, wxEXPAND | wxALL, 5 );

	m_staticText1911 = new wxStaticText( m_panelChange, wxID_ANY, wxT("信息提示"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1911->Wrap( -1 );
	m_staticText1911->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer13->Add( m_staticText1911, 0, wxALL, 5 );

	m_staticMsg3 = new wxStaticText( m_panelChange, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticMsg3->Wrap( -1 );
	m_staticMsg3->SetMinSize( wxSize( 400,20 ) );

	fgSizer13->Add( m_staticMsg3, 0, wxALL, 5 );

	m_staticline41 = new wxStaticLine( m_panelChange, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer13->Add( m_staticline41, 0, wxEXPAND | wxALL, 5 );

	m_panelChange->SetSizer( fgSizer13 );
	m_panelChange->Layout();
	fgSizer13->Fit( m_panelChange );
	m_notebook->AddPage( m_panelChange, wxT("换站测量"), false );
	m_panel3 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticline22 = new wxStaticLine( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline22->SetMinSize( wxSize( 550,-1 ) );

	fgSizer1->Add( m_staticline22, 0, wxEXPAND | wxALL, 5 );

	m_staticText84 = new wxStaticText( m_panel3, wxID_ANY, wxT("吊篮坐标表"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	m_staticText84->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer1->Add( m_staticText84, 0, wxALL, 5 );

	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_listBasket = new wxListView( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxRAISED_BORDER );
	m_listBasket->SetMinSize( wxSize( 460,200 ) );

	fgSizer12->Add( m_listBasket, 0, wxALL, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_button4 = new wxButton( m_panel3, wxID_ANY, wxT("增加"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button4->SetMinSize( wxSize( -1,32 ) );

	bSizer5->Add( m_button4, 0, wxALL, 5 );

	m_button5 = new wxButton( m_panel3, wxID_ANY, wxT("编辑"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button5->SetMinSize( wxSize( -1,32 ) );

	bSizer5->Add( m_button5, 0, wxALL, 5 );

	m_button6 = new wxButton( m_panel3, wxID_ANY, wxT("删除"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button6->SetMinSize( wxSize( -1,32 ) );

	bSizer5->Add( m_button6, 0, wxALL, 5 );

	fgSizer12->Add( bSizer5, 1, wxEXPAND, 5 );

	fgSizer1->Add( fgSizer12, 1, wxEXPAND, 5 );

	m_staticline23 = new wxStaticLine( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer1->Add( m_staticline23, 0, wxEXPAND | wxALL, 5 );

	m_staticText83 = new wxStaticText( m_panel3, wxID_ANY, wxT("信息提示"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	m_staticText83->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer1->Add( m_staticText83, 0, wxALL, 5 );

	m_staticMsg = new wxStaticText( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticMsg->Wrap( -1 );
	m_staticMsg->SetMinSize( wxSize( 400,20 ) );

	fgSizer1->Add( m_staticMsg, 0, wxALL, 5 );

	m_staticline211 = new wxStaticLine( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer1->Add( m_staticline211, 0, wxEXPAND | wxALL, 5 );

	m_panel3->SetSizer( fgSizer1 );
	m_panel3->Layout();
	fgSizer1->Fit( m_panel3 );
	m_notebook->AddPage( m_panel3, wxT("吊篮坐标"), true );

	fgSizer161->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );

	m_staticline201 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer161->Add( m_staticline201, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_btnMeasure = new wxButton( this, wxID_ANY, wxT("测量"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnMeasure->SetMinSize( wxSize( -1,32 ) );

	bSizer2->Add( m_btnMeasure, 0, wxALL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_btnSet = new wxButton( this, wxID_ANY, wxT("设置"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnSet->SetMinSize( wxSize( -1,32 ) );

	bSizer2->Add( m_btnSet, 0, wxALL, 5 );

	m_btnQuit = new wxButton( this, wxID_ANY, wxT("退出"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnQuit->SetMinSize( wxSize( -1,32 ) );

	bSizer2->Add( m_btnQuit, 0, wxALL, 5 );

	fgSizer161->Add( bSizer2, 1, wxEXPAND, 5 );

	mainSizer->Add( fgSizer161, 1, wxEXPAND, 5 );

	this->SetSizer( mainSizer );
	this->Layout();
	mainSizer->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_notebook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( SetupDlg::OnPageChanged ), NULL, this );
	m_notebook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, wxNotebookEventHandler( SetupDlg::OnPageChanging ), NULL, this );
	m_statName->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SetupDlg::OnSetStatname ), NULL, this );
	m_statDev->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SetupDlg::OnDevHeight ), NULL, this );
	m_backName->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SetupDlg::OnSetBackname ), NULL, this );
	m_backDev->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SetupDlg::OnPrismHeight ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnBtnCalc ), NULL, this );
	m_btnMeasure1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnBtnMeasure1 ), NULL, this );
	m_listBasket->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( SetupDlg::OnBasketSel ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnBtnAdd ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnBtnEdit ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnBtnDel ), NULL, this );
	m_btnMeasure->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnMeasure ), NULL, this );
	m_btnSet->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnSet ), NULL, this );
	m_btnQuit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnQuit ), NULL, this );
}

SetupDlg::~SetupDlg()
{
	// Disconnect Events
	m_notebook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( SetupDlg::OnPageChanged ), NULL, this );
	m_notebook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, wxNotebookEventHandler( SetupDlg::OnPageChanging ), NULL, this );
	m_statName->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SetupDlg::OnSetStatname ), NULL, this );
	m_statDev->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SetupDlg::OnDevHeight ), NULL, this );
	m_backName->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SetupDlg::OnSetBackname ), NULL, this );
	m_backDev->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SetupDlg::OnPrismHeight ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnBtnCalc ), NULL, this );
	m_btnMeasure1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnBtnMeasure1 ), NULL, this );
	m_listBasket->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( SetupDlg::OnBasketSel ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnBtnAdd ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnBtnEdit ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnBtnDel ), NULL, this );
	m_btnMeasure->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnMeasure ), NULL, this );
	m_btnSet->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnSet ), NULL, this );
	m_btnQuit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDlg::OnQuit ), NULL, this );

}

PointDlg::PointDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText52 = new wxStaticText( this, wxID_ANY, wxT("吊篮"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetFont( wxFont( 12, 70, 90, 92, false, wxEmptyString ) );

	fgSizer3->Add( m_staticText52, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticline18 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer3->Add( m_staticline18, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText40 = new wxStaticText( this, wxID_ANY, wxT("点名"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	fgSizer4->Add( m_staticText40, 0, wxALL, 5 );

	m_textName = new wxMyTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_textName, 0, wxALL, 5 );

	m_staticText41 = new wxStaticText( this, wxID_ANY, wxT("X"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	fgSizer4->Add( m_staticText41, 0, wxALL, 5 );

	m_textX = new wxMyTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_textX, 0, wxALL, 5 );

	m_staticText42 = new wxStaticText( this, wxID_ANY, wxT("Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	fgSizer4->Add( m_staticText42, 0, wxALL, 5 );

	m_textY = new wxMyTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_textY, 0, wxALL, 5 );

	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Z"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	fgSizer4->Add( m_staticText43, 0, wxALL, 5 );

	m_textZ = new wxMyTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_textZ, 0, wxALL, 5 );

	fgSizer3->Add( fgSizer4, 1, wxEXPAND, 5 );

	m_staticline19 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer3->Add( m_staticline19, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_button7 = new wxButton( this, wxID_OK, wxT("确定"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button7->SetMinSize( wxSize( -1,32 ) );

	bSizer6->Add( m_button7, 0, wxALL, 5 );

	m_button8 = new wxButton( this, wxID_CANCEL, wxT("取消"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button8->SetMinSize( wxSize( -1,32 ) );

	bSizer6->Add( m_button8, 0, wxALL, 5 );

	fgSizer3->Add( bSizer6, 1, wxEXPAND, 5 );

	this->SetSizer( fgSizer3 );
	this->Layout();
	fgSizer3->Fit( this );

	this->Centre( wxBOTH );
}

PointDlg::~PointDlg()
{
}
