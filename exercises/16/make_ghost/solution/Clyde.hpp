#pragma once

#include "Ghost.hpp"

namespace pacman {

class Clyde final : public Ghost {
public:
  explicit Clyde();
  void setTarget(Position pacManPos);

protected:
  double speed() const override;
  Position initialPosition() const override;

private:
  Position scatterTarget() const;
};

} // namespace pacman
