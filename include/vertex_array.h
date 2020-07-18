#pragma once

#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    VertexArray(VertexArray&& va) noexcept;
    VertexArray& operator=(VertexArray&& va) noexcept;

    VertexArray(VertexArray const&) = delete;
    VertexArray& operator=(VertexArray const&) = delete;

    void add_buffer(VertexBuffer const &vb, VertexBufferLayout const &vbl) const;
    void bind() const;
    void unbind() const;

private:
    unsigned int _renderer_id;
};
