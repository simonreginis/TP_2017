#pragma once
using namespace System;
using namespace System::Collections;

ref class FloorEventArgs : public EventArgs
{
public: int FloorTag;
public: ArrayList^ DroppedPassengers;

public:
	FloorEventArgs();

public:
	FloorEventArgs(int floorTag, ArrayList^ droppedPassengers) {
		this->FloorTag = floorTag;
		this->DroppedPassengers = droppedPassengers;
	}
};

