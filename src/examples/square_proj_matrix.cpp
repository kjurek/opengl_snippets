#include "glfw_window.h"

#include "vertex_buffer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "shader.h"
#include "renderer.h"
#include "texture.h"

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

#include <iostream>
#include <GL/glew.h>

int main()
{
    try {
        glfw::Window window(640, 480, "Square projection matrix");

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

        glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f); // 4:3 aspect ratio, narmalize any space into -1 to 1 space for every axis
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-1, 0, 0)); // move camera
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.5, 0.5, 0)); // move/scale objects
        glm::mat4 mvp = proj * view * model;

        Shader shader("../res/shaders/texture_proj.vert", "../res/shaders/texture_blend.frag");
        shader.bind();
        shader.set_uniform_4f("u_color", 1.0f, 0.5f, 0.0f, 0.5f);
        shader.set_uniform_mat4f("u_mvp", mvp);

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
