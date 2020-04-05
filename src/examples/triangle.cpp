#include "glfw_window.h"

#include "vertex_buffer.h"
#include "index_buffer.h"
#include "vertex_buffer_layout.h"
#include "vertex_array.h"
#include "shader.h"
#include "renderer.h"

#include <iostream>
#include <GL/glew.h>

int main()
{
    try {
        glfw::Window window(640, 480, "Triangle");

        float triangle[] = {
            -0.5f, -0.5f,
            0.0f, 0.5f,
            0.5f, -0.5f
        };
        unsigned int indicies[] = {0, 1, 2};

        VertexArray va;
        VertexBuffer vb(triangle, sizeof(triangle));
        VertexBufferLayout vbl;
        vbl.push<GLfloat>(2);
        va.add_buffer(vb, vbl);

        IndexBuffer ib(indicies, 3);
        Shader shader("../res/shaders/color.vert", "../res/shaders/color.frag");

        va.unbind();
        shader.unbind();
        vb.unbind();
        ib.unbind();

        Renderer renderer;

        window.run([&]() {
            renderer.clear();
            renderer.draw(va, ib, shader);
        });

    } catch (std::string const& e) {
        std::cerr << e << std::endl;
    }
}
