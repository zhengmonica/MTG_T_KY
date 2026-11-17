#ifndef WXRIGHTGRID_H
#define WXRIGHTGRID_H

#include <wx/grid.h>

class MergeInfo
{
    public:
    MergeInfo(){}
    wxString m_title;
    int m_start;
    int m_end;
};
WX_DEFINE_ARRAY(MergeInfo *, MergeInfoArray);

extern const wxEventType wxEVT_MENU_DEL_COMMAND;
extern const wxEventType wxEVT_MENU_INSERT_COMMAND;
extern const wxEventType wxEVT_MENU_CLEAR_COMMAND;
extern const wxEventType wxEVT_MENU_STICK_COMMAND;
extern const wxEventType wxEVT_MENU_SELALL_COMMAND;

class wxRightGrid : public wxGrid
{
    public:
        wxRightGrid(wxWindow *parent,
            wxWindowID id,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxWANTS_CHARS,
            const wxString& name = wxGridNameStr);
        virtual ~wxRightGrid();
        virtual void DrawColLabel( wxDC& dc, int col );
        virtual void DrawColLabels( wxDC& dc,const wxArrayInt& cols );
        virtual void OnEditorShown(wxGridEvent& event);
        virtual void OnEditorHidden(wxGridEvent& event);
        void MergeColum(const wxString& str,int start,int end);
        void GridEnable(bool e=true);
        void GridStick(bool e=true);
        void GridClear(bool e=true);
        void GridSelAll(bool e=true);
        void GridCopy(bool e=true);
        void AtuoAddRow(bool e=true);
        void GridInsert(bool e=true);
        void GridDelete(bool e=true);
        bool check;
    protected:
        enum
        {
            ID_MENU_DEL=1000,
            ID_MENU_INSERT,
            ID_MENU_CLEAR,
            ID_MENU_STICK,
            ID_MENU_COPY,
            ID_MENU_SELALL,
        };
        void OnLeftClick(wxGridEvent& event);
        void OnRightClick(wxGridEvent& event);
        void OnEnterDown(wxKeyEvent& event);
        void OnMenuDel(wxCommandEvent& event);
        void OnMenuInsert(wxCommandEvent& event);
        void OnMenuClear(wxCommandEvent& event);
        void OnMenuStick(wxCommandEvent& event);
        void OnMenuCopy(wxCommandEvent& event);
        void OnMenuSel(wxCommandEvent& event);
    private:
        MergeInfoArray m_arrayMergeCol;
        int m_col,m_row;
        bool _io;
        bool _stick;
        bool _clear;
        bool _selall;
        ///bool check;
        bool _autorow;
        bool _copy;
        bool _insert;
        bool _delete;
};
#endif // WXRIGHTGRID_H
