#pragma once
#include "Cargo.h"
class Crane
{
private:
	int x;
	int y;
	int speed_x;
	int speed_y;
	Cargo *cargo;
public:
	Crane();
	int get_x();
	int get_y();
	int getSpeed_x();
	int getSpeed_y();
	Cargo *getCargo();
	void set_x(int x);
	void set_y(int y);
	void setSpeed_x(int speed_x);
	void setSpeed_y(int speed_y);
	void stopMoving();
	void move();
	void attach(Cargo *c);
	void detach();
};

