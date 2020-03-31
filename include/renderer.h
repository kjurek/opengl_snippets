#pragma once

#include "vertex_array.h"
#include "index_buffer.h"
#include "shader.h"

class Renderer
{
public:
    void clear() const;
    void draw(VertexArray const& va, IndexBuffer const& ib, Shader const& shader) const;
};
