#include "Enemy.h"
#include <cmath>

Enemy::Enemy(sf::Texture& image, int x, int y) : Person(speed, animationSpeed) {
	speed = 150;
	animationSpeed = 14;
	sprite.setTexture(image);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	rect = sf::FloatRect(x, y, 32, 32);
}

void Enemy::update(GameMap* gameMap, float dt) {	
	if (moveDirection == right) {
		dx = 1;
	}
	else {
		dx = -1;
	}

	if (dt > 0.05f) {
		dt = 0.05f;
	}
	

	rect.left += dx * dt * speed;
	collision(gameMap, 0);
	if (!onGround)
		dy = dy + dt * gravityPower;
	rect.top += dy * dt * speed;
	collision(gameMap, 1);

	currentFrame += dt * animationSpeed;
	if (currentFrame > 8) currentFrame = 0;
	if (dx > 0) {
		sprite.setTextureRect(sf::IntRect(32 * int(currentFrame), 0, 32, 32));
	}
	if (dx < 0) {
		sprite.setTextureRect(sf::IntRect(32 * int(currentFrame) + 32, 0, -32, 32));
	}
	
	sprite.setPosition(rect.left - gameMap->offsetX, rect.top - gameMap->offsetY);
	dx = 0;
}

void Enemy::collision(GameMap* gameMap, int axis)
{	
	onGround = false;
	for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++) {
		int test = rect.top / 32;
		if (test > gameMap->h) {
			i = gameMap->h;
		}
		for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++) {
			if (gameMap->isAvailableTextureChar(gameMap->tileMap[i][j])) {
				if (dx > 0 && axis == 0) {
					rect.left = j * 32 - rect.width;
					moveDirection = left;
				}
				if (dx < 0 && axis == 0) {
					rect.left = j * 32 + 32;
					moveDirection = right;
				}
				if (dy > 0 && axis == 1) {
					if (dy > 0) {
						rect.top = i * 32 - rect.height;
						dy = 0;
						onGround = true;
					}
				}
				if (dy < 0 && axis == 1) {
					if (dy < 0) {
						rect.top = i * 32 + 32;
						dy = 0;
					}
				}
			}			
		}
	}
}