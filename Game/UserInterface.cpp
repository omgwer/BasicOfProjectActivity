#include "UserInterface.h"
#include "Defenitions.h"

UserInterface::UserInterface() {
	fontTexture.loadFromFile(FONT_BLACK);
	fontSprite.setTexture(fontTexture);
}

std::vector<sf::Sprite> UserInterface::getLifesSprite(int)
{
	std::vector<sf::Sprite> lifesSpriteList;
	fontSprite.setTextureRect(sf::IntRect(0, 0, 10, 8));
	fontSprite.setPosition(sf::Vector2f(10, 10));
	lifesSpriteList.push_back(fontSprite);


	return lifesSpriteList;
}

std::vector<sf::Sprite> UserInterface::getPointsSprite(int)
{
	std::vector<sf::Sprite> pointsSpriteList;


	return pointsSpriteList;
}
