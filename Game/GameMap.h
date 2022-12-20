#pragma once
#include <SFML/Graphics.hpp>

class GameMap
{
public:
    int h, w, offsetX, offsetY;  

    sf::String tileMap[14] = {

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

    };

    GameMap();    
};