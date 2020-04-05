#include "glfw_window.h"

#include "vertex_buffer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "shader.h"
#include "renderer.h"
#include "texture.h"

#include <iostream>
#include <GL/glew.h>

int main()
{
    try {
        Window window(640, 480, "Square blend");

        float square[] = {
            -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.0f, 1.0f
        };

        unsigned int indicies[] = {0, 1, 2, 3, 2, 0};

        VertexArray va;
        VertexBuffer vb(square, sizeof(square));
        VertexBufferLayout vbl;
        vbl.push<GLfloat>(2);
        vbl.push<GLfloat>(2);
        va.add_buffer(vb, vbl);

        IndexBuffer ib(indicies, 6);
        Shader shader("../res/shaders/texture.vert", "../res/shaders/texture_blend.frag");
        shader.bind();
        shader.set_uniform_4f("u_color", 1.0f, 0.5f, 0.0f, 0.5f);

        Texture texture("../res/textures/github_logo.png");
        texture.bind();
        shader.set_uniform_1i("u_texture", 0);

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
