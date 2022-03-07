#pragma once
#include "IImpactPoint.h"
class AntiGravityPoint : public IImpactPoint
{
public:
	Point p;
	int Power;
	float X, Y;
	AntiGravityPoint(float x, float y);
	void ImpactParticle(Particle& particle) override;
	void render(sf::RenderWindow& w);
};

