#include "texture.h"
#include "stb/stb_image.h"

#include <GL/glew.h>

Texture::Texture(std::string const& file_path)
    : _file_path(file_path)
{
    stbi_set_flip_vertically_on_load(1); // start from bottom left corner for opengl compatibility
    auto buffer = stbi_load(file_path.c_str(), &_width, &_height, &_bpp, 4);

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
                 buffer);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (buffer) {
        stbi_image_free(buffer);
    }
}

Texture::~Texture()
{
    if (_renderer_id)
    {
        glDeleteTextures(1, &_renderer_id);
    }
}

Texture::Texture(Texture &&t) noexcept
{
    *this = std::move(t);
}

Texture& Texture::operator=(Texture&& t) noexcept
{
    if (this != &t)
    {
        if (_renderer_id)
        {
            glDeleteTextures(1, &_renderer_id);
        }
        _renderer_id = t._renderer_id;
        _file_path = std::move(t._file_path);
        _width = t._width;
        _height = t._height;
        _bpp = t._bpp;

        t._renderer_id = 0;
        t._width = 0;
        t._height = 0;
        t._bpp = 0;
    }
    return *this;
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
