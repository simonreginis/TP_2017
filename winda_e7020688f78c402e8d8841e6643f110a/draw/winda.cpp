// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "winda.h"
#include <vector>

#define MAX_LOADSTRING 100
#define TMR_winda 1024

using namespace std;

struct czlowiek {
	int pietro_pocz;
	int pietro_kon;
	int x;     // lewy róg prostokąta
	int y;
};

vector<czlowiek> kolejka;
vector<czlowiek> czlowiek_winda;
vector<czlowiek> oczekiwanie_winda;

struct winda {
	int pietro;
	int kierunek;
	bool zatrzymanie;
};

winda win = {0,0,1};

vector<winda> ruchwindy;

int stan_windy = 0;   /*	0 -- stoi na jakimś poziomie, bez ruchu i ludzi
					  1 -- jest w ruchu,
					  2 -- otwieranie drzwi,
					  3 -- otwarte drzwi,
					  4 -- zamykanie drzwi,
					  */

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

HWND hwndButton;

int value = 0;
int value0 = 0;
int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;
bool koniec;
int zmienna = 0;
int ilosc = 0;

int miejsce[10] = {610, 630, 650, 670, 690, 710, 730, 750, 770, 790};
bool zajete[100] = { 0,0,0,0,0,0,0,0,0,0 };
bool wolne = false;

RECT winda_pro = { 603, 13, 847, 759 };
RECT stan = { 900, 10, 950, 40 };
RECT pietro0 = { 100, 680, 840, 750 };
RECT pietro1 = { 100, 530, 840, 600 };
RECT pietro2 = { 100, 380, 840, 450 };
RECT pietro3 = { 100, 230, 840, 300 };
RECT pietro4 = { 100,  80, 840, 150 };

RECT p0 = { 100, 680, 599, 750 };
RECT p1 = { 100, 530, 599, 600 };
RECT p2 = { 100, 380, 599, 450 };
RECT p3 = { 100, 230, 599, 300 };
RECT p4 = { 100,  80, 599, 150 };

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
void ustaw_winde();
void rysowanie_czlowieka(HDC hdc);
void przesuwanie();


void zarys_windy(HDC hdc , RECT *rect) {
	Graphics graphics(hdc);
	Pen penblue(Color(255, 0, 0, 255), 3);        // zarys windy
	GraphicsPath path;
	path.AddLine(603, 645 - value, 844, 645 - value);
	path.AddLine(844, 645 - value, 844, 755 - value);
	path.AddLine(844, 755 - value, 603, 755 - value);
	graphics.DrawPath(&penblue, &path);
}

void ruch_ludzi(HDC hdc) {
	int l=0;
	if (!wolne) {
		for (int i = 0; i < czlowiek_winda.size(); i++) {
			if (czlowiek_winda[i].pietro_kon == win.pietro) {
				for (int j = 0; j < 10; j++) {
					if (czlowiek_winda[i].x == miejsce[j])
						zajete[j] = 0;
				}
			}
		}
		wolne = true;
	}
	if(!czlowiek_winda.empty()){
		l = 0;
		for (int i = 0; i < czlowiek_winda.size(); i++) {
			if (czlowiek_winda[i].pietro_kon == win.pietro && czlowiek_winda[i].x > 50) {
				czlowiek_winda[i].x -= 5;
				l++;
			}
		}
	}
	int i = 0;
	if (l == 0) {
		koniec = true;
		while (!czlowiek_winda.empty() && i < czlowiek_winda.size())
			if (czlowiek_winda[i].pietro_kon == win.pietro)
				czlowiek_winda.erase(czlowiek_winda.begin() + i);
			else
				i++;
		wolne = false;
	}
}

void ruch_ludzi2(HDC hdc) {
	int l = 0;
	bool jest;
	if (!oczekiwanie_winda.empty()) {
		int i = 0;
		while (!oczekiwanie_winda.empty() && i < oczekiwanie_winda.size()) {
			jest = false;
			if (oczekiwanie_winda[i].pietro_pocz == win.pietro) {
				for (int j = 0; j < 10; j++) {
					if (!zajete[j]) {
						if (oczekiwanie_winda[i].x == miejsce[j]) {
							zajete[j] = 1;
							czlowiek_winda.push_back(oczekiwanie_winda[i]);
							oczekiwanie_winda.erase(oczekiwanie_winda.begin() + i);
							jest = true;
						}
						else {
							oczekiwanie_winda[i].x += 5;
							l++;
						}
						break;
					}
				}
			}
			if (!jest)
				i++;
		}	
	}
	if (l == 0 &&!ilosc){
		przesuwanie();
		if(ilosc == 0){
			stan_windy = 4;
			koniec = false;
		}
	}
}

void bez_ruchu() {
	koniec = false;
	if (win.pietro != 0) {
		if (kolejka.empty())
			zmienna++;
		else
			koniec = true;
	}
	if (zmienna == 300){
		for (int i = win.pietro; i >= 0; i--) {
			if (i != 0)
				ruchwindy.push_back({ i,-1,0 });
			else
				ruchwindy.push_back({ i,-1,1 });
		}
		koniec = true;
	}
	if (win.pietro == 0 && !kolejka.empty()){
		koniec = true;
		ustaw_winde();
	}
}

void przesuwanie() {
	ilosc = 0;
	for (int i = 0; i < czlowiek_winda.size(); i++) {
		if (czlowiek_winda[i].pietro_pocz == win.pietro)
			ilosc++;
	}
	switch (win.pietro) {
	case 0: value0 -= ilosc * 25; break;
	case 1: value1 -= ilosc * 25; break;
	case 2: value2 -= ilosc * 25; break;
	case 3: value3 -= ilosc * 25; break;
	case 4: value4 -= ilosc * 25; break;
	}
}

void przesuwanie2() {
	int l = 0;
	int ile = 0;
	if (!kolejka.empty()) {
		for(int i=0; i<kolejka.size();i++) {
			if (kolejka[i].pietro_pocz == win.pietro) {
				l = 0;
				for (int j = 0; j < i; j++)
					if (kolejka[j].pietro_pocz == kolejka[i].pietro_pocz) {
						l++;
					}
				if (kolejka[i].x != 575 - l * 25) {
					kolejka[i].x += 5;
					ile++;
				}
			}
		}
	}
	if(!ile){
		stan_windy = 4;
		koniec = false;
		ilosc = 0;
	}
}

void otwieranie_zamykanie(HDC hdc , RECT *rect , int a) {
	koniec = false;
	if (a == 1) {
			Graphics graphics(hdc);
			Pen pen(Color(255, 0, 0, 0), 2);
			int y = 640 - win.pietro * 150;
			graphics.DrawLine(&pen, 600, y, 600, y+(zmienna));
			rysowanie_czlowieka(hdc);
	}else {
			Graphics graphics(hdc);
			Pen pen(Color(255, 0, 0, 0), 2);
			int y = 640 - win.pietro * 150;
			graphics.DrawLine(&pen, 600, y, 600, y + 110 - (zmienna));
			rysowanie_czlowieka(hdc);
	}
	if (zmienna == 110)
		koniec = true;
}

void wsiadanie(HDC hdc) {
	switch (win.pietro) {
	case 0:
		otwieranie_zamykanie(hdc, &pietro0, -1);
		break;
	case 1: 
		otwieranie_zamykanie(hdc, &pietro1, -1);
		break;
	case 2: 
		otwieranie_zamykanie(hdc, &pietro2, -1);
		break;
	case 3: 
		otwieranie_zamykanie(hdc, &pietro3, -1);
		break;
	case 4: 
		otwieranie_zamykanie(hdc, &pietro4, -1);
		break;
	}
}

void zamykanie(HDC hdc) {
	switch (win.pietro) {
	case 0:
		otwieranie_zamykanie(hdc, &pietro0, 1);
		break;
	case 1:
		otwieranie_zamykanie(hdc, &pietro1, 1);
		break;
	case 2:
		otwieranie_zamykanie(hdc, &pietro2, 1);
		break;
	case 3:
		otwieranie_zamykanie(hdc, &pietro3, 1);
		break;
	case 4:
		otwieranie_zamykanie(hdc, &pietro4, 1);
		break;
	}
}

void tworz_czlowieka() {
	for (int i = 0; i < kolejka.size(); i++) {
		if (kolejka[i].x == 0) {
			int a;
			switch (kolejka[i].pietro_pocz) {
			case 0: a = value0; value0 += 25; break;
			case 1: a = value1; value1 += 25; break;
			case 2: a = value2; value2 += 25; break;
			case 3: a = value3; value3 += 25; break;
			case 4: a = value4; value4 += 25; break;
			}
			kolejka[i].x = 575 - a;
			kolejka[i].y = 680 - 150 * kolejka[i].pietro_pocz;
		}
	}
	for (int i = 0; i < oczekiwanie_winda.size(); i++) {
		if (oczekiwanie_winda[i].x == 0) {
			int a;
			switch (oczekiwanie_winda[i].pietro_pocz) {
			case 0: a = value0; value0 += 25; break;
			case 1: a = value1; value1 += 25; break;
			case 2: a = value2; value2 += 25; break;
			case 3: a = value3; value3 += 25; break;
			case 4: a = value4; value4 += 25; break;
			}
			oczekiwanie_winda[i].x = 600 - a;
			oczekiwanie_winda[i].y = 700 - 150 * oczekiwanie_winda[i].pietro_pocz;
		}
	}
}

void rysowanie_czlowieka(HDC hdc) {
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 0, 0), 2);
	
	
	FontFamily fontFamily(L"Arial");
	Font font1(&fontFamily, 20, FontStyleRegular, UnitPixel);
	PointF      pointF(0,0);
	SolidBrush  solidBrush(Color(255, 255, 255, 255));


	wchar_t pietro[2];
	pietro[1] = '\0';
	for (int i = 0; i < kolejka.size(); i++) {
		switch (kolejka[i].pietro_kon) {
		case 0:
			pietro[0] = '0';
			break;
		case 1:
			pietro[0] = '1';
			break;
		case 2:
			pietro[0] = '2';
			break;
		case 3:
			pietro[0] = '3';
			break;
		case 4:
			pietro[0] = '4';
			break;
		}

		SolidBrush solidBrush1(Color(255, 2, 0, 0));
		graphics.FillEllipse(&solidBrush1, kolejka[i].x , kolejka[i].y-1, 16, 16);
		graphics.FillRectangle(&solidBrush1, kolejka[i].x - 1, kolejka[i].y + 17, 18, 26);
		graphics.FillRectangle(&solidBrush1, kolejka[i].x - 1, kolejka[i].y + 43, 8, 18);
		graphics.FillRectangle(&solidBrush1, kolejka[i].x + 9, kolejka[i].y + 43, 8, 18);
		graphics.FillEllipse(&solidBrush1, kolejka[i].x - 1, kolejka[i].y + 57, 8, 8);
		graphics.FillEllipse(&solidBrush1, kolejka[i].x + 9, kolejka[i].y + 57, 8, 8);
		//graphics.FillRectangle(&solidBrush1, kolejka[i].x - 6, kolejka[i].y + 17, 28, 5);
		graphics.FillRectangle(&solidBrush1, kolejka[i].x - 6, kolejka[i].y + 17, 4, 23);
		graphics.FillRectangle(&solidBrush1, kolejka[i].x + 18, kolejka[i].y + 17, 4, 23);
		graphics.FillEllipse(&solidBrush1, kolejka[i].x - 6, kolejka[i].y + 38, 4, 4);
		graphics.FillEllipse(&solidBrush1, kolejka[i].x + 18, kolejka[i].y + 38, 4, 4);


		pointF.X = kolejka[i].x;
		pointF.Y = kolejka[i].y + 20;
		graphics.DrawString(pietro, -1, &font1, pointF, &solidBrush);
	}
	for (int i = 0; i < oczekiwanie_winda.size(); i++) {
		switch (oczekiwanie_winda[i].pietro_kon) {
		case 0:
			pietro[0] = '0';
			break;
		case 1:
			pietro[0] = '1';
			break;
		case 2:
			pietro[0] = '2';
			break;
		case 3:
			pietro[0] = '3';
			break;
		case 4:
			pietro[0] = '4';
			break;
		}

		SolidBrush solidBrush1(Color(255, 2, 0, 0));
		graphics.FillEllipse(&solidBrush1, oczekiwanie_winda[i].x, oczekiwanie_winda[i].y-1, 16, 16);
		graphics.FillRectangle(&solidBrush1, oczekiwanie_winda[i].x - 1, oczekiwanie_winda[i].y + 17, 18, 26);
		graphics.FillRectangle(&solidBrush1, oczekiwanie_winda[i].x - 1, oczekiwanie_winda[i].y + 43, 8, 18);
		graphics.FillRectangle(&solidBrush1, oczekiwanie_winda[i].x + 9, oczekiwanie_winda[i].y + 43, 8, 18);
		graphics.FillEllipse(&solidBrush1, oczekiwanie_winda[i].x -1, oczekiwanie_winda[i].y + 57, 8, 8);
		graphics.FillEllipse(&solidBrush1, oczekiwanie_winda[i].x + 9, oczekiwanie_winda[i].y + 57, 8, 8);
		//graphics.FillRectangle(&solidBrush1, oczekiwanie_winda[i].x -6 , oczekiwanie_winda[i].y + 17, 28, 5);
		graphics.FillRectangle(&solidBrush1, oczekiwanie_winda[i].x - 6, oczekiwanie_winda[i].y + 17, 4, 23);
		graphics.FillRectangle(&solidBrush1, oczekiwanie_winda[i].x + 18, oczekiwanie_winda[i].y + 17, 4, 23);
		graphics.FillEllipse(&solidBrush1, oczekiwanie_winda[i].x - 6, oczekiwanie_winda[i].y + 38, 4, 4);
		graphics.FillEllipse(&solidBrush1, oczekiwanie_winda[i].x + 18, oczekiwanie_winda[i].y + 38, 4, 4);

		pointF.X = oczekiwanie_winda[i].x;
		pointF.Y = oczekiwanie_winda[i].y + 20;
		graphics.DrawString(pietro, -1, &font1, pointF, &solidBrush);
	}
	for (int i = 0; i < czlowiek_winda.size(); i++) {
		switch (czlowiek_winda[i].pietro_kon) {
		case 0:
			pietro[0] = '0';
			break;
		case 1:
			pietro[0] = '1';
			break;
		case 2:
			pietro[0] = '2';
			break;
		case 3:
			pietro[0] = '3';
			break;
		case 4:
			pietro[0] = '4';
			break;
		}

		SolidBrush solidBrush1(Color(255, 2, 0, 0));
		graphics.FillEllipse(&solidBrush1, czlowiek_winda[i].x, czlowiek_winda[i].y-1, 16, 16);
		graphics.FillRectangle(&solidBrush1, czlowiek_winda[i].x - 1, czlowiek_winda[i].y + 17, 18, 26);
		graphics.FillRectangle(&solidBrush1, czlowiek_winda[i].x - 1, czlowiek_winda[i].y + 43, 8, 18);
		graphics.FillRectangle(&solidBrush1, czlowiek_winda[i].x + 9, czlowiek_winda[i].y + 43, 8, 18);
		graphics.FillEllipse(&solidBrush1, czlowiek_winda[i].x - 1, czlowiek_winda[i].y + 57, 8, 8);
		graphics.FillEllipse(&solidBrush1, czlowiek_winda[i].x + 9, czlowiek_winda[i].y + 57, 8, 8);
		//graphics.FillRectangle(&solidBrush1, czlowiek_winda[i].x - 6, czlowiek_winda[i].y + 17, 28, 5);
		graphics.FillRectangle(&solidBrush1, czlowiek_winda[i].x - 6, czlowiek_winda[i].y + 17, 4, 23);
		graphics.FillRectangle(&solidBrush1, czlowiek_winda[i].x + 18, czlowiek_winda[i].y + 17, 4, 23);
		graphics.FillEllipse(&solidBrush1, czlowiek_winda[i].x - 6, czlowiek_winda[i].y + 38, 4, 4);
		graphics.FillEllipse(&solidBrush1, czlowiek_winda[i].x + 18, czlowiek_winda[i].y + 38, 4, 4);
		
		pointF.X = czlowiek_winda[i].x ;
		pointF.Y = czlowiek_winda[i].y + 20;
		graphics.DrawString(pietro, -1, &font1, pointF, &solidBrush);
	}
}

int wyznacz_kierunek(int a, int b) {
	if (a > b)
		return -1;
	if (a < b)
		return 1;
	if (a == b)
		return 0;
}

void ruch_windy(HDC hdc, RECT *rect) {

	if(!(ruchwindy.empty())){
		if (win.pietro == ruchwindy[0].pietro) {
			if(ruchwindy[0].zatrzymanie == 1){
				win.kierunek = 0;
				if (!czlowiek_winda.empty() || !oczekiwanie_winda.empty())
					stan_windy = 2;
				else
					stan_windy = 0;
			}
			ruchwindy.erase(ruchwindy.begin());
		}else{
			if (win.pietro < ruchwindy[0].pietro){
				value++;
				for (int i = 0; i < czlowiek_winda.size(); i++) {
					czlowiek_winda[i].y--;
				}
				win.kierunek = 1;
			}
			if (win.pietro > ruchwindy[0].pietro) {
				value--;
				for (int i = 0; i < czlowiek_winda.size(); i++) {
					czlowiek_winda[i].y++;
				}
				win.kierunek = -1;
			}
			if (value % 150 == 0) {
				win.pietro += ruchwindy[0].kierunek;
			}
		}
	
	}
	zarys_windy(hdc, &winda_pro);
	rysowanie_czlowieka(hdc);
}

void ustaw_koniec(bool &ustawienie_konca, int i, int kieras, int &a) {
	for (int j = ruchwindy.size() - 1; j > 0; j--) {
		if(kieras == ruchwindy[j].kierunek == 1 && kolejka[i].pietro_kon <= ruchwindy[j].pietro)
			if (kolejka[i].pietro_kon == ruchwindy[j].pietro)
			{
				ustawienie_konca = true;
				a = j;
				break;
			}
		if (kieras == ruchwindy[j].kierunek == -1 && kolejka[i].pietro_kon >= ruchwindy[j].pietro)
			if (kolejka[i].pietro_kon == ruchwindy[j].pietro)
			{
				ustawienie_konca = true;
				a = j;
				break;
			}
	}
	int j = ruchwindy.size() - 1;
	if (!ustawienie_konca && i == 0 && kieras == ruchwindy[j].kierunek) {
		if (kieras == 1) {
			for (int k = ruchwindy[j].pietro + 1; k <= kolejka[0].pietro_kon; k++) {
				if (k != kolejka[0].pietro_kon)
					ruchwindy.push_back({ k,1,0 });
				else {
					ruchwindy.push_back({ k,1,1 });
				}
			}
			ustawienie_konca = true;
			a = j;
		}
		else {
			for (int k = ruchwindy[j].pietro - 1; k >= kolejka[0].pietro_kon; k--) {
				if (k != kolejka[0].pietro_kon)
					ruchwindy.push_back({ k,-1,0 });
				else {
					ruchwindy.push_back({ k,-1,1 });
				}
			}
			ustawienie_konca = true;
			a = j;
		}
	}
}

void ustaw_pocz(bool &ustawienie_pocz, int i, int kieras, int k) {
	for (int j = k - 1; j >= 0; j--) {
		if (kieras == ruchwindy[j].kierunek == 1 && kolejka[i].pietro_pocz <= ruchwindy[j].pietro)
			if (kolejka[i].pietro_pocz == ruchwindy[j].pietro)
			{
				if(j != 0 && ruchwindy[j-1].pietro != ruchwindy[j].pietro)
					ruchwindy[j].zatrzymanie = 1;
				ruchwindy[k].zatrzymanie = 1;
				oczekiwanie_winda.push_back(kolejka[i]);
				kolejka.erase(kolejka.begin() + i);
				ustawienie_pocz = true;
				break;
			}
		if (kieras == ruchwindy[j].kierunek == -1 && kolejka[i].pietro_pocz >= ruchwindy[j].pietro&& i != 0)
			if (kolejka[i].pietro_pocz == ruchwindy[j].pietro)
			{
				if (j != 0 && ruchwindy[j-1].pietro != ruchwindy[j].pietro)
					ruchwindy[j].zatrzymanie = 1;
				ruchwindy[k].zatrzymanie = 1;
				oczekiwanie_winda.push_back(kolejka[i]);
				kolejka.erase(kolejka.begin() + i);
				ustawienie_pocz = true;
				break;
			}
	}
}

void ustaw_winde() {
	if (ruchwindy.empty() && !kolejka.empty()) {
		if (kolejka[0].pietro_pocz != win.pietro) {
			// podjechanie na pietro klienta
			if (wyznacz_kierunek(win.pietro, kolejka[0].pietro_pocz) == 1)
				for (int i = win.pietro; i <= kolejka[0].pietro_pocz; i++) {
					if (i != kolejka[0].pietro_pocz)
						ruchwindy.push_back({ i,1,0 });
					else
						ruchwindy.push_back({ i,1,1 });
				}
			if (wyznacz_kierunek(win.pietro, kolejka[0].pietro_pocz) == -1)
				for (int i = win.pietro ; i >= kolejka[0].pietro_pocz; i--) {
					if (i != kolejka[0].pietro_pocz)
						ruchwindy.push_back({ i,-1,0 });
					else
						ruchwindy.push_back({ i,-1,1 });
				}
			if (stan_windy == 0) { stan_windy = 1; zmienna = 0; }
				
		}
		//ruch windy na odpowiednie pietro
		if (wyznacz_kierunek(kolejka[0].pietro_pocz, kolejka[0].pietro_kon) == 1)
			for (int i = kolejka[0].pietro_pocz; i <= kolejka[0].pietro_kon; i++) {
				if (i != kolejka[0].pietro_kon)
					ruchwindy.push_back({ i,1,0 });
				else{
					ruchwindy.push_back({ i,1,1 });
					oczekiwanie_winda.push_back(kolejka[0]);
				}
		}else
			for (int i = kolejka[0].pietro_pocz ; i >= kolejka[0].pietro_kon; i--) {
				if (i != kolejka[0].pietro_kon)
					ruchwindy.push_back({ i,-1,0 });
				else {
					ruchwindy.push_back({ i,-1,1 });
					oczekiwanie_winda.push_back(kolejka[0]);
				}
		}
		if (stan_windy == 0)
		{
			stan_windy = 2; zmienna = 0;
		}
		kolejka.erase(kolejka.begin());
	}else {
		if (!ruchwindy.empty() && !kolejka.empty()){
			int i = 0;
			while (!kolejka.empty() && kolejka.size() > i) {
				int kieras = wyznacz_kierunek(kolejka[i].pietro_pocz, kolejka[i].pietro_kon);
				bool ustawienie_konca = false, ustawienie_pocz = false;
				if (kieras == ruchwindy[0].kierunek && czlowiek_winda.size() + oczekiwanie_winda.size() < 10) {
					int k;
					ustaw_koniec(ustawienie_konca, i,kieras, k);
					if (ustawienie_konca)
						ustaw_pocz(ustawienie_pocz, i, kieras, k);
					if (!ustawienie_konca || !ustawienie_pocz)
						i++;
				}
				else
					i++;
			}
		}
	}
}


void tablica(HDC hdc , RECT *rect) {
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 0), 2);
	graphics.DrawRectangle(&pen, 900, 10, 50, 30);
	
	FontFamily fontFamily(L"Arial");
	Font font1(&fontFamily, 20, FontStyleRegular, UnitPixel);
	PointF      pointF5(930, 15);
	SolidBrush  solidBrush(Color(255, 0, 0, 0));

	wchar_t pietro[2];
	pietro[1] = '\0';
	switch (win.pietro) {
	case 0:
		pietro[0] = '0';
		break;
	case 1:
		pietro[0] = '1';
		break;
	case 2:
		pietro[0] = '2';
		break;
	case 3:
		pietro[0] = '3';
		break;
	case 4:
		pietro[0] = '4';
		break;
	}
	graphics.DrawString(pietro, -1, &font1, pointF5, &solidBrush);
	PointF      pointF6(910, 12);
	wchar_t kieras[2];
	kieras[1] = '\0';
	switch (win.kierunek) {
	case -1:
		kieras[0] = 'V';
		break;
	case 0:
		kieras[0] = '-';
		break;
	case 1:
		kieras[0] = '+';
		break;
	}
	graphics.DrawString(kieras, -1, &font1, pointF6, &solidBrush);
}

void sterowanie(HDC hdc) {
	switch (stan_windy) {
	case 0:
		bez_ruchu();
		break;
	case 1:
		ruch_windy(hdc, &winda_pro);
		break;
	case 2:
		wsiadanie(hdc);
		break;
	case 3:
		ruch_ludzi(hdc);
		break;
	case 4:
		zamykanie(hdc);
		break;
	}
}

void MyOnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255,0,0,0),2);
	graphics.DrawRectangle(&pen,600,10,250, 750);

	Pen penblue(Color(255, 0, 0, 255),3);        // zarys windy
	GraphicsPath path;
	path.AddLine(603,645,844,645);
	path.AddLine(844, 645, 844, 755);
	path.AddLine(844, 755, 603, 755);
	graphics.DrawPath(&penblue, &path);

	graphics.DrawLine(&pen, 100, 755, 600, 755);
	graphics.DrawLine(&pen, 100, 605, 600, 605);
	graphics.DrawLine(&pen, 100, 455, 600, 455);
	graphics.DrawLine(&pen, 100, 305, 600, 305);
	graphics.DrawLine(&pen, 100, 155, 600, 155);

	FontFamily fontFamily(L"Arial");
	Font font(&fontFamily, 50, FontStyleRegular, UnitPixel);
	PointF      pointF(50, 700);
	SolidBrush  solidBrush(Color(255, 0, 0, 0));

	graphics.DrawString(L"0", -1, &font, pointF, &solidBrush);
	PointF      pointF1(50, 550);
	graphics.DrawString(L"1", -1, &font, pointF1, &solidBrush);
	PointF      pointF2(50, 400);
	graphics.DrawString(L"2", -1, &font, pointF2, &solidBrush);
	PointF      pointF3(50, 250);
	graphics.DrawString(L"3", -1, &font, pointF3, &solidBrush);
	PointF      pointF4(50, 100);
	graphics.DrawString(L"4", -1, &font, pointF4, &solidBrush);

	//tablica(hdc, &stan);
}


int OnCreate(HWND window)
{
	SetTimer(window, TMR_winda, 10, NULL);
   //SetTimer(window, TMR_1, 25, 0);
   return 0;
}



int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;


	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
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

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
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
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("1"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 730,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON01,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("2"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 700,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON02,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("3"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 670,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON03,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("4"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 640,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON04,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need

   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("0"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 580,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON10,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("2"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 550,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON12,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("3"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 520,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON13,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("4"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 490,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON14,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need

   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("0"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 430,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON20,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("1"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 400,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON21,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("3"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 370,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON23,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("4"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 340,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON24,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need

   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("0"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 280,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON30,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("1"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 250,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON31,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("2"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 220,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON32,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("4"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 190,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON34,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need

   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("0"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 130,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON40,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("1"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 100,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON41,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("2"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 70,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON42,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
	   TEXT("3"),                  // the caption of the button
	   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
	   10, 40,                                  // the left and top co-ordinates
	   25, 25,                              // width and height
	   hWnd,                                 // parent window handle
	   (HMENU)ID_BUTTON43,                   // the ID of your button
	   hInstance,                            // the instance of your application
	   NULL);                               // extra bits you dont really need
   
   OnCreate(hWnd);

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
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	//OnCreate(hWnd,wParam,lParam);
	//OnTimer(hWnd,wParam,lParam);

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_BUTTON01:
			kolejka.push_back({ 0,1 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p0, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON02:
			kolejka.push_back({ 0,2 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p0, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON03:
			kolejka.push_back({ 0,3 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p0, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON04:
			kolejka.push_back({ 0,4 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p0, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde(); 
			break;
		case ID_BUTTON10:
			kolejka.push_back({ 1,0 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p1, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc); 
			ustaw_winde();
			break;
		case ID_BUTTON12:
			kolejka.push_back({ 1,2 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p1, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON13:
			kolejka.push_back({1,3 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p1, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON14:
			kolejka.push_back({ 1,4 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p1, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON20:
			kolejka.push_back({ 2,0 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p2, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON21:
			kolejka.push_back({ 2,1 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p2, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON23:
			kolejka.push_back({ 2,3 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p2, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde(); 
			break;
		case ID_BUTTON24:
			kolejka.push_back({ 2,4 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p2, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON30:
			kolejka.push_back({ 3,0 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p3, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON31:
			kolejka.push_back({ 3,1 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p3, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON32:
			kolejka.push_back({ 3,2 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p3, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON34:
			kolejka.push_back({ 3,4 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p3, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON40:
			kolejka.push_back({ 4,0 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p4, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON41:
			kolejka.push_back({ 4,1 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p4, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON42:
			kolejka.push_back({ 4,2 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p4, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		case ID_BUTTON43:
			kolejka.push_back({ 4,3 });
			tworz_czlowieka();
			InvalidateRect(hWnd, &p4, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			rysowanie_czlowieka(hdc);
			ustaw_winde();
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
			case TMR_winda:
			{
				switch (stan_windy) {
				case 0:
					hdc = BeginPaint(hWnd, &ps);
					bez_ruchu();
					if (koniec) {
						stan_windy = 1;
						zmienna = 0;
						koniec = false;
					}
					break;
				case 1:
					//ustaw_winde();
					if (ruchwindy.size() > 1) {
						if (ruchwindy[0].pietro == ruchwindy[1].pietro)
							ruchwindy.erase(ruchwindy.begin() + 1);
					}
					zmienna = 0;
					InvalidateRect(hWnd, &winda_pro, TRUE);
					hdc = BeginPaint(hWnd, &ps);
					ruch_windy(hdc, &winda_pro);
					break;
				case 2:
					if(zmienna % 9 == 0)
						ustaw_winde();
					switch (win.pietro) {
					case 0: InvalidateRect(hWnd, &pietro0, TRUE);  break;
					case 1: InvalidateRect(hWnd, &pietro1, TRUE); break;
					case 2: InvalidateRect(hWnd, &pietro2, TRUE); break;
					case 3: InvalidateRect(hWnd, &pietro3, TRUE); break;
					case 4: InvalidateRect(hWnd, &pietro4, TRUE); break;
					}
					hdc = BeginPaint(hWnd, &ps);
					rysowanie_czlowieka(hdc);
					wsiadanie(hdc);
					zmienna++;
					if (koniec) {
						zmienna = 0;
						koniec = false;
						stan_windy = 3;
					}
					break;
				case 3:
					switch (win.pietro) {
					case 0: InvalidateRect(hWnd, &pietro0, TRUE);  break;
					case 1: InvalidateRect(hWnd, &pietro1, TRUE); break;
					case 2: InvalidateRect(hWnd, &pietro2, TRUE); break;
					case 3: InvalidateRect(hWnd, &pietro3, TRUE); break;
					case 4: InvalidateRect(hWnd, &pietro4, TRUE); break;
					}
					hdc = BeginPaint(hWnd, &ps);
					ruch_ludzi(hdc);
					if(koniec)
						ruch_ludzi2(hdc);
					if (ilosc && koniec)
						przesuwanie2();
					rysowanie_czlowieka(hdc);
					break;
				case 4:
					switch (win.pietro) {
					case 0: InvalidateRect(hWnd, &pietro0, TRUE);  break;
					case 1: InvalidateRect(hWnd, &pietro1, TRUE); break;
					case 2: InvalidateRect(hWnd, &pietro2, TRUE); break;
					case 3: InvalidateRect(hWnd, &pietro3, TRUE); break;
					case 4: InvalidateRect(hWnd, &pietro4, TRUE); break;
					}
					hdc = BeginPaint(hWnd, &ps);
					zamykanie(hdc);
					zmienna++;
					if (koniec) {
						zmienna = 0;
						koniec = false;
						if (ruchwindy.empty())
							stan_windy = 0;
						else {
							bool jeszcze = false;
							for(int i=0; i<oczekiwanie_winda.size(); i++)
								if (win.pietro == oczekiwanie_winda[i].pietro_pocz) {
									jeszcze = true;
									break;
								}
							if (jeszcze)
								stan_windy = 2;
							else
								stan_windy = 1;
						}
					}
					break;
				}				

				InvalidateRect(hWnd, &stan, TRUE);
				hdc = BeginPaint(hWnd, &ps);
				tablica(hdc, &stan);
				
				ReleaseDC(hWnd, hdc);
				EndPaint(hWnd, &ps);
			}
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
