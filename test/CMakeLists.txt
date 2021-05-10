enable_testing()
find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(pacman_tests tests.cpp)
target_link_libraries(pacman_tests GTest::GTest libpacman)

gtest_discover_tests(pacman_tests TEST_PREFIX pacman:)
add_test(NAME monolithic COMMAND pacman_tests)
