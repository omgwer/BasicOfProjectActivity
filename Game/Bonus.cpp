#include "Bonus.h"
#include <cstdlib>

Bonus::Bonus(sf::Sprite& sprite, int x, int y, int bonusIncrementor) {
	/*sprite.setTexture(image);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));*/
	this->sprite = sprite;
	this->bonusIncrementor = bonusIncrementor;
	rect = sf::FloatRect(x, y, 32, 32);
	//generate random 0-17
	currentFrame = ((float)rand() / RAND_MAX) * (16 - 0) + 0;	
}

void Bonus::update(GameMap* gameMap, float dt)
{	
	if (dt > 0.05f) {
		dt = 0.05f;
	}

	currentFrame += dt * animationSpeed;
	if (currentFrame > 16) {
		currentFrame = 0;
	}
		
	sprite.setTextureRect(sf::IntRect(32 * int(currentFrame), 0, 32, 32));

	sprite.setPosition(rect.left - gameMap->offsetX, rect.top - gameMap->offsetY);
}

void Bonus::collision(GameMap* gameMap, int axis)
{
}
