file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
add_library(liblcd ${sources})
target_link_libraries(liblcd)