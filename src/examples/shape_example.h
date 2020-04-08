#pragma once

#include "example.h"

#include <memory>

#include "shapes.h"
#include "materials.h"

#include "glm/glm/glm.hpp"

class ShapeExample : public Example
{
public:
    ShapeExample(unsigned int width, unsigned int height);
    virtual ~ShapeExample();

    virtual void show_options() override;
    virtual void show_example(Renderer const& renderer) override;
    virtual std::string get_name() const override;

private:
    std::vector<std::unique_ptr<Shape>> _shapes;

    ColorMaterial _color;
    TextureMaterial _texture;

    float _width;
    float _height;

    glm::mat4 _proj;
    glm::mat4 _view;
    glm::vec3 _translation;

    int _current_shape;
    int _last_shape;

    int _current_material;
    int _last_material;
};
