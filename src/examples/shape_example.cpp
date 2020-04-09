#include "shape_example.h"

#include "glm/glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"


ShapeExample::ShapeExample(unsigned int width, unsigned int height)
    : _width(width), _height(height),
      _proj(glm::ortho(0.0f, _width, 0.0f, _height, -1.0f, 1.0f)),
      _view(1.0f),
      _translation(0.0f),
      _current_shape(0), _last_shape(-1),
      _current_material(0), _last_material(-1)
{
    _shapes.push_back(shapes::triangle(50, 50));
    _shapes.push_back(shapes::rectangle(50, 50));
}

ShapeExample::~ShapeExample()
{
}

void ShapeExample::show_options()
{
    ImGui::Text("Shape");
    ImGui::RadioButton("Triangle", &_current_shape, 0);
    ImGui::RadioButton("Square", &_current_shape, 1);

    ImGui::Text("Material");
    ImGui::RadioButton("Color", &_current_material, 0);
    ImGui::RadioButton("Texture", &_current_material, 1);

    ImGui::SliderFloat("Translation X", &_translation.x, 0.0f, _width - 50.0f);
    ImGui::SliderFloat("Translation Y", &_translation.y, 0.0f, _height - 50.0f);

    if (_current_material == 0) {
        ImGui::ColorEdit4("Shape color", &_color.color.r);
    }
}

void ShapeExample::show_example(Renderer const &renderer)
{
    if (_current_shape != _last_shape) {
        if (_last_shape != -1) {
            _shapes[_last_shape]->unbind();
        }
        _last_shape = _current_shape;
    }

    if (_current_material != _last_material) {
        if (_last_material != -1) {
            if (_current_material == 0) {
                _texture.unbind();
            } else {
                _color.unbind();
            }
        }
        _last_material = _current_material;
    }

    glm::mat4 model = glm::translate(glm::mat4(1.0f), _translation);

    if (_current_material == 0) {
        _color.mvp = _proj * _view * model;
        _color.bind();
    } else {
        _texture.mvp = _proj * _view * model;
        _texture.bind();
    }

    renderer.draw(_shapes[_current_shape]->va, _shapes[_current_shape]->ib);
}

std::string ShapeExample::get_name() const
{
    return "Shape Colors";
}
