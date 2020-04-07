#pragma once

#include "example.h"

#include <memory>
#include <string>

#include "glm/glm/glm.hpp"

#include "vertex_array.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "shader.h"
#include "texture.h"
#include "renderer.h"


class TextureExample : public Example
{
public:
    TextureExample();
    virtual ~TextureExample();

    virtual void show_options() override;
    virtual void show_example() override;
    virtual std::string get_name() const override;

private:
    std::unique_ptr<VertexArray> _va;
    std::unique_ptr<VertexBuffer> _vb;
    std::unique_ptr<VertexBufferLayout> _vbl;
    std::unique_ptr<IndexBuffer> _ib;
    std::unique_ptr<Shader> _shader;
    std::unique_ptr<Texture> _texture;
    std::unique_ptr<Renderer> _renderer;
};
