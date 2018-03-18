#pragma once

#include <vector>
#include "HullPoint.h"

class PointGenerator
{
public:
	static std::vector<HullPoint> Generate(long n, long canvasX, long canvasY);
	static std::vector<std::vector<HullPoint>> GenerateMultiple(long count, long n, long canvasX, long canvasY);
private:
	PointGenerator();
	~PointGenerator();
};

