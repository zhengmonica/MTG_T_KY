#ifndef BLOCKDLG_H_INCLUDED
#define BLOCKDLG_H_INCLUDED


#ifndef WX_PRECOMP
	//(*HeadersPCH(BlockDlg)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(BlockDlg)
#include <wx/statline.h>
//*)

#include "wxMyTextCtrl.h"

class BlockDlg: public wxDialog
{
	public:

		BlockDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~BlockDlg();

		//(*Declarations(H_StartPoint)
		wxMyTextCtrl* Y;
		wxStaticText* StaticText2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticLine* StaticLine2;
		wxStaticText* StaticText5;
		wxStaticLine* StaticLine1;
		wxMyTextCtrl* blockAngle;
		wxMyTextCtrl* blockName;
		wxStaticText* StaticText4;
		wxMyTextCtrl* X;
		//*)

	protected:

		//(*Identifiers(BlockDlg)
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

		//(*Handlers(BlockDlg)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
