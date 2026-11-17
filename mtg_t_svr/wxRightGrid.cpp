#include "wx_pch.h"
#include "wxRightGrid.h"
#include "wx/clipbrd.h"

const wxEventType wxEVT_MENU_DEL_COMMAND = wxNewEventType();
const wxEventType wxEVT_MENU_INSERT_COMMAND = wxNewEventType();
const wxEventType wxEVT_MENU_CLEAR_COMMAND = wxNewEventType();
const wxEventType wxEVT_MENU_STICK_COMMAND = wxNewEventType();
const wxEventType wxEVT_MENU_SELALL_COMMAND = wxNewEventType();

wxRightGrid::wxRightGrid(wxWindow *parent,
                         wxWindowID id,
                         const wxPoint& pos,
                         const wxSize& size ,
                         long style,
                         const wxString& name ):wxGrid(parent,id,pos,size,style,name)
{
    SetDefaultCellAlignment(wxALIGN_RIGHT,wxALIGN_CENTRE);
    //ctor this->Connect(wxEVT_SIZE,(wxObjectEventFunction)&mtg_t_svrFrame::OnSize,0,this);
    Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&wxRightGrid::OnEnterDown);
    Connect(wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&wxRightGrid::OnLeftClick);
    Connect(wxEVT_GRID_CELL_RIGHT_CLICK,(wxObjectEventFunction)&wxRightGrid::OnRightClick);
    //Connect(wxEVT_GRID_EDITOR_SHOWN,(wxObjectEventFunction)&wxRightGrid::OnEditorShown);
    //Connect(wxEVT_GRID_EDITOR_HIDDEN,(wxObjectEventFunction)&wxRightGrid::OnEditorHidden);
    Connect(ID_MENU_DEL,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxRightGrid::OnMenuDel);
    Connect(ID_MENU_INSERT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxRightGrid::OnMenuInsert);
    Connect(ID_MENU_CLEAR,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxRightGrid::OnMenuClear);
    Connect(ID_MENU_STICK,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxRightGrid::OnMenuStick);
    Connect(ID_MENU_COPY,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxRightGrid::OnMenuCopy);
    Connect(ID_MENU_SELALL,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxRightGrid::OnMenuSel);
    m_row=-1;
    m_col=-1;
    _io = true;
    _stick=true;
    _clear=true;
    _selall=false;
    check=false;
    _autorow=true;
    _copy=true;
    _insert=true;
    _delete=true;
}

wxRightGrid::~wxRightGrid()
{
    //dtor
}

void wxRightGrid::GridEnable(bool e)
{
    _io = e;
}

void wxRightGrid::GridStick(bool e)
{
    _stick = e;
}

void wxRightGrid::GridClear(bool e)
{
    _clear = e;
}

void wxRightGrid::GridSelAll(bool e)
{
    _selall = e;
}

void wxRightGrid::AtuoAddRow(bool e)
{
    _autorow = e;
}

void wxRightGrid::GridCopy(bool e)
{
    _copy = e;
}

void wxRightGrid::GridInsert(bool e)
{
    _insert= e;
}

void wxRightGrid::GridDelete(bool e)
{
    _delete = e;
}

void wxRightGrid::OnLeftClick(wxGridEvent& event)
{
    int row=event.GetRow();
    int col=event.GetCol();
    int n=GetNumberRows();
    int m=GetNumberCols();
    wxString cellstr;
    if(_autorow)
    {
        if(row==n-1 && _io)
        {
            int i=0;
            for(i=0;i<m;i++)
            {
                cellstr = GetCellValue(row,i);
                if(!cellstr.IsEmpty())
                {
                    break;
                }
            }
            if(i<m)
            {
                AppendRows();
                wxCommandEvent e(wxEVT_MENU_INSERT_COMMAND);
                wxPostEvent(this, e);
            }
        }
        else if(row<n-2 && row>=0 && _io)
        {
            int row1=row;
            for(int i=row+1;i<n;i++)
            {
                int j=0;
                for(j=0;j<m;j++)
                {
                    cellstr = GetCellValue(i,j);
                    if(!cellstr.IsEmpty())
                    {
                        break;
                    }
                }
                if(j<m)
                {
                    row1++;
                }
            }
            if(row1<n-1)
            {
                DeleteRows(row1+1,n-row1-1);
                wxCommandEvent e(wxEVT_MENU_DEL_COMMAND);
                wxPostEvent(this, e);
            }///whq2014-11-20删除该句
        }
    }
    /*else
    {
        if(row==n-2 && _io)
        {
            int i=0;
            for(i=0;i<m;i++)
            {
                cellstr = GetCellValue(row,i);
                if(!cellstr.IsEmpty())
                {
                    break;
                }
            }
            if(i<m)
            {
                InsertRows(row+1,1,true);
                //AppendRows();
                wxCommandEvent e(wxEVT_MENU_INSERT_COMMAND);
                wxPostEvent(this, e);
            }
        }
        else if(row<n-2 && row>=0 && _io)
        {
            int row1=row;
            for(int i=row+1;i<n-1;i++)
            {
                int j=0;
                for(j=0;j<m;j++)
                {
                    cellstr = GetCellValue(i,j);
                    if(!cellstr.IsEmpty())
                    {
                        break;
                    }
                }
                if(j<m)
                {
                    row1++;
                }
            }
            if(row1<n-1 && row1>row)
            {
                DeleteRows(row1+1,n-row1-2,true);
                wxCommandEvent e(wxEVT_MENU_DEL_COMMAND);
                wxPostEvent(this, e);
            }
        }
    }*/

    SetCurrentCell(row,col);
    ShowCellEditControl();
    event.Skip();
}

void wxRightGrid::OnEditorShown(wxGridEvent& event)
{
    event.Skip();
}

void wxRightGrid::OnEditorHidden(wxGridEvent& event)
{
    event.Skip();
}
void wxRightGrid::OnRightClick(wxGridEvent& event)
{
    ///判断是否选中
    m_row = event.GetRow();
    m_col = event.GetCol();
    SetGridCursor(m_row,m_col);
    wxMenu* menu=new wxMenu();
    wxMenuItem* item1=new wxMenuItem(menu,ID_MENU_INSERT,_("插入"));
    wxMenuItem* item2=new wxMenuItem(menu,ID_MENU_DEL,_("删除"));
    wxMenuItem* item3=new wxMenuItem(menu,ID_MENU_COPY,_("复制"));
    wxMenuItem* item4=new wxMenuItem(menu,ID_MENU_STICK,_("粘帖"));
    wxMenuItem* item5=new wxMenuItem(menu,ID_MENU_CLEAR,_("清空"));
    wxMenuItem* item6;
    if(check)
    {
        item6 = new wxMenuItem(menu,ID_MENU_SELALL,_("反全选"));
    }
    else
    {
        item6 = new wxMenuItem(menu,ID_MENU_SELALL,_("全选"));
    }
    /*if(_io)
    {
        menu->Append(item1);
        menu->Append(item2);
    }*/
    if(_copy)
    {
        menu->Append(item3);
    }
    if(_stick)
    {
        menu->Append(item4);
    }
    if(_clear)
    {
        menu->Append(item5);
    }
    if(_selall)
    {
        menu->Append(item6);
    }

    if(_insert)
    {
        menu->Append(item1);
    }

    if(_delete)
    {
        menu->Append(item2);
    }
    PopupMenu(menu,event.GetPosition());
    event.Skip();
}

void wxRightGrid::OnEnterDown(wxKeyEvent& event)
{
    int ch = event.GetKeyCode();
    if (ch == WXK_RETURN)
    {
        int nRow = GetNumberRows();
        int nCol = GetNumberCols();
        int x = GetGridCursorRow();
        int y = GetGridCursorCol();
        if((x==nRow-1) && (y==nCol-1) && _io)
        {
            AppendRows(1);
            wxCommandEvent e(wxEVT_MENU_INSERT_COMMAND);
            wxPostEvent(this, e);
            SetGridCursor(x,0);
        }
        else if(y == nCol-1)
        {
            SetGridCursor(x,0);
        }
        else
        {
            SetGridCursor(x-1,y+1);
        }
    }
    else if(event.ControlDown())
    {
        if(ch == 'A')
        {
            SelectAll();
        }
        else if( ch == 'C')
        {
            wxCommandEvent e;
            OnMenuCopy(e);
        }
        else if( ch == 'V' && _stick)
        {
            wxCommandEvent e;
            OnMenuStick(e);
        }
    }
    else if(ch==WXK_DELETE && _clear)
    {
        wxGridCellCoordsArray tl=GetSelectionBlockTopLeft();
        wxGridCellCoordsArray br=GetSelectionBlockBottomRight();
        int row,col;
        wxString str;
        if(tl.IsEmpty() || br.IsEmpty())
        {
            row = GetCursorRow();
            col = GetCursorColumn();
            SetCellValue(row,col,_(""));
        }
        else
        {
            row = br[0].GetRow() - tl[0].GetRow() + 1;
            col = br[0].GetCol() - tl[0].GetCol() + 1;
            for(int i=tl[0].GetRow(); i<=br[0].GetRow(); i++)
            {
                for(int j=tl[0].GetCol(); j<=br[0].GetCol(); j++)
                {
                    SetCellValue(i,j,_(""));
                }
            }
        }
    }
    event.Skip();
}

void wxRightGrid::OnMenuDel(wxCommandEvent& event)
{
    if(m_col!=-1 && m_row!=-1 && _io)
    {
		if(m_row == GetNumberRows()-1)return;
        if(GetNumberRows()==1)
        {
            ClearGrid();
        }
        else
        {
            DeleteRows(m_row,1);
        }
        wxCommandEvent e(wxEVT_MENU_DEL_COMMAND);
        wxPostEvent(this, e);
    }
}

void wxRightGrid::OnMenuInsert(wxCommandEvent& event)
{
    if(!_io) return;
    int row = GetCursorRow();
    InsertRows(row,1);
    wxCommandEvent e(wxEVT_MENU_INSERT_COMMAND);
    wxPostEvent(this, e);
}

void wxRightGrid::OnMenuClear(wxCommandEvent& event)
{
    int n = GetNumberRows();
    ClearGrid();
    if(_io)
    {
        DeleteRows(0,n-1);
    }
    wxCommandEvent e(wxEVT_MENU_CLEAR_COMMAND);
    wxPostEvent(this, e);
}

void wxRightGrid::OnMenuCopy(wxCommandEvent& event)
{
    wxGridCellCoordsArray tl=GetSelectionBlockTopLeft();
    wxGridCellCoordsArray br=GetSelectionBlockBottomRight();
    int row,col;
    wxString str;
    if(tl.IsEmpty() || br.IsEmpty())
    {
        row = GetCursorRow();
        col = GetCursorColumn();
        str = GetCellValue(row,col);
    }
    else
    {
        row = br[0].GetRow() - tl[0].GetRow() + 1;
        col = br[0].GetCol() - tl[0].GetCol() + 1;
        for(int i=tl[0].GetRow(); i<=br[0].GetRow(); i++)
        {
            for(int j=tl[0].GetCol(); j<=br[0].GetCol(); j++)
            {
                str += GetCellValue(i,j);
                if(j==br[0].GetCol())
                {
                    str +=_("\n");
                }
                else
                {
                    str += _(",");
                }
            }
        }
    }
    if(!str.IsEmpty())
    {
        if(wxTheClipboard->Open())
        {
            wxTheClipboard->SetData(new wxTextDataObject(str));
            wxTheClipboard->Close();
        }
    }
}

void wxRightGrid::OnMenuStick(wxCommandEvent& event)
{
    int rows = GetNumberRows();
    int cols = GetNumberCols();
    int row = GetCursorRow();
    int col = GetCursorColumn();
    wxString str;
    wxArrayString strs;
    wxString c,s;

    wxGridCellCoordsArray tl=GetSelectionBlockTopLeft();
    if(!tl.IsEmpty())
    {
        row = tl[0].GetRow();
        col = tl[0].GetCol();
    }

    if(wxTheClipboard->Open())
    {
        if(wxTheClipboard->IsSupported(wxDF_TEXT))
        {
            wxTextDataObject data;
            wxTheClipboard->GetData(data);
            str = data.GetText();
        }
    }
    str.Replace(_("\r"),_(""));
    wxTheClipboard->Close();
    int n=0,k=0;
    int i,j,ii=0;
    int len=0;
    if(!str.IsEmpty())
    {
        len = str.Length();
        for(i=0;i<len;i++)
        {
            c=str.Mid(i,1);
            if(c==_("\n"))
            {
                s = str.Mid(k,i-k);
                if(!s.IsEmpty())strs.Add(s);
                k=i+1;
            }
            else if(i==len-1)
            {
                s = str.Mid(k);
                if(!s.IsEmpty())strs.Add(s);
            }
        }

        n=strs.Count();
        if(n>(rows-row))
        {
            if(_io)
                AppendRows(n-rows+row);
            else
                n = rows-row;
        }

        for(i=0;i<n;i++)
        {
            str = strs[i];
            len = str.Length();
            k=0;
            ii=0;
            for(j=0;j<len;j++)
            {
                c = str.Mid(j,1);
                if(ii>(cols-col-1))break;
                if(c==_("\t") || c==_(","))
                {
                    SetCellValue(row+i,col+ii,str.Mid(k,j-k));
                    k=j+1;
                    ii++;
                }
                else if(j== len-1)
                {
                    SetCellValue(row+i,col+ii,str.Mid(k));
                    ii++;
                }
            }
        }
        wxCommandEvent e(wxEVT_MENU_STICK_COMMAND);
        wxPostEvent(this,e);
    }
}

void wxRightGrid::OnMenuSel(wxCommandEvent& event)
{
    int i,n,col;
    n = GetNumberRows();
    col = GetNumberCols()-1;
    if(!check)
    {
        for(i=0;i<n;i++)
        {
            SetCellValue(i,col,_("1"));
        }
        check=true;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            SetCellValue(i,col,_(""));
        }
        check=false;
    }
    wxCommandEvent e(wxEVT_MENU_SELALL_COMMAND);
    wxPostEvent(this,e);
}

void wxRightGrid::MergeColum(const wxString& str,int start,int end)
{
    MergeInfo *pInfo=new MergeInfo;
    pInfo->m_start=start;
    pInfo->m_end=end;
    pInfo->m_title=str;
    m_arrayMergeCol.Add(pInfo);
}


void wxRightGrid::DrawColLabels( wxDC& dc,const wxArrayInt& cols )
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
}

void wxRightGrid::DrawColLabel( wxDC& dc, int col )
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

