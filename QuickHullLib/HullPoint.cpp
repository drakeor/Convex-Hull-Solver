#include "stdafx.h"
#include <cmath>
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

long HullPoint::Dist(HullPoint other)
{
	return (long)sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

long HullPoint::DistAlongLine(HullPoint point2, HullPoint other, bool normalizeResult)
{
	double normal = Dist(point2);
	double dist = ((other.y - y) * (point2.x - x)
		- (other.x - x) * (point2.y - y)) / normal;
	
	if (normalizeResult) {
		if (dist > 0) {
			return 1;
		}
		else if (dist < 0) {
			return -1;
		}
		else {
			return 0;
		}
	}
	else {
		return round(abs(dist));
	}
}
