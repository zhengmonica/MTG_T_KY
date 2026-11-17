#ifndef POINTDIALOG_H
#define POINTDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(PointDialog)
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(PointDialog)
//*)
#include <wx/gdicmn.h>
#include <wx/statline.h>
#include "MDTitle.h"
#include "wxMyTextCtrl.h"

class PointDialog: public wxDialog
{
	public:

		//PointDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		PointDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,275 ), long style = wxBORDER_RAISED);
		~PointDialog();
		int flag;///0:Æðµã£¬1:ÖÕµã
		int ok;
		double x0,y0,x,y;
		void Init();

		enum
		{
		    ID_PT_NONE,
		    ID_PT_SAVE,
		    ID_PT_EXIT,
		    ID_PT_COUNT
		};
		wxRect rect[ID_PT_COUNT];

	protected:
		//(*Identifiers(PointDialog)
        //static const long ID_StaticBox1;
		//static const long ID_StaticBox2;
		static const long ID_StaticText1;
		static const long ID_StaticText2;
		static const long ID_StaticText3;
		static const long ID_StaticText4;
		static const long ID_TextCtrl1;
		static const long ID_TextCtrl2;
		static const long ID_TextCtrl3;
		static const long ID_TextCtrl4;
		static const long ID_Button1;
		static const long ID_Button2;
		static const long ID_PANEL1;
		//*)

		int motion;
        int level;

	private:

		//(*Handlers(PointDialog)
        //wxStaticBox* StaticBox1;
		//wxStaticBox* StaticBox2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxMyTextCtrl* TextCtrl1;
		wxMyTextCtrl* TextCtrl2;
		wxMyTextCtrl* TextCtrl3;
		wxMyTextCtrl* TextCtrl4;
		//wxButton* BtnSave;
		//wxButton* BtnClose;
		wxPanel* panel;
		//*)
		wxPanel* panel1;
		wxStaticLine* StaticLine1;
		wxStaticLine* StaticLine2;
		MDTitle* panelTitle;
		//wxStaticLine* pointStaticLine1;
		//wxStaticLine* pointStaticLine2;

		//(*Declarations(PointDialog)
        void OnBtnSave(wxCommandEvent& event);
		void OnBtnExit(wxCommandEvent& event);
		void OnPaintPanel(wxPaintEvent& event);
		void OnMotionPanel(wxMouseEvent& event);
        void OnLeavePanel(wxMouseEvent& event);
        void OnClickPanel(wxMouseEvent& event);
		//*)


		DECLARE_EVENT_TABLE()
};

#endif
