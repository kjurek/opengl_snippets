#include "triangle_example.h"

#include "imgui/imgui.h"

TriangleExample::TriangleExample()
{
    float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};
    unsigned int indicies[] = {0, 1, 2};
    _colors = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

    _va = std::make_unique<VertexArray>();
    _vb = std::make_unique<VertexBuffer>(vertices, sizeof(vertices));
    _vbl = std::make_unique<VertexBufferLayout>();
    _vbl->push<GLfloat>(2);
    _va->add_buffer(*_vb, *_vbl);

    _ib = std::make_unique<IndexBuffer>(indicies, 3);
    _shader = std::make_unique<Shader>("../res/shaders/color.vert",
                                       "../res/shaders/uniform.frag");
    _renderer = std::make_unique<Renderer>();
}

TriangleExample::~TriangleExample() {
    _shader->unbind();
    _va->unbind();
    _vb->unbind();
    _ib->unbind();
}

void TriangleExample::show_options()
{
    ImGui::ColorEdit4("Colors", &_colors.r);
}

void TriangleExample::show_example() {
    _shader->bind();
    _shader->set_uniform_4f("u_color", _colors.r, _colors.g, _colors.b, _colors.a);
    _renderer->draw(*_va, *_ib, *_shader);
}

std::string TriangleExample::get_name() const
{
    return "Triangle";
}
