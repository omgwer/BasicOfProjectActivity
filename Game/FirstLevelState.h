#pragma once
#include "Game.h"
#include "State.h"
#include "Player.h"

class FirstLevelState : public State {
public:
	FirstLevelState(GameDataRef data);
	~FirstLevelState();
	
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);
private:
	sf::Texture t;
	GameDataRef stateData;	

	Player* player = nullptr;
	GameMap* gameMap = nullptr;
};
