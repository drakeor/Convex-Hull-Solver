#include "stdafx.h"
#include "BruteForceSolver.h"

#include <iostream>
using namespace std;

BruteForceSolver::BruteForceSolver(std::vector<HullPoint> points)
	: ConvexHullSolver(points)
{
}


BruteForceSolver::~BruteForceSolver()
{
}

std::vector<HullLine> BruteForceSolver::Solve()
{
	std::vector<HullLine> cLines;
	this->totalNumberOfSteps = 0;

	for (auto i : points) {

		for (auto j : points) {

			// Make sure we don't calculate ourselves
			if (i != j) {

				// Calculate line segment between i and j
				int a = j.Y() - i.Y();
				int b = j.X() - i.X();
				int c = (i.X() * (j.Y() - i.Y()) - i.Y() * (i.Y() - j.X()));

				// Setting current result to 0
				int lastResult = 0;
				bool isConvex = true;

				// Iterate through the points yet again
				for (auto k : points) {

					// Make sure we don't calculate i or j
					if (k != i && k != j) {

						// Increment our step counter
						++totalNumberOfSteps;

						cout << c << endl;
						
						// Analyze the line
						int result = 0;
						if ((a * k.X() + b * k.Y()) > c) {
							result = 1;
						}
						else if ((a * k.X() + b * k.Y()) < c) {
							result = -1;
						}

						cout << lastResult << " :: " << result << std::endl;

						// Set last result only if lastResult != 0
						if (lastResult == 0) {
							lastResult = result;
						}

						// If there's a mismatch of results, this is not a convex hull
						if ((lastResult == -1 && result == 1) || (lastResult == 1 && result == -1)) {
							isConvex = false;
							cout << "No convex hull" << endl;
							break;
						}
					}
				}

				// If isConvex is still true, then this is a convex line
				if (isConvex) {
					cLines.push_back(HullLine(i.X(), i.Y(), j.X(), j.Y()));
				}
			}
		}
	}
	return cLines;
}
