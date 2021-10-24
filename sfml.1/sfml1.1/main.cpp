#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 300, 900 }), "Traffic light");

    window.clear(sf::Color(0x80, 0x80, 0x80));

    sf::CircleShape redLight(140);
    redLight.setPosition({ 10, 20 });
    redLight.setFillColor(sf::Color::Red);
    window.draw(redLight);

    sf::CircleShape yellowLight(140);
    yellowLight.setPosition({ 10, 320 });
    yellowLight.setFillColor(sf::Color::Yellow);
    window.draw(yellowLight);

    sf::CircleShape greenLight(140);
    greenLight.setPosition({ 10, 620 });
    greenLight.setFillColor(sf::Color::Green);
    window.draw(greenLight);

    window.display();

    sf::sleep(sf::seconds(5));
}