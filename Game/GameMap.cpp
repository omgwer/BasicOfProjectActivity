#include "GameMap.h"

GameMap::GameMap(Level level)
{
    setLevel(level);
}

void GameMap::setLevel(Level level) {
    switch (level)
    {
    case MAIN_MENU:
        break;
    case FIRST_LEVEL:
        setFirstLevel();
        break;
    case SECOND_LEVEL:
        break;
    case END_GAME:
        break;
    default:
        break;
    }
}

void GameMap::setFirstLevel() {

    tileMap = {
      "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
      "B                                      B     ",
      "B                                0     B     ",
      "B                                B    0B     ",
      "B                                B    BB     ",
      "B                                B0    B     ",
      "B E         E                    BB    B     ",
      "BBB       0000                  BB    0B     ",
      "B   E                            B    BB     ",
      "B   B                          BBB0    B     ",
      "B    P         BB                BB    B     ",
      "B    B         BB                      B     ",
      "B    B         BB      E  BB       B         ",
      "BBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
    };

    offsetX = 0;
    offsetY = 0;
    h = tileMap.size();
    w = tileMap[0].getSize();
}
