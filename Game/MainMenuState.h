#pragma once
#include "Game.h"
#include "State.h"
#include "UserInterface.h"
#include <SFML/Audio.hpp>
#include "GameMap.h"

enum SelectedMenuItem {
	NEW_GAME,
	SOUND_EFFECTS,
	MUSIC,
	EXIT
};

class MainMenuState : public State
{
public:
	MainMenuState(GameDataRef data);

	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);
private:
	GameDataRef stateData;
	sf::Texture terraintTexture;
	sf::Sprite terrainSprite;

	sf::Texture selectedMenuItemTexture;
	sf::Sprite selectedMenuItemSprite;
	float currentFrameSelectedMenu = 0;

	sf::Texture settingsTexture;
	sf::Sprite settingsSprite;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	std::vector<sf::Sprite>* spriteVector = new std::vector<sf::Sprite>;

	GameMap* gameMap = nullptr;

	sf::Music backgroundMusic;

	UserInterface* userInterface = nullptr;

	SelectedMenuItem selectedMenuItem = NEW_GAME;

	sf::Vector2f getPosition();

	void setMenuItem(SelectedMenuItem);

	bool effectsSound = true;
	bool backgroundSound = true;
};

