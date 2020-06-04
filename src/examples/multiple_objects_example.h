#pragma once

#include "example.h"

#include <vector>
#include <memory>

#include "vertex_array.h"
#include "vertex_buffer.h"
#include "vertex_array.h"
#include "index_buffer.h"
#include "shader.h"

class Object
{
public:
    Object();
    ~Object();

    void bind(glm::mat4 const &proj, glm::mat4 const &view);
    void unbind();

    glm::vec3 &get_pos() { return pos; }
    glm::vec4 &get_color() { return color; }
    IndexBuffer const &get_ib() const { return ib; }
    VertexArray const &get_va() const { return va; }

private:
    std::vector<float> verticies;
    std::vector<unsigned int> indicies;

    VertexBuffer vb;
    IndexBuffer ib;
    Shader shader;
    glm::vec3 pos;
    glm::vec4 color;

    VertexBufferLayout vbl;
    VertexArray va;
};

class MultipleObjectsExample : public Example
{
public:
    MultipleObjectsExample(unsigned int width, unsigned int height);

    void show_options();
    void show_example(Renderer const &renderer);
    std::string get_name() const;

private:
    unsigned int width;
    unsigned int height;

    std::vector<std::unique_ptr<Object>> objects;

    glm::mat4 proj;
    glm::mat4 view;
};
