#ifndef SNAKE_MENUCONTROLLER_H
#define SNAKE_MENUCONTROLLER_H

#include "SFML/Graphics.hpp"

//!Pomocniczy enum do pozycji myszki w menu
enum MenuChoice {
    PLAY,
    EXIT,
    DEFAULT
};

//!Pomocniczy enum do pozycji myszki przy wyborze poziomu
enum LevelChoice {
    EASY_LEVEL,
    NORMAL_LEVEL,
    HARD_LEVEL,
    DEFAULT_LEVEL
};

class MenuController {
private:
    sf::Window &window;
    char click = 'M';
    char difficultyChoice = 'C';
private:
    //! Metoda do sprawdzenia pozycji myszy w menu
    MenuChoice checkMenuChoiceButtonPosition();
//! Metoda do sprawdzenia pozycji myszy przy wyborze poziomu
    LevelChoice checkLevelChoiceButtonPosition();

public:
    //! Konstruktor kontrolera menu
    explicit MenuController(sf::Window &window);

    //!Obsługa zdarzeń menu
    char handleMenuEvent(sf::Event &event);

    //!Obsługa wyboru poziomu
    char handleLevelEvent(sf::Event &event);

    //!Getter poziomu trudności
    int getDifficultyChoice() const;

    //! Pomocniczy geter wybranej opcji
    char getClick() const;
};


#endif //SNAKE_MENUCONTROLLER_H
