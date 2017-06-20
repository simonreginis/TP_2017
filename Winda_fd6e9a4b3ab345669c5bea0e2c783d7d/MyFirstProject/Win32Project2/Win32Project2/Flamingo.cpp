#include "stdafx.h"
#include "Resource.h"
#include "Flamingo.h"
#include "Lift1.h"
#include <string>
#include <vector>
extern Lift1 newLift;
extern HWND hWnd;
extern HDC hdc;


Flamingo::Flamingo(int _x, int _y, int *_value, int _fromFloor, int _toFloor)
{
	x = _x;
	y = _y;

	(*_value)++;
	id = (*_value);
	fromFloor = _fromFloor;
	toFloor = _toFloor;
}


Flamingo::~Flamingo()
{
}
int Flamingo::GetX()
{
	return(x);
}
int Flamingo::GetY()
{
	return(y);
}
int Flamingo::GetID()
{
	return(id);
}
void Flamingo::ChangeID()
{
	id--;
}
bool Flamingo::GetIsDrawn()
{
	return(isDrawn);
}
void Flamingo::ChangeIsDrawnToTrue()
{
	isDrawn = true;
}
void Flamingo::ChangeIsDrawnToFalse()
{
	isDrawn = false;
}
void Flamingo::IncreaseX()
{
	x += 5;
}
void Flamingo::DecreaseX()
{
	x -= 5;
}
void Flamingo::IncreaseY()
{
	y++;
}
void Flamingo::DecreaseY()
{
	y--;
}
void Flamingo::ChangeInLiftToTrue()
{
	inLift = true;
}
void Flamingo::ChangeCanEnterToTrue()
{
	canEnter = true;
}
void Flamingo::ChangeInLiftToFalse()
{
	inLift = false;
}
void Flamingo::ChangeCanEnterToFalse()
{
	canEnter = false;
}
bool Flamingo::GetCanEnter()
{
	return(canEnter);
}
bool Flamingo::GetInLift()
{
	return(inLift);
}
int Flamingo::GetFromFloor()
{
	return(fromFloor);
}
int Flamingo::GetToFloor()
{
	return(toFloor);
}

int Flamingo::DrawFlamingo()
{
	bool isMoving = newLift.GetIsMoving();
	int actualFloor = newLift.GetFromFloor();
	bool liftMoved = newLift.GetLiftMoved();
	if (!isDrawn)
	{
		if ((isMoving == true || fromFloor != actualFloor) && (fromFloor == 0 || fromFloor == 2 || fromFloor == 4) && x > 250 - 2 * id && !liftMoved)
		{
			ChangeIsDrawnToTrue();
		}
		else if ((isMoving == true || fromFloor != actualFloor) && (fromFloor == 1 || fromFloor == 3) && x < 720 + 2 * id && !liftMoved)
		{
			ChangeIsDrawnToTrue();
		}
		else if ((fromFloor == 0 || fromFloor == 2 || fromFloor == 4) && x > 600 - ((id - 1) * 35) && !liftMoved)
		{
			ChangeIsDrawnToTrue();
			ChangeInLiftToTrue();
			newLift.FlamingosPlus();
		}
		else if ((fromFloor == 1 || fromFloor == 3) && x < 350 && !liftMoved)
		{
			ChangeIsDrawnToTrue();
			ChangeInLiftToTrue();
			newLift.FlamingosPlus();
		}
		else if (liftMoved && (toFloor == 0 || toFloor == 2 || toFloor == 4) && x <80)
		{
			ChangeIsDrawnToTrue();
			ChangeInLiftToFalse();
			newLift.FlamingosMinus();
			RECT drawArea7 = { 0, 556 - (120 * toFloor), 130, 620 - (120 * toFloor) };
			InvalidateRect(hWnd, &drawArea7, TRUE);
			this->~Flamingo();
			newLift.ChangeLiftMovedToFalse();
			return -1;
		}
		else if (liftMoved && (toFloor == 1 || toFloor == 3) && x > 800)
		{
			ChangeIsDrawnToTrue();
			ChangeInLiftToFalse();
			newLift.FlamingosMinus();
			RECT drawArea7 = { x - 100, 556 - (120 * toFloor), x + 55, 620 - (120 * toFloor) };
			InvalidateRect(hWnd, &drawArea7, TRUE);
			this->~Flamingo();
			newLift.ChangeLiftMovedToFalse();
			return -1;
		}
		else
		{
			HBITMAP hbmObraz;
			std::string link = "flamingo2.bmp";
			std::wstring stemp = std::wstring(link.begin(), link.end());
			LPCWSTR sw = stemp.c_str();

			std::string link1 = "flamingo5.bmp";
			std::wstring stemp1 = std::wstring(link1.begin(), link1.end());
			LPCWSTR sw1 = stemp1.c_str();

			if ((fromFloor == 0 || fromFloor == 2 || fromFloor == 4) && !liftMoved)
				hbmObraz = (HBITMAP)LoadImage(NULL, sw, IMAGE_BITMAP, 37, 65, LR_LOADFROMFILE);
			else if((fromFloor == 1 || fromFloor == 3) && !liftMoved)
				hbmObraz = (HBITMAP)LoadImage(NULL, sw1, IMAGE_BITMAP, 37, 65, LR_LOADFROMFILE);
			else if(liftMoved && (toFloor == 0 || toFloor == 2 || toFloor ==4 ))
				hbmObraz = (HBITMAP)LoadImage(NULL, sw1, IMAGE_BITMAP, 37, 65, LR_LOADFROMFILE);
			else if(liftMoved && (toFloor == 1 || toFloor==3))
				hbmObraz = (HBITMAP)LoadImage(NULL, sw, IMAGE_BITMAP, 37, 65, LR_LOADFROMFILE);

			hdc = GetDC(hWnd);

			RECT drawArea5 = { x - 6, 558 - (120 * fromFloor) , x + 43, 600 - (120 * fromFloor) };
			RECT drawArea6 = { x - 6, 558 - (120 * toFloor), x + 55, 620 - (120 * toFloor) };
			if(!liftMoved)
				FillRect(hdc, &drawArea5, (HBRUSH)GetStockObject(WHITE_BRUSH));
			else if(liftMoved)
				FillRect(hdc, &drawArea6, (HBRUSH)GetStockObject(WHITE_BRUSH));

			HDC hdcNowy = CreateCompatibleDC(hdc);
			SelectObject(hdcNowy, hbmObraz);

			if ((fromFloor == 0 || fromFloor == 2 || fromFloor == 4) && !liftMoved)
			{
				BitBlt(hdc, x, y, 37, 65, hdcNowy, 0, 0, SRCCOPY);
				IncreaseX();
			}
			else if ((fromFloor == 1 || fromFloor == 3) && !liftMoved)
			{
				BitBlt(hdc, x, y, 37, 65, hdcNowy, 0, 0, SRCCOPY);
				DecreaseX();
			}
			else if ((toFloor == 0 || toFloor == 2 || toFloor == 4) && liftMoved)
			{
				BitBlt(hdc, x, y, 37, 65, hdcNowy, 0, 0, SRCCOPY);
				DecreaseX();
			}
			else if ((toFloor == 1 || toFloor == 3) && liftMoved)
			{
				BitBlt(hdc, x, y, 37, 65, hdcNowy, 0, 0, SRCCOPY);
				IncreaseX();
			}
			DeleteDC(hdcNowy);
			ReleaseDC(hWnd, hdc);
		}
	}
}
void Flamingo::ChangeY(int _y)
{
	y -= _y;
}
void Flamingo::SetMovedToFalse()
{
	moved = false;
}
void Flamingo::SetMovedToTrue()
{
	moved = true;
}