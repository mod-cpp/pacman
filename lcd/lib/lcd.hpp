#pragma once

#include <string>
#include <vector>

typedef std::vector<std::string> lcd_grid;

lcd_grid lcd(int value);

lcd_grid lcd(std::string s1,
             std::string s2,
             std::string s3);
