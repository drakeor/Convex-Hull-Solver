#include "stdafx.h"
#include "ConvexHullSolver.h"


ConvexHullSolver::ConvexHullSolver(std::vector<HullPoint> Points)
{
	this->points = Points;
	this->totalNumberOfSteps = 0;

	cPoint1 = 0;
	cPoint2 = 0;
	isConvex = false;
	pointCount = Points.size();
}

ConvexHullSolver::~ConvexHullSolver()
{
}

long ConvexHullSolver::GetTotalNumberOfSteps()
{
	return totalNumberOfSteps;
}

std::vector<HullLine> ConvexHullSolver::Solve()
{
	while (Step());
	return lines;
}

std::vector<HullPoint> ConvexHullSolver::GetCurrentPoints()
{
	return points;
}

std::vector<HullLine> ConvexHullSolver::GetCurrentLines()
{
	return lines;
}


long ConvexHullSolver::GetPoint1()
{
	return cPoint1;
}

long ConvexHullSolver::GetPoint2()
{
	return cPoint2;
}

long ConvexHullSolver::GetPointCount()
{
	return pointCount;
}

bool ConvexHullSolver::IsConvex()
{
	return isConvex;
}

HullPoint * ConvexHullSolver::GetPoint(long id)
{
	if (id >= 0 && id < pointCount)
		return &points[id];
	return nullptr;
}