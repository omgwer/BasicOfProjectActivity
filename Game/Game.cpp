#include "Game.h"
#include <SFML/Graphics.hpp>
#include "FirstLevelState.h"

using namespace sf;

Game::Game(int gameWidth, int gameHeight, std::string gameName) {
    _data->window.create(VideoMode(600, 448), "test");
    _data->stateManager.addState(StateRef(new FirstLevelState(this->_data)));
    run();
}

void Game::run() {      

    while (_data->window.isOpen())
    {
        this->_data->stateManager.processStateChanges();

        float dt = clock.getElapsedTime().asSeconds();
        clock.restart();     

        this->_data->stateManager.getActiveState()->HandleInput();
        this->_data->stateManager.getActiveState()->Update(dt);
        this->_data->stateManager.getActiveState()->Draw(dt);
    }
}
