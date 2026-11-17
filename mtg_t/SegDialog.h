#ifndef SEGDIALOG_H
#define SEGDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(SegDialog)
    #include <wx/panel.h>
	#include <wx/stattext.h>
	#include "wxMyTextCtrl.h"
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(SegDialog)
#include <wx/statline.h>
//*)

#include "wxMyTextCtrl.h"
#include "mtg_tApp.h"

class SegDialog: public wxDialog
{
	public:

		SegDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~SegDialog();

        void PaintSeg(wxMemoryDC* dc,wxRect rect,int step,double roll);

        int type;
		//(*Declarations(SegDialog)
        wxPanel* panelMain;                     //panel1
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxStaticLine* StaticLine2;
		wxMyTextCtrl* Text1;
		wxMyTextCtrl* Text2;
		wxMyTextCtrl* Text3;
		wxMyTextCtrl* Text4;
		wxStaticLine* StaticLine1;
		wxChoice* Segtype;               //管环类型
		wxChoice* Kpos;                  //K块位置
		//*)

	protected:

		//(*Identifiers(SegDialog)
        static const long ID_PANEL1;         //主panel
        static const long ID_BUTTON1;           //设置
        static const long ID_BUTTON2;           //退出
		static const long ID_STATICTEXT1;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICLINE2;
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		//*)

	private:

		//(*Handlers(SegDialog)
        void OnTypeSelect(wxCommandEvent& event);
        void OnKposSelect(wxCommandEvent& event);
        void OnPaintPanel(wxPaintEvent& event);

        void OnBtnSave(wxCommandEvent& event);
        void OnBtnQuit(wxCommandEvent& event);
		//*)

        void LoadData();
		DECLARE_EVENT_TABLE()
};

#endif
