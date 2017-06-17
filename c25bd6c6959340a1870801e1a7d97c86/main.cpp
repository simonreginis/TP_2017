#include "Resource.h"
#include <tchar.h>
#include <windows.h>
#include <vector>
#include <sstream>

HWND hwnd;
POINT old_point;
HWND button, button_1, button_2, button_3, button_4;
HWND radio, radio_1, radio_2, radio_3, radio_4;

void draw_main();
BOOL Init(HINSTANCE hInstance, int nCmdShow);
ATOM RegisterClass(HINSTANCE hInstance);
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

USI SHAFT_X1=357,SHAFT_X2=667,SHAFT_Y1=5,SHAFT_Y2=768;

void draw_rect_object(HDC hdcBufor, USI x1, USI y1, USI x2, USI y2) // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
    Rectangle(hdcBufor, x1,y1,x2,y2);
}

void draw_main()
{
    HDC hdcOkno;
    hdcOkno = GetDC( hwnd );
    HPEN old,pen;
    pen = CreatePen( PS_SOLID, 2,  RGB( 0, 0, 0 ) );
    old =( HPEN ) SelectObject( hdcOkno, pen );
    draw_rect_object(hdcOkno, SHAFT_X1, SHAFT_Y1, SHAFT_X2, SHAFT_Y2);
    SelectObject( hdcOkno, old );
    DeleteObject( pen );
    ReleaseDC( hwnd, hdcOkno );
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
    draw_main();
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
                // SPAWN HUMAN
                break;
            case ID_BUTTON_2:
                // SPAWN HUMAN;
                break;
            case ID_BUTTON_3:
                // SPAWN HUMAN
                break;
            case ID_BUTTON_4:
                // SPAWN HUMAN
                break;
            case ID_BUTTON_5:
                // SPAWN HUMAN
                break;
            case ID_RADIO_1:
                //TARGET ?? ? ?
                break;
            case ID_RADIO_2:
                 //TARGET ?? ? ?
                break;
            case ID_RADIO_3:
                 //TARGET ?? ? ?
                break;
            case ID_RADIO_4:
                //TARGET ?? ? ?
                break;
            case ID_RADIO_5:
                 //TARGET ?? ? ?
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
