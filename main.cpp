#include "lib/Board.h"
#include "lib/Controller.h"
#include "lib/GameObjects.h"
#include "lib/GameView.h"
#include "lib/Menu.h"
#include "lib/MenuController.h"

int main() {
  sf::Event event{};
  sf::RenderWindow window(sf::VideoMode(900, 900), "Snake",
                          sf::Style::Titlebar);
  window.setPosition({650, 100});
  window.setFramerateLimit(30);
  window.setVerticalSyncEnabled(false);
  MenuController menuController(window);
  Menu menu;
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    if (menuController.getDifficultyChoice() == 'C') {
      menu.drawMenu(window, menuController.handleMenuEvent(event),
                    menuController.handleLevelEvent(event));
    } else {
      window.close();
    }

    window.display();
  }

  if (menuController.getClick() == 'P') {
    Board board(22, 22);
    sf::RenderWindow newWindow(sf::VideoMode(900, 900), "SNAKE",
                               sf::Style::Titlebar);
    GameObjects objects(board);
    Scoreboard scoreboard;
    Controller controller(objects, menuController, newWindow, scoreboard);
    GameView view(board, objects, controller, scoreboard);
    newWindow.setPosition({650, 100});
    newWindow.setFramerateLimit(30);
    newWindow.setVerticalSyncEnabled(false);
    while (newWindow.isOpen()) {
      while (newWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          newWindow.close();
      }
      newWindow.clear();
      view.draw(newWindow);
      newWindow.display();
      controller.play(event);
    }
  }
  return 0;
}
