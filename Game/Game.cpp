#include "Game.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Game::Game(int gameWidth, int gameHeight, std::string gameName) {
    data->window.create(VideoMode(600, 448), "test");
    run();
}

void Game::run() {
    Texture t;
    t.loadFromFile("./Data/Picture/chipndale.gif");
    data->player = new Player(t);
    data->gameMap = new GameMap();

    RectangleShape rectangle({ 32,32 });

    while (data->window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 300;

        sf::Event event;
        while (this->data->window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                data->window.close();
            if (event.type == Event::KeyReleased) {
                if (data->player->moveDirection == right) {
                    data->player->sprite.setTextureRect(IntRect(19, 161, 19, 24));
                }
                else {
                    data->player->sprite.setTextureRect(IntRect(19 + 19, 161, -19, 24));
                }
                if (event.key.code == sf::Keyboard::Space) {
                    data->player->isReadyForJump = true;
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            if (data->player->moveDirection == right) {
                data->player->sprite.setTextureRect(IntRect(63, 161, 19, 24));
            }
            else {
                data->player->sprite.setTextureRect(IntRect(63 + 19, 161, -19, 24));
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left)) {
            data->player->dx = -0.1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right)) {
            data->player->dx = 0.1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            if (data->player->onGround && data->player->isReadyForJump) {
                data->player->dy = -0.4;
                data->player->onGround = false;
                data->player->isReadyForJump = false;
            }
        }
        data->player->update(data->gameMap, time);

        if (data->player->rect.left > (600 / 2))
            data->gameMap->offsetX = data->player->rect.left - 600 / 2;
        if (data->player->rect.top > (448 / 2))
            data->gameMap->offsetY = data->player->rect.top - 448 / 2;

        data->window.clear(Color::White);
        for (int i = 0; i < data->gameMap->H; i++)
            for (int j = 0; j < data->gameMap->W; j++)
            {
                if (data->gameMap->tileMap[i][j] == 'B')
                    rectangle.setFillColor(Color::Black);

                if (data->gameMap->tileMap[i][j] == '0')
                    rectangle.setFillColor(Color::Green);

                if (data->gameMap->tileMap[i][j] == ' ') continue;

                rectangle.setPosition(j * 32 - data->gameMap->offsetX, i * 32 - data->gameMap->offsetY);
                data->window.draw(rectangle);
            }

        data->window.draw(data->player->sprite);
        data->window.display();
    }
}
