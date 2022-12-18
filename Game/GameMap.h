#pragma once
#include <SFML/Graphics.hpp>

class GameMap
{
public:
    int h, w, offsetX, offsetY;  

    sf::String tileMap[14] = {

       "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
       "B                                      B",
       "B                                      B",
       "B                                B     B",
       "B                                B     B",
       "B                                B     B",
       "B                                B     B",
       "BBB       0000                BBBB     B",
       "B                                B     B",
       "B                                B     B",
       "B              BB                BB    B",
       "B    B         BB                      B",
       "B    B         BB         BB           B",
       "BBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

    };

    GameMap();    
};