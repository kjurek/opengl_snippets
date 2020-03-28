#include "index_buffer.h"

#include <GL/glew.h>
#include <GL/glut.h>

index_buffer::index_buffer(void const* data, unsigned int size)
    :   _size(size)
{
    glGenBuffers(1, &_renderer_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

index_buffer::~index_buffer()
{
    glDeleteBuffers(1, &_renderer_id);
}

void index_buffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderer_id);
}

void index_buffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
