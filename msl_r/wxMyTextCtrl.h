// wxMyTextCtrl.h: interface for the wxMyTextCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(__WXMYTEXTCTRL_H__)
#define __WXMYTEXTCTRL_H__

#include <wx/textctrl.h>
#include "KeyBoard.h"

class wxMyTextCtrl  :public wxTextCtrl
{
public:
	wxMyTextCtrl(wxWindow* parent, wxWindowID id, const wxString& value = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxTextCtrlNameStr);
	virtual ~wxMyTextCtrl();

	virtual void OnLeftUp(wxMouseEvent& event);
//	virtual void OnKillFocus( wxFocusEvent& event );
    //virtual void OnSetFocus( wxFocusEvent& event );
    virtual void OnTextEnter( wxCommandEvent& event ) ;

    //virtual void Gotfocus( wxCommandEvent& event ) ;
    static KeyBoard* g_kb;
};

#endif // !defined(__WXMYTEXTCTRL_H__)
