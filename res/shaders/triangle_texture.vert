#version 430 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 tex_coord;

out vec2 v_tex_coord;

void main(void)
{
    gl_Position = position;
    v_tex_coord = tex_coord;
};
