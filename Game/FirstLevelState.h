#pragma once
#include "Game.h"
#include "State.h"

class FirstLevelState : public State {
public:
	FirstLevelState(GameDataRef data);
	~FirstLevelState();
	
	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
private:
	sf::Texture t ;
	GameDataRef stateData;	
	Player* player = nullptr;
	GameMap* gameMap = nullptr;
};
