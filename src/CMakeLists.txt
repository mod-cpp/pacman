file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
add_executable(pacman ${sources})
target_link_libraries(pacman PUBLIC libpacman)

set_target_properties(pacman
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_custom_command(TARGET pacman POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${PROJECT_SOURCE_DIR}/assets/maze.png
        ${PROJECT_SOURCE_DIR}/assets/sprites32.png
        ${PROJECT_SOURCE_DIR}/assets/joystix/joystix.ttf
        $<TARGET_FILE_DIR:pacman>)

#target_compile_options(pacman PRIVATE -fsanitize=address) # /MD will be used implicitly
#target_link_directories(pacman PRIVATE "$ENV{ProgramFiles\(x86\)}/Microsoft Visual Studio/2019/Community/VC/Tools/Llvm/x64/lib/clang/10.0.0/lib/windows")
#target_link_libraries(pacman PRIVATE libpacman clang_rt.asan_dynamic-x86_64 clang_rt.asan_dynamic_runtime_thunk-x86_64)
#target_link_options(pacman PRIVATE /wholearchive:clang_rt.asan_dynamic-x86_64.lib /wholearchive:clang_rt.asan_dynamic_runtime_thunk-x86_64.lib)
