/***************************************************************
 * Name:      mtg_d_svrApp.h
 * Purpose:   Defines Application Class
 * Author:    MIDU (；lhr@midu.com)
 * Created:   2016-02-19
 * Copyright: MIDU (http://www.midu.com)
 * License:
 **************************************************************/

#ifndef MTG_T_SVRAPP_H
#define MTG_T_SVRAPP_H

#include <wx/app.h>
#include "libmtg.h"
#include <wx/snglinst.h>

class mtg_t_svrApp : public wxApp
{
    public:
        virtual bool OnInit();
        virtual int OnExit();
        wxSingleInstanceChecker *m_check;
};

DECLARE_APP(mtg_t_svrApp)
extern mtg_t* mtg;
extern wxString path;
#endif // MTG_T_SVRAPP_H
