#include "button.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
using namespace std;
Button::Button()
{
 container.setSize(sf::Vector2f(100,50));
}
Button::Button(std::string txt,const sf::Font& font)
{
  container.setSize(sf::Vector2f(100,50));
  text.setFont(font);
}
void Button::setForegroundColor(sf::Color color)
{
  text.setFillColor(color);
}
void Button::setBackgroundColor(sf::Color color)
{
  container.setFillColor(color);
}
void Button::setPosition(int x,int y)
{
  container.setPosition(x,y);
}
void Button::setFont(sf::Font& f)
{
  text.setFont(f);
}
void Button::setText(const char* str,int size,int x,int y)
{
  text.setString(str);
  text.setCharacterSize(size);
  text.setPosition(x,y);
}
void Button::render(sf::RenderWindow& win)
{
  win.draw(container);
  win.draw(text);
}
bool Button::processMouseMove(int x,int y)
{
  auto bounds = container.getGlobalBounds();
  if(bounds.contains(x,y))
  {
    container.setFillColor(sf::Color::White);
    text.setFillColor(sf::Color::Black);
    return true;
  }
  else 
  {
    container.setFillColor(sf::Color::Black);
    text.setFillColor(sf::Color::White);
    return false;
  }
}