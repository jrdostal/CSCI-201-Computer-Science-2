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
#include <optional>

int main() {
    //SECTION - Create the window and set its properties (size, title, frame rate limit).
    const int PW = 800;
    const int PH = 800;
    sf::RenderWindow window(sf::VideoMode({PW, PH}), "Bouncing Rotating Rectangle Exercise");
    window.setFramerateLimit(60);

    //SECTION - Define the rectangle's width and height.
    float RW = 100.0f;
    float RH = 60.0f;

    //SECTION - Create the rectangle shape. Set its origin to the center, position it at the top-left corner, and give it a fill color and outline.
    sf::RectangleShape rect1({RW, RH});
    rect1.setOrigin({RW / 2.0f, RH / 2.0f});
    rect1.setPosition({0.0f, 0.0f});
    rect1.setFillColor(sf::Color::Blue);
    rect1.setOutlineColor(sf::Color::Black);
    rect1.setOutlineThickness(2.0f);

    // Initial speed (pixels per frame)
    float speedX = 1.0f;
    float speedY = 1.0f;

    //SECTION - Enter the main loop to handle events, update the rectangle's position and rotation, check for collisions with the window boundaries, and render the rectangle.
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Move the rectangle
        rect1.move({speedX, speedY});

        // Rotate the rectangle by 1 degree every frame
        rect1.rotate(sf::degrees(1.0f));

        // Check for collision with the boundaries
        sf::Vector2f pos = rect1.getPosition();
        
        // Check right and bottom boundaries
        if (pos.x + RW / 2.0f >= PW || pos.y + RH / 2.0f >= PH) {
            speedX = -speedX; // Reverse X direction
            speedY = -speedY; // Reverse Y direction
        }
        
        // Check left and top boundaries
        if (pos.x - RW / 2.0f <= 0 || pos.y - RH / 2.0f <= 0) {
            speedX = -speedX; // Reverse X direction
            speedY = -speedY; // Reverse Y direction
        }

        window.clear(sf::Color::White);
        window.draw(rect1);
        window.display();
    }

    return 0;
}