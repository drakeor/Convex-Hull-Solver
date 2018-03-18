#include "pch.h"
#include "../QuickHullLib/HullPoint.h"

TEST(HullPointTest, ConstructorTest) {
	HullPoint HullPoint;

	EXPECT_EQ(HullPoint.X(), 0);
	EXPECT_EQ(HullPoint.Y(), 0);
}

TEST(HullPointTest, PropertiesTest) {
	HullPoint HullPoint;

	HullPoint.X(5);
	HullPoint.Y(8);

	EXPECT_EQ(HullPoint.X(), 5);
	EXPECT_EQ(HullPoint.Y(), 8);
}

TEST(HullPointTest, DistanceTest) {
	HullPoint hullPoint1;
	hullPoint1.X(0);
	hullPoint1.Y(0);

	HullPoint hullPoint2;
	hullPoint2.X(3);
	hullPoint2.Y(4);

	EXPECT_EQ(hullPoint1.Dist(hullPoint2), 5);
}

TEST(HullPointTest, DistanceAlongLineTest) {
	HullPoint hullPoint1;
	hullPoint1.X(1);
	hullPoint1.Y(1);

	HullPoint hullPoint2;
	hullPoint2.X(5);
	hullPoint2.Y(1);

	HullPoint hullPoint3;
	hullPoint3.X(4);
	hullPoint3.Y(4);

	EXPECT_EQ(hullPoint1.DistAlongLine(hullPoint2, hullPoint3), 3);
}

TEST(HullPointTest, DistanceAlongLineTestNormalize1) {
	HullPoint hullPoint1;
	hullPoint1.X(1);
	hullPoint1.Y(1);

	HullPoint hullPoint2;
	hullPoint2.X(5);
	hullPoint2.Y(1);

	HullPoint hullPoint3;
	hullPoint3.X(4);
	hullPoint3.Y(4);

	EXPECT_EQ(hullPoint1.DistAlongLine(hullPoint2, hullPoint3, true), 1);
}

TEST(HullPointTest, DistanceAlongLineTestNormalize2) {
	HullPoint hullPoint1;
	hullPoint1.X(1);
	hullPoint1.Y(1);

	HullPoint hullPoint2;
	hullPoint2.X(5);
	hullPoint2.Y(1);

	HullPoint hullPoint3;
	hullPoint3.X(-4);
	hullPoint3.Y(-4);

	EXPECT_EQ(hullPoint1.DistAlongLine(hullPoint2, hullPoint3, true), -1);
}