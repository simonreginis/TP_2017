#include "Resource.h"
#include <tchar.h>
#include <windows.h>
#include <vector>
#include <sstream>
typedef unsigned short int USI;

HWND hwnd;
POINT old_point;
HWND button, button_1, button_2, button_3, button_4;
HWND radio, radio_1, radio_2, radio_3, radio_4;

USI human_destination=0;
USI SHAFT_X1=357,SHAFT_X2=667,SHAFT_Y1=5,SHAFT_Y2=768; //const

struct elevator
{
    USI current_level=0, max_weight=600, curr_weight=0, last_place_x=SHAFT_X1+10;
    USI height=150, width=290, pos_x=SHAFT_X1+10,pos_y=SHAFT_Y2-((current_level+1)*height)-7;
    USI door_y=pos_y, direction=0, min_level=999, max_level=0, stopped=0;
    bool door_are_closed=true;
    //! ???? USI target_level=current_level; ////
};
elevator lift;

std::vector <USI> buttons_on_level;  //// 0-0 1-down 2-up 3-all
bool timer_on=false;

void draw_main(USI init);
BOOL Init(HINSTANCE hInstance, int nCmdShow);
ATOM RegisterClass(HINSTANCE hInstance);
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

class human
{
public:
    human(USI level);
    ~human(){;}
    void wait_for_lift();
    bool enter_lift();
    void exit_lift();
    USI get_pos_x() {return pos_x;}
    USI get_pos_y() {return pos_y;}
    USI get_side() {return side;}
    USI set_side(USI side_temp ) {side=side_temp;}
    USI get_dir() {return direction;}
    void set_dir(USI dir) {direction=dir;}
    USI get_level() {return start_level;}
    //! bool is_waiting() {return waiting;} ???????????
private:
    USI start_level=0,dest_level=0, pos_x=0,pos_y=0, side=2, direction=0, h_weight=70; // SIDE=1 - Lewa
    //! bool waiting=false; ?????????????????????
};

human::human(USI level)
{
    start_level=level;
    (level%2==0) ? set_side(1) : set_side(2);
    dest_level=human_destination;
    (get_side()==1) ? pos_x=10 : pos_x=1014;
    pos_y=(SHAFT_Y2-17 -((start_level)*lift.height));
    if(dest_level>start_level)
    {
        set_dir(2); //UP
        buttons_on_level[start_level]=2;
    }
    else
    {
        set_dir(1); //DOWN
        buttons_on_level[start_level]=1;
    }
}


bool human::enter_lift()        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
    if(lift.curr_weight+h_weight<lift.max_weight)
        {
            if(get_side()==1)
                {
                if(pos_x<=lift.last_place_x+34)
                    pos_x++;
                }
            else if(get_side()==2)
                {
                if(pos_x>=lift.last_place_x+4)
                    pos_x--;
                }
            lift.last_place_x+=34;
            lift.curr_weight+=70;
            //waiting=0;
            return true;
        }
    return  false;      //IF WEIGHT > LIMIT
}

void human::exit_lift()
{
    if(get_side()==1){
        if(pos_x>=10)
            pos_x--;
    }
    else if(get_side()==2)
        if(pos_x<=1014)
            pos_x++;
    lift.last_place_x-=12;
    lift.curr_weight-=70;
}

void human::wait_for_lift()         
{
    if(get_side()==1)
    {
        if(pos_x<SHAFT_X1-10)
            pos_x++;
    }
    else if(get_side()==2)
        {
        if(pos_x>SHAFT_X2+10)
            pos_x--;
        }
    //waiting=1;
}
std::vector <human> people;

void move_humans(HDC hdcBufor)
{
    //bitmap
    for (std::vector<human>::iterator it = people.begin() ; it != people.end(); ++it)
        {
            it->wait_for_lift();
            Ellipse( hdcBufor, it->get_pos_x()-5, it->get_pos_y()+10, it->get_pos_x()+5, it->get_pos_y() );
        }
}




void draw_rect_object(HDC hdcBufor, USI x1, USI y1, USI x2, USI y2) // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
    Rectangle(hdcBufor, x1,y1,x2,y2);
}

  void draw_level(HDC hdcBufor, USI level)
{
    if(level%2==0)
    {
        MoveToEx( hdcBufor, 0,(SHAFT_Y2-7 -((level)*lift.height)), &old_point );
        LineTo(hdcBufor, SHAFT_X1, (SHAFT_Y2-7 -((level)*lift.height)) );
    }
    else
    {
        MoveToEx( hdcBufor, lift.pos_x+lift.width+10,(SHAFT_Y2-7 -((level)*lift.height)), &old_point );
        LineTo(hdcBufor, 1024, (SHAFT_Y2-7 -((level)*lift.height)) );
    }
}

void lift_move(HDC hdcBufor)
{
 /*
 if(lift.direction==2)
 	lift.pos_y++;
 else
  lift.pos_y--;
 */
}

void lift_open_door(HDC hdcBufor)
{
    lift.door_are_closed=false;
    if(lift.current_state<3)
        lift.current_state++;
    if(lift.door_y!=lift.pos_y+lift.height-5 || lift.current_state>3) //!!!!!!
    {
                //!
                draw_rect_object(hdcBufor, lift.pos_x, lift.pos_y, lift.pos_x+lift.width, lift.pos_y+lift.height);
                //!
                USI temp;
                HPEN old,pen;
                pen = CreatePen( PS_SOLID, 14,  RGB( 255, 255, 255 ) );
                old =( HPEN ) SelectObject( hdcBufor, pen );
                if(lift.current_level%2==0)
                    temp=lift.pos_x-5;
                else
                    temp=lift.pos_x+lift.width+3;
                MoveToEx( hdcBufor, temp, lift.pos_y+5, &old_point );
                LineTo(hdcBufor, temp, lift.door_y );
                SelectObject( hdcBufor, old );
                DeleteObject( pen );
                if(lift.current_state<4)
                    lift.door_y++;
                else
                {
                    humans_enter_lift(hdcBufor);
                    if(lift.current_state==6)
                        humans_exit_lift(hdcBufor);
                    if(lift.current_state==7)       //CLOSE DOOORRRRRRRRRRRRRRRRRR
                        {
                        if(lift.door_y!=lift.pos_y)
                            lift.door_y--;
                        else
                            {
                            lift.door_are_closed=true;
                            lift.current_state=0;
                            }
                        }
                }
                //ReleaseDC( hwnd, hdcBufor );
    }
    else
    {
        if(lift.current_state<4) //!!!!!!!!!!!!! musi byc ?
        lift.current_state++;
    }
    //std::cout<<"lift dir: "<<lift.direction<<"     " <<lift.max_level<<std::endl;
}

void draw_main(USI init=0)
{
    HDC hdcOkno,hdcBufor;
    hdcOkno = GetDC( hwnd );
    HPEN old,pen,pen2;
    HBITMAP Membitmap = CreateCompatibleBitmap(hdcOkno, 1024, 768);
    hdcBufor = CreateCompatibleDC( hdcOkno );
	SelectObject(hdcBufor, Membitmap);
    pen = CreatePen( PS_SOLID, 2,  RGB( 0, 0, 0 ) );
    old =( HPEN ) SelectObject( hdcBufor, pen );
    draw_rect_object(hdcBufor, 0, 0, 1024, 768);
    //draw_rect_object(hdcBufor, SHAFT_X1, SHAFT_Y1, SHAFT_X2, SHAFT_Y2);
    for(int i=0;i<5;i++)
        draw_level(hdcBufor, i);
    pen2 = CreatePen( PS_SOLID, 1,  RGB( 250, 10, 10 ) );
    old =( HPEN ) SelectObject( hdcBufor, pen2 );
    if(init==1)
        draw_rect_object(hdcBufor, lift.pos_x, lift.pos_y, lift.pos_x+lift.width, lift.pos_y+lift.height);
    lift_move(hdcBufor);
    SelectObject( hdcBufor, old );
    move_humans(hdcBufor);
    BitBlt( hdcOkno, 0, 0, 1024, 768, hdcBufor, 0, 0, SRCCOPY );  
    BitBlt( hdcOkno, SHAFT_X1, SHAFT_Y1, 309, 768, hdcBufor, SHAFT_X1, SHAFT_Y1, SRCCOPY );  
    BitBlt( hdcOkno, lift.pos_x, lift.pos_y, lift.width, lift.height, hdcBufor, lift.pos_x, lift.pos_y, SRCCOPY ); 
    DeleteObject( pen );
    DeleteObject( pen2 );
    DeleteObject(Membitmap);
    ReleaseDC( hwnd, hdcOkno );
    DeleteDC( hdcBufor );
}

BOOL Init(HINSTANCE hInstance, int nCmdShow)
{
    button = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "LEVEL 0", WS_CHILD |  WS_VISIBLE,1120, 170, 90, 30, hwnd,(HMENU) ID_BUTTON_1, hInstance, NULL );
    button_1 = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "LEVEL 1", WS_CHILD | WS_VISIBLE,1120, 210, 90, 30, hwnd,(HMENU) ID_BUTTON_2, hInstance, NULL );
    button_2 = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "LEVEL 2", WS_CHILD | WS_VISIBLE,1120, 250, 90, 30, hwnd,(HMENU) ID_BUTTON_3, hInstance, NULL );
    button_3 = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "LEVEL 3", WS_CHILD | WS_VISIBLE,1120, 290, 90, 30, hwnd,(HMENU) ID_BUTTON_4, hInstance, NULL );
    button_4 = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "LEVEL 4", WS_CHILD | WS_VISIBLE,1120, 330, 90, 30, hwnd,(HMENU) ID_BUTTON_5, hInstance, NULL );
    radio = CreateWindowEx( 0, "BUTTON", "DEST. LEVEL 0", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,1120, 10, 160, 20, hwnd,(HMENU) ID_RADIO_1, hInstance, NULL );
    radio_1 = CreateWindowEx( 0, "BUTTON", "DEST. LEVEL 1", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,1120, 40, 160, 20, hwnd,(HMENU) ID_RADIO_2, hInstance, NULL );
    radio_2 = CreateWindowEx( 0, "BUTTON", "DEST. LEVEL 2", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,1120, 70, 160, 20, hwnd,(HMENU) ID_RADIO_3, hInstance, NULL );
    radio_3 = CreateWindowEx( 0, "BUTTON", "DEST. LEVEL 3", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,1120, 100, 160, 20, hwnd,(HMENU) ID_RADIO_4, hInstance, NULL );
    radio_4 = CreateWindowEx( 0, "BUTTON", "DEST. LEVEL 4", WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,1120, 130, 160, 20, hwnd,(HMENU) ID_RADIO_5, hInstance, NULL );
    ShowWindow (hwnd, nCmdShow);
    draw_main(1);
}

ATOM RegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    wincl.hInstance = hInstance;
	wincl.lpszClassName = _T("WindowsApp");
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(255, 255, 255));;
    return RegisterClassEx(&wincl);
}


int WINAPI WinMain (HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow)
{
    MSG messages;
    RegisterClass(hInstance);
    HFONT hNormalFont =( HFONT ) GetStockObject( DEFAULT_GUI_FONT );
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           _T("WindowsApp"),         /* Classname */
           _T("Test"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           100,       /* Windows decides the position */
           0,       /* where the window ends up on the screen */
           1280,                 /* The programs width */
           820,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
    if (!Init(hInstance, nCmdShow))
        return 1;
    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}

void turn_on_timer()
{
    if(!timer_on)
        {
            SetTimer( hwnd, ID_TIMER, 5, NULL );
            timer_on=true;
        }
}

void spawn_human(USI level)
{
   if(level!=human_destination)
        {
            //change_level(level);
            turn_on_timer();
            //add people
        }

}
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_DESTROY:
            PostQuitMessage (0);
            break;
        case WM_COMMAND:
            switch( wParam )
            {
            case ID_BUTTON_1:
                spawn_human(0);
                break;
            case ID_BUTTON_2:
                spawn_human(1);
                break;
            case ID_BUTTON_3:
                spawn_human(2);
                break;
            case ID_BUTTON_4:
                spawn_human(3);
                break;
            case ID_BUTTON_5:
                spawn_human(4);
                break;
            case ID_RADIO_1:
                CheckRadioButton( hwnd, ID_RADIO_1, ID_RADIO_5, ID_RADIO_1 );
                human_destination=0;
                break;
            case ID_RADIO_2:
                 CheckRadioButton( hwnd, ID_RADIO_1, ID_RADIO_5, ID_RADIO_2 );
                human_destination=1;
                break;
            case ID_RADIO_3:
                 CheckRadioButton( hwnd, ID_RADIO_1, ID_RADIO_5, ID_RADIO_3 );
                human_destination=2;
                break;
            case ID_RADIO_4:
                CheckRadioButton( hwnd, ID_RADIO_1, ID_RADIO_5, ID_RADIO_4 );
                human_destination=3;
                break;
            case ID_RADIO_5:
                 CheckRadioButton( hwnd, ID_RADIO_1, ID_RADIO_5, ID_RADIO_5 );
                human_destination=4;
                break;
            default:
                break;
            }
            break;

        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}
