#include "Game.h"
#include <SFML/Graphics.hpp>
#include "FirstLevelState.h"

using namespace sf;

Game::Game(int gameWidth, int gameHeight, std::string gameName) {
    data->window.create(VideoMode(gameWidth, gameHeight), gameName);
    data->stateManager.addState(StateRef(new FirstLevelState(this->data)));
    run();
}

void Game::run() {      

    while (data->window.isOpen())
    {
        this->data->stateManager.processStateChanges();

        float dt = clock.getElapsedTime().asSeconds();
        clock.restart();     

        this->data->stateManager.getActiveState()->handleInput();
        this->data->stateManager.getActiveState()->update(dt);
        this->data->stateManager.getActiveState()->draw(dt);
    }
}
