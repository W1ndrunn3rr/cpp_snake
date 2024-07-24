#include "../lib/MenuController.h"

MenuController::MenuController(sf::Window &window) : window(window) {}

char MenuController::handleMenuEvent(sf::Event &event) {
  if (event.type == sf::Event::MouseButtonReleased) {
    if (checkMenuChoiceButtonPosition() == PLAY) {
      click = 'P';
    }
    if (checkMenuChoiceButtonPosition() == EXIT) {
      if (click == 'M')
        window.close();
    }
  }
  return click;
}

char MenuController::handleLevelEvent(sf::Event &event) {
  if (event.type == sf::Event::MouseButtonPressed) {
    if (checkLevelChoiceButtonPosition() == EASY_LEVEL) {
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (click == 'P')
          difficultyChoice = 'E';
      }
    }

    if (checkLevelChoiceButtonPosition() == NORMAL_LEVEL) {
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (click == 'P')
          difficultyChoice = 'N';
      }
    }

    if (checkLevelChoiceButtonPosition() == HARD_LEVEL) {
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (click == 'P')
          difficultyChoice = 'H';
      }
    }
  }
  return difficultyChoice;
}

int MenuController::getDifficultyChoice() const { return difficultyChoice; }

char MenuController::getClick() const { return click; }

MenuChoice MenuController::checkMenuChoiceButtonPosition() {
  sf::Vector2i position = sf::Mouse::getPosition(window);
  if (position.y > 256 && position.y < 420 && position.x > 137 &&
      position.x < 432)
    return PLAY;
  if (position.y > 479 && position.y < 644 && position.x > 140 &&
      position.x < 433)
    return EXIT;
  return DEFAULT;
}

LevelChoice MenuController::checkLevelChoiceButtonPosition() {
  sf::Vector2i position = sf::Mouse::getPosition(window);
  if (position.y > 278 && position.y < 364 && position.x > 227 &&
      position.x < 673)
    return EASY_LEVEL;
  else if (position.y > 414 && position.y < 499 && position.x > 227 &&
           position.x < 673)
    return NORMAL_LEVEL;
  else if (position.y > 538 && position.y < 625 && position.x > 227 &&
           position.x < 673)
    return HARD_LEVEL;
  return DEFAULT_LEVEL;
}
