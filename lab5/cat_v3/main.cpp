#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

struct Cat
{
    sf::ConvexShape head;
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

void onMouseMove(const sf::Event::MouseButtonEvent &event, sf::Vector2f &mousePosition)
{
    // std::cout << "mouse x=" << event.x << " , y= " << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

void onCursorMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << " , y= " << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition, sf::Vector2f &targetToMove)
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
            onCursorMove(event.mouseMove, mousePosition);
            break;
        case sf::Event::MouseButtonPressed:
            onMouseMove(event.mouseButton, targetToMove);
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
}

Cat addCat()
{
    const float outlineWidth = 3.f;
    const sf::Color outlineColor = sf::Color(1, 1, 1);
    const sf::Color fillColor = sf::Color(227, 206, 18);
    const sf::Vector2f startPosition = sf::Vector2f({250, 250});
    Cat newCat;
    newCat.head.setPointCount(7);
    newCat.head.setPoint(0, {30, 0});
    newCat.head.setPoint(1, {0, -40});
    newCat.head.setPoint(2, {0, -20});
    newCat.head.setPoint(3, {-40, -20});
    newCat.head.setPoint(4, {-40, 20});
    newCat.head.setPoint(5, {0, 20});
    newCat.head.setPoint(6, {0, 40});
    newCat.head.setFillColor(fillColor);
    newCat.head.setOutlineThickness(outlineWidth);
    newCat.head.setOutlineColor(outlineColor);

    newCat.position = startPosition;
    newCat.head.setPosition(newCat.position);
    updateArrowElements(newCat);
    return newCat;
}

sf::Vector2f getNormalize(sf::Vector2f delta)
{
    sf::Vector2f normalizeVector;
    normalizeVector.x = ((float)delta.x / (float)sqrt(delta.x * delta.x + delta.y * delta.y));
    normalizeVector.y = ((float)delta.y / (float)sqrt(delta.x * delta.x + delta.y * delta.y));
    return normalizeVector;
}

void update(const sf::Vector2f &mousePosition, Cat &cat, const float dt)
{
    const sf::Vector2f oldPosition = cat.head.getPosition();
    const sf::Vector2f delta = mousePosition - oldPosition;
    const float angleMaxSpeed = 45 * dt;
    float angle = atan2(delta.y, delta.x);
    if (angle < 0)
        angle += 2 * M_PI;
    angle = toDegrees(angle);
    const float oldRotation = cat.head.getRotation();
    const float rotation = std::abs(angle - oldRotation);

    //update angle
    if (angle != oldRotation)
    {
        if (angle > oldRotation)
        {
            if ((angle - 180) > oldRotation)
            {
                cat.head.setRotation(oldRotation - std::min(angleMaxSpeed, rotation));
            }
            else
            {
                cat.head.setRotation(oldRotation + std::min(angleMaxSpeed, rotation));
            }
        }
        else
        {
            if ((angle + 180) < oldRotation)
            {
                cat.head.setRotation(oldRotation + std::min(angleMaxSpeed, rotation));
            }
            else
            {
                cat.head.setRotation(oldRotation - std::min(angleMaxSpeed, rotation));
            }
        }
    }

    //updatePosition
    if (oldPosition != mousePosition)
    {
        sf::Vector2f normalizeVector = getNormalize(delta);
        const float maxSpeed = 20 * dt;
        cat.head.setPosition(oldPosition + normalizeVector * maxSpeed);
    }
}

void redrawFrame(sf::RenderWindow &window, Cat &cat)
{
    window.clear(sf::Color(244, 244, 244));
    window.draw(cat.head);
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
    sf::Vector2f targetPosition = {0, 0};

    Cat cat = addCat();

    while (window.isOpen())
    {
        const float dt = clock.restart().asSeconds();
        pollEvents(window, mousePosition, targetPosition);
        if (targetPosition.x != 0 && targetPosition.y != 0)
        {
            update(targetPosition, cat, dt);
        }
        redrawFrame(window, cat);
    }
}
