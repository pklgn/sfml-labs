#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr int pointCount = 200;
    const sf::Vector2f speed = { 20.f, 20.f };
    int moveNo = 1;
    float moveAngle;
    sf::Clock clock;


    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
            sf::VideoMode({ 800, 600 }), "Ellipse",
            sf::Style::Default, settings);

    sf::ConvexShape rose;
    rose.setPosition({400, 320 });
    rose.setFillColor(sf::Color(0xFF, 0x09, 0x80));

    rose.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        float radius = 200 * std::sin(6 * angle);
        sf::Vector2f point = {
            radius * std::sin(angle),
            radius * std::cos(angle)
        };
        rose.setPoint(pointNo, point);
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
        }
        moveNo++;
        const float deltaTime = clock.restart().asSeconds();
        sf::Vector2f position = rose.getPosition();
        moveAngle = float(2 * M_PI * moveNo) / float(pointCount);
        position.x += speed.x * deltaTime * std::cos(moveAngle);
        position.y += speed.y * deltaTime * std::sin(moveAngle);
        rose.setPosition(position);

        window.clear();
        window.draw(rose);
        window.display();
    }
}
