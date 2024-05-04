#include "menu.h"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
using namespace std;

sf::Font Menu::font;
Menu::Menu(const char* values[],int totalButtons)
{
    if(!font.loadFromFile("assets/fonts/crunch_chips.otf"))
      cout<<"error loading font"<<endl;
    texture.loadFromFile("SF2.jpeg");
    bg.setTexture(texture);
    bg.setScale(1.5,1.1);
    buttons = new Button[totalButtons];
    total = totalButtons;
    int y = 150;
    for(int i=0;i<totalButtons;i++)
    {
        //keep this order pos, font, text
        // why tho?
        // logic to centralize the text goes haywire otherwise
        buttons[i].setPosition(350, y);
        buttons[i].setFont(font);
        buttons[i].setText(values[i],20);
        buttons[i].setBackgroundColor(sf::Color::Black);
        buttons[i].setForegroundColor(sf::Color::White);
        y += 80;
    }
}
void Menu::render(sf::RenderWindow& win)
{
    win.draw(bg);
    for(int i=0;i<total;i++)
    {
      buttons[i].render(win);
    }
}
int Menu::pollEvent(sf::Event& ev)
{
  if(ev.type == sf::Event::MouseMoved)
  {
    for(int i=0;i<total;i++)
      buttons[i].processMouseMove(ev.mouseMove.x,ev.mouseMove.y);
  }
  else if(ev.type == sf::Event::MouseButtonReleased)
  {

    for(int i=0;i<total;i++)
    {
        bool b = buttons[i].processMouseMove(ev.mouseButton.x,ev.mouseButton.y);
        if(b) // button i clicked
          return i;
    }
  }
  return -1;
}
Menu::~Menu()
{
    delete[] buttons;
}