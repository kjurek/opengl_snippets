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
        Window window(640, 480, "Triangle with passing uniforms to shader");

        float triangle[] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};

        unsigned int indicies[] = {0, 1, 2};

        VertexArray va;
        VertexBuffer vb(triangle, sizeof(triangle));
        VertexBufferLayout vbl;
        vbl.push<GLfloat>(2);
        va.add_buffer(vb, vbl);

        IndexBuffer ib(indicies, 3);
        Shader shader("../res/shaders/color.vert", "../res/shaders/uniform.frag");

        va.unbind();
        shader.unbind();
        vb.unbind();
        ib.unbind();

        Renderer renderer;

        float r = 0.5f;
        float increment = 0.05f;

        window.run([&]() {
            renderer.clear();
            shader.bind();
            shader.set_uniform_4f("u_color", r, 0, 0, 1);
            renderer.draw(va, ib, shader);

            if (r > 1.0f) {
                increment = -0.05f;
            } else if (r < 0.0f) {
                increment = 0.05f;
            }
            r += increment;
        });

    } catch (std::string const& e) {
        std::cerr << e << std::endl;
    }
}
