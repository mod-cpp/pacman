#pragma once

#include "Ghost.hpp"

namespace pacman {

class Inky : public Ghost {
public:
  explicit Inky();
  [[nodiscard]] double speed(const GameState & gameState) const override;
  [[nodiscard]] Position target(const GameState & gameState) const override;
};

} // namespace pacman