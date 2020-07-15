#include "multiple_objects_example.h"

#include "glm/glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"

Object::Object()
    : verticies{0.0f, 0.0f, 100.f, 0.0f, 100.0f, 50.0f, 0.0f, 50.0f},
      indicies{0, 1, 2, 2, 3, 0},
      vb(&verticies[0], verticies.size() * sizeof(float)),
      ib(&indicies[0], indicies.size()),
      shader("../res/shaders/normal.vert", "../res/shaders/color.frag"),
      pos(0.0f),
      color(1.0f)
{
    vbl.push<GLfloat>(2);
    va.add_buffer(vb, vbl);
}

Object::~Object()
{
    unbind();
}

void Object::bind(glm::mat4 const& proj, glm::mat4 const& view)
{
    glm::mat4 model = glm::translate(glm::mat4(1.0f), pos);
    auto mvp = proj * view * model;

    shader.bind();
    auto loc_mvp = shader.uniform_location("u_mvp");
    glUniformMatrix4fv(loc_mvp, 1, GL_FALSE, &mvp[0][0]);

    auto loc_color = shader.uniform_location("u_color");
    glUniform4f(loc_color, color.r, color.g, color.b, color.a);

    va.bind();
    vb.bind();
    ib.bind();
}

void Object::unbind()
{
    shader.unbind();
    va.unbind();
    vb.unbind();
    ib.unbind();
}

MultipleObjectsExample::MultipleObjectsExample(unsigned int width, unsigned int height)
    : width(width),
      height(height),
      proj(glm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height), -1.0f, 1.0f)),
      view(1.0f)
{

}

void MultipleObjectsExample::show_options()
{
    if (ImGui::Button("Add Object")) {
        objects.push_back(std::make_unique<Object>());
    }

    for (size_t i = 0; i < objects.size(); ++i) {
        std::string label = "Object " + std::to_string(i);
        std::string label_x = "X " + label;
        std::string label_y = "Y " + label;
        std::string label_color = "Color " + label;
        ImGui::Text("%s", label.c_str());
        ImGui::SliderFloat(label_x.c_str(), &objects[i]->get_pos().x, 0.0f, width);
        ImGui::SliderFloat(label_y.c_str(), &objects[i]->get_pos().y, 0.0f, height);
        ImGui::ColorEdit4(label_color.c_str(), &objects[i]->get_color().r);
    }
}

void MultipleObjectsExample::show_example(Renderer const &renderer)
{
    for (auto const &object : objects) {
        object->bind(proj, view);
        renderer.draw(object->get_va(), object->get_ib());
    }
}

std::string MultipleObjectsExample::get_name() const
{
    return "Multiple objects";
}
