#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLEW Test");

    GLenum err = glewInit();
    if (GLEW_OK != err) {
        std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
        return 1;
    }
    std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
    std::cout << "Status: Using OpenGL " << glGetString(GL_VERSION) << std::endl;

    float triangle[] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};
    unsigned int buffer = 0;
    glGenBuffers(1, &buffer);
    std::cout << "buffer id: " << buffer << std::endl;

    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    glutDisplayFunc([]() {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glutSwapBuffers();
    });

    glutMainLoop();
}
