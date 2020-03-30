#include "common.h"

#include "vertex_buffer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "shader.h"

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    try {
        create_window(argc, argv);

        float square[] = {
            -0.5f,
            -0.5f,
            0.5f,
            -0.5f,
            0.5f,
            0.5f,
            -0.5f,
            0.5f,
        };

        unsigned int indicies[] = {0, 1, 2, 3, 2, 0};

        static VertexArray va;
        VertexBuffer vb(square, sizeof(square));
        VertexBufferLayout vbl;
        vbl.push<GLfloat>(2);
        va.add_buffer(vb, vbl);

        static IndexBuffer ib(indicies, sizeof(indicies));
        static Shader shader("../res/shaders/triangle.vert", "../res/shaders/triangle.frag");

        va.unbind();
        shader.unbind();
        vb.unbind();
        ib.unbind();

        glutDisplayFunc([]() {
            glClear(GL_COLOR_BUFFER_BIT);

            va.bind();
            ib.bind();
            shader.bind();

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
            glutSwapBuffers();
        });

        glutMainLoop();
    } catch (std::string const& e) {
        std::cerr << e << std::endl;
    }
}
