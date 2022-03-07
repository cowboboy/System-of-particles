#include "Point.h"
#include <SFML/Graphics.hpp>

Point::Point(float x, float y)
{
	Radius = 5;
	point.setRadius(Radius);
	point.setFillColor(sf::Color::Red);
	X = x, Y = y;
	point.setPosition(X, Y);
}

void Point::Draw(sf::RenderWindow& w)
{
	w.draw(point);
}
