#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

struct Eve
{
    sf::ConvexShape whiteOfTheEve;
    sf::ConvexShape pupilOfTheEve;
    sf::Vector2f pupilLimiter;
    sf::Vector2f pupilDefaultPosition;
};

struct Eves
{
    Eve leftEve;
    Eve rightEve;
};

sf::Vector2f toEuclidean(float radiusX, float radiusY, float angle)
{
    return {
        radiusX * (float)cos(angle),
        radiusY * (float)sin(angle)};
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    //std::cout << "mouse x=" << event.x << " , y= " << event.y << std::endl;
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
        default:
            break;
        }
    }
}

void updateEve(Eve &eve, float angle, const sf::Vector2f &mousePosition)
{
    const int limit = 40;
    if ((eve.pupilDefaultPosition.x + limit >= mousePosition.x) && (eve.pupilDefaultPosition.x - limit <= mousePosition.x))
    {
        std::cout << "default x = " << eve.pupilDefaultPosition.x << "default y = " << eve.pupilDefaultPosition.y << std::endl
                  << std::endl;
        if ((eve.pupilDefaultPosition.y + limit >= mousePosition.y) && (eve.pupilDefaultPosition.y - limit <= mousePosition.y))
        {
            eve.pupilOfTheEve.setPosition(mousePosition);
            return;
        }
    }
    else
    {
        const sf::Vector2f headOffset = toEuclidean(25, 40, angle);
        eve.pupilOfTheEve.setPosition(eve.pupilDefaultPosition + headOffset);
    }
}

void update(const sf::Vector2f &mousePosition, Eves &eves, const float dt)
{
    const sf::Vector2f deltaLeft = mousePosition - eves.leftEve.pupilOfTheEve.getPosition();
    const sf::Vector2f deltaRight = mousePosition - eves.rightEve.pupilOfTheEve.getPosition();
    const float angleLeft = atan2(deltaLeft.y, deltaLeft.x);
    const float angleRight = atan2(deltaRight.y, deltaRight.x);
    updateEve(eves.leftEve, angleLeft, mousePosition);
    updateEve(eves.rightEve, angleRight, mousePosition);
}

void redrawFrame(sf::RenderWindow &window, Eves &eves)
{
    window.clear();
    window.draw(eves.leftEve.whiteOfTheEve);
    window.draw(eves.leftEve.pupilOfTheEve);
    window.draw(eves.rightEve.whiteOfTheEve);
    window.draw(eves.rightEve.pupilOfTheEve);
    window.display();
}

// Возращает объект глаз
Eve addEve(sf::Vector2f evePosition)
{
    Eve newEve;
    constexpr int pointCount = 200;
    const sf::Vector2f ellipseRadius = {80.f, 160.f};

    sf::ConvexShape whiteOfTheEve;
    whiteOfTheEve.setPosition({evePosition.x, evePosition.y});
    whiteOfTheEve.setFillColor(sf::Color(254, 254, 254));
    whiteOfTheEve.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = sf::Vector2f{
            ellipseRadius.x * std::sin(angle),
            ellipseRadius.y * std::cos(angle)};
        whiteOfTheEve.setPoint(pointNo, point);
    }
    newEve.whiteOfTheEve = whiteOfTheEve;

    const sf::Vector2f ellipseRadiusMin = ellipseRadius * 0.2f;
    sf::ConvexShape pupilOfTheEve;
    pupilOfTheEve.setPosition({evePosition.x, evePosition.y});
    pupilOfTheEve.setFillColor(sf::Color(254, 0, 0));
    pupilOfTheEve.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = sf::Vector2f{
            ellipseRadiusMin.x * std::sin(angle),
            ellipseRadiusMin.y * std::cos(angle)};
        pupilOfTheEve.setPoint(pointNo, point);
    }
    newEve.pupilOfTheEve = pupilOfTheEve;

    newEve.pupilLimiter = ellipseRadius * 0.5f;

    newEve.pupilDefaultPosition = pupilOfTheEve.getPosition();

    return newEve;
}

void init(Eves &eves)
{
    const sf::Vector2f leftEvePosition = {250, 290};
    const sf::Vector2f rightEvePosition = {450, 290};
    eves.leftEve = addEve(leftEvePosition);
    eves.rightEve = addEve(rightEvePosition);
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "eves", sf::Style::Default, settings);
    sf::Clock clock;
    sf::Vector2f mousePosition;

    Eves eves;

    init(eves);

    while (window.isOpen())
    {
        const float dt = clock.restart().asSeconds();
        pollEvents(window, mousePosition);
        update(mousePosition, eves, dt);
        redrawFrame(window, eves);
    }
}
