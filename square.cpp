#include "common.h"

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    try {
        create_window(argc, argv);

        float square[] = {
            -0.5f,
            -0.5f, // 0 indice
            0.5f,
            -0.5f, // 1 indice
            0.5f,
            0.5f, // 2 indice
            -0.5f,
            0.5f, // 3 indice
        };

        unsigned int indicies[] = {0, 1, 2, 3, 2, 0};

        unsigned int buffer;
        glGenBuffers(1, &buffer);
        std::cout << "buffer id: " << buffer << std::endl;
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        unsigned int ibo;
        glGenBuffers(1, &ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

        std::string vertex_shader = read_file("../res/shaders/triangle.vert");
        std::string fragment_shader = read_file("../res/shaders/triangle.frag");

        auto shader = create_shader(vertex_shader, fragment_shader);
        std::cout << "shader program id: " << shader << std::endl;
        glUseProgram(shader);

        glutDisplayFunc([]() {
            glClear(GL_COLOR_BUFFER_BIT);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
            glutSwapBuffers();
        });

        glutMainLoop();
        glDeleteProgram(shader);
    } catch (std::string const& e) {
        std::cerr << e << std::endl;
    }
}
