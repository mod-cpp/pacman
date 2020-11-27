cmake_minimum_required(VERSION 3.17)
project(pacman)

set(CMAKE_CXX_STANDARD 20)

# Download automatically, you can also just copy the conan.cmake file
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif ()

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/src)
add_subdirectory(src)
