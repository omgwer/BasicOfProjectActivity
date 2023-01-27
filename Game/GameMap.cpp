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
    //tileMap = {
    //  "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
    //  "Q                                      Q     ",
    //  "Q                                B     Q     ",
    //  "Q                                Q    BQ     ",
    //  "Q                                Q    QQ     ",
    //  "Q                                QB    Q     ",
    //  "Q  ZP        QQ                  QQ    Q     ",
    //  "QQQQQQQQ       QQ           Q   QQ    BQ     ",
    //  "Q                   Q     QQ     Q    QQ     ",
    //  "Q   Q               QQQQQQQ    QQQB    Q     ",
    //  "Q              QQ                QQ    Q     ",
    //  "Q    Q         QQ                      Q     ",
    //  "Q         Q   E   Q                 Q        ",
    //  "QQQQQQQWQWRTYUIOQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ"
    //};

    tileMap = {
   "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
   "Q                                      Q     ",
   "Q         ZZZZZZZZZZZZ           B     Q     ",
   "Q                                Q    BQ     ",
   "Q                   ZZZZZZZZZZ   Q    QQ     ",
   "Q         Z                      QB    Q     ",
   "Q  ZP        QQ    Z       Z     QQ    Q     ",
   "QQQQQQQQ       QQ           Q   QQ    BQ     ",
   "Q                   Q     QQ     Q    QQ     ",
   "Q   Q          Z    QQQQQQQ    QQQB    Q     ",
   "Q              QQ                QQ    Q     ",
   "Q    Q         QQ                      Q     ",
   "Q         Q   E   Q  ZZZZZZZZZZ     Q        ",
   "QQQQQQQWQWRTYUIOQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ"
};

    offsetX = 0;
    offsetY = 0;
    h = tileMap.size();
    w = tileMap[0].getSize();
}


//tileMap = {
//   "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ",
//   "Q                                      Q     ",
//   "Q                                B     Q     ",
//   "Q                                Q    BQ     ",
//   "Q                                Q    QQ     ",
//   "Q         Z                      QB    Q     ",
//   "Q  ZP        QQ    Z       Z     QQ    Q     ",
//   "QQQQQQQQ       QQ           Q   QQ    BQ     ",
//   "Q                   Q     QQ     Q    QQ     ",
//   "Q   Q          Z    QQQQQQQ    QQQB    Q     ",
//   "Q              QQ                QQ    Q     ",
//   "Q    Q         QQ                      Q     ",
//   "Q         Q   E   Q                 Q        ",
//   "QQQQQQQWQWRTYUIOQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ"
//};