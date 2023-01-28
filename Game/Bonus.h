#pragma once
#include <SFML/Graphics.hpp>
#include "GameMap.h"

class Bonus
{
public:
	Bonus(sf::Sprite&, int, int y, int);
		
	sf::FloatRect rect;
	sf::Sprite sprite;
	int bonusIncrementor;

	void update(GameMap*, float);
	void collision(GameMap*, int);
private:
	float currentFrame;
	int animationSpeed = 23;

};

