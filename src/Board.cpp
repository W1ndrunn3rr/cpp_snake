#include "../lib/Board.h"

Board::Board() = default;

Board::Board(int h, int w) {
  height = h;
  width = w;
}

int Board::getBoardWidth() const { return width; }

int Board::getBoardHeight() const { return height; }
