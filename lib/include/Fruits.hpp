#pragma once
#include <chrono>
#include "Position.hpp"

namespace pacman {

class GameState;
class Fruits {

public:
    void update(std::chrono::milliseconds time_delta, const GameState & gameState);
    GridPosition currentSprite() const;
    Position position() const;
    bool isVisible() const;
    int value() const;
    int eat();

private:
    void hide();
    bool visible = false;
    int  index   = 0;
    std::chrono::milliseconds time_visible{0};
};

} // namespace pacman
