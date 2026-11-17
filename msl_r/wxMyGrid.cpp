#include "wxMyGrid.h"
#include <wx/dc.h>
#include <wx/settings.h>

wxMyGrid::wxMyGrid():wxGrid()
{

}

wxMyGrid::wxMyGrid(wxWindow *parent,
            wxWindowID id,
            const wxPoint& pos ,
            const wxSize& size ,
            long style ,
            const wxString& name ):wxGrid(parent,id,pos,size,style,name)
            {

            }

void wxMyGrid::MergeColum(const wxString& str,int start,int end)
{
    MergeInfo *pInfo=new MergeInfo;
    pInfo->m_start=start;
    pInfo->m_end=end;
    pInfo->m_title=str;
    m_arrayMergeCol.Add(pInfo);
}

void wxMyGrid::MergeRow(const wxString& str,int start,int end)
{
    MergeInfo *pInfo=new MergeInfo;
    pInfo->m_start=start;
    pInfo->m_end=end;
    pInfo->m_title=str;
    m_arrayMergeRow.Add(pInfo);
}

/*
void wxMyGrid::DrawRowLabels( wxDC& dc,const wxArrayInt& rows )
{
    if ( !m_numRows )
        return;

    size_t i;
    size_t numLabels = rows.GetCount();

    ///画合并后的表头
    size_t numMerge=m_arrayMergeRow.GetCount();
    //wxMessageBox(wxString::Format(_("%d"),numMerge));
    for(i=0;i<numMerge;i++)
    {
        //wxMessageBox(wxString::Format(_("%d"),i));
        int row1 = GetRowTop(m_arrayMergeRow[i]->m_start);
        int row2 = GetRowBottom(m_arrayMergeRow[i]->m_end)-1;
        wxRect rect;
        dc.SetPen( wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW), 1, wxSOLID) );
        dc.DrawLine( 0,row2, m_rowLabelWidth-1, row2);
        dc.DrawLine( 0, row1, 0, row2 );
        dc.DrawLine( m_rowLabelWidth/2-1, row1, m_rowLabelWidth/2-1, row2 );
        dc.DrawLine( m_rowLabelWidth-1, row1, m_rowLabelWidth-1, row2 );
        //dc.DrawLine( colLeft, m_colLabelHeight/2-1,
                     //colRight + 1, m_colLabelHeight/2-1  );

        dc.SetPen( *wxWHITE_PEN );
        dc.DrawLine( 0, row2+1, m_rowLabelWidth/2-1, row2+1);
        dc.DrawLine( m_rowLabelWidth/2, row2+1, m_rowLabelWidth-1, row2+1);
        dc.DrawLine( 1, row1+1, 1, row2-1 );
        dc.DrawLine( m_rowLabelWidth/2, row1, m_rowLabelWidth/2, row2 );

        dc.SetBackgroundMode( wxTRANSPARENT );
        dc.SetTextForeground( GetLabelTextColour() );
        dc.SetFont( GetLabelFont() );

        int hAlign, vAlign, orient;
        GetColLabelAlignment( &hAlign, &vAlign );
        orient = GetColLabelTextOrientation();

        rect.SetX( 0 );
        rect.SetY( row1 );
        rect.SetWidth(m_rowLabelWidth/2-1);
        rect.SetHeight(row2-row1);
        //int w=0;
        //for(int j=m_arrayMergeRow[i]->m_start;j<=m_arrayMergeRow[i]->m_end;j++) w+=GetColWidth(j);
        //rect.SetWidth( w- 4 );
        //rect.SetHeight( m_colLabelHeight/2 - 4 );
        DrawTextRectangle( dc,m_arrayMergeRow[i]->m_title, rect, hAlign, vAlign, orient );
    }

    for ( i = 0; i < numLabels; i++ )
    {
        DrawRowLabel( dc, rows[i] );
    }
}
/*
void wxMyGrid::DrawRowLabel( wxDC& dc, int row )
{
    if ( GetRowHeight(row) <= 0 || m_rowLabelWidth <= 0 )
        return;
    ///判断是否为合并表头列
    bool bMerge=false;
    size_t numMerge=(int)m_arrayMergeRow.GetCount();
    size_t i;
    for(i=0;i<numMerge;i++)
    {
        if(row>=m_arrayMergeRow[i]->m_start && row<=m_arrayMergeRow[i]->m_end)
        {
            bMerge=true;
            break;
        }
    }
    if(bMerge)
    {
        int row1 = GetRowTop(row);
        wxRect rect;
        int row2 = GetRowBottom(row) - 1;

        dc.SetPen( wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW), 1, wxSOLID) );
        dc.DrawLine( m_rowLabelWidth/2-1,row2, m_rowLabelWidth/2-1, row2 );
        dc.DrawLine( m_rowLabelWidth/2, row1, m_rowLabelWidth/2, row2);
        dc.DrawLine( m_rowLabelWidth-1, row1,
                     m_rowLabelWidth-1 + 1, row2);

        dc.SetPen( *wxWHITE_PEN );
        dc.DrawLine( m_rowLabelWidth/2+1, row1, m_rowLabelWidth+1, row1 );
        dc.DrawLine( m_rowLabelWidth/2+1, row1, m_rowLabelWidth/2+1, row2 );

        dc.SetBackgroundMode( wxTRANSPARENT );
        dc.SetTextForeground( GetLabelTextColour() );
        dc.SetFont( GetLabelFont() );

        int hAlign, vAlign, orient;
        GetColLabelAlignment( &hAlign, &vAlign );
        orient = GetColLabelTextOrientation();

        rect.SetX( m_rowLabelWidth/2 + 2 );
        rect.SetY( row1+2 );
        rect.SetWidth( m_rowLabelWidth/2 - 4 );
        rect.SetHeight( GetRowHeight(row) - 4 );
        DrawTextRectangle( dc, GetRowLabelValue( row ), rect, hAlign, vAlign, orient );
    }
    else
    {
        int row1 = GetRowTop(row);
        wxRect rect;
        int row2 = GetRowBottom(row) - 1;

        dc.SetPen( wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW), 1, wxSOLID) );
        dc.DrawLine( 0, row2, m_rowLabelWidth-1, row2 );
        dc.DrawLine( 0, row1, 0, row2 );
        dc.DrawLine( m_rowLabelWidth-1, row1,m_rowLabelWidth-1, row2 );

        dc.SetPen( *wxWHITE_PEN );
        dc.DrawLine( 1, row1, m_rowLabelWidth-1, row1 );
        dc.DrawLine( 1, row1, 1, row2 );

        dc.SetBackgroundMode( wxTRANSPARENT );
        dc.SetTextForeground( GetLabelTextColour() );
        dc.SetFont( GetLabelFont() );

        int hAlign, vAlign, orient;
        GetColLabelAlignment( &hAlign, &vAlign );
        orient = GetColLabelTextOrientation();

        rect.SetX( 2 );
        rect.SetY( row1+2 );
        rect.SetWidth( m_rowLabelWidth - 4 );
        rect.SetHeight( GetRowHeight(row) - 4 );
        DrawTextRectangle( dc, GetColLabelValue( row ), rect, hAlign, vAlign, orient );
    }

}
*/
void wxMyGrid::DrawColLabels( wxDC& dc,const wxArrayInt& cols )
{
    if ( !m_numCols )
        return;

    size_t i;
    size_t numLabels = cols.GetCount();
    ///画合并后的表头

    size_t numMerge=m_arrayMergeCol.GetCount();
    for(i=0;i<numMerge;i++)
    {
        int colLeft = GetColLeft(m_arrayMergeCol[i]->m_start);
        wxRect rect;
        int colRight = GetColRight(m_arrayMergeCol[i]->m_end) - 1;
        dc.SetPen( wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW), 1, wxSOLID) );
        dc.DrawLine( colRight, 0, colRight, m_colLabelHeight/2-1 );
        dc.DrawLine( colLeft, 0, colRight, 0 );
        //dc.DrawLine( colLeft, m_colLabelHeight/2-1,
                     //colRight + 1, m_colLabelHeight/2-1  );

        dc.SetPen( *wxWHITE_PEN );
        dc.DrawLine( colLeft, 1, colLeft, m_colLabelHeight/2-1  );
        dc.DrawLine( colLeft, 1, colRight, 1 );

        dc.SetBackgroundMode( wxTRANSPARENT );
        dc.SetTextForeground( GetLabelTextColour() );
        dc.SetFont( GetLabelFont() );

        int hAlign, vAlign, orient;
        GetColLabelAlignment( &hAlign, &vAlign );
        orient = GetColLabelTextOrientation();

        rect.SetX( colLeft + 2 );
        rect.SetY( 2 );
        int w=0;
        for(int j=m_arrayMergeCol[i]->m_start;j<=m_arrayMergeCol[i]->m_end;j++) w+=GetColWidth(j);
        rect.SetWidth( w- 4 );
        rect.SetHeight( m_colLabelHeight/2 - 4 );
        DrawTextRectangle( dc,m_arrayMergeCol[i]->m_title, rect, hAlign, vAlign, orient );
    }

    for ( i = 0; i < numLabels; i++ )
    {
        DrawColLabel( dc, cols[i] );
    }
    //wxMessageBox(wxString::Format(_("%d"),GetScrollLineX()));
}

void wxMyGrid::DrawColLabel( wxDC& dc, int col )
{
    if ( GetColWidth(col) <= 0 || m_colLabelHeight <= 0 )
        return;
    ///判断是否为合并表头列
    bool bMerge=false;
    size_t numMerge=(int)m_arrayMergeCol.GetCount();
    size_t i;
    for(i=0;i<numMerge;i++)
    {
        if(col>=m_arrayMergeCol[i]->m_start && col<=m_arrayMergeCol[i]->m_end)
        {
            bMerge=true;
            break;
        }
    }
    if(bMerge)
    {
        int colLeft = GetColLeft(col);
        wxRect rect;
        int colRight = GetColRight(col) - 1;

        dc.SetPen( wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW), 1, wxSOLID) );
        dc.DrawLine( colRight, m_colLabelHeight/2, colRight, m_colLabelHeight - 1 );
        dc.DrawLine( colLeft, m_colLabelHeight/2, colRight, m_colLabelHeight/2 );
        dc.DrawLine( colLeft, m_colLabelHeight - 1,
                     colRight + 1, m_colLabelHeight - 1 );

        dc.SetPen( *wxWHITE_PEN );
        dc.DrawLine( colLeft, m_colLabelHeight/2+1, colLeft, m_colLabelHeight - 1 );
        dc.DrawLine( colLeft, m_colLabelHeight/2+1, colRight, m_colLabelHeight/2+1 );

        dc.SetBackgroundMode( wxTRANSPARENT );
        dc.SetTextForeground( GetLabelTextColour() );
        dc.SetFont( GetLabelFont() );

        int hAlign, vAlign, orient;
        GetColLabelAlignment( &hAlign, &vAlign );
        orient = GetColLabelTextOrientation();

        rect.SetX( colLeft + 2 );
        rect.SetY( m_colLabelHeight/2+2 );
        rect.SetWidth( GetColWidth(col) - 4 );
        rect.SetHeight( m_colLabelHeight/2 - 4 );
        DrawTextRectangle( dc, GetColLabelValue( col ), rect, hAlign, vAlign, orient );
    }
    else
    {
        int colLeft = GetColLeft(col);
        wxRect rect;
        int colRight = GetColRight(col) - 1;

        dc.SetPen( wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW), 1, wxSOLID) );
        dc.DrawLine( colRight, 0, colRight, m_colLabelHeight - 1 );
        dc.DrawLine( colLeft, 0, colRight, 0 );
        dc.DrawLine( colLeft, m_colLabelHeight - 1,
                     colRight + 1, m_colLabelHeight - 1 );

        dc.SetPen( *wxWHITE_PEN );
        dc.DrawLine( colLeft, 1, colLeft, m_colLabelHeight - 1 );
        dc.DrawLine( colLeft, 1, colRight, 1 );

        dc.SetBackgroundMode( wxTRANSPARENT );
        dc.SetTextForeground( GetLabelTextColour() );
        dc.SetFont( GetLabelFont() );

        int hAlign, vAlign, orient;
        GetColLabelAlignment( &hAlign, &vAlign );
        orient = GetColLabelTextOrientation();

        rect.SetX( colLeft + 2 );
        rect.SetY( 2 );
        rect.SetWidth( GetColWidth(col) - 4 );
        rect.SetHeight( m_colLabelHeight - 4 );
        DrawTextRectangle( dc, GetColLabelValue( col ), rect, hAlign, vAlign, orient );
    }
}


