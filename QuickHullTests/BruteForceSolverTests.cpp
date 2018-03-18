#include "gtest/gtest.h"

#include "pch.h"
#include "../QuickHullLib/BruteForceSolver.h"

TEST(BruteForceSolverTest, EmptyPointsTest) {

	std::vector<HullPoint> points;

	BruteForceSolver solver(points);
	solver.Solve();

	EXPECT_EQ(solver.GetPoint1(), 0);
}

TEST(HullPointTest, OnePointTest) {

	std::vector<HullPoint> points;
	const int pointCount = 1;
	for (int i = 0; i < pointCount; i++)
	{
		HullPoint point;
		point.X(i);
		point.Y(i);
		points.push_back(point);
	}
	BruteForceSolver solver(points);
	solver.Solve();

	EXPECT_EQ(solver.GetPoint1(), pointCount);

}

TEST(HullPointTest, TwoPointsTest) {

	std::vector<HullPoint> points;
	const int pointCount = 2;
	for (int i = 0; i < pointCount; i++)
	{
		HullPoint point;
		point.X(i);
		point.Y(i);
		points.push_back(point);
	}
	BruteForceSolver solver(points);
	solver.Solve();

	EXPECT_EQ(solver.GetPoint1(), pointCount);

}

TEST(HullPointTest, ThreePointsTest) {

	std::vector<HullPoint> points;
	const int pointCount = 3;
	for (int i = 0; i < pointCount; i++)
	{
		HullPoint point;
		point.X(i);
		point.Y(i);
		points.push_back(point);
	}
	BruteForceSolver solver(points);
	solver.Solve();

	EXPECT_EQ(solver.GetPoint1(), pointCount);

}

TEST(HullPointTest, TwentyPointsTest) {

	std::vector<HullPoint> points;
	const int pointCount = 20;
	for (int i = 0; i < pointCount; i++)
	{
		HullPoint point;
		point.X(i);
		point.Y(i);
		points.push_back(point);
	}
	BruteForceSolver solver(points);
	solver.Solve();

	EXPECT_EQ(solver.GetPoint1(), pointCount);

}