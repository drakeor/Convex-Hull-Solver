#pragma once
#include "ConvexHullSolver.h"
class BruteForceSolver :
	public ConvexHullSolver
{
public:
	BruteForceSolver(std::vector<HullPoint> Points);
	~BruteForceSolver();

	bool Step();
	
	long GetA();
	long GetB();
	long GetC();

private:

	long a;
	long b;
	long c;
};

