#include "stdafx.h"
#include "HullPoint.h"

HullPoint::HullPoint()
{
	x = 0;
	y = 0;
}


HullPoint::~HullPoint()
{
}

int HullPoint::X()
{
	return x;
}

int HullPoint::Y()
{
	return y;
}

void HullPoint::X(int x)
{
	this->x = x;
}

void HullPoint::Y(int y)
{
	this->y = y;
}
