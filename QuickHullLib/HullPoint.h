#pragma once
class HullPoint
{
private:
	int x;
	int y;

public:
	HullPoint();
	~HullPoint();

	int X();
	int Y();
	void X(int x);
	void Y(int y);
};

