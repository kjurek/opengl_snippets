#pragma once

#include "shader.h"
#include "texture.h"

#include "glm/glm/glm.hpp"

struct ColorMaterial
{
    ColorMaterial();
    ~ColorMaterial();

    void bind();
    void unbind();

    Shader shader;
    glm::vec4 color;
    glm::mat4 mvp;
};

struct TextureMaterial
{
public:
    TextureMaterial();
    ~TextureMaterial();

    void bind();
    void unbind();

    Shader shader;
    Texture texture;
    glm::mat4 mvp;
};
