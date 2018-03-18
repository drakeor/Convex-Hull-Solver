#pragma once
#include <stack>
#include "ConvexHullSolver.h"

struct FrameStack
{
	int PointA;
	int PointB;
	int Side;
};

class QuickHullSolver :
	public ConvexHullSolver
{
public:
	QuickHullSolver(std::vector<HullPoint> Points);
	~QuickHullSolver();

	bool Step();

private:
	bool DoQuickHull(HullPoint pointA, HullPoint pointB, int side);
	std::stack<FrameStack> frameStack;
};

