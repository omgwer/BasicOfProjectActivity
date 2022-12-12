#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::Texture& image)
{
	isReadyForJump = true;
	sprite.setTexture(image);
	sprite.setTextureRect(sf::IntRect(19, 161, 19, 24));
	rect = sf::FloatRect(50, 50, 19, 24);	
	dx = dy = 0;
	currentFrame = 0;	
	direction moveDirection = right;
}

void Player::update(float time)
{
	rect.left += dx * time;
	
	Collision(0);

	if (!onGround) dy = dy + 0.0005 * time;
	rect.top += dy * time;
	onGround = false;
	Collision(1);
		

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

void Player::Collision(int axis)
{
	const int H = 14;
	const int W = 40;
	sf::String tileMap[H] = {
		
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"B                                      B",
	"B                                      B",
	"B                                B     B",
	"B                                B     B",
	"B                                B     B",
	"B                                B     B",
	"B         0000                BBBB     B",
	"B                                B     B",
	"BBB                              B     B",
	"B              BB                BB    B",
	"B    B         BB                      B",
	"B    B         BB         BB           B",
	"BBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

	};


	for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++) {
		for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++) {
			if (tileMap[i][j] == 'B') {
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
						rect.top = j * 32 + 32;
					}
				}
			}
		}
	}
}