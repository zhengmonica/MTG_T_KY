#ifndef DATADLG_H
#define DATADLG_H

#include "ReviewDlg.h"
#ifndef WX_PRECOMP
	//(*HeadersPCH(DataDlg)
	#include <wx/listctrl.h>
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(DataDlg)
#include <wx/statline.h>
//*)
#include <wx/listctrl.h>

class DataDlg: public wxDialog
{
	public:

		DataDlg(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~DataDlg();
		//(*Declarations(DataDlg)
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticLine* StaticLine2;
		wxListView* DataList;
		wxStaticLine* StaticLine1;
		//*)

	protected:

		//(*Identifiers(DataDlg)
		static const long ID_STATICTEXT1;
		static const long ID_STATICLINE1;
		static const long ID_LISTVIEW1;
		static const long ID_STATICLINE2;
		//*)

	private:

		//(*Handlers(DataDlg)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
