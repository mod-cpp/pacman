#This needs to be set before project()
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

cmake_minimum_required(VERSION 3.17)
enable_language(CXX)
project(modern_cpp_exercises )

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)
