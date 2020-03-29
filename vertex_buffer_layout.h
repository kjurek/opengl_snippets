#pragma once

#include <vector>
#include <cassert>

#include <GL/glew.h>

struct vertex_buffer_element
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    unsigned int get_size() const
    {
        switch (type) {
        case GL_FLOAT:
            return sizeof(GLfloat);
        case GL_UNSIGNED_INT:
            return sizeof(GLuint);
        case GL_UNSIGNED_BYTE:
            return sizeof(GLubyte);
        }
        assert(false);
        return 0;
    }
};

namespace  {

template<typename T>
vertex_buffer_element create_element(unsigned int count)
{
    assert(false);
}

template<>
vertex_buffer_element create_element<float>(unsigned int count)
{
    return {GL_FLOAT, count, GL_FALSE};
}

template<>
vertex_buffer_element create_element<unsigned int>(unsigned int count)
{
    return {GL_UNSIGNED_INT, count, GL_FALSE};
}

template<>
vertex_buffer_element create_element<unsigned char>(unsigned int count)
{
    return {GL_UNSIGNED_BYTE, count, GL_TRUE};
}

}


class vertex_buffer_layout
{
public:
    vertex_buffer_layout();

    template<typename T>
    void push(unsigned int count)
    {
        auto element = create_element<T>(count);
        _elements.push_back(element);
        _stride += count * sizeof(T);
    }

    std::vector<vertex_buffer_element> const& get_elements() const;
    unsigned int get_stride() const;

private:
    std::vector<vertex_buffer_element> _elements;
    unsigned int _stride;
};
