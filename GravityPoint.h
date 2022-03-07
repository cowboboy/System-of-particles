#pragma once
#include "IImpactPoint.h"
class GravityPoint : public IImpactPoint
{
public:
	Point p;
	int Power;
	float X, Y;
	GravityPoint(float x, float y);
	void ImpactParticle (Particle& particle) override;
	void render(sf::RenderWindow& w);
};

