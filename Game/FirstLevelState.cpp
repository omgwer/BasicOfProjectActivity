#include "SFML/Graphics.hpp"
#include "FirstLevelState.h"
#include "Player.h"
#include "Defenitions.h"
#include <iostream>

using namespace sf;

FirstLevelState::FirstLevelState(GameDataRef data) : stateData(data)
{
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
    this->enemies = new Enemies();
    this->gameMap = new GameMap(FIRST_LEVEL);

    // инициализация позиций врагов и игрока
    for (int i = 0; i < gameMap->h; i++)
        for (int j = 0; j < gameMap->w; j++) {
            if (gameMap->tileMap[i][j] == 'P') {
                int positionX = j * 32;
                int positionY = i * 32 - 15;
                this->player = new Player(playerTexture, positionX, positionY);
            }                
            if (gameMap->tileMap[i][j] == 'E') {
                int positionX = j * 32;
                int positionY = i * 32 + 2;
                this->enemies->addEnemy(enemyTexture, positionX, positionY);
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
    player->update(gameMap, dt, enemies);

    //
    enemies->update(gameMap, dt);
       

    // сдвиг карты за игроком
    if (player->rect.left > (600 / 2))
        gameMap->offsetX = player->rect.left - 600 / 2;
    if (player->rect.top > (448 / 2))
        gameMap->offsetY = player->rect.top - 448 / 2;
}

void FirstLevelState::draw(float dt)
{
    RectangleShape rectangle({ 32,32 });
    stateData->window.clear(sf::Color(160, 82, 45, 1));

    for (int i = 0; i < gameMap->h; i++)
        for (int j = 0; j < gameMap->w; j++)
        {            
            if (gameMap->tileMap[i][j] == 'B')
                rectangle.setFillColor(Color::Black);

            else if (gameMap->tileMap[i][j] == '0')
                rectangle.setFillColor(Color::Green);            

            else {
                continue;
            }
                
               /* if (gameMap->tileMap[i][j] == ' ' || gameMap->tileMap[i][j] == 'P' )
                continue;*/

            rectangle.setPosition(j * 32 - gameMap->offsetX, i * 32 - gameMap->offsetY);
            stateData->window.draw(rectangle);
        }  

    for (int i = 0; i < this->enemies->enemyList.size(); i++) {
        Enemy test = enemies->enemyList[i];
        stateData->window.draw(test.sprite);
    }
    stateData->window.draw(player->sprite);
    stateData->window.display();    
}
