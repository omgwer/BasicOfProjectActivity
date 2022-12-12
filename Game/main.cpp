#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;

const int H = 14;
const int W = 40;

String tileMap[H] = {

"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                                      B",
"B                                      B",
"B                                B     B",
"B                                B     B",
"B                                B     B",
"B                                B     B",
"B         0000                BBBB     B",
"B                                B     B",
"BBB                              B     B",
"B              BB                BB    B",
"B    B         BB                      B",
"B    B         BB         BB           B",
"BBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

};

int main()
{
    RenderWindow window(VideoMode(600, 448), "Chip&dale videogame");
    Texture t;
    t.loadFromFile("./Data/Picture/chipndale.gif");
    Player player(t);  // create new player model
    Clock clock;

    RectangleShape rectangle({32,32});
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 200;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyReleased) {
                if (player.moveDirection == right) {
                    player.sprite.setTextureRect(IntRect(19, 161, 19, 24));
                }
                else {
                    player.sprite.setTextureRect(IntRect(19 + 19, 161, -19, 24));
                }
                if (event.key.code == sf::Keyboard::Space) {
                    player.isReadyForJump = true;
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            if (player.moveDirection == right) {
                player.sprite.setTextureRect(IntRect(63, 161, 19, 24));
            }
            else {
                player.sprite.setTextureRect(IntRect(63 + 19, 161, -19, 24));
            }            
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left)) {
            player.dx = -0.1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right)) {
            player.dx = 0.1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            if (player.onGround && player.isReadyForJump) {
                player.dy = -0.4;
                player.onGround = false;
                player.isReadyForJump = false;
            }
        }        
        player.update(time);
        window.clear(Color::White);

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
            {
                if (tileMap[i][j] == 'B') 
                    rectangle.setFillColor(Color::Black);

                if (tileMap[i][j] == '0')  
                    rectangle.setFillColor(Color::Green);

                if (tileMap[i][j] == ' ') continue;

                rectangle.setPosition(j * 32,i * 32);
                window.draw(rectangle);
            }
        
        window.draw(player.sprite);
        window.display();
    }

    return 0;
}