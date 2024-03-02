#include "menu.h"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
using namespace std;

sf::Font Menu::font;
Menu::Menu(const char* values[],int totalButtons)
{
    if(!font.loadFromFile("assets/crunch_chips.otf"))
      cout<<"error loading font"<<endl;
    texture.loadFromFile("SF2.jpeg");
    bg.setTexture(texture);
    bg.setScale(1.5,1.1);
    buttons = new Button[totalButtons];
    total = totalButtons;
    int y = 150;
    for(int i=0;i<totalButtons;i++)
    {
        buttons[i].setText(values[i],20,360,y+5);
        buttons[i].setFont(font);
        buttons[i].setBackgroundColor(sf::Color::Black);
        buttons[i].setForegroundColor(sf::Color::White);
        buttons[i].setPosition(350, y);
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
void Menu::pollEvent(sf::Event& ev)
{
  for(int i=0;i<total;i++)
  {
    buttons[i].pollEvent(ev);
  }
}
Menu::~Menu()
{
    delete[] buttons;
}