file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
add_executable(pacman ${sources})
target_link_libraries(pacman libpacman)
