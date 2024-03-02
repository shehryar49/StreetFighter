#include "button.h"
Button::Button()
{

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
void Button::render(sf::RenderWindow& win)
{
  win.draw(container);
  win.draw(text);
}
void Button::pollEvent(sf::Event& e)
{
  if(e.type == sf::Event::MouseMoved)
  {

  }
}