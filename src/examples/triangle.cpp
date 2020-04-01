#include "common.h"

#include "vertex_buffer.h"
#include "index_buffer.h"
#include "vertex_buffer_layout.h"
#include "vertex_array.h"
#include "shader.h"
#include "renderer.h"

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

        static VertexArray va;
        VertexBuffer vb(triangle, sizeof(triangle));
        VertexBufferLayout vbl;
        vbl.push<GLfloat>(2);
        va.add_buffer(vb, vbl);

        static IndexBuffer ib(indicies, 3);
        static Shader shader("../res/shaders/color.vert", "../res/shaders/color.frag");

        va.unbind();
        shader.unbind();
        vb.unbind();
        ib.unbind();

        static Renderer renderer;

        glutDisplayFunc([]() {
            renderer.clear();
            renderer.draw(va, ib, shader);
            glutSwapBuffers();
        });

        glutMainLoop();
    } catch (std::string const& e) {
        std::cerr << e << std::endl;
    }
}
