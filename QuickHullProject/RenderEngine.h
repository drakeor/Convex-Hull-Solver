#pragma once

#include <SFML\Graphics.hpp>

#include "../QuickHullLib/HullPoint.h"
#include "../QuickHullLib/HullLine.h"
#include "../QuickHullLib/ConvexHullSolver.h"

/*
	This is used to render the lines and points for the algorithms to visualize them
*/
class RenderEngine
{
private:
	sf::RenderWindow* window;
	sf::Font font;

public:
	RenderEngine(sf::RenderWindow* window);

	void RenderLines(std::vector<HullLine> lines);
	void RenderCurrentLine(ConvexHullSolver* solver);
	void RenderPoints(ConvexHullSolver * solver);
	void DrawInformation(ConvexHullSolver* solver);

	void DrawBenchmarkInfo(std::string info);

	~RenderEngine();
};

