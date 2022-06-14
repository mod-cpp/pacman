[< Back](README.md)

# 12. Hello World

* [Exercise 120](#exercise-120)
* [Exercise 121](#exercise-121)
* [Exercise 122](#exercise-122)

## Exercise 120

### Hello std::cout on Godbolt.org

Compiler Explorer is a website where you can experiment with many different C++
compilers. You can compile short C++ programs, run them and inspect their assembly.

Today, we will use it to compile and run a Hello World program.

1. Play with Hello World on [Compiler Explorer][2].
2. You can save the file on Godbolt locally by pressing ctrl+S when you are on the web
   page

```cpp
#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}
```

## Exercise 121

### Hello {fmt} on Godbolt

"{fmt} is an open-source formatting library providing a fast and safe alternative to C
stdio and C++ iostreams."
[From the {fmt} GitHub page][4]

In C++20 we are getting parts of this functionality in [std::format][5].

In C++23 we might get `std::print`.

1. Play with Hello World on [Godbolt][3]
2. You can save the file on Godbolt locally by pressing ctrl+S when you are on the web
   page

```cpp
#include <fmt/format.h>

int main () {
    fmt::print("Hello {}", "World");
}
```

## [Exercise 122][1]

### Description

<details>
   <summary>Solution</summary>

```cpp

```

</details>

[1]: 12_exercises.cpp
[2]: https://godbolt.org/z/bceh7693T
[3]: https://godbolt.org/z/8oxsGG8WM
[4]: https://github.com/fmtlib/fmt
[5]: https://en.cppreference.com/w/cpp/utility/format
