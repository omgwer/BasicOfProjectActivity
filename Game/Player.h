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

	Player(sf::Texture& image) : Person(image) {
		isReadyForJump = false;
		onGround = false;
		speed = 300;
		animationSpeed = 7;
	}

	void update(GameMap*, float);

	void collision(GameMap* , int );

	void setPlayerState(PlayerState);
private:	
	const int jumpPower = 2;
	const int gravityPower = 5;
};