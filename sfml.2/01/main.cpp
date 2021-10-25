#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Simple Event Loop");
    sf::Clock clock;

    sf::CircleShape shape(40);
    shape.setPosition({200, 120});
    shape.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        const sf::Vector2f speed = {50.f, 15.f};
        const float deltaTime = clock.restart().asSeconds();
        sf::Vector2f position = shape.getPosition();
        position += speed * deltaTime;
        shape.setPosition(position);
        window.clear();
        window.draw(shape);
        window.display();
    }
}