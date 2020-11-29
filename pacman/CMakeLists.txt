conan_cmake_run(CONANFILE conanfile.py BASIC_SETUP CMAKE_TARGETS BUILD missing)

find_package(sdl2 REQUIRED)
find_package(sdl2_image REQUIRED)
include_directories(lib ${sdl2_INCLUDE_DIRS} ${sdl2_image_INCLUDE_DIRS})

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/maze.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/sprites32.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)