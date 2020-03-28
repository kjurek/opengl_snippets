#pragma once

class index_buffer
{
public:
    index_buffer(void const* data, unsigned int size);
    ~index_buffer();

    void bind() const;
    void unbind() const;

private:
    unsigned int _renderer_id;
    unsigned int _size;
};

