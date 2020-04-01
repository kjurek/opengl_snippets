#include "common.h"

#include "vertex_buffer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "shader.h"
#include "renderer.h"
#include "texture.h"

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    try {
        create_window(argc, argv);

        float square[] = {
            -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.0f, 1.0f
        };

        unsigned int indicies[] = {0, 1, 2, 3, 2, 0};

        static VertexArray va;
        VertexBuffer vb(square, sizeof(square));
        VertexBufferLayout vbl;
        vbl.push<GLfloat>(2);
        vbl.push<GLfloat>(2);
        va.add_buffer(vb, vbl);

        static IndexBuffer ib(indicies, 6);
        static Shader shader("../res/shaders/texture.vert", "../res/shaders/texture_blend.frag");
        shader.bind();
        shader.set_uniform_4f("u_color", 1.0f, 0.5f, 0.0f, 0.5f);

        Texture texture("../res/textures/github_logo.png");
        texture.bind();
        shader.set_uniform_1i("u_texture", 0);

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
