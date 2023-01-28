#pragma once
#include "SFML/Graphics.hpp"
class UserInterface
{
public:
	UserInterface();

	std::vector<sf::Sprite> getLifesSprite(int);
	std::vector<sf::Sprite> getPointsSprite(int);
private:
	sf::Texture fontTexture;
	sf::Sprite fontSprite;
	int fontHeight = 10;
	int fontWidth = 8;
};

