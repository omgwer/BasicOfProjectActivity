#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class UserInterface
{
public:
	UserInterface();

	std::vector<sf::Sprite> getLifesSprite(int);
	std::vector<sf::Sprite> getPointsSprite(int);
	std::vector<sf::Sprite> getSpriteListByString(sf::Vector2f,float, std::string);
private:
	sf::Texture fontTexture;
	sf::Sprite fontSprite;

	sf::Texture lifeTexture;
	sf::Sprite lifeSprite;
	int fontHeight = 10;
	int fontWidth = 8;
};
