#pragma once

class vertex_buffer
{
public:
    vertex_buffer(void const* data, unsigned int size);
    ~vertex_buffer();

    void bind() const;
    void unbind() const;

private:
    unsigned int _renderer_id;
};

