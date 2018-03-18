#pragma once
#include "ConvexHullSolver.h"
class BruteForceSolver :
	public ConvexHullSolver
{
public:
	BruteForceSolver(std::vector<HullPoint> Points);
	~BruteForceSolver();

	std::vector<HullLine> Solve();

	std::vector<HullPoint> GetCurrentPoints();
	std::vector<HullLine> GetCurrentLines();

	bool Step();

	long GetPoint1();
	long GetPoint2();
	long GetPointCount();
	bool GetCConvex();
	long GetA();
	long GetB();
	long GetC();

	HullPoint* GetPoint(long id);

private:
	long cPoint1;
	long cPoint2;
	long cConvex;

	long a;
	long b;
	long c;
	bool isConvex;

	long pointCount;
	std::vector<HullLine> lines;
};

