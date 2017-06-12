#pragma once
using namespace System;

ref class FloorEventArgs : public EventArgs
{
public: int FloorTag;

public:
	FloorEventArgs();

public:
	FloorEventArgs(int floorTag) {
		this->FloorTag = floorTag;
	}
};

