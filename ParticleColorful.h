#pragma once
#include "Particle.h"
class ParticleColorful : public Particle
{
public:
	sf::Color FromColor;
	sf::Color ToColor;
	ParticleColorful();
	static sf::Color MixColor(sf::Color color1, sf::Color color2, float k);
	void Draw(sf::RenderWindow& w) override;
};

