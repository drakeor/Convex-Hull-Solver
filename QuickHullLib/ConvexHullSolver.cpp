#include "stdafx.h"
#include "ConvexHullSolver.h"


ConvexHullSolver::ConvexHullSolver(std::vector<HullPoint> Points)
{
	this->Points = Points;
	this->totalNumberOfSteps = 0;
}

ConvexHullSolver::~ConvexHullSolver()
{
}

long ConvexHullSolver::GetTotalNumberOfSteps()
{
	return totalNumberOfSteps;
}
