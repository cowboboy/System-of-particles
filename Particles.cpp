#include "Particles.h"
#include "Config.h"
#include <algorithm>

void Particles::MouseControl(sf::RenderWindow& w) {
    sf::Vector2i pixelPos = sf::Mouse::getPosition(w);
    MousePosition = w.mapPixelToCoords(pixelPos);
}

void Particles::UpdateState(float time)
{
    for (auto& particle : particles)
    {
        particle.Life -= 0.02 * time;
        if (particle.Life < 0) {
            particle.Direction = rand() % 361;
            particle.Speed = 10 + rand() % 11;
            particle.Radius = 2 + rand() % 11;
            particle.Life = 20 + rand() % 101;
            particle.X = MousePosition.x;
            particle.Y = MousePosition.y;
        } else {
            float directionInRadians = particle.Direction * 0.017453f;
            particle.X += (float)(particle.Speed * cos(directionInRadians) * time * 0.01);
            particle.Y += (float)(particle.Speed * sin(directionInRadians) * time * 0.01);
            particle.getShape().setPosition(particle.X, particle.Y);
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (particles.size() < 500) {
            Particle* p = new Particle();
            p->setPos(MousePosition.x, MousePosition.y);
            particles.push_back(*p);
        }
        else {
            break;
        }
    }
}

void Particles::Render(sf::RenderWindow& w)
{
    for (auto& p : particles) {
        float k = std::min(1.f, p.Life / 100);
        int alpha = (int)255 * k;
        sf::Color color = p.getShape().getFillColor();
        color.a = alpha;
        p.getShape().setFillColor(color);
        w.draw(p.getShape());
    }
}
