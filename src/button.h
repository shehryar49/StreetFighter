#ifndef BUTTON_H_
#define BUTTON_H_
#include <SFML/Graphics.hpp>
#include <string>
class Button
{
private:
  sf::RectangleShape container;
  sf::Text text;
public:
  Button();
  Button(std::string,const sf::Font&);
  void setBackgroundColor(sf::Color);
  void setForegroundColor(sf::Color);
  void setPosition(int,int);
  void setText(const char*,int,int,int);
  void setFont(sf::Font&);
  void render(sf::RenderWindow&);
  bool processMouseMove(int,int); // mouse hover events
};
#endif