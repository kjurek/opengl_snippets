#pragma once

#include <memory>

#include "glm/glm/glm.hpp"

#include "vertex_array.h"
#include "vertex_buffer.h"
#include "vertex_array.h"
#include "index_buffer.h"

struct TexCoord
{
    glm::vec2 pos;
    glm::vec2 tex;
};

struct Shape
{
    Shape(std::vector<TexCoord> const &coords, std::vector<unsigned int> const &indicies);
    ~Shape();

    void unbind() const;

    VertexArray va;
    VertexBuffer vb;
    VertexBufferLayout vbl;
    IndexBuffer ib;
};

namespace shapes {

std::unique_ptr<Shape> triangle(float a, float h);
std::unique_ptr<Shape> rectangle(float a, float h);

}
