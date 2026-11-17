#ifndef MYFILEDLG_H_INCLUDED
#define MYFILEDLG_H_INCLUDED

#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include "wxMyTextCtrl.h"
#include "MDButtonList.h"

//(*Headers(MyfileDlg)
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
/// ClassMypointDlg
///////////////////////////////////////////////////////////////////////////////
class MyfileDlg : public wxDialog
{
	private:
	    //(*Handlers(MyfileDlg)
        void OnPaintMain(wxPaintEvent& event);

        void OnPaintFile(wxPaintEvent& event);
        void OnMotionFile(wxMouseEvent& event);
        void OnLeaveFile(wxMouseEvent& event);
        void OnClickFile(wxMouseEvent& event);

        void OnPaintBottom(wxPaintEvent& event);
        void OnMotionBottom(wxMouseEvent& event);
        void OnLeaveBottom(wxMouseEvent& event);
        void OnClickBottom(wxMouseEvent& event);

        void OnFileActivated(wxListEvent& event);
        //*)
        wxString path;               ///基础路径
        wxString fpath;              ///临时添加文件路径
        wxString ipath;              ///返回路径
        wxString iname;              ///文件名称
        wxTextCtrl* filePath;
	protected:
	    //(*Identifiers(MyfileDlg)

        //*)
        enum
        {
            ID_FP_NONE,
            ID_FP_QUIT,
            ID_FP_OK,
            ID_FP_FILE,
            ID_FP_COUNT
        };

        wxPanel* panelMain;
        wxPanel* panelBottom;
        wxPanel* fileButton;

        wxListView* fileList;

        wxRect fpButton[ID_FP_COUNT];
        int motion;

	public:
		MyfileDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _(""), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(400,400), long style = wxDEFAULT_DIALOG_STYLE);
		~MyfileDlg();
        wxString GetFile();
        wxString GetFileName();
        void UptateFileList();
        wxString Type;
		//(*Declarations(MySetupDialog)

        //*)
};

#endif // SEGMENTDLG_H_INCLUDED
