#pragma once

#include <vector>

#include "HullPoint.h"
#include "HullLine.h"

class ConvexHullSolver
{
protected:
	long totalNumberOfSteps;
	std::vector<HullPoint> Points;

public:
	ConvexHullSolver(std::vector<HullPoint> Points);
	~ConvexHullSolver();

	long GetTotalNumberOfSteps();

	virtual std::vector<HullLine> Solve() = 0;
};

