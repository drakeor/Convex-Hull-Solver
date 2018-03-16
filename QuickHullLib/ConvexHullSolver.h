#pragma once

#include <vector>

#include "HullPoint.h"
#include "HullLine.h"

class ConvexHullSolver
{
protected:
	int totalNumberOfSteps;
	std::vector<HullPoint> points;

public:
	ConvexHullSolver(std::vector<HullPoint> points);
	~ConvexHullSolver();

	int GetTotalNumberOfSteps();

	virtual std::vector<HullLine> Solve() = 0;
};

