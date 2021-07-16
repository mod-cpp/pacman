#include "Ghost.hpp"
#include <array>
#include <cmath>

namespace pacman {

GhostAnimation::GhostAnimation(Atlas::Ghost spriteSet)
  : spriteSet(spriteSet) {}

GridPosition GhostAnimation::currentSprite(GhostState state, Direction direction, int timeFrighten) const {
  switch (state) {
    default:
      return Atlas::ghostSprite(spriteSet, direction, (animationIndex % 2) == 0);
    case GhostState::Eyes:
      return Atlas::eyeSprite(direction);
    case GhostState::Frightened:
      if (timeFrighten < 3500)
        return Atlas::initialFrightened(animationIndex);
      else
        return Atlas::endingFrightened(animationIndex);
  }
}

void GhostAnimation::updateAnimation(std::chrono::milliseconds time_delta) {
  timeForAnimation += time_delta.count();
  if (timeForAnimation >= 250) {
    timeForAnimation = 0;
    animationIndex = (animationIndex + 1) % 4;
  }
}

} // namespace pacman
