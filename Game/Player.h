#pragma once
#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "Person.h"

class Player : public Person
{
public:
	bool isReadyForJump;
	bool onGround;

	Player(sf::Texture& image) : Person(image) {
		isReadyForJump = false;
		onGround = false;
	}

	void update(GameMap*, float);

	void collision(GameMap* , int );
};