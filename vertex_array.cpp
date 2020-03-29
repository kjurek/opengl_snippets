#include "vertex_array.h"

vertex_array::vertex_array()
{
    glGenVertexArrays(1, &_renderer_id);
}

vertex_array::~vertex_array()
{
    glDeleteVertexArrays(1, &_renderer_id);
}

void vertex_array::add_buffer(vertex_buffer const &vb, vertex_buffer_layout const &vbl) const
{
    bind();
    vb.bind();
    auto const &elements = vbl.get_elements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); ++i) {
        auto const &element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i,
                              element.count,
                              element.type,
                              element.normalized,
                              vbl.get_stride(),
                              (void const *) offset);
        offset += element.count * element.get_size();
    }
}

void vertex_array::bind() const
{
    glBindVertexArray(_renderer_id);
}

void vertex_array::unbind() const
{
    glBindVertexArray(0);
}
