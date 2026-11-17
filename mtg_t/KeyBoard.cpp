///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug 25 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "KeyBoard.h"
#include "wxMyTextCtrl.h"

///////////////////////////////////////////////////////////////////////////

KeyBoard::KeyBoard( wxWindow* parent, wxTextCtrl* ctrl )
{
    Create( parent,-1,_("键盘") ,wxDefaultPosition,wxDefaultSize,wxSTAY_ON_TOP | wxBORDER_RAISED);
	SetClientSize(wxSize(360,240));
	int w=272;
	int h=222;
	keyPanel = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(w,h), wxTAB_TRAVERSAL, _T("wxID_ANY"));
	keyPanel->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

	keyPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&KeyBoard::OnPaintKey,0,this);
	keyPanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&KeyBoard::OnMotionKey,0,this);
	keyPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&KeyBoard::OnKeyClicked,0,this);
	keyPanel->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&KeyBoard::OnKeyMouseDown,0,this);
	keyPanel->Connect(wxEVT_LEAVE_WINDOW,(wxObjectEventFunction)&KeyBoard::OnLeaveKey,0,this);

    inMode=ID_KEY_IN_123;
    inStep=ID_KEY_STEP_SET;
    keyCaps=ID_KEY_CAP_NLOCK;
    bracketPosition=ID_KEY_BRACKET_FRONT;

	m_pTextCtrl=ctrl;
}

KeyBoard::~KeyBoard()
{
	// Disconnect Events


	//this->Disconnect(ID_BUTTON_0,ID_BUTTON_11,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler( KeyBoard::OnBtnClick ),NULL,this);
    //this->Disconnect(ID_STATIC_0,ID_STATIC_5,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler( KeyBoard::OnBtnClick1 ),NULL,this);
}

void KeyBoard::OnPaintKey(wxPaintEvent& event)
{
    wxPaintDC dc(keyPanel);
    int w,h;
    keyPanel->GetSize(&w,&h);
    wxBitmap m_memBit;
    m_memBit.Create(w,h);
    if(m_memBit.IsOk())
    {
        wxMemoryDC memDC;
        memDC.SelectObject(m_memBit);
         ///background
        memDC.SetPen(wxPen(wxColor(124,124,124)));
        memDC.SetBrush(wxBrush(wxColor(124,124,124)));
        memDC.DrawRectangle(0,0,w,h);

        wxFont chs(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_("Arial"),wxFONTENCODING_DEFAULT);
        memDC.SetFont(chs);
        memDC.SetTextForeground(wxColor(33,33,33));

        ///画顶部
        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.SetBrush(wxBrush(wxColor(224,224,224)));
        memDC.DrawRectangle(0,0,w,36);
        int x1,y1,w1,h1;
        int x2,y2,w2,h2;

        x1=0;
        y1=0;
        w1=48;
        h1=36;
        keyButton[ID_KEY_CAPTION].x=x1;
        keyButton[ID_KEY_CAPTION].y=y1;
        keyButton[ID_KEY_CAPTION].width=w1;
        keyButton[ID_KEY_CAPTION].height=h1;

        w2=7;
        h2=7;
        x2=x1+w1/2-w2-2;
        y2=y1+h1/2-h2-2;
        memDC.SetPen(wxPen(wxColor(117,117,117)));
        memDC.DrawRectangle(x2,y2,w2,h2);
        memDC.DrawRectangle(x2+w2+4,y2,w2,h2);
        memDC.DrawRectangle(x2,y2+h2+4,w2,h2);
        memDC.DrawRectangle(x2+w2+4,y2+h2+4,w2,h2);

        x2=x1+w1;
        y2=y1;
        w2=174;
        h2=h1;
        keyButton[ID_KEY_MODE].x=x2+1;
        keyButton[ID_KEY_MODE].y=y2+1;
        keyButton[ID_KEY_MODE].width=w2-2;
        keyButton[ID_KEY_MODE].height=h2-2;
        memDC.SetPen(wxPen(wxColor(192,192,192)));
        memDC.DrawLine(x2,y2+3,x2,y2+h2-3);
        memDC.DrawLine(x2+w2,y2+3,x2+w2,y2+h2-3);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x2+1,y2+3,x2+1,y2+h2-3);
        memDC.DrawLine(x2+w2+1,y2+3,x2+w2+1,y2+h2-3);
        if(motion==ID_KEY_MODE)
        {
            memDC.SetPen(wxPen(wxColor(255,255,0)));
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.DrawRectangle(keyButton[ID_KEY_MODE]);
        }
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("123"),keyButton[ID_KEY_MODE],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("ABC"),keyButton[ID_KEY_MODE],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        x2=x2+w2;
        w2=48;
        keyButton[ID_KEY_CLOSE].x=x2+1;
        keyButton[ID_KEY_CLOSE].y=y2+1;
        keyButton[ID_KEY_CLOSE].width=w2-2;
        keyButton[ID_KEY_CLOSE].height=h2-2;
        if(motion==ID_KEY_CLOSE)
        {
            memDC.SetPen(wxPen(wxColor(255,255,0)));
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.DrawRectangle(keyButton[ID_KEY_CLOSE]);
        }
        memDC.SetTextForeground(wxColor(255,0,0));
        memDC.DrawLabel(_("▼"),keyButton[ID_KEY_CLOSE],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        memDC.SetTextForeground(wxColor(33,33,33));

        x2=2;
        y2=y2+h2+2;
        w2=w2-4;
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.SetBrush(wxBrush(wxColor(224,224,224)));
        memDC.DrawRoundedRectangle(x2,y2,w2,182,3);

        h2=45;
        keyButton[ID_KEY_MARK_2].x=x2+1;
        keyButton[ID_KEY_MARK_2].y=y2+1;
        keyButton[ID_KEY_MARK_2].width=w2-2;
        keyButton[ID_KEY_MARK_2].height=h2-2;
        keyButton[ID_KEY_MARK_3].x=x2+1;
        keyButton[ID_KEY_MARK_3].y=y2+h2+1;
        keyButton[ID_KEY_MARK_3].width=w2-2;
        keyButton[ID_KEY_MARK_3].height=h2-2;
        keyButton[ID_KEY_MARK_4].x=x2+1;
        keyButton[ID_KEY_MARK_4].y=y2+h2*2+1;
        keyButton[ID_KEY_MARK_4].width=w2-2;
        keyButton[ID_KEY_MARK_4].height=h2-2;
        keyButton[ID_KEY_MARK_5].x=x2+1;
        keyButton[ID_KEY_MARK_5].y=y2+h2*3+1;
        keyButton[ID_KEY_MARK_5].width=w2-2;
        keyButton[ID_KEY_MARK_5].height=h2-2;
        keyButton[ID_KEY_MARK_6].x=x2+1;
        keyButton[ID_KEY_MARK_6].y=y2+h2*4+1;
        keyButton[ID_KEY_MARK_6].width=w2-2;
        keyButton[ID_KEY_MARK_6].height=h2-2;
        memDC.SetPen(wxPen(wxColor(201,201,201)));
        memDC.DrawLine(x2+4,y2+h2-1,x2+w2-4,y2+h2-1);
        memDC.DrawLine(x2+4,y2+h2*2-1,x2+w2-4,y2+h2*2-1);
        memDC.DrawLine(x2+4,y2+h2*3-1,x2+w2-4,y2+h2*3-1);
        //memDC.DrawLine(x2+4,y2+h2*4-1,x2+w2-4,y2+h2*4-1);
        memDC.SetPen(wxPen(wxColor(255,255,255)));
        memDC.DrawLine(x2+4,y2+h2,x2+w2-4,y2+h2);
        memDC.DrawLine(x2+4,y2+h2*2,x2+w2-4,y2+h2*2);
        memDC.DrawLine(x2+4,y2+h2*3,x2+w2-4,y2+h2*3);
        //memDC.DrawLine(x2+4,y2+h2*4,x2+w2-4,y2+h2*4);
        if(motion==ID_KEY_MARK_2)
        {
            memDC.SetPen(wxPen(wxColor(255,255,0)));
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.DrawRectangle(keyButton[ID_KEY_MARK_2]);
        }
        memDC.DrawLabel(_("_"),keyButton[ID_KEY_MARK_2],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        if(motion==ID_KEY_MARK_3)
        {
            memDC.SetPen(wxPen(wxColor(255,255,0)));
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.DrawRectangle(keyButton[ID_KEY_MARK_3]);
        }
        memDC.DrawLabel(_("'"),keyButton[ID_KEY_MARK_3],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        if(motion==ID_KEY_MARK_4)
        {
            memDC.SetPen(wxPen(wxColor(255,255,0)));
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.DrawRectangle(keyButton[ID_KEY_MARK_4]);
        }
        memDC.DrawLabel(_("\""),keyButton[ID_KEY_MARK_4],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        if(motion==ID_KEY_MARK_5)
        {
            memDC.SetPen(wxPen(wxColor(255,255,0)));
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.DrawRectangle(keyButton[ID_KEY_MARK_5]);
        }
        if(bracketPosition==ID_KEY_BRACKET_FRONT)
        {
            memDC.DrawLabel(_("("),keyButton[ID_KEY_MARK_5],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_(")"),keyButton[ID_KEY_MARK_5],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        memDC.SetPen(wxPen(wxColor(255,255,255)));
        x2=x2+w2+5;
        w2=55;
        h2=44;
        keyButton[ID_KEY_BTN_0].x=x2;
        keyButton[ID_KEY_BTN_0].y=y2;
        keyButton[ID_KEY_BTN_0].width=w2;
        keyButton[ID_KEY_BTN_0].height=h2;
        if(motion==ID_KEY_BTN_0)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(224,224,224)));
        }
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BTN_0],3);
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("1"),keyButton[ID_KEY_BTN_0],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(keyCaps==ID_KEY_CAP_NLOCK)
            {
                if(keyExpand==ID_KEY_BTN_0)
                {
                    memDC.DrawLabel(_("a"),keyButton[ID_KEY_BTN_0],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_1)
                {
                    memDC.DrawLabel(_("d"),keyButton[ID_KEY_BTN_0],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_2)
                {
                    memDC.DrawLabel(_("g"),keyButton[ID_KEY_BTN_0],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("abc"),keyButton[ID_KEY_BTN_0],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_0)
                {
                    memDC.DrawLabel(_("A"),keyButton[ID_KEY_BTN_0],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_1)
                {
                    memDC.DrawLabel(_("D"),keyButton[ID_KEY_BTN_0],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_2)
                {
                    memDC.DrawLabel(_("G"),keyButton[ID_KEY_BTN_0],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("ABC"),keyButton[ID_KEY_BTN_0],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
        }

        y2=keyButton[ID_KEY_BTN_0].y+h2+2;
        keyButton[ID_KEY_BTN_3].x=x2;
        keyButton[ID_KEY_BTN_3].y=y2;
        keyButton[ID_KEY_BTN_3].width=w2;
        keyButton[ID_KEY_BTN_3].height=h2;
        if(motion==ID_KEY_BTN_3)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(224,224,224)));
        }
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BTN_3],3);
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("4"),keyButton[ID_KEY_BTN_3],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(keyCaps==ID_KEY_CAP_NLOCK)
            {
                if(keyExpand==ID_KEY_BTN_3)
                {
                    memDC.DrawLabel(_("j"),keyButton[ID_KEY_BTN_3],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_4)
                {
                    memDC.DrawLabel(_("m"),keyButton[ID_KEY_BTN_3],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_5)
                {
                    memDC.DrawLabel(_("p"),keyButton[ID_KEY_BTN_3],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("jkl"),keyButton[ID_KEY_BTN_3],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_3)
                {
                    memDC.DrawLabel(_("J"),keyButton[ID_KEY_BTN_3],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_4)
                {
                    memDC.DrawLabel(_("M"),keyButton[ID_KEY_BTN_3],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_5)
                {
                    memDC.DrawLabel(_("P"),keyButton[ID_KEY_BTN_3],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("JKL"),keyButton[ID_KEY_BTN_3],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
        }
        y2=keyButton[ID_KEY_BTN_3].y+h2+2;
        keyButton[ID_KEY_BTN_6].x=x2;
        keyButton[ID_KEY_BTN_6].y=y2;
        keyButton[ID_KEY_BTN_6].width=w2;
        keyButton[ID_KEY_BTN_6].height=h2;
        if(motion==ID_KEY_BTN_6)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(224,224,224)));
        }
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BTN_6],3);
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("7"),keyButton[ID_KEY_BTN_6],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(keyCaps==ID_KEY_CAP_NLOCK)
            {
                if(keyExpand==ID_KEY_BTN_6)
                {
                    memDC.DrawLabel(_("s"),keyButton[ID_KEY_BTN_6],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_7)
                {
                    memDC.DrawLabel(_("v"),keyButton[ID_KEY_BTN_6],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("stu"),keyButton[ID_KEY_BTN_6],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_6)
                {
                    memDC.DrawLabel(_("S"),keyButton[ID_KEY_BTN_6],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_7)
                {
                    memDC.DrawLabel(_("V"),keyButton[ID_KEY_BTN_6],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("STU"),keyButton[ID_KEY_BTN_6],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
        }

        y2=keyButton[ID_KEY_BTN_6].y+h2+2;
        keyButton[ID_KEY_BTN_9].x=x2;
        keyButton[ID_KEY_BTN_9].y=y2;
        keyButton[ID_KEY_BTN_9].width=w2+w2+2;
        keyButton[ID_KEY_BTN_9].height=h2;
        if(motion==ID_KEY_BTN_9)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        }
        else
        {
            if(inMode==ID_KEY_IN_ABC && keyCaps==ID_KEY_CAP_LOCK)
            {
                memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            }
            else
            {
                memDC.SetBrush(wxBrush(wxColor(224,224,224)));
            }
        }
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BTN_9],3);
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("0"),keyButton[ID_KEY_BTN_9],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            memDC.DrawLabel(_("CAPS"),keyButton[ID_KEY_BTN_9],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }

        y2=keyButton[ID_KEY_BTN_0].y;
        x2=keyButton[ID_KEY_BTN_0].x+w2+2;
        keyButton[ID_KEY_BTN_1].x=x2;
        keyButton[ID_KEY_BTN_1].y=y2;
        keyButton[ID_KEY_BTN_1].width=w2;
        keyButton[ID_KEY_BTN_1].height=h2;
        if(motion==ID_KEY_BTN_1)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(224,224,224)));
        }
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BTN_1],3);
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("2"),keyButton[ID_KEY_BTN_1],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(keyCaps==ID_KEY_CAP_NLOCK)
            {
                if(keyExpand==ID_KEY_BTN_0)
                {
                    memDC.DrawLabel(_("b"),keyButton[ID_KEY_BTN_1],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_1)
                {
                    memDC.DrawLabel(_("e"),keyButton[ID_KEY_BTN_1],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_2)
                {
                    memDC.DrawLabel(_("h"),keyButton[ID_KEY_BTN_1],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("def"),keyButton[ID_KEY_BTN_1],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_0)
                {
                    memDC.DrawLabel(_("B"),keyButton[ID_KEY_BTN_1],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_1)
                {
                    memDC.DrawLabel(_("E"),keyButton[ID_KEY_BTN_1],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_2)
                {
                    memDC.DrawLabel(_("H"),keyButton[ID_KEY_BTN_1],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("DEF"),keyButton[ID_KEY_BTN_1],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
        }

        y2=keyButton[ID_KEY_BTN_1].y+h2+2;
        keyButton[ID_KEY_BTN_4].x=x2;
        keyButton[ID_KEY_BTN_4].y=y2;
        keyButton[ID_KEY_BTN_4].width=w2;
        keyButton[ID_KEY_BTN_4].height=h2;
        if(motion==ID_KEY_BTN_4)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(224,224,224)));
        }
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BTN_4],3);
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("5"),keyButton[ID_KEY_BTN_4],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(keyCaps==ID_KEY_CAP_NLOCK)
            {
                if(keyExpand==ID_KEY_BTN_3)
                {
                    memDC.DrawLabel(_("k"),keyButton[ID_KEY_BTN_4],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_4)
                {
                    memDC.DrawLabel(_("n"),keyButton[ID_KEY_BTN_4],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_5)
                {
                    memDC.DrawLabel(_("q"),keyButton[ID_KEY_BTN_4],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("mno"),keyButton[ID_KEY_BTN_4],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }

            }
            else
            {
                if(keyExpand==ID_KEY_BTN_3)
                {
                    memDC.DrawLabel(_("K"),keyButton[ID_KEY_BTN_4],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_4)
                {
                    memDC.DrawLabel(_("N"),keyButton[ID_KEY_BTN_4],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_5)
                {
                    memDC.DrawLabel(_("Q"),keyButton[ID_KEY_BTN_4],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("MNO"),keyButton[ID_KEY_BTN_4],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
        }

        y2=keyButton[ID_KEY_BTN_4].y+h2+2;
        keyButton[ID_KEY_BTN_7].x=x2;
        keyButton[ID_KEY_BTN_7].y=y2;
        keyButton[ID_KEY_BTN_7].width=w2;
        keyButton[ID_KEY_BTN_7].height=h2;
        if(motion==ID_KEY_BTN_7)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(224,224,224)));
        }
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BTN_7],3);
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("8"),keyButton[ID_KEY_BTN_7],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(keyCaps==ID_KEY_CAP_NLOCK)
            {
                if(keyExpand==ID_KEY_BTN_6)
                {
                    memDC.DrawLabel(_("t"),keyButton[ID_KEY_BTN_7],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_7)
                {
                    memDC.DrawLabel(_("w"),keyButton[ID_KEY_BTN_7],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_8)
                {
                    memDC.DrawLabel(_("y"),keyButton[ID_KEY_BTN_7],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("vwx"),keyButton[ID_KEY_BTN_7],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }

            }
            else
            {
                if(keyExpand==ID_KEY_BTN_6)
                {
                    memDC.DrawLabel(_("T"),keyButton[ID_KEY_BTN_7],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_7)
                {
                    memDC.DrawLabel(_("W"),keyButton[ID_KEY_BTN_7],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_8)
                {
                    memDC.DrawLabel(_("Y"),keyButton[ID_KEY_BTN_7],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("VWX"),keyButton[ID_KEY_BTN_7],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
        }

        y2=keyButton[ID_KEY_BTN_1].y;
        x2=keyButton[ID_KEY_BTN_1].x+w2+2;
        keyButton[ID_KEY_BTN_2].x=x2;
        keyButton[ID_KEY_BTN_2].y=y2;
        keyButton[ID_KEY_BTN_2].width=w2;
        keyButton[ID_KEY_BTN_2].height=h2;
        if(motion==ID_KEY_BTN_2)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(224,224,224)));
        }
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BTN_2],3);
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("3"),keyButton[ID_KEY_BTN_2],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(keyCaps==ID_KEY_CAP_NLOCK)
            {
                if(keyExpand==ID_KEY_BTN_0)
                {
                    memDC.DrawLabel(_("c"),keyButton[ID_KEY_BTN_2],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_1)
                {
                    memDC.DrawLabel(_("f"),keyButton[ID_KEY_BTN_2],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_2)
                {
                    memDC.DrawLabel(_("i"),keyButton[ID_KEY_BTN_2],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("ghi"),keyButton[ID_KEY_BTN_2],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }

            }
            else
            {
                if(keyExpand==ID_KEY_BTN_0)
                {
                    memDC.DrawLabel(_("C"),keyButton[ID_KEY_BTN_2],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_1)
                {
                    memDC.DrawLabel(_("F"),keyButton[ID_KEY_BTN_2],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_2)
                {
                    memDC.DrawLabel(_("I"),keyButton[ID_KEY_BTN_2],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("GHI"),keyButton[ID_KEY_BTN_2],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
        }

        y2=keyButton[ID_KEY_BTN_2].y+h2+2;
        keyButton[ID_KEY_BTN_5].x=x2;
        keyButton[ID_KEY_BTN_5].y=y2;
        keyButton[ID_KEY_BTN_5].width=w2;
        keyButton[ID_KEY_BTN_5].height=h2;
        if(motion==ID_KEY_BTN_5)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(224,224,224)));
        }
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BTN_5],3);
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("6"),keyButton[ID_KEY_BTN_5],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(keyCaps==ID_KEY_CAP_NLOCK)
            {
                if(keyExpand==ID_KEY_BTN_3)
                {
                    memDC.DrawLabel(_("l"),keyButton[ID_KEY_BTN_5],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_4)
                {
                    memDC.DrawLabel(_("o"),keyButton[ID_KEY_BTN_5],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_5)
                {
                    memDC.DrawLabel(_("r"),keyButton[ID_KEY_BTN_5],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("pqr"),keyButton[ID_KEY_BTN_5],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }

            }
            else
            {
                if(keyExpand==ID_KEY_BTN_3)
                {
                    memDC.DrawLabel(_("L"),keyButton[ID_KEY_BTN_5],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_4)
                {
                    memDC.DrawLabel(_("O"),keyButton[ID_KEY_BTN_5],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_5)
                {
                    memDC.DrawLabel(_("R"),keyButton[ID_KEY_BTN_5],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("PQR"),keyButton[ID_KEY_BTN_5],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
        }

        y2=keyButton[ID_KEY_BTN_5].y+h2+2;
        keyButton[ID_KEY_BTN_8].x=x2;
        keyButton[ID_KEY_BTN_8].y=y2;
        keyButton[ID_KEY_BTN_8].width=w2;
        keyButton[ID_KEY_BTN_8].height=h2;
        if(motion==ID_KEY_BTN_8)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(224,224,224)));
        }
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BTN_8],3);
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("9"),keyButton[ID_KEY_BTN_8],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(keyCaps==ID_KEY_CAP_NLOCK)
            {
                if(keyExpand==ID_KEY_BTN_6)
                {
                    memDC.DrawLabel(_("u"),keyButton[ID_KEY_BTN_8],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_7)
                {
                    memDC.DrawLabel(_("o"),keyButton[ID_KEY_BTN_8],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_8)
                {
                    memDC.DrawLabel(_("z"),keyButton[ID_KEY_BTN_8],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("yz"),keyButton[ID_KEY_BTN_8],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }

            }
            else
            {
                if(keyExpand==ID_KEY_BTN_6)
                {
                    memDC.DrawLabel(_("U"),keyButton[ID_KEY_BTN_8],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_7)
                {
                    memDC.DrawLabel(_("O"),keyButton[ID_KEY_BTN_8],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else if(keyExpand==ID_KEY_BTN_8)
                {
                    memDC.DrawLabel(_("Z"),keyButton[ID_KEY_BTN_8],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
                else
                {
                    memDC.DrawLabel(_("YZ"),keyButton[ID_KEY_BTN_8],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
                }
            }
        }

        y2=keyButton[ID_KEY_BTN_8].y+h2+2;
        keyButton[ID_KEY_BLANK].x=x2;
        keyButton[ID_KEY_BLANK].y=y2;
        keyButton[ID_KEY_BLANK].width=w2;
        keyButton[ID_KEY_BLANK].height=h2;

        if(motion==ID_KEY_BLANK)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(159,159,159)));
            memDC.SetTextForeground(wxColor(255,255,255));
        }
        memDC.SetPen(wxPen(wxColor(218,218,218)));
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BLANK],3);
        memDC.SetPen(wxPen(wxColor(138,138,138)));
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BLANK].x+1,keyButton[ID_KEY_BLANK].y+1,keyButton[ID_KEY_BLANK].width-2,keyButton[ID_KEY_BLANK].height-2,3);
        if(inMode==ID_KEY_IN_123)
        {
            memDC.DrawLabel(_("．"),keyButton[ID_KEY_BLANK],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }
        else
        {
            if(motion==ID_KEY_BLANK)
            {
                memDC.SetPen(wxPen(wxColor(58,58,58)));
            }
            else
            {
                memDC.SetPen(wxPen(wxColor(255,255,255)));
            }
            memDC.DrawLine(x2+w2/3,y2+h2/2,x2+w2/3,y2+h2/2+5);
            memDC.DrawLine(x2+w2/3,y2+h2/2+5,x2+w2*2/3,y2+h2/2+5);
            memDC.DrawLine(x2+w2*2/3,y2+h2/2+5,x2+w2*2/3,y2+h2/2);
            //memDC.DrawLabel(_("└┘"),keyButton[ID_KEY_BLANK],wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        }


        y2=keyButton[ID_KEY_BTN_2].y;
        x2=keyButton[ID_KEY_BTN_2].x+w2+5;
        w2=45;
        keyButton[ID_KEY_BREAK].x=x2;
        keyButton[ID_KEY_BREAK].y=y2;
        keyButton[ID_KEY_BREAK].width=w2;
        keyButton[ID_KEY_BREAK].height=h2;
        if(motion==ID_KEY_BREAK)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(159,159,159)));
            memDC.SetTextForeground(wxColor(255,255,255));
        }
        memDC.SetPen(wxPen(wxColor(218,218,218)));
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BREAK],3);
        memDC.SetPen(wxPen(wxColor(138,138,138)));
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_BREAK].x+1,keyButton[ID_KEY_BREAK].y+1,keyButton[ID_KEY_BREAK].width-2,keyButton[ID_KEY_BREAK].height-2,3);
        if(motion==ID_KEY_BREAK)
        {
            memDC.SetPen(wxPen(wxColor(58,58,58)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(255,255,255)));
        }

        memDC.DrawLine(x2+w2/3,y2+h2/2,x2+w2/3+5,y2+h2/2-5);
        memDC.DrawLine(x2+w2/3,y2+h2/2,x2+w2/3+5,y2+h2/2+5);
        memDC.DrawLine(x2+w2/3,y2+h2/2,x2+w2*2/3,y2+h2/2);

        y2=keyButton[ID_KEY_BREAK].y+h2+2;
        keyButton[ID_KEY_MARK_0].x=x2;
        keyButton[ID_KEY_MARK_0].y=y2;
        keyButton[ID_KEY_MARK_0].width=w2;
        keyButton[ID_KEY_MARK_0].height=h2;
        if(motion==ID_KEY_MARK_0)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
            memDC.SetTextForeground(wxColor(0,0,0));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(159,159,159)));
            memDC.SetTextForeground(wxColor(255,255,255));
        }
        memDC.SetPen(wxPen(wxColor(218,218,218)));
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_MARK_0],3);
        memDC.SetPen(wxPen(wxColor(138,138,138)));
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_MARK_0].x+1,keyButton[ID_KEY_MARK_0].y+1,keyButton[ID_KEY_MARK_0].width-2,keyButton[ID_KEY_MARK_0].height-2,3);

        memDC.DrawLabel(_("-"),wxRect(x2,y2,w2,h2),wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

        y2=keyButton[ID_KEY_MARK_0].y+h2+2;
        keyButton[ID_KEY_ENTER].x=x2;
        keyButton[ID_KEY_ENTER].y=y2;
        keyButton[ID_KEY_ENTER].width=w2;
        keyButton[ID_KEY_ENTER].height=h2*2+2;
        if(motion==ID_KEY_ENTER)
        {
            memDC.SetBrush(wxBrush(wxColor(255,255,0)));
        }
        else
        {
            memDC.SetBrush(wxBrush(wxColor(159,159,159)));
        }
        memDC.SetPen(wxPen(wxColor(218,218,218)));
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_ENTER],3);
        memDC.SetPen(wxPen(wxColor(138,138,138)));
        memDC.DrawRoundedRectangle(keyButton[ID_KEY_ENTER].x+1,keyButton[ID_KEY_ENTER].y+1,keyButton[ID_KEY_ENTER].width-2,keyButton[ID_KEY_ENTER].height-2,3);

        if(motion==ID_KEY_ENTER)
        {
            memDC.SetPen(wxPen(wxColor(58,58,58)));
        }
        else
        {
            memDC.SetPen(wxPen(wxColor(255,255,255)));
        }
        memDC.DrawLine(x2+w2/3,y2+h2,x2+w2/3+5,y2+h2-5);
        memDC.DrawLine(x2+w2/3,y2+h2,x2+w2/3+5,y2+h2+5);
        memDC.DrawLine(x2+w2/3,y2+h2,x2+w2*2/3,y2+h2);
        memDC.DrawLine(x2+w2*2/3,y2+h2,x2+w2*2/3,y2+h2-h2/2);

        dc.Blit(0,0,w,h,&memDC,0,0);
    }
}

void KeyBoard::OnMotionKey(wxMouseEvent& event)
{
    int x=event.GetX();
    int y=event.GetY();

    if(winMove==ID_KEY_WIN_MOVE)
    {
        this->GetScreenPosition(&m_x0,&m_y0);
        this->SetPosition(wxPoint(m_x0+x-m_x1,m_y0+y-m_y1));
    }
    else if(x>keyButton[ID_KEY_CAPTION].x && x<keyButton[ID_KEY_CAPTION].x+keyButton[ID_KEY_CAPTION].width)
    {
        if(y>keyButton[ID_KEY_CAPTION].y && y<keyButton[ID_KEY_CAPTION].y+keyButton[ID_KEY_CAPTION].height)
        {
            motion=ID_KEY_CAPTION;
        }
        else if(y>keyButton[ID_KEY_MARK_2].y && y<keyButton[ID_KEY_MARK_2].y+keyButton[ID_KEY_MARK_2].height)
        {
            motion=ID_KEY_MARK_2;
        }
        else if(y>keyButton[ID_KEY_MARK_3].y && y<keyButton[ID_KEY_MARK_3].y+keyButton[ID_KEY_MARK_3].height)
        {
            motion=ID_KEY_MARK_3;
        }
        else if(y>keyButton[ID_KEY_MARK_4].y && y<keyButton[ID_KEY_MARK_4].y+keyButton[ID_KEY_MARK_4].height)
        {
            motion=ID_KEY_MARK_4;
        }
        else if(y>keyButton[ID_KEY_MARK_5].y && y<keyButton[ID_KEY_MARK_5].y+keyButton[ID_KEY_MARK_5].height)
        {
            motion=ID_KEY_MARK_5;
        }
        else
        {
            motion=ID_KEY_NONE;
        }
    }
    else if(x>keyButton[ID_KEY_MODE].x && x<keyButton[ID_KEY_MODE].x+keyButton[ID_KEY_MODE].width)
    {
        if(y>keyButton[ID_KEY_MODE].y && y<keyButton[ID_KEY_MODE].y+keyButton[ID_KEY_MODE].height)
        {
            motion=ID_KEY_MODE;
        }
        else if(y>keyButton[ID_KEY_BTN_0].y && y<keyButton[ID_KEY_BTN_0].y+keyButton[ID_KEY_BTN_0].height)
        {
            if(x>keyButton[ID_KEY_BTN_0].x && x<keyButton[ID_KEY_BTN_0].x+keyButton[ID_KEY_BTN_0].width)
            {
                motion=ID_KEY_BTN_0;
            }
            else if(x>keyButton[ID_KEY_BTN_1].x && x<keyButton[ID_KEY_BTN_1].x+keyButton[ID_KEY_BTN_1].width)
            {
                motion=ID_KEY_BTN_1;
            }
            else if(x>keyButton[ID_KEY_BTN_2].x && x<keyButton[ID_KEY_BTN_2].x+keyButton[ID_KEY_BTN_2].width)
            {
                motion=ID_KEY_BTN_2;
            }
            else
            {
                motion=ID_KEY_NONE;
            }
        }
        else if(y>keyButton[ID_KEY_BTN_3].y && y<keyButton[ID_KEY_BTN_3].y+keyButton[ID_KEY_BTN_3].height)
        {
            if(x>keyButton[ID_KEY_BTN_3].x && x<keyButton[ID_KEY_BTN_3].x+keyButton[ID_KEY_BTN_3].width)
            {
                motion=ID_KEY_BTN_3;
            }
            else if(x>keyButton[ID_KEY_BTN_4].x && x<keyButton[ID_KEY_BTN_4].x+keyButton[ID_KEY_BTN_4].width)
            {
                motion=ID_KEY_BTN_4;
            }
            else if(x>keyButton[ID_KEY_BTN_5].x && x<keyButton[ID_KEY_BTN_5].x+keyButton[ID_KEY_BTN_5].width)
            {
                motion=ID_KEY_BTN_5;
            }
            else
            {
                motion=ID_KEY_NONE;
            }
        }
        else if(y>keyButton[ID_KEY_BTN_6].y && y<keyButton[ID_KEY_BTN_6].y+keyButton[ID_KEY_BTN_6].height)
        {
            if(x>keyButton[ID_KEY_BTN_6].x && x<keyButton[ID_KEY_BTN_6].x+keyButton[ID_KEY_BTN_6].width)
            {
                motion=ID_KEY_BTN_6;
            }
            else if(x>keyButton[ID_KEY_BTN_7].x && x<keyButton[ID_KEY_BTN_7].x+keyButton[ID_KEY_BTN_7].width)
            {
                motion=ID_KEY_BTN_7;
            }
            else if(x>keyButton[ID_KEY_BTN_8].x && x<keyButton[ID_KEY_BTN_8].x+keyButton[ID_KEY_BTN_8].width)
            {
                motion=ID_KEY_BTN_8;
            }
            else
            {
                motion=ID_KEY_NONE;
            }
        }
        else if(y>keyButton[ID_KEY_BTN_9].y && y<keyButton[ID_KEY_BTN_9].y+keyButton[ID_KEY_BTN_9].height)
        {
            if(x>keyButton[ID_KEY_BTN_9].x && x<keyButton[ID_KEY_BTN_9].x+keyButton[ID_KEY_BTN_9].width)
            {
                motion=ID_KEY_BTN_9;
            }
            else if(x>keyButton[ID_KEY_BLANK].x && x<keyButton[ID_KEY_BLANK].x+keyButton[ID_KEY_BLANK].width)
            {
                motion=ID_KEY_BLANK;
            }
            else
            {
                motion=ID_KEY_NONE;
            }
        }
        else
        {
            motion=ID_KEY_NONE;
        }
    }
    else if(x>keyButton[ID_KEY_CLOSE].x && x<keyButton[ID_KEY_CLOSE].x+keyButton[ID_KEY_CLOSE].width)
    {
        if(y>keyButton[ID_KEY_CLOSE].y && y<keyButton[ID_KEY_CLOSE].y+keyButton[ID_KEY_CLOSE].height)
        {
            motion=ID_KEY_CLOSE;
        }
        else if(y>keyButton[ID_KEY_BREAK].y && y<keyButton[ID_KEY_BREAK].y+keyButton[ID_KEY_BREAK].height)
        {
            motion=ID_KEY_BREAK;
        }
        else if(y>keyButton[ID_KEY_MARK_0].y && y<keyButton[ID_KEY_MARK_0].y+keyButton[ID_KEY_MARK_0].height)
        {
            motion=ID_KEY_MARK_0;
        }
        else if(y>keyButton[ID_KEY_ENTER].y && y<keyButton[ID_KEY_ENTER].y+keyButton[ID_KEY_ENTER].height)
        {
            motion=ID_KEY_ENTER;
        }
        else
        {
            motion=ID_KEY_NONE;
        }
    }
    else
    {
        motion=ID_KEY_NONE;
    }

    keyPanel->Refresh();
}

void KeyBoard::OnKeyMouseDown(wxMouseEvent& event)
{
    m_x1=event.GetX();
    m_y1=event.GetY();
    if(motion==ID_KEY_CAPTION)
    {
        winMove=ID_KEY_WIN_MOVE;
    }
}

void KeyBoard::OnLeaveKey(wxMouseEvent& event)
{
    winMove=ID_KEY_NONE;
    motion=ID_KEY_NONE;
    keyPanel->Refresh();
}

void KeyBoard::OnKeyClicked(wxMouseEvent& event)
{
    if(motion==ID_KEY_MODE)
    {
        if(inMode==ID_KEY_IN_123)
        {
            inMode=ID_KEY_IN_ABC;
        }
        else
        {
            inMode=ID_KEY_IN_123;
        }
    }
    else if(motion==ID_KEY_ENTER)
    {
        if(m_pTextCtrl)
        {
            m_pTextCtrl->SetValue(m_pTextCtrl->GetValue());
            m_pTextCtrl->SetInsertionPoint(m_pTextCtrl->GetInsertionPoint());
        }

        m_pTextCtrl->SetFocus();
        Destroy();
        wxMyTextCtrl::g_kb=0;
    }
    else if(motion==ID_KEY_CLOSE)
    {
        if(m_pTextCtrl)
        {
            m_pTextCtrl->SetValue(m_pTextCtrl->GetValue());
            m_pTextCtrl->SetInsertionPoint(m_pTextCtrl->GetInsertionPoint());
        }

        m_pTextCtrl->SetFocus();
        Destroy();
        wxMyTextCtrl::g_kb=0;
    }
    else if(motion==ID_KEY_BREAK)
    {
        if(inStep==ID_KEY_STEP_SEP)
        {
            keyExpand=ID_KEY_NONE;
            inStep=ID_KEY_STEP_SET;
        }
        else
        {
            long from,to;
            m_pTextCtrl->GetSelection(&from,&to);
            if(to>from)
            {
                m_pTextCtrl->Remove(from,to);
            }
            else
            {
                long pos=m_pTextCtrl->GetInsertionPoint() ;
                if(pos>0) m_pTextCtrl->Remove(pos-1,pos);
            }
        }
        m_pTextCtrl->SetFocus();
    }
    else if(motion==ID_KEY_BTN_0)
    {
        if(inMode==ID_KEY_IN_123)
        {
            m_pTextCtrl->WriteText(_("1"));
        }
        else
        {
            if(inStep==ID_KEY_STEP_SET)
            {
                keyExpand=ID_KEY_BTN_0;
                inStep=ID_KEY_STEP_SEP;
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_0 || keyExpand==ID_KEY_BTN_1 || keyExpand==ID_KEY_BTN_2)
                {
                    if(keyCaps==ID_KEY_CAP_NLOCK)
                    {
                        if(keyExpand==ID_KEY_BTN_0)
                        {
                            m_pTextCtrl->WriteText(_("a"));
                        }
                        else if(keyExpand==ID_KEY_BTN_1)
                        {
                            m_pTextCtrl->WriteText(_("d"));
                        }
                        else if(keyExpand==ID_KEY_BTN_2)
                        {
                            m_pTextCtrl->WriteText(_("g"));
                        }
                    }
                    else
                    {
                        if(keyExpand==ID_KEY_BTN_0)
                        {
                            m_pTextCtrl->WriteText(_("A"));
                        }
                        else if(keyExpand==ID_KEY_BTN_1)
                        {
                            m_pTextCtrl->WriteText(_("D"));
                        }
                        else if(keyExpand==ID_KEY_BTN_2)
                        {
                            m_pTextCtrl->WriteText(_("G"));
                        }
                    }
                    keyExpand=ID_KEY_NONE;
                    inStep=ID_KEY_STEP_SET;
                }
                else
                {
                    keyExpand=ID_KEY_BTN_0;
                    inStep=ID_KEY_STEP_SET;
                }
            }
        }

    }
    else if(motion==ID_KEY_BTN_1)
    {
        if(inMode==ID_KEY_IN_123)
        {
            m_pTextCtrl->WriteText(_("2"));
        }
        else
        {
            if(inStep==ID_KEY_STEP_SET)
            {
                keyExpand=ID_KEY_BTN_1;
                inStep=ID_KEY_STEP_SEP;
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_0 || keyExpand==ID_KEY_BTN_1 || keyExpand==ID_KEY_BTN_2)
                {
                    if(keyCaps==ID_KEY_CAP_NLOCK)
                    {
                        if(keyExpand==ID_KEY_BTN_0)
                        {
                            m_pTextCtrl->WriteText(_("b"));
                        }
                        else if(keyExpand==ID_KEY_BTN_1)
                        {
                            m_pTextCtrl->WriteText(_("e"));
                        }
                        else if(keyExpand==ID_KEY_BTN_2)
                        {
                            m_pTextCtrl->WriteText(_("h"));
                        }
                    }
                    else
                    {
                        if(keyExpand==ID_KEY_BTN_0)
                        {
                            m_pTextCtrl->WriteText(_("B"));
                        }
                        else if(keyExpand==ID_KEY_BTN_1)
                        {
                            m_pTextCtrl->WriteText(_("E"));
                        }
                        else if(keyExpand==ID_KEY_BTN_2)
                        {
                            m_pTextCtrl->WriteText(_("H"));
                        }
                    }
                    keyExpand=ID_KEY_NONE;
                    inStep=ID_KEY_STEP_SET;
                }
                else
                {
                    keyExpand=ID_KEY_BTN_1;
                    inStep=ID_KEY_STEP_SET;
                }
            }
        }
    }
    else if(motion==ID_KEY_BTN_2)
    {
        if(inMode==ID_KEY_IN_123)
        {
            m_pTextCtrl->WriteText(_("3"));
        }
        else
        {
            if(inStep==ID_KEY_STEP_SET)
            {
                keyExpand=ID_KEY_BTN_2;
                inStep=ID_KEY_STEP_SEP;
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_0 || keyExpand==ID_KEY_BTN_1 || keyExpand==ID_KEY_BTN_2)
                {
                    if(keyCaps==ID_KEY_CAP_NLOCK)
                    {
                        if(keyExpand==ID_KEY_BTN_0)
                        {
                            m_pTextCtrl->WriteText(_("c"));
                        }
                        else if(keyExpand==ID_KEY_BTN_1)
                        {
                            m_pTextCtrl->WriteText(_("f"));
                        }
                        else if(keyExpand==ID_KEY_BTN_2)
                        {
                            m_pTextCtrl->WriteText(_("i"));
                        }
                    }
                    else
                    {
                        if(keyExpand==ID_KEY_BTN_0)
                        {
                            m_pTextCtrl->WriteText(_("C"));
                        }
                        else if(keyExpand==ID_KEY_BTN_1)
                        {
                            m_pTextCtrl->WriteText(_("F"));
                        }
                        else if(keyExpand==ID_KEY_BTN_2)
                        {
                            m_pTextCtrl->WriteText(_("I"));
                        }
                    }
                    keyExpand=ID_KEY_NONE;
                    inStep=ID_KEY_STEP_SET;
                }
                else
                {
                    keyExpand=ID_KEY_BTN_2;
                    inStep=ID_KEY_STEP_SET;
                }
            }
        }
    }
    else if(motion==ID_KEY_BTN_3)
    {
        if(inMode==ID_KEY_IN_123)
        {
            m_pTextCtrl->WriteText(_("4"));
        }
        else
        {
            if(inStep==ID_KEY_STEP_SET)
            {
                keyExpand=ID_KEY_BTN_3;
                inStep=ID_KEY_STEP_SEP;
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_3 || keyExpand==ID_KEY_BTN_4 || keyExpand==ID_KEY_BTN_5)
                {
                    if(keyCaps==ID_KEY_CAP_NLOCK)
                    {
                        if(keyExpand==ID_KEY_BTN_3)
                        {
                            m_pTextCtrl->WriteText(_("j"));
                        }
                        else if(keyExpand==ID_KEY_BTN_4)
                        {
                            m_pTextCtrl->WriteText(_("m"));
                        }
                        else if(keyExpand==ID_KEY_BTN_5)
                        {
                            m_pTextCtrl->WriteText(_("p"));
                        }
                    }
                    else
                    {
                        if(keyExpand==ID_KEY_BTN_3)
                        {
                            m_pTextCtrl->WriteText(_("J"));
                        }
                        else if(keyExpand==ID_KEY_BTN_4)
                        {
                            m_pTextCtrl->WriteText(_("M"));
                        }
                        else if(keyExpand==ID_KEY_BTN_5)
                        {
                            m_pTextCtrl->WriteText(_("P"));
                        }
                    }
                    keyExpand=ID_KEY_NONE;
                    inStep=ID_KEY_STEP_SET;
                }
                else
                {
                    keyExpand=ID_KEY_BTN_3;
                    inStep=ID_KEY_STEP_SET;
                }
            }
        }
    }
    else if(motion==ID_KEY_BTN_4)
    {
        if(inMode==ID_KEY_IN_123)
        {
            m_pTextCtrl->WriteText(_("5"));
        }
        else
        {
            if(inStep==ID_KEY_STEP_SET)
            {
                keyExpand=ID_KEY_BTN_4;
                inStep=ID_KEY_STEP_SEP;
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_3 || keyExpand==ID_KEY_BTN_4 || keyExpand==ID_KEY_BTN_5)
                {
                    if(keyCaps==ID_KEY_CAP_NLOCK)
                    {
                        if(keyExpand==ID_KEY_BTN_3)
                        {
                            m_pTextCtrl->WriteText(_("k"));
                        }
                        else if(keyExpand==ID_KEY_BTN_4)
                        {
                            m_pTextCtrl->WriteText(_("n"));
                        }
                        else if(keyExpand==ID_KEY_BTN_5)
                        {
                            m_pTextCtrl->WriteText(_("q"));
                        }
                    }
                    else
                    {
                        if(keyExpand==ID_KEY_BTN_3)
                        {
                            m_pTextCtrl->WriteText(_("K"));
                        }
                        else if(keyExpand==ID_KEY_BTN_4)
                        {
                            m_pTextCtrl->WriteText(_("N"));
                        }
                        else if(keyExpand==ID_KEY_BTN_5)
                        {
                            m_pTextCtrl->WriteText(_("Q"));
                        }
                    }
                    keyExpand=ID_KEY_NONE;
                    inStep=ID_KEY_STEP_SET;
                }
                else
                {
                    keyExpand=ID_KEY_BTN_4;
                    inStep=ID_KEY_STEP_SET;
                }
            }
        }
    }
    else if(motion==ID_KEY_BTN_5)
    {
        if(inMode==ID_KEY_IN_123)
        {
            m_pTextCtrl->WriteText(_("6"));
        }
        else
        {
            if(inStep==ID_KEY_STEP_SET)
            {
                keyExpand=ID_KEY_BTN_5;
                inStep=ID_KEY_STEP_SEP;
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_3 || keyExpand==ID_KEY_BTN_4 || keyExpand==ID_KEY_BTN_5)
                {
                    if(keyCaps==ID_KEY_CAP_NLOCK)
                    {
                        if(keyExpand==ID_KEY_BTN_3)
                        {
                            m_pTextCtrl->WriteText(_("l"));
                        }
                        else if(keyExpand==ID_KEY_BTN_4)
                        {
                            m_pTextCtrl->WriteText(_("o"));
                        }
                        else if(keyExpand==ID_KEY_BTN_5)
                        {
                            m_pTextCtrl->WriteText(_("r"));
                        }
                    }
                    else
                    {
                        if(keyExpand==ID_KEY_BTN_3)
                        {
                            m_pTextCtrl->WriteText(_("L"));
                        }
                        else if(keyExpand==ID_KEY_BTN_4)
                        {
                            m_pTextCtrl->WriteText(_("O"));
                        }
                        else if(keyExpand==ID_KEY_BTN_5)
                        {
                            m_pTextCtrl->WriteText(_("R"));
                        }
                    }
                    keyExpand=ID_KEY_NONE;
                    inStep=ID_KEY_STEP_SET;
                }
                else
                {
                    keyExpand=ID_KEY_BTN_5;
                    inStep=ID_KEY_STEP_SET;
                }
            }
        }
    }
    else if(motion==ID_KEY_BTN_6)
    {
        if(inMode==ID_KEY_IN_123)
        {
            m_pTextCtrl->WriteText(_("7"));
        }
        else
        {
            if(inStep==ID_KEY_STEP_SET)
            {
                keyExpand=ID_KEY_BTN_6;
                inStep=ID_KEY_STEP_SEP;
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_6 || keyExpand==ID_KEY_BTN_7 || keyExpand==ID_KEY_BTN_8)
                {
                    if(keyCaps==ID_KEY_CAP_NLOCK)
                    {
                        if(keyExpand==ID_KEY_BTN_6)
                        {
                            m_pTextCtrl->WriteText(_("s"));
                        }
                        else if(keyExpand==ID_KEY_BTN_7)
                        {
                            m_pTextCtrl->WriteText(_("v"));
                        }
                    }
                    else
                    {
                        if(keyExpand==ID_KEY_BTN_6)
                        {
                            m_pTextCtrl->WriteText(_("S"));
                        }
                        else if(keyExpand==ID_KEY_BTN_7)
                        {
                            m_pTextCtrl->WriteText(_("V"));
                        }
                    }
                    keyExpand=ID_KEY_NONE;
                    inStep=ID_KEY_STEP_SET;
                }
                else
                {
                    keyExpand=ID_KEY_BTN_6;
                    inStep=ID_KEY_STEP_SET;
                }
            }
        }
    }
    else if(motion==ID_KEY_BTN_7)
    {
        if(inMode==ID_KEY_IN_123)
        {
            m_pTextCtrl->WriteText(_("8"));
        }
        else
        {
            if(inStep==ID_KEY_STEP_SET)
            {
                keyExpand=ID_KEY_BTN_7;
                inStep=ID_KEY_STEP_SEP;
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_6 || keyExpand==ID_KEY_BTN_7 || keyExpand==ID_KEY_BTN_8)
                {
                    if(keyCaps==ID_KEY_CAP_NLOCK)
                    {
                        if(keyExpand==ID_KEY_BTN_6)
                        {
                            m_pTextCtrl->WriteText(_("t"));
                        }
                        else if(keyExpand==ID_KEY_BTN_7)
                        {
                            m_pTextCtrl->WriteText(_("w"));
                        }
                        else if(keyExpand==ID_KEY_BTN_8)
                        {
                            m_pTextCtrl->WriteText(_("y"));
                        }
                    }
                    else
                    {
                        if(keyExpand==ID_KEY_BTN_6)
                        {
                            m_pTextCtrl->WriteText(_("T"));
                        }
                        else if(keyExpand==ID_KEY_BTN_7)
                        {
                            m_pTextCtrl->WriteText(_("W"));
                        }
                        else if(keyExpand==ID_KEY_BTN_8)
                        {
                            m_pTextCtrl->WriteText(_("Y"));
                        }
                    }
                    keyExpand=ID_KEY_NONE;
                    inStep=ID_KEY_STEP_SET;
                }
                else
                {
                    keyExpand=ID_KEY_BTN_7;
                    inStep=ID_KEY_STEP_SET;
                }
            }
        }
    }
    else if(motion==ID_KEY_BTN_8)
    {
        if(inMode==ID_KEY_IN_123)
        {
            m_pTextCtrl->WriteText(_("9"));
        }
        else
        {
            if(inStep==ID_KEY_STEP_SET)
            {
                keyExpand=ID_KEY_BTN_8;
                inStep=ID_KEY_STEP_SEP;
            }
            else
            {
                if(keyExpand==ID_KEY_BTN_6 || keyExpand==ID_KEY_BTN_7 || keyExpand==ID_KEY_BTN_8)
                {
                    if(keyCaps==ID_KEY_CAP_NLOCK)
                    {
                        if(keyExpand==ID_KEY_BTN_6)
                        {
                            m_pTextCtrl->WriteText(_("u"));
                        }
                        else if(keyExpand==ID_KEY_BTN_7)
                        {
                            m_pTextCtrl->WriteText(_("x"));
                        }
                        else if(keyExpand==ID_KEY_BTN_8)
                        {
                            m_pTextCtrl->WriteText(_("z"));
                        }
                    }
                    else
                    {
                        if(keyExpand==ID_KEY_BTN_6)
                        {
                            m_pTextCtrl->WriteText(_("U"));
                        }
                        else if(keyExpand==ID_KEY_BTN_7)
                        {
                            m_pTextCtrl->WriteText(_("X"));
                        }
                        else if(keyExpand==ID_KEY_BTN_8)
                        {
                            m_pTextCtrl->WriteText(_("Z"));
                        }
                    }
                    keyExpand=ID_KEY_NONE;
                    inStep=ID_KEY_STEP_SET;
                }
                else
                {
                    keyExpand=ID_KEY_BTN_8;
                    inStep=ID_KEY_STEP_SET;
                }
            }
        }
    }
    else if(motion==ID_KEY_BTN_9)
    {
        if(inMode==ID_KEY_IN_123)
        {
            m_pTextCtrl->WriteText(_("0"));
        }
        else
        {
            if(keyCaps==ID_KEY_CAP_NLOCK)
            {
                keyCaps=ID_KEY_CAP_LOCK;
            }
            else
            {
                keyCaps=ID_KEY_CAP_NLOCK;
            }
        }
    }
    else if(motion==ID_KEY_BLANK)
    {
        if(inMode==ID_KEY_IN_123)
        {
            m_pTextCtrl->WriteText(_("."));
        }
        else
        {
            m_pTextCtrl->WriteText(_(" "));
            m_pTextCtrl->SetFocus();
        }
    }
    else if(motion==ID_KEY_MARK_0)
    {
        m_pTextCtrl->WriteText(_("-"));
    }
    else if(motion==ID_KEY_MARK_2)
    {
        m_pTextCtrl->WriteText(_("_"));
    }
    else if(motion==ID_KEY_MARK_3)
    {
        m_pTextCtrl->WriteText(_("'"));
    }
    else if(motion==ID_KEY_MARK_4)
    {
        m_pTextCtrl->WriteText(_("\""));
    }
    else if(motion==ID_KEY_MARK_5)
    {
        if(bracketPosition==ID_KEY_BRACKET_FRONT)
        {
            m_pTextCtrl->WriteText(_("("));
            bracketPosition=ID_KEY_BRACKET_BEHIND;
        }
        else
        {
            m_pTextCtrl->WriteText(_(")"));
            bracketPosition=ID_KEY_BRACKET_FRONT;
        }
    }
    winMove=ID_KEY_NONE;
    keyPanel->Refresh();
}
