#pragma once

#include "Ghost.hpp"

namespace pacman {

class Pinky final : public Ghost {
public:
  explicit Pinky();
  void setTarget(GridPosition pacManPos, Direction pacManDir);

protected:
  double speed() const override;
  Position initialPosition() const override;

private:
  Position scatterTarget() const;
};

} // namespace pacman
