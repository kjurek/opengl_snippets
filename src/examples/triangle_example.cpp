#include "triangle_example.h"

#include "glm/glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"

TriangleExample::TriangleExample(unsigned int width, unsigned int height)
    :   width(width),
        height(height),
        verticies {0.0f, 0.0f, 50.f, 0.0f, 25.0f, 50.0f},
        indicies {0, 1, 2},
        vb(&verticies[0], verticies.size() * sizeof(float)),
        ib(&indicies[0], indicies.size()),
        shader("../res/shaders/normal.vert", "../res/shaders/color.frag"),
        proj(glm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height), -1.0f, 1.0f)),
        view(1.0f),
        translation(0.0f),
        color(1.0f)
{
    vbl.push<GLfloat>(2);
    va.add_buffer(vb, vbl);
}

TriangleExample::~TriangleExample()
{
    shader.unbind();
    va.unbind();
    vb.unbind();
    ib.unbind();
}

void TriangleExample::show_options() {
    ImGui::SliderFloat("X", &translation.x, 0.0f, width);
    ImGui::SliderFloat("Y", &translation.y, 0.0f, height);
    ImGui::ColorEdit4("Color", &color.r);
}

void TriangleExample::show_example(Renderer const &renderer)
{
    glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
    auto mvp = proj * view * model;

    shader.bind();
    auto loc_mvp = shader.uniform_location("u_mvp");
    glUniformMatrix4fv(loc_mvp, 1, GL_FALSE, &mvp[0][0]);

    auto loc_color = shader.uniform_location("u_color");
    glUniform4f(loc_color, color.r, color.g, color.b, color.a);
    renderer.draw(va, ib);
}

std::string TriangleExample::get_name() const
{
    return "Triangle";
}
