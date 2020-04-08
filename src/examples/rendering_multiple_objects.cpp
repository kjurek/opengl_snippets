#include "imgui_window.h"
#include "imgui/imgui.h"

#include "vertex_buffer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "shader.h"
#include "renderer.h"
#include "texture.h"

#include "shapes.h"

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

#include <iostream>

int main()
{
    try {
        imgui::Window window(960, 540, "Multiple objects");

        auto square = shapes::rectangle(100, 100);

        glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f); // aspect ratio, narmalize any space into -1 to 1 space for every axis
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)); // move camera
        glm::vec3 translation_a(200, 200, 0);
        glm::vec3 translation_b(400, 200, 0);

        Shader shader("../res/shaders/texture.vert", "../res/shaders/texture_blend.frag");
        shader.bind();
        shader.set_uniform_4f("u_color", 1.0f, 0.5f, 0.0f, 0.5f);

        Texture texture("../res/textures/github_logo.png");
        texture.bind();
        shader.set_uniform_1i("u_texture", 0);

        Renderer renderer;

        window.run([&]() {
            renderer.clear();

            {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), translation_a);
                glm::mat4 mvp = proj * view * model;
                shader.bind();
                shader.set_uniform_mat4f("u_mvp", mvp);
                renderer.draw(square->va, square->ib, shader);
            }

            {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), translation_b);
                glm::mat4 mvp = proj * view * model;
                shader.bind();
                shader.set_uniform_mat4f("u_mvp", mvp);
                renderer.draw(square->va, square->ib, shader);
            }

            {
                ImGui::SliderFloat3("Translation A", &translation_a.x, 0.0f, 960.0f);
                ImGui::SliderFloat3("Translation B", &translation_b.x, 0.0f, 960.0f);
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                            1000.0f / ImGui::GetIO().Framerate,
                            ImGui::GetIO().Framerate);
            }
        });

    } catch (std::string const& e) {
        std::cerr << e << std::endl;
    }
}
