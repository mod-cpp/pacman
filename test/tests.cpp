#include "PacMan.hpp"
#include <gtest/gtest.h>

TEST(PacManTest, InitialPosition) {
  Board board;
  PacMan pacMan(board);
  EXPECT_EQ(pacMan.position().x, 13.5);
  EXPECT_EQ(pacMan.position().y, 23);
}

int main(int argc, char * argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
