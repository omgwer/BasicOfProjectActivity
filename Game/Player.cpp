#include "Player.h"
#include "Person.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::Texture& image, int x, int y) : Person(speed, animationSpeed) {
	isReadyForJump = false;
	onGround = false;
	speed = 300;
	animationSpeed = 7;
	sprite.setTexture(image);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	rect = sf::FloatRect(x, y, 32, 32);
}

void Player::update(GameMap* gameMap, float dt)
{	
	rect.left += dx * dt * speed;
	collision(gameMap, 0);
	if (!onGround) 
		dy = dy + dt * gravityPower;
	rect.top += dy * dt * speed;
	collision(gameMap, 1);

	if (onGround == true) { 
		currentFrame += dt * animationSpeed;
		if (currentFrame > 8) currentFrame = 0;
		if (dx > 0) {
			sprite.setTextureRect(sf::IntRect(32 * int(currentFrame), 96, 32, 32));
			moveDirection = right;
		}
		if (dx < 0) {
			sprite.setTextureRect(sf::IntRect(32 * int(currentFrame) + 32, 96, -32, 32));
			moveDirection = left;
		}
	}
	else {
		currentFrame += dt * animationSpeed;
		if (currentFrame > 5) currentFrame = 2;
		if (dx > 0) {
			sprite.setTextureRect(sf::IntRect(32 * int(currentFrame), 5 * 32, 32, 32));
			moveDirection = right;
		}
		if (dx < 0) {
			sprite.setTextureRect(sf::IntRect(32 * int(currentFrame) + 32, 5 * 32, -32, 32));
			moveDirection = left;
		}
	}	

	sprite.setPosition(rect.left - gameMap->offsetX, rect.top - gameMap->offsetY);
	dx = 0;
}

void Player::collision(GameMap* gameMap, int axis)
{
	onGround = false;
	for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++) {
		int test = rect.top / 32;
		if (test > gameMap->h) {
			i = gameMap->h;
		}
		for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++) {
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

void Player::setPlayerState(PlayerState playerState)
{
	switch (playerState)
	{
	case LEFT:
		dx = -1;
		break;
	case RIGHT:
		dx = 1;
		break;
	case JUMP:
		if (onGround && isReadyForJump) {
			dy = -jumpPower;
			onGround = false;
			isReadyForJump = false;
		}
		break;
	case DOWN:
		if (moveDirection == right) {
			sprite.setTextureRect(sf::IntRect(3 * 32, 4 * 32, 32, 32));
		}
		else {
			sprite.setTextureRect(sf::IntRect(3 * 32 + 32, 4 * 32, -32, 32));
		}
		break;
	case THROW:
		break;	
	default:
		break;
	}
}
