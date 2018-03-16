#pragma once
#include "ConvexHullSolver.h"
class BruteForceSolver :
	public ConvexHullSolver
{
public:
	BruteForceSolver(std::vector<HullPoint> points);
	~BruteForceSolver();

	std::vector<HullLine> Solve();
};

