#include <algorithm>
#include "Emitter.h"
#include "Config.h"
#include "ParticleColorful.h"
#include "IImpactPoint.h"

void Emitter::MouseControl(sf::RenderWindow& w) {
    sf::Vector2i pixelPos = sf::Mouse::getPosition(w);
    MousePosition = w.mapPixelToCoords(pixelPos);
}

void Emitter::UpdateState(float time)
{
    for (auto& particle : particles)
    {
        particle.Life -= 0.02 * time;
        if (particle.Life < 0) {
            int direction = rand() % 361;
            int speed = 10 + rand() % 11;
            particle.SpeedX = (float)(cos(direction * DEGTORAD) * speed);
            particle.SpeedY = -(float)(sin(direction * DEGTORAD) * speed);
            particle.Radius = 2 + rand() % 11;
            particle.Life = 20 + rand() % 101;
            particle.X = MousePosition.x;
            particle.Y = MousePosition.y;
        } else {
            for (auto& point : impactPoints) {
                point->ImpactParticle(particle);
            }
            particle.SpeedX += GravitationX * time * 0.008;
            particle.SpeedY += GravitationY * time * 0.008;
            particle.X += particle.SpeedX * time * 0.01;
            particle.Y += particle.SpeedY * time * 0.01;
            particle.getShape().setPosition(particle.X, particle.Y);
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (particles.size() < 500) {
            ParticleColorful* p = new ParticleColorful();
            p->FromColor = sf::Color(0, 0, 0);
            p->ToColor = sf::Color(255, 78, 0);
            p->setPos(MousePosition.x, MousePosition.y);
            particles.push_back(*p);
        }
        else {
            break;
        }
    }
}

void Emitter::Render(sf::RenderWindow& w)
{
    for (auto& p : particles) {
        p.Draw(w);
    }
    for (auto& g : impactPoints) {
        g->render(w); 
    }
}
