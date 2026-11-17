#ifndef KEYAREADLG_H_INCLUDED
#define KEYAREADLG_H_INCLUDED

#ifndef WX_PRECOMP
	//(*HeadersPCH(KeyAreaDlg)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(KeyAreaDlg)
#include <wx/statline.h>
//*)

#include "wxMyTextCtrl.h"

class KeyAreaDlg: public wxDialog
{
	public:

		KeyAreaDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~KeyAreaDlg();

		//(*Declarations(H_StartPoint)
		wxMyTextCtrl* Y;
		wxStaticText* StaticText2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticLine* StaticLine2;
		wxStaticText* StaticText5;
		wxStaticLine* StaticLine1;
		wxMyTextCtrl* mile1;
		wxMyTextCtrl* name;
		wxStaticText* StaticText4;
		wxMyTextCtrl* mile2;
		//wxStaticText* StaticText5;
		wxMyTextCtrl* tips;
		//*)

	protected:

		//(*Identifiers(KeyAreaDlg)
		static const long ID_STATICTEXT5;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICLINE2;
		//*)

	private:

		//(*Handlers(KeyAreaDlg)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif // KEYAREADLG_H_INCLUDED
