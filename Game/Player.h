#pragma once
#include <SFML/Graphics.hpp>

enum direction {
	left,
	right
};

class Player
{
public:
	float dx, dy;
	sf::FloatRect rect;
	bool onGround;
	bool isReadyForJump;
	sf::Sprite sprite;
	float currentFrame;
	direction moveDirection;

	Player(sf::Texture& image);	

	void Collision(int);

	void update(float time);	
};