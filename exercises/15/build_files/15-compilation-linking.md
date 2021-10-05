# Compilation, Linking and Assets

In this exercise we will add a couple of files to the project.

## CMake

As described in the slides, the project is defined by several CMake files. The ones we are interested is `CMakeLists.txt` in the root project folder and the `CMakeLists.txt` file in the `lib` folder.

You can see that the root CMake file is adding the `lib` subdirectory, this means that it is looking for a `CMakeLists.txt` file within that folder.

The CMake file in the `lib` folder describes a few package requirements and then it does this 

```cmake
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp" "*.hpp")
```

Here it is creating a variable called `sources` that will contain all `.cpp` and `.hpp` files within the `lib` folder. This means that if we want to add new files, we don't have to list them here, as any applicable files are included. But adding a file will not automatically add the file in the IDE, as CMake needs to be run again for those changes to apply.

This is because the current configuration and list of files are defined in the CMake and IDE project files inside of your build folder.

# Exercise

One of the Pac-Man ghosts is missing. We will fully implement this ghost later but for now lets add the `.cpp` and `.hpp` files to the project.

1. Create `Blinky.hpp` and `Blinky.cpp` files within the `lib` folder.

2. Run CMake again and see your IDE update to include this new file. You can try compiling again and see what happens.

3. Include the `Blinky.hpp` file within the `Blinky.cpp` file.

4. Create an empty class named `Blinky` within the `.hpp` file. Look at other ghost `.hpp` files and see how they define the class. It does not need to inherit from the `Ghost` base class and it does not need any functions. But if you have extra time, try to inherit from the Ghost class and see what happens when you try to compile.
