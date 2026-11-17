///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __ModifySegDialog__
#define __ModifySegDialog__

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
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ModifySegDialog
///////////////////////////////////////////////////////////////////////////////
class ModifySegDialog : public wxDialog
{
	private:
        static const long ID_PANEL2;

        void OnPaintBackGround(wxPaintEvent& event);

	protected:
		wxPanel* panelBG;
		wxButton* m_btnModify;
		wxButton* m_btnCancel;

	public:

		ModifySegDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		void OnBtnModify( wxCommandEvent& event );
		~ModifySegDialog();

		wxMyTextCtrl* m_textSeg;

};

#endif //__noname__
