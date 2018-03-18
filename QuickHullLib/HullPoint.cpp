#include "stdafx.h"
#include "HullPoint.h"

HullPoint::HullPoint()
{
	x = 0;
	y = 0;
	cValue = 0;
	cResult = 0;
}


HullPoint::~HullPoint()
{
}

long HullPoint::X()
{
	return x;
}

long HullPoint::Y()
{
	return y;
}

void HullPoint::X(long x)
{
	this->x = x;
}

void HullPoint::Y(long y)
{
	this->y = y;
}
