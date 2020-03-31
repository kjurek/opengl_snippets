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

        float triangle[] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};

        unsigned int indicies[] = {0, 1, 2};

        static VertexArray va;
        VertexBuffer vb(triangle, sizeof(triangle));
        VertexBufferLayout vbl;
        vbl.push<GLfloat>(2);
        va.add_buffer(vb, vbl);

        static IndexBuffer ib(indicies, 3);
        static Shader shader("../res/shaders/triangle.vert", "../res/shaders/triangle_uniform.frag");

        va.unbind();
        shader.unbind();
        vb.unbind();
        ib.unbind();

        static Renderer renderer;

        static float r = 0.5f;
        static float increment = 0.05f;

        auto render = []() {
            renderer.clear();
            shader.bind();
            shader.set_uniform_4f("u_color", r, 0, 0, 1);
            renderer.draw(va, ib, shader);
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
    } catch (std::string const& e) {
        std::cerr << e << std::endl;
    }
}