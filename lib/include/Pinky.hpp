#pragma once

#include "Ghost.hpp"

namespace pacman {

class Pinky : public Ghost {
public:
  explicit Pinky();
  [[nodiscard]] double speed(const GameState & gameState) const override;
  [[nodiscard]] Position target(const GameState & gameState) const override;
};

} // namespace pacman