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

	int operator!= (HullPoint other)
	{
		return (x != other.x) && (y != other.y);
	}

	int operator== (HullPoint other)
	{
		return (x == other.x) && (y == other.y);
	}
};

