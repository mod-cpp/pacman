find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-ttf   CONFIG REQUIRED)
find_package(fmt   REQUIRED)
find_package(ZLIB  REQUIRED)



file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")

add_library(libpacman ${sources})

target_include_directories(libpacman PUBLIC .)
target_link_libraries(libpacman PUBLIC SDL2::SDL2-static SDL2::SDL2_image SDL2::SDL2_ttf fmt::fmt ZLIB::ZLIB)
