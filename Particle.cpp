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

void Particle::setPos(float x, float y) {
	X = x; Y = y;
	circle.setPosition(X, Y);
}

sf::CircleShape& Particle::getShape() {
	return circle;
}
