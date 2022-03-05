#include "Player.h"
#include <iostream>

Player::Player(std::string f, float speedRotate, float speedMovement, int x, int y) : m_speedRotate(speedRotate), m_speedMovement(speedMovement), m_coords(x, y), m_forwardDirection(1, 0)
{
	m_imagePlayer.loadFromFile("images/" + f);
	m_imagePlayer.createMaskFromColor(sf::Color(255, 255, 255));
	m_texturePlayer.loadFromImage(m_imagePlayer);
	m_spritePlayer.setTexture(m_texturePlayer);
	m_spritePlayer.setTextureRect(sf::IntRect(0, 1, 300, 123));
	m_spritePlayer.setPosition(m_coords);
	m_spritePlayer.setOrigin(150, 123 / 2);
	m_line[0] = sf::Vertex(m_coords);
	m_line[1] = sf::Vertex(sf::Vector2f(m_coords.x + 100, m_coords.y));
	//m_forwardVector.setFillColor(sf::Color(15, 180, 140));
}

sf::Vector2f Player::getCoords()
{
	return m_coords;
}
sf::Sprite Player::getSprite()
{
	return m_spritePlayer;
}
sf::Vertex* Player::getLine()
{
	return m_line;
}
void Player::setLine(float x, float y)
{
	m_line[1].position = sf::Vector2f(x, y);
}
sf::Vector2f Player::getForwardDirection()
{
	return m_line[1].position;
}
void Player::setForwardDirection(float X, float Y)
{
	m_forwardDirection.x = X;
	m_forwardDirection.y = Y;
}
void Player::Update(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_spritePlayer.rotate(-0.1f * time);
		//m_forwardVector.rotate(-0.1f * time);
		float x, y, tempX = getForwardDirection().x, tempY = getForwardDirection().y;
		x = cos(-0.1f * time * 3.14 / 180) * (tempX - m_coords.x) - sin(-0.1f * time * 3.14 / 180) * (tempY - m_coords.y);
		y = sin(-0.1f * time * 3.14 / 180) * (tempX - m_coords.x) + cos(-0.1f * time * 3.14 / 180) * (tempY - m_coords.y);
		setLine(x, y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_spritePlayer.rotate(0.1f * time);
		//m_forwardVector.rotate(0.1f * time);
		float x, y, tempX = getForwardDirection().x, tempY = getForwardDirection().y;
		x = cos(0.1f * time * 3.14 / 180) * (tempX - m_coords.x) - sin(0.1f * time * 3.14 / 180) * (tempY - m_coords.y);
		y = sin(0.1f * time * 3.14 / 180) * (tempX - m_coords.x) + cos(0.1f * time * 3.14 / 180) * (tempY - m_coords.y);
		setLine(x, y);
	}
	//m_forwardVector.setPosition(m_coords);
	m_spritePlayer.setPosition(m_coords);
}

void Player::Control()
{
}
