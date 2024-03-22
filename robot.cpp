#include <SFML/Graphics.hpp>
class Robot {
private:
    sf::CircleShape body;
    sf::RectangleShape arm;
    sf::RectangleShape leg;

public:
    Robot(float x, float y) {
        // Initialize body
        body.setRadius(50);
        body.setFillColor(sf::Color::Blue);
        body.setPosition(x, y);

        // Initialize arm
        arm.setSize(sf::Vector2f(100, 20));
        arm.setFillColor(sf::Color::Red);
        arm.setPosition(x - 70, y + 20);

        // Initialize leg
        leg.setSize(sf::Vector2f(20, 150));
        leg.setFillColor(sf::Color::Green);
        leg.setPosition(x + 20, y + 70);
    }

    void draw(sf::RenderWindow &window) {
        window.draw(body);
        window.draw(arm);
        window.draw(leg);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Robot");

    Robot robot(300, 300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        robot.draw(window);
        window.display();
    }

    return 0;
}