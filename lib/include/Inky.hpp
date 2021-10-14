#pragma once

#include "Ghost.hpp"

namespace pacman {

class Inky final : public Ghost {
public:
  Inky();
  void setTarget(GridPosition pacManPos, Direction pacManDir, GridPosition blinkyPos);

protected:
  double speed() const override;
  Position initialPosition() const override;

private:
  Position scatterTarget() const;
};

} // namespace pacman
