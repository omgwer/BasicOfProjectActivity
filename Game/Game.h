#pragma once
#include <SFML/Graphics.hpp>
#include "StateManager.h"

struct GameData
{
	StateManager stateManager;
	sf::RenderWindow window;	
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
private:
	sf::Clock clock;
	GameDataRef data = std::make_shared<GameData>();
	
	void run();

public:
	Game(int, int, std::string);
};

