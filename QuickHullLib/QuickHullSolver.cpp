#include "stdafx.h"
#include "QuickHullSolver.h"


QuickHullSolver::QuickHullSolver(std::vector<HullPoint> Points)
	: ConvexHullSolver(Points)
{

	// Calculate our first subdivision
	int leftMostPoint = 0;
	int rightMostPoint = 0;

	for (int i = 1; i < pointCount; i++) {
		if (points[i].X() < points[leftMostPoint].X()) {
			leftMostPoint = i;
		}
		if (points[i].X() > points[rightMostPoint].X()) {
			rightMostPoint = i;
		}
	}

	DoQuickHull(points[leftMostPoint], points[rightMostPoint], 1);
	DoQuickHull(points[leftMostPoint], points[rightMostPoint], -1);

}


QuickHullSolver::~QuickHullSolver()
{

}

bool QuickHullSolver::Step()
{
	return false;
}

bool QuickHullSolver::DoQuickHull(HullPoint pointA, HullPoint pointB, int side)
{
	// Find the point furthest away
	int currentMaxIndex = -1;
	int currentMaxDist = 0;

	for (int i = 0; i < pointCount; i++)
	{
		if (pointA.DistAlongLine(pointB, points[i], true) == side) {
			int dist = pointA.DistAlongLine(pointB, points[i]);
			if (dist > currentMaxDist) {
				currentMaxDist = dist;
				currentMaxIndex = i;
			}
		}
		++totalNumberOfSteps;
	}

	// No points along this side means it's a convex hull
	// This is also the base case
	if (currentMaxIndex == -1)
	{
		HullLine hullLine(pointA.X(), pointA.Y(), pointB.X(), pointB.Y());
		lines.push_back(hullLine);
		return false;
	}

	// Recurse for our new max
	DoQuickHull(points[currentMaxIndex], pointA, 
		pointA.DistAlongLine(points[currentMaxIndex], pointB, true));
	DoQuickHull(points[currentMaxIndex], pointB, 
		pointA.DistAlongLine(pointB, points[currentMaxIndex], true));
	return false;
}
