#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;
const sf::Vector2f defaultPosition = {400, 320};


int main()
{
    constexpr int pointCount = 200;
    constexpr float radiusSize = 150;
    float newAngle = 0;
    sf::Clock clock;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Ellipse", sf::Style::Default, settings);   

    sf::ConvexShape shape;
    shape.setPosition(defaultPosition);
    shape.setFillColor(sf::Color(254, 9, 80));

    constexpr float rotationRadius = 100;


    shape.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo) {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        float ellipseRadius = radiusSize * std::sin(6 * angle);
        sf::Vector2f point = sf::Vector2f {
            ellipseRadius * std::sin( angle ),
            ellipseRadius * std::cos( angle )
        };
        shape.setPoint(pointNo, point);
    }
        
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            float deltaTime = clock.restart().asSeconds();    
            newAngle += 2 * deltaTime;       
                        
            sf::Vector2f newPoint = sf::Vector2f {
                rotationRadius * std::sin( newAngle ),
                rotationRadius * std::cos( newAngle )
            };

            shape.setPosition(defaultPosition + newPoint);
        }        

        window.clear();
        window.draw(shape);
        window.display();
    }
}