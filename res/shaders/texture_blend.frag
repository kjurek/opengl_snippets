#version 330 core

out vec4 color;
in vec2 v_tex_coord;

uniform sampler2D u_texture;
uniform vec4 u_color;

void main(void)
{
//    color = texture(u_texture, v_tex_coord) + u_color;
    color = texture(u_texture, v_tex_coord) * u_color;
};
