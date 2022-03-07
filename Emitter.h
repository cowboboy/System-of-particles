#pragma once
#include <iostream>
#include <list>
#include "Particle.h"
#include "ParticleColorful.h"
#include "Point.h"
#include "IImpactPoint.h"
class Emitter
{
public:
	std::list<ParticleColorful> particles;
	std::list<IImpactPoint*> impactPoints;
	void UpdateState(float time);
	void Render(sf::RenderWindow& w);
	void MouseControl(sf::RenderWindow& w);
	sf::Vector2f MousePosition;
	float GravitationX = 0, GravitationY = 1;
};

