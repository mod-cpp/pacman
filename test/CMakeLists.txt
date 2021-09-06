enable_testing()
find_package(GTest REQUIRED)

include(GoogleTest)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")

add_executable(pacman_tests ${sources})
target_link_libraries(pacman_tests GTest::GTest libpacman)

gtest_discover_tests(pacman_tests TEST_PREFIX pacman:)
add_test(NAME monolithic COMMAND pacman_tests)
