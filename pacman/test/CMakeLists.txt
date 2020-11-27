enable_testing()
find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(tests tests.cpp)
target_link_libraries(tests GTest::GTest)

gtest_add_tests(TARGET tests TEST_PREFIX old_pacman:)
gtest_discover_tests(tests TEST_PREFIX new_pacman:)
add_test(NAME monolithic COMMAND tests)