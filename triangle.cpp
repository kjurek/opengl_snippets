#include <iostream>

#include "common.h"

#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    try {
        create_window(argc, argv);

        glutDisplayFunc([]() {
            glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_TRIANGLES);
            glVertex2f(-0.5f, -0.5f);
            glVertex2f(0, 0.5f);
            glVertex2f(0.5f, -0.5f);
            glEnd();
            glutSwapBuffers();
        });

        glutMainLoop();
    }
    catch(std::string const &e) {
        std::cerr << e << std::endl;
    }
}
