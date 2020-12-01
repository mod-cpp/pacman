file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
add_library(libpacman ${sources})
target_link_libraries(libpacman sdl2::sdl2 sdl2_image::sdl2_image)

#target_compile_options(libpacman PRIVATE -fsanitize=address) # /MD will be used implicitly
#target_link_directories(libpacman PRIVATE "$ENV{ProgramFiles\(x86\)}/Microsoft Visual Studio/2019/Community/VC/Tools/Llvm/x64/lib/clang/10.0.0/lib/windows")
#target_link_libraries(libpacman PRIVATE sdl2::sdl2 sdl2_image::sdl2_image clang_rt.asan_dynamic-x86_64 clang_rt.asan_dynamic_runtime_thunk-x86_64)
#target_link_options(libpacman PRIVATE /wholearchive:clang_rt.asan_dynamic_runtime_thunk-x86_64.lib /wholearchive:clang_rt.asan_dynamic-x86_64.lib)
