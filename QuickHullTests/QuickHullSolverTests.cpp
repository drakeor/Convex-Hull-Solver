#include "gtest/gtest.h"

#include "pch.h"
#include "../QuickHullLib/QuickHullSolver.h"

/*
	These tests are more to check for edge cases rather than validate the output
*/
TEST(QuickHullSolverTest, EmptyPointsTest) {

	std::vector<HullPoint> points;

	QuickHullSolver solver(points);
	solver.Solve();

	EXPECT_EQ(solver.GetPointCount(), 0);
}

TEST(QuickHullSolverTest, OnePointTest) {

	std::vector<HullPoint> points;
	const int pointCount = 1;
	for (int i = 0; i < pointCount; i++)
	{
		HullPoint point;
		point.X(i);
		point.Y(i);
		points.push_back(point);
	}
	QuickHullSolver solver(points);
	solver.Solve();

	EXPECT_EQ(solver.GetPointCount(), pointCount);

}

TEST(QuickHullSolverTest, TwoPointsTest) {

	std::vector<HullPoint> points;
	const int pointCount = 2;
	for (int i = 0; i < pointCount; i++)
	{
		HullPoint point;
		point.X(i);
		point.Y(i);
		points.push_back(point);
	}
	QuickHullSolver solver(points);
	solver.Solve();

	EXPECT_EQ(solver.GetPointCount(), pointCount);

}

TEST(QuickHullSolverTest, ThreePointsTest) {

	std::vector<HullPoint> points;
	const int pointCount = 3;
	for (int i = 0; i < pointCount; i++)
	{
		HullPoint point;
		point.X(i);
		point.Y(i);
		points.push_back(point);
	}
	QuickHullSolver solver(points);
	solver.Solve();

	EXPECT_EQ(solver.GetPointCount(), pointCount);

}

TEST(QuickHullSolverTest, TwentyPointsTest) {

	std::vector<HullPoint> points;
	const int pointCount = 20;
	for (int i = 0; i < pointCount; i++)
	{
		HullPoint point;
		point.X(i);
		point.Y(i);
		points.push_back(point);
	}
	QuickHullSolver solver(points);
	solver.Solve();

	EXPECT_EQ(solver.GetPointCount(), pointCount);

}