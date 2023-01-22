#pragma once
#include "Enemy.h"
#include <vector>

class Enemies
{
public:
	Enemies();

	void update(GameMap* , float);
	std::vector<Enemy> enemyList;
	void addEnemy(sf::Texture&, int, int);
private:

};


