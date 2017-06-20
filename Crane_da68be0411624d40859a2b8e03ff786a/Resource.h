//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by dzwig.rc
//

#define IDS_APP_TITLE			103

#define IDR_MAINFRAME			128
#define IDD_DZWIG_DIALOG	102
#define IDD_ABOUTBOX			103
#define IDM_ABOUT				104
#define IDM_EXIT				105
#define IDI_DZWIG			107
#define IDI_SMALL				108
#define IDC_DZWIG			109
#define IDC_MYICON				2
#ifndef IDC_STATIC
#define IDC_STATIC				-1

#define TMR_1					1		///TIMER
//			***** PRZYCISKI *****
#define ID_BUTTON_UP				200		//kontroluje ruch dzwigu w gore
#define ID_BUTTON_DOWN				201		//kontroluje ruch dzwigu w dol
#define ID_BUTTON_LEFT				202		//kontroluje ruch dzwigu w lewo
#define ID_BUTTON_RIGHT			203		//kontroluje ruch dzwigu w prawo
#define ID_BUTTON_ATTACH					204		//pozwala zaczepic klocek
#define ID_BUTTON_DETACH					205		//pozwala upuscic klocek
#define ID_BUTTON_STOP				206		//zatrzymuje ruch dzwigu
//			***** OBSZAR RYSOWANIA *****
int const AREA_X1 = 75;		//>=65				default 75
int const AREA_X2 = 915;	//>=AREA_X1			default 915
int const AREA_Y1 = 80;		//>=50				default 80
int const AREA_Y2 = 520;	//>=AREA_Y1			default 520
int const BLOCKS = 12;			//number blocks that will spawn
int const RESTRICTION = 0;		//type of block we can carry  // 0 -rect, 1 -triangle, 2 -circle
int const MAX_LVL = 3;			//max tower height
#endif
// Next default values for new objects
//
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#endif
#endif
