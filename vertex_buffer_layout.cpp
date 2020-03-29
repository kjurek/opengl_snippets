#include "vertex_buffer_layout.h"


vertex_buffer_layout::vertex_buffer_layout()
    :   _stride(0)
{

}

std::vector<vertex_buffer_element> const& vertex_buffer_layout::get_elements() const
{
    return _elements;
}

unsigned int vertex_buffer_layout::get_stride() const
{
    return _stride;
}
