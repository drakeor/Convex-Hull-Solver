#include "gtest/gtest.h"
#include "pch.h"
#include "../QuickHullLib/PointGenerator.h"

TEST(PointGeneratorTests, GeneratePointsCorrectCount) {

	std::vector<HullPoint> hullPoints = PointGenerator::Generate(3, 1, 10);

	ASSERT_EQ(hullPoints.size(), 3);

}

TEST(PointGeneratorTests, GeneratePointsCorrectRange) {

	std::vector<HullPoint> hullPoints = PointGenerator::Generate(20, 30, 100);

	for (int i = 0; i < hullPoints.size(); i++) {
		ASSERT_TRUE(hullPoints[i].X() >= 0);
		ASSERT_TRUE(hullPoints[i].X() <= 30);

		ASSERT_TRUE(hullPoints[i].Y() >= 0);
		ASSERT_TRUE(hullPoints[i].Y() <= 100);
	}
	
}

TEST(PointGeneratorTests, GeneratePointsNoDuplicates) {

	std::vector<HullPoint> hullPoints = PointGenerator::Generate(90, 10, 10);
	bool pointExists[100];
	for (int i = 0; i < 100; i++)
		pointExists[i] = false;

	ASSERT_TRUE(hullPoints.size() != 0);

	for (int i = 0; i < hullPoints.size(); i++) {
		int pIndex = hullPoints[i].X() * 10 + hullPoints[i].Y();
		ASSERT_TRUE(!pointExists[pIndex]);
		pointExists[pIndex] = true;
	}

}

TEST(PointGeneratorTests, GeneratePointsOverflowTest) {

	std::vector<HullPoint> hullPoints = PointGenerator::Generate(200, 2, 2);

	ASSERT_EQ(hullPoints.size(), 4);

}

TEST(PointGeneratorTests, GeneratePointsTestMultiple) {

	auto hullPoints = PointGenerator::GenerateMultiple(10, 5, 6, 9);

	ASSERT_EQ(hullPoints.size(), 10);

}