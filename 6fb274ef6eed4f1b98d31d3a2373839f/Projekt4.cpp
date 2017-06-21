// Projekt4.cpp : Defines the entry point for the application.
//Krzysztof Kosiñski 165127
//Tomasz Ciborowski 165501
//C++
//Visual Studio 2015
//Zadanie nr 4.4


#include "stdafx.h"
#include "Projekt4.h"
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <ctime>

#define MAX_LOADSTRING 100


// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

struct polozenie {
	double x;
	double y;
};

class kwadrat {
public:
	kwadrat(int nowy_x, int nowy_y, int nowy_a, int nowy_w);
	void rysuj(Graphics &graphics, HDC hdc);
	polozenie pobierz_polozenie();
	int pobierz_bok();
	void przesun_kwadrat(int dodaj_x, int dodaj_y);
	void opadanie(bool kolizja, const int granica_dolna);
	int pobierz_wage();
private:
	polozenie p;
	int a;
	int waga;
	double v = 0; 
};
kwadrat::kwadrat(int nowy_x, int nowy_y, int nowy_a, int nowy_w) {
	p.x = nowy_x;
	p.y = nowy_y;
	a = nowy_a;
	waga = nowy_w;
}
void kwadrat::rysuj(Graphics &graphics, HDC hdc) {

	Pen pen(Color(255, 0, 0, 0));
	int b = a / 2;
	graphics.DrawRectangle(&pen, p.x-b, p.y, a, a);


	std::wstring string_a = std::to_wstring(waga);
	LPCWSTR string_b = string_a.c_str();
	TextOutW(hdc, p.x - a/2 + 1, p.y + 1, string_b, lstrlenW(string_b));
	
}
polozenie kwadrat::pobierz_polozenie() {
	return p;
}
int kwadrat::pobierz_bok() {
	return a;
}
void kwadrat::przesun_kwadrat(int dodaj_x, int dodaj_y) {
	p.x += dodaj_x;
	p.y += dodaj_y;
}
void kwadrat::opadanie(bool kolizja, const int granica_dolna) {
	if(!kolizja && p.y < granica_dolna - a - 0.5)
		v += 0.15;
	if (p.y <= granica_dolna - a && !kolizja) {
		p.y = p.y + v;
	} else {
		p.y = p.y - v;
		v = 0;
	}
	
	
}
int kwadrat::pobierz_wage() {
	return waga;
}

class dzwig {
	public:
		dzwig(HWND hWnd, int x, int y);
		~dzwig();
		void rysuj_calosc(HDC hdc);

		void dodaj_kwadrat(int x, int y, int a, int w);
		void usun_kwadrat(kwadrat* do_usuniecia);

		void rysuj_line(Graphics &graphics);
		void rysuj_kwadraty(Graphics &graphics, HDC hdc);
		void zaczep();
		void odczep();
		void przesun(int kierunek);
		bool czy_zaczepiony();
		void opadanie_kwadratow();
		bool kolizja(kwadrat* porownanie);

		void rysuj_menu(HDC hdc);
	private:
		const int granica_dolna = 425;
		const int granica_gorna = 54;
		const int granica_prawa = 540;
		const int granica_lewa = 130;
		const int dopuszczalna_waga = rand() % 200;

		kwadrat *zaczepiony;
		HWND *KopiaHWND;
		std::vector<kwadrat*> kwadraty;
		int x;
		int y;
		HBITMAP tlo;
};
dzwig::dzwig(HWND hWnd, int nowy_x, int nowy_y) {
	tlo = (HBITMAP)LoadImage(NULL, TEXT("dzwig.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	KopiaHWND = &hWnd;
	x = nowy_x;
	y = nowy_y;
	SetTimer(*KopiaHWND, ID_TIMER_1, 20, 0);
}
dzwig::~dzwig() {
	for (int i = kwadraty.size()-1; i >= 0; i--) {
		usun_kwadrat(kwadraty[i]);
	}
	KillTimer(*KopiaHWND, ID_TIMER_1);
}
void dzwig::rysuj_calosc(HDC hdc) {

	HDC memDC = CreateCompatibleDC(hdc);
	HBITMAP hMemBmp = CreateCompatibleBitmap(hdc, 640, 480);
	HBITMAP hOldBmp = (HBITMAP)SelectObject(memDC, hMemBmp);

	HDC TloDC = CreateCompatibleDC(hdc);
	HBITMAP TloOld = (HBITMAP)SelectObject(TloDC, tlo);

	BitBlt(memDC, 0, 0, 640, 480, TloDC, 0, 0, SRCCOPY);

	SelectObject(TloDC, TloOld);
	DeleteDC(TloDC);

	Graphics graphics(memDC);
	rysuj_line(graphics);
	rysuj_kwadraty(graphics, memDC);

	BitBlt(hdc, 50, 50, 640, 480, memDC, 0, 0, SRCCOPY);

	SelectObject(memDC, hOldBmp);
	DeleteObject(hMemBmp);
	DeleteDC(memDC);
}

void dzwig::dodaj_kwadrat(int x, int y, int a, int w) {
	kwadrat *kw = new kwadrat(x, y, a, w);
	if (!kolizja(kw))
		kwadraty.push_back(kw);	
}
void dzwig::usun_kwadrat(kwadrat *do_usuniecia) {
	if (do_usuniecia == NULL && zaczepiony != NULL) {
		do_usuniecia = zaczepiony;
	}
	for (int i = 0; i < kwadraty.size(); i++) {
		if (do_usuniecia == kwadraty[i]) {
			kwadraty.erase(kwadraty.begin() + i);
			break;
		}
	}
	if (do_usuniecia == zaczepiony) 
		zaczepiony = NULL;
	
	delete do_usuniecia;
}

void dzwig::rysuj_line(Graphics &graphics) {
	Pen pen(Color(255, 0, 0, 0));

	graphics.DrawLine(&pen, x, granica_gorna, x, y);
}
void dzwig::rysuj_kwadraty(Graphics &graphics, HDC hdc) {
	for (int i = 0; i < kwadraty.size(); i++) {
		kwadraty[i]->rysuj(graphics,hdc);
	}
}
void dzwig::przesun(int kierunek) {
	int bok = 0;
	if (zaczepiony != NULL) {
		bok = zaczepiony->pobierz_bok();
	}

	switch(kierunek){
		case 0: {
			if (x < granica_prawa) {
				if (zaczepiony != NULL && zaczepiony->pobierz_wage() <= dopuszczalna_waga){
					zaczepiony->przesun_kwadrat(1, 0);
					if (!kolizja(zaczepiony)) {
						x++;
					}
					else {
					zaczepiony->przesun_kwadrat(-1, 0);
					}

				}
				else if(zaczepiony == NULL)
					x++;
			}
			break;
		}
		case 90: {
			if (y > granica_gorna) {
				if (zaczepiony != NULL && zaczepiony->pobierz_wage() <= dopuszczalna_waga) {
						zaczepiony->przesun_kwadrat(0, -1);
					if (!kolizja(zaczepiony)) {
						y--;
					}
					else {
						zaczepiony->przesun_kwadrat(0, 1);
					}

				}
				else if(zaczepiony == NULL)
					y--;
			}
			break;
		}
		case 180: {
			if (x > granica_lewa) {
				if (zaczepiony != NULL && zaczepiony->pobierz_wage() <= dopuszczalna_waga) {
					zaczepiony->przesun_kwadrat(-1, 0);
					if (!kolizja(zaczepiony)) {
						x--;
					}
					else {
						zaczepiony->przesun_kwadrat(1, 0);
					}
				}
				else if(zaczepiony == NULL)
					x--;
				}
			break;
		}
		case 270: {
			if (y < granica_dolna - bok) {
				if (zaczepiony != NULL && zaczepiony->pobierz_wage() <= dopuszczalna_waga) {
					zaczepiony->przesun_kwadrat(0, 1);
					if (!kolizja(zaczepiony)) {
						y++;
					}
					else {
						zaczepiony->przesun_kwadrat(0, -1);
					}
					
				}
				else if(zaczepiony == NULL) 
					y++;
			}
			break;
		}
	}
}
void dzwig::zaczep() {
	for (int i = 0; i < kwadraty.size(); i++) {
		polozenie p = kwadraty[i]->pobierz_polozenie();
		if (abs(x - p.x) < 10 && abs(y - p.y) < 10) {
			zaczepiony = kwadraty[i];
			x = p.x;
			y = p.y;
		}
	}
}
void dzwig::odczep() {
	if (zaczepiony != NULL) {
		zaczepiony = NULL;
	}
}
bool dzwig::czy_zaczepiony() {
	if (zaczepiony == NULL)
		return false;
	else
		return true;
}
void dzwig::opadanie_kwadratow() {
	for (int i = 0; i < kwadraty.size(); i++) {
		if (zaczepiony != kwadraty[i]) {
			bool warunek = kolizja(kwadraty[i]);
			kwadraty[i]->opadanie(warunek, granica_dolna);
		}
	}
}
bool dzwig::kolizja(kwadrat* porownanie) {
	for (int i = 0; i < kwadraty.size(); i++) {
		if (porownanie != kwadraty[i]) {
			polozenie p1 = kwadraty[i]->pobierz_polozenie();
			polozenie p2 = porownanie->pobierz_polozenie();
			int a1 = kwadraty[i]->pobierz_bok();
			int a2 = porownanie->pobierz_bok();
			if (abs(p1.x - p2.x) <= (static_cast<double>(1) / 2)*(a1 + a2)) {
				if (p2.y < p1.y) {
					if ((p1.y - p2.y) <= a2 + 0.4) {
						return true;
					}
				} else {
					if ((p2.y - p1.y) <= a1 + 0.4) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

void dzwig::rysuj_menu(HDC hdc) {	
	TextOutW(hdc, 715, 50, L"Rozmiar :", 10);
	TextOutW(hdc, 715, 75, L"Waga :", 6);

	std::wstring string_a = std::to_wstring(dopuszczalna_waga);
	LPCWSTR string_b = string_a.c_str();

	TextOutW(hdc, 50, 550, L"Maksymalny udzwig - ", 23);
	TextOutW(hdc, 195, 550, string_b, lstrlenW(string_b));
	TextOutW(hdc, 50, 575, L"Strza³ki poruszaj¹ dŸwigiem", 28);
	TextOutW(hdc, 50, 600, L"Spacja - Zaczepia kwadrat", 25);
	TextOutW(hdc, 50, 625, L"X - usuwa zaczepiony kwadrat", 29);
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
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	srand(time(NULL));

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROJEKT4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJEKT4));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJEKT4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROJEKT4);
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
   HWND hwndButton;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("Dodaj"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   715, 100,                                  // the left and top co-ordinates
	   100, 50,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_B_DODAJ,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need

   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("Anuluj"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   835, 100,                                  // the left and top co-ordinates
	   100, 50,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_B_ANULUJ,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need

   hwndButton = CreateWindow(TEXT("edit"),                      // The class name required is button
	   TEXT("0"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | ES_NUMBER,  // the styles
	   800, 50,                                  // the left and top co-ordinates
	   100, 24,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_ROZMIAR,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need

   hwndButton = CreateWindow(TEXT("edit"),                      // The class name required is button
	   TEXT("0"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | ES_NUMBER,  // the styles
	   800, 75,                                  // the left and top co-ordinates
	   100, 24,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_WAGA,                   // the ID of your button
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
	HDC hdc;
	PAINTSTRUCT ps;
	static dzwig dzwig(hWnd, 200,200);

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case ID_B_DODAJ: {
				HWND hwnd_rozmiar = GetDlgItem(hWnd, ID_ROZMIAR);
				HWND hwnd_waga = GetDlgItem(hWnd, ID_WAGA);

				LPWSTR str_rozmiar = new wchar_t[20];
				GetWindowText(hwnd_rozmiar, str_rozmiar, GetWindowTextLength(hwnd_rozmiar) + 1);

				LPWSTR str_waga = new wchar_t[20];
				GetWindowText(hwnd_waga, str_waga, GetWindowTextLength(hwnd_waga) + 1);

				int rozmiar = _wtoi(str_rozmiar);
				int waga = _wtoi(str_waga);

				if (rozmiar > 0  && rozmiar <= 300 && waga > 0) {
					dzwig.dodaj_kwadrat(500, 100, rozmiar, waga);
				}

				::SetFocus(hWnd);
				break;
			}
			case ID_B_ANULUJ: {
				::SetFocus(hWnd);
				break;
			}
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
	case WM_KEYDOWN:
		{
			switch (wParam) 
			{
				case VK_SPACE: {
					if (dzwig.czy_zaczepiony())
						dzwig.odczep();
					else
						dzwig.zaczep();
					break;
				}
				case 'X': {
					if (dzwig.czy_zaczepiony())
						dzwig.usun_kwadrat(NULL);
					break;
				}
			}
			break;
		}
    case WM_PAINT:
        {
           hdc = BeginPaint(hWnd, &ps);
           
			dzwig.rysuj_menu(hdc);

           EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_TIMER:
	{
		switch (wParam) {
			case ID_TIMER_1: {
				
				dzwig.opadanie_kwadratow();
				

				if (GetAsyncKeyState(VK_RIGHT)) {
					dzwig.przesun(0);
				}
				if (GetAsyncKeyState(VK_UP)) {
					dzwig.przesun(90);
				}
				if (GetAsyncKeyState(VK_LEFT)) {
					dzwig.przesun(180);
				}
				if (GetAsyncKeyState(VK_DOWN)) {
					dzwig.przesun(270);
				}
				
				hdc = GetDC(hWnd);
			//	hdc = BeginPaint(hWnd, &ps);

				dzwig.rysuj_calosc(hdc);

			//	EndPaint(hWnd, &ps);

			//	InvalidateRect(hWnd, NULL, TRUE);
				ReleaseDC(hWnd, hdc);
			}
		}
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
