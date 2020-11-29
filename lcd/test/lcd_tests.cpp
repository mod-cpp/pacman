#include <gtest/gtest.h>

#include "lcd.hpp"
#include <iostream>

std::string to_string(lcd_grid grid) {
  std::stringstream output;
  for (const auto & str: grid)
    output << str;
  return output.str();
}

void lcd_spec(int value, lcd_grid grid) {
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

TEST(LcdTest, Twelve) {
  lcd_spec(12, lcd(
      "     _ ",
      "  |  _|",
      "  | |_ "
  ));
}

int main(int argc, char * argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}