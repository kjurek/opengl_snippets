#pragma once

class VertexBuffer
{
public:
    VertexBuffer(void const* data, unsigned int size);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;

private:
    unsigned int _renderer_id;
};

