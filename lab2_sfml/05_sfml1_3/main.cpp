#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 700}), "House");
    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({600, 300});
    shape1.setPosition({40, 250});
    shape1.setFillColor(sf::Color(77, 46, 28));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({80, 150});
    shape2.setPosition({90, 400});
    shape2.setFillColor(sf::Color(26, 26, 26));
    window.draw(shape2);

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(103, 27, 26));
    trapeze.setPosition(400, 150);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-220, -20});
    trapeze.setPoint(1, {130, -20});
    trapeze.setPoint(2, {280, 105});
    trapeze.setPoint(3, {-390, 105});
    window.draw(trapeze);

    sf::RectangleShape shape3;
    shape3.setSize({35, 70});
    shape3.setPosition({480, 110});
    shape3.setFillColor(sf::Color(80, 80, 80));
    window.draw(shape3);

    sf::CircleShape shape7;
    shape7.setRadius(18);
    shape7.setPosition({495, 49});
    shape7.setFillColor(sf::Color(160, 160, 160));
    window.draw(shape7);

    sf::RectangleShape shape4;
    shape4.setSize({65, 40});
    shape4.setPosition({465, 80});
    shape4.setFillColor(sf::Color(80, 80, 80));
    window.draw(shape4);

    sf::CircleShape shape8;
    shape8.setRadius(20);
    shape8.setPosition({505, 20});
    shape8.setFillColor(sf::Color(160, 160, 160));
    window.draw(shape8);

    sf::CircleShape shape9;
    shape9.setRadius(22);
    shape9.setPosition({520, 0});
    shape9.setFillColor(sf::Color(160, 160, 160));
    window.draw(shape9);

    window.display();
    sf::sleep(sf::seconds(5));
}