#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void redrawFrame(sf::RenderWindow &window, sf::Sprite texture)
{
    window.clear(sf::Color(244, 244, 244));
    window.draw(texture);
    window.display();
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            //onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Cat", sf::Style::Default, settings);
    sf::Clock clock;
    sf::Vector2f mousePosition;

    sf::Texture texture;
    texture.loadFromFile("cat.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f({150, 150}));

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        redrawFrame(window, sprite);
    }
}
