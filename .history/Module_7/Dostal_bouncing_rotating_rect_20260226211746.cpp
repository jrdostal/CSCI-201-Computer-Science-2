//SECTION - Include the graphics library header to use its functionalities for creating a window and drawing shapes. Also include the optional header for handling events in a more modern way.
// Include the graphics library header
#include <SFML/Graphics.hpp>

//SECTION - Main function where the program execution starts.
int main() {
    //SECTION - Create the window and set its properties (size, title, frame rate limit).
    // Create the window
    const int Window_Width = 800;
    const int Window_Height = 800;
    // Create the window with the specified size and title
    sf::RenderWindow window(sf::VideoMode({Window_Width, Window_Height}), "Bouncing Rotating Rectangle Exercise");
    // Set the frame rate limit to 60 frames per second
    window.setFramerateLimit(60);

    //SECTION - Define the rectangle's width and height.
    float Rectangle_Width = 100.0f;
    float Rectangle_Height = 60.0f;

    //SECTION - Create the rectangle shape. Set its origin to the center, position it at the top-left corner, and give it a fill color and outline.
    // Create the rectangle shape
    sf::RectangleShape rectangle1({Rectangle_Width, Rectangle_Height});
    // Set the origin to the center of the rectangle
    rectangle1.setOrigin({Rectangle_Width / 2.0f, Rectangle_Height / 2.0f});
    // Position the rectangle at the  top-left corner of the window
    rectangle1.setPosition({Rectangle_Width, Rectangle_Height});
    // Set the fill color and outline
    rectangle1.setFillColor(sf::Color::Blue);
    rectangle1.setOutlineColor(sf::Color::Black);
    rectangle1.setOutlineThickness(2.0f);

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
        rectangle1.move({speedX, speedY});

        // SECTION - Rotate the rectangle by 1 degree every frame
        rectangle1.rotate(sf::degrees(1.0f));

        // SECTION - Function to check for collision with the boundaries and reverse direction if necessary
        sf::Vector2f pos = rectangle1.getPosition();

        // get the bounding box of the entity
        sf::FloatRect boundingBox = rectangle1.getGlobalBounds();

        
        //SECTION - Check for collision with the left and right boundaries and reverse direction if necessary.
        if (pos.x - Rectangle_Width < 0 || pos.x + Rectangle_Width > Window_Width) {
            // Reverse X direction
            speedX = -speedX;
        }

        //SECTION - Check for collision with the top and bottom boundaries and reverse direction if necessary.
        if (pos.y - Rectangle_Height < 0 || pos.y + Rectangle_Height > Window_Height) {
            // Reverse Y direction
            speedY = -speedY;
        }

        //SECTION - Clear the window, draw the rectangle, and display the updated frame.
        // Clear the window with a white background
        window.clear(sf::Color::White);
        // Draw the rectangle
        window.draw(rectangle1);
        // Display the updated frame
        window.display();
    }

    //SECTION - End program
    return 0;
}