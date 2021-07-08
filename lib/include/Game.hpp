#pragma once

#include "Canvas.hpp"
#include "GameState.hpp"
#include "InputState.hpp"

namespace pacman {

class Game {
public:
  Game();
  void run();

private:
  Canvas canvas;
  GameState gameState;
  Score score;
  std::chrono::milliseconds timeSinceDeath{};

  void step(std::chrono::milliseconds delta, InputState inputState);
  void eatPellets();
  void processEvents(InputState & inputState);
  void checkCollision(Ghost & ghost);

  [[nodiscard]] static auto now();
};

} // namespace pacman
