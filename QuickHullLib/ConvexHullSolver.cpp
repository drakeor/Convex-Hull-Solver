#include "stdafx.h"
#include "ConvexHullSolver.h"


ConvexHullSolver::ConvexHullSolver(std::vector<HullPoint> points)
{
	this->points = points;
	this->totalNumberOfSteps = 0;
}

ConvexHullSolver::~ConvexHullSolver()
{
}

int ConvexHullSolver::GetTotalNumberOfSteps()
{
	return totalNumberOfSteps;
}
