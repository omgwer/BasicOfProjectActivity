#include "Enemy.h"

Enemy::Enemy(sf::Texture& image, int x, int y) : Person(speed, animationSpeed) {
	speed = 250;
	animationSpeed = 7;
	sprite.setTexture(image);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	rect = sf::FloatRect(50, 50, 32, 32);
}

void Enemy::update(GameMap* gameMap, float dt) {
	sprite.setPosition(rect.left, rect.top);
}