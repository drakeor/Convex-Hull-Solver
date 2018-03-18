#include <iostream>
#include <sstream>
#include <memory>

#include "../QuickHullLib/PointGenerator.h"
#include "../QuickHullLib/BruteForceSolver.h"
#include "../QuickHullLib/QuickHullSolver.h"
#include "RenderEngine.h"
#include <SFML/Graphics.hpp>

using namespace std;

long main()
{
	// Variables
	const long windowSizeX = 1280;
	const long windowSizeY = 800;
	bool isAutoRunning = false;

	// SFML code
	sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "Solver visualizer");
	window.setFramerateLimit(60);

	// Initialize our classes
	auto Points = PointGenerator::Generate(25, windowSizeX, windowSizeY);
	std::shared_ptr<ConvexHullSolver> solver(new QuickHullSolver(Points));
	RenderEngine engine(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close the window on close event
			if (event.type == sf::Event::Closed)
				window.close();

			// If space is pressed, toggle auto running otherwise single step
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					isAutoRunning = !isAutoRunning;
				}

				if (event.key.code == sf::Keyboard::S) 
				{
					if (!isAutoRunning) 
					{
						solver->Step();
					}
				}
				
			}
		}

		// Run automatically
		if (isAutoRunning)
			if (!solver->Step())
				isAutoRunning = false;

		// Render all of our stuff
		window.clear();

		engine.RenderLines(solver->GetCurrentLines());
		engine.RenderCurrentLine(solver.get());
		engine.RenderPoints(solver.get());
		engine.DrawInformation(solver.get());

		window.display();
	}

	return 0;
}