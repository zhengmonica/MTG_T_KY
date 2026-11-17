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
#include "MDTitle.h"
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class KeyBoard
///////////////////////////////////////////////////////////////////////////////
class KeyBoard :public wxDialog
{
	protected:
		void OnPaintKey(wxPaintEvent& event);
		void OnMotionKey(wxMouseEvent& event);
		void OnKeyClicked(wxMouseEvent& event);
		void OnKeyMouseDown(wxMouseEvent& event);
		void OnLeaveKey(wxMouseEvent& event);

	protected:
		enum
		{
          ID_KEY_NONE,
		  ID_KEY_CAPTION,
		  ID_KEY_MODE,
		  ID_KEY_CLOSE,
		  ID_KEY_BREAK,
		  ID_KEY_ENTER,
		  ID_KEY_MARK_0,
		  ID_KEY_MARK_1,
		  ID_KEY_MARK_2,
		  ID_KEY_MARK_3,
		  ID_KEY_MARK_4,
		  ID_KEY_MARK_5,
		  ID_KEY_MARK_6,
		  ID_KEY_BTN_0,
		  ID_KEY_BTN_1,
		  ID_KEY_BTN_2,
		  ID_KEY_BTN_3,
		  ID_KEY_BTN_4,
		  ID_KEY_BTN_5,
		  ID_KEY_BTN_6,
		  ID_KEY_BTN_7,
		  ID_KEY_BTN_8,
		  ID_KEY_BTN_9,
		  ID_KEY_BLANK,
		  ID_KEY_STEP_SET,
		  ID_KEY_STEP_SEP,
		  ID_KEY_IN_123,
		  ID_KEY_IN_ABC,
		  ID_KEY_CAP_LOCK,
		  ID_KEY_CAP_NLOCK,
		  ID_KEY_WIN_MOVE,
		  ID_KEY_BRACKET_FRONT,
		  ID_KEY_BRACKET_BEHIND,
		  ID_KEY_COUNT
		};

        int inMode;
        int inStep;
        int motion;
        int keyExpand;
        int keyCaps;
        int winMove;
        int bracketPosition;
        int m_x1,m_y1,m_x0,m_y0;
        wxPanel* keyPanel;

        wxRect keyButton[ID_KEY_COUNT];

	public:

		KeyBoard( wxWindow* parent, wxTextCtrl* ctrl );
		~KeyBoard();
        wxTextCtrl* m_pTextCtrl;
};

#endif //__KeyBoard__
