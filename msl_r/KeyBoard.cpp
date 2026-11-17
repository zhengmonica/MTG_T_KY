///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug 25 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "KeyBoard.h"
#include "wxMyTextCtrl.h"

///////////////////////////////////////////////////////////////////////////
void KeyBoard::InitGui()
{
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_btnUp = new wxButton( this, ID_BUTTON_UP, wxT("▲"), wxDefaultPosition, wxSize( 32,32 ), wxBU_AUTODRAW );
	bSizer4->Add( m_btnUp, 0, wxALL, 1 );

	m_staticArray[0] = new wxButton( this, ID_STATIC_0, wxT("数字"), wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer4->Add( m_staticArray[0], 0, wxALL, 1 );
	m_staticArray[0]->SetForegroundColour(*wxRED );

	m_staticArray[1] = new wxButton( this, ID_STATIC_1, wxT("字母"), wxDefaultPosition, wxSize( 30,20 ), 0 );

	bSizer4->Add( m_staticArray[1], 0, wxALL, 1 );

	m_staticArray[2] = new wxButton( this, ID_STATIC_2, wxT("符号"), wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer4->Add( m_staticArray[2], 0, wxALL, 1 );

	m_staticArray[3] = new wxButton( this, ID_STATIC_3, wxT(""), wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer4->Add( m_staticArray[3], 0, wxALL, 1 );
	m_staticArray[3]->Enable(false);

	m_staticArray[4] = new wxButton( this, ID_STATIC_4, wxT(""), wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer4->Add( m_staticArray[4], 0, wxALL, 1 );
	m_staticArray[4]->Enable(false);

	m_staticArray[5] = new wxButton( this, ID_STATIC_5, wxT(""), wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer4->Add( m_staticArray[5], 0, wxALL, 1 );
	m_staticArray[5]->Enable(false);

	m_btnDown = new wxButton( this, ID_BUTTON_DOWN, wxT("▼"), wxDefaultPosition, wxSize( 32,32 ), wxBU_AUTODRAW );
	bSizer4->Add( m_btnDown, 0, wxALL, 1 );

	fgSizer2->Add( bSizer4, 1, wxEXPAND, 0 );

	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 0, 0 );
	gbSizer1->SetFlexibleDirection( wxBOTH );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_btnArray[0] = new wxButton( this, ID_BUTTON_0, wxT("7"), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnArray[0], wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 1 );

	m_btnArray[1] = new wxButton( this, ID_BUTTON_1, wxT("8"), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnArray[1], wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 1 );

	m_btnArray[2] = new wxButton( this, ID_BUTTON_2, wxT("9"), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnArray[2], wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 1 );

	m_btnArray[3] = new wxButton( this, ID_BUTTON_3, wxT("+/-"), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnArray[3], wxGBPosition( 0, 3 ), wxGBSpan( 1, 1 ), wxALL, 1 );

	m_btnArray[4] = new wxButton( this, ID_BUTTON_4, wxT("4"), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnArray[4], wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 1 );

	m_btnArray[5] = new wxButton( this, ID_BUTTON_5, wxT("5"), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnArray[5], wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 1 );

	m_btnArray[6] = new wxButton( this, ID_BUTTON_6, wxT("6"), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnArray[6], wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 1 );

	m_btnBack = new wxButton( this, ID_BUTTON_BACK, wxT("<-"), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnBack, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALL, 1 );
	m_btnBack->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	m_btnArray[7] = new wxButton( this, ID_BUTTON_7, wxT("1"), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnArray[7], wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 1 );

	m_btnArray[8] = new wxButton( this, ID_BUTTON_8, wxT("2"), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnArray[8], wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 1 );

	m_btnArray[9] = new wxButton( this, ID_BUTTON_9, wxT("3"), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnArray[9], wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALL, 1 );

	m_btnArray[10] = new wxButton( this, ID_BUTTON_10, wxT("0"), wxDefaultPosition, wxSize( 98,48 ), 0 );
	gbSizer1->Add( m_btnArray[10], wxGBPosition( 3, 0 ), wxGBSpan( 1, 2 ), wxALL, 1 );

	m_btnArray[11] = new wxButton( this, ID_BUTTON_11, wxT("."), wxDefaultPosition, wxSize( 48,48 ), 0 );
	gbSizer1->Add( m_btnArray[11], wxGBPosition( 3, 2 ), wxGBSpan( 1, 1 ), wxALL, 1 );

	m_btnEnter = new wxButton( this, ID_BUTTON_ENTER, wxT("←┘"), wxDefaultPosition, wxSize( 48,98 ), 0 );
	gbSizer1->Add( m_btnEnter, wxGBPosition( 2, 3 ), wxGBSpan( 2, 1 ), wxALL, 1 );
	m_btnEnter->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	fgSizer2->Add( gbSizer1, 1, wxEXPAND, 0 );

	bSizer3->Add( fgSizer2, 1, wxEXPAND, 5 );

	///����
	for(int i=0;i<12;i++) m_btnArray[i]->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );

	this->SetSizer( bSizer3 );
	bSizer3->Fit( this );
	this->Layout();

	// Connect Events
	m_btnUp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyBoard::OnBtnUp ), NULL, this );
	m_btnDown->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyBoard::OnBtnDown ), NULL, this );
	m_btnBack->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyBoard::OnBtnBack ), NULL, this );
	m_btnEnter->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyBoard::OnBtnEnter ), NULL, this );
	this->Connect(ID_BUTTON_0,ID_BUTTON_11,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler( KeyBoard::OnBtnClick ),NULL,this);
    this->Connect(ID_STATIC_0,ID_STATIC_5,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler( KeyBoard::OnBtnClick1 ),NULL,this);
}



KeyBoard::KeyBoard( wxWindow* parent, wxTextCtrl* ctrl )
{
    Create( parent,-1,_("键盘") ,wxDefaultPosition,wxDefaultSize,wxCAPTION|wxSTAY_ON_TOP );
	InitGui();

	m_pTextCtrl=ctrl;
	m_nCurType=0;
	m_bExpand=false;
	m_bCapslock=false;
}

KeyBoard::~KeyBoard()
{
	// Disconnect Events
	m_btnUp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyBoard::OnBtnUp ), NULL, this );
	m_btnDown->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyBoard::OnBtnDown ), NULL, this );
	m_btnBack->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyBoard::OnBtnBack ), NULL, this );
	m_btnEnter->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( KeyBoard::OnBtnEnter ), NULL, this );
	this->Disconnect(ID_BUTTON_0,ID_BUTTON_11,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler( KeyBoard::OnBtnClick ),NULL,this);
    this->Disconnect(ID_STATIC_0,ID_STATIC_5,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler( KeyBoard::OnBtnClick1 ),NULL,this);
}

void KeyBoard::OnTextEnter( wxCommandEvent& event )
{
    if(m_pTextCtrl)
    {
        m_pTextCtrl->SetValue(m_pTextCtrl->GetValue());
        m_pTextCtrl->SetInsertionPoint(m_pTextCtrl->GetInsertionPoint());
    }
    //Show(false);
    Destroy();
    wxMyTextCtrl::g_kb=0;
}

void KeyBoard::OnBtnDown(wxCommandEvent& event)
{
	m_pTextCtrl->SetFocus();
	m_nCurType++;
	if(m_nCurType>=3) m_nCurType-=3;
	SetCurType(m_nCurType);
}

void KeyBoard::OnBtnUp(wxCommandEvent& event)
{
	m_pTextCtrl->SetFocus();
	m_nCurType--;
	if(m_nCurType<0) m_nCurType+=3;
	SetCurType(m_nCurType);
}


void KeyBoard::OnBtnBack(wxCommandEvent& event)
{
	if(m_bExpand)
	{
		m_bExpand=false;
		SetCurType(m_nCurType);
	}
	else
	{
		long from,to;
		m_pTextCtrl->GetSelection(&from,&to);
		if(to>from)
		{
			m_pTextCtrl->Remove(from,to);
		}
		else
		{
			long pos=m_pTextCtrl->GetInsertionPoint() ;
			if(pos>0) m_pTextCtrl->Remove(pos-1,pos);
		}
	}
	m_pTextCtrl->SetFocus();
}


void KeyBoard::OnBtnEnter(wxCommandEvent& event)
{
	if(m_pTextCtrl)
	{
		m_pTextCtrl->SetValue(m_pTextCtrl->GetValue());
		m_pTextCtrl->SetInsertionPoint(m_pTextCtrl->GetInsertionPoint());
	}
    //Show(false);
    Destroy();
    wxMyTextCtrl::g_kb=0;
	//wxCommandEvent e(wxUSER_DEFINED_COMPLETE);
    //wxPostEvent(m_pTextCtrl,e);
}

void KeyBoard::OnBtnClick1(wxCommandEvent& event)
{
    event.Skip(true);
    m_nCurType=event.GetId()-ID_STATIC_0;
    m_pTextCtrl->SetFocus();
	SetCurType(m_nCurType);
}

void KeyBoard::OnBtnClick(wxCommandEvent& event)
{
	m_pTextCtrl->SetFocus();
	int index=event.GetId()-ID_BUTTON_0;
	wxString strKey=m_btnArray[index]->GetLabel();
	if(strKey.IsEmpty()) return;
	///������
	if(strKey.Cmp(wxT("+/-"))==0)
	{
		wxString strValue=m_pTextCtrl->GetValue();
		if(!strValue.IsEmpty())
		{
			if(strValue[0]=='-')
			{
				strValue.Remove(0,1);
			}
			else
			{
				strValue.Prepend(wxT("-"));
			}
			m_pTextCtrl->SetValue(strValue);
		}
		return;
	}
	///��ĸ��Сд
	if(strKey.Cmp(wxT("↑"))==0)
	{
        m_bCapslock=true;
        SetCurType(KEY_TYPE_ALPABET);
        return;
	}
	if(strKey.Cmp(wxT("↓"))==0)
	{
	    m_bCapslock=false;
	    SetCurType(KEY_TYPE_ALPABET);
        return;
	}
	///�ո�
	if(strKey.Cmp(wxT("└┘"))==0)
	{
		strKey=wxT(" ");
	}

	int len=strKey.Length();
	if(len==1)
	{
		m_pTextCtrl->WriteText(strKey);
		if(m_bExpand)
		{
			SetCurType(m_nCurType);
			m_bExpand=false;
		}
	}
	else
	{
		m_bExpand=true;
		int start=0;
		if(index<=3)
		{
			start=0;
		}
		else if(index<=6)
		{
			start=4;
		}
		else if(index<=9)
		{
			start=7;
		}
		else
		{
			start=10;
		}
		for(int i=start;i<start+len && i<12;i++)
		{
			m_btnArray[i]->SetLabel(strKey.Mid(i-start,1));
		}
	}
	//m_pTextCtrl->SetValue(wxString::Format(wxT("%d"),id));
}


///���õ�ǰ��������
void KeyBoard::SetCurType(int type)
{
    m_nCurType=type;
	switch(type)
	{
	case KEY_TYPE_NUMBER:
		{
			m_btnArray[0]->SetLabel(wxT("7"));
			m_btnArray[1]->SetLabel(wxT("8"));
			m_btnArray[2]->SetLabel(wxT("9"));
			m_btnArray[3]->SetLabel(wxT("+/-"));
			m_btnArray[4]->SetLabel(wxT("4"));
			m_btnArray[5]->SetLabel(wxT("5"));
			m_btnArray[6]->SetLabel(wxT("6"));
			m_btnArray[7]->SetLabel(wxT("1"));
			m_btnArray[8]->SetLabel(wxT("2"));
			m_btnArray[9]->SetLabel(wxT("3"));
			m_btnArray[10]->SetLabel(wxT("0"));
			m_btnArray[11]->SetLabel(wxT("."));
			break;
		}
	case KEY_TYPE_ALPABET:
		{
		    if(m_bCapslock)
		    {
		        m_btnArray[0]->SetLabel(wxT("QWE"));
                m_btnArray[1]->SetLabel(wxT("RTY"));
                m_btnArray[2]->SetLabel(wxT("UIOP"));
                m_btnArray[3]->SetLabel(wxT("._-@"));
                m_btnArray[4]->SetLabel(wxT("ASD"));
                m_btnArray[5]->SetLabel(wxT("FGH"));
                m_btnArray[6]->SetLabel(wxT("JKL"));
                m_btnArray[7]->SetLabel(wxT("ZX"));
                m_btnArray[8]->SetLabel(wxT("CV"));
                m_btnArray[9]->SetLabel(wxT("BNM"));
                m_btnArray[10]->SetLabel(wxT("└┘"));
                m_btnArray[11]->SetLabel(wxT("↓"));
		    }
		    else
		    {
		        m_btnArray[0]->SetLabel(wxT("qwe"));
                m_btnArray[1]->SetLabel(wxT("rty"));
                m_btnArray[2]->SetLabel(wxT("uiop"));
                m_btnArray[3]->SetLabel(wxT("._-@"));
                m_btnArray[4]->SetLabel(wxT("asd"));
                m_btnArray[5]->SetLabel(wxT("fgh"));
                m_btnArray[6]->SetLabel(wxT("jkl"));
                m_btnArray[7]->SetLabel(wxT("zx"));
                m_btnArray[8]->SetLabel(wxT("cv"));
                m_btnArray[9]->SetLabel(wxT("bnm"));
                m_btnArray[10]->SetLabel(wxT("└┘"));
                m_btnArray[11]->SetLabel(wxT("↑"));
		    }
			break;
		}
	case KEY_TYPE_SYMBOL:
		{
			m_btnArray[0]->SetLabel(wxT("+"));
			m_btnArray[1]->SetLabel(wxT("-"));
			m_btnArray[2]->SetLabel(wxT("*"));
			m_btnArray[3]->SetLabel(wxT("/"));
			m_btnArray[4]->SetLabel(wxT("°"));
			m_btnArray[5]->SetLabel(wxT("′"));
			m_btnArray[6]->SetLabel(wxT("″"));
			m_btnArray[7]->SetLabel(wxT(","));
			m_btnArray[8]->SetLabel(wxT("."));
			m_btnArray[9]->SetLabel(wxT(";"));
			m_btnArray[10]->SetLabel(wxT("?"));
			m_btnArray[11]->SetLabel(wxT("!"));
			break;
		}
	case KEY_TYPE_FACE:
		{
			m_btnArray[0]->SetLabel(wxT(""));
			m_btnArray[1]->SetLabel(wxT(""));
			m_btnArray[2]->SetLabel(wxT(""));
			m_btnArray[3]->SetLabel(wxT(""));
			m_btnArray[4]->SetLabel(wxT(""));
			m_btnArray[5]->SetLabel(wxT(""));
			m_btnArray[6]->SetLabel(wxT(""));
			m_btnArray[7]->SetLabel(wxT(""));
			m_btnArray[8]->SetLabel(wxT(""));
			m_btnArray[9]->SetLabel(wxT(""));
			m_btnArray[10]->SetLabel(wxT(""));
			m_btnArray[11]->SetLabel(wxT(""));
			break;
		}
	case KEY_TYPE_GREECE:
		{
			m_btnArray[0]->SetLabel(wxT(""));
			m_btnArray[1]->SetLabel(wxT(""));
			m_btnArray[2]->SetLabel(wxT(""));
			m_btnArray[3]->SetLabel(wxT(""));
			m_btnArray[4]->SetLabel(wxT(""));
			m_btnArray[5]->SetLabel(wxT(""));
			m_btnArray[6]->SetLabel(wxT(""));
			m_btnArray[7]->SetLabel(wxT(""));
			m_btnArray[8]->SetLabel(wxT(""));
			m_btnArray[9]->SetLabel(wxT(""));
			m_btnArray[10]->SetLabel(wxT(""));
			m_btnArray[11]->SetLabel(wxT(""));
			break;
		}
	case KEY_TYPE_SPECIAL:
		{
			m_btnArray[0]->SetLabel(wxT(""));
			m_btnArray[1]->SetLabel(wxT(""));
			m_btnArray[2]->SetLabel(wxT(""));
			m_btnArray[3]->SetLabel(wxT(""));
			m_btnArray[4]->SetLabel(wxT(""));
			m_btnArray[5]->SetLabel(wxT(""));
			m_btnArray[6]->SetLabel(wxT(""));
			m_btnArray[7]->SetLabel(wxT(""));
			m_btnArray[8]->SetLabel(wxT(""));
			m_btnArray[9]->SetLabel(wxT(""));
			m_btnArray[10]->SetLabel(wxT(""));
			m_btnArray[11]->SetLabel(wxT(""));
			break;
		}
	}
	for(int i=0;i<6;i++)
	{
		if(i==type)
		{
			m_staticArray[type]->SetForegroundColour(*wxRED);
		}
		else
		{
			m_staticArray[i]->SetForegroundColour( * wxBLACK );
		}
		m_staticArray[i]->Refresh();
	}
}
