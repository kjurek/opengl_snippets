cmake_minimum_required(VERSION 3.17)

project(opengl_snippets)

find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(triangle_legacy_opengl triangle_legacy.cpp common.cpp)
target_link_libraries(triangle_legacy_opengl ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(triangle triangle.cpp common.cpp vertex_buffer.cpp index_buffer.cpp vertex_array.cpp vertex_buffer_layout.cpp)
target_link_libraries(triangle ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(square square.cpp common.cpp index_buffer.cpp vertex_buffer.cpp vertex_array.cpp vertex_buffer_layout.cpp)
target_link_libraries(square ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(triangle_uniform triangle_uniform.cpp common.cpp vertex_buffer.cpp index_buffer.cpp vertex_array.cpp vertex_buffer_layout.cpp)
target_link_libraries(triangle_uniform ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
