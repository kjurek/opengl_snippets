cmake_minimum_required(VERSION 3.16)

project(opengl_snippets)

find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(triangle triangle.cpp)
target_link_libraries(triangle ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(triangle_vertex_buffers triangle_vertex_buffers.cpp)
target_link_libraries(triangle_vertex_buffers ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
