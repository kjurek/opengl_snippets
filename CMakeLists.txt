cmake_minimum_required(VERSION 3.17)

project(opengl_snippets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(GL_WRAPPER_SOURCES
    src/vertex_buffer.cpp
    src/index_buffer.cpp
    src/vertex_array.cpp
    src/vertex_buffer_layout.cpp
    src/shader.cpp
    src/renderer.cpp
    src/texture.cpp
    src/glfw_window.cpp
    src/imgui_window.cpp
)

add_subdirectory(deps)

include_directories(include)
include_directories(deps)

add_library(gl_wrapper ${GL_WRAPPER_SOURCES})
target_link_libraries(gl_wrapper deps)

add_executable(demo
    src/examples/demo.cpp
    src/examples/background_color_example.cpp
    src/examples/triangle_example.cpp
    src/examples/rectangle_example.cpp
    src/examples/texture_example.cpp
)
target_link_libraries(demo gl_wrapper)
