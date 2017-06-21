// Win32Project2.cpp: Okreœla punkt wejœcia dla aplikacji.

#include "stdafx.h"
#include "Win32Project2.h"
#include "Lift1.h"
#include "Flamingo.h"
#include <vector>
#include <list>

#define MAX_LOADSTRING 100
int value = 0;
bool moved = false;

// Zmienne globalne:
HINSTANCE hInst;                                // bie¿¹ce wyst¹pienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytu³u
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna g³ównego

												// Przeka¿ dalej deklaracje funkcji do³¹czonych w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

std::vector<Flamingo*> floor0;
std::vector<Flamingo*> floor1;
std::vector<Flamingo*> floor2;
std::vector<Flamingo*> floor3;
std::vector<Flamingo*> floor4;
std::vector<Flamingo*> InLift;
std::vector<Flamingo*> tab[5] = {floor0, floor1, floor2, floor3, floor4};

std::vector<int> nextFloors;

std::list<int> queue;


HWND hWnd;
HWND hwndButton;
PAINTSTRUCT ps;
HDC hdc;
bool isMoving = false; //czy winda sie rusza- do wykrywania kiedy flamingi maja sie nie wpychac do windy
int howMany = 0; //ile stworzono flamingow

bool door = false;
const int MAX_N = 9;
const int MAX_F = 5;
bool allFlamingosInLift = false;

Lift1 newLift(0,0,0);

RECT drawArea1 = { 301, 0, 700, 650 };
RECT drawArea2 = { 0, 0, 300, 650 };
RECT drawArea3 = { 701, 0, 1000, 650 };
RECT drawArea4 = { 306, 30, 695, 640 };

void repaintWindow(RECT *drawArea1, RECT *drawArea2, RECT *drawArea3)
{
	InvalidateRect(hWnd, drawArea1, TRUE);
	hdc = BeginPaint(hWnd, &ps);
	newLift.DrawLift(hdc);
	EndPaint(hWnd, &ps);
	InvalidateRect(hWnd, drawArea2, TRUE);
	hdc = BeginPaint(hWnd, &ps);
	newLift.OnLeft(hdc);
	EndPaint(hWnd, &ps);
	InvalidateRect(hWnd, drawArea3, TRUE);
	hdc = BeginPaint(hWnd, &ps);
	newLift.OnRight(hdc);
	EndPaint(hWnd, &ps);
}


void inLift()
{
	int actualFloor = newLift.GetFromFloor();
	int size = (tab[actualFloor]).size();
	if (size != 0)
	{
		std::vector<Flamingo*>::iterator it;
		for (it = tab[actualFloor].begin(); it != tab[actualFloor].end(); it++)
		{
			bool flamingoInLift = (*it)->GetInLift();
			if ((InLift.size() != MAX_N) && !flamingoInLift)
			{
				newLift.ChangeLiftMovedToFalse();
				InLift.push_back(*it);
				(*it)->ChangeInLiftToTrue();
			}
		}
	}
}

void canMove()
{
	int actualFloor = newLift.GetFromFloor();
	int i = 0;
	int j = 0;
	std::vector<Flamingo*>::iterator it;
	for (it = InLift.begin(); it != InLift.end(); it++)
	{
		if ((*it)->GetInLift()) j++;
	}
	std::vector<Flamingo*>::iterator it2;
	for (it2 = InLift.begin(); it2 != InLift.end(); it2++)
	{
		bool flamingoIsDraw = (*it2)->GetIsDrawn();
		int fromFloor = (*it2)->GetFromFloor();
		(*it2)->DrawFlamingo();
		if (flamingoIsDraw)	i++;
		if (i == j)
		{
			if (fromFloor != 0) newLift.SetFromFloor(actualFloor);
			newLift.SetToFloor(nextFloors.at(0));
			SetTimer(hWnd, ID_TIMER_1, 25, NULL);
		}
		else if (!flamingoIsDraw) i = 0;
	}
}

void cleanFloors()
{
	for (int i = 0; i < MAX_F; i++)
	{
		std::vector<Flamingo*>::iterator it1;	//usuwamy z piêtra flamingi, które wsiad³y
		for (it1 = tab[i].begin(); it1 != tab[i].end(); it1++)
		{
			bool flamingoInLift = (*it1)->GetInLift();
			if (flamingoInLift)
			{
				tab[i].erase(it1);
				break;
			}
		}
	}
}

void theWalkingFlamingo(int pom)
{
		bool flamingoIsDraw = false;
		std::vector<Flamingo*>::iterator it;
		if (pom == 0)
		{
			for (int i = 0; i < MAX_F; i++)
				for (it = tab[i].begin(); it != tab[i].end(); it++)
					(*it)->DrawFlamingo();
			if (pom == -1)
			{
				InLift.erase(it);
			}
		}
		else if (pom == 1)
		{
			for (it = InLift.begin(); it != InLift.end(); it++)
			{
				flamingoIsDraw = (*it)->GetIsDrawn();
				int pom = (*it)->DrawFlamingo();
				if (pom == -1)
				{
					InLift.erase(it);
					break;
				}
			}
		}
}


void createFlamingo(int fromFloor, int toFloor)
{
	int _fromFloor = newLift.GetFromFloor();
	int _toFloor = newLift.GetToFloor();
	if (fromFloor == 0 || fromFloor == 2 || fromFloor == 4)
	{
		Flamingo *newFlamingo = new Flamingo(50, 556 - (120 * fromFloor), &value, fromFloor, toFloor);
		tab[fromFloor].push_back(newFlamingo);
		nextFloors.push_back(toFloor);
		SetTimer(hWnd, ID_TIMER_500, 100, NULL);
		
	}
	else if (fromFloor == 1 || fromFloor == 3)
	{
		Flamingo *newFlamingo = new Flamingo(960, 556 - (120 * fromFloor), &value, fromFloor, toFloor);
		tab[fromFloor].push_back(newFlamingo);
		nextFloors.push_back(toFloor);
		SetTimer(hWnd, ID_TIMER_500, 100, NULL);
	}
	howMany++;
}
#pragma endregion

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR			gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Zainicjuj ci¹gi globalne
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WIN32PROJECT2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Wykonaj inicjacje aplikacji:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT2));

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

	GdiplusShutdown(gdiplusToken);

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT2));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WIN32PROJECT2);
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

	hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	hwndButton = CreateWindow(TEXT("button"), TEXT("1"),
		WS_CHILD | WS_VISIBLE,
		30, 523, 30, 30, hWnd, (HMENU)ID_RBUTTON0_1, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("2"),
		WS_CHILD | WS_VISIBLE,
		60, 523, 30, 30, hWnd, (HMENU)ID_RBUTTON0_2, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("3"),
		WS_CHILD | WS_VISIBLE,
		90, 523, 30, 30, hWnd, (HMENU)ID_RBUTTON0_3, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("4"),
		WS_CHILD | WS_VISIBLE,
		120, 523, 30, 30, hWnd, (HMENU)ID_RBUTTON0_4, GetModuleHandle(NULL), NULL);
	//--------------------------------------------------------------------------------
	hwndButton = CreateWindow(TEXT("button"), TEXT("0"),
		WS_CHILD | WS_VISIBLE,
		880, 403, 30, 30, hWnd, (HMENU)ID_RBUTTON1_0, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("2"),
		WS_CHILD | WS_VISIBLE,
		910, 403, 30, 30, hWnd, (HMENU)ID_RBUTTON1_2, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("3"),
		WS_CHILD | WS_VISIBLE,
		940, 403, 30, 30, hWnd, (HMENU)ID_RBUTTON1_3, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("4"),
		WS_CHILD | WS_VISIBLE,
		970, 403, 30, 30, hWnd, (HMENU)ID_RBUTTON1_4, GetModuleHandle(NULL), NULL);
	//--------------------------------------------------------------------------------
	hwndButton = CreateWindow(TEXT("button"), TEXT("0"),
		WS_CHILD | WS_VISIBLE,
		30, 283, 30, 30, hWnd, (HMENU)ID_RBUTTON2_0, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("1"),
		WS_CHILD | WS_VISIBLE,
		60, 283, 30, 30, hWnd, (HMENU)ID_RBUTTON2_1, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("3"),
		WS_CHILD | WS_VISIBLE,
		90, 283, 30, 30, hWnd, (HMENU)ID_RBUTTON2_3, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("4"),
		WS_CHILD | WS_VISIBLE,
		120, 283, 30, 30, hWnd, (HMENU)ID_RBUTTON2_4, GetModuleHandle(NULL), NULL);
	//--------------------------------------------------------------------------------
	hwndButton = CreateWindow(TEXT("button"), TEXT("0"),
		WS_CHILD | WS_VISIBLE,
		880, 163, 30, 30, hWnd, (HMENU)ID_RBUTTON3_0, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("1"),
		WS_CHILD | WS_VISIBLE,
		910, 163, 30, 30, hWnd, (HMENU)ID_RBUTTON3_1, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("2"),
		WS_CHILD | WS_VISIBLE,
		940, 163, 30, 30, hWnd, (HMENU)ID_RBUTTON3_2, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("4"),
		WS_CHILD | WS_VISIBLE,
		970, 163, 30, 30, hWnd, (HMENU)ID_RBUTTON3_4, GetModuleHandle(NULL), NULL);
	//--------------------------------------------------------------------------------
	hwndButton = CreateWindow(TEXT("button"), TEXT("0"),
		WS_CHILD | WS_VISIBLE,
		30, 43, 30, 30, hWnd, (HMENU)ID_RBUTTON4_0, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("1"),
		WS_CHILD | WS_VISIBLE,
		60, 43, 30, 30, hWnd, (HMENU)ID_RBUTTON4_1, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("2"),
		WS_CHILD | WS_VISIBLE,
		90, 43, 30, 30, hWnd, (HMENU)ID_RBUTTON4_2, GetModuleHandle(NULL), NULL);
	hwndButton = CreateWindow(TEXT("button"), TEXT("3"),
		WS_CHILD | WS_VISIBLE,
		120, 43, 30, 30, hWnd, (HMENU)ID_RBUTTON4_3, GetModuleHandle(NULL), NULL);
	//--------------------------------------------------------------------------------

	if (!hWnd)
	{
		return FALSE;
	}
	ShowWindow(hWnd, SW_MAXIMIZE);
	repaintWindow(&drawArea1, &drawArea2, &drawArea3);
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
	int wmId, wmEvent;
	switch (message)
	{
	case WM_COMMAND:
	{
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_RBUTTON0_1:
			createFlamingo(0, 1);
			break;
		case ID_RBUTTON0_2:
			createFlamingo(0, 2);
			break;
		case ID_RBUTTON0_3:
			createFlamingo(0, 3);
			break;
		case ID_RBUTTON0_4:
			createFlamingo(0, 4);
			break;
		case ID_RBUTTON1_0:
			createFlamingo(1, 0);
			break;
		case ID_RBUTTON1_2:
			createFlamingo(1, 2);
			break;
		case ID_RBUTTON1_3:
			createFlamingo(1, 3);
			break;
		case ID_RBUTTON1_4:
			createFlamingo(1, 4);
			break;
		case ID_RBUTTON2_0:
			createFlamingo(2, 0);
			break;
		case ID_RBUTTON2_1:
			createFlamingo(2, 1);
			break;
		case ID_RBUTTON2_3:
			createFlamingo(2, 3);
			break;
		case ID_RBUTTON2_4:
			createFlamingo(2, 4);
			break;
		case ID_RBUTTON3_0:
			createFlamingo(3, 0);
			break;
		case ID_RBUTTON3_1:
			createFlamingo(3, 1);
			break;
		case ID_RBUTTON3_2:
			createFlamingo(3, 2);
			break;
		case ID_RBUTTON3_4:
			createFlamingo(3, 4);
			break;
		case ID_RBUTTON4_0:
			createFlamingo(4, 0);
			break;
		case ID_RBUTTON4_1:
			createFlamingo(4, 1);
			break;
		case ID_RBUTTON4_2:
			createFlamingo(4, 2);
			break;
		case ID_RBUTTON4_3:
			createFlamingo(4, 3);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_TIMER:
	{
		switch (wParam)
		{
			case ID_TIMER_1:
			{
				newLift.MoveDoor();
			}
			case ID_TIMER_2:
			{
				newLift.MoveLift();
			}
			break;
			case ID_TIMER_3:
			{
				hdc = GetDC(hWnd);
				if (door)
				{
					int height = newLift.GetHeight();
					newLift.Door(hdc);
					if (height < 100)
						newLift.ChangeHeight();
					else if (height == 100)
					{
						moved = true;
						int actualFloor = newLift.GetToFloor();
						
						int fromFloor = (*(InLift.begin()))->GetFromFloor();
						int delta = 0;
						if (fromFloor > actualFloor) delta = fromFloor - actualFloor;
						else delta = actualFloor - fromFloor;
						SetTimer(hWnd, ID_TIMER_500, 100, NULL);
						std::vector<Flamingo*>::iterator it;
						for (it = InLift.begin(); it != InLift.end(); it++)
						{
							(*it)->ChangeIsDrawnToFalse();
							(*it)->ChangeY(120 * delta);
						}

						inLift();
						cleanFloors();
						nextFloors.erase(nextFloors.begin());

						newLift.ChangeIsMovingToFalse();
						newLift.ChangeLiftUpToFalse();
						newLift.ChangeLiftMovedToTrue();
						
						KillTimer(hWnd, ID_TIMER_3);
					}
				}

				ReleaseDC(hWnd, hdc);
			}
			break;
		
			case ID_TIMER_500:
				if(moved)
					theWalkingFlamingo(1);
				else theWalkingFlamingo(0);
				int floor = newLift.GetFromFloor();
				if (!tab[floor].empty()) inLift();
				canMove();
				break;
		}
	}
	break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
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
