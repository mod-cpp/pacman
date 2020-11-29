#pragma once

#include <string>
#include <vector>

typedef std::vector<std::string> lcd_grid;

lcd_grid lcd(int value);

lcd_grid lcd(const std::string & s1,
             const std::string & s2,
             const std::string & s3);
