#include "GameMap.h"

GameMap::GameMap(Level level)
{
    setLevel(level);
}

bool GameMap::isAvailableTextureChar(char expectedChar)
{
    for (int i = 0; i < 8; i++) {
        if (expectedChar == availableTextureChar[i]) {
            return true;
        }
    }
    return false;
}

void GameMap::setLevel(Level level) {
    switch (level)
    {
    case MAIN_MENU:
        setMainMenuLevel();
        break;
    case FIRST_LEVEL:
        setFirstLevel();
        break;
    case SECOND_LEVEL:
        break;
    case END_GAME:
        setGameOverLevel();
        break;
    default:
        break;
    }
}

void GameMap::setFirstLevel() {   

    tileMap = {    
   "Q                                            ",
   "Q                                            ",
   "Q                                            ",
   "Q                                            ",
   "Q                                            ",
   "Q                 U    I   I     I  E  F I   ",
   "Q                                IIIIIIIIII  ",
   "Q             I                              ",
   "Q                                            ",
   "Q        Q                                   ",
   "Q   QX   QQQQ               X    Z     C     ",
   "Q    Q               RR    II   YY    QQ     ",
   "Q     Q      E   Q                          X",
   "Q    QQQQQQQQQQQQQQQ      E  Q            ZQQ",
   "Q                  QQQQQQQQQQ     Q      Q   ",
   "Q         ZZZZZZZZZZZZ           Q      Q    ",
   "Q                                Q     Q     ",
   "Q                   ZZZZZZZZZZ   Q    QQ     ",
   "Q         Z                      Q     Q     ",
   "Q  ZPZZZ     QQ    Z       Z     QQ    Q     ",
   "QQQQQQQQ       QQ           Q   QQ     Q     ",
   "Q                   Q  E  QQ     Q    QQ     ",
   "Q   Q     ZXC  Z    QQQQQQQ    QQQ     Q     ",
   "Q              QQ                QQ    Q     ",
   "Q    Q         QQ                      Q     ",
   "Q ZZZZ    Q   E   Q  ZZZZ E         Q        ",
   "QQQQQQQW  RTYUIOQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ"
};

    offsetX = 0;
    offsetY = 0;
    h = tileMap.size();
    w = tileMap[0].getSize();
}

void GameMap::setMainMenuLevel() {

    tileMap = {
   "YYYYYYYYYY     YYYYYYYYYY",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "                         ",
   "                         ",
   "                         ",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "YYYYYYYYYY     YYYYYYYYYY"
    };

    offsetX = 0;
    offsetY = 0;
    h = tileMap.size();
    w = tileMap[0].getSize();
}

void GameMap::setGameOverLevel() {

    tileMap = {
   "YYYYYYYYYY     YYYYYYYYYY",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "                         ",
   "                         ",
   "                         ",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "Y                       Y",
   "YYYYYYYYYY     YYYYYYYYYY"
    };

    offsetX = 0;
    offsetY = 0;
    h = tileMap.size();
    w = tileMap[0].getSize();
}
