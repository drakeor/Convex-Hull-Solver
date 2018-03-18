#include "RenderEngine.h"
#include <sstream>
#include <iostream>

RenderEngine::RenderEngine(sf::RenderWindow* window)
{
	this->window = window;
	if (!font.loadFromFile("Mina-Bold.ttf"))
	{
		std::cerr << "Cannot load font file Mini-Bold.ttf!" << std::endl;
	}
}

void RenderEngine::RenderLines(std::vector<HullLine> lines)
{
	for (auto i : lines) {
		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(i.X1(), i.Y1())),
			sf::Vertex(sf::Vector2f(i.X2(), i.Y2()))
		};
		window->draw(line, 2, sf::Lines);
	}
}

void RenderEngine::RenderCurrentLine(ConvexHullSolver * solver)
{
	HullPoint* p1 = solver->GetPoint(solver->GetPoint1());
	HullPoint* p2 = solver->GetPoint(solver->GetPoint2());
	if (p1 != nullptr && p2 != nullptr) {
		sf::Color color = sf::Color::Yellow;
		if (solver->IsConvex()) {
			color = sf::Color::Green;
		}
		else {
			color = sf::Color::Red;
		}
		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(p1->X(), p1->Y()), color),
			sf::Vertex(sf::Vector2f(p2->X(), p2->Y()), color)
		};
		window->draw(line, 2, sf::Lines);
	}
}

void RenderEngine::RenderPoints(ConvexHullSolver * solver)
{
	for (long i = 0; i < solver->GetPointCount(); i++) {
		HullPoint* p = solver->GetPoint(i);

		sf::Color color = sf::Color::White;
		if (i == solver->GetPoint1()) {
			color = sf::Color::Yellow;
		}
		else if (i == solver->GetPoint2()) {
			color = sf::Color::Cyan;
		}
		else if (p->cResult == -1) {
			color = sf::Color::Red;
		}
		else if (p->cResult == 1) {
			color = sf::Color::Green;
		}

		sf::CircleShape shape(2.f);
		shape.setFillColor(color);
		shape.setPosition(p->X(), p->Y());
		window->draw(shape);

		// Draw values for that point
		{
			std::ostringstream strstr;
			strstr << "Val: " << p->cValue << std::endl;

			sf::Text text;
			text.setFont(font);
			text.setPosition(p->X() + 3, p->Y() + 3);
			text.setString(strstr.str());
			text.setCharacterSize(12);
			text.setFillColor(sf::Color::Yellow);
			window->draw(text);

		}

	}
}

void RenderEngine::DrawInformation(ConvexHullSolver * solver)
{
	{
		std::ostringstream strstr;
		strstr << "Current Point A: " << solver->GetPoint1() << " / " << solver->GetPointCount() << std::endl;
		strstr << "Current Point B: " << solver->GetPoint2() << " / " << solver->GetPointCount() << std::endl;
		strstr << "Current Lines: " << solver->GetCurrentLines().size() << std::endl;
		strstr << "Current Steps: " << solver->GetTotalNumberOfSteps() << std::endl;

		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setOutlineColor(sf::Color::Black);
		text.setPosition(5, 5);
		text.setString(strstr.str());
		text.setCharacterSize(18);
		window->draw(text);
	}

	// Draw instructions
	{
		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setOutlineColor(sf::Color::Black);
		text.setPosition(5, window->getSize().y - 30);
		text.setString("Press <space> to run continiously. Press <s> to step once.");
		text.setCharacterSize(18);
		window->draw(text);
	}
}


RenderEngine::~RenderEngine()
{
}
