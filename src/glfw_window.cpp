#include "glfw_window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace {

void debug_callback(GLenum source,
                    GLenum type,
                    GLuint id,
                    GLenum severity,
                    GLsizei length,
                    GLchar const *message,
                    void const *userParam)
{
    fprintf(stderr,
            "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
            (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
            type,
            severity,
            message);
}

} // namespace

namespace glfw {

Window::Window(unsigned int width, unsigned int height, std::string const &title)
{
    if (!glfwInit()) {
        throw "ERROR: Couldn't init glfw";
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!_window) {
        glfwTerminate();
        throw "ERROR: Couldn't create window";
    }

    glfwMakeContextCurrent(_window);

    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        throw "ERROR: Couldn't init glew";
    }

#ifndef NDEBUG
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(debug_callback, nullptr);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
#endif

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
    std::cout << "Status: Using OpenGL " << glGetString(GL_VERSION) << std::endl;
}

Window::~Window()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void Window::run(std::function<void()> callback)
{
    while (!glfwWindowShouldClose(_window)) {
        callback();
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}

} // namespace glfw
