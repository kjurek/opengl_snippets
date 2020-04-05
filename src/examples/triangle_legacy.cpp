#include <iostream>

#include "glfw_window.h"

#include <GL/glew.h>

int main()
{
    try {
        glfw::Window window(640, 480, "Triangle using legacy OpenGL");

        window.run([]() {
            glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_TRIANGLES);
            glVertex2f(-0.5f, -0.5f);
            glVertex2f(0, 0.5f);
            glVertex2f(0.5f, -0.5f);
            glEnd();
        });

    }
    catch(std::string const &e) {
        std::cerr << e << std::endl;
    }
}
