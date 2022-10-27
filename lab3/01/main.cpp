#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Simple Event Loop");
    sf::Clock clock;

    sf::CircleShape shape(40);
    shape.setPosition({200, 120});
    shape.setFillColor(sf::Color(254, 254, 254));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        constexpr float speed = 1.f;
        const float deltaTime = clock.restart().asSecond();
        sf::Vector2f position = shape.getPosition();
        position.x += 0.5;
        shape.setPosition(position);

        window.clear();
        window.draw(shape);
        window.display();
    }
}