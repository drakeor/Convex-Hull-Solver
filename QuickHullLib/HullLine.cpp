#include "stdafx.h"
#include "HullLine.h"


HullLine::HullLine(long x1, long y1, long x2, long y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

HullLine::~HullLine()
{
}

long HullLine::X1()
{
	return x1;
}

long HullLine::X2()
{
	return x2;
}

long HullLine::Y1()
{
	return y1;
}

long HullLine::Y2()
{
	return y2;
}
