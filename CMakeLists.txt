cmake_minimum_required(VERSION 3.17)

include(FetchContent)
FetchContent_Declare(
    vcpkg
    GIT_REPOSITORY https://github.com/microsoft/vcpkg
    GIT_TAG 1257354a3ab0bebd8abe95281ca561537853578c
)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    FetchContent_GetProperties(vcpkg
        POPULATED vcpkg_POPULATED
        SOURCE_DIR vcpkg_SOURCE_DIR)
    if(NOT vcpkg_POPULATED)
        FetchContent_Populate(vcpkg)
    endif()

    set(CMAKE_TOOLCHAIN_FILE
        "${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake")
    set(VCPKG_CHAINLOAD_TOOLCHAIN_FILE
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain.cmake")
endif()

enable_language(CXX)
project(pacman)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(scaling-lib)
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)
