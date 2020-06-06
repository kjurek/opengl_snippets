#version 450 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

uniform mat4 u_mvp;
out vec4 v_color;

void main(void)
{
    v_color = color;
    gl_Position = u_mvp * vec4(position, 1.0);
};
