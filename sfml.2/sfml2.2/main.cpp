#include <cmath>
#include <SFML/Graphics.hpp>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main() {
    constexpr float BALL_SIZE = 40;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Wave Moving Ball");
    sf::Clock clockX;
    sf::Clock clockY;
    float time;
    float edgeTime;
    int backwardX = 0;
    float deltaX;
    sf::Vector2f currPosition;
    const sf::Vector2f position = {10, 350};

    sf::CircleShape ball(BALL_SIZE);
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0x00));
    constexpr float speedX = 100.f;
    constexpr float amplitudeY = 80.f;
    constexpr float periodY = 2;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        const float wavePhase = clockY.getElapsedTime().asSeconds() * float(2 * M_PI);
        const float y = amplitudeY * std::sin(wavePhase / periodY);
        if (backwardX) {
            deltaX = clockX.getElapsedTime().asSeconds() - edgeTime;
            time = edgeTime - deltaX;
        } else {
            time = clockX.getElapsedTime().asSeconds();
        }
        const float x = (speedX * time);
        currPosition = ball.getPosition();
        if (currPosition.x + 2 * BALL_SIZE >= WINDOW_WIDTH) {
            edgeTime = time;
            backwardX = 1;
        }
        if (currPosition.x <= 0) {
            clockX.restart();
            backwardX = 0;
        }
        const sf::Vector2f offset = {x, y};
        ball.setPosition(position + offset);

        window.clear();
        window.draw(ball);
        window.display();
    }
}