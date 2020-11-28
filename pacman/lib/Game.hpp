#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include "Board.hpp"
#include "GameWindow.hpp"
#include "PacMan.hpp"
#include "Pellets.hpp"
#include "SuperPellets.hpp"

class InputState;

class Game {
public:
  Game();

  void run();

private:
  GameWindow window;
  Board board;
  PacMan pacMan;
  Pellets pellets;
  SuperPellets superPellets;

  static void processEvents(InputState & inputState);

  static void keyToggle(const SDL_Event & event, InputState & inputState, bool on);

  [[nodiscard]] static auto now();
};

#endif //PACMAN_GAME_H
