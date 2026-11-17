#include "MyXYDataset.h"

XYSerie::XYSerie(double *data, int count)
{
    m_data = new double[2 * count];
    memcpy(m_data, data, 2 * count * sizeof(double));
    m_count = count;
}

XYSerie::~XYSerie()
{
    delete m_data;
}

double XYSerie::GetX(int index)
{
    wxCHECK_MSG(index < m_count, 0, _("XYSerie::GetX"));
    return m_data[index * 2];
}

double XYSerie::GetY(int index)
{
    wxCHECK_MSG(index < m_count, 0, _("XYSerie::GetY"));
    return m_data[index * 2 + 1];
}

int XYSerie::GetCount()
{
    return m_count;
}

const wxString& XYSerie::GetName()
{
    return m_name;
}

void XYSerie::SetName(const wxString &name)
{
    m_name = name;;
}



MyXYDataset::MyXYDataset()
{
    minx=miny=1.0e30;
    maxx=maxy=-1.0e30;
}


MyXYDataset::~MyXYDataset()
{
    for (size_t n = 0; n < m_series.size(); n++)
    {
        delete m_series[n];
    }
}


void MyXYDataset::AddSerie(double *data, int count)
{
    m_series.push_back(new XYSerie(data, count));

    for(int i=0;i<count;i++)
    {
        if(data[2*i]<minx) minx=data[2*i];
        if(data[2*i]>maxx) maxx=data[2*i];
        if(data[2*i+1]<miny) miny=data[2*i+1];
        if(data[2*i+1]>maxy) maxy=data[2*i+1];
    }
    DatasetChanged();
}

double MyXYDataset::GetX(size_t index, size_t serie)
{
    return m_series[serie]->GetX(index);
}

double MyXYDataset::GetY(size_t index, size_t serie)
{
    return m_series[serie]->GetY(index);
}

size_t MyXYDataset::GetSerieCount()
{
    return m_series.size();
}

size_t MyXYDataset::GetCount(size_t serie)
{
    return m_series[serie]->GetCount();
}

wxString MyXYDataset::GetSerieName(size_t serie)
{
    return m_series[serie]->GetName();
    //return wxString::Format(_("serie %i"), serie);
}

void MyXYDataset::SetSerieName(size_t serie, const wxString &name)
{
    m_series[serie]->SetName(name);
    DatasetChanged();
}

double MyXYDataset::GetMinValue(bool vertical)
{
    if(vertical)
    {
        return miny;
    }
    else
    {
        return minx;
    }
}

double MyXYDataset::GetMaxValue(bool vertical)
{
    if(vertical)
    {
        return maxy;
    }
    else
    {
        return maxx;
    }
}

bool MyXYDataset::AcceptRenderer(Renderer* r)
{
    return true;
}
