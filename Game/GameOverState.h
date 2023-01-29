#pragma once
#include "Game.h"
#include "GameMap.h"
#include "UserInterface.h"

class GameOverState : public State
{
public: 
	GameOverState(GameDataRef data, int);

	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);
private:
	GameDataRef stateData;

	GameMap* gameMap = nullptr;
	UserInterface* userInterface = nullptr;

	int resultPoints = 0;

	sf::Texture terraintTexture;
	sf::Sprite terrainSprite;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	std::vector<sf::Sprite>* spriteVector = new std::vector<sf::Sprite>;
};

