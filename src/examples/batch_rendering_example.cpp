#include "batch_rendering_example.h"

#include "glm/glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"

BatchRenderingExample::BatchRenderingExample(unsigned int width, unsigned int height)
    : width(width),
      height(height),
      verticies {
         // Object 1
         0.0f, 0.0f, 0.0f, //pos
         1.0f, 0.0f, 0.0f, 1.0f, //color

         100.f, 0.0f, 0.0f, // pos
         1.0f, 0.0f, 0.0f, 1.0f, // color

         100.0f, 50.0f, 0.0f, // pos
         1.0f, 0.0f, 0.0f, 1.0f, // color

         0.0f, 50.0f, 1.0f, // pos
         1.0f, 0.0f, 0.0f, 1.0f, // color

         // Object 2
         200.0f, 0.0f, 0.0f, //pos
         0.0f, 0.0f, 1.0f, 1.0f, //color

         300.f, 0.0f, 0.0f, // pos
         0.0f, 0.0f, 1.0f, 1.0f, // color

         300.0f, 50.0f, 0.0f, // pos
         0.0f, 0.0f, 1.0f, 1.0f, // color

         200.0f, 50.0f, 1.0f, // pos
         0.0f, 0.0f, 1.0f, 1.0f, // color
      },
      indicies {0, 1, 2, 2, 3, 0,
                4, 5, 6, 6, 7, 4},
      vb(&verticies[0], verticies.size() * sizeof(float)),
      ib(&indicies[0], indicies.size()),
      shader("../res/shaders/batch.vert", "../res/shaders/batch.frag"),
      proj(glm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height), -1.0f, 1.0f)),
      view(1.0f),
      translation(0.0f),
      color(1.0f)
{
    vbl.push<GLfloat>(3);
    vbl.push<GLfloat>(4);
    va.add_buffer(vb, vbl);
}

BatchRenderingExample::~BatchRenderingExample()
{
    shader.unbind();
    va.unbind();
    vb.unbind();
    ib.unbind();
}

void BatchRenderingExample::show_options() {
    ImGui::SliderFloat("X", &translation.x, 0.0f, width);
    ImGui::SliderFloat("Y", &translation.y, 0.0f, height);
}

void BatchRenderingExample::show_example(Renderer const &renderer)
{
    glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
    auto mvp = proj * view * model;
    shader.bind();
    auto loc = shader.uniform_location("u_mvp");
    glUniformMatrix4fv(loc, 1, GL_FALSE, &mvp[0][0]);
    renderer.draw(va, ib);
}

std::string BatchRenderingExample::get_name() const
{
    return "Batch rendering";
}
