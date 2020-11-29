enable_testing()
find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(pomodoro_tests tests.cpp)
target_link_libraries(pomodoro_tests GTest::GTest libpomodoro)

gtest_discover_tests(pomodoro_tests TEST_PREFIX pomodoro:)
add_test(NAME monolithic COMMAND pomodoro_tests)
