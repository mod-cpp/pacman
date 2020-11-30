#include <gtest/gtest.h>

#include "lcd.hpp"
#include <iostream>

std::string to_string(const lcd_grid & grid) {
  std::stringstream output;
  for (const auto & str: grid)
    output << str;
  return output.str();
}

void lcd_spec(int value, const lcd_grid & grid) {
  std::string expected = to_string(grid),
      actual = to_string(lcd(value));
  if (expected != actual) {
    std::cerr
        << "lcd(" << value << ")\n"
        << "expected==\n"
        << expected << '\n'
        << "actual==\n"
        << actual << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

TEST(LcdTest, Zero) {
  lcd_spec(0, lcd(
      " _ ",
      "| |",
      "|_|"
  ));
}

TEST(LcdTest, One) {
  lcd_spec(1, lcd(
      "   ",
      "  |",
      "  |"
  ));
}

TEST(LcdTest, Two) {
  lcd_spec(2, lcd(
      " _ ",
      " _|",
      "|_ "
  ));
}

TEST(LcdTest, Three) {
  lcd_spec(3, lcd(
      " _ ",
      " _|",
      " _|"
  ));
}

TEST(LcdTest, Four) {
  lcd_spec(4, lcd(
      "   ",
      "|_|",
      "  |"
  ));
}

TEST(LcdTest, Twelve) {
  lcd_spec(12, lcd(
      "     _ ",
      "  |  _|",
      "  | |_ "
  ));
}

TEST(LcdTest, TwentyFive) {
  lcd_spec(25, lcd(
      " _   _ ",
      " _| |_ ",
      "|_   _|"
  ));
}

TEST(LcdTest, SixtyFour) {
  lcd_spec(64, lcd(
      " _     ",
      "|_  |_|",
      "|_|   |"
  ));
}

TEST(LcdTest, SeventyFour) {
  lcd_spec(74, lcd(
      " _     ",
      "  | |_|",
      "  |   |"
  ));
}

TEST(LcdTest, EightyNine) {
  lcd_spec(89, lcd(
      " _   _ ",
      "|_| |_|",
      "|_|   |"
  ));
}

int main(int argc, char * argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
