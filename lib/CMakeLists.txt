find_package(SFML COMPONENTS COMPONENTS window graphics system CONFIG REQUIRED)
find_package(fmt REQUIRED)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")

add_library(libpacman ${sources})

target_include_directories(libpacman PUBLIC .)
target_link_libraries(libpacman PUBLIC fmt::fmt sfml-graphics)
