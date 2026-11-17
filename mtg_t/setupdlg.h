///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __setupdlg__
#define __setupdlg__

class wxListView;

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/choice.h>
#include "wxMyTextCtrl.h"
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class SetupDlg
///////////////////////////////////////////////////////////////////////////////
class SetupDlg : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText53;
		wxStaticLine* m_staticline212;
		wxNotebook* m_notebook;
		wxPanel* m_panelSetup;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticText6;
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText85;
		wxStaticText* m_staticText86;
		wxStaticText* m_staticText87;
		wxStaticText* m_staticText5;
		wxChoice* m_statName;
		wxMyTextCtrl* m_statX;
		wxMyTextCtrl* m_statY;
		wxMyTextCtrl* m_statZ;
		wxMyTextCtrl* m_statDev;
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText88;
		wxStaticText* m_staticText89;
		wxStaticText* m_staticText90;
		wxStaticText* m_staticText12;
		wxChoice* m_backName;
		wxMyTextCtrl* m_backX;
		wxMyTextCtrl* m_backY;
		wxMyTextCtrl* m_backZ;
		wxMyTextCtrl* m_backDev;
		wxStaticLine* m_staticline3;
		wxStaticText* m_staticText14;
		wxStaticText* m_staticText15;
		wxStaticText* m_diffH;
		wxStaticText* m_staticText19;
		wxStaticText* m_diffV;
		wxStaticLine* m_staticline5;
		wxStaticText* m_staticText191;
		wxStaticText* m_staticMsg1;
		wxStaticLine* m_staticline4;
		wxPanel* m_panel4;
		wxStaticLine* m_staticline20;
		wxStaticText* m_staticText46;
		wxStaticText* m_staticText48;
		wxMyTextCtrl* m_textHead;

		wxButton* m_button9;
		wxStaticLine* m_staticline14;
		wxStaticText* m_staticText461;
		wxStaticText* m_staticText481;
		wxMyTextCtrl* m_textX1;
		wxMyTextCtrl* m_textY1;
		wxMyTextCtrl* m_textZ1;

		wxButton* m_btnMeasure1;

		wxStaticLine* m_staticline151;
		wxStaticText* m_staticText591;
		wxStaticText* m_staticMsg2;
		wxStaticLine* m_staticline19;
		wxPanel* m_panelChange;
		wxStaticLine* m_staticline11;
		wxStaticText* m_staticText61;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText39;
		wxStaticText* m_staticText21;
		wxStaticText* m_staticText31;
		wxMyTextCtrl* m_basketName;
		wxMyTextCtrl* m_basketDist;
		wxMyTextCtrl* m_basketSet;
		wxMyTextCtrl* m_basketDev;
		wxStaticLine* m_staticline21;
		wxStaticText* m_staticText71;
		wxStaticText* m_staticText81;
		wxStaticText* m_staticText91;
		wxStaticText* m_staticText101;
		wxStaticText* m_staticText111;
		wxMyTextCtrl* m_basketName1;
		wxMyTextCtrl* m_basketX;
		wxMyTextCtrl* m_basketY;
		wxMyTextCtrl* m_basketZ;
		wxStaticLine* m_staticline31;
		wxStaticText* m_staticText141;
		wxStaticText* m_staticText151;
		wxStaticText* m_diff2c;
		wxStaticText* m_staticText192;
		wxStaticText* m_diff2a;
		wxStaticText* m_staticText58;
		wxStaticText* m_diff2d;
		wxStaticLine* m_staticline51;
		wxStaticText* m_staticText1911;
		wxStaticText* m_staticMsg3;
		wxStaticLine* m_staticline41;
		wxPanel* m_panel3;
		wxStaticLine* m_staticline22;
		wxStaticText* m_staticText84;
		wxListView* m_listBasket;
		wxButton* m_button4;
		wxButton* m_button5;
		wxButton* m_button6;
		wxStaticLine* m_staticline23;
		wxStaticText* m_staticText83;
		wxStaticText* m_staticMsg;
		wxStaticLine* m_staticline211;
		wxStaticLine* m_staticline201;
		wxButton* m_btnMeasure;

		wxButton* m_btnSet;
		wxButton* m_btnQuit;

		// Virtual event handlers, overide them in your derived class
		virtual void OnPageChanged( wxNotebookEvent& event ) { event.Skip(); }
		virtual void OnPageChanging( wxNotebookEvent& event ) { event.Skip(); }
		virtual void OnSetStatname( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDevHeight( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSetBackname( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPrismHeight( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnCalc( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnMeasure1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBasketSel( wxListEvent& event ) { event.Skip(); }
		virtual void OnBtnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnDel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMeasure( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSet( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }


	public:

		SetupDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION );
		~SetupDlg();

};

///////////////////////////////////////////////////////////////////////////////
/// Class PointDlg
///////////////////////////////////////////////////////////////////////////////
class PointDlg : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText52;
		wxStaticLine* m_staticline18;
		wxStaticText* m_staticText40;
		wxStaticText* m_staticText41;
		wxStaticText* m_staticText42;
		wxStaticText* m_staticText43;
		wxStaticLine* m_staticline19;
		wxButton* m_button7;
		wxButton* m_button8;

	public:
		wxMyTextCtrl* m_textName;
		wxMyTextCtrl* m_textX;
		wxMyTextCtrl* m_textY;
		wxMyTextCtrl* m_textZ;

		PointDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~PointDlg();

};

#endif //__setupdlg__
