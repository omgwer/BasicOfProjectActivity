#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << " , y= " << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case ::sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, const float dt)
{
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Cat follows mouse", sf::Style::Default, settings);
    sf::Clock clock;
    sf::Vector2f mousePosition;

    sf::ConvexShape pointer;
    init(pointer);

    while (window.isOpen())
    {
        const float dt = clock.restart().asSeconds();
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, dt);
        redrawFrame(window, pointer);
    }
}