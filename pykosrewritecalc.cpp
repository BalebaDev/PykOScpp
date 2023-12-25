#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 600), "Calculator");
    window.setFramerateLimit(60);

    sf::RectangleShape background(sf::Vector2f(400, 600));
    background.setFillColor(sf::Color::Yellow);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Error loading font!" << std::endl;
        return -1;
    }

    sf::Text displayText("", font, 50);
    displayText.setFillColor(sf::Color::Black);
    displayText.setPosition(20, 20);

    sf::RectangleShape button(sf::Vector2f(80, 80));
    button.setFillColor(sf::Color::Cyan);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(background);
        window.draw(displayText);

        // Draw buttons and implement functionality

        window.display();
    }

    return 0;
}
