#include "TopEmitter.h"

TopEmitter::TopEmitter(int w) : width(w)
{
}

void TopEmitter::ResetParticle(Particle& particle)
{
    particle.Radius = 2 + rand() % 11;
    particle.Life = 20 + rand() % 101;
    particle.X = rand() % (width + 1); 
    particle.Y = -2 * particle.Radius;
    particle.SpeedY = 1;
    particle.SpeedX = -2 + rand() % 5;
}
