#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GameMap.h"
// Base class of the game, contains base controls and execute game.
using namespace sf;

class Game
{
private:
	const int GAME_WIDTH = 600;
	const int GAME_HEIGT = 448;
	const std::string GAME_NAME = "Chip&dale videogame";
	RenderWindow window;
	Clock clock;
	Player player;
	GameMap gameMap;	
	bool isRun = false;
		
public:
	Game();
	void run();     // init game window
	void end(); //  check result  + change to new game + exit

	void initPersons();
	void initGameMap();
	// game flow cycle
	// check inputs
	// draw persons
	// draw map
	// check features(bonuses, lives etc)
	void gameFlowCycle();
	void checkInputs();
	void drawPersons();
	void drawMap();

};

