#include <SFML/Graphics.hpp>
#include <iostream>
#include "djikstra.cpp"

// Define constants for window size, node radius, etc.
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int NODE_RADIUS = 20;

int main()
{
    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Dijkstra's Algorithm Visualization");

    // Main loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Clear the window
        window.clear(sf::Color::White);

        // Draw nodes and edges

        // Update display
        window.display();
    }

    return 0;
}
