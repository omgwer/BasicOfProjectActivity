#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;
constexpr float BALL_SIZE = 40.f;
constexpr float OFFSET_Y = 90.f;  
constexpr float SPEED_X = 0.0005;
constexpr float amplitudeY = 80.f;
constexpr float periodY = 2; 

int main()
{
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Wave Moving ball");
    sf::Clock clock;
    sf::Clock speedXSync;
    sf::Vector2f position = {50.f, 250.f};    
    sf::CircleShape shape(BALL_SIZE);
    shape.setFillColor(sf::Color(254, 254, 254));
    float speedX = 100.f; 

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

        float time = clock.getElapsedTime().asSeconds();
        sf::Vector2f currentPosition = shape.getPosition();
        const float wavePhase = time * float(2 * M_PI);

        if ((position.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speedX > 0)) {
            speedX = -speedX;
        }
        if ((position.x < 0 ) && (speedX < 0)) {
            speedX = -speedX;   
        }    

        position.y =  amplitudeY * std::sin(wavePhase / periodY) +  OFFSET_Y;
        position.x = currentPosition.x + speedX * speedXSync.restart().asSeconds();       

        shape.setPosition(position);
        window.clear();
        window.draw(shape);
        window.display();
    }
}