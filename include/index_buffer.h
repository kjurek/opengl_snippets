#pragma once

class IndexBuffer
{
public:
    IndexBuffer(void const* data, unsigned int size);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;

private:
    unsigned int _renderer_id;
    unsigned int _size;
};

