#include "stdafx.h"
#include "Cargo.h"
#include "Resource.h"

Cargo::Cargo()
{
	length = (AREA_X2 - AREA_X1) / (BLOCKS + 5);
	speed_x = 0;
	speed_y = 0;
}

Cargo::~Cargo()
{
}

void Cargo::initialize(int x, int y, int type)
{
	switch (type)
	{
		case 0:							//rectagle
			this->type = type; break;
		case 1:
			this->type = type; break;		//triangle
		case 2:
			this->type = type; break;	//circle
		default: break;
	}
	this->x = x;
	this->y = y;
	this->falling = false;
}

void Cargo::move(Cargo *c)
{		if(x + speed_x >= AREA_X1 && x + speed_x + length <= AREA_X2)
			x += speed_x;
		if (y + speed_y + length <= AREA_Y2 && y +  speed_y >= AREA_Y1 && isFalling(c))
			y += speed_y;
		else
		{
			speed_x = 0;
			speed_y = 0;
		}
}

int Cargo::get_x()
{
	return x;
}

int Cargo::get_y()
{
	return y;
}

int Cargo::getSpeed_x()
{
	return speed_x;
}

int Cargo::getSpeed_y()
{
	return speed_y;
}

int Cargo::get_length()
{
	return length;
}

int Cargo::getType()
{
	return type;
}

void Cargo::set_x(int x)
{
	this->x = x;
}

void Cargo::set_y(int y)
{
	this->y = y;
}

void Cargo::setSpeed_x(int speed_x)
{
	this->speed_x = speed_x;
}

void Cargo::setSpeed_y(int speed_y)
{
	this->speed_y = speed_y;
}

void Cargo::set_length(int length)
{
	this->length = length;
}

void Cargo::setFalling(bool f)
{
	this->falling = f;
}

bool Cargo::isFalling(Cargo *c)
{
	if (this->falling)
	{
		bool is = true;
		for (int i = 0; i < BLOCKS && is; i++)
		{
			int x2 = c[i].get_x();
			int y2 = c[i].get_y();
			int l = c[i].get_length();
			if (((x >= x2 && x <= x2 + l) || (x + length >= x2 && x + length <= x2 + l)) && (y + speed_y + length > y2) && (y + speed_y + length < y2 + l))
			{
				y = y2 - length;
				setFalling(false);
				is = false;
			}
		}
		return is;
	}
	else
		return true;
}
