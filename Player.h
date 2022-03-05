#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(std::string f, float m_speedRotate, float m_speedMovement, int x, int y);
	sf::Vector2f getCoords();
	sf::Sprite getSprite();
	sf::Vertex* getLine();
	void setLine(float x, float y);
	sf::Vector2f getForwardDirection();
	void setForwardDirection(float X, float Y);
	void Update(float time);
	void Control();
private:
	float m_speedRotate, m_speedMovement;
	sf::Vector2f m_coords, m_forwardDirection;
	sf::Image m_imagePlayer;
	sf::Texture m_texturePlayer;
	sf::Sprite m_spritePlayer;
	//sf::RectangleShape m_forwardVector;
	sf::Vertex m_line[2];
};

