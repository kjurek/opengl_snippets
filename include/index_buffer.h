#pragma once

class IndexBuffer
{
public:
    IndexBuffer(void const* data, unsigned int count);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;
    unsigned int get_count() const;

private:
    unsigned int _renderer_id;
    unsigned int _count;
};

