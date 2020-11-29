#include <gtest/gtest.h>

TEST(LcdTest, Initial) {
  EXPECT_EQ(1, 2);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}