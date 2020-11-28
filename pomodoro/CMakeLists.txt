conan_cmake_run(CONANFILE conanfile.py BASIC_SETUP CMAKE_TARGETS BUILD missing)

file(COPY ${CMAKE_BINARY_DIR}/pomodoro/qt.conf DESTINATION ${CMAKE_BINARY_DIR}/pomodoro/bin/)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)
