#pragma once
#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "Person.h"

class Enemy : public Person
{
	sf::FloatRect rect;
	sf::Sprite sprite;

	Enemy(sf::Texture& image, int x, int y) : Person(speed, animationSpeed) {
		speed = 250;
		animationSpeed = 7;
		sprite.setTexture(image);
		sprite.setTextureRect(sf::IntRect(19, 161, 19, 24));
		rect = sf::FloatRect(x, y, 19, 24);
	}

};

