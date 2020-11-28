enable_testing()
find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(tests tests.cpp)
target_link_libraries(tests GTest::GTest libpacman)

gtest_discover_tests(tests TEST_PREFIX pacman:)
add_test(NAME monolithic COMMAND tests)