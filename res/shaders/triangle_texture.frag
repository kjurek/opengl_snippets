#version 330 core

in vec2 v_tex_coord;

uniform sampler2D u_texture;

void main(void)
{
    vec4 color = texture2D(u_texture, v_tex_coord);
    gl_FragColor = color;
};
