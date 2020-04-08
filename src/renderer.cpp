#include "renderer.h"


void Renderer::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(VertexArray const &va, IndexBuffer const& ib, Shader const& shader) const
{
    shader.bind();
    draw(va, ib);
}

void Renderer::draw(VertexArray const& va, IndexBuffer const& ib) const
{
    va.bind();
    ib.bind();
    glDrawElements(GL_TRIANGLES, ib.get_count(), GL_UNSIGNED_INT, nullptr);
}
