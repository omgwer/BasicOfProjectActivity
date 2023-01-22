#pragma once
#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "Person.h"

class Enemy : public Person
{
public:
	Enemy(sf::Texture&, int, int y);
	void update(GameMap*, float);
	sf::FloatRect rect;
	sf::Sprite sprite;	
};

