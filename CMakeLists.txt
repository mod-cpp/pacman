if (NOT APPLE AND NOT WIN32)
    set(CMAKE_TOOLCHAIN_FILE toolchains/linux_clang_11.cmake)
endif ()

cmake_minimum_required(VERSION 3.10)
project(modern_cpp C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)

include_directories(include)

add_subdirectory(01_foundation)
add_subdirectory(02_foundation)
add_subdirectory(11_intermediate)