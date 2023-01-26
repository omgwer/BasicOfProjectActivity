#pragma once
#include "Enemy.h"
#include "GameMap.h"
#include <vector>

class Enemies
{
public:
	Enemies();
	std::vector<Enemy> enemyList;
	void update(GameMap* , float);
	void addEnemy(sf::Texture&, int, int);
};


