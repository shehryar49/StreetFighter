#include "credits.h"
#include <iostream>
using namespace std;

Credits::Credits(sf::RenderWindow& window, sf::Font& font, sf::Sprite& background): window(window), font(font), background(background) {
    credits.setFont(font);
    credits.setString("Street Fighter: Our Version\n\n\t\t\t\tCredits\n\t\tShahryar Ahmad\n\t\t\t  21L-7727\n\t\t\tIsbah Malik\n\t\t\t  21L-1843\n\t\t  Maryam Saqib\n\t\t\t  21L-5164\n\t\t\t Usman Ali\n\t\t\t  21L-5404\n\nAll work done for Software\nEngineering Project for 6th\n\t  Semester in Class 6E\n\n\n\n");
    credits.setCharacterSize(30);
    credits.setFillColor(sf::Color::White);
    rectangle.setSize(sf::Vector2f(window.getSize().x - 40, window.getSize().y - 40));
    rectangle.setPosition(20, 20);
    rectangle.setFillColor(sf::Color(0, 0, 0, 150)); //transparent black
    scrollSpeed = 100.f;
    credits_position = window.getSize().y;
    exit_button.setPosition(680, 15);
    exit_button.setFont(font);
    exit_button.setText("Main Menu",20);
    exit_button.setBackgroundColor(sf::Color::Black);
    exit_button.setForegroundColor(sf::Color::White);
}
void Credits::update(float deltaTime) {
    credits_position -= scrollSpeed * deltaTime;
    if (credits_position + credits.getLocalBounds().height < 0) {
        credits_position = window.getSize().y;
    }
    credits.setPosition((window.getSize().x - credits.getLocalBounds().width) / 2, credits_position); //center align
}
void Credits::draw() {
    background.setPosition(0, 0);
    window.clear();
    window.draw(background);
    window.draw(rectangle);
    window.draw(credits);
    exit_button.render(window); //why is the button not printing? i shall nvr know ig
    window.display();
}
void Credits::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else
                if (pollEvent(event))
                    return;
        }
        float deltaTime = clock.restart().asSeconds();
        update(deltaTime);
        draw();
    }
}
int Credits::pollEvent(sf::Event& ev) {
    if (ev.type == sf::Event::MouseMoved)
        exit_button.processMouseMove(ev.mouseMove.x, ev.mouseMove.y);
    else if (ev.type == sf::Event::MouseButtonReleased) {
        bool b = exit_button.processMouseMove(ev.mouseButton.x, ev.mouseButton.y);
        if (b) //if exit button is pressed leave
            return 1;
    }
    return 0;
}
