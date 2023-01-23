#pragma once
#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "Person.h"
#include "Enemies.h"

enum PlayerState {
	LEFT,
	RIGHT,
	JUMP,
	DOWN,
	ATTACK,
	HIDDEN
};

class  Player : public Person
{
public:	
	bool isReadyForJump = true;
	bool onGround;	
	sf::FloatRect rect;
	sf::Sprite sprite;

	Player(sf::Texture&, int, int);

	void update(GameMap*, float, Enemies*);

	void collision(GameMap*, int);

	void collisionEnemies(GameMap*, Enemies*);

	void setPlayerState(PlayerState);
private:	
	const int jumpPower = 2;
	const int gravityPower = 5;
	int lifeCount = 3;
	bool isAttack;
	int attackFrames = 0;
};