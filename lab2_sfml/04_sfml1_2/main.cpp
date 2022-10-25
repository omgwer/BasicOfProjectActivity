#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1000, 500}), "Name");
    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({25, 480});
    shape1.setPosition({10, 10});
    shape1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({25, 270});
    shape2.setRotation(210);
    shape2.setPosition({35, 260});
    shape2.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({25, 270});
    shape3.setRotation(-30);
    shape3.setPosition({25, 250});
    shape3.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({25, 470});
    shape4.setRotation(10);
    shape4.setPosition({300, 20});
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({25, 470});
    shape5.setRotation(-10);
    shape5.setPosition({310, 20});
    shape5.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({25, 100});
    shape6.setRotation(90);
    shape6.setPosition({360, 250});
    shape6.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape6);

    sf::CircleShape shape7;
    shape7.setRadius(200);
    shape7.setPosition({500, 50});
    shape7.setFillColor(sf::Color(150, 150, 150));
    shape7.setOutlineThickness(10);
    shape7.setOutlineColor(sf::Color(250, 0, 0));
    window.draw(shape7);

    window.display();

    sf::sleep(sf::seconds(5));
}