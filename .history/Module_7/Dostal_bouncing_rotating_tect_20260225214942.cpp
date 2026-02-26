/*Your program, named bouncing_rotating_rect.cpp, must accomplish the following:

The Shape: Create a rectangle (e.g., 100-by-60 pixels) that is clearly visible against the background.

The Rotation: The rectangle must rotate continuously around its center point (not its top-left corner) as it moves.

The Translation:

    The rectangle must start at the Top-Left (0, 0) of an 800-by-800 window.

    It must move diagonally toward the Bottom-Right corner.

The Infinite Loop:

    Once the rectangle hits the bottom-right boundary, it must reverse direction and move back toward the top-left.

    This back-and-forth movement must continue infinitely.

Termination: The program must close immediately and cleanly when the user clicks the "X" button on the window.

*/
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
    }

    return 0;
}