#ifndef SEGRECORDDIALOG_H
#define SEGRECORDDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(SegRecordDialog)
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/panel.h>
	#include <wx/choice.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(SegRecordDialog)
#include <wx/statline.h>
//*)

#include "wxMyTextCtrl.h"

class SegRecordDialog: public wxDialog
{
	public:

		SegRecordDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~SegRecordDialog();

		//(*Declarations(SegRecordDialog)
//		wxTextCtrl* location;
		wxPanel* panelBottom;
		wxStaticText* statictext2;
		wxStaticLine* StaticLine1;
		wxPanel* panelMain;
		wxStaticText* statictext3;
//		wxTextCtrl* segnum;
		wxStaticText* statictext1;
		wxChoice* segtype;
		//*)

		wxMyTextCtrl* location;
		wxMyTextCtrl* segnum;

	protected:

		//(*Identifiers(SegRecordDialog)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_CHOICE1;
		static const long ID_PANEL1;
		static const long ID_PANEL2;
		static const long ID_STATICLINE1;
		//*)

		enum
        {
            ID_PT_NONE,
            ID_PT_QUIT,
            ID_PT_OK,
            ID_PT_COUNT
        };

        wxRect ptButton[ID_PT_COUNT];
        int motion;

	private:

		//(*Handlers(SegRecordDialog)
		//*)

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);

		DECLARE_EVENT_TABLE()
};

#endif
