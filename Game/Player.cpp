#include "Player.h"
#include <SFML/Graphics.hpp>

int ground = 150;

Player::Player(sf::Texture& image)
{
	isReadyForJump = true;
	Player::sprite.setTexture(image);
	sprite.setScale({2,2});
	rect = sf::FloatRect(0, 0, 19, 24);	
	dx = dy = 0;
	currentFrame = 0;	
	direction moveDirection = right;
}

void Player::update(float time)
{
	rect.left += dx * time;

	if (!onGround) dy = dy + 0.0005 * time;
	rect.top += dy * time;
	onGround = false;

	if (rect.top > ground) {
		rect.top = ground;
		dy = 0;
		onGround = true;
	}

	currentFrame += 0.001 * time;
	if (currentFrame > 3) currentFrame = 1;

	if (dx > 0) {
		sprite.setTextureRect(sf::IntRect(19 * int(currentFrame), 189, 19, 24));
		moveDirection = right;
	}			
	if (dx < 0) {
		sprite.setTextureRect(sf::IntRect(19 * int(currentFrame) + 19, 189, -19, 24));
		moveDirection = left;
	}
		
	sprite.setPosition(rect.left, rect.top);
	dx = 0;
}
