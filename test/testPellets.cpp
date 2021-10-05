#include "Pellets.hpp"
#include "SuperPellets.hpp"
#include <catch2/catch.hpp>

template<typename T>
static void pelletInitTest(const T & pellets, size_t size, size_t spriteX, size_t spriteY) {
  REQUIRE(pellets.allPellets().size() == size);
  REQUIRE(pellets.currentSprite().x == spriteX);
  REQUIRE(pellets.currentSprite().y == spriteY);
}

TEST_CASE("Pellet initialization", "[pellets]") {
  pacman::Pellets pellets;
  pelletInitTest(pellets, 240, 1, 9);

  pacman::SuperPellets superPellets;
  pelletInitTest(superPellets, 4, 0, 9);
}

template<typename T>
static void pelletEatingTest(T & pellets, size_t countBefore, size_t countAfter, size_t x, size_t y) {
  REQUIRE(pellets.allPellets().size() == countBefore);
  if (countBefore != countAfter) {
    REQUIRE(pellets.eatPelletAtPosition(pacman::GridPosition{ x, y }));
  } else {
    REQUIRE_FALSE(pellets.eatPelletAtPosition(pacman::GridPosition{ x, y }));
  }
  REQUIRE(pellets.allPellets().size() == countAfter);
}

TEST_CASE("Eating pellets", "[pellets]") {
  pacman::Pellets pellets;
  pelletEatingTest(pellets, 240, 240, 0, 0); // wall
  pelletEatingTest(pellets, 240, 239, 1, 1); // pellet
  pelletEatingTest(pellets, 239, 239, 1, 1);
  pelletEatingTest(pellets, 239, 238, 1, 2); // pellet
  pelletEatingTest(pellets, 238, 238, 1, 2);
  pelletEatingTest(pellets, 238, 238, 1, 3); // super pellet

  pacman::SuperPellets superPellets;
  pelletEatingTest(superPellets, 4, 4, 0, 0); // wall
  pelletEatingTest(superPellets, 4, 3, 1, 3); // super pellet
  pelletEatingTest(superPellets, 3, 3, 1, 3);
  pelletEatingTest(superPellets, 3, 3, 2, 1); // pellet
}
