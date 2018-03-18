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