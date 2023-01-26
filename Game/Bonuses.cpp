#include "Bonuses.h"

Bonuses::Bonuses()
{
}

void Bonuses::addBonus(sf::Sprite& enemySprite, int x, int y, int bonusIncrementor)
{
	Bonus* enemy = new Bonus(enemySprite, x, y, bonusIncrementor);
	this->bonusesList.push_back(*enemy);
}

void Bonuses::update(GameMap* gameMap, float dt)
{
	for (int i = 0; i < this->bonusesList.size(); i++) {
		bonusesList[i].update(gameMap, dt);
	}
}