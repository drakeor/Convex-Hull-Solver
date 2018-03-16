#include "stdafx.h"
#include "HullLine.h"


HullLine::HullLine(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

HullLine::~HullLine()
{
}

int HullLine::X1()
{
	return x1;
}

int HullLine::X2()
{
	return x2;
}

int HullLine::Y1()
{
	return y1;
}

int HullLine::Y2()
{
	return y2;
}
