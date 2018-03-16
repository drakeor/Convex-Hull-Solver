#pragma once
class HullLine
{
public:
	HullLine(int x1, int y1, int x2, int y2);
	~HullLine();

	int X1();
	int Y1();
	int X2();
	int Y2();

private:
	int x1;
	int y1;
	int x2;
	int y2;
};

