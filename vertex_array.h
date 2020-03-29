#pragma once

#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

class vertex_array
{
public:
    vertex_array();
    ~vertex_array();

    void add_buffer(vertex_buffer const &vb, vertex_buffer_layout const &vbl) const;
    void bind() const;
    void unbind() const;

private:
    unsigned int _renderer_id;
};
