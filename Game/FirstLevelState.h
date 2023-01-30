#pragma once
#include "Game.h"
#include "State.h"
#include "Player.h"
#include "Enemies.h"
#include "Bonuses.h"
#include "UserInterface.h"
#include <SFML/Audio.hpp>

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

	sf::Texture terraintTexture;
	sf::Sprite terrainSprite;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Texture bonusTexture;
	sf::Sprite bonusSprite;

	sf::Texture bonusTexture1;
	sf::Sprite bonusSprite1;

	sf::Texture bonusTexture2;
	sf::Sprite bonusSprite2;

	sf::Texture finishTexture;
	sf::Sprite finishSprite;

	GameDataRef stateData;

	std::vector<sf::Sprite>* spriteVector = new std::vector<sf::Sprite>;

	std::vector<sf::Sprite>* bonusesVector = new std::vector<sf::Sprite>;

	sf::Music backgroundMusic;

	void drawUi(sf::RenderWindow&, int , int);

	UserInterface* userInterface = nullptr;
	Bonuses* bonuses = nullptr;
	Enemies* enemies = nullptr;
	Player* player = nullptr;
	GameMap* gameMap = nullptr;
};
