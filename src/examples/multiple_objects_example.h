#pragma once

#include "example.h"
#include "materials.h"
#include "shapes.h"

#include <array>


class MultipleObjectsExample : public Example
{
public:
    MultipleObjectsExample(unsigned int width, unsigned int height);
    virtual ~MultipleObjectsExample();

    virtual void show_options() override;
    virtual void show_example(Renderer const &renderer) override;
    virtual std::string get_name() const override;

private:
    float _width, _height;

    std::vector<glm::vec3> _translations;
    std::vector<glm::vec4> _colors;

    glm::mat4 _proj;
    glm::mat4 _view;

    TextureWithColorMaterial _material;
    std::unique_ptr<Shape> _shape;
};
