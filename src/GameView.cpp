#include "../lib/GameView.h"
#include <cstdlib>

GameView::GameView(Board &board, GameObjects &gameObjects, Controller &ctrl,
                   Scoreboard &scoreboard)
    : gameObjects(gameObjects), ctrl(ctrl), scoreboard(scoreboard) {
  height = board.getBoardHeight();
  width = board.getBoardWidth();
  if ((!grass.loadFromFile("../assets/grass.png")) ||
      (!pumpkin.loadFromFile("../assets/pumpkin.png")) ||
      (!seed.loadFromFile("../assets/seed.png")) ||
      (!font.loadFromFile("../assets/font")) ||
      (!map.loadFromFile("../assets/map.jpg")) ||
      (!scoreboardView.loadFromFile("../assets/scoreboard.jpg")))
    exit(1);
  scale = {0.5, 0.5};
}

void GameView::draw(sf::RenderWindow &window) {
  setFont();
  sf::Sprite Map(map), Grass(grass), Pumpkin(pumpkin), Seed(seed);

  window.draw(Map);
  window.draw(score);

  if (ctrl.getPlayButton() == NOT_IN_GAME)
    window.draw(gameBegin);

  window.draw(scoreBoard);

  Grass.setScale(scale.x, scale.y);
  Pumpkin.setScale(scale.x, scale.y);
  Seed.setScale(scale.x, scale.y);

  for (row = 1; row < height - 1; row++) {
    for (col = 1; col < width - 1; col++) {
      seedSize = grassSize = {static_cast<float>(105 + ((col - 1) * 35.2)),
                              static_cast<float>(148 + ((row - 1) * 34.8))};
      pumpkinSize = {
          static_cast<float>(105 + ((col - 1) * 35)),
          static_cast<float>(148 + ((row - 1) * 34.8))}; // wektory rozmiarowe
      Grass.setPosition(grassSize.x, grassSize.y);
      Seed.setPosition(seedSize.x, seedSize.y);
      Pumpkin.setPosition(pumpkinSize.x, pumpkinSize.y);

      if (gameObjects.getApple().rowCord != row ||
          gameObjects.getApple().colCord != col)
        window.draw(Grass);

      for (auto &&element : gameObjects.getSnake())
        if (element.rowCord == row && element.colCord == col)
          window.draw(Pumpkin);

      if (gameObjects.getApple().rowCord == row &&
          gameObjects.getApple().colCord == col)
        window.draw(Seed);
    }
  }

  if (gameObjects.getGameState() == LOSS)
    window.draw(lose);

  if (ctrl.getPlayButton() == SCOREBOARD)
    drawScoreboard(window);
}

void GameView::setFont() {
  score.setFont(font);
  score.setString("SCORE: " + std::to_string(gameObjects.getScore()));
  score.setPosition(70, 60);
  score.setCharacterSize(70);
  score.setFillColor(sf::Color::White);

  scoreBoard.setFont(font);
  scoreBoard.setString("SCOREBOARD");
  scoreBoard.setPosition(530, 75);
  scoreBoard.setCharacterSize(45);
  scoreBoard.setFillColor(sf::Color::White);

  gameBegin.setFont(font);
  gameBegin.setString("PRESS |W| OR |S| TO START");
  gameBegin.setPosition(180, 3);
  gameBegin.setCharacterSize(40);
  gameBegin.setFillColor(sf::Color::White);

  lose.setFont(font);
  lose.setString("YOU LOST :( ");
  lose.setPosition(320, 3);
  lose.setCharacterSize(40);
  lose.setFillColor(sf::Color::Red);
}

void GameView::drawScoreboard(sf::RenderWindow &window) {
  scoreBoardText.setFont(font);
  scoreBoardText.setString(scoreboard.generateString());
  scoreBoardText.setPosition(400, 210);
  scoreBoardText.setCharacterSize(40);
  scoreBoardText.setFillColor(sf::Color::White);

  sf::Sprite scoreBoardSprite(scoreboardView);
  window.draw(scoreBoardSprite);
  window.draw(scoreBoardText);
}
