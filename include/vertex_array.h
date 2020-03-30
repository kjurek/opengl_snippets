#pragma once

#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    void add_buffer(VertexBuffer const &vb, VertexBufferLayout const &vbl) const;
    void bind() const;
    void unbind() const;

private:
    unsigned int _renderer_id;
};
