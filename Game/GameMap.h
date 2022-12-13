#pragma once
#include <SFML/Graphics.hpp>

class GameMap
{
public:
    const int H = 14;
    const int W = 40;
    int offsetX = 0;
    int offsetY = 0;

    GameMap();

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
};