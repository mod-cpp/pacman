#include "PacMan.hpp"
#include <gtest/gtest.h>

TEST(PacManTest, InitialPosition) {
  pacman::PacMan pacMan;
  EXPECT_EQ(pacMan.position().x, 13.5);
  EXPECT_EQ(pacMan.position().y, 23);
}
