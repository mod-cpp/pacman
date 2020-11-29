#include "lcd.hpp"

lcd_grid lcd(std::string s1,
             std::string s2,
             std::string s3) {
  lcd_grid result;
  result.push_back(s1);
  result.push_back(s2);
  result.push_back(s3);
  return result;
}

const lcd_grid digits[] =
    {
        lcd(" _ ",
            "| |",
            "|_|"
        ),
        lcd("   ",
            "  |",
            "  |"
        ),
        lcd(" _ ",
            " _|",
            "|_ "
        ),
    };

lcd_grid lcd(int value) {
  if (value < 10)
    return digits[value];
  else {
    lcd_grid lhs = lcd(value / 10);
    lcd_grid rhs = digits[value % 10];
    return lcd(
        lhs[0] + ' ' + rhs[0],
        lhs[1] + ' ' + rhs[1],
        lhs[2] + ' ' + rhs[2]);
  }
}
