#include "../lib/GameObjects.h"
#include "random"

//! Generator liczb losowych, do przydzielania jabłka w losowych miejscach na
//! planszy
int generateNumber(int height, int width, int mode) {
  // Generator liczb losowych zapożyczony ze Stack overflow
  if (mode == 1) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> randomRow(
        1, height - 2); // zakres zmniejszony
    return int(randomRow(rng));
  }
  if (mode == 2) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> randomCol(
        1, width - 2);
    return int(randomCol(rng));
  }
  return 0;
}

GameObjects::GameObjects(Board &board) {
  state = RUNNING;
  height = board.getBoardHeight();
  width = board.getBoardWidth();
  row = col = score = scorePoints = 0;
  for (int colNumber = width / 2 - 2; colNumber < width / 2 + 1; colNumber++) {
    snake.push_back({height / 2, colNumber});
  }
  direction = LEFT;
  blinker = EAST;
  placeApple();
}

bool GameObjects::Collision() {
  for (int snakeElement = 1; snakeElement < int(snake.size()); snakeElement++) {
    if ((snake.front().rowCord == snake[snakeElement].rowCord &&
         snake.front().colCord == snake[snakeElement].colCord)) {
      state = LOSS;
      return true;
    }
  }
  if (snake.front().colCord == 0 || snake.front().rowCord == 0 ||
      snake.front().rowCord == height - 1 ||
      snake.front().colCord == width - 1) {
    state = LOSS;
    return true;
  } else {
    state = RUNNING;
    return false;
  }
}

void GameObjects::eatApple() {
  if (snake.front().colCord == apple.colCord &&
      snake.front().rowCord == apple.rowCord) {
    placeApple();
    snake.push_back(snake.back());
    score += scorePoints;
  } else
    return;
}

void GameObjects::move() {
  if (!Collision()) {
    snake.insert(snake.begin(), {height / 2 + row, width / 2 - 2 + col});
    snake.pop_back();
    eatApple();
  }
}

void GameObjects::setDirection(Direction directionSet) {

  if (blinker != NORTH && directionSet == UP) {
    direction = UP;
  } else if (blinker != WEST && directionSet == LEFT) {
    direction = LEFT;
  } else if (blinker != SOUTH && directionSet == DOWN) {
    direction = DOWN;
  } else if (blinker != EAST && directionSet == RIGHT) {
    direction = RIGHT;
  }
}

void GameObjects::moveInDirection() {
  if (direction == UP) {
    row--;
    move();
    blinker = SOUTH;
  }
  if (direction == RIGHT) {
    col++;
    move();
    blinker = WEST;
  }
  if (direction == LEFT) {
    col--;
    move();
    blinker = EAST;
  }
  if (direction == DOWN) {
    row++;
    move();
    blinker = NORTH;
  }
}

int GameObjects::getScore() const { return score; }

GameState GameObjects::getGameState() { return state; }

void GameObjects::setScorePoints(int points) { scorePoints = points; }

std::vector<Cords> GameObjects::getSnake() { return snake; }

void GameObjects::placeApple() {
  apple.rowCord = generateNumber(height, width, 1);
  apple.colCord = generateNumber(height, width, 2);

  for (auto &&element : snake) {
    while (element.rowCord == apple.rowCord &&
           element.colCord == apple.colCord) {
      apple.rowCord = generateNumber(height, width, 1);
      apple.colCord = generateNumber(height, width, 2);
    }
  }
}

Cords GameObjects::getApple() const { return apple; }
