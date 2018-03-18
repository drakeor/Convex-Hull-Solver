#include "gtest/gtest.h"
#include "pch.h"
#include "../QuickHullLib/PointGenerator.h"

TEST(PointGeneratorTests, GeneratePointsCorrectCount) {

	std::vector<HullPoint> HullPoints = PointGenerator::Generate(3, 1, 10);

	ASSERT_EQ(HullPoints.size(), 3);

}

TEST(PointGeneratorTests, GeneratePointsCorrectRange) {

	std::vector<HullPoint> HullPoints = PointGenerator::Generate(20, 30, 100);

	for (long i = 0; i < HullPoints.size(); i++) {
		ASSERT_TRUE(HullPoints[i].X() >= 0);
		ASSERT_TRUE(HullPoints[i].X() <= 30);

		ASSERT_TRUE(HullPoints[i].Y() >= 0);
		ASSERT_TRUE(HullPoints[i].Y() <= 100);
	}
	
}

TEST(PointGeneratorTests, GeneratePointsNoDuplicates) {

	std::vector<HullPoint> HullPoints = PointGenerator::Generate(90, 10, 10);
	bool PointExists[100];
	for (long i = 0; i < 100; i++)
		PointExists[i] = false;

	ASSERT_TRUE(HullPoints.size() != 0);

	for (long i = 0; i < HullPoints.size(); i++) {
		long pIndex = HullPoints[i].X() * 10 + HullPoints[i].Y();
		ASSERT_TRUE(!PointExists[pIndex]);
		PointExists[pIndex] = true;
	}

}

TEST(PointGeneratorTests, GeneratePointsOverflowTest) {

	std::vector<HullPoint> HullPoints = PointGenerator::Generate(200, 2, 2);

	ASSERT_EQ(HullPoints.size(), 4);

}

TEST(PointGeneratorTests, GeneratePointsTestMultiple) {

	auto HullPoints = PointGenerator::GenerateMultiple(10, 5, 6, 9);

	ASSERT_EQ(HullPoints.size(), 10);

}