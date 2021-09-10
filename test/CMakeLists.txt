enable_testing()
find_package(GTest REQUIRED)

include(GoogleTest)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")

add_executable(pacman_tests ${sources})
target_link_libraries(pacman_tests GTest::GTest libpacman)
add_test(NAME pacman_tests COMMAND pacman_tests)

gtest_discover_tests(pacman_tests)
