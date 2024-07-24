#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H


#include <SFML/Graphics.hpp>
#include "MenuController.h"

class Menu {
public:
    Menu();
    //!Metoda pozwala na wyświetlenie menu
   void drawMenu(sf::RenderWindow &window, char click,char difficultyChoice);
};


#endif //SNAKE_MENU_H
