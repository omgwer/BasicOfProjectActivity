#include "Person.h"

Person::Person()
{
}

Person::Person(sf::Texture& image)
{
	sprite.setTexture(image);
	sprite.setTextureRect(sf::IntRect(19, 161, 19, 24));
	rect = sf::FloatRect(50, 50, 19, 24);
	dx = dy = 0;
	currentFrame = 0;
	direction moveDirection = right;
}
