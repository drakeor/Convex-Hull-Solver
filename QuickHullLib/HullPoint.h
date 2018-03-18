#pragma once
class HullPoint
{
private:
	long x;
	long y;

public:
	HullPoint();
	~HullPoint();

	long X();
	long Y();
	void X(long x);
	void Y(long y);

	long operator!= (HullPoint other)
	{
		return (x != other.x) && (y != other.y);
	}

	long operator== (HullPoint other)
	{
		return (x == other.x) && (y == other.y);
	}

	long Dist(HullPoint other);
	long DistAlongLine(HullPoint point2, HullPoint other, bool normalizeResult = false);

	long cResult;
	long cValue;
};

