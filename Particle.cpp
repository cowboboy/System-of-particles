#include "Particle.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Config.h"

Particle::Particle()
{
	int direction = rand() % 361;
	int speed = 10 + rand() % 11;
	SpeedX = (float)(cos(direction * DEGTORAD) * speed);
	SpeedY = -(float)(sin(direction * DEGTORAD) * speed);
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
