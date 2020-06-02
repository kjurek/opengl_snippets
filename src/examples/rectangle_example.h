#pragma once

#include "example.h"

#include "vertex_array.h"
#include "vertex_buffer.h"
#include "vertex_array.h"
#include "index_buffer.h"
#include "shader.h"

class RectangleExample : public Example
{
public:
    RectangleExample(unsigned int width, unsigned int height);
    ~RectangleExample();

    void show_options();
    void show_example(Renderer const &renderer);
    std::string get_name() const;

private:
    unsigned int width;
    unsigned int height;

    std::vector<float> verticies;
    std::vector<unsigned int> indicies;
    VertexBuffer vb;
    IndexBuffer ib;
    Shader shader;

    VertexArray va;
    VertexBufferLayout vbl;

    glm::mat4 proj;
    glm::mat4 view;
    glm::vec3 translation;
    glm::vec4 color;
};
