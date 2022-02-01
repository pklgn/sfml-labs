#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

const sf::Vector2f startPoint = {400, 300};

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition(startPoint);
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;

    mousePosition = {float(event.x), float(event.y)};
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
                onMouseMove(event.mouseMove, mousePosition);
                break;
            default:
                break;
        }
    }
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, sf::Clock &clock)
{
    const float MAX_ANGLE_SPEED_PER_SECOND = 15.0;
    const float time = clock.getElapsedTime().asSeconds();
    const sf::Vector2f delta = mousePosition - startPoint;
    const float mouseAngle = toDegrees(atan2(delta.y, delta.x));
    const float pointerRotation = pointer.getRotation();
    const float angleDistance = mouseAngle - pointerRotation;
    const float angleAdditionDistance = (-std::abs(angleDistance) / angleDistance) * (360 - std::abs(angleDistance));
    const float minAngle =
            std::min(std::abs(angleAdditionDistance), std::abs(angleDistance)) == std::abs(angleAdditionDistance)
            ? angleAdditionDistance
            : angleDistance;
    const float speed = minAngle / time;
    const float rotationSpeed = speed > 0
                                ? std::min(speed, MAX_ANGLE_SPEED_PER_SECOND)
                                : std::max(speed, -MAX_ANGLE_SPEED_PER_SECOND);
    if (minAngle != 0)
    {
        pointer.setRotation(rotationSpeed * time + pointerRotation);
    }
    clock.restart();
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
    sf::RenderWindow window(
            sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
            "Pointer follows mouse", sf::Style::Default, settings);
    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;
    sf::Clock clock;

    init(pointer);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, clock);
        redrawFrame(window, pointer);
    }
}