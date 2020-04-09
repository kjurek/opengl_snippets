#include "multiple_objects_example.h"

#include "imgui/imgui.h"
#include "glm/glm/gtc/matrix_transform.hpp"

MultipleObjectsExample::MultipleObjectsExample(unsigned int width, unsigned int height)
    : _width(width), _height(height),
      _proj(glm::ortho(0.0f, _width, 0.0f, _height, -1.0f, 1.0f)), _view(1.0f)
{
    _shape = shapes::rectangle(100, 100);
}

MultipleObjectsExample::~MultipleObjectsExample() {
}

void MultipleObjectsExample::show_options()
{
    if (ImGui::Button("Add object")) {
        _translations.emplace_back(0);
        _colors.emplace_back(1);
    }

    for (unsigned i = 0; i < _translations.size(); ++i) {
        std::string label_x = "Object " + std::to_string(i) + " X";
        std::string label_y = "Object " + std::to_string(i) + " Y";
        std::string label_color = "Object " + std::to_string(i) + " color";

        ImGui::SliderFloat(label_x.c_str(), &_translations[i].x, 0.0f, _width);
        ImGui::SliderFloat(label_y.c_str(), &_translations[i].y, 0.0f, _width);
        ImGui::ColorEdit4(label_color.c_str(), &_colors[i].r);

        ImGui::Spacing();
    }
}

void MultipleObjectsExample::show_example(Renderer const &renderer)
{
    for (unsigned i = 0; i < _translations.size(); ++i) {
        glm::mat4 model = glm::translate(glm::mat4(1.0f), _translations[i]);
        _material.mvp = _proj * _view * model;
        _material.color = _colors[i];
        _material.bind();
        renderer.draw(_shape->va, _shape->ib, _material.shader);
    }
}

std::string MultipleObjectsExample::get_name() const
{
    return "Multiple objects";
}
