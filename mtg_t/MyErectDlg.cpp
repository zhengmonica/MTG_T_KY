#include "MyErectDlg.h"
#include "mtg_tApp.h"
#if 0
#include "MyCanvas.h"
#else
#include "wx/xy/xylinerenderer.h"
#include "wx/xy/xyplot.h"
#include "wx/chart.h"
#include "wx/chartpanel.h"
#include "MyXYDataset.h"
#endif

MyErectDlg::MyErectDlg( wxWindow* parent )
:
ErectDlg( parent )
{
    ///查询历史推进记录
    //nres=mtg_query_segment_meas(mtg,mtg->m.seg,mtg->m.seg,&res);
    ///偏差曲线
    CreateDiffHorizon();
    CreateDiffVertical();

    m_textSeg->SetValue(wxString::Format(_("%d"),mtg->m.iseg));
}

void MyErectDlg::OnBtnModify( wxCommandEvent& event )
{
// TODO: Implement OnBtnModify
    long val;
    m_textSeg->GetValue().ToLong(&val);
    mtg->m.iseg=val;
    Close();
}

void MyErectDlg::OnBtnErect( wxCommandEvent& event )
{
// TODO: Implement OnBtnErect
    if(mtg_pause_cycle(mtg)==0)
    {
        long val;
        m_textSeg->GetValue().ToLong(&val);
        mtg->m.iseg=val+1;
        mtg_pause_cycle(mtg);
    }
    Close();
}

void MyErectDlg::CreateDiffHorizon()
{
    #if 0
    #else
    MyXYDataset *set=new MyXYDataset();

    int count=nres;
    double *data=new double[2*count];
    ///盾首
    for(int i=0;i<count;i++)
    {
        data[2*i]=res[i].headc;
        data[2*i+1]=res[i].headh*1000.0;
    }
    set->AddSerie(data,count);
    ///盾尾
    for(int i=0;i<count;i++)
    {
        data[2*i]=res[i].tailc;
        data[2*i+1]=res[i].tailh*1000.0;
    }
    set->AddSerie(data,count);
    delete data;data=0;



    set->SetSerieName(0,_("盾首偏差(mm)"));
    set->SetSerieName(1,_("盾尾偏差(mm)"));

    ///render
    XYLineRenderer* render=new XYLineRenderer(true,true);
    wxColour bColor(0,0,255);
    render->SetSerieColour(0,&bColor);
    wxColour gColor(0,255,0);
    render->SetSerieColour(1,&gColor);
    set->SetRenderer(render);

    XYPlot *plot = new XYPlot();
    plot->AddDataset(set);
    // add left and bottom number axes
    double minY=fabs(set->GetMinY());
    double maxY=fabs(set->GetMaxY());
    double maxH=(minY<maxY)?maxY:minY;
    NumberAxis* hAxis=new NumberAxis(AXIS_BOTTOM);
    NumberAxis* vAxis=new NumberAxis(AXIS_LEFT);
    vAxis->IntegerValues(true);
    if(maxH<20)
    {
        vAxis->SetFixedBounds(-20.0,20.0);
    }
    else if(maxH<50)
    {
        vAxis->SetFixedBounds(-50.0,50.0);
    }
    else if(maxH<100)
    {
        vAxis->SetFixedBounds(-100.0,100.0);
    }
    else if(maxH<200)
    {
        vAxis->SetFixedBounds(-200.0,200.0);
    }
    else
    {
        vAxis->SetFixedBounds(-500.0,500.0);
    }
    plot->AddAxis(hAxis);
    plot->AddAxis(vAxis);

    // link axes and dataset
    plot->LinkDataVerticalAxis(0, 0);
    plot->LinkDataHorizontalAxis(0, 0);
    // set legend to plot
    plot->SetLegend(new Legend(wxCENTER, wxRIGHT));
    Chart* chart=new Chart(plot,_("平面偏差"));
    m_panelHorizon->SetChart(chart);
    #endif

}

void MyErectDlg::CreateDiffVertical()
{
    #if 0
    #else
    MyXYDataset *set=new MyXYDataset();

    int count=nres;
    double *data=new double[2*count];
    ///盾首
    for(int i=0;i<count;i++)
    {
        data[2*i]=res[i].headc;
        data[2*i+1]=res[i].headv*1000.0;
    }
    set->AddSerie(data,count);
    ///盾尾
    for(int i=0;i<count;i++)
    {
        data[2*i]=res[i].tailc;
        data[2*i+1]=res[i].tailv*1000.0;
    }
    set->AddSerie(data,count);
    delete data;data=0;

    set->SetSerieName(0,_("盾首偏差(mm)"));
    set->SetSerieName(1,_("盾尾偏差(mm)"));

    ///render
    XYLineRenderer* render=new XYLineRenderer(true,true);
    wxColour bColor(0,0,255);
    render->SetSerieColour(0,&bColor);
    wxColour gColor(0,255,0);
    render->SetSerieColour(1,&gColor);
    set->SetRenderer(render);

    XYPlot *plot = new XYPlot();
    plot->AddDataset(set);
    // add left and bottom number axes
    double minY=fabs(set->GetMinY());
    double maxY=fabs(set->GetMaxY());
    double maxH=(minY<maxY)?maxY:minY;
    NumberAxis* hAxis=new NumberAxis(AXIS_BOTTOM);
    NumberAxis* vAxis=new NumberAxis(AXIS_LEFT);
    vAxis->IntegerValues(true);
    if(maxH<20)
    {
        vAxis->SetFixedBounds(-20.0,20.0);
    }
    else if(maxH<50)
    {
        vAxis->SetFixedBounds(-50.0,50.0);
    }
    else if(maxH<100)
    {
        vAxis->SetFixedBounds(-100.0,100.0);
    }
    else if(maxH<200)
    {
        vAxis->SetFixedBounds(-200.0,200.0);
    }
    else
    {
        vAxis->SetFixedBounds(-500.0,500.0);
    }
    plot->AddAxis(hAxis);
    plot->AddAxis(vAxis);

    // link axes and dataset
    plot->LinkDataVerticalAxis(0, 0);
    plot->LinkDataHorizontalAxis(0, 0);
    // set legend to plot
    plot->SetLegend(new Legend(wxCENTER, wxRIGHT));
    Chart* chart=new Chart(plot,_("高程偏差"));
    m_panelVertical->SetChart(chart);
    #endif
}
