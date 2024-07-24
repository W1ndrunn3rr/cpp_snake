#ifndef SNAKE_GAMEVIEW_H
#define SNAKE_GAMEVIEW_H

#include "Board.h"
#include "Menu.h"
#include "GameObjects.h"
#include "MenuController.h"
#include "Controller.h"

//! Pomocnicza struktura do wektora rozmiarów
struct Size{
    float x, y;
};

class GameView {
private:
    GameObjects &gameObjects;
    Controller &ctrl;
    Scoreboard &scoreboard;

    //!Metoda ustawia czcionki napisów
    void setFont();

    //! Metoda do rysowania tablicy wyników
    void drawScoreboard(sf::RenderWindow &window);
private:
    int height, width;
    sf::Texture map,grass,pumpkin,seed,scoreboardView;
    sf::Font font;
    sf::Text score,scoreBoardText,scoreBoard,gameBegin,lose;
    int row{},col{};
    Size scale{},grassSize{},seedSize{},pumpkinSize{};

public:
    //! Konstruktor widoku gry
    GameView(Board& board,GameObjects &gameObjects, Controller &ctrl,Scoreboard &scoreboard);
    //! Metoda do rysowania gry za pomocą SFML
    void draw(sf::RenderWindow& window);
};


#endif //SNAKE_GAMEVIEW_H
