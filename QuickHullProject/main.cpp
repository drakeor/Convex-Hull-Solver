#include <iostream>
#include "../QuickHullLib/PointGenerator.h"
#include "../QuickHullLib/BruteForceSolver.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	const int windowSizeX = 1280;
	const int windowSizeY = 800;

	auto points = PointGenerator::Generate(4, windowSizeX, windowSizeY);
	auto solver = BruteForceSolver(points);
	auto lines = solver.Solve();

	// Add points to drawing
	std::vector<sf::CircleShape> renderPoints;
	for (auto i : points) {
		sf::CircleShape shape(2.f);
		shape.setFillColor(sf::Color::Red);
		shape.setPosition(i.X(), i.Y());
		renderPoints.push_back(shape);
	}


	// SFML code
	sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "Solver visualizer");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		// Render lines
		for (auto i : lines) {
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(i.X1(), i.Y1())),
				sf::Vertex(sf::Vector2f(i.X2(), i.Y2()))
			};
			window.draw(line, 2, sf::Lines);
		}

		// Render circles
		for (auto i : renderPoints) {
			window.draw(i);
		}

		window.display();
	}

	return 0;
}