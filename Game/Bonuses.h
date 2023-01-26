#pragma once
#include "GameMap.h"
#include "Bonus.h"

class Bonuses
{
public:
	Bonuses();

	std::vector<Bonus> bonusesList;
	void addBonus(sf::Sprite& , int, int, int);
	void update(GameMap*, float);
};