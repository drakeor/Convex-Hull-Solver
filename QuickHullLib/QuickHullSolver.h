#pragma once
#include <stack>
#include "ConvexHullSolver.h"

// Holds information for the next iteration of QuickHull
struct FrameStack
{
	int PointA;
	int PointB;
	int Side;
};

// QuickHull implementation to find the convex hull given a set of vertices
class QuickHullSolver :
	public ConvexHullSolver
{
public:
	QuickHullSolver(std::vector<HullPoint> Points);
	~QuickHullSolver();

	bool Step();
	std::string GetName();

private:
	std::stack<FrameStack> frameStack;
};

