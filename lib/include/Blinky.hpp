#pragma once

#include "Ghost.hpp"

namespace pacman {

class Blinky : public Ghost {
public:
  explicit Blinky();
  [[nodiscard]] double speed(const GameState & gameState) const override;
  [[nodiscard]] Position target(const GameState & gameState) const override;
};

} // namespace pacman