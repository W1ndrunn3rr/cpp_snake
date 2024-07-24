#ifndef SNAKE_SCOREBOARD_H
#define SNAKE_SCOREBOARD_H

#include <string>
#include <vector>

class Scoreboard {
    //! Wektor do przechowywania tymczasowego wyników i posortowania
    std::vector<int> highScore;

    //! Metoda sortuje wyniki
    void sortScoreBoard();

//! Metoda ustawia posortowane wyniki, i zapisuje je do pliku
    void setScoreBoard();


    // Scoreboard(const Scoreboard &) = delete;
public :
    //! Konstruktor tablicy wyników
    Scoreboard();

//! Metoda pozwala dodać wyniki do ekranu
    void addToScoreboard(int points);

//! Metoda generuje string potrzebny do wyświetlenia an ekranie wyników
    std::string generateString();

};


#endif //SNAKE_SCOREBOARD_H
