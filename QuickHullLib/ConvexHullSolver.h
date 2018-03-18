#pragma once

#include <vector>

#include "HullPoint.h"
#include "HullLine.h"

class ConvexHullSolver
{
protected:
	long totalNumberOfSteps;
	long pointCount;

	std::vector<HullPoint> points;
	std::vector<HullLine> lines;

	long cPoint1;
	long cPoint2;
	bool isConvex;

public:
	ConvexHullSolver(std::vector<HullPoint> Points);
	~ConvexHullSolver();

	long GetTotalNumberOfSteps();

	std::vector<HullPoint> GetCurrentPoints();
	std::vector<HullLine> GetCurrentLines();
	HullPoint* GetPoint(long id);

	long GetPoint1();
	long GetPoint2();
	long GetPointCount();
	bool IsConvex();

	virtual bool Step() = 0;
	std::vector<HullLine> Solve();
};

