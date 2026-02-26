// rotating_rect.cpp

// To compile write following command in terminal:
// g++ rotating_rect.cpp -o rotating_rect.exe -lsfml-graphics -lsfml-window -lsfml-system


#include <SFML/Graphics.hpp>

int main() {
    const int PW = 800;
    const int PH = 800;
    sf::RenderWindow window(sf::VideoMode({PW, PH}), "Rotating Rectangle Exercise");

    // 1. Create the Rectangle
    float RW = 300.0f;
    float RH = 200.0f;
    sf::RectangleShape rect1({RW, RH});
    
    // 2. Set the Origin to the CENTER of the rectangle (RW/2, RH/2)
    // This is the "pin" around which it will spin.
    rect1.setOrigin({RW / 2.0f, RH / 2.0f});

    // 3. Since the origin is now the center, we set the position 
    // to the center of the screen directly!
    rect1.setPosition({PW / 2.0f, PH / 2.0f});

    rect1.setFillColor(sf::Color::Transparent);
    rect1.setOutlineColor(sf::Color::Blue);
    rect1.setOutlineThickness(2.0f);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // --- Logic: Rotation ---
        // This adds 0.1 degrees to the current rotation every frame
        rect1.rotate(sf::degrees(0.1f)); 

        window.clear(sf::Color::White);
        window.draw(rect1); 
        window.display();
    }

    return 0;
}