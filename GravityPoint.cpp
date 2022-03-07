#include "GravityPoint.h"
#include "IImpactPoint.h"

GravityPoint::GravityPoint(float x, float y) : p(x, y)
{
    Power = 100;
    X = x; Y = y;
}

void GravityPoint::ImpactParticle(Particle& particle)
{
    float gX = X - particle.X;
    float gY = Y - particle.Y;
    float r2 = ((100 > gX * gX + gY * gY) ? 100 : gX * gX + gY * gY);
    particle.SpeedX += gX * Power / r2;
    particle.SpeedY += gY * Power / r2;
}

void GravityPoint::render(sf::RenderWindow& w)
{
    p.Draw(w);
}
