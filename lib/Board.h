#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H


#include <vector>
#include<iostream>

//! Klasa reprezentuje planszę - stworzona na potrzeby fizycznej reprezentacji wymiarów , nie robi nic innego, poza przekazaniem
//! wysokości i szerokości
class Board {
    int height{}, width{};
public:
    Board();

    //! Konstruktor planszy, inicjujący wymiary ogólne
    Board(int height, int width);

    //!Getter szerokości
    int getBoardWidth() const;

    //!Getter wysokości
    int getBoardHeight() const;

};

#endif //SNAKE_BOARD_H
