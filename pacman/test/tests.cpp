#include <gtest/gtest.h>
#include "../lib/PacMan.h"

TEST(PacManTest, InitialPosition) {
  PacMan pacMan;
  EXPECT_EQ(pacMan.currentPosition().x, 14);
  EXPECT_EQ(pacMan.currentPosition().y, 23);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}