cmake_minimum_required(VERSION 3.16)

project(opengl_snippets)

find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(triangle_legacy_opengl triangle_legacy.cpp common.cpp)
target_link_libraries(triangle_legacy_opengl ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(triangle triangle.cpp common.cpp)
target_link_libraries(triangle ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(square square.cpp common.cpp)
target_link_libraries(square ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})

add_executable(triangle_uniform triangle_uniform.cpp common.cpp)
target_link_libraries(triangle_uniform ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
