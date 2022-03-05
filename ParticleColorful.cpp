#include "ParticleColorful.h"
ParticleColorful::ParticleColorful() : Particle()
{
}
sf::Color ParticleColorful::MixColor(sf::Color color1, sf::Color color2, float k)
{
    return sf::Color(
        (int)(color2.r * k + color1.r * (1 - k)),
        (int)(color2.g * k + color1.g * (1 - k)),
        (int)(color2.b * k + color1.b * (1 - k))
    );
}

void ParticleColorful::Draw(sf::RenderWindow& w)
{
    float k = std::min(1.f, Life / 100.f);
    circle.setFillColor(MixColor(FromColor, ToColor, k));
    float l = std::min(1.f, Life / 100.f);
    int alpha = (int)255 * k;
    sf::Color color = circle.getFillColor();
    color.a = alpha;
    circle.setFillColor(color);
    w.draw(circle);
}
