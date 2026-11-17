#ifndef LOGDIALOG_H_INCLUDED
#define LOGDIALOG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDTitle.h"
#include "MDButtonList.h"
#include "libmtg.h"

//(*Headers(LogDialog)
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
#include <wx/statline.h>
#include <wx/grid.h>
//*)

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class LogDialog
///////////////////////////////////////////////////////////////////////////////
class LogDialog : public wxDialog
{
	private:
	    //(*Handlers(LogDialog)
        void OnPaintBackground(wxPaintEvent& event);
        void OnButtonClick(wxMouseEvent& event);

        void OnPaintDateList(wxPaintEvent& event);
        void OnPaintLogs(wxPaintEvent& event);

        void OnHistorySelect(wxListEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);
        //*)
        MTG_LOG* logs;
        int nlogs;

        void QureyLogs(int sel);
	protected:
	    //(*Identifiers(LogDialog)
	    static const long ID_PANEL1;             //标题
        //*)
        enum
        {
            ID_LOG_NONE,
            ID_LOG_QUIT,
            ID_LOG_IPT,
            ID_LOG_COUNT
        };

        wxPanel* panelMain;
        wxPanel* logPanel;
        wxPanel* panelBottom;
        wxPanel* datePanel;
        wxListView* listDate;
        wxPanel* logsPanel;
        //wxListView* historyLog;

        wxRect smButton[ID_LOG_COUNT];
        int motion;
        int vmode;

        //wxTimer logTimer;
		//void OnTimer(wxTimerEvent& event);
		bool isquerying;
		int tick;

	public:
		LogDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("系统日志"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600), long style = wxBORDER_RAISED);
		~LogDialog();

        void UpdateLogName();
		//(*Declarations(MySetupDialog)
        MDTitle* panelTitle;                    //ID_PANEL1
        wxListView* listLog;
        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
