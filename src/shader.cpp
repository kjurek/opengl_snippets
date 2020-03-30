#include "shader.h"
#include "common.h"

#include <string>
#include <fstream>
#include <iostream>

#include <GL/glew.h>


Shader::Shader(std::string const& vertex_shader_path, std::string const& fragment_shader_path)
    : _vertex_shader_path(vertex_shader_path), _fragment_shader_path(fragment_shader_path),
      _renderer_id(0)
{
    std::string vertex_shader = read_file(vertex_shader_path);
    std::string fragment_shader = read_file(fragment_shader_path);
    _renderer_id = create_shader(vertex_shader, fragment_shader);
}

Shader::~Shader()
{
    glDeleteProgram(_renderer_id);
}

void Shader::bind() const
{
    glUseProgram(_renderer_id);
}

void Shader::unbind() const
{
    glUseProgram(0);
}

void Shader::set_uniform_4f(std::string const &name, float f1, float f2, float f3, float f4)
{
    auto location = get_uniform_location(name);
    glUniform4f(location, f1, f2, f3, f4);
}

int Shader::get_uniform_location(const std::string &name) const
{
    auto location = glGetUniformLocation(_renderer_id, name.c_str());
    if (location == -1) {
        std::cout << "Warning: uniform '" << name << "' doesn't exist" << std::endl;
    }
    return location;
}

unsigned int Shader::create_shader(std::string const& vertex_shader, std::string const& fragment_shader)
{
    auto program = glCreateProgram();
    auto vs = compile_shader(GL_VERTEX_SHADER, vertex_shader);
    auto fs = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

unsigned int Shader::compile_shader(unsigned int type, const std::string &source)
{
    auto id = glCreateShader(type);
    auto cstr = source.c_str();
    glShaderSource(id, 1, &cstr, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = static_cast<char *>(alloca(length * sizeof(char)));
        glGetShaderInfoLog(id, length, &length, message);
        std::cerr << "Failed to compile shader" << std::endl;
        std::cerr << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}
