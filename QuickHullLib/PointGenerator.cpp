#include "stdafx.h"
#include <memory>
#include "PointGenerator.h"


/*
 * Generates a random list of hull Points across a canvas
 * For best results, set a decently high number for canvasX and canvasY with a lower n
 */
std::vector<HullPoint> PointGenerator::Generate(long n, long canvasX, long canvasY)
{
	srand(GetTickCount());
	std::vector<HullPoint> Points;

	const long canvasSize = canvasX * canvasY;
	std::unique_ptr<bool> duplicates(new bool[canvasSize]);
	for (long i = 0; i < canvasSize; i++)
		duplicates.get()[i] = false;

	long duplicatesLeft = canvasSize * 10;

	for (long i = 0; i < n; i++) {
		long randX = rand() % canvasX;
		long randY = rand() % canvasY; 
		long arrayPos = randX * canvasY + randY;

		if (duplicates.get()[arrayPos]) {
			if (duplicatesLeft <= 0)
				break;

			--duplicatesLeft;
			--i;
			continue;
		}

		duplicates.get()[arrayPos] = true;
		HullPoint HullPoint;
		HullPoint.X(randX);
		HullPoint.Y(randY);
		Points.push_back(HullPoint);
	}

	return Points;
}

std::vector<std::vector<HullPoint>> PointGenerator::GenerateMultiple(long count, long n, long canvasX, long canvasY)
{
	std::vector<std::vector<HullPoint>> toReturn;
	for (long i = 0; i < count; i++) {
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
