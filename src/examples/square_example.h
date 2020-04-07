#pragma once

#include "example.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
#include "index_buffer.h"
#include "shader.h"
#include "renderer.h"

#include <memory>
#include <glm/glm/glm.hpp>

class SquareExample : public Example
{
public:
    SquareExample();
    virtual ~SquareExample();

    virtual void show_options() override;
    virtual void show_example() override;
    virtual std::string get_name() const;

private:
    glm::vec4 _colors;
    std::unique_ptr<VertexArray> _va;
    std::unique_ptr<VertexBuffer> _vb;
    std::unique_ptr<VertexBufferLayout> _vbl;
    std::unique_ptr<IndexBuffer> _ib;
    std::unique_ptr<Shader> _shader;
    std::unique_ptr<Renderer> _renderer;
};

