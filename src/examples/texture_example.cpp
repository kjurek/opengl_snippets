#include "texture_example.h"

#include "glm/glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"

TextureExample::TextureExample(unsigned int width, unsigned int height)
    : width(width),
      height(height),
      verticies {0.0f, 0.0f, 0.0f, 0.0f,
                 100.f, 0.0f, 1.0f, 0.0f,
                 100.0f, 50.0f, 1.0f, 1.0f,
                 0.0f, 50.0f, 0.0f, 1.0f},
      indicies {0, 1, 2, 2, 3, 0},
      vb(&verticies[0], verticies.size() * sizeof(float)),
      ib(&indicies[0], indicies.size()),
      shader("../res/shaders/texture.vert", "../res/shaders/texture_blend.frag"),
      texture("../res/textures/github_logo.png"),
      proj(glm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height), -1.0f, 1.0f)),
      view(1.0f),
      translation(0.0f),
      color(1.0f)
{
    vbl.push<GLfloat>(2);
    vbl.push<GLfloat>(2);
    va.add_buffer(vb, vbl);
}

TextureExample::~TextureExample()
{
    shader.unbind();
    texture.unbind();
    va.unbind();
    vb.unbind();
    ib.unbind();
}

void TextureExample::show_options() {
    ImGui::SliderFloat("X", &translation.x, 0.0f, width);
    ImGui::SliderFloat("Y", &translation.y, 0.0f, height);
    ImGui::ColorEdit4("Color", &color.r);
}

void TextureExample::show_example(Renderer const &renderer)
{
    glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
    auto mvp = proj * view * model;

    shader.bind();
    texture.bind();
    auto loc_mvp = shader.uniform_location("u_mvp");
    glUniformMatrix4fv(loc_mvp, 1, GL_FALSE, &mvp[0][0]);

    auto loc_color = shader.uniform_location("u_color");
    glUniform4f(loc_color, color.r, color.g, color.b, color.a);

    auto loc_texture = shader.uniform_location("u_texture");
    glUniform1i(loc_texture, 0);
    renderer.draw(va, ib);
}

std::string TextureExample::get_name() const
{
    return "Texture";
}
