file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
add_library(libpacman ${sources})
target_link_libraries(libpacman sdl2::sdl2 sdl2_image::sdl2_image)
