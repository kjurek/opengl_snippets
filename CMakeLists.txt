cmake_minimum_required(VERSION 3.17)

project(opengl_snippets)

find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

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
    src/stb/stb_image.cpp
)

include_directories(include)
include_directories(deps)

add_executable(triangle_legacy_opengl src/examples/triangle_legacy.cpp src/common.cpp)
target_link_libraries(triangle_legacy_opengl ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(triangle src/examples/triangle.cpp src/common.cpp ${GL_WRAPPER_SOURCES})
target_link_libraries(triangle ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(square src/examples/square.cpp src/common.cpp ${GL_WRAPPER_SOURCES})
target_link_libraries(square ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(triangle_uniform src/examples/triangle_uniform.cpp src/common.cpp ${GL_WRAPPER_SOURCES})
target_link_libraries(triangle_uniform ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(triangle_texture src/examples/triangle_texture.cpp src/common.cpp ${GL_WRAPPER_SOURCES})
target_link_libraries(triangle_texture ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(square_blend src/examples/square_blend.cpp src/common.cpp ${GL_WRAPPER_SOURCES})
target_link_libraries(square_blend ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(square_proj_matrix src/examples/square_proj_matrix.cpp src/common.cpp ${GL_WRAPPER_SOURCES})
target_link_libraries(square_proj_matrix ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
