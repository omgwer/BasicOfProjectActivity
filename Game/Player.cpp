#include "Player.h"
#include "Person.h"
#include <SFML/Graphics.hpp>

void Player::update(GameMap* gameMap, float time)
{
	rect.left += dx * time;
	collision(gameMap, 0);
	if (!onGround) dy = dy + 0.0005 * time;
	rect.top += dy * time;
	onGround = false;
	collision(gameMap, 1);

	currentFrame += 0.005 * time;
	if (currentFrame > 3) currentFrame = 1;

	if (dx > 0) {
		sprite.setTextureRect(sf::IntRect(19 * int(currentFrame), 189, 19, 24));
		moveDirection = right;
	}
	if (dx < 0) {
		sprite.setTextureRect(sf::IntRect(19 * int(currentFrame) + 19, 189, -19, 24));
		moveDirection = left;
	}

	sprite.setPosition(rect.left - gameMap->offsetX, rect.top - gameMap->offsetY);
	dx = 0;
}

void Player::collision(GameMap* gameMap, int axis)
{
	for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++) {
		int test = rect.top / 32;
		for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++) {
			int test2 = rect.left / 32;
			if (gameMap->tileMap[i][j] == 'B') {
				if (dx > 0 && axis == 0) {
					rect.left = j * 32 - rect.width;
				}
				if (dx < 0 && axis == 0) {
					rect.left = j * 32 + 32;
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
			if (gameMap->tileMap[i][j] == '0') {
				{
					gameMap->tileMap[i][j] = ' ';
				}
			}
		}
	}
}
