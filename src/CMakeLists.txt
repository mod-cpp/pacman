include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_add_remote(NAME bincrafters INDEX 1 URL https://api.bintray.com/conan/bincrafters/public-conan)

conan_cmake_run(CONANFILE ../conanfile.py BASIC_SETUP CMAKE_TARGETS BUILD missing)

find_package(sdl2 REQUIRED)
find_package(sdl2_image REQUIRED)
include_directories(${sdl2_INCLUDE_DIRS} ${sdl2_image_INCLUDE_DIRS})

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} sdl2::sdl2 sdl2_image::sdl2_image)