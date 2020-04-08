#include "shapes.h"

#include "glm/glm/glm.hpp"

#include <iostream>

Shape::Shape(const std::vector<TexCoord> &coords, const std::vector<unsigned int> &indicies)
    : vb(&coords[0], coords.size() * sizeof(TexCoord)), ib(&indicies[0], indicies.size())
{
    vbl.push<GLfloat>(2);
    vbl.push<GLfloat>(2);

    va.add_buffer(vb, vbl);
}

Shape::~Shape()
{
    unbind();
}

void Shape::unbind() const
{
    va.unbind();
    vb.unbind();
    ib.unbind();
}

namespace shapes {

std::unique_ptr<Shape> triangle(float a, float h)
{
    TexCoord left;
    TexCoord right;
    TexCoord top;

    left.pos = {0.0f, 0.0f};
    left.tex = {0.0f, 0.0f};

    right.pos = {a, 0.0f};
    right.tex = {1.0f, 0.0f};

    top.pos = {a / 2, h};
    top.tex = {1.0f, 1.0f};

    std::vector<TexCoord> vertices = {left, right, top};
    std::vector<unsigned int> indicies = {0, 1, 2};

    return std::make_unique<Shape>(vertices, indicies);
}

std::unique_ptr<Shape> rectangle(float a, float h)
{
    TexCoord bottom_left;
    TexCoord bottom_right;
    TexCoord top_left;
    TexCoord top_right;

    bottom_left.pos = {0.0f, 0.0f};
    bottom_left.tex = {0.0f, 0.0f};

    bottom_right.pos = {a, 0.0f};
    bottom_right.tex = {1.0f, 0.0f};

    top_right.pos = {a, h};
    top_right.tex = {1.0f, 1.0f};

    top_left.pos = {0.0f, h};
    top_left.tex = {0.0f, 1.0f};

    std::vector<TexCoord> vertices = {bottom_left, bottom_right, top_right, top_left};
    std::vector<unsigned int> indicies = {0, 1, 2, 2, 3, 0};

    return std::make_unique<Shape>(vertices, indicies);
}

} // namespace shapes
