#include "stdafx.h"
#include "Crane.h"
#include "Resource.h"

Crane::Crane()
{
	x = (AREA_X2 - AREA_X1) / 2;
	y = AREA_Y1 + 30;
	speed_x = 0;
	speed_y = 0;
	cargo = NULL;
}

void Crane::move()
{
	if (x + speed_x < AREA_X2 && x + speed_x > AREA_X1)
		x += speed_x;
	if (y + speed_y < AREA_Y2 && y + speed_y > AREA_Y1)
		y += speed_y;
}

int Crane::get_x()
{
	return x;
}

int Crane::get_y()
{
	return y;
}

int Crane::getSpeed_x()
{
	return speed_x;
}

int Crane::getSpeed_y()
{
	return speed_y;
}

void Crane::set_x(int x)
{
	this->x = x;
}

void Crane::set_y(int y)
{
	this->y = y;
}

void Crane::setSpeed_x(int speed_x)
{
	this->speed_x = speed_x;
}

void Crane::setSpeed_y(int speed_y)
{
	this->speed_y = speed_y;
}

void Crane::stopMoving()
{
	speed_x = 0;
	speed_y = 0;
}

void Crane::attach(Cargo *c)
{
	cargo = NULL;
	for (int i = 0; i < BLOCKS; i++)
	{
		int c_x = c[i].get_x();
		int c_y = c[i].get_y();
		int l = c[i].get_length();

		if (x >= c_x && x <= c_x + l && y >= c_y && y <= c_y + l)
			cargo = &c[i];
	}
}

Cargo *Crane::getCargo()
{
	return cargo;
}

void Crane::detach()
{
	if (cargo != NULL)
	{
		cargo->setSpeed_y(2);
		cargo->setFalling(true);
		cargo = NULL;
	}
	
}