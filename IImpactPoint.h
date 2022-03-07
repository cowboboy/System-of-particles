#pragma once
#include "Particle.h"
#include "Point.h"
class IImpactPoint
{
public:
	virtual void ImpactParticle(Particle& particle) = 0;
	virtual void render(sf::RenderWindow& w) = 0; 
};

