#compile with warnings
if(WIN32)
    add_compile_options(/W4 /WX)
    set_property(PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

#enable asan in debug
if(WIN32)
    add_compile_options("$<$<CONFIG:DEBUG>:-fsanitize=address>")
else()
    add_compile_options("$<$<CONFIG:DEBUG>:-fsanitize=address>")
    add_link_options("$<$<CONFIG:DEBUG>:-fsanitize=address>")
endif()

#enable ubsan in debug
if(NOT WIN32)
    add_compile_options("$<$<CONFIG:DEBUG>:-fsanitize=undefined>"
                        "$<$<CONFIG:DEBUG>:-fno-omit-frame-pointer>")
    add_link_options("$<$<CONFIG:DEBUG>:-fsanitize=undefined>")
endif()
