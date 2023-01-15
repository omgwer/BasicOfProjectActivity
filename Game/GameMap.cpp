#include "GameMap.h"

GameMap::GameMap()
{
    
}

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
    h = 14;
    w = 40;
    offsetX = 0;
    offsetY = 0;

    tileMap = {
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
      "BBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
    };
}
