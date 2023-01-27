#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameMap.h"
#include "Person.h"
#include "Enemies.h"
#include "Bonuses.h"

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

	void update(GameMap*, float, Enemies*, Bonuses*);

	void collision(GameMap*, int);

	void collisionEnemies(GameMap*, Enemies*);

	void collisionBonuses(GameMap*, Bonuses*);

	void setPlayerState(PlayerState);
private:	
	const int jumpPower = 2;
	const int gravityPower = 5;
	int lifeCount = 3;
	int gamePointsCount = 0;
	bool isAttack;
	bool isAttackFramesZero = false;

	sf::Music attackSound;
	sf::Music jumpSound;

	bool needCollisionToObject(float, float, float, float);

};