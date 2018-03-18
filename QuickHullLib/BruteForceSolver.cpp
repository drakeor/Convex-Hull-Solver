#include "stdafx.h"
#include "BruteForceSolver.h"

#include <iostream>
using namespace std;

BruteForceSolver::BruteForceSolver(std::vector<HullPoint> Points)
	: ConvexHullSolver(Points)
{
	cPoint1 = 0;
	cPoint2 = 0;

	a = 0;
	b = 0;
	c = 0;
	isConvex = false;

	pointCount = Points.size();
}


BruteForceSolver::~BruteForceSolver()
{
}

std::vector<HullLine> BruteForceSolver::Solve()
{
	while (Step());
	return lines;
}

std::vector<HullPoint> BruteForceSolver::GetCurrentPoints()
{
	return Points;
}

std::vector<HullLine> BruteForceSolver::GetCurrentLines()
{
	return lines;
}

bool BruteForceSolver::Step()
{
	// Select new Points
	++cPoint2;
	if (cPoint1 == cPoint2) {
		++cPoint2;
	}
	if (cPoint2 >= pointCount) {
		++cPoint1;
		cPoint2 = 0;
	}
	if (cPoint1 >= pointCount) {
		cPoint1 = pointCount;
		return false;
	}
	

	HullPoint p1 = Points[cPoint1];
	HullPoint p2 = Points[cPoint2];

	// Calculate line segment between i and j
	a = p2.Y() - p1.Y();
	b = p1.X() - p2.X();
	c = p1.X() * p2.Y() - p1.Y() * p2.X();

	// Setting current result to 0
	long lastResult = 0;
	isConvex = true;

	// Iterate through the Points yet again
	for (long k = 0; k < pointCount; k++) {

		HullPoint p3 = Points[k];

		// Make sure we don't calculate i or j
		if (k != cPoint1 && k != cPoint2) {

			// Increment our step counter
			++totalNumberOfSteps;

			cout << c << endl;

			// Analyze the line
			long result = 0;
			long kLine = a * p3.X() + b * p3.Y() - c;

			if (kLine > 0) {
				result = 1;
			}
			else if (kLine  < 0) {
				result = -1;
			}

			Points[k].cResult = result;
			Points[k].cC = kLine;

			cout << lastResult << " :: " << result << std::endl;

			// Set last result only if lastResult != 0
			if (lastResult == 0) {
				lastResult = result;
			}

			// If there's a mismatch of results, this is not a convex hull
			if ((lastResult == -1 && result == 1) || (lastResult == 1 && result == -1)) {
				isConvex = false;
				cout << "No convex hull" << endl;
				//break;
			}
		}
	}

	// If isConvex is still true, then this is a convex line
	if (isConvex) {
		lines.push_back(HullLine(p1.X(), p1.Y(), p2.X(), p2.Y()));
	}
	return true;
}

long BruteForceSolver::GetPoint1()
{
	return cPoint1;
}

long BruteForceSolver::GetPoint2()
{
	return cPoint2;
}

long BruteForceSolver::GetPointCount()
{
	return pointCount;
}

bool BruteForceSolver::GetCConvex()
{
	return isConvex;
}

long BruteForceSolver::GetA()
{
	return a;
}

long BruteForceSolver::GetB()
{
	return b;
}

long BruteForceSolver::GetC()
{
	return c;
}

HullPoint * BruteForceSolver::GetPoint(long id)
{
	if (id >= 0 && id < pointCount)
		return &Points[id];
	return nullptr;
}
