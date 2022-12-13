#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace sf;

struct GameData
{		
	RenderWindow window;
	Player* player;
	GameMap* gameMap;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
private:
	const float dt = 1.0f / 60.f;
	Clock clock;
	GameDataRef data = std::make_shared<GameData>();
	
	void run();

public:
	Game(int, int, std::string);
};

