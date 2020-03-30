#include "vertex_buffer_layout.h"


VertexBufferLayout::VertexBufferLayout()
    :   _stride(0)
{

}

std::vector<VertexBbufferElement> const& VertexBufferLayout::get_elements() const
{
    return _elements;
}

unsigned int VertexBufferLayout::get_stride() const
{
    return _stride;
}
