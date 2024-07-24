#include "../lib/Controller.h"

Controller::Controller(GameObjects &gameObjects, MenuController &menuController,
                       sf::RenderWindow &window, Scoreboard &scoreboard)
    : gameObjects(gameObjects), scoreboard(scoreboard), window(window) {
  button = NOT_IN_GAME;
  fileSaved = false;
  if (menuController.getDifficultyChoice() == 'E') {
    mode = EASY;
    gameObjects.setScorePoints(1);
  }
  if (menuController.getDifficultyChoice() == 'N') {
    mode = NORMAL;
    gameObjects.setScorePoints(2);
  }
  if (menuController.getDifficultyChoice() == 'H') {
    mode = HARD;
    gameObjects.setScorePoints(3);
  }
}

void Controller::play(sf::Event &event) {
  if (mode == EASY)
    seconds = sf::seconds(0.15f);
  if (mode == NORMAL)
    seconds = sf::seconds(0.1f);
  if (mode == HARD)
    seconds = sf::seconds(0.05f);
  if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::S)) &&
      gameObjects.getGameState() == RUNNING)
    button = IN_GAME;
  if (button == IN_GAME) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      gameObjects.setDirection(UP);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      gameObjects.setDirection(LEFT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      gameObjects.setDirection(DOWN);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      gameObjects.setDirection(RIGHT);
    }

    // Odmierzanie czasu napisane przy pomocy Chatu GPT
    static sf::Clock clock;
    static sf::Time elapsed = sf::Time::Zero;

    if (elapsed == sf::Time::Zero) {
      elapsed = clock.getElapsedTime();
    }
    sf::Time delta = clock.getElapsedTime() - elapsed;
    if (delta >= seconds) {
      gameObjects.moveInDirection();
      elapsed = clock.getElapsedTime();
    }
  }
  if (gameObjects.getGameState() == LOSS) {
    if (!fileSaved) {
      scoreboard.addToScoreboard(gameObjects.getScore());
      fileSaved = true;
    }
    if (event.type == sf::Event::MouseButtonPressed) {
      if (button != SCOREBOARD &&
          checkScoreBoardButtonPosition() == IN_GAME_SCOREBOARD_BUTTON &&
          event.mouseButton.button == sf::Mouse::Left) {
        button = SCOREBOARD;
      }

      if (event.mouseButton.button == sf::Mouse::Left &&
          checkScoreBoardButtonPosition() == SCOREBOARD_EXIT_BUTTON) {
        window.close();
      }
    }
  }
}

PlayButton Controller::getPlayButton() const { return button; }

ScoreboardButton Controller::checkScoreBoardButtonPosition() {
  sf::Vector2i position = sf::Mouse::getPosition(window);
  if (position.x > 520 && position.x < 850 && position.y > 65 &&
      position.y < 145)
    return IN_GAME_SCOREBOARD_BUTTON;
  else if (position.x > 380 && position.x < 521 && position.y > 769 &&
           position.y < 844)
    return SCOREBOARD_EXIT_BUTTON;
  return DEFAULT_BUTTON;
}
