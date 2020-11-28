file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
add_library(libpomodoro  ${sources})
target_link_libraries(libpomodoro Qt5::Core Qt5::Gui Qt5::Widgets)