#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");

    Texture t;
    t.loadFromFile("./Data/Picture/chipndale.gif");

    Player player(t);

    Clock clock;

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
        window.clear(Color(254,254,254));
        window.draw(player.sprite);
        window.display();
    }

    return 0;
}