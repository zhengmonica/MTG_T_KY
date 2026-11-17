#ifndef USERMANAGERDLG_H_INCLUDED
#define USERMANAGERDLG_H_INCLUD

#ifndef WX_PRECOMP
	//(*HeadersPCH(UserManagerDlg)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(UserManagerDlg)
#include <wx/statline.h>
//*)

#include "wxMyTextCtrl.h"

class UserManagerDlg: public wxDialog
{
	public:

		UserManagerDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~UserManagerDlg();

		//(*Declarations(H_StartPoint)
		wxMyTextCtrl* Y;
		wxStaticText* StaticText2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticLine* StaticLine2;
		wxStaticText* StaticText5;
		wxStaticLine* StaticLine1;
		wxMyTextCtrl* Password;
		wxMyTextCtrl* Name;
		wxStaticText* StaticText4;
		wxChoice* levelChoice;               //È¨ÏÞÑ¡Ôñ
		//wxMyTextCtrl* mile2;
		//wxStaticText* StaticText5;
		wxMyTextCtrl* tips;
		//*)

	protected:

		//(*Identifiers(UserManagerDlg)
		static const long ID_STATICTEXT5;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT1;
		//static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICLINE2;
		static const long ID_CHOICE1;
		//*)

	private:

		//(*Handlers(UserManagerDlg)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif // UserManagerDlg_H_INCLUDED
