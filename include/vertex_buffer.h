#pragma once

class VertexBuffer
{
public:
    VertexBuffer(void const* data, unsigned int size);
    ~VertexBuffer();

    VertexBuffer(VertexBuffer&& vb) noexcept;
    VertexBuffer& operator=(VertexBuffer&& vb) noexcept;

    VertexBuffer(VertexBuffer const&) = delete;
    VertexBuffer& operator=(VertexBuffer const&) = delete;

    void bind() const;
    void unbind() const;

private:
    unsigned int _renderer_id;
};

