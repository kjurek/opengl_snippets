#pragma once

#include <string>

class Texture
{
public:
    Texture(std::string const &file_path);
    ~Texture();

    Texture(Texture const&) = delete;
    Texture& operator=(Texture const&) = delete;

    void bind(unsigned int slot = 0) const;
    void unbind() const;

    int get_width() const;
    int get_height() const;
    unsigned int get_id() const;

private:
    unsigned int _renderer_id;
    std::string _file_path;
    unsigned char *_local_buffer;
    int _width, _height, _bpp;
};
