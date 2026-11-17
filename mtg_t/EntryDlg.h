///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __EntryDlg__
#define __EntryDlg__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>
#include "wxMyTextCtrl.h"
#include "MDTitle.h"
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class EntryDlg
///////////////////////////////////////////////////////////////////////////////
class EntryDlg : public wxDialog
{
	private:
        static const long ID_PANEL1;
        static const long ID_PANEL2;

        void OnPaintBackGround(wxPaintEvent& event);

	protected:
	    MDTitle* m_title;
		wxPanel* panelBG;
		wxButton* m_btnOK;
		wxButton* m_btnCancel;

		wxStaticText* StaticText1;              //
		wxStaticText* StaticText2;              //
		wxStaticText* StaticText3;              //
		wxStaticText* StaticText4;              //

	public:

		EntryDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 248,180 ), long style = wxBORDER_RAISED);
		void OnBtnModify( wxCommandEvent& event );
		~EntryDlg();

		wxMyTextCtrl* Text1;
		wxMyTextCtrl* Text2;
		wxMyTextCtrl* Text3;
		wxMyTextCtrl* Text4;

		void InitialDlg(int type,wxString* values);

		void SetTitle(wxString title);

};

#endif //__noname__
