#include <windows.h>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <conio.h>

using namespace std;

LPSTR NazwaKlasy = "Klasa Okienka";
MSG g_komunikat;

struct klocek{
	int szerokosc;
	int wysokosc;
	int polozenie_x;
	int polozenie_y;
	int roznica_x;
	int roznica_y;
	COLORREF kolor;
	bool uziemiony;
	
	klocek()
	{
		this->uziemiony=false;
	}
};

klocek Klocki[6];

const int ID_BUTTON1=1;
HWND g_przycisk_restart;
const int stala_g=10;
const int szerokosc=900;
const int wysokosc=700;
const int promien_s=6;
const int lenght_arm1=200;
const int lenght_arm2=350;
const int arm_s_x=szerokosc/2;
const int arm_s_y=50;
const int wysokosc_podloza=arm_s_y+lenght_arm1+lenght_arm2-100;

const int szerokosc_klocka=40;
const int wysokosc_klocka=60;
const int kolor1=0xff3366;
const int kolor2=0x6600ff;
const int kolor3=0x656565;
const int kolor4=0x0024ff;
const int kolor5=0xcc0033;
const int kolor6=0xffff33;
const int kolor7=0x336600;
const int kolor8=0x99ff66;
const int kolor9=0x33ccff;
const int kolor10=0x0099ff;

int fi1=0;
int fi2=0;
int arm1_x=arm_s_x;
int arm1_y=arm_s_y+lenght_arm1;
int arm2_x=arm1_x+lenght_arm2;
int arm2_y=arm1_y;

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

bool sprawdzenie_wspolrzednych_1(int alpha1, int alpha2);
bool sprawdzenie_wspolrzednych_2(int pol_x, int pol_y, int alpha2);
int wspolrzedne_arm_1();
int wspolrzedne_arm_2();
int rysowanie_arm_1(HDC hdcOkno, klocek Klocki[6]);
int rysowanie_arm_2(HDC hdcOkno);
int losowanie_koloru();
int rysowanie_klockow(HDC hdcOkno, klocek Klocki[6]);
bool sprawdzenie_klocka(klocek Klocki[6], int &numer);
int przyczepienie_klocka(klocek Klocki[6]);
int puszczenie_klocka(HDC hdcOkno, klocek Klocki[6]);
int opadajacy_klocek(HDC hdcOkno, klocek Klocki[6], int numer_klocka);
bool sprawdzenie_opadania(HDC hdcOkno, klocek Klocki[6], int &numer_klocka);
bool opadajacy(klocek Klocki[6], int numer_klocka);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

	WNDCLASSEX wc;

	wc.cbSize = sizeof( WNDCLASSEX );
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
	wc.hCursor = LoadCursor( NULL, IDC_ARROW );
	wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );
	wc.lpszMenuName = NULL;
	wc.lpszClassName = NazwaKlasy;
	wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );
	
	if( !RegisterClassEx( & wc ) )
	{
    	MessageBox( NULL, "Wysoka Komisja odmawia rejestracji tego okna!", "Niestety...",
    	MB_ICONEXCLAMATION | MB_OK );
    	return 1;
	}
	HWND hwnd;
    hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "Ramie robota", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, szerokosc, wysokosc, NULL, NULL, hInstance, NULL );
    if( hwnd == NULL )
    {
        MessageBox( NULL, "Nie utworzono okna", "Blad", MB_ICONEXCLAMATION | MB_OK );
        return 1;
    }	
	if( hwnd == NULL )
	{
    	MessageBox( NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION );
    	return 1;
	}
	
	ShowWindow( hwnd, nCmdShow );
    UpdateWindow( hwnd );
	
	HDC hdcOkno;
	hdcOkno = GetDC( hwnd );
	
	HPEN PioroCzarne, PioroBiale, PioroZielone, PioroBrazowe, Pudelko_pioro ;
	HBRUSH PedzelCzerwony, PedzelBrazowy, Pudelko_pedzel;
	POINT stary;
	PioroCzarne = CreatePen( PS_SOLID, 1, 0x000000 );
	PioroBiale = CreatePen( PS_SOLID, 1, 0xFFFFFF );
	PioroZielone = CreatePen( PS_SOLID, 1, 0x00FF00 );
	PioroBrazowe = CreatePen( PS_SOLID, 1, 0x964B00 );
	PedzelCzerwony = CreateSolidBrush(0x0000FF);
	PedzelBrazowy = CreateSolidBrush(0x004B96);
	Pudelko_pedzel =( HBRUSH ) SelectObject( hdcOkno, PedzelCzerwony );
	Ellipse( hdcOkno, arm_s_x-promien_s, arm_s_y-promien_s, arm_s_x+promien_s, arm_s_y+promien_s );
	MoveToEx( hdcOkno, arm_s_x, arm_s_y, & stary );
	LineTo( hdcOkno, arm1_x, arm1_y );
	LineTo( hdcOkno, arm2_x, arm2_y );
	
	SelectObject( hdcOkno, PedzelBrazowy );
	SelectObject( hdcOkno, PioroBrazowe );
	Rectangle( hdcOkno, 20, wysokosc_podloza, szerokosc-50, wysokosc-100 );
	
	int kolor_tym;
	for(int i=0;i<6;i++)
	{
		Klocki[i].szerokosc=szerokosc_klocka;
		Klocki[i].wysokosc=wysokosc_klocka;
		Klocki[i].polozenie_x=arm_s_x-(lenght_arm1+lenght_arm2)/1.4+i*szerokosc_klocka;
		Klocki[i].polozenie_y=wysokosc_podloza-wysokosc_klocka;
		kolor_tym=losowanie_koloru();
		Klocki[i].kolor=kolor_tym;
	}
	HBRUSH PedzelKlockow;
	HPEN PioroKlockow;
	for(int i=0;i<6;i++)
	{
		PedzelKlockow = CreateSolidBrush(Klocki[i].kolor);
		//PioroKlockow=CreatePen( PS_SOLID, 1, Klocki[i].kolor );
		//SelectObject( hdcOkno, PioroKlockow );
		SelectObject( hdcOkno, PedzelKlockow );
		Rectangle( hdcOkno, Klocki[i].polozenie_x, Klocki[i].polozenie_y, Klocki[i].polozenie_x+szerokosc_klocka, wysokosc_podloza );
	}
	DeleteObject( PedzelKlockow );
	DeleteObject( PioroKlockow );
	DeleteObject( PioroBiale );
	DeleteObject( PioroZielone );
	DeleteObject( PioroBrazowe );
	DeleteObject( Pudelko_pioro );
	DeleteObject( PedzelBrazowy );
	DeleteObject( PedzelCzerwony );
	DeleteObject( Pudelko_pedzel );
	//g_przycisk_restart=CreateWindowEx( 0, "BUTTON", "Restart", WS_CHILD | WS_VISIBLE, 50, 50, 150, 80, hwnd, ( HMENU ) ID_BUTTON1, hInstance, NULL );
	
	
	
	
	
	
	ReleaseDC( hwnd, hdcOkno );
	ShowWindow( hwnd, nCmdShow );
	UpdateWindow( hwnd );
	
	while( GetMessage( & g_komunikat, NULL, 0, 0 ) )
    {
        TranslateMessage( & g_komunikat );
        DispatchMessage( & g_komunikat );
    }
    return g_komunikat.wParam;
	
    return 0;
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	HDC hdcOkno = GetDC( hwnd );
    switch( msg )
    {
    case WM_CLOSE:
        DestroyWindow( hwnd );
        break;
       
    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;
       
        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    case WM_KEYDOWN:
    	{
    		switch(( int ) wParam )
    		 {
    		 	case VK_UP:
    		 		if(fi1<90&&sprawdzenie_wspolrzednych_1(fi1+1, fi2))
    		 			fi1++;
    		 		rysowanie_arm_1(hdcOkno, Klocki);
    		 		break;
    		 	case VK_DOWN:
    		 		if(fi1>-90&&sprawdzenie_wspolrzednych_1(fi1-1, fi2))
    		 			fi1--;
    		 		rysowanie_arm_1(hdcOkno, Klocki);
    		 		break;
    		 	case VK_LEFT:
    		 		if(sprawdzenie_wspolrzednych_1(fi1, fi2+1))
    		 			fi2++;
    		 		rysowanie_arm_1(hdcOkno, Klocki);
    		 		break;
    		 	case VK_RIGHT:
    		 		if(sprawdzenie_wspolrzednych_1(fi1, fi2-1))
    		 			fi2--;
    		 		rysowanie_arm_1(hdcOkno, Klocki);
    		 		break;
    		 	case VK_BACK:
    		 		//rysowanie_klockow(hdcOkno, Klocki);
    		 		break;
    		 	case VK_RETURN:
    		 		przyczepienie_klocka(Klocki);
					break;
				case VK_SPACE:
					for(int i=0;i<6;i++)
					{
						if(Klocki[i].uziemiony==true)
							puszczenie_klocka(hdcOkno, Klocki);
					}
					//puszczenie_klocka(hdcOkno, Klocki);
					break;
				/*case VK_DELETE:
					{
						HINSTANCE hInstance; HINSTANCE hPrevInstance; LPSTR lpCmdLine; int nCmdShow;
					
						WinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow );
						break;
					}*/
			 }
		}
	case WM_COMMAND:
		switch(wParam)
		{
			case ID_BUTTON1:
				{
					HINSTANCE hInstance; HINSTANCE hPrevInstance; LPSTR lpCmdLine; int nCmdShow;
					WinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow );
					break;
				}
		}
	} 
   
    return 0;
}

bool sprawdzenie_wspolrzednych_1(int alpha1, int alpha2)
{
	double radian_psi;
	radian_psi=(alpha1*M_PI)/180.0f;
	int prob_x,prob_y;
	prob_x=arm_s_x+lenght_arm1*sin(radian_psi);
	prob_y=arm_s_y+lenght_arm1*cos(radian_psi);
	return sprawdzenie_wspolrzednych_2(prob_x, prob_y, alpha2);
}

bool sprawdzenie_wspolrzednych_2(int pol_x, int pol_y, int alpha2)
{
	double radian_psi;
	radian_psi=(alpha2*M_PI)/180.0f;
	int prob_x,prob_y;
	prob_x=pol_x+lenght_arm2*cos(radian_psi);
	prob_y=pol_y+lenght_arm2*sin(radian_psi);	
	if(prob_x>szerokosc-20||prob_x<0||prob_y<0||prob_y>wysokosc_podloza)
		return false;
	else return true;
}

int wspolrzedne_arm_1()
{
	double radian_psi;
	radian_psi=(fi1*M_PI)/180.0f;
	arm1_x=arm_s_x+lenght_arm1*sin(radian_psi);
	arm1_y=arm_s_y+lenght_arm1*cos(radian_psi);
}

int rysowanie_arm_1(HDC hdcOkno, klocek Klocki[6])
{
	
	HPEN PioroCzarne, PioroBiale, Pudelko;
	HBRUSH PedzelCzerwony, PedzelBialy, Pudelko_kolo;
	POINT stary;
	PioroCzarne = CreatePen( PS_SOLID, 1, 0x000000 );
	PioroBiale = CreatePen( PS_SOLID, 1, 0xFFFFFF );
	PedzelCzerwony = CreateSolidBrush(0x0000FF);
	PedzelBialy = CreateSolidBrush(0xFFFFFF);
	Pudelko =( HPEN ) SelectObject( hdcOkno, PioroBiale );
	Pudelko_kolo =( HBRUSH ) SelectObject( hdcOkno, PedzelBialy );
	Ellipse( hdcOkno, arm_s_x-promien_s, arm_s_y-promien_s, arm_s_x+promien_s, arm_s_y+promien_s );
	Ellipse( hdcOkno, arm1_x-promien_s+2, arm1_y-promien_s+2, arm1_x+promien_s-2, arm1_y+promien_s-2 );
	MoveToEx( hdcOkno, arm2_x, arm2_y, & stary );
	LineTo( hdcOkno, arm1_x, arm1_y);
	LineTo( hdcOkno, arm_s_x, arm_s_y);
	SelectObject( hdcOkno, PioroCzarne );
	Pudelko_kolo =( HBRUSH ) SelectObject( hdcOkno, PedzelCzerwony );
	Ellipse( hdcOkno, arm_s_x-promien_s, arm_s_y-promien_s, arm_s_x+promien_s, arm_s_y+promien_s );
	wspolrzedne_arm_1();
	LineTo( hdcOkno, arm1_x, arm1_y);
	rysowanie_arm_2(hdcOkno);
	
	rysowanie_klockow(hdcOkno, Klocki);
	DeleteObject( PioroCzarne );
	DeleteObject( PioroBiale );
	DeleteObject( Pudelko );
	DeleteObject( PedzelCzerwony );
	DeleteObject( PedzelBialy );
	DeleteObject( Pudelko_kolo );
}

int wspolrzedne_arm_2()
{
	double radian_psi;
	radian_psi=(fi2*M_PI)/180.0f;
	int prob_x,prob_y;
	prob_x=arm1_x+lenght_arm2*cos(radian_psi);
	prob_y=arm1_y+lenght_arm2*sin(radian_psi);
	//if(prob_x>szerokosc||prob_x<0||prob_y<0||prob_y>wysokosc_podloza)
		
	arm2_x=arm1_x+lenght_arm2*cos(radian_psi);
	arm2_y=arm1_y+lenght_arm2*sin(radian_psi);
	//if(arm1_x+lenght_arm2*cos(radian_psi)||arm1_y+lenght_arm2*sin(radian_psi))
}

int rysowanie_arm_2(HDC hdcOkno)
{
	
	HPEN PioroCzarne, PioroBiale, Pudelko;
	HBRUSH PedzelCzerwony;
	POINT stary;
	PioroCzarne = CreatePen( PS_SOLID, 1, 0x000000 );
	PioroBiale = CreatePen( PS_SOLID, 1, 0xFFFFFF );
	PedzelCzerwony = CreateSolidBrush(0x0000FF);
	Pudelko =( HPEN ) SelectObject( hdcOkno, PioroBiale );
	SelectObject( hdcOkno, PioroCzarne );
	Ellipse( hdcOkno, arm1_x-promien_s+2, arm1_y-promien_s+2, arm1_x+promien_s-2, arm1_y+promien_s-2 );
	wspolrzedne_arm_2();
	LineTo( hdcOkno, arm2_x, arm2_y);
	DeleteObject( PioroCzarne );
	DeleteObject( PioroBiale );
	DeleteObject( Pudelko );
	DeleteObject( PedzelCzerwony );
}

int losowanie_koloru()
{
	srand(time(NULL));
	int numer=rand()%10+1;
	if(numer==1) return kolor10;
	else 
	if(numer==2) return kolor1;
	else 
	if(numer==3) return kolor2;
	else 
	if(numer==4) return kolor3;
	else 
	if(numer==5) return kolor4;
	else 
	if(numer==6) return kolor5;
	else 
	if(numer==7) return kolor6;
	else 
	if(numer==8) return kolor7;
	else 
	if(numer==9) return kolor8;
	else 
	if(numer==10) return kolor9;
	return kolor3;
}

int rysowanie_klockow(HDC hdcOkno, klocek Klocki[6])
{
	HBRUSH PedzelKlockow, PedzelBialy;
	HPEN PioroBiale;
	PedzelBialy = CreateSolidBrush(0xFFFFFF);
	POINT stary;
	PioroBiale = CreatePen( PS_SOLID, 1, 0xFFFFFF );
	
	for(int i=0;i<6;i++)
	{
		if(Klocki[i].uziemiony==true)
		{
			HBRUSH Pedzel_nowy;
			HPEN Pioro_nowe;
			Pioro_nowe=CreatePen( PS_SOLID, 1, Klocki[i].kolor);
			Pedzel_nowy=CreateSolidBrush(Klocki[i].kolor);
			SelectObject( hdcOkno, PioroBiale );
			SelectObject( hdcOkno, PedzelBialy );
			Rectangle( hdcOkno, Klocki[i].polozenie_x, Klocki[i].polozenie_y, Klocki[i].polozenie_x+szerokosc_klocka, Klocki[i].polozenie_y+wysokosc_klocka );
			
			HBRUSH PedzelBrazowy;
			PedzelBrazowy = CreateSolidBrush(0x004B96);
			SelectObject( hdcOkno, PedzelBrazowy );
			Rectangle( hdcOkno, 20, wysokosc_podloza, szerokosc-50, wysokosc-100 );
			
			Klocki[i].polozenie_x=arm2_x-Klocki[i].roznica_x;
			Klocki[i].polozenie_y=arm2_y-Klocki[i].roznica_y;
			SelectObject( hdcOkno, Pioro_nowe );
			SelectObject( hdcOkno, Pedzel_nowy );
			Rectangle( hdcOkno, Klocki[i].polozenie_x, Klocki[i].polozenie_y, Klocki[i].polozenie_x+szerokosc_klocka, Klocki[i].polozenie_y+wysokosc_klocka );
			DeleteObject( Pedzel_nowy );
			DeleteObject( Pioro_nowe );
			DeleteObject( PedzelBrazowy );
		} else
		{
			HBRUSH Pedzel_nowszy;
			HPEN Pioro_nowsze;
			//Pioro_nowsze=CreatePen( PS_SOLID, 1, Klocki[i].kolor);
			Pedzel_nowszy=CreateSolidBrush(Klocki[i].kolor);
			//SelectObject( hdcOkno, Pioro_nowsze );
			SelectObject( hdcOkno, Pedzel_nowszy );
			Rectangle( hdcOkno, Klocki[i].polozenie_x, Klocki[i].polozenie_y, Klocki[i].polozenie_x+szerokosc_klocka, Klocki[i].polozenie_y+wysokosc_klocka );
			DeleteObject( Pedzel_nowszy );
			DeleteObject( Pioro_nowsze );
		}
	}
	DeleteObject( PedzelKlockow );
	DeleteObject( PedzelBialy );
	DeleteObject( PioroBiale );
}

bool sprawdzenie_klocka(klocek Klocki[6], int &numer)
{
	for(int i=0;i<6;i++)
		if(arm2_x>=Klocki[i].polozenie_x&&arm2_x<=Klocki[i].polozenie_x+szerokosc_klocka&&arm2_y>=Klocki[i].polozenie_y&&arm2_y<=Klocki[i].polozenie_y+wysokosc_klocka)
			{
				Klocki[i].uziemiony=true;
				numer=i;
				return true;
			}
}
int przyczepienie_klocka(klocek Klocki[6])
{
	int numer;
	if(sprawdzenie_klocka(Klocki, numer)==true)
		{
			Klocki[numer].roznica_x=arm2_x-Klocki[numer].polozenie_x;
			Klocki[numer].roznica_y=arm2_y-Klocki[numer].polozenie_y;
		}
}

int puszczenie_klocka(HDC hdcOkno, klocek Klocki[6])
{
	int numer_klocka;
	int predkosc_opadania=10;
	if(sprawdzenie_opadania(hdcOkno, Klocki, numer_klocka)==true)
	{
		Klocki[numer_klocka].uziemiony=false;
		opadajacy_klocek(hdcOkno, Klocki, numer_klocka);
	}
	while(opadajacy(Klocki, numer_klocka)==true)
	{
		opadajacy_klocek(hdcOkno, Klocki, numer_klocka);
		predkosc_opadania+=stala_g;
		Sleep(2000/predkosc_opadania*0.4);
	}
}

int opadajacy_klocek(HDC hdcOkno, klocek Klocki[6], int numer_klocka)
{
	HBRUSH Pedzel_opadania,Pedzel_bialy;
	HPEN Pioro_opadana,Pioro_biale;
	Pioro_opadana=CreatePen( PS_SOLID, 1, Klocki[numer_klocka].kolor);
	Pedzel_opadania=CreateSolidBrush(Klocki[numer_klocka].kolor);
	Pioro_biale=CreatePen( PS_SOLID, 1, 0xFFFFFF);
	Pedzel_bialy=CreateSolidBrush(0xFFFFFF);
	SelectObject( hdcOkno, Pioro_biale );
	SelectObject( hdcOkno, Pedzel_bialy );
	Rectangle( hdcOkno, Klocki[numer_klocka].polozenie_x, Klocki[numer_klocka].polozenie_y, Klocki[numer_klocka].polozenie_x+szerokosc_klocka, Klocki[numer_klocka].polozenie_y+wysokosc_klocka);
	SelectObject( hdcOkno, Pioro_opadana );
	SelectObject( hdcOkno, Pedzel_opadania );
	Klocki[numer_klocka].polozenie_y+=1;
	Rectangle( hdcOkno, Klocki[numer_klocka].polozenie_x, Klocki[numer_klocka].polozenie_y, Klocki[numer_klocka].polozenie_x+szerokosc_klocka, Klocki[numer_klocka].polozenie_y+wysokosc_klocka);
	DeleteObject( Pedzel_opadania );
	DeleteObject( Pedzel_bialy );
	DeleteObject( Pioro_opadana );
	DeleteObject( Pioro_biale );
	
}

bool sprawdzenie_opadania(HDC hdcOkno, klocek Klocki[6], int &numer_klocka)
{
	for(int i=0;i<6;i++)
	{
		if(Klocki[i].uziemiony==true)
		{
			int czy_mozna=1;
			for(int j=0;j<6;j++)
			{
				if(Klocki[i].polozenie_x-szerokosc_klocka>=Klocki[j].polozenie_x&&Klocki[i].polozenie_x<=Klocki[j].polozenie_x+szerokosc_klocka&&i!=j&&Klocki[i].polozenie_y+wysokosc_klocka>=Klocki[j].polozenie_y)
					{
						MessageBox( NULL, "klocek ma cos po bokach ","Ale kicha...", MB_ICONEXCLAMATION );
						czy_mozna=0;
					}
			}
			if(Klocki[i].polozenie_y+wysokosc_klocka>wysokosc_podloza)
				czy_mozna=0;
			if(czy_mozna==1)
				{
					numer_klocka=i;
					return true;
				}
			else return false;
		}
	}	
}

bool opadajacy(klocek Klocki[6], int numer_klocka)
{
	int czy_mozna=1;
		for(int j=0;j<6;j++)
		{
			if(Klocki[numer_klocka].polozenie_x+szerokosc_klocka>=Klocki[j].polozenie_x && Klocki[numer_klocka].polozenie_x<=Klocki[j].polozenie_x+szerokosc_klocka && numer_klocka!=j && Klocki[numer_klocka].polozenie_y+wysokosc_klocka>=Klocki[j].polozenie_y)
				czy_mozna=0;
		}
		if(Klocki[numer_klocka].polozenie_y+wysokosc_klocka>wysokosc_podloza)
			czy_mozna=0;
		if(czy_mozna==1)
			return true;
		else return false;
}		








