#include "stdafx.h"
#include "Lift1.h"
#include "Resource.h"
#include "Flamingo.h"
#include <string>
#include <vector>

extern bool door;
extern RECT drawArea4;
extern PAINTSTRUCT ps;
extern HWND hWnd;
extern HDC hdc;
extern std::vector<Flamingo*>InLift;


Lift1::Lift1(int _fromFloor, int _height, int _toFloor)
{
	fromFloor = _fromFloor;
	height = _height;
	toFloor = _toFloor;
}


Lift1::~Lift1()
{
}

int Lift1::GetFromFloor()
{
	return(fromFloor);
}
int Lift1::GetHeight()
{
	return(height);
}
int Lift1::GetToFloor()
{
	return(toFloor);
}
void Lift1::ChangeHeight()
{
	height++;
}
void Lift1::SetHeightToZero()
{
	height = 0;
}
void Lift1::SetFromFloor(int _fromFloor)
{
	fromFloor = _fromFloor;
}
void Lift1::SetToFloor(int _toFloor)
{
	toFloor = _toFloor;
}
void Lift1::DrawLift(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen1(Color(255, 156, 34, 93), 3.0f);
	graphics.DrawLine(&pen1, 310, 523, 690, 523);//gorna
	graphics.DrawLine(&pen1, 310, 623, 690, 623);///dolna
	graphics.DrawLine(&pen1, 690, 523, 690, 623);//prawa
}
void Lift1::OnLeft(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 156, 34, 93));
	graphics.DrawLine(&pen, 0, 143, 300, 143);
	graphics.DrawLine(&pen, 0, 383, 300, 383);
	graphics.DrawLine(&pen, 0, 623, 300, 623);
}
void Lift1::OnRight(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 156, 34, 93));
	graphics.DrawLine(&pen, 701, 263, 1000, 263);
	graphics.DrawLine(&pen, 701, 503, 1000, 503);
}
void Lift1::Door(HDC hdc)
{
	int y = 623 - (fromFloor * 120);
	int temp = height;
	int x1, x2;
	if (fromFloor % 2 == 0)
	{
		x1 = 310;
		x2 = 690;
	}
	else
	{
		x1 = 690;
		x2 = 310;
	}
	if (!door)
		temp = height - 100;
	else temp *= -1;

	Graphics graphics(hdc);
	Pen pen(Color(255, 156, 34, 93), 3.0f);
	InvalidateRect(hWnd, &drawArea4, TRUE);
	hdc = BeginPaint(hWnd, &ps);
	graphics.DrawLine(&pen, x1, y - 100, x1, y + temp);
	graphics.DrawLine(&pen, x1, y - 100, x2, y - 100);
	graphics.DrawLine(&pen, x1, y, x2, y);
	graphics.DrawLine(&pen, x2, y - 100, x2, y);
	EndPaint(hWnd, &ps);
	DrawFlamingoInLift(y);
}
void Lift1::RunLift(HDC hdc, int y)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 156, 34, 93), 3.0f);
	InvalidateRect(hWnd, &drawArea4, TRUE);
	hdc = BeginPaint(hWnd, &ps);
	graphics.DrawLine(&pen, 310, y - 100, 310, y); //lewo
	graphics.DrawLine(&pen, 310, y - 100, 690, y - 100);//gorna
	graphics.DrawLine(&pen, 310, y, 690, y);///dolna
	graphics.DrawLine(&pen, 690, y - 100, 690, y);//prawa
	DrawFlamingoInLift(y);
	EndPaint(hWnd, &ps);
}
void Lift1::MoveLift()
{
	hdc = GetDC(hWnd);
	if (door)
	{
		int from_Y = 623 - (fromFloor * 120);
		int to_Y = 623 - (toFloor * 120);

		if (fromFloor < toFloor)//jedziemy w górê
		{
			RunLift(hdc, from_Y - height);
			if (from_Y > to_Y + height)
			{
				height++;
				ChangeIsMovingToTrue();
			}
			else
			{
				ChangeIsMovingToFalse();
				fromFloor = toFloor;
				KillTimer(hWnd, ID_TIMER_2);
				height = 0;
				SetTimer(hWnd, ID_TIMER_3, 25, NULL);
			}
		}
		else if (fromFloor > toFloor)//jedziemy w dol
		{
			RunLift(hdc, from_Y + height);
			if (from_Y < to_Y)
			{
				height--;
				ChangeIsMovingToTrue();
			}
			else
			{
				fromFloor = toFloor;
				KillTimer(hWnd, ID_TIMER_2);
				height = 0;
				SetTimer(hWnd, ID_TIMER_3, 25, NULL);
			}
		}
	}
	ReleaseDC(hWnd, hdc);
}

void Lift1::MoveDoor()
{
	hdc = GetDC(hWnd);
	if (!door)
	{
		Door(hdc);
		if (height < 100)
			height++;
		else if (height == 100)
		{
			KillTimer(hWnd, ID_TIMER_1);
			height = 0;
			door = true;
			SetTimer(hWnd, ID_TIMER_2, 25, NULL);
		}
	}
	ReleaseDC(hWnd, hdc);
}

void Lift1::StopLift()
{
	KillTimer(hWnd, ID_TIMER_2);
	door = true;
}

void Lift1::ChangeIsFullToTrue()
{
	isFull = true;
}
void Lift1::ChangeIsFullToFalse()
{
	isFull = false;
}
void Lift1::ChangeIsMovingToTrue()
{
	isMoving = true;
}
void Lift1::ChangeIsMovingToFalse()
{
	isMoving = false;
}
bool Lift1::GetIsFull()
{
	return(isFull);
}
bool Lift1::GetIsMoving()
{
	return(isMoving);
}
bool Lift1::GetLiftUp()
{
	return(liftUp);
}
bool Lift1::GetLiftDown()
{
	return(liftDown);
}
void Lift1::ChangeLiftUpToTrue()
{
	liftUp = true;
}
void Lift1::ChangeLiftUpToFalse()
{
	liftUp = false;
}
void Lift1::ChangeLiftDownToTrue()
{
	liftDown = true;
}
void Lift1::ChangeLiftDownToFalse()
{
	liftDown = false;
}
void Lift1::DrawFlamingoInLift(int y)
{
	HDC hdcNowy = CreateCompatibleDC(hdc);
	std::vector<Flamingo*>::iterator it;
	for (it = InLift.begin(); it != InLift.end(); it++)
	{
		(*it)->SetMovedToTrue();
		HBITMAP hbmObraz;
		std::string link = "flamingo2.bmp";
		std::wstring stemp = std::wstring(link.begin(), link.end());
		LPCWSTR sw = stemp.c_str();

		hbmObraz = (HBITMAP)LoadImage(NULL, sw, IMAGE_BITMAP, 37, 65, LR_LOADFROMFILE);

		RECT drawArea5 = { 310, 556 - (120 * fromFloor) , 68, 600 - (120 * fromFloor) };
		FillRect(hdc, &drawArea5, (HBRUSH)GetStockObject(WHITE_BRUSH));

		SelectObject(hdcNowy, hbmObraz);
		int id = (*it)->GetID();
		int x = 35 * id;
		BitBlt(hdc, 650 - x, y - 67, 37, 65, hdcNowy, 0, 0, SRCCOPY);

	}
	DeleteDC(hdcNowy);
	ReleaseDC(hWnd, hdc);
}
void Lift1::FlamingosPlus()
{
	flamingos++;
}
void Lift1::FlamingosMinus()
{
	flamingos--;
}
bool Lift1::GetLiftMoved()
{
	return(liftMoved);
}
void Lift1::ChangeLiftMovedToFalse()
{
	liftMoved = false;
}
void Lift1::ChangeLiftMovedToTrue()
{
	liftMoved = true;
}