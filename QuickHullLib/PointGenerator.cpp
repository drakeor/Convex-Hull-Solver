#include "stdafx.h"
#include <memory>
#include "PointGenerator.h"


/*
 * Generates a random list of hull points across a canvas
 * For best results, set a decently high number for canvasX and canvasY with a lower n
 */
std::vector<HullPoint> PointGenerator::Generate(int n, int canvasX, int canvasY)
{
	std::vector<HullPoint> points;

	const int canvasSize = canvasX * canvasY;
	std::unique_ptr<bool> duplicates(new bool[canvasSize]);
	for (int i = 0; i < canvasSize; i++)
		duplicates.get()[i] = false;

	int duplicatesLeft = canvasSize * 10;

	for (int i = 0; i < n; i++) {
		int randX = rand() % canvasX;
		int randY = rand() % canvasY; 
		int arrayPos = randX * canvasY + randY;

		if (duplicates.get()[arrayPos]) {
			if (duplicatesLeft <= 0)
				break;

			--duplicatesLeft;
			--i;
			continue;
		}

		duplicates.get()[arrayPos] = true;
		HullPoint hullPoint;
		hullPoint.X(randX);
		hullPoint.Y(randY);
		points.push_back(hullPoint);
	}

	return points;
}

std::vector<std::vector<HullPoint>> PointGenerator::GenerateMultiple(int count, int n, int canvasX, int canvasY)
{
	std::vector<std::vector<HullPoint>> toReturn;
	for (int i = 0; i < count; i++) {
		toReturn.push_back(Generate(n, canvasX, canvasY));
	}
	return toReturn;
}

PointGenerator::PointGenerator()
{
}


PointGenerator::~PointGenerator()
{
}
