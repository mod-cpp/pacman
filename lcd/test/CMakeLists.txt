enable_testing()
find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(lcd_tests lcd_tests.cpp)
target_link_libraries(lcd_tests GTest::GTest liblcd)

gtest_discover_tests(lcd_tests TEST_PREFIX lcd:)
add_test(NAME monolithic COMMAND lcd_tests)