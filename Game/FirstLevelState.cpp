#include "SFML/Graphics.hpp"
#include "FirstLevelState.h"
#include "Player.h"
#include "Defenitions.h"

using namespace sf;

FirstLevelState::FirstLevelState(GameDataRef data) : stateData(data)
{
}

FirstLevelState::~FirstLevelState()
{
}

void FirstLevelState::init()
{    
    t.loadFromFile(PLAYER_SPRITE_SET_PATH);
    this->player = new Player(t);
    this->gameMap = new GameMap();
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
                player->sprite.setTextureRect(IntRect(19, 161, 19, 24));                
            }
            else {
                player->sprite.setTextureRect(IntRect(19 + 19, 161, -19, 24));
            }
            if (event.key.code == sf::Keyboard::Space) {
                player->isReadyForJump = true;
            }
        }
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
    player->update(gameMap, dt);   

    // сдвиг карты за игроком
    if (player->rect.left > (600 / 2))
        gameMap->offsetX = player->rect.left - 600 / 2;
    if (player->rect.top > (448 / 2))
        gameMap->offsetY = player->rect.top - 448 / 2;
}

void FirstLevelState::draw(float dt)
{
    RectangleShape rectangle({ 32,32 });
    stateData->window.clear(Color::White);
    for (int i = 0; i < gameMap->h; i++)
        for (int j = 0; j < gameMap->w; j++)
        {            
            if (gameMap->tileMap[i][j] == 'B')
                rectangle.setFillColor(Color::Black);

            if (gameMap->tileMap[i][j] == '0')
                rectangle.setFillColor(Color::Green);

            if (gameMap->tileMap[i][j] == ' ') continue;

            rectangle.setPosition(j * 32 - gameMap->offsetX, i * 32 - gameMap->offsetY);
            stateData->window.draw(rectangle);
        }   
    stateData->window.draw(player->sprite);
    stateData->window.display();    
}
