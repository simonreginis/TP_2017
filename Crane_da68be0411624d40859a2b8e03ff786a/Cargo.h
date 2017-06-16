#pragma once
class Cargo
{
private:
	int x;
	int y;
	int speed_x;
	int speed_y;
	int length;					//dlugosc x i y, bo wszystkie obiekty beda kwadratami tylko z innymi wzorami
	int type;					//0 - rectangle, 1 - triangle, 3 - wheel
	bool falling;
public:
	Cargo();
	~Cargo();
	void initialize(int x, int y, int type);
	int get_x();
	int get_y();
	int get_length();
	int getSpeed_x();
	int getSpeed_y();
	int getType();
	void set_x(int x);
	void set_y(int y);
	void set_length(int length);
	void setSpeed_x(int speed_x);
	void setSpeed_y(int speed_y);
	void setFalling(bool f);
	void move(Cargo *c);
	bool isFalling(Cargo *c);
};

