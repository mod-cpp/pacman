#include "Fruits.hpp"
#include "GameState.hpp"

namespace pacman {

void Fruits::update(std::chrono::milliseconds time_delta, const GameState & gameState) {
    if(visible) {
        time_visible += time_delta;
    }

    if(time_visible > std::chrono::seconds(9)) {
        hide();
    }

    // Two times the same fruit for each level, after 70 and 170 pellets eaten
    else if ((index == 0 && gameState.score.eatenPellets >= 70)
          || (index == 1 && gameState.score.eatenPellets >= 170)) {
        visible = true;
    }
}

GridPosition Fruits::currentSprite() const {
    // That's the cherry
    return {3, 8};
}

Position Fruits::position() const {
    // under the pen
    return {13.5, 17};
}

bool Fruits::isVisible() const {
    return visible;
}

int Fruits::value() const {
    // The cherry is worth 100
    return 100;
}

int Fruits::eat() {
    hide();
    return value();
}

void Fruits::hide() {
    index++;
    time_visible = std::chrono::seconds{0};
    visible = false;
}


}
