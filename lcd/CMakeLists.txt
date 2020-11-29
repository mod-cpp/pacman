conan_cmake_run(CONANFILE conanfile.py BASIC_SETUP CMAKE_TARGETS BUILD missing)

include_directories(lib)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)
