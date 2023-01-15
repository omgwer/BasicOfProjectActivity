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

    GameMap();
    GameMap(Level);

    void setLevel(Level);
private:
    void setFirstLevel();
};



/*  sf::String tileMap[14] = {

     "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
     "B                                      B",
     "B                                0     B",
     "B                                B    0B",
     "B                                B    BB",
     "B                                B0    B",
     "B                                BB    B",
     "BBB       0000                  BB    0B",
     "B                                B    BB",
     "B   B                          BBB0    B",
     "B              BB                BB    B",
     "B    B         BB                      B",
     "B    B         BB         BB           B",
     "BBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

  };*/