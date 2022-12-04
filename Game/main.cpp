#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    // x, y, width, height

    Texture t;
    t.loadFromFile("./Data/Picture/chipndale.gif");

    float currentFrame = 1;

    Sprite s;
    s.setTexture(t);
    s.setTextureRect(IntRect(19, 189, 19, 24));
    s.setScale(Vector2f(4,4));
    s.setPosition(0, 0);

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
        }
        if (Event::KeyReleased) {
            s.setTextureRect(IntRect(19, 161, 19, 24));
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            s.move(-0.05 * time, 0);

            currentFrame += 0.001 * time;
            if (currentFrame > 3) currentFrame = 1;

            s.setTextureRect(IntRect(19 * int(currentFrame) +19, 189, -19, 24));
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            s.move(0.05 * time, 0);

            currentFrame += 0.001 * time;
            if (currentFrame > 3) currentFrame = 1;

            s.setTextureRect(IntRect(19*int(currentFrame), 189, 19,24));
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
           // s.move(0, -0.1);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {            
            s.setTextureRect(IntRect(63, 161, 19, 24));
        }

        window.clear(Color(254,254,254));
        window.draw(s);
        window.display();
    }

    return 0;
}