cmake_minimum_required(VERSION 3.17)

project(deps)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

set(STB_SOURCES stb_image.cpp)
set(IMGUI_SOURCES
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    imgui/examples/imgui_impl_glfw.cpp
    imgui/examples/imgui_impl_opengl3.cpp
)

include_directories(imgui)
add_library(deps ${STB_SOURCES} ${IMGUI_SOURCES})
target_link_libraries(deps ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw)
