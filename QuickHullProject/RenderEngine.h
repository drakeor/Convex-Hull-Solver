#pragma once

#include <SFML\Graphics.hpp>

#include "../QuickHullLib/HullPoint.h"
#include "../QuickHullLib/HullLine.h"
#include "../QuickHullLib/ConvexHullSolver.h"

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

	~RenderEngine();
};

