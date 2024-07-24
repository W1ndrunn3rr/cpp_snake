
#ifndef SNAKE_GAMEOBJECTS_H
#define SNAKE_GAMEOBJECTS_H

#include <vector>
#include "Board.h"
#include "SFML/Graphics.hpp"

//! Enum statusu gry
enum GameState {
    RUNNING,
    LOSS
};

//! Enum kierunków
enum Direction {
    UP,
    LEFT,
    RIGHT,
    DOWN
};

//! Dodatkowy, pomocniczy enum kierunków węża
enum Signpost {
    NORTH,
    SOUTH,
    WEST,
    EAST
};

//! Koordynaty
struct Cords {
    int rowCord, colCord;
};

class GameObjects {
private:
    std::vector<Cords> snake;
    Cords apple{};
    GameState state;
    int row, col, score, scorePoints;
    Direction direction;
    Signpost blinker;
    int height, width;
private:
    //!Metoda sprawdza kolizję i wyjście poza planszę
    bool Collision();

    //!Metoda sprawdza, czy jabłko zostało zjedzone
    void eatApple();

    //!Metoda zarządza ruchem węża
    void move();

    //!Funkcja umieszcza jabłko na tablicy
    void placeApple();
public:
    //!Konstruktor obiektów gry
    explicit GameObjects(Board &board);

    //! Metoda ustawia kierunek poruszania się węża
    void setDirection(Direction direction);

    //!Metoda porusza węża w danym kierunku
    void moveInDirection();

    //!Getter wyniku
    int getScore() const;

    //! Metoda ustawia ilość przyznawanych punktów, w zależności od poziomu trudności
    void setScorePoints(int points);

    //! Getter stanu gry
    GameState getGameState();

    //! Getter wektora reprezentującego węża
    std::vector<Cords> getSnake();

    //!Getter pozycji jabłka
    Cords getApple() const;



};


#endif //SNAKE_GAMEOBJECTS_H
