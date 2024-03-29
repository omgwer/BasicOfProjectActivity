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

	int lifeCount = 3;
	int gamePointsCount = 0;

	Player(sf::Texture&, int, int);

	void update(GameMap*, float, Enemies*, Bonuses*);

	void collision(GameMap*, int);

	void collisionEnemies(GameMap*, Enemies*);

	void collisionBonuses(GameMap*, Bonuses*);

	void setPlayerState(PlayerState);
private:	
	const int jumpPower = 2;
	const int gravityPower = 5;
	int defaultLeft = 50;
	int defaultTop = 350;

	bool isAttack;
	bool isAttackFramesZero = false;

	sf::Music attackSound;
	sf::Music jumpSound;
	sf::Music bonusSound;

	void addPoints(int);

	bool needCollisionToObject(float, float, float, float);

};