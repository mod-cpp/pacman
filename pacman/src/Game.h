#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include "Board.h"
#include "GameWindow.h"
#include "InputState.h"
#include "PacMan.h"

class Game {
public:
  Game();
  void run();

private:
  GameWindow window;
  PacMan pacMan;
  Board board;

  static void processEvents(InputState & inputState) ;
  static void keyToggle(const SDL_Event & event, InputState & inputState, bool on);
  [[nodiscard]] static auto now() ;
};

#endif //PACMAN_GAME_H
