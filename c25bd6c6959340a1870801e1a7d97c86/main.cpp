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
HBITMAP hbmHuman[5];
BOOL Init(HINSTANCE hInstance, int nCmdShow);
ATOM RegisterClass(HINSTANCE hInstance);
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
USI human_destination=0, number_of_people=0, g_time_value=50;
USI SHAFT_X1=357,SHAFT_X2=667,SHAFT_Y1=5,SHAFT_Y2=768; //const

struct elevator
{
    USI current_level=0, max_weight=500, curr_weight=0, last_place_x=SHAFT_X1+4;
    USI height=150, width=290, pos_x=SHAFT_X1+10,pos_y=SHAFT_Y2-((current_level+1)*height)-7;
    USI door_y=pos_y, direction=0, min_level=999, max_level=0, current_state=0; //states - 0 lift is moving / doing nothing, 3 - lift stopped to open door, 4 - door opening, 6 - people in, 7 - people out
    bool door_are_closed=true;
};
elevator lift;

std::vector <USI> buttons_on_level;  //// 0-0 1-down 2-up 3-all

class human
{
public:
    human(USI level, USI number);
    ~human(){;}
    void wait_for_lift();
    bool enter_lift();
    void exit_lift();
    USI get_pos_x() {return pos_x;}
    USI get_pos_y() {return pos_y;}
    void set_pos_y(USI temp) {pos_y=temp;}
    USI get_side() {return side;}
    USI set_side(USI side_temp ) {side=side_temp;}
    USI get_dir() {return direction;}
    void set_dir(USI dir) {direction=dir;}
    USI get_level() {return start_level;}
    USI get_dest() {return dest_level;}
    USI get_id() {return id;}
private:
    USI start_level=0,dest_level=0, pos_x=0,pos_y=0, side=2, direction=0, h_weight=70, id=0; // SIDE=1 - Lewa
};

void set_max_or_min(USI lvl)
{
    if(lvl<lift.current_level)
            {
                if(lvl<lift.min_level)
                    lift.min_level=lvl;
                if(lift.direction==0)
                    lift.direction=1;
            }
            else if(lvl>lift.current_level)
            {
                if(lvl>lift.max_level)
                    lift.max_level=lvl;
                if(lift.direction==0)
                    lift.direction=2;
            }
}

human::human(USI level, USI number)
{
    id=number;
    start_level=level;
    (level%2==0) ? set_side(1) : set_side(2);
    dest_level=human_destination;
    (get_side()==1) ? pos_x=10 : pos_x=1014;
    pos_y=(SHAFT_Y2-17 -((start_level)*lift.height));
    if(dest_level>start_level)
    {
        set_dir(2); //UP
        if(buttons_on_level[start_level]==0 || buttons_on_level[start_level]==2 || buttons_on_level[start_level]==4) //DO FUNCKJI????
            buttons_on_level[start_level]=2;
        else if(buttons_on_level[start_level]==1 || buttons_on_level[start_level]==3)
            buttons_on_level[start_level]=3;
    }
    else
    {
        set_dir(1); //DOWN
        if(buttons_on_level[start_level]==0 || buttons_on_level[start_level]==1 || buttons_on_level[start_level]==4) //DO FUNCKJI????
            buttons_on_level[start_level]=1;
        else if(buttons_on_level[start_level]==2 || buttons_on_level[start_level]==3)
            buttons_on_level[start_level]=3;
    }
}

void human::wait_for_lift()
{
    HDC hdcTemp = GetDC( hwnd );
    if(get_side()==1)
    {
        //if(pos_x<(SHAFT_X1-10))
        if(GetPixel(hdcTemp, pos_x+32, pos_y)==RGB(255,255,255))
            pos_x++;
        else
            {
            set_max_or_min(start_level);
            set_max_or_min(dest_level);
            }
    }
    else if(get_side()==2)
        {
        //if(pos_x>(SHAFT_X2+10))
        if(GetPixel(hdcTemp, pos_x-32, pos_y)==RGB(255,255,255))
            pos_x--;
        else
            {
            set_max_or_min(start_level);
            set_max_or_min(dest_level);
            }
        }
    DeleteDC( hdcTemp );
}

bool human::enter_lift()        //!!!!BUG OPEN DOOR (DIR SIE ZMIENIA)
{
    if(lift.curr_weight+h_weight<lift.max_weight)
        {
            if(get_side()==1)
                {
                if(pos_x<=lift.last_place_x+32)
                    pos_x++;
                else
                    {
                    lift.last_place_x+=32;
                    lift.curr_weight+=h_weight;             //!!!!!! FUNKCJAAAAAAAA
                    set_side(0);
                    if(buttons_on_level[dest_level]==0)
                        buttons_on_level[dest_level]=4;
                    }
                }
            else if(get_side()==2)
                {
                if(pos_x>=lift.last_place_x+32)
                    pos_x--;
                else
                    {
                    lift.last_place_x+=32;
                    lift.curr_weight+=h_weight;
                    set_side(0);
                    if(buttons_on_level[dest_level]==0)
                        buttons_on_level[dest_level]=4;
                    }
                }
            return true;
        }
    return  false;      //IF WEIGHT > LIMIT
}

void human::exit_lift()
{
    if(dest_level%2==0){
        if(pos_x>=30)
            pos_x--;
        else
        {
            set_side(5); //5- is going out
            lift.last_place_x-=32;
            lift.curr_weight-=70;
        }
    }
    else if(dest_level%2==1)
        if(pos_x<=994)
            pos_x++;
        else
        {
            set_side(5); //5- is going out
            lift.last_place_x-=32;
            lift.curr_weight-=70;
        }
}

std::vector <human> people;

void delete_human(USI id)
{
    people[id]=people.back();
    people.back().~human(); //! ????
    people.pop_back();
}

bool humans_exit_lift(HDC hdcBufor)            //TRUE WHEN ALL IN  / WEIGHT > LIMIT!, FALSE WHEN LIFT IS NOT MOVING
{
    bool everyone_out=true, delete_this_human=false;
    USI delete_id=0;
    for (std::vector<human>::iterator it = people.begin() ; it != people.end(); ++it)
        {
            if(it->get_dest()==lift.current_level && it->get_side()==0)   //! co gdy winda wjedzie na max floor i bedzie miala zjechac w dol
            {
                it->exit_lift();
                if(it->get_side()!=5)
                    everyone_out=false;
                else
                    {
                    delete_this_human=true;
                    delete_id=it->get_id();
                    }
            }
        }
    if(delete_this_human)
        delete_human(delete_id);
    if(everyone_out==true)
    {
        lift.current_state=3;
        return true;
    }
    else
        return false;
}

bool humans_enter_lift(HDC hdcBufor)            //TRUE WHEN ALL IN  / WEIGHT > LIMIT!, FALSE WHEN LIFT IS NOT MOVING
{
    bool everyone_in=true;
    for (std::vector<human>::iterator it = people.begin() ; it != people.end(); ++it)
        {
            if(it->get_level()==lift.current_level && (it->get_dir()==lift.direction || lift.current_level==lift.max_level || lift.current_level==lift.min_level)) //! co gdy winda wjedzie na max floor i bedzie miala zjechac w dol
            {
                if(!it->enter_lift())
                    {
                        lift.current_state=4;
                        return true;
                    }
                if(it->get_side()!=0)
                    everyone_in=false;
            }
        }
    if(everyone_in==true)
    {
        if(buttons_on_level[lift.current_level]==3)
        {
            if(lift.direction==2)
                buttons_on_level[lift.current_level]=1;
            else
                buttons_on_level[lift.current_level]=2;
        }
        else
            buttons_on_level[lift.current_level]=0;
        lift.current_state=4;
        return true;
    }
    else
        return false;
}

void lift_open_door(HDC hdcBufor)
{
    if(lift.current_state==0)
        lift.current_state=1;
    if(lift.door_y==lift.pos_y+lift.height-5)
        lift.current_state=2;
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
    if(lift.current_state==1)
        lift.door_y++;
    else
    {
        if(lift.current_state==2)
            humans_exit_lift(hdcBufor);
        if(lift.current_state==3)
            humans_enter_lift(hdcBufor);
        if(lift.current_state==4)
            {
            if(lift.door_y!=lift.pos_y)
                lift.door_y--;
            else
                lift.current_state=0;
            }
    }
}

void lift_change_state(USI dir, HDC hdcBufor)
{
    if(dir==2)
        lift.current_level=4-(((lift.pos_y+lift.height-15)/lift.height));
    else
        lift.current_level=4-(((lift.pos_y-15)/lift.height));
        if(buttons_on_level[lift.current_level]==dir || buttons_on_level[lift.current_level]==3 || buttons_on_level[lift.current_level]==4)
            {
            if(lift.current_state==0)
                lift.door_y=lift.pos_y;
            lift_open_door(hdcBufor);
            }
        else if(lift.current_state==4)
            lift_open_door(hdcBufor);
}

void lift_move(HDC hdcBufor)
{
    //std::cout<<"MIN: "<<lift.min_level<<" | MAX: "<<lift.max_level<< " | CURR: " <<lift.current_level<<std::endl;
    //std::cout<<"cur state: "<<lift.current_state<<" | LIFT.DIR: " <<lift.direction<<std::endl;
    std::stringstream WText;
    WText.str(std::string());
    WText << "Current lift weight: ";
    WText << lift.curr_weight;
    TextOut(hdcBufor, 10, 10, WText.str().c_str(), WText.str().length());
    Rectangle(hdcBufor, lift.pos_x, lift.pos_y, lift.pos_x+lift.width, lift.pos_y+lift.height);
   if(lift.direction==2)
   {
       if(lift.current_level!=lift.max_level)
            lift_change_state(2,hdcBufor);
        else
        {
            if(lift.current_state==0)
                lift.door_y=lift.pos_y;
            lift_open_door(hdcBufor);
            if(lift.current_state==0)
                {
                lift.max_level=0;
                if(lift.min_level!=999)
                    lift.direction=1;
                else
                    lift.direction=0;
                }
        }
        if(lift.current_state==0)
            lift.pos_y--;
   }
   else if(lift.direction==1)
   {
        if(lift.current_level!=lift.min_level)
            lift_change_state(1,hdcBufor);
        else
        {
            if(lift.current_state==0)
                    lift.door_y=lift.pos_y;
            lift_open_door(hdcBufor);
            if(lift.current_state==0)
                {
                lift.min_level=999;
                if(lift.max_level!=0)
                    lift.direction=2;
                else
                    lift.direction=0;
                }
        }
        if(lift.current_state==0)
            lift.pos_y++;
   }
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
