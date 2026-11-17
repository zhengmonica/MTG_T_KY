/***************************************************************
 * Name:      ResetTargetMain.h
 * Purpose:   Defines Application Frame
 * Author:    whq ()
 * Created:   2019-05-14
 * Copyright: whq ()
 * License:
 **************************************************************/

#ifndef RESETTARGETMAIN_H
#define RESETTARGETMAIN_H

//(*Headers(ResetTargetDialog)
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include <windows.h>

#define lock_t      CRITICAL_SECTION
#define initlock(f) InitializeCriticalSection(f)
#define lock(f)     EnterCriticalSection(f)
#define unlock(f)   LeaveCriticalSection(f)

class ResetTargetDialog: public wxDialog
{
    public:

        ResetTargetDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~ResetTargetDialog();

    private:

        //(*Handlers(ResetTargetDialog)
        void OnReadClick(wxCommandEvent& event);
        void OnClearClick(wxCommandEvent& event);
        void OnPaintMain(wxPaintEvent& event);
        //*)

        //(*Identifiers(ResetTargetDialog)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICLINE1;
        static const long ID_PANEL3;
        static const long ID_PANEL1;
        static const long ID_PANEL2;
        //*)

        //(*Declarations(ResetTargetDialog)
        wxButton* Button1;
        wxPanel* Panel1;
        wxButton* Button2;
        wxPanel* Panel3;
        wxStaticLine* StaticLine1;
        wxPanel* Panel2;
        //*)
        char host[64];
        char uid[64];
        char psw[64];
        char db[64];
        lock_t dblock;
        int stopped;
        int readOK;

        int ReadDB();
        int WriteDB();

        DECLARE_EVENT_TABLE()
};

#endif // RESETTARGETMAIN_H
