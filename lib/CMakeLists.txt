find_package(sdl2-image CONFIG REQUIRED)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
add_library(libpacman ${sources})

target_include_directories(libpacman PUBLIC .)
target_link_libraries(libpacman PUBLIC SDL2::SDL2-static SDL2::SDL2_image)
