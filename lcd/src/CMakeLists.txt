file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
add_executable(lcd ${sources})
target_link_libraries(lcd liblcd)

