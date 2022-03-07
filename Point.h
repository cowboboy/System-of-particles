#pragma once
#include <SFML/Graphics.hpp>

class Point
{
public:
	int Radius;
	float X, Y;
	sf::CircleShape point;
	Point(float x, float y);
	void Draw(sf::RenderWindow& w);
};

