#pragma once

#include "Ghost.hpp"

namespace pacman {

class Clyde : public Ghost {
public:
  explicit Clyde();
  [[nodiscard]] double speed(const GameState & gameState) const override;
  [[nodiscard]] Position target(const GameState & gameState) const override;
};

} // namespace pacman