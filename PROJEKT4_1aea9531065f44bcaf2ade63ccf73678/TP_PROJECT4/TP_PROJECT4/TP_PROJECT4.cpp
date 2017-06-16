// TP_PROJECT4.cpp: Okreœla punkt wejœcia dla aplikacji.
//

#include "stdafx.h"
#include "TP_PROJECT4.h"
#include "Resource.h"
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define MAX_LOADSTRING 100

HPEN Pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
HPEN Pen2 = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
class HUMAN
{
public:
	int positionX;
	int positionY;
	int destination;
	int source;
	int weight;
	int number;
	void drawhuman(HDC hdc, int destination)
	{
		SelectObject(hdc, Pen);
		Ellipse(hdc, positionX - 20, positionY - 45, positionX, positionY - 25); //głowa
		Rectangle(hdc, positionX - 30, positionY - 25, positionX + 10, positionY); //ręce
		Rectangle(hdc, positionX - 20, positionY - 25, positionX, positionY); //brzuch
		Rectangle(hdc, positionX - 20, positionY, positionX - 10, positionY + 25); //lewa noga
		Rectangle(hdc, positionX - 10, positionY, positionX, positionY + 25); //prawa noga
		SelectObject(hdc, Pen2);
		switch (destination)
		{
		case 120:
			MoveToEx(hdc, positionX - 3, positionY - 60, NULL);
			LineTo(hdc, positionX - 3, positionY - 45);
			MoveToEx(hdc, positionX - 17, positionY - 60, NULL);
			LineTo(hdc, positionX - 17, positionY - 45);
		case 336:
			MoveToEx(hdc, positionX - 6, positionY - 60, NULL);
			LineTo(hdc, positionX - 6, positionY - 45);
			MoveToEx(hdc, positionX - 14, positionY - 60, NULL);
			LineTo(hdc, positionX - 14, positionY - 45);
		case 552:
			MoveToEx(hdc, positionX - 10, positionY - 60, NULL);
			LineTo(hdc, positionX - 10, positionY - 45);
			break;
		case 228:
			MoveToEx(hdc, positionX - 3, positionY - 60, NULL);
			LineTo(hdc, positionX - 3, positionY - 45);
			MoveToEx(hdc, positionX - 17, positionY - 60, NULL);
			LineTo(hdc, positionX - 17, positionY - 45);
		case 444:
			MoveToEx(hdc, positionX - 7, positionY - 60, NULL);
			LineTo(hdc, positionX - 7, positionY - 45);
			MoveToEx(hdc, positionX - 13, positionY - 60, NULL);
			LineTo(hdc, positionX - 13, positionY - 45);
			break;
		}
	}
};

// Zmienne globalne:
HINSTANCE hInst;                                // bie¿¹ce wyst¹pienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytu³u
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna g³ównego

// Przeka¿ dalej deklaracje funkcji do³¹czonych w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void move(HWND hWnd, PAINTSTRUCT &ps, int a, int b)
{
	valueTimer1 = a;			//żeby wpisać do windy polecenie zabrania ludzi z piętra, winda najpierw musi z niego odjechać
	if (controllerBlock)		//Blokada na wielokrotne wpisywanie polecenia wjazdu na to samo piętro
	{
		floors.push_back(a);
		controllerBlock = FALSE;
	}
	floors.push_back(b);
	repaintWindow(hWnd, hdc, ps);
	if (timerblock)
		SetTimer(hWnd, TMR_1, speed, 0);
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: W tym miejscu umieœæ kod.

    // Zainicjuj ci¹gi globalne
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TP_PROJECT4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Wykonaj inicjacje aplikacji:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TP_PROJECT4));

    MSG msg;

    // G³ówna pêtla wiadomoœci:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNKCJA: MyRegisterClass()
//
//  CEL: Rejestruje klasê okna.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TP_PROJECT4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TP_PROJECT4);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNKCJA: InitInstance(HINSTANCE, int)
//
//   CEL: Zapisuje dojœcie wyst¹pienia i tworzy okno g³ówne
//
//   KOMENTARZE:
//
//        W tej funkcji dojœcie wyst¹pienia jest zapisywane w zmiennej globalnej i
//        jest tworzone i wyœwietlane okno g³ówne programu.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Przechowuj dojœcie wyst¹pienia w zmiennej globalnej

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

  hwndButton = CreateWindow(TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 40, 20, 20, hWnd, (HMENU)ID_BUTTON_5_4, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 60, 20, 20, hWnd, (HMENU)ID_BUTTON_5_3, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 80, 20, 20, hWnd, (HMENU)ID_BUTTON_5_2, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 100, 20, 20, hWnd, (HMENU)ID_BUTTON_5_1, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle + 574, 148, 20, 20, hWnd, (HMENU)ID_BUTTON_4_5, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle + 574, 168, 20, 20, hWnd, (HMENU)ID_BUTTON_4_3, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle + 574, 188, 20, 20, hWnd, (HMENU)ID_BUTTON_4_2, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle + 574, 208, 20, 20, hWnd, (HMENU)ID_BUTTON_4_1, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 256, 20, 20, hWnd, (HMENU)ID_BUTTON_3_5, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 276, 20, 20, hWnd, (HMENU)ID_BUTTON_3_4, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 296, 20, 20, hWnd, (HMENU)ID_BUTTON_3_2, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 316, 20, 20, hWnd, (HMENU)ID_BUTTON_3_1, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle + 574, 364, 20, 20, hWnd, (HMENU)ID_BUTTON_2_5, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle + 574, 384, 20, 20, hWnd, (HMENU)ID_BUTTON_2_4, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle + 574, 404, 20, 20, hWnd, (HMENU)ID_BUTTON_2_3, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle + 574, 424, 20, 20, hWnd, (HMENU)ID_BUTTON_2_1, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 472, 20, 20, hWnd, (HMENU)ID_BUTTON_1_5, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 492, 20, 20, hWnd, (HMENU)ID_BUTTON_1_4, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 512, 20, 20, hWnd, (HMENU)ID_BUTTON_1_3, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, middle - 594, 532, 20, 20, hWnd, (HMENU)ID_BUTTON_1_2, hInstance, NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("START"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1000, 0, 50, 50, hWnd, (HMENU)ID_START, hInstance, NULL);
  
  
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNKCJA: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  CEL: Przetwarza wiadomoœci dla okna g³ównego.
//
//  WM_COMMAND — przetwarzaj menu aplikacji
//  WM_PAINT — pomaluj okno g³ówne
//  WM_DESTROY — opublikuj komunikat o rezygnacji i wróæ
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analizuj zaznaczenia menu:
            switch (wmId)
            {
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
            // TODO: tutaj dodaj kod rysowania u¿ywaj¹cy elementu hdc...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//Procedura obs³ugi wiadomoœci dla okna informacji o programie.
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
