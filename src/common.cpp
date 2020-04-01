#include "common.h"

#include <iostream>
#include <fstream>

#include <GL/glew.h>
#include <GL/glut.h>

void debug_callback(GLenum source,
                    GLenum type,
                    GLuint id,
                    GLenum severity,
                    GLsizei length,
                    GLchar const* message,
                    void const* userParam)
{
    fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
            ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}

void create_window(int argc, char **argv, unsigned width, unsigned height, std::string const &title)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(title.c_str());
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        throw glewGetErrorString(err);
    }

#ifndef NDEBUG
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(
        debug_callback,
        nullptr);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
#endif

    std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
    std::cout << "Status: Using OpenGL " << glGetString(GL_VERSION) << std::endl;
}

std::string read_file(std::string const &path)
{
    std::ifstream f(path);
    if (!f) {
        throw "Couldn't read file " + path;
    }
    return std::string((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
}
