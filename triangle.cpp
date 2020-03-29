#include "common.h"

#include "vertex_buffer.h"
#include "index_buffer.h"
#include "vertex_buffer_layout.h"
#include "vertex_array.h"

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    try {
        create_window(argc, argv);

        float triangle[] = {
            -0.5f, -0.5f,
            0.0f, 0.5f,
            0.5f, -0.5f
        };
        unsigned int indicies[] = {0, 1, 2};

        static vertex_array va;
        vertex_buffer vb(triangle, sizeof(triangle));
        vertex_buffer_layout vbl;
        vbl.push<GLfloat>(2);
        va.add_buffer(vb, vbl);

        static index_buffer ib(indicies, sizeof(indicies));

        std::string vertex_shader = read_file("../res/shaders/triangle.vert");
        std::string fragment_shader = read_file("../res/shaders/triangle.frag");

        auto shader = create_shader(vertex_shader, fragment_shader);
        glUseProgram(shader);

        glutDisplayFunc([]() {
            glClear(GL_COLOR_BUFFER_BIT);

            va.bind();
            ib.bind();

            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
            glutSwapBuffers();
        });

        glutMainLoop();
        glDeleteProgram(shader);
    } catch (std::string const& e) {
        std::cerr << e << std::endl;
    }
}
