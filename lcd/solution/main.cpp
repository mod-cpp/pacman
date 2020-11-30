#include <iostream>
#include "lcd.hpp"

static const int MAX = 100;

int main() {
  for (int i = 0; i < MAX; i++) {
    auto grid = lcd(i);
    for (const auto & line: grid)
      std::cout << line << "\n";
  }
}
