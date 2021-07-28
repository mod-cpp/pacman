#pragma once

#include "Ghost.hpp"

namespace pacman {

class Clyde : public Ghost {
public:
  explicit Clyde();

protected:
  double speed(const GameState & gameState) const override;
  Position target(const GameState & gameState) const override;
  Position initialPosition() const override;

private:
  Position scatterTarget() const;
};

} // namespace pacman
