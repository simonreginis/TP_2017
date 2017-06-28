#include "stdafx.h"
#include "draw2.h"
#include <vector>
#include <fstream>
#include <gdiplus.h>
using namespace Gdiplus;



#define MAX_LOADSTRING 100
#define TMR_1 1
#define pi 3.14159265358979

// Global Variables:
HINSTANCE hInst;	// current instance
TCHAR szTitle[MAX_LOADSTRING];	// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];	// the main window class name


bool ConnectedToBox1 = false;
bool ConnectedToBox2 = false;

const int mass1 = 240;
const int mass2 = 200;





void DrawHook(HDC hdc, int x1, int y1, int x2, int y2)
{

	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 0));
	graphics.DrawLine(&pen, x1, y1 + 5, x2, y2);
	graphics.DrawLine(&pen, x1 - 45, 130, x2, 165);
	graphics.DrawLine(&pen, x1 + 45, 130, x2, 165);
	graphics.DrawEllipse(&pen, x1 + 42, 126, 10, 10);
	graphics.DrawEllipse(&pen, x1 - 50, 126, 10, 10);
	graphics.DrawEllipse(&pen, x1 - 5, 126, 10, 10);
	graphics.DrawLine(&pen, x1 + 50, 130, x2, 135);
	graphics.DrawLine(&pen, x1 - 50, 130, x2, 135);


}

void EraseHook(HDC hdc, int x1, int y1, int x2, int y2)
{

	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, x1, y1 + 5, x2, y2);
	graphics.DrawLine(&pen, x1 - 45, 130, x2, 165);
	graphics.DrawLine(&pen, x1 + 45, 130, x2, 165);
	graphics.DrawEllipse(&pen, x1 + 42, 126, 10, 10);
	graphics.DrawEllipse(&pen, x1 - 50, 126, 10, 10);
	graphics.DrawEllipse(&pen, x1 - 5, 126, 10, 10);
	graphics.DrawLine(&pen, x1 + 50, 130, x2, 135);
	graphics.DrawLine(&pen, x1 - 50, 130, x2, 135);

}

void DrawBox1(HDC hdc, int x1, int y1)
{

	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 0));
	graphics.DrawRectangle(&pen, x1, y1, 50, 50);


}

void EraseBox1Left(HDC hdc, int x1, int y1)
{
	int y2 = y1 + 50;
	int x2 = x1 + 50;
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, x1 + 2, y1 - 1, x1 + 2, y2 + 1);
	graphics.DrawLine(&pen, x2 + 2, y1 - 1, x2 + 2, y2 + 1);


}

void EraseBox1Right(HDC hdc, int x1, int y1)
{
	int y2 = y1 + 50;
	int x2 = x1 + 50;
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, x1 - 2, y1 - 1, x1 - 2, y2 + 1);
	graphics.DrawLine(&pen, x2 - 2, y1 - 1, x2 - 2, y2 + 1);


}

void EraseBox1Up(HDC hdc, int x1, int y1)
{
	int y2 = y1 + 50;
	int x2 = x1 + 50;
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, x1 - 1, y1 + 1, x2 + 1, y1 + 1);
	graphics.DrawLine(&pen, x1 - 1, y2 + 1, x2 + 1, y2 + 1);

}

void EraseBox1Down(HDC hdc, int x1, int y1)
{
	int y2 = y1 + 50;
	int x2 = x1 + 50;
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, x1 - 1, y1 - 1, x2 + 1, y1 - 1);
	graphics.DrawLine(&pen, x1 - 1, y2 - 1, x2 + 1, y2 - 1);

}

void DrawBox2(HDC hdc, int x1, int y1)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 0));
	graphics.DrawRectangle(&pen, x1, y1, 50, 50);

}

void EraseBox2Left(HDC hdc, int x1, int y1)
{
	int y2 = y1 + 50;
	int x2 = x1 + 50;
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, x1 + 2, y1 - 1, x1 + 2, y2 + 1);
	graphics.DrawLine(&pen, x2 + 2, y1 - 1, x2 + 2, y2 + 1);


}

void EraseBox2Right(HDC hdc, int x1, int y1)
{
	int y2 = y1 + 50;
	int x2 = x1 + 50;
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, x1 - 2, y1 - 1, x1 - 2, y2 + 1);
	graphics.DrawLine(&pen, x2 - 2, y1 - 1, x2 - 2, y2 + 1);


}

void EraseBox2Up(HDC hdc, int x1, int y1)
{
	int y2 = y1 + 50;
	int x2 = x1 + 50;
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, x1 - 1, y1 + 1, x2 + 1, y1 + 1);
	graphics.DrawLine(&pen, x1 - 1, y2 + 1, x2 + 1, y2 + 1);

}

void EraseBox2Down(HDC hdc, int x1, int y1)
{
	int y2 = y1 + 50;
	int x2 = x1 + 50;
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, x1 - 1, y1 - 1, x2 + 1, y1 - 1);
	graphics.DrawLine(&pen, x1 - 1, y2 - 1, x2 + 1, y2 - 1);

}


// Forward declarations of functions included in this code module:
ATOM	MyRegisterClass(HINSTANCE hInstance);
BOOL	InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Buttons(HWND, UINT, WPARAM, LPARAM);


void MyOnPaint(HDC hdc)
{


	Graphics graphics(hdc);

	Pen pen(Color(255, 249, 224, 75));
	Pen pen2(Color(255, 0, 0, 0));

	for (int i = 0; i < 1000; i++)
	{
		graphics.DrawRectangle(&pen, 100, i + 41, 20, 20);
		graphics.DrawRectangle(&pen, i - 5, 105, 20, 20);
		graphics.DrawLine(&pen, i - 5, 105, 15 + i, 125);
		graphics.DrawLine(&pen, 100, i + 41, 120, 61 + i);
		graphics.DrawLine(&pen, 120, i + 41, 100, 61 + i);

		graphics.DrawLine(&pen, 1002, 105, 1022, 125);
		graphics.DrawLine(&pen, 1002, 125, 1022, 125);

		graphics.DrawLine(&pen2, 110, 0, -5, 105);
		graphics.DrawLine(&pen2, 110, 0, 225, 105);
		graphics.DrawLine(&pen2, 110, 0, 435, 105);
		graphics.DrawLine(&pen2, 110, 0, 645, 105);
		graphics.DrawLine(&pen2, 110, 0, 855, 105);
		graphics.DrawLine(&pen2, 110, 0, 1002, 105);
		graphics.DrawRectangle(&pen2, 109, 0, 1, 40);
		graphics.DrawLine(&pen2, 100, 41, 110, 0);
		graphics.DrawLine(&pen2, 120, 41, 110, 0);

		graphics.DrawRectangle(&pen2, -5, 105, 20, 80);
		graphics.DrawRectangle(&pen2, 16, 105, 20, 80);
		graphics.DrawRectangle(&pen2, 37, 105, 20, 80);
		graphics.DrawRectangle(&pen2, 58, 105, 20, 80);

		graphics.DrawRectangle(&pen2, 50, 715, 120, 1);
		graphics.DrawRectangle(&pen2, 55, 713, 110, 1);
		graphics.DrawRectangle(&pen2, 60, 711, 100, 1);
		graphics.DrawRectangle(&pen2, 65, 709, 90, 1);
		graphics.DrawRectangle(&pen2, 70, 707, 80, 1);
		graphics.DrawRectangle(&pen2, 75, 705, 70, 1);
		graphics.DrawRectangle(&pen2, 80, 703, 60, 1);
		graphics.DrawRectangle(&pen2, 85, 701, 50, 1);
		graphics.DrawRectangle(&pen2, 85, 699, 50, 1);
		graphics.DrawRectangle(&pen2, 85, 697, 50, 1);
		graphics.DrawRectangle(&pen2, 85, 695, 50, 1);
		graphics.DrawRectangle(&pen2, 85, 693, 50, 1);

		graphics.DrawRectangle(&pen2, 200, 652, 800, 500);

		for (int j = 0; j < 100; j++)
		{
			graphics.DrawLine(&pen2, 200, 653 + j, 1000, 653 + j);
		}

		i += 20;
	}
}


// main function (exe hInstance)
int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine,
	int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	//USTAWIANIE STALYCH I LICZNIKA

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);



	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;


	hInst = hInstance;

	// main window
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	// create button and store the handle

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// MENU & BUTTON messages
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
		break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		// TODO: Add any drawing code here (not depend on timer, buttons)
		MyOnPaint(hdc);

		int ib1 = 355;
		int jb1 = 600;
		int ib2 = 755;
		int jb2 = 600;
		int ih = 355;
		int jh = 545;

		
		DrawBox1(hdc, ib1, jb1);
		DrawBox2(hdc, ib2, jb2);
		DrawHook(hdc, 355, 126, 355, 546);

		


		while (1)
		{
			Graphics graphics(hdc);
			Pen pen(Color(255, 0, 0, 0));
			graphics.DrawRectangle(&pen, 600, 300, 30, 351);
			for (int j = 0; j < 31; j++)
			{
				graphics.DrawLine(&pen, 600 + j, 300, 600 + j, 651);
			}
			if (GetAsyncKeyState(' ') && ConnectedToBox2 == false && ih >= ib2 && ih <= ib2 + 50 && jh >= 597) {
				ConnectedToBox2 = true;
				Sleep(200);
			}
			if (GetAsyncKeyState(' ') && ConnectedToBox1 == false && ih >= ib1 && ih <= ib1 + 50 && jh >= 597) {
				ConnectedToBox1 = true;
				Sleep(200);
			}

			if (GetAsyncKeyState(' ') && ConnectedToBox1 == true && jb1 >= 599) {
				ConnectedToBox1 = false;
				Sleep(200);
			}
			if (GetAsyncKeyState(' ') && ConnectedToBox2 == true && jb2 >= 599) {
				ConnectedToBox2 = false;
				Sleep(200);
			}


			if (ConnectedToBox1) {

				if (GetAsyncKeyState(VK_RIGHT))
				{
					DrawHook(hdc, ih, 126, ih, jh);
					EraseHook(hdc, ih - 1, 126, ih - 1, jh + 1);
					DrawBox1(hdc, ib1, jb1);
					EraseBox1Right(hdc, ib1 + 1, jb1);
					if (ib1 < 573 && ih < 573 && mass1 <= 250) {
						ib1++;
						ih++;
					}
				}

				if (GetAsyncKeyState(VK_LEFT))
				{
					DrawHook(hdc, ih, 126, ih, jh);
					EraseHook(hdc, ih + 1, 126, ih + 1, jh + 1);
					DrawBox1(hdc, ib1, jb1);
					EraseBox1Left(hdc, ib1 - 1, jb1);
					if (ib1 > 170 && ih > 170 && mass1 <= 250) {
						ib1--;
						ih--;
					}
				}

				if (GetAsyncKeyState(VK_UP))
				{
					EraseHook(hdc, ih, 126, ih, jh + 1);
					EraseHook(hdc, ih + 1, 126, ih + 1, jh + 1);
					EraseHook(hdc, ih - 1, 126, ih - 1, jh + 1);
					DrawHook(hdc, ih, 126, ih, jh);
					DrawBox1(hdc, ib1, jb1);
					EraseBox1Up(hdc, ib1, jb1);
					if (jb1 > 300 && jh > 300 && mass1 <= 250) {
						jb1--;
						jh--;
					}
				}

				if (GetAsyncKeyState(VK_DOWN))
				{
					EraseHook(hdc, ih, 126, ih, jh);
					EraseHook(hdc, ih + 1, 126, ih + 1, jh);
					EraseHook(hdc, ih - 1, 126, ih - 1, jh);
					DrawHook(hdc, ih, 126, ih, jh);
					DrawBox1(hdc, ib1, jb1);
					EraseBox1Down(hdc, ib1, jb1);
					if (jb1 < 600 && jh < 600 && mass1 <= 250) {
						jb1++;
						jh++;
					}

				}
				if (GetAsyncKeyState('P')) break;
			}
			else if (ConnectedToBox2) {
				if (GetAsyncKeyState(VK_RIGHT))
				{
					DrawHook(hdc, ih, 126, ih, jh);
					EraseHook(hdc, ih - 1, 126, ih - 1, jh + 1);
					DrawBox2(hdc, ib2, jb2);
					EraseBox2Right(hdc, ib2 + 1, jb2);
					if (ib2 < 951 && ih < 951 && mass2 <= 250) {
						ib2++;
						ih++;
					}
				}

				if (GetAsyncKeyState(VK_LEFT))
				{
					DrawHook(hdc, ih, 126, ih, jh);
					EraseHook(hdc, ih + 1, 126, ih + 1, jh + 1);
					DrawBox2(hdc, ib2, jb2);
					EraseBox2Left(hdc, ib2 - 1, jb2);
					if (ib2 > 632 && ih > 632 && mass2 <= 250) {
						ib2--;
						ih--;
					}
				}

				if (GetAsyncKeyState(VK_UP))
				{
					EraseHook(hdc, ih, 126, ih, jh + 1);
					EraseHook(hdc, ih + 1, 126, ih + 1, jh + 1);
					EraseHook(hdc, ih - 1, 126, ih - 1, jh + 1);
					DrawHook(hdc, ih, 126, ih, jh);
					DrawBox2(hdc, ib2, jb2);
					EraseBox2Up(hdc, ib2, jb2);
					if (jb2 > 300 && jh > 300 && mass2 <= 250) {
						jb2--;
						jh--;
					}
				}

				if (GetAsyncKeyState(VK_DOWN))
				{
					EraseHook(hdc, ih, 126, ih, jh);
					EraseHook(hdc, ih + 1, 126, ih + 1, jh);
					EraseHook(hdc, ih - 1, 126, ih - 1, jh);
					DrawHook(hdc, ih, 126, ih, jh);
					DrawBox2(hdc, ib2, jb2);
					EraseBox2Down(hdc, ib2, jb2);
					if (jb2 < 599 && jh < 599 && mass2 <= 250) {
						jb2++;
						jh++;
					}

				}
				if (GetAsyncKeyState('P')) break;
			}
			else {
				if (GetAsyncKeyState(VK_RIGHT))
				{
					DrawHook(hdc, ih, 126, ih, jh);
					EraseHook(hdc, ih - 1, 126, ih - 1, jh + 1);
					if (ih < 950) ih++;
				}

				if (GetAsyncKeyState(VK_LEFT))
				{
					DrawHook(hdc, ih, 126, ih, jh);
					EraseHook(hdc, ih + 1, 126, ih + 1, jh + 1);
					if (ih > 172) ih--;
				}

				if (GetAsyncKeyState(VK_UP))
				{
					EraseHook(hdc, ih, 126, ih, jh + 1);
					EraseHook(hdc, ih + 1, 126, ih + 1, jh + 1);
					EraseHook(hdc, ih - 1, 126, ih - 1, jh + 1);
					DrawHook(hdc, ih, 126, ih, jh);
					if (jh > 172) jh--;
				}

				if (GetAsyncKeyState(VK_DOWN))
				{
					EraseHook(hdc, ih, 126, ih, jh);
					EraseHook(hdc, ih + 1, 126, ih + 1, jh);
					EraseHook(hdc, ih - 1, 126, ih - 1, jh);
					DrawHook(hdc, ih, 126, ih, jh);
					if (jh <598) jh++;
				}
				if (GetAsyncKeyState('P')) break;
			}
		}
	}



	EndPaint(hWnd, &ps);

	break;
	case WM_CTLCOLORSTATIC:

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

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