cmake_minimum_required(VERSION 3.17)

set(VCPKG_CHAINLOAD_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake")

find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if (GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif ()
    endif ()
endif ()

if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/LICENSE.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif ()

#This needs to be set before project()
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")

enable_language(CXX)
project(pacman)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(scaling-lib)
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)
