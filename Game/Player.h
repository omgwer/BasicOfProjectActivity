#pragma once
#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "Person.h"

enum PlayerState {
	LEFT,
	RIGHT,
	JUMP,
	DOWN,
	THROW,
	HIDDEN
};

class Player : public Person
{
public:	
	bool isReadyForJump;
	bool onGround;	
	sf::FloatRect rect;
	sf::Sprite sprite;

	Player(sf::Texture& image) : Person(speed, animationSpeed) {
		isReadyForJump = false;
		onGround = false;
		speed = 300;
		animationSpeed = 7;
		sprite.setTexture(image);
		sprite.setTextureRect(sf::IntRect(19, 161, 19, 24));
		rect = sf::FloatRect(50, 50, 19, 24);
	}

	void update(GameMap*, float);

	void collision(GameMap* , int );

	void setPlayerState(PlayerState);
private:	
	const int jumpPower = 2;
	const int gravityPower = 5;
	
};