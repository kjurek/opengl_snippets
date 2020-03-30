#include "vertex_buffer.h"

#include <GL/glew.h>
#include <GL/glut.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &_renderer_id);
    glBindBuffer(GL_ARRAY_BUFFER, _renderer_id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &_renderer_id);
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, _renderer_id);
}

void VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
