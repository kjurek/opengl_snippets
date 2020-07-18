#include "index_buffer.h"

#include <GL/glew.h>
#include <utility>

IndexBuffer::IndexBuffer(void const* data, unsigned int count)
    :   _count(count)
{
    glGenBuffers(1, &_renderer_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    if (_renderer_id)
    {
        glDeleteBuffers(1, &_renderer_id);
    }
}

IndexBuffer::IndexBuffer(IndexBuffer&& ib) noexcept
{
    *this = std::move(ib);
}

IndexBuffer& IndexBuffer::operator=(IndexBuffer&& ib) noexcept
{
    if (this != &ib)
    {
        if (_renderer_id)
        {
            glDeleteBuffers(1, &_renderer_id);
        }
        _renderer_id = ib._renderer_id;
        _count = ib._count;

        ib._renderer_id = 0;
        ib._count = 0;
    }
    return *this;
}

void IndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderer_id);
}

void IndexBuffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::get_count() const
{
    return _count;
}
