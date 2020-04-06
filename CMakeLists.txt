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

add_executable(glfw_window src/examples/glfw_window.cpp)
target_link_libraries(glfw_window gl_wrapper)

add_executable(imgui_window src/examples/imgui_window.cpp)
target_link_libraries(imgui_window gl_wrapper)

add_executable(triangle_legacy_opengl src/examples/triangle_legacy.cpp)
target_link_libraries(triangle_legacy_opengl gl_wrapper)

add_executable(triangle src/examples/triangle.cpp)
target_link_libraries(triangle gl_wrapper)

add_executable(square src/examples/square.cpp)
target_link_libraries(square gl_wrapper)

add_executable(triangle_uniform src/examples/triangle_uniform.cpp)
target_link_libraries(triangle_uniform gl_wrapper)

add_executable(triangle_texture src/examples/triangle_texture.cpp)
target_link_libraries(triangle_texture gl_wrapper)

add_executable(square_blend src/examples/square_blend.cpp)
target_link_libraries(square_blend gl_wrapper)

add_executable(square_proj_matrix src/examples/square_proj_matrix.cpp)
target_link_libraries(square_proj_matrix gl_wrapper)

add_executable(rendering_multiple_objects src/examples/rendering_multiple_objects.cpp)
target_link_libraries(rendering_multiple_objects gl_wrapper)
