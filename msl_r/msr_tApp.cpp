/***************************************************************
 * Name:      msr_tApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Meter Degree (dengdeyan@meter-degree.com)
 * Created:   2011-03-21
 * Copyright: Meter Degree (http://www.meter-degree.com)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "msr_tApp.h"
#include "libele.h"
#include "wx/stdpaths.h"

//(*AppHeaders
#include "msr_tMain.h"
#include <wx/image.h>
//*)
#include <wx/config.h>
//#define PI  3.1415926535897932384626433832795

msr_t *msr=0;

wxBrush ibrush[10];
wxPen ipen[10];
wxColor icolor[10];

wxLocale intl;

IMPLEMENT_APP(msr_tApp);

BEGIN_EVENT_TABLE(msr_tApp,wxApp)
    //(*EventTable(mtg_tFrame)

    //*)
END_EVENT_TABLE()

bool msr_tApp::OnInit()
{
    const wxString name = wxString::Format(wxT("msr_t-%s"), wxGetUserId().c_str());
    m_checker = new wxSingleInstanceChecker(name);
    if ( m_checker->IsAnotherRunning() )
    {
        wxMessageBox(_("程序正在运行！"));
        return false;
    }


    ibrush[0]=wxBrush(wxColor(255,255,255));
    ibrush[1]=wxBrush(wxColor(200,225,250));
    ibrush[2]=wxBrush(wxColor(80,196,23));
    ibrush[3]=wxBrush(wxColor(200,225,250));
    ibrush[4]=wxBrush(wxColor(200,225,250));
    ibrush[5]=wxBrush(wxColor(80,196,23));
    ibrush[6]=wxBrush(wxColor(200,225,250));
    ibrush[7]=wxBrush(wxColor(80,196,23));
    ibrush[8]=wxBrush(wxColor(80,196,23));
    ibrush[9]=wxBrush(wxColor(80,196,23));
    ipen[0]=wxPen(wxColor(178,178,178));
    ipen[1]=wxPen(wxColor(21,131,221));
    ipen[2]=wxPen(wxColor(80,196,23));
    ipen[3]=wxPen(wxColor(21,131,221));
    icolor[0]=wxColor(0,0,0);
    icolor[1]=wxColor(0,0,0);
    icolor[2]=wxColor(255,255,255);

    wxConfig *config = new wxConfig(_("MTG-T"));
    long lang=0;
    config->Read(_("Language"),&lang,0);
    delete config;

    switch(lang)
    {
    case 0:
        intl.Init(wxLANGUAGE_CHINESE_SIMPLIFIED);
        break;
    case 1:
        intl.Init(wxLANGUAGE_CHINESE_TRADITIONAL);
        break;
    case 2:
        intl.Init(wxLANGUAGE_ENGLISH);
        break;
    default:
        break;
    }

    wxLocale::AddCatalogLookupPathPrefix(wxT("il8n"));
    // Initialize the catalogs we'll be using
    intl.AddCatalog(wxT("internat"));

    msr=(msr_t*)malloc(sizeof(msr_t));
    memset(msr,0,sizeof(msr_t));        ///将与mtg_t相关的所有变量初始化为0
    msr_init(msr);

    char path[260];
    FILE* fp;
    wxStandardPaths wsp;
    wxString str=wsp.GetDataDir()+wxString(_("\\plugins\\"))+wxString(_("project.prj"));
    strcpy(path,str.mb_str(wxConvLocal));
    fp=fopen(path,"r");
    if(fp)
    {
        char msg[4096];
        rewind(fp);                            /*将文件指针移到首位*/
        fgets(msg,4096,fp);
        sscanf(msg,"'%[^']',%lf,%lf,%d\n",msr->prj.name,&msr->prj.mile1,&msr->prj.mile2,&msr->prj.a2z);
        if(strlen(msr->prj.name)==0)
        {
            sscanf(msg,"%lf,%lf,%d\n",&msr->prj.mile1,&msr->prj.mile2,&msr->prj.a2z);
        }
        fclose(fp);
    }

    str=wsp.GetDataDir()+wxString(_("\\plugins\\"))+wxString(_("tunnel.dta"));
    strcpy(path,str.mb_str(wxConvLocal));
    fp=fopen(path,"r");
    if(fp)
    {
        char msg[4096];
        rewind(fp);
        int i,id;
        h_element he;
        v_element ve;
        h_offset ho;
        v_offset vo;
        m_offset mo;
        int nr[5];
        nr[0]=nr[1]=nr[2]=nr[3]=nr[4]=0;
        while(!feof(fp))
        {
            fgets(msg,4096,fp);
            id=-1;
            if(!sscanf(msg,"%%R1P,%d:",&id)) break;
            //wxMessageBox(wxString::Format(_("%d"),id));
            switch(id)
            {
                case 0:
                {
                    //wxMessageBox(wxString::Format(_("%d"),id));
                    road_init(&msr->r);
                    road_clear_horizon(&msr->r);
                    road_clear_vertical(&msr->r);
                    road_clear_horizon_off(&msr->r);
                    road_clear_vertical_off(&msr->r);
                    road_clear_mile_off(&msr->r);
                    sscanf(msg,"%%R1P,0:%d,%d,%d,%d,%d\n",&nr[0],&nr[1],&nr[2],&nr[3],&nr[4]);
                    //wxMessageBox(wxString::Format(_("%d,%d"),nr[0],nr[1]));
                    break;
                }
                case 1:
                {
                    sscanf(msg,"%%R1P,1:%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d\n",
                       &i,&he.type,&he.l1,&he.length,&he.angle1,&he.angle2,&he.radius,
                       &he.rou1,&he.rou2,&he.x1,&he.y1,&he.x2,&he.y2,&he.pz);
                    road_insert_horizon(&msr->r,&he,i);
                    //wxMessageBox(wxString::Format(_("%d"),i));
                    //road_apply_horizon(&msr->r);
                    nr[0]--;
                    break;
                }
                case 2:
                {
                    sscanf(msg,"%%R1P,2:%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d\n",
                       &i,&ve.type,&ve.l1,&ve.h1,&ve.l2,&ve.h2,
                       &ve.length,&ve.radius,&ve.angle1,&ve.angle2,&ve.pz);
                    road_insert_vertical(&msr->r,&ve,i);
                    //road_apply_vertical(&msr->r);
                    nr[1]--;
                    break;
                }
                case 3:
                {
                    sscanf(msg,"%%R1P,3:%d,%lf,%lf\n",&i,&ho.mile,&ho.off);
                    road_insert_horizon_off(&msr->r,&ho);
                    nr[2]--;
                    break;
                }
                case 4:
                {
                    sscanf(msg,"%%R1P,1:4:%d,%lf,%lf\n",&i,&vo.mile,&vo.off);
                    road_insert_vertical_off(&msr->r,&vo);
                    nr[3]--;
                    break;
                }
                case 5:
                {
                    sscanf(msg,"%%R1P,1:5:%d,%lf,%lf\n",&i,&mo.mile,&mo.off);
                    road_insert_mile_off(&msr->r,&mo);
                    nr[4]--;
                    break;
                }
                default:
                    break;
            }
            if(nr[0]==0 && nr[1]==0 && nr[2]==0 && nr[3]==0 && nr[4]==0) break;
        }

        fclose(fp);
    }

    str=wsp.GetDataDir()+wxString(_("\\plugins\\"))+wxString(_("geometry.tbm"));
    strcpy(path,str.mb_str(wxConvLocal));
    fp=fopen(path,"r");
    if(fp)
    {
        char msg[4096];
        rewind(fp);                            /*将文件指针移到首位*/
        fgets(msg,4096,fp);
        sscanf(msg,"'%[^']',%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,\
            %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,\
            %d,%lf,%lf,%lf,%lf,%d,\
            %d,%lf,%lf,%lf,%lf,%d\n",msr->tbm.name,&msr->tbm.type,&msr->tbm.mode,
        &msr->tbm.D[0],&msr->tbm.D[1],&msr->tbm.D[2],&msr->tbm.D[3],&msr->tbm.D[4],&msr->tbm.D[5],&msr->tbm.L[0],&msr->tbm.L[1],&msr->tbm.L[2],&msr->tbm.L[3],&msr->tbm.L[4],&msr->tbm.L[5],
        &msr->tbm.L[6],&msr->tbm.L[7],&msr->tbm.L[8],&msr->tbm.naj,&msr->tbm.aj[0],&msr->tbm.aj[1],&msr->tbm.aj[2],&msr->tbm.aj[3],&msr->tbm.aj[4],&msr->tbm.aj[5],&msr->tbm.aunit,
        &msr->tbm.nbj,&msr->tbm.bj[0],&msr->tbm.bj[1],&msr->tbm.bj[2],&msr->tbm.bj[3],&msr->tbm.bunit,
        &msr->tbm.nfj,&msr->tbm.fj[0],&msr->tbm.fj[1],&msr->tbm.fj[2],&msr->tbm.fj[3],&msr->tbm.funit
        );
        if(strlen(msr->tbm.name)==0)
        sscanf(msg,"'',%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,\
            %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,\
            %d,%lf,%lf,%lf,%lf,%d,\
            %d,%lf,%lf,%lf,%lf,%d\n",&msr->tbm.type,&msr->tbm.mode,
        &msr->tbm.D[0],&msr->tbm.D[1],&msr->tbm.D[2],&msr->tbm.D[3],&msr->tbm.D[4],&msr->tbm.D[5],&msr->tbm.L[0],&msr->tbm.L[1],&msr->tbm.L[2],&msr->tbm.L[3],&msr->tbm.L[4],&msr->tbm.L[5],
        &msr->tbm.L[6],&msr->tbm.L[7],&msr->tbm.L[8],&msr->tbm.naj,&msr->tbm.aj[0],&msr->tbm.aj[1],&msr->tbm.aj[2],&msr->tbm.aj[3],&msr->tbm.aj[4],&msr->tbm.aj[5],&msr->tbm.aunit,
        &msr->tbm.nbj,&msr->tbm.bj[0],&msr->tbm.bj[1],&msr->tbm.bj[2],&msr->tbm.bj[3],&msr->tbm.bunit,
        &msr->tbm.nfj,&msr->tbm.fj[0],&msr->tbm.fj[1],&msr->tbm.fj[2],&msr->tbm.fj[3],&msr->tbm.funit
        );
        fclose(fp);
    }

    str=wsp.GetDataDir()+wxString(_("\\plugins\\"))+wxString(_("segment.segt"));
    strcpy(path,str.mb_str(wxConvLocal));
    fp=fopen(path,"r");
    if(fp)
    {
        char msg[4096];
        rewind(fp);                            /*将文件指针移到首位*/
        fgets(msg,4096,fp);
        sscanf(msg,"%d,%d,%d,%lf,%lf,%lf,%lf,%d,%lf,%lf,%d\n",
        &msr->segt.type,&msr->segt.in,&msr->segt.f2b,&msr->segt.l2s,
        &msr->segt.L,&msr->segt.De,&msr->segt.D,&msr->segt.Ks,&msr->segt.G0,&msr->segt.G1,&msr->segt.s2s);
        fclose(fp);
    }

    str=wsp.GetDataDir()+wxString(_("\\plugins\\"))+wxString(_("blocks.blk"));
    strcpy(path,str.mb_str(wxConvLocal));
    fp=fopen(path,"r");
    if(fp)
    {
        char msg[4096];
        rewind(fp);
        int i,id;
        while(!feof(fp))
        {
            fgets(msg,4096,fp);
            id=-1;
            i=-1;
            if(!sscanf(msg,"%%R1P,%d:%d",&id,&i)) break;
            switch(id)
            {
                case 0:
                {
                    msr->nblk=i;
                    msr->blocks=(BLOCK_T*)realloc(msr->blocks,msr->nblk*sizeof(BLOCK_T));
                    //wxMessageBox(wxString::Format(_("%d"),i));
                    break;
                }
                case 1:
                {
                    //wxMessageBox(wxString::Format(_("%d"),i));
                    sscanf(msg,"%%R1P,1:%d,'%[^']',%lf\n",&i,msr->blocks[i].name,&msr->blocks[i].angle);
                    if(strlen(msr->blocks[i].name)==0)
                    sscanf(msg,"%%R1P,1:%d,'',%lf\n",&i,&msr->blocks[i].angle);
                    break;
                }
                default:
                    break;
            }

            if(i==msr->nblk-1) break;
        }
        fclose(fp);
    }
    msr_init_kpos(msr);
    msr_init_pz(msr);

    str=wsp.GetDataDir()+wxString(_("\\plugins\\"))+wxString(_("design.seg"));
    strcpy(path,str.mb_str(wxConvLocal));
    fp=fopen(path,"r");
    if(fp)
    {
        fclose(fp);
    }
    else
    {
        msr_init_des(msr);
        msr->dcal=0;
    }

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	mtg_tFrame* Frame = new mtg_tFrame(0);
    	Frame->SetMinSize(wxSize(800,600));
    	Frame->SetSize(1024,728);
    	Frame->CenterOnScreen();

    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)

    return wxsOK;
}

int msr_tApp::OnExit()
{
    msr_final();
    delete m_checker;
    return 0;
}
