#include "Blinky.hpp"
#include "Clyde.hpp"
#include "Inky.hpp"
#include "Pinky.hpp"
#include <catch2/catch.hpp>


template<typename T>
static void ghostInitHelper(const T & ghost, double x, double y) {
  const pacman::Position pos{ x, y };
  REQUIRE(ghost.position() == pos);

  const pacman::GridPosition gridPos = pacman::positionToGridPosition(pos);
  REQUIRE(ghost.positionInGrid() == gridPos);

  REQUIRE_FALSE(ghost.isEyes());
  REQUIRE_FALSE(ghost.isFrightened());
}

TEST_CASE("Ghosts start in the correct position", "[ghosts]") {
  pacman::Blinky blinky;
  ghostInitHelper(blinky, 13.5, 11);

  pacman::Clyde clyde;
  ghostInitHelper(clyde, 15.5, 14);

  pacman::Inky inky;
  ghostInitHelper(inky, 13.5, 14);

  pacman::Pinky pinky;
  ghostInitHelper(pinky, 11.5, 14);
}

template<typename T>
static void ghostFrightenHelper(T & ghost) {
  REQUIRE_FALSE(ghost.isFrightened());
  ghost.frighten();
  REQUIRE(ghost.isFrightened());
  ghost.reset();
  REQUIRE_FALSE(ghost.isFrightened());
}

TEST_CASE("Ghosts are frighten", "[ghosts]") {
  pacman::Blinky blinky;
  ghostFrightenHelper(blinky);

  pacman::Clyde clyde;
  ghostFrightenHelper(clyde);

  pacman::Inky inky;
  ghostFrightenHelper(inky);

  pacman::Pinky pinky;
  ghostFrightenHelper(pinky);
}

template<typename T>
static void ghostDeadHelper(T & ghost) {
  REQUIRE_FALSE(ghost.isEyes());
  ghost.die();
  REQUIRE(ghost.isEyes());
  ghost.reset();
  REQUIRE_FALSE(ghost.isEyes());
}

TEST_CASE("Ghosts can die", "[ghosts]") {
  pacman::Blinky blinky;
  ghostDeadHelper(blinky);

  pacman::Clyde clyde;
  ghostDeadHelper(clyde);

  pacman::Inky inky;
  ghostDeadHelper(inky);

  pacman::Pinky pinky;
  ghostDeadHelper(pinky);
}
