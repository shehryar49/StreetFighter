#ifndef CREDITS_H
#define CREDITS_H

#include <SFML/Graphics.hpp>
#include "button.h"

class Credits {
    sf::RenderWindow& window;
    sf::Font& font;
    sf::Sprite& background;
    sf::Text credits;
    sf::RectangleShape rectangle;
    Button exit_button;

    float scrollSpeed;
    float credits_position;

    void update(float deltaTime);
    void draw();
    int pollEvent(sf::Event&);

public:
    Credits(sf::RenderWindow& window, sf::Font& font, sf::Sprite& background);
    void run();
};

#endif // CREDITS_H
