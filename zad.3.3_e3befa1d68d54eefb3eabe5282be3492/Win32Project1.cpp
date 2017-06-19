// Win32Project1.cpp : Defines the entry point for the application.
//


#include "stdafx.h"
#include "Win32Project1.h"
#include <vector>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <cmath>
#include <queue>
#include <windows.h>


#define MAX_LOADSTRING	100
#define TMR_1 1

#define ID_BUTTON1		201
#define ID_BUTTON2		202
#define ID_BUTTON3		203
#define ID_BUTTON4		204
#define ID_BUTTON5		205
#define ID_BUTTON6		206
#define ID_BUTTON7		207
#define ID_BUTTON8		208
#define ID_BUTTON9		209
#define ID_BUTTON10		210
#define ID_BUTTON11		211
#define ID_BUTTON12 	212
#define ID_BUTTON13		213
#define ID_BUTTON14		214
#define ID_BUTTON15 	215
#define ID_BUTTON16		216
#define ID_BUTTON17		217
#define ID_BUTTON18		218
#define ID_BUTTON19		219
#define ID_BUTTON20		220
#define ID_BUTTON21 	221
#define ID_BUTTON22		222
#define ID_BUTTON23 	223
#define ID_BUTTON24		224
#define ID_BUTTON25		225
#define ID_BUTTON26 	226
#define ID_BUTTON27		227
#define ID_BUTTON28 	228
#define ID_BUTTON29		229

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

												//buttons
HWND hwndButton;

HWND hText;

RECT drawArea1 = { 194, 18, 306 , 475 };

int x = 200, y = 320;
int przywolaj = 0, przesun_do = 0, odleglosc2 = 0;
std::queue <int> kolejkap;
std::queue <int> kolejkak;

const int pietro1 = 470;
const int pietro2 = 395;
const int pietro3 = 320;
const int pietro4 = 245;
const int pietro5 = 170;

int zmienna = 0;
TCHAR buf[32];

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void Czysc(HWND hWnd)
{
	InvalidateRect(hWnd, &drawArea1, TRUE);
}

void Gora(HWND hWnd)
{
	y--;
	Czysc(hWnd);
}

void Dol(HWND hWnd)
{
	y++;
	Czysc(hWnd);
}

void Draw(HWND hWnd)
{
	srand(time(NULL));
	int poczatek, koniec, odleglosc;
	_itow_s(zmienna, buf, 10);
	SetWindowText(hText, buf);
	if (kolejkak.size() != 0)
	{
		poczatek = kolejkap.front();
		kolejkap.pop();
		koniec = kolejkak.front();
		kolejkak.pop();
		odleglosc = abs(poczatek - koniec);
		if ((poczatek - koniec) < 0) //winda jedzie do gory
		{
			for (int i = 0; i < (odleglosc * 75); i++)
			{
				if (y > (20 + 75 * (5 - koniec)))
				{
					y--;
					HDC hdcOkno = GetDC(hWnd);
					HPEN CzarnePioro, NiebieskiePioro, Pudelko;
					POINT stary;
					CzarnePioro = CreatePen(PS_SOLID, 5, 0x000000);
					NiebieskiePioro = CreatePen(PS_SOLID, 5, 0xFF0000);
					Pudelko = (HPEN)SelectObject(hdcOkno, NiebieskiePioro);
					MoveToEx(hdcOkno, x, y, &stary);
					LineTo(hdcOkno, x + 100, y);
					LineTo(hdcOkno, x + 100, y + 150);
					LineTo(hdcOkno, x, y + 150);
					LineTo(hdcOkno, x, y);
					SelectObject(hdcOkno, Pudelko);
					DeleteObject(NiebieskiePioro);
					ReleaseDC(hWnd, hdcOkno);
				}
				Czysc(hWnd);
			}

		}

		else if ((poczatek - koniec) > 0) //winda jedzie w dó³
		{
			for (int i = 0; i < (odleglosc * 75); i++)
			{
				if (y < (320 - 75 * (koniec - 5)))
					y++;
				HDC hdcOkno = GetDC(hWnd);
				HPEN CzarnePioro, NiebieskiePioro, Pudelko;
				POINT stary;
				CzarnePioro = CreatePen(PS_SOLID, 5, 0x000000);
				NiebieskiePioro = CreatePen(PS_SOLID, 5, 0xFF0000);
				Pudelko = (HPEN)SelectObject(hdcOkno, NiebieskiePioro);
				MoveToEx(hdcOkno, x, y, &stary);
				LineTo(hdcOkno, x + 100, y);
				LineTo(hdcOkno, x + 100, y + 150);
				LineTo(hdcOkno, x, y + 150);
				LineTo(hdcOkno, x, y);
				SelectObject(hdcOkno, Pudelko);
				DeleteObject(NiebieskiePioro);
				ReleaseDC(hWnd, hdcOkno);
				Czysc(hWnd);
			}

		}

	}
	else if ( przywolaj != 0 )
	{
		if (przywolaj == 1) przesun_do = pietro1 - 150;
		else if (przywolaj == 2) przesun_do = pietro2 - 150;
		else if (przywolaj == 3) przesun_do = pietro3 - 150;
		else if (przywolaj == 4) przesun_do = pietro4 - 150;
		else if (przywolaj == 5) przesun_do = pietro5 - 150;
		odleglosc2 = abs(y - przesun_do);
		if (y > przesun_do)
		{
			for (int i = 0; i < odleglosc2; i++)
			{
				y--;
				HDC hdcOkno = GetDC(hWnd);
				HPEN CzarnePioro, NiebieskiePioro, Pudelko;
				POINT stary;
				CzarnePioro = CreatePen(PS_SOLID, 5, 0x000000);
				NiebieskiePioro = CreatePen(PS_SOLID, 5, 0xFF0000);
				Pudelko = (HPEN)SelectObject(hdcOkno, NiebieskiePioro);
				MoveToEx(hdcOkno, x, y, &stary);
				LineTo(hdcOkno, x + 100, y);
				LineTo(hdcOkno, x + 100, y + 150);
				LineTo(hdcOkno, x, y + 150);
				LineTo(hdcOkno, x, y);
				SelectObject(hdcOkno, Pudelko);
				DeleteObject(NiebieskiePioro);
				ReleaseDC(hWnd, hdcOkno);
				Czysc(hWnd);
			}
		}
		else if (y < przesun_do)
		{
			for (int i = 0; i < odleglosc2; i++)
			{
				y++;
				HDC hdcOkno = GetDC(hWnd);
				HPEN CzarnePioro, NiebieskiePioro, Pudelko;
				POINT stary;
				CzarnePioro = CreatePen(PS_SOLID, 5, 0x000000);
				NiebieskiePioro = CreatePen(PS_SOLID, 5, 0xFF0000);
				Pudelko = (HPEN)SelectObject(hdcOkno, NiebieskiePioro);
				MoveToEx(hdcOkno, x, y, &stary);
				LineTo(hdcOkno, x + 100, y);
				LineTo(hdcOkno, x + 100, y + 150);
				LineTo(hdcOkno, x, y + 150);
				LineTo(hdcOkno, x, y);
				SelectObject(hdcOkno, Pudelko);
				DeleteObject(NiebieskiePioro);
				ReleaseDC(hWnd, hdcOkno);
				Czysc(hWnd);
			}
		}
		przywolaj = 0;
		przesun_do = 0;
	}
	HDC hdcOkno = GetDC(hWnd);
	HPEN CzarnePioro, NiebieskiePioro, Pudelko;
	POINT stary;
	CzarnePioro = CreatePen(PS_SOLID, 5, 0x000000);
	NiebieskiePioro = CreatePen(PS_SOLID, 5, 0xFF0000);
	Pudelko = (HPEN)SelectObject(hdcOkno, NiebieskiePioro);
	MoveToEx(hdcOkno, x, y, &stary);
	LineTo(hdcOkno, x + 100, y);
	LineTo(hdcOkno, x + 100, y + 150);
	LineTo(hdcOkno, x, y + 150);
	LineTo(hdcOkno, x, y);
	DeleteObject(NiebieskiePioro);
	Pudelko = (HPEN)SelectObject(hdcOkno, CzarnePioro);
	MoveToEx(hdcOkno, 100, 470, &stary);
	LineTo(hdcOkno, 194, 470);
	MoveToEx(hdcOkno, 306, 395, &stary);
	LineTo(hdcOkno, 400, 395);
	MoveToEx(hdcOkno, 100, 320, &stary);
	LineTo(hdcOkno, 194, 320);
	MoveToEx(hdcOkno, 306, 245, &stary);
	LineTo(hdcOkno, 400, 245);
	MoveToEx(hdcOkno, 100, 170, &stary);
	LineTo(hdcOkno, 194, 170);
	SelectObject(hdcOkno, Pudelko);
	DeleteObject(CzarnePioro);
	ReleaseDC(hWnd, hdcOkno);
	zmienna = 0;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

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

	return (int)msg.wParam;
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

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WIN32PROJECT1);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

	HWND hWnd = CreateWindowW(szWindowClass, TEXT("Mój program"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	hText = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("STATIC"), NULL, WS_CHILD | WS_VISIBLE | SS_CENTER, 700, 70, 100, 20, hWnd, NULL, hInstance, NULL);
	SetWindowText(hText, TEXT("WAGA"));


	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("gora"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		10, 10,                                  // the left and top co-ordinates
		50, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON1,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("dol"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		70, 10,                                  // the left and top co-ordinates
		50, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON2,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Timer ON"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,  // the styles
		700, 10,                                  // the left and top co-ordinates
		100, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON3,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Timer OFF"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,  // the styles
		700, 40,                                  // the left and top co-ordinates
		100, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON4,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	//przyciski 1. piêtro

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 440,                                  // the left and top co-ordinates
		20, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON5,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("3"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 415,                                  // the left and top co-ordinates
		20, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON6,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("4"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 390,                                  // the left and top co-ordinates
		20, 20,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON7,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("5"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 365,                                  // the left and top co-ordinates
		20, 20,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON8,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	//przyciski 2 pietro

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		426, 365,                                  // the left and top co-ordinates
		20, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON9,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("3"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		426, 340,                                  // the left and top co-ordinates
		20, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON10,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("4"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		426, 315,                                  // the left and top co-ordinates
		20, 20,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON11,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("5"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		426, 290,                                  // the left and top co-ordinates
		20, 20,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON12,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	//przyciski 3 pietro

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 290,                                  // the left and top co-ordinates
		20, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON13,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 265,                                  // the left and top co-ordinates
		20, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON14,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("4"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 240,                                  // the left and top co-ordinates
		20, 20,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON15,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("5"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 215,                                  // the left and top co-ordinates
		20, 20,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON16,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	//przyciski 4 pietro

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		426, 215,                                  // the left and top co-ordinates
		20, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON17,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		426, 190,                                  // the left and top co-ordinates
		20, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON18,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("3"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		426, 165,                                  // the left and top co-ordinates
		20, 20,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON19,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("5"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		426, 140,                                  // the left and top co-ordinates
		20, 20,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON20,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	//przyciski 5 pietro

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 140,                                  // the left and top co-ordinates
		20, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON21,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 115,                                  // the left and top co-ordinates
		20, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON22,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("3"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 90,                                  // the left and top co-ordinates
		20, 20,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON23,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("4"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		50, 65,                                  // the left and top co-ordinates
		20, 20,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON24,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("<1>"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		10, 415,                                  // the left and top co-ordinates
		30, 30,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON25,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("<2>"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		460, 340,                                  // the left and top co-ordinates
		30, 30,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON26,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("<3>"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		10, 265,                                 // the left and top co-ordinates
		30, 30,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON27,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("<4>"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		460, 190,                                  // the left and top co-ordinates
		30, 30,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON28,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("<5>"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		10, 115,                                  // the left and top co-ordinates
		30, 30,                               // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON29,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);



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
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case ID_BUTTON1:
		{
			Czysc(hWnd);
			y -= 5;
		}
		break;
		case ID_BUTTON2:
		{
			Czysc(hWnd);
			y += 5;
		}
		break;
		case ID_BUTTON3:
		{
			SetTimer(hWnd, TMR_1, 1, 0);
		}
		break;
		case ID_BUTTON4:
		{
			KillTimer(hWnd, TMR_1);
		}
		break;
		case ID_BUTTON5:
		{
			//pietro 1 przycisk na pietro 2
			if (y == pietro1 - 150)
			{
				kolejkap.push(1);
				kolejkak.push(2);
				Czysc(hWnd);
				zmienna = rand()%70+50;
			}
		}
		break;
		case ID_BUTTON6:
		{
			if (y == pietro1 - 150)
			{
				kolejkap.push(1);
				kolejkak.push(3);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON7:
		{
			if (y == pietro1 - 150)
			{
				kolejkap.push(1);
				kolejkak.push(4);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON8:
		{
			//pietro 1 przycisk na pietro 5
			if (y == pietro1 - 150)
			{
				kolejkap.push(1);
				kolejkak.push(5);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON9:
		{
			//pietro 2 przycisk na pietro 1
			if (y == pietro2 - 150)
			{
				kolejkap.push(2);
				kolejkak.push(1);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON10:
		{
			if (y == pietro2 - 150)
			{
				kolejkap.push(2);
				kolejkak.push(3);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON11:
		{
			if (y == pietro2 - 150)
			{
				kolejkap.push(2);
				kolejkak.push(4);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON12:
		{
			//pietro 2 przycisk na pietro 5
			if (y == pietro2 - 150)
			{
				kolejkap.push(2);
				kolejkak.push(5);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;

		case ID_BUTTON13:
		{
			//pietro 3 przycisk na pietro 1
			if (y == pietro3 - 150)
			{
				kolejkap.push(3);
				kolejkak.push(1);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON14:
		{
			if (y == pietro3 - 150)
			{
				kolejkap.push(3);
				kolejkak.push(2);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON15:
		{
			if (y == pietro3 - 150)
			{
				kolejkap.push(3);
				kolejkak.push(4);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
			
		}
		break;
		case ID_BUTTON16:
		{
			//pietro 3 przycisk na pietro 5
			if (y == pietro3 - 150)
			{
				kolejkap.push(3);
				kolejkak.push(5);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON17:
		{
			//pietro 4 przycisk na pietro 1
			if (y == pietro4 - 150)
			{
				kolejkap.push(4);
				kolejkak.push(1);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON18:
		{
			if (y == pietro4 - 150)
			{
				kolejkap.push(4);
				kolejkak.push(2);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
			
		}
		break;
		case ID_BUTTON19:
		{
			if (y == pietro4 - 150)
			{
				kolejkap.push(4);
				kolejkak.push(3);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON20:
		{
			//pietro 4 przycisk na pietro 5
			if (y == pietro4 - 150)
			{
				kolejkap.push(4);
				kolejkak.push(5);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON21:
		{
			//pietro 5 przycisk na pietro 1
			if (y == pietro5 - 150)
			{
				kolejkap.push(5);
				kolejkak.push(1);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON22:
		{
			if (y == pietro5 - 150)
			{
				kolejkap.push(5);
				kolejkak.push(2);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON23:
		{
			if (y == pietro5 - 150)
			{
				kolejkap.push(5);
				kolejkak.push(3);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON24:
		{
			//pietro 5 przycisk na pietro 4
			if (y == pietro5 - 150)
			{
				kolejkap.push(5);
				kolejkak.push(4);
				Czysc(hWnd);
				zmienna = rand() % 70 + 50;
			}
		}
		break;
		case ID_BUTTON25:
		{
			przywolaj = 1;
		}
		break;
		case ID_BUTTON26:
		{
			przywolaj = 2;
		}
		break;
		case ID_BUTTON27:
		{
			przywolaj = 3;
		}
		break;
		case ID_BUTTON28:
		{
			przywolaj = 4;
		}
		break;
		case ID_BUTTON29:
		{
			przywolaj = 5;
		}
		break;

		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
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
			Draw(hWnd);
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
