enable_testing()
find_package(Catch2 REQUIRED)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")

add_executable(pacman_tests ${sources})
target_link_libraries(pacman_tests Catch2::Catch2 libpacman)
add_test(NAME pacman_tests COMMAND pacman_tests)
