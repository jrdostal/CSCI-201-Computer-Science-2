//SECTION - Include the graphics library header to use its functionalities for creating a window and drawing shapes. Also include the optional header for handling events in a more modern way.
// Include the graphics library header
#include <SFML/Graphics.hpp>
// Include the optional header for handling events
#include <string>

//SECTION - Main function where the program execution starts.
int main() {
    //SECTION - Create the window and set its properties (size, title, frame rate limit).
    // Create the window
    const int PW = 800;
    const int PH = 800;
    // Create the window with the specified size and title
    sf::RenderWindow window(sf::VideoMode({PW, PH}), "Bouncing Rotating Rectangle Exercise");
    // Set the frame rate limit to 60 frames per second
    window.setFramerateLimit(60);

    //SECTION - Define the rectangle's width and height.
    float RW = 100.0f;
    float RH = 60.0f;

    //SECTION - Create the rectangle shape. Set its origin to the center, position it at the top-left corner, and give it a fill color and outline.
    // Create the rectangle shape
    sf::RectangleShape rect1({RW, RH});
    // Set the origin to the center of the rectangle
    rect1.setOrigin({RW / 2.0f, RH / 2.0f});
    // Position the rectangle at the top-left corner (0, 0)
    rect1.setPosition({0.0f, 0.0f});
    // Set the fill color and outline
    rect1.setFillColor(sf::Color::Blue);
    rect1.setOutlineColor(sf::Color::Black);
    rect1.setOutlineThickness(2.0f);

    // Initial speed (pixels per frame)
    float speedX = 1.0f;
    float speedY = 1.0f;

    //SECTION - Enter the main loop to handle events, update the rectangle's position and rotation, check for collisions with the window boundaries, and render the rectangle.
    while (window.isOpen()) {
        // SECTION - Loop to Handle events
        while (const std::optional event = window.pollEvent()) {
            //SECTION - Check for the "Closed" event and close the window if it occurs.
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // SECTION - Move the rectangle
        rect1.move({speedX, speedY});

        // SECTION - Rotate the rectangle by 1 degree every frame
        rect1.rotate(sf::degrees(1.0f));

        // SECTION - Function to check for collision with the boundaries and reverse direction if necessary
        sf::Vector2f pos = rect1.getPosition();
        
        //SECTION - Check for collision with the right and bottom boundaries and reverse direction if necessary.
        // Check right and bottom boundaries
        if (pos.x + RW / 2.0f >= PW || pos.y + RH / 2.0f >= PH) {
            // Reverse X direction
            speedX = -speedX;
            // Reverse Y direction
            speedY = -speedY;
        }
        
        //SECTION - Check for collision with the left and top boundaries and reverse direction if necessary.
        // Check left and top boundaries
        if (pos.x - RW / 2.0f <= 0 || pos.y - RH / 2.0f <= 0) {
            // Reverse X direction
            speedX = -speedX;
            // Reverse Y direction
            speedY = -speedY;
        }

        //SECTION - Clear the window, draw the rectangle, and display the updated frame.
        // Clear the window with a white background
        window.clear(sf::Color::White);
        // Draw the rectangle
        window.draw(rect1);
        // Display the updated frame
        window.display();
    }

    //SECTION - End program
    return 0;
}