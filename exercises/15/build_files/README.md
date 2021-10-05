[< Back](../README.md)

# Exercise: Add files to the build

In this exercise we will add a couple of files to the project.

## Background: CMake

As described in the slides, the project is defined by several CMake files. The ones we are interested
is [`CMakeLists.txt`](../../../CMakeLists.txt) in the root project folder and
the [`CMakeLists.txt`](../../../lib/CMakeLists.txt) file in the `lib` folder.

You can see that the root CMake file is adding the `lib` subdirectory, this means that it is looking for
a `CMakeLists.txt` file within that folder.

The CMake file in the `lib` folder describes a few package requirements and then it does this

```cmake
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp" "*.hpp")
```

Here it is creating a CMake variable called `sources` that will contain all `.cpp` and `.hpp` files within the `lib`
folder. This means that if we want to add new files, we don't have to list them here, as any applicable files are
included. But adding a file will not automatically add the file in the IDE, as CMake needs to be run again for those
changes to apply.

# Exercise

One of the Pac-Man ghosts is missing. We will fully implement this ghost later but for now let's add the `.cpp`
and `.hpp` files to the project.

1. Create a `Clyde.hpp` in the `lib/include` folder and a `Clyde.cpp` file in the `lib` folder.

2. Run CMake again and see your IDE update to include these new files. You can try compiling again and see what happens.

3. Include the `Clyde.hpp` file within the `Clyde.cpp` file, and add `#pragma once` to `Clyde.hpp`.

4. Include `Clyde.hpp` in [GameState.hpp](../../../lib/include/GameState.hpp) and rebuild
