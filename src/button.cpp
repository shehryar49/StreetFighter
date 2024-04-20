#include "button.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

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
void Button::setText(const char* str,int size)
{
  text.setString(str);
  text.setCharacterSize(size);
  //centre text
  float textX = container.getPosition().x + (container.getSize().x - text.getLocalBounds().width) / 2.0f;
  float textY = container.getPosition().y + (container.getSize().y - text.getLocalBounds().height) / 2.0f;
  sf::Glyph glyph = text.getFont()->getGlyph('N', size, false);
  float charHeight = glyph.bounds.height;
  textY -= (charHeight / 2.0);
  text.setPosition(textX, textY);
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