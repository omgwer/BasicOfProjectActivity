#pragma once
#include <SFML/Graphics.hpp>

enum direction {
	left,
	right
};

class Person
{
public:
	float dx, dy;
	sf::FloatRect rect;
	sf::Sprite sprite;
	float currentFrame;
	direction moveDirection;
	int speed, animationSpeed;

	Person(sf::Texture& image);
};

