#include "common.h"

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    try {
        create_window(argc, argv);

        float triangle[] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};
        unsigned int buffer;
        glGenBuffers(1, &buffer);
        std::cout << "buffer id: " << buffer << std::endl;
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), triangle, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        std::string vertex_shader = read_file("../triangle_shader.vert");
        std::string fragment_shader = read_file("../triangle_shader.frag");

        auto shader = create_shader(vertex_shader, fragment_shader);
        std::cout << "shader program id: " << shader << std::endl;
        glUseProgram(shader);

        glutDisplayFunc([]() {
            glClear(GL_COLOR_BUFFER_BIT);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glutSwapBuffers();
        });

        glutMainLoop();
    } catch (std::string const& e) {
        std::cerr << e << std::endl;
    }
}
