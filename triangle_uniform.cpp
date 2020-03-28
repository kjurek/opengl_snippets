#include "common.h"

#include "vertex_buffer.h"
#include "index_buffer.h"

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    try {
        create_window(argc, argv);

        float triangle[] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};

        unsigned int indicies[] = {0, 1, 2};

        unsigned int vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        vertex_buffer vb(triangle, sizeof(triangle));

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        index_buffer ib(indicies, sizeof(indicies));

        std::string vertex_shader = read_file("../res/shaders/triangle.vert");
        std::string fragment_shader = read_file("../res/shaders/triangle_uniform.frag");

        auto shader = create_shader(vertex_shader, fragment_shader);
        glUseProgram(shader);

        static int location;
        location = glGetUniformLocation(shader, "u_color");

        static float r = 0.5f;
        static float increment = 0.05f;

        auto render = []() {
            glClear(GL_COLOR_BUFFER_BIT);
            glUniform4f(location, r, 0, 0, 1.0);
            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
            glutSwapBuffers();

            if (r > 1.0f) {
                increment = -0.05f;
            } else if (r < 0.0f) {
                increment = 0.05f;
            }
            r += increment;
        };

        glutIdleFunc(render);
        glutDisplayFunc(render);

        glutMainLoop();
        glDeleteProgram(shader);
    } catch (std::string const& e) {
        std::cerr << e << std::endl;
    }
}
