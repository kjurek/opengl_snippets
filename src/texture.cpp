#include "texture.h"
#include "stb/stb_image.h"

#include <GL/glew.h>

Texture::Texture(const std::string &file_path)
    : _file_path(file_path), _local_buffer(nullptr), _width(0), _height(0), _bpp(0)
{
    stbi_set_flip_vertically_on_load(1); // start from bottom left corner for opengl compatibility
    _local_buffer = stbi_load(file_path.c_str(), &_width, &_height, &_bpp, 4);

    glGenTextures(1, &_renderer_id);
    glBindTexture(GL_TEXTURE_2D, _renderer_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA8,
                 _width,
                 _height,
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 _local_buffer);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (_local_buffer) {
        stbi_image_free(_local_buffer);
    }
}

Texture::~Texture()
{
    glDeleteTextures(1, &_renderer_id);
}

void Texture::bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, _renderer_id);
}

void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

int Texture::get_width() const
{
    return _width;
}

int Texture::get_height() const
{
    return _height;
}

unsigned int Texture::get_id() const
{
    return _renderer_id;
}
