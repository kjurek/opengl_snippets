#include "texture_example.h"

#include "imgui/imgui.h"

TextureExample::TextureExample()
{
    float vertices[] = {-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.5f, -0.5f, 1.0f, 1.0f};
    unsigned int indicies[] = {0, 1, 2};

    _va = std::make_unique<VertexArray>();
    _vb = std::make_unique<VertexBuffer>(vertices, sizeof(vertices));
    _vbl = std::make_unique<VertexBufferLayout>();
    _vbl->push<GLfloat>(2);
    _vbl->push<GLfloat>(2);

    _va->add_buffer(*_vb, *_vbl);

    _ib = std::make_unique<IndexBuffer>(indicies, 3);
    _shader = std::make_unique<Shader>("../res/shaders/texture.vert", "../res/shaders/texture.frag");
    _texture = std::make_unique<Texture>("../res/textures/texture.jpg");
    _renderer = std::make_unique<Renderer>();
}

TextureExample::~TextureExample()
{
    _texture->unbind();
    _shader->unbind();
    _va->unbind();
    _vb->unbind();
    _ib->unbind();
}

void TextureExample::show_options()
{
}

void TextureExample::show_example() {
    _shader->bind();
    _texture->bind();
    _shader->set_uniform_1i("u_texture", 0);
    _renderer->draw(*_va, *_ib, *_shader);
}

std::string TextureExample::get_name() const
{
    return "Texture";
}
