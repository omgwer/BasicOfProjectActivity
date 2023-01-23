#include "Enemies.h"

Enemies::Enemies()
{
}

void Enemies::update(GameMap* gameMap, float dt)
{
	for (int i = 0; i < this->enemyList.size(); i++) {
		enemyList[i].update(gameMap, dt);
	}
}


void Enemies::addEnemy(sf::Texture& enemyTexture, int x, int y)
{
	Enemy* enemy = new Enemy(enemyTexture, x , y);
	this->enemyList.push_back(*enemy);
}
