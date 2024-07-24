#include "../lib/Menu.h"
#include <iostream>

Menu::Menu() = default;

void Menu::drawMenu(sf::RenderWindow &window, char click,
                    char difficultyChoice) {
  sf::Texture texture, gameTexture;
  if ((!texture.loadFromFile("../assets/menu.jpg")) ||
      (!gameTexture.loadFromFile("../assets/texture")))
    exit(1);
  sf::Sprite spriteGame(gameTexture), spriteMenu(texture);

  sf::Font font;
  if (!font.loadFromFile("../assets/font")) {
    std::cerr << "Could not load font\n";
    exit(1);
  }
  sf::Text textPlay, textQuit, levelChoice, textEasy, textNormal, textHard;
  textPlay.setFont(font);
  textPlay.setString("PLAY");
  textPlay.setCharacterSize(100);
  textPlay.setPosition(155, 275);

  textQuit.setFont(font);
  textQuit.setString("QUIT");
  textQuit.setCharacterSize(100);
  textQuit.setPosition(155, 495);

  sf::Vector2i position = sf::Mouse::getPosition(window);

  if (position.y > 256 && position.y < 420 && position.x > 137 &&
      position.x < 432)
    textPlay.setFillColor(sf::Color::Green);

  if (position.y > 479 && position.y < 644 && position.x > 140 &&
      position.x < 433)
    textQuit.setFillColor(sf::Color::Green);

  if (click == 'M') {
    window.draw(spriteMenu);
    window.draw(textPlay);
    window.draw(textQuit);
  }
  if (click == 'P') {

    levelChoice.setFont(font);
    levelChoice.setString("CHOOSE DIFFICULTY");
    levelChoice.setCharacterSize(70);
    levelChoice.setPosition(95, 100);

    textEasy.setFont(font);
    textEasy.setString("EASY");
    textEasy.setCharacterSize(60);
    textEasy.setPosition(375, 284);

    textNormal.setFont(font);
    textNormal.setString("NORMAL");
    textNormal.setCharacterSize(60);
    textNormal.setPosition(315, 417);

    textHard.setFont(font);
    textHard.setString("HARD");
    textHard.setCharacterSize(60);
    textHard.setPosition(360, 540);

    if (position.y > 278 && position.y < 364 && position.x > 227 &&
        position.x < 673)
      textEasy.setFillColor(sf::Color::Green);

    if (position.y > 414 && position.y < 499 && position.x > 227 &&
        position.x < 673)
      textNormal.setFillColor(sf::Color::Yellow);

    if (position.y > 538 && position.y < 625 && position.x > 227 &&
        position.x < 673)
      textHard.setFillColor(sf::Color::Red);

    if (difficultyChoice == 'C') {
      window.draw(spriteGame);
      window.draw(levelChoice);
      window.draw(textEasy);
      window.draw(textNormal);
      window.draw(textHard);
    }

  } else if (click == 'Q') {
    window.close();
  }
}
