#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "MenuController.h"
#include "Scoreboard.h"
#include "GameObjects.h"

//! Enum do lokalizacji ekranu
enum PlayButton {
    NOT_IN_GAME,
    IN_GAME,
    SCOREBOARD
};

//! Enum trudności gry
enum GameMode {
    EASY,
    NORMAL,
    HARD
};

//! Enum pomocniczy do sprawdzania lokalizacji kursora
enum ScoreboardButton {
    IN_GAME_SCOREBOARD_BUTTON,
    SCOREBOARD_EXIT_BUTTON,
    DEFAULT_BUTTON
};


class Controller {

    GameObjects &gameObjects;
    Scoreboard &scoreboard;
    sf::RenderWindow &window;

    //! Sprawdzenie pozycji kursora myszy przycisku tablicy wyników
    ScoreboardButton checkScoreBoardButtonPosition();
private:
    PlayButton button;
    sf::Time seconds;
    GameMode mode;
    bool fileSaved;
public :
    //! Konstruktor inicjujący kontroler
    Controller(GameObjects &gameObjects, MenuController &menuController, sf::RenderWindow &window,
               Scoreboard &scoreboard);

    //!Metoda kontrolująca rozgrywkę
    void play(sf::Event &event);

    //!Getter przycisku stanu gry
    PlayButton getPlayButton() const;
};


#endif //SNAKE_CONTROLLER_H
