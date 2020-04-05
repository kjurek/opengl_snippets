#include <GL/glew.h>
#include <iostream>

#include "glfw_window.h"

int main()
{
    glfw::Window window(640, 480, "Hello world");
    window.run([]() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
    });
}