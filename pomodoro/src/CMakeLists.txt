file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
add_executable(pomodoro ${sources})
target_link_libraries(pomodoro libpomodoro Qt5::Core Qt5::Gui Qt5::Widgets)

