#include "vertex_array.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &_renderer_id);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &_renderer_id);
}

void VertexArray::add_buffer(VertexBuffer const &vb, VertexBufferLayout const &vbl) const
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

void VertexArray::bind() const
{
    glBindVertexArray(_renderer_id);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}
