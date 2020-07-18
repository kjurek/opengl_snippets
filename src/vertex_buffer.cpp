#include "vertex_buffer.h"

#include <utility>
#include <GL/glew.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &_renderer_id);
    glBindBuffer(GL_ARRAY_BUFFER, _renderer_id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    if (_renderer_id)
    {
        glDeleteBuffers(1, &_renderer_id);
    }
}

VertexBuffer::VertexBuffer(VertexBuffer&& vb) noexcept
{
    *this = std::move(vb);
}

VertexBuffer& VertexBuffer::operator=(VertexBuffer &&vb) noexcept
{
    if (this != &vb)
    {
        if (_renderer_id)
        {
            glDeleteBuffers(1, &_renderer_id);
        }

        _renderer_id = vb._renderer_id;
        vb._renderer_id = 0;
    }
    return *this;
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, _renderer_id);
}

void VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
