#include "Player.h"
#include "Person.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::Texture& image, int x, int y) : Person(speed, animationSpeed) {
	isReadyForJump = false;
	isAttack = false;
	onGround = false;
	speed = 250;
	animationSpeed = 7;
	sprite.setTexture(image);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	rect = sf::FloatRect(x, y, 32, 32);
}

void Player::update(GameMap* gameMap, float dt, Enemies* enemies)
{	
	if (dt > 0.05f) {
		dt = 0.05f;
	}

	if (isAttack) {
		collisionEnemies(gameMap, enemies);
		currentFrame += dt * animationSpeed;
		if (isAttackFramesZero) {
			isAttackFramesZero = false;
			currentFrame = 0;
		}
		if (currentFrame > 8) {
			currentFrame = 0;
			isAttack = false;
		}			
		if (moveDirection == right) {
			sprite.setTextureRect(sf::IntRect(32 * int(currentFrame), 8 * 32, 32, 32));
		}
		if (moveDirection == left) {
			sprite.setTextureRect(sf::IntRect(32 * int(currentFrame) + 32, 8 * 32, -32, 32));
		}
		return;
	}	

	collisionEnemies(gameMap, enemies);

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

void Player::collision(GameMap* gameMap, int axis) {
	// collision with game map or bonuses
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
			if (gameMap->tileMap[i][j] == 'B') {
				{
					gameMap->tileMap[i][j] = ' ';
				}
			}
		}
	}
}

void Player::collisionEnemies(GameMap* gameMap, Enemies* enemies) {
	int defaultLeft = 50;
	int defaultTop = 50;
	for (int i = 0; i < enemies->enemyList.size(); i++) {
		float enemyYPositionBase = enemies->enemyList.at(i).rect.top;
		float enemyXPositionBase = enemies->enemyList.at(i).rect.left;

		int testWidth = 20;
		for (int y = rect.top; y < (rect.top + rect.height); y++) {
			for (int x = rect.left; x < (rect.left + testWidth); x++) {
				for (int eY = enemyYPositionBase; eY < (enemyYPositionBase + rect.height); eY++) {
					for (int eX = enemyXPositionBase; eX < (enemyXPositionBase + testWidth); eX++) {
						if (x == eX && y == eY) {
							
							if (isAttack) {								
								std::vector<Enemy>::iterator nth = enemies->enemyList.begin() + i;
								enemies->enemyList.erase(nth);							
								return;
							}
							if (lifeCount <= 1) {
								throw std::exception("game over!");
							}
							lifeCount--;
							rect.left = defaultLeft;
							rect.top = defaultTop;
							gameMap->offsetY = 0;
							gameMap->offsetX = 0;
						}
					}
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
	case ATTACK:	
		if (isAttack == false) {
			isAttack = true;
			isAttackFramesZero = true;
		}			
		break;
	default:
		break;
	}
}
