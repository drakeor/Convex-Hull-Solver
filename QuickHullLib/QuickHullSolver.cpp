#include "stdafx.h"
#include <iostream>
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

	// Push left and right onto the stack
	FrameStack newFrameA{ leftMostPoint, rightMostPoint, 1 };
	FrameStack newFrameB{ leftMostPoint, rightMostPoint, -1 };
	frameStack.push(newFrameA);
	frameStack.push(newFrameB);
}


QuickHullSolver::~QuickHullSolver()
{

}

bool QuickHullSolver::Step()
{
	// Return false if we have no points
	if (pointCount == 0) {
		return false;
	}

	// Return false if the stack is empty
	if (frameStack.size() <= 0) {
		return false;
	}

	// Stack overflow. haha. This should never happen but theoritically rounding errors could cause this.
	if (frameStack.size() > 10000) {
		return false;
	}

	// Otherwise, pop off the stack and set up our environment
	FrameStack frame = *(&frameStack.top());
	frameStack.pop();
	HullPoint pointA = points[frame.PointA];
	HullPoint pointB = points[frame.PointB];
	int side = frame.Side;

	// For the graphics visualization stuff
	isConvex = false;
	cPoint1 = frame.PointA;
	cPoint2 = frame.PointB;

	// Now do the calculations
	int currentMaxIndex = -1;
	int currentMaxDist = 0;

	// Loop through each point
	for (int i = 0; i < pointCount; i++)
	{
		points[i].cResult = 0;
		points[i].cValue = 0;

		// Checkif it's on the side of the line we are currently looking at
		if (pointA.DistAlongLine(pointB, points[i], true) == side) {

			// Check if this is our newest max distance line
			int dist = pointA.DistAlongLine(pointB, points[i]);
			points[i].cResult = 1;
			points[i].cValue = dist;

			// If it is, update accordingly
			if (dist > currentMaxDist) {
				currentMaxDist = dist;
				currentMaxIndex = i;
			}
		}
		else {
			points[i].cResult = -1;
		}

		// Increment number of steps
		++totalNumberOfSteps;
	}

	// No points along this side means it's a convex hull
	// This is also the base case
	if (currentMaxIndex == -1)
	{
		isConvex = true;
		HullLine hullLine(pointA.X(), pointA.Y(), pointB.X(), pointB.Y());
		lines.push_back(hullLine);
		return true;
	}

	// Add new left and right frames to our frame stack
	FrameStack newFrameA{ currentMaxIndex, frame.PointA, 
		pointA.DistAlongLine(points[currentMaxIndex], pointB, true) };
	FrameStack newFrameB{ currentMaxIndex, frame.PointB, 
		pointA.DistAlongLine(pointB, points[currentMaxIndex], true) };

	frameStack.push(newFrameA);
	frameStack.push(newFrameB);

	return true;
}

std::string QuickHullSolver::GetName()
{
	return "QuickHull";
}
