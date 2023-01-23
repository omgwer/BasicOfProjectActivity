#pragma once
#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "Person.h"


class Enemy : public Person
{
public:
	bool onGround;
	Enemy(sf::Texture&, int, int y);
	void update(GameMap*, float);
	void collision(GameMap*, int);
	sf::FloatRect rect;
	sf::Sprite sprite;
private: 
	int gravityPower = 5;
};