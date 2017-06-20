#pragma once
class Flamingo
{
public:
	Flamingo(int _x, int _y, int *_value, int _fromFloor, int _toFloor);
	~Flamingo();
	int GetX();
	int GetY();
	int GetID();
	void ChangeID(); // do zmniejszenia id, gdy poprzedni z kolejki zostanie usuniêty
	bool GetIsDrawn();
	void ChangeIsDrawnToTrue();
	void ChangeIsDrawnToFalse();
	void IncreaseX();
	void DecreaseX();
	void IncreaseY();
	void DecreaseY();
	void ChangeInLiftToTrue();
	void ChangeInLiftToFalse();
	void ChangeCanEnterToFalse();
	void ChangeCanEnterToTrue();
	bool GetInLift();
	bool GetCanEnter();
	int GetFromFloor();
	int GetToFloor();
	int DrawFlamingo();
	void ChangeY(int _y);
	void SetMovedToTrue();
	void SetMovedToFalse();

private:
	int x; //polozenie x,y
	int y;

	int fromFloor;
	int toFloor;

	int id; //do identyfikacji flaminga
	bool isDrawn = false;
	bool inLift = false;
	bool canEnter = true;
	bool isWaiting = false;
	bool moved;
};

