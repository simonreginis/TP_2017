// WSKAZNIK.cpp: Okreœla punkt wejœcia dla aplikacji.
//

#include "stdafx.h"
#include "WSKAZNIK.h"
#include <list>
#include <iostream>

#define MAX_LOADSTRING 100

// Zmienne globalne:
HINSTANCE hInst;                                // bie¿¹ce wyst¹pienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytu³u
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna g³ównego

												// Przeka¿ dalej deklaracje funkcji do³¹czonych w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

HDC hdc;
HWND hWnd;
PAINTSTRUCT ps;
RECT drawArea1 = { 452, 2, 698, 528 };
int a = 400;
int r = 0;
int q = 0;
int p = 0;
int x = 200;
int y = 100;
int pietro = 1;
bool ruch = false;
bool czekaj = false;
bool otworz_drzwi = false;
bool zamknij_drzwi = false;
bool osoba = false;

int strona = 0;
int timer = 0;

bool ready = true;

std::list<int> kolejka;

//funkcje
#pragma region FunckjeSterujące

void RuchWindyG(HWND &hWnd)
{
	otworz_drzwi = true;
	KillTimer(hWnd, ID_TIMER);
	ruch = false;
	czekaj = false;
	pietro = 5;
	r = a;
	q = a;
}

void RuchWindyD(HWND &hWnd) 
{
	otworz_drzwi = true;
	KillTimer(hWnd, ID_TIMER1);
	ruch = false;
	czekaj = false;
	r = a;
	q = a;
}

void Zjazd(HWND &hWnd) {
	if (p == 1 && p < pietro)
	{
		if (a < 401) a++;
		if (a == 401)
		{
			RuchWindyD(hWnd);
			pietro = 1;
		}
	}
	if (p == 2 && p < pietro)
	{
		if (a < 301) a++;
		if (a == 301)
		{
			RuchWindyD(hWnd);
			pietro = 2;
		}
	}
	if (p == 3 && p < pietro)
	{
		if (a < 201) a++;
		if (a == 201)
		{
			RuchWindyD(hWnd);
			pietro = 3;
		}
	}
	if (p == 4 && p < pietro)
	{
		if (a < 101) a++;
		if (a == 101)
		{
			RuchWindyD(hWnd);
			pietro = 4;
		}
	}
}

void Wjazd(HWND &hWnd) {
	if (p == 5 && p > pietro)
	{
		if (a > 1) a--;
		if (a == 1)
		{
			RuchWindyG(hWnd);
			pietro = 5;
		}
	}

	if (p == 4 && p > pietro)
	{
		if (a > 101) a--;
		if (a == 101)
		{
			RuchWindyG(hWnd);
			pietro = 4;
		}
	}

	if (p == 3 && p > pietro)
	{
		if (a > 201) a--;
		if (a == 201)
		{
			RuchWindyG(hWnd);
			pietro = 3;
		}
	}

	if (p == 2 && p > pietro)
	{
		if (a > 301) a--;
		if (a == 301)
		{
			RuchWindyG(hWnd);
			pietro = 2;
		}
	}
}

int PodajA(int lv) 
{
	switch (lv){
	case 5: 
		return 1;
	default:
		return (5 - (lv % 5)) * 100;
	}
}

void PrzyciskPietra(int lv, int toLv) 
{

	if (pietro == lv)
	{
		kolejka.push_back(toLv);
		//kolejka.unique();
		//kolejka.sort();
	}
	else if (pietro != lv)
	{
		kolejka.push_back(lv);
		kolejka.push_back(toLv);
		//kolejka.unique();
		//kolejka.sort();
	}
}

void PracaWindy(HWND &hWnd, int lv, int toLv) {
		ruch = true;
		czekaj = false;
		osoba = true;
		a = PodajA(lv);
		p = toLv;
		if (toLv > lv)
			SetTimer(hWnd, ID_TIMER, 10, 0);
		else
			SetTimer(hWnd, ID_TIMER1, 10, 0);
		if (toLv % 2 == 0) strona = 2;
		else strona = 1;
		SetTimer(hWnd, ID_TIMER3, 10, 0);
}

int AktualnePietro() {
	if (a < 50) return 5;
	else if (a < 150) return 4;
	else if (a < 250) return 3;
	else if (a < 350) return 2;
	else if (a < 400)return 1;
}

#pragma endregion

#pragma region FunkcjeRysowania
void CzyOsoba() {
	if (osoba) TextOutW(hdc, 990, 40, L"TAK", 3);
	else TextOutW(hdc, 990, 40, L"NIE", 3);
}

void pokaz_timer()
{
	switch (timer){
	case 1: TextOutW(hdc, 900, 40, L"1", 1); break;
	case 2: TextOutW(hdc, 900, 40, L"2", 1); break;
	case 3: TextOutW(hdc, 900, 40, L"3", 1); break;
	case 4: TextOutW(hdc, 900, 40, L"4", 1); break;
	case 5: TextOutW(hdc, 900, 40, L"5", 1); break;
	default: TextOutW(hdc, 900, 40, L"0", 1); break;
	}
}
void pokaz_pietro()
{
	if (a < 50) TextOutW(hdc, 800, 40, L"5", 1);
	else if (a < 150) TextOutW(hdc, 800, 40, L"4", 1);
	else if (a < 250) TextOutW(hdc, 800, 40, L"3", 1);
	else if (a < 350) TextOutW(hdc, 800, 40, L"2", 1);
	else if (a < 400) TextOutW(hdc, 800, 40, L"1", 2);
}

void rysuj_szyb(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	graphics.DrawLine(&pen, 451, 1, 451, 529); //Rysowanie linii osi OX
	graphics.DrawLine(&pen, 699, 1, 699, 529); //Rysowanie linii osi OX
	graphics.DrawLine(&pen, 451, 1, 699, 1); //Rysowanie linii osi OY
	graphics.DrawLine(&pen, 451, 529, 699, 529); //Rysowanie linii osi OY

												 //rysujemy pietra
	Pen pen1(Color(255, 0, 0, 0));
	graphics.DrawLine(&pen1, 149, 100, 450, 100); //5pietro
	graphics.DrawLine(&pen1, 701, 200, 1000, 200); //4pietro
	graphics.DrawLine(&pen1, 149, 300, 450, 300); //3pietro
	graphics.DrawLine(&pen1, 701, 400, 1000, 400); //2pietro
	graphics.DrawLine(&pen1, 149, 500, 450, 500); //1pietro
}

void szyb_windy(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps)
{
	hdc = BeginPaint(hWnd, &ps);
	rysuj_szyb(hdc);
	EndPaint(hWnd, &ps);
}

void rysuj_winde(HDC &hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 0, 0));
	graphics.DrawRectangle(&pen, 454, a, 242, 98);
}

void pokaz_winde(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps)
{
	InvalidateRect(hWnd, &drawArea1, TRUE);
	hdc = BeginPaint(hWnd, &ps);
	rysuj_winde(hdc);
	EndPaint(hWnd, &ps);
}

void rysuj_drzwiL(HDC &hdc, int r, int q)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, 451, r, 451, q); //Rysowanie linii osi OX
	graphics.DrawLine(&pen, 454, r, 454, q); //Rysowanie linii osi OX
}

void rysuj_drzwiL_zamkniete(HDC &hdc, int r, int q)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	Pen pen1(Color(255, 255, 0, 0));
	graphics.DrawLine(&pen, 451, r, 451, r - 1); //Rysowanie linii osi OX
	graphics.DrawLine(&pen1, 454, r, 454, r - 1); //Rysowanie linii osi OX
}

void rysuj_drzwiP(HDC &hdc, int r, int q)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, 699, r, 699, q); //Rysowanie linii osi OX
	graphics.DrawLine(&pen, 696, r, 696, q); //Rysowanie linii osi OX
}

void rysuj_drzwiP_zamkniete(HDC &hdc, int r, int q)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	Pen pen1(Color(255, 255, 0, 0));
	graphics.DrawLine(&pen, 699, r, 699, r - 1); //Rysowanie linii osi OX
	graphics.DrawLine(&pen1, 696, r, 696, r - 1); //Rysowanie linii osi OX
}
#pragma endregion

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: W tym miejscu umieœæ kod.
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);
	// Zainicjuj ci¹gi globalne
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WSKAZNIK, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Wykonaj inicjacje aplikacji:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WSKAZNIK));

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
	return (int)msg.wParam;
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
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WSKAZNIK));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WSKAZNIK);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
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

	HWND hWndbutton = CreateWindow(TEXT("button"),
		TEXT("4"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 1,
		20, 20,
		hWnd,
		(HMENU)BUTTON5_1,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 21,
		20, 20,
		hWnd,
		(HMENU)BUTTON5_2,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 41,
		20, 20,
		hWnd,
		(HMENU)BUTTON5_3,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 61,
		20, 20,
		hWnd,
		(HMENU)BUTTON5_4,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("5"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		980, 101,
		20, 20,
		hWnd,
		(HMENU)BUTTON4_1,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		980, 121,
		20, 20,
		hWnd,
		(HMENU)BUTTON4_2,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		980, 141,
		20, 20,
		hWnd,
		(HMENU)BUTTON4_3,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		980, 161,
		20, 20,
		hWnd,
		(HMENU)BUTTON4_4,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("5"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 201,
		20, 20,
		hWnd,
		(HMENU)BUTTON3_1,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("4"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 221,
		20, 20,
		hWnd,
		(HMENU)BUTTON3_2,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 241,
		20, 20,
		hWnd,
		(HMENU)BUTTON3_3,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 261,
		20, 20,
		hWnd,
		(HMENU)BUTTON3_4,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("5"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		980, 301,
		20, 20,
		hWnd,
		(HMENU)BUTTON2_1,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("4"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		980, 321,
		20, 20,
		hWnd,
		(HMENU)BUTTON2_2,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		980, 341,
		20, 20,
		hWnd,
		(HMENU)BUTTON2_3,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		980, 361,
		20, 20,
		hWnd,
		(HMENU)BUTTON2_4,
		GetModuleHandle(NULL), NULL);


	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("5"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 401,
		20, 20,
		hWnd,
		(HMENU)BUTTON1_1,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("4"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 421,
		20, 20,
		hWnd,
		(HMENU)BUTTON1_2,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 441,
		20, 20,
		hWnd,
		(HMENU)BUTTON1_3,
		GetModuleHandle(NULL), NULL);

	hWndbutton = CreateWindow(TEXT("button"),
		TEXT("2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		150, 461,
		20, 20,
		hWnd,
		(HMENU)BUTTON1_4,
		GetModuleHandle(NULL), NULL);

	HWND groupBox = CreateWindow(TEXT("BUTTON"),
		TEXT("Pietro"),
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX | WS_GROUP,
		780, 20,
		50, 50,
		hWnd, NULL, hInstance, 0);

	groupBox = CreateWindow(TEXT("BUTTON"),
		TEXT("Timer"),
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX | WS_GROUP,
		880, 20,
		50, 50,
		hWnd, NULL, hInstance, 0);

	groupBox = CreateWindow(TEXT("BUTTON"),
		TEXT("Osoba?"),
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX | WS_GROUP,
		980, 20,
		50, 50,
		hWnd, NULL, hInstance, 0);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	szyb_windy(hWnd, hdc, ps);
	pokaz_winde(hWnd, hdc, ps);

	pokaz_pietro();
	pokaz_timer();
	CzyOsoba();

	SetTimer(hWnd, ID_TIMER_CONTROL, 10, 0);
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
	PAINTSTRUCT ps;
	HDC hdc;
	switch (message)
	{
	case WM_COMMAND:
	{
		HDC hdc;

		int wmId = LOWORD(wParam);
		// Analizuj zaznaczenia menu:
		switch (wmId)
		{
		case IDM_ABOUT:
		{
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		}
		case IDM_EXIT:
		{
			DestroyWindow(hWnd);
			break;
		}
			break;
		case BUTTON1_1://1
		{
			PrzyciskPietra(1,5);
			break;
		}

		case BUTTON1_2:
		{
			PrzyciskPietra(1,4);
			break;
		}

		case BUTTON1_3:
		{
			PrzyciskPietra(1,3);
			break;
		}

		case BUTTON1_4:
		{
			PrzyciskPietra(1,2);
			break;
		}

		case BUTTON2_1://2
		{
			PrzyciskPietra(2,5);
			break;
		}

		case BUTTON2_2:
		{
			PrzyciskPietra(2,4);
			break;
		}

		case BUTTON2_3:
		{
			PrzyciskPietra(2,3);
			break;
		}

		case BUTTON2_4:
		{
			PrzyciskPietra(2,1);
			break;
		}

		case BUTTON3_1://3
		{
			PrzyciskPietra(3,5);
			break;
		}

		case BUTTON3_2:
		{
			PrzyciskPietra(3,4);
			break;
		}

		case BUTTON3_3:
		{
			PrzyciskPietra(3,2);
			break;
		}

		case BUTTON3_4:
		{
			PrzyciskPietra(3,1);
			break;
		}

		case BUTTON4_1://4
		{
			PrzyciskPietra(4,5);
			break;
		}

		case BUTTON4_2:
		{
			PrzyciskPietra(4,3);
			break;
		}

		case BUTTON4_3:
		{
			PrzyciskPietra(4,2);
			break;
		}

		case BUTTON4_4:
		{
			PrzyciskPietra(4,1);
			break;
		}

		case BUTTON5_4://5
		{
			PrzyciskPietra(5,1);
			break;
		}

		case BUTTON5_3:
		{
			PrzyciskPietra(5,2);
			break;
		}

		case BUTTON5_2:
		{
			PrzyciskPietra(5,3);
			break;
		}

		case BUTTON5_1:
		{
			PrzyciskPietra(5,4);
			break;
		}

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{

		// HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: tutaj dodaj kod rysowania u¿ywaj¹cy elementu hdc...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
	{
		switch (wParam)
		{
			case ID_TIMER: // wjazd windy
			{
				hdc = GetDC(hWnd);
				pokaz_winde(hWnd, hdc, ps);
				pokaz_pietro();
				ReleaseDC(hWnd, hdc);

				Wjazd(hWnd);

				break;
			}

			case ID_TIMER1: // zjazd windy
			{
				hdc = GetDC(hWnd);
				pokaz_winde(hWnd, hdc, ps);
				pokaz_pietro();
				ReleaseDC(hWnd, hdc);

				Zjazd(hWnd);

				break;
			}

			case ID_TIMER3: // rysowanie drzwi
			{
				hdc = GetDC(hWnd);
				CzyOsoba();
				if (strona == 1)
				{
					if (otworz_drzwi)
					{
						rysuj_drzwiL(hdc, r, q);
						if (r < a + 100)r++;
						if (q < a + 40) q++;

						if (r == a + 100)
						{
							otworz_drzwi = false;
							zamknij_drzwi = true;
						}
					}
					CzyOsoba();
					if (zamknij_drzwi)
					{
						rysuj_drzwiL_zamkniete(hdc, r, q);
						if (r > a)r--;

						if (r == a)
						{
							zamknij_drzwi = false;
							KillTimer(hWnd, ID_TIMER3);
							SetTimer(hWnd, ID_TIMER_CONTROL, 10, 0);
						}

					}
				}
				CzyOsoba();
				if (strona == 2)
				{
					if (otworz_drzwi)
					{
						rysuj_drzwiP(hdc, r, q);
						if (r < a + 100)r++;
						if (q < a + 40) q++;

						if (r == a + 100)
						{
							otworz_drzwi = false;
							zamknij_drzwi = true;
						}
					}
					CzyOsoba();
					if (zamknij_drzwi)
					{
						rysuj_drzwiP_zamkniete(hdc, r, q);
						if (r > a) r--;
						if (r == a)
						{
							zamknij_drzwi = false;

							KillTimer(hWnd, ID_TIMER3);
							SetTimer(hWnd, ID_TIMER_CONTROL, 10, 0);
						}

					}
				}
				CzyOsoba();
				ReleaseDC(hWnd, hdc);
				break;
			}

			case ID_TIMER5: // liczenie 5 sek i wracanie na 1v
			{
				timer++;
				if (timer >= 5 && !osoba && pietro != 1) {
					timer = 0;
					p = 1;
					strona = 1;
					SetTimer(hWnd, ID_TIMER1, 10, 0);
					KillTimer(hWnd, ID_TIMER5);

					SetTimer(hWnd, ID_TIMER3, 10, 0);
					SetTimer(hWnd, ID_TIMER_CONTROL, 10, 0);
				}
				if (ruch || pietro == 1) {
					timer = 0;
					KillTimer(hWnd, ID_TIMER5);
					SetTimer(hWnd, ID_TIMER_CONTROL, 10, 0);
				}
				pokaz_timer();
			}

			case ID_TIMER_CONTROL:
			{
				kolejka.unique();
				for (std::list<int>::iterator i = kolejka.begin(); i != kolejka.end(); i++) {
					std::cout << *i << " ";
				}
				std::cout << std::endl;


				if (kolejka.empty()) ready = true;
				else ready = false;
				
				if (ready) {
					osoba = false;
					SetTimer(hWnd, ID_TIMER5, 1000, 0);
					KillTimer(hWnd, ID_TIMER_CONTROL);
				}else{
					PracaWindy(hWnd, pietro, kolejka.front());
					kolejka.pop_front();
					KillTimer(hWnd, ID_TIMER_CONTROL);
				}
				CzyOsoba();
			}
		}
	}
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

