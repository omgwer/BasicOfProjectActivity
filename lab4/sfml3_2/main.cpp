#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

struct Eve
{
    sf::ConvexShape whiteOfTheEve;
    sf::ConvexShape pupilOfTheEve;
    sf::ConvexShape pupilLimiter;
};

struct Eves
{
    Eve leftEve;
    //Eve rightEve;
};

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
        default:
            break;
        }
    }
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, const float dt)
{
}

void redrawFrame(sf::RenderWindow &window, Eves &eves)
{
    window.clear();
    window.draw(eves.leftEve.whiteOfTheEve);
    window.draw(eves.leftEve.pupilOfTheEve);
    // window.draw(eves.rightEve.whiteOfTheEve);
    // window.draw(eves.rightEve.pupilOfTheEve);
    window.display();
}

Eve addEve(sf::Vector2f evePosition)
{
    Eve newEve;
    constexpr int pointCount = 200;
    const sf::Vector2f ellipseRadius = {200.f, 80.f};

    sf::ConvexShape shape;
    shape.setPosition({evePosition.x, evePosition.y});
    shape.setFillColor(sf::Color(254, 254, 254));
    shape.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = sf::Vector2f{
            ellipseRadius.x * std::sin(angle),
            ellipseRadius.y * std::cos(angle)};
        shape.setPoint(pointNo, point);
    }

    newEve.whiteOfTheEve = shape;

    const sf::Vector2f ellipseRadiusMin = {200.f, 80.f};
    sf::ConvexShape pupilOfTheEve;
    pupilOfTheEve.setPosition({evePosition.x, evePosition.y});
    pupilOfTheEve.setFillColor(sf::Color(25, 55, 215));
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

    return newEve;
}

void init(Eves &eves)
{
    const sf::Vector2f leftEvePosition = {120, 120};
    const sf::Vector2f rightEvePosition = {280, 120};
    eves.leftEve = addEve(leftEvePosition);
    //eves.rightEve = addEve(rightEvePosition);
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

    sf::Vector2f eveSize = {320.f, 400.f};
    Eves eves;

    init(eves);

    while (window.isOpen())
    {
        const float dt = clock.restart().asSeconds();
        pollEvents(window, mousePosition);
        //update(mousePosition, pointer, dt);
        redrawFrame(window, eves);
    }
}

///
// #include <SFML/Graphics.hpp>
// #include <SFML/Window.hpp>
// #include <SFML/System.hpp>
// #include <cmath>

// constexpr unsigned WINDOW_WIDTH = 800;
// constexpr unsigned WINDOW_HEIGHT = 600;

// int main()
// {
//     constexpr int pointCount = 200;
//     const sf::Vector2f ellipseRadius = {200.f, 80.f};

//     sf::ContextSettings settings;
//     settings.antialiasingLevel = 8;
//     sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Ellipse", sf::Style::Default, settings);

//     sf::ConvexShape shape;
//     shape.setPosition({400, 320});
//     shape.setFillColor(sf::Color(254, 254, 254));

//     shape.setPointCount(pointCount);
//     for (int pointNo = 0; pointNo < pointCount; ++pointNo)
//     {
//         float angle = float(2 * M_PI * pointNo) / float(pointCount);
//         sf::Vector2f point = sf::Vector2f{
//             ellipseRadius.x * std::sin(angle),
//             ellipseRadius.y * std::cos(angle)};
//         shape.setPoint(pointNo, point);
//     }

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//         }

//         window.clear();
//         window.draw(shape);
//         window.display();
//     }
// }
