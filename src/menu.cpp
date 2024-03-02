#include "menu.h"

Menu::Menu(int totalButtons)
{
    buttons = new Button[totalButtons];
}
Menu::~Menu()
{
    delete[] buttons;
}