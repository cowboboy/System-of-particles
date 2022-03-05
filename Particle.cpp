#include "Particle.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Particle::Particle()
{
	Direction = rand() % 361;
	Speed = 10 + rand() % 11;
	Radius = 2 + rand() % 11;
	Life = 20 + rand() % 101;
	circle.setRadius(Radius);
	circle.setFillColor(sf::Color::Black);
}

void Particle::Draw(sf::RenderWindow& w)
{
	float k = std::min(1.f, Life / 100.f);
	int alpha = (int)255 * k;
	sf::Color color = circle.getFillColor();
	color.a = alpha;
	circle.setFillColor(color);
	w.draw(circle);
}

sf::CircleShape& Particle::getShape()
{
	return circle;
}

void Particle::setPos(float x, float y) {
	X = x; Y = y;
	circle.setPosition(X, Y);
}
