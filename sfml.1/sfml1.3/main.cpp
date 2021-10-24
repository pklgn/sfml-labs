#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({1300, 900}), "House");

    window.clear(sf::Color::White);

    sf::RectangleShape base;
    base.setSize({1000, 400});
    base.setFillColor(sf::Color::Blue);
    base.setPosition({150, 450});
    window.draw(base);

    sf::ConvexShape roof;
    roof.setFillColor(sf::Color(0xFF, 0, 0xFF));
    roof.setPosition({650, 250});
    roof.setPointCount(4);
    roof.setPoint(0, {-400, 0});
    roof.setPoint(1, {+400, 0});
    roof.setPoint(2, {+650, 250});
    roof.setPoint(3, {-650, 250});
    window.draw(roof);

    sf::RectangleShape door;
    door.setSize({100, 250});
    door.setPosition({300, 600});
    door.setFillColor(sf::Color::Black);
    window.draw(door);

    sf::CircleShape steamSmall;
    steamSmall.setRadius(30);
    steamSmall.setFillColor(sf::Color(0xF0, 0xF0, 0xF0));
    steamSmall.setPosition({830, 100});
    window.draw(steamSmall);

    sf::RectangleShape tubeH;
    tubeH.setSize({100, 50});
    tubeH.setFillColor(sf::Color(0x80, 0x80, 0x80));
    tubeH.setPosition({800, 150});
    window.draw(tubeH);

    sf::RectangleShape tubeV;
    tubeV.setSize({50, 100});
    tubeV.setFillColor(sf::Color(0x80, 0x80, 0x80));
    tubeV.setPosition({825, 200});
    window.draw(tubeV);

    sf::CircleShape steamMedium;
    steamMedium.setRadius(35);
    steamMedium.setFillColor(sf::Color(0xF0, 0xF0, 0xF0));
    steamMedium.setPosition({850, 60});
    window.draw(steamMedium);

    sf::CircleShape steamLarge;
    steamLarge.setRadius(40);
    steamLarge.setFillColor(sf::Color(0xF0, 0xF0, 0xF0));
    steamLarge.setPosition({860, 40});
    window.draw(steamLarge);

    sf::CircleShape steamXLarge;
    steamXLarge.setRadius(45);
    steamXLarge.setFillColor(sf::Color(0xF0, 0xF0, 0xF0));
    steamXLarge.setPosition({880, 10});
    window.draw(steamXLarge);

    sf::CircleShape steamXxLarge;
    steamXxLarge.setRadius(50);
    steamXxLarge.setFillColor(sf::Color(0xF0, 0xF0, 0xF0));
    steamXxLarge.setPosition({870, 0});
    window.draw(steamXxLarge);

    window.display();

    sf::sleep(sf::seconds(2));
}