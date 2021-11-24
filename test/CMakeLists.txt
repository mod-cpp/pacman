enable_testing()
find_package(Catch2 REQUIRED)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")

add_executable(pacman_tests ${sources})
target_link_libraries(pacman_tests Catch2::Catch2 libpacman)
target_compile_definitions(pacman_tests PUBLIC CATCH_CONFIG_CONSOLE_WIDTH=300)

# This setup the tests on CI. We disable the AI tests
# because you will have to implement them.
add_test(NAME pacman_tests COMMAND pacman_tests)
