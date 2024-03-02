#ifndef MENU_H_
#define MENU_H_
#include "button.h"

class Menu
{
private:
  Button* buttons;
  
public:
  Menu(int);
  ~Menu();
};
#endif