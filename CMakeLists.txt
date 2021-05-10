#This needs to be set before project()
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

cmake_minimum_required(VERSION 3.17)
project(modern_cpp_exercises )

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/maze.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/sprites32.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)
