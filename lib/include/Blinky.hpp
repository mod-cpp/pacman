#pragma once

#include "Ghost.hpp"

namespace pacman {

class Blinky final : public Ghost {
public:
  Blinky();
  void setTarget(Position pacManPos);

protected:
  double speed() const override;
  Position initialPosition() const override;

private:
  Position scatterTarget() const;
};

} // namespace pacman
