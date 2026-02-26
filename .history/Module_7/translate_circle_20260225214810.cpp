// translate_circle.cpp 

// To compile write following command in terminal:
// g++ translate_circle.cpp -o translate_circle.exe -lsfml-graphics -lsfml-window -lsfml-system


#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Controlled Translation");

    // This line is the "Speed Limit"
    window.setFramerateLimit(60); // 60 frames per second (FPS)

    sf::CircleShape circle(40.f);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition({0.f, 0.f});

    // 1.0f means 1 pixel per frame. 
    // At 60 frames per second, the circle moves 60 pixels every second.
    float speed = 1.0f; 

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Logic: Move 1 pixel down and 1 pixel right
        circle.move({speed, speed});

        window.clear();
        window.draw(circle);
        window.display();
    }
    return 0;
}