#pragma once
#include <iostream>
#include <list>
#include "Particle.h"
class Particles
{
public:
	std::list<Particle> particles;
	void UpdateState(float time);
	void Render(sf::RenderWindow& w);
	void MouseControl(sf::RenderWindow& w);
	sf::Vector2f MousePosition;
};

