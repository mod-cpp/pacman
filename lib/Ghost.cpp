#include "Ghost.hpp"
#include <array>
#include <cmath>
#include <numeric>

namespace pacman {

GhostAnimation::GhostAnimation(Atlas::Ghost spriteSet)
  : spriteSet(spriteSet) {}

GridPosition GhostAnimation::currentSprite(GhostState state, Direction direction, std::chrono::milliseconds timeFrighten) const {
  switch (state) {
    default:
      return Atlas::ghostSprite(spriteSet, direction, (animationIndex % 2) == 0);
    case GhostState::Eyes:
      return Atlas::eyeSprite(direction);
    case GhostState::Frightened:
      if (timeFrighten.count() < 3500)
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

/*
 *  Ghosts alternate between the scatter and chase states at
 *  specific intervals
 */
GhostState defaultStateAtDuration(std::chrono::seconds s) {
    // This array denotes the duration of each state, alternating between scatter and chase
    std::array changes = { /*scatter*/ 7, 20, 7, 20, 5, 20, 5};
    // To know the current state we first compute the cumulative time using std::partial_sum
    // This gives us {7, 27, 34, 54, 59, 79, 84}
    std::partial_sum(std::begin(changes), std::end(changes), std::begin(changes));
    // Then we look for the first value in the array greater than the time spend in chase/scatter states
    auto it =  std::upper_bound(std::begin(changes), std::end(changes), s.count());
    // We get the position of that iterator in the array
    auto count = std::distance(std::begin(changes), it);
    // Because the first positition is scatter, all the even positions will be scatter
    // all the odd positions will be chase
    return count % 2 == 0 ?  GhostState::Scatter : GhostState::Chase;
}

} // namespace pacman
