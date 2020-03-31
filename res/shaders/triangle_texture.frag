#version 430 core

out vec4 color;
in vec2 v_tex_coord;

uniform sampler2D u_texture;

void main(void)
{
    color = texture(u_texture, v_tex_coord);
};
