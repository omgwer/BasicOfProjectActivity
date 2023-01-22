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

class  Player : public Person
{
public:	
	bool isReadyForJump;
	bool onGround;	
	sf::FloatRect rect;
	sf::Sprite sprite;

	Player(sf::Texture&, int, int);

	void update(GameMap*, float);

	void collision(GameMap*, int);

	void setPlayerState(PlayerState);
private:	
	const int jumpPower = 2;
	const int gravityPower = 5;
	
};