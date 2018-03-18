#pragma once
#include "ConvexHullSolver.h"
class QuickHullSolver :
	public ConvexHullSolver
{
public:
	QuickHullSolver(std::vector<HullPoint> Points);
	~QuickHullSolver();

	bool Step();

private:
	bool DoQuickHull(HullPoint pointA, HullPoint pointB, int side);
};

