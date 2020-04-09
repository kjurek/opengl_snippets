#include "materials.h"

ColorMaterial::ColorMaterial()
    : shader("../res/shaders/normal.vert", "../res/shaders/color.frag"),
      color(1.0f)
{}

ColorMaterial::~ColorMaterial()
{
    unbind();
}

void ColorMaterial::bind()
{
    shader.bind();
    shader.set_uniform_mat4f("u_mvp", mvp);
    shader.set_uniform_4f("u_color", color.r, color.g, color.b, color.a);
}

void ColorMaterial::unbind()
{
    shader.unbind();
}

TextureMaterial::TextureMaterial()
    : shader("../res/shaders/texture.vert", "../res/shaders/texture.frag"),
      texture("../res/textures/texture_small.jpg")
{

}

TextureMaterial::~TextureMaterial()
{
    unbind();
}

void TextureMaterial::bind()
{
    shader.bind();
    texture.bind();
    shader.set_uniform_mat4f("u_mvp", mvp);
    shader.set_uniform_1i("u_texture", 0);
}

void TextureMaterial::unbind()
{
    texture.unbind();
    shader.unbind();
}

TextureWithColorMaterial::TextureWithColorMaterial()
    : shader("../res/shaders/texture.vert", "../res/shaders/texture_blend.frag"),
      texture("../res/textures/github_logo.png"), color(1.0f)
{}

TextureWithColorMaterial::~TextureWithColorMaterial()
{
    unbind();
}

void TextureWithColorMaterial::bind()
{
    shader.bind();
    texture.bind();
    shader.set_uniform_mat4f("u_mvp", mvp);
    shader.set_uniform_4f("u_color", color.r, color.g, color.b, color.a);
    shader.set_uniform_1i("u_texture", 0);
}

void TextureWithColorMaterial::unbind()
{
    texture.unbind();
    shader.unbind();
}
