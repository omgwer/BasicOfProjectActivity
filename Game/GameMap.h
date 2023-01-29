#pragma once
#include <SFML/Graphics.hpp>

enum Level {
    MAIN_MENU,
    FIRST_LEVEL,
    SECOND_LEVEL,
    END_GAME
};

struct GameLevel {
    int h, w, offsetX = 0, offsetY = 0;
};

class GameMap
{
public:
    int h, w, offsetX, offsetY;
    std::vector<sf::String> tileMap;

    GameMap(Level);
    bool isAvailableTextureChar(char);
    void setLevel(Level);
private:
    void setFirstLevel();
    void setMainMenuLevel();
    void setGameOverLevel();
    char availableTextureChar[8] = { 'Q', 'W', 'R', 'T', 'Y', 'U', 'I', 'O' };
};