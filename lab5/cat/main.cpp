#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

struct Cat
{
    sf::ConvexShape head;
    sf::RectangleShape stem;
    sf::Vector2f position;
    float rotation = 0;
};

sf::Vector2f toEuclidean(float radius, float angle)
{
    return {
        radius * (float)cos(angle),
        radius * (float)sin(angle)};
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

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
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        case sf::Event::MouseButtonPressed:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void updateArrowElements(Cat &arrow)
{
    const sf::Vector2f headOffset = toEuclidean(23, arrow.rotation);
    arrow.head.setPosition(arrow.position + headOffset);
    arrow.head.setRotation(toDegrees(arrow.rotation));

    const sf::Vector2f stemOffset = toEuclidean(0, arrow.rotation);
    arrow.stem.setPosition(arrow.position);
    arrow.stem.setRotation(toDegrees(arrow.rotation));
}

Cat addCat()
{
    const float outlineWidth = 3.f;
    const sf::Color outlineColor = sf::Color(1, 1, 1);
    const sf::Color fillColor = sf::Color(227, 206, 18);
    const sf::Vector2f startPosition = sf::Vector2f({250, 250});
    Cat newCat;
    newCat.head.setPointCount(3);
    newCat.head.setPoint(0, {30, 0});
    newCat.head.setPoint(1, {0, -40});
    newCat.head.setPoint(2, {0, 40});
    newCat.head.setFillColor(fillColor);
    newCat.head.setOutlineThickness(outlineWidth);
    newCat.head.setOutlineColor(outlineColor);
    newCat.stem.setSize({40, 40});
    newCat.stem.setOrigin({20, 20});
    newCat.stem.setFillColor(fillColor);
    newCat.stem.setOutlineThickness(outlineWidth);
    newCat.stem.setOutlineColor(outlineColor);
    newCat.position = startPosition;
    newCat.head.setPosition(newCat.position);
    newCat.stem.setPosition(newCat.position);
    updateArrowElements(newCat);
    return newCat;
}

void update(const sf::Vector2f &mousePosition, Cat &cat, const float dt)
{
    const sf::Vector2f delta = mousePosition - cat.position;
    cat.rotation = atan2(delta.y, delta.x);
    updateArrowElements(cat);
}

void redrawFrame(sf::RenderWindow &window, Cat &cat)
{
    window.clear(sf::Color(244, 244, 244));
    window.draw(cat.head);
    window.draw(cat.stem);
    window.display();
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

    Cat cat = addCat();

    while (window.isOpen())
    {
        const float dt = clock.restart().asSeconds();
        pollEvents(window, mousePosition);
        update(mousePosition, cat, dt);
        redrawFrame(window, cat);
    }
}
