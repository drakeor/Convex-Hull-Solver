#pragma once
class HullLine
{
public:
	HullLine(long x1, long y1, long x2, long y2);
	~HullLine();

	long X1();
	long Y1();
	long X2();
	long Y2();

private:
	long x1;
	long y1;
	long x2;
	long y2;
};

