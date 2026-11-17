#ifndef RECORDQUERYDLG_H
#define RECORDQUERYDLG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(RecordQueryDlg)
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/panel.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(RecordQueryDlg)
//*)
#include "wxMyTextCtrl.h"
#include <wx/listctrl.h>
#include "libmtg.h"

class RecordQueryDlg: public wxDialog
{
	public:

		RecordQueryDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~RecordQueryDlg();

		//(*Declarations(RecordQueryDlg)
		wxPanel* PanelTop;
		wxStaticText* StaticText2;
		wxStaticText* StaticText1;
		wxPanel* PanelMain;
//		wxTextCtrl* TextCtrl2;
//		wxTextCtrl* TextCtrl1;
		wxPanel* PanelBody;
		//*)
		wxMyTextCtrl* TextCtrl2;
		wxMyTextCtrl* TextCtrl1;

		int nres;
		SEG_RECORD* res;

	protected:

		//(*Identifiers(RecordQueryDlg)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_PANEL2;
		static const long ID_PANEL3;
		static const long ID_PANEL1;
		//*)

		enum
        {
            ID_PT_NONE,
            ID_PT_QRY,
            ID_PT_OUTPUT,
            ID_PT_COUNT
        };

        wxRect ptButton[ID_PT_COUNT];
        int motion;

	private:

		//(*Handlers(RecordQueryDlg)
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnPaintQueryList(wxPaintEvent& event);
		//*)

		void OnPaintTop(wxPaintEvent& event);
        void OnMotionTop(wxMouseEvent& event);
        void OnLeaveTop(wxMouseEvent& event);
        void OnClickTop(wxMouseEvent& event);
        void UpdateQueryList();

        wxListView* QueryList;




		DECLARE_EVENT_TABLE()
};

#endif
