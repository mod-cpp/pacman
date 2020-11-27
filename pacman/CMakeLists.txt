include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_add_remote(NAME bincrafters INDEX 1 URL https://api.bintray.com/conan/bincrafters/public-conan)

conan_cmake_run(CONANFILE conanfile.py BASIC_SETUP CMAKE_TARGETS BUILD missing)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/pacman/)

find_package(sdl2 REQUIRED)
find_package(sdl2_image REQUIRED)
include_directories(${sdl2_INCLUDE_DIRS} ${sdl2_image_INCLUDE_DIRS})

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/maze.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/sprites32.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)