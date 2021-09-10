#include "Position.hpp"
#include <gtest/gtest.h>

TEST(PositionTest, PositionInit) {
  pacman::Position pos;
  EXPECT_DOUBLE_EQ(pos.x, 0.0);
  EXPECT_DOUBLE_EQ(pos.y, 0.0);

  pacman::Position pos2{ 10.0, 20.0 };
  EXPECT_DOUBLE_EQ(pos2.x, 10.0);
  EXPECT_DOUBLE_EQ(pos2.y, 20.0);
}

TEST(PositionTest, GridPositionInit) {
  pacman::GridPosition gridPos{ 10, 20 };
  EXPECT_EQ(gridPos.x, 10);
  EXPECT_EQ(gridPos.y, 20);
}

TEST(PositionTest, ConvertPositionToGridPosition) {
  pacman::Position pos{ 10.0, 20.0 };
  const auto gridPos = pacman::positionToGridPosition(pos);
  EXPECT_EQ(gridPos.x, 10);
  EXPECT_EQ(gridPos.y, 20);
}

TEST(PositionTest, ConvertGridPositionToPosition) {
  pacman::GridPosition gridPos{ 10, 20 };
  const auto pos = pacman::gridPositionToPosition(gridPos);
  EXPECT_DOUBLE_EQ(pos.x, 10.0);
  EXPECT_DOUBLE_EQ(pos.y, 20.0);
}

TEST(PositionTest, PositionEquality) {
  pacman::Position pos1{ 10.0, 20.0 };
  pacman::Position pos2{ 10.0, 20.0 };
  EXPECT_TRUE(pos1 == pos2);

  pacman::Position pos3{ 9.9, 19.9 };
  EXPECT_FALSE(pos1 == pos3);

  pos3.x += 0.1;
  pos3.y += 0.1;

  EXPECT_TRUE(pos1 == pos3);
}
