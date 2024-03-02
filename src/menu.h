#ifndef MENU_H_
#define MENU_H_
#include "button.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class Menu
{
private:
  Button* buttons;
  int total;
  static sf::Font font;
  sf::Sprite bg;
  sf::Texture texture;
public:
  Menu(const char**,int);
  void render(sf::RenderWindow&);
  int pollEvent(sf::Event&);
  ~Menu();
};
#endif