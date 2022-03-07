#pragma once
#include <SFML\Graphics.hpp>
class Particle
{
public:
    int Radius;
    float X, Y;  
    float SpeedX, SpeedY;
    float Life;
    sf::CircleShape circle;
    Particle();
    virtual void Draw(sf::RenderWindow& w);
    sf::CircleShape& getShape();
    void setPos(float x, float y);
};

