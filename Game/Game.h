#pragma once
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "Player.h"

struct GameData
{
	StateManager stateManager;
	sf::RenderWindow window;	
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
private:
	const float dt = 1.0f / 60.f;
	sf::Clock clock;
	GameDataRef _data = std::make_shared<GameData>();
	
	void run();

public:
	Game(int, int, std::string);
};

