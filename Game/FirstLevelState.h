#pragma once
#include "Game.h"
#include "State.h"
#include "Player.h"
#include "Enemies.h"

class FirstLevelState : public State {
public:
	FirstLevelState(GameDataRef data);
	~FirstLevelState();
	
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);
private:
	sf::Texture playerTexture;
	sf::Texture enemyTexture;
	GameDataRef stateData;

	Enemies* enemies = nullptr;
	Player* player = nullptr;
	GameMap* gameMap = nullptr;
};
