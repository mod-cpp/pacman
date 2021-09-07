#include "Blinky.hpp"
#include "Clyde.hpp"
#include "Inky.hpp"
#include "Pinky.hpp"
#include <gtest/gtest.h>

template<typename T>
static void ghostInitHelper(const T& ghost, const double x, const double y) {
  const pacman::Position pos{ x, y };
  EXPECT_EQ(ghost.position(), pos);

  const pacman::GridPosition gridPos = pacman::positionToGridPosition(pos);
  EXPECT_EQ(ghost.positionInGrid(), gridPos);

  EXPECT_FALSE(ghost.isEyes());
  EXPECT_FALSE(ghost.isFrightened());
}

TEST(GhostTest, Init) {
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
static void ghostFrightenHelper(T& ghost) {
  EXPECT_FALSE(ghost.isFrightened());
  ghost.frighten();
  EXPECT_TRUE(ghost.isFrightened());
  ghost.reset();
  EXPECT_FALSE(ghost.isFrightened());
}

TEST(GhostTest, Frighten) {
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
  EXPECT_FALSE(ghost.isEyes());
  ghost.die();
  EXPECT_TRUE(ghost.isEyes());
  ghost.reset();
  EXPECT_FALSE(ghost.isEyes());
}

TEST(GhostTest, Dead) {
  pacman::Blinky blinky;
  ghostDeadHelper(blinky);

  pacman::Clyde clyde;
  ghostDeadHelper(clyde);

  pacman::Inky inky;
  ghostDeadHelper(inky);

  pacman::Pinky pinky;
  ghostDeadHelper(pinky);
}
