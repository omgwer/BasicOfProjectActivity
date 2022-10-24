#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({200, 600}), "Recatangles and circle");
    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({180, 580});
    shape1.setPosition({10, 10});
    shape1.setFillColor(sf::Color(0x4D, 0x4D, 0x4D));
    window.draw(shape1);

    sf::CircleShape shape2(85);
    shape2.setPosition({15, 30});
    shape2.setFillColor(sf::Color(0x0, 0xBB, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(85);
    shape3.setPosition({15, 220});
    shape3.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(shape3);

    sf::CircleShape shape4(85);
    shape4.setPosition({15, 410});
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));
}