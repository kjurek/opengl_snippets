#include "common.h"

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
        unsigned int buffer;
        glGenBuffers(1, &buffer);
        std::cout << "buffer id: " << buffer << std::endl;
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        std::string vertex_shader = read_file("../res/shaders/triangle.vert");
        std::string fragment_shader = read_file("../res/shaders/triangle_uniform.frag");

        auto shader = create_shader(vertex_shader, fragment_shader);
        std::cout << "shader program id: " << shader << std::endl;
        glUseProgram(shader);

        static int location;
        location = glGetUniformLocation(shader, "u_color");

        static float r = 0.0f;
        static float increment = 0.05f;

        auto render = []() {
            glClear(GL_COLOR_BUFFER_BIT);
            glUniform4f(location, r, 0, 0, 1.0);
            glDrawArrays(GL_TRIANGLES, 0, 3);
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
