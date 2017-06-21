#pragma once
#pragma once
class Lift1
{
public:
	Lift1(int _fromFloor, int _height, int _toFloor);
	~Lift1();
	int GetFromFloor();
	int GetHeight();
	int GetToFloor();
	void ChangeHeight();
	void SetHeightToZero();
	void SetFromFloor(int _fromFloor);
	void SetToFloor(int _toFloor);
	void DrawLift(HDC hdc);
	void OnLeft(HDC hdc);
	void OnRight(HDC hdc);
	void Door(HDC hdc);
	void RunLift(HDC hdc, int y);
	void MoveLift();
	void MoveDoor();
	bool GetIsMoving();
	bool GetIsFull();
	void ChangeIsMovingToTrue();
	void ChangeIsMovingToFalse();
	void ChangeIsFullToTrue();
	void ChangeIsFullToFalse();
	bool GetLiftUp();
	bool GetLiftDown();
	void ChangeLiftUpToTrue();
	void ChangeLiftUpToFalse();
	void ChangeLiftDownToTrue();
	void ChangeLiftDownToFalse();
	void DrawFlamingoInLift(int y);
	void FlamingosPlus();
	void FlamingosMinus();
	void StopLift();
	bool GetLiftMoved();
	void ChangeLiftMovedToTrue();
	void ChangeLiftMovedToFalse();
private:
	int fromFloor;
	int height;
	int toFloor;
	int flamingos=0;
	int actualFloor=0;
	bool isMoving = false;
	bool isFull = false;
	bool liftUp = true;
	bool liftDown = false;
	bool liftMoved = false;
};
