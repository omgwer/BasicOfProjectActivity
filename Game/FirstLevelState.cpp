#include "SFML/Graphics.hpp"
#include "FirstLevelState.h"
#include "Player.h"
#include "Defenitions.h"
#include <iostream>

using namespace sf;

FirstLevelState::FirstLevelState(GameDataRef data) : stateData(data)
{
    backgroundTexture.loadFromFile(BACKGROUND_SPRITE_SET_PATH);
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    spriteVector->push_back(backgroundSprite);

    terraintTexture.loadFromFile(TERRAIN_SPRITE_SET_PATH);
    terrainSprite.setTexture(terraintTexture);

    terrainSprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(96, 62, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(96, 128, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(208, 16, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(208, 80, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(208, 144, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(320, 64, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(288, 144, 32, 32));
    spriteVector->push_back(terrainSprite);

    //bonuses
    bonusTexture.loadFromFile(APPLE_SPRITE_SET_PATH);
    bonusSprite.setTexture(bonusTexture);

    bonusSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    bonusesVector->push_back(bonusSprite);

   /* bonusTexture.loadFromFile(BANANAS_SPRITE_SET_PATH);
    bonusTexture.loadFromFile(KIWI_SPRITE_SET_PATH);*/
}

FirstLevelState::~FirstLevelState()
{
}

void FirstLevelState::init()
{   
    int playerPositionX = 50;
    int playerPositionY = 50;
    playerTexture.loadFromFile(PLAYER_SPRITE_SET_PATH);
    enemyTexture.loadFromFile(ENEMY_SPRITE_SET_PATH);   

    bonusTexture.loadFromFile(APPLE_SPRITE_SET_PATH);  

    this->bonuses = new Bonuses();
    this->enemies = new Enemies();
    this->gameMap = new GameMap(FIRST_LEVEL);
      
   
    backgroundMusic.openFromFile(FISRT_LEVEL_SOUND);
    backgroundMusic.setVolume(25);
    backgroundMusic.play();
    backgroundMusic.setLoop(true);


    // инициализация позиций врагов и игрока
    for (int i = 0; i < gameMap->h; i++)
        for (int j = 0; j < gameMap->w; j++) {
            if (gameMap->tileMap[i][j] == 'P') {
                int positionX = j * 32;
                int positionY = i * 32 - 15;
                this->player = new Player(playerTexture, positionX, positionY);
                gameMap->tileMap[i][j] = ' ';
            }
            if (gameMap->tileMap[i][j] == 'E') {
                int positionX = j * 32;
                int positionY = i * 32 + 2;
                this->enemies->addEnemy(enemyTexture, positionX, positionY);
                gameMap->tileMap[i][j] = ' ';
            }   
            if (gameMap->tileMap[i][j] == 'Z') {
                int positionX = j * 32;
                int positionY = i * 32;
                this->bonuses->addBonus(bonusesVector->at(0), positionX, positionY, 25);
                gameMap->tileMap[i][j] = ' ';                
            }
            if (gameMap->tileMap[i][j] == 'X') {
                int positionX = j * 32;
                int positionY = i * 32;
                this->bonuses->addBonus(bonusesVector->at(0), positionX, positionY, 35);
                gameMap->tileMap[i][j] = ' ';
            }
            if (gameMap->tileMap[i][j] == 'C') {
                int positionX = j * 32;
                int positionY = i * 32;
                this->bonuses->addBonus(bonusesVector->at(0), positionX, positionY, 50);
                gameMap->tileMap[i][j] = ' ';
            }
        }
}

void FirstLevelState::handleInput()
{    
    sf::Event event;
    while (stateData->window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            stateData->window.close();
        if (event.type == Event::KeyReleased) {
            if (player->moveDirection == right) {
                player->sprite.setTextureRect(IntRect(0, 0, 32, 32));                
            }
            else {
                player->sprite.setTextureRect(IntRect(0 + 32, 161, -32, 32));
            }
            if (event.key.code == sf::Keyboard::Space) {
                player->isReadyForJump = true;
            }
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::LControl)) {
        player->setPlayerState(PlayerState::ATTACK);
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        player->setPlayerState(PlayerState::DOWN);
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left)) {
        player->setPlayerState(PlayerState::LEFT);
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        player->setPlayerState(PlayerState::RIGHT);
    }
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        player->setPlayerState(PlayerState::JUMP);
    }    
}

void FirstLevelState::update(float dt)
{    
    // update player position
    player->update(gameMap, dt, enemies, bonuses);

    //
    enemies->update(gameMap, dt);

    bonuses->update(gameMap, dt);

    // сдвиг карты за игроком
    if (player->rect.left > (GAME_WIDTH / 2))
        gameMap->offsetX = player->rect.left - GAME_WIDTH / 2;
    if (player->rect.top > (GAME_HEIGHT / 2))
        gameMap->offsetY = player->rect.top - GAME_HEIGHT / 2;
}

void FirstLevelState::draw(float dt)
{   
    Sprite sprite;
    stateData->window.clear(sf::Color(160, 82, 45, 1));

    for (int i = 0; i < gameMap->h; i++)
        for (int j = 0; j < gameMap->w; j++)
        {         
            switch (gameMap->tileMap[i][j])
            {
            case ' ':
                sprite = spriteVector->at(0);
                break;
            case 'Q': 
                sprite = spriteVector->at(1);
                break;            
            case 'W': 
                sprite = spriteVector->at(2);
                break;
            case 'R':
                sprite = spriteVector->at(3);
                break;
            case 'T':
                sprite = spriteVector->at(4);
                break;
            case 'Y':
                sprite = spriteVector->at(5);
                break;
            case 'U':
                sprite = spriteVector->at(6);
                break;
            case 'I':
                sprite = spriteVector->at(7);
                break;
            case 'O':
                sprite = spriteVector->at(8);
                break;           

            default:
                continue;
            }

            sprite.setPosition(j * 32 - gameMap->offsetX, i * 32 - gameMap->offsetY);
            
            stateData->window.draw(sprite);
        }  

    for (int i = 0; i < this->enemies->enemyList.size(); i++) {
        Enemy enemy = enemies->enemyList[i];
        stateData->window.draw(enemy.sprite);
    }

    for (int i = 0; i < this->bonuses->bonusesList.size(); i++) {
        Bonus bonus = bonuses->bonusesList[i];
        stateData->window.draw(bonus.sprite);
    }

    stateData->window.draw(player->sprite);
    stateData->window.display();    
}
