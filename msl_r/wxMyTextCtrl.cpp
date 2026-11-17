// wxMyTextCtrl.cpp: implementation of the wxMyTextCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include <wx/settings.h>

#include "wxMyTextCtrl.h"
#include "KeyBoard.h"

#ifdef _WIN32_WCE
#include <Sipapi.h>
#endif

KeyBoard* wxMyTextCtrl::g_kb=0;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

wxMyTextCtrl::wxMyTextCtrl(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos , const wxSize& size, long style, const wxValidator& validator, const wxString& name):wxTextCtrl( parent, id, value, pos ,  size , style ,validator, name)
{
	this->Connect(wxEVT_LEFT_UP, wxMouseEventHandler( wxMyTextCtrl::OnLeftUp), NULL, this);
//	this->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( wxMyTextCtrl::OnKillFocus ), NULL, this );
	this->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( wxMyTextCtrl::OnSetFocus ), NULL, this );
	this->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( wxMyTextCtrl::OnTextEnter ), NULL, this );
}

wxMyTextCtrl::~wxMyTextCtrl()
{
	this->Disconnect(wxEVT_LEFT_UP);
//	this->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( wxMyTextCtrl::OnKillFocus ), NULL, this );
	this->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( wxMyTextCtrl::OnSetFocus ), NULL, this );
	this->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( wxMyTextCtrl::OnTextEnter ), NULL, this );
	//this->Disconnect( wxEVT_SET_FOCUS, wxCommandEventHandler( wxMyTextCtrl::Gotfocus ), NULL, this );
    if(g_kb && g_kb->m_pTextCtrl==this)
    {
        delete g_kb;
        g_kb=0;
    }
}


void wxMyTextCtrl::OnTextEnter(wxCommandEvent& event)
{
    #ifdef _WIN32_WCE
    SipShowIM(SIPF_OFF);
    #else
    if(g_kb)
    {
        delete g_kb;
        g_kb=0;
    }
    #endif
    event.Skip();
}

/*void wxMyTextCtrl::OnSetFocus(wxFocusEvent& event)
{
    this->SetSelection(-1,-1);
	event.Skip();
}*/

void wxMyTextCtrl::OnLeftUp(wxMouseEvent& event)
{
    int x=0,y=0;
    ClientToScreen(&x,&y);
	int w,h;
	GetClientSize(&w,&h);
	//wxMessageBox(wxString::Format(_("%d,%d,%d,%d"),x,y,w,h));
	ClientToScreen(&w,&h);
	int h1=wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);

	h1=h1-222;
	//wxMessageBox(wxString::Format(_("%d"),h1));
	//wxMessageBox(wxString::Format(_("%d,%d,%d,%d"),x,y,w,h));
    #ifdef _WIN32_WCE
    SIPINFO    si;
    si.dwImDataSize = 0;
    si.cbSize = sizeof(si);
    BOOL bSip = SipGetInfo(&si);
    if(y<=120)
    {
        si.rcSipRect.top = h+1;//half of the screen
    }
    else
    {
        si.rcSipRect.top = y-121;//half of the screen
    }
    SipSetInfo(&si);
    SipShowIM(SIPF_ON);
    #else
    if(this->IsEditable())
    {
        if(!g_kb)
        {
            g_kb=new KeyBoard(0,this);
        }
        if(h<h1)
        {
            g_kb->SetSize(x-48,h+2,-1,-1);
        }
        else
        {
            g_kb->SetSize(x-48,y-230,-1,-1);
        }
        g_kb->m_pTextCtrl=this;
        g_kb->Show();
        this->SetFocus();
    }

    #endif
    //this->SetSelection(-1,-1);
	event.Skip();
}

