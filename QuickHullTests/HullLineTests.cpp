#include "gtest/gtest.h"
#include "pch.h"

#include "../QuickHullLib/HullLine.h"

/*
Just a simple constructor test for this class
*/
TEST(HullLineTests, Datalongegrity) {

	HullLine hullLine(1, 2, 3, 4);

	ASSERT_EQ(1, hullLine.X1());
	ASSERT_EQ(2, hullLine.Y1());
	ASSERT_EQ(3, hullLine.X2());
	ASSERT_EQ(4, hullLine.Y2());

}