#ifndef BUTTON_H_
#define BUTTON_H_
#include <SFML/Graphics.hpp>
#include <string>
class Button
{
private:
  sf::RectangleShape container;
  sf::Text text;
  sf::Font f;
public:
  Button(std::string,const sf::Font&);
  void setBackgroundColor(sf::Color);
  void setForegroundColor(sf::Color);
  void render(sf::RenderWindow&);
  void pollEvent(sf::Event&); // mouse hover events
};
#endif