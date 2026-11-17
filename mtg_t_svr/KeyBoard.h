///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug 25 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __KeyBoard__
#define __KeyBoard__

#include <wx/string.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/gbsizer.h>
#include <wx/splitter.h>
#include <wx/tglbtn.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class KeyBoard
///////////////////////////////////////////////////////////////////////////////
class KeyBoard :public wxDialog
{
	protected:
		///当前键盘类型
		enum
		{
			KEY_TYPE_NUMBER,
			KEY_TYPE_ALPABET,
			KEY_TYPE_SYMBOL,
			KEY_TYPE_FACE,
			KEY_TYPE_GREECE,
			KEY_TYPE_SPECIAL
		};
		///当前键盘类型
		int m_nCurType;
		///是否大写
		bool m_bCapslock;
		///键盘是否展开
		bool m_bExpand;
		///设置当前键盘类型
		void SetCurType(int type);

		void InitGui();

	protected:
		enum
		{
		  ID_BUTTON_0=  1024,
		  ID_BUTTON_1,
		  ID_BUTTON_2,
		  ID_BUTTON_3,
		  ID_BUTTON_4,
		  ID_BUTTON_5,
		  ID_BUTTON_6,
		  ID_BUTTON_7,
		  ID_BUTTON_8,
		  ID_BUTTON_9,
		  ID_BUTTON_10,
		  ID_BUTTON_11,
		  ID_BUTTON_DOWN,
		  ID_BUTTON_UP,
		  ID_BUTTON_BACK,
		  ID_BUTTON_ENTER,
		  ID_STATIC_0,
		  ID_STATIC_1,
		  ID_STATIC_2,
		  ID_STATIC_3,
		  ID_STATIC_4,
		  ID_STATIC_5
		};
		wxButton* m_btnUp;
		wxButton* m_btnDown;
		wxButton* m_btnArray[12];
		wxButton* m_staticArray[6];
		wxButton* m_btnEnter;
		wxButton* m_btnBack;

		// Virtual event handlers, overide them in your derived class
		void OnTextEnter( wxCommandEvent& event );
		void OnBtnUp( wxCommandEvent& event );
		void OnBtnDown( wxCommandEvent& event );
		void OnBtnBack( wxCommandEvent& event );
		void OnBtnEnter( wxCommandEvent& event );
		void OnBtnClick(wxCommandEvent& event);
		void OnBtnClick1(wxCommandEvent& event);


	public:

		KeyBoard( wxWindow* parent, wxTextCtrl* ctrl );
		~KeyBoard();
        wxTextCtrl* m_pTextCtrl;

};

#endif //__KeyBoard__
