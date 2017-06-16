// dzwig.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "dzwig.h"
#include "Crane.h"
#include "Cargo.h"
#include <objidl.h>
#include <gdiplus.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace Gdiplus;
//using namespace std;
#pragma comment (lib,"Gdiplus.lib")

#define MAX_LOADSTRING 100


// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

Crane crane;
Cargo *cargo;

HWND hwndButton;	//deklaracja uchwytu przyciskow
RECT drawArea = { AREA_X1, AREA_Y1, AREA_X2, AREA_Y2 };	//obszar, ktory sie zmienia(stawiamy klocki, latamy hookiem itd.)

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void repaintWindow(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea)
{
	if (drawArea == NULL)
		InvalidateRect(hWnd, NULL, TRUE); // repaint all
	else
		InvalidateRect(hWnd, drawArea, TRUE); //repaint drawArea


	hdc = BeginPaint(hWnd, &ps);
	Graphics graphics(hdc);

	Pen pen(Color(255, 0, 0, 0));
	SolidBrush *brush = new SolidBrush(Color(255, 255, 0, 0));
	graphics.DrawLine(&pen, crane.get_x(), AREA_Y1, crane.get_x(), crane.get_y());
	for (int i = 0; i < BLOCKS; i++)
	{
		int x = cargo[i].get_x();
		int y = cargo[i].get_y();
		int l = cargo[i].get_length();
		graphics.FillRectangle(brush, x, y, l, l);
		switch (cargo[i].getType())
		{
		case 0:				//rectangle
			graphics.DrawRectangle(&pen, x + l / 4, y + l / 4, l / 2, l / 2);
			break;
		case 1:				//triangle
		{
			graphics.DrawLine(&pen,x + l / 4, y + 3 * l / 4, x + l / 2, y + l / 4);
			graphics.DrawLine(&pen,x + l / 2, y + l / 4, x + 3 * l / 4, y + 3 * l / 4);
			graphics.DrawLine(&pen, x + 3 * l / 4, y + 3 * l / 4, x + l / 4, y + 3 * l / 4);
			break;
		}
		case 2:				//wheel
		{
			graphics.DrawEllipse(&pen, x + l / 4, y + l / 4, l / 2, l / 2);
			break;
		}
			
		}
	}
	EndPaint(hWnd, &ps);

}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;



	cargo = new Cargo[BLOCKS];
	for (int i = 0; i < BLOCKS; i++)			//tworze dynamiczna tablice z klockami i ich startowymi pozycjami
	{
		cargo[i].initialize(AREA_X1 + (cargo[i].get_length() + 10) *i, AREA_Y2 - cargo[i].get_length(), i%3);
	}

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DZWIG, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DZWIG));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

	GdiplusShutdown(gdiplusToken);

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DZWIG));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW-2);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DZWIG);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);



   //UP
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("^"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   AREA_X1 - 35, AREA_Y1 + 20,                                  // the left and top co-ordinates
	   20, 20,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON_UP,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
	//DOWN
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("v"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   AREA_X1 - 35, AREA_Y1 + 50,                                  // the left and top co-ordinates
	   20, 20,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON_DOWN,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
	//LEFT
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("<"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   AREA_X1 + 20, AREA_Y1 - 25,                                  // the left and top co-ordinates
	   20, 20,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON_LEFT,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
	//RIGHT
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT(">"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   AREA_X1 + 50, AREA_Y1 - 25,                                  // the left and top co-ordinates
	   20, 20,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON_RIGHT,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
	//ATTACH
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("[x]"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   AREA_X1 + 80, AREA_Y1 - 25,                                  // the left and top co-ordinates
	   20, 20,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON_ATTACH,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
	//DETACH
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("[ ]"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   AREA_X1 + 110, AREA_Y1 - 25,                                  // the left and top co-ordinates
	   20, 20,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON_DETACH,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
	//STOP
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("-"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   AREA_X1 - 35, AREA_Y1 - 25,                                  // the left and top co-ordinates
	   20, 20,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON_STOP,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need


   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	SetTimer(hWnd, TMR_1, 10, 0);		///1 klatka na sekunde
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
			//					 ***** MOJE PRZYCISKI *****
			case ID_BUTTON_UP:
			{
				crane.setSpeed_y(-6);
				break;
			}
			case ID_BUTTON_DOWN:
			{
				crane.setSpeed_y(6);
				break;
			}
			case ID_BUTTON_LEFT:
			{
				crane.setSpeed_x(-4);
				break;
			}
			case ID_BUTTON_RIGHT:
			{
				crane.setSpeed_x(4);
				break;
			}
			case ID_BUTTON_ATTACH:
			{
				crane.attach(cargo);
				break;
			}
			case ID_BUTTON_DETACH:
			{
				crane.detach();
				break;
			}
			case ID_BUTTON_STOP:
			{
				crane.stopMoving();
				break;
			}

            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            hdc = BeginPaint(hWnd, &ps);

			Graphics graphics(hdc);
			SolidBrush *grass_brush = new SolidBrush(Color(255, 0, 255, 0));	//zielony
			SolidBrush *crane_brush = new SolidBrush(Color(255, 0, 0, 0));		//czarny

			
			graphics.FillRectangle(grass_brush, 0, AREA_Y2, AREA_X2 + 200, AREA_Y2);	//trawa	- poziom klockow
			graphics.FillRectangle(crane_brush, AREA_X1 - 50, AREA_Y1 - 50, 50, AREA_Y2 - AREA_Y1 + 50);	//pion dzwigu
			graphics.FillRectangle(crane_brush, AREA_X1 - 65, AREA_Y1 - 30, AREA_X2, 30);	//poziom dzwigu
			
			
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_TIMER:
		switch (wParam)
		{
			case TMR_1:
				//force window to repaint
			{
				crane.move();					//wykonaj ruch dzwigu
				if (crane.getCargo() != NULL)
				{
					Cargo *c = crane.getCargo();
					c->setSpeed_y(crane.getSpeed_y());		//przypisz ruszanemu blokowi predkosci dzwigu
					c->setSpeed_x(crane.getSpeed_x());
				}
				for (int i = 0; i < BLOCKS; i++)		//rusz klockami, tez tymi opadajacymi
				{
					cargo[i].move(cargo);
				}
					

				repaintWindow(hWnd, hdc, ps, &drawArea);
				SetTimer(hWnd, TMR_1, 250, 0);		///1 klatka na sekunde
				break;
			}
			default:
			break;
		}

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
