#include "index_buffer.h"

#include <GL/glew.h>
#include <GL/glut.h>

IndexBuffer::IndexBuffer(void const* data, unsigned int count)
    :   _count(count)
{
    glGenBuffers(1, &_renderer_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &_renderer_id);
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
