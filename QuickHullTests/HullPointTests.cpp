#include "pch.h"
#include "../QuickHullLib/HullPoint.h"

TEST(HullPointTest, ConstructorTest) {
	HullPoint hullPoint;

	EXPECT_EQ(hullPoint.X(), 0);
	EXPECT_EQ(hullPoint.Y(), 0);
}

TEST(HullPointTest, PropertiesTest) {
	HullPoint hullPoint;

	hullPoint.X(5);
	hullPoint.Y(8);

	EXPECT_EQ(hullPoint.X(), 5);
	EXPECT_EQ(hullPoint.Y(), 8);
}