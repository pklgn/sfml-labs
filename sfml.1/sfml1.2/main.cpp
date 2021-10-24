#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main() {
    const sf::Color letterColor = sf::Color(0x0, 0x0, 0x0);
    const sf::Vector2f verticalSize = {40, 200};
    const sf::Vector2f horizontalSizeSmall = {60, 40};
    const sf::Vector2f horizontalSizeLarge = {100, 40};
    const sf::Vector2f horizontalSizeLargeRotate = {110, 40};
    sf::RenderWindow window(sf::VideoMode({1000, 250}), "My name");

    window.clear(sf::Color::Magenta);

    sf::RectangleShape eV;
    eV.setSize(verticalSize);
    eV.setPosition({10, 10});
    eV.setFillColor(letterColor);
    window.draw(eV);

    sf::RectangleShape eHLarge1;
    eHLarge1.setSize(horizontalSizeLarge);
    eHLarge1.setPosition({50, 10});
    eHLarge1.setFillColor(letterColor);
    window.draw(eHLarge1);

    sf::RectangleShape eHSmall;
    eHSmall.setSize(horizontalSizeSmall);
    eHSmall.setPosition({50, 90});
    eHSmall.setFillColor(letterColor);
    window.draw(eHSmall);

    sf::RectangleShape eHLarge2;
    eHLarge2.setSize(horizontalSizeLarge);
    eHLarge2.setPosition({50, 170});
    eHLarge2.setFillColor((letterColor));
    window.draw(eHLarge2);

    sf::RectangleShape pV1;
    pV1.setSize(verticalSize);
    pV1.setPosition({190, 10});
    pV1.setFillColor(letterColor);
    window.draw(pV1);

    sf::RectangleShape pHSmall;
    pHSmall.setSize(horizontalSizeSmall);
    pHSmall.setPosition({230, 10});
    pHSmall.setFillColor(letterColor);
    window.draw(pHSmall);

    sf::RectangleShape pV2;
    pV2.setSize(verticalSize);
    pV2.setPosition({290, 10});
    pV2.setFillColor(letterColor);
    window.draw(pV2);

    sf::RectangleShape kV;
    kV.setSize(verticalSize);
    kV.setPosition({370, 10});
    kV.setFillColor(letterColor);
    window.draw(kV);

    sf::RectangleShape kA2;
    kA2.setSize(horizontalSizeLargeRotate);
    kA2.rotate(-45);
    kA2.setPosition({380, 90});
    kA2.setFillColor(letterColor);
    window.draw(kA2);

    sf::RectangleShape kA1;
    kA1.setSize(horizontalSizeLargeRotate);
    kA1.rotate(45);
    kA1.setPosition({415, 105});
    kA1.setFillColor(letterColor);
    window.draw(kA1);

    window.display();

    sf::sleep(sf::seconds(10));
}