#pragma once

#include <vector>
#include "HullPoint.h"

class PointGenerator
{
public:
	static std::vector<HullPoint> Generate(int n, int canvasX, int canvasY);
	static std::vector<std::vector<HullPoint>> GenerateMultiple(int count, int n, int canvasX, int canvasY);
private:
	PointGenerator();
	~PointGenerator();
};

