#include "GameState.hpp"
#include <fmt/format.h>
#include <catch2/catch.hpp>

// TODO: Fuzzing

/*
TEST_CASE("GameStateTest") {
  pacman::GameState gameState;
  //fmt::print("{}\n", gameState.pellets.currentPositions().size());

  int pacManDeathCount = 0;
  bool canCountDeath = false;
  for (std::size_t i = 0; i < 50000; ++i) {
    gameState.inputState.up = i % 7 ? true : false;
    gameState.inputState.down = i % 11 ? true : false;
    gameState.inputState.left = i % 13 ? true : false;
    gameState.inputState.right = i % 17 ? true : false;

    canCountDeath = !gameState.isPacManDying();
    gameState.step(std::chrono::milliseconds(1000 / 30));
    if (canCountDeath && gameState.isPacManDying()) {
      pacManDeathCount++;
    }
  }

  //fmt::print("{}\n", pacManDeathCount);
  //fmt::print("{}\n", gameState.pellets.currentPositions().size());
}
*/
