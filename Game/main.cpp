#include "Game.h"
#include "Defenitions.h"
int main()
{ 
    Game game(GAME_WIDTH, GAME_HEIGHT, GAME_NAME);
    game.run();
    return 1337;
}